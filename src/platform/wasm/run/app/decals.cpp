// Lasting decals (wdecal1, D249/D250; docs/destruction.md "Lasting decals"; Video Options > Lasting Decals).
//
// The game's world hits are decals (CDecalQueue, src/engine/pure3d/prop/CMotionTrail.cpp): 100 prim buffers of 66
// vertices made at World init, filled round robin by 0x00283e10 (the collision triangles around the hit, clipped to the
// decal's square, 0.03 units out along their normal) and drawn by 0x0027f4a0, which draws only the 85 newest (the 15
// oldest slots are the ones the next adds rewrite; at most 14 adds a frame) in one run, oldest first, with depth
// writes off. Nothing fades or times out: a decal goes when 85 newer ones have been made, which a fight does in a few
// seconds, or when the queue is cleared (0x00280800: a mission unloads, 0x001cd410, or the world resets, 0x00088b80).
// Leaving an area forgets nothing by itself (the vertices are copies, not the room's).
//
// This pass keeps them (output only: nothing here reads or writes the module's memory). The decal draws are known by
// their shape at the sink (a 66-vertex prim buffer, a triangle list, blended, no depth writes, in the world's pass).
// When a decal falls out of the game's 85 (it was drawn the last frame and is not now, while others are), the runner
// copies it (its vertices, as the sink got them, and how it was drawn: textures, combiner, blend) into its own buffers
// (pages of 32 decals that share a look) and draws the copies every frame from then on, before the game's own, with
// the frame's camera from the first live decal draw: up to kKeep decals, the oldest going first. In the frame a decal
// falls out it is drawn once more from the game's own buffer (still holding it: its slot is rewritten 15 adds later).
// A clear of the game's queue (3 world frames in a row with no decal drawn after some were) drops the copies too, so a
// new mission starts clean as in the game. A texture the game drops (an unloaded inventory) puts its copies to sleep
// under the texture's content key until the game makes the same texture again (the area loaded again).
//
// Fit: every decal (the game's and the copies) is drawn with vs_rm_decal + fs_px_decal (the faithful generic combiner,
// fog and alpha test): pulled towards the camera a little (so it wins the depth test over the render mesh it lies on:
// no z-fighting where the collision mesh sits a hair below it) and faded out where the scene's surface behind it is
// further than a few centimetres along its normal (the collision mesh differs from the render mesh, so a decal floated
// over steps, kerbs and gaps), from a linear-depth copy of the scene taken at the frame's first decal.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <bgfx/bgfx.h>

#include "interp.h"
#include "nightlights.h"
#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);

