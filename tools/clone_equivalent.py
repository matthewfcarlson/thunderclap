#!/usr/bin/env python3
"""Prove functions equivalent by reusing the source of a same-shaped function already in equivalent/.

The equivalence counterpart of tools/clone_matches.py. Templates and per-class copies leave many
functions whose code is identical to a proven one apart from the addresses they reference. For each
such pair this tool lines the two functions up instruction by instruction (same shape means the same
instruction sequence), collects every referenced address that moved (callees, globals, vftables), renames
the identifiers and `equiv-map`/`equiv-conv` lines in the proven source that embed the old address, and
runs tools/equiv.py on the copy. A copy is installed when it is equivalent with no level-2 conflicts and
at least 75% branch coverage, run at 3000 inputs, the same bar as an agent's pass, and passes the Wine gate
(`--wine` at 600 inputs, tools/wine_gate.py; --no-wine-gate or HULK_NO_WINE_GATE=1 skips it).

Usage:
  tools/clone_equivalent.py [--dry-run] [--limit N] [--jobs N] [--skip FILE...]
"""
import argparse
import csv
import json
import os
import re
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from clone_matches import IMAGE, shape, _shape_job  # noqa: E402
import clone_matches  # noqa: E402
from compare import XBE_PATH, load_functions  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FLOOR = 0.75


def refs(addr):
    """Every image address the function references, in instruction order (rel32 targets included)."""
    from capstone import CS_ARCH_X86, CS_MODE_32, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    if clone_matches._XBE is None:
        clone_matches._XBE = Xbe(XBE_PATH)
    x = clone_matches._XBE
    size = load_functions()[addr][0]
    o = x.offset(addr)
    out = []
    for i in md.disasm(x.data[o:o + size], addr):
        b = bytes(i.bytes)
        if i.mnemonic in ("call", "jmp") and b[0] in (0xE8, 0xE9):
            out.append((i.address + i.size + int.from_bytes(b[1:5], "little", signed=True)) & 0xFFFFFFFF)
            continue
        for off in (i.disp_offset, i.imm_offset):
            if off and off + 4 <= len(b):
                v = int.from_bytes(b[off:off + 4], "little")
                if IMAGE[0] <= v < IMAGE[1]:
                    out.append(v)
    return out


def address_map(src, dst):
    m = {}
    for a, b in zip(refs(src), refs(dst)):
        if a != b:
            if m.get(a, b) != b:
                return None  # one old address maps to two new ones: the source can't be renamed
            m[a] = b
    m[src] = dst
    return m


def rename(text, amap):
    for old, new in amap.items():
        for fmt in ("%08x", "%08X"):
            text = re.sub(r"(?<![0-9A-Fa-f])%s(?![0-9A-Fa-f])" % (fmt % old), fmt % new, text)
        # equiv-map values and other unpadded 0x literals
        text = re.sub(r"0x0*%x\b" % old, "0x%08x" % new, text, flags=re.I)
    return text


def run_equiv(path, addr, *extra):
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/equiv.py"), path, addr, "--json", *extra],
                       capture_output=True, text=True, cwd=ROOT)
    return json.loads(r.stdout)


def accepted(r):
    if r.get("status") != "equivalent" or r["level2"]["conflicts"]:
        return False
    cv = r["level3"]["coverage"]
    return not cv["edges_total"] or cv["edges_covered"] / cv["edges_total"] >= FLOOR


