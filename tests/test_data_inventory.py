"""Tests for tools/data_inventory.py. The helpers need nothing (record sizes need libclang); the reproducibility check
needs the XBE, build/functions.csv and build/rtti.json, and skips without them: config/data.json must be exactly what
the inventory's inputs give (docs/data.md "Reproducing")."""
import json, os, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import data_inventory as di

ROOT = di.ROOT


def libclang():
    try:
        di.record_items(os.path.join(ROOT, "include/decls/data/records.h"))
        return True
    except Exception:  # noqa: BLE001
        return False


class Helpers(unittest.TestCase):
    def test_decl_type(self):
        def t(decl):
            return di.decl_type(next(di.DECL_RE.finditer(decl)))
        self.assertEqual(t('extern "C" unsigned DAT_004e21ec;'), "unsigned int")
        self.assertEqual(t('extern "C" unsigned char DAT_004ddbd0[4];'), "unsigned char[4]")   # not "unsigned int char"
        self.assertEqual(t('extern "C" unsigned  short DAT_00400000;'), "unsigned short")
        self.assertEqual(t('extern "C" float DAT_003f32d8;'), "float")
        self.assertEqual(t('extern const char DAT_003ffd00[];'), "const char[]")

    def test_canon_type(self):
        """The inventory's one spelling of a type; `unsigned int char` (an old bug that the type votes from
        config/data.json carried on) is `unsigned char`."""
        for t, want in (("unsigned int char", "unsigned char"), ("const unsigned int char[]", "const unsigned char[]"),
                        ("unsigned int short *", "unsigned short *"), ("unsigned int __int64", "unsigned __int64"),
                        ("unsigned int long long", "unsigned long long"), ("unsigned", "unsigned int"),
                        ("unsigned  char[4]", "unsigned char[4]"), ("unsigned int", "unsigned int"),
                        ("unsigned char *", "unsigned char *"), (None, None)):
            self.assertEqual(di.canon_type(t), want, t)
            if t:
                self.assertEqual(di.canon_type(di.canon_type(t)), want, t)

    def test_previous_types_canonical(self):
        """A type config/data.json still spells the old way votes in its canonical spelling."""
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "data.json")
            with open(p, "w") as f:
                f.write('{"items":[\n  {"addr":"0x004dd8e4","size":1,"kind":"bss","type":"unsigned int char"},\n'
                        '  {"addr":"0x0049c0d8","size":1,"kind":"scalar","type":"unsigned char",'
                        '"source_type":"unsigned int char"}\n]}\n')
            self.assertEqual(di.previous_items(p), {0x4dd8e4: (1, "unsigned char", "unsigned char"),
                                                    0x49c0d8: (1, "unsigned char", "unsigned char")})

    def test_operand_ref(self):
        """Absolute addresses in operands: immediates, and memory displacements with or without a base or index
        register (`[eax + 0x426830]`: indexed, with a base); not a segment-relative one (fs:[0])."""
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        md.detail = True
        def refs(code):
            return [di.operand_ref(op) for op in next(md.disasm(bytes.fromhex(code), 0x1000)).operands]
        self.assertEqual(refs("0fb68030684200"), [None, (0x426830, True, True, True)])   # movzx eax, [eax+d]
        self.assertEqual(refs("a130684200"), [None, (0x426830, True, False, False)])           # mov eax, [d]
        self.assertEqual(refs("8b048d30684200"), [None, (0x426830, True, True, False)])        # mov eax, [ecx*4+d]
        self.assertEqual(refs("6830684200"), [(0x426830, False, False, False)])                # push d
        self.assertEqual(refs("64a100000000"), [None, None])                                   # mov eax, fs:[0]

    def test_field_refs(self):
        """A base-register displacement less than FIELD_GAP after another of the same function is a field of the
        same element, not a start; the head, and a displacement another function uses alone, stay starts."""
        class Inv:
            FIELD_GAP = di.Inventory.FIELD_GAP
        xr = [(0x372bd0, 0x372be0 + i, 0x4399a0 + i, "movzx", 1, True, True, True) for i in range(8)]
        xr += [(0x3725d0, 0x3725f0, 0x4399a1, "movzx", 1, True, True, True),
               (0x2e7fb0, 0x2e8017, 0x4d10bc, "mov", 4, True, True, True),
               (0x2e7fb0, 0x2e801d, 0x4d10d8, "mov", 4, True, True, True),    # 28 bytes on: a table of its own
               (0x2e7fb0, 0x2e8020, 0x4d10dc, "mov", 4, True, False, False)]  # absolute: never a field
        got = di.Inventory.field_refs(Inv(), xr)
        self.assertEqual(got, {(0x372bd0, 0x4399a0 + i) for i in range(1, 8)})

    def test_pins(self):
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "items.json")
            with open(p, "w") as f:
                json.dump({"items": {"0x00426824": {"size": 8, "kind": "struct", "why": "x"},
                                     "0x0040bb10": {"object": "lua/lauxlib.cpp", "type": None, "why": "y"}}}, f)
            self.assertEqual(di.load_pins(p), {0x426824: {"size": 8, "kind": "struct"},
                                               0x40bb10: {"object": "lua/lauxlib.cpp", "type": None}})
            with open(p, "w") as f:
                json.dump({"items": {"0x00426824": {"size": 8, "why": "no kind"}}}, f)
            with self.assertRaises(SystemExit):
                di.load_pins(p)

    def test_source_units(self):
        """Per function block: its own names, the TU's shared declarations; a hoisted declaration no block uses is a
        unit of its own."""
        with tempfile.TemporaryDirectory() as d:
            os.makedirs(os.path.join(d, "src/game/x"))
            with open(os.path.join(d, "src/game/x/A.cpp"), "w") as f:
                f.write('#include "decls/data/game/x.h"\nextern "C" float DAT_00500000;\nextern "C" char DAT_00500010[];\n'
                        "// 0x00010000 f (4 B): matches\nint f() { return (int)DAT_00500000; }\n"
                        "// 0x00010010 g (4 B): equivalent\nint g() { return DAT_00500000 + DAT_00500004; }\n")
            old = di.ROOT, di.TREE_DIRS, di.previous_items
            di.ROOT, di.TREE_DIRS = d, ("src/game",)
            di.previous_items = lambda path=None: {0x500004: (4, "int", "int")}
            try:
                units = di.source_units()
                names = di.source_names()
            finally:
                di.ROOT, di.TREE_DIRS, di.previous_items = old
        self.assertEqual([(u[0], sorted(u[1])) for u in units],
                         [("src/game/x/A.cpp@0", ["00500000"]), ("src/game/x/A.cpp@1", ["00500000", "00500004"]),
                          ("src/game/x/A.cpp@shared", ["00500010"])])
        self.assertEqual(names[0x500000]["sources"], 2)
        self.assertEqual(dict(names[0x500000]["types"]), {"float": 2})
        self.assertEqual(dict(names[0x500004]["types"]), {"int": 1})        # on the shared headers: the recorded type
        self.assertEqual(dict(names[0x500010]["types"]), {"char[]": 1})

    @unittest.skipUnless(libclang(), "libclang not found (clang_probe.LLVM's lib/, or HULK_LIBCLANG)")
    def test_record_sizes(self):
        """records.h spans are MSVC's 32-bit layout: 4-byte pointers, __int64 8-aligned, __declspec(align)."""
        with tempfile.TemporaryDirectory() as d:
            h = os.path.join(d, "records.h")
            with open(h, "w") as f:
                f.write('struct A { void* p; __int64 q; };\nstruct B { void* p; char c[3]; };\n'
                        'struct __declspec(align(8)) C { int x; };\n'
                        'extern "C" A DAT_00500000[2];\nextern "C" B DAT_00500020;\nextern "C" C DAT_00500028[3];\n'
                        'extern "C" void* DAT_00500040;\n')
            self.assertEqual(di.record_items(h), {0x500000: ("A[2]", 32), 0x500020: ("B", 8),
                                                  0x500028: ("C[3]", 24), 0x500040: ("void *", 4)})


