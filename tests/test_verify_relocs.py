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
        for a in (0x0033b7d0, 0x0033b7a0):
            r = self.v.check(os.path.join(ROOT, "matches/0x%08x.cpp" % a), a)
            self.assertEqual(r["status"], "ok", r)

    def test_plain_names(self):
        f = self.v.library_plain_name
        self.assertEqual(f("___ceil_default"), "__ceil_default")
        self.assertEqual(f("_Sleep@4"), "Sleep")
        self.assertEqual(f("?floor@@YANN@Z"), "floor")
        self.assertIsNone(f("?floor@Foo@@QAENN@Z"))


if __name__ == "__main__":
    unittest.main()
