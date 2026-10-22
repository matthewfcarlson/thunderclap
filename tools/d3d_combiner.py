#!/usr/bin/env python3
"""Direct3D 8's texture-stage combiner as a reference, and a proof of our combiner programs against it: each of the
100 keys of shaders/vp/combiners.txt through its generated program (fs_cmb_<hash>.sc) and through the generic one
(fs_vp_stage.sc, the stages as uniforms), on fuzzed interpolants, texels and state (docs/shaders.md, "Pixel side").

  build/venv/bin/python tools/d3d_combiner.py prove                 # 100 keys x 2 programs, 600 pixels each
  build/venv/bin/python tools/d3d_combiner.py prove --inputs 3000 --only 'c4.2.0a4.2.0r1' --json
  build/venv/bin/python tools/d3d_combiner.py prove --stage-sh tests/shaders/fixtures/fs_wrong_vp_stage.sh

The reference is written from Microsoft's public Direct3D 8 documentation of the texture stage states (D3DTOP_*,
D3DTA_* with the complement and alpha-replicate modifiers, D3DTSS_RESULTARG, the stage's result in [0, 1]), the
specular add, the alpha test on the 8-bit alpha and linear fog, in Xbox D3D numbering (the values the game's helpers
write: bgfx_pddi.h, bgfxContext::Stage). It is a second, separate implementation of what fs_vp_stage.sh does (the
self-test's sweep page has a third, in C++, checked on the GPU). The texture model: sampler n answers only at stage
n's coordinates times its scale (1, or 1 / size for linear textures).
"""
import argparse
import json
import math
import os
import random
import shutil
import sys
import time

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
VP = os.path.join(ROOT, "src/platform/sdl/pddi/shaders/vp")
TOL = 2.0 ** -16                # absolute, per output component (1/257 of an 8-bit step)
ALPHA_MARGIN = 1e-3             # an alpha this close (in 1/255 units) to a rounding edge: the test is ambiguous

DIFFUSE, CURRENT, TEXTURE, TFACTOR, SPECULAR, TEMP = 0, 1, 2, 3, 4, 5
COMPLEMENT, ALPHAREPLICATE = 0x10, 0x20


def _sat(x):
    return 0.0 if x < 0.0 else 1.0 if x > 1.0 else x


def arg(a, regs):
    """D3DTA_*: the register, then the modifiers (complement 1 - x, alpha replicate)."""
    sel = a & 0xf
    v = list(regs[{DIFFUSE: "diffuse", CURRENT: "current", TEXTURE: "texture", TFACTOR: "tfactor",
                   SPECULAR: "specular", TEMP: "temp"}[sel]])
    if a & COMPLEMENT:
        v = [1.0 - x for x in v]
    if a & ALPHAREPLICATE:
        v = [v[3]] * 4
    return v


def op(o, a1, a2, a0, regs, alpha):
    """One D3DTOP (Xbox numbering) on 4-vectors; `alpha`: evaluating the alpha operation (on the .w components)."""
    w = 3
    if o == 2:
        return a1
    if o == 3:
        return a2
    if o in (4, 5, 6):
        k = {4: 1.0, 5: 2.0, 6: 4.0}[o]
        return [a1[i] * a2[i] * k for i in range(4)]
    if o == 7:
        return [a1[i] + a2[i] for i in range(4)]
    if o == 8:
        return [a1[i] + a2[i] - 0.5 for i in range(4)]
    if o == 9:
        return [2.0 * (a1[i] + a2[i] - 0.5) for i in range(4)]
    if o == 10:
        return [a1[i] - a2[i] for i in range(4)]
    if o == 11:
        return [a1[i] + a2[i] - a1[i] * a2[i] for i in range(4)]
    if o in (12, 13, 14, 15):
        f = {12: regs["diffuse"], 13: regs["current"], 14: regs["texture"], 15: regs["tfactor"]}[o][w]
        return [a1[i] * f + a2[i] * (1.0 - f) for i in range(4)]
    if o == 16:
        return [a1[i] + a2[i] * (1.0 - regs["texture"][w]) for i in range(4)]
    if o == 18:                       # modulatealpha_addcolor: arg1.rgb + arg1.a x arg2.rgb
        return [a1[i] + a1[w] * a2[i] for i in range(3)] + [a1[w]]
    if o == 19:                       # modulatecolor_addalpha: arg1.rgb x arg2.rgb + arg1.a
        return [a1[i] * a2[i] + a1[w] for i in range(3)] + [a1[w]]
    if o == 20:                       # modulateinvalpha_addcolor: (1 - arg1.a) x arg2.rgb + arg1.rgb
        return [(1.0 - a1[w]) * a2[i] + a1[i] for i in range(3)] + [a1[w]]
    if o == 21:                       # modulateinvcolor_addalpha: (1 - arg1.rgb) x arg2.rgb + arg1.a
        return [(1.0 - a1[i]) * a2[i] + a1[w] for i in range(3)] + [a1[w]]
    if o == 22:
        d = 4.0 * sum((a1[i] - 0.5) * (a2[i] - 0.5) for i in range(3))
        return [_sat(d)] * 4
    if o == 23:
        return [a0[i] + a1[i] * a2[i] for i in range(4)]
    if o == 24:
        return [a0[i] * a1[i] + (1.0 - a0[i]) * a2[i] for i in range(4)]
    raise ValueError("D3DTOP %d is not modelled" % o)


