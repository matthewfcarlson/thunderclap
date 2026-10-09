"""Tests for tools/rcf.py. Synthetic archives need no game data; real-archive tests skip without it."""
import os, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import rcf

GAME = "isos/extracted"


def make(files):
    """files: {name: bytes}, in data order."""
    ents = [(n, 1117480426, len(b)) for n, b in files.items()]
    blobs = list(files.values())
    return b"".join(rcf.build(ents, lambda i: blobs[i]))


class T(unittest.TestCase):
    def test_hash(self):
        # Known pairs from misc.rcf's directory.
        self.assertEqual(rcf.rhash("frontend\\feconfig.txt"), 0xB909394D)
        self.assertEqual(rcf.rhash("frontend\\fe_loading.txt"), 0x5B8ACE28)
        self.assertEqual(rcf.rhash("FRONTEND\\FECONFIG.TXT"), rcf.rhash("frontend\\feconfig.txt"))
        self.assertNotEqual(rcf.rhash("a/b"), rcf.rhash("a\\b"))

    def test_extract_repack(self):
        files = {"art\\b.p3d": b"\x01" * 10, "sound\\a.rsd": b"\x02" * 3000, "z.txt": b"end"}
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "t.rcf")
            data = make(files)
            open(p, "wb").write(data)
            ar = rcf.Archive(p)
            self.assertEqual([e.name for e in ar.entries], list(files))
            self.assertEqual([ar.read(e) for e in ar.entries], list(files.values()))
            self.assertIsNone(rcf.verify(p))

            class A: file = p; outdir = os.path.join(d, "o"); dir = outdir; out = os.path.join(d, "r.rcf")
            rcf.cmd_extract(A)
            self.assertEqual(open(os.path.join(d, "o", "sound", "a.rsd"), "rb").read(), files["sound\\a.rsd"])
            rcf.cmd_repack(A)
            self.assertEqual(open(A.out, "rb").read(), data)

    def test_repack_without_manifest(self):
        with tempfile.TemporaryDirectory() as d:
            os.makedirs(os.path.join(d, "in", "art"))
            open(os.path.join(d, "in", "art", "x.p3d"), "wb").write(b"P3D\xff")

            class A: dir = os.path.join(d, "in"); out = os.path.join(d, "n.rcf")
            rcf.cmd_repack(A)
            ar = rcf.Archive(A.out)
            self.assertEqual([e.name for e in ar.entries], ["art\\x.p3d"])

    def test_collision(self):
        with self.assertRaises(rcf.RcfError):
            make({"A.txt": b"1", "a.txt": b"2"})

    def test_traversal(self):
        self.assertNotIn("..", rcf.entry_path("..\\..\\x.bin"))

    @unittest.skipUnless(os.path.isdir(GAME), "no game data")
    def test_real_roundtrip(self):
        for f in sorted(os.listdir(GAME)):
            if f.endswith(".rcf"):
                self.assertIsNone(rcf.verify(os.path.join(GAME, f)), f)


if __name__ == "__main__":
    unittest.main()
