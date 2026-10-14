#!/usr/bin/env python3
"""Lua bytecode reader/lister for The Incredible Hulk: Ultimate Destruction.

The game embeds a Lua 5.0-derived VM.  Compiled chunks have this header:

    1B 4C 75 61   signature "\\x1bLua"
    51            version byte (0x51 -- the game's build says 5.1 but the body
                  layout and opcode set are those of Lua 5.0.x)
    01            endianness (1 = little)
    04 04 04      sizeof(int), sizeof(size_t), sizeof(Instruction)
    04            sizeof(lua_Number)  -> 4-byte float
    3B AF EF 4B   test number (31415926.0 as a float)

Unlike stock 5.0 there are no SIZE_OP/SIZE_A/SIZE_B/SIZE_C bytes; the
instruction layout is the stock 5.0 one (op:6, C:9, B:9, A:8; Bx:18).
Function layout (5.0 order): source, linedefined, nups, numparams, is_vararg,
maxstacksize, lineinfo[], locvars[], upvalue names[], constants[], protos[],
code[].

Usage:
    tools/luac_list.py FILE...            # luac -l style listing to stdout
    tools/luac_list.py --check DIR        # parse every bytecode file under DIR,
                                          # verify no leftover bytes, print summary
    tools/luac_list.py --stats DIR        # opcode histogram over all chunks
    tools/luac_list.py --out OUTDIR DIR   # write one .lst per bytecode file
                                          # (and one per .fig holding embedded chunks)

Written from the public Lua 5.0 format specification.  Listings contain game
content: keep them under build/lua/ (gitignored), never commit them.
"""
import os
import struct
import sys

OPS = [
    # name, mode  (A=iABC, Bx=iABx, sBx=iAsBx)
    ("MOVE", "ABC"), ("LOADK", "ABx"), ("LOADBOOL", "ABC"), ("LOADNIL", "ABC"),
    ("GETUPVAL", "ABC"), ("GETGLOBAL", "ABx"), ("GETTABLE", "ABC"),
    ("SETGLOBAL", "ABx"), ("SETUPVAL", "ABC"), ("SETTABLE", "ABC"),
    ("NEWTABLE", "ABC"), ("SELF", "ABC"), ("ADD", "ABC"), ("SUB", "ABC"),
    ("MUL", "ABC"), ("DIV", "ABC"), ("POW", "ABC"), ("UNM", "ABC"),
    ("NOT", "ABC"), ("CONCAT", "ABC"), ("JMP", "sBx"), ("EQ", "ABC"),
    ("LT", "ABC"), ("LE", "ABC"), ("TEST", "ABC"), ("CALL", "ABC"),
    ("TAILCALL", "ABC"), ("RETURN", "ABC"), ("FORLOOP", "sBx"),
    ("FORPREP", "sBx"), ("TFORLOOP", "ABC"), ("TFORPREP", "sBx"), ("SETLIST", "ABx"),
    ("SETLISTO", "ABx"), ("CLOSE", "ABC"), ("CLOSURE", "ABx"),
]
SIZE_OP, SIZE_C, SIZE_B, SIZE_A = 6, 9, 9, 8
POS_C = SIZE_OP
POS_B = POS_C + SIZE_C
POS_A = POS_B + SIZE_B
MAXARG_Bx = (1 << 18) - 1
MAXARG_sBx = MAXARG_Bx >> 1
MAXSTACK = 250  # RK operands >= this index the constant table (idx = x - 250)

# which operands are RK
RK_B = {"GETTABLE_B_NO"}  # (placeholder; B is a register for GETTABLE)
# 5.0: SETTABLE B,C RK; SELF C RK; arithmetic B,C RK; EQ/LT/LE B,C RK; GETTABLE C RK
RK_OPS_B = {"SETTABLE", "ADD", "SUB", "MUL", "DIV", "POW", "EQ", "LT", "LE"}
RK_OPS_C = {"GETTABLE", "SETTABLE", "SELF", "ADD", "SUB", "MUL", "DIV", "POW",
            "EQ", "LT", "LE"}


class LuaError(Exception):
    pass


