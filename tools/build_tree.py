#!/usr/bin/env python3
"""Verification build of the generated source tree (build/tree/, see tools/gen_tree.py).

  build/venv/bin/python tools/build_tree.py              # generate, compile, fall back, re-verify, report
  build/venv/bin/python tools/build_tree.py --jobs 4     # compiler processes (default 4; the box is shared)
  build/venv/bin/python tools/build_tree.py --rounds 8   # max fallback rounds
  build/venv/bin/python tools/build_tree.py --only src/game/global/CAction.cpp   # one TU, current state

Steps:
  1. Generate the tree from an empty fallback state (build/tree/state.json).
  2. Compile every TU with MSVC 7.1 under wibo, with tools/compare.py's flags (the defaults plus the TU's
     `// cl-flags:` line, which gen_tree.py writes for TUs of functions that need other flags) and
     `/I build/tree/include`. Objects are cached by content in build/tree-cache/obj/.
  3. Blame each compile error on what produced the line: a merged function's definition -> wrap that
     function; a TU-local shared declaration -> wrap the functions that use it; a header declaration ->
     keep that symbol out of headers; a wrapped function -> isolate it in its own TU. Regenerate and
     recompile until nothing new is blamed.
  4. Re-verify. matches/: the function's bytes in the merged object, compared with the XBE by
     compare.py's diff (relocations masked). equivalent/: compile check (the function's symbol exists).
     A match that stops matching is recompiled standalone to tell regressions from functions that do
     not match on their own either.
  5. Write build/tree/report.json and print a summary.
"""
import argparse
import collections
import hashlib
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import compare  # noqa: E402
import gen_tree  # noqa: E402
from xbe import Xbe  # noqa: E402

ROOT = gen_tree.ROOT
TREE = gen_tree.TREE
CACHE = os.path.join(ROOT, "build/tree-cache")
OBJ_CACHE = os.path.join(CACHE, "obj")
INCLUDE_DIR = os.path.join(TREE, "include")
ERR_RE = re.compile(r"^(.+?)\((\d+)\) : (?:fatal )?error (C\d+): (.*)$")


# ---------------------------------------------------------------------------------------------
# Compiling
def compile_tu(path, extra_inc=True):
    """Compile build/tree/<path> (cached by content). Returns (obj path or None, [error lines], log)."""
    src = os.path.join(TREE, path)
    text = open(src, "rb").read()
    incs = b""
    if extra_inc and os.path.isdir(INCLUDE_DIR):
        for name in sorted(_headers_used(text.decode("latin1"))):
            hp = os.path.join(INCLUDE_DIR, name)
            if os.path.exists(hp):
                incs += open(hp, "rb").read()
                # common.h comes in through the directory headers
                if name != "common.h" and os.path.exists(os.path.join(INCLUDE_DIR, "common.h")):
                    incs += open(os.path.join(INCLUDE_DIR, "common.h"), "rb").read()
    flags = compare.DEFAULT_FLAGS + compare.file_flags(src)
    h = hashlib.sha1(text + incs + gen_digest(text) + repr(flags).encode()).hexdigest()[:20]
    os.makedirs(OBJ_CACHE, exist_ok=True)
    obj = os.path.join(OBJ_CACHE, h + ".obj")
    log = os.path.join(OBJ_CACHE, h + ".log")
    if os.path.exists(obj):
        return obj, [], ""
    if os.path.exists(log):
        out = open(log).read()
        return None, parse_errors(out), out
    src_dir, name = os.path.split(src)
    inc = os.path.relpath(INCLUDE_DIR, src_dir)
    env = dict(os.environ, INCLUDE=os.path.join(compare.MSVC, "Include") + ";" + os.path.join(ROOT, "include"))
    tmp = obj + ".%d.tmp" % os.getpid()
    # include/ is on the path too: sources may `#include "gen/<ns>.h"` (include/gen/, tools/gen_headers.py) and
    # "decls/<x>.h" (pinned address-name prototypes)
    cmd = [compare.WIBO, os.path.join(compare.MSVC, "Bin/cl.exe")] + flags + [
        "/I" + inc, "/I" + os.path.relpath(GEN_INCLUDE_ROOT, src_dir), "/Fo" + tmp, name]
    try:
        r = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=src_dir, timeout=600,
                           errors="replace")
        out = r.stdout + r.stderr
        ok = r.returncode == 0 and os.path.exists(tmp)
    except subprocess.TimeoutExpired:
        out, ok = "%s(1) : error C9999: compiler timed out" % name, False
    if ok:
        os.replace(tmp, obj)
        return obj, [], out
    if os.path.exists(tmp):
        os.unlink(tmp)
    with open(log, "w") as f:
        f.write(out)
    errs = parse_errors(out)
    if not errs:
        errs = [(name, 1, "C0000", out.strip().splitlines()[-1] if out.strip() else "unknown failure")]
    return None, errs, out


GEN_INCLUDE_ROOT = os.path.join(ROOT, "include")
_GEN_DIGEST = []


