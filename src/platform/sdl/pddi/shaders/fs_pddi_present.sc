$input v_texcoord0

// The present pass: the scene target as it is (point sampled, 1:1 when the window has the target's size).
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiPresent, 0);

void main()
{
    gl_FragColor = texture2D(s_pddiPresent, v_texcoord0);
}
