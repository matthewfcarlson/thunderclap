#!/usr/bin/env python3
"""tools/ckpt_ref.py (ckpt1, docs/checkpoints.md): the record format, two-run references (a (frame, tag) is kept only
where both runs agree), the check's first divergence and drift/logic call, observables outside the verdict, and the
control gate. Synthetic records only (no game data)."""
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ckpt_ref  # noqa: E402

FLOW, HULK, SOUND, PARTICLE = 1, 4, 8, 9


def recs(n, override=None):
    """{frame: {tag: (exact, quant)}}: tags flow, hulk, sound, particle; override {(frame, tag): (e, q)}"""
    out = {}
    for f in range(n):
        out[f] = {t: (f * 16 + t, f * 16 + t + 1000) for t in (FLOW, HULK, SOUND, PARTICLE)}
    for (f, t), v in (override or {}).items():
        out[f][t] = v
    return out


class T(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp(prefix="ckref")

    def path(self, name, r, magic=ckpt_ref.MAGIC_RUN, pv=3):
        p = os.path.join(self.d, name)
        ckpt_ref.write(p, pv, r, magic)
        return p

    def run_tool(self, *args):
        return subprocess.run([sys.executable, os.path.join(ROOT, "tools/ckpt_ref.py")] + list(args),
                              capture_output=True, text=True)

    def test_roundtrip(self):
        r = recs(5)
        magic, pv, back, unav = ckpt_ref.read(self.path("a", r))
        self.assertEqual((magic, pv), (ckpt_ref.MAGIC_RUN, 3))
        self.assertEqual(back, r)
        self.assertEqual(set(unav.values()), {0})

    def test_make_drops_only_disagreeing_tags(self):
        a = self.path("a", recs(10))
        b = self.path("b", recs(10, {(7, PARTICLE): (1, 2), (8, SOUND): (3, 4)}))
        ref = os.path.join(self.d, "ref")
        self.assertEqual(self.run_tool("make", a, b, "--name", "t", "--out", ref).returncode, 0)
        _m, _pv, r, _u = ckpt_ref.read(ref)
        self.assertEqual(len(r), 10)                          # no frame dropped
        self.assertNotIn(PARTICLE, r[7])                      # only the disagreeing tag of that frame
        self.assertIn(HULK, r[7])
        self.assertNotIn(SOUND, r[8])

    def test_check_first_divergence_and_drift(self):
        ref = self.path("ref", recs(20), ckpt_ref.MAGIC_REF)
        base = recs(20)
        drift = self.path("drift", recs(20, {(12, HULK): (1, base[12][HULK][1])}))      # quantised hash equal
        logic = self.path("logic", recs(20, {(15, HULK): (1, 2)}))
        res = ckpt_ref.first_divergence(ckpt_ref.read(drift)[2], ckpt_ref.read(ref)[2], {})
        self.assertEqual((res[HULK]["first"], res[HULK]["drift"], res[HULK]["last_ok"]), (12, True, 11))
        res = ckpt_ref.first_divergence(ckpt_ref.read(logic)[2], ckpt_ref.read(ref)[2], {})
        self.assertEqual((res[HULK]["first"], res[HULK]["drift"]), (15, False))
        self.assertEqual(self.run_tool("check", logic, "--ref", ref).returncode, 1)

    def test_observable_outside_verdict(self):
        ref = self.path("ref", recs(20), ckpt_ref.MAGIC_REF)
        run = self.path("run", recs(20, {(3, SOUND): (9, 9)}))
        self.assertEqual(self.run_tool("check", run, "--ref", ref).returncode, 0)
        self.assertEqual(self.run_tool("check", run, "--ref", ref, "--strict").returncode, 1)

    def test_control_gate(self):
        ref = self.path("ref", recs(20), ckpt_ref.MAGIC_REF)
        ctl = self.path("ctl", recs(20, {(5, HULK): (7, 7)}))                       # a known divergence
        same = self.path("same", recs(20, {(5, HULK): (8, 8)}))                     # diverges only where the control did
        worse = self.path("worse", recs(20, {(5, HULK): (8, 8), (9, FLOW): (1, 1)}))
        self.assertEqual(self.run_tool("check", same, "--ref", ref, "--control", ctl).returncode, 0)
        self.assertEqual(self.run_tool("check", worse, "--ref", ref, "--control", ctl).returncode, 1)

    def test_version_mismatch_refused(self):
        ref = self.path("ref", recs(3), ckpt_ref.MAGIC_REF, pv=2)
        run = self.path("run", recs(3), pv=3)
        r = self.run_tool("check", run, "--ref", ref)
        self.assertNotEqual(r.returncode, 0)
        self.assertIn("probe versions differ", r.stdout + r.stderr)


if __name__ == "__main__":
    unittest.main()
