#!/usr/bin/env python3
"""Code hashes of equivalent blocks (docs/merge-once.md "Code hashes").

An `equivalent` block of the merged tree records a hash of the code that was proven next to its pinned symbol:

  // sym: <pin> @<12 hex> @w<12 hex>

`@<hex>` is the function's code in the TU's MSVC 7.1 object (tree_tu's compile), `@w<hex>` its code in the clang
object `equiv.py TU ADDR --wine` checks (equiv.compile_native: i686-pc-windows-msvc -O0, the SSE build's IR passes, an
empty x87-keep list). `tools/tree_tu.py check/verify` recompute them: a block whose code still hashes to its recorded
values was proven as it stands (no new equiv.py run); one that doesn't is `code_changed` and must be re-proven
(`tree_tu.py hash --proven`, which records new values only from passing equiv.py results).

The hash (function_hash) is sha256 over a canonical form of the function and everything of the object its proof runs
in place, truncated to 48 bits:

  * nodes: the function (node 0), then every region of the object it reaches through relocations that equiv.py runs or
    reads in place, in the order first reached (relocations in offset order): functions defined in the object that are
    not other blocks of the TU (inline members, `$L` unwind funclets, `__ehhandler$`), their EH tables and other data
    the object defines (`$SG` strings, static tables, `.bss` items: their size). A node is its section's name stem, its
    bytes (code: trailing int3/nop padding stripped, as build_tree.same_code; .bss: the length) and per relocation its
    offset, type and target key. Section-relative relocations (jump tables, clang's local labels) have their addend
    taken out of the bytes and resolved to (node, offset), so a neighbouring function's size doesn't leak in.
  * target keys, first rule that applies:
      - the node itself / an offset inside it: ("self", offset)
      - another block of the TU (its check record's symbol): ("addr", its address) -- equiv.py binds those by address;
      - a constant named by its content: `__real@`, `__xmm@`, `??_C@` (length + CRC + text): ("const", name);
      - an address in the symbol's own name (its leaf: FUN_/LAB_/DAT_/PTR_/hulk_at_/vtbl_/rttiTD_<8 hex>, or the
        suffix convention `Name_00xxxxxx` on a call/jump into the XBE's .text, tools/addr_names.py): ("addr", A);
      - a name an `// equiv-map:` line of the block binds: ("addr", A);
      - vftables and RTTI (`??_7`, `??_R`): ("name", name);
      - defined in the object: ("node", index) (its content is hashed as a node);
      - anything else (an external name with no address): ("name", name).
    Compiler-local names (`$L<n>`, `$T<n>`, `$SG<n>`, `__ehfuncinfo$...`) never enter the hash: they are nodes or
    offsets. So a rename that keeps every target's address, `$L`/`$T` renumbering, and edits elsewhere in the TU leave
    it unchanged; changed bytes, relocation positions or kinds, a call to another address, a changed inline callee,
    EH table or static datum change it. Where a rule can't tell, the key is the name (a rename counts as a change).
  * the block's equiv directives (`equiv-map`/`equiv-conv`/`equiv-name` lines, whitespace-normalised; the
    `+0xNN taken`/`not taken` claims of `equiv-dead`): they are part of what was proven.

This is strictly stronger than build_tree.same_code (which compares bytes and relocation offsets/types, and targets
only where both carry an address or are constants).
"""
import hashlib
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

VERSION = b"hulkcode1"
REL32, DIR32 = 0x14, 0x06
HEXLEN = 12
PLACEHOLDER_LEAF = re.compile(r"(?:FUN|LAB|DAT|PTR|hulk_at|vtbl|rttiTD)_([0-9a-fA-F]{8})")
CONSTS = ("__real@", "__xmm@", "__ymm@", "??_C@")
BY_NAME = ("??_7", "??_R")
SKIP_SECTIONS = (".debug", ".drectve", ".llvm_addrsig", ".llvm.", ".pdata", ".xdata$unwind")
DEAD_CLAIM = re.compile(r"\+0x[0-9a-fA-F]+ (?:not )?taken")
MAP_LINE = re.compile(r"^\s*//\s*equiv-map:\s*(\S+)\s*=\s*(0x[0-9a-fA-F]+)")

_TEXT = []


