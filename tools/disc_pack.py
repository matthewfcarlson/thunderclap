#!/usr/bin/env python3
"""The disc pack (wpkg1, D237; docs/wasm-port.md "Disc sources"): the player's game as one compressed, seekable file the
wasm apps read in place (src/platform/wasm/run/disc.c), beside the extracted folder and the Xbox .iso.

  build/venv/bin/python tools/disc_pack.py build SRC OUT.hulkdisc [--level 19] [--chunk 256] [--jobs 2]
        [--av1 DIR] [--texpack F.hulkpack ...]
  build/venv/bin/python tools/disc_pack.py verify PACK [--source SRC]      # every file's bytes round-trip
  build/venv/bin/python tools/disc_pack.py measure SRC [--levels 3,9,19] [--chunks 64,256,1024] [--stride 8]
  build/venv/bin/python tools/disc_pack.py ls PACK|ISO                      # the files (an .iso: its XDVDFS tree)
  build/venv/bin/python tools/disc_pack.py cat PACK|ISO NAME > out
  build/venv/bin/python tools/disc_pack.py fetch-zstd                       # zstd's sources for the runners

SRC is the extracted disc folder (default.xbe, the .rcf archives) or an Xbox disc image: a full (Redump) image, whose
game partition starts at 0x18300000, or a trimmed (xiso) image, whose XDVDFS volume starts at 0. With --av1 DIR
(tools/disc_av1.py encode) the movies' pictures are stored as AV1 (see "Movies" below); a SRC that is itself a pack
keeps its AV1 movies (unless --av1 replaces them) and its texture packs. With --texpack F.hulkpack (a one-file texture
pack, texpack_convert.py bundle) the pack also carries that texture pack, so one file holds the game and its HD
textures (wapk1: Android's file picker grants the one file picked): its files go under .hulk/texpacks/<name>/
(<name>: the file's name without .hulkpack), and the app lists it in Video Options > Texture Pack like a one-file pack
whenever the game comes from this pack (run/app/texpack.cpp).

The format (all little-endian; nothing in it but what the source holds):
  0x00 "HULKDISC" | u32 version (1) | u32 chunk size | u64 index offset | u32 index size (zstd) | u32 index raw size
       | u64 bytes of all files | u32 file count | u32 chunk count | 0x30..0x40 zero
  0x40 the chunks: every file starts a new chunk; a chunk is `chunk size` bytes of one file (the last one shorter),
       stored as one zstd frame with its checksum (kind 0), as it is (kind 1: zstd did not save 3%), or not at all
       (kind 2: all zero bytes)
  then the index, one zstd frame: u32 files, u32 chunks, u32 names size, u32 0; files x {u32 name offset, u32 flags
       (1: the pack's own, 2: a folder), u64 size, u32 first chunk, u32 0} sorted by name; chunks x {u64 offset, u32 stored size, u32 kind}; the names
       (NUL-terminated, '/'-separated, relative to the disc's root).
Files under ".hulk/" are the pack's own (the game never lists them): .hulk/pack.json (the source, the settings and
every disc file's size and sha256: `verify` checks them with no source at hand), the movies' AV1 streams and the
texture packs (each member's size and sha256 in the manifest too).

zstd is BSD-licensed (facebook/zstd); this tool uses the system's libzstd through ctypes (Homebrew's zstd, or
HULK_LIBZSTD), and the runners compile zstd's decompressor from the pinned sources fetch-zstd unpacks into
build/third_party/src/zstd. Packs are derived from the player's own disc: they stay under build/ or the player's
own folders, never committed or published.
"""
import argparse
import concurrent.futures
import ctypes
import ctypes.util
import hashlib
import json
import os
import shutil
import struct
import sys
import tarfile
import time
import urllib.request

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MAGIC = b"HULKDISC"
VERSION = 1
HDR = 0x40
KIND_ZSTD, KIND_RAW, KIND_ZERO = 0, 1, 2
FLAG_OWN, FLAG_DIR = 1, 2           # a file entry's flags: the pack's own (.hulk/), a folder (no chunks)
SECTOR = 2048
XDVDFS_MAGIC = b"MICROSOFT*XBOX*MEDIA"
# where an image's XDVDFS volume can start: a trimmed image (0) and the game partition of a full Redump image of an
# original Xbox disc (XGD1). The volume descriptor is sector 32 of the partition.
ISO_OFFSETS = (0, 0x18300000)

