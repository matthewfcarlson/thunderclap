#!/usr/bin/env python3
"""Rollback tests on the Wine build (docs/multiplayer.md section 16, mp3): whole-state snapshot and restore
(src/platform/sdl/xdk/snapshot.cpp, HULK_SNAP=1), the restore test, the input-latency probe and the rollback session.

  # the snapshot's image ranges from a link map (what the runtime copies besides the arena)
  build/venv/bin/python tools/rollback_test.py ranges IMG/hulk-strict.map OUT.txt [--list]
  # one instance on a recording with the snapshot on (what a queue job runs); --test / --probe as the env variables
  build/venv/bin/python tools/rollback_test.py run --img DIR --rec REC --out OUT --frames N [--rbtest E:D[:A[:B]]]
        [--probe E:K[:A[:B]]] [--env K=V ...]
  # the same as a queue job (ships the image with its map, the recording and these tools)
  build/venv/bin/python tools/rollback_test.py submit --name mp3-rb --img DIR --host studio --frames N [run options]
  # the rollback session (HULK_NET=rb): two instances on one host through tools/netshim.py
  build/venv/bin/python tools/rollback_test.py pair --img DIR --rec REC --hdr HDR --out OUT --frames N [--shim "..."]
  build/venv/bin/python tools/rollback_test.py submit --pair --hdr HDR ... (the pair as a queue job)
  # what the logs say (trace.txt of each run): rbtest / latprobe / rb tables
  build/venv/bin/python tools/rollback_test.py summary OUT...

Range flags: 1 = in the snapshot, 2 = in the shared state hash (both peers hold the same bytes there; the replay
cursor, which differs between a peer with a recording and one with its header, is snapshotted but not hashed).
"""
import argparse
import collections
import json
import os
import re
import shlex
import statistics
import subprocess
import sys
import threading
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
PY = sys.executable
DLLS = ["hulk-strict.exe", "hulk-strict.map", "SDL3.dll", "hulkmovie.dll", "avutil-60.dll", "avcodec-62.dll",
        "avformat-62.dll"]

# objects of the platform layer: not simulation state (render, audio device, files, threads, logs, the session)
PLATFORM_LIBS = ("hulk_sdl", "hulk_fs", "hulk_movies", "bgfx", "bx")
PLATFORM_OBJS = {
    "pddi.obj", "selftest_scene.obj", "sdl_platform.obj", "platform_events.obj", "win32_glue.obj", "trace.obj",
    "startup.obj", "library.obj", "crt_glue.obj", "replay_hooks.obj", "threads.obj", "file_io.obj", "saves.obj",
    "system.obj", "debug.obj", "graphics_d3d8.obj", "graphics_xgraphics.obj", "movies_bink.obj",
    "audio_soundtracks.obj", "audio_dsound.obj", "input_xpp.obj", "memory.obj", "timing.obj", "snapshot.obj"}
# platform state the simulation reads, and the game's own data items that live in platform objects
PLATFORM_KEEP = [
    (r"^_DAT_|^\?DAT_", 3, ("library.obj", "crt_glue.obj")),     # the game's data placed beside the glue
    (r"^_hulk_crt_rand_state$", 3, ("crt_glue.obj",)),             # rand() of the main thread (Lua math.random)
    (r"^_hulk_snd_rng$|^_hulk_snd_rand$", 3, ("replay_hooks.obj",)),  # the sound code's private generators
    (r"^_hulk_native_frame_no$", 3, ("startup.obj",)),            # the frame number
    (r"^_hulk_v|^_hulk_fixed_base$|^_hulk_dt_us$", 3, ("timing.obj",)),   # the virtual clock
    (r"^_hulk_heaps_$", 3, ("memory.obj",)),
    (r"^_g_handles$", 1, ("input_xpp.obj",)),                     # XInput handles (packet numbers)
    (r"^_g_rp$|^_g_ck$", 1, ("hulk_sdl:input_hulk_input.obj",)),  # the replay's cursor and checkpoint counter
    (r"^\?s_ring@pddi@hulk", 0, ("pddi.obj",)),                  # (the draw log's ring: a log, 768 KB)
    # the pddi front end's own state (its objects are game allocations, in the arena; these statics point at them)
    (r".", 1, ("pddi.obj", "bgfx_combiner.obj", "bgfx_context.obj", "bgfx_device.obj", "bgfx_display.obj",
               "bgfx_draw.obj", "bgfx_effects.obj", "bgfx_ext.obj", "bgfx_primbuffer.obj", "bgfx_shader.obj",
               "bgfx_texture.obj", "graphics_d3d8.obj")),
]
SYM = re.compile(r"\s*0003:([0-9a-f]{8})\s+(\S+)\s+([0-9a-f]{16})\s+(.*)$")
SEC = re.compile(r"\s*0003:([0-9a-f]{8}) ([0-9a-f]{8})H\s+(\S+)")


