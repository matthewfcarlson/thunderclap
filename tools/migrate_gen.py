#!/usr/bin/env python3
"""Rewrite matches/ (and equivalent/) sources onto shared headers so the source tree (tools/gen_tree.py) can merge
them: include/gen/ (the RTTI class headers, tools/gen_headers.py) and include/decls/ (pinned prototypes of
address names). Re-runnable, logged, and every rewrite is verified before it is kept (docs/source-tree.md).

  build/venv/bin/python tools/migrate_gen.py                          # gen family: plan + verify in a scratch dir
  build/venv/bin/python tools/migrate_gen.py --apply                  # ... and rewrite what still verifies
  build/venv/bin/python tools/migrate_gen.py --apply --equivalent     # also equivalent/ (equiv.py --inputs 3000)
  build/venv/bin/python tools/migrate_gen.py --family pin --apply     # pin-decl
  build/venv/bin/python tools/migrate_gen.py --family ns --apply      # rtti-ns / clone-ns
  build/venv/bin/python tools/migrate_gen.py --only matches/0x0004e980.cpp --show
  build/venv/bin/python tools/migrate_gen.py --family pin --no-verify --show    # plan only, compile nothing
  build/venv/bin/python tools/migrate_gen.py --family rn --batch build/rn1/batches/c1-unclash-matches-refined.json --apply

Rules. The target is the build/functions.csv name of the source's address.

  gen family (target `X::vfunc_N`, X an RTTI class):
  gen-swap        X a plain class. The stub of X goes; the definition becomes `R ns::X::vfunc_N(...)` against
                  include/gen/<ns>.h (gen_headers.swap_transform: stub fields -> the header's proven `f_XX` fields,
                  stub virtual calls -> the header's slot names, parameters cast to the header's types in a
                  prologue, non-virtual stub helpers on a `<X>_nv_<addr>` declaration struct, other stubs whose
                  names collide with generated classes renamed `<Name>_<addr>`).
  clone-template  X a template instantiation (`fight::ParamFloatConstRange<CFoo>`, `Method1<CActorManager,bool,
                  math::Vector>`): the same rewrite as an explicit specialization,
                  `template <> R fight::ParamFloatConstRange<CFoo>::vfunc_6(...)`. Clone-propagated sources (the
                  donor's stub class, `ParamIntConstRange::vfunc_6`) get the target's own mangled name this way.
  gen-nv          target `FUN_x`, a non-virtual member include/gen/ declares in X (batch b9, tools/rn_members.py):
                  the gen-swap rewrite onto `R ns::X::FUN_x(...)`, the source's only out-of-line member definition.
  gen-dtor        the slot is X's destructor and the stub body is the plain scalar deleting destructor (base
                  destructor call, `operator delete` when bit 0 of the flags is set, `return this`): the source
                  becomes `X::~X() {}` (or `template <> X<...>::~X() {}`); MSVC generates the ??_G function from it.
  pin family:
  pin-decl        the source's own declarations of the names in include/decls/address.h go; it includes the header
                  instead. For a pinned variable whose type is a class the source defines (`extern Global_10aa90*
                  DAT_004dd700;`), that class is renamed to the pinned type (`World`): the tree merges the World
                  stubs where their layouts agree.
  ns family (only sources whose TU is not on include/gen/, where the move can't collide with the header):
  rtti-ns         the global stub of the target's own namespaced RTTI class moves into its namespace
                  (`struct FaceTargetAction` -> `namespace hulkfight { namespace ai { struct FaceTargetAction`).
  clone-ns        a clone defining its donor's `A::m` for target `ns::B::m`: A becomes ns::B (reconcile_stubs.py's
                  clone-class rule for namespaced targets).
  rn family (docs/consolidation-plan.md; one batch file of `tools/rn_plan.py --batches` per run; the rewrites are
  in tools/rn_transform.py; log build/migrate-rn.log, list build/rn-migrated.txt, originals build/rn-orig/):
  unclash         a private stub named like an include/gen/ class but of another class (tools/rn_map.py) takes the
                  real class's name with the source's placeholder suffix (`CTrack` -> `ConditionFactory_23d3d0`).
  gen-ref         a stub the source only uses goes onto its include/gen/ class (fields -> `f_XX`, virtual calls ->
                  the header's slot names, non-virtual calls through a `<Class>_nv_<addr>` declaration struct).
  A source's batch items are applied in order (gen-ref first); an item that fails is left out, the others kept.

Identifiers are renamed token by token (comments, strings, preprocessor lines and `// equiv-*` lines keep their
bytes; a rule refuses a source whose equiv-* lines name what it would change); the leading comment block and any
`// cl-flags:` line stay first, and the `#include` goes right after them.

A rewrite is kept only if it still verifies: matches/ must MATCH under tools/compare.py (first output line);
equivalent/ must be EQUIVALENT under tools/equiv.py --inputs 3000 (when it isn't, the unchanged source is run
under the same checker and both lines are recorded, to tell pre-existing failures from regressions). Kept rewrites
go to the source, the text before the first rewrite to build/gen-orig/<path>, the path to build/gen-migrated.txt
and a JSON line to build/migrate-gen.log. Re-running plans nothing for a source that is already rewritten.

Not handled (reported as skips): destructor slots with more than the plain body, stubs with several bases, fields
include/gen/ doesn't have, sources with preprocessor lines, equivalent/ sources shadowed by a matches/ source,
and whatever swap_transform can't express.
"""
import argparse
import collections
import csv
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import gen_headers as gh  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
LOG = os.path.join(ROOT, "build/migrate-gen.log")
ORIG = os.path.join(ROOT, "build/gen-orig")
CHANGED = os.path.join(ROOT, "build/gen-migrated.txt")
SCRATCH = os.path.join(ROOT, "build/gen-mig-scratch")
PY = os.path.join(ROOT, "build/venv/bin/python")
VFUNC = re.compile(r"(.*)::vfunc_(\d+)$")
EQUIV_LINE = re.compile(r"//\s*equiv-[\w-]+:?(.*)")


