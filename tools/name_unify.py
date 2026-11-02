#!/usr/bin/env python3
"""Name unification (x64-6): rewrite sources so that their references name the definition's own symbol, the
link resolving them without an alias (tools/name_audit.py measures what is left).

  build/venv/bin/python tools/name_unify.py data --bindings B.json --snap SNAP --out DIR [--root R]
        [--exclude LIST ...] [--only PATH ...]

`data`: a source's own top-level declaration of a global that the Wine link binds to an emitted data item
(config/data.json) by relocation position, under an invented name (`extern int gCount;`, `extern "C" float
Threshold;`, `static const char* luaerr;` declared extern) or under its address name with C++ linkage
(`extern float DAT_003f32dc;`, a TU-namespace symbol in the tree), becomes a use of the item's C symbol:

  1. the invented name takes the item's address name `DAT_<addr>` (tools/rn_transform.pin_data_transform:
     token-level, refused where the name is also a member name, on an `// equiv-*` line, or the source already
     uses the address name);
  2. the declaration goes and the owner's `include/decls/data/<layer>/<dir>.h` comes in its place
     (tools/migrate_data.transform: a cast at each use where the source's type differs, interior offsets).

The address of each name comes from the binding map of a Wine build of the same sources (`bindings.json`:
tree symbol -> address, by relocation position or equiv.py's pairing), looked up under the source's tree
namespace (the TU's `fn_f<7 hex>` when merged, `fn_<addr>` when wrapped or isolated, from SNAP, the clang probe's
snapshot of that build). Names bound to two addresses (`ambiguous`) are left alone. R (default: the checkout) is
the tree whose sources are read; rewrites go to DIR/<path> with DIR/plan.jsonl (one line per source: renames,
migrate rules, or why not). Nothing is verified here: compare.py + verify_relocs.py (matches/) and equiv.py
(equivalent/) run on DIR afterwards, through the queue.

  build/venv/bin/python tools/name_unify.py free --link DIR --snap SNAP --out OUT
  build/venv/bin/python tools/name_unify.py free-apply --plan OUT/free-plan.jsonl --top N --out DIR2
        [--exclude LIST ...] [--manifest build/tree/manifest.json]

`free` / `free-apply` (batch 2, free functions -> C linkage): per definition address, the free -> free aliases
(name_audit) become one C name (`FUN_<addr>`): the definition gets `extern "C"` (renamed when its own name is
invented), callers keep their own types and convention with `extern "C"` and the C name. Left alone: callees and
definitions named on an `// equiv-*` line (equiv.py finds those by their C++ symbol), callers' address names of
another address (`thunk_FUN_x` is the thunk, not x), and with --manifest (a Wine build's tree manifest of the same
sources) every C name a TU's sources would declare with more than one signature (two `extern "C"` declarations of
one name must agree in a merged TU; gen_tree's spelling is the 32-bit one, so `hulk_uintptr` vs `unsigned int`
counts as different too: the arm64 front end rejects it).

  build/venv/bin/python tools/name_unify.py free-apply ... --manifest M --canonical

`--canonical` (batch 3, x64-8): a (TU, C name) pair tu_consistency holds back takes one prototype in every source of
the TU that declares the name (canon_plan / canon_transform): the definition's own, with a pointer to a non-builtin
type said `void *` (each source names its own stub struct for it) and builtin typedefs said as their type. Callers
keep their types at the call (`((Cam *)FUN_x((Cam *)c, n))`: the argument is converted to the caller's declared type
first, so a derived -> base adjustment still happens); a definition in the TU takes `void *` parameters and says
`((Foo *)p)` at each use (a typed local copy moved MSVC's register allocation; equivalents may use one when the body
assigns the parameter). All of a pair's sources or none; refusals are listed in the summary (sizes, kinds or arity
that differ, a void return used, address taken, other conventions). An `// equiv-conv` line no longer holds back a
name that keeps its name (equiv.py round 27 resolves C-linkage functions by C name and declared types).
"""
import argparse
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import migrate_data  # noqa: E402
import name_audit  # noqa: E402
import rn_transform  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
WIDE = re.compile(r"\b(hulk_u?intptr|hulk_freg|size_t|ptrdiff_t|u?intptr_t|U?LONG_PTR|DWORD_PTR|U?INT_PTR|SIZE_T|long)\b")
ADDR_NAME = re.compile(r"(?:^|_)(?:FUN|thunk_FUN|LAB)_[0-9a-fA-F]{6,8}$")
DATA_SYM = re.compile(r"\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)*)@[23]")


def data_index(bindings):
    """(name, source scopes, generator namespace or None) -> address, for the data symbols of the binding map."""
    idx = {}
    amb = set(bindings.get("ambiguous", {}))
    for s, b in bindings["bindings"].items():
        if s in amb or "$" in s:
            continue
        m = DATA_SYM.match(s)
        if m:
            scopes = [x for x in m.group(2).split("@") if x]
            gen = [x for x in scopes if re.fullmatch(r"fn_[0-9a-f]{8}", x)]
            src = tuple(reversed([x for x in scopes if not re.fullmatch(r"fn_[0-9a-f]{8}", x)]))
            key = (m.group(1), src, gen[0] if gen else None)
        elif re.fullmatch(r"_[A-Za-z_]\w*", s):
            key = (s[1:], (), None)
        else:
            continue
        a = int(b["addr"], 16)
        if key in idx and idx[key] != a:
            idx[key] = None
        else:
            idx[key] = a
    return idx


def source_namespaces(snap):
    """source path -> generator namespaces its top-level names get in the tree."""
    ns_src, src_tu = name_audit.tu_map(snap)
    out = collections.defaultdict(list)
    for ns, srcs in ns_src.items():
        for s in srcs:
            out[s].append(ns)
    return out, src_tu


def plan_data(text, rel, nss, idx, model):
    """(renames {old: DAT_x}, names already DAT_x) for one source, or raises SwapFail."""
    try:
        items = cxx_items.parse(text)
    except ValueError:
        raise rn_transform.SwapFail("does not parse")
    renames, same = {}, set()
    for it in items:
        if it.kind != "var":
            continue
        try:
            head, decs = migrate_data.declarators(it.toks)
        except Exception:  # noqa: BLE001
            continue
        for st, nm, dims, a0, a1 in decs:
            if not nm:
                continue
            a = None
            for ns in list(nss) + [None]:
                v = idx.get((nm, tuple(it.scope), ns))
                if v is not None:
                    a = v
                    break
            if a is None:
                continue
            addr_name = "DAT_%08x" % a
            if model.target(addr_name) is None:
                continue
            if nm == addr_name:
                same.add(nm)
            elif re.fullmatch(r"DAT_[0-9a-f]{8}", nm):
                continue        # (an address name bound elsewhere: interior / another item; not a rename)
            else:
                renames[nm] = addr_name
    return renames, same