def classify(name, obj):
    lib = obj.split(":")[0] if ":" in obj else ""
    plat = lib in PLATFORM_LIBS or obj in PLATFORM_OBJS
    if "hulk_xdk_calls_" in name:
        return 0
    for rx, flags, objs in PLATFORM_KEEP:
        if obj in objs and re.search(rx, name):
            return flags
    if "hulk_xdk_calls_" in name:
        return 0
    return 0 if plat else 3


def ranges(map_path):
    """[(va, size, flags, name, obj)] of section 3 (.data, .bss) and the anchor's va"""
    syms, ends, anchor = {}, [], None
    for l in open(map_path, errors="replace"):
        m = SEC.match(l)
        if m:
            ends.append(int(m.group(1), 16) + int(m.group(2), 16))
            continue
        m = SYM.match(l)
        if not m:
            continue
        off, name, va, obj = int(m.group(1), 16), m.group(2), int(m.group(3), 16), m.group(4).strip()
        if name == "_hulk_native_frame_no":
            anchor = va
        if va not in syms:
            syms[va] = (off, name, obj)
    if not syms or anchor is None:
        sys.exit("%s: no section-3 symbols or no _hulk_native_frame_no" % map_path)
    vas = sorted(syms)
    base = vas[0] - syms[vas[0]][0]
    end = base + max(ends)
    out = []
    for i, va in enumerate(vas):
        nxt = vas[i + 1] if i + 1 < len(vas) else end
        _, name, obj = syms[va]
        out.append((va, nxt - va, classify(name, obj), name, obj))
    return out, anchor


def cmd_ranges(a):
    rs, anchor = ranges(a.map)
    merged = []
    for va, size, flags, name, obj in rs:
        if not flags:
            continue
        if merged and merged[-1][2] == flags and merged[-1][0] + merged[-1][1] == va:
            merged[-1][1] += size
        else:
            merged.append([va, size, flags, name])
    with open(a.out, "w") as f:
        f.write("A %x\n" % anchor)
        for va, size, flags, name in merged:
            f.write("R %x %x %x %s\n" % (va, size, flags, name))
    by = collections.Counter()
    for va, size, flags, name, obj in rs:
        by[(flags, obj if flags != 3 or obj in PLATFORM_OBJS or ":" in obj else "(game)")] += size
    tot = collections.Counter()
    for (fl, o), n in by.items():
        tot[fl] += n
    print("%s: %d ranges; snapshot %d bytes (hashed %d), left out %d" % (a.out, len(merged), tot[1] + tot[3], tot[3], tot[0]))
    if a.list:
        for (fl, o), n in sorted(by.items(), key=lambda x: -x[1]):
            print("  flags %d %-40s %9d" % (fl, o, n))


def wpath(p):
    return "Z:" + os.path.abspath(p).replace("/", "\\")


def home_dir():
    return os.environ.get("JOBQ_HOME") or ROOT


def run_env(a, out, ranges_path):
    env = {"HULK_SNAP": "1", "HULK_SNAP_RANGES": wpath(ranges_path)}
    if getattr(a, "rbtest", None):
        env["HULK_RB_TEST"] = a.rbtest
    if getattr(a, "probe", None):
        env["HULK_LAT_PROBE"] = a.probe
    for e in a.env or []:
        k, _, v = e.partition("=")
        env[k] = v
    return env


def cmd_run(a):
    import wine_replay_job
    out = os.path.abspath(a.out)
    os.makedirs(out, exist_ok=True)
    rp = os.path.join(out, "ranges.txt")
    cmd_ranges(argparse.Namespace(map=os.path.join(a.img, "hulk-strict.map"), out=rp, list=False))
    env = run_env(a, out, rp)
    t0 = time.time()
    r, ck = wine_replay_job.replay(out, os.path.abspath(a.img), os.path.abspath(a.rec), home_dir(), a.timeout, False, env,
                                   a.frames, out)
    s = summarize(out)
    s.update({"wall_s": round(time.time() - t0, 1), "run": r, "env": env})
    json.dump(s, open(os.path.join(out, "summary.json"), "w"), indent=1)
    print(json.dumps({k: v for k, v in s.items() if k not in ("probe_rows",)}, indent=1))
    return 0


