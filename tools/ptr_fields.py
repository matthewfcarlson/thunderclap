#!/usr/bin/env python3
"""Pointers kept in 4-byte integer fields and read through a pointer pun: `*(T**)&p->f_20` (docs/native-mac.md).

  build/venv/bin/python tools/ptr_fields.py scan [FILE...] --out OUT.jsonl   # default: every source with such a pun
  build/venv/bin/python tools/ptr_fields.py summary OUT.jsonl [...]          # fields by owner (include/gen/ or source)

On the 32-bit builds `*(File**)&this->f_20` reads the 4-byte `int f_20` as a pointer. With 8-byte pointers it reads
f_20 and the 4 bytes after it, and a store writes both: the field has to be pointer-sized. The -Wshorten / pointer-int
diagnostics never see this (there is no conversion, only a reinterpretation), so this scanner finds them with
libclang (tools/ptr1.py's parse, msvc64 target): every `*` of a cast to pointer-to-pointer (or to an integer of
pointer width) of `&field`, where field is an integer of 4 bytes. Per field it records where the field is declared
(an include/gen/ header or the source itself), the pointer puns, and every other access type, so a field is a
candidate for `hulk_intptr` / `hulk_uintptr` (int / unsigned on the 32-bit builds: MSVC 7.1's code is unchanged)
when its non-pointer uses are integers of the same size.

include/gen/ is generated (tools/gen_headers.py): field types belong in the generator's inputs, not in hand edits.
"""
import argparse
import collections
import concurrent.futures
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ptr1  # noqa: E402

ci, CK, TK = ptr1.ci, ptr1.CK, ptr1.TK
ROOT = ptr1.ROOT
PUN = re.compile(rb"\*\s*\(\s*[A-Za-z_][\w:<>, ]*\s*\*\s*\*?\s*\)\s*&")


def strip(c):
    while c.kind in (CK.PAREN_EXPR, CK.UNEXPOSED_EXPR):
        k = list(c.get_children())
        if len(k) != 1:
            break
        c = k[0]
    return c


def is_cast(c):
    return c.kind in ptr1.CASTS


def field_of(addr):
    """`&x.f` / `&p->f` -> the FieldDecl cursor, else None."""
    if addr.kind != CK.UNARY_OPERATOR:
        return None
    toks = [t.spelling for t in addr.get_tokens()]
    if not toks or toks[0] != "&":
        return None
    k = list(addr.get_children())
    if len(k) != 1:
        return None
    m = strip(k[0])
    if m.kind == CK.MEMBER_REF_EXPR and m.referenced is not None and m.referenced.kind == CK.FIELD_DECL:
        return m
    return None


def scan_file(path):
    src = open(path, "rb").read()
    if not PUN.search(src):
        return []
    idx = ci.Index.create()
    tu = idx.parse(path, args=ptr1.args("x86_64-pc-windows-msvc"), unsaved_files=[(path, src)])
    out = []
    stack = [c for c in tu.cursor.get_children() if c.location.file and c.location.file.name == path]
    while stack:
        c = stack.pop()
        stack.extend(c.get_children())
        if c.kind != CK.UNARY_OPERATOR:
            continue
        kids = list(c.get_children())
        if len(kids) != 1:
            continue
        cast = strip(kids[0])
        if not is_cast(cast):
            continue
        t = cast.type.get_canonical()
        if t.kind != TK.POINTER:
            continue
        pointee = t.get_pointee().get_canonical()
        ck = [x for x in cast.get_children() if x.kind not in (CK.TYPE_REF, CK.NAMESPACE_REF, CK.TEMPLATE_REF)]
        if not ck:
            continue
        m = field_of(strip(ck[-1]))
        if m is None:
            continue
        # a `*` deref: the unary operator's first token
        first = next(iter(c.get_tokens()), None)
        if first is None or first.spelling != "*":
            continue
        f = m.referenced
        ft = f.type.get_canonical()
        if ft.kind not in (TK.INT, TK.UINT, TK.LONG, TK.ULONG) or ft.get_size() != 4:
            continue
        if pointee.kind == TK.POINTER or pointee.kind == TK.MEMBERPOINTER:
            use = "pointer"
        elif pointee.kind in (TK.FLOAT,):
            use = "float"
        elif pointee.get_size() == 4:
            use = "int4"
        else:
            use = "size%d" % pointee.get_size()
        parent = f.semantic_parent
        loc = f.location
        decl = os.path.relpath(loc.file.name, ROOT) if loc.file else "?"
        out.append({"src": os.path.relpath(path, ROOT), "line": c.location.line, "use": use,
                    "class": parent.type.spelling if parent is not None else "?", "field": f.spelling,
                    "ftype": f.type.spelling, "decl": decl, "decl_line": loc.line})
    return out


