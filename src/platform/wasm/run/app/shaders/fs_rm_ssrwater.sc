$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Water (wwater1, run/app/water.cpp, docs/water.md) in the reflection G-buffer (wssr1, fs_rm_ssrmask.sc's output): the
// water's depth and its rippled normal (rm_water.sh, the same waves fs_px_water.sc draws), smooth, at the water pass's
// strength (u_rmWater[6].w: the game's own moon glints and mirrored lights stay seen under the reflection), in
// Fresnel class 0 (F0 0.04: close to water's 0.02); faces that are not level only occlude.
#include <bgfx_shader.sh>
#include "rm_water.sh"

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_pddiFrag[16];

vec2 octEncode(vec3 n)
{
    n /= abs(n.x) + abs(n.y) + abs(n.z);
    vec2 o = n.xy;
    if (n.z < 0.0)
        o = (1.0 - abs(n.yx)) * vec2(n.x >= 0.0 ? 1.0 : -1.0, n.y >= 0.0 ? 1.0 : -1.0);
    return o;
}

void main()
{
    vec2 uv0 = v_texcoord0.xy * u_pddiFrag[4].xy + u_pddiFrag[14].xy;
    vec4 t = texture2D(s_pddiTex0, uv0);
    if (u_pddiFrag[0].y >= 0.0) {                   // (the draw's alpha test: its holes stay holes)
        float a = floor(saturate(t.a * v_pxbase.a) * 255.0 + 0.5);
        if (a < u_pddiFrag[0].x || a <= 0.0)
            discard;
    }
    vec3 pos = v_pxpos;
    if (!waterLevel(pos)) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }
    vec3 world;
    vec2 slope;
    vec3 n = waterNormal(pos, world, slope);
    gl_FragColor = vec4(octEncode(n), u_rmWater[6].w, 0.02 * 0.5);
}