namespace {

const uint32_t kDecalVerts = 66;          // (CDecalQueue: 0x42 vertices a slot)
const int kPageDecals = 32;               // decals a page (one buffer, one draw)
const uint32_t kPageVerts = kPageDecals * kDecalVerts;
const int kKeep = 1024;                   // copies kept (the game: 85)
const uint32_t kGameReserve = 1536;       // bgfx's buffer handles left to the game (farfield.cpp's reserve)
const float kCullDepth = 450.0f;          // pages beyond this (camera depth) are not drawn (draw distance 400)

int logLevel()
{
    static int n = -1;
    if (n < 0)
        n = getenv("HULK_DECAL_LOG") ? atoi(getenv("HULK_DECAL_LOG")) : 0;
    return n;
}

// how a decal was drawn (everything of its packet but the camera and the vertices)
struct Look {
    SinkStage stage[4];
    SinkRenderState state;
    float frag[16][4];
    const char* combinerKey;              // (interned)
    const char* programName;
    uint32_t combinerHash, pipeline, shaderKind, vertexProgram, lighting, fog;
    uint8_t generic;
    bool tfUsed;
    // (a texture the game dropped: the stage's content key until the game makes it again; not drawn meanwhile)
    bool dormant;
    uint64_t want[4];
};
bool sameLook(const Look& a, const Look& b)
{
    return !a.dormant && !b.dormant && !memcmp(a.stage, b.stage, sizeof a.stage) && !memcmp(&a.state, &b.state, sizeof a.state) &&
           !memcmp(a.frag, b.frag, sizeof a.frag) && a.combinerKey == b.combinerKey &&
           a.programName == b.programName && a.combinerHash == b.combinerHash && a.pipeline == b.pipeline &&
           a.shaderKind == b.shaderKind && a.vertexProgram == b.vertexProgram && a.lighting == b.lighting &&
           a.fog == b.fog && a.generic == b.generic && a.tfUsed == b.tfUsed;
}

// one of the game's decal buffers
struct Slot {
    std::vector<SinkVertex> v;            // the vertices as last written
    uint32_t sinkBuffer = kSinkNone;
    int look = -1;                        // how it was last drawn (m_looks)
    uint32_t drawnAt = 0;                 // the world frame it was last drawn in (0: not since its last write)
    bool kept = false;                    // copied (or cleared): never copied again until rewritten
};

struct Ghost {
    SinkVertex v[kDecalVerts];
    int look;
    int page;
    float c[3], r;
};

struct Page {
    int look;
    uint32_t vb = kSinkNone, owner = 0;
    std::vector<uint64_t> ghosts;         // in age order
    bool dirty = true;
    float c[3] = {0, 0, 0}, r = 0;
};

class DecalsPass final : public rm::Pass {
  public:
    const char* name() const override { return "decals"; }
    // (the copies are submitted from the first decal's draw hook and the fallen ones from the next hook: before the
    // shadows' casters (5), the night lights (6) and the lighting pass's binds (10) for that next draw)
    int order() const override { return 4; }
    void settingsChanged(const rm::Settings& s) override
    {
        bool on = s[rm::kDecals] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: lasting decals %s\n", on ? "on" : "off");
        m_on = on;
        if (!on)
            dropAll();
        // HULK_DECAL_FIT=floatStart,floatEnd,pull,pullPerDepth,cosFloor (development tuning; floatEnd 0: no fit)
        if (const char* e = getenv("HULK_DECAL_FIT"))
            sscanf(e, "%f,%f,%f,%f,%f", &m_f0, &m_f1, &m_pull, &m_pullDepth, &m_cosFloor);
    }
    bool midFrame() const override { return m_on && fitOn(); }

    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (d.count != kDecalVerts || !d.vertices || !d.owner) {
            auto it = m_slotOf.find(sinkBuffer);           // (a buffer id the sink gave to something else now)
            if (it != m_slotOf.end() && it->second != d.owner)
                m_slotOf.erase(it);
            return;
        }
        Slot& s = m_slots[d.owner];
        // a slot rewritten while the copies would still want its old decal (it was drawn and not copied yet)
        if (m_on && s.drawnAt && !s.kept && s.look >= 0 && s.v.size() == kDecalVerts) {
            keep(s);
            m_rewriteKeeps++;
        }
        s.v.assign(d.vertices, d.vertices + d.count);
        s.sinkBuffer = sinkBuffer;
        s.drawnAt = 0;
        s.kept = false;
        m_slotOf[sinkBuffer] = d.owner;
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        auto it = m_slotOf.find(sinkBuffer);
        if (it == m_slotOf.end())
            return;
        m_slots.erase(it->second);
        m_slotOf.erase(it);
    }
    void textureCreated(uint32_t vid, const SinkTextureDesc& d) override
    {
        m_ordinalOf[vid] = d.ordinal;
        m_hashOf.erase(vid);
    }
    // a texture's content key (its top level's bytes): a texture the game drops and makes again later (a decal
    // texture of an inventory unloaded while its decals are copies, loaded again when the area is) is known again
    void textureLevel(uint32_t vid, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t size) override
    {
        if (level != 0 || !data || !size)
            return;
        uint64_t x = 0xcbf29ce484222325ull ^ ((uint64_t)w << 32 | h);
        const uint8_t* b = (const uint8_t*)data;
        uint32_t n8 = size / 8;
        for (uint32_t i = 0; i < n8; i++) {
            uint64_t v;
            memcpy(&v, b + 8 * i, 8);
            x = (x ^ v) * 0x100000001b3ull;
            x ^= x >> 29;
        }
        for (uint32_t i = n8 * 8; i < size; i++)
            x = (x ^ b[i]) * 0x100000001b3ull;
        m_hashOf[vid] = x;
        if (m_dormant.count(x)) {
            auto o = m_ordinalOf.find(vid);
            if (o != m_ordinalOf.end() && o->second)
                m_wantOrd[o->second] = x;
        }
    }
    void textureDropped(uint32_t vid) override
    {
        auto it = m_ordinalOf.find(vid);
        if (it == m_ordinalOf.end())
            return;
        uint32_t ord = it->second;
        m_ordinalOf.erase(it);
        auto hit = m_hashOf.find(vid);
        uint64_t h = hit != m_hashOf.end() ? hit->second : 0;
        if (hit != m_hashOf.end())
            m_hashOf.erase(hit);
        if (!ord)
            return;
        m_wantOrd.erase(ord);
        // the copies drawn with it wait (not drawn) for the same texture to be made again; without a content key
        // they go (the sink's id may name another texture next)
        for (size_t i = 0; i < m_looks.size(); i++)
            for (int k = 0; k < 4; k++)
                if (m_looks[i].stage[k].ordinal == ord) {
                    if (h) {
                        m_looks[i].stage[k].texture = kSinkNone;
                        m_looks[i].stage[k].ordinal = 0;
                        m_looks[i].want[k] = h;
                        m_looks[i].dormant = true;
                        m_dormant[h]++;
                        m_slept++;
                    } else
                        dropLook((int)i);
                }
    }

