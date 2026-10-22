#!/usr/bin/env python3
"""x87 operation-order check (cl7): is a source's float arithmetic grouped like the original's, natively?

  build/venv/bin/python tools/x87_order.py SRC.cpp [0xADDR] [--json] [--no-msvc] [--show]
  build/venv/bin/python tools/x87_order.py --list FILE [--jobs 4] [--out build/cl7/findings.jsonl]

MSVC 7.1 reassociates float sums and products and turns x/W into x*(1/W); clang (the native build) evaluates in
source order. A source can byte-match, or be proven equivalent, and still compute `(a+b)+c` where the original
computes `a+(b+c)`: at 53-bit precision both usually round to the same float, so random inputs rarely tell.

The tool symbolically executes the x87 code of
  (a) the original function (the XBE),
  (b) the source compiled the way the native build does (tools/equiv.py compile_native: clang, i686, -O0,
      -ffp-eval-method=double -ffp-contract=off), and
  (c) the source's MSVC object (to tell "MSVC reassociated it" from "the source differs even under MSVC"),
into expression trees (loads of memory / arguments / constants, + - * /, neg, abs, sqrt, int conversions, float
stores). Roots are the trees stored to memory, returned in st(0), compared or converted to int. A root of (a) is
matched to a root of (b) by its multiset of leaves (a reassociation keeps the leaves); the two trees are then
compared modulo commutativity of + and * only. A difference is a finding:
  assoc   same leaves and operators, different grouping
  recip   x/y on one side, x*(1/y) on the other
  round   same tree but a rounding point (store to float, reload) on one side only (low priority: tools/x87_scan.py
          covers these)
  other   same leaves, different operators
Control flow: branches whose condition the constants decide are followed (a loop over a constant count is
unrolled); the others merge (a value that differs on the two paths becomes a phi). A loop of unknown trip count
is simulated once on the state it was entered with (its first iteration is a real iteration: its roots are
compared) and once more generically with what the body writes forgotten (those roots are counted, not compared).
A root with an unknown leaf is `unmatched`, never a finding; so is a root with several equally good counterparts.
--json also reports `unmatched_why` (a count per reason), `unmatched_roots` (the first dozen, with the nearest root
of the other side) and `orig_generic` (roots of generic loop iterations). See docs/equivalence.md ("x87 operation
order check (cl7)") for the limits.
"""
import argparse
import bisect
import difflib
import json
import os
import re
import struct
import sys
import tempfile
from collections import Counter

import capstone
from capstone import x86 as X

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xbe import Xbe  # noqa: E402

sys.setrecursionlimit(6000)

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
FUNCS_PATH = os.path.join(ROOT, "build/functions.csv")

# ---------------------------------------------------------------------------------------------
# Integer values: ("i", terms, const). terms: sorted tuple of atoms (hashable tuples); const: signed 32-bit.
# Atoms: ("r", reg) entry register, ("sp",) the entry esp, ("arg", off), ("m", addr, size) a loaded value,
# ("g", name) an unbound symbol, ("call", n), ("u", side, n) unknown.


def wrap(c):
    return ((c + 2 ** 31) % 2 ** 32) - 2 ** 31


def I(c=0):
    return ("i", (), wrap(c))


def atom(a):
    return ("i", (a,), 0)


def iadd(a, b):
    terms = list(a[1] + b[1])
    if a[1] and b[1]:       # x + -x cancels (a pointer difference added back to one of its ends)
        for x in list(terms):
            nx = x[1] if x[0] == "neg" else ("neg", x)
            if x in terms and nx in terms:
                terms.remove(x)
                terms.remove(nx)
    return ("i", tuple(sorted(terms, key=_sk)), wrap(a[2] + b[2]))


def ineg(b):
    return ("i", tuple(sorted((x[1] if x[0] == "neg" else ("neg", x) for x in b[1]), key=_sk)), wrap(-b[2]))


def iconst(v):
    return v[2] if not v[1] else None


def isub(a, b):
    if not b[1]:
        return ("i", a[1], wrap(a[2] - b[2]))
    if a == b:
        return I(0)
    return iadd(a, ineg(b))


def sp_off(v):
    """The entry-esp-relative offset when V is exactly sp+off."""
    if len(v[1]) == 1 and v[1][0][0] in ("sp", "sp2"):
        return v[2]
    return None


def is_entry_sp(v):
    return len(v[1]) == 1 and v[1][0] == ("sp",)


# ---------------------------------------------------------------------------------------------
# Float expression nodes: (op, size, children...) / leaves ("ld", 1, addr, bytes), ("c", 1, value),
# ("unk", 1, tag), ("call", 1, n), ("fild", 1, intval)
BIG = 1200
MAXSTEPS = 60000        # instructions per run before loops that were being unrolled are given up
MAXVISITS = 64          # times one loop head may be reached while unrolling
BUDGET = 200000         # instructions one run (the function and the helpers executed in place in it) may take
_cache = {}


def mk(op, *kids):
    # x + (-y) is x - y and -(-x) is x, exactly; a negated constant is a constant (clang adds -1.0 where MSVC subtracts 1.0)
    if op == "neg":
        k = kids[0]
        if k[0] == "neg":
            return k[2]
        if k[0] == "sub":       # -(a - b) = b - a exactly
            return mk("sub", k[3], k[2])
        if k[0] == "c":
            return ("c", 1, -k[2])
    elif op == "add":
        if kids[0][0] == "neg" and kids[1][0] == "neg":       # (-a) + (-b) = -(a + b) exactly
            return mk("neg", mk("add", kids[0][2], kids[1][2]))
        for i, k in enumerate(kids):
            if k[0] == "neg":
                return mk("sub", kids[1 - i], k[2])
            if k[0] == "c" and k[2] < 0 and kids[1 - i][0] != "c":
                return mk("sub", kids[1 - i], ("c", 1, -k[2]))
    elif op == "mul" and any(k[0] == "c" and k[2] in (1.0, -1.0) for k in kids) and not all(k[0] == "c" for k in kids):
        for i, k in enumerate(kids):        # x * 1 = x and x * -1 = -x exactly
            if k[0] == "c" and k[2] in (1.0, -1.0):
                return kids[1 - i] if k[2] == 1.0 else mk("neg", kids[1 - i])
    elif op in ("mul", "div"):      # a sign is exact: -a*b = -(a*b) = a*-b, -a/b = -(a/b) = a/-b
        for i, k in enumerate(kids):
            if k[0] == "neg" and (op == "mul" or True):
                other = list(kids)
                other[i] = k[2]
                return mk("neg", mk(op, *other))
    elif op == "sub":
        if kids[0][0] == "neg" and kids[1][0] != "neg":       # (-a) - b = -(a + b) exactly
            return mk("neg", mk("add", kids[0][2], kids[1]))
        if kids[1][0] == "neg":
            return mk("add", kids[0], kids[1][2])
        if kids[1][0] == "c" and kids[1][2] < 0 and kids[0][0] != "c":
            return mk("add", kids[0], ("c", 1, -kids[1][2]))
    if op == "phi":     # an n-ary set: nested phis flatten, order is the compiler's layout of the branches
        flatk = []
        for k in kids:
            flatk.extend(k[2:] if k[0] == "phi" else (k,))
        kids = sorted(set(flatk), key=_rk)
        if len(kids) == 1:
            return kids[0]
        if len(kids) == 2:      # an unsigned int converted: fild of the signed value, + 2^32 when negative
            for f, g in (kids, kids[::-1]):
                if f[0] == "fild" and g[0] == "add" and len(g) == 4 and f in g[2:] and \
                        any(k[0] == "c" and k[2] == 4294967296.0 for k in g[2:]):
                    return ("fild", 2, atom(("u32", f[2])))
    elif op in ("add", "mul", "cmp"):
        kids = tuple(sorted(kids, key=_rk))
    sz = 1 + sum(k[1] for k in kids)
    if sz > BIG:
        return ("unk", 1, ("big", id(kids)))
    return (op, sz) + tuple(kids)


_intern = {}
_kc = {}
_RKOPS = frozenset(("add", "sub", "mul", "div", "neg", "abs", "sqrt", "cmp", "phi", "rnd"))


def _sk(x):
    """The same for any nested tuple (integer-value atoms): structural interning, memoised by identity."""
    e = _kc.get(id(x))
    if e is not None and e[0] is x:
        return e[1]
    key = tuple(_sk(y) if isinstance(y, tuple) else y for y in x) if isinstance(x, tuple) else x
    r = _intern.setdefault(("s", key), len(_intern))
    _kc[id(x)] = (x, r)
    return r


def _rk(n):
    """A canonical sort key for a tree: an integer from a table shared by everything in this process (so both sides
    order commutative operands alike), built from the children's keys instead of from repr() of the whole tree."""
    e = _kc.get(id(n))
    if e is not None and e[0] is n:
        return e[1]
    t = n[0]
    if t in _RKOPS:
        key = (t,) + tuple(_rk(k) for k in n[2:])
    elif t == "fn":
        key = (t, n[2]) + tuple(_rk(k) for k in n[3:])
    else:
        r = _sk(n)
        _kc[id(n)] = (n, r)
        return r
    r = _intern.setdefault(key, len(_intern))
    _kc[id(n)] = (n, r)
    return r


def is_exact_float(n):
    if n[0] == "ld":
        return n[3] == 4
    if n[0] == "c":
        try:
            return struct.unpack("<f", struct.pack("<f", n[2]))[0] == n[2]
        except (OverflowError, struct.error):
            return False
    return n[0] in ("rnd", "cmp", "fbv")


def rnd(n):
    return n if is_exact_float(n) else ("rnd", 1 + n[1], n)


OPS = ("add", "sub", "mul", "div", "neg", "abs", "sqrt", "cmp", "phi")


def strip_rnd(n, memo=None):
    memo = {} if memo is None else memo
    if n in memo:
        return memo[n]
    if n[0] == "rnd":
        r = strip_rnd(n[2], memo)
    elif n[0] in OPS:
        r = mk(n[0], *[strip_rnd(k, memo) for k in n[2:]])
    elif n[0] == "fn":
        kids = tuple(strip_rnd(k, memo) for k in n[3:])
        r = ("fn", 1 + sum(k[1] for k in kids), n[2]) + kids
    else:
        r = n
    memo[n] = r
    return r


def leaves(n, out):
    t = n[0]
    if t in ("ld", "c", "unk", "call", "fild", "fbv"):
        out.append(n)
    elif t == "fn":
        out.append(("fnleaf", 1, n[2]))
        for k in n[3:]:
            leaves(k, out)
    else:
        for k in n[2:]:
            leaves(k, out)


def signature(n):
    out = []
    leaves(strip_rnd(n), out)
    if any(l[0] == "unk" for l in out):
        return None
    out = [l for l in out if not (l[0] == "c" and l[2] == 1.0)]     # x/y vs x*(1/y) differ by a 1.0
    return tuple(sorted(repr(l) for l in out))


def opcount(n):
    out = Counter()

    def go(m):
        if m[0] in OPS or m[0] == "fn":
            out[m[0] if m[0] != "fn" else "fn:" + m[2]] += 1
            for k in m[2 if m[0] != "fn" else 3:]:
                go(k)
    go(n)
    return out


def flat(n, nodiv=False):
    """Association-insensitive form: sums/products flattened. nodiv: x/y stays opaque (to tell recip from assoc)."""
    t = n[0]
    if t == "rnd":
        return flat(n[2], nodiv)
    if t in ("add", "sub", "neg"):
        terms = []

        def gather(m, sign):
            if m[0] == "add":
                gather(m[2], sign)
                gather(m[3], sign)
            elif m[0] == "sub":
                gather(m[2], sign)
                gather(m[3], -sign)
            elif m[0] == "neg":
                gather(m[2], -sign)
            elif m[0] == "rnd":
                gather(m[2], sign)
            else:
                terms.append((sign, flat(m, nodiv)))
        gather(n, 1)
        return ("sum", tuple(sorted(terms, key=_sk)))
    if t in ("mul", "div"):
        fs = []

        def gm(m, p):
            if m[0] == "mul":
                gm(m[2], p)
                gm(m[3], p)
            elif m[0] == "div" and not nodiv:
                gm(m[2], p)
                if m[2][0] == "c" and m[2][2] == 1.0 and False:
                    pass
                gm(m[3], -p)
            elif m[0] == "rnd":
                gm(m[2], p)
            else:
                fs.append((p, flat(m, nodiv) if m[0] != "div" else ("div", flat(m[2], nodiv), flat(m[3], nodiv))))
        gm(n, 1)
        # 1/y as a factor: (c 1.0, +1) * (y, -1) -> (y, -1)
        fs = [f for f in fs if not (f[0] == 1 and f[1][0] == "c" and f[1][2] == 1.0)] or fs
        return ("prod", tuple(sorted(fs, key=_sk)))
    if t in ("sqrt", "abs", "cvt"):
        return (t, flat(n[2], nodiv))
    if t in ("phi", "cmp"):
        return (t, tuple(sorted((flat(k, nodiv) for k in n[2:]), key=_sk)))
    if t == "fn":
        return ("fn", n[2]) + tuple(flat(k, nodiv) for k in n[3:])
    return n


