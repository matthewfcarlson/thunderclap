#!/usr/bin/env python3
"""Inspect and export Pure3D (.p3d) files.

  p3d.py dump <file.p3d> [--max-depth N]
  p3d.py stats <file-or-dir>...            # chunk-id histogram, unknown ids ranked
  p3d.py textures <file-or-dir>... -o DIR  # every Image -> PNG
  p3d.py gltf <file.p3d> <out.glb> [--lib other.p3d]... [--anims other.p3d]... [--anim-match GLOB]
                                           # meshes (+ skeleton, skin, textures, animations) -> binary glTF
  p3d.py city <location> <out.glb> [--rcf build/rcf]
                                           # every room of a location, textured from its districts

Layout (docs/formats/p3d.md): 12-byte file header (magic, header size, file
length) followed by chunks of {u32 id, u32 data_size, u32 total_size}, where
both sizes include the 12-byte chunk header and children follow the chunk's
own data. Parsing is tolerant: bad sizes are reported, never fatal.
"""
import argparse, collections, fnmatch, json, math, os, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import dds

MAGIC_LE = b"P3D\xff"
MAGIC_BE = b"\xffD3P"

# Top-level ids are confirmed by the constructors of the XBE's *Loader classes;
# sub-chunk ids are named from their layout (see docs/formats/p3d.md).
NAMES = {
    0x7000: "History", 0x2200: "Camera", 0x2380: "LightGroup",
    0x10000: "Geometry", 0x10001: "PolySkin", 0x10019: "ShadowSkin", 0x10023: "ShadowMeshBuffer",
    0x10020: "PrimGroup", 0x10003: "BoundingBox", 0x10004: "BoundingSphere",
    0x10005: "PositionList", 0x10006: "NormalList", 0x10007: "UVList", 0x10008: "ColourList",
    0x1000A: "IndexList",
    0x1000B: "MatrixList", 0x1000C: "WeightList", 0x1000D: "MatrixPalette",
    0x11000: "Shader", 0x11002: "ShaderTextureParam", 0x11003: "ShaderIntParam",
    0x11004: "ShaderFloatParam", 0x11005: "ShaderColourParam",
    0x13000: "Light", 0x14000: "Locator", 0x1580C: "ParticleSystem", 0x17006: "BillboardQuadGroup",
    0x19000: "Texture", 0x19001: "Image", 0x19002: "ImageData", 0x19005: "Sprite",
    0x22000: "TextureFont", 0x23000: "Skeleton", 0x23001: "SkeletonJoint",
    0x120100: "Scenegraph", 0x121000: "Animation", 0x121201: "FrameController",
    0x123000: "CompositeDrawable",
    0x7010000: "CollisionObject", 0x7010025: "WorldCollisionObject", 0x7011000: "PhysicsObject",
    0x802000A: "StatePropData",
    0x60000700: "Level", 0x60000701: "Room", 0x60000722: "Transitions", 0x60000A00: "DataHandlerRaw",
}


class Chunk:
    __slots__ = ("id", "data_off", "size", "start", "children", "bad")

    def __init__(self, id, start, data_off, size):
        self.id, self.start, self.data_off, self.size = id, start, data_off, size
        self.children, self.bad = [], None

    @property
    def name(self):
        return NAMES.get(self.id, "?")

    def child(self, cid):
        return next((c for c in self.children if c.id == cid), None)


def parse_chunks(buf, pos, end, endian):
    out = []
    while pos + 12 <= end:
        cid, doff, size = struct.unpack_from(endian + "3I", buf, pos)
        c = Chunk(cid, pos, doff, size)
        if size < 12 or doff < 12 or doff > size or pos + size > end:
            c.bad = f"bad sizes (data_size={doff:#x} size={size:#x}) at {pos:#x}"
            out.append(c)
            break  # cannot trust the stream any further at this level
        c.children = parse_chunks(buf, pos + doff, pos + size, endian)
        out.append(c)
        pos += size
    return out


def parse(buf):
    if buf[:4] == MAGIC_LE:
        endian = "<"
    elif buf[:4] == MAGIC_BE:
        endian = ">"
    else:
        raise ValueError("not a P3D file (bad magic)")
    hdr, flen = struct.unpack_from(endian + "2I", buf, 4)
    end = min(len(buf), flen) if 12 <= flen <= len(buf) else len(buf)
    return parse_chunks(buf, hdr, end, endian)


