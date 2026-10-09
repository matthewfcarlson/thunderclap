"""Minimal DDS (DXT1/3/5) decoder and PNG writer. Pure Python, no dependencies.

Pure3D ImageData chunks hold a plain DDS file; only the top mip level is decoded.
"""
import struct, zlib


class DdsError(Exception):
    pass


def _rgb565(c):
    r, g, b = (c >> 11) & 31, (c >> 5) & 63, c & 31
    return (r << 3 | r >> 2, g << 2 | g >> 4, b << 3 | b >> 2)


def _colors(c0, c1, dxt1):
    a, b = _rgb565(c0), _rgb565(c1)
    if c0 > c1 or not dxt1:
        return [a + (255,), b + (255,),
                tuple((2 * x + y) // 3 for x, y in zip(a, b)) + (255,),
                tuple((x + 2 * y) // 3 for x, y in zip(a, b)) + (255,)]
    return [a + (255,), b + (255,), tuple((x + y) // 2 for x, y in zip(a, b)) + (255,), (0, 0, 0, 0)]


def _alpha5(a0, a1, bits):
    if a0 > a1:
        tab = [a0, a1] + [((6 - i) * a0 + (i + 1) * a1) // 7 for i in range(6)]
    else:
        tab = [a0, a1] + [((4 - i) * a0 + (i + 1) * a1) // 5 for i in range(4)] + [0, 255]
    return [tab[(bits >> (3 * i)) & 7] for i in range(16)]


def decode(dds):
    """Return (width, height, rgba bytes) for a DDS file."""
    if dds[:4] != b"DDS ":
        raise DdsError("not a DDS file")
    h, w = struct.unpack_from("<II", dds, 12)
    pf_flags, fourcc = struct.unpack_from("<I4s", dds, 80)
    if not pf_flags & 4 or fourcc not in (b"DXT1", b"DXT3", b"DXT5"):
        raise DdsError(f"unsupported pixel format {fourcc!r}")
    bsize = 8 if fourcc == b"DXT1" else 16
    bw, bh = max(1, (w + 3) // 4), max(1, (h + 3) // 4)
    data = dds[128:128 + bw * bh * bsize]
    if len(data) < bw * bh * bsize:
        raise DdsError("truncated DDS data")
    out = bytearray(w * h * 4)
    p = 0
    for by in range(bh):
        for bx in range(bw):
            alpha = None
            if fourcc == b"DXT3":
                a = int.from_bytes(data[p:p + 8], "little")
                alpha = [((a >> (4 * i)) & 15) * 17 for i in range(16)]
                p += 8
            elif fourcc == b"DXT5":
                alpha = _alpha5(data[p], data[p + 1], int.from_bytes(data[p + 2:p + 8], "little"))
                p += 8
            c0, c1, idx = struct.unpack_from("<HHI", data, p)
            p += 8
            pal = _colors(c0, c1, fourcc == b"DXT1")
            for i in range(16):
                x, y = bx * 4 + (i & 3), by * 4 + (i >> 2)
                if x < w and y < h:
                    px = pal[(idx >> (2 * i)) & 3]
                    o = (y * w + x) * 4
                    out[o:o + 4] = bytes(px if alpha is None else px[:3] + (alpha[i],))
    return w, h, bytes(out)


def png(w, h, rgba):
    def chunk(t, b):
        return struct.pack(">I", len(b)) + t + b + struct.pack(">I", zlib.crc32(t + b))
    raw = b"".join(b"\0" + rgba[y * w * 4:(y + 1) * w * 4] for y in range(h))
    return (b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 6, 0, 0, 0))
            + chunk(b"IDAT", zlib.compress(raw, 6)) + chunk(b"IEND", b""))
