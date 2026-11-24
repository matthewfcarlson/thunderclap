/* The draw-distance setting (port_settings.c `draw_distance`, wvid1; docs/wasm-port.md "Draw distance"; HULK_WASM_GFX=1
 * builds only).
 *
 * World::Render 0x001c88f0 (src/game/Render/LevelLoader.cpp) draws the resident rooms within a horizontal distance:
 * a room fades out from 0x4c53bc (270) over 0x4c53c4 (25) units and is skipped beyond their sum (docs/remaster.md 3.1).
 * Nothing else reads the two floats, so an entry hook (tools/wasm_port.py GFX_APP_HOOKS) sets them to the setting's
 * values while World::Render runs and puts the original's back when it returns: the game's .data holds 270 / 25 at
 * every other moment (a snapshot, the game hash, every other reader). The band scales with the start (25/270). The
 * near-volume radius 0x4c53c0 (150: rooms whose lights reach the view) stays.
 *
 * What it changes besides the picture: World::Render's own render-only words (a room's fade f58, written 0 only, and
 * the list of rooms drawn this frame at +0x54c, which nothing reads: its only writers are 0x1c6800, 0x1c88f0 and the
 * constructor 0x1c9030) and the front end's state for the extra draws. Rooms the game has not loaded never appear:
 * the streaming budget decides what is resident (the far-field layer is a later remaster stage, remaster.md 3.3).
 * HULK_DRAWDIST_LOG=N logs every N frames the resident rooms' horizontal distances from the camera. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"

#define FADE_START 0x004c53bcu
#define FADE_BAND 0x004c53c4u
static int g_start = 270;

/* HULK_DRAWDIST_FORCE=N (tests): the hook uses N whatever the setting, so runs whose menus hold the same values
 * compare the hook alone */
void hulk_wasm_draw_distance_apply(int value) {
    const char* f = getenv("HULK_DRAWDIST_FORCE");
    if (f && *f) value = atoi(f);
    g_start = value >= 270 && value <= 4000 ? value : 270;
}

static void log_rooms(uint32_t mgr, uint32_t ctx) {
    static int every = -1;
    if (every < 0) every = getenv("HULK_DRAWDIST_LOG") ? atoi(getenv("HULK_DRAWDIST_LOG")) : 0;
    if (every <= 0 || SIM->frame % (uint32_t)every) return;
    const float* cam = (const float*)PTR(ff_call_this(0x001c1300u, ctx, 0));
    int count = *(int*)PTR(mgr + 0x28);
    uint32_t list = *(uint32_t*)PTR(mgr + 0x2c);
    int n = 0, near = 0, mid = 0, far = 0;
    float maxd = 0;
    for (int i = 0; i <= count && list; i++) {
        uint32_t it = ((uint32_t*)PTR(list))[i];
        if (!it || !*(uint8_t*)PTR(it + 8)) continue;
        const float* q = (const float*)PTR(ff_call_this(0x001c63e0u, it, 0));
        float dx = cam[0] - q[0], dz = cam[2] - q[2], d = sqrtf(dx * dx + dz * dz);
        n++;
        if (d < 295) near++;
        else if (d < 600) mid++;
        else far++;
        if (d > maxd) maxd = d;
    }
    fprintf(stderr, "hulk: frame %u: rooms resident %d: <295 %d, 295-600 %d, >600 %d, farthest %.0f (drawn %d)\n",
            SIM->frame, n, near, mid, far, (double)maxd, *(int*)PTR(mgr + 0x54c));
}

void ffgo_001c88f0(uint32_t, uint32_t, void*, void*);   /* World::Render (the hook's original) */
void hulk_wasm_tutorial_skip_draw(uint32_t ctx);         /* tutorial_skip.c: the star, after the rooms */
void hulk_wasm_traversal_draw(uint32_t ctx);             /* traversal.c: the charge-sprint glow (wtrav2) */
void hulk_wasm_coop_view_restore(void);                  /* coop.c: the local view's camera ends with the rooms' drawing
                                                          * (before the next GameClock::Update's checkpoint, wcoop1) */
void ffh_hulk_app_world_render(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (g_start == 270) {
        ffgo_001c88f0(ecx, edx, st, rb);
        log_rooms(ecx, ARG(0));
        hulk_wasm_tutorial_skip_draw(ARG(0));
        hulk_wasm_traversal_draw(ARG(0));
        hulk_wasm_coop_view_restore();
        return;
    }
    float* start = (float*)PTR(FADE_START);
    float* band = (float*)PTR(FADE_BAND);
    float s0 = *start, b0 = *band;
    *start = (float)g_start;
    *band = b0 * (float)g_start / 270.0f;
    ffgo_001c88f0(ecx, edx, st, rb);
    *start = s0;
    *band = b0;
    log_rooms(ecx, ARG(0));
    hulk_wasm_tutorial_skip_draw(ARG(0));
    hulk_wasm_traversal_draw(ARG(0));
    hulk_wasm_coop_view_restore();
}
