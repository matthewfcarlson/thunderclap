$input v_texcoord0

// FSR 1 RCAS (robust contrast-adaptive sharpening) for the app's Upscaler (wperf1, docs/performance.md): after EASU,
// at the present size (s_rmTex0). A port of AMD FidelityFX Super Resolution 1.0's RCAS (ffx_fsr1.h, FsrRcasF; no
// denoise): a 5-tap cross whose negative lobe is the largest that keeps the result inside the neighbours' range.
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

SAMPLER2D(s_rmTex0, 0);         // EASU's output (point sampled)
uniform vec4 u_rmFsr0;          // width, height, 1 / width, 1 / height of the input; w: the sharpness (2^-stops)

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec2 d = u_rmFsr0.zw;
    //    b
    //  d e f
    //    h
    vec3 b = texture2DLod(s_rmTex0, uv + vec2(0.0, -d.y), 0.0).rgb;
    vec3 dd = texture2DLod(s_rmTex0, uv + vec2(-d.x, 0.0), 0.0).rgb;
    vec3 e = texture2DLod(s_rmTex0, uv, 0.0).rgb;
    vec3 f = texture2DLod(s_rmTex0, uv + vec2(d.x, 0.0), 0.0).rgb;
    vec3 h = texture2DLod(s_rmTex0, uv + vec2(0.0, d.y), 0.0).rgb;
    vec3 mn4 = min(min(b, dd), min(f, h));
    vec3 mx4 = max(max(b, dd), max(f, h));
    vec2 peakC = vec2(1.0, -4.0);
    vec3 hitMin = min(mn4, e) / (4.0 * max(mx4, vec3(1e-5, 1e-5, 1e-5)));
    vec3 hitMax = (peakC.x - max(mx4, e)) / (4.0 * min(mn4, e) + peakC.y);
    vec3 lobeRGB = max(-hitMin, hitMax);
    float lobe = max(-(0.25 - 1.0 / 16.0), min(max(lobeRGB.r, max(lobeRGB.g, lobeRGB.b)), 0.0)) * u_rmFsr0.w;
    float rcpL = 1.0 / (4.0 * lobe + 1.0);
    vec3 pix = (lobe * (b + dd + h + f) + e) * rcpL;
    gl_FragColor = vec4(clamp(pix, 0.0, 1.0), 1.0);
}
