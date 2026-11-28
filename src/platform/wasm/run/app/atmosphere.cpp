// The atmosphere (wlook2, docs/night.md; Video Options > Atmosphere: Original / Enhanced).
//
// Two parts, both output only (nothing here reads or writes the module's memory):
// - The sky. The game draws its sky dome first in the world's pass: opaque, unlit, fixed function, one stage (texture
//   x vertex colour, fog), with a projection of its own (another near and far than the rooms'). That draw keeps its
//   packet and takes the runner's program fs_rm_sky.sc, which draws it exactly as the game does and then re-grades it by
//   the view direction in world space: a deeper zenith, a horizon glow (the city's lights at night, haze by day), the
//   dome's clouds lit from below by the city, stars and a moon where it is dark and clear, the moon (or the sun's glow)
//   in the direction of the location's key light. The game's own sky effects (lightning, flares) draw over it as ever.
// - The air. Over the world's opaque draws, before its translucent ones (where ambient occlusion runs), a full-screen
//   view from the scene's depth adds exponential height fog (dense in the streets, thin over the roofs) and a little
//   aerial perspective on top of the game's own linear fog, and the night lights' glow in the mist (nightlights.cpp):
//   each lamp's in-scattering along the view ray. The Fog row keeps working: Reduced halves this fog, Off removes it
//   (the lamps' glow stays, at half).
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <vector>

#include <bgfx/bgfx.h>

#include "nightlights.h"
#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);

