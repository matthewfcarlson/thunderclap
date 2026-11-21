#!/usr/bin/env python3
"""tools/ckpt_validate.py (ckpt1, D162/D163 R2-R4): the block diff ignores what only a relink changes (addresses,
alias names, objdump comments) and finds what the code changes; R2's window minimum holds within one reference and is
never summed across references; R4 denies by default. Synthetic images only (no game code)."""
import collections
import os
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ckpt_validate as v  # noqa: E402


def image(syms, insns, ranges, objs=None):
    """a stand-in for ckpt_validate.Image: syms [(va, name, section)], insns [(va, mnemonic, operands)]"""
    im = object.__new__(v.Image)
    im.syms = sorted((va, n, (objs or {}).get(va, "0123456789abcdef0123.obj"), sec) for va, n, sec in syms)
    im.addrs = [s[0] for s in im.syms]
    im.at = collections.defaultdict(list)
    im.by_name = {}
    for va, n, _o, _s in im.syms:
        im.at[va].append(n)
        im.by_name.setdefault(n, va)
    im._canon = {}
    im.by_sym = {n: va for va, n, _o, sec in im.syms if sec == 1}
    im.obj_of = {va: o for va, n, o, sec in im.syms if sec == 1}
    im.lo, im.hi = 0x10000000, 0x11000000
    im.insns = sorted((va, mn, v.strip_ops(ops)) for va, mn, ops in insns)    # (as Image reads the listing)
    im.iaddr = [x[0] for x in im.insns]
    im.ranges = ranges
    return im


def blocks(im, f, leaders):
    return v.normalise(im.body(f), leaders, im)


