// HUD Resolution (whud1, D249; docs/performance.md 4.3; Video Options > HUD Resolution): the HUD, menus and subtitles
// at the present size instead of the scene's. When the frame is upscaled (Render Scale below the window, or a render
// resolution below it) the game's HUD used to be drawn into the scene target at the render size and stretched with the
// world. This pass asks rm to keep the frame's tail (rm_pass.h Pass::holdTail: the scene draws after the game's last
// effect, which in play are the HUD's pass and in the front end and pause menu the menus), so the upscaler reads the
// scene without it; then, after the upscaler (order 1010), it draws the tail again into a target of the present size
// over the upscaled frame (rm::drawTail: the game's passes with their viewports scaled; the game's 2D projections are
// in clip space and need nothing else) and presents that target. rm draws the tail into the scene target too, after
// these views, so the scene (the front buffer the game's motion-trail overlay reads next frame) ends as the game drew
// it. Without an upscaler (Upscaler Off) the frame under the HUD is the bilinear stretch the present would make
// (fs_rm_copy.sc). At the render size nothing changes. The game still sees 640x480. Output only: nothing here reads or
// writes the module's memory.
#include <stdio.h>
#include <stdlib.h>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"
#include "upscale.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_present_source(uint32_t texture);

namespace {

class HudPass final : public rm::Pass {
  public:
    const char* name() const override { return "hud"; }
    int order() const override { return 1010; }      // (after the upscaler's postScene, 1000)
    void settingsChanged(const rm::Settings& s) override
    {
        bool on = s[rm::kHudRes] != 0;
        if (const char* e = getenv("HULK_HUD_RES"))      // (development: 0 off, 1 on, 2 also at the render size)
            on = atoi(e) != 0, m_force = atoi(e) == 2;
        if (on != m_on)
            fprintf(stderr, "hulk-app: HUD resolution %s\n", on ? "the present's" : "the render size's");
        m_on = on;
    }
    // (the tail is kept only when the last frame was drawn below its present size: the decision is the frame's first)
    bool holdTail() const override { return m_on && (m_up || m_force) && !m_abOff; }
    bool midFrame() const override { return holdTail(); }
    void postScene(const rm::Scene& s, uint16_t& view) override
    {
        const SinkPresent* p = rm::currentPresent();
        if (!p || p->w <= 0 || p->h <= 0 || !s.width || !s.height)
            return;
        uint32_t ow = (uint32_t)p->w, oh = (uint32_t)p->h;
        bool up = ow * 100 > s.width * 101 || oh * 100 > s.height * 101;
        m_up = up;
        if (!rm::holdingDraws())
            return;                                     // (no tail this frame, or not kept: drawn as always)
        if (!up && !m_force)
            return;                                     // (rm draws the tail into the scene: as the game drew it)
        if (!ensure(ow, oh) || view + 2 > rm::kFirstView + rm::kViewCount) {
            hulk_gfx_sink_present_source(0xffff);       // (the scene, with its tail, stretched by the present)
            return;
        }
        // the frame under the HUD: the upscaler's output, else the scene stretched as the present would
        uint16_t vb = view++;
        bgfx::setViewFrameBuffer(vb, bgfx::FrameBufferHandle{m_fb});
        bgfx::setViewMode(vb, bgfx::ViewMode::Sequential);
        bgfx::setViewRect(vb, 0, 0, (uint16_t)ow, (uint16_t)oh);
        bgfx::setViewClear(vb, BGFX_CLEAR_DEPTH | BGFX_CLEAR_STENCIL, 0, 1.0f, 0);
        bgfx::setViewTransform(vb, nullptr, nullptr);
        bgfx::touch(vb);
        uint16_t src = rm::upscaledFrame();
        uint16_t copy = rm::program("vs_rm_quad", "fs_rm_copy");
        if (src != rm::kNoHandle) {
            bgfx::TextureRegion dst, from;                // (a view's blits run before its clear and draws)
            dst.init(bgfx::TextureHandle{m_colour});
            from.init(bgfx::TextureHandle{src});
            bgfx::blit(vb, dst, from);
        } else if (copy != rm::kNoHandle) {
            rm::texture(0, (uint16_t)s.colour, BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
            rm::quad(vb, copy, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        } else {
            hulk_gfx_sink_present_source(0xffff);
            return;
        }
        rm::drawTail(view, m_fb, ow, oh, (float)ow / (float)s.width, (float)oh / (float)s.height);
        hulk_gfx_sink_present_source(m_colour);
        m_frames++;
    }
    void frame() override
    {
        abCost();
        static int log = -1;
        if (log < 0)
            log = getenv("HULK_HUD_LOG") && atoi(getenv("HULK_HUD_LOG")) > 0;
        if (log && ++m_logN % 300 == 0)
            fprintf(stderr, "hulk-app: hud: %u of 300 frames with the HUD at the present size (%ux%u)\n", m_frames,
                    m_w, m_h), m_frames = 0;
    }

  private:
    // the present-size target: colour (RGBA8, a blit destination) and depth-stencil
    bool ensure(uint32_t w, uint32_t h)
    {
        if (m_fb != rm::kNoHandle && m_w == w && m_h == h)
            return true;
        if (m_fb != rm::kNoHandle)
            bgfx::destroy(bgfx::FrameBufferHandle{m_fb});           // (destroys its textures)
        m_fb = m_colour = rm::kNoHandle;
        const uint64_t clamp = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        bgfx::TextureHandle t[2] = {
            bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, bgfx::TextureFormat::RGBA8,
                                  BGFX_TEXTURE_RT | BGFX_TEXTURE_BLIT_DST | clamp),
            bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, bgfx::TextureFormat::D24S8,
                                  BGFX_TEXTURE_RT_WRITE_ONLY)};
        if (!bgfx::isValid(t[0]) || !bgfx::isValid(t[1])) {
            if (bgfx::isValid(t[0])) bgfx::destroy(t[0]);
            if (bgfx::isValid(t[1])) bgfx::destroy(t[1]);
            return false;
        }
        bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(2, t, true);
        if (!bgfx::isValid(f))
            return false;
        m_fb = f.idx, m_colour = t[0].idx, m_w = w, m_h = h;
        return true;
    }
    // HULK_HUD_AB=N: the HUD at the render size and at the present size in turns of N presented frames
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_HUD_AB") ? atoi(getenv("HULK_HUD_AB")) : 0;
        if (n <= 0)
            return;
        const bgfx::Stats* st = bgfx::getStats();
        if (st && m_abFrame > 2 && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin) {
            int i = m_abOff ? 0 : 1;
            m_abGpu[i] += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq;
            m_abCpu[i] += 1e3 * (double)(st->cpuTimeEnd - st->cpuTimeBegin) / (double)st->cpuTimerFreq;
            m_abN[i]++;
        }
        if (++m_abFrame >= (unsigned)n) {
            m_abFrame = 0;
            m_abOff = !m_abOff;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: hud cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    bool m_on = false, m_force = false, m_up = false;
    uint16_t m_fb = rm::kNoHandle, m_colour = rm::kNoHandle;
    uint32_t m_w = 0, m_h = 0, m_frames = 0, m_logN = 0;
};
HULK_RM_REGISTER_PASS(HudPass);

} // namespace