class Reader:
    def __init__(self, data):
        self.d = data
        self.p = 0

    def need(self, n):
        if self.p + n > len(self.d):
            raise LuaError("truncated at 0x%x" % self.p)

    def byte(self):
        self.need(1)
        v = self.d[self.p]
        self.p += 1
        return v

    def u32(self):
        self.need(4)
        v = struct.unpack_from("<I", self.d, self.p)[0]
        self.p += 4
        return v

    def f32(self):
        self.need(4)
        v = struct.unpack_from("<f", self.d, self.p)[0]
        self.p += 4
        return v

    def string(self):
        n = self.u32()
        if n == 0:
            return None
        self.need(n)
        s = self.d[self.p:self.p + n]
        self.p += n
        if s[-1:] != b"\0":
            raise LuaError("string not NUL terminated at 0x%x" % self.p)
        return s[:-1]


class Func:
    pass


def load_function(r, depth=0):
    f = Func()
    f.source = r.string()
    f.linedefined = r.u32()
    f.nups = r.byte()
    f.numparams = r.byte()
    f.is_vararg = r.byte()
    f.maxstack = r.byte()
    n = r.u32()
    f.lineinfo = [r.u32() for _ in range(n)]
    n = r.u32()
    f.locvars = []
    for _ in range(n):
        name = r.string()
        f.locvars.append((name, r.u32(), r.u32()))
    n = r.u32()
    f.upvalues = [r.string() for _ in range(n)]
    n = r.u32()
    f.k = []
    for _ in range(n):
        t = r.byte()
        if t == 4:
            f.k.append(("s", r.string()))
        elif t == 3:
            f.k.append(("n", r.f32()))
        elif t == 0:
            f.k.append(("nil", None))
        else:
            raise LuaError("bad constant type %d at 0x%x" % (t, r.p))
    n = r.u32()
    f.protos = [load_function(r, depth + 1) for _ in range(n)]
    n = r.u32()
    f.code = [r.u32() for _ in range(n)]
    return f


def load_chunk_at(data, off=0):
    """Parse one chunk starting at data[off]; returns (header, func, end)."""
    r = Reader(data)
    if data[off:off + 4] != b"\x1bLua":
        raise LuaError("not a Lua bytecode chunk")
    r.p = off + 4
    hdr = {}
    hdr["version"] = r.byte()
    hdr["endian"] = r.byte()
    hdr["sizeof_int"] = r.byte()
    hdr["sizeof_size_t"] = r.byte()
    hdr["sizeof_instr"] = r.byte()
    hdr["sizeof_number"] = r.byte()
    if (hdr["endian"], hdr["sizeof_int"], hdr["sizeof_size_t"],
            hdr["sizeof_instr"], hdr["sizeof_number"]) != (1, 4, 4, 4, 4):
        raise LuaError("unexpected header %r" % hdr)
    hdr["test_number"] = r.f32()
    if hdr["test_number"] != 31415926.0:
        raise LuaError("bad test number %r" % hdr["test_number"])
    fn = load_function(r)
    return hdr, fn, r.p


def load_chunk(data):
    """Parse a whole file that is exactly one chunk (no trailing bytes)."""
    hdr, fn, end = load_chunk_at(data, 0)
    if end != len(data):
        raise LuaError("%d leftover bytes" % (len(data) - end))
    return hdr, fn


def iter_embedded(data):
    """Yield (offset, header, func) for each chunk embedded in a container
    file (the .fig 'fig0' containers hold many back to back)."""
    i = data.find(b"\x1bLua")
    while i >= 0:
        hdr, fn, end = load_chunk_at(data, i)
        yield i, hdr, fn
        i = data.find(b"\x1bLua", end)


def decode(ins):
    op = ins & 0x3F
    a = (ins >> POS_A) & 0xFF
    b = (ins >> POS_B) & 0x1FF
    c = (ins >> POS_C) & 0x1FF
    bx = (ins >> POS_C) & MAXARG_Bx
    return op, a, b, c, bx


def kstr(f, i):
    if i >= len(f.k):
        return "?K%d" % i
    t, v = f.k[i]
    if t == "s":
        return '"%s"' % v.decode("latin-1").replace("\n", "\\n")
    if t == "n":
        return "%.9g" % v
    return "nil"


