#!/usr/bin/env python3
"""Pointer-width cleanup of matches/ and equivalent/ sources (docs/wine-build.md "64-bit").

  build/venv/bin/python tools/ptr1.py scan FILE...        # pointer-width diagnostics per source, with what would fix them
  build/venv/bin/python tools/ptr1.py fix [--write] FILE...   # apply the fixes (to the files with --write), iterating
  build/venv/bin/python tools/ptr1.py proof FILE...       # MSVC 7.1 objects of HEAD vs the working copy: identical or not

Finds, with libclang (pip package `clang` + Homebrew LLVM) on the msvc64 target, the places a pointer sits in a
32-bit integer: `(int)p`, `(T*)i` and the implicit 64 -> 32-bit truncations (`int n = p - q;`), and rewrites the
declared types to the pointer-sized typedefs of include/compat/ptr.h (hulk_intptr / hulk_uintptr / hulk_longptr /
hulk_ulongptr, which ARE `int` / `unsigned int` / `long` / `unsigned long` on the 32-bit builds, so MSVC 7.1 emits
the same object). What it edits:

  * the type of a pointer -> integer cast;
  * a local variable (or array) that receives such a value or feeds an integer -> pointer cast;
  * the pointee type of a `*(int*)(base + off)` / `((uint*)p)[i]` access that stores or loads a pointer.

Parameters, return types, fields, globals and other functions' declarations are not touched (their text is shared
with other sources; the tree generator merges declarations by text): they are reported as `unresolved` with the
reason. A file that changes gets `#include "compat/ptr.h"` after its leading comment block.
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys
import tempfile

import clang.cindex as ci

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ci.Config.set_library_file(os.environ.get("HULK_LIBCLANG") or os.path.join(os.path.dirname(__import__("clang_probe").LLVM), "lib/libclang.dylib"))
CK, TK = ci.CursorKind, ci.TypeKind
WARNS = ("-Wpointer-to-int-cast", "-Wint-to-pointer-cast", "-Wvoid-pointer-to-int-cast", "-Wint-to-void-pointer-cast",
         "-Wshorten-64-to-32")
P2I = ("-Wpointer-to-int-cast", "-Wvoid-pointer-to-int-cast")
I2P = ("-Wint-to-pointer-cast", "-Wint-to-void-pointer-cast")
INCLUDE_LINE = b'#include "compat/ptr.h"\n'


def args(target):
    return ["--target=" + target, "-x", "c++", "-fms-extensions", "-fms-compatibility", "-fms-compatibility-version=13.10",
            "-std=c++14", "-I" + os.path.join(ROOT, "include"), "-include", "compat/native.h", "-fno-strict-aliasing",
            "-fwrapv", "-Xclang", "-fno-wchar", "-Xclang", "-fno-operator-names", "-Wno-c++11-narrowing",
            "-Wno-address-of-temporary", "-Wno-everything", "-Wshorten-64-to-32", "-Wpointer-to-int-cast",
            "-Wint-to-pointer-cast", "-Wvoid-pointer-to-int-cast", "-Wint-to-void-pointer-cast", "-fsyntax-only"]


INT_OF = {TK.INT: "int", TK.UINT: "unsigned int", TK.LONG: "long", TK.ULONG: "unsigned long"}
HULK = {"int": "hulk_intptr", "unsigned int": "hulk_uintptr", "long": "hulk_longptr", "unsigned long": "hulk_ulongptr"}
INT_KW = {"unsigned", "signed", "int", "long"}
QUAL_KW = {"const", "volatile", "static", "register"}
CASTS = (CK.CSTYLE_CAST_EXPR, CK.CXX_FUNCTIONAL_CAST_EXPR, CK.CXX_REINTERPRET_CAST_EXPR, CK.CXX_STATIC_CAST_EXPR)
FUNCS = (CK.FUNCTION_DECL, CK.CXX_METHOD, CK.CONSTRUCTOR, CK.DESTRUCTOR, CK.CONVERSION_FUNCTION,
         CK.FUNCTION_TEMPLATE)


def int_kind(t):
    return INT_OF.get(t.get_canonical().kind)


def elem_int(t):
    """The integer type an object of type t holds (the element type of an array), or None."""
    c = t.get_canonical()
    while c.kind in (TK.CONSTANTARRAY, TK.INCOMPLETEARRAY, TK.VARIABLEARRAY):
        c = c.element_type.get_canonical()
    return INT_OF.get(c.kind)


class Node:
    __slots__ = ("cur", "kind", "parent", "kids", "s", "e", "idx")

    def __init__(self, cur, parent):
        self.cur, self.kind, self.parent, self.kids = cur, cur.kind, parent, []
        self.s, self.e = cur.extent.start.offset, cur.extent.end.offset


class Unit:
    """One parse: the main file's AST as Nodes, tokens by offset."""

    def __init__(self, path, src, target="x86_64-pc-windows-msvc", idx=None):
        self.path, self.src = path, src
        idx = idx or ci.Index.create()
        self.tu = idx.parse(path, args=args(target), unsaved_files=[(path, src)])
        self.lines = [0]
        for m in re.finditer(rb"\n", src):
            self.lines.append(m.end())
        self.diags = []
        self.errors = sum(1 for d in self.tu.diagnostics if d.severity >= 3)
        for d in self.tu.diagnostics:
            if d.option in WARNS and d.location.file and d.location.file.name == path:
                self.diags.append((d.location.offset, d.location.line, d.location.column, d.option, d.spelling))
        self.root = Node(self.tu.cursor, None)
        self.by_start = collections.defaultdict(list)
        self.decls = collections.defaultdict(list)    # start offset -> declarator Nodes sharing that specifier
        self.nodes = []
        stack = [self.root]
        while stack:
            n = stack.pop()
            kids = []
            for c in n.cur.get_children():
                if n is self.root and not (c.location.file and c.location.file.name == path):
                    continue
                k = Node(c, n)
                kids.append(k)
            n.kids = kids
            for k in kids:
                k.idx = len(self.nodes)
                self.nodes.append(k)
                self.by_start[k.s].append(k)
                if k.kind in (CK.VAR_DECL, CK.FIELD_DECL):
                    self.decls[k.s].append(k)
                stack.append(k)
        self._toks = None
        self.dem = set()          # signature demands: ("param", key, i) / ("ret", key) / ("field", class, name, "L"|"H")
        self._keys = None

    def keys(self):
        """{(cursor kind value, location offset): i686 mangled name} of the functions of the main file."""
        if self._keys is None:
            u32 = Unit(self.path, self.src, "i686-pc-windows-msvc")
            self._keys = {}
            for n in u32.nodes:
                if n.kind in FUNCS:
                    self._keys[(n.kind.value, n.cur.location.offset)] = n.cur.mangled_name
        return self._keys

    def fnkey(self, cur):
        if cur is None or not cur.location.file or cur.location.file.name != self.path:
            return None
        return self.keys().get((cur.kind.value, cur.location.offset))

    def off(self, line, col):
        return self.lines[line - 1] + col - 1

    def tokens(self, n):
        return list(n.cur.get_tokens())

    def text(self, a, b):
        return self.src[a:b]


