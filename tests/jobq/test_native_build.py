"""Unit tests for tools/native_build_run.py / native_build_job.py (source sync, rebuild policy, overlay): no hosts needed.

  python3 -m unittest tests.jobq.test_native_build     (from the repo root)
"""
import os
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import native_build_run as nb  # noqa: E402


def put(root, rel, text):
    p = os.path.join(root, rel)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w") as f:
        f.write(text)


class Sync(unittest.TestCase):
    def setUp(self):
        self.run, self.lin = tempfile.mkdtemp(), tempfile.mkdtemp()
        put(self.run, "matches/0x1.cpp", "a")
        put(self.run, "tools/build_tree.py", "import gen_tree\n")
        put(self.run, "tools/gen_tree.py", "x = 1\n")
        put(self.run, "tools/wine_link.py", "import native_host\nL = '/opt/homebrew/opt/llvm/bin'\n")
        put(self.run, "tools/native_host.py", "")
        put(self.run, "tools/unrelated.py", "")

    def test_content_sync_add_modify_remove(self):
        m1, ch = nb.sync_sources(self.run, self.lin, [])
        self.assertEqual(len(ch["added"]), 6)
        m2, ch = nb.sync_sources(self.run, self.lin, [])
        self.assertEqual((ch["added"], ch["modified"], ch["removed"]), ([], [], []))
        put(self.run, "matches/0x1.cpp", "b")
        put(self.run, "matches/0x2.cpp", "c")
        m3, ch = nb.sync_sources(self.run, self.lin, ["tools/unrelated.py"])
        self.assertEqual((ch["added"], ch["modified"], ch["removed"]), (["matches/0x2.cpp"], ["matches/0x1.cpp"], ["tools/unrelated.py"]))
        self.assertEqual(open(os.path.join(self.lin, "matches/0x1.cpp")).read(), "b")
        self.assertFalse(os.path.exists(os.path.join(self.lin, "tools/unrelated.py")))
        os.unlink(os.path.join(self.lin, "matches/0x2.cpp"))       # a file lost from the lineage is restored, not trusted
        _, ch = nb.sync_sources(self.run, self.lin, [])
        self.assertTrue(os.path.exists(os.path.join(self.lin, "matches/0x2.cpp")))

    def test_homebrew_paths_rewritten_only_in_lineage(self):
        if os.path.exists(os.path.join(nb.HOMEBREW_LLVM, "llvm-undname")):
            self.skipTest("this host has Homebrew LLVM")
        m, ch = nb.sync_sources(self.run, self.lin, [])
        self.assertNotIn("/opt/homebrew", open(os.path.join(self.lin, "tools/wine_link.py")).read())
        self.assertIn("/opt/homebrew", open(os.path.join(self.run, "tools/wine_link.py")).read())

    def test_closure(self):
        self.assertEqual(nb.closure(os.path.join(self.run, "tools"), "build_tree"), {"tools/build_tree.py", "tools/gen_tree.py"})


class Decide(unittest.TestCase):
    def setUp(self):
        self.lin = tempfile.mkdtemp()
        put(self.lin, "tools/build_tree.py", "import gen_tree\n")
        put(self.lin, "tools/gen_tree.py", "")
        put(self.lin, "tools/wine_link.py", "")
        put(self.lin, "build/tree/state.json", "{}")
        put(self.lin, "build/native/bindings.json", "{}")
        self.base = {"matches/a.cpp": "1", "tools/gen_tree.py": "g", "tools/wine_link.py": "n", "include/x.h": "h"}

    def d(self, new, spec=None, built="same", mapped="same"):
        return nb.decide(spec or {}, self.base if built == "same" else built, self.base if mapped == "same" else mapped, new, self.lin)

    def test_modified_function_source_resumes_and_reuses_map(self):
        new = dict(self.base, **{"matches/a.cpp": "2"})
        r, m, why = self.d(new)
        self.assertEqual((r, m), (True, True))

    def test_header_or_generator_change_goes_fresh(self):
        for k in ("include/x.h", "tools/gen_tree.py"):
            r, m, why = self.d(dict(self.base, **{k: "x"}))
            self.assertEqual((r, m), (False, False), k)

    def test_added_source_resumes_but_remaps(self):
        r, m, why = self.d(dict(self.base, **{"matches/b.cpp": "1"}))
        self.assertEqual((r, m), (True, False))

    def test_link_tool_change_remaps_but_keeps_tree_state(self):
        r, m, why = self.d(dict(self.base, **{"tools/wine_link.py": "n2"}))
        self.assertEqual((r, m), (True, False))

    def test_requests_and_first_build(self):
        r, m, why = self.d(self.base, {"state": "fresh"})
        self.assertEqual((r, m), (False, False))
        r, m, why = self.d(self.base, {"map": "full"})
        self.assertEqual((r, m), (True, False))
        r, m, why = self.d(self.base, built=None, mapped=None)
        self.assertEqual((r, m), (False, False))


if __name__ == "__main__":
    unittest.main()
