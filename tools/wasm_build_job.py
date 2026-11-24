#!/usr/bin/env python3
"""Wasm port builds as jobs of the shared queue (tools/jobq.py): the headless hulk-aot or the macOS app hulk-app (and
its Hulk.app bundle) built on a remote Mac with the `wasm` capability instead of this laptop (docs/compute.md "Wasm
builds"; docs/wasm-port.md "Build the app on the queue").

  build/venv/bin/python tools/wasm_build_job.py submit --name ME --target app|aot [--bundle]
        [--inputs auto|make|JOB|FILE.tgz|DIR] [--workspace DIR | --dirty | --files PATH ...] [--env HULK_WASM_X=V ...]
        [--host mac2|studio] [--lineage L] [--slots 8] [--limit S] [--prio N] [--keep-wasm]      # prints the job id
  build/venv/bin/python tools/wasm_build_job.py test --name ME --exe JOB|PATH [--control JOB|PATH] --test KIND:... \
        [--test-env HULK_X=V ...] [--host H]      # tests only (play3, rolltest, input, metal, metal-input, metal-ab)
  build/venv/bin/python tools/wasm_build_job.py wait ID              # then: the summary (steps, wall times, host)
  build/venv/bin/python tools/wasm_build_job.py fetch ID [--dest build/ME/wasm-app]   # moves the artefacts there
  build/venv/bin/python tools/wasm_build_job.py setup [--host H ...]   # put the toolchain and inputs on the hosts
  build/venv/bin/python tools/wasm_build_job.py hosts                  # what each wasm host has (toolchain, inputs, lineages)

Metal tests (wqgpu1; docs/compute.md "Metal tests on the queue"): the app on mac2's / studio's GPU (`--needs gpu`, one
such job per host at a time), hidden window, screenshots, gfxstats and A/B cost lines returned for `fetch`:
  ... submit --name ME --target app --test metal:4100:1500,4000          # play3 replay, shots of game frames 1500, 4000
  ... test --name ME --exe NEW --control OLD --test metal:6000:2000,5900  # before/after shots (+ shots-diff/) on one host
  ... test --name ME --exe JOB --test metal-input:1500:1200 [--test-env HULK_INPUT=...]   # scripted free run (30 fps)
  ... test --name ME --exe JOB --test metal-ab:6000 --test-env HULK_LIGHT_AB=30 --test-env HULK_SETTINGS=remastered=1
Timing on a shared host is approximate (the GPU is exclusive, the CPU is not): compare within one job on one host.

Sources: the job's base is `git archive HEAD` (jobq's base tree). By default nothing else travels: the build is HEAD's.
`--workspace DIR` ships the files of that private workspace that differ from HEAD (and deletes the ones it lacks),
`--dirty` every modified or untracked file of this checkout under tools include tests config src (other lanes'
edits too), `--files` the named paths. Host code (src/platform/wasm, src/platform/sdl) and the build tools come from
the job's sources; the game's TUs come from the wasm inputs.

Wasm inputs (`--inputs`, default auto): the snapshot and binding map tools/wasm_inputs.py makes at one commit.
  auto     a fetched wasm_inputs tarball (build/jobs/out/*/wasm-in.tgz) or unpacked directory (build/wasm-inputs/<c12>)
           made at HEAD; none: as `make`
  make     made inside the same job from the job's sources (`wasm_inputs.py job`: materialize + binding map, ~11 min on
           8 slots): the way to build tree edits (src/game, src/engine, src/platform/xbox, include) shipped in the overlay
  JOB / FILE.tgz / DIR   that wasm_inputs job's tarball, a tarball, or a fetched directory (packed here)
An overlay that touches the tree with inputs other than `make` is refused (the build would silently use the inputs'
tree): pass `--inputs make`, or `--tree-ok` when the inputs already hold those edits.

Hosts: the job needs `wasm` (hosts.json caps: mac2 and studio; a host needs the Command Line Tools and the LLVM
the clang jobs use). The toolchain is this laptop's own, copied once per host into ~/hulk-jobs/wasm/tc/
(`setup`; submit's `prep` checks it): Emscripten (with its LLVM, Binaryen and its prebuilt system libraries, used
frozen, so the module links the same C library bytes as a local build) and wabt (wasm2c). The local-only inputs
(build/functions.csv; for the app SDL3 with video, bgfx/bimg/bx, their headers, the Metal shader binaries, mingw-w64's
headers, FFmpeg's headers) go to ~/hulk-jobs/wasm/inputs-STAMP (STAMP: their content hash; the newest 4 kept). No game
data is shipped: the link reads the host's own XBE (isos/extracted/default.xbe, as every job).

Per-host cache: the build directory is ~/hulk-jobs/wasm/ws/LINEAGE/out on the host (default lineage NAME-TARGET; one
job at a time, the 8 most recently used kept). wasm_port's front-end IR is keyed by content and wasm_app's
app-inputs.json stamp decides whether every TU compiles again, so a second build of the same inputs only relinks.
Outputs: build/jobs/out/ID/wb-out/ (summary.json, hulk-aot or hulk-app, Hulk.app with --bundle, link.json,
compile-summary.json, hulk.wasm with --keep-wasm); `fetch` moves them out of there. Everything is game-derived: it stays
under build/ and is never committed or published.
"""
import argparse
import hashlib
import json
import os
import re
import shlex
import shutil
import subprocess
import sys
import tarfile
import tempfile
import threading
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import jobq  # noqa: E402

WB = "~/hulk-jobs/wasm"
TARGETS = ("app", "aot")
# overlay paths a build from shipped inputs would not see: what the wasm inputs are made from (INPUT_PATHS, below) and
# the pddi shader sources (the Metal binaries are this machine's build/third_party/out/shaders/metal)
SHADER_PREFIX = ("src/platform/sdl/pddi/shaders/", "src/platform/wasm/run/app/shaders/")   # (+ the runner's)
SRC_DIRS = ["include", "src", "tools", "config"]
KEEP_INPUTS = 4
HASHCACHE = os.path.join(jobq.JOBS, "wb-hashcache.json")
# knobs a job may set (wasm_port / wasm_app / wasm_gfx read them); anything else is refused
ENV_OK = re.compile(r"^(HULK_WASM_[A-Z0-9_]+|HULK_PDDI_[A-Z0-9_]+)$")
ENV_NO = {"HULK_WASM_DIR", "HULK_WASM_SNAP", "HULK_WASM_BINDINGS"}


