#!/usr/bin/env python3
"""Float-literal lint: float/double literals in equivalent/ and matches/ sources that are not bit-exact to a
constant the original function loads.

For each source (named by the function's address) the original's constants are collected from its machine code:
  * memory operands of x87/SSE float instructions that point at the XBE's data (4 or 8 bytes by operand size),
  * immediate dwords that look like float bit patterns (`mov [x], 0x3c8efa35`, `push 0x3f800000`).
A literal is exact if its float32 (or, for 8-byte constants, double) value equals one of those. A literal that is
not exact but within --tol (relative) of one is reported with the likely intended spelling:
  0.0174533f   -> 0.0174532924f   (0x3c8efa35)
  1000000.0f   -> 999999.0f       (0x497423f0)
Literals near nothing are counted as "unmatched" (folded expressions, 0/1/2, constants kept in registers) and
are not reported. Sources are never modified.

Usage: tools/lint_floats.py [--dirs equivalent matches] [--tol 1e-3] [--out build/cl2/floats.json] [ADDR ...]
"""
import argparse
import csv
import json
import math
import os
import re
import struct
import sys

import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from xbe import Xbe

ROOT = os.path.join(HERE, "..")
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
FUNCS_PATH = os.path.join(ROOT, "build/functions.csv")

NUM = re.compile(r"(?<![\w.])(?:(\d+\.\d*|\.\d+|\d+)([eE][+-]?\d+)?)([fFlL]?)(?![\w.])")
FLOAT_MNEM = ("fld", "fst", "fadd", "fsub", "fmul", "fdiv", "fcom", "fiadd", "fisub", "fimul", "fidiv", "fucom",
              "fsubr", "fdivr", "ficom", "fild", "fist")
SSE_PREFIX = ("movss", "movsd", "addss", "addsd", "subss", "subsd", "mulss", "mulsd", "divss", "divsd",
              "comiss", "comisd", "ucomiss", "ucomisd", "cvt", "andps", "andpd", "xorps", "xorpd", "maxs", "mins",
              "sqrts", "movaps", "movups", "movlps", "movhps")


def f32(x):
    try:
        return struct.unpack("<f", struct.pack("<f", x))[0]
    except OverflowError:
        return math.inf


