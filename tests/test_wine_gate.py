"""tools/wine_gate.judge: a proof-sized --wine run must be promotable (D151, the lead's tightening of D38)."""
import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tools"))
import wine_gate  # noqa: E402


def rep(promotable, n_asked=3000, run=3000, note=None):
    r = {"status": "equivalent", "promotable": promotable, "level3": {"inputs_run": run}, "tree_code": {"n_inputs": n_asked}}
    if note:
        r["promotable_note"] = note
    return r


class Judge(unittest.TestCase):
    def test_coverage_gate(self):
        ok, why = wine_gate.judge(rep(False, note="branch coverage 85/120 is under 90%"))
        self.assertFalse(ok)
        self.assertIn("not promotable", why)
        self.assertIn("85/120", why)

    def test_split_unpinned_is_no_proof(self):
        # (integ3, rev5, D153) a run that needed an argument split nothing pins is unsupported, whatever promotable says
        r = rep(True)
        r.update(status="unsupported", **{"class": "split_unpinned"}, error="[split_unpinned] 46 inputs")
        ok, why = wine_gate.judge(r)
        self.assertFalse(ok)
        self.assertIn("unsupported", why)

    def test_small_runs_unchanged(self):
        # (a quick --wine run, not a proof: judged as before)
        ok, _ = wine_gate.judge(rep(False, n_asked=200, run=200))
        self.assertTrue(ok)


if __name__ == "__main__":
    unittest.main()
