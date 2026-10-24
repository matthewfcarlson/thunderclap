#!/usr/bin/env python3
"""Source rewrites of the consolidation plan (docs/consolidation-plan.md), used by `tools/migrate_gen.py --family rn`.

  unclash   a source's private stub that carries an include/gen/ class's name but is another class (rename map,
            tools/rn_map.py) takes the real class's name with the source's placeholder suffix:
            `CSweepTrack` -> `CCharacterTemplateManager_46110`. Token-level, everything the name spells (its
            definition, `CSweepTrack::vfunc_3`, uses) changes, and so do the stub's companion variables
            (`CTrack_vftable` -> `ConditionFactory_23d3d0_vftable`: merged, two sources' `CTrack_vftable` would be one
            symbol for two vftables); comments, strings, preprocessor and `// equiv-*` lines don't. In a TU on
            include/gen/ the stub no longer collides with the header's class.
  relabel   (b4) the same rename for a suffixed or invented stub that collides with nothing (`Obj_2d5ec0` ->
            `SpriteParticleEmitter_2d5ec0`): readability, and the name says which class a later batch moves it onto.
  gen-ref   a stub the source only uses (no member defined in the source) whose real class is an include/gen/
            class goes: the source includes the class's header, names the class (`Ref_1d1e0` ->
            `pure3d::NonCopyable`), its field accesses become the header's `f_XX` fields (a `(*(T*)&p->f_XX)` cast
            where the stub's type differs), its virtual calls the header's slot names (arguments cast to the header's
            parameter types, the result to the stub's return type), and non-virtual calls go through a declaration
            struct `<Class>_nv_<addr>` (as gen-swap does for the target's own class). Other stubs whose names
            collide with the header's names get the placeholder suffix. Refused (SwapFail) when the stub has bases,
            is used by value / `new` / `sizeof` / as a base, a used field is not in the header, a used virtual is
            past the header's vftable or is its destructor, the arity differs, or a float meets an integer.

Every rewrite is verified by migrate_gen.py (compare.py MATCH / equiv.py --inputs 3000 EQUIVALENT) before it is kept.
"""
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import gen_headers as gh  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SwapFail = gh.SwapFail
EQUIV_LINE = re.compile(r"//\s*equiv-[\w-]+:?(.*)")
FLOATS = {"float", "double", "long double"}


def clang_ast(path):
    """gen_headers.clang_ast with include/ on the include path (sources may include gen/ and decls/ headers)."""
    import subprocess
    r = subprocess.run(gh.CLANG + ["-I", os.path.join(ROOT, "include"), "-fsyntax-only", "-Xclang", "-ast-dump=json",
                                   path], capture_output=True, text=True)
    if r.returncode != 0:
        return None
    return json.loads(r.stdout)


def clang_layouts(path):
    old = list(gh.CLANG)
    try:
        gh.CLANG[:] = old + ["-I", os.path.join(ROOT, "include")]
        return gh.clang_layouts(path)
    finally:
        gh.CLANG[:] = old


def equiv_text(text):
    return "\n".join(m.group(1) for m in EQUIV_LINE.finditer(text))


def tok_edit(text, fn):
    """Apply fn(i, toks) -> replacement or None to every identifier token; comments/strings/pp lines untouched."""
    try:
        toks = cxx_items.tokenize(text)
    except ValueError:
        raise SwapFail("can't tokenize")
    out, last = [], 0
    for i, t in enumerate(toks):
        if t.t != "id":
            continue
        r = fn(i, toks)
        if r is None:
            continue
        out.append(text[last:t.s])
        out.append(r)
        last = t.e
    out.append(text[last:])
    return "".join(out)


