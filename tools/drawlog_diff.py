#!/usr/bin/env python3
"""Compare two draw logs (docs/graphics-backend.md, "Test strategy" 1).

A draw log is one record per draw: frame, draw index in the frame (and, from the hybrid build, which D3D draw call
site), primitive type and count, the shader, the stage textures (first-seen ordinals), the pddi render state blocks,
fog and a hash of the context's top matrices (hybrid/hooks.cpp HYBRID_DRAWLOG; src/platform/sdl/pddi/pddi.h
DrawRecord). Sources:

  - the hybrid build in xemu: `tools/hybrid_test.py replay REC.json --drawlog EVERY[:FIRST[:LAST]]` writes JSON lines
    (a header object, then one object per draw);
  - the native backend: `hulk::pddi::drawlogDump` writes "PDL1" binaries (the same 24 words per draw).

  build/venv/bin/python tools/drawlog_diff.py A.jsonl B.jsonl                 # first mismatches, per-frame counts
  build/venv/bin/python tools/drawlog_diff.py A.jsonl B.pdl --ignore shader_id      # hybrid vs native: the shader
                                                                                   # field compared as a kind
  build/venv/bin/python tools/drawlog_diff.py A.jsonl --summary              # one log: what it holds

Records are aligned by (frame, draw index); the exit status is 0 when every compared field of every aligned draw is
equal and both logs have the same draws.
"""
import argparse
import collections
import json
import os
import struct
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
FIELDS = ("frame", "seq", "prim", "count", "shader", "shader_id", "tex0", "tex1", "tex2", "tex3",
          "a0", "a1", "a2", "a3", "a4", "a5", "s0", "s1", "s2", "s3", "s4", "s5", "fog", "mtx")
PRIMS = {1: "points", 2: "lines", 3: "line loop", 4: "line strip", 5: "tri list", 6: "tri strip", 7: "tri fan",
         8: "quads", 9: "quad strip", 10: "polygon"}


def load(path):
    """(meta, [record dict]) from a JSONL draw log or a PDL1 binary."""
    with open(path, "rb") as f:
        head = f.read(4)
    if head == b"PDL1":
        data = open(path, "rb").read()
        _magic, n = struct.unpack_from("<4sI", data, 0)
        recs = [dict(zip(FIELDS, struct.unpack_from("<24I", data, 8 + 96 * i))) for i in range(n)]
        return {"source": "native", "format": "PDL1"}, recs
    meta, recs = {}, []
    for i, line in enumerate(open(path)):
        if not line.strip():
            continue
        o = json.loads(line)
        if i == 0 and "format" in o:
            meta = o
        else:
            recs.append(o)
    return meta, recs


def key(r):
    return r["frame"], r["seq"] & 0xFFFFFF


def class_names():
    """{vftable address: class name} from build/rtti.json (the hybrid log's shader field), if present."""
    p = os.path.join(ROOT, "build/rtti.json")
    if not os.path.exists(p):
        return {}
    out = {}
    for c in json.load(open(p))["classes"]:
        for v in c.get("vtables", []):
            out[v["address"]] = c["name"].split("::")[-1]
    return out


# the native backend's shader field is 0x8000 | its ShaderKind (src/platform/sdl/pddi/pddi.h); the hybrid build's is
# the game class's vftable: comparing the two, the hybrid's is translated through the class name
NATIVE_KINDS = {"d3dSimpleShader": 0, "d3dLayeredShader": 1, "d3dBuildingShader": 2, "d3dReflShader": 3,
                "d3dRefractVertexShader": 4, "d3dFBEffectsShader": 5, "d3dErrorShader": 6}


def to_native_kinds(recs, names):
    out = []
    for r in recs:
        r = dict(r)
        k = NATIVE_KINDS.get(names.get(r["shader"], ""))
        r["shader"] = 0x8000 | k if k is not None else r["shader"]
        out.append(r)
    return out


def fmt(field, v, names):
    if field == "shader":
        if v & 0xFFFF8000 == 0x8000:
            return "native kind %d" % (v & 0x7FFF)
        return "%s (%#x)" % (names.get(v, "?"), v)
    if field == "prim":
        return "%d %s" % (v, PRIMS.get(v, ""))
    if field == "seq":
        return "%d (site %d)" % (v & 0xFFFFFF, v >> 24)
    return "%#x" % v if field in ("mtx",) or v > 0xFFFF else str(v)


