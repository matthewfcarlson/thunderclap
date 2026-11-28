$input v_texcoord0

// Cutscene depth of field (wlens1, run/app/lens.cpp): the focus distance, into a 1x1 target. The subject is the main
// actor when he is in the shot and the depth there is not much nearer than he is (not hidden), else the nearest
// cluster of 25 depth taps over the frame's upper middle (where a cutscene frames faces); eased from the last frame's
// focus in log depth.
//   s_rmTex0 the scene's depth, s_rmTex1 the last focus (x)
//   u_rmDof[0] the depth rows (lensViewZ); u_rmDof[1] x the ease (1: take this frame's), w 1: no last focus;
//   u_rmDof[2] the main actor: xy uv, z his view depth, w 1: in the shot
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
uniform vec4 u_rmDof[3];

float tapZ(int i, int j)
{
    vec2 uv = vec2(0.32 + 0.09 * float(i), 0.24 + 0.1 * float(j));
    return min(lensViewZ(texture2DLod(s_rmTex0, uv, 0.0).x, u_rmDof[0]), 400.0);
}

void main()
{
    float zmin = 400.0;
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 5; i++)
            zmin = min(zmin, max(tapZ(i, j), 1.0));
    float lim = zmin * 1.6 + 0.5;
    float sum = 0.0, wsum = 0.0;
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 5; i++) {
            float z = max(tapZ(i, j), 1.0);
            float w = (z <= lim ? 1.0 : 0.0) * (1.0 - 0.12 * (abs(float(i) - 2.0) + abs(float(j) - 2.0)));
            sum += log(z) * w;
            wsum += w;
        }
    float f = wsum > 0.0 ? sum / wsum : log(zmin);
    if (u_rmDof[2].w > 0.5) {
        vec2 s = u_rmDof[2].xy;
        float zs = min(lensViewZ(texture2DLod(s_rmTex0, s, 0.0).x, u_rmDof[0]),
                       min(lensViewZ(texture2DLod(s_rmTex0, s + vec2(0.0, 0.03), 0.0).x, u_rmDof[0]),
                           lensViewZ(texture2DLod(s_rmTex0, s - vec2(0.0, 0.03), 0.0).x, u_rmDof[0])));
        if (zs > u_rmDof[2].z * 0.75)
            f = log(max(u_rmDof[2].z, 1.0));
    }
    float prev = texture2DLod(s_rmTex1, vec2(0.5, 0.5), 0.0).x;
    float lf = f;
    if (u_rmDof[1].w < 0.5 && prev > 0.5 && prev < 1000.0)
        lf = mix(log(prev), f, u_rmDof[1].x);
    gl_FragColor = vec4(exp(lf), exp(f), 0.0, 1.0);
}