# ---------------------------------------------------------------------------------------------------------------
# the rollback session pair (HULK_NET=rb)
def cmd_pair(a):
    import wine_replay_job
    out = os.path.abspath(a.out)
    os.makedirs(out, exist_ok=True)
    rp = os.path.join(out, "ranges.txt")
    cmd_ranges(argparse.Namespace(map=os.path.join(a.img, "hulk-strict.map"), out=rp, list=False))
    pa, pb, sa, sb = a.ports, a.ports + 1, a.ports + 2, a.ports + 3
    shim = None
    if a.shim:
        argv = [PY, os.path.join(ROOT, "tools/netshim.py"), "run", "--log", os.path.join(out, "shim.jsonl"),
                "--link", "%d:127.0.0.1:%d" % (sa, pb), "--link", "%d:127.0.0.1:%d" % (sb, pa)] + shlex.split(a.shim)
        shim = subprocess.Popen(argv, stdout=open(os.path.join(out, "shim.out"), "w"), stderr=subprocess.STDOUT)
        time.sleep(1.0)
        peer_a, peer_b = "127.0.0.1:%d" % sa, "127.0.0.1:%d" % sb
    else:
        peer_a, peer_b = "127.0.0.1:%d" % pb, "127.0.0.1:%d" % pa
    res = {}
    t0 = time.time()

    def side(name, rec, role, bind, peer):
        d = os.path.join(out, name)
        os.makedirs(d, exist_ok=True)
        env = run_env(a, d, rp)
        env.update({"HULK_NET": "rb", "HULK_NET_RB_PLAYER": role, "HULK_NET_BIND": str(bind), "HULK_NET_PEER": peer,
                    "HULK_NET_LOG": wpath(os.path.join(d, "net.log")), "HULK_FPS_CAP": "0", "HULK_NET_RB_FPS": str(a.fps),
                    "HULK_NET_RB_WINDOW": str(a.window), "HULK_NET_RB_DELAY": str(a.delay)})
        if a.p1_from is not None:
            env["HULK_NET_RB_P1_FROM"] = str(a.p1_from)
        res[name] = wine_replay_job.replay(d, os.path.abspath(a.img), os.path.abspath(rec), home_dir(), a.timeout, False,
                                           env, a.frames, d)[0]

    ta = threading.Thread(target=side, args=("a", a.rec, "0", pa, peer_a))
    tb = threading.Thread(target=side, args=("b", a.hdr, "1", pb, peer_b))
    ta.start()
    time.sleep(a.b_delay)
    tb.start()
    ta.join()
    tb.join()
    if shim:
        shim.terminate()
        try:
            shim.wait(10)
        except subprocess.TimeoutExpired:
            shim.kill()
    s = {"a": summarize(os.path.join(out, "a")), "b": summarize(os.path.join(out, "b")), "runs": res,
         "wall_s": round(time.time() - t0, 1), "shim": a.shim, "fps": a.fps, "window": a.window, "delay": a.delay}
    json.dump(s, open(os.path.join(out, "summary.json"), "w"), indent=1)
    print(json.dumps({k: {kk: vv for kk, vv in v.items() if kk not in ("probe_rows", "depths")} if isinstance(v, dict) and k in "ab" else v
                      for k, v in s.items()}, indent=1))
    return 0


# ---------------------------------------------------------------------------------------------------------------
RB = re.compile(r"rbtest f=(\d+) depth=(\d+) (ok|DIFF) state (\d+) KB \(arena (\d+) KB, live (\d+) blocks\) save (\d+) us "
                r"restore (\d+) us pass1 (\d+) us pass2 (\d+) us dirty1 (\d+) pages \((\d+) words\) io posts (\d+) "
                r"diff (\d+) pages (\d+) words calls: (.*)$")
