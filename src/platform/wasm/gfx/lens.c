/* Lens effects' view of the game (wlens1, D249; run/app/lens.cpp, docs/hdr-shadows.md "Lens effects"; HULK_WASM_GFX=1
 * builds only).
 *
 * The runner's lens pass needs two facts it cannot see in the draw stream: whether an in-engine cutscene is playing
 * (the depth of field is for cutscenes only) and how hard the camera is shaking (the chromatic aberration is for big
 * impacts only). Both are read here, in the module, and handed to the runner at each present as one packed word
 * through the gfx_quality import (what 0x101, caught in app.cpp; not an rm::Quality row), as the menus' scroll arrows
 * are (fe_options.c, wmenu2). Picture only: nothing here writes game memory, and the word's last value is host state
 * (the runner keeps its own copy; neither is game state).
 *
 *   bit 0       letterbox: nism_IsLetterBoxOn's test (tutorial_skip.c, wskip1): the logic view's +0x14, both bars'
 *               floats at +0x18 / +0x28 other than 0x3f32e0's (the bars' rest value)
 *   bit 1       the game camera is not active (the camera manager's flags, world +8 then +4: one of 0x5e,
 *               cm_IsGameCameraActive 0x000997a0): a scripted, NIS or dramatic camera
 *   bit 2       the main actor has no controller slot (actor +0x20a8 < 0: scripted)
 *   bits 8..15  the camera's translation shake, 0.02 units a step: the largest amplitude x exp(-t) of the active
 *               CGameCamera's shakes 0..2 (CGameCamera::vfunc_35 0x000a97e0: this +0xf4 + 16i time, duration,
 *               amplitude, frequency; offset = sin(t f) exp(-t) amplitude)
 *   bits 16..23 its rotation shake (shakes 3..5, degrees), 0.04 degrees a step
 *
 * and, as what 0x102 / 0x103 / 0x104 (float bits), the main actor's position (world units; the depth of field's
 * subject when he is in the shot): his scene node (actor +0x10) read as FUN_00059a50 reads it (node +0x18 a parent
 * transform: its +0x40; else node +0x4), without calling it. Sent while the letterbox is up, else zeros.
 *
 * The shake is read by an entry hook on CGameCamera::vfunc_35 (wasm_port.GFX_APP_HOOKS; every caller is a derived
 * camera's update in another TU), after the original, so the values are the update's own. HULK_LENS_LOG=1 logs the
 * word's changes of bits 0..2 and each update's shake while one is active. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"

#define VIEW_PTR 0x004e231cu           /* the logic view (+0x14 the letterbox) */
#define WORLD_PTR 0x004dd700u          /* +0x8 the camera manager, +0x20 the actor manager (+0x124 the main actor) */
#define BAR_REST 0x003f32e0u           /* the bars' rest value */

static uint32_t rd(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
static float rf(uint32_t a) { return *(float*)PTR(a); }

static int log_on(void) {
    static int l = -1;
    if (l < 0) l = getenv("HULK_LENS_LOG") ? atoi(getenv("HULK_LENS_LOG")) : 0;
    return l;
}

static uint32_t g_shake;               /* this update's shake bits (8..23), host state */

/* CGameCamera::vfunc_35 0x000a97e0 (thiscall: the camera's update (arg, dt, unused, draw)): the original, then the
 * shakes it advanced */
void ffgo_000a97e0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_camera_update(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_000a97e0(ecx, edx, st, rb);
    if (!ecx) return;
    float tr = 0.0f, rot = 0.0f;
    for (uint32_t i = 0; i < 6; i++) {
        uint32_t s = ecx + 0xf4u + 16u * i;
        float t = rf(s), dur = rf(s + 4), amp = fabsf(rf(s + 8));
        if (!(dur > 0.0f) || !(t >= 0.0f) || !(amp < 1e6f)) continue;
        float v = amp * expf(-t);
        if (i < 3) tr = v > tr ? v : tr;
        else rot = v > rot ? v : rot;
    }
    uint32_t qt = (uint32_t)fminf(tr / 0.02f + 0.5f, 255.0f), qr = (uint32_t)fminf(rot / 0.04f + 0.5f, 255.0f);
    uint32_t w = qt << 8 | qr << 16;
    if (w > g_shake) g_shake = w;      /* (one call an update; the larger if more) */
    if (log_on() && (qt || qr))
        fprintf(stderr, "hulk: lens: frame %u: shake %.3f units %.3f deg\n", SIM->frame, (double)tr, (double)rot);
}

/* the packed word (above), at each present (gfx.c); the shake bits are the last update's */
uint32_t hulk_wasm_lens_state(void) {
    uint32_t view = rd(VIEW_PTR), lb = view ? rd(view + 0x14) : 0;
    int letterbox = lb && rf(lb + 0x28) != rf(BAR_REST) && rf(lb + 0x18) != rf(BAR_REST);
    uint32_t w = rd(WORLD_PTR), cmgr = w ? rd(w + 8) : 0;
    int scripted_cam = cmgr && (rd(cmgr + 4) & 0x5e) != 0;
    uint32_t am = w ? rd(w + 0x20) : 0, actor = am ? rd(am + 0x124) : 0;
    int no_slot = actor && (int32_t)rd(actor + 0x20a8) < 0;
    uint32_t v = (uint32_t)letterbox | (uint32_t)scripted_cam << 1 | (uint32_t)no_slot << 2 | g_shake;
    g_shake = 0;
    static uint32_t logged = ~0u;
    if (log_on() && (v & 7) != logged) {
        fprintf(stderr, "hulk: lens: frame %u: letterbox %u scripted camera %u no slot %u\n", SIM->frame, v & 1,
                v >> 1 & 1, v >> 2 & 1);
        logged = v & 7;
    }
    return v;
}

/* the main actor's position (above) into out[3]; 0: none */
int hulk_wasm_lens_subject(float out[3]) {
    uint32_t w = rd(WORLD_PTR), am = w ? rd(w + 0x20) : 0, actor = am ? rd(am + 0x124) : 0;
    uint32_t node = actor ? rd(actor + 0x10) : 0;
    if (!node) return 0;
    uint32_t t = rd(node + 0x18), at = t ? t + 0x40 : node + 4;
    for (int i = 0; i < 3; i++) out[i] = rf(at + 4u * (uint32_t)i);
    return 1;
}