    void late(DrawPacket& p) override
    {
        if (!m_on)
            return;
        if (!m_wantOrd.empty())
            revive(p);
        if (!m_worldKnown) {
            // the world's pass: the game pass of the frame's first room draw (shader kind 1/2, unlit, opaque)
            if (p.viewMode == 0 && p.vertexProgram == 0 && !p.state.blend && p.state.depthWrite && !p.lighting &&
                p.transient == kSinkNone && (p.shaderKind == 1 || p.shaderKind == 2)) {
                m_worldPass = rm::currentGamePass();
                m_worldKnown = true;
            }
            return;
        }
        if (!decal(p))
            return;
        if (!fitOn())
            return;
        if (!m_copied)
            copyDepth();
        uint16_t prog = fitProgram();
        if (prog == rm::kNoHandle || m_depth.tex == rm::kNoHandle || !m_copyOk)
            return;
        m_liveBlend = blendMode(p.state);
        if (m_liveBlend < 0)
            return;
        m_faithfulPipe = p.pipeline;
        p.pipeline = prog;
        m_fitLive = true;
    }
    void draw(const DrawPacket& p) override
    {
        bool isDecal = m_on && m_worldKnown && decal(p);
        if (!isDecal) {
            flushRun();
            return;
        }
        auto it = m_slots.find(p.bufferOwner);
        if (it == m_slots.end() || it->second.sinkBuffer != p.vertexBuffer) {
            m_unknown++;
            return;
        }
        Slot& s = it->second;
        int look = lookOf(p);
        if (!m_inRun) {
            m_inRun = true;
            m_runDraws = 0;
            submitGhosts(p);
        }
        m_runDraws++;
        m_live++;
        s.look = look;
        s.drawnAt = m_worldFrame;
        keepRef(p);
        if (logLevel() >= 2 && m_detail < 6 && m_detailLooks.insert(look).second) {
            m_detail++;
            const Look& L = m_looks[look];
            fprintf(stderr, "hulk-app: decal look %d: owner %u vb %u count %u/%u shader kind %u prog '%s' vp %u lit %u "
                    "fog %u combiner '%s' blend %u op %u src %u dst %u depth %u/%u/%u cull %u mask %u stencil %u "
                    "tex %u/%u %u/%u pass %u\n", look, p.bufferOwner, p.vertexBuffer, p.count, p.vertexCount,
                    L.shaderKind, L.programName, L.vertexProgram, L.lighting, L.fog, L.combinerKey, L.state.blend,
                    L.state.blendOp, L.state.srcBlend, L.state.dstBlend, L.state.depthTest, L.state.depthFunc,
                    L.state.depthWrite, L.state.cull, L.state.writeMask, L.state.stencil, L.stage[0].texture,
                    L.stage[0].ordinal, L.stage[1].texture, L.stage[1].ordinal, rm::currentGamePass());
            const float* c = p.vertexConstants;
            if (c && p.vertexConstantCount >= 8)
                fprintf(stderr, "hulk-app: decal mv %.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f "
                        "v0 %.2f %.2f %.2f n %.2f %.2f %.2f uv %.3f %.3f col %08x\n", c[0], c[1], c[2], c[3], c[4],
                        c[5], c[6], c[7], c[8], c[9], c[10], c[11], s.v[0].pos[0], s.v[0].pos[1], s.v[0].pos[2],
                        s.v[0].normal[0], s.v[0].normal[1], s.v[0].normal[2], s.v[0].uv[0][0], s.v[0].uv[0][1],
                        s.v[0].colour0);
        }
        if (m_fitLive)
            m_bindLive = true;           // (DecalsBindPass binds the depth copy after every other pass's hook)
    }
    void passSet(uint16_t, const SinkPass&) override { flushRun(); }
    void copy(uint16_t, const SinkTarget&) override { flushRun(); }
    void fx(const FxPacket&) override { flushRun(); }
    void postScene(const rm::Scene&, uint16_t&) override { flushRun(); }
    void frame() override
    {
        flushRun();
        abCost();
        // a world frame with no decal drawn, three in a row after some were: the game cleared its queue
        if (m_on && m_worldKnown) {
            if (m_frameDecals == 0) {
                if (m_hadDecals && ++m_zeroRun >= 3)
                    clearAll();
            } else
                m_zeroRun = 0, m_hadDecals = true;
        }
        if (m_worldSeen)
            m_worldFrame++;
        m_frames++;
        if (logLevel() >= 1 && m_frames % 300 == 0) {
            size_t pages = 0;
            for (auto& pg : m_pages)
                pages += pg.vb != kSinkNone;
            fprintf(stderr, "hulk-app: decals: %.1f live a frame, %u kept (%zu pages, %zu looks), %u fell out, %u "
                    "kept on rewrite, %u fallen draws, %.1f ghost draws a frame, %u clears, %u unknown, %u slots, %u/%u "
                    "looks slept/revived (textures dropped and made again)\n",
                    m_live / 300.0, (unsigned)m_order.size(), pages, m_looks.size(), m_fell, m_rewriteKeeps,
                    m_fallenDraws, m_ghostDraws / 300.0, m_clears, m_unknown, (unsigned)m_slots.size(), m_slept,
                    m_revived);
            m_live = m_ghostDraws = 0;
        }
        m_worldKnown = m_copied = m_copyOk = m_fitLive = m_worldSeen = false;
        m_frameDecals = 0;
    }

