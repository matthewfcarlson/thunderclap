$input a_position, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// The full-screen passes' vertices: x, y in the target's pixels (0..w, 0..h edge to edge, y down: what the game's
// XYZRHW quads at -0.5 .. w - 0.5 cover with Direct3D's pixel centres), the coordinates through.
// u_fxTarget: (2 / width, 2 / height, 0, 0) of the view's target.
#include <bgfx_shader.sh>

uniform vec4 u_fxTarget;

void main()
{
    gl_Position = vec4(a_position.x * u_fxTarget.x - 1.0, 1.0 - a_position.y * u_fxTarget.y, 0.0, 1.0);
    v_texcoord0 = a_texcoord0;
    v_texcoord1 = a_texcoord1;
    v_texcoord2 = a_texcoord2;
    v_texcoord3 = a_texcoord3;
}