def cvtatom(v):
    """The integer atom for float V converted to int: it names the converted value by its association-insensitive
    form, so an outer expression is not reported again for a difference inside the conversion (the conversion is
    a root of its own)."""
    import hashlib
    return atom(("cvt", hashlib.md5(repr(flat(strip_rnd(v))).encode()).hexdigest()[:10]))


# ---------------------------------------------------------------------------------------------
# Pretty printing
def addrstr(v):
    off = sp_off(v)
    if off is not None:
        return "a%d" % off if off > 0 else "local%d" % -off
    parts = [atomstr(a) for a in v[1]]
    c = v[2]
    if c or not parts:
        parts.append(("0x%x" % c) if c >= 0 else "-0x%x" % -c)
    return "[" + "+".join(parts).replace("+-", "-") + "]"


def callstr(cid):
    if isinstance(cid[0], tuple):
        return "(edx)"
    k = cid[0]
    return "(%s#%d)" % ("0x%x" % k if isinstance(k, int) else str(k)[:24], cid[1])


def atomstr(a):
    t = a[0]
    if t == "cvt":
        return "int(" + a[1][:4] + ")"
    if t == "r":
        return "this" if a[1] == "ecx" else a[1] + "0"
    if t == "sp":
        return "sp"
    if t == "arg":
        return "a%d" % a[1]
    if t == "m":
        return "*" + addrstr(a[1])
    if t == "g":
        return a[1]
    if t == "u":
        return "u:" + (a[3] if len(a) > 3 else "?")
    if t == "cptr":
        return "out%s.%s" % (callstr(a[1]), a[2])
    if t == "call":
        return "call%s" % callstr(a[1])
    if t == "cvt":
        return "int(" + a[1] + ")"
    if t == "neg":
        return "-" + atomstr(a[1])
    if t == "iphi":
        return "phi"
    if t == "sub":
        return "(" + addrstr(a[1]) + "-" + addrstr(a[2]) + ")"
    return t


def show(n, top=True):
    t = n[0]
    if t == "ld":
        return addrstr(n[2]) + ("" if n[3] == 4 else "d")
    if t == "c":
        return "%g" % n[2]
    if t == "call":
        return "call%s()" % callstr(n[2])
    if t == "fbv":
        return "bits(%s)" % ",".join(atomstr(a) for a in n[2][1])
    if t == "fild":
        return "(float)" + atomstr(n[2][1][0]) if n[2][1] else "(float)%d" % n[2][2]
    if t == "unk":
        return "?" + (n[2][3][:8] if len(n[2]) > 3 and n[2][3] != "?" else "")
    if t == "rnd":
        return "f(" + show(n[2]) + ")"
    sym = {"add": "+", "sub": "-", "mul": "*", "div": "/"}
    if t in sym:
        s = show(n[2], False) + " " + sym[t] + " " + show(n[3], False)
        return s if top else "(" + s + ")"
    if t == "fn":
        return "%s(%s)" % (n[2], ", ".join(show(k) for k in n[3:]))
    return "%s(%s)" % (t, ", ".join(show(k) for k in n[2:]))


# ---------------------------------------------------------------------------------------------
REG32 = {}
for _r in ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"):
    REG32[_r] = _r
for _a, _b in (("eax", "a"), ("ebx", "b"), ("ecx", "c"), ("edx", "d")):
    REG32[_b + "x"] = _a
    REG32[_b + "l"] = _a
    REG32[_b + "h"] = _a
for _r in ("si", "di", "bp", "sp"):
    REG32[_r] = "e" + _r
STRINGOPS = {"rep movsd", "movsd", "rep movsb", "movsb", "rep stosd", "stosd", "rep stosb", "stosb"}
FLAGKEEP = {"mov", "movzx", "movsx", "lea", "push", "pop", "nop", "xchg", "cdq", "cwde", "cwd", "leave", "int3", "cld"}
FULL = ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp")

ARITH = {"fadd": ("add", False), "fsub": ("sub", False), "fsubr": ("sub", True), "fmul": ("mul", False),
         "fdiv": ("div", False), "fdivr": ("div", True)}
CONSTS = {"fld1": 1.0, "fldz": 0.0, "fldpi": 3.141592653589793, "fldl2e": 1.4426950408889634,
          "fldl2t": 3.321928094887362, "fldlg2": 0.30102999566398114, "fldln2": 0.6931471805599453}
UNARY = {"fsin", "fcos", "frndint", "f2xm1", "fptan", "fsincos", "fxtract"}
BINARY = {"fpatan", "fscale", "fprem", "fprem1", "fyl2x", "fyl2xp1"}
IGNORE = {"fnstsw", "fstsw", "fnstcw", "fldcw", "fwait", "wait", "sahf", "fnclex", "fclex", "ffree", "fincstp",
          "fdecstp", "fnop", "nop", "cld", "fninit", "fnsave", "frstor", "emms"}
MATHFN = re.compile(r"(?i)^(?:_CI|__CI|_|\?)?(sqrt|sin|cos|tan|atan|atan2|asin|acos|pow|exp|log|log10|fmod|floor|ceil)(?:f)?(?:@.*)?$")
UNARY_CI = {"sqrt", "sin", "cos", "tan", "atan", "asin", "acos", "exp", "log", "log10", "floor", "ceil"}


def st_regs(ins):
    """Register operands of an x87 instruction as stack indexes, from the text (capstone's detail is unreliable
    for fxch)."""
    return [int(m.group(1)) if m.group(1) else 0 for m in re.finditer(r"\bst(?:\((\d)\))?", ins.op_str)]


class State:
    __slots__ = ("regs", "mem", "st", "dirty", "escaped", "cout", "flags", "retained", "peel", "gen", "argdead")      # escaped: set of stack offsets whose address was taken
    # cout: stack offset -> (call id, argument) of the latest call that was passed a pointer to that stack offset

    def __init__(self):
        self.cout = {}
        self.flags = None       # (zf, sf, cf, of): booleans, None when not known
        self.regs = {}
        self.mem = {}
        self.st = []
        self.dirty = set()
        self.escaped = set()
        self.argdead = set()        # entry-stack bytes (incoming arguments) that were overwritten: the argument is gone
        self.peel = frozenset()     # loop heads (not unrolled) whose first iteration this path is in
        self.gen = frozenset()      # loop heads whose generic iteration (loop-carried values forgotten) this path is in
        self.retained = set()   # stack offsets whose address was passed to a call or stored to memory: any call may write them

    def copy(self):
        s = State()
        s.regs = dict(self.regs)
        s.mem = dict(self.mem)
        s.st = list(self.st)
        s.dirty = set(self.dirty)
        s.escaped = set(self.escaped)
        s.retained = set(self.retained)
        s.peel = self.peel
        s.argdead = set(self.argdead)
        s.gen = self.gen
        s.cout = dict(self.cout)
        s.flags = self.flags
        return s


