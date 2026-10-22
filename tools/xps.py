#!/usr/bin/env python3
"""The framebuffer effects' pixel shaders: an interpreter of the game's ps.1.1 / xps.1.1 text and a proof of our
bgfx translations against it (docs/shaders.md, "Pixel shaders: the framebuffer effects").

  build/venv/bin/python tools/xps.py list                  # the 20 programs: name, who assembles it, instructions
  build/venv/bin/python tools/xps.py show filter-8-0       # one program's text (on this machine only: game code text)
  build/venv/bin/python tools/xps.py prove                 # every program against shaders/fx/ (3000 pixels each)
  build/venv/bin/python tools/xps.py prove --inputs 600 --only filter-64-1 --json
  build/venv/bin/python tools/xps.py prove --filter X.sc --blur Y.sc      # other shader sources (the broken fixtures)

Where the programs come from (all the game's own code or data, nothing from Microsoft or NVIDIA):
  - the gaussian's sums and the bloom's composite: the five ps.1.1 texts FUN_00320330 hands to FUN_003202b0
    (equivalent/0x00320330.cpp; the text is in our verified source);
  - the colour pass: FUN_00320540 (equivalent/0x00320540.cpp) assembles xps.1.1 text from fixed pieces for seven
    contrast levels (1, 2, 4, 8, 16, 32, 64) and two sides each; filter_program() below builds the same text by the
    same rules;
  - the threshold program (level 255): the text at 0x432da0 in the player's XBE, read at run time (game data; not
    stored in the repo).

Semantics (ours, from Microsoft's public Direct3D 8 ps.1.1 documentation of each instruction, and the NV2A register
combiners' documented behaviour as the Xbox exposes it: signed values in [-1, 1]):
  - registers are 4-vectors; t<n> is set by `tex t<n>` (stage n's texture sampled at texture coordinate set n),
    c<n> by the application (quantised to 8 bits in [0, 1]: the combiners' constants are packed colours) or by
    `def` (taken as written), r0/r1 temporaries;
  - source modifiers: `-` negate, `_bx2` 2x - 1, `_bias` x - 0.5, `1-` invert; selectors `.a`/`.w` (alpha
    replicated), `.b`/`.z` (blue replicated), none = .rgba;
  - mov add sub mul mad lrp dp3 dp4 cnd: their D3D definitions; dp3/dp4 replicate the dot product to every written
    component (so r0.a holds it after `dp3 r0, ...`); cnd d, r0.a, s1, s2 = s1 where r0.a > 0.5, else s2;
  - instruction modifiers _x2 _x4 _d2, then every result is clamped to [-1, 1] (the combiners' range; _sat: [0, 1]);
  - `+` co-issues an instruction with the one before it: both read the registers as they were before the pair;
  - the output is r0 clamped to [0, 1].
Arithmetic is in double precision: the reference is the exact result of these definitions. What is not modelled
(the hardware's own precision, documented nowhere public): the combiners' internal 9-bit signed precision and the
8-bit rounding of `def` constants and intermediate values. docs/shaders.md states the tolerance.
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
sys.path.insert(0, os.path.join(ROOT, "tools"))
XBE_PATH = os.path.join(ROOT, "isos/extracted/default.xbe")
FX_DIR = os.path.join(ROOT, "src/platform/sdl/pddi/shaders/fx")
SMOKE = os.path.join(ROOT, "build/third_party/out/pddi-host/pddi_smoke")
THRESHOLD_TEXT_ADDR = 0x432da0          # FUN_00320540 copies the threshold program's text from here (level 7)

TOL = 2.0 ** -16                        # |shader - reference| allowed per output component: 1/257 of an 8-bit step
CND_MARGIN = 2.0 ** -12                 # cnd operands this close to 0.5 make the component ambiguous (not compared)


# ---------------------------------------------------------------------------------------------------------------
# The programs
def blur_programs():
    """FUN_00320330's five ps.1.1 programs, as its text gives them (ps0..ps4)."""
    return {
        "blur1": "    ps.1.1 \n    tex t0 \n    mul r0, t0, c0 \n",
        "blur2": "    ps.1.1 \n    tex t0 \n    tex t1 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n",
        "blur3": "    ps.1.1 \n    tex t0 \n    tex t1 \n    tex t2 \n    mul r0, t0, c0 \n    mad r0, t1, c1, r0 \n"
                 "    mad r0, t2, c2, r0 \n",
        "blur4": "    ps.1.1 \n    tex t0 \n    tex t1 \n    tex t2 \n    tex t3 \n    mul r0, t0, c0 \n"
                 "    mad r0, t1, c1, r0 \n    mad r0, t2, c2, r0 \n    mad r0, t3, c3, r0 \n",
        "composite": "    ps.1.1 \n    tex t0 \n    tex t1 \n    mul_x2 r0, t0, c0 \n    mad r0, t1, c1, r0 \n",
    }


