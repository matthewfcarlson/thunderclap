#!/usr/bin/env python3
"""Compile a source file with MSVC 7.1 (via wibo) and compare a function against the XBE.

Usage: tools/compare.py src/foo.cpp 0x18b40 [symbol] [--json] [--full] [-- extra cl flags]

symbol is an exact mangled name or a substring; without it, every function defined
in the object is tried and the best match is reported.

Bytes covered by a relocation in the compiled object are masked on both sides
(absolute addresses / call targets can't be compared until we link).
"""
import difflib
import json
import os
import re
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


def file_flags(src):
    """Per-TU compiler flags from a '// cl-flags: /Oy- ...' comment (some objects used different options)."""
    try:
        with open(src) as f:
            for _ in range(5):
                line = f.readline()
                m = re.match(r"\s*//\s*cl-flags:\s*(.+)", line)
                if m:
                    # (/GS, /GS-: the game was built with /GS; MSVC 7.1 adds the cookie to a function with a
                    # string buffer by itself, so a source can keep a plain `char buf[N]` local. Keep
                    # tools/gen_tree.py's ALLOWED_FLAGS the same)
                    allowed = {"/Oy-", "/Oy", "/O1", "/O2", "/Ox", "/Os", "/Ot", "/Og", "/Oi", "/Ob0", "/Ob1", "/Ob2", "/GX", "/GX-", "/GR", "/GR-", "/Gy",
                               "/GS", "/GS-"}
                    return [t for t in m.group(1).split() if t in allowed]
    except OSError:
        pass
    return []


def compile_obj(src, flags, out_dir):
    obj = os.path.join(out_dir, os.path.splitext(os.path.basename(src))[0] + ".obj")
    env = dict(os.environ, INCLUDE=os.path.join(MSVC, "Include") + ";" + os.path.join(ROOT, "include"))
    # cl parses a leading "/" as a switch, so pass the source relative to its own directory.
    src_dir, src_name = os.path.split(os.path.abspath(src))
    cmd = [WIBO, os.path.join(MSVC, "Bin/cl.exe")] + list(flags) + file_flags(src) + ["/Fo" + obj, src_name]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=src_dir)
    if r.returncode != 0 or not os.path.exists(obj):
        # Drop the echoed file name; keep paths short for the model.
        lines = [l.replace(os.path.dirname(os.path.abspath(src)) + os.sep, "")
                 for l in (r.stdout + r.stderr).splitlines() if l.strip() and l.strip() != os.path.basename(src)]
        raise CompileError("\n".join(lines[:20]))
    return obj


class CompileError(Exception):
    pass


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
        self.by_index = {}  # raw symbol-table index (relocations use it) -> symbol tuple
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
            self.by_index[i] = (name, value, secnum, typ, cls)
            i += 1 + naux

    def function_symbols(self):
        return [s for s in self.symbols if s[2] > 0 and s[3] == 0x20]  # DTYPE_FUNCTION

    def function(self, sym):
        name, value, secnum, _, _ = sym
        funcs = self.function_symbols()
        _, raw, relocs = self.sections[secnum - 1]
        # With /Gy each function is its own COMDAT section; otherwise bound by next symbol.
        ends = sorted(s[1] for s in funcs if s[2] == secnum and s[1] > value)
        end = ends[0] if ends else len(raw)
        mask = set()
        for vaddr, _, _ in relocs:
            if value <= vaddr < end:
                mask.update(range(vaddr - value, vaddr - value + 4))
        return name, raw[value:end], mask

    def function_relocs(self, sym):
        """[(offset in function, symbol tuple, reloc type, inline addend bytes)] for one function."""
        name, value, secnum, _, _ = sym
        funcs = self.function_symbols()
        _, raw, relocs = self.sections[secnum - 1]
        ends = sorted(s[1] for s in funcs if s[2] == secnum and s[1] > value)
        end = ends[0] if ends else len(raw)
        return [(va - value, self.by_index.get(si), typ, raw[va:va + 4])
                for va, si, typ in relocs if value <= va < end]


def strip_padding(b):
    """Drop trailing int3/nop padding."""
    return b.rstrip(b"\xcc").rstrip(b"\x90") if b else b


def target_bytes(addr):
    size, tname = load_functions()[addr]
    xbe = Xbe(XBE_PATH)
    o = xbe.offset(addr)
    return tname, xbe.data[o:o + size]


_md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
_md.syntax = capstone.CS_OPT_SYNTAX_INTEL


def _key(i):
    """Alignment key: ignore operands that move when code shifts (branch/call targets, image addresses)."""
    if i.mnemonic == "call" or i.mnemonic.startswith("j"):
        return i.mnemonic
    return re.sub(r"0x[0-9a-f]{5,}", "ADDR", "%s %s" % (i.mnemonic, i.op_str))


