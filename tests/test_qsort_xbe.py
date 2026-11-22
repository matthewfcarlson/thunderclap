#!/usr/bin/env python3
"""src/platform/sdl/crt/hulk_qsort.h against the XBE's qsort (0x00345f90) run as a black box (wasmq, D217).

The XBE function runs under Unicorn on a seeded random corpus (element widths 1 to 0x101, lengths 0 to 3000, keys
from 1 to 2^30 distinct values, sorted / reversed / random arrays, comparators that return 0 for equal keys, never
return 0, or answer at random, and that return large magnitudes); our sort, compiled by the host's C compiler, runs on
the same arrays. Both must call the comparator with the same element pairs in the same order and leave the same
permutation. Only the function's inputs and outputs are observed (the comparator is a hook at a mapped address); no
instruction of it is read. Nothing is recorded: the expected behaviour is generated at test time from the player's
own XBE, and the test is skipped without isos/extracted/default.xbe or a C compiler. docs/qsort.md."""
import ctypes
import os
import random
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
XBE = os.path.join(ROOT, "isos/extracted/default.xbe")
HEADER = os.path.join(ROOT, "src/platform/sdl/crt/hulk_qsort.h")
CC = shutil.which("cc") or shutil.which("clang") or shutil.which("gcc")
try:
    import unicorn  # noqa: F401
    HAVE_UC = True
except ImportError:
    HAVE_UC = False

QSORT = 0x00345F90
CMP_VA = 0x0F000000      # the comparator: a hooked `ret`
RET_VA = 0x0F000010      # qsort's return address: `hlt`
ARR_VA = 0x0E000000
STACK_TOP = 0x0D100000
CASES = int(os.environ.get("HULK_QSORT_CASES", "600"))


class BlackBox:
    """The XBE's sections mapped at their addresses, .bss zeroed; qsort called with cdecl arguments."""

    def __init__(self):
        from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UcError
        from xbe import Xbe
        x = Xbe(XBE)
        uc = Uc(UC_ARCH_X86, UC_MODE_32)
        for s in x.sections:
            lo = s.va & ~0xFFF
            hi = (s.va + max(s.vsize, s.rsize) + 0xFFF) & ~0xFFF
            for pg in range(lo, hi, 0x1000):
                try:
                    uc.mem_map(pg, 0x1000)
                except UcError:
                    pass          # (a page two sections share)
            uc.mem_write(s.va, x.data[s.raw:s.raw + min(s.rsize, s.vsize)])
        uc.mem_map(CMP_VA, 0x1000)
        uc.mem_write(CMP_VA, b"\xc3")
        uc.mem_write(RET_VA, b"\xf4")
        uc.mem_map(ARR_VA, 0x1000000)
        uc.mem_map(STACK_TOP - 0x100000, 0x100000)
        uc.hook_add(UC_HOOK_CODE, self._hook, begin=CMP_VA, end=CMP_VA)
        self.uc = uc

    def _hook(self, uc, addr, size, _):
        from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EAX
        esp = uc.reg_read(UC_X86_REG_ESP)
        a, b = struct.unpack("<II", uc.mem_read(esp + 4, 8))
        self.calls.append((a - ARR_VA, b - ARR_VA))
        r = self.cmp(bytes(uc.mem_read(a, self.width)), bytes(uc.mem_read(b, self.width)))
        uc.reg_write(UC_X86_REG_EAX, r & 0xFFFFFFFF)

    def sort(self, data, count, width, cmp):
        from unicorn.x86_const import UC_X86_REG_ESP
        self.width, self.cmp, self.calls = width, cmp, []
        self.uc.mem_write(ARR_VA, data)
        esp = STACK_TOP - 0x100
        self.uc.mem_write(esp, struct.pack("<IIIII", RET_VA, ARR_VA, count, width, CMP_VA))
        self.uc.reg_write(UC_X86_REG_ESP, esp)
        self.uc.emu_start(QSORT, RET_VA, count=500_000_000)
        return bytes(self.uc.mem_read(ARR_VA, count * width)), self.calls


CMPF = ctypes.CFUNCTYPE(ctypes.c_int, ctypes.c_void_p, ctypes.c_void_p)


