// The C bridge between the pddi front end and the bgfx sink on the native builds (HULK_PDDI_NATIVE; docs/native-mac.md
// "The graphics backend").
//
// Why. The front end's classes stand in for the game's pddi classes, so the native builds compile them with the game's
// MS C++ ABI (aarch64-pc-windows-msvc, retargeted: tools/native_mac.py). bgfx on the host is Itanium C++ (and its
// Metal renderer Objective-C++), which the MS ABI front end cannot call. The draw sink (draw_sink.h) is the one place
// the front end hands work to a graphics API, and its packets are plain structs of fixed-width types, so the bridge is
// that interface as extern "C" functions: the bgfx sink (bgfx_sink.cpp) and the host half of this bridge
// (bgfx_bridge.cpp, HULK_PDDI_BRIDGE_HOST) are compiled for the host against the host bgfx; the front end's half
// (bgfx_bridge.cpp, HULK_PDDI_NATIVE) is a DrawSink whose members call these functions. The Wine build keeps calling
// the sink directly (neither half is compiled there; tools/wine_gfx.py leaves this file out).
//
// Rules (both sides of each call are compiled by different front ends for the same AArch64 target):
// - Arguments and results are pointers, 32/64-bit integers, floats and void: no bool, no 8/16-bit integers (the Apple
//   ABI has the caller widen those, the Windows one does not), no structs by value (results come back through a
//   pointer), no variadic functions (text is formatted on the side that has it).
// - The structs passed by pointer are draw_sink.h's (fixed-width fields, the same layout on both sides) and the two
//   below. bgfx's callback interface (bgfx::CallbackI, an Itanium vtable) is the host half's; it calls the front end
//   back through hulk_gfx_callbacks (C function pointers, a const table of the front end's).
#pragma once

#include <stdint.h>

#include "draw_sink.h"

#ifdef __cplusplus
extern "C" {
#endif

// The front end's side of bgfx's callback interface (sdl_platform.cpp natively; the host half's CallbackI calls these)
typedef struct hulk_gfx_callbacks {
    void (*log)(const char* text);                        // a formatted line: the sink's logf, bgfx's trace errors
    void (*fatal)(const char* file, uint32_t line, uint32_t code, const char* text);   // bgfx::Fatal; does not return
    // a screenshot bgfx read back (requestScreenshot): 32-bit pixels, BGRA unless bgra is 0 (then RGBA)
    void (*screenshot)(const char* path, uint32_t width, uint32_t height, uint32_t pitch, uint32_t bgra,
                       const void* data, uint32_t yflip);
} hulk_gfx_callbacks;

// The renderer for SinkInit::renderer: HULK_GFX_RENDERER's name (metal, vulkan, gl, noop, d3d11, d3d12; 0 or "" for
// the platform's default), as the host bgfx numbers it
int32_t hulk_gfx_renderer(const char* name);

// ---- the DrawSink members (draw_sink.h), one function each; uint32_t results that are bool there are 0 / 1
// init: SinkInit::callback is a const hulk_gfx_callbacks* (or 0)
uint32_t hulk_gfx_sink_init(const hulk::pddi::SinkInit* init);
void hulk_gfx_sink_shutdown(void);
uint32_t hulk_gfx_sink_up(void);
const char* hulk_gfx_sink_name(void);
void hulk_gfx_sink_caps(hulk::pddi::SinkCaps* out);
void hulk_gfx_sink_resize_back_buffer(uint32_t width, uint32_t height);
uint32_t hulk_gfx_sink_frame_targets(uint32_t width, uint32_t height);
uint32_t hulk_gfx_sink_offscreen(void);
uint32_t hulk_gfx_sink_scene_target(void);
uint32_t hulk_gfx_sink_target_width(void);
uint32_t hulk_gfx_sink_target_height(void);
void hulk_gfx_sink_destroy_frame_targets(void);
uint32_t hulk_gfx_sink_create_texture(const hulk::pddi::SinkTextureDesc* desc);
uint32_t hulk_gfx_sink_update_texture(uint32_t texture, uint32_t level, uint32_t width, uint32_t height,
                                      const void* data, uint32_t pitch, uint32_t size);
void hulk_gfx_sink_destroy_texture(uint32_t texture);
uint32_t hulk_gfx_sink_update_vertex_buffer(uint32_t buffer, const hulk::pddi::SinkVertexData* data);
uint32_t hulk_gfx_sink_update_index_buffer(uint32_t buffer, const uint16_t* indices, uint32_t count, uint32_t owner);
void hulk_gfx_sink_destroy_buffers(uint32_t vertexBuffer, uint32_t indexBuffer);
hulk::pddi::SinkVertex* hulk_gfx_sink_alloc_transient(uint32_t count, uint32_t* token);
void hulk_gfx_sink_create_copy_target(uint32_t width, uint32_t height, hulk::pddi::SinkTarget* out);
void hulk_gfx_sink_create_render_target(uint32_t width, uint32_t height, hulk::pddi::SinkTarget* out);
void hulk_gfx_sink_destroy_copy_target(hulk::pddi::SinkTarget* t);
void hulk_gfx_sink_destroy_render_target(hulk::pddi::SinkTarget* t);
void hulk_gfx_sink_frame_copy(hulk::pddi::SinkTarget* out);
uint32_t hulk_gfx_sink_front_buffer(void);
void hulk_gfx_sink_set_pass(const hulk::pddi::SinkPass* pass);
void hulk_gfx_sink_copy_frame(uint32_t pass, const hulk::pddi::SinkTarget* dst);
uint32_t hulk_gfx_sink_draw_resources(void);
uint32_t hulk_gfx_sink_has_vertex_program(uint32_t vertexProgram);
uint32_t hulk_gfx_sink_prepare_pipeline(hulk::pddi::DrawPacket* p);
void hulk_gfx_sink_submit_draw(const hulk::pddi::DrawPacket* p);
void hulk_gfx_sink_combiner_stats(int32_t* generated, int32_t* generic, int32_t* draws);
uint32_t hulk_gfx_sink_fx_resources(void);
void hulk_gfx_sink_fx_draw(const hulk::pddi::FxPacket* p);
uint32_t hulk_gfx_sink_create_query(void);
uint32_t hulk_gfx_sink_query_result(uint32_t query, int32_t* pixels);
void hulk_gfx_sink_present(const hulk::pddi::SinkPresent* p);
void hulk_gfx_sink_frame(void);
void hulk_gfx_sink_request_screenshot(const char* path);
void hulk_gfx_sink_context_destroyed(void);

#ifdef __cplusplus
}
#endif

#if HULK_PDDI_NATIVE
namespace hulk {
namespace pddi {
DrawSink* bridgeSink();        // the front end's half (bgfx_bridge.cpp): the native builds' drawSink()
} // namespace pddi
} // namespace hulk
#endif
