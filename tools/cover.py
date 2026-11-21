#!/usr/bin/env python3
"""Function-entry coverage of a Wine-build replay (cover1, D155; docs/checkpoints.md "Coverage").

  # the address list the image arms (HULK_COVER=<list>, src/platform/sdl/xdk/startup.cpp): every function symbol of
  # the game's objects in the link's .map
  build/venv/bin/python tools/cover.py list MAP --out cover.lst
  # the replay's hits (<trace>.cov) against the tree: reached functions and bytes by area, TU and first frame
  build/venv/bin/python tools/cover.py report COV MAP [--bindings bindings.json] [--json OUT] [--list-unreached OUT]

The image puts a one-shot int3 on each listed address; the first execution restores the byte and notes the frame,
so a hit means "this function was entered at least once". Tree functions are found in the map by their `// sym:`
pin, else by the Wine link's binding map (`definitions`: XBE address -> symbol). Blocks pinned to an MSVC label
(`$L#k@owner`) are pieces of their owner's code and count as reached with it. Identical functions lld folded (ICF)
share one address: a hit there is reported for every function folded into it (`folded`). Bytes are the original
function sizes from the block headers (the XBE's bytes), not the clang image's.
"""
import argparse
import bisect
import collections
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

GAME_OBJ = re.compile(r"^(?:[a-z]{2}_)?[0-9a-f]{20}\.obj$")   # (as tools/opt_prof.py: the tree's TU objects)
MAP_LINE = re.compile(r"^\s*0001:[0-9a-f]+\s+(\S+)\s+([0-9a-f]{16})\s+(?:f\s+)?(?:i\s+)?(\S+)\s*$")
AREAS = ("src/game", "src/engine", "src/platform/xbox")


def load_map(path):
    """[(va, symbol, object)] of .text"""
    out = []
    for l in open(path, errors="replace"):
        m = MAP_LINE.match(l)
        if m:
            out.append((int(m.group(2), 16), m.group(1), m.group(3)))
    return out


INSN = re.compile(r"^\s*([0-9a-f]{8}):\s+(\S+)(?:\s+(.*))?$")
BRANCH = re.compile(r"^j[a-z]+$")


def function_ranges(syms):
    """[(start, end)] of the game objects' functions: from each symbol to the next symbol of any object"""
    starts = sorted({va for va, _s, _o in syms})
    game = sorted({va for va, _s, o in syms if GAME_OBJ.match(o)})
    out = []
    for va in game:
        i = bisect.bisect_right(starts, va)
        out.append((va, starts[i] if i < len(starts) else va + 0x10000))
    return out


def basic_blocks(exe, ranges, llvm):
    """{function start: [(leader, end)]}: leaders are the entry, direct branch targets inside the function and the
    first non-padding instruction after a branch or return; a block ends at the next leader (or the function's end
    less its trailing padding)"""
    import subprocess
    lo, hi = ranges[0][0], ranges[-1][1]
    p = subprocess.run([os.path.join(llvm, "llvm-objdump"), "-d", "--no-show-raw-insn", "--start-address=0x%x" % lo, "--stop-address=0x%x" % hi, exe],
                       capture_output=True, text=True, errors="replace")
    insns = []
    for l in p.stdout.splitlines():
        m = INSN.match(l)
        if m:
            insns.append((int(m.group(1), 16), m.group(2), m.group(3) or ""))
    addrs = [x[0] for x in insns]
    insn_set = set(addrs)       # (a branch into the middle of an instruction is never armed)
    out = {}
    for start, end in ranges:
        i, j = bisect.bisect_left(addrs, start), bisect.bisect_left(addrs, end)
        body = insns[i:j]
        while body and body[-1][1] in ("nop", "nopl", "nopw", "int3", "ud2"):
            body.pop()
        if not body:
            out[start] = [(start, start + 1)]
            continue
        fend = end if j >= len(insns) else insns[j][0]
        last = body[-1][0]
        leaders = {start}
        after = False
        for k, (va, mn, ops) in enumerate(body):
            if after and mn not in ("nop", "nopl", "nopw", "int3"):
                leaders.add(va)
                after = False
            if BRANCH.match(mn) or mn.startswith("ret"):
                after = True
                t = re.match(r"^0x([0-9a-f]+)\b", ops)
                if BRANCH.match(mn) and t:
                    tv = int(t.group(1), 16)
                    if start <= tv <= last and tv in insn_set:
                        leaders.add(tv)
        ls = sorted(x for x in leaders if start <= x <= last)
        bend = body[-1][0] + 1
        # (the block of the last instruction runs to the next instruction's address)
        nxt = bisect.bisect_right(addrs, last)
        bend = addrs[nxt] if nxt < len(addrs) else fend
        out[start] = [(x, ls[n + 1] if n + 1 < len(ls) else bend) for n, x in enumerate(ls)]
    return out


