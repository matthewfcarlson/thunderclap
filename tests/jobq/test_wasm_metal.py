"""Metal tests of tools/wasm_build_job.py (wqgpu1): the --test spec parser, the shot comparison and the stats reader of
the host runner (tools/wasm_build_run.py). No hosts, GPU or game data needed.

  build/venv/bin/python -m unittest tests.jobq.test_wasm_metal     (from the repo root)
"""
import os
import shutil
import struct
import sys
import tempfile
import unittest

TMP = tempfile.mkdtemp(prefix="wbmetal-test-")
os.environ["JOBQ_DIR"] = TMP
os.environ["JOBQ_NO_DAEMON"] = "1"
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import wasm_build_job as wbj  # noqa: E402
import wasm_build_run as wbr  # noqa: E402


def tga(path, w, h, fill):
    with open(path, "wb") as f:
        f.write(bytes([0, 0, 2]) + bytes(9) + struct.pack("<HHBB", w, h, 32, 0x20) + bytes(fill) * (w * h))


class Parse(unittest.TestCase):
    def test_metal_specs(self):
        t = wbj.parse_tests(["metal:4100:4000,1500,1500", "x=metal-input:900", "metal-ab:3000"],
                            ["HULK_LIGHT_AB=30"], 600)
        self.assertEqual([(x["kind"], x["name"], x["frames"], x["shots"]) for x in t],
                         [("metal", "metal-4100-4000_1500_1500", 4100, [1500, 4000]), ("metal-input", "x", 900, []),
                          ("metal-ab", "metal-ab-3000", 3000, [])])
        self.assertEqual(t[0]["env"], {"HULK_LIGHT_AB": "30"})

    def test_refused(self):
        for specs, env in ((["metal:100:90"], []),                      # a shot too close to the end
                           (["metal:4000:" + ",".join(str(i) for i in range(1, 70))], []),   # over 64 shots
                           (["metal:4000:1,x"], []), (["metal"], []), (["metal-ab:3000:100"], []),
                           (["metal-ab:3000"], []), (["metal-ab:3000"], ["HULK_LIGHT_AB=0"]),   # no pass to time
                           (["metal:4000"], ["HULK_GFX_SHOT_GAME=5"]), (["metal:4000", "metal:4000"], [])):
            with self.assertRaises(SystemExit, msg=specs):
                wbj.parse_tests(specs, env, 600)

    def test_old_kinds_unchanged(self):
        t = wbj.parse_tests(["play3:2000", "rolltest:900:2500", "input:3000:20"], None, 600)
        self.assertEqual([x["name"] for x in t], ["play3-2000", "rolltest-900-2500", "input-3000-20"])


class Shots(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp(dir=TMP)

    def tearDown(self):
        shutil.rmtree(self.d, ignore_errors=True)

    def test_diff(self):
        a, b, c = (os.path.join(self.d, n) for n in ("a.tga", "b.tga", "c.tga"))
        tga(a, 4, 2, [10, 20, 30, 255])
        tga(b, 4, 2, [10, 20, 30, 255])
        self.assertTrue(wbr.tga_diff(a, b, os.path.join(self.d, "d0.tga"))["identical"])
        tga(c, 4, 2, [10, 32, 30, 255])
        r = wbr.tga_diff(a, c, os.path.join(self.d, "d1.tga"))
        self.assertEqual((r["identical"], r["max"], r["px_over_8"], r["mean"]), (False, 12, 1.0, 4.0))
        h, w, hh, px = wbr.read_tga(os.path.join(self.d, "d1.tga"))
        self.assertEqual((w, hh, px[:4]), (4, 2, bytes([0, 48, 0, 255])))
        tga(c, 2, 2, [0, 0, 0, 255])
        self.assertIn("error", wbr.tga_diff(a, c, os.path.join(self.d, "d2.tga")))

    def test_report(self):
        os.makedirs(os.path.join(self.d, "shots"))
        tga(os.path.join(self.d, "shots/game-1500.tga"), 2, 2, [0, 0, 0, 255])
        txt = "\n".join([
            "pddi: bgfx Metal, 640x480",
            "gfxstats: 300 upd | wall 1.000 ms/upd: imports 0.1 (draw 0.0), module+rest 0.9 | bgfx cpu 0.200 gpu 0.300 "
            "wait 0.000 ms",
            "gfxstats:   draws 15.1/upd",
            "gfxstats: 100 upd | wall 2.000 ms/upd: imports 0.1 (draw 0.0), module+rest 1.9 | bgfx cpu 0.600 gpu 0.700 "
            "wait 0.400 ms",
            "hulk-app: windows cost: GPU 0.1 ms off, 0.2 ms on",
            "hulk-app: windows cost: GPU 0.3 ms off, 0.4 ms on"])
        r = wbr.metal_report({"shots": [1500, 3000]}, self.d, txt)
        self.assertTrue(r["metal"])
        self.assertEqual((r["shots"], r["shots_missing"]), ([1500], [3000]))
        self.assertEqual(r["stats"]["updates"], 400)
        self.assertEqual(r["stats"]["ms_per_upd"], {"wall": 1.25, "bgfx_cpu": 0.3, "gpu": 0.4, "wait": 0.1})
        self.assertEqual(r["ab"], {"windows": "GPU 0.3 ms off, 0.4 ms on"})
        self.assertEqual(len(open(os.path.join(self.d, "stats.txt")).read().splitlines()), 5)

    def test_env(self):
        e = wbr.metal_env({"env": {"HULK_GFX_RENDERER": "null", "HULK_GFX_STATS": "0", "HULK_SETTINGS": "x=1"},
                           "shots": [5, 9]}, self.d)
        self.assertEqual((e["HULK_GFX_RENDERER"], e["HULK_GFX_HIDDEN"], e["HULK_GFX_STATS"], e["HULK_SETTINGS"],
                          e["HULK_GFX_SHOT_GAME"], e["HULK_GFX_SHOT_DIR"]),
                         ("metal", "1", "0", "x=1", "5,9", os.path.join(self.d, "shots")))
        self.assertEqual(wbr.metal_env({"env": {}}, self.d)["HULK_GFX_STATS"], "300")


if __name__ == "__main__":
    unittest.main()
