$input v_texcoord0

// HDR (wr3a, docs/hdr-shadows.md): the half-float scene, plus the glow of its light above 1, into the displayable range.
// The curve leaves everything below the knee as it is (the game's picture) and rolls the rest off towards 1 by the
// brightest channel (the hue kept); light far above 1 also turns towards white, as film does.
//   u_rmPost0  x: the knee, y: the glow's strength, z: 1 when s_rmTex1 holds the glow
// wlook1: then the colour grade (fs_rm_grade.sh) when u_rmGrade[0].w is 1 (Grade: Natural / Cinematic)
#include <bgfx_shader.sh>
#include "fs_rm_grade.sh"

SAMPLER2D(s_rmTex0, 0);
SAMPLER2D(s_rmTex1, 1);
uniform vec4 u_rmPost0;

void main()
{
    vec4 c = texture2D(s_rmTex0, v_texcoord0.xy);
    vec3 x = max(c.rgb, vec3_splat(0.0));
    if (u_rmPost0.z > 0.5)
        x += texture2D(s_rmTex1, v_texcoord0.xy).rgb * u_rmPost0.y;
    float m = max(x.r, max(x.g, x.b));
    float k = u_rmPost0.x;
    if (m > k) {
        float s = 1.0 - k;
        float f = k + s * (1.0 - exp(-(m - k) / s));
        float w = saturate((m - 1.0) * 0.25) * 0.6;
        x = mix(x * (f / m), vec3_splat(f), w);
    }
    if (u_rmGrade[0].w > 0.5)
        x = gradeApply(x, v_texcoord0.xy);
    gl_FragColor = vec4(x, c.a);
}
