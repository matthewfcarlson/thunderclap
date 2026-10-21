#!/usr/bin/env python3
"""(round 18) Run equiv.py in MSVC mode and in native mode (--native: the clang object the native build links) over
a list of sources and print/collect both verdicts side by side.

  tools/equiv_native_sample.py LIST [--out FILE.jsonl] [--inputs 300] [--jobs 2] [--modes msvc,native] [--timeout 600]

LIST is a file of source paths (or `path addr` per line; the address defaults to the file name's 0xADDR). One JSON
line per (source, mode) is appended to --out, already-done pairs are skipped (resumable).
"""
import argparse
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
PY = sys.executable


def run_one(src, addr, mode, inputs, timeout, extra):
    cmd = [PY, os.path.join(ROOT, "tools/equiv.py"), src, addr, "--inputs", str(inputs), "--json"]
    if mode == "native":
        cmd.append("--native")
    cmd += extra
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout, cwd=ROOT)
    except subprocess.TimeoutExpired:
        return {"status": "timeout"}
    line = next((l for l in reversed(p.stdout.splitlines()) if l.startswith("{")), None)
    if not line:
        return {"status": "crash", "error": (p.stderr or p.stdout)[-300:]}
    rep = json.loads(line)
    l3 = rep.get("level3") or {}
    cov = l3.get("coverage") or {}
    mm = l3.get("mismatches") or []
    return {"status": rep.get("status"), "inputs": l3.get("inputs_run"), "failed": l3.get("inputs_failed"),
            "cov": "%s/%s" % (cov.get("edges_covered"), cov.get("edges_total")),
            "mismatch": (str(mm[0].get("diffs"))[:300] if mm else None),
            "l2": [i.get("kind") for i in (rep.get("level2") or {}).get("issues", [])][:4],
            "error": (rep.get("error") or "")[:200] or None, "time": rep.get("time"),
            "promotable": rep.get("promotable")}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("list")
    ap.add_argument("--out", required=True)
    ap.add_argument("--inputs", type=int, default=300)
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--modes", default="msvc,native")
    ap.add_argument("--timeout", type=int, default=600)
    a, extra = ap.parse_known_args()
    done = set()
    if os.path.exists(a.out):
        for l in open(a.out):
            r = json.loads(l)
            done.add((r["src"], r["mode"]))
    jobs = []
    for l in open(a.list):
        f = l.split("#")[0].split()
        if not f:
            continue
        src = f[0]
        addr = f[1] if len(f) > 1 else re.search(r"0x[0-9a-fA-F]{8}", os.path.basename(src)).group(0)
        for m in a.modes.split(","):
            if (src, m) not in done:
                jobs.append((src, addr, m))

    def go(j):
        src, addr, m = j
        r = run_one(src, addr, m, a.inputs, a.timeout, extra)
        r.update(src=src, addr=addr, mode=m)
        with open(a.out, "a") as f:
            f.write(json.dumps(r) + "\n")
        return r
    with ThreadPoolExecutor(a.jobs) as ex:
        for r in ex.map(go, jobs):
            print(r["addr"], r["mode"], r["status"], r.get("cov"), (r.get("mismatch") or "")[:100], flush=True)


if __name__ == "__main__":
    main()
