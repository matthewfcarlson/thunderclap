#!/usr/bin/env python3
"""Routine trace replay of selected functions across every capture session (docs/equivalence.md,
"Routine replay after promotion").

  tools/equiv_replay_fn.py --since HEAD~1 --remote mac1     # the functions the last commit added or changed
  tools/equiv_replay_fn.py --functions 0x00241390,0x0026ce10 [--sessions s2,x-menus]
  tools/equiv_replay_fn.py --changed --remote mac1          # everything whose source changed since its last replay
  tools/equiv_replay_fn.py --index [--remote mac1]          # which sessions captured which functions

Only the given functions are replayed, against every session that captured them (ours is compiled once and
every session's recorded calls replay through it), so the cost is one compile plus at most --max-calls
recorded calls per session and function, not a whole-session replay. Results go to build/traces/replay-fn.json
(mac1's to build/traces/replay-fn-mac1.json) keyed by address with the source hash; tools/equiv_confidence.py
merges them with the session results. Functions no session captured print "not-captured" and are listed in
build/traces/capture-wanted.txt (they need a capture, no replay can help).
"""
import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv_replay as er  # noqa: E402

ROOT = er.ROOT
TRACES = er.TRACES
FN_OUT = os.path.join(TRACES, "replay-fn.json")
WANTED = os.path.join(TRACES, "capture-wanted.txt")
REMOTES = {"mac1": ("matthewcarlson@192.168.155.24", "hulk-permute")}
SRC_DIRS = ("equivalent", "matches", "build/farm/equiv-demoted")


def sha_of_file(path):
    return hashlib.sha1(open(path, "rb").read()).hexdigest()[:16]


EXTRA_DIRS = []      # --src-dir: searched first (e.g. a directory of demoted or experimental sources)


def find_src(addr):
    for d in list(EXTRA_DIRS) + list(SRC_DIRS):
        p = os.path.join(d, "0x%08x.cpp" % addr)
        if os.path.exists(os.path.join(ROOT, p)):
            return p
    return None


def local_sessions():
    return sorted(d for d in os.listdir(TRACES) if os.path.exists(os.path.join(TRACES, d, "trace.sqlite"))) \
        if os.path.isdir(TRACES) else []


def index(names=None):
    """{session: {addr: captured calls}} straight from each trace.sqlite's funcs table (milliseconds)."""
    import sqlite3
    out = {}
    for n in names or local_sessions():
        db = sqlite3.connect("file:%s?mode=ro" % os.path.join(TRACES, n, "trace.sqlite"), uri=True)
        out[n] = {f: c for f, c in db.execute("SELECT func, captured FROM funcs WHERE captured > 0")}
    return out


def git_times():
    """{equivalent/ path: unix time of the last commit touching it}, one git pass."""
    out, cur = {}, None
    log = subprocess.check_output(["git", "log", "--format=@%ct", "--name-only", "--", "equivalent"], cwd=ROOT).decode()
    for line in log.splitlines():
        if line.startswith("@"):
            cur = int(line[1:])
        elif line and line not in out:
            out[line] = cur
    return out


def load_fn(path=FN_OUT):
    return json.load(open(path)) if os.path.exists(path) else {}


def last_replay_time(addr, fn_all):
    """Newest replay we have for addr: from the fn files, else the session replay-equivalent.json mtimes."""
    ts = [r.get("ts", 0) for fn in fn_all for r in [fn.get(addr)] if r]
    return max(ts) if ts else None


def stale(addrs_src, fn_all):
    """Addresses whose current equivalent/ source is newer than its last replay: a per-function record with a
    different source hash, or a whole-session result written before the source's last commit (the same rule
    tools/equiv_confidence.py uses to drop evidence)."""
    import equiv_confidence as ec
    srcs = {a: s for a, s in addrs_src if s.startswith("equivalent/")}
    sha_of = {a: sha_of_file(os.path.join(ROOT, s)) for a, s in srcs.items()}
    out = {a for a in srcs for fn in fn_all if a in fn and fn[a].get("sessions") and fn[a].get("sha") != sha_of[a]}
    out |= {a for a, r in ec.load_replays(sha_of, ec._commit_times()).items() if r.get("stale_dropped")}
    return sorted(out)


