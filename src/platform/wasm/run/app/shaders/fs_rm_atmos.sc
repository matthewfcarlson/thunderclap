$input v_texcoord0

// The atmosphere (wlook2, docs/night.md; run/app/atmosphere.cpp): over the world's opaque draws, before its translucent
// ones, from the scene's depth: exponential height fog (dense near the streets, thin above the roofs) and a little
// aerial perspective, both on top of the game's own linear fog, in the location's fog colour (lifted towards the city's
// glow at night, towards the sun by day), plus the night lights' in-scattering: each lamp's glow in the mist along the
// view ray (rm_city.sh). Output (rgb in-scattered light, a transmittance), blended one / src-alpha over the scene.
//
//   u_rmAtm[0]  the projection: x c4.x, y c5.y, z c4.z, w c5.z (as fs_rm_ao.sc)
//   u_rmAtm[1]  x c6.z, y c6.w, z c7.z, w c7.w
//   u_rmAtm[2]  x c4.w, y c5.w, z the camera's height above the ground estimate, w the height fog's density at the ground
//   u_rmAtm[3]  xyz the world's up in camera space, w the height fog's falloff (1 / units)
//   u_rmAtm[4]  rgb the fog's colour, w the aerial perspective's density (1 / units)
//   u_rmAtm[5]  xyz towards the sun or moon (camera space), w its forward-scattering strength
//   u_rmAtm[6]  x the lamps' in-scattering strength, y the far distance (sky pixels), z the fog's fade-in distance, w the
//               view depth beyond which a pixel counts as sky
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
uniform vec4 u_rmAtm[7];
#include "rm_city.sh"

float viewZ(float d)
{
    return (u_rmAtm[1].y - d * u_rmAtm[1].w) / min(d * u_rmAtm[1].z - u_rmAtm[1].x, -1e-7);
}
vec3 viewPos(vec2 uv, float d)
{
    float z = viewZ(d);
    float w = u_rmAtm[1].z * z + u_rmAtm[1].w;
    vec2 ndc = vec2(uv.x * 2.0 - 1.0, 1.0 - uv.y * 2.0);
    float x = (ndc.x * w - u_rmAtm[0].z * z - u_rmAtm[2].x) / u_rmAtm[0].x;
    float y = (ndc.y * w - u_rmAtm[0].w * z - u_rmAtm[2].y) / u_rmAtm[0].y;
    return vec3(x, y, z);
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    float d = texture2DLod(s_rmTex0, uv, 0.0).x;
    // the sky: the far plane, or beyond the sky distance (the game's sky layers write depth hundreds of units out)
    bool sky = d >= 0.99999 || viewZ(d) > u_rmAtm[6].w;
    vec3 p = viewPos(uv, sky ? 0.5 : d);
    float len = length(p);
    vec3 v = len > 0.0 ? p / len : vec3(0.0, 0.0, 1.0);
    float t = sky ? u_rmAtm[6].y : len;
    vec3 fogCol = u_rmAtm[4].rgb;
    // the sun's / moon's forward scattering (a broad lobe towards it)
    float mu = dot(v, u_rmAtm[5].xyz);
    fogCol += fogCol * u_rmAtm[5].w * pow(max(mu, 0.0), 6.0);
    float trans = 1.0;
    vec3 inscatter = vec3(0.0, 0.0, 0.0);
    if (!sky) {
        // height fog: density a e^(-b y) above the ground estimate, integrated along the ray from the camera
        float a = u_rmAtm[2].w, b = u_rmAtm[3].w;
        float y0 = u_rmAtm[2].z;                                 // (the camera's height)
        float dy = dot(v, u_rmAtm[3].xyz);                       // (the ray's climb per unit)
        float k = b * dy * t;
        float od = abs(k) > 1e-3 ? a * exp(-b * y0) * (1.0 - exp(-k)) / (b * dy) : a * exp(-b * y0) * t;
        od += u_rmAtm[4].w * t;                                  // (aerial perspective)
        od *= saturate(t / max(u_rmAtm[6].z, 1e-3));             // (nothing in the first few units: the Hulk stays crisp)
        trans = exp(-max(od, 0.0));
        inscatter = fogCol * (1.0 - trans);
    }
    inscatter += cityScatter(v, t, gl_FragCoord.xy) * u_rmAtm[6].x;
    gl_FragColor = vec4(inscatter, trans);
}