def tp(*p):
    return os.path.join(ROOT, "build/third_party", *p)


def ffmpeg_prefix():
    for p in (os.environ.get("HULK_FFMPEG_PREFIX"), "/opt/homebrew/opt/ffmpeg", "/usr/local/opt/ffmpeg"):
        if p and os.path.exists(os.path.join(p, "include/libavformat/avformat.h")):
            return p        # (rev5) not resolved: the app's library dir is the opt/ link, as in a local build
    return None


def input_items():
    """[(dest relative to inputs-STAMP, local path)]: what a wasm build reads from this machine besides the sources."""
    items = [("functions.csv", os.path.join(ROOT, "build/functions.csv")),
             ("third_party/out/sdl-video", os.environ.get("HULK_APP_SDL") or tp("out/sdl-video")),
             ("third_party/out/host/lib", tp("out/host/lib")),
             ("third_party/out/shaders/metal", tp("out/shaders/metal")),
             ("third_party/out/rm-shaders/metal", tp("out/rm-shaders/metal")),   # (the runner's: tools/rm_shaders.py)
             ("third_party/src/mingw-w64/mingw-w64-headers", tp("src/mingw-w64/mingw-w64-headers"))]
    items += [("third_party/src/%s/include" % n, tp("src", n, "include")) for n in ("bx", "bimg", "bgfx")]
    # (run/app/texpack.cpp includes bimg's stb_image by a path relative to bimg/include)
    items.append(("third_party/src/bimg/3rdparty/stb", tp("src/bimg/3rdparty/stb")))
    items += [("ckpt/" + f, os.path.join(ROOT, "build/ckpt", f)) for f in ("play3.ckref", "play3.ckref.json")]
    ff = ffmpeg_prefix()
    if ff:
        items.append(("ffmpeg/include", os.path.join(ff, "include")))
    return [(d, os.path.realpath(s)) for d, s in items if os.path.exists(s)]


def toolchain():
    """{"emscripten": (name, local root), "wabt": (name, local root)}: this machine's, by their Homebrew Cellar dirs."""
    emcc = os.path.realpath(os.environ.get("HULK_EMCC") or shutil.which("emcc") or "emcc")
    w2c = os.path.realpath(os.environ.get("HULK_WASM2C") or shutil.which("wasm2c") or "wasm2c")
    em_root = os.path.dirname(os.path.dirname(emcc))     # .../emscripten/<ver>   (bin/emcc or libexec/emcc)
    wabt_root = os.path.dirname(os.path.dirname(w2c))    # .../wabt/<ver>         (bin/wasm2c)
    for r, f in ((em_root, "libexec/emcc.py"), (wabt_root, "share/wabt/wasm2c/wasm-rt-impl.c")):
        if not os.path.exists(os.path.join(r, f)):
            sys.exit("toolchain: %s has no %s (HULK_EMCC / HULK_WASM2C)" % (r, f))
    node = os.environ.get("HULK_WB_NODE") or subprocess.run(
        [os.path.realpath(shutil.which("node") or "node"), "--version"], capture_output=True, text=True).stdout.strip()
    if not re.fullmatch(r"v\d+\.\d+\.\d+", node or ""):
        sys.exit("toolchain: no node here to take the version from (HULK_WB_NODE=vX.Y.Z)")
    return {"emscripten": ("emscripten-" + os.path.basename(em_root), em_root),
            "wabt": ("wabt-" + os.path.basename(wabt_root), wabt_root),
            "node": ("node-" + node, None)}


# ---------------------------------------------------------------------------------------------- hosts
def wasm_hosts():
    return [h["name"] for h in jobq.load_hosts() if not h.get("local") and "wasm" in h.get("caps", [])]


def host_cfg(name):
    for h in jobq.load_hosts():
        if h["name"] == name:
            return h
    sys.exit("unknown host " + name)


def ssh_parts(cfg):
    for r in cfg["routes"]:
        if subprocess.run(jobq.SSH + r + ["true"], capture_output=True).returncode == 0:
            return jobq.SSH + r[:-1], r[-1]
    sys.exit("cannot reach " + cfg["name"])


def remote(ssh, dest, script, check=True, capture=False):
    return subprocess.run(ssh + [dest, "sh -c " + shlex.quote(script)], check=check, capture_output=capture, text=True)


def rsync(ssh, src, dest, rpath, extra=()):
    e = " ".join(shlex.quote(x) for x in ssh)
    subprocess.run(["rsync", "-a", "--delete"] + list(extra) + ["-e", e, src, "%s:%s" % (dest, rpath)], check=True,
                   capture_output=True)


EM_CONFIG = """# written by tools/wasm_build_job.py setup: a copy of the submitter's Emscripten, used frozen
LLVM_ROOT = '{d}/libexec/llvm/bin'
BINARYEN_ROOT = '{d}/libexec/binaryen'
NODE_JS = '{node}/bin/node'
CACHE = '{d}/libexec/cache'
FROZEN_CACHE = True
"""


class host_lock:
    """(rev5) One sync to a host at a time: the daemon preps jobs in threads, and two syncs of one inputs-STAMP.tmp
    could mark a mix .complete. The lock file is wine_build_job.sync_host's (build/jobs/nb-sync-HOST.lock), so Wine
    build and wasm syncs to one host take turns too."""
    def __init__(self, name):
        import fcntl
        self.f = open(os.path.join(jobq.JOBS, "nb-sync-%s.lock" % name), "w")
        fcntl.flock(self.f, fcntl.LOCK_EX)

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.f.close()


def host_home(cfg):
    """The host checkout (hosts.json `dir`, default hulk-permute), as a path its shell expands."""
    return "~/" + cfg.get("dir", "hulk-permute")


