/* The module's side of the app's graphics, window and input (docs/wasm-port.md "The macOS app"; HULK_WASM_GFX=1
 * builds only: tools/wasm_port.py links this directory and tools/wasm_gfx.py's pddi front end).
 *
 * - d3dCreateDevice (0x0031ba60, an entry hook): with a renderer (HULK_GFX_RENDERER: metal, noop, ...) the pddi front
 *   end makes the device (hulk_pddi_create_device) and every pddi object the game creates from it is the front end's;
 *   with `null` (or none) the game's own d3d layer runs on d3d_null.c as in the headless build. HulkShaderCallback's
 *   dynamic_cast of the effects extension (0x001c1a40 -> 0x00344e74, a site hook) takes the same switch.
 * - The draw sink (bgfx_bridge.h): each hulk_gfx_sink_* is a `hulk` import gfx_*; the runner converts the packets'
 *   wasm32 pointers (src/platform/wasm/run/app/app.cpp). bgfx's transient vertices are written here, in a staging
 *   buffer, and copied over by the runner before its next sink call.
 * - The window and its events (platform_events.h) are the runner's: plat_* imports.
 * - The end of a presented frame (sdl_platform.cpp platformAfterFrame): what d3d_null.c's Swap does (the vblank
 *   callback, ff_frame_end: the virtual clock), then the runner's pad for port 0 when it has a window and no replay
 *   or HULK_INPUT drives the pad.
 * - The front end's operator new / delete and C allocations: the game arena, so a snapshot carries its objects; its
 *   statics are in a data section the snapshot carries too (ff_gfx_state), with the resource table below. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "port_settings.h"

#define GI(name) __attribute__((import_module("hulk"), import_name(#name)))

/* ------------------------------------------------------------------------------------------- the runner's imports */
GI(gfx_abi) uint32_t gi_abi(const uint32_t* table, uint32_t n);
GI(gfx_renderer) int32_t gi_renderer(const char* name);
GI(gfx_init) uint32_t gi_init(const void* init);
GI(gfx_shutdown) void gi_shutdown(void);
GI(gfx_up) uint32_t gi_up(void);
GI(gfx_name) uint32_t gi_name(char* buf, uint32_t cap);
GI(gfx_caps) void gi_caps(void* out);
GI(gfx_resize_back_buffer) void gi_resize_back_buffer(uint32_t w, uint32_t h);
GI(gfx_frame_targets) uint32_t gi_frame_targets(uint32_t w, uint32_t h);
GI(gfx_offscreen) uint32_t gi_offscreen(void);
GI(gfx_scene_target) uint32_t gi_scene_target(void);
GI(gfx_target_width) uint32_t gi_target_width(void);
GI(gfx_target_height) uint32_t gi_target_height(void);
GI(gfx_destroy_frame_targets) void gi_destroy_frame_targets(void);
/* resources by the module's ids (vids: "resources" below); the runner maps each to its sink's objects */
GI(gfx_create_texture) uint32_t gi_create_texture(uint32_t vid, const void* desc);
GI(gfx_update_texture) uint32_t gi_update_texture(uint32_t vid, uint32_t level, uint32_t w, uint32_t h,
                                                  const void* data, uint32_t pitch, uint32_t size);
