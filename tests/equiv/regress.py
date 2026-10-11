#!/usr/bin/env python3
"""Regression cases for tools/equiv.py: sources that a checker bug once got wrong.

  build/venv/bin/python tests/equiv/regress.py [--jobs 4] [--only NAME]

Each case is a source in tests/equiv/cases/ (named 0xADDR_what.cpp) with the status it must get and a
piece of the mismatch text that shows the right thing was caught. Skips when the game files are absent.
"""
import argparse
import os
import sys
from multiprocessing import Pool

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
CASES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "cases")

# name: (expected status, text one of the mismatches must contain, or None)
CASES = {
    # a stack local smaller than what the (stubbed) callee writes through the pointer
    "0x00241390_small_local": ("fail", "writes 0x40 bytes through ecx"),
    "0x00324e00_small_local": ("fail", "writes 0x8 bytes through argument 1"),
    # declared void, reached through a vtable, but the original returns the allocation in eax
    "0x0026ce10_void_eax": ("fail", "in eax"),
    # __security_check_cookie is __fastcall (cookie in ecx), not __cdecl
    "0x000bb600_cookie_cdecl": ("fail", "__security_check_cookie"),
    # a struct passed by value (0x2b8 bytes): the stub pops more than a trampoline's `ret N` covers
    "0x000bb600_big_pop": ("equivalent", None),
    # a wrong texcoord index far into a 192-byte vertex array passed as `const void*`
    "0x00323130_array_tail": ("fail", "the local passed as argument 3 differs"),
    # a callee with a plain ret (caller pops) declared as an ordinary thiscall member
    "0x00329f70_caller_pops": ("fail", "really pops 0"),
    # a WAVEFORMAT reached through a pointer inside the descriptor passed to the callee
    "0x00259610_nested_local": ("fail", "points to"),
    # equiv-conv on tail jumps
    "0x0026b500_conv_tail": ("equivalent", None),
    # a stub must not clobber registers the callee preserves
    "0x0026f990_preserved_regs": ("equivalent", None),
    # self-recursion: stubbed on both sides
    "0x001ec480_recursion": ("equivalent", None),
    # an LTCG register argument (esi) pushed on as a call argument is not a register save: the source drops
    # the third argument of FUN_002d7440
    "0x002ad9d0_dropped_arg": ("fail", "2 argument words, expected 3"),
    # an out-parameter compared by the original's branch (directed inputs fill it in); the source's
    # token test is inverted
    "0x0008ed60_outparam_directed": ("fail", "argument 1 is"),
}


def job(name):
    equiv = __import__(os.environ.get("EQUIV_MODULE", "equiv"))
    addr = int(name.split("_")[0], 16)
    r = equiv.verify(os.path.join(CASES_DIR, name + ".cpp"), addr)
    diffs = [d for m in (r.get("level3") or {}).get("mismatches", []) for d in m["diffs"]]
    return name, r["status"], diffs


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--jobs", type=int, default=4)
    p.add_argument("--only")
    a = p.parse_args()
    if not os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")):
        print("skip: no isos/extracted/default.xbe")
        return 0
    names = [n for n in CASES if not a.only or a.only in n]
    bad = 0
    with Pool(a.jobs) as pool:
        for name, status, diffs in pool.imap_unordered(job, names):
            want, text = CASES[name]
            ok = status == want and (text is None or any(text in d for d in diffs))
            bad += not ok
            print("%-4s %-32s %-11s %s" % ("ok" if ok else "FAIL", name, status, "" if ok else (diffs[:2] or "")))
    print("%d/%d cases ok" % (len(names) - bad, len(names)))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
