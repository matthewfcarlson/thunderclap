"""Unit tests for the binding-map key (fix1: tools/wine_link.py map_key, tools/wine_build_run.py map_key_reuse) and the
platform library stamps (tools/platform_libs.py): no hosts or tree needed.

  build/venv/bin/python -m unittest tests.jobq.test_map_key     (from the repo root)
"""
import json
import os
import sys
import tempfile
import time
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import platform_libs as pl  # noqa: E402
import wine_build_run as nb  # noqa: E402


def put(root, rel, text):
    p = os.path.join(root, rel)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w") as f:
        f.write(text)
    return p


# a tree TU of two blocks (the key reads a function's text from its block: tools/tree_index.py)
TU = "// 0x00000001 f (4 B): matches\nint f() { return h(); }\n// 0x00000002 g (4 B): equivalent\n%sint g();\n"


class MapKey(unittest.TestCase):
    """map_key over a fake tree: names decide, an equivalent's code positions don't."""

    def setUp(self):
        import wine_link
        self.wl = wine_link
        self.saved = (wine_link.tree_checks, wine_link.tree_objects, wine_link._obj_fingerprint, wine_link.TREE)
        self.root = tempfile.mkdtemp()
        put(self.root, "a.cpp", TU % "")
        self.checks = [{"addr": "0x00000001", "kind": "matches", "status": "match", "symbol": "?f@@YAHXZ", "tu": "a.cpp",
                        "src": "matches/0x1.cpp"},
                       {"addr": "0x00000002", "kind": "equivalent", "status": "compiled", "symbol": "?g@@YAHXZ",
                        "tu": "a.cpp", "src": "equivalent/0x2.cpp"}]
        self.fp = {"undefined": ["?h@@YADXZ"],
                   "fns": {"?f@@YAHXZ": {"pos": "p1", "names": ["?h@@YADXZ"]},
                           "?g@@YAHXZ": {"pos": "q1", "names": ["?h@@YADXZ"]}}}
        wine_link.tree_checks = lambda: self.checks
        wine_link.tree_objects = lambda tus: {t: "obj" for t in tus}
        wine_link._obj_fingerprint = lambda obj: self.fp
        wine_link.TREE = self.root

    def tearDown(self):
        (self.wl.tree_checks, self.wl.tree_objects, self.wl._obj_fingerprint, self.wl.TREE) = self.saved

    def key(self):
        return json.loads(json.dumps(self.wl.map_key()))["key"]

    def test_unchanged_and_body_only_edit_keep_the_key(self):
        k = self.key()
        self.assertEqual(k, self.key())
        self.fp["fns"]["?g@@YAHXZ"]["pos"] = "q2"           # an equivalent's body moved its call
        self.assertEqual(k, self.key())

    def test_renamed_callee_changes_the_key(self):          # `char h()` -> `int h()`
        k = self.key()
        self.fp["undefined"] = ["?h@@YAHXZ"]
        self.fp["fns"]["?g@@YAHXZ"]["names"] = ["?h@@YAHXZ"]
        self.assertNotEqual(k, self.key())

    def test_renamed_definition_changes_the_key(self):      # extern "C" or a new return type on the function itself
        k = self.key()
        self.checks[1]["symbol"] = "_g"
        self.fp["fns"]["_g"] = self.fp["fns"].pop("?g@@YAHXZ")
        self.assertNotEqual(k, self.key())

    def test_match_positions_and_status_count(self):
        k = self.key()
        self.fp["fns"]["?f@@YAHXZ"]["pos"] = "p2"
        k2 = self.key()
        self.assertNotEqual(k, k2)
        self.checks[1]["status"] = "wrapped"
        self.assertNotEqual(k2, self.key())

    def test_equiv_map_lines_count(self):
        k = self.key()
        put(self.root, "a.cpp", TU % "// equiv-map: ?h@@YADXZ = 0x00001234\n")      # (in the block, merge-once (d))
        self.assertNotEqual(k, self.key())