def walk(chunks, depth=0):
    for c in chunks:
        yield depth, c
        yield from walk(c.children, depth + 1)


class Reader:
    """Sequential reader over one chunk's own data (little-endian)."""

    def __init__(self, buf, c):
        self.buf, self.pos = buf, c.start + 12

    def u32(self):
        v, = struct.unpack_from("<I", self.buf, self.pos)
        self.pos += 4
        return v

    def f32(self, n):
        v = struct.unpack_from("<%df" % n, self.buf, self.pos)
        self.pos += 4 * n
        return v

    def raw(self, n):
        v = self.buf[self.pos:self.pos + n]
        self.pos += n
        return v

    def pstr(self):
        """u8 length, then that many bytes (NUL-padded to a 4-byte multiple in most chunks)."""
        n = self.buf[self.pos]
        s = self.buf[self.pos + 1:self.pos + 1 + n].split(b"\0", 1)[0].decode("latin1")
        self.pos += 1 + n
        return s


def label(buf, c):
    """Best-effort object name for dump: a printable pstring at offset 0 or 4."""
    for skip in (0, 4):
        p = c.start + 12 + skip
        if p >= c.start + c.data_off:
            break
        n = buf[p]
        s = buf[p + 1:p + 1 + n].split(b"\0", 1)[0]
        if 2 <= n <= c.data_off - 13 - skip and len(s) >= 2 and all(32 <= ch < 127 for ch in s):
            return s.decode()
    return None


def cmd_dump(a):
    buf = open(a.file, "rb").read()
    for d, c in walk(parse(buf)):
        if d > a.max_depth:
            continue
        n = label(buf, c)
        line = (f"{'  ' * d}{c.id:#08x} {c.name}{' ' + repr(n) if n else ''} @{c.start:#x}"
                f" data={c.data_off - 12} total={c.size}")
        print(line + (f"  !! {c.bad}" if c.bad else ""))


def find_p3d(paths):
    files = []
    for p in paths:
        if os.path.isdir(p):
            for r, _, fs in sorted(os.walk(p)):
                files += sorted(os.path.join(r, f) for f in fs if f.lower().endswith(".p3d"))
        else:
            files.append(p)
    return files


def cmd_stats(a):
    files = find_p3d(a.paths)
    hist, nbad, nfail = collections.Counter(), 0, 0
    for f in files:
        try:
            for _, c in walk(parse(open(f, "rb").read())):
                hist[c.id] += 1
                nbad += bool(c.bad)
        except ValueError:
            nfail += 1
    print(f"{len(files)} files, {nfail} unparsable, {nbad} bad chunks")
    for cid, n in hist.most_common():
        print(f"{cid:#08x} {NAMES.get(cid, 'UNKNOWN'):<20}{n}")


# ---- textures ---------------------------------------------------------------

def image_png(buf, img):
    """PNG bytes for an Image chunk. ImageData holds a u32 size + a DDS (DXT1/3/5) or PNG file."""
    r = Reader(buf, img.child(0x19002))
    blob = r.raw(r.u32())
    if blob[:4] == b"\x89PNG":
        return blob
    # DDS rows are stored bottom-up (the game's UVs index them as-is), so flip for viewing.
    w, h, rgba = dds.decode(blob)
    return dds.png(w, h, b"".join(rgba[y * w * 4:(y + 1) * w * 4] for y in reversed(range(h))))


def textures(buf, chunks):
    """Yield (texture name, image index, Image chunk) for every Texture in the file."""
    for _, c in walk(chunks):
        if c.id == 0x19000:
            name = Reader(buf, c).pstr()
            for i, img in enumerate(k for k in c.children if k.id == 0x19001):
                yield name, i, img  # i > 0: further mip levels


def safe_name(s):
    return "".join(ch if ch.isalnum() or ch in "-_." else "_" for ch in s) or "unnamed"