KEEP_TC = 2         # versions of each toolchain piece kept on a host (the newest by mtime; ~1.1 GB an Emscripten)

PRUNE_TC = r"""
import os, shutil, sys, time
tc, keep, current = os.path.expanduser(sys.argv[1]), int(sys.argv[2]), set(sys.argv[3:])
by = {}
for n in os.listdir(tc):
    if n.endswith(".tmp") or n in current:
        continue
    by.setdefault(n.split("-", 1)[0], []).append((os.path.getmtime(os.path.join(tc, n)), n))
for kind, xs in by.items():
    for _, n in sorted(xs, reverse=True)[max(0, keep - 1):]:
        shutil.rmtree(os.path.join(tc, n), ignore_errors=True)
        print("pruned " + n)
"""


def sync_toolchain(name, quiet=False):
    with host_lock(name):
        _sync_toolchain(name, quiet)


def _sync_toolchain(name, quiet=False):
    """Make ~/hulk-jobs/wasm/tc/<emscripten-V>, <wabt-V> and <node-V> complete on the host."""
    cfg = host_cfg(name)
    ssh, dest = ssh_parts(cfg)
    tcs = toolchain()
    for kind in ("node", "emscripten", "wabt"):
        tname, root = tcs[kind]
        d = "%s/tc/%s" % (WB, tname)
        if remote(ssh, dest, "test -f %s/.complete" % d, check=False).returncode == 0:
            continue
        t0 = time.time()
        tmp = d + ".tmp"
        remote(ssh, dest, "mkdir -p %s" % tmp)
        if kind == "node":
            # emcc's link runs its JS compiler for the symbol lists (`compiler.mjs --symbols-only`) even for a standalone
            # module (nothing of it reaches the module): nodejs.org's own build, self-contained, checked against the
            # release's SHASUMS256.txt, fetched by the host (the laptop's Homebrew node links ~20 Homebrew libraries)
            v = tname[len("node-"):]
            f = "node-%s-darwin-arm64.tar.xz" % v
            remote(ssh, dest, ("set -e; cd {t}; curl -sfLO https://nodejs.org/dist/{v}/SHASUMS256.txt; "
                               "curl -sfLO https://nodejs.org/dist/{v}/{f}; grep ' {f}$' SHASUMS256.txt | shasum -a 256 -c -; "
                               "tar xf {f} --strip-components 1; rm -f {f} SHASUMS256.txt; ./bin/node --version"
                               ).format(t=tmp, v=v, f=f))
        elif kind == "emscripten":
            rsync(ssh, root + "/", dest, tmp + "/", ["--exclude", "__pycache__", "--exclude", "libexec/.emscripten",
                                                      "--exclude", "libexec/test/", "--exclude", "libexec/cache/*.lock"])
            home = remote(ssh, dest, "echo $HOME", capture=True).stdout.strip()
            final = d.replace("~", home, 1)
            cfgtxt = EM_CONFIG.format(d=final, node=final.rsplit("/tc/", 1)[0] + "/tc/" + toolchain()["node"][0])
            remote(ssh, dest, "cat > %s/libexec/.emscripten <<'EOF'\n%sEOF" % (tmp, cfgtxt))
        else:
            rsync(ssh, root + "/", dest, tmp + "/")
            # wasm2c links Homebrew's libcrypto: a copy beside it, the binary pointed there and signed again (ad hoc)
            out = subprocess.run(["otool", "-L", os.path.join(root, "bin/wasm2c")], capture_output=True, text=True).stdout
            fix = []
            for lib in re.findall(r"^\s+(/opt/homebrew/\S+|/usr/local/\S+)", out, re.M):
                rsync(ssh, os.path.realpath(lib), dest, "%s/lib/%s" % (tmp, os.path.basename(lib)))
                for b in ("wasm2c", "wasm-strip", "wat2wasm", "wasm2wat"):
                    fix.append("[ -f %s/bin/%s ] && install_name_tool -change %s @executable_path/../lib/%s %s/bin/%s "
                               "2>/dev/null; true" % (tmp, b, lib, os.path.basename(lib), tmp, b))
            fix.append("for b in %s/bin/*; do codesign -f -s - \"$b\" >/dev/null 2>&1; done; true" % tmp)
            remote(ssh, dest, "; ".join(fix))
        remote(ssh, dest, "touch %s/.complete && rm -rf %s && mv %s %s" % (tmp, d, tmp, d))
        msg = "toolchain %s on %s in %.0f s" % (tname, name, time.time() - t0)
        print(msg, file=sys.stderr if quiet else sys.stdout)
    # check it runs there
    tc = {k: v[0] for k, v in toolchain().items()}
    chk = ("EMSDK_PYTHON={home}/build/venv/bin/python {wb}/tc/{em}/libexec/emcc --version | head -1 && "
           "{wb}/tc/{wabt}/bin/wasm2c --version && {wb}/tc/{node}/bin/node --version").format(
               home=host_home(cfg), wb=WB, em=tc["emscripten"], wabt=tc["wabt"], node=tc["node"])
    r = remote(ssh, dest, chk, check=False, capture=True)
    if r.returncode:
        sys.exit("toolchain on %s does not run: %s" % (name, (r.stderr or r.stdout)[-400:]))
    # older versions beyond KEEP_TC (a job still on one names it in its spec; a removed one fails that job's check)
    remote(ssh, dest, "%s -c %s %s/tc %d %s" % (cfg.get("python", "python3"), shlex.quote(PRUNE_TC), WB, KEEP_TC,
                                                " ".join(sorted(tc.values()))), check=False)


def hashes(items):
    try:
        cache = json.load(open(HASHCACHE))
    except (OSError, ValueError):
        cache = {}
    out, dirty = {}, False
    for d, src in items:
        files = [src] if os.path.isfile(src) else [os.path.join(dp, f) for dp, dns, fns in os.walk(src) for f in fns]
        for p in sorted(files):
            st = os.stat(p)
            key = [st.st_mtime_ns, st.st_size]
            c = cache.get(p)
            if c and c[:2] == key:
                h = c[2]
            else:
                h = hashlib.sha1(open(p, "rb").read()).hexdigest()
                cache[p] = key + [h]
                dirty = True
            out[os.path.join(d, os.path.relpath(p, src)) if p != src else d] = h
    if dirty:
        tmp = HASHCACHE + ".%d" % os.getpid()
        json.dump(cache, open(tmp, "w"))
        os.replace(tmp, HASHCACHE)
    return out


