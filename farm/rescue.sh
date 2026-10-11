#!/bin/sh
# Free rescue lane: keep retrying functions the cloud tiers exhausted, on a local endpoint.
# Matches land in matches/ (the sweep's next commit picks them up).
# Usage: farm/rescue.sh [lane] [tiers] [batch] [concurrency]
set -u
cd "$(dirname "$0")/.."
LANE=${1:-mac2}
TIERS=${2:-farm/tiers-rescue-mac2.json}
BATCH=${3:-20}
CONC=${4:-4}
PY=build/venv/bin/python
LOG=build/farm/rescue-$LANE.log
while :; do
    $PY - "$LANE" > build/farm/rescue-$LANE.txt <<'PY'
import json, os, sys
lane = sys.argv[1]
tried = set()
lp = f"build/farm/lanes/{lane}.jsonl"
if os.path.exists(lp):
    tried = {json.loads(l)["addr"] for l in open(lp) if l.strip() and json.loads(l)["status"] != "failed"}
best = {}
for l in open("build/farm/results.jsonl"):
    r = json.loads(l)
    if r["status"] in ("exhausted", "gave_up"):
        best[r["addr"]] = max(best.get(r["addr"], 0), r["bestScore"])
todo = [a for a in best if a not in tried and not os.path.exists(f"matches/{a}.cpp")]
for a in sorted(todo, key=lambda a: -best[a]):  # closest misses first
    print(a)
PY
    if [ ! -s build/farm/rescue-$LANE.txt ]; then sleep 120; continue; fi
    farm/run.sh --lane "$LANE" --queue build/farm/rescue-$LANE.txt --tiers "$TIERS" --limit "$BATCH" --concurrency "$CONC" >> "$LOG" 2>&1
done
