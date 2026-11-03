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
SENTINEL = STUBS - 0x1000           # return address of the function under test
GDT32, TIB32 = 0x5EFE0000, 0x5EFD0000   # i386: fs:[0] is the SEH chain (clang's EH frames register there)
FSLOT = SENTINEL + 0x100            # float result of a 32-bit stub (loaded by its thunk)
HEAP32 = 0x23450000                 # (an odd base: round integers like 0x20000000 are not addresses)
HEAP64 = 0x712340000             # (its low 32 bits, 0x12340000+, mark a truncated pointer)
NULL_HI = 0x10000                   # 0..0xFFFF reads as zero on both sides
KMAX = 16                           # elements per typed object (p[i] for small i stays typed)
RAW_SIZE = 0x1000

STEPS = int(os.environ.get("EQ64_STEPS", "1000000"))
RUN_TIMEOUT = int(float(os.environ.get("EQ64_RUN_SECONDS", "30")) * 1e6)    # per run (us); a longer run counts as a hang
OFF = set(os.environ.get("EQ64_OFF", "").split(","))


class Unsupported(Exception):
    """A construct this checker can't model (reported as status `unsupported`, class `tool`)."""


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
            "-std=c++14", "-O0"] + cp.NATIVE + ["-fcheck-new", "-ffp-eval-method=double", "-ffp-contract=off"]


def clangxx():
    c = cp.tool("clang++")
    if not c:
        raise CompileError("eq64 needs LLVM's clang++ (clang_probe.tool)")
    return c


def compile64(wrapper, d):
    """x86_64-pc-windows-msvc object + the vftable dump (slot -> method) of every class whose layout codegen used."""
    obj = os.path.join(d, "x64.obj")
    cmd = [clangxx()] + front_flags("x86_64-pc-windows-msvc") + [
        "-c", "-w", "-Xclang", "-fdump-vtable-layouts", "-I" + d, "-I" + os.path.join(ROOT, "include"), wrapper, "-o", obj]
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
        self.undef = sorted({obj.syms[si][0] for s in obj.sections for va, si, t in s["relocs"]
                             if si in obj.syms and obj.syms[si][2] == 0 and obj.syms[si][4] in (2, 105)})
        byaddr = sorted((a_, n_) for n_, a_ in self.defined.items())
        self.sym_starts = [a_ for a_, _ in byaddr]
        self.sym_names = [n_ for _, n_ in byaddr]

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
                if secnum > 0:
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
        args = [a for a in front_flags(target) if a not in ("-O0",)] + ["-w", "-I" + d, "-I" + os.path.join(ROOT, "include")]
        self.tu = m.Index.create().parse(wrapper, args=args)
        errs = [str(x) for x in self.tu.diagnostics if x.severity >= 3]
        if errs:
            raise CompileError("libclang: " + "; ".join(errs[:3]))
        self.by_mangled = {}
        self.records = {}       # record spelling (no spaces) -> definition cursor
        self._walk(self.tu.cursor, 0)

    def _walk(self, c, depth):
        K = ci().CursorKind
        for ch in c.get_children():
            k = ch.kind
            if k in (K.FUNCTION_DECL, K.CXX_METHOD, K.CONSTRUCTOR, K.DESTRUCTOR, K.VAR_DECL, K.CONVERSION_FUNCTION):
                try:
                    mn = ch.mangled_name
                except Exception:   # noqa: BLE001
                    mn = None
                names = [mn] if mn else []
                if k in (K.CONSTRUCTOR, K.DESTRUCTOR):
                    names += cxx_manglings(ch)
                for mn in names:
                    self.by_mangled.setdefault(mn, ch)
                    if self.bits == 32 and not mn.startswith("?"):
                        self.by_mangled.setdefault("_" + mn, ch)
                    if mn.startswith("_") and self.bits == 32 and "@" in mn and not mn.startswith("?"):
                        self.by_mangled.setdefault(mn, ch)
            if k in (K.NAMESPACE, K.LINKAGE_SPEC, K.UNEXPOSED_DECL):
                self._walk(ch, depth + 1)
            elif k in (K.CLASS_DECL, K.STRUCT_DECL, K.UNION_DECL, K.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION) or \
                    k.name == "CLASS_TEMPLATE":
                if ch.is_definition() and k.name != "CLASS_TEMPLATE":
                    self.records.setdefault(ch.type.get_canonical().spelling.replace(" ", ""), ch)
                self._walk(ch, depth + 1)