class Sim:
    """Symbolic execution of one function (capstone instructions with optional relocation info)."""

    def __init__(self, insns, side, bind=None, relocs=None, xbe=None, names=None):
        self.insns = insns
        self.side = side
        self.bind = bind or {}              # symbol name -> address
        self.relocs = relocs or {}          # function offset -> symbol name (obj side)
        self.xbe = xbe
        self.names = names or {}            # address -> function name (orig side)
        self.roots = []                     # (kind, node, offset)
        self.roots_gen = []                 # the same, from generic loop iterations (not compared; counted)
        self.cur_gen = False
        self.nunk = 0
        self.ncall = 0
        self.lastcall = None
        self.stats = Counter()
        self.reloc_at = {}                  # instruction address -> (symbol, field offset kind)
        self.callcount = {}
        self.local = {}                     # symbol name -> ObjFn: functions of the same object (inlined when called)
        self.depth = 0
        self.sawloop = False
        self.cdecl_default = False          # unknown callees pop nothing (synthetic tests; else a heuristic)
        self.shared = [BUDGET]              # remaining instruction budget, shared with the helpers executed in place
        self.cons = set()                   # loop heads that are not unrolled
        self.loopw = {}                     # head -> what the body writes (collected while it is simulated)
        self.loop_end = {}
        self.loop_regs = {}
        self.loop_x87 = {}
        self.cur_addr = 0
        self.collecting = False
        self.argmap = {}                    # original's entry-stack offset -> the source's (equiv-conv functions)

    # ---- helpers
    def unk(self, why="?"):
        self.nunk += 1
        return ("u", self.side, self.nunk, why)

    def uval(self, why="?"):
        return atom(self.unk(why))

    def funk(self, why="?"):
        return ("unk", 1, self.unk(why))

    def reg_get(self, s, name):
        n = REG32.get(name, name)
        v = s.regs.get(n)
        if v is None:
            v = s.regs[n] = atom(("r", n)) if n in ("ecx", "edx") else self.uval("reg_init")
        return v

    def reg_set(self, s, name, v):
        s.regs[REG32.get(name, name)] = v

    def sym_value(self, ins, field_off):
        """If the instruction has a relocation at FIELD_OFF within it, the (bound address | None, name)."""
        return self.reloc_at.get((ins.address, field_off))

    def opaddr(self, s, ins, op):
        m = op.mem
        if m.segment != 0:
            return self.uval("seg")
        v = I(m.disp)
        rel = self.reloc_at.get(ins.address)
        if rel is not None and ins.disp_offset and rel[1] == ins.disp_offset:
            addr = self.bind.get(rel[0])
            v = I(m.disp + addr) if addr is not None else iadd(atom(("g", rel[0])), I(m.disp))
        if m.base:
            v = iadd(v, self.reg_get(s, ins.reg_name(m.base)))
        if m.index:
            ix = self.reg_get(s, ins.reg_name(m.index))
            c = iconst(ix)
            if c is not None:
                v = iadd(v, I(c * m.scale))
            elif m.scale == 1:
                v = iadd(v, ix)
            else:
                v = iadd(v, atom(("mul", ix, m.scale)))
        return v

    def immval(self, s, ins, op):
        rel = self.reloc_at.get(ins.address)
        if rel is not None and ins.imm_offset and rel[1] == ins.imm_offset:
            addr = self.bind.get(rel[0])
            if addr is not None:
                return I(op.imm)
            return iadd(atom(("g", rel[0])), I(op.imm))
        return I(op.imm)

    def intval(self, s, ins, op):
        if op.type == X.X86_OP_REG:
            return self.reg_get(s, ins.reg_name(op.reg))
        if op.type == X.X86_OP_IMM:
            return self.immval(s, ins, op)
        if op.type == X.X86_OP_MEM:
            return self.memload_int(s, self.opaddr(s, ins, op), op.size)
        return self.uval("opnd")

    def memload_int(self, s, a, size):
        e = s.mem.get((a, size))
        if e is not None and e[0] == "int":
            return e[1]
        if e is not None and e[0] == "flt" and size == 4:      # the bits of a float stored there (fabs / fchs by mask)
            return atom(("fbits", e[1]))
        off = sp_off(a)
        if off is not None:
            co = self.cout_addr(s, off)
            if co is not None:
                return atom(("m", co, size))
            if off > 0 and size == 4 and is_entry_sp(a) and not any(o in s.argdead for o in range(off, off + 4)):
                return atom(("arg", self.argmap.get(off, off)))
            if off <= 0 or off in s.argdead:
                return self.uval(self.local_why(s, off))
        return atom(("m", a, size))

    def bits2f(self, v, s=None):
        """The float whose bits are the integer value V (a load, with sign-bit masking applied), or None."""
        if v[1] and len(v[1]) == 1 and v[2] == 0:
            a = v[1][0]
            if a[0] == "fbits":
                return a[1]
            if a[0] == "m" and a[2] == 4:
                e = (s or State()).mem.get((a[1], 4))
                if e is not None and e[0] == "int" and e[1] == v:
                    return ("ld", 1, a[1], 4)       # a slot holding its own bits
                return self.memload_float(s or State(), a[1], 4)
            if a[0] == "arg":
                return ("ld", 1, iadd(atom(("sp",)), I(a[1])), 4)
            if a[0] in ("fabsbits", "fnegbits"):
                w = self.bits2f(a[1], s)
                return mk("abs" if a[0] == "fabsbits" else "neg", w) if w is not None else None
        c = iconst(v)
        if c is not None:
            return ("c", 1, struct.unpack("<f", struct.pack("<I", c & 0xFFFFFFFF))[0])
        if _find_u(v) is None:
            return ("fbv", 2, v)        # a float made from integer operations (a random number generator's mantissa)
        return None

    def cout_addr(self, s, off):
        """A stack slot that a callee may have written through a pointer argument: named by (call, argument, offset
        from the pointer), the same on both sides whatever the frame layout."""
        best = None
        for b in s.cout:
            if b <= off < b + 16 and (best is None or b > best):
                best = b
        if best is None:
            return None
        n, k = s.cout[best]
        return iadd(atom(("cptr", n, k)), I(off - best))

    def local_why(self, s, off):
        if any(e <= off < e + 16 for e in s.escaped):
            return "local_escaped"
        return "local_afterloop" if self.sawloop else "local_other"

    def memload_float(self, s, a, size):
        e = s.mem.get((a, size))
        if e is not None and e[0] == "flt":
            return e[1]
        if e is not None and e[0] == "int" and size == 4:
            f = self.bits2f(e[1], s)
            return f if f is not None else self.funk("bits")
        off = sp_off(a)
        if off is not None:
            co = self.cout_addr(s, off)
            if co is not None:
                return ("ld", 1, co, size)
            if off > 0 and any(o in s.argdead for o in range(off, off + size)):
                return self.funk(self.local_why(s, off))
        if off is not None and off > 0 and self.argmap and is_entry_sp(a) and off in self.argmap:
            a = iadd(atom(("sp",)), I(self.argmap[off]))
        if off is not None and off <= 0:
            return self.funk(self.local_why(s, off))
        # a constant in read-only data folds to its value
        c = iconst(a)
        if c is not None and self.xbe is not None:
            sec = self.xbe.section_of(c & 0xFFFFFFFF)
            if sec is not None and sec.name == ".rdata" and size in (4, 8):
                o = self.xbe.offset(c & 0xFFFFFFFF)
                if o is not None:
                    return ("c", 1, struct.unpack("<f" if size == 4 else "<d", self.xbe.data[o:o + size])[0])
        for t in a[1]:
            if t[0] == "g" and t[1].startswith("__real@") and a[2] == 0 and len(a[1]) == 1:
                h = t[1][7:].split("@")[0]
                try:
                    if len(h) == 8 and size == 4:
                        return ("c", 1, struct.unpack("<f", bytes.fromhex(h)[::-1])[0])
                    if len(h) == 16 and size == 8:
                        return ("c", 1, struct.unpack("<d", bytes.fromhex(h)[::-1])[0])
                except ValueError:
                    pass
        return ("ld", 1, a, size)

    def pair_double(self, s, a):
        """Two dword constant stores into an 8-byte stack slot (a double assigned from a constant): one double."""
        for lo in (a, iadd(a, I(-4))):
            hi = iadd(lo, I(4))
            l, h = s.mem.get((lo, 4)), s.mem.get((hi, 4))
            if l and h and l[0] == "int" and h[0] == "int" and iconst(l[1]) is not None and iconst(h[1]) is not None:
                bits = ((iconst(h[1]) & 0xFFFFFFFF) << 32) | (iconst(l[1]) & 0xFFFFFFFF)
                s.mem[(lo, 8)] = ("flt", ("c", 1, struct.unpack("<d", struct.pack("<Q", bits))[0]))

    def note_write(self, a, size):
        """Record a memory write in every loop (not unrolled) whose body contains the current instruction."""
        for h in self.cons:
            if h <= self.cur_addr <= self.loop_end[h]:
                w = self.loopw.setdefault(h, {"slots": set(), "ptr": False, "dyn": False, "call": False, "pw": set()})
                off = sp_off(a)
                if off is not None:
                    w["slots"].add((off, size))
                elif any(x[0] in ("sp", "sp2") for x in a[1]):
                    w["dyn"] = True
                else:
                    w["ptr"] = True

    def note_pw(self, off):
        for h in self.cons:
            if h <= self.cur_addr <= self.loop_end[h]:
                self.loopw.setdefault(h, {"slots": set(), "ptr": False, "dyn": False, "call": False, "pw": set()})["pw"].add(off)

    def note_flag(self, flag):
        for h in self.cons:
            if h <= self.cur_addr <= self.loop_end[h]:
                self.loopw.setdefault(h, {"slots": set(), "ptr": False, "dyn": False, "call": False, "pw": set()})[flag] = True

    def store(self, s, a, size, kind, v):
        self.note_write(a, size)
        if sp_off(a) is not None and sp_off(a) > 0:
            s.argdead.update(range(sp_off(a), sp_off(a) + size))
        if kind == "int" and sp_off(a) is None and sp_off(v) is not None:
            s.retained.add(sp_off(v))       # the address of a local stored in memory: anything may write through it
        # a store through a pointer drops forwarded values of other bases
        if sp_off(a) is None:
            for k in [k for k in s.mem if sp_off(k[0]) is None and k[0][1] != a[1]]:
                del s.mem[k]
        else:
            for k in [k for k in s.mem if sp_off(k[0]) is not None and k[0][2] < a[2] + size and a[2] < k[0][2] + k[1]
                      and k != (a, size)]:
                del s.mem[k]
        s.mem[(a, size)] = (kind, v)
        if kind == "int" and size == 4 and sp_off(a) is not None and iconst(v) is not None:
            self.pair_double(s, a)

    # ---- x87 stack
    def push(self, s, v):
        s.st.append(v)
        if len(s.st) > 8:
            del s.st[0]

    def virt(self, s, i):
        """x87 stack index I is below the modelled stack: the result of the last call (a float function's st(0) is
        not pushed when the call is made; it appears when something uses it)."""
        if i == len(s.st) and self.lastcall is not None:
            s.st.insert(0, self.lastcall)
            self.lastcall = None
            return True
        return False

    def pop(self, s):
        if not s.st:
            self.virt(s, 0)
        if s.st:
            return s.st.pop()
        return self.funk("st_empty")

    def sti(self, s, i):
        if i >= len(s.st):
            self.virt(s, i)
        if i < len(s.st):
            return s.st[-1 - i]
        return self.funk("st_empty")

    def set_sti(self, s, i, v):
        if i >= len(s.st):
            self.virt(s, i)
        if i < len(s.st):
            s.st[-1 - i] = v

    def root(self, kind, v, ins, strip_top=True):
        while v[0] == "rnd":        # a store to float memory rounds anyway
            v = v[2]
        if v[0] in ("ld", "c", "unk", "call", "fild", "fbv"):
            return
        (self.roots_gen if self.cur_gen else self.roots).append((kind, v, ins.address))

    # ---- merging
    def iphi(self, x, y):
        """An integer value that is X on one path and Y on the other (both known), else an unknown."""
        if x is None or y is None or _find_u(x) is not None or _find_u(y) is not None or _isz(x) + _isz(y) > 80:
            return self.uval("merge_reg")
        mem = []
        for v in (x, y):
            if len(v[1]) == 1 and v[2] == 0 and v[1][0][0] == "iphi":
                mem.extend(v[1][0][1:])
            else:
                mem.append(v)
        mem = sorted(set(mem), key=_sk)
        if len(mem) > 4:
            return self.uval("merge_reg")
        return atom(("iphi",) + tuple(mem))

    def merge(self, a, b):
        r = State()
        for k in set(a.regs) | set(b.regs):
            x, y = a.regs.get(k), b.regs.get(k)
            r.regs[k] = x if x == y and x is not None else (x if k == "esp" and x is not None else self.iphi(x, y))
        for k, v in a.mem.items():
            w = b.mem.get(k)
            if w == v:
                r.mem[k] = v
            elif w is not None and v[0] == "int" and w[0] == "int":
                r.mem[k] = ("int", self.iphi(v[1], w[1]))
            elif w is not None and k[1] == 4 and {v[0], w[0]} == {"int", "flt"}:      # a float written as bits on one path
                fl, it = (v, w) if v[0] == "flt" else (w, v)
                f2 = self.bits2f(it[1], a if it is v else b)
                if f2 is not None and fl[1][0] != "unk" and f2[0] != "unk":
                    r.mem[k] = ("flt", mk("phi", fl[1], f2))
            elif w is not None and v[0] == "flt" and w[0] == "flt" and v[1][0] != "unk" and w[1][0] != "unk":
                r.mem[k] = ("flt", mk("phi", v[1], w[1]))
        n = min(len(a.st), len(b.st))
        r.st = [x if x == y else (mk("phi", x, y) if x[0] != "unk" and y[0] != "unk" else self.funk("merge_st"))
                for x, y in zip(a.st[-n:] if n else [], b.st[-n:] if n else [])]
        r.escaped = a.escaped | b.escaped
        r.retained = a.retained | b.retained
        r.peel = a.peel | b.peel
        r.argdead = a.argdead | b.argdead
        r.gen = a.gen | b.gen
        r.cout = {k: v for k, v in a.cout.items() if b.cout.get(k) == v}
        if a.flags is not None and a.flags == b.flags:
            r.flags = a.flags
        return r

    def forget(self, s, head=None):
        """Loop head that is not unrolled: forget what the loop body may change. Before the body's writes are known
        (the collecting pass) that is everything but the stack pointer and the frame pointer."""
        r = State()
        w = None if self.collecting else self.loopw.get(head)
        if w is None or w["dyn"]:
            wr = None
        else:
            wr = self.loop_regs.get(head)
        for k, v in s.regs.items():
            keep = k == "esp" or (k == "ebp" and "ebp" not in self.loop_regs.get(head, ("ebp",))) \
                or (wr is not None and k not in wr)
            r.regs[k] = v if keep else self.uval("loop_reg")
        r.escaped = set(s.escaped)
        r.retained = set(s.retained)
        if wr is not None:
            alias = w["ptr"] or w["call"]
            win = (s.retained | w["pw"]) if alias else set()      # windows a call in the body can write
            for (a, size), e in s.mem.items():
                off = sp_off(a)
                if off is not None:
                    if any(o < off + size and off < o + z for o, z in w["slots"]):
                        continue
                    if alias and any(e0 <= off < e0 + 16 for e0 in win):
                        continue
                elif alias:
                    continue
                r.mem[(a, size)] = e
            r.cout = {b: v for b, v in s.cout.items() if not any(o < b + 16 and b < o + z for o, z in w["slots"])
                      and not any(b < e0 + 16 and e0 < b + 16 for e0 in win)}
        if wr is not None and not self.loop_x87.get(head, True):
            r.st = list(s.st)
        else:
            r.st = [self.funk("loop_st") for _ in s.st]
        return r

    # ---- run
    def run(self, regs=None, mem=None, init=None):
        """Symbolic execution along the control flow. Branches whose condition is decided by constants (a loop over a
        constant count) are followed, so a loop is unrolled; the others merge (forward) or, for a loop whose exit is
        not decided, forget what the loop may change (backward)."""
        insns = self.insns
        self.rets = []
        self.back = set()
        lo, hi = insns[0].address, insns[-1].address + insns[-1].size
        self.targets = set()
        for i in insns:
            if i.group(capstone.CS_GRP_JUMP) and i.operands and i.operands[0].type == X.X86_OP_IMM:
                t = i.operands[0].imm
                if self.relocs_has(i):
                    continue
                if lo <= t < hi:
                    self.targets.add(t)
                    if t <= i.address:
                        self.back.add(t)
        self.a2i = {ins.address: k for k, ins in enumerate(insns)}
        if self.back:
            self.loop_info()
        if self.depth > 0 or not self.back:
            self.cons = set(self.back)       # a helper inlined into a caller: loops are not unrolled
            return self.run_cons(regs, mem, init=init)
        self.cons = set()
        for _ in range(8):
            self.reset()
            self.bad = set()
            r = self.run1(regs, mem)
            if not self.bad:
                if not self.cons:
                    return r
                return self.run_cons(regs, mem, r)
            self.cons |= self.bad
        self.cons = set(self.back)
        return self.run_cons(regs, mem)

    def run_cons(self, regs, mem, first=None, init=None):
        """A run with loops that are not unrolled: one pass to collect what each body writes, then the real one."""
        if self.cons and not all(h in self.loopw for h in self.cons):
            snap = dict(self.callcount)
            self.reset()
            self.collecting = True
            self.bad = set()
            self.run1(regs, mem, init)
            self.collecting = False
            self.callcount.clear()
            self.callcount.update(snap)
        self.reset()
        self.bad = set()
        return self.run1(regs, mem, init)

    def loop_info(self):
        """Per loop head: the last instruction of its body, the registers the body writes, whether it uses x87."""
        insns = self.insns
        for i in insns:
            if i.group(capstone.CS_GRP_JUMP) and i.operands and i.operands[0].type == X.X86_OP_IMM \
                    and i.operands[0].imm in self.back and i.operands[0].imm <= i.address and not self.relocs_has(i):
                h = i.operands[0].imm
                self.loop_end[h] = max(self.loop_end.get(h, 0), i.address)
        for h, e in self.loop_end.items():
            regs, x87 = set(), False
            for i in insns:
                if h <= i.address <= e:
                    try:
                        _, w = i.regs_access()
                    except Exception:
                        w = ()
                    for r in w:
                        nm = REG32.get(i.reg_name(r))
                        if nm:
                            regs.add(nm)
                    if i.mnemonic == "call":
                        regs.update(("eax", "ecx", "edx"))
                    if i.mnemonic.startswith("rep") or i.mnemonic in ("movsd", "stosd", "movsb", "stosb"):
                        regs.update(("eax", "ecx", "esi", "edi"))
                    if i.mnemonic.startswith("f") or i.mnemonic in IGNORE:
                        x87 = True
            self.loop_regs[h] = regs
            self.loop_x87[h] = x87

    def reset(self):
        self.roots = []
        self.roots_gen = []
        self.rets = []
        self.ncall = 0
        self.lastcall = None
        self.stats = Counter()
        if self.depth == 0:
            self.callcount.clear()
            self.shared[0] = BUDGET
        self.sawloop = False
        self.ret_states = []

    def run1(self, regs, mem, init=None):
        insns = self.insns
        if init is not None:
            s = init.copy()
        else:
            s = State()
            s.regs["esp"] = atom(("sp",))
            s.regs.update(regs or {})
            s.mem.update(mem or {})
        saved = {}
        visits = Counter()
        steps = 0
        idx = 0
        maxv = -1
        via_back = None
        last = s.copy()
        n = len(insns)
        while True:
            if s is None or idx >= n:
                # the path ended: continue at the lowest pending branch target or just after the furthest instruction run
                nxt = maxv + 1
                pend = min(saved) if saved else None
                if pend is not None and (nxt >= n or pend <= insns[nxt].address):
                    s = saved.pop(pend)
                    idx = self.a2i[pend]
                elif nxt < n:
                    s = last.copy()     # unreachable or unseen: keep going with what we have
                    idx = nxt
                else:
                    break
            ins = insns[idx]
            a = ins.address
            maxv = max(maxv, idx)
            self.cur_addr = a
            steps += 1
            self.shared[0] -= 1
            if self.shared[0] < 0:
                return self.roots
            if steps > MAXSTEPS:
                self.bad |= {h for h, v in visits.items() if v > 1 and h not in self.cons} or (self.back - self.cons)
                return self.roots
            if a in saved:
                s = self.merge(s, saved.pop(a))
            if s.peel:
                for h in [h for h in s.peel if not (h <= a <= self.loop_end[h])]:
                    s.peel = s.peel - {h}       # left the loop
            if s.gen:
                for h in [h for h in s.gen if not (h <= a <= self.loop_end[h])]:
                    s.gen = s.gen - {h}
            self.cur_gen = bool(s.gen)
            if a in self.back:
                visits[a] += 1
                if a in self.cons:
                    self.sawloop = True
                    if via_back != a:
                        s.peel = s.peel | {a}       # entered from outside: this iteration is simulated as it is
                elif visits[a] > MAXVISITS:
                    self.bad.add(a)
                    return self.roots
            via_back = None
            mn = ins.mnemonic
            try:
                if mn.startswith("f") or mn in IGNORE:
                    self.x87(s, ins)
                else:
                    self.integer(s, ins, idx, saved, self.targets)
            except IndexError:
                self.stats["err"] += 1
            idx += 1
            if mn.startswith("ret"):
                self.rets.append((self.sti(s, 0) if s.st else None, s.regs.get("eax")))
                if self.depth > 0:
                    self.ret_states.append(s.copy())
                elif s.st:
                    self.root("ret", self.sti(s, 0), ins)
                    s.st = []
                last = s
                s = None
                continue
            if mn.startswith("j") and ins.operands and ins.operands[0].type == X.X86_OP_IMM:
                t = ins.operands[0].imm
                inrange = t in self.targets and not self.relocs_has(ins)
                uncond = mn == "jmp"
                dec = True if uncond else self.decide(s, ins)
                if not inrange:
                    if uncond:
                        last = s
                        s = None
                    continue
                if dec is True:
                    if t > a:       # forward: join the other paths in address order
                        if t in saved:
                            saved[t] = self.merge(saved[t], s)
                        else:
                            saved[t] = s.copy()
                        last = s
                        s = None
                    elif t in self.cons:        # backward to a loop we did not unroll
                        s, idx, via_back, last = self.loop_back(s, t, saved, idx, None)
                    else:
                        idx = self.a2i[t]
                    continue
                if dec is False:
                    continue
                if t > a:
                    if t in saved:
                        saved[t] = self.merge(saved[t], s)
                    else:
                        saved[t] = s.copy()
                elif t not in self.cons:
                    self.bad.add(t)         # an undecided exit of a loop we tried to unroll
                    return self.roots
                else:       # undecided backward branch of a loop we did not unroll: it may exit here or go round again
                    s, idx, via_back, last = self.loop_back(s, t, saved, idx, True)
            elif mn == "jmp":
                last = s
                s = None
        return self.roots

    def loop_back(self, s, t, saved, idx, exits):
        """A backward branch to the head T of a loop that is not unrolled. The first iteration was simulated with
        the state the loop was entered with; this edge starts the generic iteration (what the body writes forgotten).
        After the generic iteration the path ends. A conditional edge also exits here: that state joins at the
        next instruction. Returns (state or None, next index, via_back, last)."""
        insns = self.insns
        if exits and idx < len(insns):
            nxt = insns[idx].address
            if nxt in saved:
                saved[nxt] = self.merge(saved[nxt], s)
            else:
                saved[nxt] = s.copy()
        if t in s.peel:
            g = self.forget(s, t)
            g.peel = s.peel - {t}
            g.gen = s.gen | {t}
            return g, self.a2i[t], t, s
        return None, idx, None, s

    def decide(self, s, ins):
        """True / False when the flags (known from constants) decide the conditional jump, else None."""
        f = s.flags
        if f is None:
            return None
        zf, sf, cf, of = f
        mn = ins.mnemonic
        c = {"je": lambda: zf, "jne": lambda: None if zf is None else not zf,
             "jb": lambda: cf, "jae": lambda: None if cf is None else not cf,
             "jbe": lambda: None if cf is None or zf is None else (cf or zf),
             "ja": lambda: None if cf is None or zf is None else not (cf or zf),
             "js": lambda: sf, "jns": lambda: None if sf is None else not sf,
             "jo": lambda: of, "jno": lambda: None if of is None else not of,
             "jl": lambda: None if sf is None or of is None else sf != of,
             "jge": lambda: None if sf is None or of is None else sf == of,
             "jle": lambda: None if sf is None or of is None or zf is None else (zf or sf != of),
             "jg": lambda: None if sf is None or of is None or zf is None else not (zf or sf != of)}.get(mn)
        return c() if c else None

    def relocs_has(self, ins):
        return ins.address in self.reloc_at

    # ---- integer / control instructions
    def uflags(self, s, op, a, b):
        """Flags of the 32-bit operation A op B when both are constants, else unknown."""
        ca, cb = (None if a is None else iconst(a)), (None if b is None else iconst(b))
        if ca is None or (cb is None and op not in ("neg",)):
            s.flags = None
            return
        ca &= 0xFFFFFFFF
        cb = 0 if cb is None else cb & 0xFFFFFFFF
        if op in ("sub", "cmp"):
            r = (ca - cb) & 0xFFFFFFFF
            cf, of = ca < cb, bool(((ca ^ cb) & (ca ^ r)) >> 31)
        elif op == "add":
            r = (ca + cb) & 0xFFFFFFFF
            cf, of = ca + cb > 0xFFFFFFFF, bool((~(ca ^ cb) & (ca ^ r)) >> 31)
        elif op in ("and", "test"):
            r, cf, of = ca & cb, False, False
        elif op == "or":
            r, cf, of = ca | cb, False, False
        elif op == "xor":
            r, cf, of = ca ^ cb, False, False
        elif op == "neg":
            r = (-ca) & 0xFFFFFFFF
            cf, of = ca != 0, ca == 0x80000000
        else:
            s.flags = None
            return
        s.flags = (r == 0, bool(r >> 31), cf, of)

    def integer(self, s, ins, idx, saved, targets):
        mn = ins.mnemonic
        ops = ins.operands
        esp = self.reg_get(s, "esp")
        oldf = s.flags
        if mn not in FLAGKEEP and not mn.startswith(("j", "cmov", "set")):
            s.flags = None
        if mn in STRINGOPS:
            self.string_op(s, ins)
        elif mn == "push":
            saved = ops[0].type == X.X86_OP_REG and REG32.get(ins.reg_name(ops[0].reg)) in ("ebx", "esi", "edi", "ebp") \
                and REG32.get(ins.reg_name(ops[0].reg)) not in s.regs      # a callee-saved register being saved
            v = self.intval(s, ins, ops[0])
            esp = iadd(esp, I(-4))
            s.regs["esp"] = esp
            self.store(s, esp, 4, "int", v)
            off = sp_off(esp)
            if off is not None and not saved:
                s.dirty.add(off)
        elif mn == "pop":
            v = self.memload_int(s, esp, 4)
            s.regs["esp"] = iadd(esp, I(4))
            if ops[0].type == X.X86_OP_REG:
                self.reg_set(s, ins.reg_name(ops[0].reg), v)
        elif mn == "mov":
            d, src = ops[0], ops[1]
            if d.type == X.X86_OP_REG and d.size == 1 and src.type == X.X86_OP_MEM and src.size == 1:
                self.reg_set(s, ins.reg_name(d.reg), atom(("byte", self.opaddr(s, ins, src))))
            elif d.type == X.X86_OP_MEM and d.size == 1 and src.type == X.X86_OP_REG:
                v = self.reg_get(s, ins.reg_name(src.reg))
                a = self.opaddr(s, ins, d)
                if v[1] and len(v[1]) == 1 and v[1][0][0] in ("babs", "bneg") and v[1][0][1] == a:
                    self.sign_byte(s, a, v[1][0][0], True)
                else:
                    self.store(s, a, 1, "int", self.uval("byte_store"))
            elif d.type == X.X86_OP_REG:
                if d.size == 4:
                    self.reg_set(s, ins.reg_name(d.reg), self.intval(s, ins, src))
                else:
                    self.reg_set(s, ins.reg_name(d.reg), self.uval("subreg"))
            elif d.type == X.X86_OP_MEM:
                a = self.opaddr(s, ins, d)
                if d.size == 4:
                    self.store(s, a, 4, "int", self.intval(s, ins, src))
                    off = sp_off(a)
                    if off is not None:
                        s.dirty.add(off)
                else:
                    self.store(s, a, d.size, "int", self.uval("sub_store"))
        elif mn == "lea":
            v = self.opaddr(s, ins, ops[1])
            if sp_off(v) is not None:
                s.escaped.add(sp_off(v))
            self.reg_set(s, ins.reg_name(ops[0].reg), v)
        elif mn == "and" and ops[0].type == X.X86_OP_REG and ins.reg_name(ops[0].reg) == "esp":
            self.reg_set(s, "esp", atom(("sp2",)))      # stack realignment: a new frame base
        elif mn in ("add", "sub") and ops[0].type == X.X86_OP_REG and ops[0].size == 4:
            x = self.reg_get(s, ins.reg_name(ops[0].reg))
            y = self.intval(s, ins, ops[1])
            if mn == "sub" and ops[1].type == X.X86_OP_REG and ops[1].reg == ops[0].reg:
                r = I(0)
                s.flags = (True, False, False, False)
            else:
                r = iadd(x, y) if mn == "add" else isub(x, y)
                self.uflags(s, mn, x, y)
            self.reg_set(s, ins.reg_name(ops[0].reg), r)
        elif mn in ("inc", "dec") and ops[0].type == X.X86_OP_REG and ops[0].size == 4:
            n = ins.reg_name(ops[0].reg)
            x = self.reg_get(s, n)
            r = iadd(x, I(1 if mn == "inc" else -1))
            self.reg_set(s, n, r)
            cr = iconst(r)
            if cr is not None and oldf is not None:      # inc/dec keep CF
                cr &= 0xFFFFFFFF
                s.flags = (cr == 0, bool(cr >> 31), oldf[2], cr == (0x80000000 if mn == "inc" else 0x7FFFFFFF))
        elif mn in ("and", "xor") and len(ops) == 2 and ops[1].type == X.X86_OP_IMM and ops[0].size == 1 \
                and (mn, ops[1].imm & 0xFF) in (("and", 0x7F), ("xor", 0x80)):
            tag = "babs" if mn == "and" else "bneg"
            if ops[0].type == X.X86_OP_REG:
                n = ins.reg_name(ops[0].reg)
                v = self.reg_get(s, n)
                if v[1] and len(v[1]) == 1 and v[1][0][0] == "byte":
                    self.reg_set(s, n, atom((tag, v[1][0][1])))
                else:
                    self.reg_set(s, n, self.uval("byte_op"))
            else:
                self.sign_byte(s, self.opaddr(s, ins, ops[0]), tag)
        elif mn in ("and", "xor") and len(ops) == 2 and ops[0].size == 4 \
                and (mn, self.constop(s, ins, ops[1])) in (("and", 0x7FFFFFFF), ("xor", 0x80000000)):
            tag = "fabsbits" if mn == "and" else "fnegbits"
            if ops[0].type == X.X86_OP_REG:
                n = ins.reg_name(ops[0].reg)
                self.reg_set(s, n, atom((tag, self.reg_get(s, n))))
            else:
                a = self.opaddr(s, ins, ops[0])
                e = s.mem.get((a, 4))
                if e is not None and e[0] == "flt":
                    base = e[1]
                    self.store(s, a, 4, "flt", mk("abs" if mn == "and" else "neg", base))
                else:
                    self.store(s, a, 4, "int", atom((tag, self.memload_int(s, a, 4))))
        elif mn == "xor" and ops[0].type == X.X86_OP_REG and ops[1].type == X.X86_OP_REG and ops[0].reg == ops[1].reg:
            self.reg_set(s, ins.reg_name(ops[0].reg), I(0))
            if ops[0].size == 4:
                s.flags = (True, False, False, False)
        elif mn in ("and", "or", "xor") and len(ops) == 2 and ops[0].type == X.X86_OP_REG and ops[0].size == 4:
            x = self.reg_get(s, ins.reg_name(ops[0].reg))
            y = self.intval(s, ins, ops[1])
            cx, cy = iconst(x), iconst(y)
            if cx is not None and cy is not None:
                cx, cy = cx & 0xFFFFFFFF, cy & 0xFFFFFFFF
                r = I({"and": cx & cy, "or": cx | cy, "xor": cx ^ cy}[mn])
                self.uflags(s, mn, x, y)
            else:
                r = self.iop(mn, *sorted((x, y), key=_sk))
            self.reg_set(s, ins.reg_name(ops[0].reg), r)
        elif mn in ("shl", "sal", "shr", "sar") and len(ops) == 2 and ops[0].type == X.X86_OP_REG and ops[0].size == 4 \
                and ops[1].type == X.X86_OP_IMM:
            x = self.reg_get(s, ins.reg_name(ops[0].reg))
            cx, k = iconst(x), ops[1].imm & 31
            if cx is not None and k:
                if mn in ("shl", "sal"):
                    r = I(cx << k)
                elif mn == "shr":
                    r = I((cx & 0xFFFFFFFF) >> k)
                else:
                    r = I(cx >> k)
            elif k == 0:
                r = x
            elif mn in ("shl", "sal"):
                r = atom(("mul", x, 1 << k))
            else:
                r = self.iop("%s%d" % (mn, k), x)
            self.reg_set(s, ins.reg_name(ops[0].reg), r)
        elif mn in ("shl", "sal", "shr", "sar") and len(ops) == 2 and ops[0].type == X.X86_OP_REG and ops[0].size == 4 \
                and ops[1].type == X.X86_OP_REG:
            self.reg_set(s, ins.reg_name(ops[0].reg), self.iop(mn, self.reg_get(s, ins.reg_name(ops[0].reg)),
                                                               self.reg_get(s, ins.reg_name(ops[1].reg))))
        elif mn == "imul" and len(ops) in (2, 3) and ops[0].type == X.X86_OP_REG and ops[0].size == 4:
            x = self.intval(s, ins, ops[1]) if len(ops) == 3 else self.reg_get(s, ins.reg_name(ops[0].reg))
            y = self.intval(s, ins, ops[2] if len(ops) == 3 else ops[1])
            cx, cy = iconst(x), iconst(y)
            if cx is not None and cy is not None:
                r = I(cx * cy)
            elif cy is not None or cx is not None:
                r = atom(("mul", y if cx is not None else x, cx if cx is not None else cy))
            else:
                r = self.iop("imul", *sorted((x, y), key=_sk))
            self.reg_set(s, ins.reg_name(ops[0].reg), r)
        elif mn in ("neg", "not") and len(ops) == 1 and ops[0].type == X.X86_OP_REG and ops[0].size == 4:
            x = self.reg_get(s, ins.reg_name(ops[0].reg))
            cx = iconst(x)
            self.reg_set(s, ins.reg_name(ops[0].reg),
                         (I(-cx) if mn == "neg" else I(~cx)) if cx is not None else self.iop(mn, x))
            if mn == "neg":
                self.uflags(s, "neg", x, None)
        elif mn == "leave":
            ebp = self.reg_get(s, "ebp")
            s.regs["esp"] = ebp
            s.regs["ebp"] = self.memload_int(s, ebp, 4)
            s.regs["esp"] = iadd(ebp, I(4))
        elif mn == "call":
            self.call(s, ins, idx)
        elif mn in ("cmp", "test") and len(ops) == 2 and ops[0].size == 4:
            self.uflags(s, mn, self.intval(s, ins, ops[0]), self.intval(s, ins, ops[1]))
        elif mn in ("cmp", "test", "nop", "int3", "cld", "sahf", "ret", "retn") or mn.startswith("j") \
                or mn.startswith("set") and False:
            pass
        elif mn in ("movzx", "movsx", "movsxd"):
            if ops[0].type == X.X86_OP_REG:
                src = ops[1]
                v = self.intval(s, ins, src) if src.type != X.X86_OP_MEM else self.memload_int(s, self.opaddr(s, ins, src), src.size)
                cv = iconst(v)
                if cv is not None and src.type == X.X86_OP_IMM:
                    r = v
                else:
                    r = self.iop("%s%d" % (mn, src.size), v)
                self.reg_set(s, ins.reg_name(ops[0].reg), r)
        elif mn == "xchg":
            for o in ops:
                if o.type == X.X86_OP_REG:
                    self.reg_set(s, ins.reg_name(o.reg), self.uval("xchg"))
        elif mn == "cdq" and iconst(self.reg_get(s, "eax")) is not None:
            self.reg_set(s, "edx", I(-1 if iconst(self.reg_get(s, "eax")) < 0 else 0))
        elif mn == "cdq":
            self.reg_set(s, "edx", self.iop("cdq", self.reg_get(s, "eax")))
        elif mn in ("cwde", "cwd"):
            self.reg_set(s, "edx" if mn == "cdq" else "eax", self.uval("cdq"))
        elif len(ops) == 1 and mn in ("mul", "imul", "div", "idiv") and ops[0].size == 4:
            src = self.intval(s, ins, ops[0])
            ea, ed = self.reg_get(s, "eax"), self.reg_get(s, "edx")
            if mn in ("div", "idiv"):
                self.reg_set(s, "eax", self.iop(mn + ".q", ea, ed, src))
                self.reg_set(s, "edx", self.iop(mn + ".r", ea, ed, src))
            else:
                self.reg_set(s, "eax", self.iop(mn + ".lo", ea, src))
                self.reg_set(s, "edx", self.iop(mn + ".hi", ea, src))
        elif ops and ops[0].type == X.X86_OP_REG:
            n = ins.reg_name(ops[0].reg)
            if mn.startswith("cmov") or mn.startswith("set") or True:
                self.reg_set(s, n, self.uval("int_op"))
            if mn == "mul" or mn == "div" or mn == "idiv" or mn == "imul" and len(ops) == 1:
                self.reg_set(s, "eax", self.uval("muldiv"))
                self.reg_set(s, "edx", self.uval("muldiv"))
        elif ops and ops[0].type == X.X86_OP_MEM:
            if mn in ("mul", "div", "idiv") or (mn == "imul" and len(ops) == 1):
                self.reg_set(s, "eax", self.uval("muldiv"))
                self.reg_set(s, "edx", self.uval("muldiv"))
            elif mn not in ("cmp", "test", "push", "call", "jmp"):
                a = self.opaddr(s, ins, ops[0])
                self.note_write(a, ops[0].size)
                for k in [k for k in s.mem if k[0] == a or sp_off(a) is None and sp_off(k[0]) is None]:
                    del s.mem[k]

    def iop(self, name, *vals):
        """An integer operation on known values whose result we do not fold: the same operation on the same values
        is the same value on the other side. (Values that grow past a size are unknown: they are hashed all the time.)"""
        if sum(_isz(v) for v in vals) > 80:
            return self.uval("big")
        return atom(("iop", name) + tuple(vals))

    def string_op(self, s, ins):
        """rep movs / stos: a block copy or fill of a known number of dwords is done word by word (a struct copy by
        the original, a memcpy by clang -O0 are then the same memory); anything else forgets the destination."""
        mn = ins.mnemonic
        rep = mn.startswith("rep")
        base = mn.split()[-1]
        size = 4 if base.endswith("d") else 1
        mov = base.startswith("movs")
        cnt = iconst(self.reg_get(s, "ecx")) if rep else 1
        src, dst = self.reg_get(s, "esi"), self.reg_get(s, "edi")
        if cnt is None or cnt < 0 or cnt > 256:
            self.note_flag("dyn")
            for r in ("eax", "ecx", "esi", "edi"):
                self.reg_set(s, r, self.uval("rep"))
            off = sp_off(dst)
            s.mem = {k: v for k, v in s.mem.items() if sp_off(k[0]) is not None and (off is None or sp_off(k[0]) < off)}
            return
        self.note_write(dst, cnt * size)
        if size == 4:
            for k in range(cnt):
                d = iadd(dst, I(4 * k))
                if mov:
                    sa = iadd(src, I(4 * k))
                    e = s.mem.get((sa, 4))
                    if e is not None and e[0] in ("int", "flt"):
                        self.store(s, d, 4, e[0], e[1])
                    else:
                        self.store(s, d, 4, "int", self.memload_int(s, sa, 4))
                else:
                    self.store(s, d, 4, "int", self.reg_get(s, "eax"))
        else:
            for k in [k for k in s.mem if sp_off(k[0]) is not None and sp_off(dst) is not None
                      and k[0][2] < dst[2] + cnt and dst[2] < k[0][2] + k[1]]:
                del s.mem[k]
        if mov:
            self.reg_set(s, "esi", iadd(src, I(cnt * size)))
        self.reg_set(s, "edi", iadd(dst, I(cnt * size)))
        if rep:
            self.reg_set(s, "ecx", I(0))

    def constop(self, s, ins, op):
        """The constant value of an immediate or of a register holding one, else None."""
        if op.type == X.X86_OP_IMM:
            return op.imm & 0xFFFFFFFF
        if op.type == X.X86_OP_REG:
            c = iconst(self.reg_get(s, ins.reg_name(op.reg)))
            return None if c is None else c & 0xFFFFFFFF
        return None

    def inline(self, s, f, esp, off, words):
        """A call to a function of the same object (clang -O0 keeps helpers MSVC inlines): execute the callee in
        place on the caller's state (its arguments are the words the caller pushed or stored), as the processor
        would. The callee's stores are the caller's; its roots are roots."""
        sub = Sim(f.insns, self.side, bind=self.bind, xbe=self.xbe, names=self.names)
        sub.reloc_at = f.reloc_at
        sub.local = self.local
        sub.depth = self.depth + 1
        sub.nunk = self.nunk
        sub.callcount = self.callcount
        sub.cdecl_default = self.cdecl_default
        sub.shared = self.shared
        s0 = s.copy()
        s0.regs["esp"] = iadd(esp, I(-4))
        s0.mem[(s0.regs["esp"], 4)] = ("int", atom(("retaddr", self.depth)))
        s0.dirty = set()
        sub.ret_states = []
        sub.run(init=s0)
        self.nunk = sub.nunk
        self.ncall += sub.ncall
        self.roots.extend(sub.roots)
        self.roots_gen.extend(sub.roots_gen)
        if not sub.ret_states:      # no return found: unknown effects
            for r in ("eax", "ecx", "edx"):
                s.regs[r] = self.uval("call_clob")
            s.mem = {k: v for k, v in s.mem.items() if sp_off(k[0]) is not None
                     and not any(e <= sp_off(k[0]) < e + 16 for e in s.escaped)}
            return
        m = sub.ret_states[0]
        for r in sub.ret_states[1:]:
            m = self.merge(m, r)
        pop = 4
        for i in f.insns:
            if i.mnemonic == "ret" and i.operands:
                pop += i.operands[0].imm
                break
        m.regs["esp"] = iadd(esp, I(pop - 4))
        m.dirty = set()
        s.regs, s.mem, s.st, s.dirty, s.escaped, s.cout, s.flags = m.regs, m.mem, m.st, m.dirty, m.escaped, m.cout, None

    def sign_byte(self, s, a, tag, already=False):
        """The top byte of the float at A-3 masked (and 0x7f) or flipped (xor 0x80): fabs / fchs."""
        base = iadd(a, I(-3))
        w = self.memload_float(s, base, 4)
        self.store(s, base, 4, "flt", mk("abs" if tag == "babs" else "neg", w))

    def callname(self, ins):
        rel = self.reloc_at.get(ins.address)
        if rel is not None:
            return rel[0], self.bind.get(rel[0])
        o = ins.operands[0] if ins.operands else None
        if o is not None and o.type == X.X86_OP_IMM:
            return self.names.get(o.imm, "0x%x" % o.imm), o.imm
        return None, None

    def call(self, s, ins, idx):
        name, target = self.callname(ins)
        nxt = self.insns[idx + 1] if idx + 1 < len(self.insns) else None
        esp = self.reg_get(s, "esp")
        off = sp_off(esp)
        words = 0
        if off is not None:
            while (off + 4 * words) in s.dirty:
                words += 1
        self.ncall += 1
        if target is not None:
            key = target
        elif name is not None:
            key = name
        elif ins.operands and ins.operands[0].type == X.X86_OP_MEM:
            key = ("ind", self.opaddr(s, ins, ins.operands[0]))
        elif ins.operands and ins.operands[0].type == X.X86_OP_REG:
            v = self.reg_get(s, ins.reg_name(ins.operands[0].reg))
            if len(v[1]) == 1 and v[2] == 0 and v[1][0][0] == "m" and v[1][0][2] == 4:
                key = ("ind", v[1][0][1])       # call reg after mov reg,[mem]: the same call as call [mem]
            else:
                key = ("indreg", v)
        else:
            key = "?"
        self.callcount[key] = self.callcount.get(key, 0) + 1
        n = (key if isinstance(key, (int, str)) else "ind%d" % _sk(key), self.callcount[key])
        self.note_flag("call")
        ptrs = []
        if off is not None:
            for k in range(words):
                e = s.mem.get((iadd(esp, I(4 * k)), 4))
                if e is not None and e[0] == "int" and sp_off(e[1]) is not None:
                    ptrs.append((sp_off(e[1]), k))
        ec = s.regs.get("ecx")
        if ec is not None and sp_off(ec) is not None:
            ptrs.append((sp_off(ec), "this"))
        base = name.lstrip("_?").split("@")[0] if name else ""
        m = MATHFN.match(name) if name else None
        fkind = m.group(1).lower() if m else None
        callee = self.local.get(name) if (name and self.depth < 3 and not fkind) else None
        if callee is not None and callee.insns and off is not None and self.shared[0] > len(callee.insns) * 8:
            self.inline(s, callee, esp, off, words)
            self.stats["inlined"] += 1
            nxt = None
            s.dirty = set()
            self.stats["calls"] += 1
            return
        if name and ("ftol" in name):
            v = self.pop(s)
            self.root("cvt", v, ins)
            self.reg_set(s, "eax", cvtatom(v))
            self.reg_set(s, "edx", atom(("call", ("edx", n))))
        elif fkind:
            nargs = 2 if fkind in ("pow", "atan2", "fmod") else 1
            ci = bool(re.match(r"(?i)^_?_?CI", name))
            args = []
            if ci:
                for _ in range(nargs):
                    args.append(self.pop(s))
                args.reverse()
            else:
                a = off
                for _ in range(nargs):
                    e = s.mem.get((iadd(esp, I(a - off)), 8)) if a is not None else None
                    args.append(e[1] if e else self.funk("mathcall_arg"))
                    a = a + 8 if a is not None else None
                words = 0       # the argument words are not a callee-pop count we can trust; fix up below
            if fkind == "sqrt":
                v = mk("sqrt", args[0])
            else:
                v = ("fn", 1 + sum(x[1] for x in args), fkind) + tuple(args)
            self.push(s, v)
            self.stats["mathcalls"] += 1
            self.reg_set(s, "eax", atom(("call", n)))
            if not ci:
                # a cdecl C function: the caller pops (an `add esp` follows) or the double is popped by the callee
                pass
        else:
            self.lastcall = ("call", 1, n)
            self.reg_set(s, "eax", atom(("call", n)))
            if s.st and False:
                pass
        for r in ("ecx", "edx"):
            s.regs[r] = self.uval("call_clob")
        # the callee pops its arguments (known from the callee's own `ret N`; else assumed when no `add esp, N` follows)
        known = callee_pop(target) if target is not None else None
        if fkind or (name and "ftol" in name):
            pass
        elif known is not None:
            if off is not None and known:
                s.regs["esp"] = iadd(esp, I(known))
        elif self.cdecl_default:
            pass
        elif cc_pop(name) == 0:
            pass
        elif isinstance(cc_pop(name), int) and cc_pop(name) and off is not None:
            s.regs["esp"] = iadd(esp, I(cc_pop(name)))
        elif not (nxt is not None and nxt.mnemonic == "add" and nxt.operands and nxt.operands[0].type == X.X86_OP_REG
                  and nxt.operands[0].reg == X.X86_REG_ESP):
            if off is not None and words:
                s.regs["esp"] = iadd(esp, I(4 * words))
        s.dirty = set()
        # forwarded values may have changed
        clob = s.retained | {b for b, _ in ptrs}
        for o in [o for o in s.cout if o in s.retained and o not in {b for b, _ in ptrs}]:
            del s.cout[o]       # a window some earlier call may have kept the address of: unknown after this call
        for c in clob:
            if c > 0:
                s.argdead.update(range(c, c + 16))
        s.mem = {k: v for k, v in s.mem.items() if sp_off(k[0]) is not None
                 and not any(e <= sp_off(k[0]) < e + 16 for e in clob)}
        for b, _ in ptrs:
            self.note_pw(b)
        for b, k in ptrs:
            s.cout[b] = (n, k)
        self.stats["calls"] += 1

    # ---- x87
    def x87(self, s, ins):
        mn = ins.mnemonic
        ops = ins.operands
        if mn in IGNORE:
            if mn in ("fnstcw", "fstcw", "fnsave", "fsave", "fnstenv") and ops and ops[0].type == X.X86_OP_MEM:
                self.note_write(self.opaddr(s, ins, ops[0]), 4)
            if mn in ("fnstsw", "fstsw"):
                self.reg_set(s, "eax", self.uval("fnstsw"))
            return
        self.stats["x87"] += 1
        if mn in ARITH or (mn[:-1] in ARITH and mn.endswith("p")) or (mn[0:2] == "fi" and mn[2:] in ARITH):
            pop = mn.endswith("p") and mn not in ARITH
            base = mn[:-1] if pop else mn
            intform = False
            if base[:2] == "fi" and base[1:] not in ("fist",) and base[2:] in ARITH:
                base, intform = "f" + base[2:], True
            opn, rev = ARITH[base]
            self.stats["arith"] += 1
            if ops and ops[0].type == X.X86_OP_MEM:
                a = self.opaddr(s, ins, ops[0])
                if intform:
                    src = ("fild", 2, self.memload_int(s, a, ops[0].size))
                else:
                    src = self.memload_float(s, a, ops[0].size)
                dst_i, dst = 0, self.sti(s, 0)
            else:
                rg = st_regs(ins)
                if len(rg) == 2:
                    dreg, sreg = rg
                else:
                    r = rg[0] if rg else 1
                    dreg, sreg = (r, 0) if pop else (0, r)
                dst_i, dst, src = dreg, self.sti(s, dreg), self.sti(s, sreg)
            x, y = (src, dst) if rev else (dst, src)
            if opn == "sub" and x == y:
                res = mk("sub", x, y)
            else:
                res = mk(opn, x, y)
            self.set_sti(s, dst_i, res)
            if pop:
                self.pop(s)
            return
        if mn in ("fld", "fild", "fild", "fbld"):
            o = ops[0]
            if mn == "fld":
                if o.type == X.X86_OP_REG:
                    self.push(s, self.sti(s, st_regs(ins)[0]))
                elif o.size in (4, 8):
                    self.push(s, self.memload_float(s, self.opaddr(s, ins, o), o.size))
                else:
                    self.push(s, self.funk("fptan"))
            elif mn == "fild":
                a = self.opaddr(s, ins, o)
                v = None
                if o.size == 8:     # clang: an unsigned int zero-extended to 64 bits
                    lo, hi = s.mem.get((a, 4)), s.mem.get((iadd(a, I(4)), 4))
                    if lo and hi and lo[0] == "int" and hi[0] == "int" and iconst(hi[1]) == 0:
                        v = atom(("u32", lo[1]))
                self.push(s, ("fild", 2, v if v is not None else self.memload_int(s, a, o.size)))
            else:
                self.push(s, self.funk("fld_other"))
            return
        if mn in CONSTS:
            self.push(s, ("c", 1, CONSTS[mn]))
            return
        if mn in ("fst", "fstp"):
            o = ops[0]
            v = self.sti(s, 0)
            if o.type == X.X86_OP_REG:
                self.set_sti(s, st_regs(ins)[0], v)
            elif o.size in (4, 8):
                a = self.opaddr(s, ins, o)
                sv = rnd(v) if o.size == 4 else v
                self.root("store", v, ins)
                self.store(s, a, o.size, "flt", sv)
                off = sp_off(a)
                if off is not None:
                    s.dirty.update((off, off + 4) if o.size == 8 else (off,))
            if mn == "fstp":
                self.pop(s)
            return
        if mn in ("fist", "fistp", "fisttp"):
            v = self.sti(s, 0)
            self.root("cvt", v, ins)
            o = ops[0]
            if o.type == X.X86_OP_MEM:
                a = self.opaddr(s, ins, o)
                self.store(s, a, o.size, "int", cvtatom(v))
                if o.size == 8:
                    s.mem[(a, 4)] = ("int", cvtatom(v))
                off = sp_off(a)
                if off is not None:
                    s.dirty.add(off)
            if mn != "fist":
                self.pop(s)
            return
        if mn == "fxch":
            rg = st_regs(ins)
            i = rg[0] if rg else 1
            a, b = self.sti(s, 0), self.sti(s, i)
            self.set_sti(s, 0, b)
            self.set_sti(s, i, a)
            return
        if mn == "fchs":
            self.set_sti(s, 0, mk("neg", self.sti(s, 0)))
            return
        if mn == "fabs":
            self.set_sti(s, 0, mk("abs", self.sti(s, 0)))
            return
        if mn == "fsqrt":
            self.set_sti(s, 0, mk("sqrt", self.sti(s, 0)))
            return
        if mn in ("fcom", "fcomp", "fcompp", "fucom", "fucomp", "fucompp", "fcomi", "fcomip", "fucomi", "fucomip",
                  "fcompi", "fucompi", "ficom", "ficomp", "ftst"):
            a = self.sti(s, 0)
            if mn == "ftst":
                b = ("c", 1, 0.0)
            elif ops and ops[0].type == X.X86_OP_MEM:
                ad = self.opaddr(s, ins, ops[0])
                b = ("fild", 2, self.memload_int(s, ad, ops[0].size)) if mn.startswith("fi") else \
                    self.memload_float(s, ad, ops[0].size)
            elif ops and ops[-1].type == X.X86_OP_REG:
                b = self.sti(s, st_regs(ins)[-1])
            else:
                b = self.sti(s, 1)
            self.root("cmp", mk("cmp", *sorted((a, b), key=_rk)), ins)
            if mn.endswith("pp"):
                self.pop(s)
                self.pop(s)
            elif mn.endswith("p") or mn in ("fcompi", "fucompi"):
                self.pop(s)
            return
        if mn in UNARY:
            v = self.sti(s, 0)
            self.set_sti(s, 0, ("fn", 1 + v[1], mn[1:], v))
            if mn in ("fptan", "fsincos"):
                self.push(s, self.funk("x87_other"))
            return
        if mn in BINARY:
            a, b = self.sti(s, 0), self.sti(s, 1)
            self.set_sti(s, 1, ("fn", 1 + a[1] + b[1], {"fpatan": "atan2", "fprem": "fmod"}.get(mn, mn[1:]), *((b, a) if mn == "fpatan" else (a, b))))
            self.pop(s)
            return
        # anything else: forget the top
        self.stats["unknown_x87"] += 1
        s.st = [self.funk("x87_other") for _ in s.st]