ZSTD_PIN = ("zstd", "facebook/zstd", "v1.5.7", "37d7284556b20954e56e1ca85b80226768902e2edabd3b649e9e72c0c9012ee3")
TP = os.path.join(ROOT, "build/third_party")


def log(msg):
    print(msg, flush=True)


# ------------------------------------------------------------------------------------------------ zstd (ctypes)
class Zstd:
    def __init__(self):
        cands = [os.environ.get("HULK_LIBZSTD"), "/opt/homebrew/opt/zstd/lib/libzstd.dylib",
                 "/usr/local/opt/zstd/lib/libzstd.dylib", ctypes.util.find_library("zstd"), "libzstd.so.1"]
        self.lib = None
        for c in cands:
            if not c:
                continue
            try:
                self.lib = ctypes.CDLL(c)
                break
            except OSError:
                continue
        if not self.lib:
            raise SystemExit("disc_pack: no libzstd (brew install zstd, or HULK_LIBZSTD=<path to libzstd>)")
        L = self.lib
        L.ZSTD_compressBound.restype = ctypes.c_size_t
        L.ZSTD_compressBound.argtypes = [ctypes.c_size_t]
        L.ZSTD_isError.restype = ctypes.c_uint
        L.ZSTD_isError.argtypes = [ctypes.c_size_t]
        L.ZSTD_getErrorName.restype = ctypes.c_char_p
        L.ZSTD_getErrorName.argtypes = [ctypes.c_size_t]
        L.ZSTD_createCCtx.restype = ctypes.c_void_p
        L.ZSTD_freeCCtx.argtypes = [ctypes.c_void_p]
        L.ZSTD_CCtx_setParameter.restype = ctypes.c_size_t
        L.ZSTD_CCtx_setParameter.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int]
        L.ZSTD_compress2.restype = ctypes.c_size_t
        L.ZSTD_compress2.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p,
                                     ctypes.c_size_t]
        L.ZSTD_decompress.restype = ctypes.c_size_t
        L.ZSTD_decompress.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p, ctypes.c_size_t]
        L.ZSTD_versionString.restype = ctypes.c_char_p
        import threading
        self.tls = threading.local()

    def version(self):
        return self.lib.ZSTD_versionString().decode()

    def _check(self, r):
        if self.lib.ZSTD_isError(r):
            raise RuntimeError("zstd: " + self.lib.ZSTD_getErrorName(r).decode())
        return r

    def compress(self, data, level):
        c = getattr(self.tls, "cctx", None)
        if c is None or self.tls.level != level:
            if c:
                self.lib.ZSTD_freeCCtx(c)
            c = self.tls.cctx = self.lib.ZSTD_createCCtx()
            self.tls.level = level
            self._check(self.lib.ZSTD_CCtx_setParameter(c, 100, level))     # ZSTD_c_compressionLevel
            self._check(self.lib.ZSTD_CCtx_setParameter(c, 201, 1))         # ZSTD_c_checksumFlag
        cap = self.lib.ZSTD_compressBound(len(data))
        out = ctypes.create_string_buffer(cap)
        src = ctypes.c_char_p(bytes(data))
        n = self._check(self.lib.ZSTD_compress2(c, out, cap, src, len(data)))
        return out.raw[:n]

    def decompress(self, data, size):
        out = ctypes.create_string_buffer(max(size, 1))
        n = self._check(self.lib.ZSTD_decompress(out, size, ctypes.c_char_p(bytes(data)), len(data)))
        if n != size:
            raise RuntimeError("zstd: %d bytes, expected %d" % (n, size))
        return out.raw[:size]


