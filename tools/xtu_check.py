#!/usr/bin/env python3
"""Cross-TU consistency checks the per-block 64-bit check can't see (integ2, D138; report-only).

census1 found that 15 of 16 native start-up stops were disagreements between two translation units: a caller declares
a callee otherwise than its definition (C vs C++ linkage, an argument count, a pointer passed as an int, a return
type), or allocates fewer bytes than the record the callee constructs there. Each TU is byte-matched or proven on
its own, so nothing per block notices. This pass reads every tree TU twice (libclang, i386 and x86-64, as
tools/equiv64.py parses it) and reports:

  (b) decl   a call whose declaration in the caller disagrees with the callee's definition: its native symbol
             (linkage / mangling), the argument count, an argument or the return as pointer vs integer or another
             native size, member vs free; `c_link_type` when the definition has C linkage (it binds by name with no
             type, so the disagreement links silently: find1's 0x00240760, 0x00267070 / 0x00266f90). The callee is found by its symbol (a block's pinned `// sym:`), else by the
             address its name carries (FUN_xxxxxxxx, Name_xxxxxxxx: the native link binds those by address).
  free_name  (D132, equivalent blocks: verify_relocs covers the byte-matched ones) a call whose callee reaches one of
             the game's frees under a name other than that free's own.
  (a) alloc  an allocator's result (tools/equiv64.py ALLOCATORS) passed as `this` or the first argument of a call
             to a defined member or function: the request's 64-bit size (clang folds sizeof and literals) against
             the 64-bit size of the record the callee works on (its class; for a free function, its first
             parameter's pointee). Flows: the same expression, one local, a field of `this` (`f = alloc(n);
             f->Init()`), and a function that returns an allocation (`T* Make() { return (T*)alloc(n); }`) whose
             result the caller passes on.

  build/venv/bin/python tools/xtu_check.py extract TU.cpp... --out DIR     # facts per TU (one queue job per group)
  build/venv/bin/python tools/xtu_check.py report DIR [--out build/xtu]     # rows: report.jsonl, summary.json
  build/venv/bin/python tools/xtu_check.py run [--jobq] [--prio -5]         # both, every tree TU

Coverage gaps are counted in summary.json (fatal TUs, block errors, calls without a 64-bit pair, unresolved calls,
allocations of a runtime size) and listed in gaps.jsonl; a report is `clean` only when they are all zero.
Known blind spots (rev5's review): only calls inside blocks with a pinned sym (not out-of-line helpers, header inline
functions, function pointers or virtual slots); 32/64-bit calls are paired by (line, column), so several calls of
one macro expansion with the same callee share the first one's 64-bit facts (calls are keyed by place and callee); a symbol two TUs define resolves to the first; allocation
flows don't follow globals, out-parameters or callees that return their argument; a row that differs only in the
symbol is not reported (the native link reports an unbound name itself, and an address-carrying name binds by
address, D35). Records are compared by size and AArch64 HFA-ness, not by type.

Nothing gates on it yet (rev5 reviews it before it does)."""
import argparse
import bisect
import contextlib
import ctypes
import glob
import json
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
FACTS_VER = "xtu3"     # (HFA records; calls paired by place and callee; unpinned blocks recorded)


# ------------------------------------------------------------------------------------------------ libclang helpers
_EV = []


def evaluate(c):
    """The integer value clang folds cursor C to (sizeof, literals, constant arithmetic), or None."""
    import equiv64
    m = equiv64.ci()
    lib = m.conf.lib
    if not _EV:
        lib.clang_Cursor_Evaluate.argtypes = [m.Cursor]
        lib.clang_Cursor_Evaluate.restype = ctypes.c_void_p
        lib.clang_EvalResult_getKind.argtypes = [ctypes.c_void_p]
        lib.clang_EvalResult_getKind.restype = ctypes.c_int
        lib.clang_EvalResult_isUnsignedInt.argtypes = [ctypes.c_void_p]
        lib.clang_EvalResult_isUnsignedInt.restype = ctypes.c_uint
        lib.clang_EvalResult_getAsUnsigned.argtypes = [ctypes.c_void_p]
        lib.clang_EvalResult_getAsUnsigned.restype = ctypes.c_ulonglong
        lib.clang_EvalResult_getAsLongLong.argtypes = [ctypes.c_void_p]
        lib.clang_EvalResult_getAsLongLong.restype = ctypes.c_longlong
        lib.clang_EvalResult_dispose.argtypes = [ctypes.c_void_p]
        _EV.append(1)
    r = lib.clang_Cursor_Evaluate(c)
    if not r:
        return None
    try:
        if lib.clang_EvalResult_getKind(r) != 1:      # CXEval_Int
            return None
        if lib.clang_EvalResult_isUnsignedInt(r):
            return int(lib.clang_EvalResult_getAsUnsigned(r))
        return int(lib.clang_EvalResult_getAsLongLong(r))
    finally:
        lib.clang_EvalResult_dispose(r)


