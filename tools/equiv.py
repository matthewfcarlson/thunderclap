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
import itertools
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
ARRAY_WINDOW = 16          # most bytes compared behind a scalar or unknown pointer (e.g. float v[4])
POINTEE_WINDOW = 4096        # most bytes of a stack local passed by pointer that are compared at a call
LONG_STEPS = 1000000        # step budget once every early input of the original ran out of 50k steps
PROBE_STEPS = 8000000       # round 7: one input run this long tells long but finite code from runaway loops
EARLY_STEPS = 256           # round 11: an original that returns within this many steps returned early
MIN_CONCLUSIVE = 8          # fewer completed inputs than this (or less coverage than MIN_COVERAGE): inconclusive
MIN_COVERAGE = 0.25
ACCEPT_COVERAGE = 0.75      # the bar for promotion to equivalent/ (promote-remote.sh, farm.ts, clone_equivalent.py):
ACCEPT_INPUTS = 50          # `promotable` in the report; `status` keeps its looser meaning
RMW_MNEMS = frozenset(("inc", "dec", "add", "sub", "and", "or", "xor", "adc", "sbb", "not", "neg", "shl", "shr", "sar",
                       "sal", "rol", "ror", "rcl", "rcr", "xchg", "xadd", "cmpxchg", "bts", "btr", "btc"))
EQUIV_OFF = set(os.environ.get("EQUIV_OFF", "").split(","))   # A/B experiments: switch named round-6 changes off
ONLY_SEEDS = {int(x) for x in os.environ.get("EQUIV_SEEDS", "").split(",") if x.strip()}
DEFAULT_POINTEE = 4         # ... when the callee's parameter type is unknown (e.g. virtual calls)

REL32, DIR32 = 0x14, 0x06
# Differences that equivalent code can legitimately have (level 3 still checks the behaviour):
# an immediate that merely looks like an address, a float constant loaded another way (fld1/fldz, double vs
# float), a string read in pieces vs whole, and CRT routines the original inlined.
SOFT_L2 = ("missing_address_constant", "missing_float_constant", "float_constant_not_in_original",
           "missing_data_ref_interior", "extra_data_ref_interior", "intrinsic_call")
CALLEE_SAVED = ("ebx", "esi", "edi", "ebp")

STRCMP_HELPERS = ("_strcmp", "__stricmp", "_strncmp")     # their .rdata operand is planted (directed inputs)
# CRT helpers that are executed for real instead of stubbed (pure: registers/stack only).
HELPERS = {0x0034483C: "__ftol2", 0x00345880: "__chkstk"}
# Calls that are skipped on both sides: no trace entry, registers and memory untouched. The /GS check
# compares a stack cookie and returns; its caller's `add esp, N` afterwards releases the frame.
IGNORED_CALLS = {0x0034502E: "__security_check_cookie"}
# ... but it is __fastcall: the cookie (read from this global in the prologue) must arrive in ecx
SECURITY_COOKIE = 0x004D9968
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
        self.vt_slots = []          # every vtable's slot list (round 12, vext)
        self.rtti = {}
        # functions reached through a vtable: their callers can't be found by scanning for `call`
        self.virtual_funcs = {a for a, (_, n) in self.funcs.items() if "vfunc_" in n}
        self.typedescs = {}         # '.?AVNode@scenegraph@pure3d@@' -> its RTTI type descriptor (??_R0)
        if os.path.exists(RTTI_JSON):
            for c in json.load(open(RTTI_JSON))["classes"]:
                self.rtti[c["mangled"]] = c
                self.typedescs.setdefault(c["mangled"], c.get("td"))
                for b in c.get("bases", []):
                    self.typedescs.setdefault(b["name"], b.get("td"))
                for v in c["vtables"]:
                    self.vftables[v["address"]] = c["mangled"]
                    self.vt_slots.append(v.get("slots") or [])
                    self.virtual_funcs.update(v.get("slots") or ())
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


    def noreturn(self, target, depth=0):
        """Does a function never return (longjmp, a throw/error helper)? True when no path reaches a ret:
        every path ends in int3/hlt, a call to a function that doesn't return (or one followed by int3 or
        the end of the body), or an indirect jump after reloading esp (longjmp). Conservative: unknown
        code returns."""
        cache = self.__dict__.setdefault("_noret", {})
        if target in cache:
            return cache[target]
        if not self.is_code(target) or target not in self.funcs or depth > 3:
            return False
        cache[target] = False           # recursion guard
        lo, hi = target, target + self.funcs[target][0]
        view = CodeView(self.read, target, (lo, hi), self)
        work, seen, res, steps = [target], set(), True, 0
        esp_load = False
        while work and res and steps < 2000:
            a = work.pop()
            while res and steps < 2000:
                if a in seen:
                    break
                if not lo <= a < hi:
                    res = False
                    break
                seen.add(a)
                steps += 1
                i = view.decode(a)
                if i is None:
                    res = False
                    break
                if i.mnemonic == "mov" and i.ops and i.ops[0] == ("reg", "esp") and i.ops[1][0] == "mem":
                    esp_load = True
                if i.kind == "ret":
                    res = False
                    break
                if i.kind == "stop":
                    if i.mnemonic != "int3":
                        res = False     # (int 0x2c and the like: a debugger service, which returns)
                    break
                if i.kind == "call":
                    nxt = view.decode(a + i.size)
                    # (a call the compiler lets run into int3 never returns)
                    if i.target is not None and (self.noreturn(i.target, depth + 1) or (
                            nxt is not None and nxt.mnemonic == "int3")):
                        break
                    a += i.size
                    continue
                if i.kind == "jcc":
                    if i.target is not None:
                        work.append(i.target)
                elif i.kind == "jmp":
                    if i.target is not None and lo <= i.target < hi:
                        a = i.target
                        continue
                    if i.target is not None:
                        res = res and self.noreturn(i.target, depth + 1)
                    elif i.mem is not None and i.mem[2] and not i.mem[1] and view._table(i):
                        work.extend(view._table(i))
                    else:
                        res = res and esp_load      # longjmp: esp reloaded, then an indirect jump
                    break
                a += i.size
        cache[target] = res and steps < 2000 and not work
        return cache[target]

    def is_code(self, va):
        """Game .text or XDK library code (D3D8, XGRPH, DSOUND, XPP)."""
        return self.text[0] <= va < self.text[1] or self.section_name(va) in ("D3D", "XGRPH", "DSOUND", "XPP")

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
        if len(ops) == 2 and ((ci.mnemonic == "or" and ops[1] in ("0xffffffff", "-1")) or
                              (ci.mnemonic == "and" and ops[1] in ("0", "0x0"))):
            rn.discard(self._ALIAS.get(ops[0], ops[0]))     # or edx, -1 / and eax, 0: constant result
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
        if not self.is_code(target) or depth > 3:
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
        self.__dict__.setdefault("_reg_in_all", {})[target] = set(reads)
        reads &= {"eax", "ecx", "edx"}
        cache[target] = reads
        return reads

    _SUBREGS = {"eax": {"eax": 32, "ax": 16, "ah": 16, "al": 8}, "ecx": {"ecx": 32, "cx": 16, "ch": 16, "cl": 8},
                "edx": {"edx": 32, "dx": 16, "dh": 16, "dl": 8}, "ebx": {"ebx": 32, "bx": 16, "bh": 16, "bl": 8},
                "esi": {"esi": 32, "si": 16}, "edi": {"edi": 32, "di": 16}, "ebp": {"ebp": 32, "bp": 16}}

    def reg_read_width(self, target, reg):
        """(round 7) How many low bits of an incoming register a function reads before it overwrites the
        register: 8 for a byte flag in cl (`test cl, cl`; the high bytes are whatever the caller left), 32
        when unknown. Every path is followed (calls and returns end a path: a callee is assumed to read all
        of it)."""
        cache = self.__dict__.setdefault("_rwidth", {})
        key = (target, reg)
        if key in cache:
            return cache[key]
        cache[key] = 32
        if not self.is_code(target) or reg not in self._SUBREGS:
            return 32
        subs = self._SUBREGS[reg]
        body = (target, target + self.funcs[target][0]) if target in self.funcs else None
        view = CodeView(self.read, target, body, self)
        width, work, seen, steps = 0, [target], set(), 0
        while work and steps < 400:
            a = work.pop()
            while a not in seen and steps < 400:
                seen.add(a)
                steps += 1
                i = view.decode(a)
                ci = next(self.md.disasm(self.read(a, 16), a, 1), None) if i is not None else None
                if ci is None:
                    cache[key] = 32
                    return 32
                try:
                    r, w = ci.regs_access()
                except Exception:
                    cache[key] = 32
                    return 32
                rn = {ci.reg_name(x) for x in r}
                wn = {ci.reg_name(x) for x in w}
                ops = ci.op_str.split(", ")
                if ci.mnemonic in ("xor", "sub", "sbb") and len(ops) == 2 and ops[0] == ops[1]:
                    rn.discard(ops[0])
                if ci.mnemonic in ("push", "pushal", "pushfd") and ops[0] == reg:
                    rn.discard(reg)                  # a save
                for n_ in rn:
                    if n_ in subs:
                        width = max(width, subs[n_])
                if width >= 32 or i.kind in ("call", "ret", "stop") or (i.kind == "jmp" and (
                        i.target is None or not view.internal_target(i.target))):
                    if i.kind == "call" or i.kind == "jmp":
                        width = 32                   # a callee may read it
                    break
                if reg in wn or (reg == "eax" and "eax" in wn):
                    break                            # overwritten: the rest is the function's own value
                if i.kind == "jcc":
                    if i.target is not None and view.internal_target(i.target):
                        work.append(i.target)
                elif i.kind == "jmp":
                    a = i.target
                    continue
                a += i.size
            if width >= 32:
                break
        cache[key] = 32 if steps >= 400 else (width or 32)
        return cache[key]

    def reg_writes(self, target, depth=0):
        """Which of eax/ecx/edx a function may change (its own writes plus its callees'), or None."""
        cache = self.__dict__.setdefault("_reg_wr", {})
        if target in cache:
            return cache[target]
        if not self.is_code(target) or target not in self.funcs or depth > 3:
            return None
        cache[target] = {"eax", "ecx", "edx"}       # recursion guard: assume the worst
        view = CodeView(self.read, target, (target, target + self.funcs[target][0]), self).build(limit=3000)
        out = set()
        for a, i in view.insns.items():
            ci = next(self.md.disasm(self.read(a, 16), a, 1), None)
            if ci is None:
                return None
            nop = (i.mnemonic in ("mov", "xchg") and i.mem is None and len(i.regs) == 2 and i.regs[0] == i.regs[1]) or \
                (i.mnemonic == "lea" and len(i.regs) == 1 and i.mem is not None and i.mem[1] == i.regs[0]
                 and not i.mem[2] and not i.mem[4])
            if not nop or "nopwrite" in EQUIV_OFF:
                # (alignment padding, `lea ecx, [ecx]`, writes nothing: a callee that only has it keeps ecx)
                out |= self._regs_rw(ci)[1] & {"eax", "ecx", "edx"}
            if a in view.tables:
                continue                                  # a jump table inside the function
            if i.kind == "call" or (i.kind == "jmp" and not (i.target is not None and view.internal_target(i.target))):
                sub = self.reg_writes(i.target, depth + 1) if i.target is not None else None
                out |= sub if sub is not None else {"eax", "ecx", "edx"}
        cache[target] = out
        return out

    def callee_writes(self, target, depth=0):
        """{argument location: bytes}: how far a function writes through each pointer argument.

        Locations are 'ecx'/'edx'/'eax' or a stack argument index. Only stores through the incoming pointer
        (or a copy, or the pointer plus a constant) count, including those of callees it passes the pointer
        on to (a base-class or member constructor). Loops that advance the pointer, string instructions and
        indirect calls are not followed, so this under-approximates; {} when unknown."""
        cache = self.__dict__.setdefault("_cwrites", {})
        if target in cache:
            return cache[target]
        if not self.is_code(target) or depth > 4:
            return {}
        cache[target] = {}              # recursion guard
        rthis = self.__dict__.setdefault("_ret_this", {})
        rthis[target] = False
        rets = []                       # what eax holds at each ret (("ecx", 0): the incoming this)
        body = (target, target + self.funcs[target][0]) if target in self.funcs else None
        view = CodeView(self.read, target, body, self)
        out = {}
        init = (frozenset({"ecx": ("ecx", 0), "edx": ("edx", 0), "eax": ("eax", 0)}.items()), 0, None, frozenset())
        states = {}                     # addr -> merged (regs, d, fb, slots) on entry
        work = [(target, init)]
        steps = 0

        def meet(a, b):
            if a is None:
                return b
            ra, rb = dict(a[0]), dict(b[0])
            regs = frozenset((k, v) for k, v in ra.items() if rb.get(k) == v)
            d = a[1] if a[1] == b[1] else None
            fb = a[2] if a[2] == b[2] else None
            sa, sb = dict(a[3]), dict(b[3])
            slots = frozenset((k, v) for k, v in sa.items() if sb.get(k) == v) if d is not None else frozenset()
            return (regs, d, fb, slots)

        def note(loc, ext):
            if ext > 0:
                out[loc] = max(out.get(loc, 0), ext)

        while work and steps < 4000:
            a, st = work.pop()
            merged = meet(states.get(a), st)
            if states.get(a) == merged:
                continue
            states[a] = merged
            regs, d, fb, slots = dict(merged[0]), merged[1], merged[2], dict(merged[3])
            while steps < 4000:
                steps += 1
                i = view.decode(a)
                ci = next(self.md.disasm(self.read(a, 16), a, 1), None) if i is not None else None
                if ci is None:
                    break
                m = i.mnemonic
                # stores through a tracked pointer
                for op in ci.operands:
                    # (round 7: capstone marks the memory operand of x87 stores as read only: `fstp [eax]`
                    # writing a vector through an out-pointer was missed)
                    if op.type == cx.X86_OP_MEM and (op.access & capstone.CS_AC_WRITE or (
                            m in X87_STORES and "x87st" not in EQUIV_OFF)):
                        mb = ci.reg_name(op.mem.base) if op.mem.base else None
                        if mb in regs and not op.mem.index and not m.startswith(("rep", "stos", "movs")):
                            loc, off = regs[mb]
                            disp = op.mem.disp - (1 << 32) if op.mem.disp & 0x80000000 else op.mem.disp
                            note(loc, off + disp + op.size)
                        elif mb == "esp" and d is not None and not op.mem.index and len(i.ops) == 2 and \
                                i.ops[1][0] == "reg" and m == "mov":
                            src = Program._ALIAS.get(i.ops[1][1], i.ops[1][1])
                            disp = op.mem.disp - (1 << 32) if op.mem.disp & 0x80000000 else op.mem.disp
                            if src in regs:
                                slots[d - disp] = regs[src]
                            else:
                                slots.pop(d - disp, None)
                rn, wn = self._regs_rw(ci)
                new = {}
                ops = i.ops
                if m == "mov" and len(ops) == 2 and ops[0][0] == "reg" and ops[0][1] in self._REGS:
                    if ops[1][0] == "reg" and ops[1][1] in regs:
                        new[ops[0][1]] = regs[ops[1][1]]
                    elif ops[1][0] == "mem" and not ops[1][1][2] and ops[1][1][0] is None:
                        base, disp = ops[1][1][1], ops[1][1][4]
                        disp = disp - (1 << 32) if disp & 0x80000000 else disp
                        k = None
                        if base == "esp" and d is not None:
                            k = disp - d - 4
                            if d - disp in slots:
                                new[ops[0][1]] = slots[d - disp]
                        elif base == "ebp" and fb is not None:
                            k = disp - fb - 4
                        if k is not None and k >= 0 and k % 4 == 0:
                            new[ops[0][1]] = (k // 4, 0)
                elif m == "lea" and len(ops) == 2 and ops[0][0] == "reg" and ops[1][0] == "mem":
                    _, base, index, _, disp, _ = ops[1][1]
                    disp = disp - (1 << 32) if disp & 0x80000000 else disp
                    if base in regs and not index:
                        loc, off = regs[base]
                        new[ops[0][1]] = (loc, off + disp)
                elif m in ("add", "sub") and len(ops) == 2 and ops[0][0] == "reg" and ops[0][1] in regs \
                        and ops[1][0] == "imm":
                    loc, off = regs[ops[0][1]]
                    imm = ops[1][1] - (1 << 32) if ops[1][1] & 0x80000000 else ops[1][1]
                    new[ops[0][1]] = (loc, off + (imm if m == "add" else -imm))
                # stack depth, pushes and pops
                if d is not None:
                    if m == "push":
                        d += 4
                        if ops and ops[0][0] == "reg" and ops[0][1] in regs:
                            slots[d] = regs[ops[0][1]]
                        else:
                            slots.pop(d, None)
                    elif m == "pop":
                        if ops and ops[0][0] == "reg" and d in slots:
                            new[ops[0][1]] = slots[d]
                        d -= 4
                    elif m in ("sub", "add") and i.op_str.startswith("esp,") and i.imms:
                        d += i.imms[0] if m == "sub" else -i.imms[0]
                    elif "esp" in wn and i.kind == "other":
                        d = None
                if m == "mov" and i.op_str == "ebp, esp":
                    fb = d
                elif m == "leave" or (m == "mov" and i.op_str == "esp, ebp"):
                    d = fb - 4 if (m == "leave" and fb is not None) else fb
                for r in wn:
                    if r in regs or r in new:
                        regs.pop(r, None)
                regs.update(new)
                if i.kind == "ret":
                    rets.append(regs.get("eax"))
                if i.kind in ("ret", "stop"):
                    break
                if i.kind == "call" or (i.kind == "jmp" and not (i.target is not None and view.internal_target(i.target))):
                    tail = i.kind == "jmp"
                    this_in = regs.get("ecx")
                    sub_this = i.target is not None and self.is_code(i.target) and \
                        (self.callee_writes(i.target, depth + 1) is not None) and \
                        self.__dict__.get("_ret_this", {}).get(i.target, False)
                    if tail:
                        rets.append(this_in if sub_this else None)
                    if i.target is not None and d is not None:
                        sub = self.callee_writes(i.target, depth + 1)
                        for loc2, ext2 in sub.items():
                            if isinstance(loc2, int):
                                key = d - 4 * loc2 - (4 if tail else 0)
                                src = slots.get(key)
                                if src is None and tail and key <= -4 and (-key - 4) % 4 == 0:
                                    src = ((-key - 4) // 4, 0)       # our own argument, passed on in place
                            else:
                                src = regs.get(loc2)
                            if src is not None:
                                note(src[0], src[1] + ext2)
                    if tail:
                        break
                    pop = self.callee_pop(i.target) if i.target is not None else None
                    if pop is None or d is None:
                        d = None
                        slots = {}
                    else:
                        d -= pop
                        slots = {k_: v_ for k_, v_ in slots.items() if k_ <= d}
                    for r in ("eax", "ecx", "edx"):
                        regs.pop(r, None)
                    if sub_this and this_in is not None:
                        regs["eax"] = this_in       # a base or member constructor returns its this
                    a += i.size
                    continue
                if i.kind == "jcc":
                    if i.target is not None and view.internal_target(i.target):
                        work.append((i.target, (frozenset(regs.items()), d, fb, frozenset(slots.items()))))
                elif i.kind == "jmp":
                    if i.target is not None and view.internal_target(i.target):
                        work.append((i.target, (frozenset(regs.items()), d, fb, frozenset(slots.items()))))
                    elif i.target is None and i.mem is not None and i.mem[2]:
                        for t in view._table(i):
                            work.append((t, (frozenset(regs.items()), d, fb, frozenset(slots.items()))))
                    break
                a += i.size
                if a in states:
                    work.append((a, (frozenset(regs.items()), d, fb, frozenset(slots.items()))))
                    break
        cache[target] = out if steps < 4000 else {}
        rthis[target] = steps < 4000 and bool(rets) and all(x == ("ecx", 0) for x in rets)
        return cache[target]

    def returns_this(self, target):
        """Does the function return its incoming ecx in eax on every path (a constructor, `return *this`)?"""
        self.callee_writes(target)
        return self.__dict__.get("_ret_this", {}).get(target, False)

    def reg_inputs_all(self, target):
        """Every register (callee-saved ones included) a function reads before writing it."""
        self.reg_inputs(target)
        return self.__dict__.get("_reg_in_all", {}).get(target)

    def callee_stack_args(self, target, depth=0):
        """Number of stack argument words a function reads (its semantic arity), or None if unknown."""
        cache = self.__dict__.setdefault("_nargs", {})
        if target in cache:
            return cache[target]
        if not self.is_code(target) or target not in self.funcs or depth > 3:
            return None
        cache[target] = None
        view = CodeView(self.read, target, (target, target + self.funcs[target][0]), self)
        best = 0
        ok = True
        prologue = view.prologue()
        work = [(target, 0, None, False, 0, frozenset())]       # (addr, esp depth, frame base, ebp is a general register)
        seen = set()
        steps = 0
        while work and steps < 3000 and ok:
            a, d, fb, gen, pend, wr = work.pop()
            while steps < 3000:
                if (a, d, fb, gen, pend, wr) in seen:
                    break
                seen.add((a, d, fb, gen, pend, wr))
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
                    elif base == "ebp" and gen:
                        off = -1                # ebp holds something else (`lea ebp, [eax + ebx]`)
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
                if i.ops and i.ops[0] == ("reg", "ebp") and m not in ("push", "cmp", "test") and \
                        not (m == "mov" and ops == "ebp, esp") and not (m == "pop" and fb is None):
                    gen = m != "pop"
                if m == "push" and a not in prologue and not (
                        i.ops and i.ops[0][0] == "reg" and i.ops[0][1] in CALLEE_SAVED and i.ops[0][1] not in wr):
                    pend += 4               # (not a save of a callee-saved register the function hasn't touched)
                if i.ops and i.ops[0][0] == "reg" and i.ops[0][1] in CALLEE_SAVED and m not in ("push", "cmp", "test"):
                    wr = wr | {i.ops[0][1]}
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
                    if pop is None and i.target is None:
                        # an indirect call: with nothing pushed for it, it pops nothing; otherwise the
                        # caller's use of the pushed words afterwards tells
                        if pend == 0:
                            pop = 0
                        else:
                            pu = view.pending_use(a, pend // 4)
                            if pu is not None:
                                pop = 0 if pu[0] in ("caller", "reader") else 4 * pu[1]
                    pend = 0
                    if pop is None:
                        d = None
                    elif d is not None:
                        d -= pop
                    a += i.size
                    continue
                if i.kind == "jcc":
                    if i.target is not None and view.internal_target(i.target):
                        work.append((i.target, d, fb, gen, pend, wr))
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
                            work.append((t, d, fb, gen, pend, wr))
                    break
                a += i.size
        cache[target] = best if ok and steps < 3000 and not work else None
        return cache[target]

    def vslot_writes(self, disp, pop):
        """(round 12, vext) What the functions in vtable slot `disp` that pop `pop` bytes write through each
        stack argument: {argument index: sorted [bytes written, one per implementation that writes]}."""
        cache = self.__dict__.setdefault("_vsw", {})
        if (disp, pop) in cache:
            return cache[(disp, pop)]
        out = {}
        if disp % 4 == 0 and 0 <= disp < 0x1000:
            for t in sorted({sl[disp // 4] for sl in self.vt_slots if disp // 4 < len(sl)}):
                if not self.is_code(t) or self.callee_pop(t) != pop:
                    continue
                for loc, w in (self.callee_writes(t) or {}).items():
                    if isinstance(loc, int) and w:
                        out.setdefault(loc, []).append(w)
        cache[(disp, pop)] = out = {j: sorted(ws) for j, ws in out.items()}
        return out

    def x87_args(self, target, depth=0):
        """(round 11, x87args) x87 registers a callee takes as arguments: what its first instructions read below
        the stack it found (`__CIpow`: `fxch st(1); fstp qword [esp]; fst qword [esp+8]` takes st0 and st1 and
        leaves its result in their place). 0 for ordinary callees."""
        cache = self.__dict__.setdefault("_x87a", {})
        if target in cache:
            return cache[target]
        cache[target] = 0
        if not self.is_code(target) or depth > 3:
            return 0
        view = CodeView(self.read, target, None, self)
        a, d, need = target, 0, 0
        for _ in range(24):
            i = view.decode(a)
            if i is None:
                break
            if i.kind == "jmp" and i.target is not None:
                if a == target:
                    cache[target] = self.x87_args(i.target, depth + 1)
                    return cache[target]
                a = i.target
                continue
            if i.kind != "other":
                break
            req, delta = i.x87
            need = max(need, req - d)
            d += delta
            a += i.size
        cache[target] = min(need, 3)
        return cache[target]

    def containing_func(self, va):
        """(entry, size) of the listed function whose body holds va, or None."""
        starts = self.__dict__.get("_starts")
        if starts is None:
            starts = self._starts = sorted(self.funcs)
        import bisect
        k = bisect.bisect_right(starts, va) - 1
        if k < 0:
            return None
        e = starts[k]
        return (e, self.funcs[e][0]) if va < e + self.funcs[e][0] else None

    def pending_at(self, entry, size, site):
        """(round 11) The words pushed for calls but not yet taken at `site`, on every path from the entry of the
        function (entry, size) that holds it: a set of byte counts (None in it: unknown on some path). Pushes
        of untouched callee-saved registers and the prologue's are saves, not arguments; a call takes what its
        callee pops (unknown for an indirect call with words pending), `add esp` and `pop` release."""
        view = CodeView(self.read, entry, (entry, entry + size), self)
        prologue = view.prologue()
        out = set()
        work = [(entry, 0, frozenset())]
        seen = set()
        steps = 0
        while work and steps < 4000:
            a, pend, wr = work.pop()
            while steps < 4000:
                if (a, pend, wr) in seen:
                    break
                seen.add((a, pend, wr))
                steps += 1
                i = view.decode(a)
                if i is None:
                    out.add(None)
                    break
                if a == site:
                    out.add(pend)
                m, ops = i.mnemonic, i.op_str
                if pend is not None and a not in prologue:
                    if m == "push" and not (
                            i.ops and i.ops[0][0] == "reg" and i.ops[0][1] in CALLEE_SAVED and i.ops[0][1] not in wr):
                        pend += 4
                    elif m == "pop" and pend:
                        pend -= 4
                    elif m == "add" and ops.startswith("esp,") and i.imms:
                        pend = max(0, pend - i.imms[0])
                    elif m == "sub" and ops.startswith("esp,") and i.imms:
                        pend += i.imms[0]           # (`sub esp, 8; fstp qword [esp]`: a double argument)
                    elif m == "leave" or (m == "mov" and ops == "esp, ebp"):
                        pend = 0
                    elif i.ops and i.ops[0] == ("reg", "esp") and m not in ("cmp", "test", "push", "pop"):
                        pend = None
                if i.ops and i.ops[0][0] == "reg" and i.ops[0][1] in CALLEE_SAVED and m not in ("push", "cmp", "test"):
                    wr = wr | {i.ops[0][1]}
                if i.kind in ("ret", "stop"):
                    break
                if i.kind == "call":
                    pop = self.callee_pop(i.target) if i.target is not None else (0 if pend == 0 else None)
                    if pend is not None:
                        pend = None if pop is None else max(0, pend - pop)
                    a += i.size
                    continue
                if i.kind == "jcc":
                    if i.target is not None and view.internal_target(i.target):
                        work.append((i.target, pend, wr))
                elif i.kind == "jmp":
                    if i.target is not None and view.internal_target(i.target):
                        a = i.target
                        continue
                    if i.target is None and i.mem is not None and i.mem[2]:
                        for t in view._table(i):
                            work.append((t, pend, wr))
                    break
                a += i.size
        if work:
            out.add(None)
        return out

    def ptr_call_pop(self, ea):
        """(round 11, ptrpop) How a callee reached through the fixed function pointer at `ea` (`call [ea]`)
        treats the stack, from the pointer's call sites across the image: "noargs" when some site passes it no
        words (nothing pending on any path: the pointer type takes no stack arguments, whatever its
        convention, so it pops nothing and pending words belong to a later call), "caller" when some site
        releases the words right after the call (`call [ea]; add esp, 8`: caller-cleaned, pops nothing).
        None when no site tells."""
        cache = self.__dict__.setdefault("_ptr_pop", {})
        if ea in cache:
            return cache[ea]
        res = None
        lo, hi = self.text
        data = self.__dict__.get("_text_bytes")
        if data is None:
            data = self._text_bytes = self.read(lo, hi - lo)
        pat = b"\xff\x15" + struct.pack("<I", ea)
        k = data.find(pat)
        n = 0
        while k >= 0 and n < 64 and res is None:
            site = lo + k
            n += 1
            f = self.containing_func(site)
            if f is not None:
                view = CodeView(self.read, f[0], (f[0], f[0] + f[1]), self)
                i = view.decode(site)
                if i is not None and i.kind == "call" and i.mem == (None, None, None, 1, ea, 4):
                    if view.immediate_cleanup(site):
                        res = "caller"
                    elif self.pending_at(f[0], f[1], site) == {0}:
                        res = "noargs"
            k = data.find(pat, k + 1)
        cache[ea] = res
        return res

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
        self.extra_starts = set()  # function starts functions.csv misses (named by our source)
        self.jcc = []             # conditional branch addresses
        self.setcc = []           # setcc addresses (branch-free conditions count for coverage too)
        self.tables = {}          # indirect jmp addr -> [targets]
        self.table_bound = {}     # (round 15) indirect jmp addr -> number of case indices
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

    def eax_rw(self, addr):
        """(reads eax/ax/al/ah, bits written to eax: 0, 8, 16 or 32) for one instruction."""
        c = self.__dict__.setdefault("_eaxrw", {})
        if addr not in c:
            ci = next(self.prog.md.disasm(self.read(addr, 16), addr, 1), None)
            rd, wr = False, 0
            if ci is not None:
                try:
                    r, w = ci.regs_access()
                except Exception:
                    r, w = [], []
                rn = {ci.reg_name(x) for x in r}
                wn = {ci.reg_name(x) for x in w}
                ops = ci.op_str.split(", ")
                if ci.mnemonic in ("xor", "sub", "sbb") and len(ops) == 2 and ops[0] == ops[1]:
                    rn.discard(ops[0])
                rd = bool(rn & {"eax", "ax", "al", "ah"})
                wr = 32 if "eax" in wn else 16 if "ax" in wn else 8 if wn & {"al", "ah"} else 0
                if ci.mnemonic in ("call", "ret"):
                    wr = 0
            c[addr] = (rd, wr)
        return c[addr]

    def eax_base_only(self, addr):
        """(round 8) The instruction reads eax only as the base or index of a memory operand (`cmp [eax +
        0x221c], ebx`): it dereferences the value without using it as a value."""
        i = self.decode(addr)
        if i is None or i.mem is None or not (i.mem[1] == "eax" or i.mem[2] == "eax"):
            return False
        fam = ("eax", "ax", "al", "ah")
        for k, op in enumerate(i.ops):
            if op[0] == "reg" and op[1] in fam:
                if k > 0 or i.mnemonic not in ("mov", "movzx", "movsx", "lea", "pop") and \
                        not i.mnemonic.startswith("set"):
                    return False
        ci = next(self.prog.md.disasm(self.read(addr, 16), addr, 1), None)
        try:
            r, _ = ci.regs_access()
        except Exception:
            return False
        explicit = {ci.reg_name(x) for op in ci.operands if op.type == cx.X86_OP_REG for x in (op.reg,)} | \
            {ci.reg_name(x) for op in ci.operands if op.type == cx.X86_OP_MEM for x in (op.mem.base, op.mem.index) if x}
        # an implicit read (cdq, stosd, mul, xchg's other side) uses the value
        return not ({ci.reg_name(x) for x in r} - explicit) & set(fam)

    def popped_regs(self):
        """Registers some `pop` (or `leave`, for ebp) of this function restores."""
        if "_popped" not in self.__dict__:
            if not self.insns:
                self.build()
            self._popped = {i.regs[0] for i in self.insns.values() if i.mnemonic == "pop" and i.regs} | \
                ({"ebp"} if any(i.mnemonic == "leave" for i in self.insns.values()) else set())
        return self._popped

    def write_widths(self, addr):
        """{32-bit register: bits written} for one instruction (al -> 8, ax -> 16, eax -> 32)."""
        c = self.__dict__.setdefault("_ww", {})
        if addr not in c:
            ci = next(self.prog.md.disasm(self.read(addr, 16), addr, 1), None)
            out = {}
            if ci is not None:
                try:
                    _, w = ci.regs_access()
                except Exception:
                    w = []
                for x in w:
                    n = ci.reg_name(x)
                    r32 = Program._ALIAS.get(n, n)
                    bits = 32 if n == r32 else 16 if len(n) == 2 and n.endswith(("x", "i", "p")) else 8
                    out[r32] = max(out.get(r32, 0), bits)
            c[addr] = out
        return c[addr]

    def eax_dead_after(self, addr):
        """Is the value an instruction writes to eax never read on any path (until overwritten or a return)?
        Only a return value explains such a write; a loop counter set up for a loop that didn't run is read
        on the other paths."""
        c = self.__dict__.setdefault("_eaxdead", {})
        if addr in c:
            return c[addr]
        i0 = self.decode(addr)
        if "voidflags" not in EQUIV_OFF and i0.mnemonic in ("dec", "inc", "sub", "add", "and", "or", "xor", "neg",
                                                              "shl", "shr", "sar"):
            # (round 7) `dec eax; jne` (a switch's dec chain): the value is tested through the flags, so the
            # write is read. A return value doesn't explain it
            nx = self.decode(addr + i0.size)
            if nx is not None and (nx.kind == "jcc" or nx.mnemonic.startswith(("set", "cmov", "adc", "sbb"))):
                c[addr] = False
                return False
        work, seen, steps, res = [addr + i0.size], set(), 0, True
        while work and res and steps < 400:
            a = work.pop()
            while a not in seen and steps < 400:
                seen.add(a)
                steps += 1
                i = self.decode(a)
                if i is None:
                    res = False
                    break
                rd, wr = self.eax_rw(a)
                if rd:
                    res = False
                    break
                if wr == 32 or i.kind in ("ret", "stop", "call"):
                    break
                if i.kind == "jcc":
                    if i.target is not None and self.internal_target(i.target):
                        work.append(i.target)
                elif i.kind == "jmp":
                    if i.target is not None and self.internal_target(i.target):
                        a = i.target
                        continue
                    break
                a += i.size
        c[addr] = res and steps < 400
        return c[addr]

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
        return (self.prog.text[0] <= a < self.prog.text[1]) and not self.prog.is_func_start(a) \
            and a not in self.extra_starts

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
        if len(self.tables) > 1:
            # a table read up to the first non-code word runs on into the next table placed after it (two
            # switches): it ends where the next one starts
            bases = sorted(self.insns[j].mem[4] for j in self.tables)
            for j, tg in self.tables.items():
                b = self.insns[j].mem[4]
                nxt_b = min((x for x in bases if x > b), default=None)
                if nxt_b is not None and b + 4 * len(tg) > nxt_b:
                    self.tables[j] = tg[:(nxt_b - b) // 4]
            self.table_ranges = [(lo, min([hi] + [x for x in bases if lo < x < hi])) for lo, hi in self.table_ranges]
        self.table_bound = {j: self._table_bound(j) for j in self.tables}
        return self

    def _table_bound(self, j):
        """(round 15, caseidx) The number of indices the bounds check before a jump table lets through (`cmp esi,
        0x14; ja default; jmp [esi*4 + tab]`: 21), capped at the table read; the table's length when none is found."""
        n = len(self.tables[j])
        reg = self.insns[j].mem[2]
        prev = sorted(a for a in self.insns if j - 48 <= a < j)
        cond = None
        for a in reversed(prev):
            i = self.insns[a]
            if i.kind == "jcc" and cond is None:
                cond = i.mnemonic
                continue
            if cond and i.mnemonic == "cmp" and i.ops and i.ops[0] == ("reg", reg) and len(i.ops) == 2 and \
                    i.ops[1][0] == "imm":
                k = i.ops[1][1] + (1 if cond == "ja" else 0) if cond in ("ja", "jae") else None
                return min(n, k) if k else n
            if i.kind in ("call", "jmp", "ret") or (i.ops and i.ops[0] == ("reg", reg) and i.mnemonic != "cmp"):
                break
        return n

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

    def float_ret_after(self, call_addr, own_float_ret, depth0=0):
        """Does the code after this call consume st0 (i.e. the callee returns a float)? depth0: values the
        caller already keeps on the x87 stack across the call (a running sum: `fld [k]; push eax; call f;
        fadd [m]` adds to the sum, it doesn't consume a float result)."""
        key = call_addr if not depth0 else (call_addr, depth0)
        if key in self._fret:
            return self._fret[key]
        i0 = self.decode(call_addr)
        start = call_addr + i0.size
        res = False
        seen = set()
        stack = [(start, depth0)]
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
                if i.kind == "call" and i.target in IGNORED_CALLS and "cookie" not in EQUIV_OFF:
                    a = a + i.size          # the /GS check before the epilogue: st0 stays live across it
                    continue
                if i.kind == "call" and HELPERS.get(i.target) == "__ftol2" and d < 1 and "ftolret" not in EQUIV_OFF:
                    res = True      # (round 9) `call f; call __ftol2`: the helper converts f's float result
                    break
                if i.kind == "call" and i.target is not None and "x87cmp" not in EQUIV_OFF and \
                        d < self.prog.x87_args(i.target):
                    res = True      # (round 12) `call f; call __CIasin`: f's float result is the next call's x87 argument
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
        self._fret[key] = res
        return res

    def next_call_pop(self, call_addr):
        """Look ahead from an indirect call for the outer call its pending pushes belong to.

        Returns (bytes that direct call pops, bytes pushed in between), or None. Indirect calls on the
        way are taken to be argument-less nested calls (`f(a, b, obj->g(), c)`)."""
        i = self.decode(call_addr)
        a = call_addr + i.size
        later = 0
        for _ in range(40):
            j = self.decode(a)
            if j is None:
                return None
            if j.kind == "call":
                if j.target is not None:
                    pop = self.prog.callee_pop(j.target)
                    return (pop, later) if pop else None
                a += j.size
                continue
            if j.mnemonic == "push":
                later += 4
            elif j.kind != "other" or j.mnemonic in ("pop", "leave", "pushal", "popal", "pushfd", "popfd") \
                    or (j.ops and j.ops[0] == ("reg", "esp")):
                return None                     # (a store into an argument slot, [esp+n], is fine)
            a += j.size
        return None

    def pending_use(self, call_addr, npending, _depth=0):
        """Who takes the npending argument words pushed before a call of unknown arity, from what the
        caller does with the stack afterwards: ("caller", n) when a later `add esp` releases them (the
        callee leaves its arguments: a plain ret), ("callee", k) when a later call with a known `ret N`
        pops npending - k of them (they were pushed early for that call: `push 1; call thunk; push eax;
        push esi; call f(ret 4); push eax; call g(ret 12)`), ("reader", k) when such a call pops k and a
        later `add esp` releases exactly the rest (the callee pops nothing: `push eax; push K; call thunk;
        mov ecx, eax; call f(ret 4); push ...; call g; add esp, 0x10`), None when it can't tell."""
        i = self.decode(call_addr)
        a = call_addr + i.size
        depth = 0                   # bytes pushed after the call that are still on the stack
        calls = 0                   # calls between ours and the cleanup
        taken = 0                   # pending words a later call with a known `ret N` popped
        seen = set()
        # once a later call took some pending words, anything unclear means the callee popped the rest
        unsure = lambda: ("callee", npending - taken) if taken else None
        for _ in range(64):
            if a in seen:
                return unsure()
            seen.add(a)
            j = self.decode(a)
            if j is None:
                return unsure()
            m = j.mnemonic
            if m == "push":
                depth += 4
            elif m == "pop":
                if depth >= 4:
                    depth -= 4
                else:
                    return unsure()
            elif m in ("add", "sub") and j.ops and j.ops[0] == ("reg", "esp") and j.imms:
                imm = j.imms[0]
                nx = self.decode(a + j.size)
                if m == "add" and depth == 0 and _depth == 0 and nx is not None and "epilogue" not in EQUIV_OFF and \
                        (nx.kind == "ret" or (nx.mnemonic == "pop" and nx.regs and nx.regs[0] in CALLEE_SAVED)) and \
                        imm == self.frame_alloc() and imm:
                    # the epilogue releases exactly the frame the prologue reserved: nothing released the
                    # pending words, so our callee popped them (`sub esp, 0x14; ...; push x6; call [esp+0x3c];
                    # ...; add esp, 0x14; ret`)
                    return ("callee", npending - taken)
                depth += -imm if m == "add" else imm
                if depth < 0:
                    released = -depth // 4
                    if taken:
                        # the rest of the pending words released by the caller: the callee popped none
                        return ("reader", taken) if released == npending - taken else unsure()
                    if -depth > 4 * npending:
                        return None     # releases more than the pending words: the frame (an epilogue)
                    if calls and released < npending and _depth == 0 and \
                            self._pending_unclaimed(a, npending - released):
                        # a deferred cleanup after later cdecl calls that leaves some pending words on the
                        # stack, with nothing after it taking them: our call popped them (`push 0; push 0x103;
                        # call [vt+0x164] (ret 4); push eax; call f; push 8; call g; add esp, 0x18`)
                        return ("callee", npending - released)
                    return ("caller", npending)
            elif j.kind == "call":
                if j.target in IGNORED_CALLS:
                    return unsure()
                calls += 1
                pop = self.prog.callee_pop(j.target) if j.target is not None else None
                if pop is None:
                    if j.target is not None or (j.mem is not None and not j.mem[1] and not j.mem[2]):
                        return unsure()     # (a thunk, or an import through its IAT slot: stdcall, likely)
                    # another virtual call: what its own pushed words become decides its pop (the same
                    # question, one call later); otherwise it pops what was pushed for it (thiscall)
                    sub = self.pending_use(a, depth // 4, _depth + 1) if depth and _depth < 3 else None
                    pop = depth if sub is None else (4 * sub[1] if sub[0] == "callee" else 0)
                if pop == 0 and j.target is not None and not taken:
                    reads = self.prog.callee_stack_args(j.target)
                    if reads is not None and 4 * reads > depth:
                        # a caller-cleaned call that also reads words pushed before ours: they are its
                        # arguments, pushed early (`push &t; call [vt+0x40]; push eax; ...; call f; add esp`)
                        used = min(npending, (4 * reads - depth + 3) // 4)
                        cl = self.cleanup_after(j.addr)
                        if cl is not None and used < npending and cl == depth + 4 * used:
                            # its cleanup releases only the words it reads: the rest were ours, and our
                            # callee popped them (`push 0; push T; push S; push 0; push 0; call [vt+0x48]
                            # (ret 4); push eax; call __RTDynamicCast; add esp, 0x14`)
                            return ("callee", npending - used)
                        return ("reader", npending - used)
                depth -= pop
                if depth < 0:
                    used = min(npending - taken, -depth // 4)
                    if _depth or taken + used >= npending:
                        return ("callee", npending - taken - used)
                    # some pending words remain: see whether the caller releases them later
                    taken += used
                    depth = 0
            elif j.kind == "jmp":
                if j.target is not None and self.internal_target(j.target):
                    a = j.target
                    continue
                return unsure()
            elif j.kind in ("ret", "stop") or m in ("leave", "pushal", "popal", "pushfd", "popfd") or \
                    (j.ops and j.ops[0] == ("reg", "esp")):
                return unsure()
            a += j.size
        return unsure()

    def join_balance(self, call_addr, npending):
        """Who pops the npending words pushed before a call of unknown arity, from the stack depth where a
        branch taken before the pushes joins the code after the call (`test eax, eax; je L; push 0; push T;
        push S; push 0; push 0; call [vt+0x48]; push eax; call __RTDynamicCast; add esp, 0x14; L:`): both
        paths reach L with the same depth, which leaves one way for the words to go. ("callee", k) when our
        callee pops k of them, or None."""
        if npending <= 0 or call_addr not in self.insns:
            return None
        prev = self.__dict__.get("_prev")
        if prev is None:
            prev = self._prev = {a + i.size: a for a, i in self.insns.items()}

        def plain(j):
            return j.kind == "other" and j.mnemonic not in ("pop", "push", "leave", "pushal", "popal", "pushfd",
                                                              "popfd", "enter") and \
                not (j.ops and j.ops[0] == ("reg", "esp")) and "esp" not in (j.regs[:1] if j.mnemonic in
                                                                              ("xchg", "lea", "mov") else [])
        a, n = call_addr, 0
        while n < npending:
            a = prev.get(a)
            if a is None:
                return None
            j = self.insns[a]
            if j.mnemonic == "push":
                n += 1
            elif not plain(j):
                return None
        jcc = None
        b = a
        for _ in range(16):
            b = prev.get(b)
            if b is None:
                break
            j = self.insns[b]
            if j.kind == "jcc" and j.target is not None and j.target > call_addr:
                jcc = j
                break
            if not plain(j):
                break
        if jcc is None:
            return None
        depth = 4 * npending              # (our callee taken to pop nothing)
        a = call_addr + self.insns[call_addr].size
        seen = set()
        for _ in range(64):
            if a == jcc.target:
                if depth % 4 or not 0 <= depth <= 4 * npending:
                    return None
                k = depth // 4
                # (k == 0: our callee pops nothing, but the words may still be a later call's, popped by its
                # `ret N`: pending_use decides how many are ours to read)
                return ("callee", k) if k else None
            if a in seen:
                return None
            seen.add(a)
            j = self.decode(a)
            if j is None:
                return None
            m = j.mnemonic
            if m == "push":
                depth += 4
            elif m == "pop":
                depth -= 4
            elif m in ("add", "sub") and j.ops and j.ops[0] == ("reg", "esp") and j.imms:
                depth += -j.imms[0] if m == "add" else j.imms[0]
            elif j.kind == "call":
                if j.target is None or j.target in IGNORED_CALLS:
                    return None
                pop = self.prog.callee_pop(j.target)
                if pop is None:
                    return None
                depth -= pop
            elif j.kind == "jmp":
                if j.target is not None and self.internal_target(j.target):
                    a = j.target
                    continue
                return None
            elif j.kind in ("ret", "stop") or m in ("leave", "pushal", "popal", "pushfd", "popfd", "enter") or \
                    (j.ops and j.ops[0] == ("reg", "esp")):
                return None
            a += j.size
        return None

    def _pending_unclaimed(self, addr, nleft):
        """After the cleanup at addr, nleft argument words are still on the stack: True when the code
        reaches an epilogue (pop, leave, ret, a frame release) before anything releases or pops them."""
        r = self.pending_use(addr, nleft, 1)
        if r is not None:
            return False
        a = addr
        seen = set()
        for _ in range(64):
            if a in seen:
                return False
            seen.add(a)
            j = self.decode(a)
            if j is None:
                return False
            j_next = a + j.size
            if a != addr:
                m = j.mnemonic
                if m == "pop" or m == "leave" or j.kind == "ret" or \
                        (m == "add" and j.ops and j.ops[0] == ("reg", "esp")):
                    return True
                if m == "push" or (j.kind == "call" and j.target is not None and self.prog.callee_pop(j.target)):
                    return False
                if j.kind == "jmp":
                    if j.target is not None and self.internal_target(j.target):
                        a = j.target
                        continue
                    return False
                if j.kind == "stop" or (j.ops and j.ops[0] == ("reg", "esp")):
                    return False
            a = j_next
        return False

    def frame_alloc(self):
        """Bytes the prologue reserves with `sub esp, N` (before any call), or 0."""
        if "_frame_alloc" not in self.__dict__:
            n, a = 0, self.entry
            for _ in range(12):
                j = self.decode(a)
                if j is None or j.kind != "other":
                    break
                if j.mnemonic == "sub" and j.ops and j.ops[0] == ("reg", "esp") and j.imms:
                    n = j.imms[0]
                    break
                a += j.size
            self._frame_alloc = n
        return self._frame_alloc

    def cleanup_after(self, call_addr):
        """Bytes the caller pops after a call (cdecl cleanup), or None.

        MSVC may defer the cleanup of several cdecl calls into one `add esp, N`; pushes for later
        calls in between are subtracted (and known callee pops added back)."""
        i = self.decode(call_addr)
        a = call_addr + i.size
        later = 0          # bytes pushed after our call that the same cleanup also removes
        # (round 7: 48 instructions, not 24: four calls through a writer callback, 4 words each, share one
        # `add esp, 0x40` 31 instructions on: Lua's DumpHeader)
        for k in range(48 if "cleanwin" not in EQUIV_OFF else 24):
            j = self.decode(a)
            if j is None:
                return None
            if j.mnemonic == "add" and j.op_str.startswith("esp,") and j.imms:
                nx = self.decode(a + j.size)
                if j.imms[0] - later > 0x100 and nx is not None and (
                        nx.kind == "ret" or (nx.mnemonic == "pop" and nx.regs and nx.regs[0] in CALLEE_SAVED)):
                    return None         # the epilogue releasing a big frame, not argument cleanup
                n = j.imms[0] - later
                if nx is not None and (nx.kind == "ret" or (nx.mnemonic == "pop" and nx.regs and
                                                              nx.regs[0] in CALLEE_SAVED)):
                    # an epilogue: the frame the prologue allocated (`sub esp, 0x10`) is part of it
                    n -= self.frame_alloc()
                return n if n > 0 else None
            if j.mnemonic == "pop" and j.regs == ["ecx"] and later == 0:
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
            if j.mnemonic == "push":
                later += 4
            elif j.kind == "call":
                if j.target in IGNORED_CALLS:
                    return None         # the /GS check: the frame is released next
                # a later call of unknown arity is taken to be cdecl too: the shared cleanup then has to
                # cover its pushes as well, which the subtraction below checks
                pop = self.prog.callee_pop(j.target) if j.target is not None else 0
                later -= pop or 0
            elif j.kind != "other" or j.mnemonic in ("pop", "sub", "leave", "pushal", "popal", "pushfd",
                                                    "popfd") or (j.ops and j.ops[0] == ("reg", "esp")):
                return None             # (a store into an argument slot, [esp+n], is fine)
            a += j.size
        return None

    def pop_ret_cleanup(self, call_addr):
        """(round 13, popret) Bytes `pop ecx` (once or twice) right after a call releases when a `ret` follows
        them, else None. Whether they are the call's cleanup or the frame's release is for the caller to tell
        (cleanup_after leaves this shape alone)."""
        i = self.decode(call_addr)
        if i is None:
            return None
        a, n = call_addr + i.size, 0
        j = self.decode(a)
        while j is not None and j.mnemonic == "pop" and j.regs == ["ecx"] and n < 8:
            n += 4
            a += j.size
            j = self.decode(a)
        return n if n and j is not None and j.kind == "ret" else None

    def immediate_cleanup(self, call_addr):
        """(round 8) Bytes an `add esp, N` releases right after a call, with only plain instructions in
        between (no push, pop, call, jump or other esp change), when it isn't part of an epilogue (the next
        instruction isn't ret, jmp, pop, leave or `mov esp, ebp`). None otherwise. The strict form of
        cleanup_after: no deferred cleanups shared with later calls are guessed."""
        i = self.decode(call_addr)
        if i is None:
            return None
        a = call_addr + i.size
        for _ in range(16):
            j = self.decode(a)
            if j is None or j.kind != "other":
                return None
            if j.mnemonic == "add" and j.op_str.startswith("esp,") and j.imms:
                nx = self.decode(a + j.size)
                if nx is None or nx.kind in ("ret", "jmp", "stop") or nx.mnemonic in ("pop", "leave", "popal") or \
                        (nx.mnemonic == "mov" and nx.op_str == "esp, ebp"):
                    return None
                return j.imms[0]
            if j.mnemonic in ("push", "pop", "pushal", "popal", "pushfd", "popfd", "leave", "enter") or \
                    (j.ops and j.ops[0] == ("reg", "esp")) or "esp" in j.regs and j.mnemonic not in ("mov", "lea") or \
                    (j.mnemonic in ("mov", "lea") and j.ops and j.ops[0] == ("reg", "esp")):
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
            elif m == "mov" and i.mem is not None and not i.mem[1] and not i.mem[2] and i.mem[4] == SECURITY_COOKIE:
                ok = True   # mov eax, [__security_cookie] (the /GS prologue)
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


CONV_LOCS = ("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp", "stack")


def decl_layout(sig):
    """Where our declaration puts its arguments, in order (['ecx', 'stack', ...]), and the bytes the
    callee pops; (None, None) when the signature is unknown or has a struct passed by value."""
    if not sig or sig.get("params") is None:
        return None, None
    words = [1] if sig.get("ret") == "struct" else []
    for k in sig["params"]:
        if k == "struct":
            return None, None
        words.append(2 if k in ("f64", "i64") else 1)
    locs = ["ecx"] if sig.get("this") else []
    regs = ["ecx", "edx"] if sig.get("cc") == "fastcall" else []
    nstack = 0
    for i, w in enumerate(words):
        if regs and w == 1 and not (sig.get("ret") == "struct" and i == 0):
            locs.append(regs.pop(0))
        else:
            locs.extend(["stack"] * w)
            nstack += w
    return locs, (0 if sig.get("cc") == "cdecl" else 4 * nstack)


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
            varargs = False
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
                varargs = p.peek() == "Z"         # `...`: the list ends in Z instead of @
            return {"cc": cc, "this": has_this, "ret": ret, "params": params, "param_types": types,
                    "varargs": varargs}
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
            v = (sizes.get(v), "class") if isinstance(v, str) else v
            if v and (not isinstance(v, tuple) or v[0]):
                out.setdefault(n, {})[k] = v
    return out


_TREE_NS = re.compile(r"(?<![A-Za-z0-9_])fn_[0-9a-fA-F]{8}::")


def _safe_dname(k):
    from msvc_demangle import demangle_type_name
    try:
        return demangle_type_name(k)
    except Exception:   # noqa: BLE001
        return None


def _tree_key(mangled):
    """A mangled name without the `fn_<addr>` namespace a merged source-tree object wraps it in
    (tools/build_tree.py): (qualified name, signature), comparable with the standalone source's name.
    Back-references in mangled names are positional, so the namespace can't just be cut out of the text."""
    q = _qualified(mangled)
    if q is None and "treespecial" not in EQUIV_OFF:
        q = _qualified_special(mangled)
    if q is None:
        return None
    sig = parse_signature(mangled)
    return _TREE_NS.sub("", q), _TREE_NS.sub("", repr(sorted(sig.items()))) if sig else None


def _qualified_special(mangled):
    """(round 15, `treespecial`) '??0DrawableBase@pure3d@@QAE@XZ' -> '??0 pure3d::DrawableBase': the qualified name
    of a constructor, destructor, operator or template function (`??$`), with its special code, so `_tree_key`
    translates equiv-map lines for them too (native10's stop 17: the base constructor fell back to pairing)."""
    try:
        if mangled.startswith("??$"):
            return "??$ " + _Parser(mangled[1:]).qualified_name()
        if mangled.startswith("??_"):
            code, rest = mangled[2:4], mangled[4:]
        elif mangled.startswith("??"):
            code, rest = mangled[2], mangled[3:]
        else:
            return None
        if code in ("_7", "_8", "_R", "__"):       # vftables, vbtables, RTTI, dynamic initializers: bound elsewhere
            return None
        return "??%s %s" % (code, _Parser(rest).qualified_name())
    except (DemangleError, IndexError):
        return None


def _tree_names(obj, names):
    """{name in the standalone source: name in OBJ} for mangled names that OBJ has only inside a
    `namespace fn_<addr>` (explicit equiv-map lines and equiv-conv names of a wrapped function)."""
    have = {s[0] for s in obj.syms.values()}
    want = [n for n in names if n.startswith("?") and n not in have]
    if not want or "treens" in EQUIV_OFF:
        return {}
    keyed = defaultdict(list)
    for n in have:
        if "fn_" in n and n.startswith("?"):
            k = _tree_key(n)
            if k:
                keyed[k].append(n)
    out = {}
    for n in want:
        hits = keyed.get(_tree_key(n)) or []
        if len(hits) == 1:
            out[n] = hits[0]
    return out


def _probe_sizes(src, flags, classes):
    text = open(src, errors="replace").read()
    res = {}
    strip = "treens" not in EQUIV_OFF and not re.search(r"namespace\s+fn_[0-9a-fA-F]{8}", text)

    def attempt(cls):
        # (round 7: a merged source-tree object wraps a function's source in `namespace fn_<addr>`
        # (tools/build_tree.py); its mangled names say `fn_00040550::Link`, the standalone SRC says `Link`)
        body = text + "\nextern \"C\" const unsigned equiv_sizeof_probe[] = {%s};\n" % ", ".join(
            "sizeof(%s)" % (_TREE_NS.sub("", c) if strip else c) for c in cls)
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
# MSVC's `vector constructor iterator` & co: our compile emits its own copy (a COMDAT), the original calls the
# XBE's one out of line (FUN_00011520), so they pair like any callee instead of running in place
VECTOR_ITERATORS = ("??_H@", "??_I@", "??_L@", "??_M@")
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

    def __init__(self, prog, seed, globals_, pristine=False, dictionary=(), pointers=(), overlay=None, sentinels=()):
        self.overlay = overlay or {}       # {(epoch, addr): bytes} forced by directed inputs
        # (round 7) values a runaway walk compared its links against (`&tree.nil`): half the words of every
        # data page hold one of them, in every epoch, so list and tree walks end within a few links
        self.sentinels = tuple(sentinels)
        # memory modes: "narrow" folds every heap pointer into 512 bytes (begin/end ranges stay short);
        # "noise" fills memory with random bytes (copies and byte loads see distinct values)
        self.narrow = seed % 5 == 3
        self.noise = seed % 4 == 3
        # "stable": callees change no memory (a loop that calls something per element re-reads the same
        # bound every round, so it can end)
        self.stable = seed % 8 == 6
        self.prog = prog
        self.seed = seed
        self.globals = sorted(globals_)
        self.pristine = pristine
        self.dictionary = list(dictionary)
        self.pointers = list(pointers)
        self._cache = {}

    def page(self, page, epoch):
        if self.stable:
            epoch = 0
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
        if self.sentinels and not IMAGE_LO <= page < IMAGE_HI:
            import array
            pat = self.__dict__.get("_sent_pat")
            if pat is None:
                # (the same positions on every page and epoch: drawing them per page made every remap slow)
                import random
                rnd = random.Random(mix(self.seed, 0x5E77))
                pat = self._sent_pat = [(i, self.sentinels[rnd.randrange(len(self.sentinels))])
                                        for i in range(1024) if rnd.random() < 0.5]
            arr = array.array("I", b)
            rot = mix(page, 0x5E78) % 1024           # (shifted per page, so a field offset isn't always one)
            for i, v in pat:
                arr[(i + rot) & 1023] = v
            b = arr.tobytes()
        if self.overlay:
            hits = [(a, v) for (e, a), v in self.overlay.items()
                    if (e == epoch or e == "*" or (isinstance(e, tuple) and epoch > e[1])) and page <= a < page + PAGE]
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


X87_STORES = ("fst", "fstp", "fist", "fistp", "fisttp", "fbstp", "fnstcw", "fstcw", "fnstsw", "fstsw", "fnstenv",
              "fstenv", "fnsave", "fsave")
HIGH_BYTE = {"ah": ("eax", "ax"), "ch": ("ecx", "cx"), "dh": ("edx", "dx"), "bh": ("ebx", "bx")}
LOW_PART = {"eax": ("al", "ax"), "ecx": ("cl", "cx"), "edx": ("dl", "dx"), "ebx": ("bl", "bx")}
FARITH = ("fadd", "faddp", "fsub", "fsubp", "fsubr", "fsubrp", "fmul", "fmulp", "fdiv", "fdivp", "fdivr", "fdivrp")
FCMP = ("fcom", "fcomp", "fucom", "fucomp", "fcompp", "fucompp", "fcomi", "fcomip", "fucomi", "fucomip", "ftst")


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
        self.func_stack_written = set()
        self.reg_width = {}         # register -> bits its last write set (8 for setcc al, ...)
        self.reg_dirty = set()      # registers some instruction other than a pop has written
        self.push_width = {}        # stack slot -> bits of the register pushed there
        self.array_written = set()  # stack bytes stored like array elements (indexed, via a pointer, rep)
        self.fill_byte = {}         # stack byte -> (call, argument, -1, start) of a byte out-parameter fill
        self.fill_src = {}          # stack word -> (call, argument, offset) of the stub fill that wrote it
        self.fill_owner = {}        # stack word -> the out-parameter pointer whose fill wrote it  # ... by the function itself (not by a stub's out-param write)
        self.helper_ret = None
        self.prev_jcc = None
        self.fault = None
        self.code_write = None      # first store into code (ours or the original's .text): self-modifying
        self.cur_insn = None
        self.edges = set()
        self.executed = set()
        self.loads = {r: (("entry", r), 4, 0, r, (), None) for r in ("eax", "ecx", "edx", "ebx", "esi", "edi")}
        # register -> (address, size, epoch) it was last loaded from; entry registers are inputs too
        self.last_cmp = None
        self.prev_set = None
        self.cmp_obs = {}           # jcc -> observation of the comparison that fed it
        self.cmp_obs2 = {}          # ... the second time (a loop's next iteration)
        self.str_obs = []           # compares of a buffer with a literal in .rdata (directed inputs plant it)
        self.deref_obs = []         # (round 13, objptr) [(pointer key, its source, disp)] (directed inputs)
        self.byte_bufs = {}         # byte compare site -> (address, epoch) of the first byte it compared
        self.byte_seq = []          # constants chars were compared with, in order
        self.copy_src = {}          # stack byte -> (heap/global byte it was copied from, epoch, stack byte)
        self._str_seen = {}         # (site, literal address) -> recorded; site -> (esi, edi, ecx) of the last rep cmps
        self._str_walks = []        # (literal lo, hi, buffer - literal) of each compare recorded
        self.jcc_count = Counter()  # jcc -> times executed (hot loops of a run that timed out)
        self.varargs = set()        # callees our source declares with `...`
        self.local_entries = set()  # functions of our own object entered so far (their prologues are known)
        self.loop_limits = None     # jcc -> most rounds before the run counts as timed out (runaway loops)
        self.loop_abort = False
        self.nsteps = 0             # instructions executed (the step-budget probe sizes long loops by it)
        self.noreturn = False       # the run ended in a call to a function that never returns
        self.abs_loads = set()      # addresses read as fixed addresses (`fld [0x3f32e0]`)
        self.stack_src = {}         # stack word -> source of the register stored there (directed inputs)
        self.fstack = []            # x87 stack: where each value was loaded from (None: computed)
        self.fpu_cmp = None         # the last float comparison (read back by fnstsw/sahf or fcomi)
        self.fmem = {}              # (round 9) address -> (x87 stack entry, size, store insn) of a steerable float stored there
        self.fmem_keep = None       # (insn address, address) of a store that keeps the fmem entry (fabs in memory)
        self.ftol_pending = None    # (round 9) the steerable float a running __ftol2 converts
        self.float_loads = []       # (round 9) (epoch, address, size) of floats the x87 read from memory
        self.eq_links = {}          # (round 9) input source -> another one this run found equal to it
        self.prefill_src = {}       # (round 9) stack byte -> (call, argument) of a byte out-parameter the function had set
        self.load_pc = {}           # (round 9) register -> (instruction, address) of its last load from memory
        self.stack_pc = {}          # (round 9) stack word -> the load of the value stored there (stack_src)
        self.addr_pc = {}           # (round 9) address -> the instruction that loaded a register from it
        self.out_ptrs = []          # (round 9) (call, argument, frame address) of each local passed by pointer
        self.idx_fills = set()      # (round 10) (call, argument, offset) of stub-filled words used as a stack-array index
        self.count_pcs = None       # (round 9) loads of loop counts: a discovery run plants small values there
        self.count_plants = {}      # (round 9) (epoch, address) -> bytes planted by those loads
        self.count_diffs = {}       # (round 10) `sub end, begin` of a loop bound -> the transforms after it (discovery runs)
        self.sub_pc = {}            # (round 10) register -> (sub instruction, index of its step, source) of `end - begin`
        self.count_walks = {}       # (round 10) compare of a runaway walk -> the operand holding the sentinel (or "zero")
        self.count_tiny = False     # (round 10) discovery runs plant counts of 0 or 1 (a pair loop over everything collected)
        self.walk_rounds = Counter()    # (round 10) compare -> rounds since its last plant (discovery runs)
        self.walk_heads = {}        # (round 11, walkheads) the top test of a walk (`cmp eax, edx; je` before it) -> its compare
        self.walk_seen = {}         # (round 11) (epoch, address) of every link a walk compare loaded -> the walk that did
        self.walk_inst = Counter()  # (round 11) walk compare -> walks it ran so far (a new one at its top test or a plant)
        self.walk_prev = {}         # (round 11) walk compare -> the node its link register held at the last round
        self.walk_disp = {}         # (round 11) walk compare -> offset of the link in a node (`mov eax, [eax+0xc]`)
        self.const_src = {}         # (round 9) register -> the compare that decided the constant it holds (`mov bl, 1` after a jne)
        self.last_jcc_obs = None    # (round 9) the compare the latest jcc branched on
        self.since_jcc = 99         # (round 9) instructions since the latest jcc
        self.prologue = view.prologue()
        self.pointee_sizes = {}     # callee address -> {arg index: bytes}
        self.intrinsics = {}        # unresolved CRT symbol address -> name, executed semantically
        self.local_code = None      # (lo, hi) of our object's own code, executed rather than stubbed
        self.slot_arity = None      # (unused)
        self.ecx_dirty = False      # ecx written since entry or the last call
        self.last_insn = None       # (address, eflags) of the previous instruction hook
        self.rmw_undo = None        # (round 14, rmwundo) (insn address, [(address, old bytes)]) of a read-modify-write's stores
        self.prev_esp = ENTRY_ESP
        self.convs = {}             # callee address -> argument locations (// equiv-conv)
        self.orig_entry = None      # the original's address of the function under test
        self.addr_taken = set()     # stack addresses the function computed with lea (starts of its objects)
        self.self_alias = None      # our run: the original's address of the function under test
        self.huge_rep = False       # a rep string instruction ran with a count over 4 MB
        self.max_mapped = 0         # most pages mapped at once (memory-hungry runs)
        self.abi_mismatch = None    # (call index, callee, bytes our declaration pops, bytes it really pops)
        self.cookies = set()        # values read from the /GS cookie global
        self.cdecl_site = False     # (round 8) the current call is proven cdecl by the caller's cleanup
        self.smashed = None         # (round 8) where a store overran into the return address or a saved register
        self.cdecl_slots = set()    # (operand, address) of the fields indirect calls proven cdecl went through
        self.eax_def = None         # what last set eax: ("call" | "insn", bits), and whether code read it since
        self.eax_read = False
        self.eax_vread = False      # (round 8) ... read as a value, not only dereferenced
        self.cookie_bad = None      # the cookie check got something else in ecx (before call #n)
        self.decls = {}             # callee address -> our declaration's signature (our run only)
        self.caller_cleans = set()  # callees with a plain ret whose original callers pop the arguments
        self.ax_status = False      # ax's upper bytes last came from fnstsw (a float branch's status word)
        self.wild_check = False     # stop at control flow that leaves known code (fault:wild_jump/wild_call)
        self.rep_obs = None         # the first rep string instruction with a huge count: where ecx came from
        self.fill_pre = {}          # (call, arg, offset) -> the function's own word a callee-extent fill replaced
        self.fill_watch = {}        # stack byte -> such a fill, until the function rewrites it
        self.fill_readback = set()  # fills whose replaced word the function read back before rewriting it

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
        # (round 11, x87args) [0xC00 + 2 * (3 - n)]: n x `fstp st(0)` (a callee's x87 register arguments), then on
        # to the trampoline whose address is at FSLOT + 0x10
        tr[0xC00:0xC0C] = b"\xdd\xd8" * 3 + b"\xff\x25" + struct.pack("<I", FSLOT + 0x10)
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
        ci0 = self.cur_insn
        if size > 1 and addr & (size - 1) and ci0 is not None and ci0.mnemonic in RMW_MNEMS and ci0.mem is not None and \
                "rmwundo" not in EQUIV_OFF:
            # (round 14, rmwundo) the unaligned store of a read-modify-write instruction: remember the bytes it replaces.
            # Unicorn can restart such an instruction after its store (the code hook fires again for the same address,
            # 0x0025b970's `inc dword [0x27]`): the re-execution would apply `inc` twice (_on_code puts them back).
            # Unaligned only: it is the one case seen, and a read of the old bytes at every aligned `add [m], r` slows
            # the Bink decoder (0x003341e0) by a third
            try:
                old_ = bytes(uc.mem_read(addr, size))
            except Exception:   # noqa: BLE001
                old_ = None
            if old_ is not None:
                if self.rmw_undo is None or self.rmw_undo[0] != ci0.addr:
                    self.rmw_undo = (ci0.addr, [])
                self.rmw_undo[1].append((addr, old_))
        if self.fmem:
            # (round 9, fprov) a stored steerable float overwritten by anything but its own store (or a fabs
            # mask applied in memory, `and dword [esp+4], 0x7fffffff`) is no longer that value
            ci = self.cur_insn
            for x in [x for x, e in self.fmem.items() if x < addr + size and addr < x + e[1]]:
                if ci is not None and (ci.addr == self.fmem[x][2] or self.fmem_keep == (ci.addr, x)):
                    continue
                self.fmem.pop(x, None)
        if STACK_LO <= addr < STACK_HI:
            ci = self.cur_insn
            if self.smashed is None and ci is not None and ci.mnemonic not in ("push", "call", "pushal", "pushfd") \
                    and "smash" not in EQUIV_OFF and addr < ENTRY_ESP + 4 and \
                    (ci.mnemonic.startswith(("rep", "stos", "movs")) or
                     (ci.mem is not None and (ci.mem[2] or ci.mem[1] not in ("esp", "ebp")))):
                # (round 8, smash) an array-style store (indexed, through a pointer, a string instruction) over
                # the return address or a live saved-register slot: a buffer overrun (`buf[len] = 0` with a
                # fuzzed len), undefined behaviour no real input causes. (Plain `mov [esp+k]` stores are left
                # alone: an argument word pushed once and rewritten for the next call can look like a save.)
                hit = range(addr & ~3, addr + size, 4)
                if any(x == ENTRY_ESP or (x in self.save_slots and x >= self.reg("esp")) for x in hit):
                    self.smashed = ci.addr
            if ci is not None and ci.kind == "call" and self.helper_ret is None:
                self.save_slots.update(range(addr & ~3, addr + size, 4))   # a return address: never data
            elif self.helper_ret is not None:
                pass        # _chkstk/_ftol scratch: not data the function wrote
            elif not (ci is not None and ci.mnemonic == "push" and ci.addr in self.prologue):
                self.stack_written.update(range(addr, addr + size))    # (prologue pushes allocate/save)
                self.func_stack_written.update(range(addr, addr + size))
                if ci is not None and ci.mnemonic not in ("push", "call") and (
                        ci.mnemonic.startswith(("rep", "stos", "movs")) or
                        (ci.mem is not None and (ci.mem[2] or ci.mem[1] not in ("esp", "ebp")))):
                    self.array_written.update(range(addr, addr + size))     # indexed/pointer/string store
                for x in range(addr & ~3, addr + size, 4):
                    self.fill_src.pop(x, None)
                for x in range(addr, addr + size):
                    self.fill_byte.pop(x, None)
                    if self.prefill_src:
                        self.prefill_src.pop(x, None)
                if self.fill_watch:
                    for x in range(addr, addr + size):
                        self.fill_watch.pop(x, None)
            if self.cur_insn is not None and self.cur_insn.is_fpu_store:
                self.stack_fpu[addr] = size
            else:
                for a in range(addr & ~3, addr + size, 4):
                    self.stack_fpu.pop(a, None)
            return
        if TIB <= addr < TIB + PAGE:
            return
        if self.code_write is None and (OURS <= addr < OURS + OURS_SIZE or self.prog.text[0] <= addr < self.prog.text[1]):
            self.code_write = addr      # a fuzzed pointer into code: the store changes one side's instructions
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
        if a > M32 - 3:
            # wraps around like the CPU's own access (Unicorn's mem_read doesn't: `call [ebx]` with ebx -1
            # read a different word than ours' `mov ebx, [ebx]`)
            return struct.unpack("<I", self._mem(a, 4))[0]
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
        self.max_mapped = max(self.max_mapped, len(self.mapped))
        if self.m.stable:
            return
        self.epoch += 1
        if self.fmem:       # (round 9) floats stored outside the stack are fresh memory now
            self.fmem = {x: e for x, e in self.fmem.items() if STACK_LO <= x < STACK_HI}
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

    def _is_virtual_on_ecx(self, insn):
        """call [reg+disp] where reg holds ecx's vptr: a virtual call, so ecx is its `this`."""
        if insn.mem is None or insn.mem[1] in (None, "esp", "ebp") or insn.mem[2] is not None:
            return False
        ecx = self.reg("ecx")
        if not (self.ecx_dirty or ecx == self.inp["regs"]["ecx"]):
            return False        # ecx is a leftover (e.g. from the previous stub), not a receiver
        try:
            return self.reg(insn.mem[1]) == self._read_u32(ecx)
        except Exception:
            return False

    def _stub(self, insn, target, tail):
        u = self.u
        uc = self.uc
        esp = self.reg("esp")
        self.save_slots = {x for x in self.save_slots if x >= esp}     # slots below esp are dead
        self.cdecl_site = False
        # Callee facts only for real call sites: a target read from fuzzed memory is just a number.
        known = insn.target is not None or (insn.mem is not None and insn.mem[1] is None and insn.mem[2] is None)
        p = self.prog.callee_pop(target) if known else None
        if tail:
            argbase = esp + 4
            if p is None:
                p = 4 * len(self.inp.get("own_args", [])) if self.inp.get("own_pop") is None else self.inp["own_pop"]
            nargs = p // 4 if p else len(self.inp.get("own_args", []))
            if self.convs.get(self.orig_entry) and "tailconv" not in EQUIV_OFF:
                # (round 7) a tail call out of an equiv-conv function: each side passes on its own incoming
                # stack words (ours has the C++ declaration's, the original the annotation's), so as many as
                # the original's call passes are compared
                learned_t = self.inp.setdefault("tail_arity", {})
                if self.coverage:
                    learned_t[len(self.calls)] = nargs
                elif len(self.calls) in learned_t:
                    nargs = learned_t[len(self.calls)]
            stack_words = nargs
        else:
            argbase = esp
            cleanup = self.view.cleanup_after(insn.addr)
            if cleanup is None and "popret" not in EQUIV_OFF:
                # (round 13, popret) `call [eax]; pop ecx; ret 4` (fx14 0x0026dc20): cleanup_after takes
                # `pop ecx` before a ret for an epilogue, and an unknown-arity call was then assumed to pop its
                # words, so the pop took the return address and every input went wild. When the pops land
                # exactly on this run's return-address slot with the call's words left on the stack, they
                # are the cdecl cleanup (a callee-popped call would leave the pops short of it: a `push ecx`
                # frame released by the same pop)
                n_ = self.view.pop_ret_cleanup(insn.addr)
                if n_ and esp + n_ == ENTRY_ESP:
                    cleanup = n_
            tracked = sorted(s for s in self.tracked if s >= esp)
            if not known and tracked and "ccall" not in EQUIV_OFF:
                # (round 8) an indirect call whose caller releases every word pushed for it right after the
                # call (`push esi; call [ecx+0xc]; add esp, 4`): the callee left its arguments on the stack.
                # Only cdecl does that (thiscall, stdcall and fastcall pop theirs; a member function with
                # `...` is cdecl with `this` pushed), so the callee doesn't take ecx. Were it callee-popped,
                # the `add esp` would release words below the frame's pending pushes, which MSVC never emits.
                ic = self.view.immediate_cleanup(insn.addr)
                self.cdecl_site = ic is not None and ic == 4 * len(tracked)
                # A call through the same field (the same operand, `call [esi+4]` again, at the same address,
                # not on the stack, whose slots are reused) has the same pointer type, whatever value it
                # holds now (memory is re-read after each call): the proof carries over to a call through it
                # whose cleanup is shared with the next call's (Lua's DumpFunction: `call [esi+4]; ...;
                # push x4; call [esi+4]; add esp, 0x20`).
                slot = None
                if insn.mem is not None and insn.mem[1] not in ("esp", "ebp") and insn.mem[0] is None:
                    ea_ = self._ea(insn.mem)
                    if not STACK_LO <= ea_ < STACK_HI:
                        slot = (insn.mem[1:5], ea_)
                if slot is not None:
                    if self.cdecl_site:
                        self.cdecl_slots.add(slot)
                    elif slot in self.cdecl_slots:
                        self.cdecl_site = True
            else:
                self.cdecl_site = False
            semantic = self.prog.callee_stack_args(target) if known else None
            # (round 11, ptrpop) a call through a fixed function pointer (`call [0x4de948]`) whose target is not
            # code (a fuzzed global): the pointer's other call sites tell its stack use. With `push 0; call
            # [g]; push ecx; ...; call [esi+0x18]` the 0 is the virtual call's second argument when g takes none
            ptrkind = None
            if known and p is None and insn.target is None and insn.mem is not None and \
                    "ptrpop" not in EQUIV_OFF:
                ptrkind = self.prog.ptr_call_pop(insn.mem[4])
                if ptrkind is not None:
                    p = 0
            # unknown arity: what the caller does with the pushed words afterwards decides (released by a
            # later `add esp`: caller-cleaned; popped or read by a later call they were pushed for)
            pu = None
            if p is None and tracked:
                pu = (self.view.join_balance(insn.addr, len(tracked)) if "join" not in EQUIV_OFF else None) or \
                    self.view.pending_use(insn.addr, len(tracked))
            if ptrkind == "noargs":
                nargs = 0
            elif p is not None and p > 0:
                nargs = p // 4
            elif p == 0 or (cleanup and pu is None):
                p = 0
                if cleanup:
                    nargs = min(cleanup // 4, len(tracked)) if tracked else cleanup // 4
                else:
                    nargs = len(tracked)
                    # nobody pops after this call: pending pushes that the next call pops belong to it
                    # (`push eax; call <ret 0>; push eax; call <ret 8>`)
                    nxt = self.view.next_call_pop(insn.addr)
                    if nargs and nxt is not None and nxt[0] >= 4 * nargs + nxt[1]:
                        nargs = 0
            else:
                nargs = len(tracked)
                p = 4 * nargs
                if pu is not None:
                    if pu[0] == "caller":
                        p = 0
                    elif pu[0] == "reader":
                        nargs, p = pu[1], 0
                    else:
                        nargs = pu[1]
                        p = 4 * nargs
                else:
                    nxt = self.view.next_call_pop(insn.addr)
                    if nargs and nxt is not None and nxt[0] >= p + nxt[1]:
                        nargs, p = 0, 0          # the pending pushes belong to the outer call (it pops them all)
                # an indirect call of unknown arity: our k-th call reuses what the original's k-th call
                # did on the same input, so argument pushes interleaved with an outer call in our code
                # don't change the count (if the traces differ, they fail on the target anyway). Where our
                # own code shows who takes the words, that decides our stack instead.
                k_call = len(self.calls)
                learned = self.inp.setdefault("arity_by_call", {})
                if self.coverage:                   # the original's run
                    learned[k_call] = (p, nargs)
                elif k_call in learned:
                    # our stack follows our own code (a virtual call we declare as a thiscall member pops its
                    # arguments where the original's caller cleaned them up: the target is unknown either
                    # way); compare as many words as the original's call took
                    nargs = learned[k_call][1]
            # a caller-cleaned callee takes only the words it reads: pushes above them are pending for a
            # later call (`push eax; call getter; push eax; ...; call snprintf; add esp, 0x14`)
            take = min(nargs, semantic) if semantic is not None and p == 0 else nargs
            self.tracked -= set(tracked[:take])
            stack_words = nargs           # the words this call site passes (varargs: per call site)
            if semantic is not None and p is not None:
                nargs = semantic          # compare what the callee actually reads
            if self.view.is_ours and insn.target is not None and target in self.decls:
                dl, dpop = decl_layout(self.decls[target])
                real = self.prog.callee_pop(target)
                if dpop is not None and target in self.convs:
                    p = dpop          # a declared convention (equiv-conv): our stack follows our declaration
                    if not tail and dl:
                        # the stack words our declaration passes are this call's, even where the real
                        # callee reads none of them (a register argument we pass on the stack): not pending
                        # words for the next call when our cleanup is deferred
                        self.tracked -= set(tracked[:dl.count("stack")])
                elif dpop is not None and real is not None and dpop != real:
                    # Our declaration pops differently from the real callee: linked against the real
                    # function, our stack would drift (e.g. `this` in ecx plus caller-popped arguments,
                    # declared as an ordinary thiscall member). The real callee decides.
                    self.abi_mismatch = self.abi_mismatch or (len(self.calls), target, dpop, real)
                    p = real
        args, argw = [], []
        for k in range(min(nargs, 32)):
            a = argbase + 4 * k
            v = self._read_u32(a)
            args.append((v, self.stack_fpu.get(a)))
            argw.append(self.push_width.get(a, 32))
        conv = self.convs.get(target) if known else None
        if conv:
            # a declared convention: compare the arguments as a list, wherever each side passes them
            if self.view.is_ours:
                layout = (decl_layout(self.decls.get(target))[0] if insn.target is not None else None) or []
                layout = (layout + ["stack"] * len(conv))[:len(conv)]
            else:
                layout = conv
            args, si = [], 0
            argw = []
            for li, loc in enumerate(layout):
                if loc == "stack":
                    a = argbase + 4 * si
                    si += 1
                    args.append((self._read_u32(a), self.stack_fpu.get(a)))
                    argw.append(self.push_width.get(a, 32) if "partreg" not in EQUIV_OFF else 32)
                else:
                    args.append((self.reg(loc), None))
                    # (round 7) a byte flag passed in cl over whatever the caller left in the high bytes: as
                    # many bits as the real callee reads of the register the original passes it in
                    creg = conv[li] if li < len(conv) else None
                    argw.append(self.prog.reg_read_width(target, creg) if creg in Program._SUBREGS and
                                "partreg" not in EQUIV_OFF else 32)
            # words this call passes beyond the annotated ones (a callee we declare varargs): as many as the
            # original's call site passes (its pushes), compared word by word
            n_extra = 0
            if target in self.varargs and not tail:
                learned_x = self.inp.setdefault("extra_by_call", {})
                if self.coverage:
                    n_extra = learned_x[len(self.calls)] = max(0, min(stack_words, 32) - si)
                else:
                    n_extra = learned_x.get(len(self.calls), 0)
            for k_ in range(si, si + n_extra):
                a = argbase + 4 * k_
                args.append((self._read_u32(a), self.stack_fpu.get(a)))
        k = len(self.calls)
        # locals passed by pointer: the callee may read them, so their contents are part of the call
        # our frame, including the incoming argument slots (MSVC reuses dead parameters as locals)
        arg_hi = ENTRY_ESP + 4 + 4 * len(self.inp["stack"])
        in_frame = lambda v: esp <= v < ENTRY_ESP or ENTRY_ESP + 4 <= v < arg_hi
        # (register arguments too, e.g. a constant vector in edx; not `this` in ecx, whose stack slot is
        # often scratch reused from dead locals before the object is set up by the callee)
        sp = sorted({v for v, _ in args if in_frame(v)} |
                    {self.reg(r) for r in ("eax", "edx") if in_frame(self.reg(r))})
        declared = self.pointee_sizes.get(target, {})
        argidx = {}
        for j, (v, _) in enumerate(args):
            argidx.setdefault(v, j)
        def snap(v, size, is_class, depth=0):
            limit = min([POINTEE_WINDOW, (ENTRY_ESP if v < ENTRY_ESP else arg_hi) - v] +
                        [x - v for x in self.save_slots if x > v])
            # an array grows at most up to the next local whose address the function takes (another object)
            grow = min([limit] + [x - v for x in self.addr_taken if x > v] + [x - v for x in sp if x > v])
            # extent: a class is compared over exactly its sizeof. A scalar or unknown pointer may point at
            # an array: grow over words the function itself wrote (a callee's out-param writes don't
            # count, so neighbouring out-parameters stay out)
            ext = 0
            if not is_class:
                # past ARRAY_WINDOW only over words stored like array elements: neighbouring scalars written
                # at fixed frame offsets are other locals, laid out differently in ours
                while ext + 4 <= grow and any(x in (self.func_stack_written if ext < ARRAY_WINDOW else
                                                    self.array_written) for x in range(v + ext, v + ext + 4)):
                    ext += 4
            data = bytes(self.uc.mem_read(v, limit))
            n_ = min(limit, max(size, ext))
            nested = {}
            if depth < 2:
                # a local that holds a pointer to another local (desc.format = &fmt): the callee reads that too
                for off in range(0, n_ - 3, 4):
                    w = struct.unpack_from("<I", data, off)[0]
                    if in_frame(w) and w != v and any(x in self.func_stack_written for x in range(v + off, v + off + 4)):
                        nested[off] = snap(w, DEFAULT_POINTEE, False, depth + 1)
            return (data, {a - v: sz for a, sz in self.stack_fpu.items() if v <= a < v + limit},
                    {a - v for a in range(v, v + limit) if a in self.stack_written}, n_, nested)
        pointees = {}
        for n, v in enumerate(sp):
            size = declared.get(argidx.get(v), DEFAULT_POINTEE)
            is_class = isinstance(size, tuple)
            pointees[v] = snap(v, size[0] if is_class else size, is_class)
        fdepth = 0
        if "fdepth" not in EQUIV_OFF:
            fdepth = (8 - ((uc.reg_read(u.UC_X86_REG_FPSW) >> 11) & 7)) % 8
        # (round 11, x87args) a callee that takes x87 register arguments (`fld x; fld e; call __CIpow`) replaces
        # them with its result: they were not values kept across the call, and the code after it uses the result
        x87n = min(self.prog.x87_args(target), fdepth) if known and not tail and "x87args" not in EQUIV_OFF else 0
        fret = True if x87n else self.view.float_ret_after(insn.addr, self.own_float_ret, fdepth)
        # (round 12, x87cmp) the x87 register arguments themselves (`fld x; call __CIasin`): inputs of the call like
        # its stack words, compared with the float tolerance; an argument the caller never loaded is None
        x87a = []
        if known and not tail and "x87cmp" not in EQUIV_OFF:
            x87a = [self._st_val(i) if i < fdepth else None for i in range(self.prog.x87_args(target))]
        h = mix(self.inp["seed"], 0xCA11, k)
        d = self.inp.get("dictionary")
        mode = self.inp.get("stub_mode")
        if k in self.inp.get("ret_override", {}):
            eax = self.inp["ret_override"][k]
        elif mode == "zero":
            eax = 0
        elif mode == "one":
            eax = 1
        else:
            eax = d[(h >> 8) % len(d)] if d and h & 1 else fuzz_value(h)
        # a constructor (or any callee that returns its incoming ecx on every path) gives back `this`:
        # `Cue *c = new (buf) Cue(...); use(c)` uses eax where the original recomputes `lea ecx, [buf]`
        # (only callees that also write through ecx: constructors. A stubbed accessor that returns its this,
        # `mov eax, ecx; ret`, keeps a stub result: a fuzzed or zero pointer lets the code after it reach
        # its empty-container paths, and both sides see the same value either way)
        ret_this = insn.target is not None and not tail and "this" not in EQUIV_OFF and \
            self.prog.returns_this(target) and self.prog.callee_writes(target).get("ecx", 0) > 0
        if ret_this:
            eax = self.reg("ecx")
        edx = fuzz_value(mix(self.inp["seed"], 0xCA12, k))
        fv = FLOATS[mix(self.inp["seed"], 0xCA13, k) % len(FLOATS)]
        if self.inp.get("stub_floats") is not None:
            fv = _stub_float(self.inp["stub_floats"], k)
        elif target in self.inp.get("fret_unit", ()):
            h_ = mix(self.inp["seed"], 0xF7A1, k)       # (round 11, ftolunit) a fraction: 0, 1 or in between
            fv = (0.0, 1.0)[h_ & 1] if h_ % 8 == 0 else (h_ >> 8) % 1000 / 1000.0
        if k in self.inp.get("fret_override", {}):
            fv = self.inp["fret_override"][k]        # a directed input's float result for this call
        self.calls.append({"target": target, "args": args, "regs": {r: self.reg(r) for r in Program._REGS},
                           "float_ret": fret, "at": insn.addr, "tail": tail, "pointees": pointees, "known": known,
                           "ret_to": insn.addr + insn.size,
                           "conv": bool(conv), "argw": argw, "esp": esp,
                           "via_object": self._is_virtual_on_ecx(insn), "cdecl_site": self.cdecl_site,
                           "x87args": x87a})
        self._close_segment()
        self._perturb()
        if not tail:
            # out-parameters: the callee fills any local it got a pointer to. Write the declared size (at
            # least ARRAY_WINDOW bytes), but only words the function hasn't written itself (so initialised
            # neighbours are left alone), with the same values on both sides.
            # Out-parameters. Every local passed by pointer gets its first word written. A class
            # parameter is filled over its whole sizeof. Other pointers may point at an array: words
            # up to ARRAY_WINDOW bytes are filled too, but only words nobody has written yet. Uninitialised
            # memory can't be live data, so this never clobbers a neighbour, whatever the frame layout.
            # Values depend only on (call, argument, offset), so both sides agree.
            declared = self.pointee_sizes.get(target, {})
            vext = self._vslot_room(insn, k, p, args, in_frame, sp) if "vext" not in EQUIV_OFF else {}
            outs = []
            for j, (v, _) in enumerate(args):
                if in_frame(v) and v % 4 == 0:
                    sz = declared.get(j, 4)
                    if j in vext and not isinstance(sz, tuple):
                        sz = max(sz, vext[j])
                    exact_size = isinstance(sz, tuple)        # a class: its sizeof is the whole object
                    sz = sz[0] if exact_size else max(sz, ARRAY_WINDOW)
                    top = ENTRY_ESP if v < ENTRY_ESP else arg_hi
                    hi = min([v + sz, top] + [x for x in self.save_slots if x > v])
                    outs.append((j, v, hi, exact_size))

            def put(w, j, off, owner):
                h = mix(self.inp["seed"], 0x0B7, k, j) if off == 0 else mix(self.inp["seed"], 0x0B7, k, j, off)
                word = bytearray(struct.pack("<I", fuzz_value(h)))
                if self.inp.get("stub_floats") is not None:      # (directed: every stub float alike)
                    # (+v/-v by turns per filled object: two vectors filled one after the other point
                    # opposite ways)
                    order = self.__dict__.setdefault("_fill_order", {}).setdefault((k, j), len(self._fill_order))
                    word = bytearray(struct.pack("<f", _stub_float(self.inp["stub_floats"], order)))
                for (k_, j_, off_, bi, sz), val in self.inp.get("fill_override", {}).items():
                    if (k_, j_, off_) == (k, j, off):           # a directed input's value for this word
                        word[bi:bi + sz] = (val & ((1 << (8 * sz)) - 1)).to_bytes(sz, "little")[:4 - bi]
                uc.mem_write(w, bytes(word))
                self.fmem.pop(w, None)
                self.fmem.pop(w - 4, None)
                self.stack_written.update(range(w, w + 4))
                self.fill_owner[w] = owner
                self.fill_src[w] = (k, j, off)
            for j, v, hi, exact_size in outs:
                put(v, j, 0, v)
            firsts = {v for _, v, _, _ in outs}
            for j, (v, _) in enumerate(args):
                if in_frame(v) and v % 4 and not any(x in self.func_stack_written for x in range(v, v + 1)):
                    # a byte out-parameter at an odd offset (`char found, flagA, flagB` passed by pointer):
                    # the callee writes its byte, nothing more (its neighbours are other out-parameters)
                    sz = declared.get(j, 1)
                    sz = 1 if isinstance(sz, tuple) or not 0 < sz < 4 else sz
                    b = bytearray(struct.pack("<I", fuzz_value(mix(self.inp["seed"], 0x0B7, k, j))))
                    for (k_, j_, off_, bi, n_), val in self.inp.get("fill_override", {}).items():
                        if (k_, j_, off_) == (k, j, -1):          # (-1: a byte fill, bi counts from v)
                            b[bi:bi + n_] = (val & ((1 << (8 * n_)) - 1)).to_bytes(n_, "little")[:4 - bi]
                    uc.mem_write(v, bytes(b[:sz]))
                    self.stack_written.update(range(v, v + sz))
                    for x in range(v, v + sz):
                        self.fill_byte[x] = (k, j, -1, v)
                elif in_frame(v) and v % 4 and "pfill" not in EQUIV_OFF and self.coverage is not None:
                    # (round 9, pfill) a byte out-parameter the function set itself before the call (`char hit =
                    # 0; vt->query(&a, &b, &hit)`): random inputs keep its value (the callee may leave it alone),
                    # a directed input can have the callee write it, on both sides alike (below)
                    self.prefill_src[v] = (k, j)
            for j, v, hi, exact_size in outs:
                for w in range(v + 4, hi - 3, 4):
                    if w >= ENTRY_ESP:
                        break                                   # never into the caller's argument slots
                    # free words: never written, or filled earlier for this same pointer (not the function's
                    # data, not another out-parameter's), so the result doesn't depend on the frame layout
                    free = w not in firsts and not any(x in self.func_stack_written for x in range(w, w + 4)) \
                        and (self.fill_owner.get(w, v) == v or not any(x in self.stack_written for x in range(w, w + 4)))
                    if exact_size or free:
                        put(w, j, w - v, v)
            self._callee_extent(insn, target, known, conv, k, argbase, put, in_frame, firsts)
            for (k_, j_), val in self.inp.get("pfill_override", {}).items():
                # (round 9, pfill) the byte the directed input has the callee write, whatever the pointer's
                # alignment on this side (ours may keep the flag in an aligned slot)
                if k_ == k and j_ < len(args) and in_frame(args[j_][0]):
                    uc.mem_write(args[j_][0], bytes([val & 0xFF]))
                    self.stack_written.add(args[j_][0])
            if "xfill" not in EQUIV_OFF:
                for j, (v, _) in enumerate(args):
                    if in_frame(v) and v % 4 == 0 and v < ENTRY_ESP and len(self.out_ptrs) < 256:
                        self.out_ptrs.append((k, j, v))
                for (k_, j_, off_, bi, sz), val in self.inp.get("fill_override", {}).items():
                    # (round 9, xfill) a directed input has the callee write a word past the window filled for
                    # every call (`read(&hdr, 0x1f, 4, 1)` fills 124 bytes; the fourCC at +0x48 decides a switch)
                    if k_ != k or j_ >= len(args) or off_ < ARRAY_WINDOW:
                        continue
                    v = args[j_][0]
                    if not in_frame(v) or v >= ENTRY_ESP:
                        continue
                    w = v + off_
                    room, _ = self._frame_room(v)
                    if off_ + 4 > room or self.fill_src.get(w, (None,))[0] == k:
                        continue
                    word = bytearray(self.uc.mem_read(w, 4))
                    word[bi:bi + sz] = (val & ((1 << (8 * sz)) - 1)).to_bytes(sz, "little")[:4 - bi]
                    uc.mem_write(w, bytes(word))
                    self.fmem.pop(w, None)
                    self.stack_written.update(range(w, w + 4))
                    self.fill_src[w] = (k, j_, off_)
        if conv and self.view.is_ours:
            # the callee receives its register arguments where the annotation says (as an adapter would put
            # them), so a register it preserves holds that argument afterwards, as in the original
            for li, loc in enumerate(conv):
                if loc in ("eax", "ecx", "edx") and li < len(args):     # (an adapter restores callee-saved ones)
                    uc.reg_write(_uc_regs()[loc], args[li][0])
        # a register the callee never writes keeps its value (the caller may rely on that)
        clobbers = self.prog.reg_writes(target) if known else None
        if clobbers is None:
            clobbers = {"eax", "ecx", "edx"}
        if "eax" in clobbers:
            uc.reg_write(u.UC_X86_REG_EAX, eax)
            self.eax_def, self.eax_read, self.eax_vread = ("call", 32), False, False
            self.ax_status = False
            if self.coverage and not ret_this:
                self.loads["eax"] = (("ret", k), 4, self.epoch, "eax", (), eax)     # for directed inputs
        if "edx" in clobbers:
            uc.reg_write(u.UC_X86_REG_EDX, edx)
        if "ecx" in clobbers:
            uc.reg_write(u.UC_X86_REG_ECX, fuzz_value(mix(self.inp["seed"], 0xCA14, k)))
            self.ecx_dirty = False
        if not tail:
            esp -= 4
            uc.mem_write(esp, struct.pack("<I", insn.addr + insn.size))
            uc.reg_write(u.UC_X86_REG_ESP, esp)
        if p % 4 or p > 0x10000:
            raise Fault("odd_pop_%d" % p)
        if fret:
            uc.mem_write(FSLOT, struct.pack("<f", fv))
            if x87n and self.coverage is not None:
                del self.fstack[:x87n]
            if self.coverage is not None:
                # the float result lands in st0: a float comparison on it can be steered (directed inputs)
                self.fstack.insert(0, {"val": struct.unpack("<f", struct.pack("<f", fv))[0],
                                       "src": (("fret", k), 4, self.epoch), "float": True})
                del self.fstack[8:]
        if p > 0xFC:
            # more than the trampolines' `ret N` covers (a struct passed by value): return to the caller
            # from here, after the trampoline's float load (if any) with a plain ret
            ret_addr = self._read_u32(esp)
            uc.mem_write(esp + p, struct.pack("<I", ret_addr))
            uc.reg_write(u.UC_X86_REG_ESP, esp + p)
            p = 0
        if x87n:
            uc.mem_write(FSLOT + 0x10, struct.pack("<I", TRAMP + 0x800 + (p // 4) * 16))
            uc.reg_write(u.UC_X86_REG_EIP, TRAMP + 0xC00 + 2 * (3 - x87n))
            return
        uc.reg_write(u.UC_X86_REG_EIP, TRAMP + (0x800 if fret else 0) + (p // 4) * 16)

    def _vslot_room(self, insn, k, p, args, in_frame, sp):
        """(round 12, vext) A virtual call (`call [eax+0x14]`, eax = ecx's vptr) whose target is fuzzed: the
        implementations in that vtable slot with the same stack use write up to N bytes through a pointer
        argument (pure3d's loaders' `create` write a 64-bit id). The original's run takes, per local passed, the
        biggest extent VEXT_SHARED implementations share that fits the original's free room there
        (bytes up to the next word it wrote itself, another local whose address it took, a saved register or
        the return address); ours must have that much room before a saved register or its return address.
        {argument index: bytes}, for the out-parameter fill."""
        learned = self.inp.setdefault("vext_by_call", {})
        if self.coverage is not None:
            rec = {}
            m = insn.mem
            if insn.target is None and m is not None and m[1] not in (None, "esp", "ebp") and m[2] is None and \
                    p and self.calls[-1].get("via_object"):
                tgt = self.calls[-1]["target"]
                if tgt in self.prog.funcs:
                    # (a real target, as in trace replay: its own extent, not the slot's)
                    vs = {j: [w] * VEXT_SHARED for j, w in (self.prog.callee_writes(tgt) or {}).items()
                          if isinstance(j, int) and w}
                else:
                    vs = self.prog.vslot_writes(m[4], p)
                for j, ws in vs.items():
                    if j >= len(args) or not in_frame(args[j][0]) or args[j][0] >= ENTRY_ESP:
                        continue
                    v = args[j][0]
                    room, _ = self._frame_room(v)
                    room = min([room] + [x - v for x in self.addr_taken if x > v] + [x - v for x in sp if x > v])
                    for o in range(4, room, 4):
                        if any(x in self.func_stack_written for x in range(v + o, v + o + 4)):
                            room = o
                            break
                    ok = [w for w in ws if w <= room]
                    shared = [w for w in ok if ok.count(w) >= VEXT_SHARED]
                    if shared and max(shared) > 4:
                        rec[j] = max(shared)
            learned[k] = rec
            return rec
        rec = learned.get(k, {})
        for j, need in rec.items():
            if j < len(args) and in_frame(args[j][0]) and args[j][0] < ENTRY_ESP:
                v = args[j][0]
                room, what = self._frame_room(v)
                for o in range(4, min(room, need), 4):
                    if any(x in self.func_stack_written for x in range(v + o, v + o + 4)):
                        room, what = o, "a local it set before the call"
                        break
                if room < need:
                    self.calls[-1].setdefault("overflow", []).append((j, need, room, what))
        return rec

    def _check_readback(self, insn):
        """A read of a stack word whose own earlier value a callee-extent fill replaced (fill_watch)."""
        m = insn.mnemonic
        rngs = []
        if m.startswith(("rep", "movs", "lods", "cmps", "scas")) or m in ("movsb", "movsw", "movsd"):
            sz = {"b": 1, "w": 2, "d": 4}.get(m[-1], 4)
            n = self.reg("ecx") if m.startswith("rep") else 1
            n = min(n, 0x1000)
            if "movs" in m or "lods" in m or "cmps" in m:
                rngs.append((self.reg("esi"), sz * n))
            if "cmps" in m or "scas" in m:
                rngs.append((self.reg("edi"), sz * n))
        elif insn.mem is not None and m not in ("lea", "nop"):
            write_only = insn.ops and insn.ops[0][0] == "mem" and (
                m in ("mov", "fst", "fstp", "fist", "fistp", "fisttp", "fnstcw", "fnstsw", "fstcw", "fnsave",
                      "pop") or m.startswith("set"))
            if not write_only:
                rngs.append((self._ea(insn.mem), insn.mem[5] or 4))
            if m == "push" and insn.ops and insn.ops[0][0] == "mem":
                pass
        if m == "pop" and not (insn.ops and insn.ops[0][0] == "mem"):
            rngs.append((self.reg("esp"), 4))
        for a, n in rngs:
            for x in range(a, a + n):
                f = self.fill_watch.get(x)
                if f is not None:
                    self.fill_readback.add(f)

    def _frame_room(self, v):
        """Bytes from stack address v up to the next thing that isn't free frame space (a saved register,
        a return address, the top of our locals or of our declared arguments), and what that thing is."""
        nargs = len(self.inp.get("own_args", []))
        if v < ENTRY_ESP:
            top, what = ENTRY_ESP, "the return address"
        else:
            top, what = ENTRY_ESP + 4 + 4 * nargs, "the caller's frame"
        above = [x for x in self.save_slots if x > v]
        if above and min(above) < top:
            top, what = min(above), "a saved register or return address"
        return top - v, what

    def _callee_extent(self, insn, target, known, conv, k, argbase, put, in_frame, firsts):
        """The real callee writes this far through a pointer to one of our locals (callee_writes). The
        original's frame has that much room there; check that ours does too, and write those bytes."""
        if not known or conv or insn.target is None:
            return
        learned = self.inp.setdefault("wext_by_call", {})
        if self.coverage:                       # the original's run decides the extents
            ext = self.prog.callee_writes(target)
            rec = {}
            for loc, w in ext.items():
                v = self._read_u32(argbase + 4 * loc) if isinstance(loc, int) else self.reg(loc)
                if not in_frame(v):
                    continue
                room, _ = self._frame_room(v)
                # (a partly written last word, `Key` copying 10 bytes of a 12-byte slot: its padding is stale
                # on both sides, a dead return address that differs, so the whole word is filled)
                cap = min([(w + 3) & ~3, room] + [x - v for x in firsts if x > v])
                cap &= ~3
                # offset 0 of a stack argument was filled with the other out-parameters; through a register
                # (`sub esp, 8; mov ecx, esp; push src; call copy_ctor`: a by-value argument built in place)
                # nothing filled it, and it still holds a dead return address that differs between the sides
                lo = 4 if not isinstance(loc, str) or v in firsts else 0
                if cap <= lo:
                    continue
                # every word of the extent, including words the function wrote itself before the call (a dead
                # spill slot that overlaps the object in one frame layout: the real callee overwrites it).
                # Such a word's earlier value is recorded on each side (fill_pre); an input on which the two
                # sides held different values there and either one reads the word back before rewriting it
                # is inconclusive (the static extent may cover a word the real callee doesn't write)
                offs = list(range(lo, cap, 4)) if "fill" not in EQUIV_OFF else [o for o in range(lo, cap, 4)
                        if not any(x in self.func_stack_written for x in range(v + o, v + o + 4))]
                rec[loc] = (cap, offs)
            learned[k] = rec
        else:
            rec = learned.get(k, {})
        for loc, (cap, offs) in sorted(rec.items(), key=lambda kv: str(kv[0])):
            v = self._read_u32(argbase + 4 * loc) if isinstance(loc, int) else self.reg(loc)
            if not in_frame(v):
                continue
            room, what = self._frame_room(v)
            if not self.coverage and room < cap:
                self.calls[-1].setdefault("overflow", []).append(
                    (loc, cap, room, what))
            j = 100 + loc if isinstance(loc, int) else 200 + ("eax", "ecx", "edx").index(loc)
            for o in offs:
                if o + 4 <= room:
                    w = v + o
                    if any(x in self.func_stack_written for x in range(w, w + 4)):
                        self.fill_pre[(k, j, o)] = self._read_u32(w)
                        for x in range(w, w + 4):
                            self.fill_watch[x] = (k, j, o)
                    put(w, j, o, v)

    def _reg_info(self, v):
        """{val, src, xf, raw, reg} of a register operand (for directed inputs)."""
        try:
            val = self.reg(v)
        except Exception:
            val = 0
        src = self.loads.get(Program._ALIAS.get(v, v))
        # (a returned bool tested in al; the low byte or word of a loaded register: `shr ecx, 7; test cl, 1`)
        ok = src and (src[3] == v or isinstance(src[0], tuple) or v in LOW_PART.get(src[3], ()))
        if src and v in HIGH_BYTE and src[3] in HIGH_BYTE[v] and "ahbyte" not in EQUIV_OFF and src[1] >= 2:
            # (round 7) the second byte of a loaded word (`mov ax, [esp+0x3c]; cmp al, 0x42; jne; cmp ah, 0x4d`:
            # a 'BM' magic a stubbed read filled): its source shifted right by 8 (the low byte kept from raw)
            return {"val": val, "src": src[:3], "xf": tuple(src[4]) + (("shr", 8),), "raw": src[5], "reg": v,
                    "abs": src[0] in self.abs_loads}
        out = {"val": val, "src": src[:3] if ok else None, "xf": src[4] if ok else (),
               "raw": src[5] if ok else None, "reg": v, "abs": bool(ok) and src[0] in self.abs_loads}
        if not ok and self.const_src:
            via = self.const_src.get(Program._ALIAS.get(v, v))
            if via is not None:
                out["via"] = via        # (round 9) a constant a compare decided: steer that compare
        if ok and self.eq_links and out["src"] in self.eq_links:
            out["eq"] = self.eq_links[out["src"]]
        lp = self.load_pc.get(Program._ALIAS.get(v, v))
        sp_ = self.sub_pc.get(Program._ALIAS.get(v, v)) if ok and self.sub_pc else None
        if sp_ is not None and sp_[2] == src[:3] and len(src[4]) > sp_[1] and src[3] == v:
            out["dpc"] = (sp_[0], tuple(src[4][sp_[1] + 1:]))   # (round 10) a difference of two loads: `end - begin`
        if ok and lp is not None and out["src"] and lp[1] == out["src"][0]:
            out["pc"] = lp[0]           # (round 9) the instruction that loaded it (small-count steering)
        elif ok and out["src"] and isinstance(out["src"][0], int) and out["src"][0] in self.addr_pc:
            out["pc"] = self.addr_pc[out["src"][0]]     # (derived through lea/dec/copies: `lea ebx, [eax+1]`)
        return out

    def _mem_info(self, v):
        ea = self._ea(v)
        if not v[1] and not v[2]:
            self.abs_loads.add(ea)      # a fixed address (a constant or global): not reached through a pointer
        try:
            val = int.from_bytes(self.uc.mem_read(ea, v[5]), "little")
        except Exception:
            val = 0
        fb = self.fill_byte.get(ea)
        if fb is not None and fb[3] + 4 >= ea + v[5]:
            # a byte out-parameter a stub filled (see _stub)
            return {"val": val, "src": (("fill",) + fb[:3] + (ea - fb[3], v[5]), v[5], self.epoch), "xf": (),
                    "raw": val}
        if self.out_ptrs and STACK_LO <= ea < ENTRY_ESP and (ea & 3) + v[5] <= 4 and \
                (ea & ~3) not in self.fill_src and ea not in self.stack_src and ea not in self.fill_byte and \
                not any(x in self.stack_written for x in range(ea, ea + v[5])) and "xfill" not in EQUIV_OFF:
            # (round 9, xfill) a word nobody wrote, behind a local passed to a callee by pointer: the callee
            # filled it (the original reads it back), so a directed input can have the stub fill it
            cand = [(pv, pk, pj) for pk, pj, pv in self.out_ptrs if pv <= ea < pv + POINTEE_WINDOW]
            if cand:
                pv, pk, pj = max(cand)
                off = (ea & ~3) - pv
                if off >= ARRAY_WINDOW:
                    return {"val": val, "src": (("fill", pk, pj, off, ea & 3, v[5]), v[5], self.epoch), "xf": (),
                            "raw": val}
        pf = self.prefill_src.get(ea) if self.prefill_src else None
        if pf is not None and v[5] == 1:
            return {"val": val, "src": (("pfill",) + pf, 1, self.epoch), "xf": (), "raw": val}
        fs = self.fill_src.get(ea & ~3)
        if fs is not None and (ea & 3) + v[5] <= 4:
            # an out-parameter word a stub filled: a directed input can fill in another value
            return {"val": val, "src": (("fill",) + fs + (ea & 3, v[5]), v[5], self.epoch), "xf": (), "raw": val}
        st = self.stack_src.get(ea)
        if st is not None and v[5] == 4:
            # a local holding a value loaded from elsewhere (`movsx eax, byte [edx]; mov [esp+4], eax`)
            out = {"val": val, "src": st[:3], "xf": st[4], "raw": st[5]}
            if self.stack_pc.get(ea) is not None:
                out["pc"] = self.stack_pc[ea]
            return out
        out = {"val": val, "src": (ea, v[5], self.epoch), "xf": (), "raw": val, "abs": ea in self.abs_loads}
        if self.cur_insn is not None:
            out["pc"] = self.cur_insn.addr
        if self.eq_links and out["src"] in self.eq_links:
            out["eq"] = self.eq_links[out["src"]]
        return out

    def _note_str(self, site, lit, buf, n=None, psrc=None):
        """Record a compare of the buffer at `buf` with a literal in read-only data at `lit` (n bytes, or
        up to its NUL). A directed input re-runs the input with the literal written over the buffer, in the
        memory epoch it was read in (or, for a stack buffer a stub filled, as that stub's fill)."""
        prog = self.prog
        if (site, lit) in self._str_seen or len(self.str_obs) >= 64:
            return
        if not (IMAGE_LO <= lit < IMAGE_HI) or prog.section_name(lit) != ".rdata" or lit in prog.vftables:
            return
        if (buf < NULL_HI and (psrc is None or "strnull" in EQUIV_OFF)) or prog.is_code(buf) or (IMAGE_LO <= buf < IMAGE_HI and prog.section_name(buf) == ".rdata"):
            return
        fills = {}
        if buf < NULL_HI:
            pass            # (a null-page pointer the code loaded: `_plants` points its source at a buffer)
        elif STACK_LO <= buf < STACK_HI:
            fills = {w: self.fill_src[w] for w in range(buf & ~3, buf + 256, 4) if w in self.fill_src}
            if (buf & ~3) not in fills:
                return
        elif _reserved(buf) or (OURS <= buf < OURS + OURS_SIZE):
            return
        if n is None:
            data = prog.read(lit, 256)
            k = data.find(b"\0")
            if k <= 0:
                return
            data = data[:k + 1]
        else:
            data = prog.read(lit, min(n, 256))
            if not data:
                return
        if any(lo <= lit < hi and d == buf - lit for lo, hi, d in self._str_walks):
            return          # the same two strings, further along (an inline loop's next byte pair)
        self._str_walks.append((lit, lit + len(data), buf - lit))
        self._str_seen[(site, lit)] = True
        self.str_obs.append({"site": site, "lit": data, "buf": buf, "epoch": self.epoch, "fills": fills,
                             "psrc": psrc})

    def _null_psrc(self, reg, v):
        """Where a null-page pointer in `reg` was loaded from (a plain word, no arithmetic), else None."""
        if not 0 <= v < NULL_HI:
            return None
        info = self._reg_info(reg)
        return info["src"] if info["src"] and not info["xf"] else None

    def _note_rep_cmps(self, insn):
        """`repe cmpsb` of a buffer against a literal (once per execution: Unicorn may re-enter the hook
        for each round with esi/edi advanced)."""
        size = {"b": 1, "w": 2, "d": 4}.get(insn.mnemonic[-1], 1)
        esi, edi, ecx = self.reg("esi"), self.reg("edi"), self.reg("ecx")
        last = self._str_seen.get(insn.addr)
        self._str_seen[insn.addr] = (esi, edi, ecx)
        if last and 0 < last[2] - ecx and esi - last[0] == edi - last[1] == (last[2] - ecx) * size:
            return
        if 0 < ecx <= 256:
            self._note_str(insn.addr, edi, esi, ecx * size, self._null_psrc("esi", esi))
            self._note_str(insn.addr, esi, edi, ecx * size, self._null_psrc("edi", edi))

    def _observe_x87(self, insn):
        """Where the x87 stack's values were loaded from, and float comparisons (for directed inputs)."""
        m = insn.mnemonic
        fs = self.fstack
        if m in ("fnstsw", "fstsw"):
            self.loads.pop("eax", None)
        if insn.mem is not None and "memfloats" not in EQUIV_OFF and len(self.float_loads) < 64 and \
                m not in X87_STORES and m not in ("fild", "fiadd", "fisub", "fisubr", "fimul", "fidiv", "fidivr",
                                                  "ficom", "ficomp", "fldcw", "fnldcw", "fbld", "frstor", "fldenv") \
                and insn.mem[5] in (4, 8):
            try:
                ea = self._ea(insn.mem)
                if not STACK_LO <= ea < STACK_HI and not _reserved(ea) and \
                        _patchable(ea, not insn.mem[1] and not insn.mem[2]) and \
                        all(x[1] != ea for x in self.float_loads):
                    self.float_loads.append((self.epoch, ea, insn.mem[5]))
            except Exception:   # noqa: BLE001
                pass
        if m in FCMP:
            a = fs[0] if fs else None
            sts = [_st_index(r) for r in insn.regs if _st_index(r) is not None]
            if m == "ftst":
                b = {"val": 0.0, "src": None, "float": True}
            elif insn.mem is not None:
                b = self._float_info(insn.mem)
            else:
                k = max([x for x in sts if x] or [1])
                b = fs[k] if k < len(fs) else None
            a = a or {"val": None, "src": None, "float": True}
            b = b or {"val": None, "src": None, "float": True}
            if a.get("fxf") and a.get("val") is None:
                try:
                    u = self.u
                    top = (self.uc.reg_read(u.UC_X86_REG_FPSW) >> 11) & 7
                    a = dict(a, val=_x87_value(self.uc.reg_read(u.UC_X86_REG_FP0 + top)))
                except Exception:   # noqa: BLE001
                    a = {"val": None, "src": None, "float": True}
            if "fprov" not in EQUIV_OFF:
                # (round 9) a computed operand's value (`fld [k]; fmul [4.0]; fcompp` against a stub's float):
                # the other side can still be steered to just above or below it
                try:
                    if a.get("val") is None:
                        a = dict(a, val=self._st_val(0))
                    if b.get("val") is None and insn.mem is None and m != "ftst":
                        kk = max([x for x in sts if x] or [1])
                        b = dict(b, val=self._st_val(kk))
                except Exception:   # noqa: BLE001
                    pass
                for o_ in (a, b):
                    if isinstance(o_.get("val"), float) and (math.isnan(o_["val"]) or math.isinf(o_["val"])) and \
                            o_.get("src") is None:
                        o_["val"] = None
            self.fpu_cmp = {"addr": insn.addr, "mnemonic": "fcmp", "ops": [a, b]}
            if self.float_loads:
                self.fpu_cmp["floads"] = tuple(self.float_loads)
                if self.calls:
                    self.fpu_cmp["stubs"] = True     # (stub floats may be what decides it: they go first)
            if m in ("fcomi", "fcomip", "fucomi", "fucomip"):
                self.last_cmp = self.fpu_cmp
        fprov = "fprov" not in EQUIV_OFF
        if fprov and m in X87_STORES and insn.mem is not None and self.stack_src:
            # (round 9) an x87 store ends what a stack word held before (`mov [esp+0x8c], eax` ... `fstp [esp+0x8c]`:
            # the integer copy's source no longer explains the word)
            try:
                ea = self._ea(insn.mem)
                for x in range(ea - 3, ea + max(insn.mem[5] or 4, 1)):
                    self.stack_src.pop(x, None)
            except Exception:   # noqa: BLE001
                pass
        if fprov and m in ("fst", "fstp") and insn.mem is not None and insn.mem[5] in (4, 8):
            # (round 9, fprov) a steerable float stored to memory (`call f; fstp [esp+0x40]` ... `fld
            # [esp+0x40]; fucompp`): the reload keeps its source and transforms
            try:
                ea = self._ea(insn.mem)
            except Exception:   # noqa: BLE001
                ea = None
            if ea is not None:
                for x in [x for x in self.fmem if ea - 7 <= x < ea + insn.mem[5]]:
                    self.fmem.pop(x, None)
                if fs and fs[0] is not None and fs[0].get("src") is not None:
                    self.fmem[ea] = (dict(fs[0]), insn.mem[5], insn.addr)
        if fprov and m == "fabs" and fs and fs[0] is not None and fs[0].get("src") is not None:
            fs[0] = dict(fs[0], val=None, fxf=tuple(fs[0].get("fxf", ())) + (("fabs", None),))
            return
        if fprov and insn.mem is None and m in FARITH:
            if self._fprov_arith(insn):
                return
        if m in ("fld",) and insn.mem is not None:
            fs.insert(0, self._float_info(insn.mem))
        elif m == "fxch":
            sts = [_st_index(r) for r in insn.regs if _st_index(r)]
            k = sts[0] if sts else 1
            while len(fs) <= k:
                fs.append(None)
            fs[0], fs[k] = fs[k], fs[0]
        elif fs and fs[0] is not None and fs[0].get("src") is not None and \
                (fprov or not isinstance(fs[0]["src"][0], tuple)) and "fxf" not in EQUIV_OFF and \
                (m == "fchs" or (m in ("fadd", "fsub", "fsubr", "fmul") + (("fdiv", "fdivr") if fprov else ()) and
                                 insn.mem is not None and len(insn.ops) == 1)):
            # (round 7) a loaded float plus/minus/times a constant from memory (`fld [g]; fadd [k]; fcomp [0.95]`):
            # the compare can still be steered through g, the transform inverted
            c = None
            if m != "fchs":
                c = self._float_info(insn.mem)["val"]
            if m == "fchs" or (c is not None and not math.isnan(c) and not math.isinf(c) and (m not in ("fmul", "fdivr") or c)):
                fs[0] = dict(fs[0], val=None, fxf=tuple(fs[0].get("fxf", ())) + ((m, c),))
            else:
                fs[0] = None
        elif fprov and fs and (fs[0] is None or fs[0].get("src") is None) and insn.mem is not None and \
                len(insn.ops) == 1 and m in ("fadd", "fsub", "fsubr", "fmul", "fdiv", "fdivr"):
            # (round 9) a value computed from constants, plus/minus/times a steerable float in memory (`fmul st(1);
            # fadd [ecx+0x218]; fst [ecx+0x218]`): the result is steered through that float, the computed part
            # taken as the constant it is now
            mi = self._float_info(insn.mem)
            try:
                c = self._st_val(0)
            except Exception:   # noqa: BLE001
                c = None
            t = None
            if mi.get("src") is not None and c is not None and not (math.isnan(c) or math.isinf(c)) and \
                    (not isinstance(mi["src"][0], int) or _patchable(mi["src"][0], mi.get("abs", True))):
                t = {"fadd": ("fadd", c), "fmul": ("fmul", c), "fsub": ("fsubr", c), "fsubr": ("fsub", c),
                     "fdiv": ("fdivr", c), "fdivr": ("fdiv", c)}[m]
                if t[0] in ("fmul", "fdiv") and not c:
                    t = None
            fs[0] = dict(mi, val=None, fxf=tuple(mi.get("fxf", ())) + (t,)) if t is not None else None
        elif fprov and m == "fld" and insn.mem is None:
            sts = [_st_index(r) for r in insn.regs if _st_index(r) is not None]
            k = sts[0] if sts else 0
            fs.insert(0, dict(fs[k]) if k < len(fs) and fs[k] is not None else None)     # (`fld st(0)`: a copy)
        else:
            req, delta = insn.x87
            if delta < 0:
                del fs[:-delta]
            elif delta > 0:
                for _ in range(delta):
                    fs.insert(0, None)
            elif req and m not in FCMP and not m.startswith(("fst", "fist")):
                if fs:
                    fs[0] = None          # st0 computed: no longer a plain load
        del fs[8:]

    def _st_val(self, i):
        """The value of st(i) now (Unicorn's FP0..7 are the physical registers)."""
        u = self.u
        top = (self.uc.reg_read(u.UC_X86_REG_FPSW) >> 11) & 7
        return _x87_value(self.uc.reg_read(u.UC_X86_REG_FP0 + ((top + i) & 7)))

    def _fprov_arith(self, insn):
        """(round 9, fprov) `fsubr st(1)`, `fmulp st(1)`, `fadd st(0), st(2)`: a register-form x87 operation
        between a steerable value and another whose value is known now (a constant, or anything a patch of
        the steerable one's source leaves alone) keeps the steerable one's source, with the operation as a
        transform (inverted by directed inputs). Decided by the opcode bytes (assemblers disagree on the
        names of the reversed forms). True when handled."""
        try:
            b0, b1 = self.view.read(insn.addr, 2)
        except Exception:   # noqa: BLE001
            return False
        if b0 not in (0xD8, 0xDC, 0xDE) or b1 < 0xC0:
            return False
        i = b1 & 7
        grp = (b1 >> 3) & 7         # 0 add, 1 mul, 4/5 sub/subr, 6/7 div/divr (D8: st0 = st0 op sti)
        if grp in (2, 3):
            return False            # (fcom forms: handled as compares)
        fs = self.fstack
        while len(fs) <= i:
            fs.append(None)
        d, s = (0, i) if b0 == 0xD8 else (i, 0)     # destination, other operand
        if d == s:
            fs[0] = None            # (st0 with itself: no constant operand)
            return True
        # D8: dst = st0, sub: st0 - sti, subr: sti - st0. DC/DE: dst = sti, grp 4 (E0+i) is subr: st0 - sti,
        # grp 5 (E8+i) is sub: sti - st0; grp 6 (F0+i) divr: st0 / sti, grp 7 (F8+i) div: sti / st0
        if b0 == 0xD8:
            op = {0: "add", 1: "mul", 4: "dst-src", 5: "src-dst", 6: "dst/src", 7: "src/dst"}[grp]
        else:
            op = {0: "add", 1: "mul", 4: "src-dst", 5: "dst-src", 6: "src/dst", 7: "dst/src"}[grp]
        ed, es = fs[d], fs[s]

        def steer(e):
            # (a constant at a fixed address in read-only data is no input: `fld [pi/2]; fsubr st(1)`)
            return e is not None and e.get("src") is not None and len(e.get("fxf", ())) < 6 and \
                (not isinstance(e["src"][0], int) or _patchable(e["src"][0], e.get("abs", True)))

        try:
            vd, vs = self._st_val(d), self._st_val(s)
        except Exception:   # noqa: BLE001
            return False
        res = None
        if steer(ed) or steer(es):
            mine, c, mine_is_dst = (ed, vs, True) if steer(ed) else (es, vd, False)
            if not (math.isnan(c) or math.isinf(c)):
                if op in ("add", "mul"):
                    t = ("fadd" if op == "add" else "fmul", c)
                elif op == "dst-src":
                    t = ("fsub", c) if mine_is_dst else ("fsubr", c)
                elif op == "src-dst":
                    t = ("fsubr", c) if mine_is_dst else ("fsub", c)
                elif op == "dst/src":
                    t = ("fdiv", c) if mine_is_dst else ("fdivr", c)
                else:
                    t = ("fdivr", c) if mine_is_dst else ("fdiv", c)
                if t[0] not in ("fmul", "fdiv") or c:
                    res = dict(mine, val=None, fxf=tuple(mine.get("fxf", ())) + (t,))
        fs[d] = res
        if b0 == 0xDE:
            del fs[0]
        del fs[8:]
        return True

    def _float_info(self, mem):
        ea = self._ea(mem)
        size = mem[5]
        try:
            b = bytes(self.uc.mem_read(ea, size))
            val = struct.unpack("<f" if size == 4 else "<d", b)[0] if size in (4, 8) else None
        except Exception:
            val = None
        fm = self.fmem.get(ea)
        if fm is not None and fm[1] == size and val is not None and "fprov" not in EQUIV_OFF:
            # (round 9) a steerable float stored here (fst/fstp) and not overwritten since
            return dict(fm[0], val=val)
        st = self.stack_src.get(ea)
        if val is not None and size == 4 and st is not None and st[1] == 4 and isinstance(st[0], int) and \
                "fabs" not in EQUIV_OFF and all(op[0] == "and" for op in st[4]):
            # (round 7) a float word stored to a local from a loaded value, masked (`mov eax, [arg]; and eax,
            # 0x7fffffff; mov [esp+0x14], eax; fld [esp+0x14]`: fabs): steered through the load, the mask kept
            return {"val": val, "src": st[:3], "ixf": tuple(st[4]), "raw": st[5], "float": True}
        fs = self.fill_src.get(ea)
        if val is not None and size == 4 and fs is not None and not ea & 3 and "ffill" not in EQUIV_OFF:
            # (round 7) a float a stubbed callee filled in through a pointer (`v.z == 0` after FUN_0022d240
            # filled the vector): a directed input can fill in another value, an exact 0 included
            return {"val": val, "src": (("fill",) + fs + (0, 4), 4, self.epoch), "float": True}
        if val is None or STACK_LO <= ea < STACK_HI and not ENTRY_ESP < ea < ENTRY_ESP + 0x100:
            return {"val": val, "src": None, "float": True}
        out = {"val": val, "src": (ea, size, self.epoch), "float": True}
        if "fprov" not in EQUIV_OFF:
            out["abs"] = not mem[1] and not mem[2]
        return out

    def _track_const(self, insn):
        """(round 9, via) A register set to a constant on one side of a branch (`cmp eax, [g]; jne L; mov bl, 1;
        jmp M; L: xor bl, bl`) or by a setcc holds what that compare decided: a later `test bl, bl; je` that has
        no source of its own is steered through it (bl == 1 needs eax == [g])."""
        m, ops = insn.mnemonic, insn.ops
        A = Program._ALIAS
        cs = self.const_src
        self.since_jcc += 1
        if insn.kind == "jcc":
            self.last_jcc_obs = self.last_cmp
            self.since_jcc = 0
            return
        if insn.kind == "call":
            for r in ("eax", "ecx", "edx"):
                cs.pop(r, None)
            return
        if insn.kind != "other":
            return
        dst = ops[0] if ops else None
        if dst is not None and dst[0] == "reg":
            r32 = A.get(dst[1], dst[1])
            via = None
            if m.startswith("set"):
                via = self.last_cmp
            elif (m == "mov" and len(ops) == 2 and ops[1][0] == "imm" or
                  m in ("xor", "sub") and len(ops) == 2 and ops[0] == ops[1]) and self.since_jcc <= 3:
                # (right at the start of a branch side: what the branch decided, not an initialisation)
                via = self.last_jcc_obs
            elif m in ("mov", "movzx", "movsx") and len(ops) == 2 and ops[1][0] == "reg":
                via = cs.get(A.get(ops[1][1], ops[1][1]))
            elif m in ("test", "cmp"):
                return
            if via is not None:
                for r in self.view.write_widths(insn.addr):
                    cs.pop(r, None)
                cs[r32] = via
                return
        for r in self.view.write_widths(insn.addr):
            cs.pop(r, None)

    def _note_deref(self, insn):
        """(round 13, objptr) A field access `[reg + disp]` through a pointer loaded as is from an input (memory, a
        stub's fill or result, a stack argument) where the words beside the field hold the same value (the null
        page, a run of zeros): reading a neighbouring field instead reads the same thing, so an offset error in
        the source can't show (fx15's 0x002e22c0: `D->f18` read at +0x1c, D a constructor stub's field in the null
        page). Recorded for a directed input that points the pointer at an object whose words all differ."""
        mem = insn.mem
        base = mem[1]
        if not base or mem[2] or base in ("esp", "ebp") or len(self.deref_obs) >= 16 or insn.mnemonic == "lea":
            return
        disp = mem[4]
        if not 0 <= disp < OBJ_SIZE - 8:
            return
        cur = self.loads.get(base)
        if cur is None or cur[3] != base or cur[4] or cur[1] != 4 or \
                (isinstance(cur[0], tuple) and cur[0][0] not in ("ret", "fill")):
            return
        v = self.reg(base)
        # (one per pointer: where it was loaded, else the stub result or fill it is; every field read through it
        # then reads the object)
        lp = self.load_pc.get(base)
        key = ("pc", lp[0]) if lp is not None and lp[1] == cur[0] else cur[0]
        if OBJ_BASE <= v < OBJ_BASE + OBJ_SIZE * OBJ_DEPTH or any(x[0] == key for x in self.deref_obs):
            return
        ea = (v + disp) & M32
        if ea < 4 or ea > M32 - 8 or any(_reserved(x) for x in (ea - 4, ea, ea + 4)) or STACK_LO <= ea < STACK_HI:
            return
        try:
            w = [struct.unpack("<I", self.uc.mem_read(x, 4))[0] for x in (ea - 4, ea, ea + 4)]
        except Exception:
            w = [struct.unpack("<I", bytes(self.m.byte(x + i, self.epoch) for i in range(4)))[0]
                 for x in (ea - 4, ea, ea + 4)]
        if w[1] != w[0] and w[1] != w[2]:
            return
        self.deref_obs.append((key, cur[:3], disp))

    def _observe(self, insn):
        """Track where registers were loaded from and what each cmp/test compared (for directed inputs).

        A register's source is (where it was loaded from, size, epoch, register, transforms, raw value):
        add/sub/inc/dec/shifts/and/neg/not of a loaded value are followed (`mov ecx, [eax+0xc]; dec ecx;
        sub ecx, 4; je` compares the loaded type with 5), and so are flag-setting arithmetic instructions
        that act as comparisons (`sub eax, [ecx]` before a jcc compares end with begin)."""
        m = insn.mnemonic
        ops = insn.ops
        A = Program._ALIAS
        if m.startswith("f"):
            self._observe_x87(insn)
            return
        if "via" not in EQUIV_OFF:
            self._track_const(insn)
        if self.fmem and m == "and" and len(ops) == 2 and ops[0][0] == "mem" and "fprov" not in EQUIV_OFF and \
                (ops[1] == ("imm", 0x7FFFFFFF) or ops[1][0] == "reg" and self.reg(ops[1][1]) == 0x7FFFFFFF):
            # (round 9, fprov) `fstp [esp+4]; and dword [esp+4], 0x7fffffff; fld [esp+4]`: fabs in memory (the
            # high word of a double, or a float)
            ea_ = self._ea(ops[0][1])
            for key_, sz_ in ((ea_, 4), (ea_ - 4, 8)):
                fm_ = self.fmem.get(key_)
                if fm_ is not None and fm_[1] == sz_:
                    self.fmem[key_] = (dict(fm_[0], val=None, fxf=tuple(fm_[0].get("fxf", ())) + (("fabs", None),)),
                                       sz_, fm_[2])
                    self.fmem_keep = (insn.addr, key_)
        if m == "test" and ops and ops[0] == ("reg", "ah") and self.fpu_cmp is not None:
            self.last_cmp = self.fpu_cmp          # fnstsw ax; test ah, 0x41: the float comparison decides
            return
        if m == "sahf" and self.fpu_cmp is not None:
            self.last_cmp = self.fpu_cmp
            return
        if insn.kind == "jmp" and insn.addr in self.view.tables and insn.mem is not None and insn.mem[2]:
            idx = insn.mem[2]
            info = self._reg_info(idx)
            if self.coverage is not None and info["src"] and isinstance(info["src"][0], int) and \
                    info["src"][1] == 1 and info.get("xf") and info["xf"][-1][0] == "btab" and \
                    "alphaxf" not in EQUIV_OFF:
                # (round 9) a switch through a byte table on a loaded char (`movzx edx, byte [eax + map]; jmp
                # [edx*4 + tab]`, a Lua binding's signature letters): one char per case joins the alphabet of
                # planted strings, and the buffer is where they go
                adj = _char_adjust(info["xf"][:-1])
                if adj is not None:
                    tab = Program.get().read(info["xf"][-1][1], 256)
                    ncase = len(self.view.tables[insn.addr])
                    for ci in sorted(set(tab[:256])):
                        if ci < ncase and len(self.byte_seq) < 64:
                            self.byte_seq.append((tab.index(ci) - adj) & 0xFF)
                    ea_ = info["src"][0]
                    if not STACK_LO <= ea_ < STACK_HI and insn.addr not in self.byte_bufs:
                        self.byte_bufs[insn.addr] = (ea_, info["src"][2])
            old_ = self.cmp_obs.get(insn.addr)
            if info["src"] and (old_ is None or ("obslater" not in EQUIV_OFF and not _obs_steerable(old_, via=False) and
                                                 _obs_steerable({"ops": [info]}, via=False))):
                # the jump-table index came straight from memory or an input: cases can be patched in
                # (round 9, obslater: a later round's index from fuzzed data replaces a first one read from the
                # byte table itself, `mov al, 0x76` past the end of a signature string)
                self.cmp_obs[insn.addr] = {"addr": insn.addr, "mnemonic": "table", "ops": [info],
                                           "cases": list(self.view.tables[insn.addr])}
            return
        if insn.kind == "jcc" or (m.startswith("set") and insn.kind == "other"):
            if self.last_cmp is not None:
                if insn.addr not in self.cmp_obs:
                    self.cmp_obs[insn.addr] = self.last_cmp
                elif "obslater" not in EQUIV_OFF and insn.addr not in self.cmp_obs2 and \
                        not _obs_steerable(self.cmp_obs[insn.addr], via=False) and _obs_steerable(self.last_cmp, via=False):
                    # (round 9, obslater) the first round compared constants (a loop's first element, a default),
                    # a later one data an input can change: keep that one
                    self.cmp_obs[insn.addr] = self.last_cmp
                elif insn.addr not in self.cmp_obs2 and self.last_cmp is not self.cmp_obs[insn.addr]:
                    self.cmp_obs2[insn.addr] = self.last_cmp      # the second time round (a loop's step)
            if insn.kind == "jcc":
                self.jcc_count[insn.addr] += 1
                if self.loop_limits and self.jcc_count[insn.addr] > self.loop_limits.get(insn.addr, 1 << 30):
                    # a loop that already ran away on another input: stop early, the run is repaired instead
                    self.loop_abort = True
                    raise Fault("loop_limit")
                return
        if m in ("cmp", "test") and ops:
            info = []
            for kind, v in ops:
                if kind == "reg":
                    info.append(self._reg_info(v))
                elif kind == "mem":
                    info.append(self._mem_info(v))
                else:
                    info.append({"val": v, "src": None, "imm": v})
            if len(info) == 2 and info[0].get("reg") and info[0].get("reg") == info[1].get("reg"):
                info[1]["same"] = True
            if m == "cmp" and len(info) == 2 and "eqlink" not in EQUIV_OFF and info[0]["src"] and info[1]["src"] and \
                    not info[0].get("xf") and not info[1].get("xf") and info[0]["src"] != info[1]["src"] and \
                    info[0]["val"] == info[1]["val"] and len(self.eq_links) < 64:
                # (round 9, eqlink) two inputs found equal (`cmp eax, [ebx+0xc]; jne` after a stub returned eax):
                # a later compare of one of them (`add eax, -8; cmp eax, 4; ja`) moves both, or the first compare
                # no longer holds
                self.eq_links[info[0]["src"]] = info[1]["src"]
                self.eq_links[info[1]["src"]] = info[0]["src"]
            if m == "cmp" and len(info) == 2 and self.coverage is not None:
                # an inline string compare (`mov al, [ecx]; cmp al, [edx]`) with one side in .rdata
                sa, sb = info[0]["src"], info[1]["src"]
                if sa and sb and isinstance(sa[0], int) and isinstance(sb[0], int) and sa[1] == sb[1] \
                        and not info[0].get("xf") and not info[1].get("xf"):
                    self._note_str(insn.addr, sa[0], sb[0])
                    self._note_str(insn.addr, sb[0], sa[0])
            if m == "cmp" and len(info) == 2 and self.coverage is not None and "alpha" not in EQUIV_OFF:
                for x_, y_ in ((info[0], info[1]), (info[1], info[0])):
                    sa = x_["src"]
                    adj = _char_adjust(x_.get("xf")) if "alphaxf" not in EQUIV_OFF else (0 if not x_.get("xf") else None)
                    if not (sa and isinstance(sa[0], int) and sa[1] == 1 and adj is not None) or \
                            y_.get("src") is not None or y_.get("val") is None or \
                            (y_["val"] > 0xFF if not x_.get("xf") else not -0x100 < _sx(y_["val"]) < 0x100):
                        continue
                    # a char compared with a constant (an immediate, or `mov al, 's'; cmp cl, al`): the
                    # constants make up the alphabet planted strings use, in the order compared ("class")
                    # (round 9: also a char minus a constant, `movsx eax, al; add eax, -0x56; cmp eax, 0x20`)
                    if len(self.byte_seq) < 64:
                        self.byte_seq.append((y_["val"] - adj) & 0xFF)
                    ea = sa[0]
                    if STACK_LO <= ea < STACK_HI:
                        ea = self.copy_src.get(ea)       # a stack copy of a heap string: plant the original
                        if ea is None:
                            continue
                        ea = (ea[0], ea[1])
                    else:
                        ea = (ea, sa[2])
                    if insn.addr not in self.byte_bufs:
                        self.byte_bufs[insn.addr] = ea
            self.last_cmp = {"addr": insn.addr, "mnemonic": m, "ops": info}
            return
        dst = ops[0] if ops else None
        if m == "mov" and dst is not None and dst[0] == "mem" and dst[1][5] == 1 and len(ops) == 2 and \
                ops[1][0] == "reg" and self.coverage is not None and "alpha" not in EQUIV_OFF:
            ea_d = self._ea(dst[1])
            if STACK_LO <= ea_d < STACK_HI:
                sr = self.loads.get(A.get(ops[1][1], ops[1][1]))
                if sr is not None and isinstance(sr[0], int) and sr[1] == 1 and not sr[4] and \
                        not STACK_LO <= sr[0] < STACK_HI:
                    self.copy_src[ea_d] = (sr[0], sr[2], ea_d)
                else:
                    self.copy_src.pop(ea_d, None)
        if dst is not None and dst[0] == "mem" and dst[1][1] in ("esp", "ebp"):
            ea = self._ea(dst[1])
            src = self.loads.get(A.get(ops[1][1], ops[1][1])) if m == "mov" and len(ops) == 2 and \
                ops[1][0] == "reg" else None
            if src is not None and src[3] == ops[1][1] and dst[1][5] == 4:
                self.stack_src[ea] = src
                lp_ = self.load_pc.get(A.get(ops[1][1], ops[1][1]))
                if lp_ is not None and lp_[1] == src[0]:
                    self.stack_pc[ea] = lp_[0]      # (round 9) where the value was loaded from memory
                else:
                    self.stack_pc.pop(ea, None)
            else:
                for x in range(ea - 3, ea + (dst[1][5] or 4)):
                    self.stack_src.pop(x, None)
        # flag-setting arithmetic that a jcc may test, as the comparison it amounts to
        if m in ("sub", "add", "dec", "inc", "and") and dst is not None and \
                not (dst[0] == "reg" and A.get(dst[1], dst[1]) in ("esp", "ebp")):
            a = self._reg_info(dst[1]) if dst[0] == "reg" else self._mem_info(dst[1]) if dst[0] == "mem" else None
            b = None
            if m == "dec":
                b = {"val": 1, "src": None, "imm": 1}
            elif m == "inc":
                b = {"val": M32, "src": None, "imm": M32}
            elif len(ops) == 2:
                kind, v = ops[1]
                if kind == "imm" and m == "add" and 4 <= v < 0x10000:
                    b = None        # `add eax, 0x58; je`: a base-class pointer's null check, not a value test
                elif kind == "imm":
                    b = {"val": v if m != "add" else (-v) & M32, "src": None, "imm": v}
                elif m == "sub" and kind == "reg":
                    b = self._reg_info(v)
                elif m == "sub" and kind == "mem":
                    b = self._mem_info(v)
            if a is not None and b is not None:
                self.last_cmp = {"addr": insn.addr, "mnemonic": "test" if m == "and" else "cmp", "ops": [a, b]}
            else:
                self.last_cmp = None        # the flags are this instruction's now
        elif m == "or" and len(ops) == 2 and ops[0] == ops[1] and dst[0] == "reg":
            a = self._reg_info(dst[1])
            self.last_cmp = {"addr": insn.addr, "mnemonic": "test", "ops": [a, dict(a, same=True)]}
        if dst is not None and dst[0] == "reg":
            r = dst[1]
            r32 = A.get(r, r)
            cur = self.loads.get(r32)
            tracked = cur is not None and cur[3] == r
            step = None
            if self.sub_pc and m not in ("add", "sub", "inc", "dec", "shr", "sar", "shl", "and", "neg", "not", "or",
                                         "test", "cmp", "push"):
                self.sub_pc.pop(r32, None)
            if m in ("mov", "movzx", "movsx") and len(ops) == 2 and ops[1][0] == "mem":
                size = ops[1][1][5]
                mem = ops[1][1]
                base = self.loads.get(mem[1]) if mem[1] and not mem[2] else None
                if base is None and mem[2] and not mem[1] and mem[3] == 1:
                    base = self.loads.get(mem[2])
                if m == "movzx" and size == 1 and base is not None and base[3] == (mem[1] or mem[2]) and \
                        Program.get().is_code(mem[4]):
                    # an index through a byte table in code (a switch's case map): keep the selector's source
                    self.loads[r32] = base[:3] + (r, base[4] + (("btab", mem[4]),), base[5])
                    return
                inf = self._mem_info(mem)
                if inf["xf"]:
                    self.loads[r32] = (inf["src"][0], inf["src"][1], inf["src"][2], r, inf["xf"], inf["raw"])
                    self.load_pc[r32] = (inf.get("pc", insn.addr), inf["src"][0])
                    return
                raw = inf["val"]
                if m == "movsx" and raw >> (8 * size - 1):
                    raw = (raw - (1 << (8 * size))) & M32
                # (the epoch the value was loaded from memory in: a loop counter kept in a local, `mov eax,
                # [esp+0x40]; dec eax; mov [esp+0x40], eax; jne`, was loaded before the body's calls)
                self.loads[r32] = (inf["src"][0], size, inf["src"][2] if "epoch" not in EQUIV_OFF else self.epoch, r, (), raw)
                self.load_pc[r32] = (inf.get("pc", insn.addr), inf["src"][0])
                if isinstance(inf["src"][0], int) and inf.get("pc", insn.addr) == insn.addr and len(self.addr_pc) < 4096:
                    self.addr_pc[inf["src"][0]] = insn.addr
                return
            if m in ("movzx", "movsx") and len(ops) == 2 and ops[1][0] == "reg" and r in Program._REGS:
                sr = ops[1][1]
                src = self.loads.get(A.get(sr, sr))
                if src and (src[3] == sr or sr in LOW_PART.get(src[3], ())):
                    mask = 0xFF if sr.endswith("l") else 0xFFFF
                    xf = src[4] + ((("and", mask),) if src[3] != sr else ())
                    self.loads[r] = src[:3] + (r, xf, src[5])
                else:
                    self.loads.pop(r32, None)
                return
            if m == "mov" and len(ops) == 2 and ops[1][0] == "reg":
                src = self.loads.get(A.get(ops[1][1], ops[1][1]))
                if src and src[3] == ops[1][1] and (r in Program._REGS or r32 in Program._REGS):
                    self.loads[r32] = src[:3] + (r,) + src[4:]      # (`mov cl, dl`: the byte goes along)
                else:
                    self.loads.pop(r32, None)
                return
            if m == "lea" and len(ops) == 2 and ops[1][0] == "mem" and r in Program._REGS:
                _, base, index, _, disp, _ = ops[1][1]
                src = self.loads.get(base) if base else None
                if src and src[3] == base and not index:
                    self.loads[r] = src[:3] + (r, src[4] + (("addp", disp),), src[5])     # (an address)
                else:
                    self.loads.pop(r32, None)
                return
            if m in ("imul", "mul", "idiv", "div") and len(ops) == 1:
                # one-operand forms: edx:eax = eax * r (a magic-number division), eax = edx:eax / r
                other = self.loads.get("eax")
                mine = cur if tracked else None
                if m in ("imul", "mul"):
                    if mine is not None and r32 != "eax":
                        self.loads["edx"] = mine[:3] + ("edx", mine[4] + (("mulhi", self.reg("eax")),), mine[5])
                    elif other is not None and other[3] == "eax" and r32 != "eax":
                        self.loads["edx"] = other[:3] + ("edx", other[4] + (("mulhi", self.reg(r)),), other[5])
                    else:
                        self.loads.pop("edx", None)
                    self.loads.pop("eax", None)
                else:
                    d_ = self.reg(r)
                    if other is not None and other[3] == "eax" and d_ and r32 not in ("eax", "edx"):
                        self.loads["eax"] = other[:4] + (other[4] + (("sdiv" if m == "idiv" else "udiv",
                                                                       _sx(d_) if m == "idiv" else d_),), other[5])
                    else:
                        self.loads.pop("eax", None)
                    self.loads.pop("edx", None)
                return
            if tracked and m == "add" and len(ops) == 2 and ops[1][0] == "reg":
                o2 = self.loads.get(A.get(ops[1][1], ops[1][1]))
                if o2 is not None and o2[:3] == cur[:3] and cur[4] == o2[4] + (("shr", 31),):
                    # `mov eax, edx; shr eax, 31; add eax, edx`: the sign fix-up of a signed division
                    self.loads[r32] = cur[:4] + (o2[4], cur[5])
                    return
            if tracked and len(ops) == 2 and m in ("add", "sub"):
                kind, v = ops[1]
                val = v if kind == "imm" else self._reg_info(v)["val"] if kind == "reg" else \
                    self._mem_info(v)["val"] if kind == "mem" else None
                if val is not None and not (kind == "reg" and A.get(v, v) == r32):
                    step = ("add", val if m == "add" else (-val) & M32)
                    if m == "sub" and kind in ("reg", "mem") and not cur[4] and len(self.sub_pc) < 256 and \
                            "diffcount" not in EQUIV_OFF:
                        # (round 10, diffcount) `mov edx, [ecx+4]; sub edx, [ecx]` (end - begin of a vector):
                        # small-count steering plants end = begin + a few elements here, in the epoch it was read
                        self.sub_pc[r32] = (insn.addr, 0, cur[:3])
            elif tracked and m in ("inc", "dec"):
                step = ("add", 1 if m == "inc" else M32)
            elif tracked and m in ("shr", "sar", "shl") and len(ops) == 2 and ops[1][0] == "imm":
                step = (m, ops[1][1] & 31)
            elif tracked and m == "and" and len(ops) == 2 and ops[1][0] == "imm":
                step = ("and", ops[1][1])
            elif tracked and m in ("neg", "not"):
                step = (m,)
            elif tracked and m in ("or", "test") and len(ops) == 2 and ops[0] == ops[1]:
                return
            if step is not None and len(cur[4]) < 8:
                self.loads[r32] = cur[:4] + (cur[4] + (step,), cur[5])
            elif m != "push":
                self.loads.pop(r32, None)
                self.sub_pc.pop(r32, None)
        if insn.kind == "call":
            for r in ("eax", "ecx", "edx"):
                self.loads.pop(r, None)
                self.sub_pc.pop(r, None)

    def _plant_walk(self, insn):
        """(round 10, walkend) A discovery run at the compare of a runaway list or tree walk (`mov eax, [ebp]; cmp eax,
        ecx; jne` with ecx = &tree.nil, or `mov ebp, [ebp]; test ebp, ebp; jne`): after one to three rounds the link
        just loaded (a plain load, in this memory epoch) is planted as the sentinel the compare waits for, and the
        register follows, so each walk ends after a few links, in every epoch it runs in.

        (round 11, walkheads) Many walks at one compare (127 circular bins `for (c = bin->next; c != bin; c =
        c->next)`, each with its own sentinel): fuzzed nodes alias, so a link one walk got planted with its
        sentinel is another walk's path, and the input with the plants ran away where the discovery run did not. A
        link some walk already loaded is never planted (the input then reads what the discovery run read); a
        walk's first node whose link was loaded before ends the walk at its head instead (the top test, `cmp eax,
        edx; je` before the loop, gets the sentinel: an empty bin), and a walk ends at the latest at the link
        before one loaded before."""
        A = Program._ALIAS
        pc = insn.addr
        heads = "walkheads" not in EQUIV_OFF
        head_of = self.walk_heads.get(pc) if heads else None
        side = self.count_walks[pc]
        ops = insn.ops
        if len(ops) != 2:
            return
        if head_of is None:
            self.walk_rounds[pc] += 1
        try:
            if side == "zero":
                if insn.mnemonic != "test" or ops[0] != ops[1] or ops[0][0] != "reg":
                    return
                link, sv = ops[0], 0
            else:
                link, sent = ops[1 - side], ops[side]
                sv = self.reg(sent[1]) if sent[0] == "reg" else sent[1] if sent[0] == "imm" else \
                    int.from_bytes(self.uc.mem_read(self._ea(sent[1]), 4), "little")
        except Exception:   # noqa: BLE001
            return
        if link[0] == "mem":
            ea = self._ea(link[1])
            if (link[1][5] or 4) != 4:
                return
            reg32 = None
        elif link[0] == "reg" and link[1] in Program._REGS:
            reg32 = A.get(link[1], link[1])
            src = self.loads.get(reg32)
            if src is None or src[3] != link[1] or src[4] or not isinstance(src[0], int) or src[1] != 4 or \
                    src[2] != self.epoch:
                return
            ea = src[0]
            try:
                if int.from_bytes(self.uc.mem_read(ea, 4), "little") != self.reg(reg32):
                    return
            except Exception:   # noqa: BLE001
                return
        else:
            return
        if heads:
            cur = int.from_bytes(self.uc.mem_read(ea, 4), "little")
            key = (self.epoch, ea)
            wpc = head_of if head_of is not None else pc
            if head_of is not None:
                self.walk_inst[wpc] += 1
            inst = (wpc, self.walk_inst[wpc])
            # (a link this same walk loaded before is fine: planting it only ends the walk sooner in the input)
            seen_before = self.walk_seen.get(key, inst) != inst
            self.walk_seen.setdefault(key, inst)
            ok_at = lambda a: not (STACK_LO <= a < STACK_HI or _reserved(a) or self.prog.is_code(a) or
                                   not _patchable(a, False))
            if head_of is not None:
                # the top test: a new walk starts at this node
                self.walk_prev[head_of] = cur
                self.walk_rounds[head_of] = 0
                disp = self.walk_disp.get(head_of)
                if seen_before or disp is None or cur == (sv & M32) or not ok_at(ea):
                    return
                nxt = (cur + disp) & M32
                if (self.epoch, nxt) not in self.walk_seen and ok_at(nxt):
                    return          # its first link is fresh: the walk runs, and ends at the compare
            else:
                prev = self.walk_prev.get(pc)
                if prev is not None and pc not in self.walk_disp and 0 <= ea - prev < 0x1000:
                    self.walk_disp[pc] = ea - prev
                self.walk_prev[pc] = cur
                if seen_before:
                    return          # another walk (or this one) loaded it before: planting it changes that walk
                want = 1 + mix(self.inp["seed"], pc, len(self.count_plants), 0x3A1) % 3
                disp = self.walk_disp.get(pc)
                nxt = (cur + disp) & M32 if disp is not None else None
                last = nxt is not None and ((self.epoch, nxt) in self.walk_seen or not ok_at(nxt))
                if self.walk_rounds[pc] < want and not last:
                    return
        elif self.walk_rounds[pc] < 1 + mix(self.inp["seed"], pc, len(self.count_plants), 0x3A1) % 3:
            return
        if STACK_LO <= ea < STACK_HI or _reserved(ea) or self.prog.is_code(ea) or not _patchable(ea, False):
            return
        bs = (sv & M32).to_bytes(4, "little")
        self.uc.mem_write(ea, bs)
        if reg32 is not None:
            self.uc.reg_write(_uc_regs()[reg32], sv & M32)
        self.count_plants[(self.epoch, ea)] = bs
        if head_of is None:
            self.walk_rounds[pc] = 0
            self.walk_inst[pc] += 1

    def _plant_diff(self, insn):
        """(round 10, diffcount) A discovery run at `sub end, begin` of a runaway loop's bound: one of the two words is
        planted so that the transforms after the sub (`sar edx, 2`) turn the difference into a count of 1-4, and the
        register follows. The end word when it is a plain load (in this memory epoch, or a stack argument:
        `nfixargs - actual`), else the begin word. A bound re-read after every call gets one in every epoch, each
        relative to the other word as that epoch has it."""
        A = Program._ALIAS
        ops = insn.ops
        if insn.mnemonic != "sub" or len(ops) != 2 or ops[0][0] != "reg":
            return
        r = ops[0][1]
        r32 = A.get(r, r)
        try:
            e = self.reg(r32)
            kind, v = ops[1]
            if kind == "reg":
                b = self.reg(v)
            elif kind == "mem":
                b = int.from_bytes(self.uc.mem_read(self._ea(v), 4), "little")
            else:
                return
        except Exception:   # noqa: BLE001
            return
        xa = self.count_diffs[insn.addr]
        c = (e - b) & M32
        for op in xa:
            c = _apply_xf(op, c)
        if c <= (1 if self.count_tiny else 16):
            return              # (already a small count)
        h_ = mix(self.inp["seed"], insn.addr, len(self.count_plants), 0x5C1)
        k = 1 + h_ % 4
        if "diffwide" not in EQUIV_OFF and (h_ >> 8) % 4 == 0:
            # (round 11, diffwide) one plant in four is 5-12 elements: a tie-break network over the elements of a
            # vector (0x00039c60) needs more than four of them in a row to reach its later compares
            k = 5 + (h_ >> 16) % 8
        if self.count_tiny:
            k = 1 if mix(self.inp["seed"], insn.addr, len(self.count_plants), 0x5C2) % 4 == 0 else 0
        d = _invert_xf(xa, (e - b) & M32, k)
        if d is None:
            return
        c = d
        for op in xa:
            c = _apply_xf(op, c)
        if c != k:
            return

        def word(ea):
            try:
                return int.from_bytes(self.uc.mem_read(ea, 4), "little")
            except Exception:   # noqa: BLE001
                return None

        def mem_ok(ea, ep):
            return not STACK_LO <= ea < STACK_HI and not _reserved(ea) and not self.prog.is_code(ea) and \
                _patchable(ea, False) and ep == self.epoch
        nst = len(self.inp["stack"])
        src = self.loads.get(r32)
        if src is not None and src[3] == r and not src[4] and isinstance(src[0], int) and src[1] == 4 and \
                word(src[0]) == e:
            ea, ne = src[0], (b + d) & M32
            if mem_ok(ea, src[2]):
                key = (self.epoch, ea)
            elif ENTRY_ESP + 4 <= ea < ENTRY_ESP + 4 + 4 * nst and (ea - ENTRY_ESP - 4) % 4 == 0:
                key = ("stack", (ea - ENTRY_ESP - 4) // 4)       # (an argument: `nfixargs - (top - base)/8`)
            else:
                key = None
            if key is not None:
                self.uc.mem_write(ea, ne.to_bytes(4, "little"))
                self.uc.reg_write(_uc_regs()[r32], ne)
                self.count_plants[key] = ne.to_bytes(4, "little") if key[0] != "stack" else ne
                return
        # the begin word instead (`sub eax, [esi+8]`, or a register loaded plainly from memory)
        nb = (e - d) & M32
        if kind == "mem":
            ea = self._ea(v)
            if (v[5] or 4) == 4 and mem_ok(ea, self.epoch):
                self.uc.mem_write(ea, nb.to_bytes(4, "little"))
                self.count_plants[(self.epoch, ea)] = nb.to_bytes(4, "little")
            return
        v32 = A.get(v, v)
        s2 = self.loads.get(v32)
        if s2 is not None and s2[3] == v and not s2[4] and isinstance(s2[0], int) and s2[1] == 4 and \
                word(s2[0]) == b and mem_ok(s2[0], s2[2]):
            self.uc.mem_write(s2[0], nb.to_bytes(4, "little"))
            self.uc.reg_write(_uc_regs()[v32], nb)
            self.count_plants[(self.epoch, s2[0])] = nb.to_bytes(4, "little")

    def _on_code(self, uc, addr, size, _):
        self.nsteps += 1
        try:
            if TRAMP <= addr < TRAMP + PAGE:
                return
            if self.helper_ret is not None:
                if addr != self.helper_ret:
                    return
                self.helper_ret = None
                if self.ftol_pending is not None:
                    # (round 9, ftolsrc) `call __ftol2` on a steerable float: eax is that float truncated, and an
                    # integer compare on it (`cmp eax, 8; jge`) is steered through the float's source
                    e_ = self.ftol_pending
                    self.ftol_pending = None
                    v_ = self.reg("eax")
                    key_ = ("ftol", e_["src"], tuple(e_.get("fxf") or ()), tuple(e_.get("ixf") or ()), e_.get("raw"),
                            e_.get("abs", True))
                    self.loads["eax"] = (key_, 4, self.epoch, "eax", (), v_)
                    if self.fstack:
                        del self.fstack[0]      # (the helper popped it)
            if self.wild_check and not self.view.in_body(addr) and addr not in self.view.insns and \
                    not (self.local_code and self.local_code[0] <= addr < self.local_code[1]):
                # control left the function's code: a return address, saved register or function pointer
                # the run overwrote through a wild pointer, or a fuzzed code pointer. The real game never
                # gets here; stop before running junk (whose effects depend on each side's layout)
                self.fault = self.fault or ("wild_jump", addr)
                uc.emu_stop()
                return
            insn = self.view.decode(addr)
            # Unicorn sometimes restarts an instruction (the code hook fires again for the same address)
            # and loses lazily computed flags on the way (a cmp; mov [m], r; jb then branches differently
            # in two runs of identical code). Put back the flags it had the first time.
            fl = self.uc.reg_read(self.u.UC_X86_REG_EFLAGS)
            if self.last_insn is not None and self.last_insn[0] == addr and insn is not None \
                    and not insn.op_str.startswith(("byte ptr es:", "dword ptr es:")) \
                    and not insn.mnemonic.startswith(("rep", "cmps", "scas", "movs", "stos", "lods")) \
                    and not (insn.kind in ("jmp", "jcc", "call") and insn.target == addr):
                if fl != self.last_insn[1]:
                    self.uc.reg_write(self.u.UC_X86_REG_EFLAGS, self.last_insn[1])
                    fl = self.last_insn[1]
            if self.rmw_undo is not None:
                if self.last_insn is not None and self.last_insn[0] == addr and self.rmw_undo[0] == addr and insn is not None and \
                        not insn.mnemonic.startswith(("rep", "cmps", "scas", "movs", "stos", "lods")):
                    # (round 14, rmwundo) the same read-modify-write delivered again after its store went through
                    for a_, old_ in reversed(self.rmw_undo[1]):
                        uc.mem_write(a_, old_)
                    self.rmw_undo_n = getattr(self, "rmw_undo_n", 0) + 1
                self.rmw_undo = None
            self.last_insn = (addr, fl)
            if insn is not None and insn.mem is not None and insn.mem[1] is None and insn.mem[2] is None \
                    and insn.mem[4] == SECURITY_COOKIE and insn.mnemonic != "lea":
                try:
                    self.cookies.add(self._read_u32(SECURITY_COOKIE))
                except Exception:
                    pass
            self.cur_insn = insn
            if self.coverage is not None and insn is not None:
                rd, wr = self.view.eax_rw(addr)
                if rd:
                    self.eax_read = True
                    if "derefonly" in EQUIV_OFF or not self.view.eax_base_only(addr):
                        self.eax_vread = True
                if wr:
                    self.eax_def, self.eax_read = ("insn", wr, addr), False
                    if insn is not None and insn.mnemonic in ("fnstsw", "fstsw"):
                        self.ax_status = True       # ax holds the x87 status word (no source form)
                    elif wr > 8:
                        self.ax_status = False
            if insn is not None and insn.mem is not None and insn.mnemonic not in ("lea", "nop"):
                # Map the operand's page before the instruction runs. A lazy map from the fault hook
                # restarts the instruction, and Unicorn can lose lazily computed flags across that restart
                # (a cmp; mov [unmapped], x; jb sequence then branches differently between two runs).
                ea = self._ea(insn.mem)
                for pg in {ea & ~0xFFF, (ea + max(insn.mem[5] or 4, 1) - 1) & ~0xFFF}:
                    if pg not in self.mapped and not any(lo <= pg < hi for lo, hi in RESERVED) \
                            and len(self.mapped) <= 1000:
                        try:
                            uc.mem_map(pg, PAGE)
                        except Exception:
                            continue                    # already mapped (stack, our image, ...)
                        uc.mem_write(pg, self.m.page(pg, self.epoch))
                        self.mapped.add(pg)
            if insn is None:
                raise Fault("undecodable")
            if self.count_walks and addr in self.count_walks:
                self._plant_walk(insn)
            elif self.count_diffs and addr in self.count_diffs:
                self._plant_diff(insn)
            elif self.count_pcs and addr in self.count_pcs and insn.mem is not None and insn.mnemonic != "lea":
                # (round 9, smallcount) a discovery run: a load that fed a runaway loop's bound reads a small count
                ea = self._ea(insn.mem)
                sz = insn.mem[5] or 4
                if sz in (1, 2, 4) and not STACK_LO <= ea < STACK_HI and not _reserved(ea) and \
                        not self.prog.is_code(ea) and _patchable(ea, False):
                    try:
                        cur = int.from_bytes(uc.mem_read(ea, sz), "little")
                    except Exception:   # noqa: BLE001
                        cur = None
                    if self.count_tiny and cur is not None and 1 < cur:
                        # (round 10, tinycount) counts of 0 or 1, from every count word not already that small
                        b_ = (1 if mix(self.inp["seed"], ea, 0x5C2) % 4 == 0 else 0).to_bytes(sz, "little")
                        uc.mem_write(ea, b_)
                        self.count_plants[(self.epoch, ea)] = b_
                    elif cur is not None and 16 < cur < (1 << (8 * sz)) - 16:
                        b_ = (1 + mix(self.inp["seed"], ea, 0x5C0) % 4).to_bytes(sz, "little")
                        uc.mem_write(ea, b_)
                        self.count_plants[(self.epoch, ea)] = b_
            if self.coverage is not None and insn.mem is not None and insn.mem[1] in ("esp", "ebp") and insn.mem[2] \
                    and insn.mem[2] not in ("esp", "ebp") and "idxfill" not in EQUIV_OFF and len(self.idx_fills) < 16:
                # (round 10, idxfill) `mov eax, [esp+0xa0]; shl eax, 4; fstp [esp+eax+0x20]`: a word a stub filled
                # (a count in a Lay object FUN_000f7fe0 builds) indexes an array in the frame
                ix_ = self.loads.get(Program._ALIAS.get(insn.mem[2], insn.mem[2]))
                if ix_ is not None and isinstance(ix_[0], tuple) and ix_[0][0] == "fill" and len(ix_[0]) >= 4 and \
                        ix_[0][3] >= 0:
                    self.idx_fills.add(tuple(ix_[0][1:4]))
            if self.fill_watch:
                self._check_readback(insn)
            if insn.mnemonic.startswith("rep") and self.reg("ecx") > 0x100000:
                self.huge_rep = True
            if insn.mnemonic.startswith("rep") and self.reg("ecx") > 0x2000 and "rep" not in EQUIV_OFF:
                if self.coverage is not None and self.rep_obs is None:
                    # a fill or copy of a fuzzed, absurd size (`rep stosd` over count*4 bytes): loop repair
                    # patches the count's source down to a few elements, as for a loop bound
                    info = self._reg_info("ecx")
                    if info["src"]:
                        self.rep_obs = {"addr": addr, "mnemonic": "cmp",
                                        "ops": [info, {"val": 8, "src": None, "imm": 8}]}
            if self.coverage is not None:
                self.executed.add(addr)
                if self.prev_jcc is not None:
                    self.edges.add((self.prev_jcc, addr))
                self.prev_jcc = addr if insn.kind == "jcc" or addr in self.view.tables else None
                if addr in self.view.tables and insn.mem is not None and insn.mem[2] and "caseidx" not in EQUIV_OFF:
                    # (round 15) the case index, not only the target: two indices sharing a target are two cases
                    self.edges.add((addr, ("idx", self.reg(insn.mem[2]))))
                if self.prev_set is not None:
                    pa, pr = self.prev_set
                    try:
                        v_ = self.uc.mem_read(pr[1], 1)[0] if isinstance(pr, tuple) else self.reg(pr)
                        self.edges.add((pa, "set%d" % (v_ & 1)))
                    except Exception:
                        pass
                    self.prev_set = None
                if insn.mnemonic.startswith("set") and insn.regs:
                    self.prev_set = (addr, insn.regs[0])
                elif insn.mnemonic.startswith("set") and insn.mem is not None and "setmem" not in EQUIV_OFF:
                    # (round 8) `sete byte ptr [esp + 0x1c]`: the outcome is the byte it stores (it was never
                    # counted, so both sides of such a setcc stayed uncovered)
                    try:
                        self.prev_set = (addr, ("mem", self._ea(insn.mem)))
                    except Exception:
                        pass
                if insn.mnemonic.startswith(("repe cmps", "repz cmps")):
                    self._note_rep_cmps(insn)
                if insn.mem is not None and "objptr" not in EQUIV_OFF:
                    self._note_deref(insn)
                self._observe(insn)
            if insn.ops and insn.ops[0][0] == "reg" and insn.ops[0][1] in ("ecx", "cx", "cl", "ch") and \
                    insn.mnemonic not in ("cmp", "test", "push"):
                self.ecx_dirty = True
            esp = self.reg("esp")
            if esp > self.prev_esp and esp - self.prev_esp <= 0x10000:
                # stack released (pop, add esp, ret): what was written there is dead; if alloca or a later
                # push reuses it, it isn't data the function wrote
                for x in range(self.prev_esp, esp):
                    self.stack_written.discard(x)
                    self.func_stack_written.discard(x)
                    self.array_written.discard(x)
                    self.fill_watch.pop(x, None)
            if esp != self.prev_esp and self.save_slots:
                # a return address or saved register below esp is dead: once `sub esp` reuses the slot (a
                # by-value argument built in place) it is free space, not a frame boundary
                self.save_slots = {x for x in self.save_slots if x >= esp}
            self.prev_esp = esp
            if insn.mnemonic == "lea" and insn.mem is not None and insn.mem[1] in ("esp", "ebp") \
                    and not insn.mem[2] and addr not in self.prologue:
                ta = self._ea(insn.mem)
                if ta % 4 == 0 and STACK_LO <= ta < STACK_HI:
                    self.addr_taken.add(ta)
            if self.tracked:
                self.tracked = {t for t in self.tracked if t >= esp}
            m = insn.mnemonic
            if m == "push" and insn.regs:
                # an argument pushed from a register only partly written (`setcc al; push eax`): a bool or char
                # whose upper bytes are garbage
                self.push_width[esp - 4] = self.reg_width.get(insn.regs[0], 32)
            # (`mov edi, edi` / `lea esi, [esi]`: alignment padding, not a write; a lazy `push edi` after it
            # is still a register save)
            nop_move = insn.mem is None and m in ("mov", "xchg") and len(insn.regs) == 2 and \
                insn.regs[0] == insn.regs[1] or m == "lea" and len(insn.regs) == 1 and insn.mem is not None and \
                insn.mem[1] == insn.regs[0] and not insn.mem[2] and not insn.mem[4]
            for r_, b_ in self.view.write_widths(addr).items():
                self.reg_width[r_] = b_
                if m != "pop" and not nop_move:
                    self.reg_dirty.add(r_)
            if m == "push":
                # (not a register the function set itself that happens to hold its entry value: `xor edi, edi;
                # push edi` with edi 0 on entry, as a recorded game state has it)
                if insn.regs and insn.regs[0] in CALLEE_SAVED and self.reg(insn.regs[0]) == self.inp["regs"][insn.regs[0]] \
                        and insn.regs[0] not in self.reg_dirty and insn.regs[0] in self.view.popped_regs():
                    # a (possibly lazy) save of a callee-saved register; without a matching pop somewhere it is
                    # an argument (an LTCG register argument passed on, e.g. esi)
                    self.save_slots.add(esp - 4)
                elif addr not in self.prologue:
                    self.tracked.add(esp - 4)
            elif m == "sub" and insn.op_str.startswith("esp,") and insn.imms and addr not in self.prologue \
                    and insn.imms[0] <= 64 and (self.calls or self.tracked or esp != ENTRY_ESP):
                # (sub esp, N before anything was pushed or called is the frame, even after a few movs)
                self.tracked.update(range(esp - insn.imms[0], esp, 4))
            if insn.kind == "call":
                if insn.target is not None:
                    target = insn.target
                elif insn.mem is not None:
                    target = self._read_u32(self._ea(insn.mem))
                else:
                    target = self.reg(insn.regs[0])
                if target in self.helpers:
                    if self.coverage is not None and self.helpers[target] == "__ftol2" and self.fstack and \
                            self.fstack[0] is not None and self.fstack[0].get("src") is not None and \
                            "ftolsrc" not in EQUIV_OFF:
                        self.ftol_pending = dict(self.fstack[0])
                    if self.coverage is not None and self.helpers[target] in STRCMP_HELPERS:
                        a0, a1, a2 = (self._read_u32(esp + 4 * i) for i in range(3))
                        n = a2 if self.helpers[target] == "_strncmp" else None
                        self._note_str(addr, a1, a0, n)
                        self._note_str(addr, a0, a1, n)
                    self.helper_ret = addr + size
                    self.eax_def, self.eax_read = ("helper", 32), False      # CRT helper: not ours to return
                    self.ax_status = False
                    return
                if self.view.in_body(target) and target != self.view.entry:
                    if insn.target is None and self.wild_check:
                        # a function pointer read from fuzzed memory that lands inside the function itself
                        # (an unaligned read of a heap pointer and a small int spells 0x0013400c): one side
                        # runs its own code from there, the other (whose code is elsewhere) stubs a call
                        self.fault = self.fault or ("wild_call", target)
                        uc.emu_stop()
                    return
                direct = insn.target is not None      # a relocated call, not a pointer from fuzzed memory
                if direct and target in IGNORED_CALLS:
                    if self.reg("ecx") not in self.cookies:
                        self.cookie_bad = self.cookie_bad or len(self.calls) + 1
                    esp = self.reg("esp") - 4
                    uc.mem_write(esp, struct.pack("<I", addr + size))
                    uc.reg_write(self.u.UC_X86_REG_ESP, esp)
                    uc.reg_write(self.u.UC_X86_REG_EIP, TRAMP)       # ret
                    return
                if direct and self.self_alias is not None and target == self.view.entry:
                    self._stub(insn, self.self_alias, tail=False)      # recursion: stubbed like the original's
                    return
                if direct and self.local_code and self.local_code[0] <= target < self.local_code[1]:
                    # a function of our own object: executes in place, like inlined code (its prologue's
                    # register saves aren't arguments of the calls it makes)
                    if target not in self.local_entries:
                        self.local_entries.add(target)
                        self.prologue |= CodeView(self.view.read, target, None, self.prog, is_ours=True).prologue()
                    self.tracked = set()      # the words pushed for it are its arguments
                    return
                if direct and target in self.intrinsics:
                    self._intrinsic(insn, self.intrinsics[target], tail=False)
                    return
                self._stub(insn, target, tail=False)
                if direct and self.prog.noreturn(target):
                    # a callee that never returns (longjmp, an error throw): the run ends here on both sides
                    self.noreturn = True
                    uc.emu_stop()
            elif insn.kind == "jmp":
                if insn.target is not None:
                    target = insn.target
                    if self.view.internal_target(target) and target != self.view.entry:
                        return
                elif insn.mem is not None:
                    if addr in self.view.tables:
                        return
                    target = self._read_u32(self._ea(insn.mem))
                    # (a jump through a pointer read from memory is a tail call: a fuzzed vtable entry
                    # that happens to point into some unnamed chunk of .text isn't part of the function)
                    if self.view.in_body(target) and target != self.view.entry:
                        return
                else:
                    target = self.reg(insn.regs[0])
                    if self.view.in_body(target) and target != self.view.entry:
                        return
                direct = insn.target is not None
                if direct and self.self_alias is not None and target == self.view.entry:
                    self._stub(insn, self.self_alias, tail=True)
                    return
                if direct and self.local_code and self.local_code[0] <= target < self.local_code[1]:
                    # a tail jump into another function of our object (`jmp ??1SimpleChannel` ending a derived
                    # destructor): it runs in place, and its prologue's register saves aren't arguments
                    if target not in self.local_entries and "localjmp" not in EQUIV_OFF:
                        self.local_entries.add(target)
                        self.prologue |= CodeView(self.view.read, target, None, self.prog, is_ours=True).prologue()
                    return
                if direct and target in self.intrinsics:
                    self._intrinsic(insn, self.intrinsics[target], tail=True)
                    return
                if direct and target in self.helpers and "tailhelper" not in EQUIV_OFF:
                    # (round 7) a tail jump to a CRT helper (`jmp _ftol`, the float still in st0): it runs for
                    # real, as a call to it does, and returns to our caller. Stubbed, its float operand was
                    # never compared, and the incoming arguments counted as its stack words (an equiv-conv
                    # function under test has other stack words on each side)
                    self.helper_ret = self._read_u32(self.reg("esp"))
                    self.eax_def, self.eax_read = ("helper", 32), False
                    self.ax_status = False
                    return
                self._stub(insn, target, tail=True)
                if direct and self.prog.noreturn(target):
                    self.noreturn = True
                    uc.emu_stop()
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
        elif self.noreturn:
            out["noreturn"] = True          # ended in a call that never returns: compared up to there
        elif eip != SENTINEL:
            out["status"] = "timeout"
        if self.loop_abort:
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
        out["cookie_bad"] = self.cookie_bad
        out["abi_mismatch"] = self.abi_mismatch
        # eax holds a value the function means to leave there: a callee's result the function used and then
        # kept (`p = alloc(); if (p) ...; return p`), or a write it never reads back on any path (only a
        # return value explains a dead write). A callee's result left unread is ambiguous (`g();` and
        # `return g();` compile alike), so it doesn't count.
        d = self.eax_def
        # an x87 status word left in ax by a float branch (`fnstsw ax; test ah, 0x41; ...; mov al, 1; ret`):
        # bytes no source can produce, so only what was written after it (al) is a result
        out["eax_fnstsw"] = None
        if self.ax_status and d and d[0] == "insn":
            out["eax_fnstsw"] = 8 if d[1] == 8 else 0
            if d[1] != 8:
                d = None
        # (round 8, derefonly) A callee's result that was only dereferenced (`f()->state == 1`, `cmp [eax +
        # 0x221c], ebx`) is as ambiguous: `use(f()->x)` and `p = f(); use(p->x); return p` compile alike
        out["eax_defined"] = d[1] if d and ((d[0] == "call" and self.eax_read and self.eax_vread) or (d[0] == "insn" and not self.eax_read and
                                                                self.view.eax_dead_after(d[2]))) else None
        out["segments"] = self.segments
        out["seg_fpu"] = self.seg_fpu
        out["epochs"] = self.epoch
        out["max_mapped"] = max(self.max_mapped, len(self.mapped))
        out["huge_rep"] = self.huge_rep
        out["steps"] = self.nsteps
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
                elif sym == self.func_sym and typ == DIR32 and getattr(self, "orig_addr", None) is not None:
                    S = self.orig_addr      # &self (a stored function pointer): the original's own address
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
            # (a call is a call even to an address functions.csv doesn't list as a function)
            if not view.internal_target(i.target) or (i.kind == "call" and not view.in_body(i.target)) \
                    or (i.kind == "call" and i.target == view.entry):
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


def vftable_by_name(prog, name):
    """'??_7File@core@@6BIMutable@1@@' -> the vftable of core::File's IMutable subobject (None if unknown).

    A class with several vftables is only bound when the base qualifier names one of its RTTI bases;
    otherwise the vftable is left to instruction pairing (invented base names are common)."""
    try:
        p = _Parser(name[4:])
        cls = p.qualified_name()
        base = None
        if p.peek(2) == "6B":
            p.take(2)
            if p.peek() != "@":
                base = p.qualified_name()
    except (DemangleError, IndexError):
        return None
    from msvc_demangle import demangle_type_name
    keys = [prefix + name[4:].split("@6B")[0] + "@" for prefix in (".?AV", ".?AU")]
    if "fn_" in name and not any(k in prog.rtti for k in keys) and "treens" not in EQUIV_OFF:
        # (round 7: a class declared inside the `namespace fn_<addr>` of a merged source-tree object: look
        # its RTTI up by the demangled name without that namespace)
        idx = getattr(prog, "_rtti_by_dname", None)
        if idx is None:
            idx = prog._rtti_by_dname = {}
            for k_ in prog.rtti:
                try:
                    idx.setdefault(demangle_type_name(k_), k_)
                except Exception:   # noqa: BLE001 - an odd RTTI name: not indexed
                    pass
        hit = idx.get(_TREE_NS.sub("", cls))
        keys = [hit] if hit else []
        base = _TREE_NS.sub("", base) if base else base
    for mang in keys:
        c = prog.rtti.get(mang)
        if c is None:
            continue
        vts = c["vtables"]
        if len(vts) == 1:
            return vts[0]["address"]
        if base is None:
            return None
        for b in c.get("bases", []):
            try:
                bname = demangle_type_name(b["name"])
            except DemangleError:
                continue
            if bname == base or bname.split("::")[-1] == base.split("::")[-1] and bname.endswith(base):
                for vt in vts:
                    if vt["offset"] == b["mdisp"]:
                        return vt["address"]
        return None
    return None


def name_address(prog, name):
    """An original address encoded in, or looked up by, a symbol name; None if the name says nothing."""
    if name in BUILTIN_NAMES:
        return BUILTIN_NAMES[name], "builtin"
    crt = crt_table(prog)
    if name in crt:
        return crt[name], "crt"
    if len(prog.names.get(name, [])) == 1:          # functions.csv keeps some names mangled (the CRT's undname)
        return prog.names[name][0], "name"
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
    strong_votes = defaultdict(Counter)    # from pairs whose bytes agree outside the relocated field
    for oi, ri in pairs:
        if oi.size != ri.size or oi.mnemonic != ri.mnemonic:
            continue
        ob, rb = prog.read(oi.addr, oi.size), ours.read(ri.addr, ri.size)
        masked = {i for site in rel_at for i in range(site - ri.addr, site - ri.addr + 4) if 0 <= site - ri.addr < ri.size}
        strong = all(ob[i] == rb[i] for i in range(oi.size) if i not in masked)
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
            if strong:
                strong_votes[sym[0]][t] += 1
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
            if cand is None and lit and lit.rstrip(b"\0") and len(lit.rstrip(b"\0")) < len(lit):
                # a char array without its terminator in the original (`L"()"` packed among other pairs:
                # "()[]{}"): the bytes the code reads still match
                body = lit.rstrip(b"\0")
                body += b"\0" * (len(body) % 2 if name.startswith("??_C@_1") else 0)
                hits = sorted((t for t in oaddrs if prog.read(t, len(body)) == body),
                              key=lambda t: (t not in pair_votes.get(name, {}), prog.section_name(t) != ".rdata", t))
                cand = (hits[0], "string") if hits else None
            if cand is None:
                cand = (None, "string_not_in_original")
        elif name.startswith("__real@"):
            want = bytes.fromhex(name[len("__real@"):])[::-1]
            # (read-only data only: a writable global that happens to hold 0.0 in the image is a variable)
            hits = sorted((t for t in oaddrs if prog.read(t, len(want)) == want
                           and prog.section_name(t) in (".rdata", ".text")),
                          key=lambda t: (t not in pair_votes.get(name, {}), prog.section_name(t) != ".rdata", t))
            cand = (hits[0], "float") if hits else (None, "float_local")
        elif name.startswith("??_7"):
            v = vftable_by_name(prog, name)
            if v is not None:
                cand = (v, "vftable")
        elif name.startswith("??_R0?") and name.endswith("@8"):
            # an RTTI type descriptor (dynamic_cast's source/target type), by class name: with two casts in
            # one function, pairing by position can swap them
            v = prog.typedescs.get("." + name[5:-2])
            if v is None and "fn_" in name and "treens" not in EQUIV_OFF:
                # (round 7: a class inside a merged tree object's `namespace fn_<addr>`)
                from msvc_demangle import demangle_type_name
                try:
                    want = _TREE_NS.sub("", demangle_type_name("." + name[5:-2]))
                    v = next((a_ for k_, a_ in prog.typedescs.items() if _safe_dname(k_) == want), None)
                except Exception:   # noqa: BLE001 - unparsable: left to the other rules
                    v = None
            if v:
                cand = (v, "rtti")
        if cand is None and use_names:
            na = name_address(prog, name)
            if na:
                cand = na
        votes = pair_votes.get(name)
        if cand is None and sym[2] > 0 and sym[3] == 0x20 and not name.startswith(VECTOR_ITERATORS):
            votes = None      # a function defined in our object (e.g. not inlined here): it runs in place
        if name in INTRINSIC_NAMES and cand is None:
            votes = None      # a CRT routine the XBE doesn't have out of line: runs semantically
        if name.startswith(("__real@", "??_C@")):
            votes = None      # constants bind by content only, never by position
        if votes:
            t, n = votes.most_common(1)[0]
            # Pairing is evidence against a name only when the whole function is byte-identical; in other
            # code the alignment can pair different statements of the same shape (a[0] vs a[1]).
            sv = strong_votes.get(name)
            if exact and sv and cand is not None and cand[0] is not None and cand[1] not in ("string", "float"):
                st, _ = sv.most_common(1)[0]
                if st != cand[0] and cand[0] not in sv:
                    conflicts.append({"symbol": name, "claimed": "0x%08x" % cand[0], "code": "0x%08x" % st,
                                      "how": cand[1]})
                    if exact and cand[1] != "explicit":
                        cand = (st, "paired")
            if cand is None:
                cand = ((sv or votes).most_common(1)[0][0], "paired")
            if exact and sv and len(sv) > 1:
                conflicts.append({"symbol": name, "inconsistent": ["0x%08x" % v for v in sv]})
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
        if sym is None:
            continue
        if sym == ours.func_sym:
            if typ == REL32 and getattr(ours, "orig_addr", None) is not None:
                out.append(("call", ours.orig_addr, sym[0]))      # a recursive call
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
    ours.imm_floats = set()
    for a, i in rview.insns.items():
        if any(s in rel_sites for s in range(a, a + i.size)):
            continue
        imms.update(i.imms)
        ours.imm_floats |= _imm_floats(i)
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
    # 2^32, the bias of an unsigned-to-float conversion (`fild; test; jge; fadd [2^32]`): the original's
    # float and our build's double are the same constant
    two32 = {"__real@41f0000000000000", "__real@4f800000"}
    two32_ours = any(t is None and n in two32 for k, t, n in refs)
    two32_orig = {t for t in o_float if prog.read(t, 4) == struct.pack("<f", 4294967296.0) or
                  prog.read(t, 8) == struct.pack("<d", 4294967296.0)}
    for k, t, n in refs:
        if t is None and n in two32 and two32_orig:
            continue
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
    for t in sorted(o_data - r_data - imms):     # (a literal address in our source is fine too)
        kind = "missing_data_ref_interior" if near_ours(t) else "missing_data_ref"
        issues.append({"kind": kind, "target": "0x%08x" % t, "section": prog.section_name(t)})
    for t in sorted(o_float - r_data):
        if t in two32_orig and two32_ours:
            continue
        issues.append({"kind": "missing_float_constant", "target": "0x%08x" % t})
    for t in sorted(r_data - o_data - o_float - o_imm - {oview.entry}):     # (&self: the original's too)
        n = [x for k, tt, x in refs if tt == t]
        interior = any(0 < abs(t - x) < 16 for x in o_data | o_imm)     # e.g. one byte of a global
        # (or another element of a global the original references too: a loop's induction base at a
        # different field of the same object; level 3 checks the accesses)
        interior = interior or any(resolved.get(x) in (o_data | o_imm) for x in n)
        issues.append({"kind": "extra_data_ref_interior" if interior else "extra_data_ref",
                       "target": "0x%08x" % t, "symbol": n[0] if n else None})
    for t in sorted(o_imm - r_data - imms - o_data):
        issues.append({"kind": "missing_address_constant", "target": "0x%08x" % t, "section": prog.section_name(t)})
    if "fconst" not in EQUIV_OFF:
        o_imm_f = set()
        if "immfloat" not in EQUIV_OFF:
            for i in oview.insns.values():
                o_imm_f |= _imm_floats(i)
        issues += _float_const_diffs(prog, oview, refs, o_float - r_data, o_imm_f,
                                     getattr(ours, "imm_floats", set()) if "immfloat" not in EQUIV_OFF else set())
    return issues


def _imm_floats(i):
    """(round 15, `immfloat`) The immediates of a `mov`/`push` that read as normal floats (`mov dword [esi+0x38],
    0x3e32b8c3`, `push 0x3f800000`): a float literal stored without a constant in memory. Addresses in the image,
    small integers and denormal patterns aren't floats."""
    if i.mnemonic not in ("mov", "push") or not i.imms:
        return set()
    if i.mem is not None and i.mem[5] != 4:
        return set()          # a byte or word store
    out = set()
    for v in i.imms:
        e = (v >> 23) & 0xff
        if v > 0xffff and 0 < e < 0xff and not _in_image(v):
            out.add(v)
    return out


FCONST_TOL = 1e-4       # (round 13, fconst) relative: what a mistyped literal looks like (3-7 digits right)


def _float_const_diffs(prog, oview, refs, o_left, o_imm=(), r_imm=()):
    """(round 13, fconst) A float constant of ours the original doesn't have, when the original reads a constant
    it doesn't share with us that is nearly the same value: `0.0174533f` (0x3c8efa39) where the original has
    pi/180 = 0x3c8efa35, `0.003921569f` for 1/255 (0x3b808081). Level 3 compares floats with a relative
    tolerance, so these pass every input (equivalent/0x000d6b20, 0x001c52f0, 0x001fbd00 byte-match the original
    but for the constant's bits). Values compare as the loads read them (a float, or a double), so a double of
    the same value isn't a difference."""
    sizes = {}
    for i in oview.insns.values():
        if i.mem is not None and i.mnemonic.startswith("f") and not i.mem[1] and not i.mem[2] and i.mem[4] in o_left:
            sizes.setdefault(i.mem[4], set()).add(i.mem[5])
    orig = []
    for t in sorted(o_left):
        for sz in sorted(sizes.get(t) or (4,)):
            if sz in (4, 8):
                w = struct.unpack("<f" if sz == 4 else "<d", prog.read(t, sz))[0]
                if math.isfinite(w):
                    orig.append((t, sz, w))
    # (round 15, immfloat) immediates: the original's float bit patterns we don't store, and ours it doesn't. An
    # integer that only looks like a float compares here too; it is flagged only when the original has no such
    # immediate and has a float within FCONST_TOL of it with the same exponent (a few ulps: a mistyped literal)
    imm_o = sorted(set(o_imm) - set(r_imm))
    for v in imm_o:
        w = struct.unpack("<f", struct.pack("<I", v))[0]
        orig.append(("imm", 4, w))
    mine = []
    for k, t, n in refs:
        if t is not None or not n.startswith("__real@"):
            continue
        hx = n[len("__real@"):]
        if len(hx) not in (8, 16):
            continue
        mine.append((n, struct.unpack("<f" if len(hx) == 8 else "<d", bytes.fromhex(hx)[::-1])[0], None))
    for v in sorted(set(r_imm) - set(o_imm)):
        mine.append(("0x%08x" % v, struct.unpack("<f", struct.pack("<I", v))[0], v))
    out = []
    for n, v, bits in mine:
        if not math.isfinite(v) or any(w == v for _, _, w in orig) or any(x["symbol"] == n for x in out):
            continue
        near = [(abs(w - v) / max(abs(w), abs(v)), t_, sz, w) for t_, sz, w in orig if w and v]
        near = [x for x in near if x[0] <= FCONST_TOL]
        if bits is not None:           # ours an immediate: the same exponent as the original's float
            near = [x for x in near if x[2] == 4 and
                    (struct.unpack("<I", struct.pack("<f", x[3]))[0] >> 23) == (bits >> 23)]
        if near:
            _, t_, sz, w = min(near)
            out.append({"kind": "float_immediate_differs" if bits is not None or t_ == "imm" else
                        "float_constant_differs", "symbol": n, "ours": repr(v), "original": repr(w),
                        "target": t_ if t_ == "imm" else "0x%08x" % t_, "size": sz})
    return out


# ---------------------------------------------------------------------------------------------
# Level 3 driver.
def make_input(seed, sig, prog_globals, ptr_pool=(), int_pool=(), strides=(), min_words=0):
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
        elif k == "ptr" and seed % 8 == 5 and strides and i > 0 and "ptr" in words_kind:
            # an iterator range: a later pointer a few elements past the first one, in a step the code
            # advances by (`add esi, 0x44`): `[first, last)` over fuzzed pointers is millions of elements
            first = words[words_kind.index("ptr")]
            st_ = strides[(h >> 8) % len(strides)]
            words.append((first + st_ * ((h >> 12) % 9)) & M32)
            words_kind.append(k)
        elif k == "ptr" and seed % 4 == 1:
            words.append(HEAP + 0x20000 + 0x40 * i + 4 * (h % 8))     # nearby, ascending pointers
            words_kind.append(k)
        else:
            words.append(fuzz_value(h, k) if not (seed == 0 and k == "ptr") else HEAP + 0x1000 * (i + 1))
            words_kind.append(k)
    if "struct" in kinds and len(words) < min(min_words, 1024) and "bigstruct" not in EQUIV_OFF:
        # (round 7) a struct passed by value is more than the 4 words guessed: as many as the function's own
        # `ret N` pops or its code reads (a type char at +0x2b0 of a 0x2c0-byte argument)
        words += [fuzz_value(mix(seed, 0xA6, i)) for i in range(len(words), min(min_words, 1024))]
        words_kind += ["any"] * (len(words) - len(words_kind))
    regs = {}
    for j, r in enumerate(("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp")):
        regs[r] = HEAP + ((mix(seed, 0x4E6, j) % HEAP_SIZE) & ~0xF) if seed else HEAP + 0x10000 * (j + 1)

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


def _last_ret(calls, k, v):
    """The latest call before #k+1 that returned to v (its return address), or None."""
    for i in range(k - 1, -1, -1):
        if calls[i].get("ret_to") == v and not calls[i].get("tail"):
            return i
    return None


def compare_runs(o, r, ret_kind, machine, namer, prog, max_report=4, esp_adjust=0, skip_saved=(), void_eax=False):
    """List of human-readable behaviour differences (empty = same)."""
    out = []
    oc, rc = o["calls"], r["calls"]
    if r.get("cookie_bad") and not o.get("cookie_bad"):
        out.append("__security_check_cookie (before call #%d) doesn't get the cookie in ecx: it is __fastcall, "
                   "declare it `extern \"C\" void __fastcall __security_check_cookie(unsigned int)`" % r["cookie_bad"])
    if o["status"] != r["status"]:
        out.append("original %s but ours %s" % (o["status"], r["status"]))
    o_ret = {c_["ret_to"] for c_ in oc if c_.get("ret_to") and not c_.get("tail")}
    r_ret = {c_["ret_to"] for c_ in rc if c_.get("ret_to") and not c_.get("tail")}
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
            if ov != rv and "retaddr" not in EQUIV_OFF and ov in o_ret and rv in r_ret and \
                    _last_ret(oc, k, ov) == _last_ret(rc, k, rv) is not None:
                # (round 7) a stale word below the stack pointer that held the return address of the same
                # earlier call on each side (the padding of a struct passed by value): each image's own address
                j += 1
                continue
            w_ = min((a.get("argw") or [])[j:j + 1] + (b.get("argw") or [])[j:j + 1] + [32])
            if w_ < 32 and (ov ^ rv) & ((1 << w_) - 1) == 0:
                j += 1                  # only the low byte(s) were set on one side: the rest is garbage
                continue
            if _norm(ov) == _norm(rv):
                j += 1
                continue
            if of == 4 and rf == 4 and _feq(*struct.unpack("<ff", struct.pack("<II", ov, rv))):
                j += 1
                continue
            if (of == 4 or rf == 4) and _feq(*struct.unpack("<ff", struct.pack("<II", ov, rv))) \
                    and not any(HEAP <= x < HEAP + HEAP_SIZE or OURS <= x < OURS + OURS_SIZE for x in (ov, rv)) \
                    and "argbit" not in EQUIV_OFF:
                # a float argument stored by fstp on one side and copied as a word on the other (`push ecx` of a
                # float local): a float, compared with the float tolerance, as documented for float arguments
                # (the x87 rounds the other side's value once more, or keeps 80 bits a step longer)
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
        xa, xb = a.get("x87args") or [], b.get("x87args") or []
        for j in range(min(len(xa), len(xb))):
            if not _feq(xa[j], xb[j]):
                out.append("call #%d to %s: x87 argument st(%d) is %s, expected %s" % (
                    k + 1, _fmt(a["target"]), j, "empty" if xb[j] is None else "%.7g" % xb[j],
                    "empty" if xa[j] is None else "%.7g" % xa[j]))
                bad = True
                break
        if bad:
            break
        if b.get("overflow"):
            loc, need, room, what = b["overflow"][0]
            out.append("call #%d to %s writes 0x%x bytes through %s (the original's local has room for them), "
                       "but ours has only 0x%x bytes there before %s: make the local as big as the callee's object"
                       % (k + 1, _fmt(a["target"]), need,
                          "argument %d" % (loc + 1) if isinstance(loc, int) else loc, room, what))
            break
        # contents of locals passed by pointer, matched by argument position
        for j, ((ov, _), (rv, _)) in enumerate(zip(oa, ra)):
            if ov in a.get("pointees", {}) and rv in b.get("pointees", {}):
                d_ = _pointee_diff(a["pointees"][ov], b["pointees"][rv])
                if d_ is not None:
                    path, off, rwv, owv = d_
                    out.append("call #%d to %s: the local passed as argument %d differs at %s+0x%x (%s, expected %s)" % (
                        k + 1, _fmt(a["target"]), j + 1, path, off, _desc(rwv), _desc(owv)))
                    bad = True
                    break
        if bad:
            break
        # register inputs of the callee: this (ecx), fastcall/LTCG register arguments
        if a.get("conv"):
            continue              # a declared convention: registers were compared as arguments
        want = prog.reg_inputs(a["target"]) if a["target"] in prog.funcs and a.get("known") else None
        if want is None:
            want = {"ecx"} if a.get("via_object") and b.get("via_object") else set()
            if a.get("cdecl_site"):
                # (round 8, ccall) the original's caller released the call's pushed words right after it:
                # the target is cdecl, which doesn't take ecx (only the original's code is evidence here)
                want = set()
        bad_reg = None
        for reg in sorted(want):
            if _norm(a["regs"][reg]) != _norm(b["regs"][reg]):
                bad_reg = reg
                break
            ov, rv = a["regs"][reg], b["regs"][reg]
            if ov in a.get("pointees", {}) and rv in b.get("pointees", {}):
                d_ = _pointee_diff(a["pointees"][ov], b["pointees"][rv])
                if d_ is not None:
                    out.append("call #%d to %s: the local passed in %s differs at %s+0x%x" % (
                        k + 1, _fmt(a["target"]), reg, d_[0], d_[1]))
                    bad = True
                    break
        if bad:
            break
        if bad_reg:
            label = "this (ecx)" if bad_reg == "ecx" else bad_reg
            hint = ""
            if bad_reg != "ecx":
                hint = " (the callee reads %s on entry; if it takes register arguments, declare them: " \
                       "// equiv-conv: <callee> <locations, e.g. %s stack>)" % (
                           bad_reg, " ".join(sorted(want)))
            out.append("call #%d to %s: %s is %s, expected %s%s" % (
                k + 1, _fmt(a["target"]), label, _fmt(_norm(b["regs"][bad_reg])), _fmt(_norm(a["regs"][bad_reg])),
                hint))
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
                # (a float one side stores with fst and the other copies as a word: still a float)
                sz = ofpu.get(base) or rfpu.get(base)
                if sz and rfpu.get(base, sz) == sz and ofpu.get(base, sz) == sz and base <= a < base + sz:
                    fmt = "<f" if sz == 4 else "<d"
                    ob = bytes(os_.get(base + i, machine.byte(base + i, s)) for i in range(sz))
                    rb = bytes(rs.get(base + i, machine.byte(base + i, s)) for i in range(sz))
                    if _feq(struct.unpack(fmt, ob)[0], struct.unpack(fmt, rb)[0]):
                        ok = True
                        done.update(range(base, base + sz))
                    break
            if not ok:
                # a float rounded once more on one side (x87 precision, copied through a register): the same
                # normal float but for the last bit
                w0 = a & ~3
                ob4 = bytes(os_.get(w0 + i, machine.byte(w0 + i, s)) for i in range(4))
                rb4 = bytes(rs.get(w0 + i, machine.byte(w0 + i, s)) for i in range(4))
                ow4, rw4 = struct.unpack("<I", ob4)[0], struct.unpack("<I", rb4)[0]
                if abs(ow4 - rw4) == 1 and 0x0C800000 <= (ow4 & 0x7FFFFFFF) < 0x72000000 and \
                        (ow4 ^ rw4) >> 23 == 0 and not (HEAP <= ow4 < HEAP + HEAP_SIZE or OURS <= ow4 < OURS + OURS_SIZE):
                    done.update(range(w0, w0 + 4))
                    continue
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
    if o.get("noreturn") != r.get("noreturn") and o["status"] == r["status"] == "ret" and not out:
        out.append("the original %s in a call that never returns, ours %s" % (
            "ends" if o.get("noreturn") else "doesn't end", "does" if r.get("noreturn") else "returns"))
    if o["status"] == "ret" and r["status"] == "ret" and not (o.get("noreturn") or r.get("noreturn")):
        if o["esp"] + esp_adjust != r["esp"]:
            out.append("stack pointer after return differs by %d (callee pop count)" % (r["esp"] - o["esp"] - esp_adjust))
        for reg in CALLEE_SAVED:
            if reg in skip_saved:
                continue
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
            if o.get("eax_fnstsw") is not None:
                mask &= (1 << o["eax_fnstsw"]) - 1      # (status-word bytes of the original's eax: not compared)
            if rk != "void":
                ov, rv = _norm(o["eax"] & mask), _norm(r["eax"] & mask)
                if ov != rv:
                    out.append("returned %s, expected %s%s" % (_fmt(rv), _fmt(ov),
                                                              "" if rk else " (return type unknown)"))
                if rk == "i64" and o["edx"] != r["edx"]:
                    out.append("returned high word %s, expected %s" % (_fmt(r["edx"]), _fmt(o["edx"])))
            elif void_eax and o.get("eax_defined"):
                m_ = (1 << o["eax_defined"]) - 1
                ov, rv = _norm(o["eax"] & m_), _norm(r["eax"] & m_)
                if ov != rv:
                    out.append("left %s in eax, expected %s: ours is void, but the original returns a value there "
                               "and it is called through a vtable or pointer, so callers may use it (declare "
                               "the return type)" % (_fmt(rv), _fmt(ov)))
    if r.get("abi_mismatch") and (out or ("argcall" not in EQUIV_OFF and r["abi_mismatch"][3])):
        # Our declaration pops differently from the real callee. Two such declarations can cancel out (a
        # push folded around a call: byte-identical code does this, `v44(t)->setFont()` for `v44()->setFont(t)`):
        # the stack words then belong to the wrong call. (round 15, argcall) That is a difference of its own: the
        # words each call takes are its callee's `ret N`, whatever the bytes (natively, the other call gets them).
        # Not for a callee that leaves its words to the caller (a plain `ret`: `this` in ecx with caller-popped
        # arguments can't be declared in C++).
        k_, t_, dpop_, real_ = r["abi_mismatch"]
        if out:
            out.insert(0, "call #%d to %s: our declaration has the callee pop %d bytes of arguments, but it really pops "
                       "%d (%s), so our stack is off by %d after it. Declare its real convention, or use "
                       "// equiv-conv if MSVC can't express it" % (
                           k_ + 1, _fmt(t_), dpop_, real_, "a plain ret: the caller pops" if real_ == 0 else
                           "ret %d" % real_, dpop_ - real_))
        else:
            out.append("call #%d to %s: our declaration passes it %d bytes of stack arguments, but it takes %d (%s): "
                       "the other %d bytes belong to another call (chained calls `X(a)->M()` for `X()->M(a)` give the "
                       "same bytes). Declare the words on the call that takes them" % (
                           k_ + 1, _fmt(t_), dpop_, real_, "a plain ret: the caller pops" if real_ == 0 else
                           "ret %d" % real_, abs(dpop_ - real_)))
    return out[:max_report]


def _pointee_diff(o, r, path=""):
    """(path, offset, ours, expected) of the first difference between two pointee snapshots, or None.

    The original decides: as many bytes as it filled in (or the declared size), and only bytes it wrote;
    ours initialising more than the original isn't a difference. Locals that a compared word points to
    (another local of the same frame) are compared too."""
    (ob, ofp, ow, oe, onest), (rb, rfp, rw, re_, rnest) = o, r
    # a word that points into the stack on both sides is a pointer to a local: frames differ, so the value
    # does (what it points to is compared below)
    ob, rb = bytearray(ob), bytearray(rb)
    for i in range(0, min(oe, len(ob), len(rb)) - 3, 4):
        ow_ = struct.unpack_from("<I", ob, i)[0]
        if (STACK_LO <= ow_ < STACK_HI and STACK_LO <= struct.unpack_from("<I", rb, i)[0] < STACK_HI) \
                or ow_ == STACK_FILL:
            # (STACK_FILL: the original copied an uninitialised stack word; garbage on both sides)
            ob[i:i + 4] = rb[i:i + 4] = b"\0\0\0\0"
    ob, rb = bytes(ob), bytes(rb)
    # past the first ARRAY_WINDOW bytes (an array behind a scalar pointer), only bytes both sides wrote: a
    # neighbouring local in the original's frame may be somewhere else (or nothing) in ours
    written = {i for i in ow if i < ARRAY_WINDOW or i in rw}
    off = _first_diff(ob[:oe], rb[:oe], ofp, rfp, written)
    if off is not None:
        w = lambda b: struct.unpack_from("<I", b.ljust(off + 4, b"\0"), off & ~3)[0]
        return ("(in " + path.rstrip(", ") + ") ") if path else "", off, w(rb), w(ob)
    for noff, sub in sorted(onest.items()):
        if noff in rnest:
            d = _pointee_diff(sub, rnest[noff], path + "the local its +0x%x points to, " % noff)
            if d is not None:
                return d
    return None


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


_SELF_FLAGS = {"je": 1, "jz": 1, "jne": 0, "jnz": 0, "jb": 0, "jc": 0, "jnae": 0, "jae": 1, "jnb": 1, "jnc": 1,
               "jbe": 1, "jna": 1, "ja": 0, "jnbe": 0, "jl": 0, "jnge": 0, "jge": 1, "jnl": 1, "jle": 1, "jng": 1,
               "jg": 0, "jnle": 0, "js": 0, "jns": 1, "jp": 1, "jpe": 1, "jnp": 0, "jpo": 0, "jo": 0, "jno": 1}


def infeasible_edges(view):
    """Branch sides that can't be taken: a jcc right after `cmp r, r` / `sub r, r` / `xor r, r` (a compiler
    artefact, `cmp eax, eax; je` after a loop), when nothing else jumps to the jcc. The flags are fixed (ZF=1,
    CF=SF=OF=0), so one side is dead; it isn't counted as uncovered."""
    cache = view.__dict__.get("_infeasible")
    if cache is not None:
        return cache
    out = set()
    if "selfcmp" not in EQUIV_OFF:
        prev = {a + i.size: a for a, i in view.insns.items()}
        targets = {i.target for i in view.insns.values() if i.target is not None} | \
            {t for tg in view.tables.values() for t in tg}
        for j in view.jcc:
            i = view.insns[j]
            p = view.insns.get(prev.get(j))
            if p is None or j in targets or i.mnemonic not in _SELF_FLAGS:
                continue
            if p.mnemonic in ("cmp", "sub", "xor") and len(p.ops) == 2 and p.ops[0][0] == "reg" and p.ops[0] == p.ops[1]:
                taken = _SELF_FLAGS[i.mnemonic]
                out.add((j, j + i.size) if taken else (j, i.target))
    if "leanull" not in EQUIV_OFF:
        out |= _lea_null_edges(view)
    if "leaflow" not in EQUIV_OFF:
        out |= _lea_null_flow(view)
    if "wrapcmp" not in EQUIV_OFF:
        out |= _wrap_edges(view)
    if "constflags" not in EQUIV_OFF:
        out |= _const_flag_edges(view)
    out |= getattr(view, "declared_dead", set())
    if out and "unreach" not in EQUIV_OFF:
        # (round 7) code reachable only through a dead side is dead too: all its branch sides, setcc
        # outcomes and switch cases
        seen, work = set(), [view.entry]
        while work:
            a = work.pop()
            while a in view.insns and a not in seen:
                seen.add(a)
                i = view.insns[a]
                nxt = a + i.size
                if i.kind in ("ret", "stop"):
                    break
                if i.kind == "jcc":
                    if i.target in view.insns and (a, i.target) not in out:
                        work.append(i.target)
                    if (a, nxt) in out:
                        break
                elif i.kind == "jmp":
                    if i.target in view.insns:
                        work.append(i.target)
                    work.extend(t for t in view.tables.get(a, ()) if t in view.insns)
                    break
                a = nxt
        for j in view.jcc:
            if j not in seen:
                i = view.insns[j]
                out |= {(j, i.target), (j, j + i.size)}
        for j in view.setcc:
            if j not in seen:
                out |= {(j, "set0"), (j, "set1")}
        for j, tg in view.tables.items():
            if j not in seen:
                out |= {(j, t) for t in tg}
    view._infeasible = out
    return out


_FLAGS_KEPT = ("mov", "lea", "push", "movzx", "movsx", "nop", "fld", "fst", "fstp", "fild", "fxch")


def _lea_null_edges(view):
    """(round 7) `lea ecx, [esi + 4]; ...; test ecx, ecx; je L`: the null check of `&this->member` (a source
    `if (&tag)`, or a base-class conversion). Zero only when esi is -4, never a pointer (esi is used as a
    memory base in the function). The zero side is dead, as directed inputs already never plant an address
    that wraps around. Straight-line code only: nothing else jumps between the lea and the jcc."""
    out = set()
    prev = {a + i.size: a for a, i in view.insns.items()}
    targets = {i.target for i in view.insns.values() if i.target is not None} | \
        {t for tg in view.tables.values() for t in tg}
    bases = {i.mem[1] for i in view.insns.values() if i.mem is not None and i.mnemonic != "lea" and i.mem[1]}
    for j in view.jcc:
        i = view.insns[j]
        if i.mnemonic not in ("je", "jz", "jne", "jnz") or j in targets:
            continue
        a, reg, ok = prev.get(j), None, False
        for _ in range(12):
            p = view.insns.get(a)
            if p is None or p.kind != "other":
                break
            if reg is None:
                if p.mnemonic in _FLAGS_KEPT:
                    if a in targets:
                        break
                    a = prev.get(a)
                    continue
                if p.mnemonic in ("test", "or") and len(p.ops) == 2 and p.ops[0] == p.ops[1] and p.ops[0][0] == "reg" \
                        and p.ops[0][1] in ("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp"):
                    reg = p.ops[0][1]
                    if a in targets:
                        break
                    a = prev.get(a)
                    continue
                break
            if p.mnemonic == "lea" and p.ops and p.ops[0] == ("reg", reg) and p.mem is not None:
                _, b, ix, _, disp, _ = p.mem
                ok = b is not None and ix is None and 0 < disp < 0x10000 and b != reg and (b in bases or b == "esp")
                break
            if p.ops and p.ops[0] == ("reg", reg) or p.mnemonic in ("xchg", "cmpxchg", "xadd") or \
                    p.mnemonic.startswith(("rep", "stos", "lods", "movs", "cmps", "scas", "div", "idiv", "mul", "cdq")):
                break
            if a in targets:
                break
            a = prev.get(a)
        if ok:
            out.add((j, i.target) if i.mnemonic in ("je", "jz") else (j, j + i.size))
    return out


def _lea_null_flow(view):
    """(round 9, leaflow) The `&this->member` null check of _lea_null_edges across calls and branches: `lea edi,
    [esi + 0x1f58]; call f; ...; jne L; ...; test edi, edi; je` (FaceTargetAction: `Sub *sub = &p->sub; ...;
    if (sub != 0 && ...)`). A forward data flow keeps, per register, the lea that last set it on every path
    (copies follow it). A call ends it for eax/ecx/edx only: the original keeping the value in ebx/esi/edi/ebp
    across a call is its compiler relying on the callee preserving it."""
    regs = ("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp")
    prev = {a + i.size: a for a, i in view.insns.items()}
    targets = {i.target for i in view.insns.values() if i.target is not None} | \
        {t for tg in view.tables.values() for t in tg}
    bases = {i.mem[1] for i in view.insns.values() if i.mem is not None and i.mnemonic != "lea" and i.mem[1]}
    state = {view.entry: {}}
    work = [view.entry]
    steps = 0

    def transfer(a, i, st):
        if i.kind == "call":
            return {r: v for r, v in st.items() if r not in ("eax", "ecx", "edx")}
        w = view.write_widths(a)
        if not w:
            return st
        st = dict(st)
        if i.mnemonic == "lea" and len(i.ops) == 2 and i.ops[0][0] == "reg" and i.ops[0][1] in regs and i.mem is not None:
            _, b, ix, _, disp, _ = i.mem
            for r in w:
                st.pop(r, None)
            if b is not None and ix is None and 0 < disp < 0x10000 and b != i.ops[0][1] and (b in bases or b == "esp"):
                st[i.ops[0][1]] = a
            return st
        if i.mnemonic == "mov" and len(i.ops) == 2 and i.ops[0][0] == "reg" and i.ops[1][0] == "reg" and \
                i.ops[0][1] in regs and i.ops[1][1] in regs:
            v = st.get(i.ops[1][1])
            for r in w:
                st.pop(r, None)
            if v is not None:
                st[i.ops[0][1]] = v
            return st
        for r in w:
            st.pop(r, None)
        return st

    while work and steps < 200000:
        steps += 1
        a = work.pop()
        i = view.insns.get(a)
        if i is None:
            continue
        out_st = transfer(a, i, state[a])
        if i.kind in ("ret", "stop"):
            succ = []
        elif i.kind == "jcc":
            succ = [i.target, a + i.size]
        elif i.kind == "jmp":
            succ = ([i.target] if i.target is not None else []) + list(view.tables.get(a, ()))
        else:
            succ = [a + i.size]
        for b in succ:
            if b not in view.insns:
                continue
            old = state.get(b)
            new = out_st if old is None else {r: v for r, v in old.items() if out_st.get(r) == v}
            if old is None or new != old:
                state[b] = new
                work.append(b)
    if work:
        return set()
    out = set()
    for j in view.jcc:
        i = view.insns[j]
        if i.mnemonic not in ("je", "jz", "jne", "jnz") or j in targets:
            continue
        a = prev.get(j)
        for _ in range(8):
            p = view.insns.get(a)
            if p is None or p.kind != "other":
                break
            if p.mnemonic in _FLAGS_KEPT:
                if a in targets:
                    break
                a = prev.get(a)
                continue
            if p.mnemonic in ("test", "or") and len(p.ops) == 2 and p.ops[0] == p.ops[1] and p.ops[0][0] == "reg" \
                    and p.ops[0][1] in regs and p.ops[0][1] in state.get(a, {}):
                out.add((j, i.target) if i.mnemonic in ("je", "jz") else (j, j + i.size))
            break
    return out


# (round 8) unsigned jcc -> (dead side when the compare's first operand is the lea's base, when it is the lea's
# result): True = taken, False = not taken
_WRAP_DEAD = {"jae": (True, False), "jnb": (True, False), "jnc": (True, False), "ja": (True, False),
              "jnbe": (True, False), "jb": (False, True), "jnae": (False, True), "jc": (False, True),
              "jbe": (False, True), "jna": (False, True)}


def _wrap_edges(view):
    """(round 8) `lea ecx, [ebp + 3]; cmp ebp, ecx; jae L` (`hi = p + 3; while (lo < hi)`, reverse4): ebp >= ecx
    only when p + 3 wraps past 2^32, which no object allows (computing p + 3 is undefined unless it stays
    inside p's object). That side is dead when one of the two registers is used as a memory base in the
    function (a pointer, not an integer overflow check). Straight-line code only, neither register rewritten
    between the lea and the cmp, nothing jumps in between."""
    out = set()
    prev = {a + i.size: a for a, i in view.insns.items()}
    targets = {i.target for i in view.insns.values() if i.target is not None} | \
        {t for tg in view.tables.values() for t in tg}
    bases = {i.mem[1] for i in view.insns.values() if i.mem is not None and i.mnemonic != "lea" and i.mem[1]}
    for j in view.jcc:
        i = view.insns[j]
        if i.mnemonic not in _WRAP_DEAD or j in targets:
            continue
        a, cmp_ = prev.get(j), None
        for _ in range(8):
            p = view.insns.get(a)
            if p is None or p.kind != "other":
                break
            if p.mnemonic == "cmp":
                cmp_ = p
                break
            if p.mnemonic not in _FLAGS_KEPT or a in targets:
                break
            a = prev.get(a)
        if cmp_ is None or len(cmp_.ops) != 2 or cmp_.ops[0][0] != "reg" or cmp_.ops[1][0] != "reg" or a in targets:
            continue
        ra, rb = cmp_.ops[0][1], cmp_.ops[1][1]
        if ra == rb or ra not in Program._REGS or rb not in Program._REGS:
            continue
        a = prev.get(a)
        for _ in range(12):
            p = view.insns.get(a)
            if p is None or p.kind != "other":
                break
            if p.mnemonic == "lea" and p.ops and p.ops[0][0] == "reg" and p.ops[0][1] in (ra, rb) and p.mem is not None:
                _, b, ix, _, disp, _ = p.mem
                res = p.ops[0][1]
                other = rb if res == ra else ra
                if b == other and ix is None and 0 < disp < 0x10000 and (ra in bases or rb in bases):
                    first_is_base = (ra == other)
                    dead_taken = _WRAP_DEAD[i.mnemonic][0 if first_is_base else 1]
                    out.add((j, i.target) if dead_taken else (j, j + i.size))
                break
            if p.ops and p.ops[0][0] == "reg" and p.ops[0][1] in (ra, rb) or a in targets or \
                    p.mnemonic in ("xchg", "cmpxchg", "xadd", "pop") or \
                    p.mnemonic.startswith(("rep", "stos", "lods", "movs", "cmps", "scas", "div", "idiv", "mul", "cdq")):
                break
            a = prev.get(a)
    return out


def _jcc_taken(mn, zf, cf, sf, of, pf):
    return {"je": zf, "jz": zf, "jne": not zf, "jnz": not zf, "jb": cf, "jc": cf, "jnae": cf, "jae": not cf,
            "jnb": not cf, "jnc": not cf, "jbe": cf or zf, "jna": cf or zf, "ja": not (cf or zf),
            "jnbe": not (cf or zf), "jl": sf != of, "jnge": sf != of, "jge": sf == of, "jnl": sf == of,
            "jle": zf or sf != of, "jng": zf or sf != of, "jg": not zf and sf == of, "jnle": not zf and sf == of,
            "js": sf, "jns": not sf, "jo": of, "jno": not of, "jp": pf, "jpe": pf, "jnp": not pf,
            "jpo": not pf}.get(mn)


def _const_flag_edges(view):
    """(round 8) A jcc whose flags come from `test r, r` / `cmp r, imm` / `cmp r, r2` on registers that hold
    the same constant on every path reaching it (`xor eax, eax` before a loop whose `test eax, eax; jne`
    re-reads it): one side is dead. A forward constant propagation over the function's registers (writes
    other than `xor r, r`, `sub r, r`, `mov r, imm`, `mov r, r2` make a register unknown, and so does every
    call), skipping edges it has shown dead; `test r, r; je L` makes r 0 at L."""
    regs = ("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp")
    prev = {a + i.size: a for a, i in view.insns.items()}
    targets = {i.target for i in view.insns.values() if i.target is not None} | \
        {t for tg in view.tables.values() for t in tg}
    state = {view.entry: {}}
    work = [view.entry]
    dead = set()
    steps = 0

    def transfer(a, i, st):
        st = dict(st)
        if i.kind == "call":
            return {}           # (a callee may not keep the convention's saved registers: nothing survives)
        w = view.write_widths(a)
        if i.mnemonic in ("xor", "sub") and len(i.ops) == 2 and i.ops[0] == i.ops[1] and i.ops[0][0] == "reg" \
                and i.ops[0][1] in regs:
            for r in w:
                st.pop(r, None)
            st[i.ops[0][1]] = 0
            return st
        if i.mnemonic == "mov" and len(i.ops) == 2 and i.ops[0][0] == "reg" and i.ops[0][1] in regs:
            src = i.ops[1]
            for r in w:
                st.pop(r, None)
            if src[0] == "imm":
                st[i.ops[0][1]] = src[1] & M32
            elif src[0] == "reg" and src[1] in regs and src[1] in st:
                st[i.ops[0][1]] = st[src[1]]
            return st
        for r in w:
            st.pop(r, None)
        return st

    def flags_of(j):
        """(zf, cf, sf, of, pf) the jcc at j sees, or None."""
        if j in targets:
            return None
        a = prev.get(j)
        for _ in range(8):
            p = view.insns.get(a)
            if p is None or p.kind != "other" or a in targets and p.mnemonic in _FLAGS_KEPT:
                return None
            if p.mnemonic in _FLAGS_KEPT:
                a = prev.get(a)
                continue
            st = state.get(a)
            if st is None or len(p.ops) != 2 or p.ops[0][0] != "reg" or p.ops[0][1] not in st:
                return None
            x = st[p.ops[0][1]]
            if p.ops[1][0] == "imm":
                y = p.ops[1][1] & M32
            elif p.ops[1][0] == "reg" and p.ops[1][1] in st:
                y = st[p.ops[1][1]]
            else:
                return None
            if p.mnemonic in ("test", "and") or (p.mnemonic == "or" and p.ops[0] == p.ops[1]):
                v = (x & y) if p.mnemonic != "or" else x
                return v == 0, False, bool(v >> 31), False, bin(v & 0xFF).count("1") % 2 == 0
            if p.mnemonic == "cmp":
                v = (x - y) & M32
                sx, sy, sv = x >> 31, y >> 31, v >> 31
                return v == 0, x < y, bool(sv), sx != sy and sv != sx, bin(v & 0xFF).count("1") % 2 == 0
            return None
        return None

    while work and steps < 200000:
        steps += 1
        a = work.pop()
        i = view.insns.get(a)
        if i is None:
            continue
        out_st = transfer(a, i, state[a])
        succ = []
        if i.kind in ("ret", "stop"):
            pass
        elif i.kind == "jcc":
            f = flags_of(a)
            t = _jcc_taken(i.mnemonic, *f) if f is not None else None
            if t is None:
                succ = [i.target, a + i.size]
            else:
                succ = [i.target if t else a + i.size]
        elif i.kind == "jmp":
            succ = ([i.target] if i.target is not None else []) + list(view.tables.get(a, ()))
        else:
            succ = [a + i.size]
        zero_on = None          # (successor, register) known to be 0 along that edge: `test r, r; je b`
        if i.kind == "jcc" and i.mnemonic in ("je", "jz", "jne", "jnz"):
            p = view.insns.get(prev.get(a))
            if p is not None and a not in targets and len(p.ops) == 2 and p.ops[0][0] == "reg" and \
                    p.ops[0][1] in regs and (p.mnemonic in ("test", "or") and p.ops[0] == p.ops[1] or
                                             p.mnemonic == "cmp" and p.ops[1] == ("imm", 0)):
                zero_on = (i.target if i.mnemonic in ("je", "jz") else a + i.size, p.ops[0][1])
        for b in succ:
            if b not in view.insns:
                continue
            o_st = out_st
            if zero_on is not None and zero_on[0] == b:
                o_st = dict(out_st)
                o_st[zero_on[1]] = 0
            old = state.get(b)
            new = o_st if old is None else {r: v for r, v in old.items() if o_st.get(r) == v}
            if old is None or new != old:
                state[b] = new
                work.append(b)
    if work:
        return set()            # (too big to settle: claim nothing)
    for j in view.jcc:
        if j not in state:
            continue
        f = flags_of(j)
        t = _jcc_taken(view.insns[j].mnemonic, *f) if f is not None else None
        if t is not None:
            i = view.insns[j]
            dead.add((j, j + i.size) if t else (j, i.target))
    return dead


def _declared_dead(view, lines):
    """(round 7) Branch sides a source declares dead after hand review (`// equiv-dead: +0x52 taken, +0x61 not
    taken: why`), in the labels the coverage report uses. They are left out of the coverage count and
    listed in the report (coverage.declared_dead)."""
    out = set()
    for line in lines:
        for m in re.finditer(r"\+0x([0-9a-fA-F]+)\s+(not taken|taken|case\s*->\s*\+0x([0-9a-fA-F]+))", line):
            j = view.entry + int(m.group(1), 16)
            i = view.insns.get(j)
            if i is None:
                continue
            if m.group(2) == "taken" and i.kind == "jcc":
                out.add((j, i.target))
            elif m.group(2) == "not taken" and i.kind == "jcc":
                out.add((j, j + i.size))
            elif m.group(3) and j in view.tables:
                out.add((j, view.entry + int(m.group(3), 16)))
    return out


def table_cases_n(view, j):
    return (getattr(view, "table_bound", None) or {}).get(j) or len(view.tables[j])


def coverage_of(view, edges):
    total, covered, missing = 0, 0, []
    dead = infeasible_edges(view)
    # (round 8) an edge a rule calls dead that a run took anyway is a checker bug: it counts as a normal edge
    # and is reported (`dead_taken`); hand-declared ones stay out of the count
    taken_dead = {e for e in dead & set(edges) if e not in getattr(view, "declared_dead", set())}
    dead = dead - taken_dead
    for j in view.jcc:
        i = view.insns[j]
        for t, label in ((i.target, "taken"), (j + i.size, "not taken")):
            if (j, t) in dead:
                continue
            total += 1
            if (j, t) in edges:
                covered += 1
            else:
                missing.append("+0x%x %s" % (j - view.entry, label))
    for j in view.setcc:
        for v in (0, 1):
            if (j, "set%d" % v) in dead:
                continue
            total += 1
            if (j, "set%d" % v) in edges:
                covered += 1
            else:
                missing.append("+0x%x set%s %d" % (j - view.entry, view.insns[j].mnemonic[3:], v))
    for j, tg in view.tables.items():
        if "caseidx" not in EQUIV_OFF:
            # (round 15, caseidx) every index the bounds check lets through is a case: a source that maps one of them
            # to another target (or the default) differs only on that index (0x0028aea0: 21 indices, 12 targets)
            for k in range(table_cases_n(view, j)):
                if (j, tg[k]) in dead:
                    continue
                total += 1
                if (j, ("idx", k)) in edges:
                    covered += 1
                else:
                    missing.append("+0x%x case %d ->+0x%x" % (j - view.entry, k, tg[k] - view.entry))
            continue
        for t in sorted(set(tg)):
            if (j, t) in dead:
                continue
            total += 1
            if (j, t) in edges:
                covered += 1
            else:
                missing.append("+0x%x case ->+0x%x" % (j - view.entry, t - view.entry))
    out = {"edges_total": total, "edges_covered": covered, "uncovered": missing[:20], "complete": covered == total}
    if taken_dead:
        out["dead_taken"] = sorted("+0x%x -> %s" % (j - view.entry, t if isinstance(t, str) else "+0x%x" % (t - view.entry))
                                   for j, t in taken_dead)
    if getattr(view, "declared_dead", None):
        out["declared_dead"] = sorted("+0x%x %s" % (j - view.entry, "taken" if t == view.insns[j].target else
                                                     "not taken" if j in view.insns and view.insns[j].kind == "jcc"
                                                     else "case ->+0x%x" % (t - view.entry))
                                      for j, t in view.declared_dead)
    return out


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
    by_name = {f[0]: f for f in funcs}

    def flat(f, depth=0):
        """The function's bytes, followed by those of a function of our object it tail-jumps to at its end
        (`~Derived` ending in `jmp ~Base`: the original inlined ~Base, and ~Base alone can look closer to it
        than ~Derived does)."""
        secnum, value, end = obj.func_extent(f)
        sec = obj.sections[secnum - 1]
        raw = sec["raw"] or b""
        body = strip_padding(raw[value:end])
        if depth < 2 and len(body) >= 5 and body[-5] == 0xE9 and "flat" not in EQUIV_OFF:
            for va, si, typ in sec["relocs"]:
                sym = obj.syms.get(si)
                if va == value + len(body) - 4 and sym is not None and sym[0] in by_name and sym[0] != f[0]:
                    return body[:-5] + flat(by_name[sym[0]], depth + 1)
        return body
    best = None
    for s in funcs:
        d = asm_diff(target_bytes, flat(s), set())
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
           max_steps=50000, use_names=True, clang=False, obj_path=None, keep_runs=False, time_budget=120,
           conventions=None, level3_fn=None, seeds=None):
    """Run levels 1-3 for SRC against the original function at ADDR. Returns the report dict.

    seeds: run only these random seeds (a regression case for one input out of thousands); EQUIV_SEEDS=1,2 too.
    level3_fn: run this instead of the fuzzing level 3 (tools/equiv_replay.py replays recorded game states);
    it gets the same setup as level3() as keyword arguments and its result is returned as rep["replay"]."""
    t0 = time.time()
    if not seeds and ONLY_SEEDS:
        seeds = sorted(ONLY_SEEDS)      # (round 8) EQUIV_SEEDS=5102 runs seed 5102 whatever --inputs says
    if seeds:
        n_inputs = max(n_inputs, max(seeds) + 1)
    max_inputs = max(max_inputs, n_inputs)      # (--inputs 3000 asks for at least that many)
    prog = Program.get()
    size, tname = prog.funcs[addr]
    rep = {"addr": "0x%08x" % addr, "src": src, "target": tname, "level": 0, "status": "fail"}
    explicit = dict(mapping or {})
    conv_lines = list(conventions or [])
    dead_lines = []             # `// equiv-dead: +0x52 taken, +0x61 not taken: why` (hand-reviewed)
    if src and os.path.exists(src):
        for line in open(src, errors="replace"):
            m = re.match(r"\s*//\s*equiv-map:\s*(\S+)\s*=\s*(0x[0-9a-fA-F]+)", line)
            if m:
                explicit.setdefault(m.group(1), int(m.group(2), 16))
            m = re.match(r"\s*//\s*equiv-conv:\s*(\S+)\s+(.+?)\s*$", line)
            if m:
                conv_lines.append((m.group(1), m.group(2).split()))
            m = re.match(r"\s*//\s*equiv-dead:\s*(.+?)\s*$", line)
            if m and "declared" not in EQUIV_OFF:
                dead_lines.append(m.group(1))
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
    # (round 7: a function wrapped in `namespace fn_<addr>` in a merged tree object has other mangled names
    # than its source's equiv-map / equiv-conv lines say)
    ren = _tree_names(obj, list(explicit) + [n for n, _ in conv_lines])
    explicit.update({ren[n]: a_ for n, a_ in list(explicit.items()) if n in ren})
    conv_lines = [(ren.get(n, n), l_) for n, l_ in conv_lines]
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
    # Functions our source names (FUN_00269b10, ...) are functions even where functions.csv has no entry
    # for them: a jmp there from the original is a tail call, not a chunk of the function.
    oview = CodeView(prog.read, addr, (addr, addr + size), prog)
    for s_ in obj.syms.values():
        if s_[2] <= 0 and use_names:
            na = name_address(prog, s_[0])
            if na and prog.text[0] <= na[0] < prog.text[1] and not (addr <= na[0] < addr + size):
                oview.extra_starts.add(na[0])
    for n_, a_ in explicit.items():
        if prog.text[0] <= a_ < prog.text[1] and not (addr <= a_ < addr + size):
            oview.extra_starts.add(a_)
    oview.build()
    oview.declared_dead = _declared_dead(oview, dead_lines)
    orefs = original_refs(prog, oview, size)
    # first link with locals only, so that alignment can read our code
    ours.link({})
    resolved, how, conflicts, exact = resolve_symbols(prog, ours, oview, orefs, explicit, use_names)
    ours.orig_addr = addr
    ours.link(resolved)
    rview = CodeView(ours.read, ours.func_addr, (ours.func_addr, ours.func_addr + ours.func_len), prog,
                     is_ours=True).build()
    ours_bytes = ours.bytes_at(addr, resolved)
    rep["byte_identical"] = ours_bytes == target or ours_bytes == strip_padding(target)
    # ---- level 2
    ours.orig_addr = addr
    issues = level2(prog, orefs, oview, ours, resolved, how, rview)
    if "initbytes" not in EQUIV_OFF:
        # (round 15) a global our source defines that binds to an original address: level 3 reads the original's
        # bytes there, so its initializer is never compared; the native build starts with ours
        from verify_relocs import initializer_diffs
        issues += initializer_diffs(obj.data, resolved, prog.read)
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
    # Reached only through a vtable or a function pointer, nobody can tell whether the callers use eax: when
    # we say void but the original leaves a meaningful value in eax, compare it anyway.
    void_eax = ret_kind == "void" and (addr in prog.virtual_funcs or nsites == 0)
    rep["signature"] = sig
    callees = {sym[0] for off, sym, typ, _ in ours.relocs if sym is not None and typ == REL32 and sym[0] in resolved}
    psizes = {}
    for n, d in pointee_sizes(src, flags, sorted(callees)).items():
        psizes[resolved[n]] = d
    # our declarations of the functions we call (they decide our side's stack effects)
    decls = {}
    for off, sym, typ, _ in ours.relocs + ours.local_relocs():
        if sym is not None and typ == REL32 and sym[0] in resolved:
            decls.setdefault(resolved[sym[0]], parse_signature(sym[0]))
    convs, bad = resolve_conventions(prog, conv_lines, ours, resolved, addr, fsym)
    if convs:
        rep["conventions"] = {"0x%08x" % a: " ".join(v) for a, v in convs.items()}
    if bad:
        rep["level2"]["issues"] = rep["level2"]["issues"] + bad
        rep["level2"]["ok"] = False
        if rep["level"] == 2:
            rep["level"] = 1
        issues = issues + bad
    if level3_fn is not None:
        rep["replay"] = level3_fn(prog=prog, oview=oview, rview=rview, ours=ours, orefs=orefs, sig=sig,
                                  ret_kind=ret_kind, psizes=psizes, convs=convs, decls=decls, void_eax=void_eax,
                                  issues=issues)
        rep["time"] = round(time.time() - t0, 2)
        return rep
    # (round 9, ourglobal) the original's image words our code also reads (bound data symbols): a directed input
    # plants a fixed-address word only there (a float constant the original keeps in .data, `fld [0x49fbc4]`,
    # is a literal in ours: planting it changed the original alone)
    prog.ours_data = {t for k_, t, _ in our_refs(ours, resolved, rview)[0] if k_ == "data" and t is not None}
    l3 = level3(prog, oview, rview, ours, orefs, sig, ret_kind, n_inputs, max_inputs, max_steps, keep_runs,
                time_budget, psizes=psizes, convs=convs, decls=decls, void_eax=void_eax, seeds=seeds)
    rep["level3"] = l3
    if l3["ok"] and rep["level"] == 2:
        rep["level"] = 3
    if l3.get("unsupported"):
        rep["status"] = "unsupported" if not issues else "fail"
    elif l3["ok"] and not issues:
        rep["status"] = "equivalent"
        cov = l3["coverage"]
        if not rep["byte_identical"] and (l3["inputs_run"] < MIN_CONCLUSIVE or (
                cov["edges_total"] >= 6 and cov["edges_covered"] < MIN_COVERAGE * cov["edges_total"])):
            # no difference, but too little ran to call it equivalent
            rep["status"] = "inconclusive"
            rep["inconclusive"] = "only %d inputs ran to completion, branch coverage %d/%d" % (
                l3["inputs_run"], cov["edges_covered"], cov["edges_total"])
    else:
        rep["status"] = "fail"
        # (round 9) which levels failed (`level` is the highest one passed)
        rep["failed_levels"] = ([2] if issues else []) + ([3] if l3.get("inputs_failed") or not issues else [])
    # `equivalent` only says no difference was seen with some coverage; promotion needs more (an added
    # field, so consumers parsing `status` keep working)
    cov = l3.get("coverage") or {}
    short = []
    if cov.get("edges_total") and cov["edges_covered"] < ACCEPT_COVERAGE * cov["edges_total"]:
        short.append("branch coverage %d/%d is under %d%%" % (cov["edges_covered"], cov["edges_total"],
                                                              100 * ACCEPT_COVERAGE))
    if l3.get("inputs_run", 0) < ACCEPT_INPUTS:
        short.append("only %d inputs completed (%d needed; try --inputs 3000%s)" % (
            l3.get("inputs_run", 0), ACCEPT_INPUTS,
            ", and a bigger --time-budget: the %gs budget ran out" % time_budget if l3.get("time_budget_hit") else ""))
    if rep["level2"].get("conflicts"):
        short.append("level-2 name conflicts")
    st = l3.get("statuses") or {}
    wild = st.get("wild", 0) + st.get("both_fault", 0)
    if wild > 0.1 * max(l3.get("inputs_run", 0), 1):
        # inputs set aside because control flow went wild: a few are fuzzing accidents, many mean the
        # model of some call is off (a stack that drifts until the final ret), which hides that code
        short.append("%d inputs went wild (control left the function) or crashed on both sides" % wild)
    rep["promotable"] = rep["status"] == "equivalent" and not short
    if rep["status"] == "equivalent" and short:
        rep["promotable_note"] = "; ".join(short)
    rep["time"] = round(time.time() - t0, 2)
    return rep


def resolve_conventions(prog, lines, ours, resolved, addr, fsym):
    """'// equiv-conv: NAME loc...' -> ({original address: [locations]}, [level-2 issues])."""
    out, bad = {}, []
    for name, locs in lines:
        if not locs or any(l not in CONV_LOCS for l in locs):
            bad.append({"kind": "bad_convention", "symbol": name, "locations": " ".join(locs)})
            continue
        a = None
        if re.fullmatch(r"(0x)?[0-9a-fA-F]{6,8}", name):
            a = int(name, 16)
        else:
            for sym in ours.obj.syms.values():
                if sym[0] == name or _qualified(sym[0]) == name or (_qualified(sym[0]) or "").split("::")[-1] == name:
                    if sym == fsym:
                        a = addr
                    elif sym[0] in resolved:
                        a = resolved[sym[0]]
                    if a is not None:
                        break
            if a is None:
                na = name_address(prog, name)
                a = na[0] if na else None
        if a is None:
            bad.append({"kind": "unresolved_convention", "symbol": name})
            continue
        out[a] = locs
    return out, bad


def _conv_input(inp, ours_layout, conv):
    """The original's copy of an input when our function receives its arguments per `conv`."""
    vals, si = [], 0
    for loc in ours_layout:
        if loc == "stack":
            vals.append(inp["stack"][si])
            si += 1
        else:
            vals.append(inp["regs"][loc])
    regs = dict(inp["regs"])
    stack = []
    for li, loc in enumerate(conv):
        v = vals[li] if li < len(vals) else fuzz_value(mix(inp["seed"], 0xC0, li))
        if loc == "stack":
            stack.append(v)
        else:
            regs[loc] = v
    pad = inp["stack"][si:]
    return dict(inp, regs=regs, stack=stack + pad, own_args=list(stack), own_pop=None)


def caller_cleaned(prog, oview):
    """Callees with a plain ret whose call sites in the original clean up the arguments themselves."""
    caller_cleans = set()
    sites = defaultdict(list)
    for a_, i_ in oview.insns.items():
        if i_.kind == "call" and i_.target is not None:
            sites[i_.target].append(a_)
    for t_, ss in sites.items():
        if prog.callee_pop(t_) == 0 and any(oview.cleanup_after(x) for x in ss):
            caller_cleans.add(t_)
    return caller_cleans


def level3(prog, oview, rview, ours, orefs, sig, ret_kind, n_inputs, max_inputs, max_steps, keep_runs=False,
           time_budget=120, directed=96, psizes=None, convs=None, decls=None, void_eax=False, seeds=None):
    only_seeds = set(seeds) if seeds else ONLY_SEEDS
    globals_ = sorted({t for _, k, t in orefs if k in ("data", "imm") and prog.section_name(t) in (".data", "BINKDATA", "DOLBY")})
    own_float = ret_kind in ("f32", "f64")
    varargs = {a for a, d in (decls or {}).items() if d and d.get("varargs")}
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
    target_conv = (convs or {}).get(oview.entry)
    # Our side pops per our declaration where the original shows a convention C++ can't spell: a callee
    # with a plain ret whose original callers clean up (e.g. `this` in ecx plus caller-popped stack args,
    # declared by us as a thiscall member), and callees with an equiv-conv annotation. Elsewhere both sides
    # use the callee's real `ret N`.
    caller_cleans = caller_cleaned(prog, oview)
    own_layout = decl_layout(sig)[0] or [] if target_conv else []
    esp_adjust = 0
    if target_conv:           # each side pops its own arguments: compare against each side's expectation
        esp_adjust = (decl_layout(sig)[1] or 0) - (prog.callee_pop(oview.entry) or 0)
    # pointer offsets for planted object graphs: this+4/8/12 and the small offsets the original adds to a
    # pointer (`lea edx, [eax + 0x1c]`: a list head inside the object)
    ptr_offsets = {0, 4, 8, 12} | set(sorted({i.mem[4] for i in oview.insns.values() if i.mnemonic == "lea"
                                              and i.mem and i.mem[1] not in (None, "esp", "ebp")
                                              and not i.mem[2] and 0 < i.mem[4] <= 0x200})[:12])
    # element sizes the code steps pointers by (`add esi, 0x44`, `lea edx, [edx + 0xc]`): iterator ranges
    strides = sorted({i.imms[0] for i in oview.insns.values() if i.mnemonic in ("add", "sub") and len(i.ops) == 2
                      and i.ops[0][0] == "reg" and i.ops[0][1] not in ("esp", "ebp") and i.ops[1][0] == "imm"
                      and 4 <= i.imms[0] <= 0x400 and i.imms[0] % 4 == 0})[:8] if "stride" not in EQUIV_OFF else ()
    hits = Counter()           # edge -> number of inputs that took it
    own_words = max((prog.callee_pop(oview.entry) or 0) // 4, prog.callee_stack_args(oview.entry) or 0)
    # chars byte compares test against (`cmp al, 0x2e`, `cmp byte [ecx], 0x2d`), and the next one up (inside
    # a `cmp al, 0x30; jl` .. `cmp al, 0x39; jg` range)
    alpha_words = []
    # keywords spelled by byte compares at consecutive offsets of one pointer (`cmp byte [esi], 'c'; jne;
    # cmp byte [esi + 1], 'l'; ...`)
    grp, gbase, glast = {}, None, None
    for a_ in sorted(oview.insns) + [None]:
        i = oview.insns.get(a_) if a_ is not None else None
        hit = i is not None and i.mnemonic == "cmp" and i.imms and i.ops and i.ops[0][0] == "mem" and \
            i.ops[0][1][5] == 1 and i.ops[0][1][1] and not i.ops[0][1][2] and i.ops[0][1][1] != "esp"
        if hit and gbase == i.ops[0][1][1] and a_ - glast < 32:
            grp.setdefault(i.ops[0][1][4], i.imms[0] & 0xFF)
            glast = a_
            continue
        if not hit and a_ is not None and glast is not None and a_ - glast < 32 and \
                not (i.ops and i.ops[0] == ("reg", gbase)):
            continue
        if len(grp) >= 2:
            lo = min(grp)
            w_ = bytearray()
            while lo + len(w_) in grp:
                w_.append(grp[lo + len(w_)])
            if len(w_) >= 2 and bytes(w_) not in alpha_words and "alpha" not in EQUIV_OFF:
                alpha_words.append(bytes(w_))
        grp, gbase, glast = ({i.ops[0][1][4]: i.imms[0] & 0xFF}, i.ops[0][1][1], a_) if hit else ({}, None, None)
    alphabet = sorted({c for i in oview.insns.values() if i.mnemonic == "cmp" and i.imms and i.ops and
                       ((i.ops[0][0] == "reg" and i.ops[0][1] in ("al", "bl", "cl", "dl", "ah", "bh", "ch", "dh"))
                        or (i.ops[0][0] == "mem" and i.ops[0][1][5] == 1))
                       for c in (i.imms[0] & 0xFF, (i.imms[0] + 1) & 0xFF) if 0x20 <= c < 0x7f})[:24]
    slot_arity = {}
    ub_copy = UB_COPY.get(prog.funcs[oview.entry][1]) if oview.entry in prog.funcs and "overlap" not in EQUIV_OFF \
        and not target_conv else None
    observations = {}          # jcc addr -> [(seed, cmp observation, ...)] from the original's runs
    missing_now = [set()]      # (round 9) compares with a side still missing (as of the directed pass)
    str_queue = []             # [(seed, string-compare observation, overlay, patch)] to plant (directed)
    objptr_queue = []          # (round 13) [(seed, pc, base pointer source, disp, overlay, patch)] (objptr_phase)
    objptr_seen = Counter()    # pc -> times queued
    str_seen = Counter()       # (site, literal) -> times queued
    str_popped = Counter()     # (round 9) site -> plants run
    t_start = time.process_time()      # CPU time: a loaded machine doesn't change the result
    steps = [max_steps]
    timeout_calls = [0]        # most stub calls a timed-out run of the original made
    last_steps = [0]           # instructions the last original run executed
    last_sentinels = [()]      # what the last timed-out run's walk compared its links against
    sent_left = [512, 0, 0]    # sentinel retries: budget, tried, completed
    count_pcs = set()          # (round 9) loads that read a runaway loop's count
    count_diffs = {}           # (round 10) `sub end, begin` instructions among them -> the transforms after the sub
    index_fills = set()        # (round 10) (call, argument, offset) of stub fills the original indexed a frame array with
    count_walks = {}           # (round 10) compares of runaway walks -> the operand holding the sentinel ("zero": a null link)
    static_counts = [False]    # (round 14, staticcount) `sub end, begin; sar k` element counts in the code, once switched on
    static_diffs = {}          # (round 14, staticcount) ... and the sites found in it
    if "staticcount" not in EQUIV_OFF:
        # (round 14, staticcount) A pointer difference scaled to an element count (`mov eax, [e+4]; sub eax, [e]; sar
        # eax, 2`) is a loop bound read from the input: with fuzzed pointers it is millions of elements, and every
        # round of the loop calls a stub. The discovery run of the small-count rounds plants a small count there;
        # known from the code, it needn't wait for a runaway input to find the site. A fallback only (random_phase): when
        # the usual rounds get no input through (16 ran away, fewer than 16 completed). Where they work, starting
        # inputs with small counts at every such site changes which inputs reach the code (0x001b4d00's wrong
        # knockback sign went unseen in 2680 inputs)
        for a_, i_ in oview.insns.items():
            if i_.mnemonic != "sub" or len(i_.ops) != 2 or i_.ops[0][0] != "reg" or i_.ops[1][0] not in ("reg", "mem") \
                    or i_.ops[0][1] not in ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp") or i_.mem and i_.mem[5] != 4:
                continue
            r_, n_ = i_.ops[0][1], a_ + i_.size
            for _ in range(4):
                j_ = oview.insns.get(n_)
                if j_ is None or j_.kind != "other":
                    break
                if j_.mnemonic in ("sar", "shr") and len(j_.ops) == 2 and j_.ops[0] == ("reg", r_) and \
                        j_.ops[1][0] == "imm" and 1 <= j_.imms[0] <= 5:
                    static_diffs[a_] = ((j_.mnemonic, j_.imms[0]),)
                    break
                if j_.ops and j_.ops[0] == ("reg", r_) and j_.mnemonic not in ("cmp", "test"):
                    break
                n_ += j_.size
    walk_heads = {}            # (round 11) top tests of those walks -> the walk's compare
    unit_targets = set()       # (round 11, ftolunit) callees whose float result bounded a runaway loop through __ftol2
    small_left = [512, 0, 0, 0, 0.0]   # (round 9) small-count rounds: budget, tried, completed, (round 10) completed tiny, CPU seconds
    probed = [None]            # the step-budget probe: None (not run), or the budget it settled on (0: no help)
    early_rets = [0]           # (round 11, earlyret) random inputs whose original returned within EARLY_STEPS
    first_to = [None]          # (round 11) the first random input whose original ran out of steps
    const_to = [0, 0]          # (round 11, constloop) random inputs that ran out of steps: all, in a constant-bound loop
    walk_to = [0]              # (round 11, walknolong) random inputs that ran out of steps in a walk over fuzzed links
    walk_to_seen = {}
    wreads = {}                # (round 11, opwords) completed input -> (load pc, address, transforms, value) its compares read
    budget_seed = [None]       # (round 11) the input at which the step budget was decided
    long_seed = [None]         # (round 11) the input at which the long budget was given
    stuck = []                 # inputs whose original ran too long: (seed, overlay, patch, hot comparisons)
    last_status = [None]
    loop_limits = {}           # runaway loops seen so far: later runs stop there early
    repair_on = [False]        # (not before the step budget is settled: long-running code isn't a runaway)
    repair_left = [64]
    tried_repair = set()

    # loop structure: back edges (jcc or jmp to an address at or before itself) and the forward jccs that
    # leave such a loop (target past its back edge)
    back_edges = [(a, i.target) for a, i in oview.insns.items() if i.kind in ("jcc", "jmp") and
                  i.target is not None and i.target <= a and oview.internal_target(i.target)]
    loop_exits = set()

    def reenters(t, lo, b):
        """Does the code at t go straight back into the loop [lo, b] (a body block placed after the loop,
        `jb L ... L: mov eax, [eax]; jmp next`)?"""
        a = t
        for _ in range(16):
            i = oview.insns.get(a)
            if i is None or i.kind in ("ret", "stop", "jcc"):
                return False
            if i.kind == "jmp":
                return i.target is not None and lo <= i.target <= b
            a += i.size
        return False
    for j in oview.jcc:
        t = oview.insns[j].target
        if t is None:
            continue
        if t <= j:
            loop_exits.add(j)
        elif any(lo <= j < b < t and not reenters(t, lo, b) for b, lo in back_edges):
            loop_exits.add(j)

    def repair(entry):
        """Re-run an input whose original ran away in a loop with that loop's bound patched (it then ends
        after a round or two); a run that hangs in the next loop is repaired again, up to 4 loops deep."""
        queue = [entry + (0,)]
        while queue and repair_left[0] > 0 and res["inputs_failed"] < 3 and not out_of_time():
            seed0, ov0, sp0, hot, depth = queue.pop(0)
            for j, ob in hot:
                done = False
                nst = len(make_input(seed0, sig, globals_, min_words=own_words)["stack"])
                cands = _patches(ob, ov0, sp0, nst)[:4]
                if ob.get("next") is not None:
                    # a walk (`while (cur != nil) cur = cur->left`): also end it one step further down
                    cands += _patches(ob["next"], ov0, sp0, nst)[:2]
                for overlay, patch in cands:
                    key = (seed0, tuple(sorted(map(repr, overlay.items()))), tuple(sorted(map(repr, patch.items()))))
                    if key in tried_repair:
                        continue
                    tried_repair.add(key)
                    repair_left[0] -= 1
                    res["inputs_repaired"] = res.get("inputs_repaired", 0) + 1
                    n0 = len(stuck)
                    run_input(seed0, overlay, patch, label="%d+loop" % seed0)
                    if last_status[0] == "ret":
                        return True
                    if len(stuck) > n0 and depth < 4 and stuck[-1][3][0][0] != j:
                        queue.append(stuck[-1] + (depth + 1,))     # stuck in another loop now: go on from there
                        done = True
                        break
                    if repair_left[0] <= 0:
                        return False
                if done:
                    break
        return False

    def build(seed, overlay=None, stack_patch=None):
        inp = make_input(seed, sig, globals_, rdata_ptrs, consts if seed % 3 == 2 else (), strides, own_words)
        inp["arity_by_call"] = {}
        inp["ret_override"] = {}
        if stack_patch:
            for k, v in stack_patch.items():
                if isinstance(k, tuple) and k[0] == "ret":     # a stub's return value
                    inp["ret_override"][k[1]] = v
                    continue
                if isinstance(k, tuple) and k[0] == "fret":    # a stub's float result
                    inp.setdefault("fret_override", {})[k[1]] = v
                    continue
                if isinstance(k, tuple) and k[0] == "stubfloats":    # every stub float result and fill word
                    inp["stub_floats"] = v
                    continue
                if isinstance(k, tuple) and k[0] == "sentinel":      # walk sentinels planted in memory
                    continue
                if isinstance(k, tuple) and k[0] == "stubmode":      # (round 11) every stub's result
                    continue
                if isinstance(k, tuple) and k[0] == "sbyte":         # bytes of a stack argument word
                    _, wi, bo, bn = k
                    if target_conv or wi >= len(inp["stack"]):
                        continue
                    msk = ((1 << (8 * bn)) - 1) << (8 * bo)
                    inp["stack"][wi] = (inp["stack"][wi] & ~msk & M32) | ((v << (8 * bo)) & msk)
                    if wi < len(inp["own_args"]):
                        inp["own_args"][wi] = inp["stack"][wi]
                    continue
                if isinstance(k, tuple) and k[0] == "pfill":   # (round 9) a byte out-parameter the function had set
                    inp.setdefault("pfill_override", {})[k[1:]] = v
                    continue
                if isinstance(k, tuple) and k[0] == "fill":    # a word a stub filled through a pointer
                    inp.setdefault("fill_override", {})[k[1:]] = v
                    continue
                if isinstance(k, tuple) and k[0] == "entry":   # a register argument of our function
                    reg = k[1]
                    if target_conv and reg in target_conv:
                        li = target_conv.index(reg)
                        if li < len(own_layout):
                            l = own_layout[li]
                            if l == "stack":
                                si = own_layout[:li].count("stack")
                                inp["stack"][si] = v
                                if si < len(inp["own_args"]):
                                    inp["own_args"][si] = v
                            else:
                                inp["regs"][l] = v
                    else:
                        inp["regs"][reg] = v
                    continue
                loc = ("stack", k)
                if target_conv:                 # k indexes the original's stack: find our location
                    stack_pos = [i for i, l in enumerate(target_conv) if l == "stack"]
                    if k < len(stack_pos):
                        li = stack_pos[k]
                        if li < len(own_layout):
                            l = own_layout[li]
                            loc = ("stack", own_layout[:li].count("stack")) if l == "stack" else ("reg", l)
                    else:
                        loc = ("stack", k - len(stack_pos) + own_layout.count("stack"))
                if loc[0] == "reg":
                    inp["regs"][loc[1]] = v
                    continue
                inp["stack"][loc[1]] = v
                if loc[1] < len(inp["own_args"]):
                    inp["own_args"][loc[1]] = v
        dictionary = ()
        pointers = ()
        if seed % 3 == 2:
            dictionary = [inp["regs"]["ecx"], inp["regs"]["edx"]] + inp["own_args"] + consts
            roots = {v for v in [inp["regs"]["ecx"], inp["regs"]["edx"]] + inp["own_args"] if HEAP <= v < HEAP + HEAP_SIZE}
            pointers = sorted({r + d for r in roots for d in ptr_offsets})
        inp["dictionary"] = dictionary
        inp["stub_mode"] = ("normal", "normal", "normal", "zero", "one", "normal")[seed % 6]
        if stack_patch and ("stubmode",) in stack_patch:
            inp["stub_mode"] = stack_patch[("stubmode",)]
        mach = Machine(prog, seed, globals_, pristine=(seed == 0), dictionary=dictionary, pointers=pointers,
                       overlay=overlay, sentinels=(stack_patch or {}).get(("sentinel",), ()))
        # Callee write extents the original's run learns must reach our run too: create the dict
        # before _conv_input's shallow copy so both inputs share it.
        if index_fills and "idxfill" not in EQUIV_OFF:
            # (round 10, idxfill) a word a stub fills that the original used as an index into an array in its frame
            # is drawn small (0 or 1) from then on: a fuzzed -1 stores below the array, onto whatever each side's
            # frame layout keeps there (the original's spilled loop counter), which no frame layout makes
            # equivalent. An input choice, the same on both sides; a directed input's own fill wins
            fo_ = inp.setdefault("fill_override", {})
            for k_, j_, off_ in sorted(index_fills):
                if not any(x[:3] == (k_, j_, off_) for x in fo_):
                    fo_[(k_, j_, off_, 0, 4)] = mix(seed, k_, j_, off_, 0x1D8) % 2
        if unit_targets and seed % 4 != 3:
            # (round 11, ftolunit) the float results of those callees are drawn in [0, 1] (pow of a fraction), for
            # every call: each outer round's bound is then a fraction of its scale (`(int)(pow(...) * n)`), not
            # 1000 * n. An input choice, the same on both sides; a directed input's own result for a call wins
            inp["fret_unit"] = frozenset(unit_targets)
        inp.setdefault("wext_by_call", {})
        inp.setdefault("extra_by_call", {})
        inp.setdefault("tail_arity", {})
        inp_o = _conv_input(inp, own_layout, target_conv) if target_conv else inp
        return inp, inp_o, mach

    def run_input(seed, overlay=None, stack_patch=None, label=None):
        """Run one input on both sides; returns the set of new original edges (None if inconclusive)."""
        inp, inp_o, mach = build(seed, overlay, stack_patch)
        # (round 8, overlap) strncat(d, d + 12, n): overlapping copies are undefined behaviour, and the
        # original's word-at-a-time reads and a byte loop see each other's writes differently
        ub = "overlap_ub" if ub_copy is not None and len(inp_o["stack"]) >= 3 and \
            _copy_overlap(ub_copy[1], ub_copy[0], inp_o["stack"][:3], lambda a_: mach.byte(a_, 0)) else None
        # our image is mapped in both runs, so a wild pointer reads the same bytes either way
        orun = Run(prog, oview, mach, inp_o, ours_image=(OURS, ours.image), sig=sig, max_steps=steps[0],
                   own_float_ret=own_float, coverage=True, helpers=helpers)
        orun.pointee_sizes = psizes or {}
        orun.convs = convs or {}
        orun.orig_entry = oview.entry
        orun.slot_arity = slot_arity
        orun.loop_limits = loop_limits
        orun.varargs = varargs
        orun.wild_check = True
        o = orun.run(oview.entry)
        # only a run that returned proves anything about the edges it took (a fault both sides share, e.g.
        # a stub that can't model the call, leaves the code after it unverified)
        conclusive = o["status"] == "ret"
        new = (orun.edges - edges) if conclusive else set()
        if conclusive:                 # a run that never finished proves nothing about the edges it took
            edges.update(orun.edges)
            for e in orun.edges:
                hits[e] += 1
        if o["status"] == "ret":
            for pc_, src_, disp_ in orun.deref_obs:
                # (round 13, objptr) twice per access, from different inputs (chains of plants included)
                if objptr_seen[pc_] < 2 and len(objptr_queue) < 256:
                    objptr_seen[pc_] += 1
                    objptr_queue.append((seed, pc_, src_, disp_, overlay, stack_patch))
        for sob in orun.str_obs:
            sk = (sob["site"], sob["lit"])
            if str_seen[sk] < 2 and len(str_queue) < 512:
                str_seen[sk] += 1
                str_queue.append((seed, sob, overlay, stack_patch))
        for c_ in orun.byte_seq:
            if 0x20 <= c_ < 0x7f and c_ not in alphabet and len(alphabet) < 32:
                alphabet.append(c_)
        if len(orun.byte_seq) >= 3 and len(alpha_words) < 8:
            # runs of letters compared one after the other (`p[0] == 'c' && p[1] == 'l' ...`): a keyword
            for w_ in re.findall(rb"[A-Za-z0-9_]{3,}", bytes(c_ for c_ in orun.byte_seq if c_ < 0x80)):
                if w_ not in alpha_words and len(alpha_words) < 8:
                    alpha_words.append(w_)
        if o["status"] == "ret" and alphabet and "alpha" not in EQUIV_OFF:
            # (round 7) a byte loop that compares each char with constants (an atof-style parser: '-', '.',
            # '0'..'9'): plant short strings made of those chars where it read its first byte
            bufs = {}
            bsite = {}
            for site, (ea, ep) in orun.byte_bufs.items():      # one buffer per distinct region: its lowest byte
                if not any(abs(ea - b) < 64 for b in bufs) or any(ea < b and b - ea < 64 for b in bufs):
                    for b in [b for b in bufs if 0 < b - ea < 64]:
                        bufs.pop(b)
                    bufs[ea] = ep
                    bsite[ea] = site
            for ea, ep in sorted(bufs.items())[:2]:
                # (twice, and again whenever the alphabet or the keywords grew: a planted "cla" shows the 's')
                # (round 9, alphasite: per compare site that read the buffer, so a second char loop gets its
                # turn too, a binding's signature loop after its result loop)
                ak = ("alpha", len(alphabet), len(alpha_words)) + ((bsite[ea],) if "alphasite" not in EQUIV_OFF else ())
                if str_seen[ak] >= 2 or str_seen[("alpha",)] >= 16 or len(str_queue) >= 512 or _reserved(ea) or \
                        prog.is_code(ea) or ea < NULL_HI or (IMAGE_LO <= ea < IMAGE_HI and prog.section_name(ea) == ".rdata"):
                    continue
                str_seen[ak] += 1
                str_seen[("alpha",)] += 1
                import random
                rnd = random.Random(mix(seed, ea, 0xA1FA))
                for k_ in range(24):
                    # (runs of one char half the time: "1.2345" needs several digits in a row)
                    txt = []
                    for _ in range(rnd.randint(1, 12)):
                        if alpha_words and rnd.random() < 0.25:
                            txt.extend(rnd.choice(alpha_words))
                            continue
                        txt.append(txt[-1] if txt and rnd.random() < 0.4 and txt[-1] not in b".-+" else rnd.choice(alphabet))
                    txt = txt[:24]
                    # (round 9, alphaep: in that memory epoch and every later one: a loop that calls something
                    # per char, `lua_type(L, i)` before reading sig[i], reads each char in a new epoch)
                    str_queue.append((seed, {"site": ("alpha", ea, k_), "lit": bytes(txt) + b"\0", "buf": ea,
                                             "epoch": ep if "alphaep" in EQUIV_OFF or not isinstance(ep, int)
                                             else ("after", ep - 1), "fills": {}}, overlay, stack_patch))
        if len(index_fills) < 16:
            index_fills.update(sorted(orun.idx_fills)[:16 - len(index_fills)])
        obs_run = {j: (dict(ob, next=orun.cmp_obs2[j]) if j in orun.cmp_obs2 else ob)
                   for j, ob in orun.cmp_obs.items()}
        if o["status"] == "ret" and len(wreads) < 8192 and "opwords" not in EQUIV_OFF:
            wr_ = set()
            for ob_ in obs_run.values():
                for o_ in ob_.get("ops") or ():
                    sr_ = o_.get("src")
                    if sr_ and isinstance(sr_[0], int) and sr_[1] == 4 and o_.get("pc") and isinstance(o_.get("val"), int) \
                            and len(wr_) < 64:
                        wr_.add((o_["pc"], sr_[0], tuple(o_.get("xf") or ()), o_["val"]))
            # (and the stack arguments the loops' exit compares test: `for (pc = 0; pc < lastpc; pc++)`)
            wb_ = set()
            for j_, ob_ in obs_run.items():
                if j_ in loop_exits:
                    for o_ in ob_.get("ops") or ():
                        sr_ = o_.get("src")
                        if sr_ and isinstance(sr_[0], int) and sr_[1] == 4 and not o_.get("xf") and \
                                ENTRY_ESP + 4 <= sr_[0] < ENTRY_ESP + 0x84 and isinstance(o_.get("val"), int):
                            wb_.add((sr_, o_["val"]))
            wreads[(seed, repr(overlay), repr(stack_patch))] = (tuple(wr_), tuple(wb_), overlay, stack_patch)
        if o["status"] == "ret":
            directed_ = bool(overlay) or bool(stack_patch)
            for j, ob in obs_run.items():
                lst = observations.setdefault(j, [])
                if len(lst) < 6 and all(x[0] != seed for x in lst):
                    lst.append((seed, ob, overlay, stack_patch))
                elif directed_ and len(lst) < 12 and "chain" not in EQUIV_OFF and j in missing_now[0] and \
                        all(x[0] != seed or x[2] != overlay or x[3] != stack_patch for x in lst) and \
                        all(_obs_shape(x[1]) != _obs_shape(ob) for x in lst):
                    # (round 9, chain) a directed input that reached a compare with a side still missing in a new
                    # way (another source, or another compare deciding it): its patches carry on from there (a
                    # second condition behind the first one it satisfied, `eax == [g]` then `edx == [g+4]`), so
                    # it is kept even when the first six came earlier
                    lst.append((seed, ob, overlay, stack_patch))
        elif o["status"] in ("timeout", "fault:too_many_pages") and orun.rep_obs is not None:
            if len(stuck) < 256:
                stuck.append((seed, overlay, stack_patch, [(orun.rep_obs["addr"], orun.rep_obs)]))
        elif o["status"] in ("timeout", "fault:too_many_pages") and not o["huge_rep"]:
            # a loop that ran too long: remember its hottest comparisons, to end it early (repair below)
            # (a loop's back edge first: `cmp esi, [count]; jb top` bounds the loop, while the hottest compares
            # are often clamps inside its body, whose patching never ends it)
            cand = [j for j, _ in orun.jcc_count.most_common(12) if j in obs_run]
            if "exits" in EQUIV_OFF:
                back = [j for j in cand if oview.insns[j].target is not None and oview.insns[j].target <= j]
            else:
                # the compares that can end a loop: its back edge (`cmp esi, [count]; jb top`) or a jump out
                # of it (a top-tested loop's `cmp; jae out` before the body and the `jmp top`), as opposed to
                # clamps inside the body, whose patching never ends it. Every such compare that ran often
                # counts, hottest first, but only if a patch can move it (an inner loop over a constant
                # bound, `cmp edx, 8; jb`, is the hottest back edge and can't): the outer loop's bound can
                # be far down the list when the body has many branches
                nst = len(make_input(seed, sig, globals_, min_words=own_words)["stack"])
                top = max(orun.jcc_count.values(), default=0)      # (round 8: none when it timed out in a helper)
                back = [j for j, c in orun.jcc_count.most_common() if c >= max(16, top // 64) and j in obs_run
                        and j in loop_exits and _patches(obs_run[j], overlay, stack_patch, nst)]
                cand = [j for j in cand if j not in back]
            hot = [(j, obs_run[j]) for j in (back[:2] + [j for j in cand if j not in back[:2]])][:3]
            if hot and len(stuck) < 256:
                stuck.append((seed, overlay, stack_patch, hot))
            if "smallcount" not in EQUIV_OFF and len(count_pcs) < 64:
                # (round 9, smallcount) the loads of a runaway loop's bound (`mov ecx, [eax+0xc]` ... `cmp esi,
                # ecx; jb top`): later timed-out inputs get small counts there in one go (56 loops in a row
                # need 56 repairs one at a time)
                for j, ob in hot:
                    wk_ = _walk_side(ob) if j in loop_exits and "walkend" not in EQUIV_OFF else None
                    if wk_ is not None and ob.get("addr") is not None:
                        # (round 10, walkend) a list or tree walk: its links end at the sentinel, not at a count
                        if label is None and overlay is None and stack_patch is None and \
                                not walk_to_seen.get(seed):
                            walk_to_seen[seed] = True
                            walk_to[0] += 1
                        count_pcs.add(ob["addr"])
                        count_walks[ob["addr"]] = wk_
                        if "walkheads" not in EQUIV_OFF:
                            # (round 11, walkheads) its top test: the same compare a little before it, whose jump
                            # leaves forward past the loop (`cmp eax, edx; je out` ... `cmp eax, edx; jne top`)
                            ci_ = oview.insns.get(ob["addr"])
                            for a_, i_ in oview.insns.items():
                                if ci_ is None or not ob["addr"] - 0x60 <= a_ < ob["addr"] or \
                                        (i_.mnemonic, i_.op_str) != (ci_.mnemonic, ci_.op_str) or a_ in count_walks:
                                    continue
                                jx_ = oview.insns.get(a_ + i_.size)
                                if jx_ is not None and jx_.kind == "jcc" and jx_.target is not None and jx_.target > j:
                                    count_walks[a_] = wk_
                                    walk_heads[a_] = ob["addr"]
                        continue
                    if j in loop_exits:
                        for o_ in ob.get("ops") or ():
                            sr_ = o_.get("src")
                            if sr_ and isinstance(sr_[0], tuple) and sr_[0][0] == "ftol" and isinstance(sr_[0][1], tuple) \
                                    and isinstance(sr_[0][1][0], tuple) and sr_[0][1][0][0] == "fret" and \
                                    sr_[0][1][0][1] < len(orun.calls) and "ftolunit" not in EQUIV_OFF and \
                                    len(unit_targets) < 8:
                                # (round 11, ftolunit) `end = (int)(pow(x, e) * n)` bounds the loop: a stub's float
                                # result through __ftol2, a new call in every outer round (256 rows of a table)
                                unit_targets.add(orun.calls[sr_[0][1][0][1]]["target"])
                                continue
                            if sr_ and o_.get("dpc") and "diffcount" not in EQUIV_OFF:
                                # (round 10, diffcount) the bound is `(end - begin) >> 2`: planted at the sub
                                count_pcs.add(o_["dpc"][0])
                                count_diffs[o_["dpc"][0]] = o_["dpc"][1]
                            elif sr_ and isinstance(sr_[0], int) and not STACK_LO <= sr_[0] < STACK_HI and o_.get("pc") and \
                                    not ("addrcount" not in EQUIV_OFF and any(x[0] == "addp" for x in o_.get("xf") or ()) and
                                         all(x_.get("imm") is None for x_ in ob.get("ops") or () if x_ is not o_)):
                                # (round 14, addrcount: not an address computed from a pointer and compared with another
                                # register, `cmp eax, edx` with edx = `&tree.nil` = owner + 0x3c: planting a small "count"
                                # there turns the owner into 2, a node in the zero page. `lea eax, [ecx + 1]` compared with
                                # an immediate is a count: 0x000e36c0)
                                count_pcs.add(o_["pc"])
            for j, c in orun.jcc_count.most_common(1):
                if c > 1000 and o["status"] == "timeout" and not orun.loop_abort and repair_on[0]:
                    loop_limits[j] = 256
            if o["status"] == "timeout" and label is None and overlay is None and stack_patch is None:
                # (round 11, constloop) the loop the run spent most rounds in counts down from a constant (`mov ebx,
                # 0x800; ... dec ebx; jne`: 2048 slots with two constructor calls each): nothing in the input sizes it
                const_to[0] += 1
                top_ = max(orun.jcc_count.values(), default=0)
                hot_ = [j_ for j_, c_ in orun.jcc_count.items() if j_ in loop_exits and 2 * c_ >= top_]
                # (every loop exit that ran at least half as often as the hottest compare)
                if hot_ and all(j_ in obs_run and (obs_run[j_].get("ops") or ()) and
                                all(o_.get("src") is None for o_ in obs_run[j_].get("ops") or ()) for j_ in hot_):
                    const_to[1] += 1
        last_status[0] = o["status"]
        last_steps[0] = o.get("steps", 0)
        if label is None and overlay is None and stack_patch is None:
            if o["status"] == "ret" and last_steps[0] < EARLY_STEPS:
                early_rets[0] += 1
            elif o["status"] == "timeout" and first_to[0] is None:
                first_to[0] = seed
        last_sentinels[0] = _walk_sentinels(obs_run, orun.jcc_count) \
            if o["status"] == "timeout" and "sentinel" not in EQUIV_OFF else ()
        res["statuses"][o["status"]] += 1
        if o["huge_rep"]:
            res["huge_rep"] = True
        if o["status"] == "timeout":
            timeout_calls[0] = max(timeout_calls[0], len(o["calls"]))
        if o["status"] in ("timeout", "fault:too_many_pages") or o["status"].startswith("fault:hook_error"):
            res["inputs_inconclusive"] += 1
            return None
        if orun.smashed is not None:
            ub = "stack_smash"   # (round 8, smash) the original overran a buffer into its return address or saved registers
            if o["status"] in ("fault:wild_jump", "fault:wild_call"):
                # (it went wild because of the overrun: not a sign of a call modelled wrong, the 10% wild bar)
                res["inputs_inconclusive"] += 1
                res["statuses"][ub] += 1
                return None
        if o["status"] in ("fault:wild_jump", "fault:wild_call"):
            # the original's control flow went wild (a fuzzed pointer overwrote its return address or a
            # saved register, or a fuzzed code pointer lands inside the function): no real input does that
            res["inputs_inconclusive"] += 1
            res["statuses"]["wild"] += 1
            return None
        rrun = Run(prog, rview, mach, inp, ours_image=(OURS, ours.image), sig=sig, max_steps=steps[0] * 2,
                   own_float_ret=own_float, helpers=helpers)
        rrun.pointee_sizes = psizes or {}
        rrun.intrinsics = {a: n for a, n in ours.poison.items() if n in INTRINSIC_NAMES}
        rrun.local_code = (OURS, ours.end)
        rrun.self_alias = oview.entry
        rrun.convs = convs or {}
        rrun.orig_entry = oview.entry
        rrun.decls = decls or {}
        rrun.varargs = varargs
        rrun.caller_cleans = caller_cleans
        rrun.slot_arity = slot_arity
        rrun.wild_check = True
        r = rrun.run(rview.entry)
        if orun.code_write is not None or rrun.code_write is not None:
            # a store through a fuzzed pointer that lands on code (ours at OURS, or the original's .text)
            # rewrites one side's instructions only: the game never does that, so the input proves nothing
            res["inputs_inconclusive"] += 1
            res["statuses"]["code_write"] += 1
            return None
        readback = any(orun.fill_pre.get(f) != rrun.fill_pre.get(f) for f in orun.fill_readback | rrun.fill_readback)
        if r["status"] == "fault:too_many_pages" and o["status"] == "ret" and o["huge_rep"]:
            # a fill or copy of a fuzzed, absurd size (over 4 MB): Unicorn's rep string op got through it
            # in the original, our inlined/semantic copy hit the page limit. An emulator artefact.
            res["inputs_inconclusive"] += 1
            res["statuses"]["ours_too_many_pages"] += 1
            return None
        if r["status"] == "fault:wild_call":
            res["inputs_inconclusive"] += 1         # a fuzzed code pointer into our own function (see above)
            res["statuses"]["wild"] += 1
            return None
        diffs = compare_runs(o, r, ret_kind, mach, Namer(inp, sig, prog), prog, esp_adjust=esp_adjust,
                             skip_saved=set(target_conv or ()), void_eax=void_eax)
        if ub and diffs:
            # (round 8) an input that is undefined behaviour in the original (above) and shows a difference
            # is inconclusive: no real input does that. One that agrees counts as before.
            res["inputs_inconclusive"] += 1
            res["statuses"][ub] += 1
            return None
        if readback and not diffs:
            # a callee-extent fill replaced a word the function had written, the two sides held different
            # values there, and one of them read it back: if the real callee doesn't write that word (the
            # static extent is a range, not a set of stores), the fill may have hidden a difference. (A
            # difference seen anyway still fails: the same fill on both sides can't create one.)
            res["inputs_inconclusive"] += 1
            res["statuses"]["fill_readback"] += 1
            return None
        if diffs and o["status"].startswith("fault:") and r["status"].startswith("fault:") and \
                all(d == "original %s but ours %s" % (o["status"], r["status"]) for d in diffs):
            # both sides crash, with the same calls and writes up to there, only differently (an overflowed
            # stack buffer hits the cookie check in one, a smashed saved register in the other)
            res["inputs_inconclusive"] += 1
            res["statuses"]["both_fault"] += 1
            return None
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
        el = time.process_time() - t_start
        lm = 3
        if steps[0] >= LONG_STEPS and "longmore" not in EQUIV_OFF and res["inputs_run"] < 50 and \
                res["statuses"].get("ret", 0) >= 8 and res["statuses"].get("ret", 0) >= 4 * nrun_away():
            # (round 11, longmore) long but finite code (the original returns on four in five inputs at the long
            # budget: 2048 slots with two constructor calls each, 10,000 stub calls an input) gets up to 8x the time
            # budget while fewer than the 50 inputs promotion asks for have completed
            lm = 8
        if (el > time_budget * lm and steps[0] >= LONG_STEPS) or \
                (el > time_budget * (lm if steps[0] >= LONG_STEPS else 1) and res["inputs_run"] >= 8):
            res["time_budget_hit"] = True
            return True
        return False

    def time_frac():
        el = time.process_time() - t_start
        return el / (time_budget * (3 if steps[0] >= LONG_STEPS else 1))

    # 1. random inputs; then more while coverage keeps growing
    rs = {"seed": 0, "stale": 0, "rinc": 0, "done": False}

    def sentinel_retry(seed, overlay, patch, n0):
        """(round 7) An input whose original ran away walking links (a list or tree over fuzzed pointers that
        never reach `&tree.nil`): run it again with the values the walk compared against planted in half
        of every data page. New edges, or None. Stops being tried when it doesn't help."""
        if sent_left[0] <= 0 or (sent_left[1] >= 4 and not sent_left[2]) or \
                (sent_left[1] >= 24 and sent_left[2] * 8 < sent_left[1]):
            return None
        sv = ()
        saved = stuck[n0:]
        new = None
        for _ in range(3):
            # (a run that then hangs in a walk toward another sentinel, a second tree, goes again with both)
            more = tuple(x for x in last_sentinels[0] if x not in sv)
            if not more or last_status[0] != "timeout" or sent_left[0] <= 0:
                break
            sv = (sv + more)[:6]
            sent_left[0] -= 1
            sent_left[1] += 1          # (each run counts: the 7 KB vertex emitters time out at full cost)
            pt = dict(patch or {})
            pt[("sentinel",)] = sv
            del stuck[n0:]             # (the plain run's stuck entry: repaired below if this doesn't help)
            t_ = time.process_time()
            new = run_input(seed, overlay, pt, label="%d+nil" % seed)
            res["sentinel_runs"] = res.get("sentinel_runs", 0) + 1
            res["sentinel_time"] = round(res.get("sentinel_time", 0) + time.process_time() - t_, 1)
            if new is not None:
                break
        if new is None:
            del stuck[n0:]
            stuck.extend(saved)     # (loop repair works from the plain run)
        if new is not None:
            sent_left[2] += 1
            res["inputs_sentinel"] = res.get("inputs_sentinel", 0) + 1
        return new

    def runaway():
        """The last input's original ran away: out of steps, or (round 10, smallpages) out of pages (a loop over a
        fuzzed count that writes as it goes, `do { top->tt = 0; top++; } while (--n)`)."""
        return last_status[0] == "timeout" or (last_status[0] == "fault:too_many_pages" and "smallpages" not in EQUIV_OFF)

    def nrun_away():
        return res["statuses"].get("timeout", 0) + \
            (res["statuses"].get("fault:too_many_pages", 0) if "smallpages" not in EQUIV_OFF else 0)

    def small_retry(seed, overlay0=None, patch0=None):
        """(round 9, smallcount) An input whose original ran away in loops whose counts known loads read: a
        discovery run of the original with small counts planted where those loads read, then the input again
        with those counts in its memory (both sides alike). New edges, or None."""
        # (stops when it costs a quarter of the time budget without getting an input through, a tenth of it
        # while fewer than 1 in 4 rounds do, or 35% of it in all: the directed inputs need their share)
        budget_ = time_budget * (3 if steps[0] >= LONG_STEPS else 1)
        if not count_pcs or small_left[0] <= 0 or (not small_left[2] and small_left[4] > 0.25 * budget_) or \
                (small_left[1] >= 16 and small_left[2] * 4 < small_left[1] and small_left[4] > 0.1 * budget_) or \
                small_left[4] > 0.35 * budget_:
            return None
        plants = {}
        new = None
        t0_ = time.process_time()
        try:
            return _small_rounds(seed, overlay0, patch0, plants)
        finally:
            small_left[4] += time.process_time() - t0_

    def _small_rounds(seed, overlay0, patch0, plants):
        new = None
        # (round 10, tinycount: once counts of 0 or 1 got inputs through where 1-4 didn't, start with them)
        tiny = [small_left[3] >= 2 and "tinycount" not in EQUIV_OFF]
        diverged = [0]
        # (each round plants the counts of the loops the last one ran away in; 8 rounds until it got 2 inputs
        # through, then up to 64: 56 copy loops in a row)
        for _ in range(64 if small_left[2] >= 2 else 8):
            if small_left[0] <= 0 or out_of_time():
                break
            small_left[0] -= 1
            small_left[1] += 1
            inp_, inp_o_, mach_ = build(seed, _merge_ov(overlay0, _ov_plants(plants)), _pt_plants(patch0, plants))
            drun = Run(prog, oview, mach_, inp_o_, ours_image=(OURS, ours.image), sig=sig, max_steps=steps[0],
                       own_float_ret=own_float, coverage=True, helpers=helpers)
            drun.pointee_sizes = psizes or {}
            drun.convs = convs or {}
            drun.orig_entry = oview.entry
            drun.slot_arity = slot_arity
            drun.varargs = varargs
            drun.wild_check = True
            drun.count_pcs = set(count_pcs)
            drun.count_diffs = dict(count_diffs)
            drun.count_walks = dict(count_walks)
            drun.walk_heads = dict(walk_heads)
            drun.count_tiny = tiny[0]
            drun.loop_limits = loop_limits
            dst_ = drun.run(oview.entry)["status"]
            more_ = {k_: v_ for k_, v_ in drun.count_plants.items() if plants.get(k_) != v_}
            if not more_:
                break
            plants.update(more_)
            n0 = len(stuck)
            npc = len(count_pcs)
            new = run_input(seed, _merge_ov(overlay0, _ov_plants(plants)), _pt_plants(patch0, plants),
                            label="%d+small" % seed)
            res["inputs_small"] = res.get("inputs_small", 0) + 1
            if new is not None:
                small_left[2] += 1
                if tiny[0]:
                    small_left[3] += 1
                return new
            if not runaway():
                break
            if dst_ == "ret" and diverged[0] < 2 and "walkend" not in EQUIV_OFF:
                # (round 10) the discovery run returned, the input with its plants didn't: a planted word was read
                # before the plant too (fuzzed nodes alias: one node's link is another's key). Another discovery run
                # starts from the plants
                diverged[0] += 1
                del stuck[n0:]
                continue
            if len(count_pcs) == npc:
                # (another round only when this one learned the count of another loop; or, round 10, tinycount:
                # once, with counts of 0 or 1 everywhere, when the loop it still runs away in has a bound no load
                # feeds: `for i < n: for j = i; j < n` over the n points the counted loops collected)
                if tiny[0] or "tinycount" in EQUIV_OFF:
                    break
                tiny[0] = True
            del stuck[n0:]
        return None

    def probe_steps(seed0=0):
        """Re-run input 0 (round 11: the first that ran out of steps) with PROBE_STEPS. If its original returns,
        the code is long but finite: every later input gets twice the steps it took (at least LONG_STEPS) and
        3x the time budget."""
        old = steps[0]
        steps[0] = PROBE_STEPS
        run_input(seed0, label="%d+steps" % seed0)
        if last_status[0] == "ret":
            steps[0] = min(PROBE_STEPS, max(LONG_STEPS, 2 * last_steps[0]))
            res["long_steps"] = probed[0] = steps[0]
        else:
            steps[0] = old
            probed[0] = 0

    def activate_static(seed):
        """(round 14, staticcount) Start using the `sub; sar` element counts found in the code (see static_diffs)."""
        static_counts[0] = True
        count_diffs.update(static_diffs)
        count_pcs.update(static_diffs)
        res["static_counts"] = len(static_diffs)
        small_left[1] = small_left[2] = 0      # (a fresh account: the rounds so far knew none of these sites)
        small_left[4] = 0.0

    def random_phase(soft, until_run=None, nocap=False, stop_frac=None):
        """soft: hand over to the directed phase once half the time budget is gone and 50 inputs completed
        (with --inputs 3000 the random inputs alone would use all of it); the rest of the random inputs
        run after the directed ones."""
        while rs["seed"] < max_inputs and res["inputs_failed"] < 3 and not out_of_time():
            seed = rs["seed"]
            if until_run is not None and res["inputs_run"] >= until_run:
                return
            if soft and res["inputs_run"] >= 50 and seed >= 256 and time_frac() > 0.5 and \
                    "soft" not in EQUIV_OFF:
                return
            if stop_frac is not None and seed >= 3000 and time_frac() > stop_frac:
                return      # (round 9, morein) past what --inputs 3000 runs: leave time for the directed inputs
            # (round 11, earlyret) inputs whose original returned at once (`if (start == 0) return`, 6 steps)
            # say nothing about how long the code runs: the step budget is decided at the 4th other input
            # (only while every input that ran out of steps did so in a loop over a constant count: an early return
            # next to runaway loops over fuzzed counts is a fuzzed input like any other)
            early = early_rets[0] if "earlyret" not in EQUIV_OFF and const_to[1] == const_to[0] else 0
            at_budget = budget_seed[0] is None and seed >= 4 and (seed - early >= 4 or seed >= 16)
            if at_budget:
                budget_seed[0] = seed
            all_out = at_budget and seed - early == 4 and res["statuses"].get("timeout") == 4
            if all_out and walk_to[0] >= 4 and "walknolong" not in EQUIV_OFF:
                # (round 11, walknolong) every one ran out of steps walking fuzzed links that never reach the walk's
                # sentinel: runaway walks (the walk sentinels end them), not long code. A million steps each would only
                # spend the time budget going round the same cycle
                all_out = False
                res["long_skipped"] = "walks"
            if all_out and steps[0] < LONG_STEPS and not res.get("huge_rep") \
                    and timeout_calls[0] < 500:
                # every input so far ran out of steps: long-running code (string building, big loops), not
                # fuzzed sizes (no rep string instruction with an absurd count) or a loop that runs until a
                # stubbed callee says stop (thousands of calls). Give the remaining inputs a much bigger budget (and 3x the time).
                steps[0] = LONG_STEPS
                res["long_steps"] = LONG_STEPS
                long_seed[0] = seed
                if early:
                    res["early_returns"] = early
            elif (all_out or (at_budget and "constloop" not in EQUIV_OFF and const_to[0] >= 3 and
                              const_to[1] == const_to[0])) and \
                    steps[0] < LONG_STEPS and probed[0] is None and "probe" not in EQUIV_OFF and not only_seeds:
                # (round 11, constloop: also when three of the first four ran out of steps, every one of them in a
                # loop over a constant count, and the fourth returned through a stub result that skips the loops)
                # (round 7) thousands of stub calls or a big rep: a fixed loop with many calls per round (100
                # objects x 66 calls) runs long but ends; a loop a stubbed callee keeps going never does.
                # One input (the pristine one) with a huge budget tells them apart
                s0_ = first_to[0] or 0
                skipped_ = bool(count_pcs and "smallcount" not in EQUIV_OFF and small_retry(s0_) is not None)
                if not skipped_ and static_diffs and not static_counts[0] and "smallcount" not in EQUIV_OFF:
                    # (round 14, staticcount) the sites the runaway loops pointed to got no input through (or there were
                    # none): the code's own element counts are the next thing to try, before the 8M-step probe
                    activate_static(seed)
                    skipped_ = small_retry(s0_) is not None
                if skipped_:
                    # (round 9) ... unless small counts at the loads that fed the runaway loops already got an input
                    # through: fuzzed counts, not long code (the 8M-step probe took 100 s of the 120 s budget)
                    probed[0] = 0
                    res["probe_skipped"] = True
                else:
                    probe_steps(s0_)
            if long_seed[0] is not None and seed == long_seed[0] + 4 and steps[0] >= LONG_STEPS and \
                    res["statuses"].get("timeout", 0) >= 6 and not probed[0]:
                steps[0] = max_steps          # the bigger budget didn't help: fuzzed loop bounds after all
                res.pop("long_steps", None)
            if not repair_on[0] and steps[0] < LONG_STEPS and budget_seed[0] is not None and \
                    (seed == budget_seed[0] or seed == budget_seed[0] + 4):
                # the step budget is settled (it isn't long-running code): repair the runaway inputs so far
                repair_on[0] = True
                for st_ in list(stuck):
                    if not out_of_time():
                        repair(st_)
            if seed >= n_inputs:
                if coverage_of(oview, edges)["complete"] or rs["stale"] >= 16:
                    break
            n0 = len(stuck)
            if only_seeds and seed not in only_seeds:      # (EQUIV_SEEDS=7913,9556: debugging one input)
                rs["seed"] += 1
                continue
            new = None
            tried_small = False
            nst_ = sum(res["statuses"].values())
            # (round 14, staticcount) the code's own element counts are known: inputs start with them small as soon as
            # two have run away, without waiting for the loop-repair bookkeeping
            if static_diffs and not static_counts[0] and nrun_away() >= 16 and res["inputs_run"] < 16:
                activate_static(seed)
            static_go = static_counts[0] and nrun_away() >= 2 and 2 * nrun_away() >= nst_ and seed % 4 != 3 and \
                "smallcount" not in EQUIV_OFF and (small_left[1] < 8 or small_left[2] * 4 >= small_left[1])
            if static_go or (count_pcs and repair_on[0] and small_left[2] >= 2 and small_left[2] * 2 >= small_left[1] and
                             "smallcount" not in EQUIV_OFF and
                             2 * nrun_away() >= nst_ and (seed % 4 or (seed % 8 and 10 * nrun_away() >= 9 * nst_))):
                # (round 9, smallcount) most inputs run away and small counts got some through: three in four
                # inputs start with their loop counts small (the fourth stays as drawn)
                n1 = len(stuck)
                new = small_retry(seed)
                tried_small = True
                if new is None:
                    del stuck[n1:]
            if new is None and not (tried_small and runaway()):
                new = run_input(seed)
            rs["seed"] += 1
            if new is None and runaway() and count_pcs and repair_on[0] and not tried_small and \
                    "smallcount" not in EQUIV_OFF:
                n1 = len(stuck)
                new = small_retry(seed)
                tried_small = True
                if new is None:
                    del stuck[n1:]          # (the plain run's stuck entry stays for the repair below)
                else:
                    # (the input as drawn ran away: it still counts toward the 32-inconclusive cap of the random
                    # phase, which hands the time to the directed inputs as before; else a function where half
                    # the inputs run away spent the whole budget on random ones)
                    rs["rinc"] += 1
            if new is None and last_sentinels[0] and last_status[0] == "timeout":
                new = sentinel_retry(seed, None, None, n0)
            if new is None:
                rs["rinc"] += 1          # (repair runs that time out don't count here)
                if repair_on[0] and len(stuck) > n0 and not (small_left[2] >= 2 and tried_small):
                    # (round 9: not after small counts got some inputs through and failed on this one)
                    repair(stuck[n0])
                if rs["rinc"] >= 32 and res["inputs_run"] >= 8 and until_run is None and not nocap:
                    res["inconclusive_cap_hit"] = True
                    break
                continue
            if res["statuses"].get("ret", 0) < 8 and res["inputs_faulted"] < 192 and not new:
                continue        # the original mostly faults (e.g. a divisor from memory): keep looking for inputs it completes
            rs["stale"] = 0 if new else rs["stale"] + 1
        rs["done"] = True

    # 3. directed inputs: for a branch side never taken, re-run the input that reached its comparison
    #    with the compared memory (or argument) patched to the value on the other side
    tried = set()
    dstate = {"budget": directed}
    refund = [0]
    word_left = [8192]         # (round 11, opwords) planted instruction-word runs left
    word_time = [0.0]          # (round 11) CPU seconds they took (at most 30% of the time budget)

    def directed_run(seed0, overlay, patch, label):
        """A directed input; one whose original runs away in a loop (a switch case's loop over a fuzzed
        count) is repaired like a random one (with its own budget)."""
        n0 = len(stuck)
        e0 = len(edges)
        new = run_input(seed0, overlay, patch, label=label)
        if new is None and runaway() and count_pcs and repair_on[0] and \
                "smallcount" not in EQUIV_OFF:
            # (round 9) a directed input that runs away behind the side it opened: small counts first
            n1 = len(stuck)
            new_ = small_retry(seed0, overlay, patch)
            if new_ is not None:
                return new_ or len(edges) > e0
            del stuck[n1:]
        if new is None and len(stuck) > n0 and repair_on[0] and "drepair" not in EQUIV_OFF and \
                directed_repair[0] > 0:
            left = repair_left[0]
            repair_left[0] = min(directed_repair[0], 8)
            repair(stuck[n0])
            directed_repair[0] -= min(directed_repair[0], 8) - repair_left[0]
            repair_left[0] = left
            if len(edges) > e0:
                return True
        return new

    jcur = {}           # compare -> its next observation to patch (breadth first)
    via_tries = Counter()   # (round 9) compare -> directed inputs steered through the compare that decided a constant
    via_found = set()       # (round 9) ... that found new edges that way

    via_mode = [False]

    def via_ok(j, ob):
        # (a few tries per compare and deciding compare, unless one of them helped: a constant a branch decided is
        # often a flag several conditions feed, and the budget is shared; a try that moves the decision to the
        # next condition, `edx == [g+4]` after `eax == [g]`, starts afresh)
        return via_mode[0] and (via_tries[_via_key(j, ob)] < 3 or j in via_found)
    active = set()      # compares being driven
    more = [False]      # some compare still has untried observations

    def directed_phase():
        progress = True
        via_mode[0] = False
        while dstate["budget"] > 0 and res["inputs_failed"] < 3 and not out_of_time():
            if not (progress or more[0]):
                if via_mode[0] or "via" in EQUIV_OFF:
                    break
                # (round 9, via) the direct patches are used up: now through the compares that decided the
                # constants other compares test (a flag set on one side of a branch)
                via_mode[0] = True
            progress = False
            more[0] = False
            dead = infeasible_edges(oview)
            missing = {j for j in oview.jcc for t in (oview.insns[j].target, j + oview.insns[j].size)
                       if (j, t) not in edges and (j, t) not in dead} | \
                {j for j in oview.setcc for v in ("set0", "set1") if (j, v) not in edges and (j, v) not in dead}
            missing_now[0] = set(missing)
            table_cases = {}
            for j, tg in oview.tables.items():
                if "caseidx" not in EQUIV_OFF:
                    miss = [i for i in range(table_cases_n(oview, j)) if (j, ("idx", i)) not in edges and
                            (j, tg[i]) not in dead]
                else:
                    miss = [i for i, t in enumerate(tg) if (j, t) not in edges and (j, t) not in dead]
                if miss:
                    table_cases[j] = miss
                    missing.add(j)
            # string compares against literals: plant the literal in the buffer compared (fuzzed bytes never
            # spell "Millimeters"); planted runs queue the compares they reach next (chains of keywords)
            # (at most half the budget left per pass: the compares' own patches need their turn too, a chain
            # of keyword tests through a stubbed compare wrapper behind an inline name compare)
            str_cap = dstate["budget"] - max(8, dstate["budget"] // 2) if "strcap" not in EQUIV_OFF else -1 << 30
            while missing and str_queue and dstate["budget"] > max(0, str_cap) and res["inputs_failed"] < 3 \
                    and not out_of_time():
                qi = 0
                if "strrr" not in EQUIV_OFF:
                    # (round 9, strrr) round robin over the buffers and literal sites queued: a second char loop's
                    # strings no longer wait behind 24 of the first one's
                    def skey(e_):
                        st_ = e_[1]["site"]
                        return ("alpha", st_[1]) if isinstance(st_, tuple) and st_ and st_[0] == "alpha" else st_
                    qi = min(range(min(len(str_queue), 256)), key=lambda i_: (str_popped[skey(str_queue[i_])], i_))
                    str_popped[skey(str_queue[qi])] += 1
                seed0, sob, ov0, sp0 = str_queue.pop(qi)
                if sob.get("psrc") is not None:
                    sob = dict(sob, nstack=len(make_input(seed0, sig, globals_, min_words=own_words)["stack"]))
                for overlay, patch in _plants(sob, ov0, sp0):
                    key = (sob["site"], seed0, tuple(sorted(map(repr, overlay.items()))),
                           tuple(sorted(map(repr, patch.items()))))
                    if key in tried:
                        continue
                    tried.add(key)
                    dstate["budget"] -= 1
                    res["inputs_directed"] += 1
                    res["inputs_planted"] = res.get("inputs_planted", 0) + 1
                    if directed_run(seed0, overlay, patch, "%d+str" % seed0):
                        progress = True
                        if refund[0] < 3 * directed:
                            dstate["budget"] += 4
                            refund[0] += 4
            if missing and word_left[0] > 0 and "opwords" not in EQUIV_OFF:
                # (round 11, opwords) an interpreter loop over instruction words from fuzzed memory: random words
                # rarely get past the per-field checks (`op < 0x24`, `a < maxstacksize`, `b < sizek`) to the case
                # of each opcode. Plant runs of words made of field values the compares name
                models = _word_models(observations, wreads, oview.insns)
                if models:
                    import random
                    rnd = random.Random(mix(len(edges), word_left[0], 0x0B5))
                    miss_run = 0
                    for _ in range(min(word_left[0], 1024)):
                        if out_of_time() or res["inputs_failed"] >= 3 or miss_run >= 256 or \
                                word_time[0] > 0.3 * time_budget:
                            break
                        t_w = time.process_time()
                        model, bases_ = models[rnd.choice(sorted(models))]
                        seed0, ov0, sp0, ea1, ea2, keep_, bnd_ = rnd.choice(bases_)
                        stride = ea2 - ea1 if ea2 is not None and 0 < ea2 - ea1 <= 16 else 4
                        nw_ = rnd.randint(1, 8)
                        ov_ = _merge_ov(ov0, _word_plant(model, ea1, stride, nw_, rnd, keep_))
                        sp_ = dict(sp0 or {})
                        if rnd.random() < 0.5:
                            # (stub results that let the per-word checks pass: a checker callee returning 0 ends the
                            # loop at the first word in a zero-stub input)
                            sp_[("stubmode",)] = rnd.choice(("normal", "one"))
                        nst_ = len(make_input(seed0, sig, globals_, min_words=own_words)["stack"])
                        for src_, val_ in bnd_:
                            # (a loop bound in a stack argument below the words planted: raised to their number)
                            if _sx(val_) < nw_:
                                _int_plant_into(src_, nw_ + rnd.randint(0, 2), ov_, sp_, nst_)
                        sp0 = sp_
                        word_left[0] -= 1
                        res["inputs_directed"] += 1
                        res["inputs_words"] = res.get("inputs_words", 0) + 1
                        if directed_run(seed0, ov_, sp0, "%d+words" % seed0):
                            progress = True
                            miss_run = 0
                            word_left[0] += 4
                        else:
                            miss_run += 1
                        word_time[0] += time.process_time() - t_w
            if not missing:
                # everything reached: spend what is left on sides that few inputs took (path diversity)
                rare = [j for j in oview.jcc for t in (oview.insns[j].target, j + oview.insns[j].size)
                        if hits[(j, t)] < RARE_HITS] + \
                       [j for j in oview.setcc for v in ("set0", "set1") if hits[(j, v)] < RARE_HITS]
                missing = set(rare)
            if "breadth" not in EQUIV_OFF and "active" not in EQUIV_OFF:
                # (a compare stays active until both its sides were taken RARE_HITS times, as when all its
                # observations were tried in one go: driving it on reaches the compares behind it)
                active.update(missing)
                missing = missing | active
            for j in sorted(missing):
                if j not in observations or dstate["budget"] <= 0 or out_of_time():
                    continue
                done = False
                obs_j = observations[j]
                if "breadth" not in EQUIV_OFF:
                    # one observation per compare per pass (breadth first, round robin over those with patches
                    # not tried yet): a compare that no patch flips (a value computed from several loads) no
                    # longer spends the whole budget on its six observations before the compares after it get
                    # a turn (a chain of 33 keyword tests)
                    n_ = len(obs_j)
                    c = jcur.get(j, 0)
                    pick = None
                    for step_ in range(n_):
                        idx = (c + step_) % n_
                        seed0, ob, ov0, sp0 = obs_j[idx]
                        if ob["mnemonic"] == "table":
                            ob = dict(ob, want_cases=table_cases.get(j, [])[:3])
                        if any((j, seed0, tuple(sorted(map(repr, ov_.items()))), tuple(sorted(map(repr, pt_.items()))))
                               not in tried for ov_, pt_ in
                               _patches(ob, ov0, sp0, len(make_input(seed0, sig, globals_, min_words=own_words)["stack"]),
                                        via=via_ok(j, ob))[:3]):
                            pick = idx
                            break
                    if pick is None:
                        continue
                    jcur[j] = pick + 1
                    obs_j = obs_j[pick:] + obs_j[:pick]     # (on to the next ones while they find edges)
                    more[0] = True
                breadth = "breadth" not in EQUIV_OFF
                for oi, (seed0, ob, ov0, sp0) in enumerate(obs_j):
                    found = False
                    if ob["mnemonic"] == "table":
                        ob = dict(ob, want_cases=table_cases.get(j, [])[:3])
                    # (round 9: through the compare that decided a constant too; loop repair doesn't, an inner loop
                    # over a constant bound must stay unpatchable there)
                    via_only = not _obs_steerable(ob, via=False)
                    for overlay, patch in _patches(ob, ov0, sp0, len(make_input(seed0, sig, globals_, min_words=own_words)["stack"]),
                                                   via=via_ok(j, ob))[:3]:
                        key = (j, seed0, tuple(sorted(map(repr, overlay.items()))), tuple(sorted(map(repr, patch.items()))))
                        if key in tried:
                            continue
                        tried.add(key)
                        dstate["budget"] -= 1
                        res["inputs_directed"] += 1
                        new = directed_run(seed0, overlay, patch, "%d+patch" % seed0)
                        if via_only:
                            via_tries[_via_key(j, ob)] += 1
                            if new:
                                via_found.add(j)
                        if new:
                            progress = True
                            found = True
                            if refund[0] < 3 * directed:
                                dstate["budget"] += 4         # still finding new edges: keep going (up to 4x the budget)
                                refund[0] += 4
                        if j in oview.tables:
                            sides = [(j, t) for t in set(oview.tables[j])]
                        elif oview.insns[j].kind == "jcc":
                            sides = [(j, oview.insns[j].target), (j, j + oview.insns[j].size)]
                        else:
                            sides = [(j, "set0"), (j, "set1")]
                        if j in oview.tables and "caseidx" not in EQUIV_OFF and \
                                any(hits[(j, ("idx", k_))] == 0 for k_ in table_cases.get(j, ())):
                            pass          # (round 15) a case index not reached yet
                        elif all(hits[e] >= RARE_HITS for e in sides):
                            done = True
                            active.discard(j)
                        if done or dstate["budget"] <= 0 or res["inputs_failed"] >= 3:
                            break
                    if done or dstate["budget"] <= 0 or res["inputs_failed"] >= 3:
                        break
                    if breadth:
                        jcur[j] = (pick + oi + 1) % max(1, len(observations[j]))
                        if not found:
                            break

    def tie_phase():
        # (round 12, ties) a compare of two inputs (`fabs(m[0][0]) > eps`, `cmp eax, [ebx+0xc]`) whose sides were
        # both taken: random values never tie, and `>` against `>=` differs only there. One input per compare
        # makes the two equal (where a transform maps the planted value onto the other exactly)
        n_t = 0
        for j in sorted(observations):
            if n_t >= TIE_INPUTS or out_of_time() or res["inputs_failed"] >= 3:
                break
            for seed0, ob, ov0, sp0 in observations[j]:
                pl = _tie_plants(ob, ov0, sp0, len(make_input(seed0, sig, globals_, min_words=own_words)["stack"]))
                if not pl:
                    continue
                overlay, patch = pl[0]
                key = (j, seed0, tuple(sorted(map(repr, overlay.items()))), tuple(sorted(map(repr, patch.items()))))
                if key in tried:
                    break
                tried.add(key)
                n_t += 1
                res["inputs_directed"] += 1
                res["inputs_tie"] = res.get("inputs_tie", 0) + 1
                directed_run(seed0, overlay, patch, "%d+tie" % seed0)
                break

    def objptr_phase():
        # (round 13, objptr) a pointer the code loads and reads a field through, where the words beside that field
        # read the same (a null-page pointer from a constructor stub's fill): one input per access points it at an
        # object whose words all differ, so reading the wrong field reads another value. An input choice, the same
        # on both sides; the plants of the input it came from stay (a chain of objects, OBJ_DEPTH deep)
        n_o = 0
        while objptr_queue and n_o < OBJ_INPUTS and not out_of_time() and res["inputs_failed"] < 3:
            seed0, pc, src, disp, ov0, sp0 = objptr_queue.pop(0)
            ov, pt = dict(ov0 or {}), dict(sp0 or {})
            depth = sum(1 for k_ in ov if k_[0] == "*" and isinstance(k_[1], int) and
                        OBJ_BASE <= k_[1] < OBJ_BASE + OBJ_SIZE * OBJ_DEPTH)
            if depth >= OBJ_DEPTH:
                continue
            obj = OBJ_BASE + OBJ_SIZE * depth
            if not _int_plant_into(src, obj, ov, pt, len(make_input(seed0, sig, globals_, min_words=own_words)["stack"])):
                continue
            ov[("*", obj)] = _obj_words(depth)
            key = ("obj", pc, seed0, tuple(sorted(map(repr, ov.items()))), tuple(sorted(map(repr, pt.items()))))
            if key in tried:
                continue
            tried.add(key)
            n_o += 1
            res["inputs_directed"] += 1
            res["inputs_objptr"] = res.get("inputs_objptr", 0) + 1
            directed_run(seed0, ov, pt, "%d+obj" % seed0)

    directed_repair = [64]
    random_phase(soft=True)
    directed_phase()
    if "ties" not in EQUIV_OFF and not out_of_time() and res["inputs_failed"] < 3:
        tie_phase()
    if "objptr" not in EQUIV_OFF and not out_of_time() and res["inputs_failed"] < 3:
        objptr_phase()
    if not rs["done"] and not out_of_time() and res["inputs_failed"] < 3:
        # (round 9, morein) with --inputs over 3000, the random inputs past 3000 stop at 80% of the time, so the
        # directed inputs after them still run (they ran out of time before: 12000 inputs covered less than 3000)
        random_phase(soft=False, stop_frac=0.8 if n_inputs > 3000 and "morein" not in EQUIV_OFF else None)
        directed_phase()        # (new observations from the later random inputs)
        if not rs["done"] and not out_of_time() and res["inputs_failed"] < 3 and n_inputs > 3000:
            random_phase(soft=False)
            directed_phase()
    if res.get("inconclusive_cap_hit") and 5 * rs["rinc"] <= res["inputs_run"] and rs["seed"] < max_inputs and \
            not out_of_time() and res["inputs_failed"] < 3 and "rate" not in EQUIV_OFF:
        # the random phase stopped at 32 inconclusive inputs though most complete (a few fuzzed counts run
        # away): with the directed inputs done, the time left goes to more random ones, then directed again
        random_phase(soft=False, nocap=True)
        directed_phase()
    if res.get("inconclusive_cap_hit") and res["inputs_run"] < 50 and rs["seed"] < max_inputs and \
            not out_of_time() and res["inputs_failed"] < 3 and "capfix" not in EQUIV_OFF:
        # the random phase stopped at 32 inconclusive inputs (fuzzed counts that run away) short of the 50
        # completed inputs `promotable` asks for: with the directed inputs done, spend the time left on more
        # random ones (each runaway is repaired, as before)
        random_phase(soft=False, until_run=50)
    if res.get("inconclusive_cap_hit") and rs["seed"] < max_inputs and not out_of_time() and \
            res["inputs_failed"] < 3 and "covcap" not in EQUIV_OFF:
        cov_ = coverage_of(oview, edges)
        if cov_["edges_total"] and cov_["edges_covered"] < 0.75 * cov_["edges_total"]:
            # (round 8) the cap stopped the random inputs while branch coverage is under the promotion bar
            # (a polygon clipper whose re-entry arms need rare vertex patterns, 21% of its inputs running
            # away): the time left goes to more random inputs, then directed ones again
            res["covcap"] = True
            random_phase(soft=False, nocap=True)
            directed_phase()
    res["coverage"] = coverage_of(oview, edges)
    res["statuses"] = dict(res["statuses"])
    if res["inputs_run"] == 0:
        res["unsupported"] = "no input ran to completion in the original (%s)" % res["statuses"]
    else:
        res["ok"] = res["inputs_failed"] == 0
    return res


# (round 8) CRT copy routines for which overlapping source and destination is undefined behaviour (C99 7.21.2-3,
# 7.24.4.2): name -> (character size, kind). memcpy is left out: in this XBE it is memmove's code.
UB_COPY = {"_strncat": (1, "ncat"), "_strcat": (1, "cat"), "_strncpy": (1, "ncpy"), "_strcpy": (1, "cpy"),
           "_wcsncpy": (2, "ncpy"), "_wcscpy": (2, "cpy"), "_wcsncat": (2, "ncat"), "_wcscat": (2, "cat")}


def _copy_overlap(kind, cs, args, byte, cap=1 << 16):
    """True when the input provably makes a CRT copy routine read source characters it also writes or reads as
    the destination string (undefined behaviour, so no real caller does it). `byte(a)` reads the input's
    memory. Only bytes the routine certainly touches count: a string whose terminator isn't found within
    `cap` characters is taken to be `cap` long, a subset of what the routine reads."""
    d, s_ = args[0], args[1]
    n = args[2] if kind in ("ncat", "ncpy") else None
    if n == 0:
        return False
    for p in (d, s_):
        if p < NULL_HI or STACK_LO <= p < STACK_HI or p + cap * cs + 8 > M32:
            return False         # (the stack isn't part of the input's memory model: no proof)

    def slen(p):
        for k in range(cap):
            if all(byte(p + k * cs + i) == 0 for i in range(cs)):
                return k, True
        return cap, False
    ls, s_found = slen(s_)
    if kind in ("ncat", "cat"):
        ld, d_found = slen(d)
        if not d_found:
            return False         # the scan for the end of the destination may never finish: nothing certain
    else:
        ld = 0
    k = ls if n is None else min(n, ls)
    rd = k + (1 if s_found and (n is None or n > ls) else 0)        # source characters read
    wr = k + 1 if kind in ("ncat", "cat", "cpy") else n             # characters written at d + ld
    if kind == "cpy" and not s_found:
        wr = k
    lo_s, hi_s = s_, s_ + rd * cs
    lo_d, hi_d = d, d + (ld + min(wr, cap)) * cs        # the destination string read, then the part written
    return rd > 0 and lo_s < hi_d and lo_d < hi_s


def _stub_float(mode, k):
    """The float every stub returns or fills in under a directed input's `stubfloats` patch (call k)."""
    if isinstance(mode, tuple):           # ("alt", v): +v and -v by turns
        return mode[1] if k % 2 == 0 else -mode[1]
    return mode


def _apply_xf(op, v):
    k = op[0]
    if k in ("add", "addp"):
        return (v + op[1]) & M32
    if k == "shr":
        return (v & M32) >> op[1]
    if k == "sar":
        return ((v - (1 << 32) if v & 0x80000000 else v) >> op[1]) & M32
    if k == "shl":
        return (v << op[1]) & M32
    if k == "and":
        return v & op[1]
    if k == "neg":
        return (-v) & M32
    if k == "not":
        return ~v & M32
    if k == "btab":
        return Program.get().read(op[1] + (v & M32), 1)[0] if (v & M32) < 0x10000 else 0
    if k == "mulhi":
        return ((_sx(v) * _sx(op[1])) >> 32) & M32
    if k == "sdiv":
        q = abs(_sx(v)) // abs(op[1]) if op[1] else 0
        return (q if (_sx(v) < 0) == (op[1] < 0) else -q) & M32
    if k == "udiv":
        return (v // op[1]) & M32 if op[1] else 0
    return v


def _sx(v):
    v &= M32
    return v - (1 << 32) if v & 0x80000000 else v


def _invert_fxf(fxf, want):
    """The loaded float that `fadd/fsub/fsubr/fmul [k]` and `fchs` (in order) turn into `want`."""
    w = want
    for m, c in reversed(fxf):
        if m == "fadd":
            w = w - c
        elif m == "fsub":
            w = w + c
        elif m == "fsubr":
            w = c - w
        elif m == "fmul":
            w = w / c
        elif m == "fchs":
            w = -w
        elif m == "fdiv" and c:
            w = w * c
        elif m == "fdivr" and w:
            w = c / w
        elif m == "fabs":
            if w < 0:
                return None
        else:
            return None
    return w if not (math.isnan(w) or math.isinf(w)) else None


TIE_INPUTS = 48             # (round 12, ties) at most this many tie inputs per function
# (round 13, objptr) objects with distinct words that directed inputs point loaded pointers at: OBJ_DEPTH of them,
# OBJ_SIZE bytes each, at the top of the heap (a chain of plants takes the next one)
OBJ_SIZE = 0x400
OBJ_DEPTH = 4
OBJ_BASE = HEAP + HEAP_SIZE - OBJ_SIZE * OBJ_DEPTH
OBJ_INPUTS = 24             # at most this many such inputs per function


def _obj_words(n):
    """(round 13, objptr) The content of the n-th planted object: every word different, and every byte of a
    word's low half (a field read at +1 or as a byte differs too). Small values (counts stay small): word i is
    0x101 * (i + 1) + 0x10000 * n, so `[p+0x18]` is 0x707, `[p+0x1c]` 0x808, the byte at +0x19 is 7."""
    return b"".join(struct.pack("<I", (0x101 * (i + 1) + 0x10000 * n) & M32) for i in range(OBJ_SIZE // 4))
VEXT_SHARED = 3             # (round 12, vext) implementations of a vtable slot that must share an extent


def _tie_plants(ob, overlay0, patch0, nstack):
    """(round 12, ties) Plants that make a compare's two input operands equal (none if a side isn't an input, or
    no planted value comes back as exactly the other side's)."""
    ops = ob.get("ops") or []
    out = []
    if len(ops) != 2 or not all(isinstance(o, dict) for o in ops):
        return out
    if ob["mnemonic"] == "fcmp":
        for x, y in ((ops[0], ops[1]), (ops[1], ops[0])):
            src, yv = x.get("src"), y.get("val")
            if not src or not isinstance(yv, float) or math.isnan(yv) or math.isinf(yv):
                continue
            fxf = tuple(x.get("fxf") or ())
            if not _fxf_exact_tie(fxf, yv, src):
                continue        # (the other side computed in 80 bits: no loaded value equals it exactly)
            pl = _float_plant(x, _invert_fxf(fxf, yv) if fxf else yv, overlay0, patch0, nstack)
            if pl is not None:
                out.append(pl)
    elif ob["mnemonic"] == "cmp":
        for x, y in ((ops[0], ops[1]), (ops[1], ops[0])):
            if not x.get("src") or not isinstance(y.get("val"), int) or x.get("xf") or x.get("val") == y.get("val"):
                continue
            if STACK_LO <= y["val"] < STACK_HI or OURS <= y["val"] < OURS + OURS_SIZE:
                continue        # (an address in one side's own frame or code: the other side's differs)
            ov, pt = dict(overlay0 or {}), dict(patch0 or {})
            if _int_plant_into(x["src"], y["val"], ov, pt, nstack):
                out.append((ov, pt))
    return out


def _fxf_exact_tie(fxf, want, src):
    """(round 12, ftie) Does the value _invert_fxf plants come back as exactly `want` through fxf (in the loaded
    word's precision, then as the x87 computes, in doubles here)?"""
    v = _invert_fxf(fxf, want) if fxf else want
    if v is None:
        return False
    if src[1] == 4:
        v = struct.unpack("<f", struct.pack("<f", v))[0] if abs(v) <= 3.4028234663852886e38 else None
        if v is None:
            return False
    w = v
    for m, c in fxf:
        if m == "fadd":
            w = w + c
        elif m == "fsub":
            w = w - c
        elif m == "fsubr":
            w = c - w
        elif m == "fmul":
            w = w * c
        elif m == "fchs":
            w = -w
        elif m == "fdiv" and c:
            w = w / c
        elif m == "fdivr" and w:
            w = c / w
        elif m == "fabs":
            w = abs(w)
        else:
            return False
    return w == want


def _invert_xf(xf, raw, want):
    """A loaded value that the transforms xf turn into `want` (bits xf drops are kept from raw)."""
    pres = [raw or 0]
    for op in xf:
        pres.append(_apply_xf(op, pres[-1]))
    w = want & M32
    for op, pre in zip(reversed(xf), reversed(pres[:-1])):
        k = op[0]
        if k == "add":
            w = (w - op[1]) & M32
        elif k == "addp":
            # an address computed from a pointer (`lea ecx, [ebx + 0xb4]`): a pointer that wraps around to
            # reach the wanted address (`this + 0xb4 == 0`) isn't a real input
            d = op[1] - (1 << 32) if op[1] & 0x80000000 else op[1]
            w0 = w - d
            if not 0 <= w0 <= M32:
                return None
            w = w0
        elif k in ("shr", "sar"):
            w = ((w << op[1]) | (pre & ((1 << op[1]) - 1))) & M32
        elif k == "shl":
            w = (w >> op[1]) | (pre & ~(M32 >> op[1]) & M32)
        elif k == "and":
            w = ((pre & ~op[1]) | (w & op[1])) & M32
        elif k == "neg":
            w = (-w) & M32
        elif k == "not":
            w = ~w & M32
        elif k == "mulhi" and op[1]:
            m_ = _sx(op[1])
            w = (-((-(_sx(w) << 32)) // m_)) & M32          # ceil(w * 2^32 / M)
        elif k in ("sdiv", "udiv"):
            w = (_sx(w) * op[1]) & M32
        elif k == "btab":
            tab = Program.get().read(op[1], 256)
            w = tab.index(w & 0xFF) if (w & 0xFF) in tab and w < 256 else pre
    return w


def _plants(sob, overlay0, patch0):
    """Inputs that write a compared literal over the other operand's buffer: the literal with its
    terminator (an exact match), and without it (a longer string that starts with it: prefix compares).
    A heap or global buffer is planted in the memory epoch it was read in (split per page); a stack buffer
    that a stub filled gets the literal as that stub's fill."""
    lit, buf, fills = sob["lit"], sob["buf"], sob["fills"]
    variants = [lit] + ([lit[:-1]] if lit.endswith(b"\0") and len(lit) > 2 else [])
    out = []
    for v in variants:
        ov, pt = dict(overlay0 or {}), dict(patch0 or {})
        if sob.get("psrc") is not None and buf < NULL_HI:
            # (strnull) the buffer pointer is a null-page value the code loaded (an argv entry nobody
            # filled): point its source at an object-sized heap slot that holds the literal
            depth = sum(1 for k_ in ov if k_[0] == "*" and isinstance(k_[1], int) and
                        OBJ_BASE <= k_[1] < OBJ_BASE + OBJ_SIZE * OBJ_DEPTH)
            if depth >= OBJ_DEPTH:
                continue
            obj = OBJ_BASE + OBJ_SIZE * depth
            if not _int_plant_into(sob["psrc"], obj, ov, pt, sob.get("nstack", 16)):
                continue
            ov[("*", obj)] = v if v.endswith(b"\0") else v + b"~"
            out.append((ov, pt))
            continue
        if fills:
            ok = True
            for w in range(buf & ~3, buf + len(v), 4):
                lo, hi = max(buf, w), min(w + 4, buf + len(v))
                if w not in fills:
                    ok = False
                    break
                pt[("fill",) + tuple(fills[w]) + (lo - w, hi - lo)] = int.from_bytes(v[lo - buf:hi - buf], "little")
            if not ok:
                continue
        else:
            a, rest = buf, v
            while rest:
                take = min(len(rest), PAGE - (a & (PAGE - 1)))
                ov[(sob["epoch"], a)] = rest[:take]
                a, rest = a + take, rest[take:]
        out.append((ov, pt))
    return out


def _walk_side(ob):
    """(round 10, walkend) The operand of a runaway loop's compare that holds the sentinel a walk waits for: one side a
    pointer that stayed fixed over two rounds, the other a link loaded from memory that moved (`cmp eax, ecx` with
    ecx = &tree.nil); "zero" for `test r, r` on a loaded link that moved (a list ending at null). None otherwise."""
    nx = ob.get("next")
    o1 = ob.get("ops") or ()
    if nx is None or len(o1) != 2 or len(nx.get("ops") or ()) != 2:
        return None
    o2 = nx["ops"]
    if ob.get("mnemonic") == "test" and o1[1].get("same"):
        s1, s2 = o1[0].get("src"), o2[0].get("src")
        v1, v2 = o1[0].get("val"), o2[0].get("val")
        if s1 and s2 and isinstance(s1[0], int) and isinstance(s2[0], int) and not o1[0].get("xf") and \
                isinstance(v1, int) and (v1 != v2 or (s1[0] == s2[0] and "walkheads" not in EQUIV_OFF)) and \
                HEAP <= v1 < HEAP + HEAP_SIZE:
            return "zero"
        return None
    if ob.get("mnemonic") != "cmp":
        return None
    for k in (0, 1):
        v = o1[k].get("val")
        if v is None or o1[k].get("imm") is not None or not isinstance(v, int) or not (
                HEAP <= v < HEAP + HEAP_SIZE or STACK_LO <= v < STACK_HI or IMAGE_LO <= v < IMAGE_HI or
                # (round 11) a list head in an object a fuzzed null-ish pointer put in the zero page (`&heap->bins[i]`
                # with heap = 0): its links read 0 until planted
                (0 < v < NULL_HI and o1[k].get("src") is not None and "walkheads" not in EQUIV_OFF) or
                # (round 14, walkaddr) `&tree.nil` computed by `lea edx, [esi + 0x3c]` from a fuzzed owner pointer: an
                # address wherever the fuzzed pointer points (0x8236..., past the heap), still what the walk waits for
                (v > NULL_HI and o1[k].get("src") is not None and any(x[0] == "addp" for x in o1[k].get("xf") or ()) and
                 "walkaddr" not in EQUIV_OFF)):
            continue
        ln1, ln2 = o1[1 - k], o2[1 - k]
        if v == o2[k].get("val") and ln1.get("src") and isinstance(ln1["src"][0], int) and not ln1.get("xf") and \
                (ln1.get("val") != ln2.get("val") or (
                    # (round 11) a node linked to itself (`c->next == c`: in the null page every link is 0) moves no more
                    "walkheads" not in EQUIV_OFF and ln2.get("src") and ln1["src"][0] == ln2["src"][0] and
                    ln1.get("val") != v)):
            return k
    return None


def _walk_sentinels(obs_run, jcc_count):
    """Values a runaway loop's hottest compares held fixed while the other side moved (`cmp eax, edx` with
    edx = &tree.nil and eax the next link): what a list or tree walk is waiting for."""
    out = []
    for j, _ in jcc_count.most_common(16):
        ob = obs_run.get(j)
        if ob is None or ob.get("mnemonic") != "cmp" or ob.get("next") is None:
            continue
        o1, o2 = ob["ops"], ob["next"]["ops"]
        if len(o1) != 2 or len(o2) != 2:
            continue
        for k in (0, 1):
            v = o1[k].get("val")
            if v is None or o1[k].get("imm") is not None or not isinstance(v, int) or not (
                    HEAP <= v < HEAP + HEAP_SIZE or STACK_LO <= v < STACK_HI or IMAGE_LO <= v < IMAGE_HI):
                continue        # (a pointer: what a walk waits for is a node address, not a count)
            # (the other side moved, or is stuck on a node that links to itself: `[0] == 0` on the null page,
            # or a planted sentinel of another tree)
            if v == o2[k].get("val") and o1[1 - k].get("src") is not None and v not in out and \
                    o2[1 - k].get("val") != v:
                out.append(v)
    return tuple(out[:4])


def _int_plant_into(src, v, ov, pt, nstack):
    """(round 9) Make the integer input src = (where, size, epoch) hold v, in place in a directed input's overlay
    and patch. False if it can't be planted."""
    ea, size, epoch = src
    if isinstance(ea, tuple):
        if ea[0] in ("ret", "fill", "pfill"):
            pt[ea] = v & M32
            return True
        return False
    if ENTRY_ESP + 4 <= ea < ENTRY_ESP + 4 + 4 * nstack and size == 4 and (ea - ENTRY_ESP - 4) % 4 == 0:
        pt[(ea - ENTRY_ESP - 4) // 4] = v & M32
        return True
    if not (STACK_LO <= ea < STACK_HI) and not _reserved(ea) and _patchable(ea, False):
        ov[(epoch, ea)] = (v & ((1 << (8 * size)) - 1)).to_bytes(size, "little")
        return True
    return False


def _via_key(j, ob):
    """(round 9) A compare and the compares that decided the constants it tests."""
    return (j,) + tuple(o["via"].get("addr") for o in ob.get("ops") or () if o and isinstance(o.get("via"), dict))


def _obs_shape(ob):
    """(round 9) What a compare observation steers through, without the addresses: per operand the kind of
    source, its transforms and the compare a constant came from."""
    out = []
    for o in ob.get("ops") or ():
        if not o:
            out.append(None)
            continue
        src = o.get("src")
        kind = None if src is None else (src[0][0] if isinstance(src[0], tuple) else
                                         "stack" if STACK_LO <= src[0] < STACK_HI else "mem")
        via = o.get("via")
        out.append((kind, tuple(x[0] for x in (o.get("xf") or ())), tuple(x[0] for x in (o.get("fxf") or ())),
                    via.get("addr") if isinstance(via, dict) else None, o.get("eq") is not None))
    return tuple(out)


def _ov_plants(plants):
    """(round 10) The memory words of small-count plants (their stack-argument plants go in the patch)."""
    return {k: v for k, v in plants.items() if k[0] != "stack"}


def _pt_plants(patch0, plants):
    """(round 10) A patch with the stack-argument words of small-count plants."""
    st = {k[1]: v for k, v in plants.items() if k[0] == "stack"}
    if not st:
        return patch0
    out = dict(patch0 or {})
    out.update(st)
    return out


_FIELD_OPS = ("and", "shr", "sar", "add", "btab")


def _word_models(observations, wreads=None, insns=None):
    """(round 11, opwords) Words a loop decodes into fields (an interpreter's instruction words: `op = i & 0x3f;
    a = i >> 24; b = (i >> 15) & 0x1ff`, each field checked against limits before a switch on op): for each load
    whose word at least three compares test through different field extractions, {extraction: values worth
    planting} (the values each compare's other side gives: up to a small bound, around a constant, below a value
    read from memory; every case of a switch) and the inputs that reached those compares, with the address each
    word was read at (and the next round's, for the stride). {load pc: (fields, [(seed, overlay, patch, address,
    next address)])}."""
    by_pc = defaultdict(lambda: defaultdict(set))
    bases = defaultdict(list)
    reads = defaultdict(set)        # input -> (load pc, address, transforms, value) of the words its compares read
    for j, lst in observations.items():
        for seed0, ob, ov0, sp0 in lst:
            ops = ob.get("ops") or ()
            for k, o_ in enumerate(ops):
                src = o_.get("src")
                xf = tuple(o_.get("xf") or ())
                if src and isinstance(src[0], int) and src[1] == 4 and o_.get("pc") and isinstance(o_.get("val"), int):
                    reads[(seed0, repr(ov0), repr(sp0))].add((o_["pc"], src[0], xf, o_["val"]))
                if not src or not isinstance(src[0], int) or src[1] != 4 or not o_.get("pc") or not xf or \
                        not all(x[0] in _FIELD_OPS for x in xf) or not any(x[0] in ("and", "shr", "sar") for x in xf):
                    continue
                cands = by_pc[o_["pc"]][xf]
                other = ops[1 - k] if len(ops) == 2 else None
                if ob.get("mnemonic") == "table":
                    cands.update(range(len(ob.get("cases") or ())))
                elif other is not None and other.get("same"):
                    pass
                elif other is not None and other.get("imm") is not None:
                    c = other["imm"] & M32
                    if _sx(c) <= 64:
                        cands.update(range(0, max(0, _sx(c)) + 2))
                    else:
                        cands.update({(c - 1) & M32, c, (c + 1) & M32})
                elif other is not None and isinstance(other.get("val"), int):
                    v = other["val"] & M32
                    cands.update({0, 1, (v - 1) & M32 if v else 0, v})
                cands.update((0, 1, 2, 3))
                nx = (ob.get("next") or {}).get("ops") or ()
                ea2 = nx[k]["src"][0] if k < len(nx) and nx[k].get("src") and isinstance(nx[k]["src"][0], int) and \
                    nx[k].get("pc") == o_["pc"] else None
                if len(bases[o_["pc"]]) < 256:
                    bases[o_["pc"]].append((seed0, ov0, sp0, src[0], ea2))
    out = {}
    for pc, f in by_pc.items():
        # (a decoded instruction stream: a switch on one field or four fields, of a word read from an array by index,
        # `mov eax, [edx + eax*4]`. Not a flags word tested with three masks)
        tabled = any(x[-1][0] == "btab" for x in f) or len(f) >= 4
        li = (insns or {}).get(pc)
        stepped = li is not None and li.mem is not None and li.mem[2] is not None and li.mem[3] == 4
        if len(f) < 3 or not bases[pc] or not tabled or not stepped:
            continue
        bl = []
        # every completed input whose compares read words at this load is a base (diverse stub results, sizes and
        # limits), not just the few kept per compare; the first word it read there starts the run
        for (seed0, _, _), (wr_, wb_, ov0, sp0) in sorted((wreads or {}).items(), key=lambda kv: kv[0][0]):
            at = sorted(a for p_, a, _, _ in wr_ if p_ == pc)
            if at and len(bl) < 512:
                # (a word of the run that another load's compare read in the same input, `code[sizecode - 1] & 0x3f
                # == RETURN` before the loop, keeps the field value that compare saw: the input got past it)
                keep = sorted((a, x, v) for p_, a, x, v in wr_ if p_ != pc)
                bl.append((seed0, ov0, sp0, at[0], at[1] if len(at) > 1 else None, keep, wb_))
        if not bl:
            bl = [b + ((), ()) for b in bases[pc]]
        out[pc] = (dict(f), bl)
    return out


def _word_plant(fields, base, stride, n, rnd, keep=()):
    """(round 11, opwords) n words from `base` on, each made of a random choice of field values (every memory
    epoch alike: the loop re-reads its words after each call). keep: (address, transforms, value) that other
    compares need to keep seeing."""
    ov = {}
    items = sorted(fields.items(), key=lambda f: repr(f[0]))
    for k in range(n):
        raw = rnd.getrandbits(32) if rnd.random() < 0.5 else 0
        order = items[:]
        rnd.shuffle(order)
        if rnd.random() < 0.5:
            order.sort(key=lambda f: len(f[1]))      # (the field with most values, the opcode, last: it stays)
        for xf, cands in order:
            if rnd.random() < 0.25:
                continue
            want = rnd.choice(sorted(cands))
            r2 = _invert_xf(xf, raw, want)
            if r2 is None:
                continue
            v = r2
            for op in xf:
                v = _apply_xf(op, v)
            if v == want & M32:
                raw = r2 & M32
        a = (base + stride * k) & M32
        for a_, xf, val in keep:
            if a_ == a:
                r2 = _invert_xf(xf, raw, val)
                raw = r2 & M32 if r2 is not None else raw
        ov[("*", a)] = struct.pack("<I", raw)
    return ov


def _merge_ov(a, b):
    """Two directed overlays, the second one's words winning."""
    out = dict(a or {})
    out.update(b or {})
    return out


def _char_adjust(xf):
    """(round 9) The constant a loaded char's transforms add (only adds and byte masks), or None."""
    adj = 0
    for op in xf or ():
        if op[0] == "add":
            adj += op[1]
        elif op[0] == "and" and op[1] in (0xFF, 0xFFFF):
            continue
        else:
            return None
    return adj & M32


def _obs_steerable(ob, via=True):
    """(round 9) Does a compare observation have an operand with an input source (not code, not a constant)?"""
    for o in ob.get("ops") or ():
        src = o.get("src") if o else None
        if src is None:
            if via and o and o.get("via") is not None:
                return True
            continue
        if not isinstance(src[0], int) or (_patchable(src[0], o.get("abs", True)) and not _reserved(src[0])):
            return True
    return False


def _patchable(ea, absolute=True):
    """May a directed input change this memory? Never code (a switch's byte table: ours has its own), nor
    a float constant read at a fixed address in read-only data (ours may load the same value from its own
    constant, or as fld1/fldz). Data reached through a pointer is fine."""
    prog = Program.get()
    if absolute and IMAGE_LO <= ea < IMAGE_HI and getattr(prog, "ours_data", None) is not None and \
            "ourglobal" not in EQUIV_OFF and not any(g <= ea < g + 0x100 for g in prog.ours_data):
        return False
    return not prog.is_code(ea) and not (absolute and prog.section_name(ea) == ".rdata")


def _float_plant(x, fv, overlay0, patch0, nstack):
    """(round 9) The input that makes the float source of x hold fv: a stub's float result, a word a stub
    filled, or a float in memory or a stack argument (through a masked integer copy, ixf). None if there
    is no such input."""
    src = x["src"]
    if isinstance(src[0], tuple) and src[0][0] == "fret":
        patch = dict(patch0 or {})
        patch[src[0]] = fv
        return dict(overlay0 or {}), patch
    if not abs(fv) <= 3.4028234663852886e38 and src[1] != 8:
        return None             # (no 4-byte form)
    if isinstance(src[0], tuple) and src[0][0] == "fill":
        patch = dict(patch0 or {})
        patch[src[0]] = f32bits(fv)
        return dict(overlay0 or {}), patch
    ea_ = src[0]
    if not isinstance(ea_, int) or src[1] not in (4, 8) or not _patchable(ea_, x.get("abs", True)):
        return None
    bits = f32bits(fv) if src[1] == 4 else None
    if x.get("ixf") and bits is not None:
        bits = _invert_xf(x["ixf"], x.get("raw"), bits)     # (`and eax, 0x7fffffff`: fabs)
        if bits is None:
            return None
    ov = dict(overlay0 or {})
    if STACK_LO <= ea_ < STACK_HI:
        if not (ENTRY_ESP + 4 <= ea_ < ENTRY_ESP + 4 + 4 * nstack and src[1] == 4):
            return None
        patch = dict(patch0 or {})
        patch[(ea_ - ENTRY_ESP - 4) // 4] = bits
        return ov, patch
    ov[(src[2], ea_)] = struct.pack("<I", bits) if bits is not None else struct.pack("<d", fv)
    return ov, dict(patch0 or {})


def _patches_fcmp_r8(ob, overlay0, patch0, nstack):
    """Round 8's float-compare patches (EQUIV_OFF=fprov)."""
    ops = ob["ops"]
    out = []
    # a float comparison: move one side to just above, equal to, or just below the other
    for x, y in ((ops[0], ops[1]), (ops[1], ops[0])):
        if x.get("src") and y.get("val") is not None and isinstance(x["src"][0], tuple) \
                and x["src"][0][0] == "fill":
            # a float word a stub filled (round 7)
            yv = y["val"]
            if math.isnan(yv) or math.isinf(yv):
                continue
            d = max(1.0, abs(yv) * 0.5)
            for fv in ((yv + d, yv, yv - d) if y.get("src") else (yv + d, yv - d)):
                if not abs(fv) <= 3.4028234663852886e38:
                    continue
                patch = dict(patch0 or {})
                patch[x["src"][0]] = f32bits(fv)
                out.append((dict(overlay0 or {}), patch))
            continue
        if x.get("src") and y.get("val") is not None and isinstance(x["src"][0], tuple) \
                and x["src"][0][0] == "fret":
            yv = y["val"]
            if math.isnan(yv) or math.isinf(yv):
                continue
            d = max(1.0, abs(yv) * 0.5)
            # (exactly equal only to a plain loaded value: against a computed one, a tie depends on
            # the x87 precision each side computes it in)
            for fv in ((yv + d, yv, yv - d) if y.get("src") else (yv + d, yv - d)):
                patch = dict(patch0 or {})
                patch[x["src"][0]] = fv
                out.append((dict(overlay0 or {}), patch))
            continue
        if x.get("src") and y.get("val") is not None and isinstance(ea_ := x["src"][0], int) \
                and x["src"][1] in (4, 8) and _patchable(ea_, x.get("abs", True)):
            yv = y["val"]
            if math.isnan(yv) or math.isinf(yv):
                continue
            d = max(1.0, abs(yv) * 0.5)
            # (exactly equal only to a plain loaded value: against a computed one, a tie depends on
            # the x87 precision each side computes it in)
            for fv in ((yv + d, yv, yv - d) if y.get("src") and not x.get("fxf") else (yv + d, yv - d)):
                if x.get("fxf"):
                    fv = _invert_fxf(x["fxf"], fv)
                    if fv is None:
                        continue
                if x["src"][1] == 4 and not abs(fv) <= 3.4028234663852886e38:
                    continue    # (round 7: a value past float range has no 4-byte form: skip, don't crash)
                bits = f32bits(fv) if x["src"][1] == 4 else None
                if x.get("ixf") and bits is not None:
                    bits = _invert_xf(x["ixf"], x.get("raw"), bits)     # (`and eax, 0x7fffffff`: fabs)
                    if bits is None:
                        continue
                ov = dict(overlay0 or {})
                if STACK_LO <= ea_ < STACK_HI:
                    if not (ENTRY_ESP + 4 <= ea_ < ENTRY_ESP + 4 + 4 * nstack and x["src"][1] == 4):
                        continue
                    patch = dict(patch0 or {})
                    patch[(ea_ - ENTRY_ESP - 4) // 4] = bits
                    out.append((ov, patch))
                    continue
                ov[(x["src"][2], ea_)] = struct.pack("<I", bits) if bits is not None else struct.pack("<d", fv)
                out.append((ov, dict(patch0 or {})))
    if not out and any(o.get("src") is None for o in ops):
        # a value computed from stub results (sqrt of a difference of two stub-filled vectors, a scaled
        # and clamped result): no single word to invert. Make every stub float alike instead: all 0
        # (equal vectors: distance 0), +1/-1 by call (opposite vectors: a negative dot product), all large
        for fv in (0.0, ("alt", 1.0), 1000.0, 1.0):
            patch = dict(patch0 or {})
            patch[("stubfloats",)] = fv
            out.append((dict(overlay0 or {}), patch))
    return out[:6]


def _patches(ob, overlay0, patch0, nstack, depth=0, via=False):
    """Memory/argument patches that would send a comparison the other way (input-to-state).

    With a second observation of the same comparison (a loop's next iteration), the operand that moved
    gives the loop's step, and the other one is patched to end the loop after one or two iterations."""
    ops = ob["ops"]
    out = []
    nxt = ob.get("next")

    def wants(other_val, size):
        m = (1 << (8 * size)) - 1
        return [other_val & m, (other_val + 1) & m, (other_val - 1) & m]

    targets = []
    if ob["mnemonic"] == "fcmp":
        if "fprov" in EQUIV_OFF:
            return _patches_fcmp_r8(ob, overlay0, patch0, nstack)
        # a float comparison: move one side to just above, equal to, or just below the other
        for x, y in ((ops[0], ops[1]), (ops[1], ops[0])):
            src = x.get("src")
            yv = y.get("val")
            if not src or yv is None or math.isnan(yv) or math.isinf(yv):
                continue
            fxf = tuple(x.get("fxf") or ())
            d = max(1.0, abs(yv) * 0.5)
            # (exactly equal only to a plain loaded value: against a computed one, a tie depends on the x87
            # precision each side computes it in)
            tie = bool(y.get("src")) and not fxf
            if not tie and fxf and y.get("src") and "ftie" not in EQUIV_OFF and _fxf_exact_tie(fxf, yv, src):
                # (round 12, ftie) a transformed load against another input (`fabs(m[0][0]) > eps`): a tie when the
                # transform maps the planted value onto the other one exactly (fabs, fchs, or checked forward)
                tie = True
            fvs = [yv + d, yv, yv - d] if tie else [yv + d, yv - d]
            if yv:
                # (round 9) |x - c| < eps against a small eps: +-1 lands on the far side both times; halfway and
                # one and a half times the other value don't (first when a fabs makes negatives unreachable)
                sc = [yv * 0.5, yv * 1.5]
                fvs = (sc + fvs) if any(t[0] == "fabs" for t in fxf) else (fvs + sc)
            for fv in fvs:
                bv = _invert_fxf(fxf, fv) if fxf else fv
                if bv is None:
                    continue
                pl = _float_plant(x, bv, overlay0, patch0, nstack)
                if pl is not None:
                    out.append(pl)
        if not out and any(o.get("src") is None for o in ops):
            # a value computed from stub results (sqrt of a difference of two stub-filled vectors, a scaled
            # and clamped result): no single word to invert. Make every stub float alike instead: all 0
            # (equal vectors: distance 0), +1/-1 by call (opposite vectors: a negative dot product), all large
            for fv in (0.0, ("alt", 1.0), 1000.0, 1.0):
                patch = dict(patch0 or {})
                patch[("stubfloats",)] = fv
                out.append((dict(overlay0 or {}), patch))
            fl = ob.get("floads")
            if fl:
                # (round 9, memfloats) ... or computed from floats in memory (`|sqrt(x*x + y*y + z*z) - 1| < eps`
                # on a matrix's rows): plant them all alike, as an identity matrix (1 every fifth word from the
                # lowest of a cluster: unit, orthogonal rows), all 1 and all 0
                mem = []
                for mode in ("ident", 1.0, 0.0):
                    ov = dict(overlay0 or {})
                    base = None
                    for ep, ea, sz in sorted(fl, key=lambda x: x[1]):
                        if base is None or ea - base >= 0x40:
                            base = ea
                        v = (1.0 if (ea - base) // 4 % 5 == 0 else 0.0) if mode == "ident" else mode
                        ov[(ep, ea)] = struct.pack("<f" if sz == 4 else "<d", v)
                    mem.append((ov, dict(patch0 or {})))
                out = out + mem if ob.get("stubs") else mem
        return out[:6]
    if ob["mnemonic"] == "table":
        a = ob["ops"][0]
        if a["src"]:
            want = ob.get("want_cases") or range(len(ob["cases"]))
            targets.append((a, list(want)))
    elif ob["mnemonic"] == "test":
        a = ops[0]
        b = ops[1] if len(ops) > 1 else ops[0]
        if a["src"] and (b["src"] == a["src"] or b.get("same")):
            # (-1 too: `test eax, eax; jge` / `js` branch on the sign, which 0 and 1 never flip)
            targets.append((a, [0, M32, a["val"] ^ 1, 1]))
        elif a["src"] and b.get("imm") is not None:
            targets.append((a, [0, b["val"]]))
    else:
        if len(ops) == 2:
            a, b = ops
            for x, y, i in ((a, b, 1), (b, a, 0)):
                if not x["src"]:
                    continue
                vals = wants(y["val"], x["src"][1])
                if nxt is not None and len(nxt["ops"]) == 2 and nxt["ops"][1 - i].get("src") == x["src"]:
                    step = (nxt["ops"][i]["val"] - y["val"]) & M32
                    if step and step != M32 and (step < 0x10000 or step > M32 - 0x10000):
                        # y is the loop's induction variable: end the loop after one or two more rounds
                        vals = [(y["val"] + step) & M32, y["val"], (y["val"] + 2 * step) & M32] + vals
                targets.append((x, vals))
    per_target = []
    for x, vals in targets:
        out = []
        per_target.append(out)
        ea, size, epoch = x["src"]
        xf = x.get("xf") or ()
        # the bound is re-read after a call (a new memory epoch every round): patch it in every epoch
        anyep = nxt is not None and any(o.get("src") and o["src"][0] == ea and o["src"][2] != epoch
                                        for o in nxt["ops"])
        for v in vals:
            if xf:
                v = _invert_xf(xf, x.get("raw"), v)
                if v is None:
                    continue
            n_before = len(out)
            if x.get("eq") is not None and "eqlink" not in EQUIV_OFF:
                # (round 9, eqlink) this input was found equal to another one earlier in the run: move both
                eqp = (x["eq"], v)
            else:
                eqp = None
            if isinstance(ea, tuple) and ea[0] == "ftol":
                # (round 9) an integer converted from a steerable float by __ftol2 (truncation): plant a float
                # half a unit past the wanted integer, through the float's own source and transforms
                _, fsrc, fxf, ixf, fraw, fabs_ = ea
                w_ = _sx(v)
                fv = w_ + 0.5 if w_ >= 0 else w_ - 0.5
                if fxf:
                    fv = _invert_fxf(fxf, fv)
                if fv is not None:
                    pl = _float_plant({"src": fsrc, "ixf": ixf, "raw": fraw, "abs": fabs_}, fv, overlay0, patch0, nstack)
                    if pl is not None:
                        out.append(pl)
            elif isinstance(ea, tuple):            # the value a stubbed callee returned: return another
                patch = dict(patch0 or {})
                patch[ea] = v & M32
                out.append((dict(overlay0 or {}), patch))
            elif ENTRY_ESP + 4 <= ea < ENTRY_ESP + 4 + 4 * nstack and size == 4 and (ea - ENTRY_ESP - 4) % 4 == 0:
                patch = dict(patch0 or {})
                patch[(ea - ENTRY_ESP - 4) // 4] = v & M32
                out.append((dict(overlay0 or {}), patch))
            elif ENTRY_ESP + 4 <= ea < ENTRY_ESP + 4 + 4 * nstack and size in (1, 2) and \
                    ((ea - ENTRY_ESP - 4) % 4) + size <= 4 and "sbyte" not in EQUIV_OFF:
                # (round 7) a byte or word of a stack argument (a type char at +0x2b0 of a struct passed by value)
                patch = dict(patch0 or {})
                patch[("sbyte", (ea - ENTRY_ESP - 4) // 4, (ea - ENTRY_ESP - 4) % 4, size)] = \
                    v & ((1 << (8 * size)) - 1)
                out.append((dict(overlay0 or {}), patch))
            elif not (STACK_LO <= ea < STACK_HI) and not _reserved(ea) and _patchable(ea, False):
                # (never code: a jump table inside .text is the original's alone; ours has its own)
                ov = dict(overlay0 or {})
                ov[("*" if anyep else epoch, ea)] = (v & ((1 << (8 * size)) - 1)).to_bytes(size, "little")
                out.append((ov, dict(patch0 or {})))
                if anyep and "after" not in EQUIV_OFF:
                    # (and only from the next epoch on: the loop runs once, a teardown `while (t->first !=
                    # head) erase(t->first)` whose stubbed erase never unlinks)
                    ov = dict(overlay0 or {})
                    ov[(("after", epoch), ea)] = (v & ((1 << (8 * size)) - 1)).to_bytes(size, "little")
                    out.insert(len(out) - 1, (ov, dict(patch0 or {})))
            if eqp is not None:
                for k_ in range(n_before, len(out)):
                    ov_, pt_ = dict(out[k_][0]), dict(out[k_][1])
                    if _int_plant_into(eqp[0], eqp[1], ov_, pt_, nstack):
                        out.append((ov_, pt_))      # (both moved; the single one stays too)
    if via and not any(per_target) and depth < 4 and "via" not in EQUIV_OFF:
        # (round 9, via) an operand with no source of its own that holds a constant a compare decided (`mov bl,
        # 1` after `cmp eax, [g]; jne`, a setcc's result): the patches of that compare, from the same run
        for o in ops:
            if not o.get("src") and o.get("via") is not None and o.get("imm") is None:
                per_target.append(_patches(o["via"], overlay0, patch0, nstack, depth + 1, via=True))
                break
    # distinct patches only, alternating between the operands (one of them may be memory the function
    # wrote itself, where a patch does nothing)
    out = [x for grp in itertools.zip_longest(*per_target) for x in grp if x is not None]
    seen, uniq = set(), []
    for ov, pt in out:
        key = (tuple(sorted(map(repr, ov.items()))), tuple(sorted(map(repr, pt.items()))))
        if key not in seen:
            seen.add(key)
            uniq.append((ov, pt))
    return uniq[:8]


# ---------------------------------------------------------------------------------------------
def render(rep):
    lvl = "level %d" % rep["level"]
    if rep["status"] == "fail" and rep.get("failed_levels"):
        # (round 9) `level` is the highest level passed: say which level failed (a level-3 mismatch read as
        # "FAIL ... level 2" looked like a level-2 problem)
        lvl = "fails level %s (passes level %d)" % (" and ".join(map(str, rep["failed_levels"])), rep["level"])
    lines = ["%s  %s vs %s (%s)  %s" % (rep["status"].upper(), rep.get("symbol", "?"), rep["target"],
                                        rep["addr"], lvl)]
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
        if rep.get("inconclusive"):
            lines.append("  L3 inconclusive: " + rep["inconclusive"])
        if rep.get("promotable_note"):
            lines.append("  not promotable (thin evidence): " + rep["promotable_note"])
        for m in l3["mismatches"][:3]:
            for d in m["diffs"]:
                lines.append("  L3 input %s: %s" % (m["input"], d))
        if cov["uncovered"]:
            lines.append("  never reached: " + ", ".join(cov["uncovered"][:8]))
        if cov.get("declared_dead"):
            lines.append("  declared dead (equiv-dead, not counted): " + ", ".join(cov["declared_dead"][:8]))
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
    p.add_argument("--time-budget", type=float, default=120,
                   help="level-3 CPU seconds (x3 under long step budgets); slow functions need more to reach 50 inputs")
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
                 mapping=mapping, max_level=a.level, max_steps=a.steps, use_names=not a.no_names, clang=a.clang,
                 time_budget=a.time_budget)
    print(json.dumps(rep, default=str) if a.json else render(rep))
    return 0 if rep["status"] == "equivalent" else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
