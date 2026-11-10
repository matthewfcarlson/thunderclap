#!/usr/bin/env python3
"""The unbound names of the 64-bit native links, by class (docs/native-build.md "Unbound names"), and the binding
the native link makes from the address a name carries.

  build/venv/bin/python tools/native_unbound.py classify --dir build/native-mac [--fmt macho] \
      [--bindings B.json] [--wine-unbound U.txt] [--json OUT.json] [--examples 6]
  build/venv/bin/python tools/native_unbound.py classify --dir build/native-linux-x64 --fmt elf ...
  # the snapshot the objects come from: HULK_CLANG_PROBE_DIR=<dir with snap/> (its report.json: the tree's
  # definitions by address)

Why the Wine build binds what the native links do not. Both links start from about the same undefined names (the
Wine build's strict link: 47,639 before binding). The tree puts every TU's own declarations in a TU namespace
(`fn_f<7 hex>`, docs/source-tree.md) and wraps sources in `fn_<addr>`, so a call from one TU to a function defined
in another is, by name, a call to a symbol nobody defines (`fn_00031310::FUN_0002b380` for the definition
`fn_ff0a839e::FUN_0002b380`), unless the name comes from include/gen/ or include/decls/. tools/wine_link.py binds
those names by the address each relocation was proven to reach (the binding map, `/alternatename`: 49,137 aliases),
which the native link does not use (docs/native-mac.md section 9).

What the native link can use is the address the *name* carries (tools/addr_names.py: `FUN_<addr>`, the suffix
convention `SetArc_000480a0`, `DAT_<addr>`; `thunk_FUN_x` names the target x of a `jmp` thunk elsewhere: thunk_address()).
`plan_link()` binds such a name, per object,
to the tree's own definition at that address (the tree build's report, as native_mac.TreeDefs) when

  * the reference's IR signature in that object equals the definition's (`ir_signatures()`: the MS front end's
    lowering, saved beside each object by the native compiles as `<obj>.sig.json`; `ptr` = `i64`; a caller that
    ignores the result is accepted; data: no larger than the item), and
  * the Wine build's binding map of the same tree binds the name to that same address (`--bindings`: sources'
    `FUN_` names are unverified claims, and some are wrong; the map only vetoes, it never supplies a binding).

The link applies the plan by renaming the references in copies of the objects (native_bind.apply's `extra`).
`classify` reports every unbound name by class, how the Wine build binds it, and (`--whatif`) what the binding map
would bind of the names without an address. Without sidecars it falls back to comparing the MS mangled types
(`address_bindings()`, `abi_check()`). The metric is native_mac.py's "unbound" (undefined names less the native
CRT table's rows).

  build/venv/bin/python tools/native_mac.py link --ld --bindings B.json    # (native_elf.py link the same)
"""
import argparse
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import addr_names  # noqa: E402
import clang_probe as cp  # noqa: E402

ROOT = cp.ROOT
TEXT_LO, TEXT_HI = 0x00011000, 0x00380000   # the XBE's code (wine_host's library spans are inside: not tree code)
FN_NS = re.compile(r"\bfn_[0-9a-f]{8}::")
ADDR_LEAF = re.compile(r"^(?:FUN|thunk_FUN|LAB)_(00[0-9a-f]{6})$")
DATA_LEAF = re.compile(r"^(?:DAT|PTR|hulk_at)_(00[0-9a-f]{6})$")


# ------------------------------------------------------------------------------------------------ demangled shapes
def _close(s, i):
    """Index of the '(' matching the ')' at s[i] (scanning back over ()<>)."""
    depth = 0
    while i >= 0:
        c = s[i]
        if c in ")>":
            depth += 1
        elif c in "(<":
            depth -= 1
            if depth == 0:
                return i
        i -= 1
    return -1


def _split_top(s):
    out, depth, cur = [], 0, []
    for c in s:
        if c in "(<[":
            depth += 1
        elif c in ")>]":
            depth -= 1
        if c == "," and depth == 0:
            out.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
    if "".join(cur).strip():
        out.append("".join(cur).strip())
    return out


def _last_token(s):
    """Split `ret qualified::name` at the last top-level space."""
    depth = 0
    for i in range(len(s) - 1, -1, -1):
        c = s[i]
        if c in ">)":
            depth += 1
        elif c in "<(":
            depth -= 1
        elif c == " " and depth == 0:
            return s[:i], s[i + 1:]
    return "", s


def norm(d):
    return re.sub(r"\s+", " ", re.sub(r"\b__(?:cdecl|thiscall|stdcall|fastcall|ptr64|unaligned)\b", "", d)) \
        .replace(" ,", ",").replace(" )", ")").replace("( ", "(").replace(" *", "*").replace(" &", "&").strip()


def shape(dem):
    """A demangled MS name -> {'kind': 'func'|'data', 'member', 'ret', 'params', 'name', 'type'} (None if unparsed)."""
    d = norm(dem)
    if not d.endswith(")") and not re.search(r"\) const$|\) volatile$", d):
        # data: `type name`
        t, n = _last_token(d)
        return {"kind": "data", "type": t, "name": n}
    d2 = re.sub(r"\)(?: const| volatile)+$", ")", d)
    i = _close(d2, len(d2) - 1)
    if i <= 0:
        return None
    params = d2[i + 1:-1]
    pre = d2[:i]
    if pre.endswith(")"):           # a function-pointer variable `int (*name)(int)`
        return {"kind": "data", "type": "fnptr", "name": pre}
    m = re.match(r"^(?:(public|private|protected): )?(?:(static|virtual) )?(.*)$", pre)
    access, stor, rest = m.groups()
    ret, name = _last_token(rest)
    ps = [] if params in ("", "void") else _split_top(params)
    return {"kind": "func", "member": bool(access) and stor != "static", "virtual": stor == "virtual",
            "ret": ret.strip() or "void", "params": ps, "name": name}


