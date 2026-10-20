#!/usr/bin/env python3
"""32-bit vs 64-bit record layouts (docs/native-build.md "64-bit"): which classes and structs change their field
offsets when pointers are 8 bytes, and a gate for the ones whose layout is a file format.

  build/venv/bin/python tools/layout64.py                  # include/gen/ classes + config/layout64.json records
  build/venv/bin/python tools/layout64.py --class CAction  # one record, field by field
  build/venv/bin/python tools/layout64.py --check          # compile the file-format asserts on every target

Layouts come from clang (-fdump-record-layouts) on one probe TU per chunk of classes, for each target:
i686-pc-windows-msvc (the reference: the original's layout as the MS ABI gives it), x86_64-pc-windows-msvc and
arm64-apple-darwin. A record *moves* when a field's offset (or the size) differs from i686; why: the vftable
pointer (8 bytes), pointer fields, `long` (arm64: 8 bytes), or alignment after those. `_pad_` gaps of include/gen/
are 32-bit offsets written as bytes: on 64-bit they keep their byte count while the fields around them grow, so a
class with a pad and a pointer before it is wrong on 64-bit even where clang reports no error.

config/layout64.json lists the records whose layout is a file format or otherwise must not move (read whole from
disk, written to a save, shared with a tool): each entry {"name", "include" (header under include/) or "source"
(the matches/ or equivalent/ source that defines it), "size" (the 32-bit size), "offsets" (field: offset), "why"}. `--check` compiles `static_assert(sizeof(X) == size)` and the offset of every field of each
listed record on every target; the asserts are the gate a 64-bit build has to pass (they fail today for records
with pointers, which is the point: such a record needs a disk-side struct of fixed-width fields).

Output: build/native64/layout.json (per record: size per target, fields that move, cause), summary on stdout.
"""
import argparse
import collections
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import rn_layout  # noqa: E402

ROOT = rn_layout.ROOT
OUT = os.environ.get("HULK_NATIVE64_DIR") or os.path.join(ROOT, "build/native64")
CONFIG = os.path.join(ROOT, "config/layout64.json")
CLANG = os.path.join("/opt/homebrew/opt/llvm/bin", "clang")
TARGETS = {
    "i686": ["-target", "i686-pc-windows-msvc", "-fms-compatibility"],
    "x64": ["-target", "x86_64-pc-windows-msvc", "-fms-compatibility"],
    "arm64": ["-target", "arm64-apple-darwin"],
}
COMMON = ["-fms-extensions", "-w", "-std=c++14", "-Xclang", "-fno-wchar", "-fno-operator-names"]