def cmd_textures(a):
    """Writes <out>/<p3d path relative to the given dir, minus .p3d>/<texture>.png."""
    n = fail = 0
    for p in a.paths:
        for f in find_p3d([p]):
            rel = os.path.relpath(f, p) if os.path.isdir(p) else os.path.basename(f)
            d = os.path.join(a.out, os.path.splitext(rel)[0])
            os.makedirs(d, exist_ok=True)
            buf = open(f, "rb").read()
            seen = collections.Counter()
            for name, i, img in textures(buf, parse(buf)):
                if i and not a.mips:
                    continue
                base = safe_name(os.path.splitext(name.replace("\\", "/").rsplit("/", 1)[-1])[0])
                if i == 0:
                    seen[base.lower()] += 1
                    if seen[base.lower()] > 1:
                        base += f"_{seen[base.lower()]}"
                ok = write_png(buf, f, name, img, os.path.join(d, base + (f"_mip{i}" if i else "") + ".png"))
                n += ok
                fail += not ok
    print(f"wrote {n} PNGs to {a.out}" + (f", {fail} failed" if fail else ""))


def write_png(buf, f, name, img, dst):
    try:
        png = image_png(buf, img)
    except (dds.DdsError, struct.error, AttributeError) as e:
        print(f"{f}: {name}: {e}", file=sys.stderr)
        return False
    with open(dst, "wb") as out:
        out.write(png)
    return True


# ---- meshes -----------------------------------------------------------------

def read_list(buf, c, fmt, skip=0):
    """Count-prefixed array: u32 count, `skip` bytes of extra header, then count * struct(fmt)."""
    n, = struct.unpack_from("<I", buf, c.start + 12)
    p = c.start + 16 + skip
    return list(struct.iter_unpack(fmt, buf[p:p + n * struct.calcsize(fmt)]))


def read_skeleton(buf, c):
    """Skeleton (0x23000): name, ...; SkeletonJoint (0x23001): name, u32 parent, 4x4 rest matrix."""
    name = Reader(buf, c).pstr()
    joints = []
    for k in c.children:
        if k.id == 0x23001:
            r = Reader(buf, k)
            jn, parent = r.pstr(), r.u32()
            joints.append((jn, parent, r.f32(16)))
    return name, joints


def read_prim_group(buf, c):
    """PrimGroup (0x10020): u32 version, shader name, u32 prim type, u32 vertex format,
    u32 vertex count, u32 index count, u32 matrix count, ..."""
    r = Reader(buf, c)
    r.u32()
    g = {"shader": r.pstr(), "type": r.u32()}
    for cid, key, fmt in ((0x10005, "pos", "<3f"), (0x10006, "nrm", "<3f"), (0x10008, "col", "<4B"),
                          (0x1000B, "mat", "<4B"), (0x1000C, "wt", "<3f"), (0x1000A, "idx", "<I")):
        k = c.child(cid)
        if k is not None:
            g[key] = read_list(buf, k, fmt)
    # UVList: u32 count, u32 channel, then (u, v) pairs. Rooms carry channel 0 and 1.
    for k in c.children:
        if k.id == 0x10007:
            ch, = struct.unpack_from("<I", buf, k.start + 16)
            g["uv" if ch == 0 else f"uv{ch}"] = read_list(buf, k, "<2f", 4)
    k = c.child(0x1000D)
    g["palette"] = [v[0] for v in read_list(buf, k, "<I")] if k is not None else None
    return g


def triangles(g):
    """Triangle list from a prim group. Type 0 = list, 1 = strip (degenerates dropped)."""
    idx = [i[0] for i in g["idx"]] if "idx" in g else list(range(len(g["pos"])))
    if g["type"] == 0:
        return [tuple(idx[i:i + 3]) for i in range(0, len(idx) - 2, 3)]
    if g["type"] == 1:
        out = []
        for i in range(len(idx) - 2):
            a, b, c = idx[i:i + 3]
            if a != b and b != c and a != c:
                out.append((a, b, c) if i % 2 == 0 else (b, a, c))
        return out
    return []


def mat_mul(a, b):
    """Row-major 4x4 product a*b (Pure3D uses row vectors: v' = v * M)."""
    return tuple(sum(a[r * 4 + k] * b[k * 4 + c] for k in range(4)) for r in range(4) for c in range(4))


