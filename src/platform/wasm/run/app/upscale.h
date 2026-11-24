// Temporal upscaling (wperf2, docs/performance.md 4.2): what TAA (taa.cpp) hands the upscaler (upscale.cpp) when the
// Upscaler row is a temporal one (rm::upscalerTemporal) and the present is larger than the scene. TAA then jitters the
// scene as always but does not resolve it: at the frame's first effect (where its resolve would run) it writes the
// motion of every pixel and a copy of the depth, and from there on draws the HUD's coverage into a mask; the upscaler
// reconstructs the finished frame (the game's effects and HUD drawn at the render size, as with FSR 1) at the present
// size from it and its history: Temporal (ours, fs_rm_tupscale.sc) or MetalFX (mfx.cpp, macOS).
#pragma once
#include <stdint.h>

namespace rm {

struct TemporalFrame {
    uint32_t w, h;                // the scene's size (pixels)
    uint16_t motion;              // RG16F: each pixel's screen motion to the last presented frame (uv, top-left
                                  // origin: last - current), the objects' own where they are drawn, else the camera's
    uint16_t depth;               // D32F: the scene's depth at the first effect (the HUD and effects come after)
    uint16_t mask;                // R8: the HUD's coverage (drawn after the first effect, not jittered): 1 = take the
                                  // frame as it is, no history
    float jitter[2];              // this frame's sample offset in pixels (x right, y down; FSR 2's convention: the
                                  // projection moved by 2 jx / w, -2 jy / h in clip space)
    bool reset;                   // no usable history (a cut, the first frame, a size change)
};

// taa.cpp: this frame's inputs when it prepared them (valid in postScene of passes after TAA's, 20); else null
const TemporalFrame* temporalFrame();
// taa.cpp: the upscaler wants temporal inputs next frame (upscale.cpp sets it each presented frame), and the jitter
// phase count it wants (8 at 1:1 up to 32: FSR 2's 8 x the scale squared)
void temporalWanted(bool on, uint32_t phases);
// upscale.cpp: the upscaler of the last presented frame, for the performance overlay
const char* upscalerName();

} // namespace rm
