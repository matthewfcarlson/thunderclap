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
values only from equiv.py runs of the code as it is now (3,000 inputs promotable, --wine at 3,000).

Checker views and the proof ledger (integ1, D42/D37; docs/merge-once.md "Checker views and the proof ledger"): the pin
line's third hash `@v<hex>` is the checker's view of the block in both modes (equiv.checker_view: signature, bindings,
pointee sizes ...), recomputed by check / verify (`view`: changed is a failure); config/proof-ledger.jsonl holds one line
per passing proof run; a block whose current (code, view) in a mode has none is `unproven` (a failure, counted on its
own; materialize ignores it). Both are written only by `hash --proven`.

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
SYM_LINE = re.compile(r"^// sym: (\S+)((?:[ \t]+@[wv]?[0-9a-f]{12})*)\s*$")   # the pin, then the code hashes
HASH_TOKEN = re.compile(r"@([wv]?)([0-9a-f]{12})")  # `@<hex>` the MSVC object's code, `@w<hex>` the clang object's,
                                                    # `@v<hex>` the checker's view of both (integ1, D42: views())
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
    # (tri1) relative to the directory's real path: cl runs with cwd=SRC_DIR and the OS resolves `..` physically. A
    # queue job's build/ is a symlink to the host's checkout, so equiv.py's probes (a temporary directory under build/)
    # got `../../include` = the host checkout's stale include/: the sizeof probe of every tree TU failed or read old
    # headers on the queue hosts (pointee sizes unknown), while the laptop's passed.
    real = os.path.realpath(src_dir)
    return ["/I" + os.path.relpath(os.path.realpath(ACTIVE[-1]), real),
            "/I" + os.path.relpath(os.path.realpath(os.path.join(ROOT, "include")), real)]


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
        sym = hsh = whsh = vhsh = None
        k = i + 1
        if k < end and SYM_LINE.match(lines[k]):
            sm = SYM_LINE.match(lines[k])
            sym = sm.group(1)
            for w, hx in HASH_TOKEN.findall(sm.group(2)):
                if w == "w":
                    whsh = hx
                elif w == "v":
                    vhsh = hx
                else:
                    hsh = hx
        src = re.search(r": ((?:matches|equivalent)/0x[0-9a-f]{8}\.cpp)", lines[i])
        blocks.append({"addr": addr, "name": name, "size": size, "kind": kind, "mode": mode,
                       "src": src.group(1) if src else "%s/%s.cpp" % (kind, addr),
                       "lines": [i + 1, end], "sym": sym, "hash": hsh, "whash": whsh, "vhash": vhsh, "ns": "fn_%s" % addr[2:] if mode == "wrapped" else None,
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
    return "\n".join(strip_tu_ns(keep))


_BRACE_NOISE = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)


def strip_tu_ns(lines):
    """LINES with the TU namespace lines blanked: every `namespace fn_X {` line and `} // namespace fn_X` line, and (tri1)
    the bare `}` that closes such a namespace a few lines further on (unb4's `namespace fn_X {` / declaration / `}`
    groups in the shared part, d9cbcb9af and siblings). Blanking the opening line alone left an unbalanced `}`: the text
    no longer parsed, and equiv.py's C-linkage signatures (decl_c_signature) of 510 blocks in 95 TUs came out empty."""
    out = list(lines)
    for i, l in enumerate(lines):
        if NS_CLOSE.match(l):
            out[i] = ""
        if not NS_OPEN.match(l):
            continue
        out[i] = ""
        depth = 1
        for j in range(i + 1, len(lines)):
            s = _BRACE_NOISE.sub("", lines[j])
            depth += s.count("{") - s.count("}")
            if depth <= 0:
                if s.strip() == "}":
                    out[j] = ""         # (its own close; an NS_CLOSE line is blanked above)
                break
    return out


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
                    fn_ = [i[1] for i in rr["issues"] if i[0] == "free_by_other_name"]
                    if fn_:
                        r["free_by_other_name"] = fn_     # (integ2, D132; D149 gates it against the baseline)
                        # (integ3, D132 item 6) how each name reaches the free: call, address (stored as data), table
                        # (an entry of a table the TU defines); a name both called and stored counts as `call`
                        hw = {}
                        for f_ in rr.get("free_refs", []):
                            h_ = "table" if f_["how"].startswith("table") else f_["how"]
                            if hw.get(f_["name"]) != "call":
                                hw[f_["name"]] = h_
                        if any(h_ != "call" for h_ in hw.values()):
                            r["free_how"] = hw
                    if os.environ.get("HULK_XTU_RELOCMAP"):     # (integ3) xtu_check report --relocmap input
                        r["reloc_map"] = {k: v_ for k, v_ in rr["map"].items() if verify_relocs.classify(k) == "symbol"}
                elif r["kind"] == "equivalent" and r.get("symbol") and "freeequiv" not in OFF:
                    # (integ3, D149 for equivalent blocks) no byte match pairs their relocations with the original:
                    # each relocation's name is judged by the address it gives itself (verify_relocs.name_target)
                    sym = next((s_ for s_ in coff.function_symbols() if s_[0] == r["symbol"]), None)
                    if sym is None:
                        r["free_checked"] = "no symbol"     # (rev5) a visible gap, counted by verify, not a pass
                        continue
                    fn_ = set()
                    for _, t_, typ_, _ in coff.function_relocs(sym):
                        if t_ is None or typ_ not in (verify_relocs.REL32, verify_relocs.DIR32) or \
                                verify_relocs.classify(t_[0]) != "symbol":
                            continue
                        if verify_relocs.free_name_by_name(t_[0]):
                            fn_.add(t_[0])
                    r["free_checked"] = "name"
                    if fn_:
                        r["free_by_other_name"] = sorted(fn_)
                        r["free_how"] = {n_: "name" for n_ in fn_}
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
WFAIL = {}          # (integ1) TU path -> why its clang compile failed in this process (wine_hashes caches no failure)
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
            got_ = json.load(f)
        if not (got_ and all(v is None for v in got_.values())):
            return got_
        # (integ1) an entry an older tree_tu.py wrote for a failed compile: compiled again, never trusted
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
            WFAIL[ap] = repr(e)[:500]
        if obj is None:
            # (integ1, gx4's report) never cached: a failed compile (a loaded host's timeout, a transient file error)
            # stored here made every later check of the same text `no_object` while the TU compiles fine
            return {r["addr"]: None for r in eq}
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


# ------------------------------------------------------------------------------------------------------- checker views
# (integ1, D42) A verdict depends on more than the code: equiv.py also reads the block's signature (for a C name, from our
# declarations' text), the level-2 bindings, the callees' pointee sizes (a sizeof probe), the return kind... (equiv.
# checker_view). Two such reads broke proofs whose code hashes still said ok (docs/merge-once.md "What the hash does not
# cover"). views() computes each equivalent block's view in both modes (equiv.verify(view_only=True): levels 1-2, about
# a second a block and mode), `@v` on the pin line records the hash of the pair a proof ran with (`hash --proven` only),
# and check/verify report `view`: ok, changed (a failure: re-prove), unrecorded (no @v yet: reported), unchecked
# (--no-wine-code: the pair can't be formed), error (no view: a failure).
VCACHE = os.path.join(ROOT, "build/tree-cache/view")
VIEW_MODULES = ("addr_literal", "addr_names", "build_tree", "clang_probe", "code_hash", "compare", "cxx_items",
                "data_overreach", "disasm", "equiv", "gen_tree", "hulk_env", "include_keys", "msvc_demangle",
                "platform_map", "stub_layout", "tree_tu", "verify_relocs", "xbe")
_VK = {}


def _view_base_key():
    """What every view depends on besides the TU: the checker's modules (VIEW_MODULES: what equiv.py's levels 1-2 load),
    _code_key's inputs (the XBE, functions.csv, config/data.json), EQUIV_OFF and the clang toolchain."""
    if not _VK:
        import importlib
        h = hashlib.sha1(b"view1\0" + os.environ.get("EQUIV_OFF", "").encode() + b"\0" + _code_key().encode())
        import equiv
        h.update(b"xbsyms " + equiv.xbsyms_digest().encode())     # (integ2, D101) the XDK list views bind with
        tools = os.path.dirname(os.path.abspath(__file__))
        for m in VIEW_MODULES:
            p = os.path.join(tools, m + ".py")
            if os.path.exists(p):
                with open(p, "rb") as f:
                    h.update(m.encode() + hashlib.sha1(f.read()).digest())
        try:
            h.update(_wine_base_key().encode())
        except Exception as e:      # noqa: BLE001 - no clang here: the wine half is not computed (views(wine=False))
            h.update(repr(e).encode())
        _VK["k"] = h.hexdigest()
    return _VK["k"]


def view_digest(vm, vw):
    """The `@v` hash of a block: its MSVC-mode view and its --wine view (None: clang has no object for the TU)."""
    return hashlib.sha1(json.dumps({"msvc": vm, "wine": vw}, sort_keys=True).encode()).hexdigest()[:12]


def views(path, recs, rec=None, wine=True):
    """{addr: {"msvc": view hash or None, "wine": view hash, None (no clang object) or "unchecked" (WINE false),
    "error": why a view is missing}} of the equivalent blocks of RECS (the TU's check records; with WINE their clang
    code hashes, with_wine), cached in build/tree-cache/view/ by the TU's text, its objects' keys, the records and
    _view_base_key."""
    import tempfile
    ap = os.path.abspath(path)
    rec = rec or scan(path)
    eq = [r for r in recs if r["kind"] == "equivalent" and r.get("symbol")]
    if not eq:
        return {}
    text = open(ap, "rb").read()
    k = hashlib.sha1((_view_base_key() + "\0" + object_key(ap) + "\0" + rec["path"] + "\0" + repr(bool(wine)) + "\0" +
                      json.dumps([(r["addr"], r.get("symbol"), r.get("wine_code_hash") is None) for r in recs])).encode()
                     + b"\0" + text)
    if wine:
        import include_keys
        d = include_keys.digest(ap, [include_dir(ap), os.path.join(ROOT, "include")], root=ROOT,
                                force=["compat/native.h"])
        k.update(b"\0" + str(d).encode())
    cp_ = os.path.join(VCACHE, k.hexdigest()[:24] + ".json")
    try:
        with open(cp_) as f:
            return json.load(f)
    except (OSError, ValueError):
        pass
    import equiv
    out = {}
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as tmp:
        cobj = None
        if wine and any(r.get("wine_code_hash") is not None for r in eq):
            try:
                cobj = wine_object(ap, tmp)      # (one clang compile for every block: what equiv.py --wine compiles)
            except Exception:       # noqa: BLE001 - no object: each block's own run says why
                cobj = None
        for r in eq:
            a = int(r["addr"], 16)
            v = {}
            for mode in ("msvc", "wine"):
                if mode == "wine" and not wine:
                    v["wine"] = "unchecked"
                    continue
                if mode == "wine" and r.get("wine_code_hash") is None:
                    v["wine"] = None
                    continue
                try:
                    rep = equiv.verify(ap, a, view_only=True, recs=recs, native=mode == "wine",
                                       obj_path=cobj if mode == "wine" else None)
                except Exception as e:      # noqa: BLE001
                    rep = {"status": "error", "error": repr(e)[:300]}
                v[mode] = rep.get("view")
                if not rep.get("view"):
                    v.setdefault("error", "%s: %s %s" % (mode, rep.get("status"), (rep.get("error") or
                                                                                 rep.get("view_error") or "")[:200]))
            out[r["addr"]] = v
    os.makedirs(VCACHE, exist_ok=True)
    with open(cp_ + ".%d.tmp" % os.getpid(), "w") as f:
        json.dump(out, f)
    os.replace(cp_ + ".%d.tmp" % os.getpid(), cp_)
    return out


# ------------------------------------------------------------------------------------------------------- proof ledger
# (integ1, D37) config/proof-ledger.jsonl: one line per passing proof run recorded by `hash --proven` (nothing else writes
# it): the block's address, the mode, the code hash and the checker view the run checked, the inputs asked for and run,
# the branch coverage, the checker's digest, the queue job and the date. No game content (addresses and hashes only).
# check/verify report a block whose current (code, view) pair in a mode has no line as `unproven` (a failure shown on
# its own; with --changed-since a block the change left alone is `unproven, unchanged since REF`, not failing).
LEDGER = os.path.join(ROOT, "config", "proof-ledger.jsonl")


REVOKED = os.path.join(ROOT, "config", "proof-revoked.jsonl")
_REVOKED = {}


LINE_KEY_FIELDS = ("addr", "mode", "code", "view", "checker", "job", "date", "n_inputs")


def ledger_line_key(e):
    """(integ4, D154; rev5) A ledger line's identity: a fixed tuple of the fields that identify a run (two runs of the
    same code are two lines), stable when the line is re-serialized or gains a field."""
    f_ = [str(e.get(k)) for k in LINE_KEY_FIELDS]
    if e.get("shard_jobs"):
        # (integ5, D155c; rev5) a sharded proof's line has no single job: its shards' jobs tell two such runs apart
        # (lines without shards keep the key they had)
        f_.append(json.dumps(sorted(map(str, e["shard_jobs"]))))
    return hashlib.sha1(json.dumps(f_).encode()).hexdigest()[:20]


def _revocations(path=None):
    """(integ4, D154) ({ledger_line_key}, {(addr, mode, code, checker): why}) of config/proof-revoked.jsonl (re-read
    when the file changes)."""
    path = path or REVOKED
    try:
        st = os.stat(path)
    except OSError:
        return frozenset(), {}
    k = (path, st.st_mtime_ns, st.st_size)
    if _REVOKED.get("k") != k:
        lines, runs = set(), {}
        with open(path) as f:
            for l in f:
                l = l.strip()
                if l.startswith("{"):
                    r = json.loads(l)
                    lines.update(r.get("lines", ()))
                    for c in r.get("runs", ()):
                        runs[(r["addr"], r["mode"], c[0], c[1])] = r.get("why")
        _REVOKED.update(k=k, v=(frozenset(lines), runs))
    return _REVOKED["v"]


def revoked_lines(path=None):
    return _revocations(path)[0]


def revoked_run(e):
    """(integ4, D154; rev5) The why of the revocation covering line E's (addr, mode, code, checker), or None: the same
    code under the same checker proves nothing again (a host whose tools lag, an old checker kept), a fixed checker
    (another digest) does."""
    return _revocations()[1].get((e.get("addr"), e.get("mode"), e.get("code"), e.get("checker")))


def ledger_line_proves(e):
    """(integ3, rev5) What a ledger line proves, one rule for every index (ledger_index, code_ledger_index) and the
    unproven ratchet: status equivalent and not marked unpromotable. A --wine line that passed wine_gate.judge under D38
    without equiv.py's coverage gate (promotable false) proves nothing until the lead rules on wine coverage (fails
    closed: the materialize gate already refused those modes). (integ4, D154) A line config/proof-revoked.jsonl revokes
    proves nothing either: the run is known unsound (a checker rule found since); only a new line proves that code again
    (a fresh run of new code, or of the same code under the fixed checker: another record, another key)."""
    return e.get("promotable") is not False and e.get("status", "equivalent") == "equivalent" and \
        ledger_line_key(e) not in revoked_lines() and revoked_run(e) is None and \
        (e.get("carried_from") is None or (e["carried_from"] not in revoked_lines() and
                                            same_checker_epoch(e.get("checker"), e.get("carry_checker", e.get("checker")))))


def ledger_index(path=None):
    """{(addr, mode, code hash, view hash)} of the ledger's passing lines, or None when it doesn't exist. (integ3, rev5)
    Only a promotable `equivalent` line proves its code and view, as in code_ledger_index: a recorded failure or short run
    is never a proof (hash --proven, verify's proof marks, hash --from-ledger)."""
    path = path or LEDGER
    if not os.path.exists(path):
        return None
    out, runs = set(), set()
    with open(path) as f:
        for l in f:
            l = l.strip()
            if l.startswith("{"):
                e = json.loads(l)
                if not ledger_line_proves(e):
                    continue
                if e.get("carried_from") is not None and e["carried_from"] not in runs:
                    continue        # (integ6, D159) a carried line proves only after its own proving run line
                if e.get("carried_from") is None:
                    runs.add(ledger_line_key(e))
                out.add((e["addr"], e["mode"], e["code"], e["view"]))
    return out


EPOCHS = os.path.join(ROOT, "config", "checker-epochs.jsonl")
_EPOCHS = {}


def _epoch_records(path=None):
    """(integ6, checker epochs; rev5) ({digest: [the digests it was marked the same as]}, {split digests}) of
    config/checker-epochs.jsonl (append-only; re-read when the file changes)"""
    path = path or EPOCHS
    try:
        st = os.stat(path)
    except OSError:
        return {}, set()
    k = (path, st.st_mtime_ns, st.st_size)
    if _EPOCHS.get("k") != k:
        marks, splits = {}, set()
        with open(path) as f:
            for l in f:
                l = l.strip()
                if l.startswith("{"):
                    r = json.loads(l)
                    if r.get("kind") == "mark":
                        marks.setdefault(r["digest"], []).append(r["same_as"])
                    elif r.get("kind") == "split":
                        splits.add(r["digest"])
        _EPOCHS.update(k=k, v=(marks, splits))
    return _EPOCHS["v"]


def _selftest_out(jid):
    """(checker digest, host, summaries) of a finished host_selftest job"""
    import jobq
    p = os.path.join(jobq.JOBS, "out", str(jid), "jobsrc", "selftest.json")
    with open(p) as f:
        d = json.load(f)
    row = jobq.conn().execute("select host from jobs where id=?", (int(jid),)).fetchone()
    return d.get("checker"), (row["host"] if row else None), d.get("summaries"), d.get("ok")


def _regress_job_lines(jid):
    """the REGRESS_SUMMARY lines a finished regress queue job wrote (jobsrc/regsum.jsonl), or None when its output is
    missing here (refused: never a file handed in instead)"""
    import jobq
    p = os.path.join(jobq.JOBS, "out", str(jid), "jobsrc", "regsum.jsonl")
    if not os.path.exists(p):
        return None
    with open(p) as f:
        return [json.loads(l) for l in f if l.strip().startswith("{")]


def regress_case_names():
    """every case of tests/equiv/regress.py (the full suite a mark's regress must cover)"""
    import importlib.util
    spec = importlib.util.spec_from_file_location("regress_cases", os.path.join(ROOT, "tests/equiv/regress.py"))
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return set(m.CASES) | set(m.RELOC_CASES) | set(m.DECL_CASES) | set(m.X64_CASES) | set(getattr(m, "SHARD_CASES", {}))


def _regress_facts(jids, reader):
    """({case: facts}, why) of regress jobs JIDS: each case's facts line and its ok line merged; a job without its
    summary, or a case reported twice, refuses (None, why)"""
    out, seen = {}, collections.Counter()
    for j in jids:
        ls = reader(j)
        if ls is None:
            return None, "regress job %s: no summary here (jobsrc/regsum.jsonl)" % j
        for r in ls:
            r = dict(r)
            c = r.pop("case")
            k = "ok" if set(r) == {"ok"} else "facts"
            seen[(c, k)] += 1
            if seen[(c, k)] > 1:
                return None, "regress case %s reported twice" % c
            out.setdefault(c, {}).update(r)
    return out, ""


def epoch_mark_evidence(digest, prev, jobs, prev_jobs, regress, prev_regress, selftest_out=None, regress_lines=None,
                        cases=None):
    """(integ6; rev5) (ok, why, facts to record): may DIGEST join PREV's epoch? (a) the selftest summaries of every job
    under DIGEST and under PREV are identical (input digests, edges, work, statuses, first differences), each job ran the
    digest it is given for and passed, and DIGEST ran on every host PREV did; (b) the full regress under DIGEST passed
    every case and its facts (status, class, distinct compared count, repeats, input digest, compared-keys hash, edges,
    work, first difference) equal PREV's case by case, each run under its own digest. (c), the reviewer's approval of
    this specific change, is the caller's --review."""
    selftest_out = selftest_out or _selftest_out
    regress_lines = regress_lines or _regress_job_lines
    if digest == prev:
        return False, "the same digest", {}
    outs = {}
    for d_, js_ in ((digest, jobs), (prev, prev_jobs)):
        outs[d_] = []
        for j in js_:
            ck, host, summ, ok = selftest_out(j)
            if ck != d_:
                return False, "selftest job %s ran checker %s, not %s" % (j, ck, d_), {}
            if not ok or not summ:
                return False, "selftest job %s did not pass" % j, {}
            outs[d_].append((host, json.dumps(summ, sort_keys=True)))
    if len({s for v in outs.values() for _, s in v}) != 1:
        return False, "the selftest summaries differ (between hosts or between the two checkers)", {}
    if not {h for h, _ in outs[prev]} <= {h for h, _ in outs[digest]}:
        return False, "no selftest under %s on host(s) %s" % (digest, sorted({h for h, _ in outs[prev]} -
                                                                             {h for h, _ in outs[digest]})), {}
    new_, w1_ = _regress_facts(regress, regress_lines)
    old_, w2_ = _regress_facts(prev_regress, regress_lines)
    if new_ is None or old_ is None:
        return False, w1_ or w2_, {}
    want_ = cases if cases is not None else regress_case_names()
    if not new_ or set(new_) != set(want_) or set(old_) != set(want_):
        return False, "the regress jobs cover other cases than the suite (%d / %d of %d)" % (
            len(new_), len(old_), len(want_)), {}
    for c, f_ in sorted(new_.items()):
        if f_.get("ok") is not True:
            return False, "regress case %s did not pass under %s" % (c, digest), {}
        g_ = old_[c]
        if "checker" in f_ and (f_["checker"] != digest or g_.get("checker") != prev):
            return False, "regress case %s ran under %s / %s" % (c, f_["checker"], g_.get("checker")), {}
        a_ = {k: v for k, v in f_.items() if k not in ("checker", "ok")}
        b_ = {k: v for k, v in g_.items() if k not in ("checker", "ok")}
        if a_ != b_:
            return False, "regress case %s: %s" % (c, sorted(k for k in set(a_) | set(b_) if a_.get(k) != b_.get(k))), {}
    return True, "", {"selftest": {"jobs": list(map(str, jobs)), "prev_jobs": list(map(str, prev_jobs)),
                                   "hosts": sorted({h for h, _ in outs[digest]})},
                      "regress": {"jobs": list(map(str, regress)), "prev_jobs": list(map(str, prev_regress)),
                                  "cases": len(new_),
                                  "facts": hashlib.sha1(json.dumps(new_, sort_keys=True).encode()).hexdigest()[:12]}}


def checker_epoch(d, path=None):
    """(integ6; rev5) The epoch of checker digest D: the digest itself, unless a mark (`epoch-mark D --same-as P`) links
    it to P's epoch and no split cut that link since; evaluated at read time against the file as it is now, so a split
    undoes every carry made across its link. A digest with two marks, or a cycle, keeps its own epoch (default-deny)."""
    marks, splits = _epoch_records(path)
    seen = set()
    while d in marks and d not in splits and len(marks[d]) == 1 and d not in seen:
        seen.add(d)
        d = marks[d][0]
    return d


def same_checker_epoch(a, b, path=None):
    return a is not None and b is not None and (a == b or checker_epoch(a, path) == checker_epoch(b, path))


CARRY_PARTS = {"rest", "decls", "pointee_sizes", "bindings"}


def carry_check(run, cur):
    """(integ6, D159; rev5, lead) (ok, delta or why): may the proof of ledger line RUN carry to the checker view CUR
    ({addr, mode, code, checker, view, view_parts}: the block as it is now) without a new run? Only from a run line
    (never a carried one, never a line written before D159: no view parts or touched sets) that proves, of the same
    block, mode, code hash and checker digest, whose view differs from CUR's only in entries of `decls` /
    `pointee_sizes` (per callee address) or `bindings` (per symbol) that the run never reached: no run of either side
    called or tail-jumped to the callee, and the symbol is one our code references only by calls to an address no run
    reached. Every other part of the view must be equal (`rest`: the signature, return kind, conventions, narrowing,
    issues, conflicts, contracts, switches, and any key a later checker adds): default-deny. The run would have gone
    exactly as it did under the new view: those entries are read only when a call reaches their callee."""
    for k in ("addr", "mode", "code"):
        if run.get(k) != cur.get(k):
            return False, "another %s (%s, now %s)" % (k, run.get(k), cur.get(k))
    if not same_checker_epoch(run.get("checker"), cur.get("checker")):
        # (rev5) the same checker, or one config/checker-epochs.jsonl marks as the same semantics (epoch-mark)
        return False, "another checker (%s, now %s; epochs %s, %s)" % (
            run.get("checker"), cur.get("checker"), checker_epoch(run.get("checker")), checker_epoch(cur.get("checker")))
    if run.get("carried_from") is not None:
        return False, "a carried line (carry only from a run line)"
    if not isinstance(run.get("view_parts"), dict) or not isinstance(run.get("touched"), dict) or \
            not isinstance(run.get("l2_parts"), dict):
        return False, "a line recorded without view parts and touched sets (before D159): it never carries"
    if not ledger_line_proves(run):
        return False, "the line proves nothing (not promotable, failed or revoked)"
    op, np_ = run["view_parts"], cur.get("view_parts")
    if not isinstance(np_, dict) or set(op) != CARRY_PARTS or set(np_) != CARRY_PARTS:
        return False, "view parts %s / %s: only %s are known (default-deny)" % (
            sorted(op), sorted(np_ or ()), sorted(CARRY_PARTS))
    if op["rest"] != np_["rest"]:
        return False, "the view changed outside decls, pointee_sizes and bindings"
    # (rev5) level 2 reads every callee's declaration and binding, reached or not: under the view now it must pass with
    # the run's own outcome (issues and declared-arity findings), or the carry is refused
    cl2_ = cur.get("l2_parts")
    if not isinstance(cl2_, dict) or set(cl2_) != set(run["l2_parts"]) or set(cl2_) != {"ok", "issues", "decl_arity"}:
        return False, "level-2 parts %s: only ok, issues, decl_arity are known (default-deny)" % sorted(cl2_ or ())
    if not cl2_["ok"] or cl2_ != run["l2_parts"]:
        return False, "level 2 under the view now differs from the run's (%s, run %s)" % (cl2_, run["l2_parts"])
    t_ = run["touched"]
    if set(t_) != {"callees", "symbols"}:
        return False, "touched sets %s: only callees and symbols are known (default-deny)" % sorted(t_)
    reached = {"callees": set(t_["callees"]), "symbols": set(t_["symbols"])}
    delta = []
    for k, tk in (("decls", "callees"), ("pointee_sizes", "callees"), ("bindings", "symbols")):
        o_, n_ = op[k] or {}, np_[k] or {}
        for x in sorted(set(o_) | set(n_)):
            if o_.get(x) != n_.get(x):
                if x in reached[tk]:
                    return False, "%s entry %s changed, and the run reached it" % (k, x)
                delta.append("%s %s" % (k, x))
    if not delta or run.get("view") == cur.get("view"):
        return False, "no view change confined to unreached entries"
    return True, delta


def carried_line(run, cur, delta, tu):
    """(integ6, D159) The ledger line CUR's view gets from RUN's proof: the run's record with the new view and its parts,
    `carried_from` (the run line's key: a revocation of the run revokes the carry) and the entries that moved."""
    import datetime
    e = dict(run)
    e.update(view=cur["view"], view_parts=cur["view_parts"], carried_from=ledger_line_key(run), carry_delta=delta,
             carry_l2=cur["l2_parts"], carry_checker=cur["checker"],
             tu=tu, date=datetime.date.today().isoformat())
    return e


def ledger_entry(addr, mode, code, view, rep, tu):
    import datetime
    tc = rep.get("tree_code") or {}
    l3 = rep.get("level3") or {}
    cov = l3.get("coverage") or {}
    return {"addr": addr, "mode": mode, "code": code, "view": view, "tu": tu, "n_inputs": tc.get("n_inputs"),
            "inputs_run": l3.get("inputs_run"), "inconclusive": l3.get("inputs_inconclusive"),
            "coverage": "%s/%s" % (cov.get("edges_covered"), cov.get("edges_total")) if cov else None,
            "status": rep.get("status"), "promotable": rep.get("promotable"), "checker": tc.get("checker"),
            "memfwd": l3.get("inputs_memfwd", 0), "pre": rep.get("pre"), "pre_repaired": l3.get("inputs_pre_repaired", 0),
            # (integ2, rev5's re-review of D82) compared inputs with small_retry's planted counts / as drawn (or directed)
            "compared_small": l3.get("inputs_compared_small", 0),
            # (integ2, D100; rev5's re-review) compared inputs with planted walk sentinels (sentinel_retry)
            "compared_sentinel": l3.get("inputs_sentinel", 0),
            "compared_drawn": (l3.get("inputs_run") or 0) - l3.get("inputs_compared_small", 0) - l3.get("inputs_sentinel", 0),
            "job": tc.get("job"), "date": datetime.date.today().isoformat(),
            # (integ6, D159) the view in parts and what the run reached among its entries: what `hash --carry` reads
            **({"view_parts": rep["view_parts"], "touched": l3["touched"], "l2_parts": rep["l2_parts"]}
               if isinstance(rep.get("view_parts"), dict) and isinstance(l3.get("touched"), dict) and
               isinstance(rep.get("l2_parts"), dict) else {}),
            # (integ5, D155c; lead) a sharded proof's line names every shard's job
            **({"shard_n": rep["shards"]["n"], "shard_jobs": rep["shards"]["jobs"], "job": None}
               if rep.get("shards") else {})}


def ledger_append(entries, path=None):
    path = path or LEDGER
    have = ledger_index(path) or set()
    new = []
    for e in entries:
        k = (e["addr"], e["mode"], e["code"], e["view"])
        if k not in have:
            have.add(k)
            new.append(e)
    if new:
        with open(path, "a") as f:
            for e in new:
                f.write(json.dumps(e, sort_keys=True) + "\n")
    if os.path.abspath(path) == os.path.abspath(LEDGER) and entries:
        unproven_baseline_drop(entries)
    return len(new)


def unproven_baseline_drop(entries, path=None):
    """(integ2, D126) The ratchet: a proven (addr, mode) leaves config/unproven-baseline.json. Returns the removed."""
    path = path or UNPROVEN_BASELINE
    if not os.path.exists(path):
        return []
    b = load_unproven_baseline(path)
    removed = []
    for e in entries:
        ent = b["blocks"].get(e["addr"])
        if ent and e["mode"] in ent.get("modes", {}) and ledger_line_proves(e):
            del ent["modes"][e["mode"]]
            removed.append((e["addr"], e["mode"]))
            if not ent["modes"]:
                del b["blocks"][e["addr"]]
    if removed:
        write_unproven_baseline(b, path)
    return removed


def mark_views(recs, rec, vs, ledger):
    """Annotate equivalent check records with `view` (and `view_hash`, `view_msvc`, `view_wine`) from VS (views()) and,
    with a LEDGER index, `proof` ({mode: proven / unproven / n/a / unchecked}) and `unproven` (the modes)."""
    blocks = {b["addr"]: b for b in rec["blocks"]}
    for r in recs:
        v = vs.get(r["addr"])
        if r["kind"] != "equivalent" or v is None:
            continue
        vm, vw = v.get("msvc"), v.get("wine")
        r["view_msvc"], r["view_wine"] = vm, vw
        if v.get("error") or vm is None or (vw is None and r.get("wine_code_hash") is not None):
            r["view"], r["view_error"] = "error", v.get("error") or "no view"
        elif vw == "unchecked":
            r["view"] = "unchecked"
        else:
            r["view_hash"] = h = view_digest(vm, vw)
            rv = blocks[r["addr"]].get("vhash")
            r["view"] = "unrecorded" if rv is None else "ok" if rv == h else "changed"
        if ledger is None:
            continue
        pr = {"msvc": "proven" if (r["addr"], "msvc", r.get("code_hash"), vm) in ledger else "unproven"}
        if r.get("wine_code") == "no_object" or (vw is None and r.get("wine_code_hash") is None):
            pr["wine"] = "n/a"
        elif vw == "unchecked" or "wine_code_hash" not in r:
            pr["wine"] = "unchecked"
        else:
            pr["wine"] = "proven" if (r["addr"], "wine", r.get("wine_code_hash"), vw) in ledger else "unproven"
        # (integ5, D157) a mode config/unproven-baseline.json lists for exactly this (addr, mode, code hash), with an
        # accept/seed stamp, is reported (`unproven-baseline`), not failed: the same exact lookup materialize's D126
        # gate uses (unproven_code), never the address alone; edited code has another hash and stays `unproven`
        base = _UNPROVEN_BASE[0] if _UNPROVEN_BASE else load_unproven_baseline()
        for m in [m for m, st in pr.items() if st == "unproven"]:
            if baseline_exempt(base, r["addr"], m, r.get("code_hash" if m == "msvc" else "wine_code_hash")):
                pr[m] = "unproven-baseline"
        r["proof"] = pr
        un = [m for m, st in pr.items() if st == "unproven"]
        if un:
            r["unproven"] = un
        ub = [m for m, st in pr.items() if st == "unproven-baseline"]
        if ub:
            r["unproven_baseline"] = ub


_UNPROVEN_BASE = []     # (integ5, D157; verify: the unproven baseline, read once before the pool forks)


def baseline_exempt(base, addr, mode, h):
    """(integ5, D157) True when the unproven baseline BASE lists ADDR's MODE for exactly code hash H with the stamp
    unproven-accept / unproven-seed writes (`by` and `accepted`): an entry added by hand carries neither and exempts
    nothing (and `verify --changed-since` fails on it as growth without accept)."""
    m = (base.get("blocks", {}).get(addr, {}).get("modes", {}).get(mode) or {})
    return bool(h) and m.get("code") == h and m.get("by") in ("unproven-accept", "unproven-seed") and \
        bool(m.get("accepted"))


# ------------------------------------------------------------------------------------------------------- verify cache
CACHE = os.path.join(ROOT, "build/tree-cache/tuverify")


def _code_key():
    import build_tree
    import code_hash
    import compare
    import verify_relocs
    h = hashlib.sha1(b"tuverify2\0" + ",".join(sorted(OFF)).encode())
    if os.environ.get("HULK_XTU_RELOCMAP"):
        h.update(b"\0relocmap")     # (integ3, rev5's R2) records with reloc_map are cached apart from those without
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


def cached_check(path, relocs=False, vs_standalone=False, wine=False, view=False):
    """check_tu through the verify cache: (records, hit?). WINE: with the clang code hashes too (with_wine). VIEW: with
    the checker views and, when the proof ledger exists, the ledger's verdict (views(), mark_views(); integ1, D37/D42)."""
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
    if view:
        mark_views(out, rec, views(path, out, rec, wine=wine), _LEDGER[0] if _LEDGER else ledger_index())
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
    out = [f for f in files if f.endswith(".cpp") and is_tree_tu(f)]
    try:
        more = contract_caller_tus(root, ref, out)
    except RefReadError as e:
        raise SystemExit("verify --changed-since %s: the contract callers' check can't read REF: %s" % (ref, e))
    return out + sorted(set(more) - set(out))


_CONTRACT_CALLERS = []      # (integ4) the caller blocks contract_caller_tus found (verify probes them)
_CONTRACT_SLOTS = []        # (integ4; rev5) references through data words (vftable slots): reported unprobed


def contract_caller_probe(root, owners, tus, inputs=300):
    """(integ4, D152b; lead) Every XBE caller block of a function whose contract changed: a short equiv.py run in MSVC
    mode and --wine; a caller whose original breaks the new contract (pre_violation_in_original) refuses the change
    until it has its own contract. [(addr, mode, why)] of the refusals."""
    bad = []
    by = {}
    for p in tus:
        text = open(p, errors="replace").read()
        for o in owners:
            if ("// %s " % o) in text:
                by[o] = p
    for o, p in sorted(by.items()):
        for mode, flag in (("msvc", []), ("wine", ["--wine"])):
            r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "equiv.py"), p, o, "--inputs",
                                str(2 * inputs), "--json"] + flag, cwd=root, capture_output=True, text=True)
            try:
                d = json.loads(r.stdout)
            except ValueError:
                bad.append((o, mode, "no report (%s)" % r.stderr.strip()[-200:]))
                continue
            l3_ = d.get("level3") or {}
            if l3_.get("statuses", {}).get("pre_violation_in_original"):
                bad.append((o, mode, str(d.get("error") or "pre_violation_in_original")[:200]))
            elif (l3_.get("inputs_run") or 0) < inputs:
                # (rev5) the probe counts COMPARED inputs: fewer is no probe
                bad.append((o, mode, "underprobed: %d compared of the %d needed" % (l3_.get("inputs_run") or 0, inputs)))
    return bad


