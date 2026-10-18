#!/usr/bin/env python3
"""Calling-convention consistency of the native build's library imports (docs/native-build.md "Start-up").

  build/venv/bin/python tools/native_conv_check.py                # sources + bindings + XBE checks, report only
  build/venv/bin/python tools/native_conv_check.py --tails        # also compile functions that tail-jump to an import
  build/venv/bin/python tools/native_conv_check.py --json OUT     # findings as JSON

A byte match (compare.py) and the equivalence checker (equiv.py) both accept a declaration of an XDK / XAPI / CRT
import with the wrong calling convention or argument bytes: the call site pushes the same arguments and the callee
is outside the function either way. Natively it is a bug: a __cdecl caller adds `add esp, N` after a __stdcall
callee that already popped N bytes (fx15 found `D3DDevice_SetRenderState_FillMode` declared __cdecl). The stand-in
tables of the native build (src/platform/sdl/xdk/imports.h: the 167 XDK/XAPI/Bink imports; library.h: the library
code the tree calls by address) say each import's convention and argument bytes. Four checks:

  1. sources:  every declaration of an import in matches/ and equivalent/ (by its table name or FUN_<addr>), parsed
               for calling convention (default __cdecl; a declaration inside a class body is a thiscall member) and
               argument bytes (double / __int64 by value 8, everything else 4), against the table.
  2. bindings: every symbol build/native/bindings.json binds to an import's address, by the convention in its
               mangling (`_Name@N` stdcall, `@Name@N` fastcall, `?Name@...@Y[AGI]` free functions, `Q[AB][AEGI]`
               members), against the table: this sees names the source scan doesn't (wrappers bound by position).
  3. xbe:      the table against the callee in default.xbe: the immediate of every `ret N` reachable from the
               import's address (N > 0: the callee pops N; `ret`: cdecl). The tables took their prototypes from
               the callers' symbols, so an error there would be shared by every caller.
  5. register orders: functions the original calls in registers (`// equiv-conv: FUN_x eax stack` notes, read by
               equiv.py) must list their parameters in the same order in every caller as in their own source:
               natively all of them are __cdecl (fx: 0x0026c040 called 0x0026be70 with (size, arena)).
  4. --tails:  a function whose original tail-jumps (`jmp rel32`) to a callee-popping import pops those bytes
               itself, so its source must declare a callee-pops convention; compiles each candidate with
               tools/compare.py and reads its mangled name (slow: off by default).

Report only: tools/native_link.py runs checks 1-3 and records the counts in build/native/report.json
(`conv_check`); the exit status is 1 if anything disagrees. Never edits a source: fixes go through
tools/native_fix.py's verified rewrite. First written as fx15's sweep_conv.py.
"""
import argparse
import bisect
import collections
import csv
import json
import os
import re
import struct
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
TABLES = [os.path.join(ROOT, "src/platform/sdl/xdk", f) for f in ("imports.h", "library.h")]
XBE = os.path.join(ROOT, "isos/extracted/default.xbe")
BINDINGS = os.path.join(ROOT, "build/native/bindings.json")
CONV_WORDS = {"__cdecl": "CDECL", "__stdcall": "STDCALL", "__fastcall": "FASTCALL", "__thiscall": "THISCALL"}
PROTO_RX = re.compile(r"^\s*[\w ]+?\s+HULK_(STDCALL|CDECL|FASTCALL)\s+hulk_(?:xdk|lib)_(\w+)\(([^)]*)\);", re.M)


def parse_imports(paths=TABLES):
    """{name: dict(addr, conv, nargs, nbytes)} from the stand-in tables (X(addr, name, ...) lines + prototypes).

    nbytes are the argument bytes of the prototype (every parameter is a hulk_u32; a fastcall's first two go in
    ecx/edx). Entries without a prototype (data, or a table line without a stand-in yet) are left out."""
    out = {}
    for path in paths:
        if not os.path.exists(path):
            continue
        h = open(path).read()
        table = {n: int(a, 16) for a, n in re.findall(r'^\s*X\((0x[0-9a-fA-F]{8}), (\w+), ', h, re.M)}
        for conv, name, args in PROTO_RX.findall(h):
            if name not in table:
                continue
            args = args.strip()
            n = 0 if args in ("", "void") else len(args.split(","))
            out[name] = dict(addr=table[name], conv=conv, nargs=n, nbytes=4 * n)
    return out


def strip_comments(s):
    s = re.sub(r"/\*.*?\*/", " ", s, flags=re.S)
    return re.sub(r"//[^\n]*", " ", s)


def param_bytes(params):
    """(argument bytes, count) of a parameter list text; (None, None) if it has varargs."""
    params = params.strip()
    if params in ("", "void"):
        return 0, 0
    parts, depth, cur = [], 0, ""
    for ch in params:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append(cur)
            cur = ""
        else:
            cur += ch
    parts.append(cur)
    total = 0
    for p in parts:
        p = p.strip()
        if p == "...":
            return None, None
        if "*" not in p and "&" not in p and re.search(r"\bdouble\b|__int64|long long|\bu64\b|\bs64\b", p):
            total += 8
        else:
            total += 4
    return total, len(parts)


NOT_DECL_PREV = set("=(,!&|+-*/<>?:[") | {"return", "case", "else", "new", "delete", "sizeof", "throw", "if", "while"}


