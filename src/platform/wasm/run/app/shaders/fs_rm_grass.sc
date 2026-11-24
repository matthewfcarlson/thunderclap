$input v_pxbase, v_pxspec, v_fog, v_pxpos, v_pxnormal

// Grass blades (wgrass1, run/app/grass.cpp): the ground's colour from the vertex shader, the sun's shadows as the
// baked ground takes them (fs_px_stage.sh pxShadow: the characters' and objects' row, darkened as the ground is) and
// the ground draw's fog (u_pddiFrag[1..2], the faithful formula); the night lights (wlook2, rm_city.sh) add to the
// light the surface takes, as on the baked ground (fs_px_stage.sh: before the textures modulate it).
#include <bgfx_shader.sh>
#include "rm_city.sh"

uniform vec4 u_pddiFrag[16];
uniform vec4 u_rmShadow[12];
SAMPLER2DSHADOW(s_rmShadow, 4);

float grassShadowTap(vec3 q)
{
    float t = u_rmShadow[10].w * 0.5;
    return 0.25 * (shadow2D(s_rmShadow, vec3(q.x - t, q.y - t, q.z)) + shadow2D(s_rmShadow, vec3(q.x + t, q.y - t, q.z)) +
                   shadow2D(s_rmShadow, vec3(q.x - t, q.y + t, q.z)) + shadow2D(s_rmShadow, vec3(q.x + t, q.y + t, q.z)));
}

// fs_px_stage.sh pxShadow (the sun's visibility at a camera-space point with normal n; 1: lit)
float grassShadow(vec3 pos, vec3 n)
{
    if (u_rmShadow[8].x < 0.5 || pos.z > u_rmShadow[11].x)
        return 1.0;
    vec4 p = vec4(pos + n * u_rmShadow[9].w * (1.0 + pos.z * 0.01), 1.0);
    bool second = u_rmShadow[8].x > 1.5 && pos.z > u_rmShadow[8].y;
    vec3 q = second ? vec3(dot(p, u_rmShadow[4]), dot(p, u_rmShadow[5]), dot(p, u_rmShadow[6]))
                    : vec3(dot(p, u_rmShadow[0]), dot(p, u_rmShadow[1]), dot(p, u_rmShadow[2]));
    if (q.z >= 1.0 || q.z <= 0.0)
        return 1.0;
    q.z -= u_rmShadow[10].z;
    float vis = grassShadowTap(q);
    float fade = saturate((pos.z - u_rmShadow[11].x * 0.85) / (u_rmShadow[11].x * 0.15));
    return mix(vis, 1.0, fade);
}

void main()
{
    vec3 c = v_pxbase.rgb;
    if (u_rmShadow[8].x > 0.5) {
        vec3 n = v_pxnormal.xyz;
        float facing = saturate(dot(n, u_rmShadow[9].xyz) * 4.0);
        float vis = grassShadow(v_pxpos, n);
        // wlook3: the blade's own sun (vs_rm_grass.sc: its facing, its translucency) where the sun reaches it
        float sun = vis * facing * u_rmShadow[8].z;
        c *= mix(1.0, 2.0 * v_pxspec.w, sun) + v_pxbase.w * sun;
        c *= 1.0 - u_rmShadow[8].z * (1.0 - vis) * facing;
    }
    if (u_rmCity[0].x > 0.5)
        c += v_pxspec.rgb * cityLight(v_pxpos, v_pxnormal.xyz, gl_FragCoord.xy);
    if (u_pddiFrag[1].w > 0.5) {
        float range = u_pddiFrag[2].y - u_pddiFrag[2].x;
        float k = range != 0.0 ? saturate((u_pddiFrag[2].y - v_fog) / range) : 1.0;
        c = mix(u_pddiFrag[1].xyz, c, k);
    }
    gl_FragColor = vec4(c, 1.0);
}
