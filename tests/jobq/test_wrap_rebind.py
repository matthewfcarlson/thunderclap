"""Regression test for div6's fix of the Wine link's wrappers (tools/wine_link.py wrap_rebind_plan): a probe
(HULK_TRACE_FUNCS / HULK_TRACE_EXIT), an entry or exit hook or the GameClock::Update wrapper must see every call of
the wrapped definition, also calls that name the definition itself (a C name such as `_FUN_000964d0` after x64-8's
name unification, a member called from its own merged TU). Before the fix only references bound by address went
through the wrapper, and native traces caught a few of the RNG accessor's callers.

  build/venv/bin/python -m unittest tests.jobq.test_wrap_rebind     (from the repo root)

The object test compiles a small i386 COFF object with the project's clang (skipped when it is missing).
"""
import os
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../tools"))
import wine_link as wl  # noqa: E402
import wine_host  # noqa: E402
import compare  # noqa: E402


class Plan(unittest.TestCase):
    def test_outer(self):
        w = {"_def": "_hulk_clock_update", "_hulk_clock_update": "_hulk_tr_00086450"}
        self.assertEqual(wl.wrapper_outer(w, "_def"), "_hulk_tr_00086450")
        self.assertEqual(wl.wrapper_outer(w, "_x"), "_x")
        self.assertEqual(wl.wrapper_outer({"a": "b", "b": "a"}, "a"), "b")      # (no loop forever)

    def test_plan_covers_defining_and_calling_objects(self):
        syms = {"def.obj": ({"_FUN_000964d0", "_other"}, {"_DAT_004dd6e4"}),
                "caller.obj": ({"_caller"}, {"_FUN_000964d0"}),
                "unrelated.obj": ({"_u"}, {"_v"})}
        w = {"_FUN_000964d0": "_hulk_tr_000964d0"}
        plan = wl.wrap_rebind_plan(syms, w)
        self.assertEqual(plan["def.obj"], {"_FUN_000964d0": ("_hulk_tr_000964d0", 0)})
        self.assertEqual(plan["caller.obj"], {"_FUN_000964d0": ("_hulk_tr_000964d0", 0)})
        self.assertNotIn("unrelated.obj", plan)


SRC = """extern "C" int g_dat;
extern "C" int FUN_000964d0(void) { return g_dat; }
extern "C" int caller(void) { return FUN_000964d0() + FUN_000964d0(); }
"""


class Object(unittest.TestCase):
    def test_calls_in_the_defining_object_go_to_the_wrapper(self):
        clang = os.path.join(wine_host.LLVM, "clang++")
        if not os.path.exists(clang):
            self.skipTest("no clang")
        d = tempfile.mkdtemp()
        src, obj, out = (os.path.join(d, n) for n in ("t.cpp", "t.obj", "t2.obj"))
        with open(src, "w") as f:
            f.write(SRC)
        r = subprocess.run([clang, "--target=i686-pc-windows-msvc", "-O0", "-c", src, "-o", obj],
                           capture_output=True, text=True)
        if r.returncode:
            self.skipTest("clang failed: " + r.stderr[:200])
        n = wine_host.retarget_relocs(obj, {"_FUN_000964d0": ("_hulk_tr_000964d0", 0)}, out, own=True)
        self.assertEqual(n, 2)      # both calls in caller
        c = compare.Coff(out)
        names = {s[0] for s in c.symbols}
        self.assertIn("_hulk_tr_000964d0", names)
        self.assertIn("_FUN_000964d0", names)      # the definition stays, for the wrapper's jmp


if __name__ == "__main__":
    unittest.main()
