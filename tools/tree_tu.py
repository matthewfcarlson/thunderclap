#!/usr/bin/env python3
"""Tree TUs as the unit of work (merge-once stage 1, docs/merge-once.md).

A tree TU is one translation unit of the merged source tree (tools/gen_tree.py; build/tree/src/... today, the committed
src/{game,engine,platform/xbox}/ after the flip) with many functions, each introduced by its block line
`// 0xADDR NAME (SIZE B): matches/0xADDR.cpp [wrapped: why]`. The checkers take a TU plus an address in place of a
per-function source and check that function inside the TU's object:

  build/venv/bin/python tools/compare.py TU.cpp 0xADDR             # the function's bytes in the TU's MSVC object
  build/venv/bin/python tools/verify_relocs.py TU.cpp --addr 0xADDR --json
  build/venv/bin/python tools/equiv.py TU.cpp 0xADDR [--wine | --x64] --json   # the TU's object, the block's directives
  build/venv/bin/python tools/tree_tu.py blocks TU.cpp             # the functions of a TU: address, kind, mode, symbol
  build/venv/bin/python tools/tree_tu.py check TU.cpp [--relocs] [--equiv N] [--json]   # every function of one TU
  build/venv/bin/python tools/tree_tu.py verify ROOT [--changed-since REF | --tus FILE] [--jobs N] [--out OUT.jsonl]
  build/venv/bin/python tools/tree_tu.py pin ROOT [--report report.json]   # write `// sym:` lines (see below)
  build/venv/bin/python tools/tree_tu.py hash TU.cpp --proven MSVC.json WINE.json   # record re-proven code hashes

How a function is found in its TU's object (the same rules as tools/build_tree.py's Verifier, so a tree that verified
there verifies here): its pinned symbol (a `// sym: <mangled name>` line right after the block line) when the object
has it; else the mangled-name prefixes of the block's out-of-line definitions (parsed from the TU itself:
tools/cxx_items.py, with the namespaces they sit in), the `@fn_<addr>@` namespace of a wrapped block, any function of an
isolated TU, and for a merged block whose prefixes find nothing, any function no earlier block claimed. A match is the
best-scoring candidate (compare.diff), as in build_tree. Two blocks that land on one symbol while their original bytes
differ can't be told apart without their standalone sources (build_tree.unique_symbols): where those sources still
exist this tool resolves them the same way; once they are gone a pinned symbol is what tells them apart, so `pin`
records every function's symbol before the per-function sources are retired.
A function that is one of MSVC's numbered `$L` labels (funclets, catch blocks) is pinned as `$L#<k>@<owner>`, the
k-th label of its owning function, since the label numbers move with any header edit (label pins below).

Code hashes (docs/merge-once.md "Code hashes", tools/code_hash.py): an equivalent block's pin line also records the
hashes of the code that was proven, `// sym: PIN @<MSVC object> @w<clang --wine object>`. check / verify / materialize
recompute them (`--no-wine-code` skips the clang one) and fail a block whose code changed (`code_changed`) or that has
none (`unhashed`; `pending` while its TU is listed in config/code-hash-pending.txt, which doesn't fail); `hash --proven`
records new values only from equiv.py runs of the code as it is now (3,000 inputs promotable, --wine at 600).

A block's directives (`// equiv-map:`, `// equiv-conv:`, `// equiv-dead:`) are the lines between its block line and
the next block (HULK_GEN_TREE_NOTES=1 makes gen_tree keep a merged source's notes there).

Objects: build_tree's compile (MSVC 7.1 under wibo, compare.py's flags + the TU's `// cl-flags:` line, /I the tree's
include/ and the repo's include/), cached by content in build/tree-cache/obj/ (the TU's text, flags and every header
it can reach). Verification records are cached in build/tree-cache/tuverify/ by the object's key, the TU's block
records, the checker code and the XBE: `verify` over an unchanged tree compiles and checks nothing (incremental: only
TUs whose text or headers changed are compiled and checked again).
"""
import argparse
import bisect
import collections
import contextlib
import hashlib
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
BLOCK = re.compile(r"^// (0x[0-9a-f]{8}) (.+?) \((\d+) B\): (matches|equivalent)(?:/0x[0-9a-f]{8}\.cpp)?"
                   r"(?: \[(wrapped|isolated)(?::.*)?\])?\s*$")     # (a reason can hold brackets: `Cell [100] cells`)
PLACEHOLDER = re.compile(r"^// 0x[0-9a-f]{8} .+ \(\d+ B\): not yet verified\s*$")
SYM_LINE = re.compile(r"^// sym: (\S+)((?:[ \t]+@w?[0-9a-f]{12})*)\s*$")   # the pin, then the code hashes
HASH_TOKEN = re.compile(r"@(w?)([0-9a-f]{12})")     # `@<hex>` the MSVC object's code, `@w<hex>` the clang object's
DIRECTIVE = re.compile(r"^\s*//\s*equiv-(?:map|conv|dead|name):")
PRELUDE = "tree_prelude.h"
# HULK_TREE_TU_OFF=pins,relocpick: ignore `// sym:` lines / don't prefer the reloc-correct one of several exact candidates
# (both off = build_tree.py's own choice of symbol, for A/B against a tree build)
OFF = set(os.environ.get("HULK_TREE_TU_OFF", "").split(","))
ACTIVE = []         # the include/ directory of the tree TU being checked (compare.compile_obj, equiv's clang compiles)


# ------------------------------------------------------------------------------------------------------- locating
def find_root(path):
    """The tree root above PATH: the nearest directory whose include/ holds tree_prelude.h (build/tree, or the
    checkout once the tree is committed), or None."""
    d = os.path.dirname(os.path.abspath(path))
    while True:
        if os.path.exists(os.path.join(d, "include", PRELUDE)):
            return d
        nd = os.path.dirname(d)
        if nd == d:
            return None
        d = nd


_IS = {}


def is_tree_tu(path):
    """Is PATH a tree TU (a .cpp under a tree root with at least one block line)? Per-function sources never are."""
    if not path or not path.endswith(".cpp") or not os.path.isfile(path):
        return False
    ap = os.path.abspath(path)
    parts = ap.split(os.sep)
    if len(parts) >= 2 and parts[-2] in ("matches", "equivalent"):
        return False
    st = os.stat(ap)
    k = (ap, st.st_mtime_ns, st.st_size)
    if k not in _IS:
        ok = False
        if find_root(ap):
            with open(ap, errors="replace") as f:
                ok = any(BLOCK.match(l) for l in f)
        _IS[k] = ok
    return _IS[k]


def include_dir(path):
    r = find_root(path)
    return os.path.join(r, "include") if r else None


@contextlib.contextmanager
def active(path):
    """While checking a tree TU: compare.compile_obj and equiv's clang compiles add the tree's include/ (probes and
    wrappers are compiled from temporary copies, which can't find it by their own path)."""
    inc = include_dir(path) if is_tree_tu(path) else None
    if inc:
        ACTIVE.append(inc)
    try:
        yield inc
    finally:
        if inc:
            ACTIVE.pop()


def msvc_include_flags(src_dir):
    """Extra cl.exe flags for a compile in SRC_DIR (compare.compile_obj): /I the active tree's include/, the repo's
    include/ (build_tree.compile_tu's order)."""
    if not ACTIVE:
        return []
    return ["/I" + os.path.relpath(ACTIVE[-1], src_dir), "/I" + os.path.relpath(os.path.join(ROOT, "include"), src_dir)]


def clang_include_flags():
    return ["-I" + ACTIVE[-1]] if ACTIVE else []


