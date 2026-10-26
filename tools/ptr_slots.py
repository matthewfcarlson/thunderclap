#!/usr/bin/env python3
"""Pointer-sized parameters and returns of include/gen/ virtual slots (x64-5; docs/native-mac.md section 3).

  build/venv/bin/python tools/ptr1.py fix @files --out FIX.json            # (no --write) the per-source demands
  build/venv/bin/python tools/ptr_slots.py plan FIX.json --out PLAN.json   # slots, new signatures, sources to edit
  build/venv/bin/python tools/ptr_slots.py apply PLAN.json [--write]       # evidence-rn.json "sigs" + the sources'
                                                                           #   override definitions; then
                                                                           #   tools/gen_headers.py regenerates

What it removes. ptr1 leaves a pointer that travels through an `int` parameter or return of a virtual method alone
(`int CGrappleDamageTrack::vfunc_12(int __p0) { Target *t = (Target *)__p0; ...}`): every override of the slot
shares the signature, so one source cannot widen it. Here the slot is widened as a whole: the include/gen/ slot
signature (gen_headers.py's evidence-rn.json "sigs", which every override in the headers takes) and the out-of-line
definition of every override in every source on include/gen/ get `hulk_intptr` / `hulk_uintptr` (include/compat/
ptr.h: `int` / `unsigned int` on the 32-bit builds, so the MSVC 7.1 objects, mangled names included, stay the same)
at the positions some override uses as a pointer.

A slot is left alone when a demanded position is not `int` / `unsigned int` in the header, or an override
definition's spelling cannot be rewritten (a typedef'd parameter type, a template the regex can't read), or `--drop`
names it. Sources not on include/gen/ (their own stub classes) are not touched. `check` parses sources for the
64-bit MS target (libclang, ptr1's flags) and reports errors and -Woverloaded-virtual hits (a class of a source's own
whose in-class override of a widened slot would stop overriding on 64-bit), and the pointer-width diagnostics left.
"""
import argparse
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EVIDENCE = os.path.join(ROOT, "include/gen/evidence-rn.json")
WIDE = {"int": "hulk_intptr", "unsigned int": "hulk_uintptr", "unsigned": "hulk_uintptr",
        "hulk_intptr": "hulk_intptr", "hulk_uintptr": "hulk_uintptr"}
INCLUDE = '#include "compat/ptr.h"'


def gen():
    import migrate_gen as mg
    return mg.Gen.get()


def class_of(g, key):
    """The include/gen/ Cls of a demand key `?vfunc_N@<class>@@...`, and N; or None."""
    m = re.match(r"\?vfunc_(\d+)@(.*)$", key)
    if not m:
        return None
    rest = m.group(2)
    for i in range(len(rest)):
        if rest.startswith("@@", i):
            for k in ("V", "U"):
                c = g.by_mangled.get(".?A%s%s@@" % (k, rest[:i]))
                if c is not None:
                    return c, int(m.group(1))
    return None


def sources():
    for d in ("matches", "equivalent"):
        for fn in sorted(os.listdir(os.path.join(ROOT, d))):
            if re.fullmatch(r"0x[0-9a-fA-F]{8}\.cpp", fn):
                yield "%s/%s" % (d, fn)


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
    return out


PARAM_RE = re.compile(r"^(\s*)((?:const\s+)?)((?:unsigned\s+int|unsigned|int|hulk_intptr|hulk_uintptr))\b(\s*\w*\s*)$")
DEF_RE = r"(?m)^([ \t]*(?:virtual\s+)?)([\w:<>\s\*&]+?)(\s+)((?:[\w:]+::)?%s(?:\s*<(?:[^<>;{}()]|<[^<>;{}()]*>)*>)?\s*::vfunc_%d)\s*\(([^()]*)\)"


def rewrite_def(text, cls_short, slot, want_params, want_ret):
    """Rewrite every out-of-line definition head `R C::vfunc_N(P...)` of this class short name; returns (text,
    count, problem)."""
    rx = re.compile(DEF_RE % (re.escape(cls_short), slot))
    n, problem = 0, None
    out, last = [], 0
    for m in rx.finditer(text):
        lead, ret, sp, name, params = m.groups()
        ps = split_params(params)
        if ps == ["void"] or (not ps and want_params):
            ps = []
        newps = list(ps)
        for i in want_params:
            if i >= len(ps):
                problem = "%s: %d parameters, position %d demanded" % (name, len(ps), i)
                break
            pm = PARAM_RE.match(ps[i])
            if not pm:
                problem = "%s: parameter %d spelled %r" % (name, i, ps[i].strip())
                break
            t = re.sub(r"\s+", " ", pm.group(3))
            newps[i] = pm.group(1) + pm.group(2) + WIDE[t] + pm.group(4)
        if problem:
            break
        nret = ret
        if want_ret:
            rt = re.sub(r"\s+", " ", ret.strip())
            if rt not in WIDE:
                problem = "%s: return spelled %r" % (name, ret.strip())
                break
            nret = ret.replace(ret.strip(), WIDE[rt])
        out.append(text[last:m.start()])
        out.append(lead + nret + sp + name + "(" + ",".join(newps) + ")")
        last = m.end()
        n += 1
    out.append(text[last:])
    return "".join(out), n, problem


