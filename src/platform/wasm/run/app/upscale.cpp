// Upscaling (wperf1, docs/performance.md; Video Options > Upscaler, Render Scale). The Render Scale row draws the
// scene target at a share of the render resolution (app.cpp rrSize: 100% .. 50%); the Upscaler row decides how the
// frame reaches the present size: Off, the sink's bilinear stretch as before; FSR 1, AMD's EASU (edge-adaptive
// upsampling) into a target of the present size and RCAS (sharpening) after it (run/app/shaders/fs_rm_easu.sc,
// fs_rm_rcas.sc: ports of ffx_fsr1.h, MIT), presented 1:1 (hulk_gfx_sink_present_source); Auto picks per platform
// (FSR 1 everywhere today; MetalFX on macOS when it lands). Spatial only so far: the whole frame (the HUD too) is
// upscaled after the game's effects, at the present.
// Output only: nothing here reads or writes the module's memory; the game sees 640x480 at every scale.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_present_source(uint32_t texture);

namespace {

class UpscalePass final : public rm::Pass {
  public:
    const char* name() const override { return "upscale"; }
    int order() const override { return 1000; }      // (the last postScene: everything else is in the frame)
    void settingsChanged(const rm::Settings& s) override
    {
        int mode = s[rm::kUpscaler], scale = s[rm::kRenderScale];
        if (scale < 0 || scale > 100)
            scale = 100;
        if (mode != m_mode || scale != m_scale)
            fprintf(stderr, "hulk-app: upscaler %s, render scale %d%%%s\n", mode == 0 ? "off" : mode == 1 ? "auto" : "FSR 1",
                    scale, scale ? "" : " (auto: 1280x960 pixels at most)");
        m_mode = mode;
        if (scale != m_scale)
            rm::setRenderScale(scale);
        m_scale = scale;
        if (const char* e = getenv("HULK_FSR"))          // (tuning: RCAS sharpness in stops, 0 = sharpest)
            sscanf(e, "%f", &m_stops);
    }
    void postScene(const rm::Scene& s, uint16_t& view) override
    {
        const SinkPresent* p = rm::currentPresent();
        if (!m_mode || !p || !s.width || !s.height || view + 2 > rm::kFirstView + rm::kViewCount)
            return;
        uint32_t ow = (uint32_t)p->w, oh = (uint32_t)p->h;
        // only upward (a render size at or above the present's is the sink's own stretch)
        if (ow * 100 <= s.width * 101 && oh * 100 <= s.height * 101)
            return;
        uint16_t easu = rm::program("vs_rm_quad", "fs_rm_easu"), rcas = rm::program("vs_rm_quad", "fs_rm_rcas");
        if (easu == rm::kNoHandle || rcas == rm::kNoHandle)
            return;
        if (!m_up.ensure(ow, oh, bgfx::TextureFormat::RGBA8, false, false) ||
            !m_out.ensure(ow, oh, bgfx::TextureFormat::RGBA8, false, false))
            return;
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        uint16_t v0 = view++, v1 = view++;
        float c0[4] = {(float)s.width, (float)s.height, 1.0f / s.width, 1.0f / s.height};
        rm::viewInto(v0, m_up.fb, ow, oh);
        rm::texture(0, (uint16_t)s.colour, point);
        rm::uniform("u_rmFsr0", c0);
        rm::quad(v0, easu, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        float c1[4] = {(float)ow, (float)oh, 1.0f / ow, 1.0f / oh, };
        c1[3] = exp2f(-m_stops);
        rm::viewInto(v1, m_out.fb, ow, oh);
        rm::texture(0, m_up.tex, point);
        rm::uniform("u_rmFsr0", c1);
        rm::quad(v1, rcas, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        hulk_gfx_sink_present_source(m_out.tex);
    }

  private:
    int m_mode = 0, m_scale = 100;
    float m_stops = 0.25f;
    rm::Target m_up, m_out;
};
HULK_RM_REGISTER_PASS(UpscalePass);

} // namespace
