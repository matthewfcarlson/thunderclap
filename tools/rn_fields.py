#!/usr/bin/env python3
"""Header fields from the stubs (consolidation batch b7, docs/consolidation-plan.md): put the field offsets every
stub of a class agrees on into include/gen/, inside the class's own `_pad_` gaps only.

  build/venv/bin/python tools/rn_fields.py                 # plan: what would be added (build/rn1/fields-plan.json)
  build/venv/bin/python tools/rn_fields.py --apply         # rewrite include/gen/*.h
  build/venv/bin/python tools/rn_fields.py --apply --check # ... and prove no existing layout moved (clang)

Input: build/rn1/header-additions.json (tools/rn_layout.py: per class, offsets where every stub that touches the
offset agrees on size and kind) and build/rn1/header-db.json (clang's layouts of the headers as they are).

Rules, chosen so that no existing offset or size can change (the 32-bit layout is the original's):
  - scalars only: 4-byte int -> `int`, float -> `float`, pointer -> `void*`, 2-byte int -> `short`, 1-byte
    int -> `char` (sources whose stub has another type of the same size get a cast, as gen-swap does today);
  - the field lies inside one `char _pad_XX[N];` of the class itself (absolute offsets, the generator's
    convention) and is naturally aligned; the pad is split into pad / field / pad;
  - an offset in a base's extent goes to that base (pads hold absolute offsets, so it is the base's pad that
    is split) when no class's stubs disagree there and all agreeing classes name one type; offsets past the
    class's end or where a header field already sits are left out (they would change sizes);
  - a class head that occurs more than once in its header with the same pad (two namespaces) is skipped.
The applied fields are also written to include/gen/evidence-rn.json, which tools/gen_headers.py reads like its
curated fields (gen-swap and gen-ref take field names from the generator's model). `--check` re-lays out every include/gen/ class with clang before and after: every old field keeps its offset
and type, every size is the same.
"""
import argparse
import collections
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import rn_layout  # noqa: E402

ROOT = rn_layout.ROOT
ADD = os.path.join(ROOT, "build/rn1/header-additions.json")
PLAN = os.path.join(ROOT, "build/rn1/fields-plan.json")
TYPES = {(4, "int"): "int", (4, "float"): "float", (4, "ptr"): "void*", (2, "int"): "short", (1, "int"): "char"}
PAD_RX = re.compile(r"^(\s*)char _pad_([0-9a-f]+)\[0x([0-9a-f]+)\];\s*$")


def class_heads(text, short):
    """Line indices of `class|struct <short>` definitions (not forward declarations)."""
    rx = re.compile(r"^\s*(?:class|struct)\s+%s\b(?:\s*:[^;{]*)?\s*\{" % re.escape(short))
    return [i for i, l in enumerate(text) if rx.match(l)]


def body_lines(lines, head):
    """Indices of the lines of the class body starting at `head` (brace depth 1)."""
    depth, out = 0, []
    for i in range(head, len(lines)):
        depth += lines[i].count("{") - lines[i].count("}")
        if i > head:
            if depth <= 0:
                break
            if depth == 1:
                out.append(i)
    return out


def owner(db, cls, off, sizes=None):
    """(class, offset in it) that owns absolute offset `off` of `cls`: the base subobject whose extent holds it
    (recursively), else `cls` itself. `sizes`: class sizes that override the header's (--grow)."""
    for boff, bname, _ in db[cls].get("bases", []):
        b = db.get(bname)
        bs = (sizes or {}).get(bname, b["size"] if b else 0)
        if b and bs and boff <= off < boff + bs:
            return owner(db, bname, off - boff, sizes)
    return cls, off


def descendants(db):
    """{class: [(derived class, absolute offset of the class in it)]}, transitively."""
    kids = collections.defaultdict(list)
    for n, h in db.items():
        for boff, b, _ in h.get("bases", []):
            kids[b].append((n, boff))
    out = {}

    def walk(c, m, acc):
        for k, o in kids.get(c, []):
            acc.append((k, m + o))
            walk(k, m + o, acc)
    for c in db:
        acc = []
        walk(c, 0, acc)
        out[c] = acc
    return out


