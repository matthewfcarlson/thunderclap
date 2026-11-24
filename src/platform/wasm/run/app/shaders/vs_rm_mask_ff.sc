$input a_position, a_color0, a_texcoord0
$output v_pxbase, v_texcoord0

// Temporal upscaling's HUD mask (wperf2, taa.cpp): a fixed-function draw after the frame's first effect (the HUD, not
// jittered) drawn again into the mask: vs_vp_ff's transform and HUD edge shift, stage 0's coordinates (its texture
// transform; texture coordinate set 0) and the vertex colour.
#include <bgfx_shader.sh>

uniform vec4 u_vc[96];

void main()
{
    vec4 p = vec4(a_position, 1.0);
    vec4 view = vec4(dot(p, u_vc[0]), dot(p, u_vc[1]), dot(p, u_vc[2]), dot(p, u_vc[3]));
    gl_Position = vec4(dot(view, u_vc[4]), dot(view, u_vc[5]), dot(view, u_vc[6]), dot(view, u_vc[7]));
    if (u_vc[55].x != 0.0 && gl_Position.w > 0.0) {
        float xn = gl_Position.x / gl_Position.w / u_vc[55].y;
        gl_Position.x += sign(xn) * u_vc[55].x * smoothstep(0.05, 0.2, abs(xn)) * gl_Position.w;
    }
    vec4 c = vec4(a_texcoord0, 1.0, 0.0);
    if (u_vc[48].y > 0.5)
        c = vec4(dot(c, u_vc[32]), dot(c, u_vc[33]), dot(c, u_vc[34]), dot(c, u_vc[35]));
    v_texcoord0 = c;
    v_pxbase = a_color0.zyxw;
}
