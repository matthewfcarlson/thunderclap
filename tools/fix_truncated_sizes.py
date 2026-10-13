#!/usr/bin/env python3
"""Extend functions whose recorded body stops before its real end (a functions.csv post-pass).

Ghidra ends a function at a call it believes never returns. When that belief is wrong (FUN_00236d40, a plain
constructor, was one), every caller is recorded up to the call and no further, and the cut-off body can't be
matched. For each function whose body ends in something other than ret / jmp / int3, and isn't followed by int3
padding (a genuinely noreturn call is), this decodes forward to the first ret or unconditional jmp that is followed
by int3 padding or by the next listed function, and never crosses the next listed function start.

  tools/fix_truncated_sizes.py [--dry-run]     # rewrites build/functions.csv (keep a backup)
"""
import bisect
import csv
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from capstone import CS_ARCH_X86, CS_MODE_32, Cs  # noqa: E402
from compare import XBE_PATH  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CSV = os.path.join(ROOT, "build/functions.csv")
ENDS = ("ret", "retn", "jmp", "int3")
MAX_EXTEND = 0x4000


def main():
    dry = "--dry-run" in sys.argv
    x = Xbe(XBE_PATH)
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    rows = list(csv.DictReader(open(CSV)))
    fields = list(rows[0].keys())
    starts = sorted(int(r["address"], 16) for r in rows)
    fixed = 0
    for r in rows:
        a, n = int(r["address"], 16), int(r["size"])
        try:
            o = x.offset(a)
        except ValueError:
            continue
        ins = list(md.disasm(x.data[o:o + n], a))
        if not ins or sum(i.size for i in ins) != n:
            continue
        last = ins[-1]
        if last.mnemonic in ENDS or last.mnemonic.startswith("ret"):
            continue
        if x.data[o + n:o + n + 1] == b"\xcc":          # a call that really doesn't return: the body is complete
            continue
        k = bisect.bisect_right(starts, a)
        limit = starts[k] if k < len(starts) else a + MAX_EXTEND
        limit = min(limit, a + MAX_EXTEND)
        new = None
        for i in md.disasm(x.data[o + n:x.offset(a) + (limit - a)], a + n):
            e = i.address + i.size
            if i.mnemonic.startswith("ret") or i.mnemonic == "jmp":
                nxt = x.data[x.offset(a) + (e - a):x.offset(a) + (e - a) + 1]
                if e == limit or nxt == b"\xcc":
                    new = e - a
                    break
        if new and new > n:
            r["size"] = str(new)
            fixed += 1
    print("extended %d function bodies" % fixed)
    if not dry:
        with open(CSV, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=fields)
            w.writeheader()
            w.writerows(rows)


if __name__ == "__main__":
    main()
