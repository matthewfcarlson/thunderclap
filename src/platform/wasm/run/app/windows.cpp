// Window interiors (wlook0, docs/look.md "Interior mapping"): the app's Windows option (Original / Interiors).
//
// The game's buildings are drawn with the layeredReflect shader (ShaderKind kShaderBuilding): stage 0 is the facade,
// whose alpha is 0 exactly on the window glass, and stages 1 and 2 are reflection maps the combiner adds where that
// alpha is low (c4.0.2a2.2.0r1 | c20.1.2a2.1.0r1 | c20.1.2a2.1.0r1: diffuse x facade, then + reflection x (1 - alpha)
// twice). So the windows are in the game's own data, texel-exact: no mask pack is needed.
//
// Each such draw is drawn again right after itself as a decal (the same packet: buffers, constants, textures, with a
// program of the runner's, depth test less-equal with a small bias towards the camera, no depth or alpha writes,
// blended by the glass mask): fs_rm_window.sc ray-casts a room per texture tile (a window bay) behind the glass and puts
// the game's reflection over it by Fresnel. The decal is submitted from the next hook the runner reaches (the next
// draw, pass, copy, effect or the frame's end) into the view the building was drawn in, before any other pass sets
// state for that next draw (order 3: before the shadows' casters and the lighting pass's uniforms).
// Output only: nothing here reads or writes the module's memory.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unordered_map>
#include <utility>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

namespace {

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_WINDOWS_LOG") && atoi(getenv("HULK_WINDOWS_LOG")) > 0;
    return on;
}

