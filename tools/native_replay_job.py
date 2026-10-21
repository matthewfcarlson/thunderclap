#!/usr/bin/env python3
"""Native (Wine) replays as jobs of the shared queue (tools/jobq.py, docs/compute.md "Native replays").

  # submit: ships the image + DLLs + recording with the job (content-hashed by jobq), prints the job id
  build/venv/bin/python tools/native_replay_job.py submit --name ME [--img DIR] [--rec build/rp1/play3.hrp]
        [--timeout 200] [--gfx] [--host mac2] [--env K=V ...] [--tag T]
  # wait for a job and print its checkpoint summary (frames reached, wall clock, hashes file)
  build/venv/bin/python tools/native_replay_job.py wait ID [--out-dir DIR]
  # compare the checkpoint hashes of several jobs (or ckpt files): common frames must be identical
  build/venv/bin/python tools/native_replay_job.py compare ID|FILE ID|FILE ...
  # (run: what the job itself executes on the host)

--img DIR holds the linked image and its DLLs (hulk-strict.exe, SDL3.dll, hulkmovie.dll, avutil/avcodec/avformat); the
default is build/native/link (tools/native_link.py's output; the DLLs are copied there by native_run.py). The game data
comes from the host's own isos/extracted (HULK_DATA_DIR = $JOBQ_HOME/isos/extracted): it is never shipped with a job and
must have been put there by the player (rsync of the laptop's isos/extracted to ~/hulk-permute/isos/extracted).

Headless by default: HULK_GFX_RENDERER=noop (bgfx's null renderer; checkpoint hashes are game state, not pixels) and
`--needs wine`. `--gfx` keeps the Vulkan renderer (MoltenVK) and needs `wine-gfx` (a host with a window session).
Each job gets a private clone of a template Wine prefix (~/hulk-jobs/wine-template, made once per host), so concurrent
jobs do not share a wineserver. Lockstep I/O (HULK_SYNCIO=5, the default when a recording is open) makes the run
deterministic; HULK_CKPT=1 HULK_CKPT_ALL=1 write a checkpoint hash for every frame.
Outputs (under build/jobs/out/ID/wine-out/ (under $JOBQ_DIR when set)): trace.txt, ckpt.txt (`frame hash` lines), result.json.
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
DLLS = ["hulk-strict.exe", "SDL3.dll", "hulkmovie.dll", "avutil-60.dll", "avcodec-62.dll", "avformat-62.dll"]
CKPT = re.compile(r"ckpt frame (\d+) hash ([0-9a-f]+)")
PY = os.path.join(ROOT, "build/venv/bin/python")
JOBQ = os.path.join(ROOT, "tools/jobq.py")
JOBS = os.environ.get("JOBQ_DIR") or os.path.join(ROOT, "build/jobs")
DEFAULT_ENV = {"HULK_CKPT": "1", "HULK_CKPT_ALL": "1", "HULK_AUDIO_CLOCK": "frame", "HULK_CKPT_REGIONS": "0"}


def wpath(p):
    return "Z:" + os.path.abspath(p).replace("/", "\\")


def cmd_submit(a):
    img = os.path.abspath(a.img)
    for f in DLLS:
        if not os.path.exists(os.path.join(img, f)):
            sys.exit("missing %s in %s" % (f, img))
    if not os.path.exists(a.rec):
        sys.exit("no recording " + a.rec)
    files = ["%s=wine-img/%s" % (os.path.join(img, f), f) for f in DLLS] + ["%s=wine-img/rec.hrp" % os.path.abspath(a.rec)]
    argv = [PY, JOBQ, "submit", "--name", a.name, "--needs", "wine-gfx" if a.gfx else "wine", "--limit", str(a.timeout + 240),
            "--attempts", "2", "--out", "wine-out", "--files"] + files + [
        "tools/native_replay_job.py", "tools/native_run.py"]     # until they are in the committed base tree
    if a.host:
        argv += ["--host", a.host]
    argv += ["--", "python", "tools/native_replay_job.py", "run", "--timeout", str(a.timeout)]
    if a.gfx:
        argv.append("--gfx")
    for e in a.env or []:
        argv += ["--env", e]
    r = subprocess.run(argv, capture_output=True, text=True)
    if r.returncode:
        sys.exit(r.stderr or r.stdout)
    print(r.stdout.strip())


def ckpt_file(x):
    if os.path.isfile(x):
        return x
    p = os.path.join(JOBS, "out", str(x), "wine-out/ckpt.txt")
    if not os.path.exists(p):
        sys.exit("no ckpt.txt for " + x)
    return p


def load_ckpt(x):
    d = {}
    for l in open(ckpt_file(x)):
        f, h = l.split()
        d[int(f)] = h
    return d


def cmd_wait(a):
    r = subprocess.run([PY, JOBQ, "wait", a.id])
    out = os.path.join(JOBS, "out", a.id, "wine-out", "result.json")
    if os.path.exists(out):
        print(open(out).read())
    return r.returncode


def cmd_compare(a):
    runs = [(x, load_ckpt(x)) for x in a.items]
    common = sorted(set.intersection(*[set(d) for _, d in runs]))
    bad = [f for f in common if len({d[f] for _, d in runs}) > 1]
    for x, d in runs:
        print("%s: %d checkpoints, last frame %d" % (x, len(d), max(d) if d else -1))
    print("common frames: %d (0..%d); differing: %d%s" % (len(common), common[-1] if common else -1, len(bad),
                                                          " first at %d" % bad[0] if bad else ""))
    return 1 if bad or not common else 0


def ensure_template(wine):
    """A once-per-host Wine prefix, cloned (APFS) for every job."""
    import native_run
    tpl = os.path.expanduser("~/hulk-jobs/wine-template")
    done = tpl + "/.done"
    if os.path.exists(done):
        return tpl
    lock = tpl + ".lock"
    t0 = time.time()
    while True:
        try:
            os.makedirs(os.path.dirname(lock), exist_ok=True)
            os.mkdir(lock)
            break
        except FileExistsError:
            if os.path.exists(done):
                return tpl
            if time.time() - t0 > 300:
                shutil.rmtree(lock, ignore_errors=True)
            time.sleep(3)
    try:
        if not os.path.exists(done):
            shutil.rmtree(tpl, ignore_errors=True)
            env = native_run.wine_env(tpl)
            subprocess.run([wine, "wineboot", "-i"], env=env, capture_output=True, timeout=280)
            subprocess.run([os.path.join(os.path.dirname(wine), "wineserver"), "-w"], env=env, capture_output=True, timeout=120)
            open(done, "w").write("ok\n")
    finally:
        shutil.rmtree(lock, ignore_errors=True)
    return tpl


def cmd_run(a):
    import native_run
    wine = native_run.WINE
    if os.environ.get("WINE") or not os.path.exists(wine):
        wine = os.environ.get("WINE") or wine
    native_run.WINE = wine
    work = os.getcwd()
    img = os.path.join(work, "wine-img")
    out = os.path.join(work, "wine-out")
    os.makedirs(out, exist_ok=True)
    home = os.environ.get("JOBQ_HOME") or ROOT
    data = os.path.join(home, "isos/extracted")
    if not os.path.exists(os.path.join(data, "art.rcf")):
        sys.exit("no game data at %s (rsync the player's isos/extracted there)" % data)
    tpl = ensure_template(wine)
    prefix = os.path.join(work, "wineprefix")
    for flags in ("-Rcp", "-Rp"):
        if subprocess.run(["cp", flags, tpl, prefix], capture_output=True).returncode == 0:
            break
    trace = os.path.join(out, "trace.txt")
    save = os.path.join(out, "save")
    tdata = os.path.join(out, "tdata")
    os.makedirs(save, exist_ok=True)
    os.makedirs(tdata, exist_ok=True)
    env = dict(DEFAULT_ENV)
    env.update({"HULK_TRACE_FILE": wpath(trace), "HULK_DATA_DIR": wpath(data), "HULK_SAVE_DIR": wpath(save),
                "HULK_TDATA_DIR": wpath(tdata), "HULK_INPUT_SOURCE": "replay:" + wpath(os.path.join(img, "rec.hrp"))})
    if not a.gfx:
        env["HULK_GFX_RENDERER"] = "noop"
    for e in a.env or []:
        k, _, v = e.partition("=")
        env[k] = v
    r = native_run.run(os.path.join(img, "hulk-strict.exe"), prefix, a.timeout, env, out)
    ck = []
    for l in open(trace, errors="replace"):
        m = CKPT.search(l)
        if m:
            ck.append((int(m.group(1)), m.group(2)))
    with open(os.path.join(out, "ckpt.txt"), "w") as f:
        for fr, h in ck:
            f.write("%d %s\n" % (fr, h))
    r.update({"host": os.environ.get("JOBQ_HOST"), "wine": wine, "ckpts": len(ck), "last_frame": ck[-1][0] if ck else None,
              "env": env.get("HULK_GFX_RENDERER")})
    json.dump(r, open(os.path.join(out, "result.json"), "w"), indent=1)
    shutil.rmtree(prefix, ignore_errors=True)
    shutil.rmtree(save, ignore_errors=True)
    print(json.dumps(r))
    return 0 if ck else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="c", required=True)
    s = sp.add_parser("submit")
    s.add_argument("--name", required=True)
    s.add_argument("--img", default=os.path.join(ROOT, "build/native/link"))
    s.add_argument("--rec", default=os.path.join(ROOT, "build/rp1/play3.hrp"))
    s.add_argument("--timeout", type=int, default=200)
    s.add_argument("--gfx", action="store_true")
    s.add_argument("--host")
    s.add_argument("--env", action="append")
    s = sp.add_parser("run")
    s.add_argument("--timeout", type=int, default=200)
    s.add_argument("--gfx", action="store_true")
    s.add_argument("--env", action="append")
    s = sp.add_parser("wait")
    s.add_argument("id")
    s = sp.add_parser("compare")
    s.add_argument("items", nargs="+")
    a = ap.parse_args()
    return {"submit": cmd_submit, "run": cmd_run, "wait": cmd_wait, "compare": cmd_compare}[a.c](a) or 0


if __name__ == "__main__":
    sys.exit(main())