# ---- tree helpers ----------------------------------------------------------------------------------
def strip(n):
    """Through parentheses and implicit-conversion wrappers."""
    while n.kind in (CK.PAREN_EXPR, CK.UNEXPOSED_EXPR) and len(n.kids) == 1:
        n = n.kids[0]
    return n


def binop(u, n):
    """The operator token text of a binary operator node, and its offset."""
    if len(n.kids) != 2:
        return None, None
    for t in n.cur.get_tokens():
        o = t.extent.start.offset
        if o >= n.kids[0].e and o < n.kids[1].s and t.kind == ci.TokenKind.PUNCTUATION and t.spelling not in "()":
            return t.spelling, o
    return None, None


def is_expr(n):
    return n.kind.is_expression()


def cast_type_tokens(u, n):
    """(token list, index range [a, b)) of the type spelled in a cast node, or None."""
    toks = u.tokens(n)
    if n.kind == CK.CSTYLE_CAST_EXPR and toks and toks[0].spelling == "(":
        depth = 0
        for i, t in enumerate(toks):
            if t.spelling == "(":
                depth += 1
            elif t.spelling == ")":
                depth -= 1
                if depth == 0:
                    return toks, 1, i
        return None
    if n.kind in (CK.CXX_REINTERPRET_CAST_EXPR, CK.CXX_STATIC_CAST_EXPR):
        a = next((i for i, t in enumerate(toks) if t.spelling == "<"), None)
        if a is None:
            return None
        depth = 0
        for i in range(a, len(toks)):
            if toks[i].spelling == "<":
                depth += 1
            elif toks[i].spelling == ">":
                depth -= 1
                if depth == 0:
                    return toks, a + 1, i
        return None
    if n.kind == CK.CXX_FUNCTIONAL_CAST_EXPR:
        for i, t in enumerate(toks):
            if t.spelling == "(":
                return toks, 0, i
    return None


def int_run(toks, a, b, want):
    """Token span [i, j) of the integer type in toks[a:b] (keywords, or one typedef name); qualifiers and a
    trailing '*' stay. want: canonical integer type name the span has to denote."""
    kw = [i for i in range(a, b) if toks[i].kind == ci.TokenKind.KEYWORD and toks[i].spelling in INT_KW]
    if kw:
        i, j = kw[0], kw[-1] + 1
        if j - i != len(kw):
            return None
        return i, j
    ids = [i for i in range(a, b) if toks[i].kind == ci.TokenKind.IDENTIFIER]
    if len(ids) == 1:
        return ids[0], ids[0] + 1
    return None


def edit_span(toks, i, j, want):
    return (toks[i].extent.start.offset, toks[j - 1].extent.end.offset, HULK[want])


