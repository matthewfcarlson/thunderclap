#!/usr/bin/env python3
"""Data inventory: carve the XBE's .rdata / .data / .bss into items (docs/data.md).

  build/venv/bin/python tools/data_inventory.py            # config/data.json + build/data/inventory-report.json
  build/venv/bin/python tools/data_inventory.py --check    # exit 1 unless config/data.json is what the inputs give
                                                           # (the fields data_gen reads; the rest: warnings)
  build/venv/bin/python tools/data_inventory.py --check --exact   # every field and the coverage line
  build/venv/bin/python tools/data_inventory.py --report   # also print the coverage table

Inputs (config/data.json is a function of these; `--check` holds it to that, docs/data.md "Reproducing"):
  the player's XBE, build/functions.csv, build/rtti.json (local, from the XBE), config/splits.json;
  the merged tree's sources (src/game, src/engine, src/platform/xbox; per function block: the DAT_ names they use and
  the types they declare; a source on include/decls/data/ votes the type config/data.json recorded);
  include/decls/data/records.h (typed records: one item per declaration, its 32-bit size from libclang);
  config/data-items.json (item decisions reviewed by hand), config/data-pointers.json (pointer words whose bytes read
  as text), config/data-source-offsets.json (the offsets verified code uses past an address name; `--refresh-offsets`
  re-reads them from the tree's MSVC objects).

Every byte of .rdata/.data/.bss becomes part of exactly one item. config/data.json holds addresses, sizes,
kinds, names, types, owners and xrefs only: never the bytes or string text of the game's data (string items
are named `s_<up to 20 identifier characters>_<addr>`, as a label).
"""
import argparse
import bisect
import collections
import csv
import json
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from xbe import Xbe  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
FUNCS = os.path.join(ROOT, "build/functions.csv")
SPLITS = os.path.join(ROOT, "config/splits.json")
RTTI = os.path.join(ROOT, "build/rtti.json")
OUT = os.path.join(ROOT, "config/data.json")
WORK = os.path.join(ROOT, "build/data")
XREF_CACHE = os.path.join(WORK, "code_xrefs.json")

# pointer words whose bytes also read as text (a string at 0x42777c is the word 7c 77 42 00, "|wB"): the
# printable-text rule would drop them; reviewed by hand (the mirror of config/data-not-pointers.json)
FORCED_POINTERS = os.path.join(ROOT, "config/data-pointers.json")

GAME_SECTIONS = (".rdata", ".data")
OPAQUE_SECTIONS = ("BINKDATA", "DOLBY", "$$XTIMAGE", "$$XSIMAGE")

# kinds whose bytes the compiler generates from class definitions (code-owned; checked by gen_headers --probe)
CODE_OWNED = {"vtable", "rtti_td", "rtti_col", "rtti_chd", "rtti_bca", "rtti_bcd"}
FPU = {"fld", "fadd", "fsub", "fsubr", "fmul", "fdiv", "fdivr", "fcom", "fcomp", "fst", "fstp", "fild",
       "fiadd", "fimul", "ficom", "ficomp", "fisub", "fisubr", "fidiv", "fidivr", "fist", "fistp"}
FPU_INT = {m for m in FPU if m.startswith("fi")}


# ---------------------------------------------------------------------------------------------
# Inputs
def load_functions():
    out = {}
    with open(FUNCS) as f:
        for r in csv.DictReader(f):
            out[int(r["address"], 16)] = (int(r["size"]), r["name"])
    return out


def load_forced_pointers():
    """Word addresses config/data-pointers.json declares pointers (item address + byte offsets)."""
    try:
        items = json.load(open(FORCED_POINTERS)).get("items", {})
    except (OSError, ValueError):
        return set()
    return {int(a, 16) + int(o, 16) for a, e in items.items() for o in e.get("offsets", ())}


def load_objects():
    objs = json.load(open(SPLITS))["objects"]
    objs.sort(key=lambda o: int(o["start"], 16))
    return objs


def code_xrefs(xbe, funcs, lo, hi, fresh=False):
    """[(func, insn, target, mnemonic, access size, is memory operand, indexed)] for every absolute operand of
    every function that lands in [lo, hi). Cached in build/data/code_xrefs.json (keyed by the function list)."""
    key = "%d:%d" % (len(funcs), sum(funcs) & 0xffffffff)
    if not fresh and os.path.exists(XREF_CACHE):
        c = json.load(open(XREF_CACHE))
        if c.get("key") == key:
            return c["refs"]
    import capstone
    from capstone import x86
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    refs = []
    for a in sorted(funcs):
        size = funcs[a][0]
        o = xbe.offset(a)
        if o is None:
            continue
        for i in md.disasm(xbe.data[o:o + size], a):
            for op in i.operands:
                if op.type == x86.X86_OP_IMM:
                    v, mem, idx = op.imm & 0xffffffff, False, False
                elif op.type == x86.X86_OP_MEM and op.mem.base == 0:
                    v, mem, idx = op.mem.disp & 0xffffffff, True, op.mem.index != 0
                else:
                    continue
                if lo <= v < hi:
                    refs.append((a, i.address, v, i.mnemonic, op.size, mem, idx))
    os.makedirs(WORK, exist_ok=True)
    json.dump({"key": key, "refs": refs}, open(XREF_CACHE, "w"))
    return refs


DECL_RE = re.compile(r'extern\s+(?:"C"\s+)?((?:const\s+)?[A-Za-z_][\w:]*(?:\s+[A-Za-z_]\w*)*\s*\**)\s*'
                     r'(?:const\s+)?DAT_([0-9a-fA-F]{8})\s*(\[\s*(\w*)\s*\])?\s*[;,=]')
NAME_RE = re.compile(r"\bDAT_([0-9a-fA-F]{8})\b")


def previous_items(path=None):
    """addr -> (size, type, source type) of the last inventory's typed items (config/data.json, the record of what
    the sources declared; the source type is `source_type`, else `type`)."""
    out = {}
    try:
        for line in open(path or OUT):
            m = re.match(r'\s*\{"addr":"0x([0-9a-f]+)"', line)
            if not m or '"type"' not in line:
                continue
            it = json.loads(line.strip().rstrip(","))
            out[int(m.group(1), 16)] = (it["size"], it.get("type"), it.get("source_type") or it.get("type"))
    except OSError:
        pass
    return out


def previous_types(path=None):
    """addr -> the type the last inventory recorded for an item (`source_type`, else `type`)."""
    return {a: t[2] for a, t in previous_items(path).items() if t[2]}


TREE_DIRS = ("src/game", "src/engine", "src/platform/xbox")
BLOCK_MARK = re.compile(r"^// 0x[0-9a-f]{8} .+ \(\d+ B\): (?:matches|equivalent|not yet verified)", re.M)