def mat_inv_affine(m):
    """Inverse of a row-major affine 4x4 (last column 0,0,0,1)."""
    a = [[m[r * 4 + c] for c in range(3)] for r in range(3)]
    det = (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
           + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]))
    inv = [[(a[(c + 1) % 3][(r + 1) % 3] * a[(c + 2) % 3][(r + 2) % 3]
             - a[(c + 1) % 3][(r + 2) % 3] * a[(c + 2) % 3][(r + 1) % 3]) / det for c in range(3)] for r in range(3)]
    t = m[12:15]
    it = [-sum(t[k] * inv[k][c] for k in range(3)) for c in range(3)]
    return tuple(inv[0] + [0] + inv[1] + [0] + inv[2] + [0] + it + [1])


# ---- animations -------------------------------------------------------------

# Rotation channels: per-key quaternion (x, y, z[, w]) as struct format and scale; a missing w is
# derived as sqrt(1 - x^2 - y^2 - z^2). Column-vector convention, i.e. the transpose of the joint matrix.
QUAT = {0x121105: ("<4f", 1.0), 0x121111: ("<4h", 32767.0), 0x121112: ("<3h", 32767.0), 0x121114: ("<3b", 127.0)}


def read_channel(buf, c):
    """Animation channel -> (param, frames, values), or None for channel types not decoded.
    u32 version, char[4] param ("TRAN", "ROT"), [Vector1DOF/2DOF: u16 axis, f32[3] constant],
    u32 key count, u16 frame[n], then n values. Vector1DOF (0x121102) varies only `axis`;
    Vector2DOF (0x121103) keeps `axis` constant and stores the other two."""
    if c.id not in (0x121102, 0x121103, 0x121104) and c.id not in QUAT:
        return None
    r = Reader(buf, c)
    r.u32()
    param = r.raw(4).rstrip(b"\0").decode("latin1")
    if c.id in (0x121102, 0x121103):
        axis, = struct.unpack_from("<H", buf, r.pos)
        r.pos += 2
        const = r.f32(3)
    n = r.u32()
    frames = struct.unpack_from("<%dH" % n, buf, r.pos)
    r.pos += 2 * n
    if c.id == 0x121104:
        vals = [r.f32(3) for _ in range(n)]
    elif c.id == 0x121102:
        vals = [tuple(v if i == axis else const[i] for i in range(3)) for v in r.f32(n)]
    elif c.id == 0x121103:
        vals = []
        for _ in range(n):
            it = iter(r.f32(2))
            vals.append(tuple(const[i] if i == axis else next(it) for i in range(3)))
    else:
        fmt, scale = QUAT[c.id]
        vals = []
        for v in struct.iter_unpack(fmt, r.raw(n * struct.calcsize(fmt))):
            q = [x / scale for x in v]
            if len(q) == 3:
                q.append(math.sqrt(max(0.0, 1.0 - sum(x * x for x in q))))
            s = math.sqrt(sum(x * x for x in q)) or 1.0
            vals.append(tuple(x / s for x in q))
    return param, frames, vals


def read_animation(buf, c):
    """Animation (0x121000): u32 version, name, char[4] kind ("PTRN" = skeletal pose), f32 frame
    count, f32 frame rate, u32 cyclic. Its GroupList (0x121002) holds Groups (0x121001: u32 version,
    name, u32 id, u32 channel count) whose children are channels. Joints match groups by name."""
    r = Reader(buf, c)
    r.u32()
    a = {"name": r.pstr(), "kind": r.raw(4).rstrip(b"\0").decode("latin1")}
    a["frames"], a["rate"] = r.f32(2)
    a["cyclic"] = r.u32()
    a["groups"] = []
    gl = c.child(0x121002)
    for g in gl.children if gl is not None else ():
        if g.id != 0x121001:
            continue
        r = Reader(buf, g)
        r.u32()
        name, gid = r.pstr(), r.u32()
        chans = {}
        for k in g.children:
            ch = read_channel(buf, k)
            if ch:
                chans[ch[0]] = ch[1:]
        a["groups"].append((name, gid, chans))
    return a


def animations(buf, chunks=None):
    for _, c in walk(chunks if chunks is not None else parse(buf)):
        if c.id == 0x121000:
            yield read_animation(buf, c)