def add_include(text):
    if "compat/ptr.h" in text:
        return text
    lines = text.split("\n")
    i = 0
    while i < len(lines) - 1 and (lines[i].startswith("//") or not lines[i].strip()):
        i += 1
    j = i
    while j > 0 and not lines[j - 1].strip():
        j -= 1
    return "\n".join(lines[:j] + [INCLUDE] + lines[j:])


def plan(a):
    g = gen()
    fix = json.load(open(a.fix))
    dem = collections.defaultdict(lambda: {"params": set(), "ret": False, "from": set()})
    nokey = collections.Counter()
    for f, v in fix.items():
        for d in v.get("demands", []):
            if d[0] not in ("param", "ret"):
                continue
            r = class_of(g, d[1])
            if r is None:
                nokey["not an include/gen/ vfunc"] += 1
                continue
            c, n = r
            if 0 not in c.vtables or n >= len(c.vtables[0]):
                nokey["no such slot"] += 1
                continue
            key = g.resolve(c, 0, n)
            if key in g.dtor:
                nokey["destructor slot"] += 1
                continue
            e = dem[key]
            if d[0] == "param":
                e["params"].add(d[2])
            else:
                e["ret"] = True
            e["from"].add(f)
    # every class on each slot: {slot index: {class short name: key}}
    by_slot = collections.defaultdict(lambda: collections.defaultdict(set))
    for c in g.classes:
        vt = c.vtables.get(0, [])
        for i in range(len(vt)):
            k = g.resolve(c, 0, i)
            if k in dem:
                by_slot[i][re.sub(r"<.*", "", c.name).split("::")[-1]].add(k)
    texts = {}
    for s in sources():
        texts[s] = open(os.path.join(ROOT, s), encoding="latin1", newline="").read()
    props, skipped = {}, {}
    for key, e in sorted(dem.items()):
        uid, slot = key
        ret, params = g.signature(key)
        name = None
        for c in g.classes:
            if c.unit.uid == uid:
                name = "%s::vfunc_%d" % (gh_csv(c.name), slot)
                break
        why = None
        newp = list(params)
        for i in sorted(e["params"]):
            if i >= len(params):
                why = "position %d past the header's %d parameters" % (i, len(params))
                break
            if params[i] not in WIDE:
                why = "header parameter %d is %s" % (i, params[i])
                break
            newp[i] = WIDE[params[i]]
        nret = ret
        if not why and e["ret"]:
            if ret not in WIDE:
                why = "header returns %s" % ret
            else:
                nret = WIDE[ret]
        classes = {cl for cl, ks in by_slot[slot].items() if key in ks}
        edits, problems = {}, []
        if not why:
            decl_rx = re.compile(r"\bvfunc_%d\s*\(" % slot)
            for s, t in texts.items():
                if '#include "gen/' not in t or not decl_rx.search(t):
                    continue
                nt, total = t, 0
                for cl in sorted(classes):
                    nt, k, prob = rewrite_def(nt, cl, slot, sorted(e["params"]), e["ret"])
                    if prob:
                        problems.append("%s: %s" % (s, prob))
                    total += k
                if total:
                    edits[s] = nt
        if not why and problems:
            why = "definitions not rewritable: " + "; ".join(problems[:3])
        if why:
            skipped[name] = {"why": why, "demanded_by": sorted(e["from"])}
            continue
        props[name] = {"key": list(key), "old": [ret, params], "new": [nret, newp], "demanded_by": sorted(e["from"]),
                       "edit": sorted(edits)}
    json.dump({"props": props, "skipped": skipped, "nokey": dict(nokey)}, open(a.out, "w"), indent=1)
    srcs = {s for p in props.values() for s in p["edit"]}
    dsrc = {s for p in props.values() for s in p["demanded_by"]}
    for n_, p in sorted(props.items()):
        print("  %-55s %s -> %s  edits %d, demanded by %d" % (n_, p["old"], p["new"], len(p["edit"]), len(p["demanded_by"])))
    for n_, w in sorted(skipped.items()):
        print("  skip %-50s %s" % (n_, w["why"][:160]))
    print("%d slots: %d proposed (%d sources edited, %d demanding), %d skipped; not slots: %s" % (
        len(dem), len(props), len(srcs), len(dsrc), len(skipped), dict(nokey)))