def select(a, remote_fn):
    addrs = []
    if a.functions:
        for x in a.functions.split(","):
            x = x.strip()
            if x.startswith("@"):
                addrs += [l.split()[0] for l in open(x[1:]) if l.strip()]
            elif x:
                addrs.append(x)
    if a.since:
        d = subprocess.check_output(["git", "diff", "--name-only", "--diff-filter=AM", a.since, "HEAD", "--", "equivalent"],
                                    cwd=ROOT).decode().split()
        addrs += [os.path.basename(f)[:-4] for f in d if f.endswith(".cpp")]
    addrs = ["0x%08x" % int(x, 16) for x in addrs]
    if a.changed:
        cand = [("0x%08x" % ad, s) for s, ad in er.sources("equivalent")]
        addrs += stale(cand, [load_fn()] + remote_fn)
    return sorted(set(addrs))


def run_local(addrs, names, max_calls, budget, jobs):
    import multiprocessing as mp
    idx = index(names)
    work = []
    for a in addrs:
        ad = int(a, 16)
        have = [n for n in idx if ad in idx[n]]
        src = find_src(ad)
        work.append((a, src, have, max_calls, budget))
    res = {}
    todo = [w for w in work if w[1] and w[2]]
    for a, src, have, *_ in work:
        if not src:
            res[a] = {"addr": a, "status": "no-source", "sessions": {}}
        elif not have:
            res[a] = {"addr": a, "src": src, "status": "not-captured", "sessions": {}, "sha": sha_of_file(os.path.join(ROOT, src)),
                      "ts": int(time.time())}
    if todo:
        with mp.get_context("fork").Pool(min(jobs, 6, len(todo))) as pool:
            for r in pool.imap_unordered(_job, todo):
                res[r["addr"]] = r
                print_row(r, flush=True)
    return res


def _job(w):
    a, src, have, max_calls, budget = w
    try:
        stores = [(n, er.TraceStore(os.path.join(TRACES, n))) for n in have]
        r = er.replay_multi(src, int(a, 16), stores, max_calls, budget)
    except Exception as e:
        r = {"addr": a, "src": src, "status": "error", "error": repr(e)[:200], "per_session": {}}
    r["sessions"] = r.pop("per_session", {})
    r["sha"] = sha_of_file(os.path.join(ROOT, src))
    r["ts"] = int(time.time())
    for k in ("mismatches", "incomplete_reasons", "notes", "coverage", "level2_ok"):
        if k == "mismatches" and r.get(k):
            r[k] = [{"session": m.get("session"), "call": m["call"], "diffs": m["diffs"][:2]} for m in r[k][:2]]
        elif k != "mismatches":
            r.pop(k, None)
    return r


def print_row(r, flush=False):
    s = "%s %-12s" % (r["addr"], r.get("status"))
    if r.get("sessions"):
        s += " " + " ".join("%s:%d/%d" % (n, v["agreed"], v["replayed"]) for n, v in sorted(r["sessions"].items()))
        s += "  [%ss, setup %ss]" % (r.get("time"), r.get("t_setup"))
    if r.get("mismatches"):
        m = r["mismatches"][0]
        s += "\n    mismatch (%s call %s): %s" % (m.get("session"), m["call"], "; ".join(m["diffs"]))
    if r.get("error"):
        s += "\n    error: " + str(r["error"])
    print(s, flush=flush)