def hfa(t, depth=0):
    """(rev5's R2) Is record type T a homogeneous float aggregate for AArch64 (1..4 members, all float or all double,
    through nested records and arrays)? Returns the element kind ("f4"/"f8") or None."""
    t = t.get_canonical()
    if depth > 8:
        return None
    k = t.kind.name
    if k in ("FLOAT", "DOUBLE"):
        return ("f%d" % t.get_size(), 1)
    if k == "CONSTANTARRAY":
        e = hfa(t.element_type, depth + 1)
        return (e[0], e[1] * t.element_count) if e else None
    if k != "RECORD":
        return None
    d = t.get_declaration()
    el, n = None, 0
    for c in d.get_children():
        if c.kind.name == "CXX_BASE_SPECIFIER":
            sub = hfa(c.type, depth + 1)
        elif c.kind.name == "FIELD_DECL":
            sub = hfa(c.type, depth + 1)
        else:
            continue
        if sub is None or (el is not None and sub[0] != el):
            return None
        el, n = sub[0], n + sub[1]
    return (el, n) if el and 1 <= n <= 4 else None


def kind_of(t):
    """(kind, native size, AArch64 HFA element or None) of type T: ptr / int / flt / rec / void / other."""
    t = t.get_canonical()
    k = t.kind.name
    try:
        sz = max(0, t.get_size())
    except Exception:   # noqa: BLE001
        sz = 0
    if k in ("POINTER", "LVALUEREFERENCE", "RVALUEREFERENCE", "MEMBERPOINTER", "BLOCKPOINTER", "NULLPTR"):
        return "ptr", sz
    if k == "VOID":
        return "void", 0
    if k in ("FLOAT", "DOUBLE", "LONGDOUBLE"):
        return "flt", sz
    if k == "RECORD":
        h = hfa(t)
        return "rec", sz, (h[0] + "x%d" % h[1]) if h else None
    if k == "ENUM" or k in ("BOOL", "CHAR_U", "UCHAR", "CHAR16", "CHAR32", "USHORT", "UINT", "ULONG", "ULONGLONG",
                            "UINT128", "CHAR_S", "SCHAR", "WCHAR", "SHORT", "INT", "LONG", "LONGLONG", "INT128"):
        return "int", sz
    return k.lower(), sz


def pointee_size(t):
    t = t.get_canonical()
    if t.kind.name not in ("POINTER", "LVALUEREFERENCE", "RVALUEREFERENCE"):
        return None
    p = t.get_pointee().get_canonical()
    if p.kind.name != "RECORD":
        return None
    try:
        s = p.get_size()
    except Exception:   # noqa: BLE001
        return None
    return s if s > 0 else None


def sig_of(c):
    """The facts of function declaration C: params, return, member, variadic, class size."""
    K = __import__("equiv64").ci().CursorKind
    t = c.type.get_canonical()
    params = [kind_of(a) for a in t.argument_types()] if t.kind.name == "FUNCTIONPROTO" else None
    has_this = c.kind in (K.CXX_METHOD, K.CONSTRUCTOR, K.DESTRUCTOR, K.CONVERSION_FUNCTION) and \
        not c.is_static_method()
    cls = None
    if has_this and c.semantic_parent is not None:
        try:
            s = c.semantic_parent.type.get_canonical().get_size()
            cls = [c.semantic_parent.type.get_canonical().spelling, s if s > 0 else None]
        except Exception:   # noqa: BLE001
            cls = None
    p0 = None
    if t.kind.name == "FUNCTIONPROTO":
        at = list(t.argument_types())
        if at:
            p0 = pointee_size(at[0])
    return {"params": params, "ret": kind_of(t.get_result()) if t.kind.name in ("FUNCTIONPROTO", "FUNCTIONNOPROTO")
            else None, "this": has_this, "variadic": bool(t.kind.name == "FUNCTIONPROTO" and t.is_function_variadic()),
            "cls": cls, "p0": p0, "kind": c.kind.name}


def mangled(c, bits):
    """C's symbol on BITS, without the tree's namespaces (fn_<addr>, fn_f<7 hex>: the native build's names)."""
    import equiv64
    try:
        mn = c.mangled_name
    except Exception:   # noqa: BLE001
        return None
    if mn and bits == 32 and not mn.startswith("?") and not mn.startswith("_") and not mn.startswith("@"):
        mn = "_" + mn
    return equiv64.TREE_NS.sub("", mn) if mn else mn


_PL = []


def where(c):
    """file:line of cursor C as the source says (the wrapper's `#line`: the TU or header, relative to the root)."""
    import equiv64
    m = equiv64.ci()
    try:
        lib = m.conf.lib
        if not _PL:
            lib.clang_getPresumedLocation.argtypes = [m.SourceLocation, ctypes.POINTER(m._CXString),
                                                      ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint)]
            lib.clang_getPresumedLocation.restype = None
            _PL.append(1)
        fn, ln, col = m._CXString(), ctypes.c_uint(), ctypes.c_uint()
        lib.clang_getPresumedLocation(c.location, ctypes.byref(fn), ctypes.byref(ln), ctypes.byref(col))
        f = m._CXString.from_result(fn)
        if f and os.path.isabs(f) and f.startswith(ROOT):
            f = os.path.relpath(f, ROOT)
        return "%s:%d" % (f or "?", ln.value)
    except Exception:   # noqa: BLE001
        try:
            return "%s:%d" % (os.path.basename(c.location.file.name), c.location.line)
        except Exception:   # noqa: BLE001
            return "?"


