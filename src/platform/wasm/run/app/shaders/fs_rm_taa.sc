$input v_texcoord0

// Temporal anti-aliasing (wperf1, docs/performance.md; Video Options > Anti-Aliasing: TAA): the jittered frame
// (s_rmTex0, a copy of the scene) blended into the history (s_rmTex2) reprojected through the scene's depth
// (s_rmTex1) and the camera's motion from the last presented frame, the history clipped to the current 3x3
// neighbourhood's colour box (YCoCg, mean +- gamma sigma) against ghosting. HDR-safe: the blend is weighted by
// 1 / (1 + luma). Moving objects (the characters, cars) take the camera's motion only: the clip keeps them from
// trailing; objects drawn into the velocity target (s_rmTex3) reproject by their own motion.
//   u_rmTaa0  the projection: x c4.x, y c5.y, z c4.z, w c5.z (unjittered)
//   u_rmTaa1  x c6.z, y c6.w, z c7.z, w c7.w (D3D depth: d = (c6.z z + c6.w) / (c7.z z + c7.w))
//   u_rmTaa2  x c4.w, y c5.w, z the blend of the current frame, w 1: no history (reset)
//   u_rmTaa3  x bit 0: textures have v = 0 at the bottom, bit 1: a velocity target; y the clip's gamma, zw the texel
//   u_rmTaaM[4]  current camera space -> the last frame's clip space (rows)
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);
SAMPLER2D(s_rmTex1, 1);
SAMPLER2D(s_rmTex2, 2);
SAMPLER2D(s_rmTex3, 3);         // the objects' motion: rg uv (current - last), b view depth, a 1: written
uniform vec4 u_rmTaa0;
uniform vec4 u_rmTaa1;
uniform vec4 u_rmTaa2;
uniform vec4 u_rmTaa3;
uniform vec4 u_rmTaaM[4];

bool flipped() { return fract(u_rmTaa3.x * 0.5) > 0.25; }
vec2 texUv(vec2 s) { return flipped() ? vec2(s.x, 1.0 - s.y) : s; }
float viewZ(float d) { return (u_rmTaa1.y - d * u_rmTaa1.w) / min(d * u_rmTaa1.z - u_rmTaa1.x, -1e-7); }
vec3 viewPos(vec2 s, float d)
{
    float z = viewZ(d);
    float w = u_rmTaa1.z * z + u_rmTaa1.w;
    vec2 ndc = vec2(s.x * 2.0 - 1.0, 1.0 - s.y * 2.0);
    return vec3((ndc.x * w - u_rmTaa0.z * z - u_rmTaa2.x) / u_rmTaa0.x,
                (ndc.y * w - u_rmTaa0.w * z - u_rmTaa2.y) / u_rmTaa0.y, z);
}
vec3 toYCoCg(vec3 c) { return vec3(dot(c, vec3(0.25, 0.5, 0.25)), dot(c, vec3(0.5, 0.0, -0.5)), dot(c, vec3(-0.25, 0.5, -0.25))); }
vec3 fromYCoCg(vec3 c) { return vec3(c.x + c.y - c.z, c.x + c.z, c.x - c.y - c.z); }
// the history by a 5-tap Catmull-Rom (bilinear taps; sharper than one bilinear tap, which blurs over the frames)
vec3 history(vec2 uv)
{
    vec2 size = 1.0 / u_rmTaa3.zw;
    vec2 pos = uv * size;
    vec2 c = floor(pos - 0.5) + 0.5;
    vec2 f = pos - c;
    vec2 w0 = f * (-0.5 + f * (1.0 - 0.5 * f));
    vec2 w1 = 1.0 + f * f * (-2.5 + 1.5 * f);
    vec2 w2 = f * (0.5 + f * (2.0 - 1.5 * f));
    vec2 w3 = f * f * (-0.5 + 0.5 * f);
    vec2 w12 = w1 + w2;
    vec2 t12 = (c + w2 / w12) * u_rmTaa3.zw;
    vec2 t0 = (c - 1.0) * u_rmTaa3.zw, t3 = (c + 2.0) * u_rmTaa3.zw;
    vec3 r = texture2DLod(s_rmTex2, vec2(t12.x, t0.y), 0.0).rgb * (w12.x * w0.y)
           + texture2DLod(s_rmTex2, vec2(t0.x, t12.y), 0.0).rgb * (w0.x * w12.y)
           + texture2DLod(s_rmTex2, t12, 0.0).rgb * (w12.x * w12.y)
           + texture2DLod(s_rmTex2, vec2(t3.x, t12.y), 0.0).rgb * (w3.x * w12.y)
           + texture2DLod(s_rmTex2, vec2(t12.x, t3.y), 0.0).rgb * (w12.x * w3.y);
    float wsum = w12.x * w0.y + w0.x * w12.y + w12.x * w12.y + w3.x * w12.y + w12.x * w3.y;
    return max(r / wsum, vec3_splat(0.0));
}

