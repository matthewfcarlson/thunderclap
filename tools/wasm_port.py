#!/usr/bin/env python3
"""The wasm32 port build: every tree function, linked by address (docs/wasm-port.md).

  build/venv/bin/python tools/wasm_port.py compile [--jobs N] [--only TU ...]   # tree TUs -> build/wasm/obj/*.o
  build/venv/bin/python tools/wasm_port.py link                                 # glue + host + emcc -> build/wasm/hulk.{js,wasm}
  build/venv/bin/python tools/wasm_port.py report                               # what the last link left unbound

Inputs: a clang_probe snapshot of the tree (HULK_WASM_SNAP, default build/wasm/cp/snap: manifest.json, report.json,
src/, include/, repo-include/; `tools/clang_probe.py --snapshot` after `tools/tree_tu.py materialize`) and the Wine
build's binding map of the same tree (HULK_WASM_BINDINGS, default build/wasm/maps/bindings.json): which XBE address
each name the tree references means, and which name defines each address. wasm32 has 4-byte pointers, so every
record keeps its 32-bit layout.

Each TU is compiled by clang's front end for `i686-pc-windows-msvc` with the Wine build's flags (the MS C++ ABI the
sources were written against: thiscall, vftable layouts, mangled names, RTTI) to LLVM IR, which `bind_tu()` rewrites
and retargets to wasm32 (after the owner's fusion-frenzy port, tools/wasm_ir.py):

  * every block's function becomes `ff_<addr>`, with a generic entry `ffg_<addr>(ecx, edx, stack, ret)` that takes
    x86-placed arguments; inline/linkonce helpers become internal;
  * data bound to an XBE address becomes that address (`inttoptr`): the host loads the XBE's sections into linear
    memory where the original had them (vftables, RTTI and every table are the original's bytes);
  * a direct call goes to `ff_<addr>` when its declared type is the definition's (as wasm types), otherwise through a
    packer that lays the arguments out as x86 would and calls the generic entry: declarations that disagree with the
    definition keep their x86 meaning instead of trapping;
  * a function used as a value is its original address; every indirect call (vftables, callbacks) goes through
    `ff_dispatch(addr, ...)`, a binary search over the generic entries.
"""
import argparse
import collections
import concurrent.futures
import csv
import hashlib
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from wasm_ir import (CALL, CCS, LOCAL, NAME, TOKEN, ALIAS, DATALAYOUT, TRIPLE, Param, Sig, at, coff_names,  # noqa: E402
                     deleting_dtor, entry, irname, matching, packer, parse_func_line, ret_type, retarget,
                     split_top, typedefs, vararg_call)

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.environ.get("HULK_WASM_DIR") or os.path.join(ROOT, "build/wasm")
SNAP = os.environ.get("HULK_WASM_SNAP") or os.path.join(OUT, "cp/snap")
BINDINGS = os.environ.get("HULK_WASM_BINDINGS") or os.path.join(OUT, "maps/bindings.json")
XBE = os.environ.get("HULK_XBE") or os.path.join(ROOT, "isos/extracted/default.xbe")
LLVM = os.environ.get("HULK_LLVM_BIN", "/opt/homebrew/opt/llvm/bin")
CLANG = os.path.join(LLVM, "clang++")
EMCC = os.environ.get("HULK_EMCC", "emcc")
HOST_DIR = os.path.join(ROOT, "src/platform/wasm")

# the Wine build's `msvc` configuration (tools/clang_probe.py CONFIGS["msvc"], SSE float), as IR
DIALECT = ["-Xclang", "-fno-wchar", "-fno-operator-names", "-Wno-c++11-narrowing", "-Wno-address-of-temporary"]
FRONT = (["--target=i686-pc-windows-msvc", "-fms-extensions", "-fms-compatibility", "-fms-compatibility-version=13.10",
          "-std=c++14", "-O0", "-S", "-emit-llvm", "-include", "compat/native.h", "-fno-strict-aliasing", "-fwrapv",
          "-fno-delete-null-pointer-checks"] + DIALECT
         + ["-msse2", "-mfpmath=sse", "-ffp-eval-method=double", "-ffp-contract=off", "-fcheck-new", "-fno-exceptions",
            "-w", "-DHULK_WASM=1"])
BACK = ["--target=wasm32-unknown-emscripten", "-O1", "-c", "-Wno-override-module"]
HOST_CFLAGS = ["-O1", "-Wall", "-Wextra", "-Werror"]
VERSION = "wasm1-8"          # bump when bind_tu() changes (object cache key)
SYNTH = 0xF0000000

# library code inside .text (tools/platform_map.py) and the library sections after it
LIB_SPANS = [(0x208b9c, 0x212bb0), (0x3440e0, 0x356bf0), (0x35a7b0, 0x35be88), (0x364840, 0x3f2be0)]
CODE = (0x11000, 0x3f2be0)


def is_code(a):
    return CODE[0] <= a < CODE[1]


def is_library(a):
    return any(lo <= a < hi for lo, hi in LIB_SPANS)


# ---------------------------------------------------------------------------------------------- inputs
def manifest():
    return json.load(open(os.path.join(SNAP, "manifest.json")))["tus"]


_MAP = None


def binding_map():
    global _MAP
    if _MAP is None:
        _MAP = json.load(open(BINDINGS))
    return _MAP


_BASE = None


def tu_bindings(tu):
    """{IR spelling of a name: address} for TU: the map's bindings plus its per-TU choice of an ambiguous name."""
    global _BASE
    m = binding_map()
    if _BASE is None:
        _BASE = {}
        for n, v in m["bindings"].items():
            if v.get("addr"):
                for s in coff_names(n):
                    _BASE[s] = int(v["addr"], 16)
        # data a TU defines that is the original's (a static object the game's other code reads at its address)
        for n, a in m.get("local_data", {}).items():
            for s in coff_names(n):
                _BASE[s] = int(a, 16)
    out = dict(_BASE)
    for n, by in m.get("ambiguous_by_tu", {}).items():
        a = by.get(tu)
        if a:
            for s in coff_names(n):
                out[s] = int(a, 16)
    return out


def unwrap(n):
    """A mangled name without the tree's wrapping namespaces: `?f@X@fn_0001d1e0@@...` -> `?f@X@@...`."""
    return re.sub(r"@fn_[0-9a-f]{8}(?=@)", "", n)


HEX_NAME = re.compile(r'(?<![0-9A-Za-z])(?:FUN|DAT|LAB|PTR_DAT|PTR_FUN|PTR_LAB|thunk_FUN)_([0-9a-fA-F]{8})(?![0-9A-Za-z])')