THRU = ("PAREN_EXPR", "UNEXPOSED_EXPR", "CSTYLE_CAST_EXPR", "CXX_STATIC_CAST_EXPR", "CXX_REINTERPRET_CAST_EXPR",
        "CXX_FUNCTIONAL_CAST_EXPR")


def strip(c):
    while c is not None and c.kind.name in THRU:
        k = [x for x in c.get_children() if x.kind.name != "TYPE_REF"]
        if len(k) != 1:
            break
        c = k[0]
    return c


def is_allocator(name):
    import equiv64
    if not name:
        return False
    return name in equiv64.ALLOCATORS or bool(equiv64.ALLOCATOR_CXX.match(name)) or \
        name.lstrip("_") in ("FUN_0008d690", "FUN_0008d6d0") or name in ("??2@YAPAXI@Z", "??_U@YAPAXI@Z")


# ------------------------------------------------------------------------------------------------ extract
def calls_in(fn):
    """The CALL_EXPRs of FN's body (and a constructor's initializers), in source order."""
    K = __import__("equiv64").ci().CursorKind
    out = []
    for ch in fn.get_children():
        if ch.kind == K.PARM_DECL:
            continue
        for x in ch.walk_preorder():
            if x.kind == K.CALL_EXPR:
                out.append(x)
    return out


def call_args(call):
    """(object expression or None, [argument expressions]) of CALL: a member call's object comes first."""
    K = __import__("equiv64").ci().CursorKind
    args = list(call.get_arguments())
    obj = None
    kids = list(call.get_children())
    if kids and kids[0].kind in (K.MEMBER_REF_EXPR, K.UNEXPOSED_EXPR):
        mr = kids[0]
        while mr.kind == K.UNEXPOSED_EXPR and len(list(mr.get_children())) == 1:
            mr = list(mr.get_children())[0]
        if mr.kind == K.MEMBER_REF_EXPR:
            base = [x for x in mr.get_children()]
            obj = base[0] if base else None
    return obj, args


def site_key(c):
    try:
        return (c.location.line, c.location.column)
    except Exception:   # noqa: BLE001
        return None


def extract_tu(path):
    """Facts of the tree TU PATH (relative to the root): its blocks' definitions, their calls (the callee's
    declaration as the caller sees it) and the allocations they hand to a call."""
    import equiv64
    import tree_tu
    rec = tree_tu.scan(path)
    rel = os.path.relpath(os.path.abspath(path), ROOT)
    out = {"ver": FACTS_VER, "tu": rel, "defs": [], "calls": [], "allocs": [], "ret_allocs": [], "errors": []}
    K = equiv64.ci().CursorKind
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as d:
        ctx = tree_tu.active(path) if tree_tu.is_tree_tu(path) else contextlib.nullcontext()
        with ctx:
            w = equiv64.write_wrapper(path, d)
            t32 = equiv64.TU(w, d, "i686-pc-windows-msvc", 32)
            t64 = equiv64.TU(w, d, "x86_64-pc-windows-msvc", 64)
        idx64 = {}
        for c in t64.by_mangled.values():
            idx64.setdefault((c.kind, equiv64.loc_key(c)), c)

        def pair64(c32):
            return idx64.get((c32.kind, equiv64.loc_key(c32)))
        for b in rec["blocks"]:
            s = b.get("sym")
            c32 = t32.by_mangled.get(s) if s else None
            if c32 is None:
                # (rev5) never left out silently: a block with nothing to parse (an MSVC `$L` funclet, an `_$E`
                # initializer, a `$`-named helper) is counted apart; any other is a block error
                if s and ("$" in s.split("@")[0] or s.startswith(("?_$E", "_$E", "$L"))):
                    out.setdefault("unparsed", []).append([b["addr"], s])
                else:
                    out["errors"].append([b["addr"], "no pin" if not s else "pin not in the parse"])
                continue
            c32 = c32.get_definition() or c32
            c64 = pair64(c32)
            c64 = (c64.get_definition() or c64) if c64 is not None else None
            if c64 is None:
                out["errors"].append([b["addr"], "no 64-bit pair"])
                continue
            out["defs"].append({"addr": b["addr"], "sym32": mangled(c32, 32), "pin": s, "sym64": mangled(c64, 64),
                                "at": where(c32), "kind": b.get("kind"),
                                "s32": sig_of(c32), "s64": sig_of(c64)})
            try:
                block_calls(b["addr"], c32, c64, out)
            except Exception as e:      # noqa: BLE001 - keep the TU's other blocks
                out["errors"].append([b["addr"], "calls: %r" % e])
    return out


