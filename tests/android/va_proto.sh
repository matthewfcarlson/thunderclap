#!/bin/sh
# Android A0 varargs prototype (docs/native-android.md section 12): tests/android/va_game.cpp through the MS-ABI front
# end (aarch64-pc-windows-msvc), retargeted to arm64 Android plainly and with `win64cc` on the variadic functions
# (tests/android/va_retarget.py), linked with tests/android/va_host.cpp and run case by case on the adb device.
#   sh tests/android/va_proto.sh [OUT_DIR]       # default build/android/va; env NDK, API (29), FE (front end clang++)
# Expected: `plain` fails (wrong values or a crash) in every game-variadic case; `win64cc` and `elf` (the tree's
# retarget, tools/native_elf.py) pass all but `hostcall`
# (host code calling a game variadic through a plain prototype; `hostcall_ms` declares it ms_abi and passes).
set -u
out=${1:-build/android/va}
mkdir -p "$out"
PY=${PY:-build/venv/bin/python}
NDK=${NDK:-build/android/ndk}
API=${API:-29}
BIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64/bin
[ -d "$BIN" ] || BIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin
FE=${FE:-$BIN/clang++}
BE=$(dirname "$FE")/clang
TGT=aarch64-linux-android$API
DL=$(echo 'int x;' | "$BIN/clang" --target=$TGT -x c -S -emit-llvm - -o - | sed -n 's/^target datalayout = "\(.*\)"/\1/p')
"$FE" --target=aarch64-pc-windows-msvc -fms-extensions -fms-compatibility -fms-compatibility-version=13.10 -std=c++14 \
    -O0 -S -emit-llvm -ffp-contract=off tests/android/va_game.cpp -o "$out/game.ll" || exit 1
DEV=/data/local/tmp/hulk-va
adb shell "mkdir -p $DEV" || exit 1
for m in plain win64cc elf; do
    if [ $m = elf ]; then   # the tree's retarget (tools/native_elf.py): win64cc, the `@` escape, ELF COMDATs
        HULK_ELF_CLANG=$BE $PY tools/native_elf.py retarget --target android-arm64 "$out/game.ll" "$out/game.$m.ll" || exit 1
    else
        $PY tests/android/va_retarget.py "$out/game.ll" "$out/game.$m.ll" --triple aarch64-unknown-linux-android$API \
            --datalayout "$DL" $([ $m = win64cc ] && echo --win64cc) || exit 1
    fi
    "$BE" --target=$TGT -O0 -c -Wno-override-module "$out/game.$m.ll" -o "$out/game.$m.o" || exit 1
    "$BIN/clang++" --target=$TGT -O1 -static-libstdc++ tests/android/va_host.cpp "$out/game.$m.o" -o "$out/va_$m" || exit 1
    adb push -q "$out/va_$m" $DEV/
    echo "== $m"
    for c in mix mixlong fmt hostfmt snprintf hostcall hostcall_ms; do
        r=$(adb shell "$DEV/va_$m $c 2>&1 | head -1" | tr -d '\r')
        echo "${r:-$c: no output (crashed)}"
    done
done
adb shell "rm -rf $DEV"
