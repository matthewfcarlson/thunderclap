$input v_texcoord0, v_texcoord1

// TAA's motion vectors (wperf1, taa.cpp): rg the screen motion since the last presented frame (uv units, top-left
// origin: current - last), b the view depth (the resolve keeps it only where the scene's depth agrees), a 1: written.
#include <bgfx_shader.sh>

void main()
{
    vec2 a = v_texcoord0.xy / v_texcoord0.w, b = v_texcoord1.xy / max(v_texcoord1.w, 1e-6);
    vec2 m = (a - b) * vec2(0.5, -0.5);
    gl_FragColor = vec4(m, v_texcoord0.w, v_texcoord1.w > 0.0 ? 1.0 : 0.0);
}