# ------------------------------------------------------------------------------------------------------- blocks
def scan(path):
    """A manifest record of the TU, as gen_tree writes it (path relative to the tree root, blocks with addr, name,
    src, kind, mode, lines) plus per block: `sym` (a pinned symbol or None), `notes` (its directive lines), `ns`
    (fn_<addr> of a wrapped block), and the names build_tree's Verifier looks for (`prefixes`, `cnames`)."""
    ap = os.path.abspath(path)
    root = find_root(ap)
    text = open(ap, errors="replace").read()
    lines = text.splitlines()
    marks = []
    for i, l in enumerate(lines):
        m = BLOCK.match(l)
        if m:
            marks.append((i, m))
        elif PLACEHOLDER.match(l):
            marks.append((i, None))
    blocks = []
    for j, (i, m) in enumerate(marks):
        if m is None:
            continue
        end = marks[j + 1][0] if j + 1 < len(marks) else len(lines)
        while end > i + 1 and not lines[end - 1].strip():
            end -= 1
        addr, name, size, kind, mode = m.group(1), m.group(2), int(m.group(3)), m.group(4), m.group(5) or "merged"
        sym = hsh = whsh = None
        k = i + 1
        if k < end and SYM_LINE.match(lines[k]):
            sm = SYM_LINE.match(lines[k])
            sym = sm.group(1)
            for w, hx in HASH_TOKEN.findall(sm.group(2)):
                if w:
                    whsh = hx
                else:
                    hsh = hx
        src = re.search(r": ((?:matches|equivalent)/0x[0-9a-f]{8}\.cpp)", lines[i])
        blocks.append({"addr": addr, "name": name, "size": size, "kind": kind, "mode": mode,
                       "src": src.group(1) if src else "%s/%s.cpp" % (kind, addr),
                       "lines": [i + 1, end], "sym": sym, "hash": hsh, "whash": whsh, "ns": "fn_%s" % addr[2:] if mode == "wrapped" else None,
                       "notes": [l for l in lines[i + 1:end] if DIRECTIVE.match(l)]})
    rec = {"path": os.path.relpath(ap, root) if root else ap, "root": root, "blocks": blocks}
    m = re.search(r"^namespace (fn_f[0-9a-f]{7}) \{", text, re.M)       # (the TU namespace, gen_tree's fn_f<7 hex>)
    if m:
        rec["tu_ns"] = m.group(1)
    _names(text, blocks)
    return rec


NS_OPEN = re.compile(r"^namespace (fn_f?[0-9a-f]{7,8}) \{\s*$")
NS_CLOSE = re.compile(r"^\} // namespace (fn_f?[0-9a-f]{7,8})\s*$")


def _names(text, blocks):
    """Per block, the Verifier's `prefixes` and `cnames` (build_tree.block_names), and the standalone source's
    (`sa_prefixes`), from the block's own text parsed in the namespaces gen_tree opened around it (its `namespace X {`
    / `} // namespace X` lines). Per block, not per TU: one wrapped source's verbatim text that the shallow parser can't
    follow must not cost the other blocks their names."""
    import build_tree
    import cxx_items
    lines = text.split("\n")
    stack, at = [], {}
    starts = {b["lines"][0]: b for b in blocks}
    for i, l in enumerate(lines, 1):
        if i in starts:
            at[i] = list(stack)
        m = NS_OPEN.match(l)
        if m:
            stack.append(m.group(1))
            continue
        m = NS_CLOSE.match(l)
        if m and stack and stack[-1] == m.group(1):
            stack.pop()
    for b in blocks:
        b["prefixes"], b["cnames"], b["sa_prefixes"] = [], [], []
        if b["mode"] == "isolated":
            continue            # (any function of its TU; wrapped blocks need their C names: `_FUN_x` ignores namespaces)
        lo, hi = b["lines"]
        try:
            # (the namespace lines gen_tree puts between blocks are not the block's)
            items = cxx_items.parse("\n".join("" if NS_OPEN.match(l) or NS_CLOSE.match(l) else l
                                              for l in lines[lo - 1:hi]))
        except (ValueError, IndexError, RecursionError):
            b["parse_error"] = True
            continue
        outer = at.get(lo, [])
        for it in items:
            if it.kind != "funcdef" or it.is_inline or not it.key or it.key[0].startswith("template"):
                continue
            scope = outer + list(it.scope)
            qn = build_tree.split_qualified(it.key[1])
            inner = list(it.scope)
            q = "::".join(qn[len(inner):]) if qn[:len(inner)] == inner else it.key[1]
            if "::" not in q:
                b["cnames"] += ["_" + q, "@" + q]
            b["prefixes"] += build_tree.mangle_prefixes(q, scope, it.c_linkage)
            # (the standalone source's names: no TU namespace)
            b["sa_prefixes"] += build_tree.mangle_prefixes(
                q, [x for x in scope if not re.fullmatch(r"fn_f?[0-9a-f]{7,8}", x)], it.c_linkage)
    return True


def block(path, addr):
    """(TU record, the block at ADDR) or raise KeyError."""
    rec = scan(path)
    a = "0x%08x" % (addr if isinstance(addr, int) else int(addr, 16))
    for b in rec["blocks"]:
        if b["addr"] == a:
            return rec, b
    raise KeyError("%s has no block for %s" % (path, a))


def block_lines(path, addr):
    """The text lines of the block at ADDR (its directives live here)."""
    rec, b = block(path, addr)
    lines = open(path, errors="replace").read().splitlines()
    return lines[b["lines"][0] - 1:b["lines"][1]]


def unit_text(path, addr):
    """The text a checker reads a function's own declarations from: the TU's shared part (everything before its first
    block) and the function's block, as if it were the function's own source."""
    rec, b = block(path, addr)
    lines = open(path, errors="replace").read().splitlines()
    first = rec["blocks"][0]["lines"][0] if rec["blocks"] else 1
    keep = lines[:first - 1] + lines[b["lines"][0] - 1:b["lines"][1]]
    # (gen_tree's TU namespace opens in the shared part and closes after later blocks: left out, so the text parses)
    return "\n".join("" if NS_OPEN.match(l) or NS_CLOSE.match(l) else l for l in keep)


# ------------------------------------------------------------------------------------------------------- compiling
@contextlib.contextmanager
def _tree(root):
    import build_tree
    old = build_tree.TREE, build_tree.INCLUDE_DIR
    build_tree.TREE, build_tree.INCLUDE_DIR = root, os.path.join(root, "include")
    try:
        yield build_tree
    finally:
        build_tree.TREE, build_tree.INCLUDE_DIR = old


def compile_tu(path):
    """(object path or None, error text): build_tree's compile of the TU (cached by content)."""
    ap = os.path.abspath(path)
    root = find_root(ap)
    with _tree(root) as bt:
        obj, errs, out = bt.compile_tu(os.path.relpath(ap, root))
    return obj, ("" if obj else "\n".join("%s(%s) : error %s: %s" % e for e in errs[:20]))


def object_key(path):
    ap = os.path.abspath(path)
    root = find_root(ap)
    import compare
    with _tree(root) as bt:
        return bt.tu_key(ap, open(ap, "rb").read(), compare.DEFAULT_FLAGS + compare.file_flags(ap))


# ------------------------------------------------------------------------------------------------------- label pins
# MSVC numbers its local labels (`$L68215`: the unwind funclets and catch blocks of a function with EH, in .text$x) by
# one counter over the whole compile, so any header edit that reaches the TU renumbers them. A block whose function is
# such a label is pinned by a key that doesn't move: `$L#<k>@<owner>`, the k-th (from 0, in code order) `$L` label of
# the function OWNER (its mangled name). The owner of a label is the function whose `__ehhandler$<owner>` follows it
# in its section (MSVC emits a function's funclets and then its handler), else the nearest function before it in the
# section. The key resolves to one symbol of the object, which is then checked as any pinned symbol (bytes, relocs).
LABEL = re.compile(r"^\$L\d+$")
LABEL_PIN = re.compile(r"^\$L#(\d+)@(\S+)$")
EHHANDLER = "__ehhandler$"
_LK = {}


def label_keys(coff):
    """{label symbol name: its stable pin key} for the `$L` labels of an object whose owner is known."""
    k = id(coff)
    if k in _LK and _LK[k][0] is coff:
        return _LK[k][1]
    by_sec = collections.defaultdict(list)
    for s in coff.function_symbols():
        by_sec[s[2]].append(s)
    out = {}
    for sec, syms in by_sec.items():
        syms.sort(key=lambda s: (s[1], not LABEL.match(s[0])))
        seen = collections.Counter()
        for i, s in enumerate(syms):
            if not LABEL.match(s[0]):
                continue
            owner = next((t[0][len(EHHANDLER):] for t in syms[i + 1:] if t[0].startswith(EHHANDLER)), None)
            if owner is None:
                owner = next((t[0] for t in reversed(syms[:i]) if not LABEL.match(t[0])
                              and not t[0].startswith(EHHANDLER)), None)
            if owner is None:
                continue
            out[s[0]] = "$L#%d@%s" % (seen[owner], owner)
            seen[owner] += 1
    _LK[k] = (coff, out)
    return out