SCALAR_I = {"bool", "char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int", "long",
            "unsigned long", "wchar_t"}


def regclass(t):
    t = re.sub(r"\b(?:const|volatile)\b", "", t).strip()
    t = re.sub(r"\s+", " ", t)
    if t == "...":
        return "VA"
    if t.endswith("*") or t.endswith("&") or "(" in t or "::*" in t:
        return "P"
    if t == "float":
        return "F"
    if t in ("double", "long double"):
        return "D"
    if t in ("__int64", "unsigned __int64"):
        return "Q"
    if t == "void":
        return "V"
    if t in SCALAR_I or t.startswith("enum "):
        return "I"
    return "A"      # a class, struct or union by value (its size is not in the name)


def abi_check(ref, dfn):
    """(verdict, detail) for a reference's and a definition's shape(): 'same' (the same types, namespaces aside),
    'compatible' (every argument and the result in the same register class), or a mismatch kind."""
    if ref is None or dfn is None:
        return "unparsed", ""
    if ref["kind"] != dfn["kind"]:
        return "code/data", "%s name for a %s definition" % (ref["kind"], dfn["kind"])
    if ref["kind"] == "data":
        a, b = regclass(ref["type"]), regclass(dfn["type"])
        if FN_NS.sub("", ref["type"]) == FN_NS.sub("", dfn["type"]):
            return "same", ""
        return ("compatible", "") if a == b and a != "A" else ("data type", "%s / %s" % (ref["type"], dfn["type"]))

    def args(s):
        return (["P"] if s["member"] else []) + [regclass(p) for p in s["params"]]
    ra, da = args(ref), args(dfn)
    rr, dr = regclass(ref["ret"]), regclass(dfn["ret"])
    strip = lambda s: [FN_NS.sub("", p) for p in s["params"]] + [FN_NS.sub("", s["ret"]), s["member"]]  # noqa: E731
    if "VA" in ra or "VA" in da:
        if ra != da:
            return "varargs", "%s / %s" % (ra, da)
    if "A" in ra + da + [rr, dr]:
        if strip(ref) == strip(dfn):
            return "same", ""
        return "aggregate by value", "%s -> %s / %s -> %s" % (ra, rr, da, dr)
    if len(ra) != len(da):
        return "argument count", "%d / %d" % (len(ra), len(da))
    for x, y in zip(ra, da):
        if x != y:
            k = "".join(sorted((x, y)))
            return {"IP": "pointer / int argument", "FI": "float / int argument", "DF": "float / double argument",
                    "DI": "double / int argument", "IQ": "int / int64 argument", "PQ": "pointer / int64 argument"} \
                .get(k, "argument %s / %s" % (x, y)), "%s / %s" % (ra, da)
    if rr != dr:
        if rr == "V":
            return "compatible", "the caller ignores the result"
        k = "".join(sorted((rr, dr)))
        return {"IV": "result read, none returned", "PV": "result read, none returned",
                "FV": "result read, none returned", "DV": "result read, none returned",
                "IP": "pointer / int result", "DF": "float / double result", "FI": "float / int result",
                "DI": "double / int result"}.get(k, "result %s / %s" % (rr, dr)), "%s / %s" % (rr, dr)
    if strip(ref) == strip(dfn):
        return "same", ""
    return "compatible", ""


# ------------------------------------------------------------------------------------------------ addresses in names
def leaf(sym):
    """(leaf identifier, special) of a symbol: `?Name@...` -> Name; `??0Name@` (a constructor) -> (Name, 'ctor')."""
    if sym.startswith("??0") or sym.startswith("??1"):
        m = re.match(r"\?\?[01]([A-Za-z_]\w*)@", sym)
        return (m.group(1) if m else None), ("ctor" if sym[2] == "0" else "dtor")
    if sym.startswith("??"):
        return None, "special"
    if sym.startswith("?"):
        m = re.match(r"\?([A-Za-z_]\w*)@", sym)
        return (m.group(1) if m else None), None
    m = re.fullmatch(r"[_@]?([A-Za-z_]\w*?)(?:@\d+)?", sym)
    return (m.group(1) if m else sym), None


def name_address(sym):
    """(address, how) the name carries, or (None, None): FUN_/LAB_ (`fun`), the suffix convention (`suffix`),
    DAT_/PTR_/hulk_at_ (`data`). `thunk_FUN_x` carries none (the thunk's own address is not in its name).

    A constructor or destructor of a class named by an address (`??0FUN_002605e0@...`, `??1FUN_00240060@...`:
    `class named fun`) carries the address of that special member: sources name a base class by its constructor's
    address and a temporary's class by its destructor's. plan_link binds it like a `FUN_` name, so the binding map's
    veto applies (a destructor of a class named by its constructor is bound by the Wine link elsewhere) and the IR
    signatures must agree; address_bindings() (no sidecars, no map) leaves it unbound."""
    lf, special = leaf(sym)
    if not lf:
        return None, None
    m = ADDR_LEAF.match(lf)
    if m:
        if lf.startswith("thunk_"):
            return None, None       # Ghidra's thunk_FUN_x is the thunk (at its own address) to x, not x
        return int(m.group(1), 16), ("fun" if not special else "class named fun")
    m = DATA_LEAF.match(lf)
    if m:
        return int(m.group(1), 16), "data"
    a = addr_names.suffix_address(lf)
    if a is not None and not special:
        return a, "suffix"
    return None, None


def thunk_address(sym):
    """x of Ghidra's `thunk_FUN_x` (the function a `jmp` thunk elsewhere goes to), or None. plan_link binds such a
    name to x's definition when the Wine binding map has its relocations reach x itself or a `jmp` thunk to x.
    (sh2) `thunk_FUN_x_a` / `thunk_FUN_x_b` name two different `jmp` thunks to x in one source (matches/0x000fa300.cpp,
    0x00265c40.cpp: verify_relocs holds each to its own thunk); both carry x."""
    lf, special = leaf(sym)
    m = ADDR_LEAF.match(re.sub(r"_[a-z]$", "", lf or ""))
    return int(m.group(1), 16) if m and lf.startswith("thunk_") and not special else None


