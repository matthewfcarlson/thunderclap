#!/bin/sh
# The arm64 Android image's start-up with the player's data (docs/native-android.md "Running the image"): the native
# link's libmain.so (tools/native_elf.py link --target android-arm64 --ld, with SDL3: tools/native_android_sdl.py) on
# the adb device, started by libmain_loader.c (a plain process standing in for SDL3's activity: dlopen, SDL_main),
# headless (no window; SDL's dummy audio). Stops at the first missing name (exit 3), a crash (exit 4), the end of main,
# HULK_HANG seconds without progress, or TIMEOUT seconds.
#   sh tests/android/libmain_run.sh LIBMAIN OUT_DIR [continue]
# Environment: DEVDATA (the extracted disc on the device, default /data/local/tmp/hulk-data: push it once with
# `adb push isos/extracted/. /data/local/tmp/hulk-data/`; it stays on the local emulator and is never packaged),
# REC (a .hrp recording on the host: pushed and replayed, HULK_INPUT_SOURCE=replay:...), TIMEOUT (default 300),
# HANG (default 90), HULK_ANDROID_FFMPEG (FFmpeg's prefix: its lib/*.so are pushed next to the image). `continue` is
# the survey mode (HULK_NATIVE_MISSING=continue: every missing name logged once and answered with 0; a list of stops,
# never a result). Writes OUT_DIR/{trace.txt,stdout.txt,logcat.txt,result.txt}.
set -u
lib=$1
out=$2
mode=${3:-}
mkdir -p "$out"
NDK=${NDK:-build/android/ndk}
API=${API:-29}
BIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64/bin
[ -d "$BIN" ] || BIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin
DEVDATA=${DEVDATA:-/data/local/tmp/hulk-data}
DEV=/data/local/tmp/hulk-run
"$BIN/clang" --target=aarch64-linux-android$API -O1 tests/android/libmain_loader.c -o "$out/libmain_loader" || exit 1
adb shell "test -f $DEVDATA/default.xbe" || { echo "no extracted disc at $DEVDATA on the device (default.xbe)"; exit 2; }
adb shell "rm -rf $DEV && mkdir -p $DEV/save $DEV/tdata $DEV/udata" || exit 1
adb push -q "$out/libmain_loader" $DEV/ && adb push -q "$lib" $DEV/libmain.so || exit 1
# FFmpeg's shared libraries next to the image when it links them (HULK_ANDROID_FFMPEG at link time)
FF=${HULK_ANDROID_FFMPEG:-build/third_party/out/ffmpeg-android-arm64/install}
for so in "$FF"/lib/*.so; do [ -f "$so" ] && { adb push -q "$so" $DEV/ || exit 1; }; done
X=
[ "$mode" = continue ] && X="HULK_NATIVE_MISSING=continue"
if [ -n "${REC:-}" ]; then
    adb push -q "$REC" $DEV/rec.hrp || exit 1
    X="$X HULK_INPUT_SOURCE=replay:$DEV/rec.hrp HULK_CKPT=1 HULK_CKPT_ALL=1 HULK_CKPT_REGIONS=0 HULK_AUDIO_CLOCK=frame"
fi
adb logcat -c
T0=$(date +%s)
rc=$(adb shell "cd $DEV && env LD_LIBRARY_PATH=$DEV HULK_TRACE_FILE=$DEV/trace.txt HULK_DATA_DIR=$DEVDATA HULK_SAVE_DIR=$DEV/save \
HULK_TDATA_DIR=$DEV/tdata HULK_UDATA_DIR=$DEV/udata SDL_AUDIO_DRIVER=dummy SDL_APP_ID=org.thunderclap.hulkud SDL_APP_NAME=hulk HULK_HANG=${HANG:-90} $X \
timeout ${TIMEOUT:-300} ./libmain_loader ./libmain.so > $DEV/stdout.txt 2>&1; echo \$?" | tr -d '\r')
T1=$(date +%s)
adb pull -q $DEV/trace.txt "$out/trace.txt" > /dev/null 2>&1
adb pull -q $DEV/stdout.txt "$out/stdout.txt" > /dev/null 2>&1
adb logcat -d > "$out/logcat.txt" 2>/dev/null
adb shell "rm -rf $DEV"
{
    echo "exit $rc wall $((T1 - T0)) s"
    grep -E "^(missing|crash|end|hang|first)" "$out/trace.txt" 2>/dev/null | head -12
    grep -E "^init [0-9]+" "$out/trace.txt" 2>/dev/null | tail -1
    echo "initializers run: $(grep -c '^init ' "$out/trace.txt" 2>/dev/null), skipped: $(grep -c '^skip ' "$out/trace.txt" 2>/dev/null)"
} > "$out/result.txt"
cat "$out/result.txt"