def in_class_body(src, pos):
    """Is pos directly inside a class/struct/union body? (a member declaration: thiscall, not the import's)"""
    stack, last = [], 0
    for m in re.finditer(r"[{};]", src[:pos]):
        c = m.group(0)
        if c == "{":
            head = re.sub(r"\bextern\s*\"C\"", " ", src[last:m.start()])
            if re.search(r"\b(class|struct|union)\b", head) and "(" not in head:
                stack.append("class")
            elif re.search(r"\bnamespace\b|\bextern\b", head) and "(" not in head:
                stack.append("ns")
            else:
                stack.append("fn")
        elif c == "}":
            if stack:
                stack.pop()
        last = m.end()
    return bool(stack) and stack[-1] == "class"


def source_decls(path, idents):
    """Declarations (not calls) of the identifiers in a file: [dict(ident, conv, nbytes, nargs, line, text, member)].
    A declaration is `<type tokens> [conv] IDENT(params)` followed by `;`, `{`, `throw` or `const`."""
    src = strip_comments(open(path, errors="replace").read())
    res = []
    for m in re.finditer(r"\b(%s)\s*\(" % "|".join(re.escape(i) for i in idents), src):
        ident = m.group(1)
        j = m.start()
        k = max(src.rfind(";", 0, j), src.rfind("{", 0, j), src.rfind("}", 0, j))
        prefix = re.sub(r"(?m)^\s*#[^\n]*$", " ", src[k + 1:j]).strip()
        toks = re.findall(r'"[^"]*"|[\w:]+|[^\s\w]', prefix)
        # a declaration's prefix is type tokens only; a call after `if (x)`, `D3D8::`, a label or `x = ` is not
        if not toks or toks[-1].endswith(":") or toks[-1] in NOT_DECL_PREV:
            continue
        if any(not re.fullmatch(r'[\w:]+|"[^"]*"|\*|&', t) or t.endswith(":") for t in toks):
            continue
        if any(t in ("return", "typedef", "else", "case", "new", "delete", "throw") for t in toks):
            continue
        if toks[-1] in ("*", "&") and len(toks) < 2:
            continue
        depth, i = 1, m.end()
        while i < len(src) and depth:
            depth += {"(": 1, ")": -1}.get(src[i], 0)
            i += 1
        params = src[m.end():i - 1]
        after = src[i:i + 40].lstrip()
        if not after.startswith((";", "{", "throw", "const")) or "=" in toks:
            continue
        conv = "CDECL"
        for t in toks:
            if t in CONV_WORDS:
                conv = CONV_WORDS[t]
        nb, na = param_bytes(params)
        res.append(dict(ident=ident, conv=conv, nbytes=nb, nargs=na, line=src.count("\n", 0, m.start()) + 1,
                        text=(prefix + " " + ident + "(" + " ".join(params.split()) + ")").strip()[-140:],
                        member=in_class_body(src, m.start())))
    return res


def check_sources(imps, roots=("matches", "equivalent")):
    """Check 1: (declarations found, [disagreements])."""
    idents = {}
    for n, d in imps.items():
        idents[n] = n
        idents["FUN_%08x" % d["addr"]] = n
    bad, seen = [], 0
    for root in roots:
        rd = root if os.path.isabs(root) else os.path.join(ROOT, root)
        for fn in sorted(os.listdir(rd)):
            if not fn.endswith(".cpp"):
                continue
            p = os.path.join(rd, fn)
            txt = open(p, errors="replace").read()
            if not any(i in txt for i in idents):
                continue
            for d in source_decls(p, idents):
                seen += 1
                imp = imps[idents[d["ident"]]]
                why = []
                if d["member"]:
                    why.append("declared as a member (thiscall: this in ecx), table %s/%d" % (imp["conv"], imp["nbytes"]))
                elif d["conv"] != imp["conv"]:
                    why.append("convention %s, table %s" % (d["conv"], imp["conv"]))
                if not d["member"] and d["nbytes"] is not None and d["nbytes"] != imp["nbytes"]:
                    why.append("%d argument bytes, table %d" % (d["nbytes"], imp["nbytes"]))
                if why:
                    bad.append(dict(file=os.path.relpath(p, ROOT), import_=idents[d["ident"]], **d, why="; ".join(why)))
    return seen, bad


def mangled_conv(sym):
    """(plain name, convention) of a decorated / mangled free-function symbol; (None, None) otherwise."""
    m = re.match(r"\?([\w$]+)@(?:[\w$]+@)*@Y([AGI])", sym)
    if m:
        return m.group(1), {"A": "CDECL", "G": "STDCALL", "I": "FASTCALL"}[m.group(2)]
    m = re.match(r"_(\w+)@(\d+)$", sym)
    if m:
        return m.group(1), "STDCALL"
    m = re.match(r"@(\w+)@(\d+)$", sym)
    if m:
        return m.group(1), "FASTCALL"
    m = re.match(r"_(\w+)$", sym)
    if m:
        return m.group(1), "CDECL"
    return None, None


