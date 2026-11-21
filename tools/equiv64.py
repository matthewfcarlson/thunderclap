#!/usr/bin/env python3
"""64-bit equivalence check (eq64): does the x86-64 object of a source behave like its 32-bit clang object?

  build/venv/bin/python tools/equiv.py SRC 0xADDR --x64 [--inputs N] [--json]
  build/venv/bin/python tools/equiv64.py SRC 0xADDR [--inputs N] [--json] [--seeds 3,7] [--verbose]
  build/venv/bin/python tools/equiv64.py batch LIST OUT.jsonl [--name ME] [-- --inputs 200]   # through the job queue

Design (docs/equivalence.md "64-bit check (--x64)"): the chain is original == Wine object (equiv.py --wine, the
promotion gate) and Wine object == x64 object (this). Both objects come from the same source through the same clang
front end (the tree's native spelling, compat/native.h, MS C++ ABI), so they share every declaration; what differs is
the target: 8-byte pointers, the record layouts that follow from them, the Win64 calling convention and SSE-only
float code. Both run in Unicorn (UC_MODE_32 / UC_MODE_64) from one *typed* input: memory is a graph of objects whose
types come from the source (libclang, one parse per target), generated once as abstract values and laid out twice,
once per target's record layout. Calls to functions the object doesn't define are stubs that record the call and
return the same abstract value on both sides. Everything observed (calls and their arguments, the return value, the
final contents of every object either side wrote) is decoded through the same types back to abstract values
(pointers as object + 32-bit offset) and compared exactly. Nothing is compared by byte offset where a type says what
is there; bytes nobody typed (pads, `char` buffers, raw allocations) map one to one.

Differences are classified (`class`): layout (an access the 64-bit layout puts elsewhere: a read or write past an
object's 64-bit end, a pointer kept in 4 bytes), ptrtrunc (a pointer truncated to 32 bits), untyped (through memory
no type describes: a void* or raw allocation the code casts), float (float values that differ: rounding,
transcendentals, float->int overflow), int (integer values), call (a different callee sequence), crash64 / hang64
(the 64-bit run faults or runs away where the 32-bit run returned) and tool (a gap of this checker).
"""
import argparse
import bisect
import contextlib
import ctypes
import hashlib
import json
import math
import os
import re
import struct
import subprocess
import sys
import tempfile
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import clang_probe as cp  # noqa: E402

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
PAGE = 0x1000
M32 = 0xFFFFFFFF
M64 = 0xFFFFFFFFFFFFFFFF

# ------------------------------------------------------------------------------------------------- address spaces
# Both sides use the same low layout; only the heap differs (above 4 GB on 64-bit, as on arm64 macOS, so a pointer
# kept in 32 bits never works by accident).
CODE = 0x60000000                   # our object's sections
STUBS = 0x5F000000                  # one 16-byte slot per stubbed function (within rel32 reach of CODE)
STUB_SLOTS = 0x10000
GLOBALS = 0x50000000                # extern data symbols (rel32 reach on x64), vtables
STACK_LO, STACK_HI = 0x0E000000, 0x0F000000
ENTRY_SP = STACK_HI - 0x10000
GSLOT, GSLOTS = 0x10000, 0xE00         # global objects: 64 KB slots in GLOBALS..GLOBALS+0x0E000000 (Heap.get)
SENTINEL = STUBS - 0x1000           # return address of the function under test
GDT32, TIB32 = 0x5EFE0000, 0x5EFD0000   # i386: fs:[0] is the SEH chain (clang's EH frames register there)
FSLOT = SENTINEL + 0x100            # float result of a 32-bit stub (loaded by its thunk)
HEAP32 = 0x23450000                 # (an odd base: round integers like 0x20000000 are not addresses)
HEAP64 = 0x712340000             # (its low 32 bits, 0x12340000+, mark a truncated pointer)
HEAP32_SPAN = 0x20000000            # (ADDR_RANGES32) the 32-bit heap: HEAP32 .. 0x43450000
# (rev1) `rawint` (compare) and the truncated-pointer test rely on a 64-bit heap address's low 32 bits (0x1234xxxx)
# never being a 32-bit heap address: the 64-bit heap may grow by at most this much (Heap._region enforces both bounds)
HEAP64_SPAN = HEAP32 - (HEAP64 & 0xFFFFFFFF)
assert (HEAP64 & 0xFFFFFFFF) + HEAP64_SPAN <= HEAP32 and HEAP32 + HEAP32_SPAN <= 0x50000000
NULL_HI = 0x10000                   # 0..0xFFFF reads as zero on both sides
KMAX = 16                           # elements per typed object (p[i] for small i stays typed)
COUNT_MAX = 1024                    # (integ4, x64bounds; rev5) a HULK_COUNT array's elements at most ...
COUNT_BYTES = 1 << 20               # ... and bytes (each target's): past either the input is set aside (count_cap)
RAW_SIZE = 0x1000

STEPS = int(os.environ.get("EQ64_STEPS", "1000000"))
# (integ3, workclock) the input loop's budget is counted in work: WORK_RUN units per emulator run plus WORK_HOOK per hook
# call (memory, stubs, the function's blocks; a fit of CPU time on mac2/studio over 64 tree blocks), at WORK_PER_SEC
# units to a budget second, so a host's speed never changes which inputs a check ran; CPU time is only a safety cap
# (WALL_CAP times the budget, marked `time_cut_wall`)
WORKN = {"runs": 0, "hooks": 0}
WORK_RUN, WORK_HOOK = 2640, 1.18          # (microseconds on the reference hosts)
WORK_PER_SEC = float(os.environ.get("EQ64_WORK_PER_SEC", "0") or 0) or 1.0e6


def _work():
    return WORK_RUN * WORKN["runs"] + WORK_HOOK * WORKN["hooks"]
WALL_CAP = float(os.environ.get("EQUIV_WALL_CAP", "8"))
RUN_TIMEOUT = int(float(os.environ.get("EQ64_RUN_SECONDS", "30")) * 1e6)    # per run (us); a longer run counts as a hang
OFF = set(os.environ.get("EQ64_OFF", "").split(","))
# (merge-once) while a tree TU is checked: the TU's other verified functions (MSVC symbols, tools/tree_tu.py records).
# They are separate functions of the original, stubbed as when the function is checked from its own source (where they
# are declared, not defined), never run in place as part of ours (equiv.py's TREE_EXTERNAL)
TREE_EXTERNAL = set()
TREE_ACTIVE = []        # (merge-once) the address under test while a tree TU is checked
TREE_PINNED = set()     # (merge-once) the pinned globals the function's block reads through a view (Checker.pinned_views)
PIN_VIEW = re.compile(r"^#define (\w+) \(\*\(.+ \*\)&::\1\)\s*$")
TREE_NS = re.compile(r"@fn_f?[0-9a-f]{7,8}(?=@)")


def rng_key(key):
    """(build6) A stub's key as its random stream's seed: without the declaration's position (`decl:FILE:LINE:COL:f` ->
    `decl:f`) or the tree's namespaces, so the same callee draws the same values whether the function is checked from
    its own source or from its TU, where the declaration sits elsewhere. EQ64_OFF=rngloc: the key as it is."""
    if "rngloc" in OFF or not isinstance(key, str):
        return repr(key)
    m = re.match(r"^decl:[^:]*:\d+:\d+:(.*)$", key)
    if m:
        key = "decl:" + m.group(1)
    return repr(TREE_NS.sub("", key))


def untree(name):
    """(merge-once) NAME without the tree's namespaces (fn_<addr> of a wrapped block, fn_f<7 hex> of a TU), while a tree
    TU is checked: `?FUN_0008d690@fn_f62c01b9@@YAPAXI@Z` is the allocator `?FUN_0008d690@@YAPAXI@Z`."""
    if not TREE_ACTIVE or not name or "treens" in OFF:
        return name
    return TREE_NS.sub("", name)


class Unsupported(Exception):
    """A construct this checker can't model (reported as status `unsupported`, class `tool`, or CLS when given)."""

    def __init__(self, msg="", cls="tool"):
        super().__init__(msg)
        self.cls = cls


class CompileError(Exception):
    pass


def h64(*parts):
    """Deterministic 64-bit hash of a tuple of ints/strings (Python's hash() of str is salted per process)."""
    return int.from_bytes(hashlib.blake2b(repr(parts).encode(), digest_size=8).digest(), "little")


class Rng:
    """splitmix64 stream seeded from h64(parts)."""
    __slots__ = ("s",)

    def __init__(self, *parts):
        self.s = h64(*parts)

    def next(self):
        self.s = (self.s + 0x9E3779B97F4A7C15) & M64
        z = self.s
        z = ((z ^ (z >> 30)) * 0xBF58476D1CE4E5B9) & M64
        z = ((z ^ (z >> 27)) * 0x94D049BB133111EB) & M64
        return z ^ (z >> 31)

    def below(self, n):
        return self.next() % n

    def unit(self):
        return (self.next() >> 11) / float(1 << 53)


# ------------------------------------------------------------------------------------------------- compile
def prepared_text(src):
    """SRC in the tree's native spelling (tools/gen_tree.py: size_t, operator new) behind the tree prelude: what the
    native builds compile. The 32-bit reference is compiled from the same text."""
    import gen_tree
    text = open(src, errors="replace").read()
    text = gen_tree.crt_guard_text(gen_tree.native_spelling(text))
    return '#include "tree_prelude.h"\n#line 1 "%s"\n%s' % (os.path.abspath(src).replace("\\", "/"), text)


def write_wrapper(src, d):
    import gen_tree
    with open(os.path.join(d, "tree_prelude.h"), "w") as f:
        f.write("\n".join(gen_tree.PRELUDE_LINES) + "\n")
    w = os.path.join(d, "eq64_src.cpp")
    with open(w, "w") as f:
        f.write(prepared_text(src))
    return w


def front_flags(target):
    """The native front end (tools/native_mac.py FRONT) for TARGET, as an object compile."""
    return ["--target=" + target, "-fms-extensions", "-fms-compatibility", "-fms-compatibility-version=13.10",
            "-std=c++14", "-O0", "-fno-exceptions"] + cp.NATIVE + ["-fcheck-new", "-ffp-eval-method=double", "-ffp-contract=off"]


def tree_inc():
    """(merge-once) -I the tree's include/ while a tree TU is checked (tools/tree_tu.py)."""
    import tree_tu
    return tree_tu.clang_include_flags()


def clangxx():
    c = cp.tool("clang++")
    if not c:
        raise CompileError("eq64 needs LLVM's clang++ (clang_probe.tool)")
    return c


def compile64(wrapper, d):
    """x86_64-pc-windows-msvc object + the vftable dump (slot -> method) of every class whose layout codegen used."""
    obj = os.path.join(d, "x64.obj")
    cmd = [clangxx()] + front_flags("x86_64-pc-windows-msvc") + [
        "-c", "-w", "-Xclang", "-fdump-vtable-layouts", "-I" + d] + tree_inc() + ["-I" + os.path.join(ROOT, "include"), wrapper, "-o", obj]
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace", timeout=600)
    if r.returncode:
        raise CompileError((r.stderr or "")[-1500:])
    return obj, r.stdout


def compile32(wrapper, d):
    """The Wine build's object (equiv.compile_native: i686, SSE + clang_probe's IR passes, x87-keep list)."""
    import equiv
    try:
        return equiv.compile_native(wrapper, d, ["-I" + d])
    except equiv.CompileError as e:
        raise CompileError(str(e))


# ------------------------------------------------------------------------------------------------- COFF loading
def load_obj(path):
    import equiv
    return equiv.Obj(path)


class Image:
    """One object linked at CODE: section addresses, defined symbols, relocations still to resolve."""

    def __init__(self, obj, bits):
        self.obj, self.bits = obj, bits
        self.secaddr = {}
        a = CODE
        import equiv
        for i, s in enumerate(obj.sections):
            if not equiv._linkable(s):
                continue
            al = 16
            a = (a + al - 1) & ~(al - 1)
            self.secaddr[i + 1] = a
            a += max(s["size"], 1)
        self.end = (a + PAGE - 1) & ~(PAGE - 1)
        self.defined = {}       # name -> address
        self.symsec = []        # (addr, end, name) of defined data/function symbols, for decoding addresses
        for idx, (name, value, secnum, typ, cls) in obj.syms.items():
            if secnum > 0 and secnum in self.secaddr and cls in (2, 3, 6) and not name.startswith(("$", ".")):
                if cls == 3 and value == 0 and name.startswith("."):
                    continue
                self.defined.setdefault(name, self.secaddr[secnum] + value)
        self.funcs = {}
        for name, value, secnum, typ, cls in obj.functions():
            if secnum in self.secaddr:
                self.funcs[name] = self.secaddr[secnum] + value
        self.ext_names = set()     # (merge-once) defined functions bound as undefined ones (Checker.tree_externalize)
        self.undef = sorted({obj.syms[si][0] for s in obj.sections for va, si, t in s["relocs"]
                             if si in obj.syms and obj.syms[si][2] == 0 and obj.syms[si][4] in (2, 105)})
        byaddr = sorted((a_, n_) for n_, a_ in self.defined.items())
        self.sym_starts = [a_ for a_, _ in byaddr]
        self.sym_names = [n_ for _, n_ in byaddr]

    def externalize(self, names):
        """(merge-once) Bind references to the defined functions NAMES as references to undefined ones (stubs)."""
        names = set(names) & set(self.funcs)
        refd = {self.obj.syms[si][0] for s in self.obj.sections for va, si, t in s["relocs"] if si in self.obj.syms}
        self.ext_names = names
        self.undef = sorted(set(self.undef) | (names & refd))

    def func_range(self, name):
        import equiv
        for s in self.obj.functions():
            if s[0] == name:
                secnum, lo, hi = equiv.Obj.func_extent(self.obj, s)
                return self.secaddr[secnum] + lo, self.secaddr[secnum] + hi
        return None

    def build(self, resolve):
        """Section bytes with relocations applied; resolve(name) -> address for undefined symbols."""
        out = bytearray(self.end - CODE)
        for i, s in enumerate(self.obj.sections):
            sn = i + 1
            if sn not in self.secaddr or not s["raw"] or s["flags"] & 0x80:   # .bss stays zero
                continue
            base = self.secaddr[sn] - CODE
            out[base:base + s["size"]] = s["raw"]
        for i, s in enumerate(self.obj.sections):
            sn = i + 1
            if sn not in self.secaddr:
                continue
            base = self.secaddr[sn]
            for va, si, typ in s["relocs"]:
                name, value, secnum, _, cls = self.obj.syms[si]
                if secnum > 0 and name not in self.ext_names:
                    if secnum not in self.secaddr:
                        continue
                    S = self.secaddr[secnum] + value
                else:
                    S = resolve(name)
                P = base + va
                o = P - CODE
                self._apply(out, o, P, S, typ, name)
        return bytes(out)

    def _apply(self, out, o, P, S, typ, name):
        if self.bits == 32:
            if typ == 0x06:     # DIR32
                v, = struct.unpack_from("<I", out, o)
                struct.pack_into("<I", out, o, (v + S) & M32)
            elif typ == 0x07:   # DIR32NB
                v, = struct.unpack_from("<I", out, o)
                struct.pack_into("<I", out, o, (v + S - CODE) & M32)
            elif typ == 0x14:   # REL32
                v, = struct.unpack_from("<i", out, o)
                struct.pack_into("<I", out, o, (v + S - (P + 4)) & M32)
            elif typ in (0x0A, 0x0B, 0x00):   # SECTION, SECREL, ABSOLUTE: debug/EH only
                pass
            else:
                raise Unsupported("i386 relocation type 0x%x (%s)" % (typ, name))
        else:
            if typ == 0x01:     # ADDR64
                v, = struct.unpack_from("<Q", out, o)
                struct.pack_into("<Q", out, o, (v + S) & M64)
            elif typ == 0x02:   # ADDR32
                v, = struct.unpack_from("<I", out, o)
                struct.pack_into("<I", out, o, (v + S) & M32)
            elif typ == 0x03:   # ADDR32NB
                v, = struct.unpack_from("<I", out, o)
                struct.pack_into("<I", out, o, (v + S - CODE) & M32)
            elif 0x04 <= typ <= 0x09:   # REL32, REL32_1..5
                v, = struct.unpack_from("<i", out, o)
                d = S - (P + 4 + (typ - 4))
                if not -0x80000000 <= v + d < 0x80000000:
                    raise Unsupported("rel32 out of range to %s" % name)
                struct.pack_into("<i", out, o, v + d)
            elif typ in (0x0A, 0x0B, 0x00):
                pass
            else:
                raise Unsupported("amd64 relocation type 0x%x (%s)" % (typ, name))

    def sym_at(self, a):
        i = bisect.bisect_right(self.sym_starts, a) - 1
        if i < 0:
            return None, 0
        return self.sym_names[i], a - self.sym_starts[i]


# ------------------------------------------------------------------------------------------------- types (libclang)
_CI = None


def ci():
    global _CI
    if _CI is None:
        try:
            import clang.cindex as m
        except ImportError:
            # a queue host whose venv lacks libclang's Python binding: the copy job_files() shipped with the job
            sys.path.insert(0, os.path.join(ROOT, PYLIB))
            import clang.cindex as m
        lib = None
        for d in [os.path.join(os.path.dirname(cp.LLVM), "lib")] + [os.path.join(os.path.dirname(x), "lib") for x in cp.LLVMS]:
            p = os.path.join(d, "libclang.dylib" if sys.platform == "darwin" else "libclang.so")
            if os.path.exists(p):
                lib = p
                break
        if lib and not m.Config.loaded:
            m.Config.set_library_file(lib)
        _CI = m
        f = m.conf.lib.clang_getFunctionTypeCallingConv
        f.argtypes = [m.Type]
        f.restype = ctypes.c_int
    return _CI


CC_C, CC_STD, CC_FAST, CC_THIS = 1, 2, 3, 4
PYLIB = "jobsrc/eq64-pylib"     # (a job workspace path outside build/, which is a symlink on the hosts)


def job_files():
    """{workspace path: [sha, mode]} for tools/jobq.py: this venv's libclang Python binding (`pip install clang`,
    docs/toolchain.md), for queue hosts whose venv doesn't have it (loaded from PYLIB only when the import fails)."""
    import importlib.util
    import jobq
    spec = importlib.util.find_spec("clang")
    if spec is None or not spec.submodule_search_locations:
        return {}
    d = list(spec.submodule_search_locations)[0]
    out = {}
    for f in sorted(os.listdir(d)):
        if f.endswith(".py"):
            out["%s/clang/%s" % (PYLIB, f)] = [jobq.store_file(os.path.join(d, f)), 0o644]
    return out


_MANGLINGS = None


def cxx_manglings(c):
    """Every mangled name of a constructor or destructor (libclang's mangled_name gives one variant only)."""
    global _MANGLINGS
    m = ci()
    if _MANGLINGS is None:
        class StringSet(ctypes.Structure):
            _fields_ = [("strings", ctypes.POINTER(m._CXString)), ("count", ctypes.c_uint)]
        f = m.conf.lib.clang_Cursor_getCXXManglings
        f.argtypes = [m.Cursor]
        f.restype = ctypes.POINTER(StringSet)
        dsp = m.conf.lib.clang_disposeStringSet
        dsp.argtypes = [ctypes.POINTER(StringSet)]
        _MANGLINGS = (f, m.conf.lib.clang_getCString, dsp)
    f, g, dsp = _MANGLINGS
    ss = f(c)
    if not ss:
        return []
    out = [ss.contents.strings[i].spelling.decode() for i in range(ss.contents.count)]
    # (not disposed: clang_disposeStringSet aborts through this binding; a few strings per TU)
    return out

INT_KINDS = {"BOOL": False, "CHAR_U": False, "UCHAR": False, "CHAR16": False, "CHAR32": False, "USHORT": False,
             "UINT": False, "ULONG": False, "ULONGLONG": False, "UINT128": False, "CHAR_S": True, "SCHAR": True,
             "WCHAR": False, "SHORT": True, "INT": True, "LONG": True, "LONGLONG": True, "INT128": True}


def rdecl(t):
    """The defining declaration of a record type (get_declaration can be a forward declaration)."""
    d = t.get_canonical().get_declaration()
    df = d.get_definition()
    return df if df is not None else d


def loc_key(c):
    """Target-independent identity of a declaration: where its first declaration is in the source."""
    c = c.canonical
    l = c.location
    return "%s:%d:%d:%s" % (os.path.basename(l.file.name) if l.file else "?", l.line, l.column, c.spelling)


class TU:
    """One libclang parse of the prepared source for one target."""

    def __init__(self, wrapper, d, target, bits):
        m = ci()
        self.bits, self.ptr = bits, bits // 8
        args = [a for a in front_flags(target) if a not in ("-O0",)] + ["-w", "-DHULK_EQ64_PARSE", "-I" + d] + tree_inc() + \
            ["-I" + os.path.join(ROOT, "include")]
        self.tu = m.Index.create().parse(wrapper, args=args)
        errs = [str(x) for x in self.tu.diagnostics if x.severity >= 3]
        if errs:
            raise CompileError("libclang: " + "; ".join(errs[:3]))
        self.by_mangled = {}
        self.records = {}       # record spelling (no spaces) -> definition cursor
        self._walk(self.tu.cursor, 0)

    def record(self, name):
        """The definition of record NAME (canonical spelling, no spaces), including implicit template
        instantiations the source uses (found through the types of its expressions and declarations, once)."""
        r = self.records.get(name)
        if r is not None or getattr(self, "_inst_done", False):
            return r
        self._inst_done = True
        for c in self.tu.cursor.walk_preorder():
            try:
                t = c.type
            except Exception:   # noqa: BLE001
                continue
            for _ in range(4):
                if t is None or t.kind.name == "INVALID":
                    break
                tc = t.get_canonical()
                if tc.kind.name in ("POINTER", "LVALUEREFERENCE"):
                    t = tc.get_pointee()
                    continue
                if tc.kind.name == "RECORD":
                    d = tc.get_declaration()
                    if d is not None and d.is_definition():
                        self.records.setdefault(tc.spelling.replace(" ", ""), d)
                break
        return self.records.get(name)

    def _walk(self, c, depth, templ=False):
        K = ci().CursorKind
        for ch in c.get_children():
            k = ch.kind
            if k in (K.FUNCTION_DECL, K.CXX_METHOD, K.CONSTRUCTOR, K.DESTRUCTOR, K.VAR_DECL, K.CONVERSION_FUNCTION):
                try:
                    mn = ch.mangled_name
                except Exception:   # noqa: BLE001
                    mn = None
                names = [mn] if mn else []
                if k in (K.CONSTRUCTOR, K.DESTRUCTOR) and not templ and mn:
                    names += cxx_manglings(ch)     # (never inside a template: libclang crashes on dependent ones)
                for mn in names:
                    self.by_mangled.setdefault(mn, ch)
                    if self.bits == 32 and not mn.startswith("?"):
                        self.by_mangled.setdefault("_" + mn, ch)
                    if mn.startswith("_") and self.bits == 32 and "@" in mn and not mn.startswith("?"):
                        self.by_mangled.setdefault(mn, ch)
            if k in (K.NAMESPACE, K.LINKAGE_SPEC, K.UNEXPOSED_DECL):
                self._walk(ch, depth + 1, templ)
            elif k in (K.CLASS_DECL, K.STRUCT_DECL, K.UNION_DECL, K.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION) or \
                    k.name == "CLASS_TEMPLATE":
                if ch.is_definition() and k.name != "CLASS_TEMPLATE":
                    self.records.setdefault(ch.type.get_canonical().spelling.replace(" ", ""), ch)
                self._walk(ch, depth + 1, templ or k.name in ("CLASS_TEMPLATE", "CLASS_TEMPLATE_PARTIAL_SPECIALIZATION"))


# leaf kinds whose bytes are the same on both targets when their sizes agree: a pointer into the middle of one (a byte
# offset into an `unsigned` array, `(char*)&i + 1`) is the same place on both
SAME_WIDTH = ("i", "f", "d")


class Leaf:
    __slots__ = ("path", "o32", "o64", "kind", "s32", "s64", "extra", "signed", "range", "cast", "count")

    def __init__(self, path, o32, o64, kind, s32, s64, extra=None, signed=False):
        self.path, self.o32, self.o64, self.kind, self.s32, self.s64 = path, o32, o64, kind, s32, s64
        self.extra, self.signed = extra, signed
        self.range = None       # (x64t13) (lo, hi): the values an integer field takes (HULK_RANGE, field_range)
        self.cast = None        # (integ2, D93) a pointer field's pointee as the code casts it (field_casts)
        self.count = None       # (integ4, x64bounds) a pointer field's array length: (count leaf, element bytes or None)

    def off(self, bits):
        return self.o32 if bits == 32 else self.o64

    def size(self, bits):
        return self.s32 if bits == 32 else self.s64


class Layout:
    """A type laid out on both targets: paired leaves (scalars, pointers, vfptrs, raw byte runs)."""

    def __init__(self, key, size32, size64, leaves, raw=False):
        marks = [l for l in leaves if l.kind == "m"]
        leaves = [l for l in leaves if l.kind != "m"]
        self.key, self.size32, self.size64, self.leaves, self.raw = key, size32, size64, leaves, raw
        self.record = False
        # offsets where a field, base or leaf starts: 64-bit -> 32-bit and back (empty members have no leaf)
        self.m64, self.m32 = {}, {}
        for l in leaves + marks:
            self.m64.setdefault(l.o64, l.o32)
            self.m32.setdefault(l.o32, l.o64)
        self.by32 = sorted(leaves, key=lambda l: l.o32)
        self.by64 = sorted(leaves, key=lambda l: l.o64)
        self.s32 = [l.o32 for l in self.by32]
        self.s64 = [l.o64 for l in self.by64]

    def size(self, bits):
        return self.size32 if bits == 32 else self.size64

    def to32(self, off64):
        """A 64-bit offset (into an array of this type) as the 32-bit offset of the same place, or None."""
        e, r = divmod(off64, self.size64)
        if r in self.m64:
            return e * self.size32 + self.m64[r]
        l = self.leaf_at(64, r)
        if l is not None and (l.kind == "b" or l.kind in SAME_WIDTH and l.s32 == l.s64):
            return e * self.size32 + l.o32 + (r - l.o64)
        return None

    def to64(self, off32):
        e, r = divmod(off32, self.size32)
        if r in self.m32:
            return e * self.size64 + self.m32[r]
        l = self.leaf_at(32, r)
        if l is not None and (l.kind == "b" or l.kind in SAME_WIDTH and l.s32 == l.s64):
            return e * self.size64 + l.o64 + (r - l.o32)
        return None

    def leaf_at(self, bits, off):
        """The leaf covering byte OFF (within one element) on BITS, or None (padding)."""
        starts, lst = (self.s32, self.by32) if bits == 32 else (self.s64, self.by64)
        i = bisect.bisect_right(starts, off) - 1
        while i >= 0:
            l = lst[i]
            if l.off(bits) <= off < l.off(bits) + l.size(bits):
                return l
            if l.off(bits) + max(l.s32, l.s64, 16) < off:
                break
            i -= 1
        return None


RAW = Layout("<raw>", 1, 1, [], raw=True)


def _spell(x):
    """A leaf's extra (pointee types, vftable keys, a member pointer's types) as text."""
    if isinstance(x, (tuple, list)):
        return "(" + ",".join(_spell(y) for y in x) + ")"
    sp = getattr(x, "spelling", None)
    if sp is not None:
        try:
            return x.get_canonical().spelling.replace(" ", "")
        except Exception:   # noqa: BLE001
            return sp.replace(" ", "")
    return repr(x)


RANGE_ATTR = re.compile(r"^hulk_range (-?\d+) (-?\d+)$")
COUNT_ATTR = re.compile(r"^hulk_count (\w+)(?: (\d+))?$")     # (integ4, x64bounds) HULK_COUNT / HULK_COUNT_BYTES


def field_count(c):
    """(integ4, x64bounds) (count field name, element bytes or None) from a pointer field's HULK_COUNT(field) /
    HULK_COUNT_BYTES(field, n) annotation (include/compat/hulk_annot.h): the field points at an array of exactly
    this->field elements (of its pointee type, or of n bytes for a void pointer). None without one."""
    K = ci().CursorKind
    for a in c.get_children():
        if a.kind == K.ANNOTATE_ATTR:
            m = COUNT_ATTR.match(a.spelling or "")
            if m:
                return m.group(1), (int(m.group(2)) if m.group(2) else None)
    return None


def _cites_writers(c):
    """(integ1, rev5) Does the declaration of field C carry a comment naming at least one 0x address (its writer sites)?
    The raw comment libclang attaches, else the source lines of the declaration and the line before it."""
    txt = c.raw_comment or ""
    if not re.search(r"0x[0-9a-fA-F]{5,}", txt):
        try:
            f = c.extent.start.file.name
            lines = open(f, errors="replace").read().split("\n")
            lo, hi = c.extent.start.line - 2, c.extent.end.line
            txt = "\n".join(lines[max(0, lo):hi])
        except Exception:   # noqa: BLE001
            return False
    return bool(re.search(r"(//|/\*).*0x[0-9a-fA-F]{5,}", txt))


def field_range(c):
    """(x64t13) The values an integer field takes, (lo, hi), from its HULK_RANGE(lo, hi) annotation
    (include/decls/data/records.h: `int bucket HULK_RANGE(0, 1);`, an attribute only this checker's libclang parse
    sees, under HULK_EQ64_PARSE). The generator draws the field from that range; nothing compared changes. For
    integers the game only ever stores a few values that the code uses as an index (a list number), where a fuzzed
    value would index outside the object on both runs and the two runs would follow different garbage."""
    K = ci().CursorKind
    for a in c.get_children():
        if a.kind == K.ANNOTATE_ATTR:
            m = RANGE_ATTR.match(a.spelling or "")
            if m:
                return int(m.group(1)), int(m.group(2))
    return None


def layout_fp(lay):
    """(x64t12) A digest of a Layout as the checker uses it: sizes and every leaf (path, offsets, kind, sizes,
    signedness, pointee types)."""
    if lay is RAW or lay.raw:
        return "raw"
    h = hashlib.sha1(("%d %d %d\n" % (lay.size32, lay.size64, lay.record)).encode())
    for l in lay.by32:
        h.update(("%r %d %d %s %d %d %d %s\n" % (l.path, l.o32, l.o64, l.kind, l.s32, l.s64, l.signed,
                                                  _spell(l.extra) if l.extra is not None else "")).encode())
        if l.cast is not None:
            h.update(("cast %s\n" % _spell(l.cast)).encode())     # (integ2, D93/F3) the view the code reads it through
        if l.range is not None:
            h.update(("range %d %d\n" % l.range).encode())
        if l.count is not None:
            h.update(("count %r %s\n" % (l.count[0].path, l.count[1])).encode())     # (integ4, x64bounds)
    return h.hexdigest()[:16]


def _types_by_spelling(tu):
    """{canonical spelling without spaces: type} of every type a cursor of TU has, its pointees, array elements and
    the records TU defines (the types a checker's layout keys can name)."""
    K = ci().TypeKind
    out = {}

    def add(t, depth=0):
        while t is not None and depth < 6:
            try:
                tc = t.get_canonical()
            except Exception:   # noqa: BLE001
                return
            if tc.kind == K.INVALID:
                return
            out.setdefault(tc.spelling.replace(" ", ""), tc)
            if tc.kind in (K.POINTER, K.LVALUEREFERENCE, K.RVALUEREFERENCE):
                t = tc.get_pointee()
            elif tc.kind == K.CONSTANTARRAY:
                t = tc.element_type
            else:
                return
            depth += 1

    for c in tu.tu.cursor.walk_preorder():
        try:
            add(c.type)
        except Exception:   # noqa: BLE001
            continue
    return out


def type_fingerprints(src, keys, field_casts=None):
    """(x64t12) {key: {"k64", "fp"}} of the layouts KEYS ({key: the 64-bit spelling}, as Types.fingerprints() gave
    them) in SRC's current text: the parse a Checker makes, without the objects. A key the source no longer has
    gets fp "missing". (integ2, D93/F3) FIELD_CASTS: the run's [[record, field], [T32, T64 spellings]] (its report's
    `field_casts`), applied as the run applied them (a view the source no longer has: "missing")."""
    import tree_tu
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build") if os.path.isdir(os.path.join(ROOT, "build")) else None) as d:
        ctx = tree_tu.active(src) if src and tree_tu.is_tree_tu(src) else contextlib.nullcontext()
        with ctx:
            w = write_wrapper(src, d)
            t32 = TU(w, d, "i686-pc-windows-msvc", 32)
            t64 = TU(w, d, "x86_64-pc-windows-msvc", 64)
        by32, by64 = _types_by_spelling(t32), _types_by_spelling(t64)
        types = Types(t32, t64, {})
        out = {}
        for (rec, fld), (v32, v64) in (field_casts or []):
            if v32 == AMBIGUOUS:
                types.field_casts[(rec, fld)] = (AMBIGUOUS, AMBIGUOUS)
                continue
            a, b = by32.get(v32), by64.get(v64)
            if a is None or b is None:
                return {k: {"k64": k64, "fp": "missing"} for k, k64 in keys.items()}
            types.field_casts[(rec, fld)] = (a, b)
        for k, k64 in keys.items():
            a, b = by32.get(k), by64.get(k64)
            if a is None or b is None:
                out[k] = {"k64": k64, "fp": "missing"}
                continue
            try:
                lay = types.layout(a, b)
            except Unsupported:
                lay = RAW
            out[k] = {"k64": k64, "fp": layout_fp(lay)}
        return out


