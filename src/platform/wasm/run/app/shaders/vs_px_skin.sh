// Per-pixel lighting (docs/lighting.md): the game's "skin" / "skin_onebone" vertex programs as shaders/vp/vs_vp_skin.sc
// and vs_vp_skin_onebone.sc port them (same constants, bones, position and normal), with the four directional lights
// left to fs_px_stage.sh. v_pxbase carries c104 (emissive + ambient x the ambient light).
#include <bgfx_shader.sh>

uniform vec4 u_vc[96];          // c96 .. c191

#define VC_CONST     u_vc[0]    // c96: (0, 1, 256, 0.5)
#define VC_PROJ      2          // c98:  projection rows
#define VC_DIFFUSE   u_vc[6]    // c102
#define VC_BASE      u_vc[8]    // c104
#define VC_BONES     17         // c113: 3 rows per bone

void main()
{
    vec4 p = vec4(a_position, 1.0);
#ifdef PX_ONEBONE
    int bone = VC_BONES + int(floor(a_indices.x * VC_CONST.z));
    vec4 b0 = u_vc[bone];
    vec4 b1 = u_vc[bone + 1];
    vec4 b2 = u_vc[bone + 2];
    vec4 view = vec4(dot(p, b0), dot(p, b1), dot(p, b2), VC_CONST.y);
    vec3 nsum = vec3(dot(a_normal, b0.xyz), dot(a_normal, b1.xyz), dot(a_normal, b2.xyz));
#else
    int bi0 = VC_BONES + int(floor(a_indices.x * VC_CONST.z));
    int bi1 = VC_BONES + int(floor(a_indices.y * VC_CONST.z));
    int bi2 = VC_BONES + int(floor(a_indices.z * VC_CONST.z));
    float w0 = a_weight.x;
    float w1 = a_weight.y;
    float w2 = VC_CONST.y - (w0 + w1);
    vec4 pa = vec4(dot(p, u_vc[bi0]), dot(p, u_vc[bi0 + 1]), dot(p, u_vc[bi0 + 2]), VC_CONST.y);
    vec4 pb = vec4(dot(p, u_vc[bi1]), dot(p, u_vc[bi1 + 1]), dot(p, u_vc[bi1 + 2]), VC_CONST.y);
    vec4 pc = vec4(dot(p, u_vc[bi2]), dot(p, u_vc[bi2 + 1]), dot(p, u_vc[bi2 + 2]), VC_CONST.y);
    vec4 view = w2 * pc + (w1 * pb + w0 * pa);
    vec3 na = vec3(dot(a_normal, u_vc[bi0].xyz), dot(a_normal, u_vc[bi0 + 1].xyz), dot(a_normal, u_vc[bi0 + 2].xyz));
    vec3 nb = vec3(dot(a_normal, u_vc[bi1].xyz), dot(a_normal, u_vc[bi1 + 1].xyz), dot(a_normal, u_vc[bi1 + 2].xyz));
    vec3 nsum = nb * (VC_CONST.y - w0) + na;
#endif
    gl_Position = vec4(dot(view, u_vc[VC_PROJ]), dot(view, u_vc[VC_PROJ + 1]),
                       dot(view, u_vc[VC_PROJ + 2]), dot(view, u_vc[VC_PROJ + 3]));
    v_fog = view.z;
    float len2 = dot(nsum, nsum);
    v_pxnormal = vec4(len2 > 0.0 ? nsum * inversesqrt(len2) : vec3(0.0, 0.0, 0.0), len2 > 0.0 ? 1.0 : 0.0);
    v_pxpos = view.xyz;
    v_pxbase = vec4(VC_BASE.xyz, VC_DIFFUSE.w);
    v_pxspec = vec4(0.0, 0.0, 0.0, VC_DIFFUSE.w);
    v_texcoord0 = vec4(a_texcoord0, 0.0, 1.0);
    v_texcoord1 = vec4(a_texcoord1, 0.0, 1.0);
    v_texcoord2 = vec4(a_texcoord2, 0.0, 1.0);
    v_texcoord3 = vec4(a_texcoord3, 0.0, 1.0);
}
