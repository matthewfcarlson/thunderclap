#!/usr/bin/env python3
"""Accesses that reach past the end of a data item (docs/data.md; scan1, 2026-11-13).

The 32-bit XBE lays its data items out back to back, so `DAT_x + k` past the end of item x reads whatever item follows
it there (linux1's FUN_00277190 read the terminator of "D:" as `DAT_0042b50c + 2`, a byte of the next item,
s_empty_0042b50e). verify_relocs can't see it: the address is right. The native builds place each item on its own, so
the same expression reads a stray byte. This scan finds them in the compiler's output, not the source text: every DIR32
relocation of a merged-tree MSVC object that names a data item (`_DAT_x`, `?DAT_x@@...`) carries the constant offset as
its addend, and the instruction holding it gives the access width. An access [x + k, x + k + width) must lie inside the
item that config/data.json starts at x (its `size`; the `pad` after it is not emitted by data_gen).

Classes of a hit (`kind`):
  over      a load / store of `width` bytes at x + k ends past the item (the FUN_00277190 shape)
  pad       ... ends inside the item's alignment padding (zero in the XBE, not emitted natively)
  addr      an address x + k (lea, push imm, cmp, a pointer initializer) farther past the end than `end` allows
  end       an address one past the end, or past it by less than min(32, size) (a loop's end pointer: MSVC compares
            or starts a reverse walk at one past the end plus the offset of the field the loop reads; informational,
            `--all`). Farther than that (CCharacterTemplateManager's `DAT_0048f6d0 + 3` over a 4-byte item) is `addr`.
  indexed   a register-indexed access whose constant part already starts past the end (HalRadicalAdpcm's step table
            read as `((int*)&DAT_0042ac18 + 16)[i]`, the next item)
  before    a constant offset below the item's start (k < 0)
  negidx    a register-indexed access with a constant part below the start (`--all`: the displacement of an index
            known to be >= k, `token2string[token - 257]`; a pointer walk, `[esi - 4]`)

    python tools/data_overreach.py scan [--compile] [--jobs N] [--json OUT] [--all] [TU.cpp ...]

Without TUs: every tree TU whose MSVC object build_tree's cache holds (`--compile` compiles the others: MSVC through
wibo, a queue job, docs/compute.md). Exit 1 when a hit of a reported class is found.
"""
import argparse
import bisect
import json
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

DATA_JSON = os.path.join(ROOT, "config/data.json")
TREE_DIRS = ("src/game", "src/engine", "src/platform/xbox")
SYM_RE = re.compile(r"(?<![0-9A-Za-z])_?DAT_([0-9a-fA-F]{8})(?![0-9A-Za-z])")
BLOCK_RE = re.compile(r"^// (0x[0-9a-f]{8}) (\S+) \((\d+) B\): (\w+)", re.M)
PIN_RE = re.compile(r"^// sym: (\S+)", re.M)
REPORTED = ("over", "pad", "addr", "before", "indexed")
IMAGE_LO, IMAGE_HI = 0x00010000, 0x01000000


class Items:
    """config/data.json's items by address (addr, size, pad, name, kind)."""

    def __init__(self, items):
        self.items = sorted(items, key=lambda it: it["addr"])
        self.addrs = [it["addr"] for it in self.items]

    @classmethod
    def load(cls, path=DATA_JSON):
        out = []
        with open(path) as f:
            for line in f:
                line = line.strip().rstrip(",")
                if not line.startswith('{"addr"'):
                    continue
                d = json.loads(line)
                out.append({"addr": int(d["addr"], 16), "size": d["size"], "pad": d.get("pad", 0),
                            "name": d.get("name", ""), "kind": d.get("kind", "")})
        return cls(out)

    def at(self, a):
        """The item holding address a (its size plus pad), or None."""
        j = bisect.bisect_right(self.addrs, a) - 1
        if j >= 0 and a < self.addrs[j] + self.items[j]["size"] + self.items[j]["pad"]:
            return self.items[j]
        return None


