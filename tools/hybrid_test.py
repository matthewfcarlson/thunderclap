#!/usr/bin/env python3
"""Hybrid-build test harness (docs/tasks/10-hybrid-test-plan.md, docs/hybrid-build.md).

  tools/hybrid_test.py determinism [--replay R] [--seconds 60] [--runs 2]
        two runs of the *unmodified* game with only the test hooks patched in (fixed dt, constant seed,
        input replay, checkpoints); their checkpoints must be identical.
  tools/hybrid_test.py compare --matches all [--equivalent] [--set FILE] [--replay R] [--seconds 60]
        the same replay on the hooks-only build and on a hybrid build; reports the first checkpoint that
        differs, whether the patched build reached the title, and which patched functions ran.

Every run uses the tweaks skip-intro and no-fmv (movies stall the frame counter that replays are keyed on)
and writes build/hybrid/test/<name>.json.
"""
import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hybrid_run  # noqa: E402
import patch_xbe  # noqa: E402

ROOT = patch_xbe.ROOT
TEST_DIR = os.path.join(patch_xbe.OUT_DIR, "test")
DEFAULT_REPLAY = os.path.join(ROOT, "tests/replays/newgame-normal.json")
TWEAKS = ("skip-intro", "no-fmv")
SEED = 0x1234


MASK_FILE = os.path.join(ROOT, "tests/replays/wide-mask.json")     # .data pages excluded from the hash