def resolve_pin(coff, pin):
    """The object's symbol a `// sym:` pin names, or None: a mangled name as itself, a label key (`$L#k@owner`) as the
    label it denotes in this object."""
    if LABEL_PIN.match(pin):
        hits = [n for n, key in label_keys(coff).items() if key == pin]
        return hits[0] if len(hits) == 1 else None
    return pin if any(s[0] == pin for s in coff.function_symbols()) else None


def pin_for(coff, symbol):
    """What `pin` writes for SYMBOL: its label key for an MSVC `$L` label, else the symbol."""
    return label_keys(coff).get(symbol, symbol) if LABEL.match(symbol) else symbol


# ------------------------------------------------------------------------------------------------------- checking
_V = []


def verifier():
    if not _V:
        import build_tree
        _V.append(build_tree.Verifier())
    return _V[0]


def check_tu(path, relocs=False, rec=None, obj=None, vs_standalone=False):
    """The check records of every block of one TU (build_tree.verify_tu's records, without the standalone builds
    unless the sources are there to resolve a shared symbol): matches status match / diff / no_function, equivalent
    status compiled / no_function; `symbol`, `how` (pinned, name, namespace, all, loose, unique); with RELOCS the
    verify_relocs record of each match (`relocs`: ok / bad + issues). VS_STANDALONE (while the per-function sources
    exist): an equivalent function's code against its own source compiled standalone (build_tree's check: `same`
    carries the source's proof over), a match that doesn't match is compiled standalone too."""
    import build_tree
    rec = rec or scan(path)
    if obj is None:
        obj, err = compile_tu(path)
    v = verifier()
    out, pairs, claimed = [], [], set()
    for b in rec["blocks"]:
        r = {"addr": b["addr"], "name": b["name"], "src": b["src"], "kind": b["kind"], "mode": b["mode"],
             "tu": rec["path"]}
        if obj is None:
            r["status"] = "tu_failed"
            out.append(r)
            continue
        pinned = resolve_pin(v.coff(obj), b["sym"]) if b.get("sym") and "pins" not in OFF else None
        if pinned:
            c = v._check(obj, b, claimed, only=pinned)
            c["how"] = "pinned"
        else:
            c = v.check(obj, b, claimed)
            if b["kind"] == "matches" and c["status"] == "match" and c.get("how") in ("name", "loose") \
                    and "relocpick" not in OFF:
                c = _prefer_relocs(v, obj, b, claimed, c)
            if b.get("sym") and "pins" not in OFF:
                r["pin_missing"] = b["sym"]
        if b["kind"] == "equivalent":
            r["status"] = "compiled" if c["status"] != "no_function" else "no_function"
            r["symbol"], r["how"] = c.get("symbol"), c.get("how")
        else:
            r.update({k: c[k] for k in ("status", "symbol", "how", "score") if k in c})
        if c.get("symbol"):
            claimed.add(c["symbol"])
            if LABEL.match(c["symbol"]):
                r["pin"] = pin_for(v.coff(obj), c["symbol"])      # (the stable key `pin` writes for a label)
        if vs_standalone and os.path.exists(os.path.join(ROOT, b["src"])):
            a_ = int(b["addr"], 16)
            if b["kind"] == "equivalent" and r.get("symbol"):
                r["vs_standalone"] = build_tree.compare_with_standalone(v, obj, r["symbol"], b, a_)
            elif b["kind"] == "matches" and r["status"] != "match":
                r["standalone"] = build_tree.standalone(b["src"], a_, v)["status"]
        out.append(r)
        pairs.append((b, r))
    if obj is not None:
        _shared(v, obj, pairs)
        if "codehash" not in OFF:
            code_hashes(v.coff(obj), rec, pairs, path)
        if relocs:
            import verify_relocs
            coff = v.coff(obj)
            for b, r in pairs:
                if r["kind"] == "matches" and r["status"] == "match":
                    sym = next(s for s in coff.function_symbols() if s[0] == r["symbol"])
                    rr = verify_relocs.check_object(coff, sym, int(b["addr"], 16))
                    r["relocs"] = rr["status"]
                    if rr["status"] != "ok":
                        r["reloc_issues"] = rr["issues"]
    return out


def _prefer_relocs(v, obj, b, claimed, c):
    """build_tree.prefer_relocs (of several exact candidates, the one whose relocations hit the original's targets)."""
    import build_tree
    return build_tree.prefer_relocs(v, obj, b, claimed, c)


def _shared(v, obj, pairs):
    """Blocks that landed on one symbol while their original bytes differ (build_tree.unique_symbols). A pinned block
    is its own; the others are resolved through their standalone sources where those exist, else marked
    `shared_symbol: ambiguous` (status ambiguous for a match: unverifiable, like build_tree's)."""
    import build_tree
    groups = collections.defaultdict(list)
    for b, r in pairs:
        if r.get("symbol") and b["mode"] != "isolated" and r.get("how") != "pinned":
            groups[r["symbol"]].append((b, r))
    todo = []
    for sym, grp in groups.items():
        pinned_here = [r for b, r in pairs if r.get("how") == "pinned" and r.get("symbol") == sym]
        if len(grp) + len(pinned_here) < 2:
            continue
        if len({v.target(int(b["addr"], 16)) for b, _ in grp} | {v.target(int(r["addr"], 16)) for r in pinned_here}) == 1:
            for _, r in grp:
                r["shared_symbol"] = "identical"
            continue
        todo += grp
    if not todo:
        return
    if all(os.path.exists(os.path.join(ROOT, b["src"])) for b, _ in todo):
        build_tree.unique_symbols(v, obj, todo)
        return
    for b, r in todo:
        r["shared_symbol"] = "ambiguous"
        if b["kind"] == "matches":
            r["status"] = "ambiguous"


def record(path, addr):
    """The check record of the function at ADDR in the tree TU PATH."""
    a = "0x%08x" % addr
    for r in check_tu(path):
        if r["addr"] == a:
            return r
    raise KeyError("%s has no block for %s" % (path, a))


# ------------------------------------------------------------------------------------------------------- code hashes
# An equivalent block records the hashes of the code that was proven on its pin line, `// sym: PIN @<msvc> @w<clang>`
# (tools/code_hash.py has the definition). check_tu recomputes the MSVC one from the TU's object, with_wine the clang
# one from the object `equiv.py TU ADDR --wine` checks. Per block: `code` / `wine_code` ok (the recorded value), changed
# (not: re-prove, then `hash --proven`), unhashed (none recorded; `pending` while its TU is listed in PENDING, the TUs
# the hashes were not yet filled in for), no_object (clang can't compile the TU: no --wine proof exists either);
# `code_changed`: the kinds that changed (a failure, like pin_missing).
PENDING = os.path.join(ROOT, "config", "code-hash-pending.txt")
_PENDING = []


def pending_tus():
    """The tree TUs (paths relative to the tree root) whose equivalent blocks may still lack hashes."""
    if not _PENDING:
        try:
            _PENDING.append({l.strip() for l in open(PENDING) if l.strip() and not l.startswith("#")})
        except OSError:
            _PENDING.append(set())
    return _PENDING[0]


def _ext(pairs, r):
    """equiv.py's TREE_EXTERNAL for the block of record R: the TU's other functions by symbol (bound by address)."""
    return {x["symbol"]: int(x["addr"], 16) for _, x in pairs
            if x.get("symbol") and x["addr"] != r["addr"] and x["symbol"] != r.get("symbol")}


def _mark(r, b, kind, h, tu_path):
    key, rec_h = ("code", b.get("hash")) if kind == "msvc" else ("wine_code", b.get("whash"))
    r[key + "_hash"] = h
    if h is None:
        r[key] = "no_object"
        return
    r[key] = "unhashed" if rec_h is None else "ok" if rec_h == h else "changed"
    if r[key] == "changed":
        r["code_changed"] = sorted(set(r.get("code_changed", [])) | {kind})