def diff(target, ours, mask):
    """Align instructions (LCS on normalized text) so one extra/missing instruction stays local.

    Row tags: "  " equal, "!!" differs, "--" only in target, "++" only in ours.
    Score = aligned-equal instructions / max(target, ours) instructions. exact still means byte-identical
    (with relocations masked) at the same offsets.
    """
    t_insns = list(_md.disasm(target, 0))
    o_insns = list(_md.disasm(ours, 0))

    def masked_eq(ti, oi):
        if ti.size != oi.size or ti.address != oi.address:
            return False
        return all(ti.bytes[k] == oi.bytes[k] or (oi.address + k) in mask for k in range(ti.size))

    exact = len(target) == len(ours) and len(t_insns) == len(o_insns) and all(
        masked_eq(a, b) for a, b in zip(t_insns, o_insns))

    fmt = lambda i: ("%s %s" % (i.mnemonic, i.op_str)) if i else ""
    tk, ok_ = [_key(i) for i in t_insns], [_key(i) for i in o_insns]
    rows, matched = [], 0
    sm = difflib.SequenceMatcher(None, tk, ok_, autojunk=False)
    opcodes = sm.get_opcodes()
    # Map our instruction offsets to the aligned target offsets, to check branch destinations.
    o2t = {}
    for op, i1, i2, j1, j2 in opcodes:
        if op == "equal":
            for a, b in zip(t_insns[i1:i2], o_insns[j1:j2]):
                o2t[b.address] = a.address

    def pair_eq(a, b):
        if a.size != b.size:
            return False
        is_branch = a.mnemonic == "call" or a.mnemonic.startswith("j")
        if is_branch and a.bytes[0] in (0xE8, 0xE9, 0xEB) or (is_branch and 0x70 <= a.bytes[0] <= 0x7F) or (
                is_branch and a.bytes[0] == 0x0F and a.size == 6):
            if any(b.address + k in mask for k in range(b.size)):
                return a.bytes[0] == b.bytes[0]  # relocated call/jmp to another function
            ta = int(a.op_str, 16) if a.op_str.startswith("0x") else None
            tb = int(b.op_str, 16) if b.op_str.startswith("0x") else None
            return a.bytes[:a.size - (4 if a.size >= 5 else 1)] == b.bytes[:b.size - (4 if b.size >= 5 else 1)] \
                and ta is not None and o2t.get(tb) == ta
        return all(a.bytes[k] == b.bytes[k] or (b.address + k) in mask for k in range(a.size))

    for op, i1, i2, j1, j2 in opcodes:
        if op == "equal":
            for a, b in zip(t_insns[i1:i2], o_insns[j1:j2]):
                same = pair_eq(a, b)
                matched += same
                rows.append(("  " if same else "!!", a.address, fmt(a), fmt(b)))
            continue
        n = max(i2 - i1, j2 - j1)
        for k in range(n):
            a = t_insns[i1 + k] if i1 + k < i2 else None
            b = o_insns[j1 + k] if j1 + k < j2 else None
            tag = "!!" if a and b else ("--" if a else "++")
            rows.append((tag, (a or b).address, fmt(a), fmt(b)))
    # Divide by the longer sequence: extra instructions in ours must lower the score too.
    total = max(len(t_insns), len(o_insns), 1)
    return {"exact": exact, "matched": matched, "total": total,
            "target_bytes": len(target), "our_bytes": len(ours), "rows": rows}


def compare(src, addr, symbol=None, flags=()):
    """Compile src and compare against the function at addr. Returns a result dict."""
    tname, target = target_bytes(addr)
    with tempfile.TemporaryDirectory() as tmp:
        try:
            coff = Coff(compile_obj(src, DEFAULT_FLAGS + list(flags), tmp))
        except CompileError as e:
            return {"status": "compile_error", "target": tname, "error": str(e)}
    syms = coff.function_symbols()
    if symbol:
        syms = [s for s in syms if s[0] == symbol] or [s for s in syms if symbol in s[0]]
    if not syms:
        return {"status": "no_function", "target": tname,
                "error": "no function body found in the object" + (" matching %r" % symbol if symbol else "")}
    best = None
    for sym in syms:
        name, ours, mask = coff.function(sym)
        d = diff(target, strip_padding(ours), mask)
        key = (d["exact"], d["matched"] / d["total"], -abs(d["target_bytes"] - d["our_bytes"]))
        if best is None or key > best[0]:
            best = (key, name, d)
    _, name, d = best
    return dict(d, status="match" if d["exact"] else "diff", symbol=name, target=tname,
                score=round(d["matched"] / d["total"], 3))


def render(r, full=False, context=1):
    """Human/LLM-readable report. Compact mode shows only mismatches with a little context."""
    if r["status"] in ("compile_error", "no_function"):
        return "%s\n%s" % (r["status"].upper(), r["error"])
    out = ["%s %s  vs  %s" % ("MATCH" if r["exact"] else "DIFF", r["symbol"], r["target"]),
           "bytes target=%d ours=%d, target instructions matched %d/%d" % (
               r["target_bytes"], r["our_bytes"], r["matched"], r["total"])]
    if r["exact"]:
        return "\n".join(out)
    rows = r["rows"]
    show = set(range(len(rows))) if full else {
        j for i, row in enumerate(rows) if row[0] != "  " for j in range(i - context, i + context + 1) if 0 <= j < len(rows)}
    out.append("    off  %-34s | ours   (!! differs, -- missing in ours, ++ extra in ours)" % "target")
    skipped = 0
    for i, (tag, off, t, o) in enumerate(rows):
        if i not in show:
            skipped += 1
            continue
        if skipped:
            out.append("    ... %d matching" % skipped)
            skipped = 0
        out.append("%s %04x  %-34s | %s" % (tag, off, t, o))
    if skipped:
        out.append("    ... %d matching" % skipped)
    return "\n".join(out)


def main(argv):
    extra = []
    if "--" in argv:
        i = argv.index("--")
        argv, extra = argv[:i], argv[i + 1:]
    as_json = "--json" in argv
    full = "--full" in argv
    pos = [a for a in argv if a not in ("--json", "--full")]
    src = pos[0]
    addr = next(int(a, 16) for a in pos[1:] if a.startswith("0x"))
    symbol = next((a for a in pos[1:] if not a.startswith("0x")), None)
    r = compare(src, addr, symbol, extra)
    if as_json:
        r = {k: v for k, v in r.items() if k != "rows"} | {"report": render(r, full)}
        print(json.dumps(r))
    else:
        print(render(r, full=True if not as_json else full))
    return 0 if r["status"] == "match" else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
