#!/usr/bin/env python3
"""Replay a recording on a native build headless and check it against the original's reference checkpoints
(render1, D187; docs/checkpoints.md "Comparing a build", docs/native-mac.md "Replays").

The native builds carry the replay driver (src/platform/sdl/host/replay_native.cpp: the recording's input, the
fixed-step clock, the checkpoint and the semantic probe's records). This runs one locally, as wine_replay_job.py runs
the Wine build, and gates its records against the reference with tools/ckpt_ref.py:

    build/venv/bin/python tools/native_replay.py run --exe build/native-mac/link/hulk-mac --out build/ME/run1 \\
        [--rec play3] [--frames 60000] [--hang 120] [--env K=V ...]
    build/venv/bin/python tools/native_replay.py check RUN.ckref [--ref build/ckpt/play3.ckref] [--frames N] \\
        [--control CONTROL.ckref] [--json OUT]
    build/venv/bin/python tools/native_replay.py layout   # the probe's native offsets against decls / gen

`run` writes OUT/trace.txt, OUT/trace.txt.ckref, OUT/stdout.txt and OUT/result.json (the frames reached, how the run
ended, the checkpoint lines' verdicts), stops the process once the trace shows the checkpoint of frame --frames, and
then runs `check` unless --no-check. `check` takes the records of any build (the Wine build's, a native one's, the
wasm lane's: the same "HCKR" format), so two builds race on the same test: the verdict is ckpt_ref's (every compared
(frame, tag) equal to the reference; the probe's unavailable tags are not compared) plus, with --frames, that the run
has a record at every reference frame up to N. The exit status is 0 only when both hold.

Nothing it writes is committed: traces and records are derived from the game (build/ only).
"""
import argparse
import json
import os
import re
import signal
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
RECS = {"play3": "build/rp1/play3.hrp"}           # (wine_build_job.RECS)
REFS = {"play3": "build/ckpt/play3.ckref"}
# the Wine replay's defaults (wine_replay_job.DEFAULT_ENV), the headless renderer and the dummy audio device
DEFAULT_ENV = {"HULK_CKPT": "1", "HULK_CKPT_ALL": "1", "HULK_AUDIO_CLOCK": "frame", "HULK_CKPT_REGIONS": "0",
               "HULK_AUDIO_NOMIX": "1", "HULK_CKREF": "1", "HULK_GFX_RENDERER": "noop", "SDL_AUDIO_DRIVER": "dummy",
               "HULK_NATIVE_MISSING": "continue"}
CKPT = re.compile(r"ckpt frame (\d+) hash ([0-9a-f]{8}) recording (?:\(none\) )?[0-9a-f]{8} (ok|DIVERGED)")
END = re.compile(r"^(crash|end|hang) ")


def scan(trace, pos, st):
    """Read the trace from `pos`: the checkpoint lines and the end lines. Returns the new position."""
    try:
        with open(trace, errors="replace") as f:
            f.seek(pos)
            while True:
                line = f.readline()
                if not line or not line.endswith("\n"):
                    return pos
                pos += len(line.encode("utf-8", "surrogateescape"))
                m = CKPT.search(line)
                if m:
                    fr = int(m.group(1))
                    st["last_frame"] = fr
                    st["ckpts"] += 1
                    if m.group(3) == "DIVERGED":
                        st["diverged"] += 1
                        if st["first_diverged"] is None:
                            st["first_diverged"] = fr
                elif END.match(line) and len(st["end"]) < 8:
                    st["end"].append(line.strip()[:300])
    except FileNotFoundError:
        return pos