def gen_digest(text):
    """Hash of include/gen/*.h and include/decls/*.h for sources that include them (part of the object cache key)."""
    if isinstance(text, bytes):
        text = text.decode("latin1")
    if "gen/" not in text and "decls/" not in text:
        return b""
    if not _GEN_DIGEST:
        hs = hashlib.sha1()
        for sub in ("gen", "decls"):
            d = os.path.join(GEN_INCLUDE_ROOT, sub)
            for fn in sorted(os.listdir(d)) if os.path.isdir(d) else []:
                if fn.endswith(".h"):
                    hs.update(sub.encode() + fn.encode() + open(os.path.join(d, fn), "rb").read())
        # include/decls/data/<layer>/<dir>.h (tools/data_gen.py)
        for dp, dns, fns in sorted(os.walk(os.path.join(GEN_INCLUDE_ROOT, "decls", "data"))):
            dns.sort()
            for fn in sorted(fns):
                if fn.endswith(".h"):
                    rel = os.path.relpath(os.path.join(dp, fn), GEN_INCLUDE_ROOT)
                    hs.update(rel.encode() + open(os.path.join(dp, fn), "rb").read())
        _GEN_DIGEST.append(hs.hexdigest().encode())
    return _GEN_DIGEST[0]


def _headers_used(text):
    return re.findall(r'^#include "([^"]+)"', text, re.M)


def parse_errors(out):
    errs = []
    for line in out.splitlines():
        m = ERR_RE.match(line.strip())
        if m:
            errs.append((m.group(1).replace("\\", "/"), int(m.group(2)), m.group(3), m.group(4)))
    return errs


def compile_all(paths, jobs):
    with ThreadPoolExecutor(jobs) as ex:
        res = list(ex.map(compile_tu, paths))
    return dict(zip(paths, res))


# ---------------------------------------------------------------------------------------------
# Blame
def blame(manifest, results, state):
    """Turn compile errors into fallback decisions. Returns number of new decisions."""
    new = 0
    state.setdefault("iso_plain", {})
    header_spans = manifest["headers"]
    for rec in manifest["tus"]:
        obj, errs, _ = results[rec["path"]]
        if obj is not None or not errs:
            continue
        tu_name = os.path.basename(rec["path"])
        acted = False
        for fname, line, code, msg in errs:
            why = "compile error %s: %s" % (code, msg[:120])
            if fname.endswith(".h"):
                hname = next((h for h in header_spans if fname.endswith(h)), None)
                if hname is None:
                    continue
                for s, e, key, norm in header_spans[hname]:
                    if s <= line <= e:
                        k = tuple(key)
                        if k not in state["local_only"]:
                            state["local_only"].add(k)
                            new += 1
                        acted = True
                continue
            if os.path.basename(fname) != tu_name:
                continue
            for s, e, key, norm, users in rec["locals"]:
                if s <= line <= e:
                    for a in users:
                        if a not in state["wrap"]:
                            state["wrap"][a] = "compile error in a shared declaration (%s)" % code
                            new += 1
                    acted = True
            for b in rec["blocks"]:
                s, e = b["lines"]
                if s <= line <= e:
                    a = int(b["addr"], 16)
                    if b["mode"] == "merged" and a not in state["wrap"]:
                        state["wrap"][a] = why
                        new += 1
                    elif b["mode"] == "wrapped" and a not in state["isolate"]:
                        state["isolate"][a] = why
                        new += 1
                    elif b["mode"] == "isolated" and b.get("tu_ns") and a not in state["iso_plain"]:
                        state["iso_plain"][a] = why       # its own TU without the TU namespace
                        new += 1
                    acted = True
        if not acted:
            # nothing attributable: wrap every merged function of this TU
            for b in rec["blocks"]:
                a = int(b["addr"], 16)
                if b["mode"] == "merged" and a not in state["wrap"]:
                    state["wrap"][a] = "unattributed compile error in TU"
                    new += 1
                elif b["mode"] == "isolated" and b.get("tu_ns") and a not in state["iso_plain"]:
                    state["iso_plain"][a] = "unattributed compile error in TU"
                    new += 1
    return new


# ---------------------------------------------------------------------------------------------
# Verification
class Verifier:
    def __init__(self):
        self.xbe = Xbe(compare.XBE_PATH)
        self.funcs = gen_tree.load_functions()
        self.coffs = {}

    def target(self, addr):
        size, _ = self.funcs[addr]
        o = self.xbe.offset(addr)
        return self.xbe.data[o:o + size]

    def coff(self, obj):
        c = self.coffs.get(obj)
        if c is None:
            c = self.coffs[obj] = compare.Coff(obj)
        return c

    def candidates(self, coff, block, claimed):
        """Function symbols in the object that can be this block's function."""
        syms = coff.function_symbols()
        if block["mode"] == "isolated":
            return syms, "all"
        tag = "@fn_%s@" % block["addr"][2:]
        if block["mode"] == "wrapped":
            c = [s for s in syms if tag in s[0]]
            plain = block.get("cnames", [])
            c += [s for s in syms if s[0] in plain or re.sub(r"@\d+$", "", s[0]) in plain]
            return c, "namespace"
        pre = block.get("prefixes", [])
        cn = set(block.get("cnames", []))
        c = [s for s in syms if any(s[0].startswith(p) for p in pre) or s[0] in cn
             or re.sub(r"@\d+$", "", s[0]) in cn]
        if c:
            return c, "name"
        # (not a wrapped block's fn_<addr> names; gen_tree's TU namespace fn_f<7 hex> is fine)
        return [s for s in syms if s[0] not in claimed and not WRAPPED_NS.search(s[0])], "loose"

    def check(self, obj, block, claimed):
        r = self._check(obj, block, claimed)
        if r["status"] != "match" and block["mode"] == "merged" and r.get("how") == "name":
            # the function can be one the compiler generated from the definition (a thunk, a deleting
            # destructor): try every unclaimed symbol of the TU
            r2 = self._check(obj, dict(block, prefixes=[], cnames=[]), claimed)
            if r2["status"] == "match":
                return r2
        return r

    def _check(self, obj, block, claimed, only=None):
        addr = int(block["addr"], 16)
        coff = self.coff(obj)
        cands, how = ([s for s in coff.function_symbols() if s[0] == only], "unique") if only else \
            self.candidates(coff, block, claimed)
        if not cands:
            return {"status": "no_function", "how": how}
        target = self.target(addr)
        best = None
        for sym in cands:
            name, ours, mask = coff.function(sym)
            d = compare.diff(target, compare.strip_padding(ours), mask)
            key = (d["exact"], d["matched"] / d["total"], -abs(d["target_bytes"] - d["our_bytes"]))
            if best is None or key > best[0]:
                best = (key, name, d)
            if d["exact"]:
                break
        (_, score, _), name, d = best
        return {"status": "match" if d["exact"] else "diff", "symbol": name, "how": how,
                "score": round(d["matched"] / d["total"], 3), "rows": d["rows"] if not d["exact"] else None}


