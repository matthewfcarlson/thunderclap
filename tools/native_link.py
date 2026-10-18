#!/usr/bin/env python3
"""Callee binding map for the native link (docs/native-build.md fix 5a), and a link attempt with lld-link.

  build/venv/bin/python tools/native_link.py              # binding map from the verification build + link inventory
  build/venv/bin/python tools/native_link.py --no-link    # binding map and inventory only (no lld-link run)
  build/venv/bin/python tools/native_link.py --jobs 3     # processes for the equivalent/ bindings (default 3)

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
                     vftable), hulk-strict.exe/.map (the image and its map: tools/native_run.py runs it under Wine)

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
ADDR_RX = re.compile(r"(?:^|[^0-9A-Za-z])(?:FUN|DAT|thunk_FUN|PTR|LAB)_(00[0-9a-fA-F]{6})(?![0-9a-fA-F])")


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


def match_bindings(obj, symbol, addr):
    """{undefined symbol: Counter(address)} of a byte-matching function, by position."""
    coff = compare.Coff(obj)
    sym = next((s for s in coff.function_symbols() if s[0] == symbol), None)
    out = collections.defaultdict(collections.Counter)
    if sym is None:
        return out
    x = xbe()
    for off, tsym, typ, addend_bytes in coff.function_relocs(sym):
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
    for c in checks:
        obj = objs.get(c["tu"])
        if not obj or not c.get("symbol"):
            stats["functions without an object or symbol"] += 1
            continue
        a = int(c["addr"], 16)
        if c["kind"] == "matches" and c["status"] == "match":
            for s, ts in match_bindings(obj, c["symbol"], a).items():
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
            for s, (t, how) in res["map"].items():
                refs[s][int(t, 16)]["equiv:" + how] += 1
                per_tu[s][tu].add(int(t, 16))
                per_fn[s][job[1]].add(int(t, 16))
                users[s] += 1
            for s in res["unresolved"]:
                stats["equivalent: symbols equiv.py could not bind"] += 1
            if i % 500 == 0 and sys.stderr.isatty():
                print("  equivalent bindings %d/%d" % (i, len(todo)), file=sys.stderr, flush=True)
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


def link_inventory(binding, defs, data_defs, do_link, ambiguous=(), amb_tu=None, amb_fn=None):
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
    for a, s in shim["by_addr"].items():
        by_addr_def.setdefault(a, s)
    defined |= shim["defined"]
    # start-up (docs/native-build.md "Start-up"): the host C runtime (src/platform/sdl/crt/: import libraries and our
    # glue), the library code and data the tree reaches by address (src/platform/sdl/xdk/library.h)
    host = native_host.host_crt(cp, os.path.join(OUT, "link"))
    defined |= host["defined"]
    lib = native_host.library_shim(cp, shim["objects"])
    # what the platform code itself still needs (clang's own libcalls in it: _aulldiv, memcpy): by name like the tree's
    for d_, u in cp.nm(shim["objects"] + host["objects"]).values():
        for s in u:
            if s not in defined and not s.startswith(("_hulk_host_", "__imp_", "_hulk_game_", "_hulk_clang_xc_", "@feat")):
                refs[s] += 1
                undef.add(s)
    for a, s in list(lib["by_addr"].items()) + list(host["by_addr"].items()):
        if by_addr_def.get(a) and by_addr_def[a] != s and a not in host["by_addr"]:
            continue
        by_addr_def[a] = s
    # fix 6a: the game's vftables and RTTI structures as data (build/native/link/vtables.s), named by address
    vt = code_owned_data(by_addr_def)
    for a, lab in vt["labels"].items():
        by_addr_def.setdefault(a, lab)
    for s in sorted(undef):
        b = binding.get(s)
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
    for s, d in stub_slot_aliases(sorted(objs.values()), binding, by_addr_def, undef - set(aliases), slot_how).items():
        aliases[s] = d
        how["stub vftable slot"] += 1
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
        if not plan:
            continue
        for o, (d_, u) in syms.items():
            if s in u or s in d_:
                rebind[o][s] = plan
        how["rebound per calling function (%s)" % ("ambiguous" if s in undef else "name means another address")] += 1
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
        b = binding.get(s)
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
    vt_rebind = collections.defaultdict(dict)
    for o, (d_, u) in syms.items():
        for s in (d_ | u) & set(vt_map):
            vt_rebind[o][s] = vt_map[s]
    how["stub vftable references pointed at the game's vftable"] += len(vt_map)
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
           "code_owned_data": vt["stats"], "deleting_destructors": dd["stats"], "platform_shim": shim["stats"],
           "host_crt": dict(host["stats"]), "library_shim": lib["stats"], "startup": start_st,
           "interior_retargeted_objects": len(retarget),
           "undefined_after": {"symbols": len(after), "references": sum(refs[s] for s in after),
                               "groups": tally(after_g, after)}}
    if do_link:
        link_objs = []
        for o in sorted(objs.values()):
            o2 = rename_object(o, renames[o]) if renames.get(o) else o
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
                after |= left - defined     # relocations in functions the plan doesn't know keep the old name
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
            link_objs.append(o2)
        link_objs += shim["objects"] + host["objects"]
        inv["lld_link"] = lld_link(link_objs, aliases, after | vt["undefined"], vt["asm"], dd["asm"], startup, host["libs"])
    return inv


SHIM_DIR = os.path.join(ROOT, "src/platform/sdl/xdk")
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
    out["objects"] = native_host.compile_dir(cp, SHIM_DIR, os.path.join(OUT, "link", "platform"), st)
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
    r = subprocess.run(["/opt/homebrew/opt/llvm/bin/llvm-objcopy", "--redefine-syms=" + lst, obj, out],
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
            if pos + 4 <= n and (a + pos) % 4 == 0 and not any(a + pos + k in labels for k in (1, 2, 3)):
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


def stub_slot_aliases(objects, binding, by_addr_def, undef, how):
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


DATA_LIKE = re.compile(r"^\?\?_[78R]|^\?[^@]+@.*@@[0-9]|^_(?:DAT|g|s|PTR|tbl|flt|dbl|unk)_|^\?\?_C@|^__real@")


def lld_link(objects, aliases, undefined, vt_asm=None, dd_asm=None, startup_asm=None, libs=()):
    d = os.path.join(OUT, "link")
    os.makedirs(d, exist_ok=True)
    for name, text in (("vtables", vt_asm), ("deleting", dd_asm), ("startup", startup_asm)):
        if not text:
            continue
        with open(os.path.join(d, name + ".s"), "w") as f:
            f.write(text)
        vobj = os.path.join(d, name + ".obj")
        r = subprocess.run([os.path.join("/opt/homebrew/opt/llvm/bin", "clang"), "--target=i686-pc-windows-msvc", "-c",
                            os.path.join(d, name + ".s"), "-o", vobj], capture_output=True, text=True)
        if r.returncode != 0:
            return {"status": "%s object failed" % name, "log": r.stderr[-2000:]}
        objects = objects + [vobj]
    llvm = "/opt/homebrew/opt/llvm/bin"
    lld = os.path.join(llvm, "lld-link") if os.path.exists(os.path.join(llvm, "lld-link")) else \
        (subprocess.run(["which", "lld-link"], capture_output=True, text=True).stdout.strip() or None)
    if not lld:
        return {"status": "lld-link not found"}
    # one stub per symbol still undefined: 16 zero bytes for data; code reports its name (src/platform/sdl/xdk/
    # startup.cpp hulk_native_missing). Without the start-up object (no shim), the old int3 entry.
    text = native_host.stubs_asm(undefined, DATA_LIKE)
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
    ap.add_argument("--tree", help="the verification tree to bind from (default build/tree, or HULK_TREE_DIR): e.g. "
                    "build/clang-probe/snap, the snapshot tools/clang_probe.py compiled")
    a = ap.parse_args(argv)
    global TREE
    if a.tree:
        TREE = os.path.abspath(a.tree)
    os.makedirs(OUT, exist_ok=True)
    if a.reuse_map:
        bj = json.load(open(os.path.join(OUT, "bindings.json")))
        binding, amb = bj["bindings"], bj["ambiguous"]
        defs = {int(k, 16): v for k, v in bj["definitions"].items()}
        rep = json.load(open(os.path.join(OUT, "report.json")))
        rep["link"] = link_inventory(binding, defs, {}, not a.no_link, set(amb), bj.get("ambiguous_by_tu"),
                                     bj.get("ambiguous_by_function"))
        rep["conv_check"] = conv_check()
        with open(os.path.join(OUT, "report.json"), "w") as f:
            json.dump(rep, f, indent=1)
        print(json.dumps(rep["link"], indent=1))
        return 0
    defs, refs, users, stats, per_tu, per_fn = build_map(a.jobs)
    binding, amb = bind(defs, {}, refs)
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
        if by and all(len(v) == 1 for v in by.values()):
            amb_fn[s_] = {fn: "0x%08x" % v[0] for fn, v in by.items()}
    # a name with an address that some verified function uses for another callee (a clone source calling
    # `FUN_0008ed50` where its original calls 0x00270540: the byte match masks the relocation): the name is defined,
    # so no alias would ever apply; those functions' relocations are rebound like the ambiguous ones
    for s_, fns in per_fn.items():
        n = name_address(s_)
        if n is None or n not in defs:
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
        json.dump({"bindings": binding, "ambiguous": amb, "ambiguous_by_tu": amb_tu, "ambiguous_by_function": amb_fn, "definitions": {"0x%08x" % k: v for k, v in sorted(defs.items())},
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
        rep["link"] = link_inventory(binding, defs, {}, not a.no_link, set(amb), amb_tu, amb_fn)
    rep["conv_check"] = conv_check()
    with open(os.path.join(OUT, "report.json"), "w") as f:
        json.dump(rep, f, indent=1)
    print(json.dumps(rep, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