def xbe_text():
    """(lo, hi) of the XBE's .text, or None without the XBE."""
    if not _TEXT:
        try:
            import compare
            from xbe import Xbe
            x = Xbe(compare.XBE_PATH)
            s = next(s for s in x.sections if s.name == ".text")
            _TEXT.append((s.va, s.va + s.vsize))
        except Exception:       # noqa: BLE001 - no XBE: the suffix rule is off (names stay names: stricter)
            _TEXT.append(None)
    return _TEXT[0]


def name_address(name, typ):
    """The address a symbol's own name carries (see the module doc), or None."""
    import addr_names
    leaf = addr_names.leaf_of_symbol(name)
    if not leaf:
        return None
    m = PLACEHOLDER_LEAF.fullmatch(leaf)
    if m:
        return int(m.group(1), 16)
    if typ == REL32:
        a = addr_names.suffix_address(leaf)
        t = xbe_text()
        if a is not None and t and t[0] <= a < t[1]:
            return a
    return None


def directive_lines(lines):
    """The block's equiv directives in the hash's normal form."""
    out = []
    for l in lines:
        m = re.match(r"^\s*//\s*equiv-(map|conv|dead|name):(.*)$", l)
        if not m:
            continue
        kind, rest = m.group(1), m.group(2)
        if kind == "dead":
            out.append("dead " + " ".join(DEAD_CLAIM.findall(rest)))
        else:
            out.append(kind + " " + " ".join(rest.split()))
    return sorted(out)


def equiv_map(lines):
    return {m.group(1): int(m.group(2), 16) for m in (MAP_LINE.match(l) for l in lines) if m}


class _Obj:
    """What the hash needs of a COFF object (compare.Coff) beyond its sections and symbols: section sizes (.bss) and
    per section its symbols in address order."""

    def __init__(self, coff):
        self.c = coff
        d = coff.data
        _, nsec, _, _, _, opthdr, _ = struct.unpack_from("<HHIIIHH", d, 0)
        self.size = []
        for i in range(nsec):
            o = 20 + opthdr + i * 40
            self.size.append(struct.unpack_from("<I", d, o + 16)[0])
        self.by_sec = {}
        for s in coff.symbols:
            if s[2] > 0:
                self.by_sec.setdefault(s[2], []).append(s)
        for v in self.by_sec.values():
            v.sort(key=lambda s: s[1])
        # the boundaries of the data in each section: its symbols, and the offsets section-relative relocations
        # (jump tables, clang's unnamed constants) point at
        self.bounds = {}
        for s in coff.symbols:
            if s[2] > 0 and not self.is_section_sym(s):
                self.bounds.setdefault(s[2], set()).add(s[1])
        for name, raw, relocs in coff.sections:
            for va, si, typ in relocs:
                t = coff.by_index.get(si)
                if t is not None and t[2] > 0 and typ == DIR32 and self.is_section_sym(t) and raw and va + 4 <= len(raw):
                    self.bounds.setdefault(t[2], set()).add(struct.unpack_from("<i", raw, va)[0])
        self.bounds = {k: sorted(v) for k, v in self.bounds.items()}

    def next_bound(self, sec, off):
        name, raw, _ = self.c.sections[sec - 1]
        size = len(raw) if raw else self.size[sec - 1]
        return min([b for b in self.bounds.get(sec, ()) if b > off] or [size])

    def is_section_sym(self, s):
        return s[4] == 3 and s[1] == 0 and s[0] == self.c.sections[s[2] - 1][0]

    def region(self, s):
        """(secnum, start, end, is_code) of the region symbol S starts."""
        sec = s[2]
        name, raw, _ = self.c.sections[sec - 1]
        size = len(raw) if raw else self.size[sec - 1]
        if self.is_section_sym(s):
            return sec, 0, size, s[3] == 0x20 or name.startswith(".text")
        if s[3] == 0x20:          # a function: to the next function symbol of its section (compare.Coff.function)
            ends = [t[1] for t in self.by_sec[sec] if t[3] == 0x20 and t[1] > s[1]]
            return sec, s[1], min(ends) if ends else size, True
        return sec, s[1], self.next_bound(sec, s[1]), False      # data: to the next boundary

    def region_at(self, sec, off):
        """The region a section-relative relocation to offset OFF of section SEC reaches: the function that holds it,
        else the data from OFF to the next boundary."""
        best = None
        for t in self.by_sec.get(sec, []):
            if t[3] == 0x20 and t[1] <= off and not self.is_section_sym(t):
                best = t
        if best is not None:
            r = self.region(best)
            if r[1] <= off < r[2]:
                return r
        name = self.c.sections[sec - 1][0]
        if name.startswith(".text"):         # (code outside every function: the whole section)
            raw = self.c.sections[sec - 1][1]
            return sec, 0, len(raw) if raw else self.size[sec - 1], True
        return sec, off, self.next_bound(sec, off), False


