"""Synthetic-archive tests for tools/rcf.py (no game data needed)."""
import os, struct, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import rcf


def build(files):
    names = b"".join(struct.pack("<3I", 0, off, sz) + n.encode() + b"\0"
                     for n, (off, sz) in files.items())
    hdr = 0x3C
    dir_size = 12 * len(files)
    names_off = 0x2000
    body_off = names_off + len(names)
    body_off = (body_off + 0x7FF) & ~0x7FF
    out = bytearray(body_off)
    out[:23] = rcf.MAGIC
    # offsets are placeholders; patched below
    blobs, ents, cur = [], [], body_off
    for i, (n, (_, sz)) in enumerate(files.items()):
        ents.append((0x1000 + i, cur, sz)); blobs.append(bytes([i + 1]) * sz)
        cur = (cur + sz + 0x7FF) & ~0x7FF
    names = b"".join(struct.pack("<3I", 0, o, s) + n.encode() + b"\0"
                     for n, (_, o, s) in zip(files, ents))
    struct.pack_into("<7I", out, 0x20, 0x01000102, hdr, dir_size, names_off, len(names), 0, len(files))
    for i, e in enumerate(ents):
        struct.pack_into("<3I", out, hdr + 12 * i, *e)
    out[names_off:names_off + len(names)] = names
    for e, b in zip(ents, blobs):
        out.extend(b"\0" * (e[1] - len(out))); out.extend(b)
    return bytes(out)


class T(unittest.TestCase):
    def test_extract(self):
        files = {"art\\a.p3d": (0, 10), "sound/b.rsd": (0, 3000)}
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "t.rcf"); open(p, "wb").write(build(files))
            _, h, es = rcf.parse(p)
            self.assertEqual(h["count"], 2)
            self.assertEqual([e.name for e in es], list(files))
            class A: file = p; outdir = os.path.join(d, "o")
            rcf.cmd_extract(A)
            self.assertEqual(os.path.getsize(os.path.join(d, "o", "art", "a.p3d")), 10)
            self.assertEqual(rcf.cmd_roundtrip(A), 0)

    def test_traversal(self):
        e = rcf.Entry(1, 0, 0, "..\\..\\x.bin")
        self.assertNotIn("..", rcf.entry_path(e))

    @unittest.skipUnless(os.path.isdir("isos/extracted"), "no game data")
    def test_real(self):
        for f in os.listdir("isos/extracted"):
            if f.endswith(".rcf"):
                _, h, es = rcf.parse(os.path.join("isos/extracted", f))
                self.assertEqual(len(es), h["count"])


if __name__ == "__main__":
    unittest.main()