def _pre_lines_by_block(text):
    """{address: tuple of the block's `// pre:` lines} of a tree TU's text."""
    out = {}
    for blk in re.split(r"\n(?=// 0x[0-9a-f]{8} )", text or ""):
        m = re.match(r"// (0x[0-9a-f]{8}) ", blk)
        if m:
            out[m.group(1)] = tuple(re.findall(r"^\s*//\s*pre:\s*(.*)$", blk, re.M))
    return out


def contract_caller_tus(root, ref, paths):
    """(integ4, D152b; lead) A changed `// pre:` contract changes the checker view of every XBE caller of the function
    (its proofs' inputs meet the contract through pre_violation_in_original): the TUs holding those callers are
    verified too, so a contract edit can't land with callers in other TUs left view-changed. [TU paths]"""
    import equiv
    import bisect
    import csv
    changed = []
    for p in paths:
        rel = os.path.relpath(p, root)
        now = _pre_lines_by_block(open(p, errors="replace").read())
        old = _pre_lines_by_block(file_at_ref(ref, rel, root) or "")
        changed += [a for a in set(now) | set(old) if now.get(a, ()) != old.get(a, ())]
    if not changed or "contractcallers" in os.environ.get("TREE_TU_OFF", ""):
        del _CONTRACT_CALLERS[:]
        return []
    starts = sorted(int(r[0], 16) for r in list(csv.reader(open(equiv.FUNCS_CSV)))[1:] if r and r[0].startswith("0x"))
    owners = set()
    prog = equiv.Program.get()
    del _CONTRACT_SLOTS[:]
    for a in changed:
        for c in equiv.pre_callers(int(a, 16)):
            if not isinstance(c, int):
                continue
            if prog.section_name(c) != ".text":
                # (rev5) a data word (a vftable slot): its callers reach it through the slot; reported unprobed
                _CONTRACT_SLOTS.append("0x%08x (%s, callee %s)" % (c, prog.section_name(c), a))
                continue
            i = bisect.bisect_right(starts, c) - 1
            if i >= 0:
                owners.add("0x%08x" % starts[i])
    _CONTRACT_CALLERS[:] = sorted(owners)
    if not owners:
        return []
    out = []
    for p in tree_tus(root):
        try:
            text = open(p, errors="replace").read()
        except OSError:
            continue
        if any(("// %s " % o) in text for o in owners):
            out.append(p)
    return out


