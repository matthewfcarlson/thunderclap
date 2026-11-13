"""tree_tu.py's checks beyond the blocks (tool2, 2026-11-13; docs/merge-once.md "Checks in check and verify"):

  * D9, the header probe: verify / check find the include/gen/ headers that changed (since --changed-since, uncommitted,
    or shipped to a queue job) and fail when gen_headers.py --probe fails; the probe writes only under build/tmp/;
  * D10, the submit guard: a `tree_tu.py verify|check` / `x64_gate.py check` queue job is refused when a TU it reads, a
    header those TUs can #include or a config file the check reads has an unshipped local edit, unless --head-only;
    the job carries the local digests and prints them against its own;
  * D12, data overreach: data_overreach.py's reported classes fail the block they lie in, the informational ones are
    listed only; a real MSVC compile of a read past "D:" is caught (needs MSVC under wibo).

  build/venv/bin/python -m unittest tests.test_tree_tu_checks
"""
import json
import os
import shutil
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu  # noqa: E402
import jobq  # noqa: E402

TU = "// 0x00001000 FUN_00001000 (4 B): matches\n#include \"game/x.h\"\nint f() { return 1; }\n"


def put(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as f:
        f.write(text)


def git(root, *args):
    subprocess.run(["git", "-c", "user.name=t", "-c", "user.email=t@t", *args], cwd=root, check=True,
                   capture_output=True)


class Repo(unittest.TestCase):
    """A throwaway checkout (a git repo with a tree: include/tree_prelude.h, two TUs, gen and decls headers) that
    tree_tu and jobq take for ROOT."""

    def setUp(self):
        self.tmp = tempfile.mkdtemp(prefix="tool2-checks-")
        r = self.root = os.path.join(self.tmp, "repo")
        put(os.path.join(r, "include", tree_tu.PRELUDE), "// prelude\n")
        put(os.path.join(r, "include/game/x.h"), "#include <gen/core.h>\nstruct X { int a; };\n")
        put(os.path.join(r, "include/gen/core.h"), "struct Core { int a; };\n")
        put(os.path.join(r, "include/decls/other.h"), "// nobody includes this\n")
        put(os.path.join(r, "src/game/a.cpp"), TU)
        put(os.path.join(r, "src/game/b.cpp"), TU.replace("0x00001000 FUN_00001000", "0x00002000 FUN_00002000"))
        put(os.path.join(r, "config/data.json"), "[\n]\n")
        put(os.path.join(r, "config/gen-sizes.json"), "{}\n")
        git(r, "init", "-q")
        git(r, "add", ".")
        git(r, "commit", "-q", "-m", "base")
        self.commit = subprocess.run(["git", "rev-parse", "HEAD"], cwd=r, capture_output=True, text=True).stdout.strip()
        self.patches = [mock.patch.object(tree_tu, "ROOT", r), mock.patch.object(jobq, "STORE", os.path.join(self.tmp, "store"))]
        for p in self.patches:
            p.start()
        tree_tu._META.clear()

    def tearDown(self):
        for p in self.patches:
            p.stop()
        tree_tu._META.clear()
        shutil.rmtree(self.tmp)

    def ship(self, *rels, **srcs):
        """Overlay files as jobq.collect_files gives them: REL from the checkout, or DEST=text."""
        out = {}
        for rel in rels:
            out[rel] = [jobq.store_file(os.path.join(self.root, rel)), 0o644]
        for dest, text in srcs.items():
            p = os.path.join(self.tmp, "src-" + dest.replace("/", "_"))
            put(p, text)
            out[dest.replace("__", "/")] = [jobq.store_file(p), 0o644]
        return out

    def guard(self, cmd, files=None):
        return tree_tu.submit_guard(cmd, files or {}, self.commit)


VERIFY = ["python", "tools/tree_tu.py", "verify", ".", "--relocs"]


class Commands(unittest.TestCase):
    def test_argv_and_sh(self):
        self.assertEqual(tree_tu.guarded_commands(VERIFY), [("tree_tu", "verify", [".", "--relocs"])])
        sh = ["sh", "-c", "build/venv/bin/python tools/tree_tu.py verify . --tus job/t.txt>v.log 2>&1; tail v.log"]
        self.assertEqual(tree_tu.guarded_commands(sh), [("tree_tu", "verify", [".", "--tus", "job/t.txt"])])
        self.assertEqual(tree_tu.guarded_commands(["python", "tools/x64_gate.py", "check", "--tus", "l"]),
                         [("x64_gate", "check", ["--tus", "l"])])
        self.assertEqual(tree_tu.guarded_commands(["python", "tools/tree_tu.py", "blocks", "a.cpp"]), [])
        self.assertEqual(tree_tu.guarded_commands(["python", "tools/equiv.py", "a.cpp", "0x1000"]), [])

    def test_jobq_pattern(self):
        self.assertTrue(jobq.INPUT_GUARD.search(" ".join(VERIFY)))
        self.assertFalse(jobq.INPUT_GUARD.search("python tools/tree_tu.py materialize --out build/tree"))


class Guard(Repo):
    def test_clean_checkout_passes_and_records(self):
        extra = self.guard(VERIFY)
        with open(os.path.join(jobq.STORE, extra[tree_tu.JOB_META][0])) as f:
            meta = json.load(f)
        self.assertEqual(meta["commit"], self.commit)
        self.assertIn("HEAD", meta["refs"])
        c = meta["checks"][0]
        self.assertEqual((c["tool"], c["sub"], c["args"], c["tus"], c["n_unshipped"]), ("tree_tu", "verify", [".", "--relocs"], 2, 0))
        self.assertEqual(set(c["local"]), {"tus", "headers", "reach"})

    def test_no_guard_for_other_jobs(self):
        self.assertIsNone(self.guard(["python", "tools/equiv.py", "src/game/a.cpp", "0x1000"]))

    def test_unshipped_tu_refused(self):
        put(os.path.join(self.root, "src/game/a.cpp"), TU.replace("return 1", "return 2"))
        with self.assertRaises(SystemExit) as e:
            self.guard(VERIFY)
        self.assertIn("src/game/a.cpp (modified)", str(e.exception))
        self.assertIn("--head-only", str(e.exception))
        self.guard(VERIFY, self.ship("src/game/a.cpp"))                 # shipped: fine
        self.guard(VERIFY + ["--head-only"])                            # on purpose: fine

    def test_reachable_header_refused_unreachable_not(self):
        put(os.path.join(self.root, "include/decls/other.h"), "// edited, but no TU includes it\n")
        self.guard(VERIFY)
        put(os.path.join(self.root, "include/gen/core.h"), "struct Core { int a, b; };\n")
        with self.assertRaises(SystemExit) as e:
            self.guard(VERIFY)
        self.assertIn("include/gen/core.h (modified)", str(e.exception))

    def test_tus_list_only_reads_listed(self):
        put(os.path.join(self.root, "src/game/b.cpp"), TU.replace("return 1", "return 3"))
        cmd = ["python", "tools/tree_tu.py", "verify", ".", "--tus", "job/tus.txt"]
        self.guard(cmd, self.ship(**{"job__tus.txt": "src/game/a.cpp\n"}))
        with self.assertRaises(SystemExit):
            self.guard(cmd, self.ship(**{"job__tus.txt": "src/game/b.cpp\n"}))

    def test_untracked_tu_refused(self):
        put(os.path.join(self.root, "src/game/c.cpp"), TU)
        with self.assertRaises(SystemExit) as e:
            self.guard(VERIFY)
        self.assertIn("src/game/c.cpp (untracked)", str(e.exception))

    def test_config_read(self):
        put(os.path.join(self.root, "config/data.json"), "[\n{}]\n")
        with self.assertRaises(SystemExit) as e:
            self.guard(VERIFY)
        self.assertIn("config/data.json", str(e.exception))
        # gen-sizes.json only matters when the probe will run (an include/gen header shipped)
        put(os.path.join(self.root, "config/data.json"), "[\n]\n")
        put(os.path.join(self.root, "config/gen-sizes.json"), '{"x": 1}\n')
        self.guard(VERIFY)
        with self.assertRaises(SystemExit):
            self.guard(VERIFY, self.ship(**{"include__gen__core.h": "struct Core { int a, b; };\n"}))

    def test_changed_since_other_commit_refused(self):
        with self.assertRaises(SystemExit) as e:
            self.guard(VERIFY + ["--changed-since", "HEAD~1"])
        self.assertIn("no git", str(e.exception))
        self.guard(VERIFY + ["--changed-since", "HEAD"])

    def test_ref_copies_shipped(self):
        files = self.ship(**{"include__gen__core.h": "struct Core { int a, b; };\n"})
        extra = self.guard(VERIFY + ["--head-only"], files)
        with open(os.path.join(jobq.STORE, extra[tree_tu.JOB_REF + "/include/gen/core.h"][0])) as f:
            ref = f.read()
        self.assertEqual(ref, "struct Core { int a; };\n")

    def test_in_job_comparison(self):
        files = self.ship("src/game/a.cpp")
        extra = self.guard(VERIFY, files)
        meta = os.path.join(self.root, tree_tu.JOB_META)
        os.makedirs(os.path.dirname(meta))
        shutil.copyfile(os.path.join(jobq.STORE, extra[tree_tu.JOB_META][0]), meta)
        with mock.patch.dict(os.environ, {"JOBQ_JOB": "1"}):
            paths = tree_tu.tree_tus(self.root)
            vl = tree_tu.inputs_vs_local("verify", [".", "--relocs"], tree_tu.inputs_digest(paths))
            self.assertEqual(vl["same"], {"tus": True, "reach": True, "headers": True})
            put(os.path.join(self.root, "include/gen/core.h"), "struct Core { int z; };\n")
            vl = tree_tu.inputs_vs_local("verify", [".", "--relocs"], tree_tu.inputs_digest(paths))
            self.assertEqual(vl["same"], {"tus": True, "reach": False, "headers": False})
            self.assertIsNone(tree_tu.inputs_vs_local("verify", [".", "--other"], {}).get("local"))


class GenChanges(Repo):
    def test_uncommitted_and_since_ref(self):
        self.assertEqual(tree_tu.gen_changes(self.root), [])
        put(os.path.join(self.root, "include/gen/core.h"), "struct Core { int a, b; };\n")
        put(os.path.join(self.root, "include/gen/new.h"), "struct New {};\n")
        self.assertEqual(tree_tu.gen_changes(self.root), ["include/gen/core.h", "include/gen/new.h"])
        git(self.root, "add", ".")
        git(self.root, "commit", "-q", "-m", "gen")
        self.assertEqual(tree_tu.gen_changes(self.root), [])
        self.assertEqual(tree_tu.gen_changes(self.root, "HEAD~1"), ["include/gen/core.h", "include/gen/new.h"])
        # check: only the headers its TU can include
        self.assertEqual(tree_tu.gen_changes(self.root, "HEAD~1", [os.path.join(self.root, "src/game/a.cpp")]),
                         ["include/gen/core.h"])

    def test_in_job_shipped(self):
        meta = os.path.join(self.root, tree_tu.JOB_META)
        put(meta, json.dumps({"shipped": ["include/gen/core.h", "src/game/a.cpp"], "refs": ["HEAD"], "commit": "x"}))
        with mock.patch.dict(os.environ, {"JOBQ_JOB": "1"}):
            self.assertEqual(tree_tu.gen_changes(self.root), ["include/gen/core.h"])

    def test_verify_fails_on_probe(self):
        tus = os.path.join(self.tmp, "tus.txt")
        put(tus, "src/game/a.cpp\n")
        summ = {"tus": 1, "cache_hits": 0, "counts": {"matches match": 1}, "errors": [], "n_errors": 0,
                "inputs": {"tus": "a", "headers": "b", "reach": "c"}}
        with mock.patch.object(tree_tu, "verify", return_value=dict(summ)), \
                mock.patch.object(tree_tu, "gen_changes", return_value=["include/gen/core.h"]), \
                mock.patch.object(tree_tu, "gen_probe", return_value={"ok": False, "problems": ["X: sizeof 8, recorded 4"],
                                                                      "seconds": 1.0}) as gp, \
                mock.patch("sys.stdout"), mock.patch("sys.stderr"):
            self.assertEqual(tree_tu.main(["verify", self.root, "--tus", tus]), 1)
            gp.assert_called_once()
        with mock.patch.object(tree_tu, "verify", return_value=dict(summ)), \
                mock.patch.object(tree_tu, "gen_changes", return_value=[]), \
                mock.patch.object(tree_tu, "gen_probe") as gp, mock.patch("sys.stdout"), mock.patch("sys.stderr"):
            self.assertEqual(tree_tu.main(["verify", self.root, "--tus", tus]), 0)
            gp.assert_not_called()


class Overreach(unittest.TestCase):
    def hits(self, *kinds):
        return [{"kind": k, "item": "DAT_0042b50c", "item_addr": "0x0042b50c", "item_size": 2, "offset": 2, "width": 1,
                 "target_item": "s_empty_0042b50e", "insn": "mov al, byte ptr [0x42b50e]", "symbol": s}
                for k, s in kinds]

    def test_attach_and_count(self):
        import data_overreach as dor
        out = [{"addr": "0x00001000", "name": "f", "kind": "matches", "symbol": "?f@@YAHXZ", "status": "match"},
               {"addr": "0x00002000", "name": "g", "kind": "matches", "symbol": "?g@@YAHXZ", "status": "match"}]
        pairs = [({}, r) for r in out]
        with mock.patch.object(dor, "object_hits", return_value=self.hits(("over", "?g@@YAHXZ"), ("end", "?f@@YAHXZ"),
                                                                           ("pad", "_DAT_00500000"))):
            tree_tu._ITEMS[:] = [object()]
            tree_tu.overreach("x.obj", out, pairs)
        self.assertEqual([h["kind"] for h in out[1]["overreach"]], ["over"])
        self.assertEqual([h["kind"] for h in out[0]["overreach_info"]], ["end"])
        self.assertEqual([h["kind"] for h in out[0]["overreach"]], ["pad"])      # (no block: the TU's first record)
        tree_tu._ITEMS.clear()

    def test_failing(self):
        self.assertEqual(tree_tu.failing({"matches match": 3, "overreach over": 1}), 1)
        self.assertEqual(tree_tu.failing({"matches match": 3, "info: overreach end": 4}), 0)


def have_msvc():
    try:
        import compare
        return os.path.exists(os.path.join(compare.MSVC, "Bin/cl.exe"))
    except Exception:       # noqa: BLE001
        return False


@unittest.skipUnless(have_msvc() and os.path.exists(os.path.join(ROOT, "config/data.json")),
                     "needs MSVC 7.1 under wibo and config/data.json")
class OverreachCompiled(unittest.TestCase):
    def test_read_past_d_colon(self):
        """linux1's FUN_00277190 shape: the byte after the 2-byte "D:" item read as DAT_0042b50c + 2."""
        tmp = tempfile.mkdtemp(prefix="tool2-or-", dir=os.path.join(ROOT, "build"))
        try:
            put(os.path.join(tmp, "include", tree_tu.PRELUDE), "\n")
            tu = os.path.join(tmp, "src/game/or.cpp")
            put(tu, '// 0x00277190 FUN_00277190 (24 B): matches\nextern "C" char DAT_0042b50c[2];\n'
                    'char FUN_00277190() { return DAT_0042b50c[2]; }\n')
            recs = tree_tu.check_tu(tu)
            kinds = [h["kind"] for r in recs for h in r.get("overreach", [])]
            self.assertEqual(kinds, ["over"])
        finally:
            shutil.rmtree(tmp)


if __name__ == "__main__":
    unittest.main()
