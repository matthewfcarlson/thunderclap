// Per-pixel lighting (docs/lighting.md): the lights the faithful vertex paths evaluate per vertex, evaluated here per
// pixel from the interpolated camera-space normal and position, plus the runner's dynamic lights (glowing pickups);
// then the faithful texture-stage combiner, fog and alpha test, unchanged: shaders/vp/fs_vp_stage.sh is included with
// its two vertex colours standing for the lit colours made here (the macros below), so a generated program
// (fs_pxcmb_<hash>) and the generic one combine exactly as their faithful counterparts.
//
// Uniforms: u_vc (the draw's vertex constants, the vertex program's layout), and
//   u_rmPx.x   the lighting model: 0 the vertex colours (an unlit fixed-function draw), 1 Direct3D's fixed-function
//              lights (vs_vp_ff.sh's lightTerm: four lights, Blinn specular with a local viewer), 2 the skin programs
//              (four directional lights, specular from the first with the view axis as the eye)
//   u_rmPx.y   the dynamic lights' count (u_rmLight: 2 vec4 each: camera-space position + radius, colour), z their
//              strength, w: 1 when the draw's normals are to be ignored for them (the face normal from derivatives)
// Bgfx hands the varyings to main only (its HLSL-style profiles), so the lighting is a function main's macros call.

uniform vec4 u_vc[96];
uniform vec4 u_rmPx;
uniform vec4 u_rmLight[16];
// wr3a: sun shadows (run/app/shadows.cpp, docs/hdr-shadows.md). u_rmShadow[0..2] / [4..6]: cascade 0 / 1, camera
// space -> (u, v, depth) in the atlas's first row (the characters' and objects' depth); [8] x the cascades (0: no
// shadows), y the view depth where cascade 1 starts, z the darkening of the baked world in shadow, w of the key light;
// [9] xyz towards the sun (camera space), w the normal offset (camera units); [10] x the v offset of the second row
// (the world's depth), y 1: the draw also takes the world's shadows (characters and objects), z the depth bias, w the
// atlas texel (uv); [11] x the view depth where the shadows have faded out.
uniform vec4 u_rmShadow[12];
SAMPLER2DSHADOW(s_rmShadow, 4);

#define PX_MAX_LIGHTS 8

vec3 pxFaceNormal(vec3 pos)
{
    vec3 f = cross(dFdx(pos), dFdy(pos));
    float l2 = dot(f, f);
    f = l2 > 0.0 ? f * inversesqrt(l2) : vec3(0.0, 0.0, -1.0);
    return dot(f, pos) > 0.0 ? -f : f;          // towards the camera (at the origin)
}

// the dynamic lights: a smooth falloff to zero at the radius, a wrapped N.L (light reaches a little around edges)
vec3 pxDynamic(vec3 pos, vec3 n)
{
    vec3 sum = vec3(0.0, 0.0, 0.0);
    for (int i = 0; i < PX_MAX_LIGHTS; i++) {
        if (float(i) >= u_rmPx.y)
            break;
        vec4 lp = u_rmLight[2 * i];
        vec3 d = lp.xyz - pos;
        float d2 = dot(d, d);
        float r2 = lp.w * lp.w;
        if (d2 < r2) {
            float x = 1.0 - d2 / r2;
            float ndl = d2 > 0.0 ? dot(n, d * inversesqrt(d2)) : 1.0;
            sum += u_rmLight[2 * i + 1].rgb * (x * x * saturate(ndl * 0.75 + 0.25));
        }
    }
    return sum * u_rmPx.z;
}

float pxShadowTap(vec3 q)
{
    float t = u_rmShadow[10].w * 0.5;
    return 0.25 * (shadow2D(s_rmShadow, vec3(q.x - t, q.y - t, q.z)) + shadow2D(s_rmShadow, vec3(q.x + t, q.y - t, q.z)) +
                   shadow2D(s_rmShadow, vec3(q.x - t, q.y + t, q.z)) + shadow2D(s_rmShadow, vec3(q.x + t, q.y + t, q.z)));
}

