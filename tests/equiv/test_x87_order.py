#!/usr/bin/env python3
"""Regression cases for tools/x87_order.py (the x87 operation-order check, cl7).

  build/venv/bin/python tests/equiv/test_x87_order.py [--only NAME]

Cases are sources in tests/equiv/x87_order_cases/ (named 0xADDR_what.cpp) with the status the checker must give:
  - the pre-fix versions of 0x22c2b0 (Mat::Transform: the original sums v1*m4 + v2*m8, then v0*m0, then m12) and
    0x22d180 (normalize: the original sums x*x + y*y, then z*z) must be flagged `assoc`, and flagged only for
    native clang (MSVC reassociates both back to the original's order);
  - the fixed versions (the sources at the commit after 8cd650db8) must be clean.
Plus unit cases on the tree comparison (assoc / recip / round / commutativity), which need no game files.
Skips the source cases when the game files are absent.
"""
import argparse
import os
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
CASES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "x87_order_cases")

# name: (expected overall status, expected kinds of the findings, expected class of the findings or None)
CASES = {
    "0x0022c2b0_prefix_assoc": ("finding", {"assoc"}, "native_only"),
    "0x0022d180_prefix_sum_order": ("finding", {"assoc"}, "native_only"),
    "0x0022c2b0_fixed_clean": ("clean", set(), None),
    "0x0022d180_fixed_clean": ("clean", set(), None),
}


def unit():
    import x87_order as xo
    ld = lambda k: ("ld", 1, xo.I(0x10 * k), 4)       # noqa: E731
    a, b, c, d = ld(1), ld(2), ld(3), ld(4)
    mk = xo.mk
    root = lambda n: [("store", n, 0)]                # noqa: E731

    def status(o, s):
        return xo.compare_roots(root(o), root(s))[0][0]

    out = {}
    out["unit_commutative_clean"] = status(mk("add", a, b), mk("add", b, a)) == "clean"
    out["unit_commutative_nested_clean"] = status(mk("mul", mk("add", a, b), c), mk("mul", c, mk("add", b, a))) == "clean"
    out["unit_assoc_add"] = status(mk("add", mk("add", a, b), c), mk("add", a, mk("add", b, c))) == "assoc"
    out["unit_assoc_deep"] = status(mk("add", mk("add", mk("add", a, b), c), d),
                                    mk("add", mk("add", a, b), mk("add", c, d))) == "assoc"
    out["unit_assoc_mul"] = status(mk("mul", mk("mul", a, b), c), mk("mul", a, mk("mul", b, c))) == "assoc"
    one = ("c", 1, 1.0)
    out["unit_recip"] = status(mk("div", a, b), mk("mul", a, mk("div", one, b))) == "recip"
    out["unit_round"] = status(mk("add", a, mk("mul", b, c)), mk("add", a, xo.rnd(mk("mul", b, c)))) == "round"
    out["unit_top_rnd_clean"] = status(mk("add", a, b), xo.rnd(mk("add", a, b))) == "clean"
    out["unit_sub_not_commutative"] = status(mk("sub", a, b), mk("sub", b, a)) != "clean"
    out["unit_other_shape"] = status(mk("sub", mk("mul", a, b), c), mk("mul", mk("sub", a, c), b)) == "other"
    out["unit_different_ops_unmatched"] = status(mk("add", a, b), mk("mul", a, b)) == "unmatched"
    out["unit_neg_const_is_sub"] = status(mk("sub", a, ("c", 1, 1.0)), mk("add", a, ("c", 1, -1.0))) == "clean"
    out["unit_neg_through_div"] = status(mk("neg", mk("div", a, b)), mk("div", mk("neg", a), b)) == "clean"
    out["unit_phi_nested_order"] = status(mk("phi", a, mk("phi", b, c)), mk("phi", mk("phi", c, a), b)) == "clean"
    out["unit_unmatched_leaves"] = status(mk("add", a, b), mk("add", a, c)) == "unmatched"
    return out


def run(name):
    import x87_order as xo
    exp, kinds, cls = CASES[name]
    path = os.path.join(CASES_DIR, name + ".cpp")
    r = xo.analyze(path, xo.addr_of(path))
    got_kinds = {f["kind"] for f in r.get("findings", [])}
    got_cls = {f["class"] for f in r.get("findings", [])}
    ok = r["status"] == exp and got_kinds == kinds and (cls is None or got_cls == {cls})
    return ok, "%s kinds=%s classes=%s" % (r["status"], sorted(got_kinds), sorted(got_cls))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only")
    a = ap.parse_args()
    bad = 0
    for k, ok in unit().items():
        if a.only and a.only not in k:
            continue
        print("%-5s %s" % ("ok" if ok else "FAIL", k))
        bad += not ok
    if os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")):
        for name in CASES:
            if a.only and a.only not in name:
                continue
            ok, msg = run(name)
            print("%-5s %s: %s" % ("ok" if ok else "FAIL", name, msg))
            bad += not ok
    else:
        print("skip  source cases (no isos/extracted/default.xbe)")
    print("%d failure(s)" % bad)
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
