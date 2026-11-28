$input v_texcoord0

// Light shafts (wrays1, docs/light-shafts.md; run/app/rays.cpp): the half-size march (fs_rm_rays.sc) blurred 4x4 with
// depth weights (edges stay sharp; the 4x4 takes each of the march's 16 Bayer offsets once, so its noise cancels) and
// added over the scene, the shadowed air dimming what is behind it: rgb + scene x a (blend one / src-alpha).
//   u_rmRays[1] as fs_rm_rays.sc; u_rmPost0 xy the half-size texel (uv), zw the half size (texels);
//   u_rmPost1 x 1 shows the shafts alone (development), y the view depth beyond which a pixel counts as sky
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
SAMPLER2D(s_rmTex1, 1);         // the march: rgb light, a dimming (half size)
uniform vec4 u_rmRays[8];
uniform vec4 u_rmPost0;
uniform vec4 u_rmPost1;

float viewZ(float d)
{
    float z = (u_rmRays[1].y - d * u_rmRays[1].w) / min(d * u_rmRays[1].z - u_rmRays[1].x, -1e-7);
    return d >= 0.99999 ? 1e4 : min(z, u_rmPost1.y * 2.0);
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    float z = viewZ(texture2DLod(s_rmTex0, uv, 0.0).x);
    // the 4x4 half-size texels around this pixel, by their centres (the depth the march read there)
    vec2 base = floor(uv * u_rmPost0.zw - 0.5);
    vec4 sum = vec4(0.0, 0.0, 0.0, 0.0);
    float wsum = 0.0;
    for (int j = -1; j <= 2; j++)
        for (int i = -1; i <= 2; i++) {
            vec2 c = (base + vec2(float(i), float(j)) + 0.5) * u_rmPost0.xy;
            float zs = viewZ(texture2DLod(s_rmTex0, c, 0.0).x);
            float w = exp(-abs(zs - z) / max(z, 1e-3) * 30.0) + 1e-4;
            sum += texture2DLod(s_rmTex1, c, 0.0) * w;
            wsum += w;
        }
    vec4 r = sum / wsum;
    if (u_rmPost1.x > 0.5) {
        gl_FragColor = vec4(r.rgb * 4.0 + vec3(r.a, 0.0, 0.0), 0.0);
        return;
    }
    gl_FragColor = vec4(r.rgb, 1.0 - r.a);
}
