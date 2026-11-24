// Upscaling (wperf1, docs/performance.md; Video Options > Upscaler, Render Scale). The Render Scale row draws the
// scene target at a share of the render resolution (app.cpp rrSize: 100% .. 50%); the Upscaler row decides how the
// frame reaches the present size: Off, the sink's bilinear stretch as before; FSR 1, AMD's EASU (edge-adaptive
// upsampling) into a target of the present size and RCAS (sharpening) after it (run/app/shaders/fs_rm_easu.sc,
// fs_rm_rcas.sc: ports of ffx_fsr1.h, MIT), presented 1:1 (hulk_gfx_sink_present_source).
// wperf2 (upscale.h, docs/performance.md 4.2): the temporal upscalers, which also do the anti-aliasing (they imply
// TAA: rm::upscalerTemporal): Temporal (ours, fs_rm_tupscale.sc: an FSR 2-class resolve into a history of the present
// size, then RCAS) and MetalFX (mfx.cpp: Apple's temporal scaler on macOS; elsewhere ours). Auto: the temporal one of
// the platform (MetalFX on macOS, ours elsewhere) when the Anti-Aliasing row is TAA, else FSR 1; on Android FSR 1
// (temporal upscaling costs there about what it saves). Both take TAA's jittered frame, motion, depth and HUD mask;
// frames without them (the front end: nothing jittered) take FSR 1. The whole frame (the HUD too) is upscaled after
// the game's effects, at the present; the HUD's pixels (the mask) are taken as drawn, without history.
// Output only: nothing here reads or writes the module's memory; the game sees 640x480 at every scale.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <bgfx/bgfx.h>

#include "mfx.h"
#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"
#include "upscale.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_present_source(uint32_t texture);
extern "C" uint32_t hulk_gfx_sink_scene_hdr();

namespace {

const char* s_name = "NATIVE";

class UpscalePass final : public rm::Pass {
  public:
    const char* name() const override { return "upscale"; }
    int order() const override { return 1000; }      // (the last postScene: everything else is in the frame)
    void settingsChanged(const rm::Settings& s) override
    {
        int mode = s[rm::kUpscaler], scale = s[rm::kRenderScale];
        if (scale < 0 || scale > 100)
            scale = 100;
        bool temporal = rm::upscalerTemporal(s);
        if (mode != m_mode || scale != m_scale || temporal != m_temporal) {
            static const char* const kName[5] = {"off", "auto", "FSR 1", "temporal", "MetalFX"};
            fprintf(stderr, "hulk-app: upscaler %s%s, render scale %d%%%s\n", kName[mode >= 0 && mode < 5 ? mode : 0],
                    temporal ? " (temporal: TAA)" : "", scale, scale ? "" : " (auto: 1280x960 pixels at most)");
        }
        m_mode = mode;
        m_temporal = temporal;
        if (scale != m_scale)
            rm::setRenderScale(scale);
        m_scale = scale;
        m_reset = true;
        if (const char* e = getenv("HULK_FSR"))          // (tuning: RCAS sharpness in stops, 0 = sharpest)
            sscanf(e, "%f", &m_stops);
        if (const char* e = getenv("HULK_TU"))           // (tuning: most accumulated weight, clip gamma, falloff, prior)
            sscanf(e, "%f,%f,%f,%f", &m_maxAcc, &m_gamma, &m_falloff, &m_prior);
        if (const char* e = getenv("HULK_TU_STOPS"))     // (tuning: RCAS after ours, after MetalFX)
            sscanf(e, "%f,%f", &m_tuStops, &m_mfxStops);
        if (const char* e = getenv("HULK_MFX_SIGN"))     // (tuning: MetalFX's jitter x, y and motion signs)
            sscanf(e, "%f,%f,%f", &m_mfxSign[0], &m_mfxSign[1], &m_mfxSign[2]);
        if (const char* e = getenv("HULK_TU_SIGN"))      // (tuning: our jitter's sign)
            sscanf(e, "%f", &m_tuSign);
    }
    void postScene(const rm::Scene& s, uint16_t& view) override
    {
        const SinkPresent* p = rm::currentPresent();
        if (!m_mode || !p || !s.width || !s.height) {
            rm::temporalWanted(false, 8);
            s_name = p && (uint32_t)p->w > s.width + s.width / 100 ? "BILINEAR" : "NATIVE";
            m_reset = true;
            return;
        }
        uint32_t ow = (uint32_t)p->w, oh = (uint32_t)p->h;
        // only upward (a render size at or above the present's is the sink's own stretch)
        bool up = !(ow * 100 <= s.width * 101 && oh * 100 <= s.height * 101);
        float ratio = (float)ow / (float)s.width;
        rm::temporalWanted(m_temporal && up && !m_abOff, (uint32_t)ceilf(8.0f * ratio * ratio));
        if (!up) {
            s_name = "NATIVE";
            m_reset = true;
            return;
        }
        const rm::TemporalFrame* tf = rm::temporalFrame();
        if (m_temporal && !m_abOff && tf && tf->w == s.width && tf->h == s.height) {
            bool reset = tf->reset || m_reset || ow != m_ow || oh != m_oh;
            bool mfx = (m_mode == 4 || m_mode == 1) && rm::mfxAvailable();
            if (mfx && metalFx(s, *tf, view, ow, oh, reset)) {
                done(ow, oh, "METALFX");
                return;
            }
            if (ours(s, *tf, view, ow, oh, reset)) {
                done(ow, oh, "TEMPORAL");
                return;
            }
        }
        if (fsr1(s, view, ow, oh)) {
            m_reset = true;
            s_name = "FSR1";
            return;
        }
        m_reset = true;
        s_name = "BILINEAR";
    }
    void frame() override
    {
        abCost();
        static int log = -1;
        if (log < 0)
            log = getenv("HULK_TU_LOG") && atoi(getenv("HULK_TU_LOG")) > 0;
        if (log && ++m_frames % 300 == 0) {
            uint32_t enc = 0, fail = 0;
            rm::mfxStats(&enc, &fail);
            fprintf(stderr, "hulk-app: upscale: %s, %u temporal frames of 300 (%u resets), MetalFX %u encoded, "
                    "%u failed\n", s_name, m_tuFrames, m_resets, enc, fail);
            m_tuFrames = m_resets = 0;
        }
    }

