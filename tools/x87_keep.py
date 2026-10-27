#!/usr/bin/env python3
"""x87_keep.py [--snap DIR] [--bindings FILE] [--out FILE] [--jobs N]: the functions the SSE Wine build keeps as x87 code.

The probe computes this list itself (tools/clang_probe.py main(), after the snapshot: compute_x87_keep; written to
build/clang-probe/x87_keep.txt); this prints or writes it on its own, e.g. to inspect a change. See compute_x87_keep and
docs/wine-float.md section 13: the callers of the 80-bit math shims (sin, cos, tan, atan, atan2, exp, asin, acos, log,
log10, pow) and, to a fixpoint, the users of the floating-point result of a call to such a function. Callees are matched
by address through wine_link's binding map (build/native/bindings.json, `wine_link.py --no-inventory --no-link` makes it
without clang objects).
"""
import argparse
import os
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import clang_probe as cp  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--snap", default=cp.SNAP)
    ap.add_argument("--bindings", default=os.path.join(os.environ.get("HULK_WINE_DIR") or os.path.join(ROOT, "build/native"),
                                                       "bindings.json"))
    ap.add_argument("--out", help="write the list here (default: print it)")
    ap.add_argument("--jobs", type=int, default=4)
    a = ap.parse_args()
    cp.SNAP = a.snap
    keep, nfn, mapped, _ = cp.compute_x87_keep(a.jobs, cp.tool("clang++"), a.bindings)
    text = "".join(k + "\n" for k in keep)
    if a.out:
        with open(a.out, "w") as f:
            f.write(text)
    else:
        sys.stdout.write(text)
    print("%d of %d functions stay x87 (%s)" % (len(keep), nfn, "callees by the binding map" if mapped else
                                                 "no binding map: callees by FUN_ name"), file=sys.stderr)


if __name__ == "__main__":
    main()