class Types:
    """Paired layouts from the two parses (lockstep walk of the same declarations)."""

    def __init__(self, tu32, tu64, vtables):
        self.ranges_used = {}    # (integ1, rev5) {(record, field): (lo, hi)} of the HULK_RANGE annotations used
        self.counts_used = {}    # (integ4, x64bounds) {(record, field): (count field, element bytes)} (HULK_COUNT)
        self.field_casts = {}    # (integ2, D93) {(record, field): (T32, T64)}: the record the code casts a pointer field to
        self.view_trusted = set()   # (integ2, D93) views taken on trust (Types.extend)
        self.view_ambiguous = set()     # (integ2, F5) objects of fields cast to several records (kept as declared)
        self.t = {32: tu32, 64: tu64}
        self.cache = {}
        self.pairs = {}             # (x64t12) key -> (RAW, the 64-bit type's spelling): what fingerprints() reports
        self.vtables = vtables      # parsed -fdump-vtable-layouts

    @staticmethod
    def canon(t):
        return t.get_canonical()

    def key(self, t):
        return self.canon(t).spelling.replace(" ", "")

    def layout(self, t32, t64):
        """Layout of a pointee/value type (Types of both TUs), RAW for void/char/incomplete/function."""
        K = ci().TypeKind
        a, b = self.canon(t32), self.canon(t64)
        k = self.key(a)
        if k not in self.pairs:
            self.pairs[k] = (RAW, self.key(b))
        if k in self.cache:
            return self.cache[k]
        if a.kind in (K.VOID, K.CHAR_S, K.CHAR_U, K.SCHAR, K.UCHAR) or a.get_size() <= 0 or b.get_size() <= 0:
            self.cache[k] = RAW
            return RAW
        leaves = []
        self.cache[k] = RAW     # (recursive types: a pointer to itself is fine, an embedded self is impossible)
        try:
            self._flatten(a, b, 0, 0, (), leaves, a)
        except Unsupported:
            self.cache[k] = RAW
            raise
        lay = Layout(k, a.get_size(), b.get_size(), leaves)
        lay.record = a.kind == K.RECORD
        self.cache[k] = lay
        return lay

    def _derives(self, cast32, decl32):
        """Is the record CAST32 the record DECL32 or derived from it (its bases, transitively)?"""
        K = ci().CursorKind
        want = decl32.get_canonical().spelling
        seen, todo = set(), [cast32.get_canonical()]
        while todo:
            t = todo.pop()
            if t.spelling == want:
                return True
            if t.spelling in seen:
                continue
            seen.add(t.spelling)
            d = rdecl(t)
            if d is None or not d.is_definition():
                continue
            todo.extend(c.type.get_canonical() for c in d.get_children() if c.kind == K.CXX_BASE_SPECIFIER)
        return False

    @staticmethod
    def _gen_record(t):
        """(integ2, F4) Is T a record declared in include/gen/ (RTTI-derived, checked by gen_headers.py --probe)?"""
        d = rdecl(t)
        f = d.location.file.name if d is not None and d.location.file is not None else ""
        return "/include/gen/" in f.replace("\\", "/")

    def extend(self, lay, cast, decl=None):
        """(integ2, D93, fieldcasts; rev5's review) The object a pointer field points at, when the code casts the field
        to another record CAST (`(Result_2aecb0*)builder.image`). LAY: the field's declared pointee (types DECL).
        - CAST a record of include/gen derived from the declared one, a base that lays out words (a real downcast with
          independent evidence: RTTI and gen_headers --probe): CAST, outright.
        - Otherwise (a void / incomplete / placeholder pointee, or an unrelated record): LAY extended by CAST's leaves
          and member starts past LAY's end on both targets, and the view is recorded in `view_trusted`: what the code's
          view says there is taken on trust (rev5's _wrongview: any such view passes), so such a run is no clean
          equivalent (verify64 reports it unsupported, class view_trusted).
        - A view word past LAY's end on one target and inside it on the other: unsupported, class view_straddle (the
          declared type and the view disagree about which words exist; no fallback)."""
        try:
            lc = self.layout(cast[0], cast[1])
        except Unsupported:
            return lay
        if lc.raw or lc is lay:
            return lay
        if decl is not None and not lay.raw and lay.record and lay.leaves and lay.size32 > 1 and \
                self._gen_record(cast[0]) and self._gen_record(cast[1]) and \
                self._derives(cast[0], decl[0]) and self._derives(cast[1], decl[1]):
            # (rev5's re-review, F4) a downcast is taken outright only to a record with evidence of its own: a class of
            # include/gen (RTTI and the probe check its vftables, slots and sizeof), from a base that lays out words
            return lc
        s32, s64 = (0, 0) if lay.raw else (lay.size32, lay.size64)
        if any((l.o32 >= s32) != (l.o64 >= s64) for l in lc.leaves) or \
                any((o32 >= s32) != (o64 >= s64) for o64, o32 in lc.m64.items()):
            raise Unsupported("view_straddle: %s read through %s: a view word lies past the declared type's end on one "
                              "target and inside it on the other" % (lay.key, lc.key), cls="view_straddle")
        extra = [l for l in lc.leaves if l.o32 >= s32 and l.o64 >= s64]
        # (the view's member starts too: an empty member or a struct of raw bytes has no scalar leaf of its own)
        extra += [Leaf(("view", o64), o32, o64, "m", 0, 0) for o64, o32 in sorted(lc.m64.items())
                  if o32 >= s32 and o64 >= s64]
        if not [l for l in extra if l.kind != "m"] and not any(l.kind == "m" and l.o64 for l in extra):
            return lay
        self.view_trusted.add("%s as %s" % (lay.key, lc.key))
        k = "%s+view(%s)" % (lay.key, lc.key)
        if k in self.cache:
            return self.cache[k]
        nl = Layout(k, max(s32, lc.size32), max(s64, lc.size64), ([] if lay.raw else list(lay.leaves)) + extra)
        nl.record = True
        self.cache[k] = nl
        return nl

    def _flatten(self, a, b, o32, o64, path, out, mdr):
        K = ci().TypeKind
        a, b = self.canon(a), self.canon(b)
        ka = a.kind
        if ka != b.kind and ka.name in INT_KINDS and b.kind.name in INT_KINDS:
            # hulk_intptr / size_t / ptrdiff_t: an integer of pointer width on each target
            out.append(Leaf(path, o32, o64, "i", a.get_size(), b.get_size(), signed=INT_KINDS[ka.name]))
            return
        if ka != b.kind:
            raise Unsupported("type kind differs between targets: %s / %s" % (a.spelling, b.spelling))
        if len(out) > 20000:
            raise Unsupported("type too large: %s" % a.spelling)
        if ka in (K.POINTER, K.LVALUEREFERENCE, K.RVALUEREFERENCE):
            pa, pb = self.canon(a.get_pointee()), self.canon(b.get_pointee())
            if pa.kind in (K.FUNCTIONPROTO, K.FUNCTIONNOPROTO):
                out.append(Leaf(path, o32, o64, "fp", a.get_size(), b.get_size(), (pa, pb)))
            else:
                out.append(Leaf(path, o32, o64, "p", a.get_size(), b.get_size(), (pa, pb)))
        elif ka == K.RECORD:
            self._record(a, b, o32, o64, path, out, mdr)
        elif ka == K.CONSTANTARRAY:
            ea, eb = a.element_type, b.element_type
            n = a.element_count
            sa, sb = self.canon(ea).get_size(), self.canon(eb).get_size()
            if self.canon(ea).kind in (K.CHAR_S, K.CHAR_U, K.SCHAR, K.UCHAR):
                if n > 0:
                    out.append(Leaf(path, o32, o64, "b", n, n))
                return
            for i in range(n):
                self._flatten(ea, eb, o32 + i * sa, o64 + i * sb, path + (i,), out, None)
        elif ka in (K.INCOMPLETEARRAY, K.VARIABLEARRAY, K.DEPENDENTSIZEDARRAY):
            return
        elif ka == K.ENUM:
            out.append(Leaf(path, o32, o64, "i", a.get_size(), b.get_size(), signed=True))
        elif ka.name in INT_KINDS:
            out.append(Leaf(path, o32, o64, "i", a.get_size(), b.get_size(), signed=INT_KINDS[ka.name]))
        elif ka == K.FLOAT:
            out.append(Leaf(path, o32, o64, "f", 4, 4))
        elif ka in (K.DOUBLE, K.LONGDOUBLE):
            if a.get_size() != 8 or b.get_size() != 8:
                raise Unsupported("long double of %d bytes" % a.get_size())
            out.append(Leaf(path, o32, o64, "d", 8, 8))
        elif ka == K.MEMBERPOINTER:
            pa, pb = self.canon(a.get_pointee()), self.canon(b.get_pointee())
            if pa.kind in (K.FUNCTIONPROTO, K.FUNCTIONNOPROTO) and a.get_size() == 4 and b.get_size() == 8:
                # a member-function pointer of a single-inheritance class: just the function's address (MS ABI)
                out.append(Leaf(path, o32, o64, "mfp", 4, 8, (pa, pb, a.get_class_type(), b.get_class_type())))
            else:
                out.append(Leaf(path, o32, o64, "u", a.get_size(), b.get_size()))
        else:
            raise Unsupported("type kind %s (%s)" % (ka.name, a.spelling))

    def _record(self, a, b, o32, o64, path, out, mdr):
        K = ci().CursorKind
        da, db = rdecl(a), rdecl(b)
        if not da.is_definition() or not db.is_definition():
            raise Unsupported("incomplete record embedded: %s" % a.spelling)
        mdr = mdr if mdr is not None else a
        out.append(Leaf(path + ("@",), o32, o64, "m", 0, 0))
        bases_a = [c for c in da.get_children() if c.kind == K.CXX_BASE_SPECIFIER]
        bases_b = [c for c in db.get_children() if c.kind == K.CXX_BASE_SPECIFIER]
        if any(c.is_virtual_base() for c in bases_a):
            raise Unsupported("virtual base in %s" % a.spelling)
        if self.dynamic(da) and not any(self.dynamic(rdecl(c.type)) for c in bases_a):
            out.append(Leaf(path + ("vfptr",), o32, o64, "vp", 4, 8, (self.key(mdr), self.key(a))))
        for ca, cb in zip(bases_a, bases_b):
            ta, tb = ca.type.get_canonical(), cb.type.get_canonical()
            oa, ob = ca.get_base_offsetof(da) // 8, cb.get_base_offsetof(db) // 8
            self._record(ta, tb, o32 + oa, o64 + ob, path + ("base", self.key(ta)), out, mdr)
        fa, fb = list(a.get_fields()), list(b.get_fields())
        if len(fa) != len(fb):
            raise Unsupported("fields differ between targets: %s" % a.spelling)
        union = da.kind == K.UNION_DECL
        seen_units = set()
        counted = []        # (integ4, x64bounds) (pointer leaf, count field, element bytes, field cursor)
        for x, y in zip(fa, fb):
            pa = x.get_field_offsetof()
            pb = y.get_field_offsetof()
            if pa < 0 or pb < 0:
                raise Unsupported("field offset unknown: %s::%s" % (a.spelling, x.spelling))
            if x.is_bitfield():
                sz = x.type.get_canonical().get_size()
                ua, ub = (pa // (8 * sz)) * sz, (pb // (8 * sz)) * sz
                if (ua, ub) in seen_units:
                    continue
                seen_units.add((ua, ub))
                out.append(Leaf(path + ("bf", ua), o32 + ua, o64 + ub, "i", sz, sz))
                continue
            n0 = len(out)
            self._flatten(x.type, y.type, o32 + pa // 8, o64 + pb // 8, path + (x.spelling or "anon%d" % pa,), out, None)
            fc_ = self.field_casts.get((a.spelling, x.spelling))
            if fc_ is not None and len(out) == n0 + 1 and out[n0].kind == "p":
                out[n0].cast = fc_          # (integ2, D93) the pointee the code casts this field to
            rng = field_range(x)
            if rng is not None and "rangecheck" not in OFF:
                # (integ1, rev5/D61) only on a scalar integer field (one integer leaf: not a struct, array or pointer), and
                # its declaration must cite the sites that write it (a comment on its lines naming a 0x address): the
                # range is a claim about the game's stores, checked by reading them
                lv_ = out[n0:]
                if len(lv_) != 1 or lv_[0].kind != "i":
                    raise Unsupported("HULK_RANGE on %s::%s, not a scalar integer field" % (a.spelling, x.spelling))
                if not _cites_writers(x):
                    raise Unsupported("HULK_RANGE on %s::%s without a comment citing the writer sites (0x addresses)"
                                      % (a.spelling, x.spelling))
                self.ranges_used[(a.spelling, x.spelling)] = rng
            if rng is not None:
                for l in out[n0:]:
                    if l.kind == "i":
                        l.range = rng
            cnt_ = field_count(x) if "countattr" not in OFF else None
            if cnt_ is not None:
                lv_ = out[n0:]
                if len(lv_) != 1 or lv_[0].kind != "p":
                    raise Unsupported("HULK_COUNT on %s::%s, not a pointer field" % (a.spelling, x.spelling))
                if not _cites_writers(x):
                    raise Unsupported("HULK_COUNT on %s::%s without a comment citing the writer sites (0x addresses)"
                                      % (a.spelling, x.spelling))
                counted.append((lv_[0], cnt_[0], cnt_[1], x))
            if union:
                break
        for l_, cf_, eb_, x_ in counted:
            # (integ4, x64bounds; rev5) the count is a sibling integer field whose values HULK_RANGE states (cited): the
            # generator draws it, then the array of exactly that many elements
            cl_ = [l for l in out if l.path == path + (cf_,)]
            if len(cl_) != 1 or cl_[0].kind != "i" or cl_[0].range is None:
                raise Unsupported("HULK_COUNT(%s) on %s::%s: the count must be an integer field of %s with a cited "
                                  "HULK_RANGE" % (cf_, a.spelling, x_.spelling, a.spelling))
            pv_ = l_.extra[0].get_canonical().kind.name == "VOID" if l_.extra else True
            if pv_ != (eb_ is not None) or (eb_ is not None and eb_ <= 0):
                raise Unsupported("HULK_COUNT on %s::%s: a void pointer takes HULK_COUNT_BYTES(field, n), a typed one "
                                  "HULK_COUNT(field)" % (a.spelling, x_.spelling))
            l_.count = (cl_[0], eb_)
            self.counts_used[(a.spelling, x_.spelling)] = (cf_, eb_)

    def fingerprints(self):
        """(x64t12) {layout key: {"k64": the 64-bit spelling, "fp": layout_fp}} of every layout this checker built: the
        types a run's verdict rests on. tools/x64_gate.py keeps it with a cached result and re-runs the block when
        type_fingerprints() of the current source disagrees (a field's type changed, the code didn't)."""
        out = {}
        for k, (lay, k64) in self.pairs.items():
            out[k] = {"k64": k64, "fp": layout_fp(self.cache.get(k, lay))}
        return out

    def dynamic(self, decl, _memo={}):
        K = ci().CursorKind
        k = decl.hash
        if k in _memo:
            return _memo[k]
        _memo[k] = False
        r = False
        for c in decl.get_children():
            if c.kind in (K.CXX_METHOD, K.DESTRUCTOR) and c.is_virtual_method():
                r = True
                break
            if c.kind == K.CXX_BASE_SPECIFIER and self.dynamic(rdecl(c.type)):
                r = True
                break
        _memo[k] = r
        return r


# ------------------------------------------------------------------------------------------------- vftable dump
VT_HEAD = re.compile(r"^VFTable for '(.+?)'(?: in '(.+)')? \((\d+) entries\)\.$")
VT_ENTRY = re.compile(r"^\s+(\d+) \| (.*)$")


def parse_vtables(text):
    """{(most-derived, subobject): [entry text per slot]} from -fdump-vtable-layouts (RTTI entries dropped)."""
    out = {}
    cur = None
    for line in text.splitlines():
        m = VT_HEAD.match(line)
        if m:
            sub, rest = m.group(1), m.group(2)
            md = rest.split("' in '")[-1] if rest else sub
            cur = []
            out.setdefault((md.replace(" ", ""), sub.replace(" ", "")), cur)
            continue
        if cur is None:
            continue
        m = VT_ENTRY.match(line)
        if m:
            if m.group(2).endswith(" RTTI"):
                continue
            cur.append(m.group(2))
        elif not line.strip():
            cur = None
        elif line.startswith("       [") and cur:
            cur[-1] += " " + line.strip()
    return out


# ------------------------------------------------------------------------------------------------- signatures
class FakeType:
    """A builtin type for signatures libclang has no declaration of (synthesized deleting destructors)."""

    class _K:
        def __init__(self, name):
            self.name = name

    def __init__(self, kind, size, pointee=None):
        self.kind, self.size, self.pointee = FakeType._K(kind), size, pointee

    def get_canonical(self):
        return self

    def get_size(self):
        return self.size

    def get_pointee(self):
        return self.pointee

    def is_const_qualified(self):
        return False


def _vp(bits):
    return FakeType("POINTER", bits // 8, FakeType("VOID", 0))


def _sig_delete():
    return Sig((FakeType("VOID", 0), FakeType("VOID", 0)), [(_vp(32), _vp(64))], CC_C, False, False, None, "operator delete")


class Sig:
    """A callee's parameters and return as paired types; ABI placement per side."""

    def __init__(self, ret, params, cc32, has_this, variadic, method_record=None, name=""):
        self.ret, self.params, self.cc32, self.has_this = ret, params, cc32, has_this
        self.variadic, self.method_record, self.name = variadic, method_record, name

    @staticmethod
    def of(c32, c64, name=""):
        """From the two cursors of one declaration (function, method, ctor, dtor) or function types."""
        m = ci()
        K = m.CursorKind
        if isinstance(c32, m.Cursor):
            t32, t64 = c32.type.get_canonical(), c64.type.get_canonical()
            has_this = c32.kind in (K.CXX_METHOD, K.CONSTRUCTOR, K.DESTRUCTOR, K.CONVERSION_FUNCTION) and not c32.is_static_method()
            rec = (c32.semantic_parent.type, c64.semantic_parent.type) if has_this else None
        else:
            t32, t64 = c32, c64
            has_this, rec = False, None
        cc = m.conf.lib.clang_getFunctionTypeCallingConv(t32)
        params = list(zip(t32.argument_types(), t64.argument_types())) if t32.kind.name == "FUNCTIONPROTO" else []
        variadic = t32.kind.name == "FUNCTIONPROTO" and t32.is_function_variadic()
        sg = Sig((t32.get_result(), t64.get_result()), params, cc, has_this, variadic, rec, name)
        if isinstance(c32, m.Cursor) and has_this:
            sg.const_method = c32.is_const_method()
            sg.ctor_dtor = c32.kind in (K.CONSTRUCTOR, K.DESTRUCTOR)
        return sg


def is_record(t):
    return t.get_canonical().kind.name == "RECORD"


def is_float_t(t):
    return t.get_canonical().kind.name in ("FLOAT", "DOUBLE", "LONGDOUBLE")


def c03_pod(decl):
    """MS ABI: a record returned in registers must be a C++03 POD (no user ctor/dtor/copy-assign, no bases, no
    virtuals, no private/protected fields) of 1, 2, 4 or 8 bytes."""
    K = ci().CursorKind
    for c in decl.get_children():
        if c.kind in (K.CXX_BASE_SPECIFIER, K.CONSTRUCTOR, K.DESTRUCTOR):
            return False
        if c.kind == K.CXX_METHOD and (c.is_virtual_method() or c.spelling == "operator="):
            return False
        if c.kind == K.FIELD_DECL:
            if c.access_specifier.name in ("PRIVATE", "PROTECTED"):
                return False
            ft = c.type.get_canonical()
            while ft.kind.name == "CONSTANTARRAY":
                ft = ft.element_type.get_canonical()
            if ft.kind.name == "RECORD" and not c03_pod(rdecl(ft)):
                return False
    return True


def trivial_copy(decl):
    """No user-declared copy constructor or destructor (here or in a base or member): Win64 passes such a record
    by value in a register when it has 1, 2, 4 or 8 bytes, any other by reference to a copy."""
    K = ci().CursorKind
    for c in decl.get_children():
        if c.kind == K.DESTRUCTOR or (c.kind == K.CONSTRUCTOR and c.is_copy_constructor()):
            return False
        if c.kind in (K.CXX_BASE_SPECIFIER, K.FIELD_DECL):
            ft = c.type.get_canonical()
            while ft.kind.name == "CONSTANTARRAY":
                ft = ft.element_type.get_canonical()
            if ft.kind.name == "RECORD" and not trivial_copy(rdecl(ft)):
                return False
    return True


def ret_indirect(sig, bits):
    rt = sig.ret[0 if bits == 32 else 1].get_canonical()
    if rt.kind.name != "RECORD":
        return False
    if sig.has_this:
        return True
    return not (rt.get_size() in (1, 2, 4, 8) and c03_pod(rdecl(rt)))


# ------------------------------------------------------------------------------------------------- the object graph
class Obj:
    __slots__ = ("id", "rid", "ident", "kind", "lay", "count", "a32", "a64", "size32", "size64", "ptrs", "hint", "alloc",
                 "init", "grange", "rdata", "res", "ahint", "ak")

    def __init__(self, oid, ident, kind, lay, count, size32, size64):
        self.id, self.ident, self.kind, self.lay, self.count = oid, ident, kind, lay, count
        self.rid = oid          # the key of its random contents (Heap.get)
        self.size32, self.size64 = size32, size64
        self.a32 = self.a64 = 0
        self.ptrs = {}
        self.hint = None
        self.alloc = None       # (n32, n64) requested sizes of an allocation
        self.init = None        # fixed initial bytes per side (vtables), else generated
        self.grange = None      # (integ2, D103) (lo, hi): a global's integer words (HULK_RANGE on its declaration)
        self.rdata = None       # (integ2, D103) the name of a HULK_RDATA global (its XBE bytes; no store may reach it)
        self.res = {}           # (integ2, D107) {bits: bytes reserved for it in that heap} (a heap region's span)
        self.ahint = None       # (integ3, allocty) the record an allocation is returned as (declared or cast): its leaves
        self.ak = 0             # (integ3, allocty; rev5 R1/R2) whole records typed in it, the same on both sides

    def base(self, bits):
        return self.a32 if bits == 32 else self.a64

    def size(self, bits):
        return self.size32 if bits == 32 else self.size64


class Heap:
    """Objects shared by both runs of one input: identities, both addresses, generated contents."""

    def __init__(self, chk, seed):
        self.chk, self.seed = chk, seed
        self.objs = []
        self.by_ident = {}
        self.next = {32: HEAP32, 64: HEAP64}
        self.gnext = GLOBALS
        self.gused = set()
        self.nheap = 0
        self.starts = {32: [], 64: []}      # sorted region starts -> obj
        self.order = {32: [], 64: []}
        self.by_type = {}
        self.choices = {}
        self.count_cap = None       # (integ4, x64bounds) why a HULK_COUNT array was cut to KMAX (the input is set aside)
        self.allocty = False    # (integ3) an allocation's image was drawn as its record (counted per input)

    def _region(self, bits, size):
        a = self.next[bits]
        self.next[bits] = a + ((size + PAGE - 1) & ~(PAGE - 1)) + PAGE     # one unmapped guard page after each
        if self.next[bits] - (HEAP32 if bits == 32 else HEAP64) > (HEAP32_SPAN if bits == 32 else HEAP64_SPAN):
            # (rev1) past it, a truncated 64-bit pointer could read as a 32-bit heap address (rawint, ptrtrunc)
            raise Unsupported("the %d-bit heap outgrew its span (rawint's disjoint low 32 bits)" % bits)
        return a

    def get(self, ident, kind, lay, count=None, glob=False, alloc=None):
        o = self.by_ident.get(ident)
        if o is not None:
            return o
        if count is None:
            # a record is one object (indexing past it is out of bounds, and the input is not used: the element
            # after it would be another record whose 64-bit fields are elsewhere, so `(Hdr*)p + 1` or an index past a
            # member array would read as layout differences); scalars (int*, float*, T**) are arrays of up to KMAX.
            # EQ64_OFF=recone: records as arrays too
            one = lay.record and ("recone" not in OFF or ident == ("arg", "this"))
            count = 1 if glob or one else max(1, min(KMAX, RAW_SIZE // max(1, lay.size32)))
        if lay.raw:
            n = alloc[0] if alloc else RAW_SIZE
            s32 = s64 = max(1, n)
            if alloc:
                s32, s64 = max(1, alloc[0]), max(1, alloc[1])
        else:
            s32, s64 = lay.size32 * count, lay.size64 * count
        o = Obj(len(self.objs), ident, kind, lay, count, s32, s64)
        if "rngloc" not in OFF:
            # (build6) contents keyed apart from the global objects made up front: a tree TU's data symbols (all of its
            # functions') come before the arguments, so by creation index the same argument would draw other values
            # than when the function is checked from its own source. Globals by name, the rest in creation order
            if glob:
                o.rid = ("g", rng_key(ident[1]) if ident[:1] == ("sym",) else repr(ident))
            else:
                o.rid = self.nheap
                self.nheap += 1
        o.alloc = alloc
        if glob and "gseq" not in OFF:
            # (build6) each global at a place its name decides (64 KB slots, probing on), not after the globals made
            # before it: what lies past a global's end (an index out of range reads there) is then the same whether
            # the object has this function alone or a whole tree TU of others with their own globals
            span = (max(s32, s64) + PAGE - 1) & ~(PAGE - 1)
            need = (span + PAGE + GSLOT - 1) // GSLOT
            i = h64(repr(o.rid)) % (GSLOTS - need)
            while any(j in self.gused for j in range(i, i + need)):
                i = (i + 1) % (GSLOTS - need)
            self.gused.update(range(i, i + need))
            o.a32 = o.a64 = GLOBALS + i * GSLOT
        elif glob:
            a = self.gnext
            span = (max(s32, s64) + PAGE - 1) & ~(PAGE - 1)
            self.gnext = a + span + PAGE
            o.a32 = o.a64 = a
        else:
            o.a32 = self._region(32, max(s32, PAGE))
            o.a64 = self._region(64, max(s64, PAGE))
            o.res = {32: (max(s32, PAGE) + PAGE - 1) & ~(PAGE - 1), 64: (max(s64, PAGE) + PAGE - 1) & ~(PAGE - 1)}
        self.objs.append(o)
        self.by_ident[ident] = o
        for bits in (32, 64):
            i = bisect.bisect_right(self.starts[bits], o.base(bits))
            self.starts[bits].insert(i, o.base(bits))
            self.order[bits].insert(i, o)
        self.by_type.setdefault(lay.key, []).append(o)
        return o

    def regrow(self, o, bits, size, mapped):
        """(integ2, D107) An allocation whose request on BITS outgrew the region the first run's request reserved (the
        32-bit run comes first: `count * sizeof(T)` with T twice as large on x86-64): give it a new region of SIZE
        on BITS, so its tail doesn't lie under the objects placed after it. Refused when a page of the old region is
        already mapped on that side (its bytes would be lost)."""
        old = o.base(bits)
        if any(p in mapped for p in range(old, old + o.res.get(bits, PAGE), PAGE)):
            raise Unsupported("an allocation grew on the %d-bit side after its region was mapped" % bits)
        st, od = self.starts[bits], self.order[bits]
        i = od.index(o)
        del st[i]
        del od[i]
        a = self._region(bits, max(size, PAGE))
        if bits == 32:
            o.a32 = a
        else:
            o.a64 = a
        o.res[bits] = (max(size, PAGE) + PAGE - 1) & ~(PAGE - 1)
        j = bisect.bisect_right(st, a)
        st.insert(j, a)
        od.insert(j, o)

    def find(self, bits, a):
        """(obj, offset) for an address inside an object's region (its page-rounded span), else (None, 0)."""
        st = self.starts[bits]
        i = bisect.bisect_right(st, a) - 1
        if i < 0:
            return None, 0
        o = self.order[bits][i]
        off = a - o.base(bits)
        span = (max(o.size(bits), PAGE) + PAGE - 1) & ~(PAGE - 1)
        if off < span:
            return o, off
        return None, 0

    # ---- contents
    def image(self, o, bits):
        """The initial bytes of O's region (page-rounded) on BITS."""
        span = (max(o.size(bits), PAGE) + PAGE - 1) & ~(PAGE - 1)
        buf = bytearray(span)
        if o.init is not None:
            b = o.init[bits]
            buf[:len(b)] = b
            return buf
        if o.lay.raw:
            r = Rng(self.seed, "raw", o.rid)
            n = o.size(bits) if o.alloc else span
            # raw bytes: the same on both sides, byte for byte
            for i in range(0, n, 8):
                v = r.next()
                c = (v >> 56) & 3
                if c == 0:
                    v = 0
                elif c == 1:
                    v &= 0x0000000F0000000F
                chunk = v.to_bytes(8, "little")
                buf[i:i + 8] = chunk[:max(0, min(8, n - i))]
            lay = o.ahint
            if lay is not None and o.kind == "alloc" and o.ak and "allocty" not in OFF:
                # (integ3, allocty) an allocation the allocator returns as a record (its declaration's pointer type, or
                # the cast of its result): bytes the code reads before it writes them (a stubbed initializer's work,
                # `slot = Alloc(sizeof *slot); InitSlot(slot); if (slot->drive) ...`) are that record's leaves, drawn as
                # any typed object's: a pointer field is null or an object on both sides. Raw bytes, the same byte for
                # byte, read as an 8-byte pointer differ from the 4-byte word the 32-bit run read (0x0008c470, D142)
                # (rev5 R2) every whole record of the request (`count * sizeof(T)`), each element its own leaf values;
                # (R1) the same count on both sides (allocator(): a 64-bit request that holds fewer is a layout stop)
                es_ = lay.size(bits)
                # (rev5 R2') the bytes past the typed records (a header's payload, `sizeof(Hdr) + len`): raw, the same byte
                # for byte counted from the records' end, so payload byte i is one value on both sides
                r_ = Rng(self.seed, "rawtail", o.rid)
                t0_ = o.ak * es_
                for i in range(t0_, n, 8):
                    v = r_.next()
                    c = (v >> 56) & 3
                    if c == 0:
                        v = 0
                    elif c == 1:
                        v &= 0x0000000F0000000F
                    buf[i:i + 8] = v.to_bytes(8, "little")[:max(0, min(8, n - i))]
                for e in range(o.ak):
                    for l in lay.leaves:
                        self.put_leaf(buf, e * es_ + l.off(bits), bits, l, self.leaf_value(o, e, l, lay))
                self.allocty = True
            return buf
        lay = o.lay
        es = lay.size(bits)
        for e in range(o.count):
            for l in lay.leaves:
                self.put_leaf(buf, e * es + l.off(bits), bits, l, self.leaf_value(o, e, l))
        return buf

    def leaf_value(self, o, e, l, lay=None):
        """The abstract value of leaf L of element E of O (laid out as LAY, default O's own layout): ("i", int)
        ("f", bits) ("d", bits) ("b", bytes) or a pointer ("p", obj or None, 32-bit offset) / ("fn", stub key) /
        ("vt", vtable obj)."""
        r = Rng(self.seed, "leaf", o.rid, e, l.o32)
        k = l.kind
        orng_ = getattr(self.chk, "pre_oranges", None)
        if orng_ and e == 0 and o.ident == ("arg", "this") and l.o32 in orng_ and (lay is None or lay is o.lay):
            # (integ7, item 8; rev5 (e)) a word of `this` a `*this+0xOFF.f32|i32` range item names (its 32-bit offset):
            # drawn inside the range, the same value on both sides (the leaf must be the item's type and width)
            import equiv
            cond_, guard_ = orng_[l.o32]
            want_ = "f" if cond_[5] == "f" else "i"
            if l.kind != want_ or l.s32 != 4 or l.s64 != 4:
                raise Unsupported("pre: *this+0x%x.%s32 is a %s leaf of %d/%d bytes" % (
                    l.o32, cond_[5], l.kind, l.s32, l.s64))
            v0_ = struct.pack("<f", gen_float(r)) if want_ == "f" else \
                (gen_int(r, 4, True) & M32).to_bytes(4, "little")
            nb_ = equiv._pre_range_fix(self.seed, l.o32, v0_, 4, cond_, True)
            if guard_ is not None:
                # (integ7, rev5 (b)) a guarded word is drawn in range only where its guard (the leaf at the guard's
                # 32-bit offset, as this input draws it) holds
                gl_ = o.lay.leaf_at(32, guard_[0])
                if gl_ is None or gl_.o32 != guard_[0] or gl_.kind != ("f" if guard_[1][5] == "f" else "i") or \
                        gl_.s32 != 4 or gl_.s64 != 4:
                    raise Unsupported("pre: the guard *this+0x%x is no 4-byte %s leaf" % (guard_[0], guard_[1][5]))
                gv_ = self.leaf_value(o, 0, gl_)
                gb_ = struct.pack("<I", gv_[1] & 0xFFFFFFFF)
                if not equiv._pre_in(equiv._pre_val(gb_, 4, guard_[1][5]), guard_[1]):
                    nb_ = None
            b_ = nb_ if nb_ is not None else v0_
            return ("f", struct.unpack("<I", b_)[0]) if want_ == "f" else ("i", struct.unpack("<I", b_)[0])
        if k == "i" and l.s32 == 4 and l.s64 == 8:
            # a pointer-sized integer (hulk_intptr / hulk_uintptr: a pointer the code keeps in an integer): a small
            # integer or an object's address, never a large 32-bit number (that compares with addresses one way
            # on i386 and the other above 4 GB)
            key = (e, l.o32)
            if key not in o.ptrs:
                o.ptrs[key] = ("i", r.below(NULL_HI)) if r.below(2) else \
                    self.choose_ptr(r, ("leaf", o.id, e, l.o32), None)
            return o.ptrs[key]
        if k == "i" and l.range is not None:
            return ("i", l.range[0] + r.below(l.range[1] - l.range[0] + 1))
        if k in ("i", "u") and o.grange is not None:
            return ("i", o.grange[0] + r.below(o.grange[1] - o.grange[0] + 1))
        if k == "i" or k == "u":
            return ("i", gen_int(r, min(l.s32, l.s64), l.signed))
        if k == "f":
            return ("f", struct.unpack("<I", struct.pack("<f", gen_float(r)))[0])
        if k == "d":
            return ("d", struct.unpack("<Q", struct.pack("<d", gen_float(r)))[0])
        if k == "b":
            return ("b", bytes(gen_byte(r) for _ in range(l.s32)))
        if k == "p" and l.count is not None:
            key = (e, l.o32)
            if key not in o.ptrs:
                # (integ4, x64bounds) HULK_COUNT: an array of exactly this->count elements (null when it is 0), up to
                # COUNT_MAX elements / COUNT_BYTES bytes (rev5: the count's whole declared range, within a generous
                # limit); a count past that sets the input aside (count_cap), never a shorter array
                cv = self.leaf_value(o, e, l.count[0])
                n = cv[1] if cv[0] == "i" else 0
                if n <= 0:
                    o.ptrs[key] = ("p", None, 0)
                else:
                    es_ = l.count[1] or max(1, self.chk.types.layout(l.extra[0], l.extra[1]).size64)
                    if n > COUNT_MAX or n * es_ > COUNT_BYTES:
                        self.count_cap = "%s: count %d past %d elements / %d bytes" % (
                            "/".join(map(str, l.path)), n, COUNT_MAX, COUNT_BYTES)
                        n = 1
                    if l.count[1] is not None:
                        a_ = self.get(("count", o.id, e, l.o32), "heap", RAW, alloc=(n * l.count[1], n * l.count[1]))
                    else:
                        lay_ = self.chk.types.layout(l.extra[0], l.extra[1])
                        if lay_.raw:
                            raise Unsupported("HULK_COUNT on %s: the pointee has no layout" % "/".join(map(str, l.path)))
                        a_ = self.get(("count", o.id, e, l.o32), "heap", lay_, count=n)
                    o.ptrs[key] = ("p", a_, 0)
            return o.ptrs[key]
        if k == "p":
            key = (e, l.o32)
            if key not in o.ptrs:
                v = None
                prev = self.range_partner(lay or o.lay, l)
                if prev is not None:
                    # [begin, end) pairs (a vector's begin/end/capacity): the later pointer points into the
                    # earlier one's array (null with it), so `end - begin` is an element count on both targets
                    pv = self.leaf_value(o, e, prev, lay)
                    t = pv[1] if pv[0] == "p" else None
                    if t is None:
                        v = ("p", None, 0)
                    elif not t.lay.raw:
                        k_ = r.below(t.count + 1)
                        v = ("p", t, k_ * t.lay.size32)
                if v is None:
                    v = self.choose_ptr(r, ("leaf", o.id, e, l.o32), l.extra, cast=l.cast)
                o.ptrs[key] = v
            return o.ptrs[key]
        if k == "fp":
            if r.below(4) == 0:
                return ("p", None, 0)
            st = self.chk.fnptr_stub(("fnptr", o.id, e, l.o32), l.extra)
            return ("fn", st.key)
        if k == "mfp":
            if r.below(8) == 0:
                return ("p", None, 0)
            st = self.chk.fnptr_stub(("mfp", o.id, e, l.o32), l.extra[:2], method=l.extra[2:])
            return ("fn", st.key)
        if k == "vp":
            vt = self.chk.vtable_obj(self, l.extra)
            return ("p", vt, 4)
        raise Unsupported("leaf kind " + k)

    @staticmethod
    def range_partner(lay, l):
        """The pointer leaf before L in the same record with the same pointee type, if any."""
        memo = lay.__dict__.setdefault("_partner", {})
        if l.path in memo:
            return memo[l.path]
        best = None
        for x in lay.leaves:
            if x is l:
                break
            if x.kind == "p" and x.path[:-1] == l.path[:-1] and x.extra[0].spelling == l.extra[0].spelling:
                best = x
        memo[l.path] = best
        return best

    def choose_ptr(self, r, ident, types, cast=None):
        """A pointer value for IDENT: null, an existing object of the pointee type, or a new one. Decided once per
        input (the 64-bit run sees the 32-bit run's choice, whatever objects exist by then)."""
        if ident in self.choices:
            return self.choices[ident]
        v = self._choose_ptr(r, ident, types, cast)
        self.choices[ident] = v
        return v

    def _choose_ptr(self, r, ident, types, cast=None):
        x = r.below(100)
        if x < 20:
            return ("p", None, 0)
        lay = self.chk.types.layout(types[0], types[1]) if types else RAW
        if cast is not None and cast[0] == AMBIGUOUS:
            # (integ2, F5) a field cast to several records: the object keeps its declared type, the run says so
            self.chk.types.view_ambiguous.add(str(ident[:2]))
        elif cast is not None:
            lay = self.chk.types.extend(lay, cast, types)
        if x < 35:
            same = self.by_type.get(lay.key) or []
            same = [s for s in same if s.kind == "heap"]
            if same:
                return ("p", same[r.below(len(same))], 0)
        return ("p", self.get(ident, "heap", lay), 0)

    def put_leaf(self, buf, off, bits, l, v):
        n = l.size(bits)
        if off < 0 or off + n > len(buf):
            return
        buf[off:off + n] = self.encode(bits, l, v, n)

    def encode(self, bits, l, v, n):
        t = v[0]
        if t == "i":
            x = v[1]
            return (x & ((1 << (8 * n)) - 1)).to_bytes(n, "little")
        if t == "f":
            return struct.pack("<I", v[1])
        if t == "d":
            return struct.pack("<Q", v[1])
        if t == "b":
            return v[1][:n].ljust(n, b"\0")
        return self.ptr_value(bits, v).to_bytes(n, "little")

    def ptr_value(self, bits, v):
        if v[0] == "p":
            o, off = v[1], v[2]
            if o is None:
                return 0
            return o.base(bits) + (off if bits == 32 else self.off64(o, off))
        if v[0] == "fn":
            return self.chk.stub_addr(v[1])
        raise Unsupported("pointer value " + v[0])

    @staticmethod
    def off64(o, off32):
        if o.kind == "vtable":
            return off32 * 2
        if o.lay.raw or off32 == 0:
            return off32
        if o.lay.key.startswith("region<") and off32 >= o.lay.size32 and "regiontail" not in OFF:
            return off32 - o.lay.size32 + o.lay.size64      # (integ4) the raw tail past a region's records
        v = o.lay.to64(off32)
        if v is None:
            raise Unsupported("interior pointer translation (%s +0x%x)" % (o.lay.key, off32))
        return v


def fcanon(kind, data):
    """A float as compared: its bits (every NaN alike), with its value as text for the report."""
    v = struct.unpack("<f" if kind == "f" else "<d", data)[0]
    if v != v:
        return (kind, "nan", "nan")
    return (kind, int.from_bytes(data, "little"), "%.9g" % v)


def gen_int(r, n, signed):
    x = r.below(100)
    if x < 15:
        v = 0
    elif x < 50:
        v = r.below(9)
    elif x < 58:
        v = -1
    elif x < 75:
        v = r.below(1000)
    elif x < 80:
        v = 1 << r.below(8 * n)
    else:
        v = r.next() & ((1 << (8 * n)) - 1)
    if n >= 4 and any(lo <= (v & M32) < hi for lo, hi in ADDR_RANGES32):
        v ^= 0x80000000     # (an integer that looks like an address of either run would decode as a pointer)
    return v


# 32-bit ranges where our runs place things (stack, heap, globals, stubs, code): no generated integer falls in them
ADDR_RANGES32 = [(STACK_LO, STACK_HI), (HEAP32, HEAP32 + 0x20000000), (GLOBALS, CODE + 0x1000000), (HEAP64 & M32, (HEAP64 & M32) + 0x1000000)]


def gen_float(r):
    x = r.below(100)
    if x < 15:
        return 0.0
    if x < 25:
        return 1.0
    if x < 30:
        return -1.0
    if x < 70:
        return round((r.unit() * 20 - 10), 3)
    if x < 95:
        return (r.unit() * 2 - 1) * 10000.0
    return float(struct.unpack("<f", struct.pack("<I", (r.next() & 0x7F7FFFFF)))[0])


def gen_byte(r):
    x = r.below(4)
    if x == 0:
        return 0
    if x == 1:
        return r.below(8)
    return r.below(256)


# ------------------------------------------------------------------------------------------------- stubs
CRT_SEMANTIC = {"memcpy", "memmove", "memset", "memcmp", "strlen", "strcmp", "strcpy", "strncpy", "strcat", "_stricmp",
                "stricmp", "strncmp", "_strnicmp", "strchr", "wcslen"}
CRT_STRIPPED = {n.lstrip("_") for n in CRT_SEMANTIC}
I386_HELPERS = {"__alldiv", "__aulldiv", "__allrem", "__aullrem", "__allmul", "__allshl", "__allshr", "__aullshr",
                "__aulldvrm", "__alldvrm"}
SKIP_CALLS = {"__security_check_cookie", "__chkstk", "_alloca_probe", "__alloca_probe", "_RTC_CheckEsp",
              "_chkstk", "chkstk", "alloca_probe"}   # (x64eq) the i386 C names of the probes (`__chkstk` -> `_chkstk`)
ALLOCATORS = {"??2@YAPAXI@Z", "??_U@YAPAXI@Z", "??2@YAPEAX_K@Z", "??_U@YAPEAX_K@Z", "_malloc", "malloc",
              "FUN_0008d690", "_FUN_0008d690", "FUN_0008d6d0", "_FUN_0008d6d0", "thunk_FUN_0008d690", "_thunk_FUN_0008d690"}
ALLOC_MAX = 16 << 20                # a larger 32-bit allocation sets the input aside (a fuzzed count)
# (rev5, D107 follow-up) a new allocator entry needs review: its size is read as the declared parameter (a size passed
# inside a struct would read the struct's first bytes as the request)
# the game's allocators declared with C++ linkage (`void* __cdecl FUN_0008d690(unsigned)`: ?FUN_0008d690@@YAPAXI@Z)
ALLOCATOR_CXX = re.compile(r"^\?(thunk_)?FUN_0008d6[9d]0@@YA")
# member allocators whose first parameter is the size: pure3d's bump allocator (0x002888c0, `pool->Alloc(n, align)`)
ALLOCATOR_MEMBER = re.compile(r"^\?FUN_002888c0@")
# allocators whose size is a later parameter: Lua's luaM_realloc (0x0021add0: L, block, oldsize, newsize)
ALLOCATOR_AT = {"FUN_0021add0": 3}


# implicitly declared functions (no declaration for libclang): i386 name -> (x64 name, signature)
IMPLICIT_SIGS = {"??3@YAXPAX@Z": ("??3@YAXPEAX@Z", lambda: _sig_delete()),
                 "??_V@YAXPAX@Z": ("??_V@YAXPEAX@Z", lambda: _sig_delete())}
# (x64eq) sized operator delete (`operator delete(void*, size_t)`, which clang's own deleting destructors call) is the same
# callee as the unsized one: the pointer is compared, the size (the class's size on each target) is not an argument here.
# (rev1) This relies on the 64-bit platform's sized operator delete only forwarding to the unsized one (the 32-bit
# Wine build's, src/platform/sdl/crt/crt_glue.cpp, does; libc++'s default one forwards too): a platform one that used the
# size (a size-class allocator) would need the size compared after all.
SIZED_DELETE = {"??3@YAXPAXI@Z": "??3@YAXPAX@Z", "??_V@YAXPAXI@Z": "??_V@YAXPAX@Z",
                "??3@YAXPEAX_K@Z": "??3@YAXPEAX@Z", "??_V@YAXPEAX_K@Z": "??_V@YAXPEAX@Z"}


class Stub:
    __slots__ = ("key", "names", "sig", "kind", "idx", "label")

    def __init__(self, key, sig, kind, idx, label):
        self.key, self.sig, self.kind, self.idx, self.label = key, sig, kind, idx, label
        self.names = {}


def c_name(name, bits):
    """A C symbol's undecorated name (i386: `_f`, `_f@8`, `@f@8`)."""
    if name.startswith("?"):
        return None
    if bits == 32:
        m = re.match(r"^[_@](.+?)(?:@\d+)?$", name)
        return m.group(1) if m else name
    return name


def allocator_at(name, cname):
    """The size parameter's index when NAME / CNAME is one of ALLOCATOR_AT (C or C++ linkage), else None."""
    for f, i in ALLOCATOR_AT.items():
        if cname in (f, "_" + f) or (name or "").startswith("?%s@@" % f) or name in (f, "_" + f):
            return i
    return None


def ptr_width_int(tt):
    """(T32, T64) is one integer type of pointer width on each target (hulk_intptr / hulk_uintptr)."""
    try:
        a, b = tt[0].get_canonical(), tt[1].get_canonical()
        return a.kind.name in INT_KINDS and b.kind.name in INT_KINDS and a.get_size() == 4 and b.get_size() == 8
    except Exception:   # noqa: BLE001
        return False


def thunk_method(name):
    """The method an MS adjustor thunk's mangled name stands for (`?f@C@@W3AEXXZ` -> `?f@C@@UAEXXZ`), or None."""
    m = re.match(r"^(\?[^?].*@@)([GHOPWX])(\d|[A-P]+@)(.+)$", name)
    if not m:
        return None
    return m.group(1) + chr(ord(m.group(2)) - 2) + m.group(4)


def norm_mangled(name):
    """Fallback pairing of an x64 MS mangled name with its i386 spelling (no __ptr64 `E`, thiscall members).
    String literals (`??_C@_07DIJKPEDD@compare?$AA@`) are named alike on both targets: their hash may hold `PE`."""
    if name.startswith("??_C@"):
        return name
    n = re.sub(r"@@([ABEFIJMNQRUV])E([ABCD])A", r"@@\1\2E", name)
    n = re.sub(r"(?<=[PQRSA])E(?=[ABCD])", "", n)
    n = n.replace("_K", "I").replace("_J", "H")
    return n


# ------------------------------------------------------------------------------------------------- the checker
class Checker:
    def __init__(self, src, addr, symbol=None, verbose=False):
        self.src, self.addr, self.verbose = src, addr, verbose
        self.tmp = tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build") if os.path.isdir(os.path.join(ROOT, "build")) else None)
        d = self.tmp.name
        self.wrapper = write_wrapper(src, d)
        self.obj32 = load_obj(compile32(self.wrapper, d))
        p64, dump = compile64(self.wrapper, d)
        self.obj64 = load_obj(p64)
        self.vtables = parse_vtables(dump)
        self.tu = {32: TU(self.wrapper, d, "i686-pc-windows-msvc", 32), 64: TU(self.wrapper, d, "x86_64-pc-windows-msvc", 64)}
        self.types = Types(self.tu[32], self.tu[64], self.vtables)
        self.img = {32: Image(self.obj32, 32), 64: Image(self.obj64, 64)}
        self.stubs = []
        self.stub_by_key = {}
        self.flags = set()
        self.ddtor = None
        self.param_casts = {}
        self.param_into = {}    # (pick() sets it; its deleting-destructor / early paths return before that)
        self.param_range = {}   # (integ2, D102)
        self.pre_ranges = {}    # (integ3, D152)
        self.pre_oranges = {}   # (integ7, item 8)
        if symbol is None:
            symbol = self._pick_by_original()
        if symbol and symbol.startswith("??_G") and symbol not in self.img[32].funcs:
            self.deleting_dtor(symbol, d)
        self.pick(symbol)
        if TREE_EXTERNAL:
            self.tree_externalize()
        self.resolve_all()

    def call_site_index(self, bits, st, retaddr, sites=None):
        """(x64t9, sitecasts) The index of the call returning to RETADDR among the function under test's direct calls of
        stub ST, in address order (None if it is not one of them, or the sites are not one per source call)."""
        cache = self.__dict__.setdefault("_sites", {})
        sites = self.site_casts if sites is None else sites
        key = (bits, st.key, id(sites))
        if key not in cache:
            img = self.img[bits]
            name = st.names.get(bits)
            rng = img.func_range(self.sym32 if bits == 32 else self.sym64)
            rets = []
            if name and rng:
                for i, s in enumerate(img.obj.sections):
                    sn = i + 1
                    if sn not in img.secaddr:
                        continue
                    for va, si, typ in s["relocs"]:
                        a = img.secaddr[sn] + va
                        if rng[0] <= a < rng[1] and si in img.obj.syms and img.obj.syms[si][0] == name:
                            rets.append(a + 4)
            l = len(sites.get(st.key, ()))
            cache[key] = sorted(rets) if len(rets) == l else None
        rets = cache[key]
        if rets is None or retaddr not in rets:
            return None
        return rets.index(retaddr)

    def reachable(self, bits, v):
        """Is address V of our image in a symbol the function under test can reach through relocations? Always outside
        a tree TU. (merge-once) A tree TU's object holds hundreds of functions, so an integer (a float's bits, a fuzzed
        value) lands in our code far more often than in a one-function object, and each target's layout puts another
        symbol there: an integer is read as an address only inside what the function can refer to."""
        if not TREE_ACTIVE or "treereach" in OFF:
            return True
        r = getattr(self, "_reach", {}).get(bits)
        if r is None:
            img = self.img[bits]
            edges = {}
            for i, s in enumerate(img.obj.sections):
                sn = i + 1
                if sn not in img.secaddr:
                    continue
                for va, si, typ in s["relocs"]:
                    if si not in img.obj.syms:
                        continue
                    name = img.obj.syms[si][0]
                    src, _ = img.sym_at(img.secaddr[sn] + va)
                    if src is not None and name in img.defined and name not in img.ext_names:
                        edges.setdefault(src, set()).add(name)
            start = self.sym32 if bits == 32 else self.sym64
            r, todo = {start}, [start]
            while todo:
                for n in edges.get(todo.pop(), ()):
                    if n not in r:
                        r.add(n)
                        todo.append(n)
            self.__dict__.setdefault("_reach", {})[bits] = r
        name, _ = self.img[bits].sym_at(v)
        return name in r

    def tree_externalize(self):
        """(merge-once) The TU's other functions (TREE_EXTERNAL, MSVC symbols) are stubs on both sides, as in a
        standalone check where they are only declared: their 32-bit clang names (MSVC's, or with clang's `double` return
        where MSVC's is `float`: M <-> N) and the 64-bit names of the same declarations."""
        f32 = self.img[32].funcs
        by_key = {}
        for f in f32:
            by_key.setdefault(f.replace("N", "M"), []).append(f)
        ext32 = set()
        for n in TREE_EXTERNAL:
            if n in f32:
                ext32.add(n)
                continue
            for f in by_key.get(n.replace("N", "M"), ()):
                if all(x == y or {x, y} == {"M", "N"} for x, y in zip(f, n)):
                    ext32.add(f)
        ext32.discard(self.sym32)
        loc64 = {}
        for mn, c in self.tu[64].by_mangled.items():
            if mn in self.img[64].funcs:
                loc64.setdefault((c.kind, loc_key(c)), []).append(mn)
        norm64 = {}
        for f in self.img[64].funcs:
            norm64.setdefault(norm_mangled(f), []).append(f)
        ext64 = set()
        for n in ext32:
            c = self.tu[32].by_mangled.get(n)
            hit = loc64.get((c.kind, loc_key(c))) if c is not None else None
            if not hit:
                cn = c_name(n, 32)
                hit = [cn] if cn and cn in self.img[64].funcs else norm64.get(n)
            ext64.update(hit or ())
        ext64.discard(self.sym64)
        self.img[32].externalize(ext32)
        self.img[64].externalize(ext64)

    def deleting_dtor(self, sym32, d):
        """(as equiv.py --wine, round 25) The original is a scalar deleting destructor, which clang does not emit: both
        objects get the one tools/wine_link.py synthesizes (call the complete destructor, operator delete(this) when
        flags & 1, return this), appended as module assembly."""
        import equiv
        m = re.match(r"^\?\?_G(.+)@@([A-Z])AEPAXI@Z$", sym32)
        if not m:
            raise Unsupported("deleting destructor %s" % sym32)
        cls32, acc = m.group(1), m.group(2)
        dtor32 = "??1%s@@%sAE@XZ" % (cls32, acc)
        if dtor32 not in self.img[32].funcs:
            raise Unsupported("deleting destructor without its complete destructor %s" % dtor32)
        c32 = self.tu[32].by_mangled.get(dtor32)
        dtor64 = None
        if c32 is not None:
            k = loc_key(c32)
            dtor64 = next((mn for mn, c in self.tu[64].by_mangled.items() if mn.startswith("??1") and loc_key(c) == k), None)
        if dtor64 is None or dtor64 not in self.img[64].funcs:
            dtor64 = next((f for f in self.img[64].funcs if f.startswith("??1") and norm_mangled(f) == dtor32), None)
        if dtor64 is None:
            raise Unsupported("no 64-bit complete destructor for %s (%s)" % (dtor32, [f for f in self.img[64].funcs if f.startswith("??1")]))
        m64 = re.match(r"^\?\?1(.+)@@([A-Z])EAA@XZ$", dtor64)
        if not m64:
            raise Unsupported("64-bit destructor name %s" % dtor64)
        sym64 = "??_G%s@@%sEAAPEAXI@Z" % (m64.group(1), m64.group(2))
        try:
            obj = equiv.compile_native(self.wrapper, d, ["-I" + d], tail_asm=equiv.deleting_wrapper_asm(sym32, dtor32))
        except equiv.CompileError as e:
            raise CompileError(str(e))
        if sym64 in self.img[64].funcs:
            # (x64eq) the 64-bit object defines it already (a native-only explicit instantiation emits the vftable and,
            # beside it, clang's own scalar deleting destructor: the same contract); only the 32-bit side gets one
            self.obj32 = load_obj(obj)
            self.img = {32: Image(self.obj32, 32), 64: self.img[64]}
            self.ddtor = (sym32, sym64, c32)
            return
        q, qd = '"%s"' % sym64, '"%s"' % dtor64
        lines = ["\t.text", "\t.def\t%s;\t.scl\t2;\t.type\t32;\t.endef" % q, "\t.globl\t%s" % q, "\t.p2align\t4", "%s:" % q,
                 "\tpushq\t%rbx", "\tsubq\t$48, %rsp", "\tmovq\t%rcx, %rbx", "\tmovl\t%edx, 40(%rsp)", "\tcallq\t%s" % qd,
                 "\ttestb\t$1, 40(%rsp)", "\tje\t1f", "\tmovq\t%rbx, %rcx", '\tcallq\t"??3@YAXPEAX@Z"', "1:",
                 "\tmovq\t%rbx, %rax", "\taddq\t$48, %rsp", "\tpopq\t%rbx", "\tretq"]
        w64 = os.path.join(d, "eq64_ddtor.cpp")
        with open(w64, "w") as f:
            f.write('#include "%s"\n__asm__("%s");\n' % (self.wrapper, "".join(l + "\\n" for l in lines).replace('"', '\\"')))
        p64, _ = compile64(w64, d)
        self.obj32, self.obj64 = load_obj(obj), load_obj(p64)
        self.img = {32: Image(self.obj32, 32), 64: Image(self.obj64, 64)}
        self.ddtor = (sym32, sym64, c32)

    # ---- the function under test
    def pick(self, symbol):
        name32 = symbol
        if self.ddtor:
            c = self.ddtor[2]
            c64 = next(c_ for c_ in self.tu[64].by_mangled.values() if loc_key(c_) == loc_key(c))
            self.sym32, self.sym64 = self.ddtor[0], self.ddtor[1]
            u32, u64 = FakeType("UINT", 4), FakeType("UINT", 4)
            v32, v64 = FakeType("POINTER", 4, FakeType("VOID", 0)), FakeType("POINTER", 8, FakeType("VOID", 0))
            self.sig = Sig((v32, v64), [(u32, u64)], CC_THIS, True, False,
                           (c.semantic_parent.type, c64.semantic_parent.type), self.sym32)
            self.range32 = self.img[32].func_range(self.sym32)
            return
        if name32 is not None and name32 not in self.img[32].funcs:
            # MSVC's name with a `float` return where clang's is `double` (hulk_freg): M <-> N in the return type
            alt = [f for f in self.img[32].funcs if len(f) == len(name32) and
                   all(x == y or {x, y} == {"M", "N"} for x, y in zip(f, name32))]
            if len(alt) == 1:
                name32 = alt[0]
        if name32 is None or name32 not in self.img[32].funcs:
            raise Unsupported("function under test not found in the 32-bit object (%s)" % name32)
        self.sym32 = name32
        c32 = self.tu[32].by_mangled.get(name32)
        name64 = thunk64 = None
        meth32 = thunk_method(name32) if c32 is None and "thunk" not in OFF else None
        if meth32 is not None and self.tu[32].by_mangled.get(meth32) is not None:
            # (x64eq) an adjustor thunk (`?f@C@@W3AEXXZ`: this -= 4, jump to C::f): libclang knows only the method; the
            # 64-bit thunk is the one of the same method (its adjustment is the 64-bit base offset, `W7EAA`)
            c32 = self.tu[32].by_mangled[meth32]
            k = loc_key(c32)
            m64 = next((mn for mn, c in self.tu[64].by_mangled.items() if c.kind == c32.kind and loc_key(c) == k), None)
            cand = [f for f in self.img[64].funcs if m64 is not None and thunk_method(f) == m64]
            if len(cand) == 1:
                name64, thunk64 = cand[0], m64
        if c32 is not None and name64 is None:
            k = loc_key(c32)
            for mn, c in self.tu[64].by_mangled.items():
                if c.kind == c32.kind and loc_key(c) == k and mn in self.img[64].funcs:
                    name64 = mn
                    break
        if name64 is None and name32 not in self.img[32].funcs:
            pass
        if name64 is None:
            n = c_name(name32, 32)
            if n and n in self.img[64].funcs:
                name64 = n
            else:
                cand = [f for f in self.img[64].funcs if norm_mangled(f) == name32]
                name64 = cand[0] if cand else None
        if name64 is None:
            raise Unsupported("function under test not found in the 64-bit object")
        self.sym64 = name64
        c64 = self.tu[64].by_mangled.get(thunk64 or name64)
        if c32 is None or c64 is None:
            raise Unsupported("no declaration for %s" % name32)
        self.sig = Sig.of(c32, c64, name32)
        self.param_casts = {}
        if "casts" not in OFF:
            # (the definition's body: a TU can declare the function before it defines it, merge-once)
            a32, a64 = param_casts(c32.get_definition() or c32), param_casts(c64.get_definition() or c64)
            for k in a32:
                if k in a64:
                    self.param_casts[k] = (a32[k], a64[k])
        self.gdata_used = {}    # (integ2, D103) {global: model} of the HULK_RANGE / HULK_RDATA globals a run used
        self.gcasts = {}        # (integ2, D111) {32-bit var id: (T*32, T*64) or AMBIGUOUS} (global_casts)
        self.gcasts_used = {}   # (integ2, D111) {global: "T" / "T (view)" / "ambiguous"} of the typed globals a run used
        if "gcasts" not in OFF:
            g32, g64 = global_casts(c32.get_definition() or c32), global_casts(c64.get_definition() or c64)
            def nk_(k, bits):     # the 32-bit C name's leading underscore
                return "m:" + k[3:] if bits == 32 and k.startswith("m:_") else k
            k64 = {nk_(k, 64): v for k, v in g64.items()}
            for k, v in g32.items():
                w = k64.get(nk_(k, 32))
                if w is None:
                    continue
                self.gcasts[k] = AMBIGUOUS if AMBIGUOUS in (v, w) else (v, w)
        self.param_range = {}
        if "paramrange" not in OFF:
            r32, r64 = param_range(c32.get_definition() or c32), param_range(c64.get_definition() or c64)
            if r32 != r64:
                raise Unsupported("HULK_RANGE: the 32- and 64-bit parses disagree (%s / %s)" % (r32, r64))
            self.param_range = r32
        # (integ3, D152; rev5) the block's range contract (`// pre: range|gt|ge|lt|le(argN, ...)`): drawn arguments are
        # repaired into the domain as equiv.py does (both sides alike), so the comparison stays inside it
        self.pre_ranges = pre_ranges(c32.get_definition() or c32) if "prerange" not in OFF else {}
        self.pre_oranges = pre_oranges(c32.get_definition() or c32) if "prerange" not in OFF else {}
        import equiv
        if any(equiv._pre_relational(c_) for c_ in self.pre_ranges.values()):
            pre_relational_check(c32.get_definition() or c32, self.addr)
        self.param_into = {}
        a32, a64 = param_into(c32.get_definition() or c32), param_into(c64.get_definition() or c64)
        if a32 != a64 and "intocheck" not in OFF:
            # (integ1, rev5/D61) the two parses must agree on every HULK_INTO: refuse instead of dropping it silently
            raise Unsupported("HULK_INTO: the 32- and 64-bit parses disagree (%s / %s)" % (a32, a64))
        for k in a32:
            if a64.get(k) == a32[k]:
                self.param_into[k] = a32[k]
        self.types.field_casts = {}
        if "fieldcasts" not in OFF:
            f32, f64 = field_casts(c32.get_definition() or c32), field_casts(c64.get_definition() or c64)
            for k in f32:
                if k in f64:
                    amb_ = AMBIGUOUS in (f32[k], f64[k])
                    self.types.field_casts[k] = (AMBIGUOUS, AMBIGUOUS) if amb_ else (f32[k], f64[k])
        self.ret_casts = {}
        self.site_casts = {}
        if "retcasts" not in OFF:
            r32, r64 = return_casts(c32.get_definition() or c32), return_casts(c64.get_definition() or c64)
            for k in r32:
                if k in r64:
                    self.ret_casts[k] = (r32[k].get_pointee(), r64[k].get_pointee())
            # (x64t9, sitecasts) a callee whose call sites cast its result differently: each site's own type
            self.site_casts = {}
            if "sitecasts" not in OFF:
                s32 = return_casts(c32.get_definition() or c32, True)
                s64 = return_casts(c64.get_definition() or c64, True)
                for k, l32 in s32.items():
                    l64 = s64.get(k)
                    if l64 is None or len(l64) != len(l32) or len(l32) < 2:
                        continue
                    kinds = {None if t is None else t.get_canonical().spelling for t in l32}
                    if len(kinds) > 1:
                        self.site_casts[k] = [None if a is None or b is None else (a.get_pointee(), b.get_pointee())
                                              for a, b in zip(l32, l64)]
        # (integ3, allocty; rev5 R2') per allocator call site, in source order: the record T when its size argument is
        # `n * sizeof(T)` (an array of T: every whole record typed), else None (element 0 only, the rest raw)
        self.site_arrays = alloc_site_arrays(c32.get_definition() or c32) if "allocty" not in OFF else {}
        # (integ3, allocty regions; 0x000afbf0) per allocator call site: (off32, off64, (T32, T64), array) when the body
        # casts the allocation's pointer plus a constant to a record pointer (`(Elem*)(raw + 1)`: an array-new cookie)
        self.site_regions = alloc_site_regions(c32.get_definition() or c32, c64.get_definition() or c64) \
            if "allocty" not in OFF and "allocregion" not in OFF else {}
        self.range32 = self.img[32].func_range(name32)
        self.ast_digest = ast_digest(c32, c64)
        if "post" not in OFF:
            post_macro_check(c32.get_definition() or c32, self)

    def _pick_by_original(self):
        """The MSVC 7.1 object of the source names the function (equiv.py's natmap); else the only external function."""
        import equiv
        try:
            prog = equiv.Program.get()
            size, _ = prog.funcs[self.addr]
            target = prog.read(self.addr, size)
            d = tempfile.mkdtemp(dir=self.tmp.name)
            mobj = equiv.Obj(equiv.compile_obj(self.src, equiv.DEFAULT_FLAGS, d))
            ms = equiv.pick_symbol(mobj, self.addr, target)
            if ms and ms[0] in self.img[32].funcs:
                return ms[0]
            if ms:
                return ms[0]
        except Exception as e:   # noqa: BLE001
            if self.verbose:
                print("pick by original failed:", e, file=sys.stderr)
        hexa = "%08x" % self.addr
        c = [f for f in self.img[32].funcs if hexa in f.lower()]
        if len(c) == 1:
            return c[0]
        return None

    # ---- symbols
    def canon_name(self, name, bits):
        """The target-independent key of a symbol: its declaration's location, a C name, or the i386 mangled form."""
        if name in SIZED_DELETE and "sizeddel" not in OFF:
            name = SIZED_DELETE[name]
        c = self.tu[bits].by_mangled.get(name)
        if c is not None:
            return "decl:" + loc_key(c)
        cn = c_name(name, bits)
        if cn is not None:
            return "c:" + cn
        return "m:" + (name if bits == 32 else norm_mangled(name))

    def resolve_all(self):
        """Every undefined symbol of each image -> a stub (function) or a global object (data)."""
        self.ext = {32: {}, 64: {}}     # name -> ("stub", Stub) | ("data", key)
        self.data_keys = {}
        for bits in (32, 64):
            for name in self.img[bits].undef:
                key = self.canon_name(name, bits)
                c = self.tu[bits].by_mangled.get(name)
                K = ci().CursorKind
                is_data = (c is not None and c.kind == K.VAR_DECL) or name.startswith("??_7") or \
                    name.startswith("??_R") or name in ("__fltused", "_fltused", "___security_cookie", "__security_cookie") \
                    or (c is None and re.match(r"^_?(DAT|g|PTR|s)_[0-9a-fA-F]{6,8}", name) is not None)
                if is_data:
                    self.ext[bits][name] = ("data", key)
                    self.data_keys.setdefault(key, {})[bits] = (name, c)
                else:
                    st = self.stub_by_key.get(key)
                    if st is None:
                        st = self.new_stub(key, None, "func", label=name)
                    st.names[bits] = name
                    self.ext[bits][name] = ("stub", st)
        self.global_views = self.pinned_views() if TREE_ACTIVE and "pinview" not in OFF else {}
        # signatures of function stubs from both parses
        for st in self.stubs:
            if st.kind != "func":
                continue
            n32, n64 = st.names.get(32), st.names.get(64)
            c32 = self.tu[32].by_mangled.get(n32) if n32 else None
            c64 = self.tu[64].by_mangled.get(n64) if n64 else None
            if "sizeddel" not in OFF and (c32 is None) != (c64 is None) and \
                    SIZED_DELETE.get(n32, n32) in IMPLICIT_SIGS and SIZED_DELETE.get(n64, n64) == IMPLICIT_SIGS[SIZED_DELETE.get(n32, n32)][0]:
                c32 = c64 = None    # (x64eq) one side's operator delete is declared, the other's sized one is implicit
            if c32 is not None and c64 is not None:
                try:
                    st.sig = Sig.of(c32, c64, st.label)
                except Exception:   # noqa: BLE001
                    st.sig = None
            elif "sizeddel" not in OFF and SIZED_DELETE.get(n32, n32) in IMPLICIT_SIGS and \
                    SIZED_DELETE.get(n64, n64) == IMPLICIT_SIGS[SIZED_DELETE.get(n32, n32)][0]:
                st.sig = IMPLICIT_SIGS[SIZED_DELETE.get(n32, n32)][1]()
            elif n32 in IMPLICIT_SIGS and n64 == IMPLICIT_SIGS[n32][0]:
                st.sig = IMPLICIT_SIGS[n32][1]()
            elif n32 and n64 and n32.startswith("??1") and n32.endswith("AE@XZ") and n64.endswith("EAA@XZ"):
                # a destructor of a template instance (no declaration cursor): void (this), thiscall
                st.sig = Sig((FakeType("VOID", 0), FakeType("VOID", 0)), [], CC_THIS, True, False, None, n32)

    def pinned_views(self):
        """(merge-once) {data key: (T32, T64)} for the pinned globals the function under test reads through a typed
        view: gen_tree replaces a wrapped source's `extern World* DAT_004dd700;` by the view `#define DAT_004dd700
        (*(World* *)&::DAT_004dd700)` of the TU's one declaration (a void*, or the TU's own `World*`, another class).
        The global is the view's type (the block's World*), as it is where the function is checked from its own
        source. Only the names the function's block defines such a view for (TREE_PINNED)."""
        K = ci().CursorKind
        found = {}
        if not TREE_PINNED:
            return {}
        for bits, sym in ((32, self.sym32), (64, self.sym64)):
            c = self.tu[bits].by_mangled.get(sym)
            c = (c.get_definition() or c) if c is not None else None
            if c is None:
                return {}
            for x in c.walk_preorder():
                if x.kind != K.CSTYLE_CAST_EXPR:
                    continue
                ct = x.type.get_canonical()
                if ct.kind.name != "POINTER":
                    continue
                kids = list(x.get_children())
                while kids and kids[-1].kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR) and len(list(kids[-1].get_children())) == 1:
                    kids = list(kids[-1].get_children())
                if not kids or kids[-1].kind != K.UNARY_OPERATOR:
                    continue
                toks = [tk.spelling for tk in kids[-1].get_tokens()]
                inner = list(kids[-1].get_children())
                if not toks or toks[0] != "&" or len(inner) != 1 or inner[0].kind != K.DECL_REF_EXPR:
                    continue
                v = inner[0].referenced
                if v is None or v.kind != K.VAR_DECL or v.spelling not in TREE_PINNED:
                    continue
                key = "decl:" + loc_key(v)
                found.setdefault(key, {}).setdefault(bits, set()).add(ct.get_pointee().spelling)
                found[key].setdefault(("t", bits), ct.get_pointee())
        out = {}
        for key, f in found.items():
            if len(f.get(32, ())) == 1 and len(f.get(64, ())) == 1 and key in self.data_keys:
                out[key] = (f[("t", 32)], f[("t", 64)])
        return out

    def global_model(self, key):
        """(integ2, D103) The data model (gdata_models) of the global with data key KEY: both parses must agree."""
        cache = self.__dict__.setdefault("_gmodels", {})
        if key in cache:
            return cache[key]
        ent = self.data_keys.get(key, {})
        m = {}
        for bits in (32, 64):
            c = ent.get(bits, (None, None))[1]
            m[bits] = global_model(self.tu[bits].tu, c) if c is not None else None
        if m[32] != m[64]:
            raise Unsupported("data annotation on %s: the 32- and 64-bit parses disagree (%s / %s)" % (key, m[32], m[64]))
        mod = m[32]
        if mod is not None and mod[0] == "unsupported":
            raise Unsupported(mod[1])
        cache[key] = mod
        return mod

    def _annotated_decls(self, c32):
        """(integ2, D103) The declarations of C32's variable (32-bit parse) that carry a data annotation."""
        if c32 is None:
            return []
        want = _var_id(c32)
        K = ci().CursorKind
        out = []
        for c in self.tu[32].tu.cursor.walk_preorder():
            if c.kind == K.VAR_DECL and any(a.kind == K.ANNOTATE_ATTR for a in c.get_children()):
                try:
                    if _var_id(c) == want:
                        out.append(c)
                except Exception:   # noqa: BLE001
                    pass
        return out

    def apply_global_model(self, o, key, mod, lay, c32):
        """(integ2, D103; rev5's review) Give the new global object O its annotated contents. Both annotations need the
        global's DAT_ address name and a config/data.json item that starts there with the declared size (R2).
        HULK_RANGE(lo, hi): every leaf an "i" integer of one size on both targets (a table of indices); the game's own
        initial image (file bytes, zero fill past them) in lo..hi (R1); the annotated declaration's comment cites
        every reference the XBE has into the table (range_census, R3); the generator then draws each word from lo..hi
        on both sides, nothing compared changes.
        HULK_RDATA: the declaration const; the item a plain scalar table (no pointers, no vftable); file data of a
        non-executable XBE section without the WRITABLE flag; scalars (i/f/d/b) at the same offsets and sizes on both
        targets: both sides start from the game's own bytes; a store into it refuses the check."""
        import equiv
        name = c32.spelling if c32 is not None else key
        what = "HULK_RANGE" if mod[0] == "range" else "HULK_RDATA"
        leaves = lay.leaves
        m = re.search(r"DAT_([0-9a-fA-F]{8})$", name)
        if not m:
            raise Unsupported("%s on %s: no DAT_ address name" % (what, name))
        addr, n = int(m.group(1), 16), lay.size32
        if lay.size32 != lay.size64:
            raise Unsupported("%s on %s: its size differs between the targets" % (what, name))
        xbe = equiv.Program.get().xbe
        sec = xbe.section_of(addr)
        if mod[0] == "rdata":
            # (R2) the section first: .text and the BINK sections have no WRITABLE flag either
            if sec is None or sec.executable or (sec.flags & 1) or addr + n > sec.va + sec.rsize:
                raise Unsupported("HULK_RDATA on %s: 0x%08x..+0x%x is not file data of a read-only data section of the "
                                  "XBE (%s)" % (name, addr, n, "none" if sec is None else "%s flags 0x%x" % (
                                      sec.name, sec.flags)))
        it = data_item(addr)
        if it is None or it.get("size") != n:
            raise Unsupported("%s on %s: config/data.json has no item of %d bytes at 0x%08x (%s)" % (
                what, name, n, addr, "none" if it is None else "%s, %s bytes" % (it.get("kind"), it.get("size"))))
        if mod[0] == "range":
            lo, hi = mod[1], mod[2]
            if not mod[3]:
                raise Unsupported("HULK_RANGE on the global %s without a comment citing the writer sites (0x addresses)"
                                  % name)
            for l in leaves:
                if l.kind != "i" or l.s32 != l.s64:
                    raise Unsupported("HULK_RANGE on the global %s: %s is not an integer of one size on both targets"
                                      % (name, name + "".join("[%s]" % x for x in l.path)))
                n_ = 8 * l.s32
                lo_ok = lo >= (-(1 << (n_ - 1)) if l.signed else 0)
                hi_ok = hi <= ((1 << (n_ - 1)) - 1 if l.signed else (1 << n_) - 1)
                if lo > hi or not (lo_ok and hi_ok):
                    raise Unsupported("HULK_RANGE(%d, %d) on the global %s does not fit its %d-byte %s words" % (
                        lo, hi, name, l.s32, "signed" if l.signed else "unsigned"))
            # (R1) the image the game starts from must hold the claim too
            img = xbe_image(addr, n)
            for l in leaves:
                v = int.from_bytes(img[l.o32:l.o32 + l.s32], "little", signed=l.signed)
                if not lo <= v <= hi:
                    raise Unsupported("HULK_RANGE(%d, %d) on the global %s: the XBE's initial word at +0x%x is %d" % (
                        lo, hi, name, l.o32, v))
            if "census" not in OFF:     # (R3: mandatory; EQ64_OFF=census is a development switch, proves nothing)
                txt_ = "\n".join(_comment_block(c) for c in self._annotated_decls(c32))
                miss_ = range_census(addr, n, txt_)
                if miss_:
                    raise Unsupported("HULK_RANGE on the global %s: its comment doesn't cite the XBE's references %s"
                                      % (name, ", ".join(miss_[:6]) + (" ..." if len(miss_) > 6 else "")))
            o.grange = (lo, hi)
            self.gdata_used[name] = ["range", lo, hi]
            return
        # rdata
        if c32 is None or not _const_object(c32.type):
            raise Unsupported("HULK_RDATA on %s, which is not declared const" % name)
        if it.get("kind") not in RDATA_KINDS or "*" in (it.get("type") or ""):
            raise Unsupported("HULK_RDATA on %s: the data.json item is no plain scalar table (%s %s)" % (
                name, it.get("kind"), it.get("type")))
        if any(l.kind not in ("i", "f", "d", "b") or l.o32 != l.o64 or l.s32 != l.s64 for l in leaves):
            raise Unsupported("HULK_RDATA on %s: not all scalars at the same offsets on both targets" % name)
        b = xbe_image(addr, n)
        # (rev5's R7) a word that is an address of the image is a pointer however data.json types it (an SEH scope
        # table, a table of {id, string} pairs): natively it would be 8 bytes elsewhere. The whole image counts, from
        # its header (the base, 0x10000) to the end of the last section
        img_hi = max(sc.va + sc.vsize for sc in xbe.sections)
        for k_ in range(0, n - 3, 4):
            v_ = int.from_bytes(b[k_:k_ + 4], "little")
            if xbe.base <= v_ < img_hi:
                sc = xbe.section_of(v_)
                raise Unsupported("HULK_RDATA on %s: the word at +0x%x is 0x%08x, an address in the XBE's %s" % (
                    name, k_, v_, sc.name if sc is not None else "image"))
        o.init = {32: b, 64: b}
        o.rdata = name
        self.gdata_used[name] = ["rdata", sec.name]

    def new_stub(self, key, sig, kind, label=""):
        st = Stub(key, sig, kind, len(self.stubs), label)
        if len(self.stubs) >= STUB_SLOTS:
            raise Unsupported("too many stubs")
        self.stubs.append(st)
        self.stub_by_key[key] = st
        return st

    def post_of(self, name):
        """(integ4, post) The post items of the function NAME stands for: FUN_<addr> in it, or (rev5) its 32-bit symbol
        a tree block's `// sym:` pins (tree namespaces dropped). None without."""
        if not hasattr(self, "_post_idx"):
            try:
                txt = open(self.src, errors="replace").read()
            except OSError:
                txt = ""
            self._post_idx = post_contracts(txt)
        m = re.search(r"FUN_([0-9a-fA-F]{8})", name or "")
        if m:
            return self._post_idx.get(int(m.group(1), 16))
        a = self._post_idx.get("sym", {}).get(TREE_NS.sub("", name or ""))
        return self._post_idx.get(a) if a is not None else None

    def ret_post_of(self, name):
        """(integ9, D165) The accepted return range of the function NAME stands for (FUN_<addr> in it, or its 32-bit symbol
        a return-post block's `// sym:` pins), never the function under check (its own recursion); else None."""
        if "calleepost" in OFF or "post" in OFF:
            return None
        a = ret_post_addr(name)
        if a is None or a == self.addr:
            return None
        return ret_post_accept(a)[0]

    def stub_addr(self, key):
        return STUBS + 16 * self.stub_by_key[key].idx

    def fnptr_stub(self, key, ftypes, method=None):
        st = self.stub_by_key.get(key)
        if st is None:
            sig = Sig.of(ftypes[0], ftypes[1], "fnptr")
            if method is not None:
                sig.has_this, sig.method_record = True, method      # (a member function: this first; thiscall on i386)
            st = self.new_stub(key, sig, "fnptr", "mfptr" if method is not None else "fnptr")
        return st

    def vtable_obj(self, heap, vkey):
        """The vftable object a vfptr of subobject vkey[1] in most-derived vkey[0] points at: slots are stubs."""
        o = heap.by_ident.get(("vt", vkey))
        if o is not None:
            return o
        entries = self.vtables.get(vkey) or self.vtables.get((vkey[1], vkey[1]))
        n = len(entries) if entries else 64
        if not entries:
            self.flags.add("vtable_unknown")
        stubs = []
        for i in range(n):
            k = ("vslot", vkey, i)
            st = self.stub_by_key.get(k)
            if st is None:
                sig = self.slot_sig(vkey, entries[i]) if entries else None
                st = self.new_stub(k, sig, "vslot", entries[i] if entries else "%s slot %d" % (vkey[1], i))
            stubs.append(st)
        o = heap.get(("vt", vkey), "vtable", RAW, glob=True, alloc=(4 * n + 4, 8 * n + 8))
        b32 = struct.pack("<I", 0) + b"".join(struct.pack("<I", STUBS + 16 * s.idx) for s in stubs)
        b64 = struct.pack("<Q", 0) + b"".join(struct.pack("<Q", STUBS + 16 * s.idx) for s in stubs)
        o.init = {32: b32, 64: b64}     # (a vfptr points past the RTTI locator slot: offset 4 / 8)
        return o

    def slot_sig(self, vkey, entry):
        """The signature of a vftable entry (`int C::f(int, B *)`, `C::~C() [vector deleting]`)."""
        if "deleting]" in entry:
            return ("deleting",)
        parsed = parse_entry(entry)
        if parsed is None:
            return None
        cls, meth, ptext = parsed
        nparams = 0 if not ptext.strip() or ptext.strip() == "void" else len(split_params(ptext))
        cs = []
        for bits in (32, 64):
            rec = self.tu[bits].records.get(cls)
            if rec is None:
                return None
            hit = None
            for c in rec.get_children():
                if c.spelling == meth and c.kind.name in ("CXX_METHOD", "DESTRUCTOR") and len(list(c.get_arguments())) == nparams:
                    if hit is not None and hit.displayname.replace(" ", "") != c.displayname.replace(" ", ""):
                        want = (meth + "(" + ptext + ")").replace(" ", "")
                        if c.displayname.replace(" ", "") == want:
                            hit = c
                        continue
                    hit = hit or c
            if hit is None:
                return None
            cs.append(hit)
        return Sig.of(cs[0], cs[1], entry)

    # ---- running
    def run(self, n_inputs=200, seeds=None, time_budget=120):
        t0 = time.process_time()
        res = {"inputs": 0, "completed": 0, "skipped": {}, "fails": [], "classes": {}}
        cov = set()
        seq = seeds if seeds else range(n_inputs)
        import equiv
        w0 = time.time()
        k0 = _work()
        kn0 = dict(WORKN)
        seq_ = hashlib.sha1()        # (integ3, rev5 (c)) the inputs and what each gave, for the selftest
        for seed in seq:
            if "workclock" in equiv.EQUIV_OFF:
                if (time.process_time() - t0 > time_budget or time.time() - w0 > 3 * time_budget) and not seeds:
                    res["stopped"] = "time budget"
                    break
            elif not seeds and (_work() - k0) / WORK_PER_SEC > time_budget:
                res["stopped"] = "time budget"
                break
            elif not seeds and time.process_time() - t0 > WALL_CAP * time_budget:
                res["stopped"] = "time budget"
                res["time_cut_wall"] = True
                break
            res["inputs"] += 1
            out = self.one(seed)
            seq_.update(("%s|%s|%s\n" % (seed, out.get("skip"), out.get("class") if out.get("diff") else "")).encode())
            if getattr(self, "wall_cut", False):
                # (integ3, rev5 1) an input a wall-clock timeout cut: the run proves nothing on any host
                res["stopped"] = "time budget"
                res["time_cut_wall"] = True
                break
            if out.get("skip"):
                res["skipped"][out["skip"]] = res["skipped"].get(out["skip"], 0) + 1
                res.setdefault("skip_first", {}).setdefault(out["skip"], out.get("why"))
                continue
            res["completed"] += 1
            if out.get("allocty"):
                res["allocty"] = res.get("allocty", 0) + 1
            cov |= out.get("cov", set())
            if out.get("diff"):
                c = out["class"]
                res["classes"][c] = res["classes"].get(c, 0) + 1
                if len(res["fails"]) < 3:
                    res["fails"].append({"seed": seed, "class": c, "diff": out["diff"]})
                if len(res["fails"]) >= 3 and not seeds:
                    break
        res["cov"] = cov
        res["work"] = int(_work() - k0)
        res["workn"] = {k: WORKN[k] - kn0[k] for k in WORKN}
        res["input_digest"] = seq_.hexdigest()[:12]
        res["cpu"] = round(time.process_time() - t0, 2)
        return res

    def one(self, seed):
        heap = Heap(self, seed)
        self.flags = set()
        r32 = Side(self, 32, heap, seed).call()
        if r32.get("skip"):
            return {"skip": r32["skip"], "why": (r32.get("stop") or ("", ""))[1]}
        if heap.count_cap:
            return {"skip": "count_cap", "why": heap.count_cap}      # (integ4, x64bounds)
        r64 = Side(self, 64, heap, seed).call()
        if heap.count_cap:
            return {"skip": "count_cap", "why": heap.count_cap}
        out = {"cov": r32.get("cov", set())}
        past = [k for k in written_locations(r32["side"]) if k[0] == "past"]
        if past:
            # the 32-bit run itself writes past an object its source types (a stub class smaller than the real
            # one, an index out of range): not comparable
            o = heap.objs[past[0][1]]
            return {"skip": "oob", "why": "32-bit write past the end of %s (+0x%x)" % (describe(o), past[0][3])}
        w32, w64 = r32["side"].wild, r64["side"].wild
        if w32 and (w32 != w64 or r64.get("stop")):
            # memory no object covers, at addresses that differ between the runs (an index or a pointer computed
            # out of range of every object: 32-bit address arithmetic wraps, 64-bit doesn't): not comparable
            return {"skip": "wild", "why": "32-bit run read 0x%x, outside every object" % min(w32)}
        diff, cls = compare(self, heap, r32, r64)
        if heap.allocty:
            out["allocty"] = True
        if diff:
            out["diff"], out["class"] = diff, cls
        return out


def parse_entry(entry):
    """`Camera *Ns::Cls<A, B>::f(int, B *) const [pure]` -> ("Ns::Cls<A,B>", "f", "int, B *")."""
    depth = 0
    open_at = None
    for i, ch in enumerate(entry):
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        elif ch == "(" and depth == 0:
            open_at = i
            break
    if open_at is None:
        return None
    close = entry.rfind(")")
    if close < open_at:
        return None
    head = entry[:open_at]
    k = head.rfind("::")
    if k < 0:
        return None
    meth = head[k + 2:]
    j, depth = k, 0
    while j > 0:
        ch = head[j - 1]
        if ch == ">":
            depth += 1
        elif ch == "<":
            depth -= 1
        elif depth == 0 and ch in " *&":
            break
        j -= 1
    return head[j:k].replace(" ", ""), meth, entry[open_at + 1:close]


INTO_ATTR = re.compile(r"^hulk_into (\w+)$")


def param_into(fn):
    """(x64t13) {parameter index: field name} for the pointer parameters annotated HULK_INTO(field)
    (include/decls/data/records.h): the pointer is into the array `this->field` points to (a pool's block, from the
    pool's data). The generator makes it point there, at a fuzzed offset; nothing compared changes."""
    K = ci().CursorKind
    out = {}
    params = [c for c in fn.get_children() if c.kind == K.PARM_DECL]
    for i, p in enumerate(params):
        for a in p.get_children():
            if a.kind == K.ANNOTATE_ATTR:
                m = INTO_ATTR.match(a.spelling or "")
                if m:
                    out[i] = m.group(1)
    return out


def _cited_tables(p, fn):
    """(integ2, D102; rev5's review) [(address, element count)] of the 0x addresses cited on parameter P's lines (and the
    line before) that name an array the translation unit declares, `DAT_00527c60[46]`."""
    K = ci().CursorKind
    try:
        f = p.extent.start.file.name
        lines = open(f, errors="replace").read().split("\n")
        lo_ = p.extent.start.line - 1
        while lo_ > 0 and lines[lo_ - 1].lstrip().startswith("//"):
            lo_ -= 1            # (the whole comment block above the declaration)
        txt = "\n".join(lines[lo_:p.extent.end.line])
    except Exception:   # noqa: BLE001
        return []
    want = {int(x, 16) for x in re.findall(r"0x([0-9a-fA-F]{5,})", txt)}
    if not want:
        return []
    out = []

    def decls(c, depth=0):
        for ch in c.get_children():
            if ch.kind == K.VAR_DECL:
                yield ch
            elif ch.kind in (K.LINKAGE_SPEC, K.NAMESPACE, K.UNEXPOSED_DECL) and depth < 4:
                yield from decls(ch, depth + 1)
    for c in decls(fn.translation_unit.cursor):
        m = re.match(r"^DAT_([0-9a-fA-F]{8})$", c.spelling or "")
        if not m or int(m.group(1), 16) not in want:
            continue
        t = c.type.get_canonical()
        if t.kind.name == "CONSTANTARRAY":
            out.append((int(m.group(1), 16), t.get_array_size()))
    return out


def _range_uses(fn, p):
    """(integ2, D102; rev5's design) [(array name, element count)] of the subscripts FN's body indexes with parameter P
    alone (through parentheses, casts and implicit conversions only). Every other reference to P must be a whole call
    argument or an operand of a comparison or a switch; anything else raises Unsupported ("can't be derived from its
    uses")."""
    K = ci().CursorKind
    THRU = (K.PAREN_EXPR, K.UNEXPOSED_EXPR, K.CSTYLE_CAST_EXPR, K.CXX_STATIC_CAST_EXPR, K.CXX_FUNCTIONAL_CAST_EXPR)
    CMP = ("EQ", "NE", "LT", "GT", "LE", "GE")
    out = []

    def const_array(c):
        while c.kind in THRU:
            k = [x for x in c.get_children() if x.kind != K.TYPE_REF]
            if len(k) != 1:
                return None
            c = k[0]
        if c.kind == K.DECL_REF_EXPR and c.referenced is not None and c.referenced.kind == K.VAR_DECL:
            t = c.referenced.type.get_canonical()
            if t.kind.name == "CONSTANTARRAY":
                return c.referenced.spelling, t.get_array_size()
        return None

    def visit(c, stack, depth=0):
        if depth > 300:
            raise Unsupported("HULK_RANGE: the body is too deep to check the uses of %s" % p.spelling)
        if c.kind == K.DECL_REF_EXPR and c.referenced is not None and c.referenced.hash == p.hash:
            # climb the transparent wrappers to the first real parent
            child, i = c, len(stack) - 1
            while i >= 0 and stack[i].kind in THRU:
                child, i = stack[i], i - 1
            par = stack[i] if i >= 0 else None
            kids = list(par.get_children()) if par is not None else []
            if par is not None and par.kind == K.ARRAY_SUBSCRIPT_EXPR and len(kids) == 2 and kids[1].hash == child.hash:
                b_ = const_array(kids[0])
                if b_ is None:
                    raise Unsupported("HULK_RANGE: the bound on %s can't be derived from its uses (a subscript on "
                                      "something that is no constant array)" % p.spelling)
                out.append(b_)
            elif par is not None and par.kind == K.CALL_EXPR and _by_value_arg(par, child):
                pass        # (ii) a whole call argument, passed by value (a non-const reference could change it)
            elif par is not None and par.kind == K.BINARY_OPERATOR and \
                    getattr(getattr(par, "binary_operator", None), "name", "") in CMP:
                pass        # (iii) a comparison operand
            elif par is not None and par.kind == K.SWITCH_STMT and kids and kids[0].hash == child.hash:
                pass        # (iii) a switch's condition
            else:
                raise Unsupported("HULK_RANGE: the bound on %s can't be derived from its uses (%s at line %d)" % (
                    p.spelling, par.kind.name if par is not None else "?", c.location.line))
            return
        stack.append(c)
        for ch in c.get_children():
            visit(ch, stack, depth + 1)
        stack.pop()
    # (rev5's spot-check) every child but the parameters' declarations: the body and a constructor's member
    # initializers (`: v(DAT_00527c60[index + 1].allocator)`)
    for ch in fn.get_children():
        if ch.kind != K.PARM_DECL:
            visit(ch, [])
    return out


def _by_value_arg(call, arg):
    """(integ2, D102; rev5's spot-check) Is ARG (a cursor among CALL's arguments) passed by value: the callee's matching
    parameter is not a non-const reference or a pointer (a variadic argument is by value)? False when ARG is the
    callee itself or the callee's type can't be read."""
    args = list(call.get_arguments())
    K = ci().CursorKind
    ref = call.referenced
    if ref is not None and ref.kind == K.CXX_METHOD and not ref.is_static_method() and \
            len(args) == len([c for c in ref.get_children() if c.kind == K.PARM_DECL]) + 1:
        # (rev5's spot-check) a member operator call (`b(index, 0)` for `operator()(int&, int)`): libclang counts the
        # object as argument 0; the parameters match the arguments after it
        args = args[1:]
    j = next((i for i, a in enumerate(args) if a.hash == arg.hash), None)
    if j is None:
        return False
    ft = None
    if call.referenced is not None and call.referenced.type is not None:
        ft = call.referenced.type.get_canonical()
    if ft is None or ft.kind.name not in ("FUNCTIONPROTO", "FUNCTIONNOPROTO"):
        kids = list(call.get_children())
        t = kids[0].type.get_canonical() if kids else None
        if t is not None and t.kind.name in ("POINTER", "MEMBERPOINTER"):
            t = t.get_pointee().get_canonical()
        ft = t
    if ft is None or ft.kind.name not in ("FUNCTIONPROTO", "FUNCTIONNOPROTO"):
        return False
    pts = list(ft.argument_types()) if ft.kind.name == "FUNCTIONPROTO" else []
    if j >= len(pts):
        return ft.kind.name == "FUNCTIONNOPROTO" or ft.is_function_variadic()
    pt = pts[j].get_canonical()
    if pt.kind.name in ("LVALUEREFERENCE", "RVALUEREFERENCE"):
        return pt.get_pointee().is_const_qualified()
    return pt.kind.name != "POINTER"


def _subscript_tables(fn, p):
    """(integ2, D102; rev5's spot-check) [(name, element count)] of the constant arrays FN's body subscripts with an
    index expression that refers to parameter P (`DAT_00527c60[a].allocator`, `t[i + 1]`)."""
    K = ci().CursorKind
    out = []

    def refers(c, depth=0):
        if depth > 60:
            return False
        if c.kind == K.DECL_REF_EXPR and c.referenced is not None and c.referenced.hash == p.hash:
            return True
        return any(refers(ch, depth + 1) for ch in c.get_children())

    def base_array(c):
        while c.kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR, K.CSTYLE_CAST_EXPR):
            k = [x for x in c.get_children() if x.kind != K.TYPE_REF]
            if len(k) != 1:
                return None
            c = k[0]
        if c.kind == K.DECL_REF_EXPR and c.referenced is not None and c.referenced.kind == K.VAR_DECL:
            t = c.referenced.type.get_canonical()
            if t.kind.name == "CONSTANTARRAY":
                return c.referenced.spelling, t.get_array_size()
        return None

    def walk(c, depth=0):
        if depth > 200:
            return
        if c.kind == K.ARRAY_SUBSCRIPT_EXPR:
            k = list(c.get_children())
            if len(k) == 2:
                b_ = base_array(k[0])
                if b_ is not None and refers(k[1]):
                    out.append(b_)
        for ch in c.get_children():
            walk(ch, depth + 1)
    for ch in fn.get_children():
        if ch.kind == K.COMPOUND_STMT:
            walk(ch)
    return out


def param_range(fn):
    """(integ2, D102) {parameter index: (lo, hi)} for the integer parameters annotated HULK_RANGE(lo, hi) in FN's
    definition (`void* FUN_00266e00(int a HULK_RANGE(0, 45), int b)`): the values its callers pass, where the code uses
    the parameter as an index into a table of known size. As for a field (D61), the declaration must cite its evidence
    (a comment on its lines or the line before naming a 0x address: the table, the call sites); the generator draws the
    argument from the range on both sides, nothing compared changes. Raises Unsupported for an uncited annotation or
    one on a parameter that is not an integer."""
    K = ci().CursorKind
    out = {}
    params = [c for c in fn.get_children() if c.kind == K.PARM_DECL]
    for i, p in enumerate(params):
        for a in p.get_children():
            if a.kind == K.ANNOTATE_ATTR:
                m = RANGE_ATTR.match(a.spelling or "")
                if not m:
                    continue
                t = p.type.get_canonical()
                if t.kind.name not in INT_KINDS:
                    raise Unsupported("HULK_RANGE on parameter %s of %s, not an integer" % (p.spelling, fn.spelling))
                if not _cites_writers(p):
                    raise Unsupported("HULK_RANGE on parameter %s of %s without a comment citing its evidence (0x "
                                      "addresses)" % (p.spelling, fn.spelling))
                lo, hi = int(m.group(1)), int(m.group(2))
                # (rev5's review) a cited address that names a table of known size (`MemoryHeapSlot DAT_00527c60[46]`)
                # bounds the range: an index range past the table is refused, not drawn
                for a_, n_ in _cited_tables(p, fn):
                    if lo < 0 or hi >= n_:
                        raise Unsupported("HULK_RANGE(%d, %d) on parameter %s of %s reaches past the cited table "
                                          "DAT_%08x[%d]" % (lo, hi, p.spelling, fn.spelling, a_, n_))
                # (rev5's spot-checks, his design) every use of the parameter in the body must be one the bound can be
                # read from or that can't widen it: (i) the whole index of a subscript on a constant array the TU
                # declares (bounded by its count), (ii) a whole argument of a call, (iii) an operand of a comparison or
                # a switch. Anything else (a copy, index + 1, index * 2, pointer arithmetic) is refused, and there must
                # be a use of kind (i) unless a cited table bounds the range
                tabs_ = _range_uses(fn, p)
                for nm_, n_ in tabs_:
                    if lo < 0 or hi >= n_:
                        raise Unsupported("HULK_RANGE(%d, %d) on parameter %s of %s reaches past %s[%d], which the "
                                          "body indexes with it" % (lo, hi, p.spelling, fn.spelling, nm_, n_))
                if not tabs_ and not _cited_tables(p, fn):
                    raise Unsupported("HULK_RANGE: the bound on %s can't be derived from its uses (no table subscript "
                                      "with it, none cited)" % p.spelling)
                out[i] = (lo, hi)
    return out


RDATA_ATTR = re.compile(r"^hulk_rdata$")


def _var_id(c):
    """(integ2, D103) The identity of variable C across its declarations: its linkage name (an `extern "C"` global
    redeclared inside a TU's namespace is the header's global; libclang gives the two different USRs), else its USR."""
    try:
        mn = c.mangled_name
    except Exception:   # noqa: BLE001
        mn = None
    if mn:
        return "m:" + mn
    return "u:" + c.get_usr()


def gdata_models(tu):
    """(integ2, D103) {USR: model} of the variables TU declares (at namespace scope) with a data annotation on any of
    their declarations (include/decls/data/records.h), the model one of
      ("range", lo, hi, cited)  HULK_RANGE(lo, hi): every integer word of the global holds lo..hi (the game's stores
                                into it, which the declaration's comment cites: 0x addresses, as for a field, D61)
      ("rdata",)                HULK_RDATA: a const table in a read-only section of the XBE; the run gets its bytes
      ("unsupported", why)      two annotations, or two declarations that disagree.
    A tree TU redeclares a global its generated header declares (`extern "C" int DAT_0056bfc8[514] HULK_RANGE(0,
    255);`), so the annotation is on one declaration of several: every declaration is read. Cached per parse."""
    hit = getattr(tu, "_hulk_gdata", None)
    if hit is not None:
        return hit
    K = ci().CursorKind
    found = {}

    def walk(c, depth=0):
        for ch in c.get_children():
            if ch.kind == K.VAR_DECL:
                for a in ch.get_children():
                    if a.kind != K.ANNOTATE_ATTR:
                        continue
                    sp_ = a.spelling or ""
                    m = RANGE_ATTR.match(sp_)
                    mod = ("range", int(m.group(1)), int(m.group(2))) if m else \
                        (("rdata",) if RDATA_ATTR.match(sp_) else None)
                    if mod is None:
                        continue
                    try:
                        u = _var_id(ch)
                    except Exception:   # noqa: BLE001
                        continue
                    found.setdefault(u, []).append((mod, ch))
            elif ch.kind in (K.NAMESPACE, K.LINKAGE_SPEC, K.UNEXPOSED_DECL) and depth < 6:
                walk(ch, depth + 1)
    walk(tu.cursor)
    out = {}
    texts = {}
    names = {}
    for u, l in found.items():
        texts[u] = "\n".join(_comment_block(c) for _, c in l)
        names[u] = l[0][1].spelling
        mods = {m for m, _ in l}
        if len(mods) != 1:
            out[u] = ("unsupported", "the declarations of %s carry different data annotations %s" % (
                l[0][1].spelling, sorted(mods)))
            continue
        mod = l[0][0]
        if mod[0] == "range":
            # (as for a field, D61) the annotated declaration cites the stores that give the words their values
            mod = mod + (any(_comment_block(c, near=True) for m, c in l),)
        out[u] = mod
    try:
        tu._hulk_gdata = out
        tu._hulk_gdata_text = texts
        tu._hulk_gdata_names = names
    except Exception:   # noqa: BLE001
        pass
    return out


def gdata_digest_part(tu):
    """(integ2, D103; rev5's R4) Every data-annotated global of the parse TU: its model and the text of its annotated
    declarations' comment blocks (the citations the census reads). In every block's AST digest: a global read
    through a helper, or a citation edited, runs the gate again."""
    mods = gdata_models(tu)
    texts = getattr(tu, "_hulk_gdata_text", {})
    names = getattr(tu, "_hulk_gdata_names", {})
    return sorted([u, list(m), texts.get(u, ""), gdata_inputs(names.get(u, ""), m)] for u, m in mods.items())


def gdata_inputs(name, mod):
    """(integ2, D103; rev5's R8) What a data annotation's checks read besides the source, for the digest: the
    config/data.json items (at the address, at its end, the enclosing one) and, for HULK_RANGE, the census sites with
    the listed function holding each (the function list). A changed data.json or function list runs the gate again."""
    m = re.search(r"DAT_([0-9a-fA-F]{8})$", name or "")
    if not m or mod[0] not in ("range", "rdata"):
        return None
    try:
        import equiv
        addr = int(m.group(1), 16)
        it = data_item(addr)
        n = int(it.get("size") or 0) if it else 0
        out = {"item": it, "end": data_item(addr + n), "enclosing": _enclosing_item(addr, addr + n)}
        if mod[0] == "range":
            prog = equiv.Program.get()
            starts = sorted(prog.funcs)
            lo, hi = census_window(addr, n)
            sites = []
            for site, kind in xbe_refs(lo, hi):
                i = bisect.bisect_right(starts, site) - 1
                f = [starts[i], prog.funcs[starts[i]][0]] if i >= 0 and site < starts[i] + prog.funcs[starts[i]][0] else None
                sites.append([site, kind, f])
            out["census"] = sites
        return hashlib.sha1(json.dumps(out, sort_keys=True, default=str).encode()).hexdigest()[:16]
    except Exception as e:      # noqa: BLE001 - the digest still changes with the failure text
        return "unavailable: %r" % e


_XREFS = {}
_ITEMS = []
RDATA_KINDS = ("table", "float_table", "float", "double", "scalar")


def _data_items():
    """(integ2, D103) config/data.json's items as a sorted [(addr, item)] (cached)."""
    if not _ITEMS:
        with open(os.path.join(ROOT, "config", "data.json")) as f:
            items = json.load(f)["items"]
        _ITEMS.extend(sorted((int(x["addr"], 16), x) for x in items))
    return _ITEMS


def data_item(addr):
    """(integ2, D103) The config/data.json item that starts at ADDR, or None."""
    import bisect
    its = _data_items()
    i = bisect.bisect_left(its, (addr,), key=lambda t: (t[0],))
    return its[i][1] if i < len(its) and its[i][0] == addr else None


def _enclosing_item(lo, hi):
    """(integ2, D103) (start, end) of a data.json item other than the one at LO that contains [LO, HI), or None."""
    import bisect
    its = _data_items()
    i = bisect.bisect_right(its, (lo,), key=lambda t: (t[0],)) - 1
    while i >= 0 and its[i][0] > lo - 0x100000:
        a, x = its[i]
        if a < lo and a + int(x.get("size") or 0) >= hi:
            return a, a + int(x["size"])
        i -= 1
    return None


def xbe_image(addr, n):
    """(integ2, D103) The N bytes the game starts with at ADDR: the section's file bytes, zero fill past them."""
    import equiv
    xbe = equiv.Program.get().xbe
    sec = xbe.section_of(addr)
    out = bytearray(n)
    if sec is None:
        return bytes(out)
    k = max(0, min(n, sec.va + sec.rsize - addr))
    if k:
        o = xbe.offset(addr)
        out[:k] = xbe.data[o:o + k]
    return bytes(out)


def xbe_refs(lo, hi):
    """(integ2, D103) [(site, kind)] of every 4-byte little-endian word of the XBE that holds an address in [lo, hi):
    in a code section (an instruction's absolute operand, "code") or a data section (a pointer, "data"). A byte scan,
    not a disassembly: a coincidental word is reported too (it can only ask for one more citation). Every 64 KB page
    of the range is searched (rev5's R3c)."""
    key = (lo, hi)
    if key in _XREFS:
        return _XREFS[key]
    import equiv
    xbe = equiv.Program.get().xbe
    out = set()
    for sec in xbe.sections:
        d = xbe.data[sec.raw:sec.raw + sec.rsize]
        kind = "code" if sec.executable else "data"
        for t_ in range(lo >> 16, ((hi - 1) >> 16) + 1):
            pat = t_.to_bytes(2, "little")
            i = d.find(pat, 2)
            while i >= 0:
                v = int.from_bytes(d[i - 2:i + 2], "little")
                if lo <= v < hi:
                    out.add((sec.va + i - 2, kind))
                i = d.find(pat, i + 1)
    out = sorted(out)
    _XREFS[key] = out
    return out


def pre_lines_of(fn):
    """(integ3, D152) The `// pre:` lines of the comment block right above function FN's definition (the source file)."""
    try:
        path, line = fn.extent.start.file.name, fn.extent.start.line
        lines = open(path, errors="replace").read().splitlines()
    except Exception:   # noqa: BLE001
        return []
    out = []
    i = line - 2
    while i >= 0 and lines[i].lstrip().startswith("//"):
        m = re.match(r"^\s*//\s*pre:\s*(.*)$", lines[i])
        if m:
            out.append(m.group(1))
        i -= 1
    return out[::-1]


def pre_ranges(fn):
    """(integ3, D152) {param index (0-based): (range cond)} of FN's range contract items on its parameters."""
    import equiv
    specs, _bad = equiv._parse_pre(pre_lines_of(fn))
    out = {}
    for (_w, kind, n, _off, _end, cond) in specs:
        if kind != "arg" or not isinstance(cond, tuple):
            continue
        if n - 1 in out and "preand" not in OFF:
            # (integ4, x64bounds) two items on one parameter (`ge(arg3, 0) lt(arg3, this->count)`) state both bounds:
            # the domain is their intersection (a later item used to replace the earlier one)
            out[n - 1] = _pre_and(out[n - 1], cond)
        else:
            out[n - 1] = cond
    return out


def pre_oranges(fn):
    """(integ7, item 8) {32-bit offset: range cond with its type} of FN's `*this+0xOFF.f32|i32` range items."""
    import equiv
    specs, _bad = equiv._parse_pre(pre_lines_of(fn))
    return {off: (cond, end) for (_w, kind, _n, off, end, cond) in specs if kind == "othis"}


def _pre_and(a, b):
    """(integ4, x64bounds) The intersection of two range conds ("range", lo, hi, lo_incl, hi_incl); a field bound
    (("field", NAME)) and a constant on the same side can't be ordered statically: refused."""
    lo, li = a[1], a[3]
    for x, xi in ((b[1], b[3]),):
        if isinstance(x, tuple) or isinstance(lo, tuple):
            if x != float("-inf") and lo != float("-inf"):
                raise Unsupported("two lower bounds on one parameter, one of them a field (%r / %r)" % (lo, x))
            if lo == float("-inf"):
                lo, li = x, xi
        elif x > lo or (x == lo and not xi):
            lo, li = x, xi
    hi, hi_i = a[2], a[4]
    for x, xi in ((b[2], b[4]),):
        if isinstance(x, tuple) or isinstance(hi, tuple):
            if x != float("inf") and hi != float("inf"):
                raise Unsupported("two upper bounds on one parameter, one of them a field (%r / %r)" % (hi, x))
            if hi == float("inf"):
                hi, hi_i = x, xi
        elif x < hi or (x == hi and not xi):
            hi, hi_i = x, xi
    return ("range", lo, hi, li, hi_i)


_RET_POST_SYMS = {}
_RET_POST_X64 = {}


def ret_post_addr(name):
    """(integ9, D165) The address of the return-post block (equiv.ret_post_blocks) NAME stands for: FUN_<addr> in it, or
    the block's `// sym:` pin (tree namespaces dropped); else None."""
    import equiv
    idx = equiv.ret_post_blocks()
    if not idx:
        return None
    m = re.search(r"FUN_([0-9a-fA-F]{8})", name or "")
    if m:
        a = int(m.group(1), 16)
        return a if a in idx else None
    if "_" not in _RET_POST_SYMS:
        syms = {}
        for a, ent in idx.items():
            try:
                with open(ent[0], errors="replace") as f_:
                    t_ = f_.read()
            except OSError:
                continue
            for blk in re.split(r"\n(?=// 0x[0-9a-f]{8} )", t_):
                if blk.startswith("// 0x%08x " % a):
                    sm = re.search(r"^// sym: (\S+)", blk, re.M)
                    if sm:
                        k_ = TREE_NS.sub("", sm.group(1))
                        syms[k_] = None if k_ in syms and syms[k_] != a else a     # (rev5) ambiguous: no draw
        _RET_POST_SYMS["_"] = syms
    return _RET_POST_SYMS["_"].get(TREE_NS.sub("", name or ""))


def ret_post_accept(addr):
    """(integ9, D165; rev5) (range, identity) when an x64 caller may draw ADDR's return inside its postcondition, else
    (None, why). The x64 harness compares the 32-bit and 64-bit clang objects of one source, whose callee is the same
    source on both sides: the post serves only when it is accepted in BOTH 32-bit modes (equiv.accept_ret_post: an
    equivalent block's promotable msvc and wine lines for its pinned code and view, a matches block's live post lines),
    the identity naming both. EQ64_OFF=postproof accepts the stated post unproven (regress only: proves nothing)."""
    import equiv
    key = (addr, "postproof" in OFF)
    if key in _RET_POST_X64:
        return _RET_POST_X64[key]
    ent = equiv.ret_post_blocks().get(addr)
    if ent is None:
        res = (None, "no return postcondition")
    elif "postproof" in OFF:
        rng = equiv._ret_post_range(ent[2])
        res = (rng, [ent[2], ent[3], "unproven (EQ64_OFF=postproof)"]) if rng is not None else (None, "post unparsed")
    else:
        rm, im = equiv.accept_ret_post(addr, False)
        rw, iw = equiv.accept_ret_post(addr, True)
        if rm is None or rw is None:
            res = (None, "msvc: %s; wine: %s" % (im if rm is None else "ok", iw if rw is None else "ok"))
        elif rm != rw:
            res = (None, "the modes' ranges differ")
        else:
            res = (rm, [im, iw])
    _RET_POST_X64[key] = res
    return res


def callee_post_part(fn32):
    """(integ9, D165) The AST digest's `calleepost` part: [address, acceptance] of every callee FN32's body names that
    is a return-post block, other than the function itself (the x64 gate re-runs a caller when a callee's post is
    proved, edited or revoked)."""
    if "calleepost" in OFF or "post" in OFF:
        return "off"
    out = {}
    self_ = None
    try:
        self_ = ret_post_addr(fn32.mangled_name) or ret_post_addr(fn32.spelling)
    except Exception:   # noqa: BLE001
        pass
    for c in fn32.walk_preorder():
        if c.kind.name in ("CALL_EXPR", "DECL_REF_EXPR", "MEMBER_REF_EXPR") and c.referenced is not None and \
                c.referenced.kind.name in ("FUNCTION_DECL", "CXX_METHOD"):
            r = c.referenced
            try:
                a = ret_post_addr(r.mangled_name) or ret_post_addr(r.spelling)
            except Exception:   # noqa: BLE001
                a = None
            if a is not None and a != self_ and a not in out:
                rng, info = ret_post_accept(a)
                out[a] = [list(rng) if rng is not None else None, info]
    return sorted([["0x%08x" % a, v] for a, v in out.items()])


_POST_IDX = {}


def post_contracts(extra=None):
    """(integ4, post; rev5) {function address: [(n, cond)]} of the `// post: ... when ret` items of every tree block (src/,
    scanned once) and of EXTRA (the source under check, a case file): a caller's stub of that function draws *argN inside
    cond when it returns nonzero."""
    import equiv
    if "_" not in _POST_IDX:
        _POST_IDX["_"] = {}
        for dp, _dn, fns in os.walk(os.path.join(ROOT, "src")):
            for f in fns:
                if f.endswith(".cpp"):
                    try:
                        _post_of_text(open(os.path.join(dp, f), errors="replace").read(), _POST_IDX["_"])
                    except OSError:
                        pass
    if not extra:
        return _POST_IDX["_"]
    out = dict(_POST_IDX["_"])
    _post_of_text(extra, out, header=True)
    return out


def _post_of_text(text, out, header=False):
    """Fills OUT {address: items} and OUT["sym"] {32-bit symbol (the block's `// sym:` pin, tree namespaces dropped):
    address}; (rev5) with LEDGER, a block whose current code has no proof is left out (callers fall back to the plain
    fill). Block text ends at the next `// 0x` header."""
    import equiv
    if "// post:" not in text:
        return out
    blocks = re.split(r"\n(?=// 0x[0-9a-f]{8} )", text)
    for blk in blocks:
        m = re.match(r"// (0x[0-9a-f]{8}) ", blk)
        fh = re.search(r"^// FUN_[0-9a-fA-F]{8} @ (0x[0-9a-fA-F]+)", blk, re.M) if header and not m else None
        pl = re.findall(r"^\s*//\s*post:\s*(.*)$", blk, re.M)
        if not pl:
            continue
        specs, bad = equiv._parse_post(pl)
        if bad or not (m or fh):
            continue        # (the block's own checks refuse it)
        a = int((m or fh).group(1), 16)
        sm = re.search(r"^// sym: (\S+)((?: @\S+)*)", blk, re.M)
        if "postproof" not in OFF:
            # (rev5) callers rely on a post only when the callee's current code has a proof (>= 50 checked nonzero
            # returns make its run promotable): a ledger line for one of its modes' current (code, view). A case file's
            # own statement (`// FUN_x @ 0x...`, no pins) counts only with EQ64_OFF=postproof (regress; proves nothing)
            if not m or sm is None or not _post_proven(a, sm.group(2)):
                continue
        out[a] = specs
        if sm is not None:
            out.setdefault("sym", {})[TREE_NS.sub("", sm.group(1))] = a
    return out


_LEDGER_IDX = []


def _post_proven(addr, pins):
    """(integ4, post; rev5) Does the proof ledger hold passing lines for ADDR's current code and view (PINS: the
    `// sym:` line's ` @msvc @wclang @vview` hashes): both modes, as the pin's view covers both?"""
    import tree_tu
    if not _LEDGER_IDX:
        _LEDGER_IDX.append(tree_tu.ledger_index() or set())
    hs = pins.split()
    code = {"msvc": None, "wine": None}
    view = None
    for h in hs:
        if h.startswith("@w"):
            code["wine"] = h[2:]
        elif h.startswith("@v"):
            view = h[2:]
        elif h.startswith("@"):
            code["msvc"] = h[1:]
    a = "0x%08x" % addr
    if view is None or not code["msvc"]:
        return False
    # (integ5) the pin's @v is tree_tu.view_digest(msvc view, wine view) while a ledger line holds its mode's own view:
    # the current code and view are proven when a passing msvc line of the @ code and a passing wine line of the @w code
    # (none when the block has no clang object) have views whose digest is the pin's (comparing @v with a line's view
    # never matched: no tree block's post was used outside EQ64_OFF=postproof)
    vms = {v for (a_, m_, c_, v) in _LEDGER_IDX[0] if a_ == a and m_ == "msvc" and c_ == code["msvc"]}
    vws = {v for (a_, m_, c_, v) in _LEDGER_IDX[0] if a_ == a and m_ == "wine" and c_ == code["wine"]} \
        if code["wine"] else {None}
    return any(tree_tu.view_digest(vm, vw) == view for vm in vms for vw in vws)


def post_lines_of(fn):
    """(integ4, post) The `// post:` lines of the comment block right above function FN's definition."""
    try:
        path, line = fn.extent.start.file.name, fn.extent.start.line
        lines = open(path, errors="replace").read().splitlines()
    except Exception:   # noqa: BLE001
        return []
    out = []
    i = line - 2
    while i >= 0 and lines[i].lstrip().startswith("//"):
        m = re.match(r"^\s*//\s*post:\s*(.*)$", lines[i])
        if m:
            out.append(m.group(1))
        i -= 1
    return out[::-1]


def _field_off32(t, name, depth=0):
    """(integ4, post) The byte offset of field NAME in record type T (its own field or a base's), or None."""
    if depth > 8:
        return None
    try:
        o = t.get_canonical().get_offset(name)
    except Exception:   # noqa: BLE001
        o = -1
    if o is not None and o >= 0:
        return o // 8
    d = t.get_canonical().get_declaration()
    K = ci().CursorKind
    for b in d.get_children():
        if b.kind == K.CXX_BASE_SPECIFIER:
            r = _field_off32(b.type, name, depth + 1)
            if r is not None:
                return (b.get_base_offsetof(d) // 8) + r
    return None


def post_operands(fn):
    """(integ4, post) [(op, subject, bound, resolved)] of FN's HULK_POST_* macros: a member bound with its byte offset in
    this parse's record (the 32-bit parse gives the original's), for the AST digest."""
    try:
        path, l0, l1 = fn.extent.start.file.name, fn.extent.start.line, fn.extent.end.line
        import equiv
        body = equiv._strip_comments("\n".join(open(path, errors="replace").read().splitlines()[l0 - 1:l1]))
    except Exception:   # noqa: BLE001
        return []
    out = []
    rec = fn.semantic_parent.type if fn.semantic_parent is not None else None
    for op, args in re.findall(r"\bHULK_POST_(GT|GE|LT|LE)\s*\(([^;]*)\)\s*;", body):
        a = [x.strip() for x in args.split(",")]
        res = None
        if len(a) == 2 and re.match(r"^[A-Za-z_]\w*$", a[1]) and rec is not None:
            res = _field_off32(rec, a[1])
        out.append([op] + a + [res])
    return out


def post_macro_check(fn, chk):
    """(integ4, post; rev5) A block stating `// post: ... when ret`: its HULK_POST_GE/GT/LT/LE(*param, bound) macros and
    its items must be the same claims, both ways: the subject the item's *argN (by the parameter's name, through a cast),
    the bound the same constant or the field of this whose 32-bit offset the item names. Raises Unsupported otherwise."""
    import equiv
    pl = post_lines_of(fn)
    try:
        path, l0, l1 = fn.extent.start.file.name, fn.extent.start.line, fn.extent.end.line
        body = equiv._strip_comments("\n".join(open(path, errors="replace").read().splitlines()[l0 - 1:l1]))
    except Exception:   # noqa: BLE001
        body = ""
    macros = re.findall(r"\bHULK_POST_(GT|GE|LT|LE)\s*\(([^;]*)\)\s*;", body)
    if not pl and not macros:
        return
    specs, bad = equiv._parse_post(pl)
    if bad:
        raise Unsupported("post: %s" % "; ".join(bad))
    K = ci().CursorKind
    params = [c.spelling for c in fn.get_children() if c.kind == K.PARM_DECL]
    lay = None
    if chk.sig is not None and chk.sig.method_record is not None:
        lay = chk.types.layout(chk.sig.method_record[0], chk.sig.method_record[1])
    inf = float("inf")
    got = set()
    for op, args in macros:
        a = [x.strip() for x in args.split(",")]
        if len(a) != 2:
            raise Unsupported("post: HULK_POST_%s(%s): two operands" % (op, args))
        m = re.match(r"^(?:\(\s*(?:unsigned\s+)?int\s*\))?\s*\*\s*([A-Za-z_]\w*)$", a[0])
        if not m or m.group(1) not in params:
            raise Unsupported("post: HULK_POST_%s(%s): the subject must be *parameter" % (op, args))
        n = params.index(m.group(1)) + 1
        if re.match(r"^[A-Za-z_]\w*$", a[1]):
            def own_(path, nm):     # a field of the record or of one of its bases (path: base, key, ..., name)
                return path[-1:] == (nm,) and all(path[i] == "base" for i in range(0, len(path) - 1, 2)) and \
                    len(path) % 2 == 1
            l = next((x for x in (lay.leaves if lay is not None else ()) if own_(x.path, a[1])), None)
            if l is None:
                raise Unsupported("post: HULK_POST_%s(%s): %s is no field of this" % (op, args, a[1]))
            c = ("this32", l.o32)
        else:
            try:
                c = equiv._pre_num(a[1])
            except ValueError:
                raise Unsupported("post: HULK_POST_%s(%s): the bound must be a constant or a field" % (op, args))
        cond = {"GT": ("range", c, inf, False, True), "GE": ("range", c, inf, True, True),
                "LT": ("range", -inf, c, True, False), "LE": ("range", -inf, c, True, True)}[op]
        got.add((n, cond))
    want = set(specs)
    if got != want:
        raise Unsupported("post: items %s, macros %s" % (sorted(map(str, want - got)), sorted(map(str, got - want))))


def pre_relational_check(fn, addr):
    """(integ4, x64bounds; rev5) A block with a relational range item (`lt(argN, this->FIELD)`): the items and the
    HULK_PRE_* macros in the body must state the same claims, and its `// pre-callers:` lines must cite every
    reference to the function (equiv.py's census). Raises Unsupported otherwise."""
    import equiv
    lines = pre_lines_of(fn)
    specs, bad = equiv._parse_pre(lines)
    if bad:
        raise Unsupported("`// pre:` %s" % "; ".join(bad))
    items = {(n, c) for (_w, k, n, _o, _e, c) in specs if k == "arg" and isinstance(c, tuple)}
    if not any(equiv._pre_relational(c) for _n, c in items):
        return
    try:
        path, l0, l1 = fn.extent.start.file.name, fn.extent.start.line, fn.extent.end.line
        src = open(path, errors="replace").read().splitlines()
    except Exception as ex:     # noqa: BLE001
        raise Unsupported("relational pre: can't read the block (%s)" % ex)
    i = l0 - 2
    while i >= 0 and src[i].lstrip().startswith("//"):
        i -= 1
    block = "\n".join(src[i + 1:l1])
    macros, mbad = equiv._pre_range_macros(equiv._strip_comments("\n".join(src[l0 - 1:l1])))
    if mbad or macros != items:
        raise Unsupported("relational pre: items %s, macros %s %s" % (sorted(map(str, items - macros)),
                                                                      sorted(map(str, macros - items)), mbad))
    seen, miss = equiv._pre_census(addr, block)
    if not seen or miss:
        raise Unsupported("relational pre without `// pre-callers:` citing every reference (missing: %s)" %
                          ", ".join("0x%08x" % m if isinstance(m, int) else str(m) for m in miss[:20]))


def _comment_block(c, near=False):
    """(integ2, D103; rev5's R8) The text of declaration C and the comment block right above it, from the parse's own
    tokens (the buffer the parse read, not the file as it is now). NEAR: whether its line or the line before carries
    a comment citing a 0x address (D61's rule)."""
    try:
        tu = c.translation_unit
        f = c.extent.start.file
        l0, l1 = c.extent.start.line, c.extent.end.line
        m = ci()
        ext = m.SourceRange.from_locations(m.SourceLocation.from_position(tu, f, max(1, l0 - 200), 1),
                                           m.SourceLocation.from_position(tu, f, l1, 1 << 12))
        toks = [(t.kind.name, t.spelling, t.extent.start.line, t.extent.end.line) for t in tu.get_tokens(extent=ext)]
    except Exception:   # noqa: BLE001
        return False if near else ""
    decl = [t for t in toks if l0 <= t[2] <= l1]
    above = [t for t in toks if t[3] < l0]
    block, line = [], l0
    for t in reversed(above):
        if t[0] != "COMMENT" or t[3] < line - 1:
            break
        block.insert(0, t)
        line = t[2]
    if near:
        return any(t[0] == "COMMENT" and re.search(r"0x[0-9a-fA-F]{5,}", t[1]) and t[3] >= l0 - 1
                   for t in block + decl)
    return "\n".join(t[1] for t in block + decl)

def census_window(addr, size):
    """(integ2, D103) [lo, hi) the census searches for a table [addr, addr + size) (range_census)."""
    lo, hi = addr - 0x40, addr + size + (0 if data_item(addr + size) is not None else 1)
    enc = _enclosing_item(addr, addr + size)
    if enc is not None:
        lo, hi = min(lo, enc[0]), max(hi, enc[1])
    return lo, hi


def range_census(addr, size, text):
    """(integ2, D103; rev5's R3) The XBE's references near a HULK_RANGE global [addr, addr + size) that its comment
    block TEXT doesn't cite. Searched: from 0x40 below the table (a base biased below it) through its end, the
    one-past-the-end address too unless another data.json item starts there, and the whole data.json item that
    encloses the table, if one does. A code word inside a listed function is covered by citing that function's start;
    a code word in no listed function only by citing its own site (an address at most 0x10 before the word: the
    instruction); a data word pointing in only by citing that word. The roles (which reference writes) stay the
    reviewer's to check. Returns the uncovered sites (empty: the census is complete)."""
    import bisect
    import equiv
    prog = equiv.Program.get()
    cited = sorted({int(x, 16) for x in re.findall(r"0x([0-9a-fA-F]{5,})", text)})
    starts = sorted(prog.funcs)
    lo, hi = census_window(addr, size)
    missing = []
    for site, kind in xbe_refs(lo, hi):
        if kind == "data":
            if site not in cited:
                missing.append("data word 0x%08x" % site)
            continue
        i = bisect.bisect_right(starts, site) - 1
        if i >= 0 and site < starts[i] + prog.funcs[starts[i]][0]:
            if starts[i] not in cited:
                missing.append("0x%08x (in 0x%08x)" % (site, starts[i]))
            continue
        if not any(site - 0x10 <= c <= site for c in cited):
            missing.append("0x%08x (in no listed function)" % site)
    return missing


def global_model(tu, c):
    """(integ2, D103) The data model of global C (a VAR_DECL of TU) from gdata_models, or None."""
    if c is None:
        return None
    try:
        u = _var_id(c)
    except Exception:   # noqa: BLE001
        return None
    return gdata_models(tu).get(u)


def _const_object(t):
    """(integ2, D103) Is type T const (an array's elements, through every dimension)?"""
    t = t.get_canonical()
    while t.kind.name in ("CONSTANTARRAY", "INCOMPLETEARRAY"):
        if t.is_const_qualified():
            return True
        t = t.element_type.get_canonical()
    return t.is_const_qualified()


def param_casts(fn):
    """{parameter index: T*} for the untyped parameters (void*, char*, pointer-width integers) that the body of FN
    casts to a pointer to something typed: `(LexState *)ls`, `{ T * x = (T *)__p0;`. The first such cast wins."""
    K = ci().CursorKind
    params = [c for c in fn.get_children() if c.kind == K.PARM_DECL]
    idx = {}
    for i, p in enumerate(params):
        t = p.type.get_canonical()
        untyped = t.kind.name in INT_KINDS and t.get_size() >= 4 or (
            t.kind.name == "POINTER" and t.get_pointee().get_canonical().kind.name in ("VOID", "CHAR_S", "CHAR_U", "UCHAR", "SCHAR"))
        if untyped:
            idx[p.hash] = i
    out = {}
    if not idx:
        return out

    def walk(c, depth=0):
        if depth > 200:
            return
        if c.kind in (K.CSTYLE_CAST_EXPR, K.CXX_STATIC_CAST_EXPR, K.CXX_REINTERPRET_CAST_EXPR):
            t = c.type.get_canonical()
            if t.kind.name == "POINTER":
                pk = t.get_pointee().get_canonical()
                if pk.kind.name == "RECORD" or (pk.kind.name == "POINTER"):
                    ref = None
                    for d in c.walk_preorder():
                        if d.kind == K.DECL_REF_EXPR and d.referenced is not None and d.referenced.hash in idx:
                            ref = d.referenced
                            break
                        if d.kind in (K.CALL_EXPR, K.BINARY_OPERATOR, K.MEMBER_REF_EXPR) and d != c:
                            break
                    if ref is not None and idx[ref.hash] not in out:
                        out[idx[ref.hash]] = t
        for ch in c.get_children():
            walk(ch, depth + 1)
    for ch in fn.get_children():
        if ch.kind == K.COMPOUND_STMT:
            walk(ch)
    return out


def region_layout(off32, off64, el, k):
    """(integ3, allocty regions) A layout of K records EL starting at OFF32 / OFF64 (the bytes before them untyped)."""
    leaves = []
    for e in range(k):
        for l in el.leaves:
            n = Leaf(("[%d]" % e,) + tuple(l.path), off32 + e * el.size32 + l.o32, off64 + e * el.size64 + l.o64, l.kind,
                     l.s32, l.s64, l.extra, l.signed)
            n.range, n.cast = l.range, l.cast
            leaves.append(n)
        leaves.append(Leaf(("[%d]" % e,), off32 + e * el.size32, off64 + e * el.size64, "m", 0, 0))
    lay = Layout("region<%d,%s,%d>" % (off32, el.key, k), off32 + k * el.size32, off64 + k * el.size64, leaves)
    lay.record = True
    return lay


def alloc_site_regions(fn32, fn64):
    """(integ3, allocty regions) {callee key: [(off32, off64, (T32, T64), array) or None per call, in source order]} for
    allocator calls whose result initializes a local P* p (directly or through a cast) that the body casts as
    `(T*)(p + k)` with T a record and k an integer literal: the record region starts k * sizeof(P) bytes in (each
    target's). array: the call's size argument is `n * sizeof(T) + c` (or `n * sizeof(T)`)."""
    K = ci().CursorKind

    def strip(c):
        while c.kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR, K.CSTYLE_CAST_EXPR, K.CXX_STATIC_CAST_EXPR,
                         K.CXX_REINTERPRET_CAST_EXPR):
            k = [x for x in c.get_children() if x.kind != K.TYPE_REF]
            if len(k) != 1:
                break
            c = k[0]
        return c

    def lit(c):
        c = strip(c)
        if c.kind == K.INTEGER_LITERAL:
            toks = [t.spelling for t in c.get_tokens()]
            try:
                return int(toks[0].rstrip("uUlL"), 0) if toks else None
            except ValueError:
                return None
        return None

    def is_sizeof(c, spelling):
        c = strip(c)
        if c.kind == K.CXX_UNARY_EXPR and [t.spelling for t in c.get_tokens()][:1] == ["sizeof"]:
            kids = list(c.get_children())
            return bool(kids) and kids[0].type.get_canonical().spelling == spelling
        return False

    def op(c):
        return getattr(getattr(c, "binary_operator", None), "name", "")

    def has_sizeof(c, spelling):
        """(rev5) an array only for `n * sizeof(T)` or `sizeof(T) * n`, optionally plus an integer literal: a sizeof(T)
        that is only added (`4 + sizeof(T) + len`) is one record and a payload."""
        c = strip(c)
        if c.kind == K.BINARY_OPERATOR and op(c) == "Add":
            a_, b_ = [strip(x) for x in list(c.get_children())[:2]]
            if lit(b_) is not None:
                c = a_
            elif lit(a_) is not None:
                c = b_
            else:
                return False
        if c.kind == K.BINARY_OPERATOR and op(c) == "Mul":
            return any(is_sizeof(x, spelling) for x in list(c.get_children())[:2])
        return False

    def scan(fn):
        calls, inits, casts, reassigned = [], {}, [], set()

        def walk(c, depth=0):
            if depth > 200:
                return
            if c.kind == K.CALL_EXPR and c.referenced is not None:
                calls.append(((c.location.line, c.location.column), "decl:" + loc_key(c.referenced), c))
            if c.kind == K.VAR_DECL:
                kids = [x for x in c.get_children() if x.kind not in (K.TYPE_REF,)]
                if kids:
                    v = strip(kids[-1])
                    if v.kind == K.CALL_EXPR and c.type.get_canonical().kind.name == "POINTER":
                        inits[c.hash] = (v.location.line, v.location.column), c.type.get_canonical().get_pointee()
            if c.kind in (K.CSTYLE_CAST_EXPR, K.CXX_STATIC_CAST_EXPR, K.CXX_REINTERPRET_CAST_EXPR):
                t = c.type.get_canonical()
                if t.kind.name == "POINTER" and is_record(t.get_pointee()):
                    kids = [x for x in c.get_children() if x.kind != K.TYPE_REF]
                    e = strip(kids[-1]) if kids else None
                    if e is not None and e.kind == K.BINARY_OPERATOR and op(e) == "Add":
                        a_, b_ = list(e.get_children())[:2]
                        a_ = strip(a_)
                        k_ = lit(b_)
                        if a_.kind == K.DECL_REF_EXPR and a_.referenced is not None and k_ is not None:
                            # (rev5 Q2) the byte offset is k times the Add's own element size: `(int*)p + 1` is 4,
                            # `(char*)p + 4` is 4 (the byte form), whatever the local's type
                            try:
                                es_ = e.type.get_canonical().get_pointee().get_size()
                            except Exception:   # noqa: BLE001
                                es_ = -1
                            if es_ > 0:
                                casts.append((a_.referenced.hash, k_ * es_, t.get_pointee()))
            if c.kind == K.BINARY_OPERATOR and op(c) == "Assign":
                lhs = strip(list(c.get_children())[0])
                if lhs.kind == K.DECL_REF_EXPR and lhs.referenced is not None:
                    reassigned.add(lhs.referenced.hash)     # (rev5 note) a local assigned again: no region
            for ch in c.get_children():
                walk(ch, depth + 1)
        for ch in fn.get_children():
            if ch.kind == K.COMPOUND_STMT:
                walk(ch)
        return calls, {h: v for h, v in inits.items() if h not in reassigned}, casts

    c32, i32, k32 = scan(fn32)
    c64, i64, k64 = scan(fn64)
    if len(k32) != len(k64) or len(c32) != len(c64):
        return {}
    regions = {}
    for (h32, kk, t32), (h64, _kk, t64) in zip(k32, k64):
        if h32 not in i32 or h64 not in i64:
            continue
        loc, _p32 = i32[h32]
        off32, off64 = kk, _kk
        if off32 <= 0 or off64 <= 0:
            continue
        regions.setdefault(loc, (off32, off64, (t32, t64)))
    per = {}
    for (loc, key, c), (_l, _k, c64_) in zip(sorted(c32, key=lambda x: x[0]), sorted(c64, key=lambda x: x[0])):
        r = regions.get(loc)
        if r is not None:
            args = list(c.get_arguments())
            ai_ = ALLOCATOR_AT.get(c.referenced.spelling, 0)
            arr = len(args) > ai_ and has_sizeof(args[ai_], r[2][0].get_canonical().spelling)
            r = r + (arr,)
        per.setdefault(key, []).append(r)
    return {k: v for k, v in per.items() if any(x is not None for x in v)}


def alloc_site_arrays(fn):
    """(integ3, allocty; rev5 R2') {callee key: [T's canonical spelling or None per call, in source order]}: T when the
    call's size argument (the first, or ALLOCATOR_AT's index) is `n * sizeof(T)` or `sizeof(T) * n` (through parens and
    casts), for every callee called. Other shapes (`n * m * sizeof(T)`, `n * sizeof(T) + extra`) type the header alone."""
    K = ci().CursorKind

    def strip(c):
        while c.kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR, K.CSTYLE_CAST_EXPR, K.CXX_STATIC_CAST_EXPR,
                         K.CXX_FUNCTIONAL_CAST_EXPR):
            k = [x for x in c.get_children() if x.kind != K.TYPE_REF]
            if len(k) != 1:
                break
            c = k[0]
        return c

    def sizeof_of(c):
        c = strip(c)
        if c.kind == K.CXX_UNARY_EXPR:
            toks = [t.spelling for t in c.get_tokens()]
            if toks[:1] == ["sizeof"]:
                kids = list(c.get_children())
                if kids and kids[0].kind == K.TYPE_REF:
                    return kids[0].type.get_canonical().spelling
                if kids:
                    return kids[0].type.get_canonical().spelling
                return None
        return None

    calls = []

    def walk(c, depth=0):
        if depth > 200:
            return
        if c.kind == K.CALL_EXPR and c.referenced is not None:
            args = list(c.get_arguments())
            t = None
            ai_ = ALLOCATOR_AT.get(c.referenced.spelling, 0)     # (rev5) the size parameter's index (luaM_realloc: 3)
            if len(args) > ai_:
                a = strip(args[ai_])
                if a.kind == K.BINARY_OPERATOR and getattr(getattr(a, "binary_operator", None), "name", "") == "Mul":
                    l_, r_ = list(a.get_children())[:2]
                    t = sizeof_of(l_) or sizeof_of(r_)
            calls.append(((c.location.line, c.location.column), "decl:" + loc_key(c.referenced), t))
        for ch in c.get_children():
            walk(ch, depth + 1)
    for ch in fn.get_children():
        if ch.kind == K.COMPOUND_STMT:
            walk(ch)
    per = {}
    for loc, key, t in sorted(calls):
        per.setdefault(key, []).append(t)
    return {k: v for k, v in per.items() if any(x is not None for x in v)}


def callee_returns(fn):
    """(integ3, allocty) [callee name, its declared result type] of every call in FN's body."""
    out = set()
    for c in fn.walk_preorder():
        if c.kind.name == "CALL_EXPR" and c.referenced is not None:
            try:
                out.add((c.referenced.spelling, c.referenced.result_type.get_canonical().spelling))
            except Exception:   # noqa: BLE001
                pass
    return sorted(list(x) for x in out)


def ast_digest(c32, c64):
    """(integ2, D97; rev5's review) A digest of what a run of the function C32 / C64 takes from the parse besides its
    bytes and its records' layouts: its own declaration (the signature it is called with), the HULK_INTO parameters
    (param_into), and every cast that types an object it is given (param_casts, return_casts and site casts,
    field_casts). The x64 gate keeps it with a cached result: a view type swapped or HULK_INTO added with the same
    code bytes runs again."""
    def sp(t):
        return t if isinstance(t, str) or t is None else t.get_canonical().spelling
    parts = {}
    for n, c in (("32", c32), ("64", c64)):
        fn = c.get_definition() or c
        parts["decl" + n] = [sp(c.type), sp(c.semantic_parent.type) if c.semantic_parent is not None else None,
                             c.spelling]
        try:
            parts["into" + n] = sorted([str(k), str(v)] for k, v in param_into(fn).items())
        except Unsupported as e:
            parts["into" + n] = "unsupported: %s" % e
        parts["pcasts" + n] = sorted([str(k), sp(v)] for k, v in param_casts(fn).items())
        try:
            parts["prange" + n] = sorted([str(k), list(v)] for k, v in param_range(fn).items())
        except Unsupported as e:
            parts["prange" + n] = "unsupported: %s" % e
        parts["rcasts" + n] = sorted([k, sp(v)] for k, v in return_casts(fn).items())
        parts["scasts" + n] = sorted([k, [sp(x) for x in v]] for k, v in return_casts(fn, True).items())
        # (integ3, allocty; rev5 R3) the declared result of every function it calls: an allocator's record pointer types
        # the allocation's untouched bytes, and a `void *` -> `Slot *` change leaves the code bytes alone
        parts["callret" + n] = callee_returns(fn)
        parts["pre" + n] = pre_lines_of(fn)     # (integ3, D152) a contract change re-runs the gate
        # (integ4, post; rev5) the post items and the macros' resolved operands: an edit to either re-runs the gate's
        # operand check (post_macro_check), which equiv.py's operator-only agreement relies on
        try:
            parts["post" + n] = [post_lines_of(fn), post_operands(fn)]
        except Exception as ex_:    # noqa: BLE001
            parts["post" + n] = "error: %s" % ex_
        parts["fcasts" + n] = sorted([list(k), sp(v)] for k, v in field_casts(fn).items())
        # (integ2, D103; rev5's R4) the data annotations of every global of the parse (HULK_RANGE / HULK_RDATA on any
        # declaration, with their comment blocks), not only of those the body names: a helper can read one
        parts["gdata" + n] = gdata_digest_part(fn.translation_unit)
        # (integ2, D111) the pointer-word globals it reads through a typed cast
        parts["gcasts" + n] = sorted([k, v if v == AMBIGUOUS else sp(v)] for k, v in global_casts(fn).items())
    try:     # (integ9, D165) the callees' return posts the run draws in range, as accepted now
        parts["calleepost"] = callee_post_part(c32.get_definition() or c32)
    except Exception as e:      # noqa: BLE001
        parts["calleepost"] = "error: %s" % e
    try:     # (integ3, allocty regions) the record regions the body's offset casts give allocations
        parts["aregions"] = sorted([k, [None if r is None else [r[0], r[1], r[2][0].get_canonical().spelling,
                                                               r[2][1].get_canonical().spelling, r[3]] for r in v]]
                                   for k, v in alloc_site_regions(c32.get_definition() or c32,
                                                                  c64.get_definition() or c64).items())
    except Exception as e:      # noqa: BLE001
        parts["aregions"] = "error: %s" % e
    return hashlib.sha1(json.dumps(parts, sort_keys=True, default=str).encode()).hexdigest()[:16]


def ast_digests(src, symbols):
    """(integ2, D97) {32-bit symbol: ast_digest or None} for SRC's current text (one parse of each target), the 64-bit
    declaration paired with the 32-bit one by its declaration's place (loc_key)."""
    import tree_tu
    out = {}
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build") if os.path.isdir(os.path.join(ROOT, "build")) else None) as d:
        ctx = tree_tu.active(src) if src and tree_tu.is_tree_tu(src) else contextlib.nullcontext()
        with ctx:
            w = write_wrapper(src, d)
            t32 = TU(w, d, "i686-pc-windows-msvc", 32)
            t64 = TU(w, d, "x86_64-pc-windows-msvc", 64)
        idx = {}    # (integ2, D118; rev5) (kind, loc_key) -> the 64-bit cursors there, in by_mangled's order, once
        for c in t64.by_mangled.values():
            idx.setdefault((c.kind, loc_key(c)), []).append(c)
        for s32 in symbols:
            c32 = t32.by_mangled.get(s32)
            if c32 is None:
                out[s32] = None
                continue
            hit = idx.get((c32.kind, loc_key(c32)), [])
            try:
                out[s32] = ast_digest(c32, hit[0]) if len(hit) == 1 else None
            except Exception:   # noqa: BLE001 - can't digest: the result is treated as stale
                out[s32] = None
    return out


AMBIGUOUS = "ambiguous"     # (integ2, F5) a field_casts entry with several cast targets


def field_casts(fn):
    """(integ2, D93, fieldcasts) {(record spelling, field name): T} for the casts in FN's body of a record's pointer
    field straight to a pointer to another record, `(Result_2aecb0*)builder.image` (0x002aecb0): the object such a
    field points at in the input (a stub's out-parameter, a fuzzed object) is generated as the type the code reads
    it through, not the field's declared pointee, whose layout may not cover the words read (pure3d::Image has no
    field where the Entity words sit; read through untyped bytes, a view right for 64-bit read as a layout
    difference and the 32-bit-sized one passed). The first cast of a field wins."""
    K = ci().CursorKind
    out = {}

    def strip(c):
        while c.kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR):
            k = list(c.get_children())
            if len(k) != 1:
                break
            c = k[0]
        return c

    def walk(c, depth=0):
        if depth > 200:
            return
        if c.kind in (K.CSTYLE_CAST_EXPR, K.CXX_STATIC_CAST_EXPR, K.CXX_REINTERPRET_CAST_EXPR):
            t = c.type.get_canonical()
            pk = t.get_pointee().get_canonical() if t.kind.name == "POINTER" else None
            if pk is not None and pk.kind.name == "RECORD":
                kids = [k for k in c.get_children() if k.kind != K.TYPE_REF]
                inner = strip(kids[-1]) if kids else None
                f = inner.referenced if inner is not None and inner.kind == K.MEMBER_REF_EXPR else None
                if f is not None and f.kind == K.FIELD_DECL and f.type.get_canonical().kind.name == "POINTER":
                    fp = f.type.get_canonical().get_pointee().get_canonical()
                    par = f.semantic_parent
                    if fp.kind.name in ("RECORD", "VOID") and fp.spelling != pk.spelling and par is not None:
                        out.setdefault((par.type.get_canonical().spelling, f.spelling), []).append(t.get_pointee())
        for ch in c.get_children():
            walk(ch, depth + 1)
    for ch in fn.get_children():
        if ch.kind == K.COMPOUND_STMT:
            walk(ch)
    # (rev5's re-review, F5) a field the body casts to more than one record (a tagged union: `f8` is a Node or an
    # Actor by type, 0x0019e910) has no one view: AMBIGUOUS (the object keeps its declared type; a run that reads it
    # is reported view_ambiguous)
    res = {}
    for k, ts in out.items():
        sp_ = {t.get_canonical().spelling for t in ts}
        res[k] = ts[0] if len(sp_) == 1 else AMBIGUOUS
    return res


def _pointer_word_global(v):
    """(integ2, D111) Is variable V an untyped pointer-word global: `void*` or `void*[1]` (a generated declaration of
    a word the code reads as a typed pointer)?"""
    t = v.type.get_canonical()
    if t.kind.name == "CONSTANTARRAY" and t.element_count == 1:
        t = t.element_type.get_canonical()
    return t.kind.name == "POINTER" and t.get_pointee().get_canonical().kind.name == "VOID"


def global_casts(fn):
    """(integ2, D111, gcasts) {variable id (_var_id): T*} for the untyped pointer-word globals (_pointer_word_global)
    FN's body reads through `*(T**)&DAT_x` (or `*(T**)DAT_x` of a one-word array): the global's word is generated as
    a T* on both sides, as a pinned view would type it. A global cast to two different T*: AMBIGUOUS (it stays
    untyped; the run says so, class view_ambiguous)."""
    K = ci().CursorKind
    out = {}

    def strip(c):
        while c.kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR):
            k = list(c.get_children())
            if len(k) != 1:
                break
            c = k[0]
        return c

    def walk(c, depth=0):
        if depth > 300:
            return
        if c.kind in (K.CSTYLE_CAST_EXPR, K.CXX_REINTERPRET_CAST_EXPR, K.CXX_STATIC_CAST_EXPR):
            t = c.type.get_canonical()
            pk = t.get_pointee().get_canonical() if t.kind.name == "POINTER" else None
            if pk is not None and pk.kind.name == "POINTER" and c.kind != K.CXX_STATIC_CAST_EXPR:
                kids = [k for k in c.get_children() if k.kind != K.TYPE_REF]
                inner = strip(kids[-1]) if kids else None
                v = None
                if inner is not None and inner.kind == K.UNARY_OPERATOR:
                    toks = [tk.spelling for tk in inner.get_tokens()]
                    ik = [strip(k) for k in inner.get_children()]
                    if toks and toks[0] == "&" and len(ik) == 1 and ik[0].kind == K.DECL_REF_EXPR:
                        v = ik[0].referenced
                elif inner is not None and inner.kind == K.DECL_REF_EXPR and inner.referenced is not None and \
                        inner.referenced.type.get_canonical().kind.name == "CONSTANTARRAY":
                    v = inner.referenced
                if v is not None and v.kind == K.VAR_DECL and _pointer_word_global(v) and \
                        pk.get_pointee().get_canonical().kind.name != "VOID":
                    try:
                        out.setdefault(_var_id(v), []).append(t.get_pointee())
                    except Exception:   # noqa: BLE001
                        pass
            if pk is not None and pk.kind.name != "VOID":
                # (rev5's review) every other cast of the global's value counts toward ambiguity: `(U*)DAT[0]`,
                # static_cast / reinterpret_cast<U*>(DAT[0]), `(U*)DAT` of a scalar void*
                kids = [k for k in c.get_children() if k.kind != K.TYPE_REF]
                inner = strip(kids[-1]) if kids else None
                v = None
                if inner is not None and inner.kind == K.ARRAY_SUBSCRIPT_EXPR:
                    ak = list(inner.get_children())
                    base = strip(ak[0]) if ak else None
                    if base is not None and base.kind == K.DECL_REF_EXPR:
                        v = base.referenced
                elif inner is not None and inner.kind == K.DECL_REF_EXPR and inner.referenced is not None and \
                        inner.referenced.type.get_canonical().kind.name == "POINTER":
                    v = inner.referenced
                if v is not None and v.kind == K.VAR_DECL and _pointer_word_global(v):
                    try:
                        out.setdefault(_var_id(v), []).append(t)
                    except Exception:   # noqa: BLE001
                        pass
        for ch in c.get_children():
            walk(ch, depth + 1)
    for ch in fn.get_children():
        if ch.kind != K.PARM_DECL:
            walk(ch)
    res = {}
    for k, ts in out.items():
        sp_ = {t.get_canonical().spelling for t in ts}
        res[k] = ts[0] if len(sp_) == 1 else AMBIGUOUS
    return res