namespace {

int envInt(const char* name)
{
    const char* e = getenv(name);
    return e ? atoi(e) : 0;
}

bool inverse3(const float m[3][4], float o[3][3])
{
    float det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    if (fabsf(det) < 1e-12f)
        return false;
    float id = 1.0f / det;
    o[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * id;
    o[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * id;
    o[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * id;
    o[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * id;
    o[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * id;
    o[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * id;
    o[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * id;
    o[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * id;
    o[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * id;
    return true;
}

class AtmospherePass final : public rm::Pass {
  public:
    const char* name() const override { return "atmosphere"; }
    int order() const override { return 30; }            // (after ambient occlusion's views: fog over the occlusion)
    void settingsChanged(const rm::Settings& s) override
    {
        int on = s[rm::kAtmosphere] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: atmosphere %s\n", on ? "enhanced" : "original");
        m_on = on;
        // HULK_ATMOS=sky,stars,horizon,fogNight,fogDay,falloff,aerial,lamps (development tuning)
        if (const char* e = getenv("HULK_ATMOS"))
            sscanf(e, "%f,%f,%f,%f,%f,%f,%f,%f", &m_sky, &m_stars, &m_horizon, &m_fogNight, &m_fogDay, &m_falloff,
                   &m_aerial, &m_lamps);
    }
    bool midFrame() const override { return m_on && !m_abOff; }
    void late(DrawPacket& p) override
    {
        if (!m_on || m_abOff || p.viewMode != 0)
            return;
        if (p.combinerKey && !strcmp(p.combinerKey, "c4.0.2a4.0.2r1"))
            m_modHash = p.combinerHash, m_modKnown = true;
        float view[3][4], inv[3][3], proj[16];
        bool cam = rm::frameCamera(view, inv, proj);
        if (cam)
            memcpy(m_roomProj, proj, sizeof m_roomProj), m_roomProjKnown = true;
        if (!cam && dumpOn(p.frame)) {
            const float* c = p.vertexConstants ? p.vertexConstants + 16 : nullptr;
            fprintf(m_dump, "pre f%u d%u pass%u vp%u lit%u bl%u dt%u dw%u tr%d q%d st%u vcc%u tex%u/%u hash%08x/%08x%s "
                    "c6 %g %g c7 %g %g room %g %g scene%d k%u\n", p.frame, p.drawIndex, p.pass, p.vertexProgram,
                    p.lighting, p.state.blend, p.state.depthTest, p.state.depthWrite, p.transient != kSinkNone,
                    p.query != kSinkNone, p.state.stencil, p.vertexConstantCount, p.stage[0].ordinal, p.stage[1].ordinal,
                    p.combinerHash, m_modHash, m_modKnown ? "" : "?", c ? c[10] : 0.f, c ? c[11] : 0.f, c ? c[14] : 0.f,
                    c ? c[15] : 0.f, m_roomProj[10], m_roomProj[11], rm::passIsScene(p.pass), p.shaderKind);
            auto it = m_bounds.find(p.bufferOwner);
            if (it != m_bounds.end() && p.vertexConstants) {
                const float* m = p.vertexConstants;
                float cc[3];
                for (int i = 0; i < 3; i++)
                    cc[i] = m[4 * i] * it->second.c[0] + m[4 * i + 1] * it->second.c[1] + m[4 * i + 2] * it->second.c[2] +
                            m[4 * i + 3];
                fprintf(m_dump, "   bounds r %.1f centre %.1f %.1f %.1f fog %u n%u dome %d\n", it->second.r, cc[0], cc[1],
                        cc[2], p.fog, p.vertexCount, isDome(p));
            }
            fflush(m_dump);
        }
        if (!cam && isDome(p)) {                       // (before the frame's first room draw)
            uint16_t prog = rm::program("vs_px_ff", "fs_rm_sky");
            if (prog != rm::kNoHandle) {
                p.pipeline = prog;
                p.state.depthWrite = 0;                 // (its pixels stay at the far plane: the air leaves them alone)
                m_domeProg = prog;
                m_domes++;
            }
        }
        keyLight(p, cam ? inv : nullptr);
        if (cam && p.vertexProgram == 0 && !p.lighting && !p.state.blend && p.state.depthWrite &&
            (p.shaderKind == 1 || p.shaderKind == 2) && p.transient == kSinkNone && p.vertexConstants &&
            p.vertexConstantCount >= 4 && sameView(p.vertexConstants, view)) {
            auto it = m_minY.find(p.bufferOwner);
            if (it != m_minY.end() && m_grounds.size() < 512)
                m_grounds.push_back(it->second);
        }
    }
    void draw(const DrawPacket& p) override
    {
        if (!m_on || m_abOff)
            return;
        if (m_domeProg != rm::kNoHandle && p.pipeline == m_domeProg) {
            skyUniforms(p);
            return;
        }
        // the air: in the world's pass, once its opaque draws are done, at its first translucent / stencil / 2D draw
        if (m_done || (p.viewMode != 0 && !m_opaque))
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
        if (!p.state.blend && p.state.depthWrite && p.viewMode == 0 && !p.state.stencil) {
            m_opaque = true;
            return;
        }
        if (m_opaque && (p.viewMode != 0 || p.state.stencil || (p.state.blend && !p.state.depthWrite)))
            run(-1);
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
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (!d.count || !d.vertices || !d.owner || d.count < 16)
            return;
        float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
        for (uint32_t i = 0; i < d.count; i++)
            for (int k = 0; k < 3; k++)
                lo[k] = fminf(lo[k], d.vertices[i].pos[k]), hi[k] = fmaxf(hi[k], d.vertices[i].pos[k]);
        m_minY[d.owner] = lo[1];
        Bounds b;
        float r2 = 0;
        for (int k = 0; k < 3; k++)
            b.c[k] = 0.5f * (lo[k] + hi[k]), r2 += 0.25f * (hi[k] - lo[k]) * (hi[k] - lo[k]);
        b.r = sqrtf(r2);
        m_bounds[d.owner] = b;
        m_ownerOf[sinkBuffer] = d.owner;
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        auto it = m_ownerOf.find(sinkBuffer);
        if (it != m_ownerOf.end()) {
            m_minY.erase(it->second);
            m_bounds.erase(it->second);
            m_ownerOf.erase(it);
        }
    }
    void frame() override
    {
        abCost();
        // the ground: the most common lowest point of the rooms drawn (streets and the buildings' feet)
        if (!m_grounds.empty()) {
            std::sort(m_grounds.begin(), m_grounds.end());
            float g = m_grounds[m_grounds.size() / 4];
            m_ground = m_groundKnown ? m_ground + 0.1f * (g - m_ground) : g;
            m_groundKnown = true;
        }
        m_grounds.clear();
        if (envInt("HULK_ATMOS_LOG") > 0 && ++m_frames >= 300) {
            fprintf(stderr, "hulk-app: atmosphere: %.2f sky draws, %u air runs in 300 frames; ground %.1f, camera "
                    "height %.1f, night %.2f, key %s %.2f %.2f %.2f\n", m_domes / 300.0, m_runs, m_ground, m_camHeight,
                    rm::nightAmount(), m_keyKnown ? "on" : "off", m_key[0], m_key[1], m_key[2]);
            m_frames = 0, m_domes = 0, m_runs = 0;
        }
        m_done = m_opaque = m_worldKnown = false;
    }

  private:
    // the sky dome (see the top): before the frame's first room draw, opaque, unlit, one stage modulated by the vertex
    // colour, a projection whose near and far differ from the rooms'
    bool isDome(const DrawPacket& p) const
    {
        if (p.vertexProgram != 0 || p.lighting || p.state.blend || !p.state.depthTest || p.transient != kSinkNone ||
            p.query != kSinkNone || p.state.stencil || !p.vertexConstants || p.vertexConstantCount < 56 ||
            p.stage[0].texture == kSinkNone || p.stage[1].texture != kSinkNone || !m_roomProjKnown ||
            (m_modKnown && p.combinerHash != m_modHash) || !rm::passIsScene(p.pass))
            return false;
        if (p.shaderKind != 0)
            return false;                               // (rooms are kinds 1 and 2)
        // a mesh around the camera: its bounds' centre, in camera space, well inside its radius
        auto it = m_bounds.find(p.bufferOwner);
        if (it == m_bounds.end())
            return false;
        const float* c = p.vertexConstants;
        const float* b = it->second.c;
        float cc[3], s2 = 0;
        for (int i = 0; i < 3; i++) {
            cc[i] = c[4 * i] * b[0] + c[4 * i + 1] * b[1] + c[4 * i + 2] * b[2] + c[4 * i + 3];
            s2 = fmaxf(s2, c[4 * i] * c[4 * i] + c[4 * i + 1] * c[4 * i + 1] + c[4 * i + 2] * c[4 * i + 2]);
        }
        float r = it->second.r * sqrtf(s2);
        // (play3: the desert's two dome layers r 2,531 / 2,048 units, their centres 0.2 / 0.09 r from the camera; the
        // canyon backdrop drawn next, r 568 with 5,047 vertices, is scenery)
        return r > 800.0f && p.vertexCount <= 1024 && cc[0] * cc[0] + cc[1] * cc[1] + cc[2] * cc[2] < 0.09f * r * r;
    }
    static bool sameView(const float* c, const float v[3][4])
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                if (fabsf(c[4 * i + j] - v[i][j]) > 1e-3f * (1.0f + fabsf(v[i][j])))
                    return false;
        return true;
    }
    // the location's key light (the strongest directional light of the lit draws), into world space
    void keyLight(const DrawPacket& p, const float (*inv)[3])
    {
        if (!p.lighting || !p.lights || !inv)
            return;
        float best = 0;
        const SinkLight* k = nullptr;
        for (int i = 0; i < 8; i++) {
            const SinkLight& l = p.lights[i];
            float s = l.diffuse[0] + l.diffuse[1] + l.diffuse[2];
            if (l.on && l.type == 3 && s > best)
                best = s, k = &l;
        }
        if (!k)
            return;
        float t[3] = {-k->direction[0], -k->direction[1], -k->direction[2]}, w[3];
        for (int i = 0; i < 3; i++)
            w[i] = inv[i][0] * t[0] + inv[i][1] * t[1] + inv[i][2] * t[2];
        float l = sqrtf(w[0] * w[0] + w[1] * w[1] + w[2] * w[2]);
        if (l < 1e-6f)
            return;
        for (int i = 0; i < 3; i++)
            m_key[i] = m_keyKnown ? m_key[i] + 0.05f * (w[i] / l - m_key[i]) : w[i] / l;
        m_keyKnown = true;
    }
    // HULK_ATMOS_DUMP=a:b[:path] (development): the draws before each frame's first room draw, presented frames a..b
    bool dumpOn(uint32_t frame)
    {
        static int state = -1;
        static uint32_t a, b;
        if (state < 0) {
            state = 0;
            if (const char* e = getenv("HULK_ATMOS_DUMP")) {
                char path[512] = "atmos-dump.txt";
                if (sscanf(e, "%u:%u:%511s", &a, &b, path) >= 2 && (m_dump = fopen(path, "w")))
                    state = 1;
            }
        }
        return state > 0 && frame >= a && frame <= b;
    }
    FILE* m_dump = nullptr;
    void skyUniforms(const DrawPacket& p)
    {
        float m[3][4], inv[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                m[i][j] = p.vertexConstants[4 * i + j];
        if (!inverse3(m, inv))
            return;
        float night = rm::nightAmount();
        static auto t0 = std::chrono::steady_clock::now();
        float secs = std::chrono::duration<float>(std::chrono::steady_clock::now() - t0).count();
        float u[6][4] = {
            {inv[0][0], inv[0][1], inv[0][2], 0},
            {inv[1][0], inv[1][1], inv[1][2], 0},
            {inv[2][0], inv[2][1], inv[2][2], 0},
            {night, fmodf(secs, 1000.0f), m_sky, m_stars},
            {m_key[0], m_key[1], m_key[2], m_keyKnown ? 1.0f : 0.0f},
            {0, 0, 0, m_horizon},
        };
        cityGlow(u[5]);
        rm::uniform("u_rmSky", &u[0][0], 6);
    }
    // the city's glow at night: sodium and white light scattered from below, tinted by the location's fog
    void cityGlow(float* o) const
    {
        float fog[3] = {0.05f, 0.07f, 0.09f};
        rm::nightFogColour(fog);
        o[0] = 0.30f + 0.3f * fog[0], o[1] = 0.17f + 0.3f * fog[1], o[2] = 0.08f + 0.3f * fog[2];
    }
    void run(int gamePass)
    {
        m_done = true;
        float view[3][4], inv[3][3], P[16];
        if (!rm::frameCamera(view, inv, P))
            return;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || depth == kSinkNone || !w || !h)
            return;
        uint16_t prog = rm::program("vs_rm_quad", "fs_rm_atmos");
        if (prog == rm::kNoHandle)
            return;
        if (m_colourOf != colour || m_fb == rm::kNoHandle) {
            if (m_fb != rm::kNoHandle)
                bgfx::destroy(bgfx::FrameBufferHandle{m_fb});
            bgfx::TextureHandle t{(uint16_t)colour};
            bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(1, &t, false);
            m_fb = bgfx::isValid(f) ? f.idx : rm::kNoHandle;
            m_colourOf = colour;
            if (m_fb == rm::kNoHandle)
                return;
        }
        uint16_t v;
        if (!(gamePass < 0 ? rm::viewsHere(1, &v) : rm::viewsBefore((uint16_t)gamePass, 1, &v)))
            return;
        // the camera's height above the ground estimate (world y; the camera at -inv x t)
        float camY = -(inv[1][0] * view[0][3] + inv[1][1] * view[1][3] + inv[1][2] * view[2][3]);
        m_camHeight = m_groundKnown ? fminf(400.0f, fmaxf(0.5f, camY - m_ground)) : 20.0f;
        float up[3] = {view[0][1], view[1][1], view[2][1]};
        float ul = sqrtf(up[0] * up[0] + up[1] * up[1] + up[2] * up[2]);
        for (float& x : up)
            x = ul > 0 ? x / ul : 0;
        float night = rm::nightAmount();
        int fogRow = rm::fogSetting();
        float fogScale = fogRow == 0 ? 1.0f : fogRow == 1 ? 0.5f : 0.0f;
        float fog[3] = {0.4f, 0.45f, 0.5f};
        rm::nightFogColour(fog);
        float glow[4];
        cityGlow(glow);
        float fc[3];
        for (int k = 0; k < 3; k++)                     // (night: the game's fog darkened, warmed by the city)
            fc[k] = fog[k] * (1.0f - 0.6f * night) + night * 0.35f * glow[k];
        // towards the key light in camera space
        float key[3] = {0, 0, 0};
        if (m_keyKnown)
            for (int i = 0; i < 3; i++)
                key[i] = view[i][0] * m_key[0] + view[i][1] * m_key[1] + view[i][2] * m_key[2];
        float density = (night * m_fogNight + (1.0f - night) * m_fogDay) * fogScale;
        float u[7][4] = {
            {P[0], P[5], P[2], P[6]},
            {P[10], P[11], P[14], P[15]},
            {P[3], P[7], m_camHeight, density},
            {up[0], up[1], up[2], m_falloff},
            {fc[0], fc[1], fc[2], m_aerial * fogScale},
            {key[0], key[1], key[2], m_keyKnown ? (night > 0.5f ? 0.25f : 0.6f) : 0.0f},
            {m_lamps * (fogRow == 2 ? 0.5f : 1.0f), 400.0f, 6.0f, 600.0f},
        };
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        rm::viewInto(v, m_fb, w, h);
        rm::texture(0, (uint16_t)depth, point);
        rm::uniform("u_rmAtm", &u[0][0], 7);
        if (!rm::nightLightsBindPost(5))
            noLights();
        rm::quad(v, prog, BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_ONE, BGFX_STATE_BLEND_SRC_ALPHA));
        m_runs++;
    }
    // the program declares the night lights' texture: an empty list when there are none
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
    // HULK_ATMOS_AB=N: the pass off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = envInt("HULK_ATMOS_AB");
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
                fprintf(stderr, "hulk-app: atmosphere cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1], m_abCpu[0] / m_abN[0],
                        m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1], st ? (unsigned)st->width : 0,
                        st ? (unsigned)st->height : 0);
        }
    }

    int m_on = 0;
    bool m_done = false, m_opaque = false, m_worldKnown = false, m_modKnown = false, m_roomProjKnown = false;
    bool m_keyKnown = false, m_groundKnown = false;
    uint16_t m_worldPass = 0, m_domeProg = rm::kNoHandle, m_fb = rm::kNoHandle, m_empty = rm::kNoHandle;
    uint16_t m_sCity = rm::kNoHandle, m_uCity = rm::kNoHandle;
    uint32_t m_modHash = 0, m_colourOf = kSinkNone;
    float m_roomProj[16] = {}, m_key[3] = {0, 1, 0}, m_ground = 0, m_camHeight = 20;
    float m_sky = 1.0f, m_stars = 1.0f, m_horizon = 0.5f, m_fogNight = 0.004f, m_fogDay = 0.003f, m_falloff = 0.04f;
    float m_aerial = 0.0006f, m_lamps = 0.016f;
    struct Bounds {
        float c[3], r;
    };
    std::unordered_map<uint32_t, Bounds> m_bounds;     // big prim buffers' bounding spheres (model space)
    std::unordered_map<uint32_t, float> m_minY;        // big prim buffers' lowest point (model space = world for rooms)
    std::unordered_map<uint32_t, uint32_t> m_ownerOf;
    std::vector<float> m_grounds;
    unsigned m_frames = 0, m_domes = 0, m_runs = 0;
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};
};
HULK_RM_REGISTER_PASS(AtmospherePass);

} // namespace