LEVELS = (1, 2, 4, 8, 16, 32, 64)


def filter_program(level, side):
    """FUN_00320540's text for contrast level `level` (1..64) and side 0/1 (its pieces and rules)."""
    add = "add     r0.xyz, r0.xyz, r1.w \n"
    dbl = "+mov_x2 r1.w,   r1.w \n"
    p = ["xps.1.1 \n", "def     c1, 0.5, 0.5, 0.5, 0.5 \n", "tex     t0 \n", "dp3     r0,     t0, c0 \n",
         "add     r0.xyz, t0, -r0 \n", "+mad    r1.w,   r0.w, c5, c3_bx2 \n", "mul_x2  r0.xyz, r0, c7 \n"]
    if level >= 32:
        p.append("+mov_x4 r1.w,   r1.w \n")
    elif level >= 16:
        p.append(dbl)
    p.append("mad     r0.xyz, c6_bx2, r0.w, r0 \n")
    if level == 64:
        p.append(dbl)
    p.append(add)
    if side == 0:
        if level > 1:
            p.append(add)
            if level > 2:
                p += [dbl, add]
                if level > 4:
                    p += [dbl, add]
    else:
        p.append(add)
        if level > 1:
            p += [dbl, add]
            if level > 2:
                p += [dbl, add]
    return "".join(p)


def threshold_program(xbe_path=XBE_PATH):
    from xbe import Xbe
    if not os.path.exists(xbe_path):
        raise SystemExit("the player's XBE is not at %s" % xbe_path)
    x = Xbe(xbe_path)
    o = x.offset(THRESHOLD_TEXT_ADDR)
    return x.data[o:o + 1024].split(b"\0")[0].decode("ascii")


def programs(xbe_path=XBE_PATH, with_threshold=True):
    """name -> (text, who assembles it)."""
    out = {}
    for k, t in blur_programs().items():
        out[k] = (t, "FUN_00320330 (ps.1.1)")
    for lv in LEVELS:
        for side in (0, 1):
            out["filter-%d-%d" % (lv, side)] = (filter_program(lv, side), "FUN_00320540 (xps.1.1)")
    if with_threshold:
        out["threshold"] = (threshold_program(xbe_path), "FUN_00320540: the text at 0x432da0 (xps.1.1)")
    return out


# ---------------------------------------------------------------------------------------------------------------
# Parser
OPS = {"mov": 1, "add": 2, "sub": 2, "mul": 2, "mad": 3, "lrp": 3, "dp3": 2, "dp4": 2, "cnd": 3}
SEL = {"": (0, 1, 2, 3), "rgba": (0, 1, 2, 3), "xyzw": (0, 1, 2, 3), "a": (3, 3, 3, 3), "w": (3, 3, 3, 3),
       "b": (2, 2, 2, 2), "z": (2, 2, 2, 2), "rgb": (0, 1, 2, 3), "xyz": (0, 1, 2, 3)}
MASKS = {"": 0b1111, "rgba": 0b1111, "xyzw": 0b1111, "rgb": 0b1110, "xyz": 0b1110, "a": 0b0001, "w": 0b0001}


class XpsError(Exception):
    pass


class Src:
    def __init__(self, text):
        t = text.strip()
        self.text = t
        self.neg = t.startswith("-")
        if self.neg:
            t = t[1:]
        self.invert = t.startswith("1-")
        if self.invert:
            t = t[2:]
        reg, _, sel = t.partition(".")
        self.mod = None
        for m in ("_bx2", "_bias"):
            if reg.endswith(m):
                self.mod, reg = m[1:], reg[:-len(m)]
        if sel not in SEL:
            raise XpsError("selector %r" % text)
        self.sel = SEL[sel]
        self.reg = reg
        if not (reg[:1] in "trcv" and reg[1:].isdigit()):
            raise XpsError("register %r" % text)


