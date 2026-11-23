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
    `ff_dispatch(addr, ...)`, a hash table of the generic entries.
"""
import argparse
import collections
import concurrent.futures
import csv
import hashlib
import json
import os
import re
import shutil
import struct
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

# The game's code is optimised by default (wasm14, D218: -O1 gives play3 checkpoint records byte-identical to -O0's
# over all 60,000 frames); HULK_WASM_OPT=O0 builds it as clang -O0 emits it (every function optnone). With O1 the
# front end runs as -O1
# without LLVM's passes (no optnone; the IR keeps -O0's shape for bind_tu), the back end optimises. As the Wine
# build's opt1 (tools/clang_probe.py): decompiled code's undefined behaviour stays as -O0 has it where a switch exists
# (falling off a value-returning function, loops without side effects, library calls). The four TUs the Wine build
# keeps at -O0 (tools/wine_opt_exclude.txt) are optimised here (wasm14: play3's records stay byte-identical);
# HULK_WASM_OPT_EXCLUDE=FILE names TUs to keep at -O0.
O0_FRONT = ["-O0"]
OPT_FRONT = (O0_FRONT if os.environ.get("HULK_WASM_OPT", "O1") == "O0" else
             ["-O1", "-Xclang", "-disable-llvm-passes", "-fno-strict-return", "-fno-finite-loops", "-fno-builtin"])
OPT_EXCLUDE = os.environ.get("HULK_WASM_OPT_EXCLUDE") or ""

# the Wine build's `msvc` configuration (tools/clang_probe.py CONFIGS["msvc"], SSE float), as IR
DIALECT = ["-Xclang", "-fno-wchar", "-fno-operator-names", "-Wno-c++11-narrowing", "-Wno-address-of-temporary"]
FRONT_ = (["--target=i686-pc-windows-msvc", "-fms-extensions", "-fms-compatibility", "-fms-compatibility-version=13.10",
          "-std=c++14", "@OPT@", "-S", "-emit-llvm", "-include", "compat/native.h", "-fno-strict-aliasing", "-fwrapv",
          "-fno-delete-null-pointer-checks"] + DIALECT
         + ["-msse2", "-mfpmath=sse", "-ffp-eval-method=double", "-ffp-contract=off", "-fcheck-new", "-fno-exceptions",
            "-w", "-DHULK_WASM=1"]
         # (wasm14) every local starts as zeros: decompiled code that reads or copies an uninitialised local (stack
         # garbage on the Xbox) gets the same bytes at -O0 (locals in the shadow stack, whose garbage moves with
         # every frame's size) and -O1 (wasm locals). A deliberate difference from the console; HULK_WASM_ZEROINIT=0
         # leaves locals uninitialised (docs/wasm-port.md "Status", 2026-11-22)
         + (["-ftrivial-auto-var-init=zero"] if os.environ.get("HULK_WASM_ZEROINIT", "1") != "0" else []))
_EXCL = None


def front_flags(rel):
    """FRONT for snapshot TU rel: optimised unless OPT_EXCLUDE names it."""
    global _EXCL
    if _EXCL is None:
        _EXCL = set(l.strip() for l in open(OPT_EXCLUDE) if l.strip() and not l.startswith("#")) \
            if os.path.exists(OPT_EXCLUDE) else set()
    opt = O0_FRONT if rel in _EXCL else OPT_FRONT
    i = FRONT_.index("@OPT@")
    return FRONT_[:i] + opt + FRONT_[i + 1:]
BACK = ["--target=wasm32-unknown-emscripten", "-O1", "-c", "-Wno-override-module"]
HOST_CFLAGS = ["-O1", "-Wall", "-Wextra", "-Werror"]
# host C++ (replay.cpp: the SDL layer's replay reader and checkpoint probe, compiled for the wasm host)
HOST_CXXFLAGS = ["-O1", "-std=c++17", "-fno-exceptions", "-fno-rtti", "-Wall", "-Wextra", "-Werror", "-Wno-unused-function",
                 "-Wno-missing-field-initializers"]
VERSION = "wasm14-1"          # bump when bind_tu() changes (object cache key)
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


# the return types a HULK_PORT_ABI function returns in place of the 32-bit builds' void (MS mangling: int, unsigned,
# void*, bool, char, unsigned char)
RET_CODES = ("H", "I", "PAX", "_N", "D", "E")


def port_abi_names(sym):
    """SYM (MS-mangled, with a void result: `X` after the calling convention) with that result spelled as each of
    RET_CODES: the names a HULK_PORT_ABI function or a caller's declaration of it has on the port builds."""
    out = []
    if "@@" not in sym:
        return out
    for k in range(sym.index("@@") + 2, len(sym)):
        if sym[k] == "X" and sym[k - 1] in "EAGIZ@":
            out = [sym[:k] + r + sym[k + 1:] for r in RET_CODES]
            break
    return out


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
        # HULK_PORT_ABI: a name the map has with a void result (`X`) also binds with the port builds' result there
        # (a caller's declaration of a function that returns what x86 left in eax, tu_mains)
        for n, v in m["bindings"].items():
            if v.get("addr"):
                for w in port_abi_names(n):
                    for s in coff_names(w):
                        _BASE.setdefault(s, int(v["addr"], 16))
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


_TDS = None


def game_type_descriptors():
    """{decorated name (`?AVX@ns@@`): address} of the original's RTTI type descriptors: type_info's vftable word, a
    null spare, the name."""
    global _TDS
    if _TDS is None:
        _TDS = {}
        x = Image().x
        # type_info's vftable: the word most of the `.?A` names follow (after a null spare)
        words = collections.Counter(x.data[i - 4:i] for i in (m.start() for m in re.finditer(rb"\0\0\0\0\.\?A[UV]", x.data))
                                    if i >= 4)
        vft = words.most_common(1)[0][0] if words else None
        if vft:
            key = vft + b"\0\0\0\0.?A"
            for m in re.finditer(re.escape(key) + rb"([\w@?$]+)\0", x.data):
                for sec in x.sections:
                    if sec.raw <= m.start() < sec.raw + sec.rsize:
                        _TDS["?A" + m.group(1).decode("latin1")] = sec.va + m.start() - sec.raw
    return _TDS


