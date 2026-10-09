"""Synthetic tests for tools/p3d.py (no game data needed)."""
import os, struct, sys, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import p3d


def chunk(cid, payload=b"", children=(), e="<"):
    kids = b"".join(children)
    body = payload + kids
    return struct.pack(e + "3I", cid, 12 + len(payload), 12 + len(body)) + body


def file(chunks, e="<", magic=p3d.MAGIC_LE):
    body = b"".join(chunks)
    return magic + struct.pack(e + "2I", 12, 12 + len(body)) + body


class T(unittest.TestCase):
    def test_tree(self):
        buf = file([chunk(0x19000, b"abcd", [chunk(0x19001), chunk(0xDEAD)]), chunk(0x11000)])
        cs = p3d.parse(buf)
        self.assertEqual([c.id for c in cs], [0x19000, 0x11000])
        self.assertEqual([c.id for c in cs[0].children], [0x19001, 0xDEAD])
        self.assertEqual(cs[0].name, "Texture")
        self.assertEqual(cs[0].children[1].name, "?")

    def test_big_endian(self):
        buf = file([chunk(0x19000, e=">")], ">", p3d.MAGIC_BE)
        self.assertEqual(p3d.parse(buf)[0].id, 0x19000)

    def test_truncated_is_not_fatal(self):
        buf = file([chunk(0x19000, b"x" * 8)])[:-6]
        cs = p3d.parse(buf)
        self.assertTrue(any(c.bad for _, c in p3d.walk(cs)))

    def test_bad_magic(self):
        with self.assertRaises(ValueError):
            p3d.parse(b"RIFF" + b"\0" * 20)

    @unittest.skipUnless(os.path.isdir("build/rcf_out"), "no extracted game data")
    def test_real(self):
        for r, _, fs in os.walk("build/rcf_out"):
            for f in fs:
                if f.lower().endswith(".p3d"):
                    p3d.parse(open(os.path.join(r, f), "rb").read())


if __name__ == "__main__":
    unittest.main()
