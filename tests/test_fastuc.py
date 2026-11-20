#!/usr/bin/env python3
"""tools/equiv.py _fast_uc (integ5, D155a; rev5): the direct unicorn paths return what the binding returns, and the
plain-register cache never serves a value from before a register write, a hook entry or an emulation run."""
import os
import struct
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))

CODE = 0x10000
# mov eax, 0x12345678 ; nop ; mov ecx, eax ; nop ; ret-free end
PROG = b"\xb8\x78\x56\x34\x12" + b"\x90" + b"\x89\xc1" + b"\x90"


def machine(fast):
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
    import equiv
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    if fast:
        equiv._fast_uc(uc)
    uc.mem_map(CODE, 0x1000)
    uc.mem_write(CODE, PROG)
    return uc


class T(unittest.TestCase):
    def test_fast_is_installed(self):
        import equiv
        if "fastuc" in equiv.EQUIV_OFF:
            self.skipTest("EQUIV_OFF=fastuc")
        uc = machine(True)
        self.assertIn("reg_read", uc.__dict__)

    def _run(self, fast):
        from unicorn import UC_HOOK_CODE
        from unicorn import x86_const as u
        uc = machine(fast)
        seen = []

        def hook(uc_, addr, size, _):
            if addr == CODE + 5:            # the first nop: eax is 0x12345678
                seen.append(uc_.reg_read(u.UC_X86_REG_EAX))
                seen.append(uc_.reg_read(u.UC_X86_REG_AL))
                uc_.reg_write(u.UC_X86_REG_EAX, 0xAABBCCDD)       # a write, then aliasing reads in the same hook
                seen.append(uc_.reg_read(u.UC_X86_REG_AL))
                seen.append(uc_.reg_read(u.UC_X86_REG_AX))
                seen.append(uc_.reg_read(u.UC_X86_REG_ECX))       # (cached now: the next hook must not see it)
            if addr == CODE + 8:            # the second nop: ecx changed since the last hook
                seen.append(uc_.reg_read(u.UC_X86_REG_ECX))
                seen.append(uc_.reg_read(u.UC_X86_REG_EIP))       # (cached: the run then moves past it)
        uc.hook_add(UC_HOOK_CODE, hook)
        uc.reg_write(u.UC_X86_REG_ECX, 7)
        self.assertEqual(uc.reg_read(u.UC_X86_REG_ECX), 7)
        uc.emu_start(CODE, CODE + len(PROG))
        seen.append(uc.reg_read(u.UC_X86_REG_ECX))          # after the run: its final state
        seen.append(uc.reg_read(u.UC_X86_REG_EIP))
        uc.emu_start(CODE + 6, CODE + 8)                    # a second run from a later point
        seen.append(uc.reg_read(u.UC_X86_REG_EIP))
        seen.append(bytes(uc.mem_read(CODE, 6)))
        return seen

    def test_same_values_as_the_binding(self):
        slow, fast = self._run(False), self._run(True)
        self.assertEqual(fast, slow)
        self.assertEqual(fast[:6], [0x12345678, 0x78, 0xDD, 0xCCDD, 7, 0xAABBCCDD])

    def test_exception_in_a_hook(self):
        from unicorn import UC_HOOK_CODE

        def hook(uc_, addr, size, _):
            raise ValueError("stop")
        for fast in (False, True):
            uc = machine(fast)
            uc.hook_add(UC_HOOK_CODE, hook)
            with self.assertRaises(ValueError):
                uc.emu_start(CODE, CODE + len(PROG))


if __name__ == "__main__":
    unittest.main()
