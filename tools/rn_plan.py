#!/usr/bin/env python3
"""Consolidation plan: why the tree's functions are wrapped, joined with the rename map (docs/consolidation-plan.md).

  build/venv/bin/python tools/rn_plan.py --state <state.json>      # build/rn1/plan.json + plan-summary.txt
  build/venv/bin/python tools/rn_plan.py --batches          # build/rn1/batches/b*.json for migrate_gen --family rn
                                                           #   (b1-b3, b4 relabel)
  build/venv/bin/python tools/rn_plan.py --refine build/rn1/batches/b2-genref-matches.json --state <state.json> \
      --bindings build/native/bindings.json [--refine-out PATH]
                                       # keep only the sources whose rewrite costs no merge and no link binding
                                       # (generator in the loop; see refine()). A batch item {"source", "rule":
                                       # "text", "path"} is a source already rewritten elsewhere (the gen family, b6)
  build/venv/bin/python tools/rn_plan.py --metrics BEFORE_ROOT AFTER_ROOT list.txt   # pads, stub virtuals, casts

Generates the tree in memory (tools/gen_tree.py, with the given fallback state; nothing is written to build/tree/),
records for every wrapped function the full list of names it conflicts on (gen_tree only keeps four in the reason),
and classifies each (TU, name) conflict with build/rn1/rename-map.json (tools/rn_map.py):

  header-stub    the name is declared by an include/gen/ header the TU includes and the source defines its own
                 stub of it: the stub must go onto the header class (gen-ref) or, where it is another class,
                 take its real or a placeholder name (unclash)
  split          the variants of a name in one TU belong to different real classes (rename map): renaming each
                 to its real class (or the header class) separates them
  layout         the variants are one real class (or unknown) and their layouts disagree: needs fields in
                 include/gen/ or a cast rewrite, not a rename
  function/data  a function or variable declared differently (signatures, linkage): not a class question

and the class merges stub_layout refused per real class.
"""
import argparse
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import gen_tree  # noqa: E402

ROOT = gen_tree.ROOT


def load_state(path):
    if not path:
        return gen_tree.load_state()
    s = json.load(open(path))
    return {"wrap": {int(k, 16): v for k, v in s.get("wrap", {}).items()},
            "isolate": {int(k, 16): v for k, v in s.get("isolate", {}).items()},
            "local_only": {tuple(k) for k in s.get("local_only", [])},
            "iso_plain": {int(k, 16): v for k, v in s.get("iso_plain", {}).items()}}


class PlanGenerator(gen_tree.Generator):
    """gen_tree.Generator that keeps every block's full list of conflicting names (b.rn_bad)."""

    def choose_variants(self, tu):
        while True:
            cand = [b for b in tu.blocks if b.mode == "merged"]
            users = collections.defaultdict(lambda: collections.defaultdict(set))
            raw = collections.defaultdict(lambda: collections.defaultdict(lambda: collections.defaultdict(set)))
            items = {}
            for b in cand:
                for nk, var, cvar, it in gen_tree.block_cvariants(b):
                    users[nk][cvar].add(b.addr)
                    raw[nk][cvar][var].add(b.addr)
                    if it is not None:
                        items.setdefault((nk, var), it)
            accepted = {nk: gen_tree.accept_variants(vs, tu.gen_vars.get(nk, ())) for nk, vs in users.items()}
            absorbed = {}
            for nk, vs in users.items():
                for cvar, rv in raw[nk].items():
                    if len(rv) > 1:
                        best = max(rv, key=lambda v: (len(rv[v]), -min(rv[v])))
                        rep = items.get((nk, best))
                        if rep is not None:
                            for v in rv:
                                if v != best:
                                    absorbed.setdefault(nk, {})[v] = rep
                if len(accepted[nk]) == len(vs) or not self.merge_classes or nk in tu.gen_vars:
                    continue
                m = self.merge_name(tu, nk, vs, cand)
                if m:
                    absorbed.setdefault(nk, {}).update(m)
            defined = {}
            new_bad = 0
            for b in cand:
                badv = sorted({(gen_tree.name_str(nk), var[0]) for nk, var, cvar, it in gen_tree.block_cvariants(b)
                               if cvar not in accepted[nk] and var not in absorbed.get(nk, {})})
                bad = sorted({n for n, _ in badv})
                if bad:
                    b.rn_bad = badv
                    b.rn_forced = sorted(n for n in bad if n in tu.gen_vars)
                    b.wrap("conflict: " + "; ".join(bad[:4]) + (" (+%d)" % (len(bad) - 4) if len(bad) > 4 else ""))
                    new_bad += 1
                    continue
                dk = gen_tree.key_of(b.defs[0])
                if dk in defined:
                    b.wrap("same definition as 0x%08x in this TU" % defined[dk])
                    new_bad += 1
                    continue
                defined[dk] = b.addr
            if not new_bad:
                return absorbed


