#!/bin/sh
# The co-op transport and lockstep without the game (tests/net/coop_loop_test.cpp): a local lobby server, a host and
# one or two guests joining mid-run, optionally through a seeded impairment shim and a local TURN relay; every peer's
# final state hash must agree. Needs clang++ and node.
#   tests/net/coop_loop.sh OUT_DIR [PEERS=3] [FRAMES=3000] [SHIM] [RELAY=0|1]
#   e.g. tests/net/coop_loop.sh build/wnet1/loop 3 3000 seed=7,delay=60,jitter=30,loss=3
# The handshake (wnet2) runs as deployed: a test app key and disc spot table (tools/netplay_keys.py init over a small
# made-up disc folder in OUT_DIR, HULK_NETPLAY_CONFIG=OUT_DIR/netplay.json) on the lobby and the peers. NEG=1 also runs
# five peers that must be refused, each with its status line: a wrong app key, a clock 10 minutes off, a replayed
# request, a wrong disc answer, a hello under a wrong peer key (with PEERS=2 only: it needs a free slot).
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
# a made-up disc (the toy reads its spots through the same hdisc_* calls) and the handshake's secrets for it
DISC=$OUT/disc
if [ ! -f "$DISC/default.xbe" ]; then
  mkdir -p "$DISC"
  head -c 300000 /dev/urandom > "$DISC/default.xbe"
  head -c 900000 /dev/urandom > "$DISC/data.rcf"
fi
export HULK_NETPLAY_CONFIG=$OUT/netplay.json
[ -f "$HULK_NETPLAY_CONFIG" ] || ${PY:-python3} "$ROOT/tools/netplay_keys.py" init --disc "$DISC" --spots 6 > /dev/null
KEY=$(python3 -c "import json,sys; print(json.load(open(sys.argv[1]))['app_key'])" "$HULK_NETPLAY_CONFIG")
export HULK_NET_KEY=$KEY HULK_XBE=$DISC/default.xbe
PORT=$((20000 + $$ % 20000))
RP=$((PORT + 1))
if [ "$RELAY" = 1 ]; then TURN="--turn turn:127.0.0.1:$RP --user hulk --pass hulk"; export HULK_COOP_RELAY_ONLY=1; else TURN=""; fi
node "$ROOT/net/worker/test/local_server.mjs" --port $PORT --config "$HULK_NETPLAY_CONFIG" $TURN > "$OUT/server.log" 2>&1 &
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
NEGS=""; NEGPIDS=""
if [ -n "${NEG:-}" ]; then
  # peers the lobby (or the host) must refuse, each with the status the Online Co-op row shows; all at once
  neg() {   # NAME ENV...
    n=$1; shift
    env "$@" HULK_COOP_JOIN=@"$OUT/code.txt" "$OUT/coop_loop" 9 1000 ${MS:-5} > "$OUT/neg-$n.out" 2> "$OUT/neg-$n.err" &
    NEGS="$NEGS $n"; NEGPIDS="$NEGPIDS $!"
  }
  neg badkey HULK_NET_KEY=$(printf 'ab%.0s' $(seq 32))
  neg stale HULK_NET_SKEW=-600
  neg replay HULK_NET_TEST=replay
  neg baddisc HULK_NET_TEST=baddisc
  if [ "$PEERS" = 2 ]; then neg badpeer HULK_NET_TEST=badpeer; fi     # (it needs a free slot)
fi
if [ "$PEERS" -ge 3 ]; then
  sleep ${SECOND:-3}
  HULK_COOP_JOIN=@"$OUT/code.txt" "$OUT/coop_loop" 2 "$FRAMES" ${MS:-5} > "$OUT/peer2.out" 2> "$OUT/peer2.err" &
  P2=$!
  wait $P2 || true
fi
wait $P1 || true
wait $P0 || true
for p in $NEGPIDS; do wait $p || true; done
NEGOK=1
for n in $NEGS; do
  case $n in
    badkey) want="refused this app" ;; stale) want="clock is wrong" ;; replay) want="repeated request" ;;
    baddisc) want="could not confirm the game disc" ;; badpeer) want="not a player of this room" ;;
  esac
  if grep -q "co-op: .*$want" "$OUT/neg-$n.err"; then echo "refused as expected ($n): $(grep -h "$want" "$OUT/neg-$n.err" | head -1)"
  else echo "NOT refused as expected ($n): wanted '$want'"; NEGOK=0; fi
done
cat "$OUT"/peer*.out
grep -h 'co-op' "$OUT"/peer*.err | sort | uniq -c | sort -rn | head -40
N=$(cut -d' ' -f6,8 "$OUT"/peer*.out | sort -u | wc -l | tr -d ' ')
G=$(cat "$OUT"/peer*.out | wc -l | tr -d ' ')
if [ "$G" = "$PEERS" ] && [ "$N" = 1 ] && [ "$NEGOK" = 1 ] && ! grep -q DESYNC "$OUT"/peer*.err; then echo "coop_loop: PASS ($PEERS peers agree)"; else echo "coop_loop: FAIL"; exit 1; fi