class Ins:
    def __init__(self, line, co):
        self.line = line
        self.co = co
        head, _, rest = line.partition(" ")
        parts = head.split("_")
        self.op = parts[0]
        self.scale, self.sat = 1.0, False
        for m in parts[1:]:
            if m == "x2":
                self.scale = 2.0
            elif m == "x4":
                self.scale = 4.0
            elif m == "d2":
                self.scale = 0.5
            elif m == "sat":
                self.sat = True
            else:
                raise XpsError("instruction modifier %r in %r" % (m, line))
        args = [a.strip() for a in rest.split(",")]
        if self.op == "tex":
            self.dst, self.mask, self.srcs = args[0], 0b1111, []
            return
        if self.op not in OPS:
            raise XpsError("unsupported instruction %r" % line)
        d, _, m = args[0].partition(".")
        if m not in MASKS:
            raise XpsError("write mask %r" % line)
        self.dst, self.mask = d, MASKS[m]
        self.srcs = [Src(a) for a in args[1:]]
        if len(self.srcs) != OPS[self.op]:
            raise XpsError("%s takes %d sources: %r" % (self.op, OPS[self.op], line))


class Program:
    def __init__(self, text, name="?"):
        self.name, self.text = name, text
        self.version = None
        self.defs = {}
        self.groups = []          # lists of co-issued instructions
        self.tex = []
        for raw in text.split("\n"):
            line = raw.split("//")[0].split(";")[0].strip()
            if not line:
                continue
            if self.version is None:
                if line not in ("ps.1.1", "xps.1.1"):
                    raise XpsError("version %r" % line)
                self.version = line
                continue
            line = " ".join(line.split())
            if line.startswith("def "):
                reg, *vals = [a.strip() for a in line[4:].split(",")]
                self.defs[int(reg[1:])] = [float(v) for v in vals]
                continue
            co = line.startswith("+")
            if co:
                line = line[1:].strip()
            ins = Ins(line, co)
            if ins.op == "tex":
                self.tex.append(int(ins.dst[1:]))
                continue
            if co:
                if not self.groups:
                    raise XpsError("co-issue with nothing before it")
                self.groups[-1].append(ins)
            else:
                self.groups.append([ins])
        if self.version is None:
            raise XpsError("no version line")

    @property
    def instructions(self):
        return len(self.tex) + sum(len(g) for g in self.groups)

    def constants(self):
        out = set()
        for g in self.groups:
            for i in g:
                for s in i.srcs:
                    if s.reg[0] == "c" and int(s.reg[1:]) not in self.defs:
                        out.add(int(s.reg[1:]))
        return sorted(out)


# ---------------------------------------------------------------------------------------------------------------
# Interpreter
def q8(x):
    """A combiner constant: 8 bits per channel in [0, 1] (as the backend's q8, round to nearest)."""
    x = 0.0 if x < 0.0 else 1.0 if x > 1.0 else x
    return math.floor(x * 255.0 + 0.5) / 255.0


def _clamp(x, lo, hi):
    return lo if x < lo else hi if x > hi else x


class Result:
    def __init__(self):
        self.out = None
        self.margin = math.inf      # the smallest |cnd operand - 0.5| seen
        self.clamped = 0            # instruction results the [-1, 1] clamp changed
        self.undefined = []         # _bx2 / _bias of a value outside [0, 1] (undefined in ps.1.1)


