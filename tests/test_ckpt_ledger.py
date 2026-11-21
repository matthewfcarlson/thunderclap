#!/usr/bin/env python3
"""The ledger kind `ckpt` (ckpt2, D162/D163 piece 4; rev5 ADOPT): a ckpt line satisfies only (addr, wine, wine code
hash), R2 and R4 are re-checked when it is read, and no equiv reader ever counts it. Synthetic lines only."""
import json
import os
import shutil
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu  # noqa: E402

TU = "src/game/hulkfight/CFightThing.cpp"
MANIFEST = {"version": 1, "references": [
    {"name": "play3", "ref": "x", "ref_sha256": "r3", "recording": "y", "recording_sha256": "p3", "probe": 3,
     "runs": 3, "compared": [0, 56575]},
    {"name": "play4", "ref": "x4", "ref_sha256": "r4", "recording": "y4", "recording_sha256": "p4", "probe": 3,
     "runs": 3, "compared": [0, 56575]}]}


def bitmap(*windows):
    b = bytearray(32)
    for w in windows:
        b[w // 8] |= 1 << (w % 8)
    return b.hex()


def line(**kw):
    e = {"kind": "ckpt", "addr": "0x00012340", "mode": "wine", "code": "w1", "tu": TU,
         "allow": {"entry": "fight-actors", "tags": ["hulk", "actors"]},
         "refs": {"play3": {"recording_sha256": "p3", "ref_sha256": "r3", "probe": 3, "epoch": 300,
                            "blocks": {"0x10001000": bitmap(3, 10), "0x10001010": bitmap(4, 40, 100)}}},
         "min_windows": 2, "validator": "v1", "commit": "c", "jobs": {"control": "1", "proof": "2"},
         "date": "2026-11-21T10:00:00"}
    e.update(kw)
    return e


class T(unittest.TestCase):
    def setUp(self):
        self.d = tempfile.mkdtemp()
        self.saved = (tree_tu.REVOKED, tree_tu.CKPT_PAUSE, tree_tu.CKPT_LEDGER, tree_tu.LEDGER)
        tree_tu.REVOKED = os.path.join(self.d, "revoked.jsonl")
        tree_tu.CKPT_PAUSE = os.path.join(self.d, "pause.jsonl")
        tree_tu.CKPT_LEDGER = os.path.join(self.d, "ckpt.jsonl")
        tree_tu.LEDGER = os.path.join(self.d, "ledger.jsonl")
        tree_tu._REVOKED.clear()

    def tearDown(self):
        tree_tu.REVOKED, tree_tu.CKPT_PAUSE, tree_tu.CKPT_LEDGER, tree_tu.LEDGER = self.saved
        tree_tu._REVOKED.clear()
        shutil.rmtree(self.d, ignore_errors=True)

    def acc(self, e, tu=TU, kind="equivalent", code="w1", manifest=MANIFEST):
        return tree_tu.ckpt_line_accepts(e, tu, kind, code, manifest=manifest)

    def write(self, path, recs):
        with open(path, "a") as f:
            for r in recs:
                f.write(json.dumps(r) + "\n")

    def test_good_line(self):
        self.assertIsNone(self.acc(line()))
        self.assertIsNone(self.acc(line(), tu="/some/where/" + TU))      # an absolute TU path

    def test_wine_mode_and_code_only(self):
        self.assertIsNotNone(self.acc(line(mode="msvc")))
        self.assertIsNotNone(self.acc(line(kind="equiv")))
        self.assertIsNotNone(self.acc(line(), code="w2"))
        self.assertIsNotNone(self.acc(line(), code=None))

    def test_revoked_line_run_validator(self):
        e = line()
        self.write(tree_tu.REVOKED, [{"kind": "ckpt", "addr": e["addr"], "mode": "wine",
                                      "lines": [tree_tu.ckpt_line_key(e)]}])
        self.assertIn("revoked", self.acc(e))
        self.assertIsNone(self.acc(line(date="2026-11-22T00:00:00")))    # another line of the same run is not this one
        tree_tu._REVOKED.clear()
        self.write(tree_tu.REVOKED, [{"kind": "ckpt", "addr": e["addr"], "mode": "wine", "lines": [],
                                      "runs": [["w1", "ckpt:v1"]]}])
        self.assertIn("revoked", self.acc(line(date="2026-11-22T00:00:00")))     # the run: every line of it
        self.assertIsNone(self.acc(line(validator="v2")))                         # another validator's run
        self.write(tree_tu.REVOKED, [{"kind": "ckpt", "addr": "all", "mode": "wine", "lines": [],
                                      "validators": ["v2"]}])
        self.assertIn("validator", self.acc(line(validator="v2")))

    def test_pause(self):
        self.write(tree_tu.CKPT_PAUSE, [{"pause": "p1", "date": "2026-11-21T12:00:00"}])
        self.assertIsNone(self.acc(line()))                                       # before the pause: keeps counting
        self.assertIn("pause", self.acc(line(date="2026-11-21T13:00:00")))
        self.assertTrue(tree_tu.ckpt_open_pause())
        self.write(tree_tu.CKPT_PAUSE, [{"lift": "p1", "decision": "D999", "date": "2026-11-22T00:00:00"}])
        self.assertFalse(tree_tu.ckpt_open_pause())
        self.assertIn("pause", self.acc(line(date="2026-11-21T13:00:00")))       # a lift does not admit retroactively
        self.assertIsNone(self.acc(line(date="2026-11-22T01:00:00")))
        self.assertIn("pause", self.acc(line(date=None)))                         # undated: refused

    def test_r4_recheck(self):
        self.assertIn("a matches block", self.acc(line(), kind="matches"))
        self.assertIn("R4", self.acc(line(), tu="src/game/global/FEThingsBase_3.cpp"))
        self.assertIn("R4", self.acc(line(allow={"entry": "physics", "tags": ["hulk", "actors"]})))
        self.assertIn("R4", self.acc(line(allow={"entry": "fight-actors", "tags": ["hulk"]})))
        self.assertIn("R4", self.acc(line(), tu="src/game/hulkfight/CSoundThing.cpp"))     # the name denylist

    def test_r2_recheck(self):
        e = line()
        e["refs"]["play3"]["blocks"]["0x10001020"] = bitmap(7)                   # one block in one window
        self.assertIn("R2", self.acc(e))
        e["refs"]["play3"]["blocks"]["0x10001020"] = ""                          # one block never hit
        self.assertIn("R2", self.acc(e))
        m = json.loads(json.dumps(MANIFEST))
        m["references"][0]["compared"] = [0, 3000]                               # windows 3 and 10: only 3 now
        self.assertIn("R2", self.acc(line(), manifest=m))
        m = json.loads(json.dumps(MANIFEST))
        m["references"][0]["recording_sha256"] = "other"                         # re-recorded
        self.assertIn("R2", self.acc(line(), manifest=m))
        m = json.loads(json.dumps(MANIFEST))
        m["references"] = m["references"][1:]                                    # gone from the manifest
        self.assertIn("R2", self.acc(line(), manifest=m))
        m = json.loads(json.dumps(MANIFEST))
        m["references"][0]["compared"] = [0, 90000]                              # past the bitmap: RefError
        self.assertIn("R2", self.acc(line(), manifest=m))
        self.assertIn("R2", self.acc(line(refs={})))
        self.assertIn("R2", self.acc(line(min_windows=4)))                       # the recorded minimum holds too

    def test_r2_never_summed_across_references(self):
        e = line()
        e["refs"] = {"play3": {"recording_sha256": "p3", "epoch": 300, "blocks": {"0x10001000": bitmap(3)}},
                     "play4": {"recording_sha256": "p4", "epoch": 300, "blocks": {"0x10001000": bitmap(9)}}}
        self.assertIn("R2", self.acc(e))
        e["refs"]["play4"]["blocks"]["0x10001000"] = bitmap(9, 11)
        self.assertIsNone(self.acc(e))

    def test_never_an_equiv_proof(self):
        e = line(view="vv", checker="c", status="equivalent")
        self.write(tree_tu.LEDGER, [e])
        self.assertFalse(tree_tu.ledger_line_proves(e))
        self.assertEqual(tree_tu.ledger_index(tree_tu.LEDGER), set())
        self.assertEqual(tree_tu.code_ledger_index(tree_tu.LEDGER), set())
        self.write(tree_tu.CKPT_LEDGER, [line()])
        self.assertEqual(tree_tu.code_ledger_index(), set())

    def test_unproven_code_wine_only(self):
        chk = [{"addr": "0x00012340", "kind": "equivalent", "tu": TU, "code_hash": "m1", "wine_code_hash": "w1"}]
        import ckpt_refs
        saved = ckpt_refs.load
        ckpt_refs.load = lambda path=None: MANIFEST
        try:
            self.assertEqual(tree_tu.unproven_code(chk, base={"blocks": {}}, ledger=set(), ckpt=[line()]),
                             [("0x00012340", "msvc")])
            self.assertEqual(tree_tu.unproven_code(chk, base={"blocks": {}}, ledger=set(), ckpt=[line(code="w9")]),
                             [("0x00012340", "msvc"), ("0x00012340", "wine")])
            self.assertEqual(tree_tu.unproven_code(chk, base={"blocks": {}}, ledger=set(), ckpt=[line(mode="msvc")]),
                             [("0x00012340", "msvc"), ("0x00012340", "wine")])
            self.write(tree_tu.CKPT_LEDGER, [line()])
            self.assertEqual(tree_tu.unproven_code(chk, base={"blocks": {}}, ledger=set()), [("0x00012340", "msvc")])
            # never the msvc mode, even where its code hash is the same text
            same = [dict(chk[0], code_hash="w1")]
            self.assertEqual(tree_tu.unproven_code(same, base={"blocks": {}}, ledger=set(), ckpt=[line()]),
                             [("0x00012340", "msvc")])
        finally:
            ckpt_refs.load = saved

    def test_mark_views_status(self):
        import ckpt_refs
        saved = ckpt_refs.load
        ckpt_refs.load = lambda path=None: MANIFEST
        tree_tu._UNPROVEN_BASE[:] = [{"blocks": {}}]
        try:
            self.write(tree_tu.CKPT_LEDGER, [line()])
            r = {"addr": "0x00012340", "kind": "equivalent", "tu": TU, "code_hash": "m1", "wine_code_hash": "w1"}
            tree_tu.mark_views([r], {"blocks": [{"addr": "0x00012340", "vhash": None}]},
                               {"0x00012340": {"msvc": "vm", "wine": "vw"}}, set())
            self.assertEqual(r["proof"], {"msvc": "unproven", "wine": "ckpt"})
            self.assertEqual(r["unproven"], ["msvc"])
        finally:
            ckpt_refs.load = saved
            tree_tu._UNPROVEN_BASE[:] = []

    def test_workspace_accepts_never_land(self):
        b = {"blocks": {"0x00012340": {"modes": {"wine": {"code": "w1", "by": "unproven-accept-workspace",
                                                          "accepted": "t"}}}}}
        self.assertEqual(tree_tu.workspace_accepts(b), ["0x00012340 wine"])
        self.assertFalse(tree_tu.baseline_exempt(b, "0x00012340", "wine", "w1"))     # verify never exempts it
        self.assertEqual(tree_tu.failing({"unproven baseline holds workspace accepts": 1}, unproven=True), 1)
        # materialize takes it only in a proof workspace's build (HULK_CKPT_WORKSPACE=1)
        chk = [{"addr": "0x00012340", "kind": "equivalent", "tu": TU, "code_hash": "m1", "wine_code_hash": "w1"}]
        led = {("0x00012340", "msvc", "m1")}
        saved = os.environ.pop("HULK_CKPT_WORKSPACE", None)
        try:
            self.assertEqual(tree_tu.unproven_code(chk, base=b, ledger=led, ckpt=[]), [("0x00012340", "wine")])
            os.environ["HULK_CKPT_WORKSPACE"] = "1"
            self.assertEqual(tree_tu.unproven_code(chk, base=b, ledger=led, ckpt=[]), [])
            b2 = json.loads(json.dumps(b))
            b2["blocks"]["0x00012340"]["modes"]["wine"]["by"] = "unproven-accept"       # an ordinary accept: as before
            os.environ.pop("HULK_CKPT_WORKSPACE")
            self.assertEqual(tree_tu.unproven_code(chk, base=b2, ledger=led, ckpt=[]), [])
        finally:
            os.environ.pop("HULK_CKPT_WORKSPACE", None)
            if saved is not None:
                os.environ["HULK_CKPT_WORKSPACE"] = saved

    def test_revoke_cli(self):
        e = line()
        self.write(tree_tu.CKPT_LEDGER, [e, line(addr="0x00055550", validator="v9")])
        self.write(tree_tu.LEDGER, [{"addr": e["addr"], "mode": "wine", "code": "w1", "view": "v", "job": "1",
                                     "status": "equivalent", "checker": "c", "date": "d", "n_inputs": 3000}])
        self.assertEqual(tree_tu.main(["revoke", e["addr"], "--mode", "wine", "--kind", "ckpt", "--why", "audit"]), 0)
        tree_tu._REVOKED.clear()
        self.assertIn("revoked", self.acc(e))
        self.assertIn(("0x00012340", "wine", "w1"), tree_tu.code_ledger_index())    # the equiv line untouched
        with self.assertRaises(SystemExit):                                         # nothing live left
            tree_tu.main(["revoke", e["addr"], "--mode", "wine", "--kind", "ckpt", "--why", "again"])
        with self.assertRaises(SystemExit):
            tree_tu.main(["revoke", e["addr"], "--mode", "msvc", "--kind", "ckpt", "--why", "x"])
        self.assertIsNone(self.acc(line(addr="0x00055550", validator="v9")))
        self.assertEqual(tree_tu.main(["revoke", "all", "--mode", "wine", "--kind", "ckpt", "--validator", "v9",
                                       "--why", "validator bug"]), 0)
        tree_tu._REVOKED.clear()
        self.assertIn("revoked", self.acc(line(addr="0x00055550", validator="v9")))
        self.assertIn("validator", self.acc(line(addr="0x00066660", validator="v9")))   # also lines not yet seen
        # the default kind revokes the equiv line only
        self.assertEqual(tree_tu.main(["revoke", e["addr"], "--mode", "wine", "--why", "equiv"]), 0)
        tree_tu._REVOKED.clear()
        self.assertNotIn(("0x00012340", "wine", "w1"), tree_tu.code_ledger_index())


class Record(unittest.TestCase):
    """ckpt_ledger.py record: refuses unless every condition holds (mocked jobs, trees and code hashes)"""
    def setUp(self):
        import gzip
        import types
        import ckpt_ledger
        import ckpt_refs
        self.L, self.R = ckpt_ledger, ckpt_refs
        self.d = tempfile.mkdtemp()
        self.saved = (tree_tu.REVOKED, tree_tu.CKPT_PAUSE, tree_tu.CKPT_LEDGER, ckpt_refs.load, ckpt_ledger.job_dir,
                      ckpt_ledger.wine_code, ckpt_ledger.manifest_commit, ckpt_ledger.ROOT)
        tree_tu.REVOKED = os.path.join(self.d, "revoked.jsonl")
        tree_tu.CKPT_PAUSE = os.path.join(self.d, "pause.jsonl")
        tree_tu.CKPT_LEDGER = os.path.join(self.d, "ckpt.jsonl")
        tree_tu._REVOKED.clear()
        m1 = {"version": 1, "references": [MANIFEST["references"][0]]}
        ckpt_refs.load = lambda path=None: m1
        ckpt_ledger.ROOT = self.d
        jd = os.path.join(self.d, "job")
        os.makedirs(jd)
        img = os.path.join(self.d, "img")
        os.makedirs(img)
        self.wt(os.path.join(img, "hulk-strict.exe"), "image")
        self.wt(os.path.join(jd, "image.sha256"), "%s  hulk-strict.exe\n" % ckpt_ledger.sha1_file(
            os.path.join(img, "hulk-strict.exe")))
        self.ptree = os.path.join(self.d, "ptree")
        os.makedirs(os.path.join(self.ptree, os.path.dirname(TU)))
        self.wt(os.path.join(self.ptree, TU), "code")
        with gzip.open(os.path.join(jd, "sources.json.gz"), "wt") as f:
            json.dump({TU: ckpt_ledger.sha1_file(os.path.join(self.ptree, TU)), "tools/x.py": "zz"}, f)
        ckpt_ledger.job_dir = lambda job: jd
        self.wj(os.path.join(jd, "summary.json"), {"link_noicf": True, "off": {}})
        cd = os.path.join(self.d, "build/jobs/out/12/wine-out")
        os.makedirs(cd)
        self.wt(os.path.join(cd, "image.sha1"), "%s  wine-img/hulk-strict.exe\n" % ckpt_ledger.sha1_file(
            os.path.join(img, "hulk-strict.exe")))
        self.wt(os.path.join(cd, "trace.txt.cov"), "cover epoch 300\n")
        self.land = os.path.join(self.d, "land")
        os.makedirs(os.path.join(self.land, "config"))
        self.codes = {self.ptree: "w1", self.land: "w1"}
        ckpt_ledger.wine_code = lambda tree, tu, addr: ("equivalent", self.codes[tree])
        ckpt_ledger.manifest_commit = lambda root=None: "mc"
        hits = line()["refs"]["play3"]["blocks"]
        self.blocks = {"proof": img, "covers": {"play3": {"sha256": ckpt_ledger.sha256_file(
            os.path.join(cd, "trace.txt.cov"))}}, "functions": [{"addr": "0x00012340", "tu": TU, "eligible": True, "r4": None,
                                                    "r2": True, "allow": {"entry": "fight-actors",
                                                                          "tags": ["hulk", "actors"]},
                                                    "r2_hits": {"play3": {"epoch": 300, "blocks": hits}}}]}
        self.gate = {"ok": True, "host": "mac1", "manifest_commit": "mc", "references": {
            "play3": {"ok": True, "control": "10", "proof": "11", "gate": "GATE ok ref: ok", "control_diverged": 3,
                      "particle_frames": 100}}}
        self.a = types.SimpleNamespace(blocks=os.path.join(self.d, "b.json"), gate=os.path.join(self.d, "g.json"),
                                       proof_tree=self.ptree, proof_job="11", coverage_job=["play3=12"], tree=self.land,
                                       addr=None, dry_run=True, ledger=None)

    def wt(self, p, text):
        with open(p, "w") as f:
            f.write(text)

    def wj(self, p, obj):
        self.wt(p, json.dumps(obj))

    def tearDown(self):
        (tree_tu.REVOKED, tree_tu.CKPT_PAUSE, tree_tu.CKPT_LEDGER, self.R.load, self.L.job_dir, self.L.wine_code,
         self.L.manifest_commit, self.L.ROOT) = self.saved
        tree_tu._REVOKED.clear()
        shutil.rmtree(self.d, ignore_errors=True)

    def run_(self):
        self.wj(self.a.blocks, self.blocks)
        self.wj(self.a.gate, self.gate)
        try:
            return self.L.cmd_record(self.a)
        except SystemExit as x:
            return str(x)

    def test_ok(self):
        self.assertEqual(self.run_(), 0)
        self.a.dry_run = False
        self.assertEqual(self.run_(), 0)
        e = tree_tu.ckpt_lines()
        self.assertEqual(len(e), 1)
        self.assertEqual((e[0]["mode"], e[0]["code"], e[0]["jobs"]["proof"], e[0]["host"]), ("wine", "w1", "11", "mac1"))
        self.assertIsNone(tree_tu.ckpt_line_accepts(e[0], TU, "equivalent", "w1"))

    def test_workspace_proof_allowed(self):
        self.wj(os.path.join(self.d, "job", "summary.json"), {"link_noicf": True, "off": {"HULK_CKPT_WORKSPACE": "1"}})
        jd = os.path.join(self.d, "job")
        ctl = os.path.join(self.d, "ctljob")
        os.makedirs(ctl)
        self.wj(os.path.join(ctl, "summary.json"), {"link_noicf": True, "off": {}})
        self.L.job_dir = lambda job: ctl if str(job) == "10" else jd
        self.assertEqual(self.run_(), 0)
        self.wj(os.path.join(ctl, "summary.json"), {"link_noicf": True, "off": {"HULK_CKPT_WORKSPACE": "1"}})
        self.assertIn("REFUSED", self.run_())      # never the control

    def test_refusals(self):
        import copy
        cases = [
            ("gate not ok", lambda: self.gate.update(ok=False)),
            ("gate ref not ok", lambda: self.gate["references"]["play3"].update(ok=False)),
            ("other proof job", lambda: self.gate["references"]["play3"].update(proof="99")),
            ("manifest commit", lambda: self.gate.update(manifest_commit="old")),
            ("missing ref", lambda: self.gate.update(references={})),
            ("coverage jobs", lambda: setattr(self.a, "coverage_job", [])),
            ("ineligible", lambda: self.blocks["functions"][0].update(eligible=False)),
            ("r4", lambda: self.blocks["functions"][0].update(r4="reaches platform code")),
            ("no bitmaps", lambda: self.blocks["functions"][0].update(r2_hits={})),
            ("allow entry", lambda: self.blocks["functions"][0].update(allow={"entry": "physics",
                                                                              "tags": ["hulk", "actors"]})),
            ("landing code", lambda: self.codes.update({self.land: "w2"})),
            ("not noicf", lambda: self.wj(os.path.join(self.d, "job", "summary.json"), {"link_noicf": False})),
            ("switches", lambda: self.wj(os.path.join(self.d, "job", "summary.json"),
                                         {"link_noicf": True, "off": {"TREE_TU_OFF": "unprovengate"}})),
            ("cover image", lambda: self.wt(os.path.join(self.d, "build/jobs/out/12/wine-out/image.sha1"), "ff  x\n")),
            ("cover file", lambda: self.wt(os.path.join(self.d, "build/jobs/out/12/wine-out/trace.txt.cov"), "other")),
            ("ws accept", lambda: self.wj(os.path.join(self.land, "config/unproven-baseline.json"), {"blocks": {
                "0x00099990": {"modes": {"msvc": {"code": "x", "by": "unproven-accept-workspace"}}}}})),
            ("baseline lists code", lambda: self.wj(os.path.join(self.land, "config/unproven-baseline.json"), {"blocks": {
                "0x00012340": {"modes": {"wine": {"code": "w1", "by": "unproven-accept", "accepted": "t"}}}}})),
            ("image", lambda: self.wt(os.path.join(self.blocks["proof"], "hulk-strict.exe"), "other")),
            ("sources", lambda: self.wt(os.path.join(self.ptree, TU), "edited")),
            ("R2 at read time", lambda: self.blocks["functions"][0]["r2_hits"]["play3"].update(
                blocks={"0x1": bitmap(1)})),
            ("pause", lambda: self.wt(tree_tu.CKPT_PAUSE, '{"pause": "p", "date": "2000-01-01"}\n')),
            ("audit not done", lambda: self.wt(tree_tu.CKPT_LEDGER, json.dumps(line(date="2000-01-01T00:00:00")) + "\n")),
        ]
        for name, mut in cases:
            self.tearDown()
            self.setUp()
            mut()
            r = self.run_()
            self.assertIsInstance(r, str, name)
            self.assertIn("REFUSED", r, name)

if __name__ == "__main__":
    unittest.main()
