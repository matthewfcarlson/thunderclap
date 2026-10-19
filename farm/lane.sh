#!/bin/sh
# Run a farm lane over a queue in batches, committing + pushing after each batch.
# Stops when the queue is done or a budget/credit stop is hit.
# Usage: [MODE=equiv] [FARM_EXTRA=--upgrade] farm/lane.sh LANE QUEUE TIERS [batch] [concurrency]
# Subscription tiers that hit their usage window (429) wait it out instead of stopping the lane.
set -u
cd "$(dirname "$0")/.."
LANE=$1; QUEUE=$2; TIERS=$3; BATCH=${4:-48}; CONC=${5:-12}
PY=build/venv/bin/python
IDLE=0
LOG=build/farm/lane-$LANE.log
while :; do
    START=$(wc -l < "$LOG" 2>/dev/null || echo 0)
    farm/run.sh --lane "$LANE" --mode "${MODE:-match}" --queue "$QUEUE" --tiers "$TIERS" --limit "$BATCH" --concurrency "$CONC" ${FARM_EXTRA:-} >> "$LOG" 2>&1
    $PY tools/progress.py --readme >> "$LOG" 2>&1
    # Stage only this lane's own results: other agents leave files in matches/ and equivalent/ that
    # they commit themselves, and sweeping them in mislabels the commit.
    for a in $(tail -n "$BATCH" "build/farm/lanes/$LANE.jsonl" 2>/dev/null | grep -E '"status":"(match|equivalent)"' | grep -oE '"addr":"0x[0-9a-f]+"' | cut -d'"' -f4); do
        # (git add -A also stages an equivalent/ copy that --upgrade removed after a match)
        for f in "matches/$a.cpp" "equivalent/$a.cpp"; do { [ -e "$f" ] || git ls-files --error-unmatch "$f" >/dev/null 2>&1; } && git add -A -- "$f"; done
    done
    git add README.md
    if git diff --cached --quiet; then
        IDLE=$((IDLE + 1))
    else
        IDLE=0
        n=$(git diff --cached --name-only -- matches | wc -l | tr -d ' ')
        e=$(git diff --cached --name-only -- equivalent | wc -l | tr -d ' ')
        git commit -q -m "Lane $LANE: +$n matched, +$e equivalent functions

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_011A8Mi5d28UHDdVom8hvHuu" && { git push -q || { git pull -q --no-rebase --no-edit origin main && git push -q; }; } >> "$LOG" 2>&1
    fi
    # Usage window exhausted: most of the last batch failed with 429. Wait, and don't count it as a stall.
    if [ "$(tail -n "$BATCH" "build/farm/lanes/$LANE.jsonl" 2>/dev/null | grep '"failed"' | grep -Eci '429|usage limit')" -ge $((BATCH / 2)) ]; then
        echo "== usage limit $(date); waiting 30 min" >> "$LOG"; IDLE=0; sleep 1800; continue
    fi
    # Already-finished jobs replay instantly at $0, so a queue of only those never hits "0 functions".
    [ "$IDLE" -ge 3 ] && { echo "== stalled: 3 chunks with no new matches" >> "$LOG"; break; }
    # Only this batch's output: an older run's "0 functions" line must not stop a new run.
    tail -n +"$((START + 1))" "$LOG" | grep -Eq 'farm( \(equivalent mode\))?: 0 functions' && break
    tail -n +"$((START + 1))" "$LOG" | grep -q 'skipping paid tiers' && break
done
echo "== lane $LANE done $(date)" >> "$LOG"
