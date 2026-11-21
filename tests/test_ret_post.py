#!/usr/bin/env python3
"""(integ8, D165; rev5) Return postconditions: the own-run check of the original's return (a NaN refutes), the range a
caller's stub draws in, per-mode acceptance of a callee's post (an equiv line for an equivalent block, a `post` line for a
matches block; a line of the other mode never serves), the post lines in the checker view (a post edit is another view and
never carries), and the `post` kind proving nothing in the equiv ledger. Synthetic records; no game bytes are read."""
import os
import sys
import unittest
from unittest import mock

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import equiv  # noqa: E402
import tree_tu  # noqa: E402

GE0 = [("ret", ("range", 0.0, float("inf"), True, True))]


class OwnRun(unittest.TestCase):
    def test_float_return(self):
        sig = {"ret": "f64"}
        self.assertEqual(equiv._post_ret_check(GE0, sig, {"st0": 2.5}), ("ok", 2.5))
        self.assertIn("outside", equiv._post_ret_check(GE0, sig, {"st0": -0.5}))
        self.assertIn("outside", equiv._post_ret_check(GE0, sig, {"st0": float("nan")}))     # a NaN refutes
        self.assertEqual(equiv._post_ret_check(GE0, sig, {}), "unread")

    def test_int_returns(self):
        self.assertIn("outside", equiv._post_ret_check(GE0, {"ret": "i32"}, {"eax": 0xFFFFFFFF}))
        self.assertEqual(equiv._post_ret_check(GE0, {"ret": "u32"}, {"eax": 0xFFFFFFFF}), ("ok", 0xFFFFFFFF))
        self.assertIn("outside", equiv._post_ret_check(GE0, {"ret": "i64"}, {"eax": 0, "edx": 0x80000000}))
        self.assertEqual(equiv._post_ret_check(GE0, {"ret": "ptr"}, {"eax": 1}), "unread")

    def test_parse_and_range(self):
        specs, bad = equiv._parse_post(["ge(ret, 0) lt(ret, 10)"])
        self.assertFalse(bad)
        self.assertEqual(equiv._ret_post_range(["ge(ret, 0) lt(ret, 10)"]), ("range", 0.0, 10.0, True, False))
        self.assertTrue(equiv._parse_post(["ge(ret, 0) when ret"])[1])          # (no `when` on a return item)
        self.assertIsNone(equiv._ret_post_range(["lt(*arg1, 3) when ret"]))     # (no return item: nothing to draw)


class Draw(unittest.TestCase):
    def test_repair_into_range(self):
        import struct
        cond = ("range", 0.0, float("inf"), True, True, "f")
        seen = set()
        for seed in range(200):
            nb = equiv._pre_range_fix(seed, 5, struct.pack("<d", -3.0), 8, cond, True)
            v = struct.unpack("<d", nb)[0]
            self.assertTrue(v >= 0.0)
            seen.add(v == 0.0)
        self.assertEqual(seen, {True, False})       # (the inner bound planted on some inputs, a draw on the others)
        nb = equiv._pre_range_fix(1, 5, struct.pack("<d", float("nan")), 8, cond, False)
        self.assertTrue(struct.unpack("<d", nb)[0] >= 0.0)


