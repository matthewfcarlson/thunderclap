$input a_position, a_color0, a_texcoord0
$output v_color0, v_texcoord0

// The G0 stand-in for the fixed-function vertex path: transform, pass the vertex colour and uv0 through.
// a_color0 holds a D3DCOLOR as it lies in memory (B, G, R, A), hence the swizzle.
#include <bgfx_shader.sh>

void main()
{
    gl_Position = mul(u_modelViewProj, vec4(a_position, 1.0));
    v_color0 = a_color0.zyxw;
    v_texcoord0 = a_texcoord0;
}
