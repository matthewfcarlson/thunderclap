"""Tests for tools/gen_headers.py. Name helpers need nothing; the regeneration check needs
build/rtti.json, build/functions.csv and the XBE, and skips without them."""
import filecmp, os, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import gen_headers as gh

ROOT = gh.ROOT


class Names(unittest.TestCase):
    def test_split(self):
        self.assertEqual(gh.split_top("a::B<class c::D,int>::E", "::"), ["a", "B<class c::D,int>", "E"])
        self.assertEqual(gh.split_template("Method1<class A,void,const char *>"),
                         ("Method1", ["class A", "void", "const char *"]))
        self.assertEqual(gh.split_template("Plain"), ("Plain", None))

    def test_render(self):
        self.assertEqual(gh.render_type("class om::DynAttrT<class om::String>"), "::om::DynAttrT< ::om::String >")
        self.assertEqual(gh.render_type("const class math::Vector"), "const ::math::Vector")
        self.assertEqual(gh.elaborated_types("class a::B<struct C> *"), [("class", "a::B<struct C>"), ("struct", "C")])

    def test_csv_name(self):
        self.assertEqual(gh.csv_name("Method1<class CActorManager,void,const char *>"),
                         "Method1<CActorManager,void,const_char_*>")

    def test_mangled_num(self):
        self.assertEqual(gh.mangled_num("A@", 0), (0, 2))
        self.assertEqual(gh.mangled_num("?0", 0), (-1, 2))
        self.assertEqual(gh.mangled_num("3", 0), (4, 1))
        self.assertEqual(gh.mangled_num("LM@", 0), (0xBC, 3))

    def test_fields(self):
        self.assertEqual(gh.decl_field("int", "f_04"), "int f_04")
        self.assertEqual(gh.decl_field("char[0x10]", "f_08"), "char f_08[0x10]")
        self.assertEqual(gh.decl_field(("T1 (T0::*%s)()", 4), "f_1c"), "T1 (T0::*f_1c)()")
        self.assertEqual(gh.type_size("short[3]"), 6)


@unittest.skipUnless(all(os.path.exists(os.path.join(ROOT, p)) for p in
                         ("build/rtti.json", "build/functions.csv", "isos/extracted/default.xbe")),
                     "needs build/rtti.json, build/functions.csv and the XBE")
class Regenerate(unittest.TestCase):
    def test_committed_headers_are_current(self):
        ev = gh.json.load(open(gh.EVIDENCE_PATH)) if os.path.exists(gh.EVIDENCE_PATH) else {}
        g = gh.Gen(ev)
        with tempfile.TemporaryDirectory() as d:
            headers = g.generate(d, None)
            self.assertIn("pure3d", headers)
            self.assertEqual(len(g.index), len(g.classes))
            names = sorted(f for f in os.listdir(d) if f.endswith(".h"))
            self.assertEqual(names, sorted(f for f in os.listdir(gh.OUT_DIR) if f.endswith(".h")))
            _, mismatch, errors = filecmp.cmpfiles(d, gh.OUT_DIR, names, shallow=False)
            self.assertEqual(mismatch + errors, [], "include/gen is stale: rerun tools/gen_headers.py")
        # NonCopyable: AddRef/Release overrides, destructor in slot 2, proven refcount at +4
        e = g.index["pure3d::NonCopyable"]
        self.assertEqual(e["size"], 8)
        self.assertEqual([s[:2] for s in e["slots"]["0"]], [["core::IRefCount", 0], ["core::IRefCount", 1], ["core::IRefCount", 2]])
        self.assertIn(("core::IRefCount", 2), g.dtor)


if __name__ == "__main__":
    unittest.main()
