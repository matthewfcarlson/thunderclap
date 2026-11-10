#!/usr/bin/env python3
"""M0 lockstep sessions on the Wine build (docs/multiplayer.md "M0"): instance A replays a recording as the live player
and streams every pad read over UDP (HULK_NET=send); instance B runs the same session settings from a header-only copy
of the recording (no inputs, no checkpoints) and takes every pad read from A (HULK_NET=recv). Both exchange the
session state hash every 30 frames. Packets go through tools/netshim.py.

  # header-only copy of a recording (the session settings: flags, seed, tweaks, pads)
  build/venv/bin/python tools/lockstep_test.py strip build/rp1/play3.hrp build/mp2/play3-hdr.hrp
  # a pair on one host (what a jobq job runs; --shim "" = direct, no shim)
  build/venv/bin/python tools/lockstep_test.py pair --img DIR --rec REC --hdr HDR --out OUT --frames 9000 \
        [--fps 30|0] [--lead 8] [--shim "--delay 120-200 --jitter 15 --loss 2 --seed 7"] [--ports 41000]
  # one side of a pair across hosts (each host runs its own instance and, for impairment, its own one-way shim)
  build/venv/bin/python tools/lockstep_test.py peer --role send|recv --img DIR --rec REC --out OUT --bind PORT \
        --peer A.B.C.D:PORT --frames N [--fps 30] [--lead 8] [--shim-in "..."]
  # submit a pair as a queue job (ships the image, the recordings and the tools); with --role/--peer one side only
  build/venv/bin/python tools/lockstep_test.py submit --name mp2-ls --img DIR --hdr HDR --host studio --frames 9000 [pair options]
  build/venv/bin/python tools/lockstep_test.py submit ... --host mac2 --role send --ports 41000 --peer STUDIO_IP:41000
  # summarise one or more output directories (net.log of each side)
  build/venv/bin/python tools/lockstep_test.py summary OUT...

The output directory gets a/ and b/ (trace.txt, net.log, ckpt.txt, stderr.txt), shim.jsonl and summary.json.
"""
import argparse
import json
import os
import re
import shlex
import struct
import subprocess
import sys
import threading
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
PY = sys.executable
DLLS = ["hulk-strict.exe", "SDL3.dll", "hulkmovie.dll", "avutil-60.dll", "avcodec-62.dll", "avformat-62.dll"]
STATS = re.compile(r"net stats frame (\d+): stall (\d+) ms total \((\d+) frames\), window (\d+) ms \((\d+) frames\), "
                   r"worst (\d+) ms; hitches >50 ms (\d+) total, (\d+) window, worst gap (\d+) ms \(window (\d+)\); "
                   r"rtt last (\d+) min (\d+) avg (\d+) max (\d+) ms; lead (-?\d+)\.\.(-?\d+); pkts out (\d+) in (\d+), "
                   r"(\d+) bytes out; hashes ok (\d+) bad (\d+)(?:; reads \d+)?")
HASH = re.compile(r"net hash frame (\d+) local ([0-9a-f]+) remote ([0-9a-f]+) (ok|DIVERGED)")


def a_extra(lead):
    """frames A runs past B's stop: past B's last frame (whose reads A sends at its next frame), within the gate"""
    return max(2, min(lead, 90))


def cmd_strip(a):
    raw = open(a.rec, "rb").read()
    if raw[:4] != b"HRP1":
        sys.exit("not an .hrp")
    hdr = bytearray(raw[:36])
    struct.pack_into("<II", hdr, 28, 0, 0)       # n_inputs, n_checkpoints
    open(a.out, "wb").write(bytes(hdr))
    print("%s: header only (%d bytes)" % (a.out, len(hdr)))


def instance(img, rec, out, env_extra, timeout, stop_frame, home):
    import wine_replay_job
    return wine_replay_job.replay(out, img, rec, home, timeout, False, env_extra, stop_frame, out)


def side_env(role, bind, peer, out, fps, lead, extra=()):
    import wine_replay_job
    env = {"HULK_NET": role, "HULK_NET_BIND": str(bind), "HULK_NET_PEER": peer, "HULK_NET_LEAD": str(lead),
           "HULK_NET_LOG": wine_replay_job.wpath(os.path.join(out, "net.log")), "HULK_FPS_CAP": str(fps)}
    for e in extra:
        k, _, v = e.partition("=")
        env[k] = v
    return env


def start_shim(args, links, log):
    if args is None:
        return None
    argv = [PY, os.path.join(ROOT, "tools/netshim.py"), "run", "--log", log]
    for l in links:
        argv += ["--link", l]
    argv += shlex.split(args)
    p = subprocess.Popen(argv, stdout=open(log + ".out", "w"), stderr=subprocess.STDOUT)
    time.sleep(1.0)
    return p


def stop_shim(p):
    if p:
        p.terminate()
        try:
            p.wait(10)
        except subprocess.TimeoutExpired:
            p.kill()


def home_dir():
    return os.environ.get("JOBQ_HOME") or ROOT


