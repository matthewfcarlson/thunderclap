#!/usr/bin/env python3
"""Match unmatched functions that are copies of matched ones apart from the addresses they reference.

Templates, inlined destructors and per-class boilerplate leave many functions whose code is identical
to a function already in matches/ except for the vftable, globals or callees they point at. For each
such pair this tool compiles the matched source against the unmatched address (tools/compare.py masks
relocated bytes, so the bytes match), reads which target every symbol now resolves to
(tools/verify_relocs.py), renames each symbol whose target changed, and installs the copy once both
checks pass.

Renaming: a name containing the old address in hex (FUN_0022b980, DAT_004dd6e4, g_vft_0x3f432c) gets
the new address; any other name gets `_<new address>` appended. Real-class vftables (`??_7X@@6B@`) and
the target's own name aren't renamed, so those pairs are skipped.

Usage:
  tools/clone_matches.py [--dry-run] [--limit N] [--jobs N] [--skip FILE...]
"""
import argparse
import csv
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import verify_relocs as vr  # noqa: E402
from compare import XBE_PATH, load_functions  # noqa: E402
from xbe import Xbe  # noqa: E402
from fix_relocs import source_name  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IMAGE = (0x10000, 0x800000)
_XBE = None


def shape(addr):
    """The function's bytes with every image address and rel32 branch target zeroed."""
    from capstone import CS_ARCH_X86, CS_MODE_32, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    global _XBE
    if _XBE is None:
        _XBE = Xbe(XBE_PATH)
    size = load_functions()[addr][0]
    o = _XBE.offset(addr)
    code = _XBE.data[o:o + size]
    out = bytearray()
    for i in md.disasm(code, addr):
        b = bytearray(i.bytes)
        if i.mnemonic in ("call", "jmp") and b[0] in (0xE8, 0xE9):
            b[1:5] = b"\0\0\0\0"  # rel32 to another function; short/near jumps inside stay
        else:
            for off in (i.disp_offset, i.imm_offset):
                if off and off + 4 <= len(b):
                    v = int.from_bytes(b[off:off + 4], "little")
                    if IMAGE[0] <= v < IMAGE[1]:
                        b[off:off + 4] = b"\0\0\0\0"
        out += b
    return bytes(out)


def _shape_job(addr):
    try:
        return addr, shape(int(addr, 16))
    except Exception:  # noqa: BLE001
        return addr, None


def renamed(name, old, new):
    for fmt in ("%08x", "%x", "%08X", "%X"):
        if fmt % old in name:
            return name.replace(fmt % old, fmt % new)
    return "%s_%08x" % (name, new)


def clone(pair):
    """Try the matched source of `src_addr` on `dst_addr`; return the installed text or a reason."""
    dst, src_addr = pair
    src = os.path.join(ROOT, "matches", src_addr + ".cpp")
    d, s = int(dst, 16), int(src_addr, 16)
    try:
        before = vr.check(src, s)
        after = vr.check(src, d)
    except Exception as e:  # noqa: BLE001
        return {"addr": dst, "from": src_addr, "status": "error", "detail": repr(e)[:120]}
    if after["status"] == "not_matching":
        return {"addr": dst, "from": src_addr, "status": "bytes_differ"}
    if before["status"] != "ok":
        return {"addr": dst, "from": src_addr, "status": "template_not_ok"}
    # Rename every symbol whose target moved, even when the copy already passes: one name must not
    # stand for two addresses across matches/.
    renames = {}
    if True:
        for mangled, t_new in after["map"].items():
            t_old = before["map"].get(mangled)
            if t_old is None or t_old == t_new:
                continue
            if mangled.startswith("??_7") or mangled.startswith("??_R") or mangled.startswith("__real@") \
                    or mangled.startswith("??_C"):
                return {"addr": dst, "from": src_addr, "status": "needs_new_class_or_literal", "symbol": mangled}
            name = source_name(mangled)
            renames[name] = renamed(name, int(t_old, 16), int(t_new, 16))
    text = open(src).read()
    for old, new in renames.items():
        text = re.sub(r"\b%s\b" % re.escape(old), new, text)
    with tempfile.TemporaryDirectory() as tmp:
        path = os.path.join(tmp, dst + ".cpp")
        open(path, "w").write(text)
        try:
            r = vr.check(path, d)
        except Exception as e:  # noqa: BLE001
            return {"addr": dst, "from": src_addr, "status": "error", "detail": repr(e)[:120]}
        if r["status"] != "ok":
            return {"addr": dst, "from": src_addr, "status": "renamed_still_" + r["status"],
                    "issues": r.get("issues", [])[:4]}
        keep = os.path.join(ROOT, "build/farm/clones", dst + ".cpp")
        os.makedirs(os.path.dirname(keep), exist_ok=True)
        shutil.copy(path, keep)
    return {"addr": dst, "from": src_addr, "status": "ok", "src": keep, "renames": renames}


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--jobs", type=int, default=6)
    p.add_argument("--skip", nargs="*", default=[], help="files listing addresses to leave alone (agents' batches)")
    p.add_argument("--min-size", type=int, default=8, help="skip tiny functions (thunks, ret stubs)")
    p.add_argument("--out", default=os.path.join(ROOT, "build/farm/clone-matches.jsonl"))
    a = p.parse_args()
    rows = list(csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))))
    addrs = ["0x%08x" % int(r["address"], 16) for r in rows if int(r["size"]) >= a.min_size]
    matched = {x for x in addrs if os.path.exists(os.path.join(ROOT, "matches", x + ".cpp"))}
    with Pool(a.jobs) as pool:
        shapes = dict(pool.imap_unordered(_shape_job, addrs, chunksize=64))
    by_shape = defaultdict(list)
    for x in sorted(matched):
        if shapes.get(x):
            by_shape[shapes[x]].append(x)
    skip = set()
    for f in a.skip:
        skip |= {l.split()[0] for l in open(f) if l.strip()}
    pairs = [(x, by_shape[shapes[x]][0]) for x in addrs
             if x not in matched and x not in skip and shapes.get(x) and shapes[x] in by_shape]
    if a.limit:
        pairs = pairs[:a.limit]
    print("%d unmatched functions share their code shape with a match" % len(pairs), flush=True)
    counts, installed = Counter(), []
    with open(a.out, "w") as out, Pool(a.jobs) as pool:
        for i, r in enumerate(pool.imap_unordered(clone, pairs)):
            out.write(json.dumps(r) + "\n")
            counts[r["status"]] += 1
            if r["status"] == "ok" and not a.dry_run:
                dst = os.path.join(ROOT, "matches", r["addr"] + ".cpp")
                if not os.path.exists(dst):
                    shutil.copy(r["src"], dst)
                    installed.append(dst)
            if (i + 1) % 100 == 0:
                print("  %d/%d %s" % (i + 1, len(pairs), dict(counts)), flush=True)
    if installed:
        subprocess.run([sys.executable, os.path.join(ROOT, "tools/format_matches.py")] + installed, check=False)
    print("results:", dict(counts))


if __name__ == "__main__":
    main()