def classify(g, rmap):
    """[(tu path, block addr, source, name, var kind, category, real or None, confidence)] per conflicting name."""
    by_src = collections.defaultdict(dict)
    for e in rmap:
        by_src[e["source"]][e["stub"]] = e
    rows = []
    for tu in g.tus:
        blocks = [b for b in tu.blocks if b.mode == "wrapped" and any(r.startswith("conflict:") for r in b.reasons)
                  and getattr(b, "rn_bad", None)]
        if not blocks:
            continue
        # real classes per (name) among the TU's blocks that define a stub of it
        reals = collections.defaultdict(set)
        for b in tu.blocks:
            for nm, e in by_src.get(b.path, {}).items():
                if e["real"] and e["confidence"] in ("high", "medium"):
                    reals[nm].add(e["real"])
        for b in blocks:
            forced = set(getattr(b, "rn_forced", ()))
            for nm, vk in b.rn_bad:
                e = by_src.get(b.path, {}).get(nm)
                real = e["real"] if e and e["confidence"] in ("high", "medium") else None
                conf = e["confidence"] if e else None
                if vk not in ("class", "fwd", "struct", "union", "typedef", "enum"):
                    cat = "function/data"
                elif nm in forced:
                    cat = "header-stub"
                elif real and len(reals.get(nm, ())) > 1:
                    cat = "split"
                else:
                    cat = "layout"
                rows.append((tu.path, b.addr, b.path, nm, vk, cat, real, conf))
    return rows


BATCHES = [
    # name, rule, source directory, what
    ("b1-unclash-matches", "unclash", "matches",
     "private stubs named like an include/gen/ class that are another class: real name + placeholder suffix"),
    ("b2-genref-matches", "gen-ref", "matches",
     "stubs the source only uses, whose used members fit their include/gen/ class: onto the header"),
    ("b3-equivalent", "unclash,gen-ref", "equivalent", "b1 and b2 for equivalent/ (equiv.py --inputs 3000)"),
    ("b4-relabel-matches", "relabel", "matches",
     "suffixed/invented stubs with a known real class: real short name + placeholder suffix (readability)"),
    ("b4-relabel-equivalent", "relabel", "equivalent", "b4 for equivalent/ (equiv.py --inputs 3000)"),
]


# b4 leaves alone: gen-ref's declaration structs (`CAction_nv_1c5a70`) and wrappers named after the function they
# call (`FUN_0027b070`, `ThisCall_0023c640`): their names already say what they are
NOT_RELABELED = re.compile(r"^(?:FUN_|ThisCall|ThisWrap)|_nv_[0-9a-f]+$")
# gen-ref / gen-swap's declaration structs (`CCharacter_nv_3ffa0`): already on include/gen/, not stubs to move
NV_STRUCT = re.compile(r"_nv_[0-9a-f]+$")


