$input v_texcoord0

// A separable gaussian (wr3a): 9 taps along u_rmPost0.xy (one step in uv), sigma about 2 steps.
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);
uniform vec4 u_rmPost0;

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec2 d = u_rmPost0.xy;
    vec4 c = texture2D(s_rmTex0, uv) * 0.2042;
    c += (texture2D(s_rmTex0, uv + d) + texture2D(s_rmTex0, uv - d)) * 0.1802;
    c += (texture2D(s_rmTex0, uv + 2.0 * d) + texture2D(s_rmTex0, uv - 2.0 * d)) * 0.1238;
    c += (texture2D(s_rmTex0, uv + 3.0 * d) + texture2D(s_rmTex0, uv - 3.0 * d)) * 0.0663;
    c += (texture2D(s_rmTex0, uv + 4.0 * d) + texture2D(s_rmTex0, uv - 4.0 * d)) * 0.0276;
    gl_FragColor = c;
}
