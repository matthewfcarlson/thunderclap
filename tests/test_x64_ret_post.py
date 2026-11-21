#!/usr/bin/env python3
"""tools/equiv64.py (integ9, D165; rev5): an x64 caller of a callee with a return postcondition. post_fill leaves
return items alone (it raised TypeError on `("ret", cond)`), the draw keeps the stub's result inside the range and is the
same on both sides, it happens only after a direct `call rel32` to the stub, and an ambiguous `// sym:` gets no draw."""
import os
import struct
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))


class _Kind:
    def __init__(self, name):
        self.name = name


class _T:
    def __init__(self, kind, size):
        self.kind, self.size = _Kind(kind), size

    def get_canonical(self):
        return self

    def get_size(self):
        return self.size


class _Sig:
    def __init__(self, kind, size):
        self.ret = (_T(kind, size), _T(kind, size))


class _St:
    key, label, kind = "decl:FUN_00085f80", "FUN_00085f80", "func"


class _Side:
    def __init__(self, bits, seed=7):
        self.bits, self.seed = bits, seed


class T(unittest.TestCase):
    def setUp(self):
        import equiv
        import equiv64
        self.eq, self.e64 = equiv, equiv64
        self.ge0 = ("range", 0, float("inf"), True, True)

    def test_post_fill_skips_ret(self):
        # (the latent bug: a caller of an equivalent callee with a proven return post: `k - 1` on "ret")
        side = _Side(64)
        rv = ("int", 1)
        out = self.e64.Side.post_fill(side, [("ret", self.ge0)], rv, None, 0, [], _St(), 0)
        self.assertEqual(out, rv)
        with self.assertRaises(self.e64.Unsupported):     # an out-parameter item next to it is still filled (here: none)
            self.e64.Side.post_fill(side, [("ret", self.ge0), (1, self.ge0)], rv, None, 0, [], _St(), 0)

    def test_draw_float_in_range_same_both_sides(self):
        seen_bound = False
        for n in range(400):
            a = self.e64.Side.ret_post_draw(_Side(32), self.ge0, ("f", -3.5), _Sig("FLOAT", 4), _St(), n)
            b = self.e64.Side.ret_post_draw(_Side(64), self.ge0, ("f", -3.5), _Sig("FLOAT", 4), _St(), n)
            self.assertEqual(a, b)
            self.assertGreaterEqual(a[1], 0.0)
            v = struct.unpack("<f", struct.pack("<f", a[1]))[0]
            self.assertGreaterEqual(v, 0.0)
            seen_bound |= a[1] == 0.0
        self.assertTrue(seen_bound)          # one input in twenty at the inner bound
        nan = self.e64.Side.ret_post_draw(_Side(64), self.ge0, ("f", float("nan")), _Sig("FLOAT", 4), _St(), 3)
        self.assertTrue(nan[1] == nan[1] and nan[1] >= 0.0)

    def test_draw_int(self):
        rng = ("range", 1, 9, True, True)
        for n in range(100):
            a = self.e64.Side.ret_post_draw(_Side(64), rng, ("int", 0xFFFFFFF0), _Sig("INT", 4), _St(), n)
            v = a[1] - (1 << 32) if a[1] & 0x80000000 else a[1]
            self.assertTrue(1 <= v <= 9, v)
        p = self.e64.Side.ret_post_draw(_Side(64), rng, ("int", 0x1234), _Sig("POINTER", 8), _St(), 0)
        self.assertEqual(p, ("int", 0x1234))     # (a pointer result is never drawn)

    def test_direct_call_only(self):
        class _Chk:
            def stub_addr(self, key):
                return 0x5000

        class _S(_Side):
            def __init__(self, code):
                super().__init__(64)
                self.code, self.chk = code, _Chk()

            def read(self, a, n):
                return bytes(self.code.get(a + i, 0) for i in range(n))
        ret = 0x1005
        rel = (0x5000 - ret).to_bytes(4, "little", signed=True)
        direct = _S({0x1000 + i: b for i, b in enumerate(b"\xe8" + rel)})
        self.assertTrue(self.e64.Side.direct_call(direct, ret, _St()))
        other = _S({0x1000 + i: b for i, b in enumerate(b"\xe8" + (0x10).to_bytes(4, "little"))})
        self.assertFalse(self.e64.Side.direct_call(other, ret, _St()))
        indirect = _S({0x1003: 0xFF, 0x1004: 0xD0})     # call rax
        self.assertFalse(self.e64.Side.direct_call(indirect, ret, _St()))

    def test_ambiguous_symbol(self):
        import tempfile
        saved = dict(self.e64._RET_POST_SYMS)
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "t.cpp")
            with open(p, "w") as f:
                f.write("// 0x00000010 a (1 B): matches\n// sym: ?f@@YAHXZ\n// post: ge(ret, 0)\nint f() { return 0; }\n"
                        "// 0x00000020 b (1 B): matches\n// sym: ?f@@YAHXZ\n// post: ge(ret, 0)\nint f() { return 0; }\n")
            idx = {0x10: (p, "matches", ["ge(ret, 0)"], [], ""), 0x20: (p, "matches", ["ge(ret, 0)"], [], "")}
            old = self.eq.ret_post_blocks
            self.eq.ret_post_blocks = lambda: idx
            self.e64._RET_POST_SYMS.clear()
            try:
                self.assertIsNone(self.e64.ret_post_addr("?f@@YAHXZ"))
                self.assertEqual(self.e64.ret_post_addr("FUN_00000020"), 0x20)
                self.assertIsNone(self.e64.ret_post_addr("FUN_00000030"))
            finally:
                self.eq.ret_post_blocks = old
                self.e64._RET_POST_SYMS.clear()
                self.e64._RET_POST_SYMS.update(saved)

    def test_gate_reruns_callers(self):
        # (x64_gate) a return-post block whose post / proof lines changed between REF and HEAD: its direct callers rerun
        import tempfile
        import x64_gate
        blk = "// 0x00000100 f (8 B): matches\n// sym: ?f@@YAMXZ\n// post: %s\nfloat f() { return 0; }\n"
        caller = "// 0x00000200 g (16 B): equivalent\n// sym: ?g@@YAXXZ\nvoid g() {}\n"

        class _P:
            funcs = {0x100: (8, None), 0x200: (16, None)}

            def read(self, a, n):
                return b"\xe8" if a == 0x204 else b"\x90"
        oldp, oldc = self.eq.Program.get, self.eq.pre_callers
        self.eq.Program.get = staticmethod(lambda: _P())
        self.eq.pre_callers = lambda t: [0x204, 0x300] if t == 0x100 else []
        try:
            with tempfile.TemporaryDirectory() as d:
                for side, post in (("r", "ge(ret, 0)"), ("h", "ge(ret, 1)")):
                    os.makedirs(os.path.join(d, side, "src"))
                    os.makedirs(os.path.join(d, side, "config"))
                    with open(os.path.join(d, side, "src", "a.cpp"), "w") as f:
                        f.write(blk % post)
                    with open(os.path.join(d, side, "src", "b.cpp"), "w") as f:
                        f.write(caller)
                r, h = os.path.join(d, "r"), os.path.join(d, "h")
                self.assertEqual(x64_gate.callee_post_callers(r, h), {0x200: "src/b.cpp"})
                self.assertEqual(x64_gate.callee_post_callers(r, r), {})
                with open(os.path.join(h, "src", "a.cpp"), "w") as f:
                    f.write(blk % "ge(ret, 0)")
                self.assertEqual(x64_gate.callee_post_callers(r, h), {})
                with open(os.path.join(h, "config", "proof-revoked.jsonl"), "w") as f:
                    f.write('{"addr": "0x00000100"}\n')       # (a revoked line reruns them too)
                self.assertEqual(x64_gate.callee_post_callers(r, h), {0x200: "src/b.cpp"})
        finally:
            self.eq.Program.get, self.eq.pre_callers = oldp, oldc


if __name__ == "__main__":
    unittest.main()
