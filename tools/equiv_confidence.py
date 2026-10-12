#!/usr/bin/env python3
"""Per-function confidence for equivalent/ (docs/equivalence.md, "Trace replay").

  tools/equiv_confidence.py                    # rebuild build/equiv-confidence.json from what is on disk
  tools/equiv_confidence.py --fuzz [--inputs 256] [--jobs 3]   # also (re)run equiv.py where the cache is stale

Evidence per function:
  fuzz    equiv.py level 3 on fuzzed inputs: status, inputs run, branch coverage. Cached in
          build/equiv/fuzz-cache.jsonl by source hash (filled by --fuzz).
  replay  tools/equiv_replay.py results of every capture session (build/traces/*/replay-*.json): calls
          replayed and agreed, mismatches. A mismatch in any session wins.

Tiers (higher = more trusted; patch_xbe.py --confidence/--tier-min and bisect_hybrid.py use them):
  0  replay mismatch, or listed in hybrid/exclude.txt
  1  fuzz only: never reached in a capture, or no call could be replayed
  2  replay agreed on fewer than MIN_AGREED recorded calls
  3  replay agreed on at least MIN_AGREED recorded calls
"""
import argparse
import glob
import hashlib
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
OUT = os.path.join(ROOT, "build/equiv-confidence.json")
FUZZ_CACHE = os.path.join(ROOT, "build/equiv/fuzz-cache.jsonl")
EXCLUDE = os.path.join(ROOT, "hybrid/exclude.txt")
MIN_AGREED = 3
TIER_NAMES = {0: "mismatch", 1: "fuzz-only", 2: "replay-thin", 3: "replay-verified"}


def _sha(path):
    return hashlib.sha1(open(path, "rb").read()).hexdigest()[:16]


def load_fuzz():
    out = {}
    if os.path.exists(FUZZ_CACHE):
        for line in open(FUZZ_CACHE):
            try:
                r = json.loads(line)
            except ValueError:
                continue
            out[(r["addr"], r["sha"])] = r
    return out


def _fuzz_job(args):
    src, addr, n = args
    import equiv
    t0 = time.time()
    try:
        rep = equiv.verify(src, int(addr, 16), n_inputs=n)
    except Exception as e:
        return {"addr": addr, "status": "error", "error": repr(e)[:200]}
    l3 = rep.get("level3") or {}
    cov = l3.get("coverage") or {}
    return {"addr": addr, "status": rep.get("status"), "inputs_run": l3.get("inputs_run"),
            "edges_covered": cov.get("edges_covered"), "edges_total": cov.get("edges_total"),
            "byte_identical": rep.get("byte_identical"), "n_inputs": n, "time": round(time.time() - t0, 1)}


def run_fuzz(todo, n, jobs):
    import multiprocessing as mp
    os.makedirs(os.path.dirname(FUZZ_CACHE), exist_ok=True)
    work = [(src, addr, n) for addr, src, sha in todo]
    shas = {addr: sha for addr, _, sha in todo}
    with open(FUZZ_CACHE, "a") as f, mp.get_context("fork").Pool(min(jobs, 3)) as pool:
        for i, r in enumerate(pool.imap_unordered(_fuzz_job, work)):
            r["sha"] = shas[r["addr"]]
            f.write(json.dumps(r) + "\n")
            f.flush()
            print("  fuzz %d/%d %s %s" % (i + 1, len(work), r["addr"], r["status"]), file=sys.stderr)


