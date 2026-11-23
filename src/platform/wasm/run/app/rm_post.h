// Helpers of the runner's full-screen passes (wr3a, docs/hdr-shadows.md): programs from the runner's shaders, the
// passes' own targets, views set up for a draw into a target and a full-screen quad. bgfx today; the RHI's later.
#pragma once
#include <stdint.h>

namespace rm {

enum : uint16_t { kNoHandle = 0xffff };

// a program of two runner shaders (run/app/shaders), made once; kNoHandle: not in this build / renderer
uint16_t program(const char* vs, const char* fs);

// a target the pass draws into and samples: texture + frame buffer (bgfx handles), remade when the size or format
// changes. format: bgfx::TextureFormat; blitDst: also a blit destination (no frame buffer)
struct Target {
    uint16_t tex = kNoHandle, fb = kNoHandle;
    uint32_t w = 0, h = 0, format = 0;
    bool blit = false;
    bool ensure(uint32_t w, uint32_t h, uint32_t format, bool blitDst = false, bool linear = true);
    void drop();
};

// a view drawing into frame buffer `fb` (kNoHandle: the back buffer) over w x h, no clear, in submission order
void viewInto(uint16_t view, uint16_t fb, uint32_t w, uint32_t h, uint16_t clearFlags = 0, uint32_t rgba = 0,
              float depth = 1.0f);
// the textures of the next draw: s_rmTex<stage> (sampler flags: bgfx BGFX_SAMPLER_*)
void texture(int stage, uint16_t tex, uint32_t flags);
// a vec4 uniform array by name (u_rmPost0, ...), made once
void uniform(const char* name, const float* v, uint16_t n = 1);
// a full-screen quad (uv 0..1 top-left origin on every renderer) with the program and state (BGFX_STATE_*)
void quad(uint16_t view, uint16_t program, uint64_t state);

// the half-float format the HDR scene uses, or 0 when this renderer can't render to it and blit it
bool hdrSupported();

} // namespace rm
