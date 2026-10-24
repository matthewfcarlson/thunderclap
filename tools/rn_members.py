#!/usr/bin/env python3
"""Batch b9 (docs/consolidation-plan.md): include/gen/ non-virtual member declarations from the sources that define
them, so those sources can move onto the header class (migrate_gen.py rule gen-nv).

  build/venv/bin/python tools/rn_members.py --map build/rn1/rename-map.json      # plan: build/rn1/members-plan.json
  build/venv/bin/python tools/rn_members.py --map ... --apply                     # + include/gen/evidence-rn.json
                                                                                  #   "members"; then regenerate
  build/venv/bin/python tools/rn_members.py --keep LIST --apply                   # keep only the members of these
                                                                                  #   sources (the verified ones)

A source whose own function (functions.csv `FUN_<addr>`) is an out-of-line non-virtual member of a private stub
that the rename map (tools/rn_map.py, high/medium, `own`) names as a plain include/gen/ class X: the header class X
gets the declaration `R FUN_<addr>(P...)` (gen_headers.py "members" evidence) with the source's signature in header
types (gen_headers.nv_signature: scalars and pointers to scalars kept, enums as int, a pointer to the stub itself as
`X*`, other pointers and references as `void*`), and the source becomes `R X::FUN_<addr>(P...) {...}` on the header
(gen_headers.swap_transform with nv=..., the gen-swap rewrite: stub fields -> the header's f_XX, stub virtuals ->
slot names, non-virtual helpers on a declaration struct, parameters cast back to the stub's types in a prologue).

Refused here: the stub's member is virtual, static or not __thiscall, has a class by value or a function pointer in
its signature, the file defines more than that one member, the class is a template, or a source already on
include/gen/ names FUN_<addr> (inside the class's members an unqualified FUN_<addr> would find the new member
instead of the free function the source declares).
"""
import argparse
import collections
import json
import os
import re
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_headers as gh  # noqa: E402
import migrate_gen as mg  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EVIDENCE = os.path.join(ROOT, "include/gen/evidence-rn.json")


def candidates(g, rmap, exclude):
    """[(source, addr, target, [(stub, Cls)])] for the sources whose own stub the map names as a plain gen class."""
    names = mg.load_names()
    in_matches = {f for f in os.listdir(os.path.join(ROOT, "matches")) if f.endswith(".cpp")}
    own = collections.defaultdict(list)
    for e in rmap:
        if not e["own"] or not e["real"] or e["confidence"] not in ("high", "medium"):
            continue
        C = g.by_name.get(e["real"]) or g.by_csv.get(gh.csv_name(e["real"]))
        if C is None or C.unit.template or not C.has_layout:
            continue
        own[e["source"]].append((e["stub"].split("::")[-1], C))
    out = []
    for src, stubs in sorted(own.items()):
        d, fn = src.split("/")
        if src in exclude or (d == "equivalent" and fn in in_matches):
            continue
        addr = int(fn[2:10], 16)
        target = names.get(addr)
        if target != "FUN_%08x" % addr:
            continue
        p = os.path.join(ROOT, src)
        if not os.path.exists(p):
            continue
        text = open(p, encoding="latin1", newline="").read()
        if re.search(r'#\s*include\s*[<"]gen/', text) or re.search(r"^\s*#", mg.DECLS_INCLUDE.sub("", text), re.M):
            continue
        out.append((src, addr, target, stubs))
    return out


def plan_one(g, item, ctors=False):
    src, addr, target, stubs = item
    why = None
    for stub, C in stubs:
        try:
            _text, _sym, sig = gh.swap_transform(g, os.path.join(ROOT, src), target, rename=mg.tok_rename,
                                                 stub_suffix="_%x" % addr, nv=(C, target, None, stub, ctors))
            return src, target, C, sig, None
        except gh.SwapFail as e:
            why = str(e)
            if "is not the stub" in why:
                continue
            return src, target, C, None, why
        except Exception as e:  # noqa: BLE001 - one odd source must not stop the run
            return src, target, C, None, "crash: %s %s" % (type(e).__name__, str(e)[:80])
    return src, target, None, None, why


