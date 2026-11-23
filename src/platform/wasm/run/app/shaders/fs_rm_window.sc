$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Window interiors (wlook0, docs/look.md "Interior mapping"): the glass of a building draw (a layeredReflect shader:
// stage 0 the facade, its alpha 0 on the glass; stages 1 and 2 the reflection maps the game adds where the alpha is
// low) drawn again as a decal over itself, showing a room behind each window: a box per texture tile (one window bay),
// ray-cast from the view direction in the facade's own frame (from screen-space derivatives: the world's rooms carry
// no normals or tangents), with a back wall, side walls, floor, ceiling, a furniture layer and blinds or curtains, all
// procedural (no art), lit by the daylight the game baked into the facade and by a lamp when the game's own painted
// pane is lit (night facades); the game's reflection over it by Fresnel. Output only.
//
// Uniforms: u_vc / u_pddiFrag / s_pddiTex0..2 as the faithful draw has them (the sink sets them); and
//   u_rmWin[0]  xyz the world's up in camera space (the draw's modelview), w a per-building seed
//   u_rmWin[1]  x room depth (in room widths), y Fresnel F0, z reflection strength, w lamp strength
//   u_rmWin[2]  x night bias (added to the night estimate), y debug views (1: the mask in magenta, 2: the game's painted pane), z the share of rooms lit
//               by day, w the share lit at night beyond the game's own lit panes
//   (wssr1 hook: when the SSR pass lands, its reflection buffer replaces winStages' `refl` where it has a hit)
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiTex0, 0);
SAMPLER2D(s_pddiTex1, 1);
SAMPLER2D(s_pddiTex2, 2);
uniform vec4 u_pddiFrag[16];
uniform vec4 u_vc[96];          // (the vertex constants: u_vc[48 + s].x is stage s's texture coordinate source)
uniform vec4 u_rmWin[3];

float winHash(vec3 p)
{
    p = fract(p * vec3(0.1031, 0.1030, 0.0973));
    p += dot(p, p.yxz + 33.33);
    return fract((p.x + p.y) * p.z);
}

float winLum(vec3 c) { return dot(c, vec3(0.299, 0.587, 0.114)); }

// a room's colours from its seed: walls, floor, ceiling, furniture
vec3 winPalette(float h)
{
    vec3 c = vec3(0.78, 0.74, 0.66);                            // (warm off-white)
    if (h < 0.18) c = vec3(0.62, 0.68, 0.72);                   // (pale blue-grey)
    else if (h < 0.32) c = vec3(0.72, 0.62, 0.50);              // (beige)
    else if (h < 0.44) c = vec3(0.55, 0.62, 0.52);              // (sage)
    else if (h < 0.54) c = vec3(0.70, 0.56, 0.52);              // (dusty rose)
    else if (h < 0.70) c = vec3(0.82, 0.82, 0.80);              // (office white)
    return c;
}

// stages 1 and 2 as the faithful combiner adds them on the glass, split by their texture coordinates: a stage whose
// coordinates are generated (camera-space normal, position or reflection vector: the sphere / environment map) is the
// reflection; one with mapped coordinates (a second UV set) is the window light the game paints at night
void winStages(vec2 uv1, vec2 uv2, out vec3 refl, out vec3 glow)
{
    vec3 t1 = texture2D(s_pddiTex1, uv1).rgb;
    vec3 t2 = texture2D(s_pddiTex2, uv2).rgb;
    float g1 = step(3.5, u_vc[49].x), g2 = step(3.5, u_vc[50].x);
    refl = t1 * g1 + t2 * g2;
    glow = t1 * (1.0 - g1) + t2 * (1.0 - g2);
}

