// MetalFX temporal upscaling (wperf2, mfx.cpp; docs/performance.md 4.2): macOS only (elsewhere unavailable).
#pragma once
#include <stdint.h>

namespace rm {

struct MfxInputs {
    uint16_t colour, depth, motion, mask;   // bgfx texture handles (render size; depth D32F, motion RG16F, mask R8)
    float jitter[2];                        // pixels (upscale.h TemporalFrame::jitter)
    float mvScale[2];                       // the motion texture's values to pixels
    bool reset;
};

// MetalFX's temporal scaler runs on this Mac (bgfx is up on Metal and MTLFXTemporalScaler supports the device)
bool mfxAvailable();
// the scaler for these sizes (made again when they change); its output texture (RGBA16F, present size), or 0xffff
uint16_t mfxPrepare(uint32_t inW, uint32_t inH, uint32_t outW, uint32_t outH, bool hdrColour);
// encode the scaler when bgfx reaches `view` (touched here; the next view may read the output)
void mfxSchedule(uint16_t view, const MfxInputs& in);
// encodes done / failed since the last call
void mfxStats(uint32_t* encoded, uint32_t* failed);

} // namespace rm
