// Night lights (wlook2, docs/night.md; run/app/nightlights.cpp): the presented frame's city lights (lamps, signs, vehicle
// lights: the game's own glows) as a list in a 64 x 64 float texture with a per-screen-tile index (tiled forward
// lighting). Included by fs_px_stage.sh (the per-pixel lighting) and fs_rm_atmos.sc (the lamps' in-scattering).
//
// The texture: light i at texels 2i (camera-space position, radius) and 2i + 1 (colour x strength, kind: 0 a point
// light, 1 a lamp, which lights mostly downwards); tile t's light indices from texel u_rmCity[1].w + t x (per tile / 4),
// four a texel, -1 ending the list.
//   u_rmCity[0]  x the frame's lights (0: none for this draw), y the tile size (pixels), z tiles across, w unused
//   u_rmCity[1]  x the render target's height (pixels), y 1: gl_FragCoord's origin is the bottom left, z lights a tile
//                (a multiple of 4), w the first tile texel
//   u_rmCity[2]  xyz the world's up in camera space, w the night (0..1)

uniform vec4 u_rmCity[3];
SAMPLER2D(s_rmCity, 5);

#define CITY_TEX 64.0
#define CITY_MAX_TEXELS 4

vec4 cityTexel(float i)
{
    vec2 uv = (vec2(mod(i, CITY_TEX), floor(i / CITY_TEX)) + 0.5) / CITY_TEX;
    return texture2DLod(s_rmCity, uv, 0.0);
}

// the first index texel of the pixel's tile
float cityTile(vec2 fc)
{
    if (u_rmCity[1].y > 0.5)
        fc.y = u_rmCity[1].x - fc.y;
    vec2 t = floor(fc / u_rmCity[0].y);
    return u_rmCity[1].w + (t.y * u_rmCity[0].z + t.x) * (u_rmCity[1].z * 0.25);
}

// light i's irradiance at camera-space pos with normal n (its own falloff: smooth to zero at the radius, a little
// inverse-square shape near the light; lamps mostly downwards)
vec3 cityOne(float i, vec3 pos, vec3 n)
{
    vec4 lp = cityTexel(2.0 * i);
    vec4 lc = cityTexel(2.0 * i + 1.0);
    vec3 d = lp.xyz - pos;
    float d2 = dot(d, d);
    float r2 = lp.w * lp.w;
    if (d2 >= r2)
        return vec3(0.0, 0.0, 0.0);
    float x = 1.0 - d2 / r2;
    float att = x * x / (1.0 + d2 / (0.1 * r2));          // (inverse-square near the light, zero at the radius)
    vec3 l = d2 > 0.0 ? d * inversesqrt(d2) : vec3(0.0, 0.0, 0.0);
    float ndl = saturate(dot(n, l) * 0.85 + 0.15);
    if (lc.w > 0.5) {
        float down = dot(-l, -u_rmCity[2].xyz);          // (1: the point is straight below the lamp)
        att *= mix(0.15, 1.0, smoothstep(0.45, 0.9, down));
    }
    return lc.rgb * (att * ndl);
}

// the sum of the tile's lights at a camera-space point (fc: gl_FragCoord.xy)
vec3 cityLight(vec3 pos, vec3 n, vec2 fc)
{
    vec3 sum = vec3(0.0, 0.0, 0.0);
    if (u_rmCity[0].x < 0.5)
        return sum;
    float base = cityTile(fc);
    for (int j = 0; j < CITY_MAX_TEXELS; j++) {
        if (float(j) * 4.0 >= u_rmCity[1].z)
            break;
        vec4 idx = cityTexel(base + float(j));
        if (idx.x < 0.0) break;
        sum += cityOne(idx.x, pos, n);
        if (idx.y < 0.0) break;
        sum += cityOne(idx.y, pos, n);
        if (idx.z < 0.0) break;
        sum += cityOne(idx.z, pos, n);
        if (idx.w < 0.0) break;
        sum += cityOne(idx.w, pos, n);
    }
    return sum;
}

// light i's in-scattering along the view ray (unit direction v from the camera) to distance t: a point light in a
// uniform medium, closed form of the integral of 1 / d^2 along the ray, windowed by the light's radius
vec3 cityScatterOne(float i, vec3 v, float t)
{
    vec4 lp = cityTexel(2.0 * i);
    vec4 lc = cityTexel(2.0 * i + 1.0);
    float tc = dot(lp.xyz, v);
    float h2 = max(dot(lp.xyz, lp.xyz) - tc * tc, 0.0);
    float r2 = lp.w * lp.w;
    if (h2 >= r2)
        return vec3(0.0, 0.0, 0.0);
    float h = sqrt(h2 + 0.09);
    float s = (atan((t - tc) / h) + atan(tc / h)) / h;
    float w = 1.0 - h2 / r2;
    return lc.rgb * (s * w * w);
}

vec3 cityScatter(vec3 v, float t, vec2 fc)
{
    vec3 sum = vec3(0.0, 0.0, 0.0);
    if (u_rmCity[0].x < 0.5)
        return sum;
    float base = cityTile(fc);
    for (int j = 0; j < CITY_MAX_TEXELS; j++) {
        if (float(j) * 4.0 >= u_rmCity[1].z)
            break;
        vec4 idx = cityTexel(base + float(j));
        if (idx.x < 0.0) break;
        sum += cityScatterOne(idx.x, v, t);
        if (idx.y < 0.0) break;
        sum += cityScatterOne(idx.y, v, t);
        if (idx.z < 0.0) break;
        sum += cityScatterOne(idx.z, v, t);
        if (idx.w < 0.0) break;
        sum += cityScatterOne(idx.w, v, t);
    }
    return sum;
}
