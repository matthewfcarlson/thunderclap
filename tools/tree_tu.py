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
  build/venv/bin/python tools/tree_tu.py verify ROOT [--changed-since REF | --tus FILE] [--jobs N] [--out OUT.jsonl] [--x64]
  build/venv/bin/python tools/tree_tu.py inputs ROOT [--changed-since REF | --tus FILE]   # verify's `inputs`, locally
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
none (`unhashed`); `hash --proven` records new
values only from equiv.py runs of the code as it is now (3,000 inputs promotable, --wine at 600).

Checks beyond the blocks (tool2, docs/merge-once.md "Checks beyond the blocks"): verify runs gen_headers.py --probe
when an include/gen/ header changed (check: one its TU can include; `--gen-probe` forces it) and fails when it fails;
every check scans the MSVC object for data overreach (tools/data_overreach.py: the reported classes fail their block);
tools/jobq.py refuses a verify / check / x64_gate job whose TUs or reachable headers have unshipped local edits unless
the command says `--head-only` (submit_guard), and such a job prints its `inputs` against the checkout's.

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
        if "overreach" not in OFF:
            overreach(obj, out, pairs)
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
# (not: re-prove, then `hash --proven`), unhashed (none recorded: re-prove, then `hash --proven`), no_object (clang can't compile the TU: no --wine proof exists either);
# `code_changed`: the kinds that changed (a failure, like pin_missing).
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
    return recs


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
    import data_overreach       # (D12: the overreach records, from the item inventory)
    for p in (data_overreach.__file__, data_overreach.DATA_JSON):
        with open(p, "rb") as f:
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
    return out, hit


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
    m = job_meta()
    if m is not None and not have_git():
        if ref not in m.get("refs", []):
            raise SystemExit("verify --changed-since %s in a queue job: only the job's base commit (%s) is known here"
                             % (ref, m.get("commit", "?")[:10]))
        files = [os.path.join(ROOT, f) for f in m.get("shipped", []) if f.startswith(("src/", "include/"))]
    else:
        r = subprocess.run(["git", "diff", "--name-only", ref, "--", root], capture_output=True, text=True, cwd=ROOT)
        if r.returncode:        # (a queue job has no git: it found nothing, and so passed, before tool2)
            raise SystemExit("verify --changed-since %s: git diff failed: %s" % (ref, r.stderr.strip()[:300]))
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
        elif st == "no_object":
            counts["code hash: no clang object (%s)" % kind] += 1
        elif st == "ok":
            counts["code hash ok (%s)" % kind] += 1
    if r.get("code_hash_removed"):
        counts["equivalent code hash removed"] += 1


def failing(counts):
    """verify's failure count of a summary's counts (also materialize's)."""
    return sum(n for k, n in counts.items() if k.split(" ")[0] in ("matches", "equivalent", "pinned", "ambiguous",
                                                                    "overreach")
               and not k.endswith((" match", " compiled", ": same")))


