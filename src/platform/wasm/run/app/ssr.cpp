// Screen-space reflections (wssr1, docs/reflections.md; Video Options > Reflections: Off (Original) / Low / High).
//
// 1. The G-buffer: a view of the runner's taken at the frame's first scene pass (rm::newView, before the world) into
//    a target of its own (RGBA16F + a sampled depth, the scene's size, no MSAA). Every opaque draw of the world's pass
//    is drawn again into it as it reaches the sink, with the faithful vertex transform (vs_px_ff / vs_px_skin) and
//    fs_rm_ssrmask.sc: its depth, a camera-space normal (the vertex normal where the draw has one, else the face's) and
//    the draw's reflectance, chosen per draw: rooms' ground (faces up in world space: streets, pavements, roofs) is
//    wet, strongly at night; `layeredReflect` buildings and `environment` (sphere-mapped) objects reflect everywhere;
//    characters, props and the rest only occlude. The additive glows (street lamps' halos, orbs, fire, explosions)
//    go in as depth where their texture is bright, so rays find them.
// 2. The trace (fs_rm_ssr.sc): at the frame's first effect (the game's colour pass and bloom, where HDR tone maps;
//    before HDR's views) the scene so far is copied, and each reflective pixel's mirrored view ray is marched across
//    the G-buffer's depth (Low: half size, 24 steps; High: full size, 48), the hit taking the scene's colour.
// 3. The composite (fs_rm_ssrapply.sc): blurred by roughness, weighted by Fresnel and the surface's strength, blended
//    over the scene. Where no ray hit, the scene keeps the game's own surface (its REFL / sphere-map reflection).
//
// The reflection is readable by other passes (ssr.h): the traced target and the G-buffer, valid from the composite to
// the end of the frame. Output only: nothing here reads or writes the module's memory.
#include "ssr.h"

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
extern "C" uint32_t hulk_gfx_sink_scene_hdr();

namespace {

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_SSR_LOG") && atoi(getenv("HULK_SSR_LOG")) > 0;
    return on;
}

class SsrPass;
SsrPass* s_pass;