# ---- sinks: where a pointer-carrying integer lives ---------------------------------------------------
def local_scope(n):
    p = n.cur.semantic_parent
    return p is not None and p.kind in FUNCS


def spec_edit(d, toks=None):
    """Edit of the integer type specifier of a variable / field / parameter declaration node, or a reason."""
    c = d.cur
    want = int_kind(c.type)
    toks = toks if toks is not None else list(c.get_tokens())
    a = 0
    while a < len(toks) and toks[a].spelling in QUAL_KW:
        a += 1
    b = a
    while b < len(toks) and (toks[b].kind == ci.TokenKind.KEYWORD and toks[b].spelling in INT_KW):
        b += 1
    if b == a:
        if a < len(toks) and toks[a].kind == ci.TokenKind.IDENTIFIER and toks[a].spelling != c.spelling:
            b = a + 1
        else:
            return None, "decl-spelling"
    if toks[a].spelling.startswith("hulk_"):
        return None, "done"
    return edit_span(toks, a, b, want), None


def qual_name(cur):
    parts = []
    p = cur
    while p is not None and p.kind != CK.TRANSLATION_UNIT:
        if p.kind in (CK.STRUCT_DECL, CK.CLASS_DECL, CK.NAMESPACE, CK.UNION_DECL):
            if not p.spelling:
                return None
            parts.append(p.spelling)
        elif p.kind in FUNCS:
            return None
        p = p.semantic_parent
    return "::".join(reversed(parts))


def demand_param(u, pcur):
    f = pcur.semantic_parent
    if f is None or f.kind not in FUNCS:
        return
    key = u.fnkey(f)
    if key is None:
        return
    for i, a in enumerate(f.get_arguments()):
        if a == pcur:
            u.dem.add(("param", key, i))
            return


def demand_field(u, fcur):
    cls = qual_name(fcur.semantic_parent)
    if not cls:
        return
    local = fcur.location.file and fcur.location.file.name == u.path
    u.dem.add(("field", cls, fcur.spelling, "L" if local else "H"))


def decl_edit(u, d):
    """(edit, reason): widen the declared type of a variable declaration node."""
    c = d.cur
    want = int_kind(c.type)
    if not want:
        # (an array of integers keeps its element size: its indexing and byte offsets are the layout)
        return None, "decl-not-int:%s" % c.type.spelling
    if d.kind == CK.PARM_DECL:
        demand_param(u, c)
        return None, "param"
    if d.kind == CK.FIELD_DECL:
        demand_field(u, c)
        return None, "field"
    if d.kind != CK.VAR_DECL:
        return None, "decl-kind:%s" % d.kind.name
    if not local_scope(d):
        return None, "global"
    sib = u.decls.get(d.s, [d])
    for o in sib:
        if int_kind(o.cur.type) != want or o.kind != CK.VAR_DECL:
            return None, "mixed-declarators"
    return spec_edit(d, u.tokens(d))


def cast_edit(u, n, pointee=False):
    """Edit the integer type spelled in a cast (or, pointee, the integer a cast-to-pointer points at)."""
    tt = cast_type_tokens(u, n)
    if not tt:
        return None, "cast-spelling"
    toks, a, b = tt
    t = n.cur.type
    if pointee:
        t = t.get_pointee()
        stars = [i for i in range(a, b) if toks[i].spelling == "*"]
        if len(stars) != 1:
            return None, "cast-pointee-spelling"
        b = stars[0]
    want = int_kind(t)
    if not want:
        return None, "cast-not-int:%s" % t.spelling
    r = int_run(toks, a, b, want)
    if not r:
        return None, "cast-spelling"
    return edit_span(toks, r[0], r[1], want), None


def sink_edit(u, n):
    """Resolve an lvalue / value node that has to be pointer-wide into an edit, or a reason."""
    n = strip(n)
    k = n.kind
    if k == CK.DECL_REF_EXPR:
        r = n.cur.referenced
        if r is None:
            return None, "unresolved-ref"
        for d in u.decls.get(r.extent.start.offset, []):
            if d.cur == r or (d.s, d.e) == (r.extent.start.offset, r.extent.end.offset) and d.cur.spelling == r.spelling:
                return decl_edit(u, d)
        if r.kind == CK.PARM_DECL:
            if int_kind(r.type):
                demand_param(u, r)
            return None, "param"
        if r.kind == CK.VAR_DECL:
            return None, "global"
        return None, "ref:%s" % r.kind.name
    if k == CK.MEMBER_REF_EXPR:
        r = n.cur.referenced
        if r is not None and r.kind == CK.FIELD_DECL and int_kind(r.type):
            demand_field(u, r)
        return None, "field"
    if k == CK.UNARY_OPERATOR:
        first = next(iter(n.cur.get_tokens()), None)
        if first is not None and first.spelling == "*" and len(n.kids) == 1:
            return deref_edit(u, n.kids[0])
        return None, "unary"
    if k == CK.ARRAY_SUBSCRIPT_EXPR and n.kids:
        base = strip(n.kids[0])
        if base.kind in CASTS:
            return deref_edit(u, base)
        if base.kind == CK.DECL_REF_EXPR:
            r = base.cur.referenced
            if r is not None and r.type.get_canonical().kind in (TK.CONSTANTARRAY, TK.INCOMPLETEARRAY):
                return sink_edit(u, base)
            return None, "indexed-pointer-var"
        return None, "subscript"
    return None, "lvalue:%s" % k.name