GI(gfx_update_vertex_buffer) uint32_t gi_update_vertex_buffer(uint32_t vid, const void* data);
GI(gfx_update_index_buffer) uint32_t gi_update_index_buffer(uint32_t vid, const uint16_t* idx, uint32_t n, uint32_t owner);
GI(gfx_create_target) uint32_t gi_create_target(uint32_t vid, uint32_t fb, uint32_t w, uint32_t h, uint32_t render);
GI(gfx_create_query) uint32_t gi_create_query(uint32_t vid);
GI(gfx_destroy) void gi_destroy(uint32_t vid);
GI(gfx_alloc_transient) uint32_t gi_alloc_transient(uint32_t count, uint32_t* token, void* staging);
GI(gfx_frame_copy) uint32_t gi_frame_copy(uint32_t vid, uint32_t fb);
GI(gfx_front_buffer) uint32_t gi_front_buffer(uint32_t vid);
GI(gfx_set_pass) void gi_set_pass(const void* pass);
GI(gfx_copy_frame) void gi_copy_frame(uint32_t pass, const void* dst);
GI(gfx_draw_resources) uint32_t gi_draw_resources(void);
GI(gfx_has_vertex_program) uint32_t gi_has_vertex_program(uint32_t vp);
GI(gfx_prepare_pipeline) uint32_t gi_prepare_pipeline(void* packet);
GI(gfx_submit_draw) void gi_submit_draw(const void* packet);
GI(gfx_combiner_stats) void gi_combiner_stats(int32_t* generated, int32_t* generic, int32_t* draws);
GI(gfx_fx_resources) uint32_t gi_fx_resources(void);
GI(gfx_fx_draw) void gi_fx_draw(const void* packet);
GI(gfx_query_result) uint32_t gi_query_result(uint32_t q, int32_t* pixels);
GI(gfx_present) void gi_present(const void* p);
GI(gfx_frame) void gi_frame(void);
GI(gfx_request_screenshot) void gi_request_screenshot(const char* path);
GI(gfx_context_destroyed) void gi_context_destroyed(void);
GI(gfx_render_res) void gi_render_res(int32_t value);
GI(gfx_display_aspect) void gi_display_aspect(uint32_t num, uint32_t den);
GI(gfx_fog) void gi_fog(int32_t value);
GI(gfx_quality) void gi_quality(uint32_t what, int32_t value);
GI(gfx_texpack_list) uint32_t gi_texpack_list(char* buf, uint32_t cap);
GI(gfx_texpack) void gi_texpack(uint32_t value);
GI(plat_video_init) int32_t gi_video_init(void);
GI(plat_error) uint32_t gi_error(char* buf, uint32_t cap);
GI(plat_create_window) int32_t gi_create_window(const char* title, int32_t w, int32_t h, int32_t hidden, int32_t resizable);
GI(plat_pump) void gi_pump(void);
GI(plat_quit_requested) int32_t gi_quit_requested(void);
GI(plat_has_focus) int32_t gi_has_focus(void);
GI(plat_is_fullscreen) int32_t gi_is_fullscreen(void);
GI(plat_toggle_fullscreen) int32_t gi_toggle_fullscreen(void);
GI(plat_resized) int32_t gi_resized(int32_t* w, int32_t* h);
GI(plat_sleep_ms) void gi_sleep_ms(uint32_t ms);
GI(plat_pad) int32_t gi_pad(uint32_t port, uint8_t* out18);
GI(plat_pace) void gi_pace(uint32_t fields);
GI(plat_display_rate) void gi_display_rate(uint32_t rate);
GI(gfx_discontinuity) void gi_discontinuity(void);

/* the layout of the packets the runner reads (draw_sink.h as this module lays it out: gfx_abi.cpp) */
uint32_t hulk_wasm_gfx_abi(uint32_t* table, uint32_t cap);

/* ------------------------------------------------------------------------------------------- the device switch */
static int gfx_mode = -1;      /* 1: the pddi front end draws (a renderer), 0: the game's d3d layer on d3d_null.c */
int hulk_wasm_gfx_on(void) {
    if (gfx_mode < 0) {
        const char* r = getenv("HULK_GFX_RENDERER");
        gfx_mode = r && *r && strcmp(r, "null") != 0;
    }
    return gfx_mode;
}

int hulk_pddi_create_device(int major, int minor, void** out);
void ffgo_0031ba60(uint32_t, uint32_t, void*, void*);   /* the game's d3dCreateDevice (the hook's original) */
void ffg_00344e74(uint32_t, uint32_t, void*, void*);    /* __RTDynamicCast (rtti.c) */

void ffh_hulk_gfx_create_device(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (!hulk_wasm_gfx_on()) {
        ffgo_0031ba60(ecx, edx, st, rb);
        return;
    }
    static uint32_t table[64];
    uint32_t n = hulk_wasm_gfx_abi(table, 64);
    if (!gi_abi(table, n))
        ff_fatal("gfx: the runner lays out the draw packets differently (src/platform/wasm/gfx/gfx_abi.cpp)");
    RET(hulk_pddi_create_device((int)ARG(0), (int)ARG(1), PTR(ARG(2))));
}
/* HulkShaderCallback (0x001c1a40)'s dynamic_cast of the pddi effects extension: with the front end, ours is that
 * type (the Wine link's _hulk_cast_self) */
void ffh_hulk_cast_self(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (!hulk_wasm_gfx_on()) {
        ffg_00344e74(ecx, edx, st, rb);
        return;
    }
    RET(ARG(0));
}

