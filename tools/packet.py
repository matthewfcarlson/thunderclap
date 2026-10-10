#!/usr/bin/env python3
"""Build the work queue and per-function context packets for decomp workers.

  tools/packet.py queue [--max-size 96] [--out build/farm/queue.txt]
  tools/packet.py build [--queue build/farm/queue.txt] [--out build/farm/packets]
  tools/packet.py show 0x18b40

A packet is compact plain text: target asm with symbolized calls and annotated data
references, the owning class and its vtable from RTTI, and Ghidra's decompile as a hint.
Everything is precomputed so a worker needs no tools besides submitting candidates.
"""
import argparse
import csv
import json
import os
import struct
import sys

import capstone

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
B = lambda *p: os.path.join(ROOT, "build", *p)
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
GAME_TEXT_END = 0x364840  # .text end; BINK/XDK sections follow
# Library code linked inside .text (see docs/platform-boundary.md): replaced by the port, not decompiled.
LIB_SPANS = [(0x208B9C, 0x212BB0), (0x3440E0, 0x356BF0), (0x35A7B0, 0x35BE88)]  # XAPILIB; LIBCMT+XAPI; LIBCMT EH


class Db:
    def __init__(self):
        self.xbe = Xbe(XBE_PATH)
        self.funcs = {}
        with open(B("functions.csv")) as f:
            for r in csv.DictReader(f):
                self.funcs[int(r["address"], 16)] = r
        rtti = json.load(open(B("rtti.json")))
        self.classes = {c["name"]: c for c in rtti["classes"] if c["name"]}
        self.td_name = {c["mangled"]: c["name"] for c in rtti["classes"]}
        self.uses = {}      # func va -> [(class, vtable offset, slot, nbases)]
        self.vftables = {}  # vftable va -> (class, offset)
        for c in rtti["classes"]:
            if not c["name"]:
                continue
            for v in c["vtables"]:
                self.vftables[v["address"]] = (c["name"], v["offset"])
                for i, fva in enumerate(v["slots"]):
                    self.uses.setdefault(fva, []).append((c["name"], v["offset"], i, len(c["bases"])))
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.syntax = capstone.CS_OPT_SYNTAX_INTEL
        self.md.detail = True

    def name(self, va):
        r = self.funcs.get(va)
        return r["name"] if r else None

    def is_game(self, r):
        va = int(r["address"], 16)
        if va >= GAME_TEXT_END or r["is_thunk"] == "1" or any(a <= va < b for a, b in LIB_SPANS):
            return False
        n = r["name"]
        # XDK/CRT symbols identified by XbSymbolDatabase keep their library names.
        return n.startswith("FUN_") or "vfunc_" in n

    def describe_data(self, va, width=4):
        """Short annotation for a data address: string, float, vftable, function pointer."""
        if va in self.vftables:
            cls, off = self.vftables[va]
            return "%s::vftable%s" % (cls, "" if off == 0 else "_%x" % off)
        if va in self.funcs:
            return "&" + self.funcs[va]["name"]
        s = self.xbe.cstr(va, 120)
        if s is not None and len(s) >= 2 and all(32 <= ord(ch) < 127 or ch in "\t\n\r" for ch in s):
            return json.dumps(s[:80])
        o = self.xbe.offset(va)
        if o is None:
            return "bss" if self.xbe.section_of(va) else None
        raw = self.xbe.data[o:o + 8]
        if width == 8 and len(raw) == 8:
            return "%r (double)" % struct.unpack("<d", raw)[0]
        u, = struct.unpack("<I", raw[:4])
        f, = struct.unpack("<f", raw[:4])
        if u == 0:
            return "0 (0.0f)"
        if 1e-6 < abs(f) < 1e9:
            return "%gf / 0x%x" % (f, u)
        return "0x%x" % u

    def asm(self, va, size):
        o = self.xbe.offset(va)
        lines, refs = [], {}
        for insn in self.md.disasm(self.xbe.data[o:o + size], va):
            text = "%s %s" % (insn.mnemonic, insn.op_str)
            if insn.group(capstone.CS_GRP_CALL) or insn.group(capstone.CS_GRP_JUMP):
                for op in insn.operands:
                    if op.type == capstone.x86.X86_OP_IMM:
                        tgt = op.imm
                        if va <= tgt < va + size:
                            text = "%s %04x" % (insn.mnemonic, tgt - va)
                        elif self.name(tgt):
                            text = "%s %s" % (insn.mnemonic, self.name(tgt))
            for op in insn.operands:
                cand = None
                if op.type == capstone.x86.X86_OP_IMM and op.imm > 0x10000:
                    cand = op.imm
                elif op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0 and op.mem.disp > 0x10000:
                    cand = op.mem.disp
                if cand is not None and not (insn.group(capstone.CS_GRP_CALL) or insn.group(capstone.CS_GRP_JUMP)):
                    desc = self.describe_data(cand, 8 if "qword" in insn.op_str else 4)
                    if desc:
                        refs[cand] = desc
            lines.append("  %04x  %s" % (insn.address - va, text))
        return lines, refs

    def owner(self, va):
        uses = self.uses.get(va, [])
        if not uses:
            return None, uses
        m = min(u[3] for u in uses)
        return next(u for u in uses if u[3] == m), uses

    def class_block(self, cls_name, highlight=None, max_slots=48):
        c = self.classes[cls_name]
        bases = [self.td_name.get(b["name"], b["name"]) for b in c["bases"]]
        out = ["class %s%s" % (cls_name, (" : " + ", ".join(bases)) if bases else "")]
        for v in c["vtables"]:
            out.append("  vftable%s (%d slots):" % ("" if v["offset"] == 0 else " for base at +0x%x" % v["offset"], len(v["slots"])))
            for i, fva in enumerate(v["slots"][:max_slots]):
                mark = "  <== target" if fva == highlight else ""
                out.append("    [%d] +0x%x %s%s" % (i, i * 4, self.name(fva) or "0x%x" % fva, mark))
            if len(v["slots"]) > max_slots:
                out.append("    ... %d more" % (len(v["slots"]) - max_slots))
        return out

    def packet(self, va, similar=0):
        r = self.funcs[va]
        size = int(r["size"])
        lines, refs = self.asm(va, size)
        out = ["Target function 0x%08x  %s  (%d bytes)" % (va, r["name"], size)]
        owner, uses = self.owner(va)
        if owner:
            out.append("Virtual method: slot %d of %s's vftable%s." % (
                owner[2], owner[0], "" if owner[1] == 0 else " for its base at +0x%x" % owner[1]))
            others = sorted({u[0] for u in uses} - {owner[0]})
            if others:
                out.append("Also inherited by %d classes, e.g. %s." % (len(others), ", ".join(others[:4])))
            out += self.class_block(owner[0], highlight=va)
        callers = int(r["xrefs"])
        out.append("Direct references to this function: %d" % callers)
        out.append("")
        out.append("Assembly (offsets relative to function start):")
        out += lines
        if refs:
            out.append("Data referenced:")
            for a, d in sorted(refs.items()):
                out.append("  0x%x = %s" % (a, d))
        if similar:
            from similar import Index
            if not hasattr(self, "_sim"):
                self._sim = Index.load()
            ex = self._sim.similar("0x%08x" % va, k=similar, min_score=0.4)
            if ex:
                out += ["", "Verified matches of other functions with similar code (they compile byte-exact; reuse their idioms):"]
                for a, j, size, body in ex:
                    out += ["--- %s (%d bytes, similarity %.2f) ---" % (a, size, j), body.strip()[:2500]]
        c_path = B("farm", "ghidra_c", "0x%08x.c" % va)
        if os.path.exists(c_path):
            c = open(c_path).read().strip()
            out += ["", "Ghidra decompilation (a hint; types and names are guesses):", c]
        return "\n".join(out) + "\n"


