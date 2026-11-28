$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Water (wwater1, run/app/water.cpp, docs/water.md): the game's water surfaces (the sea around the city, the outskirts'
// river, the dam's lake: "simple" shader draws, texture x vertex colour, one stage) drawn level and moving:
//   - ripples: a sum of travelling waves in world space (rm_water.sh), faded out where a pixel is too coarse for them;
//     they bend the game's texture, the refraction, the reflection (the SSR G-buffer draws the same normal) and the glint;
//   - refraction: the scene behind the water (a copy taken before the frame's first water draw) through the ripples,
//     blended under the game's own colour (texture x vertex colour) at the game's own opacity, which fades out where
//     the water is shallow (a linear-depth copy): the shore and a river's edge show their bed; the game's mirrored
//     night lights under the sea show through it as before, now bent by the waves;
//   - Fresnel: Schlick (F0 0.02) towards a sky colour (the fog's, the horizon) where no screen-space reflection lands (the
//     reflection pass blends its hits over this by the same Fresnel);
//   - the key light's glint (the sun's by day, the moon's at night, when the shadow pass knows it) and the waves'
//     shading across it;
//   - the shore: foam where the water is shallow (a moving pattern) and a soft edge where it meets the ground.
// A face that is not level, or a draw without the copies (opaque water, drawn among the rooms), keeps what it can: the
// faithful texture x colour on non-level faces; ripples, Fresnel, reflection and glint without depth on opaque water.
// The game's alpha blend stays set; with the copies the program writes alpha 1 (it has composited the scene behind
// itself), else the game's alpha.
//
// Uniforms (rm_water.sh's u_rmWater, and):
//   u_rmWaterK[0]  xy 1 / the scene target's size (pixels), z the refraction's strength (uv per unit of slope), w 1: the
//                  copies are valid
//   u_rmWaterK[1]  rgb the sky colour the fallback reflection takes, w its strength
//   u_rmWaterK[2]  xyz towards the key light (the sun, or the moon at night; camera space), w the glint's strength
//   u_rmWaterK[3]  x the foam's strength, y the shore's width (units), z the depth (units) over which the water goes
//                  from clear to the game's own opacity, w the soft edge's width (units)
//   u_rmWaterK[4]  x a development view (HULK_WATER_SHOW: 1 the normal, 2 the depth below the surface, 3 Fresnel,
//                  4 the scene behind), y the waves' shading by the key light (per unit of slope)
#include <bgfx_shader.sh>
#include "rm_water.sh"

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_pddiFrag[16];
uniform vec4 u_rmWaterK[5];
SAMPLER2D(s_rmWaterScene, 4);
SAMPLER2D(s_rmWaterDepth, 5);

float wLum(vec3 c) { return dot(c, vec3(0.3, 0.59, 0.11)); }

vec3 wFog(vec3 c, float fogz)
{
    if (u_pddiFrag[1].w > 0.5) {
        float range = u_pddiFrag[2].y - u_pddiFrag[2].x;
        float k = range != 0.0 ? clamp((u_pddiFrag[2].y - fogz) / range, 0.0, 1.0) : 1.0;
        c = mix(u_pddiFrag[1].xyz, c, k);
    }
    return c;
}

bool wAlphaTest(float a)
{
    float f = u_pddiFrag[0].y;
    if (f < 0.0) return true;
    float r = u_pddiFrag[0].x;
    a = floor(clamp(a, 0.0, 1.0) * 255.0 + 0.5);
    if (f < 0.5) return false;
    if (f < 1.5) return true;
    if (f < 2.5) return a < r;
    if (f < 3.5) return a <= r;
    if (f < 4.5) return a > r;
    if (f < 5.5) return a >= r;
    if (f < 6.5) return a == r;
    return a != r;
}

// the foam's pattern: two drifting interference patterns, thresholded
float wFoamPattern(vec2 p, float t)
{
    float a = sin(p.x * 2.3 + sin(p.y * 1.7 + t * 0.7) * 1.6 + t * 0.4);
    float b = sin(p.y * 2.9 - sin(p.x * 1.3 - t * 0.5) * 1.4 - t * 0.3);
    float c = sin((p.x + p.y) * 4.1 + t * 0.9);
    return 0.5 + 0.25 * (a * b) + 0.25 * c;
}