_JMP = {}


def jmp_target(a, hops=3):
    """The final target of a chain of `jmp rel32` thunks at a in the XBE (None if a is not one); jmp_target.xbe
    can be set to an object with `offset(va)` and `data` (tests)."""
    if a in _JMP:
        return _JMP[a]
    x = getattr(jmp_target, "xbe", None)
    if x is None:
        import struct  # noqa: F401
        import compare
        from xbe import Xbe
        x = jmp_target.xbe = Xbe(compare.XBE_PATH)
    t, b = None, a
    for _ in range(hops):
        o = x.offset(b)
        if o is None or x.data[o] != 0xE9:
            break
        b = t = (b + 5 + int.from_bytes(x.data[o + 1:o + 5], "little", signed=True)) & 0xFFFFFFFF
    _JMP[a] = t
    return t


class Defs:
    """The tree's definitions by address, as 64-bit symbols (native_mac.TreeDefs's rule: the tree build's report,
    matched by demangled form without conventions and `__ptr64`), with their shapes."""

    def __init__(self, defined64, dem64=None):
        checks = json.load(open(os.path.join(cp.SNAP, "report.json")))["checks"]
        self.by_addr = {int(c["addr"], 16): c for c in checks if c.get("symbol") and c["status"] in ("match", "compiled")}
        self.all_addr = {int(c["addr"], 16): c for c in checks}
        dem32 = cp.undname(sorted({c["symbol"] for c in self.by_addr.values() if c["symbol"].startswith("?")}))
        self.dem64 = dem64 or cp.undname(sorted(s for s in defined64 if s.startswith("?")))
        by_key = collections.defaultdict(set)
        for s in defined64:
            by_key[norm(self.dem64.get(s, s)) if s.startswith("?") else s].add(s)
        self.sym = {}
        self.why = {}
        by_name = None
        for a, c in self.by_addr.items():
            s = c["symbol"]
            k = norm(dem32.get(s, s)) if s.startswith("?") else c_plain32(s)
            t = by_key.get(k, set())
            if not t and s.startswith("?"):
                # the 64-bit form differs in its types (a `hulk_freg` result is double, `size_t` / `hulk_intptr`
                # parameters are 64-bit): the one 64-bit function of that qualified name
                if by_name is None:
                    by_name = collections.defaultdict(set)
                    for s2 in defined64:
                        if s2.startswith("?"):
                            sh = shape(self.dem64.get(s2, s2))
                            if sh and sh["kind"] == "func":
                                by_name[sh["name"]].add(s2)
                sh = shape(dem32.get(s, s))
                if sh and sh["kind"] == "func":
                    t = by_name.get(sh["name"], set())
            if len(t) == 1:
                self.sym[a] = next(iter(t))
            else:
                self.why[a] = "%d 64-bit symbols of that form" % len(t)
        self.defined = defined64


def c_plain32(s):
    m = re.match(r"^[_@]?([A-Za-z_$][\w$]*?)(@\d+)?$", s)
    return m.group(1) if m else s


def address_bindings(undef, defs, dem, data_defined, rtti_labels=()):
    """{unbound name: (class, target or None, detail)} for every name that carries an address. `target` is set where
    the link may bind the name to it (the ABI check passed)."""
    out = {}
    need = sorted({defs.sym[a] for a in defs.sym} - set(defs.dem64))
    if need:
        defs.dem64.update(cp.undname([s for s in need if s.startswith("?")]))
    for s in undef:
        a, how = name_address(s)
        if a is None:
            continue
        ref = shape(dem.get(s, s)) if s.startswith("?") else None
        if how == "data":
            t = "DAT_%08x" % a
            if t in data_defined:
                if ref is not None and ref["kind"] == "func":
                    out[s] = ("address in name: data name declared as a function", None, "")
                else:
                    out[s] = ("address in name: data item (bound)", t, "")
            elif t in rtti_labels:
                out[s] = ("address in name: vftable / RTTI record label (bound)", t, "")
            else:
                out[s] = ("address in name: data address without an item (interior / outside the inventory)", None, "")
            continue
        if how.startswith("class named"):
            out[s] = ("address in name: special member of a class named by address", None, "")
            continue
        if not (TEXT_LO <= a < TEXT_HI):
            out[s] = ("address in name: outside .text", None, "")
            continue
        t = defs.sym.get(a)
        if t is None:
            if a in defs.by_addr:
                out[s] = ("address in name: definition without a unique 64-bit symbol", None, defs.why.get(a, ""))
            elif a in defs.all_addr:
                out[s] = ("address in name: definition not verified in this tree", None, "")
            else:
                out[s] = ("address in name: no tree definition (unverified, library or not a function start)", None, "")
            continue
        if t == s:
            continue
        if not s.startswith("?") and not t.startswith("?"):
            v, det = "same", "C names"
        else:
            dref = ref if ref is not None else {"kind": "func", "member": False, "ret": "?", "params": ["?"], "name": s}
            v, det = abi_check(dref, shape(defs.dem64.get(t, t)) if t.startswith("?") else None)
            if not s.startswith("?"):
                v, det = "C name (types unknown)", ""
        if v in ("same", "compatible"):
            out[s] = ("address in name: bound (%s)" % v, t, det)
        else:
            out[s] = ("address in name: ABI mismatch: %s" % v, None, det, t)
    return out


