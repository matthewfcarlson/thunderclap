#!/usr/bin/env python3
"""Bisect a failing hybrid build down to the patched function(s) responsible (task 10, section 3).

  tools/bisect_hybrid.py --matches all [--equivalent] [--classes identical,local,equivalent]
                         [--replay R] [--seconds 45] [--max-runs 30]

A build passes when it reaches the title, keeps running, and its checkpoints match the hooks-only
baseline on the same replay (tools/hybrid_test.py compare). The patched set is split in halves (in
address order, so subsystems stay together); a failing half is kept; if both halves pass alone, the
failure needs functions from both, and each half is bisected with the other half kept patched.
Every run is logged to build/hybrid/test/bisect.jsonl.
"""
import argparse
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hybrid_test  # noqa: E402

LOG = os.path.join(hybrid_test.TEST_DIR, "bisect.jsonl")


class Bisect:
    def __init__(self, args, recs):
        self.args = args
        self.recs = {r["addr"]: r for r in recs if r.get("status") == "ok"}
        self.runs = 0
        self.cache = {}
        os.makedirs(hybrid_test.TEST_DIR, exist_ok=True)
        self.baseline = hybrid_test.build_and_run("baseline", [], args.replay, args.seconds)

    def passes(self, addrs):
        key = tuple(sorted(addrs))
        if key in self.cache:
            return self.cache[key]
        if self.runs >= self.args.max_runs:
            raise RuntimeError("run budget exhausted")
        self.runs += 1
        recs = [dict(self.recs[a]) for a in key]
        t0 = time.time()
        v = hybrid_test.compare(self.args, recs, name="bisect", baseline=self.baseline)
        ok = v["pass"]
        with open(LOG, "a") as f:
            f.write(json.dumps({"n": len(key), "first": "%#x" % key[0] if key else None,
                                "last": "%#x" % key[-1] if key else None, "pass": ok, "verdict": v,
                                "time": round(time.time() - t0)}) + "\n")
        print("  run %d: %d functions %s -> %s" % (self.runs, len(key),
              ("%#x..%#x" % (key[0], key[-1])) if key else "", "pass" if ok else "FAIL (%s)" % _why(v)),
              file=sys.stderr)
        self.cache[key] = ok
        return ok

    def culprits(self, cand, keep=()):
        """Minimal failing subset of cand (with `keep` always patched)."""
        if len(cand) == 1:
            return list(cand)
        half = len(cand) // 2
        a, b = cand[:half], cand[half:]
        if not self.passes(list(keep) + a):
            return self.culprits(a, keep)
        if not self.passes(list(keep) + b):
            return self.culprits(b, keep)
        # interaction: something in a needs something in b
        return self.culprits(a, list(keep) + b) + self.culprits(b, list(keep) + a)


def _why(v):
    if not v["title"]:
        return "no title"
    if v["exited"]:
        return "exited"
    if v["divergence"]:
        return "diverged at frame %d" % v["divergence"]["frame"]
    return "no common checkpoints"


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    hybrid_test.add_selection_args(ap)
    ap.add_argument("--replay", default=hybrid_test.DEFAULT_REPLAY)
    ap.add_argument("--seconds", type=float, default=45)
    ap.add_argument("--max-runs", type=int, default=30)
    ap.add_argument("--max-frame", type=int, default=hybrid_test.MAX_FRAME)
    ap.add_argument("--coverage", action="store_true", help="count functions run in each bisect build")
    args = ap.parse_args(argv)
    recs = hybrid_test.select_records(args)
    b = Bisect(args, recs)
    cand = sorted(b.recs)
    print("bisecting %d patched functions" % len(cand), file=sys.stderr)
    if b.passes(cand):
        print(json.dumps({"result": "pass", "patched": len(cand), "runs": b.runs}))
        return 0
    try:
        bad = b.culprits(cand)
    except RuntimeError as e:
        print(json.dumps({"result": "incomplete", "error": str(e), "runs": b.runs}))
        return 2
    out = {"result": "fail", "runs": b.runs,
           "culprits": [{"addr": "%#x" % a, "name": b.recs[a].get("name"), "src": b.recs[a]["src"],
                         "class": b.recs[a]["class"]} for a in bad]}
    print(json.dumps(out, indent=1))
    return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