def check_bindings(imps, path=BINDINGS):
    """Check 2: (symbols bound to an import, [disagreements]) from the native link's binding map.

    A thiscall member (`QAE`) bound to a stdcall import has the same stack (the callee pops the stack arguments) but
    passes `this` in ecx, which the stand-in ignores; it is reported anyway (the declaration claims a class the import
    isn't). A fastcall member against a fastcall import is the same call and is not reported."""
    if not os.path.exists(path):
        return 0, []
    b = json.load(open(path))["bindings"]
    by_addr = {d["addr"]: n for n, d in imps.items()}
    bad, seen = [], 0
    for sym, v in sorted(b.items()):
        a = int(v["addr"], 16)
        if a not in by_addr:
            continue
        seen += 1
        imp = imps[by_addr[a]]
        mm = re.match(r"\?([\w$]+)@(?:[\w$]+@)*@Q[AB]([AEGI])", sym)
        if mm:
            mc = {"E": "THISCALL", "I": "FASTCALL", "A": "CDECL", "G": "STDCALL"}[mm.group(2)]
            if mc != imp["conv"]:
                bad.append(dict(symbol=sym, import_=by_addr[a], conv=mc + " member", table=imp["conv"]))
            continue
        name, conv = mangled_conv(sym)
        if conv and conv != imp["conv"]:
            bad.append(dict(symbol=sym, import_=by_addr[a], conv=conv, table=imp["conv"]))
    return seen, bad


def xbe_rets(xbe, md, addr, limit=4096):
    """The `ret N` immediates reachable from addr (following in-function branches), and tail-jump targets."""
    seen, work, rets, tails = set(), [addr], set(), set()
    while work:
        va = work.pop()
        while va not in seen and addr <= va < addr + limit:
            seen.add(va)
            o = xbe.offset(va)
            if o is None:
                break
            insn = next(md.disasm(xbe.data[o:o + 16], va), None)
            if insn is None:
                break
            mn = insn.mnemonic
            if mn in ("int3", "ud2"):
                break
            if mn == "ret":
                rets.add(int(insn.op_str, 16) if insn.op_str else 0)
                break
            if mn == "jmp":
                if insn.op_str.startswith("0x"):
                    t = int(insn.op_str, 16)
                    if addr <= t < addr + limit and t > va - 0x400:
                        va = t
                        continue
                    tails.add(t)
                break
            if mn.startswith("j") and insn.op_str.startswith("0x"):
                work.append(int(insn.op_str, 16))
            va += insn.size
    return rets, tails


def check_xbe(imps):
    """Check 3: ([disagreements], [imports with no reachable ret]) of the tables against the callees' `ret N`.
    (Only the argument bytes a callee pops are compared; reading the instruction stream for its `ret` immediates
    is all this does with library code.)"""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import capstone
    from xbe import Xbe
    xbe = Xbe(XBE)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    bad, noret = [], []
    for n, d in sorted(imps.items(), key=lambda kv: kv[1]["addr"]):
        rets, tails = xbe_rets(xbe, md, d["addr"])
        note = None
        if rets:
            pops = max(rets)
            if d["conv"] == "STDCALL" and (pops != d["nbytes"] or len(rets) > 1 and min(rets) != pops):
                note = "table stdcall/%d, callee ret %s" % (d["nbytes"], sorted(rets))
            if d["conv"] == "CDECL" and pops != 0:
                note = "table cdecl, callee ret %s" % sorted(rets)
            if d["conv"] == "FASTCALL" and pops != max(0, d["nbytes"] - 8):
                note = "table fastcall (%d stack bytes), callee ret %s" % (max(0, d["nbytes"] - 8), sorted(rets))
        elif not tails:
            noret.append("0x%08x %s" % (d["addr"], n))
        if note:
            bad.append(dict(import_=n, addr="0x%08x" % d["addr"], note=note, tails=sorted(hex(t) for t in tails)))
    return bad, noret


def tail_jump_functions(imps):
    """{function addr: {(import, conv, bytes the import pops)}} of original functions that `jmp rel32` to an import."""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    from xbe import Xbe
    xbe = Xbe(XBE)
    funcs = sorted((int(r["address"], 16), int(r["size"])) for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))))
    starts = [a for a, _ in funcs]
    by_addr = {d["addr"]: n for n, d in imps.items()}
    out = {}
    for sec in xbe.sections:
        if not sec.executable:
            continue
        data = xbe.data[sec.raw:sec.raw + sec.rsize]
        i = data.find(b"\xe9")
        while i >= 0:
            if i + 5 <= len(data):
                va = sec.va + i
                t = (va + 5 + struct.unpack_from("<i", data, i + 1)[0]) & 0xFFFFFFFF
                if t in by_addr:
                    k = bisect.bisect_right(starts, va) - 1
                    if k >= 0 and va < funcs[k][0] + funcs[k][1] and funcs[k][0] != t:
                        imp = imps[by_addr[t]]
                        pops = imp["nbytes"] if imp["conv"] != "FASTCALL" else max(0, imp["nbytes"] - 8)
                        out.setdefault(funcs[k][0], set()).add((by_addr[t], imp["conv"], pops if imp["conv"] != "CDECL" else 0))
            i = data.find(b"\xe9", i + 1)
    return out


