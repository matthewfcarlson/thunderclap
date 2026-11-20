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

    def test_equivalent_and_how(self):
        # (integ3) an equivalent block checked by name (free_checked) is gated like a matches block; one never
        # checked is ignored; a baseline entry may carry the kind of each name (`how`)
        e = {"addr": "0x00010040", "kind": "equivalent", "status": "compiled", "tu": TU, "free_checked": "name",
             "free_by_other_name": ["_FUN_0008d340"], "free_how": {"_FUN_0008d340": "name"}}
        e2 = dict(e, addr="0x00010050")
        del e2["free_checked"]
        base = {"tus": {TU: {"0x00010060": {"names": ["_FUN_00267090"], "how": {"_FUN_00267090": "name"},
                                            "by": "free-name-accept", "accepted": "t", "why": "w"}}}}
        e3 = {"addr": "0x00010060", "kind": "equivalent", "status": "compiled", "tu": TU, "free_checked": "name",
              "free_by_other_name": ["_FUN_00267090"], "free_how": {"_FUN_00267090": "name"}}
        e4 = dict(e, addr="0x00010080", free_checked="no symbol")                     # (rev5) a gap, never gated
        self.assertEqual(t.free_names_check([e, e2, e3, e4], base),
                         [("0x00010040", "new", ["_FUN_0008d340"]), ("0x00010060", "known", ["_FUN_00267090"])])

    def test_accept_records(self):
        # (integ3) --records --how accepts only that kind, stamped as an accept, with the kind kept
        recs = os.path.join(self.d.name, "v.jsonl")
        with open(recs, "w") as f:
            f.write(json.dumps({"tu": TU, "addr": "0x00010040", "kind": "equivalent", "free_checked": "name",
                                "free_by_other_name": ["_FUN_0008d340"], "free_how": {"_FUN_0008d340": "name"}}) + "\n")
            f.write(json.dumps({"tu": TU, "addr": "0x00010070", "kind": "matches",
                                "free_by_other_name": ["_FUN_0008d330"]}) + "\n")
        old = t.FREE_BASELINE, t.file_at_ref
        t.FREE_BASELINE = self.path
        t.file_at_ref = lambda ref, rel, root=None: None       # (REF had no baseline)
        acc = ["free-name-accept", "--records", recs, "--job", "123", "--commit", "abc", "--why", "seed equiv"]
        try:
            t.write_free_baseline({"tus": {}}, self.path)
            self.assertEqual(t.main(acc + ["--how", "name"]), 0)
            got = t.load_free_baseline(self.path)["tus"][TU]
            # (rev5) only `name`, only once
            with self.assertRaises(SystemExit):
                t.main(acc + ["--how", "name"])
            with self.assertRaises(SystemExit):
                t.main(acc + ["--how", "address"])
            with self.assertRaises(SystemExit):
                t.main(["free-name-accept", "--records", recs, "--how", "name", "--why", "no job"])
            t.write_free_baseline({"tus": {}}, self.path)
            t.file_at_ref = lambda ref, rel, root=None: json.dumps({"tus": {TU: {"0x1": {"names": ["n"], "how": {
                "n": "name"}, "by": "free-name-accept", "accepted": "t", "why": "w"}}}})
            with self.assertRaises(SystemExit):                 # REF's baseline already had the seed
                t.main(acc + ["--how", "name"])
            refs = []
            t.file_at_ref = lambda ref, rel, root=None: refs.append(ref)     # (REF is HEAD, never chosen)
            self.assertEqual(t.main(acc + ["--how", "name"]), 0)
            self.assertEqual(refs, ["HEAD"])
            t.write_free_baseline({"tus": {}}, self.path)
            with self.assertRaises(SystemExit):                 # no other REF can be named
                t.main(acc + ["--how", "name", "--ref", "HEAD~5"])
        finally:
            t.FREE_BASELINE, t.file_at_ref = old
        self.assertEqual(list(got), ["0x00010040"])                                 # the call row is not taken
        self.assertEqual((got["0x00010040"]["by"], got["0x00010040"]["how"]),
                         ("free-name-accept", {"_FUN_0008d340": "name"}))
        self.assertIn("job 123 at abc", got["0x00010040"]["why"])

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
