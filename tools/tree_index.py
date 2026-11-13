#!/usr/bin/env python3
"""Address -> block of the merged tree, for tools that used to read a function's own source file.

Since merge-once step (d) (2026-11-13) there are no per-function sources (matches/0xADDR.cpp, equivalent/0xADDR.cpp;
`git show <commit>:matches/0x....cpp` in docs/merge-once.md restores one): every function is a block of a tree TU
(`// 0xADDR NAME (SIZE B): matches|equivalent/...`, tools/tree_tu.py). This module finds blocks by address with a
plain line scan (no parse; tree_tu.scan also parses each block's names, which costs seconds per large TU) and hands
out the texts the old readers took from the per-function file:

  * block_text(addr): the block's own lines (its definition and its `// equiv-*` directive lines);
  * unit_text(addr): the TU's shared part (everything before its first block: the hoisted declarations) followed by
    the block, as tree_tu.unit_text gives it (the TU namespace lines blanked);
  * source_text(addr): unit_text with the block line neutralised (`// (block) ...`), so the text, written to a file,
    is checked as a source of its own (equiv.py's standalone mode) and not as a one-block tree TU: the stand-in for
    the old per-function file where a tool checks or mutates "the function's source" (wine_link's binding map);
  * tu_text(path): a whole TU (declarations of a name are hoisted, so a TU is the unit a declaration lives in).

The tree root defaults to the checkout; a Wine build passes its materialized copy (build/tree). Block boundaries are
tree_tu.scan's: from the block line to the next block or placeholder line, trailing blank lines dropped.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import tree_tu  # noqa: E402

ROOT = tree_tu.ROOT
TOPS = ("game", "engine", os.path.join("platform", "xbox"))
_TU = {}            # abs path -> (mtime_ns, size, lines, [(addr int, kind, mode, lo, hi)], first block line or None)
_INDEX = {}         # root -> {addr int: (abs path, kind, mode, lo, hi)}


def _load(path):
    ap = os.path.abspath(path)
    st = os.stat(ap)
    hit = _TU.get(ap)
    if hit and hit[0] == st.st_mtime_ns and hit[1] == st.st_size:
        return hit
    lines = open(ap, errors="replace").read().splitlines()
    marks = []
    for i, l in enumerate(lines):
        m = tree_tu.BLOCK.match(l)
        if m:
            marks.append((i, m))
        elif tree_tu.PLACEHOLDER.match(l):
            marks.append((i, None))
    blocks = []
    for j, (i, m) in enumerate(marks):
        if m is None:
            continue
        end = marks[j + 1][0] if j + 1 < len(marks) else len(lines)
        while end > i + 1 and not lines[end - 1].strip():
            end -= 1
        blocks.append((int(m.group(1), 16), m.group(4), m.group(5) or "merged", i + 1, end))
    first = blocks[0][3] if blocks else None
    rec = (st.st_mtime_ns, st.st_size, lines, blocks, first)
    _TU[ap] = rec
    return rec


def tus(root=ROOT):
    """The tree TUs under ROOT/src/{game,engine,platform/xbox} (sorted paths)."""
    out = []
    for top in TOPS:
        for dp, dns, fns in os.walk(os.path.join(root, "src", top)):
            dns.sort()
            out += [os.path.join(dp, fn) for fn in sorted(fns) if fn.endswith(".cpp")]
    return out


def index(root=ROOT):
    """{address: (TU path, kind, mode, first line, last line)} over every block of the tree at ROOT (cached)."""
    r = os.path.abspath(root)
    if r not in _INDEX:
        idx = {}
        for p in tus(r):
            for a, kind, mode, lo, hi in _load(p)[3]:
                idx[a] = (p, kind, mode, lo, hi)
        _INDEX[r] = idx
    return _INDEX[r]


def find(addr, root=ROOT):
    """(TU path, kind) of the block at ADDR, or None."""
    hit = index(root).get(_int(addr))
    return (hit[0], hit[1]) if hit else None


def blocks(kinds=("matches", "equivalent"), root=ROOT):
    """[(address, TU path, kind)] of the blocks of these kinds, by address."""
    return sorted((a, v[0], v[1]) for a, v in index(root).items() if v[1] in kinds)


def _int(addr):
    return addr if isinstance(addr, int) else int(addr, 16)


def _block_in(path, addr):
    rec = _load(path)
    a = _int(addr)
    for b in rec[3]:
        if b[0] == a:
            return rec, b
    raise KeyError("%s has no block for 0x%08x" % (path, a))


def block_lines(addr, path=None, root=ROOT):
    """The lines of the block at ADDR (in the TU PATH if given, else found through the index); None if none."""
    try:
        if path is None:
            hit = index(root).get(_int(addr))
            if not hit:
                return None
            path = hit[0]
        rec, b = _block_in(path, addr)
    except (KeyError, OSError):
        return None
    return rec[2][b[3] - 1:b[4]]


def block_text(addr, path=None, root=ROOT):
    ls = block_lines(addr, path, root)
    return None if ls is None else "\n".join(ls) + "\n"


def unit_text(addr, path=None, root=ROOT):
    """The TU's shared part and the block at ADDR, as if it were the function's own source (tree_tu.unit_text)."""
    try:
        if path is None:
            hit = index(root).get(_int(addr))
            if not hit:
                return None
            path = hit[0]
        rec, b = _block_in(path, addr)
    except (KeyError, OSError):
        return None
    lines, first = rec[2], rec[4]
    keep = lines[:first - 1] + lines[b[3] - 1:b[4]]
    return "\n".join("" if tree_tu.NS_OPEN.match(l) or tree_tu.NS_CLOSE.match(l) else l for l in keep) + "\n"


def tu_text(path):
    return "\n".join(_load(path)[2]) + "\n"


def source_text(addr, path=None, root=ROOT):
    """unit_text with its block and placeholder lines neutralised: a stand-alone source of the function at ADDR."""
    t = unit_text(addr, path, root)
    if t is None:
        return None
    return "".join(("// (block) " + l[3:] if tree_tu.BLOCK.match(l) or tree_tu.PLACEHOLDER.match(l) else l) + "\n"
                   for l in t.rstrip("\n").split("\n"))
