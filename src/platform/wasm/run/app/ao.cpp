// Ambient occlusion (wr3a, docs/hdr-shadows.md; Video Options > Ambient Occlusion). Screen-space obscurance from the
// scene's depth (sampled: the sink keeps it readable while this is on) and the world pass's projection, applied to the
// world and the objects only: in the world's pass, once its opaque draws are done and before its first blended,
// stencil-shadow or 2D draw (the game draws translucent effects, particles and its shadow quad after the opaque
// traversal), the runner computes the visibility at half size, blurs it with depth weights and multiplies it into the
// scene, in views of its own between the game's draws (rm::viewsHere). Sky, particles, glows and the HUD are untouched.
// Output only: nothing here reads or writes the module's memory.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);

namespace {

class AoPass final : public rm::Pass {
  public:
    const char* name() const override { return "ao"; }
    int order() const override { return 25; }             // (before HDR: the occlusion is in the scene's light)
    void settingsChanged(const rm::Settings& s) override
    {
        int on = s[rm::kAo] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: ambient occlusion %s\n", on ? "on" : "off");
        m_on = on;
        if (const char* e = getenv("HULK_AO"))           // (tuning: radius, strength, fade start, fade end)
            sscanf(e, "%f,%f,%f,%f", &m_radius, &m_strength, &m_fade0, &m_fade1);
    }
    bool midFrame() const override { return m_on && !m_abOff; }
    void draw(const DrawPacket& p) override
    {
        if (!m_on || m_abOff || m_done)
            return;
        bool scene = p.viewMode == 0 && rm::passIsScene(p.pass);
        if (!m_haveProj) {
            // the world's projection: a fixed-function buffer draw's c4..c7 (vs_vp_ff.sc), perspective
            // (a room's: the sky is drawn first, with its own near and far)
            if (scene && p.vertexProgram == 0 && p.vertexConstants && p.vertexConstantCount >= 8 &&
                p.transient == kSinkNone && !p.state.blend && p.state.depthWrite &&
                (p.shaderKind == 1 || p.shaderKind == 2)) {
                const float* c = p.vertexConstants + 16;
                static int logged;
                if (getenv("HULK_AO_LOG") && logged < 3 && p.frame % 500 == 0)
                    logged++, fprintf(stderr, "hulk-app: ao: f%u proj c4 %g %g %g %g c5 %g %g %g %g c6 %g %g %g %g "
                                      "c7 %g %g %g %g\n", p.frame, c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7],
                                      c[8], c[9], c[10], c[11], c[12], c[13], c[14], c[15]);
                if (fabsf(c[14]) > 0.5f && fabsf(c[15]) < 1e-3f && fabsf(c[12]) < 1e-6f && fabsf(c[13]) < 1e-6f) {
                    memcpy(m_proj, c, sizeof m_proj);
                    m_haveProj = true;
                    m_worldView = p.pass;
                }
            }
            return;
        }
        if (p.pass != m_worldView)
            return;
        if (!p.state.blend && p.state.depthWrite && p.viewMode == 0 && !p.state.stencil) {
            m_opaque = true;
            return;
        }
        if (m_opaque && (p.viewMode != 0 || p.state.stencil || (p.state.blend && !p.state.depthWrite)))
            run(-1, &p);
    }
    void copy(uint16_t pass, const SinkTarget&) override
    {
        if (m_on && !m_abOff && !m_done && m_opaque)
            run(pass, nullptr);
    }
    void fx(const FxPacket& p) override
    {
        if (m_on && !m_abOff && !m_done && m_opaque)
            run(p.pass, nullptr);
    }
    void frame() override
    {
        abCost();
        if (getenv("HULK_AO_LOG") && ++m_frames % 300 == 0)
            fprintf(stderr, "hulk-app: ao: %u runs in 300 frames\n", m_runs - m_runs0), m_runs0 = m_runs;
        m_done = m_haveProj = m_opaque = false;
    }

    // wlook3: the occlusion is still to come in this frame (the grass blades wait for it)
    bool pending() const { return m_on && !m_abOff && !m_done; }

