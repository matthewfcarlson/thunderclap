#!/bin/sh
# Overnight permuter: score every pending near-miss in the permute queues, then permute the closest
# first in chunks, committing + pushing after each chunk, until $UNTIL or the queue runs out.
# Usage: farm/permute-night.sh [until "YYYY-MM-DD HH:MM"] [minutes per function] [chunk]
set -u
cd "$(dirname "$0")/.."
UNTIL=${1:-"$(date -v+1d +%Y-%m-%d) 08:00"}
MIN=${2:-3}
CHUNK=${3:-20}
PY=build/venv/bin/python
LOG=build/farm/permute-night.log
Q=build/farm/queue-permute-night.txt
END=$(date -j -f "%Y-%m-%d %H:%M" "$UNTIL" +%s)

echo "== permute night start $(date), until $UNTIL" >> "$LOG"
# Closest misses first: score each queue entry's source once (parallel compiles).
$PY - "$Q" >> "$LOG" 2>&1 <<'PY'
import glob, json, os, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
out = sys.argv[1]
done = set()
if os.path.exists("build/farm/permute/log.jsonl"):
    done = {json.loads(l)["addr"] for l in open("build/farm/permute/log.jsonl") if l.strip()}
entries = {}
for q in sorted(glob.glob("build/farm/queue-permute*.txt")):
    if q.endswith("-night.txt"):
        continue
    for line in open(q):
        p = line.split()
        if len(p) == 2 and p[0] not in done and not os.path.exists(f"matches/{p[0]}.cpp") and os.path.exists(p[1]):
            entries.setdefault(p[0], p[1])
def score(item):
    addr, src = item
    r = subprocess.run(["build/venv/bin/python", "tools/compare.py", src, addr, "--json"], capture_output=True, text=True)
    try:
        return json.loads(r.stdout).get("score", -1), addr, src
    except Exception:
        return -1, addr, src
with ThreadPoolExecutor(6) as ex:
    scored = sorted(ex.map(score, entries.items()), reverse=True)
with open(out, "w") as f:
    for s, a, src in scored:
        if s > 0:
            f.write(f"{a} {src}\n")
print(f"permute night: {sum(s > 0 for s, _, _ in scored)} queued of {len(scored)} pending")
PY

commit() {
    $PY tools/progress.py --readme >> "$LOG" 2>&1
    git add matches README.md
    if ! git diff --cached --quiet; then
        n=$(git diff --cached --name-only -- matches | wc -l | tr -d ' ')
        git commit -q -m "Permute night: +$n matched functions

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_011A8Mi5d28UHDdVom8hvHuu"
        # Other sessions may leave uncommitted edits; autostash so the rebase isn't refused.
        { git push -q || { git pull -q --rebase --autostash origin main && git push -q; }; } >> "$LOG" 2>&1
    fi
}

TOTAL=$(wc -l < "$Q" | tr -d ' ')
i=0
while [ "$i" -lt "$TOTAL" ] && [ "$(date +%s)" -lt "$END" ]; do
    sed -n "$((i + 1)),$((i + CHUNK))p" "$Q" > build/farm/queue-permute-night-chunk.txt
    $PY tools/permute.py --queue build/farm/queue-permute-night-chunk.txt --minutes "$MIN" --install --skip-done >> "$LOG" 2>&1
    commit
    i=$((i + CHUNK))
done
echo "== permute night done $(date)" >> "$LOG"
