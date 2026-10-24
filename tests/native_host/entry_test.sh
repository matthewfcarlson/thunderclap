#!/bin/sh
# Build and run tests/native_host/entry_test.cpp in its four modes; checks exit codes and trace lines.
set -u
out=${1:-build/x64-3}
mkdir -p "$out"
xcrun clang++ -std=c++17 -g -O1 -fno-omit-frame-pointer -rdynamic -Wall tests/native_host/entry_test.cpp \
    src/platform/sdl/host/entry_posix.cpp -o "$out/entry_test" || exit 1
fail=0
check() {   # mode, expected exit, grep pattern...
    mode=$1; want=$2; shift 2
    HULK_ENTRY_TEST=$mode HULK_HANG=$([ "$mode" = hang ] && echo 1 || echo 0) HULK_HANG_SAMPLES=1 \
        HULK_TRACE_FILE="$out/entry-$mode.txt" "$out/entry_test"
    rc=$?
    [ "$rc" = "$want" ] || { echo "FAIL $mode: exit $rc, want $want"; fail=1; }
    for pat in "$@"; do
        grep -q "$pat" "$out/entry-$mode.txt" || { echo "FAIL $mode: no '$pat'"; fail=1; }
    done
}
check ok 0 "^init 0 0x00011000" "^skip 1 0x00349000" "^init 2 0x00012000" "^first 1 CreateFileA" "^main returned 0" "^end returned code=0" "^called CreateFileA 1"
check missing 3 "^missing ?FUN_00123456@@YAXXZ caller=.* phase=main" "^frame 0 ret=" "^end missing code=3"
check crash 4 "^crash signal=1[01] addr=0x10 pc=.*game_crash" "^regs .*hulk_game_main" "^frame 0 ret=.* main" "^end crash"
check hang 6 "^hang sample 0 thread" "^end hang"
[ $fail = 0 ] && echo "entry_test: ok"
exit $fail
