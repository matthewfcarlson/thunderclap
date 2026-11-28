// Light shafts (wrays1, D249/D250, docs/light-shafts.md; Video Options > Light Shafts: Off (Original) / On).
//
// Volumetric light in the air, output only (nothing here reads or writes the module's memory):
// - By day (and under the moon, weaker), the key light's in-scattering marched along each view ray at half size through
//   the sun shadows' atlas (shadows.cpp, both rows): air in the shadow of a building, a canyon wall or the Hulk stays
//   dark and the light between reads as shafts, from a sun on screen or off it. A Henyey-Greenstein phase lobe makes it
//   strongest looking towards the sun; the air thins with height. Needs Shadows (Low or High): with them off there is
//   no sun part.
// - At night, each street lamp of the Night Lights' list (nightlights.cpp, rm_city.sh kind 1) gets a soft cone of light
//   in the mist below its head, in closed form per pixel from the tile lists (Atmosphere's spherical glow stays as it
//   is). Needs Night Lights.
// Where: in the world's pass, once its opaque draws are done, at its first translucent / stencil / 2D draw (after the
// ambient occlusion and the atmosphere's views, before particles, glows and explosions: the shafts add nothing to a
// flash), or else at the frame's first effect. The march runs in one view into a half-size RGBA16F target (a 4x4 Bayer
// start offset per pixel), the apply in a second view over the scene's colour: a 4x4 depth-weighted blur that takes each
// offset once, so the result is steady from frame to frame without TAA, added over the scene with the shadowed air
// dimming what is behind it (blend one / src-alpha).
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

namespace {

int envInt(const char* name)
{
    const char* e = getenv(name);
    return e ? atoi(e) : 0;
}

class RaysPass final : public rm::Pass {
  public:
    const char* name() const override { return "rays"; }
    int order() const override { return 32; }            // (after the atmosphere's views: shafts over the fog)
    void settingsChanged(const rm::Settings& s) override
    {
        int on = s[rm::kLightShafts] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: light shafts %s\n", on ? "on" : "off");
        m_on = on;
        // HULK_RAYS=strength,density,falloff,dim,g,lamps,steps,moon,base (development tuning)
        if (const char* e = getenv("HULK_RAYS"))
            sscanf(e, "%f,%f,%f,%f,%f,%f,%f,%f,%f", &m_strength, &m_density, &m_falloff, &m_dim, &m_g, &m_lamps, &m_steps,
                   &m_moon, &m_base);
    }
    bool midFrame() const override { return m_on && !m_abOff; }
    void draw(const DrawPacket& p) override
    {
        if (!m_on || m_abOff || m_done || (p.viewMode != 0 && !m_opaque))
            return;
        float view[3][4], inv[3][3], proj[16];
        if (!rm::frameCamera(view, inv, proj))
            return;
        if (!m_worldKnown) {
            m_worldPass = rm::currentGamePass();
            m_worldKnown = true;
        }
        if (rm::currentGamePass() != m_worldPass)
            return;
        if (!m_shadowKnown) {                            // (the shadow pass answers only inside the world's pass)
            uint16_t atlas = rm::kNoHandle;
            const float* sc = rm::shadowConstants(true, &atlas);
            if (sc && atlas != rm::kNoHandle) {
                memcpy(m_shadow, sc, sizeof m_shadow);
                m_atlas = atlas;
                m_shadowKnown = true;
            }
        }
        if (p.lighting && p.lights)
            keyColour(p);
        if (!p.state.blend && p.state.depthWrite && p.viewMode == 0 && !p.state.stencil) {
            m_opaque = true;
            return;
        }
        if (m_opaque && (p.viewMode != 0 || p.state.stencil || (p.state.blend && !p.state.depthWrite))) {
            run(-1);
            rm::lightingRebind(p);                       // (our submits took the per-pixel program's samplers)
        }
    }
    void copy(uint16_t pass, const SinkTarget&) override
    {
        if (m_on && !m_abOff && !m_done && m_opaque)
            run(pass);
    }
    void fx(const FxPacket& p) override
    {
        if (m_on && !m_abOff && !m_done && m_opaque)
            run(p.pass);
    }
    void frame() override
    {
        abCost();
        if (envInt("HULK_RAYS_LOG") > 0 && ++m_frames >= 300) {
            fprintf(stderr, "hulk-app: rays: %u runs in 300 frames (%u with the sun, %u with lamps); key %.2f %.2f %.2f, "
                    "night %.2f\n", m_runs, m_sunRuns, m_lampRuns, m_key[0], m_key[1], m_key[2], rm::nightAmount());
            m_frames = m_runs = m_sunRuns = m_lampRuns = 0;
        }
        m_done = m_opaque = m_worldKnown = m_shadowKnown = false;
    }