// the sun's visibility at a camera-space point with normal n (1: lit)
float pxShadow(vec3 pos, vec3 n)
{
    if (u_rmShadow[8].x < 0.5 || pos.z > u_rmShadow[11].x)
        return 1.0;
    vec4 p = vec4(pos + n * u_rmShadow[9].w * (1.0 + pos.z * 0.01), 1.0);
    bool second = u_rmShadow[8].x > 1.5 && pos.z > u_rmShadow[8].y;
    vec3 q = second ? vec3(dot(p, u_rmShadow[4]), dot(p, u_rmShadow[5]), dot(p, u_rmShadow[6]))
                    : vec3(dot(p, u_rmShadow[0]), dot(p, u_rmShadow[1]), dot(p, u_rmShadow[2]));
    if (q.z >= 1.0 || q.z <= 0.0)
        return 1.0;
    q.z -= u_rmShadow[10].z;
    float vis = pxShadowTap(q);
    if (u_rmShadow[10].y > 0.5)
        vis = min(vis, pxShadowTap(vec3(q.x, q.y + u_rmShadow[10].x, q.z)));
    float fade = saturate((pos.z - u_rmShadow[11].x * 0.85) / (u_rmShadow[11].x * 0.15));
    return mix(vis, 1.0, fade);
}

// Direct3D's light i (vs_vp_ff.sh lightTerm, unchanged)
vec3 pxLightTerm(int i, vec3 pos, vec3 n, vec3 eye, inout vec3 spec)
{
    vec4 lp = u_vc[14 + 4 * i];
    vec4 ld = u_vc[15 + 4 * i];
    vec4 lc = u_vc[16 + 4 * i];
    vec4 la = u_vc[17 + 4 * i];
    vec3 l;
    float att = 1.0;
    if (lp.w > 2.5) {
        float dl2 = dot(ld.xyz, ld.xyz);
        l = dl2 > 0.0 ? -ld.xyz * inversesqrt(dl2) : vec3(0.0, 0.0, 0.0);
    } else {
        vec3 d = lp.xyz - pos;
        float dist = length(d);
        l = dist > 0.0 ? d / dist : vec3(0.0, 0.0, 1.0);
        float k = la.x + la.y * dist + la.z * dist * dist;
        att = (dist <= ld.w && k > 0.0) ? 1.0 / k : 0.0;
    }
    float ndl = dot(n, l);
    if (ndl <= 0.0)
        return vec3(0.0, 0.0, 0.0);
    vec3 h = normalize(l + eye);
    float ndh = max(dot(n, h), 0.0);
    if (u_vc[13].z > 0.5 && ndh > 0.0)
        spec += lc.rgb * (att * pow(ndh, max(u_vc[11].w, 0.0001)));
    return lc.rgb * (att * ndl);
}

