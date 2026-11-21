#!/usr/bin/env python3
"""tools/cover.py (ckpt1, D162/D163): the hit file's optional window counts (HULK_COVER_EPOCH) reach the report,
per function the fewest windows any of its hit blocks ran in. Synthetic map, blocks and hits only (no game data)."""
import json
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))

MAP = """ hulk-strict

  Address         Publics by Value              Rva+Base               Lib:Object

 0001:00000000       ?f@@YAXXZ                  0000000010001000     0123456789abcdef0123.obj
 0001:00000100       ?g@@YAXXZ                  0000000010001100     0123456789abcdef0123.obj
"""
TU = """// 0x00011000 f (16 B): matches
// sym: ?f@@YAXXZ
void f() {}

// 0x00011010 g (32 B): matches
// sym: ?g@@YAXXZ
void g() {}
"""


class T(unittest.TestCase):
    def test_epochs(self):
        d = tempfile.mkdtemp(prefix="cov")
        os.makedirs(os.path.join(d, "src/game/x"))
        open(os.path.join(d, "src/game/x/t.cpp"), "w").write(TU)
        open(os.path.join(d, "m.map"), "w").write(MAP)
        json.dump({"10001000": [[0x10001000, 8], [0x10001008, 8]], "10001100": [[0x10001100, 32]]},
                  open(os.path.join(d, "b.json"), "w"))
        open(os.path.join(d, "h.cov"), "w").write("cover listed 3 hit 3 frame 900 epoch 300\n"
                                                    "10001000 5 3\n10001008 700 1\n10001100 9 4\n")
        out = os.path.join(d, "r.json")
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/cover.py"), "report", os.path.join(d, "h.cov"),
                            os.path.join(d, "m.map"), "--tree", d, "--blocks", os.path.join(d, "b.json"), "--json", out],
                           capture_output=True, text=True)
        self.assertEqual(r.returncode, 0, r.stderr)
        rep = {x["name"]: x for x in json.load(open(out))["reached"]}
        self.assertEqual(rep["f"]["min_block_epochs"], 1)       # the block that ran in one window only
        self.assertEqual(rep["g"]["min_block_epochs"], 4)
        self.assertIn("block windows", r.stdout)

    def test_windows_in_compared_frames(self):
        # (rev5) only windows overlapping the reference's compared frames count
        d = tempfile.mkdtemp(prefix="cov")
        os.makedirs(os.path.join(d, "src/game/x"))
        open(os.path.join(d, "src/game/x/t.cpp"), "w").write(TU)
        open(os.path.join(d, "m.map"), "w").write(MAP)
        json.dump({"10001000": [[0x10001000, 16]], "10001100": [[0x10001100, 32]]}, open(os.path.join(d, "b.json"), "w"))
        bm = lambda ks: bytes(sum(1 << (k % 8) for k in ks if k // 8 == j) for j in range(32)).hex()
        open(os.path.join(d, "h.cov"), "w").write(
            "cover listed 2 hit 2 frame 3000 epoch 300\n"
            "10001000 5 3 %s\n10001100 9 3 %s\n" % (bm([0, 1, 9]), bm([0, 8, 9])))
        out = os.path.join(d, "r.json")
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/cover.py"), "report", os.path.join(d, "h.cov"),
                            os.path.join(d, "m.map"), "--tree", d, "--blocks", os.path.join(d, "b.json"),
                            "--frames", "0-2399", "--json", out], capture_output=True, text=True)
        self.assertEqual(r.returncode, 0, r.stderr)
        rep = {x["name"]: x for x in json.load(open(out))["reached"]}
        self.assertEqual(rep["f"]["min_block_epochs"], 2)       # windows 0 and 1; window 9 (2700..) is outside
        self.assertEqual(rep["g"]["min_block_epochs"], 1)       # window 0 only: window 8 starts at 2400, outside

    def test_old_format(self):
        # a hit file without window counts (before D162) still reports, with no window figures
        d = tempfile.mkdtemp(prefix="cov")
        os.makedirs(os.path.join(d, "src/game/x"))
        open(os.path.join(d, "src/game/x/t.cpp"), "w").write(TU)
        open(os.path.join(d, "m.map"), "w").write(MAP)
        open(os.path.join(d, "h.cov"), "w").write("cover listed 2 hit 1 frame 9\n10001000 5\n")
        r = subprocess.run([sys.executable, os.path.join(ROOT, "tools/cover.py"), "report", os.path.join(d, "h.cov"),
                            os.path.join(d, "m.map"), "--tree", d], capture_output=True, text=True)
        self.assertEqual(r.returncode, 0, r.stderr)
        self.assertNotIn("block windows", r.stdout)


if __name__ == "__main__":
    unittest.main()