def clone(pair):
    dst, src_addr = pair
    d, s = int(dst, 16), int(src_addr, 16)
    try:
        amap = address_map(s, d)
    except Exception as e:  # noqa: BLE001
        return {"addr": dst, "from": src_addr, "status": "error", "detail": repr(e)[:120]}
    if amap is None:
        return {"addr": dst, "from": src_addr, "status": "ambiguous_addresses"}
    lines = open(os.path.join(ROOT, "equivalent", src_addr + ".cpp")).read().split("\n")
    body = "\n".join([l for l in lines[:2] if not l.startswith("// STATUS:") and " @ 0x" not in l] + lines[2:])
    text = rename(body, amap)
    with tempfile.TemporaryDirectory() as tmp:
        path = os.path.join(tmp, dst + ".cpp")
        open(path, "w").write(text)
        try:
            # 3000 inputs: the default count let wrong sources through (2026-10-12 re-check)
            r = run_equiv(path, dst, "--inputs", "3000")
        except Exception as e:  # noqa: BLE001
            return {"addr": dst, "from": src_addr, "status": "error", "detail": repr(e)[:120]}
        if accepted(r):
            # (round 23) the Wine gate: --wine at 600 inputs as well (tools/wine_gate.py; --no-wine-gate skips it)
            import wine_gate
            w = wine_gate.gate(path, d) if wine_gate.disabled() else \
                wine_gate.gate(path, d, rep=run_equiv(path, dst, "--wine", "--inputs", str(wine_gate.WINE_INPUTS),
                                                      "--max-inputs", str(wine_gate.WINE_INPUTS)))
            if not w["ok"]:
                return {"addr": dst, "from": src_addr, "status": "wine_gate", "detail": w["reason"]}
    if not accepted(r):
        cv = (r.get("level3") or {}).get("coverage") or {}
        return {"addr": dst, "from": src_addr, "status": r.get("status", "?"),
                "coverage": "%s/%s" % (cv.get("edges_covered"), cv.get("edges_total"))}
    l3 = r["level3"]
    c = l3["coverage"]
    head = ("// STATUS: equivalent (tools/equiv.py level 3: %d inputs, branch coverage %d/%d%s)\n"
            "// %s @ %s\n" % (l3["inputs_run"], c["edges_covered"], c["edges_total"],
                              "" if c["complete"] else ", incomplete", r.get("target") or dst, dst))
    return {"addr": dst, "from": src_addr, "status": "ok", "text": head + text}


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--no-wine-gate", action="store_true", help="skip the --wine check (no Wine toolchain here)")
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--skip", nargs="*", default=[], help="files listing addresses to leave alone (agents' batches)")
    p.add_argument("--min-size", type=int, default=32)
    p.add_argument("--out", default=os.path.join(ROOT, "build/farm/clone-equivalent.jsonl"))
    a = p.parse_args()
    if a.no_wine_gate:
        os.environ["HULK_NO_WINE_GATE"] = "1"      # (pool workers inherit it)
    rows = list(csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))))
    addrs = ["0x%08x" % int(r["address"], 16) for r in rows if int(r["size"]) >= a.min_size]
    done = {x for x in addrs if os.path.exists(os.path.join(ROOT, "matches", x + ".cpp"))}
    proven = {x for x in addrs if os.path.exists(os.path.join(ROOT, "equivalent", x + ".cpp"))}
    with Pool(a.jobs) as pool:
        shapes = dict(pool.imap_unordered(_shape_job, addrs, chunksize=64))
    by_shape = defaultdict(list)
    for x in sorted(proven):
        if shapes.get(x):
            by_shape[shapes[x]].append(x)
    skip = set()
    for f in a.skip:
        skip |= {l.split()[0] for l in open(f) if l.strip()}
    pairs = [(x, by_shape[shapes[x]][0]) for x in addrs
             if x not in done and x not in proven and x not in skip and shapes.get(x) and shapes[x] in by_shape]
    if a.limit:
        pairs = pairs[:a.limit]
    print("%d unproven functions share their code shape with an equivalent one" % len(pairs), flush=True)
    counts = Counter()
    with open(a.out, "w") as out, Pool(a.jobs) as pool:
        for i, r in enumerate(pool.imap_unordered(clone, pairs)):
            text = r.pop("text", None)
            out.write(json.dumps(r) + "\n")
            counts[r["status"]] += 1
            dst = os.path.join(ROOT, "equivalent", r["addr"] + ".cpp")
            if text and not a.dry_run and not os.path.exists(dst):
                open(dst, "w").write(text)
            if (i + 1) % 20 == 0:
                print("  %d/%d %s" % (i + 1, len(pairs), dict(counts)), flush=True)
    print("results:", dict(counts))


if __name__ == "__main__":
    main()