  private:
    // the key light's colour (the strongest directional light of the frame's lit draws, the sun shadows' light), smoothed
    void keyColour(const DrawPacket& p)
    {
        float best = 0.05f;
        const SinkLight* k = nullptr;
        for (int i = 0; i < 8; i++) {
            const SinkLight& l = p.lights[i];
            float y = 0.3f * l.diffuse[0] + 0.6f * l.diffuse[1] + 0.1f * l.diffuse[2];
            if (l.on && l.type == 3 && y > best)
                best = y, k = &l;
        }
        if (!k)
            return;
        for (int i = 0; i < 3; i++) {
            float c = fminf(fmaxf(k->diffuse[i], 0.0f), 1.5f);
            m_key[i] = m_keyKnown ? m_key[i] + 0.05f * (c - m_key[i]) : c;
        }
        m_keyKnown = true;
    }
    void run(int gamePass)
    {
        m_done = true;
        float view[3][4], inv[3][3], P[16];
        if (!rm::frameCamera(view, inv, P))
            return;
        bool sun = m_shadowKnown && m_keyKnown && m_shadow[8][0] > 0.5f;
        bool lamps = m_lamps > 0 && rm::nightLightsActive() && rm::nightAmount() > 0.02f;
        if (!sun && !lamps)
            return;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || depth == kSinkNone || !w || !h)
            return;
        uint16_t march = rm::program("vs_rm_quad", "fs_rm_rays"), apply = rm::program("vs_rm_quad", "fs_rm_raysapply");
        if (march == rm::kNoHandle || apply == rm::kNoHandle)
            return;
        if (!m_half.ensure((w + 1) / 2, (h + 1) / 2, bgfx::TextureFormat::RGBA16F, false, false))
            return;
        if (m_colourOf != colour || m_fb == rm::kNoHandle) {          // (the scene's colour alone: the depth is read)
            if (m_fb != rm::kNoHandle)
                bgfx::destroy(bgfx::FrameBufferHandle{m_fb});
            bgfx::TextureHandle t{(uint16_t)colour};
            bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(1, &t, false);
            m_fb = bgfx::isValid(f) ? f.idx : rm::kNoHandle;
            m_colourOf = colour;
            if (m_fb == rm::kNoHandle)
                return;
        }
        if (m_sShadow == rm::kNoHandle) {
            m_sShadow = bgfx::createUniform("s_rmShadow", bgfx::UniformType::Sampler).idx;
            m_uShadow = bgfx::createUniform("u_rmShadow", bgfx::UniformType::Vec4, 12).idx;
        }
        uint16_t v[2];
        if (!(gamePass < 0 ? rm::viewsHere(2, v) : rm::viewsBefore((uint16_t)gamePass, 2, v)))
            return;
        float up[3] = {view[0][1], view[1][1], view[2][1]};
        float ul = sqrtf(up[0] * up[0] + up[1] * up[1] + up[2] * up[2]);
        for (float& x : up)
            x = ul > 0 ? x / ul : 0;
        float night = rm::nightAmount();
        float k = m_strength * (1.0f + (m_moon - 1.0f) * night);
        float u[8][4] = {
            {P[0], P[5], P[2], P[6]},
            {P[10], P[11], P[14], P[15]},
            {P[3], P[7], sun ? m_shadow[11][0] : 0.0f, sun ? fminf(fmaxf(m_steps, 4.0f), 32.0f) : 0.0f},
            {up[0], up[1], up[2], m_falloff},
            {m_key[0] * k, m_key[1] * k, m_key[2] * k, m_density},
            {m_shadow[9][0], m_shadow[9][1], m_shadow[9][2], m_g},
            {m_dim, lamps ? m_lamps : 0.0f, (float)w / (float)m_half.w, 600.0f},
            {m_phaseCap, 6.0f, 0.55f, m_base},
        };
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        // the march (every sampler the program declares is bound: Vulkan reads an unbound one as garbage)
        rm::viewInto(v[0], m_half.fb, m_half.w, m_half.h);
        rm::texture(0, (uint16_t)depth, point);
        rm::uniform("u_rmRays", &u[0][0], 8);
        static const float kNoShadow[12][4] = {};
        bgfx::setUniform(bgfx::UniformHandle{m_uShadow}, sun ? &m_shadow[0][0] : &kNoShadow[0][0], 12);
        uint16_t atlas = sun ? m_atlas : rm::shadowDummy();
        if (atlas != rm::kNoHandle)
            rm::bindTexture(4, m_sShadow, atlas,
                             BGFX_SAMPLER_COMPARE_LEQUAL | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
        if (!lamps || !rm::nightLightsBindPost(5))
            noLights();
        rm::quad(v[0], march, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        // the apply: blurred and added over the scene
        static const int show = envInt("HULK_RAYS_SHOW");
        float t[4] = {1.0f / m_half.w, 1.0f / m_half.h, (float)m_half.w, (float)m_half.h};
        float t1[4] = {show ? 1.0f : 0.0f, 600.0f, 0, 0};
        rm::viewInto(v[1], m_fb, w, h);
        rm::texture(0, (uint16_t)depth, point);
        rm::texture(1, m_half.tex, point);
        rm::uniform("u_rmRays", &u[0][0], 8);
        rm::uniform("u_rmPost0", t);
        rm::uniform("u_rmPost1", t1);
        rm::quad(v[1], apply, BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_ONE, BGFX_STATE_BLEND_SRC_ALPHA));
        m_runs++;
        m_sunRuns += sun;
        m_lampRuns += lamps;
    }
    // the program declares the night lights' texture: an empty list when there are none (as the atmosphere's)
    void noLights()
    {
        if (m_empty == rm::kNoHandle) {
            static float none[4] = {-1, -1, -1, -1};
            bgfx::TextureHandle t = bgfx::createTexture2D(1, 1, false, 1, bgfx::TextureFormat::RGBA32F, BGFX_SAMPLER_POINT,
                                                          bgfx::copy(none, sizeof none));
            m_empty = bgfx::isValid(t) ? t.idx : rm::kNoHandle;
            m_sCity = bgfx::createUniform("s_rmCity", bgfx::UniformType::Sampler).idx;
            m_uCity = bgfx::createUniform("u_rmCity", bgfx::UniformType::Vec4, 3).idx;
        }
        static const float zero[3][4] = {};
        bgfx::setUniform(bgfx::UniformHandle{m_uCity}, zero, 3);
        if (m_empty != rm::kNoHandle)
            rm::bindTexture(5, m_sCity, m_empty, BGFX_SAMPLER_POINT);
    }
    // HULK_RAYS_AB=N: the pass off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = envInt("HULK_RAYS_AB");
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
                fprintf(stderr, "hulk-app: rays cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1], m_abCpu[0] / m_abN[0],
                        m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1], st ? (unsigned)st->width : 0,
                        st ? (unsigned)st->height : 0);
        }
    }

    int m_on = 0;
    bool m_done = false, m_opaque = false, m_worldKnown = false, m_shadowKnown = false, m_keyKnown = false;
    uint16_t m_worldPass = 0, m_atlas = rm::kNoHandle, m_fb = rm::kNoHandle, m_empty = rm::kNoHandle;
    uint16_t m_sShadow = rm::kNoHandle, m_uShadow = rm::kNoHandle, m_sCity = rm::kNoHandle, m_uCity = rm::kNoHandle;
    uint32_t m_colourOf = kSinkNone;
    float m_shadow[12][4] = {}, m_key[3] = {0, 0, 0};
    float m_strength = 1.0f, m_density = 0.0015f, m_falloff = 0.012f, m_dim = 2.0f, m_g = 0.7f, m_lamps = 0.2f;
    float m_steps = 24.0f, m_moon = 0.15f, m_phaseCap = 5.0f, m_base = 0.85f;
    rm::Target m_half;
    unsigned m_frames = 0, m_runs = 0, m_sunRuns = 0, m_lampRuns = 0;
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};
};
HULK_RM_REGISTER_PASS(RaysPass);

} // namespace
