// The app's lighting passes (wlight1, docs/lighting.md): per-pixel lighting of the game's lit draws, and dynamic
// lights from glowing pickups (health orbs) that light the draws around them, the baked world included.
//
// Both are runner passes (rm_pass.h): a draw keeps its packet, constants, textures and state; only its program is
// swapped for a per-pixel one from run/app/shaders (tools/rm_shaders.py), whose fragment shader evaluates the lights the
// faithful vertex shader would, per pixel, and then runs the faithful texture-stage combiner. Output only: nothing
// here reads or writes the module's memory, and a draw the game counts pixels of (an occlusion query) is never
// changed.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include <bgfx/bgfx.h>

#include "rm_pass.h"
#if __has_include("rm_shaders.h")
#include "rm_shaders.h"         // (tools/rm_shaders.py: wasm_app.py build; an Android build passes its profiles)
#else
struct RmEmbeddedShader { const char* name; const char* profile; const unsigned char* data; unsigned size; };
static const RmEmbeddedShader g_rm_shaders[] = {{0, 0, 0, 0}};     // (no shaders: the passes stay off)
#endif
#include "nightlights.h"
#include "shadows.h"
#include "texpack.h"

using namespace hulk::pddi;

namespace {

const uint16_t kInvalid = 0xffff;

const char* profile()
{
    switch (bgfx::getRendererType()) {
    case bgfx::RendererType::Vulkan: return "spirv";
    case bgfx::RendererType::Metal: return "metal";
    case bgfx::RendererType::OpenGLES: return "essl";
    default: return "";
    }
}

// the runner's programs: one per (vertex program, combiner) pair, the shaders made once
class Programs {
  public:
    // vp: 0 fixed function, 1 skin, 2 skin_onebone, 6 fixed function two-sided (generic only); hash 0: the generic
    // combiner
    uint16_t get(uint32_t vp, uint32_t hash)
    {
        if (vp == 6)
            hash = 0;
        uint64_t key = (uint64_t)vp << 32 | hash;
        auto it = m_progs.find(key);
        if (it != m_progs.end())
            return it->second;
        uint16_t prog = kInvalid;
        uint16_t vs = shader(vp == 1 ? "vs_px_skin" : vp == 2 ? "vs_px_skin_onebone" : "vs_px_ff");
        char name[32] = "fs_px_stage";
        if (vp == 6)
            snprintf(name, sizeof name, "fs_px_stage2s");
        else if (hash)
            snprintf(name, sizeof name, "fs_pxcmb_%08x", hash);
        uint16_t fs = shader(name);
        if (vs != kInvalid && fs != kInvalid) {
            bgfx::ProgramHandle h = bgfx::createProgram(bgfx::ShaderHandle{vs}, bgfx::ShaderHandle{fs}, false);
            if (bgfx::isValid(h))
                prog = h.idx;
        }
        m_progs[key] = prog;
        if (prog != kInvalid)
            m_mine[prog] = (uint8_t)(vp + 1);
        return prog;
    }
    // the vertex program + 1 of a program of ours, else 0
    uint8_t ours(uint32_t pipeline) const
    {
        auto it = m_mine.find(pipeline);
        return it == m_mine.end() ? 0 : it->second;
    }

  private:
    uint16_t shader(const char* name)
    {
        auto it = m_shaders.find(name);
        if (it != m_shaders.end())
            return it->second;
        uint16_t h = kInvalid;
        const char* prof = profile();
        for (const RmEmbeddedShader* s = g_rm_shaders; s->name; s++)
            if (!strcmp(s->name, name) && !strcmp(s->profile, prof)) {
                bgfx::ShaderHandle sh = bgfx::createShader(bgfx::makeRef(s->data, s->size));
                if (bgfx::isValid(sh))
                    h = sh.idx;
                break;
            }
        m_shaders[name] = h;
        return h;
    }
    std::unordered_map<std::string, uint16_t> m_shaders;
    std::unordered_map<uint64_t, uint16_t> m_progs;
    std::unordered_map<uint32_t, uint8_t> m_mine;
};

// HULK_LIGHT_LOG=1: what the passes do, every 300 presented frames
int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_LIGHT_LOG") && atoi(getenv("HULK_LIGHT_LOG")) > 0;
    return on;
}