def remote_run(host, addrs, a):
    """Sync tools/ and the sources to the remote copy, replay there, return (Popen, fetch function)."""
    ssh, d = REMOTES[host]
    stage = os.path.join(ROOT, "build/farm/replay-src")      # --src-dir sources travel as build/farm/replay-src/
    files = ["tools/*.py"]
    for x in addrs:
        src = find_src(int(x, 16))
        if src and os.path.isabs(src):
            os.makedirs(stage, exist_ok=True)
            shutil.copy(src, stage)
            src = "build/farm/replay-src/" + os.path.basename(src)
        if src:
            files.append(src)
    tar = subprocess.run("COPYFILE_DISABLE=1 tar czf - %s | ssh %s 'cd ~/%s && mkdir -p build/farm/equiv-demoted && tar xzf -'"
                         % (" ".join(files), ssh, d), shell=True, cwd=ROOT)
    if tar.returncode:
        raise SystemExit("sync to %s failed" % host)
    cmd = "cd ~/%s && nice build/venv/bin/python tools/equiv_replay_fn.py --functions %s --sessions %s --max-calls %d " \
          "--budget %d --jobs %d --out build/traces/replay-fn.json%s" % (
              d, ",".join(addrs), a.sessions, a.max_calls, a.budget, min(a.jobs, 3),
              " --src-dir build/farm/replay-src" if a.src_dir else "")
    return subprocess.Popen(["ssh", ssh, cmd], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True), \
        lambda: subprocess.run(["scp", "-q", "%s:%s/build/traces/replay-fn.json" % (ssh, d),
                                os.path.join(TRACES, "replay-fn-%s.json" % host)])


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--functions", help="comma-separated addresses (or @file with one per line)")
    ap.add_argument("--since", help="also: functions equivalent/ added or changed in REV..HEAD (e.g. HEAD~1)")
    ap.add_argument("--changed", action="store_true", help="also: equivalent/ sources changed since their last replay")
    ap.add_argument("--sessions", default="all", help="all, or comma-separated session names")
    ap.add_argument("--remote", action="append", default=[], choices=sorted(REMOTES), help="also run on this host")
    ap.add_argument("--max-calls", type=int, default=30, help="recorded calls per function and session, spread evenly (default 30)")
    ap.add_argument("--budget", type=int, default=30, help="CPU seconds per function and session (default 30)")
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--index", action="store_true", help="print sessions and how many functions each captured")
    ap.add_argument("--src-dir", action="append", default=[], help="look for 0xADDR.cpp here before equivalent/")
    ap.add_argument("--out", default=FN_OUT)
    a = ap.parse_args(argv)
    EXTRA_DIRS[:] = a.src_dir
    names = None if a.sessions == "all" else a.sessions.split(",")
    if a.index:
        for n, f in index(names).items():
            print("%-12s %4d functions %6d calls" % (n, len(f), sum(f.values())))
        return 0
    remote_fn = [load_fn(os.path.join(TRACES, "replay-fn-%s.json" % h)) for h in REMOTES
                 if os.path.exists(os.path.join(TRACES, "replay-fn-%s.json" % h))]
    addrs = select(a, remote_fn)
    if not addrs:
        raise SystemExit("nothing selected (use --functions, --since REV or --changed)")
    t0 = time.time()
    print("%d functions, sessions: %s" % (len(addrs), ", ".join(index(names)) or "(none local)"), file=sys.stderr)
    procs = [(h,) + remote_run(h, addrs, a) for h in a.remote]
    res = run_local(addrs, names, a.max_calls, a.budget, a.jobs)
    fn = load_fn(a.out)
    fn.update(res)
    json.dump(fn, open(a.out, "w"), indent=1)
    for h, p, fetch in procs:
        out = p.communicate()[0]
        fetch()
        print("--- %s:\n%s" % (h, out.strip()), file=sys.stderr)
    # summary over local + remote
    allfn = [res] + [load_fn(os.path.join(TRACES, "replay-fn-%s.json" % h)) for h, _, _ in procs]
    from collections import Counter
    verdict = {}
    for ad in addrs:
        st = [f[ad]["status"] for f in allfn if ad in f and f[ad].get("sessions")]
        other = [f[ad]["status"] for f in allfn if ad in f and f[ad]["status"] not in ("not-captured", "not_reached")]
        verdict[ad] = "mismatch" if "mismatch" in st else "agreed" if "agreed" in st else \
            "no_replay" if st else other[0] if other else "not-captured"
    wanted = sorted(ad for ad, v in verdict.items() if v == "not-captured" and find_src(int(ad, 16)))
    for ad in addrs:
        if verdict[ad] == "not-captured":
            print("%s not-captured" % ad)
    if wanted:
        old = set(open(WANTED).read().split()) if os.path.exists(WANTED) else set()
        open(WANTED, "w").write("\n".join(sorted(old | set(wanted))) + "\n")
    print("summary: %s  (%.0fs)" % (dict(Counter(verdict.values())), time.time() - t0))
    return 1 if "mismatch" in verdict.values() else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
