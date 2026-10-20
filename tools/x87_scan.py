#!/usr/bin/env python3
"""x87 precision scan: where does the native build round a float that MSVC 7.1 kept in an x87 register?

  build/venv/bin/python tools/x87_scan.py --native DIR [--out build/x87/scan] [--addr 0x350c0 ...]

DIR is a native link's output directory (tools/native_link.py --out; it holds bindings.json and
link/hulk-strict.exe + .map). docs/native-float.md explains the model; in short:

The game runs the x87 with 53-bit precision control (the CRT's _fpmath -> _controlfp(_PC_53, _MCW_PC) from
_cinit), so a value in an x87 register carries a 53-bit mantissa and a store to a `double` (qword) is exact.
Only a store to a 32-bit `float` (dword) of a value produced by arithmetic ("excess" value) rounds. Such a
rounding changes the program's result only when the rounded value is read back and *consumed* by arithmetic,
a compare, an integer conversion, a double store or the function's return in st(0). A rounded value that is
only copied to other float memory (or pushed as a float argument) is what MSVC would have stored anyway.

For each game function with a definition in the native image the scan simulates the x87 stack over both the
original's code (the XBE) and ours (the image), linear sweep (a branch target takes the stack state of the
first jump to it), and counts *round trips*: an excess value stored to a dword stack slot ([ebp-N], or [esp+N]
normalised by the tracked esp delta), the slot read back, the read value consumed as above. MSVC's own round
trips are its spills (it keeps float temporaries and named float locals in registers within a statement and
across statements, and spills only across calls or under register pressure). A function whose image has more
consuming round trips than the original is a precision site candidate; `extra` = ours - original estimates the
number of sites. Clang -O0 rounds every named float local at every assignment and the return value of a function
with more than one `return`, so -O0 images have many; an image whose locals live in registers (-O1 codegen)
should have about as many as the original.

Output: <out>.json (per function: original and native round trips, extra), <out>.txt (summary + top list).
It is a heuristic: indirect jumps, chunked functions and esp tracking across stdcall callees are approximate.
"""
import argparse
import bisect
import csv
import json
import os
import re
import struct
import sys

import capstone
from capstone import x86 as X

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
GAME_TEXT_END = 0x364840
LIB_SPANS = [(0x208B9C, 0x212BB0), (0x3440E0, 0x356BF0), (0x35A7B0, 0x35BE88)]

ARITH = {"fadd", "faddp", "fsub", "fsubp", "fsubr", "fsubrp", "fmul", "fmulp", "fdiv", "fdivp", "fdivr", "fdivrp",
         "fiadd", "fisub", "fisubr", "fimul", "fidiv", "fidivr", "fsqrt", "fprem", "fprem1", "fscale", "frndint",
         "fsin", "fcos", "fsincos", "fptan", "fpatan", "f2xm1", "fyl2x", "fyl2xp1", "fxtract"}
COMPARE = {"fcom", "fcomp", "fcompp", "fucom", "fucomp", "fucompp", "fcomi", "fcomip", "fucomi", "fucomip",
           "ficom", "ficomp", "ftst"}
POPS1 = {"faddp", "fsubp", "fsubrp", "fmulp", "fdivp", "fdivrp", "fcomp", "fucomp", "fcomip", "fucomip", "ficomp"}
CONST = {"fld1", "fldz", "fldpi", "fldl2e", "fldl2t", "fldlg2", "fldln2"}


