#!/usr/bin/env python3
"""Compile a source file with MSVC 7.1 (via wibo) and compare a function against the XBE.

Usage: tools/compare.py src/foo.cpp '?Release@RefCounted@pure3d@@UAEXXZ' 0x18b40 [-- extra cl flags]
       tools/compare.py src/foo.cpp Release 0x18b40      (substring match on symbol name)

Bytes covered by a relocation in the compiled object are masked on both sides
(absolute addresses / call targets can't be compared until we link).
"""
import os
import struct
import subprocess
import sys
import tempfile

import capstone

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe
from disasm import load_functions

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
MSVC = os.path.join(ROOT, "build/compilers/msvc7.1/compilers/win32/msvc7.1")
WIBO = os.path.join(ROOT, "build/tools/wibo")
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
DEFAULT_FLAGS = ["/nologo", "/c", "/O2", "/GR", "/GX", "/Gy"]


def compile_obj(src, flags, out_dir):
    obj = os.path.join(out_dir, os.path.splitext(os.path.basename(src))[0] + ".obj")
    env = dict(os.environ, INCLUDE=os.path.join(MSVC, "Include") + ";" + os.path.join(ROOT, "include"))
    cmd = [WIBO, os.path.join(MSVC, "Bin/cl.exe")] + flags + ["/Fo" + obj, src]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True)
    if r.returncode != 0 or not os.path.exists(obj):
        sys.exit("compile failed:\n" + r.stdout + r.stderr)
    return obj


class Coff:
    def __init__(self, path):
        d = self.data = open(path, "rb").read()
        _, nsec, _, symoff, nsym, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
        self.strtab = symoff + nsym * 18
        self.sections = []
        for i in range(nsec):
            o = 20 + opthdr + i * 40
            name = d[o:o + 8].rstrip(b"\0").decode()
            _, _, size, raw, relptr, _, nrel, _, _ = struct.unpack_from("<IIIIIIHHI", d, o + 8)
            relocs = [struct.unpack_from("<IIH", d, relptr + j * 10) for j in range(nrel)]
            self.sections.append((name, d[raw:raw + size] if raw else b"", relocs))
        self.symbols = []
        i = 0
        while i < nsym:
            o = symoff + i * 18
            if d[o:o + 4] == b"\0\0\0\0":
                off, = struct.unpack_from("<I", d, o + 4)
                s = self.strtab + off
                name = d[s:d.index(b"\0", s)].decode()
            else:
                name = d[o:o + 8].rstrip(b"\0").decode()
            value, secnum, typ, cls, naux = struct.unpack_from("<IhHBB", d, o + 8)
            self.symbols.append((name, value, secnum, typ, cls))
            i += 1 + naux

    def function(self, query):
        funcs = [s for s in self.symbols if s[2] > 0 and s[3] == 0x20]  # DTYPE_FUNCTION
        hits = [s for s in funcs if s[0] == query] or [s for s in funcs if query in s[0]]
        if len(hits) != 1:
            sys.exit("symbol %r matched %d functions: %s" % (query, len(hits), [s[0] for s in funcs]))
        name, value, secnum, _, _ = hits[0]
        _, raw, relocs = self.sections[secnum - 1]
        # With /Gy each function is its own COMDAT section; otherwise bound by next symbol.
        ends = sorted(s[1] for s in funcs if s[2] == secnum and s[1] > value)
        end = ends[0] if ends else len(raw)
        mask = set()
        for vaddr, _, _ in relocs:
            if value <= vaddr < end:
                mask.update(range(vaddr - value, vaddr - value + 4))
        return name, raw[value:end], mask


def strip_padding(b):
    """Drop trailing int3/nop padding."""
    return b.rstrip(b"\xcc").rstrip(b"\x90") if b else b


def main(argv):
    extra = []
    if "--" in argv:
        i = argv.index("--")
        argv, extra = argv[:i], argv[i + 1:]
    src, query, addr = argv[0], argv[1], int(argv[2], 16)
    flags = DEFAULT_FLAGS + extra

    with tempfile.TemporaryDirectory() as tmp:
        name, ours, mask = Coff(compile_obj(src, flags, tmp)).function(query)

    xbe = Xbe(XBE_PATH)
    size, tname = load_functions()[addr]
    o = xbe.offset(addr)
    target = xbe.data[o:o + size]
    ours = strip_padding(ours)

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.syntax = capstone.CS_OPT_SYNTAX_INTEL
    t_insns = list(md.disasm(target, 0))
    o_insns = list(md.disasm(ours, 0))

    def masked_eq(ti, oi):
        if ti.size != oi.size:
            return False
        return all(ti.bytes[k] == oi.bytes[k] or (oi.address + k) in mask for k in range(ti.size))

    rows, matched = [], 0
    for k in range(max(len(t_insns), len(o_insns))):
        ti = t_insns[k] if k < len(t_insns) else None
        oi = o_insns[k] if k < len(o_insns) else None
        ok = ti is not None and oi is not None and masked_eq(ti, oi)
        matched += ok
        fmt = lambda i: "%-30s" % ("%s %s" % (i.mnemonic, i.op_str) if i else "")
        rows.append("%s %04x  %s | %s" % ("  " if ok else "!!", ti.address if ti else oi.address, fmt(ti), fmt(oi)))

    total = max(len(t_insns), len(o_insns))
    exact = len(target) == len(ours) and matched == total
    print("%s  %s  vs  %s @ %#x" % ("MATCH" if exact else "DIFF ", name, tname, addr))
    print("bytes: target %d, ours %d; instructions matched %d/%d (reloc bytes masked: %d)"
          % (len(target), len(ours), matched, total, len(mask)))
    print("       %-30s | %-30s" % ("target", "ours"))
    print("\n".join(rows))
    return 0 if exact else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
