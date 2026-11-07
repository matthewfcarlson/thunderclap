"""tools/build_tree.py: the object cache keys (every header a TU can see must be part of its key) and --seed.
Runs on temporary files; needs nothing from build/."""
import os, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import build_tree as bt


def write(root, rel, text):
    p = os.path.join(root, rel)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w") as f:
        f.write(text)


class TuKey(unittest.TestCase):
    """tu_key: a TU's key covers the headers it can reach (include_keys.closure), and only those."""
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        r = self.root = self.tmp.name
        write(r, "include/gen/_prelude.h", '#include "compat/ptr.h"\n')
        write(r, "include/gen/global.h", '#include "_prelude.h"\n#include "core.h"\nstruct A { int a; };\n')
        write(r, "include/gen/core.h", '#include "_prelude.h"\n')
        write(r, "include/gen/fight.h", "struct F;\n")
        write(r, "include/decls/address.h", "void FUN_00010000();\n")
        write(r, "include/decls/data/records.h", '#include "compat/ptr.h"\n')
        write(r, "include/decls/data/game/global.h", '#include "decls/data/records.h"\nextern int DAT_00400000;\n')
        write(r, "include/decls/data/game/unknown.h", "extern int DAT_00400004;\n")
        write(r, "include/compat/ptr.h", "typedef int hulk_intptr;\n")
        write(r, "build/tree/include/common.h", "#pragma once\n")
        write(r, "build/tree/include/game/global.h", '#include "common.h"\nvoid g();\n')
        write(r, "build/tree/include/engine/core.h", '#include "common.h"\nvoid c();\n')
        self.tu = os.path.join(r, "build/tree/src/game/global/A.cpp")
        write(r, "build/tree/src/game/global/A.cpp", '#include "game/global.h"\n#include "gen/global.h"\n'
                                                     '#include "decls/data/game/global.h"\nint f() { return DAT_00400000; }\n')
        self.saved = bt.ROOT, bt.INCLUDE_DIR, bt.GEN_INCLUDE_ROOT
        bt.ROOT, bt.INCLUDE_DIR, bt.GEN_INCLUDE_ROOT = r, os.path.join(r, "build/tree/include"), os.path.join(r, "include")

    def tearDown(self):
        bt.ROOT, bt.INCLUDE_DIR, bt.GEN_INCLUDE_ROOT = self.saved
        self.tmp.cleanup()

    def key(self):
        bt.include_keys.reset()
        return bt.tu_key(self.tu, open(self.tu, "rb").read(), ["/O2"])

    def changes(self, rel, text):
        before = self.key()
        write(self.root, rel, text)
        return before != self.key()

    def test_nested_decls_header(self):
        self.assertTrue(self.changes("include/decls/data/game/global.h", "extern short DAT_00400000;\n"))

    def test_transitive_records_and_compat(self):
        self.assertTrue(self.changes("include/decls/data/records.h", "// x\n"))
        self.assertTrue(self.changes("include/compat/ptr.h", "typedef long hulk_intptr;\n"))

    def test_gen_header_through_another(self):
        self.assertTrue(self.changes("include/gen/core.h", "struct C;\n"))

    def test_tree_header_and_common(self):
        self.assertTrue(self.changes("build/tree/include/game/global.h", '#include "common.h"\nvoid g2();\n'))
        self.assertTrue(self.changes("build/tree/include/common.h", "#pragma once\n// y\n"))

    def test_header_it_cannot_see_keeps_the_key(self):
        self.assertFalse(self.changes("include/gen/fight.h", "struct F2;\n"))
        self.assertFalse(self.changes("include/decls/data/game/unknown.h", "extern int DAT_00400008;\n"))

    def test_quoted_name_resolves_through_every_includer_directory(self):
        # "core.h" (from include/gen/global.h) is also looked up in build/tree/include/engine/ once a file from
        # there is in the closure: conservative, so editing that one changes the key as soon as it is reachable
        self.assertFalse(self.changes("build/tree/include/engine/core.h", "void c2();\n"))
        write(self.root, "build/tree/include/game/global.h", '#include "common.h"\n#include "engine/core.h"\n')
        self.assertTrue(self.changes("build/tree/include/engine/core.h", "void c3();\n"))

    def test_new_shadowing_header(self):
        # a header added in front of the one in use (the TU's own directory comes first)
        self.assertTrue(self.changes("build/tree/src/game/global/common.h", "#error shadow\n"))
        self.assertTrue(self.changes("build/tree/src/game/global/gen/global.h", "#error shadow\n"))

    def test_computed_include_hashes_everything(self):
        write(self.root, "build/tree/src/game/global/A.cpp", "#define H <x.h>\n#include H\n")
        self.assertTrue(self.changes("include/gen/fight.h", "struct F3;\n"))

    def test_standalone_key_sees_include(self):
        src = os.path.join(self.root, "matches/0x00010000.cpp")
        write(self.root, "matches/0x00010000.cpp", '#include "compat/ptr.h"\nhulk_intptr g;\n')
        k = lambda: (bt.include_keys.reset(), bt._key(src, open(src, "rb").read(), [], bt.compile_include_env()))[1]
        before = k()
        write(self.root, "include/compat/ptr.h", "typedef long hulk_intptr;\n")
        self.assertNotEqual(before, k())


class SeedState(unittest.TestCase):
    def setUp(self):
        import json
        self.tmp = tempfile.TemporaryDirectory()
        d = self.tmp.name
        write(d, "splits.json", json.dumps({"objects": [{"start": "0x00010000", "end": "0x00020000", "file": "a.cpp", "kind": "game"},
                                                        {"start": "0x00020000", "end": "0x00030000", "file": "b.cpp", "kind": "game"}]}))
        write(d, "seed.json", json.dumps({"wrap": {"0x00010010": "w", "0x00020010": "w"}, "isolate": {"0x00010020": "i"},
                                          "local_only": [["h", "sym"]], "iso_plain": {"0x00020020": "p"}}))
        self.saved = bt.gen_tree.SPLITS, bt.gen_tree.STATE
        bt.gen_tree.SPLITS, bt.gen_tree.STATE = os.path.join(d, "splits.json"), os.path.join(d, "tree/state.json")

    def tearDown(self):
        bt.gen_tree.SPLITS, bt.gen_tree.STATE = self.saved
        self.tmp.cleanup()

    def test_drops_the_changed_objects_fallbacks(self):
        import contextlib, io, json
        with contextlib.redirect_stdout(io.StringIO()):
            bt.seed_state(os.path.join(self.tmp.name, "seed.json"), [0x00010030])
        s = json.load(open(bt.gen_tree.STATE))
        self.assertEqual(s["wrap"], {"0x00020010": "w"})
        self.assertEqual(s["isolate"], {})
        self.assertEqual(s["iso_plain"], {"0x00020020": "p"})
        self.assertEqual(s["local_only"], [])

    def test_no_changes_keeps_the_fallbacks(self):
        import contextlib, io, json
        with contextlib.redirect_stdout(io.StringIO()):
            bt.seed_state(os.path.join(self.tmp.name, "seed.json"), [])
        s = json.load(open(bt.gen_tree.STATE))
        self.assertEqual(len(s["wrap"]) + len(s["isolate"]) + len(s["iso_plain"]), 4)


if __name__ == "__main__":
    unittest.main()
