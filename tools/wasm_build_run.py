#!/usr/bin/env python3
"""Host side of tools/wasm_build_job.py: a wasm port build (the headless hulk-aot or the macOS app hulk-app and its
bundle) as one queue job (stdlib only). It runs inside the job's run directory (jobq: a clone of `git archive` of the base
commit plus the submitter's overlay) with the spec in wbrun/spec.json.

What it uses on the host (docs/compute.md "Wasm builds"; `wasm_build_job.py setup` puts them there):
  * WB/tc/<emscripten-V>, WB/tc/<wabt-V>: copies of the submitter's Emscripten (its LLVM, Binaryen and prebuilt system
    libraries; FROZEN_CACHE, so the libraries are the submitter's bytes) and wabt (wasm2c and its runtime sources);
  * WB/inputs-STAMP: the local-only build inputs (build/functions.csv; the app's third-party pieces: SDL3 with video,
    bgfx/bimg/bx and their headers, the Metal shader binaries, mingw-w64's headers, FFmpeg's headers), by content hash;
  * the host's own LLVM (`clang++` on the job's PATH, ~/llvm/bin), the Command Line Tools (/usr/bin/clang, xcrun) and
    its checkout's build/ (venv, the XBE through isos/).
The run directory's `build` (a symlink to the host checkout's build/) becomes a directory of symlinks to it with
third_party and functions.csv taken from the inputs, so the tools' ROOT/build paths find the shipped pieces and
nothing is written into the host's shared build/.

The wasm inputs (snapshot + binding map) are wbrun/wasm-in.tgz (tools/wasm_inputs.py's tarball, unpacked once per host
into WB/winputs/<hash>) or, with spec inputs "make", made in this job (`wasm_inputs.py job`: the run directory's tree,
so tree edits in the overlay count). The build directory is a per-host lineage, WB/ws/LINEAGE/out (one job at a time;
flock): wasm_port's content-keyed front-end IR (out/ir), the aot objects and wasm_app's app-inputs.json stamp survive
between jobs, so a rebuild with the same inputs compiles only what changed. The headless target uses the same stamp
(wasm_app.inputs_stamp): equal stamp and compile.json present skips `wasm_port.py compile`.

Outputs: wb-out/{summary.json, hulk-aot | hulk-app (+ Hulk.app with bundle), hulk.wasm (spec keep_wasm), link.json,
compile-summary.json}. Exit status: 0 done, 3 toolchain or inputs missing on the host, 4 a build step failed.

Metal tests (wqgpu1; metal, metal-input, metal-ab): the app with the real Metal renderer, its window hidden, on the
host's GPU (the queue user is logged in at the console, so a job started over ssh reaches the window server and the
Metal device directly). One Metal run at a time per host: the daemon dispatches at most `gpu_max` (1) `gpu` jobs per
host, and every Metal run also holds ~/hulk-jobs/gpu.lock (the wait is reported). Each role's directory keeps
shots/game-N.png (HULK_GFX_SHOT_GAME), stats.txt (the gfxstats: and `... cost:` lines), stdout.txt and, for replays,
trace.txt.ckref; with a control, shots-diff/ holds |cand - ctl| x4 images and the summary the per-shot differences.
"""
import fcntl
import hashlib
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import tarfile
import time

WB = os.path.expanduser("~/hulk-jobs/wasm")
RUN = os.getcwd()
OUTD = os.path.join(RUN, "wb-out")
PY = sys.executable
KEEP_WINPUTS = 6
KEEP_LINEAGES = 8
WINPUT_LOCKS = []      # (held for the job's life)


def log(msg):
    print("[wb %s] %s" % (time.strftime("%H:%M:%S"), msg), flush=True)