def inputs_stamp():
    return hashlib.sha1(json.dumps(sorted(hashes(input_items()).items())).encode()).hexdigest()[:16]


PRUNE = r"""
import os, shutil, sys
wb, keep, protected = os.path.expanduser(sys.argv[1]), int(sys.argv[2]), set(sys.argv[3:])
ds = sorted(((os.path.getmtime(os.path.join(wb, n)), n) for n in os.listdir(wb)
             if n.startswith("inputs-") and not n.endswith(".tmp")), reverse=True)
for _, n in ds[keep:]:
    if n[7:] not in protected:
        shutil.rmtree(os.path.join(wb, n), ignore_errors=True)
"""


def live_stamps():
    out = set()
    try:
        for r in jobq.conn().execute("SELECT prep FROM jobs WHERE state IN ('queued', 'running') AND prep IS NOT NULL"):
            argv = json.loads(r["prep"])
            if "--stamp" in argv:
                out.add(argv[argv.index("--stamp") + 1])
    except Exception as e:  # noqa: BLE001
        print("live_stamps: %s" % e, file=sys.stderr)
    return out


def sync_inputs(name, stamp, quiet=False):
    with host_lock(name):
        _sync_inputs(name, stamp, quiet)


def _sync_inputs(name, stamp, quiet=False):
    cfg = host_cfg(name)
    ssh, dest = ssh_parts(cfg)
    d = "%s/inputs-%s" % (WB, stamp)
    if remote(ssh, dest, "test -f %s/.complete" % d, check=False).returncode == 0:
        return
    t0 = time.time()
    tmp = d + ".tmp"
    remote(ssh, dest, ("mkdir -p {wb}; cd {wb}; rm -rf {t}; prev=$(ls -dt inputs-*/ 2>/dev/null | grep -v tmp | head -1); "
                       "if [ -n \"$prev\" ]; then cp -Rcp \"$prev\" {t} 2>/dev/null || cp -Rp \"$prev\" {t}; "
                       "rm -f {t}/.complete; else mkdir {t}; fi").format(wb=WB, t="inputs-%s.tmp" % stamp))
    items = input_items()
    for dd, src in items:
        remote(ssh, dest, "mkdir -p %s/%s" % (tmp, os.path.dirname(dd) or "."))
        rsync(ssh, src + ("/" if os.path.isdir(src) else ""), dest, "%s/%s%s" % (tmp, dd, "/" if os.path.isdir(src) else ""))
    if inputs_stamp() != stamp:     # (rev5) the local inputs changed under the copy: never name a mix by STAMP
        remote(ssh, dest, "rm -rf %s" % tmp, check=False)
        sys.exit("the local inputs changed while they were copied to %s (stamp %s): submit again" % (name, stamp))
    keep = {dd.split("/")[0] for dd, _ in items}
    remote(ssh, dest, "cd %s && for x in *; do case \" %s \" in *\" $x \"*) ;; *) rm -rf \"$x\";; esac; done; "
                      "touch .complete && cd .. && rm -rf inputs-%s && mv inputs-%s.tmp inputs-%s"
           % (tmp, " ".join(sorted(keep)), stamp, stamp, stamp))
    py = cfg.get("python", "python3")
    remote(ssh, dest, "%s -c %s %s %d %s" % (py, shlex.quote(PRUNE), WB, KEEP_INPUTS,
                                             " ".join(sorted({stamp} | live_stamps()))), check=False)
    msg = "inputs %s on %s in %.0f s" % (stamp, name, time.time() - t0)
    print(msg, file=sys.stderr if quiet else sys.stdout)


def cmd_setup(a):
    stamp = inputs_stamp()
    for h in a.host or wasm_hosts():
        sync_toolchain(h)
        sync_inputs(h, stamp)
        print("%s: ready (inputs %s)" % (h, stamp))
    return 0


def cmd_prep(a):
    """The queue daemon runs this when it dispatches the job to a host (jobq `prep`): toolchain and inputs there."""
    sync_toolchain(a.host, quiet=True)
    cfg = host_cfg(a.host)
    ssh, dest = ssh_parts(cfg)
    if remote(ssh, dest, "test -f %s/inputs-%s/.complete" % (WB, a.stamp), check=False).returncode:
        now = inputs_stamp()
        if now != a.stamp:
            print("inputs %s are not on %s and this machine's are now %s" % (a.stamp, a.host, now), file=sys.stderr)
            return 2
        sync_inputs(a.host, a.stamp, quiet=True)
    return 0


def cmd_hosts(a):
    py = ("import os,json\nb=os.path.expanduser('~/hulk-jobs/wasm')\nr={}\n"
          "for s in ('tc','ws'):\n p=os.path.join(b,s)\n r[s]=sorted(os.listdir(p)) if os.path.isdir(p) else []\n"
          "r['inputs']=sorted(n for n in (os.listdir(b) if os.path.isdir(b) else []) if n.startswith('inputs-'))\n"
          "print(json.dumps(r))")
    for h in wasm_hosts():
        cfg = host_cfg(h)
        ssh, dest = ssh_parts(cfg)
        r = subprocess.run(ssh + [dest, "%s -c %s" % (cfg.get("python", "python3"), shlex.quote(py))],
                           capture_output=True, text=True)
        print(h, r.stdout.strip() or r.stderr.strip()[-200:])
    print("local: toolchain %s, inputs %s" % ({k: v[0] for k, v in toolchain().items()}, inputs_stamp()))
    return 0


# ---------------------------------------------------------------------------------------------- submit
def tgz_commit(p):
    try:
        with tarfile.open(p) as t:
            return json.load(t.extractfile("wasm-inputs/meta.json")).get("commit")
    except (OSError, KeyError, ValueError, tarfile.TarError):
        return None


