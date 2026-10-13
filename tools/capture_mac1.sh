#!/bin/sh
# Run trace captures on mac1 (the capture host), N shards side by side, from a pad script or a recording.
#   tools/capture_mac1.sh NAME SCRIPT.json [SHARDS=3] [MINUTES=60]
# Syncs tools/, hybrid/, tests/replays/, equivalent/, build/farm/equiv-demoted/ and the script to
# ~/hulk-permute on mac1, then starts `trace_capture.py --session NAME-K --shard K/N` for K = 0..N-1, each on its
# own xemu instance (HULK_XEMU_INSTANCE=K). Captures stay on mac1 under build/traces/NAME-K; replay them with
#   tools/equiv_replay_fn.py --functions @LIST --remote mac1   (or --since/--changed), then tools/equiv_confidence.py
# Progress: ssh mac1 'tail -2 ~/hulk-permute/build/traces/NAME-*.out'
set -eu
cd "$(dirname "$0")/.."
H=${MAC1:-matthewcarlson@192.168.155.24}
NAME=$1; SCRIPT=$2; N=${3:-3}; MIN=${4:-60}
[ -f "$SCRIPT" ] || { echo "no such script: $SCRIPT" >&2; exit 1; }
mkdir -p build/capture-sync && cp "$SCRIPT" build/capture-sync/"$NAME".json
COPYFILE_DISABLE=1 tar czf - tools hybrid tests/replays equivalent build/farm/equiv-demoted -C build/capture-sync "$NAME".json \
  | ssh "$H" "cd ~/hulk-permute && tar xzf - && mkdir -p build/traces build/replays && mv $NAME.json build/replays/"
ssh "$H" "cd ~/hulk-permute && pgrep -f 'xemu.app' >/dev/null && echo 'warning: xemu already running on mac1' >&2; \
  for k in \$(seq 0 $((N - 1))); do \
    HULK_XEMU_INSTANCE=\$k nohup build/venv/bin/python tools/trace_capture.py --session $NAME-\$k --shard \$k/$N \
      --minutes $MIN --unseen --script build/replays/$NAME.json > build/traces/$NAME-\$k.out 2>&1 < /dev/null & \
    sleep 20; \
  done; echo started $N captures"
