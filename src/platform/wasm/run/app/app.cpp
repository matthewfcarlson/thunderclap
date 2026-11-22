// The app runner's half of graphics, the window and input (docs/wasm-port.md "The macOS app"): the `hulk` imports
// gfx_* and plat_* of a HULK_WASM_GFX=1 module (src/platform/wasm/gfx/gfx.c is the module's half). Linked with
// run/native.c (-DHULK_APP), the bgfx sink and the bridge's host half (src/platform/sdl/pddi/bgfx_sink.cpp,
// bgfx_bridge.cpp with HULK_PDDI_BRIDGE_HOST), the window and event pump (src/platform/sdl/platform_events.cpp), bgfx
// (Metal) and SDL3 with video, by `tools/wasm_port.py aot --app`.
//
// The module's pointers are offsets into its linear memory: each packet is read through its wasm32 mirror
// (gfx_wire.h) and handed to the sink with host pointers. Transient vertices: the module writes them in a staging
// buffer of its own; they are copied into bgfx's buffer before the next sink call.
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <SDL3/SDL.h>

#include "game.h"
#include "pddi/bgfx_bridge.h"
#include "platform_events.h"
#include "gfx_wire.h"

using namespace hulk::pddi;

#define GFX_ABI_HOST 1
#include "gfx_abi_table.h"

extern "C" uint8_t* hulk_run_memory(void);    // run/native.c

static uint8_t* M(u32 a) { return a ? hulk_run_memory() + a : nullptr; }
template <class T> static T* MT(u32 a) { return reinterpret_cast<T*>(M(a)); }

// ------------------------------------------------------------------------------------------- start-up options
// HULK_GFX_RENDERER: metal (the app's default) | noop | null (the game's own d3d layer on the null device: the
// headless build's run, for the replay check). The game: argv[1] or HULK_XBE, its disc HULK_DATA_DIR; started from
// Finder with neither, the extracted disc in ~/Library/Application Support/HulkUD/disc and saves next to it (save/).
extern "C" void hulk_app_start(int argc, char** argv)
{
    (void)argv;
    setenv("HULK_GFX_RENDERER", "metal", 0);
    const char* home = getenv("HOME");
    if (argc > 1 || getenv("HULK_XBE") || !home)
        return;
    char dir[1024], path[1100];
    snprintf(dir, sizeof dir, "%s/Library/Application Support/HulkUD", home);
    snprintf(path, sizeof path, "%s/disc/default.xbe", dir);
    setenv("HULK_XBE", path, 0);
    snprintf(path, sizeof path, "%s/disc", dir);
    setenv("HULK_DATA_DIR", path, 0);
    snprintf(path, sizeof path, "%s/save", dir);
    mkdir(dir, 0755);
    mkdir(path, 0755);
    setenv("HULK_SAVE_DIR", path, 0);
    if (access(getenv("HULK_XBE"), R_OK)) {
        fprintf(stderr, "hulk-app: no game: put the extracted disc (default.xbe and its files) in %s/disc\n", dir);
        if (!isatty(2))        // (started from Finder: say it in a window)
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Hulk UD",
                                     "No game found: put your extracted disc (default.xbe and its files) in "
                                     "~/Library/Application Support/HulkUD/disc", nullptr);
        exit(2);
    }
}

