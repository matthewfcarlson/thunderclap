"""tools/x64_gate.py: the 64-bit equivalence regression gate (docs/equivalence.md "64-bit gate").

  * classify: x64eq's status classes, the gate classes (layout, ptrtrunc, crash64, crash64/ptr32) only for failures;
  * judge: a gating failure not in the baseline is `new` (the gate fails), one in it `known`; a baseline block that
    passes `improved` (one that fails in another class keeps its entry); a wild64 failure `triage` (listed, not failing); one that couldn't be checked keeps its entry; no result `unchecked`;
  * the ratchet: --update-baseline removes improved and vanished blocks and never adds one; `accept` adds one only
    with a reason, and only in a gating class; the file round-trips one entry per line;
  * gate(): only changed blocks run, a result is cached by the code key, a cached key isn't run again unless a type
    its run laid out changed (x64t12: equiv64 Types.fingerprints / type_fingerprints);
  * code keys (LLVM's clang): a rename keeps a block's key; a header edit that moves a field on x86-64 only changes the
    keys of the blocks that touch it, not the others'; an edit of a callee block keeps its caller's key.

  build/venv/bin/python -m unittest tests/test_x64_gate.py
"""
import json
import os
import shutil
import sys
import tempfile
import unittest
from unittest import mock

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import x64_gate as g  # noqa: E402


def have_clang():
    try:
        import clang_probe
        return bool(clang_probe.tool("clang++"))
    except Exception:       # noqa: BLE001
        return False


def rec(status, diff=""):
    return {"status": status, "first_diff": diff}


LAYOUT = rec("fail", "input 3: [layout] memory heap#1(C) [0].f_28: 32-bit ('null',), 64-bit ('wildptr',)")
CRASH_PTR = rec("fail", "input 9: [crash64] 64-bit run crash: access to 0x8eb73fb727bd6 at f+0x79: not an address "
                        "(a pointer read from 32-bit data)")
CRASH = rec("fail", "input 9: [crash64] 64-bit run crash: access to 0x0")
TRUNC = rec("fail", "input 1: [ptrtrunc] event 14: ...")
INT = rec("fail", "input 19: [int] event 144: ...")
WILD = rec("fail", "input 2: [wild64] event 3: ...")
NO32 = rec("unsupported", "[tool] no input completed on the 32-bit side ({'oob': 165})")
EQ = rec("equivalent")


class Classes(unittest.TestCase):
    def test_classify(self):
        self.assertEqual(g.classify(EQ), ("equivalent", None))
        self.assertEqual(g.classify(LAYOUT), ("fail:layout", "layout"))
        self.assertEqual(g.classify(TRUNC), ("fail:ptrtrunc", "ptrtrunc"))
        self.assertEqual(g.classify(CRASH), ("fail:crash64", "crash64"))
        self.assertEqual(g.classify(CRASH_PTR), ("fail:crash64", "crash64/ptr32"))
        self.assertEqual(g.classify(INT), ("fail:int", None))
        self.assertEqual(g.classify(NO32), ("unsupported:no32", None))
        self.assertEqual(g.classify(rec("inconclusive")), ("inconclusive", None))
        self.assertEqual(g.classify(None), ("unchecked", None))

    def test_improved(self):
        self.assertTrue(g.improved("equivalent"))
        self.assertFalse(g.improved("fail:int"))
        self.assertFalse(g.improved("fail:layout"))
        self.assertFalse(g.improved("unsupported:no32"))
        self.assertFalse(g.improved("inconclusive"))
        self.assertFalse(g.improved("unchecked"))

    def test_judge(self):
        base = {"blocks": {"0x00000010": "layout", "0x00000020": "crash64/ptr32", "0x00000030": "layout",
                           "0x00000040": "ptrtrunc"}, "why": {}}
        blocks = [(a, "src/game/T.cpp", {"key": "k" + a}, "code changed") for a in
                  ("0x00000010", "0x00000020", "0x00000030", "0x00000040", "0x00000050", "0x00000060", "0x00000070",
                   "0x00000080", "0x00000090")]
        results = {"0x00000010": LAYOUT, "0x00000020": EQ, "0x00000030": NO32, "0x00000040": INT,
                   "0x00000050": CRASH_PTR, "0x00000060": INT, "0x00000070": EQ, "0x00000090": WILD}
        v = {r["addr"]: r["verdict"] for r in g.judge(blocks, results, base)}
        self.assertEqual(v, {"0x00000010": "known", "0x00000020": "improved", "0x00000030": "known-unclear",
                             "0x00000040": "known-unclear", "0x00000050": "new", "0x00000060": "other",
                             "0x00000070": "ok", "0x00000080": "unchecked", "0x00000090": "triage"})