def growth(db, adds):
    """--grow: {class: new size} for classes whose stubs agree on fields past the header class's end. A class may
    grow up to the first header field or base of a derived class that lies past its current end (where the
    derived class's own part starts today); template instantiations are left alone (they share one generator
    unit). The derived classes' fields keep their absolute offsets: the generator pads their own part from the
    new base end."""
    desc = descendants(db)
    votes = collections.defaultdict(lambda: collections.defaultdict(set))
    against = set()
    for cls, a in adds.items():
        if cls not in db:
            continue
        for off_s in a.get("disagree", {}):
            against.add(owner(db, cls, int(off_s, 16)))
        for off_s, f in a["agree"].items():
            t = TYPES.get((f["size"], f["kind"]))
            if t is None:
                continue
            c, o = owner(db, cls, int(off_s, 16))
            if o >= db[c]["size"]:
                votes[c][o].add((f["size"], t))
    out = {}
    for c, offs in votes.items():
        if "<" in c:
            continue
        size = db[c]["size"]
        lim = None
        for k, m in desc[c]:
            for fo, _ft, fn in db[k]["fields"]:
                if not fn.startswith("_pad_") and fo >= m + size:
                    lim = fo - m if lim is None else min(lim, fo - m)
            for bo, _bn, _ in db[k].get("bases", []):
                if bo >= m + size:
                    lim = bo - m if lim is None else min(lim, bo - m)
        end = size
        for o, ts in offs.items():
            if len(ts) != 1 or (c, o) in against:
                continue
            sz = next(iter(ts))[0]
            if o % sz or (lim is not None and o + sz > lim):
                continue
            end = max(end, o + sz)
        if end > size:
            out[c] = end + (-end) % 4
    return out


def plan(db, adds, grow=None):
    """Fields to add, per header: [(owner class, offset, type)]. An offset a derived class's stubs agree on that
    lies in a base's extent goes to that base (every class derived from it sees the field), so it is kept only
    if no class's stubs disagree on it there and every class that agrees names the same type. `grow`
    ({class: new size}, growth()): fields past a class's end up to its new size are planned too."""
    grow = grow or {}
    votes = collections.defaultdict(set)       # (owner, off) -> {(size, type)}
    against = set()
    why = collections.Counter()
    for cls, a in adds.items():
        h = db.get(cls)
        if h is None:
            why["class not in header-db (template or unknown)"] += len(a["agree"])
            continue
        for off_s in a.get("disagree", {}):
            against.add(owner(db, cls, int(off_s, 16), grow))
        for off_s, f in a["agree"].items():
            off, size = int(off_s, 16), f["size"]
            t = TYPES.get((size, f["kind"]))
            if t is None:
                why["not a scalar (%s)" % f["kind"]] += 1
                continue
            votes[owner(db, cls, off, grow)].add((size, t))
    out = collections.defaultdict(list)
    for (cls, off), ts in sorted(votes.items()):
        h = db[cls]
        flds, gaps = rn_layout.header_fields(h)
        if (cls, off) in against:
            why["another class's stubs disagree at that base offset"] += 1
            continue
        if len(ts) != 1:
            why["classes disagree on the type"] += 1
            continue
        size, t = next(iter(ts))
        if off in {o for o, _, _ in flds}:
            why["header already has a field there"] += 1
            continue
        if off % size:
            why["misaligned"] += 1
            continue
        if not any(lo <= off and off + size <= hi for lo, hi in gaps):
            if h["size"] <= off and off + size <= grow.get(cls, 0):
                out[h["header"]].append((cls, off, t))
                why["planned past the class's end (--grow)"] += 1
                continue
            why["not inside a pad (past the class's end, straddles a field)"] += 1
            continue
        out[h["header"]].append((cls, off, t))
        why["planned"] += 1
    return out, why