    // DecalsBindPass's: the fit program's depth sampler and uniforms for the game's own decal draw
    void bindLive(const DrawPacket& p)
    {
        if (!m_bindLive)
            return;
        m_bindLive = false;
        if (p.pipeline == fitProgram())
            bind(m_liveBlend);
    }

  private:
    bool fitOn() const { return m_f1 > 0.0f; }
    // a decal of the game's queue (see the header)
    bool decal(const DrawPacket& p) const
    {
        return p.viewMode == 0 && p.transient == kSinkNone && p.indexBuffer == kSinkNone && p.count == kDecalVerts &&
               p.state.prim == 0 && p.state.blend && p.state.depthTest && !p.state.depthWrite && !p.state.stencil &&
               p.query == kSinkNone && p.vertexProgram == 0 && p.bufferOwner && p.vertexConstants &&
               p.vertexConstantCount >= 8 && rm::currentGamePass() == m_worldPass;
    }
    // the fit's colour rule for a blend: 0 alpha fades (src-alpha / x), 1 colour and alpha scale (one / x), 2 towards
    // white (a multiply); -1: not one we fade (drawn faithfully)
    static int blendMode(const SinkRenderState& s)
    {
        if (s.blendOp != kBlendAdd)
            return -1;
        if (s.srcBlend == kBlendSrcAlpha)
            return 0;
        if (s.srcBlend == kBlendOne && (s.dstBlend == kBlendOne || s.dstBlend == kBlendInvSrcAlpha))
            return 1;
        if ((s.srcBlend == kBlendDstColour && s.dstBlend == kBlendZero) ||
            (s.srcBlend == kBlendZero && s.dstBlend == kBlendSrcColour))
            return 2;
        return -1;
    }
    uint16_t fitProgram() const { return rm::program("vs_rm_decal", "fs_px_decal"); }

    int lookOf(const DrawPacket& p)
    {
        Look L;
        memset(&L, 0, sizeof L);
        memcpy(L.stage, p.stage, sizeof L.stage);
        L.state = p.state;
        memcpy(L.frag, p.frag, sizeof L.frag);
        L.frag[1][0] = L.frag[1][1] = L.frag[1][2] = L.frag[2][0] = L.frag[2][1] = 0;   // (fog: the frame's)
        // the texture factor: the game leaves a different one at each decal (fifteen steps), which the decals'
        // combiner (texture x diffuse, colour and alpha) never reads; kept only for a combiner that could
        L.tfUsed = !p.combinerKey || strcmp(p.combinerKey, "c4.0.2a4.0.2r1") != 0;
        if (!L.tfUsed)
            memset(L.frag[3], 0, sizeof L.frag[3]);
        L.combinerKey = intern(p.combinerKey);
        L.programName = intern(p.programName);
        L.combinerHash = p.combinerHash;
        L.pipeline = m_fitLive && p.pipeline == fitProgram() ? m_faithfulPipe : p.pipeline;
        L.shaderKind = p.shaderKind;
        L.vertexProgram = p.vertexProgram;
        L.lighting = p.lighting;
        L.fog = p.fog;
        L.generic = p.generic;
        for (size_t i = 0; i < m_looks.size(); i++)
            if (sameLook(m_looks[i], L))
                return (int)i;
        if (logLevel() >= 3 && !m_looks.empty() && m_looks.size() < 12) {
            const Look& A = m_looks[0];
            fprintf(stderr, "hulk-app: decal look %zu differs from 0 in:", m_looks.size());
            for (int i = 0; i < 16; i++)
                for (int k = 0; k < 4; k++)
                    if (A.frag[i][k] != L.frag[i][k])
                        fprintf(stderr, " frag[%d][%d] %g/%g", i, k, A.frag[i][k], L.frag[i][k]);
            for (int k = 0; k < 4; k++)
                if (memcmp(&A.stage[k], &L.stage[k], sizeof A.stage[k]))
                    fprintf(stderr, " stage%d tex %u/%u", k, A.stage[k].texture, L.stage[k].texture);
            if (memcmp(&A.state, &L.state, sizeof A.state))
                fprintf(stderr, " state");
            fprintf(stderr, " (pipeline %u/%u, combiner %s/%s)\n", A.pipeline, L.pipeline, A.combinerKey, L.combinerKey);
        }
        m_looks.push_back(L);
        return (int)m_looks.size() - 1;
    }
    const char* intern(const char* s)
    {
        if (!s)
            return nullptr;
        return m_strings.insert(std::string(s)).first->c_str();
    }

