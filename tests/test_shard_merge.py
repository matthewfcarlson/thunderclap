#!/usr/bin/env python3
"""tools/tree_tu.py merge_shards (integ5, D155c; rev5): the N shard reports of one sharded proof merge into one report
that the whole run's rules judge; anything the merge has no rule for, a missing shard, an unsupported or CPU-cut shard
refuse it, and a difference in any shard fails it."""
import copy
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import equiv  # noqa: E402
import tree_tu  # noqa: E402

# (integ10, D181) shards merge only under the checker they ran
TC = {"msvc": "aaa", "wine": None, "view": "vvv", "checker": equiv._checker_digest(), "n_inputs": 3000}


def shard(k, n=2, run=1600, missing=("+0x10 taken",), pairs=tuple("p%d" % i for i in range(12)), **l3x):
    l3 = {"ok": True, "inputs_run": run, "inputs_inconclusive": 5, "inputs_faulted": 0, "inputs_failed": 0,
          "inputs_directed": 3, "inputs_drawn": run + 5, "mismatches": [], "statuses": {"ret": run, "timeout": 5},
          "coverage": {"edges_total": 10, "edges_covered": 10 - len(missing), "missing_all": sorted(missing),
                       "uncovered": sorted(missing), "complete": not missing, "uncovered_hash": "x"},
          "post_checked": 30, "post_pairs": len(pairs), "post_pair_list": sorted(pairs), "work": 100, "cpu": 1.0,
          "input_digest": "d%d" % k, "shard": [k, n], "compared_keys": ["k%d_%d" % (k, i) for i in range(run)]}
    l3.update(l3x)
    return {"addr": "0x001f87e0", "native": False, "symbol": "?F@@", "status": "equivalent", "level": 3,
            "byte_identical": False, "level2": {"ok": True, "issues": [], "conflicts": []}, "post": ["ge(*arg3, 0)"],
            "pre": None, "equiv_off": [], "equiv_on": [], "tree_code": dict(TC, job=str(500 + k)), "level3": l3,
            "promotable": False}


