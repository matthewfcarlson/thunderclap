#!/usr/bin/env python3
"""Byte-weighted match status. --readme rewrites the status table between <!-- status --> markers."""
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(__file__))
from packet import Db

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


def main():
    db = Db()
    game = [r for r in db.funcs.values() if db.is_game(r)]
    total = sum(int(r["size"]) for r in game)
    matched = [r for r in game if os.path.exists(os.path.join(ROOT, "matches", "0x%08x.cpp" % int(r["address"], 16)))]
    mb = sum(int(r["size"]) for r in matched)
    # Behaviour-verified (tools/equiv.py level 3) but not byte-matched; a later match supersedes it.
    has = lambda d, r: os.path.exists(os.path.join(ROOT, d, "0x%08x.cpp" % int(r["address"], 16)))
    equiv = [r for r in game if has("equivalent", r) and not has("matches", r)]
    eb = sum(int(r["size"]) for r in equiv)
    spent = 0.0
    for p in [os.path.join(ROOT, "build/farm/results.jsonl")]:
        if os.path.exists(p):
            spent += sum(json.loads(l).get("cost", 0) for l in open(p) if l.strip())
    table = (
        "| | Functions | Bytes |\n|---|---|---|\n"
        "| Game code (`.text`, excluding XDK/CRT/Bink) | {:,} | {:.2f} MB |\n"
        "| Byte-matched (`matches/`) | {:,} ({:.1f}%) | {:.0f} KB ({:.1f}%) |\n"
        "| Proven equivalent (`equivalent/`) | {:,} ({:.1f}%) | {:.0f} KB ({:.1f}%) |\n"
        "| **Verified source, total** | {:,} ({:.1f}%) | {:.0f} KB (**{:.1f}%**) |\n"
    ).format(len(game), total / 1e6, len(matched), 100 * len(matched) / len(game), mb / 1e3, 100 * mb / total,
             len(equiv), 100 * len(equiv) / len(game), eb / 1e3, 100 * eb / total,
             len(matched) + len(equiv), 100 * (len(matched) + len(equiv)) / len(game), (mb + eb) / 1e3, 100 * (mb + eb) / total)
    print(table + "farm spend (ledger): $%.2f" % spent)
    if "--readme" in sys.argv:
        p = os.path.join(ROOT, "README.md")
        s = open(p).read()
        s = re.sub(r"<!-- status -->.*?<!-- /status -->", "<!-- status -->\n" + table + "<!-- /status -->", s, flags=re.S)
        open(p, "w").write(s)
        import progress_map  # the README's treemap, docs/progress-map.svg
        progress_map.main()


if __name__ == "__main__":
    main()
