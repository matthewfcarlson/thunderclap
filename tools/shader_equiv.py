#!/usr/bin/env python3
"""Shader equivalence: a hand-written bgfx vertex shader against an NV2A vertex program (docs/shaders.md).

The shader counterpart of tools/equiv.py.

  build/venv/bin/python tools/shader_equiv.py SRC.sc [PROGRAM]          # human-readable report
  build/venv/bin/python tools/shader_equiv.py SRC.sc PROGRAM --json     # one-line JSON
  build/venv/bin/python tools/shader_equiv.py SRC.sc --inputs 3000      # more random vertices (default 600)
  build/venv/bin/python tools/shader_equiv.py SRC.sc --quick            # compile SPIR-V only
  build/venv/bin/python tools/shader_equiv.py --dump build/shaders/equiv/x/x.spirv.bin

PROGRAM is a game program name (read from the player's XBE by tools/nv2a_vp.py), a .bin blob or a .vp text file
of ours; without it, the source's `// nv2a-program:` annotation names it. The exit status is 0 only for
`equivalent`.

Levels (like equiv.py):
  1  the .sc compiles with bgfx's shaderc for every host profile (SPIR-V, Metal, GLSL 430, ESSL 300, WGSL)
  2  interface: every input register the program reads is fed by a shader input, every output it writes is
     produced, every uniform maps onto constant registers (annotations in the .sc, see parse_annotations)
  3  differential execution: the compiled SPIR-V runs in the interpreter below and the program in
     nv2a_vp.run, on directed, structured (game-like) and fuzzed vertices and constant files; every output
     component the program writes is compared within K_TOL times the reference's error bound

Why SPIR-V on the CPU: shaderc compiles a bgfx `.sc` shader through glslang to SPIR-V and runs spirv-opt's
performance passes, and the Metal and WGSL outputs are cross-compiled from that same optimised SPIR-V
(tools/shaderc/shaderc_metal.cpp and shaderc_wgsl.cpp in the pinned bgfx). Executing it tests the program the GPU
backends are built from, after the compiler has had its say, with no GPU, window or driver, deterministically and
on any machine a batch agent runs on. What it cannot see is a backend's own arithmetic (fast-math rsqrt, fused
multiply-adds): that is what the tolerance is for (docs/shaders.md, "Tolerance").

SPIR-V arithmetic here is float32, rounded after every operation (Python floats are doubles; one rounding of a
double result is the correctly rounded float32 result for + - * / and sqrt). Transcendentals are evaluated in
double and rounded once. Opcode names come from the SPIR-V grammar Khronos publishes (spirv.core.grammar.json,
MIT-style licence), read at run time from bgfx's bundled copy under build/third_party/.
"""
import argparse
import json
import math
import os
import random
import struct
import subprocess
import sys
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
def _read(path, mode):
    with open(path, mode) as f:
        return f.read()


GRAMMAR_DIR = os.path.join(ROOT, "build/third_party/src/bgfx/3rdparty/spirv-headers/include/spirv/unified1")

_F = struct.Struct("<f")
INF = float("inf")


def f32(x):
    try:
        return _F.unpack(_F.pack(x))[0]
    except OverflowError:
        return INF if x > 0 else -INF


def _load_grammar():
    core = json.loads(_read(os.path.join(GRAMMAR_DIR, "spirv.core.grammar.json"), "r"))
    ops = {i["opcode"]: i["opname"] for i in core["instructions"]}
    enums = {}
    for k in core["operand_kinds"]:
        if "enumerants" in k:
            enums[k["kind"]] = {e["value"] if isinstance(e["value"], int) else int(e["value"], 0): e["enumerant"]
                                for e in k["enumerants"]}
    glsl = json.loads(_read(os.path.join(GRAMMAR_DIR, "extinst.glsl.std.450.grammar.json"), "r"))
    ext = {i["opcode"]: i["opname"] for i in glsl["instructions"]}
    return ops, enums, ext


OPS, ENUMS, GLSL_EXT = _load_grammar()


# ===============================================================================================================
# SPIR-V
# ===============================================================================================================
# bgfx shader binary (as tools/shaderc/shaderc_spirv.cpp writes it)
def parse_bgfx_bin(data):
    magic = data[:4]
    if magic[:3] not in (b"VSH", b"FSH", b"CSH"):
        raise ValueError("not a bgfx shader binary (magic %r)" % magic)
    o = 4
    in_hash, out_hash = struct.unpack_from("<II", data, o)
    o += 8
    o += 8                                   # raw bindings: srv, uav (u32 each)
    count, = struct.unpack_from("<H", data, o)
    o += 2
    uniforms = []
    for _ in range(count):
        n = data[o]
        o += 1
        name = data[o:o + n].decode()
        o += n
        typ, num = data[o], data[o + 1]
        reg_index, reg_count = struct.unpack_from("<HH", data, o + 2)
        o += 6 + 4                           # + texComponent, texDimension (u8), texFormat (u16)
        uniforms.append(dict(name=name, type=typ, num=num, reg_index=reg_index, reg_count=reg_count))
    size, = struct.unpack_from("<I", data, o)
    o += 4
    code = data[o:o + size]
    o += size + 1
    nattr = data[o]
    o += 1
    attrs = list(struct.unpack_from("<%dH" % nattr, data, o))
    return dict(kind=magic[:3].decode(), version=magic[3], uniforms=uniforms, code=code, attrs=attrs,
                hashes=(in_hash, out_hash))


# ---------------------------------------------------------------------------------------------------------------
class Type:
    __slots__ = ("kind", "width", "signed", "elem", "count", "members", "storage", "id")

    def __init__(self, kind, **kw):
        self.kind = kind
        self.width = self.signed = self.elem = self.count = self.members = self.storage = None
        for k, v in kw.items():
            setattr(self, k, v)

    def __repr__(self):
        if self.kind in ("vector", "matrix", "array"):
            return "%s<%r x %s>" % (self.kind, self.elem, self.count)
        return self.kind


def _string(words):
    b = b"".join(struct.pack("<I", w) for w in words)
    return b[:b.index(b"\0")].decode()


def _strlen_words(words):
    for i, w in enumerate(words):
        if (w >> 24) == 0 or (w & 0xFF) == 0 or (w >> 8 & 0xFF) == 0 or (w >> 16 & 0xFF) == 0:
            return i + 1
    return len(words)