    // the last live decal's packet (the frame's camera for the fallen ones, drawn at the run's end)
    void keepRef(const DrawPacket& p)
    {
        m_ref = p;
        uint32_t n = p.vertexConstantCount < 96 ? p.vertexConstantCount : 96;
        memcpy(m_vc, p.vertexConstants, n * 16);
        m_ref.vertexConstants = &m_vc[0][0];
        m_ref.vertexConstantCount = n;
        m_ref.lights = nullptr;
        if (p.lights) {
            memcpy(m_lights, p.lights, sizeof m_lights);
            m_ref.lights = m_lights;
        }
        const float* mats[3] = {p.modelview, p.projection, p.view};
        const float** outs[3] = {&m_ref.modelview, &m_ref.projection, &m_ref.view};
        for (int i = 0; i < 3; i++) {
            *outs[i] = nullptr;
            if (mats[i]) {
                memcpy(m_mats[i], mats[i], sizeof m_mats[i]);
                *outs[i] = m_mats[i];
            }
        }
        m_ref.combinerKey = m_ref.programName = "";
        m_haveRef = true;
    }

    // the end of the frame's decal run: the decals that fell out of the game's 85 are copied, and drawn once more
    // from their own buffers
    void flushRun()
    {
        if (!m_inRun)
            return;
        m_inRun = false;
        m_frameDecals += m_runDraws;
        m_worldSeen = true;
        for (auto& e : m_slots) {
            Slot& s = e.second;
            if (s.kept || !s.drawnAt || s.drawnAt == m_worldFrame || s.drawnAt + 1 != m_worldFrame || s.look < 0 ||
                s.v.size() != kDecalVerts || s.sinkBuffer == kSinkNone)
                continue;
            m_fell++;
            if (m_haveRef) {
                DrawPacket q = m_ref;
                apply(q, m_looks[s.look]);
                q.vertexBuffer = s.sinkBuffer;
                q.count = q.vertexCount = kDecalVerts;
                q.bufferOwner = e.first;
                submit(q, m_looks[s.look]);
                m_fallenDraws++;
            }
            keep(s);
        }
    }

    // a packet drawn as `L` with the reference's camera and fog
    void apply(DrawPacket& q, const Look& L)
    {
        float fog1[4], fog2[4], tf[4];
        memcpy(fog1, q.frag[1], sizeof fog1);
        memcpy(fog2, q.frag[2], sizeof fog2);
        memcpy(tf, q.frag[3], sizeof tf);
        memcpy(q.stage, L.stage, sizeof q.stage);
        q.state = L.state;
        memcpy(q.frag, L.frag, sizeof q.frag);
        memcpy(q.frag[1], fog1, sizeof fog1);
        q.frag[2][0] = fog2[0], q.frag[2][1] = fog2[1];
        if (!L.tfUsed)
            memcpy(q.frag[3], tf, sizeof tf);
        q.combinerKey = L.combinerKey ? L.combinerKey : "";
        q.programName = L.programName ? L.programName : "";
        q.combinerHash = L.combinerHash;
        q.pipeline = L.pipeline;
        q.generic = L.generic;
        q.shaderKind = L.shaderKind;
        q.vertexProgram = L.vertexProgram;
        q.lighting = L.lighting;
        q.fog = L.fog;
        q.query = kSinkNone;
        q.transient = kSinkNone;
        q.indexBuffer = kSinkNone;
        q.pass = rm::sinkView(rm::currentGamePass());
    }
    void submit(DrawPacket& q, const Look& L)
    {
        int mode = blendMode(L.state);
        uint16_t prog = fitProgram();
        if (fitOn() && m_copyOk && mode >= 0 && prog != rm::kNoHandle && m_depth.tex != rm::kNoHandle) {
            q.pipeline = prog;
            bind(mode);
        }
        if (q.pipeline == kSinkNone)
            return;
        rm::sinkDraw(q, "lasting decal copies");
    }
    void bind(int mode)
    {
        if (!m_up) {
            m_uDecal = bgfx::createUniform("u_rmDecal", bgfx::UniformType::Vec4, 3);
            m_sDepth = bgfx::createUniform("s_rmDecalDepth", bgfx::UniformType::Sampler);
            m_up = true;
        }
        float u[3][4] = {
            {m_f0, m_f1, (float)mode, 0.0f},
            {m_w ? 1.0f / m_w : 0.0f, m_h ? 1.0f / m_h : 0.0f, m_cosFloor, 0.0f},
            {m_pull, m_pullDepth, 0.0f, 0.0f},
        };
        bgfx::setUniform(m_uDecal, u, 3);
        rm::bindTexture(6, m_sDepth.idx, m_depth.tex,
                         BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT);
    }

