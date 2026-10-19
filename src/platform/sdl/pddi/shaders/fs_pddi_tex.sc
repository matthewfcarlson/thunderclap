$input v_color0, v_texcoord0

// The G1 stand-in for the simple shader's stage 0 (texture x vertex colour, D3DTOP_MODULATE) with the alpha test
// (ATST/ACMP/ACTH: discard below the reference; u_pddiAlpha.x = reference 0..1, .y = 1 when the test is on).
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_pddiAlpha;

void main()
{
    vec4 c = texture2D(s_pddiTex0, v_texcoord0) * v_color0;
    if (u_pddiAlpha.y > 0.5 && c.a < u_pddiAlpha.x)
        discard;
    gl_FragColor = c;
}
