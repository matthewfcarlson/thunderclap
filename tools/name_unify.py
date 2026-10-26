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
    os.makedirs(a.out, exist_ok=True)
    with open(os.path.join(a.out, "free-apply.jsonl"), "w") as log:
        for q, d in sorted(per_src.items()):
            rec = {"path": q, "addrs": sorted(d["addrs"]), "define": d["define"], "calls": d["calls"]}
            if q in excl:
                rec["skip"] = "excluded"
                st["excluded"] += 1
            else:
                text = open(os.path.join(root, q), encoding="latin1", newline="").read()
                try:
                    new = free_transform(text, d["calls"], d["define"])
                    p_ = os.path.join(a.out, q)
                    os.makedirs(os.path.dirname(p_), exist_ok=True)
                    open(p_, "w", encoding="latin1", newline="").write(new)
                    st["rewritten " + q.split("/")[0]] += 1
                except rn_transform.SwapFail as e:
                    rec["skip"] = str(e)
                    st["refused: " + re.sub(r"\b\w+(?=:| also| named| is| definition)", "N", str(e))[:60]] += 1
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
    a = ap.parse_args(argv)
    return {"data": cmd_data, "free": cmd_free, "free-apply": cmd_free_apply}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
