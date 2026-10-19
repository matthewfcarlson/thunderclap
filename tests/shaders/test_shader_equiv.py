"""Tests for tools/shader_equiv.py: the SPIR-V interpreter and the equivalence verdicts.

    build/venv/bin/python -m unittest discover -s tests/shaders -v

The verdict tests need bgfx's shaderc (`tools/native_gfx.py fetch` + `shaderc`); the two game-program proofs also
need the player's XBE. Each skips when its prerequisite is missing.
"""
import math
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
FIX = os.path.join(os.path.dirname(__file__), "fixtures")
VP = os.path.join(ROOT, "src/platform/sdl/pddi/shaders/vp")

HAVE_GRAMMAR = os.path.exists(os.path.join(ROOT, "build/third_party/src/bgfx/3rdparty/spirv-headers/include/spirv/"
                                                 "unified1/spirv.core.grammar.json"))
if HAVE_GRAMMAR:
    import shader_equiv as se  # noqa: E402
    HAVE_SHADERC = os.path.exists(se.SHADERC)
else:
    HAVE_SHADERC = False
HAVE_XBE = os.path.exists(os.path.join(ROOT, "isos/extracted/default.xbe"))
N = 300                       # vertices per verdict test (the tool's default is 600)


def _read(path):
    with open(path) as f:
        return f.read()


@unittest.skipUnless(HAVE_GRAMMAR, "needs bgfx's sources (tools/native_gfx.py fetch)")
class Interpreter(unittest.TestCase):
    def test_undefined_results_are_nan_and_recorded(self):
        del se._UB[:]
        self.assertTrue(math.isnan(se._ext("Pow", [0.0, -1.0])))
        self.assertTrue(math.isnan(se._ext("InverseSqrt", [0.0])))
        self.assertTrue(math.isnan(se._ext("FMax", [float("nan"), 1.0])))
        self.assertEqual(se._ext("FMax", [(1.0, -2.0), (0.5, 0.0)]), (1.0, 0.0))
        self.assertEqual(len(se._UB), 3)

    def test_float32_rounding(self):
        self.assertEqual(se._FBIN["OpFAdd"](1.0, 2.0 ** -30), 1.0)
        self.assertEqual(se._dot((1.0, 2.0, 3.0), (4.0, 5.0, 6.0)), 32.0)
        self.assertEqual(se._ext("InverseSqrt", [4.0]), 0.5)

    def test_annotations(self):
        ann = se.parse_annotations(_read(os.path.join(FIX, "vs_synth.sc")))
        self.assertEqual(ann["program"], "synth.vp")
        self.assertEqual(ann["inputs"]["a_indices"], dict(reg=1, kind="index:2:4", bgra=False, comps=None))
        self.assertEqual(ann["uniforms"], {"u_vc": 96})
        self.assertEqual(ann["consts"][0], dict(lo=96, hi=96, kind="fixed", args=[0.0, 0.5, 256.0, 1.0]))


@unittest.skipUnless(HAVE_SHADERC, "needs bgfx's shaderc (tools/native_gfx.py shaderc)")
class Verdicts(unittest.TestCase):
    def check(self, src, status, program=None, first=None):
        rep = se.verify(src, program, n_inputs=N, profiles=["spirv"])
        self.assertEqual(rep["status"], status, se.text_report(rep))
        if first:
            self.assertEqual(rep["level3"]["mismatches"][0]["diffs"][0]["output"][:len(first)], first)
        return rep

    def test_synthetic_program_equivalent(self):
        rep = self.check(os.path.join(FIX, "vs_synth.sc"), "equivalent")
        l3 = rep["level3"]
        self.assertEqual(l3["never_compared"], [])
        self.assertGreater(l3["colour_unclamped"]["oD0.x"], 50)        # the clamp does not hide the colour

    def test_synthetic_wrong_variant_fails(self):
        # ">" for sge's ">=": only the fuzzed vertices with u exactly 0.5 tell them apart
        self.check(os.path.join(FIX, "vs_synth_wrong.sc"), "fail", first="oT0")

    def test_all_profiles_compile(self):
        rep = se.verify(os.path.join(FIX, "vs_synth.sc"), n_inputs=60)
        self.assertEqual(set(rep["level1"]["profiles"]), set(se.PROFILES))
        self.assertTrue(rep["level1"]["ok"], rep["level1"])

    def test_missing_output_is_an_interface_error(self):
        # the synthetic program writes oFog; a shader built against it without v_fog cannot be equivalent
        src = _read(os.path.join(FIX, "vs_synth.sc"))
        src = src.replace("$output v_color0, v_fog, v_texcoord0", "$output v_color0, v_texcoord0")
        src = src.replace("    v_fog = dot(a_normal, a_normal) * (1.0 / u_vc[9].x);\n", "")
        tmp = os.path.join(ROOT, "build/shaders/test-tmp")
        os.makedirs(tmp, exist_ok=True)
        path = os.path.join(tmp, "vs_nofog.sc")
        with open(path, "w") as f:
            f.write(src.replace("nv2a-program: synth.vp", "nv2a-program: " + os.path.join(FIX, "synth.vp")))
        with open(os.path.join(FIX, "varying.def.sc")) as f, open(os.path.join(tmp, "varying.def.sc"), "w") as g:
            g.write(f.read())
        rep = se.verify(path, n_inputs=20, profiles=["spirv"])
        self.assertEqual(rep["status"], "interface_error")
        self.assertTrue(any("oFog" in i for i in rep["level2"]["issues"]), rep["level2"])


@unittest.skipUnless(HAVE_SHADERC and HAVE_XBE, "needs shaderc and the player's XBE")
class GameProofs(unittest.TestCase):
    """The two hand-written game-program shaders, and a deliberately wrong variant of each."""

    def run_one(self, src):
        return se.verify(src, n_inputs=N, profiles=["spirv"])

    def test_simple_proximity(self):
        rep = self.run_one(os.path.join(VP, "vs_vp_simple_proximity.sc"))
        self.assertEqual(rep["status"], "equivalent", se.text_report(rep))

    def test_skin_onebone(self):
        rep = self.run_one(os.path.join(VP, "vs_vp_skin_onebone.sc"))
        self.assertEqual(rep["status"], "equivalent", se.text_report(rep))

    def test_wrong_simple_proximity_fails(self):
        rep = self.run_one(os.path.join(FIX, "vs_wrong_simple_proximity.sc"))
        self.assertEqual(rep["status"], "fail")
        self.assertTrue(rep["level3"]["mismatches"][0]["diffs"][0]["output"].startswith("oD0"))

    def test_wrong_skin_onebone_fails(self):
        rep = self.run_one(os.path.join(FIX, "vs_wrong_skin_onebone.sc"))
        self.assertEqual(rep["status"], "fail")
        first = rep["level3"]["mismatches"][0]
        self.assertTrue(first["diffs"][0]["output"].startswith("oD1"))
        self.assertTrue(any(u.startswith("pow(0.0") for u in first.get("undefined", [])))


if __name__ == "__main__":
    unittest.main()
