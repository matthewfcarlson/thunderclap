#!/usr/bin/env python3
"""tools/ckpt_refs.py (ckpt1, D162/D163 R1, rev5): the reference manifest's hashes must equal the files used, references
need three runs, and coverage windows count only inside a reference's compared frames, refused past the bitmap.
Synthetic files only (no game data)."""
import json
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ckpt_ref  # noqa: E402
import ckpt_refs  # noqa: E402


class T(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp(prefix="ckrefs", dir=os.path.join(ROOT, "build") if os.path.isdir(
            os.path.join(ROOT, "build")) else None)
        self.ref = os.path.join(self.d, "r.ckref")
        ckpt_ref.write(self.ref, 3, {f: {1: (f, f)} for f in range(100, 3001)}, ckpt_ref.MAGIC_REF)
        self.rec = os.path.join(self.d, "r.hrp")
        open(self.rec, "wb").write(b"HRP1 synthetic")
        self.man = os.path.join(self.d, "m.json")

    def tool(self, *a):
        return subprocess.run([sys.executable, os.path.join(ROOT, "tools/ckpt_refs.py"), "--manifest", self.man] +
                              list(a), capture_output=True, text=True)

    def test_add_and_check(self):
        r = self.tool("add", "r", "--ref", self.ref, "--recording", self.rec, "--runs", "3")
        self.assertEqual(r.returncode, 0, r.stderr)
        e = json.load(open(self.man))["references"][0]
        self.assertEqual((e["probe"], e["compared"], e["runs"]), (3, [100, 3000], 3))
        self.assertEqual(self.tool("check").returncode, 0)

    def test_tampered_file_refused(self):
        self.tool("add", "r", "--ref", self.ref, "--recording", self.rec, "--runs", "3")
        open(self.rec, "ab").write(b"x")
        r = self.tool("check")
        self.assertEqual(r.returncode, 1)
        self.assertIn("does not hash", r.stdout)

    def test_two_runs_refused(self):
        r = self.tool("add", "r", "--ref", self.ref, "--recording", self.rec, "--runs", "2")
        self.assertNotEqual(r.returncode, 0)

    def test_windows(self):
        e = {"name": "r", "compared": [700, 3000]}
        bits = bytearray(32)
        for k in (0, 5, 10, 11):           # windows of 300 frames: 0-299, 1500-1799, 3000-3299, 3300-3599
            bits[k // 8] |= 1 << (k % 8)
        self.assertEqual(ckpt_refs.windows_in(bits.hex(), 300, e), 2)      # 5 and 10 overlap 700-3000; 0 and 11 do not
        with self.assertRaises(ckpt_refs.RefError):
            ckpt_refs.windows_in(bits.hex(), 10, e)                       # 3000 >= 256*10: past the bitmap
        with self.assertRaises(ckpt_refs.RefError):
            ckpt_refs.windows_in(bits.hex(), 0, e)


if __name__ == "__main__":
    unittest.main()
