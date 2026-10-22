#!/usr/bin/env python3
"""Regression cases for tools/equiv_replay.py: sources that a replay artifact once got wrong, replayed against the
local capture sessions (build/traces/SESSION/trace.sqlite, never committed; a case whose session is missing is
skipped).

  build/venv/bin/python tests/equiv/replay_regress.py [--jobs 2] [--only NAME]
  EQUIV_REPLAY_MODULE=build/agent-tools/equiv_replay_r11.py EQUIV_MODULE=equiv_r11 tests/equiv/replay_regress.py

Each case is a source in tests/equiv/replay_cases/ (named 0xADDR_what.cpp), the session it is replayed on, the
status it must get (agreed / mismatch / no_replay) and a piece of text the first mismatch (or, for no_replay and
agreed, an incomplete reason) must contain, or None.
"""
import argparse
import importlib.util
import os
import sys
from multiprocessing import get_context

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
CASES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "replay_cases")

# name: (session, expected status, text or None[, minimum calls agreed])
CASES = {
    # x87-argument callee (`fld x; call __CIasin`): the stub returns through TRAMP+0xC00, which took a fuzz float
    # instead of the recorded asin result (fx12)
    "0x0033b6d0_x87_arg": ("g-play2", "agreed", None, 1),
    # the source that dropped luaL_checknumber's result and passed garbage on the x87 stack
    "0x0033b6d0_x87_arg_wrong": ("g-play2", "mismatch", "x87 argument"),
    # a delta keyed to eax = (&R & 0xffff0000) | fpsw after `fnstsw ax` (upper half of a pushed stack address,
    # 0xd004 vs 0x7eff) landed on our saved edi (fx12 0x00122520's pre-fix source)
    "0x00122520_fnstsw_key": ("g-play2", "agreed", None, 1),
    # the same through eax with its low byte replaced by `mov al, [edx+0x24]` (fx12 0x00017a80, pre-fix)
    "0x00017a80_al_key": ("g-play2", "agreed", None, 1),
    # the same on ebx's slot (fx12 0x000202f0, pre-fix: call 7 of p4-1)
    "0x000202f0_fnstsw_key": ("p4-1", "agreed", None, 10),
    # a 3-byte delta that left the top byte of a stale return address alone (0x60.. in ours): fx12's 0x001f9710
    "0x001f9710_partial_word": ("g-play2", "agreed", None, 2),
    # interrupt-frame bytes in the original's alignment pad, recorded in the callee's run: ours had no pad
    # (fx12 0x000c7c60, pre-fix): inconclusive, not a mismatch
    "0x000c7c60_pad_garbage": ("g-try3", "no_replay", "below the stack pointer"),
    # an 8-byte id written by a virtual callee into a 4-byte local (fx12 0x002a4b00, pre-fix): a real
    # difference, not garbage (the local was above the stack pointer since the previous call)
    "0x002a4b00_real_overflow_wrong": ("par0", "mismatch", "writes 0x8 bytes through argument 2"),
    # ours keeps the callee's out-parameters in dead argument slots (fx12 0x000f6530, pre-fix)
    "0x000f6530_dead_arg_slot": ("p4-1", "agreed", None, 5),
    # adjacent out-parameters written by one callee, one run keyed to &c that runs on over the original's
    # uninitialised name buffer (fx11 0x00080820, pre-fix): the calls where ours's cookie took those bytes are
    # inconclusive, the others agree
    "0x00080820_merged_garbage": ("g-try2", "agreed", "below the stack pointer", 2),
    # s1 was captured before the ST(0) fix: fx12's pre-fix source mismatched there on cosines recorded where
    # the game returned angles; those calls are now inconclusive
    "0x00042680_pre_st0_fix": ("s1", "no_replay", "ST(0) fix"),
    # a real difference in s1 that doesn't depend on x87 results is still found there (0x00241390's source when
    # it was excluded from the hybrid build: a ctor writes 0x40 bytes into a 0x20-byte local)
    "0x00241390_pre_st0_fix_wrong": ("s1", "mismatch", "writes 0x40 bytes"),
    # the original's replay ran out of the default 2M steps on most calls (fx12 0x00201850)
    "0x00201850_long_call": ("s2", "agreed", None, 2),
    # real differences that must stay mismatches: an unrounded product before a subtraction (fx11 0x00308fe0,
    # pre-fix), a sum of squares reassociated (fx12 0x00358030, pre-fix), a 16-byte vector into a 12-byte
    # local (fx11 0x002251d0, pre-fix)
    "0x00308fe0_rounding_wrong": ("s2", "mismatch", "0x0022c3b0"),
    "0x00358030_tie_wrong": ("p4-1", "mismatch", None),
    "0x002251d0_vec4_wrong": ("ringfeed2", "mismatch", None),
    # (round 21) a function with its own `// equiv-conv` is replayed (cap1, ownconv), and the callee's out-parameter written into
    # our dead argument slots is placed without the original's liveness test (its slots hold other words): 0x0021ee70.
    # _off: REPLAY_OFF=ownconvdead (the 6th element) restores the test and the call no longer agrees; _wrong still fails
    "0x0021ee70_own_conv": ("g-play2b", "agreed", None, 1),
    "0x0021ee70_own_conv_off": ("g-play2b", "mismatch", "argument 2", 0, "ownconvdead"),
    "0x0021ee70_own_conv_wrong": ("g-play2b", "mismatch", "argument 2"),
}


