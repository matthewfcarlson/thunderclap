// Soft particles (wfx1, D249, docs/particles.md; Video Options > Particles: Original / Soft).
//
// The game's smoke, dust, fire and explosion sprites are camera-facing quads it streams each frame (transient
// vertices already in camera space, fixed function, unlit, shader "simple", blended src-alpha / inv-src-alpha for smoke
// and dust, one / one for fire and flashes, depth tested without depth writes), drawn in the world's pass after its
// opaque traversal. Drawn flat, a sprite ends in a hard line where it cuts the ground or a wall. This pass gives those
// draws the runner's program vs_px_ff + fs_px_soft (the faithful generic combiner, fog and alpha test, shaders/
// fs_px_soft.sc), which fades a sprite's coverage where the scene behind it is near (a linear-depth copy of the scene
// taken at the frame's first such draw, before the rest of the world pass) and near the camera, and lights the smoke:
// a little darker in the sun's shadow (softly) (the shadow pass's atlas) and lit by the Night Lights' city lights as a volume. Additive
// sprites take no light (they are light) and, under HDR, a gain below 1 so a big flash no longer whites out the frame.
//
// Only draws whose first triangle faces the camera are taken (a billboard): a decal or a trail lying on a surface would
// fade into it, and keeps its faithful program. Output only: nothing here reads or writes the module's memory, and a
// draw the game counts pixels of (an occlusion query) is never changed.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bgfx/bgfx.h>

#include "nightlights.h"
#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"
#include "shadows.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);
extern "C" uint32_t hulk_gfx_sink_scene_hdr();

namespace {

class ParticlesPass final : public rm::Pass {
  public:
    const char* name() const override { return "particles"; }
    // (the draw hook binds the program's samplers after every pass that submits from the same draw's hooks: ambient
    // occlusion 25, the atmosphere 30)
    int order() const override { return 35; }
    void settingsChanged(const rm::Settings& s) override
    {
        int on = s[rm::kParticles] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: particles %s\n", on ? "soft" : "original");
        m_on = on;
        m_hdr = s[rm::kHdr] != 0;
        // HULK_SOFT=fade,nearStart,nearLength,cityLight,shadow,additiveHdrGain (development tuning)
        if (const char* e = getenv("HULK_SOFT"))
            sscanf(e, "%f,%f,%f,%f,%f,%f", &m_fade, &m_near0, &m_nearLen, &m_cityK, &m_shadowK, &m_addGain);
    }
    bool midFrame() const override { return m_on && !m_abOff; }
    void late(DrawPacket& p) override
    {
        if (!m_on || m_abOff)
            return;
        if (!m_worldKnown) {
            // the world's pass: the game pass of the frame's first room draw (shader kind 1/2, unlit, opaque)
            if (p.viewMode == 0 && p.vertexProgram == 0 && !p.state.blend && p.state.depthWrite && !p.lighting &&
                p.transient == kSinkNone && (p.shaderKind == 1 || p.shaderKind == 2)) {
                m_worldPass = rm::currentGamePass();
                m_worldKnown = true;
            }
            return;
        }
        if (!sprite(p))
            return;
        if (!m_copied && !copyDepth())
            return;
        if (m_depth.tex == rm::kNoHandle)
            return;
        uint16_t prog = rm::program("vs_px_ff", "fs_px_soft");
        if (prog == rm::kNoHandle)
            return;
        p.pipeline = prog;
        m_prog = prog;
        m_draws++;
    }
    void draw(const DrawPacket& p) override
    {
        if (!m_on || m_abOff || p.pipeline != m_prog || m_prog == rm::kNoHandle)
            return;
        bind(p);
    }
    void frame() override
    {
        abCost();
        if (getenv("HULK_SOFT_LOG") && ++m_frames % 300 == 0)
            fprintf(stderr, "hulk-app: particles: %.1f soft draws a frame, %u copies, %u not facing\n", m_draws / 300.0,
                    m_copies, m_notFacing), m_draws = 0, m_copies = 0, m_notFacing = 0;
        m_worldKnown = m_copied = false;
    }

    // wlinux2: a copy of one of our draws submitted again by another pass: the samplers bound again
    void rebind(const DrawPacket& q)
    {
        if (m_on && m_prog != rm::kNoHandle && q.pipeline == m_prog)
            bind(q);
    }