MANGLE_OPS = {"operatornew": "??2", "operatordelete": "??3", "operator=": "??4", "operator==": "??8",
              "operator!=": "??9", "operator[]": "??A", "operator()": "??R", "operatornew[]": "??_U",
              "operatordelete[]": "??_V"}


def mangle_prefixes(qname, scope, c_linkage):
    """Mangled-name prefixes a definition of qname can have (MSVC), or [] if unsure."""
    parts = list(scope) + split_qualified(qname)
    if c_linkage and len(parts) == 1:
        return []          # C names are matched exactly (block "cnames")
    tpl = [i for i, p in enumerate(parts) if re.fullmatch(r"[A-Za-z_]\w*<.*>", p)]
    if tpl and not c_linkage:
        # a member of a class template specialization (`template <> R ns::X<T>::f()`): the mangled name
        # starts ?f@?$X@ (template arguments not spelled out here: the prefix is enough to find it)
        i = tpl[-1]
        last = parts[-1]
        cls = parts[i].split("<")[0]
        if i != len(parts) - 2 or not re.fullmatch(r"~?[A-Za-z_]\w*", last):
            return []
        if last == "~" + cls:
            # the destructor, or the deleting destructors generated from it
            return ["??%s?$%s@" % (op, cls) for op in ("1", "_G", "_E")]
        if last.startswith("~"):
            return []
        return ["?%s@?$%s@" % (last, cls)]
    if any(not re.fullmatch(r"~?[A-Za-z_]\w*", p) and not p.startswith("operator") for p in parts):
        return []
    last, quals = parts[-1], parts[:-1]
    q = "".join("%s@" % p for p in reversed(quals))
    if last.startswith("~"):
        # the destructor, or the scalar/vector deleting destructors generated from it
        return ["??%s%s@@" % (op, q.rstrip("@")) for op in ("1", "_G", "_E")] if quals else []
    if quals and last == quals[-1]:
        return ["??0%s@" % q.rstrip("@") + "@"]
    if last in MANGLE_OPS:
        return [MANGLE_OPS[last] + q + "@"]
    if last.startswith("operator"):
        return []
    return ["?%s@%s@" % (last, q.rstrip("@")) if q else "?%s@@" % last]


def split_qualified(q):
    """'a::B<x::y>::f' -> ['a', 'B<x::y>', 'f'] (`::` inside template arguments doesn't split)."""
    out, cur, depth, i = [], "", 0, 0
    while i < len(q):
        c = q[i]
        if c == "<":
            depth += 1
        elif c == ">":
            depth -= 1
        if depth == 0 and q.startswith("::", i):
            out.append(cur)
            cur = ""
            i += 2
            continue
        cur += c
        i += 1
    out.append(cur)
    return [p for p in out if p]


def block_names(gen):
    """addr -> (mangled-name prefixes in the tree, C names, prefixes in the standalone source) of the block's
    definitions (from the parsed sources). A merged definition inside its TU's namespace (gen_tree's TU
    namespace, `fn_f<7 hex>`) has that namespace in the tree's names but not in the standalone object's."""
    out = {}
    for tu in gen.tus:
        for b in tu.blocks:
            pre, cn, sa = [], [], []
            tu_ns = getattr(b, "tu_ns", None)
            for d in b.defs:
                qn = split_qualified(d.key[1])
                scope = list(d.scope)
                q = "::".join(qn[len(scope):]) if qn[:len(scope)] == scope else d.key[1]
                if "::" not in q:
                    # C linkage can come from an earlier extern "C" declaration: cdecl/stdcall, fastcall
                    # names (the @N suffix is dropped before comparing)
                    cn += ["_" + q, "@" + q]
                sa += mangle_prefixes(q, scope, d.c_linkage)
                pre += mangle_prefixes(q, [tu_ns] + scope, d.c_linkage) if tu_ns and not d.c_linkage else \
                    mangle_prefixes(q, scope, d.c_linkage)
            out[b.addr] = (pre, cn, sa)
    return out