def probe(target, names, includes):
    """{qualified name: record} for one target."""
    d = os.path.join(OUT, "layout-probe")
    os.makedirs(d, exist_ok=True)
    recs = {}
    chunk = 250
    for k in range(0, len(names), chunk):
        part = names[k:k + chunk]
        src = os.path.join(d, "%s_%03d.cpp" % (target, k // chunk))
        with open(src, "w") as f:
            for h in includes:
                f.write('#include "%s"\n' % h)
            for i, q in enumerate(part):
                f.write("int s_%d = sizeof(::%s);\n" % (i, q))
        r = subprocess.run([CLANG] + TARGETS[target] + COMMON + ["-I", os.path.join(ROOT, "include"), "-c",
                                                                 "-o", os.devnull, "-Xclang", "-fdump-record-layouts",
                                                                 src], capture_output=True, text=True, errors="replace")
        if r.returncode != 0:
            print("probe %s failed: %s" % (src, r.stderr[:400]), file=sys.stderr)
        recs.update(rn_layout.parse_record_layouts(r.stdout))
    return recs


def flat(rec):
    """{field path: (offset, type)} with nesting depth folded into the name (bases and members of members)."""
    out = {}
    stack = []
    for off, t, n, depth in rec["fields"]:
        stack = stack[:depth]
        stack.append(n)
        out[".".join(stack)] = (off, t)
    return out


def cause(t):
    t = t.replace(" ", "")
    if t.endswith("*") or "(*)" in t or t.endswith("&"):
        return "pointer"
    if re.fullmatch(r"(unsigned)?long", t):
        return "long"
    return "follows"


def compare(recs):
    """Per record: size per target and the fields whose offsets differ from i686."""
    out = {}
    ref = recs["i686"]
    for q, r32 in ref.items():
        row = {"size": {"i686": r32["size"]}, "vptr": bool(r32["vptr_at"]), "moves": {}}
        f32 = flat(r32)
        pads = sum(1 for n in f32 if n.split(".")[-1].startswith("_pad_"))
        ptrs = sum(1 for _, t in f32.values() if cause(t) == "pointer")
        row["pads"], row["pointer_fields"] = pads, ptrs
        for tgt in ("x64", "arm64"):
            r = recs[tgt].get(q)
            if r is None:
                continue
            row["size"][tgt] = r["size"]
            f = flat(r)
            moved = [(n, f32[n][0], f[n][0], f32[n][1]) for n in f32 if n in f and f[n][0] != f32[n][0]]
            if moved or r["size"] != r32["size"]:
                # beyond a uniform shift (the 8-byte vftable pointer moves every field by 4): fields whose
                # distance from the first field changes (pointer fields, alignment, `long`)
                both = [n for n in f32 if n in f]
                d0 = (f[both[0]][0] - f32[both[0]][0]) if both else 0
                inner = [n for n in both if f[n][0] - f32[n][0] != d0]
                row["moves"][tgt] = {"fields": len(moved), "relative": len(inner), "first": moved[:3]}
        out[q] = row
    return out


def summarize(cmp, gen_names):
    s = collections.Counter()
    why = collections.Counter()
    for q in gen_names:
        r = cmp.get(q)
        if r is None:
            s["not laid out"] += 1
            continue
        s["records"] += 1
        if r["moves"].get("x64"):
            s["move on x64"] += 1
            if r["moves"]["x64"]["relative"]:
                s["fields move relative to each other on x64"] += 1
            if r["pads"]:
                s["move on x64 and have _pad_ gaps (byte gaps at 32-bit offsets)"] += 1
        else:
            s["same on x64"] += 1
        if r["moves"].get("arm64"):
            s["move on arm64"] += 1
        if r["vptr"]:
            why["vftable pointer"] += 1
        if r["pointer_fields"]:
            why["pointer fields"] += 1
    return dict(s), dict(why)


def load_config():
    if not os.path.exists(CONFIG):
        return []
    return json.load(open(CONFIG))["records"]


def check(cfg):
    """Compile the file-format asserts for every target: {target: {record: ok/failed}}."""
    d = os.path.join(OUT, "layout-probe")
    os.makedirs(d, exist_ok=True)
    res = {}
    for tgt in TARGETS:
        res[tgt] = {}
        for e in cfg:
            src = os.path.join(d, "assert_%s_%s.cpp" % (tgt, re.sub(r"\W", "_", e["name"])))
            with open(src, "w") as f:
                f.write('#include "%s"\n' % (e["include"] if e.get("include") else os.path.join(ROOT, e["source"])))
                f.write("static_assert(sizeof(::%s) == %d, \"%s: 32-bit file layout\");\n" % (
                    e["name"], e["size"], e["name"]))
                for fld, off in e.get("offsets", {}).items():
                    f.write("static_assert(__builtin_offsetof(::%s, %s) == %d, \"%s.%s\");\n" % (
                        e["name"], fld, off, e["name"], fld))
            r = subprocess.run([CLANG] + TARGETS[tgt] + COMMON + ["-I", os.path.join(ROOT, "include"),
                                                                "-fsyntax-only", src],
                               capture_output=True, text=True, errors="replace")
            res[tgt][e["name"]] = "ok" if r.returncode == 0 else "failed: " + \
                "; ".join(re.findall(r"static assertion failed[^\n]*", r.stderr))[:200]
    return res


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--class", dest="cls")
    ap.add_argument("--check", action="store_true")
    a = ap.parse_args(argv)
    cfg = load_config()
    if a.check:
        r = check(cfg)
        print(json.dumps(r, indent=1))
        return 0 if all(v == "ok" for t in r.values() for v in t.values()) else 1
    gen_names = [q for q, _ in rn_layout.gen_class_names()]
    # (records a source defines, `"source": "matches/0x....cpp"`, are checked by --check only)
    hdr = [e for e in cfg if e.get("include")]
    names = gen_names + [e["name"] for e in hdr if e["name"] not in gen_names]
    includes = ["gen/all.h"] + sorted({e["include"] for e in hdr if e["include"] != "gen/all.h"})
    if a.cls:
        names = [a.cls]
    recs = {t: probe(t, names, includes) for t in TARGETS}
    cmp = compare(recs)
    if a.cls:
        r32, r64 = recs["i686"].get(a.cls), recs["x64"].get(a.cls)
        if not r32:
            sys.exit("%s: not laid out" % a.cls)
        f64 = flat(r64) if r64 else {}
        fa = flat(recs["arm64"].get(a.cls) or {"fields": []})
        print("%s: size i686 %s x64 %s arm64 %s" % (a.cls, r32["size"], r64 and r64["size"],
                                                    (recs["arm64"].get(a.cls) or {}).get("size")))
        for n, (o, t) in flat(r32).items():
            print("  %5d %5s %5s  %-40s %s" % (o, f64.get(n, ("?",))[0], fa.get(n, ("?",))[0], n, t))
        return 0
    s, why = summarize(cmp, gen_names)
    disk = {e["name"]: cmp.get(e["name"]) for e in cfg}
    rep = {"include_gen": s, "include_gen_causes": why, "file_formats": disk, "records": cmp}
    os.makedirs(OUT, exist_ok=True)
    json.dump(rep, open(os.path.join(OUT, "layout.json"), "w"), indent=1)
    print("include/gen: %s\ncauses: %s" % (json.dumps(s), json.dumps(why)))
    for n, r in disk.items():
        print("file format %s: %s" % (n, json.dumps(r and {"size": r["size"], "moves": {k: v["fields"] for k, v in r["moves"].items()}})))
    return 0


if __name__ == "__main__":
    sys.exit(main())
