"""Tests for tools/p3d.py and tools/dds.py. Synthetic files need no game data; real-file tests skip without it."""
import json, os, struct, sys, tempfile, unittest
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import dds, p3d

RCF_OUT = "build/rcf"


def chunk(cid, payload=b"", children=(), e="<"):
    kids = b"".join(children)
    body = payload + kids
    return struct.pack(e + "3I", cid, 12 + len(payload), 12 + len(body)) + body


def file(chunks, e="<", magic=p3d.MAGIC_LE):
    body = b"".join(chunks)
    return magic + struct.pack(e + "2I", 12, 12 + len(body)) + body


def pstr(s):
    b = s.encode() + b"\0"
    b += b"\0" * (-len(b) % 4)
    return bytes([len(b)]) + b


def dxt1(w, h, c0, c1=0, idx=0):
    hdr = bytearray(128)
    hdr[:4] = b"DDS "
    struct.pack_into("<II", hdr, 12, h, w)
    struct.pack_into("<II4s", hdr, 76, 32, 4, b"DXT1")
    return bytes(hdr) + struct.pack("<HHI", c0, c1, idx) * (((w + 3) // 4) * ((h + 3) // 4))


def model():
    """One textured triangle: Texture t.bmp (solid red DXT1), Shader s, Geometry g."""
    img = dxt1(4, 4, 0xF800)
    tex = chunk(0x19000, pstr("t.bmp") + struct.pack("<7I", 14000, 4, 4, 32, 0, 1, 1),
                [chunk(0x19001, pstr("t.bmp") + struct.pack("<6I", 14000, 4, 4, 32, 0, 1),
                       [chunk(0x19002, struct.pack("<I", len(img)) + img)])])
    shader = chunk(0x11000, pstr("s") + pstr("simple"), [chunk(0x11002, b"TEX\0" + pstr("t.bmp"))])
    pos = [(0, 0, 0), (1, 0, 0), (0, 1, 1)]
    prim = chunk(0x10020, struct.pack("<I", 0) + pstr("s") + struct.pack("<I", 0), [
        chunk(0x10005, struct.pack("<I", 3) + b"".join(struct.pack("<3f", *p) for p in pos)),
        chunk(0x10007, struct.pack("<II", 3, 0) + struct.pack("<6f", 0, 0, 1, 0, 0, 0.25)),
        chunk(0x1000A, struct.pack("<4I", 3, 0, 1, 2)),
    ])
    geo = chunk(0x10000, pstr("g") + struct.pack("<I", 1), [prim])
    return file([tex, shader, geo])


def read_glb(path):
    data = open(path, "rb").read()
    jl, = struct.unpack_from("<I", data, 12)
    j = json.loads(data[20:20 + jl])
    binary = data[20 + jl + 8:]

    def acc(i):
        a = j["accessors"][i]
        v = j["bufferViews"][a["bufferView"]]
        n = {"SCALAR": 1, "VEC2": 2, "VEC3": 3, "VEC4": 4, "MAT4": 16}[a["type"]]
        c = {5126: "f", 5125: "I", 5123: "H", 5121: "B"}[a["componentType"]]
        flat = struct.unpack_from("<%d%s" % (n * a["count"], c), binary, v["byteOffset"])
        return [flat[k * n:(k + 1) * n] for k in range(a["count"])]
    return j, acc


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

    def test_dxt1(self):
        w, h, px = dds.decode(dxt1(4, 4, 0xF800))
        self.assertEqual((w, h), (4, 4))
        self.assertEqual(px[:4], b"\xff\x00\x00\xff")
        # c0 <= c1 selects 3-colour mode, where index 3 is transparent black.
        _, _, px = dds.decode(dxt1(4, 4, 0, 0xFFFF, 0xFFFFFFFF))
        self.assertEqual(px[:4], b"\0\0\0\0")
        self.assertTrue(dds.png(w, h, px).startswith(b"\x89PNG"))

    def test_strip(self):
        g = {"type": 1, "idx": [(i,) for i in (0, 1, 2, 3, 3, 4)], "pos": []}
        self.assertEqual(p3d.triangles(g), [(0, 1, 2), (2, 1, 3)])

    def test_gltf(self):
        with tempfile.TemporaryDirectory() as d:
            out = os.path.join(d, "m.glb")
            self.assertEqual(p3d.export_gltf(model(), out), (1, 1))
            j, acc = read_glb(out)
            prim = j["meshes"][0]["primitives"][0]
            self.assertEqual(acc(prim["attributes"]["POSITION"])[2], (0, 1, -1))       # Z flipped
            self.assertEqual([i[0] for i in acc(prim["indices"])], [0, 2, 1])           # winding reversed
            self.assertEqual(acc(prim["attributes"]["TEXCOORD_0"])[2], (0, 0.75))       # channel skipped, v flipped
            self.assertIn("baseColorTexture", j["materials"][0]["pbrMetallicRoughness"])

    def test_textures_cmd(self):
        with tempfile.TemporaryDirectory() as d:
            src = os.path.join(d, "in", "sub")
            os.makedirs(src)
            open(os.path.join(src, "m.p3d"), "wb").write(model())

            class A: paths = [os.path.join(d, "in")]; out = os.path.join(d, "out"); mips = False
            p3d.cmd_textures(A)
            self.assertTrue(os.path.exists(os.path.join(d, "out", "sub", "m", "t.png")))

    @unittest.skipUnless(os.path.isdir(RCF_OUT), "no extracted game data")
    def test_real(self):
        for f in p3d.find_p3d([RCF_OUT]):
            cs = p3d.parse(open(f, "rb").read())
            self.assertFalse(any(c.bad for _, c in p3d.walk(cs)), f)

    @unittest.skipUnless(os.path.exists(os.path.join(RCF_OUT, "art/art/global_hulk.p3d")), "no extracted game data")
    def test_real_hulk(self):
        with tempfile.TemporaryDirectory() as d:
            out = os.path.join(d, "hulk.glb")
            p3d.export_gltf(open(os.path.join(RCF_OUT, "art/art/global_hulk.p3d"), "rb").read(), out)
            j, acc = read_glb(out)
            self.assertEqual(len(j["skins"][0]["joints"]), 38)
            for prim in j["meshes"][0]["primitives"]:
                for w in acc(prim["attributes"]["WEIGHTS_0"]):
                    self.assertAlmostEqual(sum(w), 1.0, places=5)
                self.assertLess(max(max(r) for r in acc(prim["attributes"]["JOINTS_0"])), 38)


if __name__ == "__main__":
    unittest.main()