def run(prog, textures, consts, quantise=True):
    """textures: stage -> 4 floats (the texel `tex t<n>` reads); consts: index -> 4 floats (the application's)."""
    res = Result()
    reg = {}
    for i in range(8):
        c = consts.get(i, [0.0] * 4)
        reg["c%d" % i] = [q8(x) for x in c] if quantise else list(c)
    for i, v in prog.defs.items():
        reg["c%d" % i] = list(v) + [0.0] * (4 - len(v))
    for n in prog.tex:
        reg["t%d" % n] = list(textures[n])
    for r in ("r0", "r1"):
        reg.setdefault(r, [0.0] * 4)

    def read(s, k):
        if s.reg not in reg:
            raise XpsError("read of %s before it is written" % s.reg)
        x = reg[s.reg][s.sel[k]]
        if s.mod and not 0.0 <= x <= 1.0:
            res.undefined.append("%s of %r" % (s.text, x))
        if s.invert:
            x = 1.0 - x
        if s.mod == "bx2":
            x = 2.0 * x - 1.0
        elif s.mod == "bias":
            x = x - 0.5
        return -x if s.neg else x

    for group in prog.groups:
        writes = []
        for ins in group:
            a = [[read(s, k) for k in range(4)] for s in ins.srcs]
            op = ins.op
            if op == "mov":
                v = a[0]
            elif op == "add":
                v = [a[0][k] + a[1][k] for k in range(4)]
            elif op == "sub":
                v = [a[0][k] - a[1][k] for k in range(4)]
            elif op == "mul":
                v = [a[0][k] * a[1][k] for k in range(4)]
            elif op == "mad":
                v = [a[0][k] * a[1][k] + a[2][k] for k in range(4)]
            elif op == "lrp":
                v = [a[0][k] * a[1][k] + (1.0 - a[0][k]) * a[2][k] for k in range(4)]
            elif op in ("dp3", "dp4"):
                n = 3 if op == "dp3" else 4
                d = sum(a[0][k] * a[1][k] for k in range(n))
                v = [d] * 4
            elif op == "cnd":
                if ins.srcs[0].reg != "r0" or ins.srcs[0].sel != SEL["a"]:
                    raise XpsError("cnd reads r0.a in ps.1.1: %r" % ins.line)
                v = []
                for k in range(4):
                    res.margin = min(res.margin, abs(a[0][k] - 0.5))
                    v.append(a[1][k] if a[0][k] > 0.5 else a[2][k])
            else:
                raise XpsError(op)
            out = []
            for x in v:
                y = x * ins.scale
                z = _clamp(y, 0.0, 1.0) if ins.sat else _clamp(y, -1.0, 1.0)
                if z != y:
                    res.clamped += 1
                out.append(z)
            writes.append((ins, out))
        for ins, out in writes:
            cur = reg.setdefault(ins.dst, [0.0] * 4)
            reg[ins.dst] = [out[k] if ins.mask & (8 >> k) else cur[k] for k in range(4)]
    res.out = [_clamp(x, 0.0, 1.0) for x in reg["r0"]]
    return res