def standalone_obj(src):
    """Object of a verified source compiled on its own (cached by content), or None if it doesn't compile."""
    text = open(os.path.join(ROOT, src), "rb").read()
    flags = compare.DEFAULT_FLAGS + compare.file_flags(os.path.join(ROOT, src))
    h = hashlib.sha1(text + gen_digest(text) + repr(flags).encode()).hexdigest()[:20]
    obj = os.path.join(OBJ_CACHE, "sa-" + h + ".obj")
    err = os.path.join(OBJ_CACHE, "sa-" + h + ".err")
    if os.path.exists(obj):
        return obj
    if os.path.exists(err):
        return None
    import tempfile
    os.makedirs(OBJ_CACHE, exist_ok=True)
    with tempfile.TemporaryDirectory() as tmp:
        try:
            o = compare.compile_obj(os.path.join(ROOT, src), compare.DEFAULT_FLAGS, tmp)
        except compare.CompileError as e:
            with open(err, "w") as f:
                f.write(str(e))
            return None
        os.replace(o, obj)
    return obj


def standalone(src, addr, verifier):
    """Compile a verified source on its own (cached) and compare: is it a match by itself?"""
    obj = standalone_obj(src)
    if obj is None:
        return {"status": "compile_error"}
    blk = {"addr": "0x%08x" % addr, "mode": "isolated"}
    return verifier.check(obj, blk, set())


TU_NS = re.compile(r"@fn_f[0-9a-f]{7}@")            # gen_tree's TU namespace
WRAPPED_NS = re.compile(r"@fn_00[0-9a-f]{6}@")      # a wrapped block's namespace (gen_tree: fn_<addr>)
ADDR_IN_NAME = re.compile(r"(?<![0-9A-Fa-f])([0-9A-Fa-f]{8})(?![0-9A-Fa-f])")


def code_of(coff, sym):
    """(bytes without padding, relocation offsets, relocation types, comparable relocation targets)."""
    _, raw, mask = coff.function(sym)
    raw = compare.strip_padding(raw)
    rel = []
    for off, tsym, typ, _ in coff.function_relocs(sym):
        if off >= len(raw):
            continue
        n = tsym[0] if tsym else ""
        m = ADDR_IN_NAME.search(TU_NS.sub("@", n))      # (a TU namespace's hex is not an address)
        key = ("addr", m.group(1).lower()) if m else ("const", n) if n.startswith(("__real@", "??_C@")) else ("sym", "")
        rel.append((off, typ, key))
    return raw, sorted(rel)


def same_code(c1, s1, c2, s2):
    """Do two compiled functions have the same code (bytes and relocation positions/kinds; relocation
    targets compared where they carry an address or are constants)?"""
    b1, r1 = code_of(c1, s1)
    b2, r2 = code_of(c2, s2)
    if b1 != b2 or len(r1) != len(r2):
        return False
    for (o1, t1, k1), (o2, t2, k2) in zip(r1, r2):
        if o1 != o2 or t1 != t2:
            return False
        if k1[0] == k2[0] and k1[0] in ("addr", "const") and k1 != k2:
            return False
    return True


def _loose_key(name):
    """A mangled name without the TU namespace and without the digits of its signature (back-references
    shift when the namespace is removed: `?f@A@fn_f1234567@@QAEPAV12@XZ` vs `?f@A@@QAEPAV1@XZ`). The
    qualified name before the first `@@` keeps its digits, so `FUN_0023d710` never matches `FUN_0023d420`."""
    head, sep, tail = TU_NS.sub("@", name).partition("@@")
    return head + sep + re.sub(r"\d", "", tail)


def standalone_symbol(coff, tree_name, addr, prefixes, cnames):
    syms = coff.function_symbols()
    plain = tree_name.replace("fn_%08x@" % addr, "") if tree_name else None
    for s in syms:
        if s[0] == plain:
            return s
    if plain and TU_NS.search(plain):
        # a merged definition in its TU's namespace (gen_tree): the standalone source has no namespace
        naive = TU_NS.sub("@", plain)
        for s in syms:
            if s[0] == naive:
                return s
    if plain:
        # (a wrapped block's own namespace is gone from `plain`, but the types its source declares still carry
        # it: `PAUFrame_14210@1@` in the tree is `PAUFrame_14210@@` standalone, and the back-references shift)
        k = _loose_key(plain)
        c = [s for s in syms if _loose_key(s[0]) == k]
        if len(c) == 1:
            return c[0]
    c = [s for s in syms if any(s[0].startswith(p) for p in prefixes) or s[0] in cnames
         or re.sub(r"@\d+$", "", s[0]) in cnames]
    return c[0] if len(c) == 1 else None


def compare_with_standalone(verifier, tree_obj, tree_sym, block, addr):
    """'same' if the function compiled in the tree is the code its own source compiles to, 'differs',
    or why it can't tell."""
    sa = standalone_obj(block["src"])
    if sa is None:
        return "standalone_compile_error"
    tc, sc = verifier.coff(tree_obj), verifier.coff(sa)
    tsym = next((s for s in tc.function_symbols() if s[0] == tree_sym), None)
    ssym = standalone_symbol(sc, tree_sym, addr, block.get("sa_prefixes", block.get("prefixes", [])),
                             block.get("cnames", []))
    if tsym is None or ssym is None:
        return "no_symbol"
    return "same" if same_code(tc, tsym, sc, ssym) else "differs"


