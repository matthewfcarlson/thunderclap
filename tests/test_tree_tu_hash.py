"""tools/tree_tu.py + tools/code_hash.py: the code hashes of equivalent blocks (docs/merge-once.md "Code hashes").

A temporary tree with one TU is compiled with MSVC 7.1 (tree_tu's compile; needs build/'s toolchain and the XBE, else
the compile tests are skipped) and, where LLVM's clang is found, with clang as `equiv.py --wine` compiles it:

  * a rename that keeps every target's address (a callee FUN_x -> Name_x, parameters, locals) -> ok;
  * `$L` labels renumbered (an EH function added before the block) -> ok;
  * a changed constant -> code_changed; a call to another address with identical bytes -> code_changed;
  * no hash recorded -> `unhashed` (a failure) outside config/code-hash-pending.txt, `pending` (reported, not a
    failure) for a TU listed there;
  * pin_text keeps a block's hashes through a re-pin; proves() accepts only a run of the code as it is now.

  build/venv/bin/python -m unittest tests/test_tree_tu_hash.py
"""
import json
import os
import shutil
import sys
import tempfile
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import tree_tu  # noqa: E402
import compare  # noqa: E402


def have_msvc():
    return os.path.exists(compare.XBE_PATH) and os.path.exists(compare.WIBO) and os.path.isdir(compare.MSVC)


def have_clang():
    try:
        import clang_probe
        return bool(clang_probe.tool("clang++"))
    except Exception:       # noqa: BLE001
        return False


HEAD = """#include "tree_prelude.h"
struct Obj { Obj(); ~Obj(); int v; };
void %(callee)s(int);
int FUN_00033000(int);
%(extra)s
"""
BLOCK_A = """// 0x00011000 FUN_00011000 (10 B): equivalent
%(pin_a)s
int FUN_00011000(int %(param)s) {
    %(callee)s(%(param)s);
    return %(param)s + %(k)d;
}
"""
BLOCK_B = """// 0x00011010 FUN_00011010 (10 B): equivalent
%(pin_b)s
int FUN_00011010(int x) {
    Obj %(local)s;
    %(local)s.v = FUN_00033000(x);
    %(callee)s(%(local)s.v);
    return %(local)s.v;
}
"""
EXTRA_EH = """int extra_eh(int x) {
    Obj a, b;
    a.v = FUN_00033000(x);
    b.v = FUN_00033000(a.v);
    return a.v + b.v;
}"""


def tu_text(callee="FUN_00022000", param="x", k=1, local="o", extra="", pin_a="", pin_b=""):
    d = dict(callee=callee, param=param, k=k, local=local, extra=extra, pin_a=pin_a, pin_b=pin_b)
    return HEAD % d + BLOCK_A % d + BLOCK_B % d