class Leaf:
    __slots__ = ("path", "o32", "o64", "kind", "s32", "s64", "extra", "signed")

    def __init__(self, path, o32, o64, kind, s32, s64, extra=None, signed=False):
        self.path, self.o32, self.o64, self.kind, self.s32, self.s64 = path, o32, o64, kind, s32, s64
        self.extra, self.signed = extra, signed

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
        if l is not None and l.kind == "b":
            return e * self.size32 + l.o32 + (r - l.o64)
        return None

    def to64(self, off32):
        e, r = divmod(off32, self.size32)
        if r in self.m32:
            return e * self.size64 + self.m32[r]
        l = self.leaf_at(32, r)
        if l is not None and l.kind == "b":
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


class Types:
    """Paired layouts from the two parses (lockstep walk of the same declarations)."""

    def __init__(self, tu32, tu64, vtables):
        self.t = {32: tu32, 64: tu64}
        self.cache = {}
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
            self._flatten(x.type, y.type, o32 + pa // 8, o64 + pb // 8, path + (x.spelling or "anon%d" % pa,), out, None)
            if union:
                break

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
    __slots__ = ("id", "ident", "kind", "lay", "count", "a32", "a64", "size32", "size64", "ptrs", "hint", "alloc", "init")

    def __init__(self, oid, ident, kind, lay, count, size32, size64):
        self.id, self.ident, self.kind, self.lay, self.count = oid, ident, kind, lay, count
        self.size32, self.size64 = size32, size64
        self.a32 = self.a64 = 0
        self.ptrs = {}
        self.hint = None
        self.alloc = None       # (n32, n64) requested sizes of an allocation
        self.init = None        # fixed initial bytes per side (vtables), else generated

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
        self.starts = {32: [], 64: []}      # sorted region starts -> obj
        self.order = {32: [], 64: []}
        self.by_type = {}
        self.choices = {}

    def _region(self, bits, size):
        a = self.next[bits]
        self.next[bits] = a + ((size + PAGE - 1) & ~(PAGE - 1)) + PAGE     # one unmapped guard page after each
        return a

    def get(self, ident, kind, lay, count=None, glob=False, alloc=None):
        o = self.by_ident.get(ident)
        if o is not None:
            return o
        if count is None:
            # a record is one object (indexing past it is out of bounds, and the input is not used); scalars
            # (int*, float*, T**) are arrays of up to KMAX
            count = 1 if glob or (lay.record and ident == ("arg", "this")) else max(1, min(KMAX, RAW_SIZE // max(1, lay.size32)))
        if lay.raw:
            n = alloc[0] if alloc else RAW_SIZE
            s32 = s64 = max(1, n)
            if alloc:
                s32, s64 = max(1, alloc[0]), max(1, alloc[1])
        else:
            s32, s64 = lay.size32 * count, lay.size64 * count
        o = Obj(len(self.objs), ident, kind, lay, count, s32, s64)
        o.alloc = alloc
        if glob:
            a = self.gnext
            span = (max(s32, s64) + PAGE - 1) & ~(PAGE - 1)
            self.gnext = a + span + PAGE
            o.a32 = o.a64 = a
        else:
            o.a32 = self._region(32, max(s32, PAGE))
            o.a64 = self._region(64, max(s64, PAGE))
        self.objs.append(o)
        self.by_ident[ident] = o
        for bits in (32, 64):
            i = bisect.bisect_right(self.starts[bits], o.base(bits))
            self.starts[bits].insert(i, o.base(bits))
            self.order[bits].insert(i, o)
        self.by_type.setdefault(lay.key, []).append(o)
        return o

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
            r = Rng(self.seed, "raw", o.id)
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
            return buf
        lay = o.lay
        es = lay.size(bits)
        for e in range(o.count):
            for l in lay.leaves:
                self.put_leaf(buf, e * es + l.off(bits), bits, l, self.leaf_value(o, e, l))
        return buf

    def leaf_value(self, o, e, l):
        """The abstract value of leaf L of element E of O: ("i", int) ("f", bits) ("d", bits) ("b", bytes) or a
        pointer ("p", obj or None, 32-bit offset) / ("fn", stub key) / ("vt", vtable obj)."""
        r = Rng(self.seed, "leaf", o.id, e, l.o32)
        k = l.kind
        if k == "i" or k == "u":
            return ("i", gen_int(r, min(l.s32, l.s64), l.signed))
        if k == "f":
            return ("f", struct.unpack("<I", struct.pack("<f", gen_float(r)))[0])
        if k == "d":
            return ("d", struct.unpack("<Q", struct.pack("<d", gen_float(r)))[0])
        if k == "b":
            return ("b", bytes(gen_byte(r) for _ in range(l.s32)))
        if k == "p":
            key = (e, l.o32)
            if key not in o.ptrs:
                v = None
                prev = self.range_partner(o.lay, l)
                if prev is not None:
                    # [begin, end) pairs (a vector's begin/end/capacity): the later pointer points into the
                    # earlier one's array (null with it), so `end - begin` is an element count on both targets
                    pv = self.leaf_value(o, e, prev)
                    t = pv[1] if pv[0] == "p" else None
                    if t is None:
                        v = ("p", None, 0)
                    elif not t.lay.raw:
                        k_ = r.below(t.count + 1)
                        v = ("p", t, k_ * t.lay.size32)
                if v is None:
                    v = self.choose_ptr(r, ("leaf", o.id, e, l.o32), l.extra)
                o.ptrs[key] = v
            return o.ptrs[key]
        if k == "fp":
            if r.below(4) == 0:
                return ("p", None, 0)
            st = self.chk.fnptr_stub(("fnptr", o.id, e, l.o32), l.extra)
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

    def choose_ptr(self, r, ident, types):
        """A pointer value for IDENT: null, an existing object of the pointee type, or a new one. Decided once per
        input (the 64-bit run sees the 32-bit run's choice, whatever objects exist by then)."""
        if ident in self.choices:
            return self.choices[ident]
        v = self._choose_ptr(r, ident, types)
        self.choices[ident] = v
        return v

    def _choose_ptr(self, r, ident, types):
        x = r.below(100)
        if x < 20:
            return ("p", None, 0)
        lay = self.chk.types.layout(types[0], types[1]) if types else RAW
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
        v = o.lay.to64(off32)
        if v is None:
            raise Unsupported("interior pointer translation")
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
I386_HELPERS = {"__alldiv", "__aulldiv", "__allrem", "__aullrem", "__allmul", "__allshl", "__allshr", "__aullshr",
                "__aulldvrm", "__alldvrm"}
SKIP_CALLS = {"__security_check_cookie", "__chkstk", "_alloca_probe", "__alloca_probe", "_RTC_CheckEsp"}
ALLOCATORS = {"??2@YAPAXI@Z", "??_U@YAPAXI@Z", "??2@YAPEAX_K@Z", "??_U@YAPEAX_K@Z", "_malloc", "malloc",
              "FUN_0008d690", "_FUN_0008d690", "FUN_0008d6d0", "_FUN_0008d6d0"}


# implicitly declared functions (no declaration for libclang): i386 name -> (x64 name, signature)
IMPLICIT_SIGS = {"??3@YAXPAX@Z": ("??3@YAXPEAX@Z", lambda: _sig_delete()),
                 "??_V@YAXPAX@Z": ("??_V@YAXPEAX@Z", lambda: _sig_delete())}


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


def norm_mangled(name):
    """Fallback pairing of an x64 MS mangled name with its i386 spelling (no __ptr64 `E`, thiscall members)."""
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
        if symbol is None:
            symbol = self._pick_by_original()
        if symbol and symbol.startswith("??_G") and symbol not in self.img[32].funcs:
            self.deleting_dtor(symbol, d)
        self.pick(symbol)
        self.resolve_all()

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
        name64 = None
        if c32 is not None:
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
        c64 = self.tu[64].by_mangled.get(name64)
        if c32 is None or c64 is None:
            raise Unsupported("no declaration for %s" % name32)
        self.sig = Sig.of(c32, c64, name32)
        self.param_casts = {}
        if "casts" not in OFF:
            a32, a64 = param_casts(c32), param_casts(c64)
            for k in a32:
                if k in a64:
                    self.param_casts[k] = (a32[k], a64[k])
        self.range32 = self.img[32].func_range(name32)

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
        # signatures of function stubs from both parses
        for st in self.stubs:
            if st.kind != "func":
                continue
            n32, n64 = st.names.get(32), st.names.get(64)
            c32 = self.tu[32].by_mangled.get(n32) if n32 else None
            c64 = self.tu[64].by_mangled.get(n64) if n64 else None
            if c32 is not None and c64 is not None:
                try:
                    st.sig = Sig.of(c32, c64, st.label)
                except Exception:   # noqa: BLE001
                    st.sig = None
            elif n32 in IMPLICIT_SIGS and n64 == IMPLICIT_SIGS[n32][0]:
                st.sig = IMPLICIT_SIGS[n32][1]()
            elif n32 and n64 and n32.startswith("??1") and n32.endswith("AE@XZ") and n64.endswith("EAA@XZ"):
                # a destructor of a template instance (no declaration cursor): void (this), thiscall
                st.sig = Sig((FakeType("VOID", 0), FakeType("VOID", 0)), [], CC_THIS, True, False, None, n32)

    def new_stub(self, key, sig, kind, label=""):
        st = Stub(key, sig, kind, len(self.stubs), label)
        if len(self.stubs) >= STUB_SLOTS:
            raise Unsupported("too many stubs")
        self.stubs.append(st)
        self.stub_by_key[key] = st
        return st

    def stub_addr(self, key):
        return STUBS + 16 * self.stub_by_key[key].idx

    def fnptr_stub(self, key, ftypes):
        st = self.stub_by_key.get(key)
        if st is None:
            st = self.new_stub(key, Sig.of(ftypes[0], ftypes[1], "fnptr"), "fnptr", "fnptr")
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
        for seed in seq:
            if time.process_time() - t0 > time_budget and not seeds:
                res["stopped"] = "time budget"
                break
            res["inputs"] += 1
            out = self.one(seed)
            if out.get("skip"):
                res["skipped"][out["skip"]] = res["skipped"].get(out["skip"], 0) + 1
                res.setdefault("skip_first", {}).setdefault(out["skip"], out.get("why"))
                continue
            res["completed"] += 1
            cov |= out.get("cov", set())
            if out.get("diff"):
                c = out["class"]
                res["classes"][c] = res["classes"].get(c, 0) + 1
                if len(res["fails"]) < 3:
                    res["fails"].append({"seed": seed, "class": c, "diff": out["diff"]})
                if len(res["fails"]) >= 3 and not seeds:
                    break
        res["cov"] = cov
        return res

    def one(self, seed):
        heap = Heap(self, seed)
        self.flags = set()
        r32 = Side(self, 32, heap, seed).call()
        if r32.get("skip"):
            return {"skip": r32["skip"], "why": (r32.get("stop") or ("", ""))[1]}
        r64 = Side(self, 64, heap, seed).call()
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
        if c32 is not None and c64 is not None:
            try:
                lay = self.chk.types.layout(c32.type, c64.type)
            except Unsupported:
                lay = RAW
        return h.get(("sym", key), "global", lay, count=1, glob=True)

    def _unmapped(self, uc, access, address, size, value, data):
        if access == UC_MEM_FETCH_UNMAPPED:
            self.stop = ("crash", "call or jump to unmapped 0x%x" % address)
            return False
        try:
            return self.map_page(address)
        except Exception as e:  # noqa: BLE001
            self.stop = ("tool", "map: %r" % e)
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
        self.writes.append((address, size))

    def _read(self, uc, access, address, size, value, data):
        """Reads past the end of an object (its elements, or an allocation's requested size): an input whose
        32-bit run does this is not used; a 64-bit run that does it alone has a layout difference."""
        if self.oob is not None:
            return
        o, off = self.heap.find(self.bits, address)
        if o is None:
            self.oob = ("heap gap", address)
            return
        if off + size > o.size(self.bits) and o.init is None:
            self.oob = (describe(o), off)
            return
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
        v = lay.to32(off)
        return v if v is not None else ("in64", off)

    def canon_value(self, t, data):
        """DATA (bytes of type T on this side) as a target-independent value."""
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
            if (o_ is not None and off_ < o_.size(self.bits)) or (STUBS <= v < self.stub_hi) or (CODE <= v < self.code_end):
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
        if self.bits == 64 and is_record(t) and (n not in (1, 2, 4, 8) or not trivial_copy(rdecl(t))):
            p = int.from_bytes(self.read_loc(loc, 8, sp), "little")
            return self.read(p, n)
        if self.bits == 64 and loc[0] == "stack":
            return self.read(sp + loc[1], n)
        return self.read_loc(loc, n, sp)

    def call(self):
        """Run the function under test on this side's view of the input."""
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
                data = self.arg_data(pt, ("arg", i), Rng(self.seed, "arg", i))
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
        try:
            self.stub(address)
        except Stop:
            uc.emu_stop()
        except Unsupported as e:
            self.stop = ("tool", str(e))
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
        if cname in CRT_SEMANTIC:
            return self.crt(cname, sp, retaddr)
        if st.kind == "vslot" and st.sig == ("deleting",):
            sig = None
        else:
            sig = st.sig
        if name in ALLOCATORS or cname in ALLOCATORS:
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
        for (kind, t), loc in zip(kinds, locs):
            if kind == "this":
                v = int.from_bytes(self.read_loc(loc, self.ps, sp), "little")
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
                cv = self.canon_value(t, data)
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
        return self._ret(sp, retaddr, pop, rv, sig)

    def hint(self, v, pt):
        if pt is None:
            return
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
        if k in ("p", "fp", "vp"):
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
        r = Rng(self.seed, "ret", repr(st.key), n)
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
        elif name in ("strcmp", "_stricmp", "stricmp", "strncmp", "_strnicmp"):
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
        size = self.int_args(sp, 1)[0] if self.bits == 64 or sig is None or sig.cc32 != CC_THIS else 0
        if b == 32 and sig is not None and sig.cc32 in (CC_FAST,):
            size = self.reg(X.UC_X86_REG_ECX)
        size &= (1 << (8 * self.ps)) - 1
        ident = ("new", repr(st.key), n)
        o = self.heap.by_ident.get(ident)
        if o is None:
            o = self.heap.get(ident, "alloc", RAW, alloc=(size, size))
        if b == 64 and o.alloc[1] != size or b == 32 and o.alloc[0] != size:
            o.alloc = (o.alloc[0], size) if b == 64 else (size, o.alloc[1])
            o.size64 = max(1, o.alloc[1])
            o.size32 = max(1, o.alloc[0])
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
    """`??_7Inner@Outer@@6B@` -> `Outer::Inner` (non-template names only)."""
    m = VT_NAME.match(name or "")
    if not m or "?" in m.group(1) or "$" in m.group(1):
        return None
    return "::".join(reversed(m.group(1).split("@")))


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
            r32, r64 = chk.tu[32].records.get(cls), chk.tu[64].records.get(cls)
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
        cls = {"crash": "crash64", "hang": "hang64", "tool": "tool"}.get(st[0], "tool")
        if st[0] == "tool":
            return "64-bit run: %s" % st[1], "tool"
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
            v32 = s32.decode_leaf(a32, l32)
            v64 = s64.decode_leaf(a64, l64 or l32)
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
            return ptrnote(s64, "memory %s%s: 32-bit %s, 64-bit %s" % (describe(o) + " " if o else "", fmt_key(key), short(v32),
                                                                      short(v64)), cls)
    return None, None


def ptrnote(s64, text, cls):
    """A difference after the 64-bit run read part of a pointer field (a 4-byte access the 64-bit layout puts
    inside an 8-byte pointer: a raw offset or a pointer kept in an int) is a layout difference."""
    if s64.ptrpart:
        return text + " (after: %s)" % s64.ptrpart, "layout"
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
    if has(b, lambda t: t[:1] == ("trunc",)) or has(b, ptrtrunc) or (isinstance(a, tuple) and isinstance(b, tuple) and a[:1] in (("obj",), ("alloc",))
                            and b[:1] in (("i",), ("int",))):
        return "ptrtrunc"
    if has(a, lambda t: len(t) > 1 and t[0] in ("f", "d")) or has(b, lambda t: len(t) > 1 and t[0] in ("f", "d")):
        if not has(a, lambda t: t[:1] in (("obj",), ("i",), ("int",))) or _floats_only_differ(a, b):
            return "float"
    if "wild" in s64.flags and not has(a, lambda t: t[0] == "int"):
        return "untyped"
    if isinstance(a, tuple) and isinstance(b, tuple) and a and b and a[0] == "call" and b[0] == "call" and a[1] != b[1]:
        return "call"
    if a is None or b is None or (isinstance(a, tuple) and isinstance(b, tuple) and a[:1] != b[:1]):
        return "call"
    return "int"


# ------------------------------------------------------------------------------------------------- driver
def verify64(src, addr, symbol=None, n_inputs=200, seeds=None, time_budget=120, verbose=False):
    t0 = time.time()
    rep = {"addr": "0x%08x" % addr, "src": src, "mode": "x64", "status": "fail"}
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
        rep.update(status="unsupported", error="[tool] " + str(e), **{"class": "tool"}, time=round(time.time() - t0, 2))
        return rep
    rep["inputs"], rep["completed"], rep["skipped"] = res["inputs"], res["completed"], res["skipped"]
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
    if res["fails"]:
        rep["status"] = "fail"
        rep["class"] = res["fails"][0]["class"]
        rep["diff"] = res["fails"][0]["diff"]
        rep["seed"] = res["fails"][0]["seed"]
        rep["fails"] = res["fails"]
    elif res["completed"] == 0:
        rep["status"] = "unsupported"
        rep["class"] = "tool"
        rep["error"] = "[tool] no input completed on the 32-bit side (%s; first: %s)" % (res["skipped"], res.get("skip_first"))
    elif res["completed"] < 8:
        rep["status"] = "inconclusive"
    else:
        rep["status"] = "equivalent"
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