class Ours:
    """hulk_qsort.h compiled into a shared library by the host compiler."""

    def __init__(self, tmp):
        src = os.path.join(tmp, "q.c")
        lib = os.path.join(tmp, "q.so")
        with open(src, "w") as f:
            f.write('#include "%s"\nvoid hq(void* b, size_t n, size_t w, hulk_qsort_cmp c) { hulk_qsort(b, n, w, c); }\n'
                    % HEADER)
        subprocess.run([CC, "-O2", "-shared", "-fPIC", "-Wall", "-Werror", "-Wno-unused-function", src, "-o", lib],
                       check=True, capture_output=True)
        self.lib = ctypes.CDLL(lib)
        self.lib.hq.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t, CMPF]
        self.lib.hq.restype = None

    def sort(self, data, count, width, cmp):
        buf = ctypes.create_string_buffer(data, max(len(data), 1))
        base = ctypes.addressof(buf)
        calls = []

        def hook(a, b):
            calls.append((a - base, b - base))
            r = cmp(ctypes.string_at(a, width), ctypes.string_at(b, width)) & 0xFFFFFFFF
            return r - (1 << 32) if r & 0x80000000 else r
        self.lib.hq(base, count, width, CMPF(hook))
        return buf.raw[:count * width], calls


def corpus(seed, n_cases):
    """(data, count, width, comparator factory) cases. Each element starts with its 16-bit index (its identity),
    then filler bytes; its key comes from a side table."""
    rng = random.Random(seed)
    for t in range(n_cases):
        width = rng.choice([1, 2, 3, 4, 5, 7, 8, 12, 16, 0xE0, 0x101])
        count = rng.choice([0, 1, 2, 3, 8, 9, 10, 17, 33, 100, rng.randint(0, 400), 3000 if t % 97 == 0 else 50])
        if width == 1:
            count = min(count, 256)
        kr = rng.choice([1, 2, 3, 5, 1000, 1 << 30])
        keys = [rng.randrange(kr) for _ in range(count)]
        order = rng.random()
        if order < 0.1:
            keys.sort()
        elif order < 0.2:
            keys.sort(reverse=True)
        elems = [i.to_bytes(2, "little")[:width] + bytes(rng.randrange(256) for _ in range(max(0, width - 2)))
                 for i in range(count)]
        ident = (lambda e: e[0]) if width == 1 else (lambda e: e[0] | e[1] << 8)
        kind = rng.choice(["three-way", "never-zero", "random"])
        big = rng.choice([1, 2, 0x10000, 0x7FFFFFFF])
        neg = rng.choice([-1, -2, -0x10000, -0x80000000])
        cseed = rng.randrange(1 << 30)

        def factory(keys=keys, ident=ident, kind=kind, big=big, neg=neg, cseed=cseed):
            r = random.Random(cseed)

            def cmp(a, b):
                if kind == "random":
                    return r.choice((neg, 0, big))
                x, y = keys[ident(a)], keys[ident(b)]
                if x > y:
                    return big
                if x < y:
                    return neg
                return 0 if kind == "three-way" else big
            return cmp
        yield "case %d: width %d count %d keys<%d %s" % (t, width, count, kr, kind), b"".join(elems), count, width, factory


@unittest.skipUnless(os.path.exists(XBE) and HAVE_UC and CC, "needs isos/extracted/default.xbe, unicorn and cc")
class QsortMatchesXbe(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.mkdtemp(prefix="hulk_qsort_")
        cls.ours = Ours(cls.tmp)
        cls.bb = BlackBox()

    @classmethod
    def tearDownClass(cls):
        shutil.rmtree(cls.tmp, ignore_errors=True)

    def test_corpus(self):
        bad = []
        for name, data, count, width, factory in corpus(0x5EED, CASES):
            want, want_calls = self.bb.sort(data, count, width, factory())
            got, got_calls = self.ours.sort(data, count, width, factory())
            if want != got or want_calls != got_calls:
                k = next((i for i, (x, y) in enumerate(zip(want_calls, got_calls)) if x != y),
                         min(len(want_calls), len(got_calls)))
                bad.append("%s: %s, comparator calls differ from call %d of %d/%d" % (
                    name, "same order" if want == got else "order differs", k, len(want_calls), len(got_calls)))
        self.assertEqual(bad, [], "\n".join(bad[:10]))


if __name__ == "__main__":
    unittest.main()
