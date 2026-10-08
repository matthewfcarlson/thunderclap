#!/usr/bin/env python3
"""Disassemble functions from the XBE using build/functions.csv for bounds.

Usage: tools/disasm.py 0x13950 [0x14900 ...]
       tools/disasm.py 'CAction::vfunc_5'
"""
import csv
import os
import sys

import capstone

sys.path.insert(0, os.path.dirname(__file__))
from xbe import Xbe

ROOT = os.path.join(os.path.dirname(__file__), "..")
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
FUNCS_PATH = os.path.join(ROOT, "build/functions.csv")


def load_functions():
    funcs = {}
    with open(FUNCS_PATH) as f:
        for r in csv.DictReader(f):
            funcs[int(r["address"], 16)] = (int(r["size"]), r["name"])
    return funcs


def function_bytes(xbe, va, size):
    o = xbe.offset(va)
    return xbe.data[o:o + size]


def main(args):
    xbe = Xbe(XBE_PATH)
    funcs = load_functions()
    by_name = {name: va for va, (_, name) in funcs.items()}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.syntax = capstone.CS_OPT_SYNTAX_INTEL
    for a in args:
        va = int(a, 16) if a.startswith("0x") else by_name[a]
        size, name = funcs[va]
        print("; %s @ %#x (%d bytes)" % (name, va, size))
        for insn in md.disasm(function_bytes(xbe, va, size), va):
            print("  %08x  %-24s %s %s" % (insn.address, insn.bytes.hex(), insn.mnemonic, insn.op_str))
        print()


if __name__ == "__main__":
    main(sys.argv[1:])