def gh_csv(name):
    import gen_headers as gh
    return gh.csv_name(name)


def apply(a):
    p = json.load(open(a.plan))
    g = gen()
    drop = set(a.drop or [])
    edits = collections.defaultdict(list)       # source -> [(cls short names, slot, params, ret)]
    for name, pr in p["props"].items():
        if name in drop:
            continue
        uid, slot = pr["key"]
        key = (uid, slot)
        classes = set()
        for c in g.classes:
            vt = c.vtables.get(0, [])
            if slot < len(vt) and g.resolve(c, 0, slot) == key:
                classes.add(re.sub(r"<.*", "", c.name).split("::")[-1])
        oldp, newp = pr["old"][1], pr["new"][1]
        want = [i for i in range(len(oldp)) if oldp[i] != newp[i]]
        for s in pr["edit"]:
            edits[s].append((classes, slot, want, pr["old"][0] != pr["new"][0]))
    changed = []
    for s, items in sorted(edits.items()):
        path = os.path.join(ROOT, s)
        t = open(path, encoding="latin1", newline="").read()
        nt = t
        for classes, slot, want, wret in items:
            for cl in sorted(classes):
                nt, _, prob = rewrite_def(nt, cl, slot, want, wret)
                if prob:
                    raise SystemExit("%s: %s" % (s, prob))
        if nt != t:
            nt = add_include(nt)
            changed.append(s)
            if a.write:
                open(path, "w", encoding="latin1", newline="").write(nt)
    if a.write:
        ev = json.load(open(EVIDENCE))
        sigs = ev.setdefault("sigs", {})
        for name, pr in sorted(p["props"].items()):
            if name not in drop:
                sigs[name] = pr["new"]
        json.dump(ev, open(EVIDENCE, "w"), indent=1)
    if a.list:
        open(a.list, "w").write("".join(s + "\n" for s in changed))
    print("%d sources %s; %d slot signatures%s" % (len(changed), "rewritten" if a.write else "would change",
                                                   len(p["props"]) - len(drop & set(p["props"])),
                                                   " written to include/gen/evidence-rn.json" if a.write else ""))


def _check_one(path):
    import ptr1
    import clang.cindex as ci
    src = open(path, "rb").read()
    out = {"errors": [], "hidden": [], "w64": 0}
    for target in ("x86_64-pc-windows-msvc", "i686-pc-windows-msvc"):
        tu = ci.Index.create().parse(path, args=ptr1.args(target) + ["-Woverloaded-virtual"],
                                     unsaved_files=[(path, src)])
        for d in tu.diagnostics:
            here = d.location.file and d.location.file.name == path
            if d.severity >= 3:
                out["errors"].append("%s %s:%d %s" % (target[:4], os.path.basename(str(d.location.file)),
                                                      d.location.line, d.spelling[:160]))
            elif here and d.option == "-Woverloaded-virtual" and target.startswith("x86_64"):
                out["hidden"].append("%d %s" % (d.location.line, d.spelling[:200]))
            elif here and d.option in ptr1.WARNS and target.startswith("x86_64"):
                out["w64"] += 1
    return os.path.relpath(path, ROOT), out


def check(a):
    from concurrent.futures import ProcessPoolExecutor
    files = []
    for f in a.files:
        if f.startswith("@"):
            files += [x.strip() for x in open(f[1:]) if x.strip()]
        else:
            files.append(f)
    res = {}
    with ProcessPoolExecutor(a.jobs) as ex:
        for rel, r in ex.map(_check_one, [os.path.join(ROOT, f) for f in files], chunksize=8):
            res[rel] = r
    json.dump(res, open(a.out, "w"), indent=1)
    print("%d sources: %d with errors, %d with hidden virtuals, %d pointer-width diagnostics" % (
        len(res), sum(1 for r in res.values() if r["errors"]), sum(1 for r in res.values() if r["hidden"]),
        sum(r["w64"] for r in res.values())))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("plan")
    p.add_argument("fix")
    p.add_argument("--out", required=True)
    q = sub.add_parser("apply")
    q.add_argument("plan")
    q.add_argument("--write", action="store_true")
    q.add_argument("--drop", nargs="*")
    q.add_argument("--list", help="write the changed sources here")
    c = sub.add_parser("check")
    c.add_argument("files", nargs="+")
    c.add_argument("--out", required=True)
    c.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    return {"plan": plan, "apply": apply, "check": check}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
