// The draw sink: what the pddi front end hands to a renderer (docs/remaster.md D3, docs/graphics-backend.md
// section 15).
//
// The front end (the 23 pddi classes in bgfx_*.cpp: the D3D-state model, the texture-stage combiners, the constant
// file, the matrices and lights, the prim buffers and streams, the draw log) resolves every draw into a DrawPacket
// and every resource change into an event, and calls the one sink the build selects. The sink owns the graphics API:
// programs, buffers, textures, render targets, passes, copies, queries and the present. The faithful sink is bgfx
// (BgfxSink, bgfx_sink.cpp); the remastered renderer (HULK_REMASTER, docs/remaster.md section 5) is meant to be a
// second implementation of this interface, recording packets for its own frame.
//
// Rules for this header:
// - No graphics API types. Handles are sink-assigned 32-bit ids, kSinkNone for none. Enumerations are the pddi /
//   Direct3D meanings the front end already speaks, not an API's.
// - Packets are plain structs of fixed-width types (no bool members, no pointers to front-end classes), so a capture
//   sink can copy them or pass them across the C boundary the remaster renderer sits behind (remaster.md 1.3).
//   Pointers in a packet (constants, matrices, lights) are valid only during the call.
// - The front end makes the same calls in the same order whatever the sink; what the bgfx sink does with them is
//   exactly what the backend did before the split (proven: docs/graphics-backend.md section 15).
#pragma once

#include <stdint.h>

#ifndef HULK_REMASTER
#define HULK_REMASTER 0           // the remastered renderer's build (platform layer only; never the game tree)
#endif
#ifndef HULK_PDDI_SINK_BGFX
#define HULK_PDDI_SINK_BGFX 1     // the faithful bgfx sink (the normal build; the remaster build may carry it, D4)
#endif

