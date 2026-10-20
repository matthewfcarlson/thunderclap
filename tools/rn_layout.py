#!/usr/bin/env python3
"""Layouts of the include/gen/ classes as clang lays them out (MS ABI, i686), and how each stub class of the rename
map (tools/rn_map.py) fits its real class's header layout (docs/consolidation-plan.md).

  build/venv/bin/python tools/rn_layout.py            # build/rn1/header-db.json + build/rn1/layout-fit.json
  build/venv/bin/python tools/rn_layout.py --class CAction

Header side: one probe TU includes gen/all.h, takes sizeof() of every non-template class and deletes through a
pointer to it, with -fdump-record-layouts / -fdump-vtable-layouts: fields at absolute offsets (bases included,
`_pad_` gaps kept as gaps) and the primary vftable (slot -> name, return type, parameters). The real headers are
read, not regenerated from evidence (they carry hand-corrected signatures).

Stub side: tools/stub_layout.py's model of the source's class (MSVC x86 /Zp8): absolute fields and vftable slots.

Fit per stub field: `same` (header field at that offset, same type), `cast` (same size, pointer vs void* or other
4-byte scalar: a `(*(T*)&p->f_XX)` cast), `ptr-int` (a pointer on one side and an integer on the other: a 64-bit
gap), `lacks` (the offset is inside a header `_pad_` gap or past the header's fields: a field to add to include/gen/),
`conflict` (a different size or float vs integer, or straddling two header fields). Per stub slot: `same`/`arity`
(the header slot takes another number of parameters)/`beyond` (past the header's vftable).
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cxx_items  # noqa: E402
import stub_layout  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
CLANG = ["clang", "-target", "i686-pc-windows-msvc", "-fms-extensions", "-fms-compatibility", "-w"]
DB = os.path.join(ROOT, "build/rn1/header-db.json")


def gen_class_names():
    """Qualified names of the non-template classes include/gen/ defines (from its class heads)."""
    out = []
    gdir = os.path.join(ROOT, "include/gen")
    for fn in sorted(os.listdir(gdir)):
        if not fn.endswith(".h") or fn in ("all.h", "_prelude.h"):
            continue
        text = open(os.path.join(gdir, fn), encoding="latin1").read()
        items = cxx_items.parse(text)
        for it in items:
            if it.kind == "class" and it.key[0] == "class" and "<" not in it.key[1] and \
                    not it.text.lstrip().startswith("template"):
                out.append((it.key[1], fn))
    return out


def parse_record_layouts(text):
    """{record: {"size": n, "fields": [(off, type, name, depth)], "vptr_at": [offs], "bases": [(off, name, kind)]}}"""
    out = {}
    cur = None
    for block in text.split("*** Dumping AST Record Layout")[1:]:
        lines = block.strip("\n").splitlines()
        head = re.match(r"\s*(\d+) \| (?:class|struct|union) (.+)$", lines[0])
        if not head:
            continue
        name = head.group(2).strip()
        rec = {"size": None, "fields": [], "vptr_at": [], "bases": []}
        for ln in lines[1:]:
            if rec["size"] is not None:
                break                                  # what follows is another dump (vftables)
            m = re.match(r"\s*(\d+) \| (\s*)(.*)$", ln)
            if m:
                off, depth, t = int(m.group(1)), len(m.group(2)) // 2, m.group(3)
                bm = re.match(r"(?:class|struct|union) (.+?) \((primary base|base|virtual base)\)$", t)
                if bm:
                    rec["bases"].append((off, bm.group(1), bm.group(2), depth))
                    continue
                if t.startswith("(") and "vftable pointer" in t:
                    rec["vptr_at"].append(off)
                    continue
                if t.startswith("("):
                    continue
                fm = re.match(r"(.*?)\s*(\w+)$", t)
                if fm:
                    rec["fields"].append((off, fm.group(1).strip(), fm.group(2), depth))
                continue
            sm = re.search(r"\[sizeof=(\d+)", ln)
            if sm:
                rec["size"] = int(sm.group(1))
        out.setdefault(name, rec)
    return out


def parse_vtables(text):
    """{class: [(index, ret, name, params)]} from "VFTable for 'Root' in ... in 'X'" blocks (index 0 = RTTI dropped,
    slots renumbered from 0); the first block of each class is kept (its primary vftable comes first)."""
    out = {}
    for block in re.split(r"\n(?=VFTable)", "\n" + text):
        m = re.match(r"VFTable for (.+?) \((\d+) entries\)\.", block.strip())
        if not m:
            continue
        chain = re.findall(r"'([^']+)'", m.group(1))
        cls = chain[-1]
        if cls in out:
            continue
        slots = []
        for ln in block.strip().splitlines()[1:]:
            lm = re.match(r"\s*(\d+) \| (.*)$", ln)
            if not lm:
                continue
            i, t = int(lm.group(1)), lm.group(2)
            if t.endswith(" RTTI"):
                continue
            t = re.sub(r" \[(pure|scalar deleting|this adjustment[^\]]*|return adjustment[^\]]*)\]", "", t).strip()
            dm = re.match(r"(.+)::~(\w+)\(\)$", t)
            if dm:
                slots.append([i - 1, "", "~", []])
                continue
            fm = re.match(r"(.*\S)\s+(\S+)::(\w+)\((.*)\)(?: const)?$", t)
            if not fm:
                slots.append([i - 1, "?", t, []])
                continue
            ps = [p.strip() for p in fm.group(4).split(",")] if fm.group(4).strip() else []
            slots.append([i - 1, fm.group(1).strip(), fm.group(3), ps])
        out[cls] = slots
    return out


def build_db(jobs=4):
    names = gen_class_names()
    os.makedirs(os.path.dirname(DB), exist_ok=True)
    probe = os.path.join(os.path.dirname(DB), "probe")
    os.makedirs(probe, exist_ok=True)
    db = {}
    # chunks: one huge TU is fine for clang, but a class that fails (abstract with a private dtor, ...) must not
    # sink the others
    chunk = 200
    for k in range(0, len(names), chunk):
        part = names[k:k + chunk]
        src = os.path.join(probe, "db_%03d.cpp" % (k // chunk))
        with open(src, "w") as f:
            f.write('#include "gen/all.h"\n')
            for i, (q, _) in enumerate(part):
                f.write("int s_%d = sizeof(::%s);\n" % (i, q))
                f.write("void t_%d(::%s* p) { delete p; }\n" % (i, q))
        r = subprocess.run(CLANG + ["-I", os.path.join(ROOT, "include"), "-c", "-o", os.devnull,
                                    "-Xclang", "-fdump-record-layouts", "-Xclang", "-fdump-vtable-layouts", src],
                           capture_output=True, text=True, errors="replace")
        if r.returncode != 0:
            print("probe %s failed: %s" % (src, r.stderr[:500]), file=sys.stderr)
        recs = parse_record_layouts(r.stdout)
        vts = parse_vtables(r.stdout + "\n" + r.stderr)
        for q, hdr in part:
            rec = recs.get(q)
            if rec is None:
                continue
            fields = [(o, t, n) for o, t, n, d in rec["fields"]]
            db[q] = {"header": hdr, "size": rec["size"], "fields": fields, "vptr": 0 in rec["vptr_at"],
                     "slots": vts.get(q, []),
                     "bases": [(o, b, kind) for o, b, kind, d in rec["bases"] if d == 1]}
    json.dump(db, open(DB, "w"), indent=0)
    return db


def load_db():
    if not os.path.exists(DB):
        return build_db()
    return json.load(open(DB))


# ---------------------------------------------------------------------------------------------
INTS = {"char", "signed char", "unsigned char", "short", "unsigned short", "int", "unsigned int", "long",
        "unsigned long", "bool", "__int64", "unsigned __int64", "wchar_t", "enum"}
FLOATS = {"float", "double", "long double"}


def kind_of(t):
    t = re.sub(r"\b(const|volatile|struct|class|union|enum)\b", "", t).strip()
    t = re.sub(r"\s+", " ", t)
    if t.endswith("*") or t.endswith("&") or t.startswith("<fnptr>"):
        return "ptr"
    if "[" in t:
        return "array"
    if t in FLOATS:
        return "float"
    if t in INTS or t in stub_layout.SYNONYM:
        return "int"
    return "other"


def header_fields(h):
    """[(off, size, type, name)] of real fields and [(off, end)] of gaps (pads and the tail)."""
    flds, gaps = [], []
    for o, t, n in h["fields"]:
        m = re.match(r"char\[(\d+)\]$", t.replace(" ", ""))
        size = None
        if n.startswith("_pad_") and m:
            gaps.append((o, o + int(m.group(1))))
            continue
        flds.append((o, t, n))
    return flds, gaps


def tsize(t):
    t = t.replace(" ", "")
    m = re.match(r"(.+)\[(\d+)\]$", t)
    if m:
        return tsize(m.group(1)) * int(m.group(2))
    if t.endswith("*"):
        return 4
    return {"char": 1, "signedchar": 1, "unsignedchar": 1, "bool": 1, "short": 2, "unsignedshort": 2,
            "wchar_t": 2, "double": 8, "__int64": 8, "unsigned__int64": 8, "longlong": 8}.get(t, 4)


def fit_field(f, h_fields, h_gaps, h_size):
    """'same' | 'cast' | 'ptr-int' | 'lacks' | 'conflict' for one stub Field."""
    for o, t, n in h_fields:
        s = tsize(t)
        if o == f.off:
            ks, kh = kind_of(f.type), kind_of(t)
            if s != f.size:
                if kh == "array" or ks == "array":
                    return "cast"
                return "conflict"
            if stub_layout.norm_type(f.type.split()) == stub_layout.norm_type(t.split()):
                return "same"
            if {ks, kh} == {"ptr", "int"}:
                return "ptr-int"
            if "float" in (ks, kh) and ks != kh:
                return "conflict"
            return "cast"
        if o < f.off + f.size and f.off < o + s:
            return "conflict"
    for a, b in h_gaps:
        if a <= f.off and f.off + f.size <= b:
            return "lacks"
    if h_size is not None and f.off >= max([o + tsize(t) for o, t, _ in h_fields] + [0]):
        return "lacks"
    return "conflict"


def used_names(items, stub):
    """Identifier tokens used outside the stub's own class definition (an upper bound of the members it uses)."""
    out = set()
    for it in items:
        if it.kind == "class" and it.key[1] == stub:
            continue
        out |= {t.v for t in it.toks if t.t == "id"}
    return out