def check_tails(imps, roots=("matches", "equivalent")):
    """Check 4: ([disagreements], candidates)."""
    bad = []
    cands = tail_jump_functions(imps)
    for fa, imps_ in sorted(cands.items()):
        pops = max(p for _, _, p in imps_)
        if pops == 0:
            continue
        for root in roots:
            src = os.path.join(ROOT, root, "0x%08x.cpp" % fa)
            if not os.path.exists(src):
                continue
            r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/compare.py"), src, "0x%08x" % fa],
                               capture_output=True, text=True, cwd=ROOT)
            m = re.match(r"(?:MATCH|DIFF)\s+(\S+)", (r.stdout.split("\n") or [""])[0])
            if m and re.search(r"@@YA", m.group(1)):
                bad.append(dict(file=os.path.relpath(src, ROOT), symbol=m.group(1), imports=sorted(i for i, _, _ in imps_),
                                pops=pops, why="tail-jumps to a callee-popping import (pops %d) but is declared __cdecl" % pops))
    return bad, len(cands)


CONV_NOTE = re.compile(r"//\s*equiv-conv:\s*(\S+)\s+([^\n]*)")


def check_register_orders(roots=("matches", "equivalent")):
    """Check 5: functions with a register calling convention (`// equiv-conv: FUN_0026be70 eax stack`: the
    parameters in declaration order and where the original passes each). equiv.py maps every declaration to the
    original's registers, so a caller may list the parameters in any order; natively they are all __cdecl and the
    order is the ABI. For each address, every caller's list must equal the one in the function's own source.
    Returns (functions with a definition note, [disagreements])."""
    notes = collections.defaultdict(list)       # addr -> [(file, locs)]
    own = {}
    for root in roots:
        rd = os.path.join(ROOT, root)
        for fn in sorted(os.listdir(rd)):
            m = re.fullmatch(r"0x([0-9a-fA-F]{8})\.cpp", fn)
            if not m:
                continue
            txt = open(os.path.join(rd, fn), errors="replace").read()
            if "equiv-conv" not in txt:
                continue
            for name, locs in CONV_NOTE.findall(txt):
                am = re.search(r"(?:FUN|thunk_FUN)_(00[0-9a-fA-F]{6})", name)
                if not am:
                    continue
                a = int(am.group(1), 16)
                locs = tuple(locs.split())
                if a == int(m.group(1), 16):
                    own[a] = ("%s/%s" % (root, fn), locs)
                else:
                    notes[a].append(("%s/%s" % (root, fn), locs))
    bad = []
    # callers without a note: a source that calls FUN_<addr> of a register-convention function and doesn't say how
    # (equivalent/0x00219cc0 called 0x00219be0 `(owner)` where the original passes esi, edi and a stack word)
    noted = {(f, a) for a, lst in notes.items() for f, _l in lst}
    for root in roots:
        rd = os.path.join(ROOT, root)
        for fn in sorted(os.listdir(rd)):
            m = re.fullmatch(r"0x([0-9a-fA-F]{8})\.cpp", fn)
            if not m:
                continue
            txt = None
            for a, (f0, l0) in own.items():
                if a == int(m.group(1), 16) or ("%s/%s" % (root, fn), a) in noted:
                    continue
                if txt is None:
                    txt = strip_comments(open(os.path.join(rd, fn), errors="replace").read())
                if re.search(r"\b(?:thunk_)?FUN_%08x\s*\(" % a, txt) and all(l == "stack" for l in l0) is False:
                    bad.append(dict(addr="0x%08x" % a, file="%s/%s" % (root, fn), conv="(no note)", definition=f0,
                                    definition_conv=" ".join(l0),
                                    why="calls a register-convention function without an equiv-conv note"))
    for a, (f0, l0) in sorted(own.items()):
        for f, l in notes.get(a, []):
            if l != l0:
                bad.append(dict(addr="0x%08x" % a, file=f, conv=" ".join(l), definition=f0, definition_conv=" ".join(l0),
                                why="parameter order %s, the definition's %s" % (" ".join(l), " ".join(l0))))
    return len(own), bad


TREE_REPORT = os.path.join(ROOT, "build/tree/report.json")
X87_PUSH = {"fld", "fild", "fldz", "fld1", "fldpi", "fldl2e", "fldl2t", "fldlg2", "fldln2", "fbld"}
X87_NEUTRAL = {"fldcw", "fnstcw", "fstcw", "fnstsw", "fstsw", "fwait", "wait", "fnclex", "fclex", "finit", "fninit",
               "ffree", "fincstp", "fdecstp", "fnop", "fnstenv", "fldenv", "fnsave", "frstor"}
EAX_PARTS = {"eax", "ax", "al", "ah"}
# library functions whose argument is on the x87 stack (st0), not on the call stack: the CRT's float-to-int and
# the `_CI` math helpers (host_crt_table.h rows by XBE address)
X87_ARG_ADDRS = {0x0034483c: "_ftol", 0x003441f0: "_CIacos", 0x003442bc: "_CIasin", 0x00346672: "_CIpow",
                 0x0034777a: "_CIfmod"}
# (0x00348010 is ldexp: its callers push a double and an int, host_crt_table.h)


def return_kind(demangled):
    """'void', 'float' or 'int' (anything in eax / eax:edx) of an undname'd function; None if not a function."""
    m = re.search(r"\b(__cdecl|__stdcall|__thiscall|__fastcall)\b", demangled)
    if not m:
        return None
    ret = re.sub(r"\b(public|private|protected|virtual|static|struct|class|union|enum)\b|:", " ", demangled[:m.start()]).strip()
    if not ret:
        return "int"        # constructors (MSVC and clang's MS ABI return `this`) and conversion operators
    if ret == "void":
        return "void"
    if ret in ("float", "double", "long double"):
        return "float"
    return "int"


