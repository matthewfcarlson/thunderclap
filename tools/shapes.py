#!/usr/bin/env python3
"""Group functions by code shape and propagate matches between identical shapes (no LLM).

  tools/shapes.py build [--queue build/farm/queue.txt]   # -> build/farm/shapes.json, build/farm/queue-unique.txt
  tools/shapes.py propagate [--jobs 8]                    # compile each matched TU against its unmatched siblings

Shape = function bytes with call/jmp rel32 targets and absolute image addresses zeroed, i.e. the
bytes compare.py ignores anyway. Functions with one shape compile from the same source modulo names.
"""
import argparse
import csv
import json
import os
import sys
from collections import defaultdict
from multiprocessing import Pool

import capstone

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
B = lambda *p: os.path.join(ROOT, "build", *p)
MATCHES = os.path.join(ROOT, "matches")


def load_sizes():
    with open(B("functions.csv")) as f:
        return {int(r["address"], 16): int(r["size"]) for r in csv.DictReader(f)}


def shape(xbe, md, va, size):
    o = xbe.offset(va)
    b = bytearray(xbe.data[o:o + size])
    for i in md.disasm(bytes(b), va):
        start = i.address - va
        if i.bytes[0] in (0xE8, 0xE9) and i.size == 5:
            b[start + 1:start + 5] = bytes(4)
        for op in i.operands:
            v = None
            if op.type == capstone.x86.X86_OP_IMM:
                v = op.imm
            elif op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0:
                v = op.mem.disp
            if v is not None and 0x10000 < v < 0x600000:
                k = bytes(b).find((v & 0xFFFFFFFF).to_bytes(4, "little"), start, start + i.size)
                if k >= 0:
                    b[k:k + 4] = bytes(4)
    return bytes(b).hex()


def cmd_build(args):
    xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    sizes = load_sizes()
    queue = [int(l, 16) for l in open(args.queue) if l.strip()]
    groups = defaultdict(list)
    for va in queue:
        groups[shape(xbe, md, va, sizes[va])].append(va)
    shapes = {"0x%08x" % g[0]: ["0x%08x" % a for a in g[1:]] for g in groups.values()}
    json.dump(shapes, open(B("farm", "shapes.json"), "w"), indent=0)
    reps = sorted(shapes, key=lambda a: (sizes[int(a, 16)], a))
    open(B("farm", "queue-unique.txt"), "w").write("".join(a + "\n" for a in reps))
    print("%d functions -> %d shapes (%d redundant); wrote shapes.json and queue-unique.txt"
          % (len(queue), len(shapes), len(queue) - len(shapes)))


def _try(job):
    from compare import compare
    from verify_relocs import check
    src, addr = job
    r = compare(src, int(addr, 16))
    status = r["status"]
    if status == "match" and check(src, int(addr, 16))["status"] != "ok":
        status = "bad_refs"  # same bytes, but strings/constants/targets differ for this address
    return addr, src, status


def cmd_propagate(args):
    shapes = json.load(open(B("farm", "shapes.json")))
    have = lambda a: os.path.exists(os.path.join(MATCHES, a + ".cpp"))
    # Skip (source, target) pairs that already failed: same shape, but the source doesn't match bytes.
    failed = set()
    log_path = B("farm", "propagated.jsonl")
    if os.path.exists(log_path):
        for l in open(log_path):
            r = json.loads(l)
            if r["status"] != "match":
                failed.add((r["from"], r["addr"]))
    jobs = []
    for rep, sibs in shapes.items():
        members = [rep] + sibs
        source = next((a for a in members if have(a)), None)
        if source is None:
            continue
        src = os.path.join(MATCHES, source + ".cpp")
        jobs += [(src, a) for a in members if not have(a) and (source, a) not in failed]
    print("propagating to %d functions with %d workers" % (len(jobs), args.jobs))
    ok = 0
    log = open(B("farm", "propagated.jsonl"), "a")
    with Pool(args.jobs) as pool:
        for addr, src, status in pool.imap_unordered(_try, jobs):
            log.write(json.dumps({"addr": addr, "from": os.path.basename(src)[:-4], "status": status}) + "\n")
            if status == "match":
                ok += 1
                with open(os.path.join(MATCHES, addr + ".cpp"), "w") as out:
                    out.write("// Same code shape as %s (propagated; names are from that function)\n" % os.path.basename(src)[:-4])
                    out.write(open(src).read())
    print("propagated %d/%d" % (ok, len(jobs)))


if __name__ == "__main__":
    p = argparse.ArgumentParser()
    sub = p.add_subparsers(required=True)
    b = sub.add_parser("build")
    b.add_argument("--queue", default=B("farm", "queue.txt"))
    b.set_defaults(fn=cmd_build)
    pr = sub.add_parser("propagate")
    pr.add_argument("--jobs", type=int, default=8)
    pr.set_defaults(fn=cmd_propagate)
    a = p.parse_args()
    a.fn(a)