class Parsing(unittest.TestCase):
    def test_sym_line(self):
        m = tree_tu.SYM_LINE.match("// sym: $L#0@?f@@YAXXZ @0123456789ab @wba9876543210")
        self.assertEqual(m.group(1), "$L#0@?f@@YAXXZ")
        self.assertEqual(tree_tu.HASH_TOKEN.findall(m.group(2)), [("", "0123456789ab"), ("w", "ba9876543210")])
        m = tree_tu.SYM_LINE.match("// sym: @fast@8")     # (a fastcall name starts with @: still the pin)
        self.assertEqual((m.group(1), m.group(2)), ("@fast@8", ""))

    def test_pin_text_keeps_hashes(self):
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "t.cpp")
            with open(p, "w") as f:
                f.write("// 0x00011000 FUN_00011000 (10 B): equivalent\n// sym: ?old@@YAXXZ @0123456789ab @wba9876543210\n"
                        "void f() {}\n// 0x00011010 FUN_00011010 (10 B): equivalent\n// sym: ?g@@YAXXZ @00000000000a\n")
            text = tree_tu.pin_text(p, {"0x00011000": "?new@@YAXXZ"})
            self.assertIn("// sym: ?new@@YAXXZ @0123456789ab @wba9876543210\n", text)
            self.assertIn("// sym: ?g@@YAXXZ @00000000000a", text)      # (no record: the line stays)
            text = tree_tu.pin_text(p, {}, {"0x00011010": ("00000000000b", "00000000000c")})
            self.assertIn("// sym: ?g@@YAXXZ @00000000000b @w00000000000c", text)
            self.assertEqual(tree_tu.text_hashes(text)["0x00011000"], ("0123456789ab", "ba9876543210"))

    def test_proves(self):
        good = {"native": False, "status": "equivalent", "promotable": True,
                "tree_code": {"msvc": "0123456789ab", "n_inputs": 3000}}
        self.assertTrue(tree_tu.proves(good, "msvc", "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(good, "msvc", "0123456789ac")[0])           # other code
        self.assertFalse(tree_tu.proves(dict(good, promotable=False), "msvc", "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(dict(good, tree_code={"msvc": "0123456789ab", "n_inputs": 600}), "msvc",
                                        "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(dict(good, tree_code={"n_inputs": 3000}), "msvc", "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(good, "wine", "0123456789ab")[0])           # an MSVC run proves no clang code
        wine = {"native": True, "status": "equivalent", "level3": {"inputs_run": 600},
                "tree_code": {"wine": "aaaaaaaaaaaa", "n_inputs": 600, "x87_keep": 0}}
        self.assertTrue(tree_tu.proves(wine, "wine", "aaaaaaaaaaaa")[0])
        self.assertFalse(tree_tu.proves(dict(wine, tree_code=dict(wine["tree_code"], x87_keep=3)), "wine",
                                        "aaaaaaaaaaaa")[0])
        self.assertFalse(tree_tu.proves(dict(wine, status="mismatch"), "wine", "aaaaaaaaaaaa")[0])

    def test_failing(self):
        import collections
        c = collections.Counter()
        tree_tu.count_codes(c, {"code": "pending", "wine_code": "pending"})
        tree_tu.count_codes(c, {"code": "ok", "wine_code": "no_object"})
        self.assertEqual(tree_tu.failing(c), 0)
        tree_tu.count_codes(c, {"code": "changed", "wine_code": "ok", "code_changed": ["msvc"]})
        self.assertEqual(tree_tu.failing(c), 1)
        tree_tu.count_codes(c, {"code": "unhashed", "wine_code": "unhashed"})
        self.assertEqual(tree_tu.failing(c), 3)


@unittest.skipUnless(have_msvc(), "needs the MSVC toolchain under build/ and the XBE")
class Hashes(unittest.TestCase):
    wine = have_clang()

    def setUp(self):
        base = os.path.join(ROOT, "build") if os.path.isdir(os.path.join(ROOT, "build")) else None
        self.tmp = tempfile.TemporaryDirectory(dir=base)
        r = self.root = self.tmp.name
        os.makedirs(os.path.join(r, "include"))
        os.makedirs(os.path.join(r, "src", "game"))
        shutil.copy(os.path.join(ROOT, "include", "tree_prelude.h"), os.path.join(r, "include"))
        self.tu = os.path.join(r, "src", "game", "T.cpp")
        self.saved = tree_tu.PENDING, list(tree_tu._PENDING)
        tree_tu.PENDING = os.path.join(r, "pending.txt")
        tree_tu._PENDING.clear()

    def tearDown(self):
        tree_tu.PENDING = self.saved[0]
        tree_tu._PENDING[:] = self.saved[1]
        self.tmp.cleanup()

    def records(self, text):
        with open(self.tu, "w") as f:
            f.write(text)
        recs = tree_tu.check_tu(self.tu)
        if self.wine:
            tree_tu.with_wine(self.tu, recs)
        tree_tu.apply_pending(recs)
        return {r["addr"]: r for r in recs}

    def recorded(self, **kw):
        """The TU of KW with the code hashes of its code recorded (as `hash --init` / `--proven` write them)."""
        recs = self.records(tu_text(**kw))
        for r in recs.values():
            self.assertEqual(r["status"], "compiled", r)
        pins = {a: "// sym: " + r["symbol"] for a, r in recs.items()}
        hashes = {a: (r["code_hash"], r.get("wine_code_hash")) for a, r in recs.items()}
        tree_tu._write(self.tu, {a: r["symbol"] for a, r in recs.items()}, hashes)
        text = open(self.tu).read()
        for a, r in recs.items():
            self.assertIn(tree_tu.sym_line(r["symbol"], *hashes[a]), text)
        return pins, hashes

    def edited(self, pins, hashes, **kw):
        """The records of the TU of KW carrying the recorded pins and hashes."""
        lines = {a: tree_tu.sym_line(p[len("// sym: "):], *hashes[a]) for a, p in pins.items()}
        return self.records(tu_text(pin_a=lines["0x00011000"], pin_b=lines["0x00011010"], **kw))

    def assert_codes(self, recs, want):
        for a, st in want.items():
            self.assertEqual(recs[a]["code"], st, (a, recs[a]))
            if self.wine:
                self.assertEqual(recs[a]["wine_code"], st, (a, recs[a]))

    def test_rename_same_address_is_ok(self):
        pins, hashes = self.recorded()
        recs = self.edited(pins, hashes, callee="Spawn_00022000", param="value", local="guard")
        self.assert_codes(recs, {"0x00011000": "ok", "0x00011010": "ok"})
        self.assertNotIn("code_changed", recs["0x00011000"])

    def test_label_renumbering_is_ok(self):
        pins, hashes = self.recorded()
        recs = self.edited(pins, hashes, extra=EXTRA_EH)
        self.assert_codes(recs, {"0x00011000": "ok", "0x00011010": "ok"})

    def test_code_change_is_changed(self):
        pins, hashes = self.recorded()
        recs = self.edited(pins, hashes, k=2)
        self.assert_codes(recs, {"0x00011000": "changed", "0x00011010": "ok"})
        self.assertIn("msvc", recs["0x00011000"]["code_changed"])

    def test_other_callee_is_changed(self):
        # (the same bytes: a call's displacement is a relocation; only its target says it calls elsewhere)
        pins, hashes = self.recorded()
        recs = self.edited(pins, hashes, callee="FUN_00022010")
        self.assert_codes(recs, {"0x00011000": "changed", "0x00011010": "changed"})

    def test_missing_hash(self):
        recs = self.records(tu_text())
        self.assert_codes(recs, {"0x00011000": "unhashed"})
        with open(tree_tu.PENDING, "w") as f:
            f.write("src/game/T.cpp\n")
        tree_tu._PENDING.clear()
        recs = self.records(tu_text())
        self.assert_codes(recs, {"0x00011000": "pending", "0x00011010": "pending"})
        import collections
        c = collections.Counter()
        for r in recs.values():
            tree_tu.count_codes(c, r)
        self.assertEqual(tree_tu.failing(c), 0)
        self.assertEqual(c["code hash pending (msvc)"], 2)


if __name__ == "__main__":
    unittest.main()
