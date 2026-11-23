$input v_texcoord0

// HDR glow (wr3a): the scene's light above the threshold, averaged over 4 bilinear taps (a quarter-size target).
//   u_rmPost0  xy: the source's texel size, z: the threshold
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);
uniform vec4 u_rmPost0;

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec2 d = u_rmPost0.xy;
    vec3 c = texture2D(s_rmTex0, uv + vec2(-d.x, -d.y)).rgb + texture2D(s_rmTex0, uv + vec2(d.x, -d.y)).rgb +
             texture2D(s_rmTex0, uv + vec2(-d.x, d.y)).rgb + texture2D(s_rmTex0, uv + vec2(d.x, d.y)).rgb;
    gl_FragColor = vec4(max(c * 0.25 - vec3_splat(u_rmPost0.z), vec3_splat(0.0)), 1.0);
}
