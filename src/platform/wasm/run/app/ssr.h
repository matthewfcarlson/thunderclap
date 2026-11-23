// Screen-space reflections (wssr1, docs/reflections.md "SSR interface"): what another runner pass reads of the
// reflection pass's result (e.g. the interior-mapped windows blending a reflection over their interiors by Fresnel).
#pragma once
#include <stdint.h>

namespace rm {

struct SsrResult {
    // bgfx texture handles (rm_post.h kNoHandle: none)
    uint16_t reflection;      // RGBA16F, width x height (half the scene's size at Low, the scene's at High): rgb the
                              // reflected colour x confidence (premultiplied), a the confidence (0: no ray hit)
    uint16_t gbuffer;         // RGBA16F, gwidth x gheight (the scene's size): xy the camera-space normal (octahedral,
                              // fs_rm_ssr.sc octDecode), z the strength (0: not reflective), w the Fresnel class
                              // (floor: 0 glass/stone, 1 wet ground, 2 metal-like) + roughness / 2
    uint16_t depth;           // the G-buffer's depth (D32F, else D24; D3D depth of the world's projection)
    uint32_t width, height, gwidth, gheight;
    float proj[16];           // the world's projection c4..c7 (rows, vs_vp_ff.sc's layout): viewZ / viewPos as fs_rm_ssr.sc
};
// the reflection traced this frame (true from the composite, at the frame's first effect, to the end of the frame):
// sample it in views that run after it, i.e. views taken after the composite (rm::viewsBefore / newView later in the
// frame, or postScene)
bool ssrResult(SsrResult* out);

} // namespace rm
