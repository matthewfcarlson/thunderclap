$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// A shadow caster's depth (wr3a, docs/hdr-shadows.md): only the depth is written; a draw the game alpha-tests keeps
// its holes (stage 0's alpha against the reference, as the combiner's first stage usually takes it).
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_pddiFrag[16];

void main()
{
    if (u_pddiFrag[0].y >= 0.0) {
        vec2 uv0 = v_texcoord0.xy * u_pddiFrag[4].xy + u_pddiFrag[14].xy;
        float a = floor(saturate(texture2D(s_pddiTex0, uv0).a) * 255.0 + 0.5);
        if (a < u_pddiFrag[0].x || a <= 0.0)
            discard;
    }
    gl_FragColor = vec4_splat(0.0);
}
