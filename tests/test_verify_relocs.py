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
        # content::LoadObject's operator delete[] 0x00263f40 (a jmp to 0x0008d330) has a name of its own (nat2)
        self.assertEqual(self.v.free_reached(0x00263f40), 0x00263f40)
        self.assertIsNone(f("??_VLoadObject@content@@SAXPAX@Z", 0x00263f40))
        self.assertEqual(f("?thunk_FUN_00267090@@YAXPAX@Z", 0x00263f40),
                         ("free_by_other_name", "?thunk_FUN_00267090@@YAXPAX@Z"))
        self.assertEqual(f("??3@YAXPAX@Z", 0x00263f40), ("free_by_other_name", "??3@YAXPAX@Z"))
        self.assertEqual(f("_thunk_FUN_00267090", 0x0008d330), ("free_by_other_name", "_thunk_FUN_00267090"))

    def test_by_name(self):
        # (integ3, D149 equivalent blocks) by the address the name itself gives
        f = self.v.free_name_by_name
        self.assertEqual(f("_FUN_0008d340"), ("free_by_other_name", "_FUN_0008d340"))
        self.assertEqual(f("?thunk_FUN_00267090@@YAXPAX@Z"), ("free_by_other_name", "?thunk_FUN_00267090@@YAXPAX@Z"))
        self.assertEqual(f("?Free_00263f30@@YAXPAX@Z"), ("free_by_other_name", "?Free_00263f30@@YAXPAX@Z"))
        self.assertIsNone(f("??_V@YAXPAX@Z"))             # a free's own name
        self.assertIsNone(f("_FUN_00267090"))             # the heap free's own name
        self.assertIsNone(f("?free_@@YAXPAX@Z"))          # no address in the name: xtu_check's (tree-wide)
        self.assertIsNone(f("_FUN_00012345"))             # not a free

    def test_block_reported_soft(self):
        r = self.v.check(os.path.join(ROOT, "tests/verify_relocs/0x0012e2c0_free_name.cpp"), 0x0012e2c0)
        self.assertIn(["free_by_other_name", "_FUN_0008d340"], [list(i) for i in r["issues"]])
        self.assertEqual(r["status"], "ok")                   # report-only until nat2's conversion


class FreeAddressTaken(unittest.TestCase):
    """(integ3, D132 item 6) a free's address stored as data (a deleter pointer, a deleter table the TU defines) must
    carry the free's own name. The original never stores a free's address (no dword of the image is one), so the
    case is built on a synthetic image: the test object's own bytes with each relocated operand set to the game's
    operator delete[] (0x0008d340), as a byte-matched block storing it would have them."""

    TEXT, DATA = 0x00011000, 0x00500000

    def image(self, coff, funcs, table):
        """A stand-in Xbe: .text 0x11000.. holding FUNCS (name -> va) with every DIR32 operand to a code symbol
        set to 0x0008d340, and .data holding TABLE (va, entries)."""
        import struct
        import xbe as X
        text = bytearray(0x00300000 - self.TEXT)
        for name, va in funcs.items():
            sym = next(s for s in coff.function_symbols() if s[0] == name)
            _, code, _ = coff.function(sym)
            o = va - self.TEXT
            text[o:o + len(code)] = code
            for off, t, typ, _ in coff.function_relocs(sym):
                if typ == self.v.DIR32 and t is not None:
                    want = 0x0008d340 if t[0] in ("_FUN_0008d340", "??_V@YAXPAX@Z") else table[0]
                    text[o + off:o + off + 4] = struct.pack("<I", want)
        data = bytearray(0x1000)
        for k, e in enumerate(table[1]):
            data[4 * k:4 * k + 4] = struct.pack("<I", e)
        img = X.Xbe.__new__(X.Xbe)
        img.data = bytes(text) + bytes(data)
        img.base = 0x10000
        img.sections = [X.Section(".text", self.TEXT, len(text), 0, len(text), 0),
                        X.Section(".data", self.DATA, len(data), len(text), len(data), 0)]
        return img

    def setUp(self):
        os.environ["RELOC_OFF"] = "addrlit,thisdecl,libname"     # (those read the real image; not under test)
        import verify_relocs
        self.v = verify_relocs

    def tearDown(self):
        os.environ.pop("RELOC_OFF", None)

    def run_case(self):
        import tempfile
        import compare
        src = os.path.join(ROOT, "tests/verify_relocs/free_address_taken.cpp")
        with tempfile.TemporaryDirectory() as tmp:
            try:
                coff = compare.Coff(compare.compile_obj(src, compare.DEFAULT_FLAGS, tmp))
            except Exception as e:     # noqa: BLE001
                self.skipTest("no MSVC: %r" % e)
        funcs = {"?SetBad@@YAXPAURec@@@Z": 0x00020000, "?SetGood@@YAXPAURec@@@Z": 0x00020100,
                 "?UseTable@@YAPAP6AXPAX@ZXZ": 0x00020200}
        img = self.image(coff, funcs, (self.DATA, [0x0008d340, 0x0008d340]))
        saved = dict(self.v._state)
        self.v._state.clear()
        self.v._state.update(xbe=img, funcs={0x0008d340} | set(funcs.values()), vftables={})
        try:
            out = {}
            for name, va in funcs.items():
                sym = next(s for s in coff.function_symbols() if s[0] == name)
                out[name] = self.v.check_object(coff, sym, va)
            return out, img
        finally:
            self.v._state.clear()
            self.v._state.update(saved)

    def test_stored_free(self):
        r, img = self.run_case()
        bad, good, tab = (r["?SetBad@@YAXPAURec@@@Z"], r["?SetGood@@YAXPAURec@@@Z"],
                          r["?UseTable@@YAPAP6AXPAX@ZXZ"])
        # must flag: the deleter stored under its address name
        self.assertIn(["free_by_other_name", "_FUN_0008d340"], [list(i) for i in bad["issues"]])
        self.assertEqual([f["how"] for f in bad["free_refs"]], ["address"])
        self.assertEqual(bad["status"], "ok")                 # SOFT, like the direct calls
        # must not flag: the free's own name
        self.assertNotIn("free_by_other_name", [i[0] for i in good["issues"]])
        self.assertNotIn("free_refs", good)
        # a table the TU defines: entry 0 under the address name is reported, entry 1 (own name) is not
        self.assertEqual([(f["name"], f["how"]) for f in tab["free_refs"]],
                         [("_FUN_0008d340", "table _g_deleters+0x0")])

        # a DIR32 operand outside .text (the table itself) is never followed as a thunk to a free
        self.assertIsNone(self.v.free_address_issue("_FUN_0008d340", self.DATA, xbe=img))

if __name__ == "__main__":
    unittest.main()