def return_casts(fn, want_sites=False):
    """{callee declaration key: T*} for the calls in FN's body whose `void*` result the body casts straight to a
    pointer to a record or to a pointer (`(CClosure *)FUN_00219520(L, n)`, `(Ref **)FUN_0008d6d0(bytes)`): the stub's
    object is generated as a T (an allocation is typed as an array of T). The first such cast of a callee wins.
    With SITES, {key: [T* or None per call of that callee, in source order]} instead: (x64t9, sitecasts) one callee
    whose results the body casts to different types, or also uses uncast (`(HulkLoadEntry*)FUN_0008d6d0(n * 16)`
    and `(char*)FUN_0008d6d0(256)` in 0x002656b0), types each allocation by its own call site."""
    K = ci().CursorKind
    out = {}
    sites = {}

    def strip(c):
        while c.kind in (K.PAREN_EXPR, K.UNEXPOSED_EXPR):
            k = list(c.get_children())
            if len(k) != 1:
                break
            c = k[0]
        return c

    def walk(c, depth=0):
        if depth > 200:
            return
        if c.kind in (K.CSTYLE_CAST_EXPR, K.CXX_STATIC_CAST_EXPR, K.CXX_REINTERPRET_CAST_EXPR):
            t = c.type.get_canonical()
            pk = t.get_pointee().get_canonical() if t.kind.name == "POINTER" else None
            if pk is not None and (pk.kind.name in ("RECORD", "POINTER") or pk.kind.name in INT_KINDS and pk.get_size() >= 4):
                kids = [k for k in c.get_children() if k.kind != K.TYPE_REF]
                inner = strip(kids[-1]) if kids else None
                if inner is not None and inner.kind == K.CALL_EXPR and inner.referenced is not None:
                    rt = inner.type.get_canonical()
                    if rt.kind.name == "POINTER" and rt.get_pointee().get_canonical().kind.name == "VOID":
                        out.setdefault("decl:" + loc_key(inner.referenced), t)
                        sites[(inner.location.line, inner.location.column)] = t
        if c.kind == K.CALL_EXPR and c.referenced is not None:
            rt = c.type.get_canonical()
            if rt.kind.name == "POINTER" and rt.get_pointee().get_canonical().kind.name == "VOID":
                calls.append(((c.location.line, c.location.column), "decl:" + loc_key(c.referenced)))
        for ch in c.get_children():
            walk(ch, depth + 1)
    calls = []
    for ch in fn.get_children():
        if ch.kind == K.COMPOUND_STMT:
            walk(ch)
    if want_sites:
        per = {}
        for loc, key in sorted(calls):
            per.setdefault(key, []).append(sites.get(loc))
        return per
    return out


