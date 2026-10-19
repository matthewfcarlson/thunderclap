$input v_color0, v_texcoord0

// The G0 stand-in for the texture-stage combiner: the vertex colour only (stage 0 "select diffuse").
#include <bgfx_shader.sh>

void main()
{
    gl_FragColor = v_color0;
}