class Baseline(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, "b.json")
        g.write_baseline({"about": "t", "blocks": {"0x00000020": "layout", "0x00000010": "crash64/ptr32"}, "why": {}},
                         self.path)

    def tearDown(self):
        self.tmp.cleanup()

    def test_round_trip(self):
        b = g.load_baseline(self.path)
        self.assertEqual(b["blocks"], {"0x00000010": "crash64/ptr32", "0x00000020": "layout"})
        self.assertEqual(b["total"], 2)
        text = open(self.path).read()
        self.assertIn('    "0x00000010": "crash64/ptr32",\n    "0x00000020": "layout"\n', text)

    def test_ratchet_only_removes(self):
        b = g.load_baseline(self.path)
        rows = [{"addr": "0x00000010", "verdict": "improved"}, {"addr": "0x00000030", "verdict": "new"},
                {"addr": "0x00000020", "verdict": "known-unclear"}]
        removed = g.update_baseline({"rows": rows, "gone": ["0x00000099"]}, b)
        self.assertEqual(removed, ["0x00000010"])
        self.assertEqual(b["blocks"], {"0x00000020": "layout"})
        removed = g.update_baseline({"rows": [], "gone": ["0x00000020"]}, b)
        self.assertEqual(removed, ["0x00000020"])
        self.assertEqual(b["blocks"], {})

    def test_accept(self):
        out = mock.patch("sys.stdout", new_callable=lambda: open(os.devnull, "w"))
        with out:
            self.assertEqual(g.main(["accept", "0x30", "--why", "a union read on purpose", "--class", "layout",
                                     "--baseline", self.path]), 0)
        b = g.load_baseline(self.path)
        self.assertEqual(b["blocks"]["0x00000030"], "layout")
        self.assertTrue(b["why"]["0x00000030"].startswith("a union read on purpose"))
        with self.assertRaises(SystemExit):
            g.main(["accept", "0x40", "--why", "x", "--class", "int", "--baseline", self.path])
        with self.assertRaises(SystemExit):        # (--why is required)
            with mock.patch("sys.stderr", new_callable=lambda: open(os.devnull, "w")):
                g.main(["accept", "0x40", "--class", "layout", "--baseline", self.path])


