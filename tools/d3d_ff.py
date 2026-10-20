#!/usr/bin/env python3
"""Direct3D 8's fixed-function vertex pipeline as the game configures it, and a proof of our vs_vp_ff.sc against it
(docs/shaders.md, "Fixed function").

  build/venv/bin/python tools/d3d_ff.py prove                       # every configuration, 3000 vertices each
  build/venv/bin/python tools/d3d_ff.py prove --inputs 600 --only lit-spec-points --json
  build/venv/bin/python tools/d3d_ff.py prove --src tests/shaders/fixtures/vs_wrong_ff.sc
  build/venv/bin/python tools/d3d_ff.py configs                     # the configurations and what selects them

The reference is written from Microsoft's public Direct3D 8 documentation of the fixed-function pipeline
(transformation, the lighting equations, texture coordinate generation and transformation, fog) and the state the
game gives it, read from our verified sources:
  - FUN_00320c60 (the context's device set-up; equivalent/0x00320c60 in the tree's d3dExtFramebufferEffects.cpp):
    D3DTS_VIEW and WORLD identity, COLORVERTEX TRUE and every material source (diffuse, specular, ambient, emissive,
    front and back) D3DMCS_MATERIAL. So when lighting is on the vertex colours are not used: the material is.
    (The deferred render-state words it writes, 0x39deb4..0x39ded4, follow LIGHTING 0x39dea8 and SPECULARENABLE
    0x39deac, which FUN_00329f70 sets; AMBIENT is 0x39dedc, the word context slot 35 (0x321990) writes.)
  - FUN_00329f70: LIGHTING with the shader's LIT, SPECULARENABLE when the material's power is above 0, the material.
  - FUN_00321310: each light: type from 0x4d3a10, Diffuse = the light colour, Specular = Diffuse, Ambient = 0,
    position and direction already moved by the matrix the light was set with, range, attenuation, cone.
  - LOCALVIEWER and NORMALIZENORMALS are never set by the game: Direct3D 8's documented defaults, TRUE and FALSE.
    So normals are transformed by the inverse transpose of the world-view matrix and not renormalised.
  - texture coordinates (the shader classes' pass set-up, bgfx_shader.cpp's ports): a uv set per stage, or the
    camera-space reflection vector through a 2-count texture transform (the sphere map: layeredReflect,
    environment).
  - fog: linear table fog (0x39de84 = 3) on the camera-space depth.
What the equations say where the documentation is silent, taken as the reference rasteriser behaves (our reading):
a light adds nothing (diffuse or specular) where N.L <= 0; the specular term is 0 where N.H <= 0.

vs_vp_ff.sc's constants are laid out by bgfx_draw.cpp ffConstants; constants() below is that layout (a mirror, kept
in step by hand; the self-test pages check the C++ side on the GPU).
"""
import argparse
import json
import math
import os
import random
import sys
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
SRC = os.path.join(ROOT, "src/platform/sdl/pddi/shaders/vp/vs_vp_ff.sc")

TOL_COLOUR = 2.0 ** -14          # colours: absolute (1/64 of an 8-bit step)
TOL_REL = 2.0 ** -16             # positions, fog, coordinates: relative to the magnitudes summed
AMBIG_NL = 1e-4                  # |N.L| or |N.H| this close to 0, or a point light this close to its range: ambiguous
TCI_NORMAL, TCI_POSITION, TCI_REFLECT = 0x10000, 0x20000, 0x30000
D3D_POINT, D3D_SPOT, D3D_DIRECTIONAL = 1, 2, 3


# ---------------------------------------------------------------------------------------------------------------
# small linear algebra (row vectors, as Direct3D: v' = v M; matrices row-major lists of 16)
def vm(v, m):
    return [sum(v[k] * m[k * 4 + i] for k in range(4)) for i in range(4)]


def vm_env(v, m):
    return [sum(abs(v[k] * m[k * 4 + i]) for k in range(4)) for i in range(4)]


def mm(a, b):
    return [sum(a[r * 4 + k] * b[k * 4 + c] for k in range(4)) for r in range(4) for c in range(4)]


def dot3(a, b):
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]


def norm3(a):
    n = math.sqrt(dot3(a, a))
    return [x / n for x in a] if n > 0 else [0.0, 0.0, 0.0]