// HULK_LIGHT_TRACE=a:b (development, wpol1): one line a presented frame for presents a..b: the frame's lights
int traceOn(unsigned present)
{
    static long a = -2, b = -1;
    if (a == -2) {
        a = -1;
        if (const char* e = getenv("HULK_LIGHT_TRACE"))
            sscanf(e, "%ld:%ld", &a, &b);
    }
    return a >= 0 && (long)present >= a && (long)present <= b;
}

class LightingPass final : public rm::Pass {
  public:
    const char* name() const override { return "lighting"; }
    int order() const override { return 10; }
    void settingsChanged(const rm::Settings& s) override
    {
        if (const char* e = getenv("HULK_LIGHT_ORB"))            // (tuning: strength, radius)
            sscanf(e, "%f,%f", &m_dynStrength, &m_dynRadius);
        if (s[rm::kLighting] != m_perPixel || s[rm::kDynLights] != m_dynMode)
            fprintf(stderr, "hulk-app: lighting %s, dynamic lights %s\n", s[rm::kLighting] ? "per-pixel" : "original",
                    s[rm::kDynLights] ? "health orbs" : "off");
        m_perPixel = s[rm::kLighting];
        m_dynMode = s[rm::kDynLights];
    }
    void packet(DrawPacket& p) override
    {
        bool shadows = rm::shadowsOn();                 // (wr3a: every opaque draw receives the sun's shadows)
        if ((!m_perPixel && !m_dynMode && !shadows) || m_abOff)
            return;
        if (p.viewMode != 0 || p.query != kSinkNone || (p.vertexProgram > 2 && p.vertexProgram != 6) ||
            p.pipeline == kSinkNone)
            return;
        bool skin = p.vertexProgram == 1 || p.vertexProgram == 2;
        bool lit = skin || p.lighting;
        bool shadowed = shadows && !p.state.blend && p.state.depthWrite;
        if (lit ? !m_perPixel && !shadowed : !shadowed)
            return;
        ours(p);
    }
    // wpol1: the dynamic lights' part of the choice is made as the presented frame is drawn (with the lights placed
    // in it), never when an interpolated update's draws are recorded: then no frame's lights are known yet
    void late(DrawPacket& p) override
    {
        bool night = rm::nightLightsActive();            // (wlook2: the night lights reach draws like the orbs)
        if ((!m_dynMode && !night) || m_abOff)
            return;
        if (m_dynMode)
            dynamicDraw(p);
        if ((!m_dynCount && !night) || p.viewMode != 0 || p.query != kSinkNone || p.pipeline == kSinkNone || p.state.blend ||
            (p.vertexProgram != 0 && p.vertexProgram != 6) || m_progs.ours(p.pipeline))
            return;
        if (near(p))                                    // (an orb's light reaches the draw)
            ours(p);
    }
    void draw(const DrawPacket& p) override
    {
        uint8_t vp1 = m_progs.ours(p.pipeline);
        if (p.viewMode == 0 && !p.state.blend && p.query == kSinkNone) {
            m_tOpaque++;
            if (!m_haveView)
                m_tEarly++;
            if (vp1)
                m_tOurs++;
            if (vp1 && m_dynCount && rm::currentGamePass() == m_viewPass)
                m_tRecv++;
        }
        m_tFrame = p.frame;
        if (!vp1)
            return;
        // glows and other blended effects take no light, nor draws in another pass than the world's (the HUD's models)
        bool receives = m_dynCount && !p.state.blend && rm::currentGamePass() == m_viewPass;
        bool skin = vp1 == 2 || vp1 == 3;
        float px[4] = {skin ? 2.0f : p.lighting ? 1.0f : 0.0f, receives ? (float)m_dynCount : 0.0f, m_dynStrength,
                       0.0f};
        bgfx::setUniform(m_uPx, px);
        if (receives)
            bgfx::setUniform(m_uLight, m_dynCam, (uint16_t)(2 * m_dynCount));
        // wr3a: the sun's shadows (shadows.cpp); every program of ours declares the sampler, so one is always bound
        static const float kNoShadow[12][4] = {};
        uint16_t atlas = kInvalid;
        bool takesWorld = p.lighting || vp1 != 1 || p.shaderKind < 1 || p.shaderKind > 2;
        const float* sc = p.state.blend ? nullptr : rm::shadowConstants(takesWorld, &atlas);
        bgfx::setUniform(m_uShadow, sc ? sc : &kNoShadow[0][0], 12);
        rm::nightLightsBind(p);                         // (wlook2: every program of ours declares s_rmCity)
        if (atlas == kInvalid)
            atlas = rm::shadowDummy();
        if (atlas != kInvalid)
            bgfx::setTexture(4, m_sShadow, bgfx::TextureHandle{atlas},
                             BGFX_SAMPLER_COMPARE_LEQUAL | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
        m_draws++;
    }
    // prim buffers' bounding spheres (the draws near a light take the per-pixel program; the rest keep the faithful)
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (!d.count || !d.vertices || !d.owner)
            return;
        float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
        for (uint32_t i = 0; i < d.count; i++)
            for (int k = 0; k < 3; k++)
                lo[k] = fminf(lo[k], d.vertices[i].pos[k]), hi[k] = fmaxf(hi[k], d.vertices[i].pos[k]);
        Bounds b;
        float r2 = 0;
        for (int k = 0; k < 3; k++)
            b.c[k] = 0.5f * (lo[k] + hi[k]);
        for (uint32_t i = 0; i < d.count; i++) {
            float dx = d.vertices[i].pos[0] - b.c[0], dy = d.vertices[i].pos[1] - b.c[1],
                  dz = d.vertices[i].pos[2] - b.c[2];
            r2 = fmaxf(r2, dx * dx + dy * dy + dz * dz);
        }
        b.r = sqrtf(r2);
        m_bounds[d.owner] = b;
        m_ownerOf[sinkBuffer] = d.owner;
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        auto it = m_ownerOf.find(sinkBuffer);
        if (it != m_ownerOf.end()) {
            for (size_t i = 0; i < m_orbSigs.size();)
                if ((uint32_t)(m_orbSigs[i] >> 32) == it->second)
                    m_orbSigs[i] = m_orbSigs.back(), m_orbSigs.pop_back();
                else
                    i++;
            m_bounds.erase(it->second);
            m_ownerOf.erase(it);
        }
    }
    void postScene(const rm::Scene&, uint16_t&) override
    {
        // the frame's lights into world space by its view; applied from the next frame's view on
        m_world.clear();
        if (m_haveView)
            for (const Light& l : m_found) {
                Light w = l;
                for (int i = 0; i < 3; i++)
                    w.pos[i] = m_inv[i][0] * (l.pos[0] - m_view[0][3]) + m_inv[i][1] * (l.pos[1] - m_view[1][3]) +
                               m_inv[i][2] * (l.pos[2] - m_view[2][3]);
                m_world.push_back(w);
            }
        m_lightsMade += m_found.size(), m_framesSeen++;
        if (traceOn(m_present)) {
            fprintf(stderr, "LT p=%u f=%u view=%d@%u t=%.2f,%.2f,%.2f opaque=%u early=%u ours=%u recv=%u found=%zu dyn=%d",
                    m_present, m_tFrame, m_haveView ? 1 : 0, m_tViewIdx, m_view[0][3], m_view[1][3], m_view[2][3],
                    m_tOpaque, m_tEarly, m_tOurs, m_tRecv, m_found.size(), m_dynCount);
            for (size_t i = 0; i < m_found.size() && i < 6; i++)
                fprintf(stderr, " F%.2f,%.2f,%.2f", m_found[i].pos[0], m_found[i].pos[1], m_found[i].pos[2]);
            for (int k = 0; k < m_dynCount && k < 6; k++)
                fprintf(stderr, " D%.2f,%.2f,%.2f", m_dynCam[2 * k][0], m_dynCam[2 * k][1], m_dynCam[2 * k][2]);
            fprintf(stderr, "\n");
        }
        m_present++;
        m_tOpaque = m_tEarly = m_tOurs = m_tRecv = m_tViewIdx = 0;
        m_found.clear();
        m_haveView = m_placed = false;
        m_dynCount = 0;
    }
    void frame() override
    {
        abCost();
        if (logOn() && ++m_frames == 300) {
            fprintf(stderr, "hulk-app: lighting: %.1f per-pixel draws, %.2f dynamic lights a frame\n", m_draws / 300.0,
                    m_framesSeen ? m_lightsMade / m_framesSeen : 0.0);
            m_frames = 0, m_draws = 0, m_lightsMade = 0, m_framesSeen = 0;
        }
    }