class Flow(unittest.TestCase):
    """gate() with the keys and the runs replaced: what runs, what is cached, the verdicts."""

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, "b.json")
        g.write_baseline({"blocks": {"0x00000010": "layout", "0x00000099": "ptrtrunc"}, "why": {}}, self.path)
        self.cache = mock.patch.object(g, "CACHE", os.path.join(self.tmp.name, "cache"))
        self.cache.start()

    def tearDown(self):
        self.cache.stop()
        self.tmp.cleanup()

    def run_gate(self, blocks, results, gone=()):
        ran = []

        def fake_changed(ref, head, tus, jobs, workdir):
            return {"blocks": blocks, "gone": list(gone), "tus": 1, "head_root": self.tmp.name, "tmp": self.tmp.name + "/x",
                    "errors": {}, "keyed": len(blocks)}

        def fake_run(items, *a, **kw):
            ran.extend(a_ for a_, _ in items)
            return {a_: dict(results[a_], addr=a_) for a_, _ in items if a_ in results}

        with mock.patch.object(g, "changed_blocks", fake_changed), mock.patch.object(g, "run_blocks", fake_run):
            res = g.gate("HEAD", baseline_path=self.path, quiet=True)
        return res, ran

    def test_new_fails_and_cache(self):
        blocks = [("0x00000010", "src/game/T.cpp", {"key": "a1"}, "code changed"),
                  ("0x00000020", "src/game/T.cpp", {"key": "b1"}, "code changed")]
        res, ran = self.run_gate(blocks, {"0x00000010": EQ, "0x00000020": LAYOUT}, gone=["0x00000099"])
        self.assertEqual(sorted(ran), ["0x00000010", "0x00000020"])
        self.assertTrue(res["failed"])
        v = {r["addr"]: r["verdict"] for r in res["rows"]}
        self.assertEqual(v, {"0x00000010": "improved", "0x00000020": "new"})
        self.assertEqual(res["summary"]["gone_in_baseline"], 1)
        # the same keys again: nothing runs, the same verdicts
        res2, ran2 = self.run_gate(blocks, {})
        self.assertEqual(ran2, [])
        self.assertEqual({r["addr"]: r["verdict"] for r in res2["rows"]}, v)
        self.assertTrue(all(r["cached"] for r in res2["rows"]))
        # an unkeyed block is never cached
        res3, ran3 = self.run_gate([("0x00000030", "src/game/T.cpp", {"key": None}, "unkeyed")], {"0x00000030": INT})
        res4, ran4 = self.run_gate([("0x00000030", "src/game/T.cpp", {"key": None}, "unkeyed")], {"0x00000030": INT})
        self.assertEqual((ran3, ran4), (["0x00000030"], ["0x00000030"]))
        self.assertFalse(res4["failed"])

    def test_stale_types_rerun(self):
        """(x64t12) a cached result whose run built a type the source now lays out differently runs again; one whose
        types agree (or that has none) stays cached."""
        blocks = [("0x00000050", "src/game/T.cpp", {"key": "e1"}, "code changed"),
                  ("0x00000060", "src/game/T.cpp", {"key": "f1"}, "code changed"),
                  ("0x00000070", "src/game/T.cpp", {"key": "g1"}, "code changed")]
        lay = dict(LAYOUT, types={"C": {"k64": "C", "fp": "old"}})
        eq = dict(EQ, types={"D": {"k64": "D", "fp": "same"}})
        res, ran = self.run_gate(blocks, {"0x00000050": lay, "0x00000060": eq, "0x00000070": INT})
        self.assertEqual(sorted(ran), ["0x00000050", "0x00000060", "0x00000070"])
        seen = []

        def fps(path, keys):
            seen.append(sorted(keys))
            return {"C": {"k64": "C", "fp": "new"}, "D": {"k64": "D", "fp": "same"}}

        import equiv64
        with mock.patch.object(equiv64, "type_fingerprints", fps):
            res2, ran2 = self.run_gate(blocks, {"0x00000050": EQ})
        self.assertEqual(ran2, ["0x00000050"])
        self.assertEqual(seen, [["C", "D"]])            # one parse for the TU's hits
        v = {r["addr"]: (r["verdict"], r["cached"]) for r in res2["rows"]}
        self.assertEqual(v, {"0x00000050": ("ok", False), "0x00000060": ("ok", True), "0x00000070": ("other", True)})

    def test_unchecked_fails(self):
        res, ran = self.run_gate([("0x00000040", "src/game/T.cpp", {"key": "c1"}, "new")], {})
        self.assertTrue(res["failed"])
        self.assertEqual(res["rows"][0]["verdict"], "unchecked")


HEADER = """#pragma once
struct Rec {
    int a;
#ifdef _WIN64
    %(pad64)s
#endif
    int b;
};
"""
TU = """#include "tree_prelude.h"
#include "rec.h"
// 0x00011000 FUN_00011000 (10 B): matches
// sym: ?FUN_00011000@@YAHPAURec@@@Z
int FUN_00011000(Rec *r) {
    int %(local)s = r->a;
    return %(local)s + %(k)d;
}

// 0x00011010 FUN_00011010 (10 B): matches
// sym: ?FUN_00011010@@YAHPAURec@@@Z
int FUN_00011010(Rec *r) {
    return r->b + FUN_00011000(r);
}
"""


