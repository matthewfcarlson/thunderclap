#!/bin/sh
# native_linux_replay.sh IMAGE RECORDING DATA OUT [WINE_CKPT]: a headless replay of the x86-64 Linux native image.
#
# Runs on the Linux box (directly, or as a queue job: docs/native-float64.md "Linux replay"). IMAGE is the native
# link's hulk-linux (tools/native_elf.py link --target linux-x64 --ld, with SDL3: tools/native_linux_sdl.py), RECORDING
# a .hrp (build/rp1/play3.hrp), DATA the player's extracted disc (isos/extracted, with default.xbe), OUT a fresh
# directory. Writes OUT/trace.txt, OUT/stdout.txt, OUT/ckpt.txt (`frame hash` lines, the format tools/wine_replay_job.py
# compares) and OUT/result.txt. With WINE_CKPT (a Wine replay's ckpt.txt of the same recording, e.g.
# build/jobs/out/ID/nb-out/ckpt.txt), it also compares the two: common frames, identical, first differing frame.
#
# Environment (optional): FRAMES (stop once this checkpoint frame is written, default 60000), HANG (seconds
# without a frame before the run is called hung, default 120), HULK_NATIVE_MISSING=continue (survey mode: a missing
# name logs and returns 0; never a result).
set -u
IMG=$1; REC=$2; DATA=$3; OUT=$4; WCK=${5:-}
[ "$(uname -s)" = Linux ] || { echo "native_linux_replay.sh: run this on x86-64 Linux" >&2; exit 2; }
[ -x "$IMG" ] || { echo "no image $IMG" >&2; exit 2; }
[ -f "$REC" ] || { echo "no recording $REC" >&2; exit 2; }
[ -f "$DATA/default.xbe" ] || { echo "no extracted disc at $DATA (default.xbe)" >&2; exit 2; }
mkdir -p "$OUT/save" "$OUT/tdata" "$OUT/udata"
OUT=$(cd "$OUT" && pwd)
T0=$(date +%s)
env HULK_TRACE_FILE="$OUT/trace.txt" HULK_DATA_DIR="$DATA" HULK_SAVE_DIR="$OUT/save" HULK_TDATA_DIR="$OUT/tdata" \
    HULK_UDATA_DIR="$OUT/udata" HULK_INPUT_SOURCE="replay:$REC" HULK_CKPT=1 HULK_CKPT_ALL=1 HULK_CKPT_REGIONS=0 \
    HULK_AUDIO_CLOCK=frame HULK_HANG="${HANG:-120}" SDL_AUDIO_DRIVER=dummy \
    "$IMG" > "$OUT/stdout.txt" 2>&1 &
PID=$!
# stop once the checkpoint at FRAMES is written (the Wine replay jobs stop the same way, from outside)
STOP=${FRAMES:-60000}
while kill -0 $PID 2>/dev/null; do
    if grep -q "ckpt frame $STOP " "$OUT/trace.txt" 2>/dev/null; then kill $PID; break; fi
    sleep 2
done
wait $PID
RC=$?
T1=$(date +%s)
sed -n 's/.*ckpt frame \([0-9]*\) hash \([0-9a-f]*\).*/\1 \2/p' "$OUT/trace.txt" > "$OUT/ckpt.txt" 2>/dev/null
{
    echo "rc $RC wall $((T1 - T0)) s"
    echo "checkpoints $(wc -l < "$OUT/ckpt.txt"), last frame $(tail -1 "$OUT/ckpt.txt" | cut -d' ' -f1)"
    grep -m1 "low-4gb" "$OUT/trace.txt" || true
    grep -E "^(missing|crash|end)" "$OUT/trace.txt" | head -5
    grep -E "^init [0-9]+" "$OUT/trace.txt" | tail -1
    if [ -n "$WCK" ] && [ -f "$WCK" ]; then
        awk 'NR==FNR { w[$1] = $2; next } ($1 in w) { n++; if (w[$1] == $2) same++; else if (!first) first = $1 }
             END { printf "against %s: %d common frames, %d identical, first differing frame %s\n", ARGV[1], n, same,
                   first ? first : "none" }' "$WCK" "$OUT/ckpt.txt"
    fi
} > "$OUT/result.txt"
cat "$OUT/result.txt"
exit $RC