def load_names():
    out = {}
    with open(os.path.join(ROOT, "build/functions.csv")) as f:
        for r in csv.DictReader(f):
            out[int(r["address"], 16)] = r["name"]
    return out


def tok_rename(text, old, new):
    """Rename identifier tokens `old` -> `new`; comments, strings and preprocessor lines untouched."""
    try:
        toks = cxx_items.tokenize(text)
    except ValueError:
        raise gh.SwapFail("can't tokenize for a rename")
    out, last = [], 0
    for t in toks:
        if t.t == "id" and t.v == old:
            out.append(text[last:t.s])
            out.append(new)
            last = t.e
    out.append(text[last:])
    return "".join(out)


def clean_cpp_name(n):
    """'::fight::X< ::CFoo, ::math::Vector >' -> 'fight::X<CFoo, math::Vector>' (keeps `> >`)."""
    n = n.strip()
    n = re.sub(r"^::", "", n)
    n = re.sub(r"(?<=[<,(])\s*::", "", n)
    n = re.sub(r"<\s+", "<", n)
    n = re.sub(r"(?<=[^>\s])\s+>", ">", n)
    n = n.replace(" ,", ",")
    return n


def leading_comments(text):
    """Length of the leading block of `//` comment lines and blank lines (kept first in the rewrite)."""
    pos = 0
    for line in text.splitlines(True):
        s = line.strip()
        if s.startswith("//") or not s:
            pos += len(line)
            continue
        break
    return pos


class Gen:
    _g = None

    @classmethod
    def get(cls):
        if cls._g is None:
            ev = json.load(open(gh.EVIDENCE_PATH)) if os.path.exists(gh.EVIDENCE_PATH) else {}
            g = gh.Gen(ev)
            with tempfile.TemporaryDirectory() as d:
                g.generate(d, None)
            cls._g = g
        return cls._g


