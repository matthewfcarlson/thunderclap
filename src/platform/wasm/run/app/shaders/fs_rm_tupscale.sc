$input v_texcoord0

// Temporal upscaling, ours (wperf2, upscale.cpp, docs/performance.md 4.2; Video Options > Upscaler: Temporal): the
// frame at the render size, its samples jittered by TAA (taa.cpp), reconstructed at the present size against a
// history of the same size. An FSR 2-class resolve written from the published algorithm (AMD's FidelityFX Super
// Resolution 2 description: jittered samples upsampled by a Lanczos-2 kernel, the history reprojected by dilated motion
// vectors and rectified against the neighbourhood, each output pixel accumulating samples by how close they fell),
// our own code, one pass:
//   - the current frame at this output pixel: the 3x3 input samples around it at their jittered positions, weighted by
//     a narrow kernel in output pixels; its weight is that kernel's sum (how near the samples fell), so over the
//     jitter phases every output pixel gathers the samples that fell on it (the detail of the present size); where
//     there is little or no history the frame's own edge-adaptive reconstruction (FSR 1's EASU at the jittered
//     grid's coordinates, rm_easu.sh) stands in;
//   - the history (Catmull-Rom) at the position the motion of the nearest-depth sample of the 3x3 gives (the dilation
//     keeps edges with the foreground), clipped to the samples' YCoCg box (mean +- gamma sigma); a clip lowers its
//     accumulated weight (alpha), a reset or a position off screen drops it;
//   - the HUD's mask (drawn after the first effect, not jittered): there the frame is taken as it is (Catmull-Rom of
//     the unjittered samples) and nothing accumulates.
// Output: rgb, a the accumulated weight (the next frame's history). RCAS sharpens it after (upscale.cpp).
//   u_rmTu0  input width, height, 1 / width, 1 / height
//   u_rmTu1  output width, height, 1 / width, 1 / height
//   u_rmTu2  xy this frame's jitter in input pixels (x right, y down), z 1: reset, w bit 0: textures have v = 0 at
//           the bottom, bit 1: debug view
//   u_rmTu3  x the most accumulated weight, y the clip's gamma, z the output-pixel kernel's falloff (exp(-z d^2)),
//           w the smooth reconstruction's prior weight
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the frame (render size, point)
SAMPLER2D(s_rmTex1, 1);         // its depth at the first effect (point)
SAMPLER2D(s_rmTex2, 2);         // motion: uv, last - current (point)
SAMPLER2D(s_rmTex3, 3);         // the HUD mask (linear)
SAMPLER2D(s_rmTex4, 4);         // the history (present size, linear): rgb, a the accumulated weight
uniform vec4 u_rmTu0;
uniform vec4 u_rmTu1;
uniform vec4 u_rmTu2;
uniform vec4 u_rmTu3;

vec2 texUv(vec2 s) { return fract(u_rmTu2.w * 0.5) > 0.25 ? vec2(s.x, 1.0 - s.y) : s; }
vec3 toYCoCg(vec3 c) { return vec3(dot(c, vec3(0.25, 0.5, 0.25)), dot(c, vec3(0.5, 0.0, -0.5)), dot(c, vec3(-0.25, 0.5, -0.25))); }
vec3 fromYCoCg(vec3 c) { return vec3(c.x + c.y - c.z, c.x + c.z, c.x - c.y - c.z); }
vec3 easuC(vec2 fp, vec2 o) { return texture2DLod(s_rmTex0, texUv((fp + o + vec2(0.5, 0.5)) * u_rmTu0.zw), 0.0).rgb; }
#include "rm_easu.sh"

