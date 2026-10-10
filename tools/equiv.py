#!/usr/bin/env python3
"""Equivalence verifier: is our compiled function *behaviourally* the same as the original?

  tools/equiv.py SRC 0xADDR [--symbol S] [--inputs 64] [--map map.json] [--json] [-- extra cl flags]

Levels (docs/tasks/09-equivalent-decomp.md, docs/equivalence.md):
  1  compiles with MSVC 7.1 (plus an optional host-clang syntax check, warning only)
  2  same references: the same callees, globals, vftables, strings and float constants as the original
  3  differential execution in Unicorn: original bytes and our object run side by side from identical
     fuzzed states; calls are stubbed and recorded; return value, memory writes, call trace and
     callee-saved registers must agree on every input. Branch coverage of the original is reported.

Library use: verify(src, addr, ...) -> report dict (see docs/equivalence.md for the format).
Exit status: 0 = equivalent (level 3), 1 = anything else.
"""
import argparse
import json
import math
import os
import re
import struct
import subprocess
import sys
import tempfile
import time
from collections import Counter, defaultdict

import capstone
from capstone import x86_const as cx

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from compare import CompileError, DEFAULT_FLAGS, compile_obj, diff as asm_diff, strip_padding  # noqa: E402
from msvc_demangle import DemangleError, _Parser  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
FUNCS_CSV = os.path.join(ROOT, "build/functions.csv")
RTTI_JSON = os.path.join(ROOT, "build/rtti.json")
XBSYMS = os.path.join(ROOT, "build/xbsymbols.txt")
GHIDRA_C = os.path.join(ROOT, "build/farm/ghidra_c")

M32 = 0xFFFFFFFF
M64 = 0xFFFFFFFFFFFFFFFF
PAGE = 0x1000

# ---------------------------------------------------------------------------------------------
# Address-space layout for level 3 (everything else is mapped lazily on first touch).
IMAGE_LO, IMAGE_HI = 0x10000, 0x58C000          # the XBE image (header + sections)
NULL_HI = 0x10000                               # 0..0xFFFF: zero-filled "null page" region
HEAP, HEAP_SIZE = 0x40000000, 0x100000           # fuzzed pointers point in here
OURS = 0x60000000                               # our linked object
OURS_SIZE = 0x100000
POISON = 0x6FFF0000                             # unresolved externals point here (never mapped)
STACK_LO, STACK_HI = 0x7EF00000, 0x7F000000
ENTRY_ESP = STACK_HI - 0x10000
TRAMP = 0x7FFF0000                              # call-stub trampolines + sentinel
SENTINEL = TRAMP + 0xE00
FSLOT = TRAMP + 0xF00                           # float returned by a stubbed callee
TIB = 0x7FFE0000                                # fs:[0] (SEH chain)
GDT = 0x7FFD0000
RESERVED = [(OURS, OURS + OURS_SIZE), (POISON, POISON + 0x10000), (STACK_LO, STACK_HI),
            (GDT, GDT + PAGE), (TIB, TIB + PAGE), (TRAMP, TRAMP + PAGE)]
STACK_FILL = 0x5A5A5A5A
RARE_HITS = 4               # directed inputs also re-drive branch sides taken by fewer inputs than this
POINTEE_WINDOW = 256        # most bytes of a stack local passed by pointer that are compared at a call
DEFAULT_POINTEE = 4         # ... when the callee's parameter type is unknown (e.g. virtual calls)

REL32, DIR32 = 0x14, 0x06
# Differences that equivalent code can legitimately have (level 3 still checks the behaviour):
# an immediate that merely looks like an address, a float constant loaded another way (fld1/fldz, double vs
# float), a string read in pieces vs whole, and CRT routines the original inlined.
SOFT_L2 = ("missing_address_constant", "missing_float_constant", "float_constant_not_in_original",
           "missing_data_ref_interior", "extra_data_ref_interior", "intrinsic_call")
CALLEE_SAVED = ("ebx", "esi", "edi", "ebp")

# CRT helpers that are executed for real instead of stubbed (pure: registers/stack only).
HELPERS = {0x0034483C: "__ftol2", 0x00345880: "__chkstk"}
# C-linkage CRT/compiler names whose address is fixed (mined from verified matches).
BUILTIN_NAMES = {
    "__ftol2": 0x0034483C, "__ftol": 0x0034483C, "__chkstk": 0x00345880, "__alloca_probe": 0x00345880,
    "__isnan": 0x0034476F, "_strncpy": 0x00345650, "_malloc": 0x003479AA,
    "@__security_check_cookie@4": 0x0034502E,
}


