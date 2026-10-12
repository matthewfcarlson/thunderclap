#!/usr/bin/env python3
"""Regression cases for tools/equiv.py: sources that a checker bug once got wrong.

  build/venv/bin/python tests/equiv/regress.py [--jobs 4] [--only NAME]

Each case is a source in tests/equiv/cases/ (named 0xADDR_what.cpp) with the status it must get, a
piece of the mismatch text that shows the right thing was caught, and for some a minimum branch coverage.
Skips when the game files are absent.
"""
import argparse
import os
import sys
from multiprocessing import Pool

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
CASES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "cases")

# name: (expected status, text one of the mismatches must contain or None[, minimum branch coverage])
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
    # varargs: the words beyond an equiv-conv's slots are compared, and the arity is per call site
    "0x00220310_vararg_extra": ("fail", "argument 6 is"),
    "0x001cd220_vararg": ("equivalent", None),
    "0x001cd220_vararg_dropped": ("fail", "4 argument words, expected 5"),
    # a `...` declaration used to pass register arguments (equiv-conv eax ecx): no extra words compared
    "0x00218170_varargs_conv": ("equivalent", None),
    # pushes left for a later call: `push 1; call <jmp [vtable] thunk>; push eax; ...; call f(ret 12)`
    "0x000b63a0_pending_thunk": ("equivalent", None),
    # a caller-cleaned virtual call whose words are reused as arguments of the next call
    "0x0013d7b0_shared_pushes": ("equivalent", None),
    "0x0004c7c0_pending_vcall": ("equivalent", None),
    "0x002fb440_hoisted_push": ("equivalent", None),
    # a stdcall import (NtClose) after a self-recursive call: the import's pop isn't guessed from later code
    "0x00212641_import_pop": ("equivalent", None),
    # a callee that never returns (luaD_throw -> longjmp): both runs stop there
    "0x00215790_noreturn": ("equivalent", None),
    # switch cases reached through the selector's source (a stub's result, `add eax, -2; cmp eax, 9`), never
    # by patching the byte table in .text; both sources map cases to the wrong fields
    "0x001b0310_switch_cases": ("fail", "returned"),
    "0x00321ea0_switch_cases": ("fail", "returned"),
    # &self stored as a member function pointer: our symbol is the original's address
    "0x000e7930_self_address": ("equivalent", None),
    # a loop's induction base at another field of the same global (level 2)
    "0x001b3c50_induction_base": ("equivalent", None),
    # a typed struct out-parameter
    "0x0021d630_typed_outparam": ("equivalent", None),
    # coverage: loops over begin/end pairs and magic-number divisions (loop repair), a type switch done with
    # dec/sub, float compares, a printf format parser (bytes kept in a local, a byte-table switch)
    "0x002ff3f0_loop_bounds": ("equivalent", None, 0.75),
    "0x00096b50_arith_compare": ("equivalent", None, 0.75),
    "0x000fbc00_format_parser": ("equivalent", None, 0.75),
    # false failures found re-checking equivalent/: a big frame's `add esp` is no argument cleanup; a virtual
    # call's words reused by a later call through another caller-cleaned virtual; `this + 0xb4 != 0`
    # (a base-class null check) is not a test to steer; a /GS cookie load inside the prologue; strings
    # reached through a table in .rdata can be patched (the table's own pointer is a fixed address)
    "0x0008c680_frame_release": ("equivalent", None),
    "0x000991b0_chained_vcalls": ("equivalent", None),
    "0x0003a680_base_null_check": ("equivalent", None),
    "0x0008e880_cookie_prologue": ("equivalent", None),
    "0x000d3f10_string_table": ("equivalent", None, 0.75),
}


def job(name):
    equiv = __import__(os.environ.get("EQUIV_MODULE", "equiv"))
    addr = int(name.split("_")[0], 16)
    r = equiv.verify(os.path.join(CASES_DIR, name + ".cpp"), addr)
    diffs = [d for m in (r.get("level3") or {}).get("mismatches", []) for d in m["diffs"]]
    cov = (r.get("level3") or {}).get("coverage") or {}
    ratio = cov["edges_covered"] / cov["edges_total"] if cov.get("edges_total") else 1.0
    return name, r["status"], diffs, ratio


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
        for name, status, diffs, ratio in pool.imap_unordered(job, names):
            want, text = CASES[name][:2]
            min_cov = CASES[name][2] if len(CASES[name]) > 2 else 0
            ok = status == want and (text is None or any(text in d for d in diffs)) and ratio >= min_cov
            bad += not ok
            print("%-4s %-32s %-12s %3.0f%% %s" % ("ok" if ok else "FAIL", name, status, 100 * ratio,
                                                 "" if ok else (diffs[:2] or "")))
    print("%d/%d cases ok" % (len(names) - bad, len(names)))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