def has_local_array(n):
    """Does the expression read a local array (a stack image addressed by byte offsets)?"""
    stack = [n]
    while stack:
        x = stack.pop()
        if x.kind == CK.DECL_REF_EXPR:
            r = x.cur.referenced
            if r is not None and r.kind == CK.VAR_DECL and r.type.get_canonical().kind in (
                    TK.CONSTANTARRAY, TK.INCOMPLETEARRAY) and r.semantic_parent.kind in FUNCS:
                return True
        stack += x.kids
    return False


def deref_edit(u, base):
    base = strip(base)
    if base.kind in CASTS and has_local_array(base):
        return None, "deref-of-local-array"
    if base.kind in CASTS and base.cur.type.get_canonical().kind == TK.POINTER and \
            int_kind(base.cur.type.get_pointee()):
        return cast_edit(u, base, pointee=True)
    return None, "deref-of:%s" % base.kind.name


def leaves(u, n, out, depth=0):
    """Integer-valued origins that feed an expression: (kind, node) pairs appended to out."""
    n = strip(n)
    k = n.kind
    if depth > 40:
        return
    if k == CK.BINARY_OPERATOR:
        op, _ = binop(u, n)
        if op in ("+", "-", "*", "/", "%", "&", "|", "^", "<<", ">>") and len(n.kids) == 2:
            leaves(u, n.kids[0], out, depth + 1)
            if op not in ("<<", ">>"):
                leaves(u, n.kids[1], out, depth + 1)
            return
        out.append(("expr:%s" % op, n))
        return
    if k == CK.CONDITIONAL_OPERATOR and len(n.kids) == 3:
        leaves(u, n.kids[1], out, depth + 1)
        leaves(u, n.kids[2], out, depth + 1)
        return
    if k == CK.UNARY_OPERATOR:
        first = next(iter(n.cur.get_tokens()), None)
        if first is not None and first.spelling in ("-", "~", "+") and len(n.kids) == 1:
            leaves(u, n.kids[0], out, depth + 1)
            return
        out.append(("lvalue", n))
        return
    if k in CASTS and n.kids:
        if int_kind(n.cur.type):
            out.append(("intcast", n))      # (int)x: the cast's target type is what has to be pointer-wide
            return
        out.append(("cast-other", n))
        return
    if k in (CK.INTEGER_LITERAL, CK.CHARACTER_LITERAL, CK.CXX_BOOL_LITERAL_EXPR):
        out.append(("const", n))
        return
    if k in (CK.DECL_REF_EXPR, CK.MEMBER_REF_EXPR, CK.ARRAY_SUBSCRIPT_EXPR):
        out.append(("lvalue", n))
        return
    if k == CK.CALL_EXPR:
        out.append(("call", n))
        return
    out.append(("other:%s" % k.name, n))


def leaf_edit(u, kind, n):
    if kind == "lvalue":
        return sink_edit(u, n)
    if kind == "intcast":
        e, why = cast_edit(u, n)
        if e is None:
            return None, why
        # the cast's own operand is a narrower value; widening the cast target is all there is to do
        return e, None
    if kind == "const":
        return None, "constant"
    if kind == "call":
        ref = n.cur.referenced
        key = u.fnkey(ref) if ref is not None and ref.kind in FUNCS and int_kind(ref.result_type) else None
        if key:
            u.dem.add(("ret", key))
        return None, "call-return:%s" % (ref.spelling if ref is not None else "?")
    return None, kind


# ---- diagnostics -> edits ----------------------------------------------------------------------------
def find_cast(u, off):
    for n in u.by_start.get(off, []):
        if n.kind in CASTS:
            return n
    return None


def exprloc(u, n):
    if n.kind in (CK.BINARY_OPERATOR, CK.COMPOUND_ASSIGNMENT_OPERATOR):
        return binop(u, n)[1]
    if n.kind == CK.CONDITIONAL_OPERATOR and len(n.kids) == 3:
        for t in n.cur.get_tokens():
            if t.spelling == "?" and t.extent.start.offset >= n.kids[0].e:
                return t.extent.start.offset
    if n.kind == CK.MEMBER_REF_EXPR:
        return n.cur.location.offset
    return n.s


def find_converted(u, off):
    """The outermost expression node whose expression location is off."""
    best = None
    for i in range(len(u.nodes)):
        n = u.nodes[i]
        if n.kind in (CK.PAREN_EXPR, CK.UNEXPOSED_EXPR) or not is_expr(n):
            continue
        if n.s > off or n.e <= off:
            continue
        if exprloc(u, n) == off and (best is None or n.idx < best.idx):
            best = n
    return best


