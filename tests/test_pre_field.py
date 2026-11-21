#!/usr/bin/env python3
"""(integ7, D164; rev5) tools/pre_field.py's static-instance leg on synthetic data (no game bytes): a config/data.json
item typed as a family class must hold each contract word in range in its initial image."""
import os
import struct
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tools"))
import pre_field  # noqa: E402

GE0F = ("range", 0.0, float("inf"), True, True, "f")
GE0I = ("range", 0.0, float("inf"), True, True, "i")


def image(words):
    """read(addr, n) over {addr: 4 bytes}; zero elsewhere (bss)."""
    return lambda a, n: words.get(a, b"\0" * n)[:n]


class StaticCensus(unittest.TestCase):
    def item(self, typ, addr=0x500000, size=0x200, kind="data"):
        return {"addr": "0x%x" % addr, "size": size, "kind": kind, "name": "DAT_%08x" % addr, "type": typ}

    def test_out_of_range_fails(self):
        read = image({0x5000f4: struct.pack("<f", -0.5)})
        m, n = pre_field.static_census(["CGameCamera"], {0xf4: GE0F}, [self.item("CGameCamera")], read)
        self.assertEqual(n, 1)
        self.assertTrue(m and m[0].startswith("pre_uninit"), m)

    def test_in_range_passes(self):
        read = image({0x5000f4: struct.pack("<f", 0.25)})
        m, n = pre_field.static_census(["CGameCamera"], {0xf4: GE0F}, [self.item("CGameCamera")], read)
        self.assertEqual((m, n), ([], 1))

    def test_bss_zero_in_range(self):
        m, n = pre_field.static_census(["CGameCamera"], {0xf4: GE0F}, [self.item("CGameCamera")], image({}))
        self.assertEqual((m, n), ([], 1))

    def test_derived_and_qualified_names(self):
        read = image({0x5000f4: struct.pack("<i", -3)})
        m, n = pre_field.static_census(["CGameCamera", "CNISCamera"], {0xf4: GE0I},
                                       [self.item("class ::CNISCamera")], read)
        self.assertEqual(n, 1)
        self.assertTrue(m)

    def test_other_types_and_vftables_ignored(self):
        read = image({0x5000f4: struct.pack("<f", -1.0)})
        m, n = pre_field.static_census(["CGameCamera"], {0xf4: GE0F},
                                       [self.item("CGameCameraManager"), self.item("CGameCamera", kind="vftable")], read)
        self.assertEqual((m, n), ([], 0))

    def test_word_past_item_end_refused(self):
        # (rev5) an in-range image word past the item's end is still refused: the census can't vouch for it
        read = image({0x5000f4: struct.pack("<f", 1.0)})
        m, n = pre_field.static_census(["CGameCamera"], {0xf4: GE0F}, [self.item("CGameCamera", size=0x40)], read)
        self.assertEqual(n, 1)
        self.assertTrue(m and "outside the data item" in m[0], m)


if __name__ == "__main__":
    unittest.main()