/* ------------------------------------------------------------------------------------------- the sink */
int32_t hulk_gfx_renderer(const char* name) { return gi_renderer(name); }
uint32_t hulk_gfx_sink_init(const void* init) { return gi_init(init); }
void hulk_gfx_sink_shutdown(void) { gi_shutdown(); }
uint32_t hulk_gfx_sink_up(void) { return gi_up(); }
const char* hulk_gfx_sink_name(void) {
    static char name[64];
    gi_name(name, sizeof name);
    return name;
}
void hulk_gfx_sink_caps(void* out) { gi_caps(out); }
void hulk_gfx_sink_resize_back_buffer(uint32_t w, uint32_t h) { gi_resize_back_buffer(w, h); }
uint32_t hulk_gfx_sink_frame_targets(uint32_t w, uint32_t h) { return gi_frame_targets(w, h); }
uint32_t hulk_gfx_sink_offscreen(void) { return gi_offscreen(); }
uint32_t hulk_gfx_sink_scene_target(void) { return gi_scene_target(); }
uint32_t hulk_gfx_sink_target_width(void) { return gi_target_width(); }
uint32_t hulk_gfx_sink_target_height(void) { return gi_target_height(); }
void hulk_gfx_sink_destroy_frame_targets(void) { gi_destroy_frame_targets(); }
/* ------------------------------------------------------------------------------------------- resources (wroll1)
 * The front end names its sink objects by ids this module gives out (vids), never the runner's: a vid and what it
 * stands for (the texture's description and the CPU copies of its levels, a prim buffer's copies, a target's size)
 * are kept in `vt`, in the front end's state section (tools/wasm_gfx.py STATE_SECTION), so a snapshot carries them
 * with the objects that hold the vids, and the game state never holds an id whose value follows the runner's history.
 * Every change to a vid takes a new stamp from a counter in the same section. `hs` (outside the state) mirrors what
 * the runner holds: each vid's kind and the stamp of its last change there. A restore puts `vt` back and leaves `hs`:
 * every vid whose stamps differ (made, changed or destroyed since the snapshot, or changed on a timeline the restore
 * dropped) is made again in the runner from the restored copies (gfx_restored), the rest is left alone. Stamps rise
 * along a run and a restore returns to an earlier point of it, so a stamp both sides hold names the same contents. */
#define GS __attribute__((section("hulk_pddi_state")))
#define NVID 16384u
#define VID_FIRST 4u                /* 1..3: the sink's own targets (the frame copy's texture and frame buffer, the
                                     * front buffer), whatever the runner's ids for them are at the time */
#define KNONE 0xffffu               /* draw_sink.h kSinkNone */
enum { V_FREE, V_TEX, V_VB, V_IB, V_TGT, V_FB, V_QUERY };
typedef struct {
    uint8_t kind, pad[3];
    uint32_t stamp;
    /* V_TEX: SinkTextureDesc (6 words), the level table (arena: 16 x {data, w, h, pitch, size}), levels uploaded
     * V_VB: packed copy, count, owner, stride, flags, prim kind; V_IB: indices, count, owner
     * V_TGT: w, h, render (1) or copy (0) target, its frame buffer's vid; V_FB: its target's vid */
    uint32_t a[8];
} vrec;
GS static vrec vt[NVID];
GS static uint32_t v_stamp, v_hint;
typedef struct { uint8_t kind, pad[3]; uint32_t stamp, pair; } hrec;     /* pair: a target's other vid */
static hrec hs[NVID];
static uint32_t n_fails;

extern char __start_hulk_pddi_state[], __stop_hulk_pddi_state[];
uint32_t ff_gfx_state(uint32_t* lo) {
    if (!hulk_wasm_gfx_on()) return 0;
    *lo = (uint32_t)(uintptr_t)__start_hulk_pddi_state;
    return (uint32_t)(__stop_hulk_pddi_state - __start_hulk_pddi_state);
}
uint64_t ff_gfx_hash(void) {
    uint32_t lo, n = ff_gfx_state(&lo);
    uint64_t h = 0xcbf29ce484222325ull;
    for (uint32_t i = 0; i < n; i++) h = (h ^ ((const uint8_t*)PTR(lo))[i]) * 0x100000001b3ull;
    return h;
}

static uint32_t v_alloc(int kind) {
    for (uint32_t k = 0; k < NVID - VID_FIRST; k++) {
        uint32_t v = VID_FIRST + (v_hint + k) % (NVID - VID_FIRST);
        if (vt[v].kind == V_FREE) {
            memset(&vt[v], 0, sizeof vt[v]);
            vt[v].kind = (uint8_t)kind;
            v_hint = v + 1 - VID_FIRST;
            return v;
        }
    }
    ff_fatal("gfx: more than %u sink objects", NVID - VID_FIRST);
}
static vrec* v_get(uint32_t v, int kind) { return v >= VID_FIRST && v < NVID && vt[v].kind == kind ? &vt[v] : 0; }
/* the runner now holds V as the module describes it */
static void v_sent(uint32_t v) {
    hs[v].kind = vt[v].kind;
    hs[v].stamp = vt[v].stamp;
    hs[v].pair = vt[v].kind == V_TGT ? vt[v].a[3] : vt[v].kind == V_FB ? vt[v].a[0] : 0;
}
/* the runner no longer holds V (nor, for a target, its other half) */
static void v_dropped(uint32_t v) {
    uint32_t p = hs[v].pair;
    if ((hs[v].kind == V_TGT || hs[v].kind == V_FB) && p < NVID && hs[p].pair == v) memset(&hs[p], 0, sizeof hs[p]);
    memset(&hs[v], 0, sizeof hs[v]);
}
static void v_free(uint32_t v) {
    if (vt[v].kind == V_TEX && vt[v].a[6]) ff_arena_free(PTR(vt[v].a[6]));
    memset(&vt[v], 0, sizeof vt[v]);
    if (v - VID_FIRST < v_hint) v_hint = v - VID_FIRST;
}
static void fail(const char* what, uint32_t v) {
    if (n_fails++ < 8) fprintf(stderr, "gfx: the runner refused %s %u\n", what, v);
}

