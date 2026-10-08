#!/usr/bin/env python3
"""Compare models across build/farm/bench/*.jsonl (one isolated single-tier run per model)."""
import glob
import json
import os
import statistics

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
print("%-36s %4s %6s %6s %8s %9s %9s %7s %6s" % ("model", "runs", "match", "rate", "cost", "$/match", "tok/run", "p50 s", "fail"))
for path in sorted(glob.glob(os.path.join(ROOT, "build/farm/bench/*.jsonl"))):
    rows = [json.loads(l) for l in open(path) if l.strip()]
    if not rows:
        continue
    m = sum(r["status"] == "match" for r in rows)
    cost = sum(r["cost"] for r in rows)
    tok = sum(r["input"] + r["output"] for r in rows) / len(rows)
    secs = statistics.median(r["secs"] for r in rows)
    fail = sum(r["status"] == "failed" for r in rows)
    print("%-36s %4d %6d %5.0f%% %8.4f %9s %9d %7d %6d" % (
        rows[0]["model"].replace("openrouter/", ""), len(rows), m, 100 * m / len(rows), cost,
        "%.4f" % (cost / m) if m else "-", tok, secs, fail))