# ---------------------------------------------------------------------------------------------
# Values on the simulated x87 stack: (kind, site) with kind
#   "x"  excess: produced by arithmetic (or fild of an int, or fld of a double)
#   "f"  exact float (loaded from a dword, a constant)
#   "r"  read back from a dword slot an excess value was rounded into (site = the load's address)
def simulate(insns, entry):
    """Count consuming round trips in one function. Returns (round_trips, [site addresses])."""
    st = []                 # top of stack = st[-1]
    slots = {}              # slot key -> True when it holds a rounded excess value
    delta = 0               # esp offset from the function entry (pushes, sub esp)
    states = {}             # branch target -> (stack copy, delta)
    sites = []
    regs = {}               # integer register -> holds a rounded slot's bits
    stored_at = {}          # slot key -> number of calls seen when it was stored
    ncalls = 0
    across = set()          # sites whose slot was stored before a call (a spill across the call)
    ret_excess = set()      # `ret`s with an unrounded arithmetic result in st(0)
    fp_based = False        # MSVC frames: [ebp-N]; clang -O0: always ebp

    def slot_key(op):
        if op.type != X.X86_OP_MEM or op.size != 4:
            return None
        m = op.mem
        if m.index != 0:
            return None
        if m.base == X.X86_REG_EBP:
            return ("ebp", m.disp)
        if m.base == X.X86_REG_ESP:
            return ("esp", m.disp - delta)
        return None

    def consume(v):
        if v and v[0] == "r":
            sites.append(v[1])
            if v[2]:
                across.add(v[1])

    def pop():
        return st.pop() if st else None

    def sti(i):
        return st[-1 - i] if i < len(st) else None

    def set_sti(i, v):
        if i < len(st):
            st[-1 - i] = v

    after_jump = False
    for ins in insns:
        a = ins.address
        if a in states:
            st, delta = list(states[a][0]), states[a][1]
        elif after_jump:
            st = []
        after_jump = False
        mn = ins.mnemonic
        ops = ins.operands
        # esp tracking
        if mn == "push":
            delta += 4
        elif mn == "pop":
            delta -= 4
        elif mn in ("sub", "add") and len(ops) == 2 and ops[0].type == X.X86_OP_REG and ops[0].reg == X.X86_REG_ESP \
                and ops[1].type == X.X86_OP_IMM:
            delta += ops[1].imm if mn == "sub" else -ops[1].imm
        elif mn == "mov" and len(ops) == 2 and ops[0].type == X.X86_OP_REG and ops[0].reg == X.X86_REG_EBP \
                and ops[1].type == X.X86_OP_REG and ops[1].reg == X.X86_REG_ESP:
            fp_based = True
        if ins.group(capstone.CS_GRP_JUMP):
            tgt = ops[0].imm if ops and ops[0].type == X.X86_OP_IMM else None
            if tgt is not None and tgt not in states:
                states[tgt] = (list(st), delta)
            if mn == "jmp":
                after_jump = True
            continue
        if mn == "ret":
            if st:
                consume(st[-1])     # returned in st(0): the caller may compute with it
                if st[-1] and st[-1][0] == "x":
                    ret_excess.add(a)   # returns an unrounded arithmetic result
            after_jump = True
            continue
        if mn == "call":
            # the callee's float result (if any) arrives in st(0) as an excess value; clear the rest
            st = []
            ncalls += 1
            continue
        if mn == "mov" and len(ops) == 2:
            # 32-bit integer copies of a rounded slot (struct copies, fabs through memory) keep it rounded
            d, s = ops
            if d.type == X.X86_OP_REG and s.type == X.X86_OP_MEM:
                k = slot_key(s)
                regs[d.reg] = bool(k is not None and slots.get(k))
            elif d.type == X.X86_OP_MEM and s.type == X.X86_OP_REG:
                k = slot_key(d)
                if k is not None:
                    slots[k] = regs.get(s.reg, False)
            elif d.type == X.X86_OP_REG:
                regs[d.reg] = False
            elif d.type == X.X86_OP_MEM:
                k = slot_key(d)
                if k is not None:
                    slots[k] = False
            continue
        if not mn.startswith("f") and mn not in ("wait",):
            continue
        # x87
        if mn == "fld":
            op = ops[0]
            if op.type == X.X86_OP_REG:
                i = op.reg - X.X86_REG_ST0
                st.append(sti(i))
            else:
                k = slot_key(op)
                if op.size == 4:
                    st.append(("r", a, ncalls > stored_at.get(k, ncalls)) if k is not None and slots.get(k)
                              else ("f", a))
                else:
                    st.append(("x", a))
            continue
        if mn in CONST:
            st.append(("f", a))
            continue
        if mn == "fild":
            st.append(("x", a))
            continue
        if mn in ("fst", "fstp"):
            op = ops[0]
            v = sti(0)
            if op.type == X.X86_OP_REG:
                i = op.reg - X.X86_REG_ST0
                if mn == "fst":
                    set_sti(i, v)
                else:
                    set_sti(i, v)
                    pop()
                continue
            k = slot_key(op)
            if op.size == 4:
                if k is not None:
                    slots[k] = bool(v and v[0] in "xr")   # rounding now, or a rounded value copied
                    stored_at[k] = ncalls
            else:
                consume(v)          # a double / extended store keeps what a float slot rounded away
            if mn == "fstp":
                pop()
            continue
        if mn in ("fist", "fistp", "fisttp"):
            consume(sti(0))
            if mn != "fist":
                pop()
            continue
        if mn == "fxch":
            i = max([o.reg - X.X86_REG_ST0 for o in ops if o.type == X.X86_OP_REG] or [1])
            if i < len(st):
                st[-1], st[-1 - i] = st[-1 - i], st[-1]
            continue
        if mn in ("fchs", "fabs"):
            continue
        if mn in ("ffree", "fincstp", "fdecstp", "fnstsw", "fstsw", "fnstcw", "fldcw", "fwait", "fnclex", "fninit"):
            continue
        if mn in COMPARE:
            consume(sti(0))
            if ops and ops[0].type == X.X86_OP_REG:
                consume(sti(ops[0].reg - X.X86_REG_ST0))
            if mn == "fcompp" or mn == "fucompp":
                consume(sti(1))
                pop()
                pop()
            elif mn in POPS1:
                pop()
            continue
        if mn in ARITH:
            if mn in ("fsqrt", "frndint", "fsin", "fcos", "f2xm1"):
                consume(sti(0))
                set_sti(0, ("x", a))
                continue
            if mn in ("fyl2x", "fyl2xp1", "fpatan"):
                consume(sti(0))
                consume(sti(1))
                pop()
                set_sti(0, ("x", a))
                continue
            if mn in ("fprem", "fprem1", "fscale"):
                consume(sti(0))
                consume(sti(1))
                set_sti(0, ("x", a))
                continue
            if mn in ("fptan", "fsincos", "fxtract"):
                consume(sti(0))
                set_sti(0, ("x", a))
                st.append(("x", a))
                continue
            # two-operand arithmetic
            rops = [o for o in ops if o.type == X.X86_OP_REG]
            mem = [o for o in ops if o.type == X.X86_OP_MEM]
            if mem or not ops:
                if mem:
                    k = slot_key(mem[0])
                    if mem[0].size == 4 and k is not None and slots.get(k) and mn[1] != "i":
                        sites.append(a)     # arithmetic directly on a rounded slot
                        if ncalls > stored_at.get(k, ncalls):
                            across.add(a)
                consume(sti(0))
                set_sti(0, ("x", a))
                if not ops and mn.endswith("p"):
                    consume(sti(1))
                    pop()
                    set_sti(0, ("x", a))
                continue
            if len(rops) == 2:
                d = rops[0].reg - X.X86_REG_ST0
                s = rops[1].reg - X.X86_REG_ST0
                consume(sti(d))
                consume(sti(s))
                set_sti(d, ("x", a))
                if mn.endswith("p"):
                    pop()
            elif len(rops) == 1:
                # capstone: `fmul st(i)` (D8) is st0 = st0 * st(i); `fmulp st(i)` (DE) is st(i) = st(i) * st0, pop
                s = rops[0].reg - X.X86_REG_ST0
                consume(sti(0))
                consume(sti(s))
                set_sti(s if mn.endswith("p") else 0, ("x", a))
                if mn.endswith("p"):
                    pop()
            continue
    return len(set(sites)), sorted(set(sites)), len(across), len(ret_excess)


