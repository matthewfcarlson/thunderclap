"""Tests for tools/lint_floats.py. The literal scanner needs nothing; the constant check needs the game files.

  build/venv/bin/python -m unittest tests/equiv/test_lint_floats.py
"""
import os
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import lint_floats  # noqa: E402

HAVE_GAME = os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe"))


class Scanner(unittest.TestCase):
    def test_literals(self):
        src = 'int a = 0x1f; float b = 0.0174533f; double c = 1e-3; int d = 7; // 9.9f\n/* 8.8f */ char *s = "1.5f"; float e = .5f;\n'
        got = [(ln, sp) for ln, sp, _, _ in lint_floats.literals(src)]
        self.assertEqual(got, [(1, "0.0174533f"), (1, "1e-3"), (2, ".5f")])

    def test_spelling(self):
        self.assertEqual(lint_floats.spell(lint_floats.f32(999999.0), 4), "999999.0f")
        self.assertEqual(lint_floats.spell(lint_floats.f32(0.0174532924), 4), "0.017453292f")


@unittest.skipUnless(HAVE_GAME, "needs isos/extracted/default.xbe")
class Constants(unittest.TestCase):
    def lint(self, text, addr):
        orig = lint_floats.Orig()
        with tempfile.NamedTemporaryFile("w", suffix=".cpp", delete=False) as f:
            f.write(text)
        try:
            return lint_floats.lint_source(orig, f.name, addr, 1e-3)
        finally:
            os.unlink(f.name)

    def test_known_cases(self):
        # equivalent/0x000d6b20.cpp before fx19: pi/180 rounded to 6 digits (the original loads 0x3c8efa35)
        r = self.lint("float f(float x) { return x * 0.0174533f; }\n", 0x000d6b20)
        self.assertEqual([i["suggest"] for i in r["issues"]], ["0.017453292f"])
        r = self.lint("float f(float x) { return x * 0.017453292f; }\n", 0x000d6b20)
        self.assertEqual(r["issues"], [])
        # equivalent/0x00204c10.cpp before fx19: the original's initial best distance is 999999.0f
        r = self.lint("float f(bool n) { return n ? 1000000.0f : -1000000.0f; }\n", 0x00204c10)
        self.assertEqual({i["suggest"] for i in r["issues"]}, {"999999.0f"})
        r = self.lint("float f(bool n) { return n ? 999999.0f : -999999.0f; }\n", 0x00204c10)
        self.assertEqual(r["issues"], [])


if __name__ == "__main__":
    unittest.main()