def apply_pending(recs):
    """unhashed -> pending for the blocks of the TUs PENDING lists (outside the verify cache: the list changes)."""
    for r in recs:
        for key in ("code", "wine_code"):
            if r.get(key) == "unhashed" and r["tu"] in pending_tus():
                r[key] = "pending"
    return recs


def code_hashes(coff, rec, pairs, path):
    """Annotate the equivalent records of PAIRS ((block, record) of one TU) with their MSVC code hash."""
    import code_hash
    lines = open(path, errors="replace").read().splitlines()
    fs = {s[0]: s for s in coff.function_symbols()}
    for b, r in pairs:
        if r["kind"] != "equivalent" or not r.get("symbol") or r["symbol"] not in fs:
            continue
        h = code_hash.function_hash(coff, fs[r["symbol"]], _ext(pairs, r), lines[b["lines"][0] - 1:b["lines"][1]])
        _mark(r, b, "msvc", h, rec["path"])


WCACHE = os.path.join(ROOT, "build/tree-cache/whash")
_WK = {}


def _wine_env_check():
    if os.environ.get("HULK_WINE_FLOAT", "sse") != "sse" or os.environ.get("HULK_WINE_SANITIZE"):
        raise RuntimeError("clang code hashes are of the default --wine object: unset HULK_WINE_FLOAT/HULK_WINE_SANITIZE")


def _wine_base_key():
    """What every clang code hash depends on besides the TU: the compiler, its flags, the IR passes, the hash."""
    if not _WK:
        import inspect
        import clang_probe as cp
        import code_hash
        import equiv
        clang = cp.tool("clang++")
        if not clang:
            raise RuntimeError("clang code hashes need LLVM's clang++ (clang_probe.tool)")
        ver = subprocess.run([clang, "--version"], capture_output=True, text=True).stdout.splitlines()[0]
        ver = re.sub(r"^.*?clang version (\S+).*$", r"\1", ver)     # (Homebrew's and ~/llvm's 22.1.8 are one compiler)
        h = hashlib.sha1(b"whash1\0" + ver.encode() + repr(cp.CONFIGS["msvc"]["flags"] + cp.COMMON).encode())
        for m in (code_hash, cp):
            with open(m.__file__, "rb") as f:
                h.update(hashlib.sha1(f.read()).digest())
        h.update(inspect.getsource(equiv.compile_native).encode() + inspect.getsource(wine_hashes).encode()
                 + inspect.getsource(clang_symbol).encode())
        h.update(repr(code_hash.xbe_text()).encode())
        _WK["k"] = h.hexdigest()
    return _WK["k"]


def wine_object(path, outdir):
    """The clang object `equiv.py PATH ADDR --wine` checks (equiv.compile_native), compiled with an empty x87-keep
    list (the queue hosts have none; a Wine build lineage's own list must not leak in). Raises CompileError."""
    import clang_probe as cp
    import equiv
    _wine_env_check()
    old = cp._X87_LIST
    cp._X87_LIST = set()
    try:
        with active(path):
            return equiv.compile_native(path, outdir)
    finally:
        cp._X87_LIST = old


def clang_symbol(fs, symbol):
    """The clang object's name for the MSVC symbol SYMBOL ({name: symbol} FS): itself, else the one name that differs
    only in M <-> N (a `float` return that clang's hulk_freg makes `double`: equiv.pick_symbol's mnret rule), else None."""
    if symbol in fs:
        return symbol
    c = [n for n in fs if len(n) == len(symbol) and n != symbol and all(x == y or {x, y} == {"M", "N"}
                                                                          for x, y in zip(n, symbol))]
    return c[0] if len(c) == 1 else None


def wine_hashes(path, recs, rec=None):
    """{addr: clang code hash or None (the TU doesn't compile with clang)} of the equivalent blocks of RECS (the TU's
    check records), cached in build/tree-cache/whash/ by the TU's text, the headers clang can reach, the toolchain and
    the records' symbols."""
    import code_hash
    import include_keys
    import tempfile
    from compare import Coff
    ap = os.path.abspath(path)
    rec = rec or scan(path)
    eq = [r for r in recs if r["kind"] == "equivalent" and r.get("symbol")]
    if not eq:
        return {}
    text = open(ap, "rb").read()
    inc = include_dir(ap)
    d = include_keys.digest(ap, [inc, os.path.join(ROOT, "include")], root=ROOT, force=["compat/native.h"])
    if d is None:
        import build_tree
        d = "all " + build_tree.include_tree_digest(os.path.join(ROOT, "include")) + " " + \
            build_tree.include_tree_digest(inc)
    key = hashlib.sha1((_wine_base_key() + "\0" + d + "\0" + json.dumps([(r["addr"], r["symbol"]) for r in recs])).encode()
                       + b"\0" + text).hexdigest()[:24]
    cp_ = os.path.join(WCACHE, key + ".json")
    try:
        with open(cp_) as f:
            return json.load(f)
    except (OSError, ValueError):
        pass
    os.makedirs(WCACHE, exist_ok=True)
    out = {}
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as tmp:
        try:
            obj = wine_object(ap, tmp)
        except Exception as e:      # noqa: BLE001 - CompileError: no clang object, no --wine proof
            if isinstance(e, RuntimeError):
                raise
            obj = None
        if obj is None:
            out = {r["addr"]: None for r in eq}
        else:
            coff = Coff(obj)
            fs = {s[0]: s for s in coff.function_symbols()}
            lines = text.decode("utf-8", "replace").splitlines()
            blocks = {b["addr"]: b for b in rec["blocks"]}
            pairs = [(blocks.get(r["addr"]), r) for r in recs]
            whole = None
            for r in eq:
                b = blocks[r["addr"]]
                cs = clang_symbol(fs, r["symbol"])
                if cs:
                    out[r["addr"]] = code_hash.function_hash(coff, fs[cs], _ext(pairs, r),
                                                             lines[b["lines"][0] - 1:b["lines"][1]])
                else:       # (clang has no such function, e.g. an MSVC `$L` funclet or `??_G`: the whole object)
                    whole = whole or code_hash.object_hash(coff)
                    out[r["addr"]] = whole
    with open(cp_ + ".%d.tmp" % os.getpid(), "w") as f:
        json.dump(out, f)
    os.replace(cp_ + ".%d.tmp" % os.getpid(), cp_)
    return out


def with_wine(path, recs, rec=None):
    """Annotate check records with their clang code hashes (wine_hashes)."""
    rec = rec or scan(path)
    blocks = {b["addr"]: b for b in rec["blocks"]}
    for addr, h in wine_hashes(path, recs, rec).items():
        r = next(x for x in recs if x["addr"] == addr)
        _mark(r, blocks[addr], "wine", h, rec["path"])
    return apply_pending(recs)


# ------------------------------------------------------------------------------------------------------- verify cache
CACHE = os.path.join(ROOT, "build/tree-cache/tuverify")


def _code_key():
    import build_tree
    import code_hash
    import compare
    import verify_relocs
    h = hashlib.sha1(b"tuverify2\0" + ",".join(sorted(OFF)).encode())
    for m in (sys.modules[__name__], build_tree, compare, verify_relocs, code_hash, sys.modules["xbe"], sys.modules["disasm"],
              sys.modules["addr_names"]):
        with open(m.__file__, "rb") as f:
            h.update(hashlib.sha1(f.read()).hexdigest().encode())
    with open(build_tree.compare.XBE_PATH, "rb") as f:
        h.update(hashlib.sha1(f.read()).hexdigest().encode())
    import gen_tree
    with open(gen_tree.FUNCS_CSV, "rb") as f:
        h.update(hashlib.sha1(f.read()).hexdigest().encode())
    return h.hexdigest()


_CK = []


