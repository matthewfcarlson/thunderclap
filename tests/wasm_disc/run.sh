#!/bin/sh
# The runners' disc layer against the extracted folder (tests/wasm_disc/disc_cmp.c; wpkg1):
#   tests/wasm_disc/run.sh isos/extracted path/to/game.iso      (or a tools/disc_pack.py pack)
set -e
cd "$(dirname "$0")/../.."
OUT=build/wpkg1/disc_cmp
mkdir -p "$OUT"
ZF=$(build/venv/bin/python -c "import sys; sys.path.insert(0, 'tools'); import disc_pack; print(' '.join(disc_pack.zstd_flags()))")
cc -O2 -g -Wall -Wno-unused-parameter $ZF -Isrc/platform/wasm/run -o "$OUT/disc_cmp" tests/wasm_disc/disc_cmp.c \
    src/platform/wasm/run/disc.c src/platform/wasm/run/zstd_dec.c -lpthread
exec "$OUT/disc_cmp" "$@"
