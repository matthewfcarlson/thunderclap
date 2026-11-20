// The C bridge between the pddi front end and the bgfx sink on the native builds (bgfx_bridge.h). Two halves, each
// compiled only by the native links (tools/native_mac.py --gfx; never by the Wine build):
//   HULK_PDDI_BRIDGE_HOST  the host half (Itanium C++, against the host bgfx, beside bgfx_sink.cpp): the
//                          hulk_gfx_sink_* functions on bgfxSink(), bgfx's callback interface on the front end's
//                          hulk_gfx_callbacks, and the logf the host build of the sink calls
//   HULK_PDDI_NATIVE       the front end's half (MS ABI, with the other pddi units): BridgeSink, the DrawSink that
//                          drawSink() returns natively, each member one bridge call
#if HULK_PDDI_BRIDGE_HOST

#include "bgfx_bridge.h"

#include <bgfx/bgfx.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace hulk {
namespace pddi {

DrawSink* bgfxSink();               // bgfx_sink.cpp

static const hulk_gfx_callbacks* s_cb;

// the sink's log lines (pddi.h's logf, which the host build of bgfx_sink.cpp calls): formatted here, written by the
// front end's log
void logf(const char* fmt, ...)
{
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    if (s_cb && s_cb->log)
        s_cb->log(buf);
    else
        fputs(buf, stderr);
}

// bgfx's callback interface, forwarded to the front end's table (as sdl_platform.cpp's Callback on the Wine build)
struct BridgeCallback : bgfx::CallbackI {
    void fatal(const char* file, uint16_t line, bgfx::Fatal::Enum code, const char* str) override
    {
        if (s_cb && s_cb->fatal)
            s_cb->fatal(file, line, (uint32_t)code, str);
    }
    void traceVargs(const char*, uint16_t, const char* fmt, va_list ap) override
    {
        char buf[512];
        vsnprintf(buf, sizeof(buf), fmt, ap);
        if (strstr(buf, "rror") || strstr(buf, "ailed")) {     // bgfx's own trace is chatty: errors only
            char line[540];
            snprintf(line, sizeof(line), "bgfx: %s", buf);
            if (s_cb && s_cb->log)
                s_cb->log(line);
        }
    }
    void profilerBegin(const char*, uint32_t, const char*, uint16_t) override {}
    void profilerBeginLiteral(const char*, uint32_t, const char*, uint16_t) override {}
    void profilerEnd() override {}
    uint32_t cacheReadSize(uint64_t) override { return 0; }
    bool cacheRead(uint64_t, void*, uint32_t) override { return false; }
    void cacheWrite(uint64_t, const void*, uint32_t) override {}
    void captureBegin(uint32_t, uint32_t, uint32_t, bgfx::TextureFormat::Enum, bool) override {}
    void captureEnd() override {}
    void captureFrame(const void*, uint32_t) override {}
    void screenShot(const char* path, uint32_t w, uint32_t h, uint32_t pitch, bgfx::TextureFormat::Enum fmt,
                    const void* data, uint32_t, bool yflip) override
    {
        if (s_cb && s_cb->screenshot)
            s_cb->screenshot(path, w, h, pitch, fmt != bgfx::TextureFormat::RGBA8, data, yflip ? 1 : 0);
    }
};

static BridgeCallback s_callback;

} // namespace pddi
} // namespace hulk

using namespace hulk::pddi;

