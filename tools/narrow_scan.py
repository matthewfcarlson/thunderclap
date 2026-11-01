#!/usr/bin/env python3
"""Scan matches/ and equivalent/ for declarations narrower than what the original uses (sweep1, 2026-11-01).

MSVC's frame layout and register use can hide a type that is too small: the byte match (or equiv.py on the MSVC object)
passes, but the clang Wine/native build lays the frame out differently or reads all of a register. Cases found by
replay bisects (docs/journal.md, crash1 and div2):

  ret64    a 32-bit (or void) declaration of a function whose original callers read edx after the call (0x000faeb0).
  ret      a bool/char/short return where the original sets all of eax and a caller reads it (XboxSaveDrive::vfunc_11):
           the original's return paths (`mov eax, 1` / `xor eax, eax` vs `mov al, 1` / `setcc al`) and its direct
           callers' first read of eax (`test eax, eax` vs `test al, al`).
  stack    a local or parameter smaller than the original's slot (a 12-byte SYSTEMTIME where GetLocalTime writes 16):
           each source is compiled by MSVC with /Z7 (CodeView locals, frame offsets and type sizes) and /Oy- (ebp
           frames), and the frame is checked for direct ebp accesses that hit no declared variable, and for
           address-taken variables followed by unexplained slack (holes MSVC leaves only where our type is short).
  byval    a by-value parameter whose address escapes (`&p`, `p.method()`), followed by a parameter the body never
           uses: an 8-byte id declared `struct {int a;}` + `int y` (div2, 0x001f96b0).
  extern   a block-scope function/variable declaration inside a function in a namespace: MSVC 7.1 mangles it at
           global scope, clang in the namespace, so the Wine build leaves it unbound (crash1, 0x0023ec10).
  fsel     a `float` ?: or local initialised from a call that returns st(0): MSVC keeps st(0), clang rounds
           (div2, 0x0003c1d0); a heuristic, the x87 scanner (tools/x87_scan.py) is the thorough one.

  build/venv/bin/python tools/narrow_scan.py ret   [--out build/sweep1/ret.tsv] [SRC ...]
  build/venv/bin/python tools/narrow_scan.py ret64 [--out build/sweep1/ret64.tsv] [SRC ...]  # 64-bit returns declared int
  build/venv/bin/python tools/narrow_scan.py retjoin build/sweep1/ret.tsv build/sweep1/stack.jsonl # virtual narrow returns
  build/venv/bin/python tools/narrow_scan.py src   [--out build/sweep1/src.tsv] [SRC ...]   # byval, extern, fsel
  build/venv/bin/python tools/narrow_scan.py stack SRC ... | --list LIST [--out OUT.jsonl] [--jobs N]
  build/venv/bin/python tools/narrow_scan.py stack --all --jobq --name ME --out build/sweep1/stack.jsonl [--per 400]
  build/venv/bin/python tools/narrow_scan.py report build/sweep1/stack.jsonl              # stack candidates, ranked

Every class lists candidates, not bugs: each needs a look at the source and the original (tools/packet.py show).
"""
import argparse
import glob
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

M32 = 0xFFFFFFFF


def all_sources():
    out = []
    for d in ("matches", "equivalent"):
        for f in sorted(glob.glob(os.path.join(ROOT, d, "0x*.cpp"))):
            out.append((int(os.path.basename(f)[2:10], 16), os.path.relpath(f, ROOT)))
    return out


def addr_of(src):
    m = re.search(r"0x([0-9a-fA-F]{8})", os.path.basename(src))
    return int(m.group(1), 16) if m else None


def strip_comments(s):
    s = re.sub(r"/\*.*?\*/", lambda m: " " * len(m.group(0)), s, flags=re.S)
    return re.sub(r"//[^\n]*", "", s)


# ============================================================================================ ret
RET_ANY = re.compile(r"@@(?:Y[AGI]|[ABEFIJMNQRUV][A-D][AEGI]|[CDKLST][AEGI])(_N|[A-Z])")
NARROW_RET = {"_N": "bool", "D": "char", "C": "signed char", "E": "unsigned char", "F": "short", "G": "unsigned short"}
RET_RX = re.compile(r"@@(?:Y[AGI]|[ABEFIJMNQRUV][A-D][AEGI]|[CDKLST][AEGI])(_N|[CDEFG])")


def narrow_return(sym):
    """'bool'/'char'/... when the mangled name returns a narrow integer, else None."""
    if not sym or not sym.startswith("?") or sym.startswith("??"):
        return None
    m = RET_RX.search(sym)
    return NARROW_RET.get(m.group(1)) if m else None


def target_symbol(src, addr, defs):
    """Our definition's mangled name for ADDR: the binding map's definition, else the source's declared return type."""
    s = defs.get("0x%08x" % addr)
    if s:
        return s
    return None


SRC_RET_RX = re.compile(r"^\s*(?:virtual\s+|static\s+|inline\s+|__forceinline\s+)*(bool|char|unsigned\s+char|signed\s+char|"
                        r"short|unsigned\s+short|u8|s8|u16|s16|uchar|ushort|BOOLEAN|BYTE|WORD)\s+(?:__\w+\s+)?"
                        r"([\w:~]+)\s*\(", re.M)


def classify_writer(ci):
    """'full_const' / 'full' / 'narrow' / 'call' / None for an instruction that writes eax, ax or al."""
    ops = [o.strip() for o in ci.op_str.split(",")] if ci.op_str else []
    mn = ci.mnemonic
    if mn == "call":
        return "call"
    if not ops:
        if mn in ("cdq", "cwde", "cbw", "lodsd", "lodsb"):
            return {"cwde": "full", "cbw": "narrow", "lodsd": "full", "lodsb": "narrow"}.get(mn)
        return None
    dst = ops[0]
    if mn in ("cmp", "test", "push") or mn.startswith(("j", "f")):
        return None
    if dst in ("eax",):
        if mn == "xor" and len(ops) == 2 and ops[1] == "eax":
            return "full_const"
        if mn == "sub" and len(ops) == 2 and ops[1] == "eax":
            return "full_const"
        if mn == "or" and len(ops) == 2 and ops[1] in ("0xffffffff", "-1"):
            return "full_const"
        if mn == "mov" and len(ops) == 2 and re.match(r"^-?(0x[0-9a-f]+|\d+)$", ops[1]):
            return "full_const"
        if mn in ("movzx", "movsx") and len(ops) == 2 and re.match(r"^(al|ax|byte|word)", ops[1]):
            return "ext"
        return "full"
    if dst in ("al", "ax", "ah"):
        if mn == "xchg":
            return "full"
        return "narrow"
    return None