// the lit colours: which = 0 the diffuse colour (v_color0), 1 the specular colour (v_color1); front: the face's side
vec4 pxLit(vec4 base, vec4 spec, vec4 nv, vec3 pos, float which, bool front)
{
    float model = u_rmPx.x;
    bool hasN = nv.w > 0.0001;
    vec3 dir = hasN ? normalize(nv.xyz) : vec3(0.0, 0.0, 0.0);
    if (!front)
        dir = -dir;                                               // (two-sided lighting: the back face's normal)
    vec3 dyn = vec3(0.0, 0.0, 0.0);
    if (u_rmPx.y > 0.5)
        dyn = pxDynamic(pos, (hasN && u_rmPx.w < 0.5) ? dir : pxFaceNormal(pos));
    if (model < 0.5) {                                            // unlit: the vertex colours (+ dynamic light)
        if (which > 0.5)
            return spec;
        vec3 b = base.rgb;
        if (u_rmShadow[8].x > 0.5) {                              // (the baked light under a caster's shadow)
            vec3 fn = (hasN && u_rmPx.w < 0.5) ? dir : pxFaceNormal(pos);
            float facing = saturate(dot(fn, u_rmShadow[9].xyz) * 4.0);
            b *= 1.0 - u_rmShadow[8].z * (1.0 - pxShadow(pos, fn)) * facing;
        }
        return vec4(b + dyn, base.a);
    }
    if (model < 1.5) {                                            // Direct3D fixed function
        vec3 n = dir * nv.w;                                      // (the faithful path's length: no renormalising)
        vec3 eye = -normalize(pos);
        vec3 diffuse = vec3(0.0, 0.0, 0.0);
        vec3 sp = vec3(0.0, 0.0, 0.0);
        float key = u_rmShadow[8].x > 0.5 ? mix(1.0, pxShadow(pos, dir), u_rmShadow[8].w) : 1.0;
        for (int i = 0; i < 4; i++) {
            if (u_vc[14 + 4 * i].w > 0.5) {
                vec3 spi = vec3(0.0, 0.0, 0.0);
                vec3 di = pxLightTerm(i, pos, n, eye, spi);
                float k = i == 0 ? key : 1.0;                     // (the key light, the sun's stand-in, is shadowed)
                diffuse += di * k;
                sp += spi * k;
            }
        }
        vec4 diffuseMat = spec;                                   // (vs_px_ff: the diffuse material rides here)
        if (which > 0.5)
            return saturate(vec4(sp * u_vc[11].rgb, 0.0));
        return saturate(vec4(base.rgb + diffuseMat.rgb * (diffuse + dyn), diffuseMat.a));
    }
    // the skin programs (vs_vp_skin.sc): c102 diffuse, c103 specular (w power), c105+2i / c106+2i the lights
    vec3 n = dir;
    vec3 h = -u_vc[9].xyz - vec3(0.0, 0.0, 1.0);
    h = h * inversesqrt(dot(h, h));
    float ndl = dot(n, -u_vc[9].xyz);
    float ndh = dot(n, h);
    float power = clamp(u_vc[7].w, -127.9961, 127.9961);
    if (which > 0.5) {
        float specular0 = (ndl > 0.0 && ndh > 0.0) ? pow(ndh, power) : 0.0;
        return saturate(vec4(min(max(vec3(0.0, 0.0, 0.0), specular0 * u_vc[10].xyz) * u_vc[7].xyz,
                                 vec3(1.0, 1.0, 1.0)), base.a));
    }
    vec3 colour = base.xyz;
    float key = u_rmShadow[8].x > 0.5 ? mix(1.0, pxShadow(pos, dir), u_rmShadow[8].w) : 1.0;
    colour = max(vec3(0.0, 0.0, 0.0), max(ndl, 0.0) * u_vc[10].xyz) * u_vc[6].xyz * key + colour;
    for (int i = 1; i < 4; i++)
        colour = max(vec3(0.0, 0.0, 0.0), dot(n, -u_vc[9 + 2 * i].xyz) * u_vc[10 + 2 * i].xyz) * u_vc[6].xyz + colour;
    colour += dyn * u_vc[6].xyz;
    return saturate(vec4(min(colour, vec3(1.0, 1.0, 1.0)), base.a));
}

// two-sided lighting (vs_vp_ff2s, G5): the back face is lit with the reversed normal (fs_px_stage2s.sc)
#ifdef PX_TWO_SIDED
#define PX_FRONT gl_FrontFacing
#else
#define PX_FRONT true
#endif
#define v_color0 pxLit(v_pxbase, v_pxspec, v_pxnormal, v_pxpos, 0.0, PX_FRONT)
#define v_color1 pxLit(v_pxbase, v_pxspec, v_pxnormal, v_pxpos, 1.0, PX_FRONT)
#include "fs_vp_stage.sh"
