#!/usr/bin/env python3
"""Callee binding map for the native link (docs/native-build.md fix 5a), and a link attempt with lld-link.

  build/venv/bin/python tools/native_link.py              # binding map from the verification build + link inventory
  build/venv/bin/python tools/native_link.py --no-link    # binding map and inventory only (no lld-link run)
  build/venv/bin/python tools/native_link.py --jobs 3     # processes for the equivalent/ bindings (default 3)
  build/venv/bin/python tools/native_link.py --reuse-map --gfx   # the image with the pddi/bgfx graphics backend

Why: every verified function is checked with its relocations masked (compare.py) or bound by address
(equiv.py), so a call made under a caller's stub name (`Base_135f40::Fin`), from inside a wrapped source's
namespace (`fn_00213600::FUN_00219430`) or with another signature is proven to be a call to one XBE address,
but no linker knows which. This tool recovers that address for every relocation of the verification build
(build/tree/, tools/build_tree.py) and names the tree's definition at that address, so lld-link can bind the
reference with `/alternatename:<referenced>=<defined>`. On 32-bit MS ABI the alias is exact: both names are the
same machine-level call that the byte match or the behaviour check proved.

Inputs: build/tree/report.json (+ manifest.json) of a complete tools/build_tree.py run (its objects come
from build/tree-cache/obj/ by content), the XBE, and for the link inventory tools/clang_probe.py's `msvc`
objects (snapshot of the tree; run tools/clang_probe.py --snapshot after the tree build first).

Per relocation of a verified function, the address:
  * matches/: the original bytes at the same offset (the function is byte-identical with relocations masked),
    REL32 -> call target, DIR32 -> absolute address (tools/verify_relocs.py's rule);
  * equivalent/: the address tools/equiv.py binds (level 2, `mapping`: explicit equiv-map lines, content,
    names, then alignment with the original). Cached in build/native/cache/.
Then each address is named: a verified function's symbol in the tree's objects, or a data TU symbol
(`_DAT_<addr>`, tools/data_gen.py). A referenced symbol bound to one address whose definition has another
name gets an alias; references bound to two addresses are `ambiguous` (an invented C name reused by two
sources for different callees) and get none.

Outputs (build/native/, not tracked):
  bindings.json      referenced symbol -> {addr, how, refs, def}; definitions per address; ambiguous symbols
  alternatename.rsp  /alternatename lines for every binding of the verification build
  link/              the link attempt: objects.rsp, aliases.rsp (bindings restricted to symbols the clang
                     objects define), stubs.s/.obj (one stub per symbol still undefined), lld-link.log,
                     vtables.s/.obj (the game's vftables and RTTI as data, code_owned_data: fix 6a),
                     platform/ (src/platform/sdl/xdk/ compiled: the platform-import stand-ins, fix 7),
                     deleting.s/.obj (the scalar deleting destructors clang doesn't emit: fix 6b),
                     objs/ (objects with ambiguous symbols renamed per TU, rb_ rebound per calling function,
                     vt_ stub-vftable references pointed at the game's vftable, rt_ interior data references
                     retargeted to their item, gl_ clang dynamic initializers made global),
                     host/ (msvcrt/ntdll/kernel32 import libraries from src/platform/sdl/crt/host_crt_table.h),
                     crt/ (src/platform/sdl/crt/ compiled), startup.s/.obj (the game's initializer table, type_info's
                     vftable), hulk-strict.exe/.map (the image and its map: tools/native_run.py runs it under Wine),
                     gfx/ (--gfx: the pddi objects and bgfx/bimg/bx with their host imports renamed hulk_gfx_*,
                     and the import libraries for those: graphics_backend)

The start-up milestone (docs/native-build.md "Start-up"; tools/native_host.py): the host C runtime and our CRT glue,
the library code and data the tree reaches by address (src/platform/sdl/xdk/library.h), the entry point
(src/platform/sdl/xdk/startup.cpp) with the XBE's C++ initializer table, and the tools/native_conv_check.py report
(`conv_check` in report.json).

Beyond the binding map, the inventory aliases a stub class's virtual members to slot N of the game vftable the
stub stands for (stub_slot_aliases: fix 3a) and renames an ambiguous symbol per object where each TU has one
callee (`ambiguous_by_tu`). `--reuse-map` runs the inventory and link on an existing bindings.json.
  report.json        counts: bindings by how, the clang objects' undefined symbols before/after binding by
                     group (tools/clang_probe.py's groups), the lld-link result
  unbound.txt        every symbol still undefined after binding: group, references, symbol, demangled
"""
import argparse
import bisect
import collections
import csv
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from concurrent.futures import ProcessPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import compare  # noqa: E402
import native_host  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
# HULK_NATIVE_DIR: another output directory (bindings, link, report), e.g. for a run beside another agent's;
# --tree (or HULK_TREE_DIR): the verification tree to bind from, e.g. tools/clang_probe.py's snapshot of it, so the
# binding map and the clang objects come from one tree while build/tree/ is being rebuilt. The equiv.py binding
# cache is content-keyed and shared (HULK_NATIVE_CACHE to move it).
OUT = os.environ.get("HULK_NATIVE_DIR") or os.path.join(ROOT, "build/native")
CACHE = os.environ.get("HULK_NATIVE_CACHE") or os.path.join(ROOT, "build/native/cache")
TREE = os.environ.get("HULK_TREE_DIR") or os.path.join(ROOT, "build/tree")
REL32, DIR32 = 0x14, 0x06
ADDR_RX = re.compile(r"(?:^|[^0-9A-Za-z])(?:FUN|DAT|thunk_FUN|PTR|LAB|hulk_at|vtbl|rttiTD)_(00[0-9a-fA-F]{6})(?![0-9a-fA-F])")


def is_undefined(sym):
    return sym is not None and sym[2] == 0 and sym[4] == 2      # IMAGE_SYM_UNDEFINED, external


# ---------------------------------------------------------------------------------------------
# Relocation -> address
_X = {}


def xbe():
    if "x" not in _X:
        from xbe import Xbe
        _X["x"] = Xbe(compare.XBE_PATH)
    return _X["x"]


def match_bindings(obj, symbol, addr, local=None):
    """{undefined symbol: Counter(address)} of a byte-matching function, by position. With `local` (a dict of
    Counters): also the calls and jumps to code the object defines itself (native9: a source's own stand-in body for
    its callee, `pure3d::Sprite::~Sprite() {}` matched as the scalar deleting destructor whose call goes to 0x002bd430)."""
    coff = compare.Coff(obj)
    sym = next((s for s in coff.function_symbols() if s[0] == symbol), None)
    out = collections.defaultdict(collections.Counter)
    if sym is None:
        return out
    x = xbe()
    for off, tsym, typ, addend_bytes in coff.function_relocs(sym):
        if local is not None and typ == REL32 and tsym is not None and tsym[2] > 0 and tsym[4] == 2 and \
                tsym[0] != symbol and coff.sections[tsym[2] - 1][0].startswith(".text"):
            o = x.offset(addr + off)
            if o is not None:
                orig, = struct.unpack("<i", x.data[o:o + 4])
                addend, = struct.unpack("<i", addend_bytes)
                local[tsym[0]][(addr + off + 4 + orig - addend) & 0xFFFFFFFF] += 1
            continue
        if typ not in (REL32, DIR32) or tsym is None or not (is_undefined(tsym) or tsym[0].startswith("??_7")):
            continue      # (a stub's own vftable is defined in the object: its address names the real one, fix 3a)
        o = x.offset(addr + off)
        if o is None:
            continue
        orig, = struct.unpack("<I", x.data[o:o + 4])
        addend, = struct.unpack("<i", addend_bytes)
        if typ == REL32:
            t = (addr + off + 4 + struct.unpack("<i", struct.pack("<I", orig))[0] - addend) & 0xFFFFFFFF
        else:
            t = (orig - addend) & 0xFFFFFFFF
        out[tsym[0]][t] += 1
    return out


def local_data_bindings(obj, symbol, addr):
    """{data symbol the object defines itself: XBE address} of a byte-matching function: a source that defines a
    global (`LockFn EnterPtr = 0;`, `int gFlag;`) where the original reads the game's (the kernel thunk slot at
    0x003f2c8c, a .data word). MSVC emits the same `[abs32]` for both; natively the source's own copy is another
    variable. The link points those relocations at the game's item (link_inventory)."""
    coff = compare.Coff(obj)
    sym = next((s for s in coff.function_symbols() if s[0] == symbol), None)
    out = {}
    if sym is None:
        return out
    x = xbe()
    for off, t, typ, ab in coff.function_relocs(sym):
        if typ != DIR32 or t is None or t[2] <= 0 or t[4] != 2:
            continue
        if t[0].startswith(("??_C", "__real", "??_7", "??_R", "$")):
            continue
        if coff.sections[t[2] - 1][0].startswith(".text"):
            continue
        o = x.offset(addr + off)
        if o is None:
            continue
        v = (struct.unpack_from("<I", x.data, o)[0] - struct.unpack("<i", ab)[0]) & 0xFFFFFFFF
        sec = x.section_of(v)
        if sec is not None and sec.name in (".data", ".rdata"):
            out[t[0]] = v
    return out


def _equiv_job(args):
    obj, symbol, src, addr = args
    raw = open(obj, "rb").read()
    # (the COFF header's time stamp, bytes 4-8, left out: the same object built on another machine hits the cache)
    # (v2: the map also keeps the vftables the object defines itself, `??_7Stub@fn_...@@6B@`: where the
    # function stores a stub's vftable, equiv.py binds it to the game's, which fix 3a needs for the stub's slots)
    key = hashlib.sha1(raw[:4] + raw[8:] + symbol.encode() + src.encode() + b"v2").hexdigest()[:24]
    p = os.path.join(CACHE, "equiv", key + ".json")
    if os.path.exists(p):
        return json.load(open(p))
    import equiv
    undefined = {s[0] for s in compare.Coff(obj).symbols if s[2] == 0 and s[4] == 2}
    try:
        rep = equiv.verify(os.path.join(ROOT, src), addr, symbol=symbol, obj_path=obj, max_level=2)
        m = rep.get("level2", {}).get("mapping", {})
        res = {"status": rep.get("status"),
               "map": {n: [v["addr"], v["how"]] for n, v in m.items()
                       if (n in undefined or n.startswith("??_7")) and v.get("addr")},
               "unresolved": sorted(n for n, v in m.items() if n in undefined and not v.get("addr"))}
    except Exception as e:  # noqa: BLE001 - one function's failure must not stop the map
        res = {"status": "error: %s" % type(e).__name__, "map": {}, "unresolved": []}
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w") as f:
        json.dump(res, f)
    return res


_UNDNAME = {}


def undname(names):
    """{mangled: demangled} through llvm-undname (cached; names it can't demangle map to themselves)."""
    want = sorted({n for n in names if n not in _UNDNAME})
    if want:
        p = subprocess.run([os.path.join(native_host.LLVM, "llvm-undname")], input="\n".join(want) + "\n",
                           capture_output=True, text=True, errors="replace")
        blocks = [b.split("\n") for b in p.stdout.strip("\n").split("\n\n")]
        for b in blocks:
            if len(b) >= 2:
                _UNDNAME[b[0]] = b[1]
        for n in want:
            _UNDNAME.setdefault(n, n)
    return {n: _UNDNAME[n] for n in names}


_FN_NS = re.compile(r"(?<![A-Za-z0-9_])fn_[0-9a-fA-F]{8}::")


def tree_explicit(res, obj, src):
    """native10: a source's `// equiv-map:` lines name the standalone symbol (`??0DrawableBase@pure3d@@QAE@XZ`); in a
    merged tree object the name carries the TU's namespace (`??0DrawableBase@pure3d@fn_f0ae8a57@@QAE@XZ`). equiv.py
    translates the plain names (`_tree_names`) but not constructors, destructors and operators (its `_qualified`
    skips `??` names), so those fell back to instruction pairing and could bind to a neighbouring callee (0x0029a190:
    DrawableBase's constructor bound to the allocator 0x00263ea0, operator new called with `this` as the size: the
    native stop 'game heap exhausted'). Here every equiv-map line the map does not already have under its own name
    is matched to the object's undefined symbol whose demangled name is the same without `fn_<addr>::`."""
    try:
        lines = [(m.group(1), int(m.group(2), 16)) for m in
                 (re.match(r"\s*//\s*equiv-map:\s*(\S+)\s*=\s*(0x[0-9a-fA-F]+)", l)
                  for l in open(os.path.join(ROOT, src), errors="replace")) if m]
    except OSError:
        return res
    if not lines:
        return res
    syms = compare.Coff(obj).symbols
    undefined = {s[0] for s in syms if s[2] == 0 and s[4] == 2}
    lines = [(n, a) for n, a in lines if n not in undefined and n.startswith("?")]
    if not lines:
        return res
    cands = [s for s in undefined if s.startswith("?") and "fn_" in s]
    dm = undname(cands + [n for n, _ in lines])
    by = collections.defaultdict(list)
    for s in cands:
        by[_FN_NS.sub("", dm[s])].append(s)
    for n, a in lines:
        hits = by.get(_FN_NS.sub("", dm[n])) or []
        if len(hits) == 1:
            old = res["map"].get(hits[0])
            if not old or int(old[0], 16) != a:
                res.setdefault("tree_explicit", []).append([hits[0], "0x%08x" % a, old])
            res["map"][hits[0]] = ["0x%08x" % a, "explicit"]
    return res


