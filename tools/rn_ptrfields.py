#!/usr/bin/env python3
"""include/gen/ fields that hold pointers in a 4-byte integer (docs/native-mac.md: `*(T**)&this->f_20`).

  build/venv/bin/python tools/ptr_fields.py scan --out F.jsonl && build/venv/bin/python tools/ptr_fields.py summary F.jsonl
                                                       # (x64-3's scan; its summary is build/x64-3/ptr-fields.json)
  build/venv/bin/python tools/rn_ptrfields.py PTR-FIELDS.json [--apply]
                                                       # -> include/gen/evidence-rn.json "ptr_fields"; then
                                                       #    regenerate: build/venv/bin/python tools/gen_headers.py

Every include/gen/ field of the summary (declared in a header, an `int` or `unsigned int` there, its other uses
integers of the same size) is retyped by gen_headers.py to hulk_intptr / hulk_uintptr (include/compat/ptr.h): the
same type on the 32-bit builds (MSVC 7.1 and clang i686: byte matches and Wine images unchanged), pointer-sized on
the 64-bit ones. Fields declared in a source's own stub are the source's business, not the generator's.
"""
import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_headers as gh  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EVIDENCE = os.path.join(ROOT, "include/gen/evidence-rn.json")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("summary", help="tools/ptr_fields.py summary output (JSON list)")
    ap.add_argument("--apply", action="store_true")
    a = ap.parse_args(argv)
    ev = json.load(open(gh.EVIDENCE_PATH)) if os.path.exists(gh.EVIDENCE_PATH) else {}
    g = gh.Gen(ev)
    import tempfile
    with tempfile.TemporaryDirectory() as d:
        g.generate(d, None)
    out, skipped = {}, []
    for x in json.load(open(a.summary)):
        if not x["decl"].startswith("include/gen/"):
            skipped.append("%s %s: declared in %s" % (x["class"], x["field"], x["decl"]))
            continue
        bad = {k: v for k, v in x["uses"].items() if k not in ("pointer", "int4")}
        if bad:
            skipped.append("%s %s: other uses %s" % (x["class"], x["field"], bad))
            continue
        c = g.by_name.get(x["class"]) or g.by_csv.get(gh.csv_name(x["class"]))
        u = c.unit if c else g.unit_by_uid.get(x["class"].split("<")[0])
        off = int(x["field"][2:], 16)
        if u is None or u.fields.get(off) not in ("int", "unsigned int", "hulk_intptr", "hulk_uintptr"):
            skipped.append("%s %s: header field is %s" % (x["class"], x["field"], u.fields.get(off) if u else None))
            continue
        out.setdefault(u.uid, {})["0x%x" % off] = "pointer pun (%s)" % ", ".join(
            "%s %d" % kv for kv in sorted(x["uses"].items()))
    for s in skipped:
        print("  skip", s)
    print("%d fields in %d classes" % (sum(len(v) for v in out.values()), len(out)))
    if a.apply:
        ev = json.load(open(EVIDENCE))
        pf = {"_comment": "4-byte integer fields read as pointers (tools/rn_ptrfields.py from tools/ptr_fields.py's "
                          "scan): gen_headers.py types them hulk_intptr / hulk_uintptr"}
        for uid in sorted(out):
            pf[uid] = dict(sorted(out[uid].items(), key=lambda kv: int(kv[0], 16)))
        ev["ptr_fields"] = pf
        json.dump(ev, open(EVIDENCE, "w"), indent=1)
        print("wrote %s; now regenerate: build/venv/bin/python tools/gen_headers.py" % os.path.relpath(EVIDENCE, ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