/* (the runner's objects for V made from the record: a restore's reconciliation) */
void hulk_pddi_convert_packed(const void* packed, uint32_t count, uint32_t flags, void* out);   /* bgfx_draw.cpp */
typedef struct { uint32_t vertices, count, owner, packed, packedStride, vertexFlags, primKind; } wvdata;
static void send_vb(uint32_t v, void* conv) {
    vrec* r = &vt[v];
    wvdata d = {(uint32_t)(uintptr_t)conv, r->a[1], r->a[2], r->a[0], r->a[3], r->a[4], r->a[5]};
    if (!gi_update_vertex_buffer(v, &d)) fail("a vertex buffer", v);
}
static void remake(uint32_t v) {
    vrec* r = &vt[v];
    switch (r->kind) {
    case V_TEX: {
        if (!gi_create_texture(v, r->a)) fail("a texture", v);
        const uint32_t* lv = PTR(r->a[6]);
        for (uint32_t l = 0; l < 16; l++)
            if (r->a[7] & (1u << l)) gi_update_texture(v, l, lv[5 * l + 1], lv[5 * l + 2], PTR(lv[5 * l]), lv[5 * l + 3], lv[5 * l + 4]);
        break;
    }
    case V_VB: {
        void* conv = malloc((size_t)r->a[1] * 80u);       /* (host memory: the restored state is not touched) */
        if (!conv) ff_fatal("gfx: no room to convert %u vertices", r->a[1]);
        hulk_pddi_convert_packed(PTR(r->a[0]), r->a[1], r->a[4], conv);
        send_vb(v, conv);
        free(conv);
        break;
    }
    case V_IB:
        if (!gi_update_index_buffer(v, PTR(r->a[0]), r->a[1], r->a[2])) fail("an index buffer", v);
        break;
    case V_TGT:
        if (!gi_create_target(v, r->a[3], r->a[0], r->a[1], r->a[2])) fail("a target", v);
        v_sent(r->a[3]);
        break;
    case V_QUERY:
        if (!gi_create_query(v)) fail("a query", v);
        break;
    }
    v_sent(v);
}
static int v_same(uint32_t v) { return hs[v].kind == vt[v].kind && hs[v].stamp == vt[v].stamp; }
static uint32_t n_restores;
extern unsigned int hulk_native_frame_no;
int hulk_wasm_frame_rate(void);
void ff_gfx_restored(void) {
    if (!hulk_wasm_gfx_on()) return;
    hulk_native_frame_no = SIM->frame;      /* (the platform layer's frame number: screenshots by game frame) */
    uint32_t remade = 0, dropped = 0;
    /* what the runner holds and the restored state doesn't describe so: gone (a target with its frame buffer) */
    for (uint32_t v = VID_FIRST; v < NVID; v++) {
        if (hs[v].kind == V_FREE || v_same(v)) continue;
        gi_destroy(v);
        v_dropped(v);
        dropped++;
    }
    /* what the restored state describes and the runner doesn't hold: made again */
    for (uint32_t v = VID_FIRST; v < NVID; v++)
        if (vt[v].kind != V_FREE && vt[v].kind != V_FB && hs[v].kind == V_FREE) {
            remake(v);
            remade++;
        }
    gi_discontinuity();      /* (the runner draws the next frame without interpolating from the dropped timeline) */
    n_restores++;
    if (getenv("HULK_GFX_ROLL_LOG"))
        fprintf(stderr, "gfx: restore %u: %u sink objects dropped, %u made again (frame rate %d)\n", n_restores,
                dropped, remade, hulk_wasm_frame_rate());
}

