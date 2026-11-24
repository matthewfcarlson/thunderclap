// Grass blades (wgrass1, docs/grass.md; Video Options > Grass: Original / Blades Low / Blades High).
//
// The game's lawns are flat textured ground. With blades on, the runner stands clumps of blades on them, instanced in
// world space, as part of the world's pass:
// 1. The ground: every texture's level 0 (the game's own bytes) becomes, on a worker thread, a 64x64 thumbnail, a
//    blurred copy and the share of it that reads as grass (shaders/rm_grass.sh's test, its twin `grassiness` here);
//    the rooms' prim buffers (vertices and indices) are kept as they are written (their vertices are in world space:
//    a room's modelview is the view itself).
// 2. The clumps: the first time a room draw with a grassy stage-0 or stage-1 texture is seen, a worker job strews its
//    level triangles (faces within ~37 degrees of up) with clump roots, a fixed number per unit of area, from a hash
//    of the triangle's position (the same lawn gets the same clumps whenever its room is loaded); the draw's own
//    combiner, evaluated on the thumbnails' texels under each root, keeps it only where the surface reads as grass and
//    gives it the ground's colour there; each gets a random rank. The clumps are sorted into 8-unit cells, each cell
//    by rank, in one static instance buffer (made at the next frame end).
// 3. Each frame, right after the ground draw (the next hook the runner reaches, like the window interiors), the cells
//    near the camera and in view are drawn instanced (vs_rm_grass / fs_rm_grass): a cell draws the prefix of its
//    clumps whose rank the density at its nearest point keeps; in the vertex shader a clump grows out of the ground as
//    the density at its own distance passes its rank and shrinks away towards the far end, so nothing pops as the
//    camera moves. Wind sways the blades from the display clock (interp_display_time: the same picture at any display
//    rate); the characters (the two-sided draws' origins, last presented frame) bend them aside. The blades take the
//    sun's shadows (the characters' and objects' row) as the ground does, and the ground draw's fog.
// Output only: nothing here reads or writes the module's memory, and nothing collides with the blades.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <condition_variable>
#include <deque>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "interp.h"
#include "rm_pass.h"
#include "rm_post.h"
#include "nightlights.h"
#include "shadows.h"

using namespace hulk::pddi;

namespace {

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_GRASS_LOG") ? atoi(getenv("HULK_GRASS_LOG")) : 0;
    return on;
}

// shaders/rm_grass.sh rmGrassiness, the same numbers
float grassiness(float r, float g, float b)
{
    float s = r + g + b;
    if (s < 0.015f)
        return 0.0f;
    float kr = r / s, kg = g / s, kb = b / s;
    auto sstep = [](float a, float c, float x) {
        float t = (x - a) / (c - a);
        t = t < 0 ? 0 : t > 1 ? 1 : t;
        return t * t * (3 - 2 * t);
    };
    float score = (kg - kr) + 0.6f * (0.27f - kb);
    return sstep(-0.005f, 0.02f, score) * sstep(0.02f, 0.05f, kg - kb);
}

// ---- texture decoding (level 0 of the game's formats: BGRA8, BC1, BC2, BC3) into a small RGBA thumbnail
struct Thumb {
    uint32_t w = 0, h = 0;
    std::vector<uint8_t> rgba;         // w x h x 4
    std::vector<uint8_t> blur;         // the same, box-blurred over 5x5 (the local mean: the grass test's input)
    float frac = 0;                    // the share of (blurred) texels that read as grass
    // the texel at (u, v) (wrapped), 0..1
    void at(float u, float v, float out[4]) const
    {
        u -= floorf(u), v -= floorf(v);
        uint32_t x = (uint32_t)(u * w), y = (uint32_t)(v * h);
        x = x < w ? x : w - 1, y = y < h ? y : h - 1;
        const uint8_t* c = &rgba[((size_t)y * w + x) * 4];
        for (int k = 0; k < 4; k++)
            out[k] = c[k] / 255.0f;
    }
    void atBlur(float u, float v, float out[4]) const
    {
        u -= floorf(u), v -= floorf(v);
        uint32_t x = (uint32_t)(u * w), y = (uint32_t)(v * h);
        x = x < w ? x : w - 1, y = y < h ? y : h - 1;
        const uint8_t* c = &blur[((size_t)y * w + x) * 4];
        for (int k = 0; k < 4; k++)
            out[k] = c[k] / 255.0f;
    }
};

void decode565(uint16_t c, int* o)
{
    o[0] = ((c >> 11) & 31) * 255 / 31;
    o[1] = ((c >> 5) & 63) * 255 / 63;
    o[2] = (c & 31) * 255 / 31;
}

// a 4x4 block: the colour half at b + 8 (BC2/BC3) or b (BC1), the alpha half at b (BC2 explicit, BC3 interpolated)
void decodeBlock(const uint8_t* blk, uint32_t format, uint8_t out[16][4])
{
    const uint8_t* b = format == kSinkBC1 ? blk : blk + 8;
    bool bc1 = format == kSinkBC1;
    uint16_t c0 = (uint16_t)(b[0] | b[1] << 8), c1 = (uint16_t)(b[2] | b[3] << 8);
    int p[4][4];
    decode565(c0, p[0]);
    decode565(c1, p[1]);
    p[0][3] = p[1][3] = p[2][3] = p[3][3] = 255;
    for (int k = 0; k < 3; k++) {
        if (!bc1 || c0 > c1) {
            p[2][k] = (2 * p[0][k] + p[1][k]) / 3;
            p[3][k] = (p[0][k] + 2 * p[1][k]) / 3;
        } else {
            p[2][k] = (p[0][k] + p[1][k]) / 2;
            p[3][k] = 0;
        }
    }
    if (bc1 && c0 <= c1)
        p[3][3] = 0;
    uint32_t sel = (uint32_t)b[4] | (uint32_t)b[5] << 8 | (uint32_t)b[6] << 16 | (uint32_t)b[7] << 24;
    for (int i = 0; i < 16; i++) {
        int s = (sel >> (2 * i)) & 3;
        for (int k = 0; k < 4; k++)
            out[i][k] = (uint8_t)p[s][k];
    }
    if (format == kSinkBC2) {
        for (int i = 0; i < 16; i++)
            out[i][3] = (uint8_t)(((blk[i / 2] >> (4 * (i & 1))) & 15) * 17);
    } else if (format == kSinkBC3) {
        int a[8] = {blk[0], blk[1]};
        for (int k = 2; k < 8; k++)
            a[k] = a[0] > a[1] ? ((8 - k) * a[0] + (k - 1) * a[1]) / 7
                               : k < 6 ? ((6 - k) * a[0] + (k - 1) * a[1]) / 5 : (k == 6 ? 0 : 255);
        uint64_t bits = 0;
        for (int k = 0; k < 6; k++)
            bits |= (uint64_t)blk[2 + k] << (8 * k);
        for (int i = 0; i < 16; i++)
            out[i][3] = (uint8_t)a[(bits >> (3 * i)) & 7];
    }
}

