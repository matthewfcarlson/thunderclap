#!/bin/sh
# Pull permuter matches from remote Macs, re-verify locally, install, commit + push. Loops every 10 min.
# Usage: farm/collect_remote.sh user@host [user@host ...]
# The path is home-relative (~/): openrsync on macOS 15 mangles a bare relative remote path.
set -u
cd "$(dirname "$0")/.."
PY=build/venv/bin/python
LOG=build/farm/collect-remote.log
while :; do
    n=0
    for h in "$@"; do
        d=build/farm/remote/$(echo "$h" | tr '@' '_')
        mkdir -p "$d"
        rsync -az -e 'ssh -o BatchMode=yes -o ConnectTimeout=10' "$h:~/hulk-permute/matches/" "$d/" >> "$LOG" 2>&1 || continue
        for f in "$d"/0x*.cpp; do
            [ -e "$f" ] || continue
            a=$(basename "$f" .cpp)
            [ -e "matches/$a.cpp" ] && continue
            grep -qE '__asm|_emit|naked|#[[:space:]]*pragma' "$f" && continue
            s=$($PY tools/verify_relocs.py "$f" --addr "$a" --json 2>/dev/null | python3 -I -c "import json,sys; print(json.load(sys.stdin)['status'])" 2>/dev/null)
            if [ "$s" = ok ]; then
                cp "$f" "matches/$a.cpp" && $PY tools/format_matches.py "matches/$a.cpp" --jobs 1 > /dev/null 2>&1
                n=$((n+1)); echo "$(date +%T) $h $a verified" >> "$LOG"
            else
                echo "$(date +%T) $h $a rejected ($s)" >> "$LOG"
            fi
        done
    done
    if [ $n -gt 0 ]; then
        git add matches && git commit -q -m "Remote permuters: +$n matched functions

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
Claude-Session: https://claude.ai/code/session_01DM8Bn5TvuystUL5qBzT4rA" -- matches && { git pull -q --rebase --autostash origin main && git push -q; } >> "$LOG" 2>&1
    fi
    sleep 600
done
