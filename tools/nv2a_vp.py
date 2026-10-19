#!/usr/bin/env python3
"""NV2A vertex programs: decoder, assembler and reference interpreter (docs/shaders.md).

  build/venv/bin/python tools/nv2a_vp.py list                    # the game's 17 programs (from the player's XBE)
  build/venv/bin/python tools/nv2a_vp.py census                  # the summary table of docs/shaders.md
  build/venv/bin/python tools/nv2a_vp.py dis skin                # a listing on this machine (never commit it)
  build/venv/bin/python tools/nv2a_vp.py dis skin --d3d          # constants as D3D registers (c0 = hardware c96)
  build/venv/bin/python tools/nv2a_vp.py dis --file prog.bin     # any blob: 4-byte header + 16-byte instructions
  build/venv/bin/python tools/nv2a_vp.py asm prog.vp -o prog.bin # our own text back into microcode
  build/venv/bin/python tools/nv2a_vp.py info skin --json        # registers read and written, constants, flags

Clean room: the format is written from public descriptions of the NV20-family vertex program engine (community
documentation of the 128-bit instruction word, public Direct3D 8 vs.1.1 documentation for the semantics of each
operation) and checked against our own observation of the game's programs (docs/shaders.md, "Format notes"). No vendor
code or material. The game's programs are game data: they are read from the player's XBE at run time; their bytes
and listings stay on the developer's machine (build/), never in tracked files.

The interpreter (`run`) evaluates a program on one vertex with float32 arithmetic (pure Python), and tracks for
every output component an absolute error bound: how far a correct float32 implementation of the same
mathematics may legitimately be from this result (rounding of each step, the documented precision of the ILU
operations, discontinuities such as `sge` or `arl` near their threshold). tools/shader_equiv.py compares a
hand-written bgfx shader against it with that bound; operations that are exact (mov, swizzle, negate, min, max,
sge/slt away from the threshold) carry no error, so a shader that only moves data must reproduce it bit for bit.
"""
import argparse
import json
import math
import os
import struct
import sys
from dataclasses import dataclass, field


ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")


def _read(path, mode):
    with open(path, mode) as f:
        return f.read()

# ---------------------------------------------------------------------------------------------------------------
# The instruction word
#
# Four little-endian dwords; dword 0 is always zero in the game's programs. Each field is (dword, low bit, width).
FIELDS = {
    "ilu":        (1, 25, 3),   # ILU (scalar/special) operation
    "mac":        (1, 21, 4),   # MAC (vector multiply-accumulate) operation
    "const":      (1, 13, 8),   # the one constant register this instruction reads (hardware index 0..191)
    "v":          (1, 9, 4),    # the one input (vertex attribute) register this instruction reads
    "a_neg":      (1, 8, 1),
    "a_swz_x":    (1, 6, 2), "a_swz_y": (1, 4, 2), "a_swz_z": (1, 2, 2), "a_swz_w": (1, 0, 2),
    "a_r":        (2, 28, 4),   # operand A's temporary register (when its mux selects a temporary)
    "a_mux":      (2, 26, 2),   # 1 temporary, 2 input, 3 constant
    "b_neg":      (2, 25, 1),
    "b_swz_x":    (2, 23, 2), "b_swz_y": (2, 21, 2), "b_swz_z": (2, 19, 2), "b_swz_w": (2, 17, 2),
    "b_r":        (2, 13, 4),
    "b_mux":      (2, 11, 2),
    "c_neg":      (2, 10, 1),
    "c_swz_x":    (2, 8, 2), "c_swz_y": (2, 6, 2), "c_swz_z": (2, 4, 2), "c_swz_w": (2, 2, 2),
    "c_r_hi":     (2, 0, 2),    # operand C's temporary register is split across dwords 2 and 3
    "c_r_lo":     (3, 30, 2),
    "c_mux":      (3, 28, 2),
    "mac_mask":   (3, 24, 4),   # temporary-register write mask of the MAC result (bit 3 = x ... bit 0 = w)
    "out_r":      (3, 20, 4),   # the temporary register written
    "ilu_mask":   (3, 16, 4),   # temporary-register write mask of the ILU result
    "o_mask":     (3, 12, 4),   # output-register write mask
    "o_is_out":   (3, 11, 1),   # 1: the output write goes to an output register; 0: to a constant register
    "o_addr":     (3, 3, 8),    # output register (or constant register) index
    "o_mux":      (3, 2, 1),    # which unit's result goes to the output: 0 MAC, 1 ILU
    "a0x":        (3, 1, 1),    # the constant index is relative to the address register a0.x
    "final":      (3, 0, 1),    # last instruction of the program
}

MAC_OPS = ["nop", "mov", "mul", "add", "mad", "dp3", "dph", "dp4", "dst", "min", "max", "slt", "sge", "arl"]
ILU_OPS = ["nop", "mov", "rcp", "rcc", "rsq", "exp", "log", "lit"]
# Which operands each MAC operation reads (observed: add reads A and C, not B; the ILU reads C).
MAC_ARGS = {"mov": "a", "mul": "ab", "add": "ac", "mad": "abc", "dp3": "ab", "dph": "ab", "dp4": "ab", "dst": "ab",
            "min": "ab", "max": "ab", "slt": "ab", "sge": "ab", "arl": "a"}
MUX_TEMP, MUX_INPUT, MUX_CONST = 1, 2, 3
OUTPUTS = {0: "oPos", 3: "oD0", 4: "oD1", 5: "oFog", 6: "oPts", 7: "oB0", 8: "oB1",
           9: "oT0", 10: "oT1", 11: "oT2", 12: "oT3"}
OUTPUT_INDEX = {v: k for k, v in OUTPUTS.items()}
N_CONST = 192           # NV2A constant file; Direct3D numbers them -96..95 (D3D c0 = hardware c96)
D3D_CONST_BIAS = 96
N_TEMP = 16             # r0..r11 are general; r12 reads back the oPos written so far
POS_ALIAS = 12
SWZ = "xyzw"
HEADER_TYPE = 0x78      # the blob header's low byte (observed in all 17 programs), version byte 0x20


