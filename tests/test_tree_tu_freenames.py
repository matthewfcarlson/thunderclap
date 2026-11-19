"""(integ3, D149) verify's free-by-other-name gate and its shrink-only baseline (config/free-name-baseline.json)."""
import json
import os
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu as t  # noqa: E402

TU = "src/game/X.cpp"


def rec(addr, names=None, relocs=True):
    r = {"addr": addr, "kind": "matches", "status": "match", "tu": TU}
    if relocs:
        r["relocs"] = "ok" if not names else "soft"
    if names:
        r["free_by_other_name"] = names
    return r


class FreeNames(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.d.name, "free.json")

    def tearDown(self):
        self.d.cleanup()

    def test_check(self):
        base = {"tus": {TU: {"0x00010000": ["?FuncA@@YAXPAX@Z"], "0x00010010": ["?FuncB@@YAXPAX@Z"]}}}
        rows = t.free_names_check([rec("0x00010000", ["?FuncA@@YAXPAX@Z"]),                # listed: known
                                   rec("0x00010010"),                                       # fixed
                                   rec("0x00010020", ["?FuncC@@YAXPAX@Z"]),                 # new: fails
                                   rec("0x00010030", ["?FuncD@@YAXPAX@Z"], relocs=False)],  # not checked: ignored
                                  base)
        self.assertEqual(rows, [("0x00010000", "known", ["?FuncA@@YAXPAX@Z"]),
                                ("0x00010010", "fixed", ["?FuncB@@YAXPAX@Z"]),
                                ("0x00010020", "new", ["?FuncC@@YAXPAX@Z"])])
        self.assertTrue(t.failing({"free_by_other_name new": 1}))
        self.assertFalse(t.failing({"info: free_by_other_name known": 3, "info: free_by_other_name fixed": 1}))

    def test_file_round_trip(self):
        b = {"comment": "c", "tus": {TU: {"0x00010010": ["b", "a"], "0x00010000": {"names": ["z"], "by": "free-name-accept",
                                                                                   "accepted": "t", "why": "w"},
                                          "0x00010020": []}}}
        t.write_free_baseline(b, self.path)
        got = t.load_free_baseline(self.path)
        self.assertEqual(got["total"], 3)
        self.assertEqual(list(got["tus"][TU]), ["0x00010000", "0x00010010"])      # sorted, empty entries dropped
        self.assertEqual(got["tus"][TU]["0x00010010"], ["a", "b"])

    def test_growth(self):
        r = os.path.join(self.d.name, "repo")
        os.makedirs(os.path.join(r, "config"))
        sh = lambda *a: subprocess.run(["git"] + list(a), cwd=r, check=True, capture_output=True, text=True)
        sh("init", "-q")
        sh("config", "user.email", "t@example.invalid")
        sh("config", "user.name", "t")
        p = os.path.join(r, "config", "free-name-baseline.json")
        with open(os.path.join(r, "README"), "w") as f:
            f.write("x\n")
        sh("add", "README")
        sh("commit", "-qm", "empty")
        t.write_free_baseline({"tus": {TU: {"0x1": ["a"]}}}, p)
        self.assertEqual(t.free_baseline_growth("HEAD", r), [])                      # the seed, when REF had none
        sh("add", "-A")
        sh("commit", "-qm", "seed")
        t.write_free_baseline({"tus": {TU: {"0x1": ["a", "b"]}}}, p)                 # a name added by hand
        self.assertEqual(t.free_baseline_growth("HEAD", r), ["%s 0x1 b" % TU])
        t.write_free_baseline({"tus": {TU: {"0x2": ["c"]}}}, p)                      # a second seed-shaped entry
        self.assertEqual(t.free_baseline_growth("HEAD", r), ["%s 0x2 c" % TU])
        t.write_free_baseline({"tus": {TU: {"0x1": ["a"], "0x2": {"names": ["c"], "by": "free-name-accept",
                                                                  "accepted": "t1", "why": "w"}}}}, p)
        self.assertEqual(t.free_baseline_growth("HEAD", r), [])                      # accepted
        t.write_free_baseline({"tus": {}}, p)
        self.assertEqual(t.free_baseline_growth("HEAD", r), [])                      # shrinking is fine
        os.unlink(p)
        self.assertEqual(t.free_baseline_growth("HEAD", r), ["(deleted)"])
        self.assertTrue(t.free_baseline_growth("nosuchref", r)[0].startswith("(REF unreadable"))


if __name__ == "__main__":
    unittest.main()