# ---------------------------------------------------------------------------------------------------------------
# The proof: our bgfx translation (shaders/fx/) against the interpreter, through shader_equiv's SPIR-V machine
def backend_params():
    """The filter program's uniforms per (level, side), as bgfx_effects.cpp sets them (pddi_smoke --fx-params);
    None when the host smoke binary is not built."""
    if not os.path.exists(SMOKE):
        return None
    r = subprocess.run([SMOKE, "--fx-params"], capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        return None
    out = {}
    for line in r.stdout.splitlines():
        f = line.split()
        if len(f) == 10:
            out[(int(f[0]), int(f[1]))] = [float(x) for x in f[2:]]
    return out


def shader_setup(name, params):
    """Which translation draws program `name`, with which u_fxProg / u_fxK (bgfx_effects.cpp's settings)."""
    if name.startswith("blur"):
        n = int(name[4:])
        return "blur", [float(n), 0.0, 0.0, 0.0], None
    if name == "composite":
        return "blur", [2.0, 1.0, 0.0, 0.0], None
    if name == "threshold":
        return "filter", [1.0, 0.0, 0.0, 0.0], [1.0, 1.0, 1.0, 1.0]
    _, lv, side = name.split("-")
    p = params[(int(lv), int(side))]
    return "filter", p[:4], p[4:]


def _rand_texel(r):
    if r.random() < 0.1:
        return [r.choice((0.0, 1.0)) for _ in range(4)]
    return [r.randrange(256) / 255.0 for _ in range(4)]


def _rand_const(r):
    return [r.choice((0.0, 1.0, 0.5)) if r.random() < 0.1 else r.random() for _ in range(4)]


def _directed():
    """All black / all white texels with all-zero, all-one and all-half constants."""
    out = []
    for t in (0.0, 1.0):
        for c in (0.0, 0.5, 1.0):
            out.append(({n: [t] * 4 for n in range(4)}, {i: [c] * 4 for i in range(8)}))
    return out


def prove_one(name, text, spv_module, setup, n_inputs, seed, se):
    """One program against one compiled translation. Returns the report dict."""
    prog = Program(text, name)
    kind, fx_prog, fx_k = setup
    r = random.Random(seed)
    cases = [("directed", t, c) for t, c in _directed()]
    for k in range(n_inputs):
        cases.append(("random", {n: _rand_texel(r) for n in range(4)}, {i: _rand_const(r) for i in range(8)}))
    ins, outs, unis = spv_module.interface()
    out_name = next(nm for nm, d in outs.items() if not d["builtin"])
    in_names = sorted(nm for nm, d in ins.items() if not d["builtin"])
    run_n, compared, ambiguous, inside, clamped, mism = 0, 0, 0, 0, 0, []
    max_diff = 0.0
    undefined = 0
    for idx, (mode, tex, consts) in enumerate(cases):
        ref = run(prog, tex, consts)
        if ref.undefined:
            undefined += 1
            continue
        # distinct coordinates per set; the texel model answers only (sampler n, coordinate set n)
        coords = {n: (r.uniform(0.0, 1.0), r.uniform(0.0, 1.0)) for n in range(4)}
        table = {("s_fx%d" % n, tuple(se.f32(x) for x in coords[n])): tex[n] for n in range(4)}

        def sample(sampler, uv, table=table):
            key = (sampler, tuple(uv[:2]))
            if key in table:
                return table[key]
            return [0.123, 0.456, 0.789, 0.321]          # a sampler read at another set's coordinates
        m = se.Machine(spv_module, sample=sample)
        sin = {}
        for nm in in_names:
            n = int(nm[-1])
            sin[nm] = list(coords[n])
        for nm, d in ins.items():
            if d["builtin"]:
                sin[nm] = (0.0, 0.0, 0.0, 0.0) if d["type"].kind == "vector" else 0
        sun = {"u_fxC": [[q8(x) for x in consts.get(i, [0.0] * 4)] for i in range(8)], "u_fxProg": fx_prog}
        if fx_k is not None:
            sun["u_fxK"] = fx_k
        # members the compiled shader declares (spirv-opt drops the unused)
        members = set()
        for d in unis.values():
            members.update(d["members"])
        sun = {k: (v if k != "u_fxC" else v[:_array_len(unis, "u_fxC")]) for k, v in sun.items() if k in members}
        got = m.run(sin, sun)[out_name]
        run_n += 1
        clamped += ref.clamped > 0
        ambiguous_here = ref.margin < CND_MARGIN
        if ambiguous_here:
            ambiguous += 1
            continue
        bad = []
        for k in range(4):
            want, have = ref.out[k], got[k]
            if 0.0 < want < 1.0:
                inside += 1
            compared += 1
            d = abs(have - want) if math.isfinite(have) else math.inf
            max_diff = max(max_diff, d)
            if d > TOL:
                bad.append(dict(output="rgba"[k], got=have, expected=want))
        if bad:
            mism.append(dict(case=idx, kind=mode, diffs=bad, texels={n: tex[n] for n in prog.tex},
                             constants={i: [q8(x) for x in consts[i]] for i in prog.constants()}))
    rep = dict(program=name, shader=kind, instructions=prog.instructions, pixels_run=run_n,
               components_compared=compared, ambiguous=ambiguous, undefined_skipped=undefined,
               inside_0_1=inside, pixels_with_a_clamp=clamped, max_diff=max_diff, mismatches=mism[:5],
               mismatching_pixels=len(mism), u_fxProg=fx_prog, u_fxK=fx_k)
    if mism:
        rep["status"] = "fail"
    elif run_n - ambiguous < 50:
        rep["status"] = "inconclusive"
    else:
        rep["status"] = "equivalent"
    return rep


def _array_len(unis, member):
    for d in unis.values():
        if member in d["members"]:
            t = d["members"][member]["type"]
            return t.count if t.kind == "array" else 1
    return 0


def prove(filter_src=None, blur_src=None, n_inputs=3000, seed=1, only=None, quick=False):
    import shader_equiv as se
    t0 = time.time()
    filter_src = filter_src or os.path.join(FX_DIR, "fs_fx_filter.sc")
    blur_src = blur_src or os.path.join(FX_DIR, "fs_fx_blur.sc")
    params = backend_params()
    out = dict(filter=os.path.relpath(os.path.abspath(filter_src), ROOT),
               blur=os.path.relpath(os.path.abspath(blur_src), ROOT), params_from="pddi_smoke --fx-params",
               tolerance=dict(abs=TOL, cnd_margin=CND_MARGIN), level1={}, programs=[])
    if params is None:
        out.update(status="error", error="no %s: run tools/wine_gfx.py pddi" % os.path.relpath(SMOKE, ROOT))
        return out
    mods = {}
    for kind, src in (("filter", filter_src), ("blur", blur_src)):
        od = os.path.join(se.OUT_DIR, "fx", os.path.basename(src)[:-3])
        for prof in (["spirv"] if quick else list(se.PROFILES)):
            path, err = se.compile_sc(src, prof, od, stype="fragment")
            out["level1"]["%s %s" % (kind, prof)] = "ok" if path else "FAILED: " + err
            if prof == "spirv" and path:
                mods[kind] = se.load(path)[1]
    if not all(v == "ok" for v in out["level1"].values()):
        out["status"] = "compile_error"
        return out
    progs = programs()
    for name, (text, who) in progs.items():
        if only and name not in only:
            continue
        setup = shader_setup(name, params)
        rep = prove_one(name, text, mods[setup[0]], setup, n_inputs, seed, se)
        rep["assembled_by"] = who
        out["programs"].append(rep)
    st = [p["status"] for p in out["programs"]]
    out["status"] = "fail" if "fail" in st else "inconclusive" if "inconclusive" in st or not st else "equivalent"
    out["time"] = round(time.time() - t0, 1)
    return out


def text_report(rep):
    lines = ["shaders: %s, %s; tolerance %.3g absolute per component (cnd within %.3g of 0.5: not compared)" % (
        rep["filter"], rep["blur"], rep["tolerance"]["abs"], rep["tolerance"]["cnd_margin"])]
    if rep.get("error"):
        lines.append("  " + rep["error"])
    for k, v in rep.get("level1", {}).items():
        if v != "ok":
            lines.append("  compile %s: %s" % (k, v))
    for p in rep["programs"]:
        lines.append("  %-12s %-6s %-12s %2d instr, %d pixels, %d components, max diff %.2g, %d with a clamp, "
                     "%d inside (0,1), %d ambiguous" % (
                         p["program"], p["shader"], p["status"], p["instructions"], p["pixels_run"],
                         p["components_compared"], p["max_diff"], p["pixels_with_a_clamp"], p["inside_0_1"],
                         p["ambiguous"]))
        for m in p["mismatches"][:1]:
            d = m["diffs"][0]
            lines.append("      first difference: pixel %d (%s): %s = %.9g, expected %.9g; texels %s constants %s"
                         % (m["case"], m["kind"], d["output"], d["got"], d["expected"],
                            {k: ["%.4g" % x for x in v] for k, v in m["texels"].items()},
                            {k: ["%.4g" % x for x in v] for k, v in m["constants"].items()}))
            lines.append("      %d of %d pixels differ" % (p["mismatching_pixels"], p["pixels_run"]))
    lines.append("%s (%d programs, %s s)" % (rep["status"], len(rep["programs"]), rep.get("time", "?")))
    return "\n".join(lines)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("list")
    s = sub.add_parser("show")
    s.add_argument("name")
    s = sub.add_parser("prove")
    s.add_argument("--filter", help="the colour-pass translation (default shaders/fx/fs_fx_filter.sc)")
    s.add_argument("--blur", help="the sums' translation (default shaders/fx/fs_fx_blur.sc)")
    s.add_argument("--inputs", type=int, default=3000)
    s.add_argument("--seed", type=int, default=1)
    s.add_argument("--only", action="append")
    s.add_argument("--quick", action="store_true", help="compile SPIR-V only")
    s.add_argument("--json", action="store_true")
    a = ap.parse_args(argv)
    if a.cmd == "list":
        for name, (text, who) in programs().items():
            p = Program(text, name)
            print("%-12s %-8s %2d instructions, constants %s  (%s)" % (
                name, p.version, p.instructions, ",".join("c%d" % c for c in p.constants()), who))
        return 0
    if a.cmd == "show":
        print(programs()[a.name][0], end="")
        return 0
    rep = prove(a.filter, a.blur, a.inputs, a.seed, a.only, a.quick)
    print(json.dumps(rep) if a.json else text_report(rep))
    return 0 if rep["status"] == "equivalent" else 1


if __name__ == "__main__":
    sys.exit(main())
