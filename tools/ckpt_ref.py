#!/usr/bin/env python3
"""Reference checkpoints from the original game, and the check of a build against them (ckpt1, D155/D158;
docs/checkpoints.md).

  # a run's frame records (the Wine build's HULK_CKREF=1 trace.txt.ckref, or an xemu run's, same format): summary
  build/venv/bin/python tools/ckpt_ref.py show RUN.ckref
  # a reference from runs of the original (at least two; three recommended): a (frame, tag) is kept only where all agree
  build/venv/bin/python tools/ckpt_ref.py make A.ckref B.ckref [C.ckref ...] --name play3 --out build/ckpt/play3.ckref
  # a build against a reference: per tag the first diverging frame, float drift or logic, the verdict; with --cover a
  # coverage report (tools/cover.py report --json), the functions first entered in the window before the divergence
  build/venv/bin/python tools/ckpt_ref.py check RUN.ckref --ref build/ckpt/play3.ckref [--cover cover.json] [--json OUT]
  # the field dumps of one frame (HULK_CKREF_DUMP "ckdump" lines in two traces): the fields that differ
  build/venv/bin/python tools/ckpt_ref.py diff TRACE_A TRACE_B [--frame F]

Format (little-endian 32-bit words): "HCKR" (a run) or "HCKF" (a reference), format version 1, probe version; then
per frame: frame, tag mask, unavailable mask, and per tag set in the mask (ascending) its exact and quantised hash. A
reference also has a JSON sidecar (OUT.json: recording, sources, frames, dropped). References are derived game data:
they stay under build/ and are never committed.
"""
import argparse
import collections
import json
import os
import re
import struct
import sys

TAGS = ["legacy", "flow", "clock", "rng", "hulk", "camera", "actors", "mission", "sound", "particle"]
# observables, not game state: reported, but outside the verdict unless --strict (the Wine and native audio backends
# are not the original's, so which sounds get voices, and the sound code's own generators, may differ)
OBSERVABLE = {"sound"}
MAGIC_RUN, MAGIC_REF = 0x524b4348, 0x464b4348      # "HCKR", "HCKF"


def read(path):
    """-> (magic, probe version, {frame: {tag: (exact, quant)}}, {frame: unavailable mask})"""
    data = open(path, "rb").read()
    n = len(data) // 4
    w = struct.unpack("<%dI" % n, data[:n * 4])
    if n < 3 or w[0] not in (MAGIC_RUN, MAGIC_REF) or w[1] != 1:
        sys.exit("%s: not a checkpoint record file" % path)
    magic, pv = w[0], w[2]
    recs, unav = {}, {}
    i = 3
    while i + 3 <= n:
        fr, mask, un = w[i], w[i + 1], w[i + 2]
        k = bin(mask).count("1")
        if i + 3 + 2 * k > n:
            break       # (a run killed mid-write)
        tags, j = {}, i + 3
        for t in range(32):
            if mask & (1 << t):
                tags[t] = (w[j], w[j + 1])
                j += 2
        recs[fr] = tags          # (a frame written twice: the rollback snapshots replay frames; the last wins)
        unav[fr] = un
        i = j
    return magic, pv, recs, unav


def write(path, pv, recs, magic=MAGIC_REF):
    with open(path, "wb") as f:
        f.write(struct.pack("<3I", magic, 1, pv))
        for fr in sorted(recs):
            tags = recs[fr]
            mask = sum(1 << t for t in tags)
            f.write(struct.pack("<3I", fr, mask, 0))
            for t in sorted(tags):
                f.write(struct.pack("<2I", *tags[t]))


def name(t):
    return TAGS[t] if t < len(TAGS) else "tag%d" % t


def cmd_show(a):
    magic, pv, recs, unav = read(a.file)
    per = collections.Counter(t for r in recs.values() for t in r)
    na = collections.Counter(t for u in unav.values() for t in range(32) if u & (1 << t))
    print("%s: %s, probe v%d, %d frames (%s..%s)" % (a.file, "run" if magic == MAGIC_RUN else "reference", pv, len(recs),
                                                    min(recs) if recs else "-", max(recs) if recs else "-"))
    for t in sorted(per):
        print("  %-8s %6d frames%s" % (name(t), per[t], ", %d unavailable" % na[t] if na[t] else ""))


