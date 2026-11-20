"""(integ3, D152; rev5) No build may define HULK_CONTRACTS: include/compat/pre.h traps by default, and a release (native)
build has nothing else that would notice a -DHULK_CONTRACTS=0/1 switching the contracts off."""
import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tools"))


def _has(flags):
    return any("HULK_CONTRACTS" in str(f) for f in flags)


class Flags(unittest.TestCase):
    def test_native_mac(self):
        import native_mac
        self.assertFalse(_has(native_mac.FRONT))

    def test_native_elf(self):
        import native_elf
        for t in native_elf.TARGETS:
            fl = native_elf.flags(t)
            self.assertFalse(_has(fl[0] if isinstance(fl, tuple) else fl), t)

    def test_wine_and_probe(self):
        import clang_probe as cp
        self.assertFalse(_has(cp.COMMON) or _has(cp.NATIVE))
        for name, cfg in cp.CONFIGS.items():
            self.assertFalse(_has(cfg.get("flags", [])), name)

    def test_wine_link(self):
        p = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tools", "wine_link.py")
        self.assertNotIn("HULK_CONTRACTS", open(p).read())


if __name__ == "__main__":
    unittest.main()
