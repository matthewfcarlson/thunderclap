$input a_position, a_texcoord0
$output v_texcoord0

// The present pass (G4, bgfxDisplay::present) and the backend's other full-screen copies: the position is already in
// clip space, the coordinate goes through.
#include <bgfx_shader.sh>

void main()
{
    gl_Position = vec4(a_position, 1.0);
    v_texcoord0 = a_texcoord0;
}