_ER = None


def _load():
    """The replay module, loaded once per process (it keeps module state: the entry esp it was loaded with)."""
    global _ER
    if _ER is not None:
        return _ER
    eq = os.environ.get("EQUIV_MODULE")
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    if eq:
        sys.modules["equiv"] = __import__(eq)
    path = os.environ.get("EQUIV_REPLAY_MODULE", os.path.join(ROOT, "tools/equiv_replay.py"))
    spec = importlib.util.spec_from_file_location("equiv_replay", path)
    er = importlib.util.module_from_spec(spec)
    sys.modules["equiv_replay"] = er
    spec.loader.exec_module(er)
    _ER = er
    return er


def job(name):
    er = _load()
    session = CASES[name][0]
    path = os.path.join(ROOT, "build/traces", session)
    if not os.path.exists(os.path.join(path, "trace.sqlite")):
        return name, "skip", None
    addr = int(name.split("_")[0], 16)
    off = set(CASES[name][4].split(",")) if len(CASES[name]) > 4 else set()
    off -= er.REPLAY_OFF
    er.REPLAY_OFF.update(off)       # (a case's 5th element: REPLAY_OFF switches for this case only)
    try:
        r = er.replay(os.path.join(CASES_DIR, name + ".cpp"), addr, er.TraceStore(path))
    except Exception as e:      # noqa: BLE001
        return name, "error", {"error": repr(e)[:300]}
    finally:
        er.REPLAY_OFF.difference_update(off)
    return name, r.get("status"), r


def check(name, status, r):
    want, text = CASES[name][1:3]
    min_agreed = CASES[name][3] if len(CASES[name]) > 3 else 0
    if status == "skip":
        return True, "skipped (no session)"
    if status != want or (r.get("agreed") or 0) < min_agreed:
        return False, "%s agreed=%s %s" % (status, r.get("agreed"), (r.get("mismatches") or [{}])[0].get("diffs", [])[:2]
                                           or (r.get("incomplete_reasons") or [])[:1] or r.get("error", ""))
    if text:
        hay = [d for m in r.get("mismatches") or [] for d in m["diffs"]] if want == "mismatch" else \
            [x["why"] for x in r.get("incomplete_reasons") or []]
        if not any(text in h for h in hay):
            return False, "%s, but no %r in %s" % (status, text, hay[:2])
    return True, "%s agreed=%s/%s incomplete=%s" % (status, r.get("agreed"), r.get("replayed"), r.get("incomplete"))


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--only")
    a = p.parse_args()
    if not os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")):
        print("skip: no isos/extracted/default.xbe")
        return 0
    names = [n for n in CASES if not a.only or a.only in n]
    bad = 0
    with get_context("spawn").Pool(min(a.jobs, 3)) as pool:
        for name, status, r in pool.imap_unordered(job, names):
            ok, why = check(name, status, r or {})
            bad += not ok
            print("%-4s %-34s %s" % ("ok" if ok else "FAIL", name, why), flush=True)
    print("%d/%d replay cases ok" % (len(names) - bad, len(names)))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
