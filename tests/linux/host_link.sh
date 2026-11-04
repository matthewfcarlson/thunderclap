#!/bin/sh
# A1 (docs/native-build.md "x86-64 Linux"): build the native host layer's tests (tests/native_host/) for x86-64 Linux
# against the glibc sysroot of tools/linux_sysroot.py and check the executables with llvm-readelf. Link only: there
# is no Linux machine to run them on yet (the same tests run on arm64 Android through tests/android/host_tests.sh and
# as x86-64 macOS under Rosetta).
#   sh tests/linux/host_link.sh [OUT_DIR]            # default build/elf1/linux-host; env SYSROOT, PY
set -u
out=${1:-build/elf1/linux-host}
mkdir -p "$out"
PY=${PY:-build/venv/bin/python}
SYSROOT=${SYSROOT:-build/elf1/sysroot-x64}
BIN=$($PY -c "import sys; sys.path.insert(0, 'tools'); import clang_probe as cp, os; print(os.path.dirname(cp.tool('clang++')))") || exit 1
TGT=x86_64-unknown-linux-gnu
cxx() { "$BIN/clang++" --target=$TGT --sysroot="$SYSROOT" -fuse-ld=lld -std=c++17 -g -O1 -Wall -fno-omit-frame-pointer -pie -fPIE "$@"; }
fail=0
build() { name=$1; shift; cxx "$@" -o "$out/$name" -lpthread -ldl > "$out/$name.build.txt" 2>&1 || { echo "BUILD FAIL $name"; tail -20 "$out/$name.build.txt"; fail=1; }; }
build crt_test tests/native_host/crt_test.cpp src/platform/sdl/host/crt_posix.cpp src/platform/sdl/crt/softx87.cpp
build crt_test_libm -DHULK_NO_SOFT_X87 tests/native_host/crt_test.cpp src/platform/sdl/host/crt_posix.cpp
build host_test -Isrc/platform/sdl tests/native_host/host_test.cpp src/platform/sdl/host/win32_posix.cpp
build entry_test -rdynamic tests/native_host/entry_test.cpp src/platform/sdl/host/entry_posix.cpp
# rtti: the game side through the x86-64 MS-ABI front end and the ELF retarget, as the tree is compiled for linux-x64
"$BIN/clang++" --target=x86_64-pc-windows-msvc -fms-extensions -fms-compatibility -fms-compatibility-version=13.10 \
    -std=c++14 -O1 -S -emit-llvm tests/native_host/rtti_game.cpp -o "$out/rtti_game.ll" &&
$PY tools/native_elf.py retarget --target linux-x64 "$out/rtti_game.ll" "$out/rtti_game.e.ll" &&
"$BIN/clang" --target=$TGT -O1 -fPIC -c -Wno-override-module "$out/rtti_game.e.ll" -o "$out/rtti_game.o" &&
build rtti_test -Isrc/platform/sdl/host -Itests/native_host tests/native_host/rtti_test.cpp src/platform/sdl/host/rtti_msabi.cpp "$out/rtti_game.o" ||
    { echo "BUILD FAIL rtti_game"; fail=1; }
for b in crt_test crt_test_libm host_test entry_test rtti_test; do
    [ -f "$out/$b" ] || continue
    h=$("$BIN/llvm-readelf" -h "$out/$b" | sed -n 's/^ *Machine: *//p; s/^ *Type: *//p' | tr '\n' ' ')
    n=$("$BIN/llvm-readelf" -d "$out/$b" | sed -n 's/.*(NEEDED).*\[\(.*\)\]/\1/p' | tr '\n' ' ')
    i=$("$BIN/llvm-readelf" -l "$out/$b" | sed -n 's/.*Requesting program interpreter: \(.*\)\]/\1/p')
    echo "ok   $b: $h| $i | $n"
done
[ $fail = 0 ] && echo "host_link.sh: ok (linked, not run)"
exit $fail