def summary(meta, recs, names):
    frames = collections.Counter(r["frame"] for r in recs)
    shaders = collections.Counter(r["shader"] for r in recs)
    sites = collections.Counter(r["seq"] >> 24 for r in recs)
    prims = collections.Counter(r["prim"] for r in recs)
    print("%s: %d draws in %d frames (%s); %s" % (meta.get("source", "?"), len(recs), len(frames),
                                                  ", ".join("%d: %d" % kv for kv in sorted(frames.items())[:12])
                                                  + (" ..." if len(frames) > 12 else ""),
                                                  {k: meta[k] for k in ("spec", "lost", "draws_seen") if k in meta}))
    print("  shaders: " + ", ".join("%s %d" % (fmt("shader", s, names), n) for s, n in shaders.most_common()))
    print("  prims:   " + ", ".join("%s %d" % (fmt("prim", p, names), n) for p, n in prims.most_common()))
    sl = meta.get("sites") or []
    print("  sites:   " + ", ".join("%d%s %d" % (s, " (%#x)" % sl[s - 1][0] if 0 < s <= len(sl) else "", n)
                                    for s, n in sorted(sites.items())))
    print("  textures: %d distinct ordinals" % len({t for r in recs for t in (r["tex0"], r["tex1"], r["tex2"],
                                                                                r["tex3"]) if t}))


def diff(a, b, fields, names, limit):
    ia = {key(r): r for r in a}
    ib = {key(r): r for r in b}
    fa = collections.Counter(r["frame"] for r in a)
    fb = collections.Counter(r["frame"] for r in b)
    frames = sorted(set(fa) | set(fb))
    count_diff = [(f, fa.get(f, 0), fb.get(f, 0)) for f in frames if fa.get(f, 0) != fb.get(f, 0)]
    common = sorted(set(ia) & set(ib))
    mism = []
    per_field = collections.Counter()
    for k in common:
        d = [f for f in fields if ia[k].get(f) != ib[k].get(f)]
        if d:
            mism.append((k, d))
            per_field.update(d)
    print("frames: %d in A, %d in B, %d in both; draws: %d in A, %d in B, %d aligned" % (
        len(fa), len(fb), len(set(fa) & set(fb)), len(a), len(b), len(common)))
    if count_diff:
        print("draw counts differ in %d frames, first: %s" % (len(count_diff), ", ".join(
            "frame %d: %d vs %d" % c for c in count_diff[:5])))
    print("aligned draws that differ: %d%s" % (len(mism), (" (fields: %s)" % ", ".join(
        "%s %d" % kv for kv in per_field.most_common())) if mism else ""))
    for (fr, i), d in mism[:limit]:
        print("  frame %d draw %d:" % (fr, i))
        for f in d:
            print("    %-9s %-28s %s" % (f, fmt(f, ia[(fr, i)][f], names), fmt(f, ib[(fr, i)][f], names)))
    return not mism and not count_diff and len(a) == len(b)


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("a")
    ap.add_argument("b", nargs="?")
    ap.add_argument("--fields", help="comma list of fields to compare (default: all but frame/seq)")
    ap.add_argument("--ignore", default="", help="comma list of fields not to compare")
    ap.add_argument("--limit", type=int, default=10, help="mismatching draws to print")
    ap.add_argument("--summary", action="store_true", help="describe each log")
    args = ap.parse_args(argv)
    names = class_names()
    ma, a = load(args.a)
    if args.summary or not args.b:
        summary(ma, a, names)
    if not args.b:
        return 0
    mb, b = load(args.b)
    if args.summary:
        summary(mb, b, names)
    if (ma.get("source") == "native") != (mb.get("source") == "native"):
        # hybrid vs native: the shader as a kind on both sides
        a, b = (a, to_native_kinds(b, names)) if ma.get("source") == "native" else (to_native_kinds(a, names), b)
    fields = args.fields.split(",") if args.fields else [f for f in FIELDS if f not in ("frame", "seq")]
    ign = set(filter(None, args.ignore.split(",")))
    fields = [f for f in fields if f not in ign]
    same = diff(a, b, fields, names, args.limit)
    print("IDENTICAL" if same else "DIFFERENT")
    return 0 if same else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
