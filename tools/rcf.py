#!/usr/bin/env python3
"""List / extract / (round-trip check) radcore "ATG CORE CEMENT LIBRARY" (.rcf) archives.

Layout is documented in docs/formats/rcf.md. The header and directory layout
is confirmed from the first bytes of misc.rcf; the name-table record layout is
parsed heuristically (see parse_names) until verified against real archives.

  rcf.py list <file.rcf>
  rcf.py extract <file.rcf> <outdir>
  rcf.py roundtrip <file.rcf>     # parse -> rebuild directory bytes -> compare
"""
import argparse, os, re, struct, sys

MAGIC = b"ATG CORE CEMENT LIBRARY"
HDR_SIZE = 0x3C
ALIGN = 0x800


class RcfError(Exception):
    pass


class Entry:
    __slots__ = ("hash", "offset", "size", "name")

    def __init__(self, h, off, size, name=None):
        self.hash, self.offset, self.size, self.name = h, off, size, name


def parse_names(data, names_off, names_size, entries):
    """Return {entry index: name}.

    Name records are assumed to be a few u32 fields followed by an ASCII path.
    We pull every path-like string out of the table in order, then join to the
    directory by (offset,size) if the record's leading u32s contain such a
    pair, else by order.
    """
    blob = data[names_off:names_off + names_size]
    found = []
    for m in re.finditer(rb"[\x20-\x7e]{3,}", blob):
        s = m.group().decode("ascii")
        if "." in s or "/" in s or "\\" in s:
            found.append((m.start(), s))
    by_pair = {(e.offset, e.size): i for i, e in enumerate(entries)}
    out = {}
    for order, (pos, s) in enumerate(found):
        idx = None
        head = blob[max(0, pos - 16):pos]
        words = struct.unpack("<%dI" % (len(head) // 4), head[len(head) % 4:]) if len(head) >= 4 else ()
        for a, b in zip(words, words[1:]):
            if (a, b) in by_pair:
                idx = by_pair[(a, b)]
                break
        if idx is None and order < len(entries):
            idx = order
        if idx is not None and idx not in out:
            out[idx] = s
    return out


def parse(path):
    with open(path, "rb") as f:
        data = f.read()
    if not data.startswith(MAGIC):
        raise RcfError("bad magic")
    ver, dir_off, dir_size, names_off, names_size, _res, count = struct.unpack_from("<7I", data, 0x20)
    if dir_size != count * 12:
        raise RcfError(f"dir size {dir_size:#x} != 12*{count}")
    entries = [Entry(*struct.unpack_from("<3I", data, dir_off + 12 * i)) for i in range(count)]
    for i, n in parse_names(data, names_off, names_size, entries).items():
        entries[i].name = n
    return data, dict(version=ver, dir_off=dir_off, dir_size=dir_size,
                      names_off=names_off, names_size=names_size, count=count), entries


def entry_path(e):
    n = e.name or f"_unnamed/{e.hash:08x}.bin"
    parts = [p for p in re.split(r"[\\/]+", n) if p and p not in (".", "..")]
    return os.path.join(*parts) if parts else f"_unnamed/{e.hash:08x}.bin"


def cmd_list(a):
    data, h, es = parse(a.file)
    for e in es:
        print(f"{e.hash:08x} {e.offset:#010x} {e.size:>10} {e.name or '?'}")
    print(f"# {h['count']} files, {sum(1 for e in es if e.name)} named", file=sys.stderr)


def cmd_extract(a):
    data, h, es = parse(a.file)
    root = os.path.realpath(a.outdir)
    for e in es:
        if e.offset + e.size > len(data):
            raise RcfError(f"entry {e.hash:08x} runs past EOF")
        dst = os.path.realpath(os.path.join(root, entry_path(e)))
        if not dst.startswith(root + os.sep):
            raise RcfError(f"unsafe path {e.name!r}")
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as f:
            f.write(data[e.offset:e.offset + e.size])
    print(f"extracted {len(es)} files to {a.outdir}")


def cmd_roundtrip(a):
    data, h, es = parse(a.file)
    rebuilt = b"".join(struct.pack("<3I", e.hash, e.offset, e.size) for e in es)
    ok = rebuilt == data[h["dir_off"]:h["dir_off"] + h["dir_size"]]
    print("directory round-trip:", "OK" if ok else "MISMATCH")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for n, fn in (("list", cmd_list), ("extract", cmd_extract), ("roundtrip", cmd_roundtrip)):
        p = sub.add_parser(n)
        p.add_argument("file")
        if n == "extract":
            p.add_argument("outdir")
        p.set_defaults(fn=fn)
    a = ap.parse_args()
    try:
        sys.exit(a.fn(a) or 0)
    except RcfError as e:
        sys.exit(f"rcf: {e}")


if __name__ == "__main__":
    main()
