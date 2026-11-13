"""Tests for tools/data_overreach.py: the classification of an access against config/data.json-style items and the
access width read from MSVC's instruction encodings (no objects, XBE or compiler needed)."""
import os, sys, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import data_overreach as do

# FUN_00277190's case (linux1): "D:" is a 2-byte item, its terminator the next item, a 1-byte string with 1 pad byte
ITEMS = do.Items([
    {"addr": 0x42b50c, "size": 2, "pad": 0, "name": "DAT_0042b50c", "kind": "scalar"},
    {"addr": 0x42b50e, "size": 1, "pad": 1, "name": "s_empty_0042b50e", "kind": "string"},
    {"addr": 0x42b510, "size": 16, "pad": 0, "name": "tbl_0042b510", "kind": "table"},
])


def insn(hexbytes):
    code = bytes.fromhex(hexbytes)
    return code, next(do._md().disasm(code, 0))


class Classes(unittest.TestCase):
    def test_reported_and_info(self):
        """tree_tu.py check / verify fail on REPORTED and only list INFO (tool2, D12)."""
        self.assertEqual(do.REPORTED, ("over", "pad", "addr", "before", "indexed"))
        self.assertEqual(do.INFO, ("end", "negidx"))


class Classify(unittest.TestCase):
    def test_inside(self):
        self.assertIsNone(do.classify(ITEMS, 0x42b50c, 0, 2))
        self.assertIsNone(do.classify(ITEMS, 0x42b510, 12, 4))
        self.assertIsNone(do.classify(ITEMS, 0x42b510, 4, 0))          # an address inside

    def test_cross_item_read(self):
        h = do.classify(ITEMS, 0x42b50c, 2, 1)                         # ((char*)&DAT_0042b50c)[2]
        self.assertEqual(h["kind"], "over")
        self.assertEqual(h["target_item"], "s_empty_0042b50e")
        self.assertEqual(h["target_offset"], 0)

    def test_pad_and_wide(self):
        self.assertEqual(do.classify(ITEMS, 0x42b50e, 1, 1)["kind"], "pad")
        self.assertEqual(do.classify(ITEMS, 0x42b50e, 0, 2)["kind"], "pad")
        self.assertEqual(do.classify(ITEMS, 0x42b50c, 0, 4)["kind"], "over")   # *(int*)&DAT_0042b50c

    def test_addresses(self):
        self.assertEqual(do.classify(ITEMS, 0x42b510, 16, 0)["kind"], "end")
        self.assertEqual(do.classify(ITEMS, 0x42b510, 20, 0)["kind"], "end")     # one past the end plus a field offset
        self.assertEqual(do.classify(ITEMS, 0x42b510, 32, 0)["kind"], "addr")    # past it by min(32, size) or more
        self.assertEqual(do.classify(ITEMS, 0x42b50e, 3, 0)["kind"], "addr")     # a 1-byte item: 3 past
        self.assertEqual(do.classify(ITEMS, 0x42b510, -24, 4, indexed=True)["kind"], "negidx")    # x[i - 6]
        self.assertEqual(do.classify(ITEMS, 0x42b510, -4, 4)["kind"], "before")
        self.assertIsNone(do.classify(ITEMS, 0x42b510, 8, 4, indexed=True))
        self.assertEqual(do.classify(ITEMS, 0x42b510, 16, 4, indexed=True)["kind"], "indexed")

    def test_interior_name(self):
        """DAT_x naming an address inside a folded item counts from the item's start."""
        self.assertIsNone(do.classify(ITEMS, 0x42b514, 8, 4))
        self.assertEqual(do.classify(ITEMS, 0x42b514, 12, 4)["kind"], "over")

    def test_not_an_item(self):
        self.assertIsNone(do.classify(ITEMS, 0x500000, 4, 4))


class Widths(unittest.TestCase):
    def test_operands(self):
        for hexb, field, want in [
            ("8a0d0eb54200", 2, (1, False)),            # mov cl, byte ptr [0x42b50e]
            ("dd050cb54200", 2, (8, False)),            # fld qword ptr [...]
            ("c7050cb5420001000000", 2, (4, False)),    # mov dword ptr [...], 1: the address field
            ("680cb54200", 1, (0, False)),              # push offset
            ("0fb6840a0cb54200", 4, (1, True)),         # movzx eax, byte ptr [edx + ecx + ...]
            ("8d040d0cb54200", 3, (0, True)),           # lea eax, [ecx + ...]
            ("3d0cb54200", 1, (0, False)),              # cmp eax, offset (a loop bound)
        ]:
            code, i = insn(hexb)
            self.assertEqual(do.access(i, field), want, hexb)

    def test_decode_field(self):
        code = bytes.fromhex("558bec8a0d0eb54200")        # push ebp; mov ebp, esp; mov cl, byte ptr [...]
        i, f = do.decode_field(code, 5, starts=[0])
        self.assertEqual((i.address, f), (3, 2))
        i, f = do.decode_field(code, 5)                   # no start: the candidates back from the field
        self.assertEqual((i.address, f), (3, 2))

    def test_block_copy(self):
        code, i = insn("be0cb54200b908000000f3a566a5a4")  # mov esi, offset; mov ecx, 8; rep movsd; movsw; movsb
        self.assertEqual(do.block_width(code, i), 35)
        code, i = insn("bf0cb54200b904000000f3ab")        # mov edi, offset; mov ecx, 4; rep stosd
        self.assertEqual(do.block_width(code, i), 16)
        code, i = insn("be0cb54200e800000000")            # mov esi, offset; call: not a block copy
        self.assertEqual(do.block_width(code, i), 0)


if __name__ == "__main__":
    unittest.main()
