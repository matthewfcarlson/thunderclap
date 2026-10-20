"""Tests for tools/xps.py: the ps.1.1 / xps.1.1 interpreter and the proof of shaders/fx/ against it.

    build/venv/bin/python -m unittest discover -s tests/shaders -v

The interpreter tests need nothing; the proofs need bgfx's shaderc and the host smoke binary (`tools/native_gfx.py
pddi`, for the filter program's parameters); the threshold program needs the player's XBE.
"""
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import xps  # noqa: E402

FIX = os.path.join(os.path.dirname(__file__), "fixtures", "fx")
HAVE_GRAMMAR = os.path.exists(os.path.join(ROOT, "build/third_party/src/bgfx/3rdparty/spirv-headers/include/spirv/"
                                                 "unified1/spirv.core.grammar.json"))
HAVE_TOOLS = HAVE_GRAMMAR and os.path.exists(os.path.join(ROOT, "build/third_party/tools/shaderc")) and \
    os.path.exists(xps.SMOKE)
HAVE_XBE = os.path.exists(xps.XBE_PATH)
N = 300


class Interpreter(unittest.TestCase):
    def run_text(self, text, tex, consts, quantise=True):
        return xps.run(xps.Program(text), tex, consts, quantise).out

    def test_constants_are_8_bit(self):
        out = self.run_text("ps.1.1\ntex t0\nmul r0, t0, c0\n", {0: [1, 1, 1, 1]}, {0: [0.3, 0.5, 2.0, -1]})
        self.assertEqual(out, [77 / 255, 128 / 255, 1.0, 0.0])

    def test_every_instruction_clamps_to_plus_minus_one(self):
        # mul_x4 of 1 x 1 = 4 -> 1; then add -1 = 0 (not 3)
        out = self.run_text("ps.1.1\ndef c1, -1, -1, -1, -1\ntex t0\nmul_x4 r0, t0, c0\nadd r0, r0, c1\n",
                            {0: [1, 1, 1, 1]}, {0: [1, 1, 1, 1]})
        self.assertEqual(out, [0.0] * 4)

    def test_co_issue_reads_before_the_pair(self):
        # add r0.xyz uses r1.w before the co-issued doubling; the next add sees it doubled
        text = ("xps.1.1\ndef c1, 0.25, 0.25, 0.25, 0.25\ntex t0\nmov r0, c2\nmov r1.w, c1\n"
                "add r0.xyz, r0.xyz, r1.w\n+mov_x2 r1.w, r1.w\nadd r0.xyz, r0.xyz, r1.w\n")
        out = self.run_text(text, {0: [0, 0, 0, 0]}, {2: [0, 0, 0, 0]})
        self.assertEqual(out[:3], [0.75] * 3)

    def test_dp3_replicates_into_alpha_and_bx2(self):
        # r0.a = (t0 . c0) / 2; add c5_bx2 (2 x 1 - 1 = 1) -> saturated output 1
        text = "xps.1.1\ntex t0\ndp3_d2 r0, t0, c0\n"
        out = self.run_text(text, {0: [1, 1, 0, 0]}, {0: [1, 1, 1, 1]})
        self.assertEqual(out, [1.0, 1.0, 1.0, 1.0])
        out = self.run_text(text + "add r0, r0, c5_bx2\n", {0: [0.2, 0, 0, 0]}, {0: [1, 1, 1, 1], 5: [0, 0, 0, 0]},
                            quantise=False)
        self.assertEqual(out, [0.0] * 4)                    # 0.1 - 1 -> clamped to 0 at the output

    def test_cnd_is_strictly_greater(self):
        text = "xps.1.1\ndef c2, 0, 0, 0, 0\ndef c3, 1, 1, 1, 1\ndef c4, 0.5, 0.5, 0.5, 0.5\ntex t0\n" \
               "mov r0, c4\ncnd r0, r0.a, c3, c2\n"
        r = xps.run(xps.Program(text), {0: [0] * 4}, {})
        self.assertEqual(r.out, [0.0] * 4)
        self.assertEqual(r.margin, 0.0)                     # flagged: the proof does not compare it

    def test_filter_text_follows_the_rules(self):
        # level 64, side 1: mov_x4 with mul_x2, mov_x2 with the first mad, three adds with two doublings
        t = xps.filter_program(64, 1)
        self.assertIn("+mov_x4", t)
        self.assertEqual(t.count("add     r0.xyz, r0.xyz, r1.w"), 4)
        self.assertEqual(t.count("+mov_x2"), 3)
        p = xps.Program(t)
        self.assertEqual(p.version, "xps.1.1")
        self.assertEqual(p.constants(), [0, 3, 5, 6, 7])

    def test_undefined_bx2_is_reported(self):
        r = xps.run(xps.Program("ps.1.1\ntex t0\nmov r0, t0_bx2\n"), {0: [1.5, 0, 0, 0]}, {})
        self.assertTrue(r.undefined)


@unittest.skipUnless(HAVE_TOOLS, "needs shaderc and the host pddi_smoke (tools/native_gfx.py fetch/shaderc/pddi)")
class Proofs(unittest.TestCase):
    def prove(self, **kw):
        only = None if HAVE_XBE else [n for n in xps.programs(with_threshold=False)]
        return xps.prove(n_inputs=N, quick=True, only=only, **kw)

    def test_translations_are_equivalent(self):
        rep = self.prove()
        self.assertEqual(rep["status"], "equivalent", xps.text_report(rep))
        self.assertEqual(len(rep["programs"]), 20 if HAVE_XBE else 19)
        for p in rep["programs"]:
            if p["program"] != "threshold":
                self.assertGreater(p["inside_0_1"], 100, p["program"])   # outputs not all saturated

    def test_wrong_filter_fails(self):
        rep = self.prove(filter_src=os.path.join(FIX, "fs_wrong_fx_filter.sc"))
        failed = {p["program"] for p in rep["programs"] if p["status"] == "fail"}
        self.assertIn("filter-1-0", failed)
        self.assertFalse(any(n.startswith("blur") for n in failed))

    def test_wrong_blur_fails_only_four_taps(self):
        rep = self.prove(blur_src=os.path.join(FIX, "fs_wrong_fx_blur.sc"))
        failed = {p["program"] for p in rep["programs"] if p["status"] == "fail"}
        self.assertEqual(failed, {"blur4"})


if __name__ == "__main__":
    unittest.main()
