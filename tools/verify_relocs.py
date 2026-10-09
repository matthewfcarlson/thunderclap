#!/usr/bin/env python3
"""Verify that a match's relocations point at the right things (codegen match -> full match).

compare.py masks relocated bytes, so a TU calling the wrong function or loading the wrong
global still "matches". For an exact match, offsets line up, so every relocation in our object
can be paired with the 4 original bytes at the same offset. That gives the original target, which
is then checked:

  string literal  ??_C@...     same bytes at the target
  float constant  __real@...   same bits at the target
  vftable         ??_7...@6B@  target is a vftable (and that class's, when the class is in RTTI)
  call / jmp      REL32        target is a function start
  data            DIR32        target is inside .rdata/.data/.bss
  consistency                  one symbol -> one target within the function; two symbols -> one target is a warning

  tools/verify_relocs.py matches/0x00018b40.cpp            # one file (address from the name)
  tools/verify_relocs.py --all [--jobs 8]                  # every match -> build/reloc-report.jsonl
"""
import argparse
import csv
import json
import os
import struct
import sys
import tempfile
from collections import Counter
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(__file__))
from compare import Coff, CompileError, DEFAULT_FLAGS, compare, compile_obj, strip_padding  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
REL32, DIR32 = 0x14, 0x06

_state = {}


def state():
    if not _state:
        _state["xbe"] = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        with open(os.path.join(ROOT, "build/functions.csv")) as f:
            _state["funcs"] = {int(r["address"], 16) for r in csv.DictReader(f)}
        rtti = json.load(open(os.path.join(ROOT, "build/rtti.json")))
        vft = {}
        for c in rtti["classes"]:
            for v in c["vtables"]:
                vft[v["address"]] = c["mangled"]
        _state["vftables"] = vft
    return _state


def classify(name):
    if name.startswith("??_C@"):
        return "string"
    if name.startswith("__real@"):
        return "float"
    if name.startswith("??_7"):
        return "vftable"
    return "symbol"


def literal_bytes(coff, sym):
    """Contents of a string-literal symbol in our object (its COMDAT .rdata section)."""
    _, value, secnum, _, _ = sym
    if secnum <= 0:
        return None
    _, raw, _ = coff.sections[secnum - 1]
    end = raw.find(b"\0", value)
    return raw[value:end + 1] if end >= 0 else raw[value:]


