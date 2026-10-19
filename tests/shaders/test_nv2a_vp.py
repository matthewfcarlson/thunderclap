"""Tests for tools/nv2a_vp.py on synthetic programs written for these tests (no game data needed).

    build/venv/bin/python -m unittest discover -s tests/shaders -v

The last class reads the player's XBE when it is present (decoding checks only; nothing is printed or stored).
"""
import math
import os
import random
import struct
import sys
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import nv2a_vp as nv  # noqa: E402

FIX = os.path.join(os.path.dirname(__file__), "fixtures")


def consts(**regs):
    c = [[0.0] * 4 for _ in range(nv.N_CONST)]
    for k, v in regs.items():
        c[int(k[1:])] = list(v)
    return c


def inputs(**regs):
    v = [[0.0] * 4 for _ in range(16)]
    for k, val in regs.items():
        v[int(k[1:])] = list(val)
    return v


def run(text, v=None, c=None, **kw):
    prog = nv.assemble(text)
    return nv.run(prog, v or inputs(), c or consts(), **kw)


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]



def _read(path):
    with open(path) as f:
        return f.read()


class Encoding(unittest.TestCase):
    def test_fields_do_not_overlap_and_fit_dwords_1_to_3(self):
        used = [0, 0, 0, 0]
        for name, (w, b, n) in nv.FIELDS.items():
            mask = ((1 << n) - 1) << b
            self.assertLess(b + n, 33, name)
            self.assertEqual(used[w] & mask, 0, "field %s overlaps" % name)
            used[w] |= mask
        self.assertEqual(used[0], 0)                       # dword 0 carries nothing
        self.assertEqual(used[3], 0xFFFFFFFF)              # dword 3 is fully defined

    def test_random_instructions_round_trip(self):
        r = random.Random(7)
        for _ in range(500):
            w = [0, r.getrandbits(28), r.getrandbits(32), r.getrandbits(32)]
            w[1] = (w[1] & ~(0xF << 21)) | (r.randrange(14) << 21)  # a defined MAC op
            self.assertEqual(nv.encode(nv.decode(w)), w)

    def test_assemble_disassemble_round_trip(self):
        text = _read(os.path.join(FIX, "synth.vp"))
        prog = nv.assemble(text)
        listing = "\n".join(nv.disasm(prog))
        again = nv.assemble(listing)
        self.assertEqual([nv.encode(i) for i in prog], [nv.encode(i) for i in again])
        self.assertTrue(prog[-1].final)
        self.assertFalse(any(i.final for i in prog[:-1]))

    def test_blob_header_and_end_flag(self):
        prog = nv.assemble("mov oD0, v3\nmov oPos, v0")
        blob = nv.build_blob(prog)
        hdr, = struct.unpack_from("<I", blob)
        self.assertEqual(hdr & 0xFF, 0x78)
        self.assertEqual(hdr >> 16, 2)
        parsed = nv.parse_blob(blob, "t")
        self.assertEqual(nv.disasm(parsed), ["mov oD0, v3", "mov oPos, v0"])
        bad = bytearray(blob)
        bad[4 + 16 + 12] &= 0xFE                          # clear the last instruction's end flag
        with self.assertRaises(ValueError):
            nv.parse_blob(bytes(bad), "t")

    def test_assembler_rejects_what_the_hardware_cannot_encode(self):
        for text in ("mul r0, v0, v1",                    # two input registers
                     "mul r0, c[1], c[2]",                # two constants
                     "dp4 r0.x, v0, c[3] + rcp r2.x, c[3].x",   # a paired ILU writes r1 only
                     "add r0, v0, c[3] + rcp r1.x, v0.x",   # add and the ILU share operand C
                     "mov oT0, v0 + rcp oT1, v0.x",       # one output write per instruction
                     "frc r0, v0"):                       # no such operation
            with self.assertRaises(ValueError, msg=text):
                nv.assemble(text)