def cmd_make(a):
    runs = [read(p) for p in a.runs]
    if len(runs) < 2:
        sys.exit("a reference needs at least two runs of the original")
    pv = {r[1] for r in runs}
    if len(pv) > 1:
        sys.exit("probe versions differ: %s" % sorted(pv))
    pa = runs[0][1]
    recs = [r[2] for r in runs]
    unavs = [r[3] for r in runs]
    frames = set.intersection(*[set(r) for r in recs])
    out, dropped = {}, collections.Counter()
    for fr in sorted(frames):
        keep = {}
        un = 0
        for u in unavs:
            un |= u[fr]
        for t in set.intersection(*[set(r[fr]) for r in recs]):
            if un & (1 << t):
                continue
            if len({r[fr][t][0] for r in recs}) == 1:
                keep[t] = recs[0][fr][t]
            else:
                dropped[name(t)] += 1
        if keep:
            out[fr] = keep
    write(a.out, pa, out)
    meta = {"recording": a.name, "probe": pa, "sources": [os.path.abspath(p) for p in a.runs],
            "frames": len(out), "last": max(out) if out else None, "dropped_disagreeing": dict(dropped),
            "not_in_all": len(set.union(*[set(r) for r in recs]) - frames)}
    json.dump(meta, open(a.out + ".json", "w"), indent=1)
    print(json.dumps(meta))


def first_divergence(run, ref, run_unav):
    """{tag: {first, drift (quantised equal at the first), compared, diverged}}"""
    out = {}
    for fr in sorted(ref):
        if fr not in run:
            continue
        for t, (e, q) in ref[fr].items():
            if run_unav.get(fr, 0) & (1 << t) or t not in run[fr]:
                continue
            d = out.setdefault(t, {"first": None, "drift": None, "compared": 0, "diverged": 0, "last_ok": None})
            d["compared"] += 1
            re_, rq = run[fr][t]
            if re_ == e:
                if d["first"] is None:
                    d["last_ok"] = fr
                continue
            d["diverged"] += 1
            if d["first"] is None:
                d["first"] = fr
                d["drift"] = rq == q
    return out


def gate(run, run_unav, ctl, ref, strict=False):
    """The proof gate against the original: [(frame, tag)] a control matched and the run does not, and how many
    reference frames the control has that the run lacks (within the run's range)."""
    new = []
    last = max(run) if run else -1
    for fr in sorted(ref):
        if fr not in run or fr not in ctl:
            continue
        for t, (e, _q) in ref[fr].items():
            if not strict and name(t) in OBSERVABLE:
                continue
            if run_unav.get(fr, 0) & (1 << t):
                continue
            if t in ctl[fr] and t in run[fr] and ctl[fr][t][0] == e and run[fr][t][0] != e:
                new.append((fr, name(t)))
    lacks = sum(1 for fr in ref if fr in ctl and fr not in run and fr <= last)
    return new, lacks