def fit_entry(e, ctx, h, used=None):
    """{'fields': Counter, 'slots': Counter, 'detail': [...]} for one stub against its header class. With `used`,
    only members whose names occur outside the class definition count (the others are never touched)."""
    L = ctx.layout(e["stub"])
    hf, hg = header_fields(h)
    fc, sc, det, odd = collections.Counter(), collections.Counter(), [], []
    for f in L.fields:
        if f.name is None:
            continue
        if used is not None and f.name not in used:
            continue
        if re.match(r"(_?pad|pad_?|_pad_|unk|gap|_unk)\w*$", f.name or "") and kind_of(f.type) == "array":
            continue                                   # the stub's own padding
        if f.off == 0 and f.size == 4 and L.poly is False and re.search(r"vptr|vtbl|vtable|vft", f.name or "", re.I):
            fc["vptr-field"] += 1
            continue
        r = fit_field(f, hf, hg, h["size"])
        fc[r] += 1
        if r != "same":
            det.append("+0x%x %s %s: %s" % (f.off, f.type, f.name, r))
        if r in ("lacks", "conflict", "ptr-int", "cast"):
            odd.append([r, f.off, f.size, kind_of(f.type), stub_layout.norm_type(f.type.split())])
    hs = h["slots"]
    for i, s in enumerate(L.slots):
        name, params, ret, cv = s
        if used is not None and name not in used:
            continue
        if i >= len(hs):
            sc["beyond"] += 1
            det.append("slot %d %s: beyond the header's %d" % (i, name, len(hs)))
            continue
        hi = hs[i]
        if hi[2] == "~" or name.startswith("~"):
            sc["dtor"] += 1
            continue
        n_stub = 0 if params in ("", "void", None) else len(stub_layout.split_commas(params))
        if n_stub != len(hi[3]):
            sc["arity"] += 1
            det.append("slot %d %s(%s) vs header %s(%s)" % (i, name, params, hi[2], ", ".join(hi[3])))
        else:
            sc["same"] += 1
    return {"fields": dict(fc), "slots": dict(sc), "poly": L.poly, "size": L.size, "header_size": h["size"], "odd": odd,
            "detail": det[:12]}