def pin_data_transform(text, renames):
    """b11/b12: a source's invented names for global data or free functions (`extern int a, b;`, `extern "C" int
    check(...)`, whose addresses the strict Wine link / verify_relocs bind by relocation position) take their address
    names (`DAT_004985b8`, `FUN_00344e74`), so two sources merged into one TU no longer declare one invented name for
    two addresses, nor two names for one. `renames`: {invented name: DAT_/FUN_ name}. Token-level, like
    unclash; refused where the name is also a member name or named on an `// equiv-*` line."""
    eq = equiv_text(text)
    for old, new in renames.items():
        if not re.fullmatch(r"(DAT|FUN)_[0-9a-f]{8}", new):
            raise SwapFail("not an address name: %s" % new)
        if re.search(r"\b%s\b" % re.escape(old), eq):
            raise SwapFail("%s named on an equiv-* line" % old)
        if member_uses(text, old):
            raise SwapFail("%s is also a member name" % old)
        if re.search(r"\b%s\b" % re.escape(new), text):
            raise SwapFail("the source already uses %s" % new)

    def ren(i, toks):
        t = toks[i]
        if t.v not in renames:
            return None
        if i and toks[i - 1].v in (".", "->", "::"):
            return None
        return renames[t.v]
    out = tok_edit(text, ren)
    if out == text:
        raise SwapFail("nothing renamed")
    return out, "; ".join("%s->%s" % kv for kv in sorted(renames.items()))


def canon_decl_transform(text, canon):
    """b12: a source's own top-level declaration of an address-named function takes one canonical spelling
    (`canon`: {FUN_ name: declaration text}), so sources merged into one TU declare it identically (an `extern "C"`
    declaration differing in a parameter's constness, or a C++ one beside it, is a conflict the generator wraps).
    No header: sources that are not rewritten keep their own. Refused for a name the source also defines."""
    try:
        items = cxx_items.parse(text)
    except ValueError:
        raise SwapFail("does not parse")
    cuts = []
    for it in items:
        if it.kind != "func" or it.scope or it.name not in canon:
            continue
        if "{" in it.text:
            raise SwapFail("%s is defined here" % it.name)
        if re.search(r"\b%s\b" % re.escape(it.name), equiv_text(text)):
            raise SwapFail("%s named on an equiv-* line" % it.name)
        cuts.append((it.toks[0].s, it.toks[-1].e, canon[it.name], it.name))
    if not cuts:
        raise SwapFail("nothing to canonicalize")
    out, cur = [], 0
    for s0, e0, new, _n in sorted(cuts):
        out.append(text[cur:s0])
        out.append(new)
        cur = e0
    out.append(text[cur:])
    new = "".join(out)
    if new == text:
        raise SwapFail("already canonical")
    return new, ", ".join(sorted(n for _s, _e, _t, n in cuts))


def canon_data_transform(text):
    """Casters pass (consolidation follow-up of b11/b12): a top-level `extern T DAT_x[, DAT_y...];` whose names the
    source only ever uses as `&DAT_x` (an RTTI descriptor's address handed to the cast helper) takes the one spelling
    `extern char DAT_x;` per name (b11's data pins), so the sources merged into one TU declare it identically. The
    code is the same (only the address is used). Refused for names on an `// equiv-*` line."""
    try:
        toks = cxx_items.tokenize(text)
    except ValueError:
        raise SwapFail("can't tokenize")
    eq = equiv_text(text)
    cuts = []
    i, depth = 0, 0
    while i < len(toks):
        t = toks[i]
        if t.v in ("{", "(", "["):
            depth += 1
        elif t.v in ("}", ")", "]"):
            depth -= 1
        if depth == 0 and t.v == "extern" and (i == 0 or toks[i - 1].v in (";", "}") or toks[i - 1].t == "pp"):
            j = i + 1
            while j < len(toks) and toks[j].v != ";":
                j += 1
            stmt = toks[i:j]
            names = [x.v for x in stmt if x.t == "id" and re.fullmatch(r"DAT_[0-9a-f]{8}", x.v)]
            vals = [x.v for x in stmt[1:]]
            if (names and j < len(toks) and not any(v in vals for v in ("(", "[", "{", "=", '"C"', "const"))
                    and vals[-1] == names[-1]):
                # the type is every token before the first name; the rest is `NAME (, NAME)*`
                k = vals.index(names[0])
                tail = vals[k:]
                if tail == [x for n in names for x in (n, ",")][:-1]:
                    typ = " ".join(vals[:k])
                    ok = all(not re.search(r"\b%s\b" % n, eq) for n in names)
                    for n in names:
                        for q, u in enumerate(toks):
                            if u.v == n and not (i <= q < j) and (q == 0 or toks[q - 1].v != "&"):
                                ok = False
                    if ok and (typ != "char" or len(names) > 1):
                        cuts.append((t.s, toks[j].e, "\n".join("extern char %s;" % n for n in names)))
            i = j
        i += 1
    if not cuts:
        raise SwapFail("nothing to canonicalize")
    out, cur = [], 0
    for s0, e0, new in cuts:
        out.append(text[cur:s0])
        out.append(new)
        cur = e0
    out.append(text[cur:])
    return "".join(out), "%d declarations" % len(cuts)


