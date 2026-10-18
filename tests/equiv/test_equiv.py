"""Quick tests for tools/equiv.py. Pure-logic tests need nothing; end-to-end tests skip without game data.

  build/venv/bin/python -m unittest tests/equiv/test_equiv.py
"""
import os
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
equiv = __import__(os.environ.get("EQUIV_MODULE", "equiv"))  # noqa: E402
import mutate  # noqa: E402

HAVE_GAME = os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe")) and \
    os.path.exists(os.path.join(ROOT, "build/compilers/msvc7.1"))


class Logic(unittest.TestCase):
    def test_signature(self):
        s = equiv.parse_signature("?Add@V3@@QAEXPAV1@@Z")
        self.assertEqual((s["cc"], s["this"], s["ret"], s["params"]), ("thiscall", True, "void", ["ptr"]))
        s = equiv.parse_signature("?FUN_00011070@@YAXM@Z")
        self.assertEqual((s["cc"], s["ret"], s["params"]), ("cdecl", "void", ["f32"]))
        s = equiv.parse_signature("??0Foo@@QAE@XZ")
        self.assertEqual((s["ret"], s["params"]), ("ptr", []))
        s = equiv.parse_signature("?Get@A@@QBEMH_N@Z")
        self.assertEqual((s["ret"], s["params"]), ("f32", ["i32", "b8"]))
        self.assertEqual(equiv.parse_signature("_Foo@8")["params"], ["i32", "i32"])

    def test_x87_effects(self):
        prog_md = __import__("capstone").Cs(__import__("capstone").CS_ARCH_X86, __import__("capstone").CS_MODE_32)
        prog_md.detail = True

        def eff(code):
            ci = next(prog_md.disasm(code, 0))
            return equiv.Insn(ci, prog_md).x87
        self.assertEqual(eff(b"\xd9\xe8"), (0, 1))          # fld1
        self.assertEqual(eff(b"\xdd\xd8"), (1, -1))         # fstp st(0)
        self.assertEqual(eff(b"\xde\xc1"), (2, -1))         # faddp st(1)
        self.assertEqual(eff(b"\xd8\x05\0\0\0\0"), (1, 0))  # fadd dword [0]

    def test_decl_layout(self):
        self.assertEqual(equiv.decl_layout(equiv.parse_signature("?Add@V3@@QAEXPAV1@@Z")), (["ecx", "stack"], 4))
        self.assertEqual(equiv.decl_layout(equiv.parse_signature("?f@@YAHHHHPAX@Z")), (["stack"] * 4, 0))
        self.assertEqual(equiv.decl_layout(equiv.parse_signature("?f@@YIHHHH@Z")), (["ecx", "edx", "stack"], 4))

    def test_write_only_idioms(self):
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        md.detail = True
        prog = equiv.Program.__new__(equiv.Program)
        for code in (b"\x83\xca\xff", b"\x33\xd2", b"\x2b\xd2"):      # or edx,-1; xor edx,edx; sub edx,edx
            ci = next(md.disasm(code, 0))
            self.assertNotIn("edx", equiv.Program._regs_rw(prog, ci)[0])

    def test_mutants(self):
        src = "struct S { int a; int b; };\nint f(S* s, int x) {\n    g(x);\n    if (s->a < x)\n        return s->b - x;\n    return 3;\n}\n"
        m = mutate.mutants(src, None)
        self.assertIn("int f(S* s, int x) {\n    ;", m["dropcall"][0])
        self.assertTrue(any("x < s->a" in v for v in m["swap"]))
        self.assertTrue(any("s->a >= x" in v for v in m["flipcmp"]))
        self.assertTrue(any("return 4;" in v for v in m["const"]))
        self.assertTrue(any("int mut_pad_" in v for v in m["field"]))

    @unittest.skipUnless(hasattr(equiv, "_copy_overlap"), "round 8")
    def test_copy_overlap(self):
        # (round 8, overlap) memory: "abc\0" at 0x40000000, "xy\0" at 0x40000100, zeros elsewhere
        # (round 13: the only test of the rule since the regress cases on LIBCMT's strncat, 0x003468c0, are gone:
        # library code is never checked, and the rule applies only to a CRT copy routine under test)
        self.assertIn("_strncat", equiv.UB_COPY)
        mem = {0x40000000: b"abc\0", 0x40000100: b"xy\0"}

        def byte(a):
            for base, b in mem.items():
                if base <= a < base + len(b):
                    return b[a - base]
            return 0x41
        d, s = 0x40000000, 0x40000100
        self.assertFalse(equiv._copy_overlap("ncat", 1, [d, s, 10], byte))      # disjoint
        self.assertTrue(equiv._copy_overlap("ncat", 1, [d, d, 10], byte))       # strncat(d, d, n)
        self.assertTrue(equiv._copy_overlap("ncat", 1, [d, d + 2, 10], byte))   # src inside dest's string
        self.assertFalse(equiv._copy_overlap("ncat", 1, [d, d, 0], byte))       # count 0: nothing touched
        self.assertTrue(equiv._copy_overlap("ncpy", 1, [s - 1, s, 2], byte))    # dest runs into src
        self.assertFalse(equiv._copy_overlap("ncpy", 1, [s - 2, s, 2], byte))   # ends right before src

    @unittest.skipUnless(hasattr(equiv, "_char_adjust"), "round 9")
    def test_float_inversions(self):
        # (round 9, fprov) |x - c| < eps through fsub and fabs; c / x; a char minus a constant
        self.assertAlmostEqual(equiv._invert_fxf((("fsub", 1.5707964), ("fabs", None)), 0.5e-5), 1.5707964 + 0.5e-5)
        self.assertIsNone(equiv._invert_fxf((("fabs", None),), -1.0))
        self.assertAlmostEqual(equiv._invert_fxf((("fdivr", 2.0),), 4.0), 0.5)
        self.assertAlmostEqual(equiv._invert_fxf((("fdiv", 4.0),), 2.0), 8.0)
        self.assertEqual(equiv._char_adjust((("add", 0xFFFFFFAA),)), 0xFFFFFFAA)
        self.assertIsNone(equiv._char_adjust((("shr", 2),)))

    @unittest.skipUnless(hasattr(equiv, "_char_adjust"), "round 9")
    def test_fail_header_names_level(self):
        # (round 9) `level` is the highest level passed; a level-3 failure says so in the header
        rep = {"status": "fail", "symbol": "?f@@YAXXZ", "target": "FUN_00010000", "addr": "0x00010000", "level": 2,
               "failed_levels": [3], "time": 0}
        self.assertIn("fails level 3 (passes level 2)", equiv.render(rep).splitlines()[0])