uint32_t hulk_gfx_sink_create_texture(const void* d) {
    uint32_t v = v_alloc(V_TEX);
    vrec* r = &vt[v];
    memcpy(r->a, d, 24);
    r->a[6] = (uint32_t)(uintptr_t)ff_arena_alloc(16 * 5 * 4, 16);
    r->stamp = ++v_stamp;
    if (!gi_create_texture(v, r->a)) fail("a texture", v);
    v_sent(v);
    return v;
}
/* the data is the texture's CPU copy of the level (bgfxTexture::m_levels, in the arena): kept as a pointer */
uint32_t hulk_gfx_sink_update_texture(uint32_t t, uint32_t level, uint32_t w, uint32_t h, const void* data,
                                      uint32_t pitch, uint32_t size) {
    vrec* r = v_get(t, V_TEX);
    if (r && level < 16) {
        uint32_t* lv = PTR(r->a[6]);
        lv[5 * level] = (uint32_t)(uintptr_t)data;
        lv[5 * level + 1] = w;
        lv[5 * level + 2] = h;
        lv[5 * level + 3] = pitch;
        lv[5 * level + 4] = size;
        r->a[7] |= 1u << level;
        r->stamp = ++v_stamp;
    }
    if (!gi_update_texture(t, level, w, h, data, pitch, size)) fail("a texture upload", t);
    if (r) v_sent(t);
    return 1;       /* (the runner's memory is not the game's business: a refused upload is logged, not retried) */
}
void hulk_gfx_sink_destroy_texture(uint32_t t) {
    if (!v_get(t, V_TEX)) return;     /* (the sink's own targets are never the front end's to destroy) */
    gi_destroy(t);
    v_dropped(t);
    v_free(t);
}
/* a prim buffer's vertices: SinkVertexData's packed copy (bgfxPrimBuffer::m_vertices, in the arena) is kept, and
 * the converted vertices are made from it again after a restore */
uint32_t hulk_gfx_sink_update_vertex_buffer(uint32_t b, const void* d) {
    const wvdata* w = d;
    vrec* r = v_get(b, V_VB);
    if (!r) {
        b = v_alloc(V_VB);
        r = &vt[b];
    }
    r->a[0] = w->packed;
    r->a[1] = w->count;
    r->a[2] = w->owner;
    r->a[3] = w->packedStride;
    r->a[4] = w->vertexFlags;
    r->a[5] = w->primKind;
    r->stamp = ++v_stamp;
    if (!gi_update_vertex_buffer(b, d)) fail("a vertex buffer", b);
    v_sent(b);
    return b;
}
uint32_t hulk_gfx_sink_update_index_buffer(uint32_t b, const uint16_t* idx, uint32_t n, uint32_t owner) {
    vrec* r = v_get(b, V_IB);
    if (!r) {
        b = v_alloc(V_IB);
        r = &vt[b];
    }
    r->a[0] = (uint32_t)(uintptr_t)idx;
    r->a[1] = n;
    r->a[2] = owner;
    r->stamp = ++v_stamp;
    if (!gi_update_index_buffer(b, idx, n, owner)) fail("an index buffer", b);
    v_sent(b);
    return b;
}
void hulk_gfx_sink_destroy_buffers(uint32_t vb, uint32_t ib) {
    if (v_get(vb, V_VB)) {
        gi_destroy(vb);
        v_dropped(vb);
        v_free(vb);
    }
    if (v_get(ib, V_IB)) {
        gi_destroy(ib);
        v_dropped(ib);
        v_free(ib);
    }
}
/* bgfx's transient vertices: the front end writes them here; the runner copies them into bgfx's buffer before its
 * next sink call (80 bytes a SinkVertex) */
