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

if __name__ == "__main__":
    unittest.main()
