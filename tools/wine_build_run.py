#!/usr/bin/env python3
"""Host side of tools/wine_build_job.py: a full native build (MSVC tree build, clang probe, native link) and an optional
replay, as one queue job on any host (python 3.9 compatible, stdlib only). It runs inside the job's run directory (jobq: a
clone of the base tree, `git archive HEAD` of SRC_DIRS, plus the submitter's overlay) with the spec in nbrun/spec.json.

The run directory is thrown away when the job ends. What survives is a per-host lineage workspace,
~/hulk-jobs/nb/ws/LINEAGE, so a one-file change does not rebuild everything:
  * sources (SRC_DIRS) are synced into it by content hash (.nb/manifest.json): nothing depends on mtimes;
  * build/tree (build_tree's state and merged tree), build/clang-probe/snap and build/native (binding map, link) stay;
  * the content-keyed object caches are per host and shared by all lineages (NB/cache; the checkout's own build/ on
    the laptop);
  * the toolchain is stamped (.nb/toolchain.json: clang, lld-link, wibo, cl.exe, python); a different stamp drops
    all derived state, and decide() says when the build_tree state and the binding map may be reused.
Local-only inputs (the extracted disc, build/functions.csv, rtti.json, the data TUs, the prebuilt third-party
libraries) are put on each host by `wine_build_job.py sync` (NB/inputs-STAMP, immutable, named by content hash) and linked in.

Outputs (fetched by the queue): nb-out/{summary.json,*.log,link-report.json,unbound.txt,image.sha256,ckpt.txt,
trace.txt,result.json} and, when the spec asks for it, the image and its DLLs in nb-out/image/.
Exit status: 0 all requested stages done, 3 inputs stale/missing, 4 a build stage failed, 5 the replay failed.
"""
import fcntl
import hashlib
import json
import os
import shutil
import subprocess
import sys
import time

SRC_DIRS = ["matches", "equivalent", "include", "src", "tools", "config"]
INPUT_FILES = ["build/functions.csv", "build/rtti.json", "build/xbsymbols.txt", "build/port/platform_calls.json"]
TP = "build/third_party/out/"
INPUT_DIRS = ["build/data/src", TP + "pddi-win32/obj", TP + "win32/lib", TP + "sdl-backends/win32", TP + "sdl-win32",
              TP + "fs1/win32", TP + "ffmpeg-win32/movies", TP + "ffmpeg-win32/dll"]
IMAGE_FILES = ["hulk-strict.exe", "SDL3.dll", "hulkmovie.dll", "avutil-60.dll", "avcodec-62.dll", "avformat-62.dll"]
DLL_SRC = {"SDL3.dll": "sdl-win32/SDL3.dll", "hulkmovie.dll": "ffmpeg-win32/movies/hulkmovie.dll",
           "avutil-60.dll": "ffmpeg-win32/dll/avutil-60.dll", "avcodec-62.dll": "ffmpeg-win32/dll/avcodec-62.dll",
           "avformat-62.dll": "ffmpeg-win32/dll/avformat-62.dll"}
NB = os.path.expanduser("~/hulk-jobs/nb")
SKIP_DIRS = ("__pycache__", ".git")


