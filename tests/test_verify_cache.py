"""build_tree's verify cache (build3): the key covers everything a TU's check records depend on, and the records a
build reads back are the ones it would compute.

  build/venv/bin/python -m unittest tests.test_verify_cache                  # key tests (no compiler)
  HULK_TEST_VERIFY_COMPILE=N build/venv/bin/python -m unittest tests.test_verify_cache
      # also generates the tree from build/tree/state.json into a private directory, compiles its first N TUs (MSVC
      # under wibo, 2 workers) and checks: records without the cache == records with a cold cache == records with a
      # warm cache (all hits). A few minutes for N=30.
"""
import json
import os
import shutil
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import build_tree  # noqa: E402


class FakeXbe:
    data = b"xbe bytes"


class FakeVerifier:
    xbe = FakeXbe()


class Keys(unittest.TestCase):
    def setUp(self):
        build_tree._VERIFY_BASE[:] = []
        self.calls = []
        self._sk = build_tree.standalone_key
        build_tree.standalone_key = lambda src: "sa-" + src.replace("/", "_")
        self.rec = {"path": "src/game/a.cpp", "blocks": [{"addr": "0x00001000", "src": "matches/0x00001000.cpp", "mode": "merged",
                                                            "kind": "matches", "prefixes": ["?f@@"]}]}

    def tearDown(self):
        build_tree.standalone_key = self._sk
        build_tree._VERIFY_BASE[:] = []

    def key(self, rec=None, obj="abc.obj"):
        return build_tree.verify_key(FakeVerifier(), rec or self.rec, obj)

    def test_key_changes_with_each_input(self):
        k0 = self.key()
        self.assertEqual(k0, self.key())
        self.assertNotEqual(k0, self.key(obj="abd.obj"))
        self.assertNotEqual(k0, self.key(obj=None))
        rec = json.loads(json.dumps(self.rec))
        rec["blocks"][0]["mode"] = "wrapped"
        self.assertNotEqual(k0, self.key(rec))
        rec = json.loads(json.dumps(self.rec))
        rec["blocks"][0]["prefixes"] = ["?g@@"]
        self.assertNotEqual(k0, self.key(rec))
        rec = json.loads(json.dumps(self.rec))
        rec["path"] = "src/game/b.cpp"
        self.assertNotEqual(k0, self.key(rec))
        build_tree.standalone_key = lambda src: "sa2-" + src
        self.assertNotEqual(k0, self.key())

    def test_key_changes_with_xbe_and_verifier_code(self):
        k0 = self.key()
        build_tree._VERIFY_BASE[:] = []
        v = FakeVerifier()
        v.xbe = type("X", (), {"data": b"other xbe"})()
        self.assertNotEqual(k0, build_tree.verify_key(v, self.rec, "abc.obj"))
        # the verifier's own code is part of the base key
        build_tree._VERIFY_BASE[:] = []
        base = build_tree.verify_key_base(FakeVerifier())
        self.assertEqual(len(base), 40)
        self.assertEqual(base, build_tree.verify_key_base(FakeVerifier()))


class Records(unittest.TestCase):
    """Opt-in: real objects, real checks (HULK_TEST_VERIFY_COMPILE=N TUs)."""
    def test_records_identical_with_and_without_the_cache(self):
        n = int(os.environ.get("HULK_TEST_VERIFY_COMPILE", "0") or 0)
        if not n:
            self.skipTest("set HULK_TEST_VERIFY_COMPILE=N to compile N TUs and compare the records")
        import gen_tree
        tmp = tempfile.mkdtemp(prefix="verify-cache-")
        tree = os.path.join(tmp, "tree")
        os.makedirs(tree)
        shutil.copyfile(os.path.join(ROOT, "build/tree/state.json"), os.path.join(tree, "state.json"))
        gen_tree.TREE, gen_tree.STATE = tree, os.path.join(tree, "state.json")
        build_tree.TREE, build_tree.INCLUDE_DIR = tree, os.path.join(tree, "include")
        build_tree.VERIFY_CACHE = os.path.join(tmp, "verify")
        state = gen_tree.load_state()
        gen = gen_tree.generate(state)
        manifest = gen.manifest
        manifest["tus"] = [t for t in manifest["tus"] if t["blocks"]][:n]
        paths = [t["path"] for t in manifest["tus"]]
        results = build_tree.compile_all(paths, 2)
        self.assertTrue(any(results[p][0] for p in paths), "no TU compiled")
        build_tree.VERIFY_CACHE_ON = False
        a = build_tree.verify(gen, manifest, results, 2)
        build_tree.VERIFY_CACHE_ON = True
        b = build_tree.verify(gen, manifest, results, 2)
        self.assertEqual((build_tree.VERIFY_STATS["hits"], build_tree.VERIFY_STATS["misses"]), (0, len(paths)))
        c = build_tree.verify(gen, manifest, results, 2)
        self.assertEqual((build_tree.VERIFY_STATS["hits"], build_tree.VERIFY_STATS["misses"]), (len(paths), 0))
        self.assertEqual(json.dumps(a), json.dumps(b))
        self.assertEqual(json.dumps(a), json.dumps(c))
        self.assertEqual(a, c)
        print("verify cache: %d TUs, %d records identical" % (len(paths), len(a)))
        shutil.rmtree(tmp, ignore_errors=True)


if __name__ == "__main__":
    unittest.main()
