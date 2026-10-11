#!/usr/bin/env python3
"""Apply the vptr-store-order recipe (docs/agents/match-brief.md, "vptr store order") to saved attempts.

MSVC 7.1 sinks a vtable store below the first member load unless something pins it. The original's
code keeps it first, and `_ReadWriteBarrier()` (an intrinsic that emits no code) right after the store
reproduces that. This tool takes the farm's saved attempts for unmatched functions, inserts the barrier
after each vptr store in the target body, and installs the first variant that passes tools/compare.py
and tools/verify_relocs.py.

Usage:
  tools/fix_vptr.py --only FILE [--skip FILE] [--dry-run]
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from collections import Counter
from multiprocessing import Pool

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import verify_relocs as vr  # noqa: E402
from fix_relocs import attempts  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DECL = 'extern "C" void _ReadWriteBarrier();\n'
# A statement storing a vtable: `vptr = ...;`, `*(void**)this = ...;`, `x->vfptr = &..._vftable;`.
STORE = re.compile(r"[^;{}]*(\bvptr\b|\bvfptr\b|\bvftable\b|_vftable\b|\*\s*\(\s*void\s*\*\*\s*\)\s*this)[^;{}=]*=[^=;][^;]*;")


def variants(text):
    """One variant with the barrier after the first vptr store, then one with it after every store."""
    if "_ReadWriteBarrier" in text:
        return
    ms = [m for m in STORE.finditer(text) if not m.group(0).lstrip().startswith(("extern", "static", "const"))]
    if not ms:
        return
    for chosen in (ms[:1], ms):
        out, pos = [], 0
        for m in chosen:
            out.append(text[pos:m.end()])
            out.append(" _ReadWriteBarrier();")
            pos = m.end()
        out.append(text[pos:])
        body = "".join(out)
        # Keep a leading `// cl-flags:` line first.
        if body.startswith("// cl-flags:"):
            nl = body.index("\n") + 1
            yield body[:nl] + DECL + body[nl:]
        else:
            yield DECL + body
        if len(ms) == 1:
            break


def work(addr):
    a = int(addr, 16)
    tried = Counter()
    with tempfile.TemporaryDirectory() as tmp:
        for src in attempts(addr)[:12]:
            try:
                text = open(src).read()
            except OSError:
                continue
            for v in variants(text):
                path = os.path.join(tmp, addr + ".cpp")
                open(path, "w").write(v)
                tried["variants"] += 1
                try:
                    r = vr.check(path, a)
                except Exception:  # noqa: BLE001
                    continue
                tried[r["status"]] += 1
                if r["status"] == "ok":
                    keep = os.path.join(ROOT, "build/farm/fix-vptr", addr + ".cpp")
                    os.makedirs(os.path.dirname(keep), exist_ok=True)
                    shutil.copy(path, keep)
                    return {"addr": addr, "status": "fixed", "src": keep, "from": src}
    return {"addr": addr, "status": "unfixed", "tried": dict(tried)}


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--only", required=True, help="file with addresses to try")
    p.add_argument("--skip", help="file with addresses to leave alone (e.g. an agent's batch)")
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--jobs", type=int, default=6)
    p.add_argument("--out", default=os.path.join(ROOT, "build/farm/fix-vptr.jsonl"))
    a = p.parse_args()
    skip = set(open(a.skip).read().split()) if a.skip else set()
    addrs = [l.split()[0] for l in open(a.only) if l.strip()]
    addrs = [x for x in addrs if x not in skip and not os.path.exists(os.path.join(ROOT, "matches", x + ".cpp"))]
    print("%d candidates" % len(addrs), flush=True)
    counts, installed = Counter(), []
    with open(a.out, "w") as out, Pool(a.jobs) as pool:
        for r in pool.imap_unordered(work, addrs):
            out.write(json.dumps(r) + "\n")
            counts[r["status"]] += 1
            if r["status"] == "fixed":
                print("  %s fixed" % r["addr"], flush=True)
                dst = os.path.join(ROOT, "matches", r["addr"] + ".cpp")
                if not a.dry_run and not os.path.exists(dst):
                    shutil.copy(r["src"], dst)
                    installed.append(dst)
    if installed:
        subprocess.run([sys.executable, os.path.join(ROOT, "tools/format_matches.py")] + installed, check=False)
    print("results:", dict(counts))


if __name__ == "__main__":
    main()