def check(src, addr):
    st = state()
    xbe = st["xbe"]
    r = compare(src, addr)
    if r["status"] != "match":
        return {"addr": "0x%08x" % addr, "status": "not_matching", "detail": r["status"]}
    with tempfile.TemporaryDirectory() as tmp:
        try:
            coff = Coff(compile_obj(src, DEFAULT_FLAGS, tmp))
        except CompileError as e:
            return {"addr": "0x%08x" % addr, "status": "compile_error", "detail": str(e)[:200]}
    sym = next(s for s in coff.function_symbols() if s[0] == r["symbol"])
    issues, mapping = [], {}
    for off, target_sym, typ, addend_bytes in coff.function_relocs(sym):
        if target_sym is None:
            issues.append(("unknown_symbol", off))
            continue
        name = target_sym[0]
        orig, = struct.unpack("<I", xbe.data[xbe.offset(addr + off):xbe.offset(addr + off) + 4])
        addend, = struct.unpack("<i", addend_bytes)
        if typ == REL32:
            target = (addr + off + 4 + struct.unpack("<i", struct.pack("<I", orig))[0] - addend) & 0xFFFFFFFF
        elif typ == DIR32:
            target = (orig - addend) & 0xFFFFFFFF
        else:
            issues.append(("reloc_type_%#x" % typ, name))
            continue
        kind = classify(name)
        if mapping.get(name, target) != target:
            issues.append(("inconsistent", name))
        mapping[name] = target
        if kind == "string":
            ours = literal_bytes(coff, target_sym)
            o = xbe.offset(target)
            if ours is None or o is None or xbe.data[o:o + len(ours)] != ours:
                issues.append(("string_mismatch", name))
        elif kind == "float":
            hexbits = name[len("__real@"):]
            want = bytes.fromhex(hexbits)[::-1]
            o = xbe.offset(target)
            if o is None or xbe.data[o:o + len(want)] != want:
                issues.append(("float_mismatch", name))
        elif kind == "vftable":
            owner = st["vftables"].get(target)
            if owner is None:
                issues.append(("not_a_vftable", name))
            else:
                ours_cls = name[len("??_7"):].split("@6B")[0]
                if ".?AV" + ours_cls + "@" != owner and ".?AU" + ours_cls + "@" != owner \
                        and ours_cls + "@" not in owner:
                    issues.append(("vftable_of_other_class", name))  # names may be invented: warning
        elif typ == REL32:
            if target not in st["funcs"]:
                # Usually a function Ghidra didn't split out; not proof of a wrong match.
                issues.append(("call_target_not_known_function", name))
        else:
            sec = xbe.section_of(target)
            if sec is None:
                issues.append(("data_outside_image", name))
            elif sec.name == ".text" and target in st["funcs"]:
                issues.append(("function_address_as_data", name))  # e.g. int global holding &func: type wrong, bytes fine
            elif sec.name == ".text" and not (addr <= target < addr + 0x10000):
                issues.append(("data_in_code", name))
            # Other sections (.rdata/.data, XDK D3D/XGRPH/DSOUND data, BINKDATA) hold real globals.
    targets = Counter(mapping.values())
    for name, t in mapping.items():
        if targets[t] > 1 and classify(name) == "symbol":
            issues.append(("aliased_target", name))
    SOFT = ("vftable_of_other_class", "aliased_target", "call_target_not_known_function", "function_address_as_data")
    hard = [i for i in issues if i[0] not in SOFT]
    return {"addr": "0x%08x" % addr, "status": "ok" if not hard else "bad", "relocs": len(mapping),
            "issues": issues, "map": {k: "0x%08x" % v for k, v in mapping.items()}}


def _job(path):
    try:
        return check(path, int(os.path.basename(path)[:-4], 16))
    except Exception as e:  # keep the sweep going
        return {"addr": os.path.basename(path)[:-4], "status": "error", "detail": repr(e)[:200]}


def main():
    p = argparse.ArgumentParser()
    p.add_argument("file", nargs="?")
    p.add_argument("--only", help="file with addresses to (re)check")
    p.add_argument("--addr", help="target address for FILE (default: from the file name)")
    p.add_argument("--json", action="store_true", help="one-line JSON (for the farm)")
    p.add_argument("--all", action="store_true")
    p.add_argument("--jobs", type=int, default=8)
    p.add_argument("--out", default=os.path.join(ROOT, "build/reloc-report.jsonl"))
    a = p.parse_args()
    if a.file:
        r = check(a.file, int(a.addr, 16)) if a.addr else _job(a.file)
        print(json.dumps(r) if a.json else json.dumps(r, indent=1))
        return
    files = sorted(os.path.join(ROOT, "matches", f) for f in os.listdir(os.path.join(ROOT, "matches")))
    if a.only:
        want = {l.strip() for l in open(a.only) if l.strip()}
        files = [f for f in files if os.path.basename(f)[:-4] in want]
    counts, issue_counts = Counter(), Counter()
    with open(a.out, "w") as out, Pool(a.jobs) as pool:
        for i, r in enumerate(pool.imap_unordered(_job, files, chunksize=16)):
            out.write(json.dumps(r) + "\n")
            counts[r["status"]] += 1
            for kind, _ in r.get("issues", []):
                issue_counts[kind] += 1
            if (i + 1) % 1000 == 0:
                print("  %d/%d %s" % (i + 1, len(files), dict(counts)), flush=True)
    print("results:", dict(counts))
    print("issues:", dict(issue_counts.most_common()))


if __name__ == "__main__":
    main()