def member_uses(text, name):
    """True if `name` is used after `.`, `->` or as the second part of `X::name` (a member name)."""
    toks = cxx_items.tokenize(text)
    for i, t in enumerate(toks):
        if t.t == "id" and t.v == name and i:
            p = toks[i - 1].v
            if p in (".", "->"):
                return True
    return False


def short(q):
    return re.sub(r"<.*", "", q).split("::")[-1]


def placeholder(real, addr):
    return "%s_%x" % (short(real), addr)


# ---------------------------------------------------------------------------------------------
SUFFIXED = re.compile(r"^(\w+?)_([0-9a-f]{4,8})$")


def relabel_name(stub, real, addr):
    """b4's name for a suffixed or invented stub whose real class the rename map knows: the real class's short name
    with the stub's own placeholder suffix (`Obj_2d5ec0` -> `SpriteParticleEmitter_2d5ec0`, the same in every
    source that carries a copy of it) or, for an invented name, the source's (`Node` -> `Object_1c5a70`)."""
    m = SUFFIXED.match(stub)
    if m:
        return "%s_%s" % (short(real), m.group(2))
    return placeholder(real, addr)


def unclash_transform(text, addr, stub, real, new=None):
    """(new text, what) or SwapFail. `new`: the stub's new name (default: the real name + the source's suffix)."""
    if "::" in stub:
        raise SwapFail("namespaced stub")
    new = new or placeholder(real, addr)
    if not re.fullmatch(r"[A-Za-z_]\w*", new):
        raise SwapFail("not an identifier: %s" % new)
    if stub == new:
        raise SwapFail("already its placeholder name")
    eq = equiv_text(text)
    if re.search(r"\b%s\b" % re.escape(stub), eq):
        raise SwapFail("stub named on an equiv-* line")
    if re.search(r"\b%s\b" % re.escape(new), text):
        raise SwapFail("the source already uses %s" % new)
    if member_uses(text, stub):
        raise SwapFail("%s is also a member name" % stub)
    if re.search(r"^\s*#\s*define\b", text, re.M):
        raise SwapFail("macros")
    # the stub's companion variables (`extern void* CTrack_vftable[];`) go with it: in a merged TU two sources'
    # `CTrack_vftable` would be one symbol for two vftables (the native link can't bind it)
    comp = {}
    try:
        items = cxx_items.parse(text)
    except ValueError:
        raise SwapFail("does not parse")
    for it in items:
        if it.kind == "var" and it.name and it.name.startswith(stub + "_") and not it.scope:
            nn = new + it.name[len(stub):]
            if re.search(r"\b%s\b" % re.escape(it.name), eq):
                raise SwapFail("%s named on an equiv-* line" % it.name)
            if re.search(r"\b%s\b" % re.escape(nn), text):
                raise SwapFail("the source already uses %s" % nn)
            comp[it.name] = nn
    out = tok_edit(text, lambda i, toks: new if toks[i].v == stub else comp.get(toks[i].v))
    if out == text:
        raise SwapFail("nothing renamed")
    return out, "%s->%s" % (stub, new) + "".join("; %s->%s" % kv for kv in sorted(comp.items()))


# ---------------------------------------------------------------------------------------------
def _norm(t):
    t = gh._clean_qt(t)
    t = re.sub(r"\b(struct|class|union|enum)\s+", "", t)
    t = re.sub(r"\s+", " ", t).replace(" *", "*").replace("* ", "*").strip()
    # (hulk_intptr / hulk_uintptr: include/compat/ptr.h, int / unsigned int on the 32-bit builds; header fields typed
    # by tools/rn_ptrfields.py)
    return {"unsigned": "unsigned int", "signed": "int", "long": "int", "unsigned long": "unsigned int",
            "hulk_intptr": "int", "hulk_uintptr": "unsigned int"}.get(t, t)


def _is_float(t):
    return _norm(t) in FLOATS


def _fn_ret(qt):
    """'int (int, float) __attribute__((thiscall))' -> 'int'"""
    qt = gh._clean_qt(qt)
    depth = 0
    for i, ch in enumerate(qt):
        if ch == "(":
            if depth == 0 and i > 0:
                return qt[:i].strip()
            depth += 1
    return qt


