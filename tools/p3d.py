#!/usr/bin/env python3
"""Inspect Pure3D (.p3d) chunk trees.

  p3d.py dump <file.p3d> [--max-depth N]
  p3d.py stats <file-or-dir>...     # chunk-id histogram, unknown ids ranked

Layout (docs/formats/p3d.md): 12-byte file header (magic, header size, file
length) followed by chunks of {u32 id, u32 data_off, u32 total_size}; children
follow the chunk's own data and lie inside total_size. Chunk names below come
from public SHAR format docs and are UNVERIFIED for Hulk UD. Parsing is
tolerant: bad sizes are reported, never fatal.
"""
import argparse, collections, os, struct, sys

MAGIC_LE = b"P3D\xff"
MAGIC_BE = b"\xffD3P"

# id -> name, from memory of public Donut Team/SHAR docs; verify against loaders.
NAMES = {
    0x7000: "History", 0x11000: "Shader", 0x10000: "Geometry",
    0x10002: "PrimitiveGroup", 0x10005: "PositionList", 0x10006: "NormalList",
    0x10007: "UVList", 0x1000A: "IndexList", 0x4500: "Skeleton",
    0x4501: "SkeletonJoint", 0x19000: "Texture", 0x19001: "Image",
    0x19002: "ImageData", 0x121000: "Animation",
}


class Chunk:
    __slots__ = ("id", "data_off", "size", "start", "children", "bad")

    def __init__(self, id, start, data_off, size):
        self.id, self.start, self.data_off, self.size = id, start, data_off, size
        self.children, self.bad = [], None

    @property
    def name(self):
        return NAMES.get(self.id, "?")


def parse_chunks(buf, pos, end, endian, bad_out=None):
    out = []
    while pos + 12 <= end:
        cid, doff, size = struct.unpack_from(endian + "3I", buf, pos)
        c = Chunk(cid, pos, doff, size)
        if size < 12 or doff < 12 or doff > size or pos + size > end:
            c.bad = f"bad sizes (data_off={doff:#x} size={size:#x}) at {pos:#x}"
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


def cmd_dump(a):
    buf = open(a.file, "rb").read()
    for d, c in walk(parse(buf)):
        if d > a.max_depth:
            continue
        line = f"{'  ' * d}{c.id:#08x} {c.name} @{c.start:#x} data={c.size - c.data_off} total={c.size}"
        print(line + (f"  !! {c.bad}" if c.bad else ""))


def cmd_stats(a):
    files = []
    for p in a.paths:
        if os.path.isdir(p):
            for r, _, fs in os.walk(p):
                files += [os.path.join(r, f) for f in fs if f.lower().endswith(".p3d")]
        else:
            files.append(p)
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
        print(f"{cid:#08x} {NAMES.get(cid, 'UNKNOWN'):<16}{n}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    d = sub.add_parser("dump"); d.add_argument("file"); d.add_argument("--max-depth", type=int, default=99)
    d.set_defaults(fn=cmd_dump)
    s = sub.add_parser("stats"); s.add_argument("paths", nargs="+"); s.set_defaults(fn=cmd_stats)
    a = ap.parse_args()
    try:
        a.fn(a)
    except ValueError as e:
        sys.exit(f"p3d: {e}")


if __name__ == "__main__":
    main()
