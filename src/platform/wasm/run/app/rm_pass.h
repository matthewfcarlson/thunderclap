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
enum Quality : uint32_t {
    kMipmaps = 1, kAniso, kMsaa, kFarField, kDrawDistance, kLighting, kDynLights,
    kHdr, kAo, kShadows,                  // wr3a (docs/hdr-shadows.md): 0 off; shadows 1 low, 2 high
    kWindows,                             // wlook0 (docs/look.md): 0 the game's glass, 1 interiors
    kReflections,                         // wssr1 (docs/reflections.md): 0 off, 1 low, 2 high
    kQualityCount
};
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
    // a game draw about to reach the sink (direct or replayed), before any pass's draw: a pass may still change it
    // (wpol1: a choice that depends on what the presented frame has drawn so far; `packet` sees an interpolated
    // update's draws when they are recorded, before any of its frames is drawn)
    virtual void late(hulk::pddi::DrawPacket&) {}
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
    // wr3a: every pass the game sets (its own id, and the pass as the sink gets it), after sceneBegin
    virtual void passSet(uint16_t gamePass, const hulk::pddi::SinkPass&) {}
    // wr3a: the game's frame copies and effect quads as they reach the sink (before), `pass` the game's pass id
    virtual void copy(uint16_t pass, const hulk::pddi::SinkTarget& dst) {}
    virtual void fx(const hulk::pddi::FxPacket&) {}
    // a pass that draws between the game's passes this frame (rm::newView, rm::splitPass): asked at the frame's
    // first pass; while any pass says yes the game's pass ids are renumbered in submission order with the runner's
    // views among them (off: the game's ids reach the sink unchanged)
    virtual bool midFrame() const { return false; }
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

// wr3a: mid-frame views (Pass::midFrame). newView: a bgfx view that runs after everything submitted so far and
// before the game's next pass (kNoView: none left this frame, or no pass asked for them); splitPass: the game's
// current pass goes on in a new view (same target and viewport, no clear) so views can run between its draws so far
// and the rest; returns the old view (the draws so far), kNoView when it could not. sinkView: the view a game pass id
// draws in now. Draw packets reach the passes' hooks with their sink view in `pass`.
enum : uint16_t { kNoView = 0xffff };
uint16_t newView();
uint16_t splitPass();
uint16_t sinkView(uint16_t gamePass);
// n views (out[0..n-1], in order) that run before the game pass `gamePass`'s next work: after what it drew so far when
// it is the current pass (it goes on in a new view), before it when it has not started; false: none to be had
bool viewsBefore(uint16_t gamePass, int n, uint16_t* out);
// n views before the rest of the game's current pass (the draw being handed to the passes' draw hooks goes after them)
bool viewsHere(int n, uint16_t* out);
// the game's id of the pass being drawn now (stable when a pass is split; 0xffff before the frame's first pass)
uint16_t currentGamePass();
void copyFrame(uint16_t pass, const hulk::pddi::SinkTarget& dst);   // instead of hulk_gfx_sink_copy_frame
void fxDraw(const hulk::pddi::FxPacket& p);                         // instead of hulk_gfx_sink_fx_draw

// a runner shader (run/app/shaders, tools/rm_shaders.py) by name for the renderer's profile; kNoView (0xffff): none
uint16_t loadShader(const char* name);

// app.cpp's (render resolution): the scene target and the frame-sized copies are made again between frames
void appTargetsChanged();
// the scene target's samples (an occlusion query's count is per sample)
uint32_t sceneSamples();
// the pass (SinkPass id) draws into the scene target (this frame's last setPass of that id)
bool passIsScene(uint16_t pass);

} // namespace rm