def shorten_edit(u, off):
    E = find_converted(u, off)
    if E is None:
        return None, "no-node"
    P = E.parent
    while P is not None and P.kind in (CK.PAREN_EXPR, CK.UNEXPOSED_EXPR):
        E, P = P, P.parent
    if P is None:
        return None, "no-parent"
    if P.kind == CK.VAR_DECL:
        return decl_edit(u, P)
    if P.kind in (CK.BINARY_OPERATOR, CK.COMPOUND_ASSIGNMENT_OPERATOR) and len(P.kids) == 2 and P.kids[1] is E:
        op, _ = binop(u, P)
        if op and op.endswith("=") and op not in ("==", "!=", "<=", ">="):
            return sink_edit(u, P.kids[0])
    if P.kind == CK.CALL_EXPR:
        ref = P.cur.referenced
        if ref is not None and ref.kind in FUNCS and P.kids and E is not P.kids[0]:
            args = list(ref.get_arguments())
            i = P.kids.index(E) - 1 if E in P.kids else -1
            if 0 <= i < len(args) and len(P.kids) - 1 == len(args) and int_kind(args[i].type):
                key = u.fnkey(ref)
                if key:
                    u.dem.add(("param", key, i))
        return None, "arg-of:%s" % (ref.spelling if ref is not None else "?")
    if P.kind == CK.RETURN_STMT:
        f = P.parent
        while f is not None and f.kind not in FUNCS:
            f = f.parent
        if f is not None and int_kind(f.cur.result_type):
            key = u.fnkey(f.cur)
            if key:
                u.dem.add(("ret", key))
        return None, "return"
    return None, "context:%s" % P.kind.name


def plan(u):
    """(edits, unresolved list [(line, col, option, reason)]) for one parse."""
    edits, un = {}, []
    base = set()
    for off, line, col, opt, msg in u.diags:
        if opt == "-Wshorten-64-to-32" and (line, msg) in u.baseline:
            continue
        reasons = []
        es = []
        if opt in P2I:
            n = find_cast(u, off)
            if n is None:
                reasons.append("no-cast-node")
            else:
                e, why = cast_edit(u, n)
                es.append(e) if e else reasons.append(why)
        elif opt in I2P:
            n = find_cast(u, off)
            if n is None or not n.kids:
                reasons.append("no-cast-node")
            else:
                ls = []
                leaves(u, n.kids[-1], ls)
                for kind, ln in ls:
                    e, why = leaf_edit(u, kind, ln)
                    es.append(e) if e else reasons.append(why)
        else:
            e, why = shorten_edit(u, off)
            es.append(e) if e else reasons.append(why)
        for e in es:
            edits[(e[0], e[1])] = e
        # a site is resolved when it has an edit and nothing it needs is unresolved
        if reasons:
            un.append((line, col, opt, ",".join(sorted(set(reasons)))))
    return sorted(edits.values()), un


def baseline_for(path, src):
    """(line, col) of the narrowing warnings i686 has too (an `__int64` narrowed on purpose)."""
    tu = ci.Index.create().parse(path, args=args("i686-pc-windows-msvc"), unsaved_files=[(path, src)])
    return {(d.location.line, d.spelling) for d in tu.diagnostics
            if d.option == "-Wshorten-64-to-32" and d.location.file and d.location.file.name == path}


def apply(src, edits):
    out = src
    for a, b, t in sorted(edits, reverse=True):
        out = out[:a] + t.encode() + out[b:]
    return out


def add_include(src):
    if b"compat/ptr.h" in src:
        return src
    lines = src.split(b"\n")
    i = 0
    while i < len(lines) and (lines[i].startswith(b"//") or not lines[i].strip()) and i < len(lines) - 1:
        i += 1
    # after the leading comment block (blank lines before code stay with the code)
    j = i
    while j > 0 and not lines[j - 1].strip():
        j -= 1
    return b"\n".join(lines[:j] + [INCLUDE_LINE.rstrip(b"\n")] + lines[j:])


def errors_of(path, src, target):
    tu = ci.Index.create().parse(path, args=args(target), unsaved_files=[(path, src)])
    return sum(1 for d in tu.diagnostics if d.severity >= 3)


def fix_file(path, rounds=12):
    """(new source or None, remaining unresolved, rounds used)."""
    path = os.path.abspath(path)
    orig = open(path, "rb").read()
    src = add_include(orig)       # parsed with the include (stable line numbers); dropped again if nothing changes
    base = baseline_for(path, src)
    errs64 = Unit(path, src).errors
    errs32 = errors_of(path, src, "i686-pc-windows-msvc")
    used = 0
    for used in range(1, rounds + 1):
        cur = src
        u = Unit(path, cur)
        u.baseline = base
        edits, un = plan(u)
        if not edits:
            break
        src = apply(cur, edits)
        if src == cur:
            break
    final = src if src != add_include(orig) else orig
    u = Unit(path, final)
    u.baseline = base
    _, un = plan(u)
    if final != orig and (u.errors > errs64 or errors_of(path, final, "i686-pc-windows-msvc") > errs32):
        return None, [(0, 0, "", "regressed:clang-errors")], used, []     # a rewrite that breaks a clang parse is dropped
    dem = sorted(u.dem) if un else []
    return (final if final != orig else None), un, used, dem


