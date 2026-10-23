// Common pieces of the pddi backend (src/platform/sdl/pddi/): class ids, stub logging, the base-forwarding macros
// and the draw record the backend writes (the same record the hybrid build's drawlog hook writes; see
// docs/graphics-backend.md "Test strategy" and tools/drawlog_diff.py).
//
// Builds: HULK_PDDI_HOST (macOS test build: logged stubs for the base slots, a smoke test) and HULK_PDDI_GAME (the
// native i686 image: base slots call the tree's pddi base functions by XBE address, game_base.h).
#pragma once

#include <stdint.h>

#if !defined(HULK_PDDI_HOST) && !defined(HULK_PDDI_GAME)
#error "build with -DHULK_PDDI_HOST=1 or -DHULK_PDDI_GAME=1 (tools/native_gfx.py pddi)"
#endif

namespace hulk {
namespace pddi {

enum ClassId {
    kClassDevice,
    kClassDisplay,
    kClassContext,
    kClassTexture,
    kClassPrimBuffer,
    kClassPrimBufferStream,
    kClassPrimStream,
    kClassShader,
    kClassExtAntialiasControl,
    kClassExtFrameBufferTexture,
    kClassExtFramebufferEffects,
    kClassExtGammaControl,
    kClassExtGlobalProjectedTexture,
    kClassExtHardwareSkinning,
    kClassExtReadPixels,
    kClassExtVertexProgram,
    kClassExtVisibilityTest,
    kClassCount
};

// The shader classes the data uses (docs/graphics-backend.md section 2), plus the fallback.
enum ShaderKind {
    kShaderSimple,          // "simple", "lightweight"
    kShaderLayered,         // "layered"
    kShaderBuilding,        // "layeredReflect"
    kShaderRefl,            // "environment"
    kShaderRefract,         // "refract"
    kShaderFBEffects,       // "fbeffectsshader"
    kShaderError,           // "error"
    kShaderKindCount
};

// pddi primitive kinds, as the game's tables map them (0x4d3650: to D3D primitive types 5, 6, 2, 4, 1)
enum PrimKind { kPrimTriList, kPrimTriStrip, kPrimLineList, kPrimLineStrip, kPrimPoints };

// Vertex flags (the shader's flags word / BeginPrims' third argument, as d3dPrimStream 0x31be40 reads them)
enum {
    kVertexNormal = 0x10,
    kVertexColour = 0x20,
    kVertexColourSets = 0x4000,
    kVertexUvMask = 0xf
};

// A slot of ours that is still a stub: logged on its first call, counted on every call.
void stubHit(int cls, int slot, const char* fn);
// Calls per (class, slot) so far; the report lists every stub reached.
unsigned stubCalls(int cls, int slot);
void stubReport();

typedef void (*LogSink)(const char* line);
void setLogSink(LogSink sink);
void logf(const char* fmt, ...);
void logLine(char* buf, unsigned size, const char* fmt, ...);   // snprintf (the image's CRT name differs)

// The value a stub returns: zero of whatever the slot returns.
struct Default {
    template <class T> operator T() const { return T(); }
};

// One draw, as the hybrid build's drawlog hook records it (hybrid/hooks.cpp HYBRID_DRAWLOG, keep in sync): 24 words.
struct DrawRecord {
    uint32_t frame;
    uint32_t seq;           // draw index within the frame | site << 24 (hybrid: which D3D draw call site)
    uint32_t prim;          // D3D primitive type (1 points .. 6 tri strip; pddi kinds map through 0x4d3650)
    uint32_t count;         // vertex or index count passed to the draw
    uint32_t shader;        // hybrid: the current shader's vftable; native: 0x8000 | ShaderKind
    uint32_t shaderId;      // the shader's word at +0xc (hybrid); 0 (native)
    uint32_t tex[4];        // texture per stage: first-seen ordinal (1-based; 0 none)
    uint32_t stateA[6];     // the render state block at *(context+0x4c): cull at +4, ...
    uint32_t stateS[6];     // the stencil block at *(context+0x58)
    uint32_t fog;           // the fog block's enable byte (*(context+0x54)+4)
    uint32_t mtx;           // FNV-1a of the top matrices of the context's stacks 0..3
};

// The native backend's draw log: a ring the platform can dump (same layout as the hybrid ring).
void drawlogEnable(uint32_t firstFrame, uint32_t every, uint32_t lastFrame);
void drawlogAppend(const DrawRecord& r);
uint32_t drawlogCount();
const DrawRecord* drawlogAt(uint32_t i);      // i < drawlogCount(), oldest kept first
bool drawlogWants(uint32_t frame);
// The frame number draw records carry: the game-clock frame when the image reports GameClock updates
// (hulk_pddi_clock_tick, the hybrid build's g_hybrid.frame definition), else the display's present count.
uint32_t drawlogFrame(uint32_t presents);
bool drawlogGameFrames();                     // true once hulk_pddi_clock_tick has been called
uint32_t drawlogTexture(const void* texture);  // first-seen ordinal (1-based; 0 for none), as the hybrid log's
bool drawlogDump(const char* path);           // binary: "PDL1", count, records
unsigned drawCount();                         // draws submitted since start
void countDraw();

class bgfxDisplay;
#if HULK_PDDI_GAME && defined(_WIN32)
// The native image's window and run-time options (sdl_platform.cpp)
void platformInit();
bool platformDisplayInit(bgfxDisplay* display, unsigned width, unsigned height);
void platformPump();
void platformBeforeFrame(unsigned frame);
void platformAfterFrame(unsigned frame);
void platformFramePace();     // HULK_FPS_CAP: wait out the rest of the frame period after the present
class bgfxContext;
void platformSelfTest(bgfxContext* context, bgfxDisplay* display);
#endif

} // namespace pddi
} // namespace hulk

#define PDDI_STUB(slot) ::hulk::pddi::stubHit(kClass, slot, __FUNCTION__)

#if HULK_PDDI_GAME
#include "game_base.h"
#define PDDI_BASE(slot, call) return reinterpret_cast< ::hulk::pddi::GameBase*>(this)->call
#define PDDI_BASE_V(slot, call) reinterpret_cast< ::hulk::pddi::GameBase*>(this)->call
#else
#define PDDI_BASE(slot, call) do { PDDI_STUB(slot); return ::hulk::pddi::Default(); } while (0)
#define PDDI_BASE_V(slot, call) PDDI_STUB(slot)
#endif