def transform(g, path, target):
    """(rule, new text, header, class) for one source, or raises SwapFail."""
    m = VFUNC.match(target)
    addr = int(re.search(r"0x([0-9a-fA-F]{8})\.cpp$", path).group(1), 16)
    suf = "_%x" % addr
    raw = open(path, encoding="latin1", newline="").read()
    if not m:
        # gen-nv (batch b9): a non-virtual member the header declares (gen_headers "members", tools/rn_members.py)
        C, ret, params, quals = g.nv_owner[target]
        rule = "gen-nv"
        keep = ({t for k, t in load_pins().values() if k == "var"}
                if re.search(r'#\s*include\s*"decls/address\.h"', raw) else ())
        text, _, _sig = gh.swap_transform(g, path, target, rename=tok_rename, stub_suffix=suf,
                                          nv=(C, target, (ret, params, quals), None), keep=keep)
    else:
        C = g.by_csv[m.group(1)]
        rule = "clone-template" if C.targs is not None else "gen-swap"
        if g.name_of(g.resolve(C, 0, int(m.group(2)))) == "~":
            return dtor_transform(g, C, raw)
        text, _ = gh.swap_transform(g, path, target, rename=tok_rename, stub_suffix=suf)
    head, sep, rest = text.partition("\n")                      # '#include <gen/all.h>'
    tdef, sep, rest = rest.partition("\n")                      # 'typedef ... __Self;'
    if not head.startswith("#include <gen/all.h>") or not tdef.startswith("typedef "):
        raise gh.SwapFail("unexpected swap output")
    real = clean_cpp_name(tdef[len("typedef "):-len(" __Self;")])
    # swap_transform adds `using namespace <stub's namespace>;` before the definition. A member's body looks in
    # its class's namespaces anyway; where the stub's namespace is another one, the rewrite compiles without the
    # directive or it is rejected
    rest = re.sub(r"^\s*using namespace [\w:]+;\s*\n", "", rest, flags=re.M)
    # the non-virtual helper declaration struct: drop it when empty, else give it a per-source name
    rest = re.sub(r"struct __Self_nv \{\s*\};\n?", "", rest)
    rest = tok_rename(rest, "__Self_nv", "%s_nv%s" % (C.short, suf))
    rest = tok_rename(rest, "__Self", real)
    # the header goes after the leading comment block; tidy the blank lines the cuts left
    n = leading_comments(rest)
    hdr = '#include "gen/%s.h"\n' % C.unit.header
    lead = rest[:n].rstrip("\n") + "\n" if rest[:n].strip() else ""
    body = rest[n:]
    body = re.sub(r"\n{3,}", "\n\n", body).lstrip("\n")
    nl = "\r\n" if "\r\n" in raw else "\n"
    out = lead + hdr + "\n" + body
    if not out.endswith("\n"):
        out += "\n"
    if nl == "\r\n":
        out = out.replace("\r\n", "\n").replace("\n", "\r\n")
    return rule, out, C.unit.header + ".h", C.name


# a hand-written scalar deleting destructor whose destructor body is empty: the base destructor, then
# `operator delete` when bit 0 of the flags is set
SIMPLE_DTOR = re.compile(r"^\{ (\w+)\(\); if \(\(?(\w+) & 1\)?(?: != 0)?\) \{? ?(\w+)\(this\); \}? ?return this; \}$")


def dtor_transform(g, C, raw):
    """gen-dtor: a destructor slot whose stub body is SIMPLE_DTOR becomes `X::~X() {}` on include/gen/; MSVC
    generates the scalar deleting destructor (??_G, the slot's function) from it in the same object."""
    try:
        items = cxx_items.parse(raw)
    except ValueError:
        raise gh.SwapFail("does not parse")
    defs = [it for it in items if it.kind == "funcdef" and not it.is_inline]
    if len(defs) != 1:
        raise gh.SwapFail("target is a destructor slot (not exactly one definition)")
    d = defs[0]
    body = re.sub(r"\s+", " ", d.text[d.text.index("{"):]).replace("( ", "(").replace(" )", ")")
    mm = SIMPLE_DTOR.match(body)
    if not mm:
        raise gh.SwapFail("target is a destructor slot (body is not base-dtor + delete)")
    real = clean_cpp_name(g.cpp_name(C))
    lead = raw[:leading_comments(raw)].rstrip("\n")
    nl = "\r\n" if "\r\n" in raw else "\n"
    out = (lead + "\n" if lead else "") + '#include "gen/%s.h"\n\n' % C.unit.header
    out += "// scalar deleting destructor: %s() is the base destructor, %s() operator delete\n" % (mm.group(1), mm.group(3))
    out += "%s%s::~%s() {}\n" % ("template <> " if C.targs is not None else "", real, C.short)
    if nl == "\r\n":
        out = out.replace("\r\n", "\n").replace("\n", "\r\n")
    rule = "gen-dtor"
    return rule, out, C.unit.header + ".h", C.name


# `#include "decls/..."` and `#include "compat/..."` (compat/ptr.h: the pointer-sized integer typedefs of the
# 64-bit respellings, identical types on the 32-bit builds) are allowed in a rewritten source
DECLS_INCLUDE = re.compile(r'^[ \t]*#[ \t]*include[ \t]*"(?:decls|compat)/[^"]+"[ \t]*\r?$', re.M)


def skip_reason(text, target, g, names_on_equiv=True):
    if re.search(r'#\s*include\s*[<"]gen/', text):
        return "already on include/gen/"
    # `#include "decls/..."` (the data migration's data headers, decls/address.h pins) is allowed: the rewrite keeps
    # those lines (insert_include puts the gen header after them) and every rewrite is verified as it is
    if re.search(r"^\s*#", DECLS_INCLUDE.sub("", text), re.M):
        return "preprocessor lines"
    m = VFUNC.match(target or "")
    if (not m or m.group(1) not in g.by_csv) and target not in getattr(g, "nv_owner", {}):
        return "target is not an RTTI class's vfunc_N"
    return None


