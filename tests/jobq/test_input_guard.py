"""Unit tests for the stale-input guard of Wine build jobs (guard1: tools/input_guard.py): fresh, stale-and-clean
(rebuilt), stale-and-dirty (refused), private inputs, workspaces, the host check and the library stamp scheme, on
throwaway git repositories. No hosts, compilers or game data needed.

  build/venv/bin/python -m unittest tests.jobq.test_input_guard     (from the repo root)
"""
import os
import subprocess
import sys
import tempfile
import time
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import input_guard as ig  # noqa: E402
import platform_libs as pl  # noqa: E402

SDL = "build/third_party/out/sdl-backends/win32"
PDDI = "build/third_party/out/pddi-win32/obj"


def put(root, rel, text):
    p = os.path.join(root, rel)
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, "w") as f:
        f.write(text)
    return p


def read(root, rel):
    with open(os.path.join(root, rel)) as f:
        return f.read()


def git(root, *args):
    subprocess.run(["git", "-c", "user.name=t", "-c", "user.email=t@t", "-c", "commit.gpgsign=false"] + list(args),
                   cwd=root, check=True, capture_output=True)


class Base(unittest.TestCase):
    def setUp(self):
        self.root = os.path.realpath(tempfile.mkdtemp())
        git(self.root, "init", "-q")
        put(self.root, ".gitignore", "build/\n")
        put(self.root, "config/data.json", '{"items": []}\n')
        put(self.root, "config/splits.json", '{"objects": []}\n')
        put(self.root, "tools/data_gen.py", "# gen\n")
        put(self.root, "src/platform/sdl/platform_events.cpp", "// events\n")
        put(self.root, "src/platform/sdl/audio/hulk_audio.cpp", "// audio\n")
        put(self.root, "src/platform/sdl/input/hulk_input.cpp", "// input\n")
        put(self.root, "src/platform/sdl/pddi/pddi.cpp", "// pddi\n")
        put(self.root, "src/platform/sdl/pddi/smoke/smoke_main.cpp", "// host test\n")
        git(self.root, "add", "-A")
        git(self.root, "commit", "-qm", "base")
        put(self.root, "build/functions.csv", "address,size,name\n")
        self.rebuilt = []
        self.saved = ig.guards
        gs = [g for g in self.saved() if g.name in ("data", "hulk_sdl.lib", "pddi")]
        for g in gs:
            g.rebuild = self.fake_rebuild(g)
        ig.guards = lambda: gs
        self.g = {g.name: g for g in gs}
        # the inputs as their producers leave them: built from the committed sources, stamped
        put(self.root, "build/data/src/game/A.data.cpp", "// data\n")
        put(self.root, SDL + "/hulk_sdl.lib", "lib")
        put(self.root, PDDI + "/pddi.obj", "obj")
        for name, d in (("data", "build/data/src"), ("hulk_sdl.lib", SDL), ("pddi", PDDI)):
            ig.stamp(self.g[name], os.path.join(self.root, d), ig.View(self.root), self.root)

    def tearDown(self):
        ig.guards = self.saved
        subprocess.run(["rm", "-rf", self.root])

    def fake_rebuild(self, g):
        def rebuild(log):
            self.rebuilt.append(g.name)
        return rebuild

    def local_dir(self, d):
        return os.path.join(self.root, d)

    def submit(self, ws=None, live=(), private=(), local_dir=None, **kw):
        logs = []
        res, probs = ig.check_submit(ws or self.root, list(live), local_dir or self.local_dir, set(private), root=self.root,
                                     log=logs.append, **kw)
        return {r["name"]: r for r in res}, probs, logs


