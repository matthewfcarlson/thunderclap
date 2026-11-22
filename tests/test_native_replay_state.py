"""native_replay.py run starts every replay from empty save / tdata / udata directories (wasm12)."""
import os
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools"))
import native_replay  # noqa: E402


class FreshStateDirs(unittest.TestCase):
    def test_wipes_earlier_state(self):
        with tempfile.TemporaryDirectory() as out:
            os.makedirs(os.path.join(out, "save", "U", "sig"))
            with open(os.path.join(out, "save", "U", "sig", "slot.dat"), "w") as f:
                f.write("x")
            with open(os.path.join(out, "udata"), "w") as f:      # a stray file where a directory belongs
                f.write("x")
            with open(os.path.join(out, "stdout.txt"), "w") as f:  # other run outputs are left alone
                f.write("x")
            native_replay.fresh_state_dirs(out)
            for sub in native_replay.STATE_DIRS:
                d = os.path.join(out, sub)
                self.assertTrue(os.path.isdir(d))
                self.assertEqual(os.listdir(d), [])
            self.assertTrue(os.path.exists(os.path.join(out, "stdout.txt")))

    def test_creates_missing(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = os.path.join(tmp, "new", "run")
            native_replay.fresh_state_dirs(out)
            for sub in native_replay.STATE_DIRS:
                self.assertTrue(os.path.isdir(os.path.join(out, sub)))


if __name__ == "__main__":
    unittest.main()
