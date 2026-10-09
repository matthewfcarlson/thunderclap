#!/usr/bin/env python3
"""List / extract / repack radcore "ATG CORE CEMENT LIBRARY" (.rcf) archives.

Layout is documented in docs/formats/rcf.md. Names are joined to directory
entries by the game's own filename hash (FUN_002673d0), so every entry is
named exactly; repack reproduces the shipped archives byte-for-byte.

  rcf.py list <file.rcf>
  rcf.py extract <file.rcf> <outdir>      # also writes <outdir>/_rcf.json
  rcf.py repack <dir> <out.rcf>           # uses <dir>/_rcf.json if present
  rcf.py verify <file.rcf>...             # rebuild in memory, compare bytes
  rcf.py hash <name>...
"""
import argparse, json, mmap, os, re, struct, sys

MAGIC = b"ATG CORE CEMENT LIBRARY"
VERSION = 0x01000102        # bytes 02 01 00 01; the loader checks [0]==2, [1]<=1, [2]==0, [3]!=0
HDR_SIZE = 0x3C
ALIGN = 0x800
MANIFEST = "_rcf.json"


class RcfError(Exception):
    pass


def rhash(name, seed=0):
    """Filename hash used by the cement library (FUN_002673d0 in the XBE).

    h = h*31 + c over signed chars, with 0x20 added to every char below 'a'.
    That folds A-Z to a-z but also shifts '\\', '.', digits etc., so 'A' and
    'a' collide on purpose while '/' and '\\' do not.
    """
    if isinstance(name, str):
        name = name.encode("latin1")
    h = seed
    for c in name:
        if c >= 0x80:
            c -= 0x100
        if c < 0x61:
            c += 0x20
        h = (h * 31 + c) & 0xFFFFFFFF
    return h


def align(n, a=ALIGN):
    return (n + a - 1) & ~(a - 1)


class Entry:
    __slots__ = ("hash", "offset", "size", "name", "mtime")

    def __init__(self, h, off, size, name=None, mtime=0):
        self.hash, self.offset, self.size, self.name, self.mtime = h, off, size, name, mtime


class Archive:
    """Parsed archive. `entries` are in name-table order, which is also data order."""

    def __init__(self, path):
        with open(path, "rb") as f:
            self.data = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
        d = self.data
        if d[:len(MAGIC)] != MAGIC:
            raise RcfError("bad magic")
        (self.version, dir_off, dir_size, self.names_off, self.names_size,
         self.reserved, count) = struct.unpack_from("<7I", d, 0x20)
        if dir_off != HDR_SIZE or dir_size != count * 12:
            raise RcfError(f"unexpected directory {dir_off:#x}+{dir_size:#x} for {count} files")
        by_hash = {}
        for i in range(count):
            h, off, size = struct.unpack_from("<3I", d, dir_off + 12 * i)
            if off + size > len(d):
                raise RcfError(f"entry {h:08x} runs past EOF")
            by_hash[h] = Entry(h, off, size)
        if len(by_hash) != count:
            raise RcfError("duplicate hashes in directory")
        p = self.names_off + 8          # u32 alignment (0x800), u32 0
        self.entries = []
        for _ in range(count):
            mtime, _al, _z, n = struct.unpack_from("<4I", d, p)
            p += 16
            name = d[p:p + n - 1].decode("latin1")
            p += n + 3
            e = by_hash.pop(rhash(name), None)
            if e is None:
                raise RcfError(f"name {name!r} has no matching directory entry")
            e.name, e.mtime = name, mtime
            self.entries.append(e)
        if p != self.names_off + self.names_size:
            raise RcfError(f"name table ends at {p:#x}, header says {self.names_off + self.names_size:#x}")

    def read(self, e):
        return self.data[e.offset:e.offset + e.size]


def entry_path(name):
    parts = [p for p in re.split(r"[\\/]+", name) if p and p not in (".", "..")]
    if not parts:
        raise RcfError(f"empty path {name!r}")
    return os.path.join(*parts)


def build(entries, read, version=VERSION):
    """Yield the bytes of an archive. `entries` are (name, mtime, size) in data order;
    `read(i)` returns the bytes of entry i."""
    count = len(entries)
    hashes = [rhash(n) for n, _, _ in entries]
    if len(set(hashes)) != count:
        raise RcfError("filename hash collision")
    names = bytearray(struct.pack("<2I", ALIGN, 0))
    for n, mtime, _ in entries:
        b = n.encode("latin1") + b"\0"
        names += struct.pack("<4I", mtime, ALIGN, 0, len(b)) + b + b"\0\0\0"
    names_off = align(HDR_SIZE + 12 * count)
    off = align(names_off + len(names))
    offsets = []
    for _, _, size in entries:
        offsets.append(off)
        off = align(off + size)
    hdr = bytearray(names_off)
    hdr[:len(MAGIC)] = MAGIC
    struct.pack_into("<7I", hdr, 0x20, version, HDR_SIZE, 12 * count, names_off, len(names), 0, count)
    for i, (h, o, (_, _, size)) in enumerate(sorted(zip(hashes, offsets, entries))):
        struct.pack_into("<3I", hdr, HDR_SIZE + 12 * i, h, o, size)
    yield bytes(hdr)
    yield bytes(names) + bytes(align(names_off + len(names)) - names_off - len(names))
    for i, (_, _, size) in enumerate(entries):
        b = read(i)
        if len(b) != size:
            raise RcfError(f"{entries[i][0]}: size changed while packing")
        yield b
        if i + 1 < count:           # the last file is not padded
            yield bytes(align(size) - size)


