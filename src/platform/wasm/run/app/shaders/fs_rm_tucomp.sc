$input v_texcoord0

// MetalFX's output with the HUD put back (wperf2, upscale.cpp): where the HUD mask covers, the frame as it is (a
// Catmull-Rom of the unjittered samples), so the HUD stays as sharp and steady as the game drew it.
//   u_rmTu0  input width, height, 1 / width, 1 / height; u_rmTu2.w 1: textures have v = 0 at the bottom
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the frame (render size, point)
SAMPLER2D(s_rmTex3, 3);         // the HUD mask (linear)
SAMPLER2D(s_rmTex4, 4);         // MetalFX's output (present size)
uniform vec4 u_rmTu0;
uniform vec4 u_rmTu2;

vec2 texUv(vec2 s) { return u_rmTu2.w > 0.5 ? vec2(s.x, 1.0 - s.y) : s; }
vec3 frameCubic(vec2 s)
{
    vec2 pos = s * u_rmTu0.xy;
    vec2 c = floor(pos - 0.5) + 0.5;
    vec2 f = pos - c;
    vec2 w0 = f * (-0.5 + f * (1.0 - 0.5 * f));
    vec2 w1 = 1.0 + f * f * (-2.5 + 1.5 * f);
    vec2 w2 = f * (0.5 + f * (2.0 - 1.5 * f));
    vec2 w3 = f * f * (-0.5 + 0.5 * f);
    vec2 w12 = w1 + w2;
    vec2 t12 = (c + w2 / w12) * u_rmTu0.zw;
    vec2 t0 = (c - 1.0) * u_rmTu0.zw, t3 = (c + 2.0) * u_rmTu0.zw;
    vec3 r = texture2DLod(s_rmTex0, texUv(vec2(t12.x, t0.y)), 0.0).rgb * (w12.x * w0.y)
           + texture2DLod(s_rmTex0, texUv(vec2(t0.x, t12.y)), 0.0).rgb * (w0.x * w12.y)
           + texture2DLod(s_rmTex0, texUv(t12), 0.0).rgb * (w12.x * w12.y)
           + texture2DLod(s_rmTex0, texUv(vec2(t3.x, t12.y)), 0.0).rgb * (w3.x * w12.y)
           + texture2DLod(s_rmTex0, texUv(vec2(t12.x, t3.y)), 0.0).rgb * (w12.x * w3.y);
    float wsum = w12.x * w0.y + w0.x * w12.y + w12.x * w12.y + w3.x * w12.y + w12.x * w3.y;
    return max(r / wsum, vec3_splat(0.0));
}

void main()
{
    vec3 c = texture2DLod(s_rmTex4, v_texcoord0.xy, 0.0).rgb;
    float mk = texture2DLod(s_rmTex3, v_texcoord0.xy, 0.0).x;
    if (mk > 0.0)
        c = mix(c, frameCubic(texUv(v_texcoord0.xy)), mk);
    gl_FragColor = vec4(c, 1.0);
}