def name_comment(text, renames):
    """Keep the descriptive names a rewrite replaced (`zeroCondition`, `luaerr`; not `A`, `g134`, `table2`) as one
    comment line under the data includes: `// data: zeroCondition = DAT_003f335c`."""
    words = sorted((o, n) for o, n in renames.items() if re.search(r"[a-z]{3}", o) and
                   not re.fullmatch(r"(g|table|tab|data|dat|ptr|val|var|value)_?\d*[0-9a-f]*", o, re.I))
    if not words:
        return text
    nl = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(nl)
    at = max((i for i, l in enumerate(lines) if re.match(r'\s*#\s*include\s*"decls/data/', l)), default=None)
    if at is None:
        return text
    out, cur = [], "// data:"
    for o, n in words:
        part = " %s = %s" % (o, n)
        if len(cur) + len(part) + 1 > 118 and cur != "// data:":
            out.append(cur.rstrip(","))
            cur = "// data:"
        cur += part + ","
    out.append(cur.rstrip(","))
    return nl.join(lines[:at + 1] + out + lines[at + 1:])


def cmd_data(a):
    bindings = json.load(open(a.bindings))
    idx = data_index(bindings)
    nss, src_tu = source_namespaces(a.snap)
    model = migrate_data.Model()
    excl = set()
    for p in a.exclude or []:
        for line in open(p):
            line = line.strip().split()[0] if line.strip() else ""
            if re.match(r"(matches|equivalent)/0x[0-9a-f]{8}\.cpp$", line):
                excl.add(line)
    root = os.path.abspath(a.root)
    todo = []
    for d in ("matches", "equivalent"):
        for fn in sorted(os.listdir(os.path.join(root, d))):
            rel = "%s/%s" % (d, fn)
            if not re.fullmatch(r"0x[0-9a-f]{8}\.cpp", fn) or (a.only and rel not in a.only):
                continue
            todo.append(rel)
    os.makedirs(a.out, exist_ok=True)
    st = collections.Counter()
    with open(os.path.join(a.out, "plan.jsonl"), "w") as plan:
        for rel in todo:
            text = open(os.path.join(root, rel), encoding="latin1", newline="").read()
            ns = nss.get(rel, [])
            if rel not in src_tu:
                continue        # (not in the tree: shadowed equivalent/, library objects)
            try:
                renames, same = plan_data(text, rel, ns, idx, model)
            except rn_transform.SwapFail as e:
                st["plan: " + str(e)] += 1
                continue
            if not renames and not same:
                continue
            rec = {"path": rel, "mode": src_tu[rel][1], "tu": src_tu[rel][0], "renames": renames,
                   "same": sorted(same)}
            if rel in excl:
                rec["skip"] = "claimed / changed (excluded)"
                st["excluded"] += 1
                plan.write(json.dumps(rec) + "\n")
                continue
            new = text
            try:
                if renames:
                    new, _ = rn_transform.pin_data_transform(new, renames)
                rules, new, hdrs, notes = migrate_data.transform(model, rel, new)
            except (rn_transform.SwapFail, migrate_data.Fail) as e:
                rec["skip"] = str(e)
                st["refused: " + re.sub(r"\b(DAT_[0-9a-f]{8}|\w+)\b(?= (is|named|declared|used|needs|keeps))", "N",
                                       str(e))[:70]] += 1
                plan.write(json.dumps(rec) + "\n")
                continue
            except Exception as e:  # noqa: BLE001
                rec["skip"] = "crash: %s %s" % (type(e).__name__, str(e)[:80])
                st["crash"] += 1
                plan.write(json.dumps(rec) + "\n")
                continue
            new = name_comment(new, renames)
            rec.update(rules=rules, headers=hdrs, notes=notes)
            p = os.path.join(a.out, rel)
            os.makedirs(os.path.dirname(p), exist_ok=True)
            with open(p, "w", encoding="latin1", newline="") as f:
                f.write(new)
            st["rewritten " + rel.split("/")[0]] += 1
            plan.write(json.dumps(rec) + "\n")
    for k, v in st.most_common():
        print("%6d  %s" % (v, k))
    return 0


# ------------------------------------------------------------------------------------------- free functions
BUILTIN = {"void", "bool", "char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int",
           "long", "unsigned long", "__int64", "unsigned __int64", "float", "double", "long double", "wchar_t"}


def canon_type(t):
    """A demangled parameter / return type in header terms: builtin scalars kept, a pointer to anything else
    `void *` (one level; `const void *` for a pointer to const). None when it can't be said that way
    (references, class values, function pointers, pointers to pointers to non-builtins)."""
    t = name_audit.strip_ns(t).strip()
    t = re.sub(r"\b(struct|class|union|enum) ", "", t)
    if "(" in t or "&" in t or "<" in t:
        return None
    m = re.fullmatch(r"(.*?)((?:\s*\*\s*(?:const\s*)?)*)", t)
    base, stars = m.group(1).strip(), m.group(2)
    n = stars.count("*")
    const = base.endswith(" const") or base.startswith("const ")
    base = re.sub(r"^const |\s+const$", "", base).strip()
    if base in BUILTIN:
        if n == 0:
            return base
        return ("const " if const else "") + base + " " + "*" * n
    if n == 1:
        return "const void *" if const else "void *"
    if n == 0 and re.fullmatch(r"[A-Za-z_]\w*", base):
        return None       # (a class or enum by value)
    return None