def verdict(fit):
    f, s = fit["fields"], fit["slots"]
    if f.get("conflict") or s.get("beyond"):
        return "conflict"
    if fit["poly"] is False and f.get("vptr-field"):
        pass
    if f.get("lacks"):
        return "lacks"
    if s.get("arity"):
        return "arity"
    if f.get("ptr-int"):
        return "ptr-int"
    if f.get("cast"):
        return "cast"
    return "same"


def run(rmap_path, out_path, only=None):
    db = load_db()
    entries = json.load(open(rmap_path))["entries"]
    by_src = collections.defaultdict(list)
    for e in entries:
        if e["real"] and e["confidence"] in ("high", "medium") and e["real"] in db:
            if only and e["real"] not in only:
                continue
            by_src[e["source"]].append(e)
    res = []
    for src, es in sorted(by_src.items()):
        text = open(os.path.join(ROOT, src), encoding="latin1").read()
        try:
            items = cxx_items.parse(text)
            ctx = stub_layout.Context(items)
        except ValueError:
            continue
        for e in es:
            try:
                fit = fit_entry(e, ctx, db[e["real"]], used_names(items, e["stub"]))
                v = verdict(fit)
            except stub_layout.Unsupported as x:
                fit, v = {"error": str(x)[:80]}, "unsupported"
            res.append({"stub": e["stub"], "source": src, "real": e["real"], "confidence": e["confidence"],
                        "own": e["own"], "kind": e["kind"], "verdict": v, "fit": fit})
    json.dump({"comment": "tools/rn_layout.py: stub classes against their include/gen/ class", "entries": res},
              open(out_path, "w"), indent=0)
    return res


