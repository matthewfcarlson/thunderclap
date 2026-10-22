#!/usr/bin/env python3
"""Batch b6 (docs/consolidation-plan.md): include/gen/ slot signatures from the sources that define the slots.

  build/venv/bin/python tools/rn_sigs.py                # plan: build/rn1/sigs-plan.json, printed
  build/venv/bin/python tools/rn_sigs.py --apply        # + include/gen/evidence-rn.json "sigs"; then regenerate
                                                        #   the headers with tools/gen_headers.py

The gen family (tools/migrate_gen.py: gen-swap / clone-template) moves a source whose own function is slot N of an
RTTI class onto include/gen/. It refuses a source whose definition disagrees with the header's slot signature: the
header slot returns void and the source returns a value, a float parameter where the header has an integer, another
number of parameters. The header's signature is gen_headers.py's guess (arity from the slot bodies' `ret N`, `void`
and `int` otherwise), the source's is proven by its match or equivalence, so the header is what changes:

  * the return type: when every refused source of the slot returns a scalar of one kind (pointer -> void*, bool,
    char, int-like -> int, 64-bit -> __int64, float); a struct return (hidden pointer), sources that disagree, or a
    header that already returns another kind leave the slot alone;
  * float parameters: a position where every refused source has float (or double) and the header int;
  * the arity: only where gen_headers.py had no `ret N` for the slot and every source agrees on more parameters;
  * a slot whose overrides other sources on include/gen/ already define (`X::vfunc_N(`) keeps its signature: they
    would no longer compile.

The signatures go to include/gen/evidence-rn.json "sigs" ({"Owner::vfunc_N": [ret, params]}, read by gen_headers.py
like CURATED_SIGS), so regenerating the headers reproduces them; entries already there are kept.
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
INTS = {"int", "unsigned int", "long", "unsigned long", "DWORD", "UINT", "unsigned", "signed int", "size_t"}


def kind(t):
    """Scalar return kind of a C type (None: a struct or an unknown typedef)."""
    t = re.sub(r"\s+", " ", re.sub(r"\b(?:const|volatile|struct|class)\b", "", t)).strip()
    if t.endswith("*"):
        return "void*"
    if t == "bool":
        return "bool"
    if t in ("char", "unsigned char", "signed char"):
        return "char"
    if t in INTS or re.match(r"^(?:u32|uint|int|s32)_\w+$", t):
        return "int"
    if t in ("unsigned long long", "long long", "__int64", "unsigned __int64") or re.match(r"^(?:u64|s64)_\w+$", t):
        return "__int64"
    if t in ("float", "void"):
        return t
    return None


def refusals(g, jobs):
    """{slot key: [(source, stub function type, stub parameter types)]} over the gen family's candidates."""
    names = mg.load_names()
    in_matches = {int(f[2:10], 16) for f in os.listdir(os.path.join(ROOT, "matches")) if f.endswith(".cpp")}
    todo = []
    for d in ("matches", "equivalent"):
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if not re.fullmatch(r"0x[0-9a-fA-F]{8}\.cpp", fn):
                continue
            addr = int(fn[2:10], 16)
            if d == "equivalent" and addr in in_matches:
                continue
            text = open(os.path.join(ROOT, d, fn), encoding="latin1", newline="").read()
            if not mg.skip_reason(text, names.get(addr), g):
                todo.append(("%s/%s" % (d, fn), names.get(addr)))

    def one(x):
        try:
            mg.transform(g, os.path.join(ROOT, x[0]), x[1])
        except gh.SwapFail as e:
            if getattr(e, "slot", None):
                return x[0], e.slot
        except Exception:  # noqa: BLE001 - the gen family's own crash; not a signature question
            pass
        return None

    out = collections.defaultdict(list)
    with ThreadPoolExecutor(jobs) as ex:
        for r in ex.map(one, todo):
            if r:
                out[tuple(r[1][0])].append((r[0], r[1][1], r[1][2]))
    return out


