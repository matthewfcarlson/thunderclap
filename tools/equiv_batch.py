#!/usr/bin/env python3
"""Run tools/equiv.py over a list of sources in parallel and write one JSON line per result.

For offloading equivalence checks to another machine with the same checkout (e.g. a remote Mac):
the results come back as a JSONL file, and the full report of each run is kept for review.

Usage:
  tools/equiv_batch.py LIST OUT.jsonl [--jobs N] [--jobq [--name AGENT] [--per N]] [-- extra equiv.py args]
--jobq sends the checks through the shared queue (tools/jobq.py: spread over all hosts) instead of running them here.
LIST has one "0xADDR path/to/source.cpp" per line. Lines already in OUT.jsonl are skipped, so an
interrupted run resumes where it stopped.
"""
import argparse
import json
import os
import subprocess
import sys
from multiprocessing import Pool

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXTRA = []


def run(item):
    addr, src = item
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/equiv.py"), src, addr, "--json", *EXTRA],
                       capture_output=True, text=True, cwd=ROOT)
    try:
        rep = json.loads(r.stdout)
    except ValueError:
        return {"addr": addr, "src": src, "status": "error", "detail": (r.stderr or r.stdout)[-300:]}
    l3 = rep.get("level3") or {}
    return {"addr": addr, "src": src, "status": rep.get("status"), "args": EXTRA,
            "conflicts": bool((rep.get("level2") or {}).get("conflicts")),
            "inputs_run": l3.get("inputs_run"), "coverage": l3.get("coverage"), "target": rep.get("target")}


def init(extra):
    EXTRA[:] = extra


def main():
    argv = sys.argv[1:]
    extra = argv[argv.index("--") + 1:] if "--" in argv else []
    argv = argv[:argv.index("--")] if "--" in argv else argv
    p = argparse.ArgumentParser()
    p.add_argument("list")
    p.add_argument("out")
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--jobq", action="store_true", help="run through tools/jobq.py")
    p.add_argument("--name", default=os.environ.get("USER", "agent"), help="submitter name for --jobq")
    p.add_argument("--per", type=int, default=2, help="functions per job for --jobq")
    a = p.parse_args(argv)
    if a.jobq:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import jobq_equiv
        items = [tuple(l.split()[:2]) for l in open(a.list) if l.strip()]
        res = jobq_equiv.run_items(a.name, items, a.out, extra, a.per)
        return sys.exit(1 if any(i not in res for i, _ in items) else 0)
    done = set()
    if os.path.exists(a.out):
        done = {json.loads(l)["addr"] for l in open(a.out) if l.strip()}
    items = [tuple(l.split()[:2]) for l in open(a.list) if l.strip()]
    items = [i for i in items if i[0] not in done]
    print("%d to check (%d already done)" % (len(items), len(done)), flush=True)
    with open(a.out, "a") as out, Pool(a.jobs, initializer=init, initargs=(extra,)) as pool:
        for r in pool.imap_unordered(run, items):
            out.write(json.dumps(r) + "\n")
            out.flush()


if __name__ == "__main__":
    main()
