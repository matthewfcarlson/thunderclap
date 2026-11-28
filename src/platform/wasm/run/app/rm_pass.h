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
    kNightLights,                         // wlook2 (docs/night.md): 0 off, 1 the city's lamps and glows light the world
    kAtmosphere,                          // wlook2 (docs/night.md): 0 the game's sky and fog, 1 enhanced
    kGrade,                               // wlook1 (docs/look.md "Colour grade"): 0 original, 1 natural, 2 cinematic
    kGrass,                               // wgrass1 (docs/grass.md): 0 the game's flat ground, 1 blades low, 2 high
    kUpscaler = 17,                       // wperf1 (docs/performance.md): 0 off, 1 auto, 2 FSR 1; wperf2: 3 temporal
                                          // (ours), 4 MetalFX (macOS; elsewhere ours)
    kRenderScale,                         // wperf1: the scene target's share of the render resolution, percent
    kPerfOverlay,                         // wperf1 (perfov.cpp): 0 off, 1 the FPS readout, 2 with the graph
    kHudRes,                              // whud1 (hud.cpp): 0 the HUD at the render size, 1 at the present size
    kParticles,                           // wfx1 (particles.cpp, docs/particles.md): 0 the game's, 1 soft and lit
    kCharLight,                           // whulk1 (lighting.cpp): 0 the characters as lit, 1 rim, wrap, detail normals
    kContact,                             // wshadow1 (contact.cpp): 0 off, 1 screen-space contact shadows
    kBounce,                              // wshadow1 (contact.cpp): 0 off, 1 one bounce of the lit surfaces' colour
    kQualityCount
};
struct Settings {
    int value[kQualityCount];
    int operator[](Quality q) const { return value[q]; }
};
const Settings& settings();            // (the effective values: upscalerTemporal sets the msaa row to TAA)
// wperf2: the Upscaler row's choice in `menu` is a temporal upscaler (it implies TAA: the passes then see kMsaa 1)
bool upscalerTemporal(const Settings& menu);

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
    // wgrass1: a prim buffer's indices written (the sink's index buffer id after the write) / an index buffer dropped
    virtual void indices(uint32_t, const uint16_t*, uint32_t) {}
    virtual void indicesDropped(uint32_t) {}
    // wgrass1: a texture made (`vid` the module's id), a level of it written (the game's own bytes, before any texture
    // pack replaces them), dropped
    virtual void textureCreated(uint32_t, const hulk::pddi::SinkTextureDesc&) {}
    virtual void textureLevel(uint32_t, uint32_t, uint32_t, uint32_t, const void*, uint32_t) {}
    virtual void textureDropped(uint32_t) {}
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
    // whud1: keep the frame's tail (the scene draws after its last effect: the HUD) for this pass's postScene
    // (rm::drawTail) and draw it into the scene target only after the post views; asked at the frame's first sink call,
    // honoured only with renumbering (midFrame)
    virtual bool holdTail() const { return false; }
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
void indices(uint32_t sinkIndexBuffer, const uint16_t* idx, uint32_t n);    // (wgrass1)
void indicesDropped(uint32_t sinkIndexBuffer);
void textureCreated(uint32_t vid, const hulk::pddi::SinkTextureDesc& d);
void textureLevel(uint32_t vid, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t size);
void textureDropped(uint32_t vid);
void setPass(const hulk::pddi::SinkPass& p);       // instead of hulk_gfx_sink_set_pass
void present(const hulk::pddi::SinkPresent& p);    // instead of hulk_gfx_sink_present
void frame();                                      // after the sink's frame
void traceShot();                                  // (HULK_RM_TRACE: a screenshot was requested)

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

// wlook2: a draw's transient vertices as the sink holds them (app.cpp / interp.cpp hand them over before the draw
// reaches the passes); null when the draw is a buffer draw or they are unknown
void setTransient(const hulk::pddi::SinkVertex* v, uint32_t count);
const hulk::pddi::SinkVertex* transientVertices(const hulk::pddi::DrawPacket& p, uint32_t* count);

// whud1 (Pass::holdTail): draws are being kept (destroys wait for the frame's end: interp.cpp); drawTail: the frame's
// tail into frame buffer fb (w x h pixels), its passes' viewports scaled by sx, sy, in views from `view` (advanced; the
// post views' range); valid in postScene
bool holdingDraws();
void drawTail(uint16_t& view, uint16_t fb, uint32_t w, uint32_t h, float sx, float sy);

// the Fog row (port_settings.c fog): 0 the game's, 1 reduced, 2 off
int fogSetting();

// a runner shader (run/app/shaders, tools/rm_shaders.py) by name for the renderer's profile; kNoView (0xffff): none
uint16_t loadShader(const char* name);
// wlinux2 (lighting.cpp): a copy of a draw already submitted, before another pass submits it again: the per-pixel
// program's samplers (stages 4 and 5) bound again, as bgfx drops texture bindings at each submit
void lightingRebind(const hulk::pddi::DrawPacket& q);
// wfx1 (particles.cpp): the same for a copy of a soft particle draw (its stages 4, 5 and 6); lightingRebind calls it
void particlesRebind(const hulk::pddi::DrawPacket& q);
// wlook3: the grass blades are drawn after ambient occlusion is applied (thin blades in the depth read as occluders:
// the lawns turned to dark stubble). aoPending (ao.cpp): the occlusion is on and still to come this frame (a ground
// draw's blades then wait); grassWaiting (grass.cpp): blades are waiting; grassAfterAo: the occlusion ran, `view` an
// empty view of the world pass after its apply for them (kNoView: none, they go into their ground draws' views)
bool aoPending();
bool grassWaiting();
void grassAfterAo(uint16_t view);

// app.cpp's (render resolution): the scene target and the frame-sized copies are made again between frames
void appTargetsChanged();
// app.cpp's (wperf1, the Render Scale row): the scene target at pct percent of the render resolution (between frames)
void setRenderScale(int pct);
// the present being drawn (valid in postScene; null elsewhere): its rectangle in the window is the upscalers' output
const hulk::pddi::SinkPresent* currentPresent();
// the scene target's samples (an occlusion query's count is per sample)
uint32_t sceneSamples();
// the pass (SinkPass id) draws into the scene target (this frame's last setPass of that id)
bool passIsScene(uint16_t pass);

} // namespace rm
