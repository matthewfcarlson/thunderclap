// The runner's render passes (wr2, D236; docs/remaster.md 5.3, docs/wasm-port.md "Renderer options").
//
// The app's picture options are passes around the game's draw stream: each sees the runner's settings, the game's
// draw packets as they go to the sink, and two points of each presented frame: the scene target's first pass (before
// the game draws) and the end of the game's frame (before the present: the post-processing point, drawn into the
// scene target in views of the runner's own). Every sink call of the runner's (app.cpp directly, interp.cpp's replays
// of a recorded update) goes through here, so a pass works the same at every display rate. Output only: nothing here
// reads or writes the module's memory.
//
// It is the R2 form of remaster.md 5.3's interface (one structure the later RHI passes keep): a pass registers itself
// (HULK_RM_REGISTER_PASS, no central list), runs in `order()`, and draws with bgfx today; under R1 the same hooks get
// the RHI's command context instead.
#pragma once
#include <stdint.h>

#include "pddi/draw_sink.h"

namespace rm {

// The Video Options rows of the runner's passes (port_settings.c; gfx_quality what = the index below)
enum Quality : uint32_t { kMipmaps = 1, kAniso, kMsaa, kFarField, kDrawDistance, kQualityCount };
struct Settings {
    int value[kQualityCount];
    int operator[](Quality q) const { return value[q]; }
};
const Settings& settings();

// The scene target as the runner's passes draw into it (sink ids; width/height in pixels at the render size)
struct Scene {
    uint32_t frameBuffer, colour, depth, samples, width, height;
};
// bgfx views the runner's passes may use, in this order after every game pass and before the present (the game uses
// views 0..250, the present 254/255; draw_sink.h SinkCaps::lastPass)
enum : uint16_t { kFirstView = 251, kViewCount = 3 };

class Pass {
  public:
    virtual ~Pass() {}
    virtual const char* name() const = 0;
    virtual int order() const { return 0; }
    virtual void settingsChanged(const Settings&) {}
    // a game draw as the runner hands it on (both prepare_pipeline and submit see the same packet)
    virtual void packet(hulk::pddi::DrawPacket&) {}
    // a game draw about to reach the sink (direct or replayed): a pass may submit draws of its own before it
    virtual void draw(const hulk::pddi::DrawPacket&) {}
    // a prim buffer the game wrote (the sink's id after the write) / the sink buffers of one it dropped
    virtual void vertices(uint32_t, const hulk::pddi::SinkVertexData&) {}
    virtual void buffersDropped(uint32_t) {}
    // the frame's first pass into the scene target (`pass` may be changed: the clear, the viewport)
    virtual void sceneBegin(hulk::pddi::SinkPass&) {}
    // the game's frame is drawn; the present follows. `view` is the next free runner view (kFirstView..); a pass that
    // draws advances it
    virtual void postScene(const Scene&, uint16_t& view) {}
    virtual void frame() {}               // between presented frames
};

struct Registrar {
    explicit Registrar(Pass* p);
};
#define HULK_RM_REGISTER_PASS(T) \
    static T s_rmPass_##T;        \
    static rm::Registrar s_rmReg_##T(&s_rmPass_##T)

// ---- the runner's side (app.cpp, interp.cpp)
void setQuality(uint32_t what, int32_t value);     // a Video Options row changed (gfx_quality)
void packet(hulk::pddi::DrawPacket& p);
void submitDraw(const hulk::pddi::DrawPacket& p);  // instead of hulk_gfx_sink_submit_draw
void vertices(uint32_t sinkBuffer, const hulk::pddi::SinkVertexData& d);
void buffersDropped(uint32_t sinkBuffer);
void setPass(const hulk::pddi::SinkPass& p);       // instead of hulk_gfx_sink_set_pass
void present(const hulk::pddi::SinkPresent& p);    // instead of hulk_gfx_sink_present
void frame();                                      // after the sink's frame

// app.cpp's (render resolution): the scene target and the frame-sized copies are made again between frames
void appTargetsChanged();
// the scene target's samples (an occlusion query's count is per sample)
uint32_t sceneSamples();

} // namespace rm