def name_address(n):
    m = HEX_NAME.search(n)
    return int(m.group(1), 16) if m else None


# ---------------------------------------------------------------------------------------------- front end
def tu_key(rel):
    """Content key of a TU: its text plus every header of the snapshot (one digest)."""
    return hashlib.sha1(open(os.path.join(SNAP, rel), "rb").read() + include_digest().encode()
                        + " ".join(FRONT).encode()).hexdigest()[:20]


_DIGEST = None


def include_digest():
    global _DIGEST
    if _DIGEST is None:
        h = hashlib.sha1()
        for base in ("include", "repo-include"):
            for dp, dns, fns in sorted(os.walk(os.path.join(SNAP, base))):
                dns.sort()
                for fn in sorted(fns):
                    p = os.path.join(dp, fn)
                    h.update(os.path.relpath(p, SNAP).encode())
                    h.update(open(p, "rb").read())
        _DIGEST = h.hexdigest()
    return _DIGEST


def flat(rel):
    return re.sub(r"[^\w.]", "_", rel)


def front(rel):
    """x86 IR of a snapshot TU (cached by content): path of the .ll, or raises."""
    key = tu_key(rel)
    d = os.path.join(OUT, "ir")
    os.makedirs(d, exist_ok=True)
    ll = os.path.join(d, "%s.%s.ll" % (flat(rel)[-80:], key))
    if not os.path.exists(ll):
        cmd = [CLANG] + FRONT + ["-I" + os.path.join(SNAP, "include"), "-I" + os.path.join(SNAP, "repo-include"),
                                 os.path.join(SNAP, rel), "-o", ll + ".tmp"]
        r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
        if r.returncode:
            raise RuntimeError("front: " + "\n".join(x for x in r.stderr.splitlines() if "error" in x)[:800])
        os.replace(ll + ".tmp", ll)
    return ll


def strip_attr(text, attr):
    """TEXT without every ` ATTR(...)` (balanced brackets)."""
    if attr + "(" not in text:
        return text
    out, i = [], 0
    while True:
        j = text.find(attr + "(", i)
        if j < 0:
            break
        k = matching(text, j + len(attr))
        out.append(text[i:j].rstrip(" "))
        out.append(" ")
        i = k
        while i < len(text) and text[i] == " ":
            i += 1
    out.append(text[i:])
    return "".join(out)


def strip_inalloca(ir):
    """MS i686 passes a by-value object with a copy constructor or destructor `inalloca`: the caller builds the
    whole stack-argument block (a packed struct in x86 stack layout) and passes it; WebAssembly has no such thing.
    The block becomes a `byval` argument: a direct call copies it, and a packer / generic entry lays it at the
    stack area's start, so a caller that declares the arguments one by one (or the reverse) still meets them where
    x86 had them. (The copy is bitwise; the callee destroys it, as it destroys the block.)"""
    if "inalloca" not in ir:
        return ir
    return ir.replace("alloca inalloca ", "alloca ").replace("inalloca(", "byval(")


def fix_va_frames(ir, notes=None):
    """A variadic function that walks its arguments x86-style, from the address of its last named parameter
    (`(char*)&fmt + 4`), reads its own local copy of the parameter on wasm. Its address there becomes the variadic
    area's (llvm.va_start) less the parameter's slot. Callers pass the variadic arguments as x86 words
    (wasm_ir.x86_words), so the area has the x86 layout the function expects."""
    if "...) " not in ir:
        return ir
    lines = ir.split("\n")
    out = []
    k = 0
    changed = False
    while k < len(lines):
        l = lines[k]
        if not (l.startswith("define ") and ", ...)" in l):
            out.append(l)
            k += 1
            continue
        end = k
        while lines[end] != "}":
            end += 1
        body = lines[k + 1:end]
        p = parse_func_line(l)
        if not p or not p[3].params or not p[3].params[-1].name:
            out += lines[k:end + 1]
            k = end + 1
            continue
        last = p[3].params[-1]
        slot = None
        for b in body:
            m = re.match(r"\s*store %s %s, ptr (%%[-\w.]+)," % (re.escape(last.type), re.escape(last.name)), b)
            if m:
                slot = m.group(1)
                break
        uses = [i for i, b in enumerate(body) if slot and re.search(r"(getelementptr[^\n]*|ptrtoint) ptr %s\b(?![-\w.])"
                                                                   % re.escape(slot), b)]
        if not uses:
            out += lines[k:end + 1]
            k = end + 1
            continue
        size = 8 if last.type in ("double", "i64") else 4
        new = [l, "  %ffva.l = alloca ptr, align 4", "  call void @llvm.va_start.p0(ptr %ffva.l)",
               "  %ffva.p = load ptr, ptr %ffva.l, align 4",
               "  %%ffva.base = getelementptr i8, ptr %%ffva.p, i32 -%d" % size]
        for i, b in enumerate(body):
            if i in uses:
                b = re.sub(r"((?:getelementptr[^\n]*|ptrtoint) ptr )%s(?![-\w.])" % re.escape(slot), r"\1%ffva.base", b)
            new.append(b)
        out += new + ["}"]
        changed = True
        if notes is not None:
            notes["x86 variadic frame"] += 1
        k = end + 1
    ir = "\n".join(out)
    if changed and "declare void @llvm.va_start.p0(" not in ir:
        ir += "\ndeclare void @llvm.va_start.p0(ptr)\n"
    return ir


def prepare(ir):
    """Function aliases replaced by what they alias (vftable aliases are not function aliases and stay)."""
    ir = fix_va_frames(strip_inalloca(ir))
    for m in list(ALIAS.finditer(ir)):
        a, t = m.group(1), m.group(2)
        ir = ir.replace(m.group(0) + "\n", "", 1)
        ir = re.sub(re.escape(a) + r'(?![-\w.$"])', lambda _: t, ir)
    return ir


def undname(names):
    """{mangled: undecorated} via llvm-undname."""
    names = sorted(n for n in names if n.startswith("?"))
    if not names:
        return {}
    r = subprocess.run([os.path.join(LLVM, "llvm-undname")], input="\n".join(names) + "\n", capture_output=True,
                       text=True)
    out, lines = {}, r.stdout.split("\n")
    for k in range(len(lines) - 1):
        if lines[k] in names:
            out[lines[k]] = lines[k + 1]
    return out


def _plain(s):
    return re.sub(r"\b(?:class|struct|enum|union) ", "", s).replace(" ", "")


_BLOCK_NAMES = None
_BLOCK_SYMS = None