void* hulk_gfx_sink_alloc_transient(uint32_t count, uint32_t* token) {
    static uint8_t* staging;
    static uint32_t cap;
    if (count * 80u > cap) {
        free(staging);
        cap = count * 80u + 65536;
        staging = malloc(cap);
        if (!staging) ff_fatal("gfx: no room for %u transient vertices", count);
    }
    return gi_alloc_transient(count, token, staging) ? staging : 0;
}
/* the front end's targets: two vids (the texture, its frame buffer), made and destroyed together */
static void make_target(uint32_t w, uint32_t h, uint32_t render, uint32_t* out) {
    uint32_t t = v_alloc(V_TGT), fb = v_alloc(V_FB);
    vt[t].a[0] = w;
    vt[t].a[1] = h;
    vt[t].a[2] = render;
    vt[t].a[3] = fb;
    vt[fb].a[0] = t;
    vt[t].stamp = vt[fb].stamp = ++v_stamp;
    if (!gi_create_target(t, fb, w, h, render)) fail("a target", t);
    v_sent(t);
    v_sent(fb);
    out[0] = t;
    out[1] = fb;
}
static void drop_target(uint32_t* t) {
    vrec* r = v_get(t[0], V_TGT);
    if (r) {
        uint32_t fb = r->a[3];
        gi_destroy(t[0]);
        v_dropped(t[0]);
        v_free(fb);
        v_free(t[0]);
    }
    t[0] = t[1] = KNONE;
}
void hulk_gfx_sink_create_copy_target(uint32_t w, uint32_t h, void* out) { make_target(w, h, 0, out); }
void hulk_gfx_sink_create_render_target(uint32_t w, uint32_t h, void* out) { make_target(w, h, 1, out); }
void hulk_gfx_sink_destroy_copy_target(void* t) { drop_target(t); }
void hulk_gfx_sink_destroy_render_target(void* t) { drop_target(t); }
/* the sink's own targets: fixed vids; the runner maps them to its current objects at each call */
void hulk_gfx_sink_frame_copy(void* out) {
    uint32_t got = gi_frame_copy(1, 2), *t = out;
    t[0] = got & 1 ? 1 : KNONE;
    t[1] = got & 2 ? 2 : KNONE;
}
uint32_t hulk_gfx_sink_front_buffer(void) { return gi_front_buffer(3) ? 3 : KNONE; }
/* occlusion queries: the sink has no way to destroy one, so the runner keeps the ones a restore orphans for reuse */
uint32_t hulk_gfx_sink_create_query(void) {
    uint32_t v = v_alloc(V_QUERY);
    vt[v].stamp = ++v_stamp;
    if (!gi_create_query(v)) {
        v_free(v);
        return KNONE;
    }
    v_sent(v);
    return v;
}

void hulk_gfx_sink_set_pass(const void* p) { gi_set_pass(p); }
void hulk_gfx_sink_copy_frame(uint32_t pass, const void* dst) { gi_copy_frame(pass, dst); }
uint32_t hulk_gfx_sink_draw_resources(void) { return gi_draw_resources(); }
uint32_t hulk_gfx_sink_has_vertex_program(uint32_t vp) { return gi_has_vertex_program(vp); }
uint32_t hulk_gfx_sink_prepare_pipeline(void* p) { return gi_prepare_pipeline(p); }
void hulk_gfx_sink_submit_draw(const void* p) { gi_submit_draw(p); }
void hulk_gfx_sink_combiner_stats(int32_t* a, int32_t* b, int32_t* c) { gi_combiner_stats(a, b, c); }
uint32_t hulk_gfx_sink_fx_resources(void) { return gi_fx_resources(); }
void hulk_gfx_sink_fx_draw(const void* p) { gi_fx_draw(p); }
/* (HULK_GFX_ROLL_LOG: whether the game reads occlusion results, whose arrival follows the GPU's timing) */
uint32_t hulk_gfx_sink_query_result(uint32_t q, int32_t* pixels) {
    uint32_t r = gi_query_result(q, pixels);
    static int logged = -1;
    if (logged < 0) logged = !getenv("HULK_GFX_ROLL_LOG");
    if (!logged && r) {
        logged = 1;
        fprintf(stderr, "gfx: frame %u: first occlusion result (query %u: %d pixels)\n", SIM->frame, q, *pixels);
    }
    return r;
}
void hulk_gfx_sink_present(const void* p) { gi_present(p); }
void hulk_gfx_sink_frame(void) { gi_frame(); }
void hulk_gfx_sink_request_screenshot(const char* path) { gi_request_screenshot(path); }
/* the render-resolution setting (port_settings.c): the runner draws the frame at that size (output only: the front
 * end and the game keep the 640x480 frame; app.cpp "Render resolution") */
void hulk_wasm_render_res_apply(int value) { gi_render_res(value); }
void hulk_gfx_sink_context_destroyed(void) { gi_context_destroyed(); }
/* the fog setting (port_settings.c, wvid1): the runner's packets (0 the game's fog, 1 reduced, 2 off); output only */
void hulk_wasm_fog_apply(int value) { gi_fog(value); }
/* the runner's picture options (port_settings.c rows that are run/app/rm_pass.cpp passes; wr2): mipmaps, anisotropic
 * filtering, MSAA, ... as rm::Quality numbers them. Output only */
void hulk_wasm_quality_apply(int what, int value) { gi_quality((uint32_t)what, value); }

/* The texture-pack setting (port_settings.c texture_pack, wpack1): the runner lists the installed packs and replaces
 * textures at upload (run/app/texpack.cpp); nothing in the module changes. */
uint32_t hulk_wasm_texture_pack_list(char* buf, uint32_t cap) { return gi_texpack_list(buf, cap); }
void hulk_wasm_texture_pack_apply(int value) { gi_texpack((uint32_t)value); }

