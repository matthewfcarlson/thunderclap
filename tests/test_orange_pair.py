#!/usr/bin/env python3
"""(integ7, rev5 (b)) The Machine draws a guarded contract word with its guard as a pair at every memory epoch: after a
stubbed call's havoc (epoch >= 1) a redraw that makes the guard true never leaves the word out of range, and a guard
that is false leaves the word as drawn. The mutant (no pair logic: the ranges off, the entry repair alone) is shown to
leave guard-true / word-out after a redraw. Synthetic heap addresses; no game bytes are read."""
import os
import struct
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tools"))
import equiv  # noqa: E402

GE0 = ("range", 0.0, float("inf"), True, True, "f")
GT0 = ("range", 0.0, float("inf"), False, True, "f")


def word(m, a, epoch):
    return struct.unpack("<f", bytes(m.byte(a + i, epoch) for i in range(4)))[0]


class Pair(unittest.TestCase):
    base = equiv.HEAP + 0x1000
    W, G = base + 0xf4, base + 0xf8

    def machine(self, oranges, raw, seed=7):
        return equiv.Machine(None, seed, [], oranges=oranges, rawplant=raw)

    def test_guard_true_after_havoc_repaired(self):
        raw = {self.W: struct.unpack("<I", struct.pack("<f", -1000.0))[0],
               self.G: struct.unpack("<I", struct.pack("<f", 1.0))[0]}
        m = self.machine({self.W: (GE0, (self.G, GT0))}, raw)
        for e in (1, 2, 5):
            self.assertEqual(word(m, self.G, e), 1.0)
            self.assertGreaterEqual(word(m, self.W, e), 0.0)

    def test_guard_false_after_havoc_left_alone(self):
        raw = {self.W: struct.unpack("<I", struct.pack("<f", -1000.0))[0], self.G: 0}
        m = self.machine({self.W: (GE0, (self.G, GT0))}, raw)
        self.assertEqual(word(m, self.W, 1), -1000.0)

    def test_mutant_without_pair_logic_leaves_bad_state(self):
        raw = {self.W: struct.unpack("<I", struct.pack("<f", -1000.0))[0],
               self.G: struct.unpack("<I", struct.pack("<f", 1.0))[0]}
        m = self.machine(None, raw)
        self.assertEqual((word(m, self.G, 1), word(m, self.W, 1)), (1.0, -1000.0))

    def test_guard_on_another_page(self):
        g = self.base + 0x1000 + 0x10           # (the next page)
        raw = {self.W: struct.unpack("<I", struct.pack("<f", -5.0))[0],
               g: struct.unpack("<I", struct.pack("<f", 2.0))[0]}
        m = self.machine({self.W: (GE0, (g, GT0))}, raw)
        self.assertGreaterEqual(word(m, self.W, 1), 0.0)


if __name__ == "__main__":
    unittest.main()
