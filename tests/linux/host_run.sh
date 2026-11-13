#!/bin/sh
# Run the native host layer's tests that tests/linux/host_link.sh links for x86-64 Linux, on x86-64 Linux (a box, or
# the Rosetta VM of tests/linux/vm_run.sh: `vm_run.sh host-tests`). The checks are tests/android/host_tests.sh's.
#   sh tests/linux/host_run.sh BIN_DIR [WORK_DIR]       # BIN_DIR holds crt_test, crt_test_libm, host_test, entry_test, rtti_test
set -u
bin=$(cd "$1" && pwd)
work=${2:-/tmp/hulk-host-tests}
rm -rf "$work"; mkdir -p "$work/tmp"; cd "$work" || exit 1
fail=0
run() {   # name, expected exit, command
    name=$1; want=$2; shift 2
    sh -c "$*" > "$name.txt" 2>&1; rc=$?
    if [ "$rc" = "$want" ]; then echo "ok   $name (exit $rc)"; else echo "FAIL $name: exit $rc, want $want"; tail -5 "$name.txt"; fail=1; fi
}
run crt_test 0 "$bin/crt_test"
run crt_test_libm 0 "$bin/crt_test_libm"
run host_test 0 "$bin/host_test $work/tmp"
run rtti_test 0 "$bin/rtti_test"
run rtti_ref 3 "HULK_RTTI_TEST=ref $bin/rtti_test"
run rtti_typeid 3 "HULK_RTTI_TEST=typeid $bin/rtti_test"
entry() {   # mode, expected exit, grep patterns...
    mode=$1; want=$2; shift 2
    HULK_ENTRY_TEST=$mode HULK_HANG=$([ "$mode" = hang ] && echo 1 || echo 0) HULK_HANG_SAMPLES=1 \
        HULK_TRACE_FILE=$work/entry-$mode.txt "$bin/entry_test" > /dev/null 2>&1
    rc=$?
    ok=1
    [ "$rc" = "$want" ] || { echo "FAIL entry $mode: exit $rc, want $want"; ok=0; }
    for pat in "$@"; do
        grep -q "$pat" "entry-$mode.txt" || { echo "FAIL entry $mode: no '$pat'"; ok=0; }
    done
    [ $ok = 1 ] && echo "ok   entry $mode (exit $rc)" || fail=1
}
entry ok 0 "^init 0 0x00011000" "^skip 1 0x00349000" "^init 2 0x00012000" "^first 1 CreateFileA" "^main returned 0" "^end returned code=0" "^called CreateFileA 1"
entry missing 3 "^missing ?FUN_00123456@@YAXXZ caller=.* phase=main" "^frame 0 ret=" "^end missing code=3"
entry crash 4 "^crash signal=1[01] addr=0x10 pc=" "^regs .*" "^frame 0 ret=" "^end crash"
entry hang 6 "^hang phase=" "^end hang"
grep -h "low-4gb\|fpcr\|mxcsr" entry-ok.txt 2>/dev/null
[ $fail = 0 ] && echo "host_run.sh: ok"
exit $fail
