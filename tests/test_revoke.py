#!/usr/bin/env python3
"""tools/tree_tu.py revoke (integ4, D154): a revoked ledger line proves nothing; the revocation is per line, so a later
run of the same code (another record) proves it again; revoke refuses a block nothing proves."""
import json
import os
import sys
import tempfile
import unittest
from unittest import mock

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu  # noqa: E402

L1 = {"addr": "0x00272df0", "mode": "wine", "code": "aaa", "view": "vvv", "job": "83510", "status": "equivalent",
      "promotable": True, "checker": "c1", "date": "2026-11-16", "n_inputs": 3000}
L2 = dict(L1, job="99999", checker="c2")      # the same code, proven again under a fixed checker
LM = dict(L1, mode="msvc", code="bbb")


class T(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp()
        self.led = os.path.join(self.d, "ledger.jsonl")
        self.rev = os.path.join(self.d, "revoked.jsonl")
        with open(self.led, "w") as f:
            for e in (L1, LM):
                f.write(json.dumps(e) + "\n")
        self.p = [mock.patch.object(tree_tu, "LEDGER", self.led), mock.patch.object(tree_tu, "REVOKED", self.rev)]
        for p in self.p:
            p.start()
        tree_tu._REVOKED.clear()

    def tearDown(self):
        for p in self.p:
            p.stop()
        tree_tu._REVOKED.clear()

    def test_revoke(self):
        self.assertIn(("0x00272df0", "wine", "aaa"), tree_tu.code_ledger_index(self.led))
        self.assertEqual(tree_tu.main(["revoke", "0x272df0", "--mode", "wine", "--why", "D154: test"]), 0)
        idx = tree_tu.code_ledger_index(self.led)
        self.assertNotIn(("0x00272df0", "wine", "aaa"), idx)          # revoked
        self.assertIn(("0x00272df0", "msvc", "bbb"), idx)             # the other mode untouched
        self.assertNotIn(("0x00272df0", "wine", "aaa", "vvv"), tree_tu.ledger_index(self.led))
        rec = json.loads(open(self.rev).read())
        self.assertEqual((rec["addr"], rec["mode"], rec["codes"], rec["by"]), ("0x00272df0", "wine", ["aaa"], "revoke"))
        # nothing proves it now: revoke refuses
        with self.assertRaises(SystemExit):
            tree_tu.main(["revoke", "0x272df0", "--mode", "wine", "--why", "again"])
        # (rev5) the revoked line re-serialized (keys in another order, an extra field) stays revoked
        tree_tu._REVOKED.clear()
        L1b = dict(reversed(list(L1.items())), coverage="6/6")
        self.assertFalse(tree_tu.ledger_line_proves(L1b))
        # the same code under the same checker in another run: refused too (revoked_run)
        L1c = dict(L1, job="12345", date="2026-11-21")
        self.assertFalse(tree_tu.ledger_line_proves(L1c))
        self.assertIn("D154: test", tree_tu.revoked_run(L1c))
        # a later proof of the same code under a fixed checker proves it again
        with open(self.led, "a") as f:
            f.write(json.dumps(L2) + "\n")
        self.assertIn(("0x00272df0", "wine", "aaa"), tree_tu.code_ledger_index(self.led))

    def test_why_required(self):
        with self.assertRaises(SystemExit):
            tree_tu.main(["revoke", "0x272df0", "--mode", "wine", "--why", " "])


if __name__ == "__main__":
    unittest.main()
