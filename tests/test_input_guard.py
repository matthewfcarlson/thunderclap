"""tools/input_guard.py: a stale verdict names the commit the input was built from and the one it was compared against."""
import os
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "tools"))
import input_guard as ig  # noqa: E402


class G(ig.Guard):
    name, what, input, stamp, flag = "t", "test input", "inp", ".stamp", "--t-src"
    pathspecs = ("src",)

    def sources(self, view):
        return ["src/a.txt"]


def sh(root, *a):
    return subprocess.run(["git"] + list(a), cwd=root, check=True, capture_output=True, text=True).stdout.strip()


class Commits(unittest.TestCase):
    def setUp(self):
        self.td = tempfile.TemporaryDirectory()
        r = self.root = os.path.realpath(self.td.name)
        sh(r, "init", "-q")
        sh(r, "config", "user.email", "t@example.invalid")
        sh(r, "config", "user.name", "t")
        os.makedirs(os.path.join(r, "src"))
        os.makedirs(os.path.join(r, "inp"))
        self.write("one")
        sh(r, "add", "src/a.txt")
        sh(r, "commit", "-qm", "one")
        with open(os.path.join(r, "inp/out"), "w") as f:
            f.write("built")

    def tearDown(self):
        self.td.cleanup()

    def write(self, text):
        with open(os.path.join(self.root, "src/a.txt"), "w") as f:
            f.write(text)

    def test_stale_names_both_commits(self):
        g, r = G(), self.root
        built = sh(r, "rev-parse", "--short=10", "HEAD")
        ig.stamp(g, os.path.join(r, "inp"), ig.View(r), r)
        self.write("two")
        sh(r, "commit", "-qam", "two")
        now = sh(r, "rev-parse", "--short=10", "HEAD")
        res = ig.check(g, os.path.join(r, "inp"), ig.View(r), r)
        self.assertEqual(res["state"], "stale")
        self.assertEqual(res["built_from"], {"commit": built, "dirty": False})
        msg = ig.describe(g, res, r, ig.checkout_commit(r, g.pathspecs))
        self.assertIn("built from %s" % built, msg)
        self.assertIn("compared against the job's sources at %s" % now, msg)
        host = [x for x in [ig.check(g, os.path.join(r, "inp"), ig.View(r), r)]][0]
        self.assertIn(now, ig.compared_text(host, {"commit": now}))

    def test_dirty_build_and_old_stamp(self):
        g, r = G(), self.root
        self.write("edited")
        ig.stamp(g, os.path.join(r, "inp"), ig.View(r), r)
        res = ig.check(g, os.path.join(r, "inp"), ig.View(r), r)
        self.assertEqual(res["state"], "fresh")
        self.assertTrue(res["built_from"]["dirty"])
        # a stamp written before built_from existed: still judged, named as unrecorded
        ig.write_stamp(g.stamp_path(os.path.join(r, "inp")), "0" * 40, {})
        res = ig.check(g, os.path.join(r, "inp"), ig.View(r), r)
        self.assertEqual(res["state"], "stale")
        self.assertNotIn("built_from", res)
        self.assertIn("unrecorded commit (stamp 000000000000)", ig.compared_text(res, None))

    def test_workspace_below_checkout_is_not_head(self):
        os.makedirs(os.path.join(self.root, "build/ws"))
        self.assertIsNone(ig.checkout_commit(os.path.join(self.root, "build/ws")))


if __name__ == "__main__":
    unittest.main()
