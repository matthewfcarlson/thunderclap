$input v_texcoord0

// Light shafts (wrays1, docs/light-shafts.md; run/app/rays.cpp), at half size: the sun's (or the moon's) light
// scattered towards the camera by the air, marched along each view ray through the sun shadows' atlas (shadows.cpp: both
// rows, the characters' and objects' and the world's), so the air in a building's or a canyon wall's shadow stays dark
// and the light between them reads as shafts, whether the sun is on screen or not; and at night each street lamp's cone
// of light in the mist below its head (the Night Lights' list, rm_city.sh). No temporal accumulation: the march starts
// at a 4x4 Bayer offset per pixel, which the apply's 4x4 blur (fs_rm_raysapply.sc) takes once each (as the ambient
// occlusion does, wlook3), so the result is steady from frame to frame with or without TAA.
// Output: rgb the in-scattered light (the scene's units), a how much the shadowed air dims what is behind it (0..1).
//
//   u_rmRays[0]  the projection: x c4.x, y c5.y, z c4.z, w c5.z (as fs_rm_ao.sc)
//   u_rmRays[1]  x c6.z, y c6.w, z c7.z, w c7.w
//   u_rmRays[2]  x c4.w, y c5.w, z the shadows' reach (view depth), w the march's steps (0: no sun part)
//   u_rmRays[3]  xyz the world's up in camera space, w the air's falloff with height (1 / units)
//   u_rmRays[4]  rgb the sun's light x the strength, w the air's density at the camera's height (1 / units)
//   u_rmRays[5]  xyz towards the sun (camera space), w the phase function's g (forward scattering)
//   u_rmRays[6]  x the shadowed air's dimming, y the lamps' cones (strength), z the full size / this size, w the view
//                depth beyond which a pixel counts as sky
//   u_rmRays[7]  x the phase's cap, y the distance before which the air is clear, z the lamps' cone cosine, w the share
//                of the air's light taken as already there (the atmosphere's haze): only the difference of a ray from
//                that share shows, light where it is lit more, dimming where it is shadowed more
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
SAMPLER2DSHADOW(s_rmShadow, 4); // the sun shadows' atlas
uniform vec4 u_rmShadow[12];
uniform vec4 u_rmRays[8];
#include "rm_city.sh"

float viewZ(float d)
{
    return (u_rmRays[1].y - d * u_rmRays[1].w) / min(d * u_rmRays[1].z - u_rmRays[1].x, -1e-7);
}
vec3 viewPos(vec2 uv, float d)
{
    float z = viewZ(d);
    float w = u_rmRays[1].z * z + u_rmRays[1].w;
    vec2 ndc = vec2(uv.x * 2.0 - 1.0, 1.0 - uv.y * 2.0);
    float x = (ndc.x * w - u_rmRays[0].z * z - u_rmRays[2].x) / u_rmRays[0].x;
    float y = (ndc.y * w - u_rmRays[0].w * z - u_rmRays[2].y) / u_rmRays[0].y;
    return vec3(x, y, z);
}

// the sun's visibility at a camera-space point of the air (1: lit): the cascade by view depth (fs_px_stage.sh
// pxShadow, without a surface's normal offset), the objects' row and the world's
float raysVis(vec3 pos)
{
    if (pos.z > u_rmShadow[11].x)
        return 1.0;
    bool second = u_rmShadow[8].x > 1.5 && pos.z > u_rmShadow[8].y;
    vec4 p = vec4(pos, 1.0);
    vec3 q = second ? vec3(dot(p, u_rmShadow[4]), dot(p, u_rmShadow[5]), dot(p, u_rmShadow[6]))
                    : vec3(dot(p, u_rmShadow[0]), dot(p, u_rmShadow[1]), dot(p, u_rmShadow[2]));
    if (q.z >= 1.0 || q.z <= 0.0)
        return 1.0;
    q.z -= 2.0 * (second ? u_rmShadow[7].z : u_rmShadow[3].z);
    float vis = shadow2D(s_rmShadow, q);
    vis = min(vis, shadow2D(s_rmShadow, vec3(q.x, q.y + u_rmShadow[10].x, q.z)));
    float fade = saturate((pos.z - u_rmShadow[11].x * 0.8) / (u_rmShadow[11].x * 0.2));
    return mix(vis, 1.0, fade);
}

// a 4x4 Bayer matrix (0..15)
float raysB2(vec2 q)
{
    return mod(2.0 * q.x + 3.0 * q.y, 4.0);
}
float raysBayer(vec2 fc)
{
    vec2 p = mod(floor(fc), 4.0);
    return 4.0 * raysB2(mod(p, 2.0)) + raysB2(floor(p * 0.5));
}