// a 5-tap Catmull-Rom of the history at screen position s (bilinear taps)
vec4 history(vec2 s)
{
    vec2 size = u_rmTu1.xy;
    vec2 pos = s * size;
    vec2 c = floor(pos - 0.5) + 0.5;
    vec2 f = pos - c;
    vec2 w0 = f * (-0.5 + f * (1.0 - 0.5 * f));
    vec2 w1 = 1.0 + f * f * (-2.5 + 1.5 * f);
    vec2 w2 = f * (0.5 + f * (2.0 - 1.5 * f));
    vec2 w3 = f * f * (-0.5 + 0.5 * f);
    vec2 w12 = w1 + w2;
    vec2 t12 = (c + w2 / w12) * u_rmTu1.zw;
    vec2 t0 = (c - 1.0) * u_rmTu1.zw, t3 = (c + 2.0) * u_rmTu1.zw;
    vec4 r = texture2DLod(s_rmTex4, texUv(vec2(t12.x, t0.y)), 0.0) * (w12.x * w0.y)
           + texture2DLod(s_rmTex4, texUv(vec2(t0.x, t12.y)), 0.0) * (w0.x * w12.y)
           + texture2DLod(s_rmTex4, texUv(t12), 0.0) * (w12.x * w12.y)
           + texture2DLod(s_rmTex4, texUv(vec2(t3.x, t12.y)), 0.0) * (w3.x * w12.y)
           + texture2DLod(s_rmTex4, texUv(vec2(t12.x, t3.y)), 0.0) * (w12.x * w3.y);
    float wsum = w12.x * w0.y + w0.x * w12.y + w12.x * w12.y + w3.x * w12.y + w12.x * w3.y;
    return max(r / wsum, vec4_splat(0.0));
}
// the same of the frame (the HUD: its samples are not jittered), deringed to the 2x2 around
vec3 frameCubic(vec2 s)
{
    vec2 size = u_rmTu0.xy;
    vec2 pos = s * size;
    vec2 c = floor(pos - 0.5) + 0.5;
    vec2 f = pos - c;
    vec2 w0 = f * (-0.5 + f * (1.0 - 0.5 * f));
    vec2 w1 = 1.0 + f * f * (-2.5 + 1.5 * f);
    vec2 w2 = f * (0.5 + f * (2.0 - 1.5 * f));
    vec2 w3 = f * f * (-0.5 + 0.5 * f);
    vec2 w12 = w1 + w2;
    vec2 t12 = (c + w2 / w12) * u_rmTu0.zw;
    vec2 t0 = (c - 1.0) * u_rmTu0.zw, t3 = (c + 2.0) * u_rmTu0.zw;
    vec3 r = texture2DLod(s_rmTex0, texUv(vec2(t12.x, t0.y)), 0.0).rgb * (w12.x * w0.y)
           + texture2DLod(s_rmTex0, texUv(vec2(t0.x, t12.y)), 0.0).rgb * (w0.x * w12.y)
           + texture2DLod(s_rmTex0, texUv(t12), 0.0).rgb * (w12.x * w12.y)
           + texture2DLod(s_rmTex0, texUv(vec2(t3.x, t12.y)), 0.0).rgb * (w3.x * w12.y)
           + texture2DLod(s_rmTex0, texUv(vec2(t12.x, t3.y)), 0.0).rgb * (w12.x * w3.y);
    float wsum = w12.x * w0.y + w0.x * w12.y + w12.x * w12.y + w3.x * w12.y + w12.x * w3.y;
    return max(r / wsum, vec3_splat(0.0));
}