def make_batches(out_dir, rmap_path, fit_path):
    """Batch files for tools/migrate_gen.py --family rn, from the rename map and the layout fit."""
    import rn_transform
    rmap = json.load(open(rmap_path))["entries"]
    fit = {(e["source"], e["stub"]): e for e in json.load(open(fit_path))["entries"]}
    taken = rn_transform.gen_taken()
    in_matches = {f for f in os.listdir(os.path.join(ROOT, "matches")) if f.endswith(".cpp")}
    keep = collections.defaultdict(set)
    for x in rmap:
        if x["real"] and x["confidence"] in ("high", "medium") and rn_transform.short(x["real"]) == x["stub"].split("::")[-1]:
            keep[x["source"]].add(x["stub"].split("::")[-1])
    is_base = collections.defaultdict(set)      # source -> stub names another stub of it derives from
    for x in rmap:
        for bn in x.get("bases") or ():
            is_base[x["source"]].add(bn)
    items = collections.defaultdict(list)       # (rule, dir) -> items
    for e in rmap:
        if not e["real"] or e["confidence"] not in ("high", "medium"):
            continue
        d, fn = e["source"].split("/")
        if d == "equivalent" and fn in in_matches:
            continue
        st = e["stub"]
        if NV_STRUCT.search(st):
            continue
        f = fit.get((e["source"], st))
        it = {"source": e["source"], "stub": st, "real": e["real"], "confidence": e["confidence"], "own": e["own"],
              "keep": sorted(keep[e["source"]])}
        if f and not e["own"] and f["verdict"] in ("same", "cast", "ptr-int") and st not in is_base[e["source"]]:
            items[("gen-ref", d)].append(dict(it, rule="gen-ref", fit=f["verdict"]))
        elif "::" not in st and st in taken and rn_transform.short(e["real"]) != st:
            items[("unclash", d)].append(dict(it, rule="unclash"))
    # b4 relabel: suffixed (`Obj_2d5ec0`) and invented (`Node`) stubs that collide with no include/gen/ name (those
    # are unclash's), named after their real class. A suffixed stub keeps its suffix, so every source carrying a copy
    # of it (`touches`) gets the same name; a name whose entries disagree on the real class is left alone.
    want = collections.defaultdict(set)         # (source, stub) -> {(real, new name)}
    for e in rmap:
        st = e["stub"]
        if (not e["real"] or e["confidence"] not in ("high", "medium") or e["kind"] not in ("suffixed", "invented")
                or "::" in st or st in taken or NOT_RELABELED.search(st)):
            continue
        addr = int(os.path.basename(e["source"])[2:10], 16)
        new = rn_transform.relabel_name(st, e["real"], addr)
        if new == st:
            continue
        srcs = set(e.get("touches") or ()) | {e["source"]} if rn_transform.SUFFIXED.match(st) else {e["source"]}
        for src in srcs:
            want[(src, st)].add((e["real"], new, e["confidence"], e["own"] if src == e["source"] else False))
    for (src, st), opts in sorted(want.items()):
        if len({(r, n) for r, n, _c, _o in opts}) != 1:
            continue
        real, new, conf, own = sorted(opts)[0]
        d, fn = src.split("/")
        if d == "equivalent" and fn in in_matches:
            continue
        # a base stub whose derived class in the source carries the real class's name: the map's most-derived
        # evidence names the base after its derived class (`Base_2b96d0` under `OldBillboardQuadGroupLoader`)
        text = open(os.path.join(ROOT, src), encoding="latin1").read()
        if re.search(r"\b(?:class|struct)\s+%s\s*:[^{;]*\b%s\b" % (re.escape(rn_transform.short(real)), re.escape(st)), text):
            continue
        items[("relabel", d)].append({"source": src, "stub": st, "real": real, "confidence": conf, "own": own,
                                      "new": new, "rule": "relabel", "keep": sorted(keep[src])})
    os.makedirs(out_dir, exist_ok=True)
    out = []
    for name, rules, d, what in BATCHES:
        its = [x for r in rules.split(",") for x in items[(r, d)]]
        its.sort(key=lambda x: (x["source"], x["rule"] != "gen-ref", x["stub"]))
        path = os.path.join(out_dir, name + ".json")
        json.dump({"name": name, "what": what, "rules": rules, "items": its}, open(path, "w"), indent=0)
        out.append((name, len(its), len({x["source"] for x in its})))
    return out