def split_params(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "<(":
            depth += 1
        elif ch in ">)":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return out


# ------------------------------------------------------------------------------------------------- one side
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32, UC_MODE_64, UC_HOOK_MEM_UNMAPPED, UC_HOOK_MEM_WRITE, \
    UC_HOOK_CODE, UC_HOOK_BLOCK, UC_HOOK_MEM_READ, UC_PROT_ALL, UC_PROT_READ, UC_PROT_WRITE, UC_MEM_FETCH_UNMAPPED  # noqa: E402
RW = UC_PROT_READ | UC_PROT_WRITE
from unicorn import x86_const as X  # noqa: E402

ARGREGS64 = [X.UC_X86_REG_RCX, X.UC_X86_REG_RDX, X.UC_X86_REG_R8, X.UC_X86_REG_R9]
XMMREGS = [X.UC_X86_REG_XMM0, X.UC_X86_REG_XMM1, X.UC_X86_REG_XMM2, X.UC_X86_REG_XMM3]
SAVED64 = [X.UC_X86_REG_RBX, X.UC_X86_REG_RBP, X.UC_X86_REG_RSI, X.UC_X86_REG_RDI, X.UC_X86_REG_R12, X.UC_X86_REG_R13,
           X.UC_X86_REG_R14, X.UC_X86_REG_R15]
SAVED32 = [X.UC_X86_REG_EBX, X.UC_X86_REG_EBP, X.UC_X86_REG_ESI, X.UC_X86_REG_EDI]


class Stop(Exception):
    pass


class Side:
    def __init__(self, chk, bits, heap, seed):
        self.chk, self.bits, self.heap, self.seed = chk, bits, heap, seed
        self.ps = bits // 8
        self.events = []
        self.writes = []
        self.counts = {}
        self.cov = set()
        self.flags = set()
        self.stop = None
        self.fault = None
        self.wild = set()
        self.ptrpart = None
        self.rawread = None
        uc = self.uc = Uc(UC_ARCH_X86, UC_MODE_32 if bits == 32 else UC_MODE_64)
        img = chk.img[bits]

        def resolve(name):
            e = chk.ext[bits].get(name)
            if e is None:
                raise Unsupported("unresolved " + name)
            if e[0] == "stub":
                return STUBS + 16 * e[1].idx
            return self.global_obj(e[1]).base(bits)
        code = img.build(resolve)
        uc.mem_map(CODE, len(code), UC_PROT_ALL)
        uc.mem_write(CODE, code)
        uc.mem_map(STACK_LO, STACK_HI - STACK_LO, RW)
        uc.mem_map(SENTINEL, PAGE, UC_PROT_ALL)
        # 32-bit float-returning stub thunks: fld dword [FSLOT]; ret  /  fld qword [FSLOT]; ret
        th = bytes([0xC3]) + bytes(15)
        th += bytes([0xD9, 0x05]) + struct.pack("<I", FSLOT) + bytes([0xC3]) + bytes(9)
        th += bytes([0xDD, 0x05]) + struct.pack("<I", FSLOT) + bytes([0xC3]) + bytes(9)
        uc.mem_write(SENTINEL + 0x10, th)
        nst = max(len(chk.stubs) + 256, 256)
        uc.mem_map(STUBS, ((16 * nst) + PAGE - 1) & ~(PAGE - 1), UC_PROT_ALL)
        uc.mem_write(STUBS, bytes([0xC3]) * (16 * nst))
        self.stub_hi = STUBS + 16 * nst
        self.mapped = set()
        uc.hook_add(UC_HOOK_MEM_UNMAPPED, self._unmapped)
        uc.hook_add(UC_HOOK_MEM_WRITE, self._write)
        hb = HEAP32 if bits == 32 else HEAP64
        uc.hook_add(UC_HOOK_MEM_READ, self._read, begin=hb - 0x1000000, end=hb + 0x1FFFFFFF)
        self.oob = None
        uc.hook_add(UC_HOOK_CODE, self._stub_hit, begin=STUBS, end=self.stub_hi - 1)
        if bits == 32 and chk.range32:
            uc.hook_add(UC_HOOK_BLOCK, self._cov, begin=chk.range32[0], end=chk.range32[1] - 1)
        if bits == 32:
            uc.reg_write(X.UC_X86_REG_FPCW, 0x027F)

            def desc(base, limit, access, flags):
                return struct.pack("<HHBBBB", limit & 0xFFFF, base & 0xFFFF, (base >> 16) & 0xFF, access,
                                   ((limit >> 16) & 0xF) | (flags << 4), (base >> 24) & 0xFF)
            gdt = bytes(8) + desc(0, 0xFFFFF, 0x9A, 0xC) + desc(0, 0xFFFFF, 0x92, 0xC) + desc(TIB32, 0xFFF, 0x92, 0x4)
            uc.mem_map(GDT32, PAGE, RW)
            uc.mem_write(GDT32, gdt)
            uc.reg_write(X.UC_X86_REG_GDTR, (0, GDT32, len(gdt) - 1, 0))
            uc.reg_write(X.UC_X86_REG_FS, 3 * 8)
            for seg in (X.UC_X86_REG_SS, X.UC_X86_REG_DS, X.UC_X86_REG_ES):
                uc.reg_write(seg, 2 * 8)
            uc.mem_map(TIB32, PAGE, RW)
            uc.mem_write(TIB32, struct.pack("<I", M32))
        self.code_end = img.end

    # ---- memory
    def global_obj(self, key):
        h = self.heap
        o = h.by_ident.get(("sym", key))
        if o is not None:
            return o
        lay = RAW
        ent = self.chk.data_keys.get(key, {})
        c32 = ent.get(32, (None, None))[1]
        c64 = ent.get(64, (None, None))[1]
        view = getattr(self.chk, "global_views", {}).get(key)
        gc_ = None
        if view is None and c32 is not None and getattr(self.chk, "gcasts", None):
            try:
                gc_ = self.chk.gcasts.get(_var_id(ent.get(32, (None, None))[1]))
            except Exception:   # noqa: BLE001
                gc_ = None
        if gc_ is not None:
            # (integ2, D111) an untyped pointer word the body reads as a T*: generated as one (a record of include/gen
            # outright, RTTI evidence; a local stand-in is a view taken on trust, as D93's); cast two ways, untyped
            nm_ = ent.get(32, (None, None))[0] or key
            if gc_ == AMBIGUOUS:
                self.chk.types.view_ambiguous.add("global %s" % nm_)
                self.chk.gcasts_used[nm_] = "ambiguous"
            else:
                try:
                    lay = self.chk.types.layout(gc_[0], gc_[1])
                except Unsupported:
                    lay = RAW
                if not lay.raw:
                    pt = (gc_[0].get_pointee(), gc_[1].get_pointee())
                    if self.chk.types._gen_record(pt[0]) and self.chk.types._gen_record(pt[1]):
                        self.chk.gcasts_used[nm_] = pt[0].get_canonical().spelling
                    else:
                        self.chk.types.view_trusted.add("global %s as %s" % (nm_, pt[0].get_canonical().spelling))
                        self.chk.gcasts_used[nm_] = pt[0].get_canonical().spelling + " (view)"
        elif view is not None:
            try:
                lay = self.chk.types.layout(view[0], view[1])
            except Unsupported:
                lay = RAW
        elif c32 is not None and c64 is not None:
            try:
                lay = self.chk.types.layout(c32.type, c64.type)
            except Unsupported:
                lay = RAW
        mod = self.chk.global_model(key) if "gdata" not in OFF else None
        if mod is not None and (view is not None or lay is RAW or lay.raw):
            raise Unsupported("%s on %s: the global has no typed layout of its own (a view, or untyped)" % (
                "HULK_RANGE" if mod[0] == "range" else "HULK_RDATA", key))
        o = h.get(("sym", key), "global", lay, count=1, glob=True)
        if mod is not None:
            self.chk.apply_global_model(o, key, mod, lay, c32)
        return o

    def _unmapped(self, uc, access, address, size, value, data):
        WORKN["hooks"] += 1
        if access == UC_MEM_FETCH_UNMAPPED:
            self.stop = ("crash", "call or jump to unmapped 0x%x" % address)
            return False
        try:
            return self.map_page(address)
        except Exception as e:  # noqa: BLE001
            self.stop = (getattr(e, "cls", "tool"), "map: %r" % e)     # (integ2: view_straddle keeps its class)
            return False

    def map_page(self, address):
        page = address & ~(PAGE - 1)
        if page in self.mapped:
            return False
        o, off = self.heap.find(self.bits, address)
        if o is not None:
            base = o.base(self.bits)
            img = self.heap.image(o, self.bits)
            lo = base & ~(PAGE - 1)
            pre = base - lo
            if pre:
                img = bytes(pre) + bytes(img)
            n = (len(img) + PAGE - 1) & ~(PAGE - 1)
            for p in range(lo, lo + n, PAGE):
                if p in self.mapped:
                    raise Unsupported("object pages overlap")
            self.uc.mem_map(lo, n, RW)
            self.uc.mem_write(lo, bytes(img))
            for p in range(lo, lo + n, PAGE):
                self.mapped.add(p)
            return True
        if address >= (1 << 47) and self.bits == 64:
            self.fault = address
            return False
        self.uc.mem_map(page, PAGE, RW)
        self.mapped.add(page)
        if page >= NULL_HI:
            r = Rng(self.seed, "wild", page)
            self.uc.mem_write(page, b"".join(r.next().to_bytes(8, "little") for _ in range(PAGE // 8)))
            self.flags.add("wild")
            self.wild.add(page)
        return True

    def read(self, a, n):
        try:
            return bytes(self.uc.mem_read(a, n))
        except UcError:
            for p in range(a & ~(PAGE - 1), a + n, PAGE):
                if p not in self.mapped:
                    self.map_page(p)
            return bytes(self.uc.mem_read(a, n))

    def write(self, a, data):
        for p in range(a & ~(PAGE - 1), a + len(data), PAGE):
            if p not in self.mapped and not (STACK_LO <= p < STACK_HI):
                self.map_page(p)
        self.uc.mem_write(a, data)
        self.writes.append((a, len(data)))

    def _write(self, uc, access, address, size, value, data):
        WORKN["hooks"] += 1
        self.writes.append((address, size))

    def _read(self, uc, access, address, size, value, data):
        WORKN["hooks"] += 1
        """Reads past the end of an object (its elements, or an allocation's requested size): an input whose
        32-bit run does this is not used; a 64-bit run that does it alone has a layout difference."""
        if self.oob is not None:
            return
        o, off = self.heap.find(self.bits, address)
        if o is None:
            self.oob = ("heap gap", address)
            return
        if off + size > o.size(self.bits) and (o.init is None or o.rdata is not None):
            self.oob = (describe(o), off)
            return
        if self.bits == 64 and o.lay.raw and size == 8 and self.rawread is None and o.init is None:
            self.rawread = "%s: an 8-byte read at +0x%x of untyped memory" % (describe(o), off)
        if self.bits == 64 and self.ptrpart is None and not o.lay.raw:
            lay = o.lay
            l = lay.leaf_at(64, off % lay.size64)
            if l is not None and l.kind in ("p", "fp", "vp") and (size != 8 or off % lay.size64 != l.o64):
                self.ptrpart = "%s: read %d bytes at +%d of the 8-byte pointer %s" % (
                    describe(o), size, off % lay.size64 - l.o64, ".".join(str(x) for x in l.path))
            elif l is not None and l.kind in ("i", "u") and l.s64 == 4 and size == 8 and off % lay.size64 == l.o64:
                self.ptrpart = "%s: read 8 bytes from the 4-byte field %s (a pointer kept in an int?)" % (
                    describe(o), ".".join(str(x) for x in l.path))

    def _cov(self, uc, address, size, data):
        WORKN["hooks"] += 1
        self.cov.add((address, size))

    def reg(self, r):
        return self.uc.reg_read(r)

    # ---- values
    def read_int(self, a, n):
        return int.from_bytes(self.read(a, n), "little")

    def canon_ptr(self, v):
        """An address as a target-independent value."""
        b = self.bits
        if v == 0:
            return ("null",)
        if v < NULL_HI:
            return ("nullrel",)     # a member of a null object: its offset is the target's layout
        o, off = self.heap.find(b, v)
        if o is not None:
            if retypable(o):
                return ("alloc", o.id, off, b)     # (typed after the run: normalize())
            return ("obj", o.id, self.off32(o, off))
        if STUBS <= v < self.stub_hi:
            i = (v - STUBS) // 16
            if i < len(self.chk.stubs) and (v - STUBS) % 16 == 0:
                return ("fn", repr(self.chk.stubs[i].key))
        if CODE <= v < self.code_end:
            name, off = self.chk.img[b].sym_at(v)
            if name is not None:
                return ("sym", self.chk.canon_name(name, b), off)
        if STACK_LO <= v < STACK_HI:
            return ("stack",)
        if b == 64 and v <= M32 and self.heap.find(64, v | (HEAP64 & ~M32))[0] is not None:
            return ("trunc", v)     # the low half of a 64-bit object address
        # outside every object (an index or offset from fuzzed data, a wild address): no counterpart to compare
        return ("wildptr",)

    def off32(self, o, off):
        if o.kind == "vtable" and self.bits == 64:
            return off // 2 if off % 2 == 0 else ("vt64", off)
        if self.bits == 32 or o.lay.raw or off == 0:
            return off
        lay = o.lay
        if lay.key.startswith("region<") and off >= lay.size64 and "regiontail" not in OFF:
            # (integ4, allocty regions) past the typed records the payload is raw, the same bytes counted from the
            # records' end on both sides (a cookie + one record + a tail: 0x002fdc90's `count * 100 + 4`)
            return off - lay.size64 + lay.size32
        v = lay.to32(off)
        return v if v is not None else ("in64", off)

    def canon_value(self, t, data, ptrwidth=False):
        """DATA (bytes of type T on this side) as a target-independent value. PTRWIDTH: T is an integer of pointer
        width on both targets (hulk_intptr: 4 bytes on i386, 8 on x64)."""
        tc = t.get_canonical()
        k = tc.kind.name
        if k in ("POINTER", "LVALUEREFERENCE", "RVALUEREFERENCE"):
            v = int.from_bytes(data[:self.ps], "little")
            if 0 < v < NULL_HI:
                return ("nullrel",)     # a member of a null object: its offset is the target's layout
            return self.canon_ptr(v)
        if k == "FLOAT":
            return fcanon("f", data[:4])
        if k in ("DOUBLE", "LONGDOUBLE"):
            return fcanon("d", data[:8])
        if k == "RECORD":
            return ("rec", tc.spelling, data.hex())
        if k == "VOID":
            return ("void",)
        n = tc.get_size()
        v = int.from_bytes(data[:n], "little")
        if n >= 4:
            o_, off_ = self.heap.find(self.bits, v)
            if (o_ is not None and off_ < o_.size(self.bits)) or (STUBS <= v < self.stub_hi) or \
                    (CODE <= v < self.code_end and self.chk.reachable(self.bits, v)):
                return self.canon_ptr(v)
            # a pointer-width integer (hulk_intptr) holding the address of a local: its value is the stack's layout
            if ptrwidth and STACK_LO <= v < STACK_HI:
                return self.canon_ptr(v)
        signed = INT_KINDS.get(k, k == "ENUM")
        if signed and v >= 1 << (8 * n - 1):
            v -= 1 << (8 * n)
        return ("i", v)

    # ---- the call
    def arg_locs(self, sig, has_sret):
        """Where each argument is at entry to a callee (ESP/RSP pointing at the return address):
        list of ("reg", r) / ("stack", off) / ("xmm", i), and the bytes a 32-bit callee pops."""
        b = self.bits
        kinds = []
        if sig.has_this:
            kinds.append(("this", None))
        if has_sret:
            kinds.append(("sret", None))
        for i, (t32, t64) in enumerate(sig.params):
            kinds.append(("param", (t32, t64)[0 if b == 32 else 1]))
        locs = []
        if b == 32:
            off = 4
            regs = []
            if sig.cc32 == CC_THIS and not sig.variadic:
                regs = [X.UC_X86_REG_ECX]
            elif sig.cc32 == CC_FAST:
                regs = [X.UC_X86_REG_ECX, X.UC_X86_REG_EDX]
            for kind, t in kinds:
                size = 4 if t is None else max(4, (t.get_canonical().get_size() + 3) & ~3)
                if kind == "this" and sig.cc32 == CC_THIS and regs:
                    locs.append(("reg", regs.pop(0)))
                    continue
                if sig.cc32 == CC_FAST and regs and size == 4 and (t is None or not is_float_t(t) and not is_record(t)):
                    locs.append(("reg", regs.pop(0)))
                    continue
                if sig.cc32 == CC_THIS and kind == "this":
                    pass
                locs.append(("stack", off))
                off += size
            pop = off - 4 if sig.cc32 in (CC_STD, CC_FAST, CC_THIS) and not sig.variadic else 0
            return kinds, locs, pop
        for i, (kind, t) in enumerate(kinds):
            if i < 4:
                if t is not None and is_float_t(t):
                    locs.append(("xmm", i))
                else:
                    locs.append(("reg", ARGREGS64[i]))
            else:
                locs.append(("stack", 8 + 8 * i))
        return kinds, locs, 0

    def read_loc(self, loc, n, sp):
        if loc[0] == "reg":
            return (self.reg(loc[1]) & ((1 << (8 * self.ps)) - 1)).to_bytes(self.ps, "little")[:n].ljust(n, b"\0")
        if loc[0] == "xmm":
            return (self.reg(XMMREGS[loc[1]]) & M64).to_bytes(8, "little")[:n]
        return self.read(sp + loc[1], n)

    def value_bytes(self, t, loc, sp):
        """The bytes of an argument of type T at LOC (a record passed by reference on x64 is read through it)."""
        n = t.get_canonical().get_size()
        if n < 0:
            # (x64eq) libclang has no size for it (an incomplete or dependent type passed by value)
            raise Unsupported("argument of a type without a size (%s)" % getattr(t, "spelling", t))
        if self.bits == 64 and is_record(t) and (n not in (1, 2, 4, 8) or not trivial_copy(rdecl(t))):
            p = int.from_bytes(self.read_loc(loc, 8, sp), "little")
            return self.read(p, n)
        if self.bits == 64 and loc[0] == "stack":
            return self.read(sp + loc[1], n)
        return self.read_loc(loc, n, sp)

    def call(self):
        """Run the function under test on this side's view of the input."""
        import equiv
        chk, b, uc = self.chk, self.bits, self.uc
        sig = chk.sig
        sret = ret_indirect(sig, b)
        kinds, locs, pop = self.arg_locs(sig, sret)
        sp = ENTRY_SP
        stack = bytearray(0x400)
        regs = {}
        r = Rng(self.seed, "args")
        self.sret_obj = None
        for i, ((kind, t), loc) in enumerate(zip(kinds, locs)):
            if kind == "this":
                lay = chk.types.layout(sig.method_record[0], sig.method_record[1])
                o = self.heap.get(("arg", "this"), "heap", lay)
                data = self.heap.ptr_value(b, ("p", o, 0)).to_bytes(self.ps, "little")
            elif kind == "sret":
                rt = sig.ret
                lay = chk.types.layout(rt[0], rt[1])
                o = self.heap.get(("sret",), "sret", lay, count=1)
                self.sret_obj = o
                data = self.heap.ptr_value(b, ("p", o, 0)).to_bytes(self.ps, "little")
            else:
                pi = i - (len(kinds) - len(sig.params))
                pt = sig.params[pi]
                if pi in chk.param_casts:
                    # a void* / hulk_intptr parameter the function casts to T*: generated as a T*
                    pt = chk.param_casts[pi]
                data = None
                if pi in chk.param_range:
                    # (integ2, D102) an integer parameter annotated HULK_RANGE: drawn from the range its callers pass
                    lo_, hi_ = chk.param_range[pi]
                    v_ = lo_ + Rng(self.seed, "arg", i).below(hi_ - lo_ + 1)
                    sz_ = max(4, pt[0 if b == 32 else 1].get_canonical().get_size())
                    data = (v_ & ((1 << (8 * sz_)) - 1)).to_bytes(sz_, "little")
                if data is None and pi in chk.param_into:
                    data = self.arg_into(chk.param_into[pi], Rng(self.seed, "arg", i))
                if data is None:
                    data = self.arg_data(pt, ("arg", i), Rng(self.seed, "arg", i))
                if pi in getattr(chk, "pre_ranges", {}):
                    import equiv
                    t_ = pt[0 if b == 32 else 1].get_canonical()
                    w_ = t_.get_size()
                    typ_ = "f" if t_.kind.name in ("FLOAT", "DOUBLE") else "i"
                    cond_ = chk.pre_ranges[pi]
                    if equiv._pre_relational(cond_):
                        # (integ4, x64bounds; rev5) `lt(argN, this->count)`: the bound is the this-object's field as
                        # generated for this input (its HULK_RANGE draw), the same on both sides; an empty domain (no
                        # value can satisfy it) sets the input aside
                        cond_ = self.pre_resolve(cond_)
                        if cond_[0] == "empty":
                            return {"skip": "pre_empty", "stop": ("pre_empty", cond_[1]), "side": self,
                                    "events": [], "cov": set(), "flags": set()}
                    nb_ = equiv._pre_range_fix(self.seed, i, bytes(data[:w_]), w_, cond_ + (typ_,), True)
                    if nb_ is not None:
                        data = nb_ + bytes(data[w_:])
            if loc[0] == "reg":
                regs[loc[1]] = int.from_bytes(data[:self.ps].ljust(self.ps, b"\0"), "little")
            elif loc[0] == "xmm":
                regs[XMMREGS[loc[1]]] = int.from_bytes(data[:8].ljust(8, b"\0"), "little")
            else:
                stack[loc[1]:loc[1] + len(data)] = data
        struct.pack_into("<I" if b == 32 else "<Q", stack, 0, SENTINEL)
        uc.mem_write(sp, bytes(stack))
        spr = X.UC_X86_REG_ESP if b == 32 else X.UC_X86_REG_RSP
        uc.reg_write(spr, sp)
        saved = {}
        for j, rr in enumerate(SAVED32 if b == 32 else SAVED64):
            v = 0x5EED0000 + j * 0x111 if b == 32 else 0x5EED00000000 + j * 0x111
            uc.reg_write(rr, v)
            saved[rr] = v
        for rr, v in regs.items():
            uc.reg_write(rr, v)
        entry = chk.img[b].funcs[chk.sym32 if b == 32 else chk.sym64]
        try:
            WORKN["runs"] += 1
            t_run = time.monotonic()
            uc.emu_start(entry, SENTINEL, count=STEPS if b == 32 else 2 * STEPS, timeout=RUN_TIMEOUT)   # (64-bit: more room)
        except UcError as e:
            if self.stop is None:
                pc = self.reg(X.UC_X86_REG_EIP if b == 32 else X.UC_X86_REG_RIP)
                fn, fo = chk.img[b].sym_at(pc) if CODE <= pc < self.code_end else (None, 0)
                where = "%s+0x%x" % (fn, fo) if fn else "0x%x" % pc
                if self.fault is not None:
                    self.stop = ("crash", "access to 0x%x at %s: not an address (a pointer read from 32-bit data?)" % (self.fault, where))
                else:
                    self.stop = ("crash", "%s at %s" % (e, where))
        for o_ in self.heap.objs:
            if o_.rdata is not None:
                # (integ2, D103) HULK_RDATA says nothing stores into the table: a store that does refutes it
                lo_, hi_ = o_.base(b), o_.base(b) + o_.size(b)
                hit_ = next((a_ for a_, n_ in self.writes if a_ < hi_ and a_ + n_ > lo_), None)
                if hit_ is not None:
                    raise Unsupported("HULK_RDATA: the %d-bit run stored into %s at +0x%x" % (b, o_.rdata, hit_ - lo_))
        pc = self.reg(X.UC_X86_REG_EIP if b == 32 else X.UC_X86_REG_RIP)
        out = {"events": self.events, "cov": self.cov, "flags": self.flags, "side": self}
        nullw = next((a for a, n in self.writes if a < NULL_HI), None)
        if nullw is not None and b == 32:
            out["skip"] = "null"
            out["stop"] = ("null", "32-bit write to 0x%x (a member of a null object)" % nullw)
            return out
        if self.oob is not None:
            out["oob"] = self.oob
            if b == 32:
                out["skip"] = "oob"
                out["stop"] = ("oob", "32-bit read past %s +0x%x" % self.oob)
                return out
        if self.stop is not None:
            if self.stop[0] == "throw":
                out["throw"] = True
            else:
                out["stop"] = self.stop
                if b == 32:
                    out["skip"] = self.stop[0]
                return out
        elif pc != SENTINEL and "workclock" not in equiv.EQUIV_OFF and \
                time.monotonic() - t_run >= 0.95 * RUN_TIMEOUT / 1e6:
            # (integ3, workclock; rev5 1) Unicorn's wall-clock timeout stopped the run, not its step count: a hang is
            # decided by steps only, so this input says nothing (the whole run is time_cut_wall, Checker.run)
            chk.wall_cut = True
            out["stop"] = ("wallcut", "the %gs per-run safety timeout stopped the run before its steps ran out"
                           % (RUN_TIMEOUT / 1e6))
            out["skip"] = "wallcut"
            return out
        elif pc != SENTINEL:
            out["stop"] = ("hang", "ran out of %d steps" % STEPS)
            if b == 32:
                out["skip"] = "hang"
            return out
        if not out.get("throw"):
            spv = self.reg(spr)
            want = sp + (4 + pop if b == 32 else 8)
            if spv != want:
                out["stack"] = "stack pointer off by %d" % (spv - want)
            for rr, v in saved.items():
                if self.reg(rr) != v:
                    out["saved"] = "callee-saved register clobbered"
            out["ret"] = self.ret_value(sig, sret)
        return out

    def pre_resolve(self, cond):
        """(integ4, x64bounds) COND with its ("field", NAME) bounds replaced by this input's values of this->NAME: an
        integer field with a cited HULK_RANGE (else Unsupported). ("empty", why) when no integer satisfies it."""
        o = self.heap.by_ident.get(("arg", "this"))
        if o is None or o.lay.raw:
            raise Unsupported("relational pre %r: no typed this-object" % (cond,))
        vals = []
        for x in cond[1:3]:
            if isinstance(x, tuple):
                l = next((y for y in o.lay.leaves if y.path[-1:] == (x[1],) and len(y.path) % 2 == 1 and
                          all(y.path[i] == "base" for i in range(0, len(y.path) - 1, 2))), None)   # (or a base's field)
                if l is None or l.kind != "i" or l.range is None:
                    raise Unsupported("relational pre: this->%s is not an integer field with a cited HULK_RANGE" % x[1])
                v = self.heap.leaf_value(o, 0, l)
                x = float(v[1])
            vals.append(x)
        c = ("range", vals[0], vals[1], cond[3], cond[4])
        lo = vals[0] if cond[3] else vals[0] + 1
        hi = vals[1] if cond[4] else vals[1] - 1
        if lo > hi:
            return ("empty", "no integer in %r" % (c,))
        return c

    def arg_into(self, field, r):
        """(x64t13, HULK_INTO) A pointer into the array this->FIELD points to, at a fuzzed byte offset (null with it);
        None when `this` has no such pointer field."""
        o = self.heap.by_ident.get(("arg", "this"))
        strict = "intocheck" not in OFF
        if o is None or o.lay.raw:
            # (integ1, rev5/D61) refuse: the annotation names a field of `this`, and there is no typed this-object
            if strict:
                raise Unsupported("HULK_INTO(%s): no typed this-object" % field)
            return None
        l = next((x for x in o.lay.leaves if x.path == (field,) and x.kind == "p"), None)
        if l is None:
            if strict:
                raise Unsupported("HULK_INTO(%s): `this` has no pointer field of that name" % field)
            return None
        v = self.heap.leaf_value(o, 0, l)
        if v[0] != "p" or v[1] is None:
            return self.heap.ptr_value(self.bits, ("p", None, 0)).to_bytes(self.ps, "little")
        t = v[1]
        n = t.size(32) - v[2]
        if strict and n <= 1 and t.size(32) <= 1:
            # (integ1, rev5/D61) a base whose object is one element (a char* field's pointee generated as one char):
            # the offset draw would always be 0, so the annotation would test nothing
            raise Unsupported("HULK_INTO(%s): the pointee object is %d byte(s): no offset to draw" % (field, t.size(32)))
        off = v[2] + (r.below(n) if n > 0 else 0)
        return self.heap.ptr_value(self.bits, ("p", t, off)).to_bytes(self.ps, "little")

    def arg_data(self, tt, ident, r):
        """Bytes of an input argument of paired type tt on this side (pointers to fresh objects)."""
        b = self.bits
        t = tt[0 if b == 32 else 1]
        tc = t.get_canonical()
        k = tc.kind.name
        if k in ("POINTER", "LVALUEREFERENCE", "RVALUEREFERENCE"):
            p = tc.get_pointee().get_canonical()
            if p.kind.name in ("FUNCTIONPROTO", "FUNCTIONNOPROTO"):
                pp = (tt[0].get_canonical().get_pointee(), tt[1].get_canonical().get_pointee())
                st = self.chk.fnptr_stub(("fnptr",) + ident, pp)
                return self.chk.stub_addr(st.key).to_bytes(self.ps, "little")
            pp = (tt[0].get_canonical().get_pointee(), tt[1].get_canonical().get_pointee())
            if k == "POINTER" and r.below(100) < 8:
                v = ("p", None, 0)
            else:
                lay = self.chk.types.layout(pp[0], pp[1])
                v = ("p", self.heap.get(ident, "heap", lay), 0)
            return self.heap.ptr_value(b, v).to_bytes(self.ps, "little")
        if k == "RECORD":
            lay = self.chk.types.layout(tt[0], tt[1])
            o = self.heap.get(ident + ("val",), "argcopy", lay, count=1)
            img = self.heap.image(o, b)
            data = bytes(img[:lay.size(b)])
            if b == 64 and (lay.size64 not in (1, 2, 4, 8) or not trivial_copy(rdecl(tt[1]))):
                return self.heap.ptr_value(b, ("p", o, 0)).to_bytes(8, "little")
            return data.ljust((len(data) + 3) & ~3, b"\0")
        if k == "FLOAT":
            return struct.pack("<f", gen_float(r))
        if k in ("DOUBLE", "LONGDOUBLE"):
            return struct.pack("<d", gen_float(r))
        n = tc.get_size()
        signed = INT_KINDS.get(k, k == "ENUM")
        v = gen_int(r, min(n, 4), signed)
        if signed and v >= 1 << (8 * min(n, 4) - 1):
            v -= 1 << (8 * min(n, 4))
        if n == 8 and k in ("LONGLONG", "ULONGLONG") and tt[0].get_canonical().get_size() == 8:
            v = r.next()        # (an __int64 on both; a pointer-width integer keeps its 32-bit value, extended)
        return (v & ((1 << (8 * n)) - 1)).to_bytes(n, "little")

    def ret_value(self, sig, sret):
        b = self.bits
        rt = sig.ret[0 if b == 32 else 1]
        tc = rt.get_canonical()
        k = tc.kind.name
        if k == "VOID":
            return ("void",)
        if sret:
            o = self.sret_obj
            ret = self.reg(X.UC_X86_REG_EAX if b == 32 else X.UC_X86_REG_RAX)
            return ("sret", self.canon_ptr(ret))
        if k in ("FLOAT", "DOUBLE", "LONGDOUBLE"):
            if b == 32:
                top = (self.reg(X.UC_X86_REG_FPSW) >> 11) & 7
                import equiv
                v = equiv._x87_value(self.reg(X.UC_X86_REG_FP0 + top))
                if k == "FLOAT":
                    return fcanon("f", struct.pack("<f", v) if math.isfinite(v) or math.isinf(v) else b"\0\0\xc0\x7f")
                return fcanon("d", struct.pack("<d", v))
            x = self.reg(X.UC_X86_REG_XMM0)
            if k == "FLOAT":
                return fcanon("f", struct.pack("<I", x & M32))
            return fcanon("d", struct.pack("<Q", x & M64))
        n = tc.get_size()
        if b == 32:
            v = self.reg(X.UC_X86_REG_EAX) | (self.reg(X.UC_X86_REG_EDX) << 32)
        else:
            v = self.reg(X.UC_X86_REG_RAX)
        return self.canon_value(rt, (v & ((1 << (8 * max(n, 1))) - 1)).to_bytes(max(n, 1), "little")
                                if k != "RECORD" else v.to_bytes(8, "little")[:n])

    # ---- stubs
    def _stub_hit(self, uc, address, size, data):
        WORKN["hooks"] += 1
        try:
            self.stub(address)
        except Stop:
            uc.emu_stop()
        except Unsupported as e:
            self.stop = (getattr(e, "cls", "tool"), str(e))
            uc.emu_stop()
        except UcError as e:
            self.stop = ("crash", "in stub: %s" % e)
            uc.emu_stop()

    def stub(self, address):
        b, uc = self.bits, self.uc
        i = (address - STUBS) // 16
        if (address - STUBS) % 16 or i >= len(self.chk.stubs):
            self.stop = ("crash", "jump into stub area 0x%x" % address)
            raise Stop()
        st = self.chk.stubs[i]
        spr = X.UC_X86_REG_ESP if b == 32 else X.UC_X86_REG_RSP
        sp = self.reg(spr)
        retaddr = self.read_int(sp, self.ps)
        name = st.names.get(b, st.label) if st.kind == "func" else st.label
        name = untree(name)
        cname = c_name(name, b) if name else None
        n = self.counts.get(st.key, 0)
        self.counts[st.key] = n + 1
        if cname in SKIP_CALLS or (name or "").lstrip("_") in SKIP_CALLS:
            if cname in ("_chkstk", "chkstk", "_alloca_probe", "alloca_probe") and b == 32:
                # __chkstk: allocate EAX bytes below the caller's stack pointer
                eax = self.reg(X.UC_X86_REG_EAX)
                new = sp + 4 - eax
                uc.reg_write(spr, new)
                uc.reg_write(X.UC_X86_REG_EIP, retaddr)
                return
            return self._ret(sp, retaddr, 0, None, None)
        if cname in I386_HELPERS or (name or "") in I386_HELPERS:
            return self.helper386(name, sp, retaddr)
        if cname is not None and cname.lstrip("_") in CRT_STRIPPED:
            return self.crt(cname.lstrip("_"), sp, retaddr)
        if st.kind == "vslot" and st.sig == ("deleting",):
            sig = None
        else:
            sig = st.sig
        if name in ALLOCATORS or cname in ALLOCATORS or ALLOCATOR_CXX.match(name or "") or \
                (ALLOCATOR_MEMBER.match(name or "") and isinstance(sig, Sig) and sig.has_this and sig.params) or \
                (allocator_at(name, cname) is not None and isinstance(sig, Sig) and not sig.has_this and
                 len(sig.params) > allocator_at(name, cname)):
            return self.allocator(st, n, sp, retaddr)
        if cname in ("_CxxThrowException", "CxxThrowException") or (name or "").startswith("__CxxThrowException"):
            self.events.append(("throw", st.label))
            self.stop = ("throw", "")
            raise Stop()
        if cname == "__RTDynamicCast" or name == "___RTDynamicCast":
            return self.dyncast(st, n, sp, retaddr)
        if sig is None or not isinstance(sig, Sig):
            if st.kind == "vslot" and st.sig == ("deleting",):
                this = self.reg(X.UC_X86_REG_ECX if b == 32 else X.UC_X86_REG_RCX)
                flg = self.read_int(sp + 4, 4) if b == 32 else self.reg(X.UC_X86_REG_EDX) & M32
                self.events.append(("call", repr(st.key), (self.canon_ptr(this), ("i", flg))))
                return self._ret(sp, retaddr, 4 if b == 32 else 0, ("int", this), None)
            raise Unsupported("call to %s without a signature" % (name or st.label))
        sret = ret_indirect(sig, b)
        kinds, locs, pop = self.arg_locs(sig, sret)
        args = []
        this_local = None
        nparam = 0
        sret_ptr = None
        this_v = None
        pvals = []          # (integ4, post) each parameter's word (a pointer's address)
        for (kind, t), loc in zip(kinds, locs):
            if kind == "this":
                v = int.from_bytes(self.read_loc(loc, self.ps, sp), "little")
                this_v = v
                args.append(("this", self.canon_ptr(v)))
                self.hint(v, sig.method_record)
                if STACK_LO <= v < STACK_HI and sig.method_record is not None:
                    this_local = v
            elif kind == "sret":
                sret_ptr = int.from_bytes(self.read_loc(loc, self.ps, sp), "little")
            else:
                tt = sig.params[nparam]
                nparam += 1
                if b == 32 and is_record(t) and not trivial_copy(rdecl(t)):
                    # i386 passes such a record in an argument block clang builds in place (inalloca)
                    raise Unsupported("record with a copy constructor or destructor passed by value (%s)" % st.label)
                data = self.value_bytes(t, loc, sp)
                pvals.append(int.from_bytes(data[:self.ps], "little") if len(data) >= self.ps else None)
                cv = self.canon_value(t, data, ptr_width_int(tt))
                if cv[0] == "rec":
                    cv = self.canon_record(tt, data)
                args.append(cv)
                tc = t.get_canonical()
                if tc.kind.name in ("POINTER", "LVALUEREFERENCE"):
                    v = int.from_bytes(data[:self.ps], "little")
                    pt = (tt[0].get_canonical().get_pointee(), tt[1].get_canonical().get_pointee())
                    self.hint(v, pt)
                    # the local behind a pointer is compared when it is an input: const, or a record (a struct
                    # built for the callee); a non-const scalar is an out-parameter (fill_out writes it)
                    if STACK_LO <= v < STACK_HI and (tc.get_pointee().is_const_qualified() or is_record(tc.get_pointee())):
                        args.append(("pointee",) + self.pointee(pt, v))
        self.events.append(("call", repr(st.key), tuple(args)))
        # out-parameters: typed locals passed by non-const pointer get the same fresh contents on both sides
        nparam = 0
        for (kind, t), loc in zip(kinds, locs):
            if kind != "param":
                continue
            tt = sig.params[nparam]
            nparam += 1
            tc = t.get_canonical()
            if tc.kind.name in ("POINTER", "LVALUEREFERENCE") and not tc.get_pointee().is_const_qualified():
                v = int.from_bytes(self.value_bytes(t, loc, sp)[:self.ps], "little")
                # (a T** into an object, `Create(&this->mStream)`, is an out-parameter too: the callee stores a pointer)
                if STACK_LO <= v < STACK_HI or (tc.get_pointee().get_canonical().kind.name == "POINTER"
                                                 and self.heap.find(b, v)[0] is not None):
                    self.fill_out(v, tt, st.key, n, nparam)
        if this_local is not None and not getattr(sig, "const_method", False) and "deleting" not in st.label \
                and not st.label.startswith("??1"):
            # a method called on a local (a non-const method can set it up: `Key key; key.Parse(name);`)
            self.fill_out(this_local, (FakeType("POINTER", 4, sig.method_record[0]), FakeType("POINTER", 8, sig.method_record[1])),
                          st.key, n, 0)
        rv = self.stub_return(sig, st, n, sret, sret_ptr)
        if rv is not None and st.kind == "func" and not sret and self.direct_call(retaddr, st):
            rp_ = self.chk.ret_post_of(st.names.get(32) or name or st.label)
            if rp_ is not None:
                rv = self.ret_post_draw(rp_, rv, sig, st, n)
        pa_ = self.chk.post_of(st.names.get(32) or name or st.label) if "post" not in OFF and st.kind == "func" else None
        if pa_ and rv is not None and rv[0] == "int":
            rv = self.post_fill(pa_, rv, sig, this_v, pvals, st, n)
        return self._ret(sp, retaddr, pop, rv, sig)

    def post_fill(self, items, rv, sig, this_v, pvals, st, n):
        """(integ4, post; rev5) A stubbed callee whose definition states `// post: ... when ret`: when the stub's result
        is nonzero (al for a byte result), each *argN gets a value inside its items' bounds (a `*this+0xOFF` bound read
        from the object in this, at the 32-bit offset's field on each side), drawn from the seed, the same on both sides;
        with no value inside, the stub returns 0 (the definition can't return nonzero then). A zero result leaves the
        out-parameters as the stub filled them."""
        b = self.bits
        rk = sig.ret[0].get_canonical().kind.name if isinstance(sig, Sig) else ""
        v = rv[1]
        if not ((v & 0xFF) if rk in ("BOOL", "CHAR_S", "UCHAR", "SCHAR", "CHAR_U") else v):
            return rv
        by_n = {}
        for k, cond in items:
            if k == "ret":
                continue        # (integ9, D165) a return item: stub_return's draw (ret_post_of), not an out-parameter
            by_n.setdefault(k, []).append(cond)
        if not by_n:
            return rv
        writes = []
        for k, conds in sorted(by_n.items()):
            if k - 1 >= len(pvals) or pvals[k - 1] is None:
                raise Unsupported("post: *arg%d of %s: no such parameter" % (k, st.label))
            lo, hi = float("-inf"), float("inf")
            for c in conds:
                bnd = []
                for x in c[1:3]:
                    if isinstance(x, tuple):
                        x = float(self.post_field(this_v, x[1], st))
                    bnd.append(x)
                l_ = bnd[0] if c[3] else bnd[0] + 1
                h_ = bnd[1] if c[4] else bnd[1] - 1
                lo, hi = max(lo, l_), min(hi, h_)
            lo = max(lo, -(1 << 31))
            hi = min(hi, (1 << 31) - 1)
            if lo > hi:
                return ("int", 0)
            r = Rng(self.seed, "post", rng_key(st.key), n, k)
            span = int(hi - lo) + 1
            writes.append((pvals[k - 1], int(lo) + r.below(min(span, 1 << 30))))
        for a, x in writes:
            self.write(a, (x & M32).to_bytes(4, "little"))
        return rv

    def direct_call(self, retaddr, st):
        """(integ9, D165; rev5) Did a direct call reach stub ST: a `call rel32` (E8) ending at RETADDR whose target is
        the stub? A call through a vftable slot, a function pointer or a tail jump is not (no draw: fail closed)."""
        try:
            ins = self.read(retaddr - 5, 5)
        except Exception:   # noqa: BLE001
            return False
        if len(ins) != 5 or ins[0] != 0xE8:
            return False
        t = (retaddr + int.from_bytes(ins[1:5], "little", signed=True)) & ((1 << self.bits) - 1)
        return t == self.chk.stub_addr(st.key)

    def ret_post_draw(self, rng, rv, sig, st, n):
        """(integ9, D165) A direct callee whose return postcondition is accepted for x64 callers (ret_post_accept): its
        stub's result lies inside the range, one input in twenty at the range's inner bound (equiv._pre_range_fix, the
        32-bit checker's draw), from the seed and the call's number: the same on both sides. A NaN never. A pointer or
        record result is left alone (a return item states a number)."""
        import equiv
        b = self.bits
        rt = sig.ret[0 if b == 32 else 1].get_canonical()
        k = rt.kind.name
        if rv[0] in ("f", "d"):
            w, typ, raw = (4, "f", struct.pack("<f", rv[1])) if rv[0] == "f" else (8, "f", struct.pack("<d", rv[1]))
        elif rv[0] == "int" and (k == "BOOL" or k == "ENUM" or k in INT_KINDS) and rt.get_size() in (1, 2, 4, 8):
            w, typ = rt.get_size(), "i"
            raw = (rv[1] & ((1 << (8 * w)) - 1)).to_bytes(w, "little")
        else:
            return rv
        s_ = Rng(self.seed, "retpost", rng_key(st.key), n).next()
        nb_ = equiv._pre_range_fix(s_, 0xD165, raw, w, tuple(rng) + (typ,), True)
        if nb_ is None:
            return rv
        if typ == "f":
            return (rv[0], struct.unpack("<f" if w == 4 else "<d", nb_)[0])
        return ("int", int.from_bytes(nb_, "little"))

    def post_field(self, this_v, off32, st):
        """(integ4, post) The signed 32-bit field at the original's offset OFF32 of the object THIS_V points at (its
        record's leaf there, at that leaf's offset on this side)."""
        o, off = self.heap.find(self.bits, this_v or 0)
        if o is None or o.lay.raw:
            raise Unsupported("post on %s: no typed object in this" % st.label)
        es = o.lay.size(self.bits)
        if off % es:
            raise Unsupported("post on %s: this points inside an element" % st.label)
        l = next((x for x in o.lay.leaves if x.o32 == off32 and x.kind == "i" and x.s32 == 4 and x.s64 == 4), None)
        if l is None:
            raise Unsupported("post on %s: no 4-byte integer field at +0x%x of %s" % (st.label, off32, o.lay.key))
        v = int.from_bytes(self.read(this_v + l.off(self.bits), 4), "little")
        return v - (1 << 32) if v & 0x80000000 else v

    def hint(self, v, pt):
        if pt is None or isinstance(pt[0], FakeType) or isinstance(pt[1], FakeType):
            return      # (x64eq) a synthesized signature's builtin type types nothing
        o, off = self.heap.find(self.bits, v)
        if o is not None and off == 0 and retypable(o):
            try:
                lay = self.chk.types.layout(pt[0], pt[1])
            except Unsupported:
                return
            if not lay.raw and (o.hint is None or lay.size32 > o.hint.size32):
                o.hint = lay        # (the largest type it was passed as; a vftable at +0 overrides: type_allocations)

    def pointee(self, pt, v):
        try:
            lay = self.chk.types.layout(pt[0], pt[1])
        except Unsupported:
            return ("?",)
        if lay.raw:
            return ("raw",)
        return tuple(self.decode_leaf(v + l.off(self.bits), l) for l in lay.leaves[:256])

    def canon_record(self, tt, data):
        lay = self.chk.types.layout(tt[0], tt[1])
        out = []
        for l in lay.leaves:
            o = l.off(self.bits)
            out.append(self.decode_bytes(l, data[o:o + l.size(self.bits)]))
        return ("rec", tuple(out))

    def decode_leaf(self, a, l):
        return self.decode_bytes(l, self.read(a, l.size(self.bits)))

    def decode_bytes(self, l, data):
        k = l.kind
        if k in ("p", "fp", "vp", "mfp"):
            return self.canon_ptr(int.from_bytes(data, "little"))
        if k == "f":
            return fcanon("f", data)
        if k == "d":
            return fcanon("d", data)
        if k == "b":
            return ("b", data.hex())
        v = int.from_bytes(data, "little")
        n = len(data)
        o_, off_ = self.heap.find(self.bits, v) if n >= 4 else (None, 0)
        if n >= 4 and ((o_ is not None and off_ < o_.size(self.bits)) or STUBS <= v < self.stub_hi):
            return self.canon_ptr(v)
        if l.signed and n and v >= 1 << (8 * n - 1):
            v -= 1 << (8 * n)
        return ("i", v)

    def fill_out(self, v, tt, key, n, argi):
        pt = (tt[0].get_canonical().get_pointee(), tt[1].get_canonical().get_pointee())
        try:
            lay = self.chk.types.layout(pt[0], pt[1])
        except Unsupported:
            return
        if lay.raw:
            return
        tmp = self.heap.get(("out", repr(key), n, argi), "out", lay, count=1)
        img = self.heap.image(tmp, self.bits)
        self.write(v, bytes(img[:lay.size(self.bits)]))

    def stub_return(self, sig, st, n, sret, sret_ptr):
        b = self.bits
        rt = sig.ret[0 if b == 32 else 1]
        tt = sig.ret
        tc = rt.get_canonical()
        k = tc.kind.name
        r = Rng(self.seed, "ret", rng_key(st.key), n)
        if k == "VOID":
            return None
        if sret:
            lay = self.chk.types.layout(tt[0], tt[1])
            tmp = self.heap.get(("retval", repr(st.key), n), "out", lay, count=1)
            img = self.heap.image(tmp, b)
            self.uc.mem_write(sret_ptr, bytes(img[:lay.size(b)]))
            return ("int", sret_ptr)
        if k in ("POINTER", "LVALUEREFERENCE", "RVALUEREFERENCE"):
            p = (tt[0].get_canonical().get_pointee(), tt[1].get_canonical().get_pointee())
            if p[0].get_canonical().kind.name in ("FUNCTIONPROTO", "FUNCTIONNOPROTO"):
                s2 = self.chk.fnptr_stub(("fnret", repr(st.key), n), p)
                return ("int", self.chk.stub_addr(s2.key))
            if k == "POINTER" and p[0].get_canonical().kind.name == "VOID" and st.key in self.chk.ret_casts:
                p = self.chk.ret_casts[st.key]
            v = self.heap.choose_ptr(r, ("ret", repr(st.key), n), p) if k == "POINTER" else \
                ("p", self.heap.get(("ret", repr(st.key), n), "heap", self.chk.types.layout(p[0], p[1])), 0)
            return ("int", self.heap.ptr_value(b, v))
        if k == "FLOAT":
            return ("f", gen_float(r))
        if k in ("DOUBLE", "LONGDOUBLE"):
            return ("d", gen_float(r))
        if k == "RECORD":
            lay = self.chk.types.layout(tt[0], tt[1])
            tmp = self.heap.get(("retval", repr(st.key), n), "out", lay, count=1)
            img = self.heap.image(tmp, b)
            return ("int", int.from_bytes(bytes(img[:lay.size(b)]).ljust(8, b"\0"), "little"))
        nb = tc.get_size()
        signed = INT_KINDS.get(k, k == "ENUM")
        if k == "BOOL":
            v = r.below(2)
        else:
            v = gen_int(r, min(nb, 4), signed)
            if signed and v >= 1 << (8 * min(nb, 4) - 1):
                v -= 1 << (8 * min(nb, 4))
            if nb == 8 and k in ("LONGLONG", "ULONGLONG") and tt[0].get_canonical().get_size() == 8:
                v = r.next()
        return ("int", v & ((1 << (8 * nb)) - 1))

    def _ret(self, sp, retaddr, pop, rv, sig):
        b, uc = self.bits, self.uc
        if b == 32:
            eip = retaddr
            if rv is not None and rv[0] in ("f", "d"):
                uc.mem_write(FSLOT, struct.pack("<f" if rv[0] == "f" else "<d", rv[1]))
                eip = SENTINEL + (0x20 if rv[0] == "f" else 0x30)
                # the thunk's `ret` pops the return address: leave it at the new top
                newsp = sp + pop
                uc.mem_write(newsp, struct.pack("<I", retaddr))
                uc.reg_write(X.UC_X86_REG_ESP, newsp)
                uc.reg_write(X.UC_X86_REG_EIP, eip)
                return
            if rv is not None:
                v = rv[1] & M64
                uc.reg_write(X.UC_X86_REG_EAX, v & M32)
                uc.reg_write(X.UC_X86_REG_EDX, (v >> 32) & M32)
            uc.reg_write(X.UC_X86_REG_ESP, sp + 4 + pop)
            uc.reg_write(X.UC_X86_REG_EIP, eip)
            return
        if rv is not None:
            if rv[0] == "f":
                uc.reg_write(X.UC_X86_REG_XMM0, struct.unpack("<I", struct.pack("<f", rv[1]))[0])
            elif rv[0] == "d":
                uc.reg_write(X.UC_X86_REG_XMM0, struct.unpack("<Q", struct.pack("<d", rv[1]))[0])
            else:
                uc.reg_write(X.UC_X86_REG_RAX, rv[1] & M64)
        uc.reg_write(X.UC_X86_REG_RSP, sp + 8)
        uc.reg_write(X.UC_X86_REG_RIP, retaddr)

    def int_args(self, sp, n, sizes=None):
        """The first N integer arguments of a C call (cdecl on i386, Win64 on x64)."""
        out = []
        for i in range(n):
            if self.bits == 32:
                out.append(self.read_int(sp + 4 + 4 * i, 4))
            elif i < 4:
                out.append(self.reg(ARGREGS64[i]))
            else:
                out.append(self.read_int(sp + 8 + 8 * i, 8))
        return out

    def cstr(self, a, limit=0x10000, wide=False):
        out = bytearray()
        step = 2 if wide else 1
        while len(out) < limit:
            c = self.read(a + len(out), step)
            if c == b"\0" * step:
                break
            out += c
        return bytes(out)

    def crt(self, name, sp, retaddr):
        """The C runtime's memory and string routines, executed on this side's memory."""
        b = self.bits
        if name in ("memcpy", "memmove"):
            d, s, n = self.int_args(sp, 3)
            n &= (1 << (8 * self.ps)) - 1
            if n > 0x100000:
                raise Unsupported("memcpy of %d bytes" % n)
            self.write(d, self.read(s, n)) if n else None
            rv = d
        elif name == "memset":
            d, c, n = self.int_args(sp, 3)
            if n > 0x100000:
                raise Unsupported("memset of %d bytes" % n)
            self.write(d, bytes([c & 0xFF]) * n) if n else None
            rv = d
        elif name == "memcmp":
            a, c, n = self.int_args(sp, 3)
            x, y = self.read(a, n), self.read(c, n)
            rv = (x > y) - (x < y)
        elif name in ("strlen", "wcslen"):
            a, = self.int_args(sp, 1)
            rv = len(self.cstr(a, wide=name == "wcslen")) // (2 if name == "wcslen" else 1)
        elif name in ("strcmp", "stricmp", "strncmp", "strnicmp"):
            a, c = self.int_args(sp, 2)
            lim = self.int_args(sp, 3)[2] if "n" in name[3:] else 0x10000
            x, y = self.cstr(a, lim), self.cstr(c, lim)
            if "i" in name.replace("strin", "stri")[3:]:
                x, y = x.lower(), y.lower()
            rv = (x > y) - (x < y)
            rv &= M64
        elif name in ("strcpy", "strcat"):
            d, s = self.int_args(sp, 2)
            data = self.cstr(s) + b"\0"
            at = d + (len(self.cstr(d)) if name == "strcat" else 0)
            self.write(at, data)
            rv = d
        elif name == "strncpy":
            d, s, n = self.int_args(sp, 3)
            data = self.cstr(s, n)
            self.write(d, (data + bytes(n))[:n])
            rv = d
        elif name == "strchr":
            a, c = self.int_args(sp, 2)
            s = self.cstr(a)
            i = s.find(bytes([c & 0xFF])) if c & 0xFF else len(s)
            rv = a + i if i >= 0 else 0
        else:
            raise Unsupported("crt " + name)
        self.events.append(("crt", name))
        return self._ret(sp, retaddr, 0, ("int", rv & M64), None)

    def helper386(self, name, sp, retaddr):
        """i386 64-bit integer helpers (clang's runtime calls on i686-windows): pure functions of their stack words."""
        n = name.lstrip("_")
        uc = self.uc
        if n in ("allshl", "allshr", "aullshr"):
            v = self.reg(X.UC_X86_REG_EAX) | (self.reg(X.UC_X86_REG_EDX) << 32)
            c = self.reg(X.UC_X86_REG_CL) & 63
            if n == "allshl":
                v = (v << c) & M64
            elif n == "aullshr":
                v >>= c
            else:
                sv = v - (1 << 64) if v >> 63 else v
                v = (sv >> c) & M64
            uc.reg_write(X.UC_X86_REG_EAX, v & M32)
            uc.reg_write(X.UC_X86_REG_EDX, v >> 32)
            uc.reg_write(X.UC_X86_REG_ESP, sp + 4)
            uc.reg_write(X.UC_X86_REG_EIP, retaddr)
            return
        a = self.read_int(sp + 4, 8)
        c = self.read_int(sp + 12, 8)

        def s(x):
            return x - (1 << 64) if x >> 63 else x
        if n == "allmul":
            v = (a * c) & M64
        elif n in ("alldiv", "allrem"):
            if s(c) == 0:
                self.stop = ("crash", "division by zero")
                raise Stop()
            q = abs(s(a)) // abs(s(c))
            if (s(a) < 0) != (s(c) < 0):
                q = -q
            v = (q if n == "alldiv" else s(a) - q * s(c)) & M64
        elif n in ("aulldiv", "aullrem"):
            if c == 0:
                self.stop = ("crash", "division by zero")
                raise Stop()
            v = a // c if n == "aulldiv" else a % c
        else:
            raise Unsupported("helper " + name)
        uc.reg_write(X.UC_X86_REG_EAX, v & M32)
        uc.reg_write(X.UC_X86_REG_EDX, v >> 32)
        uc.reg_write(X.UC_X86_REG_ESP, sp + 4 + 16)
        uc.reg_write(X.UC_X86_REG_EIP, retaddr)

    def allocator(self, st, n, sp, retaddr):
        """operator new / malloc / the game's allocators: a fresh raw object of the requested size (each side's)."""
        b = self.bits
        sig = st.sig
        at = None
        for bits_, nm in st.names.items():
            nm = untree(nm)
            at = allocator_at(nm, c_name(nm, bits_))
            if at is not None:
                break
        # (integ2, D107 follow-up (a); rev5) the size parameter at its declared width on this side (a size_t /
        # hulk_uintptr is 8 bytes on x86-64: its upper half is part of the request), the pointer width without a
        # declaration
        w_ = self.ps
        if isinstance(sig, Sig) and sig.params:
            i_ = at or 0
            if i_ < len(sig.params):
                try:
                    w_ = max(1, min(self.ps, sig.params[i_][0 if b == 32 else 1].get_canonical().get_size()))
                except Exception:   # noqa: BLE001
                    w_ = self.ps
        if isinstance(sig, Sig) and (sig.has_this and sig.params or at is not None):
            kinds, locs, _ = self.arg_locs(sig, False)
            loc = [lc for (k, _t), lc in zip(kinds, locs) if k == "param"][at or 0]
            size = int.from_bytes(self.read_loc(loc, w_, sp), "little")
        else:
            size = self.int_args(sp, 1)[0] if self.bits == 64 or sig is None or sig.cc32 != CC_THIS else 0
        if b == 32 and sig is not None and sig.cc32 in (CC_FAST,):
            size = self.reg(X.UC_X86_REG_ECX)
        size &= (1 << (8 * w_)) - 1
        if b == 32 and size > ALLOC_MAX:
            # a size from a fuzzed count (`count * 4` of an unchecked count): no game state asks for this much
            self.stop = ("wild", "32-bit allocation of 0x%x bytes" % size)
            raise Stop()
        ident = ("new", repr(st.key), n)
        o = self.heap.by_ident.get(ident)
        s32_ = o.alloc[0] if o is not None and o.alloc else 0
        if b == 64 and (size > ALLOC_MAX or size > 4 * s32_ + 0x100) and "alloc64" not in OFF:
            # (integ2, D107 follow-up (b); rev5) the 64-bit side's request, bounded as the 32-bit one is: past
            # ALLOC_MAX, or more than four times the 32-bit request plus 0x100 (pointers double a record; padding
            # doesn't make it four times), the native size computation is wrong: a gating layout difference, not a skip.
            # An allocation only the 64-bit run makes (no 32-bit request: s32_ 0) gets the 0x100 bound and is labelled
            # layout too; it is a real difference anyway (the runs' call events differ)
            self.stop = ("alloc64", "allocation of 0x%x bytes where the 32-bit run asked for 0x%x" % (size, s32_))
            raise Stop()
        if o is None:
            o = self.heap.get(ident, "alloc", RAW, alloc=(size, size))
            # (ptr1) the source casts the allocator's result: an array of that type (a later vftable or a larger
            # type it is passed as still wins)
            cast = self.chk.ret_casts.get(st.key)
            if st.key in self.chk.site_casts:
                # (x64t9, sitecasts) the cast of this call site, found by the call's place among the function's calls
                # of the callee (each side's code, in address order; clang emits them in source order)
                i = self.chk.call_site_index(b, st, retaddr)
                sc = self.chk.site_casts[st.key]
                cast = sc[i] if i is not None and i < len(sc) else None
            if cast is not None and o.hint is None:
                try:
                    lay = self.chk.types.layout(*cast)
                    if not lay.raw:
                        o.hint = lay
                except Unsupported:
                    pass
            reg_ = None
            if st.key in getattr(self.chk, "site_regions", {}):
                i_ = self.chk.call_site_index(b, st, retaddr, self.chk.site_regions)
                reg_ = self.chk.site_regions[st.key][i_] if i_ is not None else None
            if reg_ is not None and "allocty" not in OFF:
                # (integ3, allocty regions) the cast at an offset types the allocation from there: `count` records of T
                # (an `n * sizeof(T) + c` request: as many as the 32-bit request holds past the offset), else one; the
                # bytes before it keep their raw image (written before read: the cookie)
                off32_, off64_, tt_, arr_ = reg_
                try:
                    el_ = self.chk.types.layout(*tt_)
                except Unsupported:
                    el_ = None
                if el_ is not None and not el_.raw:
                    k_ = (size - off32_) // max(1, el_.size32) if arr_ else 1
                    k_ = max(0, min(k_, KMAX))
                    if k_:
                        o.ahint = region_layout(off32_, off64_, el_, k_)
                        o.ahint.__dict__.setdefault("key32_spelling", None)
                        o.hint = o.ahint    # (the region, not the prefix's cast type, says where the words are)
            if reg_ is None and "allocty" not in OFF:
                # (integ3, allocty) the record the allocation is returned as: the cast's, else the declared pointer's
                at_ = cast
                if at_ is None and isinstance(sig, Sig):
                    p32, p64 = sig.ret[0].get_canonical(), sig.ret[1].get_canonical()
                    if p32.kind.name == "POINTER" and p64.kind.name == "POINTER":
                        at_ = (p32.get_pointee(), p64.get_pointee())
                if at_ is not None and is_record(at_[0]) and is_record(at_[1]):
                    try:
                        lay_ = self.chk.types.layout(*at_)
                        if not lay_.raw:
                            o.ahint = lay_
                            o.ahint.__dict__.setdefault("key32_spelling", at_[0].get_canonical().spelling)
                    except Unsupported:
                        pass
        if o.ahint is not None and "allocty" not in OFF:
            # (integ3, allocty; rev5 R1) the records the allocation holds, decided once from the first (32-bit) request and
            # held to on the other side: a 64-bit request with room for fewer of them (a hard-coded 32-bit size or
            # stride) is the native size computation's error, a gating layout difference, never a raw 64-bit side
            # (rev5 R2') more than element 0 only where the call site's size is `n * sizeof(T)` for this record T (then
            # n64 == k * size64 by construction); a header and its payload (`sizeof(Hdr) + len`) or a hard-coded size
            # types the header alone, the rest stays raw, the same byte for byte on both sides
            k_ = size // max(1, o.ahint.size(b))
            if b == 32 or not o.alloc or not o.alloc[0]:
                arr_ = False
                i_ = self.chk.call_site_index(b, st, retaddr, self.chk.site_arrays) if st.key in self.chk.site_arrays else None
                if i_ is not None:
                    t_ = self.chk.site_arrays[st.key][i_]
                    arr_ = t_ is not None and t_ == o.ahint.key32_spelling
                o.ak = min(k_, KMAX) if arr_ else min(k_, 1)
                if o.ak and o.hint is None:
                    o.hint = o.ahint    # (rev5 R2) a pointer to element e (`slots + 1`) translates by the record's size
            elif o.ak and k_ < 1:
                # (rev5 R1) the declared record allocated short natively: the 32-bit request holds one, the 64-bit none
                self.stop = ("alloc64", "allocation of 0x%x bytes holds %d %s where the 32-bit run's holds %d" % (
                    size, k_, o.ahint.key, o.ak))
                raise Stop()
        if b == 64 and o.alloc[1] != size or b == 32 and o.alloc[0] != size:
            o.alloc = (o.alloc[0], size) if b == 64 else (size, o.alloc[1])
            o.size64 = max(1, o.alloc[1])
            o.size32 = max(1, o.alloc[0])
            if size > o.res.get(b, 0) and "regrow" not in OFF:
                # (integ2, D107) the region was reserved at the other side's (first run's) size
                self.heap.regrow(o, b, size, self.mapped)
        self.events.append(("new", repr(st.key)))
        pop = 0
        if b == 32 and sig is not None:
            pop = self.arg_locs(sig, False)[2]
        return self._ret(sp, retaddr, pop, ("int", o.base(b)), None)

    def dyncast(self, st, n, sp, retaddr):
        b = self.bits
        args = self.int_args(sp, 5)
        p = args[0]
        r = Rng(self.seed, "dyncast", n)
        rv = p if (p and r.below(3)) else 0
        self.events.append(("call", "__RTDynamicCast", (self.canon_ptr(p), self.canon_ptr(args[2]), self.canon_ptr(args[3]))))
        return self._ret(sp, retaddr, 0, ("int", rv), None)


# ------------------------------------------------------------------------------------------------- comparison
def written_locations(side):
    """Target-independent keys of everything SIDE wrote outside its stack: {key: (addr, leaf or None, size)}."""
    out = {}
    b = side.bits
    h = side.heap
    seen = set()
    for a, n in side.writes:
        for x in range(a, a + n):
            if x in seen:
                continue
            seen.add(x)
            if STACK_LO <= x < STACK_HI or TIB32 <= x < TIB32 + PAGE or GDT32 <= x < GDT32 + PAGE:
                continue
            o, off = h.find(b, x)
            if o is not None:
                if o.kind in ("argcopy", "out"):
                    continue
                lay = o.hint if (o.hint is not None and o.lay.raw) else o.lay
                if o.kind == "alloc" and off >= o.size(b):
                    out[("past", o.id, b, off)] = (x, None, 1)
                    continue
                if lay.raw:
                    lim = o.size(b)
                    if off >= lim:
                        out[("past", o.id, b, off)] = (x, None, 1)
                    else:
                        out[("raw", o.id, off)] = (x, None, 1)
                    continue
                es = lay.size(b)
                e, r = divmod(off, es)
                count = o.count if not o.lay.raw else max(1, o.size(b) // es)
                if e >= count and o.kind != "alloc":
                    out[("past", o.id, b, off)] = (x, None, 1)
                    continue
                l = lay.leaf_at(b, r)
                if l is None:
                    continue
                if l.kind == "b":
                    out[("rawleaf", o.id, e, l.path, l.o32 + (r - l.off(b)) if False else r - l.off(b))] = (x, None, 1)
                    continue
                out[("leaf", o.id, e, l.path)] = (o.base(b) + e * es + l.off(b), l, l.size(b))
                continue
            if CODE <= x < side.code_end:
                name, so = side.chk.img[b].sym_at(x)
                out[("sym", side.chk.canon_name(name, b) if name else "?", so)] = (x, None, 1)
                continue
            out[("wild", x)] = (x, None, 1)
    return out


def location_addr(side, key):
    """The address of a location key on SIDE (for reading the other side's final value)."""
    b = side.bits
    h = side.heap
    kind = key[0]
    if kind == "leaf":
        o = h.objs[key[1]]
        lay = o.hint if (o.hint is not None and o.lay.raw) else o.lay
        for l in lay.leaves:
            if l.path == key[3]:
                return o.base(b) + key[2] * lay.size(b) + l.off(b), l
        return None, None
    if kind == "raw":
        o = h.objs[key[1]]
        return o.base(b) + key[2], None
    if kind == "rawleaf":
        o = h.objs[key[1]]
        lay = o.hint if (o.hint is not None and o.lay.raw) else o.lay
        for l in lay.leaves:
            if l.path == key[3]:
                return o.base(b) + key[2] * lay.size(b) + l.off(b) + key[4], None
        return None, None
    if kind == "wild":
        return key[1], None
    if kind == "sym":
        img = side.chk.img[b]
        for n_, a_ in img.defined.items():
            if side.chk.canon_name(n_, b) == key[1]:
                return a_ + key[2], None
        return None, None
    return None, None


VT_NAME = re.compile(r"^\?\?_7(.+?)@@6B")


def retypable(o):
    """Untyped memory a run got from an allocator or as a void* / char* stub result: typed after the run by what
    the code did with it (the vftable it stored at +0, the largest type it was passed as)."""
    return o.lay.raw and o.kind in ("alloc", "heap") and o.init is None


def vftable_class(name):
    """`??_7Inner@Outer@@6B@` -> `Outer::Inner`; a template's (`??_7?$T@VA@@@ns@@6B@`) -> `ns::T<A>` (llvm-undname)."""
    m = VT_NAME.match(name or "")
    if not m:
        return None
    if "?" in m.group(1) or "$" in m.group(1):
        return undname_class(name)
    return "::".join(reversed(m.group(1).split("@")))


_UNDNAME = {}


def undname_class(name):
    """A template class's vftable symbol -> its canonical spelling without spaces (`fight::ParamList<CFoo>`)."""
    if name not in _UNDNAME:
        r = None
        try:
            out = subprocess.run([cp.tool("llvm-undname"), name], capture_output=True, text=True, timeout=20).stdout
            line = [x for x in out.splitlines() if "`vftable'" in x]
            if line:
                t = line[0].strip()
                t = re.sub(r"^const ", "", t)
                t = re.sub(r"::`vftable'.*$", "", t)
                t = re.sub(r"\b(class|struct|union|enum) ", "", t)
                r = t.replace(" ", "")
        except Exception:   # noqa: BLE001
            r = None
        _UNDNAME[name] = r
    return _UNDNAME[name]


def type_allocations(chk, heap, s32):
    """Allocations nobody passed as a typed pointer get the class whose vftable the 32-bit run stored at +0."""
    for o in heap.objs:
        if not retypable(o) or o.size32 < 4:
            continue
        if o.a32 & ~(PAGE - 1) not in s32.mapped:
            continue
        v = int.from_bytes(s32.read(o.a32, 4), "little")
        cls = None
        if CODE <= v < s32.code_end:
            name, off = chk.img[32].sym_at(v)
            if off == 0:
                cls = vftable_class(name)
        else:
            t, _ = heap.find(32, v)
            if t is not None and t.ident[0] == "vt":
                cls = t.ident[1][0]
        if cls:
            r32, r64 = chk.tu[32].record(cls), chk.tu[64].record(cls)
            if r32 is not None and r64 is not None:
                try:
                    lay = chk.types.layout(r32.type, r64.type)
                except Unsupported:
                    continue
                if not lay.raw:
                    o.hint = lay


def normalize(v, heap):
    """Pointers into allocations, recorded as (alloc, id, side offset, bits), as 32-bit offsets of their type."""
    if isinstance(v, tuple):
        if len(v) == 4 and v[0] == "alloc":
            o = heap.objs[v[1]]
            off, bits = v[2], v[3]
            if bits == 32 or off == 0:
                return ("obj", v[1], off)
            lay = o.hint
            if lay is None:
                return ("obj", v[1], off)          # (untyped: byte for byte the same on both sides)
            if lay.key.startswith("region<") and off >= lay.size64 and "regiontail" not in OFF:
                return ("obj", v[1], off - lay.size64 + lay.size32)     # (integ4) a region's raw tail
            t = lay.to32(off)
            return ("obj", v[1], t if t is not None else ("in64", off))
        return tuple(normalize(x, heap) for x in v)
    if isinstance(v, list):
        return [normalize(x, heap) for x in v]
    return v


def compare(chk, heap, r32, r64):
    """(first difference text, class) or (None, None)."""
    s32, s64 = r32["side"], r64["side"]
    type_allocations(chk, heap, s32)
    for k in ("events", "ret"):
        for r in (r32, r64):
            if k in r:
                r[k] = normalize(r[k], heap)
    if r64.get("stop"):
        st = r64["stop"]
        cls = {"crash": "crash64", "hang": "hang64", "tool": "tool", "alloc64": "layout"}.get(st[0], "tool")
        if st[0] in ("tool", "view_straddle"):
            return "64-bit run: %s" % st[1], st[0]
        return "64-bit run %s: %s (the 32-bit run returned)" % (st[0], st[1]), cls
    for o in heap.objs:
        if o.kind == "alloc" and o.hint is not None and o.alloc and o.alloc[0] >= o.hint.size32 and o.alloc[1] < o.hint.size64:
            return "allocation of 0x%x bytes holds a %s: 0x%x bytes on 32-bit, 0x%x on 64-bit" % (
                o.alloc[1], o.hint.key, o.hint.size32, o.hint.size64), "layout"
    w32, w64 = written_locations(s32), written_locations(s64)
    for key in list(w64):
        if key[0] == "past":
            o = heap.objs[key[1]]
            return "64-bit write past the end of %s (+0x%x, 64-bit size 0x%x, 32-bit size 0x%x)" % (
                describe(o), key[3], o.size64, o.size32), "layout"
    if r64.get("oob"):
        return "64-bit read past the end of %s (+0x%x); the 32-bit run stays inside" % r64["oob"], "layout"
    e32, e64 = r32["events"], r64["events"]
    for i in range(max(len(e32), len(e64))):
        a = e32[i] if i < len(e32) else None
        b = e64[i] if i < len(e64) else None
        if a != b:
            return ptrnote(s64, "event %d: 32-bit %s, 64-bit %s" % (i, short(a), short(b)), classify(a, b, s64))
    if r32.get("ret") != r64.get("ret"):
        return ptrnote(s64, "return: 32-bit %s, 64-bit %s" % (short(r32.get("ret")), short(r64.get("ret"))),
                       classify(r32.get("ret"), r64.get("ret"), s64))
    for k in ("stack", "saved"):
        if r64.get(k) and not r32.get(k):
            return "64-bit: " + r64[k], "tool" if k == "saved" else "call"
    for key in list(w32):
        if key[0] == "past":
            del w32[key]
    keys = sorted(set(w32) | set(w64), key=repr)
    for key in keys:
        a32, l32 = (w32[key][0], w32[key][1]) if key in w32 else location_addr(s32, key)
        a64, l64 = (w64[key][0], w64[key][1]) if key in w64 else location_addr(s64, key)
        if a32 is None or a64 is None:
            return "write to %s on one side only" % (key,), "layout"
        if l32 is not None:
            l64_ = l64 or l32
            if "rawint" not in OFF and l32.kind not in ("p", "fp", "vp", "mfp") and l32.size(32) == l64_.size(64) and \
                    s32.read(a32, l32.size(32)) == s64.read(a64, l64_.size(64)):
                # (x64eq, rawint) an integer leaf with the same bits on both sides is the same integer, even when on one
                # side its value happens to be an address inside an object (an allocation's untouched bytes beside a
                # byte field, 0x2345eb01 in a 32-bit heap object): a pointer kept in an integer has different bits on
                # the two targets (the 64-bit heap is above 4 GB)
                continue
            v32 = s32.decode_leaf(a32, l32)
            v64 = s64.decode_leaf(a64, l64_)
        else:
            v32, v64 = s32.read(a32, 1), s64.read(a64, 1)
        v32, v64 = normalize(v32, heap), normalize(v64, heap)
        if v32 != v64:
            o = heap.objs[key[1]] if key[0] in ("leaf", "raw", "rawleaf") else None
            cls = classify(v32, v64, s64)
            if (key in w32) != (key in w64) and cls in ("int", "call"):
                cls = "layout"      # (only one side wrote it: the other side's store went to another offset)
            if key[0] in ("raw", "rawleaf") and cls not in ("float",):
                cls = "untyped"
            if l32 is not None and l32.kind in ("p", "fp", "vp", "mfp") and "ptrstore" not in OFF and a64 is not None:
                # (integ3, rev5 Q1) ptrpart for writes: a differing pointer field the 64-bit run stored into only in part
                # (a store not at the leaf's 64-bit offset, or narrower than the pointer: a 32-bit stride or offset
                # landing inside it) is the native layout's error, whatever the value it left
                w_ = (l64 or l32).size(64)
                if any(a_ < a64 + w_ and a_ + n_ > a64 and not (a_ == a64 and n_ >= w_) for a_, n_ in s64.writes):
                    cls = "layout"
            return ptrnote(s64, "memory %s%s: 32-bit %s, 64-bit %s" % (describe(o) + " " if o else "", fmt_key(key), short(v32),
                                                                      short(v64)), cls)
    return None, None


def ptrnote(s64, text, cls):
    """A difference after the 64-bit run read part of a pointer field (a 4-byte access the 64-bit layout puts
    inside an 8-byte pointer: a raw offset or a pointer kept in an int) is a layout difference."""
    if s64.ptrpart:
        return text + " (after: %s)" % s64.ptrpart, "layout"
    if s64.rawread and cls in ("int", "call"):
        return text + " (after: %s)" % s64.rawread, "untyped"
    return text, cls


def describe(o):
    if o is None:
        return ""
    return "%s#%d(%s)" % (o.kind, o.id, o.lay.key if not o.lay.raw else (o.hint.key if o.hint else "raw"))


def fmt_key(k):
    if k[0] == "leaf":
        return "[%d].%s" % (k[2], ".".join(str(p) for p in k[3]))
    return repr(k)


def short(v, n=200):
    s = repr(v)
    return s if len(s) <= n else s[:n] + "..."


def _floats_only_differ(a, b):
    """True when A and B have the same shape and differ only in float/double components."""
    if isinstance(a, tuple) and isinstance(b, tuple):
        if a[:1] in (("f",), ("d",)) and b[:1] == a[:1]:
            return True
        if len(a) != len(b):
            return False
        return all(x == y or _floats_only_differ(x, y) for x, y in zip(a, b))
    if isinstance(a, list) and isinstance(b, list):
        return len(a) == len(b) and all(x == y or _floats_only_differ(x, y) for x, y in zip(a, b))
    return False


def _ints_wrap(a, b):
    """A and B differ, and every differing pair of integers is equal modulo 2^32 (one of them 64-bit)."""
    if isinstance(a, tuple) and isinstance(b, tuple):
        if len(a) == 2 and len(b) == 2 and a[0] == b[0] == "i" and isinstance(a[1], int) and isinstance(b[1], int):
            return a[1] != b[1] and (a[1] - b[1]) % (1 << 32) == 0
        if len(a) != len(b):
            return False
        pairs = [(x, y) for x, y in zip(a, b) if x != y]
        return bool(pairs) and all(_ints_wrap(x, y) for x, y in pairs)
    if isinstance(a, list) and isinstance(b, list):
        pairs = [(x, y) for x, y in zip(a, b) if x != y]
        return len(a) == len(b) and bool(pairs) and all(_ints_wrap(x, y) for x, y in pairs)
    return False


def classify(a, b, s64):
    def has(v, pred):
        if isinstance(v, tuple):
            if pred(v):
                return True
            return any(has(x, pred) for x in v)
        return False
    if has(b, lambda t: len(t) >= 3 and t[0] == "obj" and isinstance(t[2], tuple)):
        return "layout"

    def ptrtrunc(t):
        return len(t) == 2 and t[0] in ("int", "i") and isinstance(t[1], int) and 0 <= t[1] <= M32 and any(
            (o.a64 & M32) <= (t[1] & M32) < (o.a64 & M32) + PAGE * 4 for o in s64.heap.objs if o.a64 >= 1 << 32)
    objs_a = set()
    has(a, lambda t: objs_a.add((t[1], t[2])) if len(t) == 3 and t[0] == "obj" else False)
    if has(b, lambda t: len(t) == 3 and t[0] == "obj" and (t[1], t[2]) not in objs_a and
           any(x[0] == t[1] for x in objs_a)):
        return "layout"     # the same object at another offset: a byte offset that is the 32-bit layout's
    if "wild64" not in OFF and isinstance(a, tuple) and isinstance(b, tuple) and b[:1] == ("wildptr",) and \
            a[:1] in (("obj",), ("null",), ("nullrel",), ("stack",)):
        # (x64eq) a pointer the 64-bit run computes outside every object where the 32-bit one lands in one: pointer
        # arithmetic with an index that wraps at 2^32 on i386 only (a fuzzed count, or an unsigned "negative" step)
        return "wild64"
    if has(b, lambda t: t[:1] == ("trunc",)) or has(b, ptrtrunc) or (isinstance(a, tuple) and isinstance(b, tuple) and a[:1] in (("obj",), ("alloc",))
                            and b[:1] in (("i",), ("int",))):
        return "ptrtrunc"
    if has(a, lambda t: len(t) > 1 and t[0] in ("f", "d")) or has(b, lambda t: len(t) > 1 and t[0] in ("f", "d")):
        if not has(a, lambda t: t[:1] in (("obj",), ("i",), ("int",))) or _floats_only_differ(a, b):
            return "float"
    if _ints_wrap(a, b):
        return "intwidth"   # equal modulo 2^32: pointer-width integer arithmetic wraps at 2^32 on one side only
    if "wild" in s64.flags and not has(a, lambda t: t[0] == "int"):
        return "untyped"
    if isinstance(a, tuple) and isinstance(b, tuple) and a and b and a[0] == "call" and b[0] == "call" and a[1] != b[1]:
        return "call"
    if a is None or b is None or (isinstance(a, tuple) and isinstance(b, tuple) and a[:1] != b[:1]):
        return "call"
    return "int"


# ------------------------------------------------------------------------------------------------- driver
def verify64(src, addr, symbol=None, n_inputs=200, seeds=None, time_budget=120, verbose=False):
    import tree_tu
    if src and tree_tu.is_tree_tu(src):
        # (merge-once) a tree TU: its whole text is the source; the function at ADDR is the one the tree's rules name
        # (tools/tree_tu.py), the tree's include/ is on every compile's path
        with tree_tu.active(src):
            try:
                recs = tree_tu.check_tu(src)
            except Exception as e:      # noqa: BLE001
                return {"addr": "0x%08x" % addr, "src": src, "mode": "x64", "status": "compile_error", "error": repr(e)[:300]}
            r_ = next((x for x in recs if int(x["addr"], 16) == addr), None)
            if r_ is None:
                return {"addr": "0x%08x" % addr, "src": src, "mode": "x64", "status": "no_function",
                        "error": "%s has no block for 0x%08x" % (src, addr)}
            symbol = symbol or r_.get("symbol")
            if "treeext" not in OFF:
                TREE_EXTERNAL.clear()
                TREE_EXTERNAL.update(x["symbol"] for x in recs
                                     if x.get("symbol") and int(x["addr"], 16) != addr and x["symbol"] != symbol)
            TREE_ACTIVE.append(addr)
            TREE_PINNED.clear()
            try:
                for l in tree_tu.block_lines(src, addr):
                    m = PIN_VIEW.match(l)
                    if m:
                        TREE_PINNED.add(m.group(1))
            except Exception:   # noqa: BLE001
                TREE_PINNED.clear()
            try:
                return _verify64(src, addr, symbol, n_inputs, seeds, time_budget, verbose)
            finally:
                TREE_PINNED.clear()
                TREE_ACTIVE.pop()
                TREE_EXTERNAL.clear()
    return _verify64(src, addr, symbol, n_inputs, seeds, time_budget, verbose)


def _verify64(src, addr, symbol=None, n_inputs=200, seeds=None, time_budget=120, verbose=False):
    t0 = time.time()
    rep = {"addr": "0x%08x" % addr, "src": src, "mode": "x64", "status": "fail"}
    import equiv as eq_
    if OFF - {""} or eq_.work_knobs_set():
        # (integ1, rev5) a run with EQ64_OFF switches is another check: tools/x64_gate.py takes it for no result
        # (integ3, rev5 2: so is one with a budget knob set, EQ64_WORK_PER_SEC / EQ64_RUN_SECONDS / EQUIV_WALL_CAP)
        rep["eq64_off"] = sorted(OFF - {""}) + eq_.work_knobs_set()
    try:
        chk = Checker(src, addr, symbol, verbose)
    except CompileError as e:
        rep.update(status="compile_error", error=str(e)[-1500:], time=round(time.time() - t0, 2))
        return rep
    except Unsupported as e:
        rep.update(status="unsupported", error="[tool] " + str(e), **{"class": "tool"}, time=round(time.time() - t0, 2))
        return rep
    rep["symbol32"], rep["symbol64"] = chk.sym32, chk.sym64
    try:
        res = chk.run(n_inputs, seeds, time_budget)
    except Unsupported as e:
        cls_ = getattr(e, "cls", "tool")
        rep.update(status="unsupported", error="[%s] %s" % (cls_, e), **{"class": cls_}, time=round(time.time() - t0, 2))
        rep["types"] = chk.types.fingerprints()
        rep["ast"] = getattr(chk, "ast_digest", None)
        return rep
    rep["types"] = chk.types.fingerprints()     # (x64t12) the layouts the verdict rests on (tools/x64_gate.py's cache)
    # (integ1, rev5/D61) the input annotations the run used: a verdict that rests on them says so
    if chk.types.ranges_used:
        rep["hulk_range"] = sorted(["%s::%s" % k, list(v)] for k, v in chk.types.ranges_used.items())
    if getattr(chk, "param_into", None):
        rep["hulk_into"] = {str(k): v for k, v in sorted(chk.param_into.items())}
    if getattr(chk, "param_range", None):
        rep["hulk_range_params"] = {str(k): list(v) for k, v in sorted(chk.param_range.items())}
    if getattr(chk, "gdata_used", None):
        rep["hulk_data"] = {k: v for k, v in sorted(chk.gdata_used.items())}
    if getattr(chk, "gcasts_used", None):
        rep["global_casts"] = {k: v for k, v in sorted(chk.gcasts_used.items())}
    rep["inputs"], rep["completed"], rep["skipped"] = res["inputs"], res["completed"], res["skipped"]
    rep["work"], rep["cpu"], rep["workn"] = res.get("work"), res.get("cpu"), res.get("workn")
    rep["input_digest"] = res.get("input_digest")
    if res.get("time_cut_wall"):
        rep["time_cut_wall"] = True
    if res.get("skip_first"):
        rep["skip_first"] = res["skip_first"]
    if chk.range32:
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        lo, hi = chk.range32
        code = bytes(chk.img[32].build(lambda n: 0)[lo - CODE:hi - CODE])
        insns = [i.address for i in md.disasm(code, lo)]
        hit = sum(1 for a in insns if any(b <= a < b + n for b, n in res["cov"]))
        rep["coverage"] = "%d/%d" % (hit, len(insns))
    rep["classes"] = res["classes"]
    if res.get("allocty"):
        rep["allocty"] = res["allocty"]     # (integ3) inputs that drew an allocation's bytes as its record
    if res["fails"]:
        rep["status"] = "fail"
        rep["class"] = res["fails"][0]["class"]
        rep["diff"] = res["fails"][0]["diff"]
        rep["seed"] = res["fails"][0]["seed"]
        rep["fails"] = res["fails"]
    elif res.get("time_cut_wall"):
        # (integ3, workclock) the CPU safety cap cut the run before its work budget: how far it got is the host's speed
        rep["status"] = "unsupported"
        rep["class"] = "time_cut_wall"
        rep["error"] = "[time_cut_wall] the CPU safety cap cut the run before its work budget: rerun with a bigger --time-budget"
    elif res["completed"] == 0:
        rep["status"] = "unsupported"
        first = res.get("skip_first") or {}
        stub = res["skipped"].get("oob", 0) >= res["inputs"] // 2 and "write past" in (first.get("oob") or "")
        rep["class"] = "stubsize" if stub else "tool"
        rep["error"] = "[%s] no input completed on the 32-bit side (%s; first: %s)" % (rep["class"], res["skipped"], res.get("skip_first"))
    elif res["completed"] < 8:
        rep["status"] = "inconclusive"
    else:
        rep["status"] = "equivalent"
    dom_ = res["skipped"].get("pre_empty", 0) + res["skipped"].get("count_cap", 0)
    if dom_ and rep["status"] in ("equivalent", "inconclusive") and 2 * dom_ >= res["inputs"] and "predom" not in OFF:
        # (integ4, x64bounds; rev5) most inputs set aside by a contract's empty domain or a count past COUNT_MAX: what
        # was compared is too narrow a slice to stand for the block
        rep["status"] = "unsupported"
        rep["class"] = "pre_dominated"
        rep["error"] = "[pre_dominated] %d of %d inputs set aside (%s)" % (
            dom_, res["inputs"], {k: res["skipped"][k] for k in ("pre_empty", "count_cap") if res["skipped"].get(k)})
    if res["skipped"].get("view_straddle") and rep["status"] != "fail":
        # (integ2, D93; rev5's review) inputs whose object a straddling view would type were skipped: say so, never
        # pass on the others
        rep["status"] = "unsupported"
        rep["class"] = "view_straddle"
        rep["error"] = "[view_straddle] %d inputs: %s" % (res["skipped"]["view_straddle"],
                                                         (res.get("skip_first") or {}).get("view_straddle"))
    rep["ast"] = getattr(chk, "ast_digest", None)     # (integ2, D97) the parsed inputs the verdict rests on besides the bytes and layouts
    if chk.types.field_casts:
        rep["field_casts"] = sorted([list(k), [v[0] if isinstance(v[0], str) else v[0].spelling,
                                                v[1] if isinstance(v[1], str) else v[1].spelling]]
                                    for k, v in chk.types.field_casts.items())
    if chk.types.view_ambiguous and rep["status"] in ("equivalent", "inconclusive"):
        # (integ2, F5; rev5's re-review) the run read a field the code casts to several records (a tagged union): no one
        # view says what is there and the object kept its declared type, so the run earns no credit
        rep["view_ambiguous"] = sorted(chk.types.view_ambiguous)
        rep["status"] = "unsupported"
        rep["class"] = "view_ambiguous"
        rep["error"] = "[view_ambiguous] a field cast to several records was read: %s" % rep["view_ambiguous"][:3]
    if chk.types.view_trusted:
        # (integ2, D93; rev5's review) views over void / incomplete / placeholder pointees, taken on trust: any view
        # passes there (rev5's _wrongview), so an equivalent run is no clean --x64 equivalent (no proof credit, no
        # baseline removal); a difference found through it still stands
        rep["view_trusted"] = sorted(chk.types.view_trusted)
        if rep["status"] in ("equivalent", "inconclusive"):
            rep["view_trusted_status"] = rep["status"]
            rep["status"] = "unsupported"
            rep["class"] = "view_trusted"
            rep["error"] = "[view_trusted] %s with views taken on trust: %s" % (rep["view_trusted_status"],
                                                                           "; ".join(rep["view_trusted"])[:300])
    rep["time"] = round(time.time() - t0, 2)
    # (the fields tools/equiv_batch.py reads from a level-3 report: batches keep the class and the first difference)
    rep["level3"] = {"inputs_run": rep.get("completed"), "coverage": rep.get("coverage"), "statuses": rep.get("skipped"),
                     "mismatches": [{"input": f["seed"], "diffs": ["[%s] %s" % (f["class"], f["diff"])]}
                                    for f in rep.get("fails", [])]}
    chk.tmp.cleanup()
    return rep


def render(rep):
    lines = ["%s %s [x64] %s" % (rep["addr"], rep.get("symbol32", ""), rep["status"].upper())]
    if rep.get("error"):
        lines.append("  error: " + rep["error"])
    if "inputs" in rep:
        lines.append("  inputs %d, completed %d, skipped %s, coverage %s" % (rep["inputs"], rep["completed"], rep.get("skipped"),
                                                                           rep.get("coverage", "?")))
        for k, v in (rep.get("skip_first") or {}).items():
            lines.append("  first %s skip: %s" % (k, v))
    for f in rep.get("fails", []):
        lines.append("  seed %d [%s]: %s" % (f["seed"], f["class"], f["diff"]))
    lines.append("  time %.1fs" % rep.get("time", 0))
    return "\n".join(lines)


def batch(argv):
    """`equiv64.py batch LIST OUT.jsonl [--name ME] [--per N] [-- equiv.py args]`: tools/jobq_equiv.py with --x64,
    shipping libclang's Python binding with each job (job_files) for hosts whose venv lacks it."""
    import jobq
    import jobq_equiv
    extra = argv[argv.index("--") + 1:] if "--" in argv else []
    argv = argv[:argv.index("--")] if "--" in argv else argv
    p = argparse.ArgumentParser(prog="equiv64.py batch")
    p.add_argument("list")
    p.add_argument("out")
    p.add_argument("--name", default="eq64")
    p.add_argument("--per", type=int, default=4)
    a = p.parse_args(argv)
    orig = jobq.collect_files
    jobq.collect_files = lambda specs, dirty=False, **kw: {**orig(specs, dirty, **kw), **job_files()}
    items = [tuple(l.split()[:2]) for l in open(a.list) if l.strip()]
    res = jobq_equiv.run_items(a.name, items, a.out, ["--x64"] + (extra or ["--inputs", "200", "--time-budget", "60"]), per=a.per)
    print("%d results in %s" % (len(res), a.out))
    return 0 if len(res) == len(items) else 1


def main(argv):
    if argv[:1] == ["batch"]:
        return batch(argv[1:])
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("src")
    p.add_argument("addr")
    p.add_argument("--symbol")
    p.add_argument("--inputs", type=int, default=200)
    p.add_argument("--seeds")
    p.add_argument("--time-budget", type=float, default=120)
    p.add_argument("--json", action="store_true")
    p.add_argument("--verbose", action="store_true")
    a = p.parse_args(argv)
    seeds = [int(x) for x in a.seeds.split(",")] if a.seeds else None
    rep = verify64(a.src, int(a.addr, 16), a.symbol, a.inputs, seeds, a.time_budget, a.verbose)
    print(json.dumps(rep, default=str) if a.json else render(rep))
    return 0 if rep["status"] == "equivalent" else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
