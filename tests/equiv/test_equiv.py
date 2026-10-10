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

    def test_other_flags_still_equivalent(self):
        r = equiv.verify(os.path.join(ROOT, "matches/0x000110d0.cpp"), 0x110D0, flags=["/Oy-"], n_inputs=16,
                         max_inputs=16)
        self.assertEqual(r["status"], "equivalent", r)


if __name__ == "__main__":
    unittest.main()
