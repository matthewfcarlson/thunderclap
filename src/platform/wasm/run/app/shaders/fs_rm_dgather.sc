$input v_texcoord0

// Cutscene depth of field (wlens1): the bokeh gather at half size. 36 taps on a golden-angle disc out to the largest
// circle; a tap reaches this texel when its own circle covers the distance (a tap behind this one only as far as twice
// this texel's own circle: a sharp subject keeps its edge against a blurred background), brighter taps weigh more (the
// highlights open into discs). Alpha: how blurred the texel is, the foreground spilling over it included.
//   s_rmTex0 the prepared colour + signed circle (fs_rm_dprep.sc)
//   u_rmDofG xy the half-size texel, z the largest radius (texels), w the cutscene ease
#include <bgfx_shader.sh>
// (the lens shaders' shared helpers, copied in each: a new .sh include recompiles every runner shader)

// the view depth (world units, positive) of a D3D depth d
float lensViewZ(float d, vec4 p)
{
    return abs((p.y - d * p.w) / min(d * p.z - p.x, -1e-7));
}

// the signed circle of confusion (-1 near .. 0 in focus .. 1 far) of view depth z with the focus f: a thin lens's
// |1/f - 1/z| times the aperture k, past a band (a close-up's background blurs, a wide shot stays sharp)
float lensCoc(float z, float f, float band, float k)
{
    float r = (1.0 / max(f, 0.05) - 1.0 / max(z, 0.05)) * k;
    float s = clamp((abs(r) - band) * 1.25, 0.0, 1.0);
    return r < 0.0 ? -s : s;
}

float lensLum(vec3 c) { return dot(c, vec3(0.2126, 0.7152, 0.0722)); }

float lensHash(vec2 p)
{
    vec3 q = fract(vec3(p.x, p.y, p.x) * 0.1031);
    q += dot(q, q.yzx + 33.33);
    return fract((q.x + q.y) * q.z);
}

SAMPLER2D(s_rmTex0, 0);
uniform vec4 u_rmDofG;

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec4 c0 = texture2DLod(s_rmTex0, uv, 0.0);
    float maxR = u_rmDofG.z;
    float cr = abs(c0.a) * maxR;
    vec3 acc = c0.rgb;
    float wsum = 1.0, fg = 0.0;
    for (int i = 0; i < 36; i++) {
        float fi = float(i);
        float r = maxR * sqrt((fi + 0.5) / 36.0);
        float a = fi * 2.39996323;
        vec4 s = texture2DLod(s_rmTex0, uv + vec2(cos(a), sin(a)) * r * u_rmDofG.xy, 0.0);
        float sr = abs(s.a) * maxR;
        if (s.a > c0.a)
            sr = min(sr, cr * 2.0);
        float m = clamp((sr - r + 0.75) / 1.5, 0.0, 1.0);
        float w = m * (1.0 + 2.5 * max(lensLum(s.rgb) - 0.7, 0.0));
        acc += s.rgb * w;
        wsum += w;
        if (s.a < c0.a && s.a < 0.0)
            fg = max(fg, m * abs(s.a));
    }
    gl_FragColor = vec4(acc / wsum, max(abs(c0.a), fg));
}