def pack_dir(d):
    """A fetched wasm_inputs directory as the tarball wasm_inputs makes (cached by the directory's meta + mtime)."""
    meta = json.load(open(os.path.join(d, "meta.json")))
    out = os.path.join(jobq.JOBS, "wb-inputs", "%s.tgz" % meta["commit"][:12])
    if not os.path.exists(out) or os.path.getmtime(out) < os.path.getmtime(os.path.join(d, "meta.json")):
        os.makedirs(os.path.dirname(out), exist_ok=True)
        with tarfile.open(out + ".tmp", "w:gz", compresslevel=1) as t:
            t.add(d, arcname="wasm-inputs")
        os.replace(out + ".tmp", out)
    return out


# what the wasm inputs are made from (tools/wasm_inputs.py: the materialized tree and the binding map): inputs made at
# another commit fit HEAD when these paths are the same at both
INPUT_PATHS = ["include", "src/game", "src/engine", "src/platform/xbox", "src/link-order.txt", "config",
               "tools/wasm_inputs.py", "tools/tree_tu.py", "tools/wine_link.py", "tools/clang_probe.py"]
# config files the wasm build itself reads (wasm_port.py link), not the inputs
INPUT_EXCEPT = ["config/wasm-data-stubs.json"]


def same_tree(c1, c2):
    if not c1 or not c2:
        return False
    if c1 == c2:
        return True
    return subprocess.run(["git", "diff", "--quiet", c1, c2, "--"] + INPUT_PATHS +
                          [":(exclude)" + x for x in INPUT_EXCEPT], cwd=ROOT,
                          capture_output=True).returncode == 0


def find_inputs(sel, commit):
    """(tarball path or None for `make`, note)."""
    if sel == "make":
        return None, "made in the job"
    if sel == "auto":
        cands = []
        for n in os.listdir(jobq.OUT) if os.path.isdir(jobq.OUT) else []:
            p = os.path.join(jobq.OUT, n, "wasm-in.tgz")
            if os.path.exists(p):
                cands.append((os.path.getmtime(p), p))
        for _, p in sorted(cands, reverse=True)[:40]:
            c = tgz_commit(p)
            if same_tree(c, commit):
                return p, "auto: %s (made at %s)" % (os.path.relpath(p, ROOT), c[:12])
        d = os.path.join(ROOT, "build/wasm-inputs", commit[:12])
        if os.path.exists(os.path.join(d, "meta.json")):
            return pack_dir(d), "auto: " + os.path.relpath(d, ROOT)
        return None, "auto: no wasm inputs for %s's tree here, made in the job" % commit[:12]
    if sel.isdigit():
        p = os.path.join(jobq.OUT, sel, "wasm-in.tgz")
    else:
        p = os.path.abspath(sel)
    if os.path.isdir(p):
        if not os.path.exists(os.path.join(p, "meta.json")):
            sys.exit("--inputs %s: not a wasm_inputs directory (no meta.json)" % sel)
        p = pack_dir(p)
    if not os.path.exists(p):
        sys.exit("--inputs %s: no %s" % (sel, p))
    c = tgz_commit(p)
    if not same_tree(c, commit):
        print("note: the wasm inputs are from %s, whose tree differs from HEAD %s's" % ((c or "?")[:12], commit[:12]),
              file=sys.stderr)
    return p, os.path.relpath(p, ROOT)


def overlay(a, commit):
    """({dest: local path}, deletions)."""
    files, dele = {}, []
    if a.workspace:
        import wine_build_job
        files, dele = wine_build_job.overlay(os.path.abspath(a.workspace))
    # (rev5) --files adds to a workspace's overlay (and wins over it)
    for rel, (sha, mode) in jobq.collect_files(a.files, a.dirty, SRC_DIRS + ["tests"]).items():
        files[rel] = os.path.join(jobq.STORE, sha)
        if rel in dele:
            dele.remove(rel)
    return files, dele


def is_input_path(rel):
    return rel not in INPUT_EXCEPT and any(rel == x or rel.startswith(x + "/") for x in INPUT_PATHS)


TEST_KINDS = {"play3": 1, "rolltest": 2, "input": (1, 2)}
# (wqgpu1) the app on the host's GPU: FRAMES[:SHOTS], SHOTS game frames for HULK_GFX_SHOT_GAME ("1000,2000"; at most 64)
METAL_KINDS = ("metal", "metal-input", "metal-ab")
SHOT_MAX = 64
AB_KNOB = re.compile(r"^HULK_[A-Z0-9]+_AB$")
TEST_USAGE = ("play3:FRAMES, PLAYTHROUGH:FRAMES (tools/playthrough.py's NAME), rolltest:A:B, input:FRAMES[:EVERY], metal:FRAMES[:SHOTS], metal-input:FRAMES[:SHOTS] or "
              "metal-ab:FRAMES (SHOTS: game frames, comma-separated)")
TEST_ENV_OK = re.compile(r"^(HULK_[A-Z0-9_]+|SDL_[A-Z0-9_]+)$")
FETCHED = os.path.join(jobq.JOBS, "wb-fetched.json")


def parse_tests(specs, test_env, timeout):
    """--test [NAME=]play3:FRAMES | rolltest:A:B | input:FRAMES[:EVERY] -> the runner's test list."""
    env = {}
    for e in test_env or []:
        k, _, v = e.partition("=")
        if not TEST_ENV_OK.match(k):
            sys.exit("--test-env %s: HULK_* / SDL_* only" % k)
        env[k] = v
    out, names = [], set()
    for sp in specs or []:
        name, _, body = sp.rpartition("=")
        f = body.split(":")
        kind, nums = f[0], f[1:]
        if kind in METAL_KINDS:
            out.append(parse_metal(sp, name, kind, nums, env, timeout, names))
            continue
        rec = None
        if kind not in TEST_KINDS and playthrough_files(kind):
            rec, kind = kind, "play3"           # (wplay4) a playthrough's name: its replay, judged like play3's
        want = TEST_KINDS.get(kind)
        if want is None or not all(x.isdigit() for x in nums) or len(nums) not in (
                want if isinstance(want, tuple) else (want,)):
            sys.exit("--test %s: %s" % (sp, TEST_USAGE))
        nums = [int(x) for x in nums]
        t = {"kind": kind, "name": re.sub(r"[^A-Za-z0-9_.-]", "_", name or "-".join([rec or kind] + f[1:])), "env": env,
             "timeout": timeout}
        if rec:
            t["rec"] = rec
        if kind == "rolltest":
            if nums[1] <= nums[0]:
                sys.exit("--test %s: B must be after A" % sp)
            t.update(a=nums[0], b=nums[1])
        else:
            t["frames"] = nums[0]
            if len(nums) > 1:
                t["every"] = nums[1]
        if t["name"] in names:
            sys.exit("--test: two tests named %s (NAME=...)" % t["name"])
        names.add(t["name"])
        out.append(t)
    return out