def cmd_run(a):
    exe = os.path.abspath(a.exe)
    out = os.path.abspath(a.out)
    rec = os.path.abspath(RECS.get(a.rec, a.rec))
    if not os.path.exists(rec):
        sys.exit("no recording " + rec)
    for sub in ("save", "tdata", "udata"):
        os.makedirs(os.path.join(out, sub), exist_ok=True)
    trace = os.path.join(out, "trace.txt")
    for p in (trace, trace + ".ckref"):
        if os.path.exists(p):
            os.remove(p)
    env = dict(os.environ)
    env.update(DEFAULT_ENV)
    env.update({"HULK_TRACE_FILE": trace, "HULK_DATA_DIR": os.path.abspath(a.data),
                "HULK_SAVE_DIR": os.path.join(out, "save"), "HULK_TDATA_DIR": os.path.join(out, "tdata"),
                "HULK_UDATA_DIR": os.path.join(out, "udata"), "HULK_INPUT_SOURCE": "replay:" + rec,
                "HULK_HANG": str(a.hang)})
    for kv in a.env or []:
        k, _, v = kv.partition("=")
        env[k] = v
    st = {"last_frame": None, "ckpts": 0, "diverged": 0, "first_diverged": None, "end": []}
    t0 = time.time()
    with open(os.path.join(out, "stdout.txt"), "wb") as so:
        p = subprocess.Popen([exe] + a.args, cwd=out, env=env, stdout=so, stderr=subprocess.STDOUT,
                             start_new_session=True)
        pos, how = 0, None
        while True:
            try:
                rc = p.wait(timeout=1.0)
                how = "exit %d" % rc
                break
            except subprocess.TimeoutExpired:
                pass
            pos = scan(trace, pos, st)
            if a.frames is not None and st["last_frame"] is not None and st["last_frame"] >= a.frames:
                how = "frame %d reached" % a.frames
                break
            if time.time() - t0 > a.timeout:
                how = "timeout %d s" % a.timeout
                break
        if p.poll() is None:
            os.killpg(p.pid, signal.SIGTERM)
            try:
                p.wait(timeout=10)
            except subprocess.TimeoutExpired:
                os.killpg(p.pid, signal.SIGKILL)
                p.wait()
    scan(trace, pos, st)
    st.update({"exe": exe, "recording": rec, "how": how, "wall": round(time.time() - t0, 1),
               "fps": round(st["ckpts"] / max(0.1, time.time() - t0), 1)})
    json.dump(st, open(os.path.join(out, "result.json"), "w"), indent=1)
    print("run: %s; last frame %s, %d checkpoint lines (%d DIVERGED, first %s) in %.0f s" % (
        how, st["last_frame"], st["ckpts"], st["diverged"], st["first_diverged"], st["wall"]))
    for l in st["end"]:
        print("  " + l)
    if a.no_check:
        return 0
    ref = RECS.get(a.rec) and REFS.get(a.rec)
    if not ref:
        return 0
    ns = argparse.Namespace(run=trace + ".ckref", ref=os.path.join(ROOT, ref), frames=a.frames, control=None,
                            json=os.path.join(out, "check.json"), strict=False)
    return cmd_check(ns)


def cmd_check(a):
    import ckpt_ref
    if not os.path.exists(a.run):
        print("check: no records %s (the build wrote none: HULK_CKREF=1?)" % a.run)
        print("VERDICT DIVERGED")
        return 1
    ns = argparse.Namespace(run=a.run, ref=a.ref, cover=None, control=a.control, strict=a.strict, json=a.json)
    rc = ckpt_ref.cmd_check(ns)
    if a.frames is None:
        return rc
    _, _, run, _ = ckpt_ref.read(a.run)
    _, _, ref, _ = ckpt_ref.read(a.ref)
    want = [fr for fr in ref if fr <= a.frames]
    lacks = [fr for fr in want if fr not in run]
    print("frames: the reference has %d records to frame %d, the run lacks %d%s" % (
        len(want), a.frames, len(lacks), " (first %d)" % min(lacks) if lacks else ""))
    if a.json and os.path.exists(a.json):
        rep = json.load(open(a.json))
        rep["frames"] = {"to": a.frames, "reference": len(want), "lacks": len(lacks),
                         "first_lacking": min(lacks) if lacks else None}
        rep["ok"] = bool(rep.get("ok")) and not lacks
        json.dump(rep, open(a.json, "w"), indent=1)
    if lacks:
        print("VERDICT DIVERGED (frames missing)")
        return 1
    return rc


