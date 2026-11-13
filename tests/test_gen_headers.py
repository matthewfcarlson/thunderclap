"""Tests for tools/gen_headers.py, the layout checker of include/gen/ (hand-maintained source since gen1).
Name helpers and the constructor scan need nothing; the model needs build/rtti.json, build/functions.csv and the
XBE; the probe also needs MSVC 7.1 under wibo. Each skips without its inputs."""
import os, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import gen_headers as gh

ROOT = gh.ROOT
HAVE_MODEL = all(os.path.exists(os.path.join(ROOT, p)) for p in
                 ("build/rtti.json", "build/functions.csv", "isos/extracted/default.xbe"))
HAVE_CL = os.path.exists(gh.WIBO) and os.path.exists(os.path.join(gh.MSVC, "Bin/cl.exe"))


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


class DeclaredCtors(unittest.TestCase):
    TEXT = """namespace fight {
class Track;
} // namespace fight
namespace fight {
// .?AVTrack@fight@@
HULK_REFCOUNT_PACK
class Track : public ::fight::Param {
public:
    Track(); // (unb5) out of line
    virtual ~Track() throw(); // overrides fight::Param slot 5
    void* f_08;
};
template <class T0>
class TrackFactoryTemplate : public ::fight::TrackFactory {
public:
    TrackFactoryTemplate(int a);
};
} // namespace fight
namespace hulkfight { namespace ai {
class Plan {
public:
    explicit Plan(int a = 0, void* b);
    int Plan_count;
};
}} // namespace hulkfight::ai
class Outer::Inner : public ::Base {
public:
    Inner(const char*);
};
class Free {
public:
    Free() {}
};
"""

    def test_scan(self):
        self.assertEqual(gh.declared_ctors(self.TEXT), {
            "fight::Track": [[]],
            "hulkfight::ai::Plan": [["int a", "void* b"]],
            "Outer::Inner": [["const char*"]],
        })


@unittest.skipUnless(HAVE_MODEL, "needs build/rtti.json, build/functions.csv and the XBE")
class ModelFacts(unittest.TestCase):
    def test_noncopyable(self):
        m = gh.Model()
        idx = m.index()
        self.assertEqual(len(idx), len(m.classes))
        e = idx["pure3d::NonCopyable"]
        self.assertEqual(e["header"], "pure3d.h")
        self.assertEqual(e["cpp"], "::pure3d::NonCopyable")
        # AddRef/Release overrides, the destructor in slot 2 (declared by every class: its own implementer)
        self.assertEqual([s[:2] for s in e["slots"]["0"]],
                         [["core::IRefCount", 0], ["core::IRefCount", 1], ["core::IRefCount", 2]])
        self.assertEqual(e["slots"]["0"][2][2], "pure3d::NonCopyable")
        self.assertIn(("core::IRefCount", 2), m.dtor)


@unittest.skipUnless(HAVE_MODEL and HAVE_CL, "needs the model inputs and MSVC 7.1 under wibo")
class Probe(unittest.TestCase):
    def test_headers_check(self):
        """Every header compiles; every class's vftables, slots, base descriptors and recorded size hold."""
        total, problems, _, _ = gh.probe()
        self.assertEqual(problems, [])
        self.assertEqual(total["headers"], total["headers_ok"])
        self.assertEqual(total["classes"], total["classes_ok"])
        self.assertGreater(total["sizes_ok"], 4000)

    def test_size_change_is_reported(self):
        """A recorded size the headers no longer have is a problem (the ratchet for 32-bit layouts)."""
        sizes = dict(gh.load_sizes(), **{"pure3d::NonCopyable": 12})
        total, problems, _, _ = gh.probe(["pure3d"], sizes=sizes)
        self.assertTrue(any(p.startswith("pure3d::NonCopyable: sizeof 8, recorded 12") for p in problems), problems)


if __name__ == "__main__":
    unittest.main()