def bind_animation(anim, joint_names):
    """Joint index -> channels for a skeleton, or None if under half the groups name its joints.
    Cutscene animations name the root group after the character, so an unmatched group 0 -> joint 0."""
    idx = {n: i for i, n in enumerate(joint_names)}
    out = {}
    for name, gid, chans in anim["groups"]:
        if name in idx:
            out[idx[name]] = chans
    for name, gid, chans in anim["groups"]:
        if name not in idx and gid == 0 and 0 not in out:
            out[0] = chans
    return out if out and len(out) * 2 >= len(anim["groups"]) else None


def mat_quat(m):
    """Unit quaternion (x, y, z, w) of the rotation in a column-major glTF 4x4."""
    a = [[m[c * 4 + r] for c in range(3)] for r in range(3)]
    t = a[0][0] + a[1][1] + a[2][2]
    if t > 0:
        s = math.sqrt(t + 1.0) * 2
        q = ((a[2][1] - a[1][2]) / s, (a[0][2] - a[2][0]) / s, (a[1][0] - a[0][1]) / s, s / 4)
    elif a[0][0] > a[1][1] and a[0][0] > a[2][2]:
        s = math.sqrt(1.0 + a[0][0] - a[1][1] - a[2][2]) * 2
        q = (s / 4, (a[0][1] + a[1][0]) / s, (a[0][2] + a[2][0]) / s, (a[2][1] - a[1][2]) / s)
    elif a[1][1] > a[2][2]:
        s = math.sqrt(1.0 + a[1][1] - a[0][0] - a[2][2]) * 2
        q = ((a[0][1] + a[1][0]) / s, s / 4, (a[1][2] + a[2][1]) / s, (a[0][2] - a[2][0]) / s)
    else:
        s = math.sqrt(1.0 + a[2][2] - a[0][0] - a[1][1]) * 2
        q = ((a[0][2] + a[2][0]) / s, (a[1][2] + a[2][1]) / s, s / 4, (a[1][0] - a[0][1]) / s)
    n = math.sqrt(sum(x * x for x in q))
    return [x / n for x in q]


FLIP = (1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1)


def to_gltf_matrix(m):
    """Pure3D (left-handed, row vectors) -> glTF (right-handed, column vectors).
    Flip Z on both sides; a row-major row-vector matrix already has glTF's
    column-major layout, so the 16 floats pass through as-is."""
    return [float(v) for v in mat_mul(mat_mul(FLIP, m), FLIP)]


class Glb:
    def __init__(self):
        self.bin = bytearray()
        self.j = {"asset": {"version": "2.0", "generator": "hulk-ud-decomp tools/p3d.py"},
                  "bufferViews": [], "accessors": [], "meshes": [], "nodes": [],
                  "scenes": [{"nodes": []}], "scene": 0}

    def view(self, data, target=None):
        self.bin += bytes(-len(self.bin) % 4)
        v = {"buffer": 0, "byteOffset": len(self.bin), "byteLength": len(data)}
        if target:
            v["target"] = target
        self.bin += data
        self.j["bufferViews"].append(v)
        return len(self.j["bufferViews"]) - 1

    def accessor(self, rows, fmt, ctype, atype, target=None, minmax=False, count=None):
        data = b"".join(struct.pack(fmt, *r) for r in rows)
        acc = {"bufferView": self.view(data, target), "componentType": ctype,
               "count": count or len(rows), "type": atype}
        if minmax:
            acc["min"] = [min(r[i] for r in rows) for i in range(len(rows[0]))]
            acc["max"] = [max(r[i] for r in rows) for i in range(len(rows[0]))]
        self.j["accessors"].append(acc)
        return len(self.j["accessors"]) - 1

    def write(self, path):
        self.bin += bytes(-len(self.bin) % 4)
        j = dict(self.j, buffers=[{"byteLength": len(self.bin)}])
        js = json.dumps(j, separators=(",", ":")).encode()
        js += b" " * (-len(js) % 4)
        with open(path, "wb") as f:
            f.write(struct.pack("<III", 0x46546C67, 2, 12 + 8 + len(js) + 8 + len(self.bin)))
            f.write(struct.pack("<I4s", len(js), b"JSON") + js)
            f.write(struct.pack("<I4s", len(self.bin), b"BIN\0") + bytes(self.bin))