// level 0 into a thumbnail of at most kThumb on a side (box filtered); false: not a format we read
enum { kThumb = 64 };
bool makeThumb(uint32_t format, uint32_t w, uint32_t h, const uint8_t* d, uint32_t size, Thumb& t)
{
    if (!w || !h || !d)
        return false;
    uint32_t tw = w < kThumb ? w : kThumb, th = h < kThumb ? h : kThumb;
    std::vector<uint32_t> acc((size_t)tw * th * 5, 0);
    uint32_t grassy = 0, n = 0;
    auto add = [&](uint32_t x, uint32_t y, const uint8_t* c) {
        uint32_t* a = &acc[((size_t)(y * th / h) * tw + x * tw / w) * 5];
        for (int k = 0; k < 4; k++)
            a[k] += c[k];
        a[4]++;
        n++;
        grassy += grassiness(c[0] / 255.0f, c[1] / 255.0f, c[2] / 255.0f) > 0.5f;
    };
    if (format == kSinkBGRA8) {
        if (size < w * h * 4)
            return false;
        uint32_t step = (w * h > 65536) ? 2 : 1;
        for (uint32_t y = 0; y < h; y += step)
            for (uint32_t x = 0; x < w; x += step) {
                const uint8_t* p = d + ((size_t)y * w + x) * 4;
                uint8_t c[4] = {p[2], p[1], p[0], p[3]};
                add(x, y, c);
            }
    } else if (format == kSinkBC1 || format == kSinkBC2 || format == kSinkBC3) {
        uint32_t bw = (w + 3) / 4, bh = (h + 3) / 4, bs = format == kSinkBC1 ? 8 : 16;
        if (size < bw * bh * bs)
            return false;
        uint32_t step = (bw * bh > 8192) ? 2 : 1;
        uint8_t px[16][4];
        for (uint32_t by = 0; by < bh; by += step)
            for (uint32_t bx = 0; bx < bw; bx += step) {
                decodeBlock(d + ((size_t)by * bw + bx) * bs, format, px);
                for (int i = 0; i < 16; i++) {
                    uint32_t x = bx * 4 + (i & 3), y = by * 4 + (i >> 2);
                    if (x < w && y < h)
                        add(x, y, px[i]);
                }
            }
    } else {
        return false;
    }
    t.w = tw, t.h = th;
    t.rgba.assign((size_t)tw * th * 4, 0);
    for (size_t i = 0; i < (size_t)tw * th; i++)
        for (int k = 0; k < 4; k++)
            t.rgba[i * 4 + k] = (uint8_t)(acc[i * 5 + 4] ? acc[i * 5 + k] / acc[i * 5 + 4] : 0);
    // the local mean (a lawn texture's dark gaps between its blades are not paths): 5x5, wrapped
    t.blur.assign(t.rgba.size(), 0);
    grassy = 0;
    for (uint32_t y = 0; y < th; y++)
        for (uint32_t x = 0; x < tw; x++) {
            uint32_t sum[4] = {0, 0, 0, 0};
            for (int dy = -2; dy <= 2; dy++)
                for (int dx = -2; dx <= 2; dx++) {
                    const uint8_t* c = &t.rgba[(((y + th + dy) % th) * tw + (x + tw + dx) % tw) * 4];
                    for (int k = 0; k < 4; k++)
                        sum[k] += c[k];
                }
            uint8_t* o = &t.blur[((size_t)y * tw + x) * 4];
            for (int k = 0; k < 4; k++)
                o[k] = (uint8_t)(sum[k] / 25);
            grassy += grassiness(o[0] / 255.0f, o[1] / 255.0f, o[2] / 255.0f) > 0.5f;
        }
    t.frac = (float)grassy / ((float)tw * th);
    (void)n;
    return true;
}

// ---- deterministic hashing (no state: the same lawn gets the same clumps)
inline uint32_t hash32(uint32_t x)
{
    x ^= x >> 16;
    x *= 0x7feb352du;
    x ^= x >> 15;
    x *= 0x846ca68bu;
    x ^= x >> 16;
    return x;
}
inline float unit(uint32_t h) { return (h >> 8) * (1.0f / 16777216.0f); }
inline uint32_t quant(float v) { return (uint32_t)(int32_t)floorf(v * 16.0f); }

struct Vtx {
    float pos[3];
    float uv[4][2];
    uint32_t colour;                   // D3DCOLOR as in memory (B, G, R, A)
};
struct VBuf {
    uint32_t owner = 0, writes = 0, lastFrame = 0;
    std::shared_ptr<const std::vector<Vtx>> v;     // (shared with a build on the worker)
};

// one clump: root (world) + rank, colour + seed, the surface alone (i_data0..2)
struct Inst {
    float pos[3];
    float rank;
    float col[3];
    float seed;
    float surf[3];
    float pad;
};
struct Cell {
    uint32_t start, count;
    float lo[3], hi[3];
};
struct Scatter {
    uint16_t vb = rm::kNoHandle;
    bool pending = false;              // being made on the worker
    uint32_t serial = 0;
    std::vector<Cell> cells;
    uint32_t total = 0;
    uint32_t vbuf = 0, ibuf = 0;       // (the sink buffers it was made from: dropped with them)
};

struct Settings {
    float nearD, farD, density, height, width;
    int blades;
};
// Low: 12 units, 3 blades a clump; High: 24 units, 5 blades
const Settings kLevel[3] = {{0, 0, 0, 0, 0, 0}, {5.0f, 12.0f, 7.0f, 0.32f, 0.05f, 3}, {9.0f, 24.0f, 12.0f, 0.34f, 0.045f, 5}};
const float kCell = 8.0f;
const uint32_t kMaxPerBuffer = 400000;

class GrassPass;
GrassPass* s_pass;