_LEDGER = []        # (verify: the ledger index, read once before the pool forks)


def _verify_one(args):
    path, relocs, vs, wine, view = args
    try:
        recs, hit = cached_check(path, relocs, vs, wine, view)
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
    # (integ1, D42) the checker's view: changed and error are failures, unrecorded / unchecked reported
    st = r.get("view")
    if st in ("changed", "error"):
        counts["equivalent view %s" % st] += 1
    elif st:
        counts["view %s" % st] += 1
    # (integ1, D37) the proof ledger: a mode whose (code, view) has no entry is unproven (failing() with unproven=True)
    for m, st in sorted((r.get("proof") or {}).items()):
        if st == "unproven" and r.get("unchanged_since_ref"):
            counts["proof: unproven, unchanged since REF (%s)" % m] += 1
        elif st == "unproven":
            counts["unproven (%s)" % m] += 1
        else:
            counts["proof: %s (%s)" % (st, m)] += 1


UNPROVEN_BASELINE = os.path.join(ROOT, "config", "unproven-baseline.json")


def load_unproven_baseline(path=None):
    """(integ2, D126) {"blocks": {addr: {"modes": {mode: {"code", "accepted", "by"}}, "why"}}} of config/unproven-baseline.json: the equivalent
    blocks whose current code had no ledger line when the gate began (2026-11-11's bulk hash pass recorded hashes before
    the ledger existed). It only shrinks: `hash --proven` removes a block's modes as they are proven, and a block is
    added only by `tree_tu.py unproven-accept ADDR --why TEXT`."""
    path = path or UNPROVEN_BASELINE
    try:
        with open(path) as f:
            return json.load(f)
    except (OSError, ValueError):
        return {"blocks": {}}


