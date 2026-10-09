#!/usr/bin/env python3
"""Pick the next round of mid-size functions for matching subagents.

  tools/agent_round.py ROUND [--agents 8] [--per 8]
Writes build/farm/agents/rROUND_bN.txt. Order: Luna near-misses (best score desc), then untried
shapes interleaved so families don't cluster. Skips anything matched or already given to an agent.
"""
import argparse, glob, json, os

p = argparse.ArgumentParser()
p.add_argument("round", type=int)
p.add_argument("--agents", type=int, default=8)
p.add_argument("--per", type=int, default=8)
a = p.parse_args()

given = set()
for f in glob.glob("build/farm/agents/*.txt"):
    given |= {l.strip() for l in open(f) if l.strip()}
have = lambda x: os.path.exists(f"matches/{x}.cpp")
near = {}
for f in ["build/farm/lanes/luna-mid.jsonl", "build/farm/lanes/sonnet-mid.jsonl"]:
    if os.path.exists(f):
        for l in open(f):
            r = json.loads(l)
            if r["status"] in ("exhausted", "gave_up"):
                near[r["addr"]] = max(near.get(r["addr"], 0), r["bestScore"])
first = sorted((x for x in near if x not in given and not have(x)), key=lambda x: -near[x])
q = [l.strip() for l in open("build/farm/queue-mid.txt") if l.strip()]
rest = [x for x in q if x not in given and not have(x) and x not in near]
inter = []
for k in range(7):
    inter += rest[k::7]
# At most one function per family of near-identical code per round (3-gram Jaccard >= 0.75):
# a batch of 8 copies of one hard function wastes an agent. Siblings follow once one is solved.
import sys
sys.path.insert(0, "tools")
from similar import grams, tokens
from xbe import Xbe
import csv
_x = Xbe("isos/extracted/default.xbe")
_size = {"0x%08x" % int(r["address"], 16): int(r["size"]) for r in csv.DictReader(open("build/functions.csv"))}
reps = []
fail_reps = []
for f in glob.glob("build/farm/agents/*.jsonl"):
    for l in open(f):
        r = json.loads(l)
        if r.get("status") != "match":
            fail_reps.append(grams(tokens(_x, int(r["addr"], 16), _size[r["addr"]])))
pick = []
for x in first + inter:
    g = grams(tokens(_x, int(x, 16), _size[x]))
    if any(len(g & h) / max(len(g | h), 1) >= 0.75 for h in reps + fail_reps):
        continue
    reps.append(g)
    pick.append(x)
    if len(pick) == a.agents * a.per:
        break
for i in range(a.agents):
    with open(f"build/farm/agents/r{a.round}_b{i + 1}.txt", "w") as f:
        f.write("".join(x + "\n" for x in pick[i * a.per:(i + 1) * a.per]))
with open(f"build/farm/agents/r{a.round}_all.lst", "w") as f:
    f.write("".join(x + "\n" for x in pick))
print("round %d: %d functions (%d near-misses first)" % (a.round, len(pick), min(len(first), len(pick))))