RANK = {"merged": 0, "wrapped": 1, "isolated": 2}
PAD = re.compile(r"\bchar\s+\w*(?:pad|gap|unk|_)\w*\s*\[")
VIRT = re.compile(r"\bvirtual\b")
INTCAST = re.compile(r"\(\s*(?:int|unsigned int|unsigned|long|unsigned long|DWORD|u32\w*)\s*\)\s*\(?\s*[A-Za-z_&]")
PTRCAST = re.compile(r"\(\s*[A-Za-z_][\w:]*\s*\*+\s*\)\s*\(?\s*(?:\(\s*char\s*\*\s*\))?")


def text_metrics(text):
    """Counts of the source constructs a batch can remove (rough, textual): explicit pad fields, virtual
    declarations of stub classes, stub class definitions, integer casts and pointer casts."""
    try:
        items = cxx_items.parse(text)
    except ValueError:
        items = []
    nv = [it for it in items if it.kind == "class" and "_nv_" in (it.name or "")]
    classes = [it for it in items if it.kind == "class" and it not in nv]
    return {"pads": sum(len(PAD.findall(it.text)) for it in classes),
            "stub_virtuals": sum(len(VIRT.findall(it.text)) for it in classes),
            "stub_classes": len(classes), "nv_structs": len(nv),
            "header_includes": len(re.findall(r'#\s*include\s*"gen/', text)),
            "int_casts": len(INTCAST.findall(text)), "ptr_casts": len(PTRCAST.findall(text))}


def metrics(before_root, after_root, sources):
    tot = collections.Counter()
    for src in sources:
        b = text_metrics(open(os.path.join(before_root, src), encoding="latin1").read())
        a = text_metrics(open(os.path.join(after_root, src), encoding="latin1").read())
        for k in b:
            tot[k + " before"] += b[k]
            tot[k + " after"] += a[k]
    return dict(tot)


def modes_of(state, overlay=None):
    """{addr: (mode, source path, TU path)} of a generator run, with `overlay` {source path: text} in place of the
    files on disk."""
    orig = gen_tree.load_sources
    if overlay:
        def load():
            out = orig()
            for a, (kind, path, text) in list(out.items()):
                if path in overlay:
                    out[a] = (kind, path, overlay[path])
            return out
        gen_tree.load_sources = load
    try:
        g = PlanGenerator(load_state(state) if isinstance(state, str) or state is None else state)
        g.build()
    finally:
        gen_tree.load_sources = orig
    return {b.addr: (b.mode, b.path, t.path, b.defs[0].key[1] if b.defs else None) for t in g.tus for b in t.blocks}, \
        gen_tree.summary(g)


def name_groups(modes):
    """{(TU, definition name): {addresses}} of merged functions: two different functions of one TU defined under one
    name (overloads: `Target(PhysicsJoint_30cd60*)` and `Target(PhysicsJoint_30d000*)`) share the mangled-name prefix
    build_tree.py and native_link.py look functions up by."""
    out = collections.defaultdict(set)
    for a, (mode, path, tu, dn) in modes.items():
        if mode == "merged" and dn:
            out[(tu, dn)].add(a)
    return out


def native_index(path):
    """From a strict native link's binding map: {tree namespace: {(scope, name): {addresses}}} for the symbols that
    live in a tree namespace (`fn_<addr>` of a wrapped source, `fn_f<hash>` of a TU), and {function address: its
    tree namespace}."""
    import rn_map
    b = json.load(open(path))
    idx = collections.defaultdict(lambda: collections.defaultdict(set))

    def add(sym, addrs):
        p = rn_map.parse_symbol(sym)
        if not p:
            return
        kind, name, quals, code = p
        rest, tns = rn_map.split_quals(quals)
        if tns is None:
            return
        idx[tns][("::".join(reversed(rest)), name or kind)] |= addrs
    for sym, info in b["bindings"].items():
        add(sym, {int(info["addr"], 16)})
    for sym, alts in b.get("ambiguous", {}).items():
        add(sym, {int(x, 16) for x in alts})
    ns_of = {}
    for a, sym in b["definitions"].items():
        p = rn_map.parse_symbol(sym)
        if p:
            ns_of[int(a, 16)] = rn_map.split_quals(p[2])[1]
    return idx, ns_of


