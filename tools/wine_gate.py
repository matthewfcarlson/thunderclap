#!/usr/bin/env python3
"""The Wine-build gate of a promotion into equivalent/ (docs/equivalence.md "Promotion").

  build/venv/bin/python tools/wine_gate.py SRC.cpp 0xADDR [--inputs 600] [--json]     # exit 0: passes the gate

A source goes into equivalent/ (or replaces one there) only when tools/equiv.py passes it in MSVC mode at 3,000 inputs
(promotable) and in Wine mode (`--wine`: the clang object the Wine build runs) at WINE_INPUTS (600) inputs: status
"equivalent" with at least 50 completed inputs. MSVC mode alone passed sources whose call declarations or float
order the Wine build gets wrong (docs/equivalence.md, rounds 22 and 23). Every installer calls gate():
build/agent-tools/promote-remote.sh (through tools/promote_dispatch.py), tools/clone_equivalent.py, tools/wine_fix.py
and the farm (farm/src/farm.ts, through this CLI).

Escape hatch, for a host without the Wine toolchain (LLVM clang): `--no-wine-gate` on those tools, or
HULK_NO_WINE_GATE=1 in the environment; gate() then passes everything and says so in its reason.
"""
import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

WINE_INPUTS = 600
MIN_RUN = 50


def disabled():
    return os.environ.get("HULK_NO_WINE_GATE", "") not in ("", "0")


def judge(rep):
    """(ok, reason) of an equiv.py --wine report."""
    if rep is None:
        return False, "wine: no result"
    st = rep.get("status")
    if st == "compile_error" and "clang" in (rep.get("error") or "") and "needs" in (rep.get("error") or ""):
        return False, "wine: toolchain unavailable (%s); --no-wine-gate to promote without it" % rep["error"][:120]
    if st != "equivalent":
        why = rep.get("error") or ""
        if not why:
            mm = (rep.get("level3") or {}).get("mismatches") or []
            why = mm[0]["diffs"][0] if mm and mm[0].get("diffs") else ""
        if not why and rep.get("level2", {}).get("issues"):
            i = rep["level2"]["issues"][0]
            why = "level 2: %s %s" % (i.get("kind"), i.get("symbol") or i.get("target") or "")
        return False, ("wine: %s %s" % (st, why)).strip()[:300]
    n = (rep.get("level3") or {}).get("inputs_run") or 0
    if n < MIN_RUN:
        return False, "wine: only %d inputs completed (%d needed)" % (n, MIN_RUN)
    return True, "wine: equivalent at %d inputs" % n


def gate(src, addr, inputs=WINE_INPUTS, time_budget=None, rep=None):
    """{'ok', 'reason', 'status', 'inputs_run'} for SRC at ADDR (an int). REP: an equiv.py --wine report already run."""
    if disabled():
        return {"ok": True, "reason": "wine gate off (HULK_NO_WINE_GATE / --no-wine-gate)", "status": None, "inputs_run": 0}
    if rep is None:
        import equiv
        kw = {"time_budget": time_budget} if time_budget else {}
        try:
            rep = equiv.verify(src, addr, n_inputs=inputs, max_inputs=inputs, native=True, **kw)
        except Exception as e:     # noqa: BLE001
            rep = {"status": "error", "error": str(e)[:200]}
    ok, why = judge(rep)
    return {"ok": ok, "reason": why, "status": rep.get("status"),
            "inputs_run": (rep.get("level3") or {}).get("inputs_run") or 0}


def main(argv):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("src")
    p.add_argument("addr")
    p.add_argument("--inputs", type=int, default=WINE_INPUTS)
    p.add_argument("--time-budget", type=float)
    p.add_argument("--no-wine-gate", action="store_true", help="pass without running (no Wine toolchain here)")
    p.add_argument("--json", action="store_true")
    a = p.parse_args(argv)
    if a.no_wine_gate:
        os.environ["HULK_NO_WINE_GATE"] = "1"
    r = gate(a.src, int(a.addr, 16), a.inputs, a.time_budget)
    print(json.dumps(r) if a.json else ("PASS " if r["ok"] else "REJECT ") + r["reason"])
    return 0 if r["ok"] else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