def cached_check(path, relocs=False, vs_standalone=False, wine=False):
    """check_tu through the verify cache: (records, hit?). WINE: with the clang code hashes too (with_wine)."""
    if not _CK:
        _CK.append(_code_key())
    rec = scan(path)
    blocks = [{k: b[k] for k in ("addr", "name", "kind", "mode", "sym", "prefixes", "cnames", "src")} for b in rec["blocks"]]
    srcs = sorted({b["src"] for b in rec["blocks"] if os.path.exists(os.path.join(ROOT, b["src"]))})
    h = hashlib.sha1((_CK[0] + "\0" + object_key(path) + "\0" + rec["path"] + "\0" + json.dumps(blocks, sort_keys=True)
                      + "\0" + repr((relocs, vs_standalone))).encode())
    for s in srcs:       # (the standalone sources resolve shared symbols while they exist)
        with open(os.path.join(ROOT, s), "rb") as f:
            h.update(hashlib.sha1(f.read()).digest())
    p = os.path.join(CACHE, h.hexdigest()[:24] + ".json")
    try:
        with open(p) as f:
            out, hit = json.load(f), True
    except (OSError, ValueError):
        out, hit = check_tu(path, relocs=relocs, rec=rec, vs_standalone=vs_standalone), False
        os.makedirs(CACHE, exist_ok=True)
        with open(p + ".%d.tmp" % os.getpid(), "w") as f:
            json.dump(out, f)
        os.replace(p + ".%d.tmp" % os.getpid(), p)
    if wine:
        with_wine(path, out, rec)
    return apply_pending(out), hit


def tree_tus(root):
    out = []
    for dp, dns, fns in os.walk(os.path.join(root, "src")):
        dns.sort()
        for fn in sorted(fns):
            p = os.path.join(dp, fn)
            if fn.endswith(".cpp") and is_tree_tu(p):
                out.append(p)
    return out


def changed_tus(root, ref):
    """Tree TUs whose text changed since git REF, and every TU when a header under the tree's include/ (or the repo's
    include/) changed: the object keys cover headers anyway, this only narrows the list a CI run walks."""
    r = subprocess.run(["git", "diff", "--name-only", ref, "--", root], capture_output=True, text=True, cwd=ROOT)
    files = [os.path.join(ROOT, l) for l in r.stdout.split()]
    if any(f.endswith(".h") for f in files):
        return tree_tus(root)
    return [f for f in files if f.endswith(".cpp") and is_tree_tu(f)]


def _verify_one(args):
    path, relocs, vs, wine = args
    try:
        recs, hit = cached_check(path, relocs, vs, wine)
        return path, recs, hit, None
    except Exception as e:      # noqa: BLE001 - keep the sweep going
        return path, [], False, repr(e)[:300]


def count_codes(counts, r):
    """The code-hash part of a record in verify's counts: changed and unhashed are failures (`equivalent ...`)."""
    for k in r.get("code_changed", []):
        counts["equivalent code changed (%s)" % k] += 1
    for key, kind in (("code", "msvc"), ("wine_code", "wine")):
        st = r.get(key)
        if st == "unhashed":
            counts["equivalent code unhashed (%s)" % kind] += 1
        elif st == "pending":
            counts["code hash pending (%s)" % kind] += 1
        elif st == "no_object":
            counts["code hash: no clang object (%s)" % kind] += 1
        elif st == "ok":
            counts["code hash ok (%s)" % kind] += 1
    if r.get("code_hash_removed"):
        counts["equivalent code hash removed"] += 1


def failing(counts):
    """verify's failure count of a summary's counts (also materialize's)."""
    return sum(n for k, n in counts.items() if k.split(" ")[0] in ("matches", "equivalent", "pinned", "ambiguous")
               and not k.endswith((" match", " compiled", ": same")))


def verify(paths, jobs=4, relocs=False, out=None, vs_standalone=False, wine=True, ref=None):
    """Check every block of PATHS (cached); returns the summary. OUT: one JSON record per function. WINE: the clang
    code hashes too. REF (a git ref): a block that had a code hash there and has none now is a failure."""
    import multiprocessing
    counts, hits = collections.Counter(), 0
    errors = []
    f = open(out, "w") if out else None
    ctx = multiprocessing.get_context("fork")
    with ctx.Pool(max(1, jobs)) as pool:
        for path, recs, hit, err in pool.imap_unordered(_verify_one, [(p, relocs, vs_standalone, wine) for p in paths],
                                                         chunksize=4):
            hits += hit
            if err:
                errors.append((path, err))
            if ref:
                removed_hashes(path, recs, ref)
            for r in recs:
                count_codes(counts, r)
                counts["%s %s" % (r["kind"], r["status"])] += 1
                if r.get("relocs") and r["relocs"] != "ok":
                    counts["matches relocs %s" % r["relocs"]] += 1
                if r.get("shared_symbol") == "ambiguous":
                    counts["ambiguous symbol"] += 1
                if r.get("pin_missing"):
                    counts["pinned symbol missing"] += 1
                if "vs_standalone" in r:
                    counts["equivalent vs standalone: %s" % r["vs_standalone"]] += 1
                if "standalone" in r:
                    counts["matches not matching in the tree, standalone: %s" % r["standalone"]] += 1
                if f:
                    f.write(json.dumps(r) + "\n")
    if f:
        f.close()
    return {"tus": len(paths), "cache_hits": hits, "counts": dict(sorted(counts.items())), "errors": errors[:20],
            "n_errors": len(errors)}


# ------------------------------------------------------------------------------------------------------- materialize
TREE_HEADER_TOPS = ("common.h", PRELUDE, "game", "engine", "platform")     # the tree's own headers under include/
TREE_TU_TOPS = ("game", "engine", "platform/xbox")                          # the tree's TUs under src/


def _sync_file(src, dst):
    data = open(src, "rb").read()
    try:
        if open(dst, "rb").read() == data:
            return False
    except OSError:
        pass
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    with open(dst + ".tmp", "wb") as f:
        f.write(data)
    os.replace(dst + ".tmp", dst)
    return True


def materialize(root, out, jobs=4, relocs=False, wine=True):
    """A committed tree (ROOT/src/{game,engine,platform/xbox}, ROOT/include/{common.h,tree_prelude.h,<layer>/...}) as
    build_tree's output in OUT (src/, include/, manifest.json, report.json, an empty state.json), so the Wine build's
    later stages (clang_probe --snapshot, wine_link) read it as they read a tree build: one verification pass (compile
    what the object cache lacks, check every function), no fallback rounds. Returns the summary."""
    import time
    t0 = time.time()
    want = {}
    for top in TREE_TU_TOPS:
        base = os.path.join(root, "src", top)
        for dp, dns, fns in os.walk(base):
            for fn in fns:
                p = os.path.join(dp, fn)
                if fn.endswith(".cpp"):
                    want[os.path.relpath(p, root)] = p
    inc = {}
    for top in TREE_HEADER_TOPS:
        p = os.path.join(root, "include", top)
        if os.path.isfile(p):
            inc["include/" + top] = p
        for dp, dns, fns in os.walk(p):
            if top == "platform" and os.path.relpath(dp, os.path.join(root, "include")).startswith("platform/sdl"):
                continue
            for fn in fns:
                if fn.endswith(".h"):
                    q = os.path.join(dp, fn)
                    inc[os.path.relpath(q, root)] = q
    changed = 0
    for rel, p in list(want.items()) + list(inc.items()):
        changed += _sync_file(p, os.path.join(out, rel))
    stale = 0
    for sub, keep in (("src", want), ("include", inc)):
        for dp, dns, fns in os.walk(os.path.join(out, sub)):
            for fn in fns:
                q = os.path.join(dp, fn)
                if os.path.relpath(q, out) not in keep:
                    os.unlink(q)
                    stale += 1
    t1 = time.time()
    paths = sorted(os.path.join(out, rel) for rel in want)
    tus = [p for p in paths if is_tree_tu(p)]
    recs_out = os.path.join(out, "checks.jsonl")
    s = verify(tus, jobs=jobs, relocs=relocs, out=recs_out, wine=wine)
    checks = [json.loads(l) for l in open(recs_out)]
    order = {p: i for i, p in enumerate(sorted(os.path.relpath(p, out) for p in tus))}
    checks.sort(key=lambda r: (order.get(r["tu"], 0), r["addr"]))
    # the link order (the order of the objects, which decides e.g. the order of clang's own dynamic initializers): the
    # committed src/link-order.txt (one TU path per line, gen_tree's TU order), else by path
    lo = os.path.join(root, "src", "link-order.txt")
    if os.path.exists(lo):
        rank = {l.strip(): i for i, l in enumerate(open(lo)) if l.strip()}
        paths.sort(key=lambda p: (rank.get(os.path.relpath(p, out), len(rank)), p))
    man = {"tus": [], "headers": {}}
    modes = collections.Counter()
    for p in paths:         # (every TU, also one whose functions all moved elsewhere: it is still an object of the link)
        rec = scan(p)
        flags = __import__("compare").file_flags(p)
        layer = "platform/xbox" if rec["path"].startswith("src/platform/xbox/") else rec["path"].split("/")[1]
        man["tus"].append({"path": rec["path"], "object": rec["path"].split("/", 2 if layer != "platform/xbox" else 3)[-1],
                           "layer": layer, "flags": flags, **({"tu_ns": rec["tu_ns"]} if rec.get("tu_ns") else {}),
                           "blocks": [{k: b[k] for k in ("addr", "name", "src", "kind", "mode", "lines", "ns")}
                                      for b in rec["blocks"]]})
        for b in rec["blocks"]:
            modes[b["mode"]] += 1
    gen = {"tu_files": len(paths), "verified_functions": sum(modes.values()), "modes": dict(modes),
           "source": "committed tree (tools/tree_tu.py materialize)"}
    for name, obj in (("manifest.json", man), ("report.json", {"generator": gen, "summary": s, "checks": checks}),
                      ("state.json", {"wrap": {}, "isolate": {}, "local_only": [], "iso_plain": {}})):
        with open(os.path.join(out, name) + ".tmp", "w") as f:
            json.dump(obj, f)
        os.replace(os.path.join(out, name) + ".tmp", os.path.join(out, name))
    s.update(copied=changed, removed=stale, copy_s=round(t1 - t0, 1), verify_s=round(time.time() - t1, 1))
    return s