def c_return_kind(path, name):
    """The return kind of a C-linkage definition `<type> [conv] name(...) {` in its source; None if not found."""
    try:
        src = strip_comments(open(path, errors="replace").read())
    except OSError:
        return None
    m = re.search(r"(?:^|[;{}\n])\s*(?:extern\s+\"C\"\s+)?((?:[\w:]+[\s*&]+)+?)(?:__cdecl\s+|__stdcall\s+|__fastcall\s+)?"
                  r"%s\s*\([^;{]*\)\s*(?:throw\s*\([^)]*\)\s*)?\{" % re.escape(name), src)
    if not m:
        return None
    ret = re.sub(r"\b(static|inline|extern|__inline|__forceinline)\b", " ", m.group(1)).strip()
    if "*" in ret or "&" in ret:
        return "int"
    ret = " ".join(ret.split())
    return "void" if ret == "void" else "float" if ret in ("float", "double", "long double") else "int"


def caller_uses(md, xbe, va, limit=16):
    """What the instructions after the call at va (the next instruction's address) do with the call's results:
    ({'eax', 'st0', 'eax-ret', 'st0-ret'} uses, before the register is written / pushed over)."""
    import capstone.x86 as cx
    uses, eax_live, st_live = set(), True, True
    o = xbe.offset(va)
    if o is None:
        return uses
    for n, insn in enumerate(md.disasm(xbe.data[o:o + 96], va)):
        if n >= limit or not (eax_live or st_live):
            break
        mn = insn.mnemonic
        if mn == "ret":
            if eax_live:
                uses.add("eax-ret")
            if st_live:
                uses.add("st0-ret")
            break
        if mn == "call":
            t = int(insn.op_str, 16) if insn.op_str.startswith("0x") else None
            if st_live and t in X87_ARG_ADDRS:
                uses.add("st0")
            # (a call's own arguments were pushed before it: a `push eax` is seen as a read above)
            break
        if mn.startswith("j") or mn.startswith("loop"):
            break
        if st_live and mn.startswith("f") and mn not in X87_NEUTRAL:
            if mn in X87_PUSH:
                st_live = False
            else:
                uses.add("st0")
                st_live = False
        if eax_live:
            try:
                rd, wr = insn.regs_access()
            except Exception:  # noqa: BLE001
                break
            rn = {insn.reg_name(r) for r in rd}
            wn = {insn.reg_name(r) for r in wr}
            ops = insn.operands
            self_zero = mn in ("xor", "sub") and len(ops) == 2 and ops[0].type == cx.X86_OP_REG and \
                ops[1].type == cx.X86_OP_REG and ops[0].reg == ops[1].reg
            if rn & EAX_PARTS and not self_zero:
                uses.add("eax")
                eax_live = False
            elif wn & EAX_PARTS:
                eax_live = False        # (`fnstsw ax` then `test ah, 0x44`: the status word, not the result)
    return uses