def get(words, name):
    w, b, n = FIELDS[name]
    return (words[w] >> b) & ((1 << n) - 1)


def put(words, name, value):
    w, b, n = FIELDS[name]
    if value < 0 or value >= (1 << n):
        raise ValueError("%s=%d does not fit %d bits" % (name, value, n))
    words[w] = (words[w] & ~(((1 << n) - 1) << b)) | (value << b)


@dataclass
class Operand:
    mux: int = 0            # 0 unused, 1 temp, 2 input, 3 const
    reg: int = 0            # temp index (inputs and constants come from the instruction's v/const fields)
    swz: tuple = (0, 1, 2, 3)
    neg: bool = False


@dataclass
class Instr:
    mac: str = "nop"
    ilu: str = "nop"
    a: Operand = field(default_factory=Operand)
    b: Operand = field(default_factory=Operand)
    c: Operand = field(default_factory=Operand)
    v: int = 0
    const: int = 0
    a0x: bool = False
    out_r: int = 0
    mac_mask: int = 0
    ilu_mask: int = 0
    o_mask: int = 0
    o_is_out: bool = True
    o_addr: int = 0xFF
    o_mux: int = 0          # 0 MAC, 1 ILU
    final: bool = False

    @property
    def ilu_temp(self):
        """Temporary register the ILU writes: a paired ILU (MAC active too) always writes r1."""
        return 1 if self.mac != "nop" else self.out_r


def decode(words):
    words = list(words)
    ins = Instr()
    mac, ilu = get(words, "mac"), get(words, "ilu")
    if mac >= len(MAC_OPS):
        raise ValueError("unknown MAC op %d" % mac)
    ins.mac, ins.ilu = MAC_OPS[mac], ILU_OPS[ilu]
    for o in "abc":
        op = getattr(ins, o)
        op.mux = get(words, o + "_mux")
        op.neg = bool(get(words, o + "_neg"))
        op.swz = tuple(get(words, "%s_swz_%s" % (o, s)) for s in SWZ)
        op.reg = (get(words, "c_r_hi") << 2 | get(words, "c_r_lo")) if o == "c" else get(words, o + "_r")
    ins.v, ins.const, ins.a0x = get(words, "v"), get(words, "const"), bool(get(words, "a0x"))
    ins.out_r, ins.mac_mask, ins.ilu_mask = get(words, "out_r"), get(words, "mac_mask"), get(words, "ilu_mask")
    ins.o_mask, ins.o_is_out, ins.o_addr = get(words, "o_mask"), bool(get(words, "o_is_out")), get(words, "o_addr")
    ins.o_mux, ins.final = get(words, "o_mux"), bool(get(words, "final"))
    return ins


def encode(ins):
    w = [0, 0, 0, 0]
    put(w, "mac", MAC_OPS.index(ins.mac))
    put(w, "ilu", ILU_OPS.index(ins.ilu))
    for o in "abc":
        op = getattr(ins, o)
        put(w, o + "_mux", op.mux)
        put(w, o + "_neg", int(op.neg))
        for s, comp in zip(SWZ, op.swz):
            put(w, "%s_swz_%s" % (o, s), comp)
        if o == "c":
            put(w, "c_r_hi", op.reg >> 2)
            put(w, "c_r_lo", op.reg & 3)
        else:
            put(w, o + "_r", op.reg)
    put(w, "v", ins.v)
    put(w, "const", ins.const)
    put(w, "a0x", int(ins.a0x))
    put(w, "out_r", ins.out_r)
    put(w, "mac_mask", ins.mac_mask)
    put(w, "ilu_mask", ins.ilu_mask)
    put(w, "o_mask", ins.o_mask)
    put(w, "o_is_out", int(ins.o_is_out))
    put(w, "o_addr", ins.o_addr)
    put(w, "o_mux", ins.o_mux)
    put(w, "final", int(ins.final))
    return w


# ---------------------------------------------------------------------------------------------------------------
# Blobs: a 4-byte header (type 0x78, version 0x20, u16 instruction count), then 16 bytes per instruction
@dataclass
class Program:
    name: str
    instrs: list
    header: int = 0
    words: list = None

    def __len__(self):
        return len(self.instrs)


def parse_blob(data, name="?"):
    hdr, = struct.unpack_from("<I", data, 0)
    if hdr & 0xFF != HEADER_TYPE:
        raise ValueError("%s: header 0x%08x is not a vertex program (type 0x%02x)" % (name, hdr, HEADER_TYPE))
    n = hdr >> 16
    if len(data) < 4 + 16 * n:
        raise ValueError("%s: %d instructions need %d bytes, have %d" % (name, n, 4 + 16 * n, len(data)))
    words = [list(struct.unpack_from("<4I", data, 4 + 16 * i)) for i in range(n)]
    prog = Program(name, [decode(w) for w in words], hdr, words)
    finals = [i for i, ins in enumerate(prog.instrs) if ins.final]
    if finals != [n - 1]:
        raise ValueError("%s: end flag on %s, expected only the last of %d" % (name, finals, n))
    return prog


def build_blob(instrs):
    instrs = list(instrs)
    for i, ins in enumerate(instrs):
        ins.final = i == len(instrs) - 1
    out = struct.pack("<I", HEADER_TYPE | 0x20 << 8 | len(instrs) << 16)
    for ins in instrs:
        out += struct.pack("<4I", *encode(ins))
    return out


# ---------------------------------------------------------------------------------------------------------------
# The game's programs (read from the player's XBE; nothing of them is stored in the repo)
#
# FUN_00329430 (d3dSimpleShader.cpp in the tree, equivalent/0x00329430.cpp) registers these names with pointers
# into .data. The addresses are game code facts (our verified source), not program contents.
GAME_PROGRAMS = [
    ("skin", 0x4d4f40), ("skin_onebone", 0x4d5388), ("point_sprite", 0x4d5640), ("toon2", 0x4d5830),
    ("toon", 0x4d56d8), ("skin_toon", 0x4d5d70), ("refract", 0x4d5a08), ("skin_refract", 0x4d6048),
    ("spheremap", 0x4d64d0), ("environmap", 0x4d6878), ("bumpmap", 0x4d6b80), ("simple_multicbv", 0x4d6ce8),
    ("simple_proximity", 0x4d6f10), ("layered_multicbv", 0x4d70f8), ("layered_proximity", 0x4d7320),
    ("layered_lightmap_multicbv", 0x4d7508), ("layered_lightmap_proximity", 0x4d7730),
]


