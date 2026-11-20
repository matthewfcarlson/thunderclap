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
        e64._LEDGER_IDX[:] = [{("0x001f87e0", "msvc", "aaaaaaaaaaaa", "cccccccccccc")}]
        out = e64._post_of_text(BLK, {})
        self.assertIn(0x1f87e0, out)
        self.assertEqual(out["sym"]["?Find@Table@@QAE_NPAXPAXPAI@Z"], 0x1f87e0)     # by symbol too
        e64._LEDGER_IDX[:] = [{("0x001f87e0", "msvc", "dddddddddddd", "cccccccccccc")}]     # an older code's proof
        self.assertNotIn(0x1f87e0, e64._post_of_text(BLK, {}))
        e64._LEDGER_IDX[:] = []


if __name__ == "__main__":
    unittest.main()