class GrassPass final : public rm::Pass {
    struct Job;
  public:
    GrassPass() { s_pass = this; }
    const char* name() const override { return "grass"; }
    // (after the window interiors, 3, which also draw from the next hook; before the shadows' casters and the
    // lighting pass, 10, which set state for the next draw)
    int order() const override { return 4; }
    void settingsChanged(const rm::Settings& s) override
    {
        int level = s[rm::kGrass];
        if (level < 0 || level > 2)
            level = 0;
        if (level != m_level) {
            fprintf(stderr, "hulk-app: grass %s\n", level == 0 ? "original" : level == 1 ? "blades low" : "blades high");
            if (level != m_level)
                dropScatters();               // (the density differs)
        }
        m_level = level;
        m_set = kLevel[level];
        // HULK_GRASS=near,far,density,height,width,wind (development tuning)
        if (const char* e = getenv("HULK_GRASS"))
            sscanf(e, "%f,%f,%f,%f,%f,%f", &m_set.nearD, &m_set.farD, &m_set.density, &m_set.height, &m_set.width,
                   &m_wind);
    }
    // ---- the ground's data as the game writes it
    void textureCreated(uint32_t vid, const SinkTextureDesc& d) override
    {
        TexInfo& t = m_tex[vid];
        t = TexInfo{};
        t.ordinal = d.ordinal;
        t.format = d.format;
        t.w = d.width, t.h = d.height;
        m_thumbs.erase(d.ordinal);
        m_texSerial[d.ordinal] = ++m_serial;
    }
    void textureLevel(uint32_t vid, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t size) override
    {
        if (level != 0)
            return;
        auto it = m_tex.find(vid);
        if (it == m_tex.end())
            return;
        if (!data || !size)
            return;
        // (decoded on the worker: the game's upload goes on)
        auto j = std::make_shared<Job>();
        j->kind = Job::kThumb;
        j->ordinal = it->second.ordinal;
        j->serial = m_texSerial[j->ordinal] = ++m_serial;
        j->format = it->second.format, j->w = w, j->h = h;
        j->bytes.assign((const uint8_t*)data, (const uint8_t*)data + size);
        m_thumbs.erase(j->ordinal);
        submit(j);
    }
    void textureDropped(uint32_t vid) override
    {
        auto it = m_tex.find(vid);
        if (it == m_tex.end())
            return;
        m_thumbs.erase(it->second.ordinal);
        m_texSerial.erase(it->second.ordinal);
        m_tex.erase(it);
    }
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        dropScattersOf(sinkBuffer, false);
        if (!d.vertices || !d.count || !d.owner || d.primKind > 1) {
            m_vb.erase(sinkBuffer);
            return;
        }
        VBuf& b = m_vb[sinkBuffer];
        // (written in frame after frame: a dynamic buffer, not a room; a room's buffer may be written several times
        // while it loads)
        if (b.owner == d.owner && b.lastFrame + 1 >= m_frameNo && b.lastFrame != m_frameNo) {
            if (++b.writes >= 3) {
                b.v.reset();
                b.lastFrame = m_frameNo;
                return;
            }
        } else if (b.owner != d.owner || b.lastFrame + 1 < m_frameNo) {
            b.writes = 0;
        }
        b.lastFrame = m_frameNo;
        b.owner = d.owner;
        auto v = std::make_shared<std::vector<Vtx>>(d.count);
        for (uint32_t i = 0; i < d.count; i++) {
            const SinkVertex& s = d.vertices[i];
            memcpy((*v)[i].pos, s.pos, sizeof s.pos);
            memcpy((*v)[i].uv, s.uv, sizeof s.uv);
            (*v)[i].colour = s.colour0;
        }
        b.v = std::move(v);
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        m_vb.erase(sinkBuffer);
        dropScattersOf(sinkBuffer, false);
    }
    void indices(uint32_t sinkIndexBuffer, const uint16_t* idx, uint32_t n) override
    {
        dropScattersOf(sinkIndexBuffer, true);
        if (!idx || !n) {
            m_ib.erase(sinkIndexBuffer);
            return;
        }
        m_ib[sinkIndexBuffer] = std::make_shared<const std::vector<uint16_t>>(idx, idx + n);
    }
    void indicesDropped(uint32_t sinkIndexBuffer) override
    {
        m_ib.erase(sinkIndexBuffer);
        dropScattersOf(sinkIndexBuffer, true);
    }

    // ---- the draws
    // (the combiner keys by hash: a draw an interpolated display rate replays has its key cleared, its hash kept)
    void packet(DrawPacket& p) override
    {
        if (p.combinerKey && *p.combinerKey && p.combinerHash && !m_keys.count(p.combinerHash))
            m_keys[p.combinerHash] = p.combinerKey;
    }
    void draw(const DrawPacket& p) override
    {
        flush();
        if (!m_level || p.viewMode != 0 || p.query != kSinkNone || !p.vertexConstants)
            return;
        pusher(p);
        if (!ground(p))
            return;
        if (m_abOff) {                                  // (cost turns: a lawn drawn, its blades not)
            auto it = m_scatters.find(key(p));
            m_lawnFrame += it != m_scatters.end() && it->second.total;
            return;
        }
        keep(p);
    }
    void passSet(uint16_t, const SinkPass&) override { flush(); }
    void copy(uint16_t, const SinkTarget&) override { flush(); }
    void fx(const FxPacket&) override { flush(); }
    void postScene(const rm::Scene&, uint16_t&) override
    {
        flush();
        // this frame's characters into world space by its view: they bend the grass from the next frame on
        m_pushers.clear();
        if (m_haveView) {
            for (const Push& c : m_found) {
                Push w;
                float d[3] = {c.p[0] - m_view[0][3], c.p[1] - m_view[1][3], c.p[2] - m_view[2][3]};
                for (int i = 0; i < 3; i++)
                    w.p[i] = m_view[0][i] * d[0] + m_view[1][i] * d[1] + m_view[2][i] * d[2];
                m_pushers.push_back(w);
            }
        }
        m_found.clear();
        m_haveView = false;
    }
    void frame() override
    {
        m_frameNo++;
        collect();
        abCost();
        if (logOn() && ++m_frames % 300 == 0) {
            size_t vbMem = 0;
            for (auto& kv : m_vb)
                vbMem += kv.second.v ? kv.second.v->size() * sizeof(Vtx) : 0;
            fprintf(stderr, "hulk-app: grass: %.1f ground draws, %.1f cells, %.0f clumps a frame; %zu lawns (%u "
                    "clumps, %.1f MB), %zu grassy textures of %zu, buffers kept %.1f MB\n", m_groundDraws / 300.0,
                    m_cellDraws / 300.0, m_clumps / 300.0, m_scatters.size(), m_totalClumps,
                    m_totalClumps * sizeof(Inst) / 1048576.0, grassyCount(), m_thumbs.size(),
                    vbMem / 1048576.0);
            m_groundDraws = m_cellDraws = m_clumps = 0;
            if (logOn() >= 3) {
                std::vector<std::pair<uint32_t, uint32_t>> v;
                for (auto& kv : m_roomStats)
                    v.push_back({kv.second.draws, kv.first});
                std::sort(v.rbegin(), v.rend());
                for (size_t i = 0; i < v.size() && i < 40; i++) {
                    auto f = m_thumbs.find(v[i].second);
                    fprintf(stderr, "hulk-app: grass: room texture %u: %u draws, %s, %.0f%% grass%s\n", v[i].second,
                            v[i].first, m_roomStats[v[i].second].buffer ? "kept" : "no buffer",
                            f != m_thumbs.end() ? 100.0f * f->second->frac : -1.0f,
                            grassy(v[i].second) ? " (lawn)" : "");
                }
                m_roomStats.clear();
            }
        }
    }

  private:
    struct TexInfo {
        uint32_t ordinal = 0, format = 0, w = 0, h = 0;
    };
    struct Push {
        float p[3];
    };
    static constexpr float kTexMin = 0.15f;        // (a texture is grass ground when this share of it reads as grass)

    // a room draw of the world on grass: unlit fixed function, a world shader, opaque, a prim buffer, its stage-0
    // texture grassy
    bool ground(const DrawPacket& p)
    {
        if (p.vertexProgram != 0 || p.lighting || p.shaderKind < 1 || p.shaderKind > 2 || p.state.blend ||
            !p.state.depthWrite || !p.state.depthTest || p.state.stencil || p.transient != kSinkNone ||
            p.vertexConstantCount < 8 || p.stage[0].texture == kSinkNone || p.state.prim > 1 ||
            !rm::passIsScene(p.pass))
            return false;
        // the room's modelview is the view: take the frame's view (the characters' positions into world space)
        if (!m_haveView) {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 4; j++)
                    m_view[i][j] = p.vertexConstants[4 * i + j];
            m_haveView = true;
        }
        if (logOn() >= 3) {
            RoomStat& r = m_roomStats[p.stage[0].ordinal];
            r.draws++;
            r.buffer = p.vertexBuffer != kSinkNone && m_vb.count(p.vertexBuffer) && m_vb[p.vertexBuffer].v;
        }
        // (a lawn's grass may be its second stage, blended over a base by its alpha)
        return grassy(p.stage[0].ordinal) || (p.stage[1].texture != kSinkNone && grassy(p.stage[1].ordinal));
    }
    bool grassy(uint32_t ordinal) const
    {
        auto t = m_thumbs.find(ordinal);
        return t != m_thumbs.end() && t->second->frac >= kTexMin;
    }
    size_t grassyCount() const
    {
        size_t n = 0;
        for (auto& kv : m_thumbs)
            n += kv.second->frac >= kTexMin;
        return n;
    }
    // a character (the two-sided fixed-function draws: the Hulk, people) bends the grass around its origin
    void pusher(const DrawPacket& p)
    {
        if (p.vertexProgram != 6 || p.state.blend || p.vertexConstantCount < 4 || m_found.size() >= 16)
            return;
        const float* c = p.vertexConstants;
        float o[3] = {c[3], c[7], c[11]};
        if (o[2] <= 0.0f || o[2] > m_set.farD + 10.0f)
            return;
        for (const Push& f : m_found)
            if (fabsf(f.p[0] - o[0]) + fabsf(f.p[1] - o[1]) + fabsf(f.p[2] - o[2]) < 1.0f)
                return;
        Push q;
        memcpy(q.p, o, sizeof o);
        m_found.push_back(q);
    }
    void keep(const DrawPacket& p)
    {
        Scatter* s = scatterFor(p);
        if (!s || !s->total || s->vb == rm::kNoHandle)
            return;
        m_q.view = p.pass;
        m_q.scatter = s;
        uint32_t n = p.vertexConstantCount < 56 ? p.vertexConstantCount : 56;
        memset(m_q.vc, 0, sizeof m_q.vc);
        memcpy(m_q.vc, p.vertexConstants, n * 16);
        memcpy(m_q.frag, p.frag, sizeof m_q.frag);
        m_q.recv = DrawPacket{};                        // (what the night lights ask of a receiver)
        m_q.recv.state = p.state;
        m_q.recv.viewMode = p.viewMode;
        m_q.recv.query = p.query;
        m_pending = true;
        m_groundDraws++;
        m_lawnFrame++;
    }
    uint64_t key(const DrawPacket& p) const
    {
        return (uint64_t)p.vertexBuffer << 48 ^ (uint64_t)(p.indexBuffer & 0xffff) << 32 ^
               (uint64_t)p.count << 8 ^ (uint64_t)p.state.prim << 4 ^ uvSet(p);
    }
    static uint32_t uvSet(const DrawPacket& p)
    {
        if (p.vertexConstantCount < 49)
            return 0;
        float s = p.vertexConstants[48 * 4];        // (texgen of stage 0: the texture coordinate set, < 4)
        return s >= 0.0f && s < 3.5f ? (uint32_t)(s + 0.5f) : 0u;
    }
    Scatter* scatterFor(const DrawPacket& p)
    {
        uint64_t k = key(p);
        auto it = m_scatters.find(k);
        if (it != m_scatters.end())
            return &it->second;
        Scatter& s = m_scatters[k];
        s.vbuf = p.vertexBuffer, s.ibuf = p.indexBuffer;
        s.serial = ++m_serial;
        build(p, k, s);
        return &s;
    }
    // the clumps of a ground draw (once: see the header), made on the worker
    void build(const DrawPacket& p, uint64_t key, Scatter& s)
    {
        auto vi = m_vb.find(p.vertexBuffer);
        if (vi == m_vb.end() || !vi->second.v)
            return;
        auto j = std::make_shared<Job>();
        j->kind = Job::kScatter;
        j->key = key, j->serial = s.serial;
        j->v = vi->second.v;
        if (p.indexBuffer != kSinkNone) {
            auto ii = m_ib.find(p.indexBuffer);
            if (ii == m_ib.end())
                return;
            j->ib = ii->second;
        }
        // the ground's texture stages as the draw samples them (thumbnails, coordinates) and its combiner
        if (!combiner(p, j->cmb))
            return;
        j->count = p.count, j->prim = p.state.prim, j->density = m_set.density;
        j->ordinal = p.stage[0].ordinal;
        auto ki = m_keys.find(p.combinerHash);
        j->key2 = p.combinerKey && *p.combinerKey ? p.combinerKey : ki != m_keys.end() ? ki->second : "?";
        s.pending = true;
        submit(j);
    }
    static void buildScatter(Job& j)
    {
        const std::vector<Vtx>& v = *j.v;
        const std::vector<uint16_t>* ib = j.ib ? j.ib.get() : nullptr;
        const Comb& cmb = j.cmb;
        uint32_t n = ib ? (uint32_t)ib->size() : (uint32_t)v.size();
        if (j.count && j.count < n)
            n = j.count;
        auto vert = [&](uint32_t i) -> int { uint32_t k = ib ? (*ib)[i] : i; return k < v.size() ? (int)k : -1; };
        uint32_t tris = j.prim == 0 ? n / 3 : (n >= 3 ? n - 2 : 0);
        std::vector<Inst>& out = j.out;
        float area = 0;
        uint32_t tried = 0;
        for (int pass = 0; pass < 2; pass++) {
            float dens = j.density;
            if (pass == 1) {
                if (area * dens > kMaxPerBuffer)
                    dens = kMaxPerBuffer / area;
                out.reserve((size_t)(area * dens * 0.6f) + 16);
            }
            for (uint32_t t = 0; t < tris; t++) {
                int a, b, c;
                if (j.prim == 0)
                    a = vert(3 * t), b = vert(3 * t + 1), c = vert(3 * t + 2);
                else
                    a = vert(t), b = vert(t + 1), c = vert(t + 2);
                if (a < 0 || b < 0 || c < 0 || a == b || b == c || a == c)
                    continue;
                const float* p0 = v[a].pos;
                const float* p1 = v[b].pos;
                const float* p2 = v[c].pos;
                float e1[3] = {p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2]};
                float e2[3] = {p2[0] - p0[0], p2[1] - p0[1], p2[2] - p0[2]};
                float nx = e1[1] * e2[2] - e1[2] * e2[1], ny = e1[2] * e2[0] - e1[0] * e2[2],
                      nz = e1[0] * e2[1] - e1[1] * e2[0];
                float len = sqrtf(nx * nx + ny * ny + nz * nz);
                if (len <= 1e-8f || fabsf(ny) < 0.8f * len)
                    continue;                                   // (not level ground)
                float ar = 0.5f * len;
                if (pass == 0) {
                    area += ar;
                    continue;
                }
                // the triangle's own seed: its corners' positions (the same lawn the same clumps at every load)
                uint32_t h = hash32(quant(p0[0]) ^ hash32(quant(p0[1]) ^ hash32(quant(p0[2]) ^
                             hash32(quant(p1[0] + p2[0]) ^ hash32(quant(p1[2] + p2[2]))))));
                float want = ar * dens;
                uint32_t m = (uint32_t)want + (unit(hash32(h ^ 0x9e3779b9u)) < want - floorf(want) ? 1u : 0u);
                for (uint32_t q = 0; q < m; q++) {
                    uint32_t hj = hash32(h + 0x632be5abu * (q + 1));
                    float x = unit(hj), y = unit(hash32(hj ^ 0x85ebca6bu));
                    if (x + y > 1.0f)
                        x = 1.0f - x, y = 1.0f - y;
                    float z = 1.0f - x - y;
                    Inst in;
                    for (int k = 0; k < 3; k++)
                        in.pos[k] = p0[k] + x * e1[k] + y * e2[k];
                    // the ground's colour there: the combiner on the texels under it (the thumbnails at the draw's
                    // coordinates), once with the baked light (the blades' colour) and once with white (the surface
                    // itself, for the grass test: a night tint does not change what is grass)
                    float tex[4][4], texb[4][4];
                    for (int st = 0; st < cmb.n; st++) {
                        const Comb::Stage& cs = cmb.st[st];
                        if (!cs.thumb) {
                            tex[st][0] = tex[st][1] = tex[st][2] = tex[st][3] = 1.0f;
                            memcpy(texb[st], tex[st], sizeof tex[st]);
                            continue;
                        }
                        float uv[2];
                        for (int k = 0; k < 2; k++)
                            uv[k] = z * v[a].uv[cs.set][k] + x * v[b].uv[cs.set][k] + y * v[c].uv[cs.set][k];
                        if (cs.matrix) {
                            float r[2];
                            for (int k = 0; k < 2; k++)
                                r[k] = cs.m[k][0] * uv[0] + cs.m[k][1] * uv[1] + cs.m[k][2];
                            uv[0] = r[0], uv[1] = r[1];
                        }
                        cs.thumb->at(uv[0] * cs.scale[0] + cs.offset[0], uv[1] * cs.scale[1] + cs.offset[1], tex[st]);
                        cs.thumb->atBlur(uv[0] * cs.scale[0] + cs.offset[0], uv[1] * cs.scale[1] + cs.offset[1],
                                         texb[st]);
                    }
                    float dif[4], white[4] = {1, 1, 1, 1};
                    for (int k = 0; k < 4; k++) {
                        int ch = k < 3 ? 2 - k : 3;     // (D3DCOLOR: B, G, R, A in memory)
                        dif[k] = (z * ((v[a].colour >> (8 * ch)) & 255) + x * ((v[b].colour >> (8 * ch)) & 255) +
                                  y * ((v[c].colour >> (8 * ch)) & 255)) / 255.0f;
                    }
                    float surf[4], col[4];
                    tried++;
                    evalComb(cmb, texb, white, surf);
                    for (int k = 0; k < 4; k++)
                        j.mean[0][k] += surf[k], j.mean[1][k] += texb[0][k], j.mean[2][k] += cmb.n > 1 ? texb[1][k] : 0;
                    j.pass0 += grassiness(texb[0][0], texb[0][1], texb[0][2]) >= 0.5f;
                    if (grassiness(surf[0], surf[1], surf[2]) < 0.5f)
                        continue;                               // (a path or a bare patch of the ground)
                    evalComb(cmb, tex, dif, col);
                    in.col[0] = col[0], in.col[1] = col[1], in.col[2] = col[2];
                    evalComb(cmb, tex, white, surf);
                    in.surf[0] = surf[0], in.surf[1] = surf[1], in.surf[2] = surf[2], in.pad = 0;
                    in.rank = unit(hash32(hj ^ 0x27d4eb2fu));
                    in.seed = unit(hash32(hj ^ 0x165667b1u));
                    out.push_back(in);
                }
            }
        }
        j.area = area, j.tried = tried;
        if (out.empty())
            return;
        // cells of kCell units (x, z), each by rank
        auto cellOf = [](const Inst& i) {
            int32_t cx = (int32_t)floorf(i.pos[0] / kCell), cz = (int32_t)floorf(i.pos[2] / kCell);
            return (int64_t)cx << 32 ^ (uint32_t)cz;
        };
        std::sort(out.begin(), out.end(), [&](const Inst& a, const Inst& b) {
            int64_t ca = cellOf(a), cb = cellOf(b);
            return ca != cb ? ca < cb : a.rank < b.rank;
        });
        for (uint32_t i = 0; i < out.size();) {
            Cell c;
            c.start = i;
            int64_t id = cellOf(out[i]);
            for (int k = 0; k < 3; k++)
                c.lo[k] = c.hi[k] = out[i].pos[k];
            uint32_t e = i;
            for (; e < out.size() && cellOf(out[e]) == id; e++)
                for (int k = 0; k < 3; k++)
                    c.lo[k] = fminf(c.lo[k], out[e].pos[k]), c.hi[k] = fmaxf(c.hi[k], out[e].pos[k]);
            c.count = e - i;
            j.cells.push_back(c);
            i = e;
        }
    }
    // a finished build: its instance buffer (the main thread)
    void finish(Job& j)
    {
        auto it = m_scatters.find(j.key);
        if (it == m_scatters.end() || it->second.serial != j.serial)
            return;                                     // (dropped while it was made)
        Scatter& s = it->second;
        s.pending = false;
        if (j.out.empty())
            return;
        bgfx::VertexLayout layout;
        layout.begin()
            .add(bgfx::Attrib::TexCoord7, 4, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord6, 4, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord5, 4, bgfx::AttribType::Float)
            .end();
        bgfx::VertexBufferHandle h = bgfx::createVertexBuffer(bgfx::copy(j.out.data(), (uint32_t)(j.out.size() *
                                                                                                    sizeof(Inst))), layout);
        if (!bgfx::isValid(h))
            return;
        s.cells = std::move(j.cells);
        s.vb = h.idx;
        s.total = (uint32_t)j.out.size();
        m_totalClumps += s.total;
        if (logOn())
            fprintf(stderr, "hulk-app: grass: lawn of texture %u (%.0f%% grass): %.0f units^2 level, %u clumps of %u in "
                    "%zu cells (stage 0 alone %u); combiner %s; means surface %.2f %.2f %.2f, stage 0 %.2f %.2f %.2f, "
                    "stage 1 %.2f %.2f %.2f a %.2f\n", j.ordinal, 100.0f * j.cmb.st[0].thumb->frac, j.area, s.total,
                    j.tried, s.cells.size(), j.pass0, j.key2.c_str(), j.mean[0][0] / j.tried, j.mean[0][1] / j.tried,
                    j.mean[0][2] / j.tried, j.mean[1][0] / j.tried, j.mean[1][1] / j.tried, j.mean[1][2] / j.tried,
                    j.mean[2][0] / j.tried, j.mean[2][1] / j.tried, j.mean[2][2] / j.tried, j.mean[2][3] / j.tried);
    }
    // the ground draw's texture stages and combiner (fs_vp_stage.sh: the key "c<op>.<arg1>.<arg2>a<op>.<a1>.<a2>r<res>"
    // per stage, '|' between; args 0 diffuse, 1 current, 2 texture, 3 texture factor, 4 specular, 5 temp, +16
    // complement, +32 alpha replicate; ops Xbox D3DTOP)
    struct Comb {
        struct Stage {
            int cop, c1, c2, aop, a1, a2, res;
            std::shared_ptr<const Thumb> thumb;
            uint32_t set;
            bool matrix;
            float m[2][3];
            float scale[2], offset[2];
        } st[4];
        int n = 0;
        float tf[4];
    };
    bool combiner(const DrawPacket& p, Comb& c) const
    {
        const char* k = p.combinerKey;
        if (!k || !*k) {
            auto it = m_keys.find(p.combinerHash);
            if (it == m_keys.end())
                return false;
            k = it->second.c_str();
        }
        memcpy(c.tf, p.frag[3], sizeof c.tf);
        for (int st = 0; st < 4 && k && *k; st++) {
            Comb::Stage& s = c.st[st];
            if (sscanf(k, "c%d.%d.%da%d.%d.%dr%d", &s.cop, &s.c1, &s.c2, &s.aop, &s.a1, &s.a2, &s.res) < 7)
                return false;
            if (s.cop <= 1)
                break;
            s.thumb = nullptr;
            if (p.stage[st].texture != kSinkNone) {
                auto t = m_thumbs.find(p.stage[st].ordinal);
                if (t == m_thumbs.end())
                    return false;                       // (a texture not classified: its colour is unknown)
                s.thumb = t->second;
            }
            const float* vc = p.vertexConstants;
            float ctl = p.vertexConstantCount > (uint32_t)(48 + st) ? vc[(48 + st) * 4] : 0.0f;
            if (s.thumb && !(ctl >= 0.0f && ctl < 3.5f))
                return false;                           // (generated coordinates: a reflection, not the ground)
            s.set = (uint32_t)(ctl + 0.5f);
            s.matrix = p.vertexConstantCount > (uint32_t)(48 + st) && vc[(48 + st) * 4 + 1] > 0.5f &&
                       p.vertexConstantCount > (uint32_t)(33 + 4 * st);
            if (s.matrix)
                for (int r = 0; r < 2; r++) {
                    const float* row = vc + (32 + 4 * st + r) * 4;
                    s.m[r][0] = row[0], s.m[r][1] = row[1], s.m[r][2] = row[2];   // (u, v, 1, 0)
                }
            s.scale[0] = p.frag[4 + st / 2][(st & 1) * 2], s.scale[1] = p.frag[4 + st / 2][(st & 1) * 2 + 1];
            s.offset[0] = p.frag[14 + st / 2][(st & 1) * 2], s.offset[1] = p.frag[14 + st / 2][(st & 1) * 2 + 1];
            c.n = st + 1;
            k = strchr(k, '|');
            if (k)
                k++;
        }
        return c.n > 0 && c.st[0].thumb;
    }
    static void arg(int a, const float* dif, const float* cur, const float* tex, const float* tf, const float* tmp,
                    float out[4])
    {
        static const float zero[4] = {0, 0, 0, 0};
        int sel = a & 15;
        const float* v = sel == 0 ? dif : sel == 1 ? cur : sel == 2 ? tex : sel == 3 ? tf : sel == 4 ? zero : tmp;
        for (int i = 0; i < 4; i++)
            out[i] = v[i];
        if ((a >> 4) & 1)
            for (int i = 0; i < 4; i++)
                out[i] = 1.0f - out[i];
        if ((a >> 4) > 1)
            for (int i = 0; i < 3; i++)
                out[i] = out[3];
    }
    static float opOne(int op, int i, const float* a1, const float* a2, const float* dif, const float* cur,
                       const float* tex, const float* tf)
    {
        auto mix = [](float x, float y, float t) { return x + (y - x) * t; };
        switch (op) {
        case 2: return a1[i];
        case 3: return a2[i];
        case 4: return a1[i] * a2[i];
        case 5: return a1[i] * a2[i] * 2;
        case 6: return a1[i] * a2[i] * 4;
        case 7: return a1[i] + a2[i];
        case 8: return a1[i] + a2[i] - 0.5f;
        case 9: return (a1[i] + a2[i] - 0.5f) * 2;
        case 10: return a1[i] - a2[i];
        case 11: return a1[i] + a2[i] - a1[i] * a2[i];
        case 12: return mix(a2[i], a1[i], dif[3]);
        case 13: return mix(a2[i], a1[i], cur[3]);
        case 14: return mix(a2[i], a1[i], tex[3]);
        case 15: return mix(a2[i], a1[i], tf[3]);
        case 16: return a1[i] + a2[i] * (1 - tex[3]);
        case 18: return i < 3 ? a1[i] + a2[i] * a1[3] : a1[3];
        case 19: return i < 3 ? a1[i] * a2[i] + a1[3] : a1[3];
        case 20: return i < 3 ? a1[i] + a2[i] * (1 - a1[3]) : a1[3];
        case 21: return i < 3 ? (1 - a1[i]) * a2[i] + a1[3] : a1[3];
        case 23: return cur[i] + a1[i] * a2[i];
        case 24: return cur[i] * a1[i] + (1 - cur[i]) * a2[i];
        default: return a1[i];
        }
    }
    static void evalComb(const Comb& c, const float tex[4][4], const float* dif, float out[4])
    {
        float cur[4], tmp[4] = {0, 0, 0, 0};
        memcpy(cur, dif, sizeof cur);
        auto sat = [](float x) { return x < 0 ? 0 : x > 1 ? 1 : x; };
        for (int st = 0; st < c.n; st++) {
            const Comb::Stage& s = c.st[st];
            float c1[4], c2[4], a1[4], a2[4], r[4];
            arg(s.c1, dif, cur, tex[st], c.tf, tmp, c1);
            arg(s.c2, dif, cur, tex[st], c.tf, tmp, c2);
            arg(s.a1, dif, cur, tex[st], c.tf, tmp, a1);
            arg(s.a2, dif, cur, tex[st], c.tf, tmp, a2);
            for (int i = 0; i < 3; i++)
                r[i] = sat(opOne(s.cop, i, c1, c2, dif, cur, tex[st], c.tf));
            r[3] = s.aop <= 1 ? cur[3] : sat(opOne(s.aop, 3, a1, a2, dif, cur, tex[st], c.tf));
            memcpy(s.res > 2 ? tmp : cur, r, sizeof r);
        }
        memcpy(out, cur, sizeof cur);
    }
    // ---- the worker: texture thumbnails and lawns are made off the runner's thread, handed back at frame ends
    struct Job {
        enum Kind { kThumb, kScatter } kind;
        uint32_t serial = 0, ordinal = 0;
        // kThumb: the level's bytes in, the thumbnail out
        uint32_t format = 0, w = 0, h = 0;
        std::vector<uint8_t> bytes;
        std::shared_ptr<Thumb> thumb;
        // kScatter: the ground draw in, the clumps and cells out
        uint64_t key = 0;
        std::shared_ptr<const std::vector<Vtx>> v;
        std::shared_ptr<const std::vector<uint16_t>> ib;
        Comb cmb;
        uint32_t count = 0, prim = 0;
        float density = 0;
        std::string key2;
        std::vector<Inst> out;
        std::vector<Cell> cells;
        float area = 0;
        uint32_t tried = 0;
        double mean[3][4] = {};            // (the log: the surface, stage 0, stage 1 means; stage 0's own pass count)
        uint32_t pass0 = 0;
    };
    struct Queue {
        std::mutex m;
        std::condition_variable cv;
        std::deque<std::shared_ptr<Job>> todo, done;
    };
    // (never freed: the worker may still hold it while the process exits)
    static Queue& queue()
    {
        static Queue* q = new Queue;
        return *q;
    }
    static void work()
    {
        Queue& q = queue();
        for (;;) {
            std::shared_ptr<Job> j;
            {
                std::unique_lock<std::mutex> l(q.m);
                q.cv.wait(l, [&] { return !q.todo.empty(); });
                j = q.todo.front();
                q.todo.pop_front();
            }
            if (j->kind == Job::kThumb) {
                auto t = std::make_shared<Thumb>();
                if (makeThumb(j->format, j->w, j->h, j->bytes.data(), (uint32_t)j->bytes.size(), *t))
                    j->thumb = t;
                j->bytes.clear();
                j->bytes.shrink_to_fit();
            } else {
                buildScatter(*j);
                j->v.reset();
                j->ib.reset();
            }
            std::lock_guard<std::mutex> l(q.m);
            q.done.push_back(j);
        }
    }
    void submit(const std::shared_ptr<Job>& j)
    {
        static bool started;
        if (!started) {
            std::thread(work).detach();
            started = true;
        }
        Queue& q = queue();
        {
            std::lock_guard<std::mutex> l(q.m);
            q.todo.push_back(j);
        }
        q.cv.notify_one();
    }
    // the finished jobs (frame ends)
    void collect()
    {
        Queue& q = queue();
        std::deque<std::shared_ptr<Job>> done;
        {
            std::lock_guard<std::mutex> l(q.m);
            done.swap(q.done);
        }
        for (auto& j : done) {
            if (j->kind == Job::kThumb) {
                auto it = m_texSerial.find(j->ordinal);
                if (it == m_texSerial.end() || it->second != j->serial || !j->thumb)
                    continue;
                if (logOn() >= 2 && j->thumb->frac > 0.05f)
                    fprintf(stderr, "hulk-app: grass: texture %u (%ux%u fmt %u) %.0f%% grass\n", j->ordinal, j->w, j->h,
                            j->format, 100.0f * j->thumb->frac);
                m_thumbs[j->ordinal] = j->thumb;
            } else {
                finish(*j);
            }
        }
    }
    void dropScatter(Scatter& s)
    {
        if (s.vb != rm::kNoHandle)
            bgfx::destroy(bgfx::VertexBufferHandle{s.vb});
        m_totalClumps -= s.total;
        s.vb = rm::kNoHandle;
        s.total = 0;
    }
    void dropScatters()
    {
        m_pending = false;
        for (auto& kv : m_scatters)
            dropScatter(kv.second);
        m_scatters.clear();
    }
    void dropScattersOf(uint32_t buffer, bool index)
    {
        if (m_pending && (index ? m_q.scatter->ibuf : m_q.scatter->vbuf) == buffer)
            flush();
        for (auto it = m_scatters.begin(); it != m_scatters.end();)
            if ((index ? it->second.ibuf : it->second.vbuf) == buffer) {
                dropScatter(it->second);
                it = m_scatters.erase(it);
            } else {
                ++it;
            }
    }

    bool mesh()
    {
        if (m_meshBlades == m_set.blades && m_meshVb != rm::kNoHandle)
            return true;
        if (m_meshVb != rm::kNoHandle) {
            bgfx::destroy(bgfx::VertexBufferHandle{m_meshVb});
            bgfx::destroy(bgfx::IndexBufferHandle{m_meshIb});
            m_meshVb = m_meshIb = rm::kNoHandle;
        }
        // a blade: 3 segments (pairs at 0, 1/3, 2/3) and a tip; each blade of the clump its own angle, offset, lean
        // and height
        struct MV { float pos[3]; float blade[3]; };
        std::vector<MV> vs;
        std::vector<uint16_t> is;
        int nb = m_set.blades > 0 ? m_set.blades : 3;
        for (int b = 0; b < nb; b++) {
            uint32_t h = hash32(0x51ed27u + b * 7919u);
            float ang = 6.2831853f * (b + 0.35f * unit(h)) / nb;
            float off = 0.03f + 0.09f * unit(hash32(h ^ 1));
            float lean = 0.15f + 0.35f * unit(hash32(h ^ 2));
            float ht = 0.7f + 0.3f * unit(hash32(h ^ 3));
            uint16_t base = (uint16_t)vs.size();
            for (int s = 0; s < 3; s++) {
                float t = s / 3.0f;
                vs.push_back({{-1.0f, t, ang}, {off, lean, ht}});
                vs.push_back({{1.0f, t, ang}, {off, lean, ht}});
            }
            vs.push_back({{0.0f, 1.0f, ang}, {off, lean, ht}});
            for (int s = 0; s < 2; s++) {
                uint16_t q = (uint16_t)(base + 2 * s);
                uint16_t t[6] = {q, (uint16_t)(q + 1), (uint16_t)(q + 2), (uint16_t)(q + 1), (uint16_t)(q + 3),
                                 (uint16_t)(q + 2)};
                is.insert(is.end(), t, t + 6);
            }
            uint16_t t[3] = {(uint16_t)(base + 4), (uint16_t)(base + 5), (uint16_t)(base + 6)};
            is.insert(is.end(), t, t + 3);
        }
        bgfx::VertexLayout layout;
        layout.begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
            .end();
        bgfx::VertexBufferHandle v = bgfx::createVertexBuffer(bgfx::copy(vs.data(), (uint32_t)(vs.size() * sizeof(MV))),
                                                              layout);
        bgfx::IndexBufferHandle i = bgfx::createIndexBuffer(bgfx::copy(is.data(), (uint32_t)(is.size() * 2)));
        if (!bgfx::isValid(v) || !bgfx::isValid(i))
            return false;
        m_meshVb = v.idx, m_meshIb = i.idx;
        m_meshBlades = m_set.blades;
        return true;
    }
    // the kept ground draw's clumps, in its view after it
    void flush()
    {
        if (!m_pending)
            return;
        m_pending = false;
        if (!mesh())                              // (bgfx draws instances on every renderer it has)
            return;
        uint16_t prog = rm::program("vs_rm_grass", "fs_rm_grass");
        if (prog == rm::kNoHandle)
            return;
        const Scatter& s = *m_q.scatter;
        const float(*c)[4] = m_q.vc;
        // the camera in world space: -R^T t of the view (rows c0..c2)
        float cam[3];
        for (int i = 0; i < 3; i++)
            cam[i] = -(c[0][i] * c[0][3] + c[1][i] * c[1][3] + c[2][i] * c[2][3]);
        // world -> clip (rows), for the cells' frustum test
        float m[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                m[i][j] = c[4 + i][0] * c[0][j] + c[4 + i][1] * c[1][j] + c[4 + i][2] * c[2][j] +
                          (j == 3 ? c[4 + i][3] : 0.0f);
        float range = m_set.farD - m_set.nearD;
        float hmax = m_set.height * 1.5f;
        float g[8][4];
        memset(g, 0, sizeof g);
        g[0][0] = cam[0], g[0][1] = cam[1], g[0][2] = cam[2];
        g[0][3] = (float)fmod(interp_display_time(), 3600.0);
        g[1][0] = m_set.nearD, g[1][1] = m_set.farD, g[1][2] = m_set.height, g[1][3] = m_set.width;
        g[2][0] = 0.8f, g[2][2] = 0.6f, g[2][1] = m_wind, g[2][3] = 0.16f;
        for (size_t i = 0; i < m_pushers.size() && i < 4; i++)
            g[3 + i][0] = m_pushers[i].p[0], g[3 + i][1] = m_pushers[i].p[1], g[3 + i][2] = m_pushers[i].p[2],
            g[3 + i][3] = 1.4f;
        static const int show = getenv("HULK_GRASS_SHOW") ? atoi(getenv("HULK_GRASS_SHOW")) : 0;
        g[7][0] = (float)show;
        // (a blade at least ~0.7 pixels wide: the width scale per unit of distance)
        uint32_t th = hulk_gfx_sink_target_height();
        float py = fabsf(c[5][1]);
        g[7][1] = th && py > 0 ? (1.4f / (py * th)) / (m_set.width > 0 ? m_set.width : 1.0f) : 0.0f;
        uint16_t atlas = rm::kNoHandle;
        const float* sc = rm::shadowConstants(false, &atlas);
        static const float kNoShadow[12][4] = {};
        if (atlas == rm::kNoHandle)
            atlas = rm::shadowDummy();
        if (!bgfx::isValid(m_sShadow))
            m_sShadow = bgfx::createUniform("s_rmShadow", bgfx::UniformType::Sampler);
        const uint64_t state = BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_Z | BGFX_STATE_DEPTH_TEST_LESS;
        for (const Cell& cell : s.cells) {
            // the nearest point of the cell's box
            float dd = 0;
            for (int k = 0; k < 3; k++) {
                float lo = cell.lo[k] - (k == 1 ? 0.0f : 0.5f), hi = cell.hi[k] + (k == 1 ? hmax : 0.5f);
                float e = cam[k] < lo ? lo - cam[k] : cam[k] > hi ? cam[k] - hi : 0.0f;
                dd += e * e;
            }
            float dmin = sqrtf(dd);
            if (dmin >= m_set.farD)
                continue;
            float dens = range > 0 ? (m_set.farD - dmin) / range : 1.0f;
            dens = dens > 1.0f ? 1.0f : dens;
            uint32_t k = (uint32_t)ceilf(cell.count * dens);
            if (!k)
                continue;
            if (!inView(m, cell, hmax))
                continue;
            k = k < cell.count ? k : cell.count;
            rm::uniform("u_vc", &c[0][0], 56);
            rm::uniform("u_pddiFrag", &m_q.frag[0][0], 16);
            rm::uniform("u_rmGrass", &g[0][0], 8);
            rm::uniform("u_rmShadow", sc ? sc : &kNoShadow[0][0], 12);
            if (atlas != rm::kNoHandle)
                bgfx::setTexture(4, m_sShadow, bgfx::TextureHandle{atlas},
                                 BGFX_SAMPLER_COMPARE_LEQUAL | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
            rm::nightLightsBind(m_q.recv);              // (wlook2: stage 5, u_rmCity)
            bgfx::setVertexBuffer(0, bgfx::VertexBufferHandle{m_meshVb});
            bgfx::setIndexBuffer(bgfx::IndexBufferHandle{m_meshIb});
            bgfx::setInstanceDataBuffer(bgfx::VertexBufferHandle{s.vb}, cell.start, k);
            bgfx::setState(state);
            bgfx::submit(m_q.view, bgfx::ProgramHandle{prog});
            m_cellDraws++;
            m_clumps += k;
            m_clumpsFrame += k;
        }
    }
    // a cell's box (grown by the blades' height) is not wholly outside one clip plane
    static bool inView(const float m[4][4], const Cell& c, float hmax)
    {
        int out[6] = {0, 0, 0, 0, 0, 0};
        for (int i = 0; i < 8; i++) {
            float p[3] = {(i & 1) ? c.hi[0] + 0.5f : c.lo[0] - 0.5f, (i & 2) ? c.hi[1] + hmax : c.lo[1],
                          (i & 4) ? c.hi[2] + 0.5f : c.lo[2] - 0.5f};
            float q[4];
            for (int r = 0; r < 4; r++)
                q[r] = m[r][0] * p[0] + m[r][1] * p[1] + m[r][2] * p[2] + m[r][3];
            out[0] += q[0] < -q[3];
            out[1] += q[0] > q[3];
            out[2] += q[1] < -q[3];
            out[3] += q[1] > q[3];
            out[4] += q[2] < 0.0f;
            out[5] += q[2] > q[3];
        }
        for (int k = 0; k < 6; k++)
            if (out[k] == 8)
                return false;
        return true;
    }
    // HULK_GRASS_AB=N: the blades off and on in turns of N presented frames (GPU and render thread a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_GRASS_AB") ? atoi(getenv("HULK_GRASS_AB")) : 0;
        if (n <= 0)
            return;
        const bgfx::Stats* st = bgfx::getStats();
        // (only frames with a lawn's blades in view, or that would have them: the rest cost nothing)
        if (st && m_abFrame > 2 && m_lawnFrame && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin) {
            int k = m_abOff ? 0 : 1;
            m_abGpu[k] += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq;
            m_abCpu[k] += 1e3 * (double)(st->cpuTimeEnd - st->cpuTimeBegin) / (double)st->cpuTimerFreq;
            m_abN[k]++;
            if (!m_abOff)
                m_abClumps += m_clumpsFrame;
        }
        m_clumpsFrame = 0;
        m_lawnFrame = 0;
        if (++m_abFrame >= (unsigned)n) {
            m_abFrame = 0;
            m_abOff = !m_abOff;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: grass cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames with lawns in view, %.0f clumps a frame on, %ux%u)\n", m_abGpu[0] / m_abN[0],
                        m_abGpu[1] / m_abN[1], m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        m_abClumps / m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0}, m_abClumps = 0, m_clumpsFrame = 0;
    unsigned m_lawnFrame = 0;

    int m_level = 0;
    Settings m_set = kLevel[0];
    float m_wind = 0.12f;
    std::unordered_map<uint32_t, TexInfo> m_tex;           // texture vid -> what it is
    std::unordered_map<uint32_t, std::shared_ptr<const Thumb>> m_thumbs;   // every texture's thumbnail by ordinal
    std::unordered_map<uint32_t, uint32_t> m_texSerial;    // the newest thumbnail asked for, by ordinal
    uint32_t m_serial = 0;
    struct RoomStat { uint32_t draws = 0; bool buffer = false; };
    std::unordered_map<uint32_t, RoomStat> m_roomStats;
    std::unordered_map<uint32_t, VBuf> m_vb;               // sink vertex buffer -> its vertices
    std::unordered_map<uint32_t, std::shared_ptr<const std::vector<uint16_t>>> m_ib;
    std::unordered_map<uint64_t, Scatter> m_scatters;
    std::unordered_map<uint32_t, std::string> m_keys;      // combiner hash -> key
    uint32_t m_totalClumps = 0;
    struct Pending {
        uint16_t view;
        Scatter* scatter;
        float vc[56][4];
        float frag[16][4];
        DrawPacket recv;
    } m_q;
    bool m_pending = false;
    uint16_t m_meshVb = rm::kNoHandle, m_meshIb = rm::kNoHandle;
    int m_meshBlades = 0;
    bgfx::UniformHandle m_sShadow = BGFX_INVALID_HANDLE;
    bool m_haveView = false;
    float m_view[3][4];
    std::vector<Push> m_found, m_pushers;
    unsigned m_frames = 0;
    uint32_t m_frameNo = 2;
    double m_groundDraws = 0, m_cellDraws = 0, m_clumps = 0;
};
HULK_RM_REGISTER_PASS(GrassPass);

} // namespace
