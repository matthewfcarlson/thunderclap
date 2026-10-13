#!/usr/bin/env python3
"""Per-function confidence for equivalent/ (docs/equivalence.md, "Trace replay").

  tools/equiv_confidence.py                    # rebuild build/equiv-confidence.json from what is on disk
  tools/equiv_confidence.py --fuzz [--inputs 256] [--jobs 3]   # also (re)run equiv.py where the cache is stale

Evidence per function:
  fuzz    equiv.py level 3 on fuzzed inputs: status, inputs run, branch coverage. From
          build/equiv/fuzz-cache.jsonl by source hash (filled by --fuzz), else the source's `// STATUS:` line.
  replay  tools/equiv_replay.py results of every capture session (build/traces/*/replay-equivalent.json) and
          tools/equiv_replay_fn.py per-function results (build/traces/replay-fn*.json), newest per (function,
          session): calls replayed and agreed, mismatches. A mismatch in any session wins. Results older than
          the source (committed later / different hash) are dropped.

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
import re
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


HEADER = re.compile(r"//\s*STATUS:\s*(\w+)\s*\(tools/equiv.py level 3:\s*(\d+) inputs, branch coverage (\d+)/(\d+)")


def header_fuzz(path):
    """The fuzz result the source's own `// STATUS:` line records (written when it was verified)."""
    with open(path, errors="replace") as f:
        for line in f.readlines()[:3]:
            m = HEADER.search(line)
            if m:
                return {"status": m.group(1), "inputs_run": int(m.group(2)), "edges_covered": int(m.group(3)),
                        "edges_total": int(m.group(4)), "n_inputs": None, "from": "header"}
    return None


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


def load_replays(sha_of=None, commit_time=None):
    """{addr: merged replay result}, one evidence entry per (function, session), newest wins:
    - build/traces/*/replay-equivalent.json: whole-session replays; dropped when the source was committed after
      the file was written (the source changed since: stale, counted in `stale_dropped`).
    - build/traces/replay-fn*.json: tools/equiv_replay_fn.py per-function replays (this machine and mac1);
      dropped when their source hash is not the current one.
    sha_of/commit_time: {addr: current sha} / {addr: last commit unix time} of the equivalent/ sources."""
    sha_of, commit_time = sha_of or {}, commit_time or {}
    ent = {}        # (addr, session) -> (ts, record)

    def put(addr, sess, ts, rec):
        if (addr, sess) not in ent or ent[(addr, sess)][0] < ts:
            ent[(addr, sess)] = (ts, rec)
    stale = {}
    for path in sorted(glob.glob(os.path.join(ROOT, "build/traces/*/replay-equivalent.json"))):
        sess = os.path.basename(os.path.dirname(path))
        mt = os.path.getmtime(path)
        for r in json.load(open(path))["results"]:
            if r.get("src") and not r["src"].startswith("equivalent/"):
                continue
            if commit_time.get(r["addr"], 0) > mt:
                stale.setdefault(r["addr"], []).append(sess)
                continue
            put(r["addr"], sess, mt, r)
    for path in sorted(glob.glob(os.path.join(ROOT, "build/traces/replay-fn*.json"))):
        for addr, f in json.load(open(path)).items():
            if not f.get("src", "").startswith("equivalent/"):
                continue
            if sha_of.get(addr) and f.get("sha") != sha_of[addr]:
                continue
            for sess, v in (f.get("sessions") or {}).items():
                rec = dict(v, addr=addr)
                mm = [m for m in f.get("mismatches") or [] if m.get("session") == sess]
                if mm:
                    rec["mismatches"] = [{"call": m["call"], "diffs": m["diffs"]} for m in mm]
                put(addr, sess, f.get("ts", 0), rec)
    out = {}
    for (addr, sess), (ts, r) in sorted(ent.items()):
        m = out.setdefault(addr, {"sessions": [], "captured": 0, "replayed": 0, "agreed": 0,
                                  "mismatched": 0, "incomplete": 0, "first_mismatch": None})
        m["sessions"].append(sess)
        for k in ("captured", "replayed", "agreed", "mismatched", "incomplete"):
            m[k] += r.get(k) or 0
        if r.get("mismatches") and not m["first_mismatch"]:
            mm = r["mismatches"][0]
            m["first_mismatch"] = {"session": sess, "call": mm["call"], "diffs": mm["diffs"][:2]}
        if r.get("status") == "error":
            m["error"] = r.get("error")
    for addr, ss in stale.items():
        out.setdefault(addr, {})["stale_dropped"] = ss
    return out


def _commit_times():
    """{addr: unix time of the last commit touching equivalent/ADDR.cpp} (one git pass)."""
    import subprocess
    out, cur = {}, None
    log = subprocess.check_output(["git", "log", "--format=@%ct", "--name-only", "--", "equivalent"], cwd=ROOT).decode()
    for line in log.splitlines():
        if line.startswith("@"):
            cur = int(line[1:])
        elif line.startswith("equivalent/0x"):
            out.setdefault("0x%08x" % int(line[11:-4], 16), cur)
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
    sha_of = {"0x%08x" % a: _sha(os.path.join(ROOT, src)) for src, a in srcs}
    replays = load_replays(sha_of, _commit_times())
    funcs = {}
    for src, a in srcs:
        addr = "0x%08x" % a
        sha = _sha(os.path.join(ROOT, src))
        fz = cache.get((addr, sha))
        fz = {k: fz.get(k) for k in ("status", "inputs_run", "edges_covered", "edges_total", "n_inputs")} if fz \
            else header_fuzz(os.path.join(ROOT, src))
        rec = {"src": src, "sha": sha, "fuzz": fz,
               "replay": replays.get(addr), "excluded": excl.get(addr)}
        rp = rec["replay"]
        if rp and rp.get("stale_dropped"):
            rec["replay_stale"] = rp.pop("stale_dropped")      # sessions whose result predates the source
            if "sessions" not in rp:
                rec["replay"] = rp = None
        rec["replay_status"] = ("mismatch" if rp and rp["mismatched"] else "agreed" if rp and rp["agreed"]
                                else "no_replay" if rp and (rp["captured"] or rp["incomplete"]) else "not_reached")
        rec["tier"] = tier_of(rec)
        funcs[addr] = rec
    from collections import Counter
    summary = {"tiers": {"%d %s" % (t, TIER_NAMES[t]): n for t, n in sorted(Counter(r["tier"] for r in funcs.values()).items())},
               "replay": dict(Counter(r["replay_status"] for r in funcs.values())),
               "fuzz_known": sum(1 for r in funcs.values() if r["fuzz"]),
               "replay_stale": sum(1 for r in funcs.values() if r.get("replay_stale"))}
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