# ------------------------------------------------------------------------------------------------ sources
class FolderSource:
    kind = "folder"

    def __init__(self, root):
        self.root = root
        self.files = {}
        self.dirs = set()
        for dp, dns, fns in os.walk(root):
            dns[:] = sorted(d for d in dns if not d.startswith("."))
            for d in dns:
                self.dirs.add(os.path.relpath(os.path.join(dp, d), root).replace(os.sep, "/"))
            for f in fns:
                if f.startswith("."):
                    continue
                p = os.path.join(dp, f)
                rel = os.path.relpath(p, root).replace(os.sep, "/")
                self.files[rel] = os.path.getsize(p)

    def read(self, name, off, n):
        with open(os.path.join(self.root, name), "rb") as f:
            f.seek(off)
            return f.read(n)


def iso_volume(f):
    """The byte offset of the image's XDVDFS partition, or None."""
    for base in ISO_OFFSETS:
        f.seek(base + 32 * SECTOR)
        v = f.read(SECTOR)
        if len(v) == SECTOR and v[:20] == XDVDFS_MAGIC and v[0x7EC:0x800] == XDVDFS_MAGIC:
            return base
    return None


class IsoSource:
    """An Xbox disc image's XDVDFS tree (written from the format's public description: a volume descriptor at the
    partition's sector 32 naming the root directory table; each table a binary tree of entries {u16 left, u16 right
    (in 4-byte units from the table's start, 0 = none), u32 sector, u32 size, u8 attributes (0x10: a directory),
    u8 name length, name}, entries 4-aligned, a sector's unused tail 0xFF)."""
    kind = "iso"

    def __init__(self, path):
        self.path = path
        self.f = open(path, "rb")
        self.base = iso_volume(self.f)
        if self.base is None:
            raise SystemExit("%s: not an Xbox disc image (no XDVDFS volume at 0 or 0x18300000)" % path)
        self.f.seek(self.base + 32 * SECTOR)
        v = self.f.read(SECTOR)
        root, rsize = struct.unpack_from("<II", v, 20)
        self.ents = {}          # name -> (sector, size)
        self.files = {}
        self.dirs = set()
        self._walk(root, rsize, "", 0)

    def _walk(self, sec, size, pre, depth):
        if depth > 32 or size == 0:
            return
        self.f.seek(self.base + sec * SECTOR)
        d = self.f.read(size)
        seen = set()

        def node(o):
            if o in seen or o + 14 > len(d):
                return
            seen.add(o)
            l, r, s, n, a, ln = struct.unpack_from("<HHIIBB", d, o)
            if l == 0xFFFF and r == 0xFFFF:
                return
            name = d[o + 14:o + 14 + ln].decode("latin1")
            if l:
                node(l * 4)
            if a & 0x10:
                self.dirs.add(pre + name)
                self._walk(s, n, pre + name + "/", depth + 1)
            else:
                self.ents[pre + name] = (s, n)
                self.files[pre + name] = n
            if r:
                node(r * 4)
        node(0)

    def read(self, name, off, n):
        s, size = self.ents[name]
        n = max(0, min(n, size - off))
        return os.pread(self.f.fileno(), n, self.base + s * SECTOR + off)     # (threads share the file)


class PackSource:
    kind = "pack"

    def __init__(self, path, z=None):
        self.path = path
        self.z = z or Zstd()
        self.f = open(path, "rb")
        h = self.f.read(HDR)
        if h[:8] != MAGIC:
            raise SystemExit("%s: not a disc pack" % path)
        (self.version, self.chunk, self.index_off, isz, iraw, self.total, nf, nc) = struct.unpack_from(
            "<IIQIIQII", h, 8)
        if self.version != VERSION:
            raise SystemExit("%s: pack version %d (this tool reads %d)" % (path, self.version, VERSION))
        self.f.seek(self.index_off)
        ix = self.z.decompress(self.f.read(isz), iraw)
        nf2, nc2, nsz, _ = struct.unpack_from("<4I", ix, 0)
        assert (nf2, nc2) == (nf, nc)
        fo = 16
        co = fo + 24 * nf
        no = co + 16 * nc
        names = ix[no:no + nsz]
        self.chunks = [struct.unpack_from("<QII", ix, co + 16 * i) for i in range(nc)]
        self.ents = {}
        self.files = {}
        self.all = {}
        self.dirs = set()
        for i in range(nf):
            noff, flags, size, first, _ = struct.unpack_from("<IIQII", ix, fo + 24 * i)
            name = names[noff:names.index(b"\0", noff)].decode("utf-8")
            if flags & FLAG_DIR:
                self.dirs.add(name)
                continue
            self.all[name] = (size, first)
            if not name.startswith(".hulk/"):
                self.files[name] = size

    def chunk_bytes(self, ci, raw_size):
        off, csize, kind = self.chunks[ci]
        if kind == KIND_ZERO:
            return bytes(raw_size)
        b = os.pread(self.f.fileno(), csize, off)
        return b if kind == KIND_RAW else self.z.decompress(b, raw_size)

    def read(self, name, off, n):
        size, first = self.all[name]
        n = max(0, min(n, size - off))
        out = bytearray()
        while n > 0:
            ci, co = divmod(off, self.chunk)
            raw = min(self.chunk, size - ci * self.chunk)
            b = self.chunk_bytes(first + ci, raw)
            take = min(n, raw - co)
            out += b[co:co + take]
            off += take
            n -= take
        return bytes(out)

    def manifest(self):
        return json.loads(self.read(".hulk/pack.json", 0, 1 << 30))


