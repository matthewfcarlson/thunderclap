#!/usr/bin/env python3
"""Map a Dolphin (GameCube) HD texture pack onto the Xbox version's textures.

  texpack_convert.py names <gc.ciso>                     # Dolphin names of every GC texture
  texpack_convert.py map <gc.ciso> <pack dir> <xbox dir> [-o build/texpack/map.json]
  texpack_convert.py convert <gc.ciso> <pack dir> <xbox dir> [-o build/texpack/out]
  texpack_convert.py keys <xbox dir> <keys.txt>          # check the app's sink keys against a HULK_PACK_DUMP list
  texpack_convert.py pack <pack dir> <xbox dir> --name NAME [--map build/texpack/map.json] [--mods DIR]
                                                         # -> <mods>/NAME/textures/tex-<sink key>.png (the app)
  texpack_convert.py bundle <mods>/NAME <xbox dir> OUT.hulkpack [--payload baked|png|both]
                                                         # the app pack as one file (wpkg1; docs/texture-packs.md)

<pack dir> is the folder of tex1_*.png files; <xbox dir> holds the Xbox RCFs
(isos/extracted). Everything runs from the user's own files; nothing here is
bundled. See docs/texture-packs.md for the formats, the Dolphin hash, and the
key scheme of the output (<xbox key>.png, key = XXH64 of the Xbox mip-0
ImageData payload, 16 lowercase hex digits).

The pack is untrusted input: its PNGs are only opened with Pillow, and the
tool should be run as `python3 -I` (isolated mode). Needs numpy and Pillow;
uses the `xxhash` module if installed, else a slow pure-Python XXH64.
"""
import argparse, collections, io, json, os, re, shutil, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gc_disc, p3d, rcf  # noqa: E402

import numpy as np  # noqa: E402
from PIL import Image  # noqa: E402

# ---- XXH64 --------------------------------------------------------------------

try:
    import xxhash

    def xxh64(data, seed=0):
        return xxhash.xxh64(data, seed).intdigest()
except ImportError:  # pragma: no cover - slow fallback
    _P1, _P2, _P3, _P4, _P5 = (0x9E3779B185EBCA87, 0xC2B2AE3D27D4EB4F, 0x165667B19E3779F9,
                               0x85EBCA77C2B2AE63, 0x27D4EB2F165667C5)
    _M = (1 << 64) - 1

    def _rotl(x, r):
        return ((x << r) | (x >> (64 - r))) & _M

    def _round(acc, v):
        return (_rotl((acc + v * _P2) & _M, 31) * _P1) & _M

    def xxh64(data, seed=0):
        data = bytes(data)
        n, p = len(data), 0
        if n >= 32:
            v = [(seed + _P1 + _P2) & _M, (seed + _P2) & _M, seed, (seed - _P1) & _M]
            lim = n - 32
            while p <= lim:
                w = struct.unpack_from("<4Q", data, p)
                v = [_round(v[i], w[i]) for i in range(4)]
                p += 32
            h = (_rotl(v[0], 1) + _rotl(v[1], 7) + _rotl(v[2], 12) + _rotl(v[3], 18)) & _M
            for x in v:
                h = ((h ^ _round(0, x)) * _P1 + _P4) & _M
        else:
            h = (seed + _P5) & _M
        h = (h + n) & _M
        while p + 8 <= n:
            h = (_rotl(h ^ _round(0, struct.unpack_from("<Q", data, p)[0]), 27) * _P1 + _P4) & _M
            p += 8
        if p + 4 <= n:
            h = (_rotl(h ^ (struct.unpack_from("<I", data, p)[0] * _P1) & _M, 23) * _P2 + _P3) & _M
            p += 4
        while p < n:
            h = (_rotl(h ^ (data[p] * _P5) & _M, 11) * _P1) & _M
            p += 1
        h ^= h >> 33
        h = (h * _P2) & _M
        h ^= h >> 29
        h = (h * _P3) & _M
        return h ^ (h >> 32)

# ---- GX encoders (what the GameCube build does at load time) -------------------

GX_RGBA8, GX_C8, GX_CMPR = 6, 9, 14