def rk(f, x):
    return kstr(f, x - MAXSTACK) if x >= MAXSTACK else "R%d" % x


def format_func(f, name="main", out=None):
    out = out if out is not None else []
    src = f.source.decode("latin-1") if f.source else "=?"
    out.append("\n%s <%s:%d> (%d instructions)" % (name, src, f.linedefined, len(f.code)))
    out.append("%d%s params, %d stack, %d upvalues, %d locals, %d constants, %d functions" % (
        f.numparams, "+" if f.is_vararg else "", f.maxstack, f.nups,
        len(f.locvars), len(f.k), len(f.protos)))
    for pc, ins in enumerate(f.code):
        op, a, b, c, bx = decode(ins)
        if op >= len(OPS):
            out.append("\t%d\t[%s]\tBADOP%d\t%d %d %d" % (
                pc + 1, f.lineinfo[pc] if pc < len(f.lineinfo) else "-", op, a, b, c))
            continue
        nm, mode = OPS[op]
        line = f.lineinfo[pc] if pc < len(f.lineinfo) else "-"
        cm = ""
        if mode == "ABC":
            if nm in ("MOVE", "LOADNIL", "GETUPVAL", "SETUPVAL", "UNM", "NOT", "RETURN"):
                args = "%d %d" % (a, b)
            elif nm == "CLOSE":
                args = "%d" % a
            elif nm == "TFORLOOP":
                args = "%d %d" % (a, c)
            else:
                args = "%d %d %d" % (a, b, c)
            if nm in RK_OPS_B and b >= MAXSTACK:
                cm += " " + kstr(f, b - MAXSTACK)
            if nm in RK_OPS_C and c >= MAXSTACK:
                cm += " " + kstr(f, c - MAXSTACK)
            if nm in ("GETUPVAL", "SETUPVAL") and b < len(f.upvalues) and f.upvalues[b]:
                cm += " ; " + f.upvalues[b].decode("latin-1")
        elif mode == "ABx":
            args = "%d %d" % (a, bx)
            if nm in ("LOADK", "GETGLOBAL", "SETGLOBAL"):
                cm = " ; " + kstr(f, bx)
        else:
            sbx = bx - MAXARG_sBx
            if nm == "JMP":
                args = "%d" % sbx
            else:
                args = "%d %d" % (a, sbx)
            cm = " ; to %d" % (pc + 1 + sbx + 1)
        out.append("\t%d\t[%s]\t%s\t%s%s" % (pc + 1, line, nm, args, cm.replace(" ; ", "\t; ") if cm.startswith(" ;") else cm))
    for i, v in enumerate(f.locvars):
        out.append("local %d: %s (pc %d-%d)" % (i, v[0].decode("latin-1") if v[0] else "?", v[1], v[2]))
    for i, p in enumerate(f.protos):
        format_func(p, "function[%d]" % i, out)
    return out


def walk(f):
    yield f
    for p in f.protos:
        yield from walk(p)


def validate(f):
    """Sanity checks that catch a wrong opcode table / RK split."""
    problems = []
    for pc, ins in enumerate(f.code):
        op, a, b, c, bx = decode(ins)
        if op >= len(OPS):
            problems.append("bad opcode %d at pc %d" % (op, pc))
            continue
        nm, mode = OPS[op]
        if nm in ("GETGLOBAL", "SETGLOBAL"):
            if bx >= len(f.k) or f.k[bx][0] != "s":
                problems.append("%s non-string const at pc %d" % (nm, pc))
        elif nm == "LOADK" and bx >= len(f.k):
            problems.append("LOADK out of range at pc %d" % pc)
        elif nm == "CLOSURE" and bx >= len(f.protos):
            problems.append("CLOSURE out of range at pc %d" % pc)
        if nm in RK_OPS_C and c >= MAXSTACK and c - MAXSTACK >= len(f.k):
            problems.append("RK(C) out of range at pc %d" % pc)
        if nm in RK_OPS_B and b >= MAXSTACK and b - MAXSTACK >= len(f.k):
            problems.append("RK(B) out of range at pc %d" % pc)
    if f.lineinfo and len(f.lineinfo) != len(f.code):
        problems.append("lineinfo size %d != code size %d" % (len(f.lineinfo), len(f.code)))
    return problems