def writes_eax(ci):
    try:
        _, w = ci.regs_access()
        wn = {ci.reg_name(x) for x in w}
    except Exception:  # noqa: BLE001
        return False
    return bool(wn & {"eax", "ax", "al", "ah"})


def ret_paths(insns):
    """Counts of how return paths set eax: {full_const, full, ext, narrow, call, unknown} over a linear listing."""
    jump_from = {}
    for k, ci in enumerate(insns):
        if ci.mnemonic.startswith("j") and ci.op_str.startswith("0x"):
            try:
                t = int(ci.op_str, 16)
            except ValueError:
                continue
            jump_from.setdefault(t, []).append(k)
    counts = {}
    seen = set()

    def walk(k):
        # explore the predecessors of instruction k back to the instruction that last set eax
        while True:
            if k in seen:
                return
            seen.add(k)
            for j in jump_from.get(insns[k].address, ()):
                walk(j)
            if k == 0:
                counts["unknown"] = counts.get("unknown", 0) + 1
                return
            prev = insns[k - 1]
            if prev.mnemonic in ("ret", "jmp"):
                if not jump_from.get(insns[k].address):
                    counts["unknown"] = counts.get("unknown", 0) + 1
                return
            if writes_eax(prev) or prev.mnemonic == "call":
                c = classify_writer(prev)
                if c:
                    counts[c] = counts.get(c, 0) + 1
                    return
            k -= 1

    for k, ci in enumerate(insns):
        if ci.mnemonic == "ret":
            seen.discard(k)
            walk(k)
    return counts


def callee_side(prog, addr):
    size = prog.funcs.get(addr, (0,))[0]
    if not size:
        return None
    return ret_paths(list(prog.md.disasm(prog.read(addr, size), addr)))


def caller_side(prog, target):
    """{'full': n, 'narrow': n, 'pass': n, 'none': n, 'sites': n} over the direct call sites of the original."""
    import equiv
    out = {"full": 0, "narrow": 0, "pass": 0, "push": 0, "none": 0, "sites": 0, "full_at": []}
    for site in prog.call_sites(target)[:60]:
        out["sites"] += 1
        a = site + 5
        res = "none"
        for _ in range(12):
            ci = next(prog.md.disasm(prog.read(a, 16), a, 1), None)
            if ci is None:
                break
            mn = ci.mnemonic
            rn, wn = prog._regs_rw(ci)
            try:
                r_, _ = ci.regs_access()
                rd = {ci.reg_name(x) for x in r_}
            except Exception:  # noqa: BLE001
                rd = set()
            ops = [o.strip() for o in ci.op_str.split(",")]
            if mn in ("xor", "sub") and len(ops) == 2 and ops[0] == ops[1]:
                rd = set()          # xor eax, eax: a write
            if not ("eax" in rn or rd & {"al", "ax", "eax"}):
                rd = set()
            if mn == "ret":
                res = "pass"
                break
            if mn == "push" and ci.op_str == "eax":
                res = "push"
                break
            if rd & {"al", "ax", "eax", "ah"}:
                if "eax" in rd and mn not in ("push",):
                    if mn == "mov" and re.match(r"^e[a-ds][xip]$", ci.op_str.split(",")[0].strip()):
                        res = "push"    # copied to another register: undecided
                    else:
                        res = "full"
                else:
                    res = "narrow"
                break
            if "eax" in wn or mn in ("call", "jmp") or mn.startswith("j"):
                break
            a += ci.size
        out[res] += 1
        if res == "pass":
            out.setdefault("pass_from", []).append(site)
        if res == "full":
            out["full_at"].append("0x%08x" % site)
    return out


def cmd_ret(a):
    import equiv
    prog = equiv.Program.get()
    defs = {}
    bp = a.bindings
    if bp and os.path.exists(bp):
        defs = json.load(open(bp)).get("definitions", {})
    items = [(addr_of(s), s) for s in a.srcs] if a.srcs else all_sources()
    rows = []
    for addr, src in items:
        sym = target_symbol(src, addr, defs)
        kind = narrow_return(sym)
        if kind is None and sym is None:
            # no binding: look at the source's own declaration of the function
            txt = strip_comments(open(os.path.join(ROOT, src), errors="replace").read())
            m = SRC_RET_RX.search(txt)
            if m and ("FUN_%08x" % addr in m.group(2) or "vfunc" in m.group(2) or "target" in m.group(2)):
                kind = re.sub(r"\s+", " ", m.group(1))
        if not kind or addr not in prog.funcs:
            continue
        cs = callee_side(prog, addr) or {}
        cl = caller_side(prog, addr)
        virt = addr in prog.virtual_funcs
        full_ret = cs.get("full_const", 0) + cs.get("full", 0)
        narrow_ret = cs.get("narrow", 0)
        score = 0
        why = []
        if full_ret and not narrow_ret:
            score += 2 if cs.get("full_const") else 1
            why.append("original sets all of eax on every classified return path")
        if cl["full"]:
            score += 3
            why.append("direct caller(s) read all of eax: " + " ".join(cl["full_at"][:4]))
        for site in cl.get("pass_from", []):
            f = prog.containing_func(site)
            fa = f[0] if isinstance(f, tuple) else f
            if fa is None:
                continue
            ps = defs.get("0x%08x" % fa)
            if ps and ps.startswith("?") and not narrow_return(ps) and RET_ANY.search(ps) and \
                    RET_ANY.search(ps).group(1) in "HIJK":
                score += 2
                why.append("passed on as the int return of 0x%08x (%s)" % (fa, ps[:60]))
        if cl["narrow"] and not cl["full"]:
            score -= 2
        if narrow_ret:
            score -= 2
        rows.append((score, "0x%08x" % addr, src, kind, "virtual" if virt else "direct", cs, cl, "; ".join(why)))
    rows.sort(key=lambda r: (-r[0], r[1]))
    out = open(a.out, "w") if a.out else sys.stdout
    out.write("score\taddr\tsrc\tret\treach\tcallee_paths\tcallers\twhy\n")
    for r in rows:
        cs = ",".join("%s=%d" % kv for kv in sorted(r[5].items()))
        cl = "sites=%d full=%d narrow=%d pass=%d push=%d" % (r[6]["sites"], r[6]["full"], r[6]["narrow"], r[6]["pass"], r[6]["push"])
        out.write("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" % (r[0], r[1], r[2], r[3], r[4], cs, cl, r[7]))
    n = sum(1 for r in rows if r[0] > 0)
    print("ret: %d narrow-return functions, %d candidates (score > 0)" % (len(rows), n), file=sys.stderr)


