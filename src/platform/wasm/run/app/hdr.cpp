// HDR and tone mapping (wr3a, docs/hdr-shadows.md; Video Options > HDR). The scene target is half float (the sink,
// HULK_SINK_OVERLAY), so additive light (glows, sparks, orbs, the per-pixel lights) sums past 1 instead of clipping.
// Before the game's own framebuffer effects (its colour pass and bloom: the frame's first effect copy or quad) the
// runner tone maps the scene back into the displayable range, in views of its own between the game's (rm::viewsBefore):
// the light above 1 is blurred into a glow at a quarter size, then the scene plus the glow is rolled off above a knee
// (run/app/shaders/fs_rm_tonemap.sc). The game's bloom, colour pass, overlay (motion trail), fader and HUD then draw
// as they always do, on top. Output only: nothing here reads or writes the module's memory.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);
extern "C" uint32_t hulk_gfx_sink_scene_hdr();

namespace {

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_HDR_LOG") && atoi(getenv("HULK_HDR_LOG")) > 0;
    return on;
}

class HdrPass final : public rm::Pass {
  public:
    const char* name() const override { return "hdr"; }
    int order() const override { return 30; }
    void settingsChanged(const rm::Settings& s) override
    {
        int on = s[rm::kHdr] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: HDR %s\n", on ? "on" : "off");
        m_on = on;
        if (const char* e = getenv("HULK_HDR"))          // (tuning: knee, glow strength, glow threshold)
            sscanf(e, "%f,%f,%f", &m_knee, &m_glow, &m_threshold);
    }
    bool midFrame() const override { return m_on && hulk_gfx_sink_scene_hdr() && !m_abOff; }
    void draw(const DrawPacket& p) override
    {
        if (p.viewMode == 0 && rm::passIsScene(p.pass) && !p.state.blend && p.state.depthWrite)
            m_scene = true;
    }
    void copy(uint16_t pass, const SinkTarget& dst) override
    {
        if (!active())
            return;
        SinkTarget refr = {kSinkNone, kSinkNone};
        hulk_gfx_sink_frame_copy(&refr);               // (the refraction copy of the frame: mid-scene, not the effects)
        if (dst.texture != refr.texture)
            run(pass);
    }
    void fx(const FxPacket& p) override
    {
        if (active())
            run(p.pass);
    }
    void postScene(const rm::Scene&, uint16_t&) override
    {
        if (logOn() && ++m_frames % 300 == 0)
            fprintf(stderr, "hulk-app: hdr: %u of 300 frames tone mapped before the effects\n", m_mapped), m_mapped = 0;
    }
    void frame() override
    {
        abCost();
        m_done = false;
        m_scene = false;
    }

  private:
    bool active() const { return midFrame() && !m_done && m_scene; }
    // the tone map in views before the game pass `pass` goes on
    void run(uint16_t pass)
    {
        m_done = true;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || !w || !h)
            return;
        uint16_t tone = rm::program("vs_rm_quad", "fs_rm_tonemap");
        uint16_t bright = rm::program("vs_rm_quad", "fs_rm_bright");
        uint16_t blur = rm::program("vs_rm_quad", "fs_rm_blur");
        if (tone == rm::kNoHandle)
            return;
        if (!m_copy.ensure(w, h, bgfx::TextureFormat::RGBA16F, true))
            return;
        bool glow = m_glow > 0.0f && bright != rm::kNoHandle && blur != rm::kNoHandle &&
                    m_a.ensure(w / 4, h / 4, bgfx::TextureFormat::RGBA16F) &&
                    m_b.ensure(w / 4, h / 4, bgfx::TextureFormat::RGBA16F);
        uint16_t v[4];
        if (!rm::viewsBefore(pass, glow ? 4 : 1, v))
            return;
        const uint64_t write = BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A;
        const uint32_t lin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        // the scene as it is now (a view's blits run before its draws)
        bgfx::TextureRegion dst, src;
        dst.init(bgfx::TextureHandle{m_copy.tex});
        src.init(bgfx::TextureHandle{(uint16_t)colour});
        bgfx::blit(v[0], dst, src);
        int k = 0;
        if (glow) {
            float p0[4] = {1.0f / w, 1.0f / h, m_threshold, 0};
            rm::viewInto(v[0], m_a.fb, m_a.w, m_a.h);
            rm::texture(0, m_copy.tex, lin);
            rm::uniform("u_rmPost0", p0);
            rm::quad(v[0], bright, write);
            float px[4] = {1.0f / m_a.w, 0, 0, 0}, py[4] = {0, 1.0f / m_a.h, 0, 0};
            rm::viewInto(v[1], m_b.fb, m_b.w, m_b.h);
            rm::texture(0, m_a.tex, lin);
            rm::uniform("u_rmPost0", px);
            rm::quad(v[1], blur, write);
            rm::viewInto(v[2], m_a.fb, m_a.w, m_a.h);
            rm::texture(0, m_b.tex, lin);
            rm::uniform("u_rmPost0", py);
            rm::quad(v[2], blur, write);
            k = 3;
        }
        float t[4] = {m_knee, m_glow, glow ? 1.0f : 0.0f, 0};
        rm::viewInto(v[k], (uint16_t)fb, w, h);
        rm::texture(0, m_copy.tex, lin | BGFX_SAMPLER_POINT);
        if (glow)
            rm::texture(1, m_a.tex, lin);
        rm::uniform("u_rmPost0", t);
        rm::quad(v[k], tone, write);
        m_mapped++;
    }
    // HULK_HDR_AB=N: HDR's views off and on in turns of N presented frames (the scene stays half float), bgfx's GPU
    // and render thread time a frame for each
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_HDR_AB") ? atoi(getenv("HULK_HDR_AB")) : 0;
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
                fprintf(stderr, "hulk-app: hdr cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_on = 0;
    bool m_done = false, m_scene = false;
    float m_knee = 0.8f, m_glow = 0.35f, m_threshold = 1.0f;
    rm::Target m_copy, m_a, m_b;
    unsigned m_frames = 0, m_mapped = 0;
};
HULK_RM_REGISTER_PASS(HdrPass);

} // namespace