def cmd_list(a):
    ar = Archive(a.file)
    for e in ar.entries:
        print(f"{e.hash:08x} {e.offset:#010x} {e.size:>10} {e.name}")
    print(f"# {len(ar.entries)} files", file=sys.stderr)


def cmd_extract(a):
    ar = Archive(a.file)
    os.makedirs(a.outdir, exist_ok=True)
    root = os.path.realpath(a.outdir)
    seen = {}
    for e in ar.entries:
        rel = entry_path(e.name)
        if rel.lower() in seen:
            raise RcfError(f"{e.name!r} and {seen[rel.lower()]!r} collide on a case-insensitive filesystem")
        seen[rel.lower()] = e.name
        dst = os.path.realpath(os.path.join(root, rel))
        if not dst.startswith(root + os.sep):
            raise RcfError(f"unsafe path {e.name!r}")
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as f:
            f.write(ar.read(e))
        os.utime(dst, (e.mtime, e.mtime))
    with open(os.path.join(root, MANIFEST), "w") as f:
        json.dump({"version": ar.version,
                   "files": [{"name": e.name, "mtime": e.mtime} for e in ar.entries]}, f, indent=1)
    print(f"extracted {len(ar.entries)} files to {a.outdir}")


def cmd_repack(a):
    root = a.dir
    mpath = os.path.join(root, MANIFEST)
    if os.path.exists(mpath):
        with open(mpath) as f:
            m = json.load(f)
        version, files = m["version"], [(x["name"], x["mtime"]) for x in m["files"]]
    else:
        version, files = VERSION, []
        for dp, dns, fns in os.walk(root):
            dns.sort()
            for fn in sorted(fns):
                p = os.path.join(dp, fn)
                files.append((os.path.relpath(p, root).replace(os.sep, "\\"), int(os.stat(p).st_mtime)))
    paths = [os.path.join(root, entry_path(n)) for n, _ in files]
    entries = [(n, t, os.path.getsize(p)) for (n, t), p in zip(files, paths)]

    def read(i):
        with open(paths[i], "rb") as f:
            return f.read()
    with open(a.out, "wb") as f:
        for chunk in build(entries, read, version):
            f.write(chunk)
    print(f"packed {len(entries)} files into {a.out}")


def verify(path):
    """Rebuild `path` from its own parse and compare. Returns the first differing offset or None."""
    ar = Archive(path)
    entries = [(e.name, e.mtime, e.size) for e in ar.entries]
    pos = 0
    for chunk in build(entries, lambda i: ar.read(ar.entries[i]), ar.version):
        orig = ar.data[pos:pos + len(chunk)]
        if orig != chunk:
            return pos + next((i for i, (x, y) in enumerate(zip(orig, chunk)) if x != y), min(len(orig), len(chunk)))
        pos += len(chunk)
    return None if pos == len(ar.data) else pos


def cmd_verify(a):
    bad = 0
    for p in a.files:
        r = verify(p)
        print(f"{p}: {'OK' if r is None else f'MISMATCH at {r:#x}'}")
        bad += r is not None
    return 1 if bad else 0


def cmd_hash(a):
    for n in a.names:
        print(f"{rhash(n):08x} {n}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list"); p.add_argument("file"); p.set_defaults(fn=cmd_list)
    p = sub.add_parser("extract"); p.add_argument("file"); p.add_argument("outdir"); p.set_defaults(fn=cmd_extract)
    p = sub.add_parser("repack"); p.add_argument("dir"); p.add_argument("out"); p.set_defaults(fn=cmd_repack)
    p = sub.add_parser("verify"); p.add_argument("files", nargs="+"); p.set_defaults(fn=cmd_verify)
    p = sub.add_parser("hash"); p.add_argument("names", nargs="+"); p.set_defaults(fn=cmd_hash)
    a = ap.parse_args()
    try:
        sys.exit(a.fn(a) or 0)
    except RcfError as e:
        sys.exit(f"rcf: {e}")


if __name__ == "__main__":
    main()
