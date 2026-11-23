/* The tutorial-skip star (wskip1; port_settings.c `tutorial_skip`, Gameplay Options > Tutorial Skip; docs/wasm-port.md
 * "Tutorial skip"; HULK_WASM_GFX=1 builds only).
 *
 * In the two tutorial missions (c00m01, the moves; c00m02, being the Hulk) a spinning, glowing star waits a few units
 * behind the Hulk where he gains control (between him and the camera: pull the stick back to walk into it). Walking
 * into it ends the mission through the game's own success path, as if its last objective had just been met:
 *
 *   c00m01  gfm_SetMissionProgressSimple("c00m01", "complete"): the mission's own condition on that progress runs its
 *           ending (the fades, gfm_SetAcquireMission("c00m02"), sm_SetMissionState(MISSION_SUCCESS): the summary)
 *   c00m02  set_game_state("c0m2", "complete"): the mission's own script state reaching its last stage runs its
 *           ending (gfm_SetNextMission("c01m10"), the XP award, MISSION_IMMEDIATELOAD)
 *
 * so the progress, the next mission and the save are the game's. The line is our own Lua (binding and script-state
 * names only), run by the game's sh_DoString 0x001d3f00 from an entry hook on UpdateSimulation 0x00088c30 (after
 * the original: no script runs then).
 *
 * Game state: the star's place and whether it fired live in the snapshotted section (hulk_game_state), are computed
 * from the game's state alone (the main actor, the logic view) in the update, and with the setting off nothing here
 * runs, so a faithful run is the original's. With it on, the same input gives the same state (and HULK_ROLLTEST holds:
 * the section restores with the game). The setting is per session (netplay peers must share it).
 *
 * The star is drawn by the game's own pddi context, right after World::Render 0x001c88f0 (draw_distance.c's hook
 * calls hulk_wasm_tutorial_skip_draw): our own procedural geometry (an extruded five-pointed star, faceted by a fixed
 * light, and an additive glow disc and beam), in world space under the camera's modelview, depth-tested. Drawing makes
 * the front end's render bookkeeping move (a shader, prim-stream draws), like any draw; it reads only the state.
 *
 * HULK_TSKIP_LOG=1 logs the mission, the Hulk and the star; HULK_TSKIP_LOG=2 also every 30 updates. */
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "port_settings.h"

#define GAME_STATE __attribute__((section("hulk_game_state")))

/* the game's objects */
#define WORLD_PTR 0x004dd700u          /* +0x20 the actor manager (+0x124 the main actor), +0x2c the scenario manager */
#define GAME_PTR 0x004dd6ecu           /* +0x38 the game-flow manager: +0x80 chapter, +0x84 mission (gfm_GetChapter) */
#define VIEW_PTR 0x004e231cu           /* the logic view: +0x4c its position (rm_GetCameraPosition) */
#define SCRIPT_PTR 0x004e23ccu         /* the ScriptHandler singleton (FUN_001d4c90) */
#define DEVICE_PTR 0x0052c2a0u         /* pure3d's pddi device */
#define CONTEXT_PTR 0x0052c2a8u        /* pure3d's pddi context */
#define FN_DOSTRING 0x001d3f00u        /* ScriptHandler::DoString(text, chunk name) */
#define FN_NODE_POS 0x00059a50u        /* a scene node's position (the probe's position_of) */
#define FN_VERTEX 0x0008ef00u          /* the prim stream's next vertex */
#define FN_CAM_POS 0x001c1300u         /* the render context's camera position */

#define BEHIND 4.0f                    /* the star's distance behind the Hulk */
#define LIFT 1.2f                      /* its centre above his feet */
#define REACH 1.8f                     /* the trigger: horizontal distance to the centre */
#define SETTLE 45                      /* updates in play (below), the Hulk standing, before the star is placed */
#define CAM_NEAR 14.0f                 /* in play: the logic view within this of the Hulk (the chase camera is ~10
                                        * away; an in-engine intro's cameras are far, while the Hulk may already
                                        * have a controller slot and be moved by the script) */

static struct {
    uint32_t actor;            /* the main actor the star was placed for (0: none yet) */
    int32_t mission;           /* 1 or 2: the tutorial it was placed in */
    int32_t settle;            /* updates the Hulk has been under control */
    int32_t placed;            /* the star is up */
    int32_t fired;             /* walked into (once per mission run) */
    uint32_t ticks;            /* updates since placed (the spin) */
    float pos[3];              /* the star's centre */
    float rest[3];             /* where the Hulk stood when the settle count began */
    uint32_t shader_core, shader_glow;   /* the pddi shaders (the device's "simple", kept) */
} g_ts GAME_STATE;