def inv3(m):
    """The inverse of the upper 3x3 of a row-major 4x4 (as a 3x3 list of rows)."""
    a = [[m[r * 4 + c] for c in range(3)] for r in range(3)]
    det = (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
           a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]))
    cof = [[(a[(r + 1) % 3][(c + 1) % 3] * a[(r + 2) % 3][(c + 2) % 3] -
             a[(r + 1) % 3][(c + 2) % 3] * a[(r + 2) % 3][(c + 1) % 3]) for c in range(3)] for r in range(3)]
    return [[cof[c][r] / det for c in range(3)] for r in range(3)]


def colour4(c):
    """A D3DCOLOR as r, g, b, a in 0..1 (FUN_0031ffc0's conversion)."""
    return [((c >> 16) & 255) / 255.0, ((c >> 8) & 255) / 255.0, (c & 255) / 255.0, (c >> 24) / 255.0]


# ---------------------------------------------------------------------------------------------------------------
# The reference
def normal_matrix(world):
    """Direct3D transforms normals by the inverse transpose of the world-view matrix (VIEW is the identity here):
    n' = n (M^-1)^T for row vectors, i.e. n'_i = sum_k n_k inv[i][k]."""
    return inv3(world)


def reference(st, vtx):
    """One vertex through the fixed-function pipeline. st: the state (make_state); vtx: position, normal, colour0,
    colour1 (D3DCOLOR ints), uv (4 sets of 2). Returns outputs, which components Direct3D defines, error envelopes and
    an ambiguity flag."""
    p = list(vtx["position"]) + [1.0]
    view = vm(p, st["world"])
    view_env = vm_env(p, st["world"])
    clip = vm(view, st["proj"])
    clip_env = [sum(view_env[k] * abs(st["proj"][k * 4 + i]) for k in range(4)) for i in range(4)]
    out = {"oPos": (clip, clip_env), "oFog": ([view[2]], [view_env[2]])}
    inv = normal_matrix(st["world"])
    n = [sum(vtx["normal"][k] * inv[i][k] for k in range(3)) for i in range(3)]
    if st["normalize"]:
        n = norm3(n)
    ambiguous = []
    v3 = view[:3]
    if st["lighting"]:
        md, ms = colour4(st["material"]["diffuse"]), colour4(st["material"]["specular"])
        ma, me = colour4(st["material"]["ambient"]), colour4(st["material"]["emissive"])
        ga = colour4(st["ambient"])
        eye = norm3([-x for x in v3])
        diff, spec = [0.0] * 3, [0.0] * 3
        for L in st["lights"][:4]:
            if not L["on"]:
                continue
            if L["type"] == D3D_DIRECTIONAL:
                ldir = norm3([-x for x in L["direction"]])
                att = 1.0
            else:
                d = [L["position"][k] - v3[k] for k in range(3)]
                dist = math.sqrt(dot3(d, d))
                ldir = [x / dist for x in d] if dist > 0 else [0.0, 0.0, 1.0]
                if abs(dist - L["range"]) < 1e-3 * max(1.0, L["range"]):
                    ambiguous.append("range")
                k = L["att"][0] + L["att"][1] * dist + L["att"][2] * dist * dist
                att = 1.0 / k if dist <= L["range"] and k > 0 else 0.0
            ndl = dot3(n, ldir)
            if abs(ndl) < AMBIG_NL:
                ambiguous.append("N.L")
            if ndl <= 0:
                continue
            for k in range(3):
                diff[k] += L["diffuse"][k] * ndl * att
            if st["specular"]:
                h = norm3([ldir[k] + eye[k] for k in range(3)])
                ndh = dot3(n, h)
                if abs(ndh) < AMBIG_NL:
                    ambiguous.append("N.H")
                if ndh > 0:
                    s = ndh ** st["material"]["power"]
                    for k in range(3):
                        spec[k] += L["diffuse"][k] * s * att           # Specular = Diffuse (FUN_00321310)
        c = [me[k] + ma[k] * ga[k] + md[k] * diff[k] for k in range(3)]
        out["oD0"] = ([min(max(x, 0.0), 1.0) for x in c] + [md[3]], None)
        if st["specular"]:
            out["oD1"] = ([min(max(spec[k] * ms[k], 0.0), 1.0) for k in range(3)], None)
    else:
        b = colour4(vtx["colour0"])
        out["oD0"] = (b, None)
    for s in range(4):
        tci, ttff = st["stages"][s]
        gen = tci >> 16
        if gen == 0:
            uv = vtx["uv"][tci & 3]
            c, defined = [uv[0], uv[1], 1.0, 0.0], 2
            env = [abs(uv[0]), abs(uv[1]), 1.0, 0.0]
        else:
            if gen == 1:
                vec = n
            elif gen == 2:
                vec = v3
            else:
                e = norm3(v3)          # from the eye to the vertex (the eye at the origin; LOCALVIEWER)
                k = 2.0 * dot3(n, e)
                vec = [e[i] - k * n[i] for i in range(3)]
            c, defined = list(vec) + [1.0], 3
            env = [abs(x) for x in vec] + [1.0]
            if gen == 2:
                env = [view_env[0], view_env[1], view_env[2], 1.0]
        if ttff & 0xff:
            m = st["texmats"][s] if s < 3 else [1.0 if i % 5 == 0 else 0.0 for i in range(16)]
            env = [sum(abs(c[k] * m[k * 4 + i]) + env[k] * abs(m[k * 4 + i]) for k in range(4)) for i in range(4)]
            c = vm(c, m)
            defined = ttff & 0xff
        out["oT%d" % s] = (c[:defined], env[:defined])
    return out, ambiguous