def inputs_digest(paths):
    """What a verify of PATHS read, by content and independent of where the tree lies (checkout, build/tree, a queue
    job's workspace): `tus`, sha1 over each TU's path relative to its tree root and its text; `headers`, sha1 over every
    .h a compile can reach by /I (the tree's include/, then the repo's include/: one path relative to include/ each,
    the first directory's copy winning, as the compile's search order). A queue job runs on `git archive HEAD` plus its
    overlay files, so a pass there covers uncommitted edits only when they were shipped (`--files`/`--dirty`):
    `tree_tu.py inputs` gives the same two values for the local files, without compiling (hash3: 28 verify jobs passed
    a header change that their workspaces never held)."""
    th = hashlib.sha1(b"tus1\0")
    roots = set()
    for p in sorted(paths, key=lambda p_: os.path.relpath(p_, find_root(p_) or ROOT)):
        r = find_root(p) or ROOT
        roots.add(r)
        th.update(os.path.relpath(p, r).replace(os.sep, "/").encode() + b"\0")
        with open(p, "rb") as f:
            th.update(hashlib.sha1(f.read()).digest())
    files = {}
    for inc in [os.path.join(r, "include") for r in sorted(roots)] + [os.path.join(ROOT, "include")]:
        for dp, dns, fns in os.walk(inc):
            for fn in fns:
                if fn.endswith(".h"):
                    q = os.path.join(dp, fn)
                    files.setdefault(os.path.relpath(q, inc).replace(os.sep, "/"), q)
    hh = hashlib.sha1(b"headers1\0")
    for rel in sorted(files):
        with open(files[rel], "rb") as f:
            hh.update(rel.encode() + b"\0" + hashlib.sha1(f.read()).digest())
    rh = hashlib.sha1(b"reach1\0")
    rf = reach_files(paths)
    if rf is None:          # (a computed #include: every header)
        rh.update(b"all\0" + hh.digest())
    else:
        for rel in sorted(rf):
            with open(rf[rel], "rb") as f:
                rh.update(rel.encode() + b"\0" + hashlib.sha1(f.read()).digest())
    return {"tus": th.hexdigest()[:16], "headers": hh.hexdigest()[:16], "reach": rh.hexdigest()[:16]}


def _tree_rel(p):
    """P relative to its tree root (else to ROOT), '/'-separated: the key a file has wherever the tree lies."""
    r = find_root(p) or ROOT
    rel = os.path.relpath(p, r)
    if rel.startswith(".."):
        rel = os.path.relpath(p, ROOT)
    return rel.replace(os.sep, "/")


def reach_files(paths):
    """{path relative to the tree root: abs path} of every file the compiles of PATHS can read through #include
    (tools/include_keys.closure over the tree's include/, then the repo's, and the includers' directories:
    conservative, every #include line and every candidate), or None when a TU has a computed #include. inputs_digest's
    `reach`, and what submit_guard compares."""
    import include_keys
    out = {}
    for p in paths:
        ap = os.path.abspath(p)
        r = find_root(ap) or ROOT
        c = include_keys.closure(ap, [os.path.join(r, "include"), os.path.join(ROOT, "include")])
        if c is None:
            return None
        for f in c:
            out.setdefault(_tree_rel(f), f)
    return out


# ------------------------------------------------------------------------------------------------------- queue jobs
# (tool2, D10) A queue job runs on `git archive COMMIT` plus the files it ships (docs/compute.md "Workspaces"), so a
# verify job passes whatever the checkout holds unless the edits travel with it (hash3). tools/jobq.py's make_job calls
# submit_guard for every job whose command runs `tree_tu.py verify|check` or `x64_gate.py check`: it refuses the job
# when a listed TU, a file those TUs can #include, or a config file the check reads has an uncommitted edit (or is
# untracked) in the checkout and is not shipped, unless the command says `--head-only` (check the commit, plus what is
# shipped, on purpose). It ships JOB_META: the local `inputs` digests, the shipped paths, the commit and the refs that
# name it, and the commit's copy of every shipped tree file (JOB_REF, for the x64 gate's REF side: there is no git in
# a job's workspace). Inside the job, verify prints its own `inputs` against the local ones (`inputs_vs_local`) and
# runs the header probe when the shipped files touch include/gen/.
JOB_META = ".jobq/local-inputs.json"
JOB_REF = ".jobq/ref"
GEN_PREFIX = "include/gen/"
CONFIG_READ = {"verify": ["config/data.json"], "check": ["config/data.json"], "x64": ["config/x64-baseline.json"],
               "gen": ["config/gen-sizes.json"]}
_META = []


def job_meta():
    """The submit's record (JOB_META) inside a queue job, else None."""
    if not os.environ.get("JOBQ_JOB"):
        return None
    if not _META:
        p = os.path.join(ROOT, JOB_META)
        try:
            with open(p) as f:
                _META.append(json.load(f))
        except (OSError, ValueError):
            _META.append(None)
    return _META[0]


def have_git():
    return subprocess.run(["git", "rev-parse", "--git-dir"], cwd=ROOT, capture_output=True).returncode == 0