# ---------------------------------------------------------------------------------------------
_md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
_md.syntax = capstone.CS_OPT_SYNTAX_INTEL
_md.detail = True
_g = {}


def glob():
    if not _g:
        _g["xbe"] = Xbe(XBE_PATH)
        import csv
        names, sizes = {}, {}
        with open(FUNCS_PATH) as f:
            for r in csv.DictReader(f):
                a = int(r["address"], 16)
                names[a] = r["name"]
                sizes[a] = int(r["size"])
        _g["names"], _g["sizes"] = names, sizes
    return _g


_pops = {}


def cc_pop(name):
    """What the symbol's decoration says about who pops the arguments: 0 (cdecl), the byte count (stdcall `_f@N`),
    "callee" (stdcall / thiscall / fastcall of a C++ name: the callee pops what was written), or None."""
    if not name:
        return None
    if name.startswith("?"):
        i = name.find("@@")
        if i < 0:
            return None
        s = name[i + 2:i + 5]
        if len(s) < 2:
            return None
        if s[0] in "YZ":
            c = s[1]
        elif s[0] in "STKL":            # static member
            c = s[1]
        elif s[0] in "QRIJUVAB" and len(s) > 2:
            c = s[2]
        else:
            return None
        return {"A": 0, "B": 0, "E": "callee", "F": "callee", "G": "callee", "H": "callee", "I": "callee",
                "J": "callee"}.get(c)
    if name.startswith("@") and "@" in name[1:]:
        return "callee"
    m = re.match(r"^_.*@(\d+)$", name)
    if m:
        return int(m.group(1))
    return 0 if name.startswith("_") else None