def edx_read_after(prog, site):
    """(addr, text) of the first instruction after `call` at SITE that reads edx before anything writes it, else None."""
    a = site + 5
    for _ in range(12):
        ci = next(prog.md.disasm(prog.read(a, 16), a, 1), None)
        if ci is None:
            return None
        mn = ci.mnemonic
        try:
            r_, w_ = ci.regs_access()
            rd = {ci.reg_name(x) for x in r_}
            wr = {ci.reg_name(x) for x in w_}
        except Exception:  # noqa: BLE001
            return None
        ops = [o.strip() for o in ci.op_str.split(",")] if ci.op_str else []
        if mn in ("xor", "sub") and len(ops) == 2 and ops[0] == ops[1]:
            rd = set()
        if mn in ("call", "ret", "jmp") or mn.startswith("j"):
            return None
        if rd & {"edx", "dx", "dl", "dh"}:
            return "0x%08x" % ci.address, mn + " " + ci.op_str
        if wr & {"edx", "dx", "dl", "dh"}:
            return None
        a += ci.size
    return None


def cmd_ret64(a):
    """ret64: a function declared to return 32 bits or less (or void) whose original callers read edx right after the
    call (`push edx; push eax`): it returns 64 bits in edx:eax (0x000faeb0 Iter::Run passed b()'s __int64 on). Also lists
    callers that rely on a callee preserving edx (custom/LTCG conventions): those need a look, not a type."""
    import equiv
    prog = equiv.Program.get()
    defs = json.load(open(a.bindings)).get("definitions", {}) if a.bindings and os.path.exists(a.bindings) else {}
    items = [(addr_of(s), s) for s in a.srcs] if a.srcs else all_sources()
    out = open(a.out, "w") if a.out else sys.stdout
    out.write("addr\tsrc\tret\tsites\tedx_reads\tsymbol\n")
    n = 0
    for addr, src in items:
        sym = defs.get("0x%08x" % addr)
        sig = equiv.parse_signature(sym) if sym else None
        rk = sig.get("ret") if sig else None
        if rk in ("i64", "f64", "f32", "struct"):
            continue
        sites = prog.call_sites(addr)[:60]
        hits = [h for h in (edx_read_after(prog, x) for x in sites) if h]
        if hits:
            n += 1
            out.write("0x%08x\t%s\t%s\t%d\t%s\t%s\n" % (addr, src, rk, len(sites), " ".join("%s:%s" % h for h in hits[:3]), sym or ""))
    print("ret64: %d candidates" % n, file=sys.stderr)


