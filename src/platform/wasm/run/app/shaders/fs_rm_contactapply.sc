$input v_texcoord0

// Contact shadows and bounce light (wshadow1, run/app/contact.cpp): the half-size terms blurred 4x4 with depth weights
// (each half-size texel's depth read where fs_rm_contact.sc read it), multiplied into the scene by the blend
// (destination x src.rgb + destination x src.a = destination x visibility x (1 + bounce)).
//   u_rmCt1 as fs_rm_contact.sc; u_rmPost0 xy: the half-size texel (uv), z: development (1 the visibility, 2 the bounce)
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
SAMPLER2D(s_rmTex1, 1);         // the terms (rgb the bounce, a the visibility), half size
uniform vec4 u_rmCt1;
uniform vec4 u_rmPost0;

float viewZ(float d)
{
    return (u_rmCt1.y - d * u_rmCt1.w) / min(d * u_rmCt1.z - u_rmCt1.x, -1e-7);
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    float d = texture2DLod(s_rmTex0, uv, 0.0).x;
    vec4 r = vec4(0.0, 0.0, 0.0, 1.0);
    if (d < 0.99999) {
        float z = viewZ(d);
        vec2 hs = 1.0 / u_rmPost0.xy;
        vec2 base = floor(uv * hs - 0.5);
        vec4 sum = vec4_splat(0.0);
        float wsum = 0.0;
        for (int j = -1; j <= 2; j++)
            for (int i = -1; i <= 2; i++) {
                vec2 c = (base + vec2(float(i), float(j)) + 0.5) * u_rmPost0.xy;
                float sz = viewZ(texture2DLod(s_rmTex0, c, 0.0).x);
                float w = exp(-abs(sz - z) / max(z, 1e-3) * 60.0);
                sum += texture2DLod(s_rmTex1, c, 0.0) * w;
                wsum += w;
            }
        if (wsum > 1e-4)
            r = sum / wsum;
    }
    if (u_rmPost0.z > 1.5)                                  // (development: HULK_CONTACT_SHOW=2, the bounce)
        gl_FragColor = vec4(r.rgb * 2.0, 1.0);
    else if (u_rmPost0.z > 0.5)                             // (development: HULK_CONTACT_SHOW=1, the visibility)
        gl_FragColor = vec4(r.aaa, 1.0);
    else
        gl_FragColor = vec4(r.a * min(r.rgb, vec3_splat(1.0)), r.a);
}
