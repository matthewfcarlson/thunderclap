#!/usr/bin/env python3
"""RETIRED (gen1, 2026-11-13): include/gen/ is hand-maintained source, so this tool, which fed the header
generator's inputs (include/gen/evidence*.json) or rewrote matches/ onto the generated headers, refuses to run.
Edit the headers and the blocks in src/ by hand (docs/headers.md). Kept for reference; its module-level
helpers still import.

Owner classes: include/gen/owners.h classes for the non-polymorphic classes RTTI never names (x64-10, name
unification batch 5; docs/consolidation-plan.md section 11).

A member call on a source's own stub (`t->Set(name)` on `Target_27b040`) reaches its definition, a member of the
defining source's own stub, only through a Wine-link alias. RTTI names no class for ~5,000 such definitions, so
include/gen/ had nothing for the callers to call through. This tool gives each such definition a generated class:

  plan   from a Wine build's link outputs (tools/name_audit.py input dir): every member -> member alias group whose
         definition is a non-virtual member of the defining source's own top-level stub, and whose stub is
         self-contained (fields and member signatures of builtin types and pointers to them or to the stub itself;
         no bases, virtual members, nested types or inline bodies). Per definition at 0xA, stub C, member M:
           - the class `owners::<C>_<a>` (C itself when it already ends in the address) with C's members in source
             order, typedef names said as the builtin types they name, the defined member named `FUN_<A>`;
           - signatures reconciled with the callers: a 4-byte integer parameter (or return) of the definition that
             some caller declares as a pointer becomes hulk_uintptr / hulk_intptr (hulk_ulongptr / hulk_longptr for
             `long`): the same type on the 32-bit builds (same code, same mangled name), pointer-sized on the 64-bit
             ones (include/compat/ptr.h);
           - 32-bit and 64-bit field offsets and sizes (clang record layouts, i686 / x86_64 windows-msvc);
         writes OUT/evidence-owners.json (for include/gen/, tools/gen_headers.py emits owners.h from it),
         OUT/moved.txt (`0xA owners::X::FUN_A`, name_unify.py member --moved), and the definition sources rewritten
         onto the header class under OUT/{matches,equivalent}/ (the stub goes, the source includes gen/owners.h and
         defines `R owners::X::FUN_A(P...)`).

  build/venv/bin/python tools/owner_classes.py plan --link DIR --out OUT [--exclude FILE...] [--evidence OLD.json]

The callers are then rewritten by `tools/name_unify.py member --moved OUT/moved.txt` and `member-apply`.
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))   # tools/ (this is tools/legacy/)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import name_audit  # noqa: E402
import name_unify as nu  # noqa: E402
import rn_transform  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
NS = "owners"
# replay-pinned functions (docs/wine-replay.md): never moved
PINS = {0x86450, 0x964D0, 0x113E0, 0x86630, 0x269170}
HULK_INT = {("int", False): "hulk_intptr", ("int", True): "hulk_uintptr",
            ("long", False): "hulk_longptr", ("long", True): "hulk_ulongptr"}


class Refuse(Exception):
    pass


def class_name(C, A):
    return C if re.search(r"_0*%x$" % A, C) else "%s_%x" % (C, A)


def dem_sig(d):
    """(return text, [param texts]) of a demangled member function symbol."""
    k = d.index("__thiscall")
    ret = d[:k].split(":", 1)[-1].strip()
    # the parameter list: the last top-level parenthesis group
    depth, end, start = 0, None, None
    for i in range(len(d) - 1, -1, -1):
        c = d[i]
        if c == ")":
            if depth == 0:
                end = i
            depth += 1
        elif c == "(":
            depth -= 1
            if depth == 0:
                start = i
                break
    ps = d[start + 1:end]
    out, cur, depth = [], "", 0
    for c in ps:
        if c in "<(":
            depth += 1
        elif c in ">)":
            depth -= 1
        if c == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += c
    if cur.strip():
        out.append(cur.strip())
    if out == ["void"]:
        out = []
    return ret, out


def render(text, toks, sub):
    """Tokens back to text with the inter-token spacing kept and id tokens substituted (sub(tok) -> str or None)."""
    out = []
    for i, t in enumerate(toks):
        if i:
            gap = text[toks[i - 1].e:t.s]
            out.append(gap if "\n" not in gap else " ")
        r = sub(t) if t.t == "id" else None
        out.append(r if r is not None else text[t.s:t.e])
    return re.sub(r"\s+", " ", "".join(out)).strip()


def plan_one(src, text, C, M, A, caller_sigs):
    """(evidence entry, new definition source text) for the definition C::M at A, or raise Refuse."""
    try:
        items = cxx_items.parse(text)
    except ValueError:
        raise Refuse("does not parse")
    if re.search(r"//\s*equiv-[\w-]+:?.*\b(%s|%s)\b" % (re.escape(C), re.escape(M)), text):
        raise Refuse("named on an equiv-* line")
    if re.search(r"^\s*#\s*define\b.*\b(%s|%s)\b" % (re.escape(C), re.escape(M)), text, re.M):
        raise Refuse("named in a macro")
    td = nu.builtin_typedefs(items)
    cl = [it for it in items if it.kind == "class" and it.name == C]
    if len(cl) != 1 or cl[0].scope:
        raise Refuse("stub not one top-level class")
    it = cl[0]
    vs = [t.v for t in it.toks]
    if vs[0] not in ("struct", "class") or "template" in vs[:1]:
        raise Refuse("not a plain struct/class")
    if nu.class_bases(it):
        raise Refuse("stub has bases")
    if "virtual" in vs or "static" in vs or "friend" in vs or "operator" in vs:
        raise Refuse("virtual / static / friend / operator in the stub")
    if any(i2.kind == "class" and i2.name == C for i2 in items if i2 is not it):
        raise Refuse("stub defined twice")
    stubs = {i2.name for i2 in items if i2.kind in ("class", "fwd", "template class") and i2.name and i2.name != C}
    X = class_name(C, A)
    defined = None
    mems = []
    for n, toks, meth in nu.class_members(it):
        if n is None:
            raise Refuse("nested type / using in the stub")
        if toks[-1].v == "}":
            raise Refuse("inline member body")
        tv = [t.v for t in toks]
        if n == C or "~" in tv:
            raise Refuse("constructor / destructor declared")
        ids = [t.v for t in toks if t.t == "id" and t.v not in cxx_items.KEYWORDS and t.v not in td]
        if any(x in stubs for x in ids):
            raise Refuse("member names another stub")
        if meth and n == M:
            if defined is not None:
                raise Refuse("member overloaded")
            defined = toks
        mems.append((n, toks, meth))
    if defined is None:
        raise Refuse("member not declared in the stub")
    if any(x.v == "=" for x in defined):
        raise Refuse("default argument")
    # the definition
    fdefs = [i2 for i2 in items if i2.kind == "funcdef" and i2.key and len(i2.key) > 1
             and nu.split_q(str(i2.key[1]))[-2:] == [C, M]]
    if len(fdefs) != 1:
        raise Refuse("definition %s::%s not found once" % (C, M))
    fd = fdefs[0]
    if any(i2.kind == "funcdef" and i2 is not fd for i2 in items):
        raise Refuse("source defines other functions")
    own = nu.fn_parts(text, nu._M(defined, M), td)
    dfp = nu.fn_parts(text, fd, td)
    if own["conv"] != "__cdecl" or dfp["conv"] != "__cdecl":
        raise Refuse("calling convention")
    if own["rinfo"] is None or any(p is None for p in own["pinfo"]) or len(own["pinfo"]) != len(dfp["pinfo"]):
        raise Refuse("member types")
    # reconciliation: a 4-byte integer the callers declare as a pointer
    n = len(own["pinfo"])
    ptr_pos, ptr_ret = set(), False
    for rt, ps in caller_sigs:
        if len(ps) != n:
            continue
        for i, p in enumerate(ps):
            if "*" in p and "(" not in p:
                ptr_pos.add(i)
        if "*" in rt:
            ptr_ret = True

    def hulk_of(info):
        if info[0] != "int" or info[1] != 4 or info[3]:
            return None
        w = info[2]
        wd = set(re.sub(r"\b(const|volatile)\b", "", " ".join(td.get(x, x) for x in w.split())).split())
        if wd & {"char", "short", "bool", "wchar_t", "__int64"}:
            return None
        return HULK_INT[("long" if "long" in wd else "int", "unsigned" in wd)]
    new_p = {i: hulk_of(own["pinfo"][i]) for i in ptr_pos if own["pinfo"][i][0] == "int"}
    new_p = {i: h for i, h in new_p.items() if h}
    new_r = hulk_of(own["rinfo"]) if ptr_ret and own["rinfo"][0] == "int" else None
    # the body keeps using a reconciled parameter as the integer it was (`((unsigned int)value)`): its code stays
    # the same, and on the 64-bit builds no call in it becomes ambiguous or narrows; a parameter the body assigns
    # or takes the address of keeps its type
    dfp0 = nu.fn_parts(text, fd, td)
    use_edits = []
    for i in sorted(new_p):
        pn = dfp0["pnames"][i]
        ty = [t for t in dfp0["params"][i] if not pn or t.s != pn.s]
        if not pn or dfp0["body"] is None:
            del new_p[i]
            continue
        try:
            use_edits += nu.param_use_casts(fd.toks, dfp0["body"], pn.v, text[ty[0].s:ty[-1].e])
        except rn_transform.SwapFail:
            del new_p[i]
            use_edits = [e for e in use_edits if text[e[0]:e[1]] != pn.v]

    def sub(t):
        if t.v in td:
            return td[t.v]
        if t.v == C:
            return X
        return None
    # header members
    hm = []
    for nm, toks, meth in mems:
        if toks is defined:
            ret = render(text, own["ret"], sub) if new_r is None else new_r
            ps = []
            for i, p in enumerate(own["params"]):
                pn = own["pnames"][i]
                if i in new_p:
                    ps.append(new_p[i] + (" " + pn.v if pn else ""))
                else:
                    ps.append(render(text, p, sub))
            tail = render(text, toks[own["rp"] + 1:-1], sub) if own["rp"] + 1 < len(toks) - 1 else ""
            hm.append("%s FUN_%08x(%s)%s;" % (ret, A, ", ".join(ps), (" " + tail) if tail else ""))
        else:
            hm.append(render(text, toks, sub))
    # the definition source: the stub goes, C -> owners::X, the declarator's name -> FUN_A, reconciled types
    toks = cxx_items.tokenize(text)
    fs, fe = fd.toks[0].s, fd.toks[-1].e
    name_tok = fd.toks[dfp["name_i"]]
    edits = []
    for i, t in enumerate(toks):
        if t.t != "id":
            continue
        pv = toks[i - 1].v if i else ""
        if t.v == M and t.s != name_tok.s and not (it.toks[0].s <= t.s < it.toks[-1].e):
            raise Refuse("member named outside its declaration and definition")
        if t.v != C or pv in (".", "->", "::"):
            continue
        if it.toks[0].s <= t.s < it.toks[-1].e:
            continue
        edits.append((t.s, t.e, "%s::%s" % (NS, X)))
    edits.append((name_tok.s, name_tok.e, "FUN_%08x" % A))
    edits += use_edits
    for i, h in new_p.items():
        p = dfp["params"][i]
        pn = dfp["pnames"][i]
        ty = [t for t in p if not pn or t.s != pn.s]
        edits.append((ty[0].s, ty[-1].e, h))
    if new_r:
        r = dfp["ret"]
        if len(r) >= 2 and r[-1].v == "::" and r[-2].v == C:
            r = r[:-2]
        edits.append((r[0].s, r[-1].e, new_r))
    # the class item and forward declarations of C go (with their line when alone on it)
    for i2 in items:
        if i2 is it or (i2.kind == "fwd" and i2.name == C):
            s0, e0 = i2.toks[0].s, i2.toks[-1].e
            ls = text.rfind("\n", 0, s0) + 1
            le = text.find("\n", e0)
            le = len(text) if le < 0 else le
            if not text[ls:s0].strip() and not text[e0:le].strip():
                edits.append((ls, min(le + 1, len(text)), ""))
            else:
                edits.append((s0, e0, ""))
    edits = [e for e in edits if not any(e is not o and o[0] <= e[0] < o[1] and o[2] == "" and e[2] != "" for o in edits)]
    out, cur = [], 0
    for s0, e0, new in sorted(edits):
        if s0 < cur:
            raise Refuse("overlapping edits")
        out.append(text[cur:s0])
        out.append(new)
        cur = e0
    out.append(text[cur:])
    new = rn_transform.insert_include("".join(out), '#include "gen/owners.h"')
    ev = {"addr": "0x%08x" % A, "source": src, "stub": C, "members": hm}
    if new_p or new_r:
        ev["reconciled"] = {"params": sorted(new_p), "return": bool(new_r)}
    return X, ev, new


CLANGS = [p for p in ("/opt/homebrew/opt/llvm/bin/clang", "clang") if p == "clang" or os.path.exists(p)]


def layouts(ev):
    """{class: {"size": [s32, s64], "offsets": {field: [o32, o64]}}} from clang record layouts; also the classes
    that do not compile on their own ({class: error})."""
    body = ['#include "compat/ptr.h"', "namespace %s {" % NS]
    lines = {}
    for X, e in sorted(ev.items()):
        lines[len(body) + 1] = X
        body.append("struct %s {" % X)
        for m in e["members"]:
            lines[len(body) + 1] = X
            body.append("    " + m)
        body.append("};")
    body.append("}")
    for X in ev:
        body.append("unsigned hulk_owner_sz_%s = sizeof(%s::%s);" % (X, NS, X))
    res = {}
    bad = {}
    with tempfile.TemporaryDirectory() as d:
        p = os.path.join(d, "owners.cpp")
        open(p, "w").write("\n".join(body) + "\n")
        for k, tgt in enumerate(("i686-pc-windows-msvc", "x86_64-pc-windows-msvc")):
            r = subprocess.run([CLANGS[0], "-target", tgt, "-fms-extensions", "-fms-compatibility", "-w", "-I",
                                os.path.join(ROOT, "include"), "-fsyntax-only", "-Xclang", "-fdump-record-layouts", p],
                               capture_output=True, text=True, errors="replace")
            for m in re.finditer(r"owners\.cpp:(\d+):\d+: error: (.*)", r.stderr):
                X = lines.get(int(m.group(1)))
                if X:
                    bad.setdefault(X, m.group(2))
            if bad:
                return res, bad
            cur = None
            for line in r.stdout.splitlines():
                m = re.match(r"\s*0 \| struct %s::(\w+)( \(empty\))?$" % NS, line)
                if m:
                    cur = m.group(1)
                    res.setdefault(cur, {"size": [0, 0], "offsets": {}})
                    continue
                m = re.match(r"\s*(\d+)(?::\d+-\d+)? \|\s{3}(.*\S)\s+(\w+)$", line)
                if cur and m and line.count("|") == 1 and not line.split("|")[1].startswith("     "):
                    o = res[cur]["offsets"].setdefault(m.group(3), [0, 0])
                    o[k] = int(m.group(1))
                    continue
                m = re.match(r"\s*\|\s*\[sizeof=(\d+)", line)
                if cur and m:
                    res[cur]["size"][k] = int(m.group(1))
                    cur = None
    return res, bad


def survey(link):
    rows = [r for r in name_audit.classify(link, os.path.join(link, "cp/snap")) if r[0] == "game"
            and r[1].startswith("function:")]
    B = json.load(open(os.path.join(link, "bindings.json")))
    defs = {v: int(k, 16) for k, v in B["definitions"].items()}
    dem = name_audit.undname({r[3] for r in rows} | {r[4] for r in rows})
    groups = collections.defaultdict(list)
    for kind, cat, n, s, t, srcs in rows:
        if not t or "," in t or nu.member_shape(s, dem) != "member" or nu.member_shape(t, dem) != "member":
            continue
        if nu.NS_SYM.search(t):
            groups[t].append((s, n, srcs))
    return groups, defs, dem


def cmd_plan(a):
    groups, defs, dem = survey(a.link)
    excl = set()
    for p in a.exclude or []:
        excl |= {l.split()[0] for l in open(p) if l.strip() and not l.startswith("#")}
    real = set()
    if a.rename_map and os.path.exists(a.rename_map):
        real = {int(e["addr"], 16) for e in json.load(open(a.rename_map))["entries"]
                if e["own"] and e["real"] and e["confidence"] in ("high", "medium")}
    root = os.path.abspath(a.root)
    st, sa = collections.Counter(), collections.Counter()
    ev, texts, log = {}, {}, []
    for t, rs in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        A = defs.get(t)
        rec = {"target": t, "addr": "0x%08x" % A if A is not None else None, "aliases": len(rs)}
        try:
            if A is None:
                raise Refuse("no address")
            if A in PINS:
                raise Refuse("replay pin")
            if A in real:
                raise Refuse("the rename map names an RTTI class")
            q = nu.split_q(re.sub(r"\bfn_[0-9a-f]{8}::", "", name_audit.qual_name(dem.get(t, t))))
            if len(q) != 2:
                raise Refuse("class in a namespace / nested")
            src = next((p for p in ("matches/0x%08x.cpp" % A, "equivalent/0x%08x.cpp" % A)
                        if os.path.exists(os.path.join(root, p))), None)
            if src is None:
                raise Refuse("no source")
            if src in excl:
                raise Refuse("excluded")
            rec["source"] = src
            sigs = [dem_sig(dem.get(s, s)) for s, n, srcs in rs if dem.get(s, s) != s]
            text = open(os.path.join(root, src), encoding="latin1", newline="").read()
            X, e, new = plan_one(src, text, q[0], q[1], A, sigs)
            if X in ev:
                raise Refuse("class name taken")
            e["aliases"] = len(rs)
            ev[X] = e
            texts[X] = (src, new)
            rec["class"] = X
        except (Refuse, rn_transform.SwapFail) as ex:
            rec["refused"] = str(ex)
        k = rec.get("refused", "planned")
        st[k] += 1
        sa[k] += len(rs)
        log.append(rec)
    # classes that don't compile on their own go
    while True:
        lay, bad = layouts(ev)
        if not bad:
            break
        for X, why in bad.items():
            st["planned"] -= 1
            sa["planned"] -= ev[X]["aliases"]
            k = "header class does not compile: " + re.sub(r"'[^']*'", "'N'", why)[:60]
            st[k] += 1
            sa[k] += ev[X]["aliases"]
            for r in log:
                if r.get("class") == X:
                    r["refused"] = k
                    del r["class"]
            del ev[X], texts[X]
    for X, l in lay.items():
        ev[X]["size"] = l["size"]
        ev[X]["offsets"] = l["offsets"]
    os.makedirs(a.out, exist_ok=True)
    with open(os.path.join(a.out, "evidence-owners.json"), "w") as f:
        json.dump({"_comment": "tools/owner_classes.py plan: include/gen/owners.h classes (tools/gen_headers.py)",
                   "classes": ev}, f, indent=1, sort_keys=True)
    with open(os.path.join(a.out, "moved.txt"), "w") as f:
        for X, e in sorted(ev.items(), key=lambda kv: kv[1]["addr"]):
            f.write("%s %s::%s::FUN_%s\n" % (e["addr"], NS, X, e["addr"][2:]))
    for X, (src, new) in texts.items():
        p = os.path.join(a.out, src)
        os.makedirs(os.path.dirname(p), exist_ok=True)
        open(p, "w", encoding="latin1", newline="").write(new)
    with open(os.path.join(a.out, "plan.jsonl"), "w") as f:
        for r in log:
            f.write(json.dumps(r) + "\n")
    for k, v in sorted(st.items(), key=lambda kv: -sa[kv[0]]):
        print("%5d defs %6d aliases  %s" % (v, sa[k], k))
    return 0


def main(argv=None):
    sys.exit("tools/legacy/owner_classes.py is retired (gen1, 2026-11-13): include/gen/ is hand-maintained source "
             "(docs/headers.md)")
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("plan")
    p.add_argument("--link", required=True, help="the name_audit input dir (bindings.json, aliases.rsp, cp/snap...)")
    p.add_argument("--out", required=True)
    p.add_argument("--root", default=ROOT)
    p.add_argument("--exclude", nargs="*", help="files listing source paths to leave alone")
    p.add_argument("--rename-map", default=os.path.join(ROOT, "build/rn1/rename-map.json"),
                   help="definitions whose stub the rename map names as an RTTI class are left to include/gen/")
    a = ap.parse_args(argv)
    return {"plan": cmd_plan}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