class T(unittest.TestCase):
    def test_relink_is_no_change(self):
        # the same code at other addresses, with another alias set for the same data item
        a = image([(0x10001000, "?f@@YAXXZ", 1), (0x10001100, "?g@@YAXXZ", 1), (0x10500000, "_DAT_0048e100", 3)],
                  [(0x10001000, "leal", "0x10500000, %eax"), (0x10001006, "je", "0x1000100a"),
                   (0x10001008, "calll", "0x10001100 <?g@@YAXXZ>"), (0x1000100a, "retl", "  # imm = 0x10500000")],
                  [(0x10001000, 0x10001010), (0x10001100, 0x10001110)])
        b = image([(0x10002000, "?f@@YAXXZ", 1), (0x10002200, "?g@@YAXXZ", 1), (0x10600000, "_hulk_d_0048e100", 3),
                   (0x10600000, "_DAT_0048e100", 3)],
                  [(0x10002000, "leal", "0x10600000, %eax"), (0x10002006, "je", "0x1000200a"),
                   (0x10002008, "calll", "0x10002200 <?g@@YAXXZ>"), (0x1000200a, "retl", "  # imm = 0x10600000")],
                  [(0x10002000, 0x10002010), (0x10002200, 0x10002210)])
        ca = blocks(a, 0x10001000, [0x10001000, 0x10001008, 0x1000100a])
        cb = blocks(b, 0x10002000, [0x10002000, 0x10002008, 0x1000200a])
        self.assertEqual(v.changed_blocks(ca, cb), [])

    def test_code_change_found(self):
        a = image([(0x10001000, "?f@@YAXXZ", 1)], [(0x10001000, "movl", "$1, %eax"), (0x10001005, "retl", "")],
                  [(0x10001000, 0x10001010)])
        b = image([(0x10001000, "?f@@YAXXZ", 1)], [(0x10001000, "movl", "$2, %eax"), (0x10001005, "retl", "")],
                  [(0x10001000, 0x10001010)])
        ca = blocks(a, 0x10001000, [0x10001000, 0x10001005])
        cb = blocks(b, 0x10001000, [0x10001000, 0x10001005])
        self.assertEqual(v.changed_blocks(ca, cb), [0x10001000])

    def test_modified_block_equal_to_another(self):
        # (rev5) the proof's second block now reads like its first: an ordered alignment pairs it with the control's
        # first block and loses the change; the shape-and-index diff finds it
        ctl = collections.OrderedDict([(1, ["movl $1, %eax", "je B2"]), (2, ["movl $2, %eax", "jmp B3"]),
                                       (3, ["movl $1, %eax", "je B4"]), (4, ["retl"])])
        prf = collections.OrderedDict([(1, ["movl $1, %eax", "je B2"]), (2, ["movl $1, %eax", "jmp B3"]),
                                       (3, ["movl $1, %eax", "je B4"]), (4, ["retl"])])
        self.assertEqual(v.changed_blocks(ctl, prf), [2])
        prf2 = collections.OrderedDict([(1, ["movl $1, %eax", "je B3"]), (2, ["movl $2, %eax", "jmp B3"]),
                                        (3, ["movl $1, %eax", "je B4"]), (4, ["retl"])])
        self.assertEqual(v.changed_blocks(ctl, prf2), [1, 2, 3, 4])      # another edge: the whole function

    def test_allowlist_names_tags(self):
        self.assertEqual(v.allow_entry("src/game/global/CCameraManager.cpp"), ("camera", ("camera",)))
        self.assertIsNone(v.allow_entry("src/engine/pure3d/Scenegraph_2.cpp"))       # rendering: no tag observes it
        self.assertEqual(v.allow_entry("src/engine/pure3d/ParticleSystemLoader.cpp")[0], "particles")
        self.assertIsNone(v.allow_entry("src/game/global/HUDOverlay_2.cpp"))
        self.assertIsNone(v.allow_entry("src/game/global/CSoundSystem.cpp"))
        self.assertIsNone(v.allow_entry("src/game/hulkfight/CSoundCommandTrack.cpp"))   # (an allowed directory, a sound TU)

    def test_windows_not_summed(self):
        # one changed block hit once in each of two references: no reference reaches MIN_WINDOWS
        refs = {"r1": {"name": "r1", "compared": [0, 3000]}, "r2": {"name": "r2", "compared": [0, 3000]}}
        one = bytearray(32)
        one[0] = 1
        import ckpt_refs
        best = {n: ckpt_refs.windows_in(one.hex(), 300, refs[n]) for n in refs}
        self.assertGreaterEqual(sum(best.values()), v.MIN_WINDOWS)   # (what a summing reader would wrongly accept)
        self.assertFalse(v.r2_ok(best))
        self.assertTrue(v.r2_ok({"r1": 1, "r2": 2}))
        self.assertFalse(v.r2_ok({"r1": 0}))

    def test_r4_default_deny(self):
        tree = {"?f@@YAXXZ": ("src/game/hulkfight/a.cpp", "equivalent", "0x1"), "?m@@YAXXZ": ("src/game/hulkfight/a.cpp", "matches", "0x2"),
                "?p@@YAXXZ": ("src/platform/xbox/core/p.cpp", "equivalent", "0x3"),
                "?i@@YAXXZ": ("src/game/hulkfight/a.cpp", "equivalent", "0x4"), "?h@@YAXXZ": ("src/game/hulkfight/a.cpp", "equivalent", "0x5"),
                "?s@@YAXXZ": ("src/engine/audio/s.cpp", "equivalent", "0x6"), "?c@@YAXXZ": ("src/game/hulkfight/a.cpp", "equivalent", "0x7")}
        syms = [(0x10001000, "?f@@YAXXZ", 1), (0x10001100, "?m@@YAXXZ", 1), (0x10001200, "?p@@YAXXZ", 1),
                (0x10001300, "?i@@YAXXZ", 1), (0x10001400, "?h@@YAXXZ", 1), (0x10001500, "?s@@YAXXZ", 1),
                (0x10001600, "?c@@YAXXZ", 1), (0x10009000, "_hulk_host_fopen", 1)]
        insns = [(0x10001000, "retl", ""), (0x10001100, "retl", ""), (0x10001200, "retl", ""),
                 (0x10001300, "calll", "*0x4(%eax)"), (0x10001400, "calll", "0x10009000"), (0x10001500, "retl", ""),
                 (0x10001600, "calll", "0x10001500"), (0x10009000, "retl", "")]
        ranges = [(0x10001000 + 0x100 * k, 0x10001080 + 0x100 * k) for k in range(7)] + [(0x10009000, 0x10009010)]
        im = image(syms, insns, ranges, objs={0x10009000: "host_crt.obj"})
        self.assertIsNone(v.classify(0x10001000, im, tree, {0x10001000}, {}))
        self.assertIn("matches", v.classify(0x10001100, im, tree, {0x10001100}, {}))
        self.assertIn("no allowlist entry", v.classify(0x10001200, im, tree, {0x10001200}, {}))
        self.assertIn("indirect", v.classify(0x10001300, im, tree, {0x10001300}, {}))
        self.assertIn("platform", v.classify(0x10001400, im, tree, {0x10001400}, {}))
        self.assertIn("reaches", v.classify(0x10001600, im, tree, {0x10001600}, {}))
        self.assertIn("not a tree block", v.classify(0x10009000, im, tree, {0x10009000}, {}))


if __name__ == "__main__":
    unittest.main()