def reference(stages, px):
    """stages: [(colour op, arg1, arg2, alpha op, arg1, arg2, result)]; px: the pixel's inputs. -> (rgba or None
    when the alpha test discards, ambiguous)."""
    regs = dict(diffuse=px["diffuse"], specular=px["specular"], tfactor=px["tfactor"], current=list(px["diffuse"]),
                temp=[0.0] * 4)
    for n, (cop, ca1, ca2, aop, aa1, aa2, res) in enumerate(stages):
        if cop == 1:
            break
        regs["texture"] = px["texels"][n]
        c = op(cop, arg(ca1, regs), arg(ca2, regs), regs["current"], regs, False)
        a = op(aop, arg(aa1, regs), arg(aa2, regs), regs["current"], regs, True) if aop != 1 else regs["current"]
        out = [_sat(c[0]), _sat(c[1]), _sat(c[2]), _sat(a[3])]
        regs["temp" if res == TEMP else "current"] = out
    c = list(regs["current"])
    if px["spec_add"]:
        c = [c[i] + px["specular"][i] for i in range(3)] + [c[3]]
    ambiguous = False
    if px["alpha_cmp"] >= 0:
        x = _sat(c[3]) * 255.0
        if abs((x + 0.5) - math.floor(x + 0.5) - 0.0) < ALPHA_MARGIN or abs(x + 0.5 - math.floor(x + 0.5) - 1.0) \
                < ALPHA_MARGIN:
            ambiguous = True
        a8 = math.floor(x + 0.5)
        ref = px["alpha_ref"]
        f = px["alpha_cmp"]
        ok = {0: False, 1: True, 2: a8 < ref, 3: a8 <= ref, 4: a8 > ref, 5: a8 >= ref, 6: a8 == ref,
              7: a8 != ref}[f]
        if not ok:
            return None, ambiguous
    if px["fog_on"]:
        s, e = px["fog_start"], px["fog_end"]
        k = _sat((e - px["fog"]) / (e - s)) if e != s else 1.0
        c = [px["fog_colour"][i] * (1.0 - k) + c[i] * k for i in range(3)] + [c[3]]
    return [_sat(x) for x in c], ambiguous


# ---------------------------------------------------------------------------------------------------------------
def _byte4(r):
    return [r.randrange(256) / 255.0 for _ in range(4)]


def make_pixel(r):
    px = dict(diffuse=_byte4(r), specular=_byte4(r), tfactor=_byte4(r), texels=[_byte4(r) for _ in range(4)],
              uv=[[r.uniform(0, 1), r.uniform(0, 1), r.uniform(-1, 1), r.uniform(-1, 1)] for _ in range(4)],
              scale=[r.choice((1.0, 1.0, 1.0 / 64, 1.0 / 640)) for _ in range(4)], offset=[0.0] * 4,
              spec_add=r.random() < 0.5, alpha_cmp=r.choice((-1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7)),
              alpha_ref=float(r.randrange(256)), fog_on=r.random() < 0.5, fog_colour=_byte4(r),
              fog_start=r.uniform(0, 100), fog=r.uniform(-50, 400))
    px["fog_end"] = px["fog_start"] + r.uniform(1, 300)
    # a render-target copy where targets are bottom-up (G5): v x -scale + 1
    px["vscale"] = [(-x if r.random() < 0.25 else x) for x in px["scale"]]
    px["offset"] = [1.0 if v < 0 else 0.0 for v in px["vscale"]]
    for t in px["texels"] + [px["diffuse"]]:
        if r.random() < 0.1:
            t[3] = r.choice((0.0, 1.0))
    return px


