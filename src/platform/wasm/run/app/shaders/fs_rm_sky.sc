$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// The enhanced sky (wlook2, docs/night.md; run/app/atmosphere.cpp): the game's sky dome drawn as the game draws it
// (stage 0's texture modulated by the vertex colour, its linear fog: the combiner c4.0.2a4.0.2r1), then re-graded by the
// view direction in world space: a deeper zenith, a horizon glow (the city's lights from below at night, haze by day),
// stars and a moon where the dome is dark, and the dome's clouds lit from below by the city. The moon sits in the
// direction of the location's key light (the shadows' sun stand-in), so its light and the shadows agree.
//
// Uniforms: u_pddiFrag / s_pddiTex0 as the faithful draw has them, and
//   u_rmSky[0..2]  rows: camera space -> world (the dome's own modelview, inverted)
//   u_rmSky[3]     x the night (0..1), y a slow clock (seconds), z the enhancement's strength, w the stars' strength
//   u_rmSky[4]     xyz towards the moon / sun (world), w 1: known
//   u_rmSky[5]     rgb the city's glow colour (night), w the horizon glow's strength
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_pddiFrag[16];
uniform vec4 u_rmSky[6];

float skyHash(vec3 p)
{
    p = fract(p * vec3(0.1031, 0.1030, 0.0973));
    p += dot(p, p.yxz + 33.33);
    return fract((p.x + p.y) * p.z);
}

float skyLum(vec3 c) { return dot(c, vec3(0.299, 0.587, 0.114)); }

// stars: one candidate per cell of a direction grid, a few percent of cells lit, sizes and brightness varied
vec3 skyStars(vec3 d, float t)
{
    vec3 q = d * 140.0;
    vec3 cell = floor(q);
    vec3 f = q - cell;
    float h = skyHash(cell);
    if (h < 0.965)
        return vec3(0.0, 0.0, 0.0);
    vec3 o = vec3(skyHash(cell + 17.0), skyHash(cell + 31.0), skyHash(cell + 47.0)) * 0.6 + 0.2;
    float r2 = dot(f - o, f - o);
    float b = (h - 0.965) / 0.035;
    float core = exp(-r2 * 90.0) * (0.25 + 1.6 * b * b * b);
    float tw = 0.8 + 0.2 * sin(t * (1.0 + 3.0 * skyHash(cell + 5.0)) + h * 60.0);
    vec3 tint = mix(vec3(0.75, 0.85, 1.0), vec3(1.0, 0.9, 0.75), skyHash(cell + 71.0));
    return tint * core * tw;
}

void main()
{
    vec2 uv0 = v_texcoord0.xy * u_pddiFrag[4].xy + u_pddiFrag[14].xy;
    vec4 c = texture2DBias(s_pddiTex0, uv0, u_pddiFrag[7].w) * v_pxbase;
    if (u_pddiFrag[1].w > 0.5) {
        float range = u_pddiFrag[2].y - u_pddiFrag[2].x;
        float k = range != 0.0 ? saturate((u_pddiFrag[2].y - v_fog) / range) : 1.0;
        c.xyz = mix(u_pddiFrag[1].xyz, c.xyz, k);
    }
    c = saturate(c);
    vec3 base = c.rgb;
    float amt = u_rmSky[3].z;
    if (amt > 0.001) {
        vec3 dc = normalize(v_pxpos);
        vec3 d = normalize(vec3(dot(u_rmSky[0].xyz, dc), dot(u_rmSky[1].xyz, dc), dot(u_rmSky[2].xyz, dc)));
        float h = d.y;
        float up = saturate(h);
        float night = u_rmSky[3].x;
        float lum = skyLum(base);
        // the gradient: a deeper, bluer zenith
        vec3 zen = mix(vec3(0.88, 0.96, 1.1), vec3(0.6, 0.72, 1.05), night);
        base *= mix(vec3(1.0, 1.0, 1.0), zen, smoothstep(0.25, 0.9, up));
        // a narrow glow at the horizon (the city's lights at night, haze by day)
        float horizon = exp(-max(h, 0.0) * 20.0) * step(-0.25, h);
        vec3 glow = mix(u_pddiFrag[1].xyz * 0.5 + vec3(0.05, 0.05, 0.06), u_rmSky[5].rgb, night);
        base += glow * horizon * u_rmSky[5].w;
        // the clouds (the dome's brighter texels) lit from below by the city, low over the horizon
        float cloud = smoothstep(0.04, 0.3, lum);
        base += u_rmSky[5].rgb * cloud * (1.0 - smoothstep(0.0, 0.22, up)) * night * 0.3;
        // the moon (night) or the sun's glow (day) in the key light's direction
        float clear = 1.0 - smoothstep(0.07, 0.2, lum);          // (clouds hide what is behind them)
        if (u_rmSky[4].w > 0.5 && u_rmSky[4].y > -0.05) {
            float m = max(dot(d, normalize(u_rmSky[4].xyz)), 0.0);
            if (night > 0.5) {
                float disc = smoothstep(0.99965, 0.99985, m);
                float crater = 0.85 + 0.15 * skyHash(floor(d * 900.0));
                base += vec3(1.0, 0.98, 0.92) * disc * crater * 2.2 * mix(0.25, 1.0, clear);
                base += vec3(0.55, 0.62, 0.8) * (pow(m, 600.0) * 0.35 + pow(m, 40.0) * 0.05) * (0.5 + cloud);
            } else {
                base += vec3(1.0, 0.9, 0.7) * (pow(m, 900.0) * 3.0 + pow(m, 60.0) * 0.18 + pow(m, 8.0) * 0.06);
            }
        }
        // stars where the sky is dark and clear, fading into the city's glow at the horizon
        float starMask = night * u_rmSky[3].w * clear * smoothstep(0.03, 0.3, h);
        if (starMask > 0.001)
            base += skyStars(d, u_rmSky[3].y) * starMask;
        c.rgb = mix(c.rgb, base, amt);
    }
    gl_FragColor = vec4(max(c.rgb, vec3(0.0, 0.0, 0.0)), c.a);
}