# ---------------------------------------------------------------------------------------------------------------
# What the backend uploads (bgfx_draw.cpp ffConstants: the layout in vs_vp_ff.sc)
def constants(st):
    c = [[0.0] * 4 for _ in range(96)]
    w, p = st["world"], st["proj"]
    for i in range(4):
        c[i] = [w[k * 4 + i] for k in range(4)]
        c[4 + i] = [p[k * 4 + i] for k in range(4)]
    m = st["material"]
    c[8], c[9], c[10], c[11] = colour4(m["diffuse"]), colour4(m["ambient"]), colour4(m["emissive"]), \
        colour4(m["specular"])
    c[11][3] = m["power"]
    c[12] = colour4(st["ambient"])
    c[13] = [1.0 if st["lighting"] else 0.0, 0.0, 1.0 if st["lighting"] and st["specular"] else 0.0,
             1.0 if st["normalize"] else 0.0]
    n = 0
    for L in st["lights"]:
        if not L["on"] or n >= 4:
            continue
        q = 14 + 4 * n
        c[q] = list(L["position"]) + [float(L["type"])]
        c[q + 1] = list(L["direction"]) + [L["range"]]
        c[q + 2] = list(L["diffuse"])
        c[q + 3] = list(L["att"]) + [0.0]
        n += 1
    ident = [1.0 if i % 5 == 0 else 0.0 for i in range(16)]
    for s in range(4):
        tci, ttff = st["stages"][s]
        gen = tci >> 16
        c[48 + s] = [float(tci & 3) if gen == 0 else 10.0 if gen == 1 else 11.0 if gen == 2 else 12.0,
                     float(ttff & 0xff), 0.0, 0.0]
        m = st["texmats"][s] if s < 3 else ident
        for i in range(4):
            c[32 + 4 * s + i] = [m[k * 4 + i] for k in range(4)]
    inv = normal_matrix(w)
    for i in range(3):
        c[52 + i] = [inv[i][0], inv[i][1], inv[i][2], 0.0]
    return c


# ---------------------------------------------------------------------------------------------------------------
# States and vertices
def _unit(r):
    while True:
        v = [r.uniform(-1, 1) for _ in range(3)]
        n = math.sqrt(dot3(v, v))
        if 0.1 < n <= 1:
            return [x / n for x in v]


def _affine(r, scale=None, nonuniform=False):
    ax = _unit(r)
    ang = r.uniform(-math.pi, math.pi)
    c, s, t = math.cos(ang), math.sin(ang), 1 - math.cos(ang)
    x, y, z = ax
    rot = [[t * x * x + c, t * x * y + s * z, t * x * z - s * y],
           [t * x * y - s * z, t * y * y + c, t * y * z + s * x],
           [t * x * z + s * y, t * y * z - s * x, t * z * z + c]]
    sc = [scale or 1.0] * 3
    if nonuniform:
        sc = [r.uniform(0.5, 2.0) for _ in range(3)]
    m = [rot[i][j] * sc[i] for i in range(3) for j in range(3)]
    tr = [r.uniform(-20, 20), r.uniform(-20, 20), r.uniform(30, 200)]      # in front of the camera
    return [m[0], m[1], m[2], 0.0, m[3], m[4], m[5], 0.0, m[6], m[7], m[8], 0.0, tr[0], tr[1], tr[2], 1.0]