def additions(res):
    """Fields the header lacks, per class: offsets where every stub that touches them agrees (one size, one kind:
    int/float/ptr) are proposals for include/gen/ (tools/gen_headers.py evidence); the others disagree."""
    per = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
    srcs = collections.defaultdict(lambda: collections.defaultdict(set))
    for r in res:
        for kind, off, size, k, t in r.get("fit", {}).get("odd", ()):
            if kind == "lacks":
                per[r["real"]][off][(size, k)] += 1
                srcs[r["real"]][off].add(r["source"])
    out = {}
    for cls, offs in per.items():
        agree = {"0x%x" % o: {"size": next(iter(c))[0], "kind": next(iter(c))[1], "stubs": sum(c.values()),
                              "sources": len(srcs[cls][o])}
                 for o, c in sorted(offs.items()) if len(c) == 1}
        dis = {"0x%x" % o: {"%d %s" % k: n for k, n in c.items()} for o, c in sorted(offs.items()) if len(c) > 1}
        out[cls] = {"agree": agree, "disagree": dis}
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--map", default=os.path.join(ROOT, "build/rn1/rename-map.json"))
    ap.add_argument("--out", default=os.path.join(ROOT, "build/rn1/layout-fit.json"))
    ap.add_argument("--rebuild-db", action="store_true")
    ap.add_argument("--class", dest="cls", nargs="*")
    a = ap.parse_args(argv)
    if a.rebuild_db or not os.path.exists(DB):
        db = build_db()
        print("header db: %d classes" % len(db))
    res = run(a.map, a.out, a.cls)
    add = additions(res)
    json.dump(add, open(os.path.join(os.path.dirname(a.out), "header-additions.json"), "w"), indent=0)
    print("header additions: %d classes, %d fields where the stubs agree, %d offsets where they don't" % (
        len(add), sum(len(v["agree"]) for v in add.values()), sum(len(v["disagree"]) for v in add.values())))
    c = collections.Counter((r["kind"], r["own"], r["verdict"]) for r in res)
    for k in sorted(c):
        print(k, c[k])
    if a.cls:
        for r in res:
            print(json.dumps(r))
    return 0


if __name__ == "__main__":
    sys.exit(main())
