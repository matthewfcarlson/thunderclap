#!/bin/sh
# A1 smoke test (docs/native-android.md section 13): run the native link's libmain.so (tools/native_elf.py link
# --target android-arm64 --ld) on the adb device through a stand-in for SDL3's activity (libmain_loader.c): dlopen,
# SDL_main, the game's initializers in the XBE's order, then the game's main, up to the first call of a symbol the
# image lacks (a stub: hulk_native_missing reports it and exits 3) or a crash (exit 4). Prints the start-up trace.
#   sh tests/android/libmain_smoke.sh [LIBMAIN] [OUT_DIR]     # default build/native-android-arm64/link/libmain.so
# Needs: NDK (env NDK, default build/android/ndk), adb with one device. Nothing from the disc goes to the device (the
# run stops before any file is opened; HULK_DATA_DIR is not set).
set -u
lib=${1:-build/native-android-arm64/link/libmain.so}
out=${2:-build/native-android-arm64/smoke}
mkdir -p "$out"
NDK=${NDK:-build/android/ndk}
API=${API:-29}
BIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64/bin
[ -d "$BIN" ] || BIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin
"$BIN/clang" --target=aarch64-linux-android$API -O1 tests/android/libmain_loader.c -o "$out/libmain_loader" || exit 1
DEV=/data/local/tmp/hulk-a1
adb shell "rm -rf $DEV && mkdir -p $DEV" || exit 1
adb push -q "$out/libmain_loader" "$lib" $DEV/ || exit 1
rc=$(adb shell "cd $DEV && HULK_TRACE_FILE=$DEV/trace.txt ./libmain_loader ./libmain.so > $DEV/stdout.txt 2>&1; echo \$?" | tr -d '\r')
adb pull -q $DEV/trace.txt "$out/trace.txt" > /dev/null 2>&1
adb pull -q $DEV/stdout.txt "$out/stdout.txt" > /dev/null 2>&1
adb shell "rm -rf $DEV"
echo "exit $rc"
head -c 4000 "$out/stdout.txt"
grep -v "^init \|^skip " "$out/trace.txt" | head -40
echo "initializers run: $(grep -c '^init ' "$out/trace.txt"), skipped: $(grep -c '^skip ' "$out/trace.txt")"
