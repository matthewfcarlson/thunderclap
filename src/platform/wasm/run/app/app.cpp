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
#include "interp.h"
#include "texpack.h"
#include "rm_pass.h"

using namespace hulk::pddi;

#define GFX_ABI_HOST 1
#include "gfx_abi_table.h"

extern "C" uint8_t* hulk_run_memory(void);    // run/native.c
extern "C" void hulk_app_movie_overlay(unsigned ww, unsigned wh);   // run/app/movie.c

static uint8_t* M(u32 a) { return a ? hulk_run_memory() + a : nullptr; }
template <class T> static T* MT(u32 a) { return reinterpret_cast<T*>(M(a)); }

// (start-up options and the game's location: start.cpp)

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
static u32 s_recStaging, s_recCount;          // (recording: the module's staging, copied at the next call)
static void flush()
{
    if (s_recStaging) {
        interp_transient((const SinkVertex*)M(s_recStaging), s_recCount);
        s_recStaging = 0;
    }
    if (s_pendingHost) {
        memcpy(s_pendingHost, M(s_pendingStaging), (size_t)s_pendingCount * sizeof(SinkVertex));
        s_pendingHost = nullptr;
    }
}

static void* s_window;

// ------------------------------------------------------------------------------------------- the module's ids (wroll1)
// The module names sink objects by its own ids (vids: src/platform/wasm/gfx/gfx.c "resources"), so the game state
// never holds the sink's ids, whose values follow this process's history; here each vid is mapped to what the sink
// made for it. After a restore the module drops and makes again the vids whose contents differ.
enum { kVids = 16384 };
enum ResKind : uint8_t {
    kResNone, kResTexture, kResVertices, kResIndices, kResRenderTarget, kResCopyTarget, kResFrameBuffer, kResQuery,
    kResSinkOwned
};
struct Res {
    ResKind kind;
    uint8_t scaled;       // a copy target of the frame's size, made at the render resolution (rrRemake)
    uint32_t id, id2;     // the sink's ids (a target: its texture and frame buffer)
    uint32_t pair;        // a target's frame buffer vid, a frame buffer's target vid
};
static Res s_res[kVids];
static uint32_t s_spareQuery[1024], s_spareQueries;      // (the sink can't destroy a query: kept for the next one)
static Res* res(uint32_t vid) { return vid < kVids ? &s_res[vid] : nullptr; }
static void drop(uint32_t vid)
{
    Res* r = res(vid);
    if (!r)
        return;
    switch (r->kind) {
    // (interp_destroy: now, or once no recorded stream can still draw it)
    case kResTexture:
        texpack_dropped(vid);
        interp_destroy(1, r->id, 0);
        break;
    case kResVertices:
        meshpack_dropped(vid);
        rm::buffersDropped(r->id);
        interp_destroy(2, r->id, kSinkNone);
        break;
    case kResIndices:
        meshpack_dropped(vid);
        interp_destroy(2, kSinkNone, r->id);
        break;
    case kResRenderTarget:
    case kResCopyTarget: {
        interp_destroy(r->kind == kResRenderTarget ? 3 : 4, r->id, r->id2);
        if (Res* f = res(r->pair); f && f->kind == kResFrameBuffer && f->pair == vid)
            *f = Res{};
        break;
    }
    case kResFrameBuffer:
        if (Res* t = res(r->pair); t && (t->kind == kResRenderTarget || t->kind == kResCopyTarget) && t->pair == vid) {
            *r = Res{};
            drop(t - s_res);
        }
        break;
    case kResQuery:
        if (r->id != kSinkNone && s_spareQueries < sizeof s_spareQuery / sizeof s_spareQuery[0])
            s_spareQuery[s_spareQueries++] = r->id;
        break;
    default:
        break;
    }
    *r = Res{};
    r->id = r->id2 = kSinkNone;
}
// a vid in a packet as the sink's id (kSinkNone and kSinkTargetScene stay)
static uint32_t hostId(uint32_t vid)
{
    Res* r = res(vid);
    return r && r->kind != kResNone ? r->id : vid == kSinkNone || vid >= kVids ? vid : kSinkNone;
}
static uint32_t hostTexture(uint32_t vid) { return hostId(vid); }
static uint32_t hostFrameBuffer(uint32_t vid)
{
    Res* r = res(vid);
    if (r && r->kind == kResFrameBuffer) {
        Res* t = res(r->pair);
        return t ? t->id2 : kSinkNone;
    }
    return hostId(vid);
}

