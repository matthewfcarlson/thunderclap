#!/usr/bin/env python3
"""(integ8) `tree_tu.py hash --emit DIR` / `hash-apply DIR`: a hash queue job's changes come back as a pin patch, the
appended ledger lines and the unproven ratchet's removals. hash-apply applies them to a checkout without copying files:
git apply of the patch (refused when it does not apply), each ledger line once, the ratchet re-run locally so other
lanes' baseline entries and TU edits stay. A throwaway git repo; no game bytes."""
import json
import os
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu  # noqa: E402

TU = "src/x.cpp"
BODY = ["// head\n", "// 0x00001000 f (4 B): equivalent\n", "// sym: ?f@@YAXXZ @old @wold @vold\n", "void f() {}\n",
        "\n", "// 0x00001010 g (4 B): matches\n", "void g() {}\n", "// tail\n"]
LINE = {"addr": "0x00001000", "mode": "wine", "code": "wnew", "view": "v1", "checker": "k", "job": "7",
        "date": "d", "n_inputs": 3000, "status": "equivalent", "promotable": True}
BASE = {"blocks": {"0x00001000": {"modes": {"wine": {"code": "wnew", "by": "unproven-accept"}}, "why": "w"},
                   "0x00002000": {"modes": {"msvc": {"code": "c2", "by": "unproven-accept"}}, "why": "other lane"}}}


def git(root, *a):
    subprocess.run(["git", *a], cwd=root, check=True, capture_output=True)


class EmitApply(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.job, self.co = os.path.join(self.tmp.name, "job"), os.path.join(self.tmp.name, "co")
        for r in (self.job, self.co):
            os.makedirs(os.path.join(r, "src"))
            os.makedirs(os.path.join(r, "config"))
            open(os.path.join(r, TU), "w").write("".join(BODY))
            open(os.path.join(r, "config", "proof-ledger.jsonl"), "w").write("")
            json.dump(BASE, open(os.path.join(r, "config", "unproven-baseline.json"), "w"))
            git(r, "init", "-q")

    def tearDown(self):
        self.tmp.cleanup()

    def at(self, r):
        return mock.patch.multiple(tree_tu, ROOT=r, LEDGER=os.path.join(r, "config", "proof-ledger.jsonl"),
                                   UNPROVEN_BASELINE=os.path.join(r, "config", "unproven-baseline.json"))

    def run_job(self):
        out = os.path.join(self.tmp.name, "out")
        with self.at(self.job), mock.patch.object(tree_tu, "find_root", return_value=self.job):
            st = tree_tu._emit_begin([os.path.join(self.job, TU)])
            p = os.path.join(self.job, TU)
            open(p, "w").write("".join(BODY).replace("@old @wold @vold", "@new @wnew @vnew"))
            tree_tu.ledger_append([dict(LINE)])        # (appends, and drops 0x1000 wine from the job's baseline)
            man = tree_tu._emit_end(st, out)
        return out, man

    def test_emit_then_apply(self):
        out, man = self.run_job()
        self.assertEqual(man["changed_tus"], [TU])
        self.assertEqual(man["ledger_lines"], 1)
        self.assertEqual(man["repinned"], [[TU, "0x00001000"]])
        self.assertTrue(man["checker"])
        self.assertEqual(man["baseline_removed"], [["0x00001000", "wine"]])
        # the checkout has another lane's edit elsewhere in the TU: the patch keeps it
        p = os.path.join(self.co, TU)
        txt0 = open(p).read()
        open(p, "w").write(txt0.replace("// tail", "// tail edited by another lane"))
        with self.at(self.co):
            r = tree_tu.hash_apply(out, root=self.co, check=False)
            self.assertTrue(r["ok"], r)
            txt = open(p).read()
            self.assertIn("@new @wnew @vnew", txt)
            self.assertIn("another lane", txt)
            b = tree_tu.load_unproven_baseline()["blocks"]
            self.assertNotIn("0x00001000", b)
            self.assertIn("0x00002000", b)           # (the other lane's entry stays)
            r2 = tree_tu.hash_apply(out, root=self.co, dry_run=True, check=False)
            self.assertEqual(r2["ledger_appended"], 0)      # (a line is appended once)

    def test_patch_that_does_not_apply_writes_nothing(self):
        out, _ = self.run_job()
        p = os.path.join(self.co, TU)
        open(p, "w").write("".join(BODY).replace("@old", "@moved"))     # (the pin line changed since)
        with self.at(self.co):
            r = tree_tu.hash_apply(out, root=self.co, check=False)
            self.assertFalse(r["ok"])
            self.assertEqual(open(tree_tu.LEDGER).read(), "")
            self.assertIn("0x00001000", tree_tu.load_unproven_baseline()["blocks"])


    def test_post_apply_check_flags_a_stale_pin(self):
        # (rev5) the patch applies, but this checkout's code of the re-pinned block is not the job's: the apply fails
        out, _ = self.run_job()
        stale = [{"addr": "0x00001000", "kind": "equivalent", "code_changed": ["msvc"], "view": "ok"}]
        with self.at(self.co), mock.patch.object(tree_tu, "cached_check", return_value=(stale, False)):
            r = tree_tu.hash_apply(out, root=self.co)
            self.assertFalse(r["ok"])
            self.assertEqual(r["stale"][0]["addr"], "0x00001000")
            self.assertTrue(open(tree_tu.LEDGER).read())        # (the lines stay: true of the job's code)
        ok = [{"addr": "0x00001000", "kind": "equivalent", "view": "ok"}]
        with self.at(self.co), mock.patch.object(tree_tu, "cached_check", return_value=(ok, False)):
            self.assertTrue(tree_tu.hash_apply(out, root=self.co)["ok"])


if __name__ == "__main__":
    unittest.main()
