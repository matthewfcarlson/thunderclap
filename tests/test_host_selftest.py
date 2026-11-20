#!/usr/bin/env python3
"""tools/host_selftest.py apply: a failing host loses the equiv cap, a passing one gets it back (integ3, hostcheck)."""
import importlib
import json
import os
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))


class T(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp()
        os.environ["JOBQ_DIR"] = self.d
        os.environ.pop("JOBQ_HOSTS", None)
        json.dump({"hosts": [{"name": "a", "caps": ["equiv", "msvc"]}, {"name": "b", "caps": ["equiv", "msvc"]}]},
                  open(os.path.join(self.d, "hosts.json"), "w"))
        import host_selftest
        self.m = importlib.reload(host_selftest)

    def _res(self, jid, ok):
        p = os.path.join(self.d, "out", str(jid), "jobsrc")
        os.makedirs(p)
        json.dump({"ok": ok, "checker": "c0", "diffs": [] if ok else [{"case": "x", "want": {"n": 1}, "got": {"n": 2}}]},
                  open(os.path.join(p, "selftest.json"), "w"))

    def caps(self):
        return {h["name"]: h["caps"] for h in json.load(open(os.path.join(self.d, "hosts.json")))["hosts"]}

    def test_quarantine_and_restore(self):
        self._res(1, True)
        self._res(2, False)
        open(os.path.join(self.d, "selftest.ids"), "w").write("a 1\nb 2\n")
        self.m.apply()
        c = self.caps()
        self.assertIn("equiv", c["a"])
        self.assertNotIn("equiv", c["b"])
        self.assertIn("msvc", c["b"])
        st = json.load(open(os.path.join(self.d, "selftest.json")))
        self.assertFalse(st["b"]["ok"])
        self.assertEqual(st["b"]["diffs"][0]["case"], "x")
        self._res(3, True)
        open(os.path.join(self.d, "selftest.ids"), "w").write("b 3\n")
        self.m.apply()
        self.assertIn("equiv", self.caps()["b"])
        log_ = open(os.path.join(self.d, "daemon.log")).read()
        self.assertIn("b: selftest FAILED (job 2; x)", log_)
        self.assertIn("b: selftest passes again (job 3)", log_)

    def test_missing_result_changes_nothing(self):
        open(os.path.join(self.d, "selftest.ids"), "w").write("a 9\n")
        self.m.apply()
        self.assertIn("equiv", self.caps()["a"])

    def test_dry_run(self):
        self._res(2, False)
        open(os.path.join(self.d, "selftest.ids"), "w").write("b 2\n")
        self.m.apply(dry_run=True)
        self.assertIn("equiv", self.caps()["b"])


if __name__ == "__main__":
    unittest.main()