def ambiguities(modes, idx, ns_of, renames):
    """{TU: {(scope, name): {old tree namespace: addresses}}} where merged functions of one TU that came from different
    tree namespaces bind one invented name to different addresses (the native link could bind neither). `renames`
    {source: {old name: new name}} applies the batch's renames to the old symbols' names."""
    by_tu = collections.defaultdict(lambda: collections.defaultdict(set))   # TU -> old ns -> sources
    for a, (mode, path, tu, _dn) in modes.items():
        if mode == "merged" and ns_of.get(a):
            by_tu[tu][ns_of[a]].add(path)
    out = {}
    for tu, groups in by_tu.items():
        if len(groups) < 2:
            continue
        seen = collections.defaultdict(dict)        # key -> {ns: addrs}
        for ns, srcs in groups.items():
            ren = {}
            for src in srcs:
                ren.update(renames.get(src, {}))
            for (scope, name), addrs in idx.get(ns, {}).items():
                scope = "::".join(ren.get(x, x) for x in scope.split("::")) if scope else scope
                name = ren.get(name, name)
                seen[(scope, name)][ns] = addrs
        bad = {k: {ns: (addrs, sorted(groups[ns])) for ns, addrs in v.items()} for k, v in seen.items()
               if len(v) > 1 and len(set().union(*v.values())) > 1 and not set.intersection(*v.values())}
        if bad:
            out[tu] = bad
    return out


