$input v_texcoord0

// Cutscene depth of field (wlens1): the half-size colour and signed circle of confusion (alpha), the nearest of the
// four depths the texel covers (a foreground edge keeps its blur); a letterbox bar's rows are in focus (they never
// spread).
//   s_rmTex0 the scene copy (bilinear: one tap averages the four), s_rmTex1 the focus (1x1), s_rmTex2 the depth
//   u_rmDof[0] the depth rows; u_rmDof[1] y the focus band, z the aperture; u_rmDofG xy the full-size texel
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
SAMPLER2D(s_rmTex1, 1);
SAMPLER2D(s_rmTex2, 2);
uniform vec4 u_rmDof[3];
uniform vec4 u_rmDofG;

// a letterbox bar's row: the scene copy (s_rmTex0) black across it (the game draws the bars before its effects)
float lensBar(float v)
{
    float m = 0.0;
    for (int i = 0; i < 5; i++)
        m = max(m, dot(texture2DLod(s_rmTex0, vec2(0.1 + 0.2 * float(i), v), 0.0).rgb, vec3_splat(1.0)));
    return m < 0.004 ? 1.0 : 0.0;
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec2 d = u_rmDofG.xy * 0.5;
    float z = lensViewZ(texture2DLod(s_rmTex2, uv + vec2(-d.x, -d.y), 0.0).x, u_rmDof[0]);
    z = min(z, lensViewZ(texture2DLod(s_rmTex2, uv + vec2(d.x, -d.y), 0.0).x, u_rmDof[0]));
    z = min(z, lensViewZ(texture2DLod(s_rmTex2, uv + vec2(-d.x, d.y), 0.0).x, u_rmDof[0]));
    z = min(z, lensViewZ(texture2DLod(s_rmTex2, uv + vec2(d.x, d.y), 0.0).x, u_rmDof[0]));
    float f = texture2DLod(s_rmTex1, vec2(0.5, 0.5), 0.0).x;
    vec3 c = max(texture2DLod(s_rmTex0, uv, 0.0).rgb, vec3_splat(0.0));
    float bar = lensBar(uv.y);
    gl_FragColor = vec4(c, (1.0 - bar) * lensCoc(z, f, u_rmDof[1].y, u_rmDof[1].z));
}