def gen_mentions(names):
    """{FUN_ name: [sources already on include/gen/ that name it]}."""
    hits = collections.defaultdict(list)
    for d in ("matches", "equivalent"):
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if not fn.endswith(".cpp"):
                continue
            t = open(os.path.join(ROOT, d, fn), encoding="latin1").read()
            if not re.search(r'#\s*include\s*[<"]gen/', t):
                continue
            for m in set(re.findall(r"\bFUN_[0-9a-fA-F]{8}\b", t)) & names:
                hits[m].append("%s/%s" % (d, fn))
    return hits


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--map", default=os.path.join(ROOT, "build/rn1/rename-map.json"))
    ap.add_argument("--exclude", nargs="*", default=[], help="files listing source paths to leave out")
    ap.add_argument("--out", default=os.path.join(ROOT, "build/rn1/members-plan.json"))
    ap.add_argument("--keep", help="with --apply: write only the members of the sources listed in this file")
    ap.add_argument("--plan", help="with --keep: an existing plan file instead of planning again")
    ap.add_argument("--apply", action="store_true", help="write the declarations to include/gen/evidence-rn.json")
    ap.add_argument("--ctors", action="store_true", help="constructors instead of members: evidence-rn.json "
                    "\"ctors\" (the class's) and \"base_ctors\" (its direct base's out-of-line default constructor)")
    ap.add_argument("--replace", action="store_true", help="with --apply: drop the members already in evidence-rn.json")
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args(argv)
    g = mg.Gen.get()
    if a.plan:
        plan = json.load(open(a.plan))
    else:
        exclude = set()
        for f in a.exclude:
            exclude |= {l.split()[-1] for l in open(f) if l.strip()}
        rmap = json.load(open(a.map))["entries"]
        todo = candidates(g, rmap, exclude)
        with ThreadPoolExecutor(a.jobs) as ex:
            res = list(ex.map(lambda it: plan_one(g, it, a.ctors), todo))
        ok = [(s, t, C, sig) for s, t, C, sig, why in res if sig]
        hits = gen_mentions({t for _s, t, _C, _sig in ok})
        plan = {"members": [], "refused": collections.Counter()}
        for s, t, C, sig, why in res:
            if why:
                plan["refused"][re.sub(r"\+0x[0-9a-f]+|\b\d+\b|\b\w+_[0-9a-f]{4,8}\b", "N", why)[:80]] += 1
        for s, t, C, sig in ok:
            if hits.get(t):
                plan["refused"]["an include/gen/ source names it"] += 1
                continue
            m = {"source": s, "class": gh.csv_name(C.name), "name": t, "sig": list(sig)}
            if a.ctors:
                if C.bases:
                    if C.bases[0][1] != 0 or C.bases[0][0].unit.template:
                        plan["refused"]["primary base not at offset 0 or a template"] += 1
                        continue
                    m["base"] = gh.csv_name(C.bases[0][0].name)
            plan["members"].append(m)
        plan["looked_at"] = len(todo)
        os.makedirs(os.path.dirname(a.out), exist_ok=True)
        json.dump(plan, open(a.out, "w"), indent=1)
        for why, n in plan["refused"].most_common(30):
            print("  %5d  %s" % (n, why))
        print("%d sources looked at, %d members planned (%s)" % (len(todo), len(plan["members"]), a.out))
    if a.apply and a.ctors:
        keep = {l.split()[-1] for l in open(a.keep) if l.strip()} if a.keep else None
        ev = json.load(open(EVIDENCE))
        cs = {} if a.replace else {k: v for k, v in ev.get("ctors", {}).items()}
        bs = {} if a.replace else {k: v for k, v in ev.get("base_ctors", {}).items()}
        cs.setdefault("_comment", "constructors defined out of line by sources (tools/rn_members.py --ctors): class -> "
                                  "{FUN name: params}")
        bs.setdefault("_comment", "classes whose default constructor the game calls out of line from a derived class's "
                                  "constructor (tools/rn_members.py --ctors)")
        for m in plan["members"]:
            if keep is None or m["source"] in keep:
                cs.setdefault(m["class"], {})[m["name"]] = m["sig"][1]
                if m.get("base"):
                    bs[m["base"]] = "called by %s" % m["name"]
        ev["ctors"], ev["base_ctors"] = cs, bs
        json.dump(ev, open(EVIDENCE, "w"), indent=1)
        print("wrote %d constructors, %d base constructors" % (sum(len(v) for k, v in cs.items() if not k.startswith("_")),
                                                              len([k for k in bs if not k.startswith("_")])))
    elif a.apply:
        keep = {l.split()[-1] for l in open(a.keep) if l.strip()} if a.keep else None
        ev = json.load(open(EVIDENCE))
        ms = {"_comment": "non-virtual member declarations (tools/rn_members.py, batch b9): class -> {name: [ret, "
                          "params, quals]}, from the defining sources"}
        # the members already there stay (their sources are on include/gen/ now, so a new plan doesn't list them);
        # --keep limits only the plan's own members, unless --replace drops the old ones
        if not a.replace:
            for cname, old in ev.get("members", {}).items():
                if not cname.startswith("_"):
                    ms.setdefault(cname, {}).update(old)
        for m in plan["members"]:
            if keep is None or m["source"] in keep:
                ms.setdefault(m["class"], {})[m["name"]] = m["sig"]
        ev["members"] = ms
        json.dump(ev, open(EVIDENCE, "w"), indent=1)
        print("wrote %d members to %s; now regenerate: build/venv/bin/python tools/gen_headers.py"
              % (sum(len(v) for k, v in ms.items() if not k.startswith("_")), os.path.relpath(EVIDENCE, ROOT)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