# ---------------------------------------------------------------------------------------------
class Pe:
    def __init__(self, path):
        self.data = open(path, "rb").read()
        d = self.data
        pe = struct.unpack_from("<I", d, 0x3c)[0]
        nsec = struct.unpack_from("<H", d, pe + 6)[0]
        opt = struct.unpack_from("<H", d, pe + 20)[0]
        self.base = struct.unpack_from("<I", d, pe + 24 + 28)[0]
        self.secs = []
        o = pe + 24 + opt
        for i in range(nsec):
            name, vs, va, rs, ra = struct.unpack_from("<8sIIII", d, o + 40 * i)
            self.secs.append((self.base + va, vs, ra, rs))

    def read(self, va, n):
        for sva, vs, ra, rs in self.secs:
            if sva <= va < sva + vs:
                off = ra + (va - sva)
                return self.data[off:off + min(n, sva + vs - va)]
        return b""


def read_map(path):
    rx = re.compile(r"^\s*0001:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8,16})\s")
    out = {}
    for line in open(path, errors="replace"):
        m = rx.match(line)
        if m:
            out.setdefault(m.group(1), int(m.group(2), 16))
    return out


def is_game(va):
    return va < GAME_TEXT_END and not any(a <= va < b for a, b in LIB_SPANS)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--native", required=True, help="native link output dir (bindings.json, link/hulk-strict.*)")
    ap.add_argument("--image", help="image name in DIR/link (default hulk-strict)", default="hulk-strict")
    ap.add_argument("--out", default=os.path.join(ROOT, "build/x87/scan"))
    ap.add_argument("--addr", nargs="*", help="only these XBE addresses; prints the sites")
    a = ap.parse_args()

    x = Xbe(XBE_PATH)
    sizes = {}
    for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))):
        sizes[int(r["address"], 16)] = int(r["size"])
    b = json.load(open(os.path.join(a.native, "bindings.json")))
    defs = {int(k, 16): v for k, v in b["definitions"].items()}
    pe = Pe(os.path.join(a.native, "link", a.image + ".exe"))
    syms = read_map(os.path.join(a.native, "link", a.image + ".map"))
    starts = sorted(set(syms.values()))
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True

    want = {int(v, 16) for v in a.addr} if a.addr else None
    rows = []
    for va in sorted(defs):
        if want is not None and va not in want:
            continue
        if not is_game(va) or va not in sizes:
            continue
        sym = defs[va]
        nva = syms.get(sym)
        if nva is None:
            continue
        i = bisect.bisect_right(starts, nva)
        nend = starts[i] if i < len(starts) else nva + 0x1000
        nbytes = pe.read(nva, min(nend - nva, 0x20000))
        o = x.offset(va)
        obytes = x.data[o:o + sizes[va]]
        oi = list(md.disasm(obytes, va))
        if not any(ins.mnemonic.startswith("f") for ins in oi):
            continue
        ni = list(md.disasm(nbytes, nva))
        orig_n, orig_sites, orig_across, orig_ret = simulate(oi, va)
        nat_n, nat_sites, nat_across, nat_ret = simulate(ni, nva)
        rows.append({"addr": "0x%08x" % va, "size": sizes[va], "symbol": sym, "orig": orig_n, "native": nat_n,
                     "orig_across_call": orig_across, "orig_ret_excess": orig_ret, "native_ret_excess": nat_ret, "native_across_call": nat_across, "extra": max(0, nat_n - orig_n), "missing": max(0, orig_n - nat_n), "orig_sites": ["0x%x" % s for s in orig_sites],
                     "native_sites": ["0x%x" % s for s in nat_sites]})
        if want is not None:
            print(json.dumps(rows[-1], indent=1))
    if want is not None:
        return
    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    json.dump(rows, open(a.out + ".json", "w"), indent=0)
    cand = [r for r in rows if r["extra"] > 0]
    with open(a.out + ".txt", "w") as f:
        f.write("x87 precision scan of %s\n" % a.native)
        f.write("game functions with x87 code and a definition in the image: %d\n" % len(rows))
        f.write("  original consuming round trips (MSVC spills): %d in %d functions\n"
                % (sum(r["orig"] for r in rows), sum(1 for r in rows if r["orig"])))
        f.write("    of them a spill across a call: %d\n" % sum(r["orig_across_call"] for r in rows))
        f.write("  image consuming round trips: %d in %d functions (across a call: %d)\n"
                % (sum(r["native"] for r in rows), sum(1 for r in rows if r["native"]),
                   sum(r["native_across_call"] for r in rows)))
        f.write("functions whose counts agree: %d; image more: %d; image fewer: %d (%d round trips MSVC has and the "
                "image doesn't)\n" % (sum(1 for r in rows if r["native"] == r["orig"]),
                                       sum(1 for r in rows if r["native"] > r["orig"]),
                                       sum(1 for r in rows if r["native"] < r["orig"]),
                                       sum(r["missing"] for r in rows)))
        f.write("functions returning an unrounded arithmetic result in st(0): original %d, image %d\n"
                % (sum(1 for r in rows if r["orig_ret_excess"]), sum(1 for r in rows if r["native_ret_excess"])))
        f.write("candidates (image > original): %d functions, %d extra round trips\n"
                % (len(cand), sum(r["extra"] for r in cand)))
        for r in sorted(cand, key=lambda r: -r["extra"]):
            f.write("%s %5d B  extra %3d (orig %d, native %d)  %s\n"
                    % (r["addr"], r["size"], r["extra"], r["orig"], r["native"], r["symbol"][:100]))
    print(open(a.out + ".txt").read()[:1500])


if __name__ == "__main__":
    main()
