#!/bin/sh
# tests/net/disc_spot_test.cpp: the disc challenge's spots through run/disc.c from each disc source (wnet2).
#   HULK_NETPLAY_CONFIG=F tests/net/disc_spot_test.sh OUT_DIR SRC [SRC ...]
# e.g. ... build/wnet2/spots isos/extracted isos/X.xiso.iso build/hulk-hd.hulkdisc
set -eu
OUT=${1:?OUT_DIR}; shift
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
RUN=$ROOT/src/platform/wasm/run
mkdir -p "$OUT"
ZF=$(cd "$ROOT" && ${PY:-build/venv/bin/python} -c "import sys; sys.path.insert(0,'tools'); import disc_pack; print(' '.join(disc_pack.zstd_flags()))" | tail -1)
clang -std=c11 -O2 -w $ZF -c "$RUN/disc.c" -o "$OUT/disc.o"
clang -std=c11 -O2 -w $ZF -c "$RUN/zstd_dec.c" -o "$OUT/zstd_dec.o"
for f in core mux thread server; do clang -std=c11 -O2 -w -c "$RUN/app/netplay_juice_$f.c" -o "$OUT/juice_$f.o"; done
clang++ -std=c++20 -O1 -fno-exceptions -fno-rtti -I"$RUN/app" "$ROOT/tests/net/disc_spot_test.cpp" \
  "$RUN/app/netplay_util.cpp" "$OUT/disc.o" "$OUT/zstd_dec.o" "$OUT"/juice_*.o -lpthread -o "$OUT/disc_spot_test"
"$OUT/disc_spot_test" "$@"