class Semantics(unittest.TestCase):
    def test_mov_swizzle_negate_and_mask(self):
        res = run("mov r0, -v1.wzyx\nmov oT0.xz, r0", inputs(v1=(1, 2, 3, 4)))
        self.assertEqual(res.outputs["oT0"], [-4.0, 0.0, -2.0, 0.0])
        self.assertEqual(res.written["oT0"], 0b1010)
        self.assertEqual(res.errors["oT0"], [0.0] * 4)    # moves are exact

    def test_replicated_swizzle_text(self):
        prog = nv.assemble("mov oT0, v1.y")
        self.assertEqual(prog[0].a.swz, (1, 1, 1, 1))

    def test_add_reads_a_and_c(self):
        res = run("add oT0, v1, c[100]", inputs(v1=(1, 2, 3, 4)), consts(c100=(10, 20, 30, 40)))
        self.assertEqual(res.outputs["oT0"], [11.0, 22.0, 33.0, 44.0])
        ins = nv.assemble("add oT0, v1, c[100]")[0]
        self.assertEqual((ins.a.mux, ins.c.mux), (nv.MUX_INPUT, nv.MUX_CONST))

    def test_mul_mad_float32_rounding(self):
        a, b, c = 1 / 3, 3.0, 1e-8
        res = run("mad oT0, v1, c[100], c[100].y", inputs(v1=(a, 0, 0, 0)), consts(c100=(b, c, 0, 0)))
        want = f32(f32(f32(a) * b) + f32(c))
        self.assertEqual(res.outputs["oT0"][0], want)
        self.assertGreater(res.errors["oT0"][0], 0)

    def test_dot_products(self):
        v = inputs(v1=(1, 2, 3, 4))
        c = consts(c100=(5, 6, 7, 8))
        self.assertEqual(run("dp3 oT0, v1, c[100]", v, c).outputs["oT0"], [38.0] * 4)
        self.assertEqual(run("dp4 oT0, v1, c[100]", v, c).outputs["oT0"], [70.0] * 4)
        self.assertEqual(run("dph oT0, v1, c[100]", v, c).outputs["oT0"], [46.0] * 4)

    def test_dst_min_max(self):
        v = inputs(v1=(9, 2, 3, 9))
        c = consts(c100=(9, 5, 9, 7))
        self.assertEqual(run("dst oT0, v1, c[100]", v, c).outputs["oT0"], [1.0, 10.0, 3.0, 7.0])
        self.assertEqual(run("min oT0, v1, c[100]", v, c).outputs["oT0"], [9.0, 2.0, 3.0, 7.0])
        self.assertEqual(run("max oT0, v1, c[100]", v, c).outputs["oT0"], [9.0, 5.0, 9.0, 9.0])

    def test_slt_sge_at_and_near_the_threshold(self):
        v = inputs(v1=(1, 2, 3, 4))
        c = consts(c100=(1, 1, 4, 4))
        self.assertEqual(run("sge oT0, v1, c[100]", v, c).outputs["oT0"], [1.0, 1.0, 0.0, 1.0])
        self.assertEqual(run("slt oT0, v1, c[100]", v, c).outputs["oT0"], [0.0, 0.0, 1.0, 0.0])
        # a computed operand within its rounding bound of the threshold makes the result ambiguous
        res = run("mul r0, v1, c[101]\nsge oT0, r0, c[100]", inputs(v1=(1 / 3, 0, 0, 0)),
                  consts(c100=(1.0, 0, 0, 0), c101=(3, 1, 1, 1)))
        self.assertTrue(math.isinf(res.errors["oT0"][0]))
        self.assertEqual(res.errors["oT0"][1], 0.0)

    def test_arl_and_relative_constants(self):
        text = "arl a0.x, v1.x\nmov oT0, c[a0.x+100]"
        c = consts(c102=(7, 7, 7, 7), c103=(8, 8, 8, 8))
        self.assertEqual(run(text, inputs(v1=(2.0, 0, 0, 0)), c).outputs["oT0"], [7.0] * 4)
        self.assertEqual(run(text, inputs(v1=(2.99, 0, 0, 0)), c).outputs["oT0"], [7.0] * 4)   # floor
        self.assertEqual(run(text, inputs(v1=(-0.5, 0, 0, 0)), consts(c99=(1, 1, 1, 1))).outputs["oT0"],
                         [1.0] * 4)
        self.assertIn("out of range", run(text, inputs(v1=(95.0, 0, 0, 0)), c).bad)

    def test_arl_near_an_integer_is_flagged(self):
        res = run("mul r0.x, v1.x, c[100].x\narl a0.x, r0.x\nmov oT0, c[a0.x+100]",
                  inputs(v1=(1 / 3, 0, 0, 0)), consts(c100=(3, 0, 0, 0)))
        self.assertIn("arl operand", res.bad)

    def test_rcp_rcc_rsq(self):
        res = run("rcp oT0, v1.y", inputs(v1=(0, 4, 0, 0)))
        self.assertEqual(res.outputs["oT0"], [0.25] * 4)
        self.assertEqual(run("rcp oT0, v1.x", inputs(v1=(1, 0, 0, 0))).outputs["oT0"], [1.0] * 4)
        self.assertEqual(run("rsq oT0, v1.x", inputs(v1=(-16, 0, 0, 0))).outputs["oT0"], [0.25] * 4)  # |x|
        big = run("rcc oT0, v1.x", inputs(v1=(1e-30, 0, 0, 0))).outputs["oT0"][0]
        self.assertAlmostEqual(big / nv.RCC_MAX, 1.0, places=5)
        neg = run("rcc oT0, v1.x", inputs(v1=(-1e30, 0, 0, 0))).outputs["oT0"][0]
        self.assertAlmostEqual(neg / -nv.RCC_MIN, 1.0, places=5)
        self.assertIn("not finite", run("rcp oT0, v1.x", inputs()).bad)

    def test_exp_log(self):
        e = run("exp oT0, v1.x", inputs(v1=(2.5, 0, 0, 0))).outputs["oT0"]
        self.assertEqual(e[:2] + [e[3]], [4.0, 0.5, 1.0])
        self.assertAlmostEqual(e[2], 2 ** 2.5, places=4)
        lg = run("log oT0, v1.x", inputs(v1=(-12.0, 0, 0, 0))).outputs["oT0"]
        self.assertEqual(lg[0], 3.0)
        self.assertEqual(lg[1], 1.5)
        self.assertAlmostEqual(lg[2], math.log2(12), places=5)

    def test_lit(self):
        def lit(x, y, w):
            return run("lit oT0, v1", inputs(v1=(x, y, 0, w))).outputs["oT0"]
        self.assertEqual(lit(0.5, 0.25, 2), [1.0, 0.5, 0.0625, 1.0])
        self.assertEqual(lit(-0.5, 0.25, 2), [1.0, 0.0, 0.0, 1.0])
        self.assertEqual(lit(0.5, -0.25, 2), [1.0, 0.5, 0.0, 1.0])
        self.assertEqual(lit(0.5, 0.5, 1000)[2], f32(0.5 ** nv.LIT_POWER_LIMIT))       # power clamped

    def test_paired_ilu_writes_r1_and_reads_the_old_state(self):
        text = ("mov r1, c[100]\n"
                "mul r1.x, r1, c[101] + rcp r1.y, r1.x\n"   # both read r1.x = 2 before either writes
                "mov oT0, r1")
        res = run(text, c=consts(c100=(2, 9, 9, 9), c101=(3, 1, 1, 1)))
        self.assertEqual(res.outputs["oT0"], [6.0, 0.5, 9.0, 9.0])
        ins = nv.assemble(text)[1]
        self.assertEqual((ins.out_r, ins.ilu_temp), (1, 1))

    def test_unpaired_ilu_writes_its_register(self):
        res = run("rcp r5.x, v1.x\nmov oT0, r5", inputs(v1=(8, 0, 0, 0)))
        self.assertEqual(res.outputs["oT0"][0], 0.125)

    def test_ilu_result_to_an_output(self):
        res = run("dp4 r0, v1, v1 + mov oFog.x, v1.y", inputs(v1=(1, 2, 3, 4)))
        self.assertEqual(res.outputs["oFog"][0], 2.0)

    def test_r12_reads_the_position_written_so_far(self):
        res = run("mov oPos, v0\nmov oT0, r12.wzyx", inputs(v0=(1, 2, 3, 4)))
        self.assertEqual(res.outputs["oT0"], [4.0, 3.0, 2.0, 1.0])

    def test_screen_epilogue_and_clip_position(self):
        text = _read(os.path.join(FIX, "synth.vp"))
        prog = nv.assemble(text)
        self.assertEqual(nv.screen_epilogue(prog), len(prog) - 2)
        c = consts(c58=(320, -240, 1, 0), c59=(320, 240, 0, 0), c96=(0, 0.5, 256, 1),
                   c100=(1, 0, 0, 0), c101=(0, 1, 0, 0), c102=(0, 0, 1, 0), c103=(0, 0, 0.5, 1),
                   c105=(1, 0, 0, 1))
        v = inputs(v0=(2, 4, 6, 1))
        clip = nv.run(prog, v, c, position="clip").outputs["oPos"]
        screen = nv.run(prog, v, c).outputs["oPos"]
        self.assertEqual(clip, [2.0, 4.0, 6.0, 4.0])
        self.assertEqual(screen, [320 + 2 * 320 / 4, 240 - 4 * 240 / 4, 6 / 4, 4.0])

    def test_error_bounds_grow_with_magnitude_and_stay_zero_for_moves(self):
        res = run("dp4 r0, v1, c[100]\nmov oT0, r0\nmov oT1, v1",
                  inputs(v1=(1e3, -1e3, 1, 1)), consts(c100=(1, 1, 1e-3, 1)))
        self.assertGreater(res.errors["oT0"][0], 1e3 * 2 ** -23)
        self.assertEqual(res.errors["oT1"], [0.0] * 4)

    def test_info(self):
        i = nv.info(nv.Program("s", nv.assemble(_read(os.path.join(FIX, "synth.vp")))))
        self.assertEqual(i["inputs"], [0, 1, 2, 3])
        self.assertEqual(i["relative_bases"], [110, 111])
        self.assertEqual(i["outputs"], {"oPos": "xyzw", "oD0": "xyzw", "oFog": "x", "oT0": "xyzw"})
        self.assertEqual(i["uninitialised_reads"], [])
        self.assertEqual(i["paired"], 2)


@unittest.skipUnless(os.path.exists(nv.XBE_PATH), "needs the player's XBE (isos/extracted/default.xbe)")
class GamePrograms(unittest.TestCase):
    """Decoding checks on the game's programs (read at run time; nothing about them is printed)."""

    def test_all_17_decode_and_round_trip(self):
        total = 0
        for name, _addr in nv.GAME_PROGRAMS:
            prog = nv.game_program(name)
            total += len(prog)
            self.assertEqual([nv.encode(i) for i in prog.instrs], prog.words, name)
            i = nv.info(prog)
            self.assertIn("oPos", i["outputs"], name)
            self.assertIsNotNone(i["screen_epilogue"], name)
            self.assertEqual(i["uninitialised_reads"], [], name)
            # the observations the format notes rely on
            for ins in prog.instrs:
                if ins.mac == "add":
                    self.assertNotEqual(ins.c.mux, 0, name)
                if ins.o_mask:
                    self.assertTrue(ins.o_is_out, name)   # no program writes constants
        self.assertEqual(total, 661)


if __name__ == "__main__":
    unittest.main()
