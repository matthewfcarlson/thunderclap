#!/usr/bin/env python3
"""A synthetic Xbox disc image (XDVDFS) for the disc layer's tests (wpkg1): generated files only, nothing of the game.

  build/venv/bin/python tests/wasm_disc/make_test_iso.py OUTDIR

writes OUTDIR/folder/ (the files), OUTDIR/trimmed.iso (the volume at 0) and OUTDIR/full.iso (the volume at the
game-partition offset of a full Redump image, 0x18300000; sparse, so it takes no room for the gap). The directory
tables are balanced binary trees over case-insensitively sorted names, 4-aligned entries that never cross a sector
(the rest of a sector 0xFF), as the format's public description gives them. Then

  tests/wasm_disc/run.sh OUTDIR/folder OUTDIR/full.iso
  build/venv/bin/python tools/disc_pack.py build OUTDIR/folder OUTDIR/t.hulkdisc --chunk 64 && \\
      tests/wasm_disc/run.sh OUTDIR/folder OUTDIR/t.hulkdisc
"""
import os
import random
import struct
import sys

SECTOR = 2048
MAGIC = b"MICROSOFT*XBOX*MEDIA"


def tree():
    """{name: bytes | dict}: many names (deep trees), mixed case, a subfolder, an empty file and folder, sizes on and
    around chunk and sector edges, a zero-filled file"""
    rnd = random.Random(7)
    t = {"default.xbe": bytes(rnd.getrandbits(8) for _ in range(70000)), "RCFS.txt": b"a.rcf,b.rcf -x\n",
         "empty.bin": b"", "zeros.bin": bytes(300000), "Empty Folder": {}}
    for i in range(150):
        n = rnd.choice([1, 2047, 2048, 2049, 65535, 65536, 65537, 262144, 300001, rnd.randrange(1, 400000)])
        t["file%03d.%s" % (i, rnd.choice(["rcf", "Bin", "txt"]))] = bytes(rnd.getrandbits(8) for _ in range(n)) \
            if i % 3 else (b"compressible text %d " % i) * (n // 20 + 1)
    t["img"] = {"a.bin": b"x" * 5000, "B.bin": b"y" * 3, "deeper": {"z.dat": bytes(range(256)) * 40}}
    return t


def write_folder(t, d):
    os.makedirs(d, exist_ok=True)
    for k, v in t.items():
        p = os.path.join(d, k)
        if isinstance(v, dict):
            write_folder(v, p)
        else:
            open(p, "wb").write(v)


class Image:
    def __init__(self):
        self.data = bytearray()

    def alloc(self, nbytes):
        """sectors for nbytes at the end (relative to the volume); returns the first sector"""
        s = max(len(self.data) // SECTOR, 33)
        self.data += bytes(s * SECTOR - len(self.data))
        self.data += bytes(-(-max(nbytes, 1) // SECTOR) * SECTOR)
        return s

    def put(self, sector, b):
        self.data[sector * SECTOR:sector * SECTOR + len(b)] = b


def write_dir(img, t):
    """the directory's table (and its children); returns (sector, size)"""
    names = sorted(t, key=lambda n: n.upper())
    if not names:
        return 0, 0
    kids = {}
    for n in names:
        v = t[n]
        if isinstance(v, dict):
            kids[n] = write_dir(img, v) + (0x10,)
        else:
            s = img.alloc(len(v))
            img.put(s, v)
            kids[n] = (s, len(v), 0x20)
    # the table: entries in pre-order of a balanced tree; offsets are known after layout, so lay out twice
    order = []

    def pre(lo, hi):
        if lo >= hi:
            return None
        m = (lo + hi) // 2
        order.append(m)
        return m, pre(lo, m), pre(m + 1, hi)
    root = pre(0, len(names))
    offs = {}
    pos = 0
    for m in order:
        size = (14 + len(names[m]) + 3) & ~3
        if pos // SECTOR != (pos + size - 1) // SECTOR:
            pos = (pos // SECTOR + 1) * SECTOR
        offs[m] = pos
        pos += size
    table = bytearray(b"\xff" * (-(-pos // SECTOR) * SECTOR))

    def emit(node):
        if node is None:
            return
        m, l, r = node
        s, n, attr = kids[names[m]]
        nb = names[m].encode("latin1")
        e = struct.pack("<HHIIBB", offs[l[0]] // 4 if l else 0, offs[r[0]] // 4 if r else 0, s, n, attr, len(nb)) + nb
        e += b"\0" * (((len(e) + 3) & ~3) - len(e))
        table[offs[m]:offs[m] + len(e)] = e
        emit(l)
        emit(r)
    emit(root)
    sec = img.alloc(len(table))
    img.put(sec, table)
    return sec, len(table)


def write_iso(t, path, base):
    img = Image()
    img.alloc(0)
    root, size = write_dir(img, t)
    vd = bytearray(SECTOR)
    vd[0:20] = MAGIC
    struct.pack_into("<II", vd, 20, root, size)
    vd[0x7EC:0x800] = MAGIC
    img.put(32, vd)
    with open(path, "wb") as f:
        if base:
            f.truncate(base)        # (a hole: the video partition of a full image)
            f.seek(base)
        f.write(img.data)


def main():
    out = sys.argv[1]
    t = tree()
    write_folder(t, os.path.join(out, "folder"))
    write_iso(t, os.path.join(out, "trimmed.iso"), 0)
    write_iso(t, os.path.join(out, "full.iso"), 0x18300000)
    print("wrote %s/{folder,trimmed.iso,full.iso}" % out)


if __name__ == "__main__":
    main()