def diff_reason(tree_rows, sa_rows):
    """Short description of how the merged function differs."""
    if not tree_rows:
        return "?"
    bad = [r for r in tree_rows if r[0] != "  "]
    calls_t = [r for r in bad if r[2].startswith("call") or r[3].startswith("call")]
    if any(r[0] == "--" and r[2].startswith("call") for r in bad):
        return "a call became inline code (callee now defined in the same TU)"
    if calls_t:
        return "call sequence differs"
    return "codegen differs (%d of %d instructions)" % (len(bad), len(tree_rows))


# ---------------------------------------------------------------------------------------------
def run(jobs=4, rounds=8, fresh=True):
    state = {"wrap": {}, "isolate": {}, "local_only": set(), "iso_plain": {}} if fresh else gen_tree.load_state()
    history = []
    for rnd in range(1, rounds + 1):
        gen = gen_tree.generate(state)
        gen_tree.save_state(state)
        manifest = gen.manifest
        paths = [t["path"] for t in manifest["tus"]]
        results = compile_all(paths, jobs)
        failed = [p for p in paths if results[p][0] is None]
        new = blame(manifest, results, state)
        history.append({"round": rnd, "tus": len(paths), "failed": len(failed), "new_fallbacks": new})
        print("round %d: %d TUs, %d failed, %d new fallbacks" % (rnd, len(paths), len(failed), new), flush=True)
        if not failed:
            break
        if not new or rnd == rounds - 1:
            # last resort: every function of a still-failing TU gets its own TU
            for rec in manifest["tus"]:
                if results[rec["path"]][0] is None:
                    for b in rec["blocks"]:
                        a = int(b["addr"], 16)
                        if a not in state["isolate"]:
                            state["isolate"][a] = "TU still failing after %d rounds" % rnd
                            new += 1
                        elif b.get("tu_ns") and b["mode"] == "isolated" and a not in state["iso_plain"]:
                            state["iso_plain"][a] = "TU still failing after %d rounds" % rnd
                            new += 1
            if not new:
                break
    gen_tree.save_state(state)
    return gen, manifest, results, history, state


def precompile_standalone(manifest, jobs):
    """Standalone objects of every equivalent/ source in the tree (they are compared with the tree's code)."""
    srcs = sorted({b["src"] for rec in manifest["tus"] for b in rec["blocks"] if b["kind"] == "equivalent"})
    with ThreadPoolExecutor(jobs) as ex:
        list(ex.map(standalone_obj, srcs))


def regressions(checks):
    """Functions whose code in the tree differs from their verified source's: a match that stopped matching
    (and matches standalone), or an equivalent/ function whose bytes differ from its standalone build."""
    out = {}
    for c in checks:
        mode = "isolated+ns" if c["mode"] == "isolated" and c.get("tu_ns") else c["mode"]
        if c["kind"] == "matches" and c["status"] != "match" and c.get("standalone") == "match":
            out[int(c["addr"], 16)] = (mode, "lost its match in the tree (%s)" % c.get("why", c["status"]))
        elif c["kind"] == "equivalent" and c.get("vs_standalone") == "differs":
            out[int(c["addr"], 16)] = (mode, "code differs from its standalone build")
        elif c.get("shared_symbol") == "ambiguous" and c["mode"] == "merged":
            # (unique_symbols: its own definition is not in the TU's object under a name it can be told by;
            # wrapped, it gets its fn_<addr> namespace and is checked under that)
            out[int(c["addr"], 16)] = (mode, "checked against another function's symbol (ambiguous lookup)")
    return out


def verify(gen, manifest, results, jobs=4):
    precompile_standalone(manifest, jobs)
    v = Verifier()
    names = block_names(gen)
    out = []
    for rec in manifest["tus"]:
        obj = results[rec["path"]][0]
        claimed = set()
        pairs = []
        for b in rec["blocks"]:
            a = int(b["addr"], 16)
            pre, cn, sa = names.get(a, ([], [], []))
            b["prefixes"], b["cnames"], b["sa_prefixes"] = pre, cn, sa
            r = {"addr": b["addr"], "name": b["name"], "src": b["src"], "kind": b["kind"], "mode": b["mode"],
                 "tu": rec["path"]}
            if b.get("tu_ns"):
                r["tu_ns"] = b["tu_ns"]
            if obj is None:
                r["status"] = "tu_failed"
            elif b["kind"] == "equivalent":
                c = v.check(obj, b, claimed)
                r["status"] = "compiled" if c["status"] != "no_function" else "no_function"
                r["symbol"] = c.get("symbol")
                r["how"] = c.get("how")
                if c.get("symbol"):
                    claimed.add(c["symbol"])
                    r["vs_standalone"] = compare_with_standalone(v, obj, c["symbol"], b, a)
            else:
                c = v.check(obj, b, claimed)
                r.update({k: c[k] for k in ("status", "symbol", "how", "score") if k in c})
                if c.get("symbol"):
                    claimed.add(c["symbol"])
                if c["status"] != "match":
                    sa = standalone(b["src"], a, v)
                    r["standalone"] = sa["status"]
                    if sa["status"] == "match" and c["status"] == "diff":
                        r["why"] = diff_reason(c.get("rows"), sa.get("rows"))
            out.append(r)
            pairs.append((b, r))
        if obj is not None:
            unique_symbols(v, obj, pairs)
    return out