# ============================================================================================ src (byval, extern, fsel)
def split_params(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def find_bodies(txt):
    """[(name, params text, body start, body end, namespace stack)] for function definitions (brace matching)."""
    out = []
    ns = []          # (name, depth at open)
    depth = 0
    i = 0
    n = len(txt)
    func_rx = re.compile(r"([\w:~<>]+)\s*\(([^;{}()]*(?:\([^()]*\)[^;{}()]*)*)\)\s*(?:const\s*)?(?:throw\s*\([^)]*\)\s*)?"
                         r"(?::[^{;]*)?\{$")
    while i < n:
        ch = txt[i]
        if ch == "{":
            pre = txt[max(0, i - 600):i + 1]
            mn = re.search(r"namespace\s*(\w*)\s*\{$", pre)
            mf = func_rx.search(pre)
            if mn:
                ns.append((mn.group(1) or "<anon>", depth))
                depth += 1
                i += 1
                continue
            if mf and mf.group(1) not in ("if", "while", "for", "switch", "catch", "sizeof", "return") and \
                    not re.search(r"\b(struct|class|union|enum)\s+[\w:]*\s*(:[^{;]*)?\{$", pre[-200:]):
                # find matching close
                d, j = 1, i + 1
                while j < n and d:
                    if txt[j] == "{":
                        d += 1
                    elif txt[j] == "}":
                        d -= 1
                    j += 1
                out.append((mf.group(1), mf.group(2), i + 1, j - 1, [x[0] for x in ns]))
                i = j
                continue
            depth += 1
        elif ch == "}":
            depth -= 1
            if ns and ns[-1][1] == depth:
                ns.pop()
        i += 1
    return out


SCALAR = {"int", "unsigned", "long", "short", "char", "bool", "float", "double", "u8", "u16", "u32", "s8", "s16", "s32",
          "unsigned int", "unsigned long", "unsigned short", "unsigned char", "signed char", "int*", "void*"}


_NAMESPACES = None


def known_namespaces(txt):
    """Namespace names: every `namespace X` in include/ and in this source."""
    global _NAMESPACES
    if _NAMESPACES is None:
        ns = set()
        for dp, _, fns in os.walk(os.path.join(ROOT, "include")):
            for fn in fns:
                if fn.endswith((".h", ".hpp", ".inc")):
                    try:
                        ns.update(re.findall(r"\bnamespace\s+(\w+)", open(os.path.join(dp, fn), errors="replace").read()))
                    except OSError:
                        pass
        _NAMESPACES = ns
    return _NAMESPACES | set(re.findall(r"\bnamespace\s+(\w+)", txt))


def scan_src(src):
    txt = strip_comments(open(os.path.join(ROOT, src), errors="replace").read())
    found = []
    nss = known_namespaces(txt)
    structs = set(re.findall(r"\b(?:struct|class|union)\s+(\w+)", txt))
    for name, params, b0, b1, ns in find_bodies(txt):
        body = txt[b0:b1]
        # ---- byval: an address-taken by-value parameter followed by an unused parameter
        ps = split_params(params) if params.strip() not in ("", "void") else []
        parsed = []
        for p in ps:
            p2 = re.sub(r"=.*$", "", p).strip()
            m = re.match(r"^(?:const\s+)?((?:unsigned\s+|signed\s+|struct\s+|class\s+)?[\w:]+(?:\s*\*+)?)\s*(\w+)?$", p2)
            if m:
                parsed.append((m.group(1).strip(), m.group(2)))
            else:
                parsed.append((p2, None))
        for k, (t, nm) in enumerate(parsed):
            if not nm:
                continue
            esc = re.search(r"&\s*%s\b(?!\s*[.\[]|\s*->)" % re.escape(nm), body) or \
                (t.split("::")[-1] in structs and "*" not in t and re.search(r"\b%s\s*\.\s*\w+\s*\(" % re.escape(nm), body))
            if not esc or "*" in t or "&" in t:
                continue
            if k + 1 < len(parsed):
                t2, nm2 = parsed[k + 1]
                if nm2 is None or not re.search(r"\b%s\b" % re.escape(nm2), body):
                    found.append(("byval", name, "%s %s escapes; next parameter %s %s is unused" % (t, nm, t2, nm2 or "(unnamed)")))
                    continue
            if t.split("::")[-1] in structs:
                # clang copies a by-value struct parameter into a local of its declared size (a scalar it leaves in
                # place): a callee that reads past that size sees the copy's neighbours, not the next argument
                found.append(("byval_struct", name, "by-value struct %s %s escapes (callee must not read past its size)" % (t, nm)))
        # ---- extern: block-scope declarations inside a namespace (lexically, or a qualified definition `ns::C::f`)
        quals = name.split("::")[:-1]
        if not ns and any(q in nss for q in quals):
            ns = [q for q in quals if q in nss]
        if ns:
            for m in re.finditer(r"(?:^|[;{}])\s*(extern\s+[^;{}=()]*\b(\w+)\s*(\([^;{}]*\))?\s*;|"
                                 r"(?:void|int|bool|float|unsigned|char|short|long|[\w:]+\s*\*)\s+(?:__\w+\s+)?(\w+)\s*\([^;{}()]*\)\s*;)",
                                 body):
                decl = m.group(1).strip()
                if decl.startswith(("return", "delete", "new", "else", "goto")):
                    continue
                if re.match(r"^(?:void|int|bool|float|unsigned|char|short|long|[\w:]+\s*\*)\s+\w+\s*\(\s*\)\s*;$", decl) and \
                        not decl.startswith("extern"):
                    pass
                if not decl.startswith("extern") and re.search(r"\(\s*[\w.\->&*]+\s*(,\s*[\w.\->&*]+\s*)*\)\s*;$", decl) and \
                        not re.search(r"\(\s*((const\s+)?[\w:]+\s*[*&]*\s*\w*\s*(,|\)))", decl):
                    continue      # a call or initialisation, not a declaration
                if not decl.startswith("extern"):
                    # `T* f(args);` is a declaration only when the parentheses hold types
                    inner = re.search(r"\(([^()]*)\)", decl)
                    if inner and inner.group(1).strip() and not re.match(
                            r"^\s*(void|(const\s+)?(unsigned\s+|signed\s+|struct\s+|class\s+)?[\w:]+(\s*[*&]+)?(\s+\w+)?)\s*(,|$)",
                            inner.group(1).strip()):
                        continue
                    if inner and inner.group(1).strip() and re.match(r"^\s*[a-z_]\w*\s*(,|$)", inner.group(1).strip()) and \
                            inner.group(1).strip().split(",")[0].strip() not in ("void", "int", "unsigned", "float", "char",
                                                                                   "bool", "short", "long", "double"):
                        continue
                found.append(("extern", name, "block-scope `%s` inside namespace %s" % (re.sub(r"\s+", " ", decl), "::".join(ns))))
        # ---- fsel: a float ?: (a float local, or an arm that is a float literal) whose other arm is a call
        for m in re.finditer(r"\b(float|hulk_freg)\s+(\w+)\s*=\s*([^;]*\?[^;]*:[^;]*);", body):
            e = m.group(3)
            if not re.search(r"\w\s*\([^()]*\)", e) or re.search(r"\(hulk_freg\)", e):
                continue
            if m.group(1) == "float" or re.search(r"[?:]\s*\(?-?\d+\.\d*f\b", e):
                found.append(("fsel", name, "%s %s = %s" % (m.group(1), m.group(2), re.sub(r"\s+", " ", e)[:120])))
    return found


def cmd_src(a):
    items = [(addr_of(s), s) for s in a.srcs] if a.srcs else all_sources()
    out = open(a.out, "w") if a.out else sys.stdout
    out.write("class\taddr\tsrc\tfunction\tnote\n")
    counts = {}
    for addr, src in items:
        try:
            for cls, fn, note in scan_src(src):
                counts[cls] = counts.get(cls, 0) + 1
                out.write("%s\t0x%08x\t%s\t%s\t%s\n" % (cls, addr or 0, src, fn, note))
        except Exception as e:  # noqa: BLE001
            print("%s: %s" % (src, e), file=sys.stderr)
    print("src: %s" % counts, file=sys.stderr)


# ============================================================================================ stack (MSVC /Z7 CodeView)
S_END, S_GPROC32, S_LPROC32, S_BPREL32, S_REGREL32, S_BLOCK32, S_FRAMEPROC = 0x6, 0x1110, 0x110F, 0x110B, 0x1111, 0x1103, 0x1012
S_GPROC32_ID, S_LPROC32_ID, S_PROC_ID_END, S_REGISTER, S_INLINESITE, S_INLINESITE_END = 0x1147, 0x1146, 0x114F, 0x1106, 0x114D, 0x114E
PRIM_SIZE = {0x00: 0, 0x03: 0, 0x10: 1, 0x20: 1, 0x30: 1, 0x68: 1, 0x69: 1, 0x70: 1, 0x71: 2, 0x7A: 2, 0x7B: 4,
             0x11: 2, 0x21: 2, 0x72: 2, 0x73: 2, 0x12: 4, 0x22: 4, 0x74: 4, 0x75: 4, 0x13: 8, 0x23: 8, 0x76: 8, 0x77: 8,
             0x40: 4, 0x41: 8, 0x42: 10, 0x08: 4}


def numeric_leaf(b, o):
    v = struct.unpack_from("<H", b, o)[0]
    if v < 0x8000:
        return v, o + 2
    sz = {0x8000: 1, 0x8001: 2, 0x8002: 2, 0x8003: 4, 0x8004: 4, 0x8009: 8, 0x800A: 8}.get(v)
    if sz is None:
        return 0, o + 2
    fmt = {1: "<b", 2: "<h", 4: "<i", 8: "<q"}[sz]
    if v in (0x8002, 0x8004, 0x800A):
        fmt = fmt.upper()
    return struct.unpack_from(fmt, b, o + 2)[0], o + 2 + sz


class Types:
    def __init__(self, data):
        self.recs = {}
        if not data or len(data) < 4:
            return
        o, ti = 4, 0x1000
        while o + 4 <= len(data):
            ln, kind = struct.unpack_from("<HH", data, o)
            self.recs[ti] = (kind, data[o + 4:o + 2 + ln])
            o += 2 + ln
            ti += 1

    def size(self, ti, depth=0):
        if ti < 0x1000:
            mode = (ti >> 8) & 7
            if mode:
                return 4      # near32 pointer
            return PRIM_SIZE.get(ti & 0xFF, 0)
        r = self.recs.get(ti)
        if r is None or depth > 20:
            return 0
        kind, b = r
        try:
            if kind == 0x1002:            # LF_POINTER
                return 4
            if kind == 0x1001:            # LF_MODIFIER
                return self.size(struct.unpack_from("<I", b, 0)[0], depth + 1)
            if kind == 0x1503:            # LF_ARRAY
                return numeric_leaf(b, 8)[0]
            if kind in (0x1504, 0x1505):  # LF_CLASS / LF_STRUCTURE
                return numeric_leaf(b, 16)[0]
            if kind == 0x1506:            # LF_UNION
                return numeric_leaf(b, 8)[0]
            if kind == 0x1507:            # LF_ENUM
                return self.size(struct.unpack_from("<I", b, 4)[0], depth + 1)
        except struct.error:
            return 0
        return 0

    def name(self, ti):
        r = self.recs.get(ti)
        if ti < 0x1000:
            return "prim%x" % ti
        if not r:
            return "?"
        kind, b = r
        if kind in (0x1504, 0x1505, 0x1506):
            off = 16 if kind != 0x1506 else 8
            _, o = numeric_leaf(b, off)
            return b[o:b.index(b"\0", o)].decode(errors="replace") if b"\0" in b[o:] else "?"
        if kind == 0x1503:
            return "%s[]" % self.name(struct.unpack_from("<I", b, 0)[0])
        if kind == 0x1001:
            return self.name(struct.unpack_from("<I", b, 0)[0])
        return {0x1002: "ptr", 0x1507: "enum"}.get(kind, "k%x" % kind)

    def is_fwdref(self, ti):
        r = self.recs.get(ti)
        if not r or r[0] not in (0x1504, 0x1505, 0x1506):
            return False
        return bool(struct.unpack_from("<H", r[1], 2)[0] & 0x80)


def cv_procs(coff, types):
    """{proc name: {'locals': [(name, off, size, type name)], 'params': [...], 'regs': [...], 'offset', 'len', 'sec'}}
    from the object's .debug$S sections (each COMDAT function has its own associated section)."""
    procs = {}
    for si, (name, data, relocs) in enumerate(coff.sections):
        if name != ".debug$S" or len(data) < 8:
            continue
        o = 4
        while o + 8 <= len(data):
            sub, ln = struct.unpack_from("<II", data, o)
            base = o + 8
            if sub == 0xF1 and ln == 0:
                # MSVC 7.1: an empty symbol subsection header, then the records run to the end of the section
                body = data[o + 8:]
                o = len(data)
            else:
                body = data[o + 8:o + 8 + ln]
                o = (o + 8 + ln + 3) & ~3
            if sub != 0xF1:
                continue
            k = 0
            cur = None
            while k + 4 <= len(body):
                rl, rk = struct.unpack_from("<HH", body, k)
                rb = body[k + 4:k + 2 + rl]
                if rk in (S_GPROC32, S_LPROC32):
                    plen, = struct.unpack_from("<I", rb, 12)
                    dbg_start, dbg_end = struct.unpack_from("<II", rb, 16)
                    nm = rb[35:rb.index(b"\0", 35)].decode(errors="replace")
                    # which section/offset: the relocation at this record's offset field
                    sec = None
                    for (roff, rsym, rtyp) in relocs:
                        if roff == base + k + 4 + 28:
                            sec = rsym
                    cur = {"name": nm, "len": plen, "vars": [], "regs": [], "dbg": (dbg_start, dbg_end), "sym": sec}
                    procs[nm + "#%d" % si] = cur
                elif rk == S_BPREL32 and cur is not None:
                    off, ti = struct.unpack_from("<iI", rb, 0)
                    nm = rb[8:rb.index(b"\0", 8)].decode(errors="replace")
                    cur["vars"].append({"name": nm, "off": off, "ti": ti, "size": types.size(ti), "type": types.name(ti),
                                        "fwd": types.is_fwdref(ti)})
                elif rk == S_REGREL32 and cur is not None:
                    off, ti, reg = struct.unpack_from("<iIH", rb, 0)
                    nm = rb[10:rb.index(b"\0", 10)].decode(errors="replace")
                    cur["vars"].append({"name": nm, "off": off, "ti": ti, "size": types.size(ti), "type": types.name(ti),
                                        "reg": reg, "fwd": types.is_fwdref(ti)})
                elif rk == S_REGISTER and cur is not None:
                    ti, reg = struct.unpack_from("<IH", rb, 0)
                    nm = rb[6:rb.index(b"\0", 6)].decode(errors="replace")
                    cur["regs"].append(nm)
                k += 2 + rl
    return procs


def fwd_sizes(types):
    """Full definitions' sizes by name, for forward references (records with the fwdref bit point to no size)."""
    out = {}
    for ti, (kind, b) in types.recs.items():
        if kind in (0x1504, 0x1505, 0x1506) and not types.is_fwdref(ti):
            out[types.name(ti)] = types.size(ti)
    return out


def ebp_accesses(code):
    """([(insn offset, ebp displacement, access width, mnemonic, is_lea)] for every [ebp+disp] operand,
    compiler-owned frame ranges [(lo, hi)]: the /GS cookie slot and the /GX EH registration record)."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    out, owned, written = [], [], set()
    insns = list(md.disasm(code, 0))
    for k, ci in enumerate(insns):
        if ci.op_str.startswith("dword ptr fs:") or ", dword ptr fs:" in ci.op_str or "fs:[" in ci.op_str:
            owned.append((-16, 0))          # EH: state, handler, next record, saved esp
        for op in ci.operands:
            if op.type == capstone.x86.X86_OP_MEM and ci.reg_name(op.mem.base) == "ebp" and op.mem.index == 0:
                out.append((ci.address, op.mem.disp, op.size, ci.mnemonic, ci.mnemonic == "lea"))
                if ((op.access & capstone.CS_AC_WRITE) or ci.mnemonic.startswith(("fst", "fist", "fnst"))) and \
                        ci.mnemonic != "lea" and op.size in (4, 8):
                    written.add(op.mem.disp)       # a dword/qword store (x87 stores too): a spill or temporary slot
        # the /GS cookie: `mov eax, [___security_cookie]` (an unrelocated absolute load) then `mov [ebp-N], eax`
        if ci.mnemonic == "mov" and k + 1 < len(insns) and len(ci.operands) == 2 and \
                ci.operands[1].type == capstone.x86.X86_OP_MEM and ci.operands[1].mem.base == 0 and \
                ci.operands[1].mem.index == 0 and ci.operands[1].mem.disp == 0:
            reg = ci.reg_name(ci.operands[0].reg) if ci.operands[0].type == capstone.x86.X86_OP_REG else None
            for nx in insns[k + 1:k + 10]:
                if nx.mnemonic == "mov" and len(nx.operands) == 2 and nx.operands[0].type == capstone.x86.X86_OP_MEM and \
                        nx.reg_name(nx.operands[0].mem.base) == "ebp" and nx.operands[1].type == capstone.x86.X86_OP_REG and \
                        nx.reg_name(nx.operands[1].reg) == reg:
                    d = nx.operands[0].mem.disp
                    if d < 0:
                        owned.append((d, d + 4))
                    break
                try:
                    if reg in {nx.reg_name(x) for x in nx.regs_access()[1]}:
                        break
                except Exception:  # noqa: BLE001
                    break
    # a slot the function itself stores to and that no declared variable covers is a spill of a register variable or a
    # temporary (MSVC records those as S_REGISTER, not by frame offset); the caller drops those (hole kind needs reads only)
    return out, owned, written


def analyse_proc(p, code, fsz):
    """Frame holes hit by direct accesses, and address-taken variables followed by slack."""
    vs = []
    for v in p["vars"]:
        size = v["size"]
        if v["fwd"]:
            size = fsz.get(v["type"], size)
        vs.append(dict(v, size=size))
    issues = []
    if not vs or not code:
        return issues
    # with /Oy- the frame base is ebp: params at ebp+8.., locals below ebp. BPREL offsets are ebp-relative here.
    cover = []
    for v in vs:
        if v.get("reg") not in (None, 22):   # REGREL32 relative to ebp (CV_REG_EBP = 22) only
            continue
        cover.append((v["off"], v["off"] + max(v["size"], 1), v))
    if not cover:
        return issues
    acc, owned, written = ebp_accesses(code)
    locs = sorted((c for c in cover if c[0] < 0), key=lambda c: (c[0], c[1]))
    lo_frame = min([c[0] for c in locs], default=0)

    def owner(d, w):
        for a0, a1, v in cover:
            if a0 <= d < a1:
                return v, d + w <= a1
        return None, False

    def compiler_owned(d):
        return any(a0 <= d < a1 for a0, a1 in owned)

    # unnamed temporaries: an address MSVC takes (`lea ecx, [ebp-8]` for a constructor's this) that no declared variable
    # covers; a hole read between it and the next declared variable belongs to the temporary
    temps = sorted({d for (ia, d, w, mn, lea) in acc if lea and d < 0 and owner(d, 1)[0] is None})

    def in_temp(d):
        for t in temps:
            if t <= d:
                end = min([c[0] for c in cover if c[0] > t] + [x for x in temps if x > t] + [0])
                if d < end:
                    return True
        return False

    for (ia, d, w, mn, lea) in acc:
        if d < 0 and not lea and in_temp(d):
            continue
        if d >= 0 and d < 8:
            continue          # saved ebp / return address
        if d < 0 and d < lo_frame:
            continue          # below every declared local: saved registers / EH frame / temporaries
        if lea and d < 0:
            continue
        if compiler_owned(d):
            continue
        v, inside = owner(d, max(w, 1))
        if v is None:
            if d < 0 and any(d <= x < d + max(w, 1) or x <= d < x + 4 for x in written):
                continue          # a spill slot
            if d < 0:
                issues.append({"kind": "hole", "at": ia, "disp": d, "width": w, "insn": mn})
            elif d >= 8:
                # between declared parameters: a parameter slot our declaration has no name for (above the last one is
                # a hidden struct-return pointer or an undeclared argument: decl_lint's business)
                top = max(c[1] for c in cover)
                if 12 <= d < top:      # ebp+8 below the first declared parameter is the hidden struct-return pointer
                    issues.append({"kind": "param_hole", "at": ia, "disp": d, "width": w, "insn": mn})
        elif not inside and d + w > v["off"] + ((v["size"] + 3) & ~3) and not (lea and d > 0):
            # (a 4-byte access to a char/short's own slot is MSVC reusing it: `movzx ecx, [esp+8]; mov [esp+8], ecx; fild`)
            issues.append({"kind": "straddle", "at": ia, "disp": d, "width": w, "insn": mn, "var": v["name"],
                           "var_off": v["off"], "var_size": v["size"]})
    # address-taken locals with slack before the next declared variable (or the frame top)
    leas = {d for (ia, d, w, mn, lea) in acc if lea}
    for a0, a1, v in locs:
        if a0 not in leas:
            continue
        nxt = min([c[0] for c in cover if c[0] >= a1] + [o0 for o0, o1 in owned if o0 >= a1] +
                  [x for x in written if a1 <= x < 0] + [t for t in temps if t >= a1] + [0])
        slack = nxt - a1
        rounded = (v["size"] + 3) & ~3
        if nxt - a0 > rounded and slack >= 4:
            # 8-byte alignment of the next variable explains up to 4
            nv = next((c[2] for c in cover if c[0] == nxt), None)
            if nv is not None and nv["size"] >= 8 and slack <= 4 and nxt % 8 == 0:
                continue
            if slack <= 4 and a0 % 8 == 0 and v["size"] % 8 == 0:
                continue      # padding after an 8-byte-aligned variable
            issues.append({"kind": "slack", "var": v["name"], "type": v["type"], "var_off": a0, "var_size": v["size"],
                           "slack": slack, "next": nv["name"] if nv else "(frame top)"})
    return issues


def scan_stack_one(src):
    import compare
    rec = {"src": src}
    try:
        flags = list(compare.DEFAULT_FLAGS) + ["/Z7"]
        ff = compare.file_flags(os.path.join(ROOT, src))
        with tempfile.TemporaryDirectory() as td:
            # /Oy- last so it wins over a // cl-flags: /Oy
            obj = compile_z7(os.path.join(ROOT, src), flags, ff, td)
            coff = compare.Coff(obj)
            tdata = b"".join(d for (n, d, r) in coff.sections if n == ".debug$T")
            types = Types(tdata)
            fsz = fwd_sizes(types)
            procs = cv_procs(coff, types)
            # code of each function by symbol
            out = []
            for key, p in procs.items():
                code = None
                for (sname, val, secnum, typ, cls) in coff.symbols:
                    if sname == p["name"] or sname.endswith(p["name"]):
                        pass
                code = proc_code(coff, p)
                sym = coff.by_index.get(p.get("sym"), (None,))[0]
                if code and narrow_return(sym):
                    import capstone
                    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
                    md.detail = True
                    rec.setdefault("narrow_ret", []).append(
                        {"sym": sym, "ret": narrow_return(sym), "paths": ret_paths(list(md.disasm(code, 0)))})
                issues = analyse_proc(p, code, fsz)
                if issues:
                    out.append({"proc": p["name"], "issues": issues,
                                "vars": [(v["name"], v["off"], v["size"], v["type"]) for v in p["vars"]]})
            rec["status"] = "ok"
            rec["procs"] = out
    except Exception as e:  # noqa: BLE001
        rec["status"] = "error"
        rec["error"] = str(e)[:300]
    return rec


def compile_z7(src, flags, ff, out_dir):
    import compare
    obj = os.path.join(out_dir, os.path.splitext(os.path.basename(src))[0] + ".obj")
    env = dict(os.environ, INCLUDE=os.path.join(compare.MSVC, "Include") + ";" + os.path.join(ROOT, "include"))
    src_dir, src_name = os.path.split(os.path.abspath(src))
    ff = [f for f in ff if f not in ("/Oy",)]
    cmd = [compare.WIBO, os.path.join(compare.MSVC, "Bin/cl.exe")] + flags + ff + ["/Oy-", "/Fo" + obj, src_name]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=src_dir)
    if r.returncode != 0 or not os.path.exists(obj):
        raise RuntimeError("compile: " + (r.stdout + r.stderr)[-300:])
    return obj


def proc_code(coff, p):
    """The code bytes of a CodeView procedure: the relocation on its S_GPROC32 names the function's symbol."""
    sym = p.get("sym")
    s = coff.by_index.get(sym) if sym is not None else None
    if s is None:
        return None
    name, value, secnum, typ, cls = s
    if secnum <= 0:
        return None
    data = coff.sections[secnum - 1][1]
    return data[value:value + p["len"]]


def run_stack_local(items, out, jobs=1):
    done = set()
    if out and os.path.exists(out):
        done = {json.loads(l).get("src") for l in open(out) if l.strip()}
    todo = [s for s in items if s not in done]
    fo = open(out, "a") if out else None
    if jobs > 1:
        import multiprocessing as mp
        it = mp.Pool(jobs).imap_unordered(scan_stack_one, todo, chunksize=4)
    else:
        it = map(scan_stack_one, todo)
    for rec in it:
        if fo:
            fo.write(json.dumps(rec) + "\n")
            fo.flush()
        else:
            print(json.dumps(rec, indent=1))


def run_stack_jobq(items, out, name, per, limit):
    import jobq
    done = set()
    if os.path.exists(out):
        done = {json.loads(l).get("src") for l in open(out) if l.strip()}
    todo = [s for s in items if s not in done]
    if not todo:
        return
    commit = jobq.head_commit()
    base = jobq.collect_files([], True)
    jobs = []
    with tempfile.TemporaryDirectory() as td:
        for k in range(0, len(todo), per):
            ch = todo[k:k + per]
            files = dict(base)
            lst = ""
            for src in ch:
                dest = "jobsrc/" + src
                files[dest] = [jobq.store_file(os.path.join(ROOT, src)), 0o644]
                lst += dest + "\n"
            lp = os.path.join(td, "list%d" % k)
            open(lp, "w").write(lst)
            files["jobsrc/list.txt"] = [jobq.store_file(lp), 0o644]
            files["tools/narrow_scan.py"] = [jobq.store_file(os.path.abspath(__file__)), 0o755]
            cmd = ["python", "tools/narrow_scan.py", "stack", "--list", "jobsrc/list.txt", "--out", "jobsrc/out.jsonl",
                   "--jobs", "2"]
            jobs.append(jobq.make_job(name, cmd, "msvc", files, ["jobsrc/out.jsonl"], limit, 2, 3, 0, commit))
    ids = jobq.submit_jobs(jobs)
    print("submitted %d jobs: %s-%s" % (len(ids), ids[0], ids[-1]), file=sys.stderr)
    pending = set(ids)
    c = jobq.conn()
    with open(out, "a") as fo:
        while pending:
            rows = c.execute("SELECT id,state,host FROM jobs WHERE id IN (%s)" % ",".join(map(str, pending))).fetchall()
            for r in rows:
                if r["state"] not in jobq.TERMINAL:
                    continue
                pending.discard(r["id"])
                p = os.path.join(jobq.OUT, str(r["id"]), "jobsrc/out.jsonl")
                if os.path.exists(p):
                    for l in open(p):
                        try:
                            rec = json.loads(l)
                        except ValueError:
                            continue
                        if rec.get("src", "").startswith("jobsrc/"):
                            rec["src"] = rec["src"][len("jobsrc/"):]
                        fo.write(json.dumps(rec) + "\n")
                fo.flush()
                print("job %s %s on %s; %d left" % (r["id"], r["state"], r["host"], len(pending)), file=sys.stderr)
            if pending:
                time.sleep(20)


def cmd_stack(a):
    items = list(a.srcs)
    if a.list:
        items += [l.split()[-1] for l in open(a.list) if l.strip()]
    if a.all:
        items += [s for _, s in all_sources()]
    if a.jobq:
        run_stack_jobq(items, a.out, a.name, a.per, a.limit)
    else:
        run_stack_local(items, a.out, a.jobs)


def cmd_report(a):
    ranks = {"hole": 3, "straddle": 3, "param_beyond": 2, "param_hole": 2, "slack": 1}
    rows = []
    errs = 0
    for l in open(a.jsonl):
        r = json.loads(l)
        if r.get("status") != "ok":
            errs += 1
            continue
        for p in r.get("procs", []):
            spills = {i["disp"] for i in p["issues"] if i["kind"] == "hole" and
                      (i["insn"].startswith(("fst", "fist", "fnst")) and i["width"] in (4, 8))}
            p["issues"] = [i for i in p["issues"] if not (i["kind"] == "hole" and i["disp"] in spills) and
                           not (i["kind"] == "straddle" and i["insn"] == "lea" and i["var_off"] > 0) and
                           not (i["kind"] == "straddle" and
                           i["disp"] + i["width"] <= i["var_off"] + ((i["var_size"] + 3) & ~3)) and
                           not (i["kind"] == "param_hole" and i["disp"] == 8)]
            if not p["issues"]:
                continue
            kinds = sorted({i["kind"] for i in p["issues"]}, key=lambda k: -ranks[k])
            rows.append((max(ranks[k] for k in kinds), r["src"], p["proc"], kinds, p["issues"]))
    rows.sort(key=lambda r: (-r[0], r[1]))
    counts = {}
    for r in rows:
        for k in r[3]:
            counts[k] = counts.get(k, 0) + 1
    print("# stack: %d procs flagged, %s; %d sources failed to compile" % (len(rows), counts, errs))
    for r in rows:
        print("%d\t%s\t%s\t%s\t%s" % (r[0], r[1], r[2], ",".join(r[3]), json.dumps(r[4][:4])))


def cmd_retjoin(a):
    """Narrow returns whose original sets all of eax on its return paths (`mov eax, 1`, `xor eax, eax`) where MSVC,
    compiling our source, sets only al/ax (`mov al, 1`): the same compiler would have made the original's idiom from
    the original's (int) type, so the declaration is narrower than the original's."""
    orig = {}
    for l in open(a.ret_tsv):
        f = l.rstrip("\n").split("\t")
        if f[0] == "score":
            continue
        paths = dict((k, int(v)) for k, v in (x.split("=") for x in f[5].split(",") if "=" in x))
        orig[f[2]] = (f[1], f[3], f[4], paths, f[6])
    n = 0
    print("addr\tsrc\tret\treach\toriginal_paths\tour_msvc_paths\tcallers")
    for l in open(a.jsonl):
        r = json.loads(l)
        o = orig.get(r.get("src"))
        if not o or not r.get("narrow_ret"):
            continue
        op = o[3]
        o_full = op.get("full_const", 0) + op.get("full", 0)
        for nr in r["narrow_ret"]:
            up = nr["paths"]
            u_full = up.get("full_const", 0) + up.get("full", 0)
            if o_full and not op.get("narrow") and up.get("narrow") and not u_full:
                n += 1
                print("%s\t%s\t%s\t%s\t%s\t%s\t%s" % (o[0], r["src"], nr["ret"], o[2],
                      ",".join("%s=%d" % kv for kv in sorted(op.items())),
                      ",".join("%s=%d" % kv for kv in sorted(up.items())), o[4]))
    print("# %d candidates" % n, file=sys.stderr)


def main(argv):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)
    r = sub.add_parser("ret")
    r.add_argument("srcs", nargs="*")
    r.add_argument("--out")
    r.add_argument("--bindings", default=os.path.join(ROOT, "build/native/bindings.json"),
                   help="a binding map (wine_link.py) for our definitions' mangled names")
    s = sub.add_parser("src")
    s.add_argument("srcs", nargs="*")
    s.add_argument("--out")
    k = sub.add_parser("stack")
    k.add_argument("srcs", nargs="*")
    k.add_argument("--list")
    k.add_argument("--all", action="store_true")
    k.add_argument("--out")
    k.add_argument("--jobs", type=int, default=1)
    k.add_argument("--jobq", action="store_true")
    k.add_argument("--name", default="narrow_scan")
    k.add_argument("--per", type=int, default=400)
    k.add_argument("--limit", type=int, default=3600)
    rp = sub.add_parser("report")
    rp.add_argument("jsonl")
    r6 = sub.add_parser("ret64")
    r6.add_argument("srcs", nargs="*")
    r6.add_argument("--out")
    r6.add_argument("--bindings", default=os.path.join(ROOT, "build/native/bindings.json"))
    rj = sub.add_parser("retjoin")
    rj.add_argument("ret_tsv")
    rj.add_argument("jsonl")
    a = p.parse_args(argv)
    {"ret64": cmd_ret64, "retjoin": cmd_retjoin, "ret": cmd_ret, "src": cmd_src, "stack": cmd_stack, "report": cmd_report}[a.cmd](a)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