class Accept(unittest.TestCase):
    A = 0x00085f80

    def setUp(self):
        equiv._RET_POST_ACC.clear()

    def tearDown(self):
        equiv._RET_POST_ACC.clear()

    def _matches(self, lines, mode_of_line, post=("ge(ret, 0)",), domain=()):
        idx = {self.A: ("src/x.cpp", "matches", ["ge(ret, 0)"], [], "")}
        recs = [{"addr": "0x%08x" % self.A, "kind": "matches", "post_code_hash": "c0de"}]
        line = {"kind": "post", "addr": "0x%08x" % self.A, "mode": mode_of_line, "code": "c0de", "view": "v0",
                "post": list(post), "domain": list(domain), "status": "equivalent", "promotable": True}
        with mock.patch.object(equiv, "ret_post_blocks", return_value=idx), \
                mock.patch.object(tree_tu, "check_tu", return_value=recs), \
                mock.patch.object(tree_tu, "post_wine_hash", return_value="c0de"), \
                mock.patch.object(tree_tu, "wine_object", return_value=None), \
                mock.patch.object(tree_tu, "current_view", return_value=("v0", None, None)), \
                mock.patch.object(tree_tu, "post_lines", return_value=[line] if lines else []):
            return equiv.accept_ret_post(self.A, False)[0], (equiv._RET_POST_ACC.clear() or
                                                             equiv.accept_ret_post(self.A, True)[0])

    def test_matches_per_mode(self):
        m, w = self._matches(True, "msvc")
        self.assertIsNotNone(m)
        self.assertIsNone(w)            # (a msvc post line never serves a --wine caller)
        m, w = self._matches(True, "wine")
        self.assertIsNone(m)
        self.assertIsNotNone(w)
        self.assertEqual(self._matches(False, "msvc"), (None, None))

    def test_view_names_the_evidence_not_the_run(self):
        # (rev5) two lines of the same identity (another job and date) give the same caller view entry
        idx = {self.A: ("src/x.cpp", "matches", ["ge(ret, 0)"], [], "")}
        recs = [{"addr": "0x%08x" % self.A, "kind": "matches", "post_code_hash": "c0de"}]
        infos = []
        for job in ("1", "2"):
            equiv._RET_POST_ACC.clear()
            line = {"kind": "post", "addr": "0x%08x" % self.A, "mode": "msvc", "code": "c0de", "view": "v0",
                    "post": ["ge(ret, 0)"], "domain": [], "status": "equivalent", "promotable": True, "job": job}
            with mock.patch.object(equiv, "ret_post_blocks", return_value=idx), \
                    mock.patch.object(tree_tu, "check_tu", return_value=recs), \
                    mock.patch.object(tree_tu, "current_view", return_value=("v0", None, None)), \
                    mock.patch.object(tree_tu, "post_lines", return_value=[line]):
                infos.append(equiv.accept_ret_post(self.A, False)[1])
        self.assertEqual(infos[0], infos[1])

    def test_matches_line_must_state_the_post_and_domain_now(self):
        self.assertEqual(self._matches(True, "msvc", post=("ge(ret, 1)",)), (None, None))
        self.assertEqual(self._matches(True, "msvc", domain=("ge(arg1, 0)",)), (None, None))

    def test_equivalent_per_mode(self):
        a = "0x%08x" % self.A
        vh = tree_tu.view_digest("vm", "vw")
        idx = {self.A: ("src/x.cpp", "equivalent", ["ge(ret, 0)"], [], " @cm @wcw @v%s" % vh)}
        for led, want in (({(a, "msvc", "cm", "vm"), (a, "wine", "cw", "vw")}, (True, True)),
                          ({(a, "msvc", "cm", "vm")}, (False, False)),       # (the pin's @v needs both modes' views)
                          ({(a, "msvc", "cm", "vx"), (a, "wine", "cw", "vw")}, (False, False)),
                          ({(a, "msvc", "old", "vm"), (a, "wine", "cw", "vw")}, (False, False))):
            got = []
            for native in (False, True):
                equiv._RET_POST_ACC.clear()
                with mock.patch.object(equiv, "ret_post_blocks", return_value=idx), \
                        mock.patch.object(tree_tu, "ledger_index", return_value=led):
                    got.append(equiv.accept_ret_post(self.A, native)[0] is not None)
            self.assertEqual(tuple(got), want, led)


class ShardMerge(unittest.TestCase):
    def test_distinct_return_values_over_shards(self):
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import test_shard_merge as tsm

        def sh(k, vals):
            r = tsm.shard(k, post_ret_checked=40, post_ret_values=len(vals), post_ret_value_list=sorted(vals))
            r["post"] = ["ge(ret, 0)"]
            return r
        m, why = tree_tu.merge_shards([sh(0, ["1.0", "2.0"]), sh(1, ["2.0", "3.0"])])
        self.assertIsNotNone(m, why)
        self.assertEqual(m["level3"]["post_ret_values"], 3)       # (a union, never 4)
        self.assertEqual(m["level3"]["post_ret_checked"], 80)
        m, _ = tree_tu.merge_shards([sh(0, ["1.0"]), sh(1, ["1.0"])])
        self.assertEqual(m["class"], "post_unverified")         # (one distinct return)
        bad = sh(1, ["1.0"])
        del bad["level3"]["post_ret_value_list"]
        self.assertIsNone(tree_tu.merge_shards([sh(0, ["1.0"]), bad])[0])


class ViewAndLedger(unittest.TestCase):
    def _view(self, post):
        rep = {"post": post} if post else {}
        return equiv.checker_view(False, ("?f@@YANXZ",), {"cc": "thiscall"}, "f64", False, {}, rep, {}, {}, [])

    def test_post_in_view_and_no_carry(self):
        v0, c0 = self._view(None)
        v1, c1 = self._view(["ge(ret, 0)"])
        v2, c2 = self._view(["lt(*arg3, *this+0xc68) when ret"])     # (out-parameter posts too: rev5)
        self.assertEqual(len({v0, v1, v2}), 3)
        p0, p1 = equiv.view_parts(c0), equiv.view_parts(c1)
        self.assertNotEqual(p0["rest"], p1["rest"])     # (a post edit is outside the carryable entries)
        run = {"addr": "0x1", "mode": "msvc", "code": "c", "checker": "k", "view": v0, "view_parts": p0,
               "touched": {"callees": [], "symbols": []}, "l2_parts": {"ok": True, "issues": "i", "decl_arity": "d"},
               "status": "equivalent", "promotable": True}
        cur = {"addr": "0x1", "mode": "msvc", "code": "c", "checker": "k", "view": v1, "view_parts": p1,
               "l2_parts": {"ok": True, "issues": "i", "decl_arity": "d"}}
        ok, why = tree_tu.carry_check(run, cur)
        self.assertFalse(ok, why)

    def test_post_kind_proves_nothing_else(self):
        e = {"kind": "post", "addr": "0x1", "mode": "msvc", "code": "c", "view": "v", "status": "equivalent",
             "promotable": True}
        self.assertFalse(tree_tu.ledger_line_proves(e))


if __name__ == "__main__":
    unittest.main()
