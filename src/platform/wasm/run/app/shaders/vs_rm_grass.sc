$input a_position, a_normal, i_data0, i_data1, i_data2
$output v_pxbase, v_pxspec, v_fog, v_pxpos, v_pxnormal

// Grass blades (wgrass1, run/app/grass.cpp, docs/grass.md): one instance is a clump of blades standing on the game's
// grass ground, in world space (the rooms' vertices are world space: their modelview is the view itself).
//   a_position   the blade's vertex: x the side (-1, 0, 1), y the height along the blade (0..1), z the blade's angle
//                in its clump (radians)
//   a_normal     the blade in its clump: x its distance from the clump's centre, y its lean, z its height (a fraction
//                of the clump's)
//   i_data0      the clump: xyz its root (world), w its rank (0..1: which density keeps it)
//   i_data1      rgb the ground's colour under it (texture x baked light), w a random number
//   i_data2      rgb the ground's surface under it (its textures alone: what added light multiplies), w unused
// Uniforms: u_vc (the ground draw's constants: c0..c3 the view, c4..c7 the projection, c55 the HUD edge shift),
//   u_rmGrass[0] xyz the camera (world), w the display clock (seconds)
//   u_rmGrass[1] x the distance where the density starts to fall, y where it is 0, z the blade height, w its width
//   u_rmGrass[2] xz the wind's direction (world), y its strength, w the colour variation
//   u_rmGrass[3..6] what bends the grass aside (characters): xyz their position (world), w the radius (0: none)
//   u_rmGrass[7] x the show mode (1: tint), y the minimum width in pixels at 1 unit (x the projection), z, w unused
#include <bgfx_shader.sh>

uniform vec4 u_vc[96];
uniform vec4 u_rmGrass[8];

void main()
{
    vec3 root = i_data0.xyz;
    float rank = i_data0.w;
    vec3 cam = u_rmGrass[0].xyz;
    float time = u_rmGrass[0].w;
    float d = length(root - cam);
    // density by distance: a clump stands while its rank is under the density there; it grows out of the ground as
    // the density passes its rank (no popping), and every blade shrinks away towards the far end
    float dens = saturate((u_rmGrass[1].y - d) / max(u_rmGrass[1].y - u_rmGrass[1].x, 0.001));
    float grow = saturate((dens - rank) * 8.0);
    grow *= 1.0 - smoothstep(u_rmGrass[1].y * 0.75, u_rmGrass[1].y, d);
    float seed = i_data1.w;
    float h = u_rmGrass[1].z * a_normal.z * (0.75 + 0.5 * fract(seed * 7.13)) * grow;
    float t = a_position.y;
    // the blade's frame: its own angle in the clump plus the clump's
    float ang = a_position.z + seed * 6.2831853;
    vec2 dir = vec2(cos(ang), sin(ang));                      // (the blade's facing; the side is across it)
    vec2 side = vec2(-dir.y, dir.x);
    vec2 off = vec2(cos(ang * 1.7 + 1.3), sin(ang * 1.7 + 1.3)) * a_normal.x;
    // width: tapering to the tip, at least a fraction of a pixel's width further away (thin blades shimmer)
    float w = u_rmGrass[1].w * (1.0 - t) * max(1.0, d * u_rmGrass[7].y);
    vec3 p = root + vec3(off.x, 0.0, off.y) + vec3(side.x, 0.0, side.y) * (a_position.x * w * 0.5);
    // lean, wind and what pushes it aside, growing with the height squared (the root stays put)
    vec2 bend = dir * (a_normal.y * h);
    vec2 wd = u_rmGrass[2].xz;
    float ph = dot(root.xz, vec2(0.21, 0.13));
    float gust = sin(time * 1.3 + ph) * 0.6 + sin(time * 2.9 + ph * 1.7 + seed * 3.0) * 0.25 + 0.35;
    bend += wd * (gust * u_rmGrass[2].y * h);
    float flatten = 0.0;
    for (int i = 0; i < 4; i++) {
        vec4 pu = u_rmGrass[3 + i];
        if (pu.w > 0.0) {
            vec3 dv = root - pu.xyz;
            float r = length(dv.xz);
            if (r < pu.w && abs(dv.y) < 3.0) {
                float k = 1.0 - r / pu.w;
                k *= k;
                vec2 away = r > 0.001 ? dv.xz / r : dir;
                bend += away * (k * h * 1.2);
                flatten = max(flatten, k);
            }
        }
    }
    float t2 = t * t;
    p.xz += bend * t2;
    p.y += h * t * (1.0 - 0.6 * flatten) - dot(bend, bend) * t2 / max(2.0 * h, 0.001);   // (keeps its length)
    vec4 view = vec4(dot(vec4(p, 1.0), u_vc[0]), dot(vec4(p, 1.0), u_vc[1]), dot(vec4(p, 1.0), u_vc[2]), 1.0);
    gl_Position = vec4(dot(view, u_vc[4]), dot(view, u_vc[5]), dot(view, u_vc[6]), dot(view, u_vc[7]));
    if (h <= 0.0)
        gl_Position = vec4(0.0, 0.0, -2.0, 1.0);              // (not standing: outside the clip volume)
    if (u_vc[55].x != 0.0 && gl_Position.w > 0.0) {
        float xn = gl_Position.x / gl_Position.w / u_vc[55].y;
        gl_Position.x += sign(xn) * u_vc[55].x * smoothstep(0.05, 0.2, abs(xn)) * gl_Position.w;
    }
    v_fog = view.z;
    v_pxpos = view.xyz;
    // the ground's colour: darker at the root (the blades shade each other), lighter and a little yellower at the
    // tip, so the lawn as a whole keeps the ground's brightness; a little variation between clumps
    vec3 c = i_data1.rgb * (1.0 + u_rmGrass[2].w * (fract(seed * 13.7) - 0.5));
    c *= 0.85 + 0.4 * t;
    c = mix(c, c * vec3(1.08, 1.05, 0.85), t);
    // the surface for the night lights, shaded as the colour
    float shade = (1.0 + u_rmGrass[2].w * (fract(seed * 13.7) - 0.5)) * (0.85 + 0.4 * t);
    v_pxspec = vec4(mix(i_data2.rgb, i_data2.rgb * vec3(1.08, 1.05, 0.85), t) * shade, 0.0);
    if (u_rmGrass[7].x > 0.5)
        c = mix(c, vec3(1.0, 0.2, 0.9), 0.6);
    v_pxbase = vec4(c, 1.0);
    // the world's up in camera space (the shadows' facing: the blades take the ground's)
    v_pxnormal = vec4(normalize(vec3(u_vc[0].y, u_vc[1].y, u_vc[2].y)), 1.0);
}