def block_names():
    """{addr: the tree's name of the block} (snapshot report.json)."""
    global _BLOCK_NAMES, _BLOCK_SYMS
    if _BLOCK_NAMES is None:
        r = json.load(open(os.path.join(SNAP, "report.json")))
        _BLOCK_NAMES = {int(c["addr"], 16): c.get("name") or "" for c in r["checks"]}
        _BLOCK_SYMS = {int(c["addr"], 16): c.get("symbol") or "" for c in r["checks"]}
    return _BLOCK_NAMES


def block_syms():
    """{addr: the block's pinned symbol} (report.json; a `$L#k@owner` label pin names its owner)."""
    block_names()
    return {a: re.sub(r"^\$L#\d+@", "", s) for a, s in _BLOCK_SYMS.items() if s}


def tu_mains(tu, ir, defmap, alt=None):
    """({IR name: address} of the TU's block definitions, {address: IR name} of blocks that are another block's
    code (identical code under one pinned symbol: a generic entry forwards)). By the map's definition name; else the
    name with a float result spelled double (hulk_freg: `M` -> `N`); else the block's tree name (undecorated)."""
    defs = set(irname(t) for t in re.findall(r'^define [^\n]*?(' + NAME + r')\(', ir, re.M))
    out, rest = {}, []
    for a, sym in sorted(defmap.items()):
        hit = next((s for s in coff_names(sym) if s in defs and s not in out), None)
        if hit is None and alt and a in alt:
            hit = next((s for s in coff_names(alt[a]) if s in defs and s not in out), None)
        if hit is None and sym.startswith("_$E"):
            # cl's dynamic initializer: the TU's own initializer (all of its ??__E, as the native start-up table)
            c = [d for d in defs if d.startswith("_GLOBAL__sub_I_") and d not in out]
            c = c or [d for d in defs if d.startswith("??__E") and d not in out]
            hit = c[0] if len(c) == 1 else None
        if hit is None:
            for k in range(len(sym)):
                if sym[k] == "M" and "@@" in sym[:k] and sym[k - 1] in "EAGIZ@":
                    v = sym[:k] + "N" + sym[k + 1:]
                    if v in defs and v not in out:
                        hit = v
                        break
        if hit:
            out[hit] = a
        else:
            rest.append(a)
    same = {}
    if rest:
        un = None
        names = block_names()
        for a in rest:
            want = _plain(names.get(a, "")) + "("
            if want != "(" and "::" in want:
                if un is None:
                    un = {n: _plain(d) for n, d in undname(defs - set(out)).items()}
                c = [n for n, d in un.items() if want in d and n not in out]
                if len(c) == 1:
                    out[c[0]] = a
                    continue
            sym = defmap[a]
            hit = next((s for s in coff_names(sym) if s in out), None)
            if hit:
                same[a] = hit
    return out, same


ADJUSTOR = re.compile(r"@@[WO]\d")


def adjustors(img):
    """{addr: (target, ecx adjustment)} of the blocks that are this-adjustor thunks (`sub ecx, n; jmp target`), from
    the XBE's bytes."""
    out = {}
    for a, sym in block_syms().items():
        if ADJUSTOR.search(sym):
            b = img.read(a, 8)
            if b[0:2] == b"\x83\xe9" and b[3] == 0xE9:
                out[a] = ((a + 8 + int.from_bytes(b[4:8], "little", signed=True)) & 0xFFFFFFFF, b[2])
    return out


def load_tu(tu, addrs):
    """(prepared IR, mains, same) of a TU; a block that is a scalar deleting destructor clang didn't emit (it emits
    one only with its vftable) gets one in IR (wasm_ir.deleting_dtor)."""
    ir = prepare(open(front(tu), errors="surrogateescape").read())
    m = binding_map()["definitions"]
    pins = block_syms()
    # (an adjustor thunk's block is a stand-in that makes cl emit the thunk; the link writes its entry: adjustors())
    defmap = {a: pins.get(a) or m.get("0x%08x" % a) for a in addrs
              if (pins.get(a) or "0x%08x" % a in m) and not ADJUSTOR.search(pins.get(a) or "")}
    alt = {a: m["0x%08x" % a] for a in addrs if "0x%08x" % a in m and m["0x%08x" % a] != defmap.get(a)}
    mains, same = tu_mains(tu, ir, defmap, alt)
    found = set(mains.values()) | set(same)
    extra = [a for a in addrs if a not in found and defmap.get(a, "").startswith("??_G")]
    if extra:
        dtors = {n for n in binding_map()["bindings"] if n.startswith("??1")}
        for a in extra:
            sym = defmap[a]
            if not re.search(r'^define [^\n]*%s\(' % re.escape(at(sym)), ir, re.M):
                ir = deleting_dtor(ir, sym, dtors)
        mains, same = tu_mains(tu, ir, defmap, alt)
    return ir, mains, same


def defsig_of(job):
    """Pass 1: (tu, {addr: (sig key, (ret, [param types], varargs))}, error)."""
    tu, addrs = job
    try:
        ir, mains, same = load_tu(tu, addrs)
        types = typedefs(ir)
        out = {}
        for l in ir.split("\n"):
            if l.startswith("define "):
                p = parse_func_line(l)
                if p and p[2] in mains:
                    s = p[3]
                    out[mains[p[2]]] = (s.key(types), (s.ret, [q.type for q in s.params], s.varargs))
        for a, n in same.items():
            if mains[n] in out:
                out[a] = out[mains[n]]
        return tu, out, None
    except Exception as e:      # noqa: BLE001 - one TU's failure is a report line
        return tu, None, "%s: %s" % (type(e).__name__, str(e)[:800])


# ---------------------------------------------------------------------------------------------- binding
_PERFN = None


def per_function():
    """{caller IR name: {name IR spelling: address}}: the map's names that mean another address in some callers (two
    sources merged into one TU, each naming its own `Obj::Init`)."""
    global _PERFN
    if _PERFN is None:
        _PERFN = collections.defaultdict(dict)
        for n, per in binding_map().get("ambiguous_by_function", {}).items():
            for fn, a in per.items():
                for f in coff_names(fn):
                    for s_ in coff_names(n):
                        _PERFN[f][s_] = int(a, 16)
    return _PERFN