    // ---- the copies
    void keep(Slot& s)
    {
        s.kept = true;
        if (s.look < 0 || s.v.size() != kDecalVerts)
            return;
        uint64_t id = ++m_nextGhost;
        Ghost& g = m_ghosts[id];
        memcpy(g.v, s.v.data(), sizeof g.v);
        g.look = s.look;
        float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
        for (uint32_t i = 0; i < kDecalVerts; i++)
            for (int k = 0; k < 3; k++)
                lo[k] = fminf(lo[k], g.v[i].pos[k]), hi[k] = fmaxf(hi[k], g.v[i].pos[k]);
        float r2 = 0;
        for (int k = 0; k < 3; k++)
            g.c[k] = 0.5f * (lo[k] + hi[k]), r2 += 0.25f * (hi[k] - lo[k]) * (hi[k] - lo[k]);
        g.r = sqrtf(r2);
        // the look's newest page with room, else a new one
        int page = -1;
        for (int i = (int)m_pages.size() - 1; i >= 0; i--)
            if (m_pages[i].look == g.look && m_pages[i].owner) {
                if ((int)m_pages[i].ghosts.size() < kPageDecals)
                    page = i;
                break;
            }
        if (page < 0) {
            Page pg;
            pg.look = g.look;
            pg.owner = 0xE0000000u + (m_nextOwner++ & 0x0fffffffu);
            m_pages.push_back(pg);
            page = (int)m_pages.size() - 1;
        }
        g.page = page;
        m_pages[page].ghosts.push_back(id);
        m_pages[page].dirty = true;
        m_order.push_back(id);
        while ((int)m_order.size() > kKeep)
            dropGhost(m_order.front());
    }
    void dropGhost(uint64_t id)
    {
        auto it = m_ghosts.find(id);
        if (it == m_ghosts.end())
            return;
        Page& pg = m_pages[it->second.page];
        for (size_t i = 0; i < pg.ghosts.size(); i++)
            if (pg.ghosts[i] == id) {
                pg.ghosts.erase(pg.ghosts.begin() + i);
                break;
            }
        pg.dirty = true;
        m_ghosts.erase(it);
        for (size_t i = 0; i < m_order.size(); i++)
            if (m_order[i] == id) {
                m_order.erase(m_order.begin() + i);
                break;
            }
    }
    void dropLook(int look)
    {
        std::vector<uint64_t> ids;
        for (auto& e : m_ghosts)
            if (e.second.look == look)
                ids.push_back(e.first);
        for (uint64_t id : ids)
            dropGhost(id);
        for (auto& e : m_slots)
            if (e.second.look == look)
                e.second.kept = true, e.second.look = -1;
    }
    void clearAll()
    {
        if (!m_order.empty())
            m_clears++;
        dropAll();
        for (auto& e : m_slots)
            e.second.kept = true;          // (cleared by the game: nothing of them is copied later)
        m_hadDecals = false;
        m_zeroRun = 0;
        if (logLevel() >= 1)
            fprintf(stderr, "hulk-app: decals: the game's queue was cleared (frame %u): copies dropped\n", m_frames);
    }
    void dropAll()
    {
        for (auto& pg : m_pages)
            if (pg.vb != kSinkNone)
                interp_destroy(2, pg.vb, kSinkNone);
        m_pages.clear();
        m_ghosts.clear();
        m_order.clear();
        m_dormant.clear();
        m_wantOrd.clear();
    }
    // a page's buffer as its copies are now (made, written again or dropped); pages are written at full size
    // (unused decals degenerate) so the sink's dynamic buffer never grows
    void makePages()
    {
        const bgfx::Caps* caps = bgfx::getCaps();
        const bgfx::Stats* st = bgfx::getStats();
        for (auto& pg : m_pages) {
            if (!pg.dirty)
                continue;
            pg.dirty = false;
            if (pg.ghosts.empty()) {
                if (pg.vb != kSinkNone)
                    interp_destroy(2, pg.vb, kSinkNone);
                pg.vb = kSinkNone;
                pg.owner = 0;                       // (a page emptied for good: copies go oldest first)
                continue;
            }
            if (pg.vb == kSinkNone && caps && st) {
                uint32_t limit = std::min(caps->limits.maxVertexBuffers, caps->limits.maxDynamicVertexBuffers);
                uint32_t used = std::max((uint32_t)st->numVertexBuffers, (uint32_t)st->numDynamicVertexBuffers);
                if (used + kGameReserve + 2 >= limit) {
                    m_noRoom++;
                    pg.dirty = true;
                    continue;
                }
            }
            m_pageVerts.assign(kPageVerts, SinkVertex());
            float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
            size_t n = 0;
            for (uint64_t id : pg.ghosts) {
                const Ghost& g = m_ghosts[id];
                memcpy(&m_pageVerts[n * kDecalVerts], g.v, sizeof g.v);
                for (int k = 0; k < 3; k++)
                    lo[k] = fminf(lo[k], g.c[k] - g.r), hi[k] = fmaxf(hi[k], g.c[k] + g.r);
                n++;
            }
            float r2 = 0;
            for (int k = 0; k < 3; k++)
                pg.c[k] = 0.5f * (lo[k] + hi[k]), r2 += 0.25f * (hi[k] - lo[k]) * (hi[k] - lo[k]);
            pg.r = sqrtf(r2);
            SinkVertexData vd = {m_pageVerts.data(), kPageVerts, pg.owner, nullptr, 0, 0, 0};
            pg.vb = hulk_gfx_sink_update_vertex_buffer(pg.vb, &vd);
        }
    }
    // the copies, before the frame's first live decal (`p`: the frame's camera)
    // a draw naming a texture the dormant copies wait for: its sink id, so they are drawn again
    void revive(const DrawPacket& p)
    {
        for (int k = 0; k < 4; k++) {
            auto w = m_wantOrd.find(p.stage[k].ordinal);
            if (w == m_wantOrd.end() || p.stage[k].texture == kSinkNone)
                continue;
            uint64_t h = w->second;
            for (auto& L : m_looks) {
                if (!L.dormant)
                    continue;
                bool waiting = false;
                for (int j = 0; j < 4; j++) {
                    if (L.want[j] == h) {
                        L.stage[j].texture = p.stage[k].texture;
                        L.stage[j].ordinal = p.stage[k].ordinal;
                        L.want[j] = 0;
                    }
                    waiting |= L.want[j] != 0;
                }
                if (!waiting) {
                    L.dormant = false;
                    m_revived++;
                }
            }
            m_dormant.erase(h);
            m_wantOrd.erase(w);
        }
    }