def hooks_cfg(replay, wide=False, snap_frame=0):
    h = {"seed": SEED, "flags": ["fixed-dt", "ckpt", "autostart"], "dt_us": 33333, "ckpt_interval": 30}
    if replay:
        h["replay"] = json.load(open(replay))
    if wide:
        h["flags"].append("wide")
        h["snap_frame"] = snap_frame
        if os.path.exists(MASK_FILE):
            pages = json.load(open(MASK_FILE))["pages"]
            mask = [0] * (patch_xbe.WIDE_PAGES // 32)
            for p in pages:
                mask[p >> 5] |= 1 << (p & 31)
            h["mask"] = mask
    return h


def build_and_run(name, records, replay, seconds, interval=10, coverage=False, wide=False, snap_frame=0):
    """Build XBE `name` from records (may be empty), install, boot, return the boot report."""
    os.makedirs(TEST_DIR, exist_ok=True)
    out = os.path.join(TEST_DIR, name + ".xbe")
    man = patch_xbe.build(records, out, tweaks=TWEAKS, hooks=hooks_cfg(replay, wide, snap_frame))
    hybrid_run.install(out)
    cov = [f["ours"] for f in man["functions"]] if coverage and man["functions"] else None
    rep = hybrid_run.boot(seconds, interval, tag="test-" + name, coverage=cov, manifest=man)
    rep["patched"] = man["patched"]
    json.dump(rep, open(os.path.join(TEST_DIR, name + "-report.json"), "w"), indent=1)   # name.json is the manifest
    return rep


def checkpoints(rep):
    return [tuple(c) for c in (rep.get("hybrid") or {}).get("checkpoints", [])]


# Checkpoints after this frame are not compared: on newgame-normal.json the game is deterministic through
# the front end (frames 0-450); after the new-game load the loop's frame count depends on load time.
MAX_FRAME = 450


def first_divergence(a, b, max_frame=MAX_FRAME):
    """{frame, a, b} of the first differing checkpoint over the common frames (<= max_frame), else None."""
    ma, mb = dict(a), dict(b)
    for f in sorted(set(ma) & set(mb)):
        if max_frame and f > max_frame:
            break
        if ma[f] != mb[f]:
            return {"frame": f, "a": "%08x" % ma[f], "b": "%08x" % mb[f]}
    return None


def common_frames(a, b, max_frame=MAX_FRAME):
    return len([f for f in set(dict(a)) & set(dict(b)) if not max_frame or f <= max_frame])


def determinism(args):
    reps = [build_and_run("determinism-%d" % i, [], args.replay, args.seconds, wide=args.wide,
                          snap_frame=args.snap_frame) for i in range(args.runs)]
    cks = [checkpoints(r) for r in reps]
    res = {"runs": args.runs, "checkpoints": [len(c) for c in cks], "frames": [(r.get("hybrid") or {}).get("frame") for r in reps],
           "monitor_errors": sum(bool(r.get("monitor_error")) for r in reps),
           "divergence": None}
    for c in cks[1:]:
        d = first_divergence(cks[0], c, args.max_frame)
        if d:
            res["divergence"] = d
            break
    res["common"] = min(common_frames(cks[0], c, args.max_frame) for c in cks[1:]) if len(cks) > 1 else len(cks[0])
    res["deterministic"] = res["divergence"] is None and res["common"] > 0
    if args.wide:
        snaps = [((r.get("hybrid") or {}).get("wide") or {}) for r in reps]
        if all(sn.get("snap_taken") for sn in snaps):
            lo = snaps[0]["lo"]
            diff = sorted({i for sn in snaps[1:] for i, (p, q) in enumerate(zip(snaps[0]["snap"], sn["snap"])) if p != q})
            res["snap_frames"] = [sn["snap_taken"] for sn in snaps]
            res["varying_pages"] = [{"page": i, "va": "%#x" % (lo + 0x1000 * i)} for i in diff]
    return res


def select_records(args):
    jobs = patch_xbe.select(args)
    if args.set:
        keep = patch_xbe.read_addr_file(args.set)
        jobs = [j for j in jobs if j[0] in keep]
    drop = patch_xbe.read_addr_file(args.exclude) if args.exclude else set()
    if not args.no_default_exclude:
        drop |= patch_xbe.default_exclude()
    jobs = [j for j in jobs if j[0] not in drop]
    cache = patch_xbe.load_cache()
    recs = patch_xbe.check_extent(patch_xbe.prepare_all(jobs, args.jobs, cache))
    patch_xbe.save_cache(cache)
    classes = set(args.classes.split(","))
    for r in recs:
        if r.get("status") == "ok" and r["class"] not in classes:
            r["status"] = "skip"
    return recs


def compare(args, recs=None, name="patched", baseline=None):
    """Hooks-only baseline vs the hybrid build with `recs`. Returns a verdict dict."""
    if recs is None:
        recs = select_records(args)
    if baseline is None:
        baseline = build_and_run("baseline", [], args.replay, args.seconds)
    pat = build_and_run(name, recs, args.replay, args.seconds, coverage=args.coverage)
    a, b = checkpoints(baseline), checkpoints(pat)
    mf = getattr(args, "max_frame", MAX_FRAME)
    d = first_divergence(a, b, mf)
    v = {"patched": pat["patched"], "title": pat["title"], "exited": pat["exited"], "frozen": pat["frozen"],
         "frames": (pat.get("hybrid") or {}).get("frame"), "baseline_frames": (baseline.get("hybrid") or {}).get("frame"),
         "common_checkpoints": common_frames(a, b, mf), "divergence": d}
    if "coverage" in pat:
        v["functions_run"] = pat["coverage"]["hit"]
    # it must also keep running: reach the end of the compared window if the baseline did
    need = min(mf or 1 << 30, v["baseline_frames"] or 0)
    v["ran_far_enough"] = (v["frames"] or 0) >= need
    v["pass"] = bool(pat["title"] and not pat["exited"] and d is None and v["common_checkpoints"] > 0
                     and v["ran_far_enough"])
    return v


def add_selection_args(ap):
    ap.add_argument("--matches")
    ap.add_argument("--equivalent", action="store_true")
    ap.add_argument("--only")
    ap.add_argument("--set")
    ap.add_argument("--exclude")
    ap.add_argument("--no-default-exclude", action="store_true")
    ap.add_argument("--classes", default="identical")
    ap.add_argument("--jobs", type=int, default=8)


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    d = sub.add_parser("determinism")
    d.add_argument("--runs", type=int, default=2)
    d.add_argument("--max-frame", type=int, default=0, help="compare checkpoints up to this frame (0: all)")
    d.add_argument("--wide", action="store_true", help="also hash all of .data/.bss (minus wide-mask.json)")
    d.add_argument("--snap-frame", type=int, default=0, help="with --wide: keep page hashes at this frame")
    c = sub.add_parser("compare")
    add_selection_args(c)
    c.add_argument("--coverage", action="store_true")
    c.add_argument("--max-frame", type=int, default=MAX_FRAME)
    for p in (d, c):
        p.add_argument("--replay", default=DEFAULT_REPLAY if os.path.exists(DEFAULT_REPLAY) else None)
        p.add_argument("--seconds", type=float, default=60)
    a = ap.parse_args(argv)
    res = determinism(a) if a.cmd == "determinism" else compare(a)
    print(json.dumps(res, indent=1))
    json.dump(res, open(os.path.join(TEST_DIR, a.cmd + "-result.json"), "w"), indent=1)
    return 0 if res.get("deterministic", res.get("pass")) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
