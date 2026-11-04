"""jq3: where `wine_build_job.py submit` lets a Wine build run (tools/wine_build_job.py placement): --host pins; otherwise
the queue picks the host at dispatch, with an affinity for the host that has the lineage's state, or a pin when that
state is required (--state resume / --map reuse). No hosts needed (the ssh survey is replaced).

  build/venv/bin/python -m unittest tests.jobq.test_wine_placement     (from the repo root)
"""
import argparse
import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import wine_build_job as wbj  # noqa: E402


def args(**kw):
    d = dict(host=None, replay="play3", state="auto", map="auto", affinity_wait=900)
    d.update(kw)
    return argparse.Namespace(**d)


class Placement(unittest.TestCase):
    def setUp(self):
        self.saved = wbj.build_hosts, wbj.survey
        wbj.build_hosts = lambda replay: ["hA", "hB"]
        self.sv = {}
        wbj.survey = lambda hosts, lineage, stamp: self.sv

    def tearDown(self):
        wbj.build_hosts, wbj.survey = self.saved

    def test_explicit_host_pins(self):
        pin, aff, sync, _ = wbj.placement(args(host="hB"), "L", "s")
        self.assertEqual((pin, aff, sync), ("hB", None, ["hB"]))

    def test_new_lineage_is_unpinned_and_synced_everywhere(self):
        self.sv = {"hA": {"lineage": None, "inputs": True}, "hB": {"lineage": None, "inputs": False}}
        pin, aff, sync, _ = wbj.placement(args(), "L", "s")
        self.assertEqual((pin, aff, sync), (None, None, ["hB"]))

    def test_unreachable_host_still_a_candidate(self):
        self.sv = {"hA": {"lineage": None, "inputs": True}}          # hB did not answer: synced at dispatch (prep)
        pin, aff, sync, _ = wbj.placement(args(), "L", "s")
        self.assertEqual((pin, aff, sync), (None, None, ["hB"]))

    def test_lineage_state_gives_affinity_to_newest(self):
        self.sv = {"hA": {"lineage": 100.0, "inputs": True}, "hB": {"lineage": 200.0, "inputs": True}}
        pin, aff, sync, _ = wbj.placement(args(), "L", "s")
        self.assertEqual((pin, aff), (None, "hB"))
        self.assertEqual(wbj.placement(args(affinity_wait=0), "L", "s")[:2], (None, None))
        self.assertEqual(wbj.placement(args(state="fresh"), "L", "s")[:2], (None, None))

    def test_required_state_pins(self):
        self.sv = {"hA": {"lineage": 100.0, "inputs": True}, "hB": {"lineage": None, "inputs": True}}
        self.assertEqual(wbj.placement(args(state="resume"), "L", "s")[:2], ("hA", None))
        self.assertEqual(wbj.placement(args(map="reuse"), "L", "s")[:2], ("hA", None))
        self.assertEqual(wbj.placement(args(stages="link,replay"), "L", "s")[:2], ("hA", None))
        self.assertEqual(wbj.placement(args(stages="build,probe"), "L", "s")[:2], (None, "hA"))
        self.sv = {"hA": {"lineage": None, "inputs": True}}           # nowhere: a fresh build anywhere (decide() says so)
        self.assertEqual(wbj.placement(args(state="resume"), "L", "s")[:2], (None, None))


if __name__ == "__main__":
    unittest.main()