def _tiles(arr, bw, bh):
    """Pad HxW[xC] to whole blocks and return it in GX block order (rows of blocks, each bh x bw)."""
    h, w = arr.shape[:2]
    H, W = -(-h // bh) * bh, -(-w // bw) * bw
    pad = np.zeros((H, W) + arr.shape[2:], arr.dtype)
    pad[:h, :w] = arr
    return pad.reshape(H // bh, bh, W // bw, bw, *arr.shape[2:]).swapaxes(1, 2)


def dxt1_to_cmpr(data, w, h):
    """DXT1 blocks (row-major, LE) -> GX CMPR: 2x2 groups of 4x4 blocks per 8x8 tile,
    big-endian colours, 2-bit indices in the opposite order within each byte."""
    bw, bh = max(1, (w + 3) // 4), max(1, (h + 3) // 4)
    blk = np.frombuffer(data[:bw * bh * 8], np.uint8).reshape(bh, bw, 8)
    t = _tiles(blk, 2, 2).reshape(-1, 8).copy()      # (tiles*4, 8) in TL,TR,BL,BR order
    t[:, [0, 1, 2, 3]] = t[:, [1, 0, 3, 2]]          # u16 colours LE -> BE
    i = t[:, 4:]
    t[:, 4:] = ((i & 3) << 6) | ((i >> 2 & 3) << 4) | ((i >> 4 & 3) << 2) | (i >> 6)
    return t.tobytes()


def encode_c8(idx):
    return _tiles(idx, 8, 4).tobytes()


def encode_rgba8(rgba):
    t = _tiles(rgba, 4, 4)
    t = t.reshape(t.shape[0], t.shape[1], 16, 4)
    ar = t[..., [3, 0]].reshape(t.shape[0], t.shape[1], 32)
    gb = t[..., [1, 2]].reshape(t.shape[0], t.shape[1], 32)
    return np.concatenate([ar, gb], axis=2).tobytes()


def rgb5a3_tlut(pal):
    """256x4 RGBA palette -> big-endian RGB5A3 TLUT (opaque form when alpha >= 0xE0)."""
    p = pal.astype(np.uint16)
    r, g, b, a = p[:, 0], p[:, 1], p[:, 2], p[:, 3]
    opaque = 0x8000 | (r >> 3) << 10 | (g >> 3) << 5 | (b >> 3)
    trans = (a >> 5) << 12 | (r >> 4) << 8 | (g >> 4) << 4 | (b >> 4)
    return np.where(a >= 0xE0, opaque, trans).astype(">u2").tobytes()


def png_palette(im):
    out = np.full((256, 4), 255, np.uint8)
    p = np.frombuffer(bytes(im.getpalette("RGB") or b""), np.uint8).reshape(-1, 3)[:256]
    out[:len(p), :3] = p
    t = im.info.get("transparency")
    if isinstance(t, bytes):
        out[:len(t), 3] = np.frombuffer(t, np.uint8)[:256]
    elif isinstance(t, int):
        out[t, 3] = 0
    return out


def dolphin_name(w, h, mips, fmt, tex, tlut=None, c8_idx=None):
    """Dolphin's custom-texture name: tex1_<w>x<h>[_m]_<xxh64(base level)>[_<xxh64(tlut range)>]_<fmt>.

    For C8 the TLUT hash covers only entries min..max of the indices the base level uses.
    """
    name = f"tex1_{w}x{h}{'_m' if mips else ''}_{xxh64(tex):016x}"
    if tlut is not None:
        lo, hi = int(c8_idx.min()), int(c8_idx.max())
        name += f"_{xxh64(tlut[2 * lo:2 * (hi + 1)]):016x}"
    return name + f"_{fmt}"


def gx_from_blob(blob):
    """(w, h, fmt, gx base-level bytes, tlut, idx, flipped) for an ImageData payload, as the GC build uploads it.

    DDS (always DXT1 on GC) -> CMPR, rows as stored. Paletted PNG -> C8 + RGB5A3 TLUT,
    other PNG -> RGBA8; PNG rows are flipped vertically (bottom row first, like the DDS files).
    """
    if blob[:4] == b"DDS ":
        h, w = struct.unpack_from("<II", blob, 12)
        if blob[0x54:0x58] != b"DXT1":
            return None
        return w, h, GX_CMPR, dxt1_to_cmpr(blob[128:], w, h), None, None, False
    if blob[:4] == b"\x89PNG":
        im = Image.open(io.BytesIO(blob))
        w, h = im.size
        if im.mode == "P":
            idx = np.array(im, np.uint8)[::-1]
            return w, h, GX_C8, encode_c8(idx), rgb5a3_tlut(png_palette(im)), idx, True
        rgba = np.array(im.convert("RGBA"), np.uint8)[::-1]
        return w, h, GX_RGBA8, encode_rgba8(rgba), None, None, True
    return None


# ---- texture enumeration --------------------------------------------------------

def p3d_textures(buf):
    """[(texture name, [mip-0 payload, ...] per Image)] for every Texture chunk."""
    out = []
    try:
        chunks = p3d.parse(buf)
    except ValueError:
        return out
    for _, c in p3d.walk(chunks):
        if c.id != 0x19000:
            continue
        name = p3d.Reader(buf, c).pstr()
        blobs = []
        for img in (k for k in c.children if k.id == 0x19001):
            d = img.child(0x19002)
            if d is None:
                continue
            r = p3d.Reader(buf, d)
            blobs.append(bytes(r.raw(r.u32())))
        if blobs:
            out.append((name, blobs))
    return out


def gc_textures(disc_path):
    """Yield dicts for every texture on the GameCube disc, with its Dolphin name."""
    disc = gc_disc.Disc(disc_path)
    rcfs = disc.open("rcfs.txt").decode("latin1").strip().split(",")
    for a in rcfs:
        try:
            arc = gc_disc.Rcf(disc, a.strip())
        except (StopIteration, ValueError):
            continue
        for e in arc.entries:
            if not e[0].lower().endswith(".p3d"):
                continue
            for tn, blobs in p3d_textures(arc.read(e)):
                g = gx_from_blob(blobs[0])
                if g is None:
                    continue
                w, h, fmt, tex, tlut, idx, flipped = g
                yield dict(rcf=a, p3d=e[0], texture=tn, w=w, h=h, fmt=fmt, mips=len(blobs),
                           flipped=flipped, dolphin=dolphin_name(w, h, len(blobs) > 1, fmt, tex, tlut, idx))


def xbox_textures(xbox_dir):
    """Yield (rcf, p3d path, texture name, mip-0 payload) for every Xbox texture."""
    names = open(os.path.join(xbox_dir, "rcfs.txt")).read().strip().split(",")
    for a in names:
        path = os.path.join(xbox_dir, a.strip())
        if not os.path.exists(path):
            continue
        arc = rcf.Archive(path)
        for e in arc.entries:
            if e.name.lower().endswith(".p3d"):
                for tn, blobs in p3d_textures(arc.read(e)):
                    yield a.strip(), e.name, tn, blobs[0]


def xbox_key(blob):
    """Key of an Xbox texture: XXH64 (seed 0) of its mip-0 ImageData payload (the DDS/PNG file bytes)."""
    return f"{xxh64(blob):016x}"


# ---- image decoding / similarity ------------------------------------------------

def _565(c):
    r, g, b = (c >> 11) & 31, (c >> 5) & 63, c & 31
    return np.stack([(r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2)], -1).astype(np.int32)


def decode_dds(blob):
    """Mip 0 of a DXT1/3/5 DDS -> HxWx4 uint8 (rows as stored)."""
    h, w = struct.unpack_from("<II", blob, 12)
    cc = blob[0x54:0x58]
    bs = 8 if cc == b"DXT1" else 16
    bw, bh = max(1, (w + 3) // 4), max(1, (h + 3) // 4)
    b = np.frombuffer(blob[128:128 + bw * bh * bs], np.uint8).reshape(-1, bs)
    cb = b[:, bs - 8:]
    c0 = cb[:, 0].astype(np.int32) | cb[:, 1].astype(np.int32) << 8
    c1 = cb[:, 2].astype(np.int32) | cb[:, 3].astype(np.int32) << 8
    a, bb = _565(c0), _565(c1)
    four = (c0 > c1) | (cc != b"DXT1")
    pal = np.stack([a, bb, np.where(four[:, None], (2 * a + bb) // 3, (a + bb) // 2),
                    np.where(four[:, None], (a + 2 * bb) // 3, 0)], 1)
    alpha = np.full((len(b), 4), 255, np.int32)
    if cc == b"DXT1":
        alpha[:, 3] = np.where(four, 255, 0)
    bits = cb[:, 4:8].astype(np.uint32)
    bits = bits[:, 0] | bits[:, 1] << 8 | bits[:, 2] << 16 | bits[:, 3] << 24
    sel = (bits[:, None] >> (2 * np.arange(16, dtype=np.uint32))) & 3
    rgb = np.take_along_axis(pal, sel[:, :, None].astype(np.int64).repeat(3, 2), 1)
    al = np.take_along_axis(alpha, sel.astype(np.int64), 1)
    if cc == b"DXT3":
        ab = b[:, :8].astype(np.uint32)
        nib = np.stack([ab & 15, ab >> 4], -1).reshape(-1, 16)
        al = nib * 17
    elif cc == b"DXT5":
        a0, a1 = b[:, 0].astype(np.int32), b[:, 1].astype(np.int32)
        tab = np.zeros((len(b), 8), np.int32)
        tab[:, 0], tab[:, 1] = a0, a1
        for i in range(6):
            tab[:, 2 + i] = np.where(a0 > a1, ((6 - i) * a0 + (i + 1) * a1) // 7,
                                     ((4 - i) * a0 + (i + 1) * a1) // 5 if i < 4 else (0 if i == 4 else 255))
        ab = np.zeros(len(b), np.uint64)
        for i in range(6):
            ab |= b[:, 2 + i].astype(np.uint64) << np.uint64(8 * i)
        s = (ab[:, None] >> (3 * np.arange(16, dtype=np.uint64))) & np.uint64(7)
        al = np.take_along_axis(tab, s.astype(np.int64), 1)
    px = np.concatenate([rgb, al[:, :, None]], 2).astype(np.uint8).reshape(bh, bw, 4, 4, 4)
    return px.swapaxes(1, 2).reshape(bh * 4, bw * 4, 4)[:h, :w]


def decode_blob(blob):
    if blob[:4] == b"DDS ":
        return decode_dds(blob)
    return np.array(Image.open(io.BytesIO(blob)).convert("RGBA"), np.uint8)


def thumb(rgba, n=16):
    """16x16 premultiplied-RGB + alpha thumbnail (so colour under transparent texels is ignored)."""
    t = np.asarray(Image.fromarray(np.ascontiguousarray(rgba)).resize((n, n), Image.BILINEAR), np.float32)
    t[..., :3] *= t[..., 3:] / 255.0
    return t


def similarity(a, b):
    """Mean absolute difference of two thumbnails (0 = identical, 255 = opposite)."""
    return float(np.abs(a - b).mean())


# ---- mapping --------------------------------------------------------------------

PACK_RX = re.compile(r"tex1_(\d+)x(\d+)(_m)?_([0-9a-f]{16})(?:_([0-9a-f]{16}))?_(\d+)\.png$")
SIM_MAX = 12.0  # thumbnail MAD accepted for an image match


def build_map(disc, pack, xbox, log=print):
    pack_files = sorted(f for f in os.listdir(pack) if PACK_RX.match(f))
    pack_set = set(pack_files)
    log(f"pack: {len(pack_files)} textures")

    gc_by_name = collections.defaultdict(list)
    n_gc = 0
    for t in gc_textures(disc):
        n_gc += 1
        if t["dolphin"] + ".png" in pack_set:
            gc_by_name[t["dolphin"] + ".png"].append(t)
    log(f"gc: {n_gc} textures, {len(gc_by_name)} of {len(pack_files)} pack names reproduced")

    xb_by_path = collections.defaultdict(dict)   # p3d path -> texture name -> key
    xb_by_tex = collections.defaultdict(set)     # texture name -> keys
    xb_info, xb_blob = {}, {}
    for a, path, tn, blob in xbox_textures(xbox):
        k = xbox_key(blob)
        xb_by_path[path.lower()][tn.lower()] = k
        xb_by_tex[tn.lower()].add(k)
        xb_info.setdefault(k, dict(rcf=a, p3d=path, texture=tn, fmt=blob[:4].decode("latin1").strip(" \x89")))
        xb_blob.setdefault(k, blob)
    log(f"xbox: {len(xb_info)} distinct textures")

    thumbs = {}

    def xthumb(k):
        if k not in thumbs:
            try:
                thumbs[k] = thumb(decode_blob(xb_blob[k]))
            except Exception:  # noqa: BLE001 - odd payloads just never match
                thumbs[k] = None
        return thumbs[k]

    def pthumb(f):
        with Image.open(os.path.join(pack, f)) as im:
            return thumb(np.array(im.convert("RGBA"), np.uint8))

    entries, stats = {}, collections.Counter()
    for f in pack_files:
        gcs = gc_by_name.get(f)
        if not gcs:
            entries[f] = dict(status="no_gc_texture")
            stats["no_gc_texture"] += 1
            continue
        keys, how = {}, None
        for g in gcs:   # 1) same p3d path + texture name
            k = xb_by_path.get(g["p3d"].lower(), {}).get(g["texture"].lower())
            if k:
                keys[k] = "path+name"
        if not keys:     # 2) same texture name in any Xbox p3d
            for g in gcs:
                for k in xb_by_tex.get(g["texture"].lower(), ()):
                    keys[k] = "name"
        pt = None
        if keys:
            how = "name"
        else:            # 3) image similarity against Xbox textures of the same aspect
            pt = pthumb(f)
            g = gcs[0]
            best = None
            for k, info in xb_info.items():
                b = xb_blob[k]
                if b[:4] == b"DDS ":
                    xh, xw = struct.unpack_from("<II", b, 12)
                elif b[:4] == b"\x89PNG":
                    xw, xh = struct.unpack_from(">II", b, 16)
                else:
                    continue
                if xw * g["h"] != xh * g["w"]:
                    continue
                xt = xthumb(k)
                if xt is None:
                    continue
                s = similarity(pt, xt[::-1] if xb_blob[k][:4] == b"\x89PNG" else xt)
                if best is None or s < best[0]:
                    best = (s, k)
            if best and best[0] <= SIM_MAX:
                keys[best[1]] = "image"
                how = "image"
        # Pack images are in GX upload order (bottom row first, as the DDS files store
        # them). Xbox PNG payloads decode top row first, so compare those flipped.
        # `sim` checks the pairing; `sim_flipped` is the other orientation for reference.
        out = []
        for k, m in keys.items():
            xt = xthumb(k)
            if pt is None:
                pt = pthumb(f)
            if xt is not None and xb_info[k]["fmt"] == "PNG":
                xt = xt[::-1]
            out.append(dict(key=k, match=m, **xb_info[k],
                            sim=None if xt is None else round(similarity(pt, xt), 2),
                            sim_flipped=None if xt is None else round(similarity(pt[::-1], xt), 2)))
        if out:
            stats[how] += 1
            entries[f] = dict(status=how, gc=[{x: g[x] for x in ("rcf", "p3d", "texture", "w", "h", "fmt", "mips")}
                                              for g in gcs], xbox=out)
        else:
            stats["no_xbox_match"] += 1
            entries[f] = dict(status="no_xbox_match", gc=[{x: g[x] for x in ("rcf", "p3d", "texture", "w", "h", "fmt",
                                                                             "mips")} for g in gcs])
    log("mapping: " + ", ".join(f"{k} {v}" for k, v in stats.most_common()))
    return dict(pack_count=len(pack_files), gc_texture_count=n_gc, reproduced=len(gc_by_name),
                xbox_texture_count=len(xb_info), stats=dict(stats), entries=entries)


def cmd_names(a):
    for t in gc_textures(a.disc):
        print(f"{t['dolphin']}.png\t{t['p3d']}\t{t['texture']}")


def cmd_map(a):
    m = build_map(a.disc, a.pack, a.xbox)
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w") as f:
        json.dump(m, f, indent=1)
    print(f"wrote {a.out}")


def best_files(m, include_image=False):
    """{Xbox payload key: (pack file, candidates)} from a map: the largest pack image, then the closest thumbnail."""
    best = {}
    for f, e in m["entries"].items():
        mm = PACK_RX.match(f)
        area = int(mm[1]) * int(mm[2])
        for x in e.get("xbox", ()):
            if x["match"] == "image" and not include_image:
                continue
            rank = (-area, x["sim"] if x["sim"] is not None else 1e9, f)
            if x["key"] not in best or rank < best[x["key"]][0]:
                best[x["key"]] = (rank, f, best.get(x["key"], (None, None, 0))[2] + 1)
            else:
                best[x["key"]] = best[x["key"]][:2] + (best[x["key"]][2] + 1,)
    return {k: (f, n) for k, (_, f, n) in best.items()}


# ---- the app's keys (docs/texture-packs.md "Override packs in the app") ----------------------
#
# The app keys a texture by what its draw sink receives at upload (docs/remaster.md 2.7, option A): XXH64 (seed 0)
# of le32 format, le32 width, le32 height and the level-0 bytes, format 0 BGRA8 (A8R8G8B8 in memory), 1 BC1, 2 BC2,
# 3 BC3. A DDS payload's level 0 arrives as its blocks as stored; a PNG payload arrives decoded to BGRA8, rows in the
# order PNG_ROWS_FLIPPED says (checked against a HULK_PACK_DUMP list with `keys`).
SINK_BGRA8, SINK_BC1, SINK_BC2, SINK_BC3 = 0, 1, 2, 3
PNG_ROWS_FLIPPED = True     # (`keys` reports which order the dump confirms)


def sink_upload(blob, png_flipped=PNG_ROWS_FLIPPED):
    """(format, width, height, level-0 bytes) the sink receives for an ImageData payload, or None."""
    if blob[:4] == b"DDS ":
        h, w = struct.unpack_from("<II", blob, 12)
        fmt = {b"DXT1": SINK_BC1, b"DXT2": SINK_BC2, b"DXT3": SINK_BC2, b"DXT4": SINK_BC3,
               b"DXT5": SINK_BC3}.get(bytes(blob[0x54:0x58]))
        if fmt is None:
            return None
        bs = 8 if fmt == SINK_BC1 else 16
        n = max(1, (w + 3) // 4) * max(1, (h + 3) // 4) * bs
        return fmt, w, h, bytes(blob[128:128 + n])
    if blob[:4] == b"\x89PNG":
        rgba = np.array(Image.open(io.BytesIO(blob)).convert("RGBA"), np.uint8)
        if png_flipped:
            rgba = rgba[::-1]
        h, w = rgba.shape[:2]
        return SINK_BGRA8, w, h, np.ascontiguousarray(rgba[..., [2, 1, 0, 3]]).tobytes()
    return None


def sink_key(fmt, w, h, data):
    return f"{xxh64(struct.pack('<III', fmt, w, h) + data):016x}"


def cmd_keys(a):
    """How many Xbox textures' sink keys a session's HULK_PACK_DUMP list holds, by payload kind and PNG row order."""
    dumped = set()
    for line in open(a.dump):
        if line.startswith("tex-"):
            dumped.add(line[4:20])
    stats = collections.Counter()
    seen = set()
    for _a, _path, _tn, blob in xbox_textures(a.xbox):
        pk = xbox_key(blob)
        if pk in seen:
            continue
        seen.add(pk)
        kind = "DDS" if blob[:4] == b"DDS " else "PNG"
        variants = (True,) if kind == "DDS" else (True, False)
        hit = None
        for v in variants:
            u = sink_upload(blob, v)
            if u and sink_key(*u) in dumped:
                hit = v
                break
        stats[(kind, {None: "not seen", True: "seen" if kind == "DDS" else "seen, rows flipped",
                      False: "seen, rows as stored"}[hit])] += 1
    print(f"{len(dumped)} keys in {a.dump}")
    for (kind, how), n in sorted(stats.items()):
        print(f"  {kind:4s} {how:22s} {n}")


def cmd_pack(a):
    """The app's override pack from a Dolphin pack: <mods>/<name>/textures/tex-<sink key>.png (hard links to the
    pack's files where the orientation agrees, else flipped copies), index.txt and pack.json."""
    m = json.load(open(a.map))
    best = best_files(m, a.include_image)
    out = os.path.join(os.path.expanduser(a.mods), a.name)
    tex = os.path.join(out, "textures")
    os.makedirs(tex, exist_ok=True)
    flipped_png = a.png_rows == "flipped"
    keys, done = {}, set()
    for _a, _path, _tn, blob in xbox_textures(a.xbox):
        pk = xbox_key(blob)
        if pk not in best or pk in done:
            continue
        done.add(pk)
        u = sink_upload(blob, flipped_png)
        if u is None:
            continue
        sk = sink_key(*u)
        f, _n = best[pk]
        mm = PACK_RX.match(f)
        area = int(mm[1]) * int(mm[2])
        # Pack images are in GX upload order (bottom row first, as DDS payloads store them and the GC loader flips
        # PNGs). A PNG payload whose rows reach the sink as stored needs the pack image flipped back.
        flip = blob[:4] == b"\x89PNG" and not flipped_png
        if sk not in keys or area > keys[sk][2]:
            keys[sk] = (f, flip, area)
    for name in os.listdir(tex):            # (a previous run's files)
        if name.endswith(".png") or name == "index.txt":
            os.remove(os.path.join(tex, name))
    linked = copied = 0
    with open(os.path.join(tex, "index.txt"), "w") as idx:
        for sk, (f, flip, _area) in sorted(keys.items()):
            dst = os.path.join(tex, f"tex-{sk}.png")
            src = os.path.join(a.pack, f)
            if flip:
                with Image.open(src) as im:
                    im.transpose(Image.FLIP_TOP_BOTTOM).save(dst)
                copied += 1
            else:
                try:
                    os.link(src, dst)
                    linked += 1
                except OSError:
                    shutil.copyfile(src, dst)
                    copied += 1
            idx.write(f"tex-{sk} tex-{sk}.png\n")
    with open(os.path.join(out, "pack.json"), "w") as fh:
        json.dump(dict(name=a.name, kinds=["tex"], textures=len(keys), source="texpack_convert.py pack (a Dolphin pack)",
                       png_rows=a.png_rows), fh, indent=1)
    print(f"wrote {len(keys)} textures to {tex} ({linked} hard links, {copied} copies)")


# ---- one-file packs (wpkg1) ----------------------------------------------------
ALPHA_FULL, ALPHA_OPAQUE, ALPHA_PUNCH = 0, 1, 2     # run/app/texpack.cpp AlphaMode


def bc1_alpha(data):
    """texpack.cpp's alpha use of a DXT1 original: opaque, or 1-bit (a 3-colour block that uses index 3)"""
    b = np.frombuffer(data[:len(data) // 8 * 8], "<u2").reshape(-1, 4)
    three = b[:, 0] <= b[:, 1]
    idx = (b[:, 2].astype(np.uint32) | b[:, 3].astype(np.uint32) << 16)[three]
    for i in range(16):
        if np.any((idx >> (2 * i) & 3) == 3):
            return ALPHA_PUNCH
    return ALPHA_OPAQUE


def texbake_exe():
    """tools/texbake.cpp (the app's encoder, run/app/texpack.cpp's build()) compiled once into build/texpack/"""
    import hashlib, subprocess
    import disc_pack
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    srcs = [os.path.join(root, f) for f in ("tools/texbake.cpp", "src/platform/wasm/run/app/texpack.cpp",
                                            "src/platform/wasm/run/disc.c", "src/platform/wasm/run/disc.h")]
    h = hashlib.sha1(b"".join(open(f, "rb").read() for f in srcs)).hexdigest()[:12]
    exe = os.path.join(root, "build/texpack/texbake-" + h)
    if os.path.exists(exe):
        return exe
    os.makedirs(os.path.dirname(exe), exist_ok=True)
    tp = os.path.join(root, "build/third_party/src")
    cc = ["xcrun", "clang"] if sys.platform == "darwin" else ["cc"]
    cxx = ["xcrun", "clang++"] if sys.platform == "darwin" else ["c++"]
    objs = []
    for c in ("disc.c", "zstd_dec.c"):
        o = exe + "." + c + ".o"
        subprocess.run(cc + ["-O2", "-c", os.path.join(root, "src/platform/wasm/run", c), "-o", o] +
                       disc_pack.zstd_flags(), check=True)
        objs.append(o)
    inc = ["-I" + os.path.join(root, d) for d in ("src/platform/sdl/pddi", "src/platform/sdl")] + \
        ["-I" + os.path.join(tp, d) for d in ("bimg/include", "bx/include", "bgfx/include")]
    if sys.platform == "darwin":
        inc.append("-I" + os.path.join(tp, "bx/include/compat/osx"))
    subprocess.run(cxx + ["-std=c++20", "-O2", "-fno-exceptions", "-fno-rtti", "-w", srcs[0], "-o", exe] + inc + objs +
                   ["-lpthread"], check=True)
    for o in objs:
        os.remove(o)
    return exe


def cmd_bundle(a):
    """An app pack folder (`pack`'s output) as one .hulkpack: a disc pack (tools/disc_pack.py) of the folder, with
    textures/baked/tex-<key>-<format>-<alpha>.bin, the app's own encodes, when --payload is baked or both."""
    import subprocess, tempfile, time
    import disc_pack
    src = os.path.abspath(os.path.expanduser(a.src))
    tex = os.path.join(src, "textures")
    keys = {}
    for line in open(os.path.join(tex, "index.txt")):
        k, _, f = line.strip().partition(" ")
        if k.startswith("tex-") and f:
            keys[k[4:]] = f
    out = os.path.abspath(a.out)
    stage = tempfile.mkdtemp(prefix="hulkpack-", dir=os.path.dirname(out))
    t0 = time.time()
    try:
        st = os.path.join(stage, "textures")
        os.makedirs(os.path.join(st, "baked"))
        shutil.copyfile(os.path.join(tex, "index.txt"), os.path.join(st, "index.txt"))
        for f in ("pack.json",):
            if os.path.exists(os.path.join(src, f)):
                shutil.copyfile(os.path.join(src, f), os.path.join(stage, f))
        if a.payload in ("png", "both"):
            for k, f in keys.items():
                d = os.path.join(st, f)
                try:
                    os.link(os.path.join(tex, f), d)
                except OSError:
                    shutil.copyfile(os.path.join(tex, f), d)
        else:                       # (index.txt lists PNGs: the app keys on it; baked ones are found beside them)
            pass
        if a.payload in ("baked", "both"):
            # the (format, alpha) the app keys each replacement by: from the Xbox texture the key was made from
            want = {}
            for _a, _path, _tn, blob in xbox_textures(a.xbox):
                u = sink_upload(blob, a.png_rows == "flipped")
                if u is None:
                    continue
                k = sink_key(*u)
                if k in keys and k not in want:
                    want[k] = (u[0], bc1_alpha(u[3]) if u[0] == SINK_BC1 else ALPHA_FULL)
            missing = sorted(set(keys) - set(want))
            if missing:
                print(f"bundle: {len(missing)} keys not among the Xbox textures (kept as PNG only): {missing[:5]}")
            exe = texbake_exe()
            lines = "".join(f"{os.path.join(tex, keys[k])}\t{fmt}\t{am}\t"
                            f"{os.path.join(st, 'baked', f'tex-{k}-{fmt}-{am}.bin')}\n"
                            for k, (fmt, am) in sorted(want.items()))
            jobs = max(1, a.jobs)
            procs = []
            for i in range(jobs):           # (each worker's list from a file: pipes both ways would fill and stall)
                lst = os.path.join(stage, "bake%d.txt" % i)
                open(lst, "w").write("".join(lines.splitlines(True)[i::jobs]))
                procs.append(subprocess.Popen([exe], stdin=open(lst), stdout=subprocess.PIPE, text=True))
            bad = 0
            for p_ in procs:
                bad += sum(1 for ln in p_.stdout if ln.startswith("fail"))
                p_.wait()
            for i in range(jobs):
                os.remove(os.path.join(stage, "bake%d.txt" % i))
            print(f"bundle: baked {len(want) - bad} replacements in {time.time() - t0:.0f} s ({bad} failed)")
            if a.payload == "baked" and missing:
                for k in missing:
                    os.link(os.path.join(tex, keys[k]), os.path.join(st, keys[k]))
        disc_pack.main(["build", stage, out, "--level", str(a.level), "--chunk", "256", "--jobs", str(a.jobs)])
    finally:
        shutil.rmtree(stage, ignore_errors=True)
    print(f"bundle: {out} {os.path.getsize(out) / 1e6:.1f} MB ({len(keys)} textures, payload {a.payload}) "
          f"in {time.time() - t0:.0f} s")


def cmd_convert(a):
    if a.map and os.path.exists(a.map):
        m = json.load(open(a.map))
    else:
        m = build_map(a.disc, a.pack, a.xbox)
    os.makedirs(a.out, exist_ok=True)
    # One Xbox texture can be claimed by several pack files (the GC build sometimes has the
    # same art at two sizes or formats in different .p3d files): keep the largest pack image,
    # then the closest thumbnail.
    best = {}
    for f, e in m["entries"].items():
        mm = PACK_RX.match(f)
        area = int(mm[1]) * int(mm[2])
        for x in e.get("xbox", ()):
            if x["match"] == "image" and not a.include_image:
                continue
            rank = (-area, x["sim"] if x["sim"] is not None else 1e9, f)
            if x["key"] not in best or rank < best[x["key"]][0]:
                best[x["key"]] = (rank, f, best.get(x["key"], (None, None, 0))[2] + 1)
            else:
                best[x["key"]] = best[x["key"]][:2] + (best[x["key"]][2] + 1,)
    for k, (_, f, _n) in sorted(best.items()):
        shutil.copyfile(os.path.join(a.pack, f), os.path.join(a.out, k + ".png"))  # already in upload order
    multi = sum(v[2] > 1 for v in best.values())
    print(f"wrote {len(best)} PNGs to {a.out}" + (f" ({multi} keys had more than one candidate; largest kept)"
                                                  if multi else ""))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    p = sp.add_parser("names"); p.add_argument("disc")
    for c in ("map", "convert"):
        p = sp.add_parser(c)
        p.add_argument("disc"); p.add_argument("pack"); p.add_argument("xbox")
    sp.choices["map"].add_argument("-o", "--out", default="build/texpack/map.json")
    sp.choices["convert"].add_argument("-o", "--out", default="build/texpack/out")
    sp.choices["convert"].add_argument("--map", default="build/texpack/map.json",
                                       help="reuse a map.json from `map` (rebuilt if missing)")
    sp.choices["convert"].add_argument("--include-image", action="store_true",
                                       help="also write textures matched only by image similarity")
    p = sp.add_parser("keys")
    p.add_argument("xbox"); p.add_argument("dump", help="a HULK_PACK_DUMP keys list (keys.txt)")
    p = sp.add_parser("pack")
    p.add_argument("pack"); p.add_argument("xbox")
    p.add_argument("--name", required=True, help="the pack's folder name (the app's Texture Pack setting shows it)")
    p.add_argument("--map", default="build/texpack/map.json")
    p.add_argument("--mods", default="~/Library/Application Support/HulkUD/mods")
    p.add_argument("--png-rows", choices=("flipped", "stored"), default="flipped" if PNG_ROWS_FLIPPED else "stored",
                   help="the row order PNG payloads reach the sink in (`keys` checks it)")
    p.add_argument("--include-image", action="store_true")
    p = sp.add_parser("bundle")
    p.add_argument("src", help="an app pack folder (<mods>/NAME, `pack`'s output)")
    p.add_argument("xbox")
    p.add_argument("out", help="OUT.hulkpack (the game's derived content: keep it under build/ or the mods folder)")
    p.add_argument("--payload", choices=("baked", "png", "both"), default="baked")
    p.add_argument("--level", type=int, default=19)
    p.add_argument("--jobs", type=int, default=2)
    p.add_argument("--png-rows", choices=("flipped", "stored"), default="flipped" if PNG_ROWS_FLIPPED else "stored")
    a = ap.parse_args()
    {"names": cmd_names, "map": cmd_map, "convert": cmd_convert, "keys": cmd_keys, "pack": cmd_pack,
     "bundle": cmd_bundle}[a.cmd](a)


if __name__ == "__main__":
    main()