void main()
{
    vec2 uv = v_texcoord0.xy * u_pddiFrag[4].xy + u_pddiFrag[14].xy;
    vec4 facade = texture2D(s_pddiTex0, uv);
    float mask = saturate((0.6 - facade.a) * 2.5);
    if (mask < 0.004)
        discard;
    vec3 refl, glow;
    winStages(v_texcoord1.xy * u_pddiFrag[4].zw + u_pddiFrag[14].zw, v_texcoord2.xy * u_pddiFrag[5].xy + u_pddiFrag[15].xy,
              refl, glow);
    if (u_rmWin[2].y > 0.5) {               // (debug views: 1 the mask, 2 the painted pane, 3 the window light, 4 the reflection)
        vec3 v = u_rmWin[2].y > 3.5 ? refl : u_rmWin[2].y > 2.5 ? glow : u_rmWin[2].y > 1.5 ? facade.rgb : vec3(1.0, 0.0, 1.0);
        gl_FragColor = vec4(v, mask);
        return;
    }

    // the facade's frame: dP/du, dP/dv (camera space) and the face normal towards the camera
    vec3 P = v_pxpos;
    vec3 dp1 = dFdx(P), dp2 = dFdy(P);
    vec2 du1 = dFdx(uv), du2 = dFdy(uv);
    float det = du1.x * du2.y - du1.y * du2.x;
    vec3 N = cross(dp1, dp2);
    float nl = dot(N, N);
    if (abs(det) < 1e-12 || nl < 1e-20)
        discard;
    N *= inversesqrt(nl);
    if (dot(N, P) > 0.0)
        N = -N;
    vec3 Tu = (dp1 * du2.y - dp2 * du1.y) / det;
    vec3 Tv = (dp2 * du1.x - dp1 * du2.x) / det;
    vec3 up = u_rmWin[0].xyz;

    // the room's axes: horizontal (x), vertical (y, up), depth (z, into the wall)
    bool vVertical = abs(dot(Tv, up)) * length(Tu) >= abs(dot(Tu, up)) * length(Tv);
    vec3 H = vVertical ? Tu : Tv;
    vec3 V = vVertical ? Tv : Tu;
    vec2 cell = floor(uv);
    vec2 f = fract(uv);
    float x = vVertical ? f.x : f.y;
    float y = vVertical ? f.y : f.x;
    if (dot(V, up) < 0.0) {
        V = -V;
        y = 1.0 - y;
    }
    float wH = max(length(H), 1e-4), wV = max(length(V), 1e-4);
    float depth = u_rmWin[1].x * wH;
    vec3 D = normalize(P);
    vec3 d = vec3(dot(D, H) / (wH * wH), dot(D, V) / (wV * wV), max(dot(D, -N), 0.02) / depth);
    vec3 o = vec3(x, y, 0.0);

    // the box: the nearest of its five inner faces
    vec3 tf = (step(vec3(0.0, 0.0, 0.0), d) - o) / d;
    float t = min(min(tf.x, tf.y), tf.z);
    vec3 h = clamp(o + d * t, 0.0, 1.0);
    float seed = u_rmWin[0].w;
    float r0 = winHash(vec3(cell, seed));
    float r1 = winHash(vec3(cell.yx + 17.0, seed + 3.1));
    float r2 = winHash(vec3(cell + 41.0, seed * 1.7 + 0.37));
    vec3 wall = winPalette(r0);
    vec3 albedo;
    float lampFace = 1.0;
    if (t == tf.z) {                                            // the back wall: a skirting, a door or a picture
        albedo = wall;
        if (h.y < 0.05)
            albedo *= 0.55;
        vec2 q = vec2(h.x - (0.2 + 0.6 * r1), h.y);
        if (r2 < 0.35 && abs(q.x) < 0.11 && h.y < 0.72)
            albedo = mix(vec3(0.35, 0.24, 0.16), vec3(0.5, 0.5, 0.52), step(0.5, r1));   // (a door)
        else if (r2 > 0.6 && abs(q.x) < 0.13 && abs(h.y - 0.52) < 0.09)
            albedo = mix(vec3(0.2, 0.25, 0.35), vec3(0.6, 0.35, 0.2), fract(r2 * 7.0));     // (a picture)
    } else if (t == tf.y) {
        if (d.y < 0.0) {                                        // the floor: wood planks or carpet
            float wood = step(0.45, r1);
            float plank = 0.85 + 0.15 * step(0.5, fract(h.x * 6.0 + floor(h.z * 2.0) * 0.5));
            albedo = mix(vec3(0.32, 0.30, 0.30), vec3(0.45, 0.30, 0.18) * plank, wood);
            lampFace = 0.9;
        } else {                                                // the ceiling: a light panel
            albedo = vec3(0.85, 0.85, 0.83);
            lampFace = 1.2;
        }
    } else {
        albedo = wall * 0.92;                                   // a side wall
    }

    // the furniture layer: a desk, sofa or cabinet silhouette on a plane part-way in
    float zf = 0.45 + 0.3 * r2;
    float tz = zf / d.z;
    vec3 pf = o + d * tz;
    float x0 = 0.15 + 0.35 * r0, x1 = x0 + 0.25 + 0.3 * r1;
    float top = r1 < 0.3 ? 0.55 : 0.3;
    bool furn = tz < t && pf.x > x0 && pf.x < x1 && pf.y > 0.0 && pf.y < top;
    if (furn) {
        albedo = mix(vec3(0.18, 0.14, 0.11), vec3(0.32, 0.34, 0.38), step(0.5, r0)) * (pf.y > top - 0.04 ? 1.4 : 1.0);
        h = pf;
    }

    // the light: the daylight baked into the facade, falling off into the room; the game's own pane (its colour and
    // brightness over the window: painted lit offices at night, dark glass by day) as the room's fill, and a lamp
    // where the game paints the pane lit (or a share of rooms chosen by the seed)
    float ext = winLum(v_pxbase.rgb);
    float night = saturate(1.0 - smoothstep(0.25, 0.65, ext) + u_rmWin[2].x);
    vec3 paneRgb = facade.rgb * v_pxbase.rgb + glow;           // (the glass as the game paints and lights it)
    float pane = winLum(paneRgb);
    float gameLit = smoothstep(0.12, 0.4, winLum(glow));
    float r3 = winHash(vec3(cell * 1.31 + 7.0, seed + 11.0));
    float lit = max(gameLit, step(r3, mix(u_rmWin[2].z, u_rmWin[2].w, night)));
    vec3 lampCol = r1 < 0.5 ? vec3(1.0, 0.82, 0.58) : vec3(0.86, 0.94, 1.0);
    lampCol = mix(lampCol, glow / max(winLum(glow), 0.05) * 0.9, 0.5 * gameLit);   // (towards the game's window light)
    float corner = 0.75 + 0.25 * smoothstep(0.0, 0.18, min(min(h.x, 1.0 - h.x), min(h.y, 1.0 - h.y)));
    vec3 fill = paneRgb * 0.35 + vec3(0.03, 0.03, 0.035);
    vec3 day = v_pxbase.rgb * (0.3 + 0.4 * (1.0 - saturate(h.z))) * (1.0 - 0.6 * night) + fill;
    vec3 lamp = lampCol * (lit * u_rmWin[1].w * lampFace * (0.55 + 0.45 * saturate(h.y)));
    vec3 room = albedo * (day + lamp) * corner;
    if (t == tf.y && d.y > 0.0 && !furn && abs(h.x - 0.5) < 0.22 && abs(h.z - 0.5) < 0.18)
        room = mix(room, lampCol * 1.1, lit);                   // (the ceiling's light panel, emissive when lit)

    // blinds or curtains just behind the glass
    float r4 = winHash(vec3(cell + 3.7, seed + 5.0));
    float tb = 0.03 / d.z;
    vec3 pb = o + d * tb;
    if (r4 < 0.35) {                                            // blinds over the top of the window
        float cover = 0.2 + 0.7 * r2;
        if (pb.y > 1.0 - cover && fract(pb.y * 14.0) < 0.75)
            room = mix(vec3(0.78, 0.76, 0.7), lampCol, 0.25) * (day * 1.2 + lamp * 0.8);
    } else if (r4 < 0.6) {                                      // curtains at the sides
        float cw = 0.12 + 0.18 * r0;
        if (pb.x < cw || pb.x > 1.0 - cw) {
            float fold = 0.8 + 0.2 * sin(pb.x * 60.0);
            room = winPalette(fract(r4 * 9.0)) * 0.8 * fold * (day * 1.3 + lamp * 0.9);
        }
    }

    // fade the room's detail into its average where a window is only a few pixels
    float px = max(length(fwidth(uv)), 1e-5);
    float detail = saturate(1.6 - 6.0 * px);
    vec3 flatRoom = wall * (day + lampCol * (lit * u_rmWin[1].w * 0.8)) * 0.8;
    if (!(t > 0.0 && t < 1e4))
        detail = 0.0;                                           // (a frame the derivatives got wrong: a quad over an edge)
    room = mix(flatRoom, room, detail);

    // the glass: the game's reflection over the room by Fresnel
    float cosv = saturate(dot(-D, N));
    float F = u_rmWin[1].y + (1.0 - u_rmWin[1].y) * pow(1.0 - cosv, 5.0);
    vec3 c = room * 0.92 * (1.0 - F) + refl * u_rmWin[1].z * F;

    if (u_pddiFrag[1].w > 0.5) {                                // the draw's fog, as the faithful combiner has it
        float range = u_pddiFrag[2].y - u_pddiFrag[2].x;
        float k = range != 0.0 ? saturate((u_pddiFrag[2].y - v_fog) / range) : 1.0;
        c = mix(u_pddiFrag[1].xyz, c, k);
    }
    gl_FragColor = vec4(c, mask);
}