def game_td_for(name):
    """The game's type descriptor for clang's `??_R0?AV...@8` (wine_link's native9/native12 rules: the tree's
    `fn_<hex>` wrapper namespaces left out, then an `_<hex>` address suffix, then a unique class leaf name), or None:
    __RTDynamicCast and typeid compare descriptors, and the objects' vftables are the game's."""
    if not (name.startswith("??_R0?A") and name.endswith("@8")):
        return None
    tds = game_type_descriptors()
    d = name[5:-2]
    g = re.sub(r"fn_[0-9a-f]{8}@", "", d)
    if g in tds:
        return tds[g]
    g2 = re.sub(r"_[0-9a-f]{5,6}@", "@", g)
    if g2 in tds:
        return tds[g2]
    m = re.match(r"\?A[UV](\w+?)(?:_[0-9a-f]{5,6})?@", d)
    if not m:
        return None
    cands = [a for t, a in tds.items() if re.match(r"\?A[UV]" + re.escape(m.group(1)) + "@", t)]
    return cands[0] if len(cands) == 1 else None


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
                        + " ".join(front_flags(rel)).encode()).hexdigest()[:20]


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
        cmd = [CLANG] + front_flags(rel) + ["-I" + os.path.join(SNAP, "include"), "-I" + os.path.join(SNAP, "repo-include"),
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


def fix_param_block(ir):
    """A function that takes the address of a parameter's copy and reads past it walks its stack arguments x86-style
    (Render::Object::vfunc_6 0x1c4e00: `memcpy(this + 0x30, &a0, 0x40)` copies its sixteen int parameters). On x86 the
    arguments are one block; on wasm each parameter's copy is its own local, which -O0 happens to lay out in a row
    and -O1 does not. When a parameter copy's address escapes (it is used other than by a load or a store to it),
    every stack parameter's copy becomes a slot of one block in x86 layout (4-byte slots, 8 for i64/double; the
    this-pointer of a thiscall and fastcall's register parameters are not on the stack)."""
    lines = ir.split("\n")
    out, k = [], 0
    while k < len(lines):
        l = lines[k]
        if not (l.startswith("define ") and ", ...)" not in l):
            out.append(l)
            k += 1
            continue
        end = k
        while lines[end] != "}":
            end += 1
        body = lines[k + 1:end]
        p = parse_func_line(l)
        new = None
        if p and p[3].params and p[3].cc != "x86_fastcallcc" and all(q.name for q in p[3].params):
            params = p[3].params[1:] if p[3].cc == "x86_thiscallcc" else p[3].params
            ok = all(not q.byval and not q.sret and not q.inreg and
                     q.type in ("i8", "i16", "i32", "i64", "ptr", "float", "double") for q in params)
            slots = {}
            for b in body:
                m = re.match(r"\s*store (\S+) (%[-\w.]+), ptr (%[-\w.]+),", b)
                if m and m.group(2) in [q.name for q in params] and m.group(2) not in slots.values():
                    slots[m.group(3)] = m.group(2)
            if ok and len(slots) == len(params) and len(params) > 1:
                esc = False
                for b in body:
                    for s in slots:
                        if not re.search(r"%s(?![-\w.])" % re.escape(s), b):
                            continue
                        if re.match(r"\s*%s = alloca " % re.escape(s), b) or \
                                re.match(r"\s*store [^,]+, ptr %s," % re.escape(s), b) or \
                                re.match(r"\s*%%[-\w.]+ = load [^,]+, ptr %s," % re.escape(s), b):
                            continue
                        esc = True
                if esc:
                    off, offs = 0, {}
                    for q in params:
                        offs[q.name] = off
                        off += 8 if q.type in ("i64", "double") else 4
                    new = ["  %%ffpb = alloca [%d x i8], align 8" % off]
                    for b in body:
                        m = re.match(r"\s*(%[-\w.]+) = alloca ", b)
                        if m and m.group(1) in slots:
                            b = "  %s = getelementptr inbounds i8, ptr %%ffpb, i32 %d" % (m.group(1), offs[slots[m.group(1)]])
                        new.append(b)
        if new is None:
            out += lines[k:end + 1]
        else:
            out += [l] + new + ["}"]
        k = end + 1
    return "\n".join(out)


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
    ir = fix_param_block(fix_va_frames(strip_inalloca(ir)))
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
    name with a float result spelled double (hulk_freg: `M` -> `N`); else with a void result spelled int or
    void* (HULK_PORT_ABI: `X` -> `H` / `I` / `PAX` / `_N` / `D` / `E`); else the block's tree name (undecorated)."""
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
        if hit is None:
            # HULK_PORT_ABI (include/compat/ptr.h): a void the 32-bit builds keep returns what x86 left in eax here
            # (hulk_eaxptr, a TU's own typedef): the binding map is the Wine build's, whose name says void (`X`); the one
            # definition whose name has another return type in that place
            for k in range(len(sym)):
                if sym[k] == "X" and "@@" in sym[:k] and sym[k - 1] in "EAGIZ@":
                    head, tail = sym[:k], sym[k + 1:]
                    c = [d for d in defs if d not in out and len(d) > len(sym) - 1 and d.startswith(head)
                         and d.endswith(tail) and d[k:len(d) - len(tail)] in RET_CODES]
                    if len(c) == 1:
                        hit = c[0]
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


# A member-function-pointer forwarder (CallbackHolder<T>, CallbackHolderInt<T>, CallbackHolderFloat<T>::vfunc_0, 8 bytes:
# `mov eax, ecx; mov ecx, [eax+4]; jmp [eax+8]`) passes the caller's stack arguments on to (object->*fn) untouched; its
# source (`(mObject->*fn)()`) is one stand-in for the three, so the int and float holders lose their argument (the
# front end's camera-invert selectors set both flags: play3's camera at frame 541). The link writes their entries
# from the XBE's bytes instead: `this` becomes [this+4] and the call goes on to [this+8] with the caller's arguments
# (wasm6).
FORWARDER = bytes.fromhex("8bc18b4804ff6008")
_FORWARDERS = None


def forwarders():
    """{addr} of the blocks whose code is a member-function-pointer forwarder (FORWARDER), from the XBE's bytes."""
    global _FORWARDERS
    if _FORWARDERS is None:
        img = Image()
        _FORWARDERS = {a for a in block_syms() if img.read(a, 8) == FORWARDER}
    return _FORWARDERS


# ---------------------------------------------------------------------------------------------- devirtualized calls
# A direct call clang made to a virtual method cl 7.1 calls through the vftable: clang devirtualizes a call on an
# object whose type it knows (a member object, `drive->b.v0()`), cl doesn't, and the object's real class is one the
# source doesn't show (a stand-in record). Such a callee is a virtual method (MS mangling: E/F private, M/N protected,
# U/V public) the TU doesn't define and nothing binds (a direct call cl made is a relocation the map binds). Clang
# itself says how the virtual call goes: a probe compiled with the TU, `p->m(args)`, and the call goes there
# (fusion-frenzy-decomp's wasm port).
VIRTUAL = re.compile(r'^\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)+)@[EFMNUV]')
VPROBE = re.compile(r'(?:public|protected|private): virtual (.*?)__thiscall ((?:\w+::)*\w+)::(\w+)\((.*)\)( const)?$')


def split_top_args(s):
    """'float, struct Vec *, int (__cdecl *)(int, int)' -> its top-level comma-separated parts."""
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
    return out + [cur.strip()] if cur.strip() else out


def _probe_front(tu, probes, key):
    """IR path of TU compiled with PROBES appended (cached), or None when it doesn't compile."""
    d = os.path.join(OUT, "devirt")
    os.makedirs(d, exist_ok=True)
    ll = os.path.join(d, "%s.%s.ll" % (flat(tu)[-80:], key))
    if os.path.exists(ll):
        return ll
    if os.path.exists(ll + ".fail"):
        return None
    cpp = ll[:-3] + ".cpp"
    # (the TU by #include keeps its own directory's includes)
    open(cpp, "w").write('#include "%s"\n// wasm_port: devirtualized calls made virtual again\n%s\n'
                         % (os.path.join(SNAP, tu), "\n".join(probes)))
    cmd = [CLANG] + front_flags(tu) + ["-I" + os.path.join(SNAP, "include"), "-I" + os.path.join(SNAP, "repo-include"),
                             cpp, "-o", ll + ".tmp"]
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    if r.returncode:
        open(ll + ".fail", "w").write(r.stderr[-4000:])
        return None
    os.replace(ll + ".tmp", ll)
    return ll


def devirt(ir, tu, notes=None):
    """IR of TU with clang's devirtualized calls (see VIRTUAL) made virtual again, through probes."""
    defined = set(irname(t) for t in re.findall(r'^define [^@\n]*(' + NAME + r')\(', ir, re.M))
    called = set(irname(t) for t in re.findall(r'\bcall [^@%\n]*(' + NAME + r')\(', ir))
    bound = tu_bindings(tu)
    hints = set(re.findall(r"^// equiv-map: (\S+) = 0x", open(os.path.join(SNAP, tu), errors="replace").read(), re.M))
    cand = sorted(n for n in called if VIRTUAL.match(n) and n not in defined and n not in bound and n not in hints
                  and unwrap(n) not in hints and name_address(n) is None)
    if not cand:
        return ir
    tag = hashlib.sha1(tu.encode()).hexdigest()[:8]
    probes = {}
    for k, (n, d) in enumerate(sorted(undname(set(cand)).items())):
        m = VPROBE.search(d)
        if not m or "`" in d:
            if notes is not None:
                notes["devirt: not probed (name)"] += 1
            continue
        ret, cls, meth, args, const = m.group(1).strip(), m.group(2), m.group(3), m.group(4), m.group(5)
        params = [] if args in ("", "void") else split_top_args(args)
        if "..." in params:
            continue
        sig = ", ".join(["%s%s* p" % (cls, " const" if const else "")] +
                        ["%s a%d" % (t, i) for i, t in enumerate(params)])
        call = "p->%s(%s)" % (meth, ", ".join("a%d" % i for i in range(len(params))))
        pr = "__ff_vprobe_%s_%d" % (tag, k)
        probes[n] = (pr, 'extern "C" %s %s(%s) { %s%s; }' % (ret, pr, sig, "" if ret == "void" else "return ", call))
    if not probes:
        return ir
    base = tu_key(tu)

    def key(ps):
        return hashlib.sha1((base + "\n".join(ps)).encode()).hexdigest()[:16]
    texts = ["// probes"] + [p for _, p in probes.values()]
    ll = _probe_front(tu, texts, key(texts))
    if ll is None:                      # find the probes that compile on their own
        ok = {n: v for n, v in probes.items()
              if _probe_front(tu, texts[:1] + [v[1]], key(texts[:1] + [v[1]])) is not None}
        if notes is not None:
            notes["devirt: probe failed"] += len(probes) - len(ok)
        probes = ok
        texts = texts[:1] + [p for _, p in probes.values()]
        ll = _probe_front(tu, texts, key(texts)) if probes else None
        if ll is None:
            return ir
    out = open(ll, errors="surrogateescape").read()
    for n, (pr, _) in probes.items():
        # an sret return puts the hidden pointer first for a free function and after `this` for a method
        if re.search(r'^define [^\n]*@%s\([^)\n]*sret' % re.escape(pr), out, re.M):
            if notes is not None:
                notes["devirt: sret not probed"] += 1
            continue
        out = re.sub(r'(\bcall )(?:x86_thiscallcc )?([^@%%\n]*)%s\(' % re.escape(at(n)),
                     lambda m, pr=pr: m.group(1) + m.group(2) + "@" + pr + "(", out)
        if notes is not None:
            notes["devirt: calls made virtual"] += 1
    return out


def fpfix(ir, notes=None):
    """The 64-bit builds' float passes (tools/native_float.py, docs/native-float64.md) on a TU's i686 IR: castfix
    (`(float)i` inside an expression is not rounded), fpcvt (float -> integer conversions with the Wine build's
    results; wasm's saturating truncations differ out of range) and x87ext (a math-shim result consumed by the next
    arithmetic, fptrunc or fcmp keeps its 80-bit value; the shims are softx87's, host/x87.cpp). retfix64 is not
    needed for the packers (they carry st(0) as a double) but is for direct calls: a `float` call of a `hulk_freg`
    definition is read as the double, as the Wine build's retfix does (wasm7: the collision solver's impulses at
    play3 frame 450 differed by an ULP, the props' sleep at 751). HULK_WASM_FPFIX=0 turns them off (wasm6)."""
    if os.environ.get("HULK_WASM_FPFIX", "1") == "0":
        return ir
    import native_float
    ir, a = native_float.castfix_ir(ir)
    ir, b = native_float.fpcvt_ir(ir)
    ir, c = native_float.x87ext_ir(ir)
    ir, d = native_float.retfix64_ir(ir)
    if notes is not None:
        notes["fpfix: castfix"] += a
        notes["fpfix: fpcvt"] += b
        notes["fpfix: x87ext calls"] += c["shim calls"]
        notes["fpfix: x87ext consumers"] += c["consumers"]
        notes["fpfix: retfix64 definitions"] += d["float definitions"]
        notes["fpfix: retfix64 calls"] += d["float calls"]
    return ir


def load_tu(tu, addrs, notes=None):
    """(prepared IR, mains, same) of a TU; a block that is a scalar deleting destructor clang didn't emit (it emits
    one only with its vftable) gets one in IR (wasm_ir.deleting_dtor)."""
    ir = prepare(fpfix(devirt(open(front(tu), errors="surrogateescape").read(), tu, notes), notes))
    m = binding_map()["definitions"]
    pins = block_syms()
    # (an adjustor thunk's block is a stand-in that makes cl emit the thunk; the link writes its entry: adjustors())
    fw = forwarders()
    defmap = {a: pins.get(a) or m.get("0x%08x" % a) for a in addrs
              if (pins.get(a) or "0x%08x" % a in m) and not ADJUSTOR.search(pins.get(a) or "") and a not in fw}
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


# The replay hooks (src/platform/sdl/host/native_hooks.h, the native link's table; D192): placed here by renaming, never
# by editing a replay-pin function's source. Each hook is a host function with a generic entry's shape,
# `void ffh_<hook>(ecx, edx, stack, ret)` (src/platform/wasm/host/replay.cpp), so a caller's declaration need not match
# its C type:
#   entry  the definition at ADDR becomes `ffo_<addr>` (its generic entry `ffgo_<addr>`, which the hook calls) and
#          `ff_<addr>` a packer calling the hook: every call, direct, packed or through ff_dispatch, reaches the hook;
#   site   in the block at ADDR, calls of the function at OTHER call the hook instead (through a packer);
#   data   in the block at ADDR, the data item at OTHER is the host's variable named HOOK.
# `layout` and `gfx` rows are the native builds' own; WASM_HOOK_SKIP leaves out rows the wasm host has no hook for yet.
NATIVE_HOOKS_H = os.path.join(ROOT, "src/platform/sdl/host/native_hooks.h")
WASM_HOOK_SKIP = {"hulk_nhook_save_selftest", "hulk_cast_self"}
# HULK_WASM_GFX=1: the app's module (docs/wasm-port.md "The macOS app"): the pddi front end (tools/wasm_gfx.py) and
# src/platform/wasm/gfx/ are linked, d3dCreateDevice asks the host which device to make (src/platform/wasm/gfx/gfx.c),
# and the native hooks' `gfx` rows apply (taking the same switch there)
GFX = os.environ.get("HULK_WASM_GFX") == "1"
GFX_DEVICE_ADDR = 0x0031ba60        # d3dCreateDevice (pure3d::InitPlatform 0x00292560, its only caller)
# the options menus' frame-rate item (src/platform/wasm/gfx/fe_options.c, D224): the front end's lookup of an int
# callback by name and NamedValueInt's Create, so the injected "PortFrameRate" value reaches the host; the camera
# selectors' sync (front-end set-up and the pause menu), which shows the setting on the item too
# World::Render, whose room fade constants the draw-distance setting sets while it runs (src/platform/wasm/gfx/
# draw_distance.c, wvid1)
GFX_APP_HOOKS = {0x000df9e0: "ffh_hulk_app_fe_callback", 0x000f8e70: "ffh_hulk_app_named_int",
                 0x000b5ad0: "ffh_hulk_app_fe_sync", 0x001c88f0: "ffh_hulk_app_world_render"}
_HOOKS = None


def wasm_hooks():
    """(entry {addr: hook}, site {(caller, callee): hook}, data {(caller, item): variable})"""
    global _HOOKS
    if _HOOKS is None:
        ent, site, data = {}, {}, {}
        for m in re.finditer(r"H\((entry|site|data), (0x[0-9a-fA-F]+), (0x[0-9a-fA-F]+|0), (\w+), (\w+),",
                             open(NATIVE_HOOKS_H).read()):
            kind, a, o, hook, status = m.group(1), int(m.group(2), 16), int(m.group(3), 16), m.group(4), m.group(5)
            if (hook in WASM_HOOK_SKIP or status == "gfx") and not (GFX and status == "gfx"):
                continue
            if kind == "entry":
                ent[a] = "ffh_" + hook
            elif kind == "site":
                site[(a, o)] = "ffh_" + hook
            else:
                data[(a, o)] = hook
        if GFX:
            ent[GFX_DEVICE_ADDR] = "ffh_hulk_gfx_create_device"
            ent.update(GFX_APP_HOOKS)
        # debugging: HULK_WASM_DEBUG_HOOKS="site:0xCALLER:0xCALLEE:name,entry:0xADDR:0:name" (hooks the host sources
        # of HULK_WASM_HOST_EXTRA define as ffh_<name>; never in a committed build)
        for row in filter(None, os.environ.get("HULK_WASM_DEBUG_HOOKS", "").split(",")):
            kind, a, o, hook = row.split(":")
            if kind == "entry":
                ent[int(a, 16)] = "ffh_" + hook
            else:
                site[(int(a, 16), int(o, 16))] = "ffh_" + hook
        _HOOKS = (ent, site, data)
    return _HOOKS


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
    for g in gdefs:                     # clang's RTTI type descriptors: the game's
        if g.startswith("??_R0?A") and g not in bound:
            a = game_td_for(g)
            if a is not None:
                bound[g] = a
                notes["RTTI type descriptor bound to the game's"] += 1
    for n in list(decls) + [g for g in gdefs if re.search(r" = (?:\w+ )*external ", lines[gdefs[g]])]:
        if n not in bound and not n.startswith("llvm."):
            a = name_address(n)
            if a is not None and (n in decls) == is_code(a):
                bound[n] = a
                notes["bound by name"] += 1
    extra = []
    packers = {}

    # debugging: HULK_WASM_DEBUG_VOIDRET=1 makes each indirect call with an integer result that reaches a block leaving
    # the result untouched (a void block) call the host's ff_dbg_voidret(target, TU index) (a source dropping a result
    # its callers read, the HULK_PORT_ABI class; host extra build/<agent>/dbg/voidret.c; never in a committed build)
    voidret = tu_index if os.environ.get("HULK_WASM_DEBUG_VOIDRET") else None

    def need_packer(sig, target, indirect=False):
        key = (sig.key(types), target, indirect)
        if key not in packers:
            name = "ffp.%d" % len(packers)
            packers[key] = name
            extra.extend(packer(name, sig, target, types, indirect, voidret=voidret))
        return packers[key]

    sigs = {n: p[3] for n, (_, p) in list(defs.items()) + list(decls.items())}
    redirect = {}
    hk_ent, hk_site, hk_data = wasm_hooks()
    cur = [None]                        # the block whose body is being rewritten (its address)

    def canonical(name):
        """A local (inline) definition the game has at an address with a tree definition: call that one."""
        a = bound.get(name)
        return a is not None and a in game and name not in mains

    def callee_for(name, sig):
        if name in mains:
            # (a replay entry hook leaves the defining TU's own direct calls alone, as the native link's)
            return ("ffo_%08x" if mains[name] in hk_ent else "ff_%08x") % mains[name]
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
                if a in hk_ent and a in mains.values():
                    return "ffo_%08x" % a       # (the defining TU's own calls: not hooked)
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
        hk = hk_site.get((cur[0], bound.get(name, mains.get(name))))
        if hk and sigs.get(name) is not None:
            notes["replay hook site"] += 1
            return at(need_packer(sigs[name], hk)) + "("
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
    hook_vars = set()
    for l in lines:
        if l.startswith("define "):
            p_ = parse_func_line(l)
            cur[0] = mains.get(p_[2]) if p_ else None
        elif l == "}":
            cur[0] = None
        elif cur[0] is not None and any(ca == cur[0] for ca, _ in hk_data):
            def data_hook(m):
                var = hk_data.get((cur[0], bound.get(irname(m.group(0)))))
                if var is None:
                    return m.group(0)
                hook_vars.add(var)
                notes["replay hook data"] += 1
                return at(var)
            l = TOKEN.sub(data_hook, l)
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
                l = l.replace(at(name) + "(", at(("ffo_%08x" if mains[name] in hk_ent else "ff_%08x")
                                                 % mains[name]) + "(", 1)
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
        if a in hk_ent:                 # a replay entry hook: ff_<addr> calls the hook, ffgo_<addr> the definition
            notes["replay hook entry"] += 1
            wrap = packer("ff_%08x" % a, sigs[name], hk_ent[a], types)
            lines += [wrap[0].replace("define internal ", "define ", 1)] + wrap[1:]
            lines += entry("ffgo_%08x" % a, sigs[name], "ffo_%08x" % a, types)
            lines.append("declare void %s(i32, i32, ptr, ptr)" % at(hk_ent[a]))
    for var in sorted(hook_vars):
        lines.append("%s = external global i32" % at(var))
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
        if voidret is not None:
            lines.append("declare void @ff_dbg_voidret(i32, i32)")
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


# The tree's own mutable globals (wroll1, D227): a TU's statics with no XBE address (function-local statics and their
# guards, stand-in globals such as pure3d's globalTextBible or the XboxDrive object) are module data above 1 GB, not
# image or arena memory, yet they are game state: a restore that leaves them (sched.c HULK_ROLLTEST) re-simulates a
# different game (an atexit registration made twice across PRESSSTART -> GAME). They go to one data section, which
# sched.c snapshots with the image and the arena (__start_/__stop_hulk_game_state). Left out: RTTI type descriptors
# (??_R0: type_info's spare word caches a name the C library allocates; never game state). The section is hashed
# apart from the game hash (frame.c ff_module_hash): its words include pointers into module data (vftables), whose
# values change with the build.
GAME_STATE_SECTION = "hulk_game_state"
_GLOBAL_DEF = re.compile(r'^(@\S+|@"[^"]*") = (?:internal |dso_local )+global ')


def game_state_section(text):
    out, n = [], 0
    for line in text.split("\n"):
        if line.startswith("@") and _GLOBAL_DEF.match(line) and ", section " not in line and "??_R0" not in line:
            if ", comdat" in line:
                line = line.replace(", comdat", ', section "%s", comdat' % GAME_STATE_SECTION, 1)
            else:
                line, k = re.subn(r", align (\d+)$", r', section "%s", align \1' % GAME_STATE_SECTION, line)
                if not k:
                    line += ', section "%s"' % GAME_STATE_SECTION
            n += 1
        out.append(line)
    return "\n".join(out), n


def compile_tu(job):
    tu, tu_index, addrs = job
    game, defsig, deftys = _G["game"], _G["defsig"], _G["deftys"]
    try:
        dv = collections.Counter()
        ir, mains, same = load_tu(tu, addrs, dv)
        text, info = bind_tu(ir, tu, tu_index, mains, same, tu_bindings(tu), game, defsig, deftys)
        text, info["state_globals"] = game_state_section(text)
        d = os.path.join(OUT, "obj")
        os.makedirs(d, exist_ok=True)
        wl = os.path.join(d, flat(tu) + ".ll")
        open(wl, "w", errors="surrogateescape").write(text)
        r = subprocess.run([CLANG] + BACK + ["-x", "ir", wl, "-o", wl[:-3] + ".o"], capture_output=True, text=True,
                           errors="replace")
        if r.returncode:
            return tu, None, "back: " + "\n".join(x for x in r.stderr.splitlines() if "error" in x)[:800]
        info["notes"].update(dv)
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


def _va_of(x, off):
    for sec in x.sections:
        if sec.raw <= off < sec.raw + sec.rsize:
            return sec.va + off - sec.raw
    return None


SIZED_FREE = {"??3@YAXPAXI@Z": "??3@YAXPAX@Z", "??_V@YAXPAXI@Z": "??_V@YAXPAX@Z"}
DTOR = re.compile(r"\?\?1((?:[A-Za-z_]\w*@)+)@[UQ]AE@XZ$")


def destructor_entries(img, names):
    """{`??1X` name: the address of X's deleting destructor} for destructors nothing defines (implicit destructors of
    the tree's stand-in classes, which clang calls by name): the class is the RTTI class of that name (the tree's
    `fn_<hex>` wrapper namespaces left out), its vftable the one whose locator names it at offset 0, and the deleting
    destructor the slot whose code tests `flags & 1` (`test byte ptr [esp+8], 1`). Called with flags 0 it is exactly
    `X::~X()`: the original's own destructor, no free."""
    x = img.x
    want = {}
    for n in names:
        m = DTOR.match(n)
        if m:
            parts = [q for q in m.group(1).split("@") if q and not re.fullmatch(r"fn_[0-9a-f]{8}", q)]
            want[n] = ".?AV" + "@".join(parts) + "@@"
    out = {}
    for n, td_name in want.items():
        hits = [i for i in re.finditer(re.escape(td_name.encode()) + b"\0", x.data)]
        if len(hits) != 1:
            continue
        td = _va_of(x, hits[0].start() - 8)
        if td is None:
            continue
        vft = None
        for c in re.finditer(re.escape(struct.pack("<I", td)), x.data):
            col = _va_of(x, c.start() - 12)       # the locator: {signature, offset, cd offset, type, hierarchy}
            if col is None or x.u32(col) != 0 or x.u32(col + 4) != 0:
                continue
            refs = [r for r in re.finditer(re.escape(struct.pack("<I", col)), x.data)]
            vfts = [_va_of(x, r.start() + 4) for r in refs if r.start() % 4 == 0]
            vfts = [v for v in vfts if v is not None]
            if len(vfts) == 1:
                vft = vfts[0]
                break
        if vft is None:
            continue
        for k in range(64):
            f = x.u32(vft + 4 * k)
            if f is None or not is_code(f):
                break
            code = img.read(f, 64)
            if b"\xf6\x44\x24\x08\x01" in code and code.find(b"\xc2\x04\x00") > 0:
                out[n] = f
                break
    return out


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
    gfx = sorted(os.path.join(HOST_DIR, "gfx", f) for f in os.listdir(os.path.join(HOST_DIR, "gfx"))
                 if f.endswith((".c", ".cpp"))) if GFX else []
    return [x for x in os.environ.get("HULK_WASM_HOST_EXTRA", "").split(",") if x] + gfx + sorted(os.path.join(dp, f) for dp, _, fs in os.walk(os.path.join(HOST_DIR, "host")) for f in fs
                  if f.endswith((".c", ".cpp")))


def _wasm_opt():
    """Binaryen's wasm-opt: HULK_WASM_OPT_BIN, Emscripten's own (Homebrew: libexec/binaryen), or on PATH."""
    if os.environ.get("HULK_WASM_OPT_BIN"):
        return os.environ["HULK_WASM_OPT_BIN"]
    e = os.path.realpath(shutil.which(EMCC) or EMCC)
    for d in (os.path.dirname(e), os.path.dirname(os.path.dirname(e))):
        for sub in ("binaryen/bin/wasm-opt", "libexec/binaryen/bin/wasm-opt"):
            if os.path.exists(os.path.join(d, sub)):
                return os.path.join(d, sub)
    return shutil.which("wasm-opt") or "wasm-opt"


WASM_OPT = _wasm_opt()
WASM_FEATURES = ["--enable-bulk-memory", "--enable-sign-ext", "--enable-mutable-globals",
                 "--enable-nontrapping-float-to-int", "--enable-multivalue", "--enable-reference-types"]


def _leb(b, i):
    v = sh = 0
    while True:
        x = b[i]
        i += 1
        v |= (x & 0x7f) << sh
        sh += 7
        if x < 0x80:
            return v, i


def wasm_imports(path):
    """[(module, name, kind)] of a wasm module's import section."""
    b = open(path, "rb").read()
    i, out = 8, []
    while i < len(b):
        sid = b[i]
        size, i = _leb(b, i + 1)
        if sid == 2:
            j = i
            n, j = _leb(b, j)
            for _ in range(n):
                ln, j = _leb(b, j)
                mod = b[j:j + ln].decode()
                j += ln
                ln, j = _leb(b, j)
                name = b[j:j + ln].decode()
                j += ln
                kind = b[j]
                j += 1
                if kind == 0:
                    _, j = _leb(b, j)
                elif kind == 1:
                    j += 1
                    flags, j = _leb(b, j)
                    _, j = _leb(b, j)
                    if flags & 1:
                        _, j = _leb(b, j)
                elif kind == 2:
                    flags, j = _leb(b, j)
                    _, j = _leb(b, j)
                    if flags & 1:
                        _, j = _leb(b, j)
                elif kind == 3:
                    j += 2
                else:
                    raise ValueError("import kind %d" % kind)
                out.append((mod, name, kind))
            return out
        i += size
    return out


def asyncify(raw, out):
    """Binaryen's Asyncify on the linked module, driven from C (src/platform/wasm/host/sched.c): the driver loop is
    not instrumented, no import unwinds (the asyncify.* imports are the pass's own functions)."""
    return subprocess.run([WASM_OPT, raw, "-o", out, "-g", "--asyncify",
                           "--pass-arg=asyncify-removelist@ff_sched_loop",
                           "--pass-arg=asyncify-imports@hulk.none", "-O1"] + WASM_FEATURES,
                          capture_output=True, text=True, errors="replace",
                          env=dict(os.environ, BINARYEN_CORES=os.environ.get("BINARYEN_CORES", "2")))


def cmd_link(a):
    img = Image()
    names = func_names()
    rep = json.load(open(os.path.join(OUT, "compile.json")))
    objs = [os.path.join(OUT, "obj", flat(t) + ".o") for t in sorted(rep["info"])]
    if GFX:
        import wasm_gfx
        objs += wasm_gfx.objects()
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
        o = os.path.join(gen, os.path.splitext(os.path.basename(src))[0] + ".o")
        flags = HOST_CXXFLAGS if src.endswith(".cpp") else HOST_CFLAGS
        r = subprocess.run([EMCC] + flags + ["-I", os.path.join(HOST_DIR, "host"), "-I",
                                             os.path.join(HOST_DIR, "host", "shim"), "-I",
                                             os.path.join(ROOT, "src/platform/sdl"), "-c", src, "-o", o],
                           capture_output=True, text=True)
        if r.returncode:
            raise SystemExit("host: %s\n%s" % (src, r.stderr[-3000:]))
        host_objs.append(o)
    host_defs = set()
    host_all = set()
    for d, _ in nm(host_objs).values():
        host_defs |= {x for x in d if re.fullmatch(r"ffg?_[0-9a-f]{8}", x)}
        host_all |= d
    lacking = sorted(x for x in undefined if (x.startswith("ffh_") or x in {v for v in wasm_hooks()[2].values()})
                     and x not in host_all)
    if lacking:
        raise SystemExit("link: the host defines no replay hook %s (src/platform/wasm/host/replay.cpp)" % ", ".join(lacking))
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
        if not m or x in host_defs or (m.group(1) == "ffg" and int(m.group(2), 16) in adj) or \
                (m.group(1) == "ffg" and int(m.group(2), 16) in forwarders()):
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
    # member-function-pointer forwarders: `this` becomes [this+4], the call goes on to [this+8] (FORWARDER)
    for ad in sorted(forwarders()):
        x = "ffg_%08x" % ad
        if x in defined | host_defs:
            continue
        stubs.pop(x, None)
        c.append("void %s(uint32_t ecx, uint32_t edx, void* st, void* rb) { ff_dispatch(*(uint32_t*)(uintptr_t)(ecx + 8), "
                 "*(uint32_t*)(uintptr_t)(ecx + 4), edx, st, rb); }" % x)
        thunks[x] = 0
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
    # an open-addressing hash table (linear probing, at most half full), laid out here: one or two probes a call
    bits = max(10, (2 * len(entries) - 1).bit_length())
    slots = [None] * (1 << bits)
    for x in entries:
        k = ((int(x[4:], 16) * 0x9E3779B1) & 0xffffffff) >> (32 - bits)
        while slots[k] is not None:
            k = (k + 1) & ((1 << bits) - 1)
        slots[k] = x
    c.append("#define FF_BITS %d" % bits)
    c.append("static const struct { uint32_t a; ffg_t f; } table[1 << FF_BITS] = {")
    c += ["  {0x%s, %s}," % (x[4:], x) if x else "  {0, 0}," for x in slots]
    c.append("};")
    c.append("""ffg_t ff_lookup(uint32_t a) {
  unsigned k = (a * 0x9E3779B1u) >> (32 - FF_BITS);
  for (;;) {
    if (table[k].a == a) return table[k].f;
    if (!table[k].f) return 0;
    k = (k + 1) & ((1u << FF_BITS) - 1);
  }
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
    out = os.path.join(OUT, "hulk.raw.wasm")
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
            "-sALLOW_MEMORY_GROWTH=0", "-sSTACK_SIZE=%d" % (4 << 20), "-sSTANDALONE_WASM=1",
            "-sSTACK_OVERFLOW_CHECK=0", "-Wl,--no-demangle", "-Wl,--error-limit=0", "--profiling-funcs"]
        cmd += (["-sERROR_ON_UNDEFINED_SYMBOLS=1"] if final else
                ["-sERROR_ON_UNDEFINED_SYMBOLS=0", "-Wl,--warn-unresolved-symbols"])
        return subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    r = run([], False)
    missing = set(re.findall(r"undefined symbol: (\S+)", r.stderr))
    if os.path.exists(out):     # (standalone: what the link left undefined is an `env` import)
        missing |= {n for m, n, kind in wasm_imports(out) if m == "env"}
    missing = sorted(missing)
    decl = {}
    if missing:
        want = set(missing)
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
                "declare void @ff_unbound_name(ptr)", "declare void @ff_dispatch(i32, i32, i32, ptr, ptr)"]
        dtors = destructor_entries(img, missing)
        # clang's sized frees (C++14 sized deallocation; MSVC 7.1 has none): the game's unsized ones by address, as
        # the Wine build's crt_glue.cpp forwards them
        for n, unsized in SIZED_FREE.items():
            a_ = binding_map()["bindings"].get(unsized, {}).get("addr")
            if n in missing and a_:
                dtors[n] = int(a_, 16)
        for i, n in enumerate(missing):
            irn, d = decl.get(n, (n, None))
            if n in dtors and d and d.startswith("declare "):
                sig = parse_func_line(d)[3]
                if sig.params and sig.params[0].type == "ptr":
                    body.append("define %s %s(%s) {" % (sig.ret, at(irn), ", ".join(
                        "%s %%a%d" % (p.type, k) for k, p in enumerate(sig.params))))
                    free = n in SIZED_FREE         # (cdecl: the pointer on the stack; a destructor: this, flags 0)
                    body += ["  %st = alloca [4 x i32], align 4", "  %rb = alloca [16 x i8], align 8",
                             "  %t = ptrtoint ptr %a0 to i32",
                             "  store i32 %s, ptr %%st, align 4" % ("%t" if free else "0"),
                             "  call void @ff_dispatch(i32 %d, i32 %s, i32 0, ptr %%st, ptr %%rb)" % (
                                 dtors[n], "0" if free else "%t"),
                             "  ret void" if sig.ret == "void" else "  ret ptr %a0" if sig.ret == "ptr" else
                             "  ret %s 0" % sig.ret, "}"]
                    continue
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
    if not r.returncode:
        r = asyncify(out, os.path.join(OUT, "hulk.wasm"))
    warn = collections.Counter()
    for line in r.stderr.splitlines():
        m = re.search(r"(function signature mismatch|undefined symbol): (\S+)", line)
        if m:
            warn[(m.group(1), m.group(2))] += 1
    link = {"rc": r.returncode, "objects": len(objs), "entries": len(entries),
            "stubs": {k: list(v) for k, v in stubs.items()}, "thunks": {k: "0x%08x" % v for k, v in thunks.items()},
            "named_undefined": missing, "data_undefined": data_stubs(missing, decl), "destructors": {k: "0x%08x" % v for k, v in dtors.items()} if missing else {}, "warnings": [list(k) + [n] for k, n in warn.items()],
            "stderr": r.stderr[-6000:] if r.returncode else ""}
    json.dump(link, open(os.path.join(OUT, "link.json"), "w"), indent=1)
    print("link rc %d: %d objects, %d generic entries, %d thunks, %d unbound entries, %d named stubs, %d warnings" % (
        r.returncode, len(objs), len(entries), len(thunks), len(stubs), len(missing), len(warn)))
    if r.returncode:
        print(r.stderr[-3000:])
    cmd_report(a)
    baseline = json.load(open(DATA_STUB_BASELINE))["names"] if os.path.exists(DATA_STUB_BASELINE) else []
    new_data, gone = data_stub_check(link["data_undefined"], baseline)
    if gone:
        print("data stubs: %d baseline name(s) no longer stubs, drop them from %s: %s" % (
            len(gone), os.path.relpath(DATA_STUB_BASELINE, ROOT), ", ".join(gone)))
    if new_data and not r.returncode:
        if os.path.exists(os.path.join(OUT, "hulk.wasm")):
            os.remove(os.path.join(OUT, "hulk.wasm"))
        raise SystemExit("link: %d data name(s) bound nothing and became zero-filled stubs (name game data DAT_<addr>; "
                         "config/wasm-data-stubs.json only shrinks): %s" % (len(new_data), ", ".join(new_data)))
    if r.returncode:        # (an older hulk.wasm left in the directory must not reach `aot`: wapp2)
        if os.path.exists(os.path.join(OUT, "hulk.wasm")):
            os.remove(os.path.join(OUT, "hulk.wasm"))
        raise SystemExit("link failed (rc %d): %s/link.json" % (r.returncode, OUT))


# (gcmp1) A data name the link leaves undefined becomes a zero-filled 64-byte stub: whatever reads or points at it gets
# zeros, silently (0x00295e20's `extern float one` stood for the identity matrix 0x4c9f38 and made every root
# scenegraph transform a zero matrix: the intro's sky, backdrop and props vanished). Sources name game data by its
# address (DAT_<addr>), never by a TU-local name. config/wasm-data-stubs.json lists the data stubs known when the
# check came in; it only shrinks. Function stubs (destructors, vfunc views) stay reported, not failing.
DATA_STUB_BASELINE = os.path.join(ROOT, "config/wasm-data-stubs.json")


def data_stubs(missing, decl):
    """The named stubs that are data: no function declaration names them (the stub is a zero-filled global)."""
    return sorted(n for n in missing if not (decl.get(n, (None, ""))[1] or "").startswith("declare "))


def data_stub_check(data, baseline):
    """-> (new, gone): data stubs not in the baseline (the link fails on them), baseline names no longer stubs (the
    baseline can shrink: drop them)."""
    return sorted(set(data) - set(baseline)), sorted(set(baseline) - set(data))


def cmd_report(a):
    link = json.load(open(os.path.join(OUT, "link.json")))
    by = collections.Counter(v[0] for v in link["stubs"].values())
    print("unbound entries by place (the host's work list): %d" % len(link["stubs"]), dict(by.most_common()))
    for kind, _ in by.most_common():
        ns = sorted({(v[1] or "?") for v in link["stubs"].values() if v[0] == kind})
        print("  %s (%d): %s" % (kind, len(ns), ", ".join(ns[:30]) + (" ..." if len(ns) > 30 else "")))
    print("named undefined: %d" % len(link["named_undefined"]), ", ".join(link["named_undefined"][:40]))
    if "data_undefined" in link:
        print("named undefined data (zero-filled stubs): %d" % len(link["data_undefined"]), ", ".join(link["data_undefined"]))
    for w in link["warnings"][:20]:
        print("  warning:", *w)


# ---------------------------------------------------------------------------------------------- ahead of time
WASM2C = os.environ.get("HULK_WASM2C") or shutil.which("wasm2c") or "wasm2c"
CC = os.environ.get("HULK_CC", "clang")


def wabt_share():
    """wabt's wasm2c runtime sources (wasm-rt-impl.c ...): next to the wasm2c binary's prefix."""
    pre = os.path.dirname(os.path.dirname(os.path.realpath(WASM2C)))
    return os.path.join(pre, "share/wabt/wasm2c"), os.path.join(pre, "include")


def _cc(job):
    src, obj, flags = job
    r = subprocess.run([CC] + flags + ["-c", src, "-o", obj + ".tmp"], capture_output=True, text=True,
                       errors="replace")
    if r.returncode:
        return src, r.stderr[-2000:]
    os.replace(obj + ".tmp", obj)
    return src, None


# the app runner (aot --app; docs/wasm-port.md "The macOS app"): run/native.c with HULK_APP, run/app/, the bgfx sink and
# the bridge's host half (src/platform/sdl/pddi/), the window code (platform_events.cpp); bgfx (Metal) and SDL3 with
# video (HULK_APP_SDL: an install prefix; the shared sdl-host is built without video)
APP_SDL = os.environ.get("HULK_APP_SDL") or os.path.join(ROOT, "build/third_party/out/sdl-video")
APP_FRAMEWORKS = ["CoreAudio", "AudioToolbox", "CoreFoundation", "IOKit", "GameController", "CoreHaptics",
                  "ForceFeedback", "Foundation", "AVFoundation", "CoreMotion", "Carbon", "AppKit", "Metal", "MetalKit",
                  "QuartzCore", "UniformTypeIdentifiers", "CoreVideo", "CoreMedia", "Cocoa", "VideoToolbox"]
BGFX_DEFS = ["-DBX_CONFIG_DEBUG=0", "-DBIMG_CONFIG_DECODE_ASTC=0", "-DBGFX_CONFIG_RENDERER_WEBGPU=0",
             "-DBGFX_CONFIG_MULTITHREADED=0", "-D__STDC_LIMIT_MACROS", "-D__STDC_FORMAT_MACROS",
             "-D__STDC_CONSTANT_MACROS", "-DBGFX_CONFIG_RENDERER_METAL=1"]


def ffmpeg_flags():
    """FFmpeg's headers for run/app/movie.c (HULK_FFMPEG_PREFIX, else Homebrew's): the app loads the libraries of the
    same major versions at run time (never linked or shipped); without the headers it builds with black movies."""
    for p in (os.environ.get("HULK_FFMPEG_PREFIX"), "/opt/homebrew/opt/ffmpeg", "/usr/local/opt/ffmpeg"):
        if p and os.path.exists(os.path.join(p, "include/libavformat/avformat.h")):
            return ["-DHULK_HAVE_FFMPEG=1", "-I" + os.path.join(p, "include"),
                    # (wbuild1) HULK_FFMPEG_LIBDIR: where the app loads the libraries at run time, when it is built
                    # elsewhere (a queue host: the headers come from the shipped inputs, the libraries are the player's)
                    '-DHULK_FFMPEG_LIBDIR="%s"' % (os.environ.get("HULK_FFMPEG_LIBDIR") or os.path.join(p, "lib"))]
    print("aot --app: no FFmpeg headers (brew install ffmpeg, or HULK_FFMPEG_PREFIX): the app's movies play black")
    return []


def app_objects(d, wflags):
    """(objects, link flags) of the app runner's own sources (compiled here, cached by content and flags)."""
    import wine_gfx
    tp = os.path.join(ROOT, "build/third_party")
    sdl = os.path.join(ROOT, "src/platform/sdl")
    if not os.path.exists(os.path.join(APP_SDL, "lib/libSDL3.a")):
        raise SystemExit("aot --app: no SDL3 with video at %s (HULK_APP_SDL)" % APP_SDL)
    gen = os.path.join(d, "app-gen")
    wine_gfx.embed_shaders(gen, "metal")        # the sink's programs (tools/wine_gfx.py shaders)
    cxx = ["xcrun", "clang++", "-arch", "arm64", "-mmacosx-version-min=11.0", "-std=c++20", "-O2", "-g",
           "-fno-exceptions", "-fno-rtti", "-Wall", "-Wno-unused-parameter", "-Wno-unused-private-field",
           "-Wno-deprecated-declarations", "-I" + os.path.join(sdl, "pddi"), "-I" + gen, "-I" + sdl,
           "-I" + os.path.join(APP_SDL, "include"), "-I" + d, "-I" + wabt_share()[0], "-I" + wabt_share()[1],
           "-I" + os.path.join(tp, "src/bx/include"), "-I" + os.path.join(tp, "src/bx/include/compat/osx"),
           "-I" + os.path.join(tp, "src/bimg/include"), "-I" + os.path.join(tp, "src/bgfx/include")] + BGFX_DEFS
    run = os.path.join(HOST_DIR, "run")
    jobs = [(os.path.join(run, "native.c"), [CC] + wflags + ["-DHULK_APP=1"])]
    for f in sorted(os.listdir(os.path.join(run, "app"))):
        if f.endswith(".cpp"):
            jobs.append((os.path.join(run, "app", f), cxx))
        elif f.endswith(".c"):          # (movie.c: FFmpeg's headers, its libraries loaded at run time)
            jobs.append((os.path.join(run, "app", f), ["xcrun", "clang", "-arch", "arm64", "-mmacosx-version-min=11.0",
                                                        "-std=c11", "-O2", "-g", "-Wall", "-Wno-unused-parameter",
                                                        "-I" + sdl] + ffmpeg_flags()))
    for f in ("bgfx_sink.cpp", "bgfx_bridge.cpp"):
        jobs.append((os.path.join(sdl, "pddi", f), cxx + ["-DHULK_PDDI_HOST=1", "-DHULK_PDDI_EMBED_SHADERS=1",
                                                         "-DHULK_PDDI_BRIDGE_HOST=1", "-DHULK_SINK_OVERLAY=1"]))
    jobs.append((os.path.join(sdl, "platform_events.cpp"), cxx + ["-DHULK_SDL_LINKED=1"]))
    os.makedirs(os.path.join(d, "app"), exist_ok=True)
    objs = []
    for src, cmd in jobs:
        # (run/app/input.cpp includes the SDL layer's input/hulk_input.cpp: that directory's sources count too)
        key = hashlib.sha1(open(src, "rb").read() + " ".join(cmd).encode() + b"".join(
            open(os.path.join(dp, f), "rb").read() for dp in (os.path.join(run, "app"), os.path.join(sdl, "pddi"), gen,
                                                              os.path.join(sdl, "input"), os.path.join(sdl, "movies"))
            for f in sorted(os.listdir(dp)) if f.endswith(".h") or dp.endswith("input") and f.endswith(".cpp")
            or dp.endswith("movies") and f == "movie.c"
        )).hexdigest()[:16]
        obj = os.path.join(d, "app", "%s.%s.o" % (os.path.basename(src).rsplit(".", 1)[0], key))
        if not os.path.exists(obj):
            r = subprocess.run(cmd + ["-c", src, "-o", obj + ".tmp"], capture_output=True, text=True, errors="replace")
            if r.returncode:
                raise SystemExit("aot --app: %s\n%s" % (src, r.stderr[-4000:]))
            os.replace(obj + ".tmp", obj)
        objs.append(obj)
    lib = os.path.join(tp, "out/host/lib")
    rt = subprocess.run(["xcrun", "clang", "--print-runtime-dir"], capture_output=True, text=True).stdout.strip()
    lflags = [os.path.join(lib, n + ".a") for n in ("bgfx", "bimg", "bx")] + [
        os.path.join(APP_SDL, "lib/libSDL3.a"), "-lc++", "-liconv", os.path.join(rt, "libclang_rt.osx.a")]
    for fw in APP_FRAMEWORKS:
        lflags += ["-framework", fw]
    return objs, lflags


def cmd_aot(a):
    """hulk.wasm -> C (wasm2c, module `game`) -> a native executable (build/wasm/hulk-aot) with the runner
    src/platform/wasm/run/native.c. Objects are cached by the C file's content."""
    import time
    t = time.time()
    d = os.path.join(OUT, "aot")
    os.makedirs(d, exist_ok=True)
    for f in os.listdir(d):
        if f.endswith(".c") or f.endswith(".h"):
            os.remove(os.path.join(d, f))
    r = subprocess.run([WASM2C, os.path.join(OUT, "hulk.wasm"), "-n", "game", "--num-outputs=%d" % a.outputs,
                        "-o", os.path.join(d, "game.c")], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("wasm2c: " + r.stderr[-2000:])
    share, inc = wabt_share()
    flags = [a.opt, "-I", d, "-I", share, "-I", inc, "-w", "-fno-strict-aliasing"]
    jobs, objs = [], []
    impl = open(os.path.join(d, "game-impl.h"), "rb").read()
    for f in sorted(os.listdir(d)) + [os.path.join(share, "wasm-rt-impl.c"), os.path.join(share, "wasm-rt-mem-impl.c"),
                                      os.path.join(share, "wasm-rt-exceptions-impl.c"),
                                      os.path.join(HOST_DIR, "run/native.c")]:
        if not f.endswith(".c"):
            continue
        src = f if os.path.isabs(f) else os.path.join(d, f)
        key = hashlib.sha1(open(src, "rb").read() + impl + " ".join(flags).encode()).hexdigest()[:16]
        obj = os.path.join(d, "obj", "%s.%s.o" % (os.path.basename(src)[:-2], key))
        objs.append(obj)
        if not os.path.exists(obj):
            jobs.append((src, obj, flags))
    os.makedirs(os.path.join(d, "obj"), exist_ok=True)
    keep = set(objs)
    for f in os.listdir(os.path.join(d, "obj")):
        if os.path.join(d, "obj", f) not in keep:
            os.remove(os.path.join(d, "obj", f))
    print("aot: wasm2c %.0f s; compiling %d of %d C files (%s)" % (time.time() - t, len(jobs), len(objs), a.opt),
          flush=True)
    with concurrent.futures.ProcessPoolExecutor(a.jobs) as ex:
        for src, err in ex.map(_cc, jobs):
            if err:
                raise SystemExit("cc %s: %s" % (src, err))
    lflags = ["-lm"]
    if a.app:
        app_objs, lflags = app_objects(d, flags)
        objs = [o for o in objs if not os.path.basename(o).startswith("native.")] + app_objs
    out = os.path.join(OUT, "hulk-app" if a.app else "hulk-aot")
    r = subprocess.run([CC] + objs + ["-o", out] + lflags, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("link: " + r.stderr[-3000:])
    print("aot: %s in %.0f s" % (out, time.time() - t))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("compile")
    c.add_argument("--only", nargs="*")
    c.add_argument("--jobs", type=int, default=2)
    sp.add_parser("link")
    sp.add_parser("report")
    c = sp.add_parser("aot")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--outputs", type=int, default=32)
    c.add_argument("--opt", default="-O2")
    c.add_argument("--app", action="store_true", help="the macOS app runner (HULK_WASM_GFX=1 modules): hulk-app")
    a = ap.parse_args(argv)
    {"compile": cmd_compile, "link": cmd_link, "report": cmd_report, "aot": cmd_aot}[a.cmd](a)


if __name__ == "__main__":
    main()