def _projection(r):
    fov, asp = r.uniform(0.5, 1.6), r.uniform(0.75, 1.8)
    zn, zf = r.uniform(0.1, 2.0), r.uniform(300, 5000)
    ys = 1 / math.tan(fov / 2)
    q = zf / (zf - zn)
    return [ys / asp, 0, 0, 0, 0, ys, 0, 0, 0, 0, q, 1, 0, 0, -zn * q, 0]


def _colour(r):
    return r.randrange(1 << 32)


def _light(r, kind):
    L = dict(on=True, diffuse=[r.uniform(0, 1) for _ in range(3)] + [1.0], range=0.0, att=[0.0, 0.0, 0.0],
             position=[0.0, 0.0, 0.0], direction=[0.0, 0.0, 1.0])
    if kind == "dir":
        L["type"] = D3D_DIRECTIONAL
        L["direction"] = [x * r.uniform(0.3, 2.0) for x in _unit(r)]     # not unit: Direct3D normalises it
    else:
        L["type"] = D3D_POINT
        L["position"] = [r.uniform(-60, 60), r.uniform(-60, 60), r.uniform(0, 250)]
        L["range"] = r.uniform(20, 300)
        L["att"] = [r.uniform(0.2, 1.5), r.uniform(0, 0.05), r.uniform(0, 0.001)]
    return L


def _sphere(r, exact):
    """The reflective classes' texture matrix (scale 0.5, offset 0.5), or a random one."""
    if exact:
        return [0.5, 0, 0, 0, 0, -0.5, 0, 0, 0, 0, 1, 0, 0.5, 0.5, 0, 1]
    return [r.uniform(-1, 1) for _ in range(12)] + [r.uniform(-1, 1) for _ in range(3)] + [1.0]


# name -> (description, what selects it, state maker)
def _cfg(lighting, specular=False, lights=(), stages=((0, 0),), refl_exact=True, scale=None, nonuniform=False):
    def make(r):
        st = dict(world=_affine(r, scale or (r.uniform(0.5, 2.0) if scale == 0 else None), nonuniform),
                  proj=_projection(r), lighting=lighting, specular=specular, normalize=False,
                  material=dict(diffuse=_colour(r), ambient=_colour(r), specular=_colour(r), emissive=_colour(r),
                                power=r.uniform(0.5, 64.0) if specular else 0.0),
                  ambient=_colour(r), lights=[_light(r, k) for k in lights],
                  stages=[tuple(stages[s]) if s < len(stages) else (s, 0) for s in range(4)],
                  texmats=[_sphere(r, refl_exact) if s < len(stages) and stages[s][0] == TCI_REFLECT else
                           _sphere(r, False) for s in range(3)])
        return st
    return make


CONFIGS = {
    "unlit": ("no lighting: the vertex colour; stage 0 uv set 0", "simple/layered LIT 0, prim streams (2D, text)",
              _cfg(False)),
    "unlit-layered": ("no lighting; stages 0/1 uv sets 0/1", "layered (TEX + TTEX)",
                      _cfg(False, stages=((0, 0), (1, 0)))),
    "lit-dir": ("lit, 1-4 directional lights, no specular", "simple/layered LIT 1, power 0",
                _cfg(True, lights=("dir", "dir", "dir", "dir"))),
    "lit-dir1": ("lit, one directional light", "simple LIT 1, one light", _cfg(True, lights=("dir",))),
    "lit-spec-points": ("lit, specular, two point and two directional lights", "LIT 1, SHIN > 0, point lights",
                        _cfg(True, True, ("point", "dir", "point", "dir"), ((0, 0), (1, 0)))),
    "lit-scaled": ("lit, specular, a uniformly scaled modelview (normals by the inverse transpose, not renormalised)",
                   "any lit mesh under a scaled transform", _cfg(True, True, ("dir", "point"), scale=0)),
    "lit-nonuniform": ("lit, a non-uniformly scaled modelview", "a mesh under a non-uniform scale",
                       _cfg(True, False, ("dir", "point"), nonuniform=True)),
    "layered-reflect": ("lit, stages: uv 0, uv 1, the reflection vector through the sphere map (count 2)",
                        "layeredReflect (TEX + TTEX + REFL)",
                        _cfg(True, True, ("dir", "point"), ((0, 0), (1, 0), (TCI_REFLECT, 2)))),
    "environment": ("unlit, stages: uv 0, the reflection vector through the sphere map", "environment (TEX + REFL)",
                    _cfg(False, stages=((0, 0), (TCI_REFLECT, 2)))),
    "texgen-other": ("camera-space normal and position, count 3/4 transforms (no data uses these)",
                     "nothing in the data (the shader supports them)",
                     _cfg(True, False, ("dir",), ((TCI_NORMAL, 3), (TCI_POSITION, 4), (TCI_REFLECT, 0), (1, 2)),
                          refl_exact=False)),
}


