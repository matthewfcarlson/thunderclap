$input v_pxbase, v_texcoord0

// Temporal upscaling's HUD mask (wperf2, taa.cpp): how much of the pixel the draw covers. u_rmMask: stage 0's
// coordinate scale and offset (u_pddiFrag[4].xy, [14].xy); u_rmMask1.x: 0 opaque (1), 1 alpha blended (alpha),
// 2 additive or other blends (the brightest channel).
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_rmMask;
uniform vec4 u_rmMask1;

void main()
{
    vec2 uv = v_texcoord0.xy * u_rmMask.xy + u_rmMask.zw;
    vec4 c = texture2D(s_pddiTex0, uv) * v_pxbase;
    float a = u_rmMask1.x < 0.5 ? 1.0 : u_rmMask1.x < 1.5 ? c.a : max(c.r, max(c.g, c.b));
    a = clamp(a, 0.0, 1.0);
    if (a < 0.02)
        discard;
    gl_FragColor = vec4(a, a, a, a);
}