  private:
    // a particle sprite of the world's pass (see the header)
    bool sprite(const DrawPacket& p)
    {
        if (p.viewMode != 0 || p.query != kSinkNone || p.vertexProgram != 0 || p.lighting || p.shaderKind != 0 ||
            p.transient == kSinkNone || p.pipeline == kSinkNone || !p.state.blend || !p.state.depthTest ||
            p.state.depthWrite || p.state.stencil || p.state.blendOp != kBlendAdd || !p.vertexConstants ||
            p.vertexConstantCount < 8 || rm::currentGamePass() != m_worldPass)
            return false;
        bool alpha = p.state.srcBlend == kBlendSrcAlpha &&
                     (p.state.dstBlend == kBlendInvSrcAlpha || p.state.dstBlend == kBlendOne);
        bool one = p.state.srcBlend == kBlendOne && (p.state.dstBlend == kBlendOne || p.state.dstBlend == kBlendInvSrcAlpha);
        if (!alpha && !one)
            return false;
        uint32_t n = 0;
        const SinkVertex* v = rm::transientVertices(p, &n);
        if (!v || p.vertexCount < 3)
            return false;
        // the first triangle in camera space (the draw's modelview, c0..c2): its normal along the view ray to it
        const float* c = p.vertexConstants;
        float q[3][3];
        for (int k = 0; k < 3; k++)
            for (int i = 0; i < 3; i++)
                q[k][i] = c[4 * i] * v[k].pos[0] + c[4 * i + 1] * v[k].pos[1] + c[4 * i + 2] * v[k].pos[2] + c[4 * i + 3];
        float a[3] = {q[1][0] - q[0][0], q[1][1] - q[0][1], q[1][2] - q[0][2]};
        float b[3] = {q[2][0] - q[0][0], q[2][1] - q[0][1], q[2][2] - q[0][2]};
        float nrm[3] = {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
        float m[3] = {(q[0][0] + q[1][0] + q[2][0]) / 3, (q[0][1] + q[1][1] + q[2][1]) / 3,
                      (q[0][2] + q[1][2] + q[2][2]) / 3};
        float nl = sqrtf(nrm[0] * nrm[0] + nrm[1] * nrm[1] + nrm[2] * nrm[2]);
        float ml = sqrtf(m[0] * m[0] + m[1] * m[1] + m[2] * m[2]);
        if (nl < 1e-12f || ml < 1e-6f)
            return false;
        float facing = fabsf(nrm[0] * m[0] + nrm[1] * m[1] + nrm[2] * m[2]) / (nl * ml);
        float screen = fabsf(nrm[2]) / nl;              // (screen-aligned: the normal along the view axis)
        if (facing < 0.8f && screen < 0.8f) {
            m_notFacing++;
            return false;
        }
        return true;
    }

    // the scene's depth so far as linear camera depth (R32F, else R16F), in a view before the rest of the world pass
    bool copyDepth()
    {
        m_copied = true;                                // (one try a frame)
        float view[3][4], inv[3][3], P[16];
        if (!rm::frameCamera(view, inv, P))
            return false;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || depth == kSinkNone || !w || !h)
            return false;
        uint16_t prog = rm::program("vs_rm_quad", "fs_rm_softdepth");
        if (prog == rm::kNoHandle)
            return false;
        if (!m_format) {
            const bgfx::Caps* caps = bgfx::getCaps();
            const uint32_t need = BGFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER | BGFX_CAPS_FORMAT_TEXTURE_2D;
            m_format = caps && (caps->formats[bgfx::TextureFormat::R32F] & need) == need ? bgfx::TextureFormat::R32F
                                                                                       : bgfx::TextureFormat::R16F;
        }
        if (!m_depth.ensure(w, h, m_format, false, false))
            return false;
        uint16_t v;
        if (!rm::viewsHere(1, &v))
            return false;
        m_w = w, m_h = h;
        float a[4] = {P[10], P[11], P[14], P[15]};       // (c6.z, c6.w, c7.z, c7.w)
        rm::viewInto(v, m_depth.fb, w, h);
        rm::texture(0, (uint16_t)depth, BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT);
        rm::uniform("u_rmSoftCopy", a);
        rm::quad(v, prog, BGFX_STATE_WRITE_R);
        m_copies++;
        return true;
    }