def apply(plan_):
    """Rewrite the headers; returns (per-header counts, skips, {class: {offset: type}} as applied)."""
    applied, skipped = collections.Counter(), collections.Counter()
    done = {}
    for hdr, items in plan_.items():
        p = os.path.join(ROOT, "include/gen", hdr)
        lines = open(p, encoding="latin1").read().split("\n")
        by_cls = collections.defaultdict(list)
        for cls, off, t in items:
            by_cls[cls].append((off, t))
        edits = {}                                     # line index -> replacement lines
        for cls, fl in by_cls.items():
            short = cls.split("::")[-1]
            heads = class_heads(lines, short)
            # the head whose body has the pads the plan splits
            cand = []
            for hd in heads:
                pads = {}
                for i in body_lines(lines, hd):
                    m = PAD_RX.match(lines[i])
                    if m:
                        pads[i] = (int(m.group(2), 16), int(m.group(3), 16), m.group(1))
                if all(any(lo <= off < lo + n for lo, n, _ in pads.values()) for off, _ in fl):
                    cand.append(pads)
            if len(cand) != 1:
                skipped["class head not unique in %s" % hdr] += len(fl)
                continue
            pads = cand[0]
            for i, (lo, n, ind) in pads.items():
                inside = sorted((off, t) for off, t in fl if lo <= off < lo + n)
                if not inside or i in edits:
                    continue
                rep, cur = [], lo
                for off, t in inside:
                    size = {"int": 4, "float": 4, "void*": 4, "short": 2, "char": 1}[t]
                    if off < cur or off + size > lo + n:
                        continue
                    if off > cur:
                        rep.append("%schar _pad_%02x[0x%x];" % (ind, cur, off - cur))
                    rep.append("%s%s f_%02x;" % (ind, t, off))
                    cur = off + size
                    applied[hdr] += 1
                    done.setdefault(cls, {})["0x%x" % off] = t
                if cur < lo + n:
                    rep.append("%schar _pad_%02x[0x%x];" % (ind, cur, lo + n - cur))
                edits[i] = rep
        new = []
        for i, l in enumerate(lines):
            new.extend(edits.get(i, [l]))
        with open(p, "w", encoding="latin1", newline="") as f:
            f.write("\n".join(new))
    return applied, skipped, done


def check(before, after, may_grow=()):
    """Old fields keep offsets and types, sizes stay (or grow, for `may_grow`): [problems]."""
    bad = []
    for cls, h in before.items():
        a = after.get(cls)
        if a is None:
            bad.append("%s: no longer laid out" % cls)
            continue
        if a["size"] != h["size"] and not (cls in may_grow and a["size"] > h["size"]):
            bad.append("%s: size %s -> %s" % (cls, h["size"], a["size"]))
        af = {(o, t, n) for o, t, n in map(tuple, a["fields"])}
        for o, t, n in map(tuple, h["fields"]):
            if not n.startswith("_pad_") and (o, t, n) not in af:
                bad.append("%s: field %s at %#x moved or changed" % (cls, n, o))
    return bad


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--grow", action="store_true",
                    help="also fields past a class's end (growth()): written to evidence-rn.json, then include/gen/ "
                         "is regenerated with tools/gen_headers.py (the derived classes' pads move with the base)")
    a = ap.parse_args(argv)
    db = rn_layout.load_db()
    adds = json.load(open(ADD))
    grow = growth(db, adds) if a.grow else {}
    pl, why = plan(db, adds, grow)
    json.dump({h: v for h, v in pl.items()}, open(PLAN, "w"), indent=0)
    if grow:
        print("grow: %d classes" % len(grow))
    print("plan: %s" % json.dumps(dict(why.most_common())))
    if not a.apply:
        return 0
    if a.grow:
        done, applied, skipped = {}, collections.Counter(), collections.Counter()
        for hdr, items in pl.items():
            for cls, off, t in items:
                done.setdefault(cls, {})["0x%x" % off] = t
                applied[hdr] += 1
    else:
        applied, skipped, done = apply(pl)
    # the same fields for tools/gen_headers.py's model (gen-swap / gen-ref read the generator's emitted fields,
    # not the header text): include/gen/evidence-rn.json, applied like CURATED_FIELDS
    ev = os.path.join(ROOT, "include/gen/evidence-rn.json")
    evd = json.load(open(ev)) if os.path.exists(ev) else {}
    old = evd.get("fields", {})
    for cls, fl in done.items():
        old.setdefault(cls, {}).update(fl)
    # keep the file's other entries ("sigs": tools/rn_sigs.py, batch b6)
    evd["_comment"] = ("Fields added to include/gen/ by tools/rn_fields.py (consolidation batch b7): offsets "
                       "every stub of the class agrees on, inside the class's own _pad_ gaps or (--grow) past "
                       "its end.")
    evd["fields"] = {k: dict(sorted(v.items(), key=lambda kv: int(kv[0], 16))) for k, v in sorted(old.items())}
    with open(ev, "w") as f:
        json.dump(evd, f, indent=1)
    print("applied: %d fields (%s); skipped: %s" % (sum(applied.values()), dict(applied), dict(skipped)))
    if a.grow:
        import gen_headers
        gen_headers.main([])
    if a.check:
        after = rn_layout.build_db()
        may = set(grow)
        for c in grow:
            may |= {k for k, _ in descendants(db)[c]}
        bad = check(db, after, may)
        print("check: %d classes, %d problems" % (len(db), len(bad)))
        for b in bad[:20]:
            print("  " + b)
        return 1 if bad else 0
    return 0


if __name__ == "__main__":
    sys.exit(main())