@unittest.skipUnless(all(os.path.exists(os.path.join(ROOT, p)) for p in
                         ("build/rtti.json", "build/functions.csv", "isos/extracted/default.xbe")) and libclang(),
                     "needs the extracted XBE, build/functions.csv, build/rtti.json and libclang")
class Reproducible(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.items, cls.cov = di.generate()

    def test_check(self):
        """tools/data_inventory.py --check: config/data.json is what the inputs give (no hand edits)."""
        self.assertEqual(di.check(self.items, self.cov), 0)

    def edited(self, edit):
        """A copy of config/data.json with EDIT(row) applied to one row of each kind it accepts (returns True)."""
        d = tempfile.mkdtemp()
        p = os.path.join(d, "data.json")
        with open(di.OUT) as f, open(p, "w") as g:
            done = set()
            for line in f:
                if line.lstrip().startswith('{"addr":'):
                    end = ",\n" if line.endswith(",\n") else "\n"
                    row = json.loads(line.strip().rstrip(","))
                    if row["kind"] not in done and edit(row):
                        done.add(row["kind"])
                        line = "  " + json.dumps(row, separators=(",", ":")) + end
                g.write(line)
        self.addCleanup(lambda: (os.unlink(p), os.rmdir(d)))
        return p

    def test_informational_fields_warn(self):
        """A difference in a field data_gen doesn't read (source_names, owner_by, xrefs, interior, flags) is a
        warning: exit 0; --exact fails on it."""
        def edit(row):
            if row["kind"] not in ("string", "float", "bss"):
                return False
            row["source_names"] = row.get("source_names", 0) + 1
            row["owner_by"] = "guess"
            row["xrefs"] = row.get("xrefs", []) + ["0x10000"]
            row["interior"] = ["0x%x" % (int(row["addr"], 16) + 1)]
            row["flags"] = ["out_of_order"]
            return True
        p = self.edited(edit)
        self.assertEqual(di.check(self.items, self.cov, path=p), 0)
        self.assertEqual(di.check(self.items, self.cov, path=p, exact=True), 1)

    def test_checked_fields_fail(self):
        """A difference in a field data_gen reads (size, kind, name, type, object, ...) fails."""
        for field, value in (("kind", "unknown"), ("object", "global/CAction.cpp"), ("type", "int"),
                             ("name", "DAT_renamed"), ("pad", 4)):
            p = self.edited(lambda row: row["kind"] == "float" and row.get(field) != value and
                            row.update({field: value}) is None)
            self.assertEqual(di.check(self.items, self.cov, path=p), 1, field)
        # a vftable's interior addresses are link labels (tools/wine_link.py)
        p = self.edited(lambda row: row["kind"] == "vtable" and
                        row.update({"interior": ["0x%x" % (int(row["addr"], 16) + 8)]}) is None)
        self.assertEqual(di.check(self.items, self.cov, path=p), 1)

    def test_source_type_counts_where_data_gen_reads_it(self):
        """source_type is data_gen's fallback scalar type: a change that moves it fails, others warn."""
        p = self.edited(lambda row: row["kind"] == "table" and not row.get("type") and not row.get("source_type") and
                        row["size"] % 4 == 0 and
                        row.update({"source_type": "int[]"}) is None)
        self.assertEqual(di.check(self.items, self.cov, path=p), 1)
        p = self.edited(lambda row: row["kind"] == "float" and row.get("type") == "float" and
                        row.update({"source_type": "double"}) is None)
        self.assertEqual(di.check(self.items, self.cov, path=p), 0)

    def test_base_register_operands(self):
        """`movzx eax, byte [eax + 0x426830]` (luaO_log2) references Lua's log_2 table; the D3D library's
        PGRAPH register writes through the MMIO base (`[esi + 0x400750]`) reference nothing."""
        by = {it["addr"]: it for it in self.items}
        self.assertIn(0x215f70, [int(x, 16) if isinstance(x, str) else x for x in by[0x426830]["xrefs"]])
        for a in (0x400750, 0x400754, 0x400100):      # NV2A_PGRAPH registers, inside game strings and tables
            self.assertNotIn(a, by)

    def test_no_misspelled_types(self):
        for it in self.items:
            for f in ("type", "source_type"):
                self.assertNotRegex(it.get(f) or "", r"\bunsigned int (char|short|long|__int64)\b", hex(it["addr"]))

    def test_check_catches_drift(self):
        """A changed input makes --check fail: a pin moved to another object."""
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "items.json")
            with open(di.ITEMS_PINNED) as f:
                items = json.load(f)
            a = next(k for k, e in items["items"].items() if set(e) & {"object"} and "size" not in e)
            items["items"][a]["object"] = "global/CAction.cpp"
            with open(p, "w") as f:
                json.dump(items, f)
            old = di.ITEMS_PINNED
            di.ITEMS_PINNED = p
            try:
                self.assertEqual(di.main(["--check"]), 1)
            finally:
                di.ITEMS_PINNED = old


if __name__ == "__main__":
    unittest.main()