def find_bytecode(root):
    for dp, _, fns in os.walk(root):
        for fn in sorted(fns):
            p = os.path.join(dp, fn)
            try:
                with open(p, "rb") as fh:
                    if fh.read(4) == b"\x1bLua":
                        yield p
            except OSError:
                pass


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    if argv[1] == "--check":
        ok = bad = 0
        nfunc = ninstr = 0
        hdrs = set()
        for p in sorted(find_bytecode(argv[2])):
            try:
                hdr, fn = load_chunk(open(p, "rb").read())
                probs = []
                for g in walk(fn):
                    nfunc += 1
                    ninstr += len(g.code)
                    probs += validate(g)
                if probs:
                    raise LuaError("; ".join(probs[:3]))
                hdrs.add(tuple(sorted(hdr.items())))
                ok += 1
            except LuaError as e:
                bad += 1
                print("FAIL", p, e)
        emb = embf = 0
        for dp, _, fns in os.walk(argv[2]):
            for fn_ in sorted(fns):
                if not fn_.endswith(".fig"):
                    continue
                p = os.path.join(dp, fn_)
                data = open(p, "rb").read()
                try:
                    k = 0
                    for off, hdr, fn in iter_embedded(data):
                        k += 1
                        for g in walk(fn):
                            nfunc += 1
                            ninstr += len(g.code)
                            probs = validate(g)
                            if probs:
                                raise LuaError(probs[0])
                    if k:
                        embf += 1
                        emb += k
                except LuaError as e:
                    bad += 1
                    print("FAIL", p, e)
        print("standalone chunks parsed %d, failed %d; embedded: %d chunks in %d .fig files" % (ok, bad, emb, embf))
        print("functions %d, instructions %d" % (nfunc, ninstr))
        for h in hdrs:
            print("header", dict(h))
        return 1 if bad else 0
    if argv[1] == "--stats":
        from collections import Counter
        cnt = Counter()
        nchunks = 0
        for p in find_bytecode(argv[2]):
            _, fn = load_chunk(open(p, "rb").read())
            nchunks += 1
            for g in walk(fn):
                cnt.update(i & 0x3F for i in g.code)
        for dp, _, fns in os.walk(argv[2]):
            for fn_ in fns:
                if fn_.endswith(".fig"):
                    for off, hdr, fn in iter_embedded(open(os.path.join(dp, fn_), "rb").read()):
                        nchunks += 1
                        for g in walk(fn):
                            cnt.update(i & 0x3F for i in g.code)
        tot = sum(cnt.values())
        print("chunks %d, instructions %d" % (nchunks, tot))
        for op, n in cnt.most_common():
            print("%-10s %9d %5.1f%%" % (OPS[op][0], n, 100.0 * n / tot))
        return 0
    if argv[1] == "--out":
        outdir, root = argv[2], argv[3]
        for p in find_bytecode(root):
            rel = os.path.relpath(p, root)
            dst = os.path.join(outdir, rel + ".lst")
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            try:
                hdr, fn = load_chunk(open(p, "rb").read())
                open(dst, "w").write("\n".join(format_func(fn)) + "\n")
            except LuaError as e:
                print("FAIL", p, e)
        for dp, _, fns in os.walk(root):
            for fn_ in sorted(fns):
                if not fn_.endswith(".fig"):
                    continue
                p = os.path.join(dp, fn_)
                dst = os.path.join(outdir, os.path.relpath(p, root) + ".lst")
                lines = []
                try:
                    for off, hdr, fn in iter_embedded(open(p, "rb").read()):
                        lines.append("; ==== embedded chunk at 0x%x" % off)
                        lines += format_func(fn)
                except LuaError as e:
                    print("FAIL", p, e)
                if lines:
                    os.makedirs(os.path.dirname(dst), exist_ok=True)
                    open(dst, "w").write("\n".join(lines) + "\n")
        return 0
    for p in argv[1:]:
        hdr, fn = load_chunk(open(p, "rb").read())
        print("; %s" % p)
        print("\n".join(format_func(fn)))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