# Who selects each program and who uploads its constants: facts about the game's code, from our verified sources
# (docs/shaders.md, "Census"). `need`: what the shipped data needs (see the census for the evidence).
GAME_PROGRAM_NOTES = {
    "skin": ("FUN_00327860 (prim buffer stream): vertex flags bit 7 and bit 8", "FUN_00324270; bones "
             "d3dExtHardwareSkinning::vfunc_5", "yes: all 387 skinned prim groups (format 0x2191)"),
    "skin_onebone": ("FUN_00327860: bit 7 without bit 8", "FUN_00324270; bones d3dExtHardwareSkinning::vfunc_5",
                     "no prim group in the data (every skinned one has weights); keep"),
    "point_sprite": ("nothing (d3dPointSpriteShader slot 23 returns \"\")", "d3dPointSpriteShader", "no"),
    "toon2": ("d3dToon2VertexShader slots 4/23", "d3dToon2VertexShader", "no (class unused)"),
    "toon": ("d3dToonVertexShader slot 23", "d3dToonVertexShader", "no (class unused)"),
    "skin_toon": ("d3dToonVertexShader slot 23 (skinned)", "d3dToonVertexShader", "no (class unused)"),
    "refract": ("d3dRefractVertexShader slots 4/23", "d3dRefractVertexShader", "yes: 43 prim groups"),
    "skin_refract": ("d3dRefractVertexShader slot 23 (flag +0x7d)", "d3dRefractVertexShader",
                     "only if refract meets a skinned mesh at run time; keep"),
    "spheremap": ("d3dSpheremapVertexShader slots 4/23", "d3dSpheremapVertexShader", "no (class unused)"),
    "environmap": ("nothing (registered only)", "-", "no"),
    "bumpmap": ("d3dBumpMapVertexShader slots 4/23", "d3dBumpMapVertexShader", "no (class unused)"),
    "simple_multicbv": ("d3dSimpleShader slot 23 (param MCBV)", "d3dSimpleShader::vfunc_24, FUN_0032a5a0",
                        "unlikely: MCBV = 0 in all data"),
    "simple_proximity": ("d3dSimpleShader slot 23 (param CBVP)", "d3dSimpleShader::vfunc_24, "
                         "FUN_0032a5a0, FUN_0032a600", "unlikely: CBVP = 0 in all data"),
    "layered_multicbv": ("d3dLayeredShader / d3dLightMapShader slot 23 (MCBV)", "d3dLayeredShader",
                         "unlikely: MCBV = 0 in all data"),
    "layered_proximity": ("d3dLayeredShader / d3dLightMapShader slot 23 (CBVP)", "d3dLayeredShader",
                          "unlikely: CBVP = 0 in all data"),
    "layered_lightmap_multicbv": ("d3dLayeredLMapShader slot 23", "d3dLayeredLMapShader", "no (class unused)"),
    "layered_lightmap_proximity": ("d3dLayeredLMapShader slot 23", "d3dLayeredLMapShader", "no (class unused)"),
}


def _ranges(regs, prefix="c"):
    out, run = [], []
    for r in sorted(regs):
        if run and r == run[-1] + 1:
            run.append(r)
        else:
            if run:
                out.append(run)
            run = [r]
    if run:
        out.append(run)
    return ", ".join("%s%d" % (prefix, g[0]) if len(g) == 1 else "%s%d-%d" % (prefix, g[0], g[-1]) for g in out)


def _standard_epilogue(instrs, epi):
    """mul oPos.xyz, r12, c58 ... mad oPos.xyz, r12, r1.x, c59, with r1.x = rcc(r12.w) computed anywhere."""
    if epi is None:
        return False
    pos = [ins for ins in instrs[epi:] if ins.o_mask and ins.o_is_out and ins.o_addr == 0]
    rcc = [ins for ins in instrs if ins.ilu == "rcc" and ins.c.mux == MUX_TEMP and ins.c.reg == POS_ALIAS]
    return (len(pos) == 2 and len(rcc) == 1 and pos[0].mac == "mul" and pos[0].const == 58 and
            pos[1].mac == "mad" and pos[1].const == 59 and pos[0].o_mask == pos[1].o_mask == 0b1110)


def census(xbe_path=XBE_PATH):
    """One row per game program: shapes, registers, who selects it (no program contents)."""
    rows = []
    for name, addr in GAME_PROGRAMS:
        p = game_program(name, xbe_path)
        i = info(p)
        epi = i["screen_epilogue"]
        pre = info(Program("pre", p.instrs[:epi])) if epi is not None else i
        sel, consts, need = GAME_PROGRAM_NOTES[name]
        rows.append(dict(name=name, addr="0x%06x" % addr, instructions=i["instructions"], paired=i["paired"],
                         inputs=_ranges(i["inputs"], "v"),
                         outputs=" ".join("%s.%s" % kv if kv[1] != "xyzw" else kv[0]
                                          for kv in i["outputs"].items()),
                         constants=_ranges(pre["constants"]),
                         relative=_ranges(pre["relative_bases"]) or "-",
                         epilogue=_standard_epilogue(p.instrs, epi),
                         ops=i["ops"], selected_by=sel, constants_from=consts, needed=need))
    return rows