def rebind_per_function(ir, bound, notes):
    """In a function the map rebinds a name for, the name becomes `name$addr` (declared as the name is), bound to
    that address."""
    per = per_function()
    lines = ir.split("\n")
    decl_line = {}
    for l in lines:
        if l.startswith("declare "):
            p = parse_func_line(l)
            if p:
                decl_line[p[2]] = l
        elif l.startswith("@") and " external " in l:
            m = re.match("(" + NAME + r") = ", l)
            if m:
                decl_line[irname(m.group(1))] = l
    cur, extra = None, {}
    for k, l in enumerate(lines):
        if l.startswith("define "):
            p = parse_func_line(l)
            cur = per.get(p[2]) if p else None
            continue
        if l == "}":
            cur = None
            continue
        if not cur:
            continue
        for n, a in cur.items():
            tok = at(n)
            if tok in l and n in decl_line:
                new = "%s$%08x" % (n, a)
                l = re.sub(re.escape(tok) + r'(?![-\w.$"])', lambda _: at(new), l)
                bound[new] = a
                extra[new] = decl_line[n].replace(tok, at(new), 1)
                notes["rebound per calling function"] += 1
        lines[k] = l
    return "\n".join(lines + list(extra.values())) if extra else ir


# the host's variadic C library functions (ret, fixed parameters, variadic), as callers' variadic calls need them
HOST_VARIADIC = {0x00344f75: ("i32", ["ptr", "ptr"], True), 0x00356734: ("i32", ["ptr", "ptr"], True),
                 0x00345804: ("i32", ["ptr", "ptr"], True), 0x00347792: ("i32", ["ptr", "ptr"], True)}


class _Every:
    """Every variadic callee walks its list x86-style: the game's own (fix_va_frames) and the host's (crt.c reads
    the area as x86 stack slots)."""
    def __contains__(self, _):
        return True


X86VA = _Every()