def insert_include(text, line):
    """`text` with `line` (an #include) after the leading comment block and any include/ lines already there."""
    nl = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(nl)
    i = 0
    while i < len(lines) and (lines[i].strip().startswith("//") or not lines[i].strip()
                              or re.match(r'\s*#\s*include\s*"(gen|decls|compat)/', lines[i])):
        i += 1
    while i > 0 and not lines[i - 1].strip():
        i -= 1
    return nl.join(lines[:i] + [line] + lines[i:])


# ---------------------------------------------------------------------------------------------
# pin-decl: address names declared differently by different sources get one prototype in include/decls/
DECLS = "decls/address.h"
PINNED = {}       # name -> ('var', type name) | ('func', None); filled from include/decls/address.h


def load_pins():
    if PINNED:
        return PINNED
    text = open(os.path.join(ROOT, "include", DECLS), encoding="latin1").read()
    for it in cxx_items.parse(text):
        if it.kind == "var":
            vs = [t.v for t in it.toks]
            PINNED[it.name] = ("var", vs[vs.index(it.name) - 2])       # extern T * NAME ;
        elif it.kind == "func":
            PINNED[it.name] = ("func", None)
    return PINNED


def rtti_simple_names():
    out = set()
    for c in json.load(open(os.path.join(ROOT, "build/rtti.json")))["classes"]:
        n = re.sub(r"\b(class|struct|enum|union) ", "", c.get("name") or "")
        out |= set(re.findall(r"[A-Za-z_]\w*", n))
    return out


def pin_transform(rel, addr, text, rtti):
    """(rule, new text, header, names) or raises SwapFail. Removes the source's own declarations of pinned
    names, includes decls/address.h, and renames the source's private class for a pinned variable's object
    (`Global_10aa90` -> `World` for `extern Global_10aa90* DAT_004dd700;`)."""
    pins = load_pins()
    try:
        items = cxx_items.parse(text)
    except ValueError:
        raise gh.SwapFail("does not parse")
    equiv = "\n".join(m.group(1) for m in EQUIV_LINE.finditer(text))
    ids = {t.v for it in items for t in it.toks if t.t == "id"}
    cuts, renames, names = [], {}, []
    for it in items:
        if it.kind not in ("var", "func") or it.name not in pins:
            continue
        nm = it.name
        if it.kind == "func" and addr == int(nm[4:], 16):
            continue
        kind, ty = pins[nm]
        if (kind == "var") != (it.kind == "var"):
            raise gh.SwapFail("%s declared as a %s" % (nm, it.kind))
        if nm in equiv:
            raise gh.SwapFail("%s named on an equiv-* line" % nm)
        vs = [t.v for t in it.toks]
        if it.scope:
            raise gh.SwapFail("%s declared inside a namespace" % nm)
        if it.kind == "var":
            core = [v for v in vs if v not in ("extern", '"C"', "struct", "class")]
            if len(core) != 4 or core[1] != "*" or core[2] != nm or core[3] != ";":
                raise gh.SwapFail("%s: declaration is not `extern T* %s;`" % (nm, nm))
            own = core[0]
            if own != ty:
                if ty in ids:
                    raise gh.SwapFail("%s: the source already uses the name %s" % (nm, ty))
                if own in rtti or own in gh_names():
                    raise gh.SwapFail("%s: type %s is an RTTI / include/gen/ class" % (nm, own))
                defs = [x for x in items if x.kind == "class" and x.key[1] == own]
                if len(defs) != 1:
                    raise gh.SwapFail("%s: type %s is not a class the source defines" % (nm, own))
                if own in equiv:
                    raise gh.SwapFail("%s named on an equiv-* line" % own)
                others = [x for x in items if x.kind == "var" and x is not it and own in {t.v for t in x.toks}]
                if others:
                    raise gh.SwapFail("%s: type %s also types %s" % (nm, own, others[0].name))
                if ty in renames.values():
                    raise gh.SwapFail("two private types for %s" % ty)
                renames[own] = ty
        s0, e0 = it.toks[0].s, it.toks[-1].e
        # the whole line when the declaration is alone on it
        ls = text.rfind("\n", 0, s0) + 1
        le = text.find("\n", e0)
        le = len(text) if le < 0 else le + 1
        if text[ls:s0].strip() == "" and text[e0:le].strip() == "":
            s0, e0 = ls, le
        cuts.append((s0, e0))
        names.append(nm)
    if not cuts:
        raise gh.SwapFail("nothing to pin")
    out, cur = [], 0
    for s0, e0 in sorted(cuts):
        out.append(text[cur:s0])
        cur = e0
    out.append(text[cur:])
    new = "".join(out)
    for old, nw in renames.items():
        new = tok_rename(new, old, nw)
    if not re.search(r'^\s*#\s*include\s*"%s"' % re.escape(DECLS), new, re.M):
        new = insert_include(new, '#include "%s"' % DECLS)
    return "pin-decl", new, DECLS, names + ["%s->%s" % kv for kv in renames.items()]