def scan_file(path):
    path = os.path.abspath(path)
    src = add_include(open(path, "rb").read())
    u = Unit(path, src)
    u.baseline = baseline_for(path, src)
    edits, un = plan(u)
    n = sum(1 for d in u.diags if not (d[3] == "-Wshorten-64-to-32" and (d[1], d[4]) in u.baseline))
    return n, len(edits), un


# ---- signatures: parameters, returns and fields that other sources' casts and arguments demand ----------
FN_SPEC = {"static", "virtual", "inline", "extern", "__forceinline", "__inline", "const", "volatile"}
FN_KINDS = (CK.FUNCTION_DECL, CK.CXX_METHOD)


def ret_edit(n):
    """Edit of the integer return type spelled in a function declaration node, or None."""
    want = int_kind(n.cur.result_type)
    if not want:
        return None
    toks = list(n.cur.get_tokens())
    a = 0
    while a < len(toks):
        t = toks[a]
        if t.spelling in FN_SPEC or (t.kind == ci.TokenKind.LITERAL and t.spelling.startswith('"')):
            a += 1
        elif t.spelling == "__declspec" and a + 1 < len(toks) and toks[a + 1].spelling == "(":
            depth = 0
            a += 1
            while a < len(toks):
                depth += toks[a].spelling == "("
                depth -= toks[a].spelling == ")"
                a += 1
                if depth == 0:
                    break
        else:
            break
    b = a
    while b < len(toks) and toks[b].kind == ci.TokenKind.KEYWORD and toks[b].spelling in INT_KW:
        b += 1
    if b == a:
        if a + 1 < len(toks) and toks[a].kind == ci.TokenKind.IDENTIFIER and toks[a + 1].spelling != "::" and \
                toks[a + 1].spelling != "(":
            b = a + 1
        else:
            return None
    if toks[a].spelling.startswith("hulk_"):
        return None
    return edit_span(toks, a, b, want)


def sig_edits(u, D, blocked):
    """Edits that satisfy the demands D in one parse (i686: the keys are its mangled names). Returns
    (edits, keys declared here, virtual keys here, {qualified name: keys})."""
    edits, keys, virt, names = {}, set(), set(), collections.defaultdict(set)
    for n in u.nodes:
        if n.kind in FN_KINDS:
            key = n.cur.mangled_name
            keys.add(key)
            names["%s::%s" % (qual_name(n.cur.semantic_parent) or "", n.cur.spelling)].add(key)
            if n.cur.is_virtual_method():
                virt.add(key)
                continue
            if key in blocked:
                continue
            params = [k for k in n.kids if k.kind == CK.PARM_DECL]
            for dm in D.get(key, ()):
                if dm[0] == "param" and dm[2] < len(params):
                    pn = params[dm[2]]
                    if int_kind(pn.cur.type):
                        e, _ = spec_edit(pn)
                        if e:
                            edits[(e[0], e[1])] = e
                elif dm[0] == "ret":
                    e = ret_edit(n)
                    if e:
                        edits[(e[0], e[1])] = e
        elif n.kind == CK.FIELD_DECL:
            cls = qual_name(n.cur.semantic_parent)
            keys.add(("field", cls, n.cur.spelling))
            if cls and ("field", cls, n.cur.spelling) in D and ("field", cls, n.cur.spelling) not in blocked and \
                    int_kind(n.cur.type):
                sib = u.decls.get(n.s, [n])
                if all(o.kind == CK.FIELD_DECL and int_kind(o.cur.type) == int_kind(n.cur.type) for o in sib):
                    e, _ = spec_edit(n)
                    if e:
                        edits[(e[0], e[1])] = e
    return sorted(edits.values()), keys, virt, names


def parse_demands(rows):
    """{key: [demand rows]} from [["param", key, i] / ["ret", key] / ["field", class, name, "L"|"H"]]."""
    D = collections.defaultdict(list)
    for r in rows:
        if r[0] == "field":
            D[("field", r[1], r[2])].append(tuple(r))
        else:
            D[r[1]].append(tuple(r))
    return D


_G = {}


def init_sigs(rows, blocked):
    _G["D"] = parse_demands(rows)
    _G["blocked"] = blocked


