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
 * - The front end's operator new / delete: the game arena, so a snapshot carries its objects. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"

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
GI(gfx_create_texture) uint32_t gi_create_texture(const void* desc);
GI(gfx_update_texture) uint32_t gi_update_texture(uint32_t texture, uint32_t level, uint32_t w, uint32_t h,
                                                  const void* data, uint32_t pitch, uint32_t size);
GI(gfx_destroy_texture) void gi_destroy_texture(uint32_t texture);
GI(gfx_update_vertex_buffer) uint32_t gi_update_vertex_buffer(uint32_t b, const void* data);
GI(gfx_update_index_buffer) uint32_t gi_update_index_buffer(uint32_t b, const uint16_t* idx, uint32_t n, uint32_t owner);
GI(gfx_destroy_buffers) void gi_destroy_buffers(uint32_t vb, uint32_t ib);
GI(gfx_alloc_transient) uint32_t gi_alloc_transient(uint32_t count, uint32_t* token, void* staging);
GI(gfx_create_copy_target) void gi_create_copy_target(uint32_t w, uint32_t h, void* out);
GI(gfx_create_render_target) void gi_create_render_target(uint32_t w, uint32_t h, void* out);
GI(gfx_destroy_copy_target) void gi_destroy_copy_target(void* t);
GI(gfx_destroy_render_target) void gi_destroy_render_target(void* t);
GI(gfx_frame_copy) void gi_frame_copy(void* out);
GI(gfx_front_buffer) uint32_t gi_front_buffer(void);
GI(gfx_set_pass) void gi_set_pass(const void* pass);
GI(gfx_copy_frame) void gi_copy_frame(uint32_t pass, const void* dst);
GI(gfx_draw_resources) uint32_t gi_draw_resources(void);
GI(gfx_has_vertex_program) uint32_t gi_has_vertex_program(uint32_t vp);
GI(gfx_prepare_pipeline) uint32_t gi_prepare_pipeline(void* packet);
GI(gfx_submit_draw) void gi_submit_draw(const void* packet);
GI(gfx_combiner_stats) void gi_combiner_stats(int32_t* generated, int32_t* generic, int32_t* draws);
GI(gfx_fx_resources) uint32_t gi_fx_resources(void);
GI(gfx_fx_draw) void gi_fx_draw(const void* packet);
GI(gfx_create_query) uint32_t gi_create_query(void);
GI(gfx_query_result) uint32_t gi_query_result(uint32_t q, int32_t* pixels);
GI(gfx_present) void gi_present(const void* p);
GI(gfx_frame) void gi_frame(void);
GI(gfx_request_screenshot) void gi_request_screenshot(const char* path);
GI(gfx_context_destroyed) void gi_context_destroyed(void);
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
uint32_t hulk_gfx_sink_create_texture(const void* d) { return gi_create_texture(d); }
uint32_t hulk_gfx_sink_update_texture(uint32_t t, uint32_t level, uint32_t w, uint32_t h, const void* data,
                                      uint32_t pitch, uint32_t size) {
    return gi_update_texture(t, level, w, h, data, pitch, size);
}
void hulk_gfx_sink_destroy_texture(uint32_t t) { gi_destroy_texture(t); }
uint32_t hulk_gfx_sink_update_vertex_buffer(uint32_t b, const void* d) { return gi_update_vertex_buffer(b, d); }
uint32_t hulk_gfx_sink_update_index_buffer(uint32_t b, const uint16_t* idx, uint32_t n, uint32_t owner) {
    return gi_update_index_buffer(b, idx, n, owner);
}
void hulk_gfx_sink_destroy_buffers(uint32_t vb, uint32_t ib) { gi_destroy_buffers(vb, ib); }
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
void hulk_gfx_sink_create_copy_target(uint32_t w, uint32_t h, void* out) { gi_create_copy_target(w, h, out); }
void hulk_gfx_sink_create_render_target(uint32_t w, uint32_t h, void* out) { gi_create_render_target(w, h, out); }
void hulk_gfx_sink_destroy_copy_target(void* t) { gi_destroy_copy_target(t); }
void hulk_gfx_sink_destroy_render_target(void* t) { gi_destroy_render_target(t); }
void hulk_gfx_sink_frame_copy(void* out) { gi_frame_copy(out); }
uint32_t hulk_gfx_sink_front_buffer(void) { return gi_front_buffer(); }
void hulk_gfx_sink_set_pass(const void* p) { gi_set_pass(p); }
void hulk_gfx_sink_copy_frame(uint32_t pass, const void* dst) { gi_copy_frame(pass, dst); }
uint32_t hulk_gfx_sink_draw_resources(void) { return gi_draw_resources(); }
uint32_t hulk_gfx_sink_has_vertex_program(uint32_t vp) { return gi_has_vertex_program(vp); }
uint32_t hulk_gfx_sink_prepare_pipeline(void* p) { return gi_prepare_pipeline(p); }
void hulk_gfx_sink_submit_draw(const void* p) { gi_submit_draw(p); }
void hulk_gfx_sink_combiner_stats(int32_t* a, int32_t* b, int32_t* c) { gi_combiner_stats(a, b, c); }
uint32_t hulk_gfx_sink_fx_resources(void) { return gi_fx_resources(); }
void hulk_gfx_sink_fx_draw(const void* p) { gi_fx_draw(p); }
uint32_t hulk_gfx_sink_create_query(void) { return gi_create_query(); }
uint32_t hulk_gfx_sink_query_result(uint32_t q, int32_t* pixels) { return gi_query_result(q, pixels); }
void hulk_gfx_sink_present(const void* p) { gi_present(p); }
void hulk_gfx_sink_frame(void) { gi_frame(); }
void hulk_gfx_sink_request_screenshot(const char* path) { gi_request_screenshot(path); }
void hulk_gfx_sink_context_destroyed(void) { gi_context_destroyed(); }

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
typedef void (*resize_fn)(int, int, void*);
static resize_fn on_resize;
static void* on_resize_user;
void hulk_platform_set_resize_handler(resize_fn fn, void* user) {
    on_resize = fn;
    on_resize_user = user;
}
void hulk_platform_pump(void) {
    gi_pump();
    int32_t w, h;
    if (gi_resized(&w, &h) && on_resize) on_resize(w, h, on_resize_user);
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

/* ------------------------------------------------------------------------------------------- the frame */
void ff_frame_end(void);
int ff_replay_active(void);
void hulk_wasm_gfx_frame_end(void) {
    if (SIM->d3d_vblank_cb) ff_call(SIM->d3d_vblank_cb, 0);
    ff_frame_end();
    hulk_native_frame_no = SIM->frame;
    /* a free run's frame lasts what the original's SwapBuffers waits for (0x31b190): one field with the flag
     * 0x005554a0 set (menus, movies: 60 Hz), two with it clear (gameplay: 30 Hz), as the presents are paced
     * (sdl_platform.cpp HULK_FPS_CAP); ff_frame_end moved the clock one field. A replay keeps its own clock. */
    static int free_run = -1, cap60 = -1;
    if (free_run < 0) {
        free_run = !ff_replay_active();
        const char* c = getenv("HULK_FPS_CAP");
        cap60 = c && atoi(c) == 60;
    }
    if (free_run && !cap60 && !*(volatile uint8_t*)PTR(0x005554a0u)) SIM->clock += HULK_TSC_HZ / 60;
    static int live = -1;
    if (live < 0) live = !getenv("HULK_INPUT") && !ff_replay_active();
    uint8_t pad[18];
    if (live && gi_pad(0, pad)) memcpy(SIM->pads[0], pad, 18);
}
