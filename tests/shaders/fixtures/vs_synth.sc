$input a_position, a_indices, a_normal, a_texcoord0
$output v_color0, v_fog, v_texcoord0

// The bgfx counterpart of synth.vp (tests/shaders): proven equivalent by tests/shaders/test_shader_equiv.py.
//
// nv2a-program: synth.vp
// nv2a-input: a_position = v0 position
// nv2a-input: a_indices = v1 index:2:4
// nv2a-input: a_normal = v2 normal
// nv2a-input: a_texcoord0 = v3 uv
// nv2a-uniform: u_vc = c96
// nv2a-const: c96 = fixed 0 0.5 256 1
// nv2a-const: c100..c103 = projection
// nv2a-const: c104 = direction
// nv2a-const: c105 = range 0.5 8
// nv2a-const: c106 = color
// nv2a-const: c110 = direction
// nv2a-const: c111 = color
// nv2a-const: c112 = direction
// nv2a-const: c113 = color
// nv2a-const: c114 = direction
// nv2a-const: c115 = color
// nv2a-const: c116 = direction
// nv2a-const: c117 = color

#include <bgfx_shader.sh>

uniform vec4 u_vc[22];          // c96 .. c117

void main()
{
    vec4 p = vec4(a_position, 1.0);
    gl_Position = vec4(dot(p, u_vc[4]), dot(p, u_vc[5]), dot(p, u_vc[6]), dot(p, u_vc[7]));

    int light = int(floor(a_indices.x * u_vc[0].z));        // 2 * light index
    float ndl = dot(a_normal, -u_vc[14 + light].xyz);
    float ndh = dot(a_normal, u_vc[8].xyz);
    float power = clamp(u_vc[9].w, -127.9961, 127.9961);
    float diffuse = max(ndl, 0.0);
    float specular = (ndl > 0.0 && ndh > 0.0) ? pow(ndh, power) : 0.0;
    vec4 colour = diffuse * u_vc[15 + light];
    colour = specular * u_vc[10] + colour;
    v_color0 = saturate(min(colour, u_vc[0].wwww));

    float flag = step(u_vc[0].y, a_texcoord0.x);            // sge: 1 when u >= 0.5
    v_texcoord0 = vec4(a_texcoord0, 0.0, 1.0) * flag;
    v_fog = dot(a_normal, a_normal) * (1.0 / u_vc[9].x);
}