// light i's cone in the mist when it is a street lamp (kind 1: its light mostly downwards): the ray's nearest approach
// to the cone's axis below the lamp's head, a gaussian across the cone widening downwards and fading to its end, for as
// far as the ray stays in it (the form of rm_city.sh's headlight beams, pointed down); nothing for other kinds
vec3 raysCone(float i, vec3 v, float t)
{
    vec4 lc = cityTexel(3.0 * i + 1.0);
    if (lc.w < 0.5 || lc.w > 1.5)
        return vec3(0.0, 0.0, 0.0);
    vec4 lp = cityTexel(3.0 * i);
    vec3 ax = -u_rmCity[2].xyz;                             // (down)
    float b = dot(v, ax);
    float dd = dot(v, -lp.xyz), e = dot(ax, -lp.xyz);
    float den = max(1.0 - b * b, 1e-3);
    float len = 0.75 * lp.w;
    float u = clamp((e - b * dd) / den, 0.0, len);
    float sr = clamp(b * u - dd, 0.0, t);                   // (the ray's point nearest that axis point, before the surface)
    u = clamp(dot(v * sr - lp.xyz, ax), 0.0, len);
    vec3 q = v * sr - (lp.xyz + ax * u);
    float cs = u_rmRays[7].z;
    float tanc = sqrt(max(1.0 - cs * cs, 0.0)) / max(cs, 0.1);
    float wb = 0.25 + u * tanc * 0.55;
    float fall = 1.0 - u / len;
    float through = min(2.0 * wb * inversesqrt(den), 3.0 * wb + 2.0);
    return lc.rgb * (exp(-dot(q, q) / (wb * wb)) * fall * through / (wb * wb + 1.0));
}

vec3 raysCones(vec3 v, float t, vec2 fc)
{
    vec3 sum = vec3(0.0, 0.0, 0.0);
    if (u_rmCity[0].x < 0.5 || u_rmRays[6].y <= 0.0)
        return sum;
    float base = cityTile(fc);
    for (int j = 0; j < CITY_MAX_TEXELS; j++) {
        if (float(j) * 4.0 >= u_rmCity[1].z)
            break;
        vec4 idx = cityTexel(base + float(j));
        if (idx.x < 0.0) break;
        sum += raysCone(idx.x, v, t);
        if (idx.y < 0.0) break;
        sum += raysCone(idx.y, v, t);
        if (idx.z < 0.0) break;
        sum += raysCone(idx.z, v, t);
        if (idx.w < 0.0) break;
        sum += raysCone(idx.w, v, t);
    }
    return sum * (u_rmRays[6].y * u_rmCity[2].w);
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    float d = texture2DLod(s_rmTex0, uv, 0.0).x;
    bool sky = d >= 0.99999 || viewZ(d) > u_rmRays[6].w;
    vec3 p = viewPos(uv, sky ? 0.5 : d);
    float len = length(p);
    vec3 v = len > 0.0 ? p / len : vec3(0.0, 0.0, 1.0);
    float tEnd = sky ? 1e5 : len;
    vec3 col = vec3(0.0, 0.0, 0.0);
    float dark = 0.0;
    float n = u_rmRays[2].w;
    if (n > 0.5) {
        // the march: to the surface or the shadows' reach, steps closer together near the camera (t ~ s^2)
        float tMax = min(tEnd, u_rmRays[2].z / max(v.z, 0.05));
        float jit = (raysBayer(gl_FragCoord.xy) + 0.5) / 16.0;
        float climb = dot(v, u_rmRays[3].xyz);
        float lit = 0.0, shade = 0.0;
        for (int i = 0; i < 32; i++) {
            if (float(i) >= n)
                break;
            float s = (float(i) + jit) / n;
            float t = tMax * s * s;
            float dt = tMax * 2.0 * s / n;
            float h = clamp(t * climb, -40.0, 400.0);       // (the height above the camera)
            float rho = exp(-u_rmRays[3].w * h) * saturate(t / max(u_rmRays[7].y, 1e-3)) * dt;
            float vis = raysVis(v * t);
            lit += rho * vis;
            shade += rho * (1.0 - vis);
        }
        float g = u_rmRays[5].w;
        float mu = dot(v, u_rmRays[5].xyz);
        float hg = (1.0 - g * g) / pow(max(1.0 + g * g - 2.0 * g * mu, 1e-4), 1.5);
        float hg0 = (1.0 - g * g) / pow(1.0 + g * g, 1.5);
        float ph = min(0.4 + 0.6 * hg / hg0, u_rmRays[7].x);
        float rho0 = u_rmRays[4].w;
        float base = u_rmRays[7].w * (lit + shade);
        col = u_rmRays[4].rgb * (ph * max(lit - base, 0.0) * rho0);
        dark = min(u_rmRays[6].x * max(base - lit, 0.0) * rho0 * min(ph, 2.0), 0.3);
    }
    col += raysCones(v, tEnd, gl_FragCoord.xy * u_rmRays[6].z);
    gl_FragColor = vec4(col, dark);
}
