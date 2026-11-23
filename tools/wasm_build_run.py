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
"""
import fcntl
import hashlib
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
    lk = open(os.path.join(WB, "winputs", key + ".lock"), "a+")
    fcntl.flock(lk, fcntl.LOCK_SH)
    if not os.path.exists(os.path.join(d, ".complete")):
        fcntl.flock(lk, fcntl.LOCK_UN)
        fcntl.flock(lk, fcntl.LOCK_EX)      # (only unpackers and brief checkers hold it while it is incomplete)
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
    fcntl.flock(lk, fcntl.LOCK_SH)      # (downgrade: others may read, nobody may remove)
    WINPUT_LOCKS.append(lk)
    old = sorted((os.path.join(WB, "winputs", n) for n in os.listdir(os.path.join(WB, "winputs"))
                  if ".tmp" not in n and not n.endswith(".lock")), key=os.path.getmtime, reverse=True)
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
    for role, exe in exes.items():
        # every role runs in the same directory (moved to ROLE afterwards): the save / data paths are game state
        out = fresh(os.path.join(base, "run"))
        argv = [PY, "tools/native_replay.py", "run", "--exe", exe, "--out", out, "--frames", str(t["frames"]),
                "--timeout", str(t.get("timeout", 3600)), "--no-check"]
        extra = dict(t.get("env", {}), HULK_APP_DIR=fresh(os.path.join(out, "appdir")), HULK_NO_UI="1")
        if os.path.basename(exe) == "hulk-app" and "HULK_GFX_RENDERER" not in t.get("env", {}):
            extra["HULK_GFX_RENDERER"] = "null"
        for k, v in extra.items():
            argv += ["--env", "%s=%s" % (k, v)]
        argv += ["--", os.path.join(RUN, "isos/extracted/default.xbe")]
        t0 = time.time()
        r = subprocess.run(argv, cwd=RUN, capture_output=True, text=True)
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
        res[role] = {"ok": ok, "run": r.stdout.strip().split("\n")[0][:300], "wall_s": round(time.time() - t0, 1),
                     "last_frame": info.get("last_frame"), "vs_reference": first_line(rep)}
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
    if "ctl" in exes:
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
        rc, txt, wall = free_run(exe, out, extra, t.get("timeout", 3600))
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
    return res


def run_tests(spec, exes, summ):
    out = os.path.join(OUTD, "tests")
    summ["tests"] = {}
    ok = True
    for t in spec.get("tests", []):
        t0 = time.time()
        base = fresh(os.path.join(out, t["name"]))
        log("test %s (%s) on %s" % (t["name"], t["kind"], ", ".join("%s=%s" % kv for kv in exes.items())))
        r = test_play3(t, exes, base) if t["kind"] == "play3" else test_free(t, exes, base)
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


def main():
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
