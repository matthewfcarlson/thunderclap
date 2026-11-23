$input v_texcoord0

// Screen-space reflections (wssr1, docs/reflections.md): the ray march. For each reflective pixel of the G-buffer
// (fs_rm_ssrmask.sc) the view ray is mirrored about its normal and marched across the screen against the G-buffer's
// depth (perspective-correct: 1/w and z/w step linearly in screen space), then refined by bisection; a hit takes the
// scene's colour there (the frame so far: the world, its glows and effects). Output: rgb the colour x the confidence,
// a the confidence (0: no hit; the composite keeps the game's own surface, its REFL / sphere map, there).
//   u_rmSsr0  the projection: x c4.x, y c5.y, z c4.z, w c5.z
//   u_rmSsr1  x c6.z, y c6.w, z c7.z, w c7.w (D3D depth: d = (c6.z z + c6.w) / (c7.z z + c7.w))
//   u_rmSsr2  x c4.w, y c5.w, z the longest ray (view units), w the steps
//   u_rmSsr3  x the thickness (a fraction of the depth), y 1: textures have v = 0 at the bottom, zw the G-buffer texel
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the G-buffer's depth
SAMPLER2D(s_rmTex1, 1);         // the G-buffer: normal, strength, roughness
SAMPLER2D(s_rmTex2, 2);         // the scene's colour (a copy)
uniform vec4 u_rmSsr0;
uniform vec4 u_rmSsr1;
uniform vec4 u_rmSsr2;
uniform vec4 u_rmSsr3;

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
// camera space -> (screen u, screen v, 1/w)
vec3 project(vec3 p)
{
    float w = u_rmSsr1.z * p.z + u_rmSsr1.w;
    float k = 1.0 / w;
    vec2 ndc = vec2(u_rmSsr0.x * p.x + u_rmSsr0.z * p.z + u_rmSsr2.x, u_rmSsr0.y * p.y + u_rmSsr0.w * p.z + u_rmSsr2.y) * k;
    return vec3(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5, k);
}
vec3 octDecode(vec2 o)
{
    vec3 n = vec3(o, 1.0 - abs(o.x) - abs(o.y));
    if (n.z < 0.0)
        n.xy = (1.0 - abs(n.yx)) * vec2(n.x >= 0.0 ? 1.0 : -1.0, n.y >= 0.0 ? 1.0 : -1.0);
    return normalize(n);
}
float sceneZ(vec2 s) { return viewZ(texture2DLod(s_rmTex0, texUv(s), 0.0).x); }

void main()
{
    vec2 tuv = v_texcoord0.xy;
    vec2 s = texUv(tuv);                                   // (the screen's uv, top-left origin)
    vec4 g = texture2DLod(s_rmTex1, tuv, 0.0);
    float d = texture2DLod(s_rmTex0, tuv, 0.0).x;
    if (g.z <= 0.0 || d >= 0.99999) {
        gl_FragColor = vec4_splat(0.0);
        return;
    }
    vec3 p = viewPos(s, d);
    vec3 n = octDecode(g.xy);
    vec3 v = normalize(p);
    vec3 r = reflect(v, n);
    // the ray's end: its longest length, kept in front of the camera
    float len = u_rmSsr2.z;
    if (r.z < 0.0)
        len = min(len, (p.z - 0.3) / -r.z);
    vec3 p0 = p + n * (0.02 + 0.002 * p.z);                // (off the surface: no self hit)
    vec3 a = project(p0), b = project(p0 + r * len);
    float qa = p0.z * a.z, qb = (p0.z + r.z * len) * b.z;
    // clip the segment to the screen (in screen space)
    vec2 dir = b.xy - a.xy;
    float tmax = 1.0;
    if (dir.x > 0.0) tmax = min(tmax, (1.0 - a.x) / dir.x);
    if (dir.x < 0.0) tmax = min(tmax, -a.x / dir.x);
    if (dir.y > 0.0) tmax = min(tmax, (1.0 - a.y) / dir.y);
    if (dir.y < 0.0) tmax = min(tmax, -a.y / dir.y);
    float pixels = length(dir * tmax / u_rmSsr3.zw);
    float steps = clamp(pixels / 2.0, 4.0, u_rmSsr2.w);
    // a fixed per-pixel start offset (no change from frame to frame: no shimmer), the blur in the composite hides it
    float noise = fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715))));
    float dt = tmax / steps;
    float t0 = 0.0, hit = 0.0, tHit = 0.0, rz0 = p0.z;
    for (int i = 0; i < 64; i++) {
        if (float(i) >= steps)
            break;
        float t = (float(i) + 0.5 + 0.5 * noise) * dt;
        vec2 ss = mix(a.xy, b.xy, t);
        float rz = mix(qa, qb, t) / mix(a.z, b.z, t);
        float sz = sceneZ(ss);
        // a hit: the ray went behind the depth by less than the surface's thickness, or by less than its own step
        // (a long step crosses a thin surface: a coarse march finds it and the bisection refines it)
        float thick = max(max(0.4, sz * u_rmSsr3.x), min((rz - rz0) * 1.5, sz * 0.25));
        if (rz > sz && rz - sz < thick) {
            // bisection between the last step in front and this one
            float lo = t0, hi = t;
            for (int k = 0; k < 5; k++) {
                float m = 0.5 * (lo + hi);
                vec2 sm = mix(a.xy, b.xy, m);
                float mz = mix(qa, qb, m) / mix(a.z, b.z, m);
                if (mz > sceneZ(sm))
                    hi = m;
                else
                    lo = m;
            }
            tHit = hi;
            hit = 1.0;
            break;
        }
        t0 = t;
        rz0 = rz;
    }
    if (hit < 0.5) {
        gl_FragColor = vec4_splat(0.0);
        return;
    }
    vec2 hs = mix(a.xy, b.xy, tHit);
    // fades: at the screen's edges, at the ray's far end, for rays turning back towards the camera
    vec2 e = min(hs, 1.0 - hs);
    float conf = smoothstep(0.0, 0.07, min(e.x, e.y));
    conf *= 1.0 - smoothstep(0.6, 1.0, tHit);
    conf *= smoothstep(-0.9, -0.4, r.z);
    vec3 c = min(texture2DLod(s_rmTex2, texUv(hs), 0.0).rgb, vec3_splat(8.0));
    gl_FragColor = vec4(c * conf, conf);
}
