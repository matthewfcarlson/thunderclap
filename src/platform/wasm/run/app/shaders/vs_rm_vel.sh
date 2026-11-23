// TAA's motion vectors (wperf1, taa.cpp): an object draw again into the velocity target, its vertex both where the
// draw puts it now (u_vc, jittered: it rasterises where the scene's did) and where the same draw put it in the last
// presented frame (u_rmPrev, unjittered). v_texcoord0 / v_texcoord1: the current (jitter removed) and the last clip
// positions. VEL_SKIN 0: fixed function (modelview c0..c3, projection c4..c7); 1: three bones, 2: one bone
// (vs_vp_skin*.sc: projection c98.., bones c113.., three rows each).
#include <bgfx_shader.sh>

uniform vec4 u_vc[96];
uniform vec4 u_rmPrev[96];
uniform vec4 u_rmVel;           // x, y: the jitter (NDC) the current constants carry

#if VEL_SKIN == 0
#define VEL_VIEW(U) vec4(dot(p, U[0]), dot(p, U[1]), dot(p, U[2]), dot(p, U[3]))
#define VEL_PROJ 4
#elif VEL_SKIN == 1
#define VEL_BONE(U, b) vec4(dot(p, U[b]), dot(p, U[b + 1]), dot(p, U[b + 2]), 1.0)
#define VEL_VIEW(U) (w2 * VEL_BONE(U, bi2) + (w1 * VEL_BONE(U, bi1) + w0 * VEL_BONE(U, bi0)))
#define VEL_PROJ 2
#else
#define VEL_VIEW(U) vec4(dot(p, U[bi0]), dot(p, U[bi0 + 1]), dot(p, U[bi0 + 2]), 1.0)
#define VEL_PROJ 2
#endif
#define VEL_CLIP(U, v) vec4(dot(v, U[VEL_PROJ]), dot(v, U[VEL_PROJ + 1]), dot(v, U[VEL_PROJ + 2]), dot(v, U[VEL_PROJ + 3]))

void main()
{
    vec4 p = vec4(a_position, 1.0);
#if VEL_SKIN != 0
    int bi0 = 17 + int(floor(a_indices.x * 256.0));
#endif
#if VEL_SKIN == 1
    int bi1 = 17 + int(floor(a_indices.y * 256.0));
    int bi2 = 17 + int(floor(a_indices.z * 256.0));
    float w0 = a_weight.x;
    float w1 = a_weight.y;
    float w2 = 1.0 - (w0 + w1);
#endif
    vec4 v = VEL_VIEW(u_vc);
    vec4 c = VEL_CLIP(u_vc, v);
    gl_Position = c;
    v_texcoord0 = vec4(c.x - u_rmVel.x * c.w, c.y - u_rmVel.y * c.w, c.z, c.w);
    vec4 vp = VEL_VIEW(u_rmPrev);
    v_texcoord1 = VEL_CLIP(u_rmPrev, vp);
}
