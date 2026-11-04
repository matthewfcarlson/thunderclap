#!/bin/sh
# Android A0 (docs/native-android.md section 12): build the native host layer's tests (tests/native_host/) with the NDK
# for arm64 Android and run them on a device or emulator over adb. Nothing from the game's disc goes to the device.
#   sh tests/android/host_tests.sh [OUT_DIR]          # default build/android/host
# Needs: NDK (env NDK, default build/android/ndk), adb on PATH with one device, build/venv/bin/python, and the MS-ABI
# front end for rtti_game.cpp: env FE (a clang++; default the NDK's). The retargeted IR is compiled by the same LLVM
# (FE's clang): IR from a newer LLVM does not load into an older one (LLVM 22's `llvm.lifetime.start` has no size
# argument; the NDK r30 clang 21 rejects it at -O1). API level: env API (default 29).
set -u
out=${1:-build/android/host}
mkdir -p "$out"
PY=${PY:-build/venv/bin/python}
NDK=${NDK:-build/android/ndk}
API=${API:-29}
BIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64/bin
[ -d "$BIN" ] || BIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin
TGT=aarch64-linux-android$API
cxx() { "$BIN/clang++" --target=$TGT -std=c++17 -g -O1 -Wall -fno-omit-frame-pointer -static-libstdc++ "$@"; }
DEV=/data/local/tmp/hulk-a0
fail=0
build() { name=$1; shift; cxx "$@" -o "$out/$name" > "$out/$name.build.txt" 2>&1 || { echo "BUILD FAIL $name"; cat "$out/$name.build.txt"; fail=1; }; }

build crt_test tests/native_host/crt_test.cpp src/platform/sdl/host/crt_posix.cpp src/platform/sdl/crt/softx87.cpp
build crt_test_libm -DHULK_NO_SOFT_X87 tests/native_host/crt_test.cpp src/platform/sdl/host/crt_posix.cpp
build host_test -Isrc/platform/sdl tests/native_host/host_test.cpp src/platform/sdl/host/win32_posix.cpp
build entry_test -rdynamic tests/native_host/entry_test.cpp src/platform/sdl/host/entry_posix.cpp
# rtti: the game side through the MS-ABI front end and the ELF retarget (tools/native_elf.py, as the tree is
# compiled for android-arm64), the runtime and the test with their ELF spellings of the MS names (`@` -> `#`)
FE=${FE:-$BIN/clang++}
BE=$(dirname "$FE")/clang
"$FE" --version | head -1
"$FE" --target=aarch64-pc-windows-msvc -fms-extensions -fms-compatibility -fms-compatibility-version=13.10 -std=c++14 \
    -O1 -S -emit-llvm tests/native_host/rtti_game.cpp -o "$out/rtti_game.ll" &&
HULK_ELF_CLANG=$BE $PY tools/native_elf.py retarget --target android-arm64 "$out/rtti_game.ll" "$out/rtti_game.m.ll" &&
"$BE" --target=$TGT -O1 -c -Wno-override-module "$out/rtti_game.m.ll" -o "$out/rtti_game.o" &&
build rtti_test -Isrc/platform/sdl/host -Itests/native_host tests/native_host/rtti_test.cpp src/platform/sdl/host/rtti_msabi.cpp "$out/rtti_game.o" ||
    { echo "BUILD FAIL rtti_game"; fail=1; }

adb shell "rm -rf $DEV && mkdir -p $DEV/tmp" || exit 1
for b in crt_test crt_test_libm host_test entry_test rtti_test; do
    [ -f "$out/$b" ] && adb push -q "$out/$b" $DEV/
done
run() {   # name, expected exit, command (on the device)
    name=$1; want=$2; shift 2
    adb shell "cd $DEV && $* 2>&1; echo exit=\$?" | tr -d '\r' > "$out/$name.txt"
    rc=$(sed -n 's/^exit=//p' "$out/$name.txt" | tail -1)
    if [ "$rc" = "$want" ]; then echo "ok   $name (exit $rc)"; else echo "FAIL $name: exit $rc, want $want"; tail -5 "$out/$name.txt"; fail=1; fi
}
run crt_test 0 ./crt_test
run crt_test_libm 0 ./crt_test_libm
run host_test 0 ./host_test $DEV/tmp
run rtti_test 0 ./rtti_test
run rtti_ref 3 HULK_RTTI_TEST=ref ./rtti_test
run rtti_typeid 3 HULK_RTTI_TEST=typeid ./rtti_test
# entry_test: the four endings, trace lines checked as tests/native_host/entry_test.sh (the hang sampler is Mach-only:
# on Linux/Android it writes one `hang phase=` line)
entry() {   # mode, expected exit, grep patterns...
    mode=$1; want=$2; shift 2
    rc=$(adb shell "cd $DEV && HULK_ENTRY_TEST=$mode HULK_HANG=$([ "$mode" = hang ] && echo 1 || echo 0) HULK_HANG_SAMPLES=1 HULK_TRACE_FILE=$DEV/entry-$mode.txt ./entry_test > /dev/null 2>&1; echo \$?" | tr -d '\r')
    adb pull -q $DEV/entry-$mode.txt "$out/entry-$mode.txt" > /dev/null 2>&1
    ok=1
    [ "$rc" = "$want" ] || { echo "FAIL entry $mode: exit $rc, want $want"; ok=0; }
    for pat in "$@"; do
        grep -q "$pat" "$out/entry-$mode.txt" || { echo "FAIL entry $mode: no '$pat'"; ok=0; }
    done
    [ $ok = 1 ] && echo "ok   entry $mode (exit $rc)" || fail=1
}
entry ok 0 "^init 0 0x00011000" "^skip 1 0x00349000" "^init 2 0x00012000" "^first 1 CreateFileA" "^main returned 0" "^end returned code=0" "^called CreateFileA 1"
entry missing 3 "^missing ?FUN_00123456@@YAXXZ caller=.* phase=main" "^frame 0 ret=" "^end missing code=3"
# (bionic's dladdr sees .dynsym only: the static game_crash has no name there, unlike macOS)
entry crash 4 "^crash signal=1[01] addr=0x10 pc=" "^regs .*hulk_game_main" "^frame 0 ret=.*main" "^end crash"
entry hang 6 "^hang phase=" "^end hang"
grep -h "low-4gb\|fpcr" "$out/entry-ok.txt" 2>/dev/null
[ $fail = 0 ] && echo "host_tests.sh: ok"
exit $fail
