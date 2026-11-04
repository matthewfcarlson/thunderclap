#!/bin/sh
# va1 (docs/native-build.md "Varargs"): the game's variadic functions on the 64-bit targets. The real sources of the
# x86-style va_list producers and the slot-walking consumers, plus tests/native_host/va_tree_game.cpp (their callees and
# callers), go through the MS-ABI front end and the target's retarget one TU each, as the tree does; the host main is
# tests/native_host/va_tree_test.cpp.
#   sh tests/native_host/va_tree_test.sh mac     [OUT]   # arm64 macOS: tools/native_mac.py's retarget (Darwin varargs)
#   sh tests/native_host/va_tree_test.sh x64     [OUT]   # x86-64 macOS under Rosetta: System V host + `win64cc` on the
#                                                        # game's variadics (tools/native_elf.py's pass), as on SteamOS
#   sh tests/native_host/va_tree_test.sh android [OUT]   # arm64 Android over adb: tools/native_elf.py retarget, NDK
# Default OUT build/va1/test-MODE. Android: env NDK (build/android/ndk), API (29); one adb device or emulator.
# 0x0021f800 declares 0x00216320 under its own C++ name (the tree's link aliases the two by address); the test
# compiles a copy whose declaration (and call) spell the definition's name and parameter types, with the same variadic
# shape (two pointer-sized named parameters), so the call binds without a link-time alias.
set -u
mode=${1:-mac}
out=${2:-build/va1/test-$mode}
mkdir -p "$out"
PY=${PY:-build/venv/bin/python}
SRCS="matches/0x000964a0 matches/0x0023fde0 matches/0x00245b00 matches/0x00246f50 matches/0x00267760 matches/0x00267730
 matches/0x0023fef0 matches/0x000fc020 matches/0x00216320 matches/0x00338e20 matches/0x00213440 matches/0x00213470
 matches/0x0025fba0 equivalent/0x00232cc0 equivalent/0x000fbc00 equivalent/0x000fbe00 equivalent/0x002160c0
 equivalent/0x00214a90 equivalent/0x0025fad0 equivalent/0x0021f800 tests/native_host/va_tree_game"
case $mode in
    mac)     FT=aarch64-pc-windows-msvc; BT=arm64-apple-macosx13.0
             FE=$($PY -c "import sys; sys.path.insert(0, 'tools'); import clang_probe as cp; print(cp.tool('clang++'))"); BE=$FE ;;
    x64)     FT=x86_64-pc-windows-msvc; BT=x86_64-apple-macosx13.0
             FE=$($PY -c "import sys; sys.path.insert(0, 'tools'); import clang_probe as cp; print(cp.tool('clang++'))"); BE=$FE ;;
    android) NDK=${NDK:-build/android/ndk}; API=${API:-29}
             BIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64/bin
             [ -d "$BIN" ] || BIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin
             FT=aarch64-pc-windows-msvc; BT=aarch64-linux-android$API; FE=$BIN/clang++; BE=$BIN/clang ;;
    *) echo "mode: mac | x64 | android"; exit 2 ;;
esac
# the tree's front-end flags (tools/native_mac.py FRONT) without the forced compat/native.h: these TUs are the sources
# as they are, not gen_tree's TUs (which guard the sources' own CRT declarations against it)
FLAGS="-fms-extensions -fms-compatibility -fms-compatibility-version=13.10 -std=c++14 -O0 -S -emit-llvm -Iinclude
 -fno-strict-aliasing -fwrapv -fno-delete-null-pointer-checks -Xclang -fno-wchar -fno-operator-names
 -Wno-c++11-narrowing -Wno-address-of-temporary -fcheck-new -ffp-eval-method=double -ffp-contract=off -w"
objs=""
for s in $SRCS; do
    n=$(basename $s)
    src=$s.cpp
    if [ $n = 0x0021f800 ]; then
        sed -e 's/^void __cdecl FUN_00216320(const char\*, const char\*, \.\.\.);/const char* __cdecl FUN_00216320(hulk_uintptr, hulk_uintptr, ...);/' \
            -e 's/FUN_00216320(context->name, "%s: %s",/FUN_00216320((hulk_uintptr)context->name, (hulk_uintptr)"%s: %s",/' \
            $src > "$out/$n.cpp"; src=$out/$n.cpp
        grep -q "const char\* __cdecl FUN_00216320(hulk_uintptr, hulk_uintptr, ...);" $src || { echo "0x0021f800: declaration not found"; exit 1; }
    fi
    "$FE" --target=$FT $FLAGS $src -o "$out/$n.ll" || { echo "FRONT END FAIL $s"; exit 1; }
    case $mode in
        mac) $PY tools/native_mac.py retarget "$out/$n.ll" "$out/$n.t.ll" ;;
        x64) $PY - "$out/$n.ll" "$out/$n.t.ll" "$BE" <<'EOF'
import re, subprocess, sys
sys.path.insert(0, "tools")
import native_mac, native_elf
inp, outp, be = sys.argv[1:]
dl = subprocess.run([be, "--target=x86_64-apple-macosx13.0", "-x", "c", "-S", "-emit-llvm", "-", "-o", "-"], input="int x;",
                    capture_output=True, text=True).stdout
dl = re.search(r'^target datalayout = "(.*)"', dl, re.M).group(1)
s = native_mac.retarget(open(inp, errors="surrogateescape").read())
s = re.sub(r'^target datalayout = .*$', 'target datalayout = "%s"' % dl, s, count=1, flags=re.M)
s = re.sub(r'^target triple = .*$', 'target triple = "x86_64-apple-macosx13.0"', s, count=1, flags=re.M)
s = native_elf.add_win64cc(s, native_elf.HostNames())
open(outp, "w", errors="surrogateescape").write(s)
EOF
             ;;
        android) HULK_ELF_CLANG=$BE $PY tools/native_elf.py retarget --target android-arm64 "$out/$n.ll" "$out/$n.t.ll" ;;
    esac || { echo "RETARGET FAIL $s"; exit 1; }
    "$BE" --target=$BT -O0 -c -Wno-override-module $([ $mode = android ] && echo -fPIC) "$out/$n.t.ll" -o "$out/$n.o" ||
        { echo "BACKEND FAIL $s"; exit 1; }
    objs="$objs $out/$n.o"
done
case $mode in
    mac) xcrun clang++ -arch arm64 -std=c++17 -O1 tests/native_host/va_tree_test.cpp src/platform/sdl/host/rtti_msabi.cpp $objs -o "$out/va_tree" || exit 1
         "$out/va_tree" ;;
    x64) xcrun clang++ -arch x86_64 -std=c++17 -O1 tests/native_host/va_tree_test.cpp src/platform/sdl/host/rtti_msabi.cpp $objs -o "$out/va_tree" || exit 1
         arch -x86_64 "$out/va_tree" ;;
    android) "$BIN/clang++" --target=$BT -std=c++17 -O1 -static-libstdc++ tests/native_host/va_tree_test.cpp src/platform/sdl/host/rtti_msabi.cpp $objs \
                 -o "$out/va_tree" || exit 1
             DEV=/data/local/tmp/hulk-va1
             adb shell "mkdir -p $DEV" && adb push -q "$out/va_tree" $DEV/ || exit 1
             adb shell "$DEV/va_tree; echo exit=\$?" | tr -d '\r' > "$out/run.txt"
             adb shell "rm -rf $DEV"
             cat "$out/run.txt"
             grep -q '^exit=0$' "$out/run.txt" ;;
esac