@unittest.skipUnless(have_clang(), "needs LLVM's clang++")
class Keys(unittest.TestCase):
    def setUp(self):
        base = os.path.join(ROOT, "build") if os.path.isdir(os.path.join(ROOT, "build")) else None
        self.tmp = tempfile.TemporaryDirectory(dir=base)
        r = self.root = self.tmp.name
        os.makedirs(os.path.join(r, "include"))
        os.makedirs(os.path.join(r, "src", "game"))
        shutil.copy(os.path.join(ROOT, "include", "tree_prelude.h"), os.path.join(r, "include"))
        self.tu = os.path.join(r, "src", "game", "T.cpp")
        self.cache = mock.patch.object(g, "CACHE", os.path.join(r, "cache"))
        self.cache.start()

    def tearDown(self):
        self.cache.stop()
        self.tmp.cleanup()

    def keys(self, pad64="", local="v", k=1):
        with open(os.path.join(self.root, "include", "rec.h"), "w") as f:
            f.write(HEADER % {"pad64": pad64})
        with open(self.tu, "w") as f:
            f.write(TU % {"local": local, "k": k})
        ks = g.tu_keys(self.tu)
        for a, x in ks.items():
            self.assertTrue(x["key"], (a, x))
        return {a: x["key"] for a, x in ks.items()}

    def test_keys(self):
        k0 = self.keys()
        self.assertEqual(sorted(k0), ["0x00011000", "0x00011010"])
        self.assertEqual(self.keys(local="value"), k0)                  # a rename
        k1 = self.keys(pad64="void *p;")                                # `b` moves on x86-64 only
        self.assertEqual(k1["0x00011000"], k0["0x00011000"])
        self.assertNotEqual(k1["0x00011010"], k0["0x00011010"])
        k2 = self.keys(k=2)                                             # the callee changes, its caller doesn't
        self.assertNotEqual(k2["0x00011000"], k0["0x00011000"])
        self.assertEqual(k2["0x00011010"], k0["0x00011010"])
        self.assertTrue(os.listdir(os.path.join(self.root, "cache", "keys")))

    def test_type_fingerprints(self):
        """(x64t12) a field's type changes, the code reading the other field doesn't: the same code key, another
        fingerprint for the record; the checker's own fingerprints round-trip through type_fingerprints."""
        import equiv64
        k0 = self.keys()
        f0 = equiv64.type_fingerprints(self.tu, {"Rec": "Rec", "int": "int"})
        self.assertNotIn("missing", [v["fp"] for v in f0.values()])
        self.assertEqual(self.keys(pad64="unsigned pad;").get("0x00011000"), k0["0x00011000"])
        f1 = equiv64.type_fingerprints(self.tu, {"Rec": "Rec", "int": "int"})
        self.assertNotEqual(f1["Rec"]["fp"], f0["Rec"]["fp"])
        self.assertEqual(f1["int"], f0["int"])
        self.assertEqual(equiv64.type_fingerprints(self.tu, {"Gone": "Gone"})["Gone"]["fp"], "missing")
        rep = equiv64.verify64(self.tu, 0x00011000, n_inputs=10, time_budget=30)
        self.assertIn("Rec", rep.get("types", {}), rep)
        now = equiv64.type_fingerprints(self.tu, {k: v["k64"] for k, v in rep["types"].items()})
        self.assertEqual(now, rep["types"])

    def test_pairing(self):
        self.assertEqual(g.canon64("?f@C@@QEAAXH@Z"), g.canon64("?f@C@@QAEXH@Z"))
        self.assertEqual(g.canon64("?f@@YAXPEAH@Z"), g.canon64("?f@@YGXPAH@Z"))
        f64 = ["?vfunc_8@S@p@@UEAAX_J0H@Z", "FUN_00012345"]
        bc, p64 = {}, {}
        for f in f64:
            bc.setdefault(g.canon64(f), []).append(f)
            p64.setdefault(g._prefix(f), []).append(f)
        p32 = {g._prefix("?vfunc_8@S@p@@UAEXHHH@Z"): ["?vfunc_8@S@p@@UAEXHHH@Z"]}
        self.assertEqual(g.pair64("?vfunc_8@S@p@@UAEXHHH@Z", f64, bc, p64, p32), "?vfunc_8@S@p@@UEAAX_J0H@Z")
        self.assertEqual(g.pair64("_FUN_00012345@8", f64, bc, p64, p32), "FUN_00012345")
        self.assertIsNone(g.pair64("?other@@YAXXZ", f64, bc, p64, p32))