void main()
{
    vec2 uv0 = v_texcoord0.xy * u_pddiFrag[4].xy + u_pddiFrag[14].xy;
    vec4 t0 = texture2D(s_pddiTex0, uv0);
    vec4 faithful = t0 * v_pxbase;
    if (!wAlphaTest(faithful.a))
        discard;
    vec3 pos = v_pxpos;
    if (!waterLevel(pos)) {
        gl_FragColor = vec4(wFog(faithful.rgb, v_fog), faithful.a);
        return;
    }
    vec3 world;
    vec2 slope;
    vec3 n = waterNormal(pos, world, slope);
    vec3 e = normalize(pos);                               // (camera to the point)
    float cosv = clamp(dot(-e, n), 0.0, 1.0);
    float fres = 0.02 + 0.98 * pow(1.0 - cosv, 5.0);

    // the game's colour through the ripples (its texture bent a little): the water's body
    vec3 body = texture2D(s_pddiTex0, uv0 + slope * 0.04).rgb * v_pxbase.rgb;
    float gameA = clamp(faithful.a, 0.0, 1.0);

    // the surface: the game's colour, the sky's at the horizon (the fog's) by Fresnel where no screen-space reflection
    // lands, the sun's glint, foam at the shore; then the draw's fog (only on the surface: the scene behind it is fogged
    // already, and fogging it again sank the bridge towers and the moon's glint into the fog)
    // the waves shade the game's colour as the key light (sun or moon) falls across them, so they read at night too
    vec3 key = u_rmWaterK[2].xyz;
    vec3 keyM = vec3(dot(key, u_rmWater[0].xyz), dot(key, u_rmWater[1].xyz), dot(key, u_rmWater[2].xyz));
    vec2 kxz = dot(keyM.xz, keyM.xz) > 1e-6 ? normalize(keyM.xz) : vec2(0.6, 0.8);
    float shade = clamp(1.0 - u_rmWaterK[4].y * dot(slope, kxz), 0.55, 1.45);
    vec3 sky = u_rmWaterK[1].rgb;
    vec3 c = mix(body * shade, sky, fres * u_rmWaterK[1].w);
    if (u_rmWaterK[2].w > 0.0) {
        vec3 r = reflect(e, n);
        float g = pow(clamp(dot(r, key), 0.0, 1.0), 300.0);
        c += vec3(1.0, 0.95, 0.85) * (g * u_rmWaterK[2].w);
    }

    // what is behind the water (copies of the scene so far: refraction, depth)
    vec2 suv = gl_FragCoord.xy * u_rmWaterK[0].xy;
    bool copies = u_rmWaterK[0].w > 0.5;
    float thick = 1e4;
    vec3 behind = c;
    float a = gameA;
    vec3 seen = c;
    if (copies) {
        float z0 = texture2DLod(s_rmWaterDepth, suv, 0.0).x;
        thick = max(z0 - pos.z, 0.0);
        behind = texture2DLod(s_rmWaterScene, suv, 0.0).rgb;
        // the refraction's offset: the ripples' slope, less with distance; never onto something in front of the water
        vec2 off = slope * u_rmWaterK[0].z / (1.0 + pos.z * 0.01);
        vec2 ruv = suv + off;
        float z1 = texture2DLod(s_rmWaterDepth, ruv, 0.0).x;
        if (z1 < pos.z)
            ruv = suv, z1 = z0;
        float rthick = max(z1 - pos.z, 0.0);
        seen = texture2DLod(s_rmWaterScene, ruv, 0.0).rgb;
        // the game's own transparency (what it draws under the sea shows through it: the mirrored towers, the moon's
        // glint), clearer where the water is shallow (the shore, the bed under a river's edge)
        a *= smoothstep(0.0, u_rmWaterK[3].z, rthick);
        // the shore: foam in shallow water, in the light the water's vertex colour carries (dark at night)
        if (u_rmWaterK[3].x > 0.0) {
            float shore = 1.0 - smoothstep(0.0, u_rmWaterK[3].y, thick);
            float pat = wFoamPattern(world.xz * 1.6, u_rmWater[6].x);
            float foam = shore * smoothstep(0.55 - 0.45 * shore, 0.85 - 0.3 * shore, pat) + 0.6 * shore * shore * shore;
            float light = clamp(wLum(v_pxbase.rgb) * 1.3 + 0.1, 0.12, 1.0);
            foam = clamp(foam * u_rmWaterK[3].x, 0.0, 1.0);
            c = mix(c, vec3(0.86, 0.9, 0.92) * light, foam);
            a = max(a, foam);
        }
    }
    if (u_rmWaterK[4].x > 0.5) {   // (development: HULK_WATER_SHOW=1 normals, 2 depth, 3 Fresnel, 4 the scene behind)
        float k = u_rmWaterK[4].x;
        gl_FragColor = vec4(k < 1.5 ? n * 0.5 + 0.5 : k < 2.5 ? vec3_splat(clamp(thick / 4.0, 0.0, 1.0))
                            : k < 3.5 ? vec3_splat(fres) : (copies ? behind : vec3(1.0, 0.0, 1.0)), 1.0);
        return;
    }
    c = wFog(c, v_fog);
    if (!copies) {
        gl_FragColor = vec4(c, gameA);
        return;
    }
    // the game's blend done here, over the bent scene; then the soft edge into the ground the water meets
    c = mix(seen, c, a);
    c = mix(behind, c, smoothstep(0.0, u_rmWaterK[3].w, thick));
    gl_FragColor = vec4(c, 1.0);
}
