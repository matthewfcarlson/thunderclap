#!/usr/bin/env python3
"""Ground-truth check for tools/equiv.py: matched functions must pass level 3 against themselves.

  build/venv/bin/python tests/equiv/selftest.py [--n 300] [--jobs 2] [--flags /O1] [--only 0x...,0x...]

Picks a size-stratified sample of matches/ (fixed seed), runs equiv.verify on each and writes
build/equiv/selftest[-<flags>].jsonl plus a summary. With --flags the same sources are compiled with
different options (e.g. /Oy- or /O1): different bytes, same behaviour, so they must pass too.
Skips when the game files are absent.
"""
import argparse
import json
import os
import random
import sys
import time
from collections import Counter
from multiprocessing import Pool

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))

BUCKETS = [(0, 32), (32, 64), (64, 128), (128, 256), (256, 512), (512, 1 << 20)]


def sample(n, seed=9):
    import equiv
    prog = equiv.Program.get()
    files = sorted(f for f in os.listdir(os.path.join(ROOT, "matches")) if f.endswith(".cpp"))
    by = {b: [] for b in BUCKETS}
    for f in files:
        a = int(f[:-4], 16)
        if a not in prog.funcs:
            continue
        sz = prog.funcs[a][0]
        for b in BUCKETS:
            if b[0] <= sz < b[1]:
                by[b].append(a)
    rng = random.Random(seed)
    per = n // len(BUCKETS)
    out = []
    for b in BUCKETS:
        out += rng.sample(by[b], min(per, len(by[b])))
    return sorted(out)


def job(args):
    addr, flags = args
    import equiv
    src = os.path.join(ROOT, "matches", "0x%08x.cpp" % addr)
    t = time.time()
    try:
        r = equiv.verify(src, addr, flags=flags)
    except Exception as e:
        import traceback
        r = {"addr": "0x%08x" % addr, "status": "crash", "error": traceback.format_exc()[-1500:]}
    r["wall"] = round(time.time() - t, 2)
    r["size"] = equiv.Program.get().funcs[addr][0]
    return r


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--n", type=int, default=300)
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--flags", default="", help="extra cl flags, space separated")
    p.add_argument("--only", help="comma-separated addresses")
    p.add_argument("--out")
    a = p.parse_args()
    if not os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")):
        print("skip: no isos/extracted/default.xbe")
        return 0
    addrs = [int(x, 16) for x in a.only.split(",")] if a.only else sample(a.n)
    flags = a.flags.split()
    tag = "-" + "".join(f.strip("/") for f in flags) if flags else ""
    out = a.out or os.path.join(ROOT, "build/equiv/selftest%s.jsonl" % tag)
    os.makedirs(os.path.dirname(out), exist_ok=True)
    counts, fails = Counter(), []
    t0 = time.time()
    with open(out, "w") as f, Pool(a.jobs) as pool:
        for i, r in enumerate(pool.imap_unordered(job, [(x, flags) for x in addrs])):
            f.write(json.dumps(r, default=str) + "\n")
            f.flush()
            counts[r["status"]] += 1
            if r["status"] != "equivalent":
                fails.append(r)
            if (i + 1) % 25 == 0:
                print("  %d/%d %s" % (i + 1, len(addrs), dict(counts)), flush=True)
    print("results:", dict(counts), "in %.0fs" % (time.time() - t0))
    for r in fails:
        l3 = r.get("level3") or {}
        why = (l3.get("mismatches") or [{}])[0].get("diffs") or l3.get("unsupported") or \
            [i["kind"] for i in (r.get("level2") or {}).get("issues", [])][:3] or r.get("error", "")[-300:]
        print("  %s %-11s %5s B  %s" % (r["addr"], r["status"], r.get("size"), why))
    return 0


if __name__ == "__main__":
    sys.exit(main())