# ------------------------------------------------------------------------------------------------ IR signatures
# What a call passes, at the machine level, is in the IR's function types after the front end's ABI lowering (the MS
# lowering for the target's Windows triple: `this`, sret / byval, coerced aggregates, a constructor's returned `this`).
# compile_one() saves, beside each object, the IR signature of every function the TU defines or declares and the size
# of every global (`<obj>.sig.json`); a name binds to a definition when both signatures are the same.
FN_HEAD = re.compile(r'^(define|declare) ([^@\n]*?)(@"[^"]+"|@[\w.$?@-]+)\((.*)\)([^(\n]*?)(?:\{)?$', re.M)
GLOBAL_HEAD = re.compile(r'^(@"[^"]+"|@[\w.$?@-]+) = ((?:[a-z_]+ )*?)(global|constant) (.*)$', re.M)
TYPE_DEF = re.compile(r'^(%"[^"]+"|%[\w.$-]+) = type (.*)$', re.M)
DROP = {"dso_local", "dso_preemptable", "local_unnamed_addr", "unnamed_addr", "noundef", "nonnull", "noalias",
        "nocapture", "readonly", "writeonly", "readnone", "returned", "writable", "dead_on_unwind", "immarg", "noinline",
        "internal", "private", "external", "linkonce_odr", "linkonce", "weak_odr", "weak", "available_externally",
        "extern_weak", "common", "hidden", "protected", "default", "dllimport", "dllexport", "nofree", "nosync",
        "noreturn", "nounwind", "thread_local", "externally_initialized", "zeroinitializer"}
ATTR_ARG = re.compile(r"\b(?:align \d+|dereferenceable(?:_or_null)?\(\d+\)|range\([^)]*\)|nofpclass\([^)]*\)|"
                      r"captures\([^)]*\)|memory\([^)]*\)|initializes\([^)]*\))|(?:^|\s)#\d+|\s%(?:[\w.$-]+|\"[^\"]*\")$")


def _split_ir(s):
    out, depth, cur, q = [], 0, [], False
    for c in s:
        if c == '"':
            q = not q
        elif not q and c in "({[<":
            depth += 1
        elif not q and c in ")}]>":
            depth -= 1
        if c == "," and depth == 0 and not q:
            out.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
    if "".join(cur).strip():
        out.append("".join(cur).strip())
    return out


