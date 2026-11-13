#!/bin/sh
# The APK on the adb device (docs/native-android.md "Running the image"): install, the player's data into the app's
# internal storage (once), start HulkActivity, wait until the process ends or TIMEOUT seconds, pull the trace.
#   sh tests/android/apk_run.sh APK OUT_DIR [continue]
# Environment: DATA (the extracted disc on the host, default isos/extracted; copied to the device once: adb push to
# /data/local/tmp/hulk-data, then `run-as` into the app's files/data, where only the app and adb's run-as can read it;
# nothing from the disc goes into the APK), TIMEOUT (default 300), REINSTALL_DATA=1 (copy the data again).
# `continue` is the survey mode (HULK_NATIVE_MISSING=continue). Writes OUT_DIR/{trace.txt,logcat.txt,result.txt}.
set -u
apk=$1
out=$2
mode=${3:-}
P=org.thunderclap.hulkud
DATA=${DATA:-isos/extracted}
mkdir -p "$out"
adb install -r "$apk" > "$out/install.txt" 2>&1 || { cat "$out/install.txt"; exit 1; }
if [ "${REINSTALL_DATA:-0}" = 1 ] || ! adb shell run-as $P test -f files/data/default.xbe; then
    [ -f "$DATA/default.xbe" ] || { echo "no extracted disc at $DATA (default.xbe)"; exit 2; }
    adb shell "test -f /data/local/tmp/hulk-data/default.xbe" || adb push -q "$DATA/." /data/local/tmp/hulk-data/ || exit 1
    adb shell "chmod -R a+rX /data/local/tmp/hulk-data && run-as $P sh -c 'rm -rf files/data && cp -r /data/local/tmp/hulk-data files/data'" || exit 1
fi
adb shell am force-stop $P
adb shell run-as $P rm -f files/trace.txt
X=
[ "$mode" = continue ] && X="--es HULK_NATIVE_MISSING continue"
adb logcat -c
T0=$(date +%s)
adb shell am start -W -n $P/.HulkActivity --es SDL_AUDIO_DRIVER dummy --es HULK_HANG "${HANG:-90}" $X > /dev/null
sleep 2
while adb shell pidof $P > /dev/null 2>&1; do
    [ $(( $(date +%s) - T0 )) -ge "${TIMEOUT:-300}" ] && { adb shell am force-stop $P; echo "timeout" > "$out/timeout"; break; }
    sleep 2
done
T1=$(date +%s)
adb shell run-as $P cat files/trace.txt > "$out/trace.txt" 2>/dev/null
adb logcat -d > "$out/logcat.txt" 2>/dev/null
{
    echo "wall $((T1 - T0)) s$( [ -f "$out/timeout" ] && echo ' (timeout: stopped)')"
    grep -E "^(missing|crash|end|hang)" "$out/trace.txt" 2>/dev/null | head -12
    grep -E "^init [0-9]+" "$out/trace.txt" 2>/dev/null | tail -1
    echo "initializers run: $(grep -c '^init ' "$out/trace.txt" 2>/dev/null), skipped: $(grep -c '^skip ' "$out/trace.txt" 2>/dev/null)"
} > "$out/result.txt"
cat "$out/result.txt"