# ---------------------------------------------------------------------------------------------
# rtti-ns: a global stub of a namespaced RTTI class (`struct FaceTargetAction` for
# hulkfight::ai::FaceTargetAction) moves into its namespace
_NS_INDEX = {}


def ns_index():
    """simple name -> [namespace path] of RTTI classes whose qualifiers are namespaces (not classes); and the
    set of simple names of global RTTI classes."""
    if not _NS_INDEX:
        g = Gen.get()
        idx, glob = collections.defaultdict(set), set()
        for u in g.units.values():
            if u.outer is not None:
                continue
            if u.ns:
                idx[u.short].add(tuple(u.ns))
            else:
                glob.add(u.short)
        _NS_INDEX["idx"], _NS_INDEX["glob"] = idx, glob
    return _NS_INDEX["idx"], _NS_INDEX["glob"]


def ns_skip(text):
    if re.search(r'#\s*include\s*[<"]gen/', text):
        return "already on include/gen/"
    # `#include "decls/..."` (the data migration's data headers, decls/address.h pins) is allowed: the rewrite keeps
    # those lines (insert_include puts the gen header after them) and every rewrite is verified as it is
    if re.search(r"^\s*#", DECLS_INCLUDE.sub("", text), re.M):
        return "preprocessor lines"
    return None


def ns_transform(rel, addr, text, rtti, target):
    """The source's stub of its own target class moves into the class's namespace: `struct FaceTargetAction`
    + `FaceTargetAction::vfunc_3` for hulkfight::ai::FaceTargetAction::vfunc_3 becomes `namespace hulkfight {
    namespace ai { struct FaceTargetAction ... } }` + `hulkfight::ai::FaceTargetAction::vfunc_3`. A clone whose
    stub is its donor's class (`A::m` for target `ns::B::m`) first renames A to B (reconcile_stubs.py's
    clone-class rule for namespaced targets). Other global stubs are left alone: moving them changes no merge
    and would collide with include/gen/ in TUs that include it."""
    idx, glob = ns_index()
    if not target or "<" in target:
        raise gh.SwapFail("template or unnamed target")
    parts = gh.split_top(target, "::")
    if len(parts) < 3:
        raise gh.SwapFail("target is not a member of a namespaced class")
    ns, B, m = tuple(parts[:-2]), parts[-2], parts[-1]
    if ns not in idx.get(B, ()):
        raise gh.SwapFail("target class is not a namespaced RTTI class")
    try:
        items = cxx_items.parse(text)
    except ValueError:
        raise gh.SwapFail("does not parse")
    equiv = "\n".join(mm.group(1) for mm in EQUIV_LINE.finditer(text))
    defs = [it for it in items if it.kind == "funcdef" and not it.is_inline and not it.scope]
    if len(defs) != 1:
        raise gh.SwapFail("not exactly one out-of-line definition")
    q = defs[0].key[1]
    if "::" not in q or q.count("::") != 1:
        raise gh.SwapFail("definition is not a global class's member")
    A, m2 = q.split("::")
    if m2 != m and not (m2 == "~" + A and m.startswith("~")):
        raise gh.SwapFail("member name differs from the target's")
    rule = "rtti-ns"
    ids = {t.v for it in items for t in it.toks if t.t == "id"}
    if A != B:
        if B in ids:
            raise gh.SwapFail("clone: the source already uses %s" % B)
        if A in rtti and A not in idx:
            pass
        rule = "clone-ns"
    if any(re.search(r"\b%s\b" % re.escape(n), equiv) for n in {A, B}):
        raise gh.SwapFail("stub named on an equiv-* line")
    own = [it for it in items if not it.scope and it.kind in ("class", "fwd") and it.key[1] == A]
    if not any(it.kind == "class" for it in own):
        raise gh.SwapFail("no global definition of %s in the source" % A)
    for it in items:
        if it.kind == "class":
            vs = [t.v for t in it.toks]
            head = vs[:vs.index("{")] if "{" in vs else vs
            if ":" in head and A in head[head.index(":"):]:
                raise gh.SwapFail("%s is a base class in the source" % A)
    toks = cxx_items.tokenize(text)
    spans = [(it.toks[0].s, it.toks[-1].e) for it in own]
    qual = "::".join(ns) + "::" + B
    edits = []
    for i, t in enumerate(toks):
        if t.t != "id" or t.v != A:
            continue
        inside = any(s0 <= t.s < e0 for s0, e0 in spans)
        p = toks[i - 1].v if i else ""
        if inside or p == "~" or (p == "::" and i >= 2 and toks[i - 2].v == A):
            if A != B:
                edits.append((t.s, t.e, B))       # the class's own name (and its ctor/dtor names)
            continue
        if p in (".", "->", "::"):
            raise gh.SwapFail("%s also used as a member name" % A)
        edits.append((t.s, t.e, qual))
    for s0, e0 in spans:
        edits.append((s0, s0, " ".join("namespace %s {" % x for x in ns) + " "))
        edits.append((e0, e0, " " + "}" * len(ns)))
    edits.sort(key=lambda e: (e[0], e[1]))
    out, cur = [], 0
    for s0, e0, nt in edits:
        if s0 < cur:
            raise gh.SwapFail("overlapping edits")
        out.append(text[cur:s0])
        out.append(nt)
        cur = e0
    out.append(text[cur:])
    return rule, "".join(out), "-", ["%s->%s" % (A, qual)]


