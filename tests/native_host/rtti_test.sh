#!/bin/sh
# Build and run the MS-ABI RTTI runtime test (src/platform/sdl/host/rtti_msabi.cpp) on arm64 macOS:
# tests/native_host/rtti_game.cpp the way tools/native_mac.py compiles the tree (front end for
# aarch64-pc-windows-msvc, IR retargeted to Mach-O), rtti_test.cpp and the runtime for the host.
#   sh tests/native_host/rtti_test.sh [OUT_DIR] [extra host flags, e.g. -fsanitize=address,undefined]
set -u
out=${1:-build/x64-5}; shift 2>/dev/null
mkdir -p "$out"
PY=${PY:-build/venv/bin/python}
CXX=$($PY -c "import sys; sys.path.insert(0, 'tools'); import clang_probe as cp; print(cp.tool('clang++'))") || exit 1
$CXX --target=aarch64-pc-windows-msvc -fms-extensions -fms-compatibility -fms-compatibility-version=13.10 -std=c++14 \
    -O1 -S -emit-llvm tests/native_host/rtti_game.cpp -o "$out/rtti_game.ll" || exit 1
$PY tools/native_mac.py retarget "$out/rtti_game.ll" "$out/rtti_game.m.ll" || exit 1
$CXX --target=arm64-apple-macosx13.0 -O1 -c -Wno-override-module "$out/rtti_game.m.ll" -o "$out/rtti_game.o" || exit 1
xcrun clang++ -std=c++17 -g -O1 -Wall "$@" tests/native_host/rtti_test.cpp src/platform/sdl/host/rtti_msabi.cpp \
    "$out/rtti_game.o" -o "$out/rtti_test" || exit 1
fail=0
"$out/rtti_test" || fail=1
for mode in ref typeid; do
    o=$(HULK_RTTI_TEST=$mode "$out/rtti_test"); rc=$?
    [ $rc = 3 ] || { echo "FAIL $mode: exit $rc, want 3 ($o)"; fail=1; }
    case "$mode:$o" in
        ref:*bad_cast*|typeid:*bad_typeid*) ;;
        *) echo "FAIL $mode: '$o'"; fail=1 ;;
    esac
done
[ $fail = 0 ] && echo "rtti_test.sh: ok"
exit $fail