@unittest.skipUnless(HAVE_GAME, "needs isos/extracted and the MSVC toolchain")
class EndToEnd(unittest.TestCase):
    def test_match_is_equivalent(self):
        r = equiv.verify(os.path.join(ROOT, "matches/0x000110d0.cpp"), 0x110D0, n_inputs=16, max_inputs=16)
        self.assertEqual(r["status"], "equivalent", r)
        self.assertEqual(r["level"], 3)

    def test_wrong_operand_fails(self):
        src = open(os.path.join(ROOT, "matches/0x000110f0.cpp")).read().replace("z -= other->z", "z += other->z")
        with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as d:
            p = os.path.join(d, "m.cpp")
            open(p, "w").write(src)
            r = equiv.verify(p, 0x110F0, n_inputs=32, max_inputs=32)
        self.assertEqual(r["status"], "fail")
        self.assertTrue(r["level3"]["mismatches"])

    def test_env_seed_past_inputs(self):
        # (round 8) EQUIV_SEEDS=N runs seed N even when --inputs is smaller (it reported unsupported)
        old = set(equiv.ONLY_SEEDS)
        equiv.ONLY_SEEDS.clear()
        equiv.ONLY_SEEDS.add(300)
        try:
            r = equiv.verify(os.path.join(ROOT, "matches/0x000110d0.cpp"), 0x110D0, n_inputs=16, max_inputs=16)
        finally:
            equiv.ONLY_SEEDS.clear()
            equiv.ONLY_SEEDS.update(old)
        self.assertGreaterEqual(r["level3"]["inputs_run"], 1, r)

    def test_other_flags_still_equivalent(self):
        r = equiv.verify(os.path.join(ROOT, "matches/0x000110d0.cpp"), 0x110D0, flags=["/Oy-"], n_inputs=16,
                         max_inputs=16)
        self.assertEqual(r["status"], "equivalent", r)


if __name__ == "__main__":
    unittest.main()