def block_calls(addr, f32, f64, out):
    """The calls of one block (both parses, paired by source position) and the allocations among them."""
    import equiv64
    K = equiv64.ci().CursorKind
    l32, l64 = calls_in(f32), calls_in(f64)
    by64 = {}
    for c in l64:       # (keyed by place and callee: a call and the temporaries' constructors share a place)
        by64.setdefault((site_key(c), c.referenced.spelling if c.referenced is not None else None), c)
    local_alloc = {}        # local variable hash -> alloc record
    field_alloc = {}        # (record spelling, field name) -> alloc record
    pending = []            # allocations made in this block
    for c in l32:
        c64 = by64.get((site_key(c), c.referenced.spelling if c.referenced is not None else None))
        callee = c.referenced
        if callee is None or callee.kind not in (K.FUNCTION_DECL, K.CXX_METHOD, K.CONSTRUCTOR, K.DESTRUCTOR):
            continue
        callee64 = c64.referenced if c64 is not None else None
        n32 = mangled(callee, 32)       # (untreed: the allocators are declared in the TU's namespace too)
        rec = {"caller": addr, "at": where(c), "callee32": n32,
               "callee64": mangled(callee64, 64) if callee64 is not None else None,
               "name": callee.spelling, "decl_at": where(callee), "s32": sig_of(callee),
               "s64": sig_of(callee64) if callee64 is not None else None,
               "argc": len(list(c.get_arguments()))}
        out["calls"].append(rec)
        if is_allocator(n32) and c64 is not None:
            a32 = list(c.get_arguments())
            a64 = list(c64.get_arguments())
            at_ = 3 if (callee.spelling or "").endswith("0021add0") else 0
            if len(a32) > at_ and len(a64) > at_:
                al = {"caller": addr, "at": where(c), "size32": evaluate(a32[at_]), "size64": evaluate(a64[at_]),
                      "site": site_key(c)}
                pending.append((c, al))
    # flows: where each allocation goes
    allocs_by_hash = {x[0].hash: x[1] for x in pending}

    def alloc_of(e):
        """The allocation expression E (stripped) is, or the local / field it was stored in."""
        e = strip(e)
        if e is None:
            return None
        if e.kind == K.CALL_EXPR and e.hash in allocs_by_hash:
            return allocs_by_hash[e.hash]
        if e.kind == K.DECL_REF_EXPR and e.referenced is not None and e.referenced.hash in local_alloc:
            return local_alloc[e.referenced.hash]
        if e.kind == K.MEMBER_REF_EXPR and e.referenced is not None and e.referenced.kind == K.FIELD_DECL:
            k = (e.referenced.semantic_parent.type.get_canonical().spelling if e.referenced.semantic_parent else "",
                 e.referenced.spelling)
            return field_alloc.get(k)
        return None
    # locals and fields assigned from an allocation (in body order)
    for x in f32.walk_preorder():
        if x.kind == K.VAR_DECL:
            kids = [k for k in x.get_children() if k.kind.name not in ("TYPE_REF", "NAMESPACE_REF", "TEMPLATE_REF")]
            if kids:
                a = alloc_of(kids[-1])
                if a is not None:
                    local_alloc[x.hash] = a
        elif x.kind == K.BINARY_OPERATOR:
            kids = list(x.get_children())
            op = getattr(getattr(x, "binary_operator", None), "name", None)
            if op is None:      # (older bindings: the operator token between the operands)
                toks = [t.spelling for t in x.get_tokens()]
                n0 = len(list(kids[0].get_tokens())) if kids else 0
                op = "Assign" if len(toks) > n0 and toks[n0] == "=" else None
            if len(kids) == 2 and op == "Assign":
                a = alloc_of(kids[1])
                lhs = strip(kids[0])
                if a is None or lhs is None:
                    continue
                if lhs.kind == K.DECL_REF_EXPR and lhs.referenced is not None and lhs.referenced.kind == K.VAR_DECL:
                    local_alloc[lhs.referenced.hash] = a
                elif lhs.kind == K.MEMBER_REF_EXPR and lhs.referenced is not None and \
                        lhs.referenced.kind == K.FIELD_DECL:
                    k = (lhs.referenced.semantic_parent.type.get_canonical().spelling
                         if lhs.referenced.semantic_parent else "", lhs.referenced.spelling)
                    field_alloc[k] = dict(a, via="field %s::%s" % k)
        elif x.kind == K.RETURN_STMT:
            kids = list(x.get_children())
            if kids:
                a = alloc_of(kids[0])
                if a is not None:
                    out["ret_allocs"].append({"addr": addr, "size32": a.get("size32"), "size64": a.get("size64"),
                                              "at": a.get("at")})
    # consumers: a call whose object or first argument is an allocation
    for c in l32:
        callee = c.referenced
        if callee is None or callee.kind not in (K.FUNCTION_DECL, K.CXX_METHOD, K.CONSTRUCTOR):
            continue
        obj, args = call_args(c)
        src = None
        how = None
        if obj is not None:
            src, how = alloc_of(obj), "this"
        if src is None and args:
            src, how = alloc_of(args[0]), "arg0"
        if src is None:
            continue
        out["allocs"].append(dict(src, how=how + ("" if "via" not in src else " via " + src["via"]),
                                  callee32=mangled(callee, 32), name=callee.spelling, use_at=where(c)))
    # placement new on an allocation: `new (m) T(...)`, the constructor's object is the placement argument
    news64 = {}
    for x in f64.walk_preorder():
        if x.kind == K.CXX_NEW_EXPR:
            news64.setdefault(site_key(x), x)
    for x in f32.walk_preorder():
        if x.kind != K.CXX_NEW_EXPR:
            continue
        kids = list(x.get_children())
        ctor = next((k for k in kids if k.kind == K.CALL_EXPR and k.referenced is not None and
                     k.referenced.kind == K.CONSTRUCTOR), None)
        place = [k for k in kids if k.kind.name not in ("TYPE_REF", "NAMESPACE_REF", "TEMPLATE_REF") and k is not ctor
                 and not (k.kind == K.CALL_EXPR and k.referenced is not None and k.referenced.kind == K.CONSTRUCTOR)]
        if not place:
            continue
        src = alloc_of(place[0])
        if src is None:
            continue
        x64 = news64.get(site_key(x))
        t64 = x64.type.get_canonical().get_pointee() if x64 is not None else None
        s64 = t64.get_size() if t64 is not None else None
        out["allocs"].append(dict(src, how="placement new" + ("" if "via" not in src else " via " + src["via"]),
                                  callee32=mangled(ctor.referenced, 32) if ctor is not None else None,
                                  name=ctor.referenced.spelling if ctor is not None else None, use_at=where(x),
                                  new_size64=s64 if s64 and s64 > 0 else None,
                                  new_type=t64.spelling if t64 is not None else None))
    # calls whose result is handed on, for the return flows (resolved in the report): `T* p = Make(); p->Init()`
    for c in l32:
        callee = c.referenced
        if callee is None or callee.kind not in (K.FUNCTION_DECL, K.CXX_METHOD, K.CONSTRUCTOR):
            continue
        obj, args = call_args(c)
        for how, e in (("this", obj), ("arg0", args[0] if args else None)):
            e = strip(e)
            if e is None:
                continue
            maker = None
            if e.kind == K.CALL_EXPR and e.referenced is not None:
                maker = e.referenced
            elif e.kind == K.DECL_REF_EXPR and e.referenced is not None and e.referenced.kind == K.VAR_DECL:
                kids = [k for k in e.referenced.get_children() if k.kind.name not in ("TYPE_REF", "NAMESPACE_REF")]
                init = strip(kids[-1]) if kids else None
                if init is not None and init.kind == K.CALL_EXPR and init.referenced is not None:
                    maker = init.referenced
            if maker is not None and maker.kind in (K.FUNCTION_DECL, K.CXX_METHOD) and \
                    not is_allocator(mangled(maker, 32)):
                out.setdefault("handoffs", []).append({"caller": addr, "maker32": mangled(maker, 32),
                                                       "maker": maker.spelling, "callee32": mangled(callee, 32),
                                                       "name": callee.spelling, "how": how, "use_at": where(c)})
                break