/* The aspect-ratio setting (port_settings.c, wvid1, D234): what the display reports to the game (bgfxDisplay slot 16,
 * d3dDisplay::GetAspectRatio 0x31b500's place) and the shape of the frame in the window. The game's frame stays
 * 640x480 (an Xbox 16:9 mode is the same anamorphic 640x480): the cameras widen horizontally (Hor+) and the HUD lays
 * out on the wider frame; the runner draws the scene target at the aspect (app.cpp "Render resolution") and presents
 * it unstretched. 43 / 169 / 1610 / 219 (64:27), 0 the window's, clamped to 4:3 .. 64:27. Game state follows it (the
 * logic view), so tests and replays pin 43 (port_settings.c). */
static int g_aspect = 43, g_hud_edge;
/* the HUD Frame setting (port_settings.c): 1 moves the HUD's 4:3 corner-bracket frame models out to the edges of a
 * wider picture (bgfx_context.cpp vfunc_109, docs/wine-widescreen-60fps.md "HULK_HUD=edge"); nothing at 4:3 */
void hulk_wasm_hud_edge_apply(int value) { g_hud_edge = value; }
int hulk_wasm_hud_edge(void) {
    hulk_settings_load();
    return g_hud_edge;
}
static uint32_t g_asp_sent_n = 4, g_asp_sent_d = 3;
void hulk_wasm_aspect_apply(int value) { g_aspect = value; }
void hulk_wasm_display_aspect(uint32_t ww, uint32_t wh, uint32_t* num, uint32_t* den) {
    hulk_settings_load();
    uint32_t n = 4, d = 3;
    switch (g_aspect) {
    case 169: n = 16, d = 9; break;
    case 1610: n = 16, d = 10; break;
    case 219: n = 64, d = 27; break;
    case 0:
        if (ww && wh) {
            n = ww, d = wh;
            if ((uint64_t)n * 3 < (uint64_t)d * 4) n = 4, d = 3;            /* narrower than 4:3: 4:3, letterboxed */
            else if ((uint64_t)n * 27 > (uint64_t)d * 64) n = 64, d = 27;   /* wider than 21:9: 21:9, pillarboxed */
        }
        break;
    default: break;
    }
    if (n != g_asp_sent_n || d != g_asp_sent_d) {
        g_asp_sent_n = n, g_asp_sent_d = d;
        gi_display_aspect(n, d);
    }
    *num = n, *den = d;
}

/* ------------------------------------------------------------------------------------------- the window */
int hulk_platform_video_init(void) { return gi_video_init(); }
const char* hulk_platform_error(void) {
    static char err[256];
    gi_error(err, sizeof err);
    return err;
}
void* hulk_platform_create_window(const char* title, int w, int h, int hidden, int resizable) {
    return gi_create_window(title, w, h, hidden, resizable) ? (void*)1 : 0;
}
/* the handles bgfx needs are the runner's (gfx_init puts them in): the front end only checks they exist */
int hulk_platform_native_handles(void* window, void** nwh, void** ndt, int* wayland) {
    (void)window;
    *nwh = (void*)1;
    *ndt = 0;
    *wayland = 0;
    return 1;
}
/* the handler is a front-end function (sdl_platform.cpp onResize) compiled through the i686 path: as a value it is
 * its synthetic dispatch address, not a wasm table index, so it is called through ff_dispatch (a call through a C
 * function pointer traps with "Invalid call_indirect" at the first window resize; wapp2) */
static uint32_t on_resize, on_resize_user;
void hulk_platform_set_resize_handler(void* fn, void* user) {
    on_resize = (uint32_t)(uintptr_t)fn;
    on_resize_user = (uint32_t)(uintptr_t)user;
}
void hulk_platform_pump(void) {
    gi_pump();
    int32_t w, h;
    if (gi_resized(&w, &h) && on_resize) ff_call(on_resize, 3, (uint32_t)w, (uint32_t)h, on_resize_user);
}
int hulk_platform_quit_requested(void) { return gi_quit_requested(); }
int hulk_platform_has_focus(void) { return gi_has_focus(); }
int hulk_platform_is_fullscreen(void) { return gi_is_fullscreen(); }
int hulk_platform_toggle_fullscreen(void) { return gi_toggle_fullscreen(); }

/* ------------------------------------------------------------------------------------------- the host subset */
void hulk_host_ExitProcess(unsigned int code) {
    fflush(stderr);
    exit((int)code);
}
static uint64_t mono_ns(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ull + (uint64_t)ts.tv_nsec;
}
int hulk_host_QueryPerformanceCounter(void* count) {
    uint64_t v = mono_ns();
    memcpy(count, &v, 8);
    return 1;
}
int hulk_host_QueryPerformanceFrequency(void* freq) {
    uint64_t v = 1000000000ull;
    memcpy(freq, &v, 8);
    return 1;
}
void hulk_host_Sleep(unsigned int ms) { gi_sleep_ms(ms); }
void hulk_native_log(const char* line) { fputs(line, stderr); }
unsigned int hulk_native_frame_no;