def game_program(name, xbe_path=XBE_PATH):
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    from xbe import Xbe
    addr = dict(GAME_PROGRAMS).get(name)
    if addr is None:
        raise SystemExit("no game program %r (have: %s)" % (name, ", ".join(n for n, _ in GAME_PROGRAMS)))
    if not os.path.exists(xbe_path):
        raise SystemExit("the player's XBE is not at %s" % xbe_path)
    x = Xbe(xbe_path)
    o = x.offset(addr)
    n = struct.unpack_from("<I", x.data, o)[0] >> 16
    prog = parse_blob(x.data[o:o + 4 + 16 * n], name)
    prog.addr = addr
    return prog


def load_program(spec):
    """A game program by name, a .bin blob, or a .vp text file of ours."""
    if os.path.exists(spec):
        if spec.endswith(".vp"):
            return Program(os.path.basename(spec), assemble(_read(spec, "r")))
        return parse_blob(_read(spec, "rb"), os.path.basename(spec))
    return game_program(spec)


# ---------------------------------------------------------------------------------------------------------------
# Text form: vs.1.1-style, one instruction per line; a paired ILU operation follows the MAC one after " + "
#   dp4 oPos.x, v0, c[96]
#   mul r0.xyz, r1, c[a0.x+100].w + rsq r1.w, c[100].x
#   rcp oFog.x, r2.z                     (ILU alone)
#   arl a0.x, v1.x
# A temporary write and an output write of the same result are written "r3.xy|oT0.xy" (one instruction does both).
def _mask_str(m):
    return "".join(c for i, c in enumerate(SWZ) if m & (8 >> i))


def _swz_str(swz):
    s = "".join(SWZ[c] for c in swz)
    if s == "xyzw":
        return ""
    if len(set(s)) == 1:
        return "." + s[0]
    return "." + s


def _src_str(ins, op, d3d=False):
    if op.mux == MUX_TEMP:
        r = "r%d" % op.reg
    elif op.mux == MUX_INPUT:
        r = "v%d" % ins.v
    elif op.mux == MUX_CONST:
        idx = ins.const - D3D_CONST_BIAS if d3d else ins.const
        r = ("c[a0.x%+d]" % idx) if ins.a0x else ("c[%d]" % idx)
    else:
        r = "?"
    return ("-" if op.neg else "") + r + _swz_str(op.swz)


def _dst_names(ins, unit):
    out = []
    if unit == "mac" and ins.mac_mask:
        out.append("r%d%s" % (ins.out_r, _dot_mask(ins.mac_mask)))
    if unit == "ilu" and ins.ilu_mask:
        out.append("r%d%s" % (ins.ilu_temp, _dot_mask(ins.ilu_mask)))
    if ins.o_mask and ins.o_mux == (0 if unit == "mac" else 1):
        if ins.o_is_out:
            reg = OUTPUTS.get(ins.o_addr, "o?%d" % ins.o_addr)
        else:
            reg = "c[%d]" % ins.o_addr
        out.append(reg + _dot_mask(ins.o_mask))
    return out


def _dot_mask(m):
    return "" if m == 15 else "." + _mask_str(m)


def disasm_instr(ins, d3d=False):
    parts = []
    if ins.mac != "nop":
        dst = _dst_names(ins, "mac")
        if ins.mac == "arl":
            dst = ["a0.x"]
        srcs = [_src_str(ins, getattr(ins, o), d3d) for o in MAC_ARGS[ins.mac]]
        parts.append("%s %s, %s" % (ins.mac, "|".join(dst) or "_", ", ".join(srcs)))
    if ins.ilu != "nop":
        dst = _dst_names(ins, "ilu")
        parts.append("%s %s, %s" % (ins.ilu, "|".join(dst) or "_", _src_str(ins, ins.c, d3d)))
    return " + ".join(parts) or "nop"


def disasm(prog, d3d=False):
    return [disasm_instr(i, d3d) for i in (prog.instrs if isinstance(prog, Program) else prog)]


def _parse_reg(tok):
    """'-c[a0.x+12].xxyw' -> dict(neg, kind, index, rel, swz/mask text)."""
    tok = tok.strip()
    neg = tok.startswith("-")
    if neg:
        tok = tok[1:]
    if tok.startswith("c["):
        end = tok.index("]")
        inner, rest = tok[2:end], tok[end + 1:]
        rel = inner.startswith("a0.x")
        idx = int(inner[4:] or 0) if rel else int(inner)
        kind = "c"
    else:
        name, _, rest = tok.partition(".")
        rest = "." + rest if rest else ""
        rel = False
        if name in OUTPUT_INDEX:
            kind, idx = "o", OUTPUT_INDEX[name]
        elif name == "a0":
            kind, idx = "a0", 0
        elif name[0] in "rv" and name[1:].isdigit():
            kind, idx = name[0], int(name[1:])
        else:
            raise ValueError("bad register %r" % tok)
    comps = rest[1:] if rest.startswith(".") else ""
    return dict(neg=neg, kind=kind, index=idx, rel=rel, comps=comps)


def _swz_of(comps):
    if not comps:
        return (0, 1, 2, 3)
    s = [SWZ.index(c) for c in comps]
    while len(s) < 4:
        s.append(s[-1])                     # D3D replication rule: the last component repeats
    return tuple(s)


def _mask_of(comps):
    if not comps:
        return 15
    m = 0
    for c in comps:
        m |= 8 >> SWZ.index(c)
    return m