def write_unproven_baseline(b, path=None):
    path = path or UNPROVEN_BASELINE
    b["blocks"] = {k: b["blocks"][k] for k in sorted(b["blocks"])}
    b["total"] = sum(len(v.get("modes", {})) for v in b["blocks"].values())
    with open(path + ".tmp", "w") as f:
        json.dump(b, f, indent=1)
        f.write("\n")
    os.replace(path + ".tmp", path)


class RefReadError(Exception):
    """REF's copy of a file could not be read (an unknown ref, a git failure, a job without the ref): not the same as
    the file being absent at REF."""


def file_at_ref(ref, rel, root=None):
    """(integ3, D126 follow-up) The text of REL (a path relative to the tree root) at commit REF, None when REF has
    no such file; raises RefError when REF's copy can't be read. In a queue job (no git in the workspace) REF must be
    the job's base commit (or a name the submit recorded for it): the copy is JOB_REF's when REL was shipped (absent
    there: new in the shipped files), else the workspace's own (the commit's). Outside a job REF is verified
    (`rev-parse --verify`) before the file is looked up, so a mistyped REF is an error, not an empty list."""
    root = root or ROOT
    m = job_meta()
    if m is not None and subprocess.run(["git", "rev-parse", "--git-dir"], cwd=root,
                                        capture_output=True).returncode != 0:
        if ref not in m.get("refs", []) and ref != m.get("commit"):
            raise RefReadError("in a queue job only the base commit (%s) is known, not %s"
                               % (str(m.get("commit", "?"))[:10], ref))
        p = os.path.join(root, JOB_REF, rel) if rel in m.get("shipped", []) else os.path.join(root, rel)
        if not os.path.exists(p):
            return None
        with open(p) as f:
            return f.read()
    r = subprocess.run(["git", "rev-parse", "--verify", "--quiet", ref + "^{commit}"], cwd=root, capture_output=True,
                       text=True)
    if r.returncode:
        raise RefReadError("no commit %s" % ref)
    c = r.stdout.strip()
    r = subprocess.run(["git", "ls-tree", "--name-only", c, "--", ":(top)" + rel], cwd=root, capture_output=True,
                       text=True)
    if r.returncode:
        raise RefReadError("git ls-tree %s: %s" % (c[:10], r.stderr.strip()[:200]))
    if not r.stdout.strip():
        return None
    r = subprocess.run(["git", "show", "%s:%s" % (c, rel)], cwd=root, capture_output=True, text=True)
    if r.returncode:
        raise RefReadError("git show %s:%s: %s" % (c[:10], rel, r.stderr.strip()[:200]))
    return r.stdout


def unproven_baseline_growth(ref, root=None):
    """(integ2, D126; rev5's R3) ["addr mode"] of the (addr, mode, code) entries config/unproven-baseline.json holds now
    that REF's didn't (new or another hash), unless that mode's own stamp says `by: unproven-accept`, or `by:
    unproven-seed` when REF had no list at all (the seed happens once); and ["(deleted)"] when REF had the list and
    the tree doesn't. A determined hand-edit can still fake a stamp; review covers that, as for the x64 baseline.
    (integ3, D126 follow-up) REF's copy comes from file_at_ref: in a queue job from JOB_REF or the workspace, and a
    REF that can't be read fails closed (["(REF unreadable: ...)"]), never as "REF had no list"."""
    root = root or ROOT
    rel = "config/unproven-baseline.json"
    try:
        text = file_at_ref(ref, rel, root)
        had = text is not None and bool(text.strip())
        before = json.loads(text).get("blocks", {}) if had else {}
    except (RefReadError, ValueError) as e:
        return ["(REF unreadable: %s)" % str(e)[:200]]
    path = os.path.join(root, rel)
    if had and not os.path.exists(path):
        return ["(deleted)"]
    now = load_unproven_baseline(path).get("blocks", {})
    out = []
    for addr, ent in now.items():
        old = before.get(addr, {}).get("modes", {})
        for mode, m in ent.get("modes", {}).items():
            om = old.get(mode) or {}
            if om.get("code") == m.get("code"):
                continue
            # (rev5) an accept stamp vouches for a changed code only when the stamp itself is new: REF had no such
            # mode, or REF's stamp differs (a hash swapped by hand under last week's accept is reported)
            if m.get("by") == "unproven-accept" and m.get("accepted") and \
                    (not om or (om.get("by"), om.get("accepted")) != (m.get("by"), m.get("accepted"))):
                continue
            if m.get("by") == "unproven-seed" and m.get("accepted") and not had:
                continue
            out.append("%s %s" % (addr, mode))
    return out


FREE_BASELINE = os.path.join(ROOT, "config", "free-name-baseline.json")


def load_free_baseline(path=None):
    """(integ3, D149) {"tus": {TU: {addr: [names] | {"names", "accepted", "by", "why"}}}} of config/free-name-baseline.json:
    the matches blocks that call one of the game's frees under another name (verify_relocs free_by_other_name) when the
    gate began. A bare list is the seed's entry. Only shrinks: `verify --relocs --update-free-baseline` drops what a
    fresh check no longer reports; an entry is added (or a name added to it) only by `tree_tu.py free-name-accept`."""
    path = path or FREE_BASELINE
    try:
        with open(path) as f:
            return json.load(f)
    except (OSError, ValueError):
        return {"tus": {}}


def free_entry(e):
    """(names set, stamp dict) of a baseline entry."""
    if isinstance(e, list):
        return set(e), {"by": "free-name-seed"}
    return set(e.get("names", [])), e


def write_free_baseline(b, path=None):
    path = path or FREE_BASELINE
    tus = {}
    for tu in sorted(b.get("tus", {})):
        ents = {a: b["tus"][tu][a] for a in sorted(b["tus"][tu]) if free_entry(b["tus"][tu][a])[0]}
        for a, e in ents.items():
            if isinstance(e, list):
                ents[a] = sorted(e)
            else:
                e["names"] = sorted(e["names"])
        if ents:
            tus[tu] = ents
    b["tus"] = tus
    b["total"] = sum(len(free_entry(e)[0]) for t in tus.values() for e in t.values())
    with open(path + ".tmp", "w") as f:
        f.write("{\n")
        head = [k for k in ("comment", "seed_why", "total") if k in b]
        for k in head:
            f.write(" %s: %s,\n" % (json.dumps(k), json.dumps(b[k])))
        f.write(' "tus": {\n')
        for i, tu in enumerate(tus):
            f.write("  %s: {\n" % json.dumps(tu))
            items = list(tus[tu].items())
            for j, (a, e) in enumerate(items):
                f.write("   %s: %s%s\n" % (json.dumps(a), json.dumps(e, sort_keys=True), "," if j + 1 < len(items) else ""))
            f.write("  }%s\n" % ("," if i + 1 < len(tus) else ""))
        f.write(" }\n}\n")
    os.replace(path + ".tmp", path)


def free_names_check(recs, base):
    """(integ3, D149) verify's view of one TU's records against the free-name baseline: [(addr, "new"|"known"|"fixed",
    names)]. new: a name not listed for the block (fails); fixed: listed names the block no longer calls (with relocs)."""
    out = []
    for r in recs:
        if not ((r.get("kind") == "matches" and r.get("status") == "match" and "relocs" in r) or
                (r.get("kind") == "equivalent" and r.get("free_checked") == "name")):
            continue
        tu = r.get("tu") or ""
        have = set(r.get("free_by_other_name", []))
        listed = free_entry(base.get("tus", {}).get(tu, {}).get(r["addr"], []))[0]
        if have - listed:
            out.append((r["addr"], "new", sorted(have - listed)))
        if have & listed:
            out.append((r["addr"], "known", sorted(have & listed)))
        if listed - have:
            out.append((r["addr"], "fixed", sorted(listed - have)))
    return out


def free_baseline_growth(ref, root=None):
    """(integ3, D149) ["TU addr name"] the free-name baseline holds now that REF's didn't, unless the entry's own stamp is a
    new `by: free-name-accept` (or the seed's, when REF had no file: once); ["(deleted)"] when REF had it and the tree
    doesn't; a REF that can't be read fails closed (file_at_ref)."""
    root = root or ROOT
    rel = "config/free-name-baseline.json"
    try:
        text = file_at_ref(ref, rel, root)
        had = text is not None and bool(text.strip())
        before = json.loads(text).get("tus", {}) if had else {}
    except (RefReadError, ValueError) as e:
        return ["(REF unreadable: %s)" % str(e)[:200]]
    path = os.path.join(root, rel)
    if had and not os.path.exists(path):
        return ["(deleted)"]
    out = []
    for tu, ents in load_free_baseline(path).get("tus", {}).items():
        for addr, e in ents.items():
            names, st = free_entry(e)
            oe = before.get(tu, {}).get(addr)
            onames, ost = free_entry(oe) if oe is not None else (set(), {})
            extra = names - onames
            if not extra:
                continue
            if st.get("by") == "free-name-accept" and st.get("accepted") and \
                    (oe is None or (ost.get("by"), ost.get("accepted")) != (st.get("by"), st.get("accepted"))):
                continue
            if st.get("by") == "free-name-seed" and not had:
                continue
            out += ["%s %s %s" % (tu, addr, n) for n in sorted(extra)]
    return out


def code_ledger_index(path=None):
    """{(addr, mode, code hash)} of the ledger: a code a passing run proved, under any checker view."""
    path = path or LEDGER
    out = set()
    if os.path.exists(path):
        with open(path) as f:
            for l in f:
                l = l.strip()
                if l.startswith("{"):
                    e = json.loads(l)
                    # (rev5's R2) only a passing proof counts (ledger_line_proves: the one rule)
                    if not ledger_line_proves(e):
                        continue
                    out.add((e["addr"], e["mode"], e["code"]))
    return out


def unproven_code(checks, base=None, ledger=None, wine=True):
    """(integ2, D126) [(addr, mode)] of the equivalent blocks among CHECKS whose current code hash in a mode has no
    passing ledger line under any view and that the unproven baseline doesn't list FOR THAT HASH (rev5's R1: an
    exemption is pinned to the code it was granted for; edited code needs its own proof): what materialize refuses.
    With WINE, an equivalent block without a clang code hash is unproven too (nothing says what runs)."""
    base = base if base is not None else load_unproven_baseline()
    led = ledger if ledger is not None else code_ledger_index()
    known = base.get("blocks", {})
    out = []
    for r in checks:
        if r.get("kind") != "equivalent":
            continue
        for mode, key in (("msvc", "code_hash"), ("wine", "wine_code_hash")):
            if mode == "wine" and not wine:
                continue
            h = r.get(key)
            if h and (r["addr"], mode, h) in led:
                continue
            if h and (known.get(r["addr"], {}).get("modes", {}).get(mode) or {}).get("code") == h:
                continue
            out.append((r["addr"], mode))
    return out


