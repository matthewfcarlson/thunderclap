#!/usr/bin/env python3
"""tools/equiv.py SNPRINTF_MODELS (integ10, D181; rev5): FUN_000964a0 run as MSVC's _vsnprintf plus the wrapper's
terminator. The format engine against C's rules (Python's % operator follows them for these conversions, apart from a
zero precision of a zero, checked by hand), the length cases and the fallbacks."""
import itertools
import os
import struct
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import equiv  # noqa: E402

M32 = 0xFFFFFFFF


def fmt(f, *words, strings=None):
    it = iter(words)
    strings = strings or {}

    def cstr(a, lim):
        s_ = strings[a]
        return s_ if lim is None else s_[:lim]
    return equiv._fmt_msvc(f.encode(), lambda: next(it) & M32, cstr)


class Format(unittest.TestCase):
    def test_ints_against_c(self):
        vals = [0, 1, -1, 7, 42, -42, 123456, -2147483648, 2147483647]
        for fl, w, p, conv in itertools.product(["", "-", "+", " ", "0", "#", "-+", "+0", " 0"], ["", "1", "8"],
                                                ["", ".0", ".3", ".12"], "diuxX"):
            spec = "%" + fl + w + p + conv
            for v in vals:
                pv = v if conv in "di" else v & M32
                fl_ = fl
                if conv in "uxX":
                    fl_ = fl_.replace("+", "").replace(" ", "")      # (C: no sign for an unsigned conversion)
                if p:
                    fl_ = fl_.replace("0", "")                        # (C: a precision turns the 0 flag off)
                if v == 0:
                    fl_ = fl_.replace("#", "")                        # (C: no 0x prefix on a zero)
                pspec = "%" + fl_ + w + p + ("d" if conv == "i" else conv)
                if p == ".0" and v == 0:
                    # C: a zero precision of a zero prints no digits (Python prints 0)
                    sign = ("+" if "+" in fl_ else " " if " " in fl_ else "") if conv in "di" else ""
                    exp = sign.ljust(int(w or 0)) if "-" in fl_ else sign.rjust(int(w or 0))
                else:
                    exp = pspec % pv
                self.assertEqual(fmt(spec, v), exp.encode(), (spec, v))

    def test_int_min_and_h(self):
        self.assertEqual(fmt("%d", 0x80000000), b"-2147483648")
        self.assertEqual(fmt("%hd", 0x1234ffff), b"-1")
        self.assertEqual(fmt("%hu", 0x1234ffff), b"65535")
        self.assertEqual(fmt("%ld|%lx", 5, 255), b"5|ff")

    def test_star(self):
        self.assertEqual(fmt("%*d", 5, 42), b"   42")
        self.assertEqual(fmt("%*d", -5 & M32, 42), b"42   ")                 # (a negative width: left-justified)
        self.assertEqual(fmt("%.*d", 4, 42), b"0042")
        self.assertEqual(fmt("%.*d", -1 & M32, 42), b"42")                   # (a negative precision: none)

    def test_c_s_percent(self):
        self.assertEqual(fmt("a%cb", 0), b"a\0b")                            # (%c of 0 writes a NUL, counted)
        self.assertEqual(fmt("%3c|%-3c|", 0x41, 0x42), b"  A|B  |")
        self.assertEqual(fmt("%s|%.2s|%5s|%-5.1s|", 1, 1, 1, 1, strings={1: b"abc"}), b"abc|ab|  abc|a    |")
        self.assertEqual(fmt("%s|%.3s", 0, 0), b"(null)|(nu")
        self.assertEqual(fmt("100%%"), b"100%")
        self.assertEqual(fmt("comic_book_selector_%d", 3), b"comic_book_selector_3")

    def test_fallbacks(self):
        for f in ("%f", "%e", "%g", "%p", "%n", "%o", "%I64d", "%S", "%ls", "abc%"):
            self.assertIsNone(fmt(f, 1, 2, 3), f)

    def test_fault(self):
        def bad():
            raise equiv.Fault("intrinsic_access")
        with self.assertRaises(equiv.Fault):           # (the model catches it and keeps the generic stub)
            equiv._fmt_msvc(b"%d", bad, None)


class Effect(unittest.TestCase):
    def test_lengths(self):
        self.assertEqual(equiv._snprintf_effect(b"abc", 8), (b"abc\0", 3))           # len < n
        self.assertEqual(equiv._snprintf_effect(b"abcd", 4), (b"abcd", 4))           # len == n: no NUL
        self.assertEqual(equiv._snprintf_effect(b"abcdef", 4), (b"abc\0", M32))     # len > n: -1, NUL at n-1
        self.assertEqual(equiv._snprintf_effect(b"abc", 0), (b"", M32))              # n = 0
        self.assertEqual(equiv._snprintf_effect(b"", 0), (b"", 0))
        self.assertEqual(equiv._snprintf_effect(b"abc", -3), (b"", M32))             # (the wrapper's jle)


class Digest(unittest.TestCase):
    def test_xbe_bytes(self):
        try:
            p = equiv.Program.get()
        except Exception as e:     # noqa: BLE001
            raise unittest.SkipTest("no XBE: %s" % e)
        import hashlib
        self.assertEqual(hashlib.sha1(p.read(0x964a0, 47)).hexdigest(), equiv.SNPRINTF_MODELS[0x964a0])


if __name__ == "__main__":
    unittest.main()