void main()
{
    vec2 tuv = v_texcoord0.xy;
    vec2 px = u_rmTaa3.zw;
    vec3 cur = texture2DLod(s_rmTex0, tuv, 0.0).rgb;
    if (u_rmTaa2.w > 0.5) {
        gl_FragColor = vec4(cur, 1.0);
        return;
    }
    // the 3x3 neighbourhood's moments (YCoCg) and the nearest depth (dilated: edges reproject with the foreground)
    vec3 m1 = vec3_splat(0.0), m2 = vec3_splat(0.0);
    float dmin = 1.0;
    vec2 dUv = tuv;
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            vec2 o = vec2(float(i), float(j)) * px;
            vec3 c = toYCoCg(texture2DLod(s_rmTex0, tuv + o, 0.0).rgb);
            m1 += c;
            m2 += c * c;
            float d = texture2DLod(s_rmTex1, tuv + o, 0.0).x;
            if (d < dmin) {
                dmin = d;
                dUv = tuv + o;
            }
        }
    }
    m1 *= 1.0 / 9.0;
    m2 *= 1.0 / 9.0;
    vec3 sigma = sqrt(max(m2 - m1 * m1, vec3_splat(0.0)));
    vec3 lo = m1 - u_rmTaa3.y * sigma, hi = m1 + u_rmTaa3.y * sigma;
    // reproject: this pixel's camera-space position (at the nearest depth) into the last frame's screen
    vec3 p = viewPos(texUv(tuv), min(dmin, 0.999999));
    vec4 q = vec4(dot(u_rmTaaM[0], vec4(p, 1.0)), dot(u_rmTaaM[1], vec4(p, 1.0)), dot(u_rmTaaM[2], vec4(p, 1.0)),
                  dot(u_rmTaaM[3], vec4(p, 1.0)));
    vec2 prev = vec2(q.x / q.w * 0.5 + 0.5, 0.5 - q.y / q.w * 0.5);
    if (u_rmTaa3.x > 1.5) {
        // an object's own motion where it is what the scene shows (its depth agrees with the scene's)
        vec4 mv = texture2DLod(s_rmTex3, dUv, 0.0);
        float z = viewZ(dmin);
        if (mv.a > 0.5 && abs(mv.b - z) < 0.03 * z + 0.3)
            prev = texUv(tuv) - mv.xy;
    }
    vec2 ptuv = texUv(prev);
    float alpha = u_rmTaa2.z;
    if (q.w <= 0.0 || prev.x < 0.0 || prev.x > 1.0 || prev.y < 0.0 || prev.y > 1.0) {
        gl_FragColor = vec4(cur, 1.0);
        return;
    }
    vec3 h = toYCoCg(history(ptuv));
    // clip the history towards the box's centre
    vec3 ctr = 0.5 * (hi + lo), ext = 0.5 * (hi - lo) + 1e-4;
    vec3 v = h - ctr;
    vec3 a = abs(v / ext);
    float m = max(a.x, max(a.y, a.z));
    if (m > 1.0)
        h = ctr + v / m;
    vec3 hc = fromYCoCg(h);
    // the motion in pixels: faster motion trusts the current frame more (less blur in pans)
    vec2 mv = (tuv - ptuv) / px;
    alpha = mix(alpha, 0.35, clamp(length(mv) / 32.0, 0.0, 1.0));
    float wc = alpha / (1.0 + dot(cur, vec3(0.299, 0.587, 0.114)));
    float wh = (1.0 - alpha) / (1.0 + dot(hc, vec3(0.299, 0.587, 0.114)));
    gl_FragColor = vec4((cur * wc + hc * wh) / (wc + wh), 1.0);
}