def classify(items, sym_addr, addend, width, indexed=False):
    """The hit of one access (None when it stays inside its item): DAT_<sym_addr> + addend, `width` bytes (0 for an
    address that is only formed)."""
    base = items.at(sym_addr)
    if base is None:
        return None                          # not an item (a constant spelled DAT_, a library address)
    off = sym_addr - base["addr"] + addend   # DAT_x may name an address inside a folded item
    size = base["size"]
    target = base["addr"] + off
    if indexed:
        if 0 <= off < size:
            return None
        kind = "indexed" if off >= size else "negidx"
    elif off < 0:
        kind = "before"
    elif width == 0:
        if off < size:
            return None
        kind = "end" if off < size + min(32, size) else "addr"
    else:
        if off + width <= size:
            return None
        kind = "pad" if off + width <= size + base["pad"] else "over"
    hit = items.at(target)
    return {"kind": kind, "item": base["name"], "item_addr": "0x%08x" % base["addr"], "item_size": size,
            "item_pad": base["pad"], "offset": off, "width": width, "target": "0x%08x" % target,
            "target_item": hit["name"] if hit else None,
            "target_offset": target - hit["addr"] if hit else None}


_MD = None


def _md():
    global _MD
    if _MD is None:
        import capstone
        _MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        _MD.detail = True
    return _MD


def access(insn, field_off):
    """(width, indexed) of the instruction operand whose 4-byte field starts at field_off (relative to the
    instruction); width 0 when the field is an address that is only formed (lea, an immediate)."""
    import capstone.x86 as X
    if insn.imm_offset == field_off and insn.disp_offset != field_off:
        return 0, False
    for op in insn.operands:
        if op.type == X.X86_OP_MEM:
            idx = op.mem.base != 0 or op.mem.index != 0
            if insn.mnemonic == "lea":
                return 0, idx
            return op.size, idx
    return 0, False


STRING_OP = re.compile(r"^(rep )?(movs|stos)([bwd])$")


def block_width(code, insn, limit=8):
    """A block copy's extent from an address loaded into esi / edi (MSVC's inline memcpy / memset / struct copy:
    `mov esi, offset DAT_x; mov ecx, N; rep movsd; movsw; movsb`): the bytes it reads (esi) or writes (edi), else 0."""
    if insn.mnemonic != "mov" or insn.op_str[:4] not in ("esi,", "edi,"):
        return 0
    reg = insn.op_str[:3]
    ecx, total, seen = None, 0, 0
    nxt = insn.address + insn.size
    for i in _md().disasm(code[nxt:nxt + 64], nxt):
        seen += 1
        if seen > limit:
            break
        m = STRING_OP.match(i.mnemonic)
        if i.mnemonic == "mov" and i.op_str.startswith("ecx, "):
            try:
                ecx = int(i.op_str[5:], 0)
            except ValueError:
                ecx = None
            continue
        if m:
            if m.group(2) == "stos" and reg != "edi":
                break
            n = {"b": 1, "w": 2, "d": 4}[m.group(3)]
            if m.group(1):
                if ecx is None:
                    return 0
                total += ecx * n
            else:
                total += n
            continue
        if total or i.mnemonic in ("call", "ret") or i.mnemonic.startswith("j"):
            break
        if i.op_str.split(",")[0].strip() == reg:
            break
    return total


def decode_field(code, va, starts=()):
    """The instruction of `code` whose displacement or immediate field starts at offset va: linear decode from the
    nearest start before it (a function symbol), else the longest candidate 10..1 bytes back (ambiguous: `or eax, imm`
    sits inside `mov cl, [imm]`)."""
    md = _md()
    s = max((x for x in starts if x <= va), default=None)
    if s is not None:
        for i in md.disasm(code[s:va + 16], s):
            if i.address > va:
                break
            if i.address <= va < i.address + i.size:
                f = va - i.address
                if f in (i.disp_offset, i.imm_offset) and (i.disp_offset or i.imm_offset):
                    return i, f
                break
    for back in range(10, 0, -1):
        st = va - back
        if st < 0:
            continue
        try:
            i = next(md.disasm(code[st:st + 16], st))
        except StopIteration:
            continue
        if i.address + i.size > va + 3 and back in (i.disp_offset, i.imm_offset):
            return i, back
    return None, None


def tu_blocks(path):
    """{symbol: (block address, name, status)} of a tree TU's `// sym:` pins."""
    text = open(path, errors="replace").read()
    out = {}
    for m in BLOCK_RE.finditer(text):
        p = PIN_RE.search(text, m.end(), m.end() + 400)
        if p:
            out[p.group(1)] = (m.group(1), m.group(2), m.group(4))
    return out