def sha_file(p):
    h = hashlib.sha1()
    with open(p, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def sha_image(p):
    """sha1 of an image with the PE header's TimeDateStamp zeroed (lld-link stamps the link time; nothing else varies)."""
    import struct
    data = bytearray(open(p, "rb").read())
    if data[:2] == b"MZ":
        pe = struct.unpack_from("<I", data, 0x3c)[0]
        if data[pe:pe + 4] == b"PE\0\0":
            data[pe + 8:pe + 12] = b"\0\0\0\0"
    return hashlib.sha1(bytes(data)).hexdigest()


def scan(root, dirs):
    """{relative path: sha1} of the files under root/dirs (no caches, no .pyc)."""
    out = {}
    for d in dirs:
        for dp, dns, fns in os.walk(os.path.join(root, d)):
            dns[:] = [x for x in dns if x not in SKIP_DIRS]
            for fn in fns:
                if fn == ".DS_Store" or fn.endswith(".pyc"):
                    continue
                p = os.path.join(dp, fn)
                if os.path.islink(p) and not os.path.exists(p):
                    continue
                out[os.path.relpath(p, root)] = sha_file(p)
    return out


def log(msg):
    sys.stdout.write("[nb %s] %s\n" % (time.strftime("%H:%M:%S"), msg))
    sys.stdout.flush()


def jload(p, default=None):
    try:
        with open(p) as f:
            return json.load(f)
    except (OSError, ValueError):
        return default


def jsave(p, obj):
    os.makedirs(os.path.dirname(p), exist_ok=True)
    tmp = p + ".%d.tmp" % os.getpid()
    with open(tmp, "w") as f:
        json.dump(obj, f)
    os.replace(tmp, p)


def diff_manifests(old, new):
    ch = {"added": [], "modified": [], "removed": []}
    for rel, sha in new.items():
        if rel not in old:
            ch["added"].append(rel)
        elif old[rel] != sha:
            ch["modified"].append(rel)
    ch["removed"] = [r for r in old if r not in new]
    return ch


def sync_sources(run, lin, deletions):
    """Make lin's SRC_DIRS files equal run's (content hashes, not mtimes). Returns (new manifest, changes)."""
    for rel in deletions:
        try:
            os.unlink(os.path.join(run, rel))
        except OSError:
            pass
    new = scan(run, SRC_DIRS)
    old = jload(os.path.join(lin, ".nb/manifest.json"), {})
    ch = diff_manifests(old, new)
    for rel, sha in new.items():
        dst = os.path.join(lin, rel)
        if old.get(rel) == sha and os.path.isfile(dst):
            continue
        if rel in old and rel not in ch["modified"]:
            ch["modified"].append(rel)     # recorded but missing on disk: restored
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        tmp = dst + ".nbtmp"
        shutil.copyfile(os.path.join(run, rel), tmp)
        os.chmod(tmp, os.stat(os.path.join(run, rel)).st_mode & 0o777)
        os.replace(tmp, dst)
    for rel in ch["removed"]:
        try:
            os.unlink(os.path.join(lin, rel))
        except OSError:
            pass
    jsave(os.path.join(lin, ".nb/manifest.json"), new)
    ch["portable"] = portable(lin, [r for r in new if r.startswith("tools/")])     # (all of them: idempotent, and an older sync may have skipped it)
    return new, ch


HOMEBREW_LLVM = "/opt/homebrew/opt/llvm/bin"


def portable(lin, rels):
    """Older copies of the build tools name Homebrew's LLVM directly (newer ones find it through clang_probe.LLVM): on a host
    without it, point those literals at the host's LLVM so a workspace made before that change still builds. Only the lineage's
    copy is touched (the manifest keeps the shipped content's hash), and only the compiler's location changes."""
    if os.path.exists(os.path.join(HOMEBREW_LLVM, "llvm-undname")):
        return 0
    llvm = os.path.expanduser("~/llvm/bin")
    n = 0
    for rel in rels:
        if rel.startswith("tools/") and rel.endswith(".py"):
            p = os.path.join(lin, rel)
            t = open(p, errors="surrogateescape").read()
            if HOMEBREW_LLVM in t:
                with open(p, "w", errors="surrogateescape") as f:
                    f.write(t.replace(HOMEBREW_LLVM, llvm))
                n += 1
    return n


def purge_cached_errors(d):
    """wine_link (older copies) cached an equiv.py failure as the function's result for good; such an entry is a transient
    error (see main()), so it is dropped before a link and the function is checked again. Error results are tiny."""
    n = 0
    if os.path.isdir(d):
        for e in os.scandir(d):
            if e.name.endswith(".json") and e.stat().st_size < 200:
                try:
                    if '"status": "error' in open(e.path).read():
                        os.unlink(e.path)
                        n += 1
                except OSError:
                    pass
    return n


def link_to(path, target):
    if os.path.islink(path) and os.readlink(path) == target:
        return
    if os.path.lexists(path):
        if os.path.islink(path) or os.path.isfile(path):
            os.unlink(path)
        else:
            shutil.rmtree(path)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    os.symlink(target, path)


def cmd_out(cmd):
    try:
        return subprocess.run(cmd, capture_output=True, text=True, timeout=60).stdout.strip()
    except (OSError, subprocess.SubprocessError):
        return ""


def toolchain(lin, home):
    """Identity of everything outside the sources that shapes the objects and the image."""
    sys.path.insert(0, os.path.join(lin, "tools"))
    import clang_probe
    import compare
    llvm = clang_probe.LLVM

    def sha(p):
        return sha_file(p) if os.path.exists(p) else None
    return {"clang": cmd_out([os.path.join(llvm, "clang++"), "--version"]).splitlines()[:1],
            "lld-link": cmd_out([os.path.join(llvm, "lld-link"), "--version"]).splitlines()[:1],
            "wibo": sha(compare.WIBO), "cl": sha(os.path.join(compare.MSVC, "Bin/cl.exe")),
            "c1xx": sha(os.path.join(compare.MSVC, "Bin/c1xx.dll")),
            "xbe": sha(os.path.join(home, "isos/extracted/default.xbe")),
            "python": sys.version.split()[0].rsplit(".", 1)[0]}


def closure(tools, entry):
    """Names of the tools/ modules (as tools/NAME.py) the script ENTRY imports, directly or not (static scan)."""
    import re
    seen, todo = set(), [entry]
    while todo:
        n = todo.pop()
        if n in seen or not os.path.exists(os.path.join(tools, n + ".py")):
            continue
        seen.add(n)
        for m in re.finditer(r"^\s*(?:import|from)\s+([A-Za-z_]\w*)", open(os.path.join(tools, n + ".py"), errors="replace").read(), re.M):
            todo.append(m.group(1))
    return {"tools/%s.py" % n for n in seen}


def decide(spec, built, mapped, new, lin):
    """(resume the build_tree state?, reuse the binding map?, reasons).

    The state (build_tree --resume) keeps the fallbacks (wrapped/isolated functions) an earlier build found; a resumed
    build is verified like a fresh one but can keep a fallback a fresh build would not need, so it is only taken when,
    since the last good build, only function sources (matches/ equivalent/) and files the tree build does not read
    (src/, the tools outside build_tree's imports) changed. The binding map (wine_link --reuse-map) is only reused
    when, since it was made, sources were modified but none added or removed, and nothing under include/ config/ or in
    wine_link's imports changed."""
    tools = os.path.join(lin, "tools")
    tree_files, map_files = closure(tools, "build_tree"), closure(tools, "wine_link")

    def classify(old, watched):
        ch = diff_manifests(old, new)
        n = {k: len(v) for k, v in ch.items()}
        shape = [r for r in ch["added"] + ch["removed"] if r.startswith(("matches/", "equivalent/"))]
        core = [r for k in ("added", "modified", "removed") for r in ch[k]
                if r.startswith(("include/", "config/")) or r in watched]
        return n, shape, core
    st, mp, why = spec.get("state", "auto"), spec.get("map", "auto"), {}
    have_tree = built is not None and os.path.exists(os.path.join(lin, "build/tree/state.json"))
    if st == "fresh" or not have_tree:
        resume = False
        why["state"] = "fresh requested" if st == "fresh" else "no earlier build in this lineage"
    elif st == "resume":
        resume = True
        why["state"] = "resume requested"
    else:
        n, shape, core = classify(built, tree_files)
        resume = not core
        why["state"] = ("resume: %s since the last build; none of include/ config/ or the tree build's tools" % n) if resume else \
            "fresh: %d inputs of the tree build changed (%s)" % (len(core), ", ".join(core[:3]))
    have_map = mapped is not None and os.path.exists(os.path.join(lin, "build/native/bindings.json"))
    if mp == "full" or not have_map or not resume:
        reuse = False
        why["map"] = ("full map requested" if mp == "full" else "no earlier map in this lineage" if not have_map
                      else "full map: the build_tree state started fresh")
    elif mp == "reuse":
        reuse = True
        why["map"] = "reuse requested"
    else:
        n, shape, core = classify(mapped, map_files)
        reuse = not core and not shape
        why["map"] = ("reuse: %s since the map, no function source added or removed" % n) if reuse else \
            "full map: %d function sources added/removed, %d map inputs changed (%s)" % (len(shape), len(core), ", ".join(core[:3]))
    return resume, reuse, why


def stage(name, argv, env, cwd, outdir):
    t0 = time.time()
    if shutil.which("caffeinate"):
        argv = ["caffeinate", "-is"] + argv
    log("%s: %s" % (name, " ".join(argv)))
    with open(os.path.join(outdir, name + ".log"), "wb") as lg:
        rc = subprocess.call(argv, cwd=cwd, env=env, stdin=subprocess.DEVNULL, stdout=lg, stderr=subprocess.STDOUT)
    wall = round(time.time() - t0, 1)
    log("%s: exit %d in %.0f s" % (name, rc, wall))
    return rc, wall


def flock_lineage(path):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    f = open(path, "w")
    t0, told = time.time(), time.time()
    while True:
        try:
            fcntl.flock(f, fcntl.LOCK_EX | fcntl.LOCK_NB)
            return f, time.time() - t0
        except OSError:
            if time.time() - told > 120:
                log("waiting for another job on this lineage")
                told = time.time()
            time.sleep(2)


def gc(keep_days=10):
    """Remove lineages nobody used for KEEP_DAYS days (never one that is locked)."""
    wsd = os.path.join(NB, "ws")
    if not os.path.isdir(wsd):
        return
    for n in os.listdir(wsd):
        p = os.path.join(wsd, n)
        try:
            if time.time() - os.path.getmtime(os.path.join(p, ".nb/manifest.json")) > keep_days * 86400:
                lk = open(os.path.join(NB, "locks", n + ".lock"), "a")
                fcntl.flock(lk, fcntl.LOCK_EX | fcntl.LOCK_NB)
                log("gc: lineage %s unused for %d days, removed" % (n, keep_days))
                shutil.rmtree(p, ignore_errors=True)
        except (OSError, ValueError):
            pass


def image_src(n, lin, inp):
    return os.path.join(lin, "build/native/link", n) if n == "hulk-strict.exe" else os.path.join(inp, TP, DLL_SRC[n])


def main():
    run = os.getcwd()
    spec = json.load(open(os.path.join(run, "nbrun/spec.json")))
    host, home = os.environ.get("JOBQ_HOST", "?"), os.path.expanduser(os.environ.get("JOBQ_HOME", ""))
    local = host == "local"
    out = os.path.join(run, "nb-out")
    os.makedirs(out, exist_ok=True)
    summ = {"host": host, "job": os.environ.get("JOBQ_JOB"), "lineage": spec["lineage"], "stages": {}, "wall": {}}
    T0 = time.time()

    def finish(code, msg=None):
        if msg:
            summ["error"] = msg
            log("FAILED: " + msg)
        summ["wall"]["total"] = round(time.time() - T0, 1)
        summ["exit"] = code
        json.dump(summ, open(os.path.join(out, "summary.json"), "w"), indent=1)
        sys.exit(code)

    # inputs: the checkout itself on the laptop, NB/inputs-STAMP (put there by `wine_build_job.py sync`) elsewhere
    inp = home if local else os.path.join(NB, "inputs-" + spec["inputs_stamp"])
    if not local and not os.path.exists(os.path.join(inp, ".complete")):
        finish(3, "inputs %s are not on %s: run wine_build_job.py sync" % (spec["inputs_stamp"], host))
    for f in ("isos/extracted/default.xbe", "build/venv/bin/python", "build/tools/wibo"):
        if not os.path.exists(os.path.join(home, f)):
            finish(3, "%s is missing on %s (%s)" % (f, host, home))
    caches = ({"tree": "build/tree-cache", "clang": "build/clang-probe/cache", "native": "build/native/cache"} if local else
              {"tree": "tree-cache", "clang": "clang-cache", "native": "native-cache"})
    croot = home if local else os.path.join(NB, "cache")
    lin = os.path.join(NB, "ws", spec["lineage"])
    lock, waited = flock_lineage(os.path.join(NB, "locks", spec["lineage"] + ".lock"))
    summ["wall"]["lineage_wait"] = round(waited, 1)
    os.makedirs(lin, exist_ok=True)
    if not local:
        gc()
    t = time.time()
    manifest, changes = sync_sources(run, lin, spec.get("deletions", []))
    summ["wall"]["sync_sources"] = round(time.time() - t, 1)
    summ["sync"] = {k: (len(v) if isinstance(v, list) else v) for k, v in changes.items()}
    summ["sources_hash"] = hashlib.sha1(json.dumps(sorted(manifest.items())).encode()).hexdigest()[:16]
    log("sources: %s -> %s" % (summ["sync"], summ["sources_hash"]))

    # lineage layout: shared local-only things are symlinks, derived state stays
    for n in ("venv", "compilers", "tools"):
        link_to(os.path.join(lin, "build", n), os.path.join(home, "build", n))
    link_to(os.path.join(lin, "isos"), os.path.join(home, "isos"))
    # (equiv.py's CRT table cache, build/equiv/crt2.json, is written non-atomically on first use: a cold lineage let
    # wine_link's workers read it half written, and the resulting equiv errors were cached, so the binding map and the
    # image depended on that race. The host's own build/equiv has the file.)
    link_to(os.path.join(lin, "build/equiv"), os.path.join(home, "build/equiv"))
    for n in ("functions.csv", "rtti.json", "xbsymbols.txt", "port", "data", "third_party"):
        link_to(os.path.join(lin, "build", n), os.path.join(inp, "build", n))
    tcache = os.path.join(croot, caches["tree"])
    os.makedirs(tcache, exist_ok=True)
    link_to(os.path.join(lin, "build/tree-cache"), tcache)
    env = dict(os.environ)
    env.update({"HULK_GFX_OUT": os.path.join(inp, TP[:-1]), "HULK_SDL_OUT": os.path.join(inp, TP[:-1]),
                "HULK_CLANG_PROBE_CACHE": os.path.join(croot, caches["clang"]),
                "HULK_WINE_CACHE": os.path.join(croot, caches["native"]),
                "PYTHONDONTWRITEBYTECODE": "1",
                "PYTHONHASHSEED": "0"})     # (set iteration order decides object/stub order in the link: the image must not depend on the run)
    env.pop("PYTHONPYCACHEPREFIX", None)
    env.update(spec.get("env", {}))
    py = os.path.join(lin, "build/venv/bin/python")

    # toolchain stamp: other tools than the lineage was built with -> all derived state goes
    tc = toolchain(lin, home)
    summ["toolchain"] = tc
    old_tc = jload(os.path.join(lin, ".nb/toolchain.json"))
    if old_tc is not None and old_tc != tc:
        log("toolchain changed since this lineage was built: derived state dropped")
        for d in ("build/tree", "build/clang-probe", "build/native"):
            shutil.rmtree(os.path.join(lin, d), ignore_errors=True)
        for f in ("built.json", "mapped.json"):
            if os.path.exists(os.path.join(lin, ".nb", f)):
                os.unlink(os.path.join(lin, ".nb", f))
        summ["toolchain_changed"] = True
    jsave(os.path.join(lin, ".nb/toolchain.json"), tc)

    stages = spec["stages"]
    jobs = str(spec.get("jobs", 4))
    resume, reuse, why = decide(spec, jload(os.path.join(lin, ".nb/built.json")), jload(os.path.join(lin, ".nb/mapped.json")),
                                manifest, lin)
    summ["decision"] = {"resume_state": resume, "reuse_map": reuse, "why": why}
    log("decision: %s" % json.dumps(summ["decision"]))
    ok = True
    if "build" in stages:
        if not resume:
            shutil.rmtree(os.path.join(lin, "build/tree"), ignore_errors=True)
        argv = [py, "tools/build_tree.py", "--jobs", jobs, "--rounds", "16", "--regression-rounds", "4"] + (["--resume"] if resume else [])
        rc, wall = stage("build", argv, env, lin, out)
        summ["wall"]["build"], summ["stages"]["build"] = wall, rc
        if rc == 0 and os.path.exists(os.path.join(lin, "build/tree/report.json")):
            jsave(os.path.join(lin, ".nb/built.json"), manifest)
            shutil.copyfile(os.path.join(lin, "build/tree/state.json"), os.path.join(out, "tree-state.json"))
        else:
            ok = False
    if ok and "probe" in stages:
        argv = [py, "tools/clang_probe.py", "--snapshot", "--configs", "msvc", "--jobs", jobs]
        rc, wall = stage("probe", argv, env, lin, out)
        summ["wall"]["probe"], summ["stages"]["probe"] = wall, rc
        ok = rc == 0
    if ok and "link" in stages:
        exe = os.path.join(lin, "build/native/link/hulk-strict.exe")
        summ["purged_cached_errors"] = purge_cached_errors(os.path.join(env["HULK_WINE_CACHE"], "equiv"))
        if os.path.exists(exe):
            os.unlink(exe)
        argv = [py, "tools/wine_link.py", "--jobs", jobs] + (["--reuse-map"] if reuse else []) + (["--gfx"] if spec.get("gfx") else [])
        rc, wall = stage("link", argv, env, lin, out)
        summ["wall"]["link"], summ["stages"]["link"] = wall, rc
        ok = rc == 0 and os.path.exists(exe)
        rp = os.path.join(lin, "build/native/report.json")
        if os.path.exists(rp):
            shutil.copyfile(rp, os.path.join(out, "link-report.json"))
            lk = (jload(rp, {}).get("link") or {})
            summ["link"] = {"undefined_after": (lk.get("undefined_after") or {}).get("symbols"),
                            "lld_link": json.dumps(lk.get("lld_link"))[:300]}
        if os.path.exists(os.path.join(lin, "build/native/unbound.txt")):
            shutil.copyfile(os.path.join(lin, "build/native/unbound.txt"), os.path.join(out, "unbound.txt"))
        if ok:
            if not reuse:
                jsave(os.path.join(lin, ".nb/mapped.json"), manifest)
            sums = {n: (sha_image if n == "hulk-strict.exe" else sha_file)(image_src(n, lin, inp)) for n in IMAGE_FILES if os.path.exists(image_src(n, lin, inp))}
            summ["image"] = sums
            with open(os.path.join(out, "image.sha256"), "w") as f:
                for n, s in sorted(sums.items()):
                    f.write("%s  %s\n" % (s, n))
            if "image" in spec.get("fetch", []):
                os.makedirs(os.path.join(out, "image"), exist_ok=True)
                for n in IMAGE_FILES:
                    if os.path.exists(image_src(n, lin, inp)):
                        shutil.copyfile(image_src(n, lin, inp), os.path.join(out, "image", n))
                mp = os.path.join(lin, "build/native/link/hulk-strict.map")
                if os.path.exists(mp):
                    shutil.copyfile(mp, os.path.join(out, "image/hulk-strict.map"))
    if not ok:
        finish(4, "a build stage failed (see nb-out/*.log)")
    rpl = spec.get("replay")
    if rpl:
        sys.path.insert(0, os.path.join(lin, "tools"))
        sys.path.insert(0, os.path.join(run, "nbrun"))
        import wine_replay_job
        img = os.path.join(run, "wine-img")
        os.makedirs(img, exist_ok=True)
        for n in IMAGE_FILES:
            if os.path.exists(image_src(n, lin, inp)):
                shutil.copyfile(image_src(n, lin, inp), os.path.join(img, n))
        t = time.time()
        r, ck = wine_replay_job.replay(run, img, os.path.join(run, "nbrun/rec.hrp"), home, rpl.get("timeout", 300),
                                         False, rpl.get("env", {}), rpl.get("frames"), os.path.join(out, "replay"))
        summ["wall"]["replay"] = round(time.time() - t, 1)
        summ["replay"] = r
        for n in ("trace.txt", "ckpt.txt", "result.json"):
            shutil.copyfile(os.path.join(out, "replay", n), os.path.join(out, n))
        shutil.rmtree(os.path.join(out, "replay"), ignore_errors=True)
        if not ck or (rpl.get("frames") and ck[-1][0] < rpl["frames"]):
            finish(5, "the replay reached frame %s, wanted %s" % (ck[-1][0] if ck else None, rpl.get("frames")))
    finish(0)


if __name__ == "__main__":
    main()
