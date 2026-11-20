#!/usr/bin/env python3
"""tools/tree_tu.py hash --carry (integ6, D159): a proof carries to a new checker view without a run only from a run line
of the same block, mode, code and checker whose view moved only in decls / pointee_sizes / bindings entries the run never
reached; everything else is refused (default-deny); a carried line proves only after its run line and falls with it."""
import json
import os
import sys
import tempfile
import unittest
from unittest import mock

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import equiv  # noqa: E402
import tree_tu  # noqa: E402

VIEW = {"version": 1, "mode": "msvc", "symbol": "?f@@YAXXZ", "sig": {"cc": "cdecl"}, "ret_kind": "void",
        "void_eax": False, "conventions": {}, "narrow": {}, "issues": [], "conflicts": 0,
        "bindings": {"?g@@YAXH@Z": ["0x00010000", "name"], "?h@@YAXH@Z": ["0x00020000", "name"],
                     "?d@@3HA": ["0x00400000", "name"]},
        "pointee_sizes": {"0x00010000": {"0": 4}, "0x00020000": {"0": 8}},
        "decls": {"0x00010000": {"cc": "cdecl", "params": ["i32"]}, "0x00020000": {"cc": "cdecl", "params": ["i32"]}}}
H = equiv._h10
# the run reached 0x10000 (g); h at 0x20000 is referenced by calls only and never reached; d is data (touched)
TOUCHED = {"callees": ["0x00010000"], "symbols": sorted([H("?g@@YAXH@Z"), H("?d@@3HA")])}
RUN = {"addr": "0x00001000", "mode": "msvc", "code": "c0de", "view": "v0", "checker": "chk", "job": "1", "date": "d",
       "n_inputs": 3000, "inputs_run": 3000, "status": "equivalent", "promotable": True,
       "view_parts": equiv.view_parts(VIEW), "touched": TOUCHED,
       "l2_parts": {"ok": True, "issues": H([]), "decl_arity": H([])}}


def cur(view, vh="v1", **kw):
    c = {"addr": "0x00001000", "mode": "msvc", "code": "c0de", "checker": "chk", "view": vh,
         "view_parts": equiv.view_parts(view), "l2_parts": dict(RUN["l2_parts"])}
    c.update(kw)
    return c


def moved(**changes):
    v = json.loads(json.dumps(VIEW))
    for k, (x, val) in changes.items():
        if val is None:
            v[k].pop(x, None)
        else:
            v[k][x] = val
    return v