# ---------------------------------------------------------------------------------------------
# Shared, lazily loaded program data.
class Program:
    _inst = None

    @classmethod
    def get(cls):
        if cls._inst is None:
            cls._inst = cls()
        return cls._inst

    def __init__(self):
        import csv
        self.xbe = Xbe(XBE_PATH)
        self.funcs = {}
        self.names = defaultdict(list)
        with open(FUNCS_CSV) as f:
            for r in csv.DictReader(f):
                a = int(r["address"], 16)
                self.funcs[a] = (int(r["size"]), r["name"])
                self.names[r["name"]].append(a)
        self.vftables = {}
        if os.path.exists(RTTI_JSON):
            for c in json.load(open(RTTI_JSON))["classes"]:
                for v in c["vtables"]:
                    self.vftables[v["address"]] = c["mangled"]
        self.xbsyms = {}
        if os.path.exists(XBSYMS):
            for line in open(XBSYMS):
                m = re.match(r"\s*(\w+)__(\w+)\s*=\s*0x([0-9a-fA-F]+)", line)
                if m:
                    self.xbsyms.setdefault(m.group(2), int(m.group(3), 16))
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.detail = True
        self._page_cache = {}
        self._pop_cache = {}
        text = next(s for s in self.xbe.sections if s.name == ".text")
        self.text = (text.va, text.va + text.vsize)

    def image_page(self, page):
        """Original image bytes for one page (sections may share pages; BSS reads as zero)."""
        b = self._page_cache.get(page)
        if b is None:
            buf = bytearray(PAGE)
            if page == 0x10000:
                buf[:] = self.xbe.data[:PAGE]
            for s in self.xbe.sections:
                lo, hi = max(page, s.va), min(page + PAGE, s.va + s.rsize)
                if lo < hi:
                    buf[lo - page:hi - page] = self.xbe.data[s.raw + lo - s.va:s.raw + hi - s.va]
            b = self._page_cache[page] = bytes(buf)
        return b

    def read(self, va, n):
        out = bytearray()
        while n > 0:
            page = va & ~0xFFF
            take = min(n, page + PAGE - va)
            if IMAGE_LO <= page < IMAGE_HI:
                out += self.image_page(page)[va - page:va - page + take]
            else:
                out += b"\0" * take
            va += take
            n -= take
        return bytes(out)

    def u32(self, va):
        return struct.unpack("<I", self.read(va, 4))[0]

    def section_name(self, va):
        s = self.xbe.section_of(va)
        return s.name if s else None

    def is_func_start(self, va):
        return va in self.funcs

    def callee_pop(self, target, depth=0):
        """Bytes a callee pops (ret N), 0 for cdecl, None if unknown (no ret found / not code)."""
        if target in self._pop_cache:
            return self._pop_cache[target]
        res = None
        if self.text[0] <= target < self.text[1] or self.section_name(target) in ("D3D", "XGRPH", "DSOUND", "XPP"):
            body = (target, target + self.funcs[target][0]) if target in self.funcs else None
            view = CodeView(self.read, target, body, self)
            try:
                view.build(limit=4000)
                rets = [i for i in view.insns.values() if i.kind == "ret"]
                if rets:
                    res = max(i.ret_imm for i in rets)
                elif depth < 4:
                    # every exit is a tail call: the function pops what its tail callee pops
                    for i in view.insns.values():
                        if i.kind == "jmp" and i.target is not None and not view.internal_target(i.target):
                            res = self.callee_pop(i.target, depth + 1)
                            if res is not None:
                                break
            except Exception:
                res = None
        self._pop_cache[target] = res
        return res


    _REGS = ("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp")
    _ALIAS = {"al": "eax", "ah": "eax", "ax": "eax", "cl": "ecx", "ch": "ecx", "cx": "ecx", "dl": "edx",
              "dh": "edx", "dx": "edx", "bl": "ebx", "bh": "ebx", "bx": "ebx", "si": "esi", "di": "edi",
              "bp": "ebp", "sil": "esi", "dil": "edi"}

    def _regs_rw(self, ci):
        try:
            r, w = ci.regs_access()
        except Exception:
            return set(), set()
        rn = {self._ALIAS.get(ci.reg_name(x), ci.reg_name(x)) for x in r}
        wn = {self._ALIAS.get(ci.reg_name(x), ci.reg_name(x)) for x in w}
        ops = ci.op_str.split(", ")
        if ci.mnemonic in ("xor", "sub", "sbb") and len(ops) == 2 and ops[0] == ops[1]:
            rn.discard(self._ALIAS.get(ops[0], ops[0]))     # xor eax, eax: a write, not a read
        if ci.mnemonic == "lea" and len(ops) == 2 and ops[1] in ("[%s]" % ops[0], "dword ptr [%s]" % ops[0]):
            rn.discard(ops[0])                              # lea ecx, [ecx]: alignment nop
        if ci.mnemonic in ("mov", "xchg") and len(ops) == 2 and ops[0] == ops[1]:
            rn.discard(self._ALIAS.get(ops[0], ops[0]))     # mov edi, edi: hot-patch nop
        if ci.mnemonic == "push" and ops[0] in self._REGS:
            rn.discard(ops[0])                              # a save or `push ecx` local allocation
        return rn, wn

    def reg_inputs(self, target, depth=0):
        """Registers a function reads before writing them (ecx = this, LTCG register args); None if unknown."""
        cache = self.__dict__.setdefault("_reg_in", {})
        if target in cache:
            return cache[target]
        if not (self.text[0] <= target < self.text[1]) or depth > 3:
            return None
        cache[target] = set()           # recursion guard
        body = (target, target + self.funcs[target][0]) if target in self.funcs else None
        view = CodeView(self.read, target, body, self)
        reads = set()
        work = [(target, frozenset())]
        seen = set()
        steps = 0
        while work and steps < 400:
            a, written = work.pop()
            while steps < 400:
                if (a, written) in seen:
                    break
                seen.add((a, written))
                steps += 1
                ci = next(self.md.disasm(self.read(a, 16), a, 1), None)
                if ci is None:
                    break
                i = view.decode(a)
                rn, wn = self._regs_rw(ci)
                reads |= {x for x in rn if x in self._REGS and x not in written}
                written = written | frozenset(x for x in wn if x in self._REGS)
                if i.kind in ("ret", "stop"):
                    break
                if i.kind == "call" or (i.kind == "jmp" and i.target is not None and not view.internal_target(i.target)):
                    if i.target is not None:
                        sub = self.reg_inputs(i.target, depth + 1)
                        if sub:
                            reads |= {x for x in sub if x not in written}
                    if i.kind == "jmp":
                        break
                    written = written | {"eax", "ecx", "edx"}
                    a += i.size
                    continue
                if i.kind == "jcc":
                    if i.target is not None and view.internal_target(i.target):
                        work.append((i.target, written))
                elif i.kind == "jmp":
                    if i.target is not None and view.internal_target(i.target):
                        a = i.target
                        continue
                    break
                a += i.size
        # Only the caller-saved argument registers: callee-saved ones read early are usually saves or
        # LTCG oddities, and comparing them would flag equivalent code with other register allocation.
        reads &= {"eax", "ecx", "edx"}
        cache[target] = reads
        return reads

    def callee_stack_args(self, target, depth=0):
        """Number of stack argument words a function reads (its semantic arity), or None if unknown."""
        cache = self.__dict__.setdefault("_nargs", {})
        if target in cache:
            return cache[target]
        if not (self.text[0] <= target < self.text[1]) or target not in self.funcs or depth > 3:
            return None
        cache[target] = None
        view = CodeView(self.read, target, (target, target + self.funcs[target][0]), self)
        best = 0
        ok = True
        work = [(target, 0, None)]
        seen = set()
        steps = 0
        while work and steps < 3000 and ok:
            a, d, fb = work.pop()
            while steps < 3000:
                if (a, d, fb) in seen:
                    break
                seen.add((a, d, fb))
                steps += 1
                i = view.decode(a)
                if i is None:
                    ok = False
                    break
                if i.mem is not None:
                    base, disp = i.mem[1], i.mem[4]
                    disp = disp - (1 << 32) if disp & 0x80000000 else disp
                    if base == "esp":
                        if d is None:
                            ok = False
                            break
                        off = disp - d - 4
                    elif base == "ebp":
                        if fb is None:          # a frame set up elsewhere (e.g. an SEH prolog helper)
                            ok = False
                            break
                        off = disp - fb - 4
                    else:
                        off = -1
                    if off >= 0 and i.mnemonic == "lea":
                        ok = False              # an argument's address escapes (va_list style): unknown
                        break
                    if off >= 0:
                        best = max(best, off // 4 + max(1, (i.mem[5] or 4) // 4))
                m, ops = i.mnemonic, i.op_str
                if d is not None:
                    if m == "push":
                        d += 4
                    elif m == "pop":
                        d -= 4
                    elif m in ("sub", "add") and ops.startswith("esp,") and i.imms:
                        d += i.imms[0] if m == "sub" else -i.imms[0]
                    elif m == "and" and ops.startswith("esp,"):
                        d = None
                if m == "mov" and ops == "ebp, esp":
                    fb = d
                elif m == "leave" or (m == "mov" and ops == "esp, ebp"):
                    d = fb
                    fb = None if m == "leave" else fb
                    if m == "leave" and d is not None:
                        d -= 4
                if i.kind in ("ret", "stop"):
                    break
                if i.kind == "call":
                    pop = self.callee_pop(i.target) if i.target is not None else None
                    if pop is None:
                        d = None
                    elif d is not None:
                        d -= pop
                    a += i.size
                    continue
                if i.kind == "jcc":
                    if i.target is not None and view.internal_target(i.target):
                        work.append((i.target, d, fb))
                elif i.kind == "jmp":
                    if i.target is not None and view.internal_target(i.target):
                        a = i.target
                        continue
                    if i.target is not None and d == 0:
                        sub = self.callee_stack_args(i.target, depth + 1)
                        if sub is None:
                            ok = False
                        else:
                            best = max(best, sub)
                    elif i.target is None and i.mem is not None and i.mem[2]:
                        for t in view._table(i):
                            work.append((t, d, fb))
                    break
                a += i.size
        cache[target] = best if ok and steps < 3000 and not work else None
        return cache[target]

    def call_sites(self, target):
        """Addresses of direct `call target` instructions in .text."""
        idx = self.__dict__.get("_sites")
        if idx is None:
            idx = defaultdict(list)
            lo, hi = self.text
            data = self.read(lo, hi - lo)
            k = data.find(b"\xe8")
            while k >= 0:
                if k + 5 <= len(data):
                    rel = struct.unpack_from("<i", data, k + 1)[0]
                    t = (lo + k + 5 + rel) & M32
                    if t in self.funcs:
                        idx[t].append(lo + k)
                k = data.find(b"\xe8", k + 1)
            self._sites = idx
        return idx.get(target, [])

    def callers_use_return(self, target):
        """('eax'|'st0'|None, sites checked): does any direct caller consume the original's return value?"""
        uses_eax = uses_st0 = False
        n = 0
        for site in self.call_sites(target)[:40]:
            view = CodeView(self.read, site, None, self)
            first = view.decode(site)
            if first is None or first.kind != "call" or first.target != target:
                continue
            n += 1
            a = site + 5
            depth = 0
            for _ in range(10):
                ci = next(self.md.disasm(self.read(a, 16), a, 1), None)
                if ci is None:
                    break
                i = view.decode(a)
                req, delta = i.x87
                if req > depth:
                    uses_st0 = True
                    break
                depth += delta
                rn, wn = self._regs_rw(ci)
                if "eax" in rn:
                    uses_eax = True
                    break
                if "eax" in wn or i.kind != "other":
                    break
                a += ci.size
        return ("st0" if uses_st0 else "eax" if uses_eax else None), n


# ---------------------------------------------------------------------------------------------
# Instruction decoding and static analysis (shared by the original and our object).
UC_REGS = None


def _uc_regs():
    global UC_REGS
    if UC_REGS is None:
        from unicorn import x86_const as u
        UC_REGS = {n: getattr(u, "UC_X86_REG_" + n.upper()) for n in (
            "eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp", "eip", "ax", "bx", "cx", "dx", "si", "di",
            "al", "bl", "cl", "dl", "ah", "bh", "ch", "dh")}
    return UC_REGS


class Insn:
    __slots__ = ("addr", "size", "mnemonic", "op_str", "kind", "target", "mem", "regs", "imms",
                 "ret_imm", "x87", "is_fpu_store", "ops")

    def __init__(self, ci, md):
        self.addr, self.size, self.mnemonic, self.op_str = ci.address, ci.size, ci.mnemonic, ci.op_str
        self.target = None
        self.mem = None       # (seg, base, index, scale, disp, size)
        self.regs = []
        self.imms = []
        self.ops = []
        self.ret_imm = 0
        for op in ci.operands:
            if op.type == cx.X86_OP_REG:
                self.regs.append(ci.reg_name(op.reg))
                self.ops.append(("reg", ci.reg_name(op.reg)))
            elif op.type == cx.X86_OP_IMM:
                self.imms.append(op.imm & M32)
                self.ops.append(("imm", op.imm & M32))
            elif op.type == cx.X86_OP_MEM:
                m = op.mem
                self.mem = (ci.reg_name(m.segment) if m.segment else None,
                            ci.reg_name(m.base) if m.base else None,
                            ci.reg_name(m.index) if m.index else None, m.scale, m.disp & M32, op.size)
                self.ops.append(("mem", self.mem))
        mn = self.mnemonic
        if mn == "call":
            self.kind = "call"
        elif mn == "jmp" or mn == "ljmp":
            self.kind = "jmp"
        elif mn.startswith("j") or mn.startswith("loop") or mn in ("jecxz", "jcxz"):
            self.kind = "jcc"
        elif mn in ("ret", "retn", "retf"):
            self.kind = "ret"
            self.ret_imm = self.imms[0] if self.imms else 0
        elif mn in ("int3", "hlt", "ud2", "int"):
            self.kind = "stop"
        else:
            self.kind = "other"
        if self.kind in ("call", "jmp", "jcc") and self.imms and not self.mem and not self.regs:
            self.target = self.imms[0]
        self.x87 = x87_effect(self)
        self.is_fpu_store = mn in ("fst", "fstp")


def _st_index(name):
    m = re.match(r"st\((\d)\)", name or "")
    return int(m.group(1)) if m else None


def x87_effect(insn):
    """(required stack depth, depth delta) for x87 instructions; (0, 0) otherwise."""
    m = insn.mnemonic
    if not m.startswith("f"):
        return (0, 0)
    sts = [_st_index(r) for r in insn.regs if _st_index(r) is not None]
    hi = max(sts) + 1 if sts else 0
    has_mem = insn.mem is not None
    if m in ("fld", "fild", "fbld"):
        return (hi, 1)
    if m in ("fld1", "fldz", "fldpi", "fldl2e", "fldl2t", "fldlg2", "fldln2"):
        return (0, 1)
    if m in ("fst", "fist"):
        return (max(1, hi), 0)
    if m in ("fstp", "fistp", "fbstp", "fisttp"):
        return (max(1, hi), -1)
    if m in ("fadd", "fsub", "fsubr", "fmul", "fdiv", "fdivr"):
        return (1 if has_mem else max(1, hi), 0)
    if m in ("faddp", "fsubp", "fsubrp", "fmulp", "fdivp", "fdivrp"):
        return (max(2, hi), -1)
    if m in ("fiadd", "fisub", "fisubr", "fimul", "fidiv", "fidivr", "ficom"):
        return (1, 0)
    if m in ("fcom", "fucom"):
        return (max(1, hi), 0) if not has_mem else (1, 0)
    if m in ("fcomp", "fucomp", "ficomp"):
        return ((max(1, hi), -1) if not has_mem else (1, -1))
    if m in ("fcompp", "fucompp"):
        return (2, -2)
    if m in ("fcomi", "fucomi"):
        return (max(1, hi), 0)
    if m in ("fcomip", "fucomip"):
        return (max(1, hi), -1)
    if m == "fxch":
        return (max(2, hi), 0)
    if m in ("fchs", "fabs", "fsqrt", "frndint", "fsin", "fcos", "ftst", "fxam", "f2xm1"):
        return (1, 0)
    if m in ("fprem", "fprem1", "fscale"):
        return (2, 0)
    if m in ("fpatan", "fyl2x", "fyl2xp1"):
        return (2, -1)
    if m in ("fsincos", "fptan", "fxtract"):
        return (1, 1)
    if m.startswith("fcmov"):
        return (max(1, hi), 0)
    return (0, 0)


class CodeView:
    """Recursive-descent view of one function's code, from a byte reader at real addresses."""

    def __init__(self, read, entry, body, prog, is_ours=False):
        self.read = read
        self.entry = entry
        self.body = body          # (lo, hi) of the function body, or None
        self.prog = prog
        self.is_ours = is_ours
        self.insns = {}
        self.jcc = []             # conditional branch addresses
        self.setcc = []           # setcc addresses (branch-free conditions count for coverage too)
        self.tables = {}          # indirect jmp addr -> [targets]
        self.table_ranges = []    # (lo, hi) of jump tables (data inside the body)
        self._dec = {}
        self._fret = {}

    def decode(self, addr):
        i = self._dec.get(addr)
        if i is None:
            code = self.read(addr, 16)
            ci = next(self.prog.md.disasm(code, addr, 1), None)
            if ci is None:
                return None
            i = self._dec[addr] = Insn(ci, self.prog.md)
        return i

    def in_body(self, a):
        return self.body is not None and self.body[0] <= a < self.body[1]

    def internal_target(self, a):
        """Is a jump to a part of this function (body or, for the original, an unnamed chunk)?"""
        if a == self.entry:
            return True
        if self.in_body(a):
            return True
        if self.is_ours or self.body is None:
            return False
        return (self.prog.text[0] <= a < self.prog.text[1]) and not self.prog.is_func_start(a)

    def build(self, limit=20000):
        work = [self.entry]
        while work and len(self.insns) < limit:
            a = work.pop()
            while a not in self.insns and len(self.insns) < limit:
                i = self.decode(a)
                if i is None:
                    break
                self.insns[a] = i
                nxt = a + i.size
                if i.mnemonic.startswith("set") and i.kind == "other":
                    self.setcc.append(a)
                if i.kind == "ret" or i.kind == "stop":
                    break
                if i.kind == "jcc":
                    self.jcc.append(a)
                    if i.target is not None and self.internal_target(i.target):
                        work.append(i.target)
                    a = nxt
                    continue
                if i.kind == "jmp":
                    if i.target is not None:
                        if self.internal_target(i.target):
                            work.append(i.target)
                    elif i.mem and i.mem[2] and not i.mem[1] and self.body is not None:
                        tgts = self._table(i)
                        self.tables[a] = tgts
                        work.extend(tgts)
                    break
                a = nxt
        return self

    def _table(self, i):
        base = i.mem[4]
        out = []
        for k in range(512):
            v = struct.unpack("<I", self.read(base + 4 * k, 4))[0]
            if not self.internal_target(v) or v in self.prog.funcs and v != self.entry:
                break
            out.append(v)
        if out:
            self.table_ranges.append((base, base + 4 * len(out)))
        return out

    def float_ret_after(self, call_addr, own_float_ret):
        """Does the code after this call consume st0 (i.e. the callee returns a float)?"""
        if call_addr in self._fret:
            return self._fret[call_addr]
        i0 = self.decode(call_addr)
        start = call_addr + i0.size
        res = False
        seen = set()
        stack = [(start, 0)]
        steps = 0
        if i0.kind == "jmp":           # tail call: the result is ours
            res = own_float_ret
            stack = []
        while stack and steps < 400 and not res:
            a, d = stack.pop()
            while (a, d) not in seen and steps < 400:
                seen.add((a, d))
                steps += 1
                i = self.decode(a)
                if i is None:
                    break
                req, delta = i.x87
                if req > d:
                    res = True
                    break
                d = max(0, d + delta)
                if i.kind == "ret":
                    if own_float_ret and d == 0:
                        res = True
                    break
                if i.kind in ("call", "stop"):
                    break
                if i.kind == "jcc":
                    if i.target is not None:
                        stack.append((i.target, d))
                elif i.kind == "jmp":
                    if i.target is not None and self.internal_target(i.target):
                        a = i.target
                        continue
                    if i.target is not None and own_float_ret and d == 0:
                        res = True
                    break
                a = a + i.size
        self._fret[call_addr] = res
        return res

    def cleanup_after(self, call_addr):
        """Bytes the caller pops after a call (cdecl cleanup), or None."""
        i = self.decode(call_addr)
        a = call_addr + i.size
        for k in range(8):
            j = self.decode(a)
            if j is None:
                return None
            if j.mnemonic == "add" and j.op_str.startswith("esp,") and j.imms:
                return j.imms[0]
            if j.mnemonic == "pop" and j.regs == ["ecx"]:
                n = 0
                while j is not None and j.mnemonic == "pop" and j.regs == ["ecx"] and n < 8:
                    n += 4
                    a += j.size
                    j = self.decode(a)
                # /O1 cleans 4 or 8 bytes with pop ecx; an epilogue pops more registers and returns
                if j is None or j.kind == "ret" or j.mnemonic in ("pop", "leave") or \
                        (j.mnemonic == "mov" and j.op_str == "esp, ebp"):
                    return None
                return n
            if j.kind != "other" or j.mnemonic in ("push", "pop", "sub", "leave", "pushal", "popal", "pushfd",
                                                  "popfd") or "esp" in j.op_str.split(",")[0]:
                return None
            a += j.size
        return None

    def prologue(self):
        """Addresses of prologue instructions whose pushes are not call arguments."""
        out = set()
        a = self.entry
        prev = None
        for _ in range(16):
            i = self.decode(a)
            if i is None:
                break
            m, ops = i.mnemonic, i.op_str
            nxt = self.decode(a + i.size)
            ok = False
            if m == "push" and i.regs and i.regs[0] in ("ebp", "ebx", "esi", "edi"):
                ok = True
            elif m == "push" and i.regs and i.regs[0] in ("ecx", "eax", "edx") and nxt is not None \
                    and nxt.kind != "call" and not (prev and prev.mnemonic == "mov" and "fs:" in prev.op_str):
                ok = True
            elif m == "push" and i.regs and i.regs[0] == "eax" and prev is not None and "fs:" in prev.op_str:
                ok = True
            elif m == "push" and i.imms and (i.imms[0] == M32 or (prev is not None and prev.mnemonic == "push"
                                                                  and prev.imms and prev.imms[0] == M32)):
                ok = True
            elif m == "mov" and (ops == "ebp, esp" or "fs:" in ops):
                ok = True
            elif m in ("sub", "and") and ops.startswith("esp,"):
                ok = True
            elif m == "mov" and ops.startswith("eax,") and i.imms and nxt is not None and nxt.kind == "call":
                ok = True   # mov eax, N; call __chkstk
            elif m == "call" and prev is not None and prev.mnemonic == "mov" and prev.op_str.startswith("eax,") \
                    and prev.imms and prev.addr in out:
                ok = True
            if not ok:
                break
            out.add(a)
            prev = i
            a += i.size
        return out


# ---------------------------------------------------------------------------------------------
# COFF object (keeps what linking needs: section flags, sizes, all relocations).
class Obj:
    def __init__(self, path):
        d = self.data = open(path, "rb").read()
        _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
        strtab = symoff + nsym * 18
        self.sections = []
        for i in range(nsec):
            o = 20 + opthdr + i * 40
            name = d[o:o + 8].rstrip(b"\0").decode("latin1")
            _, _, size, raw, relptr, _, nrel, _, flags = struct.unpack_from("<IIIIIIHHI", d, o + 8)
            relocs = [struct.unpack_from("<IIH", d, relptr + j * 10) for j in range(nrel)]
            if name.startswith("/"):
                off = int(name[1:])
                name = d[strtab + off:d.index(b"\0", strtab + off)].decode("latin1")
            self.sections.append({"name": name, "size": size, "raw": d[raw:raw + size] if raw else None,
                                  "relocs": relocs, "flags": flags})
        self.syms = {}
        i = 0
        while i < nsym:
            o = symoff + i * 18
            if d[o:o + 4] == b"\0\0\0\0":
                off, = struct.unpack_from("<I", d, o + 4)
                name = d[strtab + off:d.index(b"\0", strtab + off)].decode("latin1")
            else:
                name = d[o:o + 8].rstrip(b"\0").decode("latin1")
            value, secnum, typ, cls, naux = struct.unpack_from("<IhHBB", d, o + 8)
            self.syms[i] = (name, value, secnum, typ, cls)
            i += 1 + naux

    def functions(self):
        return [s for s in self.syms.values() if s[2] > 0 and s[3] == 0x20]

    def func_extent(self, sym):
        name, value, secnum, _, _ = sym
        ends = sorted(s[1] for s in self.functions() if s[2] == secnum and s[1] > value)
        sec = self.sections[secnum - 1]
        end = ends[0] if ends else sec["size"]
        return secnum, value, end


def _linkable(sec):
    f = sec["flags"]
    if f & 0x800 or f & 0x200:          # LNK_REMOVE / LNK_INFO (.drectve)
        return False
    if sec["name"].startswith(".debug"):
        return False
    return sec["size"] > 0


# ---------------------------------------------------------------------------------------------
# Signatures from MSVC mangled names.
FLOAT_T = {"float": "f32", "double": "f64", "long double": "f64"}


def _kind_of(t):
    t = t.strip()
    if t.endswith("*") or t.endswith("&") or "(__" in t:
        return "ptr"
    if t in FLOAT_T:
        return FLOAT_T[t]
    if t == "void":
        return "void"
    if t == "bool":
        return "b8"
    if t in ("char", "signed char", "unsigned char"):
        return "i8"
    if t in ("short", "unsigned short", "wchar_t"):
        return "i16"
    if t in ("__int64", "unsigned __int64"):
        return "i64"
    if t.startswith(("class ", "struct ", "union ")):
        return "struct"
    return "i32"


def parse_signature(mangled):
    """{'cc', 'this', 'ret', 'params': [kinds]} from a mangled name, or a partial dict for C names."""
    if mangled.startswith("?"):
        try:
            s = mangled
            special = None
            if s.startswith("??"):
                code = s[2]
                if code == "_":
                    code = s[2:4]
                    rest = s[4:]
                else:
                    rest = s[3:]
                special = code
                p = _Parser(rest)
            else:
                p = _Parser(s[1:])
            p.qualified_name()
            acc = p.take()
            if acc in "YZ":
                has_this = False
            elif acc in "CDKLST":
                has_this = False
            elif acc in "ABEFIJMNQRUV":
                has_this = True
                p.take()     # this cv
            else:
                return None
            cc = {"A": "cdecl", "E": "thiscall", "G": "stdcall", "I": "fastcall"}.get(p.take(), "cdecl")
            if p.peek() == "@":
                p.take()
                ret = "ptr" if special in ("0", "_G", "_E") else "void"
            else:
                if p.peek(2) == "?A":
                    p.take(2)
                ret = _kind_of(p.type())
            params, types = [], []
            if p.peek() == "X":
                p.take()
            else:
                p.types = []           # argument back-references count top-level argument types only
                while p.peek() not in ("@", "Z", ""):
                    start, saved = p.i, list(p.types)
                    t = p.type()
                    p.types = saved
                    if p.i - start > 1 and len(p.types) < 10:
                        p.types.append(t)
                    types.append(t)
                    params.append(_kind_of(t))
            return {"cc": cc, "this": has_this, "ret": ret, "params": params, "param_types": types}
        except (DemangleError, IndexError, StopIteration):
            return None
    m = re.match(r"^([_@])(.+?)(?:@(\d+))?$", mangled)
    if m:
        n = int(m.group(3)) // 4 if m.group(3) else None
        cc = "fastcall" if m.group(1) == "@" else ("stdcall" if m.group(3) else "cdecl")
        return {"cc": cc, "this": False, "ret": None, "params": ["i32"] * n if n is not None else None}
    return None


def ghidra_ret_kind(addr):
    p = os.path.join(GHIDRA_C, "0x%08x.c" % addr)
    if not os.path.exists(p):
        return None
    for line in open(p, errors="replace"):
        line = line.strip()
        if not line or line.startswith("/") or line.startswith("*"):
            continue
        m = re.match(r"^(\w[\w\s\*]*?)\s+(__\w+\s+)?[\w:<>~]+\s*\(", line)
        if not m:
            return None
        t = m.group(1).strip()
        if t.endswith("*"):
            return "ptr"
        return {"void": "void", "float": "f32", "double": "f64", "float10": "f64", "bool": "b8",
                "char": "i8", "byte": "i8", "undefined1": "i8", "uchar": "i8", "short": "i16", "ushort": "i16",
                "undefined2": "i16", "longlong": "i64", "ulonglong": "i64", "undefined8": "i64"}.get(t, "i32")
    return None


PRIM_SIZE = {"char": 1, "signed char": 1, "unsigned char": 1, "bool": 1, "short": 2, "unsigned short": 2,
             "wchar_t": 2, "int": 4, "unsigned int": 4, "long": 4, "unsigned long": 4, "float": 4, "double": 8,
             "long double": 8, "__int64": 8, "unsigned __int64": 8}


def _pointee(t):
    """'const class Foo *' -> 'class Foo'; None if t is not a pointer/reference."""
    t = t.strip()
    if not (t.endswith("*") or t.endswith("&")) or "(__" in t:
        return None
    t = t[:-1].strip()
    for cv in ("const volatile ", "const ", "volatile "):
        if t.startswith(cv):
            t = t[len(cv):]
    return t


def pointee_sizes(src, flags, names):
    """{mangled callee name: {stack arg index: sizeof(*arg)}} for our callees' pointer parameters.

    Primitive pointees are sized directly; class types by compiling a sizeof probe appended to SRC.
    """
    want = {}
    classes = set()
    for n in names:
        sig = parse_signature(n)
        if not sig or not sig.get("param_types"):
            continue
        idx = 1 if sig.get("ret") == "struct" else 0
        for k, t in enumerate(sig["param_types"]):
            pt = _pointee(t)
            if pt is None:
                continue
            if pt in PRIM_SIZE:
                want.setdefault(n, {})[idx + k] = PRIM_SIZE[pt]
            elif pt.startswith(("class ", "struct ", "union ")):
                want.setdefault(n, {})[idx + k] = pt.split(" ", 1)[1]
                classes.add(pt.split(" ", 1)[1])
            elif pt.endswith("*"):
                want.setdefault(n, {})[idx + k] = 4
    sizes = {}
    if classes and src and os.path.exists(src):
        sizes = _probe_sizes(src, flags, sorted(classes))
    out = {}
    for n, d in want.items():
        for k, v in d.items():
            v = sizes.get(v) if isinstance(v, str) else v
            if v:
                out.setdefault(n, {})[k] = v
    return out


def _probe_sizes(src, flags, classes):
    text = open(src, errors="replace").read()
    res = {}

    def attempt(cls):
        body = text + "\nextern \"C\" const unsigned equiv_sizeof_probe[] = {%s};\n" % ", ".join(
            "sizeof(%s)" % c for c in cls)
        with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as d:
            p = os.path.join(d, "probe.cpp")
            open(p, "w").write(body)
            try:
                obj = Obj(compile_obj(p, DEFAULT_FLAGS + list(flags), d))
            except CompileError:
                return None
            for name, value, secnum, _, _ in obj.syms.values():
                if name == "_equiv_sizeof_probe" and secnum > 0:
                    raw = obj.sections[secnum - 1]["raw"] or b""
                    return list(struct.unpack_from("<%dI" % len(cls), raw, value))
        return None
    vals = attempt(classes)
    if vals is not None:
        return dict(zip(classes, vals))
    for c in classes[:8]:            # some type is incomplete: probe one by one
        v = attempt([c])
        if v:
            res[c] = v[0]
    return res


MATH1 = {"sin": math.sin, "cos": math.cos, "tan": math.tan, "sqrt": math.sqrt, "exp": math.exp, "log": math.log,
         "log10": math.log10, "fabs": abs, "floor": math.floor, "ceil": math.ceil, "atan": math.atan,
         "asin": math.asin, "acos": math.acos, "sinh": math.sinh, "cosh": math.cosh, "tanh": math.tanh}
MATH2 = {"atan2": math.atan2, "pow": math.pow, "fmod": math.fmod}
X87_NAN = struct.unpack("<d", bytes.fromhex("000000000000f8ff"))[0]     # the x87 "indefinite" NaN
INTRINSIC_NAMES = {"_memcpy", "_memmove", "_memset", "_strlen", "_strcmp", "_stricmp", "__stricmp", "_strncmp",
                   "__strnicmp", "_strcpy", "_strcat", "__ReadWriteBarrier"} | {"_" + k for k in MATH1} | \
    {"_" + k for k in MATH2}


# ---------------------------------------------------------------------------------------------
# The XBE's own CRT routines, found by behaviour (memcpy & co. are inlined in some code and called in
# other code; executing the real routine on both sides makes that difference disappear).
CRT_REGION = (0x340000, 0x364840)
CRT_CACHE = os.path.join(ROOT, "build/equiv/crt.json")


def _crt_probe(prog, addr, args, buffers, float_args=None, steps=200000):
    """Call a cdecl function on a scratch machine; returns (eax, st0 or None, memory reader) or None."""
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_MEM_UNMAPPED, UcError
    from unicorn import x86_const as u
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    mapped = set()

    def unm(uc_, access, a, size, value, _):
        pg = a & ~0xFFF
        if pg in mapped:
            return True
        mapped.add(pg)
        if IMAGE_LO <= pg < IMAGE_HI:
            uc_.mem_map(pg, PAGE)
            uc_.mem_write(pg, prog.image_page(pg))
            return True
        if 0x50000000 <= pg < 0x50100000 or pg < 0x10000:
            uc_.mem_map(pg, PAGE)
            return True
        return False
    uc.hook_add(UC_HOOK_MEM_UNMAPPED, unm)
    uc.mem_map(STACK_LO, STACK_HI - STACK_LO)
    uc.mem_map(TRAMP, PAGE)
    uc.mem_write(TRAMP, b"\xf4" * PAGE)
    uc.reg_write(u.UC_X86_REG_FPCW, 0x027F)
    for a, data in buffers.items():
        unm(uc, 0, a, 1, 0, None)
        uc.mem_write(a, data)
    words = list(args)
    stack = struct.pack("<I", SENTINEL) + b"".join(struct.pack("<I", w & M32) for w in words) + bytes(64)
    uc.mem_write(ENTRY_ESP, stack)
    uc.reg_write(u.UC_X86_REG_ESP, ENTRY_ESP)
    try:
        uc.emu_start(addr, SENTINEL, count=steps)
    except UcError:
        return None
    if uc.reg_read(u.UC_X86_REG_EIP) != SENTINEL or uc.reg_read(u.UC_X86_REG_ESP) != ENTRY_ESP + 4:
        return None
    top = (uc.reg_read(u.UC_X86_REG_FPSW) >> 11) & 7
    st0 = _x87_value(uc.reg_read(u.UC_X86_REG_FP0 + top)) if (8 - top) % 8 else None
    return uc.reg_read(u.UC_X86_REG_EAX), st0, (lambda a, n: bytes(uc.mem_read(a, n)))


def _dwords(d):
    return list(struct.unpack("<II", struct.pack("<d", d)))


def _is_crt(prog, addr, name):
    A, B = 0x50000100, 0x50000800
    try:
        if name in ("_memcpy", "_memmove"):
            src = bytes(range(1, 40))
            r = _crt_probe(prog, addr, [A, B, 37], {B: src, A: b"\xee" * 64})
            return bool(r) and r[0] == A and r[2](A, 38) == src[:37] + b"\xee"
        if name == "_memset":
            r = _crt_probe(prog, addr, [A, 0x1AB, 37], {A: b"\x11" * 64})
            return bool(r) and r[0] == A and r[2](A, 38) == b"\xab" * 37 + b"\x11"
        if name == "_strlen":
            r = _crt_probe(prog, addr, [A], {A: b"hello world\0"})
            r2 = _crt_probe(prog, addr, [A], {A: b"\0"})
            return bool(r and r2) and r[0] == 11 and r2[0] == 0
        if name in ("_strcmp", "__stricmp", "_strncmp"):
            n3 = [3] if name == "_strncmp" else []
            a1 = _crt_probe(prog, addr, [A, B] + n3, {A: b"abcx\0", B: b"abcy\0"})
            a2 = _crt_probe(prog, addr, [A, B] + n3, {A: b"abd\0", B: b"abc\0"})
            a3 = _crt_probe(prog, addr, [A, B] + n3, {A: b"ABC\0", B: b"abc\0"})
            if not (a1 and a2 and a3):
                return False
            sgn = lambda v: 0 if v == 0 else (-1 if v & 0x80000000 else 1)
            want = {"_strcmp": (-1, 1, -1), "__stricmp": (-1, 1, 0), "_strncmp": (0, 1, -1)}[name]
            return (sgn(a1[0]), sgn(a2[0]), sgn(a3[0])) == want
        if name in ("_strcpy", "_strcat"):
            r = _crt_probe(prog, addr, [A, B], {A: b"xy\0zzzzzz", B: b"abc\0"})
            want = b"abc\0" if name == "_strcpy" else b"xyabc\0"
            return bool(r) and r[0] == A and r[2](A, len(want)) == want
        if name[1:] in MATH1:
            for x in (0.375, 2.75, -1.625):
                try:
                    want = MATH1[name[1:]](x)
                except ValueError:
                    continue
                r = _crt_probe(prog, addr, _dwords(x), {})
                if not (r and r[1] is not None and _feq(r[1], want, 1e-9, 1e-12)):
                    return False
            return True
        if name[1:] in MATH2:
            for x, y in ((0.375, 1.5), (2.75, -0.5), (7.0, 2.5)):
                try:
                    want = MATH2[name[1:]](x, y)
                except ValueError:
                    continue
                r = _crt_probe(prog, addr, _dwords(x) + _dwords(y), {})
                if not (r and r[1] is not None and _feq(r[1], want, 1e-9, 1e-12)):
                    return False
            return True
    except Exception:
        return False
    return False


def crt_table(prog):
    """{CRT name: address} for the XBE's CRT routines, cached in build/equiv/crt.json."""
    if os.path.exists(CRT_CACHE):
        return json.load(open(CRT_CACHE))
    found = {}
    names = ["_memcpy", "_memset", "_strlen", "_strcmp", "__stricmp", "_strncmp", "_strcpy", "_strcat",
             "_memmove"] + ["_" + k for k in MATH1 if k != "fabs"] + ["_" + k for k in MATH2]
    cands = sorted(a for a in prog.funcs if CRT_REGION[0] <= a < CRT_REGION[1] and prog.callee_pop(a) == 0)
    for name in names:
        for a in cands:
            if a in found.values() and name != "_memmove":
                continue
            if _is_crt(prog, a, name):
                found[name] = a
                break
    os.makedirs(os.path.dirname(CRT_CACHE), exist_ok=True)
    json.dump({k: v for k, v in found.items()}, open(CRT_CACHE, "w"), indent=1)
    return found


# ---------------------------------------------------------------------------------------------
# Deterministic fuzz values.
def mix(*xs):
    h = 0x9E3779B97F4A7C15
    for x in xs:
        h ^= x & M64
        h = (h * 0xBF58476D1CE4E5B9) & M64
        h ^= h >> 31
        h = (h * 0x94D049BB133111EB) & M64
        h ^= h >> 29
    return h


FLOATS = [0.0, 1.0, 0.5, -1.0, 2.0, 10.0, 100.0, 0.25, 3.14159, -0.5, 1000.0, 0.001, 0.75, -2.0, 5.0, 64.0]


def f32bits(f):
    return struct.unpack("<I", struct.pack("<f", f))[0]


def fuzz_value(h, kind="any"):
    """A 32-bit value shaped like real data: zero, small ints, heap pointers, floats, flags."""
    sel = h & 15
    r = h >> 4
    if kind == "ptr":
        return 0 if sel == 0 else HEAP + ((r % HEAP_SIZE) & ~3)
    if kind == "f32":
        return f32bits(FLOATS[r % len(FLOATS)] * (1.0 if sel < 12 else (1 + (r >> 8) % 1000) / 37.0))
    if kind == "b8":
        return r & 1
    if kind in ("i8", "i16", "i32") and sel < 9:
        return 0 if sel < 4 else r % 8
    if kind == "tame":         # mostly small numbers and pointers: loop bounds stay small
        if sel <= 3:
            return 0
        if sel <= 6:
            return HEAP + ((r % HEAP_SIZE) & ~3)
        if sel <= 12:
            return r % 16
        return f32bits(FLOATS[r % len(FLOATS)])
    if sel <= 2:
        return 0
    if sel <= 5:
        return HEAP + ((r % HEAP_SIZE) & ~3)
    if sel <= 7:
        return r % 8
    if sel == 8:
        return r % 256
    if sel == 9:
        return M32
    if sel <= 11:
        return f32bits(FLOATS[r % len(FLOATS)])
    if sel == 12:
        return 1
    if sel == 13:
        return r & M32
    if sel == 14:
        return (r % 64) * 4
    return 1 << (r % 32)


_TEMPLATES = None


def templates():
    global _TEMPLATES
    if _TEMPLATES is None:
        _TEMPLATES = [struct.pack("<1024I", *[fuzz_value(mix(0x7E57, t, i), "any" if t < 32 else "tame")
                                              for i in range(1024)]) for t in range(64)]
    return _TEMPLATES


# ---------------------------------------------------------------------------------------------
class Fault(Exception):
    pass


class Machine:
    """Initial memory state for one input: a deterministic function of (seed, epoch, address)."""

    def __init__(self, prog, seed, globals_, pristine=False, dictionary=(), pointers=(), overlay=None):
        self.overlay = overlay or {}       # {(epoch, addr): bytes} forced by directed inputs
        # memory modes: "narrow" folds every heap pointer into 512 bytes (begin/end ranges stay short);
        # "noise" fills memory with random bytes (copies and byte loads see distinct values)
        self.narrow = seed % 5 == 3
        self.noise = seed % 4 == 3
        self.prog = prog
        self.seed = seed
        self.globals = sorted(globals_)
        self.pristine = pristine
        self.dictionary = list(dictionary)
        self.pointers = list(pointers)
        self._cache = {}

    def page(self, page, epoch):
        key = (page, epoch)
        b = self._cache.get(key)
        if b is not None:
            return b
        if page < NULL_HI:
            b = bytes(PAGE)
        elif IMAGE_LO <= page < IMAGE_HI:
            b = self.prog.image_page(page)
            if not self.pristine:
                gs = [g for g in self.globals if page - 16 < g < page + PAGE]
                if gs:
                    buf = bytearray(b)
                    for g in gs:
                        for k in range(4):
                            a = g + 4 * k
                            if page <= a and a + 4 <= page + PAGE:
                                buf[a - page:a - page + 4] = struct.pack("<I", fuzz_value(mix(self.seed, epoch, a)))
                    b = bytes(buf)
        elif self.noise and mix(self.seed, page, 0x401) & 1:     # half the pages: structured fields elsewhere
            import random
            b = random.Random(mix(self.seed, epoch, page, 0x9015E)).randbytes(PAGE)
        else:
            b = templates()[mix(self.seed, epoch, page) % 32 + (32 if self.seed % 2 else 0)]
            if self.narrow:
                w = list(struct.unpack("<1024I", b))
                b = struct.pack("<1024I", *[(HEAP + (v & 0x1FC)) if HEAP <= v < HEAP + HEAP_SIZE else v for v in w])
            if self.dictionary:
                # plant interesting values (the input's pointers, constants the code compares against)
                import random
                buf = bytearray(b)
                rnd = random.Random(mix(self.seed, epoch, page, 0xD1C7))
                for i, v in zip(rnd.choices(range(1024), k=192), rnd.choices(self.dictionary, k=192)):
                    struct.pack_into("<I", buf, 4 * i, v)
                if self.pointers:
                    # a small object graph: fields point back at the input objects (and just past them)
                    for i, v in zip(rnd.choices(range(1024), k=320), rnd.choices(self.pointers, k=320)):
                        struct.pack_into("<I", buf, 4 * i, v)
                b = bytes(buf)
        if self.overlay:
            hits = [(a, v) for (e, a), v in self.overlay.items() if e == epoch and page <= a < page + PAGE]
            if hits:
                buf = bytearray(b)
                for a, v in hits:
                    n = min(len(v), page + PAGE - a)
                    buf[a - page:a - page + n] = v[:n]
                b = bytes(buf)
        if len(self._cache) > 4096:
            self._cache.clear()
        self._cache[key] = b
        return b

    def byte(self, addr, epoch):
        p = addr & ~0xFFF
        return self.page(p, epoch)[addr - p]


def _reserved(a):
    return any(lo <= a < hi for lo, hi in RESERVED)


def _x87_value(mant_exp):
    mant, exp = mant_exp
    sign = -1.0 if exp & 0x8000 else 1.0
    e = exp & 0x7FFF
    if e == 0x7FFF:
        return float("nan") if mant & ((1 << 63) - 1) else sign * float("inf")
    if mant == 0:
        return 0.0 * sign
    try:
        return sign * math.ldexp(mant, e - 16383 - 63)
    except OverflowError:
        return sign * float("inf")


class Run:
    """One execution of one function (original or ours) on one input."""

    def __init__(self, prog, view, machine, inp, ours_image=None, sig=None, max_steps=50000,
                 own_float_ret=False, coverage=None, helpers=None):
        self.prog, self.view, self.m, self.inp = prog, view, machine, inp
        self.ours_image = ours_image
        self.sig = sig
        self.max_steps = max_steps
        self.own_float_ret = own_float_ret
        self.coverage = coverage
        self.helpers = helpers or {}
        self.calls = []
        self.segments = []          # per call boundary: {addr: byte}
        self.seg_fpu = []           # per segment: {dword addr: size} written by fst/fstp
        self.cur_fpu = {}
        self.epoch = 0
        self.mapped = set()
        self.stack_fpu = {}
        self.tracked = set()
        self.save_slots = set()     # stack slots holding saved callee-saved registers
        self.stack_written = set()  # stack bytes written since entry (uninitialised bytes are not compared)
        self.func_stack_written = set()  # ... by the function itself (not by a stub's out-param write)
        self.helper_ret = None
        self.prev_jcc = None
        self.fault = None
        self.cur_insn = None
        self.edges = set()
        self.executed = set()
        self.loads = {}             # register -> (address, size, epoch) it was last loaded from
        self.last_cmp = None
        self.prev_set = None
        self.cmp_obs = {}           # jcc -> observation of the comparison that fed it
        self.prologue = view.prologue()
        self.pointee_sizes = {}     # callee address -> {arg index: bytes}
        self.intrinsics = {}        # unresolved CRT symbol address -> name, executed semantically
        self.local_code = None      # (lo, hi) of our object's own code, executed rather than stubbed
        self.slot_arity = None      # vtable slot offset -> (pop, nargs), learned from the original's runs

    # -- setup ---------------------------------------------------------------------------------
    def _setup(self):
        from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED, \
            UC_HOOK_MEM_WRITE, UC_HOOK_INTR
        from unicorn import x86_const as u
        uc = self.uc = Uc(UC_ARCH_X86, UC_MODE_32)

        def desc(base, limit, access, flags):
            return struct.pack("<HHBBBB", limit & 0xFFFF, base & 0xFFFF, (base >> 16) & 0xFF, access,
                               ((limit >> 16) & 0xF) | (flags << 4), (base >> 24) & 0xFF)
        uc.mem_map(GDT, PAGE)
        gdt = b"\0" * 8 + desc(0, 0xFFFFF, 0x9A, 0xC) + desc(0, 0xFFFFF, 0x92, 0xC) + desc(TIB, 0xFFF, 0x92, 0x4)
        uc.mem_write(GDT, gdt)
        uc.reg_write(u.UC_X86_REG_GDTR, (0, GDT, len(gdt) - 1, 0))
        uc.reg_write(u.UC_X86_REG_FS, 3 * 8)
        for seg in ("SS", "DS", "ES"):
            uc.reg_write(getattr(u, "UC_X86_REG_" + seg), 2 * 8)
        uc.mem_map(TIB, PAGE)
        uc.mem_write(TIB, struct.pack("<I", M32) + b"\0" * (PAGE - 4))
        uc.mem_map(STACK_LO, STACK_HI - STACK_LO)
        uc.mem_write(STACK_LO, struct.pack("<I", STACK_FILL) * ((STACK_HI - STACK_LO) // 4))
        # trampolines: [p/4*16] ret p ; [0x800 + p/4*16] fld dword [FSLOT]; ret p
        tr = bytearray(b"\xf4" * PAGE)
        for k in range(64):
            tr[k * 16:k * 16 + 3] = b"\xc2" + struct.pack("<H", 4 * k)
            tr[0x400 + k * 16:0x400 + k * 16 + 9] = b"\xdd\x05" + struct.pack("<I", FSLOT) + b"\xc2" + \
                struct.pack("<H", 4 * k)
            tr[0x800 + k * 16:0x800 + k * 16 + 9] = b"\xd9\x05" + struct.pack("<I", FSLOT) + b"\xc2" + \
                struct.pack("<H", 4 * k)
        uc.mem_map(TRAMP, PAGE)
        uc.mem_write(TRAMP, bytes(tr))
        if self.ours_image is not None:
            base, img = self.ours_image
            uc.mem_map(OURS, OURS_SIZE)
            uc.mem_write(base, img)
        uc.reg_write(u.UC_X86_REG_FPCW, 0x027F)
        inp = self.inp
        for r, v in inp["regs"].items():
            uc.reg_write(getattr(u, "UC_X86_REG_" + r.upper()), v)
        esp = ENTRY_ESP
        uc.mem_write(esp, struct.pack("<I", SENTINEL) + struct.pack("<%dI" % len(inp["stack"]), *inp["stack"]))
        uc.reg_write(u.UC_X86_REG_ESP, esp)
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self._on_unmapped)
        uc.hook_add(UC_HOOK_MEM_WRITE, self._on_write)
        uc.hook_add(UC_HOOK_CODE, self._on_code)
        uc.hook_add(UC_HOOK_INTR, self._on_intr)
        self.u = u

    # -- hooks ---------------------------------------------------------------------------------
    def _on_unmapped(self, uc, access, addr, size, value, _):
        page = addr & ~0xFFF
        if _reserved(addr):
            self.fault = self.fault or ("bad_access", addr)
            return False
        if len(self.mapped) > 1000:
            self.fault = self.fault or ("too_many_pages", addr)
            return False
        try:
            uc.mem_map(page, PAGE)
        except Exception:
            self.fault = self.fault or ("map_failed", addr)
            return False
        uc.mem_write(page, self.m.page(page, self.epoch))
        self.mapped.add(page)
        # an access straddling two pages
        if (addr + size - 1) & ~0xFFF != page and (addr + size - 1) & ~0xFFF not in self.mapped:
            p2 = (addr + size - 1) & ~0xFFF
            if not _reserved(p2):
                uc.mem_map(p2, PAGE)
                uc.mem_write(p2, self.m.page(p2, self.epoch))
                self.mapped.add(p2)
        return True

    def _on_write(self, uc, access, addr, size, value, _):
        if STACK_LO <= addr < STACK_HI:
            ci = self.cur_insn
            if not (ci is not None and ci.mnemonic == "push" and ci.addr in self.prologue):
                self.stack_written.update(range(addr, addr + size))    # (prologue pushes allocate/save)
                self.func_stack_written.update(range(addr, addr + size))
            if self.cur_insn is not None and self.cur_insn.is_fpu_store:
                self.stack_fpu[addr] = size
            else:
                for a in range(addr & ~3, addr + size, 4):
                    self.stack_fpu.pop(a, None)
            return
        if TIB <= addr < TIB + PAGE:
            return
        if self.cur_insn is not None and self.cur_insn.is_fpu_store and size in (4, 8):
            self.cur_fpu[addr] = size

    def _on_intr(self, uc, intno, _):
        self.fault = self.fault or ("interrupt_%d" % intno, uc.reg_read(self.u.UC_X86_REG_EIP))
        uc.emu_stop()

    def reg(self, name):
        return self.uc.reg_read(_uc_regs()[name])

    def _ea(self, mem):
        seg, base, index, scale, disp, _ = mem
        a = disp
        if base:
            a += self.reg(base)
        if index:
            a += self.reg(index) * scale
        if seg == "fs":
            a += TIB
        return a & M32

    def _read_u32(self, a):
        try:
            return struct.unpack("<I", self.uc.mem_read(a, 4))[0]
        except Exception:
            # force a lazy map through an emulated-style access
            p = a & ~0xFFF
            if _reserved(a):
                self.fault_detail = a
                raise Fault("bad_access")
            for pg in {p, (a + 3) & ~0xFFF}:
                if pg not in self.mapped:
                    self.uc.mem_map(pg, PAGE)
                    self.uc.mem_write(pg, self.m.page(pg, self.epoch))
                    self.mapped.add(pg)
            return struct.unpack("<I", self.uc.mem_read(a, 4))[0]

    def _close_segment(self):
        """Snapshot every byte that differs from the segment's initial state (non-stack memory)."""
        snap = {}
        uc = self.uc
        pages = [(p, self.m.page(p, self.epoch)) for p in self.mapped]
        if self.ours_image is not None:
            base, img = self.ours_image
            for off in range(0, len(img), PAGE):
                chunk = img[off:off + PAGE]
                pages.append((base + off, chunk))
        for p, exp in pages:
            cur = bytes(uc.mem_read(p, len(exp)))
            if cur == exp:
                continue
            for c in range(0, len(exp), 64):
                if cur[c:c + 64] != exp[c:c + 64]:
                    for i in range(c, min(c + 64, len(exp))):
                        if cur[i] != exp[i]:
                            snap[p + i] = cur[i]
        self.segments.append(snap)
        self.seg_fpu.append(self.cur_fpu)
        self.cur_fpu = {}

    def _perturb(self):
        """After a stubbed call: the callee may have changed any non-stack memory."""
        self.epoch += 1
        keep = set()
        for p in self.mapped:
            if self.prog.text[0] <= p < self.prog.text[1]:
                keep.add(p)     # never touch code pages
            else:
                self.uc.mem_unmap(p, PAGE)    # remapped with the new epoch's contents on next touch
        self.mapped = keep

    def _mem(self, a, n, data=None):
        """Read (or write) n bytes, mapping lazily like an emulated access would."""
        if a + n > (1 << 32):                      # wraps around like the CPU's own string ops
            k = (1 << 32) - a
            if data is None:
                return self._mem(a, k) + self._mem(0, n - k)
            self._mem(a, k, data[:k])
            self._mem(0, n - k, data[k:])
            return None
        if POISON < a + n and a < POISON + 0x10000:     # the only unmapped reserved range
            raise Fault("intrinsic_access")
        if n > PAGE * (1000 - len(self.mapped)):
            raise Fault("too_many_pages")          # the original's inline loop would run out of pages too
        for pg in range(a & ~0xFFF, ((a + max(n, 1) - 1) & ~0xFFF) + PAGE, PAGE):
            if pg not in self.mapped and not any(lo <= pg < hi for lo, hi in RESERVED):
                self.uc.mem_map(pg, PAGE)
                self.uc.mem_write(pg, self.m.page(pg, self.epoch))
                self.mapped.add(pg)
        if data is None:
            return bytes(self.uc.mem_read(a, n))
        self.uc.mem_write(a, data)

    def _cstr(self, a, limit=1 << 16):
        out = bytearray()
        while len(out) < limit:
            chunk = self._mem(a + len(out), min(64, PAGE - ((a + len(out)) & 0xFFF)))
            k = chunk.find(b"\0")
            if k >= 0:
                return bytes(out + chunk[:k])
            out += chunk
        raise Fault("intrinsic_access")

    def _intrinsic(self, insn, name, tail):
        """A CRT routine the original inlined: do what it does, without a call-trace entry."""
        u = self.u
        esp = self.reg("esp")
        base = esp + 4 if tail else esp
        w = [self._read_u32(base + 4 * i) for i in range(4)]
        n = name.lstrip("_")
        eax, fres = 0, None
        dbl = lambda i: struct.unpack("<d", struct.pack("<II", w[i], w[i + 1]))[0]
        if n in ("memcpy", "memmove"):
            self._mem(w[0], w[2], self._mem(w[1], w[2])) if w[2] else None
            eax = w[0]
        elif n == "memset":
            if w[2]:
                self._mem(w[0], w[2], bytes([w[1] & 0xFF]) * w[2])
            eax = w[0]
        elif n == "strlen":
            eax = len(self._cstr(w[0]))
        elif n in ("strcmp", "stricmp", "_stricmp", "strcmpi", "strncmp", "strnicmp", "_strnicmp"):
            a_, b_ = self._cstr(w[0]), self._cstr(w[1])
            if n in ("strncmp", "strnicmp", "_strnicmp"):
                a_, b_ = a_[:w[2]], b_[:w[2]]
            if n in ("stricmp", "_stricmp", "strcmpi", "strnicmp", "_strnicmp"):
                a_, b_ = a_.lower(), b_.lower()
            eax = 0 if a_ == b_ else (M32 if a_ < b_ else 1)
        elif n in ("strcpy", "strcat"):
            s_ = self._cstr(w[1]) + b"\0"
            dst = w[0] + (len(self._cstr(w[0])) if n == "strcat" else 0)
            self._mem(dst, len(s_), s_)
            eax = w[0]
        elif n in MATH1 or n in MATH2:
            x = dbl(0)
            try:
                fres = MATH1[n](x) if n in MATH1 else MATH2[n](x, dbl(2))
            except OverflowError:
                fres = float("inf")
            except (ValueError, ZeroDivisionError):
                fres = float("-inf") if n in ("log", "log10") and x == 0 else X87_NAN
        elif n in ("ReadWriteBarrier", "_ReadWriteBarrier"):
            pass
        else:
            raise Fault("intrinsic_unknown")
        uc = self.uc
        uc.reg_write(u.UC_X86_REG_EAX, eax & M32)
        if not tail:
            esp -= 4
            uc.mem_write(esp, struct.pack("<I", insn.addr + insn.size))
            uc.reg_write(u.UC_X86_REG_ESP, esp)
        if fres is not None:
            uc.mem_write(FSLOT, struct.pack("<d", fres))
            uc.reg_write(u.UC_X86_REG_EIP, TRAMP + 0x400)
        else:
            uc.reg_write(u.UC_X86_REG_EIP, TRAMP)

    def _stub(self, insn, target, tail):
        u = self.u
        uc = self.uc
        esp = self.reg("esp")
        # Callee facts only for real call sites: a target read from fuzzed memory is just a number.
        known = insn.target is not None or (insn.mem is not None and insn.mem[1] is None and insn.mem[2] is None)
        p = self.prog.callee_pop(target) if known else None
        if tail:
            argbase = esp + 4
            if p is None:
                p = 4 * len(self.inp.get("own_args", [])) if self.inp.get("own_pop") is None else self.inp["own_pop"]
            nargs = p // 4 if p else len(self.inp.get("own_args", []))
        else:
            argbase = esp
            cleanup = self.view.cleanup_after(insn.addr)
            tracked = sorted(s for s in self.tracked if s >= esp)
            semantic = self.prog.callee_stack_args(target) if known else None
            if p is not None and p > 0:
                nargs = p // 4
            elif p == 0 or cleanup:
                p = 0
                if cleanup:
                    nargs = min(cleanup // 4, len(tracked)) if tracked else cleanup // 4
                else:
                    nargs = len(tracked)
            else:
                nargs = len(tracked)
                p = 4 * nargs
                # a virtual call: reuse what the original's call through the same vtable slot did, so
                # that argument pushes interleaved with an outer call in our code don't change the count
                slot = insn.mem[4] if insn.mem is not None and insn.mem[1] not in (None, "esp", "ebp") \
                    and not insn.mem[2] else None
                if slot is not None and self.slot_arity is not None:
                    if self.coverage:               # the original's run
                        self.slot_arity.setdefault(slot, (p, nargs))
                    elif slot in self.slot_arity:
                        p, nargs = self.slot_arity[slot]
            self.tracked -= set(tracked[:nargs])
            if semantic is not None and p is not None:
                nargs = semantic          # compare what the callee actually reads
        args = []
        for k in range(min(nargs, 32)):
            a = argbase + 4 * k
            v = self._read_u32(a)
            args.append((v, self.stack_fpu.get(a)))
        k = len(self.calls)
        # locals passed by pointer: the callee may read them, so their contents are part of the call
        # our frame, including the incoming argument slots (MSVC reuses dead parameters as locals)
        arg_hi = ENTRY_ESP + 4 + 4 * len(self.inp["stack"])
        in_frame = lambda v: esp <= v < ENTRY_ESP or ENTRY_ESP + 4 <= v < arg_hi
        sp = sorted({v for v, _ in args if in_frame(v)})
        declared = self.pointee_sizes.get(target, {})
        argidx = {}
        for j, (v, _) in enumerate(args):
            argidx.setdefault(v, j)
        pointees = {}
        for n, v in enumerate(sp):
            size = declared.get(argidx.get(v), DEFAULT_POINTEE)
            limit = min([POINTEE_WINDOW, (ENTRY_ESP if v < ENTRY_ESP else arg_hi) - v] +
                        [x - v for x in self.save_slots if x > v])
            # extent: the declared size, grown over words the function itself wrote (an array or struct it
            # filled in, even when the parameter type is a scalar pointer); a callee's out-param writes
            # don't count, so neighbouring out-parameters stay out
            ext = 0
            while ext + 4 <= limit and any(x in self.func_stack_written for x in range(v + ext, v + ext + 4)):
                ext += 4
            pointees[v] = (bytes(self.uc.mem_read(v, limit)),
                           {a - v: sz for a, sz in self.stack_fpu.items() if v <= a < v + limit},
                           {a - v for a in range(v, v + limit) if a in self.stack_written},
                           min(limit, max(size, ext)))
        fret = self.view.float_ret_after(insn.addr, self.own_float_ret)
        h = mix(self.inp["seed"], 0xCA11, k)
        d = self.inp.get("dictionary")
        mode = self.inp.get("stub_mode")
        if mode == "zero":
            eax = 0
        elif mode == "one":
            eax = 1
        else:
            eax = d[(h >> 8) % len(d)] if d and h & 1 else fuzz_value(h)
        edx = fuzz_value(mix(self.inp["seed"], 0xCA12, k))
        fv = FLOATS[mix(self.inp["seed"], 0xCA13, k) % len(FLOATS)]
        self.calls.append({"target": target, "args": args, "regs": {r: self.reg(r) for r in Program._REGS},
                           "float_ret": fret, "at": insn.addr, "tail": tail, "pointees": pointees, "known": known,
                           "via_object": insn.mem is not None and insn.mem[1] not in (None, "esp", "ebp")
                           and insn.mem[2] is None})
        self._close_segment()
        self._perturb()
        if not tail:
            # out-parameters: the callee writes the first word of any local it got a pointer to
            for j, (v, _) in enumerate(args):
                if in_frame(v) and v % 4 == 0:
                    uc.mem_write(v, struct.pack("<I", fuzz_value(mix(self.inp["seed"], 0x0B7, k, j))))
                    self.stack_written.update(range(v, v + 4))
        uc.reg_write(u.UC_X86_REG_EAX, eax)
        uc.reg_write(u.UC_X86_REG_EDX, edx)
        uc.reg_write(u.UC_X86_REG_ECX, fuzz_value(mix(self.inp["seed"], 0xCA14, k)))
        if not tail:
            esp -= 4
            uc.mem_write(esp, struct.pack("<I", insn.addr + insn.size))
            uc.reg_write(u.UC_X86_REG_ESP, esp)
        if p > 0xFC or p % 4:
            raise Fault("odd_pop_%d" % p)
        if fret:
            uc.mem_write(FSLOT, struct.pack("<f", fv))
        uc.reg_write(u.UC_X86_REG_EIP, TRAMP + (0x800 if fret else 0) + (p // 4) * 16)

    def _observe(self, insn):
        """Track where registers were loaded from and what each cmp/test compared (for directed inputs)."""
        m = insn.mnemonic
        ops = insn.ops
        if insn.kind == "jcc" or (m.startswith("set") and insn.kind == "other"):
            if self.last_cmp is not None and insn.addr not in self.cmp_obs:
                self.cmp_obs[insn.addr] = self.last_cmp
            if insn.kind == "jcc":
                return
        if m in ("cmp", "test") and ops:
            info = []
            for kind, v in ops:
                if kind == "reg":
                    r32 = Program._ALIAS.get(v, v)
                    try:
                        val = self.reg(v)
                    except Exception:
                        val = 0
                    src = self.loads.get(r32)
                    info.append({"val": val, "src": src[:3] if src and src[3] == v else None, "reg": v})
                elif kind == "mem":
                    ea = self._ea(v)
                    try:
                        val = int.from_bytes(self.uc.mem_read(ea, v[5]), "little")
                    except Exception:
                        val = 0
                    info.append({"val": val, "src": (ea, v[5], self.epoch)})
                else:
                    info.append({"val": v, "src": None, "imm": v})
            if len(info) == 2 and info[0].get("reg") and info[0].get("reg") == info[1].get("reg"):
                info[1]["same"] = True
            self.last_cmp = {"addr": insn.addr, "mnemonic": m, "ops": info}
            return
        if m in ("mov", "movzx", "movsx") and len(ops) == 2 and ops[0][0] == "reg" and ops[1][0] == "mem":
            r = ops[0][1]
            size = ops[1][1][5]
            self.loads[Program._ALIAS.get(r, r)] = (self._ea(ops[1][1]), size, self.epoch, r)
        elif ops and ops[0][0] == "reg" and m not in ("push",):
            self.loads.pop(Program._ALIAS.get(ops[0][1], ops[0][1]), None)
        if insn.kind == "call":
            for r in ("eax", "ecx", "edx"):
                self.loads.pop(r, None)

    def _on_code(self, uc, addr, size, _):
        try:
            if TRAMP <= addr < TRAMP + PAGE:
                return
            if self.helper_ret is not None:
                if addr != self.helper_ret:
                    return
                self.helper_ret = None
            insn = self.view.decode(addr)
            self.cur_insn = insn
            if insn is None:
                raise Fault("undecodable")
            if self.coverage is not None:
                self.executed.add(addr)
                if self.prev_jcc is not None:
                    self.edges.add((self.prev_jcc, addr))
                self.prev_jcc = addr if insn.kind == "jcc" or addr in self.view.tables else None
                if self.prev_set is not None:
                    pa, pr = self.prev_set
                    try:
                        self.edges.add((pa, "set%d" % (self.reg(pr) & 1)))
                    except Exception:
                        pass
                    self.prev_set = None
                if insn.mnemonic.startswith("set") and insn.regs:
                    self.prev_set = (addr, insn.regs[0])
                self._observe(insn)
            esp = self.reg("esp")
            if self.tracked:
                self.tracked = {t for t in self.tracked if t >= esp}
            m = insn.mnemonic
            if m == "push":
                if insn.regs and insn.regs[0] in CALLEE_SAVED and self.reg(insn.regs[0]) == self.inp["regs"][insn.regs[0]]:
                    self.save_slots.add(esp - 4)
                elif addr not in self.prologue:
                    self.tracked.add(esp - 4)
            elif m == "sub" and insn.op_str.startswith("esp,") and insn.imms and addr not in self.prologue \
                    and insn.imms[0] <= 64:
                self.tracked.update(range(esp - insn.imms[0], esp, 4))
            if insn.kind == "call":
                if insn.target is not None:
                    target = insn.target
                elif insn.mem is not None:
                    target = self._read_u32(self._ea(insn.mem))
                else:
                    target = self.reg(insn.regs[0])
                if target in self.helpers:
                    self.helper_ret = addr + size
                    return
                if self.view.in_body(target) and target != self.view.entry:
                    return
                direct = insn.target is not None      # a relocated call, not a pointer from fuzzed memory
                if direct and self.local_code and self.local_code[0] <= target < self.local_code[1]:
                    return            # a function of our own object: executes in place, like inlined code
                if direct and target in self.intrinsics:
                    self._intrinsic(insn, self.intrinsics[target], tail=False)
                    return
                self._stub(insn, target, tail=False)
            elif insn.kind == "jmp":
                if insn.target is not None:
                    target = insn.target
                    if self.view.internal_target(target) and target != self.view.entry:
                        return
                elif insn.mem is not None:
                    if addr in self.view.tables:
                        return
                    target = self._read_u32(self._ea(insn.mem))
                    if self.view.internal_target(target):
                        return
                else:
                    target = self.reg(insn.regs[0])
                    if self.view.internal_target(target):
                        return
                direct = insn.target is not None
                if direct and self.local_code and self.local_code[0] <= target < self.local_code[1]:
                    return
                if direct and target in self.intrinsics:
                    self._intrinsic(insn, self.intrinsics[target], tail=True)
                    return
                self._stub(insn, target, tail=True)
        except Fault as e:
            self.fault = self.fault or (str(e), addr)
            uc.emu_stop()
        except Exception as e:  # never let a hook exception escape silently
            self.fault = self.fault or ("hook_error:" + repr(e)[:80], addr)
            uc.emu_stop()

    # -- run -----------------------------------------------------------------------------------
    def run(self, entry):
        from unicorn import UcError
        self._setup()
        err = None
        try:
            self.uc.emu_start(entry, SENTINEL, count=self.max_steps)
        except UcError as e:
            err = str(e)
        eip = self.reg("eip")
        out = {"status": "ret"}
        if self.fault:
            out["status"] = "fault:" + self.fault[0]
            out["fault_at"] = self.fault[1]
        elif err:
            out["status"] = "fault:" + err.split("(")[0].strip().replace(" ", "_")
            out["fault_at"] = eip
        elif eip != SENTINEL:
            out["status"] = "timeout"
        self._close_segment()
        u = self.u
        out["eax"] = self.reg("eax")
        out["edx"] = self.reg("edx")
        out["esp"] = self.reg("esp")
        out["saved"] = {r: self.reg(r) for r in CALLEE_SAVED}
        fpsw = self.uc.reg_read(u.UC_X86_REG_FPSW)
        top = (fpsw >> 11) & 7
        out["fdepth"] = (8 - top) % 8
        out["st0"] = _x87_value(self.uc.reg_read(u.UC_X86_REG_FP0 + top)) if out["fdepth"] else None
        out["calls"] = self.calls
        out["segments"] = self.segments
        out["seg_fpu"] = self.seg_fpu
        out["epochs"] = self.epoch
        return out


# ---------------------------------------------------------------------------------------------
# Linking our object at OURS, with externals bound to original addresses.
def _normkey(i):
    if i.kind in ("call", "jmp", "jcc"):
        return i.mnemonic + (" ind" if i.target is None else "")
    return re.sub(r"0x[0-9a-f]{5,}", "ADDR", "%s %s" % (i.mnemonic, i.op_str))


class Ours:
    """Our compiled object, laid out at OURS. Symbol addresses come from `resolved` or the layout."""

    def __init__(self, obj, func_sym):
        self.obj = obj
        self.func_sym = func_sym
        self.sec_addr = {}
        cur = OURS
        for i, s in enumerate(obj.sections, 1):
            if _linkable(s):
                cur = (cur + 15) & ~15
                self.sec_addr[i] = cur
                cur += s["size"]
        self.end = cur
        secnum, value, end = obj.func_extent(func_sym)
        raw = obj.sections[secnum - 1]["raw"] or b""
        body = strip_padding(raw[value:end])
        self.func_addr = self.sec_addr[secnum] + value
        self.func_len = len(body)
        self.func_secnum = secnum
        self.func_off = value
        # relocations inside our function: (offset, symbol name, type, addend)
        self.relocs = []
        sec = obj.sections[secnum - 1]
        for va, si, typ in sec["relocs"]:
            if value <= va < value + max(self.func_len, 1) + 0:
                sym = obj.syms.get(si)
                addend, = struct.unpack_from("<i", raw, va)
                self.relocs.append((va - value, sym, typ, addend))
        self.image = None
        self.unresolved_used = []

    def local_relocs(self):
        """[(offset, sym, type, addend)] of functions defined in our object that our function reaches."""
        out, seen = [], {self.func_sym[0]}
        work = [s for _, s, _, _ in self.relocs if s is not None and s[2] > 0 and s[3] == 0x20]
        while work:
            fs = work.pop()
            if fs[0] in seen:
                continue
            seen.add(fs[0])
            secnum, value, end = self.obj.func_extent(fs)
            sec = self.obj.sections[secnum - 1]
            raw = sec["raw"] or b""
            for va, si, typ in sec["relocs"]:
                if value <= va < end:
                    sym = self.obj.syms.get(si)
                    if sym is None or (sym[2] == secnum and not sym[0].startswith(("?", "_"))):
                        continue
                    out.append((va - value, sym, typ, struct.unpack_from("<i", raw, va)[0]))
                    if sym[2] > 0 and sym[3] == 0x20:
                        work.append(sym)
        return out

    def sym_local_addr(self, sym):
        name, value, secnum, _, _ = sym
        if secnum > 0 and secnum in self.sec_addr:
            return self.sec_addr[secnum] + value
        return None

    def link(self, resolved):
        img = bytearray(self.end - OURS)
        poison = {}
        for i, s in self.sec_addr.items():
            sec = self.obj.sections[i - 1]
            if sec["raw"]:
                img[s - OURS:s - OURS + sec["size"]] = sec["raw"]
        for i, s in self.sec_addr.items():
            sec = self.obj.sections[i - 1]
            for va, si, typ in sec["relocs"]:
                sym = self.obj.syms.get(si)
                if sym is None:
                    continue
                name = sym[0]
                if name in resolved and sym != self.func_sym:
                    S = resolved[name]
                else:
                    S = self.sym_local_addr(sym)
                    if S is None:
                        S = poison.setdefault(name, POISON + 16 * len(poison))
                P = s + va
                o = P - OURS
                A, = struct.unpack_from("<I", img, o)
                if typ == DIR32:
                    v = A + S
                elif typ == REL32:
                    v = A + S - (P + 4)
                elif typ == 0x07:      # DIR32NB
                    v = A + S - OURS
                else:
                    continue
                struct.pack_into("<I", img, o, v & M32)
        self.image = bytes(img)
        self.poison = {v: k for k, v in poison.items()}
        return self

    def bytes_at(self, addr, resolved):
        """Our function's bytes as if linked at the original address (for a byte-identity check)."""
        sec = self.obj.sections[self.func_secnum - 1]
        raw = bytearray(sec["raw"][self.func_off:self.func_off + self.func_len])
        for va, si, typ in sec["relocs"]:
            off = va - self.func_off
            if not 0 <= off <= len(raw) - 4:
                continue
            sym = self.obj.syms.get(si)
            if sym is None:
                continue
            if sym == self.func_sym:
                S = addr
            elif sym[0] in resolved:
                S = resolved[sym[0]]
            elif sym[2] == self.func_secnum:
                S = addr + sym[1] - self.func_off
            else:
                S = self.sym_local_addr(sym) or POISON
            A, = struct.unpack_from("<I", raw, off)
            if typ == DIR32:
                v = A + S
            elif typ == REL32:
                v = A + S - (addr + off + 4)
            else:
                continue
            struct.pack_into("<I", raw, off, v & M32)
        return bytes(raw)

    def read(self, va, n):
        if OURS <= va < self.end:
            o = va - OURS
            b = self.image[o:o + n]
            return b + b"\0" * (n - len(b))
        return Program.get().read(va, n)


# ---------------------------------------------------------------------------------------------
# References and symbol resolution (level 2).
def _in_image(v):
    return IMAGE_LO <= v < IMAGE_HI


def original_refs(prog, view, size):
    """Original references: [(insn addr, kind, target)]; kinds call / data / imm / float."""
    body = (view.entry, view.entry + size)
    out = []
    for a in sorted(view.insns):
        i = view.insns[a]
        if i.kind in ("call", "jmp") and i.target is not None:
            if not view.internal_target(i.target) or (i.kind == "call" and i.target == view.entry):
                out.append((a, "call", i.target))
            continue
        if i.kind == "jcc":
            continue
        if i.mem is not None:
            seg, base, index, scale, disp, msize = i.mem
            if _in_image(disp) and not (body[0] <= disp < body[1]) and a not in view.tables:
                if base and base != "esp":
                    kind = "imm"          # [reg + 0x1e820] may be a struct offset, not an address
                else:
                    kind = "float" if i.mnemonic.startswith("f") and not index else "data"
                out.append((a, kind, disp))
        for v in i.imms:
            if _in_image(v) and not (body[0] <= v < body[1]) and i.kind not in ("call", "jmp"):
                out.append((a, "imm", v))
    return out


def _qualified(mangled):
    """'?vfunc_5@CAction@@QAEXXZ' -> 'CAction::vfunc_5' (None for special names)."""
    if not mangled.startswith("?") or mangled.startswith("??"):
        return None
    try:
        p = _Parser(mangled[1:])
        return p.qualified_name()
    except (DemangleError, IndexError):
        return None


HEX_NAME = re.compile(r"(?:FUN|DAT|PTR|LAB|SUB|UNK|BYTE|WORD|DWORD|FLOAT|thunk_FUN|g|s|data|func)_(?:0x)?([0-9a-fA-F]{8})(?![0-9a-fA-F])")


def name_address(prog, name):
    """An original address encoded in, or looked up by, a symbol name; None if the name says nothing."""
    if name in BUILTIN_NAMES:
        return BUILTIN_NAMES[name], "builtin"
    crt = crt_table(prog)
    if name in crt:
        return crt[name], "crt"
    q = _qualified(name)
    base = q or re.sub(r"^[_@]|@\d+$", "", name)
    if len(prog.names.get(base, [])) == 1:          # exact Ghidra/RTTI name (thunk_FUN_x is not FUN_x)
        return prog.names[base][0], "name"
    m = HEX_NAME.search(base.split("::")[-1])
    if m:
        return int(m.group(1), 16), "name"
    if not q and base in prog.xbsyms:
        return prog.xbsyms[base], "xdk"
    return None


def literal_bytes(obj, sym):
    _, value, secnum, _, _ = sym
    if secnum <= 0:
        return None
    raw = obj.sections[secnum - 1]["raw"] or b""
    if sym[0].startswith("??_C@_1"):      # wide string: up to a 00 00 pair
        k = value
        while k + 1 < len(raw) and raw[k:k + 2] != b"\0\0":
            k += 2
        return raw[value:k + 2]
    end = raw.find(b"\0", value)
    return raw[value:end + 1] if end >= 0 else raw[value:]


def resolve_symbols(prog, ours, oview, orefs, explicit=None, use_names=True):
    """Map each external/data symbol our function uses to an original address.

    Order: explicit map > content (strings, floats, vftables) > names > alignment with the original.
    Returns (resolved {name: addr}, how {name: method}, conflicts [..]).
    """
    explicit = explicit or {}
    resolved, how, conflicts = {}, {}, []
    by_target = defaultdict(set)
    for a, k, t in orefs:
        by_target[t].add(k)
    # pairing by alignment: our reloc site -> original value at the same spot
    pair_votes = defaultdict(Counter)
    oinsns = [oview.insns[a] for a in sorted(oview.insns)]
    our_view = CodeView(ours.read, ours.func_addr, (ours.func_addr, ours.func_addr + ours.func_len), prog,
                        is_ours=True).build()
    rinsns = [our_view.insns[a] for a in sorted(our_view.insns)]
    import difflib
    sm = difflib.SequenceMatcher(None, [_normkey(i) for i in oinsns], [_normkey(i) for i in rinsns],
                                 autojunk=False)
    pairs = []
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == "equal" or (op == "replace" and i2 - i1 == j2 - j1):
            pairs.extend(zip(oinsns[i1:i2], rinsns[j1:j2]))
    rel_at = {}
    for off, sym, typ, addend in ours.relocs:
        rel_at[ours.func_addr + off] = (sym, typ, addend)
    for oi, ri in pairs:
        if oi.size != ri.size or oi.mnemonic != ri.mnemonic:
            continue
        for k in range(ri.size - 3):
            site = ri.addr + k
            if site not in rel_at:
                continue
            sym, typ, addend = rel_at[site]
            if sym is None:
                continue
            orig = prog.u32(oi.addr + k)
            if typ == REL32:
                t = (oi.addr + k + 4 + struct.unpack("<i", struct.pack("<I", orig))[0] - addend) & M32
            elif typ == DIR32:
                t = (orig - addend) & M32
            else:
                continue
            pair_votes[sym[0]][t] += 1
    exact = len(oinsns) == len(rinsns) and all(_normkey(a) == _normkey(b) and a.size == b.size
                                               for a, b in zip(oinsns, rinsns))
    oaddrs = {t for _, _, t in orefs}
    syms = []
    for off, sym, typ, addend in ours.relocs:
        if sym is None or sym == ours.func_sym:
            continue
        if sym[2] == ours.func_secnum and not sym[0].startswith("?") and not sym[0].startswith("_"):
            continue      # local labels / own section (switch tables)
        if sym[0] not in [s[0] for s in syms]:
            syms.append(sym)
    # symbols used only by our own helper functions (code the original inlined): no pairing for those
    for off, sym, typ, addend in ours.local_relocs():
        if sym[0] not in [s[0] for s in syms] and sym != ours.func_sym:
            syms.append(sym)
    for sym in syms:
        name = sym[0]
        cand = None
        if name in explicit:
            cand = (explicit[name], "explicit")
        elif name.startswith("??_C@"):
            lit = literal_bytes(ours.obj, sym)
            hits = sorted((t for t in oaddrs if lit and prog.read(t, len(lit)) == lit),
                          key=lambda t: (t not in pair_votes.get(name, {}), prog.section_name(t) != ".rdata", t))
            cand = (hits[0], "string") if hits else None
            if cand is None:
                cand = (None, "string_not_in_original")
        elif name.startswith("__real@"):
            want = bytes.fromhex(name[len("__real@"):])[::-1]
            hits = sorted((t for t in oaddrs if prog.read(t, len(want)) == want),
                          key=lambda t: (t not in pair_votes.get(name, {}), prog.section_name(t) != ".rdata", t))
            cand = (hits[0], "float") if hits else (None, "float_local")
        elif name.startswith("??_7"):
            cls = name[len("??_7"):].split("@6B")[0]
            hits = [a for a, m in prog.vftables.items() if m in (".?AV" + cls + "@", ".?AU" + cls + "@")]
            hits_ref = [h for h in hits if h in oaddrs]
            if hits_ref or len(hits) == 1:
                cand = ((hits_ref or hits)[0], "vftable")
        if cand is None and use_names:
            na = name_address(prog, name)
            if na:
                cand = na
        votes = pair_votes.get(name)
        if cand is None and sym[2] > 0 and sym[3] == 0x20:
            votes = None      # a function defined in our object (e.g. not inlined here): it runs in place
        if name in INTRINSIC_NAMES and cand is None:
            votes = None      # a CRT routine the XBE doesn't have out of line: runs semantically
        if votes:
            t, n = votes.most_common(1)[0]
            if cand is not None and cand[0] is not None and cand[0] != t and cand[1] not in ("string", "float"):
                conflicts.append({"symbol": name, "claimed": "0x%08x" % cand[0], "code": "0x%08x" % t,
                                  "how": cand[1]})
                if exact and cand[1] != "explicit":
                    cand = (t, "paired")
            if cand is None:
                cand = (t, "paired")
            if len(votes) > 1:
                conflicts.append({"symbol": name, "inconsistent": ["0x%08x" % v for v in votes]})
        if cand is not None and cand[0] is not None:
            resolved[name] = cand[0]
        how[name] = cand[1] if cand else "unresolved"
    # order-based fallback for whatever is still unresolved
    left = [s for s in syms if s[0] not in resolved and how[s[0]] == "unresolved"]
    if left:
        claimed = set(resolved.values())
        rel_kind = {}
        for off, sym, typ, addend in ours.relocs:
            if sym is not None:
                rel_kind.setdefault(sym[0], "call" if typ == REL32 else "data")
        for kind in ("call", "data"):
            ls = [s[0] for s in left if rel_kind.get(s[0]) == kind and s[0] not in INTRINSIC_NAMES
                  and not (s[2] > 0 and s[3] == 0x20)]
            os_ = []
            for a, k, t in orefs:
                kk = "call" if k == "call" else "data"
                if kk == kind and t not in claimed and t not in os_:
                    os_.append(t)
            if ls and len(ls) == len(os_):
                for n, t in zip(ls, os_):
                    resolved[n] = t
                    how[n] = "ordered"
    return resolved, how, conflicts, exact


def our_refs(ours, resolved, rview):
    """Our references after resolution: [(kind, addr or None, symbol)] plus plain immediates."""
    out = []
    rel_sites = set()
    for k, (off, sym, typ, addend) in enumerate(ours.relocs + ours.local_relocs()):
        if sym is None or sym == ours.func_sym:
            continue
        if k < len(ours.relocs):
            rel_sites.update(range(ours.func_addr + off, ours.func_addr + off + 4))
        if sym[2] > 0 and sym[3] == 0x20 and sym[0] not in resolved:
            continue          # our own helper function: it runs in place, its references count instead
        name = sym[0]
        if name in resolved:
            t = resolved[name]
        else:
            loc = ours.sym_local_addr(sym)
            if loc is not None and sym[2] == ours.func_secnum:
                continue          # own section: jump tables, local labels
            t = None
        kind = "call" if typ == REL32 else "data"
        out.append((kind, t if t is None else (t + (addend if typ == DIR32 else 0)) & M32, name))
    imms = set()
    for a, i in rview.insns.items():
        if any(s in rel_sites for s in range(a, a + i.size)):
            continue
        imms.update(i.imms)
        if i.mem is not None:
            imms.add(i.mem[4])
    return out, imms


def level2(prog, orefs, oview, ours, resolved, how, rview):
    refs, imms = our_refs(ours, resolved, rview)
    issues = []
    o_calls = {t for _, k, t in orefs if k == "call"}
    o_data = {t for _, k, t in orefs if k == "data"}
    o_float = {t for _, k, t in orefs if k == "float"}
    o_imm = {t for _, k, t in orefs if k == "imm"}
    r_calls = {t for k, t, _ in refs if k == "call" and t is not None}
    r_data = {t for k, t, _ in refs if k == "data" and t is not None}

    def near_ours(t):        # the middle of something we reference (a string read in pieces, a struct field)
        return any(0 < abs(t - x) < 16 for x in r_data)
    for k, t, n in refs:
        if t is None:
            if n in INTRINSIC_NAMES:
                issues.append({"kind": "intrinsic_call", "symbol": n})       # executed semantically in level 3
            elif n.startswith("__real@"):
                issues.append({"kind": "float_constant_not_in_original", "symbol": n})
            else:
                issues.append({"kind": "unresolved_symbol", "symbol": n, "how": how.get(n)})
    for t in sorted(o_calls - r_calls):
        issues.append({"kind": "missing_call", "target": "0x%08x" % t, "name": prog.funcs.get(t, (0, None))[1]})
    for t in sorted(r_calls - o_calls):
        n = [x for k, tt, x in refs if tt == t]
        issues.append({"kind": "extra_call", "target": "0x%08x" % t, "symbol": n[0] if n else None})
    for t in sorted(o_data - r_data):
        kind = "missing_data_ref_interior" if near_ours(t) else "missing_data_ref"
        issues.append({"kind": kind, "target": "0x%08x" % t, "section": prog.section_name(t)})
    for t in sorted(o_float - r_data):
        issues.append({"kind": "missing_float_constant", "target": "0x%08x" % t})
    for t in sorted(r_data - o_data - o_float - o_imm):
        n = [x for k, tt, x in refs if tt == t]
        interior = any(0 < abs(t - x) < 16 for x in o_data | o_imm)     # e.g. one byte of a global
        issues.append({"kind": "extra_data_ref_interior" if interior else "extra_data_ref",
                       "target": "0x%08x" % t, "symbol": n[0] if n else None})
    for t in sorted(o_imm - r_data - imms - o_data):
        issues.append({"kind": "missing_address_constant", "target": "0x%08x" % t, "section": prog.section_name(t)})
    return issues


# ---------------------------------------------------------------------------------------------
# Level 3 driver.
def make_input(seed, sig, prog_globals, ptr_pool=(), int_pool=()):
    kinds = []
    cc = sig.get("cc") if sig else None
    params = (sig or {}).get("params")
    if sig and sig.get("ret") == "struct":
        kinds.append("ptr")
    if params:
        kinds.extend(params)
    words, words_kind = [], []
    for i, k in enumerate(kinds):
        h = mix(seed, 0xA4, i)
        if k == "f64":
            d = FLOATS[h % len(FLOATS)] * (1 if (h >> 8) & 3 else 3.7)
            lo, hi = struct.unpack("<II", struct.pack("<d", d))
            words += [lo, hi]
            words_kind += ["f64", "f64"]
        elif k == "i64":
            words += [fuzz_value(h, "i32"), 0 if h & 0x100 else M32 * ((h >> 9) & 1)]
            words_kind += ["i64", "i64"]
        elif k == "struct":
            words += [fuzz_value(mix(h, j)) for j in range(4)]
            words_kind += ["any"] * 4
        elif k in ("i32", "i16", "i8") and int_pool and h & 0x100:
            words.append(int_pool[(h >> 9) % len(int_pool)])          # boundary values from the code
            words_kind.append(k)
        elif k == "ptr" and ptr_pool and seed % 3 == 2 and h & 0x100:
            words.append(ptr_pool[(h >> 9) % len(ptr_pool)])         # e.g. a string the code compares with
            words_kind.append(k)
        elif k == "ptr" and seed % 5 == 3:
            words.append(HEAP + (h & 0x1FC))                            # narrow mode: within 512 bytes
            words_kind.append(k)
        elif k == "ptr" and seed % 4 == 1:
            words.append(HEAP + 0x20000 + 0x40 * i + 4 * (h % 8))     # nearby, ascending pointers
            words_kind.append(k)
        else:
            words.append(fuzz_value(h, k) if not (seed == 0 and k == "ptr") else HEAP + 0x1000 * (i + 1))
            words_kind.append(k)
    regs = {}
    for j, r in enumerate(("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp")):
        regs[r] = HEAP + ((mix(seed, 0x4E6, j) % HEAP_SIZE) & ~0xF) if seed else HEAP + 0x10000 * (j + 1)
        if seed % 5 == 3 and r in ("ecx", "edx"):
            regs[r] = HEAP + (mix(seed, 0x4E6, j) & 0x1F0)
    own_args = list(words)
    if cc == "fastcall" and params is not None:
        if words:
            regs["ecx"] = words.pop(0)
        if words:
            regs["edx"] = words.pop(0)
    stack = words + [fuzz_value(mix(seed, 0xA5, i)) for i in range(16)]
    own_pop = None
    if sig and params is not None:
        own_pop = 0 if cc == "cdecl" else 4 * len(words)
    return {"seed": seed, "regs": regs, "stack": stack, "own_args": words, "own_pop": own_pop}


FTOL = (1e-5, 1e-6)


def _feq(a, b, rel=FTOL[0], ab=FTOL[1]):
    if a is None or b is None:
        return a is b
    if math.isnan(a) or math.isnan(b):
        return math.isnan(a) and math.isnan(b)
    if math.isinf(a) or math.isinf(b):
        return a == b
    return abs(a - b) <= max(ab, rel * max(abs(a), abs(b)))


def _norm(v):
    if STACK_LO <= v < STACK_HI:
        return "stack"
    return v


def _fmt(v):
    return v if isinstance(v, str) else "0x%08x" % v


class Namer:
    """Describe addresses relative to the input's pointers (this+0x40, arg2+8, global 0x...)."""

    def __init__(self, inp, sig, prog):
        self.bases = []
        if sig and sig.get("this"):
            self.bases.append(("this", inp["regs"]["ecx"]))
        for i, w in enumerate(inp["own_args"]):
            if HEAP <= w < HEAP + HEAP_SIZE:
                self.bases.append(("arg%d" % i, w))
        self.prog = prog

    def __call__(self, a):
        best = None
        for n, b in self.bases:
            if 0 <= a - b < 0x2000 and (best is None or a - b < best[1]):
                best = (n, a - b)
        if best:
            return "%s+0x%x" % best
        if IMAGE_LO <= a < IMAGE_HI:
            return "global 0x%08x" % a
        return "0x%08x" % a


def compare_runs(o, r, ret_kind, machine, namer, prog, max_report=4):
    """List of human-readable behaviour differences (empty = same)."""
    out = []
    if o["status"] != r["status"]:
        out.append("original %s but ours %s" % (o["status"], r["status"]))
        if r["status"] != "ret" and o["status"] == "ret":
            pass
    oc, rc = o["calls"], r["calls"]
    for k in range(max(len(oc), len(rc))):
        if k >= len(oc):
            out.append("extra call #%d to %s (original makes %d calls)" % (k + 1, _fmt(rc[k]["target"]), len(oc)))
            break
        if k >= len(rc):
            out.append("missing call #%d to %s (ours makes %d calls)" % (k + 1, _fmt(oc[k]["target"]), len(rc)))
            break
        a, b = oc[k], rc[k]
        if a["target"] != b["target"]:
            out.append("call #%d went to %s instead of %s" % (k + 1, _fmt(b["target"]), _fmt(a["target"])))
            break
        if a.get("float_ret") != b.get("float_ret"):
            pass
        oa, ra = a["args"], b["args"]
        if len(oa) != len(ra):
            out.append("call #%d to %s: %d argument words, expected %d" % (k + 1, _fmt(a["target"]), len(ra), len(oa)))
            break
        bad = False
        j = 0
        while j < len(oa):
            (ov, of), (rv, rf) = oa[j], ra[j]
            if _norm(ov) == _norm(rv):
                j += 1
                continue
            if of == 4 and rf == 4 and _feq(*struct.unpack("<ff", struct.pack("<II", ov, rv))):
                j += 1
                continue
            if of == 8 and rf == 8 and j + 1 < len(oa):
                od = struct.unpack("<d", struct.pack("<II", ov, oa[j + 1][0]))[0]
                rd = struct.unpack("<d", struct.pack("<II", rv, ra[j + 1][0]))[0]
                if _feq(od, rd):
                    j += 2
                    continue
            out.append("call #%d to %s: argument %d is %s, expected %s" % (
                k + 1, _fmt(a["target"]), j + 1, _fmt(_norm(rv)), _fmt(_norm(ov))))
            bad = True
            break
        if bad:
            break
        # contents of locals passed by pointer, matched by argument position
        for j, ((ov, _), (rv, _)) in enumerate(zip(oa, ra)):
            if ov in a.get("pointees", {}) and rv in b.get("pointees", {}):
                (ob, ofp, ow, oe), (rb, rfp, rw, re_) = a["pointees"][ov], b["pointees"][rv]
                n = max(oe, re_)
                off = _first_diff(ob[:n], rb[:n], ofp, rfp, ow | rw)
                if off is not None:
                    out.append("call #%d to %s: the local passed as argument %d differs at +0x%x (%s, expected %s)" % (
                        k + 1, _fmt(a["target"]), j + 1, off, _desc(struct.unpack_from("<I", rb.ljust(off + 4, b"\0"), off & ~3)[0]),
                        _desc(struct.unpack_from("<I", ob.ljust(off + 4, b"\0"), off & ~3)[0])))
                    bad = True
                    break
        if bad:
            break
        # register inputs of the callee: this (ecx), fastcall/LTCG register arguments
        want = prog.reg_inputs(a["target"]) if a["target"] in prog.funcs and a.get("known") else None
        if want is None:
            want = {"ecx"} if a.get("via_object") or b.get("via_object") else set()
        bad_reg = None
        for reg in sorted(want):
            if _norm(a["regs"][reg]) != _norm(b["regs"][reg]):
                bad_reg = reg
                break
        if bad_reg:
            label = "this (ecx)" if bad_reg == "ecx" else bad_reg
            out.append("call #%d to %s: %s is %s, expected %s" % (
                k + 1, _fmt(a["target"]), label, _fmt(_norm(b["regs"][bad_reg])), _fmt(_norm(a["regs"][bad_reg]))))
            break
    nseg = min(len(o["segments"]), len(r["segments"]))
    if o["status"] != "ret" or r["status"] != "ret":
        nseg -= 1
    for s in range(max(0, nseg)):
        os_, rs = o["segments"][s], r["segments"][s]
        addrs = set(os_) | set(rs)
        if not addrs:
            continue
        diffs = []
        for a in sorted(addrs):
            ov = os_[a] if a in os_ else machine.byte(a, s)
            rv = rs[a] if a in rs else machine.byte(a, s)
            if ov != rv:
                diffs.append(a)
        if not diffs:
            continue
        ofpu, rfpu = o["seg_fpu"][s], r["seg_fpu"][s]
        real = []
        done = set()
        for a in diffs:
            if a in done:
                continue
            ok = False
            for base in range(a - 7, a + 1):
                sz = ofpu.get(base)
                if sz and rfpu.get(base) == sz and base <= a < base + sz:
                    fmt = "<f" if sz == 4 else "<d"
                    ob = bytes(os_.get(base + i, machine.byte(base + i, s)) for i in range(sz))
                    rb = bytes(rs.get(base + i, machine.byte(base + i, s)) for i in range(sz))
                    if _feq(struct.unpack(fmt, ob)[0], struct.unpack(fmt, rb)[0]):
                        ok = True
                        done.update(range(base, base + sz))
                    break
            if not ok:
                real.append(a)
        if real:
            a = real[0]
            base = a & ~3
            ob = bytes(os_.get(base + i, machine.byte(base + i, s)) for i in range(4))
            rb = bytes(rs.get(base + i, machine.byte(base + i, s)) for i in range(4))
            where = "before call #%d" % (s + 1) if s < len(oc) else "before return"
            ow, rw = struct.unpack("<I", ob)[0], struct.unpack("<I", rb)[0]
            wrote_o, wrote_r = any(base + i in os_ for i in range(4)), any(base + i in rs for i in range(4))
            if wrote_o and not wrote_r:
                out.append("missing write to %s %s (expected %s)" % (namer(base), where, _desc(ow)))
            elif wrote_r and not wrote_o:
                out.append("unexpected write to %s %s (%s)" % (namer(base), where, _desc(rw)))
            else:
                out.append("write to %s %s was %s, expected %s" % (namer(base), where, _desc(rw), _desc(ow)))
            if len(real) > 4:
                out[-1] += " (+%d more bytes differ)" % (len(real) - 1)
            break
    if o["status"] == "ret" and r["status"] == "ret":
        if o["esp"] != r["esp"]:
            out.append("stack pointer after return differs by %d (callee pop count)" % (r["esp"] - o["esp"]))
        for reg in CALLEE_SAVED:
            if _norm(o["saved"][reg]) != _norm(r["saved"][reg]):
                out.append("%s not preserved the same way (%s vs %s)" % (reg, _fmt(_norm(r["saved"][reg])),
                                                                        _fmt(_norm(o["saved"][reg]))))
        rk = ret_kind
        if rk in ("f32", "f64"):
            if o["fdepth"] != r["fdepth"]:
                out.append("x87 stack depth at return %d, expected %d" % (r["fdepth"], o["fdepth"]))
            elif not _feq(o["st0"], r["st0"]):
                out.append("returned %r, expected %r" % (r["st0"], o["st0"]))
        else:
            if o["fdepth"] != r["fdepth"]:
                out.append("x87 stack depth at return %d, expected %d" % (r["fdepth"], o["fdepth"]))
            mask = {"i8": 0xFF, "b8": 0xFF, "i16": 0xFFFF}.get(rk, M32)
            if rk != "void":
                ov, rv = _norm(o["eax"] & mask), _norm(r["eax"] & mask)
                if ov != rv:
                    out.append("returned %s, expected %s%s" % (_fmt(rv), _fmt(ov),
                                                              "" if rk else " (return type unknown)"))
                if rk == "i64" and o["edx"] != r["edx"]:
                    out.append("returned high word %s, expected %s" % (_fmt(r["edx"]), _fmt(o["edx"])))
    return out[:max_report]


def _first_diff(ob, rb, ofp, rfp, written=None):
    """First differing byte offset of two pointee snapshots (x87 stores compare with tolerance), or None.

    Only bytes the function wrote (in either run) count: an uninitialised out-parameter is garbage."""
    n = min(len(ob), len(rb))
    skip = set()
    for off, sz in ofp.items():
        if rfp.get(off) == sz and off + sz <= n:
            fmt = "<f" if sz == 4 else "<d"
            if _feq(struct.unpack_from(fmt, ob, off)[0], struct.unpack_from(fmt, rb, off)[0]):
                skip.update(range(off, off + sz))
    for i in range(n):
        if ob[i] != rb[i] and i not in skip and (written is None or i in written):
            return i
    return None


def _desc(v):
    f = struct.unpack("<f", struct.pack("<I", v))[0]
    s = "0x%x" % v
    if v and 1e-6 < abs(f) < 1e9 and v not in range(HEAP, HEAP + HEAP_SIZE):
        s += " (%gf)" % f
    return s


_TC = {}


def _callee_is_thiscall(prog, target):
    if target not in _TC:
        name = prog.funcs.get(target, (0, ""))[1]
        _TC[target] = "::" in name and not name.startswith("FUN_")
    return _TC[target]


def coverage_of(view, edges):
    total, covered, missing = 0, 0, []
    for j in view.jcc:
        i = view.insns[j]
        for t, label in ((i.target, "taken"), (j + i.size, "not taken")):
            total += 1
            if (j, t) in edges:
                covered += 1
            else:
                missing.append("+0x%x %s" % (j - view.entry, label))
    for j in view.setcc:
        for v in (0, 1):
            total += 1
            if (j, "set%d" % v) in edges:
                covered += 1
            else:
                missing.append("+0x%x set%s %d" % (j - view.entry, view.insns[j].mnemonic[3:], v))
    for j, tg in view.tables.items():
        for t in sorted(set(tg)):
            total += 1
            if (j, t) in edges:
                covered += 1
            else:
                missing.append("+0x%x case ->+0x%x" % (j - view.entry, t - view.entry))
    return {"edges_total": total, "edges_covered": covered, "uncovered": missing[:20],
            "complete": covered == total}


# ---------------------------------------------------------------------------------------------
def pick_symbol(obj, addr, target_bytes, symbol=None):
    funcs = obj.functions()
    if symbol:
        c = [s for s in funcs if s[0] == symbol] or [s for s in funcs if symbol in s[0]]
        if c:
            return c[0]
    hexa = "%08x" % addr
    c = [s for s in funcs if hexa in s[0].lower()]
    if len(c) == 1:
        return c[0]
    best = None
    for s in funcs:
        secnum, value, end = obj.func_extent(s)
        raw = obj.sections[secnum - 1]["raw"] or b""
        d = asm_diff(target_bytes, strip_padding(raw[value:end]), set())
        key = (d["matched"] / d["total"], -abs(d["target_bytes"] - d["our_bytes"]))
        if best is None or key > best[0]:
            best = (key, s)
    return best[1] if best else None


def clang_check(src):
    """Host-clang syntax check (warning only)."""
    clang = "/usr/bin/clang++" if os.path.exists("/usr/bin/clang++") else None
    if not clang:
        return None
    r = subprocess.run([clang, "-fsyntax-only", "-target", "i686-pc-windows-msvc", "-fms-extensions",
                        "-fms-compatibility", "-fms-compatibility-version=13.10", "-w", "-I", os.path.join(ROOT, "include"),
                        src], capture_output=True, text=True)
    return {"ok": r.returncode == 0, "error": (r.stderr or "")[:600]}


def verify(src, addr, symbol=None, flags=(), n_inputs=64, max_inputs=256, mapping=None, max_level=3,
           max_steps=50000, use_names=True, clang=False, obj_path=None, keep_runs=False, time_budget=120):
    """Run levels 1-3 for SRC against the original function at ADDR. Returns the report dict."""
    t0 = time.time()
    prog = Program.get()
    size, tname = prog.funcs[addr]
    rep = {"addr": "0x%08x" % addr, "src": src, "target": tname, "level": 0, "status": "fail"}
    explicit = dict(mapping or {})
    if src and os.path.exists(src):
        for line in open(src, errors="replace"):
            m = re.match(r"\s*//\s*equiv-map:\s*(\S+)\s*=\s*(0x[0-9a-fA-F]+)", line)
            if m:
                explicit.setdefault(m.group(1), int(m.group(2), 16))
    # ---- level 1
    tmp = None
    if obj_path is None:
        tmp = tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) if os.path.isdir(os.path.join(ROOT, "build")) \
            else tempfile.TemporaryDirectory()
        try:
            obj_path = compile_obj(src, DEFAULT_FLAGS + list(flags), tmp.name)
        except CompileError as e:
            rep.update(status="compile_error", error=str(e), time=round(time.time() - t0, 2))
            tmp.cleanup()
            return rep
    obj = Obj(obj_path)
    if tmp:
        tmp.cleanup()
    rep["level1"] = {"ok": True}
    if clang:
        rep["level1"]["clang"] = clang_check(src)
    target = prog.read(addr, size)
    fsym = pick_symbol(obj, addr, target, symbol)
    if fsym is None:
        rep.update(status="no_function", error="no function body in the object")
        return rep
    rep["symbol"] = fsym[0]
    rep["level"] = 1
    ours = Ours(obj, fsym)
    oview = CodeView(prog.read, addr, (addr, addr + size), prog).build()
    orefs = original_refs(prog, oview, size)
    # first link with locals only, so that alignment can read our code
    ours.link({})
    resolved, how, conflicts, exact = resolve_symbols(prog, ours, oview, orefs, explicit, use_names)
    ours.link(resolved)
    rview = CodeView(ours.read, ours.func_addr, (ours.func_addr, ours.func_addr + ours.func_len), prog,
                     is_ours=True).build()
    ours_bytes = ours.bytes_at(addr, resolved)
    rep["byte_identical"] = ours_bytes == target or ours_bytes == strip_padding(target)
    # ---- level 2
    issues = level2(prog, orefs, oview, ours, resolved, how, rview)
    # an immediate that merely looks like an address may legitimately be computed differently: warn only
    warnings = [i for i in issues if i["kind"] in SOFT_L2]
    issues = [i for i in issues if i["kind"] not in SOFT_L2]
    rep["level2"] = {"ok": not issues, "issues": issues[:20], "warnings": warnings[:10],
                     "mapping": {n: {"addr": "0x%08x" % resolved[n] if n in resolved else None, "how": how[n]}
                                 for n in how},
                     "conflicts": conflicts[:10]}
    if not issues:
        rep["level"] = 2
    if max_level < 3:
        rep["status"] = "draft" if not issues else "fail"
        rep["time"] = round(time.time() - t0, 2)
        return rep
    # ---- level 3
    sig = parse_signature(fsym[0])
    ret_kind = sig.get("ret") if sig else None
    if ret_kind is None:
        ret_kind = ghidra_ret_kind(addr)
    used, nsites = prog.callers_use_return(addr)
    if ret_kind is None and nsites:
        ret_kind = {"st0": "f64", "eax": "i32"}.get(used, "void")     # C name: infer from the callers
        rep["return_note"] = "return type inferred from %d call sites of the original" % nsites
    if ret_kind == "void" and used:
        rep["return_note"] = "our function returns void, but callers of the original use %s" % used
        ret_kind = "f64" if used == "st0" else "i32"
    rep["signature"] = sig
    callees = {sym[0] for off, sym, typ, _ in ours.relocs if sym is not None and typ == REL32 and sym[0] in resolved}
    psizes = {}
    for n, d in pointee_sizes(src, flags, sorted(callees)).items():
        psizes[resolved[n]] = d
    l3 = level3(prog, oview, rview, ours, orefs, sig, ret_kind, n_inputs, max_inputs, max_steps, keep_runs,
                time_budget, psizes=psizes)
    rep["level3"] = l3
    if l3["ok"] and rep["level"] == 2:
        rep["level"] = 3
    if l3.get("unsupported"):
        rep["status"] = "unsupported" if not issues else "fail"
    elif l3["ok"] and not issues:
        rep["status"] = "equivalent"
    else:
        rep["status"] = "fail"
    rep["time"] = round(time.time() - t0, 2)
    return rep


def level3(prog, oview, rview, ours, orefs, sig, ret_kind, n_inputs, max_inputs, max_steps, keep_runs=False,
           time_budget=120, directed=96, psizes=None):
    globals_ = sorted({t for _, k, t in orefs if k in ("data", "imm") and prog.section_name(t) in (".data", "BINKDATA", "DOLBY")})
    own_float = ret_kind in ("f32", "f64")
    helpers = dict(HELPERS)
    helpers.update({a: n for n, a in crt_table(prog).items()})     # executed for real on both sides
    consts = sorted({v for i in oview.insns.values() if i.mnemonic in ("cmp", "test", "sub", "and")
                     for v in i.imms for v in (v, (v + 1) & M32, (v - 1) & M32)} | {0, 1})[:64]
    # pointers to read-only data the original uses (strings it compares against, tables)
    rdata_ptrs = sorted({t for _, k, t in orefs if k in ("data", "imm") and prog.section_name(t) == ".rdata"
                         and t not in prog.vftables})[:32]
    consts = consts + rdata_ptrs
    res = {"ok": False, "inputs_run": 0, "inputs_inconclusive": 0, "inputs_faulted": 0, "inputs_failed": 0,
           "inputs_directed": 0, "mismatches": [], "statuses": Counter()}
    edges = set()
    hits = Counter()           # edge -> number of inputs that took it
    slot_arity = {}
    observations = {}          # jcc addr -> [(seed, cmp observation, ...)] from the original's runs
    t_start = time.time()

    def build(seed, overlay=None, stack_patch=None):
        inp = make_input(seed, sig, globals_, rdata_ptrs, consts if seed % 3 == 2 else ())
        if stack_patch:
            for k, v in stack_patch.items():
                inp["stack"][k] = v
                if k < len(inp["own_args"]):
                    inp["own_args"][k] = v
        dictionary = ()
        pointers = ()
        if seed % 3 == 2:
            dictionary = [inp["regs"]["ecx"], inp["regs"]["edx"]] + inp["own_args"] + consts
            roots = {v for v in [inp["regs"]["ecx"], inp["regs"]["edx"]] + inp["own_args"] if HEAP <= v < HEAP + HEAP_SIZE}
            pointers = sorted({r + d for r in roots for d in (0, 4, 8, 12)})
        inp["dictionary"] = dictionary
        inp["stub_mode"] = ("normal", "normal", "normal", "zero", "one", "normal")[seed % 6]
        mach = Machine(prog, seed, globals_, pristine=(seed == 0), dictionary=dictionary, pointers=pointers,
                       overlay=overlay)
        return inp, mach

    def run_input(seed, overlay=None, stack_patch=None, label=None):
        """Run one input on both sides; returns the set of new original edges (None if inconclusive)."""
        inp, mach = build(seed, overlay, stack_patch)
        # our image is mapped in both runs, so a wild pointer reads the same bytes either way
        orun = Run(prog, oview, mach, inp, ours_image=(OURS, ours.image), sig=sig, max_steps=max_steps,
                   own_float_ret=own_float, coverage=True, helpers=helpers)
        orun.pointee_sizes = psizes or {}
        orun.slot_arity = slot_arity
        o = orun.run(oview.entry)
        conclusive = not (o["status"] in ("timeout", "fault:too_many_pages") or o["status"].startswith("fault:hook_error"))
        new = (orun.edges - edges) if conclusive else set()
        if conclusive:                 # a run that never finished proves nothing about the edges it took
            edges.update(orun.edges)
            for e in orun.edges:
                hits[e] += 1
        if o["status"] == "ret":
            for j, ob in orun.cmp_obs.items():
                lst = observations.setdefault(j, [])
                if len(lst) < 6 and all(x[0] != seed for x in lst):
                    lst.append((seed, ob, overlay, stack_patch))
        res["statuses"][o["status"]] += 1
        if o["status"] in ("timeout", "fault:too_many_pages") or o["status"].startswith("fault:hook_error"):
            res["inputs_inconclusive"] += 1
            return None
        rrun = Run(prog, rview, mach, inp, ours_image=(OURS, ours.image), sig=sig, max_steps=max_steps * 2,
                   own_float_ret=own_float, helpers=helpers)
        rrun.pointee_sizes = psizes or {}
        rrun.intrinsics = {a: n for a, n in ours.poison.items() if n in INTRINSIC_NAMES}
        rrun.local_code = (OURS, ours.end)
        rrun.slot_arity = slot_arity
        r = rrun.run(rview.entry)
        diffs = compare_runs(o, r, ret_kind, mach, Namer(inp, sig, prog), prog)
        if o["status"] == "ret":
            res["inputs_run"] += 1
        else:
            res["inputs_faulted"] += 1    # compared up to the fault, but not counted as a passing input
        if diffs:
            res["inputs_failed"] += 1
            if len(res["mismatches"]) < 5:
                res["mismatches"].append({"input": label or seed, "diffs": diffs, "original_status": o["status"],
                                          "calls": len(o["calls"])})
        return new

    def out_of_time():
        if time.time() - t_start > time_budget and res["inputs_run"] >= 8:
            res["time_budget_hit"] = True
            return True
        return False

    # 1. random inputs; then more while coverage keeps growing
    seed, stale = 0, 0
    while seed < max_inputs and res["inputs_failed"] < 3 and not out_of_time():
        if seed >= n_inputs:
            if coverage_of(oview, edges)["complete"] or stale >= 16:
                break
        new = run_input(seed)
        seed += 1
        if new is None:
            if res["inputs_inconclusive"] >= 32 and res["inputs_run"] >= 8:
                res["inconclusive_cap_hit"] = True
                break
            continue
        stale = 0 if new else stale + 1
    # 2. directed inputs: for a branch side never taken, re-run the input that reached its comparison
    #    with the compared memory (or argument) patched to the value on the other side
    tried = set()
    budget = directed
    progress = True
    while progress and budget > 0 and res["inputs_failed"] < 3 and not out_of_time():
        progress = False
        missing = {j for j in oview.jcc for t in (oview.insns[j].target, j + oview.insns[j].size)
                   if (j, t) not in edges} | {j for j in oview.setcc for v in ("set0", "set1") if (j, v) not in edges}
        if not missing:
            # everything reached: spend what is left on sides that few inputs took (path diversity)
            rare = [j for j in oview.jcc for t in (oview.insns[j].target, j + oview.insns[j].size)
                    if hits[(j, t)] < RARE_HITS] + \
                   [j for j in oview.setcc for v in ("set0", "set1") if hits[(j, v)] < RARE_HITS]
            missing = set(rare)
        for j in sorted(missing):
            if j not in observations or budget <= 0 or out_of_time():
                continue
            done = False
            for seed0, ob, ov0, sp0 in observations[j]:
                for overlay, patch in _patches(ob, ov0, sp0, len(make_input(seed0, sig, globals_)["stack"]))[:3]:
                    key = (j, seed0, tuple(sorted(overlay.items())), tuple(sorted(patch.items())))
                    if key in tried:
                        continue
                    tried.add(key)
                    budget -= 1
                    res["inputs_directed"] += 1
                    new = run_input(seed0, overlay, patch, label="%d+patch" % seed0)
                    if new:
                        progress = True
                    sides = [(j, oview.insns[j].target), (j, j + oview.insns[j].size)] \
                        if oview.insns[j].kind == "jcc" else [(j, "set0"), (j, "set1")]
                    if all(hits[e] >= RARE_HITS for e in sides):
                        done = True
                    if done or budget <= 0 or res["inputs_failed"] >= 3:
                        break
                if done or budget <= 0 or res["inputs_failed"] >= 3:
                    break
    res["coverage"] = coverage_of(oview, edges)
    res["statuses"] = dict(res["statuses"])
    if res["inputs_run"] == 0:
        res["unsupported"] = "no input ran to completion in the original (%s)" % res["statuses"]
    else:
        res["ok"] = res["inputs_failed"] == 0
    return res


def _patches(ob, overlay0, patch0, nstack):
    """Memory/argument patches that would send a comparison the other way (input-to-state)."""
    ops = ob["ops"]
    out = []

    def wants(other_val, size):
        m = (1 << (8 * size)) - 1
        return [other_val & m, (other_val + 1) & m, (other_val - 1) & m]

    targets = []
    if ob["mnemonic"] == "test":
        a = ops[0]
        b = ops[1] if len(ops) > 1 else ops[0]
        if a["src"] and (b["src"] == a["src"] or b.get("same")):
            targets.append((a["src"], [0, 1, a["val"] ^ 1]))
        elif a["src"] and b.get("imm") is not None:
            targets.append((a["src"], [0, b["val"]]))
    else:
        if len(ops) == 2:
            a, b = ops
            if a["src"]:
                targets.append((a["src"], wants(b["val"], a["src"][1])))
            if b["src"]:
                targets.append((b["src"], wants(a["val"], b["src"][1])))
    for (ea, size, epoch), vals in targets:
        for v in vals:
            if ENTRY_ESP + 4 <= ea < ENTRY_ESP + 4 + 4 * nstack and size == 4 and (ea - ENTRY_ESP - 4) % 4 == 0:
                patch = dict(patch0 or {})
                patch[(ea - ENTRY_ESP - 4) // 4] = v & M32
                out.append((dict(overlay0 or {}), patch))
            elif not (STACK_LO <= ea < STACK_HI) and not _reserved(ea):
                ov = dict(overlay0 or {})
                ov[(epoch, ea)] = (v & ((1 << (8 * size)) - 1)).to_bytes(size, "little")
                out.append((ov, dict(patch0 or {})))
    return out[:6]


# ---------------------------------------------------------------------------------------------
def render(rep):
    lines = ["%s  %s vs %s (%s)  level %d" % (rep["status"].upper(), rep.get("symbol", "?"), rep["target"],
                                              rep["addr"], rep["level"])]
    if rep.get("error"):
        lines.append(rep["error"])
    l2 = rep.get("level2")
    if l2:
        for i in l2["issues"][:10]:
            lines.append("  L2 %s" % " ".join("%s=%s" % kv for kv in i.items()))
        for c in l2.get("conflicts", [])[:5]:
            lines.append("  L2 note: %s" % c)
    l3 = rep.get("level3")
    if l3:
        cov = l3["coverage"]
        lines.append("  L3 inputs: %d compared, %d faulted in the original, %d inconclusive, %d failed; "
                     "branch coverage %d/%d" % (l3["inputs_run"], l3["inputs_faulted"], l3["inputs_inconclusive"],
                                                l3["inputs_failed"], cov["edges_covered"], cov["edges_total"]))
        if l3.get("unsupported"):
            lines.append("  L3 unsupported: " + l3["unsupported"])
        for m in l3["mismatches"][:3]:
            for d in m["diffs"]:
                lines.append("  L3 input %d: %s" % (m["input"], d))
        if cov["uncovered"]:
            lines.append("  never reached: " + ", ".join(cov["uncovered"][:8]))
    lines.append("  %.1fs" % rep.get("time", 0))
    return "\n".join(lines)


def main(argv):
    extra = []
    if "--" in argv:
        k = argv.index("--")
        argv, extra = argv[:k], argv[k + 1:]
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("src")
    p.add_argument("addr")
    p.add_argument("--symbol")
    p.add_argument("--inputs", type=int, default=64)
    p.add_argument("--max-inputs", type=int, default=256)
    p.add_argument("--steps", type=int, default=50000)
    p.add_argument("--level", type=int, default=3)
    p.add_argument("--map", help="JSON {symbol: '0xaddr'} binding our symbols to original addresses")
    p.add_argument("--no-names", action="store_true", help="ignore addresses encoded in symbol names")
    p.add_argument("--clang", action="store_true", help="also run a host-clang syntax check (warning only)")
    p.add_argument("--json", action="store_true")
    a = p.parse_args(argv)
    mapping = None
    if a.map:
        mapping = {k: int(v, 16) if isinstance(v, str) else v for k, v in json.load(open(a.map)).items()}
    rep = verify(a.src, int(a.addr, 16), symbol=a.symbol, flags=extra, n_inputs=a.inputs, max_inputs=a.max_inputs,
                 mapping=mapping, max_level=a.level, max_steps=a.steps, use_names=not a.no_names, clang=a.clang)
    print(json.dumps(rep, default=str) if a.json else render(rep))
    return 0 if rep["status"] == "equivalent" else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