def sigs_file(path):
    D, blocked = _G["D"], _G["blocked"]
    try:
        orig = open(path, "rb").read()
        src = add_include(orig)
        u = Unit(path, src, "i686-pc-windows-msvc")
        edits, keys, virt, _names = sig_edits(u, D, blocked)
        if not edits:
            return path, None, sorted(virt, key=str), "", 0
        new = apply(src, edits)
        e0 = u.errors
        u64 = Unit(path, new)
        base64 = Unit(path, src).errors
        if errors_of(path, new, "i686-pc-windows-msvc") > e0 or u64.errors > base64:
            return path, None, sorted(virt, key=str), "regressed", len(edits)
        return path, new, sorted(virt, key=str), "", len(edits)
    except Exception as e:  # noqa: BLE001
        return path, None, [], repr(e), 0


def scan_keys(path):
    """(declared keys, virtual keys) of one source, read-only."""
    try:
        src = open(path, "rb").read()
        u = Unit(path, src, "i686-pc-windows-msvc")
        D = {}
        _, keys, virt, names = sig_edits(u, D, set())
        return path, sorted(keys, key=str), sorted(virt, key=str), {k: sorted(v) for k, v in names.items()}
    except Exception:  # noqa: BLE001
        return path, [], [], {}


def header_keys(path):
    """Function keys and (class, field) keys a header declares."""
    try:
        src = open(path, "rb").read()
        u = Unit(path, src, "i686-pc-windows-msvc")
        _, keys, virt, names = sig_edits(u, {}, set())
        return path, sorted(keys, key=str), sorted(virt, key=str), {k: sorted(v) for k, v in names.items()}
    except Exception:  # noqa: BLE001
        return path, [], [], {}


# ---- proof: the MSVC 7.1 object must not change ---------------------------------------------------
def obj_sig(src, tmp):
    """Everything an object holds that a source change could move: section bytes with their relocations
    (symbol names, not indexes), the symbol table (names = mangling), per section. None if it won't compile."""
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from compare import DEFAULT_FLAGS, CompileError, Coff, compile_obj
    try:
        coff = Coff(compile_obj(src, DEFAULT_FLAGS, tmp))
    except CompileError as e:
        return "compile error: %s" % e
    # the compiler numbers its local labels (`$L3434`, jump-table targets) from a counter every declaration moves
    # (a typedef is enough): they are named by what they point at instead
    def sym(t):
        if t[0].startswith("$L") and t[0][2:].isdigit():
            return ("$L@%d:%d" % (t[2], t[1]),) + tuple(t[1:])
        return t
    secs = []
    for name, raw, relocs in coff.sections:
        rl = sorted((va, sym(coff.by_index.get(si) or ("?",))[0], typ) for va, si, typ in relocs)
        secs.append((name, raw, rl))
    return sorted(secs), sorted(sym(t) for t in coff.symbols)


def proof_one(args_):
    path, orig_path = args_
    with tempfile.TemporaryDirectory() as tmp:
        name = os.path.basename(path)
        if orig_path:
            data = open(orig_path, "rb").read()
        else:
            r = subprocess.run(["git", "show", "HEAD:" + os.path.relpath(path, ROOT)], capture_output=True, cwd=ROOT)
            if r.returncode:
                return path, "not in HEAD"
            data = r.stdout
        # the same directory and name for both (the object's debug section holds the path)
        src = os.path.join(tmp, name)
        open(src, "wb").write(data)
        sa = obj_sig(src, tmp)
        open(src, "wb").write(open(path, "rb").read())
        sb = obj_sig(src, tmp)
    if isinstance(sa, str):
        return path, "orig does not compile" if isinstance(sb, str) else "orig does not compile (new does)"
    if isinstance(sb, str):
        return path, "NEW DOES NOT COMPILE: " + sb[:200]
    return path, "identical" if sa == sb else "DIFFERENT"


def tuple_key(k):
    return tuple(tuple_key(x) if isinstance(x, list) else x for x in k) if isinstance(k, (list, tuple)) else k


