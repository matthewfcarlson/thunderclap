$input v_pxbase, v_pxspec, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3, v_pxnormal, v_pxpos

// Window interiors (wlook0, wlook1; docs/look.md "Interior mapping"): the glass of a building draw (a layeredReflect
// shader: stage 0 the facade, its alpha 0 on the glass; stages 1 and 2 the reflection maps the game adds where the
// alpha is low) drawn again as a decal over itself, showing a room behind each window, ray-cast from the view direction
// in the facade's own frame. All procedural (no art).
//
// wlook1: rooms are chosen per window by a hash of the room's centre in world space (not the texture tile): a bay is
// split into rooms of a storey's height and an office's width when it is large; each room takes a type (office,
// apartment, lobby with a double-height ceiling, storage, shop with a neon sign), a box with its floor below the sill,
// its own colour temperature, lights on or off (the game's own lit-window pattern kept), furniture planes, blinds, a
// roller blind or curtains, and sometimes a silhouette. Lit rooms are as bright as the game's painted window light
// (the night layer), so the skyline keeps its glow. The frame is snapped: vertical from the world's up, the face's
// normal made horizontal, so a 2x2 quad over a triangle edge or a UV seam can't turn the room (no speckle at the
// panes' edges).
//
// Uniforms: u_vc / u_pddiFrag / s_pddiTex0..2 as the faithful draw has them (the sink sets them); and
//   u_rmWin[0]  xyz the world's up in camera space (the draw's modelview), w a per-building seed
//   u_rmWin[1]  x room depth (in room widths), y Fresnel F0, z reflection strength, w lamp strength
//   u_rmWin[2]  x night bias (added to the night estimate), y debug views (1: the mask in magenta, 2: the game's
//               painted pane, 3 its window light, 4 the reflection, 5 the room types), z the share of rooms lit by
//               day, w the share lit at night beyond the game's own lit panes
//   u_rmWin[3]  x the lowest world height of the draw's prim buffer (its foot), y its top, z the street's height (the
//               lowest foot drawn lately; -1e30 none yet): shops and lobbies stay on the first storey above it
#include <bgfx_shader.sh>

SAMPLER2D(s_pddiTex0, 0);
SAMPLER2D(s_pddiTex1, 1);
SAMPLER2D(s_pddiTex2, 2);
uniform vec4 u_pddiFrag[16];
uniform vec4 u_vc[96];          // (the vertex constants: c0..c2 the modelview's rows, u_vc[48 + s].x stage s's source)
uniform vec4 u_rmWin[4];

#define T_OFFICE 0.0
#define T_HOME 1.0
#define T_LOBBY 2.0
#define T_STORE 3.0
#define T_SHOP 4.0

float winHash(vec3 p)
{
    p = fract(p * vec3(0.1031, 0.1030, 0.0973));
    p += dot(p, p.yxz + 33.33);
    return fract((p.x + p.y) * p.z);
}

float winLum(vec3 c) { return dot(c, vec3(0.299, 0.587, 0.114)); }

// a light's colour from a colour temperature 0 (2700 K, warm) .. 1 (6500 K, cool), luminance about 1
vec3 winKelvin(float k)
{
    vec3 warm = vec3(1.25, 0.88, 0.52), mid = vec3(1.12, 1.0, 0.86), cool = vec3(0.92, 1.0, 1.12);
    return k < 0.5 ? mix(warm, mid, k * 2.0) : mix(mid, cool, k * 2.0 - 2.0 * 0.5);
}

// stages 1 and 2 as the faithful combiner adds them on the glass, split by their texture coordinates: a stage whose
// coordinates are generated (the sphere / environment map) is the reflection; one with mapped coordinates (a second
// UV set) is the window light the game paints at night
void winStages(vec2 uv1, vec2 uv2, out vec3 refl, out vec3 glow)
{
    vec3 t1 = texture2D(s_pddiTex1, uv1).rgb;
    vec3 t2 = texture2D(s_pddiTex2, uv2).rgb;
    float g1 = step(3.5, u_vc[49].x), g2 = step(3.5, u_vc[50].x);
    refl = t1 * g1 + t2 * g2;
    glow = t1 * (1.0 - g1) + t2 * (1.0 - g2);
}