_GH_NAMES = []


def gh_names():
    if not _GH_NAMES:
        g = Gen.get()
        s = {u.short for u in g.units.values()} | {gh.split_top(q, "::")[-1] for q in g.extra_fwd}
        s |= {n for u in g.units.values() for n in u.ns}
        _GH_NAMES.append(s)
    return _GH_NAMES[0]


def compare_cli(path, addr):
    """tools/compare.py's first output line for `path` at `addr`."""
    r = subprocess.run([PY, os.path.join(ROOT, "tools/compare.py"), path, "0x%08x" % addr], capture_output=True,
                       text=True, cwd=ROOT, errors="replace")
    out = (r.stdout or "").strip().splitlines()
    return out[0] if out else (r.stderr.strip().splitlines() or ["(no output)"])[-1]


def equiv_cli(path, addr, inputs):
    """tools/equiv.py's verdict ('equivalent', 'fail', ...) and its first output line."""
    r = subprocess.run([PY, os.path.join(ROOT, "tools/equiv.py"), path, "0x%08x" % addr, "--inputs", str(inputs)],
                       capture_output=True, text=True, cwd=ROOT, errors="replace", timeout=3600)
    out = (r.stdout or "") + (r.stderr or "")
    first = out.strip().splitlines()[0] if out.strip() else "(no output)"
    m = re.match(r"\s*(\w+)", first)
    return (m.group(1).lower() if m else "error"), first