def playthrough_files(name):
    """(recording, our own records) of a playthrough (tools/playthrough.py: build/playthrough/NAME/), or None"""
    if not re.fullmatch(r"[A-Za-z0-9_.-]+", name or ""):
        return None
    d = os.path.join(ROOT, "build/playthrough", name)
    hrp, ref = os.path.join(d, name + ".hrp"), os.path.join(d, name + ".self.ckref")
    return (hrp, ref) if os.path.exists(hrp) and os.path.exists(ref) else None


def parse_metal(sp, name, kind, f, env, timeout, names):
    """metal:FRAMES[:SHOTS] (a play3 replay), metal-input:FRAMES[:SHOTS] (a HULK_INPUT run), metal-ab:FRAMES (a play3
    replay timing a pass's HULK_<PASS>_AB turns, which --test-env must name)."""
    if not f or not f[0].isdigit() or len(f) > (1 if kind == "metal-ab" else 2):
        sys.exit("--test %s: %s" % (sp, TEST_USAGE))
    frames = int(f[0])
    shots = []
    if len(f) > 1 and f[1]:
        if not re.fullmatch(r"\d+(,\d+)*", f[1]):
            sys.exit("--test %s: SHOTS is a comma-separated list of game frames" % sp)
        shots = sorted({int(x) for x in f[1].split(",")})
        if len(shots) > SHOT_MAX:
            sys.exit("--test %s: at most %d shots (HULK_GFX_SHOT_GAME)" % (sp, SHOT_MAX))
        if shots[-1] > frames - 30:
            # (the run stops about a second after its target frame, and bgfx writes a shot a frame or two late)
            sys.exit("--test %s: shots must be at least 30 frames before FRAMES" % sp)
    if kind == "metal-ab" and not any(AB_KNOB.match(k) and v not in ("", "0") for k, v in env.items()):
        sys.exit("--test %s: name the pass to time with --test-env HULK_<PASS>_AB=N (HULK_LIGHT_AB, HULK_WINDOWS_AB, ...)"
                 % sp)
    if "HULK_GFX_SHOT_GAME" in env:
        sys.exit("--test %s: give the shots in the test (metal:FRAMES:SHOTS), not HULK_GFX_SHOT_GAME" % sp)
    t = {"kind": kind, "name": re.sub(r"[^A-Za-z0-9_.-]", "_", name or "-".join([kind] + [x.replace(",", "_") for x in f])),
         "env": env, "timeout": timeout, "frames": frames, "shots": shots}
    if t["name"] in names:
        sys.exit("--test: two tests named %s (NAME=...)" % t["name"])
    names.add(t["name"])
    return t


def gpu_hosts():
    return [h["name"] for h in jobq.load_hosts() if not h.get("local") and "gpu" in h.get("caps", [])]


def resolve_exe(x):
    """An executable: a path, or a wasm build job's id (its wb-out/, or where `fetch` moved it)."""
    if not x.isdigit():
        p = os.path.abspath(x)
        if os.path.isdir(p):
            p = next((os.path.join(p, n) for n in ("hulk-app", "hulk-aot") if os.path.exists(os.path.join(p, n))), p)
        if not os.path.isfile(p):
            sys.exit("no executable %s" % x)
        return p
    dirs = [out_dir(x)]
    try:
        dirs.append(json.load(open(FETCHED)).get(x))
    except (OSError, ValueError):
        pass
    for d in filter(None, dirs):
        for n in ("hulk-app", "hulk-aot"):
            if os.path.exists(os.path.join(d, n)):
                return os.path.join(d, n)
    sys.exit("job %s: no hulk-app / hulk-aot in %s" % (x, " or ".join(filter(None, dirs))))


