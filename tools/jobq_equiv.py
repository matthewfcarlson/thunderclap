#!/usr/bin/env python3
"""Run tools/equiv.py over a list of sources through the shared job queue (tools/jobq.py, docs/compute.md).

Usage: tools/jobq_equiv.py LIST OUT.jsonl [--name AGENT] [--per N] [--no-dirty] [--attempts N] [--limit S]
                           [--status FILE] [-- equiv.py args]
LIST has one "0xADDR path/to/source.cpp" per line (the same file promote_dispatch.py and equiv_batch.py take). One job
runs N functions (default 2). Each source is shipped with its job, so uncommitted sources and, unless --no-dirty,
uncommitted tools/ files are what the remote hosts run. OUT.jsonl gets the records equiv_batch.py writes (plus
"host"); addresses already in OUT are skipped, so a rerun resumes. Exit 0 when every address has a result.
"""
import argparse
import json
import os
import re
import sys
import tempfile
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import jobq


def default_limit(extra, margin=600):
    m = re.search(r"--time-budget\s+(\d+)", " ".join(extra))
    return (int(m.group(1)) if m else 1800) + margin


def run_items(name, items, out, extra, per=2, attempts=3, limit=None, dirty=True, status=None, quiet=False):
    """items: [(addr, src)]. Appends one record per finished address to the file OUT; returns {addr: record}."""
    done = {}
    if os.path.exists(out):
        done = {json.loads(l)["addr"]: json.loads(l) for l in open(out) if l.strip()}
    todo = [i for i in items if i[0] not in done]
    if not todo:
        return done
    limit = limit or default_limit(extra)
    commit = jobq.head_commit()
    base = jobq.collect_files([], dirty)
    jobs, chunks = [], []
    with tempfile.TemporaryDirectory() as td:
        for k in range(0, len(todo), per):
            ch = todo[k:k + per]
            files = dict(base)
            lst = ""
            for ad, src in ch:
                files["jobsrc/%s.cpp" % ad] = [jobq.store_file(src), 0o644]
                lst += "%s jobsrc/%s.cpp\n" % (ad, ad)
            lp = os.path.join(td, "list")
            open(lp, "w").write(lst)
            files["jobsrc/list.txt"] = [jobq.store_file(lp), 0o644]
            cmd = ["python", "tools/equiv_batch.py", "jobsrc/list.txt", "jobsrc/out.jsonl", "--jobs", str(len(ch)), "--"] + extra
            jobs.append(jobq.make_job(name, cmd, "equiv", files, ["jobsrc/out.jsonl"], limit, len(ch), attempts, 0,
                                      commit))
            chunks.append(ch)
    ids = jobq.submit_jobs(jobs)
    srcs = dict(todo)
    pending = dict(zip(ids, chunks))
    results, gaveup, t0, last = dict(done), {}, time.time(), 0
    c = jobq.conn()
    with open(out, "a") as fo:
        while pending:
            rows = c.execute("SELECT id,state,host,reason FROM jobs WHERE id IN (%s)" % ",".join(map(str, pending))).fetchall()
            for r in rows:
                if r["state"] not in jobq.TERMINAL:
                    continue
                ch = pending.pop(r["id"])
                p = os.path.join(jobq.OUT, str(r["id"]), "jobsrc/out.jsonl")
                recs = []
                if os.path.exists(p):
                    for l in open(p):
                        try:
                            recs.append(json.loads(l))
                        except ValueError:
                            pass
                for rec in recs:
                    ad = rec.get("addr")
                    if ad in srcs and rec.get("status") not in (None, "error") and ad not in results:
                        rec["src"], rec["host"] = srcs[ad], r["host"]
                        results[ad] = rec
                        fo.write(json.dumps(rec) + "\n")
                        fo.flush()
                for ad, _ in ch:
                    if ad not in results:
                        gaveup[ad] = r["reason"] or r["state"]
            if status or (not quiet and time.time() - last > 30):
                last = time.time()
                msg = "%s %d/%d done, %d jobs pending, %d gave up, elapsed %dm" % (
                    time.strftime("%H:%M:%S"), len(results) - len(done), len(todo), len(pending), len(gaveup),
                    (time.time() - t0) // 60)
                if status:
                    open(status + ".tmp", "w").write(msg + "\n")
                    os.replace(status + ".tmp", status)
                if not quiet:
                    print(msg, file=sys.stderr, flush=True)
            if pending:
                time.sleep(1)
                if not os.environ.get("JOBQ_NO_DAEMON") and int(time.time()) % 30 == 0:
                    jobq.ensure()
    if gaveup:
        print("unfinished: %s" % sorted(gaveup), file=sys.stderr)
    return results


def main():
    argv, extra = jobq.split_dashdash(sys.argv[1:])
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("list"), ap.add_argument("out")
    ap.add_argument("--name", default=os.environ.get("USER", "agent"))
    ap.add_argument("--per", type=int, default=2)
    ap.add_argument("--attempts", type=int, default=3)
    ap.add_argument("--limit", type=int)
    ap.add_argument("--no-dirty", action="store_true")
    ap.add_argument("--status")
    a = ap.parse_args(argv)
    items = [tuple(l.split()[:2]) for l in open(a.list) if l.strip()]
    res = run_items(a.name, items, a.out, extra, a.per, a.attempts, a.limit, not a.no_dirty, a.status)
    missing = [i for i, _ in items if i not in res]
    print("%d/%d with a result" % (len(items) - len(missing), len(items)))
    return 1 if missing else 0


if __name__ == "__main__":
    sys.exit(main())