def source_units():
    """[(unit name, names used, declarations text)] of the sources the inventory reads names and types from: every
    function block of the merged tree's TUs (TREE_DIRS; since the merge-once flip, docs/merge-once.md) as the
    function's own source: the DAT_ names of the block's text, and for their declarations the TU's shared part (before
    its first block) plus the block. A name the shared part declares that no block uses (a declaration a function's
    source carried, now hoisted) is a unit of its own. (Before the flip: the per-function sources in matches/ +
    equivalent/, frozen at F.)"""
    out = []
    for d in TREE_DIRS:
        for dp, dns, fns in os.walk(os.path.join(ROOT, d)):
            dns.sort()
            for fn in sorted(fns):
                if not fn.endswith(".cpp"):
                    continue
                path = os.path.join(dp, fn)
                with open(path, encoding="latin1") as f:
                    text = f.read()
                if "DAT_" not in text:
                    continue
                rel = os.path.relpath(path, ROOT)
                marks = [m.start() for m in BLOCK_MARK.finditer(text)]
                if not marks:
                    out.append((rel, names_in(text), text))
                    continue
                shared = text[:marks[0]]
                seen = set()
                for j, at in enumerate(marks):
                    body = text[at:marks[j + 1] if j + 1 < len(marks) else len(text)]
                    used = names_in(body)
                    seen |= used
                    out.append(("%s@%d" % (rel, j), used, shared + body))
                rest = names_in(shared) - seen
                if rest:
                    out.append(("%s@shared" % rel, rest, shared))
    return out


def names_in(text):
    return {a.lower() for a in NAME_RE.findall(text)}


def source_names():
    """addr -> {"sources": n, "types": Counter} from DAT_ names the sources (source_units) use and declare.

    A source on include/decls/data/ (tools/migrate_data.py) no longer declares the names it uses; its vote is
    the type the last inventory recorded for the item (config/data.json is the record of what the sources
    declared), so a re-run after the migration carves and types the same items."""
    out = collections.defaultdict(lambda: {"sources": 0, "types": collections.Counter()})
    prev = None
    for _, used, decl_text in source_units():
        if not used:
            continue
        for a in used:
            out[int(a, 16)]["sources"] += 1
        decls = [m for m in DECL_RE.finditer(decl_text) if m.group(2).lower() in used]
        if '#include "decls/data/' in decl_text:
            if prev is None:
                prev = previous_types()
            declared = {m.group(2).lower() for m in decls}
            for a in used - declared:
                t = prev.get(int(a, 16))
                if t:
                    out[int(a, 16)]["types"][t] += 1
        for m in decls:
            out[int(m.group(2), 16)]["types"][decl_type(m)] += 1
    return out


def decl_type(m):
    """The type a DECL_RE match declares, spelled as the inventory records it (`unsigned` is `unsigned int`)."""
    t = re.sub(r"\s+", " ", m.group(1)).strip()
    t = re.sub(r"\bunsigned(?!\s+(?:int|char|short|long|__int64)\b)", "unsigned int", t)
    if m.group(3):
        t += "[%s]" % m.group(4)
    return t


SRC_OFFSETS = os.path.join(ROOT, "config/data-source-offsets.json")
# a data symbol in an object: `_DAT_x` (extern "C", the shared data headers), `?DAT_x@@...` (C++ linkage)
SYM_RE = re.compile(r"(?<![0-9A-Za-z])_?DAT_([0-9a-fA-F]{8})(?![0-9A-Za-z])")


def load_source_offsets(path=None):
    """addr -> the largest offset past DAT_<addr> that verified code uses: config/data-source-offsets.json, a
    committed input (`--refresh-offsets` re-reads it from the merged tree's MSVC objects)."""
    try:
        with open(path or SRC_OFFSETS) as f:
            d = json.load(f)
    except OSError:
        return {}, 0
    return {int(a, 16): k for a, k in d["offsets"].items()}, d.get("objects", 0)


def tree_objects():
    """(object paths, TU count) of the merged tree's TUs (TREE_DIRS) that build_tree's object cache holds (compiled
    by `tools/tree_tu.py check` / `verify`, by content)."""
    import tree_tu
    import build_tree
    tus = []
    for d in TREE_DIRS:
        for dp, dns, fns in os.walk(os.path.join(ROOT, d)):
            tus += [os.path.join(dp, f) for f in fns if f.endswith(".cpp")]
    out = []
    for p in sorted(tus):
        obj = os.path.join(build_tree.OBJ_CACHE, tree_tu.object_key(p) + ".obj")
        if os.path.exists(obj):
            out.append(obj)
    return out, len(tus)


def refresh_source_offsets(path=None, compile_missing=False, jobs=4):
    """Re-read config/data-source-offsets.json from the merged tree's objects (every TU must have its object:
    `compile_missing` compiles the others, MSVC through wibo: a queue job, docs/compute.md)."""
    objs, total = tree_objects()
    if compile_missing and len(objs) < total:
        import tree_tu
        from concurrent.futures import ThreadPoolExecutor
        tus = []
        for d in TREE_DIRS:
            for dp, dns, fns in os.walk(os.path.join(ROOT, d)):
                tus += [os.path.join(dp, f) for f in fns if f.endswith(".cpp")]
        with ThreadPoolExecutor(jobs) as ex:
            list(ex.map(tree_tu.compile_tu, sorted(tus)))
        objs, total = tree_objects()
    if len(objs) < total:
        raise SystemExit("--refresh-offsets: %d of %d tree TUs have no object (compile them: --compile, as a queue "
                         "job)" % (total - len(objs), total))
    off = source_offsets(objs)
    with open(path or SRC_OFFSETS, "w") as f:
        f.write('{"_doc": "Offsets past an address name that the merged tree\'s MSVC objects use (DAT_x + k, the '
                'relocation addends; tools/data_inventory.py --refresh-offsets): an input of the inventory\'s extents. '
                'Addresses and offsets only.",\n "objects": %d,\n "offsets": {\n' % len(objs))
        ks = sorted(off)
        f.write(",\n".join('  "0x%08x": %d' % (a, off[a]) for a in ks))
        f.write("\n }\n}\n")
    return off, len(objs)


def source_offsets(objs):
    """addr -> largest offset past DAT_<addr> that compiled verified code uses (DIR32 addends in the objects)."""
    from compare import Coff
    out = {}
    for path in objs:
        c = Coff(path)
        for name, raw, relocs in c.sections:
            for va, si, typ in relocs:
                if typ != 6:
                    continue
                sym = c.by_index.get(si)
                if not sym:
                    continue
                m = SYM_RE.search(sym[0])
                if not m or len(raw) < va + 4:
                    continue
                add, = struct.unpack_from("<i", raw, va)
                a = int(m.group(1), 16)
                if 0 < add < 0x10000:
                    out[a] = max(out.get(a, 0), add)
    return out


ITEMS_PINNED = os.path.join(ROOT, "config/data-items.json")
PIN_KEYS = ("size", "pad", "kind", "type", "name", "object")


def load_pins(path=None):
    """{addr: {size, kind, type, name, object}} of config/data-items.json: item decisions reviewed by hand (each with
    its `why`) that the evidence alone doesn't give. With `size` the item is placed as one span before carving (a
    `kind` is then required); without it the fields override the carved item that starts there."""
    try:
        with open(path or ITEMS_PINNED) as f:
            items = json.load(f).get("items", {})
    except OSError:
        return {}
    out = {}
    for a, e in items.items():
        p = {k: e[k] for k in PIN_KEYS if k in e}
        if "size" in p and "kind" not in p:
            raise SystemExit("config/data-items.json: %s has a size but no kind" % a)
        out[int(a, 16)] = p
    return out


