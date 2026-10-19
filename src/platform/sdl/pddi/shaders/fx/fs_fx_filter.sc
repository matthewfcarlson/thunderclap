$input v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// The framebuffer effects' colour pass (d3dExtFramebufferEffects, FUN_00324660), our translation of the 17 xps.1.1
// programs FUN_00320540 assembles from text (the game's own code; no vendor material): 8 levels x 2 sides of
//
//   tex t0
//   dp3 r0, t0, c0                     luminance by the weights c0, in every channel
//   add r0.xyz, t0, -r0                the colour less its luminance
//   + mad r1.w, r0.w, c5, c3_bx2       the brightness curve: luminance x c5 + (2 c3 - 1)
//   mul_x2 r0.xyz, r0, c7              the saturation: 2 x (colour - luminance) x c7
//   [+ mov_x4 / mov_x2 r1.w, r1.w]     levels 32-64 / 16
//   mad r0.xyz, c6_bx2, r0.w, r0       the tint: (2 c6 - 1) x luminance
//   [+ mov_x2 r1.w, r1.w]              level 64
//   add r0.xyz, r0.xyz, r1.w           then more adds of r1.w, doubling it between some (the level's multiplier)
//
// and level 7's threshold program (the text at 0x432da0):
//
//   def c1, 0.5..; def c2, 0..; def c3, 1..
//   tex t0
//   dp3_d2 r0, t0, c0
//   add r0, r0, c5_bx2
//   add r0, r0, c1
//   cnd r0, r0.a, c3, c2               1 where (t0 . c0) / 2 + 2 c5 - 1 + 0.5 > 0.5, else 0
//
// Register combiner arithmetic: every instruction's result is clamped to [-1, 1]; the output to [0, 1]; co-issued
// (+) instructions read the registers as they were before the pair. The constants arrive quantised to 8 bits in
// [0, 1] (the CPU side does that, as the Xbox's SetPixelShaderConstant does).
//
// u_fxC[i] = c<i>; u_fxProg = (mode: 0 colour pass, 1 threshold; the multiplier co-issued with mul_x2 (1, 2, 4);
// the one with the first mad (1, 2); the number of adds 1..4); u_fxK = after add i, r1.w times u_fxK[i] (1 or 2).
#include <bgfx_shader.sh>

SAMPLER2D(s_fx0, 0);
uniform vec4 u_fxC[8];
uniform vec4 u_fxProg;
uniform vec4 u_fxK;

float s1(float x) { return clamp(x, -1.0, 1.0); }
vec3 s3(vec3 x) { return clamp(x, -1.0, 1.0); }

void main()
{
    vec4 t0 = texture2D(s_fx0, v_texcoord0);
    if (u_fxProg.x > 0.5) {
        float r = s1(dot(t0.xyz, u_fxC[0].xyz) * 0.5);
        r = s1(r + (2.0 * u_fxC[5].w - 1.0));
        r = s1(r + 0.5);
        gl_FragColor = r > 0.5 ? vec4(1.0, 1.0, 1.0, 1.0) : vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }
    float lum = s1(dot(t0.xyz, u_fxC[0].xyz));
    vec3 r0 = s3(t0.xyz - vec3(lum, lum, lum));
    float r1 = s1(lum * u_fxC[5].w + (2.0 * u_fxC[3].w - 1.0));
    r0 = s3(2.0 * r0 * u_fxC[7].xyz);
    r1 = s1(r1 * u_fxProg.y);
    r0 = s3((2.0 * u_fxC[6].xyz - 1.0) * lum + r0);
    r1 = s1(r1 * u_fxProg.z);
    // the adds (1 to 4), r1.w doubled after some
    r0 = s3(r0 + r1);
    r1 = s1(r1 * u_fxK.x);
    if (u_fxProg.w > 1.5) {
        r0 = s3(r0 + r1);
        r1 = s1(r1 * u_fxK.y);
    }
    if (u_fxProg.w > 2.5) {
        r0 = s3(r0 + r1);
        r1 = s1(r1 * u_fxK.z);
    }
    if (u_fxProg.w > 3.5)
        r0 = s3(r0 + r1);
    gl_FragColor = clamp(vec4(r0, lum), 0.0, 1.0);
}