void main()
{
    vec2 s = texUv(v_texcoord0.xy);              // (screen: top-left origin)
    vec2 J = u_rmTu2.xy;
    vec2 ip = s * u_rmTu0.xy;                    // this pixel's centre in (unjittered) input pixels
    vec2 n = floor(ip + J);                      // the input pixel whose sample (at n + 0.5 - J) is nearest
    vec2 ratio = u_rmTu1.xy * u_rmTu0.zw;        // output pixels per input pixel
    vec3 sharp = vec3_splat(0.0), m1 = vec3_splat(0.0), m2 = vec3_splat(0.0);
    float wSharp = 0.0, dmin = 2.0;
    vec2 dpix = n;
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            vec2 pix = n + vec2(float(i), float(j));
            vec2 tu = texUv((pix + 0.5) * u_rmTu0.zw);
            vec3 c = texture2DLod(s_rmTex0, tu, 0.0).rgb;
            vec2 d = pix + 0.5 - J - ip;             // input pixels
            vec2 dOut = d * ratio;                   // output pixels
            // the sample's share of this output pixel (a narrow kernel in output pixels: over the jitter phases the
            // pixel gathers the samples that fell on it)
            float ws = exp(-u_rmTu3.z * dot(dOut, dOut));
            sharp += c * ws;
            wSharp += ws;
            vec3 y = toYCoCg(c);
            m1 += y;
            m2 += y * y;
            float dd = texture2DLod(s_rmTex1, tu, 0.0).x;
            if (dd < dmin) {
                dmin = dd;
                dpix = pix;
            }
        }
    }
    // the frame's own reconstruction at this pixel: FSR 1's EASU at the jittered grid's coordinates (the fallback where
    // there is little or no history, and the prior of the current samples)
    vec3 soft = easuAt(ip + J - 0.5);
    float wcur = min(wSharp, 1.0);
    float A = 0.0;
    vec3 outc = soft;
    vec2 mv = texture2DLod(s_rmTex2, texUv((dpix + 0.5) * u_rmTu0.zw), 0.0).xy;
    vec2 ps = s + mv;
    if (u_rmTu2.z < 0.5 && ps.x >= 0.0 && ps.x <= 1.0 && ps.y >= 0.0 && ps.y <= 1.0) {
        vec4 h = history(ps);
        A = h.a;
        m1 *= 1.0 / 9.0;
        m2 *= 1.0 / 9.0;
        vec3 sigma = sqrt(max(m2 - m1 * m1, vec3_splat(0.0)));
        vec3 ctr = m1, ext = u_rmTu3.y * sigma + 1e-3;
        vec3 v = toYCoCg(h.rgb) - ctr;
        vec3 a = abs(v / ext);
        float m = max(a.x, max(a.y, a.z));
        vec3 hc = h.rgb;
        if (m > 1.0) {
            hc = fromYCoCg(ctr + v / m);
            A *= 1.0 / (m * m);
        }
        // fast motion keeps less history (each reprojection resamples it: a whip pan moves 20 output pixels a frame)
        float mpx = length(mv * u_rmTu1.xy);
        A = min(A, u_rmTu3.x * mix(1.0, 0.15, clamp(mpx / 24.0, 0.0, 1.0)));
        // little history: start from the smooth reconstruction
        float t = clamp(A, 0.0, 1.0);
        hc = mix(soft, hc, t);
        // the current samples with the smooth reconstruction as a prior: a sample right on the pixel dominates, far
        // ones defer to it, the more so the less history there is (a moving edge, whose history the clip drops,
        // would show the input's stair steps)
        float k = u_rmTu3.w + 2.0 * (1.0 - clamp(A * 0.25, 0.0, 1.0)) + mpx * 0.125;
        vec3 cur = (sharp + soft * k) / (wSharp + k);
        A = max(A, 0.5);
        float An = min(A + wcur, u_rmTu3.x);
        outc = mix(hc, cur, wcur / An);
        A = An;
    } else {
        A = 0.5 + wcur;
    }
    float mk = texture2DLod(s_rmTex3, v_texcoord0.xy, 0.0).x;
    if (mk > 0.0) {
        outc = mix(outc, frameCubic(s), mk);
        A *= 1.0 - mk;
    }
    if (u_rmTu2.w > 1.5) {
        // (HULK_TU_DEBUG: r, g the motion in output pixels x 0.02 + 0.5, b the accumulated weight / the most)
        vec2 mo = mv * u_rmTu1.xy * 0.02 + 0.5;
        gl_FragColor = vec4(mo.x, mo.y, A / u_rmTu3.x, A);
        return;
    }
    gl_FragColor = vec4(outc, A);
}
