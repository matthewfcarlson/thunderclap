#!/usr/bin/env python3
"""Replace hard-coded data addresses in matches/ with declared symbols.

Some matches write a vtable or global address as an integer (`p->vt = 0x413fb0;`). The bytes match,
because the literal equals the original's value, but the code can't be relocated, so it is useless
for the native port, and tools/verify_relocs.py never sees the reference. This tool rewrites each
literal that points into .rdata/.data/.bss as a declared symbol (`(int)DAT_00413fb0` with
`extern char DAT_00413fb0[];`) and keeps the rewrite only if tools/compare.py still says MATCH and
tools/verify_relocs.py says "ok" with the symbol resolving to that same address.

Usage:
  tools/fix_literals.py [FILES...]   # default: every matches/*.cpp with such a literal
  tools/fix_literals.py --dry-run
"""
import argparse
import glob
import json
import os
import re
import shutil
import sys
import tempfile
from collections import Counter
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import verify_relocs as vr  # noqa: E402
from compare import XBE_PATH  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA_START = 0x3F2BE0  # .rdata; .data follows at 0x48CA80
LIT = re.compile(r"(?<![\w.])0x([0-9a-fA-F]{5,8})\b")
_XBE = None


def data_va(v):
    global _XBE
    if _XBE is None:
        _XBE = Xbe(XBE_PATH)
    if v < DATA_START:
        return False
    sec = _XBE.section_of(v)
    return sec is not None and not sec.executable


def rewrite(text):
    """Replace data-address literals outside comments; return (new text, [addresses])."""
    out, addrs, pos = [], [], 0
    # Mask comments so their numbers are left alone.
    masked = re.sub(r"//[^\n]*|/\*.*?\*/", lambda m: " " * len(m.group(0)), text, flags=re.S)
    for m in LIT.finditer(masked):
        v = int(m.group(1), 16)
        if not data_va(v):
            continue
        out.append(text[pos:m.start()])
        out.append("((int)DAT_%08x)" % v)
        addrs.append(v)
        pos = m.end()
    out.append(text[pos:])
    if not addrs:
        return None, []
    body = "".join(out)
    decls = "".join('extern "C" char DAT_%08x[];\n' % v for v in sorted(set(addrs))
                    if ("DAT_%08x[]" % v) not in text)
    if body.startswith("// cl-flags:"):
        nl = body.index("\n") + 1
        return body[:nl] + decls + body[nl:], addrs
    return decls + body, addrs


def work(path):
    addr = os.path.basename(path)[:-4]
    text = open(path).read()
    new, addrs = rewrite(text)
    if new is None:
        return {"addr": addr, "status": "none"}
    with tempfile.TemporaryDirectory() as tmp:
        p = os.path.join(tmp, addr + ".cpp")
        open(p, "w").write(new)
        try:
            r = vr.check(p, int(addr, 16))
        except Exception as e:  # noqa: BLE001
            return {"addr": addr, "status": "error", "detail": repr(e)[:120]}
        if r["status"] != "ok":
            return {"addr": addr, "status": "rewrite_" + r["status"], "issues": r.get("issues", [])[:3]}
        mapped = {int(v, 16) for k, v in r["map"].items() if "DAT_" in k}
        if not set(addrs) <= mapped:
            return {"addr": addr, "status": "symbol_mismatch"}
        keep = os.path.join(ROOT, "build/farm/fix-literals", addr + ".cpp")
        os.makedirs(os.path.dirname(keep), exist_ok=True)
        shutil.copy(p, keep)
    return {"addr": addr, "status": "fixed", "src": keep, "n": len(addrs)}


def main():
    p = argparse.ArgumentParser()
    p.add_argument("files", nargs="*")
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--jobs", type=int, default=6)
    p.add_argument("--out", default=os.path.join(ROOT, "build/farm/fix-literals.jsonl"))
    a = p.parse_args()
    files = a.files or sorted(glob.glob(os.path.join(ROOT, "matches", "*.cpp")))
    counts = Counter()
    with open(a.out, "w") as out, Pool(a.jobs) as pool:
        for r in pool.imap_unordered(work, files, chunksize=8):
            if r["status"] == "none":
                continue
            out.write(json.dumps(r) + "\n")
            counts[r["status"]] += 1
            if r["status"] == "fixed" and not a.dry_run:
                shutil.copy(r["src"], os.path.join(ROOT, "matches", r["addr"] + ".cpp"))
    print("results:", dict(counts))


if __name__ == "__main__":
    main()