  private:
    // HULK_LIGHT_AB=N (cost measurement): the passes off and on in turns of N presented frames, bgfx's GPU and render
    // thread time a frame summed for each, so both see the same load and scenes
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_LIGHT_AB") ? atoi(getenv("HULK_LIGHT_AB")) : 0;
        if (n <= 0)
            return;
        const bgfx::Stats* st = bgfx::getStats();
        if (st && m_abFrame > 2 && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin) {   // (settled turns)
            int k = m_abOff ? 0 : 1;
            m_abGpu[k] += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq;
            m_abCpu[k] += 1e3 * (double)(st->cpuTimeEnd - st->cpuTimeBegin) / (double)st->cpuTimerFreq;
            m_abN[k]++;
        }
        if (++m_abFrame >= n) {
            m_abFrame = 0;
            m_abOff = !m_abOff;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: lighting cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1], m_abCpu[0] / m_abN[0],
                        m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1], st ? (unsigned)st->width : 0,
                        st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};
    // the draw takes the runner's per-pixel program for its vertex program and combiner
    void ours(DrawPacket& p)
    {
        if (!m_up && !up())
            return;
        uint16_t prog = m_progs.get(p.vertexProgram, p.generic ? 0 : p.combinerHash);
        if (prog == kInvalid && !p.generic)
            prog = m_progs.get(p.vertexProgram, 0);
        if (prog != kInvalid)
            p.pipeline = prog;
    }
    bool up()
    {
        if (!*profile())
            return false;
        m_uPx = bgfx::createUniform("u_rmPx", bgfx::UniformType::Vec4);
        m_uLight = bgfx::createUniform("u_rmLight", bgfx::UniformType::Vec4, 16);
        m_uShadow = bgfx::createUniform("u_rmShadow", bgfx::UniformType::Vec4, 12);
        m_sShadow = bgfx::createUniform("s_rmShadow", bgfx::UniformType::Sampler);
        return m_up = true;
    }
    struct Light {
        float pos[3];
        float radius;
        float colour[4];
    };
    // the view matrix of the frame: a static world draw's modelview (the camera folded in, the world's own transform
    // the identity), as rows (camera = m_view x (world, 1)); its 3x3 inverse
    bool takeView(const DrawPacket& p)
    {
        if (p.vertexProgram != 0 || !p.vertexConstants || p.vertexConstantCount < 4 || p.transient != kSinkNone ||
            p.lighting || p.state.blend || !p.state.depthWrite || p.shaderKind < 1 || p.shaderKind > 2)
            return false;
        const float* c = p.vertexConstants;
        float m[3][4];                                  // (m_view keeps the last camera until this one is good)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                m[i][j] = c[4 * i + j];
        float det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                    m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        if (fabsf(det) < 1e-12f)
            return false;
        float id = 1.0f / det;
        m_inv[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * id;
        m_inv[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * id;
        m_inv[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * id;
        m_inv[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * id;
        m_inv[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * id;
        m_inv[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * id;
        m_inv[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * id;
        m_inv[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * id;
        m_inv[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * id;
        memcpy(m_view, m, sizeof m_view);
        return true;
    }
    void dynamicDraw(const DrawPacket& p)
    {
        if (p.viewMode != 0)
            return;
        if (!m_haveView && takeView(p)) {
            m_haveView = m_viewKnown = true;
            m_tViewIdx = p.drawIndex;
            m_viewPass = rm::currentGamePass();     // (the game's pass: the runner's views may split it, wr3a)
            place();                                // (the frame's own camera)
        } else if (!m_haveView && !m_placed && m_viewKnown) {
            place();                                // (the draws before the frame's first world draw: the last camera)
        }
        Light l;
        if (m_found.size() < 64 && glow(p, &l)) {
            for (const Light& f : m_found)             // (an orb is drawn twice, in two passes: one light)
                if (fabsf(f.pos[0] - l.pos[0]) + fabsf(f.pos[1] - l.pos[1]) + fabsf(f.pos[2] - l.pos[2]) < 0.5f)
                    return;
            m_found.push_back(l);
        }
    }
    // the last frame's lights into this frame's camera space (m_view), the nearest kMax
    void place()
    {
        m_placed = true;
        m_dynCount = 0;
        struct Near { float d2; const Light* l; };
        Near near[64];
        int n = 0;
        for (const Light& l : m_world) {
            if (n == 64)
                break;
            float c[3];
            for (int i = 0; i < 3; i++)
                c[i] = m_view[i][0] * l.pos[0] + m_view[i][1] * l.pos[1] + m_view[i][2] * l.pos[2] + m_view[i][3];
            near[n].d2 = c[0] * c[0] + c[1] * c[1] + c[2] * c[2];
            near[n].l = &l;
            n++;
        }
        std::sort(near, near + n, [](const Near& a, const Near& b) { return a.d2 < b.d2; });
        for (int k = 0; k < n && k < kMax; k++) {
            const Light& l = *near[k].l;
            float* o = m_dynCam[2 * k];
            for (int i = 0; i < 3; i++)
                o[i] = m_view[i][0] * l.pos[0] + m_view[i][1] * l.pos[1] + m_view[i][2] * l.pos[2] + m_view[i][3];
            o[3] = l.radius;
            memcpy(m_dynCam[2 * k + 1], l.colour, sizeof l.colour);
            m_dynCount++;
        }
    }
    // a fixed-function buffer draw whose bounding sphere (by its modelview) meets one of this frame's lights
    bool near(const DrawPacket& p) const
    {
        if (p.transient != kSinkNone || !p.vertexConstants || p.vertexConstantCount < 4 ||
            (p.vertexProgram != 0 && p.vertexProgram != 6))
            return false;
        auto it = m_bounds.find(p.bufferOwner);
        if (it == m_bounds.end())
            return false;
        const float* c = p.vertexConstants;
        const Bounds& b = it->second;
        float cc[3], s2 = 0;
        for (int i = 0; i < 3; i++) {
            cc[i] = c[4 * i] * b.c[0] + c[4 * i + 1] * b.c[1] + c[4 * i + 2] * b.c[2] + c[4 * i + 3];
            for (int j = 0; j < 3; j++)
                s2 = fmaxf(s2, c[4 * i + j] * c[4 * i + j]);
        }
        float r = b.r * sqrtf(3.0f * s2);              // (a bound on the modelview's scale)
        if (rm::nightLightsTouch(cc, r))
            return true;
        for (int k = 0; k < m_dynCount; k++) {
            const float* l = m_dynCam[2 * k];
            float dx = l[0] - cc[0], dy = l[1] - cc[1], dz = l[2] - cc[2], rr = r + l[3];
            if (dx * dx + dy * dy + dz * dz < rr * rr)
                return true;
        }
        return false;
    }
    struct Bounds {
        float c[3], r;
    };
    std::unordered_map<uint32_t, Bounds> m_bounds;     // prim buffer owner -> bounding sphere (model space)
    std::unordered_map<uint32_t, uint32_t> m_ownerOf;  // sink vertex buffer -> owner
    // a health orb's draw (docs/lighting.md "Finding them"): its light, camera space
    bool glow(const DrawPacket& p, Light* l);
    enum { kMax = 8 };
    bool m_haveView = false, m_viewKnown = false, m_placed = false;
    uint16_t m_viewPass = 0;
    // orb meshes known by their prim buffer and texture (wpol1): the sprite + mesh pair names them once; the game sorts
    // its blended draws back to front, so the pair is adjacent in some frames only and the mesh alone counts after
    std::vector<uint64_t> m_orbSigs;
    struct PendingMesh {
        bool on;
        uint32_t texture;
        uint64_t sig;
        float pos[3];
    } m_mesh = {};                          // an unknown orb-like mesh drawn just before (its sprite may follow)
    void learn(uint64_t sig);
    void orb(const float pos[3], Light* l, uint32_t frame);
    float m_view[3][4], m_inv[3][3];
    std::vector<Light> m_found, m_world;
    float m_dynCam[2 * kMax][4];
    int m_dynCount = 0;
    float m_dynStrength = 1.0f, m_dynRadius = 8.0f;
    uint32_t m_sprite = kSinkNone;          // the texture of an orb's sprite drawn just before (glow)
    double m_lightsMade = 0, m_framesSeen = 0;
    Programs m_progs;
    bool m_up = false;
    int m_perPixel = 0, m_dynMode = 0;
    bgfx::UniformHandle m_uPx = BGFX_INVALID_HANDLE, m_uLight = BGFX_INVALID_HANDLE;
    bgfx::UniformHandle m_uShadow = BGFX_INVALID_HANDLE, m_sShadow = BGFX_INVALID_HANDLE;
    unsigned m_frames = 0;
    double m_draws = 0;
    unsigned m_present = 0, m_tFrame = 0, m_tOpaque = 0, m_tEarly = 0, m_tOurs = 0, m_tRecv = 0, m_tViewIdx = 0;
};
HULK_RM_REGISTER_PASS(LightingPass);

// A health orb is drawn as a pair: a camera-facing sprite (6 transient vertices, its corners already in camera space)
// then a small mesh (14 vertices, no vertex colours) with the same texture, both additive (one, one), unlit and fixed
// function; the mesh's modelview puts it at the orb. (Found in play3's tutorial and city draws; the mesh's content key
// differs between locations, the pair's shape does not.) The orb's colour is the health orbs' green: the textures
// are grey and the draws carry no colour of their own (docs/lighting.md "Finding them"). The game sorts its blended
// draws back to front, so the two are adjacent only in some frames, in either order (wpol1): an adjacent pair names
// the mesh (its prim buffer and texture), and a named mesh is an orb by itself from then on.
bool LightingPass::glow(const DrawPacket& p, Light* l)
{
    bool additive = p.state.blend && p.state.srcBlend == kBlendOne && p.state.dstBlend == kBlendOne &&
                    p.state.blendOp == kBlendAdd && p.vertexProgram == 0 && !p.lighting && p.viewMode == 0;
    uint32_t sprite = m_sprite;
    m_sprite = kSinkNone;
    PendingMesh mesh = m_mesh;
    m_mesh.on = false;
    if (!additive)
        return false;
    if (p.transient != kSinkNone) {
        if (p.vertexCount != 6)
            return false;
        m_sprite = p.stage[0].texture;
        if (mesh.on && mesh.texture == p.stage[0].texture) {      // (the pair the other way round: mesh, sprite)
            learn(mesh.sig);
            orb(mesh.pos, l, p.frame);
            return true;
        }
        return false;
    }
    if (p.vertexCount != 14 || !p.vertexConstants || p.vertexConstantCount < 4)
        return false;
    const float* c = p.vertexConstants;
    float pos[3] = {c[3], c[7], c[11]};
    uint64_t sig = (uint64_t)p.bufferOwner << 32 | p.stage[0].texture;
    bool known = std::find(m_orbSigs.begin(), m_orbSigs.end(), sig) != m_orbSigs.end();
    if (!known) {
        if (sprite == kSinkNone || sprite != p.stage[0].texture) {  // (perhaps a pair's first: its sprite next)
            m_mesh.on = true, m_mesh.texture = p.stage[0].texture, m_mesh.sig = sig;
            memcpy(m_mesh.pos, pos, sizeof pos);
            return false;
        }
        learn(sig);
    }
    orb(pos, l, p.frame);
    return true;
}

void LightingPass::learn(uint64_t sig)
{
    if (m_orbSigs.size() < 64 && std::find(m_orbSigs.begin(), m_orbSigs.end(), sig) == m_orbSigs.end())
        m_orbSigs.push_back(sig);
}

// the orb's light: at the mesh's translation (camera space), the health orbs' green
void LightingPass::orb(const float pos[3], Light* l, uint32_t frame)
{
    memcpy(l->pos, pos, sizeof l->pos);
    l->radius = m_dynRadius;
    static int logged;
    if (logOn() && logged < 40 && (frame % 50) == 0)
        logged++, fprintf(stderr, "hulk-app: lighting: orb f%u at %.2f %.2f %.2f\n", frame, pos[0], pos[1], pos[2]);
    l->colour[0] = 0.45f, l->colour[1] = 1.0f, l->colour[2] = 0.3f, l->colour[3] = 1.0f;
}

// HULK_LIGHT_DUMP=a:b[:path]: every draw of presented frames a..b, one line each (identification of glow draws)
class LightDump final : public rm::Pass {
  public:
    const char* name() const override { return "lightdump"; }
    int order() const override { return 100; }
    void open()
    {
        m_on = 0;
        if (const char* e = getenv("HULK_LIGHT_DUMP")) {
            char path[512] = "light-dump.txt";
            if (sscanf(e, "%u:%u:%511s", &m_a, &m_b, path) >= 2) {
                m_f = fopen(path, "w");
                m_on = m_f != nullptr;
            }
        }
    }
    void draw(const DrawPacket& p) override
    {
        if (m_on < 0)
            open();
        m_inFrame = m_on > 0 && p.frame >= m_a && p.frame <= m_b;
        if (!m_on || p.frame < m_a || p.frame > m_b)
            return;
        const float* c = p.vertexConstants;
        bool ff = p.vertexProgram == 0 && c && p.vertexConstantCount >= 4;
        fprintf(m_f, "f%u d%u pass%u vm%u vp%u k%u buf%u tr%u n%u/%u st%u/%u/%u/%u bl%u:%u:%u:%u dt%u dw%u "
                "cull%u lit%u fog%u mat%08x/%08x/%08x/%08x amb%08x tf%.2f,%.2f,%.2f,%.2f cmb=%s t=(%.2f %.2f %.2f) "
                "q%u pipe%u\n",
                p.frame, p.drawIndex, p.pass, p.viewMode, p.vertexProgram, p.shaderKind, p.bufferOwner,
                p.transient != kSinkNone, p.count, p.vertexCount, p.stage[0].ordinal, p.stage[1].ordinal,
                p.stage[2].ordinal, p.stage[3].ordinal, p.state.blend, p.state.srcBlend, p.state.dstBlend,
                p.state.blendOp, p.state.depthTest, p.state.depthWrite, p.state.cull, p.lighting, p.fog, p.material[0],
                p.material[1], p.material[2], p.material[3], p.ambient, p.frag[3][0], p.frag[3][1], p.frag[3][2],
                p.frag[3][3], p.combinerKey, ff ? c[3] : 0.f, ff ? c[7] : 0.f, ff ? c[11] : 0.f, p.query != kSinkNone,
                p.pipeline);
        if (p.lighting && p.lights)
            for (int i = 0; i < 8; i++)
                if (p.lights[i].on)
                    fprintf(m_f, "   L%d type%d col %.2f %.2f %.2f pos %.1f %.1f %.1f dir %.2f %.2f %.2f r%.1f\n", i,
                            p.lights[i].type, p.lights[i].diffuse[0], p.lights[i].diffuse[1], p.lights[i].diffuse[2],
                            p.lights[i].position[0], p.lights[i].position[1], p.lights[i].position[2],
                            p.lights[i].direction[0], p.lights[i].direction[1], p.lights[i].direction[2],
                            p.lights[i].range);
    }
    // (wr3a) the frame's passes, copies and effect quads between the draws
    void passSet(uint16_t game, const SinkPass& p) override
    {
        if (m_on > 0 && m_inFrame)
            fprintf(m_f, "PASS game%u view%u target%s%x clear%x %u,%u %ux%u\n", game, p.id,
                    p.target == kSinkTargetScene ? "scene" : "", p.target == kSinkTargetScene ? 0 : p.target,
                    p.clearFlags, p.x, p.y, p.w, p.h);
    }
    void copy(uint16_t pass, const SinkTarget& dst) override
    {
        if (m_on > 0 && m_inFrame)
            fprintf(m_f, "COPY pass%u -> tex%u fb%u\n", pass, dst.texture, dst.frameBuffer);
    }
    void fx(const FxPacket& p) override
    {
        if (m_on > 0 && m_inFrame)
            fprintf(m_f, "FX pass%u prog%u quad %.0f,%.0f-%.0f,%.0f tex%u,%u n%u state%x target %ux%u\n", p.pass,
                    p.program, p.x0, p.y0, p.x1, p.y1, p.texture[0], p.texture[1], p.textures, p.state,
                    p.targetWidth, p.targetHeight);
    }
    void vertices(uint32_t, const SinkVertexData& d) override
    {
        if (m_on <= 0 || d.count > 64 || !d.packed)
            return;
        double c[4] = {0, 0, 0, 0};
        for (uint32_t i = 0; i < d.count; i++)
            for (int k = 0; k < 4; k++)
                c[k] += (d.vertices[i].colour0 >> (8 * k) & 255) / 255.0 / d.count;
        fprintf(m_f, "VB owner%u n%u key%016llx flags%x prim%u bgra %.2f %.2f %.2f %.2f\n", d.owner, d.count,
                (unsigned long long)texpack_xxh64(d.packed, (size_t)d.count * d.packedStride), d.vertexFlags, d.primKind,
                c[0], c[1], c[2], c[3]);
    }
    void packet(DrawPacket& p) override
    {
        if (m_on < 0)
            open();
        static int n = -1;
        static unsigned hide[16];
        if (n < 0) {
            n = 0;
            if (const char* e = getenv("HULK_LIGHT_HIDE"))
                while (n < 16 && *e) {
                    hide[n++] = (unsigned)strtoul(e, (char**)&e, 10);
                    if (*e == ',')
                        e++;
                }
        }
        for (int i = 0; i < n; i++)
            if (p.stage[0].ordinal == hide[i])
                p.state.writeMask = 0;
    }
    void frame() override
    {
        if (m_on > 0)
            fflush(m_f);
    }

  private:
    int m_on = -1;
    bool m_inFrame = false;
    unsigned m_a = 0, m_b = 0;
    FILE* m_f = nullptr;
};
HULK_RM_REGISTER_PASS(LightDump);

} // namespace

// (rm_pass.h) a runner shader by name for this renderer's profile, made once; 0xffff when there is none
uint16_t rm::loadShader(const char* name)
{
    static std::unordered_map<std::string, uint16_t> made;
    auto it = made.find(name);
    if (it != made.end())
        return it->second;
    uint16_t h = kInvalid;
    const char* prof = profile();
    for (const RmEmbeddedShader* s = g_rm_shaders; s->name; s++)
        if (!strcmp(s->name, name) && !strcmp(s->profile, prof)) {
            bgfx::ShaderHandle sh = bgfx::createShader(bgfx::makeRef(s->data, s->size));
            if (bgfx::isValid(sh))
                h = sh.idx;
            break;
        }
    made[name] = h;
    return h;
}