// a wall colour of the room's type
vec3 winWall(float type, float h)
{
    if (type == T_OFFICE)
        return h < 0.5 ? vec3(0.80, 0.80, 0.78) : h < 0.8 ? vec3(0.66, 0.70, 0.74) : vec3(0.74, 0.70, 0.62);
    if (type == T_HOME) {
        if (h < 0.2) return vec3(0.82, 0.74, 0.62);            // (warm cream)
        if (h < 0.4) return vec3(0.58, 0.66, 0.58);            // (sage)
        if (h < 0.55) return vec3(0.74, 0.58, 0.54);           // (terracotta pink)
        if (h < 0.7) return vec3(0.52, 0.60, 0.72);            // (dusty blue)
        if (h < 0.85) return vec3(0.84, 0.82, 0.78);           // (white)
        return vec3(0.42, 0.36, 0.40);                         // (aubergine)
    }
    if (type == T_LOBBY)
        return h < 0.5 ? vec3(0.78, 0.70, 0.58) : vec3(0.62, 0.60, 0.58);   // (travertine, grey stone)
    if (type == T_STORE)
        return vec3(0.46, 0.46, 0.44);                         // (bare concrete)
    return h < 0.5 ? vec3(0.86, 0.86, 0.88) : vec3(0.30, 0.30, 0.34);       // (a shop: white or dark)
}