class T(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp()
        self.led = os.path.join(self.d, "ledger.jsonl")
        self.rev = os.path.join(self.d, "revoked.jsonl")
        self.p = [mock.patch.object(tree_tu, "LEDGER", self.led), mock.patch.object(tree_tu, "REVOKED", self.rev)]
        for p in self.p:
            p.start()
        tree_tu._REVOKED.clear()

    def tearDown(self):
        for p in self.p:
            p.stop()
        tree_tu._REVOKED.clear()

    def test_unreached_entries_carry(self):
        for v in (moved(decls=("0x00020000", {"cc": "cdecl", "params": ["i32", "ptr"]})),
                  moved(pointee_sizes=("0x00020000", {"0": 16})),
                  moved(bindings=("?h@@YAXH@Z", ["0x00030000", "name"])),
                  moved(decls=("0x00030000", {"cc": "cdecl", "params": []})),      # an entry added
                  moved(decls=("0x00020000", None))):                               # an entry removed
            ok, d = tree_tu.carry_check(RUN, cur(v))
            self.assertTrue(ok, d)
            self.assertTrue(d)

    def test_reached_entries_refuse(self):
        for v in (moved(decls=("0x00010000", {"cc": "cdecl", "params": ["i32", "ptr"]})),
                  moved(pointee_sizes=("0x00010000", {"0": 16})),
                  moved(bindings=("?g@@YAXH@Z", ["0x00030000", "name"])),          # bound to a reached callee
                  moved(bindings=("?d@@3HA", ["0x00400004", "name"]))):            # data: always touched
            ok, why = tree_tu.carry_check(RUN, cur(v))
            self.assertFalse(ok)
            self.assertIn("reached", why)

    def test_rest_is_default_deny(self):
        for k, val in (("sig", {"cc": "stdcall"}), ("narrow", {"0x00020000": {"0": 8}}), ("issues", [["x", "y"]]),
                       ("conventions", {"0x00020000": ["ecx"]}), ("ret_kind", "i32"), ("pre", ["ge(arg1, 0)"]),
                       ("a_key_added_later", 1)):
            v = json.loads(json.dumps(VIEW))
            v[k] = val
            ok, why = tree_tu.carry_check(RUN, cur(v))
            self.assertFalse(ok, k)
            self.assertIn("outside", why)

    def test_level2_must_hold(self):
        # (rev5) an unreached callee's declaration that now gives a level-2 arity finding, or a failing level 2: refused
        v = moved(decls=("0x00020000", {"cc": "cdecl", "params": ["i32", "ptr"]}))
        da = {"ok": True, "issues": H([]), "decl_arity": H(['{"callee": "0x00020000", "kind": "pops"}'])}
        for l2 in (da, dict(RUN["l2_parts"], ok=False), dict(RUN["l2_parts"], issues=H(["x"])), None,
                   dict(RUN["l2_parts"], extra=1)):
            ok, why = tree_tu.carry_check(RUN, cur(v, l2_parts=l2))
            self.assertFalse(ok, l2)
            self.assertIn("level", why)
        x2 = dict(RUN["l2_parts"], extra=1)      # a level-2 part no rule knows, on both sides: default-deny
        self.assertFalse(tree_tu.carry_check(dict(RUN, l2_parts=x2), cur(v, l2_parts=dict(x2)))[0])
        old = {k: x for k, x in RUN.items() if k != "l2_parts"}
        self.assertFalse(tree_tu.carry_check(old, cur(v))[0])
        self.assertEqual(tree_tu.carried_line(RUN, cur(v), ["d"], "t")["carry_l2"], RUN["l2_parts"])

    def test_line_and_block_conditions(self):
        v = moved(decls=("0x00020000", {"cc": "cdecl", "params": []}))
        self.assertTrue(tree_tu.carry_check(RUN, cur(v))[0])
        for kw in ({"code": "other"}, {"checker": "chk2"}, {"mode": "wine"}, {"addr": "0x00001004"}):
            self.assertFalse(tree_tu.carry_check(RUN, cur(v, **kw))[0], kw)
        old = {k: x for k, x in RUN.items() if k not in ("view_parts", "touched")}
        self.assertIn("before D159", tree_tu.carry_check(old, cur(v))[1])
        carried = tree_tu.carried_line(RUN, cur(v), ["decls 0x00020000"], "tu.cpp")
        self.assertIn("carried line", tree_tu.carry_check(carried, cur(v, vh="v2"))[1])
        for bad in (dict(RUN, promotable=False), dict(RUN, status="fail")):
            self.assertFalse(tree_tu.carry_check(bad, cur(v))[0])
        # parts or touched sets of an unknown shape: refused
        self.assertFalse(tree_tu.carry_check(dict(RUN, view_parts=dict(RUN["view_parts"], extra={})), cur(v))[0])
        self.assertFalse(tree_tu.carry_check(dict(RUN, touched=dict(TOUCHED, data=[])), cur(v))[0])
        # the same view (nothing moved) is not a carry
        self.assertFalse(tree_tu.carry_check(RUN, cur(VIEW, vh="v0"))[0])

    def test_ledger_index_and_revocation(self):
        v = moved(decls=("0x00020000", {"cc": "cdecl", "params": []}))
        carried = tree_tu.carried_line(RUN, cur(v), ["decls 0x00020000"], "tu.cpp")
        self.assertEqual(carried["carried_from"], tree_tu.ledger_line_key(RUN))
        # a carried line without its run line in the ledger proves nothing
        with open(self.led, "w") as f:
            f.write(json.dumps(carried) + "\n")
        self.assertNotIn(("0x00001000", "msvc", "c0de", "v1"), tree_tu.ledger_index(self.led))
        with open(self.led, "w") as f:
            f.write(json.dumps(RUN) + "\n" + json.dumps(carried) + "\n")
        idx = tree_tu.ledger_index(self.led)
        self.assertIn(("0x00001000", "msvc", "c0de", "v0"), idx)
        self.assertIn(("0x00001000", "msvc", "c0de", "v1"), idx)
        # revoking the run line by its key revokes the carried line
        with open(self.rev, "w") as f:
            f.write(json.dumps({"addr": "0x00001000", "mode": "msvc", "lines": [tree_tu.ledger_line_key(RUN)],
                                "runs": [], "why": "test"}) + "\n")
        tree_tu._REVOKED.clear()
        self.assertFalse(tree_tu.ledger_line_proves(carried))
        self.assertEqual(tree_tu.ledger_index(self.led), set())
        # and a revocation of the run's (code, checker) as well
        with open(self.rev, "w") as f:
            f.write(json.dumps({"addr": "0x00001000", "mode": "msvc", "lines": [], "runs": [["c0de", "chk"]],
                                "why": "test"}) + "\n")
        tree_tu._REVOKED.clear()
        self.assertFalse(tree_tu.ledger_line_proves(carried))

    def test_view_parts_shape(self):
        p = equiv.view_parts(VIEW)
        self.assertEqual(set(p), tree_tu.CARRY_PARTS)
        self.assertNotIn("?g@@YAXH@Z", json.dumps(p))      # names hashed: addresses and hashes only
        self.assertEqual(set(p["decls"]), set(VIEW["decls"]))

    def test_shard_merge_unions_touched(self):
        sys.path.insert(0, os.path.join(ROOT, "tests"))
        import test_shard_merge as tsm
        a = tsm.shard(0, touched={"callees": ["0x00010000"], "symbols": ["s1"]})
        b = tsm.shard(1, touched={"callees": ["0x00020000"], "symbols": ["s2"]})
        m, why = tree_tu.merge_shards([a, b])
        self.assertIsNotNone(m, why)
        self.assertEqual(m["level3"]["touched"], {"callees": ["0x00010000", "0x00020000"], "symbols": ["s1", "s2"]})
        # a shard without touched sets: the merged run has none (it never carries)
        m, why = tree_tu.merge_shards([a, tsm.shard(1)])
        self.assertIsNotNone(m, why)
        self.assertNotIn("touched", m["level3"])
        # shards that disagree on the view's parts are not one proof
        a2 = dict(a, view_parts={"rest": "x"})
        self.assertIsNone(tree_tu.merge_shards([a2, b])[0])

class Touched(unittest.TestCase):
    def test_touched_sets(self):
        class Ours:
            relocs = [(0, ("data", 0, 0, 0), equiv.DIR32, 0), (4, ("callfar", 0, 0, 0), equiv.REL32, 0),
                      (8, ("callnear", 0, 0, 0), equiv.REL32, 0), (12, ("both", 0, 0, 0), equiv.REL32, 0),
                      (16, ("both", 0, 0, 0), equiv.DIR32, 0), (20, ("unres", 0, 0, 0), equiv.REL32, 0)]

            def local_relocs(self):
                # (a helper of our object that runs in place: its references are the function's too)
                return [(0, ("local_data", 0, 0, 0), equiv.DIR32, 0), (4, ("mixed_local", 0, 0, 0), equiv.DIR32, 0)]
        Ours.relocs = Ours.relocs + [(24, ("mixed_local", 0, 0, 0), equiv.REL32, 0)]
        resolved = {"data": 0x400000, "callfar": 0x10000, "callnear": 0x20000, "both": 0x30000, "noref": 0x40000,
                    "local_data": 0x400010, "mixed_local": 0x50000}
        how = {n: "name" for n in list(resolved) + ["unres"]}
        with mock.patch.object(equiv, "TOUCHED_CALLS", {0x20000}):
            t = equiv.touched_sets(Ours(), resolved, how)
        self.assertEqual(t["callees"], ["0x00020000"])
        # only callfar (called, never reached) is untouched: data, mixed, unreferenced and unresolved names are touched
        self.assertEqual(set(t["symbols"]), {equiv._h10(n) for n in how if n != "callfar"})

    def test_run_records_reached_callees(self):
        # real checks: every callee the code calls (0x24170) or tail-jumps to (0x354c0) is among the touched callees
        if not os.path.exists(equiv.XBE_PATH):
            self.skipTest("no XBE")
        for case in ("0x00024170_fun_name", "0x000354c0_native_tail_fret"):
            self._check(os.path.join(ROOT, "tests/equiv/cases/%s.cpp" % case), int(case.split("_")[0], 16))

    def _check(self, src, a):
        v = equiv.verify(src, a, view_only=True)
        equiv.TOUCHED_CALLS.add(0xdeadbee0)     # (left over from an earlier check: never this check's)
        r = equiv.verify(src, a, n_inputs=30, time_budget=30)
        self.assertNotIn("0xdeadbee0", r["level3"]["touched"]["callees"])
        self.assertEqual(r["status"], "equivalent")
        self.assertEqual(r["view_parts"], equiv.view_parts(v["view_detail"]))
        self.assertTrue(set(v["view_detail"]["decls"]) <= set(r["level3"]["touched"]["callees"]))
        self.assertTrue(set(r["level3"]["touched"]["symbols"]) <=
                        {equiv._h10(n) for n in v["view_detail"]["bindings"]})
        self.assertTrue(r["level3"]["touched"]["symbols"])


if __name__ == "__main__":
    unittest.main()
