$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Screen-space reflections (wssr1, docs/reflections.md): the reflection G-buffer. Every opaque draw of the world's
// pass (and the additive glows, as depth only) is drawn again into the runner's own target with the faithful vertex
// transform (vs_px_ff / vs_px_skin): its depth, the camera-space normal and the draw's reflectance.
//   u_rmSsrMat  x strength off the ground (the draw's material: buildings, environment-mapped objects), y roughness,
//               z strength where the surface faces up (the ground of a room: wet streets), w kind: 0 opaque, 1 metal
//               (environment-mapped: a high F0), 2 a glow (depth only, where its texture is bright), 3 a building
//               (layeredReflect: stage 0's alpha is 0 on the window glass: the glass smooth at full strength, the
//               facade a quarter as strong and rough)
//   u_rmSsrUp   xyz world up in camera space, w cos of the steepest slope taken as ground
// Output (RGBA16F): xy the normal (octahedral), z the strength (0: not reflective), w the Fresnel class + roughness / 2
// (class 0 glass and stone F0 0.04, 1 wet ground, 2 metal-like; the composite's u_rmSsr4.zw / 0.5).
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_pddiFrag[16];
uniform vec4 u_rmSsrMat;
uniform vec4 u_rmSsrUp;

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
    if (u_rmSsrMat.w > 1.5 && u_rmSsrMat.w < 2.5) {
        // a glow: solid where it is bright, so rays find it (the light of street lamps, orbs, fire)
        vec3 c = t.rgb * v_pxbase.rgb;
        if (dot(c, vec3(0.3, 0.59, 0.11)) * t.a * v_pxbase.a < 0.2)
            discard;
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }
    if (u_pddiFrag[0].y >= 0.0) {                   // (the draw's alpha test: its holes stay holes)
        float a = floor(saturate(t.a) * 255.0 + 0.5);
        if (a < u_pddiFrag[0].x || a <= 0.0)
            discard;
    }
    vec3 pos = v_pxpos;
    vec3 f = cross(dFdx(pos), dFdy(pos));
    float l2 = dot(f, f);
    f = l2 > 0.0 ? f * inversesqrt(l2) : vec3(0.0, 0.0, -1.0);
    if (dot(f, pos) > 0.0)
        f = -f;
    // the vertex normal where the draw has one that agrees with the face (70% of room groups have none)
    vec3 n = f;
    if (v_pxnormal.w > 0.5 && v_pxnormal.w < 2.0) {
        vec3 vn = normalize(v_pxnormal.xyz);
        if (dot(vn, pos) > 0.0)
            vn = -vn;
        if (dot(vn, f) > 0.5)
            n = vn;
    }
    float strength = u_rmSsrMat.x;
    float rough = u_rmSsrMat.y;
    float cls = u_rmSsrMat.w > 0.5 && u_rmSsrMat.w < 1.5 ? 2.0 : 0.0;
    if (u_rmSsrMat.w > 2.5) {
        float facade = saturate(t.a);
        strength *= mix(1.0, 0.25, facade);
        rough = mix(0.03, 0.4, facade);
    }
    if (u_rmSsrMat.z > 0.0 && dot(f, u_rmSsrUp.xyz) > u_rmSsrUp.w) {
        strength = u_rmSsrMat.z;
        cls = 1.0;
        n = f;                                      // (the ground: the flat face, a puddle)
        // grass and leaves (green over red and blue, texture x baked colour) stay matt: no mirrored tree trunks
        vec3 c = t.rgb * v_pxbase.rgb;
        float green = smoothstep(0.01, 0.05, c.g - max(c.r, c.b));
        strength *= 1.0 - 0.85 * green;
        rough = mix(rough, 0.7, green);
    }
    gl_FragColor = vec4(octEncode(n), strength, cls + min(saturate(rough), 0.99) * 0.5);
}