class T(unittest.TestCase):
    def test_merge(self):
        a = shard(0, missing=("+0x10 taken", "+0x20 taken"), pairs=tuple("p%d" % i for i in range(7)))
        b = shard(1, missing=("+0x20 taken", "+0x30 taken"), pairs=tuple("p%d" % i for i in range(5, 12)))
        m, why = tree_tu.merge_shards([b, a])
        self.assertIsNotNone(m, why)
        l = m["level3"]
        self.assertEqual(l["inputs_run"], 3200)
        self.assertEqual(l["statuses"], {"ret": 3200, "timeout": 10})
        self.assertEqual(l["coverage"]["missing_all"], ["+0x20 taken"])      # covered when either shard took it
        self.assertEqual(l["coverage"]["edges_covered"], 9)
        self.assertEqual(l["post_pairs"], 12)                                 # distinct pairs, not 7 + 7
        self.assertEqual(l["post_checked"], 60)
        self.assertEqual(m["status"], "equivalent")
        self.assertTrue(m["promotable"])
        self.assertEqual(m["shards"]["jobs"], ["500", "501"])
        e = tree_tu.ledger_entry("0x001f87e0", "msvc", "aaa", "vvv", m, "t.cpp")
        self.assertEqual((e["shard_n"], e["shard_jobs"], e["job"]), (2, ["500", "501"], None))
        ok, why = tree_tu.proves(m, "msvc", "aaa", "vvv")
        self.assertTrue(ok, why)

    def test_distinct_inputs_and_line_key(self):
        a, b = shard(0, run=1600), shard(1, run=1600)
        b["level3"]["compared_keys"] = a["level3"]["compared_keys"][:300] + b["level3"]["compared_keys"][300:]
        m, _ = tree_tu.merge_shards([a, b])
        self.assertEqual(m["level3"]["inputs_run"], 2900)            # 300 inputs both shards compared count once
        self.assertEqual(m["level3"]["compared_duplicates"], 300)
        self.assertIsNotNone(tree_tu.run_shortfall(m, 3000))
        c = copy.deepcopy(b)
        del c["level3"]["compared_keys"]
        self.assertIsNone(tree_tu.merge_shards([a, c])[0])          # no list: refused
        m, _ = tree_tu.merge_shards([shard(0), shard(1)])
        e1 = tree_tu.ledger_entry("0x001f87e0", "msvc", "aaa", "vvv", m, "t.cpp")
        e2 = dict(e1, shard_jobs=["600", "601"])
        self.assertNotEqual(tree_tu.ledger_line_key(e1), tree_tu.ledger_line_key(e2))   # two sharded runs: two keys
        plain = {"addr": "0x1", "mode": "msvc", "code": "c", "view": "v", "checker": "k", "job": "9", "date": "d",
                 "n_inputs": 3000}
        self.assertEqual(tree_tu.ledger_line_key(plain), tree_tu.ledger_line_key(dict(plain, shard_jobs=None)))

    def test_lone_shard_proves_nothing(self):
        ok, why = tree_tu.proves(shard(0, run=3100), "msvc", "aaa", "vvv")
        self.assertFalse(ok)
        self.assertIn("shard", why)

    def test_refusals(self):
        a, b = shard(0), shard(1)
        self.assertIsNone(tree_tu.merge_shards([a])[0])                                   # a missing shard
        self.assertIsNone(tree_tu.merge_shards([a, copy.deepcopy(a)])[0])                 # shard 0 twice
        self.assertIsNone(tree_tu.merge_shards([a, shard(1, n=3)])[0])                    # another N
        c = copy.deepcopy(b)
        c["tree_code"]["msvc"] = "bbb"
        self.assertIsNone(tree_tu.merge_shards([a, c])[0])                                # other code
        c = copy.deepcopy(b)
        c["level3"]["time_cut_wall"] = True
        self.assertIsNone(tree_tu.merge_shards([a, c])[0])                                # the CPU cap cut a shard
        c = copy.deepcopy(b)
        c["status"] = "unsupported"
        self.assertIsNone(tree_tu.merge_shards([a, c])[0])
        c = copy.deepcopy(b)
        c["level3"]["a_new_counter"] = 3
        m, why = tree_tu.merge_shards([a, c])
        self.assertIsNone(m)
        self.assertIn("default-deny", why)                                                # no rule: refused
        c = copy.deepcopy(b)
        c["equiv_off"] = ["x"]
        self.assertIsNone(tree_tu.merge_shards([a, c])[0])                                # switches
        c, d = copy.deepcopy(a), copy.deepcopy(b)
        c["level3"]["pre_trap"] = "fired"
        d["level3"]["pre_trap"] = "missing: x"
        self.assertIsNone(tree_tu.merge_shards([c, d])[0])                                # the trap in every shard

    def test_a_difference_in_one_shard_fails(self):
        a, b = shard(0), shard(1)
        b["status"] = "fail"
        b["level3"]["ok"] = False
        b["level3"]["inputs_failed"] = 1
        b["level3"]["mismatches"] = [{"input": 7, "diffs": ["eax 1 vs 2"]}]
        m, why = tree_tu.merge_shards([a, b])
        self.assertEqual(m["status"], "fail")
        self.assertFalse(m["promotable"])
        self.assertEqual(len(m["level3"]["mismatches"]), 1)

    def test_short_totals_stay_short(self):
        m, _ = tree_tu.merge_shards([shard(0, run=1000), shard(1, run=1000)])
        self.assertIsNotNone(tree_tu.run_shortfall(m, 3000))                              # 2,000 compared of 3,000
        self.assertFalse(tree_tu.proves(m, "msvc", "aaa", "vvv")[0])
        m, _ = tree_tu.merge_shards([shard(0, pairs=("p1",)), shard(1, pairs=("p1",))])
        self.assertEqual(m["class"], "post_unverified")                                   # one distinct pair

    def test_another_checker_refused(self):
        # (integ10, D181) 0x00094fb0's shards from before 3d027e12e (no `post` field) crashed level3_verdict: shards of
        # another checker are refused before any verdict is read
        a, b = shard(0), shard(1)
        for r in (a, b):
            r["tree_code"]["checker"] = "0123456789ab"
            r.pop("post")
        m, why = tree_tu.merge_shards([a, b])
        self.assertIsNone(m)
        self.assertIn("merge them with the tools they ran", why)
        a, b = shard(0), shard(1)
        a["tree_code"]["checker"] = "0123456789ab"                         # (one shard of another checker)
        self.assertIsNone(tree_tu.merge_shards([a, b])[0])

    def test_no_post_field(self):
        a, b = shard(0, pairs=()), shard(1, pairs=())
        for r in (a, b):
            r.pop("post")
            r["level3"].pop("post_pairs")
            r["level3"].pop("post_pair_list")
        m, why = tree_tu.merge_shards([a, b])
        self.assertIsNotNone(m, why)                                                       # (no post: none stated)


if __name__ == "__main__":
    unittest.main()