def shader_maps(buf, chunks):
    """(shader name -> TEX texture name, lowercase texture name -> (buf, first Image)) for one file."""
    shader_tex = {}
    for _, c in walk(chunks):
        if c.id == 0x11000:
            name = Reader(buf, c).pstr()
            for k in c.children:
                if k.id == 0x11002:
                    r = Reader(buf, k)
                    if r.raw(4) == b"TEX\0":
                        shader_tex[name] = r.pstr().lower()
    return shader_tex, {name.lower(): (buf, img) for name, i, img in textures(buf, chunks) if i == 0}


def export_gltf(models, path, libs=(), anims=(), match="*"):
    """Write .p3d meshes, skeletons and animations to a binary glTF.

    `models`: one .p3d buffer, or a list of (name, buffer) each grouped under a node of that name.
    `libs`: other .p3d buffers whose shaders and textures may be referenced; a model's own win
    (rooms use their location's districts). `anims`: further .p3d buffers to take PTRN animations
    from; the models' own count too. Animations whose name matches the `match` glob are bound to
    every skeleton whose joints they name. Returns (meshes, primitives, animations)."""
    if isinstance(models, (bytes, bytearray)):
        models = [(None, models)]
    g = Glb()
    j = g.j
    lib_st, lib_ti = {}, {}
    for b in libs:
        st, ti = shader_maps(b, parse(b))
        lib_st.update(st)
        lib_ti.update(ti)
    images, materials = {}, {}

    def texture(name, src):
        k = (id(src[0]), src[1].start)
        if k not in images:
            images[k] = None
            try:
                png = image_png(*src)
            except (dds.DdsError, struct.error, AttributeError):
                png = None
            if png:
                j.setdefault("images", []).append({"name": name, "mimeType": "image/png", "bufferView": g.view(png)})
                j.setdefault("textures", []).append({"source": len(j["images"]) - 1})
                images[k] = len(j["textures"]) - 1
        return images[k]

    def material(shader, st, ti):
        tex = st[shader] if shader in st else lib_st.get(shader)
        src = ti.get(tex) or lib_ti.get(tex)
        key = (shader, id(src[0]), src[1].start) if src else (shader,)
        if key not in materials:
            m = {"name": shader, "pbrMetallicRoughness": {"metallicFactor": 0.0, "roughnessFactor": 1.0}}
            t = texture(tex, src) if src else None
            if t is not None:
                m["pbrMetallicRoughness"]["baseColorTexture"] = {"index": t}
            j.setdefault("materials", []).append(m)
            materials[key] = len(j["materials"]) - 1
        return materials[key]

    skeletons = []  # (first joint node, joint names)
    for mname, buf in models:
        chunks = parse(buf)
        st, ti = shader_maps(buf, chunks)
        roots = j["scenes"][0]["nodes"]
        if mname is not None:
            j["nodes"].append({"name": mname, "children": []})
            roots.append(len(j["nodes"]) - 1)
            roots = j["nodes"][-1]["children"]

        # Skeletons -> joint node hierarchies (TRS, so animations can target them) + skins.
        skins = {}
        for _, c in walk(chunks):
            if c.id != 0x23000:
                continue
            sname, joints = read_skeleton(buf, c)
            base = len(j["nodes"])
            world = []
            for i, (jn, parent, m) in enumerate(joints):
                world.append(m if parent >= i else mat_mul(m, world[parent]))
                gm = to_gltf_matrix(m)
                j["nodes"].append({"name": jn, "translation": gm[12:15], "rotation": mat_quat(gm)})
                if parent < i:
                    j["nodes"][base + parent].setdefault("children", []).append(base + i)
                else:
                    roots.append(base + i)
            ibm = g.accessor([to_gltf_matrix(mat_inv_affine(w)) for w in world], "<16f", 5126, "MAT4")
            j.setdefault("skins", []).append({"name": sname, "joints": list(range(base, base + len(joints))),
                                              "inverseBindMatrices": ibm, "skeleton": base})
            skins[sname] = len(j["skins"]) - 1
            skeletons.append((base, [jn for jn, _, _ in joints]))

        # PolySkin (name, u32 version, skeleton name, u32 prim count) and Geometry (name, u32 prim count) -> meshes.
        for _, c in walk(chunks):
            if c.id not in (0x10000, 0x10001):
                continue
            r = Reader(buf, c)
            name = r.pstr()
            skel = (r.u32(), r.pstr())[1] if c.id == 0x10001 else None
            prims = []
            for k in c.children:
                if k.id != 0x10020:
                    continue
                pg = read_prim_group(buf, k)
                if "pos" not in pg:
                    continue
                tris = triangles(pg)
                if not tris:
                    continue
                attrs = {"POSITION": g.accessor([(x, y, -z) for x, y, z in pg["pos"]], "<3f", 5126, "VEC3", 34962, True)}
                if "nrm" in pg:
                    attrs["NORMAL"] = g.accessor([(x, y, -z) for x, y, z in pg["nrm"]], "<3f", 5126, "VEC3", 34962)
                if "uv" in pg:
                    # UVs index the DDS rows as stored; our PNGs are flipped for viewing, so flip v.
                    attrs["TEXCOORD_0"] = g.accessor([(u, 1.0 - v) for u, v in pg["uv"]], "<2f", 5126, "VEC2", 34962)
                if "uv1" in pg:
                    attrs["TEXCOORD_1"] = g.accessor([(u, 1.0 - v) for u, v in pg["uv1"]], "<2f", 5126, "VEC2", 34962)
                if "col" in pg:
                    # D3DCOLOR (B, G, R, A bytes): baked vertex lighting on world geometry.
                    attrs["COLOR_0"] = g.accessor([(r_, g_, b_, a_) for b_, g_, r_, a_ in pg["col"]],
                                                  "<4B", 5121, "VEC4", 34962)
                    j["accessors"][attrs["COLOR_0"]]["normalized"] = True
                if skel in skins and "mat" in pg and "wt" in pg and pg["palette"]:
                    pal = pg["palette"]
                    # Four palette slots per vertex; the first weight's slot is the top byte.
                    attrs["JOINTS_0"] = g.accessor([tuple(pal[i] for i in m[::-1]) for m in pg["mat"]],
                                                   "<4H", 5123, "VEC4", 34962)
                    wts = []
                    for w in pg["wt"]:
                        w = [max(0.0, x) for x in w] + [max(0.0, 1.0 - sum(w))]
                        s = sum(w) or 1.0
                        wts.append(tuple(x / s for x in w))
                    attrs["WEIGHTS_0"] = g.accessor(wts, "<4f", 5126, "VEC4", 34962)
                # The Z flip mirrors the mesh, so reverse the winding to keep faces outward.
                ind = g.accessor([(a, cc, b) for a, b, cc in tris], "<3I", 5125, "SCALAR", 34963, count=3 * len(tris))
                prims.append({"attributes": attrs, "indices": ind, "material": material(pg["shader"], st, ti)})
            if not prims:
                continue
            j["meshes"].append({"name": name, "primitives": prims})
            node = {"name": name, "mesh": len(j["meshes"]) - 1}
            if skel in skins:
                node["skin"] = skins[skel]
            j["nodes"].append(node)
            roots.append(len(j["nodes"]) - 1)
    if not j["meshes"]:
        raise ValueError("no meshes found")

    # Skeletal (PTRN) animations, first of each name wins (mission files repeat them).
    anim_list, seen = [], set()
    if skeletons:
        for b in [buf for _, buf in models] + list(anims):
            for an in animations(b):
                if (an["kind"] == "PTRN" and an["name"] not in seen
                        and fnmatch.fnmatchcase(an["name"].lower(), match.lower())):
                    seen.add(an["name"])
                    anim_list.append(an)
    times = {}
    for base, names in skeletons:
        for an in anim_list:
            bound = bind_animation(an, names)
            if not bound:
                continue
            rate = an["rate"] or 30.0
            samplers, channels = [], []
            for ji, chans in sorted(bound.items()):
                for param, target in (("TRAN", "translation"), ("ROT", "rotation")):
                    frames, vals = chans.get(param, ((), ()))
                    if not frames:
                        continue
                    if target == "translation":
                        out = g.accessor([(x, y, -z) for x, y, z in vals], "<3f", 5126, "VEC3")
                    else:
                        # Z flip: (x, y, z, w) -> (-x, -y, z, w); keep consecutive keys in one hemisphere.
                        qs = []
                        for x, y, z, w in vals:
                            q = (-x, -y, z, w)
                            if qs and sum(p * v for p, v in zip(qs[-1], q)) < 0:
                                q = tuple(-v for v in q)
                            qs.append(q)
                        out = g.accessor(qs, "<4f", 5126, "VEC4")
                    if (frames, rate) not in times:
                        times[frames, rate] = g.accessor([(f / rate,) for f in frames], "<f", 5126, "SCALAR",
                                                         minmax=True)
                    samplers.append({"input": times[frames, rate], "output": out, "interpolation": "LINEAR"})
                    channels.append({"sampler": len(samplers) - 1, "target": {"node": base + ji, "path": target}})
            if channels:
                j.setdefault("animations", []).append({"name": an["name"], "samplers": samplers, "channels": channels})
    g.write(path)
    return len(j["meshes"]), sum(len(m["primitives"]) for m in j["meshes"]), len(j.get("animations", ()))


