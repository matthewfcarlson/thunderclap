$input a_position, a_normal, a_texcoord0
$output v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1

// The game's "refract" vertex program (54 NV2A instructions), selected by d3dRefractVertexShader::vfunc_23 for
// the refraction effect (43 prim groups in the data). It lights the vertex with three directional lights, as
// the other programs do, but scales the lighting by a single view-dependent factor k (an edge/Fresnel-like
// term from the transformed normal and the screen position), and builds oT0, the coordinate at which the
// pixel stage samples the already-drawn frame: the normal, projected like a point, scaled and offset by the
// vertex's own screen position. oT1 is the model's own texture coordinate.
// Proven equivalent with tools/shader_equiv.py.
//
// Constants (hardware numbering; u_vc[i] is c[96 + i]), as d3dRefractVertexShader::vfunc_24 (0x32f3b0) uploads
// them:
//   c96        (0, 1, 256, 0.5)
//   c98-c101   rows of the clip transform, transposed (applied to the position, and to the normal taken as a point)
//   c102-c104  three rows of a second transform, transposed (applied to the normal as a direction)
//   c107       viewport (width, height, 1, 1)
//   c108       (u scale, v scale, 0, 0): the frame texture's used fraction times the effect scale
//   c109       (0.5, 0.5, 0.5, 0.5)
//   c110       material diffuse   c111  material specular (w: power)   c112  emissive + ambient * global ambient
//   c113+2i    light i direction (view space); c114+2i light i colour (zero when the light is off)  i = 0..2
//   c121       w: intensity - 0.3 (the game's alpha and intensity setting), the offset in k
//
// What it computes, in the program's own odd form: nT = the second transform's rotation applied to the normal;
// ndc = clip.xyz / clip.w; k = clamp((nT . ndc)^2 + c121.w, 0, 1). Each light's "n.l" is not a dot product with the
// normal but k times the sum of the components of -direction, and its "n.h" is k times the sum of the components
// of the half vector of the light and the view axis (0, 0, 1); lit's rule turns those into a diffuse and
// specular amount for light 0, and lights 1 and 2 add diffuse only. Both colours carry k in alpha. Fog is 0.
//
// nv2a-program: refract
// nv2a-input: a_position = v0 position
// nv2a-input: a_normal = v2 normal
// nv2a-input: a_texcoord0 = v9 uv
// nv2a-uniform: u_vc = c96
// nv2a-const: c96 = fixed 0 1 256 0.5
// nv2a-const: c98..c101 = projection
// nv2a-const: c102..c104 = matrix
// nv2a-const: c107 = range 100 1000
// nv2a-const: c108 = range 0 1
// nv2a-const: c109 = fixed 0.5 0.5 0.5 0.5
// nv2a-const: c110 = color
// nv2a-const: c111 = range 0 16
// nv2a-const: c112 = color
// nv2a-const: c113 = direction
// nv2a-const: c114 = color
// nv2a-const: c115 = direction
// nv2a-const: c116 = color
// nv2a-const: c117 = direction
// nv2a-const: c118 = color
// nv2a-const: c121 = range -0.3 0.7

#include <bgfx_shader.sh>

uniform vec4 u_vc[26];          // c96 .. c121

#define VC_CONST     u_vc[0]    // c96: (0, 1, 256, 0.5)
#define VC_CLIP      2          // c98:  four rows
#define VC_NORMAL    6          // c102: three rows
#define VC_VIEWPORT  u_vc[11]   // c107
#define VC_UVSCALE   u_vc[12]   // c108
#define VC_HALF      u_vc[13]   // c109
#define VC_DIFFUSE   u_vc[14]   // c110
#define VC_SPECULAR  u_vc[15]   // c111 (w: power)
#define VC_EMISSIVE  u_vc[16]   // c112
#define VC_LIGHT     17         // c113: 3 x (direction, colour)
#define VC_BIAS      u_vc[25].w // c121.w

// the sum of the components of a vector (the program's "dot with (k, k, k)" form)
float sum3(vec3 v) { return v.x + v.y + v.z; }

// A light's diffuse colour contribution: max(0, amount * colour), times the material diffuse
vec3 diffuse_term(float amount, vec3 colour)
{
    return max(VC_CONST.xxx, amount * colour) * VC_DIFFUSE.xyz;
}

void main()
{
    vec4 p = vec4(a_position, 1.0);
    vec4 clip = vec4(dot(u_vc[VC_CLIP], p), dot(u_vc[VC_CLIP + 1], p), dot(u_vc[VC_CLIP + 2], p), dot(u_vc[VC_CLIP + 3], p));
    gl_Position = clip;
    v_fog = 0.0;
    v_texcoord1 = vec4(a_texcoord0, 0.0, 1.0);

    // the screen position of the vertex, and the factor k
    vec4 ndc = clip * (1.0 / clip.w);
    vec3 nt = vec3(dot(u_vc[VC_NORMAL].xyz, a_normal), dot(u_vc[VC_NORMAL + 1].xyz, a_normal),
                   dot(u_vc[VC_NORMAL + 2].xyz, a_normal));
    float nd = dot(nt, ndc.xyz);
    float k = clamp(-nd * -nd + VC_BIAS, 0.0, 1.0);

    // light 0: the half vector of the light and the view axis, and lit's rule
    vec3 h = -u_vc[VC_LIGHT].xyz - VC_CONST.xxy;
    h = h * inversesqrt(dot(h, h));
    float amount0 = -k * sum3(u_vc[VC_LIGHT].xyz);
    float half0 = k * sum3(h);
    float power = clamp(VC_SPECULAR.w, -127.9961, 127.9961);
    float diffuse0 = max(amount0, 0.0);                                   // lit: y
    float specular0 = (amount0 > 0.0 && half0 > 0.0) ? pow(half0, power) : 0.0; // lit: z

    float amount1 = -k * sum3(u_vc[VC_LIGHT + 2].xyz);
    float amount2 = -k * sum3(u_vc[VC_LIGHT + 4].xyz);

    vec3 colour = VC_EMISSIVE.xyz;
    colour = diffuse_term(diffuse0, u_vc[VC_LIGHT + 1].xyz) + colour;
    colour = diffuse_term(amount1, u_vc[VC_LIGHT + 3].xyz) + colour;
    colour = diffuse_term(amount2, u_vc[VC_LIGHT + 5].xyz) + colour;
    vec3 specular = max(VC_CONST.xxx, specular0 * u_vc[VC_LIGHT + 1].xyz) * VC_SPECULAR.xyz;

    // colour outputs: min with c96.y as the program does, then the NV2A's clamp to [0, 1]; alpha is k
    v_color0 = saturate(vec4(min(colour, VC_CONST.yyy), k));
    v_color1 = saturate(vec4(min(specular, VC_CONST.yyy), k));

    // oT0: the normal as a point through the clip transform (perspective divided), scaled by the used
    // fraction of the frame texture and offset by the vertex's own screen position in texture space
    vec4 np = vec4(dot(u_vc[VC_CLIP], vec4(a_normal, 1.0)), dot(u_vc[VC_CLIP + 1], vec4(a_normal, 1.0)),
                   dot(u_vc[VC_CLIP + 2], vec4(a_normal, 1.0)), dot(u_vc[VC_CLIP + 3], vec4(a_normal, 1.0)));
    np = np * (1.0 / np.w);
    vec4 screen = ndc;
    screen.x = ndc.x * VC_HALF.x + VC_HALF.x;
    screen.y = ndc.y * -VC_HALF.x + VC_HALF.x;
    v_texcoord0 = np * VC_UVSCALE + screen * VC_VIEWPORT;
}