def own_symbol(v, b):
    """The function's own symbol in its standalone object: the one that matches the original (or the best one)."""
    obj = standalone_obj(b["src"])
    if obj is None:
        return None
    r = v.check(obj, {"addr": b["addr"], "mode": "isolated"}, set())
    return r.get("symbol")


SUFFIXES = re.compile(r"_[0-9a-f]{4,8}(?=@)")      # placeholder suffixes (`Obj_14940@`): addresses, kept apart


def own_candidates(own, syms, tag):
    """Tree symbols that are `own` (a standalone symbol): equal under _loose_key, then with struct/class
    (U/V) not told apart (the tree's merged declaration can be the other keyword), then the placeholder suffixes
    (which _loose_key's digit removal blurs: `Obj_14860` / `Obj_14940`) breaking a tie."""
    if not own:
        return []
    k = _loose_key(own)
    lk = {s: _loose_key(s.replace(tag, "")) for s in syms}
    c = [s for s in syms if lk[s] == k]
    if not c:
        uv = re.sub(r"[UV]", "V", k)
        c = [s for s in syms if re.sub(r"[UV]", "V", lk[s]) == uv]
    if len(c) > 1:
        sx = SUFFIXES.findall(own)
        c2 = [s for s in c if SUFFIXES.findall(TU_NS.sub("@", s.replace(tag, ""))) == sx]
        c = c2 or c
    return c


def unique_symbols(v, obj, pairs):
    """The lookup by mangled-name prefix (mangle_prefixes: no parameter types, no template arguments) can check
    two functions of one TU against one symbol: overloads `Target(PhysicsJoint_30cbb0*)` /
    `Target(PhysicsJoint_30cd60*)`, or every instantiation of `Method2<CActorManager, ...>::~Method2` against
    the first. With relocations masked, clones then "match" under each other's symbol and the native link binds
    them to one address. Where the functions' original bytes differ, each is re-checked against the tree symbol
    whose name is its own standalone symbol's (TU namespace and back-reference digits aside, _loose_key);
    one without such a symbol is marked `shared_symbol: ambiguous` and, being unverifiable, gets status
    `ambiguous` (matches) / vs_standalone `ambiguous` (equivalent/), which regressions() turns into a fallback
    (merged -> wrapped). Groups whose original bytes are identical are harmless (`shared_symbol: identical`)."""
    groups = collections.defaultdict(list)
    for b, r in pairs:
        if r.get("symbol") and b["mode"] != "isolated":
            groups[r["symbol"]].append((b, r))
    syms = None
    for sym, grp in groups.items():
        if len(grp) < 2:
            continue
        if len({v.target(int(b["addr"], 16)) for b, _ in grp}) == 1:
            for _, r in grp:
                r["shared_symbol"] = "identical"
            continue
        if syms is None:
            syms = v.coff(obj).function_symbols()
        for b, r in grp:
            own = own_symbol(v, b)
            k = _loose_key(own) if own else None
            tag = "fn_%s@" % b["addr"][2:]          # a wrapped block's namespace (not in the standalone name)
            c = own_candidates(own, [s[0] for s in syms], tag)
            if len(c) == 1 and c[0] == sym:
                r["shared_symbol"] = "owner"
                continue
            if len(c) != 1:
                r["shared_symbol"] = "ambiguous"
                if b["kind"] == "equivalent":
                    r["vs_standalone"] = "ambiguous"
                else:
                    r["status"] = "ambiguous"
                    r["standalone"] = standalone(b["src"], int(b["addr"], 16), v)["status"]
                continue
            c2 = v._check(obj, b, set(), only=c[0])
            r["shared_symbol"] = "resolved"
            r["symbol"], r["how"] = c2.get("symbol"), "unique"
            a = int(b["addr"], 16)
            if b["kind"] == "equivalent":
                r["vs_standalone"] = compare_with_standalone(v, obj, c[0], b, a)
            else:
                r["status"], r["score"] = c2["status"], c2.get("score")
                if c2["status"] != "match":
                    sa = standalone(b["src"], a, v)
                    r["standalone"] = sa["status"]
                    if sa["status"] == "match" and c2["status"] == "diff":
                        r["why"] = diff_reason(c2.get("rows"), sa.get("rows"))


def summarize(manifest, results, checks, history, gen, state):
    tus = manifest["tus"]
    ok = [t for t in tus if results[t["path"]][0] is not None]
    bad = [t for t in tus if results[t["path"]][0] is None]
    causes = collections.Counter()
    examples = {}
    for t in bad:
        for fname, line, code, msg in results[t["path"]][1][:1]:
            k = "%s %s" % (code, re.sub(r"'[^']*'", "'X'", msg)[:80])
            causes[k] += 1
            examples.setdefault(k, "%s(%d)" % (t["path"], line))
    st = collections.Counter((c["kind"], c["status"]) for c in checks)
    m = [c for c in checks if c["kind"] == "matches"]
    m_by_mode = collections.Counter((c["mode"], c["status"]) for c in m)
    lost = [c for c in m if c["status"] != "match"]
    lost_why = collections.Counter(
        ("regression: " + c.get("why", c["status"])) if c.get("standalone") == "match" else
        ("not a match standalone either (%s)" % c.get("standalone")) for c in lost)
    return {
        "rounds": history,
        "tu_files": len(tus),
        "tu_compiled": len(ok),
        "tu_failed": len(bad),
        "tu_failure_causes": [{"cause": k, "tus": v, "example": examples[k]} for k, v in causes.most_common()],
        "functions": {"%s/%s" % k: v for k, v in sorted(st.items())},
        "matches_by_mode": {"%s/%s" % k: v for k, v in sorted(m_by_mode.items())},
        "matches_total": len(m),
        "matches_still_matching": sum(1 for c in m if c["status"] == "match"),
        "matches_lost": len(lost),
        "matches_lost_why": dict(lost_why.most_common()),
        "symbol_lookup": dict(collections.Counter(c.get("how") for c in checks if c.get("how"))),
        "shared_symbols": dict(collections.Counter(c["shared_symbol"] for c in checks if c.get("shared_symbol"))),
        "equivalent_vs_standalone": dict(collections.Counter(
            "%s/%s" % (c["mode"], c.get("vs_standalone")) for c in checks if c["kind"] == "equivalent")),
        "regressions_left": len(regressions(checks)),
        "by_layer": by_layer(tus, results, checks),
        "fallbacks": {"wrapped_by_build": len(state["wrap"]), "isolated_by_build": len(state["isolate"]),
                      "header_symbols_kept_local": len(state["local_only"]),
                      "isolated_without_tu_namespace": len(state.get("iso_plain", {}))},
        "generator": gen_tree.summary(gen),
    }