class InJob(unittest.TestCase):
    """Inside a queue job (no git in the workspace, tool2): the base commit is the only REF, its tree is the workspace
    with the shipped files back at the commit's copies (tree_tu.JOB_REF), the changed TUs are the shipped ones, and the
    gate never submits from the host."""

    def setUp(self):
        import tree_tu
        self.tt = tree_tu
        self.tmp = tempfile.mkdtemp(prefix="x64gate-job-")      # (not inside a git checkout)
        self.ws = os.path.join(self.tmp, "ws")
        w = lambda rel, text: (os.makedirs(os.path.dirname(os.path.join(self.ws, rel)), exist_ok=True),
                               open(os.path.join(self.ws, rel), "w").write(text))
        w("include/tree_prelude.h", "\n")
        w("include/gen/core.h", "struct Core { int a, b; };\n")          # shipped (edited)
        w("include/gen/new.h", "\n")                                      # shipped (new)
        w("src/game/a.cpp", "// 0x00011000 f (4 B): matches\nint f() { return 1; }\n")
        w("src/game/b.cpp", "// 0x00011010 g (4 B): matches\nint g() { return 2; }\n")
        w(tree_tu.JOB_REF + "/include/gen/core.h", "struct Core { int a; };\n")
        w(tree_tu.JOB_META, json.dumps({"commit": "c0ffee", "refs": ["HEAD", "c0ffee"], "checks": [],
                                        "shipped": ["include/gen/core.h", "include/gen/new.h", "tools/x.py"]}))
        self.p = [mock.patch.object(g, "ROOT", self.ws), mock.patch.object(tree_tu, "ROOT", self.ws),
                  mock.patch.dict(os.environ, {"JOBQ_JOB": "1"})]
        for p in self.p:
            p.start()
        tree_tu._META.clear()

    def tearDown(self):
        for p in self.p:
            p.stop()
        self.tt._META.clear()
        shutil.rmtree(self.tmp)

    def test_rev(self):
        self.assertEqual(g.rev("HEAD"), "c0ffee")
        with self.assertRaises(SystemExit):
            g.rev("HEAD~1")

    def test_candidates(self):
        self.assertEqual(g.candidate_tus("c0ffee"), ["src/game/a.cpp", "src/game/b.cpp"])     # a header shipped
        self.assertEqual(g.candidate_tus("c0ffee", tus=["src/game/b.cpp"]), ["src/game/b.cpp"])

    def test_snapshot(self):
        d = g.snapshot("c0ffee", os.path.join(self.tmp, "ref"))
        self.assertEqual(open(os.path.join(d, "include/gen/core.h")).read(), "struct Core { int a; };\n")
        self.assertFalse(os.path.exists(os.path.join(d, "include/gen/new.h")))
        self.assertTrue(os.path.exists(os.path.join(d, "src/game/a.cpp")))
        self.assertEqual(open(os.path.join(self.ws, "include/gen/core.h")).read(), "struct Core { int a, b; };\n")

    def test_runs_stay_local(self):
        os.makedirs(os.path.join(self.tmp, "w"))
        with mock.patch.object(g.subprocess, "run") as run:
            g.run_blocks([("0x%08x" % (0x11000 + i), "a.cpp") for i in range(9)], mode="jobq",
                         workdir=os.path.join(self.tmp, "w"))
        self.assertIn("--no-jobq", run.call_args[0][0])


if __name__ == "__main__":
    unittest.main()