def open_source(path, z=None):
    if os.path.isdir(path):
        return FolderSource(path)
    with open(path, "rb") as f:
        head = f.read(8)
    if head == MAGIC:
        return PackSource(path, z)
    return IsoSource(path)


# ------------------------------------------------------------------------------------------------ build
def plan_chunks(src, chunk):
    """[(name, index in file, offset, size)] in pack order."""
    out = []
    for name in sorted(src.files):
        size = src.files[name]
        for k in range(max(1, (size + chunk - 1) // chunk)):
            out.append((name, k, k * chunk, min(chunk, size - k * chunk)))
    return out


def encode(z, data, level):
    if data.count(0) == len(data):
        return KIND_ZERO, b""
    if level > 3 and len(z.compress(data, 1)) >= len(data) * 0.99:
        return KIND_RAW, data           # (the movies: zstd's fast level already finds nothing to save)
    c = z.compress(data, level)
    if len(c) < len(data) * 0.97:
        return KIND_ZSTD, c
    return KIND_RAW, data


def cmd_build(a):
    z = Zstd()
    src = open_source(a.src, z)
    chunk = a.chunk * 1024
    out = os.path.abspath(a.out)
    if out.startswith(ROOT + os.sep) and not out.startswith(os.path.join(ROOT, "build") + os.sep):
        raise SystemExit("a disc pack is the game: keep it under build/ (never in the tracked tree)")
    replace = {}             # disc name -> (keep bytes, member name, member bytes): the AV1 movies (disc_av1.py)
    extra = {}
    lazy = {}                # .hulk/ name -> (a PackSource, its name, size): members read from another pack
    av1 = None
    texpacks = {}
    if a.av1:
        import disc_av1
        av1 = disc_av1.load_for_pack(a.av1, src)
        for disc_name, ranges in av1["zero"].items():
            replace[disc_name] = ranges
        extra.update(av1["members"])
    elif src.kind == "pack":     # (its AV1 movies: the disc files' replaced ranges are zeros in it already)
        sman = src.manifest()
        if "av1" in sman:
            av1 = {"manifest": sman["av1"]}
            for n, (size, _first) in src.all.items():
                if n.startswith(".hulk/av1/"):
                    lazy[n] = (src, n, size)
    if src.kind == "pack":
        texpacks.update(src.manifest().get("texpacks", {}))
        for n, (size, _first) in src.all.items():
            if n.startswith(".hulk/texpacks/"):
                lazy[n] = (src, n, size)
    for t in a.texpack or []:
        tp = PackSource(t, z)
        name = os.path.basename(t)
        if name.lower().endswith(".hulkpack"):
            name = name[:-9]
        if not name or "/" in name or not any(n.startswith("textures/") for n in tp.files):
            raise SystemExit("%s: not a one-file texture pack (texpack_convert.py bundle)" % t)
        for n in [k for k in lazy if k.startswith(".hulk/texpacks/%s/" % name)]:
            del lazy[n]
        for n, size in tp.files.items():
            lazy[".hulk/texpacks/%s/%s" % (name, n)] = (tp, n, size)
        texpacks[name] = {"source": os.path.basename(t), "files": len(tp.files), "bytes": sum(tp.files.values())}
    t0 = time.time()
    names = sorted(src.files)
    log("disc_pack: %s %s, %d files, %.2f GB; zstd %s level %d, %d KiB chunks, %d jobs" % (
        src.kind, a.src, len(names), sum(src.files.values()) / 1e9, z.version(), a.level, a.chunk, a.jobs))
    # every disc file's digest (of the bytes the game reads from the pack)
    hashes = {}

    class Reader:
        """the pack's view of one disc file: the source, with the AV1 movies' replaced ranges zeroed"""
        def read(self, name, off, n):
            b = src.read(name, off, n)
            for lo, hi in replace.get(name, ()):
                s, e = max(lo, off), min(hi, off + len(b))
                if s < e:
                    b = b[:s - off] + bytes(e - s) + b[e - off:]
            return b
    rd = Reader()
    members = {}             # .hulk/ name -> bytes
    for name, data in extra.items():
        members[name] = data

    class Both:
        files = dict(src.files)

        def read(self, name, off, n):
            if name in members:
                return members[name][off:off + n]
            if name in lazy:
                p, inner, _size = lazy[name]
                return p.read(inner, off, n)
            return rd.read(name, off, n)
    both = Both()
    manifest = {"tool": "disc_pack.py %d" % VERSION, "source": src.kind, "zstd": z.version(), "level": a.level,
                "chunk": chunk, "files": {}}
    if av1:
        manifest["av1"] = av1["manifest"]
    if texpacks:
        manifest["texpacks"] = texpacks
    # the manifest is written last (it holds the digests), so it needs its own size up front: two passes over a
    # placeholder are avoided by writing it as the last file of the order (its name sorts after the disc's)
    for name, data in members.items():
        both.files[name] = len(data)
    for name, (_p, _inner, size) in lazy.items():
        both.files[name] = size
    plan = plan_chunks(both, chunk)
    tmp = out + ".part"
    total = 0
    with open(tmp, "wb") as f:
        f.write(bytes(HDR))
        pos = HDR
        chunks = []
        first = {}
        hstate = {}
        last = time.time()

        def job(item):
            name, k, off, n = item
            data = both.read(name, off, n)
            if len(data) != n:
                raise SystemExit("%s: short read at %d" % (name, off))
            return item, data, encode(z, data, a.level)
        with concurrent.futures.ThreadPoolExecutor(a.jobs) as ex:
            window = []
            it = iter(plan)
            for item in it:
                window.append(ex.submit(job, item))
                if len(window) < a.jobs * 4:
                    continue
                pos = _drain(window.pop(0), f, pos, chunks, first, hstate)
                if time.time() - last > 10:
                    last = time.time()
                    log("  %d / %d chunks, %.0f s" % (len(chunks), len(plan), last - t0))
            while window:
                pos = _drain(window.pop(0), f, pos, chunks, first, hstate)
        for name in names:
            hashes[name] = hstate[name].hexdigest()
        manifest["files"] = {n: [src.files[n], hashes[n]] for n in names}
        manifest["members"] = {n: [len(d), hashlib.sha256(d).hexdigest()] for n, d in members.items()}
        manifest["members"].update({n: [v[2], hstate[n].hexdigest()] for n, v in lazy.items()})
        mj = json.dumps(manifest, indent=1, sort_keys=True).encode()
        mname = ".hulk/pack.json"
        first[mname] = len(chunks)
        for k in range(max(1, (len(mj) + chunk - 1) // chunk)):
            data = mj[k * chunk:(k + 1) * chunk]
            kind, stored = encode(z, data, a.level)
            f.write(stored)
            chunks.append((pos, len(stored), kind))
            pos += len(stored)
        sizes = dict(both.files)
        sizes[mname] = len(mj)
        dirs = set(d for d in getattr(src, "dirs", ()) if not d.startswith(".hulk"))
        allnames = sorted(set(sizes) | dirs)
        nb = bytearray()
        noffs = {}
        for n in allnames:
            noffs[n] = len(nb)
            nb += n.encode("utf-8") + b"\0"
        ix = bytearray(struct.pack("<4I", len(allnames), len(chunks), len(nb), 0))
        for n in allnames:
            if n in dirs:
                ix += struct.pack("<IIQII", noffs[n], FLAG_DIR, 0, 0, 0)
            else:
                ix += struct.pack("<IIQII", noffs[n], FLAG_OWN if n.startswith(".hulk/") else 0, sizes[n], first[n], 0)
        for c in chunks:
            ix += struct.pack("<QII", *c)
        ix += nb
        zix = z.compress(bytes(ix), 19)
        index_off = pos
        f.write(zix)
        total = sum(src.files.values())
        f.seek(0)
        f.write(MAGIC + struct.pack("<IIQIIQII", VERSION, chunk, index_off, len(zix), len(ix), total, len(allnames),
                                    len(chunks)))
    os.replace(tmp, out)
    size = os.path.getsize(out)
    kinds = [c[2] for c in chunks]
    log("disc_pack: %s %.3f GB (%.1f%% of %.3f GB) in %.0f s; chunks zstd %d, raw %d, zero %d" % (
        out, size / 1e9, 100.0 * size / max(1, total), total / 1e9, time.time() - t0, kinds.count(KIND_ZSTD),
        kinds.count(KIND_RAW), kinds.count(KIND_ZERO)))


def _drain(fut, f, pos, chunks, first, hstate):
    (name, k, off, n), data, (kind, stored) = fut.result()
    if k == 0:
        first[name] = len(chunks)
        hstate[name] = hashlib.sha256()
    hstate[name].update(data)
    f.write(stored)
    chunks.append((pos, len(stored), kind))
    return pos + len(stored)


# ------------------------------------------------------------------------------------------------ verify
def cmd_verify(a):
    z = Zstd()
    p = PackSource(a.pack, z)
    man = p.manifest()
    src = open_source(a.source, z) if a.source else None
    t0 = time.time()
    bad = []
    if set(p.files) != set(man["files"]):
        bad.append("the pack's files differ from its manifest's")
    if src:
        want = set(src.files)
        if want != set(p.files):
            bad.append("files only in the source: %s; only in the pack: %s" % (
                sorted(want - set(p.files))[:10], sorted(set(p.files) - want)[:10]))
        if src.dirs != p.dirs:
            bad.append("folders only in the source: %s; only in the pack: %s" % (
                sorted(src.dirs - p.dirs)[:10], sorted(p.dirs - src.dirs)[:10]))
    replaced = {n: r for n, r in man.get("av1", {}).get("zero", {}).items()}
    nbytes = 0
    for name in sorted(p.files):
        size, digest = man["files"][name]
        if p.files[name] != size:
            bad.append("%s: size %d, manifest %d" % (name, p.files[name], size))
            continue
        h = hashlib.sha256()
        hs = hashlib.sha256() if src else None
        same_src = True
        step = 8 << 20
        for off in range(0, max(size, 1), step):
            b = p.read(name, off, step)
            h.update(b)
            if src:
                s = src.read(name, off, step)
                for lo, hi in replaced.get(name, ()):
                    lo2, hi2 = max(lo, off), min(hi, off + len(s))
                    if lo2 < hi2:
                        if any(b[lo2 - off:hi2 - off]):
                            same_src = False
                        s = s[:lo2 - off] + bytes(hi2 - lo2) + s[hi2 - off:]
                if s != b:
                    same_src = False
        nbytes += size
        if h.hexdigest() != digest:
            bad.append("%s: sha256 differs from the manifest's" % name)
        if src and not same_src:
            bad.append("%s: bytes differ from the source" % name)
    for name, (size, digest) in man.get("members", {}).items():
        if name not in p.all or p.all[name][0] != size:
            bad.append("%s: missing, or not its manifest's size" % name)
            continue
        h = hashlib.sha256()
        for off in range(0, max(size, 1), 8 << 20):
            h.update(p.read(name, off, 8 << 20))
        if h.hexdigest() != digest:
            bad.append("%s: sha256 differs" % name)
    tps = man.get("texpacks", {})
    for t in a.texpack or []:           # (a texture pack it carries, byte for byte against its file)
        tp = PackSource(t, z)
        name = os.path.basename(t)[:-9] if t.lower().endswith(".hulkpack") else os.path.basename(t)
        if name not in tps:
            bad.append("%s: the pack carries no texture pack %s" % (t, name))
            continue
        have = {n[len(".hulk/texpacks/%s/" % name):]: v[0] for n, v in p.all.items()
                if n.startswith(".hulk/texpacks/%s/" % name)}
        if have != tp.files:
            bad.append("%s: its files differ from the pack's .hulk/texpacks/%s/" % (t, name))
            continue
        for n, size in tp.files.items():
            if tp.read(n, 0, size) != p.read(".hulk/texpacks/%s/%s" % (name, n), 0, size):
                bad.append("%s: %s differs" % (t, n))
    for b in bad:
        log("FAIL " + b)
    nrep = sum(len(r) for r in replaced.values())
    log("verify %s: %d files, %.2f GB, %s%s%s in %.0f s: %s" % (
        a.pack, len(p.files), nbytes / 1e9, "against %s %s" % (src.kind, a.source) if src else "against its manifest",
        ", %d movies' pictures replaced by AV1 (their headers kept, the rest zero)" % nrep if nrep else "",
        "".join(", texture pack %s (%d files)" % (k, v["files"]) for k, v in sorted(tps.items())),
        time.time() - t0, "FAIL" if bad else "ok"))
    return 1 if bad else 0


# ------------------------------------------------------------------------------------------------ measure
def cmd_measure(a):
    """Compressed size per level and chunk size, on every --stride'th chunk of each file (the estimate scales)."""
    z = Zstd()
    src = open_source(a.src, z)
    levels = [int(x) for x in a.levels.split(",")]
    sizes = [int(x) for x in a.chunks.split(",")]
    total = sum(src.files.values())
    rows = []
    for ck in sizes:
        chunk = ck * 1024
        plan = plan_chunks(src, chunk)
        sample = plan[::a.stride]
        raw = sum(p[3] for p in sample)
        for lv in levels:
            t = time.time()

            def job(item):
                name, k, off, n = item
                data = src.read(name, off, n)
                kind, st = encode(z, data, lv)
                td = time.perf_counter()
                if kind == KIND_ZSTD:
                    z.decompress(st, n)
                return len(st), (time.perf_counter() - td) if kind == KIND_ZSTD else 0.0, kind
            with concurrent.futures.ThreadPoolExecutor(a.jobs) as ex:
                res = list(ex.map(job, sample))
            if a.by_type:
                by = {}
                for p, r in zip(sample, res):
                    ext = p[0]
                    v = by.setdefault(ext, [0, 0])
                    v[0] += p[3]
                    v[1] += r[0]
                for ext, (rw, st) in sorted(by.items(), key=lambda x: -x[1][0]):
                    log("    %-16s %5.1f%% of %.0f MB sampled" % (ext, 100.0 * st / rw, rw / 1e6))
            stored = sum(r[0] for r in res)
            dec = sum(r[1] for r in res)
            zbytes = sum(p[3] for p, r in zip(sample, res) if r[2] == KIND_ZSTD)
            rows.append((ck, lv, stored / raw, time.time() - t, zbytes / max(dec, 1e-9) / 1e6))
            log("chunk %5d KiB level %2d: %.1f%% -> ~%.3f GB of %.3f GB; compress %.0f s (sample %.2f GB, %d jobs); "
                "decompress %.0f MB/s (one thread)" % (ck, lv, 100 * stored / raw, total * stored / raw / 1e9,
                                                      total / 1e9, time.time() - t, raw / 1e9, a.jobs,
                                                      zbytes / max(dec, 1e-9) / 1e6))


# ------------------------------------------------------------------------------------------------ ls / cat
def cmd_ls(a):
    s = open_source(a.path)
    names = s.all if isinstance(s, PackSource) and a.all else s.files
    for n in sorted(names):
        v = names[n]
        print("%12d  %s" % (v[0] if isinstance(v, tuple) else v, n))


def cmd_cat(a):
    s = open_source(a.path)
    size = s.all[a.name][0] if isinstance(s, PackSource) else s.files[a.name]
    out = sys.stdout.buffer
    for off in range(0, size, 8 << 20):
        out.write(s.read(a.name, off, 8 << 20))


# ------------------------------------------------------------------------------------------------ zstd's sources
def zstd_src():
    """build/third_party/src/zstd (lib/ of the pinned release), fetched on first use; returns its lib/ directory."""
    name, repo, ref, want = ZSTD_PIN
    dest = os.path.join(TP, "src", name)
    stamp = os.path.join(dest, ".pinned")
    if os.path.exists(stamp) and open(stamp).read().strip() == "%s %s" % (ref, want):
        return os.path.join(dest, "lib")
    dl = os.path.join(TP, "dl")
    os.makedirs(dl, exist_ok=True)
    path = os.path.join(dl, "%s-%s.tar.gz" % (name, ref))
    if not os.path.exists(path):
        log("download zstd %s" % ref)
        with urllib.request.urlopen("https://codeload.github.com/%s/tar.gz/%s" % (repo, ref), timeout=600) as r, \
                open(path + ".part", "wb") as f:
            shutil.copyfileobj(r, f)
        os.replace(path + ".part", path)
    h = hashlib.sha256(open(path, "rb").read()).hexdigest()
    if h != want:
        raise SystemExit("%s: sha256 %s, pinned %s: check ZSTD_PIN" % (path, h, want))
    if os.path.exists(dest):
        shutil.rmtree(dest)
    os.makedirs(dest)
    with tarfile.open(path) as t:
        members = []
        for m in t.getmembers():
            parts = m.name.split("/", 1)
            if len(parts) < 2 or not (parts[1].startswith("lib/") or parts[1] in ("LICENSE", "COPYING")):
                continue
            if m.issym() or m.islnk() or ".." in parts[1].split("/"):
                continue
            m.name = parts[1]
            members.append(m)
        t.extractall(dest, members=members, filter="data")
    open(stamp, "w").write("%s %s\n" % (ref, want))
    return os.path.join(dest, "lib")


# the runners' zstd decompressor: one C file (run/zstd_dec.c includes zstd's decompression sources) with these flags
def zstd_flags():
    return ["-I" + zstd_src(), "-DZSTD_DISABLE_ASM=1", "-DZSTD_LEGACY_SUPPORT=0", "-DZSTD_NO_TRACE=1",
            "-DDEBUGLEVEL=0", "-DZSTD_MULTITHREAD=0"]


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("build")
    c.add_argument("src")
    c.add_argument("out")
    c.add_argument("--level", type=int, default=19)
    c.add_argument("--chunk", type=int, default=256, help="KiB of a file per chunk")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--av1", help="the AV1 movies (a tools/disc_av1.py encode directory)")
    c.add_argument("--texpack", action="append", help="a one-file texture pack (.hulkpack) the pack carries (wapk1)")
    c = sp.add_parser("verify")
    c.add_argument("pack")
    c.add_argument("--source")
    c.add_argument("--texpack", action="append", help="check a texture pack it carries against this .hulkpack")
    c = sp.add_parser("measure")
    c.add_argument("src")
    c.add_argument("--levels", default="3,9,19")
    c.add_argument("--chunks", default="64,256,1024")
    c.add_argument("--stride", type=int, default=8)
    c.add_argument("--by-type", action="store_true", help="the ratio of each file type (by extension)")
    c.add_argument("--jobs", type=int, default=2)
    c = sp.add_parser("ls")
    c.add_argument("path")
    c.add_argument("--all", action="store_true", help="a pack's own .hulk/ files too")
    c = sp.add_parser("cat")
    c.add_argument("path")
    c.add_argument("name")
    sp.add_parser("fetch-zstd")
    a = ap.parse_args(argv)
    if a.cmd == "fetch-zstd":
        log(zstd_src())
        return 0
    return {"build": cmd_build, "verify": cmd_verify, "measure": cmd_measure, "ls": cmd_ls, "cat": cmd_cat}[a.cmd](a) or 0


if __name__ == "__main__":
    sys.exit(main())