def cmd_gltf(a):
    libs = [open(f, "rb").read() for f in a.lib]
    anims = [open(f, "rb").read() for f in a.anims]
    meshes, prims, nanim = export_gltf(open(a.file, "rb").read(), a.out, libs, anims, a.anim_match)
    print(f"wrote {a.out}: {meshes} meshes, {prims} primitives, {nanim} animations")


def location_files(rcf, location):
    """Room files and district libraries for a location: its directory name (downtown_day) or
    file prefix (dt_day). Rooms: rooms.rcf art/locations/<loc>/; libraries: districts.rcf, same path."""
    rooms_dir = os.path.join(rcf, "rooms", "art", "locations")
    locs = sorted(os.listdir(rooms_dir)) if os.path.isdir(rooms_dir) else []
    for loc in locs:
        rooms = find_p3d([os.path.join(rooms_dir, loc)])
        if location in (loc, os.path.basename(rooms[0]).rsplit("_r", 1)[0] if rooms else None):
            return rooms, find_p3d([os.path.join(rcf, "districts", "art", "locations", loc)])
    raise ValueError(f"unknown location {location!r} under {rooms_dir}; one of: {', '.join(locs)}")


def cmd_city(a):
    rooms, libs = location_files(a.rcf, a.location)
    meshes, prims, _ = export_gltf([(os.path.splitext(os.path.basename(f))[0], open(f, "rb").read()) for f in rooms],
                                   a.out, [open(f, "rb").read() for f in libs])
    print(f"wrote {a.out}: {len(rooms)} rooms, {meshes} meshes, {prims} primitives")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    d = sub.add_parser("dump"); d.add_argument("file"); d.add_argument("--max-depth", type=int, default=99)
    d.set_defaults(fn=cmd_dump)
    s = sub.add_parser("stats"); s.add_argument("paths", nargs="+"); s.set_defaults(fn=cmd_stats)
    t = sub.add_parser("textures"); t.add_argument("paths", nargs="+"); t.add_argument("-o", "--out", required=True)
    t.add_argument("--mips", action="store_true", help="also write mip levels")
    t.set_defaults(fn=cmd_textures)
    m = sub.add_parser("gltf"); m.add_argument("file"); m.add_argument("out")
    m.add_argument("--lib", action="append", default=[], help="extra .p3d to resolve shaders/textures from")
    m.add_argument("--anims", action="append", default=[], help="extra .p3d to take skeletal animations from")
    m.add_argument("--anim-match", default="*", help="glob on animation names, e.g. 'hlk_*'")
    m.set_defaults(fn=cmd_gltf)
    c = sub.add_parser("city"); c.add_argument("location"); c.add_argument("out")
    c.add_argument("--rcf", default="build/rcf", help="directory of extracted RCFs (default build/rcf)")
    c.set_defaults(fn=cmd_city)
    a = ap.parse_args()
    try:
        a.fn(a)
    except ValueError as e:
        sys.exit(f"p3d: {e}")


if __name__ == "__main__":
    main()