def by_layer(tus, results, checks):
    """TUs compiled and functions per layer (src/<layer>/...; docs/shipping.md §1)."""
    layer_of = {t["path"]: t.get("layer", "game") for t in tus}
    out = collections.defaultdict(collections.Counter)
    for t in tus:
        d = out[layer_of[t["path"]]]
        d["tu_files"] += 1
        d["tu_compiled"] += results[t["path"]][0] is not None
    for c in checks:
        d = out[layer_of.get(c["tu"], "game")]
        d["%s/%s" % (c["kind"], c["mode"])] += 1
        if c["kind"] == "matches":
            d["matches_still_matching"] += c["status"] == "match"
        else:
            d["equivalent_compiled"] += c["status"] == "compiled"
    return {k: dict(sorted(v.items())) for k, v in sorted(out.items())}


def run_equiv(checks, results, limit):
    """equiv.verify on the tree's objects (obj_path + symbol): behaviour check of equivalent/ functions.

    Caveat: functions defined in the same object run as our own code (equiv.py treats them like inlined
    helpers) instead of being bound to the original's addresses."""
    import equiv
    todo = [c for c in checks if c["kind"] == "equivalent" and c["status"] == "compiled" and c.get("symbol")]
    if limit:
        todo = todo[:limit]
    by_tu = {}
    for c in todo:
        by_tu.setdefault(c["tu"], []).append(c)
    st = collections.Counter()
    for tu, cs in by_tu.items():
        obj = results[tu][0]
        for c in cs:
            try:
                rep = equiv.verify(os.path.join(ROOT, c["src"]), int(c["addr"], 16), symbol=c["symbol"], obj_path=obj)
                c["equiv"] = rep["status"]
            except Exception as e:  # noqa: BLE001 - a crash in one function must not stop the report
                c["equiv"] = "error: %s" % type(e).__name__
            st[c["equiv"]] += 1
    return dict(st)


