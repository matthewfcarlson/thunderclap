#!/usr/bin/env python3
"""The Wine proof gate on replay checkpoints: a proof run must be ok at every checkpoint where the control run is ok.

  tools/ckpt_gate.py CONTROL PROOF [--known 5880,5910,...]     # job ids (build/jobs/out/ID/{nb-out,wine-out}/trace.txt) or traces

Both kinds of checkpoint line a Wine replay writes are read (docs/wine-replay.md "Checkpoint hashing" and
"Particle-RNG checkpoints"):
  ckpt frame N hash H recording R ok|DIVERGED     the main hash (gameplay RNG, boot step, camera, clock)
  prng frame N hash H recording R ok|DIVERGED     the particle-RNG hash (images since div10; "(none)" when the
                                                  recording has no prng_checkpoints, which counts as ok)
For each kind: checkpoints, diverged frames, the first persistent divergence (20 diverged in a row), and the gate:
frames where the control is ok and the proof diverged. For prng also the hashes themselves against the control's
(the Wine build's particle stream is deterministic; the recording has prng checkpoints only for the frames where the
original's replays agree, play3: to 12900): a difference is reported as CHANGED, and fails with --strict-prng.
A control without prng lines (an image older than div10) leaves
that kind unchecked against it; the proof's own prng result is still reported. Exit 1 when a gate fails.
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LINE = re.compile(r"\b(ckpt|prng) frame (\d+) hash ([0-9a-f]+) recording (\(none\) )?([0-9a-f]+) (ok|DIVERGED)")


def trace_path(x):
    if os.path.isfile(x):
        return x
    for sub in ("nb-out", "wine-out"):
        p = os.path.join(ROOT, "build/jobs/out", str(x), sub, "trace.txt")
        if os.path.exists(p):
            return p
    sys.exit("no trace for " + x)


def load(x):
    """-> {"ckpt": {frame: (ok, hash, have_recording)}, "prng": {...}}"""
    out = {"ckpt": {}, "prng": {}}
    for l in open(trace_path(x), errors="replace"):
        m = LINE.search(l)
        if m:
            out[m.group(1)][int(m.group(2))] = (m.group(6) == "ok", m.group(3), not m.group(4))
    return out


def summary(d):
    frames = sorted(d)
    bad = [f for f in frames if not d[f][0]]
    bs = set(bad)
    pers = next((f for i, f in enumerate(frames) if all(g in bs for g in frames[i:i + 20])), None)
    have = sum(1 for f in frames if d[f][2])
    return frames, bad, pers, have


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("control")
    ap.add_argument("proof")
    ap.add_argument("--strict-prng", action="store_true", help="also fail when a prng hash differs from the control's")
    ap.add_argument("--known", default="", help="comma list of frames to mark as known transients in the listing")
    a = ap.parse_args(argv)
    known = {int(x) for x in a.known.split(",") if x}
    c, p = load(a.control), load(a.proof)
    fail = 0
    for kind in ("ckpt", "prng"):
        for name, d in (("control", c[kind]), ("proof", p[kind])):
            if not d:
                print("%s %s: no lines" % (kind, name))
                continue
            frames, bad, pers, have = summary(d)
            shown = [("%d*" % f if f in known else str(f)) for f in (bad if pers is None else [f for f in bad if f < pers])]
            print("%s %s: %d checkpoints (last %d, %d with a recorded hash), %d diverged; first persistent %s; before it: %s" % (
                kind, name, len(frames), frames[-1], have, len(bad), pers, " ".join(shown[:40]) + (" ..." if len(shown) > 40 else "")))
        if not c[kind] or not p[kind]:
            if kind == "prng" and not c[kind]:
                print("prng gate: not checked (the control has no prng lines: an image older than div10)")
            else:
                print("%s gate: FAILED (the proof has no %s lines)" % (kind, kind))
                fail = 1
            continue
        common = sorted(set(c[kind]) & set(p[kind]))
        regress = [f for f in common if c[kind][f][0] and not p[kind][f][0]]
        fixed = [f for f in common if not c[kind][f][0] and p[kind][f][0]]
        last = max(p[kind])                      # a proof stopped earlier (--frames) is judged on its own range
        missing = [f for f in c[kind] if c[kind][f][0] and f not in p[kind] and f <= last]
        print("%s gate: %d common frames; control-ok/proof-diverged %d%s; proof-ok/control-diverged %d; control-ok frames the proof lacks %d%s" % (
            kind, len(common), len(regress), (" (first %s)" % regress[:10]) if regress else "", len(fixed), len(missing),
            (" (first %d)" % min(missing)) if missing else ""))
        if regress or missing:
            fail = 1
        if kind == "prng":
            # the Wine build's particle stream is deterministic run to run and host to host (div10), while the
            # recording's prng checkpoints stop where the original's own replays stop agreeing; past that the
            # control's hashes are the reference: a proof that changes them changed the particles
            changed = [f for f in common if c[kind][f][1] != p[kind][f][1]]
            print("prng hashes against the control: %d of %d common frames differ%s%s" % (
                len(changed), len(common), (" (first %d)" % changed[0]) if changed else "",
                " -> FAILED (--strict-prng)" if changed and a.strict_prng else (" (CHANGED: the particles differ; see docs/wine-replay.md)" if changed else "")))
            if changed and a.strict_prng:
                fail = 1
    print("GATE " + ("FAILED" if fail else "ok"))
    return fail


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
