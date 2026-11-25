$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Soft particles (wfx1, run/app/particles.cpp, docs/particles.md): the game's smoke, dust, fire and explosion sprites
// with the faithful texture-stage combiner (shaders/vp/fs_vp_stage.sh, the generic one: its stages from u_pddiFrag),
// fog and alpha test, and three changes:
//   - a depth fade: the sprite's coverage goes to zero where it meets the scene behind it (a copy of the scene's depth
//     taken before the game's sprites), so it no longer ends in a hard line at the ground and the walls; and near the
//     camera, so a sprite the camera is in does not fill the frame;
//   - lighting (smoke and dust, blended over the scene; never additive glows, which are light themselves): darker in
//     the sun's shadow (the shadow atlas, as fs_rm_grass.sc reads it) and lit by the Night Lights' city lights
//     (rm_city.sh), as a volume (no normal: a sprite faces the camera);
//   - additive sprites scaled by a gain (HDR: big flashes no longer white out the frame).
// The fade, the point and the pixel are kept in private globals from the vertex colour (v_color0 below, the combiner's
// first read) to the final clamp (`saturate(c)`, the combiner's last statement), where the light and the fade are
// applied: bgfx hands the varyings and gl_FragColor to main only.
//
// Uniforms:
//   u_rmSoft[0]  x 1 / the fade distance (camera units; 0: no depth fade), y the near fade's start, z 1 / its length,
//                w 1: the fade scales colour and alpha (one / x blends), 0: alpha only (src-alpha / x blends)
//   u_rmSoft[1]  unused
//   u_rmSoft[2]  xy 1 / the scene target's size (pixels), z the city lights' strength (0: unlit), w the shadow's
//                darkening (0: none)
//   u_rmSoft[3]  x the colour gain (additive draws under HDR; 1 otherwise)
#include <bgfx_shader.sh>

uniform vec4 u_vc[96];
uniform vec4 u_rmSoft[4];
uniform vec4 u_rmShadow[12];
SAMPLER2DSHADOW(s_rmShadow, 4);
#include "rm_city.sh"
SAMPLER2D(s_rmSoftDepth, 6);

#if BGFX_SHADER_LANGUAGE_GLSL
#define PX_PRIVATE
#else
#define PX_PRIVATE static
#endif
PX_PRIVATE float g_pxSoft;
PX_PRIVATE vec3 g_pxPos;
PX_PRIVATE vec2 g_pxFc;

// a wide, soft lookup (five taps 6 texels apart): a sprite is a flat card standing in a volume, so the shadow's own edge
// across it would cut the cloud into hard dark wedges (play3 f54000); smoke takes the shadow as a soft gradient
float pxSoftShadowTap(vec3 q)
{
    float t = u_rmShadow[10].w * 6.0;
    return 0.2 * (shadow2D(s_rmShadow, q) + shadow2D(s_rmShadow, vec3(q.x - t, q.y - t, q.z)) +
                  shadow2D(s_rmShadow, vec3(q.x + t, q.y - t, q.z)) + shadow2D(s_rmShadow, vec3(q.x - t, q.y + t, q.z)) +
                  shadow2D(s_rmShadow, vec3(q.x + t, q.y + t, q.z)));
}

// the sun's visibility at a camera-space point (1: lit); the point is pushed a little towards the sun (no normal)
float pxSoftShadow(vec3 pos)
{
    if (u_rmShadow[8].x < 0.5 || pos.z > u_rmShadow[11].x)
        return 1.0;
    bool second = u_rmShadow[8].x > 1.5 && pos.z > u_rmShadow[8].y;
    vec4 b = second ? u_rmShadow[7] : u_rmShadow[3];
    vec4 p = vec4(pos + u_rmShadow[9].xyz * (b.x + 0.3), 1.0);
    vec3 q = second ? vec3(dot(p, u_rmShadow[4]), dot(p, u_rmShadow[5]), dot(p, u_rmShadow[6]))
                    : vec3(dot(p, u_rmShadow[0]), dot(p, u_rmShadow[1]), dot(p, u_rmShadow[2]));
    if (q.z >= 1.0 || q.z <= 0.0)
        return 1.0;
    q.z -= b.z;
    float vis = pxSoftShadowTap(q);
    if (u_rmShadow[10].y > 0.5)
        vis = min(vis, pxSoftShadowTap(vec3(q.x, q.y + u_rmShadow[10].x, q.z)));
    float fade = clamp((pos.z - u_rmShadow[11].x * 0.85) / (u_rmShadow[11].x * 0.15), 0.0, 1.0);
    return mix(vis, 1.0, fade);
}

// the vertex colour as the combiner reads it; the fade, the camera-space point and the pixel for the final clamp
vec4 pxSoftColour(vec4 base, vec3 pos, vec2 fc)
{
    float f = 1.0;
    if (u_rmSoft[0].x > 0.0) {
        float z = texture2DLod(s_rmSoftDepth, fc * u_rmSoft[2].xy, 0.0).x;   // (the scene's linear depth there)
        f = smoothstep(0.0, 1.0, (z - pos.z) * u_rmSoft[0].x);
    }
    f *= smoothstep(0.0, 1.0, (pos.z - u_rmSoft[0].y) * u_rmSoft[0].z);
    g_pxSoft = f;
    g_pxPos = pos;
    g_pxFc = fc;
    return base;
}

float pxSat(float x) { return clamp(x, 0.0, 1.0); }
vec2 pxSat(vec2 x) { return clamp(x, 0.0, 1.0); }
vec3 pxSat(vec3 x) { return clamp(x, 0.0, 1.0); }
// the combiner's output (its only vec4 clamp): the light (smoke: the combiner modulates the texture by the vertex
// colour, so light scaling the output is light scaling the colour; only where the pixel shows, as most of a smoke
// sprite's texels are clear), the gain, then the fade
vec4 pxSat(vec4 x)
{
    x = clamp(x, 0.0, 1.0);
    float shows = u_rmSoft[0].w > 0.5 ? max(x.r, max(x.g, x.b)) : x.a;
    if (shows * g_pxSoft > 0.004) {
        float k = 1.0;
        if (u_rmSoft[2].w > 0.0)
            k = 1.0 - u_rmSoft[2].w * (1.0 - pxSoftShadow(g_pxPos));
        vec3 light = vec3(k, k, k);
        if (u_rmSoft[2].z > 0.0 && u_rmCity[0].x > 0.5)
            // (no normal: cityOne's wrap gives 0.15 for n = 0; the volume takes light from every side)
            light += cityLight(g_pxPos, vec3(0.0, 0.0, 0.0), g_pxFc) * (u_rmSoft[2].z * (0.5 / 0.15));
        x.rgb = clamp(x.rgb * light * u_rmSoft[3].x, 0.0, 1.0);
    }
    return u_rmSoft[0].w > 0.5 ? x * g_pxSoft : vec4(x.rgb, x.a * g_pxSoft);
}

#define v_color0 pxSoftColour(v_pxbase, v_pxpos, gl_FragCoord.xy)
#define v_color1 v_pxspec
#undef saturate
#define saturate(_x) pxSat(_x)
#include "fs_vp_stage.sh"