LP = re.compile(r"latprobe f=(\d+) input=(\S+) read=(-?\d+) input=(-?\d+) actor=(-?\d+) position=(-?\d+) camera=(-?\d+)")
CK = re.compile(r"ckpt frame (\d+) hash ([0-9a-f]{8}) recording (?:\(none\) )?([0-9a-f]{8}) (ok|DIVERGED)")
RBS = re.compile(r"rb stats (.*)$")
RBD = re.compile(r"rb depth (\d+): (\d+)")
NETH = re.compile(r"net hash frame (\d+) local ([0-9a-f]+) remote ([0-9a-f]+) (ok|DIVERGED)")


def summarize(d):
    tr = os.path.join(d, "trace.txt")
    s = {"dir": d, "rbtest": 0, "rbtest_ok": 0, "rbtest_diff": [], "probe_rows": [], "ckpt_diverged": [],
         "ckpt_ok": 0, "last_ckpt": None}
    if not os.path.exists(tr):
        return s
    rows = []
    for l in open(tr, errors="replace"):
        m = RB.search(l)
        if m:
            g = m.groups()
            r = {"f": int(g[0]), "ok": g[2] == "ok", "state_kb": int(g[3]), "arena_kb": int(g[4]), "live": int(g[5]),
                 "save_us": int(g[6]), "restore_us": int(g[7]), "pass1_us": int(g[8]), "pass2_us": int(g[9]),
                 "dirty1": int(g[10]), "posts": int(g[12]), "diff_pages": int(g[13]), "calls": g[15].strip()}
            rows.append(r)
            continue
        m = LP.search(l)
        if m:
            g = m.groups()
            s["probe_rows"].append({"f": int(g[0]), "input": g[1], "read": int(g[2]), "in": int(g[3]), "actor": int(g[4]),
                                    "pos": int(g[5]), "cam": int(g[6])})
            continue
        m = CK.search(l)
        if m:
            if m.group(4) == "ok":
                s["ckpt_ok"] += 1
            else:
                s["ckpt_diverged"].append(int(m.group(1)))
            s["last_ckpt"] = int(m.group(1))
    s["rbtest"] = len(rows)
    s["rbtest_ok"] = sum(r["ok"] for r in rows)
    s["rbtest_diff"] = [(r["f"], r["diff_pages"], r["posts"], r["calls"][:200]) for r in rows if not r["ok"]][:40]
    if rows:
        def st(k):
            v = sorted(r[k] for r in rows)
            return {"min": v[0], "median": v[len(v) // 2], "p90": v[int(len(v) * 0.9)], "max": v[-1]}
        s["rbtest_stats"] = {k: st(k) for k in ("state_kb", "arena_kb", "save_us", "restore_us", "pass1_us", "pass2_us",
                                                  "dirty1", "posts")}
        s["rbtest_with_io"] = sum(1 for r in rows if r["posts"])
        s["rbtest_with_io_ok"] = sum(1 for r in rows if r["posts"] and r["ok"])
        s["rbtest_with_calls"] = sum(1 for r in rows if r["calls"] != "-")
        s["rbtest_with_calls_ok"] = sum(1 for r in rows if r["calls"] != "-" and r["ok"])
    if s["probe_rows"]:
        s["probe"] = probe_table(s["probe_rows"])
    # the rollback session's own lines
    net = os.path.join(d, "net.log")
    if os.path.exists(net):
        h = {"ok": 0, "bad": 0, "first_bad": None}
        last = None
        depths = collections.Counter()
        for l in open(net, errors="replace"):
            m = NETH.search(l)
            if m:
                if m.group(4) == "ok":
                    h["ok"] += 1
                else:
                    h["bad"] += 1
                    h["first_bad"] = h["first_bad"] or int(m.group(1))
            m = RBS.search(l)
            if m:
                last = m.group(1)
            m = RBD.search(l)
            if m:
                depths[int(m.group(1))] = int(m.group(2))
        s["net_hashes"] = h
        s["rb_last_stats"] = last
        s["depths"] = dict(sorted(depths.items()))
    return s


def probe_table(rows):
    """per input: how many probes saw any effect, and the distribution of (first frame of effect - first injected read)"""
    out = {}
    for inp in sorted(set(r["input"] for r in rows)):
        rs = [r for r in rows if r["input"] == inp and r["read"] >= 0]
        t = {"probes": len(rs)}
        for sig in ("in", "actor", "pos", "cam"):
            lat = [r[sig] - r["read"] for r in rs if r[sig] >= 0]
            c = collections.Counter(lat)
            t[sig] = {"n": len(lat), "hist": dict(sorted(c.items())),
                      "median": statistics.median(lat) if lat else None}
        out[inp] = t
    return out


def cmd_summary(a):
    for d in a.dirs:
        if os.path.isdir(os.path.join(d, "a")):
            for side in ("a", "b"):
                s = summarize(os.path.join(d, side))
                print(side, json.dumps({k: v for k, v in s.items() if k != "probe_rows"}, indent=1))
        else:
            s = summarize(d)
            print(json.dumps({k: v for k, v in s.items() if k != "probe_rows"}, indent=1))


def cmd_submit(a):
    img = os.path.abspath(a.img)
    files = ["%s=rb-img/%s" % (os.path.join(img, f), f) for f in DLLS]
    files += ["%s=rb-img/rec.hrp" % os.path.abspath(a.rec)]
    if a.pair:
        files += ["%s=rb-img/hdr.hrp" % os.path.abspath(a.hdr)]
    argv = [PY, os.path.join(ROOT, "tools/jobq.py"), "submit", "--name", a.name, "--needs", "wine", "--limit",
            str(a.timeout + 900), "--attempts", "1", "--out", "rb-out", "--files"] + files + [
        "tools/rollback_test.py", "tools/netshim.py", "tools/wine_replay_job.py", "tools/wine_run.py"]
    if a.host:
        argv += ["--host", a.host]
    cmd = ["--", "python", "tools/rollback_test.py", "pair" if a.pair else "run", "--img", "rb-img", "--rec",
           "rb-img/rec.hrp", "--out", "rb-out", "--frames", str(a.frames), "--timeout", str(a.timeout)]
    if a.pair:
        cmd += ["--hdr", "rb-img/hdr.hrp", "--fps", str(a.fps), "--window", str(a.window), "--delay", str(a.delay),
                "--ports", str(a.ports), "--shim=" + (a.shim or "")]
        if a.p1_from is not None:
            cmd += ["--p1-from", str(a.p1_from)]
    if a.rbtest:
        cmd += ["--rbtest", a.rbtest]
    if a.probe:
        cmd += ["--probe", a.probe]
    for e in a.env or []:
        cmd += ["--env", e]
    r = subprocess.run(argv + cmd, capture_output=True, text=True)
    if r.returncode:
        sys.exit(r.stderr or r.stdout)
    print(r.stdout.strip())


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="c", required=True)
    p = sp.add_parser("ranges")
    p.add_argument("map")
    p.add_argument("out")
    p.add_argument("--list", action="store_true")

    def common(p):
        p.add_argument("--img", required=True)
        p.add_argument("--rec", default=os.path.join(ROOT, "build/rp1/play3.hrp"))
        p.add_argument("--frames", type=int, default=60000)
        p.add_argument("--timeout", type=int, default=3600)
        p.add_argument("--rbtest", help="HULK_RB_TEST: every:depth[:from[:to]]")
        p.add_argument("--probe", help="HULK_LAT_PROBE: every:frames[:from[:to]]")
        p.add_argument("--env", action="append", help="K=V")
        p.add_argument("--fps", type=int, default=30, help="pair: HULK_FPS_CAP (0: unpaced)")
        p.add_argument("--window", type=int, default=8, help="pair: frames of prediction (HULK_NET_RB_WINDOW)")
        p.add_argument("--delay", type=int, default=0, help="pair: frames of input delay (HULK_NET_RB_DELAY)")
        p.add_argument("--p1-from", type=int, help="pair: the frame from which player 1's random input starts")
        p.add_argument("--shim", default="", help="pair: netshim model arguments; empty: no shim")
        p.add_argument("--ports", type=int, default=43000)
    p = sp.add_parser("run")
    common(p)
    p.add_argument("--out", required=True)
    p = sp.add_parser("pair")
    common(p)
    p.add_argument("--out", required=True)
    p.add_argument("--hdr", required=True)
    p.add_argument("--b-delay", type=float, default=2.0)
    p = sp.add_parser("submit")
    common(p)
    p.add_argument("--name", required=True)
    p.add_argument("--host")
    p.add_argument("--pair", action="store_true")
    p.add_argument("--hdr")
    p = sp.add_parser("summary")
    p.add_argument("dirs", nargs="+")
    a = ap.parse_args()
    return {"ranges": cmd_ranges, "run": cmd_run, "pair": cmd_pair, "submit": cmd_submit, "summary": cmd_summary}[a.c](a)


if __name__ == "__main__":
    sys.exit(main())