RECORDS_H = os.path.join(ROOT, "include/decls/data/records.h")


def record_items(path=None):
    """{addr: (declared type, 32-bit size)} of the items include/decls/data/records.h declares
    (`extern "C" T DAT_<addr>[N];`, docs/data.md "Typed records"): each is one inventory item spanning the
    declaration's 32-bit size, whatever the carve would make of its bytes. Sizes come from libclang
    (i686-pc-windows-msvc, the MSVC layout; the data TUs assert them with MSVC)."""
    import clang.cindex as ci
    if not ci.Config.loaded:
        try:
            import clang_probe
            lib = os.environ.get("HULK_LIBCLANG") or os.path.join(os.path.dirname(clang_probe.LLVM), "lib",
                                                                 "libclang.dylib" if sys.platform == "darwin"
                                                                 else "libclang.so")
            if os.path.exists(lib):
                ci.Config.set_library_file(lib)
        except Exception:  # noqa: BLE001
            pass
    path = path or RECORDS_H
    tu = ci.Index.create().parse(path, args=["-x", "c++", "--target=i686-pc-windows-msvc", "-fms-extensions",
                                             "-fms-compatibility", "-std=c++14", "-I" + os.path.join(ROOT, "include")])
    errs = [str(d) for d in tu.diagnostics if d.severity >= 3]
    if errs:
        raise SystemExit("records.h does not parse: %s" % "; ".join(errs[:3]))
    out = {}
    for c in tu.cursor.walk_preorder():
        if c.kind != ci.CursorKind.VAR_DECL or not c.location.file or \
                os.path.abspath(c.location.file.name) != os.path.abspath(path):
            continue
        m = re.fullmatch(r"DAT_([0-9a-f]{8})", c.spelling)
        if m:
            size = c.type.get_size()
            if size <= 0:
                raise SystemExit("records.h: %s has no complete type" % c.spelling)
            out[int(m.group(1), 16)] = (c.type.spelling, size)
    return out


# ---------------------------------------------------------------------------------------------
# Byte tests
PRINTABLE = set(range(0x20, 0x7f)) | {0x09, 0x0a, 0x0d}


def string_at(buf, o, end, strict=False):
    """Length of a NUL-terminated text string at buf[o:] within end (without the NUL), or None.
    Text is printable ASCII plus tab/newline/CR; game strings may also hold \\x08 / \\x1b markup and (unless
    strict) a few Latin-1 letters."""
    n = buf.find(b"\0", o, end)
    if n < 0:
        return None
    s = buf[o:n]
    if not s:
        return 0
    bad = high = 0
    for b in s:
        if b in PRINTABLE:
            continue
        if b in (0x08, 0x1b) and len(s) >= 3:
            bad += 1
        elif b >= 0xc0 and not strict:
            high += 1
        else:
            return None
    if (bad + high) * 4 > len(s):
        return None
    return len(s)


def wstring_at(buf, o, end):
    i = o
    while i + 1 < end:
        c = buf[i] | buf[i + 1] << 8
        if c == 0:
            return (i - o) // 2 if i > o else None
        if not (0x20 <= c < 0x7f or c in (9, 10, 13)):
            return None
        i += 2
    return None


PRIM_SIZE = {"char": 1, "signed char": 1, "unsigned char": 1, "bool": 1, "short": 2, "unsigned short": 2,
             "int": 4, "unsigned int": 4, "long": 4, "unsigned long": 4, "float": 4, "uint": 4, "double": 8,
             "__int64": 8, "unsigned __int64": 8, "undefined4": 4}


def type_size(t):
    """Size of a source-declared type when it is a primitive, pointer, or array of them; else None."""
    m = re.fullmatch(r"(?:const )?(.+?)(\[(\d+)\])?", t)
    base, n = m.group(1).strip(), m.group(3)
    if base.endswith("*"):
        sz = 4
    else:
        sz = PRIM_SIZE.get(base)
    if sz is None or (m.group(2) and not n):
        return None
    return sz * (int(n) if n else 1)


def plausible_float(w):
    if w == 0 or w == 0x80000000:
        return True
    e = (w >> 23) & 0xff
    return 80 <= e <= 180       # |x| in about [1e-14, 1e16]


def ident(text, n=20):
    t = re.sub(r"[^A-Za-z0-9]+", "_", text).strip("_")
    return t[:n].rstrip("_") or "empty"


