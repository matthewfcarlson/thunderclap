#!/bin/sh
# wasm_apk_replay.sh OUTDIR FRAMES [RENDERER]: play3 in the installed wasm app (tools/wasm_android.py; docs/wasm-port.md
# "The Android app"), from <files>/play3.hrp with the disc in <files>/disc; pulls trace.txt, its .ckref, log.txt and
# logcat into OUTDIR. RENDERER: null (the headless build's run, default), vulkan or gles. Compare the records with
# tools/native_replay.py check, or byte for byte with a macOS app run of the same hulk.wasm.
set -e
. build/android/env.sh
OUT=$1; FR=${2:-60000}; R=${3:-null}; P=org.thunderclap.hulkud; F=/data/user/0/$P/files
mkdir -p $OUT
adb shell am force-stop $P
adb shell run-as $P sh -c "'rm -rf files/run; mkdir -p files/run/save files/run/tdata files/run/udata; rm -f files/log.txt'"
adb logcat -c
adb shell am start -n $P/.SetupActivity --es HULK_DATA_DIR $F/disc --es HULK_TRACE_FILE $F/run/trace.txt \
  --es HULK_SAVE_DIR $F/run/save --es HULK_TDATA_DIR $F/run/tdata --es HULK_UDATA_DIR $F/run/udata \
  --es HULK_INPUT_SOURCE replay:$F/play3.hrp --es HULK_HANG 120 --es HULK_CKPT 1 --es HULK_CKPT_ALL 1 \
  --es HULK_AUDIO_CLOCK frame --es HULK_CKPT_REGIONS 0 --es HULK_AUDIO_NOMIX 1 --es HULK_CKREF 1 \
  --es HULK_GFX_RENDERER $R --es SDL_AUDIO_DRIVER dummy $EXTRA
T0=$(date +%s)
while :; do
  sleep 10
  L=$(adb shell run-as $P sh -c "'grep \"^ckpt frame\" files/run/trace.txt | tail -1'" 2>/dev/null | awk '{print $3}')
  ALIVE=$(adb shell pidof $P | tr -d '\r')
  echo "$(( $(date +%s) - T0 )) s frame ${L:-none} pid ${ALIVE:-gone}"
  [ -n "$L" ] && [ "$L" -ge "$FR" ] && break
  [ -z "$ALIVE" ] && break
done
echo "wall $(( $(date +%s) - T0 )) s" > $OUT/wall.txt
adb shell am force-stop $P
adb exec-out run-as $P cat files/run/trace.txt > $OUT/trace.txt
adb exec-out run-as $P cat files/run/trace.txt.ckref > $OUT/trace.txt.ckref || true
adb exec-out run-as $P cat files/log.txt > $OUT/log.txt || true
adb logcat -d > $OUT/logcat.txt
