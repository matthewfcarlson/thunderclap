"""tools/wasm_port.py's data-stub guard (gcmp1): data names the wasm link stubs fail it unless the baseline lists them."""
import json
import os
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import wasm_port  # noqa: E402


class DataStubs(unittest.TestCase):
    def test_classify(self):
        decl = {"?f@@YAXXZ": ("?f@@YAXXZ", "declare void @\"?f@@YAXXZ\"()"),
                "?one@@3MA": ("?one@@3MA", "@\"?one@@3MA\" = external global float, align 4")}
        self.assertEqual(wasm_port.data_stubs(["?f@@YAXXZ", "?one@@3MA", "?noline@@3HA"], decl),
                         ["?noline@@3HA", "?one@@3MA"])

    def test_check(self):
        new, gone = wasm_port.data_stub_check(["a", "b"], ["b", "c"])
        self.assertEqual(new, ["a"])
        self.assertEqual(gone, ["c"])

    def test_baseline_file(self):
        names = json.load(open(wasm_port.DATA_STUB_BASELINE))["names"]
        self.assertEqual(names, sorted(set(names)))


if __name__ == "__main__":
    unittest.main()