extern "C" {

// The front end's operator new / delete natively (tools/native_mac.py GFX_CXX renames its references to these): the
// host's heap, as the Wine image's pddi objects take msvcrt's (wine_link GFX_CXX), never the game's heaps
void* hulk_gfx_op_new(size_t n) { return malloc(n ? n : 1); }
void* hulk_gfx_op_new_array(size_t n) { return malloc(n ? n : 1); }
void hulk_gfx_op_delete(void* p) { free(p); }
void hulk_gfx_op_delete_array(void* p) { free(p); }

int32_t hulk_gfx_renderer(const char* r)
{
    if (!r || !*r)
        return bgfx::RendererType::Count;
    if (!strcmp(r, "metal"))
        return bgfx::RendererType::Metal;
    if (!strcmp(r, "vulkan"))
        return bgfx::RendererType::Vulkan;
    if (!strcmp(r, "gl"))
        return bgfx::RendererType::OpenGL;
    if (!strcmp(r, "noop"))
        return bgfx::RendererType::Noop;
    if (!strcmp(r, "d3d11"))
        return bgfx::RendererType::Direct3D11;
    if (!strcmp(r, "d3d12"))
        return bgfx::RendererType::Direct3D12;
    return bgfx::RendererType::Count;
}

uint32_t hulk_gfx_sink_init(const SinkInit* in)
{
    SinkInit init = *in;
    s_cb = (const hulk_gfx_callbacks*)in->callback;
    init.callback = s_cb ? (bgfx::CallbackI*)&s_callback : 0;
    return bgfxSink()->init(init) ? 1 : 0;
}
void hulk_gfx_sink_shutdown(void) { bgfxSink()->shutdown(); }
uint32_t hulk_gfx_sink_up(void) { return bgfxSink()->up() ? 1 : 0; }
const char* hulk_gfx_sink_name(void) { return bgfxSink()->name(); }
void hulk_gfx_sink_caps(SinkCaps* out) { *out = bgfxSink()->caps(); }
void hulk_gfx_sink_resize_back_buffer(uint32_t w, uint32_t h) { bgfxSink()->resizeBackBuffer(w, h); }
uint32_t hulk_gfx_sink_frame_targets(uint32_t w, uint32_t h) { return bgfxSink()->frameTargets(w, h) ? 1 : 0; }
uint32_t hulk_gfx_sink_offscreen(void) { return bgfxSink()->offscreen() ? 1 : 0; }
uint32_t hulk_gfx_sink_scene_target(void) { return bgfxSink()->sceneTarget() ? 1 : 0; }
uint32_t hulk_gfx_sink_target_width(void) { return bgfxSink()->targetWidth(); }
uint32_t hulk_gfx_sink_target_height(void) { return bgfxSink()->targetHeight(); }
void hulk_gfx_sink_destroy_frame_targets(void) { bgfxSink()->destroyFrameTargets(); }
uint32_t hulk_gfx_sink_create_texture(const SinkTextureDesc* d) { return bgfxSink()->createTexture(*d); }
uint32_t hulk_gfx_sink_update_texture(uint32_t texture, uint32_t level, uint32_t w, uint32_t h, const void* data,
                                      uint32_t pitch, uint32_t size)
{
    return bgfxSink()->updateTexture(texture, level, w, h, data, pitch, size) ? 1 : 0;
}
void hulk_gfx_sink_destroy_texture(uint32_t texture) { bgfxSink()->destroyTexture(texture); }
uint32_t hulk_gfx_sink_update_vertex_buffer(uint32_t b, const SinkVertexData* d)
{
    return bgfxSink()->updateVertexBuffer(b, *d);
}
uint32_t hulk_gfx_sink_update_index_buffer(uint32_t b, const uint16_t* indices, uint32_t count, uint32_t owner)
{
    return bgfxSink()->updateIndexBuffer(b, indices, count, owner);
}
void hulk_gfx_sink_destroy_buffers(uint32_t vb, uint32_t ib) { bgfxSink()->destroyBuffers(vb, ib); }
SinkVertex* hulk_gfx_sink_alloc_transient(uint32_t count, uint32_t* token)
{
    return bgfxSink()->allocTransient(count, token);
}
void hulk_gfx_sink_create_copy_target(uint32_t w, uint32_t h, SinkTarget* out)
{
    *out = bgfxSink()->createCopyTarget(w, h);
}
void hulk_gfx_sink_create_render_target(uint32_t w, uint32_t h, SinkTarget* out)
{
    *out = bgfxSink()->createRenderTarget(w, h);
}
void hulk_gfx_sink_destroy_copy_target(SinkTarget* t) { bgfxSink()->destroyCopyTarget(t); }
void hulk_gfx_sink_destroy_render_target(SinkTarget* t) { bgfxSink()->destroyRenderTarget(t); }
void hulk_gfx_sink_frame_copy(SinkTarget* out) { *out = bgfxSink()->frameCopy(); }
uint32_t hulk_gfx_sink_front_buffer(void) { return bgfxSink()->frontBuffer(); }
void hulk_gfx_sink_set_pass(const SinkPass* p) { bgfxSink()->setPass(*p); }
void hulk_gfx_sink_copy_frame(uint32_t pass, const SinkTarget* dst) { bgfxSink()->copyFrame((uint16_t)pass, *dst); }
uint32_t hulk_gfx_sink_draw_resources(void) { return bgfxSink()->drawResources() ? 1 : 0; }
uint32_t hulk_gfx_sink_has_vertex_program(uint32_t vp) { return bgfxSink()->hasVertexProgram(vp) ? 1 : 0; }
uint32_t hulk_gfx_sink_prepare_pipeline(DrawPacket* p) { return bgfxSink()->preparePipeline(*p) ? 1 : 0; }
void hulk_gfx_sink_submit_draw(const DrawPacket* p) { bgfxSink()->submitDraw(*p); }
void hulk_gfx_sink_combiner_stats(int32_t* generated, int32_t* generic, int32_t* draws)
{
    bgfxSink()->combinerStats(generated, generic, draws);
}
uint32_t hulk_gfx_sink_fx_resources(void) { return bgfxSink()->fxResources() ? 1 : 0; }
void hulk_gfx_sink_fx_draw(const FxPacket* p) { bgfxSink()->fxDraw(*p); }
uint32_t hulk_gfx_sink_create_query(void) { return bgfxSink()->createQuery(); }
uint32_t hulk_gfx_sink_query_result(uint32_t q, int32_t* pixels) { return bgfxSink()->queryResult(q, pixels); }
void hulk_gfx_sink_present(const SinkPresent* p) { bgfxSink()->present(*p); }
void hulk_gfx_sink_frame(void) { bgfxSink()->frame(); }
void hulk_gfx_sink_request_screenshot(const char* path) { bgfxSink()->requestScreenshot(path); }
void hulk_gfx_sink_context_destroyed(void) { bgfxSink()->contextDestroyed(); }

} // extern "C"