def cmd_pair(a):
    out = os.path.abspath(a.out)
    os.makedirs(out, exist_ok=True)
    pa, pb = a.ports, a.ports + 1          # A and B listen here
    sa, sb = a.ports + 2, a.ports + 3      # the shim's inputs: to B, to A
    shim = None
    if a.shim:
        shim = start_shim(a.shim, ["%d:127.0.0.1:%d" % (sa, pb), "%d:127.0.0.1:%d" % (sb, pa)], os.path.join(out, "shim.jsonl"))
        peer_a, peer_b = "127.0.0.1:%d" % sa, "127.0.0.1:%d" % sb
    else:
        peer_a, peer_b = "127.0.0.1:%d" % pb, "127.0.0.1:%d" % pa
    res = {}
    t0 = time.time()

    def run(name, rec, env):
        d = os.path.join(out, name)
        os.makedirs(d, exist_ok=True)
        # A runs past B's stop so B's last inputs are sent even if packets near the end are lost; the gate lets it get
        # at most LEAD frames past B's last frame
        stop = a.frames + a_extra(a.lead) if name == "a" else a.frames
        res[name] = instance(os.path.abspath(a.img), os.path.abspath(rec), d, env, a.timeout, stop, home_dir())[0]

    ea = side_env("send", pa, peer_a, os.path.join(out, "a"), a.fps, a.lead, a.env or [])
    eb = side_env("recv", pb, peer_b, os.path.join(out, "b"), a.fps, a.lead, a.env or [])
    ta = threading.Thread(target=run, args=("a", a.rec, ea))
    tb = threading.Thread(target=run, args=("b", a.hdr, eb))
    ta.start()
    time.sleep(a.b_delay)
    tb.start()
    ta.join()
    # A stops at the frame; B may be a little behind: give it the rest of its own stop rule
    tb.join()
    stop_shim(shim)
    s = summarize(out)
    s.update({"wall_s": round(time.time() - t0, 1), "runs": res, "shim": a.shim, "fps": a.fps, "lead": a.lead})
    json.dump(s, open(os.path.join(out, "summary.json"), "w"), indent=1)
    print(json.dumps(s, indent=1))
    return 0 if s.get("diverged") == 0 and s.get("compared", 0) > 0 else 1


def cmd_peer(a):
    out = os.path.abspath(a.out)
    os.makedirs(out, exist_ok=True)
    shim = None
    peer = a.peer
    if a.shim_out:
        # the impairment of this side's outgoing direction: a local one-way shim in front of the peer
        host, port = a.peer.split(":")
        shim = start_shim(a.shim_out, ["%d:%s:%s" % (a.bind + 2, host, port)], os.path.join(out, "shim.jsonl"))
        peer = "127.0.0.1:%d" % (a.bind + 2)
    env = side_env(a.role, a.bind, peer, out, a.fps, a.lead, a.env or [])
    r = instance(os.path.abspath(a.img), os.path.abspath(a.rec), out, env, a.timeout, a.frames, home_dir())[0]
    stop_shim(shim)
    s = summarize_side(out)
    s["run"] = r
    json.dump(s, open(os.path.join(out, "summary.json"), "w"), indent=1)
    print(json.dumps(s, indent=1))
    return 0


def summarize_side(d):
    log = os.path.join(d, "net.log")
    s = {"dir": d, "hashes": 0, "ok": 0, "diverged": 0, "first_bad": None, "last_hash_frame": None, "stats": None,
         "windows": []}
    if not os.path.exists(log):
        return s
    for l in open(log, errors="replace"):
        m = HASH.search(l)
        if m:
            s["hashes"] += 1
            s["last_hash_frame"] = int(m.group(1))
            if m.group(4) == "ok":
                s["ok"] += 1
            else:
                s["diverged"] += 1
                if s["first_bad"] is None:
                    s["first_bad"] = int(m.group(1))
        m = STATS.search(l)
        if m:
            v = [int(x) for x in m.groups()]
            st = dict(zip(["frame", "stall_ms", "stalled_frames", "win_stall_ms", "win_stalled", "worst_stall_ms", "hitches",
                           "win_hitches", "worst_gap_ms", "win_worst_gap_ms", "rtt_last", "rtt_min", "rtt_avg", "rtt_max",
                           "lead_min", "lead_max", "pkts_out", "pkts_in", "bytes_out", "hash_ok", "hash_bad"], v))
            s["stats"] = st
            s["windows"].append({k: st[k] for k in ("frame", "win_stall_ms", "win_stalled", "win_hitches", "win_worst_gap_ms",
                                                    "lead_min", "lead_max", "rtt_last")})
    return s


def summarize(out):
    a, b = summarize_side(os.path.join(out, "a")), summarize_side(os.path.join(out, "b"))
    # the checkpoint hashes too (they include the camera: equal while both instances show the same player's view)
    def ck(d):
        p = os.path.join(d, "ckpt.txt")
        r = {}
        if os.path.exists(p):
            for l in open(p):
                f, h = l.split()
                r[int(f)] = h
        return r
    ca, cb = ck(os.path.join(out, "a")), ck(os.path.join(out, "b"))
    common = sorted(set(ca) & set(cb))
    bad = [f for f in common if ca[f] != cb[f]]
    return {"a": {k: v for k, v in a.items() if k != "windows"}, "b": {k: v for k, v in b.items() if k != "windows"},
            "compared": a["hashes"] + b["hashes"], "diverged": a["diverged"] + b["diverged"],
            "ckpt_common": len(common), "ckpt_last": common[-1] if common else None, "ckpt_differ": len(bad),
            "ckpt_first_differ": bad[0] if bad else None,
            "windows_a": a["windows"], "windows_b": b["windows"]}


