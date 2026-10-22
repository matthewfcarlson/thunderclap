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
    # equiv-conv: the original takes parameters in registers, the source on the stack; the roots must still pair
    "0x000cb7d0_conv_clean": ("clean", set(), None, 4),
    # pointer differences (a4 + (a8 - a4) = a8), spilled float masks, a call result left on the x87 stack
    "0x00313940_pointer_diff_clean": ("round_only", {"round"}, None, 60),
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
    na = mk("neg", a)
    out["unit_neg_pair_clean"] = status(mk("add", na, mk("neg", b)), mk("sub", na, b)) == "clean"
    out["unit_neg_sub_not_clean"] = status(mk("sub", na, b), mk("sub", a, b)) != "clean"
    out["unit_neg_of_sub_swaps"] = status(mk("neg", mk("sub", a, b)), mk("sub", b, a)) == "clean"
    out["unit_mul_minus_one_is_neg"] = status(mk("mul", a, ("c", 1, -1.0)), mk("neg", a)) == "clean"
    out["unit_mul_by_two_not_neg"] = status(mk("mul", a, ("c", 1, 2.0)), mk("neg", a)) != "clean"
    A, B = xo.atom(("m", xo.I(0x10), 4)), xo.atom(("m", xo.I(0x20), 4))
    out["unit_ptr_diff_cancels"] = xo.iadd(A, xo.isub(B, A)) == B
    out["unit_ptr_diff_keeps_other"] = xo.iadd(A, xo.isub(B, B)) == A and xo.iadd(A, xo.isub(B, A)) != A
    out["unit_phi_joined_elsewhere"] = status(mk("mul", mk("phi", a, b), c),
                                              mk("phi", mk("mul", a, c), mk("mul", b, c))) == "clean"
    out["unit_phi_joined_elsewhere_neg"] = status(mk("mul", mk("phi", a, b), c),
                                                  mk("phi", mk("mul", a, c), mk("add", b, c))) != "clean"
    out["unit_unmatched_leaves"] = status(mk("add", a, b), mk("add", a, c)) == "unmatched"
    return out


SYNTH_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "x87_order_synth")


def synth(name):
    """Synthetic cases: a C file with `ref` (plays the original) and `test`; `// expect: clean=3 unmatched>=1`."""
    import re
    import x87_order as xo
    path = os.path.join(SYNTH_DIR, name)
    text = open(path).read()
    exp = re.search(r"//\s*expect:\s*(.*)", text).group(1).split()
    msvc = "ref-msvc" in text
    res, _ = xo.synth_compare(path, ref_msvc=msvc)
    got = {}
    for st, *_ in res:
        got[st] = got.get(st, 0) + 1
    ok = True
    for e in exp:
        m = re.match(r"(\w+)(>=|=)(\d+)$", e)
        k, op, v = m.group(1), m.group(2), int(m.group(3))
        ok &= (got.get(k, 0) >= v) if op == ">=" else (got.get(k, 0) == v)
    for k in got:      # a status the case does not mention must not appear
        ok &= any(e.startswith(k) for e in exp)
    return ok, str(got)


def run(name):
    import x87_order as xo
    exp, kinds, cls, *rest = CASES[name]
    min_clean = rest[0] if rest else 0
    path = os.path.join(CASES_DIR, name + ".cpp")
    r = xo.analyze(path, xo.addr_of(path))
    got_kinds = {f["kind"] for f in r.get("findings", [])}
    got_cls = {f["class"] for f in r.get("findings", [])}
    nclean = r.get("stats", {}).get("clean", 0)
    ok = r["status"] == exp and got_kinds == kinds and (cls is None or got_cls == {cls}) and nclean >= min_clean
    return ok, "%s kinds=%s classes=%s clean_roots=%d" % (r["status"], sorted(got_kinds), sorted(got_cls), nclean)


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
    import compare
    for f in sorted(os.listdir(SYNTH_DIR)):
        if f.endswith(".cpp") and (not a.only or a.only in f):
            try:
                ok, msg = synth(f)
            except compare.CompileError as e:
                ok, msg = False, str(e)[:200]
            print("%-5s synth/%s: %s" % ("ok" if ok else "FAIL", f, msg))
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