def submit_job(a, spec, ov, slots, limit, label):
    stamp = inputs_stamp()
    spec.update({"inputs_stamp": stamp, "toolchain": {k: v[0] for k, v in toolchain().items()}, "submitted_by": a.name,
                 "tests": parse_tests(a.test, a.test_env, a.test_timeout)})
    if any(t["kind"] in ("play3", "metal", "metal-ab") for t in spec["tests"]):
        rec = os.path.join(ROOT, "build/rp1/play3.hrp")
        if not os.path.exists(rec) or "ckpt/play3.ckref" not in {d for d, _ in input_items()}:
            sys.exit("play3 tests need build/rp1/play3.hrp and build/ckpt/play3.ckref here")
        ov["wbrun/play3.hrp"] = rec
    for t in spec["tests"]:
        if t.get("rec"):
            hrp, ref = playthrough_files(t["rec"])
            ov["wbrun/%s.hrp" % t["rec"]] = hrp
            ov["wbrun/%s.self.ckref" % t["rec"]] = ref
    for role, x in (("ctl", getattr(a, "control", None)), ("cand", getattr(a, "exe", None))):
        if x:
            p = resolve_exe(x)
            dest = "wbrun/exe-%s/%s" % (role, os.path.basename(p))
            ov[dest] = p
            spec.setdefault("exes", {})[role] = dest
    if spec.get("exes", {}).get("ctl") and not spec["tests"]:
        sys.exit("--control needs --test")
    with tempfile.NamedTemporaryFile("w", suffix=".json", delete=False) as tf:
        json.dump(spec, tf, indent=1)
    ov.update({"wbrun/spec.json": tf.name, "wbrun/wasm_build_run.py": os.path.join(ROOT, "tools/wasm_build_run.py")})
    store = {dest: [jobq.store_file(p), os.stat(p).st_mode & 0o777] for dest, p in ov.items()}
    os.unlink(tf.name)
    if a.host and a.host not in wasm_hosts():
        sys.exit("%s has no `wasm` capability (hosts.json; wasm hosts: %s)" % (a.host, ", ".join(wasm_hosts())))
    # a job with a Metal test needs a host's GPU (`gpu`: mac2 and studio, which are wasm hosts too); the daemon runs at
    # most gpu_max (1) such jobs per host at a time
    needs = "gpu" if any(t["kind"] in METAL_KINDS for t in spec["tests"]) else "wasm"
    if needs == "gpu":
        if spec["target"] == "aot":
            sys.exit("metal tests run the app: --target app")
        for role, p in (spec.get("exes") or {}).items():
            if os.path.basename(p) != "hulk-app":
                sys.exit("metal tests run the app (hulk-app), not %s" % os.path.basename(p))
        both = [h for h in gpu_hosts() if h in wasm_hosts()]
        if not both:
            sys.exit("no host has both the `gpu` and `wasm` capabilities (hosts.json)")
        if a.host and a.host not in both:
            sys.exit("%s has no `gpu` capability (hosts.json; GPU hosts: %s)" % (a.host, ", ".join(both)))
    prep = [sys.executable, os.path.abspath(__file__), "prep", "--host", "{host}", "--stamp", stamp]
    job = jobq.make_job(a.name, ["python", "wbrun/wasm_build_run.py"], needs, store, ["wb-out"], limit, slots,
                        a.attempts, a.prio, spec["commit"], jobq.BASE_PATHS, a.host, prep=prep)
    jid = jobq.submit_jobs([job])[0]
    print(jid)
    print("%s; tests: %s%s" % (label, ", ".join(t["name"] for t in spec["tests"]) or "none",
                               "; host " + a.host if a.host else ""), file=sys.stderr)
    return 0


def cmd_submit(a):
    commit = jobq.head_commit()
    files, dele = overlay(a, commit)
    tree = sorted(f for f in list(files) + dele if is_input_path(f))
    tgz, note = find_inputs(a.inputs, commit)
    if tree and tgz and not a.tree_ok:
        sys.exit("refused: the overlay changes %d file(s) the wasm inputs are made from (%s ...) but the inputs are %s, "
                 "which the build uses as they are: pass --inputs make (the job makes them from its sources) or "
                 "--tree-ok (the inputs already hold the change)" % (len(tree), tree[0], note))
    shaders = sorted(f for f in list(files) + dele if f.startswith(SHADER_PREFIX))
    if shaders and a.target == "app" and not a.shaders_ok:
        sys.exit("refused: the overlay changes pddi shader sources (%s ...), but the app embeds this machine's compiled "
                 "Metal shaders (build/third_party/out/shaders/metal, out/rm-shaders/metal): compile them here first "
                 "(tools/wine_gfx.py shaders; tools/rm_shaders.py for run/app/shaders) and pass --shaders-ok" % shaders[0])
    env = {}
    for e in a.env or []:
        k, _, v = e.partition("=")
        if not ENV_OK.match(k) or k in ENV_NO:
            sys.exit("--env %s: only HULK_WASM_* / HULK_PDDI_* build knobs (not %s)" % (k, ", ".join(sorted(ENV_NO))))
        env[k] = v
    names = {i[0] for i in input_items()}
    if a.target == "app":
        for need in ("third_party/out/sdl-video", "third_party/out/host/lib", "third_party/out/shaders/metal"):
            if need not in names:
                sys.exit("the app needs %s here (tools/wasm_app.py sdl; tools/wine_gfx.py)" % need)
    lineage = re.sub(r"[^A-Za-z0-9_.-]", "_", a.lineage or "%s-%s" % (a.name, a.target))
    spec = {"commit": commit, "target": a.target, "bundle": bool(a.bundle), "lineage": lineage, "jobs": a.slots,
            "inputs": "make" if tgz is None else "tgz", "inputs_note": note,
            "env": env, "deletions": dele, "keep_wasm": bool(a.keep_wasm), "macos_min": a.macos_min,
            "ffmpeg_libdir": os.path.join(ffmpeg_prefix() or "/opt/homebrew/opt/ffmpeg", "lib"), "overlay": len(files)}
    ov = dict(files)
    if tgz:
        ov["wbrun/wasm-in.tgz"] = tgz
    a.exe = None
    limit = a.limit or (5400 if tgz is None else 3600) + (len(a.test or []) * (2 if a.control else 1) * a.test_timeout)
    return submit_job(a, spec, ov, a.slots, limit, "wasm %s build at %s: %d overlay files, %d deletions, inputs %s, "
                      "lineage %s, %d slots" % (a.target, commit[:12], len(files), len(dele), note, lineage, a.slots))


def cmd_test(a):
    """Tests of built executables (no build): --exe, and --control for a pair on one host."""
    if not a.test:
        sys.exit("test: name at least one --test")
    commit = jobq.head_commit()
    spec = {"commit": commit, "target": "none", "env": {}, "deletions": []}
    limit = a.limit or 600 + len(a.test) * (2 if a.control else 1) * a.test_timeout
    return submit_job(a, spec, {}, 1, limit, "wasm tests of %s%s" % (a.exe, " against control %s" % a.control
                                                                       if a.control else ""))


def out_dir(jid):
    return os.path.join(jobq.OUT, str(jid), "wb-out")


def cmd_wait(a):
    rc = subprocess.run([sys.executable, os.path.join(ROOT, "tools/jobq.py"), "wait", a.id]).returncode
    s = os.path.join(out_dir(a.id), "summary.json")
    if os.path.exists(s):
        summ = json.load(open(s))
        print(json.dumps({k: summ.get(k) for k in ("result", "host", "commit", "target", "compile", "steps", "wall_s",
                                                    "build_wall_s", "lineage_wait_s", "exe_sha1") if k in summ},
                         indent=1))
        for name, t in (summ.get("tests") or {}).items():
            print("TEST %s: %s" % (name, "ok" if t.get("ok") else "FAILED"))
            for role in ("cand", "ctl", "compare"):
                if role in t:
                    print("  %-7s %s" % (role, json.dumps({k: v for k, v in t[role].items() if k != "lines"})))
    else:
        print("no summary (tools/jobq.py result %s)" % a.id)
    return rc