def callee_pop(addr, depth=0):
    """Bytes the function at ADDR pops on return (`ret N`), 0 for a plain ret, None when unknown."""
    if addr in _pops:
        return _pops[addr]
    g = glob()
    res = None
    xbe = g["xbe"]
    o = xbe.offset(addr) if addr is not None else None
    if o is not None and addr in g["sizes"]:
        insns = disasm(xbe.data[o:o + g["sizes"][addr]], addr)
        for i in insns:
            if i.mnemonic == "ret":
                res = i.operands[0].imm if i.operands else 0
                break
        else:
            last = insns[-1] if insns else None
            if last is not None and last.mnemonic == "jmp" and last.operands and last.operands[0].type == X.X86_OP_IMM \
                    and depth < 3:
                res = callee_pop(last.operands[0].imm, depth + 1)
    _pops[addr] = res
    return res


def disasm(code, base):
    return list(_md.disasm(code, base))


def orig_insns(addr):
    g = glob()
    xbe = g["xbe"]
    o = xbe.offset(addr)
    return disasm(xbe.data[o:o + g["sizes"][addr]], addr)


def skeleton(ins, reloc_here):
    out = [ins.mnemonic]
    for op in ins.operands:
        if op.type == X.X86_OP_REG:
            out.append(("r", op.reg))
        elif op.type == X.X86_OP_IMM:
            out.append(("i", "G" if (reloc_here or op.imm >= 0x10000 and ins.group(capstone.CS_GRP_CALL)) else
                        (op.imm if op.imm < 0x10000 else "G")))
        else:
            m = op.mem
            out.append(("m", m.base, m.index, m.scale, "G" if (reloc_here or m.disp >= 0x10000) else m.disp, op.size))
    return tuple(out)


