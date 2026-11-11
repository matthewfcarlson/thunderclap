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
SYM_LINE = re.compile(r"^// sym: (\S+)\s*$")
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
        sym = None
        k = i + 1
        if k < end and SYM_LINE.match(lines[k]):
            sym = SYM_LINE.match(lines[k]).group(1)
        src = re.search(r": ((?:matches|equivalent)/0x[0-9a-f]{8}\.cpp)", lines[i])
        blocks.append({"addr": addr, "name": name, "size": size, "kind": kind, "mode": mode,
                       "src": src.group(1) if src else "%s/%s.cpp" % (kind, addr),
                       "lines": [i + 1, end], "sym": sym, "ns": "fn_%s" % addr[2:] if mode == "wrapped" else None,
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


# ------------------------------------------------------------------------------------------------------- verify cache
CACHE = os.path.join(ROOT, "build/tree-cache/tuverify")


def _code_key():
    import build_tree
    import compare
    import verify_relocs
    h = hashlib.sha1(b"tuverify1\0" + ",".join(sorted(OFF)).encode())
    for m in (sys.modules[__name__], build_tree, compare, verify_relocs, sys.modules["xbe"], sys.modules["disasm"]):
        with open(m.__file__, "rb") as f:
            h.update(hashlib.sha1(f.read()).hexdigest().encode())
    with open(build_tree.compare.XBE_PATH, "rb") as f:
        h.update(hashlib.sha1(f.read()).hexdigest().encode())
    import gen_tree
    with open(gen_tree.FUNCS_CSV, "rb") as f:
        h.update(hashlib.sha1(f.read()).hexdigest().encode())
    return h.hexdigest()


_CK = []


def cached_check(path, relocs=False, vs_standalone=False):
    """check_tu through the verify cache: (records, hit?)."""
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
            return json.load(f), True
    except (OSError, ValueError):
        pass
    out = check_tu(path, relocs=relocs, rec=rec, vs_standalone=vs_standalone)
    os.makedirs(CACHE, exist_ok=True)
    with open(p + ".%d.tmp" % os.getpid(), "w") as f:
        json.dump(out, f)
    os.replace(p + ".%d.tmp" % os.getpid(), p)
    return out, False


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
    path, relocs, vs = args
    try:
        recs, hit = cached_check(path, relocs, vs)
        return path, recs, hit, None
    except Exception as e:      # noqa: BLE001 - keep the sweep going
        return path, [], False, repr(e)[:300]


def verify(paths, jobs=4, relocs=False, out=None, vs_standalone=False):
    """Check every block of PATHS (cached); returns the summary. OUT: one JSON record per function."""
    import multiprocessing
    counts, hits = collections.Counter(), 0
    errors = []
    f = open(out, "w") if out else None
    ctx = multiprocessing.get_context("fork")
    with ctx.Pool(max(1, jobs)) as pool:
        for path, recs, hit, err in pool.imap_unordered(_verify_one, [(p, relocs, vs_standalone) for p in paths], chunksize=4):
            hits += hit
            if err:
                errors.append((path, err))
            for r in recs:
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


def materialize(root, out, jobs=4, relocs=False):
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
    s = verify(tus, jobs=jobs, relocs=relocs, out=recs_out)
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
def pin_text(path, records):
    """The TU's text with a `// sym:` line after every block line whose function has a symbol in RECORDS ({addr:
    symbol}); an existing pin is replaced."""
    lines = open(path, errors="replace").read().split("\n")
    out, i = [], 0
    while i < len(lines):
        l = lines[i]
        out.append(l)
        m = BLOCK.match(l)
        i += 1
        if m:
            if i < len(lines) and SYM_LINE.match(lines[i]):
                i += 1
            s = records.get(m.group(1))
            if s:
                out.append("// sym: " + s)
    return "\n".join(out)


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
    a = ap.parse_args(argv)
    if a.cmd == "layout":
        print(json.dumps(layout(os.path.abspath(a.tree), os.path.abspath(a.root))))
        return 0
    if a.cmd == "materialize":
        s = materialize(os.path.abspath(a.root), os.path.abspath(a.out), jobs=a.jobs, relocs=a.relocs)
        print(json.dumps(s, indent=1))
        bad = sum(n for k, n in s["counts"].items() if k.split(" ")[0] in ("matches", "equivalent", "pinned", "ambiguous")
                  and not k.endswith((" match", " compiled", ": same")))
        return 1 if bad or s["n_errors"] else 0
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
                == "equivalent"
            bad += not ok
            if a.json:
                print(json.dumps(r))
            else:
                print("%s %-10s %-8s %-10s %s%s%s  %s" % (r["addr"], r["kind"], r["mode"], r["status"],
                                                        ("relocs " + r["relocs"] + " ") if "relocs" in r else "",
                                                        ("equiv " + str(r["equiv"]) + " ") if "equiv" in r else "",
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
        s = verify(paths, jobs=a.jobs, relocs=a.relocs, out=a.out, vs_standalone=a.vs_standalone)
        print(json.dumps(s, indent=1))
        bad = sum(n for k, n in s["counts"].items() if k.split(" ")[0] in ("matches", "equivalent", "pinned", "ambiguous")
                  and not k.endswith((" match", " compiled", ": same")))
        return 1 if bad or s["n_errors"] else 0
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