def object_hits(obj, items, blocks=None, kinds=REPORTED):
    """The hits of one MSVC object."""
    from compare import Coff
    c = Coff(obj)
    blocks = blocks or {}
    out = []
    for secnum, (sname, raw, relocs) in enumerate(c.sections, 1):
        code = sname.startswith(".text")
        funcs = sorted((s[1], s[0]) for s in c.symbols if s[2] == secnum and (s[3] == 0x20 or not code))
        starts = [v for v, _ in funcs]
        for va, si, typ in relocs:
            if typ != 6 or len(raw) < va + 4:
                continue
            sym = c.by_index.get(si)
            m = SYM_RE.search(sym[0]) if sym else None
            if not m:
                continue
            addend, = struct.unpack_from("<i", raw, va)
            if not code:
                width, indexed, text = 0, False, "data word"
            else:
                insn, f = decode_field(raw, va, starts)
                if insn is None:
                    width, indexed, text = 0, False, "?"
                else:
                    width, indexed = access(insn, f)
                    if width == 0 and not indexed:
                        width = block_width(raw, insn)
                    text = "%s %s" % (insn.mnemonic, insn.op_str)
            h = classify(items, int(m.group(1), 16), addend, width, indexed)
            if not h or h["kind"] not in kinds:
                continue
            j = bisect.bisect_right(starts, va) - 1
            fn = funcs[j][1] if j >= 0 else sname
            blk = blocks.get(fn)
            h.update({"section": sname, "symbol": fn, "insn": text,
                      "block": blk[0] if blk else None, "block_name": blk[1] if blk else None,
                      "status": blk[2] if blk else None})
            out.append(h)
    return out


def tree_tus(paths=None):
    if paths:
        return [os.path.abspath(p) for p in paths]
    tus = []
    for d in TREE_DIRS:
        for dp, dns, fns in os.walk(os.path.join(ROOT, d)):
            tus += [os.path.join(dp, f) for f in fns if f.endswith(".cpp")]
    return sorted(tus)


def scan(tus, compile_missing=False, jobs=4, kinds=REPORTED):
    import build_tree
    import tree_tu
    items = Items.load()
    objs = {}

    def obj_of(p):
        o = os.path.join(build_tree.OBJ_CACHE, tree_tu.object_key(p) + ".obj")
        if os.path.exists(o):
            return o
        if compile_missing:
            o, err = tree_tu.compile_tu(p)
            return o
        return None

    if compile_missing:
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(jobs) as ex:
            for p, o in zip(tus, ex.map(obj_of, tus)):
                objs[p] = o
    else:
        objs = {p: obj_of(p) for p in tus}
    hits, missing = [], []
    for p in tus:
        if not objs[p]:
            missing.append(os.path.relpath(p, ROOT))
            continue
        for h in object_hits(objs[p], items, tu_blocks(p), kinds):
            h["tu"] = os.path.relpath(p, ROOT)
            hits.append(h)
    return hits, missing


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("scan")
    s.add_argument("tus", nargs="*")
    s.add_argument("--compile", action="store_true", help="compile TUs without a cached object (MSVC: a queue job)")
    s.add_argument("--jobs", type=int, default=4)
    s.add_argument("--all", action="store_true", help="also the informational classes (end, negidx)")
    s.add_argument("--json", help="write {hits, missing} here")
    a = ap.parse_args(argv)
    kinds = REPORTED + (("end", "negidx") if a.all else ())
    hits, missing = scan(tree_tus(a.tus), a.compile, a.jobs, kinds)
    if a.json:
        with open(a.json, "w") as f:
            json.dump({"hits": hits, "missing": missing}, f, indent=1)
    for h in hits:
        print("%-7s %s %s+%d w%d (item %d B%s) -> %s%s  %s %s [%s]  %s" % (
            h["kind"], h["tu"], h["item"], h["offset"], h["width"], h["item_size"],
            "+%d pad" % h["item_pad"] if h["item_pad"] else "", h["target_item"],
            "+%d" % h["target_offset"] if h["target_offset"] else "", h["block"], h["block_name"] or h["symbol"],
            h["status"], h["insn"]))
    by = {}
    for h in hits:
        by[h["kind"]] = by.get(h["kind"], 0) + 1
    print("%d hits %s; %d TUs without an object%s" % (len(hits), json.dumps(by, sort_keys=True), len(missing),
                                                     " (--compile)" if missing else ""))
    return 1 if any(h["kind"] in REPORTED for h in hits) else 0


if __name__ == "__main__":
    sys.exit(main())
