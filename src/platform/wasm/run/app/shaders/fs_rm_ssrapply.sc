$input v_texcoord0

// Screen-space reflections (wssr1, docs/reflections.md): the composite. The traced reflection (fs_rm_ssr.sc, maybe at
// half size) is gathered over a disc that grows with the surface's roughness (depth-weighted, so edges stay sharp),
// weighted by Schlick's Fresnel and the surface's strength, and blended over the scene (source alpha): where no ray
// hit, the scene keeps the game's own surface (its REFL / sphere-map reflection).
//   u_rmSsr0, u_rmSsr1, u_rmSsr2.xy as fs_rm_ssr.sc
//   u_rmSsr3  x the strength of every reflection, y 1: textures have v = 0 at the bottom, zw the trace's texel (uv)
//   u_rmSsr4  x the gather's radius at roughness 1 (trace texels), y development view (HULK_SSR_SHOW), z F0 of wet
//             ground, w F0 of the metal-like (environment-mapped) class; glass and stone 0.04
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the G-buffer's depth
SAMPLER2D(s_rmTex1, 1);         // the G-buffer
SAMPLER2D(s_rmTex2, 2);         // the traced reflection (rgb x confidence, confidence)
uniform vec4 u_rmSsr0;
uniform vec4 u_rmSsr1;
uniform vec4 u_rmSsr2;
uniform vec4 u_rmSsr3;
uniform vec4 u_rmSsr4;

vec2 texUv(vec2 s) { return u_rmSsr3.y > 0.5 ? vec2(s.x, 1.0 - s.y) : s; }
float viewZ(float d) { return (u_rmSsr1.y - d * u_rmSsr1.w) / min(d * u_rmSsr1.z - u_rmSsr1.x, -1e-7); }
vec3 viewPos(vec2 s, float d)
{
    float z = viewZ(d);
    float w = u_rmSsr1.z * z + u_rmSsr1.w;
    vec2 ndc = vec2(s.x * 2.0 - 1.0, 1.0 - s.y * 2.0);
    return vec3((ndc.x * w - u_rmSsr0.z * z - u_rmSsr2.x) / u_rmSsr0.x,
                (ndc.y * w - u_rmSsr0.w * z - u_rmSsr2.y) / u_rmSsr0.y, z);
}
vec3 octDecode(vec2 o)
{
    vec3 n = vec3(o, 1.0 - abs(o.x) - abs(o.y));
    if (n.z < 0.0)
        n.xy = (1.0 - abs(n.yx)) * vec2(n.x >= 0.0 ? 1.0 : -1.0, n.y >= 0.0 ? 1.0 : -1.0);
    return normalize(n);
}

void main()
{
    vec2 tuv = v_texcoord0.xy;
    vec4 g = texture2DLod(s_rmTex1, tuv, 0.0);
    float d = texture2DLod(s_rmTex0, tuv, 0.0).x;
    float show = u_rmSsr4.y;
    if (show > 0.5 && show < 1.5) {                         // (development: HULK_SSR_SHOW=1, the G-buffer)
        vec3 n = octDecode(g.xy);
        vec3 k = vec3(floor(g.w) * 0.5, 1.0 - floor(g.w) * 0.5, n.y * 0.5 + 0.5);   // (class red/green, normal's y)
        gl_FragColor = vec4(g.z > 0.0 ? k * saturate(g.z) : vec3_splat(0.0), 1.0);
        return;
    }
    if (g.z <= 0.0 || d >= 0.99999) {
        if (show > 1.5)
            gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
        else
            discard;
        return;
    }
    vec2 s = texUv(tuv);
    vec3 p = viewPos(s, d);
    vec3 n = octDecode(g.xy);
    float cls = floor(g.w);
    float rough = (g.w - cls) * 2.0;
    // the gather: centre + 8 taps on a ring at the roughness's radius, weighted by depth likeness
    float radius = u_rmSsr4.x * rough;
    vec4 sum = texture2DLod(s_rmTex2, tuv, 0.0);
    float wsum = 1.0;
    if (radius > 0.3) {
        for (int i = 0; i < 8; i++) {
            float ang = float(i) * 0.785398 + 0.39;
            vec2 o = vec2(cos(ang), sin(ang)) * radius * u_rmSsr3.zw;
            float dz = viewZ(texture2DLod(s_rmTex0, tuv + o, 0.0).x);
            float w = exp(-abs(dz - p.z) / max(p.z, 1e-3) * 40.0);
            sum += texture2DLod(s_rmTex2, tuv + o, 0.0) * w;
            wsum += w;
        }
    }
    float conf = sum.a / wsum;
    vec3 refl = sum.a > 1e-4 ? sum.rgb / sum.a : vec3_splat(0.0);
    // Schlick's Fresnel (F0 by class: glass and stone 0.04, wet ground, environment-mapped objects); rough surfaces
    // lose some of the grazing peak
    float c = saturate(dot(-normalize(p), n));
    float f0 = cls > 1.5 ? u_rmSsr4.w : cls > 0.5 ? u_rmSsr4.z : 0.04;
    float fres = f0 + (1.0 - f0) * pow(1.0 - c, 5.0) * (1.0 - 0.6 * rough);
    float w = saturate(g.z * fres * conf * u_rmSsr3.x);
    if (show > 2.5) {                                       // (development: 3 the reflection alone, 2 its weight)
        gl_FragColor = vec4(refl * w, 1.0);
        return;
    }
    if (show > 1.5) {
        gl_FragColor = vec4(w, conf, g.z, 1.0);
        return;
    }
    gl_FragColor = vec4(refl, w);
}
