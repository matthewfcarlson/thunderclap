#!/usr/bin/env python3
"""Lint call declarations: tools/equiv.py's round-23 `decl_arity` diagnostic over many sources, without level 3.

  build/venv/bin/python tools/decl_lint.py SRC.cpp [SRC.cpp ...]           # one line per flagged callee
  build/venv/bin/python tools/decl_lint.py --all --out OUT.jsonl --jobq --name AGENT [--per 300]
  build/venv/bin/python tools/decl_lint.py --list LIST --out OUT.jsonl [--jobs 4]

A callee whose real stack arity (the original's `ret N`, the highest argument slot a cdecl callee reads, the fewest
words pending at the original's call sites, a function pointer some site calls with nothing pending) differs from
the stack words our declaration passes to it (its decoration, an `// equiv-conv` note, clang's call sites for a C
name). MSVC mode passes such a source when the bytes coincide; the Wine build breaks (docs/equivalence.md, round 23).
The address comes from the file name (0xADDR.cpp). OUT.jsonl gets one record per source: {addr, src, status,
decl_arity: [...]}; sources already in OUT are skipped (rerun to resume). LIST lines: "0xADDR path" or a path.
--jobq ships the sources with their jobs (the hosts' own matches/ and equivalent/ may be older). Exit 1 when
anything is flagged.
"""
import argparse
import glob
import json
import os
import re
import sys
import tempfile
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))


def _equiv():
    import importlib
    return importlib.import_module(os.environ.get("DECL_LINT_MODULE", "equiv"))


def lint_one(src, addr=None):
    eq = _equiv()
    if addr is None:
        m = re.search(r"0x([0-9a-fA-F]{8})", os.path.basename(src))
        if not m:
            return {"src": src, "status": "no_address"}
        addr = int(m.group(1), 16)
    rec = {"addr": "0x%08x" % addr, "src": src}
    if addr not in eq.Program.get().funcs:
        rec["status"] = "unknown_function"
        return rec
    try:
        rep = eq.verify(src, addr, max_level=2)
    except Exception as e:      # noqa: BLE001
        rec.update(status="error", error=str(e)[:300])
        return rec
    rec["status"] = rep.get("status")
    if rep.get("symbol"):
        rec["symbol"] = rep["symbol"]
    if rep.get("error"):
        rec["error"] = rep["error"][:300]
    rec["decl_arity"] = rep.get("decl_arity") or []
    if rep.get("decl_arity_error"):
        rec["decl_arity_error"] = rep["decl_arity_error"]
    return rec


def _worker(item):
    return lint_one(item[1], item[0])


def run_local(items, out, jobs=1):
    done = set()
    if out and os.path.exists(out):
        done = {(json.loads(l).get("src")) for l in open(out) if l.strip()}
    todo = [i for i in items if i[1] not in done]
    fo = open(out, "a") if out else None
    flagged = 0
    if jobs > 1:
        import multiprocessing as mp
        pool = mp.Pool(jobs)
        it = pool.imap_unordered(_worker, todo, chunksize=4)
    else:
        it = map(_worker, todo)
    for rec in it:
        if fo:
            fo.write(json.dumps(rec) + "\n")
            fo.flush()
        if rec.get("decl_arity"):
            flagged += 1
            if not fo:
                eq = _equiv()
                print("%s %s" % (rec["addr"], rec["src"]))
                print("\n".join(eq.render_decl_arity(rec["decl_arity"])))
    return flagged


def run_jobq(items, out, name, per=300, limit=3600, module=None):
    import jobq
    done = set()
    if os.path.exists(out):
        done = {json.loads(l).get("src") for l in open(out) if l.strip()}
    todo = [i for i in items if i[1] not in done]
    if not todo:
        return
    commit = jobq.head_commit()
    base = jobq.collect_files([], True)
    jobs, chunks = [], []
    with tempfile.TemporaryDirectory() as td:
        for k in range(0, len(todo), per):
            ch = todo[k:k + per]
            files = dict(base)
            lst = ""
            for ad, src in ch:
                dest = "jobsrc/" + src
                files[dest] = [jobq.store_file(os.path.join(ROOT, src)), 0o644]
                lst += "%s %s\n" % ("0x%08x" % ad if ad is not None else "-", dest)
            lp = os.path.join(td, "list%d" % k)
            open(lp, "w").write(lst)
            files["jobsrc/list.txt"] = [jobq.store_file(lp), 0o644]
            cmd = ["python", "tools/decl_lint.py", "--list", "jobsrc/list.txt", "--out", "jobsrc/out.jsonl", "--jobs", "2"] + (
                ["--module", module] if module else [])
            jobs.append(jobq.make_job(name, cmd, "equiv", files, ["jobsrc/out.jsonl"], limit, 2, 3, 0, commit))
            chunks.append(ch)
    ids = jobq.submit_jobs(jobs)
    print("submitted %d jobs: %s-%s" % (len(ids), ids[0], ids[-1]), file=sys.stderr)
    pending = dict(zip(ids, chunks))
    c = jobq.conn()
    with open(out, "a") as fo:
        while pending:
            rows = c.execute("SELECT id,state,host FROM jobs WHERE id IN (%s)" % ",".join(map(str, pending))).fetchall()
            for r in rows:
                if r["state"] not in jobq.TERMINAL:
                    continue
                pending.pop(r["id"])
                p = os.path.join(jobq.OUT, str(r["id"]), "jobsrc/out.jsonl")
                if os.path.exists(p):
                    for l in open(p):
                        try:
                            rec = json.loads(l)
                        except ValueError:
                            continue
                        rec["src"] = rec["src"][len("jobsrc/"):] if rec.get("src", "").startswith("jobsrc/") else rec.get("src")
                        rec["host"] = r["host"]
                        fo.write(json.dumps(rec) + "\n")
                fo.flush()
                print("job %s %s on %s; %d left" % (r["id"], r["state"], r["host"], len(pending)), file=sys.stderr)
            if pending:
                time.sleep(20)


def main(argv):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("srcs", nargs="*")
    p.add_argument("--list")
    p.add_argument("--all", action="store_true", help="every source in matches/ and equivalent/")
    p.add_argument("--out")
    p.add_argument("--jobs", type=int, default=1)
    p.add_argument("--jobq", action="store_true")
    p.add_argument("--name", default="decl_lint")
    p.add_argument("--per", type=int, default=300)
    p.add_argument("--limit", type=int, default=3600)
    p.add_argument("--module", help="the equiv module to use (a development copy of tools/equiv.py)")
    a = p.parse_args(argv)
    if a.module:
        os.environ["DECL_LINT_MODULE"] = a.module
    items = []
    if a.all:
        for d in ("matches", "equivalent"):
            for f in sorted(glob.glob(os.path.join(ROOT, d, "0x*.cpp"))):
                items.append((int(os.path.basename(f)[2:10], 16), os.path.relpath(f, ROOT)))
    if a.list:
        for line in open(a.list):
            parts = line.split()
            if not parts:
                continue
            if len(parts) == 1:
                items.append((None, parts[0]))
            else:
                items.append((None if parts[0] == "-" else int(parts[0], 16), parts[1]))
    items += [(None, s) for s in a.srcs]
    if a.jobq:
        if not a.out:
            p.error("--jobq needs --out")
        run_jobq(items, a.out, a.name, a.per, a.limit, a.module)
        return 0
    return 1 if run_local(items, a.out, a.jobs) else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
