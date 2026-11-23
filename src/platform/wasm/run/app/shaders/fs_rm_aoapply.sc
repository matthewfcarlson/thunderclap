$input v_texcoord0

// Ambient occlusion (wr3a): the half-size visibility blurred 4x4 with depth weights (edges stay sharp), multiplied
// into the scene (the blend: destination x source).
//   u_rmAo0, u_rmAo1 as fs_rm_ao.sc; u_rmPost0 xy: the half-size texel (uv), z: 2 shows the depth
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
SAMPLER2D(s_rmTex1, 1);         // the visibility (r) and view depth (g), half size
uniform vec4 u_rmAo1;
uniform vec4 u_rmPost0;

void main()
{
    vec2 uv = v_texcoord0.xy;
    float d = texture2DLod(s_rmTex0, uv, 0.0).x;
    if (u_rmPost0.z > 3.5) {                                // (development: HULK_AO_SHOW=4, the half-size output)
        vec4 r = texture2DLod(s_rmTex1, uv, 0.0);
        gl_FragColor = vec4(r.r, fract(r.g / 20.0), 0.0, 1.0);
        return;
    }
    if (u_rmPost0.z > 2.5) {                                // (development: HULK_AO_SHOW=3, the raw depth)
        gl_FragColor = vec4(saturate((1.0 - d) * 50.0), fract(d * 1000.0), d, 1.0);
        return;
    }
    if (d >= 0.99999) {
        gl_FragColor = vec4_splat(1.0);
        return;
    }
    float z = (u_rmAo1.y - d * u_rmAo1.w) / min(d * u_rmAo1.z - u_rmAo1.x, -1e-7);
    float sum = 0.0, wsum = 0.0;
    for (int j = -1; j <= 2; j++)
        for (int i = -1; i <= 2; i++) {
            vec4 s = texture2DLod(s_rmTex1, uv + (vec2(float(i), float(j)) - 0.5) * u_rmPost0.xy, 0.0);
            float w = exp(-abs(s.g - z) / max(z, 1e-3) * 60.0);
            sum += s.r * w;
            wsum += w;
        }
    float ao = wsum > 0.0 ? sum / wsum : 1.0;
    if (u_rmPost0.z > 1.5)                                  // (development: HULK_AO_SHOW=2, the view depth)
        ao = fract(z / 20.0);
    gl_FragColor = vec4(ao, ao, ao, 1.0);
}