class Module:
    def __init__(self, code):
        words = struct.unpack("<%dI" % (len(code) // 4), code)
        if words[0] != 0x07230203:
            raise ValueError("not SPIR-V")
        self.names, self.member_names = {}, {}
        self.decor, self.member_decor = {}, {}
        self.types, self.consts, self.globals = {}, {}, {}
        self.functions = {}
        self.entry = None
        self.ext_sets = {}
        i = 5
        cur_fn = None
        cur_block = None
        while i < len(words):
            wc, opc = words[i] >> 16, words[i] & 0xFFFF
            ops = list(words[i + 1:i + wc])
            i += wc
            name = OPS.get(opc, "Op?%d" % opc)
            if name == "OpName":
                self.names[ops[0]] = _string(ops[1:])
            elif name == "OpMemberName":
                self.member_names[(ops[0], ops[1])] = _string(ops[2:])
            elif name == "OpDecorate":
                self.decor.setdefault(ops[0], {})[ENUMS["Decoration"].get(ops[1], ops[1])] = ops[2:]
            elif name == "OpMemberDecorate":
                self.member_decor.setdefault((ops[0], ops[1]), {})[ENUMS["Decoration"].get(ops[2], ops[2])] = ops[3:]
            elif name == "OpEntryPoint":
                n = _strlen_words(ops[2:])
                self.entry = dict(model=ops[0], fn=ops[1], name=_string(ops[2:]), interface=ops[2 + n:])
            elif name == "OpExtInstImport":
                self.ext_sets[ops[0]] = _string(ops[1:])
            elif name.startswith("OpType"):
                self._type(name, ops)
            elif name in ("OpConstant", "OpConstantTrue", "OpConstantFalse", "OpConstantComposite",
                          "OpConstantNull", "OpSpecConstant", "OpSpecConstantTrue", "OpSpecConstantFalse",
                          "OpSpecConstantComposite"):
                self._const(name, ops)
            elif name == "OpUndef" and cur_fn is None:
                self.consts[ops[1]] = self.zero(self.types[ops[0]])
            elif name == "OpVariable" and cur_fn is None:
                ptr = self.types[ops[0]]
                init = self.consts[ops[3]] if len(ops) > 3 else None
                self.globals[ops[1]] = dict(type=ptr.elem, storage=ENUMS["StorageClass"][ops[2]], init=init)
            elif name == "OpFunction":
                cur_fn = dict(id=ops[1], params=[], blocks={}, order=[], ret=ops[0])
                self.functions[ops[1]] = cur_fn
            elif name == "OpFunctionParameter":
                cur_fn["params"].append(ops[1])
            elif name == "OpFunctionEnd":
                cur_fn = cur_block = None
            elif name == "OpLabel":
                cur_block = []
                cur_fn["blocks"][ops[0]] = cur_block
                cur_fn["order"].append(ops[0])
            elif cur_block is not None:
                cur_block.append((name, ops))
        if self.entry is None:
            raise ValueError("no entry point")

    def _type(self, name, ops):
        r = ops[0]
        if name == "OpTypeVoid":
            t = Type("void")
        elif name == "OpTypeBool":
            t = Type("bool")
        elif name == "OpTypeInt":
            t = Type("int", width=ops[1], signed=bool(ops[2]))
        elif name == "OpTypeFloat":
            t = Type("float", width=ops[1])
            if ops[1] != 32:
                raise ValueError("only 32-bit floats are supported (got %d)" % ops[1])
        elif name == "OpTypeVector":
            t = Type("vector", elem=self.types[ops[1]], count=ops[2])
        elif name == "OpTypeMatrix":
            t = Type("matrix", elem=self.types[ops[1]], count=ops[2])
        elif name == "OpTypeArray":
            t = Type("array", elem=self.types[ops[1]], count=self.consts[ops[2]])
        elif name == "OpTypeRuntimeArray":
            t = Type("array", elem=self.types[ops[1]], count=0)
        elif name == "OpTypeStruct":
            t = Type("struct", members=[self.types[m] for m in ops[1:]])
        elif name == "OpTypePointer":
            t = Type("pointer", storage=ENUMS["StorageClass"][ops[1]], elem=self.types.get(ops[2]))
        elif name == "OpTypeFunction":
            t = Type("function")
        else:
            t = Type(name[6:].lower())
        t.id = r
        self.types[r] = t

    def _const(self, name, ops):
        t = self.types[ops[0]]
        if name in ("OpConstantTrue", "OpSpecConstantTrue"):
            v = True
        elif name in ("OpConstantFalse", "OpSpecConstantFalse"):
            v = False
        elif name in ("OpConstant", "OpSpecConstant"):
            if t.kind == "float":
                v = struct.unpack("<f", struct.pack("<I", ops[2]))[0]
            else:
                v = ops[2]
                if t.signed and v >= 1 << 31:
                    v -= 1 << 32
        elif name in ("OpConstantComposite", "OpSpecConstantComposite"):
            v = tuple(self.consts[c] for c in ops[2:])
        else:
            v = self.zero(t)
        self.consts[ops[1]] = v

    def zero(self, t):
        if t.kind == "float":
            return 0.0
        if t.kind == "int":
            return 0
        if t.kind == "bool":
            return False
        if t.kind in ("vector", "matrix", "array"):
            return tuple(self.zero(t.elem) for _ in range(t.count))
        if t.kind == "struct":
            return tuple(self.zero(m) for m in t.members)
        return None

    def interface(self):
        """Inputs, outputs and uniform blocks of the entry point, by name."""
        ins, outs, unis = {}, {}, {}
        for vid, g in self.globals.items():
            d = self.decor.get(vid, {})
            nm = self.names.get(vid, "%%%d" % vid)
            if g["storage"] == "Input":
                ins[nm] = dict(id=vid, type=g["type"], location=(d.get("Location") or [None])[0],
                               builtin=ENUMS["BuiltIn"].get((d.get("BuiltIn") or [None])[0]))
            elif g["storage"] == "Output":
                bi = ENUMS["BuiltIn"].get((d.get("BuiltIn") or [None])[0])
                outs[nm] = dict(id=vid, type=g["type"], location=(d.get("Location") or [None])[0], builtin=bi)
            elif g["storage"] in ("Uniform", "UniformConstant", "PushConstant"):
                t = g["type"]
                members = {}
                if t is not None and t.kind == "struct":
                    for k, mt in enumerate(t.members):
                        mn = self.member_names.get((t.id, k), "m%d" % k)
                        md = self.member_decor.get((t.id, k), {})
                        members[mn] = dict(index=k, type=mt, offset=(md.get("Offset") or [0])[0])
                unis[nm] = dict(id=vid, type=t, members=members)
        return ins, outs, unis


# ---------------------------------------------------------------------------------------------------------------
# Values: float / int / bool scalars; tuples for vectors, matrices (tuple of columns), arrays and structs.
# Memory: a variable holds [value]; a pointer is (cell, path) with path a tuple of indices into the value.
# Undefined behaviour seen during the current run. SPIR-V / GLSL leave these results undefined; the interpreter
# returns NaN for them (and min/max/clamp of a NaN is NaN), so a shader that lets one reach an output fails, and
# one whose compiled code computes an undefined value only to discard it (spirv-opt turns `c ? pow(x, y) : 0`
# into a select that evaluates both sides) passes. The list is attached to a mismatch as a diagnostic.
_UB = []


def _ub(what):
    if len(_UB) < 8:
        _UB.append(what)


def _get(val, path):
    for p in path:
        val = val[p]
    return val


def _set(val, path, new):
    if not path:
        return new
    lst = list(val)
    lst[path[0]] = _set(val[path[0]], path[1:], new)
    return tuple(lst)


def _map(f, *xs):
    if isinstance(xs[0], tuple):
        return tuple(_map(f, *[x[i] if isinstance(x, tuple) else x for x in xs]) for i in range(len(xs[0])))
    return f(*xs)


def _i32(x, signed=True):
    x &= 0xFFFFFFFF
    return x - (1 << 32) if signed and x >= 1 << 31 else x


def _fdiv(a, b):
    if not (2.0 ** -126 <= abs(b) <= 2.0 ** 126):
        _ub("division by %r" % b)
    if b == 0.0:
        if a == 0.0 or a != a:
            return float("nan")
        return math.copysign(INF, a) * math.copysign(1.0, b)
    return f32(a / b)


def _fmul(a, b):
    try:
        return f32(a * b)
    except (OverflowError, ValueError):
        return float("nan")


def _dot(a, b):
    acc = None
    for x, y in zip(a, b):
        p = f32(x * y)
        acc = p if acc is None else f32(acc + p)
    return acc


def _ext(name, args):
    a = args[0]
    if name in ("FMax", "FMin", "FClamp"):
        n = len(args)
        f = {"FMax": max, "FMin": min}.get(name)

        def strict(*xs):
            if any(x != x for x in xs):
                _ub("%s of NaN" % name)
                return float("nan")
            return f(xs[0], xs[1]) if f else min(max(xs[0], xs[1]), xs[2])
        return _map(strict, *args[:n])
    if name == "InverseSqrt":
        def isq(x):
            if x <= 0 or x != x:
                _ub("inversesqrt(%r)" % x)
                return float("nan")
            return f32(1.0 / math.sqrt(x))
        return _map(isq, a)
    if name == "Sqrt":
        def sq(x):
            if x < 0:
                _ub("sqrt(%r)" % x)
            return float("nan") if x < 0 else f32(math.sqrt(x))
        return _map(sq, a)
    if name in ("FMax", "NMax"):
        return _map(lambda x, y: y if x != x else (x if y != y else max(x, y)), a, args[1])
    if name in ("FMin", "NMin"):
        return _map(lambda x, y: y if x != x else (x if y != y else min(x, y)), a, args[1])
    if name in ("SMax", "UMax"):
        return _map(max, a, args[1])
    if name in ("SMin", "UMin"):
        return _map(min, a, args[1])
    if name in ("FClamp", "NClamp"):
        return _map(lambda x, lo, hi: min(max(x, lo), hi), a, args[1], args[2])
    if name == "SClamp":
        return _map(lambda x, lo, hi: min(max(x, lo), hi), a, args[1], args[2])
    if name == "FAbs":
        return _map(abs, a)
    if name == "FSign":
        return _map(lambda x: 1.0 if x > 0 else (-1.0 if x < 0 else 0.0), a)
    if name == "Floor":
        return _map(lambda x: float(math.floor(x)) if math.isfinite(x) else x, a)
    if name == "Ceil":
        return _map(lambda x: float(math.ceil(x)) if math.isfinite(x) else x, a)
    if name == "Trunc":
        return _map(lambda x: float(math.trunc(x)) if math.isfinite(x) else x, a)
    if name == "Fract":
        return _map(lambda x: f32(x - math.floor(x)), a)
    if name == "Exp2":
        return _map(lambda x: f32(2.0 ** x) if x < 128 else INF, a)
    if name in ("Log2", "Log"):
        for y in (a if isinstance(a, tuple) else (a,)):
            if y <= 0:
                _ub("%s(%r)" % (name.lower(), y))
    if name == "Log2":
        return _map(lambda x: -INF if x == 0 else (float("nan") if x < 0 else f32(math.log2(x))), a)
    if name == "Exp":
        return _map(lambda x: f32(math.exp(x)) if x < 89 else INF, a)
    if name == "Log":
        return _map(lambda x: -INF if x == 0 else (float("nan") if x < 0 else f32(math.log(x))), a)
    if name == "Pow":
        def pw(x, y):
            if x < 0 or (x == 0 and y <= 0):
                _ub("pow(%r, %r)" % (x, y))
                return float("nan")
            try:
                return f32(x ** y) if x > 0 or (x == 0 and y > 0) else (1.0 if y == 0 else float("nan"))
            except (OverflowError, ZeroDivisionError):
                return INF
        return _map(pw, a, args[1])
    if name == "Fma":
        return _map(lambda x, y, z: f32(x * y + z), a, args[1], args[2])
    if name == "FMix":
        return _map(lambda x, y, t: f32(x + f32(t * f32(y - x))), a, args[1], args[2])
    if name == "Step":
        return _map(lambda e, x: 0.0 if x < e else 1.0, a, args[1])
    if name == "SmoothStep":
        def ss(e0, e1, x):
            t = min(max(_fdiv(f32(x - e0), f32(e1 - e0)), 0.0), 1.0)
            return f32(f32(t * t) * f32(3.0 - f32(2.0 * t)))
        return _map(ss, a, args[1], args[2])
    if name == "Length":
        if isinstance(a, tuple):
            return f32(math.sqrt(_dot(a, a)))
        return abs(a)
    if name == "Normalize":
        if isinstance(a, tuple):
            ln = f32(math.sqrt(_dot(a, a)))
            return tuple(_fdiv(x, ln) for x in a)
        return math.copysign(1.0, a)
    if name == "Cross":
        b = args[1]
        return (f32(f32(a[1] * b[2]) - f32(a[2] * b[1])), f32(f32(a[2] * b[0]) - f32(a[0] * b[2])),
                f32(f32(a[0] * b[1]) - f32(a[1] * b[0])))
    if name == "Distance":
        d = tuple(f32(x - y) for x, y in zip(a, args[1])) if isinstance(a, tuple) else (f32(a - args[1]),)
        return f32(math.sqrt(_dot(d, d)))
    if name == "Reflect":
        n = args[1]
        d = _dot(n, a)
        return tuple(f32(x - f32(f32(2.0 * d) * y)) for x, y in zip(a, n))
    if name in ("Sin", "Cos", "Tan", "Asin", "Acos", "Atan"):
        f = getattr(math, name.lower())
        return _map(lambda x: f32(f(x)), a)
    if name == "Atan2":
        return _map(lambda y, x: f32(math.atan2(y, x)), a, args[1])
    if name == "Round" or name == "RoundEven":
        return _map(lambda x: float(round(x)), a)
    raise NotImplementedError("GLSL.std.450 %s" % name)


_FCMP = {
    "OpFOrdEqual": lambda a, b: a == b, "OpFOrdNotEqual": lambda a, b: a == a and b == b and a != b,
    "OpFOrdLessThan": lambda a, b: a < b, "OpFOrdGreaterThan": lambda a, b: a > b,
    "OpFOrdLessThanEqual": lambda a, b: a <= b, "OpFOrdGreaterThanEqual": lambda a, b: a >= b,
    "OpFUnordEqual": lambda a, b: not (a < b or a > b), "OpFUnordNotEqual": lambda a, b: a != b,
    "OpFUnordLessThan": lambda a, b: not (a >= b), "OpFUnordGreaterThan": lambda a, b: not (a <= b),
    "OpFUnordLessThanEqual": lambda a, b: not (a > b), "OpFUnordGreaterThanEqual": lambda a, b: not (a < b),
    "OpIEqual": lambda a, b: a == b, "OpINotEqual": lambda a, b: a != b,
    "OpSLessThan": lambda a, b: a < b, "OpSGreaterThan": lambda a, b: a > b,
    "OpSLessThanEqual": lambda a, b: a <= b, "OpSGreaterThanEqual": lambda a, b: a >= b,
    "OpULessThan": lambda a, b: a < b, "OpUGreaterThan": lambda a, b: a > b,
    "OpULessThanEqual": lambda a, b: a <= b, "OpUGreaterThanEqual": lambda a, b: a >= b,
    "OpLogicalEqual": lambda a, b: a == b, "OpLogicalNotEqual": lambda a, b: a != b,
    "OpLogicalAnd": lambda a, b: a and b, "OpLogicalOr": lambda a, b: a or b,
}
_FBIN = {
    "OpFAdd": lambda a, b: f32(a + b), "OpFSub": lambda a, b: f32(a - b), "OpFMul": _fmul, "OpFDiv": _fdiv,
    "OpFMod": lambda a, b: f32(a - b * math.floor(a / b)) if b else float("nan"),
    "OpFRem": lambda a, b: f32(math.fmod(a, b)) if b else float("nan"),
    "OpIAdd": lambda a, b: _i32(a + b), "OpISub": lambda a, b: _i32(a - b), "OpIMul": lambda a, b: _i32(a * b),
    "OpSDiv": lambda a, b: _i32(int(a / b)) if b else 0, "OpUDiv": lambda a, b: a // b if b else 0,
    "OpSMod": lambda a, b: _i32(a % b) if b else 0, "OpSRem": lambda a, b: _i32(int(math.fmod(a, b))) if b else 0,
    "OpUMod": lambda a, b: a % b if b else 0,
    "OpShiftLeftLogical": lambda a, b: _i32(a << b), "OpShiftRightArithmetic": lambda a, b: a >> b,
    "OpShiftRightLogical": lambda a, b: (a & 0xFFFFFFFF) >> b,
    "OpBitwiseAnd": lambda a, b: _i32(a & b), "OpBitwiseOr": lambda a, b: _i32(a | b),
    "OpBitwiseXor": lambda a, b: _i32(a ^ b),
}


class ExecError(Exception):
    pass


class Machine:
    """Runs a Module's entry point. Inputs and uniforms are given by variable / member name."""

    def __init__(self, module, step_limit=200000, sample=None):
        self.m = module
        self.step_limit = step_limit
        self.used_ops = set()
        # fragment shaders: sample(name, coord) -> 4 floats, `name` the bgfx sampler (s_fx0 for s_fx0Texture /
        # s_fx0Sampler); images and samplers are tokens carrying that name
        self.sample = sample

    def run(self, inputs, uniforms):
        m = self.m
        self.mem = {}
        ins, outs, unis = m.interface()
        for nm, d in ins.items():
            if nm not in inputs:
                raise ExecError("no value for input %s" % nm)
            self.mem[d["id"]] = [self._coerce(inputs[nm], d["type"])]
        for nm, d in outs.items():
            self.mem[d["id"]] = [m.zero(d["type"])]
        for nm, d in unis.items():
            t = d["type"]
            if t is None:
                continue
            if t.kind in ("image", "sampler", "sampledimage"):
                base = nm[:-7] if nm.endswith(("Texture", "Sampler")) else nm
                self.mem[d["id"]] = [("texture", base)]
                continue
            if t.kind == "struct":
                vals = []
                for mn, md in sorted(d["members"].items(), key=lambda kv: kv[1]["index"]):
                    if mn not in uniforms:
                        raise ExecError("no value for uniform %s" % mn)
                    vals.append(self._coerce(uniforms[mn], md["type"]))
                self.mem[d["id"]] = [tuple(vals)]
            else:
                self.mem[d["id"]] = [self._coerce(uniforms.get(nm), t)] if nm in uniforms else [m.zero(t)]
        for vid, g in m.globals.items():
            if vid not in self.mem:
                self.mem[vid] = [g["init"] if g["init"] is not None else m.zero(g["type"])]
        self.steps = 0
        del _UB[:]
        self._call(m.entry["fn"], [])
        self.undefined = list(_UB)
        return {nm: self.mem[d["id"]][0] for nm, d in outs.items()}

    def _coerce(self, val, t):
        if t.kind == "float":
            return f32(float(val))
        if t.kind == "int":
            return int(val)
        if t.kind == "bool":
            return bool(val)
        if t.kind in ("vector", "matrix", "array", "struct"):
            elems = t.members if t.kind == "struct" else [t.elem] * t.count
            val = list(val)
            if len(val) < len(elems):
                raise ExecError("value for %r has %d elements, need %d" % (t, len(val), len(elems)))
            return tuple(self._coerce(v, et) for v, et in zip(val, elems))
        raise ExecError("cannot pass a %r" % t)

    def _call(self, fid, args):
        fn = self.m.functions[fid]
        env = dict(zip(fn["params"], args))
        local_mem = []
        prev, label = None, fn["order"][0]
        while True:
            block = fn["blocks"][label]
            nxt = None
            for name, ops in block:
                self.steps += 1
                if self.steps > self.step_limit:
                    raise ExecError("step limit reached (a loop that does not end?)")
                self.used_ops.add(name)
                if name == "OpPhi":
                    for k in range(2, len(ops), 2):
                        if ops[k + 1] == prev:
                            env[ops[1]] = self._val(env, ops[k])
                            break
                    else:
                        raise ExecError("phi without the predecessor block")
                    continue
                if name in ("OpSelectionMerge", "OpLoopMerge", "OpLine", "OpNoLine", "OpSource",
                            "OpExtInstWithForwardRefsKHR", "OpModuleProcessed"):
                    continue
                if name == "OpBranch":
                    nxt = ops[0]
                    break
                if name == "OpBranchConditional":
                    nxt = ops[1] if self._val(env, ops[0]) else ops[2]
                    break
                if name == "OpSwitch":
                    sel = self._val(env, ops[0])
                    nxt = ops[1]
                    for k in range(2, len(ops), 2):
                        if ops[k] == sel:
                            nxt = ops[k + 1]
                            break
                    break
                if name == "OpReturn":
                    return None
                if name == "OpReturnValue":
                    return self._val(env, ops[0])
                if name in ("OpKill", "OpUnreachable", "OpTerminateInvocation"):
                    raise ExecError("%s reached" % name)
                self._exec(env, name, ops, local_mem)
            prev, label = label, nxt

    def _val(self, env, i):
        if i in env:
            return env[i]
        if i in self.m.consts:
            return self.m.consts[i]
        raise ExecError("undefined id %%%d" % i)

    def _exec(self, env, name, ops, local_mem):
        m = self.m
        V = lambda i: self._val(env, i)                             # noqa: E731
        if name == "OpVariable":
            t = m.types[ops[0]].elem
            cell = [m.consts[ops[3]] if len(ops) > 3 else m.zero(t)]
            local_mem.append(cell)
            env[ops[1]] = (cell, ())
            return
        if name in ("OpAccessChain", "OpInBoundsAccessChain"):
            base = ops[2]
            cell, path = (self.mem[base], ()) if base in self.mem else env[base]
            env[ops[1]] = (cell, path + tuple(V(i) for i in ops[3:]))
            return
        if name == "OpLoad":
            p = ops[2]
            cell, path = (self.mem[p], ()) if p in self.mem else env[p]
            try:
                env[ops[1]] = _get(cell[0], path)
            except (IndexError, TypeError):
                raise ExecError("load out of bounds at %r" % (path,))
            return
        if name == "OpStore":
            p = ops[0]
            cell, path = (self.mem[p], ()) if p in self.mem else env[p]
            try:
                cell[0] = _set(cell[0], path, V(ops[1]))
            except (IndexError, TypeError):
                raise ExecError("store out of bounds at %r" % (path,))
            return
        r = ops[1]
        if name in _FBIN:
            f = _FBIN[name]
            env[r] = _map(f, V(ops[2]), V(ops[3]))
        elif name in _FCMP:
            f = _FCMP[name]
            env[r] = _map(f, V(ops[2]), V(ops[3]))
        elif name == "OpFNegate":
            env[r] = _map(lambda x: -x, V(ops[2]))
        elif name == "OpSNegate":
            env[r] = _map(lambda x: _i32(-x), V(ops[2]))
        elif name == "OpLogicalNot":
            env[r] = _map(lambda x: not x, V(ops[2]))
        elif name == "OpNot":
            env[r] = _map(lambda x: _i32(~x), V(ops[2]))
        elif name == "OpVectorTimesScalar":
            s = V(ops[3])
            env[r] = tuple(_fmul(x, s) for x in V(ops[2]))
        elif name == "OpMatrixTimesScalar":
            s = V(ops[3])
            env[r] = tuple(tuple(_fmul(x, s) for x in col) for col in V(ops[2]))
        elif name == "OpMatrixTimesVector":
            mat, vec = V(ops[2]), V(ops[3])                       # mat: columns
            rows = len(mat[0])
            env[r] = tuple(_dot([col[k] for col in mat], vec) for k in range(rows))
        elif name == "OpVectorTimesMatrix":
            vec, mat = V(ops[2]), V(ops[3])
            env[r] = tuple(_dot(vec, col) for col in mat)
        elif name == "OpMatrixTimesMatrix":
            a, b = V(ops[2]), V(ops[3])
            rows = len(a[0])
            env[r] = tuple(tuple(_dot([col[k] for col in a], bc) for k in range(rows)) for bc in b)
        elif name == "OpTranspose":
            a = V(ops[2])
            env[r] = tuple(tuple(col[k] for col in a) for k in range(len(a[0])))
        elif name == "OpDot":
            env[r] = _dot(V(ops[2]), V(ops[3]))
        elif name == "OpCompositeConstruct":
            parts = []
            t = m.types[ops[0]]
            for i in ops[2:]:
                v = V(i)
                if t.kind == "vector" and isinstance(v, tuple):
                    parts.extend(v)
                else:
                    parts.append(v)
            env[r] = tuple(parts)
        elif name == "OpCompositeExtract":
            env[r] = _get(V(ops[2]), ops[3:])
        elif name == "OpCompositeInsert":
            env[r] = _set(V(ops[3]), tuple(ops[4:]), V(ops[2]))
        elif name == "OpVectorShuffle":
            a, b = V(ops[2]), V(ops[3])
            both = tuple(a) + tuple(b)
            env[r] = tuple(both[k] if k != 0xFFFFFFFF else 0.0 for k in ops[4:])
        elif name == "OpVectorExtractDynamic":
            env[r] = V(ops[2])[V(ops[3])]
        elif name == "OpVectorInsertDynamic":
            v = list(V(ops[2]))
            v[V(ops[4])] = V(ops[3])
            env[r] = tuple(v)
        elif name == "OpCopyObject":
            env[r] = V(ops[2])
        elif name == "OpSelect":
            c, a, b = V(ops[2]), V(ops[3]), V(ops[4])
            if isinstance(c, tuple):
                env[r] = tuple(x if k else y for k, x, y in zip(c, a, b))
            else:
                env[r] = a if c else b
        elif name == "OpExtInst":
            if m.ext_sets.get(ops[2]) != "GLSL.std.450":
                raise ExecError("extended instruction set %r" % m.ext_sets.get(ops[2]))
            env[r] = _ext(GLSL_EXT[ops[3]], [V(i) for i in ops[4:]])
            self.used_ops.add("GLSL.std.450 " + GLSL_EXT[ops[3]])
        elif name in ("OpConvertFToS", "OpConvertFToU"):
            def cv(x):
                if not (math.isfinite(x) and -2.0 ** 31 <= x < 2.0 ** 31):
                    _ub("float-to-int of %r" % x)
                    return 0
                return int(math.trunc(x))
            env[r] = _map(cv, V(ops[2]))
        elif name in ("OpConvertSToF", "OpConvertUToF"):
            env[r] = _map(lambda x: f32(float(x)), V(ops[2]))
        elif name == "OpBitcast":
            t = m.types[ops[0]]
            base = t.elem if t.kind == "vector" else t

            def bc(x):
                if base.kind == "float":
                    return struct.unpack("<f", struct.pack("<I", x & 0xFFFFFFFF))[0]
                u = struct.unpack("<I", _F.pack(x))[0] if isinstance(x, float) else x & 0xFFFFFFFF
                return _i32(u, base.signed)
            env[r] = _map(bc, V(ops[2]))
        elif name == "OpAny":
            env[r] = any(V(ops[2]))
        elif name == "OpAll":
            env[r] = all(V(ops[2]))
        elif name in ("OpIsNan", "OpIsInf"):
            f = (lambda x: x != x) if name == "OpIsNan" else (lambda x: math.isinf(x))
            env[r] = _map(f, V(ops[2]))
        elif name == "OpFunctionCall":
            env[r] = self._call(ops[2], [env[i] if i in env else (self.mem[i], ()) if i in self.mem else V(i)
                                         for i in ops[3:]])
        elif name == "OpUndef":
            env[r] = m.zero(m.types[ops[0]])
        elif name == "OpSampledImage":
            env[r] = V(ops[2])
        elif name in ("OpImageSampleImplicitLod", "OpImageSampleExplicitLod"):
            tok = V(ops[2])
            if self.sample is None or not isinstance(tok, tuple) or tok[0] != "texture":
                raise ExecError("a texture sample with no sampler model")
            env[r] = tuple(f32(x) for x in self.sample(tok[1], V(ops[3])))
        else:
            raise ExecError("unsupported SPIR-V instruction %s" % name)


def load(path_or_bytes):
    data = _read(path_or_bytes, "rb") if isinstance(path_or_bytes, str) else path_or_bytes
    b = parse_bgfx_bin(data)
    return b, Module(b["code"])


# ===============================================================================================================
# The equivalence harness
# ===============================================================================================================
SHADERC = os.path.join(ROOT, "build/third_party/tools/shaderc")
BGFX_SRC = os.path.join(ROOT, "build/third_party/src/bgfx/src")
OUT_DIR = os.path.join(ROOT, "build/shaders/equiv")
PROFILES = {                 # the host-compilable profiles tools/wine_gfx.py uses (D3D needs Windows)
    "spirv": ("linux", "spirv"),
    "metal": ("osx", "metal"),
    "glsl": ("linux", "430"),
    "essl": ("android", "300_es"),
    "wgsl": ("linux", "wgsl"),
}
K_TOL = 4.0                  # allowed |shader - reference| = K_TOL * bound (see docs/shaders.md, "Tolerance")
ABS_FLOOR = 2.0 ** -100      # below float32's normal range: flushing denormals to zero is not a difference
FUZZ_RANGE = 8.0
COLOR_OUTPUTS = ("oD0", "oD1", "oB0", "oB1")
DEFAULT_OUTPUTS = {          # bgfx output name -> NV2A output register (by convention; `nv2a-output:` overrides)
    "gl_Position": "oPos", "v_color0": "oD0", "v_color1": "oD1", "v_fog": "oFog",
    "v_texcoord0": "oT0", "v_texcoord1": "oT1", "v_texcoord2": "oT2", "v_texcoord3": "oT3",
}


def _nv2a():
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import nv2a_vp
    return nv2a_vp


# ---------------------------------------------------------------------------------------------------------------
# Annotations in the .sc source (comments; shaderc ignores them)
#
#   // nv2a-program: simple_proximity
#   // nv2a-input: a_position = v0 position         kinds: position normal color uv weight index:<stride>:<count> any
#   // nv2a-input: a_color0 = v3 color bgra         "bgra": the attribute is a D3DCOLOR read as bytes B,G,R,A
#   // nv2a-uniform: u_vc = c96                     uniform array element i = hardware constant c[96 + i]
#   // nv2a-output: v_fog = oFog                    (only needed when the name convention above does not apply)
#   // nv2a-const: c96 = fixed 0 0.5 1 1000         what the game puts there: fixed values (all input sets)
#   // nv2a-const: c106..c109 = matrix              or a hint for the structured inputs: matrix (affine rows),
#                                                   projection (perspective x affine rows), direction, position,
#                                                   color, range <lo> <hi>
def parse_annotations(src_text):
    ann = dict(program=None, inputs={}, uniforms={}, outputs={}, consts=[])
    for ln, line in enumerate(src_text.splitlines(), 1):
        s = line.strip()
        if not s.startswith("//"):
            continue
        s = s[2:].strip()
        if not s.startswith("nv2a-"):
            continue
        key, _, rest = s.partition(":")
        rest = rest.split("#")[0].strip()
        try:
            if key == "nv2a-program":
                ann["program"] = rest.split()[0]
            elif key == "nv2a-input":
                lhs, rhs = [t.strip() for t in rest.split("=", 1)]
                toks = rhs.split()
                reg = toks[0]
                if not (reg.startswith("v") and reg[1:].isdigit()):
                    raise ValueError("expected v<N>, got %r" % reg)
                kind = next((t for t in toks[1:] if t not in ("bgra",) and not t.isdigit()), "any")
                comps = next((int(t) for t in toks[1:] if t.isdigit()), None)
                ann["inputs"][lhs] = dict(reg=int(reg[1:]), kind=kind, bgra="bgra" in toks[1:], comps=comps)
            elif key == "nv2a-uniform":
                lhs, rhs = [t.strip() for t in rest.split("=", 1)]
                if not (rhs.startswith("c") and rhs[1:].isdigit()):
                    raise ValueError("expected c<N>, got %r" % rhs)
                ann["uniforms"][lhs] = int(rhs[1:])
            elif key == "nv2a-output":
                lhs, rhs = [t.strip() for t in rest.split("=", 1)]
                ann["outputs"][lhs] = rhs.split()[0]
            elif key == "nv2a-const":
                lhs, rhs = [t.strip() for t in rest.split("=", 1)]
                a, _, b = lhs.partition("..")
                lo = int(a.strip()[1:])
                hi = int(b.strip()[1:]) if b else lo
                toks = rhs.split()
                ann["consts"].append(dict(lo=lo, hi=hi, kind=toks[0], args=[float(t) for t in toks[1:]]))
            else:
                raise ValueError("unknown annotation %s" % key)
        except (ValueError, IndexError) as e:
            raise SystemExit("%d: bad annotation %r: %s" % (ln, line.strip(), e))
    return ann


# ---------------------------------------------------------------------------------------------------------------
def compile_sc(src, profile, out_dir, stype="vertex", varyingdef=None, includes=()):
    if not os.path.exists(SHADERC):
        raise SystemExit("no shaderc at %s: run `tools/wine_gfx.py fetch` and `tools/wine_gfx.py shaderc`"
                         % os.path.relpath(SHADERC, ROOT))
    plat, prof = PROFILES[profile]
    vdef = varyingdef or os.path.join(os.path.dirname(os.path.abspath(src)), "varying.def.sc")
    os.makedirs(out_dir, exist_ok=True)
    out = os.path.join(out_dir, "%s.%s.bin" % (os.path.basename(src)[:-3], profile))
    cmd = [SHADERC, "-f", src, "-o", out, "--type", stype, "--platform", plat, "-p", prof,
           "-i", BGFX_SRC, "--varyingdef", vdef]
    for inc in includes:
        cmd += ["-i", inc]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0 or not os.path.exists(out):
        return None, (r.stdout + r.stderr).strip()[-2000:]
    return out, ""


# ---------------------------------------------------------------------------------------------------------------
# Input generation
def _unit(r):
    while True:
        v = [r.uniform(-1, 1) for _ in range(3)]
        n = math.sqrt(sum(x * x for x in v))
        if 0.1 < n <= 1:
            return [x / n for x in v]


def _affine_rows(r, rows=4):
    """Rows of M = [s*R | t; 0 0 0 1] (a constant register per row, as the game uploads transposed matrices)."""
    ax = _unit(r)
    ang = r.uniform(-math.pi, math.pi)
    c, s, t = math.cos(ang), math.sin(ang), 1 - math.cos(ang)
    x, y, z = ax
    rot = [[t * x * x + c, t * x * y - s * z, t * x * z + s * y],
           [t * x * y + s * z, t * y * y + c, t * y * z - s * x],
           [t * x * z - s * y, t * y * z + s * x, t * z * z + c]]
    sc = r.uniform(0.5, 2.0)
    tr = [r.uniform(-50, 50) for _ in range(3)]
    m = [[rot[i][0] * sc, rot[i][1] * sc, rot[i][2] * sc, tr[i]] for i in range(3)] + [[0.0, 0.0, 0.0, 1.0]]
    return m[:rows]


def _projection_rows(r):
    """Rows of P*V: a D3D-style perspective (z in [0, w]) times an affine view."""
    fov = r.uniform(0.5, 1.6)
    asp = r.uniform(0.75, 1.8)
    zn, zf = r.uniform(0.1, 2.0), r.uniform(100, 5000)
    ys = 1 / math.tan(fov / 2)
    p = [[ys / asp, 0, 0, 0], [0, ys, 0, 0], [0, 0, zf / (zf - zn), -zn * zf / (zf - zn)], [0, 0, 1, 0]]
    v = _affine_rows(r)
    return [[sum(p[i][k] * v[k][j] for k in range(4)) for j in range(4)] for i in range(4)]


def _input_value(r, kind, mode):
    if kind.startswith("index"):
        _, stride, count = (kind.split(":") + ["3", "26"])[:3]
        return [int(stride) * r.randrange(int(count)) / 255.0 for _ in range(4)]
    if mode == "fuzz" or kind == "any":
        return [r.choice((0.0, 1.0, -1.0, 0.5)) if r.random() < 0.05 else r.uniform(-FUZZ_RANGE, FUZZ_RANGE)
                for _ in range(4)]
    if kind == "position":
        return [r.uniform(-100, 100) for _ in range(3)] + [1.0]
    if kind == "normal":
        return _unit(r) + [0.0]
    if kind == "color":
        return [r.randrange(256) / 255.0 for _ in range(4)]
    if kind == "uv":
        return [r.uniform(-4, 4) for _ in range(4)]
    if kind == "weight":
        w = [r.random() for _ in range(4)]
        s = sum(w)
        return [x / s for x in w]
    raise SystemExit("unknown input kind %r" % kind)


def make_case(r, ann, mode):
    """One vertex: 16 input registers and 192 constants (hardware numbering)."""
    v = [[0.0, 0.0, 0.0, 1.0] for _ in range(16)]
    for nm, a in ann["inputs"].items():
        v[a["reg"]] = _input_value(r, a["kind"], mode)
    if mode == "fuzz":
        c = [[r.uniform(-FUZZ_RANGE, FUZZ_RANGE) for _ in range(4)] for _ in range(192)]
    else:
        c = [[r.uniform(-2, 2) for _ in range(4)] for _ in range(192)]
    for h in ann["consts"]:
        n = h["hi"] - h["lo"] + 1
        k = h["kind"]
        if k == "fixed":
            vals = h["args"] + [0.0] * (4 - len(h["args"]))
            rows = [vals] * n
        elif mode == "fuzz":
            continue
        elif k == "matrix":
            rows = _affine_rows(r, 4)[:n] if n <= 4 else None
        elif k == "projection":
            rows = _projection_rows(r)[:n]
        elif k == "direction":
            rows = [_unit(r) + [r.uniform(0, 1000)] for _ in range(n)]
        elif k == "position":
            rows = [[r.uniform(-100, 100) for _ in range(3)] + [1.0] for _ in range(n)]
        elif k == "color":
            rows = [[r.uniform(0, 1) for _ in range(4)] for _ in range(n)]
        elif k == "range":
            lo, hi = h["args"][:2]
            rows = [[r.uniform(lo, hi) for _ in range(4)] for _ in range(n)]
        elif k == "bones":
            rows = []
            while len(rows) < n:
                rows.extend(_affine_rows(r, 3))
            rows = rows[:n]
        else:
            raise SystemExit("unknown constant hint %r" % k)
        for i, row in enumerate(rows):
            c[h["lo"] + i] = list(row)
    return v, c


def directed_cases(ann):
    """A few fixed vertices: all-zero inputs, all-one inputs (with the game's fixed constants)."""
    out = []
    for val in (0.0, 1.0):
        v = [[0.0, 0.0, 0.0, 1.0] for _ in range(16)]
        for nm, a in ann["inputs"].items():
            if a["kind"].startswith("index"):
                v[a["reg"]] = [0.0] * 4
            else:
                v[a["reg"]] = [val] * 3 + [1.0 if val else 0.0]
        c = [[0.5, -0.25, 1.0, 2.0] for _ in range(192)]
        for h in ann["consts"]:
            if h["kind"] == "fixed":
                for i in range(h["lo"], h["hi"] + 1):
                    c[i] = h["args"] + [0.0] * (4 - len(h["args"]))
        out.append((v, c))
    return out


# ---------------------------------------------------------------------------------------------------------------
def _fmt(x):
    if isinstance(x, float):
        return "%.9g (0x%08x)" % (x, struct.unpack("<I", _F.pack(x))[0]) if math.isfinite(x) else repr(x)
    return repr(x)


def _short(vec):
    return "(" + ", ".join("%.6g" % x for x in vec) + ")"


def verify(src, program=None, n_inputs=600, seed=1, profiles=None, color_clamp=True, keep_going=False):
    """Check a hand-written bgfx vertex shader against an NV2A vertex program. Returns the report dict."""
    nv = _nv2a()
    t0 = time.time()
    text = _read(src, "r")
    ann = parse_annotations(text)
    program = program or ann["program"]
    rep = dict(src=os.path.relpath(os.path.abspath(src), ROOT), program=program, status="fail", level=0)
    if program and program.endswith((".vp", ".bin")):
        rep["program"] = os.path.basename(program)
    if not program:
        rep.update(status="no_program", error="no program given (argument or `// nv2a-program:`)")
        return rep
    if program.endswith((".vp", ".bin")) and not os.path.isabs(program):
        here = os.path.join(os.path.dirname(os.path.abspath(src)), program)
        program = here if os.path.exists(here) else os.path.join(ROOT, program)
    prog = nv.load_program(program)
    pinfo = nv.info(prog)
    rep["program_info"] = dict(instructions=pinfo["instructions"], inputs=pinfo["inputs"],
                               outputs=pinfo["outputs"])

    # level 1: compiles for every host profile; SPIR-V is the one executed
    out_dir = os.path.join(OUT_DIR, os.path.basename(src)[:-3])
    l1 = {}
    spv = None
    for prof in (profiles or list(PROFILES)):
        path, err = compile_sc(src, prof, out_dir)
        l1[prof] = "ok" if path else "FAILED: " + err
        if prof == "spirv":
            spv = path
    if spv is None and "spirv" not in l1:
        spv, err = compile_sc(src, "spirv", out_dir)
        l1["spirv"] = "ok" if spv else "FAILED: " + err
    rep["level1"] = dict(ok=all(v == "ok" for v in l1.values()), profiles=l1)
    if not rep["level1"]["ok"]:
        rep["status"] = "compile_error"
        return rep
    rep["level"] = 1

    # level 2: the interface maps onto the program's
    b, mod = load(spv)
    ins, outs, unis = mod.interface()
    issues, warnings = [], []
    in_map = {}
    for nm, d in ins.items():
        if d["builtin"]:
            continue
        a = ann["inputs"].get(nm)
        if a is None:
            issues.append("shader input %s has no `nv2a-input:` mapping" % nm)
            continue
        t = d["type"]
        n = t.count if t.kind == "vector" else 1
        if a["comps"]:
            n = min(n, a["comps"])
        in_map[nm] = dict(a, n=n, type=t)
    fed = {a["reg"] for a in in_map.values()}
    for reg in pinfo["inputs"]:
        if reg not in fed:
            issues.append("the program reads v%d; no shader input is mapped to it" % reg)
    for nm, a in ann["inputs"].items():
        if nm not in ins:
            warnings.append("annotated input %s is not a live input of the compiled shader" % nm)
    uni_map = {}
    for unm, d in unis.items():
        for mn, md in d["members"].items():
            if mn.startswith("u_") and mn in ann["uniforms"]:
                t = md["type"]
                cnt = t.count if t.kind == "array" else 1
                uni_map[mn] = dict(base=ann["uniforms"][mn], count=cnt, type=t)
            elif mn not in ann["uniforms"]:
                issues.append("uniform %s has no `nv2a-uniform:` mapping" % mn)
    visible = set()
    for u in uni_map.values():
        visible.update(range(u["base"], u["base"] + u["count"]))
    epi = pinfo["screen_epilogue"]
    pre = prog.instrs[:epi] if epi is not None else prog.instrs
    pre_consts = nv.info(nv.Program("pre", pre))
    for cr in pre_consts["constants"]:
        if cr not in visible:
            warnings.append("the program reads c%d, which no shader uniform covers" % cr)
    if pre_consts["relative_bases"] and not visible:
        warnings.append("the program reads relative constants; no shader uniform covers them")
    out_map = {}
    for nm, d in outs.items():
        short = nm.split(".")[-1]
        reg = ann["outputs"].get(short) or DEFAULT_OUTPUTS.get(short)
        if d["builtin"] == "Position":
            reg = ann["outputs"].get("gl_Position", "oPos")
        if reg is None:
            warnings.append("shader output %s maps to no NV2A output (ignored)" % short)
            continue
        out_map[reg] = dict(name=nm, short=short, type=d["type"])
    for reg, mask in pinfo["outputs"].items():
        if reg not in out_map:
            issues.append("the program writes %s.%s; the shader has no output mapped to it" % (reg, mask))
    rep["level2"] = dict(ok=not issues, issues=issues, warnings=warnings,
                         inputs={k: "v%d%s (%d)" % (v["reg"], " bgra" if v["bgra"] else "", v["n"])
                                 for k, v in in_map.items()},
                         uniforms={k: "c%d..c%d" % (v["base"], v["base"] + v["count"] - 1) for k, v in uni_map.items()},
                         outputs={k: v["short"] for k, v in out_map.items()})
    if issues:
        rep["status"] = "interface_error"
        return rep
    rep["level"] = 2

    # level 3: differential execution
    machine = Machine(mod)
    r = random.Random(seed)
    cases = [("directed", v, c) for v, c in directed_cases(ann)]
    n_struct = n_inputs // 2
    for k in range(n_inputs):
        mode = "structured" if k < n_struct else "fuzz"
        v, c = make_case(r, ann, mode)
        cases.append((mode, v, c))
    run_n, skipped, skip_reasons = 0, 0, {}
    compared, exact, ambiguous, inside = {}, {}, {}, {}
    max_ratio, max_where = 0.0, None
    mismatches = []
    by_kind = {}
    for idx, (mode, v, c) in enumerate(cases):
        # what the vertex buffer gives each side: the declared components; the rest is (0, 0, 0, 1)
        vv = [list(x) for x in v]
        for nm, a in in_map.items():
            row = vv[a["reg"]]
            vv[a["reg"]] = [f32(row[j]) if j < a["n"] else (0.0, 0.0, 0.0, 1.0)[j] for j in range(4)]
        ref = nv.run(prog, vv, c, position="clip")
        if ref.bad:
            skipped += 1
            key = ref.bad.split(" = ")[0].split(" is within")[0]
            skip_reasons[key] = skip_reasons.get(key, 0) + 1
            continue
        sin = {}
        for nm, a in in_map.items():
            row = vv[a["reg"]][:a["n"]]
            if a["bgra"]:
                full = vv[a["reg"]]
                row = [full[2], full[1], full[0], full[3]][:a["n"]]
            sin[nm] = row if a["type"].kind == "vector" else row[0]
        for nm, d in ins.items():
            if d["builtin"]:
                sin[nm] = 0
        sun = {}
        for mn, u in uni_map.items():
            rows = [c[i] if 0 <= i < 192 else [0.0] * 4 for i in range(u["base"], u["base"] + u["count"])]
            sun[mn] = rows if u["type"].kind == "array" else rows[0]
        try:
            got = machine.run(sin, sun)
        except ExecError as e:
            rep["status"] = "unsupported"
            rep["error"] = "SPIR-V execution: %s" % e
            return rep
        run_n += 1
        by_kind[mode] = by_kind.get(mode, 0) + 1
        bad_here = []
        for reg, mask in ref.written.items():
            o = out_map[reg]
            sv = got[o["name"]]
            sv = list(sv) if isinstance(sv, tuple) else [sv]
            for j in range(4):
                if not mask & (8 >> j):
                    continue
                comp = "%s.%s" % (reg, "xyzw"[j])
                if j >= len(sv):
                    bad_here.append((comp, None, ref.outputs[reg][j], 0.0))
                    continue
                want, bound = ref.outputs[reg][j], ref.errors[reg][j]
                have = sv[j]
                if color_clamp and reg in COLOR_OUTPUTS:
                    if 0.0 < want < 1.0:
                        inside[comp] = inside.get(comp, 0) + 1
                    want = min(max(want, 0.0), 1.0)
                if not math.isfinite(bound):
                    ambiguous[comp] = ambiguous.get(comp, 0) + 1
                    continue
                compared[comp] = compared.get(comp, 0) + 1
                tol = K_TOL * bound + ABS_FLOOR
                diff = abs(have - want) if math.isfinite(have) else INF
                if bound == 0.0:
                    exact[comp] = exact.get(comp, 0) + 1
                if diff > tol:
                    bad_here.append((comp, have, want, bound))
                elif bound > 0 and diff / (K_TOL * bound) > max_ratio:
                    max_ratio, max_where = diff / (K_TOL * bound), (idx, comp)
        if bad_here:
            mm = dict(input=idx, kind=mode, diffs=[], inputs={}, )
            for comp, have, want, bound in bad_here:
                mm["diffs"].append(dict(output=comp, got=have, expected=want, bound=bound * K_TOL + ABS_FLOOR))
            for nm, a in in_map.items():
                mm["inputs"]["v%d" % a["reg"]] = vv[a["reg"]]
            if machine.undefined:
                mm["undefined"] = machine.undefined
            mismatches.append(mm)
            if len(mismatches) >= 20 and not keep_going:
                break
    never = sorted("%s.%s" % (reg, ch) for reg, comps in pinfo["outputs"].items() for ch in comps
                   if not compared.get("%s.%s" % (reg, ch)))
    l3 = dict(ok=not mismatches, vertices_run=run_n, vertices_skipped=skipped, skip_reasons=skip_reasons,
              by_kind=by_kind, components_compared=sum(compared.values()),
              exact_components=sorted(k for k, n in exact.items() if n == compared.get(k)),
              ambiguous=ambiguous, never_compared=never,
              colour_unclamped={k: inside.get(k, 0) for k in sorted(compared) if k.split(".")[0] in COLOR_OUTPUTS},
              max_ratio=round(max_ratio, 4),
              max_ratio_at=max_where, mismatches=mismatches[:20], spirv_ops=sorted(machine.used_ops),
              tolerance=dict(k=K_TOL, abs_floor=ABS_FLOOR, color_clamp=color_clamp))
    rep["level3"] = l3
    if mismatches:
        rep["status"] = "fail"
    elif run_n < 50 or never:
        rep["status"] = "inconclusive"
        rep["level"] = 2
        rep["note"] = ("only %d vertices ran" % run_n) if run_n < 50 else \
            "never compared (ambiguous or skipped every time): %s" % ", ".join(never)
    else:
        rep["status"] = "equivalent"
        rep["level"] = 3
    rep["time"] = round(time.time() - t0, 2)
    return rep


def text_report(rep):
    out = []
    head = "%s vs %s: %s" % (rep["src"], rep["program"], rep["status"])
    if "level3" in rep:
        l3 = rep["level3"]
        head += " (level %d: %d vertices, %d skipped, %d components compared, worst %.0f%% of tolerance)" % (
            rep["level"], l3["vertices_run"], l3["vertices_skipped"], l3["components_compared"],
            100 * l3["max_ratio"])
    out.append(head)
    if rep.get("error"):
        out.append("  " + rep["error"])
    if "level1" in rep and not rep["level1"]["ok"]:
        for k, v in rep["level1"]["profiles"].items():
            if v != "ok":
                out.append("  %s: %s" % (k, v))
    if "level2" in rep:
        for i in rep["level2"]["issues"]:
            out.append("  interface: " + i)
        for w in rep["level2"]["warnings"]:
            out.append("  warning: " + w)
    if "level3" in rep:
        l3 = rep["level3"]
        if l3["skip_reasons"]:
            out.append("  skipped: " + "; ".join("%s (%d)" % kv for kv in l3["skip_reasons"].items()))
        if l3["ambiguous"]:
            out.append("  ambiguous components (not compared): " +
                       ", ".join("%s %d" % kv for kv in sorted(l3["ambiguous"].items())))
        if l3.get("colour_unclamped"):
            out.append("  colour components inside (0, 1) before the clamp: " +
                       " ".join("%s %d" % kv for kv in l3["colour_unclamped"].items()))
        if l3["exact_components"]:
            out.append("  bit-exact: " + " ".join(l3["exact_components"]))
        if rep.get("note"):
            out.append("  " + rep["note"])
        if l3["mismatches"]:
            m = l3["mismatches"][0]
            d = m["diffs"][0]
            out.append("  first difference: vertex %d (%s): %s = %s, expected %s, allowed +-%.3g" % (
                m["input"], m["kind"], d["output"], _fmt(d["got"]), _fmt(d["expected"]), d["bound"]))
            if len(m["diffs"]) > 1:
                out.append("    also: " + ", ".join(x["output"] for x in m["diffs"][1:]))
            if m.get("undefined"):
                out.append("    the shader computed undefined values on this vertex: " + "; ".join(m["undefined"]))
            out.append("    inputs: " + " ".join("%s=%s" % (k, _short(v)) for k, v in m["inputs"].items()))
            out.append("    %d of %d vertices differ (stopped at 20 unless --keep-going)" % (
                len(l3["mismatches"]), l3["vertices_run"]))
    return "\n".join(out)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", nargs="?", help="the bgfx vertex shader (.sc)")
    ap.add_argument("program", nargs="?", help="NV2A program: a game program name, a .bin or a .vp file")
    ap.add_argument("--inputs", type=int, default=600, help="random vertices (half structured, half fuzzed)")
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--quick", action="store_true", help="compile SPIR-V only (skip the other profiles)")
    ap.add_argument("--no-color-clamp", action="store_true", help="compare oD0/oD1 without the [0,1] clamp")
    ap.add_argument("--keep-going", action="store_true")
    ap.add_argument("--dump", metavar="BIN", help="print a compiled bgfx shader's SPIR-V interface")
    a = ap.parse_args(argv)
    if a.dump:
        b, mod = load(a.dump)
        ins, outs, unis = mod.interface()
        print("bgfx %s v%d, uniforms %s" % (b["kind"], b["version"], b["uniforms"]))
        for nm, d in list(ins.items()) + list(outs.items()):
            print("  %-34s %-24r loc %s %s" % (nm, d["type"], d["location"], d["builtin"] or ""))
        for nm, d in unis.items():
            print("  uniform %s %s" % (nm, {k: (v["type"], v["offset"]) for k, v in d["members"].items()}))
        return 0
    if not a.src:
        ap.error("need a shader source")
    rep = verify(a.src, a.program, n_inputs=a.inputs, seed=a.seed, profiles=["spirv"] if a.quick else None,
                 color_clamp=not a.no_color_clamp, keep_going=a.keep_going)
    if a.json:
        print(json.dumps(rep))
    else:
        print(text_report(rep))
    return 0 if rep["status"] == "equivalent" else 1


if __name__ == "__main__":
    sys.exit(main())