class Submit(Base):
    def test_fresh(self):
        res, probs, _ = self.submit()
        self.assertEqual(probs, [])
        self.assertEqual({n: r["state"] for n, r in res.items()}, {"data": "fresh", "hulk_sdl.lib": "fresh", "pddi": "fresh"})
        self.assertEqual(self.rebuilt, [])

    def test_stale_clean_is_rebuilt(self):
        put(self.root, "config/data.json", '{"items": [1]}\n')
        git(self.root, "commit", "-qam", "data change")
        res, probs, logs = self.submit()
        self.assertEqual(probs, [])
        self.assertEqual(self.rebuilt, ["data"])
        self.assertEqual((res["data"]["state"], res["data"]["why"]), ("fresh", "rebuilt"))
        self.assertTrue(any("config/data.json" in m and "rebuilding" in m for m in logs), logs)
        # the stamp now names the committed sources: a second submit does nothing
        self.rebuilt.clear()
        self.assertEqual(self.submit()[1], [])
        self.assertEqual(self.rebuilt, [])

    def test_stale_dirty_is_refused(self):
        put(self.root, "config/data.json", '{"items": [2]}\n')        # another agent's work in progress
        res, probs, _ = self.submit()
        self.assertEqual(self.rebuilt, [])
        self.assertEqual(len(probs), 1)
        self.assertIn("build/data/src", probs[0])
        self.assertIn("config/data.json", probs[0])
        self.assertIn("uncommitted", probs[0])
        self.assertIn("--data-src", probs[0])
        self.assertIn("--allow-stale", probs[0])

    def test_refused_submit_rebuilds_nothing(self):
        put(self.root, "src/platform/sdl/audio/hulk_audio.cpp", "// audio 2\n")
        git(self.root, "commit", "-qam", "audio change")                 # clean: hulk_sdl.lib could be rebuilt
        put(self.root, "config/data.json", '{"items": [5]}\n')          # dirty: the data TUs cannot
        res, probs, _ = self.submit()
        self.assertEqual(len(probs), 1)
        self.assertEqual(self.rebuilt, [])
        self.assertIn("not rebuilt", res["hulk_sdl.lib"]["why"])
        res, probs, _ = self.submit(allow_stale=True)                    # --allow-stale: the clean one is rebuilt
        self.assertEqual(len(probs), 1)
        self.assertEqual(self.rebuilt, ["hulk_sdl.lib"])

    def test_untracked_source_is_dirty(self):
        put(self.root, "src/platform/sdl/input/hulk_session.cpp", "// new\n")
        res, probs, _ = self.submit()
        self.assertEqual(self.rebuilt, [])
        self.assertEqual(res["data"]["state"], "fresh")
        self.assertEqual(res["hulk_sdl.lib"]["state"], "stale")
        self.assertIn("src/platform/sdl/input/hulk_session.cpp", res["hulk_sdl.lib"]["changed"])
        self.assertEqual(len(probs), 1)
        self.assertIn("--sdl-src", probs[0])
        self.assertIn("?? src/platform/sdl/input/hulk_session.cpp", probs[0])

    def test_dirty_elsewhere_does_not_block_a_clean_rebuild(self):
        put(self.root, "src/platform/sdl/input/hulk_input.cpp", "// input 2\n")
        git(self.root, "commit", "-qam", "input change")
        put(self.root, "src/platform/sdl/pddi/smoke/smoke_main.cpp", "// edited host test (not a pddi source)\n")
        put(self.root, "tools/other.py", "# unrelated work in progress\n")
        res, probs, _ = self.submit()
        self.assertEqual(probs, [])
        self.assertEqual(self.rebuilt, ["hulk_sdl.lib"])
        self.assertEqual(res["pddi"]["state"], "fresh")

    def test_pddi_and_top_level_sources(self):
        put(self.root, "src/platform/sdl/platform_events.cpp", "// events 2\n")    # counts for the library and pddi
        git(self.root, "commit", "-qam", "events")
        res, probs, _ = self.submit()
        self.assertEqual(probs, [])
        self.assertEqual(sorted(self.rebuilt), ["hulk_sdl.lib", "pddi"])

    def test_private_stale_is_refused_not_rebuilt(self):
        priv = os.path.join(self.root, "build/guard-test/data-src")
        put(priv, "game/A.data.cpp", "// data\n")
        ig.stamp(self.g["data"], priv, ig.View(self.root), self.root)
        put(self.root, "config/data.json", '{"items": [3]}\n')
        git(self.root, "commit", "-qam", "data change")
        ld = lambda d: priv if d == "build/data/src" else self.local_dir(d)  # noqa: E731
        res, probs, _ = self.submit(private={"build/data/src"}, local_dir=ld)
        self.assertEqual(self.rebuilt, [])
        self.assertEqual(len(probs), 1)
        self.assertIn("private", probs[0])
        self.assertIn("build/guard-test/data-src", probs[0])

    def test_private_unstamped_is_a_warning(self):
        priv = os.path.join(self.root, "build/guard-test/data-src")
        put(priv, "game/A.data.cpp", "// data\n")
        ld = lambda d: priv if d == "build/data/src" else self.local_dir(d)  # noqa: E731
        res, probs, logs = self.submit(private={"build/data/src"}, local_dir=ld)
        self.assertEqual(probs, [])
        self.assertEqual(res["data"]["state"], "unstamped")
        self.assertTrue(any("WARNING" in m for m in logs))

    def test_shared_unstamped_data_is_stale(self):
        os.unlink(os.path.join(self.root, "build/data/src/.srchash"))
        res, probs, _ = self.submit()
        self.assertEqual(probs, [])
        self.assertEqual(self.rebuilt, ["data"])

    def test_workspace_with_other_sources_is_refused(self):
        ws = os.path.join(self.root, "build/ws")
        for rel in ("config/data.json", "config/splits.json", "tools/data_gen.py"):
            put(ws, rel, read(self.root, rel))
        put(ws, "config/data.json", '{"items": ["ws"]}\n')
        res, probs, _ = self.submit(ws=ws)
        self.assertEqual(self.rebuilt, [])
        data = [p for p in probs if "build/data/src" in p]
        self.assertEqual(len(data), 1)
        self.assertIn("workspace", data[0])

    def test_live_paths_come_from_the_checkout(self):
        ws = os.path.join(self.root, "build/ws")
        put(ws, "tools/data_gen.py", "# an old copy\n")
        put(ws, "config/data.json", read(self.root, "config/data.json"))
        put(ws, "config/splits.json", read(self.root, "config/splits.json"))
        self.assertEqual(self.submit(ws=ws)[0]["data"]["state"], "stale")
        self.assertEqual(self.submit(ws=ws, live=["tools"], rebuild=False)[0]["data"]["state"], "fresh")

    def test_rebuild_off(self):
        put(self.root, "config/data.json", '{"items": [4]}\n')
        git(self.root, "commit", "-qam", "data change")
        res, probs, _ = self.submit(rebuild=False)
        self.assertEqual(self.rebuilt, [])
        self.assertEqual(len(probs), 1)

    def test_local_input_file_counts(self):
        put(self.root, "build/functions.csv", "address,size,name\n0x1,1,f\n")
        res, probs, _ = self.submit()
        self.assertEqual(res["data"]["state"], "fresh")
        self.assertEqual(self.rebuilt, ["data"])

    def test_pddi_unstamped_by_mtime(self):
        os.unlink(os.path.join(self.root, PDDI, ".srchash"))
        old = time.time() - 3600
        for dp, _, fns in os.walk(os.path.join(self.root, "src")):
            for f in fns:
                os.utime(os.path.join(dp, f), (old, old))
        res, probs, _ = self.submit()
        self.assertEqual(res["pddi"]["state"], "fresh")
        self.assertTrue(os.path.exists(os.path.join(self.root, PDDI, ".srchash")))      # stamped now
        os.unlink(os.path.join(self.root, PDDI, ".srchash"))
        os.utime(os.path.join(self.root, PDDI, "pddi.obj"), (old - 60, old - 60))
        res, probs, _ = self.submit()
        self.assertEqual(self.rebuilt, ["pddi"])


