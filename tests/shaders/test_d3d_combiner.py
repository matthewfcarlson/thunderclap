"""Tests for tools/d3d_combiner.py: the texture-stage reference and the proof of the 100 combiner programs.

    build/venv/bin/python -m unittest discover -s tests/shaders -v

The reference tests need nothing; the proofs need bgfx's shaderc (`tools/native_gfx.py fetch` + `shaderc`).
"""
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import d3d_combiner as dc  # noqa: E402

FIX = os.path.join(os.path.dirname(__file__), "fixtures")
HAVE_TOOLS = os.path.exists(os.path.join(ROOT, "build/third_party/tools/shaderc")) and os.path.exists(
    os.path.join(ROOT, "build/third_party/src/bgfx/3rdparty/spirv-headers/include/spirv/unified1/"
                       "spirv.core.grammar.json"))
N = 40


def pixel(**kw):
    px = dict(diffuse=[0.5, 0.25, 1.0, 0.5], specular=[0.1, 0.2, 0.3, 0.0], tfactor=[1.0, 0.0, 0.0, 0.25],
              texels=[[0.2, 0.4, 0.6, 0.8]] * 4, spec_add=False, alpha_cmp=-1, alpha_ref=0.0, fog_on=False,
              fog_colour=[0, 0, 0, 0], fog_start=0.0, fog_end=1.0, fog=0.0)
    px.update(kw)
    return px


class Reference(unittest.TestCase):
    def test_modulate_texture_diffuse(self):
        out, _ = dc.reference([(4, 2, 0, 4, 2, 0, 1)], pixel())
        self.assertEqual(out, [0.1, 0.1, 0.6, 0.4])

    def test_temp_result_and_blendfactoralpha(self):
        # stage 0 -> temp = texture; stage 1: current = temp x 0.25 + diffuse x 0.75 (factor alpha)
        st = [(2, 2, 0, 2, 2, 0, 5), (15, 5, 0, 2, 0, 0, 1)]
        out, _ = dc.reference(st, pixel())
        for got, want in zip(out[:3], [0.2 * 0.25 + 0.5 * 0.75, 0.4 * 0.25 + 0.25 * 0.75, 0.6 * 0.25 + 0.75]):
            self.assertAlmostEqual(got, want, places=12)

    def test_complement_and_alpha_replicate(self):
        out, _ = dc.reference([(2, 2 | 0x10, 0, 2, 2, 0, 1)], pixel())
        self.assertEqual([round(x, 12) for x in out[:3]], [0.8, 0.6, 0.4])
        out, _ = dc.reference([(2, 2 | 0x20, 0, 2, 2, 0, 1)], pixel())
        self.assertEqual(out[:3], [0.8, 0.8, 0.8])

    def test_alpha_test_discards(self):
        out, _ = dc.reference([(2, 2, 0, 2, 2, 0, 1)], pixel(alpha_cmp=4, alpha_ref=250.0))   # greater: 204 > 250
        self.assertIsNone(out)


@unittest.skipUnless(HAVE_TOOLS, "needs bgfx's shaderc (tools/native_gfx.py fetch, shaderc)")
class Proofs(unittest.TestCase):
    def test_every_key_is_equivalent(self):
        rep = dc.prove(n_inputs=N)
        self.assertEqual(rep["status"], "equivalent", dc.text_report(rep))
        self.assertEqual(len(rep["keys"]), 100)

    def test_wrong_op_20_fails_its_keys(self):
        rep = dc.prove(n_inputs=N, stage_sh=os.path.join(FIX, "fs_wrong_vp_stage.sh"))
        for k in rep["keys"]:
            uses = "c20." in k["key"]
            for w in ("generated", "generic"):
                self.assertEqual(k[w]["status"], "fail" if uses else "equivalent", (k["key"], w))


if __name__ == "__main__":
    unittest.main()
