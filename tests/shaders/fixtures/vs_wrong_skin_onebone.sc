$input a_position, a_normal, a_indices, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// A DELIBERATELY WRONG copy of src/platform/sdl/pddi/shaders/vp/vs_vp_skin_onebone.sc for
// tests/shaders/test_shader_equiv.py: it drops lit's n.h > 0 test, so a power <= 0 gives pow(0, p), which is
// undefined (and not 0). Below, the original comment.
//
// The game's "skin_onebone" vertex program (43 NV2A instructions): each vertex follows one bone. Chosen by
// FUN_00327860 (d3dPrimBufferStream.cpp) for prim buffers whose vertex flags have bit 7 (skinned) set and bit 8
// (several bones per vertex) clear; "skin" is the several-bone version. Four directional lights in view
// space, the first with a Blinn specular term (the D3D `lit` rule), and fog from view-space z.
// Proven equivalent with tools/shader_equiv.py.
//
// Constants (hardware numbering; u_vc[i] is c[96 + i]), as FUN_00324270 and d3dExtHardwareSkinning::vfunc_5
// (0x322200) upload them:
//   c96        (0, 1, 256, 0.5)
//   c98-c101   rows of transform 1 (projection), transposed
//   c102       material diffuse colour       c103  specular colour (w: specular power)
//   c104       emissive + ambient * the ambient light
//   c105+2i    light i direction (view space); c106+2i light i diffuse colour (zero when the light is off)
//   c113+3i    bone i: three rows of (bone matrix * view), transposed
// The bone index is a normalised byte holding 3 * bone: floor(byte/255 * 256) = 3 * bone for every byte
// below 255, so the scale by 256 (not 255) makes the conversion immune to rounding.
//
// nv2a-program: skin_onebone
// nv2a-input: a_position = v0 position
// nv2a-input: a_normal = v2 normal
// nv2a-input: a_indices = v15 index:3:26
// nv2a-input: a_texcoord0 = v9 uv
// nv2a-input: a_texcoord1 = v10 uv
// nv2a-input: a_texcoord2 = v11 uv
// nv2a-input: a_texcoord3 = v12 uv
// nv2a-uniform: u_vc = c96
// nv2a-const: c96 = fixed 0 1 256 0.5
// nv2a-const: c98..c101 = projection
// nv2a-const: c102 = color
// nv2a-const: c103 = range 0 16
// nv2a-const: c104 = color
// nv2a-const: c105 = direction
// nv2a-const: c106 = color
// nv2a-const: c107 = direction
// nv2a-const: c108 = color
// nv2a-const: c109 = direction
// nv2a-const: c110 = color
// nv2a-const: c111 = direction
// nv2a-const: c112 = color
// nv2a-const: c113..c190 = bones

#include <bgfx_shader.sh>

uniform vec4 u_vc[96];          // c96 .. c191

#define VC_CONST     u_vc[0]    // c96: (0, 1, 256, 0.5)
#define VC_PROJ      2          // c98:  projection rows
#define VC_DIFFUSE   u_vc[6]    // c102
#define VC_SPECULAR  u_vc[7]    // c103 (w: power)
#define VC_BASE      u_vc[8]    // c104
#define VC_LIGHT     9          // c105: 4 x (direction, colour)
#define VC_BONES     17         // c113: 3 rows per bone

// Light i's diffuse contribution for lights 1..3: max(0, (n . -dir) * colour), then times the material.
vec4 directional(int i, vec3 n)
{
    float ndl = dot(n, -u_vc[VC_LIGHT + 2 * i].xyz);
    return max(VC_CONST.xxxx, ndl * u_vc[VC_LIGHT + 2 * i + 1]);
}

void main()
{
    // the bone: three rows of a 3x4 matrix, from the index the vertex carries
    int bone = VC_BONES + int(floor(a_indices.x * VC_CONST.z));
    vec4 b0 = u_vc[bone];
    vec4 b1 = u_vc[bone + 1];
    vec4 b2 = u_vc[bone + 2];

    vec4 p = vec4(a_position, 1.0);
    vec4 view = vec4(dot(p, b0), dot(p, b1), dot(p, b2), VC_CONST.y);
    gl_Position = vec4(dot(view, u_vc[VC_PROJ]), dot(view, u_vc[VC_PROJ + 1]),
                       dot(view, u_vc[VC_PROJ + 2]), dot(view, u_vc[VC_PROJ + 3]));
    v_fog = view.z;

    // the normal goes through the bone's rotation part (not renormalised, as in the program)
    vec3 n = vec3(dot(a_normal, b0.xyz), dot(a_normal, b1.xyz), dot(a_normal, b2.xyz));

    // light 0: diffuse and a specular term from the half vector of the light and the view axis (0, 0, 1)
    vec3 h = -u_vc[VC_LIGHT].xyz - VC_CONST.xxy;
    h = h * inversesqrt(dot(h, h));
    float ndl = dot(n, -u_vc[VC_LIGHT].xyz);
    float ndh = dot(n, h);
    float power = clamp(VC_SPECULAR.w, -127.9961, 127.9961);
    float diffuse0 = max(ndl, 0.0);                                    // lit: y
    float specular0 = (ndl > 0.0) ? pow(max(ndh, 0.0), power) : 0.0;   // WRONG: pow(0, power <= 0)

    vec4 colour = VC_BASE;
    colour = max(VC_CONST.xxxx, diffuse0 * u_vc[VC_LIGHT + 1]) * VC_DIFFUSE + colour;
    colour = directional(1, n) * VC_DIFFUSE + colour;
    colour = directional(2, n) * VC_DIFFUSE + colour;
    colour = directional(3, n) * VC_DIFFUSE + colour;
    vec4 specular = max(VC_CONST.xxxx, specular0 * u_vc[VC_LIGHT + 1]) * VC_SPECULAR;

    // min with c96.y as the program does; the NV2A then clamps colour outputs to [0, 1]
    v_color0 = saturate(min(colour, VC_CONST.yyyy));
    v_color1 = saturate(min(specular, VC_CONST.yyyy));

    v_texcoord0 = vec4(a_texcoord0, 0.0, 1.0);
    v_texcoord1 = vec4(a_texcoord1, 0.0, 1.0);
    v_texcoord2 = vec4(a_texcoord2, 0.0, 1.0);
    v_texcoord3 = vec4(a_texcoord3, 0.0, 1.0);
}