def bind_tu(ir, tu, tu_index, mains, same, bound, game, defsig, deftys):
    """x86 IR of TU -> (wasm32 IR, notes). MAINS: {IR name: addr} of its blocks; BOUND: {IR name: addr}; GAME: every
    address with a definition; DEFSIG/DEFTYS: their signatures."""
    notes = collections.Counter()
    mism = []
    bound = dict(bound)
    ir = rebind_per_function(ir, bound, notes)
    types = typedefs(ir)
    lines = ir.split("\n")
    defs, decls, gdefs = {}, {}, {}
    for k, l in enumerate(lines):
        if l.startswith("define ") or l.startswith("declare "):
            p = parse_func_line(l)
            if p:
                (defs if p[0] == "define" else decls)[p[2]] = (k, p)
        elif l.startswith("@"):
            m = re.match("(" + NAME + r") = ", l)
            if m:
                gdefs[irname(m.group(1))] = k
    # names the map doesn't bind: the TU's `// equiv-map: NAME = 0xADDR` hints (also for the name without the tree's
    # wrapping namespaces, `@fn_<hex>`), then a name that spells an address
    hints = {}
    for m in re.finditer(r"^// equiv-map: (\S+) = (0x[0-9a-fA-F]+)", open(os.path.join(SNAP, tu), errors="replace").read(),
                         re.M):
        hints[m.group(1)] = int(m.group(2), 16)
    for n in list(decls) + [g for g in gdefs if re.search(r" = (?:\w+ )*external ", lines[gdefs[g]])]:
        if n in bound or n.startswith("llvm."):
            continue
        u = unwrap(n)
        a = hints.get(n, hints.get(u))
        if a is not None and (n in decls) == is_code(a):
            bound[n] = a
            notes["bound by equiv-map / unwrapped name"] += 1
    for n in list(decls) + [g for g in gdefs if re.search(r" = (?:\w+ )*external ", lines[gdefs[g]])]:
        if n not in bound and not n.startswith("llvm."):
            a = name_address(n)
            if a is not None and (n in decls) == is_code(a):
                bound[n] = a
                notes["bound by name"] += 1
    extra = []
    packers = {}

    def need_packer(sig, target, indirect=False):
        key = (sig.key(types), target, indirect)
        if key not in packers:
            name = "ffp.%d" % len(packers)
            packers[key] = name
            extra.extend(packer(name, sig, target, types, indirect))
        return packers[key]

    sigs = {n: p[3] for n, (_, p) in list(defs.items()) + list(decls.items())}
    redirect = {}

    def canonical(name):
        """A local (inline) definition the game has at an address with a tree definition: call that one."""
        a = bound.get(name)
        return a is not None and a in game and name not in mains

    def callee_for(name, sig):
        if name in mains:
            return "ff_%08x" % mains[name]
        if name in defs and not canonical(name):
            return None                     # a local function: the call stays
        a = bound.get(name)
        if a is None:
            return None                     # unbound: libc by name, or reported by the link
        if not is_code(a):
            notes["call bound to data"] += 1
            return None
        if a in game:
            if not sig.varargs and a in deftys and deftys[a][2]:
                return "ff_%08x" % a        # fixed declaration of a variadic definition: vararg_call retypes it
            if sig.varargs and a in deftys and not deftys[a][2]:
                return "argpack:%08x" % a
            if defsig.get(a) == sig.key(types) or sig.varargs:
                if sig.varargs and defsig.get(a) != sig.key(types):
                    mism.append(("0x%08x" % a, name, "varargs", sig.key(types), defsig.get(a)))
                return "ff_%08x" % a
            mism.append(("0x%08x" % a, name, "packed", sig.key(types), defsig.get(a)))
            notes["packed call"] += 1
            return need_packer(sig, "ffg_%08x" % a)
        if sig.varargs:
            notes["variadic library call"] += 1
            return "ff_%08x" % a            # the host defines a variadic C function
        notes["library call"] += 1
        return need_packer(sig, "ffg_%08x" % a)

    def rewrite_call(m, line):
        pre, tok = m.group(1), m.group(2)
        if tok.startswith("%"):
            close = matching(line, m.end() - 1)
            args = split_top(line[m.end():close - 1])
            cc = next((w for w in pre.split() if w in CCS), None)
            fnty = re.search(r'\(([^()]*)\)\s*$', pre)
            if fnty and fnty.group(1).rstrip().endswith("..."):
                notes["indirect varargs call"] += 1
                return None
            ps = [Param(a.rsplit(" ", 1)[0]) for a in args]
            sig = Sig(cc, ret_type(re.sub(r'\([^()]*\)\s*$', '', pre).strip() or "void")
                      if fnty else ret_type(pre), ps, False)
            name = need_packer(sig, None, indirect=True)
            notes["indirect call"] += 1
            return "%s(ptr %s%s" % (at(name), tok, ", " if args else "")
        name = irname(tok)
        if name.startswith("llvm."):
            return None
        if name in defs and name not in mains and not canonical(name):
            return '@"ffl$%s"(' % name         # a local function: the call stays (restored below)
        sig = sigs.get(name)
        if sig is None:
            return None
        to = callee_for(name, sig)
        if to is None:
            return None
        if to.startswith("argpack:"):
            close = matching(line, m.end() - 1)
            args = split_top(line[m.end():close - 1])
            cc = next((w for w in pre.split() if w in CCS), None)
            ps = [Param(x.rsplit(" ", 1)[0]) for x in args]
            notes["variadic declaration of a fixed definition"] += 1
            return at(need_packer(Sig(cc, sig.ret, ps, False), "ffg_" + to[8:])) + "("
        if to.startswith("ff_"):
            redirect[name] = to
        return at(to) + "("

    out = []
    for l in lines:
        if " call " in l and not l.startswith(("define", "declare")):
            pos, buf = 0, []
            for m in CALL.finditer(l):
                new = rewrite_call(m, l)
                if new is None:
                    continue
                buf.append(l[pos:m.start(2)])
                buf.append(new)
                pos = m.end()
            buf.append(l[pos:])
            l = "".join(buf)
            l = re.sub(r'(@ffp\.\d+\(ptr ' + LOCAL + r')\)', r'\1)', l)
            l = re.sub(r'\([^()]*\.\.\.\) (@ffp\.\d+\()', r'\1', l)
            if "@ffp." in l:        # a packer's parameters are plain: no sret/byval at the call
                l = strip_attr(strip_attr(l, "sret"), "byval")
            # a packer is called with its own (plain) return type: drop a function type before it
            if "@ff_" in l:
                l = vararg_call(l, {**HOST_VARIADIC, **deftys}, notes, X86VA, types)
        out.append(l)
    lines = out
    # every remaining use of a symbol: functions as values, data
    value = {}
    for name in list(defs) + list(decls) + list(gdefs):
        if name in mains:
            value[name] = mains[name]
        elif name in bound and name not in defs:
            value[name] = bound[name]
    synth = []
    taken = set()
    for l in lines:
        if l.startswith(("define", "declare")):
            continue
        for m in TOKEN.finditer(l):
            n = irname(m.group(0))
            if n in defs and n not in mains:
                if n in bound:
                    value[n] = bound[n]
                else:
                    taken.add(n)
    for i, n in enumerate(sorted(taken)):
        value[n] = SYNTH + (tu_index << 14) + i
        synth.append((value[n], n))

    def sub(m):
        n = irname(m.group(0))
        if n in redirect and n not in value:
            return at(redirect[n])
        if n in value:
            return "inttoptr (i32 %d to ptr)" % value[n]
        return m.group(0)
    drop = set()
    for n in value:
        if n in gdefs:
            drop.add(gdefs[n])
        if n in decls:
            drop.add(decls[n][0])
    for n in redirect:
        if n in decls:
            drop.add(decls[n][0])
    comdats = set(irname("@" + c[1:]) for c in re.findall(r'^(\$(?:"[^"]+"|[-\w.$?@]+)) = comdat ', ir, re.M))
    keep = []
    for k, l in enumerate(lines):
        if k in drop:
            continue
        if l.startswith("define "):
            p = parse_func_line(l)
            name = p[2]
            if name in mains:
                l = re.sub(r'^define (?:(?:linkonce_odr|weak_odr|weak|linkonce|external|available_externally|'
                           r'dso_local|hidden|protected|internal|private|dllexport) )*', "define ", l, count=1)
                l = l.replace(at(name) + "(", at("ff_%08x" % mains[name]) + "(", 1)
            elif re.match(r'^define (?:dso_local )?(?:(?:linkonce_odr|linkonce|weak_odr|weak|internal|private) )', l):
                l = re.sub(r'^define (?:(?:linkonce_odr|weak_odr|weak|linkonce|external|available_externally|'
                           r'dso_local|hidden|protected|internal|private) )*', "define internal ", l, count=1)
            l = re.sub(r' comdat(\([^)]*\))?', '', l)
            keep.append(l)
            continue
        if l.startswith("declare "):
            keep.append(l)
            continue
        if l.startswith("@"):
            m = re.match("(" + NAME + r") = (.*)$", l)
            if m:
                rest = m.group(2)
                if (", comdat" in rest or irname(m.group(1)) in comdats) and not rest.startswith("external"):
                    # a COMDAT member (vftables, selectany data, static locals of inline functions): this TU's copy
                    rest = re.sub(r'^(?:(?:linkonce_odr|weak_odr|weak|linkonce|common|dso_local|external|hidden|'
                                  r'private|internal) )*', "internal ", rest, count=1)
                rest = re.sub(r', comdat(\([^)]*\))?', '', rest)
                rest = re.sub(r'\b(dllimport|dllexport) ', '', rest)
                l = m.group(1) + " = " + TOKEN.sub(sub, rest)
            keep.append(l)
            continue
        if l.startswith("$") and " = comdat " in l:
            continue
        keep.append(TOKEN.sub(sub, l) if not l.startswith(("attributes", "!")) else l)
    lines = keep
    have = set()
    for n, to in redirect.items():
        if to in have or int(to[3:], 16) in mains.values() or int(to[3:], 16) in same:
            continue
        have.add(to)
        s = sigs[n]
        ty = deftys.get(int(to[3:], 16))
        if ty and ty[2]:
            lines.append("declare %s %s(%s, ...)" % (ty[0], at(to), ", ".join(ty[1])) if ty[1] else
                         "declare %s %s(...)" % (ty[0], at(to)))
            continue
        lines.append("declare %s %s(%s%s)" % (s.ret, at(to), ", ".join(
            p.type + (" byval(%s)" % p.byval if p.byval else "") + (" sret(%s)" % p.sret if p.sret else "")
            for p in s.params), ", ..." if s.varargs else ""))
    for name, a in sorted(mains.items(), key=lambda x: x[1]):
        lines += entry("ffg_%08x" % a, sigs[name], "ff_%08x" % a, types)
    for a, name in sorted(same.items()):        # identical code under one symbol (ICF): the other block's
        lines += entry("ffg_%08x" % a, sigs[name], "ff_%08x" % mains[name], types)
        lines.append("define %s @ff_%08x(%s) {" % (sigs[name].ret, a, ", ".join(
            "%s %%a%d" % (p.type, i) for i, p in enumerate(sigs[name].params))))
        call = "call %s @ff_%08x(%s)" % (sigs[name].ret, mains[name], ", ".join(
            "%s %%a%d" % (p.type, i) for i, p in enumerate(sigs[name].params)))
        lines += (["  " + call, "  ret void"] if sigs[name].ret == "void" else
                  ["  %r = " + call, "  ret %s %%r" % sigs[name].ret])
        lines.append("}")
    for v, n in synth:
        lines += entry("ffg_%08x" % v, sigs[n], n, types)
    lines += extra
    text = "\n".join(lines)
    for t in sorted({k[1] for k in packers if k[1]}):
        if "define void %s(" % at(t) not in text:
            lines.append("declare void %s(i32, i32, ptr, ptr)" % at(t))
    if any(k[2] for k in packers):
        lines.append("declare void @ff_dispatch(i32, i32, i32, ptr, ptr)")
    text = "\n".join(lines)
    for intr in ("declare void @llvm.memset.p0.i32(ptr, i8, i32, i1)",
                 "declare void @llvm.memcpy.p0.p0.i32(ptr, ptr, i32, i1)"):
        if intr.split("(")[0].split()[-1] + "(" not in text:
            text += "\n" + intr
    text = re.sub(r'@"ffl\$([^"]+)"', lambda m: at(m.group(1)), text)
    text = retarget(text)
    # x86-only function attributes clang put on the i686 definitions
    text = re.sub(r'"(stackrealign|probe-stack|stack-probe-size|min-legal-vector-width)"(="[^"]*")?', '', text)
    return text, {"notes": dict(notes), "mismatch": mism, "synth": ["0x%08x" % v for v, _ in synth],
                  "mains": len(mains)}


