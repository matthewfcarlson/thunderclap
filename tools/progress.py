#!/usr/bin/env python3
"""Byte-weighted verification status of the game code, read from the merged tree (src/{game,engine,platform/xbox}):
a function counts as byte-matched or proven equivalent by its block header (`// 0xADDR NAME (SIZE B): matches|equivalent`,
tools/tree_tu.py). matches/ and equivalent/ are frozen at the merge-once flip (docs/merge-once.md) and not read here.

--readme rewrites the status table between the <!-- status --> markers in README.md, redraws docs/progress-map.svg
(tools/progress_map.py) and refreshes docs/game-functions.csv (skipped while that file has uncommitted changes, since
the checkout is shared)."""
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(__file__))
from packet import Db
import tree_tu

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


def tree_kinds(root=ROOT):
    """{address: 'matches' | 'equivalent'} over every block of every tree TU."""
    out = {}
    for p in tree_tu.tree_tus(root):
        for b in tree_tu.scan(p)["blocks"]:
            out[int(b["addr"], 16)] = b["kind"]
    return out


def main():
    db = Db()
    kinds = tree_kinds()
    game = [r for r in db.funcs.values() if db.is_game(r)]
    total = sum(int(r["size"]) for r in game)
    kind = lambda r: kinds.get(int(r["address"], 16))
    matched = [r for r in game if kind(r) == "matches"]
    mb = sum(int(r["size"]) for r in matched)
    # Behaviour-verified (tools/equiv.py), not byte-matched.
    equiv = [r for r in game if kind(r) == "equivalent"]
    eb = sum(int(r["size"]) for r in equiv)
    # Library code (XAPILIB, LIBCMT, D3D, DSOUND, Bink, ...): reimplemented, never in the tree; reported apart
    # (docs/platform-boundary.md, "Rules").
    lib = [r for r in db.funcs.values() if db.is_library(r)]
    lb = sum(int(r["size"]) for r in lib)
    spent = 0.0
    for p in [os.path.join(ROOT, "build/farm/results.jsonl")]:
        if os.path.exists(p):
            spent += sum(json.loads(l).get("cost", 0) for l in open(p) if l.strip())
    table = (
        "| | Functions | Bytes |\n|---|---|---|\n"
        "| Game code (`.text`, excluding XDK/CRT/Bink) | {:,} | {:.2f} MB |\n"
        "| Byte-matched (`: matches` blocks) | {:,} ({:.1f}%) | {:.0f} KB ({:.1f}%) |\n"
        "| Proven equivalent (`: equivalent` blocks) | {:,} ({:.1f}%) | {:.0f} KB ({:.1f}%) |\n"
        "| **Verified source, total** | {:,} ({:.1f}%) | {:.0f} KB (**{:.1f}%**) |\n"
    ).format(len(game), total / 1e6, len(matched), 100 * len(matched) / len(game), mb / 1e3, 100 * mb / total,
             len(equiv), 100 * len(equiv) / len(game), eb / 1e3, 100 * eb / total,
             len(matched) + len(equiv), 100 * (len(matched) + len(equiv)) / len(game), (mb + eb) / 1e3, 100 * (mb + eb) / total)
    missing = [r["address"] for r in game if kind(r) is None]
    print(table + "library code, not counted above: {:,} functions, {:.0f} KB\n".format(len(lib), lb / 1e3)
          + "game functions without a tree block: %s\n" % (", ".join(missing) or "none")
          + "farm spend (ledger, retired farm): $%.2f" % spent)
    if "--readme" in sys.argv:
        p = os.path.join(ROOT, "README.md")
        s = open(p).read()
        s = re.sub(r"<!-- status -->.*?<!-- /status -->", "<!-- status -->\n" + table + "<!-- /status -->", s, flags=re.S)
        open(p, "w").write(s)
        import progress_map
        progress_map.main([os.path.join(ROOT, "docs/progress-map.svg")], kinds=kinds)
        csv = os.path.join(ROOT, "docs/game-functions.csv")    # read by tech_debt.py, reach.py, progress_map --functions
        dirty = subprocess.run(["git", "diff", "--quiet", "--", csv], cwd=ROOT).returncode != 0
        if dirty:
            print("docs/game-functions.csv has uncommitted changes: not rewritten")
        else:
            progress_map.main(["--write-functions", csv])


if __name__ == "__main__":
    main()
