"""(integ2, D126) the materialize gate on unproven code and its shrinking baseline (config/unproven-baseline.json)."""
import json
import os
import sys
import tempfile
import unittest
from unittest import mock

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu as t  # noqa: E402


def rec(addr, code, wcode):
    return {"addr": addr, "kind": "equivalent", "code_hash": code, "wine_code_hash": wcode}


class Unproven(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.TemporaryDirectory()
        self.led = os.path.join(self.d.name, "ledger.jsonl")
        self.base = os.path.join(self.d.name, "unproven.json")
        with open(self.led, "w") as f:
            f.write(json.dumps({"addr": "0x00010000", "mode": "msvc", "code": "aaa", "view": "v1"}) + "\n")
            f.write(json.dumps({"addr": "0x00010000", "mode": "wine", "code": "bbb", "view": "v1"}) + "\n")
            # (rev5's R2) a non-promotable line proves nothing
            f.write(json.dumps({"addr": "0x00010040", "mode": "wine", "code": "ggg", "view": "v1",
                                "status": "fail", "promotable": False}) + "\n")

    def tearDown(self):
        self.d.cleanup()

    def test_gate(self):
        led = t.code_ledger_index(self.led)
        checks = [rec("0x00010000", "aaa", "bbb"),              # proven both modes (under some view)
                  rec("0x00010010", "ccc", "ddd"),              # no line: refused
                  rec("0x00010020", "eee", "fff"),              # listed in the baseline (wine only)
                  {"addr": "0x00010030", "kind": "matches"}]
        base = {"blocks": {"0x00010020": {"modes": {"wine": {"code": "fff"}}, "why": "x"}}}
        bad = t.unproven_code(checks, base=base, ledger=led)
        self.assertEqual(bad, [("0x00010010", "msvc"), ("0x00010010", "wine"), ("0x00010020", "msvc")])
        # (rev5's R1) an exemption holds only for the code it was granted for
        self.assertEqual(t.unproven_code([rec("0x00010020", "eee", "fff2")], base=base, ledger=led),
                         [("0x00010020", "msvc"), ("0x00010020", "wine")])
        # (rev5's R2) a non-promotable ledger line is no proof
        self.assertEqual(t.unproven_code([rec("0x00010040", "hhh", "ggg")], base={"blocks": {}}, ledger=led),
                         [("0x00010040", "msvc"), ("0x00010040", "wine")])
        # (rev5) a missing clang hash of an equivalent block is unproven when the Wine side is built
        self.assertEqual(t.unproven_code([rec("0x00010000", "aaa", None)], base={"blocks": {}}, ledger=led),
                         [("0x00010000", "wine")])
        self.assertEqual(t.unproven_code([rec("0x00010000", "aaa", None)], base={"blocks": {}}, ledger=led,
                                         wine=False), [])
        self.assertEqual(t.failing({"unproven code, not in baseline": 3}, unproven=False), 3)   # materialize fails
        # a changed code hash of a proven block is unproven again
        self.assertEqual(t.unproven_code([rec("0x00010000", "zzz", "bbb")], base={"blocks": {}}, ledger=led),
                         [("0x00010000", "msvc")])

    def test_verify_reports_listed_code(self):
        """(integ5, D157) verify reports an equivalent block's mode that the baseline lists for exactly its current code
        hash (stamped by unproven-accept / unproven-seed) under `unproven-baseline`, not as a failure; a listed block
        whose code hash changed, an entry without the stamp (added by hand) and a block listed for the other mode only
        still fail as `unproven`."""
        import collections
        seed = {"accepted": "2026-11-19T00:00:00", "by": "unproven-seed"}
        acc = {"accepted": "2026-11-20T00:00:00", "by": "unproven-accept"}
        base = {"blocks": {"0x00020000": {"modes": {"msvc": dict(seed, code="m1"), "wine": dict(acc, code="w1")}},
                           "0x00020010": {"modes": {"msvc": dict(seed, code="m2")}},
                           "0x00020020": {"modes": {"msvc": {"code": "m3"}}, "why": "by hand"},
                           "0x00020030": {"modes": {"wine": dict(seed, code="w4")}}}}
        recs = [dict(rec("0x00020000", "m1", "w1"), wine_code="ok"),    # listed, both hashes current: reported
                dict(rec("0x00020010", "m2x", "w2"), wine_code="ok"),   # listed for m2, code now m2x: fails
                dict(rec("0x00020020", "m3", "w3"), wine_code="ok"),    # a hand-added entry (no stamp): fails
                dict(rec("0x00020030", "m4", "w4"), wine_code="ok")]    # wine listed, msvc not: msvc fails
        vs = {r["addr"]: {"msvc": "vm", "wine": "vw"} for r in recs}
        blocks = {"blocks": [{"addr": r["addr"], "vhash": t.view_digest("vm", "vw")} for r in recs]}
        with mock.patch.object(t, "_UNPROVEN_BASE", [base]):
            t.mark_views(recs, blocks, vs, set())
        by = {r["addr"]: r for r in recs}
        self.assertEqual(by["0x00020000"]["proof"], {"msvc": "unproven-baseline", "wine": "unproven-baseline"})
        self.assertNotIn("unproven", by["0x00020000"])
        self.assertEqual(by["0x00020000"]["unproven_baseline"], ["msvc", "wine"])
        self.assertEqual(by["0x00020010"]["unproven"], ["msvc", "wine"])
        self.assertEqual(by["0x00020020"]["unproven"], ["msvc", "wine"])
        self.assertEqual(by["0x00020030"]["unproven"], ["msvc"])
        self.assertEqual(by["0x00020030"]["unproven_baseline"], ["wine"])
        c = collections.Counter()
        t.count_codes(c, by["0x00020000"])
        self.assertEqual(t.failing(c), 0)
        self.assertEqual(c["proof: unproven-baseline (msvc)"], 1)
        for a in ("0x00020010", "0x00020020", "0x00020030"):
            c = collections.Counter()
            t.count_codes(c, by[a])
            self.assertGreater(t.failing(c), 0, a)
        # the exemption is the materialize gate's own exact lookup: what it exempts, unproven_code does not refuse
        self.assertEqual(t.unproven_code([rec("0x00020000", "m1", "w1")], base=base, ledger=set()), [])
        self.assertTrue(t.baseline_exempt(base, "0x00020000", "msvc", "m1"))
        self.assertFalse(t.baseline_exempt(base, "0x00020000", "msvc", None))
        self.assertFalse(t.baseline_exempt(base, "0x00020020", "msvc", "m3"))
        # growth without accept still fails verify (the summary count is a failure even when every block is exempt)
        self.assertEqual(t.failing({"unproven baseline grew without accept": 1, "proof: unproven-baseline (msvc)": 3}), 1)

    def test_ratchet(self):
        t.write_unproven_baseline({"blocks": {"0x00010020": {"modes": {"msvc": {"code": "eee"}, "wine": {"code": "fff"}},
                                                             "why": "x"},
                                              "0x00010030": {"modes": {"wine": {"code": "iii"}}, "why": "y"}}}, self.base)
        removed = t.unproven_baseline_drop([{"addr": "0x00010020", "mode": "wine", "promotable": True},
                                            {"addr": "0x00010030", "mode": "wine"},
                                            {"addr": "0x00010099", "mode": "msvc"}], self.base)
        self.assertEqual(sorted(removed), [("0x00010020", "wine"), ("0x00010030", "wine")])
        b = t.load_unproven_baseline(self.base)
        self.assertEqual(b["blocks"], {"0x00010020": {"modes": {"msvc": {"code": "eee"}}, "why": "x"}})
        self.assertEqual(b["total"], 1)

    def test_ledger_append_shrinks_only_the_committed_ledger(self):
        t.write_unproven_baseline({"blocks": {"0x00010020": {"modes": {"msvc": {"code": "eee"}}, "why": "x"}}}, self.base)
        e = {"addr": "0x00010020", "mode": "msvc", "code": "eee", "view": "v2", "promotable": True}
        with mock.patch.object(t, "UNPROVEN_BASELINE", self.base):
            t.ledger_append([e], self.led)                       # a job's ledger: the baseline stays
            self.assertEqual(t.load_unproven_baseline(self.base)["total"], 1)
            with mock.patch.object(t, "LEDGER", self.led):
                t.ledger_append([dict(e, view="v3")], self.led)  # the committed one: it shrinks
            self.assertEqual(t.load_unproven_baseline(self.base)["total"], 0)


    def test_growth_needs_accept(self):
        """(rev5's R3) the list may only grow through unproven-accept's per-mode stamp; a seed stamp counts only when
        REF had no list; a hash swapped by hand, a re-seed and a deleted list are all reported."""
        import subprocess
        repo = os.path.join(self.d.name, "repo")
        os.makedirs(os.path.join(repo, "config"))
        bp = os.path.join(repo, "config", "unproven-baseline.json")
        g = lambda *a: subprocess.run(["git", "-C", repo] + list(a), capture_output=True, text=True, check=True)
        g("init", "-q")
        g("config", "user.email", "t@example.invalid")
        g("config", "user.name", "t")
        open(os.path.join(repo, "README"), "w").write("x\n")
        g("add", "-A")
        g("commit", "-qm", "empty")
        seed = {"code": "a", "accepted": "2026-11-19", "by": "unproven-seed"}
        t.write_unproven_baseline({"blocks": {"0x1": {"modes": {"msvc": dict(seed)}, "why": "x"}}}, bp)
        self.assertEqual(t.unproven_baseline_growth("HEAD", repo), [])        # the one seed: REF had no list
        g("add", "-A")
        g("commit", "-qm", "seed")
        # a hand-swapped hash under the seed stamp, a hand-added entry, an accepted one
        t.write_unproven_baseline({"blocks": {
            "0x1": {"modes": {"msvc": dict(seed, code="a2")}, "why": "x"},
            "0x2": {"modes": {"wine": {"code": "b"}}, "why": "by hand"},
            "0x3": {"modes": {"msvc": {"code": "c", "accepted": "2026-11-19", "by": "unproven-accept"}}, "why": "ok"},
            "0x4": {"modes": {"msvc": {"code": "d", "accepted": "2026-11-19", "by": "unproven-seed"}}, "why": "re"}}},
            bp)
        self.assertEqual(sorted(t.unproven_baseline_growth("HEAD", repo)), ["0x1 msvc", "0x2 wine", "0x4 msvc"])
        # (rev5) a hash swapped by hand under an accept stamp REF already had is reported; a fresh accept is not
        acc = {"code": "c", "accepted": "2026-11-19T10:00:00", "by": "unproven-accept"}
        t.write_unproven_baseline({"blocks": {"0x1": {"modes": {"msvc": dict(seed)}, "why": "x"},
                                              "0x3": {"modes": {"msvc": dict(acc)}, "why": "ok"}}}, bp)
        g("add", "-A")
        g("commit", "-qm", "accepted")
        t.write_unproven_baseline({"blocks": {"0x1": {"modes": {"msvc": dict(seed)}, "why": "x"},
                                              "0x3": {"modes": {"msvc": dict(acc, code="c2")}, "why": "ok"}}}, bp)
        self.assertEqual(t.unproven_baseline_growth("HEAD", repo), ["0x3 msvc"])
        t.write_unproven_baseline({"blocks": {"0x1": {"modes": {"msvc": dict(seed)}, "why": "x"},
                                              "0x3": {"modes": {"msvc": dict(acc, code="c2",
                                                                             accepted="2026-11-20T09:00:00")},
                                                      "why": "re-accepted"}}}, bp)
        self.assertEqual(t.unproven_baseline_growth("HEAD", repo), [])
        os.unlink(bp)
        self.assertEqual(t.unproven_baseline_growth("HEAD", repo), ["(deleted)"])
        self.assertEqual(t.failing({"unproven baseline grew without accept": 1}, unproven=False), 1)

    def test_ref_unreadable_fails_closed(self):
        """(integ3, D126 follow-up) a REF git can't resolve is an error the growth check reports, not "REF had no
        list" (under which every seed stamp would vouch); a REF without the file is still the one seed."""
        import subprocess
        repo = os.path.join(self.d.name, "repo2")
        os.makedirs(os.path.join(repo, "config"))
        g = lambda *a: subprocess.run(["git", "-C", repo] + list(a), capture_output=True, text=True, check=True)
        g("init", "-q")
        g("config", "user.email", "t@example.invalid")
        g("config", "user.name", "t")
        open(os.path.join(repo, "README"), "w").write("x\n")
        g("add", "-A")
        g("commit", "-qm", "empty")
        bp = os.path.join(repo, "config", "unproven-baseline.json")
        seed = {"code": "a", "accepted": "2026-11-19", "by": "unproven-seed"}
        t.write_unproven_baseline({"blocks": {"0x1": {"modes": {"msvc": dict(seed)}, "why": "x"}}}, bp)
        self.assertEqual(t.unproven_baseline_growth("HEAD", repo), [])
        grew = t.unproven_baseline_growth("no-such-ref", repo)
        self.assertEqual(len(grew), 1)
        self.assertTrue(grew[0].startswith("(REF unreadable: no commit no-such-ref"), grew)
        self.assertIsNone(t.file_at_ref("HEAD", "config/unproven-baseline.json", repo))
        with self.assertRaises(t.RefReadError):
            t.file_at_ref("no-such-ref", "config/unproven-baseline.json", repo)

    def test_in_job(self):
        """(integ3, D126 follow-up) in a queue job's workspace (no git) REF's list is JOB_REF's copy when the list was
        shipped, else the workspace's (the commit's): a seed stamp no longer vouches there, a shipped deletion is
        seen, and a REF other than the job's base commit fails closed."""
        ws = os.path.join(self.d.name, "ws")
        os.makedirs(os.path.join(ws, "config"))
        os.makedirs(os.path.join(ws, t.JOB_REF, "config"))
        os.makedirs(os.path.dirname(os.path.join(ws, t.JOB_META)), exist_ok=True)
        rel = "config/unproven-baseline.json"
        seed = {"code": "a", "accepted": "2026-11-19", "by": "unproven-seed"}
        one = {"blocks": {"0x1": {"modes": {"msvc": dict(seed)}, "why": "x"}}}
        two = {"blocks": {"0x1": {"modes": {"msvc": dict(seed)}, "why": "x"},
                          "0x2": {"modes": {"wine": dict(seed, code="b")}, "why": "hand"}}}

        def meta(shipped):
            with open(os.path.join(ws, t.JOB_META), "w") as f:
                json.dump({"commit": "c0ffee", "refs": ["HEAD", "origin/main", "c0ffee"], "shipped": shipped}, f)
            t._META.clear()

        with mock.patch.object(t, "ROOT", ws), mock.patch.dict(os.environ, {"JOBQ_JOB": "1"}):
            try:
                t.write_unproven_baseline(json.loads(json.dumps(one)), os.path.join(ws, t.JOB_REF, rel))
                t.write_unproven_baseline(json.loads(json.dumps(two)), os.path.join(ws, rel))
                meta([rel])
                self.assertEqual(t.unproven_baseline_growth("origin/main", ws), ["0x2 wine"])   # (was: [])
                os.unlink(os.path.join(ws, rel))
                self.assertEqual(t.unproven_baseline_growth("origin/main", ws), ["(deleted)"])  # (was: unseen)
                t.write_unproven_baseline(json.loads(json.dumps(one)), os.path.join(ws, rel))
                meta([])                    # not shipped: the workspace's copy is the commit's
                self.assertEqual(t.unproven_baseline_growth("HEAD", ws), [])
                os.unlink(os.path.join(ws, t.JOB_REF, rel))
                meta([rel])                 # shipped, new: REF had no list, the seed counts once
                self.assertEqual(t.unproven_baseline_growth("HEAD", ws), [])
                grew = t.unproven_baseline_growth("HEAD~3", ws)
                self.assertTrue(grew and grew[0].startswith("(REF unreadable"), grew)
            finally:
                t._META.clear()


if __name__ == "__main__":
    unittest.main()