_G = {}


def _init(game, defsig, deftys):
    _G.update(game=game, defsig=defsig, deftys=deftys)


def compile_tu(job):
    tu, tu_index, addrs = job
    game, defsig, deftys = _G["game"], _G["defsig"], _G["deftys"]
    try:
        ir, mains, same = load_tu(tu, addrs)
        text, info = bind_tu(ir, tu, tu_index, mains, same, tu_bindings(tu), game, defsig, deftys)
        d = os.path.join(OUT, "obj")
        os.makedirs(d, exist_ok=True)
        wl = os.path.join(d, flat(tu) + ".ll")
        open(wl, "w", errors="surrogateescape").write(text)
        r = subprocess.run([CLANG] + BACK + ["-x", "ir", wl, "-o", wl[:-3] + ".o"], capture_output=True, text=True,
                           errors="replace")
        if r.returncode:
            return tu, None, "back: " + "\n".join(x for x in r.stderr.splitlines() if "error" in x)[:800]
        info["missing_blocks"] = sorted("0x%08x" % a for a in set(addrs) - set(mains.values()) - set(same))
        return tu, info, None
    except Exception as e:      # noqa: BLE001
        import traceback
        return tu, None, "%s: %s %s" % (type(e).__name__, str(e)[:600], traceback.format_exc()[-400:])


def cmd_compile(a):
    tus = manifest()
    index = {t["path"]: i for i, t in enumerate(tus)}
    addrs = {t["path"]: [int(b["addr"], 16) for b in t["blocks"]] for t in tus}
    want = a.only or sorted(addrs)
    os.makedirs(OUT, exist_ok=True)
    sigs, deftys, errs = {}, {}, {}
    with concurrent.futures.ProcessPoolExecutor(a.jobs) as ex:
        for i, (tu, k, err) in enumerate(ex.map(defsig_of, sorted(addrs.items()), chunksize=4), 1):
            if err:
                errs[tu] = err
                continue
            for ad, (key, ty) in k.items():
                sigs[ad] = key
                deftys[ad] = ty
            if i % 250 == 0:
                print("  front %d/%d" % (i, len(addrs)), file=sys.stderr, flush=True)
    game = set(sigs)
    jobs = [(t, index[t], addrs[t]) for t in want if t not in errs]
    res = {}
    with concurrent.futures.ProcessPoolExecutor(a.jobs, initializer=_init, initargs=(game, sigs, deftys)) as ex:
        for i, (tu, info, err) in enumerate(ex.map(compile_tu, jobs, chunksize=2), 1):
            if err:
                errs[tu] = err
            else:
                res[tu] = info
            if i % 250 == 0:
                print("  bind %d/%d" % (i, len(jobs)), file=sys.stderr, flush=True)
    rep = {"tus": len(addrs), "compiled": len(res), "functions": len(sigs), "failed": errs, "info": res,
           "sigs": {"0x%08x" % k: v for k, v in sigs.items()},
           "deftys": {"0x%08x" % k: v for k, v in deftys.items()}}
    path = os.path.join(OUT, "compile.json")
    if a.only and os.path.exists(path):
        prev = json.load(open(path))
        prev["info"].update(res)
        for t in res:
            prev["failed"].pop(t, None)
        prev["failed"].update(errs)
        prev["compiled"] = len(prev["info"])
        rep = prev
    json.dump(rep, open(path, "w"), indent=1)
    notes = collections.Counter()
    for v in rep["info"].values():
        notes.update(v["notes"])
    missing = sum(len(v.get("missing_blocks", [])) for v in rep["info"].values())
    print("compiled %d / %d TUs, %d functions defined, %d blocks without a definition found, failed %d"
          % (rep["compiled"], rep["tus"], len(rep["sigs"]), missing, len(rep["failed"])))
    print("  notes:", dict(notes.most_common()))
    for k, v in list(rep["failed"].items())[:20]:
        print("  %s %s" % (k, v.splitlines()[0][:300] if v else ""))


# ---------------------------------------------------------------------------------------------- link
C_TYPES = {"i32": "uint32_t", "ptr": "uint32_t", "i8": "int", "i16": "int", "i1": "int", "i64": "uint64_t",
           "float": "float", "double": "double", "void": "void"}


def nm(objs):
    out = {}
    for k in range(0, len(objs), 400):
        r = subprocess.run([os.path.join(LLVM, "llvm-nm"), "-P"] + objs[k:k + 400], capture_output=True, text=True)
        cur = None
        for line in r.stdout.splitlines():
            if line.endswith(":") and line[:-1] in objs[k:k + 400]:
                cur = line[:-1]
                out[cur] = (set(), set())
                continue
            f = line.split()
            if len(f) >= 2 and cur:
                (out[cur][1] if f[1] in "Uw" else out[cur][0]).add(f[0])
    return out


class Image:
    def __init__(self):
        import xbe
        self.x = xbe.Xbe(XBE)

    def read(self, a, n):
        o = self.x.offset(a)
        return self.x.data[o:o + n] if o is not None else b"\0" * n

    def section(self, a):
        s = self.x.section_of(a)
        return s.name if s else None


def thunk_target(img, a, depth=0):
    b = img.read(a, 5)
    if b[0] != 0xE9 or depth > 4:
        return None
    t = (a + 5 + int.from_bytes(b[1:5], "little", signed=True)) & 0xFFFFFFFF
    return thunk_target(img, t, depth + 1) or t


