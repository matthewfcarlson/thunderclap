$input v_texcoord0

// Lens flare (wlens1): the flare's features at quarter size (blurred and added by the composite).
//   ghosts and a halo of the strong small lights (fs_rm_fbright.sc), mirrored through the centre, the colours split a
//   little; and the sun: a glow, a faint horizontal streak and five tinted ghosts along the line from the sun through
//   the centre, scaled by how much of the sun's disc the depth shows as sky.
//   s_rmTex0 the bright texels, s_rmTex1 the scene's depth, s_rmTex2 the scene copy
//   u_rmFlare[1] x ghosts' gain, y halo's gain, z the aspect (width / height), w the sun's strength (0: none)
//   u_rmFlare[2] xy the sun (uv); u_rmFlare[3] the depth rows (lensViewZ)
#include <bgfx_shader.sh>
// (the lens shaders' shared helpers, copied in each: a new .sh include recompiles every runner shader)

// the view depth (world units, positive) of a D3D depth d
float lensViewZ(float d, vec4 p)
{
    return abs((p.y - d * p.w) / min(d * p.z - p.x, -1e-7));
}

// the signed circle of confusion (-1 near .. 0 in focus .. 1 far) of view depth z with the focus f: a thin lens's
// |1/f - 1/z| times the aperture k, past a band (a close-up's background blurs, a wide shot stays sharp)
float lensCoc(float z, float f, float band, float k)
{
    float r = (1.0 / max(f, 0.05) - 1.0 / max(z, 0.05)) * k;
    float s = clamp((abs(r) - band) * 1.25, 0.0, 1.0);
    return r < 0.0 ? -s : s;
}

float lensLum(vec3 c) { return dot(c, vec3(0.2126, 0.7152, 0.0722)); }

float lensHash(vec2 p)
{
    vec3 q = fract(vec3(p.x, p.y, p.x) * 0.1031);
    q += dot(q, q.yzx + 33.33);
    return fract((q.x + q.y) * q.z);
}

SAMPLER2D(s_rmTex0, 0);
SAMPLER2D(s_rmTex1, 1);
SAMPLER2D(s_rmTex2, 2);
uniform vec4 u_rmFlare[4];

vec3 ghostTint(float i)
{
    return i < 0.5 ? vec3(1.0, 0.75, 0.45) : i < 1.5 ? vec3(0.55, 0.85, 1.0) : i < 2.5 ? vec3(0.75, 1.0, 0.6)
                                                                                 : vec3(0.9, 0.6, 1.0);
}

vec3 splitTap(vec2 uv, vec2 dir)
{
    return vec3(texture2DLod(s_rmTex0, uv + dir * 0.006, 0.0).r, texture2DLod(s_rmTex0, uv, 0.0).g,
                texture2DLod(s_rmTex0, uv - dir * 0.006, 0.0).b);
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    float asp = u_rmFlare[1].z;
    vec3 o = vec3_splat(0.0);
    // the strong lights' ghosts: the bright image mirrored through the centre at four scales
    vec2 m = vec2_splat(1.0) - uv;
    vec2 gv = (vec2_splat(0.5) - m) * 0.38;
    vec2 dir = normalize(gv + vec2(1e-5, 1e-5));
    for (int i = 0; i < 4; i++) {
        vec2 s = m + gv * float(i);
        float fall = pow(clamp(1.0 - length(vec2_splat(0.5) - s) / 0.7071, 0.0, 1.0), 6.0);
        float inside = step(0.0, s.x) * step(s.x, 1.0) * step(0.0, s.y) * step(s.y, 1.0);
        o += splitTap(s, dir) * ghostTint(float(i)) * fall * inside * (i == 0 ? 0.35 : 0.6);
    }
    vec2 hs = m + dir * 0.42;
    float hfall = pow(clamp(1.0 - length(vec2_splat(0.5) - fract(hs)) / 0.7071, 0.0, 1.0), 4.0);
    vec3 halo = splitTap(hs, dir) * hfall;
    o = o * u_rmFlare[1].x * 0.5 + halo * u_rmFlare[1].y * 0.35;
    // the sun
    float sunK = u_rmFlare[1].w;
    if (sunK > 0.0) {
        vec2 su = u_rmFlare[2].xy;
        float vis = 0.0;
        for (int j = 0; j < 3; j++)
            for (int i = 0; i < 3; i++) {
                vec2 t = su + vec2(float(i) - 1.0, (float(j) - 1.0) * asp) * 0.008;
                float inside = step(0.0, t.x) * step(t.x, 1.0) * step(0.0, t.y) * step(t.y, 1.0);
                float z = lensViewZ(texture2DLod(s_rmTex1, clamp(t, vec2_splat(0.0), vec2_splat(1.0)), 0.0).x,
                                    u_rmFlare[3]);
                vis += inside * step(600.0, z);
            }
        vis /= 9.0;
        // (a clear sky there: the copy's brightness at the sun)
        float sky = smoothstep(0.35, 0.8, lensLum(texture2DLod(s_rmTex2, clamp(su, vec2_splat(0.0),
                                                                                vec2_splat(1.0)), 0.0).rgb));
        float k = sunK * vis * mix(0.35, 1.0, sky);
        if (k > 0.001) {
            vec2 d = (uv - su) * vec2(asp, 1.0);
            float r2 = dot(d, d);
            vec3 sunCol = vec3(1.0, 0.92, 0.78);
            o += sunCol * (exp(-r2 / 0.004) * 0.35 + exp(-r2 / 0.06) * 0.12) * k;
            o += sunCol * exp(-abs(d.y) / 0.006) * exp(-abs(d.x) / 0.35) * 0.10 * k;
            vec2 axis = vec2_splat(0.5) - su;
            for (int i = 0; i < 5; i++) {
                float fi = float(i);
                float t = 0.55 + 0.38 * fi;
                vec2 p = su + axis * 2.0 * t * (i == 2 ? 0.7 : 1.0);
                float rad = 0.018 + 0.022 * fract(fi * 0.618 + 0.3);
                vec2 q = (uv - p) * vec2(asp, 1.0);
                float disc = 1.0 - smoothstep(rad * 0.7, rad, length(q));
                o += ghostTint(mod(fi, 4.0)) * disc * 0.06 * k;
            }
        }
    }
    gl_FragColor = vec4(o, 1.0);
}