class SsrPass final : public rm::Pass {
  public:
    SsrPass() { s_pass = this; }
    const char* name() const override { return "reflections"; }
    // (before lighting, 10: its G-buffer draws are submitted before the lighting pass binds the draw's own textures;
    // before HDR, 30: the composite is in the scene's light, then tone mapped)
    int order() const override { return 7; }
    void settingsChanged(const rm::Settings& s) override
    {
        int level = s[rm::kReflections];
        if (level != m_level)
            fprintf(stderr, "hulk-app: reflections %s\n", level == 0 ? "off" : level == 1 ? "low" : "high");
        m_level = level;
        // (tuning: strength, wet ground at night, by day, buildings, longest ray, F0 of wet ground)
        if (const char* e = getenv("HULK_SSR"))
            sscanf(e, "%f,%f,%f,%f,%f,%f", &m_strength, &m_wetNight, &m_wetDay, &m_building, &m_maxRay, &m_wetF0);
    }
    bool midFrame() const override { return m_level > 0 && !m_abOff; }
    void sceneBegin(SinkPass&) override
    {
        m_view = rm::kNoView;
        if (!midFrame())
            return;
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (!w || !h || !ensureG(w, h))
            return;
        if ((m_view = rm::newView()) == rm::kNoView)
            return;
        rm::viewInto(m_view, m_gfb, m_gw, m_gh, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0, 1.0f);
    }
    void draw(const DrawPacket& p) override
    {
        if (m_view == rm::kNoView || m_done)
            return;
        if (!m_ready) {
            if (!takeView(p))
                return;
        } else if (rm::currentGamePass() != m_worldPass) {
            return;
        }
        if (p.viewMode != 0 || p.state.stencil || p.query != kSinkNone || !p.vertexConstants || !p.state.writeMask ||
            !(p.vertexProgram <= 2 || p.vertexProgram == 6))
            return;
        bool opaque = !p.state.blend && p.state.depthWrite;
        bool glow = p.state.blend && p.state.dstBlend == kBlendOne && p.state.depthTest && p.vertexProgram == 0 &&
                    (p.state.srcBlend == kBlendOne || p.state.srcBlend == kBlendSrcAlpha);
        if (!opaque && !glow)
            return;
        float mat[4] = {0, 0, 0, glow ? 2.0f : 0.0f};
        bool world = !glow && isWorld(p);
        if (world && p.fog)
            m_fogLum += 0.3f * p.frag[1][0] + 0.59f * p.frag[1][1] + 0.11f * p.frag[1][2], m_fogN++;
        if (!glow) {
            if (world) {
                mat[0] = p.shaderKind == 2 ? m_building : 0.0f;
                mat[3] = p.shaderKind == 2 ? 3.0f : 0.0f;          // (the glass by stage 0's alpha)
                mat[1] = m_night ? 0.1f : 0.3f;
                mat[2] = m_night ? m_wetNight : m_wetDay;
            } else if (p.shaderKind == 3) {
                mat[0] = 0.8f, mat[1] = 0.06f, mat[3] = 1.0f;
            } else if (p.shaderKind == 2) {
                mat[0] = m_building, mat[1] = 0.1f, mat[3] = 3.0f;
            }
        }
        static const char* const kVs[3] = {"vs_px_ff", "vs_px_skin", "vs_px_skin_onebone"};
        uint16_t prog = rm::program(kVs[p.vertexProgram == 6 ? 0 : p.vertexProgram], "fs_rm_ssrmask");
        if (prog == rm::kNoHandle)
            return;
        DrawPacket q = p;
        q.pipeline = prog;
        q.pass = m_view;
        q.query = kSinkNone;
        q.fog = 0;
        q.state.writeMask = 0xf;
        q.state.blend = 0;
        q.state.stencil = 0;
        if (glow) {
            q.state.cull = 0;
        } else {
            q.state.depthTest = 1;
            q.state.depthFunc = 3;                                  // (lequal)
        }
        q.state.depthWrite = 1;
        rm::uniform("u_rmSsrMat", mat);
        rm::uniform("u_rmSsrUp", m_up);
        hulk_gfx_sink_submit_draw(&q);
        m_draws++, m_frameDraws++;
        m_reflective += mat[0] > 0 || mat[2] > 0;
        m_glows += glow;
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
    void frame() override
    {
        abCost();
        // night: the rooms' fog is dark (downtown night ~0.05; the desert's and day's are light)
        if (m_fogN) {
            float lum = m_fogLum / m_fogN;
            m_night = lum < 0.15f;
            m_lastFog = lum;
        }
        m_fogLum = 0, m_fogN = 0;
        if (logOn() && ++m_frames % 300 == 0) {
            fprintf(stderr, "hulk-app: reflections: %u of 300 frames traced; G-buffer draws %.1f a frame (%.1f "
                    "reflective, %.1f glows); fog %.3f (%s)\n", m_runs, m_draws / 300.0, m_reflective / 300.0,
                    m_glows / 300.0, m_lastFog, m_night ? "night" : "day");
            m_runs = 0, m_draws = m_reflective = m_glows = 0;
        }
        m_ready = m_done = m_traced = false;
        m_frameDraws = 0;
    }

    bool traced(rm::SsrResult* out) const
    {
        if (!m_traced)
            return false;
        out->reflection = m_trace.tex;
        out->gbuffer = m_gcol;
        out->depth = m_gdepth;
        out->width = m_trace.w, out->height = m_trace.h;
        out->gwidth = m_gw, out->gheight = m_gh;
        memcpy(out->proj, m_proj, sizeof m_proj);
        return true;
    }

  private:
    bool active() const { return midFrame() && m_view != rm::kNoView && m_ready && !m_done && m_frameDraws; }
    bool ensureG(uint32_t w, uint32_t h)
    {
        if (m_gfb != rm::kNoHandle && m_gw == w && m_gh == h)
            return true;
        if (m_gfb != rm::kNoHandle)
            bgfx::destroy(bgfx::FrameBufferHandle{m_gfb});
        m_gfb = m_gcol = m_gdepth = rm::kNoHandle;
        const bgfx::Caps* caps = bgfx::getCaps();
        const uint32_t need = BGFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER | BGFX_CAPS_FORMAT_TEXTURE_2D;
        bgfx::TextureFormat::Enum df = caps && (caps->formats[bgfx::TextureFormat::D32F] & need) == need
                                           ? bgfx::TextureFormat::D32F : bgfx::TextureFormat::D24;
        const uint64_t flags = BGFX_TEXTURE_RT | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        bgfx::TextureHandle t[2] = {
            bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, bgfx::TextureFormat::RGBA16F, flags),
            bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, df, flags)};
        if (!bgfx::isValid(t[0]) || !bgfx::isValid(t[1])) {
            if (bgfx::isValid(t[0])) bgfx::destroy(t[0]);
            if (bgfx::isValid(t[1])) bgfx::destroy(t[1]);
            return false;
        }
        bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(2, t, true);
        if (!bgfx::isValid(f))
            return false;
        m_gfb = f.idx, m_gcol = t[0].idx, m_gdepth = t[1].idx;
        m_gw = w, m_gh = h;
        fprintf(stderr, "hulk-app: reflections: G-buffer %ux%u (%s depth)\n", w, h,
                df == bgfx::TextureFormat::D32F ? "D32F" : "D24");
        return true;
    }
    // the world's view and projection: a room draw (unlit fixed function, a world shader, opaque; its modelview is
    // the view itself; c4..c7 the world's projection, not the sky's)
    bool takeView(const DrawPacket& p)
    {
        if (p.vertexProgram != 0 || !p.vertexConstants || p.vertexConstantCount < 8 || p.transient != kSinkNone ||
            p.lighting || p.state.blend || !p.state.depthWrite || p.shaderKind < 1 || p.shaderKind > 2 || p.viewMode ||
            !rm::passIsScene(p.pass))
            return false;
        const float* c = p.vertexConstants;
        const float* pr = c + 16;
        if (!(fabsf(pr[14]) > 0.5f && fabsf(pr[15]) < 1e-3f && fabsf(pr[12]) < 1e-6f && fabsf(pr[13]) < 1e-6f))
            return false;
        memcpy(m_proj, pr, sizeof m_proj);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                m_viewM[i][j] = c[4 * i + j];
        // world up (0, 1, 0) in camera space: the view's second column
        float ux = m_viewM[0][1], uy = m_viewM[1][1], uz = m_viewM[2][1];
        float l = sqrtf(ux * ux + uy * uy + uz * uz);
        if (l < 1e-6f)
            return false;
        m_up[0] = ux / l, m_up[1] = uy / l, m_up[2] = uz / l;
        m_up[3] = 0.85f;                                            // (ground: within ~32 degrees of level)
        m_worldPass = rm::currentGamePass();
        m_ready = true;
        return true;
    }
    bool isWorld(const DrawPacket& p) const
    {
        if (p.vertexProgram != 0 || p.lighting || p.shaderKind < 1 || p.shaderKind > 2 || p.vertexConstantCount < 4)
            return false;
        const float* c = p.vertexConstants;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                if (fabsf(c[4 * i + j] - m_viewM[i][j]) > 1e-3f * (1.0f + fabsf(m_viewM[i][j])))
                    return false;
        return true;
    }
    // the trace and the composite in views before the game pass `pass` goes on
    void run(uint16_t pass)
    {
        m_done = true;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || !w || !h || w != m_gw || h != m_gh)
            return;
        uint16_t trace = rm::program("vs_rm_quad", "fs_rm_ssr"), apply = rm::program("vs_rm_quad", "fs_rm_ssrapply");
        if (trace == rm::kNoHandle || apply == rm::kNoHandle)
            return;
        bool high = m_level >= 2;
        uint32_t tw = high ? w : (w + 1) / 2, th = high ? h : (h + 1) / 2;
        bgfx::TextureFormat::Enum sf = hulk_gfx_sink_scene_hdr() ? bgfx::TextureFormat::RGBA16F
                                                                   : bgfx::TextureFormat::BGRA8;
        if (!m_copy.ensure(w, h, sf, true) || !m_trace.ensure(tw, th, bgfx::TextureFormat::RGBA16F, false, true))
            return;
        uint16_t v[2];
        if (!rm::viewsBefore(pass, 2, v))
            return;
        const bgfx::Caps* caps = bgfx::getCaps();
        float flip = caps && caps->originBottomLeft ? 1.0f : 0.0f;
        const float* c = m_proj;                                    // rows c4, c5, c6, c7
        float u0[4] = {c[0], c[5], c[2], c[6]};
        float u1[4] = {c[10], c[11], c[14], c[15]};
        float u2[4] = {c[3], c[7], m_maxRay, high ? 48.0f : 24.0f};
        float u3[4] = {0.03f, flip, 1.0f / tw, 1.0f / th};
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        const uint32_t lin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        // the scene as it is now (a view's blits run before its draws), then the trace
        bgfx::TextureRegion dst, src;
        dst.init(bgfx::TextureHandle{m_copy.tex});
        src.init(bgfx::TextureHandle{(uint16_t)colour});
        bgfx::blit(v[0], dst, src);
        rm::viewInto(v[0], m_trace.fb, m_trace.w, m_trace.h, BGFX_CLEAR_COLOR, 0);
        rm::texture(0, m_gdepth, point);
        rm::texture(1, m_gcol, point);
        rm::texture(2, m_copy.tex, lin);
        rm::uniform("u_rmSsr0", u0);
        rm::uniform("u_rmSsr1", u1);
        rm::uniform("u_rmSsr2", u2);
        rm::uniform("u_rmSsr3", u3);
        rm::quad(v[0], trace, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        // the composite over the scene
        static const int show = getenv("HULK_SSR_SHOW") ? atoi(getenv("HULK_SSR_SHOW")) : 0;
        float a3[4] = {m_strength, flip, 1.0f / tw, 1.0f / th};
        float a4[4] = {high ? 6.0f : 3.0f, (float)show, m_wetF0, 0.5f};
        // (wlook3: the gather's least radius in trace texels: Low's half-size trace is denoised by a ring of 1.25
        // texels, High's by 0.75)
        float a2[4] = {c[3], c[7], high ? 0.75f : 1.25f, 0.0f};
        rm::viewInto(v[1], (uint16_t)fb, w, h);
        rm::texture(0, m_gdepth, point);
        rm::texture(1, m_gcol, point);
        rm::texture(2, m_trace.tex, lin);
        rm::uniform("u_rmSsr0", u0);
        rm::uniform("u_rmSsr1", u1);
        rm::uniform("u_rmSsr2", a2);
        rm::uniform("u_rmSsr3", a3);
        rm::uniform("u_rmSsr4", a4);
        rm::quad(v[1], apply, BGFX_STATE_WRITE_RGB |
                                  (show ? 0 : BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA,
                                                                    BGFX_STATE_BLEND_INV_SRC_ALPHA)));
        m_runs++;
        m_traced = true;
    }
    // HULK_SSR_AB=N: reflections off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_SSR_AB") ? atoi(getenv("HULK_SSR_AB")) : 0;
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
                fprintf(stderr, "hulk-app: reflections cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f "
                        "ms (%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_level = 0;
    float m_strength = 1.0f, m_wetNight = 1.0f, m_wetDay = 0.0f, m_building = 0.8f, m_maxRay = 120.0f,
          m_wetF0 = 0.15f;
    uint16_t m_view = rm::kNoView, m_worldPass = 0;
    bool m_ready = false, m_done = false, m_traced = false, m_night = false;
    float m_proj[16], m_viewM[3][4], m_up[4] = {0, 1, 0, 0.85f};
    float m_fogLum = 0, m_lastFog = 0;
    unsigned m_fogN = 0;
    uint16_t m_gfb = rm::kNoHandle, m_gcol = rm::kNoHandle, m_gdepth = rm::kNoHandle;
    uint32_t m_gw = 0, m_gh = 0;
    rm::Target m_copy, m_trace;
    unsigned m_frames = 0, m_runs = 0, m_frameDraws = 0;
    double m_draws = 0, m_reflective = 0, m_glows = 0;
};
HULK_RM_REGISTER_PASS(SsrPass);

} // namespace

bool rm::ssrResult(SsrResult* out) { return s_pass && s_pass->traced(out); }
