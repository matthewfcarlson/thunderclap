#!/bin/sh
# The co-op transport and lockstep without the game (tests/net/coop_loop_test.cpp): a local lobby server, a host and
# one or two guests joining mid-run, optionally through a seeded impairment shim and a local TURN relay; every peer's
# final state hash must agree. Needs clang++ and node.
#   tests/net/coop_loop.sh OUT_DIR [PEERS=3] [FRAMES=3000] [SHIM] [RELAY=0|1]
#   e.g. tests/net/coop_loop.sh build/wnet1/loop 3 3000 seed=7,delay=60,jitter=30,loss=3
set -eu
OUT=${1:?OUT_DIR}
PEERS=${2:-3}
FRAMES=${3:-3000}
SHIM=${4:-}
RELAY=${5:-0}
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
APP=$ROOT/src/platform/wasm/run/app
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
CXX=${CXX:-clang++}
CC=${CC:-clang}
if [ ! -x "$OUT/coop_loop" ] || [ -n "${REBUILD:-}" ]; then
  for f in core mux thread server; do
    $CC -std=c11 -O2 -w -c "$APP/netplay_juice_$f.c" -o "$OUT/juice_$f.o"
  done
  $CXX -std=c++20 -O1 -g -fno-exceptions -fno-rtti -Wall -Wno-unused-parameter -I"$ROOT/tests/net/stub" \
    ${SAN:-} "$APP/netplay.cpp" "$APP/netplay_util.cpp" "$ROOT/tests/net/coop_loop_test.cpp" "$OUT"/juice_*.o \
    -lpthread -ldl -o "$OUT/coop_loop" 2>&1 | grep -v 'unused' || true
fi
PORT=$((20000 + $$ % 20000))
RP=$((PORT + 1))
if [ "$RELAY" = 1 ]; then TURN="--turn turn:127.0.0.1:$RP --user hulk --pass hulk"; export HULK_COOP_RELAY_ONLY=1; else TURN=""; fi
node "$ROOT/net/worker/test/local_server.mjs" --port $PORT $TURN > "$OUT/server.log" 2>&1 &
SRV=$!
trap 'kill $SRV 2>/dev/null || true' EXIT
for i in 1 2 3 4 5 6 7 8 9 10; do grep -q listening "$OUT/server.log" && break; sleep 0.3; done
export HULK_NET_WORKER=http://127.0.0.1:$PORT HULK_COOP_SHIM="$SHIM" HULK_COOP_TMP="$OUT" HULK_COOP_LOG=${HULK_COOP_LOG:-0}
rm -f "$OUT/code.txt" "$OUT"/peer*.out
R=""; [ "$RELAY" = 1 ] && R=$RP
HULK_COOP_HOST=1 HULK_COOP_CODE_FILE="$OUT/code.txt" HULK_COOP_RELAY=$R \
  "$OUT/coop_loop" 0 "$FRAMES" ${MS:-5} > "$OUT/peer0.out" 2> "$OUT/peer0.err" &
P0=$!
sleep 1.5
HULK_COOP_JOIN=@"$OUT/code.txt" "$OUT/coop_loop" 1 "$FRAMES" ${MS:-5} > "$OUT/peer1.out" 2> "$OUT/peer1.err" &
P1=$!
if [ "$PEERS" -ge 3 ]; then
  sleep ${SECOND:-3}
  HULK_COOP_JOIN=@"$OUT/code.txt" "$OUT/coop_loop" 2 "$FRAMES" ${MS:-5} > "$OUT/peer2.out" 2> "$OUT/peer2.err" &
  P2=$!
  wait $P2 || true
fi
wait $P1 || true
wait $P0 || true
cat "$OUT"/peer*.out
grep -h 'co-op' "$OUT"/peer*.err | sort | uniq -c | sort -rn | head -40
N=$(cut -d' ' -f6,8 "$OUT"/peer*.out | sort -u | wc -l | tr -d ' ')
G=$(cat "$OUT"/peer*.out | wc -l | tr -d ' ')
if [ "$G" = "$PEERS" ] && [ "$N" = 1 ] && ! grep -q DESYNC "$OUT"/peer*.err; then echo "coop_loop: PASS ($PEERS peers agree)"; else echo "coop_loop: FAIL"; exit 1; fi