    void submitGhosts(const DrawPacket& p)
    {
        if (m_abOff || m_order.empty())
            return;
        makePages();
        const float* c = p.vertexConstants;      // (decals are in world space: the modelview is the view)
        for (auto& pg : m_pages) {
            if (pg.vb == kSinkNone || pg.ghosts.empty() || m_looks[pg.look].dormant)
                continue;
            float z = c[8] * pg.c[0] + c[9] * pg.c[1] + c[10] * pg.c[2] + c[11];
            if (z + pg.r < 0.0f || z - pg.r > kCullDepth)
                continue;
            DrawPacket q = p;
            apply(q, m_looks[pg.look]);
            q.vertexBuffer = pg.vb;
            q.count = q.vertexCount = (uint32_t)pg.ghosts.size() * kDecalVerts;
            q.bufferOwner = pg.owner;
            submit(q, m_looks[pg.look]);
            m_ghostDraws++;
        }
    }

    // ---- the fit's depth copy (as particles.cpp's): the scene's depth so far as linear camera depth
    void copyDepth()
    {
        m_copied = true;                                // (one try a frame)
        float view[3][4], inv[3][3], P[16];
        if (!rm::frameCamera(view, inv, P))
            return;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || depth == kSinkNone || !w || !h)
            return;
        uint16_t prog = rm::program("vs_rm_quad", "fs_rm_softdepth");
        if (prog == rm::kNoHandle)
            return;
        if (!m_format) {
            const bgfx::Caps* caps = bgfx::getCaps();
            const uint32_t need = BGFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER | BGFX_CAPS_FORMAT_TEXTURE_2D;
            m_format = caps && (caps->formats[bgfx::TextureFormat::R32F] & need) == need ? bgfx::TextureFormat::R32F
                                                                                       : bgfx::TextureFormat::R16F;
        }
        if (!m_depth.ensure(w, h, m_format, false, false))
            return;
        uint16_t v;
        if (!rm::viewsHere(1, &v))
            return;
        m_w = w, m_h = h;
        float a[4] = {P[10], P[11], P[14], P[15]};       // (c6.z, c6.w, c7.z, c7.w)
        rm::viewInto(v, m_depth.fb, w, h);
        rm::texture(0, (uint16_t)depth, BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT);
        rm::uniform("u_rmSoftCopy", a);
        rm::quad(v, prog, BGFX_STATE_WRITE_R);
        m_copyOk = true;
    }

    // HULK_DECAL_AB=N: the copies and the fit off and on in turns of N presented frames (GPU and render thread)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_DECAL_AB") ? atoi(getenv("HULK_DECAL_AB")) : 0;
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
            m_savedF1 = m_abOff ? m_f1 : m_savedF1;
            m_f1 = m_abOff ? 0.0f : m_savedF1;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: decals cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %u kept)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1], (unsigned)m_order.size());
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};
    float m_savedF1 = 0;

    bool m_on = false, m_up = false;
    bool m_worldKnown = false, m_worldSeen = false, m_copied = false, m_copyOk = false, m_fitLive = false;
    bool m_bindLive = false, m_inRun = false, m_haveRef = false;
    int m_liveBlend = 0;
    uint16_t m_worldPass = 0xffff;
    uint32_t m_worldFrame = 1, m_frames = 0, m_runDraws = 0, m_frameDecals = 0, m_zeroRun = 0;
    uint32_t m_faithfulPipe = kSinkNone;     // (the live decal's own program, before the fit's)
    bool m_hadDecals = false;
    std::unordered_map<uint32_t, Slot> m_slots;          // the game's decal buffers by prim buffer owner
    std::unordered_map<uint32_t, uint32_t> m_slotOf;     // sink vertex buffer -> owner
    std::unordered_map<uint32_t, uint32_t> m_ordinalOf;  // texture vid -> the front end's ordinal
    std::unordered_map<uint32_t, uint64_t> m_hashOf;     // texture vid -> its top level's content key
    std::unordered_map<uint64_t, int> m_dormant;         // content keys dormant copies wait for
    std::unordered_map<uint32_t, uint64_t> m_wantOrd;    // a made-again texture's ordinal -> its key (to revive)
    std::vector<Look> m_looks;
    std::unordered_set<std::string> m_strings;
    std::unordered_map<uint64_t, Ghost> m_ghosts;
    std::deque<uint64_t> m_order;                        // the copies, oldest first
    std::vector<Page> m_pages;
    std::vector<SinkVertex> m_pageVerts;
    uint64_t m_nextGhost = 0;
    uint32_t m_nextOwner = 0;
    DrawPacket m_ref;
    float m_vc[96][4];
    SinkLight m_lights[8];
    float m_mats[3][16];
    rm::Target m_depth;
    uint32_t m_format = 0, m_w = 0, m_h = 0;
    bgfx::UniformHandle m_uDecal = BGFX_INVALID_HANDLE, m_sDepth = BGFX_INVALID_HANDLE;
    // the fit: the floating fade's start and end (units along the normal), the pull towards the camera along the view
    // ray (units, plus a share of the depth), the floor of the view's cosine to the surface
    float m_f0 = 0.10f, m_f1 = 0.30f, m_pull = 0.05f, m_pullDepth = 0.002f, m_cosFloor = 0.12f;
    // log counters
    unsigned m_slept = 0, m_revived = 0;
    unsigned m_fell = 0, m_rewriteKeeps = 0, m_fallenDraws = 0, m_clears = 0, m_unknown = 0, m_noRoom = 0;
    unsigned m_detail = 0;
    std::unordered_set<int> m_detailLooks;
    double m_live = 0, m_ghostDraws = 0;
};
HULK_RM_REGISTER_PASS(DecalsPass);

// the fit program's sampler for the game's own decal draws, bound after every other pass's draw hook (a pass that
// submits a draw of its own from the same hook would take the binding with it: bgfx drops texture bindings at each
// submit)
class DecalsBindPass final : public rm::Pass {
  public:
    const char* name() const override { return "decals bind"; }
    int order() const override { return 90; }
    void draw(const DrawPacket& p) override { s_rmPass_DecalsPass.bindLive(p); }
};
HULK_RM_REGISTER_PASS(DecalsBindPass);

} // namespace