// ------------------------------------------------------------------------------------------- bgfx's callbacks
static void cbLog(const char* text) { fputs(text, stderr); }
static void cbFatal(const char* file, uint32_t line, uint32_t code, const char* text)
{
    fprintf(stderr, "hulk-app: bgfx fatal %s:%u code %u: %s\n", file, line, code, text);
    exit(3);
}
// a screenshot bgfx read back: TGA, 32-bit BGRA, top-left origin (as sdl_platform.cpp's)
static void cbScreenshot(const char* path, uint32_t w, uint32_t h, uint32_t pitch, uint32_t bgra, const void* data,
                         uint32_t yflip)
{
    const uint8_t* px = (const uint8_t*)data;
    FILE* f = fopen(path, "wb");
    if (!f)
        return;
    uint8_t hdr[18] = {0, 0, 2};
    hdr[12] = w & 255, hdr[13] = (w >> 8) & 255, hdr[14] = h & 255, hdr[15] = (h >> 8) & 255;
    hdr[16] = 32, hdr[17] = 0x28;
    fwrite(hdr, 18, 1, f);
    uint8_t* row = (uint8_t*)malloc(w * 4);
    for (uint32_t y = 0; y < h; y++) {
        const uint8_t* p = px + (yflip ? h - 1 - y : y) * pitch;
        for (uint32_t x = 0; x < w; x++, p += 4) {
            row[x * 4 + 0] = bgra ? p[0] : p[2];
            row[x * 4 + 1] = p[1];
            row[x * 4 + 2] = bgra ? p[2] : p[0];
            row[x * 4 + 3] = p[3];
        }
        fwrite(row, w * 4, 1, f);
    }
    free(row);
    fclose(f);
    fprintf(stderr, "hulk-app: screenshot %s %ux%u\n", path, w, h);
}
static const hulk_gfx_callbacks s_callbacks = {cbLog, cbFatal, cbScreenshot};

// ------------------------------------------------------------------------------------------- transient vertices
static SinkVertex* s_pendingHost;
static u32 s_pendingStaging, s_pendingCount;
static void flush()
{
    if (s_pendingHost) {
        memcpy(s_pendingHost, M(s_pendingStaging), (size_t)s_pendingCount * sizeof(SinkVertex));
        s_pendingHost = nullptr;
    }
}

static void* s_window;