  private:
    // the occlusion, then the grass blades' view (wlook3): when it ran before the rest of the current pass, an empty
    // view of that pass after the apply, split off ahead of the draw being handed over (else the blades go into their
    // ground draws' views); `p` the game draw the hooks are handing over: the lighting pass's samplers bound again for
    // it, as our submits took them (wlinux2, lightingRebind)
    void run(int gamePass, const DrawPacket* p)
    {
        bool here = runAo(gamePass) && gamePass < 0;
        uint16_t gv = rm::kNoView;
        if (here && rm::grassWaiting()) {
            gv = rm::sinkView(rm::currentGamePass());
            rm::splitPass();
        }
        rm::grassAfterAo(gv);
        if (p)
            rm::lightingRebind(*p);
    }
    // the occlusion in views before the rest of the current pass (gamePass < 0) or the game pass `gamePass`
    bool runAo(int gamePass)
    {
        m_done = true;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || depth == kSinkNone || !w || !h)
            return false;
        uint16_t ao = rm::program("vs_rm_quad", "fs_rm_ao"), apply = rm::program("vs_rm_quad", "fs_rm_aoapply");
        if (ao == rm::kNoHandle || apply == rm::kNoHandle)
            return false;
        if (!m_ao.ensure((w + 1) / 2, (h + 1) / 2, bgfx::TextureFormat::RGBA16F, false, true))
            return false;
        // a frame buffer of the scene's colour alone (the depth is read while the occlusion is applied)
        if (m_colourOf != colour || m_fb == rm::kNoHandle) {
            if (m_fb != rm::kNoHandle)
                bgfx::destroy(bgfx::FrameBufferHandle{m_fb});
            bgfx::TextureHandle t{(uint16_t)colour};
            bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(1, &t, false);
            m_fb = bgfx::isValid(f) ? f.idx : rm::kNoHandle;
            m_colourOf = colour;
            if (m_fb == rm::kNoHandle)
                return false;
        }
        uint16_t v[2];
        if (!(gamePass < 0 ? rm::viewsHere(2, v) : rm::viewsBefore((uint16_t)gamePass, 2, v)))
            return false;
        if (getenv("HULK_AO_LOG") && m_runs % 500 == 0)
            fprintf(stderr, "hulk-app: ao: views %u %u (game pass %d, world view %u) fb %u colour %u depth %u %ux%u\n",
                    v[0], v[1], gamePass, m_worldView, m_fb, colour, depth, w, h);
        const float* c = m_proj;          // rows c4, c5, c6, c7
        float a0[4] = {c[0], c[5], c[2], c[6]};
        float a1[4] = {c[10], c[11], c[14], c[15]};
        float a2[4] = {c[3], c[7], m_radius, 1.0f / w};
        float a3[4] = {m_strength, m_fade0, m_fade1, 1.0f / h};
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        rm::viewInto(v[0], m_ao.fb, m_ao.w, m_ao.h);
        rm::texture(0, (uint16_t)depth, point);
        rm::uniform("u_rmAo0", a0);
        rm::uniform("u_rmAo1", a1);
        rm::uniform("u_rmAo2", a2);
        rm::uniform("u_rmAo3", a3);
        rm::quad(v[0], ao, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        static const int showMode = getenv("HULK_AO_SHOW") ? atoi(getenv("HULK_AO_SHOW")) : 0;
        float t[4] = {1.0f / m_ao.w, 1.0f / m_ao.h, (float)showMode, 0};
        rm::viewInto(v[1], m_fb, w, h);
        rm::texture(0, (uint16_t)depth, point);
        rm::texture(1, m_ao.tex, BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT);
        rm::uniform("u_rmAo1", a1);
        rm::uniform("u_rmPost0", t);
        const bool show = showMode != 0;                 // (development: the occlusion alone, 2 the depth)
        rm::quad(v[1], apply, BGFX_STATE_WRITE_RGB |
                                  (show ? 0 : BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_ZERO, BGFX_STATE_BLEND_SRC_COLOR)));
        m_runs++;
        return true;
    }
    // HULK_AO_AB=N: the occlusion off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_AO_AB") ? atoi(getenv("HULK_AO_AB")) : 0;
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
                fprintf(stderr, "hulk-app: ao cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u; applied %u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0, m_runs);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_on = 0;
    bool m_done = false, m_haveProj = false, m_opaque = false;
    uint16_t m_worldView = 0;
    float m_proj[16];
    float m_radius = 3.0f, m_strength = 1.5f, m_fade0 = 150.0f, m_fade1 = 300.0f;
    rm::Target m_ao;
    uint16_t m_fb = rm::kNoHandle;
    uint32_t m_colourOf = kSinkNone;
    unsigned m_runs = 0, m_runs0 = 0, m_frames = 0;
};
HULK_RM_REGISTER_PASS(AoPass);

} // namespace

bool rm::aoPending() { return s_rmPass_AoPass.pending(); }
