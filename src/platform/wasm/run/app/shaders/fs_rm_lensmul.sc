$input v_texcoord0

// Lens effects (wlens1, run/app/lens.cpp): the vignette and the grain alone, as one factor multiplied into the scene
// (blend dst * src + src * dst: the output is half the factor), with no copy of the scene.
//   u_rmLens as fs_rm_lens.sc's (z the vignette, w the grain; u_rmLens[2] y the seed, z the aspect; [3] zw the size)
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

uniform vec4 u_rmLens[4];

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec2 d = uv - vec2_splat(0.5);
    float asp = u_rmLens[2].z;
    float rr = length(d * vec2(asp, 1.0)) / length(vec2(0.5 * asp, 0.5));
    float k = 1.0 - u_rmLens[0].z * 0.32 * smoothstep(0.35, 1.05, rr);
    float g = u_rmLens[0].w;
    if (g > 0.0) {
        vec2 px = floor(uv * u_rmLens[3].zw);
        float s = u_rmLens[2].y;
        float n = (lensHash(px + s * 7.13) - 0.5) * 0.6 + (lensHash(floor(px * 0.5) + s * 3.71 + 19.0) - 0.5) * 0.4;
        k *= 1.0 + n * g * 0.12;
    }
    gl_FragColor = vec4_splat(k * 0.5);
}
