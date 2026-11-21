#!/usr/bin/env python3
"""tools/equiv.py `// vclass:` (integ9, D177): class evidence for an indirect call's pop, checked against the XBE's
RTTI (the class family's vftables at the class's subobject offset, every `ret N` of the slot's function, _purecall
slots skipped, a tail jump through the object's own vftable followed) and the original's stack model. Needs the XBE."""
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))


class T(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        import equiv
        cls.eq = equiv
        try:
            cls.p = equiv.Program.get()
        except Exception as e:     # noqa: BLE001
            raise unittest.SkipTest("no XBE: %s" % e)

    def pop(self, entry, line):
        return self.eq.vclass_pop(self.p, entry, line)

    def test_resolves(self):
        r, why = self.pop(0xb0a50, "+0x6f .?AUIControllerInputPoint@core@@ ev 0x00268fa0")
        self.assertIsNone(why)
        self.assertEqual(r[:2], (0xb0abf, 8))
        self.assertEqual(r[2], ["0x0042b24c"])            # (the interfaces' _purecall slots are no object's)
        self.assertEqual(self.pop(0x296160, "+0x49 .?AVd3dContext@pure3d@@ ev 0x00268fa0")[0][1], 4)   # (a self tail jump followed)

    def test_refusals(self):
        self.assertIn("not `+0xOFF", self.pop(0xb0a50, "+0x6f .?AUIControllerInputPoint@core@@")[1])   # no evidence
        self.assertIn("not a class", self.pop(0xb0a50, "+0x6f .?AVNoSuch@@ ev 0x00268fa0")[1])
        self.assertIn("no slot", self.pop(0xb0a50, "+0x6f .?AUIDriveErrorCallback@core@@ ev 0x00268fa0")[1])
        self.assertIn("not an indirect call", self.pop(0xb0a50, "+0x0 .?AUIControllerInputPoint@core@@ ev 0x00268fa0")[1])
        self.assertIn("no slot", self.pop(0xb0a50, "+0x6f .?AUIRefCount@core@@ ev 0x00268fa0")[1])    # (a family without the slot)
        self.assertIn("unknown", self.pop(0x272df0, "+0xb8 .?AVRequest@core@@ ev 0x00268fa0")[1])   # (a tail jump through another object)
        # (a pop the original's stack model can't have there: +0xb8 allows 0 or 4, Drive's slot 5 pops 8)
        self.assertIn("stack model", self.pop(0x272df0, "+0xb8 .?AVDrive@core@@ ev 0x00268fa0")[1])

    def test_citations(self):
        # (rev5) the evidence cites at least one address, each a function start or a vftable
        self.assertIn("cites no address", self.pop(0xb0a50, "+0x6f .?AUIControllerInputPoint@core@@ because")[1])
        self.assertIn("neither a function", self.pop(0xb0a50, "+0x6f .?AUIControllerInputPoint@core@@ see 0x0052c2ac")[1])
        self.assertIsNone(self.pop(0xb0a50, "+0x6f .?AUIControllerInputPoint@core@@ built by FUN_00268fa0")[1])

    def test_mixed_family(self):
        # (rev5) a family whose members' slot pops differ is refused, never pinned to one of the pops
        import itertools
        old = self.eq._ret_pops
        cnt = itertools.count()
        self.eq._ret_pops = lambda prog, f, depth=0, slots=None: 4 * (next(cnt) % 2)
        try:
            r, why = self.pop(0x296160, "+0x3a .?AVNode@scenegraph@pure3d@@ ev 0x00297f20")
            self.assertIsNone(r)
            self.assertIn("pop [0, 4]", why)
        finally:
            self.eq._ret_pops = old

    def test_purecall_and_selfjump(self):
        self.assertTrue(self.eq._is_purecall(self.p, 0x344f51))
        self.assertFalse(self.eq._is_purecall(self.p, 0x268ec0))
        self.assertEqual(self.eq._self_vjump(self.p, 0x31e840), 0x1b0)
        self.assertIsNone(self.eq._self_vjump(self.p, 0x2738d0))     # (`mov ecx, [ecx+8]`: another object)

    def test_pinned(self):
        self.eq.VCLASS_PINS.clear()
        self.eq.VCLASS_PINS[0x1000] = 8
        try:
            calls = [{"at": 0x1000, "esp": 0x7000}, {"esp": 0x7008, "args": [1], "known": False}]
            self.assertTrue(self.eq._split_pinned(self.p, calls, 0, 8, 2))
            self.assertFalse(self.eq._split_pinned(self.p, calls, 0, 4, 2))
        finally:
            self.eq.VCLASS_PINS.clear()


class Pair(unittest.TestCase):
    """(integ10; rev5) vsplit/msplit pair ours' call with the original's k-th by slot, not by raw call index."""

    def test_inserted_direct_call(self):
        import equiv
        o = [{"islot": None, "target": 0x1}, {"islot": 0x40}, {"islot": 0xc}, {"islot": 0x40}]
        # ours: clang calls strcmp out of line before the second slot call (MSVC inlined it): raw indices shift by one
        r = [{"islot": None, "target": 0x1}, {"islot": 0x40}, {"islot": None, "target": 0x2}, {"islot": 0xc},
             {"islot": 0x40}]
        self.assertEqual(equiv._pair_icall(o, r, 1), 1)
        self.assertEqual(equiv._pair_icall(o, r, 2), 3)      # (raw index 2 is the strcmp)
        self.assertEqual(equiv._pair_icall(o, r, 3), 4)      # (the 2nd call through +0x40 on both sides)

    def test_register_call(self):
        # clang -O0 loads the slot into a register: `mov eax, [ecx+0x3c]; mov [esp], edx; call eax` is slot 0x3c
        import capstone
        import equiv
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        md.detail = True

        class V:
            def __init__(self, code, base=0x1000):
                self.insns = {}
                for ci in md.disasm(code, base):
                    self.insns[ci.address] = equiv.Insn(ci, md)

            def decode(self, a):
                return self.insns.get(a)
        v = V(bytes.fromhex("8b413c" "891424" "ffd0"))
        call = v.insns[max(v.insns)]
        self.assertEqual(equiv._icall_slot(call, v), 0x3c)
        v = V(bytes.fromhex("8b413c" "83c004" "ffd0"))           # (add eax, 4 after the load: not a slot)
        self.assertIsNone(equiv._icall_slot(v.insns[max(v.insns)], v))
        v = V(bytes.fromhex("8b4424" "08" "ffd0"))                # (a load from the frame)
        self.assertIsNone(equiv._icall_slot(v.insns[max(v.insns)], v))
        v = V(bytes.fromhex("ff523c"))                            # (call [edx+0x3c])
        self.assertEqual(equiv._icall_slot(v.insns[0x1000], v), 0x3c)

    def test_unpaired(self):
        import equiv
        o = [{"islot": 0x40}, {"islot": 0x40}]
        self.assertIsNone(equiv._pair_icall(o, [{"islot": 0x40}], 1))          # (no 2nd +0x40 call in ours)
        self.assertIsNone(equiv._pair_icall(o, [{"islot": 0x44}, {"islot": 0x40}, {"islot": None}], 1))
        self.assertIsNone(equiv._pair_icall([{"islot": None}], [{"islot": None}], 0))   # (not a slot call)
        self.assertIsNone(equiv._pair_icall(o, o, 5))


if __name__ == "__main__":
    unittest.main()
