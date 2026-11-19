"""verify_relocs.py regression cases (need the player's XBE and build/functions.csv; skipped without them)."""
import os, sys, unittest
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))

HAVE = all(os.path.exists(os.path.join(ROOT, p)) for p in ("isos/extracted/default.xbe", "build/functions.csv",
                                                             "build/rtti.json"))


@unittest.skipUnless(HAVE, "needs the extracted XBE and build/functions.csv")
class LibName(unittest.TestCase):
    """(libname1) a CRT name must hit the address the CRT tables list for it."""

    def setUp(self):
        os.environ.pop("RELOC_OFF", None)
        import verify_relocs
        self.v = verify_relocs

    def test_wrong_library_name_fails(self):
        r = self.v.check(os.path.join(ROOT, "tests/verify_relocs/0x0033b7d0_ceil_name.cpp"), 0x0033b7d0)
        self.assertEqual(r["status"], "bad")
        self.assertIn(["libname_address_mismatch", "___ceil_default"], [list(i) for i in r["issues"]])

    def test_right_library_names_pass(self):
        import tree_index
        for a in (0x0033b7d0, 0x0033b7a0):
            r = self.v.check(tree_index.find(a)[0], a)        # (its tree TU: merge-once (d))
            self.assertEqual(r["status"], "ok", r)

    def test_plain_names(self):
        f = self.v.library_plain_name
        self.assertEqual(f("___ceil_default"), "__ceil_default")
        self.assertEqual(f("_Sleep@4"), "Sleep")
        self.assertEqual(f("?floor@@YANN@Z"), "floor")
        self.assertIsNone(f("?floor@Foo@@QAENN@Z"))



@unittest.skipUnless(HAVE, "needs the extracted XBE and build/functions.csv")
class FreeName(unittest.TestCase):
    """(integ2, D132) a call reaching one of the game's frees must use that free's own name (reported, not failing)."""

    def setUp(self):
        os.environ.pop("RELOC_OFF", None)
        import verify_relocs
        self.v = verify_relocs

    def test_names(self):
        f = self.v.free_name_issue
        self.assertIsNone(f("??3@YAXPAX@Z", 0x0008d330))
        self.assertIsNone(f("??_V@YAXPAX@Z", 0x0008d340))
        self.assertIsNone(f("??3LoadObject@content@@SAXPAX@Z", 0x00263f30))
        self.assertIsNone(f("??3LoadObject@content@fn_f1234567@@SAXPAX@Z", 0x00263f30))
        self.assertIsNone(f("_FUN_00267090", 0x00267090))
        self.assertEqual(f("_FUN_0008d340", 0x0008d340), ("free_by_other_name", "_FUN_0008d340"))
        self.assertEqual(f("??3@YAXPAX@Z", 0x0008d340), ("free_by_other_name", "??3@YAXPAX@Z"))   # delete for delete[]
        self.assertEqual(f("?free_@@YAXPAX@Z", 0x00267090), ("free_by_other_name", "?free_@@YAXPAX@Z"))
        self.assertIsNone(f("_FUN_00012345", 0x00012345))      # not a free
        # through the game's one-jmp thunk 0x00263f40 (Ghidra's thunk_FUN_00267090) to operator delete 0x0008d330
        self.assertEqual(self.v.free_reached(0x00263f40), 0x0008d330)
        self.assertEqual(f("?thunk_FUN_00267090@@YAXPAX@Z", 0x00263f40),
                         ("free_by_other_name", "?thunk_FUN_00267090@@YAXPAX@Z"))
        self.assertIsNone(f("??3@YAXPAX@Z", 0x00263f40))
        self.assertEqual(f("_thunk_FUN_00267090", 0x0008d330), ("free_by_other_name", "_thunk_FUN_00267090"))

    def test_block_reported_soft(self):
        r = self.v.check(os.path.join(ROOT, "tests/verify_relocs/0x0012e2c0_free_name.cpp"), 0x0012e2c0)
        self.assertIn(["free_by_other_name", "_FUN_0008d340"], [list(i) for i in r["issues"]])
        self.assertEqual(r["status"], "ok")                   # report-only until nat2's conversion


if __name__ == "__main__":
    unittest.main()
