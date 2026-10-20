"""Tests for tools/d3d_ff.py: the fixed-function reference and the proof of vs_vp_ff.sc against it.

    build/venv/bin/python -m unittest discover -s tests/shaders -v

The reference tests need nothing; the proofs need bgfx's shaderc (`tools/native_gfx.py fetch` + `shaderc`).
"""
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import d3d_ff  # noqa: E402

FIX = os.path.join(os.path.dirname(__file__), "fixtures")
HAVE_TOOLS = os.path.exists(os.path.join(ROOT, "build/third_party/tools/shaderc")) and os.path.exists(
    os.path.join(ROOT, "build/third_party/src/bgfx/3rdparty/spirv-headers/include/spirv/unified1/"
                       "spirv.core.grammar.json"))
IDENT = [1.0 if i % 5 == 0 else 0.0 for i in range(16)]
POINTS = {"lit-spec-points", "lit-scaled", "lit-nonuniform", "layered-reflect"}


def state(**kw):
    st = dict(world=list(IDENT), proj=list(IDENT), lighting=True, specular=False, normalize=False,
              material=dict(diffuse=0xff808080, ambient=0xff404040, specular=0xffffffff, emissive=0xff102030,
                            power=0.0),
              ambient=0xff202020, lights=[], stages=[(s, 0) for s in range(4)], texmats=[list(IDENT)] * 3)
    st.update(kw)
    return st


def vertex(**kw):
    v = dict(position=[0.0, 0.0, 10.0], normal=[0.0, 0.0, -1.0], colour0=0xff00ff00, colour1=0,
             uv=[[0.25, 0.5]] * 4)
    v.update(kw)
    return v


class Reference(unittest.TestCase):
    def test_lit_ignores_the_vertex_colour(self):
        # emissive + ambient material x ambient light + diffuse material x light x N.L (a light straight on)
        L = dict(on=True, type=d3d_ff.D3D_DIRECTIONAL, diffuse=[1.0, 0.5, 0.25, 1.0], direction=[0, 0, 2.0],
                 position=[0, 0, 0], range=0, att=[0, 0, 0])
        out, amb = d3d_ff.reference(state(lights=[L]), vertex())
        want = [e / 255 + (0x40 / 255) * (0x20 / 255) + (0x80 / 255) * c
                for e, c in ((0x10, 1.0), (0x20, 0.5), (0x30, 0.25))]
        for got, w in zip(out["oD0"][0][:3], want):
            self.assertAlmostEqual(got, w, places=12)
        self.assertEqual(out["oD0"][0][3], 1.0)                # the diffuse material's alpha
        self.assertEqual(amb, [])

    def test_unlit_passes_the_vertex_colour(self):
        out, _ = d3d_ff.reference(state(lighting=False), vertex())
        self.assertEqual(out["oD0"][0], [0.0, 1.0, 0.0, 1.0])

    def test_normals_are_not_renormalised(self):
        # a world scaled by 2: the inverse transpose halves the normal; N.L = 0.5
        w = [2.0 if i % 5 == 0 and i < 15 else 0.0 for i in range(16)]
        w[15] = 1.0
        L = dict(on=True, type=d3d_ff.D3D_DIRECTIONAL, diffuse=[1.0, 1.0, 1.0, 1.0], direction=[0, 0, 1.0],
                 position=[0, 0, 0], range=0, att=[0, 0, 0])
        st = state(world=w, lights=[L], material=dict(diffuse=0xffffffff, ambient=0, specular=0, emissive=0,
                                                      power=0.0), ambient=0)
        out, _ = d3d_ff.reference(st, vertex())
        self.assertAlmostEqual(out["oD0"][0][0], 0.5, places=12)
        st["normalize"] = True
        out, _ = d3d_ff.reference(st, vertex())
        self.assertAlmostEqual(out["oD0"][0][0], 1.0, places=12)

    def test_uv_transform_uses_the_third_row(self):
        m = list(IDENT)
        m[8], m[9] = 0.5, 0.25                                 # row 3: the translation of 2D coordinates
        st = state(lighting=False, stages=[(0, 2)] + [(s, 0) for s in range(1, 4)], texmats=[m, IDENT, IDENT])
        out, _ = d3d_ff.reference(st, vertex())
        self.assertEqual(out["oT0"][0], [0.75, 0.75])


@unittest.skipUnless(HAVE_TOOLS, "needs bgfx's shaderc (tools/native_gfx.py fetch, shaderc)")
class Proofs(unittest.TestCase):
    def test_vs_vp_ff_is_equivalent(self):
        rep = d3d_ff.prove(n_inputs=300, quick=True)
        self.assertEqual(rep["status"], "equivalent", d3d_ff.text_report(rep))
        self.assertEqual(len(rep["configs"]), len(d3d_ff.CONFIGS))

    def test_two_sided_variant_front_and_back(self):
        src = os.path.join(ROOT, "src/platform/sdl/pddi/shaders/vp/vs_vp_ff2s.sc")
        rep = d3d_ff.prove(src, n_inputs=300, quick=True)
        self.assertEqual(rep["status"], "equivalent", d3d_ff.text_report(rep))
        lit = [c for c in rep["configs"] if c["config"] == "lit-spec-points"][0]
        self.assertGreater(lit["compared"].get("oB0.x", 0), 200)        # the back colours are compared

    def test_wrong_attenuation_fails_the_point_light_configurations(self):
        rep = d3d_ff.prove(os.path.join(FIX, "vs_wrong_ff.sc"), n_inputs=300, quick=True)
        failed = {c["config"] for c in rep["configs"] if c["status"] == "fail"}
        self.assertEqual(failed, POINTS)


if __name__ == "__main__":
    unittest.main()