def _fn_params(n):
    return [gh._clean_qt(c["type"]["qualType"]) for c in n.get("inner", []) if c.get("kind") == "ParmVarDecl"]


def _from_include(n):
    for loc in (n.get("loc", {}), n.get("range", {}).get("begin", {})):
        if loc.get("includedFrom") or loc.get("spellingLoc", {}).get("includedFrom") or \
                loc.get("expansionLoc", {}).get("includedFrom"):
            return True
    return False


def _walk(n, f, parent=None, depth=0):
    if _from_include(n):
        return
    f(n, parent, depth)
    for c in n.get("inner", []):
        _walk(c, f, n, depth + 1)


def genref_transform(path, raw, stub, real, hdb, addr, taken, keep=(), base_ok=False):
    """Rewrite source text `raw` (also on disk at `path`, which clang reads) so stub `stub` is the include/gen/
    class `real`. Returns (new text, what) or raises SwapFail."""
    h = hdb.get(real)
    if h is None:
        raise SwapFail("no header layout for %s" % real)
    sshort = short(stub)
    sns = stub.split("::")[:-1]
    eq = equiv_text(raw)
    if re.search(r"\b%s\b" % re.escape(sshort), eq):
        raise SwapFail("stub named on an equiv-* line")
    if re.search(r"^\s*#\s*(?!include\s*\"(gen|decls|compat)/)", raw, re.M):
        raise SwapFail("preprocessor lines")
    ast = clang_ast(path)
    if ast is None:
        raise SwapFail("clang can't parse the original")
    S, fwds, nodes_ns = None, [], {}
    fields, methods = {}, {}
    recs = {}           # short name -> complete record (the stub's bases are looked up here)

    def find(n, ns):
        nonlocal S
        if _from_include(n):
            return
        k = n.get("kind")
        if k == "NamespaceDecl":
            ns = ns + [n.get("name", "")]
        if k == "CXXRecordDecl" and n.get("name") and n.get("completeDefinition") and not n.get("isImplicit"):
            recs.setdefault(n["name"], n)
        if k == "CXXRecordDecl" and n.get("name") == sshort and not n.get("isImplicit") and ns == sns:
            if n.get("completeDefinition"):
                if S is not None:
                    raise SwapFail("two definitions of the stub")
                S = n
            else:
                fwds.append(n)
        for c in n.get("inner", []):
            if k == "CXXRecordDecl" and c.get("kind") == "CXXRecordDecl" and c.get("isImplicit"):
                continue
            find(c, ns)
    find(ast, [])
    if S is None:
        raise SwapFail("no definition of the stub")
    sid = S["id"]

    # The stub's bases (b13/b8 base chain): the primary chain (first base of each level, at offset 0) gives the
    # virtual slot order, root first, and its non-virtual members may be called through the stub; a secondary base
    # contributes fields only (by absolute offset in the stub's layout). Virtual bases are refused.
    def bases_of(r):
        out = []
        for b in r.get("bases") or []:
            if b.get("isVirtual"):
                raise SwapFail("stub has a virtual base")
            bn = re.sub(r"^(class|struct) ", "", gh._clean_qt(b["type"]["qualType"])).split("::")[-1]
            if bn not in recs:
                raise SwapFail("stub base %s is not a class the source defines" % bn)
            out.append(recs[bn])
        return out
    chain = [S]
    while chain[0].get("bases"):
        chain.insert(0, bases_of(chain[0])[0])
    allr, todo = {}, [S]
    while todo:
        r = todo.pop()
        if r["id"] not in allr:
            allr[r["id"]] = r
            todo.extend(bases_of(r))
    primary = {r["id"] for r in chain}
    vnames = []
    for r in chain + [r for r in allr.values() if r["id"] not in primary]:
        own_v = set()
        for c in r.get("inner", []):
            k = c.get("kind")
            if k == "FieldDecl":
                fields[c["id"]] = (c.get("name"), c["type"]["qualType"], r["name"])
            elif k in ("CXXMethodDecl", "CXXConstructorDecl", "CXXDestructorDecl") and not c.get("isImplicit"):
                if r["id"] not in primary:
                    continue        # a secondary base's members: calls to them stay unresolved (refused below)
                methods[c["id"]] = c
                if c.get("virtual"):
                    nm = "~" if k == "CXXDestructorDecl" else c.get("name")
                    if nm in own_v:
                        raise SwapFail("overloaded virtual %s" % nm)
                    own_v.add(nm)
                    if nm not in vnames:    # an override in a later level reuses the base's slot
                        vnames.append(nm)
            elif k == "VarDecl":
                raise SwapFail("static data member")
            elif k == "CXXRecordDecl" and not c.get("isImplicit"):
                raise SwapFail("nested class")
    hslots = h["slots"]
    hfields = {o: (t, n) for o, t, n in h["fields"] if not n.startswith("_pad_")}
    layout = None
    sb, se = gh._rng(S)
    edits = []          # (pos, order, end, text)
    nv_used = set()

    def need_layout():
        nonlocal layout
        if layout is None:
            lay = clang_layouts(path)
            if lay is None:
                raise SwapFail("clang can't lay out the original")
            layout = lay.get(sshort, {})
        return layout

    def visit(n, parent, depth):
        k = n.get("kind")
        try:
            b0, e0 = gh._rng(n)
        except SwapFail:
            b0 = e0 = None
        inside = b0 is not None and sb <= b0 < se
        if inside:
            return
        if k in ("CXXMethodDecl", "CXXConstructorDecl", "CXXDestructorDecl") and n.get("parentDeclContextId") == sid:
            raise SwapFail("the source defines a member of the stub")
        if k == "CXXNewExpr" or k == "CXXDeleteExpr":
            if sshort in json.dumps(n.get("type", {})) or sshort in json.dumps(n.get("inner", [{}])[0].get("type", {})):
                raise SwapFail("new/delete of the stub")
        if k == "CXXConstructExpr" and re.search(r"\b%s\b" % re.escape(sshort), n.get("type", {}).get("qualType", "")) \
                and "*" not in n.get("type", {}).get("qualType", ""):
            # (b8: the derived class's constructor initializing its stub base is fine; the header class's own
            # constructor then builds the base part, which verification checks)
            if not (base_ok and parent is not None and parent.get("kind") == "CXXCtorInitializer"
                    and "baseInit" in parent):
                raise SwapFail("the stub is constructed (by value)")
        if k == "UnaryExprOrTypeTraitExpr" and sshort in json.dumps(n):
            raise SwapFail("sizeof/alignof of the stub")
        if k in ("VarDecl", "FieldDecl", "ParmVarDecl"):
            qt = n.get("type", {}).get("qualType", "")
            if re.search(r"\b%s\b" % re.escape(sshort), qt) and not re.search(r"\b%s\b\s*(const\s*)?[*&]" % re.escape(sshort), qt):
                raise SwapFail("the stub is used by value (%s)" % qt[:40])
        if k == "CXXRecordDecl" and n.get("bases") and not base_ok:
            for bs in n["bases"]:
                if re.search(r"\b%s\b" % re.escape(sshort), bs.get("type", {}).get("qualType", "")):
                    raise SwapFail("the stub is a base class")
        if k == "DeclRefExpr" and n.get("referencedDecl", {}).get("id") in methods:
            raise SwapFail("member pointer to a stub method")
        if k == "MemberExpr":
            rid = n.get("referencedMemberDecl")
            if rid not in fields and rid not in methods:
                return
            base = n.get("inner", [{}])[0]
            ub = gh._unwrap(base)
            via_this = ub.get("kind") == "CXXThisExpr"
            if via_this and not base_ok:
                raise SwapFail("implicit member access outside the stub")
            # (base_ok, b8: the stub is the base of a class the source defines, whose members reach the stub's
            # fields and virtuals through `this`; they are renamed the same way)
            name_pos = n["range"]["end"]["offset"]
            if rid in fields:
                fnm, fqt, frec = fields[rid]
                hit = need_layout().get((frec, fnm))
                if hit is None:
                    raise SwapFail("no layout for field %s" % fnm)
                off = hit[0]
                if off not in hfields:
                    raise SwapFail("field +0x%x not in the header" % off)
                ht, hn = hfields[off]
                if gh.type_size(ht.replace(" ", "")) not in (None, 0) and False:
                    pass
                if _norm(fqt) == _norm(ht):
                    edits.append((name_pos, (2, 0), e0, hn))
                else:
                    if _is_float(fqt) != _is_float(ht):
                        raise SwapFail("field +0x%x: stub %s vs header %s" % (off, fqt, ht))
                    edits.append((b0, (1, depth), b0, "(*(%s)&" % gh._ptr_to(fqt)))
                    edits.append((name_pos, (2, 0), e0, hn))
                    edits.append((e0, (0, -depth), e0, ")"))
                return
            m = methods[rid]
            if m.get("virtual"):
                nm = "~" if m.get("kind") == "CXXDestructorDecl" else m.get("name")
                i = vnames.index(nm)
                if i >= len(hslots):
                    raise SwapFail("stub virtual %d beyond the header's vftable" % i)
                hi = hslots[i]
                if hi[2] == "~" or nm == "~":
                    raise SwapFail("calls the destructor slot")
                if parent is None or parent.get("kind") != "CXXMemberCallExpr":
                    raise SwapFail("virtual member used other than in a call")
                args = parent.get("inner", [])[1:]
                sparams = _fn_params(m)
                hparams = hi[3]
                if len(args) != len(hparams) or len(sparams) != len(hparams):
                    raise SwapFail("slot %d arity: stub %d vs header %d" % (i, len(sparams), len(hparams)))
                for a, sp, hp in zip(args, sparams, hparams):
                    if _norm(sp) == _norm(hp):
                        continue
                    if _is_float(sp) or _is_float(hp):
                        raise SwapFail("slot %d: stub %s vs header %s" % (i, sp, hp))
                    ab, ae = gh._rng(a)
                    edits.append((ab, (1, depth + 2), ab, "(%s)(" % hp))
                    edits.append((ae, (0, -(depth + 2)), ae, ")"))
                sret, hret = _fn_ret(m["type"]["qualType"]), hi[1]
                if _norm(sret) != _norm(hret) and _norm(sret) != "void":
                    if _norm(hret) == "void":
                        raise SwapFail("slot %d returns void in the header" % i)
                    if _is_float(sret) != _is_float(hret):
                        raise SwapFail("slot %d returns %s, stub %s" % (i, hret, sret))
                    pb, pe = gh._rng(parent)
                    edits.append((pb, (1, depth - 1), pb, "((%s)(" % sret))
                    edits.append((pe, (0, -(depth - 1)), pe, "))"))
                edits.append((name_pos, (2, 0), e0, hi[2]))
                return
            if any(x.get("kind") == "CompoundStmt" for x in m.get("inner", [])):
                raise SwapFail("calls an inline non-virtual stub helper")
            if m.get("kind") != "CXXMethodDecl" or m.get("storageClass") == "static":
                raise SwapFail("uses a constructor/destructor/static member")
            if via_this:
                raise SwapFail("calls a non-virtual stub member through this")
            nv_used.add(rid)
            bb, be = gh._rng(base)
            if n.get("isArrow"):
                edits.append((bb, (1, depth), bb, "((__NV*)("))
                edits.append((be, (0, -depth), be, "))"))
            else:
                dot = raw.index(".", be)
                edits.append((bb, (1, depth), bb, "((__NV*)&("))
                edits.append((be, (0, -depth), be, "))"))
                edits.append((dot, (2, 0), dot + 1, "->"))

    _walk(ast, visit)
    order = sorted(edits, key=lambda e: (e[0], e[1]))
    out, cur = [], 0
    # file-level cuts: the stub's definition (-> the nv declaration struct) and its forward declarations
    nvname = "%s_nv_%x" % (short(real), addr)
    nv_decls = []
    for rid in sorted(nv_used):
        mb, me = gh._rng(methods[rid])
        nv_decls.append("    " + raw[mb:me].strip().rstrip(";") + ";")
    semi = raw.find(";", se)
    if semi < 0 or raw[se:semi].strip():
        raise SwapFail("no ';' after the stub")
    cuts = [(sb, semi + 1, ("struct %s {\n%s\n};" % (nvname, "\n".join(nv_decls))) if nv_decls else "")]
    for fw in fwds:
        b, e = gh._rng(fw)
        j = raw.find(";", e)
        if j >= 0 and re.fullmatch(r"\s*(struct|class|union)\s+%s\s*" % re.escape(sshort), raw[b:j]):
            cuts.append((b, j + 1, ""))
    allx = sorted([(p, o, e, t) for p, o, e, t in order] + [(b, (3, 0), e, t) for b, e, t in cuts],
                  key=lambda x: (x[0], x[1]))
    for pos, _, end, text in allx:
        if pos < cur:
            if _[0] == 3:
                raise SwapFail("an edit inside a removed declaration")
            raise SwapFail("overlapping rewrites")
        out.append(raw[cur:pos])
        out.append(text)
        cur = end
    out.append(raw[cur:])
    new = "".join(out)
    # other names that collide with the header's (short names, as gen-swap does)
    items = cxx_items.parse(new)
    own_names = {it.key[1].split("::")[-1] for it in items if it.kind in ("class", "fwd", "typedef", "enum") and it.key}
    own_names |= {it.name for it in items if it.kind in ("var", "func") and it.name and not it.name.startswith(("FUN_", "DAT_"))}
    hit = sorted(n for n in own_names if n in taken and n != sshort)
    derived = {r.get("name") for r in recs.values()
               if any(re.search(r"\b%s\b" % re.escape(sshort), b.get("type", {}).get("qualType", ""))
                      for b in r.get("bases") or [])} if base_ok else set()
    for nm in hit:
        if nm in keep and nm not in derived:
            # (b8: the source's own class derived from the stub may take the placeholder suffix: in a TU on
            # include/gen/ its real name is the header's class)
            raise SwapFail("would rename %s, which is its real class's name" % nm)
        if re.search(r"\b%s\b" % re.escape(nm), eq):
            raise SwapFail("colliding name %s named on an equiv-* line" % nm)
        if member_uses(new, nm):
            raise SwapFail("colliding name %s is also a member name" % nm)
        rn = "%s_%x" % (nm, addr)
        if re.search(r"\b%s\b" % re.escape(rn), new):
            raise SwapFail("the source already uses %s" % rn)
        new = tok_edit(new, lambda i, toks, nm=nm, rn=rn: rn if toks[i].v == nm else None)
    # the stub's name -> the real class (nothing to rename when the stub already has the real qualified name);
    # `struct S` -> `X`; the nv struct's placeholder
    same = re.sub(r"^::", "", stub) == re.sub(r"^::", "", real)
    if sns and not same:
        raise SwapFail("namespaced stub of another name")
    qreal = re.sub(r"^::", "", real)
    if re.search(r"\bnamespace\b", new):
        qreal = "::" + qreal

    def ren(i, toks):
        t = toks[i]
        if t.v == "__NV":
            return nvname
        if same or t.v != sshort:
            return None
        if i >= 1 and toks[i - 1].v in (".", "->", "::"):
            raise SwapFail("the stub's name is also a member or qualified name")
        return qreal
    new = tok_edit(new, ren)
    if not same:
        new = re.sub(r"\b(struct|class|union)\s+(%s)\b" % re.escape(qreal), r"\2", new)
    hdr = '#include "gen/%s"' % h["header"]
    if hdr not in new:
        new = insert_include(new, hdr)
    return new, "%s->%s%s" % (stub, real, (" (+%s)" % ",".join(hit)) if hit else "")


def insert_include(text, line):
    nl = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(nl)
    i = 0
    while i < len(lines) and (lines[i].strip().startswith("//") or not lines[i].strip()
                              or re.match(r'\s*#\s*include\s*"(gen|decls|compat)/', lines[i])):
        i += 1
    while i > 0 and not lines[i - 1].strip():
        i -= 1
    return nl.join(lines[:i] + [line] + lines[i:])


def load_hdb():
    return json.load(open(os.path.join(ROOT, "build/rn1/header-db.json")))


def gen_taken():
    """Short names include/gen/ declares (classes, forward declarations, template families) and its namespace names:
    a stub of the same short name in a source that includes a header collides (gen-swap's rule)."""
    out = set()
    gdir = os.path.join(ROOT, "include/gen")
    for fn in os.listdir(gdir):
        if not fn.endswith(".h"):
            continue
        text = open(os.path.join(gdir, fn), encoding="latin1").read()
        out |= set(re.findall(r"^\s*namespace\s+(\w+)", text, re.M))
        out |= set(re.findall(r"^\s*(?:template\s*<[^>]*>\s*)?(?:class|struct|union)\s+(\w+)", text, re.M))
    return out