def cmd_scan(a):
    files = a.files or sorted(os.path.join(d, f) for d in ("matches", "equivalent") for f in os.listdir(os.path.join(ROOT, d))
                              if f.endswith(".cpp"))
    files = [os.path.join(ROOT, f) if not os.path.isabs(f) else f for f in files]
    files = [f for f in files if PUN.search(open(f, "rb").read())]
    shard = os.environ.get("HULK_SHARD")
    if shard:
        k, n = map(int, shard.split("/"))
        files = files[k::n]
    print("%d files with a pun" % len(files), file=sys.stderr)
    done = set()
    if os.path.exists(a.out):
        done = {json.loads(l)["file"] for l in open(a.out)}
    with open(a.out, "a") as f, concurrent.futures.ProcessPoolExecutor(a.jobs) as ex:
        todo = [p for p in files if os.path.relpath(p, ROOT) not in done]
        for p, rows in zip(todo, ex.map(scan_file, todo, chunksize=4)):
            f.write(json.dumps({"file": os.path.relpath(p, ROOT), "rows": rows}) + "\n")
            f.flush()
    return 0


def cmd_summary(a):
    by = collections.defaultdict(lambda: {"uses": collections.Counter(), "srcs": set(), "ftype": None})
    for path in a.inp:
        for l in open(path):
            for r in json.loads(l)["rows"]:
                k = (r["decl"], r["class"], r["field"])
                by[k]["uses"][r["use"]] += 1
                by[k]["srcs"].add(r["src"])
                by[k]["ftype"] = r["ftype"]
    kinds = collections.Counter()
    rows = []
    for (decl, cls, fld), v in sorted(by.items()):
        where = "include/gen" if decl.startswith("include/gen/") else ("include" if decl.startswith("include/") else "source")
        mixed = set(v["uses"]) - {"pointer", "int4"}
        state = "pointer-only" if set(v["uses"]) == {"pointer"} else ("pointer+int" if not mixed and "pointer" in v["uses"] else
                                                                      ("no pointer pun" if "pointer" not in v["uses"] else "mixed"))
        kinds[(where, state)] += 1
        rows.append({"decl": decl, "class": cls, "field": fld, "ftype": v["ftype"], "uses": dict(v["uses"]),
                     "sources": len(v["srcs"]), "state": state})
    for k, n in sorted(kinds.items()):
        print("%-12s %-16s %5d fields" % (k[0], k[1], n))
    pun = sum(r["uses"].get("pointer", 0) for r in rows)
    print("pointer puns of 4-byte integer fields: %d sites, %d fields" % (pun, sum(1 for r in rows if "pointer" in r["uses"])))
    if a.out:
        with open(a.out, "w") as f:
            json.dump(rows, f, indent=0)
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("scan")
    s.add_argument("files", nargs="*")
    s.add_argument("--out", required=True)
    s.add_argument("--jobs", type=int, default=2)
    m = sub.add_parser("summary")
    m.add_argument("inp", nargs="+")
    m.add_argument("--out")
    a = ap.parse_args(argv)
    return cmd_scan(a) if a.cmd == "scan" else cmd_summary(a)


if __name__ == "__main__":
    sys.exit(main())