// ------------------------------------------------------------------------------------------- render resolution
// (wopt1, D232; docs/wasm-port.md "Render resolution") The setting (port_settings.c render_res, sent by gfx_render_res):
// 1..4 a multiple of the frame, 0 the window's pixels (the frame's aspect, fitted), else that height at the frame's
// aspect. Output only: the front end and the game keep the frame they asked for (frame_targets: 640x480), and every
// size they read (target_width/height) is that one. Here the scene target, the sink's frame copy and front buffer and
// the copy targets of the frame's size are made at the render size; a pass into one of them has its viewport scaled;
// an occlusion query's pixel count is scaled back. Render targets (the effects' smaller targets) keep their sizes.
static int s_rrMode = 1, s_rrPending, s_rrForce;     // (force: the scene target again at the same size: MSAA)
static uint32_t s_logW, s_logH, s_physW, s_physH, s_winW, s_winH;
// the display's aspect (gfx_display_aspect: the aspect-ratio setting, wvid1 D234; 4:3 the frame's own): the scene
// target takes that shape (the game's 640x480 frame drawn anamorphically, as on an Xbox 16:9 mode) and the module's
// present rectangle (bgfx_display.cpp presentRect) is the same rectangle of the window
static uint32_t s_aspN = 4, s_aspD = 3;
static void rrSize(uint32_t* pw, uint32_t* ph)
{
    uint32_t lw = s_logW, lh = s_logH, w = lw, h = lh;
    bool own = s_aspN * 3 == s_aspD * 4;    // 4:3: sizes from the frame's own (as before)
    uint32_t an = own ? lw : s_aspN, ad = own ? lh : s_aspD;
    if (!an || !ad)
        an = 4, ad = 3;
    if (s_rrMode >= 1 && s_rrMode <= 4) {
        h = lh * (uint32_t)s_rrMode;
        w = own ? lw * (uint32_t)s_rrMode : (uint32_t)(((uint64_t)h * an + ad / 2) / ad);
    } else if (s_rrMode == 0) {
        if (s_winW && s_winH) {         // the largest rectangle of the display's aspect in the window (its present rect)
            if ((uint64_t)s_winW * ad <= (uint64_t)s_winH * an) {
                w = s_winW;
                h = (uint32_t)(((uint64_t)s_winW * ad + an / 2) / an);
            } else {
                h = s_winH;
                w = (uint32_t)(((uint64_t)s_winH * an + ad / 2) / ad);
            }
        }
    } else if (s_rrMode > 4) {
        h = (uint32_t)s_rrMode;
        w = (uint32_t)(((uint64_t)h * an + ad / 2) / ad);
    }
    const uint32_t kMax = 8192;
    if (w > kMax || h > kMax) {
        uint32_t k = w > h ? w : h;
        w = (uint32_t)((uint64_t)w * kMax / k);
        h = (uint32_t)((uint64_t)h * kMax / k);
    }
    *pw = w ? w : 1;
    *ph = h ? h : 1;
}
static bool rrScaled() { return s_logW && (s_physW != s_logW || s_physH != s_logH); }
static uint16_t rrX(uint32_t x) { return (uint16_t)(s_logW ? (uint64_t)x * s_physW / s_logW : x); }
static uint16_t rrY(uint32_t y) { return (uint16_t)(s_logH ? (uint64_t)y * s_physH / s_logH : y); }
static void refreshSinkOwned();
// the scene target and the scaled copy targets at the render size (between frames: frame())
static void rrRemake()
{
    s_rrPending = 0;
    if (!s_logW || !hulk_gfx_sink_offscreen())
        return;
    uint32_t w, h;
    rrSize(&w, &h);
    bool force = s_rrForce;
    s_rrForce = 0;
    if (w == s_physW && h == s_physH && !force)
        return;
    if (!hulk_gfx_sink_frame_targets(w, h)) {
        fprintf(stderr, "hulk-app: render resolution %ux%u refused: %ux%u\n", w, h, s_logW, s_logH);
        hulk_gfx_sink_frame_targets(s_logW, s_logH);
        w = s_logW, h = s_logH;
    }
    s_physW = w, s_physH = h;
    for (uint32_t v = 0; v < kVids; v++) {
        Res* r = &s_res[v];
        if (r->kind != kResCopyTarget || !r->scaled)
            continue;
        SinkTarget t = {r->id, r->id2};
        hulk_gfx_sink_destroy_copy_target(&t);
        hulk_gfx_sink_create_copy_target(w, h, &t);
        r->id = t.texture, r->id2 = t.frameBuffer;
    }
    refreshSinkOwned();
    fprintf(stderr, "hulk-app: render resolution %ux%u (the game's frame %ux%u)\n", w, h, s_logW, s_logH);
}

