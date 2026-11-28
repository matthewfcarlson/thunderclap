$input v_texcoord0

// Lens effects (wlens1, run/app/lens.cpp): the composite over the scene. The depth of field's blend (the half-size
// gather where the pixel's or the foreground's circle is large), chromatic aberration towards the edges, the flare
// added, the vignette and the grain.
//   s_rmTex0 the scene copy, s_rmTex1 the gather, s_rmTex2 the depth, s_rmTex3 the focus (1x1), s_rmTex4 the flare
//   u_rmLens[0] x the depth of field (the cutscene ease; 0 none), y the aberration, z the vignette, w the grain
//   u_rmLens[1] the depth rows (lensViewZ)
//   u_rmLens[2] x 1: the flare, y the grain's seed, z the aspect (width / height)
//   u_rmLens[3] x the focus band, y the aperture, zw the target's size (pixels)
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
SAMPLER2D(s_rmTex3, 3);
SAMPLER2D(s_rmTex4, 4);
uniform vec4 u_rmLens[4];

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
    vec4 c0 = texture2DLod(s_rmTex0, uv, 0.0);
    if (lensBar(uv.y) > 0.5) {
        gl_FragColor = c0;                      // (a letterbox bar: left as the game drew it)
        return;
    }
    vec3 c = c0.rgb;
    vec2 d = uv - vec2_splat(0.5);
    float asp = u_rmLens[2].z;
    float rr = length(d * vec2(asp, 1.0)) / length(vec2(0.5 * asp, 0.5));      // (0 centre .. 1 corner)
    float ca = u_rmLens[0].y;
    if (ca > 0.0) {
        vec2 off = d * ca * smoothstep(0.3, 1.0, rr) * 0.011;
        c = vec3(texture2DLod(s_rmTex0, uv - off, 0.0).r, c.g, texture2DLod(s_rmTex0, uv + off, 0.0).b);
    }
    float dof = u_rmLens[0].x;
    if (dof > 0.0) {
        vec4 b = texture2DLod(s_rmTex1, uv, 0.0);
        float z = lensViewZ(texture2DLod(s_rmTex2, uv, 0.0).x, u_rmLens[1]);
        float f = texture2DLod(s_rmTex3, vec2(0.5, 0.5), 0.0).x;
        float coc = abs(lensCoc(z, f, u_rmLens[3].x, u_rmLens[3].y));
        float t = smoothstep(0.04, 0.3, max(coc, b.a)) * dof;
        c = mix(c, b.rgb, t);
    }
    if (u_rmLens[2].x > 0.5)
        c += texture2DLod(s_rmTex4, uv, 0.0).rgb;
    float vig = u_rmLens[0].z;
    if (vig > 0.0)
        c *= 1.0 - vig * 0.32 * smoothstep(0.35, 1.05, rr);
    float g = u_rmLens[0].w;
    if (g > 0.0) {
        vec2 px = floor(uv * u_rmLens[3].zw);
        float s = u_rmLens[2].y;
        float n = (lensHash(px + s * 7.13) - 0.5) * 0.6 + (lensHash(floor(px * 0.5) + s * 3.71 + 19.0) - 0.5) * 0.4;
        float l = clamp(lensLum(c), 0.0, 1.0);
        c += vec3_splat(n * g * 0.07 * (0.25 + 3.0 * l * (1.0 - l)));
    }
    gl_FragColor = vec4(max(c, vec3_splat(0.0)), c0.a);
}