extern "C" {

// ------------------------------------------------------------------------------------------- the sink
u32 w2c_hulk_gfx_abi(struct w2c_hulk*, u32 table, u32 n)
{
    const uint32_t mine[] = {GFX_ABI_TABLE};
    uint32_t k = sizeof mine / sizeof mine[0];
    const uint32_t* theirs = MT<uint32_t>(table);
    bool ok = n == k;
    for (uint32_t i = 0; ok && i < k; i++)
        if (theirs[i] != mine[i]) {
            fprintf(stderr, "hulk-app: draw packet layout entry %u: module %u, runner %u\n", i, theirs[i], mine[i]);
            ok = false;
        }
    return ok;
}
u32 w2c_hulk_gfx_renderer(struct w2c_hulk*, u32 name) { return (u32)hulk_gfx_renderer((const char*)M(name)); }
u32 w2c_hulk_gfx_init(struct w2c_hulk*, u32 init)
{
    const WSinkInit* w = MT<WSinkInit>(init);
    SinkInit in = {};
    in.width = w->width;
    in.height = w->height;
    in.renderer = w->renderer;
    in.nativeType = w->nativeType;
    in.callback = (void*)&s_callbacks;
    if (s_window) {
        int wayland = 0;
        hulk_platform_native_handles(s_window, &in.nativeWindow, &in.nativeDisplay, &wayland);
        in.nativeType = wayland;
    }
    return hulk_gfx_sink_init(&in);
}
void w2c_hulk_gfx_shutdown(struct w2c_hulk*) { flush(); hulk_gfx_sink_shutdown(); }
u32 w2c_hulk_gfx_up(struct w2c_hulk*) { return hulk_gfx_sink_up(); }
u32 w2c_hulk_gfx_name(struct w2c_hulk*, u32 buf, u32 cap)
{
    const char* n = hulk_gfx_sink_name();
    if (cap) {
        snprintf((char*)M(buf), cap, "%s", n ? n : "");
    }
    return (u32)strlen(n ? n : "");
}
void w2c_hulk_gfx_caps(struct w2c_hulk*, u32 out) { hulk_gfx_sink_caps(MT<SinkCaps>(out)); }
void w2c_hulk_gfx_resize_back_buffer(struct w2c_hulk*, u32 w, u32 h) { flush(); hulk_gfx_sink_resize_back_buffer(w, h); }
u32 w2c_hulk_gfx_frame_targets(struct w2c_hulk*, u32 w, u32 h) { flush(); return hulk_gfx_sink_frame_targets(w, h); }
u32 w2c_hulk_gfx_offscreen(struct w2c_hulk*) { return hulk_gfx_sink_offscreen(); }
u32 w2c_hulk_gfx_scene_target(struct w2c_hulk*) { return hulk_gfx_sink_scene_target(); }
u32 w2c_hulk_gfx_target_width(struct w2c_hulk*) { return hulk_gfx_sink_target_width(); }
u32 w2c_hulk_gfx_target_height(struct w2c_hulk*) { return hulk_gfx_sink_target_height(); }
void w2c_hulk_gfx_destroy_frame_targets(struct w2c_hulk*) { flush(); hulk_gfx_sink_destroy_frame_targets(); }
u32 w2c_hulk_gfx_create_texture(struct w2c_hulk*, u32 desc)
{
    flush();
    return hulk_gfx_sink_create_texture(MT<SinkTextureDesc>(desc));
}
u32 w2c_hulk_gfx_update_texture(struct w2c_hulk*, u32 t, u32 level, u32 w, u32 h, u32 data, u32 pitch, u32 size)
{
    flush();
    return hulk_gfx_sink_update_texture(t, level, w, h, M(data), pitch, size);
}
void w2c_hulk_gfx_destroy_texture(struct w2c_hulk*, u32 t) { flush(); hulk_gfx_sink_destroy_texture(t); }
u32 w2c_hulk_gfx_update_vertex_buffer(struct w2c_hulk*, u32 b, u32 data)
{
    flush();
    const WSinkVertexData* w = MT<WSinkVertexData>(data);
    SinkVertexData d;
    d.vertices = MT<const SinkVertex>(w->vertices);
    d.count = w->count;
    d.owner = w->owner;
    d.packed = M(w->packed);
    d.packedStride = w->packedStride;
    d.vertexFlags = w->vertexFlags;
    d.primKind = w->primKind;
    return hulk_gfx_sink_update_vertex_buffer(b, &d);
}
u32 w2c_hulk_gfx_update_index_buffer(struct w2c_hulk*, u32 b, u32 idx, u32 n, u32 owner)
{
    flush();
    return hulk_gfx_sink_update_index_buffer(b, MT<const uint16_t>(idx), n, owner);
}
void w2c_hulk_gfx_destroy_buffers(struct w2c_hulk*, u32 vb, u32 ib) { flush(); hulk_gfx_sink_destroy_buffers(vb, ib); }
u32 w2c_hulk_gfx_alloc_transient(struct w2c_hulk*, u32 count, u32 token, u32 staging)
{
    flush();
    uint32_t tok = kSinkNone;
    SinkVertex* v = hulk_gfx_sink_alloc_transient(count, &tok);
    memcpy(M(token), &tok, 4);
    if (!v)
        return 0;
    s_pendingHost = v;
    s_pendingStaging = staging;
    s_pendingCount = count;
    return 1;
}
void w2c_hulk_gfx_create_copy_target(struct w2c_hulk*, u32 w, u32 h, u32 out)
{
    flush();
    hulk_gfx_sink_create_copy_target(w, h, MT<SinkTarget>(out));
}
void w2c_hulk_gfx_create_render_target(struct w2c_hulk*, u32 w, u32 h, u32 out)
{
    flush();
    hulk_gfx_sink_create_render_target(w, h, MT<SinkTarget>(out));
}
void w2c_hulk_gfx_destroy_copy_target(struct w2c_hulk*, u32 t) { flush(); hulk_gfx_sink_destroy_copy_target(MT<SinkTarget>(t)); }
void w2c_hulk_gfx_destroy_render_target(struct w2c_hulk*, u32 t)
{
    flush();
    hulk_gfx_sink_destroy_render_target(MT<SinkTarget>(t));
}
void w2c_hulk_gfx_frame_copy(struct w2c_hulk*, u32 out) { flush(); hulk_gfx_sink_frame_copy(MT<SinkTarget>(out)); }
u32 w2c_hulk_gfx_front_buffer(struct w2c_hulk*) { flush(); return hulk_gfx_sink_front_buffer(); }
void w2c_hulk_gfx_set_pass(struct w2c_hulk*, u32 p) { flush(); hulk_gfx_sink_set_pass(MT<const SinkPass>(p)); }
void w2c_hulk_gfx_copy_frame(struct w2c_hulk*, u32 pass, u32 dst)
{
    flush();
    hulk_gfx_sink_copy_frame(pass, MT<const SinkTarget>(dst));
}
u32 w2c_hulk_gfx_draw_resources(struct w2c_hulk*) { flush(); return hulk_gfx_sink_draw_resources(); }
u32 w2c_hulk_gfx_has_vertex_program(struct w2c_hulk*, u32 vp) { return hulk_gfx_sink_has_vertex_program(vp); }

// a draw packet with host pointers (the out fields of preparePipeline go back)
static void packet(const WDrawPacket* w, DrawPacket* p)
{
    p->frame = w->frame;
    p->drawIndex = w->drawIndex;
    p->phase = w->phase;
    p->pad0 = w->pad0;
    p->instance = w->instance;
    p->shaderKind = w->shaderKind;
    p->shaderSerial = w->shaderSerial;
    p->bufferOwner = w->bufferOwner;
    p->viewMode = w->viewMode;
    p->vertexProgram = w->vertexProgram;
    p->programName = w->programName ? (const char*)M(w->programName) : "";
    p->combinerKey = w->combinerKey ? (const char*)M(w->combinerKey) : "";
    p->combinerHash = w->combinerHash;
    p->forceGeneric = w->forceGeneric;
    p->generic = w->generic;
    p->pad1 = w->pad1;
    p->pipeline = w->pipeline;
    p->vertexConstants = MT<const float>(w->vertexConstants);
    p->vertexConstantCount = w->vertexConstantCount;
    memcpy(p->frag, w->frag, sizeof p->frag);
    memcpy(p->stage, w->stage, sizeof p->stage);
    p->state = w->state;
    p->count = w->count;
    p->vertexCount = w->vertexCount;
    p->transient = w->transient;
    p->vertexBuffer = w->vertexBuffer;
    p->indexBuffer = w->indexBuffer;
    p->query = w->query;
    p->pass = w->pass;
    p->pad2 = w->pad2;
    p->modelview = MT<const float>(w->modelview);
    p->projection = MT<const float>(w->projection);
    p->view = MT<const float>(w->view);
    p->lights = MT<const SinkLight>(w->lights);
    memcpy(p->material, w->material, sizeof p->material);
    p->power = w->power;
    p->ambient = w->ambient;
    p->lighting = w->lighting;
    p->fog = w->fog;
}
u32 w2c_hulk_gfx_prepare_pipeline(struct w2c_hulk*, u32 pk)
{
    flush();
    WDrawPacket* w = MT<WDrawPacket>(pk);
    DrawPacket p;
    packet(w, &p);
    u32 r = hulk_gfx_sink_prepare_pipeline(&p);
    w->generic = p.generic;
    w->pipeline = p.pipeline;
    return r;
}
void w2c_hulk_gfx_submit_draw(struct w2c_hulk*, u32 pk)
{
    flush();
    DrawPacket p;
    packet(MT<const WDrawPacket>(pk), &p);
    hulk_gfx_sink_submit_draw(&p);
}
void w2c_hulk_gfx_combiner_stats(struct w2c_hulk*, u32 a, u32 b, u32 c)
{
    hulk_gfx_sink_combiner_stats(MT<int32_t>(a), MT<int32_t>(b), MT<int32_t>(c));
}
u32 w2c_hulk_gfx_fx_resources(struct w2c_hulk*) { flush(); return hulk_gfx_sink_fx_resources(); }
void w2c_hulk_gfx_fx_draw(struct w2c_hulk*, u32 p) { flush(); hulk_gfx_sink_fx_draw(MT<const FxPacket>(p)); }
u32 w2c_hulk_gfx_create_query(struct w2c_hulk*) { flush(); return hulk_gfx_sink_create_query(); }
u32 w2c_hulk_gfx_query_result(struct w2c_hulk*, u32 q, u32 pixels)
{
    return hulk_gfx_sink_query_result(q, MT<int32_t>(pixels));
}
void w2c_hulk_gfx_present(struct w2c_hulk*, u32 p) { flush(); hulk_gfx_sink_present(MT<const SinkPresent>(p)); }
void w2c_hulk_gfx_frame(struct w2c_hulk*) { flush(); hulk_gfx_sink_frame(); }
void w2c_hulk_gfx_request_screenshot(struct w2c_hulk*, u32 path)
{
    hulk_gfx_sink_request_screenshot((const char*)M(path));
}
void w2c_hulk_gfx_context_destroyed(struct w2c_hulk*) { flush(); hulk_gfx_sink_context_destroyed(); }

// ------------------------------------------------------------------------------------------- the window
u32 w2c_hulk_plat_video_init(struct w2c_hulk*) { return (u32)hulk_platform_video_init(); }
u32 w2c_hulk_plat_error(struct w2c_hulk*, u32 buf, u32 cap)
{
    const char* e = hulk_platform_error();
    if (cap)
        snprintf((char*)M(buf), cap, "%s", e ? e : "");
    return 0;
}
static int s_resized, s_resizeW, s_resizeH;
static void onResize(int w, int h, void*)
{
    s_resized = 1;
    s_resizeW = w;
    s_resizeH = h;
}
u32 w2c_hulk_plat_create_window(struct w2c_hulk*, u32 title, u32 w, u32 h, u32 hidden, u32 resizable)
{
    // the front end names its window for the native builds ("... (native)"): the app keeps the game's own name
    (void)title;
    s_window = hulk_platform_create_window("The Incredible Hulk: Ultimate Destruction", (int)w, (int)h, (int)hidden,
                                           (int)resizable);
    if (s_window)
        hulk_platform_set_resize_handler(onResize, 0);
    return s_window != nullptr;
}
void w2c_hulk_plat_pump(struct w2c_hulk*) { hulk_platform_pump(); }
u32 w2c_hulk_plat_quit_requested(struct w2c_hulk*) { return (u32)hulk_platform_quit_requested(); }
u32 w2c_hulk_plat_has_focus(struct w2c_hulk*) { return (u32)hulk_platform_has_focus(); }
u32 w2c_hulk_plat_is_fullscreen(struct w2c_hulk*) { return (u32)hulk_platform_is_fullscreen(); }
u32 w2c_hulk_plat_toggle_fullscreen(struct w2c_hulk*) { return (u32)hulk_platform_toggle_fullscreen(); }
u32 w2c_hulk_plat_resized(struct w2c_hulk*, u32 w, u32 h)
{
    if (!s_resized)
        return 0;
    s_resized = 0;
    memcpy(M(w), &s_resizeW, 4);
    memcpy(M(h), &s_resizeH, 4);
    return 1;
}
void w2c_hulk_plat_sleep_ms(struct w2c_hulk*, u32 ms) { usleep((useconds_t)ms * 1000); }

// pad 0 for the module (gfx.c): XINPUT_GAMEPAD's 18 bytes; 0 while there is no window (headless runs keep the
// module's own pad)
u32 hulk_app_pad(u32 port, uint8_t* out18);    // input.cpp
u32 w2c_hulk_plat_pad(struct w2c_hulk*, u32 port, u32 out)
{
    if (!s_window)
        return 0;
    return hulk_app_pad(port, M(out));
}

// the C library's stdin (the front end's sscanf pulls it in): nothing to read
u32 w2c_wasi__snapshot__preview1_fd_read(struct w2c_wasi__snapshot__preview1*, u32, u32, u32, u32) { return 8; }

} // extern "C"