def function_hash(coff, sym, ext=None, lines=()):
    """The code hash (HEXLEN hex digits) of function SYM (a compare.Coff symbol tuple) of COFF.
    EXT: {symbol name: address} of the TU's other blocks; LINES: the block's text (its directives)."""
    return hash_info(coff, sym, ext or {}, lines)[0]


def hash_info(coff, sym, ext, lines):
    """(hash, {"nodes": how many regions it covers, "names": the targets keyed by name})."""
    o = _Obj(coff)
    emap = equiv_map(lines)
    nodes, index, work = [], {}, []

    def node(region):
        if region not in index:
            index[region] = len(nodes)
            nodes.append(region)
            work.append(region)
        return index[region]

    node(o.region(sym))
    out = [VERSION]
    names = []
    while work:
        sec, lo, hi, code = work.pop(0)
        secname, raw, relocs = coff.sections[sec - 1]
        body = bytearray(raw[lo:hi]) if raw else bytearray()
        rows = []
        for va, si, typ in sorted(relocs):
            if not lo <= va < hi:
                continue
            t = coff.by_index.get(si)
            off = va - lo
            if t is None:
                rows.append((off, typ, ("unknown",)))
                continue
            name = t[0]
            if t[2] > 0 and t[2] == sec and lo <= t[1] < hi and not o.is_section_sym(t):
                k = ("self", t[1] - lo)
            elif t[2] > 0 and o.is_section_sym(t) and typ == DIR32 and raw and off + 4 <= len(body):
                # section-relative: the addend in the bytes is the offset in that section
                a, = struct.unpack_from("<i", body, off)
                body[off:off + 4] = b"\0\0\0\0"
                if t[2] == sec and lo <= a < hi:
                    k = ("self", a - lo)
                else:
                    r = o.region_at(t[2], a)
                    k = ("node", node(r), a - r[1])
            elif name in ext:
                k = ("addr", ext[name])
            elif name.startswith(CONSTS):
                k = ("const", name)
            else:
                a = name_address(name, typ)
                if a is None and name in emap:
                    a = emap[name]
                if a is not None:
                    k = ("addr", a)
                elif name.startswith(BY_NAME):
                    k = ("name", name)
                elif t[2] > 0:
                    k = ("node", node(o.region(t)))
                else:
                    k = ("name", name)
            if k[0] == "name":
                names.append(name)
            rows.append((off, typ, k))
        if code and raw:
            import compare
            body = bytearray(compare.strip_padding(bytes(body)))
        stem = secname.split("$")[0]
        out.append(("%s %s %s" % (stem, body.hex() if raw else "bss:%d" % (hi - lo),
                                  ";".join("%x,%x,%s" % (off, typ, ",".join(str(x) for x in k)) for off, typ, k in rows)))
                   .encode())
    out.append(("directives " + "|".join(directive_lines(lines))).encode())
    h = hashlib.sha256(b"\n".join(out)).hexdigest()[:HEXLEN]
    return h, {"nodes": len(nodes), "names": names}


def object_hash(coff):
    """The whole object's code (every section but debug/directive ones, relocations by target name with compiler
    labels as positions): the fallback for a function the clang object doesn't name as MSVC does."""
    o = _Obj(coff)
    out = [VERSION + b" object"]
    for i, (name, raw, relocs) in enumerate(coff.sections, 1):
        if name.startswith(SKIP_SECTIONS):
            continue
        rows = []
        for va, si, typ in sorted(relocs):
            t = coff.by_index.get(si)
            if t is None:
                k = "?"
            elif t[2] > 0 and (o.is_section_sym(t) or re.match(r"^(\$|\.L|__ehfuncinfo\$|__unwind)", t[0])):
                k = "@%d+%x" % (t[2], t[1])
            else:
                k = t[0]
            rows.append("%x,%x,%s" % (va, typ, k))
        out.append(("%s %s %s" % (name, raw.hex() if raw else "bss:%d" % o.size[i - 1], ";".join(rows))).encode())
    return hashlib.sha256(b"\n".join(out)).hexdigest()[:HEXLEN]