tree_explicit.changed = []


# ---------------------------------------------------------------------------------------------
def tree_checks():
    rep = json.load(open(os.path.join(TREE, "report.json")))
    return rep["checks"]


def tree_objects(tus):
    import build_tree
    build_tree.TREE, build_tree.INCLUDE_DIR = TREE, os.path.join(TREE, "include")
    return {t: build_tree.compile_tu(t)[0] for t in sorted(tus)}


def build_map(jobs):
    checks = tree_checks()
    objs = tree_objects({c["tu"] for c in checks})
    defs = {}                       # addr -> defining symbol in the tree's objects
    for c in checks:
        if c.get("symbol") and c["status"] in ("match", "compiled") and objs.get(c["tu"]):
            defs[int(c["addr"], 16)] = c["symbol"]
    refs = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))   # sym -> addr -> how
    per_tu = collections.defaultdict(lambda: collections.defaultdict(set))                 # sym -> TU -> addrs
    per_fn = collections.defaultdict(lambda: collections.defaultdict(set))                 # sym -> function -> addrs
    users = collections.Counter()
    stats = collections.Counter()
    todo, todo_tu = [], []
    local_data = collections.defaultdict(set)
    local_code = collections.defaultdict(collections.Counter)
    vt_src = collections.defaultdict(lambda: collections.defaultdict(set))     # ??_7 symbol -> source -> addresses
    # native9: checks of one TU sharing a symbol whose source doesn't name it (build_tree's loose lookup took a
    # same-named function: 0x0023d710 as 0x0023d420's `Func`): their positions would bind the other source's
    # relocations to this address's bytes, so they bind nothing
    groups = collections.defaultdict(list)
    for c in checks:
        if c.get("symbol") and c["kind"] == "matches" and c["status"] == "match":
            groups[(c["tu"], c["symbol"])].append(c)
    skip = set()
    multi = sorted(sym for (tu, sym), cs in groups.items() if len(cs) > 1 and sym.startswith("?"))
    dem = {}
    if multi:
        out_ = subprocess.run([native_host.LLVM + "/llvm-undname"], input="\n".join(multi) + "\n",
                              capture_output=True, text=True, errors="replace").stdout.splitlines()
        for i in range(len(out_) - 1):
            if out_[i] in multi and out_[i] not in dem:
                dem[out_[i]] = out_[i + 1]
    keywords = {"public", "private", "protected", "virtual", "static", "void", "int", "char", "bool", "short", "long",
                "unsigned", "signed", "float", "double", "const", "struct", "class", "union", "enum", "__thiscall",
                "__cdecl", "__stdcall", "__fastcall", "__ptr64", "__int64", "volatile", "operator", "wchar_t"}
    for (tu, sym), cs in groups.items():
        if len(cs) < 2 or sym not in dem:
            continue
        words = {w for w in re.findall(r"[A-Za-z_]\w*", dem[sym]) if w not in keywords and not re.fullmatch(r"fn_[0-9a-f]{8}", w)}
        for c in cs:
            try:
                txt = open(os.path.join(ROOT, c["src"]), errors="replace").read()
            except OSError:
                continue
            if not all(re.search(r"\b%s\b" % re.escape(w), txt) for w in words):
                skip.add(c["addr"])
    stats["checks sharing a symbol their source doesn't name (not bound)"] = len(skip)
    for c in checks:
        if c["addr"] in skip:
            continue
        obj = objs.get(c["tu"])
        if not obj or not c.get("symbol"):
            stats["functions without an object or symbol"] += 1
            continue
        a = int(c["addr"], 16)
        if c["kind"] == "matches" and c["status"] == "match":
            for s, v in local_data_bindings(obj, c["symbol"], a).items():
                local_data[s].add(v)
            for s, ts in match_bindings(obj, c["symbol"], a, local_code).items():
                if s.startswith("??_7"):
                    vt_src[s][c["src"]] |= set(ts)
                for t, n in ts.items():
                    refs[s][t]["position"] += n
                    per_tu[s][c["tu"]].add(t)
                    per_fn[s][c["symbol"]].add(t)
                users[s] += 1
            stats["matches bound by position"] += 1
        elif c["kind"] == "equivalent" and c["status"] == "compiled":
            todo.append((obj, c["symbol"], c["src"], a))
            todo_tu.append(c["tu"])
    with ProcessPoolExecutor(jobs) as ex:
        for i, (res, tu, job) in enumerate(zip(ex.map(_equiv_job, todo, chunksize=8), todo_tu, todo), 1):
            stats["equivalent: equiv.py level 2 %s" % ("ok" if res["status"] in ("draft", "pass") else res["status"])] += 1
            res = tree_explicit(dict(res, map=dict(res["map"])), job[0], job[2])
            for s, t, old in res.get("tree_explicit", []):
                stats["equivalent: equiv-map lines bound in the tree's namespace (native10)"] += 1
                if old:
                    stats["equivalent: ... of them replacing another address (%s)" % old[1]] += 1
                tree_explicit.changed.append([job[2], s, t, old])
            for s, (t, how) in res["map"].items():
                refs[s][int(t, 16)]["equiv:" + how] += 1
                per_tu[s][tu].add(int(t, 16))
                per_fn[s][job[1]].add(int(t, 16))
                users[s] += 1
            for s in res["unresolved"]:
                stats["equivalent: symbols equiv.py could not bind"] += 1
            if i % 500 == 0 and sys.stderr.isatty():
                print("  equivalent bindings %d/%d" % (i, len(todo)), file=sys.stderr, flush=True)
    build_map.local_data = {s: "0x%08x" % next(iter(v)) for s, v in local_data.items() if len(v) == 1}
    build_map.vt_src = vt_src
    build_map.local_code = {s: "0x%08x" % next(iter(v)) for s, v in local_code.items()
                            if len({final_target(t) for t in v}) == 1}
    return defs, refs, users, stats, per_tu, per_fn


def data_definitions(objs_syms):
    """addr -> data symbol, from objects' defined `_DAT_<addr>` symbols (tools/data_gen.py's data TUs)."""
    out = {}
    for d in objs_syms:
        for s in d:
            m = re.fullmatch(r"_DAT_(00[0-9a-f]{6})", s)
            if m:
                out[int(m.group(1), 16)] = s
    return out


def final_target(a):
    """a, or the function a chain of `jmp rel32` thunks at a ends in."""
    return jmp_target(a) or a


def bind(defs, data_defs, refs):
    """referenced symbol -> binding record; and the ambiguous ones.

    Two addresses that are one function (a `jmp` thunk and its target: `operator delete` called at 0x0008d330 in
    one source and through thunk 0x00263f30 in another) are one callee: bound to the thunks' final target."""
    out, amb = {}, {}
    for s, by_addr in refs.items():
        addrs = sorted(by_addr)
        if len(addrs) > 1 and len({final_target(a) for a in addrs}) == 1:
            t = final_target(addrs[0])
            how = sorted({h for a in addrs for h in by_addr[a]} | {"thunks of one function"})
            d = defs.get(t) or data_defs.get(t)
            out[s] = {"addr": "0x%08x" % t, "how": how, "def": d}
            continue
        if len(addrs) > 1:
            amb[s] = {"0x%08x" % a: dict(by_addr[a]) for a in addrs}
            continue
        a = addrs[0]
        how = sorted(by_addr[a])
        d = defs.get(a) or data_defs.get(a)
        out[s] = {"addr": "0x%08x" % a, "how": how, "def": d}
    return out, amb


def jmp_target(a, hops=3):
    """The final target of a chain of `jmp rel32` thunks at a (None if a is not one)."""
    x, t = xbe(), None
    for _ in range(hops):
        o = x.offset(a)
        if o is None or x.data[o] != 0xE9:
            break
        a = t = (a + 5 + struct.unpack_from("<i", x.data, o + 1)[0]) & 0xFFFFFFFF
    return t


def name_address(s):
    m = ADDR_RX.search(s if s.startswith("?") else "_" + s.lstrip("_@"))
    return int(m.group(1), 16) if m else None


# ---------------------------------------------------------------------------------------------
# The link inventory over tools/clang_probe.py's msvc objects
def clang_objects():
    import clang_probe as cp
    clang = cp.tool("clang++")
    digest = cp.include_digest(cp.SNAP)
    tus = cp.tu_list()
    res = cp.compile_all("msvc", tus + cp.data_tus(), 3, clang, digest)
    return cp, tus, res