// the furniture and people layers: planes parallel to the glass. a / e: the albedo and emission of what is hit (a.w 1:
// something was hit at depth tz < tmax)
vec4 winFurniture(float type, vec3 o, vec3 d, float yLo, float r0, float r1, float r2, float lit, vec3 lampCol,
                  inout float tmax, out vec3 e)
{
    e = vec3(0.0, 0.0, 0.0);
    vec4 hit = vec4(0.0, 0.0, 0.0, 0.0);
    // the near plane: desks, a sofa, a counter, boxes
    float zf = 0.42 + 0.3 * r2;
    float tz = zf / d.z;
    vec3 p = o + d * tz;
    float fy = p.y - yLo;                                       // (height above the floor, in storeys)
    if (tz < tmax && p.x > 0.0 && p.x < 1.0) {
        if (type == T_OFFICE) {                                 // desks in a row with monitors on them
            float c = fract(p.x * 2.0 + r0);
            bool desk = fy < 0.24 && fy > 0.2 || (fy < 0.2 && (c < 0.06 || c > 0.94));
            bool mon = fy > 0.24 && fy < 0.36 && abs(c - 0.5) < 0.12;
            if (desk) hit = vec4(vec3(0.42, 0.40, 0.38) * (r1 < 0.5 ? 1.0 : 0.6), 1.0);
            if (mon) {
                hit = vec4(0.06, 0.06, 0.07, 1.0);
                if (abs(c - 0.5) < 0.1 && fy > 0.26 && fy < 0.35 && fract(r0 * 13.0 + floor(p.x * 2.0) * 0.37) < 0.5)
                    e = mix(vec3(0.30, 0.50, 0.85), vec3(0.75, 0.8, 0.9), r1) * (0.15 + 0.55 * lit);
            }
        } else if (type == T_HOME) {                            // a sofa and a floor lamp
            float x0 = 0.12 + 0.3 * r0, x1 = x0 + 0.45;
            if (p.x > x0 && p.x < x1 && (fy < 0.15 || (fy < 0.3 && (p.x < x0 + 0.05 || p.x > x1 - 0.05)) ||
                                         (fy < 0.34 && fy > 0.15 && abs(p.x - 0.5 * (x0 + x1)) < 0.2 && r1 > 0.4)))
                hit = vec4(mix(vec3(0.45, 0.22, 0.16), vec3(0.20, 0.26, 0.36), step(0.5, r1)) * (fy < 0.15 ? 0.8 : 1.0),
                           1.0);
            float lx = x1 + 0.12;
            if (abs(p.x - lx) < 0.012 && fy < 0.5)
                hit = vec4(0.15, 0.14, 0.12, 1.0);
            if (abs(p.x - lx) < 0.07 - 0.25 * max(fy - 0.5, 0.0) && fy > 0.5 && fy < 0.62) {
                hit = vec4(0.9, 0.86, 0.78, 1.0);
                e = lampCol * (1.6 * lit);                     // (the lamp's shade glows)
            }
        } else if (type == T_LOBBY) {                           // a reception desk and a plant
            if (abs(p.x - 0.5 + 0.2 * (r0 - 0.5)) < 0.25 && fy < 0.22)
                hit = vec4(vec3(0.30, 0.22, 0.16) * (fy > 0.2 ? 1.5 : 1.0), 1.0);
            vec2 q = vec2(p.x - (r1 < 0.5 ? 0.12 : 0.88), fy - 0.32);
            if (dot(q * vec2(1.0, 0.7), q * vec2(1.0, 0.7)) < 0.012)
                hit = vec4(0.16, 0.28, 0.12, 1.0);
        } else if (type == T_STORE) {                           // stacked boxes
            float c = floor(p.x * 5.0);
            float hgt = 0.12 + 0.35 * winHash(vec3(c, r0 * 7.0, r1));
            if (fy < hgt && fract(p.x * 5.0) > 0.06)
                hit = vec4(vec3(0.52, 0.40, 0.26) * (0.75 + 0.25 * step(0.5, fract(fy * 7.0))), 1.0);
        } else {                                                // a shop: a counter and lit shelves
            if (fy < 0.2 && abs(p.x - 0.5) < 0.3)
                hit = vec4(0.82, 0.82, 0.84, 1.0);
        }
        if (hit.w > 0.5)
            tmax = tz;
    }
    // somebody in the room, now and then (lit offices and homes)
    if ((type == T_OFFICE || type == T_HOME) && lit > 0.5 && fract(r2 * 31.0) < 0.14) {
        float zp = 0.3 + 0.25 * fract(r0 * 17.0);
        float tp = zp / d.z;
        vec3 q = o + d * tp;
        float px = 0.25 + 0.5 * fract(r1 * 23.0);
        float qy = q.y - yLo;
        vec2 hd = vec2(q.x - px, (qy - 0.62) * 1.0);
        bool body = abs(q.x - px) < 0.07 - 0.03 * max(0.45 - qy, 0.0) && qy > 0.0 && qy < 0.55;
        bool head = dot(hd, hd) < 0.0036;
        if (tp < tmax && (body || head)) {
            hit = vec4(0.05, 0.045, 0.05, 1.0);
            e = vec3(0.0, 0.0, 0.0);
            tmax = tp;
        }
    }
    return hit;
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
    float dbg = u_rmWin[2].y;
    if (dbg > 0.5 && dbg < 4.5) {           // (debug views: 1 the mask, 2 the painted pane, 3 the window light, 4 the reflection)
        vec3 v = dbg > 3.5 ? refl : dbg > 2.5 ? glow : dbg > 1.5 ? facade.rgb : vec3(1.0, 0.0, 1.0);
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

    // the room's axes: horizontal (x), vertical (y, up), depth (z, into the wall); snapped on walls: vertical is the
    // world's up and the normal horizontal, so only the bay's size comes from the derivatives
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
    float bw = max(length(H), 1e-4), bh = max(length(V), 1e-4);
    vec3 Hn = H / bw, Vn = V / bh;
    if (abs(dot(N, up)) < 0.35) {                               // (a wall: snap)
        vec3 Nh = normalize(N - up * dot(N, up));
        vec3 Hs = cross(up, Nh);
        Hn = dot(Hs, Hn) < 0.0 ? -Hs : Hs;
        Vn = up;
        N = Nh;
    }

    // rooms: a big bay is split into rooms of a storey (~3.4 units) and an office's width (~4.5 units)
    float nx = clamp(floor(bw / 4.5 + 0.5), 1.0, 3.0), ny = clamp(floor(bh / 3.4 + 0.5), 1.0, 3.0);
    float sx = min(floor(x * nx), nx - 1.0), sy = min(floor(y * ny), ny - 1.0);
    float rw = bw / nx, rh = bh / ny;
    x = x * nx - sx;
    y = y * ny - sy;
    // the room's centre in the world (the modelview's inverse: rooms are in world space): its identity
    vec3 C = P + Hn * ((0.5 - x) * rw) + Vn * ((0.5 - y) * rh);
    vec3 q = C - vec3(u_vc[0].w, u_vc[1].w, u_vc[2].w);
    vec3 W = q.x * u_vc[0].xyz + q.y * u_vc[1].xyz + q.z * u_vc[2].xyz;
    vec3 id = floor(W * 0.8 + 0.37);
    float seed = u_rmWin[0].w;
    float r0 = winHash(id + vec3(seed, 0.0, 0.0));
    float r1 = winHash(id.zxy * 1.7 + 13.1);
    float r2 = winHash(id.yzx * 0.37 + vec3(41.0, seed, 7.0));
    float r3 = winHash(id * 1.31 + 7.0);
    float r4 = winHash(id.yxz + 3.7);
    float tsel = winHash(id * 0.71 + 91.3);
    // shops and lobbies on the first storey above the building's foot, offices, homes and storage above it
    // (a building's prim buffers can be sections of it: the street's height is the lowest foot drawn lately, the
    // buffer's own foot only until one is known)
    float base = u_rmWin[3].z > -1e29 ? u_rmWin[3].z : u_rmWin[3].x;
    bool street = W.y - base < 4.5 && u_rmWin[3].y > u_rmWin[3].x;
    float type = street ? (tsel < 0.45 ? T_SHOP : tsel < 0.75 ? T_LOBBY : tsel < 0.9 ? T_OFFICE : T_STORE) :
                 (tsel < 0.42 ? T_OFFICE : tsel < 0.86 ? T_HOME : T_STORE);

    // the light: on or off. The game's own lit panes stay lit; beyond them a share by type and time of day
    float ext = winLum(v_pxbase.rgb);
    float night = saturate(1.0 - smoothstep(0.25, 0.65, ext) + u_rmWin[2].x);
    float gameLit = smoothstep(0.12, 0.4, winLum(glow));
    float share = mix(u_rmWin[2].z, u_rmWin[2].w, night) *
                  (type == T_STORE ? 0.35 : type == T_SHOP ? 2.5 : type == T_LOBBY ? 2.0 : 1.0);
    float lit = max(gameLit, step(r3, share));
    float kel = type == T_HOME ? 0.1 * r1 : type == T_OFFICE ? 0.45 + 0.45 * r1 : type == T_SHOP ? 0.7 :
                type == T_LOBBY ? 0.2 + 0.2 * r1 : 0.15;
    vec3 lampCol = winKelvin(kel);
    lampCol = mix(lampCol, glow / max(winLum(glow), 0.05), 0.35 * gameLit);   // (towards the game's window light)
    // as bright as the game's lit pane (its night layer), at least a typical lit window
    float bright = min(max(winLum(glow) * 1.2, 0.7), 1.0) * u_rmWin[1].w / 0.8;

    vec3 wall = winWall(type, r0);
    vec3 paneRgb = facade.rgb * v_pxbase.rgb + glow;
    vec3 fill = paneRgb * 0.3 + vec3(0.035, 0.04, 0.05) * (0.5 + night);   // (the city's glow at night)

    // the room's detail fades into its average where a room is only a few pixels: such windows (most of a skyline)
    // take only the average, the box and its contents are traced only where they show
    float px = max(length(fwidth(uv)) * max(nx, ny), 1e-5);
    float detail = saturate(1.6 - 6.0 * px);
    vec3 dayFlat = v_pxbase.rgb * 0.575 * (1.0 - 0.6 * night) + fill;
    vec3 flatRoom = wall * (dayFlat + lampCol * (lit * bright * 0.8)) * 0.85 + lampCol * (lit * 0.15 * bright);
    // (derivatives taken before the branch: the blinds' slats at their scale)
    float slatW = fwidth(y * 16.0);
    vec3 room = flatRoom;
    vec3 D = normalize(P);
    if (detail > 0.004) {
        // the box: x 0..1 across, y from the floor (below the sill) to the ceiling, z 0..1 into the building
        float yLo = type == T_LOBBY ? -0.45 : -0.28;
        float yHi = type == T_LOBBY ? 1.85 : 1.06;
        float depthW = u_rmWin[1].x * max(rw, 0.8 * rh) * (type == T_LOBBY ? 1.4 : type == T_STORE ? 0.8 : 1.0);
        vec3 d = vec3(dot(D, Hn) / rw, dot(D, Vn) / rh, max(dot(D, -N), 0.02) / depthW);
        vec3 o = vec3(x, y, 0.0);
        vec3 lo = vec3(0.0, yLo, 0.0), hi = vec3(1.0, yHi, 1.0);
        vec3 t0 = (lo - o) / d, t1 = (hi - o) / d;
        vec3 tf = max(t0, t1);
        float t = min(min(tf.x, tf.y), tf.z);
        vec3 h = o + d * t;
        h = clamp(h, lo, hi);
        float fy = (h.y - yLo) / (yHi - yLo);                       // (0 floor .. 1 ceiling)

        vec3 albedo = wall;
        vec3 emit = vec3(0.0, 0.0, 0.0);
        float face = t == tf.z ? 0.0 : t == tf.y ? (d.y < 0.0 ? 1.0 : 2.0) : 3.0;   // back, floor, ceiling, side
        if (face < 0.5) {                                           // the back wall
            if (h.y - yLo < 0.04)
                albedo *= 0.5;                                      // (a skirting)
            float ax = 0.2 + 0.6 * r1;
            if (type == T_OFFICE) {
                if (r2 < 0.4 && abs(h.x - ax) < 0.1 && fy < 0.66)
                    albedo = vec3(0.55, 0.56, 0.58);                // (a door)
                else if (r2 > 0.6 && abs(h.x - ax) < 0.2 && abs(fy - 0.52) < 0.1)
                    albedo = vec3(0.92, 0.93, 0.94);                // (a whiteboard)
            } else if (type == T_HOME) {
                if (r2 > 0.4 && abs(h.x - ax) < 0.12 && abs(fy - 0.56) < 0.09) {
                    albedo = mix(vec3(0.15, 0.2, 0.35), vec3(0.75, 0.42, 0.2), fract(r2 * 7.0 + h.y * 3.0)) *
                             (abs(h.x - ax) > 0.105 || abs(fy - 0.56) > 0.075 ? 0.3 : 1.0);   // (art in a frame)
                } else if (r2 < 0.25 && abs(fy - 0.45) < 0.012)
                    albedo = vec3(0.3, 0.22, 0.15);                 // (a shelf)
            } else if (type == T_STORE) {
                if (fract(fy * 4.0) < 0.06)
                    albedo = vec3(0.3, 0.3, 0.32);                  // (shelving)
            } else if (type == T_SHOP) {                            // a neon sign
                vec2 s = vec2((h.x - 0.5) * 3.0, (fy - 0.6) * 9.0);
                float ring = abs(length(s * vec2(1.0, 0.5)) - 0.8);
                float bar = abs(s.y) < 0.12 && abs(s.x) < 1.2 ? 0.0 : 1.0;
                float neon = min(ring, bar) < 0.1 ? 1.0 : 0.0;
                vec3 nc = r1 < 0.33 ? vec3(1.0, 0.2, 0.6) : r1 < 0.66 ? vec3(0.2, 0.9, 1.0) : vec3(1.0, 0.55, 0.1);
                emit += nc * neon * 2.2 * max(lit, 0.6);
                albedo = mix(albedo, nc * 0.4, neon);
            } else if (type == T_LOBBY) {
                if (abs(h.x - ax) < 0.06)
                    albedo = vec3(0.86, 0.84, 0.8);                 // (a pillar)
            }
        } else if (face < 1.5) {                                    // the floor
            if (type == T_HOME) {
                float plank = 0.85 + 0.15 * step(0.5, fract(h.x * 6.0 + floor(h.z * 2.5) * 0.5));
                albedo = (r4 < 0.6 ? vec3(0.48, 0.32, 0.19) : vec3(0.62, 0.50, 0.36)) * plank;
                if (abs(h.x - 0.5) < 0.3 && abs(h.z - 0.55) < 0.2 && r2 > 0.3)
                    albedo = winWall(T_HOME, fract(r2 * 5.0)) * 0.7;   // (a rug)
            } else if (type == T_OFFICE)
                albedo = vec3(0.30, 0.32, 0.36);                    // (carpet)
            else if (type == T_LOBBY)
                albedo = vec3(0.80, 0.78, 0.74) * (0.9 + 0.1 * step(0.5, fract(h.x * 3.0 + floor(h.z * 3.0) * 0.5)));
            else if (type == T_SHOP)
                albedo = vec3(0.7, 0.7, 0.72) * (0.85 + 0.15 * step(0.5, fract(h.x * 5.0) + fract(h.z * 5.0) - 0.5));
            else
                albedo = vec3(0.38, 0.38, 0.37);
        } else if (face < 2.5) {                                    // the ceiling and its lights
            albedo = vec3(0.86, 0.86, 0.84);
            if (type == T_OFFICE) {                                 // a grid of panels, every other one a light
                vec2 g = fract(vec2(h.x * 2.0, h.z * 3.0));
                if (abs(g.x - 0.5) < 0.3 && abs(g.y - 0.5) < 0.25 && fract((floor(h.x * 2.0) + floor(h.z * 3.0)) * 0.5) < 0.1)
                    emit += lampCol * (1.6 * lit);
                else if (g.x < 0.02 || g.y < 0.03)
                    albedo *= 0.7;
            } else if (type == T_LOBBY || type == T_SHOP) {         // spots
                vec2 g = fract(vec2(h.x * 3.0, h.z * 3.0)) - 0.5;
                if (dot(g, g) < 0.02)
                    emit += lampCol * (2.2 * lit);
            } else if (type == T_STORE) {                           // one bare bulb
                vec2 g = vec2(h.x - 0.5, h.z - 0.5);
                if (dot(g, g) < 0.002)
                    emit += lampCol * (2.5 * lit);
            } else if (abs(h.x - 0.5) < 0.16 && abs(h.z - 0.5) < 0.12 && r4 > 0.5)
                emit += lampCol * (1.4 * lit);                      // (a ceiling lamp; else only the floor lamp)
        } else {
            albedo = wall * 0.9;                                    // a side wall
            if (type == T_STORE && fract(fy * 4.0) < 0.06)
                albedo = vec3(0.3, 0.3, 0.32);
        }

        // furniture, people
        float tmax = t;
        vec3 fe;
        vec4 furn = winFurniture(type, o, d, yLo, r0, r1, r2, lit, lampCol, tmax, fe);
        bool hitFurn = furn.w > 0.5;
        if (hitFurn) {
            albedo = furn.rgb;
            emit = fe;
            h = o + d * tmax;
            fy = (h.y - yLo) / (yHi - yLo);
        }

        // the lighting: daylight baked into the facade falling off into the room, the game's own pane as a fill, the
        // room's light (brighter towards the light source: the ceiling, or the floor lamp in a home)
        vec3 day = v_pxbase.rgb * (0.35 + 0.45 * (1.0 - saturate(h.z))) * (1.0 - 0.6 * night) + fill;
        float shape = type == T_HOME ? 0.55 + 0.45 * saturate(1.0 - 1.8 * length(vec2(h.x - 0.85, h.z - 0.45))) :
                      0.6 + 0.4 * fy;
        vec3 lamp = lampCol * (lit * bright * shape);
        float corner = 0.78 + 0.22 * smoothstep(0.0, 0.15, min(min(h.x, 1.0 - h.x), min(fy, 1.0 - fy)));
        float faceShade = hitFurn ? 1.0 : face < 0.5 ? 1.0 : face < 1.5 ? 0.72 : face < 2.5 ? 0.9 : 0.8;
        vec3 rd = albedo * (day + lamp * (1.0 - 0.3 * saturate(h.z) * step(0.5, face))) * corner * faceShade + emit;

        // what is just behind the glass: blinds, a roller blind or curtains (lit from the room)
        float tb = 0.03 / d.z;
        vec3 pb = o + d * tb;
        vec3 sheen = day * 1.1 + lamp * 0.9;
        if (r4 < 0.22) {                                            // venetian blinds over the top
            float cover = 0.15 + 0.75 * r2;
            // (slats finer than a pixel: their average)
            float slat = mix(step(fract(pb.y * 16.0), 0.72), 0.72, saturate(slatW * 2.0 - 0.5));
            if (pb.y > 1.0 - cover)
                rd = mix(rd, mix(vec3(0.80, 0.78, 0.72), lampCol, 0.2) * sheen, slat);
        } else if (r4 < 0.34) {                                     // a roller blind, glowing when lit
            float cover = 0.3 + 0.7 * r1;
            if (pb.y > 1.0 - cover)
                rd = mix(vec3(0.86, 0.82, 0.74), vec3(0.72, 0.78, 0.82), step(0.5, r0)) * (day * 0.9 + lamp * 0.7) +
                       lampCol * (lit * bright * 0.25);
        } else if (r4 < 0.56 && type != T_SHOP && type != T_LOBBY) {   // curtains at the sides
            float cw = 0.1 + 0.2 * r0;
            if (pb.x < cw || pb.x > 1.0 - cw) {
                float fold = 0.8 + 0.2 * sin(pb.x * 60.0);
                rd = winWall(T_HOME, fract(r4 * 9.0)) * 0.85 * fold * sheen + lampCol * (lit * bright * 0.12);
            }
        }

        if (!(t > 0.0 && t < 1e4))
            detail = 0.0;                                           // (a frame the derivatives got wrong)
        room = mix(flatRoom, rd, detail);
    }
    if (dbg > 4.5)                          // (debug view 5: the room types, lit brighter)
        room = (type == T_OFFICE ? vec3(0.2, 0.4, 1.0) : type == T_HOME ? vec3(1.0, 0.6, 0.2) : type == T_LOBBY ?
                vec3(1.0, 1.0, 1.0) : type == T_STORE ? vec3(0.3, 0.3, 0.3) : vec3(1.0, 0.2, 0.8)) * (0.4 + 0.6 * lit);

    // the glass: the game's reflection over the room by Fresnel
    float cosv = saturate(dot(-D, N));
    float F = u_rmWin[1].y + (1.0 - u_rmWin[1].y) * pow(1.0 - cosv, 5.0);
    vec3 c = room * (1.0 - F) + refl * u_rmWin[1].z * F;

    if (u_pddiFrag[1].w > 0.5) {                                // the draw's fog, as the faithful combiner has it
        float range = u_pddiFrag[2].y - u_pddiFrag[2].x;
        float k = range != 0.0 ? saturate((u_pddiFrag[2].y - v_fog) / range) : 1.0;
        c = mix(u_pddiFrag[1].xyz, c, k);
    }
    gl_FragColor = vec4(c, mask);
}