def cmd_check(a):
    _, pr, run, unav = read(a.run)
    _, pf, ref, _ = read(a.ref)
    if pr != pf:
        sys.exit("probe versions differ: run v%d, reference v%d (record new references)" % (pr, pf))
    res = first_divergence(run, ref, unav)
    common = len(set(run) & set(ref))
    firsts = sorted((d["first"], t) for t, d in res.items()
                    if d["first"] is not None and (a.strict or name(t) not in OBSERVABLE))
    ok = not firsts and common > 0
    print("%s against %s: %d common frames (reference %d, run %d..%d)" % (a.run, a.ref, common, len(ref),
                                                                       min(run) if run else -1, max(run) if run else -1))
    for t in sorted(res):
        d = res[t]
        print("  %-8s compared %6d diverged %6d first %s%s" % (
            name(t) + ("*" if name(t) in OBSERVABLE else ""), d["compared"], d["diverged"], d["first"],
            "" if d["first"] is None else " (%s; last ok before it %s)" % ("float drift" if d["drift"] else "logic",
                                                                           d["last_ok"])))
    report = {"run": a.run, "ref": a.ref, "common": common, "ok": ok,
              "tags": {name(t): d for t, d in res.items()}}
    if firsts:
        fr, t = firsts[0]
        lo = res[t]["last_ok"] or 0
        print("first divergence: frame %d, tag %s (window %d..%d)" % (fr, name(t), lo, fr))
        report["first"] = {"frame": fr, "tag": name(t), "window": [lo, fr]}
        if a.cover:
            cov = json.load(open(a.cover))
            sus = [x for x in cov["reached"] if lo <= x["frame"] <= fr and not x.get("folded")]
            sus.sort(key=lambda x: (x["frame"], x["addr"]))
            print("functions first entered in the window: %d" % len(sus))
            for x in sus[:40]:
                print("  %s f=%d %s (%s)" % (x["addr"], x["frame"], x["name"], x["tu"]))
            report["suspects"] = sus
    if a.control:
        # the proof gate against the original: a (frame, tag) the control matched must still match (the control's own
        # divergences are the known ones; a change may not add any)
        _, pc, ctl, _cun = read(a.control)
        if pc != pf:
            sys.exit("probe versions differ: control v%d, reference v%d" % (pc, pf))
        new, lacks = gate(run, unav, ctl, ref, a.strict)
        print("gate against the control %s: %d (frame, tag) newly diverged%s; %d reference frames the run lacks" % (
            a.control, len(new), " first %d %s" % new[0] if new else "", lacks))
        report["gate"] = {"control": a.control, "new": new[:200], "new_count": len(new), "lacks": lacks}
        ok = not new and lacks == 0
    print("VERDICT", "ok" if ok else "DIVERGED")
    report["ok"] = ok
    if a.json:
        json.dump(report, open(a.json, "w"), indent=1)
    return 0 if ok else 1


DUMP = re.compile(r"ckdump f=(\d+) t=(\d+) (\S+)\[(\d+)\] ([0-9a-f]{8})( f)?")


def load_dump(path, frame):
    out = collections.OrderedDict()
    for l in open(path, errors="replace"):
        m = DUMP.search(l)
        if m and (frame is None or int(m.group(1)) == frame):
            k = (int(m.group(1)), name(int(m.group(2))), m.group(3), int(m.group(4)))
            out.setdefault(k, []).append((m.group(5), bool(m.group(6))))
    return out


def f32(bits):
    return struct.unpack("<f", struct.pack("<I", int(bits, 16)))[0]


def cmd_diff(a):
    da, db = load_dump(a.a, a.frame), load_dump(a.b, a.frame)
    keys = list(da) + [k for k in db if k not in da]
    nd = 0
    for k in keys:
        va, vb = da.get(k), db.get(k)
        if va == vb:
            continue
        nd += 1
        def fmt(v):
            if not v:
                return "-"
            return ",".join("%s(%g)" % (b, f32(b)) if fl else b for b, fl in v)
        print("f=%d %s.%s[%d]: %s | %s" % (k + (fmt(va), fmt(vb))))
    print("%d of %d fields differ" % (nd, len(keys)))
    return 1 if nd else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    s = sp.add_parser("show")
    s.add_argument("file")
    s = sp.add_parser("make")
    s.add_argument("runs", nargs="+")
    s.add_argument("--name", required=True)
    s.add_argument("--out", required=True)
    s = sp.add_parser("check")
    s.add_argument("run")
    s.add_argument("--ref", required=True)
    s.add_argument("--cover")
    s.add_argument("--control", help="a control run (the same build without the change): the verdict is then the gate, "
                   "no (frame, tag) the control matched may diverge")
    s.add_argument("--strict", action="store_true", help="the observables (*: sound) count toward the verdict too")
    s.add_argument("--json")
    s = sp.add_parser("diff")
    s.add_argument("a")
    s.add_argument("b")
    s.add_argument("--frame", type=int)
    a = ap.parse_args()
    return {"show": cmd_show, "make": cmd_make, "check": cmd_check, "diff": cmd_diff}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