def make_vertex(r):
    return dict(position=[r.uniform(-30, 30) for _ in range(3)], normal=[x * r.uniform(0.99, 1.0) for x in _unit(r)],
                colour0=_colour(r), colour1=_colour(r), uv=[[r.uniform(-4, 4), r.uniform(-4, 4)] for _ in range(4)])


def _bgra(c):
    """What a bgfx Uint8-normalised attribute delivers for a D3DCOLOR in memory: B, G, R, A."""
    return [(c & 255) / 255.0, ((c >> 8) & 255) / 255.0, ((c >> 16) & 255) / 255.0, (c >> 24) / 255.0]


OUT_NAMES = {"oPos": "gl_Position", "oD0": "v_color0", "oD1": "v_color1", "oFog": "v_fog", "oB0": "v_bcolor0",
             "oB1": "v_bcolor1",
             "oT0": "v_texcoord0", "oT1": "v_texcoord1", "oT2": "v_texcoord2", "oT3": "v_texcoord3"}


def prove_config(name, mod, se, n_inputs, seed):
    desc, sel, make = CONFIGS[name]
    r = random.Random("%s/%d" % (name, seed))
    ins, outs, unis = mod.interface()
    by_short = {nm.split(".")[-1]: nm for nm in outs}
    run_n, compared, ambiguous, inside, mism, worst = 0, {}, 0, {}, [], 0.0
    machine = se.Machine(mod)
    uni_len = None
    for d in unis.values():
        if "u_vc" in d["members"]:
            uni_len = d["members"]["u_vc"]["type"].count
    states = max(1, n_inputs // 10)
    for idx in range(n_inputs):
        if idx % 10 == 0:
            st = make(r)
            c = constants(st)
        v = make_vertex(r)
        ref, amb = reference(st, v)
        if amb:
            ambiguous += 1
            continue
        sin = {"a_position": v["position"], "a_normal": v["normal"], "a_color0": _bgra(v["colour0"]),
               "a_color1": _bgra(v["colour1"])}
        for s in range(4):
            sin["a_texcoord%d" % s] = v["uv"][s]
        sin = {k: val for k, val in sin.items() if k in ins}
        got = machine.run(sin, {"u_vc": c[:uni_len]})
        run_n += 1
        bad = []
        if "v_bcolor0" in by_short and st["lighting"]:
            # vs_vp_ff2s (two-sided lighting): the back face's colours are the pipeline on the reversed normal
            back, bamb = reference(st, dict(v, normal=[-x for x in v["normal"]]))
            if bamb:
                ambiguous += 1
                continue
            ref = dict(ref, oB0=back["oD0"])
            if "oD1" in back:
                ref["oB1"] = back["oD1"]
        for reg, (want, env) in ref.items():
            nm = by_short.get(OUT_NAMES[reg])
            have = got[nm]
            have = list(have) if isinstance(have, tuple) else [have]
            for j, w in enumerate(want):
                comp = "%s.%s" % (reg, "xyzw"[j])
                tol = TOL_COLOUR if env is None else TOL_REL * max(env[j], 1.0)
                if env is None and 0.0 < w < 1.0:
                    inside[comp] = inside.get(comp, 0) + 1
                compared[comp] = compared.get(comp, 0) + 1
                d = abs(have[j] - w) if math.isfinite(have[j]) else math.inf
                worst = max(worst, d / tol)
                if d > tol:
                    bad.append(dict(output=comp, got=have[j], expected=w, allowed=tol))
        if bad:
            mism.append(dict(vertex=idx, diffs=bad))
    rep = dict(config=name, description=desc, selected_by=sel, vertices_run=run_n, states=states,
               ambiguous=ambiguous, components_compared=sum(compared.values()), compared=compared,
               inside_0_1=inside, worst_ratio=round(worst, 4), mismatches=mism[:5], mismatching=len(mism))
    rep["status"] = "fail" if mism else "inconclusive" if run_n < 50 else "equivalent"
    return rep


def prove(src=None, n_inputs=3000, seed=1, only=None, quick=False):
    import shader_equiv as se
    t0 = time.time()
    src = src or SRC
    out = dict(src=os.path.relpath(os.path.abspath(src), ROOT), tolerance=dict(colour=TOL_COLOUR, relative=TOL_REL),
               level1={}, configs=[])
    od = os.path.join(se.OUT_DIR, "ff", os.path.basename(src)[:-3])
    mod = None
    for prof in (["spirv"] if quick else list(se.PROFILES)):
        path, err = se.compile_sc(src, prof, od)
        out["level1"][prof] = "ok" if path else "FAILED: " + err
        if prof == "spirv" and path:
            mod = se.load(path)[1]
    if mod is None or not all(v == "ok" for v in out["level1"].values()):
        out["status"] = "compile_error"
        return out
    for name in CONFIGS:
        if only and name not in only:
            continue
        out["configs"].append(prove_config(name, mod, se, n_inputs, seed))
    st = [c["status"] for c in out["configs"]]
    out["status"] = "fail" if "fail" in st else "inconclusive" if "inconclusive" in st or not st else "equivalent"
    out["time"] = round(time.time() - t0, 1)
    return out


def text_report(rep):
    lines = ["%s against the Direct3D 8 fixed-function reference; tolerance: colours %.3g absolute, positions/fog/"
             "coordinates %.3g x the magnitudes summed" % (rep["src"], rep["tolerance"]["colour"],
                                                           rep["tolerance"]["relative"])]
    for k, v in rep.get("level1", {}).items():
        if v != "ok":
            lines.append("  compile %s: %s" % (k, v))
    for c in rep["configs"]:
        ins = sum(v for k, v in c["inside_0_1"].items())
        lines.append("  %-16s %-12s %d vertices (%d states), %d components, worst %.0f%% of tolerance, %d colour "
                     "components inside (0,1), %d ambiguous" % (
                         c["config"], c["status"], c["vertices_run"], c["states"], c["components_compared"],
                         100 * c["worst_ratio"], ins, c["ambiguous"]))
        for m in c["mismatches"][:1]:
            d = m["diffs"][0]
            lines.append("      first difference: vertex %d: %s = %.9g, expected %.9g (allowed %.3g); also %s" % (
                m["vertex"], d["output"], d["got"], d["expected"], d["allowed"],
                ", ".join(x["output"] for x in m["diffs"][1:6]) or "-"))
            lines.append("      %d of %d vertices differ" % (c["mismatching"], c["vertices_run"]))
    lines.append("%s (%d configurations, %s s)" % (rep["status"], len(rep["configs"]), rep.get("time", "?")))
    return "\n".join(lines)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("configs")
    s = sub.add_parser("prove")
    s.add_argument("--src")
    s.add_argument("--inputs", type=int, default=3000)
    s.add_argument("--seed", type=int, default=1)
    s.add_argument("--only", action="append")
    s.add_argument("--quick", action="store_true")
    s.add_argument("--json", action="store_true")
    a = ap.parse_args(argv)
    if a.cmd == "configs":
        for k, (d, sel, _) in CONFIGS.items():
            print("%-16s %s\n%-16s selected by: %s" % (k, d, "", sel))
        return 0
    rep = prove(a.src, a.inputs, a.seed, a.only, a.quick)
    print(json.dumps(rep) if a.json else text_report(rep))
    return 0 if rep["status"] == "equivalent" else 1


if __name__ == "__main__":
    sys.exit(main())
