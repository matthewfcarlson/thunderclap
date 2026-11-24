$input v_texcoord0

// Ambient occlusion (wr3a, docs/hdr-shadows.md): a screen-space obscurance estimate (Alchemy-style) from the scene's
// depth and the world pass's projection, at half size. Output: r the visibility (1 = open), g the view depth.
//   u_rmAo0  the projection: x c4.x, y c5.y, z c4.z, w c5.z (x_clip = c4.x x + c4.z z + c4.w, y alike)
//   u_rmAo1  x c6.z, y c6.w, z c7.z, w c7.w (z_clip = c6.z z + c6.w, w_clip = c7.z z + c7.w)
//   u_rmAo2  x c4.w, y c5.w, z the radius (world units), w the full-size texel width (uv)
//   u_rmAo3  x the strength, y the far fade start, z the far fade end, w the full-size texel height (uv)
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
uniform vec4 u_rmAo0;
uniform vec4 u_rmAo1;
uniform vec4 u_rmAo2;
uniform vec4 u_rmAo3;

float viewZ(float d)
{
    return (u_rmAo1.y - d * u_rmAo1.w) / min(d * u_rmAo1.z - u_rmAo1.x, -1e-7);
}
vec3 viewPos(vec2 uv, float d)
{
    float z = viewZ(d);
    float w = u_rmAo1.z * z + u_rmAo1.w;
    vec2 ndc = vec2(uv.x * 2.0 - 1.0, 1.0 - uv.y * 2.0);
    float x = (ndc.x * w - u_rmAo0.z * z - u_rmAo2.x) / u_rmAo0.x;
    float y = (ndc.y * w - u_rmAo0.w * z - u_rmAo2.y) / u_rmAo0.y;
    return vec3(x, y, z);
}
vec3 at(vec2 uv)
{
    return viewPos(uv, texture2DLod(s_rmTex0, uv, 0.0).x);
}

void main()
{
    vec2 uv = v_texcoord0.xy;
    float d = texture2DLod(s_rmTex0, uv, 0.0).x;
    if (d >= 0.99999) {
        gl_FragColor = vec4(1.0, 1e6, 0.0, 1.0);
        return;
    }
    vec3 p = viewPos(uv, d);
    // wlook1: the normal over a two-texel baseline: the depth buffer's steps (terraces of the 24-bit depth on ground seen
    // at a grazing angle) tilt a one-texel normal by a few milliradians, row by row, which the samples read as
    // occlusion: the horizontal bands on the desert ground
    vec2 tx = vec2(u_rmAo2.w, u_rmAo3.w) * 2.0;
    // the normal from the nearer neighbour on each axis (edges keep their own side)
    vec3 px1 = at(uv + vec2(tx.x, 0.0)) - p, px0 = p - at(uv - vec2(tx.x, 0.0));
    vec3 py1 = at(uv + vec2(0.0, tx.y)) - p, py0 = p - at(uv - vec2(0.0, tx.y));
    vec3 dx = abs(px1.z) < abs(px0.z) ? px1 : px0;
    vec3 dy = abs(py1.z) < abs(py0.z) ? py1 : py0;
    vec3 n = normalize(cross(dy, dx));
    if (dot(n, p) > 0.0)
        n = -n;
    // the disc's radius on screen (uv) at this depth
    float r = u_rmAo2.z;
    vec2 rs = r * u_rmAo0.xy / max(u_rmAo1.z * p.z + u_rmAo1.w, 1e-4) * 0.5;
    rs *= min(1.0, 0.1 / max(rs.x, 1e-6));
    // a rotation per pixel of a 12-sample spiral. wlook3: from a 4x4 Bayer matrix (was interleaved gradient noise):
    // the apply's 4x4 blur then takes each of the 16 rotations once, so the estimate's noise cancels instead of
    // reading as grain (nothing resolves it without TAA)
    vec2 fc = floor(gl_FragCoord.xy);
    vec2 lo = mod(fc, 2.0), hi = mod(floor(fc * 0.5), 2.0);
    float bayer = 4.0 * mod(2.0 * lo.x + 3.0 * lo.y, 4.0) + mod(2.0 * hi.x + 3.0 * hi.y, 4.0);
    float ang = (bayer + 0.5) * (6.2831853 / 16.0);
    float sum = 0.0;
    for (int i = 0; i < 12; i++) {
        float t = (float(i) + 0.5) / 12.0;
        float a = ang + float(i) * 2.3999632;
        vec2 o = vec2(cos(a), sin(a)) * rs * t;
        vec3 q = at(uv + o);
        vec3 v = q - p;
        float vv = dot(v, v);
        float range = saturate(1.0 - vv / (r * r * 4.0));
        // (an angle bias: a sample has to rise ~4 degrees above the surface's plane to occlude, so a flat surface with
        // a slightly wrong normal stays open while corners, steps and contacts keep their occlusion)
        sum += max(dot(v, n) - 0.07 * sqrt(vv) - 0.002 * p.z - 0.02, 0.0) / (vv + 0.01) * range;
    }
    float ao = max(0.0, 1.0 - 2.0 * u_rmAo3.x * sum / 12.0);
    float fade = saturate((p.z - u_rmAo3.y) / max(u_rmAo3.z - u_rmAo3.y, 1.0));
    gl_FragColor = vec4(mix(ao, 1.0, fade), p.z, 0.0, 1.0);
}