def uniforms(stages, px):
    f = [[0.0] * 4 for _ in range(16)]
    f[0] = [px["alpha_ref"], float(px["alpha_cmp"]), 1.0 if px["spec_add"] else 0.0, 0.0]
    f[1] = list(px["fog_colour"][:3]) + [1.0 if px["fog_on"] else 0.0]
    f[2] = [px["fog_start"], px["fog_end"], 0.0, 0.0]
    f[3] = list(px["tfactor"])
    f[4] = [px["scale"][0], px["vscale"][0], px["scale"][1], px["vscale"][1]]
    f[5] = [px["scale"][2], px["vscale"][2], px["scale"][3], px["vscale"][3]]
    f[14] = [0.0, px["offset"][0], 0.0, px["offset"][1]]
    f[15] = [0.0, px["offset"][2], 0.0, px["offset"][3]]
    for i in range(4):
        if i < len(stages):
            cop, ca1, ca2, aop, aa1, aa2, res = stages[i]
            f[6 + 2 * i] = [float(cop), float(ca1), float(ca2), float(aop)]
            f[7 + 2 * i] = [float(aa1), float(aa2), float(res), 0.0]
        else:
            f[6 + 2 * i] = [1.0, 0.0, 0.0, 1.0]
    return f


def prove_key(key, stages, mod, se, n_inputs, seed):
    r = random.Random("%s/%d" % (key, seed))
    ins, outs, unis = mod.interface()
    out_name = next(nm for nm, d in outs.items() if not d["builtin"])
    machine = None
    run_n, compared, ambiguous, discarded, inside, mism, maxd = 0, 0, 0, 0, 0, [], 0.0
    for idx in range(n_inputs):
        px = make_pixel(r)
        table = {}
        for n in range(4):
            uv = [se.f32(x) for x in px["uv"][n][:2]]
            su, sv, ov = se.f32(px["scale"][n]), se.f32(px["vscale"][n]), px["offset"][n]
            # what the stage samples at: u x scale, v x (+-scale) + offset (one rounding each; a fused
            # multiply-add would differ in the last bit: the key is looked up both ways)
            key = (se.f32(uv[0] * su), se.f32(se.f32(uv[1] * sv) + ov))
            table[("s_pddiTex%d" % n, key)] = px["texels"][n]
            table[("s_pddiTex%d" % n, (key[0], se.f32(uv[1] * sv + ov)))] = px["texels"][n]

        def sample(name, coord, table=table):
            return table.get((name, tuple(coord[:2])), [0.123, 0.456, 0.789, 0.321])
        machine = se.Machine(mod, sample=sample)
        sin = {"v_color0": px["diffuse"], "v_color1": px["specular"], "v_fog": px["fog"]}
        for n in range(4):
            sin["v_texcoord%d" % n] = px["uv"][n]
        sin = {k: v for k, v in sin.items() if k in ins}
        want, amb = reference(stages, px)
        if amb:
            ambiguous += 1
            continue
        try:
            got = list(machine.run(sin, {"u_pddiFrag": uniforms(stages, px)})[out_name])
        except se.ExecError as e:
            if "OpKill" not in str(e) and "OpTerminateInvocation" not in str(e):
                raise
            got = None
        run_n += 1
        if want is None or got is None:
            if want is None:
                discarded += 1
            if (want is None) != (got is None):
                mism.append(dict(pixel=idx, got=got, expected=want, what="alpha test"))
            continue
        bad = []
        for k in range(4):
            compared += 1
            if 0.0 < want[k] < 1.0:
                inside += 1
            d = abs(got[k] - want[k]) if math.isfinite(got[k]) else math.inf
            maxd = max(maxd, d)
            if d > TOL:
                bad.append("rgba"[k])
        if bad:
            mism.append(dict(pixel=idx, got=got, expected=want, what=",".join(bad)))
    enough = min(50, max(10, n_inputs // 4))         # pixels the alpha test kept
    st = "fail" if mism else "inconclusive" if run_n - discarded < enough else "equivalent"
    return dict(status=st, pixels=run_n, components=compared, ambiguous=ambiguous, discarded=discarded,
                inside_0_1=inside, max_diff=maxd, mismatches=mism[:3], mismatching=len(mism))


def prove(n_inputs=600, seed=1, only=None, stage_sh=None, quick=True):
    import shader_equiv as se
    import wine_gfx as ng
    t0 = time.time()
    keys = ng.read_combiners()
    ng.generate_combiner_shaders()
    work = os.path.join(se.OUT_DIR, "cmb")
    os.makedirs(work, exist_ok=True)
    # the sources compiled from a work directory with the stage code (ours, or a fixture's) beside them
    shutil.copy(stage_sh or os.path.join(VP, "fs_vp_stage.sh"), os.path.join(work, "fs_vp_stage.sh"))
    vdef = os.path.join(VP, "varying.def.sc")
    out = dict(stage_sh=os.path.relpath(os.path.abspath(stage_sh or os.path.join(VP, "fs_vp_stage.sh")), ROOT),
               tolerance=dict(abs=TOL, alpha_margin=ALPHA_MARGIN), keys=[], compile_errors=[])

    def compile_one(src):
        dst = os.path.join(work, os.path.basename(src))
        shutil.copy(src, dst)
        mod = None
        for prof in (["spirv"] if quick else list(se.PROFILES)):
            path, err = se.compile_sc(dst, prof, os.path.join(work, "bin"), stype="fragment", varyingdef=vdef,
                                      includes=[work])
            if not path:
                out["compile_errors"].append("%s %s: %s" % (os.path.basename(src), prof, err[-300:]))
            elif prof == "spirv":
                mod = se.load(path)[1]
        return mod
    generic = compile_one(os.path.join(VP, "fs_vp_stage.sc"))
    for key, h, example in keys:
        if only and key not in only:
            continue
        stages = ng.parse_combiner(key)
        gen = compile_one(os.path.join(ng.GEN_SHADERS, "fs_cmb_%08x.sc" % h))
        row = dict(key=key, example=example)
        for which, mod in (("generated", gen), ("generic", generic)):
            row[which] = prove_key(key, stages, mod, se, n_inputs, seed) if mod else dict(status="compile_error")
        out["keys"].append(row)
    sts = [k[w]["status"] for k in out["keys"] for w in ("generated", "generic")]
    out["status"] = "compile_error" if out["compile_errors"] else "fail" if "fail" in sts else \
        "inconclusive" if "inconclusive" in sts or not sts else "equivalent"
    out["time"] = round(time.time() - t0, 1)
    return out


def text_report(rep, verbose=False):
    lines = ["combiner programs (stage code %s) against the Direct3D 8 texture-stage reference; tolerance %.3g "
             "absolute per component" % (rep["stage_sh"], rep["tolerance"]["abs"])]
    for e in rep["compile_errors"][:5]:
        lines.append("  compile: " + e)
    counts = {}
    for k in rep["keys"]:
        for w in ("generated", "generic"):
            s = k[w]["status"]
            counts[(w, s)] = counts.get((w, s), 0) + 1
            if s != "equivalent" or verbose:
                p = k[w]
                lines.append("  %-44s %-9s %-12s %s" % (k["key"][:44], w, s, "" if s == "compile_error" else
                             "%d pixels, %d discarded, max diff %.2g" % (p["pixels"], p["discarded"], p["max_diff"])))
                for m in p.get("mismatches", [])[:1]:
                    lines.append("      pixel %d (%s): got %s, expected %s; %d pixels differ" % (
                        m["pixel"], m["what"], m["got"], m["expected"], p["mismatching"]))
    px = sum(k[w].get("pixels", 0) for k in rep["keys"] for w in ("generated", "generic"))
    disc = sum(k[w].get("discarded", 0) for k in rep["keys"] for w in ("generated", "generic"))
    ins = sum(k[w].get("inside_0_1", 0) for k in rep["keys"] for w in ("generated", "generic"))
    md = max([k[w].get("max_diff", 0) for k in rep["keys"] for w in ("generated", "generic")] or [0])
    lines.append("  %s; %d pixels (%d discarded by the alpha test), %d components inside (0, 1), max diff %.2g" % (
        ", ".join("%s %s %d" % (w, s, n) for (w, s), n in sorted(counts.items())), px, disc, ins, md))
    lines.append("%s (%d keys x 2 programs, %s s)" % (rep["status"], len(rep["keys"]), rep.get("time", "?")))
    return "\n".join(lines)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("prove")
    s.add_argument("--inputs", type=int, default=600)
    s.add_argument("--seed", type=int, default=1)
    s.add_argument("--only", action="append")
    s.add_argument("--stage-sh", help="another fs_vp_stage.sh (the broken fixture)")
    s.add_argument("--all-profiles", action="store_true", help="also compile every host profile")
    s.add_argument("--json", action="store_true")
    s.add_argument("-v", "--verbose", action="store_true")
    a = ap.parse_args(argv)
    rep = prove(a.inputs, a.seed, a.only, a.stage_sh, quick=not a.all_profiles)
    print(json.dumps(rep) if a.json else text_report(rep, a.verbose))
    return 0 if rep["status"] == "equivalent" else 1


if __name__ == "__main__":
    sys.exit(main())
