$input v_texcoord0

// FSR 1 EASU (edge-adaptive spatial upsampling) for the app's Upscaler (wperf1, docs/performance.md): the scene at the
// render size (s_rmTex0) to the present size, one pass. A port of AMD FidelityFX Super Resolution 1.0's EASU
// (ffx_fsr1.h, FsrEasuF) to bgfx's shader language: 12 point taps around the output pixel's position in the input, the
// local edge direction and length from luma gradients of the four bilinear corners, an anisotropic Lanczos-2-like
// kernel stretched along the edge, and the result clamped to the nearest 2x2's range (no ringing).
//
// Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the input (point sampled, clamped)
uniform vec4 u_rmFsr0;          // input width, height, 1 / width, 1 / height

vec3 tapC(vec2 fp, vec2 o)
{
    return texture2DLod(s_rmTex0, (fp + o + vec2(0.5, 0.5)) * u_rmFsr0.zw, 0.0).rgb;
}
float lumaOf(vec3 c) { return c.b * 0.5 + (c.r * 0.5 + c.g); }

// one bilinear corner's contribution to the direction and length ('+' pattern a / b c d / e around c)
void easuSet(inout vec2 dir, inout float len, float w, float lA, float lB, float lC, float lD, float lE)
{
    float dc = lD - lC;
    float cb = lC - lB;
    float lenX = max(abs(dc), abs(cb));
    lenX = 1.0 / max(lenX, 1.0 / 65536.0);
    float dirX = lD - lB;
    dir.x += dirX * w;
    lenX = clamp(abs(dirX) * lenX, 0.0, 1.0);
    lenX *= lenX;
    len += lenX * w;
    float ec = lE - lC;
    float ca = lC - lA;
    float lenY = max(abs(ec), abs(ca));
    lenY = 1.0 / max(lenY, 1.0 / 65536.0);
    float dirY = lE - lA;
    dir.y += dirY * w;
    lenY = clamp(abs(dirY) * lenY, 0.0, 1.0);
    lenY *= lenY;
    len += lenY * w;
}

void easuTap(inout vec3 aC, inout float aW, vec2 off, vec2 dir, vec2 len, float lob, float clp, vec3 c)
{
    vec2 v;
    v.x = off.x * dir.x + off.y * dir.y;
    v.y = off.x * (-dir.y) + off.y * dir.x;
    v *= len;
    float d2 = min(v.x * v.x + v.y * v.y, clp);
    float wB = (2.0 / 5.0) * d2 - 1.0;
    float wA = lob * d2 - 1.0;
    wB *= wB;
    wA *= wA;
    wB = (25.0 / 16.0) * wB - (25.0 / 16.0 - 1.0);
    float w = wB * wA;
    aC += c * w;
    aW += w;
}

void main()
{
    // the output pixel's centre in input pixels (0, 0 the first texel's centre)
    vec2 pp = v_texcoord0.xy * u_rmFsr0.xy - vec2(0.5, 0.5);
    vec2 fp = floor(pp);
    pp -= fp;
    //    b c
    //  e f g h
    //  i j k l
    //    n o
    vec3 b = tapC(fp, vec2(0.0, -1.0)), c = tapC(fp, vec2(1.0, -1.0));
    vec3 e = tapC(fp, vec2(-1.0, 0.0)), f = tapC(fp, vec2(0.0, 0.0));
    vec3 g = tapC(fp, vec2(1.0, 0.0)), h = tapC(fp, vec2(2.0, 0.0));
    vec3 i = tapC(fp, vec2(-1.0, 1.0)), j = tapC(fp, vec2(0.0, 1.0));
    vec3 k = tapC(fp, vec2(1.0, 1.0)), l = tapC(fp, vec2(2.0, 1.0));
    vec3 n = tapC(fp, vec2(0.0, 2.0)), o = tapC(fp, vec2(1.0, 2.0));
    float bL = lumaOf(b), cL = lumaOf(c), eL = lumaOf(e), fL = lumaOf(f), gL = lumaOf(g), hL = lumaOf(h);
    float iL = lumaOf(i), jL = lumaOf(j), kL = lumaOf(k), lL = lumaOf(l), nL = lumaOf(n), oL = lumaOf(o);
    vec2 dir = vec2(0.0, 0.0);
    float len = 0.0;
    easuSet(dir, len, (1.0 - pp.x) * (1.0 - pp.y), bL, eL, fL, gL, jL);
    easuSet(dir, len, pp.x * (1.0 - pp.y), cL, fL, gL, hL, kL);
    easuSet(dir, len, (1.0 - pp.x) * pp.y, fL, iL, jL, kL, nL);
    easuSet(dir, len, pp.x * pp.y, gL, jL, kL, lL, oL);
    vec2 dir2 = dir * dir;
    float dirR = dir2.x + dir2.y;
    bool zro = dirR < 1.0 / 32768.0;
    dirR = zro ? 1.0 : inversesqrt(dirR);
    dir.x = zro ? 1.0 : dir.x;
    dir *= dirR;
    len = len * 0.5;
    len *= len;
    float stretch = (dir.x * dir.x + dir.y * dir.y) / max(abs(dir.x), abs(dir.y));
    vec2 len2 = vec2(1.0 + (stretch - 1.0) * len, 1.0 - 0.5 * len);
    float lob = 0.5 + ((1.0 / 4.0 - 0.04) - 0.5) * len;
    float clp = 1.0 / lob;
    vec3 aC = vec3(0.0, 0.0, 0.0);
    float aW = 0.0;
    easuTap(aC, aW, vec2(0.0, -1.0) - pp, dir, len2, lob, clp, b);
    easuTap(aC, aW, vec2(1.0, -1.0) - pp, dir, len2, lob, clp, c);
    easuTap(aC, aW, vec2(-1.0, 1.0) - pp, dir, len2, lob, clp, i);
    easuTap(aC, aW, vec2(0.0, 1.0) - pp, dir, len2, lob, clp, j);
    easuTap(aC, aW, vec2(0.0, 0.0) - pp, dir, len2, lob, clp, f);
    easuTap(aC, aW, vec2(-1.0, 0.0) - pp, dir, len2, lob, clp, e);
    easuTap(aC, aW, vec2(1.0, 1.0) - pp, dir, len2, lob, clp, k);
    easuTap(aC, aW, vec2(2.0, 1.0) - pp, dir, len2, lob, clp, l);
    easuTap(aC, aW, vec2(2.0, 0.0) - pp, dir, len2, lob, clp, h);
    easuTap(aC, aW, vec2(1.0, 0.0) - pp, dir, len2, lob, clp, g);
    easuTap(aC, aW, vec2(1.0, 2.0) - pp, dir, len2, lob, clp, o);
    easuTap(aC, aW, vec2(0.0, 2.0) - pp, dir, len2, lob, clp, n);
    vec3 mn4 = min(min(f, g), min(j, k));
    vec3 mx4 = max(max(f, g), max(j, k));
    vec3 pix = min(mx4, max(mn4, aC / max(aW, 1e-6)));
    gl_FragColor = vec4(pix, 1.0);
}
