#!/bin/sh
# Run a farm lane over a queue in batches, committing + pushing after each batch.
# Stops when the queue is done or a budget/credit stop is hit.
# Usage: farm/lane.sh LANE QUEUE TIERS [batch] [concurrency]
set -u
cd "$(dirname "$0")/.."
LANE=$1; QUEUE=$2; TIERS=$3; BATCH=${4:-48}; CONC=${5:-12}
PY=build/venv/bin/python
IDLE=0
LOG=build/farm/lane-$LANE.log
while :; do
    farm/run.sh --lane "$LANE" --queue "$QUEUE" --tiers "$TIERS" --limit "$BATCH" --concurrency "$CONC" >> "$LOG" 2>&1
    $PY tools/progress.py --readme >> "$LOG" 2>&1
    git add matches README.md
    if git diff --cached --quiet; then
        IDLE=$((IDLE + 1))
    else
        IDLE=0
        n=$(git diff --cached --name-only -- matches | wc -l | tr -d ' ')
        git commit -q -m "Lane $LANE: +$n matched functions

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_01DM8Bn5TvuystUL5qBzT4rA" && { git pull -q --rebase origin main && git push -q; } >> "$LOG" 2>&1
    fi
    # Already-finished jobs replay instantly at $0, so a queue of only those never hits "0 functions".
    [ "$IDLE" -ge 3 ] && { echo "== stalled: 3 chunks with no new matches" >> "$LOG"; break; }
    tail -60 "$LOG" | grep -q 'farm: 0 functions' && break
    tail -60 "$LOG" | grep -q 'skipping paid tiers' && break
done
echo "== lane $LANE done $(date)" >> "$LOG"