LAYOUT_PROBE = r'''
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "decls/managers.h"
#define O(c, f) __builtin_offsetof(c, f)
static_assert(O(HulkWorld, parts[7]) == %(world_actor_manager)s, "world_actor_manager: HulkWorld parts[7] (32-bit +0x20)");
static_assert(O(HulkWorld, parts[10]) == %(world_scenario_manager)s, "world_scenario_manager: HulkWorld parts[10] (+0x2c)");
static_assert(O(::CScenarioManager, f_0c) == %(sm_state)s, "sm_state: CScenarioManager::f_0c");
static_assert(O(::CScenarioManager, f_1194) == %(sm_checkpoint)s, "sm_checkpoint: CScenarioManager::f_1194");
static_assert(O(::CScenarioManager, f_1198) == %(sm_elapsed)s, "sm_elapsed: CScenarioManager::f_1198");
static_assert(O(::CScenarioManager, f_119c) == %(sm_end_time)s, "sm_end_time: CScenarioManager::f_119c");
'''
LAYOUT_FIELDS = ("world_actor_manager", "world_scenario_manager", "sm_state", "sm_checkpoint", "sm_elapsed", "sm_end_time")


def layout_values():
    """replay_native.cpp's hulk_probe_layout64 initializer, by field."""
    s = open(os.path.join(ROOT, "src/platform/sdl/host/replay_native.cpp")).read()
    m = re.search(r"hulk_probe_layout64 = \{([^}]*)\}", s)
    vals = [v.strip() for v in m.group(1).split(",")] if m else []
    if len(vals) != len(LAYOUT_FIELDS):
        raise SystemExit("native_replay: replay_native.cpp's hulk_probe_layout64 initializer not found")
    return dict(zip(LAYOUT_FIELDS, vals))


def layout_check():
    """None, or the failing static_asserts: the probe's native offsets (hulk_probe_layout64) against decls' HulkWorld
    and gen's CScenarioManager under the tree's native front end (native_pddi.layout_check's way)."""
    import clang_probe as cp
    import native_mac as nmac
    front = [x for x in nmac.FRONT if x not in ("-S", "-emit-llvm")] + cp.common_native()
    d = os.path.join(ROOT, "build/native-replay")
    os.makedirs(d, exist_ok=True)
    p = os.path.join(d, "layout_probe.cpp")
    open(p, "w").write(LAYOUT_PROBE % layout_values())
    r = subprocess.run([cp.tool("clang++")] + front + ["-I" + os.path.join(ROOT, "include"), "-Wno-invalid-offsetof",
                        "-fsyntax-only", p], capture_output=True, text=True, errors="replace")
    return None if r.returncode == 0 else r.stderr[-3000:]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    r = sp.add_parser("run")
    r.add_argument("--exe", required=True, help="the native image (native_mac.py link: NATIVE_DIR/link/hulk-mac)")
    r.add_argument("--out", required=True)
    r.add_argument("--rec", default="play3", help="play3 or a .hrp path")
    r.add_argument("--frames", type=int, help="stop once the checkpoint of this frame is in the trace")
    r.add_argument("--data", default=os.path.join(ROOT, "isos/extracted"))
    r.add_argument("--hang", type=int, default=120, help="HULK_HANG: seconds without progress before the image ends")
    r.add_argument("--timeout", type=int, default=7200)
    r.add_argument("--env", action="append", help="K=V for the image (after the defaults)")
    r.add_argument("--no-check", action="store_true")
    r.add_argument("args", nargs="*")
    c = sp.add_parser("check")
    c.add_argument("run", help="the run's records (TRACE.ckref) from any build")
    c.add_argument("--ref", default=os.path.join(ROOT, REFS["play3"]))
    c.add_argument("--frames", type=int, help="also require a record at every reference frame up to this one")
    c.add_argument("--control")
    c.add_argument("--strict", action="store_true")
    c.add_argument("--json")
    sp.add_parser("layout", help="the probe's native offsets against the headers")
    a = ap.parse_args()
    if a.cmd == "layout":
        e = layout_check()
        print(e or "probe layout: ok (%d offsets)" % len(LAYOUT_FIELDS))
        sys.exit(1 if e else 0)
    sys.exit(cmd_run(a) if a.cmd == "run" else cmd_check(a))


if __name__ == "__main__":
    main()