def cmd_fetch(a):
    src = out_dir(a.id)
    if not os.path.exists(os.path.join(src, "summary.json")):
        sys.exit("no %s (job not done? tools/jobq.py result %s)" % (src, a.id))
    summ = json.load(open(os.path.join(src, "summary.json")))
    if summ.get("result") not in ("ok", "tests failed"):
        sys.exit("job %s did not finish: %s" % (a.id, summ.get("result")))
    try:
        name = jobq.conn().execute("SELECT name FROM jobs WHERE id=?", (int(a.id),)).fetchone()["name"]
    except Exception:  # noqa: BLE001
        name = "wasm"
    dest = os.path.abspath(a.dest or os.path.join(ROOT, "build", name, "wasm-%s-%s" % (summ["target"], a.id)))
    if not dest.startswith(os.path.join(ROOT, "build") + os.sep):
        sys.exit("the artefacts stay under build/ (they are built from the game: never committed or published)")
    os.makedirs(dest, exist_ok=True)
    for f in sorted(os.listdir(src)):
        t = os.path.join(dest, f)
        if os.path.isdir(t) and not os.path.islink(t):
            shutil.rmtree(t)
        elif os.path.lexists(t):
            os.remove(t)
        shutil.move(os.path.join(src, f), t)
    with open(os.path.join(dest, "job.json"), "w") as f:
        json.dump({"job": a.id, "fetched": time.strftime("%Y-%m-%d %H:%M:%S")}, f)
    try:
        idx = json.load(open(FETCHED))
    except (OSError, ValueError):
        idx = {}
    idx[str(a.id)] = dest
    with open(FETCHED + ".tmp", "w") as f:
        json.dump(idx, f, indent=0)
    os.replace(FETCHED + ".tmp", FETCHED)
    print("%s: %s (job %s, %s on %s)" % (dest, ", ".join(sorted(os.listdir(dest))), a.id, summ["commit"][:12],
                                         summ["host"]))
    if summ["target"] in TARGETS:
        exe = "hulk-app" if summ["target"] == "app" else "hulk-aot"
        print("run: build/venv/bin/python tools/native_replay.py run --exe %s ... -- $PWD/isos/extracted/default.xbe"
              % os.path.relpath(os.path.join(dest, exe), ROOT))
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    p = sp.add_parser("submit")
    p.add_argument("--name", required=True)
    p.add_argument("--target", choices=TARGETS, required=True)
    p.add_argument("--bundle", action="store_true", help="app: also the Hulk.app bundle")
    p.add_argument("--inputs", default="auto", help="auto | make | JOB | FILE.tgz | DIR")
    p.add_argument("--tree-ok", action="store_true", help="the inputs already hold the overlay's tree edits")
    p.add_argument("--shaders-ok", action="store_true",
                   help="this machine's compiled shaders (build/third_party/out/shaders/metal) hold the overlay's edits")
    g = p.add_mutually_exclusive_group()
    g.add_argument("--workspace", help="a private workspace: its files that differ from HEAD travel")
    g.add_argument("--dirty", action="store_true", help="every modified/untracked file of this checkout")
    p.add_argument("--files", nargs="*", default=[], help="PATH or SRC=DEST to overlay (on top of --workspace / --dirty)")
    p.add_argument("--env", nargs="*", help="HULK_WASM_*=V / HULK_PDDI_*=V build knobs")
    p.add_argument("--host", help="pin to a wasm host")
    p.add_argument("--lineage", help="the host's build directory (default NAME-TARGET)")
    p.add_argument("--slots", type=int, default=8)
    p.add_argument("--limit", type=int, help="seconds per attempt (default 3600; 5400 with inputs made in the job)")
    p.add_argument("--attempts", type=int, default=2)
    p.add_argument("--prio", type=int, default=0)
    p.add_argument("--keep-wasm", action="store_true", help="also return hulk.wasm")
    p.add_argument("--macos-min", default="11.0", help="MACOSX_DEPLOYMENT_TARGET of the executables")
    p.add_argument("--control", help="tests: also run this executable (path or wasm job id) and compare")

    def test_opts(q):
        q.add_argument("--test", action="append", help="[NAME=]play3:FRAMES | rolltest:A:B | input:FRAMES[:EVERY] | "
                       "metal:FRAMES[:SHOTS] | metal-input:FRAMES[:SHOTS] | metal-ab:FRAMES")
        q.add_argument("--test-env", action="append", help="HULK_*/SDL_* K=V for every test run")
        q.add_argument("--test-timeout", type=int, default=3600, help="seconds per test run")
    test_opts(p)
    p = sp.add_parser("test")
    p.add_argument("--name", required=True)
    p.add_argument("--exe", required=True, help="the candidate: a path or a wasm build job id")
    p.add_argument("--control", help="the control: a path or a wasm build job id (same host, compared)")
    p.add_argument("--host")
    p.add_argument("--limit", type=int)
    p.add_argument("--attempts", type=int, default=2)
    p.add_argument("--prio", type=int, default=0)
    test_opts(p)
    p = sp.add_parser("wait")
    p.add_argument("id")
    p = sp.add_parser("fetch")
    p.add_argument("id")
    p.add_argument("--dest")
    p = sp.add_parser("setup")
    p.add_argument("--host", nargs="*")
    p = sp.add_parser("prep")
    p.add_argument("--host", required=True)
    p.add_argument("--stamp", required=True)
    sp.add_parser("hosts")
    a = ap.parse_args()
    return {"submit": cmd_submit, "test": cmd_test, "wait": cmd_wait, "fetch": cmd_fetch, "setup": cmd_setup, "prep": cmd_prep,
            "hosts": cmd_hosts}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
