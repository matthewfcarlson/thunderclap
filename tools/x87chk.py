#!/usr/bin/env python3
"""The x87 leak check of the Wine build (docs/native-float64.md "Checking for x87 leaks"): a HULK_X87CHK=1 Wine build
checks the x87 stack at the entry of every game function and XDK stand-in during a replay; a clean run logs no event.

  tools/x87chk.py submit [wine_build_job submit options]     # queue the measurement build: prints the job id
  tools/x87chk.py check JOB|TRACE [--frames N]                # its result: exit 0 iff the checks ran and logged nothing

`submit` is `tools/wine_build_job.py submit` with `--env HULK_X87CHK=1` and the defaults `--name x87chk --gfx --replay
play3 --frames 60000` (any of them can be given instead). Run it on its own lineage, or one whose next build may relink
anyway: the measurement image is not the proof image. `check` reads build/jobs/out/JOB/nb-out (after
`wine_build_job.py wait JOB`): the link's entry-check count (link-report.json), the `x87chk armed` line, the replay's
last checkpoint, and the `x87chk` / `x87chain` events, grouped by the function entered and its caller.
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EVENT = re.compile(r"^x87chk (\d+) f=(\d+) tid=\d+ sw=([0-9a-f]+) top (\d)->(\d) fn=(0x[0-9a-f]+) site=\S+ "
                   r"caller=(0x[0-9a-f]+\+0x[0-9a-f]+) prev=(0x[0-9a-f]+) prevsite=\S+ prevcaller=(\S+)")
CKPT = re.compile(r"\bckpt frame (\d+) hash")


def submit(rest):
    have = {a.split("=")[0] for a in rest if a.startswith("--")}
    args = ["--env", "HULK_X87CHK=1"]
    for opt, val in (("--name", "x87chk"), ("--gfx", None), ("--replay", "play3"), ("--frames", "60000")):
        if opt not in have:
            args += [opt] + ([val] if val else [])
    cmd = [sys.executable, os.path.join(ROOT, "tools/wine_build_job.py"), "submit"] + args + rest
    sys.exit(subprocess.call(cmd))


def link_checks(out):
    """The link's entry-check count (link-report.json), or None."""
    p = os.path.join(out, "link-report.json")
    if not os.path.exists(p):
        return None
    found = []

    def walk(o):
        if isinstance(o, dict):
            for k, v in o.items():
                if k.startswith("x87chk entry check") and isinstance(v, int):
                    found.append(v)
                walk(v)
    walk(json.load(open(p)))
    return max(found) if found else 0


def check(x, frames):
    if os.path.isfile(x):
        out, trace = os.path.dirname(x), x
    else:
        out = os.path.join(ROOT, "build/jobs/out", x, "nb-out")
        trace = os.path.join(out, "trace.txt")
        if not os.path.exists(trace):
            sys.exit("no %s (tools/wine_build_job.py wait %s first)" % (trace, x))
    n_link = link_checks(out)
    armed, last, events, chains = None, None, [], 0
    for l in open(trace, errors="replace"):
        l = l.strip()
        if l.startswith("x87chk armed:"):
            armed = int(l.split()[2])
        elif l.startswith("x87chk "):
            m = EVENT.match(l)
            events.append(m.groups() if m else (l,))
        elif l.startswith("x87chain "):
            chains += 1
        else:
            m = CKPT.search(l)
            if m:
                last = int(m.group(1))
    print("link entry checks: %s" % ("?" if n_link is None else n_link))
    print("armed at start-up: %s" % ("no (not a HULK_X87CHK image)" if armed is None else armed))
    print("last checkpoint:   %s%s" % (last, "" if frames is None else " (want %d)" % frames))
    print("events:            %d (%d with a frame chain)" % (len(events), chains))
    if events:
        full = [e for e in events if len(e) > 2 and int(e[2], 16) & 0x80000000]
        top = [e for e in events if len(e) > 2 and not int(e[2], 16) & 0x80000000]
        print("  TOP moved: %d, st(0) full: %d; first at frame %s" % (len(top), len(full), events[0][1]))
        by = collections.Counter((e[5], e[6]) for e in events if len(e) > 2)
        for (fn, caller), n in by.most_common(12):
            print("  %6d  fn %s  from %s" % (n, fn, caller))
    ok = armed is not None and armed > 0 and not events and last is not None and (frames is None or last >= frames)
    print("X87CHK %s" % ("ok" if ok else "FAILED"))
    return 0 if ok else 1


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "submit":
        submit(sys.argv[2:])
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("submit", help="queue a HULK_X87CHK=1 Wine build (wine_build_job submit options follow)")
    c = sub.add_parser("check", help="read a finished run's trace")
    c.add_argument("job", help="job id or trace.txt")
    c.add_argument("--frames", type=int, default=None, help="the replay must reach a checkpoint at this frame")
    a = ap.parse_args()
    sys.exit(check(a.job, a.frames))


if __name__ == "__main__":
    main()
