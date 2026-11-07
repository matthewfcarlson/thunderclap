"""tools/gen_tree.py compatible(): which declarations of one name can share a TU's scope. Runs on source text only;
needs nothing from build/.

  build/venv/bin/python -m unittest tests/test_gen_tree_compat.py
"""
import os, sys, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import gen_tree as g


def cvariant(text, name, addr):
    """The canonical variant gen_tree gives `name` in a block made of `text` (a source of one function)."""
    b = g.Block(addr, 4, "f", "m", "x.cpp", text)
    b.orig_decls = list(b.decls)
    return [v for v in g.block_cvariants(b) if v[0] == name][0][2]


DEF = "struct T;\nchar Find(T* t, int k) { return 0; }\n"
USE = "struct T;\nchar Find(T*, int);\nvoid FUN_00002000(T* t) { Find(t, 1); }\n"


class CxxRedeclaration(unittest.TestCase):
    """A C++ declaration and the definition of the same function (a merged TU holds both)."""

    def test_declaration_beside_its_definition(self):
        # (reg5) the declaration's signature keeps its `;`: compared with it, the pair was never compatible
        d, u = cvariant(DEF, "Find", 0x1000), cvariant(USE, "Find", 0x2000)
        self.assertEqual(d[0], "def")
        self.assertEqual(u[0], "func")
        self.assertTrue(u[3].endswith(";"))
        self.assertTrue(g.compatible(d, u))
        self.assertTrue(g.compatible(u, d))

    def test_other_return_type(self):
        d = cvariant(DEF, "Find", 0x1000)
        u = cvariant(USE.replace("char Find", "int Find"), "Find", 0x2000)
        self.assertFalse(g.compatible(d, u))

    def test_overload(self):
        d = cvariant(DEF, "Find", 0x1000)
        u = cvariant(USE.replace("Find(T*, int)", "Find(T*, char)").replace("(t, 1)", "(t, 'a')"), "Find", 0x2000)
        self.assertTrue(g.compatible(d, u))

    def test_switch_off(self):
        d, u = cvariant(DEF, "Find", 0x1000), cvariant(USE, "Find", 0x2000)
        g.GEN_OFF.add("defsig")
        try:
            self.assertFalse(g.compatible(d, u))
        finally:
            g.GEN_OFF.discard("defsig")


if __name__ == "__main__":
    unittest.main()