def cmd_extract(a):
    os.makedirs(a.out, exist_ok=True)
    for p in a.tus:
        rel = os.path.relpath(os.path.abspath(p), ROOT)
        dst = os.path.join(a.out, rel.replace("/", "__") + ".json")
        try:
            f = extract_tu(p)
        except Exception as e:      # noqa: BLE001
            f = {"ver": FACTS_VER, "tu": rel, "fatal": repr(e)[:300]}
        with open(dst, "w") as fh:
            json.dump(f, fh)
        print(rel, "defs", len(f.get("defs", [])), "calls", len(f.get("calls", [])), "allocs",
              len(f.get("allocs", [])), "fatal" if f.get("fatal") else "", flush=True)


# ------------------------------------------------------------------------------------------------ report
NAME_ADDR = re.compile(r"(?:^|[^0-9A-Za-z])(?:FUN|LAB|thunk_FUN)?_?([0-9a-fA-F]{8})(?:@|$)")


def name_address(name):
    """The address a callee's name carries (FUN_xxxxxxxx / Name_xxxxxxxx, C or C++ spelling), else None."""
    import addr_names
    if not name:
        return None
    a = addr_names.symbol_suffix_address(name)
    if a is None:
        leaf = name.lstrip("_?")
        m = re.match(r"(?:FUN|LAB)_([0-9a-fA-F]{8})", leaf)
        a = int(m.group(1), 16) if m else None
    return a


