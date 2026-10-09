#!/bin/sh
# Overnight local matching: run a local endpoint over everything the cloud didn't finish, in batches,
# committing after each batch, until at least $UNTIL (then finish the current batch and exit).
# Usage: farm/night.sh [until "YYYY-MM-DD HH:MM"] [tiers] [batch] [concurrency]
set -u
cd "$(dirname "$0")/.."
UNTIL=${1:-"2026-10-09 07:00"}
TIERS=${2:-farm/tiers-night.json}
BATCH=${3:-24}
CONC=${4:-4}
PY=build/venv/bin/python
LOG=build/farm/night.log
END=$(date -j -f "%Y-%m-%d %H:%M" "$UNTIL" +%s)
LANE=night

commit() {
    $PY tools/shapes.py propagate --jobs 8 >> "$LOG" 2>&1
    $PY tools/progress.py --readme >> "$LOG" 2>&1
    git add matches README.md
    if ! git diff --cached --quiet; then
        n=$(git diff --cached --name-only -- matches | wc -l | tr -d ' ')
        git commit -q -m "Night lane: +$n matched functions

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_01DM8Bn5TvuystUL5qBzT4rA" && { git pull -q --rebase origin main && git push -q; } >> "$LOG" 2>&1
    fi
}

echo "== night start $(date), until $UNTIL" >> "$LOG"
while [ "$(date +%s)" -lt "$END" ]; do
    # Queue: shapes the cloud never finished (smallest first), then cloud-exhausted near-misses.
    $PY - "$LANE" > build/farm/night-queue.txt <<'PY'
import json, os, sys, csv
lane = sys.argv[1]
done_lane = set()
lp = f"build/farm/lanes/{lane}.jsonl"
if os.path.exists(lp):
    done_lane = {json.loads(l)["addr"] for l in open(lp) if l.strip() and json.loads(l)["status"] != "failed"}
size = {"0x%08x" % int(r["address"], 16): int(r["size"]) for r in csv.DictReader(open("build/functions.csv"))}
best, touched = {}, set()
for l in open("build/farm/results.jsonl"):
    r = json.loads(l)
    touched.add(r["addr"])
    if r["status"] in ("exhausted", "gave_up"):
        best[r["addr"]] = max(best.get(r["addr"], 0), r["bestScore"])
have = lambda a: os.path.exists(f"matches/{a}.cpp")
reps = [l.strip() for l in open("build/farm/queue-unique.txt") if l.strip()]
untried = [a for a in reps if a not in touched and not have(a) and a not in done_lane]
misses = sorted((a for a in best if not have(a) and a not in done_lane), key=lambda a: -best[a])
for a in untried + misses:
    print(a)
PY
    if [ ! -s build/farm/night-queue.txt ]; then echo "queue empty $(date)" >> "$LOG"; sleep 600; continue; fi
    farm/run.sh --lane "$LANE" --queue build/farm/night-queue.txt --tiers "$TIERS" --limit "$BATCH" --concurrency "$CONC" >> "$LOG" 2>&1
    commit
done
commit
echo "== night done $(date)" >> "$LOG"