# ---------------------------------------------------------------------------------------------
class Inventory:
    def __init__(self):
        self.xbe = Xbe(XBE_PATH)
        self.funcs = load_functions()
        self.fstarts = sorted(self.funcs)
        self.objs = load_objects()
        self.ostarts = [int(o["start"], 16) for o in self.objs]
        self.secs = {s.name: s for s in self.xbe.sections if s.name in GAME_SECTIONS}
        rd, dt = self.secs[".rdata"], self.secs[".data"]
        self.lo, self.hi = rd.va, dt.va + dt.vsize
        self.text = next(s for s in self.xbe.sections if s.name == ".text")
        # one flat image of [lo, hi): raw bytes, zeros for the virtual tails (bss)
        self.img = bytearray(self.hi - self.lo)
        for s in (rd, dt):
            o = s.va - self.lo
            self.img[o:o + s.rsize] = self.xbe.data[s.raw:s.raw + s.rsize]
        self.bss_lo = dt.va + dt.rsize
        self.rdata_tail = rd.va + rd.rsize
        self.items = {}           # addr -> item dict
        self.fixed = []           # (start, end) of items placed before carving
        self.init_obj = next((i for i, o in enumerate(self.objs) if o.get("kind") == "game-init"), None)

    # -- helpers
    def sec_name(self, a):
        if a < self.secs[".data"].va:
            return ".rdata"
        return ".bss" if a >= self.bss_lo else ".data"

    def u32(self, a):
        return struct.unpack_from("<I", self.img, a - self.lo)[0]

    def obj_index(self, a):
        i = bisect.bisect_right(self.ostarts, a) - 1
        if i < 0:
            return None
        o = self.objs[i]
        return i if a < int(o["end"], 16) else None

    def func_of(self, a):
        i = bisect.bisect_right(self.fstarts, a) - 1
        if i >= 0:
            f = self.fstarts[i]
            if a < f + self.funcs[f][0]:
                return f
        return None

    def is_code_ptr(self, v):
        return self.text.va <= v < self.text.va + self.text.vsize or self.xbe.is_code(v) and \
            self.xbe.section_of(v) is not None and self.xbe.section_of(v).name not in OPAQUE_SECTIONS

    def is_data_ptr(self, v):
        return self.lo <= v < self.hi

    def add(self, a, size, kind, **kw):
        bound = getattr(self, "_bound", None)
        if bound is not None and a + size > bound:
            size = bound - a           # an access wider than the gap to the next referenced address
            kw["flags"] = kw.get("flags", []) + ["truncated"]
        it = dict(addr=a, size=size, kind=kind, **kw)
        self.items[a] = it
        return it

    # -- 1. structures known up front
    def place_fixed(self):
        rd = self.secs[".rdata"]
        a = rd.va
        while self.u32(a) & 0x80000000 and self.u32(a) != 0xffffffff:
            a += 4
        self.add(rd.va, a + 4 - rd.va, "kernel_thunks", name="XboxKrnlThunkTable", layer_hint="library")
        self.fixed.append((rd.va, a + 4))
        rtti = json.load(open(RTTI))
        self.rtti_classes = rtti["classes"]
        # type_info's own vftable (CRT; no locator before it): every type descriptor points at it
        ti = rtti["type_info_vftable"]
        self.add(ti, 4, "vtable", name="??_7type_info@@6B@", type="vftable", cls="type_info", slots=1,
                 layer_hint="library")
        self.fixed.append((ti, ti + 4))
        by_td = {c["td"]: c for c in rtti["classes"]}
        seen = set()

        def put(a, size, kind, **kw):
            if a in seen or not self.lo <= a < self.hi:
                return
            seen.add(a)
            self.add(a, size, kind, **kw)
            self.fixed.append((a, a + size))

        for c in rtti["classes"]:
            m = c["mangled"]                         # .?AVFoo@ns@@
            put(c["td"], (8 + len(m) + 1 + 3) & ~3, "rtti_td", name="??_R0%s@8" % m, type="TypeDescriptor",
                cls=c["name"])
        for c in rtti["classes"]:
            core = c["mangled"][4:]                   # Foo@ns@@
            for v in c["vtables"]:
                col = v["col"]
                put(col, 20, "rtti_col", name="??_R4%s6B@" % core if v["offset"] == 0 else "??_R4%s6B@+%x" % (
                    core, v["offset"]), type="RTTICompleteObjectLocator", cls=c["name"])
                chd = self.u32(col + 16)
                nb, bca = self.u32(chd + 8), self.u32(chd + 12)
                put(chd, 16, "rtti_chd", name="??_R3%s8" % core, type="RTTIClassHierarchyDescriptor",
                    cls=c["name"])
                put(bca, 4 * nb, "rtti_bca", name="??_R2%s8" % core, type="RTTIBaseClassArray", cls=c["name"])
                for j in range(nb):
                    bcd = self.u32(bca + 4 * j)
                    btd = self.u32(bcd)
                    bn = by_td[btd]["name"] if btd in by_td else "?"
                    put(bcd, 24, "rtti_bcd", name="??_R1%s" % bn, type="RTTIBaseClassDescriptor", cls=bn)
        # vtables: [COL pointer][slots], the ??_7 symbol 4 bytes in (one MSVC COMDAT)
        vts = []
        for c in rtti["classes"]:
            for v in c["vtables"]:
                vts.append((v["address"], c, v))
        vts.sort(key=lambda t: t[0])
        starts = sorted(set(s for s, _ in self.fixed))
        for vt, c, v in vts:
            n = len(v["slots"])
            # never run into the next fixed structure (rtti.py can over-count a vtable's slots)
            j = bisect.bisect_right(starts, vt)
            if j < len(starts):
                n = min(n, (starts[j] - vt) // 4)
            core = c["mangled"][4:]
            name = "??_7%s6B@" % core if v["offset"] == 0 else "??_7%s6B@+%x" % (core, v["offset"])
            it = put(vt - 4, 4 + 4 * n, "vtable", name=name, type="vftable", cls=c["name"], slots=n,
                     vfptr_offset=v["offset"])
        self.vtables = {vt for vt, _, _ in vts}
        # typed records (include/decls/data/records.h): one item each, its declaration's span
        self.records = record_items()
        for a, (t, size) in sorted(self.records.items()):
            if not self.lo <= a < self.hi:
                continue
            put(a, size, "bss" if a >= self.bss_lo else "table", record=t)
        # item spans reviewed by hand (config/data-items.json)
        self.pins = load_pins()
        for a, p in sorted(self.pins.items()):
            if "size" in p:
                if a in seen:
                    raise SystemExit("config/data-items.json: %#x is also a fixed structure or a record" % a)
                put(a, p["size"], p["kind"], **{k: p[k] for k in ("type", "name") if k in p})
        for a, p in sorted(self.pins.items()):
            if "pad" in p:
                # alignment padding after the item (written as its `pad`), e.g. a 12-byte record in a 16-byte slot
                end = a + (p["size"] if "size" in p else self.records[a][1] if a in self.records else 0)
                if end == a:
                    raise SystemExit("config/data-items.json: %#x has a pad but no span (size or record)" % a)
                put(end, p["pad"], "padding", section=self.sec_name(end))

    # -- 2. start points
    def collect_starts(self, xrefs, src, src_off):
        starts = collections.defaultdict(set)    # addr -> reasons
        self.code_refs = collections.defaultdict(list)
        mem_targets = {r[2] for r in xrefs if r[5]}
        self.dropped_imm = 0
        for f, ia, v, mn, sz, mem, idx in xrefs:
            if not mem and v not in mem_targets and not self.address_like_imm(v, mn):
                self.dropped_imm += 1   # an immediate in the data range that is a constant (FourCC, hash, mask)
                continue
            starts[v].add("code")
            self.code_refs[v].append((f, mn, sz, mem, idx))
        self.false_source_names = []
        for a in src:
            if self.lo <= a < self.hi:
                if a not in mem_targets and a not in starts and a >= self.bss_lo and not self.address_like_imm(a, "push"):
                    self.false_source_names.append(a)   # a DAT_ name for a constant that only looks like an address
                    continue
                starts[a].add("source")
        # aligned words of initialized data that point into the data range
        self.data_ptrs = {}       # word address -> value
        forced = load_forced_pointers()
        for a in range(self.lo, self.bss_lo, 4):
            v = self.u32(a)
            if self.is_data_ptr(v) and a not in forced:
                b = self.img[a - self.lo:a - self.lo + 3]
                if all(c in PRINTABLE for c in b):
                    continue            # text ("RSU\0"), not an address
                if v % 4 and not (v < self.bss_lo and self.looks_string(v, 1)):
                    continue            # unaligned targets are only string tails
            if self.is_data_ptr(v) or (self.is_code_ptr(v) and v in self.funcs):
                self.data_ptrs[a] = v
                if self.is_data_ptr(v):
                    starts[v].add("data")
        self.src_off = src_off
        return starts

    # -- 3. carve
    def carve(self, starts):
        # fixed structures must not overlap (an overlap means a bad RTTI parse: keep the first)
        fixed, last = [], self.lo
        for fs, fe in sorted(set(self.fixed)):
            if fs < last:
                self.items.pop(fs, None)
                self.overlaps = getattr(self, "overlaps", 0) + 1
                continue
            fixed.append((fs, fe))
            last = fe
        self.fixed = fixed
        fixed_starts = [s for s, _ in fixed]
        self.interior = collections.defaultdict(list)   # item addr -> [interior referenced addrs]
        free = []
        for a in sorted(starts):
            j = bisect.bisect_right(fixed_starts, a) - 1
            if j >= 0 and fixed[j][0] <= a < fixed[j][1]:
                if a != fixed[j][0]:
                    self.interior[fixed[j][0]].append(a)
                continue
            free.append(a)
        # merge starts covered by a source offset (DAT_x + k used by verified code)
        merged, skip_until = [], -1
        for a in free:
            if merged and a <= skip_until:
                self.interior[merged[-1]].append(a)
                continue
            merged.append(a)
            k = self.src_off.get(a)
            if k and not self.looks_string(a):
                skip_until = max(skip_until, a + k)
        # a string swallows starts that fall inside it (pointers to a suffix: "xRET" + 1)
        absorbed, cur_end = [], -1
        for a in merged:
            if a < cur_end:
                self.interior[absorbed[-1]].append(a)
                continue
            absorbed.append(a)
            o = a - self.lo
            n = string_at(self.img, o, min(len(self.img), o + 4096)) if a < self.bss_lo else None
            if n is not None and n >= 4 and not (a % 4 == 0 and a in self.data_ptrs and n < 8) and \
                    not any(r[1] in FPU for r in self.code_refs.get(a, [])):
                cur_end = a + n + 1
        merged = absorbed
        free_set = set(merged)
        edges = {self.secs[".data"].va, self.bss_lo, self.rdata_tail}
        # free regions between fixed structures
        regions, pos = [], self.lo
        for fs, fe in fixed:
            if pos < fs:
                regions.append((pos, fs))
            pos = fe
        if pos < self.hi:
            regions.append((pos, self.hi))
        for rs, re_ in regions:
            bs = sorted({rs, re_} | {a for a in free_set if rs < a < re_} | {e for e in edges if rs < e < re_})
            for i in range(len(bs) - 1):
                self.classify(bs[i], bs[i + 1], referenced=bs[i] in free_set)

    def address_like_imm(self, v, mn):
        """Is an immediate operand (never used as a memory operand) plausibly an address?"""
        if mn in ("cmp", "and", "or", "xor", "add", "sub", "imul", "test", "sbb", "adc"):
            return False
        if v % 4 == 0:
            return not (v >= self.bss_lo and all(c in PRINTABLE for c in v.to_bytes(4, "little")[:3]))
        # unaligned: string literals (and their tails) only
        return v < self.bss_lo and self.looks_string(v, 1)

    def set_source_types(self, src):
        self.src_types = {a: v["types"].most_common(1)[0][0] for a, v in src.items() if v["types"]}

    def looks_string(self, a, minlen=2):
        o = a - self.lo
        n = string_at(self.img, o, min(len(self.img), o + 4096))
        return n is not None and n >= minlen

    def classify(self, s, e, referenced):
        """Turn [s, e) (a referenced start up to the next one) into one or more items."""
        if s >= e:
            return
        self._bound = e
        sec = self.sec_name(s)
        if self.rdata_tail <= s < self.secs[".data"].va:
            self.add(s, e - s, "padding", section=".rdata")
            return
        if sec == ".bss":
            self.add(s, e - s, "bss" if referenced else "unknown_bss", section=sec)
            return
        if not referenced:
            self.carve_unreferenced(s, e)
            return
        o, oe = s - self.lo, e - self.lo
        refs = self.code_refs.get(s, [])
        fpu = [r for r in refs if r[1] in FPU and r[3]]
        acc = collections.Counter(r[2] for r in refs if r[3])
        indexed = any(r[4] for r in refs)
        # strings
        n = string_at(self.img, o, oe)
        if n is not None and n <= 3 and s % 4 == 0 and s in self.data_ptrs:
            n = None                    # a pointer whose bytes happen to read as a short string
        st = self.src_types.get(s, "")
        if n is not None and n < 4 and (st and "char" not in st or any(r[2] >= 2 for r in refs if r[3])):
            n = None                    # a short "string" that code loads as a number (or sources type as one)
        if n is not None and not fpu:
            self.add(s, n + 1, "string", section=sec)
            self.rest(s + n + 1, e)
            return
        w = wstring_at(self.img, o, oe)
        if w is not None and w >= 2 and not fpu:
            self.add(s, 2 * w + 2, "wstring", section=sec)
            self.rest(s + 2 * w + 2, e)
            return
        size = e - s
        if fpu:
            sz = max(r[2] for r in fpu)
            ints = all(r[1] in FPU_INT for r in fpu)
            elem = {4: "int" if ints else "float", 8: "__int64" if ints else "double", 2: "short",
                    10: "long double"}.get(sz, "float")
            kind = "double" if elem == "double" else "float" if elem == "float" else "scalar"
            if size > sz and indexed and not self.zero(s + sz, e):
                n = size // sz
                self.add(s, n * sz, "float_table" if kind in ("float", "double") else "table", section=sec,
                         type="%s[%d]" % (elem, n))
                self.rest(s + n * sz, e)
                return
            self.add(s, sz, kind, section=sec, type=elem)
            self.rest(s + sz, e)
            return
        # extent evidence: access width (not indexed), source declaration, source offsets
        ext = 0
        if acc and not indexed:
            ext = max(acc)
        st = self.src_types.get(s)
        tsz = type_size(st) if st else None
        if tsz:
            ext = max(ext, tsz)
        k = self.src_off.get(s)
        if k:
            ext = max(ext, (k + 4) & ~3)
        if ext and ext < size and not indexed:
            self.whole(s, s + ext, sec, refs)
            self.rest(s + ext, e)
            return
        self.whole(s, e, sec, refs, indexed=indexed)

    def whole(self, s, e, sec, refs, indexed=False):
        """A referenced item of known extent [s, e)."""
        size = e - s
        acc = collections.Counter(r[2] for r in refs if r[3])
        if s % 4 == 0 and size % 4 == 0:
            words = size // 4
            ptrs = [self.data_ptrs.get(s + 4 * i) for i in range(words)]
            nz = [p for p in ptrs if p]
            if nz and all(p or self.u32(s + 4 * i) == 0 for i, p in enumerate(ptrs)):
                if words == 1:
                    self.add(s, 4, "pointer", section=sec, type="void*")
                else:
                    self.add(s, size, "pointer_table", section=sec, type="void*[%d]" % words)
                return
            if nz:
                self.add(s, size, "struct", section=sec, pointers=len(nz))
                return
        sz = max(acc) if acc else 0
        t = {1: "unsigned char", 2: "short", 4: "int", 8: "__int64"}.get(sz)
        if sz and sz == size:
            self.add(s, size, "scalar", section=sec, type=t)
        else:
            if t and size % sz == 0:
                t = "%s[%d]" % (t, size // sz)
            else:
                t = None
            self.add(s, size, "table", section=sec, type=t)

    def zero(self, s, e):
        return not any(self.img[s - self.lo:e - self.lo])

    def rest(self, s, e):
        """The bytes after an item up to the next referenced address."""
        if s < e:
            self.carve_unreferenced(s, e)

    def carve_unreferenced(self, s, e):
        """Greedy carve of bytes nothing references directly: strings, pointer runs, float runs (header-defined
        static constants that every including object emits), zero padding, and what's left as unknown."""
        sec = self.sec_name(s)
        p = s
        unk = None

        def flush(upto):
            nonlocal unk
            if unk is not None and upto > unk:
                self.add(unk, upto - unk, "unknown", section=sec, referenced=False)
            unk = None

        while p < e:
            o = p - self.lo
            aligned = p % 4 == 0 and p + 4 <= e
            n = string_at(self.img, o, e - self.lo, strict=True)
            if n is not None and (n >= 4 or n >= 2 and not aligned) and not (aligned and p in self.data_ptrs):
                flush(p)
                self.add(p, n + 1, "string", section=sec, referenced=False)
                p += n + 1
                continue
            w = wstring_at(self.img, o, e - self.lo) if p % 2 == 0 else None
            if w is not None and w >= 3 and not (aligned and p in self.data_ptrs):
                flush(p)
                self.add(p, 2 * w + 2, "wstring", section=sec, referenced=False)
                p += 2 * w + 2
                continue
            if aligned and (p in self.data_ptrs or self.u32(p) and plausible_float(self.u32(p))):
                kind = "pointer" if p in self.data_ptrs else "float"
                q = p + 4
                while q + 4 <= e and (q in self.data_ptrs if kind == "pointer" else
                                      q not in self.data_ptrs and self.u32(q) and plausible_float(self.u32(q))):
                    q += 4
                flush(p)
                nw = (q - p) // 4
                if kind == "pointer":
                    self.add(p, q - p, "pointer_table" if nw > 1 else "pointer", section=sec,
                             type="void*[%d]" % nw if nw > 1 else "void*", referenced=False)
                else:
                    self.add(p, q - p, "float_table" if nw > 1 else "float", section=sec,
                             type="float[%d]" % nw if nw > 1 else "float", referenced=False)
                p = q
                continue
            if self.img[o] == 0 and not (aligned and self.u32(p)):
                q = p
                while q < e and self.img[q - self.lo] == 0:
                    q += 1
                if q < e and q % 4 and (q & ~3) > p:
                    q &= ~3                   # the next word starts with zero bytes (a float like 0x447fc000)
                flush(p)
                self.add(p, q - p, "padding" if q - p < 4 else "zeros", section=sec)
                p = q
                continue
            if unk is None:
                unk = p
            p += 4 if aligned else 1
        flush(e)

    # -- 4. names, owners, xrefs
    def finish(self, src):
        items = [self.items[a] for a in sorted(self.items)]
        # merge neighbouring padding items
        out = []
        for it in items:
            if out and it["kind"] in ("padding", "zeros") and out[-1]["kind"] == it["kind"] and \
                    out[-1]["addr"] + out[-1]["size"] == it["addr"]:
                out[-1]["size"] += it["size"]
                continue
            out.append(it)
        items = out
        addrs = [it["addr"] for it in items]

        def item_at(a):
            j = bisect.bisect_right(addrs, a) - 1
            return items[j] if j >= 0 and a < items[j]["addr"] + items[j]["size"] else None

        # data -> data references (item level)
        data_refs = collections.defaultdict(set)
        code_ptrs = collections.defaultdict(set)
        for w, v in self.data_ptrs.items():
            src_it = item_at(w)
            if src_it is None or src_it["kind"] in ("padding", "unknown"):
                continue
            if self.is_data_ptr(v):
                t = item_at(v)
                if t is not None and t is not src_it:
                    data_refs[t["addr"]].add(src_it["addr"])
            else:
                code_ptrs[src_it["addr"]].add(v)
        code_by_item = collections.defaultdict(set)
        for v, rs in self.code_refs.items():
            t = item_at(v)
            if t is not None:
                for r in rs:
                    code_by_item[t["addr"]].add(r[0])
        for it in items:
            a = it["addr"]
            it["xrefs"] = sorted(code_by_item.get(a, ()))
            it["data_refs"] = sorted(data_refs.get(a, ()))
            s = src.get(a)
            if s:
                it["source_names"] = s["sources"]
                if s["types"] and not it.get("type"):
                    it["type"] = s["types"].most_common(1)[0][0]
                elif s["types"]:
                    it["source_type"] = s["types"].most_common(1)[0][0]
            inter = self.interior.get(a)
            if inter:
                it["interior"] = sorted(set(inter))
        # a type the sources gave once stays while nothing contradicts it: an item no source names any more keeps the
        # type the last inventory recorded for the same span (its declaration in include/decls/data/ stays put)
        prev = previous_items()
        for it in items:
            p = prev.get(it["addr"])
            if p and p[1] and not it.get("type") and p[0] == it["size"] and it["kind"] not in CODE_OWNED:
                it["type"] = p[1]
        self.assign_owners(items, code_ptrs)
        by_addr = {it["addr"]: it for it in items}
        for a, p in sorted(self.pins.items()):
            it = by_addr.get(a)
            if it is None:
                raise SystemExit("config/data-items.json: no item starts at %#x" % a)
            for k in ("kind", "type", "name"):
                if k in p:
                    it[k] = p[k]            # ("type": null: the item has no type)
            if "object" in p and p["object"] != it.get("object"):
                o = next((o for o in self.objs if o["file"] == p["object"]), None)
                if o is None:
                    raise SystemExit("config/data-items.json: %#x: no object %s" % (a, p["object"]))
                it["object"], it["layer"] = o["file"], o.get("layer", "game")
                it["opaque"] = it["layer"] == "library"
        for it in items:
            it.setdefault("name", self.name_of(it))
        self.final = items
        return items

    def name_of(self, it):
        a, k = it["addr"], it["kind"]
        if k == "string":
            o = a - self.lo
            return "s_%s_%08x" % (ident(bytes(self.img[o:o + it["size"] - 1]).decode("latin1")), a)
        if k == "wstring":
            o = a - self.lo
            return "ws_%s_%08x" % (ident(bytes(self.img[o:o + it["size"] - 2]).decode("utf-16-le")), a)
        pre = {"float": "flt", "double": "dbl", "float_table": "fltTbl", "pointer_table": "ptrTbl",
               "pointer": "PTR", "table": "tbl", "struct": "struct", "scalar": "DAT", "bss": "DAT",
               "unknown": "unk", "unknown_bss": "unkBss", "padding": "pad", "zeros": "zero"}.get(k, "DAT")
        return "%s_%08x" % (pre, a)

    def assign_owners(self, items, code_ptrs):
        """Owner object per item: the referencing object; shared data by link order (the run it sits in)."""
        lib = {i for i, o in enumerate(self.objs) if o.get("kind") == "library"}

        def cands(it):
            c = collections.Counter()
            for f in it["xrefs"]:
                i = self.obj_index(f)
                if i is not None and i != self.init_obj:
                    c[i] += 1
            return c

        by_addr = {it["addr"]: it for it in items}
        for it in items:
            it["_c"] = cands(it)
            if it["kind"] == "vtable" or it["kind"] == "pointer_table" or it["kind"] == "struct":
                # a table of code pointers belongs with the code it points to when nothing references it
                if not it["_c"]:
                    for v in code_ptrs.get(it["addr"], ()):
                        i = self.obj_index(v)
                        if i is not None and i != self.init_obj:
                            it["_c"][i] += 0.5
        # data-only referenced items take their referencing items' candidates (2 rounds: strings in tables)
        for _ in range(2):
            for it in items:
                if not it["_c"] and it["data_refs"]:
                    for r in it["data_refs"]:
                        for i, n in by_addr[r]["_c"].items():
                            it["_c"][i] += 0.25 * n
                    if it["_c"]:
                        it["_via_data"] = True
        # init-only references: the dynamic initializer is in link order too, but has no object of its own
        for it in items:
            if not it["_c"] and it["xrefs"]:
                it["_init_only"] = True
        # anchors: one candidate. Shared items: the candidate inside the neighbouring anchors' window, first in
        # link order (a COMDAT is placed with the first object that contributes it).
        for sec in (".rdata", ".data", ".bss"):
            seq = [it for it in items if self.sec_name(it["addr"]) == sec]
            anchors = [(k, min(it["_c"])) for k, it in enumerate(seq) if len(it["_c"]) == 1]
            ak = [k for k, _ in anchors]
            for k, it in enumerate(seq):
                j = bisect.bisect_left(ak, k)
                prev = anchors[j - 1][1] if j > 0 else None
                if j < len(ak) and ak[j] == k:
                    nxt = anchors[j + 1][1] if j + 1 < len(ak) else None
                else:
                    nxt = anchors[j][1] if j < len(ak) else None
                c = it["_c"]
                flags = it.setdefault("flags", [])
                if len(c) == 1:
                    own, how = min(c), "refs"
                    if prev is not None and nxt is not None and not (prev <= own <= nxt) and own not in lib:
                        flags.append("out_of_order")
                elif c:
                    lo_, hi_ = (prev if prev is not None else -1), (nxt if nxt is not None else 1 << 30)
                    inwin = sorted(i for i in c if lo_ <= i <= hi_)
                    own = inwin[0] if inwin else min(c)
                    how = "shared"
                    if not inwin:
                        flags.append("out_of_order")
                else:
                    if prev is not None and prev == nxt:
                        own, how = prev, "neighbours"
                    elif prev is not None or nxt is not None:
                        own = prev if prev is not None else nxt
                        how = "neighbour_guess"
                    else:
                        own, how = None, "none"
                if it.get("_via_data") and how in ("refs", "shared"):
                    how = "data_" + how
                if it.get("_init_only"):
                    flags.append("init_only")
                it["object_i"] = own
                it["owner_by"] = how
                if how.endswith("shared"):
                    it["shared_objects"] = len(c)
        # compiler-generated class data (vtables, RTTI) lives with its class: the object whose dominant class it is
        home = {}
        for i, o in enumerate(self.objs):
            if o.get("dominant") and o.get("kind") == "game":
                home.setdefault(o["dominant"], i)
        for it in items:
            if it["kind"] in CODE_OWNED and it.get("cls") in home and it["object_i"] != home[it["cls"]]:
                it["object_i"] = home[it["cls"]]
                it["owner_by"] = "class"
                it["flags"] = [f for f in it.get("flags", []) if f != "out_of_order"]
        for it in items:
            i = it.pop("object_i")
            it.pop("_c", None)
            it.pop("_via_data", None)
            it.pop("_init_only", None)
            if not it.get("flags"):
                it.pop("flags", None)
            if i is None:
                it["object"], it["layer"] = None, "library" if it.get("layer_hint") == "library" else "unknown"
            else:
                o = self.objs[i]
                it["object"], it["layer"] = o["file"], o.get("layer", "game")
            if it.pop("layer_hint", None) == "library":
                it["layer"] = "library"
            it["opaque"] = it["layer"] == "library"


def opaque_sections(xbe):
    out = []
    for s in xbe.sections:
        if s.name in OPAQUE_SECTIONS:
            out.append({"addr": s.va, "size": s.vsize, "section": s.name, "kind": "library_section",
                        "name": "sec_" + re.sub(r"\W", "", s.name), "object": None, "layer": "library",
                        "opaque": True, "xrefs": [], "data_refs": []})
    return out


# ---------------------------------------------------------------------------------------------
def coverage(items):
    by_kind = collections.Counter()
    by_kind_n = collections.Counter()
    by_layer = collections.defaultdict(collections.Counter)
    for it in items:
        k = it["kind"]
        by_kind[k] += it["size"]
        by_kind_n[k] += 1
        by_layer[it["layer"]][k] += it["size"]
    owners = collections.Counter(it.get("owner_by") for it in items if it["kind"] not in ("padding",))
    return {"bytes_by_kind": dict(by_kind.most_common()), "items_by_kind": dict(by_kind_n.most_common()),
            "bytes_by_layer": {k: dict(v.most_common()) for k, v in sorted(by_layer.items())},
            "owner_by": dict(owners.most_common()),
            "unknown_bytes": by_kind["unknown"] + by_kind["unknown_bss"],
            "total_bytes": sum(by_kind.values())}


OWNER_BY = {"refs": "refs", "data_refs": "data", "shared": "shared", "data_shared": "data-shared",
            "neighbours": "between", "neighbour_guess": "guess", "none": "none", "class": "class"}
MAX_DATA_REFS = 8


def write_json(items, path, cov):
    """One line per item. Alignment padding after an item is folded into it as `pad`; section, layer and
    opacity follow from the address and config/splits.json (written only where they don't)."""
    keys = ["addr", "size", "pad", "kind", "name", "type", "source_type", "cls", "slots", "vfptr_offset",
            "object", "layer", "owner_by", "shared_objects", "referenced", "pointers", "source_names",
            "interior", "flags", "xrefs", "data_refs", "data_refs_n"]
    rows = []
    for it in items:
        if it["kind"] == "padding" and rows and rows[-1]["section"] == it["section"]:
            rows[-1]["pad"] = rows[-1].get("pad", 0) + it["size"]
            continue
        rows.append(dict(it))
    with open(path, "w") as f:
        f.write('{"comment": "Data inventory of .rdata/.data/.bss (tools/data_inventory.py, docs/data.md). Addresses, '
                'sizes, kinds, names, types, owners and references only: no game bytes or string text.",\n')
        f.write(' "coverage": %s,\n "items": [\n' % json.dumps(cov, sort_keys=False))
        for j, it in enumerate(rows):
            if it["kind"] != "vtable":
                it.pop("cls", None)
            if it["kind"] in CODE_OWNED:
                # compiler-generated from the class (build/rtti.json has the structure): name, owner, xrefs
                it.pop("type", None)
                if it["kind"] != "vtable":
                    it.pop("data_refs", None)
                if not it.get("vfptr_offset"):
                    it.pop("vfptr_offset", None)
            if it.get("object") is not None:
                it.pop("layer", None)
            if it.get("referenced") is not False:
                it.pop("referenced", None)
            it["owner_by"] = OWNER_BY.get(it.get("owner_by"), it.get("owner_by"))
            dr = it.get("data_refs", [])
            if len(dr) > MAX_DATA_REFS:
                it["data_refs"], it["data_refs_n"] = dr[:MAX_DATA_REFS], len(dr)
            d = {}
            for k in keys:
                if k not in it or (it[k] in (None, [], "") and k != "object"):
                    continue
                v = it[k]
                if k == "addr":
                    v = "0x%08x" % v
                elif k in ("xrefs", "data_refs", "interior"):
                    v = ["0x%x" % x for x in v]
                d[k] = v
            if it["section"] in OPAQUE_SECTIONS:
                d["section"] = it["section"]
            f.write("  " + json.dumps(d, separators=(",", ":")) + (",\n" if j + 1 < len(rows) else "\n"))
        f.write(" ]\n}\n")


def section_of(a):
    if 0x3f2be0 <= a < 0x48ca80:
        return ".rdata"
    if 0x48ca80 <= a < 0x48ca80 + 0x4f56c:
        return ".data"
    if 0x48ca80 + 0x4f56c <= a < 0x48ca80 + 0xe2e60:
        return ".bss"
    return None


def load_inventory(path=OUT, objects=None):
    """config/data.json with section, layer and opaque filled in (padding stays folded in `pad`)."""
    d = json.load(open(path))
    layer = {o["file"]: o.get("layer", "game") for o in (objects or load_objects())}
    for it in d["items"]:
        it["addr"] = int(it["addr"], 16)
        it["section"] = it.get("section") or section_of(it["addr"])
        for k in ("xrefs", "data_refs", "interior"):
            it[k] = [int(x, 16) for x in it.get(k, [])]
        it.setdefault("pad", 0)
        it["layer"] = it.get("layer") or layer.get(it.get("object"), "unknown")
        it["opaque"] = it["layer"] == "library"
    return d


def generate(fresh=False):
    """(items, coverage) of the inventory from its inputs (module docstring)."""
    inv = Inventory()
    xr = code_xrefs(inv.xbe, inv.funcs, inv.lo, inv.hi, fresh)
    src = source_names()
    src_off, n_objs = load_source_offsets()
    inv.place_fixed()
    starts = inv.collect_starts(xr, src, src_off)
    inv.set_source_types(src)
    inv.carve(starts)
    items = inv.finish(src)
    # sanity: items tile [lo, hi) exactly
    pos = inv.lo
    for it in items:
        assert it["addr"] == pos, ("gap/overlap at %#x (item %#x %s)" % (pos, it["addr"], it["kind"]))
        pos += it["size"]
    assert pos == inv.hi, hex(pos)
    for it in items:
        it.setdefault("section", inv.sec_name(it["addr"]))
    items += opaque_sections(inv.xbe)
    cov = coverage(items)
    cov["source_offsets"] = len(src_off)
    cov["source_offsets_objects"] = n_objs
    cov["records"] = len(inv.records)
    cov["pinned_items"] = len(inv.pins)
    return items, cov


# the fields of config/data.json that tools/data_gen.py reads (the data TUs and include/decls/data/ follow from them):
# --check fails when one of them differs. `source_type` counts only where it changes data_gen's scalar type (its
# fallback when `type` gives none), and `interior` on vftables and RTTI structures (tools/wine_link.py labels those
# addresses). The rest (source_names, source_type otherwise, owner_by, shared_objects, flags,
# xrefs, data_refs, interior, referenced, pointers, cls/slots/vfptr_offset, the coverage line) is informational:
# reported as warnings (--exact fails on them too).
CHECKED_FIELDS = ("size", "pad", "kind", "name", "type", "object", "layer", "section")


def _data_gen_scalar(row):
    import data_gen  # noqa: E402  (imports this module; loaded only for --check)
    it = dict(row)
    it["size"] = it.get("size", 0)
    return data_gen.scalar_type(it)


def check(items, cov, path=None, show=20, exact=False):
    """0 when PATH holds what the inputs give in every field data_gen reads (CHECKED_FIELDS), else 1 with a summary
    of the items that differ; differences in the informational fields are printed as warnings (EXACT: they fail too)."""
    import tempfile
    with tempfile.NamedTemporaryFile("w", suffix=".json", delete=False) as t:
        tmp = t.name
    try:
        write_json(items, tmp, cov)
        with open(tmp) as f, open(path or OUT) as g:
            new, old = f.read(), g.read()
    finally:
        os.unlink(tmp)
    if new == old:
        print("config/data.json is reproducible from its inputs (%d lines)" % new.count("\n"))
        return 0
    def rows(text):
        return {d["addr"]: d for d in (json.loads(l.strip().rstrip(",")) for l in text.splitlines()
                                       if l.lstrip().startswith('{"addr":'))}
    def cov_line(text):
        return next((l for l in text.splitlines() if l.lstrip().startswith('"coverage"')), None)
    a, b = rows(old), rows(new)
    errs, warns = collections.Counter(), collections.Counter()
    bad, info = [], []
    for k in sorted(set(a) | set(b)):
        if a.get(k) == b.get(k):
            continue
        if k not in a or k not in b:
            errs["only in the %s" % ("regenerated" if k in b else "committed")] += 1
            bad.append(k)
            continue
        hard = False
        for f in sorted(set(a[k]) | set(b[k])):
            if a[k].get(f) == b[k].get(f):
                continue
            if f in CHECKED_FIELDS or (f == "source_type" and _data_gen_scalar(a[k]) != _data_gen_scalar(b[k])) or \
                    (f == "interior" and a[k]["kind"] in CODE_OWNED):
                errs[f] += 1
                hard = True
            else:
                warns[f] += 1
        (bad if hard else info).append(k)
    if cov_line(old) != cov_line(new):
        warns["coverage line"] += 1
    if exact:
        errs.update(warns)
        bad, info, warns = sorted(bad + info), [], collections.Counter()
    def show_rows(keys):
        for k in keys[:show]:
            print("  %s\n    committed:   %s\n    regenerated: %s" % (k, json.dumps(a.get(k))[:300],
                                                                    json.dumps(b.get(k))[:300]))
    if warns:
        print("warning: config/data.json differs from its inputs in informational fields only data_gen does not read "
              "(%d item(s)); regenerate to refresh them:" % len(info))
        for f, n in warns.most_common():
            print("  %-28s %d" % (f, n))
        show_rows(info if not errs else [])
    if not errs:
        print("config/data.json is reproducible from its inputs in the fields data_gen reads (%d lines)"
              % new.count("\n"))
        return 0
    print("config/data.json is NOT reproducible from its inputs: %s" % (
        "%d item(s) differ" % len(bad) if bad else "the coverage line differs"))
    for f, n in errs.most_common():
        print("  %-28s %d" % (f, n))
    show_rows(bad)
    print("Regenerate with tools/data_inventory.py (then tools/data_gen.py; docs/data.md \"Reproducing\"), or fix the "
          "input that moved.")
    return 1


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--report", action="store_true", help="print the coverage table")
    ap.add_argument("--fresh", action="store_true", help="re-disassemble (ignore build/data/code_xrefs.json)")
    ap.add_argument("--check", action="store_true",
                    help="regenerate in memory and compare with config/data.json: exit 1 when a field data_gen reads "
                    "differs (the others are warnings)")
    ap.add_argument("--exact", action="store_true", help="with --check: fail on any difference, informational "
                    "fields and the coverage line included")
    ap.add_argument("--refresh-offsets", action="store_true",
                    help="re-read config/data-source-offsets.json from the merged tree's MSVC objects first")
    ap.add_argument("--compile", action="store_true", help="with --refresh-offsets: compile tree TUs without an "
                    "object (MSVC: run it as a queue job)")
    a = ap.parse_args(argv)
    if a.refresh_offsets:
        off, n = refresh_source_offsets(compile_missing=a.compile)
        print("source offsets: %d from %d objects -> %s" % (len(off), n, os.path.relpath(SRC_OFFSETS, ROOT)))
    items, cov = generate(a.fresh)
    if a.check:
        return check(items, cov, exact=a.exact)
    write_json(items, OUT, cov)
    os.makedirs(WORK, exist_ok=True)
    json.dump(cov, open(os.path.join(WORK, "inventory-report.json"), "w"), indent=1)
    print("items: %d -> %s" % (len(items), os.path.relpath(OUT, ROOT)))
    if a.report:
        print(json.dumps(cov, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