class ObjFn:
    """A function of a COFF object: instructions, relocation map."""

    def __init__(self, coff, sym):
        name, code, _ = coff.function(sym)
        code = code.rstrip(b"\xcc")
        self.name = name
        self.code = code
        self.insns = disasm(code, 0)
        self.relocs = {}
        for off, tsym, typ, addend in coff.function_relocs(sym):
            if tsym is not None and off < len(code):
                self.relocs[off] = (tsym[0], typ)
        # instruction address -> (symbol, field offset in the instruction)
        self.reloc_at = {}
        for ins in self.insns:
            for off, (nm, typ) in self.relocs.items():
                if ins.address <= off < ins.address + ins.size:
                    self.reloc_at[ins.address] = (nm, off - ins.address)


def bind_symbols(orig, objfn, explicit=None):
    """Map the object's symbols to addresses by aligning its instructions with the original's."""
    bind = dict(explicit or {})
    sk_o = [skeleton(i, False) for i in orig]
    sk_m = [skeleton(i, i.address in objfn.reloc_at) for i in objfn.insns]
    sm = difflib.SequenceMatcher(None, sk_m, sk_o, autojunk=False)
    for tag, a0, a1, b0, b1 in sm.get_opcodes():
        if tag != "equal":
            continue
        for k in range(a1 - a0):
            mi, oi = objfn.insns[a0 + k], orig[b0 + k]
            rel = objfn.reloc_at.get(mi.address)
            if rel is None:
                continue
            nm, foff = rel
            val = None
            if mi.group(capstone.CS_GRP_CALL) or mi.group(capstone.CS_GRP_JUMP):
                if oi.operands and oi.operands[0].type == X.X86_OP_IMM:
                    val = oi.operands[0].imm
            elif foff == mi.disp_offset and foff:
                for op_m, op_o in zip(mi.operands, oi.operands):
                    if op_m.type == X.X86_OP_MEM:
                        val = op_o.mem.disp - op_m.mem.disp
            elif foff == mi.imm_offset and foff:
                for op_m, op_o in zip(mi.operands, oi.operands):
                    if op_m.type == X.X86_OP_IMM:
                        val = op_o.imm - op_m.imm
            if val is not None:
                bind.setdefault(nm, val & 0xFFFFFFFF)
    return bind


