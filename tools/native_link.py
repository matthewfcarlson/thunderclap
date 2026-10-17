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
                     objects define), stubs.s/.obj (one stub per symbol still undefined), lld-link.log
  report.json        counts: bindings by how, the clang objects' undefined symbols before/after binding by
                     group (tools/clang_probe.py's groups), the lld-link result
  unbound.txt        every symbol still undefined after binding: group, references, symbol, demangled
"""
import argparse
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

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUT = os.path.join(ROOT, "build/native")
CACHE = os.path.join(OUT, "cache")
TREE = os.path.join(ROOT, "build/tree")
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
        if not is_undefined(tsym) or typ not in (REL32, DIR32):
            continue
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
    key = hashlib.sha1(open(obj, "rb").read() + symbol.encode() + src.encode()).hexdigest()[:24]
    p = os.path.join(CACHE, "equiv", key + ".json")
    if os.path.exists(p):
        return json.load(open(p))
    import equiv
    undefined = {s[0] for s in compare.Coff(obj).symbols if s[2] == 0 and s[4] == 2}
    try:
        rep = equiv.verify(os.path.join(ROOT, src), addr, symbol=symbol, obj_path=obj, max_level=2)
        m = rep.get("level2", {}).get("mapping", {})
        res = {"status": rep.get("status"),
               "map": {n: [v["addr"], v["how"]] for n, v in m.items() if n in undefined and v.get("addr")},
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
    return {t: build_tree.compile_tu(t)[0] for t in sorted(tus)}


def build_map(jobs):
    checks = tree_checks()
    objs = tree_objects({c["tu"] for c in checks})
    defs = {}                       # addr -> defining symbol in the tree's objects
    for c in checks:
        if c.get("symbol") and c["status"] in ("match", "compiled") and objs.get(c["tu"]):
            defs[int(c["addr"], 16)] = c["symbol"]
    refs = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))   # sym -> addr -> how
    users = collections.Counter()
    stats = collections.Counter()
    todo = []
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
                users[s] += 1
            stats["matches bound by position"] += 1
        elif c["kind"] == "equivalent" and c["status"] == "compiled":
            todo.append((obj, c["symbol"], c["src"], a))
    with ProcessPoolExecutor(jobs) as ex:
        for i, res in enumerate(ex.map(_equiv_job, todo, chunksize=8), 1):
            stats["equivalent: equiv.py level 2 %s" % ("ok" if res["status"] in ("draft", "pass") else res["status"])] += 1
            for s, (t, how) in res["map"].items():
                refs[s][int(t, 16)]["equiv:" + how] += 1
                users[s] += 1
            for s in res["unresolved"]:
                stats["equivalent: symbols equiv.py could not bind"] += 1
            if i % 500 == 0 and sys.stderr.isatty():
                print("  equivalent bindings %d/%d" % (i, len(todo)), file=sys.stderr, flush=True)
    return defs, refs, users, stats


def data_definitions(objs_syms):
    """addr -> data symbol, from objects' defined `_DAT_<addr>` symbols (tools/data_gen.py's data TUs)."""
    out = {}
    for d in objs_syms:
        for s in d:
            m = re.fullmatch(r"_DAT_(00[0-9a-f]{6})", s)
            if m:
                out[int(m.group(1), 16)] = s
    return out


def bind(defs, data_defs, refs):
    """referenced symbol -> binding record; and the ambiguous ones."""
    out, amb = {}, {}
    for s, by_addr in refs.items():
        addrs = sorted(by_addr)
        if len(addrs) > 1:
            amb[s] = {"0x%08x" % a: dict(by_addr[a]) for a in addrs}
            continue
        a = addrs[0]
        how = sorted(by_addr[a])
        d = defs.get(a) or data_defs.get(a)
        out[s] = {"addr": "0x%08x" % a, "how": how, "def": d}
    return out, amb


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


def link_inventory(binding, defs, data_defs, do_link, ambiguous=()):
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
    for s in sorted(undef):
        b = binding.get(s)
        a = int(b["addr"], 16) if b else None
        src = "relocation" if b else None
        if a is None:
            a = name_address(s)
            src = "name" if a is not None else None
        if a is None:
            continue
        d = by_addr_def.get(a)
        if d and d != s:
            aliases[s] = d
            how["bound by %s" % src] += 1
        elif b:
            how["relocation's address has no definition in the clang objects"] += 1
    after = undef - set(aliases)
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
           "aliases": len(aliases), "aliases_by_source": dict(how),
           "undefined_after": {"symbols": len(after), "references": sum(refs[s] for s in after),
                               "groups": tally(after_g, after)}}
    if do_link:
        inv["lld_link"] = lld_link(sorted(objs.values()), aliases, after)
    return inv


DATA_LIKE = re.compile(r"^\?\?_[78R]|^\?[^@]+@.*@@[0-9]|^_(?:DAT|g|s|PTR|tbl|flt|dbl|unk)_|^\?\?_C@|^__real@")


def lld_link(objects, aliases, undefined):
    d = os.path.join(OUT, "link")
    os.makedirs(d, exist_ok=True)
    llvm = "/opt/homebrew/opt/llvm/bin"
    lld = os.path.join(llvm, "lld-link") if os.path.exists(os.path.join(llvm, "lld-link")) else \
        (subprocess.run(["which", "lld-link"], capture_output=True, text=True).stdout.strip() or None)
    if not lld:
        return {"status": "lld-link not found"}
    # one stub per symbol still undefined: int3 for code, 16 zero bytes for data
    lines = ['\t.text', '\t.globl\t"_hulk_native_entry"', '"_hulk_native_entry":', "\tint3"]
    data = []
    for s in sorted(undefined):
        q = '"%s"' % s.replace('"', '\\"')
        if DATA_LIKE.match(s):
            data += ["\t.globl\t%s" % q, "%s:" % q, "\t.zero\t16"]
        else:
            lines += ["\t.globl\t%s" % q, "%s:" % q, "\tint3"]
    lines += ["\t.data"] + data
    with open(os.path.join(d, "stubs.s"), "w") as f:
        f.write("\n".join(lines) + "\n")
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
               "/errorlimit:0", "/out:" + os.path.join(d, "hulk-%s.exe" % tag),
               "@" + os.path.join(d, "objects.rsp"), "@" + os.path.join(d, "aliases.rsp")] + extra
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


# ---------------------------------------------------------------------------------------------
def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--no-link", action="store_true", help="skip the lld-link attempt")
    ap.add_argument("--no-inventory", action="store_true", help="only the binding map (no clang objects)")
    a = ap.parse_args(argv)
    os.makedirs(OUT, exist_ok=True)
    defs, refs, users, stats = build_map(a.jobs)
    binding, amb = bind(defs, {}, refs)
    how = collections.Counter("+".join(b["how"]) for b in binding.values())
    with open(os.path.join(OUT, "bindings.json"), "w") as f:
        json.dump({"bindings": binding, "ambiguous": amb, "definitions": {"0x%08x" % k: v for k, v in sorted(defs.items())},
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
        rep["link"] = link_inventory(binding, defs, {}, not a.no_link, set(amb))
    with open(os.path.join(OUT, "report.json"), "w") as f:
        json.dump(rep, f, indent=1)
    print(json.dumps(rep, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