def link_inventory(binding, defs, data_defs, do_link, ambiguous=(), amb_tu=None, amb_fn=None, local_data=None,
                   local_code=None):
    cp, tus, res = clang_objects()
    man = cp.Manifest()
    objs = {p: r["obj"] for p, r in res.items() if r.get("obj")}
    syms = cp.nm(sorted(objs.values()))
    defined = set()
    for d, u in syms.values():
        defined |= d
    data_defs = dict(data_defs)
    data_defs.update(data_definitions(d for d, u in syms.values()))
    refs = collections.Counter()
    for d, u in syms.values():
        for s in u:
            refs[s] += 1
    undef = {s for s in refs if s not in defined and not s.startswith(("@feat", "__imp_"))}
    aliases, how = {}, collections.Counter()
    by_addr_def = {}
    for a, s in list(defs.items()) + list(data_defs.items()):
        if s in defined:
            by_addr_def.setdefault(a, s)
    # a verified definition whose MSVC 7.1 symbol clang spells differently (MSVC mangles a parameter `Matrix*` by
    # the class key of the declaration it saw first, `PAUMatrix`, clang by the definition's, `PAVMatrix`): the
    # one clang definition with that address in its name
    by_name_addr = collections.defaultdict(set)
    for s in defined:
        a = name_address(s)
        if a is not None and a in defs:
            by_name_addr[a].add(s)
    for a, ss in by_name_addr.items():
        if a not in by_addr_def and len(ss) == 1:
            by_addr_def[a] = next(iter(ss))
            how["definition under clang's spelling of its name"] += 1
    # native16: a definition whose float return is `hulk_freg` (include/compat/ptr.h: float under MSVC
    # 7.1, double natively) is mangled with `N` (double) where the MSVC symbol says `M` (float). On x87 both come
    # back in st0, so a caller declared `float f()` reads the unrounded value the original's callers read: the
    # binding goes to the clang definition that differs from the MSVC symbol in the return type's code only (never a
    # parameter's: a double parameter takes 8 bytes of the caller's stack)
    def_names = set(defs.values())
    ret_rx = re.compile(r"@@(Y[A-Z]|[ABEFIJMNQRUV][A-D][A-Z]|[CDKLST][A-Z])([MN])")
    for a, s in defs.items():
        if a in by_addr_def or s in defined or not s.startswith("?"):
            continue
        ms = list(ret_rx.finditer(s))
        if not ms:
            continue
        i = ms[-1].start(2)
        cand = {s[:i] + ("N" if s[i] == "M" else "M") + s[i + 1:]}
        cand = {c for c in cand if c in defined and c not in def_names}
        if len(cand) == 1:
            by_addr_def[a] = next(iter(cand))
            how["definition with a hulk_freg (double) return (native16)"] += 1
    # fix 6b: the verified scalar deleting destructors clang doesn't emit (build/native/link/deleting.s)
    dd = deleting_destructors(defs, defined)
    for s, addrs in dd["symbols"].items():
        defined.add(s)
        for a in addrs:
            by_addr_def.setdefault(a, s)
    for s in dd["references"]:
        if s not in defined:
            refs[s] += 1
            undef.add(s)
    # fix 7 (first part): the XDK import shim (src/platform/sdl/xdk/), whose stand-ins define the platform imports
    # by address and name
    shim = platform_shim(cp)
    if SDL_LIBS:        # (the backends' and SDL3's own symbols: never stubbed, the libraries define them)
        r_ = subprocess.run([native_host.LLVM + "/llvm-nm", "--defined-only", "-g"] + SDL_LIBS,
                            capture_output=True, text=True)
        shim["defined"] |= {l.split()[-1] for l in r_.stdout.splitlines() if len(l.split()) >= 3}
        r_ = subprocess.run([native_host.LLVM + "/llvm-nm", "--undefined-only", "-g"] + SDL_LIBS,
                            capture_output=True, text=True)
        sdl_undef = {l.split()[-1] for l in r_.stdout.splitlines() if l.strip().startswith("U ")}
    else:
        sdl_undef = set()
    for a, s in shim["by_addr"].items():
        by_addr_def.setdefault(a, s)
    defined |= shim["defined"]
    # start-up (docs/native-build.md "Start-up"): the host C runtime (src/platform/sdl/crt/: import libraries and our
    # glue), the library code and data the tree reaches by address (src/platform/sdl/xdk/library.h)
    host = native_host.host_crt(cp, os.path.join(OUT, "link"))
    defined |= host["defined"]
    lib = native_host.library_shim(cp, shim["objects"])
    # what the platform code itself still needs (clang's own libcalls in it: _aulldiv, memcpy): by name like the tree's
    for d_, u in list(cp.nm(shim["objects"] + host["objects"]).values()) + [(set(), sdl_undef)]:
        for s in u:
            if s not in defined and not s.startswith(("_hulk_host_", "__imp_", "_hulk_game_", "_hulk_clang_xc_", "@feat")):
                refs[s] += 1
                undef.add(s)
    for a, s in list(lib["by_addr"].items()) + list(host["by_addr"].items()):
        if by_addr_def.get(a) and by_addr_def[a] != s and a not in host["by_addr"]:
            continue
        by_addr_def[a] = s
    # --gfx: the pddi backend on bgfx in place of pure3d's d3d layer (graphics_backend): the engine's one call of
    # d3dCreateDevice gets our device, so every pddi object the game creates from then on is ours; the pddi
    # objects' references to the portable bases' functions are bound by address like the tree's own
    gfx = graphics_backend(os.path.join(OUT, "link")) if GFX else None
    if gfx and gfx["objects"]:
        for s in gfx["game_refs"]:
            refs[s] += 1
            undef.add(s)
        defined |= gfx["defined"]
        by_addr_def[GFX_DEVICE_ADDR] = GFX_DEVICE_ENTRY
    # native9: adjustor thunks and pure forwarders re-emitted from the original's bytes (jump_shapes), in place of
    # whatever the tree defines at their addresses (a thunk named by bytes can jump to a source's own stand-in)
    js = jump_shapes(by_addr_def)
    for a, lab in js["labels"].items():
        by_addr_def[a] = lab
        defined.add(lab)
    # --gfx (G3, build/g3/for-native9.md): GameClock::Update 0x00086450 ticks the backend's draw-log frame counter
    # first (the hybrid build hooks the same function), so native draw-log frames are numbered like the hybrid's
    clock_asm = ""
    wrapped = {}            # (native11) a wrapped definition -> its wrapper, for the forwarders jump_shapes re-emitted
    def_before_wrappers = dict(by_addr_def)     # (native10: SITE_REBIND finds a wrapped caller's own definition)
    if gfx and gfx["objects"] and by_addr_def.get(GFX_CLOCK_ADDR) and GFX_CLOCK_TICK in gfx["defined"]:
        # (native10, replay request B: the platform's per-frame hook first, with the clock: the checkpoint hash,
        # src/platform/sdl/xdk/replay_hooks.cpp)
        frame = ("\tpushl\t4(%esp)\n\tcalll\t_hulk_native_frame\n\taddl\t$4, %esp\n"
                 if "_hulk_native_frame" in shim["defined"] else "")
        clock_asm = ("\t.text\n\t.globl\t_hulk_clock_update\n\t.p2align\t4\n_hulk_clock_update:\n\tpushl\t%%eax\n"
                     "\tpushl\t%%ecx\n\tpushl\t%%edx\n%s\tcalll\t%s\n\tpopl\t%%edx\n\tpopl\t%%ecx\n\tpopl\t%%eax\n"
                     '\tjmp\t"%s"\n' % (frame, GFX_CLOCK_TICK, by_addr_def[GFX_CLOCK_ADDR]))
        if frame:
            how["GameClock::Update wrapped: hulk_native_frame (replay checkpoints)"] += 1
        by_addr_def[GFX_CLOCK_ADDR] = "_hulk_clock_update"
        how["GameClock::Update wrapped: hulk_pddi_clock_tick (--gfx)"] += 1
        defined.add("_hulk_clock_update")
    # HULK_TRACE_FUNCS=addr,addr,...: a probe wrapper in front of each of these functions (every caller bound by
    # address and every vftable slot goes through it): it logs `fcall` with ecx, edx, the return address and four
    # stack words (src/platform/sdl/xdk/startup.cpp hulk_trace_func), then jumps to the definition. Probe builds only.
    for t in [int(v, 16) for v in os.environ.get("HULK_TRACE_FUNCS", "").replace(",", " ").split()]:
        d = by_addr_def.get(t)
        if not d:
            continue
        lab = "_hulk_tr_%08x" % t
        wrapped[d] = lab
        clock_asm += ("\t.text\n\t.globl\t%s\n\t.p2align\t4\n%s:\n\tpushl\t%%edx\n\tpushl\t%%ecx\n\tpushl\t%%eax\n"
                      "\tmovl\t%%esp, %%eax\n\tpushl\t%%eax\n\tpushl\t$%d\n\tcalll\t_hulk_trace_func\n\taddl\t$8, %%esp\n"
                      "\tpopl\t%%eax\n\tpopl\t%%ecx\n\tpopl\t%%edx\n\tjmp\t\"%s\"\n" % (lab, lab, t, d))
        by_addr_def[t] = lab
        defined.add(lab)
        how["probe wrapper (HULK_TRACE_FUNCS)"] += 1
    # native14: HULK_TRACE_EXIT=addr,...: probes that also log the return (`fexit`: eax, edx, st0, output buffers;
    # src/platform/sdl/xdk/startup.cpp hulk_trace_enter / hulk_trace_exit): the wrapper logs the entry, swaps the
    # return address for _hulk_tx_ret (the real one waits in hulk_trace_enter's stack) and jumps to the definition;
    # _hulk_tx_ret saves the result registers and st0 (fxam: only when the x87 stack holds one) and returns to the
    # caller. Any calling convention (the callee pops its own arguments). Probe builds only.
    tx = [int(v, 16) for v in os.environ.get("HULK_TRACE_EXIT", "").replace(",", " ").split()]
    if tx and "_hulk_trace_exit" in shim["defined"]:
        clock_asm += ("\t.text\n\t.globl\t_hulk_tx_ret\n\t.p2align\t4\n_hulk_tx_ret:\n\tpushl\t%eax\n\tpushl\t%edx\n"
                      "\tpushl\t%ecx\n\tpushl\t%eax\n\tsubl\t$8, %esp\n\tfxam\n\tfnstsw\t%ax\n\tandl\t$0x4500, %eax\n"
                      "\tcmpl\t$0x4100, %eax\n\tje\t1f\n\tfstl\t(%esp)\n\tmovl\t$1, %eax\n\tjmp\t2f\n1:\n\txorl\t%eax, %eax\n"
                      "2:\n\tmovl\t%esp, %ecx\n\tpushl\t%eax\n\tpushl\t%ecx\n\tleal\t16(%esp), %ecx\n\tpushl\t%ecx\n"
                      "\tcalll\t_hulk_trace_exit\n\taddl\t$20, %esp\n\tmovl\t%eax, 12(%esp)\n\tpopl\t%eax\n\tpopl\t%ecx\n"
                      "\tpopl\t%edx\n\tretl\n")
        defined.add("_hulk_tx_ret")
    for t in tx if "_hulk_trace_exit" in shim["defined"] else []:
        d = by_addr_def.get(t)
        if not d:
            continue
        lab = "_hulk_tx_%08x" % t
        wrapped[d] = lab
        clock_asm += ("\t.text\n\t.globl\t%s\n\t.p2align\t4\n%s:\n\tpushl\t%%edx\n\tpushl\t%%ecx\n\tpushl\t%%eax\n"
                      "\tmovl\t%%esp, %%eax\n\tpushl\t%%eax\n\tpushl\t$%d\n\tcalll\t_hulk_trace_enter\n\taddl\t$8, %%esp\n"
                      "\tmovl\t$_hulk_tx_ret, 12(%%esp)\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tpopl\t%%edx\n\tjmp\t\"%s\"\n"
                      % (lab, lab, t, d))
        by_addr_def[t] = lab
        defined.add(lab)
        how["exit probe wrapper (HULK_TRACE_EXIT)"] += 1
    # native10: the platform's event pump (src/platform/sdl/platform_events.cpp, linked with --gfx), which the
    # shim's main-thread sleeps and waits call (xdk/threads.cpp): a no-op without the graphics objects
    if "_hulk_platform_pump" not in defined:
        clock_asm += "\t.text\n\t.globl\t_hulk_platform_pump\n\t.p2align\t4\n_hulk_platform_pump:\n\tretl\n"
        defined.add("_hulk_platform_pump")
    # native10: ENTRY_HOOKS (the replay pins that act at a function's entry)
    for eh in ENTRY_HOOKS:
        t, hook = eh[0], eh[1]
        skip = eh[3] if len(eh) > 3 else None     # native11: a nonzero hook result returns at once (`ret skip`)
        d = by_addr_def.get(t)
        if not d or hook not in shim["defined"]:
            how["entry hook skipped (no definition or hook): 0x%08x" % t] += 1
            continue
        lab = "_hulk_eh_%08x" % t
        wrapped[d] = lab
        clock_asm += ("\t.text\n\t.globl\t%s\n\t.p2align\t4\n%s:\n\tpushl\t%%edx\n\tpushl\t%%ecx\n\tpushl\t%%eax\n"
                      "\tmovl\t%%esp, %%eax\n\tpushl\t%%eax\n\tcalll\t%s\n\taddl\t$4, %%esp\n" % (lab, lab, hook))
        if skip is None:
            clock_asm += "\tpopl\t%%eax\n\tpopl\t%%ecx\n\tpopl\t%%edx\n\tjmp\t\"%s\"\n" % d
        else:
            clock_asm += ("\ttestl\t%%eax, %%eax\n\tpopl\t%%eax\n\tpopl\t%%ecx\n\tpopl\t%%edx\n\tjnz\t%s_skip\n"
                          "\tjmp\t\"%s\"\n%s_skip:\n\tretl\t$%d\n" % (lab, d, lab, skip))
        by_addr_def[t] = lab
        defined.add(lab)
        how["entry hook (native10) 0x%08x -> %s" % (t, hook)] += 1
    # native11: EXIT_HOOKS (thiscall functions with a hook after them)
    for t, hook, nb, _why, *pre in EXIT_HOOKS:
        d = by_addr_def.get(t)
        if not d or hook not in shim["defined"]:
            how["exit hook skipped (no definition or hook): 0x%08x" % t] += 1
            continue
        lab = "_hulk_xh_%08x" % t
        wrapped[d] = lab
        if pre:   # hook(this, [this+pre] before the call, the first stack argument)
            clock_asm += ("\t.text\n\t.globl\t%s\n\t.p2align\t4\n%s:\n\tpushl\t%%ecx\n\tpushl\t%d(%%ecx)\n"
                          % (lab, lab, pre[0])
                          + "\tpushl\t%d(%%esp)\n" % (nb + 8) * (nb // 4)
                          + "\tmovl\t%d(%%esp), %%ecx\n\tcalll\t\"%s\"\n" % (nb + 4, d)
                          + "\tpushl\t%%eax\n\tpushl\t16(%%esp)\n\tpushl\t8(%%esp)\n\tpushl\t16(%%esp)\n\tcalll\t%s\n"
                            "\taddl\t$12, %%esp\n\tpopl\t%%eax\n\taddl\t$4, %%esp\n\tpopl\t%%ecx\n\tretl\t$%d\n" % (hook, nb))
        else:
            clock_asm += ("\t.text\n\t.globl\t%s\n\t.p2align\t4\n%s:\n\tpushl\t%%ecx\n" % (lab, lab)
                          + "\tpushl\t%d(%%esp)\n" % (nb + 4) * (nb // 4)
                          + "\tmovl\t%d(%%esp), %%ecx\n\tcalll\t\"%s\"\n" % (nb, d)
                          + "\tpushl\t%%eax\n\tpushl\t4(%%esp)\n\tcalll\t%s\n\taddl\t$4, %%esp\n"
                            "\tpopl\t%%eax\n\tpopl\t%%ecx\n\tretl\t$%d\n" % (hook, nb))
        by_addr_def[t] = lab
        defined.add(lab)
        how["exit hook (native11) 0x%08x -> %s" % (t, hook)] += 1
    # native11: a forwarder re-emitted by jump_shapes before the wrappers existed (`mov ecx, [ecx+0xb8]; jmp
    # 0x272fc0`, the drive's post: request H's exit hook was never reached) jumps to the wrapper too
    for d, lab in wrapped.items():
        n_ = js["asm"].count('\tjmp\t"%s"\n' % d)
        if n_:
            js["asm"] = js["asm"].replace('\tjmp\t"%s"\n' % d, "\tjmp\t%s\n" % lab)
            how["re-emitted forwarders pointed at a wrapper (native11)"] += n_
    # fix 6a: the game's vftables and RTTI structures as data (build/native/link/vtables.s), named by address
    vt = code_owned_data(by_addr_def)
    vt["asm"] += js["asm"] + clock_asm
    for a, lab in vt["labels"].items():
        by_addr_def.setdefault(a, lab)
    # native9: stand-in bodies. A verified source that defines its callee itself (`pure3d::Sprite::~Sprite() {}`
    # matched as the scalar deleting destructor 0x002be420, whose call is to the real destructor 0x002bd430): the
    # byte match masks the call, so natively it ran the empty stand-in (here: then called a base destructor nobody
    # defines). Every such symbol (bindings.json local_code: the address each verified call of it goes to) that is
    # not itself the tree's definition of some address is renamed away in the objects defining it, their own calls
    # are pointed at the definition of that address, and every other reference is aliased to it.
    standin = {}
    def_values = set(by_addr_def.values())
    for s_, a_ in (local_code or {}).items():
        if s_ not in defined or s_ in def_values:
            continue
        a_ = int(a_, 16)
        d = by_addr_def.get(a_) or by_addr_def.get(final_target(a_))
        if d and d != s_:
            standin[s_] = d
    standin_objs = collections.defaultdict(dict)
    for o, (d_, u) in syms.items():
        for s_ in d_ & set(standin):
            standin_objs[o][s_] = standin[s_]
    for s_, d in standin.items():
        aliases[s_] = d
        defined.discard(s_)
    how["stand-in bodies replaced by the callee's definition"] = len(standin)
    # native9: a symbol of a wrapped TU (`??0PrimGroupBase@fn_fcb4ee90@@QAE@XZ`) that no relocation bound, whose
    # equivalents in other TUs (the same name without the TU namespace) are all bound to one address: that address
    # (equivalent/0x002e1960's `equiv-map: ??0PrimGroupBase@@QAE@XZ = 0x002a5060` names the standalone symbol)
    by_key = collections.defaultdict(set)
    for s_, b_ in binding.items():
        if "@fn_" in s_:
            by_key[re.sub(r"@fn_[0-9a-f]{8}@", "@", s_)].add(b_["addr"])
    for s in sorted(undef):
        b = binding.get(s)
        if not b and s in DATA_REBIND:
            b = {"addr": DATA_REBIND[s]}
            how["bound by DATA_REBIND (a symbol no relocation names)"] += 1
        if not b and "@fn_" in s and s not in ambiguous:
            k = by_key.get(re.sub(r"@fn_[0-9a-f]{8}@", "@", s), set())
            if len(k) == 1:
                b = {"addr": next(iter(k))}
                how["bound like the same name in other TUs"] += 1
        a = int(b["addr"], 16) if b else None
        src = "relocation" if b else None
        if a is None:
            a = name_address(s)
            src = "name" if a is not None else None
        if a is None and s in vt["names"]:
            a, src = vt["names"][s], "MSVC vftable/RTTI name (config/data.json)"
        if a is None and shim_key(s) in shim["by_name"]:
            a, src = shim["by_name"][shim_key(s)], "XDK import name (src/platform/sdl/xdk/imports.h)"
        if (a is None or (not by_addr_def.get(a) and not b)) and s not in ambiguous:
            # a CRT function the tree (or clang's own lowering: memcpy, _alldiv, __CxxFrameHandler3) names directly
            hn = host["by_name"].get(native_host.plain_name(s) or "")
            if hn and hn != s:
                aliases[s] = hn
                how["bound by CRT name (src/platform/sdl/crt/host_crt_table.h)"] += 1
                continue
        if a is None:
            continue
        d = by_addr_def.get(a)
        if not d and b:
            # the verified call goes to a thunk (`jmp FUN_x`, the source calls it thunk_FUN_x or FUN_x): its target
            t = jmp_target(a)
            if t is not None and by_addr_def.get(t):
                d, src = by_addr_def[t], "relocation to a thunk, bound to its jump target"
        if d and d != s:
            aliases[s] = d
            how["bound by %s" % src] += 1
        elif b:
            how["relocation's address has no definition in the clang objects"] += 1
    # fix 3a: virtual members of stub classes, named only by a clang-emitted stub vftable: slot N of the
    # game's vftable the stub stands for (its address: where the verified code stores the stub's vftable)
    slot_how = collections.Counter()
    slot_of = {}
    slot_aliases = stub_slot_aliases(sorted(objs.values()), binding, by_addr_def, undef - set(aliases), slot_how, slot_of)
    for s, d in slot_aliases.items():
        aliases[s] = d
        how["stub vftable slot"] += 1
    with open(os.path.join(OUT, "slot_aliases.json"), "w") as f:      # (native_conv_check check 10 reads it)
        json.dump(slot_aliases, f, indent=0)
    # the 329-style ambiguous symbols: one callee per TU -> the symbol is renamed in that TU's object
    renames, renamed_all = collections.defaultdict(list), set()
    obj_tu = {o: p for p, o in objs.items()}
    for s in sorted(undef - set(aliases)):
        per = (amb_tu or {}).get(s)
        if not per:
            continue
        users = [o for o, (d, u) in syms.items() if s in u]
        done = 0
        for o in users:
            a_ = per.get(obj_tu.get(o))
            d = by_addr_def.get(int(a_, 16)) if a_ else None
            if d:
                new = "%s$%s" % (s, hashlib.sha1(obj_tu[o].encode()).hexdigest()[:8])
                renames[o].append((s, new))
                aliases[new] = d
                done += 1
        if users and done == len(users):
            renamed_all.add(s)
            how["ambiguous: renamed per object"] += 1
        elif done:
            how["ambiguous: renamed in some objects"] += 1
    # the rest: one callee per calling function -> each relocation is rebound by the function it is in
    rebind = collections.defaultdict(dict)
    rebind_interior = {}        # native9: a rebound name whose address lies inside a data item: (item, offset)
    items0, starts0 = native_host.data_items()
    defined_at0 = {a: s for a, s in data_defs.items() if s in defined}
    for a, lab in vt["labels"].items():
        defined_at0.setdefault(a, lab)
    for s in sorted(set(amb_fn or {}) - renamed_all):
        per = (amb_fn or {}).get(s)
        if not per:
            continue
        plan = {}
        for fn, a_ in per.items():
            d = by_addr_def.get(int(a_, 16))
            if d:
                if d == s or d == aliases.get(s):
                    continue
                new = "%s$%s" % (s, a_[2:])
                plan[fn] = new
                aliases[new] = d
            else:
                c = native_host.container(int(a_, 16), items0, starts0, defined_at0)
                if c:
                    new = "%s$%s" % (s, a_[2:])
                    plan[fn] = new
                    rebind_interior[new] = c
                    aliases[new] = c[0]     # (the name stays in the symbol table, unreferenced once retargeted)
        if not plan:
            continue
        for o, (d_, u) in syms.items():
            if s in u or s in d_:
                rebind[o][s] = plan
        how["rebound per calling function (%s)" % ("ambiguous" if s in undef else "name means another address")] += 1
    how["rebound to an address inside a data item"] = len(rebind_interior)
    # native10: call sites bound to a platform function of their own (SITE_REBIND): the calls one function makes to
    # one callee go to another definition (the pad constructor's reads that are not polls, ...)
    site_stats = site_rebind(syms, binding, aliases, def_before_wrappers, defined, rebind)
    how.update(site_stats)
    after = undef - set(aliases) - renamed_all
    # an address inside a data item another object defines (a global at +0x4c of a data TU's `DAT_<start>`, an
    # interior label of a vftable item): the referencing objects are patched to name the item, offset in the addend
    items, starts = native_host.data_items()
    defined_at = {a: s for a, s in data_defs.items() if s in defined}
    for a, lab in vt["labels"].items():
        defined_at.setdefault(a, lab)
    interior = {}
    own_rows = native_host.host_tables()[2] + native_host.library_table()[1]
    for s in sorted(after):
        b = binding.get(s) or ({"addr": DATA_REBIND[s]} if s in DATA_REBIND else None)    # (unb1: DATA_REBIND into an item)
        a = int(b["addr"], 16) if b else name_address(s)
        if a is None or by_addr_def.get(a):
            continue
        c = next(((sym, a - s0) for s0, sym, n in own_rows if s0 < a < s0 + n), None) or \
            native_host.container(a, items, starts, defined_at)
        if c:
            interior[s] = c
    after -= set(interior)
    after -= defined          # (defined by the platform objects: __fltused, the sized operator delete, ...)
    retarget = collections.defaultdict(dict)
    for o, (d_, u) in syms.items():
        for s in u & set(interior):
            retarget[o][s] = interior[s]
    # clang's own vftables of stub classes (`??_7MemoryDlAllocator@core@fn_0026ce90@@6B@`, emitted where verified
    # code constructs the stub): the verification proved which game vftable each vptr store writes (the binding
    # map's address), so the stores and other references are pointed at the game's vftable (vtables.s; its slots
    # are the tree's definitions) instead of the stub's, whose slots name members nobody defines
    vitems = [(int(it["addr"], 16), it["size"]) for it in items if it["kind"] == "vtable"]
    vstarts = [a for a, _ in vitems]
    vt_map = {}
    for s in defined:
        if not s.startswith("??_7"):
            continue
        b = binding.get(s)
        if not b:
            continue
        a = int(b["addr"], 16)
        lab = vt["labels"].get(a)
        if lab:
            vt_map[s] = (lab, 0)
            continue
        k = bisect.bisect_right(vstarts, a) - 1
        if k >= 0 and a < vitems[k][0] + vitems[k][1] and vt["labels"].get(vitems[k][0]):
            vt_map[s] = (vt["labels"][vitems[k][0]], a - vitems[k][0])
    # native9: clang's RTTI type descriptors (`??_R0?AVObjectLoader@content@fn_f638de75@@@8`: a wrapped source's
    # class carries the TU's namespace in its decorated name) pointed at the game's descriptor of the same class
    # (config/data.json `??_R0.?AVObjectLoader@content@@@8`): __RTDynamicCast and typeid compare decorated names,
    # and the objects' vftables are the game's, whose hierarchies name the game's classes; with the TU namespace
    # every dynamic_cast in a wrapped source failed (P3DFileHandler 0x00265cd0: no SimpleChunkHandler)
    n_td = 0
    leaf = collections.defaultdict(set)     # `?AVTextureLoader@` -> game TD names (a source's class without its namespace)
    for g in vt["names"]:
        m = re.match(r"\?\?_R0\.(\?A[UV]\w+@)", g)
        if m:
            leaf[m.group(1)].add(g)
    for s in defined:
        if not s.startswith("??_R0?") or s in vt_map:
            continue
        g = "??_R0." + re.sub(r"fn_[0-9a-f]{8}@", "", s[5:])
        if g not in vt["names"]:
            # native12: a class renamed with its source's address (`AnimationLoader_2abfb0`: the consolidation's
            # unclash renames, x64-1 b1-b7) is still the game's class for dynamic_cast / typeid: the stripped
            # name, if the game has that descriptor (equivalent/0x002abfb0: the particle loader's cast to
            # pure3d::AnimationLoader returned null, play3 crashed before frame 30)
            g2 = re.sub(r"_[0-9a-f]{6}@", "@", g)
            if g2 in vt["names"]:
                g = g2
                how["RTTI type descriptors matched without an address suffix (native12)"] += 1
        if g not in vt["names"]:
            m = re.match(r"\?\?_R0(\?A[UV]\w+@)", s)
            lf = re.sub(r"_[0-9a-f]{6}@$", "@", m.group(1)) if m else None      # (native12: as above)
            cands = {x for k in ("?AU", "?AV") for x in leaf.get(k + m.group(1)[3:], ()) or leaf.get(k + lf[3:], ())} if m else set()
            if len(cands) == 1:
                g = cands.pop()
        a = vt["names"].get(g)
        if a is not None and vt["labels"].get(a):
            vt_map[s] = (vt["labels"][a], 0)
            n_td += 1
    how["RTTI type descriptors pointed at the game's (by decorated name)"] += n_td
    vt_rebind = collections.defaultdict(dict)
    for o, (d_, u) in syms.items():
        for s in (d_ | u) & set(vt_map):
            vt_rebind[o][s] = vt_map[s]
    how["stub vftable references pointed at the game's vftable"] += len(vt_map) - n_td
    # data a verified source defines itself where the original uses the game's item (local_data_bindings): every
    # reference is pointed at the game's item (data.s label, a library slot, or an interior offset of an item)
    ld_map = {}
    for s_, a_ in (local_data or {}).items():
        if s_ not in defined:
            continue
        a_ = int(a_, 16)
        d = by_addr_def.get(a_) or defined_at.get(a_)
        if d and d != s_:
            ld_map[s_] = (d, 0)
            continue
        c = next(((sym, a_ - s0) for s0, sym, n in own_rows if s0 <= a_ < s0 + n), None) or \
            native_host.container(a_, items, starts, defined_at)
        if c:
            ld_map[s_] = c
    for o, (d_, u) in syms.items():
        for s_ in (d_ | u) & set(ld_map):
            vt_rebind[o][s_] = ld_map[s_]
    how["source-defined globals pointed at the game's item"] += len(ld_map)
    # a game initializer whose source is the dynamic initializer itself (an isolated `.text$yc` source defining a
    # global with a constructor: MSVC's `$E1`): clang's equivalent is the TU's local `__GLOBAL__sub_I_<file>`, made
    # global in a copy of the object so the start-up table can call it in the XBE's order
    globalize = collections.defaultdict(list)
    for c in tree_checks():
        if not re.fullmatch(r"_\$E\d+", c.get("symbol") or "") or c["status"] != "match" or c["tu"] not in objs:
            continue
        o = objs[c["tu"]]
        name = "__GLOBAL__sub_I_" + os.path.basename(c["tu"])
        try:
            have = any(sy[0] == name for sy in compare.Coff(o).symbols)
        except Exception:  # noqa: BLE001
            have = False
        if have:
            globalize[o].append(name)
            by_addr_def[int(c["addr"], 16)] = name
            defined.add(name)
            how["game initializer bound to clang's own dynamic initializer"] += 1
    # the start-up table (build/native/link/startup.s) and the game's main
    startup, start_st = native_host.startup_asm(xbe(), by_addr_def)
    if by_addr_def.get(native_host.MAIN_ADDR):
        aliases["_hulk_game_main"] = by_addr_def[native_host.MAIN_ADDR]
    ok_tus = {p for p in tus if res[p]["rc"] == 0}
    before_g = cp.group_undefined(undef, refs, man, ok_tus)
    after_g = cp.group_undefined(after, refs, man, ok_tus)
    dem = cp.undname(sorted(after))
    for s in after:
        # the stub-name symbols left are mostly virtual members of TU-local stub classes: clang emits the stub's
        # vftable (MSVC /O2 drops it), and no verified function's relocation names them
        if after_g[s] == cp.G_STUB:
            b = binding.get(s)
            after_g[s] = ("%s: virtual member of a stub class (only in a clang-emitted stub vftable)" % cp.G_STUB
                          if "virtual" in dem.get(s, "") and not b else
                          "%s: bound to an address with no verified definition" % cp.G_STUB if b else
                          "%s: ambiguous (bound to two addresses)" % cp.G_STUB if s in ambiguous else
                          "%s: no relocation names it" % cp.G_STUB)
    with open(os.path.join(OUT, "unbound.txt"), "w") as f:
        for s in sorted(after, key=lambda s: (after_g[s], -refs[s], s)):
            f.write("%s\t%d\t%s\t%s\n" % (after_g[s], refs[s], s, dem.get(s, s)))

    def tally(g, which):
        t = collections.defaultdict(lambda: [0, 0])
        for s in which:
            t[g[s]][0] += 1
            t[g[s]][1] += refs[s]
        return {k: {"symbols": v[0], "references": v[1]} for k, v in sorted(t.items(), key=lambda kv: -kv[1][0])}
    inv = {"code_tus_compiling": len(ok_tus), "tus": len(tus), "objects": len(objs),
           "undefined_before": {"symbols": len(undef), "references": sum(refs[s] for s in undef),
                                "groups": tally(before_g, undef)},
           "aliases": len(aliases), "aliases_by_source": dict(how), "stub_vftable_slots": dict(slot_how),
           "code_owned_data": vt["stats"], "jump_shapes": js["stats"], "deleting_destructors": dd["stats"], "platform_shim": shim["stats"],
           "host_crt": dict(host["stats"]), "library_shim": lib["stats"], "startup": start_st,
           "graphics": dict(gfx["stats"], unresolved=gfx["unresolved"],
                            game_refs_unbound=sorted(s for s in gfx["game_refs"] if s not in aliases))
           if gfx else None,
           "interior_retargeted_objects": len(retarget),
           "undefined_after": {"symbols": len(after), "references": sum(refs[s] for s in after),
                               "groups": tally(after_g, after)}}
    if do_link:
        link_objs, data_objs = [], []
        for o in sorted(objs.values()):
            if standin_objs.get(o):
                renames[o] = renames[o] + [(s_, s_ + "$standin") for s_ in sorted(standin_objs[o])]
            o2 = rename_object(o, renames[o]) if renames.get(o) else o
            if standin_objs.get(o):
                out_o = os.path.join(OUT, "link", "objs", "si_" + os.path.basename(o))
                os.makedirs(os.path.dirname(out_o), exist_ok=True)
                native_host.retarget_relocs(o2, {s_ + "$standin": (d, 0) for s_, d in standin_objs[o].items()}, out_o,
                                            own=True)
                o2 = out_o
            if globalize.get(o):
                out_o = os.path.join(OUT, "link", "objs", "gl_" + os.path.basename(o))
                os.makedirs(os.path.dirname(out_o), exist_ok=True)
                if native_host.globalize_object(o2, set(globalize[o]), out_o):
                    o2 = out_o
            if rebind.get(o):
                out_o = os.path.join(OUT, "link", "objs", "rb_" + os.path.basename(o))
                os.makedirs(os.path.dirname(out_o), exist_ok=True)
                left = native_host.rebind_object(o2, rebind[o], out_o)
                o2 = out_o
                after |= left - defined - set(aliases)     # relocations the plan leaves keep the old name (an alias may cover it)
                inner = {n_: rebind_interior[n_] for pl in rebind[o].values() for n_ in pl.values() if n_ in rebind_interior}
                if inner:
                    out_o = os.path.join(OUT, "link", "objs", "ri_" + os.path.basename(o))
                    native_host.retarget_relocs(o2, inner, out_o)
                    o2 = out_o
                    after -= set(inner)
            if vt_rebind.get(o):
                out_o = os.path.join(OUT, "link", "objs", "vt_" + os.path.basename(o))
                os.makedirs(os.path.dirname(out_o), exist_ok=True)
                native_host.retarget_relocs(o2, vt_rebind[o], out_o)
                o2 = out_o
            if retarget.get(o):
                out_o = os.path.join(OUT, "link", "objs", "rt_" + os.path.basename(o))
                os.makedirs(os.path.dirname(out_o), exist_ok=True)
                native_host.retarget_object(o2, retarget[o], out_o)
                o2 = out_o
            if obj_tu.get(o, "").startswith("data/src/"):
                data_objs.append(o2)
                continue
            link_objs.append(o2)
        # the data TUs' items at the XBE's distances (build/native/link/data.s) instead of the data TU objects
        blk = native_host.data_block(xbe(), data_objs, want=after | vt["undefined"])
        link_objs += [o for o in data_objs if o not in set(blk["objects_used"])]
        inv["data_block"] = blk["stats"]
        if blk["mismatch"]:
            inv["data_block_mismatch"] = blk["mismatch"]
        link_objs += shim["objects"] + host["objects"]
        if gfx and gfx["objects"]:
            link_objs += gfx["objects"]
        # a virtual member of a stub class that clang calls directly (`sub.F0()` on a member object: clang
        # devirtualizes, MSVC 7.1 called through the vftable) and that nothing defines: its stub dispatches through
        # the object's vftable at the member's slot, as the original's call did
        vthunks = {s_: n for s_, n in slot_of.items() if s_ in after}
        for s_, n in source_slots(after - set(vthunks), man).items():
            vthunks[s_] = n
        inv["virtual_dispatch_stubs"] = len(vthunks)
        inv["lld_link"] = lld_link(link_objs, aliases, (after | vt["undefined"] | set(gfx["unresolved"] if gfx else ()))
                                   - blk["defined"],
                                   vt["asm"], dd["asm"], startup,
                                   host["libs"] + (gfx["libs"] if gfx and gfx["objects"] else []) + SDL_LIBS,
                                   data_asm=blk["asm"], vthunks=vthunks)
    return inv


# ---------------------------------------------------------------------------------------------
# native10: per-call-site bindings to platform functions (build/rp1/for-native9.md, docs/native-replay.md)
# (caller address, callee address, the platform definition its calls go to instead, why)
# sky1: data symbols the verified sources name but no relocation binds (build/native/unbound.txt, "no relocation names
# it"): they linked as zero stubs. `float pure3d::scenegraph::one` (matches/0x00295e20.cpp, Node::vfunc_17's
# `return &one` for a node with no parent) is the identity Matrix at 0x004c9f38 (tbl_004c9f38 in config/data.json); as
# a stub every TransformNode's world matrix was local x 0 (the sky and every static scenegraph object drew nothing).
# unb1: the audit of the rest ("no relocation names it" + data symbols no relocation reaches; build/unb1/notes.md).
# `g2` (matches/0x0024e4c0.cpp): MSVC inlined TypeT_24e4c0's constructor into the function, so the verified relocation
# is in `target` (0x4e6358, ambiguous with `Target`'s 0x4e6348, which is rebound per function); clang keeps the
# constructor out of line, its reference to `g2` was left to the zero stub (bss at 0x4e6358: the pool bookkeeping the
# temporary type object points at). `g_pool_2579f0` (matches/0x002579f0.cpp's operator delete): the audio pool at
# 0x004e7620, inside DAT_004e75b8 (the interior retarget below). `_rttiBCA_00487908`: the base class array that
# PTR_00438880 (data.s) points into at +4; tools/data_gen.py names it by kind and ADDR_RX does not match "rttiBCA".
DATA_REBIND = {"?one@scenegraph@pure3d@@3MA": "0x004c9f38",
               "?g2@fn_fb3c10a1@@3DA": "0x004e6358",
               "?g_pool_2579f0@fn_002579f0@@3PADA": "0x004e7620",
               "_rttiBCA_00487908": "0x00487908"}

SITE_REBIND = [
    (0x002692c0, 0x003eb91f, "_hulk_xdk_XInputGetStateInit@8",
     "ControllerSystemXBox's pad object constructor reads a new pad 20 times: not polls (replay request A)"),
    (0x00086450, 0x00267f40, "_hulk_clock_tick",
     "GameClock::Update's time: fixed dt / the virtual clock with a replay or HULK_VCLOCK=1 (request D; xdk/timing.cpp)"),
    (0x00087e30, 0x00267f40, "_hulk_clock_now", "the GameClock constructor's first timestamp (request D)"),
    (0x00086630, 0x00267f00, "_hulk_replay_seed", "the new-game reseed: the recording's seed (request E)"),
    (0x001c1a40, 0x00344e74, "_hulk_cast_self",
     "--gfx: HulkShaderCallback's dynamic_cast of the pddi framebuffer-effects extension (ours, no game RTTI): the "
     "extension is that type (build/g4/for-native10.md 8; xdk/library.cpp)"),
    # native11, request G (sound-rng, seq-rng; xdk/replay_hooks.cpp): the hybrid's per-site patches, here per caller
    # (each caller below makes only the patched calls to its callee: read off the original)
    (0x001ef2a0, 0x000964d0, "_hulk_sound_rng", "sound-rng: the sound manager caches the RNG it draws from (0x1ef2ca)"),
    (0x001efe20, 0x000964d0, "_hulk_sound_rng", "sound-rng: 0x1efe8d"),
    (0x001f7320, 0x000964d0, "_hulk_sound_rng", "sound-rng: the voices' draws (0x1f7362, 0x1f74b7)"),
    (0x00260ae0, 0x0034774c, "_hulk_sound_rand", "sound-rng: audio sequencing's rand() (0x260ae2)"),
    (0x002526b0, 0x004e5acc, "_hulk_seq_rng_ptr", "seq-rng: SeqActionVarVolumeRand::vfunc_1 reads the RNG pointer (0x2526cc)"),
    (0x00253680, 0x004e5acc, "_hulk_seq_rng_ptr", "seq-rng: SeqActionVarPitchRand::vfunc_1 (0x25369c)"),
    (0x00255250, 0x004e5acc, "_hulk_seq_rng_ptr", "seq-rng: SeqCommandLogicOr::vfunc_0 (0x25527f)"),
    (0x002549a0, 0x000113e0, "_hulk_seq_randint", "seq-rng: SeqEventSilence::vfunc_2 -> RandInt (0x2549c9)"),
    (0x00254c80, 0x000113e0, "_hulk_seq_randint", "seq-rng: SeqEventLogicRepeat's state -> RandInt (0x254ca8)"),
]
# native11: exit hooks: a wrapper calls the (thiscall) definition with the caller's stack arguments, then
# `void hook(u32 this)`, then returns as the definition did (eax kept). (address, hook, argument bytes, why)
EXIT_HOOKS = [
    # native15: (..., pre) = the hook is `hook(this, word, first argument)` with the dword at this+pre read before the
    # call (the drive's request count before the post) and the call's first stack argument (the posted request)
    (0x00272fc0, "_hulk_hook_drive_post", 12,
     "core::DriveThread's post: the main thread waits for the drive to go idle (request H, syncio)", 0x8c),
]
# native10: entry hooks: a wrapper in front of the function (every caller bound by address and every vftable slot
# goes through it, as HULK_TRACE_FUNCS' probes) calls `int hook(u32* regs)` (eax, ecx, edx, the return address, the
# arguments), then jumps to the definition. (address, hook, why)
ENTRY_HOOKS = [
    (0x00269170, "_hulk_hook_pad_poll",
     "ControllerSystemXBox::vfunc_12: the poll's rate limit off with a recording open (request C)"),
    # native11, request F no-fmv (tools/patch_xbe.py TWEAKS): (address, hook, why, bytes `ret` pops when it skips)
    (0x001b7310, "_hulk_hook_fmv_queue",
     "no-fmv: CFMVManager::QueueMovie returns at once (the hybrid's `ret 0xc` at its entry)", 12),
    # native17: core::Drive::vfunc_3, the main thread's drive pump (completed requests are delivered here): the drive
    # threads run their queued steps first, in lockstep with the main thread (xdk/replay_hooks.cpp HULK_SYNCIO=5)
    (0x00272df0, "_hulk_hook_drive_pump",
     "core::Drive::vfunc_3: the drive threads' turn before the main thread collects completions (lockstep I/O)"),
    (0x001b7d10, "_hulk_hook_fmv_render",
     "no-fmv: the FMV render reads the movie's status as 0 (finished) and stops it (the hybrid's `xor eax, eax` "
     "for the call at 0x1b7d38): the hook takes that path itself", 8),
]


def site_rebind(syms, binding, aliases, by_addr_def, defined, rebind):
    """Add SITE_REBIND's plans to `rebind` ({object: {symbol: {function symbol: new symbol}}}): in the object that
    defines the caller, the relocations of the caller's body that name the callee (an undefined symbol bound to
    the callee's address, by the binding map or by its name) are pointed at the new definition. Returns stats."""
    st = collections.Counter()
    for caller, callee, new, _why in SITE_REBIND:
        fn = by_addr_def.get(caller)
        if not fn or new not in defined:
            st["site rebinding skipped (caller or new definition missing): 0x%08x" % caller] += 1
            continue
        target = by_addr_def.get(callee)
        hit = 0
        for o, (d_, u) in syms.items():
            if fn not in d_:
                continue
            for s in u | (d_ - {fn}):
                b = binding.get(s)
                a = int(b["addr"], 16) if b else name_address(s)
                if a == callee or (target and (aliases.get(s) == target or s == target)):
                    plan = dict(rebind[o].get(s, {}))     # (amb_fn shares one plan between objects)
                    plan[fn] = new
                    rebind[o][s] = plan
                    hit += 1
        st["site rebinding (native10) 0x%08x -> %s" % (caller, new)] += hit
    return st


# ---------------------------------------------------------------------------------------------
# The graphics backend (docs/graphics-backend.md G1, build/g0/LINK.md): --gfx / HULK_NATIVE_GFX=1
GFX = os.environ.get("HULK_NATIVE_GFX") == "1"
GFX_OUT = os.environ.get("HULK_GFX_OUT") or os.path.join(ROOT, "build/third_party/out")   # tools/native_gfx.py
GFX_DEVICE_ADDR = 0x0031ba60            # d3dCreateDevice (pure3d::InitPlatform 0x00292560, its only caller)
GFX_DEVICE_ENTRY = "_hulk_pddi_create_device"
GFX_CLOCK_ADDR = 0x00086450             # GameClock::Update (build/g3/for-native9.md: the draw log's frame numbers)
GFX_CLOCK_TICK = "_hulk_pddi_clock_tick"
GFX_KEEP = {"__fltused", "@feat.00"}    # the image's own (src/platform/sdl/crt/crt_glue.cpp)
# Which DLL each Windows function bgfx/bx and the pddi backend import comes from (stdcall names; everything cdecl is
# msvcrt.dll's, the compiler helpers ntdll.dll's). A name missing here is reported, not guessed.
GFX_DLLS = {
    "kernel32": set("""CloseHandle CreateProcessA CreateSemaphoreA CreateThread DeleteCriticalSection EnterCriticalSection
        FindClose FindFirstFileExW FindNextFileW FreeLibrary GetCommandLineW GetCurrentProcess GetCurrentThreadId
        GetEnvironmentVariableW GetExitCodeThread GetFullPathNameW GetLargePageMinimum GetLastError GetModuleFileNameW
        GetModuleHandleA GetModuleHandleW GetNativeSystemInfo GetProcAddress GetStdHandle GetSystemInfo GetTempPathW
        InitializeCriticalSection IsDebuggerPresent LeaveCriticalSection LoadLibraryA LoadLibraryExW LoadLibraryW
        MoveFileExW OutputDebugStringA QueryPerformanceCounter QueryPerformanceFrequency ReleaseSemaphore
        SetEnvironmentVariableW SetErrorMode Sleep SwitchToThread TerminateProcess TlsAlloc TlsFree TlsGetValue
        TlsSetValue VirtualAlloc VirtualFree VirtualProtect WaitForSingleObject WaitForSingleObjectEx WriteFile
        CreateFileA ExitProcess GetTickCount K32EnumProcessModules K32GetModuleBaseNameA
        K32GetProcessMemoryInfo""".split()),
    "user32": set("""AdjustWindowRect AdjustWindowRectEx CreateWindowExA CreateWindowExW DefWindowProcA DefWindowProcW
        DestroyWindow DispatchMessageA GetClientRect GetDC LoadCursorA LoadIconA PeekMessageA RegisterClassA
        RegisterClassExA ReleaseDC SetWindowPos SetWindowTextA ShowWindow TranslateMessage UpdateWindow""".split()),
    "gdi32": set("ChoosePixelFormat DescribePixelFormat GetPixelFormat SetPixelFormat SwapBuffers".split()),
    "ntdll": set("_alldiv _allrem _aulldiv _aullrem _allmul _allshl _allshr _aullshr _chkstk".split()),
}
GFX_CXX = {"??2@YAPAXI@Z": "op_new", "??3@YAXPAX@Z": "op_delete", "??_U@YAPAXI@Z": "op_new_array",
           "??_V@YAXPAX@Z": "op_delete_array"}


def gfx_nm(paths):
    """(defined, undefined) external symbols over objects and archives (every member)."""
    d, u = set(), set()
    p = subprocess.run([os.path.join(native_host.LLVM, "llvm-nm"), "--no-sort"] + list(paths),
                       capture_output=True, text=True, errors="replace")
    for line in p.stdout.splitlines():
        parts = line.split()
        if len(parts) == 2 and parts[0] == "U":
            u.add(parts[1])
        elif len(parts) == 3 and parts[1] in "TDBRCVW":
            d.add(parts[2])
    return d, u


def gfx_import(s):
    """(dll, renamed symbol, .def line) for one host name the graphics objects import, or None."""
    m = re.fullmatch(r"(__imp_)?_(\w+?)(@\d+)", s)            # stdcall: Windows API
    if m:
        name = m.group(2)
        dll = next((k for k in ("kernel32", "user32", "gdi32") if name in GFX_DLLS[k]), None)
        if not dll:
            return None
        return dll, "%s_hulk_gfx_%s%s" % (m.group(1) or "", name, m.group(3)), \
            "hulk_gfx_%s%s == %s" % (name, m.group(3), name)
    if s in GFX_CXX:
        return "msvcrt", "_hulk_gfx_" + GFX_CXX[s], "hulk_gfx_%s == %s" % (GFX_CXX[s], s)
    m = re.fullmatch(r"(__imp_)?_(\w+)", s)                     # cdecl: the C runtime and compiler helpers
    if m:
        name = m.group(2)
        dll = "ntdll" if name in GFX_DLLS["ntdll"] else "msvcrt"
        return dll, "%s_hulk_gfx_%s" % (m.group(1) or "", name), "hulk_gfx_%s == %s" % (name, name)
    return None


def graphics_backend(outdir):
    """The pddi backend and bgfx for the native image (--gfx; build/g0/LINK.md, docs/graphics-backend.md G1).

    Inputs (tools/native_gfx.py build --target win32 + pddi --target win32): the pddi objects
    (out/pddi-win32/obj/*.obj, linked as objects: they define the device entry point) and bgfx/bimg/bx.lib.
    Every host function they import is renamed to `hulk_gfx_<name>` in copies of the objects and libraries
    (build/native/link/gfx/) and comes from import libraries of our own (`hulk_gfx_X == X`): the graphics side
    calls msvcrt.dll / kernel32 / user32 / gdi32 / ntdll directly, while the tree's references of the same plain
    names (`_free`, `_memcpy`, `??3@YAXPAX@Z`, `_CloseHandle@4`, ...) keep their bindings to the game's heap, the
    host CRT and the XDK shim. The pddi objects' `FUN_<address>` references (hulk::pddi::GameBase, the portable
    pddi bases' own functions) are returned for the address binding; d3dCreateDevice is bound to
    hulk_pddi_create_device by the caller."""
    st = collections.Counter()
    out = {"objects": [], "libs": [], "game_refs": set(), "defined": set(), "unresolved": [], "stats": st}
    objs = sorted(os.path.join(GFX_OUT, "pddi-win32/obj", f) for f in os.listdir(os.path.join(GFX_OUT, "pddi-win32/obj"))
                  if f.endswith(".obj")) if os.path.isdir(os.path.join(GFX_OUT, "pddi-win32/obj")) else []
    libs = [os.path.join(GFX_OUT, "win32/lib/%s.lib" % n) for n in ("bgfx", "bimg", "bx")]
    if not objs or not all(os.path.exists(l) for l in libs):
        st["not built (tools/native_gfx.py build --target win32; pddi --target win32)"] += 1
        return out
    d_obj, _u = gfx_nm(objs)
    d_all, u_all = gfx_nm(objs + libs)
    renames, imports = {}, collections.defaultdict(set)
    for s in sorted(u_all - d_all):
        if s in GFX_KEEP or s.startswith("_hulk_native_"):
            continue          # (the image's own: the trace sink in src/platform/sdl/xdk/startup.cpp, ...)
        if ADDR_RX.search(s if s.startswith("?") else "_" + s.lstrip("_@")):
            out["game_refs"].add(s)
            continue
        r = gfx_import(s)
        if r is None:
            out["unresolved"].append(s)
            continue
        dll, new, line = r
        renames[s] = new
        imports[dll].add(line)
    st["pddi objects"] = len(objs)
    st["GameBase references (bound by address)"] = len(out["game_refs"])
    st["host imports renamed hulk_gfx_"] = len(renames)
    st["host imports without a DLL (stubbed)"] = len(out["unresolved"])
    gd = os.path.join(outdir, "gfx")
    os.makedirs(os.path.join(gd, "obj"), exist_ok=True)
    for dll, lines in sorted(imports.items()):
        df = os.path.join(gd, "gfx_%s.def" % dll)
        with open(df, "w") as f:
            f.write("LIBRARY %s.dll\nEXPORTS\n%s\n" % (dll, "\n".join(sorted(lines))))
        lib = os.path.join(gd, "gfx_%s.lib" % dll)
        r = subprocess.run([os.path.join(native_host.LLVM, "llvm-dlltool"), "-m", "i386", "-d", df,
                            "-l", lib], capture_output=True, text=True)
        if r.returncode:
            raise RuntimeError("llvm-dlltool %s: %s" % (dll, r.stderr[-1000:]))
        out["libs"].append(lib)
    lst = os.path.join(gd, "renames.txt")
    with open(lst, "w") as f:
        f.write("".join("%s %s\n" % kv for kv in sorted(renames.items())))
    for src, dst_dir in [(o, os.path.join(gd, "obj")) for o in objs] + [(l, gd) for l in libs]:
        dst = os.path.join(dst_dir, os.path.basename(src))
        r = subprocess.run([native_host.LLVM + "/llvm-objcopy", "--redefine-syms=" + lst, src, dst],
                           capture_output=True, text=True)
        if r.returncode:
            raise RuntimeError("llvm-objcopy %s: %s" % (src, r.stderr[-1000:]))
        (out["objects"] if src.endswith(".obj") else out["libs"]).append(dst)
    out["defined"] = d_obj
    if GFX_DEVICE_ENTRY not in d_obj:
        st["device entry point missing"] += 1
    return out


SHIM_DIR = os.path.join(ROOT, "src/platform/sdl/xdk")
# sa1 (docs/native-audio-input.md, build/sa1/for-native9.md): the SDL3 audio/input backends, when tools/native_sdl.py
# has built them; xdk/ is then compiled with HULK_NATIVE_SDL=1 (both or neither). HULK_NATIVE_SDL=0 turns them off.
SDL_OUT = os.environ.get("HULK_SDL_OUT") or os.path.join(ROOT, "build/third_party/out")
SDL_LIBS = [os.path.join(SDL_OUT, "sdl-backends/win32/hulk_sdl.lib"), os.path.join(SDL_OUT, "sdl-win32/SDL3.lib")]
if os.environ.get("HULK_NATIVE_SDL") == "0" or not all(os.path.exists(x) for x in SDL_LIBS):
    SDL_LIBS = []
else:
    # fs1 (build/fs1/for-native9.md): files and saves on SDL3 (tools/native_fs.py backends --target win32); mv1
    # (build/mv1/for-native9.md): the movie player (tools/native_ffmpeg.py movies; FFmpeg is loaded at run time)
    for extra in ("fs1/win32/hulk_fs.lib", "ffmpeg-win32/movies/hulk_movies.lib"):
        if os.path.exists(os.path.join(SDL_OUT, extra)):
            SDL_LIBS.insert(len(SDL_LIBS) - 1, os.path.join(SDL_OUT, extra))
SHIM_RX = re.compile(r"^\s*X\((0x[0-9a-fA-F]{8}), (\w+), ")


def shim_key(sym):
    """The bare function name of a C or MS-mangled symbol (`_CreateFileA@28`, `?CreateFileA@XAPILIB@fn_x@@YG...`)."""
    m = re.match(r"^[?_@]?([A-Za-z_]\w*?)(?:@|$)", sym)
    return m.group(1) if m else None


def platform_shim(cp):  # noqa: C901
    """Compile src/platform/sdl/xdk/ (the XDK import stand-ins; native builds only) for i686-pc-windows-msvc.

    imports.h's HULK_XDK_IMPORT table gives each stand-in's XBE address; every symbol the tree calls that address
    by (bindings) or that function's name by is aliased to the stand-in `hulk_xdk_<name>`."""
    st = collections.Counter()
    out = {"objects": [], "defined": set(), "by_addr": {}, "by_name": {}, "stats": st}
    hdr = os.path.join(SHIM_DIR, "imports.h")
    if not os.path.exists(hdr):
        return out
    table = [(int(m.group(1), 16), m.group(2)) for m in map(SHIM_RX.match, open(hdr)) if m]
    out["objects"] = native_host.compile_dir(cp, SHIM_DIR, os.path.join(OUT, "link", "platform"), st,
                                             ("HULK_NATIVE_SDL=1",) if SDL_LIBS else ())
    st["SDL3 audio/input backends (HULK_NATIVE_SDL)"] = 1 if SDL_LIBS else 0
    for dset, _u in cp.nm(out["objects"]).values():
        out["defined"] |= dset
    by_key = {shim_key(s)[len("hulk_xdk_"):]: s for s in out["defined"] if (shim_key(s) or "").startswith("hulk_xdk_")}
    for a, name in table:
        s = by_key.get(name)
        if s is None:
            st["imports without a definition"] += 1
            continue
        out["by_addr"][a] = s
        out["by_name"][name] = a
        st["imports"] += 1
    return out


def deleting_destructors(defs, defined):
    """Fix 6b: the scalar deleting destructors (`??_GX@@UAEPAXI@Z`) the verification build defines and clang doesn't.

    MSVC 7.1 emits `??_G` as a COMDAT wherever the source defines a virtual destructor; clang (MS ABI) emits it
    only with the class's vftable, i.e. in a TU that constructs the class. The game's vftables (vtables.s) and
    the stub vftables' slot 0 point at it. Each is synthesized here from MSVC's own definition of the function:
    in the verification build it calls exactly the complete destructor `??1X` and the global `operator delete`
    (checked per function from the MSVC object's relocations; anything else is left alone), so it is

        X* __thiscall X::`scalar deleting destructor'(unsigned flags)
        { this->X::~X(); if (flags & 1) ::operator delete(this); return this; }

    with `??1X` the clang-compiled destructor from the same source. No source or MSVC input changes; MS-ABI only
    (Itanium emits its deleting destructor D0 with the vtable)."""
    want = {a: s for a, s in defs.items() if s.startswith("??_G") and s.endswith("PAXI@Z") and s not in defined}
    st = collections.Counter({"verified ??_G missing from the clang objects": len(want)})
    out, asm, refs = {}, ["\t.text"], set()
    if not want:
        return {"symbols": out, "references": refs, "asm": None, "stats": dict(st)}
    by_sym = {c["symbol"]: c for c in tree_checks() if c.get("symbol") in set(want.values())}
    objs = tree_objects({c["tu"] for c in by_sym.values()})
    delete = "??3@YAXPAX@Z"
    for a, s in sorted(want.items()):
        dtor = "??1" + s[4:-len("PAXI@Z")] + "@XZ"
        c = by_sym.get(s)
        if c is None or c["kind"] != "matches" or c["status"] != "match" or not objs.get(c["tu"]):
            st["skipped: not a byte-matching function of the verification build"] += 1
            continue
        coff = compare.Coff(objs[c["tu"]])
        sym = next((x for x in coff.function_symbols() if x[0] == s), None)
        called = sorted({t[0] for off, t, typ, ab in coff.function_relocs(sym) if t}) if sym else None
        if called != sorted({dtor, delete}):
            st["skipped: MSVC's definition calls something else (%s)" % ("no symbol" if sym is None else "relocations")] += 1
            continue
        if dtor not in defined:
            st["skipped: the destructor is not in the clang objects"] += 1
            continue
        if s in out:
            # one symbol at two addresses (the same template instance or class verified in two TUs): one definition
            out[s].append(a)
            st["same symbol at another address"] += 1
            continue
        q, qd = '"%s"' % s, '"%s"' % dtor
        asm += ["\t.globl\t%s" % q, "\t.p2align\t4", "%s:" % q, "\tpushl\t%esi", "\tmovl\t%ecx, %esi",
                "\tcalll\t%s" % qd, "\ttestb\t$1, 8(%esp)", "\tje\t1f", "\tpushl\t%esi",
                '\tcalll\t"%s"' % delete, "\tpopl\t%ecx", "1:", "\tmovl\t%esi, %eax", "\tpopl\t%esi", "\tretl\t$4"]
        out[s] = [a]
        refs |= {dtor, delete}
        st["synthesized"] += 1
    return {"symbols": out, "references": refs, "asm": "\n".join(asm) + "\n", "stats": dict(st)}


def rename_object(obj, pairs):
    """A copy of a clang object with symbols renamed (llvm-objcopy --redefine-syms), under build/native/link/objs/."""
    d = os.path.join(OUT, "link", "objs")
    os.makedirs(d, exist_ok=True)
    out = os.path.join(d, os.path.basename(obj))
    lst = out + ".syms"
    with open(lst, "w") as f:
        f.write("".join("%s %s\n" % (a, b) for a, b in pairs))
    r = subprocess.run([native_host.LLVM + "/llvm-objcopy", "--redefine-syms=" + lst, obj, out],
                       capture_output=True, text=True)
    return out if r.returncode == 0 else obj


def code_owned_data(by_addr_def):
    """The vftables and RTTI structures of config/data.json (code-owned: no data TU defines them) as one
    assembly file: each item's bytes from the XBE, every dword that holds an address of the image as a
    relocation (to the tree's definition of a function, to another of these items, to a data TU item, or to
    `_hulk_x_<addr>`, a stub for anything else), and a label `_hulk_d_<addr>` at each item and each interior
    address data.json lists (a vftable's slot 0 is one: the COL pointer comes first). The native link binds
    the sources' by-address names (`g_vftable_<addr>`, `DAT_<addr>`, stub vftable names bound by relocation)
    to these labels. MS-ABI only, like the aliases: the layouts are MSVC's."""
    import bisect
    items = [it for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"]
             if it["kind"] == "vtable" or it["kind"].startswith("rtti_")]
    items.sort(key=lambda it: int(it["addr"], 16))
    starts = [int(it["addr"], 16) for it in items]
    x = xbe()
    lo, hi = x.base, max(sec.va + sec.vsize for sec in x.sections)
    labels, names = {}, {}
    kind_at = {int(it["addr"], 16): it["kind"] for it in items}
    for it in items:
        a = int(it["addr"], 16)
        labels[a] = "_hulk_d_%08x" % a
        for i in it.get("interior", []):
            labels[int(i, 16)] = "_hulk_d_%08x" % int(i, 16)
        if it.get("name", "").startswith("??_"):
            # MSVC's symbol: a vftable's is slot 0, after the pointer to its complete object locator
            sym = a + 4 if it["kind"] == "vtable" and kind_at.get(x.u32(a) or 0) == "rtti_col" else a
            names[it["name"]] = sym
            labels.setdefault(sym, "_hulk_d_%08x" % sym)
    undefined, st = set(), collections.Counter()

    def target(v):
        d = by_addr_def.get(v)
        if d:
            st["pointers to a definition"] += 1
            return d
        i = bisect.bisect_right(starts, v) - 1
        if i >= 0 and v < starts[i] + items[i]["size"]:
            st["pointers into these items"] += 1
            return labels[v] if v in labels else "%s+%d" % (labels[starts[i]], v - starts[i])
        st["pointers to a stub (_hulk_x_)"] += 1
        undefined.add("_hulk_x_%08x" % v)
        return "_hulk_x_%08x" % v
    out = ["\t.data"]
    for it in items:
        a, n = int(it["addr"], 16), it["size"]
        o = x.offset(a)
        if o is None:
            continue
        raw = x.data[o:o + n]
        st["items"] += 1
        pos = 0
        while pos < n:
            if a + pos in labels:
                out += ['\t.globl\t%s' % labels[a + pos], "%s:" % labels[a + pos]]
            if pos + 4 <= n and (a + pos) % 4 == 0 and not any(a + pos + k in labels for k in (1, 2, 3)) \
                    and not (it["kind"] == "rtti_td" and pos >= 8):     # unb1: a type descriptor's name is text
                v, = struct.unpack_from("<I", raw, pos)
                if lo <= v < hi:
                    t = target(v)
                    out.append('\t.long\t"%s"' % t if "+" not in t else "\t.long\t%s" % t)
                else:
                    out.append("\t.long\t%d" % v)
                pos += 4
            else:
                out.append("\t.byte\t%d" % raw[pos])
                pos += 1
    return {"labels": labels, "names": names, "undefined": undefined, "asm": "\n".join(out) + "\n", "stats": dict(st)}


SHAPE_OPS = {"sub", "add", "mov", "lea"}


def jump_shapes(by_addr_def):
    """native9: the XBE's adjustor thunks and pure forwarders as our own code (build/native/link/vtables.s, .text).

    A function whose original is only register/stack adjustments ending in a jump (`sub ecx, 4; jmp X`: MSVC's
    adjustor thunks in the vftables of classes with several bases; `mov ecx, [ecx+0xc]; jmp X`, `mov eax, [ecx];
    jmp [eax+8]`: forwarders) is re-emitted from its own bytes, the `jmp rel32` pointed at the tree's definition of
    its target. Why: the verification build names such a thunk by bytes, and its clang counterpart can jump
    elsewhere (matches/0x002777c0.cpp defines `CementLibrary::vfunc_0() {}` next to the thunk it matched, so clang's
    thunk ran that empty body instead of 0x00277790: the IFileCompletionCallback AddRef was lost and the
    CementLibrary freed under its request). The copy is the original instruction for instruction, so it is exact
    whatever the source's thunk says. Candidates: build/functions.csv entries (the shape must end at the entry's
    end) and every vftable slot's target. Returns {addr: label}, the asm, stats."""
    import capstone
    x = xbe()
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    lo, hi = x.base, max(sec.va + sec.vsize for sec in x.sections)
    cands = {}
    for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv"))):
        cands[int(r["address"], 16)] = int(r["size"])
    for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"]:
        if it["kind"] != "vtable":
            continue
        a0 = int(it["addr"], 16)
        for k in range(it["size"] // 4):
            v = x.u32(a0 + 4 * k) or 0
            if lo <= v < hi and v not in cands:
                cands[v] = None
    st = collections.Counter()
    shapes = {}
    for a, size in sorted(cands.items()):
        o = x.offset(a)
        if o is None:
            continue
        code = bytes(x.data[o:o + (size or 24)])
        pro, end, ok = [], None, False
        for ins in md.disasm(code, a):
            if ins.mnemonic == "jmp":
                op = ins.operands[0]
                if op.type == capstone.x86.X86_OP_IMM and ins.bytes[0] in (0xE9, 0xEB):
                    end = ("rel", op.imm & 0xFFFFFFFF)
                elif op.type == capstone.x86.X86_OP_MEM and op.mem.base and not op.mem.index:
                    end = ("raw", bytes(ins.bytes))
                ok = end is not None and (size is None or ins.address + ins.size == a + size)
                break
            if ins.mnemonic not in SHAPE_OPS or len(pro) >= 4:
                break
            good = True
            for op in ins.operands:
                if op.type == capstone.x86.X86_OP_MEM and (not op.mem.base or op.mem.index or lo <= op.mem.disp < hi):
                    good = False
                if op.type == capstone.x86.X86_OP_IMM and lo <= (op.imm & 0xFFFFFFFF) < hi:
                    good = False
            if not good:
                break
            pro.append(bytes(ins.bytes))
        if not ok or (not pro and end[0] == "rel" and by_addr_def.get(a)):
            continue           # (a bare `jmp X` with a definition is bound to its target already: jmp_target; one
                               # without, in a vftable slot like 0x00255d00, gets its own)
        shapes[a] = (b"".join(pro), end)
    labels = {a: "_hulk_j_%08x" % a for a in shapes}
    out = ["\t.text"]
    for a, (pro, end) in sorted(shapes.items()):
        if end[0] == "rel":
            t = end[1]
            d = labels.get(t) or by_addr_def.get(t) or by_addr_def.get(final_target(t))
            if not d:
                st["target has no definition (left as it was)"] += 1
                labels.pop(a)
                continue
        out += ["\t.globl\t%s" % labels[a], "\t.p2align\t4", "%s:" % labels[a]]
        if pro:
            out.append("\t.byte\t" + ",".join(str(b) for b in pro))
        if end[0] == "rel":
            out.append('\tjmp\t"%s"' % d)
            st["adjust + jmp" if pro else "jmp"] += 1
        else:
            out.append("\t.byte\t" + ",".join(str(b) for b in end[1]))
            st["adjust + jmp [reg+d]"] += 1
        st["replaced a definition" if by_addr_def.get(a) else "had no definition"] += 1
    return {"labels": labels, "asm": "\n".join(out) + "\n", "stats": dict(st)}


def source_slots(symbols, man):
    """{virtual member symbol: vftable slot} read from the stub class's definition in its TU, for stub classes no
    clang object emits a vftable for: a class without bases whose virtual functions are all declared in its body
    (MS ABI: slots in declaration order, a virtual destructor taking one). Unique definitions only."""
    want = collections.defaultdict(list)       # (ns, class) -> [(symbol, member)]
    for s in symbols:
        # (a namespace between the class and the TU's fn_ namespace is allowed: `?acquire@Lock_2756e0@core@fn_f0fe475a@@`)
        m = re.match(r"\?(\w+)@(\w+)@(?:\w+@)*?(fn_[0-9a-f]{8})@@[UM][AB]E", s)
        if m:
            want[(m.group(3), m.group(2))].append((s, m.group(1)))
    if not want:
        return {}
    import clang_probe
    tu_of = {t.get("tu_ns"): p for p, t in man.tus.items()}
    for p, t in man.tus.items():          # (a wrapped block's own namespace, fn_<addr>)
        for b in t.get("blocks", []):
            if b.get("ns"):
                tu_of.setdefault(b["ns"], p)
    out = {}
    texts = {}
    for (ns, cls), members in want.items():
        tu = tu_of.get(ns)
        if not tu:
            continue
        if tu not in texts:
            try:
                texts[tu] = open(os.path.join(clang_probe.SNAP, tu), errors="replace").read()
            except OSError:
                texts[tu] = ""
        bodies = set()
        for m in re.finditer(r"\b(?:class|struct)\s+%s\s*\{" % re.escape(cls), texts[tu]):
            i, depth = m.end() - 1, 0
            for j in range(i, len(texts[tu])):
                depth += {"{": 1, "}": -1}.get(texts[tu][j], 0)
                if depth == 0:
                    break
            bodies.add(texts[tu][i + 1:j])
        if len(bodies) != 1:
            continue
        body = re.sub(r"\{[^{}]*\}", ";", bodies.pop())          # inline bodies
        virt = re.findall(r"\bvirtual\b[^;(]*?(~?\w+)\s*\(", body)
        if len(virt) != len(set(virt)):
            continue          # overloads: the order is MSVC's grouping, not the declaration's
        for sym, name in members:
            if name in virt:
                out[sym] = virt.index(name)
    return out


def stub_slot_aliases(objects, binding, by_addr_def, undef, how, slot_of=None):
    """{undefined virtual member: definition} from the clang objects' own stub vftables (see link_inventory)."""
    want = set(undef)
    slots = collections.defaultdict(set)        # symbol -> {(vftable symbol, slot)}
    for o in objects:
        try:
            c = compare.Coff(o)
        except Exception:  # noqa: BLE001 - an unreadable object only loses its slots
            continue
        for name, value, secnum, typ, cls in c.symbols:
            if not name.startswith("??_7") or secnum <= 0 or cls != 2:
                continue
            _, raw, relocs = c.sections[secnum - 1]
            for va, si, rtyp in relocs:
                t = c.by_index.get(si)
                if t and t[0] in want and va >= value and (va - value) % 4 == 0:
                    slots[t[0]].add((name, (va - value) // 4))
    if slot_of is not None:
        for s, refs in slots.items():
            ns = {n for _v, n in refs}
            if len(ns) == 1:
                slot_of[s] = ns.pop()
    x = xbe()
    out = {}
    for s, refs in slots.items():
        ds = set()
        for v, n in refs:
            b = binding.get(v)
            if not b:
                how["vftable address unknown"] += 1
                continue
            o = x.offset(int(b["addr"], 16) + 4 * n)
            if o is None:
                continue
            f, = struct.unpack_from("<I", x.data, o)
            ds.add(by_addr_def.get(f) or "")
        if len(ds) == 1 and "" not in ds:
            out[s] = ds.pop()
            how["bound to the game vftable's slot"] += 1
        elif ds == {""}:
            how["slot of the game vftable has no verified definition"] += 1
        elif ds:
            how["slots disagree"] += 1
    how["virtual members found in stub vftables"] = len(slots)
    return out


DATA_LIKE = re.compile(r"^\?\?_[78R]|^\?[^@]+@.*@@[0-9]|^_(?:DAT|g|s|PTR|tbl|flt|dbl|unk|hulk_at|vtbl|rttiTD)_|^\?\?_C@|^__real@")


def lld_link(objects, aliases, undefined, vt_asm=None, dd_asm=None, startup_asm=None, libs=(), data_asm=None, vthunks=None):
    d = os.path.join(OUT, "link")
    os.makedirs(d, exist_ok=True)
    for name, text in (("vtables", vt_asm), ("deleting", dd_asm), ("startup", startup_asm), ("data", data_asm)):
        if not text:
            continue
        with open(os.path.join(d, name + ".s"), "w") as f:
            f.write(text)
        vobj = os.path.join(d, name + ".obj")
        r = subprocess.run([os.path.join(native_host.LLVM, "clang"), "--target=i686-pc-windows-msvc", "-c",
                            os.path.join(d, name + ".s"), "-o", vobj], capture_output=True, text=True)
        if r.returncode != 0:
            return {"status": "%s object failed" % name, "log": r.stderr[-2000:]}
        objects = objects + [vobj]
    llvm = native_host.LLVM
    lld = os.path.join(llvm, "lld-link") if os.path.exists(os.path.join(llvm, "lld-link")) else \
        (subprocess.run(["which", "lld-link"], capture_output=True, text=True).stdout.strip() or None)
    if not lld:
        return {"status": "lld-link not found"}
    # one stub per symbol still undefined: 16 zero bytes for data; code reports its name (src/platform/sdl/xdk/
    # startup.cpp hulk_native_missing). Without the start-up object (no shim), the old int3 entry.
    text = native_host.stubs_asm(undefined, DATA_LIKE, vthunks)
    if not startup_asm:
        text = '\t.text\n\t.globl\t"_hulk_native_entry"\n"_hulk_native_entry":\n\tint3\n' + text
    with open(os.path.join(d, "stubs.s"), "w") as f:
        f.write(text)
    stub = os.path.join(d, "stubs.obj")
    r = subprocess.run([os.path.join(llvm, "clang"), "--target=i686-pc-windows-msvc", "-c", os.path.join(d, "stubs.s"),
                        "-o", stub], capture_output=True, text=True)
    if r.returncode != 0:
        return {"status": "stub object failed", "log": r.stderr[-2000:]}
    with open(os.path.join(d, "objects.rsp"), "w") as f:
        f.write("\n".join('"%s"' % o for o in objects + [stub]) + "\n")
    with open(os.path.join(d, "aliases.rsp"), "w") as f:
        f.write("\n".join('"/alternatename:%s=%s"' % (a, b) for a, b in sorted(aliases.items())) + "\n")
    out = {}
    for tag, extra in (("strict", []), ("force", ["/force:multiple"])):
        cmd = [lld, "/nologo", "/machine:x86", "/subsystem:console", "/entry:hulk_native_entry", "/nodefaultlib", "/safeseh:no",
               "/errorlimit:0", "/out:" + os.path.join(d, "hulk-%s.exe" % tag), "/map:" + os.path.join(d, "hulk-%s.map" % tag),
               "/base:0x10000000", "@" + os.path.join(d, "objects.rsp"), "@" + os.path.join(d, "aliases.rsp")] + list(libs) + extra
        r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
        log = r.stdout + r.stderr
        with open(os.path.join(d, "lld-link-%s.log" % tag), "w") as f:
            f.write(log)
        kinds = collections.Counter()
        for l in log.splitlines():
            m = re.match(r"lld-link: (error|warning): (.*)", l)
            if m:
                kinds["%s: %s" % (m.group(1), re.sub(r":.*", "", re.sub(r"'[^']*'|\S+\.obj", "X", m.group(2)))[:80])] += 1
        exe = os.path.join(d, "hulk-%s.exe" % tag)
        out[tag] = {"rc": r.returncode, "messages": dict(kinds.most_common(20)),
                    "image": os.path.getsize(exe) if r.returncode == 0 and os.path.exists(exe) else None}
    return out


def conv_check():
    """tools/native_conv_check.py (report only): calling conventions of the sources' and the binding map's
    declarations of library imports against the stand-in tables and the XBE's `ret N`."""
    import native_conv_check
    try:
        r = native_conv_check.run(bindings_path=os.path.join(OUT, "bindings.json"))
    except Exception as e:  # noqa: BLE001 - a report, never a reason to fail the link
        return {"error": "%s: %s" % (type(e).__name__, e)}
    return {"findings": r["findings"], "imports": r["imports"],
            "sources": {"declarations": r["sources"]["declarations"], "disagreeing": len(r["sources"]["disagreeing"])},
            "bindings": {"symbols": r["bindings"]["symbols"], "disagreeing": len(r["bindings"]["disagreeing"])},
            "xbe": {"checked": r["xbe"]["checked"], "disagreeing": len(r["xbe"]["disagreeing"])},
            "register_orders": {"functions": r["register_orders"]["functions"],
                                "disagreeing": len(r["register_orders"]["disagreeing"])},
            "details": ([d.get("symbol") or "%s:%s" % (d.get("file"), d.get("line")) if "why" in d or "symbol" in d
                        else d.get("import_") for k in ("sources", "bindings", "xbe") for d in r[k]["disagreeing"]] +
                       ["%s %s" % (d["addr"], d["file"]) for d in r["register_orders"]["disagreeing"]])[:40]}


# ---------------------------------------------------------------------------------------------
def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--no-link", action="store_true", help="skip the lld-link attempt")
    ap.add_argument("--no-inventory", action="store_true", help="only the binding map (no clang objects)")
    ap.add_argument("--reuse-map", action="store_true",
                    help="take the binding map from build/native/bindings.json (e.g. built on another machine) "
                         "instead of rebuilding it; only the link inventory and the link run")
    ap.add_argument("--gfx", action="store_true",
                    help="link the pddi backend on bgfx in place of pure3d's d3d layer (or HULK_NATIVE_GFX=1; "
                         "build/g0/LINK.md, docs/graphics-backend.md G1)")
    ap.add_argument("--tree", help="the verification tree to bind from (default build/tree, or HULK_TREE_DIR): e.g. "
                    "build/clang-probe/snap, the snapshot tools/clang_probe.py compiled")
    a = ap.parse_args(argv)
    global TREE, GFX
    GFX = GFX or a.gfx
    if a.tree:
        TREE = os.path.abspath(a.tree)
    os.makedirs(OUT, exist_ok=True)
    if a.reuse_map:
        bj = json.load(open(os.path.join(OUT, "bindings.json")))
        binding, amb = bj["bindings"], bj["ambiguous"]
        defs = {int(k, 16): v for k, v in bj["definitions"].items()}
        rep = json.load(open(os.path.join(OUT, "report.json")))
        rep["link"] = link_inventory(binding, defs, {}, not a.no_link, set(amb), bj.get("ambiguous_by_tu"),
                                     bj.get("ambiguous_by_function"), bj.get("local_data"), bj.get("local_code"))
        rep["conv_check"] = conv_check()
        with open(os.path.join(OUT, "report.json"), "w") as f:
            json.dump(rep, f, indent=1)
        print(json.dumps(rep["link"], indent=1))
        return 0
    defs, refs, users, stats, per_tu, per_fn = build_map(a.jobs)
    with open(os.path.join(OUT, "tree-explicit.json"), "w") as f:
        json.dump(tree_explicit.changed, f, indent=0)
    binding, amb = bind(defs, {}, refs)
    # native9: a stub class's vftable bound to two addresses because a check took a same-named function of the TU
    # (build_tree's loose symbol lookup: 0x0023d710 was compared as 0x0023d420's `Func`): the address from the one
    # source that declares the class is the vftable
    for s_ in [x for x in amb if x.startswith("??_7")]:
        m = re.match(r"\?\?_7(\w+)@", s_)
        srcs = getattr(build_map, "vt_src", {}).get(s_, {})
        own = {tuple(sorted(v)) for src, v in srcs.items() if m and os.path.exists(os.path.join(ROOT, src)) and
               re.search(r"\b(?:class|struct)\s+%s\b" % re.escape(m.group(1)), open(os.path.join(ROOT, src), errors="replace").read())}
        if len(own) == 1 and len(next(iter(own))) == 1:
            t = next(iter(own))[0]
            binding[s_] = {"addr": "0x%08x" % t, "how": ["position", "declaring source"], "def": defs.get(t)}
            del amb[s_]
    # an ambiguous symbol (one name, two callees) is often one callee per TU: the link renames it per object
    amb_tu = {}
    for s_ in amb:
        by = {tu: sorted({final_target(x) for x in ad}) for tu, ad in per_tu[s_].items()}
        if all(len(v) == 1 for v in by.values()):
            amb_tu[s_] = {tu: "0x%08x" % v[0] for tu, v in by.items()}
    # otherwise one callee per calling function (two sources merged into one TU, each naming its own `Obj::Init`):
    # the link rebinds each relocation by the function it is in
    amb_fn = {}
    for s_ in amb:
        if s_ in amb_tu:
            continue
        by = {fn: sorted({final_target(x) for x in ad}) for fn, ad in per_fn[s_].items()}
        # (native9: the functions with one callee each, even when another one has two: a check that took a
        # same-named function of its TU, build_tree's loose lookup, must not cost every other caller its binding)
        one = {fn: "0x%08x" % v[0] for fn, v in by.items() if len(v) == 1}
        if one:
            amb_fn[s_] = one
    # a name with an address that some verified function uses for another callee (a clone source calling
    # `FUN_0008ed50` where its original calls 0x00270540: the byte match masks the relocation): the name is defined,
    # so no alias would ever apply; those functions' relocations are rebound like the ambiguous ones
    for s_, fns in per_fn.items():
        n = name_address(s_)
        # (native9: data names too: `extern "C" int* FUN_00256660() { return &DAT_004dd780; }`, a source propagated
        # from another function's shape, whose original returns 0x004e7620)
        if n is None or (n not in defs and not re.search(r"(?:^|[^0-9A-Za-z])DAT_00[0-9a-fA-F]{6}", s_)):
            continue
        own = final_target(n)
        wrong = {}
        for fn, ad in fns.items():
            tt = {final_target(x) for x in ad}
            if len(tt) == 1 and own not in tt:
                wrong[fn] = "0x%08x" % tt.pop()
        if wrong:
            amb_fn.setdefault(s_, {}).update(wrong)
    how = collections.Counter("+".join(b["how"]) for b in binding.values())
    with open(os.path.join(OUT, "bindings.json"), "w") as f:
        json.dump({"bindings": binding, "ambiguous": amb, "ambiguous_by_tu": amb_tu, "ambiguous_by_function": amb_fn,
                   "local_data": getattr(build_map, "local_data", {}), "local_code": getattr(build_map, "local_code", {}),
                   "definitions": {"0x%08x" % k: v for k, v in sorted(defs.items())},
                   "references": dict(users)}, f, indent=0)
    with open(os.path.join(OUT, "alternatename.rsp"), "w") as f:
        for s, b in sorted(binding.items()):
            if b["def"] and b["def"] != s:
                f.write('"/alternatename:%s=%s"\n' % (s, b["def"]))
    rep = {"stats": dict(stats), "referenced_symbols": len(refs), "bound": len(binding), "ambiguous": len(amb),
           "bound_to_a_tree_definition": sum(1 for b in binding.values() if b["def"]),
           "aliases": sum(1 for s, b in binding.items() if b["def"] and b["def"] != s),
           "how": dict(how.most_common())}
    if not a.no_inventory:
        rep["link"] = link_inventory(binding, defs, {}, not a.no_link, set(amb), amb_tu, amb_fn,
                                     getattr(build_map, "local_data", {}), getattr(build_map, "local_code", {}))
    rep["conv_check"] = conv_check()
    with open(os.path.join(OUT, "report.json"), "w") as f:
        json.dump(rep, f, indent=1)
    print(json.dumps(rep, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