def failing(counts, unproven=True):
    """verify's failure count of a summary's counts (also materialize's, which passes UNPROVEN=False: the Wine build
    builds what the tree holds; the ledger's verdict is verify's)."""
    return sum(n for k, n in counts.items() if (k.split(" ")[0] in ("matches", "equivalent", "pinned", "ambiguous",
                                                                     "overreach") + (("unproven",) if unproven else ())
                                                 or k in ("unproven code, not in baseline",
                                                          "unproven baseline grew without accept",
                                                          "free_by_other_name new",
                                                          "free-name baseline grew without accept",
                                                          "contract caller breaks the contract"))
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
CONFIG_READ = {"verify": ["config/data.json", "config/proof-ledger.jsonl", "config/unproven-baseline.json",
                          "config/free-name-baseline.json"],
               "check": ["config/data.json", "config/proof-ledger.jsonl"], "x64": ["config/x64-baseline.json", "config/rtti-baseline.json", "config/data.json"],
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


def verify(paths, jobs=4, relocs=False, out=None, vs_standalone=False, wine=True, ref=None, view=True, free_base=None):
    """Check every block of PATHS (cached); returns the summary. OUT: one JSON record per function. WINE: the clang
    code hashes too. REF (a git ref): a block that had a code hash there and has none now is a failure. VIEW: the
    checker views and the proof ledger's verdict (integ1, D37/D42)."""
    import multiprocessing
    counts, hits = collections.Counter(), 0
    errors = []
    led = ledger_index() if view else None
    _LEDGER[:] = [led]
    _UNPROVEN_BASE[:] = [load_unproven_baseline()]
    f = open(out, "w") if out else None
    fb = (free_base if free_base is not None else load_free_baseline()) if relocs else None
    free_rows = []
    exempt = []
    ctx = multiprocessing.get_context("fork")
    with ctx.Pool(max(1, jobs)) as pool:
        for path, recs, hit, err in pool.imap_unordered(_verify_one, [(p, relocs, vs_standalone, wine, view)
                                                                       for p in paths], chunksize=4):
            hits += hit
            if err:
                errors.append((path, err))
            if ref:
                removed_hashes(path, recs, ref)
            if fb is not None and "freegate" not in os.environ.get("TREE_TU_OFF", ""):
                # (integ3, D149) a call to the game's free under another name fails unless the baseline lists it
                for addr_, v_, names_ in free_names_check(recs, fb):
                    counts["free_by_other_name new" if v_ == "new" else "info: free_by_other_name %s" % v_] += len(names_)
                    if v_ != "known":
                        hw_ = next((r_.get("free_how", {}) for r_ in recs if r_["addr"] == addr_), {})
                        free_rows.append({"tu": next((r_.get("tu") for r_ in recs if r_.get("tu")), ""), "addr": addr_,
                                          "verdict": v_, "names": names_,
                                          "how": {n_: hw_.get(n_, "call") for n_ in names_}})
            for r in recs:
                if r.get("free_checked") == "no symbol":
                    counts["info: free_checked no symbol"] += 1    # (integ3, rev5) unchecked by name: a gap
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
                for m_ in r.get("unproven_baseline", []):
                    exempt.append("%s %s" % (r["addr"], m_))
                if f:
                    f.write(json.dumps(r) + "\n")
    if f:
        f.close()
    return {"tus": len(paths), "cache_hits": hits, "counts": dict(sorted(counts.items())), "errors": errors[:20],
            "n_errors": len(errors), "inputs": inputs_digest(paths),
            "ledger": None if not view else "none" if led is None else len(led),
            "unproven_baseline": load_unproven_baseline().get("total", 0),    # (D126) the list's size, for status
            # (integ5, D157) the equivalent blocks' modes this verify reported instead of failing: listed for their code
            "unproven_baseline_exempt": {"count": len(exempt), "blocks": sorted(exempt)},
            "free_name_baseline": load_free_baseline().get("total", 0),       # (D149)
            **({"free_names": free_rows} if free_rows else {})}


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
    s = verify(tus, jobs=jobs, relocs=relocs, out=recs_out, wine=wine, view=False)
    checks = [json.loads(l) for l in open(recs_out)]
    # (integ2, D126) the Wine build runs only proven code: an equivalent block whose code hash in a mode has no ledger
    # line (under any view) and that config/unproven-baseline.json doesn't list stops the materialize
    if "unprovengate" not in os.environ.get("TREE_TU_OFF", ""):
        bad = unproven_code(checks, wine=wine)
        if bad:
            s["counts"]["unproven code, not in baseline"] = len(bad)
            s["unproven_refused"] = ["%s %s" % x for x in bad[:200]]
    s["unproven_baseline"] = load_unproven_baseline().get("total", 0)
    # (rev5's R4) a build materialized with a development switch proves nothing: it says so
    s["off"] = sorted(x for x in os.environ.get("TREE_TU_OFF", "").split(",") if x)
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
                      ("state.json", {"wrap": {}, "isolate": {}, "local_only": [], "iso_plain": {},
                                      **({"off": s["off"]} if s["off"] else {})})):
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
def sym_line(pin, h=None, wh=None, vh=None):
    return "// sym: " + pin + ("" if h is None else " @" + h) + ("" if wh is None else " @w" + wh) + \
        ("" if vh is None else " @v" + vh)


def pin_text(path, records, hashes=None):
    """The TU's text with a `// sym:` line after every block line whose function has a symbol in RECORDS ({addr:
    symbol}); an existing pin is replaced, keeping its code hashes; a block without a symbol keeps its line as it is.
    HASHES ({addr: (msvc hash or None, clang hash or None[, view hash or None])}): hashes to write (None: keep the
    line's)."""
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
            oh = dict(((w or "m"), hx) for w, hx in HASH_TOKEN.findall(old.group(2))) if old else {}
            s = records.get(m.group(1)) or (old.group(1) if old else None)
            nh = tuple(hashes.get(m.group(1), ())) + (None, None, None)
            h, wh, vh = nh[0] or oh.get("m"), nh[1] or oh.get("w"), nh[2] or oh.get("v")
            if s:
                out.append(sym_line(s, h, wh, vh))
            elif h or wh or vh:
                raise ValueError("%s %s: code hashes without a pinned symbol" % (path, m.group(1)))
    return "\n".join(out)


def text_hashes(text, views=False):
    """{addr: (msvc hash, clang hash)} recorded in a TU's text (VIEWS: (msvc, clang, view))."""
    out, lines = {}, text.split("\n")
    for i, l in enumerate(lines[:-1]):
        m = BLOCK.match(l)
        sm = SYM_LINE.match(lines[i + 1]) if m else None
        if sm:
            hs = dict(((w or "m"), hx) for w, hx in HASH_TOKEN.findall(sm.group(2)))
            if hs:
                out[m.group(1)] = (hs.get("m"), hs.get("w")) + ((hs.get("v"),) if views else ())
    return out


def removed_hashes(path, recs, ref):
    """Mark `code_hash_removed` on the records of blocks that had a code hash at git REF and have none now (a hash is
    only replaced by `hash --proven`, never dropped)."""
    root = find_root(path)
    rel = os.path.relpath(os.path.abspath(path), ROOT)
    r_ = subprocess.run(["git", "show", "%s:%s" % (ref, rel)], capture_output=True, text=True, cwd=ROOT, errors="replace")
    if r_.returncode or not root:
        return
    before = text_hashes(r_.stdout, views=True)
    now = text_hashes(open(path, errors="replace").read(), views=True)
    for r in recs:
        if r["kind"] != "equivalent":
            continue
        b, n = before.get(r["addr"], (None, None, None)), now.get(r["addr"], (None, None, None))
        if (b[0] and not n[0]) or (b[1] and not n[1]) or (b[2] and not n[2]):
            r["code_hash_removed"] = True
        # (integ1, D37) the block's recorded hashes are REF's and its code is what they say: an `unproven` block the
        # change did not touch is reported as such, not as this change's failure
        if r["addr"] in before and b == n and r.get("code") in ("ok", None) and r.get("wine_code") in ("ok", "no_object", None):
            r["unchanged_since_ref"] = True


# ------------------------------------------------------------------------------------------------------- recording
MSVC_INPUTS, WINE_INPUTS = 3000, 3000     # (integ1, D38: --wine at 3,000 too, was 600)
MIN_COMPLETED = 3000    # (integ1, user decision D62) inputs a proof must have COMPARED, per mode (inconclusive don't count)


def run_shortfall(rep, asked):
    """(integ1, D38/D62) Why a run falls short of a proof, or None: it must have compared (completed) MIN_COMPLETED
    inputs and at least as many as it asked for; inconclusive inputs are drawn but not compared. A proof-sized equiv.py
    run draws on until it has (up to equiv.PROOF_DRAW_LIMIT, or the time budget). The refusal names the counts and the
    main inconclusive causes."""
    l3 = rep.get("level3") or {}
    run = l3.get("inputs_run") or 0
    inc = l3.get("inputs_inconclusive") or 0
    drawn = l3.get("inputs_drawn") or (run + inc + (l3.get("inputs_faulted") or 0) + (l3.get("inputs_failed") or 0))
    need = max(MIN_COMPLETED, asked or 0)
    if run >= need:
        return None
    causes = sorted(((v, k) for k, v in (l3.get("statuses") or {}).items() if k != "ret" and v), reverse=True)[:3]
    why = "%d of %d inputs compared (%d drawn, %d inconclusive%s)" % (
        run, need, drawn, inc, (": " + ", ".join("%s %d" % (k, v) for v, k in causes)) if causes else "")
    if l3.get("time_budget_hit"):
        why += "; the time budget ran out (use a longer --time-budget)"
    elif l3.get("inconclusive_cap_hit") and not l3.get("proofcap"):
        why += "; the inconclusive cap stopped it (a checker without proofcap)"
    return why


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
    shards = collections.defaultdict(list)
    for p in paths:
        text = open(p).read()
        try:
            recs = [json.loads(text)]
        except ValueError:
            recs = [json.loads(l) for l in text.splitlines() if l.strip().startswith("{")]
        for r in recs:
            if isinstance(r, dict) and r.get("addr"):
                a = "0x%08x" % int(r["addr"], 16)
                sh_ = (r.get("level3") or {}).get("shard")
                if sh_:
                    # (integ5, D155c) a shard proves nothing alone: the shards of one proof are merged first
                    tc_ = {k_: v_ for k_, v_ in (r.get("tree_code") or {}).items() if k_ != "job"}
                    shards[(a, bool(r.get("native")), sh_[1], json.dumps(tc_, sort_keys=True, default=str))].append(r)
                else:
                    out[a].append(r)
    SHARD_NOTES[:] = []
    for (a, _nat, n_, _tc), reps in sorted(shards.items()):
        m_, why_ = merge_shards(reps)
        SHARD_NOTES.append({"addr": a, "native": _nat, "shards": n_, "merged": m_ is not None, "why": why_})
        if m_ is not None:
            out[a].append(m_)
    return out


SHARD_NOTES = []    # (integ5, D155c) what _load_results did with each group of shard reports

# (integ5, D155c; rev5) how each level-3 field of the shards of one proof merges. A field no rule names refuses the
# merge (default-deny): a new counter needs its rule here before a sharded proof may count it.
SHARD_SUM = {"inputs_run", "inputs_inconclusive", "inputs_faulted", "inputs_failed", "inputs_directed", "inputs_drawn",
             "inputs_compared_small", "inputs_defnan_planted", "inputs_memfwd", "inputs_nan_eq", "inputs_objptr",
             "inputs_planted", "inputs_pre_repaired", "inputs_repaired", "inputs_sentinel", "inputs_small",
             "inputs_strcase", "inputs_stubexit", "inputs_tie", "inputs_words", "post_checked", "post_phase", "post_ret0",
             "post_unread", "sentinel_runs", "stubexit_runs", "vsplit_reruns", "work", "edges_withdrawn",
             "pre_defnan_all", "pre_defnan_words", "pre_range_bounds", "stubexit_sealed", "cpu", "sentinel_time",
             "inputs_repeated"}
SHARD_SUM_DICT = {"statuses", "workn", "stubexit_n", "unexplained"}
SHARD_MAX = {"long_steps", "rep_allow_max", "static_counts", "early_returns"}
SHARD_ANY = {"huge_rep", "probe_skipped", "covcap", "inconclusive_cap_hit", "time_budget_hit"}
SHARD_LIST = {"proofcap", "proofdraw", "long_skipped", "input_digest", "coverage_with_inconclusive"}
SHARD_FIRST = {"post_refuted_first", "pre_violation_first"}
SHARD_EQUAL = {"pre_trap", "pre_trap_words"}
SHARD_REFUSE = {"time_cut_wall", "unsupported"}
SHARD_SPECIAL = {"ok", "mismatches", "coverage", "post_pairs", "post_pair_list", "shard", "compared_keys", "touched"}


def merge_shards(reps):
    """(integ5, D155c; rev5) One report from the N shard reports of a sharded proof (equiv.py --shard K/N), or (None,
    why). Every shard K = 0..N-1 exactly once, of the same block, mode, code, view, checker and switches; a shard that is
    unsupported or cut by the CPU cap means no proof; a difference in any shard is the merged run's difference. Counts
    sum (the inconclusive and set-aside caps then read the totals), post pairs are the union of distinct pairs, the
    coverage is that of the union of the covered edges, the contract trap must have fired in every shard; then
    equiv.level3_verdict gives status and promotable by the whole run's rules. The merged report names every shard's
    job (`shards`)."""
    import equiv
    if not reps:
        return None, "no shards"
    n = (reps[0].get("level3") or {}).get("shard", [0, 0])[1]
    ks = sorted((r.get("level3") or {}).get("shard", [None])[0] for r in reps)
    if {tuple((r.get("level3") or {}).get("shard") or ())[1:] for r in reps} != {(n,)}:
        return None, "the shards were not all cut %d ways" % n
    if n < 2 or ks != list(range(n)):
        return None, "shards %s of %d: every shard 0..%d exactly once" % (ks, n, n - 1)
    key = lambda r: json.dumps([r.get("addr"), bool(r.get("native")), r.get("symbol")] +
                               [(r.get("tree_code") or {}).get(k) for k in ("msvc", "wine", "view", "checker", "n_inputs",
                                                                           "x87_keep")], default=str)
    if len({key(r) for r in reps}) != 1:
        return None, "the shards are not runs of one block, mode, code, view and checker"
    if any(r.get("equiv_off") or r.get("equiv_on") for r in reps):
        return None, "a shard ran with checker switches"
    if len({json.dumps([r.get("post"), r.get("pre")], default=str) for r in reps}) != 1:
        return None, "the shards disagree on the block's contracts"
    if len({json.dumps(r.get("view_parts"), sort_keys=True) for r in reps}) != 1:
        return None, "the shards disagree on the checker view's parts"
    for r in reps:
        st_ = r.get("status")
        if st_ == "unsupported" or (r.get("level3") or {}).get("time_cut_wall"):
            return None, "shard %s: %s (%s)" % (r["level3"]["shard"][0], st_, r.get("class") or r.get("error") or "")
        if st_ not in ("equivalent", "inconclusive", "fail"):
            return None, "shard %s: status %s" % (r["level3"]["shard"][0], st_)
    known = SHARD_SUM | SHARD_SUM_DICT | SHARD_MAX | SHARD_ANY | SHARD_LIST | SHARD_FIRST | SHARD_EQUAL | SHARD_REFUSE | \
        SHARD_SPECIAL
    l3s = [r.get("level3") or {} for r in sorted(reps, key=lambda r: r["level3"]["shard"][0])]
    unknown = sorted({k for l in l3s for k in l} - known)
    if unknown:
        return None, "no merge rule for %s (default-deny)" % ", ".join(unknown)
    m = {}
    for k in SHARD_SUM:
        if any(k in l for l in l3s):
            m[k] = sum(l.get(k) or 0 for l in l3s)
    for k in SHARD_SUM_DICT:
        if any(k in l for l in l3s):
            c_ = collections.Counter()
            for l in l3s:
                c_.update({x: v for x, v in (l.get(k) or {}).items()})
            m[k] = dict(c_)
    for k in SHARD_MAX:
        if any(k in l for l in l3s):
            m[k] = max(l.get(k) or 0 for l in l3s)
    for k in SHARD_ANY:
        if any(l.get(k) for l in l3s):
            m[k] = True
    for k in SHARD_LIST:
        if any(k in l for l in l3s):
            m[k] = [l.get(k) for l in l3s]
    for k in SHARD_FIRST:
        v_ = next((l[k] for l in l3s if l.get(k)), None)
        if v_ is not None:
            m[k] = v_
    for k in SHARD_EQUAL:
        vs_ = {json.dumps(l.get(k), default=str) for l in l3s}
        if len(vs_) != 1:
            return None, "the shards disagree on %s (%s): every shard runs the same check" % (k, sorted(vs_))
        if k in l3s[0]:
            m[k] = l3s[0][k]
    if any(not isinstance(l.get("compared_keys"), list) for l in l3s):
        return None, "a shard does not list its compared inputs"
    keys_ = set()
    for l in l3s:
        keys_.update(l["compared_keys"])
    if len(keys_) != m.get("inputs_run", 0):
        # (rev5) an input two shards both compared counts once: the compared total is the distinct inputs
        m["compared_duplicates"] = m.get("inputs_run", 0) - len(keys_)
    m["inputs_run"] = len(keys_)
    if any("touched" in l for l in l3s):
        # (integ6, D159) what the whole proof reached: the union of the shards' touched sets (a carry reads it); a shard
        # without one leaves the merged run without one (it then never carries)
        if all(isinstance(l.get("touched"), dict) for l in l3s):
            m["touched"] = {k_: sorted({x for l in l3s for x in (l["touched"].get(k_) or ())}) for k_ in ("callees", "symbols")}
    m["ok"] = all(l.get("ok") for l in l3s)
    m["mismatches"] = [x for l in l3s for x in (l.get("mismatches") or [])]
    if any("post_pairs" in l for l in l3s):
        if any(l.get("post_pairs") and "post_pair_list" not in l for l in l3s):
            return None, "a shard reports post pairs without the list"
        m["post_pair_list"] = sorted({x for l in l3s for x in (l.get("post_pair_list") or [])})
        m["post_pairs"] = len(m["post_pair_list"])     # (rev5) distinct pairs over all shards, not a sum
    covs = [l.get("coverage") or {} for l in l3s]
    if any("missing_all" not in c for c in covs):
        return None, "a shard's coverage lacks its uncovered edges"
    base_ = {c["edges_total"] - len(c.get("dead_taken") or []) for c in covs}
    if len(base_) != 1:
        return None, "the shards disagree on the edges to cover"
    dead_ = sorted({x for c in covs for x in (c.get("dead_taken") or [])})
    missing = set(covs[0]["missing_all"])
    for c in covs[1:]:
        missing &= set(c["missing_all"])         # an edge counts as covered when any shard took it
    total = base_.pop() + len(dead_)
    m["coverage"] = {"edges_total": total, "edges_covered": total - len(missing), "uncovered": sorted(missing)[:20],
                     "complete": not missing, "missing_all": sorted(missing),
                     "uncovered_hash": hashlib.sha1("\n".join(sorted(missing)).encode()).hexdigest()[:12]}
    if dead_:
        m["coverage"]["dead_taken"] = dead_
    m["shard"] = [None, n]
    out = json.loads(json.dumps(reps[0], default=str))
    out["level3"] = m
    out["level"] = 2 if out.get("level", 0) >= 2 else out.get("level")
    for k_ in ("status", "class", "error", "inconclusive", "promotable", "promotable_note", "failed_levels"):
        out.pop(k_, None)
    issues = []
    seen_ = set()
    for r in reps:
        for i_ in (r.get("level2") or {}).get("issues") or []:
            k2_ = json.dumps(i_, sort_keys=True, default=str)
            if k2_ not in seen_:
                seen_.add(k2_)
                issues.append(i_)
    out["level2"] = dict(out.get("level2") or {}, issues=issues, ok=not issues)
    out["shards"] = {"n": n, "jobs": [(r.get("tree_code") or {}).get("job") for r in
                                      sorted(reps, key=lambda r: r["level3"]["shard"][0])],
                     "input_digests": [l.get("input_digest") for l in l3s]}
    import time as time_
    out = equiv.level3_verdict(out, m, issues, out.get("post"), 0, time_.time())
    return out, "merged %d shards: %s" % (n, out.get("status"))


def proves(rep, kind, h, view=None):
    """(ok, why): does equiv.py report REP prove the code that hashes to H (and, given VIEW, with the checker's view of it
    as it is now: integ1, D42)? msvc: a promotable MSVC run asked for >= 3,000 inputs; wine: a --wine run that passes
    the promotion gate (tools/wine_gate.py) asked for >= 3,000 (D38)."""
    tc = rep.get("tree_code") or {}
    if h is None:
        return False, "no hash to prove"
    if (rep.get("level3") or {}).get("shard") and not rep.get("shards"):
        return False, "one shard of a sharded proof (merge all of them: hash --proven takes every shard's report)"
    if rep.get("equiv_off") or rep.get("equiv_on"):
        return False, "a run with non-default checker switches (EQUIV_OFF %s, EQUIV_ON %s)" % (
            ",".join(rep.get("equiv_off") or []) or "-", ",".join(rep.get("equiv_on") or []) or "-")
    if bool(rep.get("native")) != (kind == "wine"):
        return False, "another mode"
    if tc.get(kind) != h:
        return False, "a run of other code (%s, now %s)" % (tc.get(kind), h)
    if view is not None and tc.get("view") != view:
        return False, "a run with another checker view (%s, now %s)" % (tc.get("view"), view)
    if kind == "msvc":
        if not rep.get("promotable"):
            return False, "not promotable (%s)" % rep.get("status")
        if (tc.get("n_inputs") or 0) < MSVC_INPUTS:
            return False, "asked for %s inputs (%d needed)" % (tc.get("n_inputs"), MSVC_INPUTS)
        why_ = run_shortfall(rep, tc["n_inputs"])
        if why_:
            return False, why_
        return True, "promotable at %s inputs (%s compared)" % (tc["n_inputs"], (rep.get("level3") or {}).get("inputs_run"))
    import wine_gate
    ok, why = wine_gate.judge(rep)
    if not ok:
        return False, why
    if tc.get("x87_keep"):
        return False, "the --wine compile used an x87-keep list (%d functions): run it without one" % tc["x87_keep"]
    if (tc.get("n_inputs") or 0) < WINE_INPUTS:
        return False, "asked for %s inputs (%d needed)" % (tc.get("n_inputs"), WINE_INPUTS)
    why_ = run_shortfall(rep, tc["n_inputs"])
    if why_:
        return False, why_
    return True, why


def _ledger_lines(addr, mode, code, path=None):
    """(integ6, D159) the ledger's lines of (ADDR, MODE, CODE), in file order"""
    out = []
    with open(path or LEDGER) as f:
        for l in f:
            if ('"%s"' % addr) in l and l.strip().startswith("{"):
                e = json.loads(l)
                if (e.get("addr"), e.get("mode"), e.get("code")) == (addr, mode, code):
                    out.append(e)
    return out


def current_view(path, addr, mode, recs, cobj=None):
    """(integ6, D159) (view hash, view parts) of block ADDR in MODE as the checker sees it now (a view-only run)."""
    import equiv
    was = equiv.VIEW_DECLARITY[0]
    equiv.VIEW_DECLARITY[0] = True       # (rev5) levels 1 and 2 in full: decl_arity too
    try:
        rep = equiv.verify(os.path.abspath(path), int(addr, 16), view_only=True, recs=recs, native=mode == "wine",
                           obj_path=cobj if mode == "wine" else None)
    finally:
        equiv.VIEW_DECLARITY[0] = was
    return rep.get("view"), rep.get("view_parts"), equiv.l2_parts(rep)


def hash_proven(path, results, addrs=None, dry_run=False, ledger=None, unproven_accepted=False, carry=False):
    """Record what RESULTS ({addr: [equiv.py reports]}) prove about PATH's equivalent blocks as they are now (proves():
    the code and the checker's view in each mode): a proven mode's run goes into the proof ledger (integ1, D37), and a
    block whose every mode is proven gets its code hashes and `@v` (D42) written; a mode already in the ledger for its
    current code and view needs no new run. Returns the per-block outcome."""
    rec = scan(path)
    recs = check_tu(path, rec=rec)
    with_wine(path, recs, rec)
    vs = views(path, recs, rec, wine=True)
    led = ledger_index(ledger) or set()
    ub = load_unproven_baseline().get("blocks", {}) if unproven_accepted else {}
    blocks = {b["addr"]: b for b in rec["blocks"]}
    root = find_root(os.path.abspath(path))
    tu = os.path.relpath(os.path.abspath(path), root) if root else path
    out, new, entries = [], {}, []
    for r in recs:
        if r["kind"] != "equivalent" or (addrs and r["addr"] not in addrs):
            continue
        o = {"addr": r["addr"], "code": r.get("code"), "wine_code": r.get("wine_code")}
        if not r.get("symbol"):
            o["result"] = "no symbol (%s)" % r["status"]
            out.append(o)
            continue
        if not carry and not results.get(r["addr"]) and r.get("code") == "ok" and \
                r.get("wine_code") in ("ok", "no_object"):
            o["result"] = "skipped: no result for this block (code unchanged)"
            out.append(o)
            continue
        v = vs.get(r["addr"]) or {}
        vm, vw = v.get("msvc"), v.get("wine")
        if v.get("error") or vm is None or (vw is None and r.get("wine_code_hash") is not None):
            o["result"] = "unproven: no checker view (%s)" % (v.get("error") or "none")
            out.append(o)
            continue
        modes = [("msvc", "code", vm)] + ([("wine", "wine_code", vw)] if r.get("wine_code_hash") is not None else [])
        for kind, key, view in modes:
            h = r.get(key + "_hash")
            if (r["addr"], kind, h, view) in led:
                o[kind] = "in the ledger"
                continue
            if carry:
                # (integ6, D159) no run: a run line of this code under this checker whose view differs only in entries
                # the run never reached (carry_check); the new view is recomputed here, with its parts
                import equiv
                cobj_ = None
                tmp_ = None
                try:
                    if kind == "wine":
                        import tempfile
                        tmp_ = tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build"))
                        cobj_ = wine_object(os.path.abspath(path), tmp_.name)
                    cv_, cp_, cl2_ = current_view(path, r["addr"], kind, recs, cobj_)
                finally:
                    if tmp_ is not None:
                        tmp_.cleanup()
                if cv_ != view:
                    o[kind] = "unproven: the view-only run gave view %s, the block's view is %s" % (cv_, view)
                    continue
                cur_ = {"addr": r["addr"], "mode": kind, "code": h, "checker": equiv._checker_digest(), "view": view,
                        "view_parts": cp_, "l2_parts": cl2_}
                whys_, got_ = [], None
                for e_ in _ledger_lines(r["addr"], kind, h, ledger):
                    ok_, d_ = carry_check(e_, cur_)
                    if ok_:
                        got_ = carried_line(e_, cur_, d_, tu)
                        break
                    whys_.append("%s: %s" % (ledger_line_key(e_)[:10], d_))
                if got_ is None:
                    o[kind] = "unproven: no line carries (%s)" % ("; ".join(whys_[-4:]) or "no line of this code")
                    continue
                o[kind] = "carried from %s (%s)" % (got_["carried_from"], ", ".join(got_["carry_delta"][:6]))
                entries.append(got_)
                o.setdefault("ledger", []).append(got_)
                continue
            if unproven_accepted:
                # (integ3, lead) the mode is unproven and config/unproven-baseline.json lists exactly this code (an
                # unproven-accept after a layout-only edit): the pin follows the code; no proof is claimed or recorded,
                # and the materialize gate keeps refusing anything the list doesn't name
                bm_ = (ub.get(r["addr"], {}).get("modes") or {}).get(kind) or {}
                if bm_.get("code") == h and h:
                    o[kind] = "unproven-accepted (%s)" % (bm_.get("by") or "?")
                    continue
                o[kind] = "unproven: neither the ledger nor the unproven list holds %s" % h
                continue
            why = [(x, proves(x, kind, h, view)) for x in results.get(r["addr"], [])]
            good = [(x, w) for x, (ok, w) in why if ok]
            if good:
                ent_ = ledger_entry(r["addr"], kind, h, view, good[0][0], tu)
                rw_ = revoked_run(ent_)
                if rw_ is not None:
                    # (integ4, D154; rev5) the same code under a revoked checker: never written
                    o[kind] = "unproven: the run's checker %s was revoked for this code (%s)" % (ent_.get("checker"), rw_)
                    continue
                o[kind] = good[0][1]
                entries.append(ent_)
                o.setdefault("ledger", []).append(entries[-1])
            else:
                o[kind] = "unproven: " + ("; ".join(w for _, (_, w) in why) or "no result for this block")
        if any(str(o.get(k, "")).startswith("unproven:") or (str(o.get(k, "")).startswith("unproven") and not
               str(o.get(k, "")).startswith("unproven-accepted")) for k in ("msvc", "wine")):
            o["result"] = "unproven: nothing recorded on the pin line"
            out.append(o)
            continue
        vh = view_digest(vm, vw)
        b = blocks[r["addr"]]
        if b.get("hash") != r.get("code_hash") or (r.get("wine_code_hash") is not None and
                                                    b.get("whash") != r.get("wine_code_hash")) or b.get("vhash") != vh:
            new[r["addr"]] = (r.get("code_hash"), r.get("wine_code_hash"), vh)
            o["result"] = "recorded"
            o["hashes"] = new[r["addr"]]
        else:
            o["result"] = "unchanged"
        out.append(o)
    if not dry_run:
        if new:
            _write(path, {r["addr"]: r.get("pin") or r["symbol"] for r in recs if r["addr"] in new}, new)
        if entries:
            ledger_append(entries, ledger)
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
    s = verify(paths, jobs=jobs, wine=True, out=None, view=False)     # (fills the caches in parallel)
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
    p.add_argument("--no-view", action="store_true", help="skip the checker views (@v) and the proof ledger")
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
    p.add_argument("--no-view", action="store_true", help="skip the checker views (@v) and the proof ledger (D37/D42)")
    p.add_argument("--gen-probe", action="store_true", help="run gen_headers.py --probe even when no include/gen/ "
                   "header changed (by default it runs when one did: since --changed-since, uncommitted, or shipped)")
    p.add_argument("--head-only", action="store_true", help="as a queue job: verify the commit (plus what is shipped) "
                   "on purpose, though the checkout has unshipped edits the TUs read (jobq.py refuses the job otherwise)")
    p.add_argument("--update-free-baseline", action="store_true", help="(D149, with --relocs) drop from "
                   "config/free-name-baseline.json the free-by-other-name calls the checked blocks no longer make")
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
    p = sub.add_parser("unproven-accept", help="(D126) list an equivalent block's unproven modes in "
                       "config/unproven-baseline.json, with a reason")
    p.add_argument("addr")
    p.add_argument("--tu", required=True, help="the block's tree TU (its hashes are taken from its check)")
    p.add_argument("--modes", default="msvc,wine")
    p.add_argument("--why", required=True)
    p = sub.add_parser("revoke", help="(integ4, D154) revoke every ledger line that proves ADDR in MODE now (a run a later "
                       "checker rule shows unsound): config/proof-revoked.jsonl, append-only")
    p.add_argument("addr")
    p.add_argument("--mode", required=True, choices=["msvc", "wine"])
    p.add_argument("--why", required=True)
    p = sub.add_parser("epoch-mark", help="(integ6; rev5) mark checker digest DIGEST as the same semantics as PREV "
                       "(carry may cross the link): config/checker-epochs.jsonl, append-only; only with the reviewer's "
                       "approval of that change, identical selftests on every host and identical regress facts")
    p.add_argument("digest")
    p.add_argument("--same-as", required=True)
    p.add_argument("--why", required=True)
    p.add_argument("--review", required=True, help="the reviewer's approval of this mark (agent and date, or the commit)")
    p.add_argument("--selftest", nargs="+", required=True, metavar="JOB", help="host_selftest jobs under DIGEST")
    p.add_argument("--prev-selftest", nargs="+", required=True, metavar="JOB", help="host_selftest jobs under PREV")
    p.add_argument("--regress", nargs="+", required=True, metavar="JOB", help="the full regress suite's queue jobs "
                   "under DIGEST (each wrote jobsrc/regsum.jsonl with REGRESS_SUMMARY)")
    p.add_argument("--prev-regress", nargs="+", required=True, metavar="JOB", help="... under PREV")
    p = sub.add_parser("epoch-split", help="(integ6; rev5) cut the mark of DIGEST (it was semantic after all): every "
                       "carry across that link stops proving; append-only")
    p.add_argument("digest")
    p.add_argument("--why", required=True)
    p.add_argument("--review", required=True)
    p = sub.add_parser("unproven-seed", help="(D126) seed config/unproven-baseline.json from a verify/materialize "
                       "checks.jsonl: every equivalent (addr, mode) whose code has no ledger line (once, when the gate "
                       "begins)")
    p.add_argument("checks")
    p.add_argument("--why", required=True)
    p = sub.add_parser("free-name-accept", help="(D149) list a block's reference of a free under another name in "
                       "config/free-name-baseline.json, with a reason (a matches block: call / address / table; an "
                       "equivalent block: name)")
    p.add_argument("addr", nargs="?")
    p.add_argument("--tu")
    p.add_argument("--name", help="the callee's name as verify_relocs reports it")
    p.add_argument("--records", metavar="JSONL", help="(integ3) instead of ADDR/--tu/--name: accept every reported "
                   "name of --how's kind in a `verify --relocs --out` records file (the equivalent blocks' seed, once)")
    p.add_argument("--how", choices=("call", "address", "table", "name"), help="with --records: `name` only (the "
                   "equivalent blocks' seed); with ADDR: checked against what the fresh check reports")
    p.add_argument("--job", help="with --records: the queue job id that wrote the records (put in the stamp)")
    p.add_argument("--commit", help="with --records: the commit the records were checked at (put in the stamp)")
    p.add_argument("--why", required=True)
    p = sub.add_parser("free-name-seed", help="(D149) seed config/free-name-baseline.json from a `verify --relocs --out` "
                       "records file (once, when the gate begins)")
    p.add_argument("records")
    p.add_argument("--why", required=True)
    p = sub.add_parser("hash", help="record equivalent blocks' code hashes (only from proofs)")
    p.add_argument("paths", nargs="+", help="TUs (--proven), or the tree root (--compute)")
    p.add_argument("--unproven-accepted", action="store_true", help="(integ3) re-pin equivalent blocks whose every mode "
                   "is proven by the ledger (current code and view) or listed with exactly its current code hash in "
                   "config/unproven-baseline.json (unproven-accept after a layout-only edit); no run, no ledger line")
    p.add_argument("--from-ledger", action="store_true", help="(integ3, movers) re-pin equivalent blocks whose current "
                   "code AND checker view already have a promotable ledger line in every mode (no new run: the line is the "
                   "proof; MSVC 7.1's header-sensitive spill orders, 0x00027930 & co.); any other block is refused")
    p.add_argument("--carry", action="store_true", help="(integ6, D159) re-pin equivalent blocks whose code hashes and "
                   "checker are unchanged and whose view moved only in decls / pointee_sizes / bindings entries the proof "
                   "run never reached: no run; a carried ledger line names its run line (docs/equivalence.md)")
    p.add_argument("--proven", nargs="+", metavar="RESULT", help="equiv.py --json reports / jsonl: an MSVC run at "
                   "--inputs 3000 (promotable) and a --wine run (>= 3,000) of the code and checker view as they are now")
    p.add_argument("--addr", action="append", help="only these blocks (with --proven)")
    p.add_argument("--compute", metavar="OUT.jsonl", help="report the hashes of the code as it stands (writes no TU)")
    p.add_argument("--tus", metavar="FILE", help="with --compute: TU paths, one per line (default: every TU)")
    p.add_argument("--commit", help="with --compute: the commit the workspace is (recorded)")
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--ledger", metavar="JSONL", help="with --proven: the proof ledger to read and append to (default "
                   "config/proof-ledger.jsonl)")
    p.add_argument("--json", action="store_true")
    a = ap.parse_args(argv)
    if a.cmd in ("free-name-accept", "free-name-seed") and not (a.why or "").strip():
        sys.exit("%s: --why must give a reason" % a.cmd)
    if a.cmd == "free-name-accept":
        today = __import__("datetime").datetime.now().isoformat(timespec="seconds")
        b = load_free_baseline()
        if a.records:
            # (integ3) the reported names of one kind from a whole-tree `verify --relocs --out`, each stamped as an
            # accept (free_baseline_growth lets a new accept stamp through); rev5 approves the use (the equivalent
            # blocks' `name` seed when that check began)
            # (rev5) a once-only seed of one kind, never a standing bulk path: `name` only, refused once any `name`
            # entry exists here or at REF, and the stamp names the records' job and commit
            if a.how != "name":
                sys.exit("free-name-accept --records: only --how name (the equivalent blocks' seed); accept call, "
                         "address and table rows one by one")
            if not (a.job and a.commit):
                sys.exit("free-name-accept --records: give --job and --commit of the verify that wrote the records")

            def has_name_kind(bl):
                return any("name" in (free_entry(e)[1].get("how") or {}).values()
                           for ents in bl.get("tus", {}).values() for e in ents.values())
            if has_name_kind(b):
                sys.exit("free-name-accept --records: the baseline already holds `name` entries (the seed is once)")
            # (rev5's residual) REF is always HEAD (in a queue job, the job's base commit): no older REF from before the
            # seed can be named to re-run it
            m_ = job_meta()
            ref = (m_ or {}).get("commit") if m_ is not None and subprocess.run(
                ["git", "rev-parse", "--git-dir"], cwd=ROOT, capture_output=True).returncode != 0 else "HEAD"
            try:
                text = file_at_ref(ref or "HEAD", "config/free-name-baseline.json")
            except RefReadError as e:
                sys.exit("free-name-accept --records: %s unreadable: %s" % (ref, e))
            if text and has_name_kind(json.loads(text)):
                sys.exit("free-name-accept --records: %s's baseline holds `name` entries (the seed is once)" % ref)
            why = "%s [records: job %s at %s]" % (a.why.strip(), a.job, a.commit)
            n = 0
            for l in open(a.records):
                if not l.strip():
                    continue
                r = json.loads(l)
                hw = r.get("free_how", {})
                pick = {x for x in r.get("free_by_other_name", []) if hw.get(x, "call") == a.how}
                if not pick:
                    continue
                names, st = free_entry(b.setdefault("tus", {}).setdefault(r["tu"], {}).get(r["addr"], []))
                if pick <= names:
                    continue
                e = {"names": sorted(names | pick), "accepted": today, "by": "free-name-accept", "why": why}
                hows = dict(st.get("how", {}))
                hows.update({x: a.how for x in pick if a.how != "call"})
                if hows:
                    e["how"] = hows
                b["tus"][r["tu"]][r["addr"]] = e
                n += len(pick - names)
            write_free_baseline(b)
            print(n, "names accepted")
            return 0
        if not (a.addr and a.tu and a.name):
            sys.exit("free-name-accept: give ADDR --tu --name (or --records --how)")
        recs = check_tu(a.tu, relocs=True)
        r = next((x for x in recs if x["addr"] == a.addr), None)
        if r is None or r.get("kind") not in ("matches", "equivalent"):
            sys.exit("free-name-accept: %s is no block of %s" % (a.addr, a.tu))
        how = r.get("free_how", {}).get(a.name, "call" if r.get("kind") == "matches" else "name")
        if a.how and a.how != how:
            sys.exit("free-name-accept: the check reports %s as %s, not %s" % (a.name, how, a.how))
        tu = os.path.relpath(os.path.abspath(a.tu), find_root(a.tu) or ROOT)
        names, st = free_entry(b.setdefault("tus", {}).setdefault(tu, {}).get(a.addr, []))
        e = {"names": sorted(names | {a.name}), "accepted": today, "by": "free-name-accept", "why": a.why.strip()}
        hows = dict(st.get("how", {}))
        if how != "call":
            hows[a.name] = how
        if hows:
            e["how"] = hows
        b["tus"][tu][a.addr] = e
        write_free_baseline(b)
        print(tu, a.addr, b["tus"][tu][a.addr])
        return 0
    if a.cmd == "free-name-seed":
        if os.path.exists(FREE_BASELINE):
            sys.exit("free-name-seed: config/free-name-baseline.json exists (it only shrinks; add with free-name-accept)")
        b = {"comment": "D149: matches blocks that call one of the game's frees (operator delete / delete[], FREE_NAMES) "
                        "under another name, when the gate began. Only shrinks (verify --relocs --update-free-baseline); "
                        "add with tree_tu.py free-name-accept --why. decl1 removes them.",
             "seed_why": a.why.strip(), "tus": {}}
        for l in open(a.records):
            if not l.strip():
                continue
            r = json.loads(l)
            if r.get("free_by_other_name"):
                b["tus"].setdefault(r["tu"], {})[r["addr"]] = sorted(set(r["free_by_other_name"]))
        write_free_baseline(b)
        print(sum(len(v) for v in b["tus"].values()), "blocks", b["total"], "names")
        return 0
    if a.cmd in ("unproven-accept", "unproven-seed") and not (a.why or "").strip():
        sys.exit("%s: --why must give a reason" % a.cmd)
    if a.cmd in ("epoch-mark", "epoch-split"):
        import datetime
        if not a.why.strip() or not a.review.strip():
            sys.exit("%s: --why and --review must be given" % a.cmd)
        marks, splits = _epoch_records()
        rec = {"kind": a.cmd.split("-")[1], "digest": a.digest, "why": a.why.strip(), "review": a.review.strip(),
               "date": datetime.date.today().isoformat()}
        if a.cmd == "epoch-split":
            if a.digest not in marks or a.digest in splits:
                sys.exit("epoch-split: %s has no mark in force" % a.digest)
        else:
            ok_, why_, facts_ = epoch_mark_evidence(a.digest, a.same_as, a.selftest, a.prev_selftest, a.regress,
                                                    a.prev_regress)
            if not ok_:
                sys.exit("epoch-mark refused: " + why_)
            if a.digest in marks:
                sys.exit("epoch-mark: %s is marked already (append-only; a split cuts a mark, never a second one)" % a.digest)
            rec.update(same_as=a.same_as, **facts_)
        with open(EPOCHS, "a") as f:
            f.write(json.dumps(rec, sort_keys=True) + "\n")
        print(json.dumps(rec))
        return 0
    if a.cmd == "revoke":
        # (integ4, D154) append-only: no un-revoke; a fresh proof (another ledger line) is the only way back
        if not (a.why or "").strip():
            sys.exit("revoke: --why must give a reason")
        addr = "0x%08x" % int(a.addr, 16)
        lines = []
        if os.path.exists(LEDGER):
            for l in open(LEDGER):
                l = l.strip()
                if l.startswith("{"):
                    e = json.loads(l)
                    if e.get("addr") == addr and e.get("mode") == a.mode and ledger_line_proves(e):
                        lines.append(e)
        if not lines:
            sys.exit("revoke: no ledger line proves %s %s" % (addr, a.mode))
        rec = {"addr": addr, "mode": a.mode, "lines": sorted(ledger_line_key(e) for e in lines),
               "codes": sorted({e.get("code") for e in lines}), "jobs": sorted({str(e.get("job")) for e in lines}),
               "runs": sorted({(e.get("code"), e.get("checker")) for e in lines}),
               "why": a.why.strip(), "by": "revoke",
               "date": __import__("datetime").datetime.now().isoformat(timespec="seconds")}
        with open(REVOKED, "a") as f:
            f.write(json.dumps(rec, sort_keys=True) + "\n")
        print("revoked", addr, a.mode, len(lines), "line(s):", rec["codes"])
        return 0
    if a.cmd == "unproven-accept":
        # (rev5's R3) the hash comes from the block's check, the block must be an equivalent one and the mode unproven
        recs = check_tu(a.tu)
        with_wine(a.tu, recs)
        r = next((x for x in recs if x["addr"] == a.addr), None)
        if r is None or r.get("kind") != "equivalent":
            sys.exit("unproven-accept: %s is no equivalent block of %s" % (a.addr, a.tu))
        led = code_ledger_index()
        b = load_unproven_baseline()
        ent = b["blocks"].setdefault(a.addr, {"modes": {}, "why": a.why.strip()})
        today = __import__("datetime").datetime.now().isoformat(timespec="seconds")   # (a full timestamp)
        for mode in [m for m in a.modes.split(",") if m]:
            h = r.get({"msvc": "code_hash", "wine": "wine_code_hash"}[mode])
            if not h:
                sys.exit("unproven-accept: %s has no %s code hash" % (a.addr, mode))
            if (a.addr, mode, h) in led:
                sys.exit("unproven-accept: %s %s is proven (a ledger line holds its code)" % (a.addr, mode))
            ent["modes"][mode] = {"code": h, "accepted": today, "by": "unproven-accept", "why": a.why.strip()}
        ent["why"] = a.why.strip()
        write_unproven_baseline(b)
        print(a.addr, ent)
        return 0
    if a.cmd == "unproven-seed":
        if os.path.exists(UNPROVEN_BASELINE):
            sys.exit("unproven-seed: config/unproven-baseline.json exists (the list only shrinks; add a block with "
                     "unproven-accept)")
        checks = [json.loads(l) for l in open(a.checks) if l.strip()]
        bad = unproven_code(checks, base={"blocks": {}})
        h_ = {(r["addr"], m): r.get(k) for r in checks for m, k in (("msvc", "code_hash"), ("wine", "wine_code_hash"))}
        today = __import__("datetime").datetime.now().isoformat(timespec="seconds")
        b = {"comment": "D126: equivalent blocks whose code had no passing proof-ledger line when the materialize gate "
                        "began, each mode pinned to that code hash. Only shrinks (ledger_append removes proven modes; "
                        "unproven-accept adds, with a reason).", "blocks": {}}
        for addr, mode in bad:
            if not h_.get((addr, mode)):
                continue        # (no hash to pin: it stays refused)
            ent = b["blocks"].setdefault(addr, {"modes": {}, "why": a.why.strip()})
            ent["modes"][mode] = {"code": h_[(addr, mode)], "accepted": today, "by": "unproven-seed"}
        write_unproven_baseline(b)
        print(len(b["blocks"]), "blocks", b["total"], "modes")
        return 0
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
        if (a.from_ledger or a.unproven_accepted or a.carry) and a.proven:
            ap.error("hash: --from-ledger / --unproven-accepted / --carry take no --proven")
        if a.carry and (a.from_ledger or a.unproven_accepted):
            ap.error("hash: --carry alone")
        if not a.proven and not a.from_ledger and not a.unproven_accepted and not a.carry:
            ap.error("hash: --proven RESULT... or --compute OUT or --from-ledger or --unproven-accepted or --carry")
        res = {} if (a.from_ledger or a.unproven_accepted or a.carry) else _load_results(a.proven)
        addrs = {"0x%08x" % int(x, 16) for x in a.addr} if a.addr else None
        bad = 0
        for sn_ in SHARD_NOTES:     # (integ5, D155c; rev5) each group of shard reports: merged, or refused and why
            print(json.dumps({"shard_merge": sn_}) if a.json else "shards %s %s: %s" % (
                sn_["addr"], "wine" if sn_["native"] else "msvc", sn_["why"]))
        for path in a.paths:
            for o in hash_proven(path, res, addrs, dry_run=a.dry_run, ledger=a.ledger,
                                 unproven_accepted=a.unproven_accepted, carry=a.carry):
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
        return 1 if failing(s["counts"], unproven=False) or s["n_errors"] else 0
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
        if not a.no_view:
            rec_ = scan(a.tu)
            mark_views(recs, rec_, views(a.tu, recs, rec_, wine=not a.no_wine_code), ledger_index())
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
                and not r.get("overreach") and r.get("view") not in ("changed", "error") and not r.get("unproven")
            bad += not ok
            if a.json:
                print(json.dumps(r))
            else:
                code = ""
                if r["kind"] == "equivalent" and "code" in r:
                    code = "code %s%s " % (r["code"], "/" + r["wine_code"] if "wine_code" in r else "")
                if r.get("view"):
                    code += "view %s " % r["view"]
                if r.get("unproven"):
                    code += "UNPROVEN(%s) " % ",".join(r["unproven"])
                if r.get("unproven_baseline"):
                    code += "unproven-baseline(%s) " % ",".join(r["unproven_baseline"])
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
                   wine=not a.no_wine_code, ref=a.changed_since, view=not a.no_view)
        if a.changed_since and (_CONTRACT_CALLERS or _CONTRACT_SLOTS) and \
                "contractcallers" not in os.environ.get("TREE_TU_OFF", ""):
            # (integ4, D152b; lead) a contract edit re-checks every XBE caller: none may break it in its original
            cb_ = contract_caller_probe(root, _CONTRACT_CALLERS, paths)
            s["contract_callers"] = {"callers": list(_CONTRACT_CALLERS), "refused": cb_,
                                     "unprobed_slots": list(_CONTRACT_SLOTS)}
            if cb_:
                s["counts"]["contract caller breaks the contract"] = len(cb_)
            # (rev5's R3) the unproven list may only grow through unproven-accept (its stamp on the entry)
            grew = unproven_baseline_growth(a.changed_since, root)
            if grew:
                s["counts"]["unproven baseline grew without accept"] = len(grew)
                s["unproven_baseline_growth"] = grew[:50]
            fgrew = free_baseline_growth(a.changed_since, root)     # (integ3, D149)
            if fgrew:
                s["counts"]["free-name baseline grew without accept"] = len(fgrew)
                s["free_name_baseline_growth"] = fgrew[:50]
        if a.update_free_baseline:
            if not a.relocs:
                sys.exit("verify --update-free-baseline needs --relocs")
            fb_ = load_free_baseline()
            n_ = 0
            for row in s.get("free_names", []):
                if row["verdict"] != "fixed":
                    continue
                ent = fb_.get("tus", {}).get(row["tu"], {})
                if row["addr"] not in ent:
                    continue
                names_, st_ = free_entry(ent[row["addr"]])
                left = names_ - set(row["names"])
                if isinstance(ent[row["addr"]], list):
                    ent[row["addr"]] = sorted(left)
                else:
                    ent[row["addr"]]["names"] = sorted(left)
                n_ += len(names_) - len(left)
            if n_:
                write_free_baseline(fb_)
            s["free_name_baseline_lowered"] = n_
            s["free_name_baseline"] = load_free_baseline().get("total", 0)
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
