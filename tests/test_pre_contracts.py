"""(integ3, D152) Range contracts: the callee index (argN -> stack word, __thiscall members and doubles) and the
pre_violation_in_original check over a run's call records; macro/item agreement and the subject rule."""
import os
import struct
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tools"))
import equiv  # noqa: E402

TU = """\
// 0x00010000 FUN_00010000 (10 B): equivalent
// pre: ge(arg2, 0) range(arg3, 0, 7)
float __cdecl FUN_00010000(double d, float dt, int n) {
    HULK_PRE_GE(dt, 0.0f);
    HULK_PRE_RANGE(n, 0, 7);
    return dt;
}

// 0x00010100 Thing::Step (20 B): equivalent
// pre: gt(arg1, 0)
void Thing::Step(float tau) {
    HULK_PRE_GT(tau, 0.0f);
}
"""


def f(x):
    return (struct.unpack("<I", struct.pack("<f", x))[0], None)


class Index(unittest.TestCase):
    def test_words(self):
        idx = equiv.contracts_of_text(TU)
        # FUN_00010000: the double takes words 0-1, dt word 2 (float), n word 3 (int)
        self.assertEqual([(w, ww, c[5]) for w, ww, c in idx[0x10000]], [(2, 4, "f"), (3, 4, "i")])
        # Thing::Step is __thiscall: this in ecx, tau the first stack word
        self.assertEqual([(w, ww, c[5]) for w, ww, c in idx[0x10100]], [(0, 4, "f")])


class Violation(unittest.TestCase):
    def setUp(self):
        self.idx = equiv.contracts_of_text(TU)

    def call(self, target, args):
        return {"target": target, "args": args}

    def test_out_of_range_found(self):
        calls = [self.call(0x10000, [(0, None), (0, None), f(-1.0), (3, None)])]
        self.assertIn("0x00010000 word 2", equiv.pre_arg_violation(calls, self.idx))
        calls = [self.call(0x10000, [(0, None), (0, None), f(1.0), (8, None)])]
        self.assertIn("word 3", equiv.pre_arg_violation(calls, self.idx))

    def test_in_range_clean(self):
        calls = [self.call(0x10000, [(0, None), (0, None), f(0.0), (7, None)]), self.call(0x10100, [f(0.5)])]
        self.assertIsNone(equiv.pre_arg_violation(calls, self.idx))

    def test_thiscall_and_nan(self):
        self.assertIsNotNone(equiv.pre_arg_violation([self.call(0x10100, [f(0.0)])], self.idx))   # gt: 0 is outside
        self.assertIsNotNone(equiv.pre_arg_violation([self.call(0x10100, [(0x7FC00000, None)])], self.idx))  # NaN

    def test_other_callee_ignored(self):
        self.assertIsNone(equiv.pre_arg_violation([self.call(0x20000, [f(-5.0)])], self.idx))


class Macros(unittest.TestCase):
    def test_agreement_and_subject(self):
        code = "float __cdecl F(double d, float dt, int n) { HULK_PRE_GE(dt, 0.0f); HULK_PRE_RANGE(n, 0, 7); }"
        got, bad = equiv._pre_range_macros(code)
        self.assertEqual(bad, [])
        self.assertEqual(got, {(2, ("range", 0.0, float("inf"), True, True)), (3, ("range", 0.0, 7.0, True, True))})
        _, bad = equiv._pre_range_macros("float F(float a, float b) { HULK_PRE_GE(a + b, 0.0f); }")
        self.assertTrue(bad and "pre_macro_subject" in bad[0])
        _, bad = equiv._pre_range_macros("float F(float a) { HULK_PRE_GE(x, 0.0f); }")
        self.assertTrue(bad and "not a parameter" in bad[0])


if __name__ == "__main__":
    unittest.main()