def check_returns(roots=("matches", "equivalent"), tree_report=TREE_REPORT, callers_of=None):
    """Check 6: results the original's callers use that a verified definition doesn't return (fx: matches/0x0008d690,
    the game's operator new, was `void` and its callers read eax), and calls to the x87-argument library helpers
    (`_ftol`, `_CIacos`, ...) under a plain name, whose argument the source doesn't pass (equivalent/0x00011000: a
    `float FUN_003441f0()` call; MSVC loaded the argument onto the x87 stack for another reason, natively nothing
    does).

    For every verified function of the tree build (tree report: symbol and address), its declared return kind
    (demangled C++ symbol; a C-linkage definition from its source) against every call site of it in the original's
    game code (each function of build/functions.csv disassembled; `jmp` thunks followed): a `void` definition whose
    caller reads eax before writing it, or a non-float one whose caller consumes st0 (`fstp`, `fcomp`, a call to
    `_ftol`...), is a finding. `eax-ret` / `st0-ret` (the caller returns right after the call) count only when the
    caller's own definition returns that kind. Returns (definitions checked, [findings], [x87-helper calls])."""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import capstone
    from xbe import Xbe
    xbe = Xbe(XBE)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    rep = json.load(open(tree_report))
    checks = [c for c in rep["checks"] if c.get("symbol") and c["status"] in ("match", "compiled")]
    syms = sorted({c["symbol"] for c in checks if c["symbol"].startswith("?")})
    dem = {}
    try:
        exe = "/opt/homebrew/opt/llvm/bin/llvm-undname"
        out = subprocess.run([exe], input="\n".join(syms) + "\n", capture_output=True, text=True, errors="replace").stdout
        lines = out.splitlines()
        for i in range(0, len(lines) - 1):
            if lines[i] in syms and lines[i] not in dem:
                dem[lines[i]] = lines[i + 1]
    except OSError:
        pass
    kind = {}
    for c in checks:
        a = int(c["addr"], 16)
        s = c["symbol"]
        if s.startswith("?"):
            k = return_kind(dem.get(s, ""))
        else:
            k = c_return_kind(os.path.join(ROOT, c["src"]), re.sub(r"^[_@]|@\d+$", "", s))
        if k:
            kind[a] = (k, c["src"], s)
    # call sites in the original's game code
    funcs = sorted((int(r["address"], 16), int(r["size"])) for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))))
    thunk = {}
    for a, n in funcs:
        o = xbe.offset(a)
        if o is not None and n == 5 and xbe.data[o] == 0xE9:
            thunk[a] = (a + 5 + struct.unpack_from("<i", xbe.data, o + 1)[0]) & 0xFFFFFFFF
    md_plain = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    sites = collections.defaultdict(list)       # callee -> [(caller, address after the call)]
    for a, n in funcs:
        o = xbe.offset(a)
        if o is None or n <= 0 or n > 0x20000:
            continue
        for insn in md_plain.disasm(xbe.data[o:o + n], a):
            if insn.mnemonic == "call" and insn.op_str.startswith("0x"):
                t = int(insn.op_str, 16)
                t = thunk.get(t, t)
                sites[t].append((a, insn.address + insn.size))
    bad = []
    for a, (k, src, sym) in sorted(kind.items()):
        if k == "float":
            continue
        for caller, va in sites.get(a, []):
            u = caller_uses(md, xbe, va)
            ck = kind.get(caller, (None,))[0]
            eax = "eax" in u or ("eax-ret" in u and ck == "int")
            st0 = "st0" in u or ("st0-ret" in u and ck == "float")
            if (k == "void" and eax) or st0:
                bad.append(dict(addr="0x%08x" % a, file=src, symbol=sym, declared=k, caller="0x%08x" % caller,
                                caller_file=kind.get(caller, (None, None))[1], site="0x%08x" % va,
                                why="declared %s; the original caller 0x%08x uses %s after the call" % (
                                    k, caller, "st0" if st0 else "eax")))
    # calls to the x87-argument helpers by a plain name (the compiler's own `__ftol2`/`__CIacos` are fine)
    helpers = []
    names = {}
    for a, nm in X87_ARG_ADDRS.items():
        names["FUN_%08x" % a] = nm
    for root in roots:
        rd = os.path.join(ROOT, root)
        for fn in sorted(os.listdir(rd)):
            if not fn.endswith(".cpp"):
                continue
            txt = strip_comments(open(os.path.join(rd, fn), errors="replace").read())
            for nm in names:
                calls = 0
                for m in re.finditer(r"\b%s\s*\(" % nm, txt):
                    k = max(txt.rfind(";", 0, m.start()), txt.rfind("{", 0, m.start()), txt.rfind("}", 0, m.start()))
                    prefix = txt[k + 1:m.start()]
                    if re.search(r"\b(extern|int|void|float|double|unsigned|char|long|short|__cdecl)\b", prefix) and \
                            not re.search(r"=|\breturn\b|\(", prefix):
                        continue        # a declaration
                    calls += 1
                if calls:
                    helpers.append(dict(file="%s/%s" % (root, fn), name=nm, helper=names[nm],
                                        why="calls %s (%s: argument on the x87 stack) by a plain name" % (nm, names[nm])))
    return len(kind), bad, helpers


def declared_pops(sym, demangled):
    """(convention, stack bytes the callee pops as the symbol declares it) of a function symbol; None if unknown.
    cdecl pops 0; thiscall/stdcall their stack parameters; fastcall is left out (its first two dwords travel in
    registers and the type sizes decide which)."""
    m = re.match(r"_(\w+)@(\d+)$", sym)
    if m:
        return "STDCALL", int(m.group(2))
    if re.match(r"_\w+$", sym):
        return "CDECL", 0
    if not sym.startswith("?"):
        return None
    m = re.search(r"\b(__cdecl|__stdcall|__thiscall|__fastcall)\b", demangled)
    if not m:
        return None
    conv = CONV_WORDS[m.group(1)]
    if conv == "FASTCALL":
        return None
    if conv == "CDECL":
        return conv, 0
    rest = demangled[m.end():]
    i = rest.find("(")
    if i < 0:
        return None
    depth, j = 0, i
    for j in range(i, len(rest)):
        depth += {"(": 1, ")": -1}.get(rest[j], 0)
        if depth == 0:
            break
    params = rest[i + 1:j]
    # a class passed by value has a size the name doesn't say: not counted
    for p in re.split(r",(?![^<]*>)", params):
        if re.match(r"\s*(struct|class|union)\b", p) and "*" not in p and "&" not in p:
            return None
    nb, _n = param_bytes(params)
    if nb is None:
        return None
    return conv, nb


def rel32_symbols(objects_rsp):
    """Symbols some REL32 relocation (a call or jump) names in the link's objects (native_link's objects.rsp)."""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import compare
    out = set()
    for line in open(objects_rsp):
        o = line.strip().strip('"')
        if not o:
            continue
        if not os.path.isabs(o):
            o = os.path.join(ROOT, o)
        try:
            c = compare.Coff(o)
        except Exception:  # noqa: BLE001
            continue
        for _name, _raw, relocs in c.sections:
            for va, si, typ in relocs:
                if typ == 0x14:
                    t = c.by_index.get(si)
                    if t:
                        out.add(t[0])
    return out