def assemble(text):
    """Our text form (see above) to a list of Instr. `#` and `;` start comments; ARL is `arl a0.x, src`."""
    out = []
    for ln, line in enumerate(text.splitlines(), 1):
        line = line.split(";")[0].split("#")[0].strip()
        if not line:
            continue
        ins = Instr()
        slots, v_used, c_used = {}, None, None
        try:
            halves = [p.strip() for p in line.split(" + ")]
            if len(halves) > 2:
                raise ValueError("at most one MAC and one ILU operation per instruction")
            for hi, part in enumerate(halves):
                op, _, args = part.partition(" ")
                toks = [t.strip() for t in _split_args(args)]
                dsts, srcs = toks[0], toks[1:]
                # a pair is "MAC + ILU"; alone, mov is the MAC's and rcp/rcc/rsq/exp/log/lit are the ILU's
                if len(halves) == 2:
                    unit = "mac" if hi == 0 else "ilu"
                else:
                    unit = "mac" if op in MAC_ARGS else "ilu"
                if (unit == "mac" and op not in MAC_ARGS) or (unit == "ilu" and op not in ILU_OPS[1:]):
                    raise ValueError("%s is not a %s operation" % (op, unit.upper()))
                if unit == "mac":
                    ins.mac = op
                    names = MAC_ARGS[op]
                else:
                    ins.ilu = op
                    names = "c"
                if len(srcs) != len(names):
                    raise ValueError("%s takes %d sources" % (op, len(names)))
                for o, s in zip(names, srcs):
                    r = _parse_reg(s)
                    new = Operand(neg=r["neg"], swz=_swz_of(r["comps"]))
                    if r["kind"] == "r":
                        new.mux, new.reg = MUX_TEMP, r["index"]
                    elif r["kind"] == "v":
                        if v_used not in (None, r["index"]):
                            raise ValueError("one input register per instruction (v%d and v%d)"
                                             % (v_used, r["index"]))
                        new.mux, ins.v = MUX_INPUT, r["index"]
                        v_used = r["index"]
                    elif r["kind"] == "c":
                        key = (r["index"], r["rel"])
                        if c_used not in (None, key):
                            raise ValueError("one constant register per instruction")
                        idx = r["index"]
                        if not 0 <= idx < N_CONST and not r["rel"]:
                            raise ValueError("constant c[%d] out of range" % idx)
                        new.mux, ins.const, ins.a0x = MUX_CONST, idx, r["rel"]
                        c_used = key
                    else:
                        raise ValueError("bad source %r" % s)
                    if o in slots and slots[o] != new:
                        # the ILU reads operand C, which add and mad use too: a pair must agree on it
                        raise ValueError("operand %s is needed with two different values" % o.upper())
                    slots[o] = new
                    setattr(ins, o, new)
                if op == "arl":
                    continue
                for d in dsts.split("|"):
                    if d == "_":
                        continue
                    r = _parse_reg(d)
                    m = _mask_of(r["comps"])
                    if r["kind"] == "r":
                        if unit == "mac":
                            ins.out_r, ins.mac_mask = r["index"], m
                        else:
                            ins.ilu_mask = m
                            ins._ilu_r = r["index"]
                    elif r["kind"] in ("o", "c"):
                        if ins.o_mask:
                            raise ValueError("one output (or constant) write per instruction")
                        ins.o_mask, ins.o_is_out, ins.o_addr = m, r["kind"] == "o", r["index"]
                        ins.o_mux = 0 if unit == "mac" else 1
                    else:
                        raise ValueError("bad destination %r" % d)
            ilu_r = getattr(ins, "_ilu_r", None)
            if ilu_r is not None:
                if ins.mac != "nop" and ilu_r != 1:
                    raise ValueError("a paired ILU operation can only write r1")
                if ins.mac == "nop":
                    ins.out_r = ilu_r
        except (ValueError, IndexError) as e:
            raise ValueError("line %d: %s: %s" % (ln, line, e))
        out.append(ins)
    if not out:
        raise ValueError("empty program")
    for i, ins in enumerate(out):
        ins.final = i == len(out) - 1
        for o in "abc":                     # the game's unused operands read v (mux 2) with swizzle xyzw
            if getattr(ins, o).mux == 0:
                getattr(ins, o).mux = MUX_INPUT
    return out