def has_x87_arith(insns, minimum=2):
    n = 0
    for i in insns:
        m = i.mnemonic
        if m[0] == "f" and (m[1:4] in ("add", "sub", "mul", "div") or m[1:5] in ("sqrt",) or m[1:3] == "ch"
                            or m[2:5] in ("add", "sub", "mul", "div")):
            n += 1
    return n >= minimum


def bind_names(bind):
    """address -> name for the original's call targets, from the object's symbols (better than FUN_xxxx)."""
    g = glob()
    names = dict(g["names"])
    for nm, a in bind.items():
        if not nm.startswith("__real@") and not nm.startswith("??_C@"):
            names[a] = nm
    return names


def own_conv(src, addr):
    """The `// equiv-conv: FUN_<addr> loc...` line of the function under test (where the original takes its
    parameters, in the source's parameter order), or None."""
    try:
        for line in open(src, errors="replace"):
            m = re.match(r"\s*//\s*equiv-conv:\s*(\S+)\s+(.+?)\s*$", line)
            if m:
                nm = NAME_ADDR.search(" " + m.group(1))
                if (nm and int(nm.group(1), 16) == addr) or re.fullmatch(r"(0x)?0*%x" % addr, m.group(1).lower()):
                    return m.group(2).split()
    except OSError:
        pass
    return None


def run_side(insns, side, bind=None, objfn=None, names=None, local=None, conv=None):
    g = glob()
    sim = Sim(insns, side, bind=bind, xbe=g["xbe"], names=(names or g["names"]) if objfn is None else None)
    if objfn is not None:
        sim.reloc_at = objfn.reloc_at
    sim.local = local or {}
    regs = {}
    if conv:        # the original takes parameter i in a register or the next stack word; the source: stack word i
        j = 0
        for i, loc in enumerate(conv):
            if loc == "stack":
                sim.argmap[4 + 4 * j] = 4 + 4 * i
                j += 1
            elif loc in REG32:
                regs[REG32[loc]] = atom(("arg", 4 + 4 * i))
    roots = sim.run(regs)
    return roots, sim


# ---------------------------------------------------------------------------------------------
_fu = {}
_szc = {}


def _isz(x):
    """Number of tuples in a nested tuple (memoised by identity)."""
    if not isinstance(x, tuple):
        return 0
    e = _szc.get(id(x))
    if e is not None and e[0] is x:
        return e[1]
    r = 1 + sum(_isz(y) for y in x if isinstance(y, tuple))
    _szc[id(x)] = (x, r)
    return r


def _find_u(x):
    """The first unknown atom ("u", side, n, why) inside a nested tuple, or None (memoised by identity)."""
    if not isinstance(x, tuple):
        return None
    e = _fu.get(id(x))
    if e is not None and e[0] is x:
        return e[1]
    if len(x) == 4 and x[0] == "u" and isinstance(x[1], str):
        r = x
    else:
        r = None
        for k in x:
            if isinstance(k, tuple):
                r = _find_u(k)
                if r is not None:
                    break
    _fu[id(x)] = (x, r)
    return r


def why_unmatched(n, sig, nocand):
    """Why an original root has no counterpart (a short tag; the scan's unmatched breakdown)."""
    out = []
    leaves(strip_rnd(n), out)
    for l in out:
        if l[0] == "unk":
            return "unk:" + (l[2][3] if len(l[2]) > 3 else "?")
    for l in out:
        if l[0] in ("ld", "fild"):
            u = _find_u(l)
            if u is not None:
                return "addr:" + u[3]
    if sig is None:
        return "unk:big"
    if any(l[0] == "call" for l in out):
        return "call_leaf" if nocand else "call_subroot"
    return "no_counterpart" if nocand else "subroot"


def nearest(sig, S, kind):
    """The root of S whose leaves overlap SIG most (diagnostics for the unmatched breakdown); roots with an unknown
    leaf count too (their known leaves)."""
    best, bs = None, 0.0
    a = Counter(sig)
    for r in S:
        lv = []
        leaves(r[2], lv)
        b = Counter(repr(l) for l in lv if l[0] != "unk" and not (l[0] == "c" and l[2] == 1.0))
        if not b:
            continue
        inter = sum((a & b).values())
        sc = inter / max(1, sum((a | b).values()))
        if sc > bs:
            best, bs = r, sc
    return None if best is None else (round(bs, 2), show(best[2])[:240])


def expand_phi(sn):
    """The trees a root splits into when a branch join was compared or stored after the arms (MSVC duplicates the
    compare into each arm; clang compares once after the join): the arms of a top-level phi, or of a phi operand of a
    compare. None when there is no such phi."""
    if sn[0] == "phi":
        return list(sn[2:])
    if sn[0] == "cmp":
        for i in (2, 3):
            if sn[i][0] == "phi":
                other = sn[5 - i]
                return [mk("cmp", other, arm) for arm in sn[i][2:]]
    return None


def has_phi(n, memo):
    r = memo.get(n)
    if r is None:
        r = memo[n] = n[0] == "phi" or (n[0] in _RKOPS or n[0] == "fn") and any(
            has_phi(k, memo) for k in (n[3:] if n[0] == "fn" else n[2:]))
    return r


def distribute(n, memo, cap=16):
    """The phi-free alternatives of a tree (a phi chooses one arm; the rest of the tree is the same on each path), or
    None when there are more than CAP. Two trees that differ only in where the branches were joined have the same set."""
    if not has_phi(n, memo):
        return [n]
    if n[0] == "phi":
        out = []
        for arm in n[2:]:
            a = distribute(arm, memo, cap)
            if a is None:
                return None
            out.extend(a)
        return out if len(set(out)) <= cap else None
    kids = n[3:] if n[0] == "fn" else n[2:]
    alts = [[]]
    for k in kids:
        ka = distribute(k, memo, cap)
        if ka is None or len(alts) * len(ka) > cap * 4:
            return None
        alts = [x + [y] for x in alts for y in ka]
    if n[0] == "fn":
        res = [("fn", 1 + sum(k[1] for k in c), n[2]) + tuple(c) for c in alts]
    else:
        res = [mk(n[0], *c) for c in alts]
    return res if len(set(res)) <= cap else None


def compare_roots(oroots, sroots, why=None, near=None):
    """Per distinct original root: (status, orig tree, src tree|None). Status: clean|assoc|recip|round|other|unmatched.
    WHY (a dict, optional) receives root offset -> reason tag for the unmatched ones."""
    memo = {}
    def prep(roots):
        seen, out = set(), []
        for kind, n, at in roots:
            while n[0] == "rnd":
                n = n[2]
            key = (kind, n)
            if key in seen:
                continue
            seen.add(key)
            sn = strip_rnd(n, memo)
            out.append((kind, n, sn, signature(n), at))
        return out
    O, S = prep(oroots), prep(sroots)
    ext = []        # the split forms of the other side's roots are candidates too
    pm0 = {}
    for r in S:
        parts = distribute(r[2], pm0) if has_phi(r[2], pm0) else None
        if parts and 1 < len(parts) <= 8:
            ext.extend((r[0], part, part, signature(part), r[4]) for part in parts)
    S = S + ext
    bysig = {}
    for r in S:
        if r[3] is not None:
            bysig.setdefault(r[3], []).append(r)
    res = []
    done = set()
    o_sn = {r[2] for r in O}
    s_sn = {r[2] for r in S}
    for kind, n, sn, sig, at in O:
        if sn in done:
            continue
        done.add(sn)
        if sig is None:
            res.append(("unmatched", n, None, at))
            if why is not None:
                why[n] = why_unmatched(n, sig, True)
            continue
        cands = bysig.get(sig, [])
        cands = [c for c in cands if c[0] == kind or kind in ("store", "ret") and c[0] in ("store", "ret")]
        if not cands:
            res.append(("unmatched", n, None, at))
            if why is not None:
                why[n] = why_unmatched(n, sig, True)
            if near is not None:
                near[n] = nearest(sig, S, kind)
            continue
        if any(c[2] == sn and (c[1] == n) for c in cands):
            res.append(("clean", n, None, at))
            continue
        if any(c[2] == sn for c in cands):
            c = next(c for c in cands if c[2] == sn)
            res.append(("round", n, c[1], at))
            continue
        # No root of the other side is the same tree. A finding needs a unique counterpart of the closest kind of
        # difference (a symmetric computation repeats the same leaves in other statements, and the same value is often
        # stored again with a constant added).
        pool_s = [c for c in cands if c[2] not in o_sn]
        pool_o = [r for r in O if r[3] == sig and r[2] not in s_sn and (r[0] == kind or kind in ("store", "ret")
                                                                         and r[0] in ("store", "ret"))]
        st, c = "unmatched", None
        for tier, key in (("assoc", lambda m: flat(m, True)), ("recip", lambda m: flat(m)),
                          ("other", lambda m: tuple(sorted(opcount(m).items())))):
            ks = key(sn)
            ms = {x[2]: x for x in pool_s if key(x[2]) == ks}
            if ms:
                mo = {x[2] for x in pool_o if key(x[2]) == ks}
                if len(ms) == 1 and len(mo) == 1:
                    st, c = tier, next(iter(ms.values()))
                else:
                    st = "ambiguous"
                break
        if st == "ambiguous":
            res.append(("unmatched", n, None, at))
            if why is not None:
                why[n] = "ambiguous"
            continue
        if st == "unmatched" and why is not None:
            why[n] = why_unmatched(n, sig, False)       # a sub-root of the other side's tree (a sqrt, a phi around it)
        res.append((st, n, None if c is None else c[1], at))
    # an original root that is a phi / a compare of a phi, whose arms the other side has as separate roots
    pm = {}
    s_alts = None
    for k, (st, n, c, at) in enumerate(res):
        if st == "unmatched":
            sn_ = strip_rnd(n, memo)
            parts = expand_phi(sn_)
            if parts and len(parts) <= 4 and all(p_ in s_sn for p_ in parts):
                res[k] = ("clean", n, None, at)
                continue
            if has_phi(sn_, pm):        # the same alternatives with the branches joined at another place
                alts = distribute(sn_, pm)
                if alts and len(alts) > 1 and all(a_ in s_sn for a_ in alts):
                    res[k] = ("clean", n, None, at)
                    continue
                if alts and len(alts) > 1:
                    if s_alts is None:
                        s_alts = {}
                        for r_ in S:
                            if has_phi(r_[2], pm):
                                al = distribute(r_[2], pm)
                                if al and len(al) > 1:
                                    s_alts.setdefault(frozenset(al), r_)
                    if frozenset(alts) in s_alts:
                        res[k] = ("clean", n, None, at)
    return res


