#!/usr/bin/env python3
"""The reference manifest (ckpt1, D162/D163 R1; docs/checkpoints.md "The rule"): config/ckpt-refs.json names every
reference recording a checkpoint validation is checked against, with the content hashes of the reference file
(build/ckpt/NAME.ckref, local derived data, never committed) and of the recording replayed (build/rp1/NAME.hrp), the
probe version, the number of original runs and the frames the reference compares. Only names and hashes are tracked.

  build/venv/bin/python tools/ckpt_refs.py check            # every manifest entry's files are here and hash as listed
  build/venv/bin/python tools/ckpt_refs.py add NAME --ref build/ckpt/NAME.ckref --recording build/rp1/NAME.hrp --runs 3
  build/venv/bin/python tools/ckpt_refs.py show

`add` refuses a reference made from fewer than three runs (two original runs agree by chance where the original is
not deterministic: docs/checkpoints.md "The particle tag") and replaces an entry of the same name. Readers use
`load()`, `verify()` (the files used must be the ones the manifest names: refused otherwise, never warned) and
`windows_in(cov_epoch_len, entry)` (the windows of a coverage bitmap that overlap the reference's compared frames;
refused when they reach past the bitmap's 256 windows: never a fall-back to the hit file's total column).
"""
import argparse
import hashlib
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MANIFEST = os.path.join(ROOT, "config", "ckpt-refs.json")
BITMAP_WINDOWS = 256          # (src/platform/sdl/xdk/startup.cpp: HULK_COVER_EPOCH's window bitmap)
MIN_RUNS = 3


class RefError(Exception):
    pass


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    return h.hexdigest()


def load(path=None):
    path = path or MANIFEST
    if not os.path.exists(path):
        return {"version": 1, "references": []}
    with open(path) as f:
        m = json.load(f)
    if m.get("version") != 1:
        raise RefError("%s: unknown manifest version %r" % (path, m.get("version")))
    return m


def _ref_facts(path):
    """(probe version, first frame, last frame) of a reference file (tools/ckpt_ref.py format)"""
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import ckpt_ref
    magic, pv, recs, _u = ckpt_ref.read(path)
    if magic != ckpt_ref.MAGIC_REF:
        raise RefError("%s is a run, not a reference (tools/ckpt_ref.py make)" % path)
    if not recs:
        raise RefError("%s holds no frames" % path)
    return pv, min(recs), max(recs)


def verify(manifest=None, root=ROOT):
    """[entry] after checking every entry: both files present and hashing as listed, the reference's probe version and
    compared frames as listed. Raises RefError naming the first entry that does not."""
    m = manifest if manifest is not None else load()
    out = []
    for e in m["references"]:
        for key, rel in (("ref_sha256", e["ref"]), ("recording_sha256", e["recording"])):
            p = os.path.join(root, rel)
            if not os.path.exists(p):
                raise RefError("reference %s: %s is missing here" % (e["name"], rel))
            if sha256(p) != e[key]:
                raise RefError("reference %s: %s does not hash as the manifest lists (%s)" % (e["name"], rel, key))
        pv, lo, hi = _ref_facts(os.path.join(root, e["ref"]))
        if pv != e["probe"] or [lo, hi] != e["compared"]:
            raise RefError("reference %s: probe v%d frames %d-%d, the manifest lists v%s %s" % (
                e["name"], pv, lo, hi, e["probe"], e["compared"]))
        if e.get("runs", 0) < MIN_RUNS:
            raise RefError("reference %s: made from %s runs (at least %d)" % (e["name"], e.get("runs"), MIN_RUNS))
        out.append(e)
    return out


def windows_in(bits_hex, epoch_len, entry):
    """the windows of one hit's bitmap (cover.py / startup.cpp: 256 windows of epoch_len frames) that overlap the
    reference's compared frames. Refused when those frames reach past the bitmap."""
    lo, hi = entry["compared"]
    if epoch_len <= 0:
        raise RefError("no window length: a coverage run without HULK_COVER_EPOCH counts nothing")
    if hi >= BITMAP_WINDOWS * epoch_len:
        raise RefError("reference %s compares frames to %d, past the bitmap's %d windows of %d frames: rerun the "
                       "coverage with a longer HULK_COVER_EPOCH" % (entry["name"], hi, BITMAP_WINDOWS, epoch_len))
    bits = bytes.fromhex(bits_hex)
    return sum(1 for k in range(min(len(bits) * 8, BITMAP_WINDOWS)) if bits[k // 8] >> (k % 8) & 1
               and k * epoch_len <= hi and k * epoch_len + epoch_len - 1 >= lo)


def cmd_add(a):
    m = load(a.manifest)
    pv, lo, hi = _ref_facts(a.ref)
    if a.runs < MIN_RUNS:
        sys.exit("a reference needs at least %d original runs (two agree by chance where the original is not "
                 "deterministic)" % MIN_RUNS)
    rel = lambda p: os.path.relpath(os.path.abspath(p), ROOT)
    e = {"name": a.name, "ref": rel(a.ref), "ref_sha256": sha256(a.ref), "recording": rel(a.recording),
         "recording_sha256": sha256(a.recording), "probe": pv, "runs": a.runs, "compared": [lo, hi]}
    m["references"] = [x for x in m["references"] if x["name"] != a.name] + [e]
    m["references"].sort(key=lambda x: x["name"])
    with open(a.manifest or MANIFEST, "w") as f:
        json.dump(m, f, indent=1)
        f.write("\n")
    print(json.dumps(e))


def cmd_check(a):
    try:
        es = verify(load(a.manifest))
    except RefError as e:
        print("ckpt-refs: FAILED: %s" % e)
        return 1
    print("ckpt-refs: ok, %d reference(s): %s" % (len(es), ", ".join("%s (v%d, frames %d-%d)" % (
        e["name"], e["probe"], e["compared"][0], e["compared"][1]) for e in es)))
    return 0


def cmd_show(a):
    print(json.dumps(load(a.manifest), indent=1))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--manifest")
    sp = ap.add_subparsers(dest="cmd", required=True)
    s = sp.add_parser("add")
    s.add_argument("name")
    s.add_argument("--ref", required=True)
    s.add_argument("--recording", required=True)
    s.add_argument("--runs", type=int, required=True)
    sp.add_parser("check")
    sp.add_parser("show")
    a = ap.parse_args()
    return {"add": cmd_add, "check": cmd_check, "show": cmd_show}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