def cmd_list(a):
    syms = load_map(a.map)
    if not a.bb:
        addrs = sorted({va for va, _s, o in syms if GAME_OBJ.match(o)})
    else:
        sys.path.insert(0, os.path.join(ROOT, "tools"))
        from clang_probe import LLVM
        bbs = basic_blocks(a.exe, function_ranges(syms), LLVM)
        addrs = sorted({x for v in bbs.values() for x, _e in v})
        json.dump({"%08x" % f: [[x, e - x] for x, e in v] for f, v in bbs.items()}, open(a.out + ".blocks.json", "w"))
        print("%d functions, %d blocks (%s.blocks.json)" % (len(bbs), len(addrs), a.out))
    with open(a.out, "w") as f:
        f.write("".join("%08x\n" % x for x in addrs))
    print("%d addresses -> %s" % (len(addrs), a.out))


def tree_blocks(root):
    import tree_tu
    out = []
    for area in AREAS:
        for p in sorted(glob.glob(os.path.join(root, area, "**", "*.cpp"), recursive=True)):
            rel = os.path.relpath(p, root)
            for b in tree_tu.scan(p)["blocks"]:
                out.append({"addr": int(b["addr"], 16), "name": b["name"], "size": b["size"], "kind": b["kind"],
                            "sym": b["sym"], "tu": rel})
    return out


def area_of(tu):
    parts = tu.split("/")
    return "/".join(parts[:2]) if parts[1] != "platform" else "/".join(parts[:3])