class MapKeyReuse(unittest.TestCase):
    """wine_build_run.map_key_reuse with a stand-in `wine_link.py --map-key`."""

    def setUp(self):
        self.lin, self.out = tempfile.mkdtemp(), tempfile.mkdtemp()
        self.now = os.path.join(self.lin, "now.json")
        put(self.lin, "tools/wine_link.py",
            "import shutil, sys\nassert sys.argv[1] == '--map-key'\nshutil.copyfile(%r, sys.argv[2])\n" % self.now)
        self.bj = put(self.lin, "build/native/bindings.json", "{}")

    def keys(self, saved, now, bindings_sha=None):
        if saved is not None:
            saved = dict(saved, bindings_sha1=bindings_sha or nb.sha_file(self.bj))
            put(self.lin, "build/native/mapkey.json", json.dumps(saved))
        put(self.lin, "now.json", json.dumps(now) if now is not None else "")
        return nb.map_key_reuse(sys.executable, dict(os.environ), self.lin, self.out)

    def test_same_key_reuses(self):
        k = {"version": 1, "key": "a", "parts": {"x": "1"}}
        r, why, _ = self.keys(k, k)
        self.assertTrue(r, why)

    def test_changed_key_remaps_and_names_the_part(self):
        r, why, _ = self.keys({"version": 1, "key": "a", "parts": {"x": "1", "y": "2"}},
                              {"version": 1, "key": "b", "parts": {"x": "1", "y": "3"}})
        self.assertFalse(r)
        self.assertIn("1 parts (y)", why)

    def test_no_saved_key_or_other_map_or_no_tool_remaps(self):
        k = {"version": 1, "key": "a", "parts": {}}
        self.assertFalse(self.keys(None, k)[0])                        # map made by an older wine_link
        self.assertFalse(self.keys(k, k, bindings_sha="0" * 40)[0])    # the key belongs to another bindings.json
        self.assertFalse(self.keys(k, None)[0])                        # --map-key failed / older tools


class PlatformLibs(unittest.TestCase):
    def setUp(self):
        self.plat, self.out = tempfile.mkdtemp(), tempfile.mkdtemp()
        put(self.plat, "top.h", "t")
        put(self.plat, "fs/a.cpp", "a")
        self.lib = put(self.out, "fs1/win32/hulk_fs.lib", "lib")

    def test_stamp_follows_content_not_mtime(self):
        old = time.time() - 1000
        os.utime(self.lib, (old, old))
        self.assertEqual(pl.state(self.lib, ["fs"], plat=self.plat), ("stale", "mtime"))
        self.assertEqual(pl.state(self.lib, ["fs"], plat=self.plat, trust_mtime=False), ("unknown", "no source stamp"))
        pl.write_stamp(self.lib, pl.source_hash(["fs"], plat=self.plat))
        self.assertEqual(pl.state(self.lib, ["fs"], plat=self.plat), ("fresh", "content hash"))
        put(self.plat, "fs/a.cpp", "a")                                # touched, same content (a lineage copy)
        self.assertEqual(pl.state(self.lib, ["fs"], plat=self.plat)[0], "fresh")
        put(self.plat, "fs/a.cpp", "b")
        self.assertEqual(pl.state(self.lib, ["fs"], plat=self.plat)[0], "stale")
        put(self.plat, "fs/a.cpp", "a")
        put(self.plat, "top.h", "t2")                                  # the top-level files count for every library
        self.assertEqual(pl.state(self.lib, ["fs"], plat=self.plat)[0], "stale")

    def test_stamp_fresh_stamps_only_mtime_fresh_libraries(self):
        new = time.time() + 1000
        os.utime(self.lib, (new, new))
        res = pl.stamp_fresh(self.out, plat=self.plat)
        self.assertEqual(res["fs1/win32/hulk_fs.lib"], "fresh")
        self.assertEqual(res["sdl-backends/win32/hulk_sdl.lib"], "missing")
        self.assertEqual(pl.read_stamp(self.lib), pl.source_hash(["fs"], plat=self.plat))


if __name__ == "__main__":
    unittest.main()