    void bind(const DrawPacket& p)
    {
        if (!m_up) {
            m_uSoft = bgfx::createUniform("u_rmSoft", bgfx::UniformType::Vec4, 4);
            m_sDepth = bgfx::createUniform("s_rmSoftDepth", bgfx::UniformType::Sampler);
            m_uShadow = bgfx::createUniform("u_rmShadow", bgfx::UniformType::Vec4, 12);
            m_sShadow = bgfx::createUniform("s_rmShadow", bgfx::UniformType::Sampler);
            m_up = true;
        }
        bool additive = p.state.dstBlend == kBlendOne;
        bool scalesColour = p.state.srcBlend == kBlendOne;
        float u[4][4] = {
            {m_fade > 0 ? 1.0f / m_fade : 0.0f, m_near0, m_nearLen > 0 ? 1.0f / m_nearLen : 1e6f, scalesColour ? 1.0f : 0.0f},
            {0, 0, 0, 0},
            {m_w ? 1.0f / m_w : 0.0f, m_h ? 1.0f / m_h : 0.0f, additive ? 0.0f : m_cityK, 0.0f},
            {additive && m_hdr && hulk_gfx_sink_scene_hdr() ? m_addGain : 1.0f, 0, 0, 0},
        };
        // the sun's shadow on smoke and dust (the shadow pass's constants: none when it is off or this pass is not one
        // that receives); every sampler the program declares is bound (Vulkan reads an unbound one as garbage)
        static const float kNoShadow[12][4] = {};
        uint16_t atlas = rm::kNoHandle;
        const float* sc = additive ? nullptr : rm::shadowConstants(true, &atlas);
        if (sc)
            u[2][3] = m_shadowK;
        bgfx::setUniform(m_uSoft, u, 4);
        bgfx::setUniform(m_uShadow, sc ? sc : &kNoShadow[0][0], 12);
        if (atlas == rm::kNoHandle)
            atlas = rm::shadowDummy();
        if (atlas != rm::kNoHandle)
            bgfx::setTexture(4, m_sShadow, bgfx::TextureHandle{atlas},
                             BGFX_SAMPLER_COMPARE_LEQUAL | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
        if (additive || !rm::nightLightsBindPost(5))   // (the city's lights reach the smoke; else none bound)
            rm::nightLightsBind(p);
        bgfx::setTexture(6, m_sDepth, bgfx::TextureHandle{m_depth.tex},
                         BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT);
    }

    // HULK_SOFT_AB=N: the pass off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_SOFT_AB") ? atoi(getenv("HULK_SOFT_AB")) : 0;
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
                fprintf(stderr, "hulk-app: particles cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_on = 0;
    bool m_hdr = false, m_up = false, m_worldKnown = false, m_copied = false;
    uint16_t m_worldPass = 0xffff, m_prog = rm::kNoHandle;
    uint32_t m_format = 0, m_w = 0, m_h = 0;
    rm::Target m_depth;
    bgfx::UniformHandle m_uSoft = BGFX_INVALID_HANDLE, m_sDepth = BGFX_INVALID_HANDLE;
    bgfx::UniformHandle m_uShadow = BGFX_INVALID_HANDLE, m_sShadow = BGFX_INVALID_HANDLE;
    // the fade distance (camera units), the near fade (start, length), the city lights' and the shadow's strength on
    // smoke, the additive sprites' gain under HDR (wsweep1: 0.6; at 1 a stack of explosion flashes summed far past 1
    // and the tone map turned most of the frame white, play3 f39000 / f45001)
    float m_fade = 1.0f, m_near0 = 0.4f, m_nearLen = 1.6f, m_cityK = 0.35f, m_shadowK = 0.3f, m_addGain = 0.6f;
    unsigned m_frames = 0, m_copies = 0, m_notFacing = 0;
    double m_draws = 0;
};
HULK_RM_REGISTER_PASS(ParticlesPass);

} // namespace

void rm::particlesRebind(const DrawPacket& q) { s_rmPass_ParticlesPass.rebind(q); }
