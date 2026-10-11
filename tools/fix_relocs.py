#!/usr/bin/env python3
"""Rescue byte-exact attempts that fail only the reference check (tools/verify_relocs.py).

The farm scores an attempt 0.99 when its bytes match but a call or global points at the wrong
address. The commonest cause is one declared callee standing for two different functions:
packets label both `operator delete` (0x8d330) and `operator delete[]` (0x8d340) as
`thunk_FUN_00267090`, so a single declaration produces "inconsistent". This tool:

1. scans the farm's saved attempts (build/farm/work/*/A/, build/farm/bench/*/work/A/,
   build/farm/agent-work/*/A_N.cpp) for functions that are not yet in matches/;
2. installs any attempt that already passes both checks (the checker has improved since);
3. for an "inconsistent" callee, splits its call sites between per-target names, in reloc order
   first, then every assignment up to a small cap, and installs the first variant that passes.

Usage:
  tools/fix_relocs.py                 # candidates: lane best score >= 0.985, not yet matched
  tools/fix_relocs.py --only FILE     # addresses listed in FILE
  tools/fix_relocs.py --dry-run       # report, don't install
"""
import argparse
import glob
import itertools
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from collections import Counter
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import verify_relocs as vr  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DELETE = {0x8d330: "operator delete", 0x8d340: "operator delete[]"}
MAX_TRIES = 64


def attempts(addr):
    pats = ["build/farm/work/*/%s/*.cpp" % addr, "build/farm/bench/*/work/%s/*.cpp" % addr,
            "build/farm/bench/*/work/%s.cpp" % addr, "build/farm/agent-work/*/%s_*.cpp" % addr]
    files = []
    for p in pats:
        files += glob.glob(os.path.join(ROOT, p))
    return sorted(set(files), key=os.path.getmtime, reverse=True)


def reloc_targets(src, addr):
    """[(symbol name, target VA)] for each relocation of the matched function, in code order."""
    st = vr.state()
    xbe = st["xbe"]
    r = vr.compare(src, addr)
    with tempfile.TemporaryDirectory() as tmp:
        coff = vr.Coff(vr.compile_obj(src, vr.DEFAULT_FLAGS, tmp))
    sym = next(s for s in coff.function_symbols() if s[0] == r["symbol"])
    out = []
    for off, target_sym, typ, addend_bytes in coff.function_relocs(sym):
        if target_sym is None or typ not in (vr.REL32, vr.DIR32):
            continue
        orig, = struct.unpack("<i", xbe.data[xbe.offset(addr + off):xbe.offset(addr + off) + 4])
        addend, = struct.unpack("<i", addend_bytes)
        base = addr + off + 4 if typ == vr.REL32 else 0
        out.append((target_sym[0], (base + orig - addend) & 0xFFFFFFFF))
    return out


def source_name(mangled):
    """`?FUN_0022b980@@YAXPAX@Z` -> `FUN_0022b980`, `_FUN_x` -> `FUN_x`, `?f@C@@...` -> `f`."""
    if mangled.startswith("?"):
        return mangled[1:].split("@")[0]
    return mangled.lstrip("_").split("@")[0]


CALL_PREV = re.compile(r"(^|[=(,;{}!?:&|+\-*/<>]|->|\.|\breturn|\belse)\s*$")


def occurrences(text, name):
    """(use sites, declaration line spans) of `name(` (or of `name` for data) in text."""
    calls, decls = [], []
    if not re.search(r"\b%s\s*\(" % re.escape(name), text):  # data: first mention declares it
        ms = list(re.finditer(r"\b%s\b" % re.escape(name), text))
        if ms:
            ls = text.rfind("\n", 0, ms[0].start()) + 1
            le = text.find("\n", ms[0].end())
            decls.append((ls, le if le >= 0 else len(text)))
        return ms[1:], decls
    for m in re.finditer(r"\b%s\s*\(" % re.escape(name), text):
        line_start = text.rfind("\n", 0, m.start()) + 1
        before = text[line_start:m.start()]
        if CALL_PREV.search(before) or not before.strip():
            calls.append(m)
        else:
            line_end = text.find("\n", m.end())
            decls.append((line_start, line_end if line_end >= 0 else len(text)))
    return calls, decls


def variant(text, name, calls, decl, assign):
    """Rename call i to assign[i]; clone the declaration once per new plain name."""
    new_names = sorted({n for n in assign if not n.startswith("operator ") and n != name})
    pieces, pos = [], 0
    for m, n in zip(calls, assign):
        pieces.append(text[pos:m.start()])
        pieces.append(n + ("(" if m.group(0).endswith("(") else ""))
        pos = m.end()
    pieces.append(text[pos:])
    out = "".join(pieces)
    if new_names:
        if decl is None:
            return None
        line = text[decl[0]:decl[1]]
        # Several declarations can share a line: clone only the statement naming `name`.
        stmts = [x for x in re.findall(r"[^;]*;", line) if re.search(r"\b%s\b" % re.escape(name), x)]
        if len(stmts) == 1 and "{" not in stmts[0]:
            line = stmts[0].strip()
        if "virtual" in line:
            return None
        clones = "".join("\n" + re.sub(r"\b%s\b" % re.escape(name), n, line) for n in new_names)
        # The declaration sits before the body, so its offsets are unchanged by the renames above.
        out = out[:decl[1]] + clones + out[decl[1]:]
    return out


