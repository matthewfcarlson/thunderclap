#!/usr/bin/env python3
"""Token-level fixes to matches/ and equivalent/ sources whose names are genuinely wrong, so that the source tree
(tools/gen_tree.py) can merge them. Re-runnable: a second run on an unchanged corpus plans nothing.

  build/venv/bin/python tools/reconcile_stubs.py              # plan only: what would change, and what is skipped
  build/venv/bin/python tools/reconcile_stubs.py --apply      # rewrite the sources, log to build/reconcile-stubs.log
  build/venv/bin/python tools/reconcile_stubs.py --apply --only matches/0x0002c110.cpp

Rules (each one renames identifier tokens only; comments, strings and preprocessor lines stay byte-for-byte):

  clone-free   A clone-propagated source defines its donor's address name (`FUN_00025410` in
               matches/0x0002c110.cpp). The definition gets its own address name (`FUN_0002c110`, from
               build/functions.csv). Two clones of one donor in one object otherwise define the same function.
  clone-class  A clone-propagated source defines `A::m` while build/functions.csv names the function `B::m`
               (B a plain global class name, the same member name). Every `A` of the source becomes `B`: the
               source's stub of A is the stand-in for the target's own class.

Not touched: template targets (`Method1<CActorManager,bool,math::Vector>::vfunc_0`: no source spelling for them
yet), targets whose class is namespaced, sources whose `// equiv-*` lines, preprocessor lines or function-like
macros mention the old name, sources that already use the new name, and equivalent/ sources shadowed by a
matches/ source of the same address. Renaming changes mangled names only, which compare.py masks (relocations)
and equiv.py doesn't bind by (it binds address names by their address), but every changed source is
re-verified anyway (see docs/source-tree.md).
"""
import argparse
import csv
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import rename_placeholders as rp  # noqa: E402

ROOT = rp.ROOT
LOG = os.path.join(ROOT, "build/reconcile-stubs.log")
ORIG = os.path.join(ROOT, "build/stubs-orig")
PLAIN = re.compile(r"[A-Za-z_]\w*$")
FUN_NAME = re.compile(r"FUN_[0-9a-f]{8}$")


def load_names():
    out = {}
    with open(os.path.join(ROOT, "build/functions.csv")) as f:
        for r in csv.DictReader(f):
            out[int(r["address"], 16)] = r["name"]
    return out


def namespaced_rtti():
    """Simple names of RTTI classes that live in a namespace (a plain `B` target may not stand for them)."""
    out = set()
    try:
        for c in json.load(open(os.path.join(ROOT, "build/rtti.json")))["classes"]:
            n = re.sub(r"\b(class|struct|enum|union) ", "", c.get("name") or "")
            n = re.sub(r"<.*", "", n)
            if "::" in n:
                out.add(n.split("::")[-1])
    except (OSError, ValueError):
        sys.exit("build/rtti.json is needed")
    return out


def base_names(it):
    vs = [t.v for t in it.toks]
    head = vs[:vs.index("{")] if "{" in vs else vs
    return set(head[head.index(":") + 1:]) if ":" in head else set()


def plan_source(src, target, ns_rtti):
    """(rule, {old: new}) or (None, why-skipped) for one source."""
    if not src.ok:
        return None, "does not parse"
    try:
        items = cxx_items.parse(src.text)
    except ValueError:
        return None, "does not parse"
    defs = [it for it in items if it.kind == "funcdef" and not it.is_inline
            and not it.key[0].startswith("template")]
    if len(defs) != 1:
        return None, None
    d = defs[0]
    name = d.key[1]
    if d.scope or name == target:
        return None, None
    own = "FUN_%08x" % src.addr
    if "::" not in name:
        if not FUN_NAME.match(name) or target != own:
            return None, None
        rule, mapping = "clone-free", {name: own}
    else:
        a, m = name.rsplit("::", 1)
        if "::" in a or "<" in target or target.count("::") != 1:
            return None, ("template target" if "<" in target else None)
        b, m2 = target.split("::")
        if m != m2 or not PLAIN.match(b) or not PLAIN.match(a) or a == b:
            return None, None
        if b in ns_rtti:
            return None, "target class %s is namespaced in RTTI" % b
        if not any(it.kind == "class" and it.key[1] == a for it in items):
            return None, "no class definition of %s in the source" % a
        if any(it.kind == "class" and a in base_names(it) for it in items):
            return None, "%s is also a base class in the source" % a
        rule, mapping = "clone-class", {a: b}
    for old, new in mapping.items():
        why = src.blockers(old, new)
        if why:
            return None, "%s: %s" % (rule, why)
    return rule, mapping


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true", help="rewrite the sources (default: plan only)")
    ap.add_argument("--only", nargs="*", help="limit to these source paths (matches/0x....cpp)")
    ap.add_argument("--rule", choices=("clone-free", "clone-class"), action="append", help="only these rules")
    ap.add_argument("--changed", default=os.path.join(ROOT, "build/stubs-changed.txt"),
                    help="append changed paths here (default build/stubs-changed.txt)")
    a = ap.parse_args(argv)
    names = load_names()
    ns_rtti = namespaced_rtti()
    srcs = rp.load_sources()
    in_matches = {s.addr for s in srcs if s.rel.startswith("matches/")}
    planned, skipped = [], {}
    for s in srcs:
        if a.only and s.rel not in a.only:
            continue
        if s.rel.startswith("equivalent/") and s.addr in in_matches:
            continue
        target = names.get(s.addr)
        if target is None:
            continue
        rule, m = plan_source(s, target, ns_rtti)
        if rule is None:
            if m:
                skipped[m] = skipped.get(m, 0) + 1
            continue
        if a.rule and rule not in a.rule:
            continue
        planned.append((s, rule, m))
    by_rule = {}
    for s, rule, m in planned:
        by_rule[rule] = by_rule.get(rule, 0) + 1
    print("planned: %d sources %s" % (len(planned), json.dumps(by_rule)))
    for why, n in sorted(skipped.items(), key=lambda x: -x[1])[:20]:
        print("  skipped %5d  %s" % (n, why))
    if not a.apply:
        for s, rule, m in planned[:40]:
            print("  %s %s %s" % (s.rel, rule, m))
        return 0
    os.makedirs(os.path.dirname(LOG), exist_ok=True)
    with open(LOG, "a") as log, open(a.changed, "a") as ch:
        for s, rule, m in planned:
            new = s.renamed_text(m)
            if new == s.text:
                continue
            keep = os.path.join(ORIG, s.rel)                 # the text before the first rewrite, for re-verification
            if not os.path.exists(keep):
                os.makedirs(os.path.dirname(keep), exist_ok=True)
                with open(keep, "w", encoding="latin1", newline="") as f:
                    f.write(s.text)
            with open(os.path.join(ROOT, s.rel), "w", encoding="latin1", newline="") as f:
                f.write(new)
            log.write(json.dumps({"file": s.rel, "rule": rule, "rename": m}) + "\n")
            ch.write(s.rel + "\n")
    print("rewrote %d sources (log: %s)" % (len(planned), os.path.relpath(LOG, ROOT)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