def load_replays():
    """{addr: merged replay result} over every session's replay-equivalent.json (and replay-src.json)."""
    out = {}
    for path in sorted(glob.glob(os.path.join(ROOT, "build/traces/*/replay-equivalent.json"))):
        sess = os.path.basename(os.path.dirname(path))
        for r in json.load(open(path))["results"]:
            if r.get("src", "").startswith("equivalent/") is False and r.get("src"):
                continue
            m = out.setdefault(r["addr"], {"sessions": [], "captured": 0, "replayed": 0, "agreed": 0,
                                           "mismatched": 0, "incomplete": 0, "first_mismatch": None})
            m["sessions"].append(sess)
            for k in ("captured", "replayed", "agreed", "mismatched", "incomplete"):
                m[k] += r.get(k) or 0
            if r.get("mismatches") and not m["first_mismatch"]:
                mm = r["mismatches"][0]
                m["first_mismatch"] = {"session": sess, "call": mm["call"], "diffs": mm["diffs"][:2]}
            if r.get("status") == "error":
                m["error"] = r.get("error")
    return out


def tier_of(rec):
    rp = rec.get("replay") or {}
    if rec.get("excluded") or rp.get("mismatched"):
        return 0
    if not rp.get("agreed"):
        return 1
    return 3 if rp["agreed"] >= MIN_AGREED else 2


def build(fuzz=False, n_inputs=256, jobs=3):
    import equiv_replay as er
    srcs = er.sources("equivalent")
    excl = {}
    if os.path.exists(EXCLUDE):
        for line in open(EXCLUDE):
            s = line.split("#")[0].strip()
            if s:
                excl["0x%08x" % int(s.split()[0], 16)] = line.split(None, 1)[1].strip() if len(line.split(None, 1)) > 1 else ""
    cache = load_fuzz()
    if fuzz:
        todo = []
        for src, a in srcs:
            addr, sha = "0x%08x" % a, _sha(os.path.join(ROOT, src))
            if (addr, sha) not in cache:
                todo.append((addr, src, sha))
        if todo:
            print("fuzzing %d functions (%d inputs)" % (len(todo), n_inputs), file=sys.stderr)
            run_fuzz(todo, n_inputs, jobs)
            cache = load_fuzz()
    replays = load_replays()
    funcs = {}
    for src, a in srcs:
        addr = "0x%08x" % a
        sha = _sha(os.path.join(ROOT, src))
        fz = cache.get((addr, sha))
        rec = {"src": src, "sha": sha,
               "fuzz": {k: fz.get(k) for k in ("status", "inputs_run", "edges_covered", "edges_total", "n_inputs")}
               if fz else None,
               "replay": replays.get(addr), "excluded": excl.get(addr)}
        rp = rec["replay"]
        rec["replay_status"] = ("mismatch" if rp and rp["mismatched"] else "agreed" if rp and rp["agreed"]
                                else "no_replay" if rp and (rp["captured"] or rp["incomplete"]) else "not_reached")
        rec["tier"] = tier_of(rec)
        funcs[addr] = rec
    from collections import Counter
    summary = {"tiers": {"%d %s" % (t, TIER_NAMES[t]): n for t, n in sorted(Counter(r["tier"] for r in funcs.values()).items())},
               "replay": dict(Counter(r["replay_status"] for r in funcs.values())),
               "fuzz_known": sum(1 for r in funcs.values() if r["fuzz"])}
    doc = {"generated": time.strftime("%Y-%m-%d %H:%M"), "min_agreed": MIN_AGREED, "tier_names": TIER_NAMES,
           "summary": summary, "functions": funcs}
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    json.dump(doc, open(OUT, "w"), indent=1)
    return doc


def load_tiers(path=OUT):
    """{addr int: tier} from a confidence file (patch_xbe.py, bisect_hybrid.py)."""
    doc = json.load(open(path))
    return {int(a, 16): r["tier"] for a, r in doc["functions"].items()}


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--fuzz", action="store_true", help="run equiv.py for functions without a cached fuzz result")
    ap.add_argument("--inputs", type=int, default=256)
    ap.add_argument("--jobs", type=int, default=3)
    a = ap.parse_args(argv)
    doc = build(a.fuzz, a.inputs, a.jobs)
    print(json.dumps(doc["summary"], indent=1))
    print("wrote %s" % os.path.relpath(OUT, ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