def pick_obj_fn(coff, orig, bind_explicit, orig_roots, native):
    """The object's function that corresponds to the original: best skeleton similarity."""
    best = None
    sk_o = [skeleton(i, False) for i in orig]
    for sym in coff.function_symbols():
        try:
            f = ObjFn(coff, sym)
        except Exception:
            continue
        if not f.insns:
            continue
        sk_m = [skeleton(i, i.address in f.reloc_at) for i in f.insns]
        score = difflib.SequenceMatcher(None, sk_m, sk_o, autojunk=False).ratio() if not native else None
        if best is None or (score is not None and score > best[0]):
            best = (score, f, sym)
        if not native and score is not None and score == 1.0:
            break
    return best


NAME_ADDR = re.compile(r"(?:^|[^0-9A-Za-z])(?:DAT|FUN)_(00[0-9a-fA-F]{6})(?![0-9A-Za-z])")


def is_equivalent_src(src):
    try:
        with open(src, errors="replace") as f:
            return f.readline().lstrip().startswith("// STATUS:")
    except OSError:
        return False


def explicit_binds(src, names=()):
    """Symbols bound by the source's `// equiv-map: name = 0xADDR` lines and, for an equivalent/ source (tools/
    wine_link.py takes equiv.py's binding: explicit lines, then names), by their `DAT_<addr>`/`FUN_<addr>` names.
    A matches/ source is bound by position (the MSVC object's relocations), whatever its names say."""
    out = {}
    if names:
        for nm in names:
            m = NAME_ADDR.search(nm)
            if m:
                out[nm] = int(m.group(1), 16)
    try:
        for line in open(src, errors="replace"):
            m = re.match(r"\s*//\s*equiv-map:\s*(\S+)\s*=\s*(0x[0-9a-fA-F]+)", line)
            if m:
                out[m.group(1)] = int(m.group(2), 16)
    except OSError:
        pass
    return out


LAST = {}      # debugging: the last analyze()'s root lists and instructions


def analyze(src, addr, msvc=True, native=True, workdir=None):
    """Full check of SRC against the original at ADDR. Returns a report dict."""
    import compare
    import equiv
    g = glob()
    _kc.clear()
    _fu.clear()
    _szc.clear()
    _intern.clear()
    _cache.clear()
    rep = {"addr": "0x%08x" % addr, "src": src}
    if addr not in g["sizes"]:
        rep["status"] = "no_function"
        return rep
    orig = orig_insns(addr)
    if not has_x87_arith(orig):
        rep["status"] = "no_x87"
        return rep
    oroots = None
    own = tempfile.TemporaryDirectory(dir=workdir)
    tmp = own.name
    try:
        mf = None
        bind = explicit_binds(src)
        results = {}
        by_name = is_equivalent_src(src)
        if msvc or native:
            try:
                mobj = compare.compile_obj(src, compare.DEFAULT_FLAGS, tmp)
                mcoff = compare.Coff(mobj)
                best = pick_obj_fn(mcoff, orig, bind, None, False)
                if best is not None:
                    mf = best[1]
                    rep["msvc_similarity"] = round(best[0], 3)
                    if by_name:
                        bind = explicit_binds(src, [s[0] for s in mcoff.symbols])
                    bind = bind_symbols(orig, mf, bind)
                    if not by_name:
                        conf = []
                        for nm, a in bind.items():
                            m = NAME_ADDR.search(nm)
                            if m and int(m.group(1), 16) != a:
                                conf.append([nm, "0x%08x" % a])
                        if conf:
                            rep["bind_name_conflicts"] = conf      # position says another address than the name
                oroots, osim = run_side(orig, "o", names=bind_names(bind), conv=own_conv(src, addr))
                LAST["orig"] = (oroots, orig)
                rep["orig_roots"] = len(oroots)
                rep["orig_generic"] = len(osim.roots_gen)
                rep["orig_calls"] = osim.ncall
                if best is not None:
                    if msvc:
                        mroots, msim = run_side(mf.insns, "m", bind, mf)
                        results["msvc"] = compare_roots(oroots, mroots)
                        rep["msvc_roots"] = len(mroots)
            except compare.CompileError as e:
                rep["msvc_error"] = str(e)[:200]
        if oroots is None:
            oroots, osim = run_side(orig, "o", names=bind_names(bind), conv=own_conv(src, addr))
            rep["orig_roots"] = len(oroots)
            rep["orig_calls"] = osim.ncall
        if native:
            try:
                nobj = equiv.compile_native(src, tmp)
                ncoff = compare.Coff(nobj)
                cands = []
                local = {}
                for sym in ncoff.function_symbols():
                    try:
                        local[sym[0]] = ObjFn(ncoff, sym)
                    except Exception:
                        pass
                for f in local.values():
                    if not f.insns:
                        continue
                    roots, sim = run_side(f.insns, "n", bind, f, local=local)
                    why = {}
                    near = {}
                    res = compare_roots(oroots, roots, why, near)
                    score = sum(1 for r in res if r[0] != "unmatched")
                    cands.append((score, len(f.insns), f, roots, res, why, near))
                if cands:
                    cands.sort(key=lambda c: (-c[0], -c[1]))
                    LAST["native"] = (cands[0][3], cands[0][2])
                    LAST["bind"] = bind
                    rep["native_fn"] = cands[0][2].name
                    rep["native_roots"] = len(cands[0][3])
                    results["native"] = cands[0][4]
                    rep["unmatched_why"] = dict(Counter(cands[0][5].values()))
                    rep["unmatched_roots"] = [["+0x%x" % at, w, show(n)[:240], cands[0][6].get(n)] for st_, n, _, at in cands[0][4]
                                              if st_ == "unmatched" for w in (cands[0][5].get(n, "?"),)][:12]
                else:
                    rep["native_error"] = "no function in the clang object"
            except compare.CompileError as e:
                rep["native_error"] = str(e)[:200]
    finally:
        own.cleanup()
    # per original root: native and msvc status
    nat = results.get("native")
    ms = results.get("msvc")
    stat = Counter()
    findings = []
    if nat is not None:
        mdict = {r[1]: r for r in ms} if ms else {}
        for st, n, sn_, at in nat:
            stat[st] += 1
            if st in ("clean", "unmatched"):
                continue
            mst = mdict.get(n)
            msv = mst[0] if mst else None
            if msv is None:
                cls = "unknown_msvc"
            elif msv == "clean":
                cls = "native_only"         # MSVC reassociated it: the source text's order is wrong for native
            elif msv == "unmatched":
                cls = "msvc_unmatched"
            else:
                cls = "src_differs"         # the source differs from the original even under MSVC
            findings.append({"kind": st, "class": cls, "msvc": msv, "at": "+0x%x" % at,
                             "orig": show(n), "src": show(sn_) if sn_ else None,
                             "diff": "orig %s vs src %s" % (show(n), show(sn_)) if sn_ else show(n)})
    if ms is not None and nat is None:
        for st, n, sn_, at in ms:
            stat["msvc_" + st] += 1
    rep["stats"] = dict(stat)
    rep["msvc_stats"] = dict(Counter(r[0] for r in ms)) if ms else None
    rep["findings"] = findings
    rep["status"] = "finding" if any(f["kind"] != "round" for f in findings) else (
        "round_only" if findings else ("clean" if stat.get("clean") else "unmatched"))
    return rep


def synth_compare(src, ref="ref", test="test", ref_msvc=False, workdir=None):
    """Test helper: compile SRC (clang native flags, and MSVC for REF when REF_MSVC) and compare the roots of the C
    function REF (playing the original) with those of TEST. No game files needed. Returns compare_roots()'s list."""
    import compare
    import equiv
    with tempfile.TemporaryDirectory(dir=workdir) as tmp:
        nobj = equiv.compile_native(src, tmp)
        ncoff = compare.Coff(nobj)
        nfns = {}
        for sym in ncoff.function_symbols():
            try:
                nfns[sym[0]] = ObjFn(ncoff, sym)
            except Exception:
                pass
        if ref_msvc:
            mcoff = compare.Coff(compare.compile_obj(src, compare.DEFAULT_FLAGS, tmp))
            rfns = {}
            for sym in mcoff.function_symbols():
                try:
                    rfns[sym[0]] = ObjFn(mcoff, sym)
                except Exception:
                    pass
        else:
            rfns = nfns

        def run(f, fns, side):
            sim = Sim(f.insns, side, bind={}, xbe=None, names={})
            sim.cdecl_default = True
            sim.reloc_at = f.reloc_at
            sim.local = fns
            return sim.run(), sim
        rf, tf = rfns["_" + ref], nfns["_" + test]
        oroots, _ = run(rf, rfns, "o")
        sroots, _ = run(tf, nfns, "n")
        why = {}
        res = compare_roots(oroots, sroots, why)
        return res, why


def addr_of(path):
    m = re.search(r"0x([0-9a-fA-F]{6,8})", os.path.basename(path))
    return int(m.group(1), 16) if m else None


class Timeout(Exception):
    pass


def _alarm(sig, frm):
    raise Timeout()


def _job(args):
    import signal
    path, addr, msvc = args
    try:
        signal.signal(signal.SIGALRM, _alarm)
        signal.alarm(240)
        try:
            return analyze(path, addr, msvc=msvc)
        finally:
            signal.alarm(0)
    except Timeout:
        return {"addr": "0x%08x" % addr, "src": path, "status": "error", "error": "timeout"}
    except Exception as e:  # noqa: BLE001
        import traceback
        return {"addr": "0x%08x" % addr, "src": path, "status": "error", "error": "%s: %s" % (type(e).__name__, e),
                "trace": traceback.format_exc()[-600:]}


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", nargs="?")
    ap.add_argument("addr", nargs="?")
    ap.add_argument("--list", help="file with one source path per line")
    ap.add_argument("--no-msvc", action="store_true", help="skip the MSVC object comparison")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--out", help="write one JSON line per source here (with --list)")
    ap.add_argument("--jobs", type=int, default=1)
    a = ap.parse_args()
    jobs = []
    if a.list:
        for line in open(a.list):
            p = line.strip()
            if p and addr_of(p) is not None:
                jobs.append((p, addr_of(p), not a.no_msvc))
    elif a.src:
        addr = int(a.addr, 16) if a.addr else addr_of(a.src)
        if addr is None:
            ap.error("address needed")
        jobs.append((a.src, addr, not a.no_msvc))
    else:
        ap.error("source or --list needed")
    if a.jobs > 1 and len(jobs) > 1:
        from multiprocessing import Pool
        with Pool(a.jobs) as p:
            it = p.imap(_job, jobs, chunksize=4)
            reps = list(_progress(it, len(jobs), a.out))
    else:
        reps = list(_progress(map(_job, jobs), len(jobs), a.out))
    if a.json and not a.out:
        print(json.dumps(reps if len(reps) > 1 else reps[0], indent=1))
        return 0
    for r in reps:
        print("%s %-10s %s" % (r["addr"], r["status"], r["src"]))
        for f in r.get("findings", []):
            print("   %-6s %-12s %s  %s" % (f["kind"], f["class"], f["at"], f["diff"]))
        if r.get("error"):
            print("   error:", r["error"])
    return 1 if any(r["status"] == "finding" for r in reps) else 0


def _progress(it, n, out):
    fo = open(out, "w") if out else None
    for k, r in enumerate(it):
        if fo:
            fo.write(json.dumps(r) + "\n")
            fo.flush()
            if k % 50 == 0:
                print("%d/%d" % (k, n), file=sys.stderr, flush=True)
        yield r


if __name__ == "__main__":
    sys.exit(main())