class Host(Base):
    def test_host_check(self):
        lin = os.path.join(self.root, "build/lineage")
        for rel in ("config/data.json", "config/splits.json", "tools/data_gen.py", "src/platform/sdl/platform_events.cpp",
                    "src/platform/sdl/audio/hulk_audio.cpp", "src/platform/sdl/input/hulk_input.cpp",
                    "src/platform/sdl/pddi/pddi.cpp"):
            put(lin, rel, read(self.root, rel))
        st = {r["name"]: r["state"] for r in ig.host_check(lin, self.root)}
        self.assertEqual(st, {"data": "fresh", "hulk_sdl.lib": "fresh", "pddi": "fresh"})
        put(lin, "src/platform/sdl/input/hulk_session.cpp", "// the job has a new source\n")
        res = {r["name"]: r for r in ig.host_check(lin, self.root)}
        self.assertEqual(res["hulk_sdl.lib"]["state"], "stale")
        self.assertIn("hulk_session.cpp", res["hulk_sdl.lib"]["message"])
        self.assertEqual(res["pddi"]["state"], "fresh")
        os.unlink(os.path.join(self.root, "build/data/src/.srchash"))
        res = {r["name"]: r for r in ig.host_check(lin, self.root)}
        self.assertEqual(res["data"]["state"], "unstamped")       # (an input shipped before the guard: not judged)


class Scheme(unittest.TestCase):
    def test_library_stamp_matches_platform_libs(self):
        """A library's stamp is the hash wine_link (platform_libs.state) compares: both schemes must agree."""
        root = os.path.realpath(tempfile.mkdtemp())
        try:
            plat = os.path.join(root, "src/platform/sdl")
            for rel in ("hulk_sdl_api.h", "audio/a.cpp", "audio/b.h", "input/x/y.cpp", "replay/r.cpp", "net/n.cpp",
                        "audio/old.cpp.orig"):
                put(plat, rel, rel)
            g = ig.PlatformLib("sdl-backends/win32/hulk_sdl.lib", ["audio", "input", "replay"], [], ["wine_sdl.py"], False)
            dg, per = ig.digest(g.files(ig.View(root), root), g.base)
            self.assertEqual(dg, pl.source_hash(["audio", "input", "replay"], plat=plat))
            self.assertNotIn("src/platform/sdl/net/n.cpp", per)
            self.assertNotIn("src/platform/sdl/audio/old.cpp.orig", per)
        finally:
            subprocess.run(["rm", "-rf", root])


if __name__ == "__main__":
    unittest.main()