// (rm_pass.h) the scene target is made again between frames (MSAA changed)
void rm::appTargetsChanged()
{
    s_rrPending = 1;
    s_rrForce = 1;
}

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
u32 w2c_hulk_gfx_frame_targets(struct w2c_hulk*, u32 w, u32 h)
{
    flush();
    s_logW = w, s_logH = h;
    rrSize(&s_physW, &s_physH);
    if (hulk_gfx_sink_frame_targets(s_physW, s_physH))
        return 1;
    s_physW = w, s_physH = h;
    return hulk_gfx_sink_frame_targets(w, h);
}
u32 w2c_hulk_gfx_offscreen(struct w2c_hulk*) { return hulk_gfx_sink_offscreen(); }
u32 w2c_hulk_gfx_scene_target(struct w2c_hulk*) { return hulk_gfx_sink_scene_target(); }
u32 w2c_hulk_gfx_target_width(struct w2c_hulk*) { return s_logW && hulk_gfx_sink_target_width() ? s_logW : hulk_gfx_sink_target_width(); }
u32 w2c_hulk_gfx_target_height(struct w2c_hulk*) { return s_logH && hulk_gfx_sink_target_height() ? s_logH : hulk_gfx_sink_target_height(); }
void w2c_hulk_gfx_destroy_frame_targets(struct w2c_hulk*) { flush(); hulk_gfx_sink_destroy_frame_targets(); }
u32 w2c_hulk_gfx_create_texture(struct w2c_hulk*, u32 vid, u32 desc)
{
    flush();
    Res* r = res(vid);
    if (!r)
        return 0;
    drop(vid);
    r->kind = kResTexture;
    r->id = hulk_gfx_sink_create_texture(MT<SinkTextureDesc>(desc));
    if (r->id != kSinkNone)
        texpack_created(vid, &r->id, *MT<SinkTextureDesc>(desc));     // (texture packs: texpack.cpp)
    return r->id != kSinkNone;
}
u32 w2c_hulk_gfx_update_texture(struct w2c_hulk*, u32 vid, u32 level, u32 w, u32 h, u32 data, u32 pitch, u32 size)
{
    flush();
    Res* r = res(vid);
    if (!r || r->kind != kResTexture || r->id == kSinkNone)
        return 0;
    if (texpack_tracks(vid))
        return texpack_update(vid, level, w, h, M(data), pitch, size);
    return hulk_gfx_sink_update_texture(r->id, level, w, h, M(data), pitch, size);
}
u32 w2c_hulk_gfx_update_vertex_buffer(struct w2c_hulk*, u32 vid, u32 data)
{
    flush();
    Res* r = res(vid);
    if (!r)
        return 0;
    if (r->kind != kResVertices)
        drop(vid);
    r->kind = kResVertices;
    const WSinkVertexData* w = MT<WSinkVertexData>(data);
    SinkVertexData d;
    d.vertices = MT<const SinkVertex>(w->vertices);
    d.count = w->count;
    d.owner = w->owner;
    d.packed = M(w->packed);
    d.packedStride = w->packedStride;
    d.vertexFlags = w->vertexFlags;
    d.primKind = w->primKind;
    meshpack_vertices(vid, d);              // (model packs: meshpack.cpp)
    uint32_t was = r->id;
    r->id = hulk_gfx_sink_update_vertex_buffer(r->id, &d);
    if (was != kSinkNone && was != r->id)
        rm::buffersDropped(was);
    if (r->id != kSinkNone)
        rm::vertices(r->id, d);                 // (the runner's passes: the far field's room match)
    return r->id != kSinkNone;
}
u32 w2c_hulk_gfx_update_index_buffer(struct w2c_hulk*, u32 vid, u32 idx, u32 n, u32 owner)
{
    flush();
    Res* r = res(vid);
    if (!r)
        return 0;
    if (r->kind != kResIndices)
        drop(vid);
    r->kind = kResIndices;
    meshpack_indices(vid, MT<const uint16_t>(idx), n);
    r->id = hulk_gfx_sink_update_index_buffer(r->id, MT<const uint16_t>(idx), n, owner);
    return r->id != kSinkNone;
}
u32 w2c_hulk_gfx_create_target(struct w2c_hulk*, u32 vid, u32 fb, u32 w, u32 h, u32 render)
{
    flush();
    Res *r = res(vid), *f = res(fb);
    if (!r || !f)
        return 0;
    drop(vid);
    drop(fb);
    SinkTarget t;
    bool scaled = !render && w == s_logW && h == s_logH;      // a copy of the frame: at the render size
    static int s_tlog = getenv("HULK_RM_LOG") ? atoi(getenv("HULK_RM_LOG")) : 0;
    if (s_tlog)
        fprintf(stderr, "hulk-app: target vid %u %ux%u %s\n", vid, w, h, render ? "render" : "copy");
    if (render)
        hulk_gfx_sink_create_render_target(w, h, &t);
    else
        hulk_gfx_sink_create_copy_target(scaled ? s_physW : w, scaled ? s_physH : h, &t);
    r->kind = render ? kResRenderTarget : kResCopyTarget;
    r->scaled = scaled;
    r->id = t.texture;
    r->id2 = t.frameBuffer;
    r->pair = fb;
    f->kind = kResFrameBuffer;
    f->pair = vid;
    return t.texture != kSinkNone;
}
u32 w2c_hulk_gfx_create_query(struct w2c_hulk*, u32 vid)
{
    flush();
    Res* r = res(vid);
    if (!r)
        return 0;
    drop(vid);
    uint32_t q = kSinkNone;
    if (s_spareQueries) {
        q = s_spareQuery[--s_spareQueries];
    } else {
        q = hulk_gfx_sink_create_query();
    }
    if (q == kSinkNone)
        return 0;
    r->kind = kResQuery;
    r->id = q;
    return 1;
}
void w2c_hulk_gfx_destroy(struct w2c_hulk*, u32 vid)
{
    flush();
    drop(vid);
}
u32 w2c_hulk_gfx_alloc_transient(struct w2c_hulk*, u32 count, u32 token, u32 staging)
{
    flush();
    uint32_t tok = kSinkNone;
    if (interp_recording()) {          // (the stream keeps a copy: drawn later, from the sink's buffer then)
        tok = 0;
        memcpy(M(token), &tok, 4);
        s_recStaging = staging;
        s_recCount = count;
        interp_transient(nullptr, 0);
        return 1;
    }
    SinkVertex* v = hulk_gfx_sink_alloc_transient(count, &tok);
    memcpy(M(token), &tok, 4);
    if (!v)
        return 0;
    s_pendingHost = v;
    s_pendingStaging = staging;
    s_pendingCount = count;
    return 1;
}
// the sink's own targets: fixed vids naming whatever the sink holds now
u32 w2c_hulk_gfx_frame_copy(struct w2c_hulk*, u32 vid, u32 fb)
{
    flush();
    SinkTarget t;
    hulk_gfx_sink_frame_copy(&t);
    Res *r = res(vid), *f = res(fb);
    if (r)
        r->kind = kResSinkOwned, r->id = t.texture;
    if (f)
        f->kind = kResSinkOwned, f->id = t.frameBuffer;
    return (t.texture != kSinkNone ? 1 : 0) | (t.frameBuffer != kSinkNone ? 2 : 0);
}
u32 w2c_hulk_gfx_front_buffer(struct w2c_hulk*, u32 vid)
{
    flush();
    uint32_t t = hulk_gfx_sink_front_buffer();
    Res* r = res(vid);
    if (r)
        r->kind = kResSinkOwned, r->id = t;
    return t != kSinkNone;
}
// the sink's own targets (vids 1..3) after the render size changed: what the sink holds now
static void refreshSinkOwned()
{
    if (s_res[1].kind == kResSinkOwned || s_res[2].kind == kResSinkOwned) {
        SinkTarget t;
        hulk_gfx_sink_frame_copy(&t);
        if (s_res[1].kind == kResSinkOwned)
            s_res[1].id = t.texture;
        if (s_res[2].kind == kResSinkOwned)
            s_res[2].id = t.frameBuffer;
    }
    if (s_res[3].kind == kResSinkOwned)
        s_res[3].id = hulk_gfx_sink_front_buffer();
}
void w2c_hulk_gfx_set_pass(struct w2c_hulk*, u32 p)
{
    flush();
    SinkPass pass = *MT<const SinkPass>(p);
    bool scale = pass.target == kSinkTargetScene;
    if (Res* f = res(pass.target); !scale && f) {
        Res* t = f->kind == kResFrameBuffer ? res(f->pair) : nullptr;
        scale = f->kind == kResSinkOwned || (t && t->kind == kResCopyTarget && t->scaled);
    }
    if (scale && rrScaled()) {
        uint16_t x0 = rrX(pass.x), y0 = rrY(pass.y);
        pass.w = (uint16_t)(rrX((uint32_t)pass.x + pass.w) - x0);
        pass.h = (uint16_t)(rrY((uint32_t)pass.y + pass.h) - y0);
        pass.x = x0, pass.y = y0;
    }
    if (pass.target != kSinkTargetScene)
        pass.target = hostFrameBuffer(pass.target);
    if (interp_recording())
        return interp_pass(pass);
    rm::setPass(pass);
}
void w2c_hulk_gfx_copy_frame(struct w2c_hulk*, u32 pass, u32 dst)
{
    flush();
    const SinkTarget* w = MT<const SinkTarget>(dst);
    SinkTarget t = {hostTexture(w->texture), hostFrameBuffer(w->frameBuffer)};
    if (interp_recording())
        return interp_copy((uint16_t)pass, t);
    hulk_gfx_sink_copy_frame(pass, &t);
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
    for (int i = 0; i < 4; i++) {
        p->stage[i].texture = hostTexture(w->stage[i].texture);
        if (w->query != kSinkNone)          // (texture packs: a draw the game counts pixels of keeps the original)
            p->stage[i].texture = texpack_query_texture(w->stage[i].texture, p->stage[i].texture);
    }
    p->state = w->state;
    p->count = w->count;
    p->vertexCount = w->vertexCount;
    p->transient = w->transient;
    p->vertexBuffer = hostId(w->vertexBuffer);
    p->indexBuffer = hostId(w->indexBuffer);
    p->query = hostId(w->query);
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
    rm::packet(*p);                                                             // (the runner's passes: fog, ...)
    meshpack_draw(w->vertexBuffer, w->indexBuffer, w->query != kSinkNone, p);   // (model packs)
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
    if (interp_recording())
        return interp_draw(p);
    rm::submitDraw(p);
}
void w2c_hulk_gfx_combiner_stats(struct w2c_hulk*, u32 a, u32 b, u32 c)
{
    hulk_gfx_sink_combiner_stats(MT<int32_t>(a), MT<int32_t>(b), MT<int32_t>(c));
}
u32 w2c_hulk_gfx_fx_resources(struct w2c_hulk*) { flush(); return hulk_gfx_sink_fx_resources(); }
void w2c_hulk_gfx_fx_draw(struct w2c_hulk*, u32 p)
{
    flush();
    FxPacket fx = *MT<const FxPacket>(p);
    for (int i = 0; i < 4; i++)
        fx.texture[i] = hostTexture(fx.texture[i]);
    if (interp_recording())
        return interp_fx(fx);
    hulk_gfx_sink_fx_draw(&fx);
}
u32 w2c_hulk_gfx_query_result(struct w2c_hulk*, u32 q, u32 pixels)
{
    uint32_t id = hostId(q);
    if (id == kSinkNone)
        return kQueryPending;
    u32 st = hulk_gfx_sink_query_result(id, MT<int32_t>(pixels));
    if (uint32_t n = rm::sceneSamples(); n > 1 && pixels)          // (MSAA: the count is of samples)
        *MT<int32_t>(pixels) = (int32_t)(((uint32_t)*MT<int32_t>(pixels) + n / 2) / n);
    if (rrScaled() && pixels) {             // the count at the frame's size, as the game's Xbox would give it
        int32_t* n = MT<int32_t>(pixels);
        uint64_t den = (uint64_t)s_physW * s_physH;
        *n = (int32_t)(((uint64_t)(uint32_t)*n * s_logW * s_logH + den / 2) / den);
    }
    return st;
}
void w2c_hulk_gfx_present(struct w2c_hulk*, u32 p)
{
    flush();
    SinkPresent pr = *MT<const SinkPresent>(p);
    if ((pr.windowWidth != s_winW || pr.windowHeight != s_winH) && s_rrMode == 0)
        s_rrPending = 1;
    s_winW = pr.windowWidth, s_winH = pr.windowHeight;
    if (rrScaled())                         // 1:1 when the render size is the frame's rectangle in the window
        pr.point = (uint32_t)pr.w == s_physW && (uint32_t)pr.h == s_physH;
    if (interp_recording())
        return interp_present(pr);          // (drawn by interp_pace, with the ring after each present's stream)
    hulk_app_movie_overlay(pr.windowWidth, pr.windowHeight);     // (run/app/movie.c: the hold-to-skip ring)
    rm::present(pr);
}
void w2c_hulk_gfx_frame(struct w2c_hulk*)
{
    flush();
    texpack_frame();
    if (!interp_frame()) {
        hulk_gfx_sink_frame();
        rm::frame();
        if (s_rrPending)                    // (a recorded update: after interp_pace has drawn it)
            rrRemake();
    }
}
void w2c_hulk_gfx_render_res(struct w2c_hulk*, u32 value)
{
    if ((int)value == s_rrMode)
        return;
    s_rrMode = (int)value;
    s_rrPending = 1;
}
void w2c_hulk_gfx_display_aspect(struct w2c_hulk*, u32 num, u32 den)
{
    if (!num || !den || (num == s_aspN && den == s_aspD))
        return;
    s_aspN = num, s_aspD = den;
    s_rrPending = 1;
    fprintf(stderr, "hulk-app: display aspect %u:%u\n", num, den);
}
// the fog setting (wvid1): 0 the game's, 1 reduced (the planes x2.5), 2 off. Output only: rm_pass.cpp's fog pass
void rm_set_fog(int value);
void w2c_hulk_gfx_fog(struct w2c_hulk*, u32 value) { rm_set_fog((int)value); }
// the runner's picture options (wr2: port_settings.c rows that are rm passes; rm_pass.h Quality)
void w2c_hulk_gfx_quality(struct w2c_hulk*, u32 what, u32 value) { rm::setQuality(what, (int32_t)value); }
// the Texture Pack setting (port_settings.c texture_pack; texpack.cpp): the installed packs, the chosen one
u32 w2c_hulk_gfx_texpack_list(struct w2c_hulk*, u32 buf, u32 cap) { return texpack_list((char*)M(buf), cap); }
void w2c_hulk_gfx_texpack(struct w2c_hulk*, u32 value) { texpack_select(value); }
void w2c_hulk_gfx_request_screenshot(struct w2c_hulk*, u32 path)
{
    hulk_gfx_sink_request_screenshot((const char*)M(path));
}
void w2c_hulk_gfx_context_destroyed(struct w2c_hulk*)
{
    flush();
    interp_context_destroyed();
    hulk_gfx_sink_context_destroyed();
}
// display rates (fps2, D228a: run/app/interp.cpp): the module's SwapBuffers wait, the rate, a restore
void w2c_hulk_plat_pace(struct w2c_hulk*, u32 fields)
{
    interp_pace(fields);
    if (s_rrPending) {                      // (render resolution: the stream that named the old targets is drawn)
        rrRemake();
        interp_discontinuity();
    }
}
void w2c_hulk_plat_display_rate(struct w2c_hulk*, u32 rate) { interp_set_rate((int)rate); }
void w2c_hulk_gfx_discontinuity(struct w2c_hulk*) { interp_discontinuity(); }

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
    interp_set_window(s_window);
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
