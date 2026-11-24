$input v_texcoord0

// Temporal upscaling's inputs (wperf2, taa.cpp, upscale.h; docs/performance.md 4.2): at the frame's first effect, each
// pixel's screen motion to the last presented frame (rg: uv, top-left origin, last - current: the camera's through the
// scene's depth, an object's own where the velocity target holds it and its depth agrees) and the scene's depth copied
// (gl_FragDepth: the effects and HUD that follow may change the scene's). Constants as fs_rm_taa.sc's.
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex1, 1);         // the scene's depth
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

void main()
{
    vec2 tuv = v_texcoord0.xy;
    vec2 s = texUv(tuv);
    float d = texture2DLod(s_rmTex1, tuv, 0.0).x;
    vec3 p = viewPos(s, min(d, 0.999999));
    vec4 q = vec4(dot(u_rmTaaM[0], vec4(p, 1.0)), dot(u_rmTaaM[1], vec4(p, 1.0)), dot(u_rmTaaM[2], vec4(p, 1.0)),
                  dot(u_rmTaaM[3], vec4(p, 1.0)));
    vec2 prev = q.w > 0.0 ? vec2(q.x / q.w * 0.5 + 0.5, 0.5 - q.y / q.w * 0.5) : vec2(-1.0, -1.0);
    if (u_rmTaa3.x > 1.5) {
        vec4 mv = texture2DLod(s_rmTex3, tuv, 0.0);
        float z = viewZ(d);
        if (mv.a > 0.5 && abs(mv.b - z) < 0.03 * z + 0.3)
            prev = s - mv.xy;
    }
    gl_FragColor = vec4(prev - s, 0.0, 1.0);
    gl_FragDepth = d;
}