def rn_apply(rel, addr, text, items, hdb, taken, work):
    """rn family: apply a source's batch items in order (gen-ref first: it reads the stubs' original AST, then the
    renames). (rule, new text, header, what); an item that fails is left out, SwapFail if none applies."""
    import rn_transform
    tmp = os.path.join(work, "rn-ast", os.path.dirname(rel))
    os.makedirs(tmp, exist_ok=True)
    p = os.path.join(tmp, os.path.basename(rel))
    rules, whats, fails, hdrs = [], [], [], set()
    keep = set(items[0].get("keep", ())) if items else set()
    for it in sorted(items, key=lambda x: x["rule"] not in ("gen-ref", "gen-base")):
        try:
            if it["rule"] == "unclash":
                new, what = rn_transform.unclash_transform(text, addr, it["stub"], it["real"])
            elif it["rule"] == "relabel":
                new, what = rn_transform.unclash_transform(text, addr, it["stub"], it["real"], it.get("new"))
            elif it["rule"] in ("gen-ref", "gen-base"):
                with open(p, "w", encoding="latin1", newline="") as f:
                    f.write(text)
                new, what = rn_transform.genref_transform(p, text, it["stub"], it["real"], hdb, addr, taken, keep,
                                                          base_ok=it["rule"] == "gen-base")
                hdrs.add("gen/" + hdb[it["real"]]["header"])
            else:
                raise gh.SwapFail("unknown rule %s" % it["rule"])
        except gh.SwapFail as e:
            fails.append("%s %s: %s" % (it["rule"], it["stub"], e))
            continue
        text = new
        rules.append(it["rule"])
        whats.append(what)
    if not rules:
        raise gh.SwapFail(fails[0] if len(fails) == 1 else "; ".join(fails)[:200] if fails else "nothing to do")
    rule = "+".join(sorted(set(rules), key=rules.index))
    return rule, text, ",".join(sorted(hdrs)) or "rn/none", "; ".join(whats) + (" [failed: %s]" % "; ".join(fails) if fails else "")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true", help="rewrite the sources that still verify")
    ap.add_argument("--only", nargs="*", help="limit to these source paths")
    ap.add_argument("--family", choices=("gen", "pin", "ns", "rn"), default="gen",
                    help="gen: gen-swap + clone-template (default); pin: pin-decl; ns: rtti-ns; rn: a --batch file")
    ap.add_argument("--rule", choices=("gen-swap", "clone-template", "gen-dtor", "gen-nv", "pin-decl", "rtti-ns", "clone-ns",
                                       "unclash", "gen-ref", "gen-base", "relabel"),
                    action="append")
    ap.add_argument("--batch", help="rn family: the batch file (tools/rn_plan.py --batches)")
    ap.add_argument("--equivalent", action="store_true", help="also equivalent/ sources (checked with equiv.py)")
    ap.add_argument("--equiv-inputs", type=int, default=3000)
    ap.add_argument("--limit", type=int)
    ap.add_argument("--jobs", type=int, default=4, help="compiler/checker processes (default 4; shared box)")
    ap.add_argument("--show", action="store_true", help="print the rewritten text")
    ap.add_argument("--no-verify", action="store_true", help="plan only: rewrite into the scratch dir, compile nothing")
    a = ap.parse_args(argv)
    if a.family == "rn":
        if not a.batch:
            ap.error("--family rn needs --batch")
        global LOG, ORIG, CHANGED
        LOG = os.path.join(ROOT, "build/migrate-rn.log")
        ORIG = os.path.join(ROOT, "build/rn-orig")
        CHANGED = os.path.join(ROOT, "build/rn-migrated.txt")
    g = Gen.get()
    names = load_names()
    rtti = rtti_simple_names() if a.family != "gen" else set()
    gen_tu_srcs = set()
    if a.family == "ns":
        # a stub moved into its namespace collides with the include/gen/ class in a TU that includes the
        # header (measured: -48 merged over all candidates, +113 when only TUs off include/gen/ are touched)
        import gen_tree
        gt = gen_tree.generate(None, write=False)
        gen_tu_srcs = {b.path for t in gt.tus if t.gen for b in t.blocks}
    if a.family == "pin":
        pins = load_pins()
    rn_items = collections.defaultdict(list)
    if a.family == "rn":
        import rn_transform
        batch = json.load(open(a.batch))
        for it in batch["items"]:
            if a.rule and it["rule"] not in a.rule:
                continue
            rn_items[it["source"]].append(it)
        rn_hdb, rn_taken = rn_transform.load_hdb(), rn_transform.gen_taken()
    dirs = ("matches", "equivalent") if a.equivalent else ("matches",)
    in_matches = {int(f[2:10], 16) for f in os.listdir(os.path.join(ROOT, "matches")) if f.endswith(".cpp")}
    todo, skipped = [], collections.Counter()
    for d in dirs:
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if not re.fullmatch(r"0x[0-9a-fA-F]{8}\.cpp", fn):
                continue
            rel = "%s/%s" % (d, fn)
            if a.only and rel not in a.only:
                continue
            addr = int(fn[2:10], 16)
            if d == "equivalent" and addr in in_matches:
                continue
            text = open(os.path.join(ROOT, rel), encoding="latin1", newline="").read()
            if a.family == "pin":
                # (a source that includes decls/address.h but still declares a pinned name itself, e.g. one pinned
                # since, is rewritten too: pin_transform drops its own declaration)
                why = None if any(n in text for n in pins) else "no pinned name"
            elif a.family == "ns":
                why = ns_skip(text) or ("its TU is on include/gen/" if rel in gen_tu_srcs else None)
            elif a.family == "rn":
                why = None if rel in rn_items else "not in the batch"
            else:
                why = skip_reason(text, names.get(addr), g)
            if why:
                skipped[why] += 1
                continue
            todo.append((rel, addr, names.get(addr), text))
    os.makedirs(SCRATCH, exist_ok=True)
    work = tempfile.mkdtemp(prefix="mig-", dir=SCRATCH)

    def plan_one(item):
        rel, addr, target, text = item
        try:
            if a.family == "pin":
                rule, new, hdr, cls = pin_transform(rel, addr, text, rtti)
            elif a.family == "ns":
                rule, new, hdr, cls = ns_transform(rel, addr, text, rtti, target)
            elif a.family == "rn":
                rule, new, hdr, cls = rn_apply(rel, addr, text, rn_items[rel], rn_hdb, rn_taken, work)
            else:
                rule, new, hdr, cls = transform(g, os.path.join(ROOT, rel), target)
        except gh.SwapFail as e:
            return rel, addr, None, "rewrite: " + str(e), None
        except Exception as e:  # noqa: BLE001 - one odd source must not stop the run
            return rel, addr, None, "rewrite crash: %s %s" % (type(e).__name__, str(e)[:60]), None
        if a.rule and a.family != "rn" and rule not in a.rule:
            return rel, addr, None, "rule %s not selected" % rule, None
        if a.family == "gen" and a.equivalent and EQUIV_LINE.search(text):
            # equiv-* annotations may name stub types or mangled names the rewrite changes
            for m in EQUIV_LINE.finditer(text):
                if re.search(r"\b%s\b" % re.escape(cls.split("::")[-1].split("<")[0]), m.group(1)):
                    return rel, addr, None, "stub named on an equiv-* line", None
        sub = os.path.join(work, os.path.dirname(rel))
        os.makedirs(sub, exist_ok=True)
        p = os.path.join(sub, os.path.basename(rel))
        with open(p, "w", encoding="latin1", newline="") as f:
            f.write(new)
        return rel, addr, (rule, new, hdr, cls, p), None, None

    with ThreadPoolExecutor(a.jobs) as ex:
        planned = list(ex.map(plan_one, todo[:a.limit] if a.limit else todo))
    for rel, addr, ok, why, _ in planned:
        if why:
            skipped[re.sub(r"\+0x[0-9a-f]+|\b\d+\b", "N", why)[:90]] += 1
    cands = [(rel, addr, ok) for rel, addr, ok, why, _ in planned if ok]
    print("candidates: %d rewritten in %s (%d sources looked at)" % (len(cands), os.path.relpath(work, ROOT), len(todo)))

    def verify_one(c):
        rel, addr, (rule, new, hdr, cls, p) = c
        if rel.startswith("matches/"):
            line = compare_cli(p, addr)
            return c, line.startswith("MATCH"), line, None
        v_new, l_new = equiv_cli(p, addr, a.equiv_inputs)
        if v_new != "equivalent":
            v_old, l_old = equiv_cli(os.path.join(ROOT, rel), addr, a.equiv_inputs)
            return c, False, l_new, "original: " + l_old
        return c, True, l_new, None

    if a.no_verify:
        for why, n in skipped.most_common(25):
            print("  %6d  %s" % (n, why))
        for rel, addr, (rule, new, hdr, cls, p) in cands[:10] if a.show else []:
            print("==== %s (%s) %s\n%s" % (rel, rule, cls, new))
        return 0
    with ThreadPoolExecutor(a.jobs) as ex:
        results = list(ex.map(verify_one, cands))
    kept = [(c, line) for c, ok, line, _ in results if ok]
    st = collections.Counter()
    for c, ok, line, extra in results:
        st[(c[2][0], "kept" if ok else "rejected: " + re.sub(r"\s.*", "", line)[:20])] += 1
    for k, v in sorted(st.items()):
        print("  %-15s %-30s %d" % (k[0], k[1], v))
    print("skipped:")
    for why, n in skipped.most_common(25):
        print("  %6d  %s" % (n, why))
    with open(os.path.join(work, "results.json"), "w") as f:
        json.dump([{"file": c[0], "rule": c[2][0], "ok": ok, "line": line, "original": extra}
                   for c, ok, line, extra in results], f, indent=1)
    if a.show:
        for (rel, addr, (rule, new, hdr, cls, p)), line in kept[:20]:
            print("==== %s (%s) %s\n%s" % (rel, rule, line, new))
    if not a.apply:
        return 0
    n = 0
    orig_text = {r: t for r, _, _, t in todo}
    with open(LOG, "a") as log, open(CHANGED, "a") as ch:
        for (rel, addr, (rule, new, hdr, cls, p)), line in kept:
            src = os.path.join(ROOT, rel)
            cur = open(src, encoding="latin1", newline="").read()
            if cur != orig_text[rel]:
                print("changed meanwhile, skipped:", rel)
                continue
            keep = os.path.join(ORIG, rel)
            if not os.path.exists(keep):
                os.makedirs(os.path.dirname(keep), exist_ok=True)
                shutil.copyfile(src, keep)
            with open(src, "w", encoding="latin1", newline="") as f:
                f.write(new)
            log.write(json.dumps({"file": rel, "rule": rule, "header": hdr if "/" in hdr else "gen/" + hdr, "what": cls,
                                  "verified": line}) + "\n")
            ch.write(rel + "\n")
            n += 1
    print("rewrote %d sources (log: %s, list: %s, originals: %s)" % (
        n, os.path.relpath(LOG, ROOT), os.path.relpath(CHANGED, ROOT), os.path.relpath(ORIG, ROOT)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
