"""tree_tu.inputs_digest (hash3): verify's `inputs` names the files it checked by content, the same wherever the tree
lies (the checkout, materialize's build/tree, a queue job's workspace), and changes with any TU or header text.

  build/venv/bin/python -m unittest tests.test_tree_tu_inputs        # no compiler
"""
import os
import shutil
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu  # noqa: E402

TU = "// 0x00001000 FUN_00001000 (4 B): matches\nint f() { return 1; }\n"


def put(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as f:
        f.write(text)


class Inputs(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.mkdtemp(prefix="hash3-inputs-")

    def tearDown(self):
        shutil.rmtree(self.tmp)

    def tree(self, name, headers=None, tu=TU, rel="src/game/a.cpp"):
        r = os.path.join(self.tmp, name)
        put(os.path.join(r, "include", tree_tu.PRELUDE), "// prelude\n")
        for h, t in (headers or {"game/x.h": "struct X { int a; };\n"}).items():
            put(os.path.join(r, "include", h), t)
        put(os.path.join(r, rel), tu)
        return os.path.join(r, rel)

    def test_same_content_same_digest_anywhere(self):
        a = self.tree("checkout")
        b = self.tree(os.path.join("deeper", "build", "tree"))
        self.assertEqual(tree_tu.inputs_digest([a]), tree_tu.inputs_digest([b]))

    def test_header_edit_changes_headers(self):
        a = self.tree("a")
        b = self.tree("b", {"game/x.h": "struct X { int a; int b; };\n"})
        da, db = tree_tu.inputs_digest([a]), tree_tu.inputs_digest([b])
        self.assertEqual(da["tus"], db["tus"])
        self.assertNotEqual(da["headers"], db["headers"])

    def test_added_header_changes_headers(self):
        a = self.tree("a")
        b = self.tree("b", {"game/x.h": "struct X { int a; };\n", "game/y.h": "\n"})
        self.assertNotEqual(tree_tu.inputs_digest([a])["headers"], tree_tu.inputs_digest([b])["headers"])

    def test_tu_text_and_path_change_tus(self):
        a = self.tree("a")
        b = self.tree("b", tu=TU.replace("return 1", "return 2"))
        c = self.tree("c", rel="src/game/b.cpp")
        da = tree_tu.inputs_digest([a])
        self.assertNotEqual(da["tus"], tree_tu.inputs_digest([b])["tus"])
        self.assertNotEqual(da["tus"], tree_tu.inputs_digest([c])["tus"])

    def test_reach_only_what_the_tus_include(self):
        """`reach` (tool2): the files the TUs can #include; an edit elsewhere under include/ changes only `headers`."""
        tu = '// 0x00001000 FUN_00001000 (4 B): matches\n#include "game/x.h"\nint f() { return 1; }\n'
        a = self.tree("a", {"game/x.h": "struct X { int a; };\n", "game/y.h": "\n"}, tu=tu)
        b = self.tree("b", {"game/x.h": "struct X { int a; };\n", "game/y.h": "// edited\n"}, tu=tu)
        c = self.tree("c", {"game/x.h": "struct X { int b; };\n", "game/y.h": "\n"}, tu=tu)
        da, db, dc = (tree_tu.inputs_digest([p]) for p in (a, b, c))
        self.assertEqual(da["reach"], db["reach"])
        self.assertNotEqual(da["headers"], db["headers"])
        self.assertNotEqual(da["reach"], dc["reach"])
        self.assertEqual(sorted(tree_tu.reach_files([a])), ["include/game/x.h"])

    def test_order_of_paths_does_not_matter(self):
        a = self.tree("a")
        b = os.path.join(self.tmp, "a", "src/game/b.cpp")
        put(b, TU)
        self.assertEqual(tree_tu.inputs_digest([a, b]), tree_tu.inputs_digest([b, a]))


if __name__ == "__main__":
    unittest.main()