#elif HULK_PDDI_NATIVE

#include "bgfx_pddi.h"
#include "bgfx_bridge.h"

namespace hulk {
namespace pddi {

class BridgeSink final : public DrawSink {
  public:
    bool init(const SinkInit& in) override { return hulk_gfx_sink_init(&in) != 0; }
    void shutdown() override { hulk_gfx_sink_shutdown(); }
    bool up() const override { return hulk_gfx_sink_up() != 0; }
    const char* name() const override { return hulk_gfx_sink_name(); }
    SinkCaps caps() const override
    {
        SinkCaps c;
        hulk_gfx_sink_caps(&c);
        return c;
    }
    void resizeBackBuffer(uint32_t w, uint32_t h) override { hulk_gfx_sink_resize_back_buffer(w, h); }
    bool frameTargets(uint32_t w, uint32_t h) override { return hulk_gfx_sink_frame_targets(w, h) != 0; }
    bool offscreen() const override { return hulk_gfx_sink_offscreen() != 0; }
    bool sceneTarget() const override { return hulk_gfx_sink_scene_target() != 0; }
    uint32_t targetWidth() const override { return hulk_gfx_sink_target_width(); }
    uint32_t targetHeight() const override { return hulk_gfx_sink_target_height(); }
    void destroyFrameTargets() override { hulk_gfx_sink_destroy_frame_targets(); }
    uint32_t createTexture(const SinkTextureDesc& d) override { return hulk_gfx_sink_create_texture(&d); }
    bool updateTexture(uint32_t texture, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t pitch,
                       uint32_t size) override
    {
        return hulk_gfx_sink_update_texture(texture, level, w, h, data, pitch, size) != 0;
    }
    void destroyTexture(uint32_t texture) override { hulk_gfx_sink_destroy_texture(texture); }
    uint32_t updateVertexBuffer(uint32_t b, const SinkVertexData& d) override
    {
        return hulk_gfx_sink_update_vertex_buffer(b, &d);
    }
    uint32_t updateIndexBuffer(uint32_t b, const uint16_t* indices, uint32_t count, uint32_t owner) override
    {
        return hulk_gfx_sink_update_index_buffer(b, indices, count, owner);
    }
    void destroyBuffers(uint32_t vb, uint32_t ib) override { hulk_gfx_sink_destroy_buffers(vb, ib); }
    SinkVertex* allocTransient(uint32_t count, uint32_t* token) override
    {
        return hulk_gfx_sink_alloc_transient(count, token);
    }
    SinkTarget createCopyTarget(uint32_t w, uint32_t h) override
    {
        SinkTarget t;
        hulk_gfx_sink_create_copy_target(w, h, &t);
        return t;
    }
    SinkTarget createRenderTarget(uint32_t w, uint32_t h) override
    {
        SinkTarget t;
        hulk_gfx_sink_create_render_target(w, h, &t);
        return t;
    }
    void destroyCopyTarget(SinkTarget* t) override { hulk_gfx_sink_destroy_copy_target(t); }
    void destroyRenderTarget(SinkTarget* t) override { hulk_gfx_sink_destroy_render_target(t); }
    SinkTarget frameCopy() override
    {
        SinkTarget t;
        hulk_gfx_sink_frame_copy(&t);
        return t;
    }
    uint32_t frontBuffer() override { return hulk_gfx_sink_front_buffer(); }
    void setPass(const SinkPass& p) override { hulk_gfx_sink_set_pass(&p); }
    void copyFrame(uint16_t pass, SinkTarget dst) override { hulk_gfx_sink_copy_frame(pass, &dst); }
    bool drawResources() override { return hulk_gfx_sink_draw_resources() != 0; }
    bool hasVertexProgram(uint32_t vp) override { return hulk_gfx_sink_has_vertex_program(vp) != 0; }
    bool preparePipeline(DrawPacket& p) override { return hulk_gfx_sink_prepare_pipeline(&p) != 0; }
    void submitDraw(const DrawPacket& p) override { hulk_gfx_sink_submit_draw(&p); }
    void combinerStats(int* generated, int* generic, int* draws) override
    {
        hulk_gfx_sink_combiner_stats(generated, generic, draws);
    }
    bool fxResources() override { return hulk_gfx_sink_fx_resources() != 0; }
    void fxDraw(const FxPacket& p) override { hulk_gfx_sink_fx_draw(&p); }
    uint32_t createQuery() override { return hulk_gfx_sink_create_query(); }
    uint32_t queryResult(uint32_t q, int32_t* pixels) override { return hulk_gfx_sink_query_result(q, pixels); }
    void present(const SinkPresent& p) override { hulk_gfx_sink_present(&p); }
    void frame() override { hulk_gfx_sink_frame(); }
    void requestScreenshot(const char* path) override { hulk_gfx_sink_request_screenshot(path); }
    void contextDestroyed() override { hulk_gfx_sink_context_destroyed(); }
};

DrawSink* bridgeSink()
{
    static BridgeSink* s_sink;            // made on first use, never destroyed (no static constructor or atexit)
    if (!s_sink)
        s_sink = new BridgeSink();
    return s_sink;
}

} // namespace pddi
} // namespace hulk

#endif
