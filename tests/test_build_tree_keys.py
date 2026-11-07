"""Object cache keys of tools/build_tree.py: every header a TU can see must be part of its key.
Runs on a temporary include/ tree; needs nothing from build/."""
import os, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import build_tree as bt


def write(root, rel, text):
    p = os.path.join(root, rel)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w") as f:
        f.write(text)


class GenDigest(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.inc = self.tmp.name
        write(self.inc, "gen/_prelude.h", '#include "compat/ptr.h"\n')
        write(self.inc, "gen/global.h", '#include "_prelude.h"\nstruct A { int a; };\n')
        write(self.inc, "decls/address.h", "void FUN_00010000();\n")
        write(self.inc, "decls/data/records.h", '#include "compat/ptr.h"\n')
        write(self.inc, "decls/data/game/global.h", "extern int DAT_00400000;\n")
        write(self.inc, "compat/ptr.h", "typedef int hulk_intptr;\n")
        self.saved = bt.GEN_INCLUDE_ROOT, list(bt._GEN_DIGEST)

    def tearDown(self):
        bt.GEN_INCLUDE_ROOT = self.saved[0]
        bt._GEN_DIGEST[:] = self.saved[1]
        self.tmp.cleanup()

    def digest(self, text):
        bt.GEN_INCLUDE_ROOT = self.inc
        del bt._GEN_DIGEST[:]
        return bt.gen_digest(text)

    def test_nested_decls_header(self):
        tu = '#include "decls/data/game/global.h"\nint f() { return DAT_00400000; }\n'
        before = self.digest(tu)
        write(self.inc, "decls/data/game/global.h", "extern short DAT_00400000;\n")
        self.assertNotEqual(before, self.digest(tu))

    def test_compat_header(self):
        tu = '#include "gen/global.h"\n'
        before = self.digest(tu)
        write(self.inc, "compat/ptr.h", "typedef long hulk_intptr;\n")
        self.assertNotEqual(before, self.digest(tu))

    def test_compat_only_source(self):
        tu = '#include "compat/ptr.h"\nhulk_intptr g;\n'
        before = self.digest(tu)
        self.assertNotEqual(before, b"")
        write(self.inc, "compat/ptr.h", "typedef long hulk_intptr;\n")
        self.assertNotEqual(before, self.digest(tu))

    def test_new_header(self):
        tu = '#include "gen/global.h"\n'
        before = self.digest(tu)
        write(self.inc, "decls/data/engine/new.h", "extern int DAT_00500000;\n")
        self.assertNotEqual(before, self.digest(tu))


if __name__ == "__main__":
    unittest.main()
