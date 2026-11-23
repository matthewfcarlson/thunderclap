$input v_texcoord0

// TAA's resolve back into the scene (wperf1): the history (s_rmTex0) with a light sharpen (a 5-tap unsharp mask held
// to the cross's own range, so it neither rings nor overshoots; HDR-safe). u_rmTaa3: zw the texel, y the strength.
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);
uniform vec4 u_rmTaa3;

void main()
{
    vec2 uv = v_texcoord0.xy;
    vec2 d = u_rmTaa3.zw;
    vec3 e = texture2DLod(s_rmTex0, uv, 0.0).rgb;
    vec3 b = texture2DLod(s_rmTex0, uv + vec2(0.0, -d.y), 0.0).rgb;
    vec3 l = texture2DLod(s_rmTex0, uv + vec2(-d.x, 0.0), 0.0).rgb;
    vec3 r = texture2DLod(s_rmTex0, uv + vec2(d.x, 0.0), 0.0).rgb;
    vec3 t = texture2DLod(s_rmTex0, uv + vec2(0.0, d.y), 0.0).rgb;
    vec3 mn = min(min(min(b, l), min(r, t)), e), mx = max(max(max(b, l), max(r, t)), e);
    vec3 s = e + u_rmTaa3.y * (4.0 * e - b - l - r - t) * 0.25;
    gl_FragColor = vec4(clamp(s, mn, mx), 1.0);
}