def _split_args(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "[":
            depth += 1
        elif ch == "]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return out


# ---------------------------------------------------------------------------------------------------------------
# Static facts: what a program reads and writes
def info(prog):
    reads_v, reads_c, rel_c, writes_o, temps_w = set(), set(), set(), {}, set()
    uninit, written = set(), set()
    for k, ins in enumerate(prog.instrs):
        ops = set(MAC_ARGS.get(ins.mac, "")) | ({"c"} if ins.ilu != "nop" else set())
        for o in ops:
            op = getattr(ins, o)
            if op.mux == MUX_INPUT:
                reads_v.add(ins.v)
            elif op.mux == MUX_CONST:
                (rel_c if ins.a0x else reads_c).add(ins.const)
            elif op.mux == MUX_TEMP and op.reg not in written and op.reg != POS_ALIAS:
                uninit.add((k, op.reg))
        if ins.mac not in ("nop", "arl") and ins.mac_mask:
            written.add(ins.out_r)
            temps_w.add(ins.out_r)
        if ins.ilu != "nop" and ins.ilu_mask:
            written.add(ins.ilu_temp)
            temps_w.add(ins.ilu_temp)
        if ins.o_mask and ins.o_is_out:
            nm = OUTPUTS.get(ins.o_addr, "o?%d" % ins.o_addr)
            writes_o[nm] = writes_o.get(nm, 0) | ins.o_mask
    ops = {}
    for ins in prog.instrs:
        for u in (ins.mac, ins.ilu):
            if u != "nop":
                ops[u] = ops.get(u, 0) + 1
    return {
        "instructions": len(prog.instrs),
        "inputs": sorted(reads_v),
        "constants": sorted(reads_c),
        "relative_bases": sorted(rel_c),
        "outputs": {k: _mask_str(v) for k, v in sorted(writes_o.items(), key=lambda kv: OUTPUT_INDEX.get(kv[0], 99))},
        "temps": sorted(temps_w),
        "ops": dict(sorted(ops.items())),
        "paired": sum(1 for i in prog.instrs if i.mac != "nop" and i.ilu != "nop"),
        "uninitialised_reads": sorted(uninit),
        "screen_epilogue": screen_epilogue(prog),
    }


# ---------------------------------------------------------------------------------------------------------------
# Reference interpreter
#
# One vertex at a time, pure Python (no numpy in the repo's venv). Every value is a 4-list of float32 values
# (Python floats rounded to float32 after each operation: computing in double and rounding once is correctly
# rounded for + - * / and sqrt, since 53 >= 2*24 + 2), and next to it runs a 4-list of absolute error bounds: the
# largest distance between this result and the result of any other correct float32 evaluation of the same
# mathematics, given exact inputs. Rules:
#   * swizzle, negate, mov, min, max: exact (the bound passes through unchanged)
#   * mul/add/mad/dp*: the first-order bound |a|eb + |b|ea + ea*eb, plus one ulp of every rounded product and
#     partial sum, so a fused, reordered or differently associated evaluation is inside it
#   * rcp/rsq/rcc: the input's bound through the derivative, plus 4 ulps (GLSL, Vulkan and WGSL allow 2.5 ulps or
#     less for 1/x and inversesqrt; the NV2A's own accuracy is not publicly documented)
#   * exp/log (partial precision in vs.1.1, "at least 10 bits") and lit's power: a relative 2^-10 (exp/log) or
#     2^-8 (lit) on the approximated component
#   * slt/sge, arl, lit's branches, exp/log's floor: discontinuities. Operands within their bound of the threshold
#     make the result "ambiguous": its bound becomes inf (that component is not compared) or, for arl and for a
#     relative constant index out of range, the vertex is marked bad and skipped.
U = 2.0 ** -23           # one ulp of 1.0 in float32
ILU_ULPS = 4.0
PARTIAL = 2.0 ** -10
LIT_POW = 2.0 ** -8
RCC_MIN, RCC_MAX = 5.42101e-20, 1.884467e+19   # rcc clamps |1/x| into this range, keeping the sign
LIT_POWER_LIMIT = 127.9961                       # vs.1.1: the specular power is clamped to (-128, 128)
INF = float("inf")
_F = struct.Struct("<f")


def f32(x):
    """Round a Python float to float32 (overflow gives +-inf, as the hardware's float32 would)."""
    try:
        return _F.unpack(_F.pack(x))[0]
    except OverflowError:
        return INF if x > 0 else -INF


@dataclass
class RunResult:
    outputs: dict           # name -> [x, y, z, w] (float32 values; components never written are 0.0)
    errors: dict            # name -> [ex, ey, ez, ew] absolute bounds (inf: ambiguous, not compared)
    written: dict           # name -> 4-bit mask (bit 3 = x) of the components the program wrote
    bad: str = ""           # non-empty: this vertex could not be evaluated meaningfully (reason)
    constants_written: dict = None


class _State:
    __slots__ = ("v", "c", "ce", "r", "re", "o", "oe", "ow", "a0", "bad", "cw")

    def __init__(self, v, c):
        self.v = v
        self.c = c
        self.ce = None                      # constant errors: created on the first constant write
        self.r = [[0.0] * 4 for _ in range(N_TEMP)]
        self.re = [[0.0] * 4 for _ in range(N_TEMP)]
        self.o = {k: [0.0] * 4 for k in OUTPUTS}
        self.oe = {k: [0.0] * 4 for k in OUTPUTS}
        self.ow = dict.fromkeys(OUTPUTS, 0)
        self.a0 = 0
        self.bad = ""
        self.cw = {}

    def mark(self, reason):
        if not self.bad:
            self.bad = reason


_Z4 = (0.0, 0.0, 0.0, 0.0)


def _fetch(st, ins, op):
    if op.mux == MUX_TEMP:
        if op.reg == POS_ALIAS:
            val, err = st.o[0], st.oe[0]
        else:
            val, err = st.r[op.reg], st.re[op.reg]
    elif op.mux == MUX_INPUT:
        val, err = st.v[ins.v], _Z4
    elif op.mux == MUX_CONST:
        idx = ins.const
        if ins.a0x:
            idx = st.a0 + ins.const
            if not 0 <= idx < N_CONST:
                st.mark("constant index a0.x%+d = %d is out of range" % (ins.const, idx))
                idx = min(max(idx, 0), N_CONST - 1)
        val = st.c[idx]
        err = st.ce[idx] if st.ce is not None else _Z4
    else:
        raise ValueError("operand with mux 0")
    s = op.swz
    if op.neg:
        return [-val[s[0]], -val[s[1]], -val[s[2]], -val[s[3]]], [err[s[0]], err[s[1]], err[s[2]], err[s[3]]]
    return [val[s[0]], val[s[1]], val[s[2]], val[s[3]]], [err[s[0]], err[s[1]], err[s[2]], err[s[3]]]


def _mul1(a, ea, b, eb):
    r = f32(a * b)
    return r, abs(a) * eb + abs(b) * ea + ea * eb + U * abs(r)


def _add1(a, ea, b, eb):
    r = f32(a + b)
    return r, ea + eb + U * abs(r)


def _dot(a, ea, b, eb, n, hom=False):
    """Products, then a left-to-right float32 sum (dp3: 3 terms, dp4: 4, dph: 3 + b.w)."""
    acc = None
    e = mag = 0.0
    for k in range(n):
        p = f32(a[k] * b[k])
        e += abs(a[k]) * eb[k] + abs(b[k]) * ea[k] + ea[k] * eb[k]
        mag += abs(p)
        acc = p if acc is None else f32(acc + p)
    if hom:
        acc = f32(acc + b[3])
        e += eb[3]
        mag += abs(b[3])
    e += 2 * (n + hom) * U * mag            # n products and n-1 (+1) sums, each rounded once
    return [acc] * 4, [e] * 4


def _mac(st, ins):
    op = ins.mac
    args = MAC_ARGS[op]
    a, ea = _fetch(st, ins, ins.a)
    if "b" in args:
        b, eb = _fetch(st, ins, ins.b)
    if "c" in args:
        c, ec = _fetch(st, ins, ins.c)
    if op == "mov":
        return a, ea
    if op == "mul":
        rs = [_mul1(a[k], ea[k], b[k], eb[k]) for k in range(4)]
    elif op == "add":
        rs = [_add1(a[k], ea[k], c[k], ec[k]) for k in range(4)]
    elif op == "mad":
        rs = []
        for k in range(4):
            p, ep = _mul1(a[k], ea[k], b[k], eb[k])
            r, er = _add1(p, ep, c[k], ec[k])
            rs.append((r, er + U * abs(p)))     # a fused multiply-add is inside this bound too
    elif op == "dp3":
        return _dot(a, ea, b, eb, 3)
    elif op == "dp4":
        return _dot(a, ea, b, eb, 4)
    elif op == "dph":
        return _dot(a, ea, b, eb, 3, hom=True)
    elif op == "dst":
        y, ey = _mul1(a[1], ea[1], b[1], eb[1])
        return [1.0, y, a[2], b[3]], [0.0, ey, ea[2], eb[3]]
    elif op in ("min", "max"):
        f = min if op == "min" else max
        return [f(a[k], b[k]) for k in range(4)], [max(ea[k], eb[k]) for k in range(4)]
    elif op in ("slt", "sge"):
        r, e = [], []
        for k in range(4):
            d = a[k] - b[k]
            r.append(1.0 if ((d >= 0) if op == "sge" else (d < 0)) else 0.0)
            tol = ea[k] + eb[k]
            e.append(INF if tol > 0 and abs(d) <= tol else 0.0)
        return r, e
    elif op == "arl":
        x = a[0]
        fl = math.floor(x)
        if ea[0] > 0 and min(x - fl, fl + 1 - x) <= ea[0]:
            st.mark("arl operand %r is within its error bound %.3g of an integer" % (x, ea[0]))
        st.a0 = int(fl)
        return None, None
    else:
        raise ValueError(op)
    return [r for r, _ in rs], [e for _, e in rs]


def _ilu(st, ins):
    c, ec = _fetch(st, ins, ins.c)
    op = ins.ilu
    x, ex = c[0], ec[0]
    if op == "mov":
        return c, ec
    if op in ("rcp", "rcc"):
        if x == 0.0:
            r = math.copysign(INF, x)
        else:
            r = f32(1.0 / x)
        if op == "rcc":
            m = min(max(abs(r), RCC_MIN), RCC_MAX)
            r = f32(math.copysign(m, r))
        ax = abs(x)
        e = ex / (ax * (ax - ex)) if ax > ex else INF
        e += ILU_ULPS * U * abs(r)
        return [r] * 4, [e] * 4
    if op == "rsq":
        ax = abs(x)
        r = INF if ax == 0.0 else f32(1.0 / math.sqrt(ax))
        e = 0.5 * ex / (ax - ex) ** 1.5 if ax > 2 * ex else INF
        e += ILU_ULPS * U * abs(r)
        return [r] * 4, [e] * 4
    if op == "exp":
        fl = math.floor(x)
        near = ex > 0 and min(x - fl, fl + 1 - x) <= ex
        try:
            rx, rz = f32(2.0 ** fl), f32(2.0 ** x)
        except OverflowError:
            rx = rz = INF
        ry = f32(x - fl)
        return ([rx, ry, rz, 1.0],
                [INF if near else 0.0, INF if near else ex + U * abs(ry), abs(rz) * (math.log(2) * ex + PARTIAL), 0.0])
    if op == "log":
        ax = abs(x)
        if ax == 0.0:
            return [-INF, 1.0, -INF, 1.0], [INF, INF, INF, 0.0]
        lz = math.log2(ax)
        fl = math.floor(lz)
        rel = ex / ax
        near = rel > 0 and min(lz - fl, fl + 1 - lz) <= rel / math.log(2)
        ry = f32(ax / 2.0 ** fl)
        return ([f32(fl), ry, f32(lz), 1.0],
                [INF if near else 0.0, INF if near else abs(ry) * rel,
                 rel / math.log(2) + PARTIAL * max(1.0, abs(lz)), 0.0])
    if op == "lit":
        cx, cy, cw = c[0], c[1], c[3]
        p = min(max(cw, -LIT_POWER_LIMIT), LIT_POWER_LIMIT)
        ry = max(cx, 0.0)
        rz, ez = 0.0, 0.0
        if cx > 0 and cy > 0:
            try:
                rz = f32(cy ** p)
            except OverflowError:
                rz = INF
            ez = abs(rz) * (abs(p) * ec[1] / cy + abs(math.log(cy)) * ec[3] + LIT_POW)
        if (ec[0] > 0 and abs(cx) <= ec[0]) or (ec[1] > 0 and abs(cy) <= ec[1]):
            ez = INF
        return [1.0, ry, rz, 1.0], [0.0, ec[0], ez, 0.0]
    raise ValueError(op)


def _write(dst, dste, mask, val, err):
    if mask & 8:
        dst[0], dste[0] = val[0], err[0]
    if mask & 4:
        dst[1], dste[1] = val[1], err[1]
    if mask & 2:
        dst[2], dste[2] = val[2], err[2]
    if mask & 1:
        dst[3], dste[3] = val[3], err[3]


def screen_epilogue(prog):
    """Index of the first instruction that rewrites an oPos component already written, or None.

    The game's programs end with the screen-space transform (observed in all 17, the form public descriptions
    of the Xbox give): `mul oPos.xyz, r12, c58` / `rcc r1.x, r12.w` / `mad oPos.xyz, r12, r1.x, c59`, i.e.
    oPos.xyz = oPos.xyz * c58 / oPos.w + c59 with c58/c59 the viewport scale and offset. Everything before that
    instruction computes the clip-space position, which is what a bgfx shader returns in gl_Position.
    """
    instrs = prog.instrs if isinstance(prog, Program) else prog
    seen = 0
    for k, ins in enumerate(instrs):
        if ins.o_mask and ins.o_is_out and ins.o_addr == 0:
            if seen & ins.o_mask:
                return k
            seen |= ins.o_mask
    return None


def run(prog, v, c, trace=None, position="screen"):
    """Run `prog` (a Program or a list of Instr) on one vertex.

    position="clip" reports oPos as it was before the screen-space epilogue (see screen_epilogue).

    v: up to 16 input registers, each 4 floats (missing ones read 0); c: 192 constant registers of 4 floats
    (hardware numbering; D3D register n is c[n + 96]). Values are rounded to float32 on entry.
    `trace` (a list) receives (instruction index, MAC result, ILU result) per instruction.
    """
    instrs = prog.instrs if isinstance(prog, Program) else prog
    vv = [[f32(x) for x in r] for r in v] + [[0.0] * 4 for _ in range(16 - len(v))]
    cc = [[f32(x) for x in r] for r in c]
    if len(cc) != N_CONST:
        raise ValueError("need %d constant registers, got %d" % (N_CONST, len(cc)))
    st = _State(vv, cc)
    epi = screen_epilogue(instrs) if position == "clip" else None
    clip = None
    for k, ins in enumerate(instrs):
        if k == epi:
            clip = (list(st.o[0]), list(st.oe[0]), st.ow[0])
        mv = me = iv = ie = None
        if ins.mac != "nop":
            mv, me = _mac(st, ins)
        if ins.ilu != "nop":
            iv, ie = _ilu(st, ins)
        # the two units read the old state; writes follow
        if mv is not None and ins.mac_mask:
            _write(st.r[ins.out_r], st.re[ins.out_r], ins.mac_mask, mv, me)
        if iv is not None and ins.ilu_mask:
            t = ins.ilu_temp
            _write(st.r[t], st.re[t], ins.ilu_mask, iv, ie)
        if ins.o_mask:
            val, err = (mv, me) if ins.o_mux == 0 else (iv, ie)
            if val is None:
                raise ValueError("instruction %d writes an output from an idle unit" % k)
            if ins.o_is_out:
                if ins.o_addr not in OUTPUTS:
                    raise ValueError("instruction %d writes unknown output %d" % (k, ins.o_addr))
                _write(st.o[ins.o_addr], st.oe[ins.o_addr], ins.o_mask, val, err)
                st.ow[ins.o_addr] |= ins.o_mask
            else:
                if st.ce is None:
                    st.c = [list(r) for r in st.c]
                    st.ce = [[0.0] * 4 for _ in range(N_CONST)]
                _write(st.c[ins.o_addr], st.ce[ins.o_addr], ins.o_mask, val, err)
                st.cw[ins.o_addr] = st.cw.get(ins.o_addr, 0) | ins.o_mask
        if trace is not None:
            trace.append((k, mv, iv))
    if clip is not None:
        st.o[0], st.oe[0], st.ow[0] = clip
    outs, errs, written = {}, {}, {}
    for k, nm in OUTPUTS.items():
        m = st.ow[k]
        if m:
            outs[nm], errs[nm], written[nm] = st.o[k], st.oe[k], m
            for j in range(4):
                if m & (8 >> j) and not math.isfinite(st.o[k][j]):
                    st.mark("%s.%s is not finite" % (nm, SWZ[j]))
    return RunResult(outs, errs, written, st.bad, st.cw)


# ---------------------------------------------------------------------------------------------------------------
def _cmd_census(a):
    rows = census()
    if a.json:
        print(json.dumps(rows, indent=1))
        return
    print("| program | instr. | paired | inputs | outputs | constants read (before the epilogue) | relative | "
          "selected by | constants from | data needs it |")
    print("|---|---|---|---|---|---|---|---|---|---|")
    for r in rows:
        print("| `%s` | %d | %d | %s | %s | %s | %s | %s | %s | %s |" % (
            r["name"], r["instructions"], r["paired"], r["inputs"], r["outputs"], r["constants"], r["relative"],
            r["selected_by"], r["constants_from"], r["needed"]))
    print()
    print("%d programs, %d instructions; every one ends with the screen-space epilogue (c58/c59): %s" % (
        len(rows), sum(r["instructions"] for r in rows), all(r["epilogue"] for r in rows)))
    ops = {}
    for r in rows:
        for k, v in r["ops"].items():
            ops[k] = ops.get(k, 0) + v
    print("operations: " + ", ".join("%s %d" % kv for kv in sorted(ops.items(), key=lambda kv: -kv[1])))


def _cmd_list(a):
    rows = []
    for name, addr in GAME_PROGRAMS:
        p = game_program(name)
        i = info(p)
        rows.append(dict(name=name, addr="0x%06x" % addr, **i))
    if a.json:
        print(json.dumps(rows, indent=1))
        return
    for r in rows:
        print("%-28s %s %3d instr  in v%s  out %s  const %d (+%d rel)  ops %s" % (
            r["name"], r["addr"], r["instructions"], ",v".join(map(str, r["inputs"])),
            " ".join("%s.%s" % kv for kv in r["outputs"].items()), len(r["constants"]),
            len(r["relative_bases"]), " ".join("%s:%d" % kv for kv in r["ops"].items())))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list")
    p.add_argument("--json", action="store_true")
    p = sub.add_parser("census", help="the summary table for docs/shaders.md (no program contents)")
    p.add_argument("--json", action="store_true")
    p = sub.add_parser("dis")
    p.add_argument("name", nargs="?")
    p.add_argument("--file")
    p.add_argument("--d3d", action="store_true", help="constants as D3D registers (hardware - 96)")
    p.add_argument("--raw", action="store_true", help="show the four dwords too")
    p = sub.add_parser("info")
    p.add_argument("name")
    p.add_argument("--json", action="store_true")
    p = sub.add_parser("asm")
    p.add_argument("src")
    p.add_argument("-o", "--out", required=True)
    a = ap.parse_args(argv)
    if a.cmd == "list":
        _cmd_list(a)
    elif a.cmd == "census":
        _cmd_census(a)
    elif a.cmd == "dis":
        prog = load_program(a.file or a.name)
        for k, (ins, text) in enumerate(zip(prog.instrs, disasm(prog, a.d3d))):
            raw = (" ; %08x %08x %08x %08x" % tuple(encode(ins))) if a.raw else ""
            print("%3d  %s%s" % (k, text, raw))
    elif a.cmd == "info":
        i = info(load_program(a.name))
        print(json.dumps(i, indent=None if a.json else 1))
    elif a.cmd == "asm":
        instrs = assemble(_read(a.src, "r"))
        with open(a.out, "wb") as f:
            f.write(build_blob(instrs))
        print("%s: %d instructions" % (a.out, len(instrs)))


if __name__ == "__main__":
    main()
