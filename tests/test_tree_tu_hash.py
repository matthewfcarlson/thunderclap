"""tools/tree_tu.py + tools/code_hash.py: the code hashes of equivalent blocks (docs/merge-once.md "Code hashes").

A temporary tree with one TU is compiled with MSVC 7.1 (tree_tu's compile; needs build/'s toolchain and the XBE, else
the compile tests are skipped) and, where LLVM's clang is found, with clang as `equiv.py --wine` compiles it:

  * a rename that keeps every target's address (a callee FUN_x -> Name_x, parameters, locals) -> ok;
  * `$L` labels renumbered (an EH function added before the block) -> ok;
  * a changed constant -> code_changed; a call to another address with identical bytes -> code_changed;
  * no hash recorded -> `unhashed` (a failure);
  * pin_text keeps a block's hashes through a re-pin; proves() accepts only a run of the code as it is now;
  * (integ1) `@v` parsed and kept, proves() checks the checker view, the proof ledger and `unproven` (D37/D42).

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
                "level3": {"inputs_run": 3000, "inputs_inconclusive": 100},
                "tree_code": {"msvc": "0123456789ab", "n_inputs": 3000}}
        self.assertTrue(tree_tu.proves(good, "msvc", "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(good, "msvc", "0123456789ac")[0])           # other code
        self.assertFalse(tree_tu.proves(dict(good, promotable=False), "msvc", "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(dict(good, tree_code={"msvc": "0123456789ab", "n_inputs": 600}), "msvc",
                                        "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(dict(good, tree_code={"n_inputs": 3000}), "msvc", "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(good, "wine", "0123456789ab")[0])           # an MSVC run proves no clang code
        wine = {"native": True, "status": "equivalent", "promotable": True,
                "level3": {"inputs_run": 3000, "inputs_faulted": 100},
                "tree_code": {"wine": "aaaaaaaaaaaa", "n_inputs": 3000, "x87_keep": 0}}
        self.assertTrue(tree_tu.proves(wine, "wine", "aaaaaaaaaaaa")[0])
        self.assertFalse(tree_tu.proves(dict(wine, promotable=False), "wine", "aaaaaaaaaaaa")[0])   # (D151)
        self.assertFalse(tree_tu.proves(dict(wine, tree_code=dict(wine["tree_code"], x87_keep=3)), "wine",
                                        "aaaaaaaaaaaa")[0])
        self.assertFalse(tree_tu.proves(dict(wine, status="mismatch"), "wine", "aaaaaaaaaaaa")[0])
        # (integ1, D38 as run) a run the time budget cut or that drew fewer inputs than asked proves nothing
        cut = dict(good, level3={"inputs_run": 349, "inputs_inconclusive": 0, "time_budget_hit": True})
        ok_, why_ = tree_tu.proves(cut, "msvc", "0123456789ab")
        self.assertFalse(ok_)
        self.assertIn("time budget", why_)
        few = dict(good, level3={"inputs_run": 534, "inputs_inconclusive": 32, "inconclusive_cap_hit": True})
        self.assertFalse(tree_tu.proves(few, "msvc", "0123456789ab")[0])
        # (D62) 3,000 COMPARED: 2,999 compared of 6,000 drawn is short; 3,000 compared of 6,000 drawn proves
        short = dict(good, level3={"inputs_run": 2999, "inputs_inconclusive": 3001, "statuses": {"timeout": 3001}})
        ok_, why_ = tree_tu.proves(short, "msvc", "0123456789ab")
        self.assertFalse(ok_)
        self.assertIn("timeout 3001", why_)
        self.assertTrue(tree_tu.proves(dict(good, level3={"inputs_run": 3000, "inputs_inconclusive": 3000}), "msvc",
                                       "0123456789ab")[0])
        self.assertFalse(tree_tu.proves(dict(wine, level3={"inputs_run": 534, "time_budget_hit": True}), "wine",
                                        "aaaaaaaaaaaa")[0])

    def test_view_hash(self):
        # (integ1, D42) `@v` is the third hash; pin_text keeps it and writes it from a 3-tuple; a 2-tuple keeps it
        m = tree_tu.SYM_LINE.match("// sym: ?f@@YAXXZ @0123456789ab @wba9876543210 @v00000000000f")
        self.assertEqual(tree_tu.HASH_TOKEN.findall(m.group(2))[-1], ("v", "00000000000f"))
        with tempfile.TemporaryDirectory() as d:
            p = os.path.join(d, "t.cpp")
            with open(p, "w") as f:
                f.write("// 0x00011000 FUN_00011000 (10 B): equivalent\n// sym: ?f@@YAXXZ @0123456789ab @wba9876543210 "
                        "@v00000000000f\nvoid f() {}\n")
            self.assertEqual(tree_tu.scan(p)["blocks"][0]["vhash"], "00000000000f")
            text = tree_tu.pin_text(p, {"0x00011000": "?g@@YAXXZ"})
            self.assertIn("// sym: ?g@@YAXXZ @0123456789ab @wba9876543210 @v00000000000f\n", text)
            text = tree_tu.pin_text(p, {}, {"0x00011000": (None, None, "0000000000aa")})
            self.assertIn("@wba9876543210 @v0000000000aa", text)
            self.assertEqual(tree_tu.text_hashes(text, views=True)["0x00011000"],
                             ("0123456789ab", "ba9876543210", "0000000000aa"))
        self.assertNotEqual(tree_tu.view_digest("a", "b"), tree_tu.view_digest("a", None))

    def test_proves_view(self):
        good = {"native": False, "status": "equivalent", "promotable": True,
                "level3": {"inputs_run": 3000, "inputs_inconclusive": 100},
                "tree_code": {"msvc": "0123456789ab", "n_inputs": 3000, "view": "00000000000f"}}
        self.assertTrue(tree_tu.proves(good, "msvc", "0123456789ab", "00000000000f")[0])
        self.assertFalse(tree_tu.proves(good, "msvc", "0123456789ab", "00000000000e")[0])     # another view
        old = dict(good, tree_code={"msvc": "0123456789ab", "n_inputs": 3000})              # a run before views
        self.assertFalse(tree_tu.proves(old, "msvc", "0123456789ab", "00000000000f")[0])
        wine = {"native": True, "status": "equivalent", "level3": {"inputs_run": 600},
                "tree_code": {"wine": "aaaaaaaaaaaa", "n_inputs": 600, "x87_keep": 0}}
        self.assertFalse(tree_tu.proves(wine, "wine", "aaaaaaaaaaaa")[0])      # (D38) --wine needs 3,000 now
        # (rev3) a run with a rule not adopted (EQUIV_ON) or a default one off (EQUIV_OFF) proves nothing
        self.assertFalse(tree_tu.proves(dict(good, equiv_on=["nanpayload"]), "msvc", "0123456789ab", "00000000000f")[0])
        self.assertFalse(tree_tu.proves(dict(good, equiv_off=["vptrread"]), "msvc", "0123456789ab", "00000000000f")[0])
        import wine_gate
        w3 = {"native": True, "status": "equivalent", "level3": {"inputs_run": 2900}, "equiv_on": ["nanpayload"]}
        self.assertFalse(wine_gate.judge(w3)[0])
        self.assertTrue(wine_gate.judge(dict(w3, equiv_on=[]))[0])

    def test_ledger_and_marks(self):
        import collections
        with tempfile.TemporaryDirectory() as d:
            led = os.path.join(d, "ledger.jsonl")
            self.assertIsNone(tree_tu.ledger_index(led))
            rep = {"status": "equivalent", "promotable": True, "level3": {"inputs_run": 2900, "coverage":
                   {"edges_covered": 4, "edges_total": 4}}, "tree_code": {"n_inputs": 3000, "checker": "c", "job": "1"}}
            e = tree_tu.ledger_entry("0x00011000", "msvc", "0123456789ab", "00000000000f", rep, "src/game/T.cpp")
            self.assertEqual(tree_tu.ledger_append([e, e], led), 1)
            self.assertEqual(tree_tu.ledger_append([e], led), 0)
            idx = tree_tu.ledger_index(led)
            self.assertEqual(idx, {("0x00011000", "msvc", "0123456789ab", "00000000000f")})
            rec = {"blocks": [{"addr": "0x00011000", "vhash": tree_tu.view_digest("00000000000f", "00000000000e")}]}
            r = {"addr": "0x00011000", "kind": "equivalent", "code_hash": "0123456789ab", "wine_code_hash": "bbbbbbbbbbbb",
                 "wine_code": "ok", "code": "ok"}
            tree_tu.mark_views([r], rec, {"0x00011000": {"msvc": "00000000000f", "wine": "00000000000e"}}, idx)
            self.assertEqual((r["view"], r["proof"], r["unproven"]), ("ok", {"msvc": "proven", "wine": "unproven"},
                                                                      ["wine"]))
            c = collections.Counter()
            tree_tu.count_codes(c, r)
            self.assertEqual(tree_tu.failing(c), 1)
            self.assertEqual(tree_tu.failing(c, unproven=False), 0)
            r2 = dict(r, unchanged_since_ref=True)
            c = collections.Counter()
            tree_tu.count_codes(c, r2)
            self.assertEqual(tree_tu.failing(c), 0)     # (unproven before the change too: reported, not this change's)
            r3 = {"addr": "0x00011000", "kind": "equivalent", "code_hash": "0123456789ab", "wine_code_hash": None,
                  "wine_code": "no_object"}
            tree_tu.mark_views([r3], rec, {"0x00011000": {"msvc": "00000000000d", "wine": None}}, idx)
            self.assertEqual(r3["view"], "changed")
            c = collections.Counter()
            tree_tu.count_codes(c, r3)
            self.assertEqual(c["equivalent view changed"], 1)
            self.assertEqual(r3["proof"]["wine"], "n/a")

    def test_failing(self):
        import collections
        c = collections.Counter()
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

    def tearDown(self):
        self.tmp.cleanup()

    def records(self, text):
        with open(self.tu, "w") as f:
            f.write(text)
        recs = tree_tu.check_tu(self.tu)
        if self.wine:
            tree_tu.with_wine(self.tu, recs)
        return {r["addr"]: r for r in recs}

    def recorded(self, **kw):
        """The TU of KW with the code hashes of its code recorded (as `hash --proven` writes them)."""
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
        self.assert_codes(recs, {"0x00011000": "unhashed", "0x00011010": "unhashed"})
        import collections
        c = collections.Counter()
        for r in recs.values():
            tree_tu.count_codes(c, r)
        self.assertEqual(tree_tu.failing(c), 4 if self.wine else 2)



class FromLedger(unittest.TestCase):
    """(integ3, movers) `hash --from-ledger`: a block whose current code AND checker view have a ledger line in every mode
    is re-pinned with no run (MSVC 7.1's header-sensitive spill orders); any other block stays unproven."""

    def run_hash(self, ledger_lines, view_now=("vm", "vw"), extra=None, baseline=None):
        import json as _j
        from unittest import mock
        with tempfile.TemporaryDirectory() as d:
            led = os.path.join(d, "ledger.jsonl")
            with open(led, "w") as f:
                for a, m, c, v in ledger_lines:
                    f.write(_j.dumps({"addr": a, "mode": m, "code": c, "view": v}) + "\n")
                for e in extra or []:
                    f.write(_j.dumps(e) + "\n")
            rec = {"path": "src/game/T.cpp", "blocks": [{"addr": "0x00011000", "hash": "old000000000", "whash": "w00000000000",
                                                         "vhash": "v"}]}
            r = {"addr": "0x00011000", "kind": "equivalent", "symbol": "?f@@YAXXZ", "status": "compiled",
                 "code_hash": "new000000000", "wine_code_hash": "w00000000000", "code": "changed", "wine_code": "ok"}
            wrote = {}
            with mock.patch.object(tree_tu, "scan", lambda p: rec), \
                    mock.patch.object(tree_tu, "check_tu", lambda p, rec=None: [dict(r)]), \
                    mock.patch.object(tree_tu, "with_wine", lambda *a, **k: None), \
                    mock.patch.object(tree_tu, "views", lambda *a, **k: {"0x00011000": {"msvc": view_now[0], "wine": view_now[1]}}), \
                    mock.patch.object(tree_tu, "find_root", lambda p: None), \
                    mock.patch.object(tree_tu, "_write", lambda path, pins, hashes: wrote.update(hashes)), \
                    mock.patch.object(tree_tu, "load_unproven_baseline", lambda *a, **k: {"blocks": baseline or {}}):
                out = tree_tu.hash_proven("T.cpp", {}, ledger=led, unproven_accepted=baseline is not None)
            return out[0], wrote

    def test_indexes_agree(self):
        """(rev5) ledger_index and code_ledger_index read a ledger line by one rule (ledger_line_proves)."""
        import json as _j
        with tempfile.TemporaryDirectory() as d:
            led = os.path.join(d, "ledger.jsonl")
            lines = [{"addr": "0x1", "mode": "wine", "code": "c1", "view": "v", "status": "equivalent", "promotable": False},
                     {"addr": "0x2", "mode": "wine", "code": "c2", "view": "v", "status": "equivalent", "promotable": True},
                     {"addr": "0x3", "mode": "msvc", "code": "c3", "view": "v", "status": "fail"},
                     {"addr": "0x4", "mode": "msvc", "code": "c4", "view": "v"}]
            with open(led, "w") as f:
                f.write("".join(_j.dumps(e) + "\n" for e in lines))
            a = {(x[0], x[1], x[2]) for x in tree_tu.ledger_index(led)}
            b = tree_tu.code_ledger_index(led)
            self.assertEqual(a, b)
            self.assertEqual(b, {("0x2", "wine", "c2"), ("0x4", "msvc", "c4")})

    def test_unproven_accepted(self):
        """(integ3) --unproven-accepted: a mode listed in the unproven baseline with exactly the current code re-pins
        with the other mode proven; a listed old code, or a mode in neither, refuses; nothing goes to the ledger."""
        led = [("0x00011000", "msvc", "new000000000", "vm")]
        o, wrote = self.run_hash(led, baseline={"0x00011000": {"modes": {"wine": {"code": "w00000000000", "by": "unproven-accept"}}}})
        self.assertEqual(o["result"], "recorded")
        self.assertTrue(o["wine"].startswith("unproven-accepted"))
        self.assertNotIn("ledger", o)
        # (rev5) after the re-pin, verify's proof mark still says the wine mode is unproven (never proven)
        r = {"addr": "0x00011000", "kind": "equivalent", "code_hash": "new000000000", "wine_code_hash": "w00000000000",
             "code": "ok", "wine_code": "ok"}
        rec = {"blocks": [{"addr": "0x00011000", "vhash": tree_tu.view_digest("vm", "vw")}]}
        tree_tu.mark_views([r], rec, {"0x00011000": {"msvc": "vm", "wine": "vw"}},
                           {("0x00011000", "msvc", "new000000000", "vm")})
        self.assertEqual(r["proof"], {"msvc": "proven", "wine": "unproven"})
        o, wrote = self.run_hash(led, baseline={"0x00011000": {"modes": {"wine": {"code": "old0000000ww"}}}})
        self.assertTrue(o["result"].startswith("unproven"))
        self.assertEqual(wrote, {})
        o, wrote = self.run_hash([], baseline={"0x00011000": {"modes": {"wine": {"code": "w00000000000"}}}})
        self.assertTrue(o["result"].startswith("unproven"))        # msvc in neither the ledger nor the list
        self.assertEqual(wrote, {})

    def test_repins_only_when_every_mode_is_in_the_ledger(self):
        o, wrote = self.run_hash([("0x00011000", "msvc", "new000000000", "vm"), ("0x00011000", "wine", "w00000000000", "vw")])
        self.assertEqual(o["result"], "recorded")
        self.assertEqual(wrote["0x00011000"][0], "new000000000")
        o, wrote = self.run_hash([("0x00011000", "msvc", "new000000000", "vm")])              # wine not proven
        self.assertTrue(o["result"].startswith("unproven"))
        self.assertEqual(wrote, {})
        o, wrote = self.run_hash([("0x00011000", "msvc", "new000000000", "vm")],              # (rev5) a failed line
                                 extra=[{"addr": "0x00011000", "mode": "wine", "code": "w00000000000", "view": "vw",
                                         "status": "equivalent", "promotable": False}])
        self.assertTrue(o["result"].startswith("unproven"))
        self.assertEqual(wrote, {})
        o, wrote = self.run_hash([("0x00011000", "msvc", "new000000000", "other"),            # another checker view
                                  ("0x00011000", "wine", "w00000000000", "vw")])
        self.assertTrue(o["result"].startswith("unproven"))
        self.assertEqual(wrote, {})

if __name__ == "__main__":
    unittest.main()