# ------------------------------------------------------------------------------------------------------- layout
GEN_HEADER = "// GENERATED by tools/gen_tree.py -- DO NOT EDIT."
TREE_HEADER = "// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here."


def layout(tree, root):
    """A generated tree (TREE: gen_tree's src/, include/ and manifest.json, build/tree) laid out in ROOT as the committed
    tree: ROOT/src/{game,engine,platform/xbox}/..., ROOT/include/{common.h,tree_prelude.h,game,engine,platform/xbox}/...,
    the generator's DO-NOT-EDIT line replaced by the committed tree's header (a comment), and ROOT/src/link-order.txt:
    the manifest's TU order, which is the link order (materialize sorts the objects by it). Files of the tree tops in
    ROOT that the generated tree no longer has are removed. Returns {written, unchanged, removed, tus}."""
    man = json.load(open(os.path.join(tree, "manifest.json")))
    want = {}
    for sub in ("src", "include"):
        for dp, dns, fns in os.walk(os.path.join(tree, sub)):
            for fn in fns:
                p = os.path.join(dp, fn)
                rel = os.path.relpath(p, tree)
                if rel.startswith(("include/gen/", "include/decls/", "include/compat/", "src/platform/sdl/")):
                    raise ValueError("generated tree writes outside the tree tops: " + rel)
                want[rel] = p
    out = collections.Counter()
    for rel, p in sorted(want.items()):
        text = open(p, errors="surrogateescape").read()
        lines = text.split("\n")
        for i in range(min(3, len(lines))):
            if lines[i].startswith(GEN_HEADER):
                lines[i] = TREE_HEADER
        text = "\n".join(lines)
        dst = os.path.join(root, rel)
        if os.path.exists(dst) and open(dst, errors="surrogateescape").read() == text:
            out["unchanged"] += 1
            continue
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "w", errors="surrogateescape") as f:
            f.write(text)
        out["written"] += 1
    keep = set(want)
    for top in ["src/" + t_ for t_ in TREE_TU_TOPS] + ["include/" + t_ for t_ in TREE_HEADER_TOPS]:
        base = os.path.join(root, top)
        cands = [base] if os.path.isfile(base) else [os.path.join(dp, fn) for dp, dns, fns in os.walk(base) for fn in fns]
        for q in cands:
            rel = os.path.relpath(q, root)
            if rel.startswith("include/platform/sdl") or rel in keep:
                continue
            os.unlink(q)
            out["removed"] += 1
    order = [t_["path"] for t_ in man["tus"]]
    missing = [p for p in order if p not in want]
    if missing:
        raise ValueError("manifest TUs missing from the generated tree: %s" % missing[:5])
    with open(os.path.join(root, "src", "link-order.txt"), "w") as f:
        f.write("".join(p + "\n" for p in order))
    out["tus"] = len(order)
    return dict(out)


# ------------------------------------------------------------------------------------------------------- pinning
def sym_line(pin, h=None, wh=None):
    return "// sym: " + pin + ("" if h is None else " @" + h) + ("" if wh is None else " @w" + wh)


def pin_text(path, records, hashes=None):
    """The TU's text with a `// sym:` line after every block line whose function has a symbol in RECORDS ({addr:
    symbol}); an existing pin is replaced, keeping its code hashes; a block without a symbol keeps its line as it is.
    HASHES ({addr: (msvc hash or None, clang hash or None)}): code hashes to write (None: keep the line's)."""
    lines = open(path, errors="replace").read().split("\n")
    hashes = hashes or {}
    out, i = [], 0
    while i < len(lines):
        l = lines[i]
        out.append(l)
        m = BLOCK.match(l)
        i += 1
        if m:
            old = SYM_LINE.match(lines[i]) if i < len(lines) else None
            if old:
                i += 1
            oh = dict((("w" if w else "m"), hx) for w, hx in HASH_TOKEN.findall(old.group(2))) if old else {}
            s = records.get(m.group(1)) or (old.group(1) if old else None)
            nh = hashes.get(m.group(1), (None, None))
            h, wh = nh[0] or oh.get("m"), nh[1] or oh.get("w")
            if s:
                out.append(sym_line(s, h, wh))
            elif h or wh:
                raise ValueError("%s %s: code hashes without a pinned symbol" % (path, m.group(1)))
    return "\n".join(out)


def text_hashes(text):
    """{addr: (msvc hash, clang hash)} recorded in a TU's text."""
    out, lines = {}, text.split("\n")
    for i, l in enumerate(lines[:-1]):
        m = BLOCK.match(l)
        sm = SYM_LINE.match(lines[i + 1]) if m else None
        if sm:
            hs = dict((("w" if w else "m"), hx) for w, hx in HASH_TOKEN.findall(sm.group(2)))
            if hs:
                out[m.group(1)] = (hs.get("m"), hs.get("w"))
    return out


def removed_hashes(path, recs, ref):
    """Mark `code_hash_removed` on the records of blocks that had a code hash at git REF and have none now (a hash is
    only replaced by `hash --proven`, never dropped)."""
    root = find_root(path)
    rel = os.path.relpath(os.path.abspath(path), ROOT)
    r_ = subprocess.run(["git", "show", "%s:%s" % (ref, rel)], capture_output=True, text=True, cwd=ROOT, errors="replace")
    if r_.returncode or not root:
        return
    before = text_hashes(r_.stdout)
    now = text_hashes(open(path, errors="replace").read())
    for r in recs:
        if r["kind"] != "equivalent":
            continue
        b, n = before.get(r["addr"], (None, None)), now.get(r["addr"], (None, None))
        if (b[0] and not n[0]) or (b[1] and not n[1]):
            r["code_hash_removed"] = True


# ------------------------------------------------------------------------------------------------------- recording
MSVC_INPUTS, WINE_INPUTS = 3000, 600


def proof_code(src, addr, native, recs):
    """What equiv.py records in a tree TU's report (`tree_code`): the code hash of the object it checks (the MSVC one,
    or with NATIVE the clang one; `x87_keep`: the size of the x87-keep list the --wine compile used, which the hash's
    compile leaves empty)."""
    a = "0x%08x" % addr
    r = next((x for x in recs if x["addr"] == a), None)
    if r is None or r["kind"] != "equivalent" or not r.get("symbol"):
        return {"error": "no equivalent block with a symbol at %s" % a}
    if native:
        import clang_probe as cp
        rec = scan(src)
        h = wine_hashes(src, recs, rec).get(a)
        return {"wine": h, "symbol": r["symbol"], "x87_keep": len(cp._x87_list())}
    return {"msvc": r.get("code_hash"), "symbol": r["symbol"]}


