$input a_position, a_normal, a_weight, a_indices, a_texcoord0
$output v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1

// The game's "skin_refract" vertex program (72 NV2A instructions): the "refract" effect on a skinned mesh. Chosen
// by d3dRefractVertexShader::vfunc_23 when the class's skinned flag (+0x7d) is set. The data has no skinned
// refract prim group; this covers a run-time case. It is "skin"'s bone blend and lighting (a normalised normal, four
// directional lights, Blinn specular by the `lit` rule) with the refraction coordinate oT0 of "refract": the
// blended normal times a scale, plus the vertex's own screen position in texture space times the viewport.
// Both colours carry the constant c191.w as alpha. Fog is 0. oT1 is the model's own texture coordinate.
// Proven equivalent with tools/shader_equiv.py.
//
// Constants (hardware numbering; u_vc[i] is c[96 + i]), as d3dExtHardwareSkinning::vfunc_5 and
// d3dRefractVertexShader::vfunc_24 (0x32f3b0) upload them:
//   c96        (0, 1, 256, 0.5)
//   c98-c101   rows of the transform 1 (projection), transposed
//   c102       material diffuse   c103  specular (w: power)   c104  emissive + ambient * global ambient
//   c105+2i    light i direction (view space); c106+2i light i colour (zero when off)  i = 0..3
//   c113+3i    bone i: three rows of (bone matrix * view), transposed
//   c188       (u scale, v scale, 0, 0)   c189  (0.5, 0.5, 0.5, 0.5)   c190  viewport (width, height, 1, 1)
//   c191       (1, 1, 1, w): w is the colours' alpha (intensity - 0.3)
// The bone index is a normalised byte holding 3 * bone, scaled by 256 (see vs_vp_skin.sc).
//
// nv2a-program: skin_refract
// nv2a-input: a_position = v0 position
// nv2a-input: a_normal = v2 normal
// nv2a-input: a_weight = v1 weight
// nv2a-input: a_indices = v15 index:3:26
// nv2a-input: a_texcoord0 = v9 uv
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
// nv2a-const: c188 = range 0 1
// nv2a-const: c189 = fixed 0.5 0.5 0.5 0.5
// nv2a-const: c190 = range 100 1000
// nv2a-const: c191 = range -0.3 0.7

#include <bgfx_shader.sh>

uniform vec4 u_vc[96];          // c96 .. c191

#define VC_CONST     u_vc[0]    // c96: (0, 1, 256, 0.5)
#define VC_PROJ      2          // c98:  projection rows
#define VC_DIFFUSE   u_vc[6]    // c102
#define VC_SPECULAR  u_vc[7]    // c103 (w: power)
#define VC_BASE      u_vc[8]    // c104
#define VC_LIGHT     9          // c105: 4 x (direction, colour)
#define VC_BONES     17         // c113: 3 rows per bone
#define VC_UVSCALE   u_vc[92]   // c188
#define VC_HALF      u_vc[93]   // c189
#define VC_VIEWPORT  u_vc[94]   // c190
#define VC_ALPHA     u_vc[95].w // c191.w

// Light i's diffuse contribution for lights 1..3: max(0, (n . -dir) * colour), then times the material.
vec4 directional(int i, vec3 n)
{
    float ndl = dot(n, -u_vc[VC_LIGHT + 2 * i].xyz);
    return max(VC_CONST.xxxx, ndl * u_vc[VC_LIGHT + 2 * i + 1]);
}

