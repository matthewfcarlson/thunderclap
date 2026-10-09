#!/bin/sh
# Unattended sweep: farm in chunks, propagate to identical shapes, update README status, commit + push.
# Usage: farm/sweep.sh [queue] [tiers] [concurrency] [budget] [chunk]
set -u
cd "$(dirname "$0")/.."
QUEUE=${1:-build/farm/queue-unique.txt}
TIERS=${2:-farm/tiers-luna-haiku.json}
CONC=${3:-48}
BUDGET=${4:-15}
CHUNK=${5:-400}
PY=build/venv/bin/python
LOG=build/farm/sweep.log

# One process per farm database: wait for any other default-db farm run to finish.
while pgrep -f 'farm/src/farm.ts --queue' >/dev/null; do sleep 30; done

while :; do
    echo "== chunk start $(date)" >> "$LOG"
    farm/run.sh --queue "$QUEUE" --tiers "$TIERS" --limit "$CHUNK" --concurrency "$CONC" --budget "$BUDGET" >> "$LOG" 2>&1
    $PY tools/shapes.py propagate --jobs 8 >> "$LOG" 2>&1
    $PY tools/progress.py --readme >> "$LOG" 2>&1
    git add matches README.md
    if ! git diff --cached --quiet; then
        n=$(git diff --cached --name-only -- matches | wc -l | tr -d ' ')
        git commit -q -m "Farm sweep: +$n matched functions

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_01DM8Bn5TvuystUL5qBzT4rA" && { git pull -q --rebase origin main && git push -q; } >> "$LOG" 2>&1
    fi
    # Stop when the farm has nothing left to do or the budget stopped paid tiers.
    tail -40 "$LOG" | grep -q 'farm: 0 functions' && break
    # Every stop reason (ledger budget, key limit, 402 out of credits) ends with this phrase.
    tail -40 "$LOG" | grep -q 'skipping paid tiers' && break
done
echo "== sweep done $(date)" >> "$LOG"