def refine(batch_path, state, out_path, rounds=8, bindings=None, base_modes=None):
    """Generator in the loop: rewrite every source of the batch (no verification), generate the tree, and drop
      * the sources whose own function got a worse mode (merged < wrapped < isolated), and every source of a TU where
        another function got worse;
      * the batch's sources in a group of merged functions of one TU that share a definition name, when the group is
        new or grew (overloads: build_tree.py and native_link.py look functions up by mangled-name prefix);
      * with `bindings` (the strict native link's binding map of the tree the batch applies to): the sources whose
        merge makes one invented name of a TU namespace stand for two addresses (the link can bind neither);
    repeat until nothing is dropped. Writes the refined batch and returns its numbers."""
    import tempfile
    import migrate_gen
    import rn_transform
    batch = json.load(open(batch_path))
    per = collections.defaultdict(list)
    for it in batch["items"]:
        per[it["source"]].append(it)
    hdb, taken = rn_transform.load_hdb(), rn_transform.gen_taken()
    work = tempfile.mkdtemp(prefix="refine-", dir=os.path.join(ROOT, "build"))
    texts, fails = {}, collections.Counter()
    for src, its in sorted(per.items()):
        text = open(os.path.join(ROOT, src), encoding="latin1", newline="").read()
        addr = int(os.path.basename(src)[2:10], 16)
        if its[0]["rule"] == "text":
            # an already rewritten source (`path`: e.g. a migrate_gen gen-family rewrite), refined like the others
            texts[src] = open(its[0]["path"], encoding="latin1", newline="").read()
            continue
        try:
            rule, new, hdr, what = migrate_gen.rn_apply(src, addr, text, its, hdb, taken, work)
            texts[src] = new
        except migrate_gen.gh.SwapFail as e:
            fails[re.sub(r"\b\d+\b|0x[0-9a-f]+|_[0-9a-f]{5,6}\b", "N", str(e))[:60]] += 1
    if base_modes:
        # the reference tree's modes from another checkout (--base-modes, written by --dump-modes): a batch that also
        # changes a shared header (b12's decls/address.h pins) is judged against the tree before the header changed
        bm = json.load(open(base_modes))
        base = {int(a, 16): tuple(v) for a, v in bm["modes"].items()}
        s0 = {"modes": bm["summary"]}
    else:
        base, s0 = modes_of(state)
    renames = collections.defaultdict(dict)
    for src, its in per.items():
        addr = int(os.path.basename(src)[2:10], 16)
        for it in its:
            if it["rule"] in ("unclash", "relabel"):
                new = it.get("new") or rn_transform.placeholder(it["real"], addr)
                renames[src][it["stub"]] = new
                renames[src][it["stub"] + "_vftable"] = new + "_vftable"
    amb0 = set()
    if bindings:
        idx, ns_of = native_index(bindings)
        amb0 = {(tu, k) for tu, ks in ambiguities(base, idx, ns_of, {}).items() for k in ks}
    log = []
    keep = dict(texts)
    for rnd in range(rounds):
        m, s1 = modes_of(state, keep)
        worse_tu, drop = set(), set()
        if bindings:
            # a merge that would make the native link see one invented name for two addresses
            newly = {p for a, (mode, p, t, _dn) in m.items() if p in keep and mode == "merged"
                     and base.get(a, ("",))[0] != "merged"}
            for tu, ks in ambiguities(m, idx, ns_of, {p: r for p, r in renames.items() if p in keep}).items():
                for k, by_ns in ks.items():
                    if (tu, k) in amb0:
                        continue
                    involved = {p for ns, (addrs, srcs) in by_ns.items() for p in srcs}
                    drop |= (involved & newly) or (involved & set(keep)) or {
                        p for a, (mode, p, t, _dn) in m.items() if t == tu and p in keep}
        # by object (`X.cpp`, `X.GS.cpp`, `X.iso_<addr>.cpp` are one): a function isolated by the batch sits in its
        # own .iso_ TU, away from the batch sources that caused it
        unit = lambda tu: os.path.join(os.path.dirname(tu), os.path.basename(tu).split(".", 1)[0])  # noqa: E731
        for a, (mode, path, tu, _dn) in m.items():
            bm = base.get(a)
            if bm and RANK[mode] > RANK[bm[0]]:
                if path in keep:
                    drop.add(path)
                else:
                    worse_tu.add(unit(tu))
        for a, (mode, path, tu, _dn) in m.items():
            if unit(tu) in worse_tu and path in keep:
                drop.add(path)
        # a newly merged function that shares its definition's name with another merged function of the TU
        # (the batch's sources in the group, newly merged or not; when none is, the batch's sources in that TU)
        g0, g1 = name_groups(base), name_groups(m)
        in_tu = collections.defaultdict(set)
        for a, (mode, path, tu, _dn) in m.items():
            if path in keep:
                in_tu[tu].add(path)
        for k, addrs in g1.items():
            if len(addrs) > 1 and addrs != g0.get(k, set()):
                mine = {m[a][1] for a in addrs if m[a][1] in keep}
                drop |= mine or in_tu[k[0]]
        log.append({"round": rnd + 1, "sources": len(keep), "modes": s1["modes"], "dropped": len(drop)})
        print("refine round %d: %d sources, modes %s, dropping %d" % (rnd + 1, len(keep), s1["modes"], len(drop)))
        if not drop:
            break
        for p in drop:
            keep.pop(p, None)
    better = sum(1 for a, v in m.items() if a in base and RANK[v[0]] < RANK[base[a][0]])
    worse = sum(1 for a, v in m.items() if a in base and RANK[v[0]] > RANK[base[a][0]])
    out = dict(batch)
    out["items"] = [it for it in batch["items"] if it["source"] in keep]
    out["refined"] = {"from": len(per), "rewritable": len(texts), "kept": len(keep), "rounds": log,
                      "modes_before": s0["modes"], "modes_after": s1["modes"], "functions_better": better,
                      "functions_worse": worse, "rewrite_failures": dict(fails.most_common(20))}
    json.dump(out, open(out_path, "w"), indent=0)
    return out["refined"]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--state", help="fallback state (default build/tree/state.json)")
    ap.add_argument("--map", default=os.path.join(ROOT, "build/rn1/rename-map.json"))
    ap.add_argument("--out", default=os.path.join(ROOT, "build/rn1"))
    ap.add_argument("--batches", action="store_true", help="write the batch files only (no tree generation)")
    ap.add_argument("--refine", metavar="BATCH", help="drop the batch's sources that cost merges (see refine())")
    ap.add_argument("--refine-out", metavar="PATH")
    ap.add_argument("--bindings", help="refine: a strict native link's build/native/bindings.json of the same tree; "
                                       "merges that would make one invented name bind two addresses are refused")
    ap.add_argument("--metrics", nargs=3, metavar=("BEFORE_ROOT", "AFTER_ROOT", "LIST"),
                    help="textual counts (pads, stub virtuals, stub classes, casts) of the listed sources before/after")
    ap.add_argument("--fit", default=os.path.join(ROOT, "build/rn1/layout-fit.json"))
    ap.add_argument("--dump-modes", metavar="PATH", help="write this tree's modes (with --state) for --base-modes")
    ap.add_argument("--base-modes", metavar="PATH", help="refine: judge against these modes (--dump-modes of the "
                                                         "reference tree) instead of this checkout's")
    a = ap.parse_args(argv)
    if a.dump_modes:
        m, s = modes_of(a.state)
        json.dump({"summary": s["modes"], "modes": {"0x%08x" % k: list(v) for k, v in m.items()}},
                  open(a.dump_modes, "w"))
        print(s["modes"])
        return 0
    if a.metrics:
        before, after, lst = a.metrics
        srcs = [x.strip() for x in open(lst) if x.strip()]
        print(json.dumps(metrics(before, after, srcs), indent=1))
        return 0
    if a.refine:
        r = refine(a.refine, a.state, a.refine_out or re.sub(r"\.json$", "-refined.json", a.refine), bindings=a.bindings,
                   base_modes=a.base_modes)
        print(json.dumps({k: v for k, v in r.items() if k != "rounds"}, indent=1))
        return 0
    if a.batches:
        for name, n, ns in make_batches(os.path.join(a.out, "batches"), a.map, a.fit):
            print("%-22s %5d items in %5d sources" % (name, n, ns))
        return 0
    g = PlanGenerator(load_state(a.state))
    g.build()
    s = gen_tree.summary(g)
    rmap = json.load(open(a.map))["entries"]
    rows = classify(g, rmap)
    blocks_by_cat = collections.defaultdict(set)
    for tu, addr, src, nm, vk, cat, real, conf in rows:
        blocks_by_cat[cat].add(addr)
    # a wrapped block whose every conflicting name is a class question with a known real class
    per_block = collections.defaultdict(list)
    for r in rows:
        per_block[r[1]].append(r)
    only = collections.Counter()
    for addr, rs in per_block.items():
        cats = {r[5] for r in rs}
        known = all(r[6] for r in rs if r[5] != "function/data")
        key = "+".join(sorted(cats)) + (" (all classes mapped)" if known else "")
        only[key] += 1
    names = collections.Counter((r[3], r[5]) for r in rows)
    out = {"summary": {k: v for k, v in s.items() if k != "headers"},
           "conflict_blocks": len(per_block),
           "blocks_by_category": {k: len(v) for k, v in blocks_by_cat.items()},
           "block_category_sets": dict(only.most_common()),
           "top_names": [[n, c, k] for (n, c), k in names.most_common(80)],
           "refusals": dict(g.refusals.most_common(40)),
           "rows": [list(r[:1]) + ["0x%08x" % r[1]] + list(r[2:]) for r in rows]}
    os.makedirs(a.out, exist_ok=True)
    with open(os.path.join(a.out, "plan.json"), "w") as f:
        json.dump(out, f, indent=0)
    lines = ["modes: %s" % s["modes"], "conflict-wrapped functions: %d" % len(per_block),
             "functions by category (a function can be in several): %s" % {k: len(v) for k, v in blocks_by_cat.items()}]
    lines += ["  %6d  %s" % (v, k) for k, v in only.most_common(20)]
    lines.append("top conflicting names:")
    lines += ["  %6d  %-40s %s" % (k, n, c) for (n, c), k in names.most_common(30)]
    open(os.path.join(a.out, "plan-summary.txt"), "w").write("\n".join(lines) + "\n")
    print("\n".join(lines))
    return 0


if __name__ == "__main__":
    sys.exit(main())
