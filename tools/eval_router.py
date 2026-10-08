#!/usr/bin/env python3
"""How well do difficulty signals predict whether a model matched? AUC per signal.

  tools/eval_router.py build/farm/bench/openai_gpt-6-luna.jsonl [more ledgers...]
Signals: Jev difficulty score / match probability (build/farm/difficulty.jsonl), function size,
call count, and a static asm-complexity score.
"""
import csv
import json
import os
import sys

import capstone

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))


def auc(pairs):
    """pairs: (score, label) with higher score = predicted harder; label 1 = failed. Ties count half."""
    pos = [s for s, y in pairs if y]
    neg = [s for s, y in pairs if not y]
    if not pos or not neg:
        return float("nan")
    wins = sum((p > n) + 0.5 * (p == n) for p in pos for n in neg)
    return wins / (len(pos) * len(neg))


def static_complexity(xbe, md, va, size):
    o = xbe.offset(va)
    branches = calls = floats = 0
    for i in md.disasm(xbe.data[o:o + size], va):
        if i.mnemonic.startswith("j"):
            branches += 1
        elif i.mnemonic == "call":
            calls += 1
        elif i.mnemonic.startswith("f"):
            floats += 1
    return branches * 3 + calls * 2 + floats + size / 16


def main(ledgers):
    funcs = {int(r["address"], 16): r for r in csv.DictReader(open(os.path.join(ROOT, "build/functions.csv")))}
    jev = {}
    for l in open(os.path.join(ROOT, "build/farm/difficulty.jsonl")):
        r = json.loads(l)
        jev[r["addr"]] = r["answers"]
    outcome = {}
    for p in ledgers:
        for l in open(p):
            r = json.loads(l)
            outcome[r["addr"]] = r["status"] != "match"
    xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    rows = [a for a in outcome if a in jev]
    signals = {
        "jev difficulty": lambda a: jev[a]["difficulty"]["score"],
        "jev 1-P(match)": lambda a: 1 - jev[a]["cheap_model_matches"]["probability"],
        "size": lambda a: int(funcs[int(a, 16)]["size"]),
        "calls": lambda a: int(funcs[int(a, 16)]["calls"]),
        "static asm score": lambda a: static_complexity(xbe, md, int(a, 16), int(funcs[int(a, 16)]["size"])),
    }
    fails = sum(outcome[a] for a in rows)
    print("labeled functions: %d (%d failed, %d matched)" % (len(rows), fails, len(rows) - fails))
    print("AUC for predicting failure (0.5 = coin flip, 1.0 = perfect):")
    for name, f in signals.items():
        print("  %-18s %.2f" % (name, auc([(f(a), outcome[a]) for a in rows])))


if __name__ == "__main__":
    main(sys.argv[1:])