def split_params(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "<(":
            depth += 1
        elif ch in ">)":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return [p.strip() for p in out]


def canon_prototype(dem, name):
    """`void * __cdecl fn_x::FUN_0008d690(int)` -> `extern "C" void * __cdecl FUN_0008d690(int);`, or (None, why)."""
    m = re.fullmatch(r"(.*?)\s*\b(__cdecl|__stdcall|__fastcall)\s+([\w:]+)\((.*)\)", dem)
    if not m:
        return None, "signature shape"
    ret = canon_type(m.group(1))
    if ret is None:
        return None, "return type %s" % m.group(1)
    ps = split_params(m.group(4))
    if ps == ["void"]:
        ps = []
    if "..." in ps:
        return None, "variadic"
    cps = [canon_type(p) for p in ps]
    if any(c is None for c in cps):
        return None, "parameter type %s" % ps[cps.index(None)]
    return 'extern "C" %s %s %s(%s);' % (ret, m.group(2), name, ", ".join(cps) or "void"), None


def known_names():
    out = {}
    with open(os.path.join(ROOT, "build/functions.csv")) as f:
        import csv
        for r in csv.DictReader(f):
            if re.fullmatch(r"[A-Za-z_]\w*", r["name"]) and not r["name"].startswith(("FUN_", "thunk_", "LAB_")):
                out[int(r["address"], 16)] = r["name"]
    return out


def free_kind(s, dem):
    if not s.startswith("?"):
        return True
    d = dem.get(s, s)
    return not s.startswith("??") and "__thiscall" not in d and "virtual" not in d and "static " not in d


def cmd_free(a):
    """Plan: per definition address, the free -> free aliases (name_audit), the canonical C name and prototype, the
    definition source and the caller sources (those of the referencing namespace that declare the caller's name)."""
    rows = [r for r in name_audit.classify(a.link, a.snap) if r[0] == "game" and r[1].startswith("function:")]
    bindings = json.load(open(os.path.join(a.link, "bindings.json")))
    defs = {v: int(k, 16) for k, v in bindings["definitions"].items()}
    dem = name_audit.undname({r[3] for r in rows} | {r[4] for r in rows})
    nss, src_tu = source_namespaces(a.snap)
    by_addr_src = {int(p.split("/")[1][2:10], 16): p for p in src_tu}
    known = known_names()
    root = os.path.abspath(a.root)
    cache = {}

    def items(p):
        if p not in cache:
            try:
                cache[p] = cxx_items.parse(open(os.path.join(root, p), encoding="latin1").read())
            except (OSError, ValueError):
                cache[p] = []
        return cache[p]
    groups = collections.defaultdict(list)
    for kind, cat, n, s, t, srcs in rows:
        if t in defs and free_kind(s, dem) and free_kind(t, dem):
            groups[defs[t]].append((cat, n, s, t, srcs))
    plans = []
    for A, rs in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        t = rs[0][3]
        tdem = dem.get(t, t) if t.startswith("?") else None
        ti = name_audit.ident(name_audit.qual_name(name_audit.plain(t, dem))) if t.startswith("?") else t.lstrip("_").split("@")[0]
        N = known.get(A) or "FUN_%08x" % A
        p = {"addr": "0x%08x" % A, "aliases": len(rs), "references": sum(r[1] for r in rs), "definition": by_addr_src.get(A),
             "def_symbol": t, "def_name": ti, "name": N, "c_linkage": not t.startswith("?")}
        if tdem:
            p["prototype"], why = canon_prototype(tdem, N)
            if why:
                p["refused"] = why
        callers = collections.defaultdict(set)
        unattributed = 0
        for cat, n, s, t_, srcs in rs:
            ci = name_audit.ident(name_audit.qual_name(name_audit.plain(s, dem))) if s.startswith("?") else s.lstrip("_@").split("@")[0]
            hit = [q for q in set(srcs) if any(it.kind == "func" and it.name == ci for it in items(q))]
            if not hit:
                unattributed += 1
            for q in hit:
                callers[q].add(ci)
        p["callers"] = {q: sorted(v) for q, v in sorted(callers.items())}
        p["unattributed"] = unattributed
        plans.append(p)
    os.makedirs(a.out, exist_ok=True)
    with open(os.path.join(a.out, "free-plan.jsonl"), "w") as f:
        for p in plans:
            f.write(json.dumps(p) + "\n")
    st = collections.Counter()
    for p in plans:
        st["refused: " + p["refused"].split()[0] if p.get("refused") else "plannable"] += p["aliases"]
    print("%d definitions, %d aliases" % (len(plans), sum(p["aliases"] for p in plans)))
    for k, v in st.most_common():
        print("%7d  %s" % (v, k))
    return 0


def free_transform(text, calls, define=None):
    """One source's part of the free-function batch. `calls`: {caller name: (C name, canonical prototype)} for the
    source's own top-level declarations of callees; `define`: (own name, C name) when the source defines one of
    the batch's functions. Declarations get `extern "C"` (their own types and convention kept), uses take the C
    name, the definition gets `extern "C"` (and the C name). Raises SwapFail."""
    try:
        items = cxx_items.parse(text)
    except ValueError:
        raise rn_transform.SwapFail("does not parse")
    eq = rn_transform.equiv_text(text)
    eq_other = "\n".join(m.group(0) for m in re.finditer(r"//\s*equiv-(?!conv\b)[\w-]+:?.*", text))

    def on_equiv_line(ci, N):
        # (batch 3: an `// equiv-conv` line naming a function that keeps its name is fine, equiv.py round 27
        # convcname/cdeclret resolves a C-linkage callee or definition by its C name and declared types)
        if ci == N:
            return bool(re.search(r"\b%s\b" % re.escape(ci), eq_other))
        return any(re.search(r"\b%s\b" % re.escape(n), eq) for n in (ci, N))
    # left alone: a callee named on an `// equiv-*` line other than equiv-conv, or renamed (equiv.py finds it by
    # its own name), and a caller's address name of another address (`thunk_FUN_x` is the thunk's own address,
    # not x: the rename would skip the thunk)
    calls = {ci: v for ci, v in calls.items() if not on_equiv_line(ci, v[0])
             and not (ADDR_NAME.search(ci) and ci != v[0])}
    if define and on_equiv_line(*define):
        define = None
    cuts, renames = [], {}
    for ci, (N, proto) in calls.items():
        decl = [it for it in items if it.kind == "func" and it.name == ci and not it.scope]
        if not decl:
            raise rn_transform.SwapFail("no top-level declaration of %s" % ci)
        if any(it.kind == "funcdef" and it.name == ci for it in items):
            raise rn_transform.SwapFail("%s also defined here" % ci)
        for it in decl:
            vs = [t.v for t in it.toks]
            if "static" in vs or "inline" in vs or "template" in vs or "operator" in vs:
                raise rn_transform.SwapFail("%s: static/inline/template declaration" % ci)
            if it.c_linkage:
                continue
            # (the caller keeps its own types and convention: a C name's symbol carries neither types nor a
            # namespace, so the link is exact; `extern` becomes `extern "C"`)
            if vs[0] == "extern":
                cuts.append((it.toks[0].s, it.toks[0].e, 'extern "C"'))
            else:
                cuts.append((it.toks[0].s, it.toks[0].s, 'extern "C" '))
        if ci != N:
            renames[ci] = N
    if define:
        own, N = define
        ds = [it for it in items if it.name == own and it.kind in ("func", "funcdef") and not it.scope]
        if not any(it.kind == "funcdef" for it in ds):
            raise rn_transform.SwapFail("definition of %s not found at top level" % own)
        for it in ds:
            vs = [t.v for t in it.toks]
            if "static" in vs or "inline" in vs or "template" in vs or "::" in vs[:vs.index("(") if "(" in vs else 0]:
                raise rn_transform.SwapFail("%s: static/inline/template/qualified definition" % own)
            if not it.c_linkage:
                cuts.append((it.toks[0].s, it.toks[0].s, 'extern "C" '))
        if own != N:
            renames[own] = N
    for old, new in renames.items():
        if re.search(r"\b%s\b" % re.escape(old), eq):
            raise rn_transform.SwapFail("%s named on an equiv-* line" % old)
        if rn_transform.member_uses(text, old):
            raise rn_transform.SwapFail("%s is also a member name" % old)
        if re.search(r"\b%s\b" % re.escape(new), text):
            raise rn_transform.SwapFail("the source already uses %s" % new)
    if not cuts and not renames:
        raise rn_transform.SwapFail("nothing to do")
    out, cur = [], 0
    for s0, e0, new in sorted(cuts):
        if s0 < cur:
            raise rn_transform.SwapFail("overlapping edits")
        out.append(text[cur:s0])
        out.append(new)
        cur = e0
    out.append(text[cur:])
    new = "".join(out)
    if renames:
        def ren(i, toks):
            t = toks[i]
            if t.v not in renames or (i and toks[i - 1].v in (".", "->", "::")):
                return None
            return renames[t.v]
        new = rn_transform.tok_edit(new, ren)
    return new


def tu_consistency(per_src, manifest, root, excl, detail=None):
    """{source: {C names}} to hold back. Two `extern "C"` declarations of one name with other types can't share
    a merged TU (gen_tree: a conflict, the sources wrap), while C++ declarations of them were overloads. So per
    TU of the manifest (tools/gen_tree.py's build/tree/manifest.json of a build of the same sources) and per C
    name of the batch: when the TU's sources (every one, rewritten or not) declare or define that name, under
    their own name or the one the batch renames to it, with more than one signature (gen_tree's canonical
    spelling), no source of the TU takes the C name for it."""
    import gen_tree
    m = json.load(open(manifest))
    tu_of, members = {}, collections.defaultdict(list)
    for t in m["tus"]:
        key = t["path"].split(".iso_")[0] + ".cpp" if ".iso_" in t["path"] else t["path"]
        for b in t["blocks"]:
            tu_of[b["src"]] = key
            members[key].append(b["src"])
    names = collections.defaultdict(set)          # TU -> C names the batch gives its sources
    for q, d in per_src.items():
        if q in excl or q not in tu_of:
            continue
        names[tu_of[q]] |= {v[0] for v in d["calls"].values()} | ({d["define"][1]} if d["define"] else set())
    held = collections.defaultdict(set)
    for tu, ns in names.items():
        sigs = collections.defaultdict(set)
        for s in members[tu]:
            try:
                src = open(os.path.join(root, s), encoding="latin1").read()
                its = cxx_items.parse(src)
            except (OSError, ValueError):
                continue
            d = per_src.get(s) if s not in excl else None
            ren = {}
            if d:
                ren = {ci: v[0] for ci, v in d["calls"].items() if not (ADDR_NAME.search(ci) and ci != v[0])}
                if d["define"]:
                    ren[d["define"][0]] = d["define"][1]
            for it in its:
                if it.kind not in ("func", "funcdef") or it.scope or not it.name:
                    continue
                n = ren.get(it.name, it.name)
                if n not in ns:
                    continue
                p = gen_tree._norm_sig_parts(it)
                if p:
                    # (a declaration's qualifiers end in its `;`, a definition's don't: the same signature)
                    p = (p[0], p[1], re.sub(r"\s*;$", "", p[2]))
                k = repr(p) if p else it.norm
                # (gen_tree's spelling is the 32-bit one: `hulk_uintptr` = `unsigned int`; a 64-bit build sees
                # two C declarations of other types)
                k += repr(WIDE.findall(src[it.toks[0].s:it.toks[-1].e]))
                if not gen_tree.ADDR_NAME.search(n):
                    # (C vs C++ linkage counts as one spelling only for address names)
                    k += " C" if (it.c_linkage or it.name in ren) else " C++"
                sigs[n].add(k)
        for n, ss in sigs.items():
            if len(ss) > 1:
                for s in members[tu]:
                    held[s].add(n)
                if detail is not None:
                    detail.setdefault("pairs", set()).add((tu, n))
    if detail is not None:
        detail["members"], detail["tu_of"] = members, tu_of
    return held


# ---------------------------------------------------------------------------------------------------------------
# batch 3 (x64-8): canonical prototypes. A C name that a merged TU's sources declare with more than one signature
# (tu_consistency) takes one prototype in all of them: the definition's own, with every pointer to a non-builtin
# type said `void *` (`const void *` for a pointer to const; each source names its own struct for it). Callers
# keep their own types at the call: each argument whose declared type differs is cast to it first (`(T *)(arg)`,
# so a derived -> base adjustment still happens), and the result is cast back to the caller's return type. The
# definition, when its prototype changes, takes `void *` parameters under another name and its typed one as a local
# (`Foo *p = (Foo *)p_;`), returns through a cast to its own type. Refused (the name stays held in that TU): sizes
# that differ (an `int` for a `char`, a pointer for an integer, `float` for `double`), bool for a non-bool return,
# a void return used by a caller, arity, references, class values, function pointers, arrays, uses other than a
# direct call, calling conventions that differ, default arguments.
INT_SIZES = {"bool": 1, "char": 1, "signed char": 1, "unsigned char": 1, "short": 2, "short int": 2,
             "unsigned short": 2, "unsigned short int": 2, "signed short": 2, "wchar_t": 2, "int": 4, "signed": 4,
             "signed int": 4, "unsigned": 4, "unsigned int": 4, "long": 4, "long int": 4, "signed long": 4,
             "unsigned long": 4, "unsigned long int": 4, "__int64": 8, "unsigned __int64": 8, "long long": 8,
             "unsigned long long": 8, "__int32": 4, "unsigned __int32": 4, "__int16": 2, "unsigned __int16": 2,
             "__int8": 1, "unsigned __int8": 1}
FLT_SIZES = {"float": 4, "double": 8, "long double": 8}
BUILTIN_WORDS = {"void", "bool", "char", "short", "int", "long", "signed", "unsigned", "float", "double", "wchar_t",
                 "__int64", "__int32", "__int16", "__int8"}
CONVS = ("__cdecl", "_cdecl", "__stdcall", "__fastcall")
DROP_WORDS = {"extern", '"C"', "static", "inline", "__inline", "__forceinline", "register"}


class _TdTok:
    """A typedef name's token standing for the builtin type it names (`r`: its spelling)."""
    __slots__ = ("t", "v", "s", "e", "r")

    def __init__(self, t, v):
        self.t, self.v, self.s, self.e, self.r = "id", v, t.s, t.e, v


def _raw(text, ts):
    return " ".join(getattr(t, "r", None) or text[t.s:t.e] for t in ts)


def builtin_typedefs(items):
    """{typedef name: builtin type words} of a source's top-level `typedef <builtin type> Name;` items."""
    td = {}
    for it in items:
        if it.kind != "typedef" or it.scope or not it.name:
            continue
        vs = [t.v for t in it.toks]
        if len(vs) < 4 or vs[0] != "typedef" or vs[-1] != ";" or vs[-2] != it.name:
            continue
        ws = [td.get(v, v) for v in vs[1:-2] if v not in ("const", "volatile")]
        if ws and all(w in BUILTIN_WORDS for w in " ".join(ws).split()) and "void" not in ws:
            td[it.name] = " ".join(ws)
    return td


def type_info(text, ts, td=None):
    """(info, name token) of a parameter or return type's tokens. info: ('ptr', raw, pointee const, builtin
    pointee, stars) | ('int', size, raw, bool) | ('flt', size, raw) | ('void',) | ('var',) | None. td: the
    source's builtin typedefs (builtin_typedefs), said as the type they name."""
    ts = [(_TdTok(t, td[t.v]) if td and t.t == "id" and t.v in td else t) for t in ts]
    vs = [t.v for t in ts]
    if "=" in vs:
        return None, None             # (default argument)
    name = None
    if len(ts) > 1 and ts[-1].t == "id" and ts[-1].v not in cxx_items.KEYWORDS and vs[-2] not in (
            "::", "struct", "class", "enum", "union"):
        name = ts[-1]
        ts, vs = ts[:-1], vs[:-1]
    if vs == ["..."]:
        return ("var",), None
    if any(v in ("(", "&", "[", "<", "...") for v in vs) or not ts:
        return None, name
    if "*" not in vs and "::" in vs:
        return None, name
    if "*" in vs:
        k = vs.index("*")
        base = [v for v in vs[:k] if v not in ("const", "volatile", "struct", "class", "union", "enum", "::")]
        if vs[0] == "enum" or not base:
            return None, name
        tail = vs[k:]
        while tail and tail[-1] in ("const", "volatile"):        # top-level cv of the pointer itself
            tail = tail[:-1]
        n = tail.count("*")
        if any(v not in ("*", "const", "volatile") for v in tail):
            return None, name
        bi = all(w in BUILTIN_WORDS for w in " ".join(base).split())
        rts = ts[:k] + [t for t in ts[k:k + len(tail)]]
        return ("ptr", _raw(text, rts), "const" in vs[:k], bi, n), name
    words = " ".join(v for v in vs if v not in ("const", "volatile", "register", "signed") or v == "signed" and len(vs) == 1)
    if vs and vs[0] == "signed" and len(vs) > 1:
        words = " ".join(v for v in vs[1:] if v not in ("const", "volatile"))
        if words == "char":
            words = "signed char"
    raw = _raw(text, [t for t in ts if t.v not in ("const", "volatile", "register")])
    if words == "void":
        return ("void",), name
    if words in INT_SIZES:
        return ("int", INT_SIZES[words], raw, words == "bool"), name
    if words in FLT_SIZES:
        return ("flt", FLT_SIZES[words], raw), name
    return None, name


def fn_parts(text, it, td=None):
    """A top-level function declaration / definition split up, or raise SwapFail."""
    ts = it.toks
    vs = [t.v for t in ts]
    end = vs.index("{") if it.kind == "funcdef" else len(vs)
    k = next((j for j in range(end - 1) if vs[j] == it.name and vs[j + 1] == "(" and ts[j].t == "id"), None)
    if k is None:
        raise rn_transform.SwapFail("%s: declarator not found" % it.name)
    rp = cxx_items._match(ts, k + 1, "(", ")")
    pre = ts[:k]
    j = 0
    ret = []
    conv = None
    while j < len(pre):
        v = pre[j].v
        if v == "__declspec":
            j = cxx_items._match(pre, j + 1, "(", ")") + 1
            continue
        if v in CONVS:
            conv = "__cdecl" if v == "_cdecl" else v
        elif v in ("template", "operator", "virtual", "friend", "typedef"):
            raise rn_transform.SwapFail("%s: %s" % (it.name, v))
        elif v not in DROP_WORDS:
            ret.append(pre[j])
        j += 1
    params, cur, depth = [], [], 0
    for t in ts[k + 2:rp]:
        if t.v in ("(", "[", "<"):
            depth += 1
        elif t.v in (")", "]", ">"):
            depth -= 1
        if t.v == "," and depth == 0:
            params.append(cur)
            cur = []
        else:
            cur.append(t)
    if cur:
        params.append(cur)
    if len(params) == 1 and [t.v for t in params[0]] == ["void"]:
        params = []
    rinfo, _ = type_info(text, ret, td)
    pinfo = [type_info(text, p, td) for p in params]
    return {"name_i": k, "lp": k + 1, "rp": rp, "ret": ret, "rinfo": rinfo, "params": params,
            "pinfo": [p[0] for p in pinfo], "pnames": [p[1] for p in pinfo], "conv": conv or "__cdecl",
            "body": end if end < len(vs) else None}


def canon_of(info):
    """The canonical spelling of a definition's type."""
    if info[0] == "ptr":
        _, raw, const, bi, n = info
        if bi:
            return re.sub(r"\s+", " ", raw.replace("*", " *")).strip().replace("* *", "**")
        return "const void *" if const and n == 1 else "void *"
    if info[0] in ("int", "flt"):
        return re.sub(r"\s+", " ", info[2]).strip()
    if info[0] == "void":
        return "void"
    return "..."


def canon_decl(name, d):
    ps = [canon_of(i) for i in d["pinfo"]]
    return '%s %s %s(%s)' % (canon_of(d["rinfo"]), d["conv"], name, ", ".join(ps) or "void")


def _norm_t(s):
    return re.sub(r"\s+", "", s)


def arg_cast(pc, pk):
    """Prefix casts for an argument declared pc by the caller, pk by the canonical prototype; '' when none is
    needed; raise SwapFail when they can't be bridged."""
    if pc is None or pk is None:
        raise rn_transform.SwapFail("parameter type")
    if pc[0] == "int" and pk[0] == "ptr" and pc[1] == 4 and not pc[3]:
        # (a caller that passes a pointer the definition takes in a 32-bit integer: the same bits on the 32-bit
        # build; on a 64-bit one the caller's integer was already too narrow. The other way round, a
        # definition that takes a pointer in an integer, is left for a width fix of the definition.)
        return "(%s)(hulk_uintptr)(%s)" % (canon_of(pk), pc[2])
    if pc[0] != pk[0] or pc[0] in ("void",):
        raise rn_transform.SwapFail("parameter kinds differ (%s / %s)" % (pc[0], pk[0]))
    if pc[0] == "var":
        return ""
    if pc[0] == "ptr":
        # (cast to the caller's own type first even when it names the definition's: a derived -> base
        # conversion the caller's declaration did implicitly must still adjust before `void *`)
        ck = canon_of(pk)
        if _norm_t(pc[1]) == _norm_t(ck) or pc[3] and _norm_t("const " + pc[1]) == _norm_t(ck):
            return ""       # (the same type, or const added to a builtin pointee: no class, no adjustment)
        if ck in ("void *", "const void *") and (not pc[2] or ck == "const void *"):
            return "(%s)" % pc[1]
        return "(%s)(%s)" % (ck, pc[1])
    if pc[1] != pk[1] or pc[0] == "int" and pc[3] != pk[3]:
        raise rn_transform.SwapFail("parameter sizes differ (%s / %s)" % (pc[2], pk[2]))
    if pc[0] == "flt":
        if _norm_t(pc[2]) != _norm_t(pk[2]):
            raise rn_transform.SwapFail("float parameter types differ")
        return ""
    if _norm_t(pc[2]) == _norm_t(pk[2]):
        return ""
    return "(%s)" % pc[2]


def ret_cast(rc, rk):
    """Cast of the call's value for a caller's return type rc and the canonical rk: '' / '(T)' / 'void'."""
    if rc is None or rk is None:
        raise rn_transform.SwapFail("return type")
    if rc[0] == "void":
        return "" if rk[0] == "void" else "void"
    if rk[0] == "void":
        raise rn_transform.SwapFail("the caller uses a void return")
    if rc[0] == "int" and rk[0] == "ptr" and rc[1] == 4 and not rc[3]:
        return "(%s)(hulk_uintptr)" % rc[2]           # (as in arg_cast)
    if rc[0] != rk[0]:
        raise rn_transform.SwapFail("return kinds differ (%s / %s)" % (rc[0], rk[0]))
    if rc[0] == "ptr":
        if _norm_t(rc[1]) == _norm_t(canon_of(rk)):
            return ""
        return "(%s)" % rc[1]
    if rc[1] != rk[1] or rc[0] == "int" and rc[3] != rk[3]:
        raise rn_transform.SwapFail("return sizes or bool-ness differ")
    if _norm_t(rc[2]) == _norm_t(rk[2]):
        return ""
    if rc[0] == "flt":
        raise rn_transform.SwapFail("float return types differ")
    return "(%s)" % rc[2]


def param_use_casts(ts, body, name, typ):
    """Edits that make every use of parameter `name` in a definition's body (tokens from index `body`, its `{`)
    say `((typ)name)`; SwapFail when the body assigns it, takes its address or may declare another variable of
    that name."""
    out = []
    for j in range(body + 1, len(ts) - 1):
        x = ts[j]
        if x.t != "id" or x.v != name or ts[j - 1].v in (".", "->", "::"):
            continue
        pv, nv = ts[j - 1], ts[j + 1].v
        if nv in ("=", "+=", "-=", "++", "--") or pv.v in ("&", "++", "--"):
            raise rn_transform.SwapFail("definition assigns or takes the address of %s" % name)
        if pv.t == "id" and pv.v not in cxx_items.KEYWORDS or pv.v in (">", "*") and (
                ts[j - 2].t == "id" and ts[j - 2].v not in cxx_items.KEYWORDS or ts[j - 2].v in (">", "::")):
            raise rn_transform.SwapFail("definition may declare another %s" % name)
        out.append((x.s, x.e, "((%s)%s)" % (typ, name)))
    return out


def canon_transform(text, names, define=None, local_copy=False):
    """Batch 3 for one source. names: {own name: (C name, canonical decl text, canonical parts)} for each name the
    source declares (or defines) that takes the canonical prototype; define: own name of the definition among
    them, if this is the definition source. Returns the new text or raises SwapFail."""
    try:
        items = cxx_items.parse(text)
        toks = cxx_items.tokenize(text)
    except ValueError:
        raise rn_transform.SwapFail("does not parse")
    # (`// equiv-conv: FUN_x ...` names a callee that keeps its name: equiv.py finds it by the address in the name
    # and, round 27 convcname/cdeclret, takes a C-linkage callee's types from this declaration. Other equiv-* lines,
    # and any line naming a name the batch renames, are left alone)
    eq = "\n".join(m.group(0) for m in re.finditer(r"//\s*equiv-(?!conv\b)[\w-]+:?.*", text))
    eqc = "\n".join(m.group(1) for m in re.finditer(r"//\s*equiv-conv:?(.*)", text))
    td = builtin_typedefs(items)
    edits = []                    # (start, end, replacement)
    owned = set()                 # token starts of declarator names
    need_ptr_h = False
    for ci, (N, cdecl, kd) in names.items():
        if re.search(r"\b%s\b" % re.escape(ci), eq) or (ci != N and re.search(r"\b%s\b" % re.escape(N), eq)) or (
                ci != N and re.search(r"\b(%s|%s)\b" % (re.escape(ci), re.escape(N)), eqc)):
            raise rn_transform.SwapFail("%s named on an equiv-* line" % ci)
        if rn_transform.member_uses(text, ci):
            raise rn_transform.SwapFail("%s is also a member name" % ci)
        if ci != N and re.search(r"\b%s\b" % re.escape(N), text):
            raise rn_transform.SwapFail("the source already uses %s" % N)
        if "hulk_" in cdecl and not re.search(r"\bhulk_u?(int|long)ptr\b", text) and "compat/ptr.h" not in text:
            need_ptr_h = True
        decls = [it for it in items if it.name == ci and it.kind in ("func", "funcdef")]
        if not decls:
            raise rn_transform.SwapFail("no declaration of %s" % ci)
        if any(it.scope for it in decls):
            raise rn_transform.SwapFail("%s declared in a namespace" % ci)
        own = None
        for it in decls:
            vs = [t.v for t in it.toks]
            if "template" in vs or "operator" in vs or "static" in vs or "__declspec" in vs:
                raise rn_transform.SwapFail("%s: static/template/declspec declaration" % ci)
            d = fn_parts(text, it, td)
            if it.kind == "func" and [t.v for t in it.toks[d["rp"] + 1:]] != [";"]:
                raise rn_transform.SwapFail("%s: declaration qualifiers" % ci)
            if d["conv"] != kd["conv"]:
                raise rn_transform.SwapFail("%s: calling convention differs" % ci)
            if it.kind == "funcdef":
                if ci != define:
                    raise rn_transform.SwapFail("%s also defined here" % ci)
                own = d
                continue
            if own is None:
                own = d          # (the caller's types: its first declaration)
            elif [canon_of(i) if i else None for i in d["pinfo"]] != [canon_of(i) if i else None for i in own["pinfo"]]:
                raise rn_transform.SwapFail("%s declared twice with other types" % ci)
            pre = 'extern "C" ' if it.linkage != "C" else ""
            edits.append((it.toks[0].s, it.toks[-1].e, pre + cdecl + ";"))
        if own is None:
            continue
        if define == ci:
            own = next(fn_parts(text, it, td) for it in decls if it.kind == "funcdef")
        # the definition
        for it in decls:
            if it.kind != "funcdef":
                continue
            d = fn_parts(text, it, td)
            ts = it.toks
            for p, pi, pn, ki in zip(d["params"], d["pinfo"], d["pnames"], kd["pinfo"]):
                cs = canon_of(ki)
                if pi is None:
                    raise rn_transform.SwapFail("definition parameter type")
                tt = p[:-1] if pn else p
                if not (pi[0] == "ptr" and not pi[3]):
                    if any(t.v in td for t in tt):
                        edits.append((tt[0].s, tt[-1].e, cs))     # (a builtin typedef said as its type)
                    continue
                # the parameter becomes `void *` under its own name and every use in the body says its type
                # (`((Foo *)p)`): an expression cast, no new variable, so the code doesn't change (a typed local
                # copy moved MSVC's register allocation). Refused when the body assigns it, takes its address
                # or may declare another variable of that name.
                if pn is None:
                    edits.append((tt[0].s, tt[-1].e, cs))
                    continue
                uses = []
                try:
                    if any(t.t == "pp" and re.match(r"#\s*define\b", t.v) and re.search(r"\b%s\b" % re.escape(pn.v), t.v)
                           for t in toks):
                        raise rn_transform.SwapFail("a macro uses %s" % pn.v)      # (the casts can't reach it)
                    uses = param_use_casts(ts, d["body"], pn.v, pi[1])
                    edits.append((tt[0].s, tt[-1].e, cs))
                    edits.extend(uses)
                except rn_transform.SwapFail:
                    if not local_copy:
                        raise
                    # (an equivalent: a typed local copy of a `void *` parameter behaves the same)
                    nn = pn.v + "_"
                    if re.search(r"\b%s\b" % re.escape(nn), text):
                        raise rn_transform.SwapFail("%s already used" % nn)
                    edits.append((p[0].s, p[-1].e, "%s %s" % (cs, nn)))
                    b = ts[d["body"]]
                    edits.append((b.e, b.e, "\n    %s %s = (%s)%s;" % (pi[1], pn.v, pi[1], nn)))
            ri = d["rinfo"]
            rk = canon_of(kd["rinfo"])
            if ri is None:
                raise rn_transform.SwapFail("definition return type")
            if not (ri[0] == "ptr" and not ri[3]):
                if any(t.v in td for t in d["ret"]):
                    edits.append((d["ret"][0].s, d["ret"][-1].e, rk))
            else:
                edits.append((d["ret"][0].s, d["ret"][-1].e, rk))
                # every return value is converted to the definition's own type first
                b = d["body"]
                bend = len(ts) - 1
                j = b + 1
                while j < bend:
                    if ts[j].v == "return":
                        k = j + 1
                        depth = 0
                        while k < bend and not (ts[k].v == ";" and depth == 0):
                            if ts[k].v in ("(", "[", "{"):
                                depth += 1
                            elif ts[k].v in (")", "]", "}"):
                                depth -= 1
                            k += 1
                        if k == j + 2:
                            edits.append((ts[j + 1].s, ts[j + 1].s, "(%s)" % ri[1]))
                        elif k > j + 1:
                            edits.append((ts[j + 1].s, ts[j + 1].s, "(%s)(" % ri[1]))
                            edits.append((ts[k - 1].e, ts[k - 1].e, ")"))
                        j = k
                    j += 1
            owned.add(ts[d["name_i"]].s)
            if it.linkage != "C" and [t.v for t in ts[:2]] != ["extern", '"C"']:
                edits.append((ts[0].s, ts[0].s, 'extern "C" '))
        for it in decls:
            if it.kind == "func":
                owned.add(it.toks[fn_parts(text, it)["name_i"]].s)
        # the calls
        for i, t in enumerate(toks):
            if t.t != "id" or t.v != ci or t.s in owned:
                continue
            if i and toks[i - 1].v in (".", "->", "::"):
                raise rn_transform.SwapFail("%s used qualified" % ci)
            if any(it.toks[0].s <= t.s < it.toks[-1].e for it in decls if it.kind == "func"):
                continue
            if i + 1 >= len(toks) or toks[i + 1].v != "(":
                raise rn_transform.SwapFail("%s used other than in a call" % ci)
            rp = cxx_items._match(toks, i + 1, "(", ")")
            args, cur, depth = [], [], 0
            for x in toks[i + 2:rp]:
                if x.v in ("(", "[", "{"):
                    depth += 1
                elif x.v in (")", "]", "}"):
                    depth -= 1
                if x.v == "," and depth == 0:
                    args.append(cur)
                    cur = []
                else:
                    cur.append(x)
            if cur:
                args.append(cur)
            kps = kd["pinfo"]
            variadic = kps and kps[-1][0] == "var"
            if len(args) != len(own["pinfo"]) and not (variadic and len(args) >= len(kps) - 1):
                raise rn_transform.SwapFail("%s: call arity" % ci)
            if len(own["pinfo"]) != len(kps):
                raise rn_transform.SwapFail("%s: declared arity differs" % ci)
            for a, pc, pk in zip(args, own["pinfo"], kps):
                c = arg_cast(pc, pk)
                if c and len(a) == 1 and a[0].t == "num" and pc[0] == pk[0] == "int" and "." not in a[0].v:
                    c = ""          # (an integer literal: the same value either way)
                if c and len(a) == 1:
                    edits.append((a[0].s, a[0].s, c))
                elif c:
                    edits.append((a[0].s, a[0].s, c + "("))
                    edits.append((a[-1].e, a[-1].e, ")"))
            rc = ret_cast(own["rinfo"], kd["rinfo"])
            if rc == "void":
                if toks[i - 1].v == "return":
                    edits.append((t.s, t.s, "(void)"))
            elif rc:
                edits.append((t.s, t.s, "(" + rc))
                edits.append((toks[rp].e, toks[rp].e, ")"))
    if not edits:
        raise rn_transform.SwapFail("nothing to do")
    out, cur = [], 0
    for s0, e0, new in sorted(edits, key=lambda e: (e[0], e[1])):
        if s0 < cur:
            raise rn_transform.SwapFail("overlapping edits")
        out.append(text[cur:s0])
        out.append(new)
        cur = e0
    out.append(text[cur:])
    new = "".join(out)
    renames = {ci: v[0] for ci, v in names.items() if ci != v[0]}
    if renames:
        def ren(i, ts):
            t = ts[i]
            if t.v not in renames or (i and ts[i - 1].v in (".", "->", "::")):
                return None
            return renames[t.v]
        new = rn_transform.tok_edit(new, ren)
    if (need_ptr_h or any("hulk_uintptr" in e[2] for e in edits)) and "compat/ptr.h" not in text and not re.search(
            r"\bhulk_u?(int|long)ptr\b", text):
        new = rn_transform.insert_include(new, '#include "compat/ptr.h"')
    return new


def canon_plan(plans, per_src, detail, root, excl, st):
    """{source: {own name: (C name, canonical decl, canonical parts, is the definition)}} for the (TU, C name)
    pairs tu_consistency held where every source of the TU that declares the name takes the canonical prototype
    (canon_transform), each source's names together. Sources the batch didn't touch (they declare the C name under
    its own name) are added to per_src."""
    by_name = {p["name"]: p for p in plans}
    members = detail.get("members", {})
    texts, parsed = {}, {}

    def text_of(q):
        if q not in texts:
            try:
                texts[q] = open(os.path.join(root, q), encoding="latin1", newline="").read()
                parsed[q] = cxx_items.parse(texts[q])
            except (OSError, ValueError):
                texts[q], parsed[q] = None, []
        return texts[q]
    kds = {}
    for tu, n in sorted(detail.get("pairs", ())):
        if n in kds or n not in by_name:
            continue
        p = by_name[n]
        kds[n] = None
        t = text_of(p["definition"])
        if t is None:
            continue
        fd = [it for it in parsed[p["definition"]] if it.kind == "funcdef" and it.name == p["def_name"] and not it.scope]
        if len(fd) != 1:
            continue
        try:
            kd = fn_parts(t, fd[0], builtin_typedefs(parsed[p["definition"]]))
        except (rn_transform.SwapFail, ValueError):
            continue
        if kd["rinfo"] is None or any(i is None for i in kd["pinfo"]):
            continue
        kds[n] = (canon_decl(n, kd), kd)
    st["canonical: names with a canonical prototype"] = sum(1 for v in kds.values() if v)
    # per pair: the members declaring the name, each as (source, own name, is the definition)
    pair_m = {}
    for tu, n in detail.get("pairs", ()):
        if not kds.get(n):
            st["canonical: pairs refused (definition prototype)"] += 1
            continue
        p = by_name[n]
        ms = []
        for q in members.get(tu, ()):
            if text_of(q) is None:
                continue
            d = per_src.get(q)
            ren = {}
            if d:
                # (a caller's address name of another address is that address's own function: `thunk_FUN_x`, or a
                # FUN_y the link bound to x; free_transform leaves it alone, and so does this)
                ren = {ci: v[0] for ci, v in d["calls"].items() if not (ADDR_NAME.search(ci) and ci != v[0])}
                if d["define"]:
                    ren[d["define"][0]] = d["define"][1]
            for ci in sorted({it.name for it in parsed[q] if it.kind in ("func", "funcdef") and not it.scope
                              and it.name and ren.get(it.name, it.name) == n}):
                ms.append((q, ci, q == p["definition"] and ci == p["def_name"]))
        pair_m[(tu, n)] = ms
    # one name at a time, then all of a source's names together, until nothing changes
    why = collections.Counter()
    ok = set()
    for key, ms in pair_m.items():
        n = key[1]
        good = bool(ms)
        for q, ci, isdef in ms:
            if q in excl:
                good = False
                why["excluded source"] += 1
                break
            try:
                canon_transform(texts[q], {ci: (n, kds[n][0], kds[n][1])}, ci if isdef else None,
                                q.startswith("equivalent/"))
            except rn_transform.SwapFail as e:
                good = False
                why[re.sub(r"\b\w+(?=:| also| named| is| declared| used| already)", "N",
                           re.sub(r"\(.*\)", "", str(e)))[:60]] += 1
                break
        if good:
            ok.add(key)
    while True:
        per = collections.defaultdict(list)
        for key in ok:
            for q, ci, isdef in pair_m[key]:
                per[q].append((key, ci, isdef))
        bad = set()
        for q, xs in per.items():
            try:
                canon_transform(texts[q], {ci: (k[1], kds[k[1]][0], kds[k[1]][1]) for k, ci, isdef in xs},
                                next((ci for k, ci, isdef in xs if isdef), None), q.startswith("equivalent/"))
            except rn_transform.SwapFail:
                bad |= {k for k, ci, isdef in xs}
        if not bad:
            break
        why["names together in one source"] += len(bad)
        ok -= bad
    for k, v in why.most_common():
        st["canonical: pair refused, " + k] += v
    st["canonical: pairs unlocked"] = len(ok)
    st["canonical: pairs held"] = len(pair_m) - len(ok)
    canon = collections.defaultdict(dict)
    for key in ok:
        n = key[1]
        for q, ci, isdef in pair_m[key]:
            canon[q][ci] = (n, kds[n][0], kds[n][1], isdef)
            per_src[q]          # (a source the batch hadn't touched)
    return dict(canon), sorted(ok)


def cmd_free_apply(a):
    plans = [json.loads(l) for l in open(a.plan)]
    plans = [p for p in plans if not p.get("refused") and p.get("definition") and p.get("prototype")][:a.top]
    excl = set()
    for path in a.exclude or []:
        excl |= {l.split()[0] for l in open(path) if l.strip()}
    per_src = collections.defaultdict(lambda: {"calls": {}, "define": None, "addrs": set()})
    for p in plans:
        N, proto = p["name"], p["prototype"]
        d = per_src[p["definition"]]
        d["define"] = (p["def_name"], N)
        d["addrs"].add(p["addr"])
        for q, cis in p["callers"].items():
            for ci in cis:
                per_src[q]["calls"][ci] = (N, proto)
                per_src[q]["addrs"].add(p["addr"])
    root = os.path.abspath(a.root)
    st = collections.Counter()
    detail = {}
    held = tu_consistency(per_src, a.manifest, root, excl, detail) if a.manifest else {}
    canon, canon_log = ({}, []) if not a.canonical or not held else canon_plan(
        plans, per_src, detail, root, excl, st)
    for q, ns in held.items():
        if q not in per_src:
            continue
        d = per_src[q]
        d["held"] = sorted(({v[0] for v in d["calls"].values()} & ns | ({d["define"][1]} & ns if d["define"] else set()))
                           - {v[0] for v in canon.get(q, {}).values()})
        d["calls"] = {ci: v for ci, v in d["calls"].items() if v[0] not in ns}
        if d["define"] and d["define"][1] in ns:
            d["define"] = None
    os.makedirs(a.out, exist_ok=True)
    with open(os.path.join(a.out, "free-apply.jsonl"), "w") as log:
        for q, d in sorted(per_src.items()):
            rec = {"path": q, "addrs": sorted(d["addrs"]), "define": d["define"], "calls": d["calls"]}
            if canon.get(q):
                rec["canonical"] = {ci: v[0] for ci, v in canon[q].items()}
            if d.get("held"):
                rec["held"] = d["held"]
                st["names held back (TU spellings differ)"] += len(d["held"])
            if q in excl:
                rec["skip"] = "excluded"
                st["excluded"] += 1
            else:
                text = open(os.path.join(root, q), encoding="latin1", newline="").read()
                new = None
                if canon.get(q):
                    # (canon_plan already ran this transform on the same text: it can't fail here)
                    cd = canon[q]
                    df = next((ci for ci, v in cd.items() if v[3]), None)
                    new = text = canon_transform(text, {ci: v[:3] for ci, v in cd.items()}, df,
                                                 q.startswith("equivalent/"))
                    st["canonical sources"] += 1
                try:
                    new = free_transform(text, d["calls"], d["define"])
                except rn_transform.SwapFail as e:
                    if "nothing to do" not in str(e):
                        rec["skip"] = str(e)
                        st["refused: " + re.sub(r"\b\w+(?=:| also| named| is| definition)", "N", str(e))[:60]] += 1
                    # (the canonical part stays: the other sources of its (TU, name) pairs count on it)
                if new is not None:
                    p_ = os.path.join(a.out, q)
                    os.makedirs(os.path.dirname(p_), exist_ok=True)
                    open(p_, "w", encoding="latin1", newline="").write(new)
                    st["rewritten " + q.split("/")[0]] += 1
            log.write(json.dumps(rec) + "\n")
    for k, v in st.most_common():
        print("%6d  %s" % (v, k))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    d = sub.add_parser("data")
    d.add_argument("--bindings", required=True)
    d.add_argument("--snap", required=True)
    d.add_argument("--out", required=True)
    d.add_argument("--root", default=ROOT)
    d.add_argument("--exclude", nargs="*", help="files listing paths not to rewrite (claims, changed sources)")
    d.add_argument("--only", nargs="*")
    f = sub.add_parser("free")
    f.add_argument("--link", required=True, help="the name_audit input dir (bindings.json, aliases.rsp, ...)")
    f.add_argument("--snap", required=True)
    f.add_argument("--out", required=True)
    f.add_argument("--root", default=ROOT)
    fa = sub.add_parser("free-apply")
    fa.add_argument("--plan", required=True, help="free-plan.jsonl of `free`")
    fa.add_argument("--top", type=int, default=50, help="the first N plannable definitions (largest first)")
    fa.add_argument("--out", required=True)
    fa.add_argument("--root", default=ROOT)
    fa.add_argument("--exclude", nargs="*")
    fa.add_argument("--canonical", action="store_true", help="batch 3: a held (TU, C name) pair takes the "
                    "definition's prototype with `void *` for pointers to non-builtin types in every source of the "
                    "TU that declares it, casts at the calls (canon_transform)")
    fa.add_argument("--manifest", help="build/tree/manifest.json of a Wine build of the same sources: hold back a C "
                    "name in a TU whose sources declare it with more than one signature (tu_consistency)")
    a = ap.parse_args(argv)
    return {"data": cmd_data, "free": cmd_free, "free-apply": cmd_free_apply}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