static int g_on;
static int log_level(void) {
    static int l = -1;
    if (l < 0) l = getenv("HULK_TSKIP_LOG") ? atoi(getenv("HULK_TSKIP_LOG")) : 0;
    return l;
}

void hulk_wasm_tutorial_skip_apply(int value) { g_on = value != 0; }

static uint32_t rd(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
static float rf(uint32_t a) { return *(float*)PTR(a); }

/* the tutorial being played: 1 (c00m01), 2 (c00m02), else 0 */
static int tutorial(void) {
    uint32_t game = rd(GAME_PTR), fm = game ? rd(game + 0x38) : 0;
    if (!fm || rd(fm + 0x80) != 0) return 0;
    uint32_t m = rd(fm + 0x84);
    return m == 1 || m == 2 ? (int)m : 0;
}

static uint32_t main_actor(void) {
    uint32_t w = rd(WORLD_PTR), am = w ? rd(w + 0x20) : 0;
    return am ? rd(am + 0x124) : 0;
}

static int actor_pos(uint32_t actor, float out[3]) {
    uint32_t node = rd(actor + 0x10);
    if (!node) return 0;
    uint32_t p[3] = {0, 0, 0};
    if (!(ff_call_this(FN_NODE_POS, node, 1, (uint32_t)(uintptr_t)p) & 0xff)) return 0;
    memcpy(out, p, sizeof p);
    return 1;
}

static void run_lua(const char* text) {
    static const char name[] = "=port_tutorial_skip";
    uint32_t sh = rd(SCRIPT_PTR);
    if (!sh) return;
    ff_call_this(FN_DOSTRING, sh, 2, (uint32_t)(uintptr_t)text, (uint32_t)(uintptr_t)name);
}

/* where the star goes: BEHIND units from the Hulk towards the camera, horizontally (pulling the stick back walks
 * there); without a usable camera, behind his facing */
static void place(uint32_t actor, const float hp[3]) {
    float dx = 0, dz = 0;
    uint32_t view = rd(VIEW_PTR);
    if (view) {
        dx = rf(view + 0x4c) - hp[0];
        dz = rf(view + 0x54) - hp[2];
    }
    float d = sqrtf(dx * dx + dz * dz);
    if (d < 0.5f) {       /* (the scene node's matrix: its z row is the facing) */
        uint32_t node = rd(actor + 0x10), dr = node ? rd(node + 0x18) : 0;
        dx = dr ? -rf(dr + 0x30) : 0;
        dz = dr ? -rf(dr + 0x38) : 1;
        d = sqrtf(dx * dx + dz * dz);
        if (d < 1e-3f) dx = 0, dz = 1, d = 1;
    }
    g_ts.pos[0] = hp[0] + dx / d * BEHIND;
    g_ts.pos[1] = hp[1] + LIFT;
    g_ts.pos[2] = hp[2] + dz / d * BEHIND;
    g_ts.placed = 1;
    g_ts.ticks = 0;
    if (log_level())
        fprintf(stderr, "hulk: tutorial skip: frame %u: c00m0%d star at (%.2f, %.2f, %.2f), the Hulk at (%.2f, %.2f, %.2f)\n",
                SIM->frame, g_ts.mission, (double)g_ts.pos[0], (double)g_ts.pos[1], (double)g_ts.pos[2], (double)hp[0],
                (double)hp[1], (double)hp[2]);
    if (log_level() && view)
        fprintf(stderr, "hulk: tutorial skip: camera at (%.2f, %.2f, %.2f)\n", (double)rf(view + 0x4c), (double)rf(view + 0x50), (double)rf(view + 0x54));
}

static void update(void) {
    int t = tutorial();
    uint32_t actor = t ? main_actor() : 0;
    if (!actor) {
        if (g_ts.actor || g_ts.mission) memset(&g_ts.actor, 0, offsetof(__typeof__(g_ts), pos));
        return;
    }
    if (actor != g_ts.actor || t != g_ts.mission) {    /* a new mission run (or the Hulk made again: a restart) */
        g_ts.actor = actor;
        g_ts.mission = t;
        g_ts.settle = g_ts.placed = g_ts.fired = 0;
        g_ts.ticks = 0;
    }
    float hp[3];
    if (!actor_pos(actor, hp)) return;
    uint32_t view = rd(VIEW_PTR);
    float cd = 1e9f;
    if (view) {
        float cx = rf(view + 0x4c) - hp[0], cy = rf(view + 0x50) - hp[1], cz = rf(view + 0x54) - hp[2];
        cd = sqrtf(cx * cx + cy * cy + cz * cz);
    }
    /* in play: a controller slot (-1: scripted), the game camera (the camera manager's flags, world +8 then +4:
     * none of 0x5e, cm_IsGameCameraActive 0x000997a0) close by, and no letterbox (nism_IsLetterBoxOn 0x001b9120:
     * the logic view's +0x14, both bars' floats at +0x18 / +0x28 other than 0x3f32e0's) */
    uint32_t cmgr = rd(rd(WORLD_PTR) + 8), lb = view ? rd(view + 0x14) : 0;
    int game_cam = cmgr && (rd(cmgr + 4) & 0x5e) == 0;
    int letterbox = lb && rf(lb + 0x28) != rf(0x003f32e0u) && rf(lb + 0x18) != rf(0x003f32e0u);
    int controlled = (int32_t)rd(actor + 0x20a8) >= 0 && cd < CAM_NEAR && game_cam && !letterbox;
    if (log_level() >= 2 && SIM->frame % 30 == 0)
        fprintf(stderr, "hulk: tutorial skip: frame %u c00m0%d hulk (%.2f, %.2f, %.2f) cam %.1f/%d/%d slot %d life %u sm %u%s%s\n",
                SIM->frame, t, (double)hp[0], (double)hp[1], (double)hp[2], (double)cd, game_cam, letterbox,
                (int32_t)rd(actor + 0x20a8),
                rd(actor + 0x20b0), rd(rd(WORLD_PTR) + 0x2c) ? rd(rd(rd(WORLD_PTR) + 0x2c) + 0xc) : 0,
                g_ts.placed ? " placed" : "", g_ts.fired ? " fired" : "");
    if (!g_ts.placed) {
        float rx = hp[0] - g_ts.rest[0], rz = hp[2] - g_ts.rest[2];
        if (!controlled || !g_ts.settle || rx * rx + rz * rz > 0.25f) {   /* (an intro moving him: start again) */
            memcpy(g_ts.rest, hp, sizeof g_ts.rest);
            g_ts.settle = controlled ? 1 : 0;
        } else {
            g_ts.settle++;
        }
        if (g_ts.settle >= SETTLE) place(actor, hp);
        return;
    }
    g_ts.ticks++;
    if (g_ts.fired || !controlled) return;
    float dx = hp[0] - g_ts.pos[0], dz = hp[2] - g_ts.pos[2], dy = hp[1] + LIFT - g_ts.pos[1];
    if (dx * dx + dz * dz > REACH * REACH || dy * dy > 9.0f) return;
    g_ts.fired = 1;
    if (log_level()) fprintf(stderr, "hulk: tutorial skip: c00m0%d skipped (frame %u)\n", t, SIM->frame);
    run_lua(t == 1 ? "gfm_SetMissionProgressSimple(\"c00m01\", \"complete\") gfm_SetAcquireMission(\"c00m02\") "
                     "sm_SetMissionState(MISSION_SUCCESS)"
                   : "gfm_SetNextMission(\"c01m10\") sta_AddXP(xp_awards.c00m02.complete) "
                     "sm_SetMissionState(MISSION_IMMEDIATELOAD)");
}

/* UpdateSimulation 0x00088c30 (CGame's world, thiscall (int* kind, dt)): the original, then the star's update */
void ffgo_00088c30(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_update_sim(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_00088c30(ecx, edx, st, rb);
    if (g_on) update();
}

/* ------------------------------------------------------------------------------------------- drawing */
static uint32_t vslot(uint32_t obj, int i) { return rd(rd(obj) + 4u * (uint32_t)i); }

static uint32_t K4(const char* s) {
    return (uint32_t)(uint8_t)s[0] | (uint32_t)(uint8_t)s[1] << 8 | (uint32_t)(uint8_t)s[2] << 16 |
           (s[2] ? (uint32_t)(uint8_t)s[3] << 24 : 0u);
}

static uint32_t make_shader(int blend) {
    static const char simple[] = "simple";
    uint32_t dev = rd(DEVICE_PTR);
    if (!dev) return 0;
    uint32_t sh = ff_call_this(vslot(dev, 11), dev, 2, (uint32_t)(uintptr_t)simple, 0u);
    if (!sh) return 0;
    ff_call_this(vslot(sh, 0), sh, 0);                       /* AddRef: kept */
    ff_call_this(vslot(sh, 6), sh, 2, K4("BLMD"), (uint32_t)blend);
    ff_call_this(vslot(sh, 6), sh, 2, K4("LIT"), 0u);
    ff_call_this(vslot(sh, 6), sh, 2, K4("2SID"), 1u);
    return sh;
}

typedef struct { float p[3]; uint32_t c; } tvert;

/* one prim stream of triangles (pddi: kind 0, vertex flags 0x20 one colour) */
static void draw_tris(uint32_t ctx, uint32_t shader, const tvert* v, int n) {
    uint32_t s = ff_call_this(vslot(ctx, 30), ctx, 5, shader, 0u, 0x20u, (uint32_t)n, 0u);
    if (!s) return;
    for (int i = 0; i < n; i++) {
        memcpy(PTR(rd(s + 8)), v[i].p, 12);
        *(uint32_t*)PTR(rd(s + 0x10)) = v[i].c;
        ff_call_this(FN_VERTEX, s, 0);
    }
    ff_call_this(vslot(ctx, 31), ctx, 1, s);
}

static uint32_t argb(float a, float r, float g, float b) {
    #define B8(x) ((uint32_t)((x) <= 0 ? 0 : (x) >= 1 ? 255 : (int)((x) * 255.0f + 0.5f)))
    return B8(a) << 24 | B8(r) << 16 | B8(g) << 8 | B8(b);
    #undef B8
}

/* the render context ctx's camera (World::Render's argument); called after World::Render */
void hulk_wasm_tutorial_skip_draw(uint32_t rctx) {
    if (!g_on || !g_ts.placed || g_ts.fired || tutorial() != g_ts.mission || main_actor() != g_ts.actor) return;
    uint32_t ctx = rd(CONTEXT_PTR);
    if (!ctx) return;
    if (!g_ts.shader_core) g_ts.shader_core = make_shader(0);
    if (!g_ts.shader_glow) g_ts.shader_glow = make_shader(2);
    if (!g_ts.shader_core || !g_ts.shader_glow) return;

    float t = (float)g_ts.ticks / 30.0f;
    float c[3] = {g_ts.pos[0], g_ts.pos[1] + 0.25f * sinf(t * 2.0f), g_ts.pos[2]};
    float yaw = t * 2.4f, cy = cosf(yaw), sy = sinf(yaw);
    float pulse = 0.5f + 0.5f * sinf(t * 4.0f);

    /* the star: five points (outer radius R, inner r) in its own xy plane, extruded to apexes at +-D on z, spun
     * about the vertical; each face is shaded by a fixed light so the spin reads */
    enum { PTS = 5, RIM = 2 * PTS };
    const float R = 0.8f, r = 0.34f, D = 0.26f;
    float rim[RIM][3];
    for (int i = 0; i < RIM; i++) {
        float a = 3.14159265f * 0.5f + (float)i * 3.14159265f / PTS, rr = (i & 1) ? r : R;
        float x = rr * cosf(a), y = rr * sinf(a);
        rim[i][0] = c[0] + x * cy;
        rim[i][1] = c[1] + y;
        rim[i][2] = c[2] + x * sy;
    }
    float apex[2][3] = {{c[0] - D * sy, c[1], c[2] + D * cy}, {c[0] + D * sy, c[1], c[2] - D * cy}};
    const float L[3] = {0.45f, 0.75f, -0.48f};
    tvert v[4 * RIM * 3];
    int n = 0;
    for (int side = 0; side < 2; side++)
        for (int i = 0; i < RIM; i++) {
            const float* a = rim[i];
            const float* b = rim[(i + 1) % RIM];
            const float* p = apex[side];
            float e1[3] = {a[0] - p[0], a[1] - p[1], a[2] - p[2]}, e2[3] = {b[0] - p[0], b[1] - p[1], b[2] - p[2]};
            float nx = e1[1] * e2[2] - e1[2] * e2[1], ny = e1[2] * e2[0] - e1[0] * e2[2], nz = e1[0] * e2[1] - e1[1] * e2[0];
            float nl = sqrtf(nx * nx + ny * ny + nz * nz);
            float k = nl > 0 ? fabsf(nx * L[0] + ny * L[1] + nz * L[2]) / nl : 0.5f;
            float s = 0.55f + 0.45f * k;
            uint32_t col = argb(1, 1.0f * s, (0.80f + 0.15f * pulse) * s, 0.25f * s);
            v[n++] = (tvert){{p[0], p[1], p[2]}, argb(1, 1, 1, 0.75f)};
            v[n++] = (tvert){{a[0], a[1], a[2]}, col};
            v[n++] = (tvert){{b[0], b[1], b[2]}, col};
        }
    draw_tris(ctx, g_ts.shader_core, v, n);

    /* the glow: a disc facing the camera, bright at the centre and fading to nothing (added), and a faint beam */
    float cam[3] = {c[0], c[1], c[2] + 1};
    uint32_t cp = rctx ? ff_call_this(FN_CAM_POS, rctx, 0) : 0;
    if (cp) cam[0] = rf(cp), cam[1] = rf(cp + 4), cam[2] = rf(cp + 8);
    float f[3] = {cam[0] - c[0], cam[1] - c[1], cam[2] - c[2]};
    float fl = sqrtf(f[0] * f[0] + f[1] * f[1] + f[2] * f[2]);
    if (fl < 1e-3f) return;
    f[0] /= fl, f[1] /= fl, f[2] /= fl;
    float ux[3] = {f[2], 0, -f[0]};                 /* horizontal, across the view */
    float ul = sqrtf(ux[0] * ux[0] + ux[2] * ux[2]);
    if (ul < 1e-3f) ux[0] = 1, ux[2] = 0, ul = 1;
    ux[0] /= ul, ux[2] /= ul;
    float uy[3] = {f[1] * ux[2] - f[2] * ux[1], f[2] * ux[0] - f[0] * ux[2], f[0] * ux[1] - f[1] * ux[0]};
    enum { SEG = 24 };
    tvert g[SEG * 3 + 12];
    int m = 0;
    float gr = 1.5f + 0.2f * pulse;
    uint32_t centre = argb(1, 0.40f, 0.32f, 0.08f), edge = argb(0, 0, 0, 0);
    float o[3] = {c[0] + f[0] * 0.6f, c[1] + f[1] * 0.6f, c[2] + f[2] * 0.6f};   /* (in front of the star) */
    for (int i = 0; i < SEG; i++) {
        float a0 = 6.2831853f * (float)i / SEG, a1 = 6.2831853f * (float)(i + 1) / SEG;
        float c0 = cosf(a0) * gr, s0 = sinf(a0) * gr, c1 = cosf(a1) * gr, s1 = sinf(a1) * gr;
        g[m++] = (tvert){{o[0], o[1], o[2]}, centre};
        g[m++] = (tvert){{o[0] + ux[0] * c0 + uy[0] * s0, o[1] + ux[1] * c0 + uy[1] * s0, o[2] + ux[2] * c0 + uy[2] * s0}, edge};
        g[m++] = (tvert){{o[0] + ux[0] * c1 + uy[0] * s1, o[1] + ux[1] * c1 + uy[1] * s1, o[2] + ux[2] * c1 + uy[2] * s1}, edge};
    }
    /* the beam: a vertical strip from the ground to 12 units up, bright at the bottom */
    float bw = 0.22f, y0 = g_ts.pos[1] - LIFT, y1 = y0 + 12.0f;
    uint32_t bb = argb(1, 0.22f, 0.18f, 0.04f), bt = argb(0, 0, 0, 0);
    float bx0 = c[0] - ux[0] * bw, bz0 = c[2] - ux[2] * bw, bx1 = c[0] + ux[0] * bw, bz1 = c[2] + ux[2] * bw;
    g[m++] = (tvert){{bx0, y0, bz0}, bb};
    g[m++] = (tvert){{bx1, y0, bz1}, bb};
    g[m++] = (tvert){{bx1, y1, bz1}, bt};
    g[m++] = (tvert){{bx0, y0, bz0}, bb};
    g[m++] = (tvert){{bx1, y1, bz1}, bt};
    g[m++] = (tvert){{bx0, y1, bz0}, bt};
    /* (added light writes no depth: the Hulk behind it still draws; the context's z write as it was afterwards) */
    uint32_t zw = ff_call_this(vslot(ctx, 63), ctx, 0) & 0xff;
    ff_call_this(vslot(ctx, 62), ctx, 1, 0u);
    draw_tris(ctx, g_ts.shader_glow, g, m);
    ff_call_this(vslot(ctx, 62), ctx, 1, zw);
}