void main()
{
    // the three bones: rows of 3x4 matrices selected by the indices the vertex carries
    int bi0 = VC_BONES + int(floor(a_indices.x * VC_CONST.z));
    int bi1 = VC_BONES + int(floor(a_indices.y * VC_CONST.z));
    int bi2 = VC_BONES + int(floor(a_indices.z * VC_CONST.z));

    vec4 p = vec4(a_position, 1.0);
    float w0 = a_weight.x;
    float w1 = a_weight.y;
    float w2 = VC_CONST.y - (w0 + w1);

    // blended view-space position (the w component accumulates the weights, as in the program)
    vec4 pa = vec4(dot(p, u_vc[bi0]), dot(p, u_vc[bi0 + 1]), dot(p, u_vc[bi0 + 2]), VC_CONST.y);
    vec4 pb = vec4(dot(p, u_vc[bi1]), dot(p, u_vc[bi1 + 1]), dot(p, u_vc[bi1 + 2]), VC_CONST.y);
    vec4 pc = vec4(dot(p, u_vc[bi2]), dot(p, u_vc[bi2 + 1]), dot(p, u_vc[bi2 + 2]), VC_CONST.y);
    vec4 view = w2 * pc + (w1 * pb + w0 * pa);
    gl_Position = vec4(dot(view, u_vc[VC_PROJ]), dot(view, u_vc[VC_PROJ + 1]),
                       dot(view, u_vc[VC_PROJ + 2]), dot(view, u_vc[VC_PROJ + 3]));
    v_fog = 0.0;

    // normal: bone 0 plus (1 - w0) of bone 1 (rotation parts), renormalised
    vec3 na = vec3(dot(a_normal, u_vc[bi0].xyz), dot(a_normal, u_vc[bi0 + 1].xyz), dot(a_normal, u_vc[bi0 + 2].xyz));
    vec3 nb = vec3(dot(a_normal, u_vc[bi1].xyz), dot(a_normal, u_vc[bi1 + 1].xyz), dot(a_normal, u_vc[bi1 + 2].xyz));
    vec3 nsum = nb * (VC_CONST.y - w0) + na;
    // a zero normal stays zero (inversesqrt(0) is undefined in SPIR-V)
    float len2 = dot(nsum, nsum);
    float inv = len2 > 0.0 ? inversesqrt(len2) : 0.0;
    vec3 n = nsum * inv;

    // light 0: diffuse and a specular term from the half vector of the light and the view axis (0, 0, 1)
    vec3 h = -u_vc[VC_LIGHT].xyz - VC_CONST.xxy;
    h = h * inversesqrt(dot(h, h));
    float ndl = dot(n, -u_vc[VC_LIGHT].xyz);
    float ndh = dot(n, h);
    float power = clamp(VC_SPECULAR.w, -127.9961, 127.9961);
    float diffuse0 = max(ndl, 0.0);                                    // lit: y
    float specular0 = (ndl > 0.0 && ndh > 0.0) ? pow(ndh, power) : 0.0; // lit: z

    vec3 colour = VC_BASE.xyz;
    colour = max(VC_CONST.xxx, diffuse0 * u_vc[VC_LIGHT + 1].xyz) * VC_DIFFUSE.xyz + colour;
    colour = directional(1, n).xyz * VC_DIFFUSE.xyz + colour;
    colour = directional(2, n).xyz * VC_DIFFUSE.xyz + colour;
    colour = directional(3, n).xyz * VC_DIFFUSE.xyz + colour;
    vec3 specular = max(VC_CONST.xxx, specular0 * u_vc[VC_LIGHT + 1].xyz) * VC_SPECULAR.xyz;

    // min with c96.y as the program does; the NV2A then clamps colour outputs to [0, 1]. Alpha is c191.w.
    v_color0 = saturate(vec4(min(colour, VC_CONST.yyy), VC_ALPHA));
    v_color1 = saturate(vec4(min(specular, VC_CONST.yyy), VC_ALPHA));

    // oT0: the normal (w: its inverse squared length, as the program leaves it) times the scale, plus the
    // vertex's screen position in texture space times the viewport
    vec4 ndc = gl_Position * (1.0 / gl_Position.w);
    ndc.x = ndc.x * VC_HALF.x + VC_HALF.x;
    ndc.y = ndc.y * -VC_HALF.x + VC_HALF.x;
    v_texcoord0 = vec4(n, inv * inv) * VC_UVSCALE + ndc * VC_VIEWPORT;
    v_texcoord1 = vec4(a_texcoord0, 0.0, 1.0);
}