class WindowsPass final : public rm::Pass {
  public:
    const char* name() const override { return "windows"; }
    int order() const override { return 3; }
    void settingsChanged(const rm::Settings& s) override
    {
        if (s[rm::kWindows] != m_mode)
            fprintf(stderr, "hulk-app: windows %s\n", s[rm::kWindows] ? "interiors" : "original");
        m_mode = s[rm::kWindows];
        // HULK_WINDOWS=depth,F0,reflection,lamp,nightBias,mask,dayLit,nightLit (development tuning)
        if (const char* e = getenv("HULK_WINDOWS"))
            sscanf(e, "%f,%f,%f,%f,%f,%f,%f,%f", &m_k[1][0], &m_k[1][1], &m_k[1][2], &m_k[1][3], &m_k[2][0],
                   &m_k[2][1], &m_k[2][2], &m_k[2][3]);
    }
    void draw(const DrawPacket& p) override
    {
        flush();
        if (!m_mode || m_abOff || !candidate(p))
            return;
        keep(p);
    }
    void passSet(uint16_t, const SinkPass&) override { flush(); }
    void copy(uint16_t, const SinkTarget&) override { flush(); }
    void fx(const FxPacket&) override { flush(); }
    void postScene(const rm::Scene&, uint16_t&) override { flush(); }
    // a per-building seed from each prim buffer's centre (world space for rooms): stable across loads of the room
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (!d.count || !d.vertices || !d.owner)
            return;
        double c[3] = {0, 0, 0};
        uint32_t n = d.count < 64 ? d.count : 64;
        for (uint32_t i = 0; i < n; i++)
            for (int k = 0; k < 3; k++)
                c[k] += d.vertices[i].pos[k] / n;
        float s = (float)fmod(fabs(floor(c[0] / 4) * 12.9898 + floor(c[1] / 4) * 4.1414 + floor(c[2] / 4) * 78.233),
                              97.0);
        m_seed[d.owner] = s;
        float lo = 1e30f, hi = -1e30f;                  // (wlook1: the buffer's height range: the building's foot)
        for (uint32_t i = 0; i < d.count; i++)
            lo = fminf(lo, d.vertices[i].pos[1]), hi = fmaxf(hi, d.vertices[i].pos[1]);
        m_height[d.owner] = {lo, hi};
        m_ownerOf[sinkBuffer] = d.owner;
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        auto it = m_ownerOf.find(sinkBuffer);
        if (it != m_ownerOf.end()) {
            m_seed.erase(it->second);
            m_height.erase(it->second);
            m_ownerOf.erase(it);
        }
    }
    void frame() override
    {
        abCost();
        // the street's height: the lowest building foot drawn, kept low for a while (a view of upper storeys only
        // must not take a tower's middle for the street)
        if (m_footMin < 1e29f) {
            if (m_ground > 1e29f || m_footMin < m_ground)
                m_ground = m_footMin;
            else
                m_ground += (m_footMin - m_ground) * 0.002f;
        }
        m_footMin = 1e30f;
        if (logOn() && ++m_frames == 300) {
            fprintf(stderr, "hulk-app: windows: %.1f building draws a frame drawn again with interiors\n",
                    m_drawn / 300.0);
            m_frames = 0, m_drawn = 0;
        }
    }

  private:
    // a building draw of the world: layeredReflect, its faithful combiner (the facade's alpha marks the glass),
    // opaque, perspective, a prim buffer, not counted by a query
    bool candidate(const DrawPacket& p) const
    {
        if (p.shaderKind != 2 || p.viewMode != 0 || p.query != kSinkNone || p.transient != kSinkNone ||
            p.state.blend || !p.state.depthTest || !p.state.depthWrite || p.state.stencil ||
            (p.vertexProgram != 0 && p.vertexProgram != 6) || p.lighting || p.stage[0].texture == kSinkNone ||
            !p.vertexConstants || p.vertexConstantCount < 4 || !p.combinerKey)
            return false;
        return !strncmp(p.combinerKey, "c4.0.2a2.2.0r1|c20.1.2a2.1.0r1", 30);
    }
    void keep(const DrawPacket& p)
    {
        m_q = p;
        uint32_t n = p.vertexConstantCount < 96 ? p.vertexConstantCount : 96;
        memcpy(m_vc, p.vertexConstants, n * 16);
        m_q.vertexConstants = &m_vc[0][0];
        m_q.vertexConstantCount = n;
        if (p.lights) {
            memcpy(m_lights, p.lights, sizeof m_lights);
            m_q.lights = m_lights;
        }
        const float* mats[3] = {p.modelview, p.projection, p.view};
        const float** outs[3] = {&m_q.modelview, &m_q.projection, &m_q.view};
        for (int i = 0; i < 3; i++)
            if (mats[i]) {
                memcpy(m_mats[i], mats[i], sizeof m_mats[i]);
                *outs[i] = m_mats[i];
            }
        m_q.combinerKey = "";
        m_q.programName = "";
        m_pending = true;
    }
    void flush()
    {
        if (!m_pending)
            return;
        m_pending = false;
        uint16_t prog = rm::program("vs_rm_window", "fs_rm_window");
        if (prog == rm::kNoHandle)
            return;
        // the world's up in camera space: the modelview's second column (rooms: the view itself)
        const float* c = m_q.vertexConstants;
        float up[3] = {c[1], c[5], c[9]};
        float l = sqrtf(up[0] * up[0] + up[1] * up[1] + up[2] * up[2]);
        if (l < 1e-6f)
            return;
        auto it = m_seed.find(m_q.bufferOwner);
        m_k[0][0] = up[0] / l, m_k[0][1] = up[1] / l, m_k[0][2] = up[2] / l;
        m_k[0][3] = it != m_seed.end() ? it->second : (float)(m_q.bufferOwner % 97);
        auto ht = m_height.find(m_q.bufferOwner);
        m_k[3][0] = ht != m_height.end() ? ht->second.first : 0.0f;
        m_k[3][1] = ht != m_height.end() ? ht->second.second : 0.0f;   // (equal: no foot known)
        if (ht != m_height.end())
            m_footMin = fminf(m_footMin, ht->second.first);
        m_k[3][2] = m_ground < 1e29f ? m_ground : -1e30f;      // (none yet: the foot alone)
        rm::uniform("u_rmWin", &m_k[0][0], 4);
        m_q.pipeline = prog;
        m_q.query = kSinkNone;
        m_q.state.depthTest = 1;
        m_q.state.depthFunc = 3;                  // (less-equal: the decal's vertex shader is biased towards the camera)
        m_q.state.depthWrite = 0;
        m_q.state.blend = 1;
        m_q.state.blendOp = kBlendAdd;
        m_q.state.srcBlend = kBlendSrcAlpha;
        m_q.state.dstBlend = kBlendInvSrcAlpha;
        m_q.state.writeMask = 7;                  // (colour only: the scene's alpha stays the game's)
        hulk_gfx_sink_submit_draw(&m_q);
        m_drawn++;
    }
    // HULK_WINDOWS_AB=N: the interiors off and on in turns of N presented frames (GPU and render thread a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_WINDOWS_AB") ? atoi(getenv("HULK_WINDOWS_AB")) : 0;
        if (n <= 0)
            return;
        const bgfx::Stats* st = bgfx::getStats();
        if (st && m_abFrame > 2 && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin) {
            int k = m_abOff ? 0 : 1;
            m_abGpu[k] += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq;
            m_abCpu[k] += 1e3 * (double)(st->cpuTimeEnd - st->cpuTimeBegin) / (double)st->cpuTimerFreq;
            m_abN[k]++;
        }
        if (++m_abFrame >= n) {
            m_abFrame = 0;
            m_abOff = !m_abOff;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: windows cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1], m_abCpu[0] / m_abN[0],
                        m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1]);
        }
    }
    int m_mode = 0;
    bool m_pending = false;
    DrawPacket m_q;
    float m_vc[96][4];
    SinkLight m_lights[8];
    float m_mats[3][16];
    // u_rmWin (fs_rm_window.sc): [0] up + seed (per draw); [1] depth, F0, reflection, lamp; [2] night bias, mask view,
    // share of rooms lit by day, at night beyond the game's lit panes
    // [3] the prim buffer's height range, the street's height (wlook1: shops and lobbies on the first storey)
    float m_k[4][4] = {{0, 1, 0, 0}, {0.9f, 0.12f, 1.0f, 0.8f}, {0.0f, 0.0f, 0.12f, 0.2f}, {0, 0, 0, 0}};
    std::unordered_map<uint32_t, float> m_seed;        // prim buffer owner -> seed
    std::unordered_map<uint32_t, std::pair<float, float>> m_height;   // prim buffer owner -> lowest, highest y
    float m_footMin = 1e30f, m_ground = 1e30f;
    std::unordered_map<uint32_t, uint32_t> m_ownerOf;  // sink vertex buffer -> owner
    unsigned m_frames = 0;
    double m_drawn = 0;
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};
};
HULK_RM_REGISTER_PASS(WindowsPass);

} // namespace
