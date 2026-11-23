$input a_position, a_texcoord0
$output v_texcoord0

// The runner's full-screen passes (wr3a, docs/hdr-shadows.md): a quad in clip space, uv with the top-left origin.
#include <bgfx_shader.sh>

void main()
{
    gl_Position = vec4(a_position.xy, 0.0, 1.0);
    v_texcoord0 = vec4(a_texcoord0, 0.0, 1.0);
}