def diff_sig(call, d):
    """The kinds of disagreement between a call's declaration and the definition D (64-bit facts)."""
    out = []
    cs, ds = call.get("s64"), d.get("s64")
    if cs is None or ds is None:
        return ["unpaired"]
    if call.get("callee64") != d.get("sym64"):
        out.append("symbol")
    cp_, dp_ = cs["params"], ds["params"]
    if cs["this"] != ds["this"]:
        # a member on one side, a free function taking the object as its first (pointer) argument on the other:
        # `this` is that argument natively too (rcx / x0), so only the remaining arguments are compared
        # (rev5's R1) but not when a record is returned: a method returns it through sret placed after `this`, a
        # free function in registers
        sret = "rec" in ((cs.get("ret") or [None])[0], (ds.get("ret") or [None])[0])
        tag = "this_as_arg0_sret" if sret else "this_as_arg0"
        if cp_ is not None and dp_ is not None and cs["this"] and len(dp_) == len(cp_) + 1 and dp_[0][0] == "ptr":
            out.append(tag)
            dp_ = dp_[1:]
        elif cp_ is not None and dp_ is not None and ds["this"] and len(cp_) == len(dp_) + 1 and cp_[0][0] == "ptr":
            out.append(tag)
            cp_ = cp_[1:]
        else:
            out.append("member_vs_free")
    if cp_ is not None and dp_ is not None and not (cs["variadic"] or ds["variadic"]):
        if len(cp_) != len(dp_):
            out.append("argc %d/%d" % (len(cp_), len(dp_)))
        for i, (x, y) in enumerate(zip(cp_, dp_)):     # (the arguments both have)
            if x[0] == y[0] == "rec" and (x[2:] or [None])[0] != (y[2:] or [None])[0]:
                out.append("arg%d hfa_vs_not" % i)      # (rev5's R2) s-registers vs x-registers on arm64
            if x[0] != y[0]:
                if {x[0], y[0]} == {"ptr", "int"}:
                    out.append("arg%d pointer_vs_int" % i)
                else:
                    out.append("arg%d %s_vs_%s" % (i, x[0], y[0]))
            elif x[1] != y[1]:
                out.append("arg%d size %d/%d" % (i, x[1], y[1]))
    if cs["ret"] and ds["ret"] and cs["ret"][0] == ds["ret"][0] == "rec" and \
            (cs["ret"][2:] or [None])[0] != (ds["ret"][2:] or [None])[0]:
        out.append("ret hfa_vs_not")
    if cs["ret"] and ds["ret"] and (cs["ret"][0] != ds["ret"][0] or cs["ret"][1] != ds["ret"][1]):
        if {cs["ret"][0], ds["ret"][0]} == {"ptr", "int"}:
            out.append("ret pointer_vs_int")
        else:
            out.append("ret %s%d_vs_%s%d" % (cs["ret"][0], cs["ret"][1], ds["ret"][0], ds["ret"][1]))
    # (find1) an extern "C" pair binds natively by name with no type in the symbol: a pointer taken as an int (or an
    # argument of another size, in either direction) links silently and truncates. Its own kind
    sym = d.get("sym64") or ""
    if sym and not sym.startswith("?") and any(k.startswith(("arg", "ret")) for k in out):
        out.append("c_link_type")
    return out


def record_size(d):
    """The 64-bit size of the record the definition D works on (its class; a free function's first pointee)."""
    s = d.get("s64") or {}
    if s.get("this") and s.get("cls") and s["cls"][1]:
        return s["cls"][1], s["cls"][0]
    if s.get("p0"):
        return s["p0"], "arg0 pointee"
    return None, None