class Sizer:
    """Sizes and alignments of IR types (the 64-bit targets: pointers 8, natural alignment)."""

    def __init__(self, ir):
        self.defs = {m.group(1): m.group(2).strip() for m in TYPE_DEF.finditer(ir)}
        self.memo = {}

    def size(self, t):
        t = t.strip()
        if t in self.memo:
            return self.memo[t]
        self.memo[t] = (0, 1)
        r = self._size(t)
        self.memo[t] = r
        return r

    def _size(self, t):
        m = re.fullmatch(r"i(\d+)", t)
        if m:
            n = max(1, (int(m.group(1)) + 7) // 8)
            n = 1 << (n - 1).bit_length()
            return n, min(n, 16)
        if t in ("ptr", "double", "i64"):
            return 8, 8
        if t == "float":
            return 4, 4
        if t == "half" or t == "bfloat":
            return 2, 2
        if t in ("fp128", "x86_fp80"):
            return 16, 16
        m = re.fullmatch(r"\[(\d+) x (.*)\]", t)
        if m:
            s, a = self.size(m.group(2))
            return int(m.group(1)) * s, a
        m = re.fullmatch(r"<(\d+) x (.*)>", t)
        if m:
            s, _a = self.size(m.group(2))
            n = int(m.group(1)) * s
            return n, min(1 << max(0, (n - 1).bit_length()), 16)
        packed = t.startswith("<{")
        if t.startswith("{") or packed:
            inner = t[2:-2] if packed else t[1:-1]
            off, al = 0, 1
            for f in _split_ir(inner):
                s, a = self.size(f)
                if not packed:
                    off = (off + a - 1) // a * a
                    al = max(al, a)
                off += s
            if not packed:
                off = (off + al - 1) // al * al
            return off, al
        if t.startswith("%"):
            d = self.defs.get(t)
            if d is None or d == "opaque":
                return 0, 1
            return self.size(d)
        return 0, 1


def _norm_param(p, sz):
    """A lowered parameter or result: its type and the attributes that change how it is passed."""
    keep = []
    m = re.search(r"\b(sret|byval|byref|inalloca|preallocated)\(([^)]*(?:\([^)]*\))?[^)]*)\)", p)
    if m:
        s, a = sz.size(m.group(2))
        keep.append("%s(%d,%d)" % (m.group(1), s, a))
        p = p.replace(m.group(0), "")
    p = ATTR_ARG.sub("", p)
    toks = [t for t in p.split() if t not in DROP]
    for t in ("inreg", "signext", "zeroext", "swiftself", "nest"):
        if t in toks:
            toks.remove(t)
            keep.append(t)
    ty = " ".join(toks)
    if ty.startswith("%") or ty.startswith("{") or ty.startswith("<{"):
        s, a = sz.size(ty)
        ty = "agg(%d,%d)" % (s, a)
    return " ".join([ty] + keep)


CC_WORDS = {"ccc", "fastcc", "coldcc", "win64cc", "x86_64_sysvcc", "aarch64_vector_pcs", "preserve_mostcc", "swiftcc"}


def ir_signatures(ir):
    """{symbol (MS spelling): signature} of a module's functions and globals: functions 'cc ret(params)', globals
    'g size align'."""
    sz = Sizer(ir)
    out = {}
    for m in FN_HEAD.finditer(ir):
        name = m.group(3)[1:].strip('"')
        pre = ATTR_ARG.sub("", m.group(2))
        toks = [t for t in pre.split() if t not in DROP]
        cc = [t for t in toks if t in CC_WORDS or t.startswith("cc")]
        ret_toks = [t for t in toks if t not in cc and t not in ("inreg", "signext", "zeroext")]
        ext = [t for t in toks if t in ("signext", "zeroext", "inreg")]
        ret = _norm_param(" ".join(ret_toks), sz) + ("".join(" " + e for e in ext))
        params = [_norm_param(p, sz) for p in _split_ir(m.group(4))]
        out[name] = "%s%s(%s)" % ((" ".join(cc) + " ") if cc else "", ret, ", ".join(params))
    for m in GLOBAL_HEAD.finditer(ir):
        name = m.group(1)[1:].strip('"')
        rest = m.group(4)
        # the value type: up to the initializer (a top-level space after a balanced type) or ", align"
        depth, i, q = 0, 0, False
        while i < len(rest):
            c = rest[i]
            if c == '"':
                q = not q
            elif not q and c in "({[<":
                depth += 1
            elif not q and c in ")}]>":
                depth -= 1
            elif not q and depth == 0 and c in " ,":
                break
            i += 1
        s, a = sz.size(rest[:i])
        am = re.search(r", align (\d+)", rest)
        out[name] = "g %d %d" % (s, int(am.group(1)) if am else a)
    return out


def save_signatures(ir, obj, unescape=None):
    """Called by the native compiles after the retarget: `<obj>.sig.json` beside the object `obj` (names in MS
    spelling; `unescape` reads ELF's `#` back as `@`)."""
    sig = ir_signatures(ir)
    if unescape:
        sig = {unescape(k): v for k, v in sig.items()}
    p = sig_path(obj)
    with open(p + ".tmp", "w") as f:
        json.dump(sig, f, separators=(",", ":"))
    os.replace(p + ".tmp", p)


def has_signatures(obj):
    return os.path.exists(sig_path(obj))


def sig_path(obj):
    return (obj[:-2] if obj.endswith(".o") else obj) + ".sig.json"


def load_signatures(objs):
    """{obj: {symbol: signature}} (objects without a sidecar: absent)."""
    out = {}
    for o in objs:
        p = sig_path(o)
        if os.path.exists(p):
            out[o] = json.load(open(p))
    return out


def _ty(p):
    """The type of a normalized parameter or result (`i1 zeroext` -> i1, `[2 x i64]`, `win64cc void` -> void)."""
    toks = [t for t in p.split() if t not in CC_WORDS]
    p = " ".join(toks)
    if p[:1] in "[{<":
        depth = 0
        for i, c in enumerate(p):
            depth += c in "[{<"
            depth -= c in "]}>"
            if depth == 0:
                return p[:i + 1]
    return toks[0] if toks else ""


def sig_diff(a, b):
    """The kind of difference between two signatures (for the report)."""
    if a.startswith("g ") or b.startswith("g "):
        return "data" if a.startswith("g ") and b.startswith("g ") else "code / data"
    pa = re.match(r"(.*?)\((.*)\)$", a)
    pb = re.match(r"(.*?)\((.*)\)$", b)
    if not pa or not pb:
        return "unparsed"
    ra, rb = _ty(pa.group(1)), _ty(pb.group(1))
    la = _split_ir(pa.group(2))
    lb = _split_ir(pb.group(2))
    if ("..." in la) != ("..." in lb):
        return "variadic / fixed"
    if len(la) != len(lb):
        return "argument count"
    for x, y in zip(la, lb):
        if x != y:
            k = tuple(sorted((_ty(x), _ty(y))))
            names = {("i32", "ptr"): "pointer / int argument", ("float", "i32"): "float / int argument",
                     ("double", "float"): "float / double argument", ("i32", "i64"): "int / int64 argument",
                     ("i64", "ptr"): "pointer / int64 argument", ("double", "i32"): "double / int argument"}
            if _ty(x) == _ty(y):
                return "argument attributes (%s / %s)" % (x, y)
            return names.get(k, "argument %s / %s" % k)
    if ra != rb:
        k = tuple(sorted((ra, rb)))
        names = {("i32", "ptr"): "pointer / int result", ("double", "float"): "float / double result",
                 ("i32", "void"): "result read, none returned", ("ptr", "void"): "result read, none returned",
                 ("float", "void"): "result read, none returned", ("double", "void"): "result read, none returned",
                 ("float", "i32"): "float / int result", ("double", "i32"): "double / int result"}
        if rb == "void" or ra == "void":
            if ra == "void":
                return "compatible"     # the caller ignores the result
        return names.get(k, "result %s / %s" % k)
    if pa.group(1) != pb.group(1):
        return "result attributes / convention (%s / %s)" % (pa.group(1), pb.group(1))
    return "other"


def abi_key(sig):
    """A signature as the 64-bit targets pass it: `ptr` and `i64` travel alike (one 64-bit integer register or stack
    slot on AArch64 and x86-64, Darwin, System V and Win64), so a pointer the other side spells `hulk_intptr` /
    `hulk_uintptr` (or `__int64`) is the same argument; every other type, width and attribute must agree."""
    return re.sub(r"\bptr\b", "i64", sig)


def plan_link(objs, syms, defs, data_defined, label_defined=(), sigs=None, verify=None):
    """The address bindings the link makes: ({obj: {referenced name: definition}}, {name: (class, detail)}).

    A name binds in an object when it carries an address (name_address()), the tree defines that address (`defs`:
    Defs; data: a data TU's `DAT_<addr>` or a vftable / RTTI record label), and the reference's IR signature in that
    object equals the definition's (functions; for data: the referenced global is no larger than the item and its
    alignment no stricter than the item's). `syms`: {obj: (defined, undefined)}.

    `verify`: the Wine build's binding map of the same tree (wine_index()). A name the sources spell with an address
    is a claim no checker verifies for `FUN_` names (verify_relocs checks the suffix convention only), and some are
    wrong (sources propagated from a function of the same code shape keep its callees' names: `FUN_00019420` for the
    destructor 0x00067a20). The binding map has, per name, the address its relocations were proven to reach; a name
    binds only where that address is the one the name says (for `thunk_FUN_x`: x, or a `jmp` thunk to x; calling
    the thunk is calling x). Without a map, nothing binds."""
    if sigs is None:
        sigs = load_signatures(objs)
    def addr_of(s):
        a, how = name_address(s)
        if a is None:
            t = thunk_address(s)
            if t is not None:
                return t, "thunk"
        return a, how
    cand = sorted({s for _o, (_d, u) in syms.items() for s in u if addr_of(s)[0] is not None})
    cdem = cp.undname([s for s in cand if s.startswith("?")]) if verify is not None else {}
    def_sig = {}
    for o, (d, _u) in syms.items():
        so = sigs.get(o)
        if so:
            for s in d:
                if s in so:
                    def_sig.setdefault(s, so[s])
    renames = collections.defaultdict(dict)
    why = {}
    per_name = collections.defaultdict(lambda: [0, 0])     # name -> [objects bound, objects not bound]
    for o, (_d, u) in syms.items():
        so = sigs.get(o)
        for s in u:
            a, how = addr_of(s)
            if a is None:
                continue
            target, cls, det = None, None, ""
            if how == "data":
                t = "DAT_%08x" % a
                if t in data_defined or t in label_defined:
                    target = t
                else:
                    cls = "data address without an item (interior / outside the inventory)"
            elif not (TEXT_LO <= a < TEXT_HI):
                cls = "outside .text"
            else:
                target = defs.sym.get(a)
                if target is None and how in ("fun", "class named fun", "suffix") and a not in defs.all_addr:
                    # (sh2) `FUN_x` where x is a `jmp` thunk with no definition of its own (0x00263ea0 -> the allocator
                    # 0x0008d690, 0x0008d340 -> free): calling the thunk is calling its target
                    j = jmp_target(a)
                    if j is not None and defs.sym.get(j) is not None:
                        target, det = defs.sym[j], "jmp thunk %#x -> %#x" % (a, j)
                if target is None:
                    cls = ("definition without a unique 64-bit symbol" if a in defs.by_addr else
                           "definition not verified in this tree" if a in defs.all_addr else
                           "no tree definition (unverified, library or not a function start)")
            if target is not None and target == s:
                continue
            if target is not None:
                w = verify.lookup(s, cdem) if verify is not None else None
                if verify is None:
                    target, cls = None, "not verified (no Wine binding map given)"
                elif w is None:
                    target, cls = None, "not verified: the Wine binding map has no binding of the name"
                elif w[1] is None:
                    target, cls = None, "not verified: ambiguous in the Wine binding map"
                elif int(w[1], 16) != a and not (how == "thunk" and jmp_target(int(w[1], 16)) == a):
                    # (a `thunk_FUN_x` name: its relocations reach x or a `jmp` thunk to x)
                    target, cls, det = None, "the name's address is not where the Wine build binds it", \
                        "%#x / %s" % (a, w[1])
            if target is not None:
                rs = so.get(s) if so else None
                ds = def_sig.get(target)
                if target in label_defined and rs is not None and rs.startswith("g "):
                    ds = rs     # link-table records: no IR (their layout is native_mac's)
                if rs is None or ds is None:
                    cls, det = "no IR signature", ("reference" if rs is None else "definition")
                elif rs == ds:
                    cls = "bound (same IR signature)"
                elif not rs.startswith("g ") and abi_key(rs) == abi_key(ds):
                    cls = "bound (same IR signature but pointer / 64-bit integer)"
                elif rs.startswith("g ") and ds.startswith("g "):
                    r_s, r_a = map(int, rs.split()[1:])
                    d_s, d_a = map(int, ds.split()[1:])
                    if r_s <= d_s and (r_a <= d_a or (int(target[4:], 16) % r_a == 0 if target.startswith("DAT_") else False)):
                        cls = "bound (data within the item)"
                    else:
                        cls, det = "ABI mismatch: data larger or more aligned than the item", "%s / %s" % (rs, ds)
                else:
                    if sig_diff(abi_key(rs), abi_key(ds)) == "compatible":
                        cls, det = "bound (the caller ignores the result)", ""
                    else:
                        cls, det = "ABI mismatch: " + sig_diff(rs, ds), "%s / %s" % (rs, ds)
                if cls.startswith("bound"):
                    renames[o][s] = target
                    per_name[s][0] += 1
                    why.setdefault(s, (cls, det))
                    continue
            per_name[s][1] += 1
            why[s] = (cls, det)
    for s, (b, n) in per_name.items():
        if b and n:
            why[s] = ("bound in some objects only", why[s][1])
    return dict(renames), why, {s for s, (b, n) in per_name.items() if b and not n}


def whatif_map(syms, defs, verify, sigs, names, data_defined):
    """For the report only (not a link step): how many names without an address the Wine build's binding map would
    bind to a tree definition with the same IR signature (the rejected name table, docs/native-mac.md section 9,
    with the IR check). {class: names}."""
    names = set(names)
    dem = cp.undname(sorted(s for s in names if s.startswith("?")))
    def_sig = {}
    for o, (d, _u) in syms.items():
        so = sigs.get(o) or {}
        for s in d:
            if s in so:
                def_sig.setdefault(s, so[s])
    res = {}
    for o, (_d, u) in syms.items():
        so = sigs.get(o) or {}
        for s in u & names:
            w = verify.lookup(s, dem)
            if w is None:
                c = "no binding in the map"
            elif w[1] is None:
                c = "ambiguous in the map"
            else:
                a = int(w[1], 16)
                t = defs.sym.get(a) or ("DAT_%08x" % a if "DAT_%08x" % a in data_defined else None)
                if t is None:
                    c = "bound to an address without a 64-bit tree definition"
                elif so.get(s) is None or def_sig.get(t) is None:
                    c = "no IR signature"
                elif abi_key(so[s]) == abi_key(def_sig[t]) or sig_diff(abi_key(so[s]), abi_key(def_sig[t])) == "compatible":
                    c = "same IR signature"
                elif so[s].startswith("g ") and def_sig[t].startswith("g "):
                    c = "data (sizes differ)"
                else:
                    c = "IR signatures differ: " + sig_diff(so[s], def_sig[t])
            prev = res.get(s)
            res[s] = c if prev in (None, c) else "differs between objects"
    out = collections.Counter(res.values())
    return dict(out.most_common())


def plan_report(why, bound, refs=None):
    """The link report's summary of plan_link(): names by class (bound or why not), with their references."""
    by = collections.Counter()
    nref = collections.Counter()
    for s, (c, _d) in why.items():
        by[c] += 1
        nref[c] += (refs or {}).get(s, 0)
    return {"names bound in every object": len(bound),
            "classes": {c: {"names": n, "references": nref[c]} for c, n in by.most_common()}}


# ------------------------------------------------------------------------------------------------ the classifier
def read_unbound(path):
    rows = []
    for line in open(path, errors="replace"):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 3:
            rows.append((p[0], int(p[1]), p[2], p[3] if len(p) > 3 else p[2]))
    return rows


def objects_of(d):
    rep = json.load(open(os.path.join(d, "report.json")))
    return sorted(os.path.join(d, "cache", os.path.basename(o)) for o in rep["objects"].values())


def defined_and_labels(d, fmt):
    """The objects' defined names (MS spelling) plus what native_mac's link tables define (type descriptors, vftable
    and RTTI record labels)."""
    import native_mac as nm
    objs = objects_of(d)
    if fmt == "elf":
        import native_elf as ne
        syms = ne.nm_elf(objs, cp.tool("llvm-nm"))
    else:
        syms = nm.nm_macho(objs)
    defined = set()
    for _o, (dd, _u) in syms.items():
        defined |= dd
    _rtti, _n, td = nm.type_descriptors(defined)
    defined |= td
    labels = set(td)
    return defined, labels


class WineIndex(dict):
    """{normalized demangled key: (how, addr, def)} of the Wine build's binding map, and by qualified name alone
    (`lookup`: a 64-bit name whose types differ from the 32-bit one, `hulk_intptr` / `size_t` parameters, a
    `hulk_freg` result, is found by its qualified name when the map binds that name to one address)."""

    def __init__(self):
        super().__init__()
        self.by_name = collections.defaultdict(set)

    def lookup(self, sym, dem):
        k = norm(dem.get(sym, sym)) if sym.startswith("?") else c_plain32(sym)
        w = self.get(k)
        if w is not None or not sym.startswith("?"):
            return w
        sh = shape(dem.get(sym, sym))
        if not sh:
            return None
        a = self.by_name.get(sh["name"])
        if a and len(a) == 1:
            ad = next(iter(a))
            return ("by name", ad, None) if ad else ("ambiguous", None, None)
        return None


def wine_index(bindings_path):
    b = json.load(open(bindings_path))
    names = list(b["bindings"]) + list(b.get("ambiguous", {}))
    dem = cp.undname(sorted(s for s in names if s.startswith("?")))
    idx = WineIndex()
    for s, v in b["bindings"].items():
        k = norm(dem.get(s, s)) if s.startswith("?") else c_plain32(s)
        idx[k] = ("+".join(sorted(set(v["how"]))) if isinstance(v.get("how"), list) else str(v.get("how")),
                  v["addr"], v.get("def"))
        if s.startswith("?"):
            sh = shape(dem.get(s, s))
            if sh:
                idx.by_name[sh["name"]].add(v["addr"])
    for s in b.get("ambiguous", {}):
        k = norm(dem.get(s, s)) if s.startswith("?") else c_plain32(s)
        idx.setdefault(k, ("ambiguous", None, None))
        if s.startswith("?"):
            sh = shape(dem.get(s, s))
            if sh:
                idx.by_name[sh["name"]].add(None)
    return idx


def wine_how(how):
    if how == "ambiguous":
        return "ambiguous (renamed per object / per function)"
    if "position" in how and "name" not in how:
        return "relocation position"
    if how.startswith("equiv:name") or "name" in how:
        return "equiv.py name / name+position"
    if how.startswith("equiv:"):
        return "equiv.py binding (" + how.split("+")[0][6:] + ")"
    return how


def invented_class(s, d):
    """The class of a name that carries no address."""
    if s.startswith("??_R") or "RTTI" in d:
        return "invented: RTTI descriptor"
    if s.startswith("??_7") or re.search(r"vftable|vtable|Vtable|_vt\b|g_vA\b|g_vt", d):
        return "invented: vftable variable"
    sh = shape(d) if s.startswith("?") else None
    if not s.startswith("?"):
        return "invented: C name"
    if sh is None:
        return "invented: other C++ name"
    if sh["kind"] == "data":
        return "invented: variable"
    if sh.get("virtual"):
        return "invented: virtual member of a stub class"
    if s.startswith("??0") or s.startswith("??1"):
        return "invented: constructor / destructor of a stub class"
    if sh["member"] or "::" in FN_NS.sub("", sh["name"]):
        return "invented: member of a stub class"
    return "invented: free function"


def cmd_classify(a):
    d = a.dir
    rows = read_unbound(a.unbound or os.path.join(d, "unbound.txt"))
    crt = [r for r in rows if r[0].startswith("native CRT table")]
    vslot = [r for r in rows if r[0].startswith("link: vftable slot")]
    rows = [r for r in rows if r[0].startswith("unbound") or r[0].startswith("no 32-bit") or r[0].startswith("name table")]
    defined, labels = defined_and_labels(d, a.fmt)
    rtti_lab = set()
    try:
        import native_mac as nm
        tdefs = nm.TreeDefs(defined)
        _asm, _st, _u = nm.code_owned64(tdefs, nm.crt_bindings()[1], defined)
        rtti_lab = set(re.findall(r'^"_(DAT_[0-9a-f]{8})":', _asm, re.M))
    except Exception as e:  # (the XBE missing: no record labels)
        print("note: no vftable/RTTI labels (%s)" % e, file=sys.stderr)
    defs = Defs(defined)
    dem = {r[2]: r[3] for r in rows}
    undef = [r[2] for r in rows]
    refs = {r[2]: r[1] for r in rows}
    data_def = {s for s in defined if s.startswith("DAT_")}
    widx = wine_index(a.bindings) if a.bindings else None
    whatif = None
    objs = objects_of(d)
    sigs = load_signatures(objs)
    if sigs:
        import native_mac as nm_
        syms = (__import__("native_elf").nm_elf(objs, cp.tool("llvm-nm")) if a.fmt == "elf" else nm_.nm_macho(objs))
        _ren, why, bound = plan_link(objs, syms, defs, defined, labels | rtti_lab, sigs, verify=widx)
        ab = {}
        for s_ in undef:
            if s_ in why:
                c_, det_ = why[s_]
                ab[s_] = ("address in name: " + c_, s_ if s_ in bound else None, det_)
        print("IR signatures: %d / %d objects" % (len(sigs), len(objs)), file=sys.stderr)
        if widx is not None and a.whatif:
            inv = [s_ for s_ in undef if s_ not in ab]
            whatif = whatif_map(syms, defs, widx, sigs, inv, data_def)
    else:
        ab = address_bindings(undef, defs, dem, data_def, rtti_lab)
    wine_unb = set()
    if a.wine_unbound and os.path.exists(a.wine_unbound):
        wdem = [l.rstrip("\n").split("\t") for l in open(a.wine_unbound)]
        names = [p[2] for p in wdem if len(p) > 2]
        wd = cp.undname(sorted(n.lstrip("_") if n.startswith("_?") else n for n in names if n.lstrip("_").startswith("?")))
        for n in names:
            m = n[1:] if n.startswith("_?") else n
            wine_unb.add(norm(wd.get(m, m)) if m.startswith("?") else c_plain32(n))
    cls = collections.OrderedDict()
    cross, cross_ex = collections.Counter(), []
    for s in undef:
        dsym = None
        if s in ab:
            c, t, det = ab[s][:3]
            dsym = ab[s][3] if len(ab[s]) > 3 else (t if t != s else None)
        else:
            c, t, det = invented_class(s, dem.get(s, s)), None, ""
        w = ""
        if widx is not None:
            k = norm(dem.get(s, s)) if s.startswith("?") else s
            wl = widx.lookup(s, dem)
            if k in wine_unb:
                w = "stubbed in the Wine build too"
            elif wl is not None:
                w = wine_how(wl[0])
            else:
                w = "not in the binding map (slot alias / stand-in / site rebinding)"
            if t:
                # the Wine build's binding (relocation-proven) of the same name, against the address the name says
                wa = (wl or (None, None, None))[1]
                na = name_address(s)[0]
                cross["no Wine binding"] += wa is None
                if wa is not None:
                    ok = int(wa, 16) == na
                    cross["agrees with the Wine binding map" if ok else "DISAGREES with the Wine binding map"] += 1
                    if not ok:
                        cross_ex.append((s, "%#x" % na, wa))
        e = cls.setdefault(c, {"symbols": 0, "references": 0, "bindable": 0, "wine": collections.Counter(),
                               "detail": collections.Counter(), "examples": []})
        e["symbols"] += 1
        e["references"] += refs[s]
        if t:
            e["bindable"] += 1
        if w:
            e["wine"][w] += 1
        if det:
            e["detail"][det] += 1
        if len(e["examples"]) < a.examples or (len(e["examples"]) < a.examples * 4 and hash(s) % 50 == 0):
            e["examples"].append((s, dem.get(s, s)[:200], dsym, defs.dem64.get(dsym, dsym)[:200] if dsym else None))
    total = len(undef)
    bindable = sum(1 for s in undef if s in ab and ab[s][1])
    out = {"dir": d, "unbound": total, "native CRT table rows": len(crt), "vftable slots without a definition": len(vslot),
           "bindable by the address in the name": bindable, "unbound after": total - bindable,
           "bound names against the Wine binding map": dict(cross), "disagreements (examples)": cross_ex,
           "names without an address: what the Wine binding map would bind (report only)": whatif,
           "classes": {}}
    for c, e in sorted(cls.items(), key=lambda kv: -kv[1]["symbols"]):
        out["classes"][c] = {"symbols": e["symbols"], "references": e["references"], "bindable": e["bindable"],
                             "wine": dict(e["wine"].most_common()), "detail": dict(e["detail"].most_common(8)),
                             "examples": e["examples"][:a.examples]}
    if a.json:
        with open(a.json, "w") as f:
            json.dump(out, f, indent=1)
    print("%s: unbound %d (CRT rows %d apart); bindable by address %d -> %d" %
          (d, total, len(crt), bindable, total - bindable))
    print("cross-check: %s" % dict(cross))
    for c, e in out["classes"].items():
        print("%7d %7d  %s%s" % (e["symbols"], e["bindable"], c,
                                 ("  [wine: %s]" % ", ".join("%s %d" % kv for kv in list(e["wine"].items())[:3]))
                                 if e["wine"] else ""))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("classify")
    c.add_argument("--dir", required=True, help="a native output directory (report.json, cache/, unbound.txt)")
    c.add_argument("--fmt", choices=["macho", "elf"], default="macho")
    c.add_argument("--bindings", help="the Wine build's binding map of the same tree (how the Wine link binds each name)")
    c.add_argument("--wine-unbound", help="the Wine build's unbound.txt (names it stubs too)")
    c.add_argument("--unbound", help="the unbound list to classify (default DIR/unbound.txt; a --no-addr link's for the "
                   "classes before the address bindings)")
    c.add_argument("--whatif", action="store_true", help="also estimate what the binding map would bind of the names "
                   "without an address (the rejected name table, with the IR check)")
    c.add_argument("--json")
    c.add_argument("--examples", type=int, default=6)
    a = ap.parse_args(argv)
    if a.cmd == "classify":
        return cmd_classify(a)


if __name__ == "__main__":
    sys.exit(main())