def propose(g, by):
    props, skipped = {}, {}
    for key, rows in sorted(by.items()):
        name = "%s::vfunc_%d" % key
        hret, hparams = g.signature(key)
        nret_known = g.arity.get(key)
        arities = {len(p) for _, _, p in rows}
        if len(arities) != 1:
            skipped[name] = "the sources disagree on the arity %s" % sorted(arities)
            continue
        k = arities.pop()
        if k != len(hparams) and (nret_known is not None or k < len(hparams)):
            skipped[name] = "arity %d vs header %d (ret N %s)" % (k, len(hparams), nret_known)
            continue
        rets = {kind(gh.split_fn_type(t) or "?") for _, t, _ in rows}
        if None in rets or len(rets) != 1:
            skipped[name] = "return types %s" % sorted({gh.split_fn_type(t) for _, t, _ in rows})
            continue
        ret = rets.pop()
        if hret != "void":
            ret = hret if ret in ("void", hret) or (ret != "float" and hret != "float") else None
            if ret is None:
                skipped[name] = "header returns %s" % hret
                continue
        params = list(hparams) + ["int"] * (k - len(hparams))
        why = None
        for i in range(k):
            fl = {p[i].strip() in ("float", "double") for _, _, p in rows}
            if len(fl) != 1:
                why = "parameter %d: float and integer" % i
            elif fl == {True}:
                params[i] = "float"
            elif params[i] in ("float", "double"):
                why = "parameter %d: header float, sources integer" % i
            if why:
                break
        if why:
            skipped[name] = why
        elif (ret, params) == (hret, list(hparams)):
            skipped[name] = "no change"
        else:
            props[name] = {"key": list(key), "old": [hret, list(hparams)], "new": [ret, params],
                           "sources": sorted({s for s, _, _ in rows})}
    return props, skipped


def defined_on_gen(g, props):
    """{proposal: [sources on include/gen/ that define an override of its slot]}."""
    keys = {}
    for name, p in props.items():
        keys[tuple(p["key"])] = name
    by_slot = collections.defaultdict(dict)       # slot index -> {class short name: proposal}
    for c in g.classes:
        vt = c.vtables.get(0, [])
        for i in range(len(vt)):
            kk = g.resolve(c, 0, i)
            if kk in keys:
                by_slot[i][c.name.split("::")[-1]] = keys[kk]
    hits = collections.defaultdict(set)
    for d in ("matches", "equivalent"):
        for fn in os.listdir(os.path.join(ROOT, d)):
            if not fn.endswith(".cpp"):
                continue
            t = open(os.path.join(ROOT, d, fn), encoding="latin1").read()
            if '#include "gen/' not in t:
                continue
            for m in re.finditer(r"\b(\w+)::vfunc_(\d+)\s*\(", t):
                p = by_slot.get(int(m.group(2)), {}).get(m.group(1))
                if p:
                    hits[p].add("%s/%s" % (d, fn))
    return {k: sorted(v) for k, v in hits.items()}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true", help="write the signatures to include/gen/evidence-rn.json")
    ap.add_argument("--drop", nargs="*", default=[], help="slots (Owner::vfunc_N) to leave out")
    ap.add_argument("--out", default=os.path.join(ROOT, "build/rn1/sigs-plan.json"))
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args(argv)
    g = mg.Gen.get()
    by = refusals(g, a.jobs)
    props, skipped = propose(g, by)
    for name, srcs in defined_on_gen(g, props).items():
        skipped[name] = "include/gen/ sources define the slot with the old signature: %s" % ", ".join(srcs[:3])
        props.pop(name)
    for name in a.drop:
        if props.pop(name, None):
            skipped[name] = "dropped (--drop)"
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    json.dump({"props": props, "skipped": skipped}, open(a.out, "w"), indent=1)
    for name, p in sorted(props.items()):
        print("  %-62s %s -> %s (%d)" % (name, p["old"], p["new"], len(p["sources"])))
    for name, why in sorted(skipped.items()):
        print("  skip %-57s %s" % (name, why))
    print("%d slots refused sources, %d signatures proposed, %d left (%s)" % (len(by), len(props), len(skipped), a.out))
    if a.apply:
        ev = json.load(open(EVIDENCE))
        sigs = ev.setdefault("sigs", {"_comment": "slot signatures (tools/rn_sigs.py, batch b6), applied like "
                                                  "gen_headers.CURATED_SIGS"})
        for name, p in sorted(props.items()):
            sigs.setdefault(name, p["new"])
        json.dump(ev, open(EVIDENCE, "w"), indent=1)
        print("wrote %s; now regenerate: build/venv/bin/python tools/gen_headers.py" % os.path.relpath(EVIDENCE, ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