def _load_results(paths):
    out = collections.defaultdict(list)
    for p in paths:
        text = open(p).read()
        try:
            recs = [json.loads(text)]
        except ValueError:
            recs = [json.loads(l) for l in text.splitlines() if l.strip().startswith("{")]
        for r in recs:
            if isinstance(r, dict) and r.get("addr"):
                out["0x%08x" % int(r["addr"], 16)].append(r)
    return out


def proves(rep, kind, h):
    """(ok, why): does equiv.py report REP prove the code that hashes to H? msvc: a promotable MSVC run asked for
    >= 3,000 inputs; wine: a --wine run that passes the promotion gate (tools/wine_gate.py) asked for >= 600."""
    tc = rep.get("tree_code") or {}
    if h is None:
        return False, "no hash to prove"
    if bool(rep.get("native")) != (kind == "wine"):
        return False, "another mode"
    if tc.get(kind) != h:
        return False, "a run of other code (%s, now %s)" % (tc.get(kind), h)
    if kind == "msvc":
        if not rep.get("promotable"):
            return False, "not promotable (%s)" % rep.get("status")
        if (tc.get("n_inputs") or 0) < MSVC_INPUTS:
            return False, "asked for %s inputs (%d needed)" % (tc.get("n_inputs"), MSVC_INPUTS)
        return True, "promotable at %s inputs" % tc["n_inputs"]
    import wine_gate
    ok, why = wine_gate.judge(rep)
    if not ok:
        return False, why
    if tc.get("x87_keep"):
        return False, "the --wine compile used an x87-keep list (%d functions): run it without one" % tc["x87_keep"]
    if (tc.get("n_inputs") or 0) < WINE_INPUTS:
        return False, "asked for %s inputs (%d needed)" % (tc.get("n_inputs"), WINE_INPUTS)
    return True, why


def hash_proven(path, results, addrs=None, dry_run=False):
    """Record the code hashes of PATH's equivalent blocks that changed (or have none) where RESULTS ({addr: [equiv.py
    reports]}) prove the code as it is now (proves()); a block whose code didn't change keeps its hashes. Returns the
    per-block outcome."""
    rec = scan(path)
    recs = check_tu(path, rec=rec)
    with_wine(path, recs, rec)
    out, new = [], {}
    for r in recs:
        if r["kind"] != "equivalent" or (addrs and r["addr"] not in addrs):
            continue
        o = {"addr": r["addr"], "code": r.get("code"), "wine_code": r.get("wine_code")}
        if not r.get("symbol"):
            o["result"] = "no symbol (%s)" % r["status"]
            out.append(o)
            continue
        want = {}
        for kind, key in (("msvc", "code"), ("wine", "wine_code")):
            if r.get(key) in ("ok", "no_object"):
                continue
            h = r.get(key + "_hash")
            why = [proves(x, kind, h) for x in results.get(r["addr"], [])]
            good = [w for ok, w in why if ok]
            if good:
                want[kind] = h
                o[kind] = good[0]
            else:
                o[kind] = "unproven: " + ("; ".join(w for _, w in why) or "no result for this block")
        if any(str(o.get(k, "")).startswith("unproven") for k in ("msvc", "wine")):
            o["result"] = "unproven: nothing recorded"
        elif want:
            new[r["addr"]] = (want.get("msvc"), want.get("wine"))
            o["result"] = "recorded"
        else:
            o["result"] = "unchanged"
        out.append(o)
    if new and not dry_run:
        _write(path, {r["addr"]: r.get("pin") or r["symbol"] for r in recs if r["addr"] in new}, new)
    return out


def _write(path, pins, hashes):
    text = pin_text(path, pins, hashes)
    with open(path + ".tmp", "w") as f:
        f.write(text)
    os.replace(path + ".tmp", path)


def compute_records(root, paths, jobs=2, commit=None):
    """Per TU the code hashes of its equivalent blocks as the code stands (for `hash --init`)."""
    dirty = None
    if not os.environ.get("JOBQ_JOB"):
        r_ = subprocess.run(["git", "status", "--porcelain", "--", "src", "include"], capture_output=True, text=True,
                            cwd=root)
        dirty = r_.returncode != 0 or bool(r_.stdout.strip())
    s = verify(paths, jobs=jobs, wine=True, out=None)     # (fills the caches in parallel)
    for p in paths:
        recs, _ = cached_check(p, wine=True)
        text = open(p, "rb").read()
        yield {"tu": os.path.relpath(p, root), "tu_sha": hashlib.sha1(text).hexdigest(), "commit": commit,
               "clean": dirty is False or (dirty is None and bool(os.environ.get("JOBQ_JOB"))),
               "blocks": [{k: r.get(k) for k in ("addr", "symbol", "pin", "code_hash", "wine_code_hash", "code",
                                                 "wine_code", "status")}
                          for r in recs if r["kind"] == "equivalent"]}
    compute_records.summary = s


