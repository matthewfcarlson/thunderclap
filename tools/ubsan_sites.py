#!/usr/bin/env python3
"""Float-cast-overflow sites of a native replay (ubsan1; docs/native-float.md "float-cast-overflow").

  build/venv/bin/python tools/ubsan_sites.py TRACE.txt --map build/native/link/hulk-strict.map \
        [--bindings build/native/bindings.json] [--out build/ubsan1/sites.jsonl]

The image built with HULK_NATIVE_SANITIZE=float-cast (tools/clang_probe.py SANITIZE) logs one `ubsan float-cast` line per
site at its 1st, 2nd, 4th, 8th ... hit (src/platform/sdl/xdk/startup.cpp). This folds them per site (the ubsan data
record's address) and writes one JSON line each: the converting function (the map symbol containing the return address, and
its XBE address), the source file and line the compiler recorded, the hit count (the last logged line's: a lower bound,
at most 2x low), the first frame, the first value seen and the last one logged."""
import argparse
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import native_run  # noqa: E402

LINE = re.compile(r"ubsan float-cast site=0x(\w+) ret=0x(\w+) file=(.*?) line=(\d+) col=(\d+) from=(\S+) to=(.+?) "
                  r"count=(\d+) first_frame=(\d+) frame=(\d+) bits=(\w+) value=(\S+)")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("trace")
    ap.add_argument("--map", required=True)
    ap.add_argument("--bindings", default="build/native/bindings.json")
    ap.add_argument("--out", default="build/ubsan1/sites.jsonl")
    a = ap.parse_args()
    sym = native_run.Symbolizer(a.map, a.bindings)
    sites = {}
    for l in open(a.trace, errors="replace"):
        m = LINE.search(l)
        if not m:
            continue
        site, ret, f, line, col, ft, tt, n, ff, fr, bits, val = m.groups()
        s = sites.setdefault(site, {"site": "0x" + site, "ret": "0x" + ret, "file": f, "line": int(line),
                                    "col": int(col), "count": 0, "first_frame": int(ff), "sample_bits": bits,
                                    "sample_value": val, "from": ft, "to": tt})
        s["count"] = max(s["count"], int(n))
        s["last_frame"] = int(fr)
        s["last_value"] = val
        s["last_bits"] = bits
    out = []
    for s in sites.values():
        desc = sym(int(s["ret"], 16))
        m = re.match(r"(.*?)\+0x[0-9a-f]+(?: \[xbe (0x\w+)\])?$", desc)
        s["function"] = m.group(1) if m else desc
        s["xbe"] = m.group(2) if m and m.group(2) else None
        s["file"] = re.sub(r"^.*?/snap/", "", s["file"].replace("\\", "/"))
        out.append(s)
    out.sort(key=lambda s: (-s["count"], s["first_frame"]))
    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    with open(a.out, "w") as f:
        for s in out:
            f.write(json.dumps(s) + "\n")
    print("%d sites, %d functions -> %s" % (len(out), len({s["function"] for s in out}), a.out))


if __name__ == "__main__":
    main()
