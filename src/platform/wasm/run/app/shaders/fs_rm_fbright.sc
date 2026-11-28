$input v_texcoord0

// Lens flare (wlens1, run/app/lens.cpp): the strong small lights at quarter size. A texel passes by how far its
// brightness is over the threshold and over its surround's (a ring of 8 taps): lamps, signs, orbs and flashes pass, a
// bright sky or a sunlit wall does not.
//   s_rmTex0 the scene copy; u_rmFlare[0] xy the full-size texel, z the threshold, w the ring's radius (uv)
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
uniform vec4 u_rmFlare[4];

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec2 d = u_rmFlare[0].xy;
    vec3 c = (texture2DLod(s_rmTex0, uv + vec2(-d.x, -d.y), 0.0).rgb + texture2DLod(s_rmTex0, uv + vec2(d.x, -d.y), 0.0).rgb +
              texture2DLod(s_rmTex0, uv + vec2(-d.x, d.y), 0.0).rgb + texture2DLod(s_rmTex0, uv + vec2(d.x, d.y), 0.0).rgb) * 0.25;
    float r = u_rmFlare[0].w;
    vec2 ry = vec2(r, r * u_rmFlare[1].z);
    float ring = 0.0;
    for (int i = 0; i < 8; i++) {
        float a = float(i) * 0.7853982;
        ring += lensLum(texture2DLod(s_rmTex0, uv + vec2(cos(a), sin(a)) * ry, 0.0).rgb);
    }
    ring *= 0.125;
    c = max(c, vec3_splat(0.0));
    float l = lensLum(c);
    float thr = u_rmFlare[0].z;
    float b = clamp((l - thr) / max(1.0 - thr, 0.05), 0.0, 1.0) * clamp((l - ring - 0.25) * 3.0, 0.0, 1.0);
    gl_FragColor = vec4(min(c, vec3_splat(2.0)) * b, 1.0);
}