def cmd_summary(a):
    for d in a.dirs:
        s = summarize(d) if os.path.isdir(os.path.join(d, "a")) else summarize_side(d)
        print(json.dumps({k: v for k, v in s.items() if not k.startswith("windows")}, indent=1))


def cmd_submit(a):
    img = os.path.abspath(a.img)
    files = ["%s=ls-img/%s" % (os.path.join(img, f), f) for f in DLLS]
    files += ["%s=ls-img/rec.hrp" % os.path.abspath(a.rec), "%s=ls-img/hdr.hrp" % os.path.abspath(a.hdr)]
    argv = [PY, os.path.join(ROOT, "tools/jobq.py"), "submit", "--name", a.name, "--needs", "wine", "--limit",
            str(a.timeout + 600), "--attempts", "1", "--out", "ls-out", "--files"] + files + [
        "tools/lockstep_test.py", "tools/netshim.py", "tools/wine_replay_job.py", "tools/wine_run.py"]
    if a.host:
        argv += ["--host", a.host]
    if a.role:      # one side of a cross-host pair
        argv += ["--", "python", "tools/lockstep_test.py", "peer", "--role", a.role, "--img", "ls-img", "--rec",
                 "ls-img/rec.hrp" if a.role == "send" else "ls-img/hdr.hrp", "--out", "ls-out", "--bind", str(a.ports),
                 "--peer", a.peer, "--frames", str(a.frames + (a_extra(a.lead) if a.role == "send" else 0)), "--fps", str(a.fps),
                 "--lead", str(a.lead), "--timeout", str(a.timeout), "--shim-out=" + (a.shim or "")]
    else:
        argv += ["--", "python", "tools/lockstep_test.py", "pair", "--img", "ls-img", "--rec", "ls-img/rec.hrp", "--hdr",
                 "ls-img/hdr.hrp", "--out", "ls-out", "--frames", str(a.frames), "--fps", str(a.fps), "--lead",
                 str(a.lead), "--timeout", str(a.timeout), "--ports", str(a.ports), "--shim=" + (a.shim or "")]
    for e in a.env or []:
        argv += ["--env", e]
    r = subprocess.run(argv, capture_output=True, text=True)
    if r.returncode:
        sys.exit(r.stderr or r.stdout)
    print(r.stdout.strip())


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="c", required=True)
    s = sp.add_parser("strip")
    s.add_argument("rec")
    s.add_argument("out")

    def common(p):
        p.add_argument("--img", required=True)
        p.add_argument("--rec", default=os.path.join(ROOT, "build/rp1/play3.hrp"))
        p.add_argument("--frames", type=int, default=9000)
        p.add_argument("--fps", type=int, default=30, help="HULK_FPS_CAP (0: unpaced)")
        p.add_argument("--lead", type=int, default=8, help="HULK_NET_LEAD: frames A may run ahead of B's last report")
        p.add_argument("--timeout", type=int, default=1800)
        p.add_argument("--env", action="append", help="K=V for both instances")
    p = sp.add_parser("pair")
    common(p)
    p.add_argument("--hdr", required=True)
    p.add_argument("--out", required=True)
    p.add_argument("--shim", default="", help="netshim model arguments; empty: no shim")
    p.add_argument("--ports", type=int, default=41000)
    p.add_argument("--b-delay", type=float, default=2.0, help="seconds between starting A and B")
    p = sp.add_parser("peer")
    common(p)
    p.add_argument("--role", choices=["send", "recv"], required=True)
    p.add_argument("--out", required=True)
    p.add_argument("--bind", type=int, required=True)
    p.add_argument("--peer", required=True)
    p.add_argument("--shim-out", default="", help="netshim model arguments for this side's outgoing packets")
    p = sp.add_parser("submit")
    common(p)
    p.add_argument("--name", required=True)
    p.add_argument("--hdr", required=True)
    p.add_argument("--host")
    p.add_argument("--shim", default="", help="pair: the shim's model; peer (--role): this side's outgoing shim")
    p.add_argument("--ports", type=int, default=41000, help="pair: the first of four ports; peer: the bind port")
    p.add_argument("--role", choices=["send", "recv"], help="submit one side of a cross-host pair")
    p.add_argument("--peer", help="with --role: the other host's A.B.C.D:PORT")
    p = sp.add_parser("summary")
    p.add_argument("dirs", nargs="+")
    a = ap.parse_args()
    return {"strip": cmd_strip, "pair": cmd_pair, "peer": cmd_peer, "submit": cmd_submit, "summary": cmd_summary}[a.c](a)


if __name__ == "__main__":
    sys.exit(main())
