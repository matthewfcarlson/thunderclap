#!/usr/bin/env python3
"""tools/native_local_data.py: the native links' gate on local data stand-ins (unb4), on a made-up binding map.

  build/venv/bin/python tests/native_host/native_local_data_test.py      # exit 0 when every case passes
"""
import json
import os
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import native_local_data as nld  # noqa: E402

fails = 0


def check(what, got, want):
    global fails
    if got != want:
        fails += 1
        print("FAIL %s: got %r, want %r" % (what, got, want))


check("const float", nld.is_const("?kRadiansToDegrees@fn_fc9b775c@@3MB"), True)
check("const pointer to const char", nld.is_const("?s@@3PEBDB"), True)
check("pointer to const char", nld.is_const("?s@@3PEBDA"), False)
check("class object", nld.is_const("?gThing@fn_fabc8fa7@@3VThing@1@A"), False)
check("C name", nld.is_const("gCount"), False)

m = {"local_data": {"?k@@3MB": "0x003f32b8", "?g@@3VThing@@A": "0x004e7038", "?sound@@3VSound@@A": "0x004de958",
                    "?gone@@3HA": "0x004e7000"}}
with tempfile.NamedTemporaryFile("w", suffix=".json", delete=False) as f:
    json.dump(m, f)
try:
    g = nld.gate(f.name, {"?k@@3MB", "?g@@3VThing@@A", "?sound@@3VSound@@A"})
    check("refused", [r["symbol"] for r in g["refused"]], ["?g@@3VThing@@A"])
    check("allowed", sorted(r["symbol"] for r in g["allowed"]), ["?k@@3MB", "?sound@@3VSound@@A"])
    check("not defined natively", g["not defined natively"], 1)
    check("no map", nld.gate(os.path.join(tempfile.gettempdir(), "no-such-map.json"), set())["refused"], [])
finally:
    os.unlink(f.name)

print("native_local_data_test: %s" % ("ok" if not fails else "%d failure(s)" % fails))
sys.exit(1 if fails else 0)
