// HULK_GFX_STATS=N (wprof1; docs/wasm-port.md "Profile"): the app runner's graphics statistics, averaged and logged
// every N updates (draws, uploads, time in the sink imports, bgfx's stats, the pacing waits). Off: one test a call.
#pragma once
#include <stdint.h>
#include "pddi/draw_sink.h"

enum GsCat { kGsDraw, kGsTransient, kGsBuffers, kGsTextures, kGsPass, kGsFrame, kGsPresent, kGsOther, kGsCats };
extern int g_gsOn;             // -1 until HULK_GFX_STATS is read, then 0 / 1
int gs_init();
inline bool gs_enabled() { return g_gsOn < 0 ? gs_init() != 0 : g_gsOn != 0; }
uint64_t gs_now();
void gs_time(int cat, uint64_t t0);
void gs_draw(const hulk::pddi::DrawPacket& p);
void gs_transient(uint32_t count);
void gs_vb(uint32_t vid, uint32_t count);
void gs_ib(uint32_t vid, uint32_t count);
void gs_tex(int create, uint32_t bytes);
void gs_pass();
void gs_fx();
void gs_wait(int64_t lateNs, int64_t spinNs);   // a pacing wait: how late it woke, how long it yielded
void gs_frame_end();     // after the update's frame end

struct GsScope {
    int cat;
    uint64_t t0;
    explicit GsScope(int c) : cat(c), t0(gs_enabled() ? gs_now() : 0) {}
    ~GsScope() { if (t0) gs_time(cat, t0); }
};
#define GS_SCOPE(c) GsScope gs_scope_(c)
