#!/usr/bin/env python3
"""Local data stand-ins the native links do not bind (dg1, 2026-11-11).

  build/venv/bin/python tools/native_local_data.py [BINDINGS.json] [--strict] [--json]

A verified source may define a global of its own (`SeqEventClipType_360ef0 g_360ef0;`, `extern "C" int gCount = 0;`)
where the original uses the game's data item: MSVC emits the same absolute address operand for both, so the function
still byte-matches. The Wine link points those references at the game's item (tools/wine_link.py local_data_bindings;
the binding map's `local_data`). The native links (tools/native_mac.py / native_elf.py) do not: natively the source's
own object is a separate variable of the stand-in's size, so the game's item is never written and the stand-in can be
overrun (the init 374 crash: a 1-byte class built into a 104-byte type). The fix is in source: name the game's item
(`DAT_<addr>`, typed by include/decls/data/records.h where it holds pointers).

This lists the binding map's `local_data` entries (default: build/native/bindings.json, a Wine link's map) with the
inventory item at each address, so a native iteration sees them; `--strict` exits 1 when there are any.

The native links run `gate()` (unb4): a stand-in the native objects still define under its 32-bit name, that is not
`const` (a constant's copy holds the same value) and is not one of KNOWN (open items, each with its reason), refuses
the link (tools/native_mac.py / native_elf.py `link`, exit 2; `--allow-local-data` links anyway). A stand-in whose
64-bit build names the game's item (`#if defined(HULK_PTR64)`: x64t5's 0x0035fb20) has another native symbol and passes.
"""
import argparse
import bisect
import json
import os
import re
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


# open stand-ins the gate lets through, each with its reason (remove a row when its source names the game's item)
KNOWN = {
    "?sound@@3VSound@@A": "0x0035de40's sound path string (16-byte item 0x004de958): the 64-bit String record does "
                          "not fit the item until the data inventory types it (x64t5)",
    "?gSound@@3VSound@@A": "0x0035e600's sound path string (12-byte item 0x004e2184): as `sound` (x64t5)",
}


def standins(bindings):
    """The binding map's local_data entries with the inventory item at each address."""
    ld = json.load(open(bindings)).get("local_data") or {}
    items = sorted((int(i["addr"], 16), i) for i in json.load(open(os.path.join(ROOT, "config/data.json")))["items"])
    starts = [s for s, _ in items]
    rows = []
    for sym, addr in sorted(ld.items(), key=lambda kv: (int(kv[1], 16), kv[0])):
        v = int(addr, 16)
        k = bisect.bisect_right(starts, v) - 1
        it = items[k][1] if k >= 0 and v < items[k][0] + items[k][1]["size"] + items[k][1].get("pad", 0) else None
        rows.append({"symbol": sym, "addr": addr,
                     "item": None if it is None else "DAT_%08x%s" % (items[k][0], "" if v == items[k][0] else
                                                                      " + 0x%x" % (v - items[k][0])),
                     "size": None if it is None else it["size"], "object": None if it is None else it.get("object")})
    return rows


def is_const(sym):
    """An MS-mangled variable declared const (`?k@ns@@3MB`: storage class 3, the type, then the cv letter B)."""
    return bool(re.match(r"^\?[^@]", sym)) and bool(re.search(r"@@[0-4].*B$", sym))


def gate(bindings, defined):
    """(unb4) The native links' check of the stand-ins: {"refused": [...], "allowed": [...]} of the rows the native
    objects define (`defined`: the names as the IR spells them). Refused: not const, not in KNOWN."""
    out = {"refused": [], "allowed": [], "not defined natively": 0}
    if not bindings or not os.path.exists(bindings):
        return out
    for r in standins(bindings):
        if r["symbol"] not in defined:
            out["not defined natively"] += 1
            continue
        why = "const (a copy holds the same value)" if is_const(r["symbol"]) else KNOWN.get(r["symbol"])
        if why:
            out["allowed"].append(dict(r, why=why))
        else:
            out["refused"].append(r)
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("bindings", nargs="?", default=os.path.join(ROOT, "build/native/bindings.json"))
    ap.add_argument("--strict", action="store_true", help="exit 1 if the map has any local_data stand-in")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args(argv)
    rows = standins(a.bindings)
    if a.json:
        print(json.dumps(rows, indent=1))
    else:
        for r in rows:
            print("%-60s %s  %s (%s B, %s)" % (r["symbol"], r["addr"], r["item"], r["size"], r["object"]))
        print("%d local data stand-in(s): natively each is its own variable, not the game's item" % len(rows))
    return 1 if a.strict and rows else 0


if __name__ == "__main__":
    sys.exit(main())
