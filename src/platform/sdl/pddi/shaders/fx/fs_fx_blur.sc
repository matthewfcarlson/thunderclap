$input v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// The framebuffer effects' sums (FUN_00320330's ps.1.1 programs, our translation): the gaussian's 1 to 4 taps
// (tex t0..t3; mul r0, t0, c0; mad r0, t1, c1, r0; ...) and the bloom's composite (tex t0; tex t1;
// mul_x2 r0, t0, c0; mad r0, t1, c1, r0). Also the quarter copy's fixed-function stage (texture x the texture factor),
// which is the one-tap sum with c0 = the factor. Results clamped to [-1, 1] each step, the output to [0, 1].
// u_fxC[i] = c<i>; u_fxProg = (taps 1..4, 1 for the composite's doubled first product).
#include <bgfx_shader.sh>

SAMPLER2D(s_fx0, 0);
SAMPLER2D(s_fx1, 1);
SAMPLER2D(s_fx2, 2);
SAMPLER2D(s_fx3, 3);
uniform vec4 u_fxC[8];
uniform vec4 u_fxProg;

void main()
{
    vec4 r0 = clamp(texture2D(s_fx0, v_texcoord0) * u_fxC[0] * (u_fxProg.y > 0.5 ? 2.0 : 1.0), -1.0, 1.0);
    if (u_fxProg.x > 1.5)
        r0 = clamp(texture2D(s_fx1, v_texcoord1) * u_fxC[1] + r0, -1.0, 1.0);
    if (u_fxProg.x > 2.5)
        r0 = clamp(texture2D(s_fx2, v_texcoord2) * u_fxC[2] + r0, -1.0, 1.0);
    if (u_fxProg.x > 3.5)
        r0 = clamp(texture2D(s_fx3, v_texcoord3) * u_fxC[3] + r0, -1.0, 1.0);
    gl_FragColor = clamp(r0, 0.0, 1.0);
}