def check_pops(path=BINDINGS, objects_rsp=None):
    """Check 7: every symbol the verified code calls (bindings.json: symbol -> XBE address) whose declared
    convention pops another number of argument bytes than the callee's `ret N` in the XBE. MSVC compiles such a
    call to the original's bytes when the next call reads what the callee left on the stack (matches/0x0024ed10:
    a five-argument `Data(...)` constructor declared over a two-argument init that pops 8, the base constructor
    after it reading the other three) or when the caller cleans up later; natively the stack is off by the
    difference. Returns (symbols checked, [disagreements])."""
    if not os.path.exists(path):
        return 0, []
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import capstone
    from xbe import Xbe
    xbe = Xbe(XBE)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    bj = json.load(open(path))
    b = bj["bindings"]
    syms = sorted(s for s in b if s.startswith("?"))
    dem = {}
    out = subprocess.run(["/opt/homebrew/opt/llvm/bin/llvm-undname"], input="\n".join(syms) + "\n",
                         capture_output=True, text=True, errors="replace").stdout.splitlines()
    for i in range(len(out) - 1):
        if out[i] in b and out[i] not in dem:
            dem[out[i]] = out[i + 1]
    text = next(sec for sec in xbe.sections if sec.name == ".text")
    # only symbols that are called (a REL32 relocation in the native link's objects): a function's address taken
    # for a stub vftable or a callback is no call (needs native_link's objects.rsp next to bindings.json)
    objects_rsp = objects_rsp or os.path.join(os.path.dirname(path), "link", "objects.rsp")
    called = rel32_symbols(objects_rsp) if os.path.exists(objects_rsp) else None
    rets_cache, bad, seen = {}, [], 0
    for s in sorted(b):
        a = int(b[s]["addr"], 16)
        if not (text.va <= a < text.va + text.vsize):
            continue
        if s.startswith("?") and ("@@6B" in s or re.match(r"\?\?_[78R]", s) or "@@3" in s):
            continue          # data (vftables, variables)
        if called is not None and s not in called:
            continue
        if re.match(r"__(all|aull)\w+$|__ftol|__CI", s):
            continue          # the compiler's own helpers (callee-pops by their own convention, not a declaration)
        d = declared_pops(s, dem.get(s, ""))
        if d is None:
            continue
        conv, nb = d
        if a not in rets_cache:
            rets_cache[a] = xbe_rets(xbe, md, a)
        rets, tails = rets_cache[a]
        if not rets:
            continue
        seen += 1
        pops = max(rets)
        if pops != nb or len(rets) > 1:
            bad.append(dict(symbol=s, addr="0x%08x" % a, conv=conv, declared=nb, callee=sorted(rets),
                            refs=bj.get("references", {}).get(s), demangled=dem.get(s, s)[:160],
                            why="declared %s popping %d, the callee returns with %s" % (
                                conv.lower(), nb, "/".join("ret %d" % r for r in sorted(rets)))))
    return seen, bad


def symbol_conv(s):
    """'cdecl' / 'stdcall' / 'fastcall' / 'thiscall' of a function symbol (C decoration or MS mangling), or None."""
    if not s:
        return None
    if s.startswith("?"):
        m = re.search(r"@@Y([AGIE])", s) or re.search(r"@@[QAIUMESC][AB]?([AEGI])", s)
        return {"A": "cdecl", "G": "stdcall", "I": "fastcall", "E": "thiscall"}[m.group(1)] if m else None
    if re.match(r"_\w+@\d+$", s):
        return "stdcall"
    if re.match(r"@\w+@\d+$", s):
        return "fastcall"
    return "cdecl" if re.match(r"_\w+$", s) else None


def check_definition_convs(path=BINDINGS):
    """Check 8: a caller's symbol in another calling convention than the definition the link aliases it to
    (matches/0x00275110 called the thiscall constructor 0x00274e60 as `void __stdcall FUN_00274e60(void*)`: ecx
    happened to hold `this` in the original, natively it doesn't). Some pairs are the same machine call (a
    fastcall definition whose only argument is in ecx, called as a thiscall member without arguments); the report
    counts each pair, the details list the ones that need ecx and don't set it (a cdecl/stdcall caller of a
    thiscall definition) first. Returns ({pair: count}, [details])."""
    if not os.path.exists(path):
        return {}, []
    b = json.load(open(path))["bindings"]
    pairs, bad = collections.Counter(), []
    for s, v in sorted(b.items()):
        d = v.get("def")
        if not d or d == s or "@@6B" in s or "@@3" in s:
            continue
        a, c = symbol_conv(s), symbol_conv(d)
        if a and c and a != c:
            pairs["%s caller, %s definition" % (a, c)] += 1
            if c == "thiscall" and a in ("cdecl", "stdcall"):
                bad.append(dict(symbol=s, definition=d, addr=v["addr"], why="%s caller of a thiscall definition" % a))
    return dict(pairs.most_common()), bad