def cmd_report(a):
    hits, epochs, hdr = {}, {}, None
    for l in open(a.cov):
        if l.startswith("cover"):
            hdr = l.strip()
            continue
        w = l.split()
        hits[int(w[0], 16)] = int(w[1])
        if len(w) > 2:          # (HULK_COVER_EPOCH: the windows in which the address ran)
            epochs[int(w[0], 16)] = int(w[2])
        if len(w) > 3 and a.frames:
            # (rev5, D162 piece 1) only the windows inside the frames a reference compares count: the bitmap's
            # windows (k*n .. k*n+n-1) that overlap --frames FROM-TO
            n = int(re.search(r"epoch (\d+)", hdr or "").group(1))
            lo, hi = (int(x) for x in a.frames.split("-"))
            bits = bytes.fromhex(w[3])
            epochs[int(w[0], 16)] = sum(1 for k in range(len(bits) * 8) if bits[k // 8] >> (k % 8) & 1
                                        and k * n <= hi and k * n + n - 1 >= lo)
    syms = load_map(a.map)
    by_sym = {}
    for va, s, _o in syms:
        by_sym.setdefault(s, va)
        if s.startswith("_"):
            by_sym.setdefault(s[1:], va)
    defs = {}
    if a.bindings:
        defs = {int(k, 16): v for k, v in json.load(open(a.bindings))["definitions"].items()}
    bbs = {}
    if a.blocks:
        bbs = {int(k, 16): v for k, v in json.load(open(a.blocks)).items()}
    blocks = tree_blocks(a.tree)
    owner_of = {}
    found = collections.Counter()
    for b in blocks:
        s, va = b["sym"], None
        if s and s.startswith("$L#"):
            owner_of[b["addr"]] = s.split("@", 1)[1]
            found["label"] += 1
            continue
        if s and s in by_sym:
            va = by_sym[s]
            found["pin"] += 1
        elif b["addr"] in defs and defs[b["addr"]] in by_sym:
            va = by_sym[defs[b["addr"]]]
            found["binding"] += 1
        elif s and re.search(r"@@U?[A-Z]+M", s) and re.sub(r"(@@[A-Z]{2,3})M", r"\1N", s) in by_sym:
            va = by_sym[re.sub(r"(@@[A-Z]{2,3})M", r"\1N", s)]     # (a float return the Wine build widens to double)
            found["float-return"] += 1
        else:
            found["not in image"] += 1
        b["va"] = va
    for b in blocks:
        if b["addr"] in owner_of:
            ow = owner_of[b["addr"]]
            b["va"] = by_sym.get(ow, by_sym.get(ow.lstrip("_")))
            b["label"] = True
    at_va = collections.Counter(b["va"] for b in blocks if b.get("va") is not None and not b.get("label"))
    stat = collections.defaultdict(lambda: collections.Counter())
    by_tu = collections.defaultdict(lambda: collections.Counter())
    first = collections.Counter()
    reached, unreached, unmapped = [], [], []
    for b in blocks:
        ar = area_of(b["tu"])
        st = stat[ar]
        st["functions"] += 1
        st["bytes"] += b["size"]
        if b.get("va") is None:
            st["unmapped"] += 1
            st["unmapped_bytes"] += b["size"]
            unmapped.append(b)
            continue
        fr = hits.get(b["va"])
        folded = at_va[b["va"]] > 1
        if folded:
            st["folded"] += 1
        bt = by_tu[b["tu"]]
        bt["functions"] += 1
        bt["bytes"] += b["size"]
        frac = None
        if bbs.get(b["va"]) and not b.get("label"):
            tot_b = sum(n for _x, n in bbs[b["va"]])
            frac = sum(n for x, n in bbs[b["va"]] if x in hits) / max(1, tot_b)
            st["bb_blocks"] += len(bbs[b["va"]])
            st["bb_hit"] += sum(1 for x, _n in bbs[b["va"]] if x in hits)
            st["est_covered_bytes"] += b["size"] * frac
            bt["est_covered_bytes"] += b["size"] * frac
            b["frac"] = frac
            hit_ep = [epochs.get(x, 0) for x, _n in bbs[b["va"]] if x in hits]
            b["min_epochs"] = min(hit_ep) if hit_ep and epochs else None
        if fr is not None:
            st["reached"] += 1
            st["reached_bytes"] += b["size"]
            if folded:
                st["reached_folded"] += 1
            bt["reached"] += 1
            bt["reached_bytes"] += b["size"]
            first[min(fr // 1000 * 1000, 60000)] += 1
            reached.append((b, fr))
        else:
            unreached.append(b)
    tot = collections.Counter()
    for v in stat.values():
        tot.update(v)
    print(hdr)
    print("blocks found in the image by: %s" % dict(found))
    print("%-20s %8s %8s %6s %11s %11s %6s %8s %8s %9s %9s %6s" % ("area", "funcs", "reached", "%", "bytes", "reached B",
                                                       "%B", "unmapped", "folded", "blocks", "blk hit", "estB%"))
    for ar, v in sorted(stat.items()) + [("total", tot)]:
        print("%-20s %8d %8d %5.1f%% %11d %11d %5.1f%% %8d %8d %9d %9d %5.1f%%" % (
            ar, v["functions"], v["reached"], 100.0 * v["reached"] / max(1, v["functions"]), v["bytes"],
            v["reached_bytes"], 100.0 * v["reached_bytes"] / max(1, v["bytes"]), v["unmapped"], v["folded"],
            v["bb_blocks"], v["bb_hit"], 100.0 * v["est_covered_bytes"] / max(1, v["bytes"])))
    print("first hit by frame (thousands):", " ".join("%d:%d" % kv for kv in sorted(first.items())))
    if epochs:
        hist = collections.Counter(min(e, 64) for e in epochs.values())
        print("block windows (HULK_COVER_EPOCH; 64 = 64 or more):", " ".join("%d:%d" % kv for kv in sorted(hist.items())))
    if a.json:
        json.dump({"header": hdr, "found": found, "areas": stat, "total": tot,
                   "block_epochs": {"%08x" % x: e for x, e in epochs.items()},
                   "first_by_kframe": first,
                   "tus": by_tu,
                   "reached": [{"addr": "0x%08x" % b["addr"], "name": b["name"], "size": b["size"], "tu": b["tu"],
                                "frame": fr, "folded": at_va[b["va"]] > 1, "label": bool(b.get("label")),
                                "block_frac": None if b.get("frac") is None else round(b["frac"], 3),
                                "min_block_epochs": b.get("min_epochs")}
                               for b, fr in reached],
                   "unreached": [{"addr": "0x%08x" % b["addr"], "name": b["name"], "size": b["size"], "tu": b["tu"]}
                                 for b in unreached],
                   "unmapped": [{"addr": "0x%08x" % b["addr"], "name": b["name"], "size": b["size"], "tu": b["tu"],
                                 "sym": b["sym"]} for b in unmapped]},
                  open(a.json, "w"), indent=0)
        print("->", a.json)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    s = sp.add_parser("list")
    s.add_argument("map")
    s.add_argument("--bb", action="store_true", help="every basic-block leader (needs --exe; also writes OUT.blocks.json)")
    s.add_argument("--exe", help="the linked image (hulk-strict.exe) to disassemble")
    s.add_argument("--out", required=True)
    s = sp.add_parser("report")
    s.add_argument("cov")
    s.add_argument("map")
    s.add_argument("--bindings")
    s.add_argument("--tree", default=ROOT)
    s.add_argument("--blocks", help="list --bb's OUT.blocks.json: block-level byte coverage")
    s.add_argument("--frames", metavar="FROM-TO", help="count only the windows overlapping these frames (the frames "
                   "the recording's reference compares; needs a hit file with window bitmaps)")
    s.add_argument("--json")
    a = ap.parse_args()
    return {"list": cmd_list, "report": cmd_report}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