def cmd_queue(args):
    db = Db()
    rows = [r for r in db.funcs.values() if db.is_game(r) and 1 <= int(r["size"]) <= args.max_size]
    rows.sort(key=lambda r: (int(r["size"]), int(r["calls"]), r["address"]))
    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    with open(args.out, "w") as f:
        for r in rows:
            f.write("0x%08x\n" % int(r["address"], 16))
    print("queued %d functions (<= %d bytes) -> %s" % (len(rows), args.max_size, args.out))


def cmd_build(args):
    db = Db()
    os.makedirs(args.out, exist_ok=True)
    n = 0
    for line in open(args.queue):
        va = int(line.strip(), 16)
        with open(os.path.join(args.out, "0x%08x.txt" % va), "w") as f:
            f.write(db.packet(va, similar=args.similar))
        n += 1
    print("wrote %d packets -> %s" % (n, args.out))


def cmd_show(args):
    print(Db().packet(int(args.addr, 16), similar=args.similar), end="")


if __name__ == "__main__":
    p = argparse.ArgumentParser()
    sub = p.add_subparsers(required=True)
    q = sub.add_parser("queue")
    q.add_argument("--max-size", type=int, default=96)
    q.add_argument("--out", default=B("farm", "queue.txt"))
    q.set_defaults(fn=cmd_queue)
    b = sub.add_parser("build")
    b.add_argument("--queue", default=B("farm", "queue.txt"))
    b.add_argument("--out", default=B("farm", "packets"))
    b.add_argument("--similar", type=int, default=0, help="append up to K similar verified matches")
    b.set_defaults(fn=cmd_build)
    s = sub.add_parser("show")
    s.add_argument("addr")
    s.add_argument("--similar", type=int, default=0)
    s.set_defaults(fn=cmd_show)
    a = p.parse_args()
    a.fn(a)
