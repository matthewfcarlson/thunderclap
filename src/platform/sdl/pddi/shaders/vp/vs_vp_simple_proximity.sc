$input a_position, a_color0, a_texcoord0
$output v_color0, v_fog, v_texcoord0

// The game's "simple_proximity" vertex program (30 NV2A instructions), selected by d3dSimpleShader::vfunc_23
// when the shader's proximity-lighting flag is set: transform, plus up to four point lights with an
// inverse-square falloff added to the vertex colour. Proven equivalent with tools/shader_equiv.py.
//
// Constants (hardware numbering; u_vc[i] is c[96 + i]), as d3dSimpleShader::vfunc_24 (0x32aca0) and
// FUN_0032a600 upload them:
//   c96       (0, 0.5, 1, 1000)
//   c106-c109 rows of transform 6, transposed (world): the world-space position
//   c110-c113 rows of (transform 6 * transform 0 * transform 1), transposed: the clip-space position
//   c126+3i   light i position (xyz)                         i = 0..3; an unused light has colour 0
//   c127+3i   light i attenuation (z: the D3D light's Attenuation2)
//   c128+3i   light i colour (diffuse rgb; w 0)
//
// nv2a-program: simple_proximity
// nv2a-input: a_position = v0 position
// nv2a-input: a_color0 = v3 color bgra
// nv2a-input: a_texcoord0 = v9 uv
// nv2a-uniform: u_vc = c96
// nv2a-const: c96 = fixed 0 0.5 1 1000
// nv2a-const: c106..c109 = matrix
// nv2a-const: c110..c113 = projection
// nv2a-const: c126 = position
// nv2a-const: c127 = range 0.0001 0.01
// nv2a-const: c128 = color
// nv2a-const: c129 = position
// nv2a-const: c130 = range 0.0001 0.01
// nv2a-const: c131 = color
// nv2a-const: c132 = position
// nv2a-const: c133 = range 0.0001 0.01
// nv2a-const: c134 = color
// nv2a-const: c135 = position
// nv2a-const: c136 = range 0.0001 0.01
// nv2a-const: c137 = color

#include <bgfx_shader.sh>

uniform vec4 u_vc[42];          // c96 .. c137

#define VC_ZERO      u_vc[0]    // c96: x = 0
#define VC_WORLD     10         // c106: world rows
#define VC_WVP       14         // c110: world-view-projection rows
#define VC_LIGHTS    30         // c126: 4 x (position, attenuation, colour)

// One point light: colour / (attenuation.z * squared distance). The NV2A computes 1/x with rcp and then
// multiplies; written the same way here so the rounding steps line up.
vec3 pointLight(int i, vec3 wpos)
{
    vec3  d     = u_vc[VC_LIGHTS + 3 * i].xyz - wpos;
    float scale = u_vc[VC_LIGHTS + 3 * i + 1].z * dot(d, d);
    return u_vc[VC_LIGHTS + 3 * i + 2].xyz * (1.0 / scale);
}

void main()
{
    vec4 p = vec4(a_position, 1.0);
    gl_Position = vec4(dot(p, u_vc[VC_WVP]), dot(p, u_vc[VC_WVP + 1]),
                       dot(p, u_vc[VC_WVP + 2]), dot(p, u_vc[VC_WVP + 3]));

    vec3 wpos = vec3(dot(p, u_vc[VC_WORLD]), dot(p, u_vc[VC_WORLD + 1]), dot(p, u_vc[VC_WORLD + 2]));

    // lights 0 + 1, then + 2, then + 3, in the program's order of additions
    vec3 lit = pointLight(0, wpos) + pointLight(1, wpos);
    lit = lit + pointLight(2, wpos);
    lit = lit + pointLight(3, wpos);

    vec4 colour = a_color0.zyxw;                     // D3DCOLOR bytes B, G, R, A -> r, g, b, a
    // the NV2A clamps colour outputs to [0, 1]; a bgfx varying is not clamped
    v_color0 = saturate(vec4(lit, VC_ZERO.x) + colour);
    v_fog = wpos.z;                                  // fog from world-space z
    v_texcoord0 = vec4(a_texcoord0, 0.0, 1.0);
}