def _git_out(*args):
    r = subprocess.run(["git"] + list(args), cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("git %s: %s" % (" ".join(args), r.stderr.strip()[:300]))
    return r.stdout


def guarded_commands(cmd):
    """[(tool, subcommand, args)] of the `tree_tu.py verify|check` and `x64_gate.py check` runs in a job's argv, also
    inside an `sh -c` string (its words up to the next `;`, `&&`, `|`, `>`)."""
    import shlex
    out = []

    def walk(argv):
        for i, w in enumerate(argv):
            nxt = argv[i + 1] if i + 1 < len(argv) else None
            if w.endswith("tree_tu.py") and nxt in ("verify", "check"):
                tool = "tree_tu"
            elif w.endswith("x64_gate.py") and nxt == "check":
                tool = "x64_gate"
            else:
                continue
            args = []
            for x in argv[i + 2:]:
                if x and all(c in ";&|<>()" for c in x):
                    break
                args.append(x)
            out.append((tool, nxt, args))

    walk(list(cmd))
    for i, w in enumerate(cmd[:-1]):
        if os.path.basename(w) in ("sh", "bash", "zsh") and cmd[i + 1] == "-c" and i + 2 < len(cmd):
            lx = shlex.shlex(cmd[i + 2], posix=True, punctuation_chars=True)
            lx.whitespace_split = True
            try:
                walk(list(lx))
            except ValueError:
                pass
    return out


def _parse_guarded(tool, sub, args):
    """The options of a guarded command that decide what it reads."""
    ap = argparse.ArgumentParser(add_help=False)
    if tool == "tree_tu" and sub == "verify":
        ap.add_argument("root", nargs="?", default=".")
        ap.add_argument("--x64", action="store_true")
        ap.add_argument("--gen-probe", action="store_true")
    elif tool == "tree_tu":
        ap.add_argument("tu", nargs="?")
        ap.add_argument("--gen-probe", action="store_true")
    else:
        ap.add_argument("--head")
    if not (tool == "tree_tu" and sub == "check"):
        ap.add_argument("--changed-since")
        ap.add_argument("--tus")
    ap.add_argument("--head-only", action="store_true")
    a, _ = ap.parse_known_args(args)
    return a


def _local_sha(rel):
    try:
        with open(os.path.join(ROOT, rel), "rb") as f:
            return hashlib.sha1(f.read()).hexdigest()
    except OSError:
        return None


def _stored(files, rel):
    """The text of a shipped file (jobq's content store), or None."""
    if rel not in files:
        return None
    import jobq
    with open(os.path.join(jobq.STORE, files[rel][0]), "rb") as f:
        return f.read().decode(errors="replace")


def submit_guard(cmd, files, commit):
    """D10, for jobq.make_job: None for a command that runs no guarded check; else the overlay files to add (JOB_META,
    JOB_REF copies), or SystemExit naming the unshipped local edits. FILES: the overlay ({workspace path: [sha1, mode]}),
    COMMIT: the job's base commit."""
    runs = guarded_commands(cmd)
    if not runs:
        return None
    import jobq
    changed = set(_git_out("diff", "--name-only", commit, "--", "include", "src", "config").split())
    untracked = set(_git_out("ls-files", "--others", "--exclude-standard", "--", "include", "src", "config").split())
    unshipped = {rel: ("untracked" if rel in untracked else "deleted" if _local_sha(rel) is None else "modified")
                 for rel in changed | untracked if rel not in files}
    shipped = sorted(files)
    gen_shipped = any(f.startswith(GEN_PREFIX) for f in shipped)
    refs = {"HEAD": commit} if _git_out("rev-parse", "HEAD").strip() == commit else {}
    refs[commit] = commit
    checks, refused, x64 = [], [], False
    for tool, sub, args in runs:
        a = _parse_guarded(tool, sub, args)
        name = "%s.py %s" % (tool, sub)
        if a.changed_since and not getattr(a, "tus", None):
            r = subprocess.run(["git", "rev-parse", "--verify", a.changed_since + "^{commit}"], cwd=ROOT,
                               capture_output=True, text=True)
            if r.returncode or r.stdout.strip() != commit:
                raise SystemExit("refused: %s --changed-since %s in a queue job: the job has no git, so it can only "
                                 "take the changes it ships against its own base commit (%s); pass --tus FILE, or "
                                 "--changed-since HEAD with the edits shipped" % (name, a.changed_since, commit[:10]))
            refs[a.changed_since] = commit
        # the TUs the command reads, as the checkout has them
        if tool == "tree_tu" and sub == "check":
            tus = [a.tu] if a.tu else []
        elif a.tus:
            text = _stored(files, a.tus)
            if text is None:
                lp = os.path.join(ROOT, a.tus)
                if not os.path.exists(lp):
                    raise SystemExit("refused: %s --tus %s: neither shipped nor in the checkout" % (name, a.tus))
                text = open(lp).read()
            tus = [l.strip() for l in text.splitlines() if l.strip()]
        elif tool == "tree_tu" and not a.changed_since:
            tus = [os.path.relpath(p, ROOT) for p in tree_tus(ROOT)]
        else:       # (changed since the base: what is shipped or edited, every TU when a header is)
            ed = set(shipped) | set(unshipped)
            tus = [os.path.relpath(p, ROOT) for p in tree_tus(ROOT)] if any(f.endswith(".h") for f in ed) else \
                sorted(f for f in ed if f.endswith(".cpp") and f.startswith("src/"))
        tus = [os.path.relpath(os.path.join(ROOT, t), ROOT).replace(os.sep, "/") for t in tus]
        local = [os.path.join(ROOT, t) for t in tus if os.path.exists(os.path.join(ROOT, t))]
        reach = reach_files(local)
        reads = set(tus) | (set(reach) if reach is not None else
                            {f for f in changed | untracked if f.startswith("include/")})
        is_x64 = tool == "x64_gate" or getattr(a, "x64", False)
        x64 |= is_x64
        reads |= set(CONFIG_READ["verify"] if tool == "tree_tu" else [])
        reads |= set(CONFIG_READ["x64"] if is_x64 else [])
        if gen_shipped or getattr(a, "gen_probe", False) or any(f.startswith(GEN_PREFIX) for f in unshipped):
            reads |= {f for f in unshipped if f.startswith(GEN_PREFIX)} | set(CONFIG_READ["gen"])
        bad = sorted(f for f in reads if f in unshipped)
        if bad and not a.head_only:
            refused.append((name, bad))
        checks.append({"tool": tool, "sub": sub, "args": args, "head_only": a.head_only, "tus": len(tus),
                       "local": inputs_digest(local) if local else None, "unshipped": bad[:50], "n_unshipped": len(bad)})
    if refused:
        name, bad = refused[0]
        more = sum(len(b) for _, b in refused)
        big = [f for _, b in refused for f in b if os.path.isfile(os.path.join(ROOT, f))
               and os.path.getsize(os.path.join(ROOT, f)) > 8 << 20]
        raise SystemExit(
            "refused: this %s job runs on `git archive %s` plus the files it ships, but %d uncommitted file(s) it reads "
            "are not shipped: %s%s.\nShip them (jobq.py submit --dirty, or --files PATH ...), or add --head-only to the "
            "%s command to check the commit (plus what is shipped) on purpose (docs/compute.md \"Workspaces\").%s" % (
                name, commit[:10], more, ", ".join("%s (%s)" % (f, unshipped[f]) for f in bad[:8]),
                " and %d more" % (more - 8) if more > 8 else "", name,
                "\n--dirty skips files over 8 MB: ship %s with --files." % " ".join(sorted(set(big))) if big else ""))
    extra = {}
    for rel in shipped:     # (the commit's copy of each shipped tree file: the REF side of an x64 gate in the job)
        if rel.startswith(("include/", "src/")) and rel not in untracked:
            r = subprocess.run(["git", "cat-file", "-e", "%s:%s" % (commit, rel)], cwd=ROOT, capture_output=True)
            if r.returncode == 0:
                data = subprocess.run(["git", "show", "%s:%s" % (commit, rel)], cwd=ROOT, capture_output=True).stdout
                extra["%s/%s" % (JOB_REF, rel)] = [_store_bytes(data), 0o644]
    meta = {"v": 1, "commit": commit, "refs": sorted(refs), "shipped": shipped, "checks": checks}
    extra[JOB_META] = [_store_bytes(json.dumps(meta, indent=1).encode()), 0o644]
    if x64:
        import equiv64
        extra.update(equiv64.job_files())
    return extra


def _store_bytes(data):
    import jobq
    import tempfile
    os.makedirs(jobq.STORE, exist_ok=True)
    with tempfile.NamedTemporaryFile(dir=jobq.STORE, delete=False) as f:
        f.write(data)
    try:
        return jobq.store_file(f.name)
    finally:
        os.unlink(f.name)


def inputs_vs_local(sub, args, inputs, tool="tree_tu"):
    """Inside a queue job: the submit's local digests of this command (JOB_META) against INPUTS, the job's own."""
    m = job_meta()
    if not m:
        return None
    c = next((c for c in m.get("checks", []) if c["tool"] == tool and c["sub"] == sub and c["args"] == args), None)
    if c is None or not c.get("local"):
        return {"local": None, "note": "no local digests recorded for this command"}
    same = {k: c["local"].get(k) == inputs.get(k) for k in ("tus", "reach", "headers")}
    return {"local": c["local"], "shipped": inputs, "same": same, "head_only": c["head_only"],
            "unshipped": c["unshipped"], "n_unshipped": c["n_unshipped"],
            "note": "the job checked the checkout's files" if same["tus"] and same["reach"] else
            ("--head-only: the commit's copy of %d local edit(s)" % c["n_unshipped"] if c["head_only"] else
             "shipped files differ from the checkout's (a private workspace?)")}


# ------------------------------------------------------------------------------------------------------- header probe
def gen_changes(root, ref=None, paths=None):
    """D9: the files under include/gen/ that changed: in a queue job those it ships (JOB_META), else since git REF (the
    working tree, untracked too) or, without REF, the uncommitted ones. PATHS: only those some of these TUs can
    #include (check)."""
    m = job_meta()
    if m is not None:
        ch = [f for f in m.get("shipped", []) if f.startswith(GEN_PREFIX)]
    elif not have_git():
        ch = []
    else:
        d = os.path.relpath(os.path.join(root, "include", "gen"), ROOT)
        ch = _git_out("diff", "--name-only", ref or "HEAD", "--", d).split() + \
            _git_out("ls-files", "--others", "--exclude-standard", "--", d).split()
        ch = [f for f in ch if f.endswith(".h")]
    if paths is not None and ch:
        rf = reach_files(paths)
        if rf is not None:
            ch = [f for f in ch if f in rf]
    return sorted(set(ch))


def gen_probe(root):
    """tools/gen_headers.py --probe over ROOT's include/gen/ (in process; work files under build/tmp/): {ok, counts,
    problems (first lines), seconds}."""
    import time
    import gen_headers
    t = time.time()
    try:
        total, problems, _, _ = gen_headers.probe(include=os.path.join(root, "include"))
    except Exception as e:      # noqa: BLE001 - missing inputs (build/rtti.json, the XBE, wibo) fail the check
        return {"ok": False, "error": repr(e)[:300], "seconds": round(time.time() - t, 1)}
    ok = not problems and total["headers"] == total["headers_ok"]
    return {"ok": ok, "counts": dict(total), "n_problems": len(problems),
            "problems": [p.splitlines()[0] for p in problems[:20]], "seconds": round(time.time() - t, 1)}


# ------------------------------------------------------------------------------------------------------- overreach
# (tool2, D12) tools/data_overreach.py over the object check_tu already has: a reported class (over, pad, addr, before,
# indexed) fails the block it lies in (`overreach`), the informational ones (end, negidx) are listed (`overreach_info`).
_ITEMS = []


def overreach(obj, out, pairs):
    import data_overreach as dor
    if not _ITEMS:
        _ITEMS.append(dor.Items.load())
    syms = {r["symbol"]: r for b, r in pairs if r.get("symbol")}
    blocks = {s: (r["addr"], r["name"], r["kind"]) for s, r in syms.items()}
    for h in dor.object_hits(obj, _ITEMS[0], blocks, dor.REPORTED + dor.INFO):
        r = syms.get(h["symbol"]) or (out[0] if out else None)
        if r is None:
            continue
        k = {x: h[x] for x in ("kind", "item", "item_addr", "item_size", "offset", "width", "target_item", "insn",
                               "symbol")}
        r.setdefault("overreach" if h["kind"] in dor.REPORTED else "overreach_info", []).append(k)


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
                for h in r.get("overreach", []):
                    counts["overreach %s" % h["kind"]] += 1
                for h in r.get("overreach_info", []):
                    counts["info: overreach %s" % h["kind"]] += 1
                if "vs_standalone" in r:
                    counts["equivalent vs standalone: %s" % r["vs_standalone"]] += 1
                if "standalone" in r:
                    counts["matches not matching in the tree, standalone: %s" % r["standalone"]] += 1
                if f:
                    f.write(json.dumps(r) + "\n")
    if f:
        f.close()
    return {"tus": len(paths), "cache_hits": hits, "counts": dict(sorted(counts.items())), "errors": errors[:20],
            "n_errors": len(errors), "inputs": inputs_digest(paths)}


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
    """Per TU the code hashes of its equivalent blocks as the code stands (a report: `hash . --compute`)."""
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
    p.add_argument("--gen-probe", action="store_true", help="run gen_headers.py --probe (default: when an uncommitted "
                   "include/gen/ header this TU can #include changed)")
    p.add_argument("--head-only", action="store_true", help="as a queue job: check the commit, though the checkout "
                   "has unshipped edits the TU reads (submit_guard)")
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
    p.add_argument("--gen-probe", action="store_true", help="run gen_headers.py --probe even when no include/gen/ "
                   "header changed (by default it runs when one did: since --changed-since, uncommitted, or shipped)")
    p.add_argument("--head-only", action="store_true", help="as a queue job: verify the commit (plus what is shipped) "
                   "on purpose, though the checkout has unshipped edits the TUs read (jobq.py refuses the job otherwise)")
    p.add_argument("--x64", action="store_true", help="then the 64-bit gate (tools/x64_gate.py) over the blocks whose "
                   "code changed since --changed-since (default HEAD): a block newly in layout/ptrtrunc/crash64 fails")
    p = sub.add_parser("inputs", help="verify's `inputs` digests of the local files (no compile): compare with a "
                       "queue job's verify summary to see that it checked these files")
    p.add_argument("root")
    p.add_argument("--changed-since", metavar="REF")
    p.add_argument("--tus", metavar="FILE", help="TU paths, one per line")
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
    p = sub.add_parser("hash", help="record equivalent blocks' code hashes (only from proofs)")
    p.add_argument("paths", nargs="+", help="TUs (--proven), or the tree root (--compute)")
    p.add_argument("--proven", nargs="+", metavar="RESULT", help="equiv.py --json reports / jsonl: an MSVC run at "
                   "--inputs 3000 (promotable) and a --wine run (>= 600) of the code as it is now")
    p.add_argument("--addr", action="append", help="only these blocks (with --proven)")
    p.add_argument("--compute", metavar="OUT.jsonl", help="report the hashes of the code as it stands (writes no TU)")
    p.add_argument("--tus", metavar="FILE", help="with --compute: TU paths, one per line (default: every TU)")
    p.add_argument("--commit", help="with --compute: the commit the workspace is (recorded)")
    p.add_argument("--jobs", type=int, default=2)
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
        if not a.proven:
            ap.error("hash: --proven RESULT... or --compute OUT")
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
        gch = gen_changes(find_root(a.tu) or ROOT, paths=[a.tu])
        recs = check_tu(a.tu, relocs=a.relocs)
        if not a.no_wine_code:
            with_wine(a.tu, recs)
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
                == "equivalent" and not r.get("code_changed") and "unhashed" not in (r.get("code"), r.get("wine_code")) \
                and not r.get("overreach")
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
                for k in ("overreach", "overreach_info"):
                    for h in r.get(k, []):
                        print("    %s %s: %s+%d w%d (item %d B) -> %s  %s" % (
                            "OVERREACH" if k == "overreach" else "info", h["kind"], h["item"], h["offset"], h["width"],
                            h["item_size"], h["target_item"], h["insn"]))
        if gch or a.gen_probe:
            g = gen_probe(find_root(a.tu) or ROOT)
            g["why"] = ("changed: " + ", ".join(gch)) if gch else "--gen-probe"
            bad += not g["ok"]
            print(json.dumps({"gen_probe": g}) if a.json else "gen_probe %s (%s): %s" % (
                "ok" if g["ok"] else "FAIL", g["why"], g.get("error") or "; ".join(g["problems"][:5]) or g["counts"]))
        return 1 if bad else 0
    if a.cmd in ("verify", "inputs"):
        root = os.path.abspath(a.root)
        if a.tus:
            paths = [os.path.abspath(os.path.join(root, l.strip())) if not os.path.isabs(l.strip()) else l.strip()
                     for l in open(a.tus) if l.strip()]
        elif a.changed_since:
            paths = changed_tus(root, a.changed_since)
        else:
            paths = tree_tus(root)
        if a.cmd == "inputs":
            print(json.dumps({"tus": len(paths), "inputs": inputs_digest(paths)}, indent=1))
            return 0
        s = verify(paths, jobs=a.jobs, relocs=a.relocs, out=a.out, vs_standalone=a.vs_standalone,
                   wine=not a.no_wine_code, ref=a.changed_since)
        # (D10) in a queue job: the files checked against the checkout's at submit
        vl = inputs_vs_local("verify", (argv if argv is not None else sys.argv[1:])[1:], s["inputs"])
        if vl is not None:
            s["inputs_vs_local"] = vl
            print("inputs: job %s, checkout %s: %s" % (s["inputs"], vl.get("local"), vl["note"]), file=sys.stderr)
        # (D9) the header probe when include/gen/ changed
        gch = gen_changes(root, a.changed_since)
        gen_failed = False
        if gch or a.gen_probe:
            g = gen_probe(root)
            g["why"] = ("changed: " + ", ".join(gch[:10]) + (" ..." if len(gch) > 10 else "")) if gch else "--gen-probe"
            s["gen_probe"] = g
            gen_failed = not g["ok"]
            print("gen_probe %s (%s, %.0f s)%s" % ("ok" if g["ok"] else "FAIL", g["why"], g["seconds"],
                                                   "" if g["ok"] else ": " + (g.get("error") or "; ".join(g["problems"][:5]))),
                  file=sys.stderr)
        else:
            s["gen_probe"] = {"ran": False, "why": "no include/gen/ header changed"}
        x64_failed = False
        if a.x64:
            # (gate1) the 64-bit gate over the same TUs: only blocks whose 32-bit clang or x86-64 code changed run
            import x64_gate
            if root != ROOT:
                raise SystemExit("verify --x64: the gate checks the committed tree (ROOT), not %s" % root)
            g = x64_gate.gate(a.changed_since or "HEAD", tus=None if a.changed_since and not a.tus else
                              [os.path.relpath(p_, ROOT) for p_ in paths], jobs=a.jobs)
            print(x64_gate.render(g), file=sys.stderr)
            s["x64_gate"] = dict(g["summary"], failed=g["failed"])
            x64_failed = g["failed"]
        print(json.dumps(s, indent=1))
        return 1 if failing(s["counts"]) or s["n_errors"] or x64_failed or gen_failed else 0
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