def try_split(src, addr, res):
    """Variants of src that give each target of an inconsistent callee its own name."""
    names = [n for kind, n in res.get("issues", []) if kind == "inconsistent"]
    if not names:
        return
    relocs = reloc_targets(src, addr)
    text = open(src).read()
    for mangled in dict.fromkeys(names):
        name = source_name(mangled)
        targets = [t for s, t in relocs if s == mangled]
        calls, decls = occurrences(text, name)
        if not calls or not targets:
            continue
        member = any(text[max(0, m.start() - 2):m.start()] in ("->",) or text[m.start() - 1:m.start()] == "."
                     for m in calls)

        def label(t):
            if t in DELETE and not member:
                return DELETE[t]
            prefix = "FUN" if any(m.group(0).endswith("(") for m in calls) else "DAT"
            return "%s_%08x" % (prefix, t) if ("%s_%08x" % (prefix, t)) != name else name
        decl = decls[0] if decls else None
        uniq = list(dict.fromkeys(targets))
        tried = set()
        order = []
        if len(calls) == len(targets):
            order.append(tuple(label(t) for t in targets))
        labels = [label(t) for t in uniq]
        for combo in itertools.product(labels, repeat=len(calls)):
            if len(order) >= MAX_TRIES:
                break
            order.append(combo)
        for assign in order:
            if assign in tried:
                continue
            tried.add(assign)
            v = variant(text, name, calls, decl, assign)
            if v is not None:
                yield v


def work(addr):
    addr_i = int(addr, 16)
    seen = Counter()
    for src in attempts(addr):
        try:
            res = vr.check(src, addr_i)
        except Exception as e:  # noqa: BLE001
            seen["error"] += 1
            continue
        seen[res["status"]] += 1
        if res["status"] == "ok":
            return {"addr": addr, "status": "ok_as_is", "src": src}
        if res["status"] != "bad":
            continue
        kinds = sorted({k for k, _ in res["issues"]})
        try:
            variants = list(try_split(src, addr_i, res))
        except Exception as e:  # noqa: BLE001
            variants = []
        with tempfile.TemporaryDirectory() as tmp:
            for i, v in enumerate(variants):
                path = os.path.join(tmp, "%s.cpp" % addr)
                open(path, "w").write(v)
                try:
                    r2 = vr.check(path, addr_i)
                except Exception:  # noqa: BLE001
                    continue
                if r2["status"] == "ok":
                    keep = os.path.join(ROOT, "build/farm/fix-relocs", "%s.cpp" % addr)
                    os.makedirs(os.path.dirname(keep), exist_ok=True)
                    shutil.copy(path, keep)
                    return {"addr": addr, "status": "fixed", "src": keep, "from": src, "tries": i + 1}
        seen["bad:" + ",".join(kinds)] += 1
    return {"addr": addr, "status": "unfixed", "seen": dict(seen)}


def candidates():
    best = {}
    for f in glob.glob(os.path.join(ROOT, "build/farm/lanes/*.jsonl")) + glob.glob(os.path.join(ROOT, "build/farm/bench/*.jsonl")):
        for line in open(f):
            try:
                r = json.loads(line)
            except ValueError:
                continue
            a, s = r.get("addr"), r.get("bestScore")
            if a and s is not None and s > best.get(a, -1):
                best[a] = s
    return sorted(a for a, s in best.items() if s >= 0.985)


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--only", help="file with addresses to try")
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--jobs", type=int, default=8)
    p.add_argument("--out", default=os.path.join(ROOT, "build/farm/fix-relocs.jsonl"))
    a = p.parse_args()
    addrs = [l.split()[0] for l in open(a.only) if l.strip()] if a.only else candidates()
    addrs = [x for x in addrs if not os.path.exists(os.path.join(ROOT, "matches", x + ".cpp"))]
    print("%d candidates" % len(addrs), flush=True)
    counts, why = Counter(), Counter()
    installed = []
    with open(a.out, "w") as out, Pool(a.jobs) as pool:
        for r in pool.imap_unordered(work, addrs):
            out.write(json.dumps(r) + "\n")
            counts[r["status"]] += 1
            for k in r.get("seen", {}):
                if k.startswith("bad:"):
                    why[k[4:]] += 1
            if r["status"] in ("ok_as_is", "fixed"):
                print("  %s %s" % (r["addr"], r["status"]), flush=True)
                if not a.dry_run:
                    dst = os.path.join(ROOT, "matches", r["addr"] + ".cpp")
                    shutil.copy(r["src"], dst)
                    installed.append(dst)
    if installed:
        subprocess.run([sys.executable, os.path.join(ROOT, "tools/format_matches.py")] + installed, check=False)
    print("results:", dict(counts))
    print("remaining issue kinds (per unfixed attempt):", dict(why.most_common(12)))


if __name__ == "__main__":
    main()
