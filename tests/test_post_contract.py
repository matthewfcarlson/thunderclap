#!/usr/bin/env python3
"""tools/equiv.py / tools/equiv64.py postconditions (integ4, post; rev5): parsing, the original-side check, and the
callers' index: a callee's post is used only when the proof ledger holds its current code (by address and by its
`// sym:` symbol)."""
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))

BLK = """// 0x001f87e0 FUN_001f87e0 (163 B): equivalent/0x001f87e0.cpp
// sym: ?Find@Table@@QAE_NPAXPAXPAI@Z @aaaaaaaaaaaa @wbbbbbbbbbbbb @vcccccccccccc
// post: ge(*arg3, 0) lt(*arg3, *this+0xc68) when ret
bool Table::Find(void* a, void* b, unsigned* out) { return false; }
"""


class T(unittest.TestCase):
    def setUp(self):
        import equiv
        import equiv64
        self.eq, self.e64 = equiv, equiv64

    def test_parse(self):
        specs, bad = self.eq._parse_post(["ge(*arg3, 0) lt(*arg3, *this+0xc68) when ret"])
        self.assertEqual(bad, [])
        self.assertEqual(specs[1], (3, ("range", float("-inf"), ("this32", 0xc68), True, False)))
        self.assertTrue(self.eq._parse_post(["lt(*arg3, 4)"])[1])               # no `when ret`
        self.assertTrue(self.eq._parse_post(["lt(arg3, 4) when ret"])[1])       # not a pointee

    def test_check(self):
        mem = {0x1000: 5, 0x2000 + 0xc68: 4}
        inp = {"stack": [0, 0, 0x1000], "regs": {"ecx": 0x2000}}
        sig = {"params": ["ptr", "ptr", "ptr"], "ret": "b8"}
        post = self.eq._parse_post(["lt(*arg3, *this+0xc68) when ret"])[0]
        self.assertIn("outside", self.eq._post_check(post, sig, inp, {"eax": 1}, mem.get))
        self.assertEqual(self.eq._post_check(post, sig, inp, {"eax": 0x100}, mem.get), "zero")   # al 0: false
        mem[0x1000] = 3
        self.assertEqual(self.eq._post_check(post, sig, inp, {"eax": 1}, mem.get), ("ok", ((3, 3, (4.0,)),)))

    def test_index_needs_proof(self):
        e64 = self.e64
        e64._LEDGER_IDX[:] = [set()]
        out = e64._post_of_text(BLK, {})
        self.assertNotIn(0x1f87e0, out)          # no proof of the current code: callers get the plain fill
        import tree_tu
        # (integ5) a ledger line holds its mode's own view; the pin's @v is the digest of the msvc and wine views
        blk = BLK.replace("@vcccccccccccc", "@v" + tree_tu.view_digest("vm1", "vw1"))
        both = {("0x001f87e0", "msvc", "aaaaaaaaaaaa", "vm1"), ("0x001f87e0", "wine", "bbbbbbbbbbbb", "vw1")}
        e64._LEDGER_IDX[:] = [both]
        out = e64._post_of_text(blk, {})
        self.assertIn(0x1f87e0, out)
        self.assertEqual(out["sym"]["?Find@Table@@QAE_NPAXPAXPAI@Z"], 0x1f87e0)     # by symbol too
        e64._LEDGER_IDX[:] = [{x for x in both if x[1] == "msvc"}]                  # one mode only: not the pin's view
        self.assertNotIn(0x1f87e0, e64._post_of_text(blk, {}))
        e64._LEDGER_IDX[:] = [(both - {("0x001f87e0", "wine", "bbbbbbbbbbbb", "vw1")}) |
                              {("0x001f87e0", "wine", "bbbbbbbbbbbb", "vw2")}]
        self.assertNotIn(0x1f87e0, e64._post_of_text(blk, {}))                     # another view of the same code
        e64._LEDGER_IDX[:] = [{("0x001f87e0", "msvc", "dddddddddddd", "vm1"), ("0x001f87e0", "wine", "bbbbbbbbbbbb", "vw1")}]
        self.assertNotIn(0x1f87e0, e64._post_of_text(blk, {}))                     # an older code's proof
        e64._LEDGER_IDX[:] = [{("0x001f87e0", "msvc", "aaaaaaaaaaaa", "cccccccccccc")}]
        self.assertNotIn(0x1f87e0, e64._post_of_text(BLK, {}))                     # (the old, wrong match: @v as a line view)
        nw = blk.replace(" @wbbbbbbbbbbbb", "")                                    # no clang object: the msvc line alone
        e64._LEDGER_IDX[:] = [{("0x001f87e0", "msvc", "aaaaaaaaaaaa", "vm1")}]
        self.assertNotIn(0x1f87e0, e64._post_of_text(nw, {}))                      # (@v was the digest with a wine view)
        nw2 = BLK.replace(" @wbbbbbbbbbbbb", "").replace("@vcccccccccccc", "@v" + tree_tu.view_digest("vm1", None))
        self.assertIn(0x1f87e0, e64._post_of_text(nw2, {}))
        e64._LEDGER_IDX[:] = []

    def test_index_uses_the_ledger_predicate(self):
        """(integ5; rev5) passing is tree_tu.ledger_line_proves (via ledger_index): a revoked or non-promotable wine
        line of the callee leaves its post unused."""
        import json
        import tempfile
        from unittest import mock
        import tree_tu
        e64 = self.e64
        blk = BLK.replace("@vcccccccccccc", "@v" + tree_tu.view_digest("vm1", "vw1"))
        lm = {"addr": "0x001f87e0", "mode": "msvc", "code": "aaaaaaaaaaaa", "view": "vm1", "status": "equivalent",
              "promotable": True, "checker": "c1", "job": "1"}
        lw = dict(lm, mode="wine", code="bbbbbbbbbbbb", view="vw1", job="2")
        d = tempfile.mkdtemp()
        led, rev = os.path.join(d, "ledger.jsonl"), os.path.join(d, "revoked.jsonl")

        def index(lines, revoked=()):
            with open(led, "w") as f:
                f.writelines(json.dumps(e) + "\n" for e in lines)
            with open(rev, "w") as f:
                for e in revoked:
                    f.write(json.dumps({"addr": e["addr"], "mode": e["mode"], "codes": [e["code"]], "by": "revoke",
                                        "lines": [tree_tu.ledger_line_key(e)], "runs": [], "why": "t"}) + "\n")
            tree_tu._REVOKED.clear()
            e64._LEDGER_IDX[:] = []
            return 0x1f87e0 in e64._post_of_text(blk, {})
        try:
            with mock.patch.object(tree_tu, "LEDGER", led), mock.patch.object(tree_tu, "REVOKED", rev):
                self.assertTrue(index([lm, lw]))
                self.assertFalse(index([lm, lw], revoked=[lw]))                     # the wine proof revoked
                self.assertFalse(index([lm, dict(lw, promotable=False)]))           # not promotable
                self.assertFalse(index([lm, dict(lw, status="fail")]))              # a recorded failure
        finally:
            tree_tu._REVOKED.clear()
            e64._LEDGER_IDX[:] = []


if __name__ == "__main__":
    unittest.main()
