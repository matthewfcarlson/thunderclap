#!/usr/bin/env python3
"""Summarise a HULK_PROF sampling profile of a Wine-build replay (opt1; src/platform/sdl/xdk/startup.cpp).

  build/venv/bin/python tools/opt_prof.py PROF MAP [--bindings bindings.json] [--top 40] [--tu-map tu.json]

PROF is the replay's trace.txt.prof (`prof samples S frame F` then `eip count` lines), MAP the link's hulk-strict.map
(lld-link /map), bindings.json wine_link's binding map (its `definitions`: XBE address -> symbol; a symbol defined
there is a game function). Prints the samples by class (game function, platform code, bgfx/bx, the CRT import
thunks, outside the image = Wine/host DLLs), the top functions and, with --by-obj, the top objects.
"""
import argparse
import bisect
import collections
import json
import re


# the game's TU objects in the link: content-hash names, plain or with wine_link's prefixes (vtables, rebinds, ...)
GAME_OBJ = re.compile(r"^(?:[a-z]{2}_)?[0-9a-f]{20}\.obj$")


def load_map(path):
    syms = []
    rx = re.compile(r"^\s*0001:[0-9a-f]+\s+(\S+)\s+([0-9a-f]{16})\s+(?:f\s+)?(?:i\s+)?(\S+)\s*$")
    for l in open(path, errors="replace"):
        m = rx.match(l)
        if m:
            syms.append((int(m.group(2), 16), m.group(1), m.group(3)))
    syms.sort()
    return syms


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("prof")
    ap.add_argument("map")
    ap.add_argument("--bindings")
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--by-obj", action="store_true")
    a = ap.parse_args()
    syms = load_map(a.map)
    addrs = [s[0] for s in syms]
    lo, hi = (syms[0][0], syms[-1][0] + 0x10000) if syms else (0, 0)
    game = set()
    if a.bindings:
        game = set(json.load(open(a.bindings))["definitions"].values())
    hdr, hist = None, collections.Counter()
    for l in open(a.prof):
        if l.startswith("prof"):
            hdr = l.strip()
            continue
        e, c = l.split()
        hist[int(e, 16)] += int(c)
    tot = sum(hist.values())
    cls, fn, obj = collections.Counter(), collections.Counter(), collections.Counter()
    for eip, c in hist.items():
        if not (lo <= eip < hi):
            cls["outside the image (Wine, host DLLs, SDL3)"] += c
            fn["<outside 0x%04xxxxx>" % (eip >> 20)] += c
            continue
        i = bisect.bisect_right(addrs, eip) - 1
        _, name, o = syms[i]
        if name in game or GAME_OBJ.match(o):
            k = "game function"
        elif o.startswith(("bgfx:", "bx:")):
            k = "bgfx/bx"
        elif o.startswith("msvcrt:") or name.startswith("__imp_"):
            k = "CRT import thunks"
        else:
            k = "platform / other image code"
        cls[k] += c
        fn[(k[:4], name)] += c
        obj[o] += c
    print(hdr, "| %d samples" % tot)
    for k, c in cls.most_common():
        print("  %5.1f%%  %s" % (100.0 * c / tot, k))
    print("top functions:")
    for k, c in fn.most_common(a.top):
        print("  %5.2f%%  %s" % (100.0 * c / tot, k if isinstance(k, str) else "%s %s" % k))
    if a.by_obj:
        print("top objects:")
        for k, c in obj.most_common(a.top):
            print("  %5.2f%%  %s" % (100.0 * c / tot, k))


if __name__ == "__main__":
    main()