namespace hulk {
namespace pddi {

enum : uint32_t { kSinkNone = 0xffff };
enum { kVertexProgramCount = 7 };    // the vertex programs the draw path knows (bgfx_draw.cpp kPrograms)

// What the sink tells the front end once it is up (conventions that change constants and the pass layout)
struct SinkCaps {
    uint8_t homogeneousDepth;     // clip-space z in [-w, w] (OpenGL): the projections' depth row is remapped
    uint8_t originBottomLeft;     // render targets have v = 0 at the bottom: copies of targets are sampled v-flipped
    uint8_t copyTakesPass;        // a render-target copy is a draw in a pass of its own (no blits: OpenGL)
    uint8_t pad;
    uint16_t lastPass;            // the highest pass id draws may use (bgfx: views 0..250; 254/255 are the present's)
    uint16_t pad2;
};

// ---- the backend vertex: one layout for every draw (80 bytes; bgfx_draw.cpp converts the game's layouts to it)
struct SinkVertex {
    float pos[3];
    float normal[3];
    float weight[3];
    uint8_t indices[4];           // bone indices as the NV2A reads v15 (x = the D3DCOLOR's red byte)
    uint32_t colour0;             // D3DCOLOR as in memory (the shaders swizzle)
    uint32_t colour1;
    float uv[4][2];
};

// ---- resources
enum SinkTextureFormat : uint32_t { kSinkBGRA8, kSinkBC1, kSinkBC2, kSinkBC3 };

struct SinkTextureDesc {
    uint32_t width, height;
    uint32_t mips;                // levels beyond the top one the game supplies (Direct3D clamps at the last)
    uint32_t format;              // SinkTextureFormat
    uint32_t ordinal;             // the front end's texture id (first-seen order; the draw log's key)
    uint32_t pddiFormat;          // the game's pddi format (11/12: linear, texel coordinates)
};

// A prim buffer's vertices or indices (re)written: the converted vertices, and the game's own bytes for content keys
struct SinkVertexData {
    const SinkVertex* vertices;
    uint32_t count;
    uint32_t owner;               // the prim buffer's front-end serial (stable for the buffer's life)
    const void* packed;           // the game's packed layout (docs/remaster.md 2.7 `mdl` keys), packedStride a vertex
    uint32_t packedStride;
    uint32_t vertexFlags;         // the pddi vertex flags of the layout
    uint32_t primKind;            // PrimKind
};

// A render target the sink made for the front end: its texture (sampled) and, where the sink needs one, the frame
// buffer to draw into it
struct SinkTarget {
    uint32_t texture;
    uint32_t frameBuffer;
};

// ---- passes (bgfx views): the front end decides when a new pass begins (a clear or a viewport change after draws,
// a copy, a full-screen effect); passes run in id order, their draws in submission order
enum : uint32_t {
    kSinkTargetScene = 0xfffffffeu,    // the game's render target (the scene target, or the back buffer without one)
};
enum : uint16_t { kSinkClearColour = 1, kSinkClearDepth = 2, kSinkClearStencil = 4 };   // = pddi's clear flags
struct SinkPass {
    uint16_t id;
    uint16_t clearFlags;          // kSinkClear*
    uint32_t target;              // kSinkTargetScene or a SinkTarget's frameBuffer
    uint16_t x, y, w, h;          // the viewport (pixels)
    uint32_t clearRgba;           // 0xRRGGBBAA
    float clearDepth;
    uint32_t clearStencil;
};

// ---- the draw packet
// Draw phases (docs/remaster.md 2.6): unknown until a tag point says otherwise (heuristics are the sink's business)
enum SinkPhase : uint32_t {
    kPhaseUnknown, kPhaseSky, kPhaseWorld, kPhaseObjects, kPhaseTranslucent, kPhaseShadow, kPhaseEffects, kPhaseHud,
    kPhaseFrontEnd, kPhaseCount
};

// pddi compare functions (0x4d3a6c): 0 never 1 always 2 less 3 lequal 4 greater 5 gequal 6 equal 7 notequal;
// stencil ops (0x4d3a54): 0 keep 1 zero 2 replace 3 incr 4 decr 5 invert
enum SinkBlendFactor : uint8_t {
    kBlendZero, kBlendOne, kBlendSrcColour, kBlendInvSrcColour, kBlendSrcAlpha, kBlendInvSrcAlpha, kBlendDstAlpha,
    kBlendInvDstAlpha, kBlendDstColour, kBlendInvDstColour, kBlendSrcAlphaSat
};
enum SinkBlendOp : uint8_t { kBlendAdd, kBlendSub, kBlendRevSub, kBlendMin, kBlendMax };

struct SinkRenderState {
    uint8_t prim;                 // PrimKind: 0 tri list, 1 tri strip, 2 line list, 3 line strip, 4 points
    uint8_t writeMask;            // 1 r, 2 g, 4 b, 8 a
    uint8_t depthTest;            // 0: no depth test (and no depth write)
    uint8_t depthFunc;            // pddi compare
    uint8_t depthWrite;
    uint8_t cull;                 // 0 none, 1 counter-clockwise, 2 clockwise (Direct3D's: none under two-sided)
    uint8_t blend;                // 0: off
    uint8_t blendOp;              // SinkBlendOp
    uint8_t srcBlend, dstBlend;   // SinkBlendFactor
    uint8_t stencil;              // 0: off
    uint8_t stencilFunc;          // pddi compare
    uint8_t stencilRef, stencilReadMask;
    uint8_t stencilOp[3];         // fail, depth fail, pass
    uint8_t pad;
};

enum SinkAddress : uint8_t { kAddressWrap, kAddressMirror, kAddressClamp, kAddressBorder };

struct SinkStage {
    uint32_t texture;             // sink texture id (kSinkNone: the stage samples white)
    uint32_t ordinal;             // the front end's texture id (0: none)
    uint8_t address;              // SinkAddress (both u and v)
    uint8_t minPoint, magPoint, mipPoint;   // 1: point sampled, 0: linear
    uint8_t linear;               // a linear texture: texel coordinates (frag[4..5] carry the scale)
    uint8_t fromTarget;           // a copy of a render target
    uint8_t pad[2];
};

// The light set as the draw sees it (camera space; FUN_00321310)
struct SinkLight {
    int32_t type;                 // D3D: 1 point, 2 spot, 3 directional
    uint32_t on;
    float diffuse[4];
    float position[3], direction[3];
    float range, att[3];
};

struct DrawPacket {
    // identity (the remaster's per-draw ids and tags; docs/remaster.md 2.6)
    uint32_t frame;               // the display's present count
    uint32_t drawIndex;           // the draw's index in its frame (the draw log's seq)
    uint32_t phase;               // SinkPhase (set by a tag point, else unknown)
    uint32_t pad0;
    uint64_t instance;            // the drawable a tag point named (0: none)
    uint32_t shaderKind;          // ShaderKind
    uint32_t shaderSerial;        // pddiBaseShader's change serial (+0xc)
    uint32_t bufferOwner;         // the prim buffer's serial (0: a prim stream)
    uint32_t viewMode;            // the view block's mode: 0 perspective, 1 orthographic, 2 pixels
    // the vertex and fragment programs
    uint32_t vertexProgram;       // index into the vertex program table (bgfx_draw.cpp kPrograms; 0 fixed function)
    const char* programName;      // the game's program name ("" fixed function)
    const char* combinerKey;      // the stage combiner's canonical key ("c4.0.2a4.0.2r1|...")
    uint32_t combinerHash;
    uint8_t forceGeneric;         // the self-test: the generic combiner whatever the key
    uint8_t generic;              // out (preparePipeline): drawn by the generic combiner
    uint16_t pad1;
    uint32_t pipeline;            // out (preparePipeline): the sink's program for the pair
    // constants: the program's constant file (the fixed-function layout, vs_vp_ff.sc, or c96.. of the vertex
    // programs), the fragment uniforms (u_pddiFrag: alpha test, fog, texture factor, coordinate scales, stages)
    const float* vertexConstants;
    uint32_t vertexConstantCount; // vec4s
    float frag[16][4];
    SinkStage stage[4];
    SinkRenderState state;
    // the vertex source
    uint32_t count;               // vertices (no indices) or indices to draw
    uint32_t vertexCount;
    uint32_t transient;           // a SinkTransient's token (kSinkNone: a buffer)
    uint32_t vertexBuffer, indexBuffer;   // sink buffer ids (indexBuffer kSinkNone: not indexed)
    uint32_t query;               // the occlusion query the draw counts for (kSinkNone: none)
    uint16_t pass;                // SinkPass id
    uint16_t pad2;
    // the scene as the front end knows it (row-vector matrices, Direct3D conventions); for sinks that rebuild it
    const float* modelview;       // D3D WORLD (the camera folded in: D3D's VIEW is the identity here)
    const float* projection;
    const float* view;            // the camera's view matrix when known (0 until R1 finds it; remaster.md 8)
    const SinkLight* lights;      // 8, camera space
    uint32_t material[4];         // the D3D material: diffuse, specular, ambient, emissive (D3DCOLOR)
    float power;
    uint32_t ambient;             // the ambient light (D3DCOLOR)
    uint32_t lighting;            // D3D LIGHTING
    uint32_t fog;                 // fog on (colour, start, end are in frag[1..2])
};

// A full-screen pass quad (the framebuffer effects, bgfx_effects.cpp)
enum SinkFxProgram : uint32_t { kFxFilter, kFxBlur };
enum : uint32_t { kFxWriteRgb = 1, kFxWriteAlpha = 2, kFxBlendAdd = 4 };   // FxPacket::state
struct FxPacket {
    uint16_t pass;
    uint16_t pad;
    uint32_t program;             // SinkFxProgram
    float x0, y0, x1, y1;         // the quad in target pixels
    float uv[4][4];               // per texture coordinate set: u0, v0, u1, v1 (normalised, top-left origin)
    uint32_t texture[4];          // sink texture ids
    uint32_t textures;
    uint32_t state;               // kFx*
    float consts[8][4];           // c0..c7 as the combiners get them
    float prog[8];                // u_fxProg, then u_fxK (the filter program)
    uint32_t targetWidth, targetHeight;
};

// The present (display slot 14): the frame into the window
struct SinkPresent {
    int32_t x, y, w, h;           // where the frame lands in the window (black bars around it)
    uint32_t windowWidth, windowHeight;
    uint32_t frameWidth, frameHeight;
    uint8_t point;                // point sampled (1:1, or HULK_GFX_SCALE nearest/integer)
    uint8_t bars;                 // the frame does not cover the window: clear it black
    uint8_t keepFrontBuffer;      // the framebuffer effects' overlay reads the frame as presented next frame
    uint8_t pad;
};

enum SinkQueryResult : uint32_t { kQueryPending, kQueryVisible, kQueryInvisible };

struct SinkInit {
    void* nativeWindow;
    void* nativeDisplay;
    uint32_t width, height;
    int32_t renderer;             // the sink's own renderer choice (bgfx: bgfx::RendererType; Count = default)
    int32_t nativeType;           // 1: the handles are a Wayland display/surface
    void* callback;               // the sink's own callback object (bgfx: bgfx::CallbackI*) or 0
};

class DrawSink {
  public:
    virtual ~DrawSink() {}
    // ---- life
    virtual bool init(const SinkInit& init) = 0;
    virtual void shutdown() = 0;
    virtual bool up() const = 0;                          // initialised (resources can be made)
    virtual const char* name() const = 0;
    virtual SinkCaps caps() const = 0;
    virtual void resizeBackBuffer(uint32_t width, uint32_t height) = 0;   // the window (swap chain) size
    // the game's render target at the frame's size (the scene target, its copy texture); false: the frame is drawn
    // straight into the back buffer (no copies, no effects)
    virtual bool frameTargets(uint32_t width, uint32_t height) = 0;
    virtual bool offscreen() const = 0;
    virtual bool sceneTarget() const = 0;                 // offscreen with the scene target made
    virtual uint32_t targetWidth() const = 0;
    virtual uint32_t targetHeight() const = 0;
    virtual void destroyFrameTargets() = 0;
    // ---- textures
    virtual uint32_t createTexture(const SinkTextureDesc& desc) = 0;          // kSinkNone: refused
    virtual bool updateTexture(uint32_t texture, uint32_t level, uint32_t width, uint32_t height, const void* data,
                               uint32_t pitch, uint32_t size) = 0;            // false: no memory now (retry later)
    virtual void destroyTexture(uint32_t texture) = 0;
    // ---- prim buffers: a new or rewritten copy; returns the (possibly new) buffer id
    virtual uint32_t updateVertexBuffer(uint32_t buffer, const SinkVertexData& data) = 0;
    virtual uint32_t updateIndexBuffer(uint32_t buffer, const uint16_t* indices, uint32_t count, uint32_t owner) = 0;
    virtual void destroyBuffers(uint32_t vertexBuffer, uint32_t indexBuffer) = 0;
    // transient vertices for one draw (prim streams); 0 when there is no room (the draw is dropped)
    virtual SinkVertex* allocTransient(uint32_t count, uint32_t* token) = 0;
    // ---- render targets of the front end (the effects' targets, the copies)
    virtual SinkTarget createCopyTarget(uint32_t width, uint32_t height) = 0;   // a copy destination of the frame
    virtual SinkTarget createRenderTarget(uint32_t width, uint32_t height) = 0; // drawn into, sampled (clamped)
    virtual void destroyCopyTarget(SinkTarget* t) = 0;
    virtual void destroyRenderTarget(SinkTarget* t) = 0;
    virtual SinkTarget frameCopy() = 0;                   // the display's frame-buffer copy (refraction)
    virtual uint32_t frontBuffer() = 0;                   // the previous frame as presented (made on first use)
    // ---- passes and copies
    virtual void setPass(const SinkPass& pass) = 0;
    virtual void copyFrame(uint16_t pass, SinkTarget dst) = 0;   // the frame so far into dst (at the pass's start)
    // ---- draws
    virtual bool drawResources() = 0;                     // the draw path's own resources made (false: no draws)
    virtual bool hasVertexProgram(uint32_t vertexProgram) = 0;
    virtual bool preparePipeline(DrawPacket& p) = 0;      // picks p.pipeline / p.generic; false: not drawable
    virtual void submitDraw(const DrawPacket& p) = 0;
    virtual void combinerStats(int* generated, int* generic, int* draws) = 0;
    // ---- full-screen passes
    virtual bool fxResources() = 0;                       // false: no fx programs (the passes are skipped)
    virtual void fxDraw(const FxPacket& p) = 0;
    // ---- queries
    virtual uint32_t createQuery() = 0;                   // kSinkNone: no queries
    virtual uint32_t queryResult(uint32_t query, int32_t* pixels) = 0;   // SinkQueryResult
    // ---- frame
    virtual void present(const SinkPresent& p) = 0;
    virtual void frame() = 0;
    virtual void requestScreenshot(const char* path) = 0;
    virtual void contextDestroyed() = 0;                  // the context's draw and fx resources
};

// The build's sink (HULK_REMASTER: remasterSink(), the remaster's capture sink; else the bgfx sink)
DrawSink* drawSink();
#if HULK_PDDI_SINK_BGFX
DrawSink* bgfxSink();
#endif
#if HULK_REMASTER
DrawSink* remasterSink();            // src/platform/sdl/remaster/capture/ (not built yet: the link says so)
#endif

// Tag points (docs/remaster.md 2.6): the phase and drawable of the draws that follow, until the next tag
void sinkTag(uint32_t phase, uint64_t instance);

} // namespace pddi
} // namespace hulk
