#!/usr/bin/env python3
"""Read files out of a GameCube disc image (.iso or .ciso) without extracting it.

  gc_disc.py info <disc>                 # game id, title, FST size
  gc_disc.py list <disc> [GLOB]          # every file: offset, size, path
  gc_disc.py extract <disc> <path> <out> # one file to disk

CISO container (as written by Dolphin / ciso tools): "CISO" magic, u32 block
size (little-endian) at +4, then a 0x7ff8-byte map with one byte per disc
block (1 = present). Present blocks follow the 0x8000-byte header in order;
absent blocks read as zeros.

GameCube disc (big-endian): boot.bin at 0 (game id at 0, title at 0x20,
FST offset/size at 0x424/0x428). FST: 12-byte entries {u8 is_dir, u24 name
offset, u32 file offset | parent, u32 size | next index}; entry 0 is the root
and its third word is the entry count; the name table follows the entries.
"""
import argparse, fnmatch, mmap, os, struct, sys

CISO_HDR = 0x8000


class Disc:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.m = mmap.mmap(self.f.fileno(), 0, access=mmap.ACCESS_READ)
        if self.m[:4] == b"CISO":
            self.block, = struct.unpack_from("<I", self.m, 4)
            present = self.m[8:CISO_HDR]
            self.map, n = [], 0
            for b in present:
                self.map.append(n if b else None)
                n += bool(b)
        else:
            self.block, self.map = None, None
        self._fst = None

    def read(self, off, n):
        if self.map is None:
            return self.m[off:off + n]
        out = bytearray()
        while n > 0:
            blk, inner = divmod(off, self.block)
            take = min(n, self.block - inner)
            idx = self.map[blk] if blk < len(self.map) else None
            if idx is None:
                out += bytes(take)
            else:
                p = CISO_HDR + idx * self.block + inner
                out += self.m[p:p + take]
            off += take
            n -= take
        return bytes(out)

    def header(self):
        h = self.read(0, 0x440)
        fst_off, fst_size = struct.unpack_from(">II", h, 0x424)
        return {"id": h[:6].decode("latin1"), "title": h[0x20:0x60].split(b"\0")[0].decode("latin1"),
                "fst_off": fst_off, "fst_size": fst_size}

    def files(self):
        """[(path, disc offset, size)] for every file in the FST."""
        if self._fst is not None:
            return self._fst
        h = self.header()
        fst = self.read(h["fst_off"], h["fst_size"])
        count, = struct.unpack_from(">I", fst, 8)
        names = fst[count * 12:]

        def name(i):
            w, = struct.unpack_from(">I", fst, i * 12)
            o = w & 0xFFFFFF
            return names[o:names.index(b"\0", o)].decode("latin1")

        out, stack = [], [("", count)]  # (dir prefix, end index)
        i = 1
        while i < count:
            while stack and i >= stack[-1][1]:
                stack.pop()
            w, a, b = struct.unpack_from(">III", fst, i * 12)
            prefix = stack[-1][0] if stack else ""
            if w >> 24:
                stack.append((prefix + name(i) + "/", b))
            else:
                out.append((prefix + name(i), a, b))
            i += 1
        self._fst = out
        return out

    def open(self, path):
        for p, off, size in self.files():
            if p.lower() == path.lower():
                return self.read(off, size)
        raise KeyError(path)


class Rcf:
    """An RCF archive read in place from the disc (docs/formats/rcf.md).

    The GameCube archives carry version bytes 02 01 01 01: byte [2] = 1 marks
    a big-endian header and directory. The name table stays little-endian
    (same records as on Xbox), so names join to entries by hash as usual.
    """

    def __init__(self, disc, path):
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import rcf
        self.disc = disc
        self.base, self.size = next((o, s) for p, o, s in disc.files() if p.lower() == path.lower())
        h = disc.read(self.base, 0x3C)
        if not h.startswith(rcf.MAGIC):
            raise ValueError(f"{path}: not an RCF")
        e = ">" if h[0x22] == 1 else "<"
        _v, dir_off, dir_size, names_off, names_size, _r, count = struct.unpack_from(e + "7I", h, 0x20)
        dirb = disc.read(self.base + dir_off, dir_size)
        by_hash = {}
        for i in range(count):
            hh, off, size = struct.unpack_from(e + "3I", dirb, 12 * i)
            by_hash[hh] = (off, size)
        names = disc.read(self.base + names_off, names_size)
        p, self.entries = 8, []
        for _ in range(count):
            _mt, _al, _z, n = struct.unpack_from("<4I", names, p)
            name = names[p + 16:p + 15 + n].decode("latin1")
            p += 16 + n + 3
            off, size = by_hash[rcf.rhash(name)]
            self.entries.append((name, off, size))

    def read(self, name_or_entry):
        if isinstance(name_or_entry, str):
            name_or_entry = next(e for e in self.entries if e[0].lower() == name_or_entry.lower())
        _, off, size = name_or_entry
        return self.disc.read(self.base + off, size)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    p = sp.add_parser("info"); p.add_argument("disc")
    p = sp.add_parser("list"); p.add_argument("disc"); p.add_argument("glob", nargs="?", default="*")
    p = sp.add_parser("extract"); p.add_argument("disc"); p.add_argument("path"); p.add_argument("out")
    a = ap.parse_args()
    d = Disc(a.disc)
    if a.cmd == "info":
        h = d.header()
        print(f"{h['id']} {h['title']!r} fst@{h['fst_off']:#x} size={h['fst_size']:#x}"
              + (f" ciso block={d.block:#x}" if d.block else ""))
    elif a.cmd == "list":
        for path, off, size in d.files():
            if fnmatch.fnmatch(path.lower(), a.glob.lower()):
                print(f"{off:#010x} {size:10d} {path}")
    else:
        with open(a.out, "wb") as f:
            f.write(d.open(a.path))


if __name__ == "__main__":
    main()