def func_names():
    out = {}
    p = os.path.join(ROOT, "build/functions.csv")
    if os.path.exists(p):
        for r in csv.DictReader(open(p)):
            out[int(r["address"], 16)] = (r["name"], r.get("is_thunk") == "1")
    return out


def classify(a, img):
    if is_library(a):
        return img.section(a) if not (0x11000 <= a < 0x364840) else "library .text"
    sec = img.section(a)
    return "game" if sec == ".text" else (sec or "outside")


def host_sources():
    return sorted(os.path.join(dp, f) for dp, _, fs in os.walk(os.path.join(HOST_DIR, "host")) for f in fs
                  if f.endswith(".c"))


def cmd_link(a):
    img = Image()
    names = func_names()
    rep = json.load(open(os.path.join(OUT, "compile.json")))
    objs = [os.path.join(OUT, "obj", flat(t) + ".o") for t in sorted(rep["info"])]
    syms = nm(objs)
    defined, undefined = set(), collections.Counter()
    for d, _ in syms.values():
        defined |= d
    for _, u in syms.values():
        for x in u:
            if x not in defined:
                undefined[x] += 1
    host = host_sources()
    gen = os.path.join(OUT, "glue")
    os.makedirs(gen, exist_ok=True)
    host_objs = []
    for src in host:
        o = os.path.join(gen, os.path.basename(src)[:-2] + ".o")
        r = subprocess.run([EMCC] + HOST_CFLAGS + ["-I", os.path.join(HOST_DIR, "host"), "-c", src, "-o", o],
                           capture_output=True, text=True)
        if r.returncode:
            raise SystemExit("host: %s\n%s" % (src, r.stderr[-3000:]))
        host_objs.append(o)
    host_defs = set()
    for d, _ in nm(host_objs).values():
        host_defs |= {x for x in d if re.fullmatch(r"ffg?_[0-9a-f]{8}", x)}
    gen = os.path.join(OUT, "glue")
    os.makedirs(gen, exist_ok=True)
    decl_types = {}
    for t in sorted(rep["info"]):
        for m in re.finditer(r"^declare (.*?)@(ff_[0-9a-f]{8})\((.*)\)\s*$",
                             open(os.path.join(OUT, "obj", flat(t) + ".ll"), errors="surrogateescape").read(), re.M):
            decl_types.setdefault(m.group(2), (ret_type(m.group(1)), split_top(m.group(3))))
    adj = adjustors(img)
    c = ["#include <stdint.h>", "void ff_unbound(uint32_t, const char*);",
         "void ff_dispatch(uint32_t, uint32_t, uint32_t, void*, void*);",
         "void ff_dispatch_miss(uint32_t, uint32_t, uint32_t, void*, void*);",
         "typedef void (*ffg_t)(uint32_t, uint32_t, void*, void*);"]
    stubs, thunks = {}, {}
    entries = set(x for x in defined | host_defs if re.fullmatch(r"ffg_[0-9a-f]{8}", x))
    for x in sorted(undefined):
        m = re.fullmatch(r"(ffg?)_([0-9a-f]{8})", x)
        if not m or x in host_defs or (m.group(1) == "ffg" and int(m.group(2), 16) in adj):
            continue
        ad = int(m.group(2), 16)
        t = thunk_target(img, ad)
        if m.group(1) == "ffg" and t is not None and "ffg_%08x" % t in defined | host_defs:
            c.append("void ffg_%08x(uint32_t, uint32_t, void*, void*);" % t)
            c.append("void %s(uint32_t ecx, uint32_t edx, void* st, void* rb) { ffg_%08x(ecx, edx, st, rb); }"
                     % (x, t))
            thunks[x] = t
            entries.add(x)
            continue
        nm_ = names.get(ad, (None, False))[0]
        stubs[x] = (classify(ad, img), nm_)
        label = (nm_ or "function").replace('"', "'")
        if m.group(1) == "ffg":
            c.append("void %s(uint32_t ecx, uint32_t edx, void* st, void* rb) { (void)ecx; (void)edx; (void)st; "
                     "(void)rb; ff_unbound(0x%08x, \"%s\"); }" % (x, ad, label))
            entries.add(x)
        else:
            ret, params = decl_types.get(x, ("void", []))
            ps = [C_TYPES.get(Param(p).type, "uint32_t") for p in params if p != "..."]
            c.append("%s %s(%s) { %sff_unbound(0x%08x, \"%s\"); %s}" % (
                C_TYPES.get(ret, "uint32_t"), x, (", ".join("%s a%d" % (t_, i) for i, t_ in enumerate(ps)) +
                                                  (", ..." if "..." in params else "")) or "void",
                "".join("(void)a%d; " % i for i in range(len(ps))), ad, label,
                "" if ret == "void" else "return 0; "))
    # this-adjustor thunks: the entry moves `this` and goes on to the target
    for ad, (t, n) in sorted(adj.items()):
        x = "ffg_%08x" % ad
        if x in defined | host_defs:
            continue
        stubs.pop(x, None)
        c.append("void %s(uint32_t ecx, uint32_t edx, void* st, void* rb) { ff_dispatch(0x%08x, ecx - %d, edx, st, rb); }"
                 % (x, t, n))
        thunks[x] = t
        entries.add(x)
    # jmp thunks reached only as addresses (vftable slots) get dispatch entries too
    for ad, (nm_, thunk) in sorted(names.items()):
        x = "ffg_%08x" % ad
        if not thunk or x in entries or not is_code(ad):
            continue
        t = thunk_target(img, ad)
        if t is not None and "ffg_%08x" % t in defined | host_defs:
            c.append("void ffg_%08x(uint32_t, uint32_t, void*, void*);" % t)
            c.append("void %s(uint32_t ecx, uint32_t edx, void* st, void* rb) { ffg_%08x(ecx, edx, st, rb); }"
                     % (x, t))
            thunks[x] = t
            entries.add(x)
    entries = sorted(entries)
    for x in entries:
        c.append("void %s(uint32_t, uint32_t, void*, void*);" % x)
    c.append("static const struct { uint32_t a; ffg_t f; } table[] = {")
    c += ["  {0x%s, %s}," % (x[4:], x) for x in entries]
    c.append("};")
    c.append("""ffg_t ff_lookup(uint32_t a) {
  unsigned lo = 0, hi = sizeof table / sizeof table[0];
  while (lo < hi) {
    unsigned m = (lo + hi) / 2;
    if (table[m].a < a) lo = m + 1; else hi = m;
  }
  return lo < sizeof table / sizeof table[0] && table[lo].a == a ? table[lo].f : 0;
}
extern int ff_trace_on;
void ff_trace_dispatch(uint32_t a, uint32_t ecx, void* st);
void ff_dispatch(uint32_t a, uint32_t ecx, uint32_t edx, void* st, void* rb) {
  ffg_t f = ff_lookup(a);
  if (ff_trace_on > 1) ff_trace_dispatch(a, ecx, st);
  if (f) f(ecx, edx, st, rb); else ff_dispatch_miss(a, ecx, edx, st, rb);
}""")
    glue = os.path.join(gen, "glue.c")
    open(glue, "w").write("\n".join(c) + "\n")
    rsp = os.path.join(gen, "objs.rsp")
    open(rsp, "w").write("\n".join(objs) + "\n")
    out = os.path.join(OUT, "hulk.js")
    stub_ll = os.path.join(gen, "stubs.ll")
    stub_o = stub_ll[:-3] + ".o"
    if os.path.exists(stub_o):
        os.remove(stub_o)
    r = subprocess.run([EMCC] + HOST_CFLAGS + ["-I", os.path.join(HOST_DIR, "host"), "-c", glue, "-o",
                                               glue[:-2] + ".o"], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("glue: %s" % r.stderr[-3000:])
    host_objs.append(glue[:-2] + ".o")

    def run(extra, final):
        cmd = [EMCC, "-O1", "@" + rsp] + host_objs + extra + [
            "-o", out, "-sGLOBAL_BASE=%d" % (1024 << 20), "-sINITIAL_MEMORY=%d" % (1536 << 20),
            "-sALLOW_MEMORY_GROWTH=0", "-sSTACK_SIZE=%d" % (4 << 20), "-sNODERAWFS=1", "-sEXIT_RUNTIME=1",
            "-Wl,--no-demangle", "-Wl,--error-limit=0", "--profiling-funcs", "-sASYNCIFY=1",
            "-sASYNCIFY_STACK_SIZE=65536"]
        cmd += (["-sERROR_ON_UNDEFINED_SYMBOLS=1"] if final else
                ["-sERROR_ON_UNDEFINED_SYMBOLS=0", "-Wl,--warn-unresolved-symbols"])
        return subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    r = run([], False)
    missing = set(re.findall(r"undefined symbol: (\S+)", r.stderr))
    if os.path.exists(out):
        missing |= set(re.findall(r"abort\('missing function: (.*?)'\);", open(out, errors="replace").read()))
    missing = sorted(missing)
    if missing:
        want = set(missing)
        decl = {}
        for t in sorted(rep["info"]):
            for line in open(os.path.join(OUT, "obj", flat(t) + ".ll"), errors="surrogateescape"):
                if not (line.startswith("declare ") or (line.startswith("@") and " external " in line)):
                    continue
                if line.startswith("declare "):
                    p = parse_func_line(line)
                    n = p[2] if p else None
                else:
                    n = irname(re.match(NAME, line).group(0))
                for cand in (n, (n or "")[1:] if (n or "").startswith("\x01") else None):
                    if cand in want and cand not in decl:
                        decl[cand] = (n, line.strip())
        body = ['target datalayout = "%s"' % DATALAYOUT, 'target triple = "%s"' % TRIPLE,
                "declare void @ff_unbound_name(ptr)"]
        for i, n in enumerate(missing):
            irn, d = decl.get(n, (n, None))
            body.append('@.s%d = private constant [%d x i8] c"%s\\00"' % (
                i, len(n.encode()) + 1,
                "".join(ch if ch.isalnum() or ch in "?@_$." else "\\%02X" % ord(ch) for ch in n)))
            if d and d.startswith("declare "):
                sig = parse_func_line(d)[3]
                body.append("define %s %s(%s%s) {" % (sig.ret, at(irn), ", ".join(p.type for p in sig.params),
                                                       ", ..." if sig.varargs else ""))
                body += ["  call void @ff_unbound_name(ptr @.s%d)" % i, "  unreachable", "}"]
            else:
                body.append("%s = global [64 x i8] zeroinitializer" % at(irn))
        open(stub_ll, "w").write("\n".join(body) + "\n")
        rr = subprocess.run([CLANG] + BACK + ["-x", "ir", stub_ll, "-o", stub_o], capture_output=True, text=True)
        if rr.returncode:
            raise SystemExit("stubs: " + rr.stderr[-2000:])
    r = run([stub_o] if missing else [], True)
    warn = collections.Counter()
    for line in r.stderr.splitlines():
        m = re.search(r"(function signature mismatch|undefined symbol): (\S+)", line)
        if m:
            warn[(m.group(1), m.group(2))] += 1
    link = {"rc": r.returncode, "objects": len(objs), "entries": len(entries),
            "stubs": {k: list(v) for k, v in stubs.items()}, "thunks": {k: "0x%08x" % v for k, v in thunks.items()},
            "named_undefined": missing, "warnings": [list(k) + [n] for k, n in warn.items()],
            "stderr": r.stderr[-6000:] if r.returncode else ""}
    json.dump(link, open(os.path.join(OUT, "link.json"), "w"), indent=1)
    print("link rc %d: %d objects, %d generic entries, %d thunks, %d unbound entries, %d named stubs, %d warnings" % (
        r.returncode, len(objs), len(entries), len(thunks), len(stubs), len(missing), len(warn)))
    if r.returncode:
        print(r.stderr[-3000:])
    cmd_report(a)


def cmd_report(a):
    link = json.load(open(os.path.join(OUT, "link.json")))
    by = collections.Counter(v[0] for v in link["stubs"].values())
    print("unbound entries by place (the host's work list): %d" % len(link["stubs"]), dict(by.most_common()))
    for kind, _ in by.most_common():
        ns = sorted({(v[1] or "?") for v in link["stubs"].values() if v[0] == kind})
        print("  %s (%d): %s" % (kind, len(ns), ", ".join(ns[:30]) + (" ..." if len(ns) > 30 else "")))
    print("named undefined: %d" % len(link["named_undefined"]), ", ".join(link["named_undefined"][:40]))
    for w in link["warnings"][:20]:
        print("  warning:", *w)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("compile")
    c.add_argument("--only", nargs="*")
    c.add_argument("--jobs", type=int, default=2)
    sp.add_parser("link")
    sp.add_parser("report")
    a = ap.parse_args(argv)
    {"compile": cmd_compile, "link": cmd_link, "report": cmd_report}[a.cmd](a)


if __name__ == "__main__":
    main()