def run(sources=True, bindings=True, xbe=True, tails=False, roots=("matches", "equivalent"), bindings_path=BINDINGS,
        returns=False, tree_report=TREE_REPORT, pops=False):
    """All checks; a JSON-able summary (counts and findings)."""
    imps = parse_imports()
    rep = {"imports": len(imps)}
    if sources:
        n, bad = check_sources(imps, roots)
        rep["sources"] = {"declarations": n, "disagreeing": bad}
    if bindings:
        n, bad = check_bindings(imps, bindings_path)
        rep["bindings"] = {"symbols": n, "disagreeing": bad}
    if xbe:
        bad, noret = check_xbe(imps)
        rep["xbe"] = {"checked": len(imps), "disagreeing": bad, "no_ret_reachable": noret}
    n, bad = check_register_orders(roots)
    rep["register_orders"] = {"functions": n, "disagreeing": bad}
    if pops:
        pairs, dbad = check_definition_convs(bindings_path)
        rep["definition_convs"] = {"pairs": pairs, "disagreeing": dbad}
        n, bad = check_pops(bindings_path)
        rep["pops"] = {"symbols": n, "disagreeing": bad}
    if returns and os.path.exists(tree_report):
        n, bad, helpers = check_returns(roots, tree_report)
        rep["returns"] = {"definitions": n, "disagreeing": bad}
        rep["x87_helpers"] = {"disagreeing": helpers}
    if tails:
        bad, n = check_tails(imps, roots)
        rep["tails"] = {"candidates": n, "disagreeing": bad}
    rep["findings"] = sum(len(v["disagreeing"]) for k, v in rep.items() if isinstance(v, dict))
    return rep


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--roots", nargs="+", default=["matches", "equivalent"])
    ap.add_argument("--no-xbe", action="store_true", help="skip the check against the callees' `ret N`")
    ap.add_argument("--tails", action="store_true", help="also compile functions that tail-jump to an import")
    ap.add_argument("--returns", action="store_true", help="check 6: results the original's callers use that a "
                    "verified definition doesn't return, and x87-argument helpers called by plain name (~1 min)")
    ap.add_argument("--pops", action="store_true", help="check 7: callee-pops bytes of every bound symbol against "
                    "the callee's `ret N`")
    ap.add_argument("--bindings", default=BINDINGS)
    ap.add_argument("--tree-report", default=TREE_REPORT, help="the tree build's report.json for --returns")
    ap.add_argument("--json")
    a = ap.parse_args(argv)
    rep = run(xbe=not a.no_xbe, tails=a.tails, roots=a.roots, returns=a.returns, tree_report=a.tree_report,
              pops=a.pops, bindings_path=a.bindings)
    print("stand-ins with a prototype: %d" % rep["imports"])
    s = rep["sources"]
    print("declarations of imports in the sources: %d; disagreeing with the tables: %d" % (s["declarations"], len(s["disagreeing"])))
    for b in s["disagreeing"]:
        print("  %s:%d  %s  [%s]" % (b["file"], b["line"], b["text"], b["why"]))
    s = rep["bindings"]
    print("symbols bound to imports: %d; mangled convention disagreeing: %d" % (s["symbols"], len(s["disagreeing"])))
    for x in s["disagreeing"]:
        print("  %s -> %s: %s, table %s" % (x["symbol"], x["import_"], x["conv"], x["table"]))
    if "xbe" in rep:
        s = rep["xbe"]
        print("imports checked against the XBE's ret N: %d; disagreeing: %d; no ret reachable: %s" % (
            s["checked"], len(s["disagreeing"]), ", ".join(s["no_ret_reachable"]) or "none"))
        for x in s["disagreeing"]:
            print("  %s %s: %s %s" % (x["addr"], x["import_"], x["note"], x["tails"] or ""))
    s = rep["register_orders"]
    print("register-convention functions (equiv-conv) with their own note: %d; callers listing another parameter "
          "order: %d" % (s["functions"], len(s["disagreeing"])))
    for x in s["disagreeing"]:
        print("  %s %s: %s (definition %s: %s)" % (x["addr"], x["file"], x["conv"], x["definition"], x["definition_conv"]))
    if "pops" in rep:
        s = rep["pops"]
        print("bound symbols with a declared callee-pops count: %d; disagreeing with the callee's ret N: %d" % (
            s["symbols"], len(s["disagreeing"])))
        for x in s["disagreeing"]:
            print("  %s %s  [%s]" % (x["addr"], x["symbol"], x["why"]))
    if "definition_convs" in rep:
        s = rep["definition_convs"]
        print("caller symbols in another convention than their definition: %s; cdecl/stdcall callers of a thiscall "
              "definition: %d" % (s["pairs"], len(s["disagreeing"])))
    if "returns" in rep:
        s = rep["returns"]
        print("verified definitions with a return kind: %d; whose original callers use a result they don't return: %d"
              % (s["definitions"], len(s["disagreeing"])))
        for x in s["disagreeing"]:
            print("  %s %s  %s  [%s]" % (x["addr"], x["file"], x["symbol"], x["why"]))
        s = rep["x87_helpers"]
        print("sources calling an x87-argument helper by a plain name: %d" % len(s["disagreeing"]))
        for x in s["disagreeing"]:
            print("  %s  %s (%s)" % (x["file"], x["name"], x["helper"]))
    if "tails" in rep:
        s = rep["tails"]
        print("functions tail-jumping to an import: %d; declared __cdecl though the import pops: %d" % (s["candidates"], len(s["disagreeing"])))
        for t in s["disagreeing"]:
            print("  %s  %s  [%s]" % (t["file"], t["symbol"], t["why"]))
    if a.json:
        with open(a.json, "w") as f:
            json.dump(rep, f, indent=1)
    return 1 if rep["findings"] else 0


if __name__ == "__main__":
    sys.exit(main())