def worker_fix(path):
    try:
        new, un, rounds, dem = fix_file(path)
        return path, new, un, rounds, None, dem
    except Exception as e:  # noqa: BLE001
        return path, None, [], 0, repr(e), []


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["scan", "fix", "proof", "collect", "sigs"])
    ap.add_argument("--demands", help="sigs: JSON list of demand rows (the union of fix's per-file `demands`)")
    ap.add_argument("--blocked", help="sigs: JSON from `collect` (keys declared in headers, virtual keys)")
    ap.add_argument("--block-names", help="sigs: file of function names (as `Class::name`, or `::name`) whose "
                    "signatures stay as they are, one per line: the ones a 64-bit compile of the tree found ambiguous")
    ap.add_argument("--block-overloaded", action="store_true", help="sigs: leave every name with several signatures")
    ap.add_argument("--skip", help="sigs: @list of sources that are read but never edited; keys they declare stay as they are")
    ap.add_argument("--orig-dir", help="proof: compare against the same-named files of this directory (default: git HEAD)")
    ap.add_argument("files", nargs="+")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--out", help="write a JSON report (per file: changed, unresolved)")
    a = ap.parse_args()
    files = []
    for f in a.files:       # a directory means its *.cpp; @list reads one path per line
        if os.path.isdir(f):
            files += sorted(os.path.join(f, x) for x in os.listdir(f) if x.endswith(".cpp"))
        elif f.startswith("@"):
            files += [l.strip() for l in open(f[1:]) if l.strip()]
        else:
            files.append(f)
    a.files = files
    from multiprocessing import Pool
    rep = {}
    reasons = collections.Counter()
    if a.cmd == "proof":
        with Pool(a.jobs) as pool:
            jobs = [(os.path.abspath(f), os.path.join(a.orig_dir, os.path.basename(os.path.dirname(f)),
                                                     os.path.basename(f)) if a.orig_dir else None) for f in a.files]
            res = list(pool.imap(proof_one, jobs, chunksize=2))
        c = collections.Counter(r for _, r in res)
        for f, r in res:
            if r != "identical":
                print(" ", os.path.relpath(f, ROOT), r)
        print(dict(c))
        if a.out:
            json.dump(dict(res), open(a.out, "w"), indent=0)
        return
    if a.cmd == "collect":
        # keys the signature phase must leave alone: declared in headers (include/), virtual in any source
        hdrs = []
        for dp, _, fs in os.walk(os.path.join(ROOT, "include")):
            hdrs += [os.path.join(dp, f) for f in fs if f.endswith(".h")]
        out = {"header": set(), "virtual": set(), "overloaded": set()}
        groups = collections.defaultdict(set)
        with Pool(a.jobs) as pool:
            for _, keys, virt, names in pool.imap(header_keys, sorted(hdrs), chunksize=2):
                out["header"] |= set(map(tuple_key, keys))
                for g, ks in names.items():
                    groups[g] |= set(ks)
            for _, keys, virt, names in pool.imap(scan_keys, a.files, chunksize=8):
                out["virtual"] |= set(map(tuple_key, virt))
                for g, ks in names.items():
                    groups[g] |= set(ks)
        # a name declared with several signatures (overloads, or stubs that disagree about one function): widening
        # one of them leaves a call ambiguous on 64-bit (int vs a pointer-sized integer), so none of them is touched
        for g, ks in groups.items():
            if len(ks) > 1:
                out["overloaded"] |= set(ks)
        res = {k: sorted(v, key=str) for k, v in out.items()}
        res["groups"] = {g: sorted(ks) for g, ks in groups.items() if len(ks) > 1}      # name -> its several signatures
        json.dump(res, open(a.out, "w"))
        print({k: len(v) for k, v in out.items()})
        return
    if a.cmd == "sigs":
        rows = json.load(open(a.demands))
        bl = json.load(open(a.blocked))
        blocked = set(map(tuple_key, bl["header"])) | set(map(tuple_key, bl["virtual"]))
        if a.block_overloaded:
            blocked |= set(map(tuple_key, bl.get("overloaded", [])))
        if a.block_names:
            for nm in (l.strip() for l in open(a.block_names)):
                if nm:
                    for g in (nm, "::" + nm):
                        blocked |= set(bl.get("groups", {}).get(g, []))
        if a.skip:
            with Pool(a.jobs) as pool:
                skipf = [l.strip() for l in open(a.skip[1:]) if l.strip()]
                for _, keys, _v, _n in pool.imap(scan_keys, skipf, chunksize=8):
                    blocked |= set(map(tuple_key, keys))
        rows = [r for r in rows if (tuple(r[:3]) if r[0] == "field" else r[1]) not in blocked]
        wanted = {tuple(r[:3]) if r[0] == "field" else r[1] for r in rows}
        with Pool(a.jobs, initializer=init_sigs, initargs=(rows, blocked)) as pool:
            n_edits = changed = regressed = 0
            for f, new, virt, err, ne in pool.imap(sigs_file, a.files, chunksize=4):
                if err == "regressed":
                    regressed += 1
                    print("regressed", f)
                elif err:
                    print("error", f, err)
                if new is not None:
                    changed += 1
                    n_edits += ne
                    if a.write:
                        open(f, "wb").write(new)
        print(json.dumps({"files_changed": changed, "edits": n_edits, "regressed": regressed,
                          "demanded_keys": len(wanted), "blocked_keys": len(blocked)}))
        return
    with Pool(a.jobs) as pool:
        if a.cmd == "scan":
            for f, r in zip(a.files, pool.imap(scan_file, a.files, chunksize=8)):
                rep[f] = r
        else:
            for f, new, un, rounds, err, dem in pool.imap(worker_fix, a.files, chunksize=4):
                rep[f] = {"changed": new is not None, "unresolved": un, "rounds": rounds, "error": err, "demands": dem}
                if new is not None and a.write:
                    open(f, "wb").write(new)
    for f, r in rep.items():
        un = r[2] if a.cmd == "scan" else r["unresolved"]
        for _, _, opt, why in un:
            reasons[re.sub(r":.*", "", why.split(",")[0])] += 1
    print(json.dumps(reasons.most_common(40)))
    if a.out:
        json.dump(rep, open(a.out, "w"), indent=0)


if __name__ == "__main__":
    main()