def init_hashes(root, records, dry_run=False):
    """Fill in the code hashes of the TUs PENDING lists from `hash --compute` records made at the committed tree (a
    queue job: its workspace is `git archive HEAD`): only blocks with no hash, only TUs whose text is the text the
    records were computed from and has no uncommitted edits. A TU whose equivalent blocks all have their hashes then
    leaves PENDING. Returns {written, skipped: {tu: why}}."""
    pend = pending_tus()
    done, skipped, written = set(), {}, []
    for rr in records:
        tu = rr["tu"]
        p = os.path.join(root, tu)
        if tu not in pend:
            skipped[tu] = "not pending"
            continue
        if not rr.get("clean"):
            skipped[tu] = "computed from a working tree with uncommitted edits"
            continue
        if not os.path.exists(p) or hashlib.sha1(open(p, "rb").read()).hexdigest() != rr["tu_sha"]:
            skipped[tu] = "the TU changed since the hashes were computed"
            continue
        d = subprocess.run(["git", "diff", "--quiet", "HEAD", "--", tu], cwd=root)
        if d.returncode != 0:
            skipped[tu] = "uncommitted edits"
            continue
        rec = scan(p)
        have = {b["addr"]: b for b in rec["blocks"]}
        new, pins, left = {}, {}, 0
        for b in rr["blocks"]:
            cur = have.get(b["addr"])
            if cur is None or cur["kind"] != "equivalent":
                continue
            if cur.get("hash") or cur.get("whash"):
                continue
            if cur.get("sym") and cur["sym"] != (b.get("pin") or b.get("symbol")):
                left += 1           # (its pin is not the symbol the hash is of: pin first)
                continue
            if not b.get("code_hash") or b.get("wine_code") not in ("unhashed", "pending", "no_object", "ok") \
                    or (b.get("wine_code") != "no_object" and not b.get("wine_code_hash")):
                left += 1
                continue
            new[b["addr"]] = (b["code_hash"], b.get("wine_code_hash"))
            pins[b["addr"]] = cur.get("sym") or b.get("pin") or b["symbol"]
        if new and not dry_run:
            _write(p, pins, new)
        written.append((tu, len(new)))
        if left:
            skipped[tu] = "%d blocks without hashes (no symbol or no object)" % left
        else:
            done.add(tu)
    if done and not dry_run:
        keep = [l for l in open(PENDING)] if os.path.exists(PENDING) else []
        with open(PENDING + ".tmp", "w") as f:
            f.write("".join(l for l in keep if l.strip() not in done))
        os.replace(PENDING + ".tmp", PENDING)
        _PENDING.clear()
    return {"written_tus": len([w for w in written if w[1]]), "written_blocks": sum(n for _, n in written),
            "done_tus": len(done), "skipped": skipped}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("blocks")
    p.add_argument("tu")
    p.add_argument("--json", action="store_true")
    p = sub.add_parser("check")
    p.add_argument("tu")
    p.add_argument("--relocs", action="store_true", help="also verify_relocs every match")
    p.add_argument("--equiv", type=int, metavar="N", help="also run equiv.py with N inputs on every equivalent function")
    p.add_argument("--wine", action="store_true", help="with --equiv: the Wine build's clang object")
    p.add_argument("--x64", action="store_true", help="with --equiv: the 64-bit check")
    p.add_argument("--no-wine-code", action="store_true", help="skip the clang code hashes (no clang here)")
    p.add_argument("--json", action="store_true")
    p = sub.add_parser("verify")
    p.add_argument("root", help="the tree root (build/tree, or the checkout once the tree is committed)")
    p.add_argument("--changed-since", metavar="REF")
    p.add_argument("--tus", metavar="FILE", help="TU paths, one per line")
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--relocs", action="store_true")
    p.add_argument("--vs-standalone", action="store_true", help="while matches/ and equivalent/ exist: equivalent code "
                   "against its standalone build (build_tree's check)")
    p.add_argument("--out", metavar="OUT.jsonl")
    p.add_argument("--no-wine-code", action="store_true", help="skip the clang code hashes (no clang here)")
    p = sub.add_parser("pin")
    p.add_argument("root")
    p.add_argument("--records", metavar="JSONL", help="records of `verify --out` (default: check every TU)")
    p.add_argument("--dry-run", action="store_true")
    p = sub.add_parser("layout", help="a generated tree (build/tree) as the committed tree in ROOT, with src/link-order.txt")
    p.add_argument("--tree", default=os.path.join(ROOT, "build/tree"))
    p.add_argument("--root", default=ROOT)
    p = sub.add_parser("materialize", help="a committed tree as build_tree's output (for the Wine build's stages)")
    p.add_argument("--root", default=ROOT)
    p.add_argument("--out", default=os.path.join(ROOT, "build/tree"))
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--relocs", action="store_true")
    p.add_argument("--no-wine-code", action="store_true", help="skip the clang code hashes (no clang here)")
    p = sub.add_parser("hash", help="record equivalent blocks' code hashes (only from proofs, or `--init` for PENDING)")
    p.add_argument("paths", nargs="+", help="TUs (--proven), or the tree root (--compute, --init)")
    p.add_argument("--proven", nargs="+", metavar="RESULT", help="equiv.py --json reports / jsonl: an MSVC run at "
                   "--inputs 3000 (promotable) and a --wine run (>= 600) of the code as it is now")
    p.add_argument("--addr", action="append", help="only these blocks (with --proven)")
    p.add_argument("--compute", metavar="OUT.jsonl", help="write the hashes of the code as it stands (a queue job)")
    p.add_argument("--tus", metavar="FILE", help="with --compute: TU paths, one per line (default: every TU)")
    p.add_argument("--commit", help="with --compute: the commit the workspace is (recorded)")
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--init", metavar="RECORDS.jsonl", help="fill in the TUs of config/code-hash-pending.txt from "
                   "--compute records")
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--json", action="store_true")
    a = ap.parse_args(argv)
    if a.cmd == "hash":
        if a.compute:
            root = os.path.abspath(a.paths[0])
            paths = [os.path.abspath(os.path.join(root, l.strip())) for l in open(a.tus) if l.strip()] if a.tus \
                else tree_tus(root)
            with open(a.compute, "w") as f:
                for r in compute_records(root, paths, jobs=a.jobs, commit=a.commit):
                    f.write(json.dumps(r) + "\n")
            print(json.dumps(compute_records.summary, indent=1))
            return 0
        if a.init:
            s = init_hashes(os.path.abspath(a.paths[0]), [json.loads(l) for l in open(a.init) if l.strip()],
                            dry_run=a.dry_run)
            print(json.dumps(s, indent=1))
            return 0
        if not a.proven:
            ap.error("hash: --proven RESULT..., --compute OUT or --init RECORDS")
        res = _load_results(a.proven)
        addrs = {"0x%08x" % int(x, 16) for x in a.addr} if a.addr else None
        bad = 0
        for path in a.paths:
            for o in hash_proven(path, res, addrs, dry_run=a.dry_run):
                bad += o["result"].startswith(("unproven", "no symbol"))
                print(json.dumps(dict(o, tu=path)) if a.json else "%s %s  %s%s" % (
                    o["addr"], o["result"], "msvc: %s " % o["msvc"] if "msvc" in o else "",
                    "wine: %s" % o["wine"] if "wine" in o else ""))
        return 1 if bad else 0
    if a.cmd == "layout":
        print(json.dumps(layout(os.path.abspath(a.tree), os.path.abspath(a.root))))
        return 0
    if a.cmd == "materialize":
        s = materialize(os.path.abspath(a.root), os.path.abspath(a.out), jobs=a.jobs, relocs=a.relocs,
                        wine=not a.no_wine_code)
        print(json.dumps(s, indent=1))
        return 1 if failing(s["counts"]) or s["n_errors"] else 0
    if a.cmd == "blocks":
        rec = scan(a.tu)
        if a.json:
            print(json.dumps(rec))
        else:
            for b in rec["blocks"]:
                print("%s %-10s %-8s lines %d-%d %s%s" % (b["addr"], b["kind"], b["mode"], b["lines"][0], b["lines"][1],
                                                         b["name"], ("  sym " + b["sym"]) if b["sym"] else ""))
        return 0
    if a.cmd == "check":
        recs = check_tu(a.tu, relocs=a.relocs)
        if not a.no_wine_code:
            with_wine(a.tu, recs)
        apply_pending(recs)
        if a.equiv:
            import equiv
            for r in recs:
                if r["kind"] != "equivalent" or r["status"] != "compiled":
                    continue
                if a.x64:
                    import equiv64
                    rep = equiv64.verify64(a.tu, int(r["addr"], 16), n_inputs=a.equiv)
                else:
                    rep = equiv.verify(a.tu, int(r["addr"], 16), n_inputs=a.equiv, native=a.wine)
                r["equiv"] = rep.get("status")
        bad = 0
        for r in recs:
            ok = r["status"] in ("match", "compiled") and r.get("relocs", "ok") == "ok" and r.get("equiv", "equivalent") \
                == "equivalent" and not r.get("code_changed") and "unhashed" not in (r.get("code"), r.get("wine_code"))
            bad += not ok
            if a.json:
                print(json.dumps(r))
            else:
                code = ""
                if r["kind"] == "equivalent" and "code" in r:
                    code = "code %s%s " % (r["code"], "/" + r["wine_code"] if "wine_code" in r else "")
                print("%s %-10s %-8s %-10s %s%s%s%s%s  %s" % (r["addr"], r["kind"], r["mode"], r["status"],
                                                            ("relocs " + r["relocs"] + " ") if "relocs" in r else "",
                                                            ("equiv " + str(r["equiv"]) + " ") if "equiv" in r else "",
                                                            code, "PIN MISSING " if r.get("pin_missing") else "",
                                                            r.get("how") or "", r.get("symbol") or ""))
        return 1 if bad else 0
    if a.cmd == "verify":
        root = os.path.abspath(a.root)
        if a.tus:
            paths = [os.path.abspath(os.path.join(root, l.strip())) if not os.path.isabs(l.strip()) else l.strip()
                     for l in open(a.tus) if l.strip()]
        elif a.changed_since:
            paths = changed_tus(root, a.changed_since)
        else:
            paths = tree_tus(root)
        s = verify(paths, jobs=a.jobs, relocs=a.relocs, out=a.out, vs_standalone=a.vs_standalone,
                   wine=not a.no_wine_code, ref=a.changed_since)
        print(json.dumps(s, indent=1))
        return 1 if failing(s["counts"]) or s["n_errors"] else 0
    if a.cmd == "pin":
        root = os.path.abspath(a.root)
        syms = collections.defaultdict(dict)
        if a.records:
            for l in open(a.records):
                r = json.loads(l)
                if r.get("symbol") and r.get("shared_symbol") != "ambiguous":
                    syms[os.path.join(root, r["tu"])][r["addr"]] = r.get("pin") or r["symbol"]
        else:
            for p in tree_tus(root):
                for r in check_tu(p):
                    if r.get("symbol") and r.get("shared_symbol") != "ambiguous":
                        syms[p][r["addr"]] = r.get("pin") or r["symbol"]
        n = 0
        for p, recs in sorted(syms.items()):
            new = pin_text(p, recs)
            if new != open(p, errors="replace").read():
                n += 1
                if not a.dry_run:
                    with open(p, "w") as f:
                        f.write(new)
        print("%d TUs %s" % (n, "would change" if a.dry_run else "pinned"))
        return 0


if __name__ == "__main__":
    sys.exit(main())