def run_data(manifest, results, jobs):
    """Data TUs next to the tree (docs/data.md): their own verification, then a link check of the tree's objects."""
    import data_gen
    model = data_gen.Model()
    tus = data_gen.generate(model)
    with ThreadPoolExecutor(jobs) as ex:
        res = list(ex.map(lambda t: data_gen.compile_tu(t[0]), tus))
    st = collections.Counter()
    for (p, items, _), (obj, err) in zip(tus, res):
        st["tus"] += 1
        st["tus_compiled"] += obj is not None
        for r in data_gen.verify_tu(model, p, items, obj, err):
            st["items"] += 1
            st["items_verified"] += r["status"] == "match"
    out = dict(st)
    out["link"] = data_gen.link_check({t["path"]: results[t["path"]][0] for t in manifest["tus"]}, model,
                                      defined_syms=data_gen.defined_symbols(o for o, _ in res))
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--rounds", type=int, default=8)
    ap.add_argument("--resume", action="store_true", help="start from build/tree/state.json instead of empty")
    ap.add_argument("--regression-rounds", type=int, default=4, metavar="N",
                    help="rebuild up to N times, falling back functions whose code changed in the tree (default 4)")
    ap.add_argument("--only", help="compile one TU of the current tree and print its errors")
    ap.add_argument("--equiv", type=int, metavar="N", help="also run tools/equiv.py (64 inputs) on the merged "
                    "object for the first N equivalent/ functions (0 = all; slow: 1-5 s each)")
    ap.add_argument("--data", action="store_true", help="also build the data TUs (tools/data_gen.py: generate, "
                    "compile, byte-check every item) and check how the tree's DAT_ references resolve against them")
    a = ap.parse_args(argv)
    if a.only:
        obj, errs, out = compile_tu(a.only)
        print(out if obj is None else "OK " + obj)
        return 0 if obj else 1
    gen, manifest, results, history, state = run(a.jobs, a.rounds, fresh=not a.resume)
    checks = verify(gen, manifest, results, a.jobs)
    escalated = {}      # addr -> (state key, reason): wrapped -> isolated escalations made by the regression rounds
    for rnd in range(a.regression_rounds):
        # a function whose code changed in the tree falls back: merged -> wrapped -> isolated
        reg = regressions(checks)
        new = 0
        # Escalations settle merged neighbours first: in a TU where a merged function regressed, a wrapped or
        # isolated function of the same object that also regressed keeps its mode this round and is checked again
        # once its merged neighbours have been wrapped (a merged neighbour's declarations can change a wrapped
        # function's code: 0x2ea3c0 differed only while 0x2e9880 was merged next to it, and fallbacks are never
        # undone, so escalating both at once made the result depend on which TUs failed first). Not on the last
        # round: nothing whose code differs may be left in place.
        # the object a TU belongs to: `X.cpp`, `X.GS.cpp`, `X.iso_<addr>.cpp`, `X.new_<n>.cpp` -> X
        unit = {int(c["addr"], 16): os.path.join(os.path.dirname(c["tu"]), os.path.basename(c["tu"]).split(".", 1)[0])
                for c in checks}
        merged_units = {unit.get(addr) for addr, (mode, _w) in reg.items() if mode == "merged"}
        last = rnd == a.regression_rounds - 1
        deferred = {addr for addr, (mode, _w) in reg.items()
                    if mode != "merged" and not last and unit.get(addr) in merged_units}
        # blocks wrapped only because a regressed merged function had the same definition would merge next
        # round in its place, usually with the same problem (one round per clone): wrap them now
        twins = collections.defaultdict(list)
        for rec in manifest["tus"]:
            for b in rec["blocks"]:
                for r in b["reasons"]:
                    m = re.match(r"same definition as (0x[0-9a-f]{8}) in this TU", r)
                    if m:
                        twins[int(m.group(1), 16)].append(int(b["addr"], 16))
        for addr, (mode, why) in reg.items():
            if addr in deferred:
                continue
            if mode == "merged":
                for t in twins.get(addr, ()):
                    if t not in state["wrap"]:
                        state["wrap"][t] = "same definition as 0x%08x, which %s" % (addr, why)
                        new += 1
            if mode == "merged" and addr not in state["wrap"]:
                state["wrap"][addr] = why
                new += 1
            elif mode == "wrapped" and addr not in state["isolate"]:
                state["isolate"][addr] = why
                escalated[addr] = ("isolate", why)
                new += 1
            elif mode == "isolated+ns" and addr not in state.setdefault("iso_plain", {}):
                state["iso_plain"][addr] = why
                escalated[addr] = ("iso_plain", why)
                new += 1
        if not new and deferred:
            # nothing else moved: the deferred ones escalate now (their neighbours cannot settle any further)
            for addr in sorted(deferred):
                mode, why = reg[addr]
                if mode == "wrapped" and addr not in state["isolate"]:
                    state["isolate"][addr] = why
                    escalated[addr] = ("isolate", why)
                    new += 1
                elif mode == "isolated+ns" and addr not in state.setdefault("iso_plain", {}):
                    state["iso_plain"][addr] = why
                    escalated[addr] = ("iso_plain", why)
                    new += 1
            deferred = set()
        print("regressions: %d (%d new fallbacks%s)" % (len(reg), new,
                                                         ", %d deferred" % len(deferred) if deferred else ""), flush=True)
        if deferred:
            print("  deferred: %s" % " ".join("0x%08x" % x for x in sorted(deferred)), flush=True)
        if not new:
            break
        gen_tree.save_state(state)
        gen, manifest, results, h2, state = run(a.jobs, a.rounds, fresh=False)
        history += h2
        checks = verify(gen, manifest, results, a.jobs)
    # Re-check the escalations once everything else has settled: a wrapped function isolated in an early round may
    # have differed only because of a neighbour that a later round moved. Undo them, rebuild, and re-apply only those
    # that still differ (fallbacks are otherwise never undone, which made the tree depend on the order of rounds).
    if escalated and a.regression_rounds:
        for addr, (key, _why) in escalated.items():
            state[key].pop(addr, None)
        gen_tree.save_state(state)
        gen, manifest, results, h2, state = run(a.jobs, a.rounds, fresh=False)
        history += h2
        checks = verify(gen, manifest, results, a.jobs)
        back = 0
        for _ in range(2):
            reg = regressions(checks)
            new = 0
            for addr, (mode, why) in sorted(reg.items()):
                if mode == "merged" and addr not in state["wrap"]:
                    state["wrap"][addr] = why
                    new += 1
                elif mode == "wrapped" and addr not in state["isolate"]:
                    state["isolate"][addr] = why
                    new += 1
                elif mode == "isolated+ns" and addr not in state.setdefault("iso_plain", {}):
                    state["iso_plain"][addr] = why
                    new += 1
            back += new
            if not new:
                break
            gen_tree.save_state(state)
            gen, manifest, results, h2, state = run(a.jobs, a.rounds, fresh=False)
            history += h2
            checks = verify(gen, manifest, results, a.jobs)
        print("recheck: %d escalations undone, %d fallbacks re-applied; %d regressions left"
              % (len(escalated), back, len(regressions(checks))), flush=True)
    rep = summarize(manifest, results, checks, history, gen, state)
    if a.equiv is not None:
        rep["equiv_on_merged_objects"] = run_equiv(checks, results, a.equiv)
    if a.data:
        rep["data"] = run_data(manifest, results, a.jobs)
    with open(os.path.join(TREE, "report.json"), "w") as f:
        json.dump(dict(rep, checks=checks), f, indent=1)
    rep.pop("generator")
    print(json.dumps(rep, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