def report(facts_dir, out_dir):
    facts = []
    for f in sorted(glob.glob(os.path.join(facts_dir, "*.json"))):
        try:
            facts.append(json.load(open(f)))
        except ValueError:
            pass
    by_sym, by_addr = {}, {}
    def_names = {}      # (rev5) a definition's plain name -> its symbols
    for f in facts:
        for d in f.get("defs", []):
            d["tu"] = f["tu"]
            by_sym.setdefault(d["sym32"], d)
            by_addr.setdefault(int(d["addr"], 16), d)
            sym = d.get("sym32") or ""
            leaf = sym[1:].split("@")[0] if sym.startswith("?") else sym.lstrip("_@").split("@")[0]
            if leaf:
                def_names.setdefault(leaf, []).append(sym)

    def resolve(sym, name):
        d = by_sym.get(sym)
        if d is not None:
            return d, "symbol"
        a = name_address(sym) or name_address(name)
        if a is not None and a in by_addr:
            return by_addr[a], "address"
        return None, None
    rows, stats = [], {"tus": len(facts), "fatal": 0, "defs": 0, "calls": 0, "resolved": 0, "decl_rows": 0,
                       "alloc_rows": 0, "allocs": 0, "allocs_sized": 0}
    seen = set()
    ret_alloc = {}
    gaps = []
    stats.update(block_errors=0, unpaired_calls=0, unresolved_calls=0, unresolved_library_calls=0,
                 unresolved_by_symbol=0, allocs_unsized=0, stale_facts=0)
    for f in [f for f in facts if f.get("ver") != FACTS_VER]:
        # (rev5) facts of another extraction (older records, older call pairing) are not compared, and block `clean`
        stats["stale_facts"] += 1
        gaps.append({"gap": "stale_facts", "tu": f.get("tu"), "ver": f.get("ver")})
    facts = [f for f in facts if f.get("ver") == FACTS_VER]
    stats["unparsed_blocks"] = 0
    for f in facts:
        stats["unparsed_blocks"] += len(f.get("unparsed", []))     # (funclets, initializers: nothing to parse)
        for e in f.get("errors", []):
            stats["block_errors"] += 1
            gaps.append({"gap": "block_error", "tu": f["tu"], "addr": e[0], "why": e[1]})
        if f.get("fatal"):
            stats["fatal"] += 1
            gaps.append({"gap": "tu_fatal", "tu": f["tu"], "why": f["fatal"]})
        stats["defs"] += len(f.get("defs", []))
        for r in f.get("ret_allocs", []):
            ret_alloc.setdefault(int(r["addr"], 16), r)
    for f in facts:
        for c in f.get("calls", []):
            stats["calls"] += 1
            d, how = resolve(c["callee32"], c["name"])
            if d is None:
                if name_address(c["callee32"]) is None and name_address(c["name"]) is None:
                    if c["name"] in def_names:
                        # (rev5) the tree defines a function of that name, but not under this symbol (an unpinned
                        # block, a fatal or stale TU, a C++ mangling that differs): a gap, not library code
                        stats["unresolved_by_symbol"] += 1
                        gaps.append({"gap": "unresolved_by_symbol", "tu": f["tu"], "caller": c["caller"],
                                     "callee": c["callee32"], "definitions": def_names[c["name"]][:4],
                                     "at": c["at"]})
                        continue
                    # a callee with no address in its name and no definition of its name in the tree: the XDK,
                    # the CRT, the platform layer (expected; counted apart, not blocking `clean`)
                    stats["unresolved_library_calls"] += 1
                    continue
                stats["unresolved_calls"] += 1
                gaps.append({"gap": "unresolved_call", "tu": f["tu"], "caller": c["caller"], "callee": c["callee32"],
                             "at": c["at"]})
                continue
            stats["resolved"] += 1
            if d["addr"] == c["caller"]:
                continue
            if c.get("s64") is None or d.get("s64") is None:
                stats["unpaired_calls"] += 1
                gaps.append({"gap": "unpaired_call", "tu": f["tu"], "caller": c["caller"], "callee": d["addr"],
                             "at": c["at"]})
                continue
            kinds = diff_sig(c, d)
            if kinds in (["symbol"], ["symbol", "this_as_arg0"], ["this_as_arg0"]):
                # the names differ only: bound by the address the caller's name carries (the native link binds
                # FUN_/Name_<addr> by address, D35), or the same symbol up to the tree's namespaces
                kinds = []
            if not kinds:
                continue
            k = (c["caller"], d["addr"], c["callee32"], tuple(kinds))
            if k in seen:
                continue
            seen.add(k)
            rows.append({"check": "decl", "caller": c["caller"], "caller_tu": f["tu"], "at": c["at"],
                         "callee": d["addr"], "callee_tu": d["tu"], "callee_at": d["at"], "bound_by": how,
                         "caller_decl": c["callee32"], "caller_decl_at": c["decl_at"], "definition": d["sym32"],
                         "kinds": kinds})
            stats["decl_rows"] += 1

        def alloc_row(a, d, via):
            stats["allocs"] += 1
            need, what = record_size(d)
            if need is None or a.get("size64") is None:
                stats["allocs_unsized"] += 1
                gaps.append({"gap": "alloc_unsized", "tu": f["tu"], "caller": a["caller"], "at": a.get("at"),
                             "why": "no record size" if need is None else "a runtime size"})
                return
            stats["allocs_sized"] += 1
            if a["size64"] < need:
                rows.append({"check": "alloc", "caller": a["caller"], "caller_tu": f["tu"], "at": a["at"],
                             "use_at": a.get("use_at"), "how": via, "size32": a.get("size32"),
                             "size64": a["size64"], "callee": d["addr"], "callee_tu": d["tu"], "record": what,
                             "record_size64": need})
                stats["alloc_rows"] += 1
        for a in f.get("allocs", []):
            d, how = resolve(a["callee32"], a["name"]) if a.get("callee32") else (None, None)
            if d is not None:
                alloc_row(a, d, a["how"])
            elif a.get("new_size64"):
                # a placement new of a type whose constructor isn't a block: the type's own native size
                alloc_row(a, {"addr": None, "tu": f["tu"], "s64": {"this": True, "cls": [a.get("new_type"),
                                                                                          a["new_size64"]]}}, a["how"])
        for h in f.get("handoffs", []):
            m, _ = resolve(h["maker32"], h["maker"])
            if m is None or int(m["addr"], 16) not in ret_alloc:
                continue
            d, _ = resolve(h["callee32"], h["name"])
            if d is None:
                continue
            r = ret_alloc[int(m["addr"], 16)]
            alloc_row({"caller": h["caller"], "at": r.get("at"), "use_at": h["use_at"], "size32": r.get("size32"),
                       "size64": r.get("size64")}, d, h["how"] + " via return of " + m["addr"])
    # (D132 for equivalent blocks) a call in an equivalent block (not relocation-checked) whose callee's name or
    # symbol reaches one of the game's frees under another name than that free's own
    import verify_relocs
    kind_of_def = {(f["tu"], d["addr"]): d.get("kind") for f in facts for d in f.get("defs", [])}
    free_rows = 0
    for f in facts:
        for c in f.get("calls", []):
            if kind_of_def.get((f["tu"], c["caller"])) != "equivalent":
                continue
            d, how = resolve(c["callee32"], c["name"])
            a_ = int(d["addr"], 16) if d is not None else name_address(c["callee32"]) or name_address(c["name"])
            if a_ is None:
                continue
            fr = verify_relocs.free_reached(a_)
            if fr is None or verify_relocs.FREE_NAMES[fr].match(c["callee32"] or ""):
                continue
            rows.append({"check": "free_name", "caller": c["caller"], "caller_tu": f["tu"], "at": c["at"],
                         "callee": "0x%08x" % fr, "name": c["callee32"]})
            free_rows += 1
    stats["free_name_rows"] = free_rows
    os.makedirs(out_dir, exist_ok=True)
    with open(os.path.join(out_dir, "report.jsonl"), "w") as fh:
        for r in sorted(rows, key=lambda r: (r["check"], r["caller_tu"], r["caller"])):
            fh.write(json.dumps(r) + "\n")
    kinds = {}
    for r in rows:
        for k in r.get("kinds", [r["check"]]):
            k0 = re.sub(r"\d+", "N", k)
            k0 = "argN size" if k0.startswith("argN size") else ("argc" if k0.startswith("argc") else k0)
            kinds[k0] = kinds.get(k0, 0) + 1
    stats["kinds"] = dict(sorted(kinds.items(), key=lambda x: -x[1]))
    # (rev5's R3) the coverage gaps: a report is clean only when these are zero or each is explained
    with open(os.path.join(out_dir, "gaps.jsonl"), "w") as fh:
        for g in gaps:
            fh.write(json.dumps(g) + "\n")
    stats["clean"] = not any(stats[k] for k in ("fatal", "block_errors", "unpaired_calls", "unresolved_calls",
                                                "unresolved_by_symbol", "allocs_unsized", "stale_facts"))
    with open(os.path.join(out_dir, "summary.json"), "w") as fh:
        json.dump(stats, fh, indent=1)
    return rows, stats


