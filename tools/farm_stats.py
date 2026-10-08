#!/usr/bin/env python3
"""Summarize build/farm/results.jsonl: success and cost per tier/model, overall cost per match."""
import json
import os
import sys
from collections import defaultdict

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "build/farm/results.jsonl")
rows = [json.loads(l) for l in open(path) if l.strip()]

by = defaultdict(lambda: {"runs": 0, "match": 0, "cost": 0.0, "input": 0, "output": 0, "cache": 0, "secs": 0, "att": 0})
for r in rows:
    b = by[(r["tier"], r["model"])]
    b["runs"] += 1
    b["match"] += r["status"] == "match"
    b["cost"] += r["cost"]
    b["input"] += r["input"]
    b["output"] += r["output"]
    b["cache"] += r.get("cacheRead", 0)
    b["secs"] += r["secs"]
    b["att"] += r["attempts"]

print("%-4s %-42s %5s %6s %7s %9s %10s %8s %6s" % ("tier", "model", "runs", "match", "rate", "cost", "$/match", "tok/run", "att"))
for (t, m), b in sorted(by.items()):
    print("%-4d %-42s %5d %6d %6.0f%% %9.4f %10.4f %8d %6.1f" % (
        t, m, b["runs"], b["match"], 100 * b["match"] / b["runs"], b["cost"],
        b["cost"] / b["match"] if b["match"] else float("nan"),
        (b["input"] + b["output"]) / b["runs"], b["att"] / b["runs"]))

addrs = {r["addr"] for r in rows}
matched = {r["addr"] for r in rows if r["status"] == "match"}
total = sum(r["cost"] for r in rows)
print("\nfunctions attempted %d, matched %d (%.0f%%), total $%.4f, $%.4f per match" % (
    len(addrs), len(matched), 100 * len(matched) / max(len(addrs), 1), total, total / max(len(matched), 1)))
statuses = defaultdict(int)
for r in rows:
    statuses[r["status"]] += 1
print("run outcomes:", dict(statuses))
