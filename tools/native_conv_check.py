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
    for a, (f0, l0) in sorted(own.items()):
        for f, l in notes.get(a, []):
            if l != l0:
                bad.append(dict(addr="0x%08x" % a, file=f, conv=" ".join(l), definition=f0, definition_conv=" ".join(l0),
                                why="parameter order %s, the definition's %s" % (" ".join(l), " ".join(l0))))
    return len(own), bad


def run(sources=True, bindings=True, xbe=True, tails=False, roots=("matches", "equivalent"), bindings_path=BINDINGS):
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
    ap.add_argument("--json")
    a = ap.parse_args(argv)
    rep = run(xbe=not a.no_xbe, tails=a.tails, roots=a.roots)
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
