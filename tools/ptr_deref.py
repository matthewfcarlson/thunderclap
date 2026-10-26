#!/usr/bin/env python3
"""Pointers stored or loaded through `int*` / `unsigned*` variables (x64-5; docs/native-mac.md section 11).

  build/venv/bin/python tools/ptr_deref.py fix FILE... [--write] [--out REPORT.json]

What ptr1 leaves as `deref-of`: a pointer-sized value stored through, or a pointer read from, a 4-byte integer
pointer that a variable or member holds (`int* p = (int*)this; *p = (hulk_intptr)&g_vt_1888c0;`, `if (*p &&
((Ref*)*p)->state)`, `*mTail = (hulk_intptr)node;`). The variable's type can't simply widen (its other accesses,
`p[1]`, `p + 2`, address 4-byte words of the 32-bit layout), so the one access widens: `*p` becomes
`*(hulk_intptr*)p` (`hulk_uintptr` for an unsigned pointee), a pointer-sized access at the same address. On the
32-bit builds `hulk_intptr*` is `int*`: MSVC 7.1's object is unchanged. Only a `*` applied directly to a variable or a
member; `*++p`, `p[i]` and arithmetic are left (their offsets are the 32-bit layout's: the consolidation's).

A file is written only when its clang errors (both targets) don't grow and it has fewer pointer-width diagnostics
than before; `#include "compat/ptr.h"` is added as ptr1 does.
"""
import argparse
import concurrent.futures
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ptr1  # noqa: E402

ci, CK, TK = ptr1.ci, ptr1.CK, ptr1.TK
INT4 = {TK.INT: "hulk_intptr", TK.LONG: "hulk_intptr", TK.UINT: "hulk_uintptr", TK.ULONG: "hulk_uintptr"}


def deref_target(n):
    """`*X` with X a variable or member of type pointer-to-4-byte-integer: (star node, X node, replacement type)."""
    while n is not None and n.kind in (CK.PAREN_EXPR, CK.UNEXPOSED_EXPR):
        n = n.kids[0] if len(n.kids) == 1 else None
    if n is None or n.kind != CK.UNARY_OPERATOR or len(n.kids) != 1:
        return None
    t = ptr1.first_tok(n) if hasattr(ptr1, "first_tok") else next(iter(n.cur.get_tokens()), None)
    if t is None or t.spelling != "*" or t.extent.start.offset != n.s:
        return None
    x = ptr1.strip(n.kids[0])
    if x.kind not in (CK.DECL_REF_EXPR, CK.MEMBER_REF_EXPR):
        return None
    pt = x.cur.type.get_canonical()
    if pt.kind != TK.POINTER:
        return None
    rep = INT4.get(pt.get_pointee().get_canonical().kind)
    if rep is None:
        return None
    return n, x, rep


def sites(u):
    """{star node offset: (insert offset, text)} for the pointer-width diagnostics of a parse."""
    edits = {}
    for off, line, col, opt, msg in u.diags:
        cand = []
        if opt in ptr1.I2P:
            c = ptr1.find_cast(u, off)
            if c is not None and c.kids:
                cand.append(c.kids[-1])
        elif opt == "-Wshorten-64-to-32":
            e = ptr1.find_converted(u, off)
            p = e.parent if e is not None else None
            while p is not None and p.kind in (CK.PAREN_EXPR, CK.UNEXPOSED_EXPR):
                e, p = p, p.parent
            if p is not None and p.kind in (CK.BINARY_OPERATOR, CK.COMPOUND_ASSIGNMENT_OPERATOR) and \
                    len(p.kids) == 2 and p.kids[1] is e:
                cand.append(p.kids[0])
        for c in cand:
            r = deref_target(c)
            if r:
                star, x, rep = r
                edits[star.s] = (x.s, "(%s*)" % rep)
    return edits


def fix_file(path, write):
    path = os.path.abspath(path)
    orig = open(path, "rb").read()
    src = ptr1.add_include(orig)
    u = ptr1.Unit(path, src)
    before = len(u.diags)
    edits = sites(u)
    if not edits:
        return os.path.relpath(path, ptr1.ROOT), 0, before, before, None
    new = src
    for _star, (at, text) in sorted(edits.items(), key=lambda kv: -kv[1][0]):
        new = new[:at] + text.encode() + new[at:]
    u2 = ptr1.Unit(path, new)
    e32a = ptr1.errors_of(path, src, "i686-pc-windows-msvc")
    e32b = ptr1.errors_of(path, new, "i686-pc-windows-msvc")
    if u2.errors > u.errors or e32b > e32a or len(u2.diags) >= before:
        return os.path.relpath(path, ptr1.ROOT), 0, before, len(u2.diags), "rejected"
    if write:
        open(path, "wb").write(new)
    return os.path.relpath(path, ptr1.ROOT), len(edits), before, len(u2.diags), None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["fix"])
    ap.add_argument("files", nargs="+")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--out")
    a = ap.parse_args()
    files = []
    for f in a.files:
        files += [x.strip() for x in open(f[1:]) if x.strip()] if f.startswith("@") else [f]
    res = {}
    with concurrent.futures.ProcessPoolExecutor(a.jobs) as ex:
        for rel, n, b, after, why in ex.map(fix_file, files, [a.write] * len(files), chunksize=8):
            res[rel] = {"edits": n, "diags_before": b, "diags_after": after, "why": why}
    changed = [k for k, v in res.items() if v["edits"]]
    print("%d files, %d changed (%d edits), diagnostics %d -> %d, %d rejected" % (
        len(res), len(changed), sum(v["edits"] for v in res.values()),
        sum(v["diags_before"] for v in res.values()),
        sum(v["diags_after"] if v["edits"] else v["diags_before"] for v in res.values()),
        sum(1 for v in res.values() if v["why"])))
    if a.out:
        json.dump(res, open(a.out, "w"), indent=1)


if __name__ == "__main__":
    sys.exit(main())
