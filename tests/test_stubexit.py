#!/usr/bin/env python3
"""tools/equiv.py stubexit (integ4; rev5): the static sites of 0x00088020 and 0x00086240, and the sealed-loop rule: a loop
with a call that may not return (a noreturn callee or an indirect call) is not sealed, so its guard is never forced.
Skips without the game files."""
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))


class T(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        import equiv
        if not os.path.exists(equiv.XBE_PATH):
            raise unittest.SkipTest("no XBE")
        cls.eq = equiv
        cls.prog = equiv.Program.get()

    def sites(self, a, size):
        ov = self.eq.CodeView(self.prog.read, a, (a, a + size), self.prog)
        ov.build()
        return {c - a: s for c, s in self.eq._stubexit_sites(ov, self.prog).items()}

    def test_drain_loop(self):
        s = self.sites(0x86240, 43)
        self.assertEqual(sorted(s), [0x0a, 0x20])
        self.assertTrue(s[0x0a]["guard"] and not s[0x20]["guard"])
        self.assertTrue(all(x["kind"] == "test" and x["width"] == 8 and x["zf_exit"] for x in s.values()))

    def test_sealed_guard(self):
        s = self.sites(0x88020, 1281)
        g = s[0x352]
        self.assertTrue(g["guard"] and g["sealed"] and g["kind"] == "cmp" and g["imm"] == 0x800 and g["zf_exit"])
        self.assertFalse(s[0x441]["sealed"])        # the load loop has exits

    def test_noreturn_call_unseals(self):
        # (rev5, must-not) the same loop with its callee 0x001bb0b0 taken as noreturn (an exit-like stub): not sealed
        old = self.prog.noreturn
        try:
            self.prog.noreturn = lambda t: t == 0x1bb0b0 or old(t)
            s = self.sites(0x88020, 1281)
        finally:
            self.prog.noreturn = old
        # (its decoding stops at the call, or the loop counts the call as a way out: either way no forced guard)
        self.assertTrue(0x352 not in s or not s[0x352]["sealed"])

    def test_noreturn_clause(self):
        # the clause itself: the loop decoded as before, its call to 0x001bb0b0 judged exit-like
        old = self.eq._sx_noreturn
        try:
            self.eq._sx_noreturn = lambda prog, t: t == 0x1bb0b0
            s = self.sites(0x88020, 1281)
        finally:
            self.eq._sx_noreturn = old
        self.assertTrue(s[0x352]["guard"])
        self.assertFalse(s[0x352]["sealed"])


if __name__ == "__main__":
    unittest.main()
