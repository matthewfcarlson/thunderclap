#!/usr/bin/env python3
"""tools/ckpt_audit.py (ckpt2, D162 safeguard 2): the weekly sample is reproducible from the week id, stratified by
allowlist entry (ceil 5% of each), drawn only from live lines recorded before the week; a failed mode revokes the
block's ckpt lines and opens a pause that only a lift naming a decision closes. Synthetic lines and reports only."""
import json
import os
import shutil
import sys
import tempfile
import unittest
from unittest import mock

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "tests"))
import ckpt_audit as au  # noqa: E402
import tree_tu  # noqa: E402
from test_ckpt_ledger import MANIFEST, line  # noqa: E402


def lines(n, entry="fight-actors", date="2026-11-10T00:00:00"):
    tags = {"fight-actors": ["hulk", "actors"], "camera": ["camera"]}[entry]
    tu = {"fight-actors": "src/game/hulkfight/F%d.cpp", "camera": "src/game/global/Camera%d.cpp"}[entry]
    return [line(addr="0x%08x" % (0x10000 + 0x10 * i), tu=tu % i, allow={"entry": entry, "tags": tags}, date=date)
            for i in range(n)]


class T(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp()
        self.p = [mock.patch.object(tree_tu, "REVOKED", os.path.join(self.d, "rev.jsonl")),
                  mock.patch.object(tree_tu, "CKPT_PAUSE", os.path.join(self.d, "pause.jsonl")),
                  mock.patch.object(tree_tu, "CKPT_LEDGER", os.path.join(self.d, "ckpt.jsonl")),
                  mock.patch.object(au, "AUDIT", os.path.join(self.d, "audit.jsonl")),
                  mock.patch("ckpt_refs.load", lambda path=None: MANIFEST)]
        for p in self.p:
            p.start()
        tree_tu._REVOKED.clear()

    def tearDown(self):
        for p in self.p:
            p.stop()
        tree_tu._REVOKED.clear()
        shutil.rmtree(self.d, ignore_errors=True)

    def codes(self, ls, code="w1"):
        return {(e["tu"], e["addr"]): ("equivalent", code, "m1") for e in ls}

    def test_draw_reproducible_and_stratified(self):
        pop = lines(41) + lines(3, "camera")
        a = au.draw(pop, "2026-W48")
        self.assertEqual({k: len(v) for k, v in a.items()}, {"fight-actors": 3, "camera": 1})   # ceil(5%) per entry
        b = au.draw(list(reversed(pop)), "2026-W48")                                           # order-free
        self.assertEqual({k: [e["addr"] for e in v] for k, v in a.items()},
                         {k: [e["addr"] for e in v] for k, v in b.items()})
        c = au.draw(pop, "2026-W49")
        self.assertNotEqual([e["addr"] for e in a["fight-actors"]], [e["addr"] for e in c["fight-actors"]])

    def test_population_live_and_before_week(self):
        old, new = lines(3), lines(2, date="2026-11-24T10:00:00")      # W48 starts Monday 2026-11-23
        ls = old + new
        codes = self.codes(ls)
        codes[(old[0]["tu"], old[0]["addr"])] = ("equivalent", "w9", "m1")       # edited since: not live
        pop, _c = au.population("2026-W48", None, lines=ls, codes=codes)
        self.assertEqual(sorted(e["addr"] for e in pop), sorted(e["addr"] for e in old[1:]))

    def test_judge_one(self):
        s = {"addr": "0x00012340", "code": "w1", "msvc_code": "m1"}
        self.assertEqual(au.judge_one(None, "msvc", s, {})[0], "inconclusive")
        fail = {"status": "fail", "first_diff": "ret differs", "tree_code": {"msvc": "m1"}}
        self.assertEqual(au.judge_one(fail, "msvc", s, {})[0], "fail")
        other = {"status": "fail", "tree_code": {"wine": "w2"}, "native": True}
        self.assertEqual(au.judge_one(other, "wine", s, {})[0], "inconclusive")       # another code: not this line's
        short = {"status": "unsupported", "tree_code": {"msvc": "m1"}}
        self.assertEqual(au.judge_one(short, "msvc", s, {})[0], "inconclusive")
        x = {"status": "fail", "first_diff": "[layout] word 3"}
        self.assertEqual(au.judge_one(x, "x64", s, {"blocks": {}})[0], "fail")
        self.assertEqual(au.judge_one(x, "x64", s, {"blocks": {"0x00012340": "layout"}})[0], "pass")
        self.assertEqual(au.judge_one(dict(x, first_diff="[float] x"), "x64", s, {"blocks": {}})[0], "fail")
        self.assertEqual(au.judge_one({"status": "equivalent"}, "x64", s, {})[0], "pass")
        self.assertEqual(au.judge_one({"status": "inconclusive"}, "x64", s, {})[0], "inconclusive")

    def test_failure_revokes_and_pauses(self):
        ls = lines(1, date="2026-11-01T00:00:00")
        with open(tree_tu.CKPT_LEDGER, "w") as f:
            f.write(json.dumps(ls[0]) + "\n")
        s = {"key": tree_tu.ckpt_line_key(ls[0]), "addr": ls[0]["addr"], "tu": ls[0]["tu"], "code": "w1",
             "msvc_code": "m1", "entry": "fight-actors"}
        au.append({"kind": "sample", "week": "2026-W48", "head": "h", "sample": [s]})
        jd = os.path.join(self.d, "jobs")
        rep = {"msvc": {"status": "fail", "first_diff": "ret differs", "tree_code": {"msvc": "m1"}},
               "wine": None, "x64": {"status": "equivalent"}}
        with mock.patch.object(au, "ROOT", self.d):
            os.makedirs(os.path.join(self.d, "build/ckpt/audit/2026-W48"))
            jobs = {}
            for i, m in enumerate(au.MODES):
                jobs["%s %s" % (s["key"], m)] = str(i)
                if rep[m] is not None:
                    os.makedirs(os.path.join(self.d, "build/jobs/out", str(i), "audit"))
                    with open(os.path.join(self.d, "build/jobs/out", str(i), "audit", m + ".json"), "w") as f:
                        json.dump(rep[m], f)
            with open(os.path.join(self.d, "build/ckpt/audit/2026-W48/jobs.json"), "w") as f:
                json.dump(jobs, f)
            self.assertEqual(au.cmd_judge(type("A", (), {"week": "2026-W48"})()), 1)
        tree_tu._REVOKED.clear()
        self.assertIn("revoked", tree_tu.ckpt_line_accepts(ls[0], ls[0]["tu"], "equivalent", "w1",
                                                           manifest=MANIFEST))
        self.assertTrue(tree_tu.ckpt_open_pause())
        vs = au.verdicts("2026-W48")
        self.assertEqual(sorted((v["mode"], v["verdict"]) for v in vs), [("msvc", "fail"), ("x64", "pass")])
        sus = [r for r in au.records() if r.get("kind") == "equiv_suspect"]
        self.assertEqual([(r["addr"], r["mode"], r["code"]) for r in sus], [(ls[0]["addr"], "msvc", "m1")])
        self.assertTrue(tree_tu.code_ledger_index() is not None)      # (no equiv line revoked by the audit itself)
        # an earlier line keeps counting? no: the failed block's lines are revoked; another block's line keeps counting
        other = line(addr="0x00055550", date="2026-11-01T00:00:00")
        self.assertIsNone(tree_tu.ckpt_line_accepts(other, other["tu"], "equivalent", "w1", manifest=MANIFEST))
        newer = line(addr="0x00055550", date="2099-01-01T00:00:00")
        self.assertIn("pause", tree_tu.ckpt_line_accepts(newer, newer["tu"], "equivalent", "w1", manifest=MANIFEST))
        # lift: only naming a decision, only an open pause
        pid = [r["pause"] for r in au.records(tree_tu.CKPT_PAUSE) if r.get("pause")][0]
        with self.assertRaises(SystemExit):
            au.main(["lift", pid, "--decision", "ok", "--why", "x"])
        with self.assertRaises(SystemExit):
            au.main(["lift", "nope", "--decision", "D170", "--why", "x"])
        self.assertEqual(au.main(["lift", pid, "--decision", "D170", "--why", "user lifted"]), 0)
        self.assertFalse(tree_tu.ckpt_open_pause())
        with self.assertRaises(SystemExit):
            au.main(["lift", pid, "--decision", "D170", "--why", "again"])


    def test_redraw(self):
        ls = lines(5, date="2026-11-01T00:00:00")
        with open(tree_tu.CKPT_LEDGER, "w") as f:
            for e in ls:
                f.write(json.dumps(e) + "\n")
        codes = self.codes(ls)
        od = au.order(ls, "2026-W48")["fight-actors"]
        self.assertEqual([e["addr"] for e in au.draw(ls, "2026-W48")["fight-actors"]], [od[0]["addr"]])
        keys = [tree_tu.ckpt_line_key(e) for e in od]
        rec = {"kind": "sample", "week": "2026-W48", "order": {"fight-actors": keys},
               "sample": [au.slot(od[0], codes, "fight-actors")]}
        au.append(rec)
        codes[(od[0]["tu"], od[0]["addr"])] = ("equivalent", "w9", "m1")      # the sampled block edited since
        codes[(od[1]["tu"], od[1]["addr"])] = ("matches", "w1", "m1")         # the next one no longer counts either
        with mock.patch.object(au, "current_codes", lambda lines, tree: codes):
            r, slots = au.current_sample("2026-W48")
            out = au.replace_dead(r, slots, "2026-W48", None)
        self.assertEqual([x["addr"] for x in out], [od[2]["addr"]])           # the next counting line, in order
        r2, slots2 = au.current_sample("2026-W48")
        self.assertEqual([x["addr"] for x in slots2], [od[2]["addr"]])        # recorded
        rp = [x for x in au.records() if x.get("kind") == "replace"]
        self.assertEqual((rp[0]["old"], rp[0]["new"]["key"]), (keys[0], keys[2]))
        # the same week gives the same order wherever it is computed
        self.assertEqual([e["addr"] for e in au.order(list(reversed(ls)), "2026-W48")["fight-actors"]],
                         [e["addr"] for e in od])

    def test_x64_report(self):
        s = {"key": "k", "addr": "0x00012340", "tu": "t", "code": "w1", "msvc_code": "m1", "entry": "fight-actors"}
        au.append({"kind": "sample", "week": "2026-W48", "head": "h", "order": {}, "sample": [s]})
        with mock.patch.object(au, "ROOT", self.d):
            os.makedirs(os.path.join(self.d, "build/ckpt/audit/2026-W48"))
            os.makedirs(os.path.join(self.d, "build/jobs/out/9/audit"))
            with open(os.path.join(self.d, "build/jobs/out/9/audit/x64.json"), "w") as f:
                json.dump({"status": "fail", "first_diff": "[ptrtrunc] p"}, f)
            with open(os.path.join(self.d, "build/ckpt/audit/2026-W48/jobs.json"), "w") as f:
                json.dump({"k x64": "9"}, f)
            self.assertEqual(au.cmd_judge(type("A", (), {"week": "2026-W48"})()), 1)
        self.assertEqual([r["addr"] for r in au.records() if r.get("kind") == "x64_report"], ["0x00012340"])
        self.assertTrue(tree_tu.ckpt_open_pause())


    def test_audit_missing(self):
        import datetime
        now = datetime.date(2026, 12, 2)                       # W49; the previous week is W48 (from 2026-11-23)
        self.assertIsNone(au.audit_missing(now, lines=[]))
        self.assertIsNone(au.audit_missing(now, lines=lines(1, date="2026-11-25T00:00:00")))   # none before W48
        old = lines(1, date="2026-11-01T00:00:00")
        self.assertIn("no audit sample", au.audit_missing(now, lines=old))
        s = {"key": "k", "addr": "0x1", "tu": "t", "code": "w1", "msvc_code": "m1", "entry": "fight-actors"}
        au.append({"kind": "sample", "week": "2026-W48", "order": {}, "sample": [s]})
        self.assertIn("without a verdict", au.audit_missing(now, lines=old))
        for m in au.MODES:
            au.append({"kind": "verdict", "week": "2026-W48", "key": "k", "mode": m, "verdict": "pass"})
        self.assertIsNone(au.audit_missing(now, lines=old))
        au.append({"kind": "sample", "week": "2026-W47", "order": {}, "sample": []})


if __name__ == "__main__":
    unittest.main()