def cmd_report(a):
    rows, stats = report(a.facts, a.out)
    print(json.dumps(stats, indent=1))


def cmd_run(a):
    import tree_tu
    tus = sorted(os.path.relpath(p, ROOT) for p in tree_tu.tree_tus(ROOT))
    facts = a.facts
    if not a.jobq:
        os.makedirs(facts, exist_ok=True)
        cmd_extract(argparse.Namespace(tus=tus, out=facts))
    else:
        groups = [tus[i:i + a.per] for i in range(0, len(tus), a.per)]
        jl = os.path.join(facts, "..", "submit.jsonl")
        os.makedirs(facts, exist_ok=True)
        with open(jl, "w") as fh:
            for i, g in enumerate(groups):
                fh.write(json.dumps({"cmd": ["sh", "-c", "mkdir -p jobout/facts; build/venv/bin/python tools/xtu_check.py "
                                             "extract %s --out jobout/facts > jobout/log.txt 2>&1" % " ".join(g)],
                                     "files": ["tools/xtu_check.py"],
                                     "out": ["jobout/facts", "jobout/log.txt"]}) + "\n")
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/jobq.py"), "submit-many", jl, "--name",
                            a.name, "--needs", "clang", "--limit", "7200", "--prio", str(a.prio), "--attempts", "2"],
                           cwd=ROOT, capture_output=True, text=True)
        ids = r.stdout.split()
        print(len(ids), "jobs", ids[:1], ids[-1:], r.stderr[-500:])
        with open(os.path.join(facts, "..", "ids"), "w") as fh:
            fh.write("\n".join(ids) + "\n")


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = p.add_subparsers(dest="cmd", required=True)
    e = sp.add_parser("extract")
    e.add_argument("tus", nargs="+")
    e.add_argument("--out", required=True)
    e.set_defaults(fn=cmd_extract)
    r = sp.add_parser("report")
    r.add_argument("facts")
    r.add_argument("--out", default=os.path.join(ROOT, "build/xtu"))
    r.set_defaults(fn=cmd_report)
    u = sp.add_parser("run")
    u.add_argument("--jobq", action="store_true")
    u.add_argument("--per", type=int, default=40)
    u.add_argument("--prio", type=int, default=-5)
    u.add_argument("--name", default="xtu")
    u.add_argument("--facts", default=os.path.join(ROOT, "build/xtu/facts"))
    u.set_defaults(fn=cmd_run)
    a = p.parse_args(argv)
    a.fn(a)


if __name__ == "__main__":
    main()