def sha_file(p):
    h = hashlib.sha1()
    with open(p, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def run(argv, env, summ, step):
    t = time.time()
    log("$ " + " ".join(argv))
    r = subprocess.run(argv, cwd=RUN, env=env, stdin=subprocess.DEVNULL)
    summ["steps"][step] = {"rc": r.returncode, "s": round(time.time() - t, 1)}
    write_summary(summ)
    if r.returncode:
        log("%s failed (rc %d)" % (step, r.returncode))
        summ["result"] = "failed: " + step
        write_summary(summ)
        sys.exit(4)


def write_summary(summ):
    os.makedirs(OUTD, exist_ok=True)
    with open(os.path.join(OUTD, "summary.json"), "w") as f:
        json.dump(summ, f, indent=1)


def fail(summ, why, code=3):
    log(why)
    summ["result"] = why
    write_summary(summ)
    sys.exit(code)


def link_build(inputs):
    """RUN/build: a directory of symlinks to the host checkout's build/, third_party and functions.csv from INPUTS."""
    b = os.path.join(RUN, "build")
    if not os.path.islink(b):
        return
    host = os.path.realpath(b)
    os.unlink(b)
    os.makedirs(b)
    own = {"third_party": os.path.join(inputs, "third_party"), "functions.csv": os.path.join(inputs, "functions.csv"),
           "ckpt": os.path.join(inputs, "ckpt"), "rp1": None}
    for n in sorted(os.listdir(host)):
        if n not in own:
            os.symlink(os.path.join(host, n), os.path.join(b, n))
    for n, t in own.items():
        if t and os.path.exists(t):
            os.symlink(t, os.path.join(b, n))
    # the recordings the tests replay travel with the job (wbrun/<name>.hrp, as wine_build_job ships them)
    os.makedirs(os.path.join(b, "rp1"))
    for f in os.listdir(os.path.join(RUN, "wbrun")):
        if f.endswith(".hrp"):
            os.symlink(os.path.join(RUN, "wbrun", f), os.path.join(b, "rp1", f))


def wasm_inputs(spec, summ, env):
    """(snap dir, bindings path) of the build's wasm inputs."""
    if spec["inputs"] == "make":
        run([PY, "tools/wasm_inputs.py", "job", "--commit", spec["commit"], "--jobs", str(spec["jobs"])],
            dict(env, PYTHONHASHSEED="0"), summ, "inputs")
        out = os.path.join(RUN, "wasm-in/out")
        return os.path.join(out, "snap"), os.path.join(out, "bindings.json")
    tgz = os.path.join(RUN, "wbrun/wasm-in.tgz")
    key = sha_file(tgz)[:16]
    d = os.path.join(WB, "winputs", key)
    os.makedirs(os.path.join(WB, "winputs"), exist_ok=True)
    # (rev5) one unpacker at a time; a job holds a shared lock on its inputs while it builds from them, so pruning
    # (below, by another job) never removes a directory in use
    # KEY.lock: shared while a job builds from the directory (pruning takes it exclusively, never waiting);
    # KEY.unpack.lock: one unpacker at a time (rev5: a second job must not wait out the first one's tests)
    lk = open(os.path.join(WB, "winputs", key + ".lock"), "a+")
    fcntl.flock(lk, fcntl.LOCK_SH)
    if not os.path.exists(os.path.join(d, ".complete")):
        ul = open(os.path.join(WB, "winputs", key + ".unpack.lock"), "a+")
        fcntl.flock(ul, fcntl.LOCK_EX)
    else:
        ul = None
    if not os.path.exists(os.path.join(d, ".complete")):
        tmp = d + ".tmp%d" % os.getpid()
        shutil.rmtree(tmp, ignore_errors=True)
        os.makedirs(tmp)
        with tarfile.open(tgz) as t:
            t.extractall(tmp, filter="data")
        shutil.rmtree(d, ignore_errors=True)
        os.replace(os.path.join(tmp, "wasm-inputs"), d)
        shutil.rmtree(tmp, ignore_errors=True)
        open(os.path.join(d, ".complete"), "w").close()
    os.utime(d)
    if ul:
        ul.close()
    WINPUT_LOCKS.append(lk)             # (released once the build is done: the tests do not read the inputs)
    old = sorted((os.path.join(WB, "winputs", n) for n in os.listdir(os.path.join(WB, "winputs"))
                  if ".tmp" not in n and not n.endswith(".lock")), key=os.path.getmtime, reverse=True)
    old = [p for p in old if os.path.basename(p) != key]
    for p in old[KEEP_WINPUTS:]:
        try:
            g = open(p + ".lock", "a+")
            fcntl.flock(g, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError:
            continue        # (in use)
        shutil.rmtree(p, ignore_errors=True)
        g.close()
    summ["wasm_inputs"] = {"tgz": key, "meta": json.load(open(os.path.join(d, "meta.json")))}
    return os.path.join(d, "snap"), os.path.join(d, "bindings.json")


def lock_lineage(name, summ):
    d = os.path.join(WB, "ws", name)
    os.makedirs(d, exist_ok=True)
    f = open(os.path.join(d, ".lock"), "w")
    t = time.time()
    try:
        fcntl.flock(f, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except OSError:
        log("lineage %s is busy: waiting" % name)
        fcntl.flock(f, fcntl.LOCK_EX)
    summ["lineage_wait_s"] = round(time.time() - t, 1)
    os.utime(d)
    # the KEEP_LINEAGES most recently used lineages stay (a busy one is never removed: its lock is held)
    ws = os.path.join(WB, "ws")
    old = sorted((os.path.join(ws, n) for n in os.listdir(ws)), key=os.path.getmtime, reverse=True)
    for p in old[KEEP_LINEAGES:]:
        try:
            g = open(os.path.join(p, ".lock"), "w")
            fcntl.flock(g, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError:
            continue
        shutil.rmtree(p, ignore_errors=True)
        log("removed old lineage %s" % os.path.basename(p))
    return f, d


def prune_ir(env, out):
    """After a full compile: drop front-end IR whose key no TU of the current snapshot has (the cache only grows)."""
    code = ("import sys; sys.path.insert(0, 'tools'); import wasm_port as w\n"
            "print('\\n'.join(w.tu_key(t['path']) for t in w.manifest()))")
    r = subprocess.run([PY, "-c", code], cwd=RUN, env=env, capture_output=True, text=True)
    if r.returncode:
        log("ir prune skipped: %s" % r.stderr[-300:])
        return
    keys = set(r.stdout.split())
    ird = os.path.join(out, "ir")
    n = 0
    for f in os.listdir(ird) if os.path.isdir(ird) else []:
        if f.endswith(".ll") and f.rsplit(".", 2)[-2] not in keys:
            os.remove(os.path.join(ird, f))
            n += 1
    log("ir: removed %d stale front-end files" % n)



# ---------------------------------------------------------------------------------------------- tests
# (wbuild1, lead 11-22) runs of the built (or shipped) executables on this host: play3 replays checked against the
# original's records (build/ckpt/play3.ckref), HULK_ROLLTEST round trips and scripted HULK_INPUT runs with
# HULK_HASH_EVERY; with a control executable each test runs on both and the candidate is compared with the control.
START_SCRIPT = "300-305:10,400-405:0/1,1000-1005:0/1"     # START, then A: through the front end into the game
HASH = re.compile(r"hulk: frame (\d+) game hash (0x[0-9a-f]+)")
COOP_HASH = re.compile(r"hulk: co-op: frame (\d+) state hash ([0-9a-f]+)")


GPU_LOCK = os.path.expanduser("~/hulk-jobs/gpu.lock")
METAL_KINDS = ("metal", "metal-ab", "metal-input")
# a Metal run's defaults (a test's --test-env may change HULK_GFX_STATS; renderer, window and shot paths are the job's)
METAL_ENV = {"HULK_GFX_RENDERER": "metal", "HULK_GFX_HIDDEN": "1", "SDL_MAC_BACKGROUND_APP": "1"}
METAL_DEFAULTS = {"HULK_GFX_STATS": "300"}
COST = re.compile(r"^hulk-app: (.+?) cost: (.*)$")
STATS = re.compile(r"^gfxstats: (\d+) upd \| wall ([0-9.]+) ms/upd.*bgfx cpu ([0-9.]+) gpu ([0-9.]+) wait ([0-9.]+) ms")


class gpu_lock:
    """The host's GPU, one Metal run at a time (beside the daemon's gpu_max): (held, seconds waited)."""
    def __init__(self):
        os.makedirs(os.path.dirname(GPU_LOCK), exist_ok=True)
        self.f = open(GPU_LOCK, "a+")
        t = time.time()
        try:
            fcntl.flock(self.f, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError:
            log("the GPU is busy (another Metal run on this host): waiting")
            fcntl.flock(self.f, fcntl.LOCK_EX)
        self.wait_s = round(time.time() - t, 1)
        self.f.seek(0)
        self.f.truncate()
        self.f.write("%s %d %s\n" % (os.environ.get("JOBQ_JOB"), os.getpid(), time.strftime("%H:%M:%S")))
        self.f.flush()

    def close(self):
        self.f.close()


def host_gpu():
    r = subprocess.run(["sysctl", "-n", "machdep.cpu.brand_string"], capture_output=True, text=True)
    return r.stdout.strip() or None


def metal_env(t, out):
    """The Metal run's environment additions: METAL_DEFAULTS < the test's env < METAL_ENV and the job's paths."""
    os.makedirs(os.path.join(out, "shots"), exist_ok=True)
    env = dict(METAL_DEFAULTS)
    env.update(t.get("env", {}))
    env.update(METAL_ENV)
    env["HULK_GFX_SHOT_DIR"] = os.path.join(out, "shots")
    if t.get("shots"):
        env["HULK_GFX_SHOT_GAME"] = ",".join(str(x) for x in t["shots"])
    else:
        env.pop("HULK_GFX_SHOT_GAME", None)
    return env


def read_tga(p):
    """(header, width, height, BGRA bytes) of an uncompressed 32-bit TGA (bgfx's screenshots), else None."""
    try:
        d = open(p, "rb").read()
    except OSError:
        return None
    if len(d) < 18 or d[2] != 2 or d[16] != 32:
        return None
    w, h = d[12] | d[13] << 8, d[14] | d[15] << 8
    px = d[18 + d[0]:18 + d[0] + w * h * 4]
    return (d[:18 + d[0]], w, h, px) if len(px) == w * h * 4 else None


def tga_diff(a, b, out_tga):
    """Per-channel |a - b| over RGB: {mean, max, share of pixels off by more than 8}; writes the difference x4."""
    A, B = read_tga(a), read_tga(b)
    if not A or not B or A[1:3] != B[1:3]:
        return {"error": "unreadable or different sizes"}
    pa, pb = A[3], B[3]
    if pa == pb:
        return {"identical": True, "mean": 0.0, "max": 0, "px_over_8": 0.0}
    d = bytearray(len(pa))
    tot = mx = over = 0
    for i in range(0, len(pa), 4):
        e0, e1, e2 = abs(pa[i] - pb[i]), abs(pa[i + 1] - pb[i + 1]), abs(pa[i + 2] - pb[i + 2])
        m = max(e0, e1, e2)
        if m:
            tot += e0 + e1 + e2
            mx = max(mx, m)
            over += m > 8
            d[i], d[i + 1], d[i + 2] = min(255, e0 * 4), min(255, e1 * 4), min(255, e2 * 4)
        d[i + 3] = 255
    with open(out_tga, "wb") as f:
        f.write(A[0] + bytes(d))
    n = len(pa) // 4
    return {"identical": False, "mean": round(tot / (3.0 * n), 4), "max": mx, "px_over_8": round(over / float(n), 5)}


def to_png(d):
    """Every .tga in D as .png (sips; the TGA kept only when the conversion fails)."""
    for f in sorted(os.listdir(d)) if os.path.isdir(d) else []:
        if f.endswith(".tga"):
            p = os.path.join(d, f)
            r = subprocess.run(["sips", "-s", "format", "png", p, "--out", p[:-4] + ".png"], capture_output=True)
            if r.returncode == 0 and os.path.exists(p[:-4] + ".png"):
                os.remove(p)


def metal_report(t, out, txt):
    """What a Metal run left: renderer, shots, the gfxstats and A/B cost lines (also written to stats.txt)."""
    lines = txt.splitlines()
    keep = [l for l in lines if l.startswith("gfxstats:") or COST.match(l)]
    with open(os.path.join(out, "stats.txt"), "w") as f:
        f.write("\n".join(keep) + ("\n" if keep else ""))
    got = sorted(int(f[5:-4]) for f in os.listdir(os.path.join(out, "shots")) if re.fullmatch(r"game-\d+\.tga", f))
    want = t.get("shots") or []
    r = {"metal": any("bgfx Metal" in l for l in lines), "shots": got, "shots_missing": [x for x in want if x not in got]}
    st = [STATS.match(l) for l in lines]
    st = [m for m in st if m]
    if st:
        # the mean over the stats windows (each HULK_GFX_STATS updates): wall, bgfx CPU and GPU ms per update
        n = sum(int(m.group(1)) for m in st)
        r["stats"] = {"windows": len(st), "updates": n,
                      "ms_per_upd": {k: round(sum(int(m.group(1)) * float(m.group(i)) for m in st) / n, 3)
                                     for k, i in (("wall", 2), ("bgfx_cpu", 3), ("gpu", 4), ("wait", 5))}}
    costs = {}
    for l in lines:
        m = COST.match(l)
        if m:
            costs[m.group(1)] = m.group(2)        # (the last report of each pass: the longest average)
    if costs:
        r["ab"] = costs
    return r


def fresh(d):
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(d)
    return d


def exe_env(exe, out, extra):
    """The image's environment for a run in OUT: private save / title / user data and app dirs, no UI, the null
    renderer for the app unless the test names one."""
    data = os.path.join(RUN, "isos/extracted")
    env = dict(os.environ, HULK_DATA_DIR=data, HULK_SAVE_DIR=fresh(os.path.join(out, "save")),
               HULK_TDATA_DIR=fresh(os.path.join(out, "tdata")), HULK_UDATA_DIR=fresh(os.path.join(out, "udata")),
               HULK_APP_DIR=fresh(os.path.join(out, "appdir")), HULK_NO_UI="1", SDL_AUDIO_DRIVER="dummy")
    if os.path.basename(exe) == "hulk-app":
        env["HULK_GFX_RENDERER"] = "null"
    env.update(extra)
    return env


def free_run(exe, out, extra, timeout):
    """One run without a recording: (exit code or 'timeout', stdout text)."""
    env = exe_env(exe, out, extra)
    t0 = time.time()
    with open(os.path.join(out, "stdout.txt"), "wb") as so:
        p = subprocess.Popen([exe, os.path.join(RUN, "isos/extracted/default.xbe")], cwd=out, env=env, stdout=so,
                             stderr=subprocess.STDOUT, start_new_session=True)
        try:
            rc = p.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            os.killpg(p.pid, 9)
            p.wait()
            rc = "timeout"
    return rc, open(os.path.join(out, "stdout.txt"), errors="replace").read(), round(time.time() - t0, 1)


def ckref_check(run, ref, out_json, frames=None, control=None):
    argv = [PY, "tools/native_replay.py", "check", run, "--ref", ref, "--json", out_json]
    if frames:
        argv += ["--frames", str(frames)]
    if control:
        argv += ["--control", control]
    r = subprocess.run(argv, cwd=RUN, capture_output=True, text=True)
    rep = {}
    if os.path.exists(out_json):
        rep = json.load(open(out_json))
    return r.returncode, r.stdout, rep


def first_line(rep):
    f = rep.get("first")
    tags = {t: d.get("first") for t, d in (rep.get("tags") or {}).items() if d.get("first") is not None}
    return ("first divergence frame %d tag %s" % (f["frame"], f["tag"]) if f else "no divergence") + \
        ("; per tag: " + ", ".join("%s@%s" % kv for kv in sorted(tags.items(), key=lambda kv: kv[1])) if tags else "")


def test_play3(t, exes, base):
    res = {}
    ref = os.path.join(RUN, "build/ckpt/play3.ckref")
    if t.get("rec"):        # (wplay4) a playthrough: its recording and our own records travel in wbrun/
        ref = os.path.join(RUN, "wbrun", t["rec"] + ".self.ckref")
    metal = t["kind"] in METAL_KINDS
    for role, exe in exes.items():
        # every role runs in the same directory (moved to ROLE afterwards): the save / data paths are game state
        out = fresh(os.path.join(base, "run"))
        argv = [PY, "tools/native_replay.py", "run", "--exe", exe, "--out", out, "--frames", str(t["frames"]),
                "--timeout", str(t.get("timeout", 3600)), "--no-check"]
        if t.get("rec"):
            argv += ["--rec", os.path.join(RUN, "wbrun", t["rec"] + ".hrp")]
            if os.path.isdir(os.path.join(RUN, "wbrun", t["rec"] + ".seed")):
                argv += ["--save-seed", os.path.join(RUN, "wbrun", t["rec"] + ".seed")]
        extra = dict(t.get("env", {}), HULK_APP_DIR=fresh(os.path.join(out, "appdir")), HULK_NO_UI="1")
        if metal:
            extra.update(metal_env(t, out))
        elif os.path.basename(exe) == "hulk-app" and "HULK_GFX_RENDERER" not in t.get("env", {}):
            extra["HULK_GFX_RENDERER"] = "null"
        for k, v in extra.items():
            argv += ["--env", "%s=%s" % (k, v)]
        argv += ["--", os.path.join(RUN, "isos/extracted/default.xbe")]
        gl = gpu_lock() if metal else None
        load0 = os.getloadavg()[0]
        t0 = time.time()
        r = subprocess.run(argv, cwd=RUN, capture_output=True, text=True)
        wall = round(time.time() - t0, 1)
        load1 = os.getloadavg()[0]
        if gl:
            gl.close()
        rec = os.path.join(out, "trace.txt.ckref")
        rc, txt, rep = ckref_check(rec, ref, os.path.join(out, "check.json"), t["frames"])
        info = {}
        try:
            info = json.load(open(os.path.join(out, "result.json")))
        except (OSError, ValueError):
            pass
        # the image stops a little after the target frame: records past it are reported, never judged
        first = rep.get("first")
        lacks = (rep.get("frames") or {}).get("lacks")
        ok = rc == 0 or bool(first and first["frame"] > t["frames"] and not lacks)
        res[role] = {"ok": ok, "run": (r.stdout.strip().split("\n")[0] or r.stderr.strip()[-300:])[:300], "wall_s": wall,
                     "last_frame": info.get("last_frame"), "vs_reference": first_line(rep)}
        if metal:
            # a Metal run is judged by what it ran (the Metal device, the target frame, every shot), not by the
            # reference: play3 alone shows the known camera transient from ~5,875 (CLAUDE.md wbuild1)
            so = open(os.path.join(out, "stdout.txt"), errors="replace").read() if os.path.exists(
                os.path.join(out, "stdout.txt")) else ""
            m = metal_report(t, out, so)
            m.update(gpu_wait_s=gl.wait_s, load=[round(load0, 2), round(load1, 2)])
            res[role].update(m)
            res[role]["ok"] = bool(m["metal"] and (info.get("last_frame") or -1) >= t["frames"]
                                   and not m["shots_missing"] and (t["kind"] != "metal-ab" or "ab" in m))
        # the records stay in wb-out; the full trace is big: keep its last lines
        tr = os.path.join(out, "trace.txt")
        if os.path.exists(tr) and os.path.getsize(tr) > (4 << 20):
            with open(tr, "rb") as f:
                f.seek(-(256 << 10), 2)
                tail = f.read()
            with open(tr + ".tail", "wb") as f:
                f.write(tail)
            os.remove(tr)
        os.rename(out, os.path.join(base, role))
    if "ctl" in exes and metal:
        same = filecmp_prefix(os.path.join(base, "cand/trace.txt.ckref"), os.path.join(base, "ctl/trace.txt.ckref"))
        res["compare"] = dict(compare_shots(base), records_identical=same,
                              ok=bool(res["cand"]["ok"] and res["ctl"]["ok"]))
    elif "ctl" in exes:
        rc, txt, rep = ckref_check(os.path.join(base, "cand/trace.txt.ckref"), os.path.join(base, "ctl/trace.txt.ckref"),
                                   os.path.join(base, "cand-vs-ctl.json"))
        same = filecmp_prefix(os.path.join(base, "cand/trace.txt.ckref"), os.path.join(base, "ctl/trace.txt.ckref"))
        _, _, gate = ckref_check(os.path.join(base, "cand/trace.txt.ckref"), ref, os.path.join(base, "gate.json"),
                                 t["frames"], control=os.path.join(base, "ctl/trace.txt.ckref"))
        # (rev5) both runs must reach the target frame: a candidate that crashed early compares a short prefix
        reached = all((res[r_].get("last_frame") or -1) >= t["frames"] for r_ in ("cand", "ctl"))
        res["compare"] = {"ok": rc == 0 and bool(gate.get("ok")) and reached, "reached": reached,
                          "records_identical": same,
                          "vs_control": first_line(rep), "gate": (gate.get("gate") or {}).get("new_count")}
    return res


def compare_shots(base):
    """cand's shots against ctl's (the same game frames): {frame: difference} and base/shots-diff/diff-N.tga."""
    dd = fresh(os.path.join(base, "shots-diff"))
    a, b = os.path.join(base, "cand/shots"), os.path.join(base, "ctl/shots")
    common = sorted(set(os.listdir(a)) & set(os.listdir(b))) if os.path.isdir(a) and os.path.isdir(b) else []
    per = {}
    for f in common:
        if re.fullmatch(r"game-\d+\.tga", f):
            d = tga_diff(os.path.join(a, f), os.path.join(b, f), os.path.join(dd, "diff-" + f[5:]))
            per[f[5:-4]] = d
    return {"shots_compared": len(per), "shots_identical": sum(1 for d in per.values() if d.get("identical")),
            "shots": per}


def filecmp_prefix(a, b):
    """Records byte-identical over the shorter run (a replay stops once its target frame is in the trace)."""
    try:
        x, y = open(a, "rb").read(), open(b, "rb").read()
    except OSError:
        return None
    n = min(len(x), len(y))
    return x[:n] == y[:n] if n else None


def test_free(t, exes, base):
    res = {}
    hashes = {}
    for role, exe in exes.items():
        out = fresh(os.path.join(base, "run"))      # (the same paths for every role: they are game state)
        extra = {"HULK_INPUT": START_SCRIPT}
        if t["kind"] == "rolltest":
            extra["HULK_ROLLTEST"] = "%d:%d" % (t["a"], t["b"])
        else:
            extra.update({"HULK_FRAMES": str(t["frames"]), "HULK_HASH_EVERY": str(t.get("every", 10))})
        extra.update(t.get("env", {}))
        metal = t["kind"] in METAL_KINDS
        if metal:
            extra.update(metal_env(t, out))
        gl = gpu_lock() if metal else None
        load0 = os.getloadavg()[0]
        rc, txt, wall = free_run(exe, out, extra, t.get("timeout", 3600))
        load1 = os.getloadavg()[0]
        if gl:
            gl.close()
        r = {"rc": rc, "wall_s": wall}
        if t["kind"] == "rolltest":
            lines = [l for l in txt.splitlines() if l.startswith("rolltest:")]
            r["ok"] = rc == 0 and any("identical" in l for l in lines)
            r["lines"] = lines[-3:]
        else:
            h = [(int(m.group(1)), m.group(2)) for m in HASH.finditer(txt)]
            hashes[role] = h
            with open(os.path.join(out, "hashes.txt"), "w") as f:
                f.write("".join("%d %s\n" % x for x in h))
            # (rev5) a run that crashed, timed out or stopped short of its frames is not ok, whatever its hashes say
            every = t.get("every", 10)
            r["ok"] = rc == 0 and bool(h) and h[-1][0] >= t["frames"] - every
            r["hashes"] = len(h)
            r["last"] = h[-1] if h else None
            if metal:
                m = metal_report(t, out, txt)
                m.update(gpu_wait_s=gl.wait_s, load=[round(load0, 2), round(load1, 2)])
                r.update(m)
                r["ok"] = bool(r["ok"] and m["metal"] and not m["shots_missing"])
        res[role] = r
        os.rename(out, os.path.join(base, role))
    if "ctl" in exes and t["kind"] != "rolltest":
        a, b = dict(hashes.get("cand", [])), dict(hashes.get("ctl", []))
        common = sorted(set(a) & set(b))
        diff = [f for f in common if a[f] != b[f]]
        reached = bool(common) and common[-1] >= t["frames"] - t.get("every", 10)
        res["compare"] = {"ok": reached and not diff and res["cand"]["ok"] and res["ctl"]["ok"],
                          "common": len(common), "last_common": common[-1] if common else None,
                          "first_differing_frame": diff[0] if diff else None}
        if t["kind"] in METAL_KINDS:
            # (a before/after pair: the images may differ on purpose, the game state may not: with Metal the game
            # hash holds pddi front-end pointers into the host heap, so hashes are reported, never judged)
            res["compare"].update(compare_shots(base), ok=bool(res["cand"]["ok"] and res["ctl"]["ok"]),
                                  hashes_note="Metal game hashes include host heap pointers (waud1)")
    return res


def test_coop(t, exes, base, spec):
    """(wnet1) coop:FRAMES[:PEERS[:SECOND_JOIN_S]]: the candidate as a co-op host (HULK_INPUT's START_SCRIPT into the
    game; dev_coop_local=PEERS Hulks, wcoop1) and 1-2 guests, each with a scripted pad of its own, that join it mid-game through net/worker/test/local_server.mjs on loopback, every one with the
    null renderer and HULK_FRAMES=FRAMES, game hashes every 300 frames. Ok: every run reaches FRAMES, the guests
    joined, no DESYNC, and every game hash a guest prints after its join equals the host's at that frame. --test-env
    goes to every peer; HULK_COOP_SHIM etc. through it too."""
    res = {}
    exe = exes["cand"]
    node = None
    for d in sorted(glob.glob(os.path.join(WB, "tc", "node-*", "bin", "node"))):
        node = d
    if not node:
        return {"cand": {"ok": False, "why": "no node on this host (wasm_build_job.py setup)"}}
    port = 20000 + os.getpid() % 20000
    srv_log = open(os.path.join(base, "server.log"), "w")
    srv = subprocess.Popen([node, os.path.join(os.path.dirname(os.path.abspath(__file__)), "net/worker/test/local_server.mjs"), "--port", str(port), "--log"],
                           stdout=srv_log, stderr=subprocess.STDOUT, start_new_session=True)
    time.sleep(1.5)
    code = os.path.join(base, "code.txt")
    every = 300
    procs = {}
    try:
        for k in range(t["peers"]):
            role = "host" if k == 0 else "guest%d" % k
            out = fresh(os.path.join(base, role))
            extra = {"HULK_FRAMES": str(t["frames"]), "HULK_HASH_EVERY": str(every), "HULK_INPUT": START_SCRIPT,
                     "HULK_NET_WORKER": "http://127.0.0.1:%d" % port, "HULK_COOP_TMP": fresh(os.path.join(out, "tmp")),
                     "HULK_COOP_LOG": "2"}
            if k == 0:
                # (the app's front end needs a second START and A to reach the game: GS_GAME at ~1,300; the extra
                # Hulks spawn ~250 frames later)
                extra.update(HULK_COOP_HOST="1", HULK_COOP_CODE_FILE=code,
                             HULK_INPUT=START_SCRIPT + ",1300-1305:10,1500-1505:0/1,1800-1805:0/1",
                             HULK_SETTINGS="developer=1,dev_coop_local=%d" % t["peers"])
            else:
                # each guest's own pad (its pad 0 locally, its Hulk's in the session): guest 1 runs with the left
                # stick, guest 2 taps A and turns; frames are the host's once it has joined
                extra.update(HULK_COOP_JOIN="@" + code, HULK_INPUT=START_SCRIPT + (
                    ",4000-7000:0/0/0/30000,8000-8010:0/1,8020-12000:0/0/-20000/25000" if k == 1 else
                    ",5000-5010:0/1,6000-9000:0/0/25000/-10000,11000-11010:0/1"))
            extra.update(t.get("env", {}))
            env = exe_env(exe, out, extra)
            so = open(os.path.join(out, "stdout.txt"), "wb")
            procs[role] = (subprocess.Popen([exe, os.path.join(RUN, "isos/extracted/default.xbe")], cwd=out, env=env,
                                            stdout=so, stderr=subprocess.STDOUT, start_new_session=True), out)
            time.sleep(3 if k == 0 else t["second"])
        deadline = time.time() + t.get("timeout", 3600)
        for role, (p, out) in procs.items():
            try:
                rc = p.wait(timeout=max(1, deadline - time.time()))
            except subprocess.TimeoutExpired:
                os.killpg(p.pid, 9)
                p.wait()
                rc = "timeout"
            txt = open(os.path.join(out, "stdout.txt"), errors="replace").read()
            # (the session's own state hashes: the game hash lines are taken in the frame end before the set's pads
            # are put back, so they hold each peer's own pad)
            h = {int(m.group(1)): m.group(2) for m in COOP_HASH.finditer(txt)}
            co = [l for l in txt.splitlines() if ("co-op:" in l or "coop:" in l) and "agrees" not in l
                  and "state hash" not in l and "ICE " not in l and "selected" not in l]
            joined = re.search(r"in the host's game from frame (\d+)", txt)
            ev = [l.split(": ", 2)[-1] for l in txt.splitlines() if l.startswith("hulk: coop: frame")]
            res[role] = {"rc": rc, "hashes": len(h), "last": max(h) if h else None, "coop": co[-12:], "_ev": ev,
                         "desync": "DESYNC" in txt, "joined_frame": int(joined.group(1)) if joined else None,
                         "_h": h}
    finally:
        try:
            srv.kill()
        except OSError:
            pass
        srv.wait()
        srv_log.close()
    host = res.get("host", {}).get("_h", {})
    ok = all(r.get("rc") == 0 for r in res.values())
    for role, r in res.items():
        if role == "host":
            continue
        gh = r.pop("_h")
        common = sorted(f for f in gh if f in host)
        diff = [f for f in common if gh[f] != host[f]]
        # the game side's events (spawns, leashes, downs: wcoop1's log) after the join, the same on every peer
        hev, gev = res["host"]["_ev"], r.pop("_ev")
        jf = r["joined_frame"] or 0
        fr = lambda l: int(l.split(":")[0].split()[-1]) if l.split(":")[0].split()[-1].isdigit() else -1
        hev2 = [l for l in hev if fr(l) >= jf]
        gev2 = [l for l in gev if fr(l) >= jf]
        r["game_events"] = {"host": len(hev2), "same": hev2 == gev2, "sample": gev2[:4]}
        r.update(compared=len(common), first=common[0] if common else None, last=common[-1] if common else None,
                 differing=diff[:5])
        ok = ok and len(common) >= 10 and not diff and not r["desync"] and r["joined_frame"] is not None
    res.get("host", {}).pop("_h", None)
    res.get("host", {}).pop("_ev", None)
    res["server"] = [l for l in open(os.path.join(base, "server.log"), errors="replace").read().splitlines()
                     if " 2" not in l[25:40]][-12:]
    res["ok"] = ok
    return {"cand": res}


def run_tests(spec, exes, summ):
    out = os.path.join(OUTD, "tests")
    summ["tests"] = {}
    ok = True
    for t in spec.get("tests", []):
        t0 = time.time()
        base = fresh(os.path.join(out, t["name"]))
        log("test %s (%s) on %s" % (t["name"], t["kind"], ", ".join("%s=%s" % kv for kv in exes.items())))
        r = test_play3(t, exes, base) if t["kind"] in ("play3", "metal", "metal-ab") else \
            test_coop(t, exes, base, spec) if t["kind"] == "coop" else test_free(t, exes, base)
        if t["kind"] in METAL_KINDS:
            for d in [os.path.join(base, role, "shots") for role in exes] + [os.path.join(base, "shots-diff")]:
                to_png(d)
            r["host_cpu"] = host_gpu()
        r["wall_s"] = round(time.time() - t0, 1)
        # with a control the verdict is the comparison (ckpt_gate's: the candidate may add no divergence the control
        # does not have; the roles' own checks against the reference are reported); a rolltest judges both runs
        r["ok"] = r["compare"]["ok"] if "compare" in r else all(
            v.get("ok") for k, v in r.items() if isinstance(v, dict))
        ok = ok and r["ok"]
        summ["tests"][t["name"]] = r
        write_summary(summ)
        log("test %s: %s %s" % (t["name"], "ok" if r["ok"] else "FAILED", json.dumps(r)[:600]))
    return ok


def build(spec, summ, inputs):
    """The build in the lineage directory: the executable's path in OUTD."""
    tc = {k: os.path.join(WB, "tc", v) for k, v in spec["toolchain"].items()}
    for k, d in tc.items():
        if not os.path.exists(os.path.join(d, ".complete")):
            fail(summ, "toolchain %s missing on this host (%s): tools/wasm_build_job.py setup --host H" % (k, d))
    llvm = os.path.dirname(shutil.which("clang++") or "")
    if not llvm:
        fail(summ, "no clang++ (LLVM) on the job's PATH")
    env = dict(os.environ)
    env.update({"HULK_LLVM_BIN": llvm, "HULK_EMCC": os.path.join(tc["emscripten"], "libexec/emcc"),
                "EMSDK_PYTHON": PY, "HULK_WASM2C": os.path.join(tc["wabt"], "bin/wasm2c"),
                # (emcc's link runs its JS compiler for the symbol lists; EM_* overrides the copy's config)
                "EM_NODE_JS": os.path.join(tc["node"], "bin/node"),
                "HULK_CC": "/usr/bin/clang", "BINARYEN_CORES": str(spec["jobs"]),
                "MACOSX_DEPLOYMENT_TARGET": spec["macos_min"], "HULK_FFMPEG_PREFIX": os.path.join(inputs, "ffmpeg"),
                "HULK_FFMPEG_LIBDIR": spec["ffmpeg_libdir"]})
    for k in ("HULK_WASM_SNAP", "HULK_WASM_BINDINGS", "HULK_WASM_DIR", "HULK_APP_SDL", "HULK_WASM_GFX"):
        env.pop(k, None)
    env.update(spec["env"])
    # the build's id (wver1; tools/wasm_app.py build_id): the job's commit, "+N" for N overlay files and deletions
    n = int(spec.get("overlay") or 0) + len(spec.get("deletions") or [])
    env.setdefault("HULK_BUILD_ID", spec["commit"][:7] + ("+%d" % n if n else ""))
    summ["build_id"] = env["HULK_BUILD_ID"]
    snap, bind = wasm_inputs(spec, summ, env)
    env["HULK_WASM_SNAP"], env["HULK_WASM_BINDINGS"] = snap, bind
    lock, lin = lock_lineage(spec["lineage"], summ)
    out = os.path.join(lin, "out")
    env["HULK_WASM_DIR"] = out
    os.makedirs(out, exist_ok=True)
    summ["toolchain"] = {"llvm": subprocess.run([os.path.join(llvm, "clang"), "--version"], capture_output=True,
                                                text=True).stdout.split("\n")[0],
                         "cc": subprocess.run(["/usr/bin/clang", "--version"], capture_output=True,
                                              text=True).stdout.split("\n")[0], **spec["toolchain"]}
    j = str(spec["jobs"])
    sys.path.insert(0, os.path.join(RUN, "tools"))
    import wasm_app
    if spec["target"] == "app":
        env["HULK_WASM_GFX"] = "1"
        stamp = wasm_app.inputs_stamp(env)
        try:
            old = json.load(open(os.path.join(out, wasm_app.STAMP)))
        except (OSError, ValueError):
            old = None
        summ["compile"] = "hooked TUs only (inputs unchanged)" if old == stamp and os.path.exists(
            os.path.join(out, "compile.json")) else "every TU"
        run([PY, "tools/wasm_app.py", "build", "--jobs", j], env, summ, "build")
        exe = os.path.join(out, "hulk-app")
    else:
        stamp = wasm_app.inputs_stamp(env)
        sp = os.path.join(out, wasm_app.STAMP)
        try:
            old = json.load(open(sp))
        except (OSError, ValueError):
            old = None
        if old == stamp and os.path.exists(os.path.join(out, "compile.json")):
            summ["compile"] = "skipped (inputs unchanged)"
        else:
            summ["compile"] = "every TU"
            if os.path.exists(sp):
                os.remove(sp)
            run([PY, "tools/wasm_port.py", "compile", "--jobs", j], env, summ, "compile")
            rep = json.load(open(os.path.join(out, "compile.json")))
            if rep.get("failed"):
                fail(summ, "%d TUs failed to compile (first: %s)" % (
                    len(rep["failed"]), str(next(iter(rep["failed"].items())))[:300]), 4)
            with open(sp, "w") as f:
                json.dump(stamp, f, indent=1)
        run([PY, "tools/wasm_port.py", "link"], env, summ, "link")
        run([PY, "tools/wasm_port.py", "aot", "--jobs", j], env, summ, "aot")
        exe = os.path.join(out, "hulk-aot")
    if summ["compile"] == "every TU":
        prune_ir(env, out)
    os.makedirs(OUTD, exist_ok=True)
    dst = os.path.join(OUTD, os.path.basename(exe))
    shutil.copy2(exe, dst)
    summ["exe_sha1"] = sha_file(exe)
    for f in ("link.json",):
        if os.path.exists(os.path.join(out, f)):
            shutil.copy2(os.path.join(out, f), os.path.join(OUTD, f))
    if spec.get("keep_wasm"):
        shutil.copy2(os.path.join(out, "hulk.wasm"), os.path.join(OUTD, "hulk.wasm"))
    rep = json.load(open(os.path.join(out, "compile.json")))
    with open(os.path.join(OUTD, "compile-summary.json"), "w") as f:
        json.dump({k: rep.get(k) for k in ("tus", "compiled", "functions", "failed")}, f, indent=1)
    if spec["target"] == "app" and spec.get("bundle"):
        app = os.path.join(RUN, "build", "wb-bundle", "Hulk.app")
        run([PY, "tools/wasm_app.py", "bundle", "--exe", exe, "--out", app], env, summ, "bundle")
        shutil.move(app, os.path.join(OUTD, "Hulk.app"))
    lock.close()            # (the tests run on the copy in OUTD: the lineage is free for the next build)
    return dst


def on_term(sig, _frame):
    """(wqgpu1) A cancelled or timed-out job gets SIGTERM on its process group, but the images run in sessions of
    their own (free_run, native_replay.py run): kill every process started from this run directory first, or an app
    outlives its job (and keeps the host's GPU; an orphan of a cancelled job ran 17 h on mac2, 11-23)."""
    subprocess.run(["pkill", "-9", "-f", RUN + "/"], capture_output=True)
    log("signal %d: the run's images killed" % sig)
    sys.exit(128 + sig)


def main():
    import signal
    signal.signal(signal.SIGTERM, on_term)
    signal.signal(signal.SIGHUP, on_term)
    t0 = time.time()
    spec = json.load(open(os.path.join(RUN, "wbrun/spec.json")))
    summ = {"host": os.environ.get("JOBQ_HOST"), "job": os.environ.get("JOBQ_JOB"), "commit": spec["commit"],
            "target": spec["target"], "lineage": spec.get("lineage"), "steps": {}, "result": "running"}
    write_summary(summ)
    inputs = os.path.join(WB, "inputs-" + spec["inputs_stamp"])
    if not os.path.exists(os.path.join(inputs, ".complete")):
        fail(summ, "inputs %s missing on this host" % spec["inputs_stamp"])
    os.utime(inputs)
    for rel in spec.get("deletions", []):         # (--workspace: files HEAD has and the workspace lacks)
        p = os.path.normpath(os.path.join(RUN, rel))
        if p.startswith(RUN + os.sep) and os.path.isfile(p) and not os.path.islink(p):
            os.remove(p)
    link_build(inputs)
    exes = {role: os.path.join(RUN, p) for role, p in (spec.get("exes") or {}).items()}
    for p in exes.values():
        os.chmod(p, 0o755)
    if spec["target"] != "none":
        exes["cand"] = build(spec, summ, inputs)
        summ["build_wall_s"] = round(time.time() - t0, 1)
        for f in WINPUT_LOCKS:
            f.close()
    ok = True
    if spec.get("tests"):
        try:        # one image at a time from here: give the other slots back (jobq_run.py probe reads .jq-slots)
            with open(os.path.join(os.environ.get("JOBQ_RUN_DIR") or RUN, ".jq-slots"), "w") as f:
                f.write("1\n")
        except OSError as e:
            log("could not release slots: %s" % e)
        ok = run_tests(spec, exes, summ)
    summ["wall_s"] = round(time.time() - t0, 1)
    summ["result"] = "ok" if ok else "tests failed"
    write_summary(summ)
    log("done in %.0f s: %s" % (summ["wall_s"], summ["result"]))
    if not ok:
        sys.exit(5)


if __name__ == "__main__":
    main()
