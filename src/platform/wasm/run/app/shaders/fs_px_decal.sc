$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Lasting decals (wdecal1, run/app/decals.cpp, docs/destruction.md "Lasting decals"): the game's world-hit decals (and
// the runner's copies of them) with the faithful texture-stage combiner (shaders/vp/fs_vp_stage.sh, the generic one),
// fog and alpha test, faded out where they float. A decal lies on the collision mesh (0.03 units out along its
// normal), which is not the render mesh: over a kerb, a step or a gap the surface the camera sees behind it is further
// away. The scene's depth behind the decal (a linear copy taken at the frame's first decal, before any decal draws)
// gives that distance along the view ray; times the view's cosine to the decal it is the distance along the normal,
// and the decal fades from u_rmDecal[0].x to .y of it. vs_rm_decal pulls the decal towards the camera so it wins the
// depth test where the render mesh is a little in front (no z-fighting); v_pxpos is the unpulled point.
//
// Uniforms:
//   u_rmDecal[0]  x the fade's start, y its end (units along the normal), z the blend's rule: 0 alpha fades
//                 (src-alpha / x), 1 colour and alpha scale (one / x), 2 towards white (a multiply)
//   u_rmDecal[1]  xy 1 / the scene target's size (pixels), z the floor of the view's cosine
//   u_rmDecal[2]  the vertex shader's pull (vs_px_ff.sh PX_DCPULL)
#include <bgfx_shader.sh>

uniform vec4 u_vc[96];
uniform vec4 u_rmDecal[3];
SAMPLER2D(s_rmDecalDepth, 6);

#if BGFX_SHADER_LANGUAGE_GLSL
#define PX_PRIVATE
#else
#define PX_PRIVATE static
#endif
PX_PRIVATE float g_dcFit;

// the vertex colour as the combiner reads it; the fit for the final clamp
vec4 dcColour(vec4 base, vec3 pos, vec2 fc)
{
    float z = texture2DLod(s_rmDecalDepth, fc * u_rmDecal[1].xy, 0.0).x;   // (the scene's linear depth there)
    float l = length(pos);
    // (the decal's face from the point's derivatives: the game's decal vertices carry no normal)
    vec3 fn = cross(dFdx(pos), dFdy(pos));
    float fl = length(fn);
    float c = fl > 1e-12 ? max(abs(dot(fn / fl, pos / max(l, 1e-4))), u_rmDecal[1].z) : 1.0;
    float h = (z - pos.z) * (l / max(pos.z, 1e-3)) * c;          // (> 0: the surface is behind the decal)
    g_dcFit = 1.0 - smoothstep(u_rmDecal[0].x, u_rmDecal[0].y, h);
    return base;
}

float pxSat(float x) { return clamp(x, 0.0, 1.0); }
vec2 pxSat(vec2 x) { return clamp(x, 0.0, 1.0); }
vec3 pxSat(vec3 x) { return clamp(x, 0.0, 1.0); }
// the combiner's output (its only vec4 clamp), faded by the blend's rule
vec4 pxSat(vec4 x)
{
    x = clamp(x, 0.0, 1.0);
    if (u_rmDecal[0].z > 1.5)
        return mix(vec4(1.0, 1.0, 1.0, 1.0), x, g_dcFit);
    if (u_rmDecal[0].z > 0.5)
        return x * g_dcFit;
    return vec4(x.rgb, x.a * g_dcFit);
}

#define v_color0 dcColour(v_pxbase, v_pxpos, gl_FragCoord.xy)
#define v_color1 v_pxspec
#undef saturate
#define saturate(_x) pxSat(_x)
#include "fs_vp_stage.sh"