def strip_code(text):
    """Blank comments, string and char literals (keeping line numbers) so only code literals are scanned."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i)); i = j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r"[^\n]", " ", text[i:j])); i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
            out.append(" " * (j - i)); i = j
        else:
            out.append(c); i += 1
    return "".join(out)


def literals(text):
    """[(line, spelling, value, is_float_suffix, is_double_implied)] float-looking literals in code."""
    code = strip_code(text)
    res = []
    for ln, line in enumerate(code.split("\n"), 1):
        if line.lstrip().startswith("#"):
            continue
        for m in NUM.finditer(line):
            intpart, exp, suf = m.group(1), m.group(2), m.group(3)
            if "." not in intpart and not exp and suf.lower() != "f":
                continue                                    # integer
            # hex like 0x1f: the lookbehind keeps "0x1" out; skip tokens glued to 'x'
            if m.start() > 0 and line[m.start() - 1] in "xX":
                continue
            try:
                v = float(intpart + (exp or ""))
            except ValueError:
                continue
            res.append((ln, m.group(0), v, suf.lower() == "f"))
    return res


class Orig:
    def __init__(self):
        self.xbe = Xbe(XBE_PATH)
        self.funcs = {}
        with open(FUNCS_PATH) as f:
            for r in csv.DictReader(f):
                self.funcs[int(r["address"], 16)] = int(r["size"])
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.detail = True
        self.cache = {}

    def data_va(self, va):
        s = self.xbe.section_of(va)
        return s is not None and not s.executable

    def constants(self, addr):
        """[(kind, size, value, bits, where)] constants the function at addr reads."""
        if addr in self.cache:
            return self.cache[addr]
        size = self.funcs.get(addr)
        res, seen = [], set()
        if size is None:
            self.cache[addr] = None
            return None
        code = self.xbe.data[self.xbe.offset(addr):self.xbe.offset(addr) + size]
        for ins in self.md.disasm(code, addr):
            mn = ins.mnemonic
            isf = mn.startswith(FLOAT_MNEM) or mn.startswith(SSE_PREFIX)
            for op in ins.operands:
                if op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0 and isf:
                    va = op.mem.disp & 0xFFFFFFFF
                    sz = op.size
                    if sz in (4, 8) and self.data_va(va) and not mn.startswith(("fild", "fist", "fiadd", "fisub",
                                                                                "fimul", "fidiv", "ficom")):
                        try:
                            raw = self.xbe.data[self.xbe.offset(va):self.xbe.offset(va) + sz]
                        except Exception:
                            continue
                        if len(raw) != sz:
                            continue
                        w = struct.unpack("<f" if sz == 4 else "<d", raw)[0]
                        key = (va, sz)
                        if key not in seen and math.isfinite(w):
                            seen.add(key)
                            res.append(("mem", sz, w, raw[::-1].hex(), "%08x" % va))
                elif op.type == capstone.x86.X86_OP_IMM and mn in ("mov", "push", "cmp", "and", "or", "xor"):
                    val = op.imm & 0xFFFFFFFF
                    if 0x00800000 <= (val & 0x7FFFFFFF) < 0x7F000000 and val > 0xFFFF:
                        w = struct.unpack("<f", struct.pack("<I", val))[0]
                        key = ("imm", val)
                        if key not in seen and math.isfinite(w) and w != 0:
                            seen.add(key)
                            res.append(("imm", 4, w, "%08x" % val, "%08x" % ins.address))
        self.cache[addr] = res
        return res


def spell(v, sz):
    """Shortest spelling that reads back as the same float32 (or double)."""
    if sz == 4:
        for p in range(1, 12):
            s = "%.*g" % (p, v)
            if f32(float(s)) == v:
                break
    else:
        s = repr(v)
    if "." not in s and "e" not in s and "inf" not in s:
        s += ".0"
    return s + ("f" if sz == 4 else "")


def lint_source(orig, path, addr, tol):
    consts = orig.constants(addr)
    if consts is None:
        return None
    with open(path, errors="replace") as f:
        text = f.read()
    lits = literals(text)
    issues, exact, unmatched = [], 0, 0
    for ln, sp, v, fsuf in lits:
        a = abs(v)
        if a in (0.0, 1.0):
            exact += 1                                       # fldz / fld1
            continue
        fa = f32(a)
        ok = False
        near = []
        for kind, sz, w, bits, where in consts:
            wa = abs(w)
            if (sz == 4 and fa == wa) or (sz == 8 and a == wa) or (sz == 8 and fsuf and fa == wa):
                ok = True
                break
            if wa and abs(wa - a) / max(wa, a) <= tol:
                near.append((abs(wa - a) / max(wa, a), kind, sz, w, bits, where))
        if ok:
            exact += 1
        elif near:
            rel, kind, sz, w, bits, where = min(near)
            issues.append({"line": ln, "literal": sp, "value": v, "float32_bits": "%08x" % struct.unpack(
                "<I", struct.pack("<f", f32(v)))[0] if math.isfinite(f32(v)) else None,
                "original": w, "original_bits": bits, "original_size": sz, "original_at": where, "via": kind,
                "rel_diff": rel, "suggest": ("-" if v < 0 and w < 0 else "") + spell(abs(w), sz)})
        else:
            unmatched += 1
    return {"literals": len(lits), "exact": exact, "unmatched": unmatched, "issues": issues}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dirs", nargs="*", default=["equivalent", "matches"])
    ap.add_argument("--tol", type=float, default=1e-3)
    ap.add_argument("--out", default=os.path.join(ROOT, "build/cl2/floats.json"))
    ap.add_argument("--file", nargs=2, metavar=("SRC", "ADDR"), help="lint one source against ADDR's constants (testing)")
    ap.add_argument("addrs", nargs="*")
    a = ap.parse_args()
    orig = Orig()
    if a.file:
        r = lint_source(orig, a.file[0], int(a.file[1], 16), a.tol)
        print(json.dumps(r, indent=1))
        return
    results, nsrc, nlit, nskip, nex, nun = [], 0, 0, 0, 0, 0
    for d in a.dirs:
        base = os.path.join(ROOT, d)
        for fn in sorted(os.listdir(base)):
            m = re.fullmatch(r"(0x[0-9a-f]{8})\.cpp", fn)
            if not m or (a.addrs and m.group(1) not in a.addrs):
                continue
            addr = int(m.group(1), 16)
            r = lint_source(orig, os.path.join(base, fn), addr, a.tol)
            if r is None:
                nskip += 1
                continue
            nsrc += 1
            nlit += r["literals"]; nex += r["exact"]; nun += r["unmatched"]
            for it in r["issues"]:
                it.update({"addr": m.group(1), "dir": d})
                results.append(it)
    results.sort(key=lambda x: (-x["rel_diff"] if x["rel_diff"] > 1e-5 else 1, x["addr"]))
    summary = {"sources": nsrc, "no_function": nskip, "literals": nlit, "exact": nex, "unmatched": nun, "issues": len(results),
               "addresses": len({(r["dir"], r["addr"]) for r in results}),
               "both_dirs": sorted({r["addr"] for r in results if r["dir"] == "equivalent"} &
                                   {r["addr"] for r in results if r["dir"] == "matches"})}
    if a.out != "-":
        os.makedirs(os.path.dirname(a.out), exist_ok=True)
        with open(a.out, "w") as f:
            json.dump({"summary": summary, "issues": results}, f, indent=1)
    print("sources %(sources)d  literals %(literals)d (exact %(exact)d, unmatched %(unmatched)d)  issues %(issues)d in %(addresses)d sources" % summary)
    for r in results[:40]:
        print("%s/%s:%d  %s -> %s  (orig %s %s at %s, rel %.2e)" % (r["dir"], r["addr"], r["line"], r["literal"],
              r["suggest"], r["original_bits"], r["via"], r["original_at"], r["rel_diff"]))


if __name__ == "__main__":
    main()