/* (mingw-w64's spellings of the C library the front end calls) */
int _vsnprintf(char* buf, size_t n, const char* fmt, va_list ap) { return vsnprintf(buf, n, fmt, ap); }
int _snprintf(char* buf, size_t n, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = vsnprintf(buf, n, fmt, ap);
    va_end(ap);
    return r;
}

/* ------------------------------------------------------------------------------------------- the arena */
void* hulk_gfx_op_new(uint32_t n) { return ff_arena_alloc(n ? n : 1, 16); }
void* hulk_gfx_op_new_array(uint32_t n) { return ff_arena_alloc(n ? n : 1, 16); }
void hulk_gfx_op_delete(void* p) { if (p) ff_arena_free(p); }
void hulk_gfx_op_delete_array(void* p) { if (p) ff_arena_free(p); }
/* the front end's C allocations (tools/wasm_gfx.py C_RENAME: texture levels, prim buffers' copies, conversions): the
 * arena too (wroll1), so its objects never point into the module's own heap, whose layout follows the host */
void* hulk_gfx_malloc(uint32_t n) { return ff_arena_alloc(n ? n : 1, 16); }
void* hulk_gfx_calloc(uint32_t n, uint32_t k) {
    if (k && n > 0xffffffffu / k) return 0;
    return ff_arena_alloc(n * k ? n * k : 1, 16);     /* (ff_arena_alloc zeroes) */
}
void* hulk_gfx_realloc(void* p, uint32_t n) { return ff_arena_realloc(p, n ? n : 1); }
void hulk_gfx_free(void* p) { if (p) ff_arena_free(p); }

/* ------------------------------------------------------------------------------------------- the frame */
void ff_frame_end(void);
void ff_frame_checkpoint(void);
int ff_replay_active(void);
void hulk_wasm_gfx_frame_end(void) {
    if (SIM->d3d_vblank_cb) ff_call(SIM->d3d_vblank_cb, 0);
    ff_frame_end();
    hulk_native_frame_no = SIM->frame;
    /* a free run's frame lasts what the original's SwapBuffers waits for (0x31b190): one field with the flag
     * 0x005554a0 set (menus, movies: 60 Hz), two with it clear (gameplay: 30 Hz), as the updates are paced
     * (plat_pace); ff_frame_end moved the clock one field. At every display rate (D228a): the display's rate only
     * changes how often the runner draws each update (run/app/interp.cpp). A replay keeps its own clock. */
    static int free_run = -1;
    if (free_run < 0) free_run = !ff_replay_active();
    if (free_run && !*(volatile uint8_t*)PTR(0x005554a0u)) SIM->clock += HULK_TSC_HZ / 60;
    static int live = -1;
    if (live < 0) live = !getenv("HULK_INPUT") && !ff_replay_active();
    uint8_t pad[18];
    if (live && gi_pad(0, pad)) memcpy(SIM->pads[0], pad, 18);
    ff_frame_checkpoint();
}

/* ------------------------------------------------------------------------------------------- display rates (fps2)
 * D228a: the simulation steps at the original's rate whatever the display does. The display rate (30: the
 * original's presents, 60, 120, 0: the display's refresh) is host state, not game state: the runner records each
 * update's drawing and draws it again with interpolated transforms (run/app/interp.cpp). The settings layer applies
 * it with hulk_wasm_frame_rate_apply (port_settings.c: at load and on a change; it takes effect at the next frame
 * end); 30 until then. HULK_DISPLAY_FPS (the runner's) overrides it without touching the menus. */
static int g_rate = 30;
static int rate_now(void) { return g_rate; }
int hulk_wasm_frame_rate(void) { return rate_now(); }
void hulk_wasm_frame_rate_apply(int value) {
    g_rate = value == 60 || value == 120 || value == 0 ? value : 30;
}
/* the SwapBuffers wait (sdl_platform.cpp platformFramePace under HULK_PDDI_WASM): the runner draws the update and
 * waits; fields: 1 with the flag 0x005554a0 set (60 Hz), else 2 */
void hulk_wasm_frame_pace(void) {
    static int sent = -2;
    int r = rate_now();
    if (r != sent) gi_display_rate((uint32_t)r), sent = r;
    gi_pace(*(volatile uint8_t*)PTR(0x005554a0u) ? 1u : 2u);
}