  private:
    void done(uint32_t ow, uint32_t oh, const char* name)
    {
        m_ow = ow, m_oh = oh;
        m_reset = false;
        s_name = name;
        m_tuFrames++;
    }
    bool fsr1(const rm::Scene& s, uint16_t& view, uint32_t ow, uint32_t oh)
    {
        if (view + 2 > rm::kFirstView + rm::kViewCount)
            return false;
        uint16_t easu = rm::program("vs_rm_quad", "fs_rm_easu"), rcas = rm::program("vs_rm_quad", "fs_rm_rcas");
        if (easu == rm::kNoHandle || rcas == rm::kNoHandle)
            return false;
        if (!m_up.ensure(ow, oh, bgfx::TextureFormat::RGBA8, false, false) ||
            !m_out.ensure(ow, oh, bgfx::TextureFormat::RGBA8, false, false))
            return false;
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        uint16_t v0 = view++, v1 = view++;
        float c0[4] = {(float)s.width, (float)s.height, 1.0f / s.width, 1.0f / s.height};
        rm::viewInto(v0, m_up.fb, ow, oh);
        rm::texture(0, (uint16_t)s.colour, point);
        rm::uniform("u_rmFsr0", c0);
        rm::quad(v0, easu, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        rcasInto(v1, m_up.tex, ow, oh, m_stops);
        hulk_gfx_sink_present_source(m_out.tex);
        return true;
    }
    void rcasInto(uint16_t v, uint16_t src, uint32_t ow, uint32_t oh, float stops)
    {
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        float c1[4] = {(float)ow, (float)oh, 1.0f / ow, 1.0f / oh};
        c1[3] = exp2f(-stops);
        rm::viewInto(v, m_out.fb, ow, oh);
        rm::texture(0, src, point);
        rm::uniform("u_rmFsr0", c1);
        rm::quad(v, rm::program("vs_rm_quad", "fs_rm_rcas"), BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
    }
    float flip() const
    {
        const bgfx::Caps* caps = bgfx::getCaps();
        return caps && caps->originBottomLeft ? 1.0f : 0.0f;
    }
    // ours: the resolve into the history (present size), then RCAS
    bool ours(const rm::Scene& s, const rm::TemporalFrame& tf, uint16_t& view, uint32_t ow, uint32_t oh, bool reset)
    {
        if (view + 2 > rm::kFirstView + rm::kViewCount)
            return false;
        uint16_t tu = rm::program("vs_rm_quad", "fs_rm_tupscale"), rcas = rm::program("vs_rm_quad", "fs_rm_rcas");
        if (tu == rm::kNoHandle || rcas == rm::kNoHandle)
            return false;
        if (!m_hist[0].ensure(ow, oh, bgfx::TextureFormat::RGBA16F, false, true) ||
            !m_hist[1].ensure(ow, oh, bgfx::TextureFormat::RGBA16F, false, true) ||
            !m_out.ensure(ow, oh, bgfx::TextureFormat::RGBA8, false, false))
            return false;
        if (m_histFor != 1)
            reset = true;                               // (the history was MetalFX's or nothing)
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        const uint32_t lin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        uint16_t v0 = view++, v1 = view++;
        rm::Target& in = m_hist[m_cur], &out = m_hist[m_cur ^ 1];
        float u0[4] = {(float)s.width, (float)s.height, 1.0f / s.width, 1.0f / s.height};
        float u1[4] = {(float)ow, (float)oh, 1.0f / ow, 1.0f / oh};
        static int dbg = getenv("HULK_TU_DEBUG") ? atoi(getenv("HULK_TU_DEBUG")) : 0;
        float u2[4] = {m_tuSign * tf.jitter[0], m_tuSign * tf.jitter[1], reset ? 1.0f : 0.0f, flip() + (dbg ? 2.0f : 0.0f)};
        float u3[4] = {m_maxAcc, m_gamma, m_falloff, m_prior};
        rm::viewInto(v0, out.fb, ow, oh);
        rm::texture(0, (uint16_t)s.colour, point);
        rm::texture(1, tf.depth, point);
        rm::texture(2, tf.motion, point);
        rm::texture(3, tf.mask, lin);
        rm::texture(4, in.tex, lin);
        rm::uniform("u_rmTu0", u0);
        rm::uniform("u_rmTu1", u1);
        rm::uniform("u_rmTu2", u2);
        rm::uniform("u_rmTu3", u3);
        rm::quad(v0, tu, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        rcasInto(v1, out.tex, ow, oh, m_tuStops);
        hulk_gfx_sink_present_source(m_out.tex);
        m_cur ^= 1;
        m_histFor = 1;
        m_resets += reset;
        return true;
    }
    // MetalFX: the scaler between two views (the hook view), then the HUD put back (fs_rm_tucomp.sc) and RCAS (its
    // output is a little soft next to FSR 1's)
    bool metalFx(const rm::Scene& s, const rm::TemporalFrame& tf, uint16_t& view, uint32_t ow, uint32_t oh, bool reset)
    {
        if (view + 3 > rm::kFirstView + rm::kViewCount)
            return false;
        uint16_t comp = rm::program("vs_rm_quad", "fs_rm_tucomp");
        if (comp == rm::kNoHandle || !m_up.ensure(ow, oh, bgfx::TextureFormat::RGBA8, false, false) ||
            !m_out.ensure(ow, oh, bgfx::TextureFormat::RGBA8, false, false))
            return false;
        uint16_t outTex = rm::mfxPrepare(s.width, s.height, ow, oh, hulk_gfx_sink_scene_hdr() != 0);
        if (outTex == 0xffff)
            return false;
        if (m_histFor != 2)
            reset = true;
        uint16_t v0 = view++, v1 = view++, v2 = view++;
        rm::MfxInputs in;
        in.colour = (uint16_t)s.colour, in.depth = tf.depth, in.motion = tf.motion, in.mask = tf.mask;
        in.jitter[0] = m_mfxSign[0] * tf.jitter[0];
        in.jitter[1] = m_mfxSign[1] * tf.jitter[1];
        in.mvScale[0] = m_mfxSign[2] * (float)s.width;
        in.mvScale[1] = m_mfxSign[2] * (float)s.height;
        in.reset = reset;
        rm::viewInto(v0, m_out.fb, ow, oh);
        rm::mfxSchedule(v0, in);
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        const uint32_t lin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        float u0[4] = {(float)s.width, (float)s.height, 1.0f / s.width, 1.0f / s.height};
        float u2[4] = {0, 0, 0, flip()};
        rm::viewInto(v1, m_up.fb, ow, oh);
        rm::texture(0, (uint16_t)s.colour, point);
        rm::texture(3, tf.mask, lin);
        rm::texture(4, outTex, point);
        rm::uniform("u_rmTu0", u0);
        rm::uniform("u_rmTu2", u2);
        rm::quad(v1, comp, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        rcasInto(v2, m_up.tex, ow, oh, m_mfxStops);
        hulk_gfx_sink_present_source(m_out.tex);
        m_histFor = 2;
        m_resets += reset;
        return true;
    }

    // HULK_UPSCALE_AB=N: the temporal upscaler off (TAA's own resolve + FSR 1) and on in turns of N presented frames
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_UPSCALE_AB") ? atoi(getenv("HULK_UPSCALE_AB")) : 0;
        if (n <= 0)
            return;
        const bgfx::Stats* st = bgfx::getStats();
        if (st && m_abFrame > 3 && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin) {
            int i = m_abOff ? 0 : 1;
            m_abGpu[i] += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq;
            m_abCpu[i] += 1e3 * (double)(st->cpuTimeEnd - st->cpuTimeBegin) / (double)st->cpuTimerFreq;
            m_abN[i]++;
        }
        if (++m_abFrame >= (unsigned)n) {
            m_abFrame = 0;
            m_abOff = !m_abOff;
            m_reset = true;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: upscale cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u; on: %s)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0, m_lastTemporal);
        }
        if (!m_abOff && (s_name[0] == 'T' || s_name[0] == 'M'))
            m_lastTemporal = s_name;
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};
    const char* m_lastTemporal = "-";

    int m_mode = 0, m_scale = 100;
    bool m_temporal = false, m_reset = true;
    float m_stops = 0.25f, m_tuStops = 0.25f;
    float m_maxAcc = 12.0f, m_gamma = 1.25f, m_falloff = 2.0f, m_prior = 0.35f, m_mfxStops = 0.5f;
    float m_mfxSign[3] = {1.0f, 1.0f, 1.0f}, m_tuSign = 1.0f;
    uint32_t m_ow = 0, m_oh = 0, m_cur = 0, m_histFor = 0, m_frames = 0, m_tuFrames = 0, m_resets = 0;
    rm::Target m_up, m_out, m_hist[2];
};
HULK_RM_REGISTER_PASS(UpscalePass);

} // namespace

const char* rm::upscalerName() { return s_name; }
