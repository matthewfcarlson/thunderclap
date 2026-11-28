$input v_texcoord0

// Contact shadows and bounce light (wshadow1, run/app/contact.cpp, docs/hdr-shadows.md), at half size, from the scene's
// depth and colour and the world pass's projection. Output: rgb the bounce (strength applied), a the visibility.
//   u_rmCt0  the projection: x c4.x, y c5.y, z c4.z, w c5.z (x_clip = c4.x x + c4.z z + c4.w, y alike)
//   u_rmCt1  x c6.z, y c6.w, z c7.z, w c7.w (z_clip = c6.z z + c6.w, w_clip = c7.z z + c7.w)
//   u_rmCt2  x c4.w, y c5.w, z the full-size texel width (uv), w its height
//   u_rmCt3  xyz towards the sun (camera space, unit), w the shadow's strength (0: none)
//   u_rmCt4  x the ray's length, y the occluders' thickness (world units), z the bounce's strength (0: none),
//            w the bounce's radius
//   u_rmCt5  x the far fade's start, y its end
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
SAMPLER2D(s_rmTex1, 1);         // the scene's colour
uniform vec4 u_rmCt0;
uniform vec4 u_rmCt1;
uniform vec4 u_rmCt2;
uniform vec4 u_rmCt3;
uniform vec4 u_rmCt4;
uniform vec4 u_rmCt5;

float viewZ(float d)
{
    return (u_rmCt1.y - d * u_rmCt1.w) / min(d * u_rmCt1.z - u_rmCt1.x, -1e-7);
}
vec3 viewPos(vec2 uv, float d)
{
    float z = viewZ(d);
    float w = u_rmCt1.z * z + u_rmCt1.w;
    vec2 ndc = vec2(uv.x * 2.0 - 1.0, 1.0 - uv.y * 2.0);
    float x = (ndc.x * w - u_rmCt0.z * z - u_rmCt2.x) / u_rmCt0.x;
    float y = (ndc.y * w - u_rmCt0.w * z - u_rmCt2.y) / u_rmCt0.y;
    return vec3(x, y, z);
}
vec3 at(vec2 uv)
{
    return viewPos(uv, texture2DLod(s_rmTex0, uv, 0.0).x);
}
vec2 project(vec3 q)
{
    float w = max(u_rmCt1.z * q.z + u_rmCt1.w, 1e-4);
    vec2 ndc = vec2(u_rmCt0.x * q.x + u_rmCt0.z * q.z + u_rmCt2.x, u_rmCt0.y * q.y + u_rmCt0.w * q.z + u_rmCt2.y) / w;
    return vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    float d = texture2DLod(s_rmTex0, uv, 0.0).x;
    if (d >= 0.99999) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
        return;
    }
    vec3 p = viewPos(uv, d);
    float fade = 1.0 - saturate((p.z - u_rmCt5.x) / max(u_rmCt5.y - u_rmCt5.x, 1.0));
    if (fade <= 0.0) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
        return;
    }
    // the normal over a two-texel baseline from the nearer neighbour on each axis (ao.cpp's, wlook1)
    vec2 tx = u_rmCt2.zw * 2.0;
    vec3 px1 = at(uv + vec2(tx.x, 0.0)) - p, px0 = p - at(uv - vec2(tx.x, 0.0));
    vec3 py1 = at(uv + vec2(0.0, tx.y)) - p, py0 = p - at(uv - vec2(0.0, tx.y));
    vec3 dx = abs(px1.z) < abs(px0.z) ? px1 : px0;
    vec3 dy = abs(py1.z) < abs(py0.z) ? py1 : py0;
    vec3 n = normalize(cross(dy, dx));
    if (dot(n, p) > 0.0)
        n = -n;
    // a 4x4 Bayer value per (half-size) pixel: the apply's 4x4 blur takes each of the 16 once (wlook3)
    vec2 fc = floor(gl_FragCoord.xy);
    vec2 lo = mod(fc, 2.0), hi = mod(floor(fc * 0.5), 2.0);
    float bayer = (4.0 * mod(2.0 * lo.x + 3.0 * lo.y, 4.0) + mod(2.0 * hi.x + 3.0 * hi.y, 4.0) + 0.5) / 16.0;

    // contact shadow: a short ray towards the sun through the depth
    float vis = 1.0;
    vec3 L = u_rmCt3.xyz;
    float ndl = dot(n, L);
    if (u_rmCt3.w > 0.0 && ndl > 0.0) {
        vec3 o = p + n * (0.02 + 0.002 * p.z);
        float occ = 0.0;
        for (int i = 0; i < 12; i++) {
            float t = (float(i) + bayer) / 12.0;
            vec3 q = o + L * (u_rmCt4.x * t);
            vec2 s = project(q);
            if (s.x < 0.0 || s.x > 1.0 || s.y < 0.0 || s.y > 1.0 || q.z < 0.05)
                break;
            float dz = q.z - viewZ(texture2DLod(s_rmTex0, s, 0.0).x);
            // (a surface in front of the ray point, beyond the depth's precision and within the occluders' thickness)
            if (dz > 0.01 + 0.0015 * q.z && dz < u_rmCt4.y) {
                occ = 1.0 - 0.6 * t;
                break;
            }
        }
        vis = 1.0 - u_rmCt3.w * occ * saturate(ndl * 4.0) * fade;
    }

    // bounce: the lit colour of the surfaces around, as seen from this one's side
    vec3 b = vec3_splat(0.0);
    if (u_rmCt4.z > 0.0) {
        float r = u_rmCt4.w;
        vec2 rs = r * u_rmCt0.xy / max(u_rmCt1.z * p.z + u_rmCt1.w, 1e-4) * 0.5;
        rs *= min(1.0, 0.12 / max(rs.x, 1e-6));
        float ang = bayer * 6.2831853;
        for (int i = 0; i < 8; i++) {
            float t = sqrt((float(i) + 0.5) / 8.0);
            float a = ang + float(i) * 2.3999632;
            vec2 s = uv + vec2(cos(a), sin(a)) * rs * t;
            float sd = texture2DLod(s_rmTex0, s, 0.0).x;
            if (sd >= 0.99999)
                continue;
            vec3 v = viewPos(s, sd) - p;
            float vv = dot(v, v);
            float c = dot(v, n) * inversesqrt(vv + 1e-4);
            float wgt = saturate(c - 0.1) * saturate(1.0 - vv / (r * r));
            b += min(texture2DLod(s_rmTex1, s, 0.0).rgb, vec3_splat(1.5)) * wgt;
        }
        b *= u_rmCt4.z / 8.0 * fade;
    }
    gl_FragColor = vec4(b, vis);
}
