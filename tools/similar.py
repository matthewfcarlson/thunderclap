#!/usr/bin/env python3
"""Find already-matched functions whose code resembles a target (for few-shot examples in packets).

  tools/similar.py 0x0009dcb0 [k]     # print the top-k similar matched functions

Similarity = overlap coefficient over instruction 3-grams (shared / smaller set, at least 4 shared). Instructions are normalized to the mnemonic plus
operand *kinds*: registers kept, immediates/displacements bucketed, image addresses dropped. Code
that does the same thing on different fields or globals still lines up.
"""
import csv
import os
import pickle
import re
import sys
from collections import Counter, defaultdict

import capstone

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
MATCHES = os.path.join(ROOT, "matches")
CACHE = os.path.join(ROOT, "build", "farm", "simindex.pkl")

_md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
_md.syntax = capstone.CS_OPT_SYNTAX_INTEL


def _norm(insn):
    if insn.mnemonic == "call" or insn.mnemonic.startswith("j"):
        return insn.mnemonic
    ops = re.sub(r"0x[0-9a-f]{5,}", "A", insn.op_str)           # image addresses
    ops = re.sub(r"0x[0-9a-f]+|\b\d+\b", "N", ops)               # small constants / offsets
    return insn.mnemonic + " " + ops


def tokens(xbe, va, size):
    o = xbe.offset(va)
    return [_norm(i) for i in _md.disasm(xbe.data[o:o + size], va)]


def grams(toks, n=3):
    return {tuple(toks[i:i + n]) for i in range(max(len(toks) - n + 1, 1))}


class Index:
    def __init__(self):
        xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
        self.sizes = {}
        with open(os.path.join(ROOT, "build/functions.csv")) as f:
            for r in csv.DictReader(f):
                self.sizes["0x%08x" % int(r["address"], 16)] = int(r["size"])
        self.xbe = xbe
        self.grams = {}
        self.postings = defaultdict(list)
        self.direct = set()
        for name in os.listdir(MATCHES):
            a = name[:-4]
            if a not in self.sizes:
                continue
            path = os.path.join(MATCHES, name)
            with open(path) as f:
                propagated = f.readline().startswith("// Same code shape")
            if not propagated:
                self.direct.add(a)
            g = grams(tokens(xbe, int(a, 16), self.sizes[a]))
            self.grams[a] = g
            for t in g:
                self.postings[t].append(a)
        self.n_matches = len(os.listdir(MATCHES))

    @classmethod
    def load(cls):
        n = len(os.listdir(MATCHES))
        if os.path.exists(CACHE):
            with open(CACHE, "rb") as f:
                idx = pickle.load(f)
            if idx.n_matches == n:
                idx.xbe = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
                return idx
        idx = cls()
        xbe, idx.xbe = idx.xbe, None
        with open(CACHE, "wb") as f:
            pickle.dump(idx, f)
        idx.xbe = xbe
        return idx

    def similar(self, addr, k=3, min_score=0.5):
        g = grams(tokens(self.xbe, int(addr, 16), self.sizes[addr]))
        shared = Counter()
        for t in g:
            # Very common grams (prologues, ret) carry little signal and cost a lot; skip them.
            p = self.postings.get(t, ())
            if len(p) < 2000:
                shared.update(p)
        scored = []
        for a, c in shared.most_common(300):
            if a == addr or c < 4:
                continue
            # Overlap coefficient: a small matched helper fully contained in a big target scores high.
            j = c / min(len(g), len(self.grams[a]))
            # Prefer direct (model-written) matches over propagated copies of the same source.
            scored.append((j + (0.02 if a in self.direct else 0), a, j))
        scored.sort(reverse=True)
        out, seen_src = [], set()
        for _, a, j in scored:
            if j < min_score:
                break
            src = open(os.path.join(MATCHES, a + ".cpp")).read()
            body = src.split("\n", 1)[1] if src.startswith("// Same code shape") else src
            if body in seen_src:  # several addresses can share one TU
                continue
            seen_src.add(body)
            out.append((a, round(j, 2), self.sizes[a], body))
            if len(out) == k:
                break
        return out


def main():
    addr = "0x%08x" % int(sys.argv[1], 16)
    k = int(sys.argv[2]) if len(sys.argv) > 2 else 3
    for a, j, size, body in Index.load().similar(addr, k):
        print("== %s  similarity %.2f  (%d bytes)\n%s" % (a, j, size, body[:1500]))


if __name__ == "__main__":
    main()
