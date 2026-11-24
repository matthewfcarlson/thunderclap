// Night lights (wlook2, docs/night.md; Video Options > Night Lights: Off (Original) / On).
//
// The night city's light sources are in the game's own draw stream: street lamps, signs and vehicle lights carry
// additive glow sprites and small additive meshes (blended one/one or src-alpha/one, unlit, depth tested), which the
// game draws after the world's opaque traversal. This pass finds them as each presented frame is drawn (no game state
// is read), keeps them in world space, and hands the per-pixel lighting (lighting.cpp, fs_px_stage.sh) a list of the
// frame's lights in a small data texture with a per-screen-tile index (tiled forward lighting: each pixel loops only
// over the lights whose sphere covers its tile), so the ground, walls, cars and characters around a lamp take its light:
// pools on the streets under the lamps, spill on the facades, a glow around headlights. The atmosphere pass
// (atmosphere.cpp) reads the same list for the lamps' in-scattering in the night mist.
//
// Steady frame to frame (wpol1's lesson: identify by mesh and texture, never by draw adjacency): every glow is a light
// by itself; a light found again within a small distance of a known one is the same light, a light that stays put is
// static and outlives frames in which its glow is off screen (a lamp's pool stays while its head is above the picture),
// a moving one (a car's) lives only while drawn, and every light fades in and out over a few frames.
//
// wlook4 adds two kinds the game draws no glow for (docs/night.md section 4): shop fronts, segment lights along the foot
// of building facades whose glass (the facade's alpha) is lit, read once per building buffer; and headlights, a cone
// at the other end of every car whose tail light glows are drawn (tail lights become backward spots).
//
// Output only: nothing here reads or writes the module's memory; lights are render state rebuilt from the stream.
#include "nightlights.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "texpack.h"

using namespace hulk::pddi;

namespace {

const uint16_t kInvalid = 0xffff;
#if defined(__ANDROID__)
enum { kMaxLights = 64, kPerTile = 8, kMaxShop = 20 };     // (handheld budget: fewer lights, 8 a tile)
#else
enum { kMaxLights = 128, kPerTile = 24, kMaxShop = 56 };
#endif
enum { kTex = 64, kMaxTilesX = 32, kMaxTilesY = 32, kTexelsPerLight = 3 };
// kinds (rm_city.sh): a point light; a lamp (mostly downwards); a spot (wlook4: headlights and tail lights, the third
// texel its direction and outer cone cosine); a shop front (wlook4: a segment along a facade's foot, the third texel
// its half axis)
enum Kind { kPoint = 0, kLamp = 1, kSpot = 2, kLine = 3 };
enum CarLight { kNoCar = 0, kHead = 1, kTail = 2 };
// a light that stays within this of where it was first seen is static (a halo sprite pulled towards the camera wobbles
// by ~0.6 units as the camera moves; cars move metres a frame)
const float kStill = 1.0f;

int envInt(const char* name)
{
    const char* e = getenv(name);
    return e ? atoi(e) : 0;
}

struct Cached {
    float pos[3];               // world space
    float size;                 // the glow's world size (diameter)
    float colour[3];            // hue x brightness (0..1 per channel)
    uint32_t firstSeen, lastSeen, seen;
    float origin[3];            // where it was first seen (static test)
    float moved;                // the largest displacement from origin
    float fade;                 // 0..1
    uint32_t texture;           // the glow's texture ordinal (identity)
    bool dying;
    // wlook4: a vehicle's light: which, and its direction (world space, unit); the light's motion a frame
    int car;
    float dir[3];
    float vel[3];
    float front[3];             // a tail light's headlight (the car's other end), world space
    bool hasFront;
};

class NightLightsPass final : public rm::Pass {
    struct Found;
  public:
    const char* name() const override { return "nightlights"; }
    int order() const override { return 6; }       // (before the lighting pass's draw hook: its programs bind ours)
    void settingsChanged(const rm::Settings& s) override
    {
        int on = s[rm::kNightLights] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: night lights %s\n", on ? "on" : "off");
        m_on = on;
        // HULK_NIGHT=strength,radiusScale,minRadius,maxRadius,dayStrength,warm (development tuning)
        if (const char* e = getenv("HULK_NIGHT"))
            sscanf(e, "%f,%f,%f,%f,%f,%f", &m_strength, &m_radiusScale, &m_minR, &m_maxR, &m_dayStrength, &m_warm);
        if (const char* e = getenv("HULK_NIGHT_CARS"))
            sscanf(e, "%f,%f,%f,%f,%f,%f", &m_headK, &m_headR, &m_headCos, &m_headTilt, &m_tailK, &m_tailR);
        if (const char* e = getenv("HULK_NIGHT_SHOPS"))
            sscanf(e, "%f,%f,%f,%f,%f", &m_shopK, &m_shopR, &m_shopFar, &m_shopLit, &m_shopHeight);
        if (!m_on)
            m_cache.clear(), m_count = 0;
    }
    void late(DrawPacket& p) override
    {
        if (p.viewMode != 0)
            return;                                 // (the camera and fog are tracked with the pass off too: atmosphere.cpp)
        if (!m_haveView && takeView(p)) {
            dumpOn(p.frame);
            m_haveView = m_viewKnown = true;
            m_worldPass = rm::currentGamePass();
            place();
        } else if (!m_haveView && !m_placed && m_viewKnown) {
            place();                                // (the draws before the frame's first world draw: the last camera)
        }
        if (!p.state.blend && p.state.depthWrite && p.fog && p.vertexProgram == 0 && !p.lighting &&
            (p.shaderKind == 1 || p.shaderKind == 2) && rm::currentGamePass() == m_worldPass)
            m_fogSum[0] += p.frag[1][0], m_fogSum[1] += p.frag[1][1], m_fogSum[2] += p.frag[1][2], m_fogN++;
        if (m_haveView && m_on && !m_abOff) {
            car(p);
            building(p);
            source(p);
        }
    }
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (!d.count || !d.vertices || !d.owner)
            return;
        float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
        double col[3] = {0, 0, 0};
        for (uint32_t i = 0; i < d.count; i++) {
            for (int k = 0; k < 3; k++)
                lo[k] = fminf(lo[k], d.vertices[i].pos[k]), hi[k] = fmaxf(hi[k], d.vertices[i].pos[k]);
            uint32_t c = d.vertices[i].colour0;           // (D3DCOLOR: b g r a in memory)
            col[0] += (c >> 16 & 255) / 255.0, col[1] += (c >> 8 & 255) / 255.0, col[2] += (c & 255) / 255.0;
        }
        Bounds& b = m_bounds[sinkBuffer];
        memcpy(b.lo, lo, sizeof lo), memcpy(b.hi, hi, sizeof hi);
        if (d.count <= 512) {
            Small s;
            for (int k = 0; k < 3; k++)
                s.c[k] = 0.5f * (lo[k] + hi[k]), s.size = fmaxf(s.size, hi[k] - lo[k]),
                s.col[k] = (float)(col[k] / d.count);
            m_small[d.owner] = s;
        }
        m_ownerOf[sinkBuffer] = d.owner;
        // wlook4: the geometry of buffers written once (rooms, buildings: their shop fronts), positions and two uv sets;
        // a buffer written frame after frame is dynamic and kept out
        dropShops(sinkBuffer, false);
        Geo& g = m_geo[sinkBuffer];
        bool again = g.owner == d.owner && g.lastFrame + 1 >= m_present && g.lastFrame != m_present;
        g.writes = again ? g.writes + 1 : 0;
        g.owner = d.owner, g.lastFrame = m_present;
        if (g.writes >= 2 || d.count < 6) {
            g.v.reset();
            return;
        }
        auto v = std::make_shared<std::vector<GeoVtx>>(d.count);
        for (uint32_t i = 0; i < d.count; i++) {
            memcpy((*v)[i].pos, d.vertices[i].pos, sizeof(float) * 3);
            memcpy((*v)[i].uv, d.vertices[i].uv, sizeof(float) * 4);
        }
        g.v = std::move(v);
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        auto it = m_ownerOf.find(sinkBuffer);
        if (it != m_ownerOf.end()) {
            m_small.erase(it->second);
            m_ownerOf.erase(it);
        }
        m_bounds.erase(sinkBuffer);
        m_geo.erase(sinkBuffer);
        dropShops(sinkBuffer, false);
    }
    void indices(uint32_t sinkIndexBuffer, const uint16_t* idx, uint32_t n) override
    {
        dropShops(sinkIndexBuffer, true);
        if (!idx || !n)
            m_ib.erase(sinkIndexBuffer);
        else
            m_ib[sinkIndexBuffer] = std::make_shared<const std::vector<uint16_t>>(idx, idx + n);
    }
    void indicesDropped(uint32_t sinkIndexBuffer) override
    {
        m_ib.erase(sinkIndexBuffer);
        dropShops(sinkIndexBuffer, true);
    }
    void postScene(const rm::Scene&, uint16_t&) override { endFrame(); }
    void frame() override
    {
        abCost();
        if (envInt("HULK_NIGHT_LOG") > 0 && ++m_frames >= 300) {
            fprintf(stderr, "hulk-app: night lights: %.1f sources, %.1f lights placed a frame (%.1f shop fronts, %.1f "
                    "vehicle lights), %zu cached, %.1f cars a frame, %zu shop fronts known, ground %.1f, night %.2f "
                    "(fog %.3f %.3f %.3f)\n", m_srcSum / m_frames, m_placedSum / m_frames, m_shopPlacedSum / m_frames,
                    m_spotSum / m_frames, m_cache.size(), m_carSum / m_frames, m_shopTotal, m_ground, m_night,
                    m_fog[0], m_fog[1], m_fog[2]);
            fprintf(stderr, "hulk-app: night shops: built %u, grid %u, walls %u, edges %u, pieces %u, glass %u; place: "
                    "unlit %u, high %u, far %u, off-screen %u, candidates %u\n", m_dbg[0], m_dbg[1], m_dbg[2], m_dbg[3],
                    m_dbg[4], m_dbg[5], m_dbg[6], m_dbg[7], m_dbg[8], m_dbg[9], m_dbg[10]);
            memset(m_dbg, 0, sizeof m_dbg);
            m_frames = 0, m_srcSum = m_placedSum = m_shopPlacedSum = m_spotSum = m_carSum = 0;
        }
    }

    // ---- for lighting.cpp and atmosphere.cpp
    bool active() const { return m_on && !m_abOff && m_count > 0; }
    bool touch(const float c[3], float r) const
    {
        if (!active())
            return false;
        for (int i = 0; i < m_count; i++) {
            const float* l = m_sphere + 4 * i;          // (the light's bounding sphere, camera space)
            float dx = l[0] - c[0], dy = l[1] - c[1], dz = l[2] - c[2], rr = r + l[3];
            if (dx * dx + dy * dy + dz * dz < rr * rr)
                return true;
        }
        return false;
    }
    void bind(bool receives, uint8_t stage)
    {
        if (!m_up && !up())
            return;
        float u[3][4];
        memcpy(u, m_u, sizeof u);
        if (!receives || !active())
            u[0][0] = 0.0f;
        bgfx::setUniform(m_uCity, u, 3);
        bgfx::setTexture(stage, m_sCity, bgfx::TextureHandle{m_tex}, BGFX_SAMPLER_POINT | BGFX_SAMPLER_UVW_CLAMP);
    }
    bool receives(const DrawPacket& p) const
    {
        return !p.state.blend && p.viewMode == 0 && p.query == kSinkNone && rm::currentGamePass() == m_worldPass;
    }
    float night() const { return m_night; }
    bool camera(float view[3][4], float inv[3][3], float proj[16]) const
    {
        if (!m_haveView)
            return false;
        memcpy(view, m_view, sizeof m_view);
        memcpy(inv, m_inv, sizeof m_inv);
        memcpy(proj, m_proj, sizeof m_proj);
        return true;
    }
    bool fog(float rgb[3]) const
    {
        if (!m_fogKnown)
            return false;
        memcpy(rgb, m_fog, sizeof m_fog);
        return true;
    }

  private:
    // the frame's view (a static world draw's modelview: the camera folded in), as rows; its 3x3 inverse; the world
    // pass's projection (c4..c7)
    bool takeView(const DrawPacket& p)
    {
        if (p.vertexProgram != 0 || !p.vertexConstants || p.vertexConstantCount < 8 || p.transient != kSinkNone ||
            p.lighting || p.state.blend || !p.state.depthWrite || p.shaderKind < 1 || p.shaderKind > 2)
            return false;
        const float* c = p.vertexConstants;
        float m[3][4];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                m[i][j] = c[4 * i + j];
        float det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                    m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        const float* pr = c + 16;
        if (fabsf(det) < 1e-12f || !(fabsf(pr[14]) > 0.5f && fabsf(pr[15]) < 1e-3f))
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
        memcpy(m_proj, pr, sizeof m_proj);
        // the world's up in camera space (the modelview's second column), normalised
        float up[3] = {m[0][1], m[1][1], m[2][1]};
        float l = sqrtf(up[0] * up[0] + up[1] * up[1] + up[2] * up[2]);
        for (int i = 0; i < 3; i++)
            m_up3[i] = l > 0 ? up[i] / l : (i == 1 ? 1.0f : 0.0f);
        return true;
    }
    void toWorld(const float cam[3], float w[3]) const
    {
        for (int i = 0; i < 3; i++)
            w[i] = m_inv[i][0] * (cam[0] - m_view[0][3]) + m_inv[i][1] * (cam[1] - m_view[1][3]) +
                   m_inv[i][2] * (cam[2] - m_view[2][3]);
    }
    void toCam(const float w[3], float c[3]) const
    {
        for (int i = 0; i < 3; i++)
            c[i] = m_view[i][0] * w[0] + m_view[i][1] * w[1] + m_view[i][2] * w[2] + m_view[i][3];
    }

    // ---- sources: a glow of the world pass (additive onto the frame, unlit, depth tested, fixed function)
    void source(const DrawPacket& p)
    {
        if (!p.state.blend || p.state.dstBlend != kBlendOne || p.state.blendOp != kBlendAdd || !p.state.depthTest ||
            p.vertexProgram != 0 || p.lighting || p.query != kSinkNone || p.state.stencil ||
            rm::currentGamePass() != m_worldPass || !p.vertexConstants || p.vertexConstantCount < 4)
            return;
        if (p.state.srcBlend != kBlendOne && p.state.srcBlend != kBlendSrcAlpha)
            return;
        const float* c = p.vertexConstants;
        float centre[3], size = 0, vcol[3] = {1, 1, 1};
        if (p.transient != kSinkNone) {
            uint32_t n = 0;
            const SinkVertex* v = rm::transientVertices(p, &n);
            if (!v || p.vertexCount < 3 || p.vertexCount > 12)
                return;
            n = p.vertexCount;
            float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
            double col[3] = {0, 0, 0};
            for (uint32_t i = 0; i < n; i++) {
                for (int k = 0; k < 3; k++)
                    lo[k] = fminf(lo[k], v[i].pos[k]), hi[k] = fmaxf(hi[k], v[i].pos[k]);
                uint32_t q = v[i].colour0;
                col[0] += (q >> 16 & 255) / 255.0, col[1] += (q >> 8 & 255) / 255.0, col[2] += (q & 255) / 255.0;
            }
            float m[3];
            for (int k = 0; k < 3; k++)
                m[k] = 0.5f * (lo[k] + hi[k]), size = fmaxf(size, hi[k] - lo[k]), vcol[k] = (float)(col[k] / n);
            for (int i = 0; i < 3; i++)
                centre[i] = c[4 * i] * m[0] + c[4 * i + 1] * m[1] + c[4 * i + 2] * m[2] + c[4 * i + 3];
            size *= scaleOf(c);
        } else {
            auto it = m_small.find(p.bufferOwner);
            if (it == m_small.end() || p.vertexCount > 64)
                return;
            const Small& s = it->second;
            for (int i = 0; i < 3; i++)
                centre[i] = c[4 * i] * s.c[0] + c[4 * i + 1] * s.c[1] + c[4 * i + 2] * s.c[2] + c[4 * i + 3];
            size = s.size * scaleOf(c);
            memcpy(vcol, s.col, sizeof vcol);
        }
        float d2 = centre[0] * centre[0] + centre[1] * centre[1] + centre[2] * centre[2];
        if (size < 0.05f || size > m_maxSize || d2 > 200.0f * 200.0f)
            return;
        // the colour: the texture's mean (premultiplied by its alpha) x the vertex colour x the texture factor where
        // the combiner reads it; a glow drawn src-alpha/one also scales by the vertex alpha (ignored: hue only)
        float tex[4] = {1, 1, 1, 1};
        bool known = p.stage[0].ordinal && texpack_mean(p.stage[0].ordinal, tex);
        if (!p.stage[0].ordinal || p.stage[0].texture == kSinkNone)
            tex[0] = tex[1] = tex[2] = tex[3] = 1.0f;
        float col[3];
        for (int k = 0; k < 3; k++)
            col[k] = (known && tex[3] > 1e-3f ? tex[k] / tex[3] : tex[k]) * vcol[k];
        float mx = fmaxf(col[0], fmaxf(col[1], col[2]));
        if (mx < 0.04f)
            return;                                     // (a dark glow: nothing to light)
        // the light's brightness: white glows (lamps, headlights) full, saturated ones (signs, markers, tail lights)
        // less: their colour carries them
        float mn = fminf(col[0], fminf(col[1], col[2]));
        float sat = mx > 0 ? 1.0f - mn / mx : 0.0f;
        float bright = sat < 0.35f ? 1.0f : 0.6f;
        static const float kWarm[3] = {1.0f, 0.80f, 0.58f};    // (a white glow's light: warm sodium-halogen white)
        for (int k = 0; k < 3; k++)
            col[k] = col[k] / mx * bright * (sat < 0.35f ? 1.0f - m_warm + m_warm * kWarm[k] : 1.0f);
        Found f;
        toWorld(centre, f.pos);
        f.size = size;
        memcpy(f.colour, col, sizeof col);
        f.texture = p.stage[0].ordinal;
        // wlook4: a vehicle's light (a white glow at one end of a car: a headlight; a red one: a tail light), shining
        // outwards from that end along the car's length
        bool red = col[0] > 0.3f && col[1] < 0.55f * col[0] && col[2] < 0.55f * col[0];
        if ((sat < 0.35f || red) && size < 3.0f)
            carOf(f, red ? kTail : kHead);
        if (dumpOn(p.frame))
            fprintf(m_dump, "src f%u d%u %s n%u tex%u known%d mean %.2f %.2f %.2f a%.2f vcol %.2f %.2f %.2f cam %.2f %.2f "
                    "%.2f size %.2f bl%u:%u\n", p.frame, p.drawIndex, p.transient != kSinkNone ? "tr" : "buf", p.vertexCount,
                    p.stage[0].ordinal, known, tex[0], tex[1], tex[2], tex[3], vcol[0], vcol[1], vcol[2], centre[0],
                    centre[1], centre[2], size, p.state.srcBlend, p.state.dstBlend);
        // sparks and particle swarms: one light for glows close together
        for (Found& g : m_found) {
            float dx = g.pos[0] - f.pos[0], dy = g.pos[1] - f.pos[1], dz = g.pos[2] - f.pos[2];
            if (dx * dx + dy * dy + dz * dz < 1.0f) {
                g.size = fmaxf(g.size, f.size);
                for (int k = 0; k < 3; k++)
                    g.colour[k] = fmaxf(g.colour[k], f.colour[k]);
                if (!g.car && f.car)
                    g.car = f.car, memcpy(g.dir, f.dir, sizeof g.dir);
                return;
            }
        }
        if (m_found.size() < 512)
            m_found.push_back(f);
    }
    static float scaleOf(const float* c)
    {
        float s2 = 0;
        for (int i = 0; i < 3; i++)
            s2 = fmaxf(s2, c[i] * c[i] + c[4 + i] * c[4 + i] + c[8 + i] * c[8 + i]);
        return sqrtf(s2);
    }

    static float hash3(float x, float y, float z, uint32_t salt)
    {
        uint32_t h = (uint32_t)(int32_t)floorf(x) * 73856093u ^ (uint32_t)(int32_t)floorf(y) * 19349663u ^
                     (uint32_t)(int32_t)floorf(z) * 83492791u ^ salt * 2654435761u;
        h ^= h >> 13, h *= 0x5bd1e995u, h ^= h >> 15;
        return (float)(h & 0xffffff) / 16777216.0f;
    }

    // ---- wlook4: vehicles. A car is a lit opaque draw of the world pass whose prim buffer's box, through the draw's
    // modelview, is car-sized: one model axis up, a length of 2.8-9 units, a width of 1.1-3.6, under 4 high. Its
    // length axis in world space tells which way a light at either end shines.
    void car(const DrawPacket& p)
    {
        if (!p.lighting || p.state.blend || !p.state.depthWrite || p.transient != kSinkNone || p.query != kSinkNone ||
            p.viewMode != 0 || rm::currentGamePass() != m_worldPass || !p.vertexConstants ||
            p.vertexConstantCount < 4 || m_cars.size() >= 96)
            return;
        auto it = m_bounds.find(p.vertexBuffer);
        if (it == m_bounds.end())
            return;
        const Bounds& b = it->second;
        const float* c = p.vertexConstants;
        float ax[3][3], len[3], ext[3];
        for (int k = 0; k < 3; k++) {
            float cam[3] = {c[k], c[4 + k], c[8 + k]};
            for (int i = 0; i < 3; i++)
                ax[k][i] = m_inv[i][0] * cam[0] + m_inv[i][1] * cam[1] + m_inv[i][2] * cam[2];
            len[k] = sqrtf(ax[k][0] * ax[k][0] + ax[k][1] * ax[k][1] + ax[k][2] * ax[k][2]);
            ext[k] = (b.hi[k] - b.lo[k]) * len[k];
        }
        int u = 0;
        for (int k = 1; k < 3; k++)
            if (len[k] > 0 && fabsf(ax[k][1]) / len[k] > fabsf(ax[u][1]) / fmaxf(len[u], 1e-9f))
                u = k;
        if (len[u] <= 0 || fabsf(ax[u][1]) / len[u] < 0.85f)
            return;
        int a = (u + 1) % 3, bb = (u + 2) % 3;
        int la = ext[a] >= ext[bb] ? a : bb;
        float L = fmaxf(ext[a], ext[bb]), W = fminf(ext[a], ext[bb]);
        if (L < 2.8f || L > 9.0f || W < 1.1f || W > 3.6f || ext[u] > 4.0f || ext[u] < 0.6f || L < 1.3f * W)
            return;
        Car k;
        float m[3], cam[3];
        for (int i = 0; i < 3; i++)
            m[i] = 0.5f * (b.lo[i] + b.hi[i]);
        for (int i = 0; i < 3; i++)
            cam[i] = c[4 * i] * m[0] + c[4 * i + 1] * m[1] + c[4 * i + 2] * m[2] + c[4 * i + 3];
        toWorld(cam, k.centre);
        float h = sqrtf(ax[la][0] * ax[la][0] + ax[la][2] * ax[la][2]);
        if (h < 1e-6f)
            return;
        k.axis[0] = ax[la][0] / h, k.axis[1] = 0, k.axis[2] = ax[la][2] / h;
        k.half = 0.5f * L, k.halfW = 0.5f * W, k.height = ext[u];
        k.la = la;
        for (Car& o : m_cars) {
            float dx = o.centre[0] - k.centre[0], dz = o.centre[2] - k.centre[2];
            if (dx * dx + dz * dz < 1.0f && fabsf(o.centre[1] - k.centre[1]) < 1.5f) {
                if (k.half > o.half)
                    o = k;                              // (a car's parts: the body is the largest)
                return;
            }
        }
        m_cars.push_back(k);
        if (dumpOn(p.frame))
            fprintf(m_dump, "car f%u d%u at %.2f %.2f %.2f axis %.2f %.2f half %.2f halfW %.2f h %.2f kind %u vp %u tex %u "
                    "vb %u la %d\n", p.frame, p.drawIndex, k.centre[0], k.centre[1], k.centre[2], k.axis[0],
                    k.axis[2], k.half, k.halfW, k.height, p.shaderKind, p.vertexProgram, p.stage[0].ordinal, p.vertexBuffer, la);
    }
    // a white or red glow at one end of one of the frame's cars
    void carOf(Found& f, int cls)
    {
        f.cls = cls;
        const Car* best = nullptr;
        float bestSide = 1e30f, along = 0;
        for (const Car& k : m_cars) {
            float d[3] = {f.pos[0] - k.centre[0], f.pos[1] - k.centre[1], f.pos[2] - k.centre[2]};
            float t = d[0] * k.axis[0] + d[2] * k.axis[2];
            float s = -d[0] * k.axis[2] + d[2] * k.axis[0];
            if (fabsf(t) > k.half + 0.9f || fabsf(t) < 0.45f * k.half || fabsf(s) > k.halfW + 0.9f ||
                d[1] < -0.5f * k.height - 1.0f || d[1] > 0.5f * k.height + 1.0f)
                continue;
            if (fabsf(s) < bestSide)
                bestSide = fabsf(s), best = &k, along = t;
        }
        if (!best)
            return;
        float sg = along > 0 ? 1.0f : -1.0f;
        f.car = cls;
        // the other end of the car, mirrored through its middle: where a tail light's headlight is (the game draws no
        // headlight glows: a car whose tail lights are on gets headlights)
        for (int k = 0; k < 3; k++)
            f.front[k] = f.pos[k] - 2.0f * along * best->axis[k];
        f.front[1] += 0.1f;
        if (m_dump && m_dumpThis)
            fprintf(m_dump, "carlight cls %d end %+d along %.2f half %.2f\n", cls, sg > 0 ? best->la + 1 : -(best->la + 1),
                    along, best->half);
        f.dir[0] = sg * best->axis[0], f.dir[1] = cls == kHead ? -m_headTilt : 0.0f, f.dir[2] = sg * best->axis[2];
        float l = sqrtf(f.dir[0] * f.dir[0] + f.dir[1] * f.dir[1] + f.dir[2] * f.dir[2]);
        for (int k = 0; k < 3; k++)
            f.dir[k] /= l;
    }
    // a cached light takes a frame's glow: its vehicle light kind and direction (the car's, else the light's own
    // motion near the street: headlights forwards, tail lights backwards)
    void carLight(Cached& e, const Found& f)
    {
        if (!f.cls) {
            e.car = kNoCar;
            return;
        }
        float d[3];
        if (f.car) {
            memcpy(d, f.dir, sizeof d);
            if (f.cls == kTail) {
                memcpy(e.front, f.front, sizeof e.front);
                e.hasFront = true;
            }
        } else {
            float vh = sqrtf(e.vel[0] * e.vel[0] + e.vel[2] * e.vel[2]);
            bool low = m_ground > 1e29f || e.pos[1] - m_ground < 2.5f;
            if (vh < 0.04f || vh > 4.0f || !low)
                return;                                 // (no direction now: keep the last one while it lasts)
            float sg = f.cls == kTail ? -1.0f : 1.0f;
            if (e.hasFront)                             // (the car not found this frame: its headlight moves along)
                for (int k = 0; k < 3; k++)
                    e.front[k] += e.vel[k];
            d[0] = sg * e.vel[0] / vh, d[1] = f.cls == kHead ? -m_headTilt : 0.0f, d[2] = sg * e.vel[2] / vh;
            float l = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
            for (int k = 0; k < 3; k++)
                d[k] /= l;
        }
        if (e.car != f.cls) {
            memcpy(e.dir, d, sizeof d);
        } else {
            float l = 0;
            for (int k = 0; k < 3; k++)
                e.dir[k] += 0.4f * (d[k] - e.dir[k]), l += e.dir[k] * e.dir[k];
            l = sqrtf(l);
            for (int k = 0; k < 3; k++)
                e.dir[k] = l > 1e-6f ? e.dir[k] / l : d[k];
        }
        e.car = f.cls;
    }

    // ---- wlook4: shop fronts. A building draw (layeredReflect with its faithful combiner: the facade's alpha is 0 on
    // the glass) is read once per prim buffer pair: each wall triangle's bottom edge at the building's foot is split
    // into pieces of at most 10 units, and a piece whose band 0.6-2.2 units up is glass (the facade's alpha grid,
    // through the stage's texture coordinates) is a shop front: a segment light along the facade, lit or not and its
    // colour chosen by its place (a warm or cool interior, now and then a neon tint), as the interiors choose rooms.
    void packet(DrawPacket& p) override
    {
        if (p.shaderKind == 2 && p.combinerKey && p.combinerHash &&
            !strncmp(p.combinerKey, "c4.0.2a2.2.0r1|c20.1.2a2.1.0r1", 30))
            m_buildingHashes.insert(p.combinerHash);
    }
    void building(const DrawPacket& p)
    {
        if (p.shaderKind != 2 || p.viewMode != 0 || p.query != kSinkNone || p.transient != kSinkNone ||
            p.state.blend || !p.state.depthWrite || p.lighting || !m_buildingHashes.count(p.combinerHash) ||
            !p.vertexConstants || p.vertexConstantCount < 49 || rm::currentGamePass() != m_worldPass ||
            (p.state.prim != 0 && p.state.prim != 1))
            return;
        uint64_t key = (uint64_t)p.vertexBuffer << 32 ^ (uint64_t)(p.indexBuffer & 0xffff) << 16 ^ (p.count & 0xffff);
        auto bt = m_built.find(key);
        if (bt != m_built.end()) {
            bt->second.lastDrawn = m_present;
            m_footMin = fminf(m_footMin, bt->second.foot);
            return;
        }
        Built& B = m_built[key];
        B.vb = p.vertexBuffer, B.ib = p.indexBuffer, B.lastDrawn = m_present;
        m_vbUse[B.vb]++;
        if (B.ib != kSinkNone)
            m_ibUse[B.ib]++;
        auto gi = m_geo.find(p.vertexBuffer);
        if (gi == m_geo.end() || !gi->second.v)
            return;
        m_dbg[0]++;
        const std::vector<GeoVtx>& v = *gi->second.v;
        const std::vector<uint16_t>* ib = nullptr;
        if (p.indexBuffer != kSinkNone) {
            auto ii = m_ib.find(p.indexBuffer);
            if (ii == m_ib.end())
                return;
            ib = ii->second.get();
        }
        const float* c = p.vertexConstants;
        std::vector<float> W(v.size() * 3);
        float foot = 1e30f;
        for (size_t i = 0; i < v.size(); i++) {
            const float* q = v[i].pos;
            float cam[3];
            for (int r = 0; r < 3; r++)
                cam[r] = c[4 * r] * q[0] + c[4 * r + 1] * q[1] + c[4 * r + 2] * q[2] + c[4 * r + 3];
            toWorld(cam, &W[3 * i]);
            foot = fminf(foot, W[3 * i + 1]);
        }
        B.foot = foot;
        m_footMin = fminf(m_footMin, foot);
        uint8_t grid[256];
        int set = (int)(c[4 * 48] + 0.5f);
        bool haveGrid = set >= 0 && set <= 1 && texpack_alpha_grid(p.stage[0].ordinal, grid);
        if (set < 0 || set > 1)
            set = 0;
        m_dbg[1] += haveGrid;                           // (no glass mask known: the walls' feet only, no shop fronts)
        bool xf = c[4 * 48 + 1] > 0.5f;
        const float* r0 = c + 4 * 32;
        const float* r1 = c + 4 * 33;
        uint32_t n = ib ? (uint32_t)ib->size() : (uint32_t)v.size();
        if (p.count && p.count < n)
            n = p.count;
        uint32_t tris = p.state.prim == 0 ? n / 3 : (n >= 3 ? n - 2 : 0);
        auto vert = [&](uint32_t i) -> int { uint32_t k = ib ? (*ib)[i] : i; return k < v.size() ? (int)k : -1; };
        auto alphaAt = [&](float u, float w) -> float {
            if (xf) {
                float u2 = r0[0] * u + r0[1] * w + r0[2];
                float w2 = r1[0] * u + r1[1] * w + r1[2];
                u = u2, w = w2;
            }
            u -= floorf(u), w -= floorf(w);
            int x = std::min(15, (int)(u * 16.0f)), y = std::min(15, (int)(w * 16.0f));
            return grid[y * 16 + x] / 255.0f;
        };
        for (uint32_t t = 0; t < tris && B.shops.size() < 256; t++) {
            int id[3];
            if (p.state.prim == 0)
                id[0] = vert(3 * t), id[1] = vert(3 * t + 1), id[2] = vert(3 * t + 2);
            else
                id[0] = vert(t), id[1] = vert(t + 1), id[2] = vert(t + 2);
            if (id[0] < 0 || id[1] < 0 || id[2] < 0 || id[0] == id[1] || id[1] == id[2] || id[0] == id[2])
                continue;
            const float* P[3] = {&W[3 * id[0]], &W[3 * id[1]], &W[3 * id[2]]};
            float e1[3], e2[3], N[3];
            for (int k = 0; k < 3; k++)
                e1[k] = P[1][k] - P[0][k], e2[k] = P[2][k] - P[0][k];
            N[0] = e1[1] * e2[2] - e1[2] * e2[1], N[1] = e1[2] * e2[0] - e1[0] * e2[2], N[2] = e1[0] * e2[1] - e1[1] * e2[0];
            float a2 = sqrtf(N[0] * N[0] + N[1] * N[1] + N[2] * N[2]);
            if (a2 < 1.0f || fabsf(N[1]) / a2 > 0.2f)
                continue;                               // (small, or not a wall)
            m_dbg[2]++;
            // the two lowest corners are the bottom edge; the third well above them
            int o[3] = {0, 1, 2};
            std::sort(o, o + 3, [&](int x, int y) { return P[x][1] < P[y][1]; });
            const float *A = P[o[0]], *Q = P[o[1]], *R = P[o[2]];
            if (Q[1] - A[1] > 0.15f || R[1] - Q[1] < 1.2f || A[1] > foot + 1.2f)
                continue;
            float e[3] = {Q[0] - A[0], Q[1] - A[1], Q[2] - A[2]};
            float Ls = sqrtf(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
            if (Ls < 1.5f)
                continue;
            m_dbg[3]++;
            for (float s = 0; s <= Ls; s += 2.0f)         // (the feet of walls by place: the street under a shop)
                footAdd(A[0] + (Q[0] - A[0]) * s / Ls, A[2] + (Q[2] - A[2]) * s / Ls, A[1]);
            for (int k = 0; k < 3; k++)
                e[k] /= Ls;
            float rr[3] = {R[0] - A[0], R[1] - A[1], R[2] - A[2]};
            float rx = rr[0] * e[0] + rr[1] * e[1] + rr[2] * e[2];
            float f[3] = {rr[0] - rx * e[0], rr[1] - rx * e[1], rr[2] - rx * e[2]};
            float ry = sqrtf(f[0] * f[0] + f[1] * f[1] + f[2] * f[2]);
            if (ry < 1e-3f)
                continue;
            for (int k = 0; k < 3; k++)
                f[k] /= ry;
            if (!haveGrid)
                continue;
            const float* uvA = v[id[o[0]]].uv[set];
            const float* uvQ = v[id[o[1]]].uv[set];
            const float* uvR = v[id[o[2]]].uv[set];
            int np = (int)ceilf(Ls / 10.0f);
            float pl = Ls / np;
            for (int j = 0; j < np; j++) {
                float glass = 0;
                int cnt = 0;
                for (float s = j * pl + 0.5f; s < (j + 1) * pl; s += 1.0f)
                    for (float hgt : {0.6f, 1.4f, 2.2f}) {
                        // the point (s along the edge, hgt up) in the triangle's plane: barycentric coordinates
                        float X[3] = {e[0] * s, e[1] * s + hgt, e[2] * s};
                        float px = X[0] * e[0] + X[1] * e[1] + X[2] * e[2];
                        float py = X[0] * f[0] + X[1] * f[1] + X[2] * f[2];
                        float g = py / ry, bq = (px - g * rx) / Ls;
                        float u = uvA[0] + bq * (uvQ[0] - uvA[0]) + g * (uvR[0] - uvA[0]);
                        float w = uvA[1] + bq * (uvQ[1] - uvA[1]) + g * (uvR[1] - uvA[1]);
                        glass += 1.0f - alphaAt(u, w);
                        cnt++;
                    }
                m_dbg[4]++;
                if (!cnt || (glass /= cnt) < 0.15f)
                    continue;
                m_dbg[5]++;
                Shop sh;
                float mid = (j + 0.5f) * pl;
                for (int k = 0; k < 3; k++)
                    sh.c[k] = A[k] + e[k] * mid, sh.half[k] = e[k] * 0.5f * pl;
                sh.foot = sh.c[1];
                sh.c[1] += m_shopHeight;
                int64_t cell = (int64_t)floorf(sh.c[0]) * 1000003 ^ (int64_t)floorf(sh.c[1]) * 1009 ^
                               (int64_t)floorf(sh.c[2]) * 7919;
                if (!m_shopCells.insert(cell).second)
                    continue;                           // (the same facade in another draw)
                sh.cell = cell;
                sh.glass = glass;
                // lit, and its colour, by its place (stable across frames, loads and rollbacks)
                float h0 = hash3(sh.c[0] / 3.0f, sh.c[1] / 3.0f, sh.c[2] / 3.0f, 1);
                float h1 = hash3(sh.c[0] / 3.0f, sh.c[1] / 3.0f, sh.c[2] / 3.0f, 2);
                sh.lit = h0 < m_shopLit;
                static const float kPal[6][3] = {{1.0f, 0.74f, 0.46f}, {1.0f, 0.82f, 0.60f}, {1.0f, 0.93f, 0.82f},
                                                 {0.84f, 0.93f, 1.0f}, {1.0f, 0.42f, 0.70f}, {0.40f, 0.88f, 1.0f}};
                int pi = h1 < 0.30f ? 0 : h1 < 0.55f ? 1 : h1 < 0.78f ? 2 : h1 < 0.93f ? 3 : h1 < 0.965f ? 4 : 5;
                memcpy(sh.colour, kPal[pi], sizeof sh.colour);
                B.shops.push_back(sh);
            }
        }
        m_shopTotal += B.shops.size();
    }
    // the lowest wall foot of the buildings read, on a grid of 4 units: a shop front whose foot is well above the
    // lowest one around it stands on a building's upper section or its roof, not on the street
    static int64_t footCell(int x, int z) { return (int64_t)x * 1000003 + z; }
    void footAdd(float x, float z, float y)
    {
        auto it = m_footGrid.emplace(footCell((int)floorf(x / 4.0f), (int)floorf(z / 4.0f)), y).first;
        it->second = fminf(it->second, y);
    }
    float footNear(float x, float z) const
    {
        int cx = (int)floorf(x / 4.0f), cz = (int)floorf(z / 4.0f);
        float m = 1e30f;
        for (int i = -2; i <= 2; i++)
            for (int j = -2; j <= 2; j++) {
                auto it = m_footGrid.find(footCell(cx + i, cz + j));
                if (it != m_footGrid.end())
                    m = fminf(m, it->second);
            }
        return m;
    }
    // a buffer rewritten or dropped: the shop fronts read from it go (read again at the next draw)
    void dropShops(uint32_t id, bool index)
    {
        auto& use = index ? m_ibUse : m_vbUse;
        auto u = use.find(id);
        if (u == use.end())
            return;
        use.erase(u);
        for (auto it = m_built.begin(); it != m_built.end();) {
            if ((index ? it->second.ib : it->second.vb) == id) {
                for (const Shop& sh : it->second.shops)
                    m_shopCells.erase(sh.cell);
                m_shopTotal -= it->second.shops.size();
                auto& other = index ? m_vbUse : m_ibUse;
                auto o = other.find(index ? it->second.vb : it->second.ib);
                if (o != other.end() && --o->second <= 0)
                    other.erase(o);
                it = m_built.erase(it);
            } else {
                ++it;
            }
        }
    }

    // ---- the frame's end: this frame's glows into the world-space cache; ageing and fades
    void endFrame()
    {
        if (m_fogN) {
            for (int k = 0; k < 3; k++)
                m_fog[k] = m_fogSum[k] / m_fogN;
            m_fogKnown = true;
            float lum = 0.3f * m_fog[0] + 0.59f * m_fog[1] + 0.11f * m_fog[2];
            float target = lum < 0.12f ? 1.0f : lum > 0.30f ? 0.0f : (0.30f - lum) / 0.18f;
            m_night += (target - m_night) * (m_night < 0 ? 1.0f : 0.1f);
            if (m_night < 0)
                m_night = target;
        }
        m_fogSum[0] = m_fogSum[1] = m_fogSum[2] = 0, m_fogN = 0;
        m_srcSum += m_found.size();
        uint32_t now = ++m_present;
        if (m_haveView) {
            for (const Found& f : m_found) {
                Cached* best = nullptr;
                float bd = 1e30f;
                for (Cached& e : m_cache) {
                    // (a moving light where its motion puts it now: wlook4, cars)
                    float dx = e.pos[0] + e.vel[0] - f.pos[0], dy = e.pos[1] + e.vel[1] - f.pos[1],
                          dz = e.pos[2] + e.vel[2] - f.pos[2];
                    float d2 = dx * dx + dy * dy + dz * dz, lim = fmaxf(1.0f, 0.6f * fmaxf(e.size, f.size));
                    if (d2 < lim * lim && d2 < bd && e.lastSeen != now)
                        bd = d2, best = &e;
                }
                if (best) {
                    Cached& e = *best;
                    float dx = f.pos[0] - e.origin[0], dy = f.pos[1] - e.origin[1], dz = f.pos[2] - e.origin[2];
                    e.moved = fmaxf(e.moved, sqrtf(dx * dx + dy * dy + dz * dz));
                    bool still = e.moved < kStill;
                    uint32_t gap = now - e.lastSeen;
                    for (int k = 0; k < 3; k++) {
                        float v = (f.pos[k] - e.pos[k]) / (float)(gap ? gap : 1);
                        e.vel[k] = still ? 0.0f : e.vel[k] + 0.5f * (v - e.vel[k]);
                        e.pos[k] = still ? e.pos[k] + 0.2f * (f.pos[k] - e.pos[k]) : f.pos[k];
                        e.colour[k] += 0.25f * (f.colour[k] - e.colour[k]);
                    }
                    carLight(e, f);
                    e.size += 0.25f * (f.size - e.size);
                    e.lastSeen = now, e.seen++, e.dying = false;
                } else if (m_cache.size() < 1024) {
                    Cached e = {};
                    memcpy(e.pos, f.pos, sizeof e.pos);
                    memcpy(e.origin, f.pos, sizeof e.origin);
                    memcpy(e.colour, f.colour, sizeof e.colour);
                    e.size = f.size;
                    e.firstSeen = e.lastSeen = now, e.seen = 1;
                    e.texture = f.texture;
                    carLight(e, f);
                    if (e.car)
                        e.fade = 0.5f;                  // (a car's light: it moves on; no slow fade-in)
                    m_cache.push_back(e);
                }
            }
        }
        // ageing: a moving light lives while drawn; a static one while it is off screen or hidden for a while, but
        // goes once its place is in view and nothing is drawn there (a lamp knocked down)
        float origin[3] = {0, 0, 0}, cam[3] = {0, 0, 0};
        if (m_viewKnown)
            toWorld(origin, cam);                       // (the camera in world space)
        for (size_t i = 0; i < m_cache.size();) {
            Cached& e = m_cache[i];
            uint32_t unseen = now - e.lastSeen;
            bool isStatic = e.seen >= 4 && e.moved < kStill;
            float dx = e.pos[0] - cam[0], dy = e.pos[1] - cam[1], dz = e.pos[2] - cam[2];
            float dist = sqrtf(dx * dx + dy * dy + dz * dz);
            bool go;
            if (!isStatic)
                go = unseen > 2;
            else
                go = dist > 220.0f || unseen > 3600 || (unseen > 12 && onScreen(e.pos) && dist < 80.0f);
            e.dying = go;
            e.fade += go ? -0.12f : 0.12f;
            if (e.fade > 1.0f)
                e.fade = 1.0f;
            if (e.fade <= 0.0f && go) {
                m_cache[i] = m_cache.back();
                m_cache.pop_back();
                continue;
            }
            if (e.fade < 0)
                e.fade = 0;
            i++;
        }
        if (m_dump && m_dumpThis) {
            fprintf(m_dump, "end p%u found %zu cache %zu placed %d night %.2f\n", now, m_found.size(), m_cache.size(),
                    m_count, m_night);
            for (const Cached& e : m_cache)
                fprintf(m_dump, "  L %.2f %.2f %.2f size %.2f seen %u unseen %u moved %.2f fade %.2f tex %u car %d dir %.2f "
                        "%.2f %.2f vel %.2f %.2f %.2f%s\n", e.pos[0], e.pos[1], e.pos[2], e.size, e.seen, now - e.lastSeen,
                        e.moved, e.fade, e.texture, e.car, e.dir[0], e.dir[1], e.dir[2], e.vel[0], e.vel[1], e.vel[2],
                        e.dying ? " dying" : "");
            fflush(m_dump);
        }
        m_found.clear();
        m_carSum += m_cars.size();
        m_cars.clear();
        // the street's height: the lowest building foot drawn, kept low for a while (windows.cpp's rule)
        if (m_footMin < 1e29f) {
            if (m_ground > 1e29f || m_footMin < m_ground)
                m_ground = m_footMin;
            else
                m_ground += (m_footMin - m_ground) * 0.002f;
        }
        m_footMin = 1e30f;
        for (auto& b : m_built)
            b.second.fade = fminf(1.0f, b.second.fade + 0.1f);
        m_haveView = m_placed = false;
        m_dumpThis = false;
    }
    bool onScreen(const float w[3]) const
    {
        float c[3];
        toCam(w, c);
        const float* P = m_proj;
        float x = P[0] * c[0] + P[1] * c[1] + P[2] * c[2] + P[3];
        float y = P[4] * c[0] + P[5] * c[1] + P[6] * c[2] + P[7];
        float wc = P[12] * c[0] + P[13] * c[1] + P[14] * c[2] + P[15];
        return wc > 0.1f && fabsf(x) < 0.9f * wc && fabsf(y) < 0.9f * wc;
    }

    // ---- the frame's light list (camera space), its tiles, the data texture
    void place()
    {
        m_placed = true;
        m_count = 0;
        if (!m_on || m_abOff || (m_night <= 0.01f && m_dayStrength <= 0.0f)) {
            m_u[0][0] = 0;
            return;
        }
        if (!m_up && !up())
            return;
        uint32_t W = hulk_gfx_sink_target_width(), H = hulk_gfx_sink_target_height();
        if (!W || !H)
            return;
        float strength = m_strength * (m_dayStrength + (1.0f - m_dayStrength) * fmaxf(0.0f, m_night));
        struct Pick {
            float score;
            float cam[3], r;                            // the light: camera space, its radius
            float col[3];
            int kind;
            float x[4];                                 // the third texel (spot: direction, cone; line: half axis)
            float bc[3], br;                            // its bounding sphere (tiles, the draws it touches)
        };
        static Pick picks[2048], shops[1024];
        int n = 0, ns = 0, spots = 0;
        const float* P = m_proj;
        // the sphere against the frustum's sides (clip space: |x| <= w + r * |row|)
        auto inFrustum = [&](const float* c, float r) {
            float wc = P[12] * c[0] + P[13] * c[1] + P[14] * c[2] + P[15];
            float x = P[0] * c[0] + P[1] * c[1] + P[2] * c[2] + P[3];
            float y = P[4] * c[0] + P[5] * c[1] + P[6] * c[2] + P[7];
            float rx = r * sqrtf(P[0] * P[0] + P[1] * P[1] + P[2] * P[2] + P[12] * P[12] + P[13] * P[13] + P[14] * P[14]);
            float ry = r * sqrtf(P[4] * P[4] + P[5] * P[5] + P[6] * P[6] + P[12] * P[12] + P[13] * P[13] + P[14] * P[14]);
            float rw = r * sqrtf(P[12] * P[12] + P[13] * P[13] + P[14] * P[14]);
            return !(wc < -rw || x > wc + rx || -x > wc + rx || y > wc + ry || -y > wc + ry);
        };
        auto dirToCam = [&](const float* w, float* c) {
            float l = 0;
            for (int i = 0; i < 3; i++)
                c[i] = m_view[i][0] * w[0] + m_view[i][1] * w[1] + m_view[i][2] * w[2], l += c[i] * c[i];
            l = sqrtf(l);
            for (int i = 0; i < 3; i++)
                c[i] = l > 1e-9f ? c[i] / l : 0.0f;
        };
        for (const Cached& e : m_cache) {
            if (e.fade <= 0.0f || n >= 1024)
                continue;
            Pick k = {};
            toCam(e.pos, k.cam);
            bool isStatic = e.seen >= 4 && e.moved < kStill;
            float r = fminf(m_maxR, fmaxf(m_minR, m_radiusScale * e.size));
            float gain = isStatic ? 1.0f : 0.5f;        // (moving glows: effects, markers; half as strong)
            k.kind = isStatic ? kLamp : kPoint;
            memcpy(k.bc, k.cam, sizeof k.bc);
            if (e.car) {                                // (wlook4: a vehicle's light, a cone along the car)
                bool head = e.car == kHead;
                r = head ? m_headR : m_tailR;
                gain = head ? m_headK : m_tailK;
                k.kind = kSpot;
                dirToCam(e.dir, k.x);
                k.x[3] = head ? m_headCos : 0.0f;
                if (head)                               // (the cone's bounding sphere: about its middle)
                    for (int i = 0; i < 3; i++)
                        k.bc[i] = k.cam[i] + k.x[i] * r * 0.5f;
            }
            k.r = r;
            k.br = e.car == kHead ? r * 0.92f : r;
            if (!inFrustum(k.bc, k.br))
                continue;
            for (int j = 0; j < 3; j++)
                k.col[j] = e.colour[j] * e.fade * strength * gain;
            float d = sqrtf(k.cam[0] * k.cam[0] + k.cam[1] * k.cam[1] + k.cam[2] * k.cam[2]);
            k.score = e.fade * gain * (e.colour[0] + e.colour[1] + e.colour[2]) * r / (d + 4.0f);
            picks[n++] = k;
        }
        // wlook4: headlights. The game draws tail light glows but none at the front: a car whose tail lights are on
        // gets a headlight opposite each, a warm white cone along the road ahead
        for (const Cached& e : m_cache) {
            if (e.fade <= 0.0f || e.car != kTail || !e.hasFront || n >= 1024 || m_headK <= 0)
                continue;
            Pick k = {};
            toCam(e.front, k.cam);
            float back[3] = {-e.dir[0], -m_headTilt, -e.dir[2]};
            float l = sqrtf(back[0] * back[0] + back[1] * back[1] + back[2] * back[2]);
            for (int i = 0; i < 3; i++)
                back[i] /= l;
            dirToCam(back, k.x);
            k.x[3] = m_headCos;
            k.kind = kSpot;
            k.r = m_headR;
            for (int i = 0; i < 3; i++)
                k.bc[i] = k.cam[i] + k.x[i] * k.r * 0.5f;
            k.br = k.r * 0.92f;
            if (!inFrustum(k.bc, k.br))
                continue;
            static const float kHeadCol[3] = {1.0f, 0.92f, 0.78f};
            for (int j = 0; j < 3; j++)
                k.col[j] = kHeadCol[j] * e.fade * strength * m_headK;
            float d = sqrtf(k.bc[0] * k.bc[0] + k.bc[1] * k.bc[1] + k.bc[2] * k.bc[2]);
            k.score = e.fade * m_headK * 2.7f * k.r / (d + 4.0f);
            picks[n++] = k;
        }
        // wlook4: the shop fronts near the camera (at the street), faded out with distance
        float camW[3], zero[3] = {0, 0, 0};
        toWorld(zero, camW);
        if (m_shopK > 0) {
            for (const auto& bt : m_built) {
                const Built& B = bt.second;
                for (const Shop& sh : B.shops) {
                    float dx = sh.c[0] - camW[0], dy = sh.c[1] - camW[1], dz = sh.c[2] - camW[2];
                    float d = sqrtf(dx * dx + dy * dy + dz * dz);
                    if (m_dumpThis && m_dump && d < 60.0f)
                        fprintf(m_dump, "shop %.1f %.1f %.1f d %.1f glass %.2f lit %d above %.1f half %.1f %.1f\n", sh.c[0],
                                sh.c[1], sh.c[2], d, sh.glass, sh.lit, sh.c[1] - m_ground, sh.half[0], sh.half[2]);
                    if (!sh.lit || ns >= 1024) {
                        m_dbg[6]++;
                        continue;
                    }
                    if (sh.foot > footNear(sh.c[0], sh.c[2]) + 1.0f) {
                        m_dbg[7]++;
                        continue;                       // (the foot of a building's upper section: not a street)
                    }
                    if (d > m_shopFar) {
                        m_dbg[8]++;
                        continue;
                    }
                    Pick k = {};
                    toCam(sh.c, k.cam);
                    float hl = sqrtf(sh.half[0] * sh.half[0] + sh.half[1] * sh.half[1] + sh.half[2] * sh.half[2]);
                    for (int i = 0; i < 3; i++)
                        k.x[i] = m_view[i][0] * sh.half[0] + m_view[i][1] * sh.half[1] + m_view[i][2] * sh.half[2];
                    k.r = m_shopR;
                    memcpy(k.bc, k.cam, sizeof k.bc);
                    k.br = m_shopR + hl + 2.0f;
                    if (!inFrustum(k.bc, k.br)) {
                        m_dbg[9]++;
                        continue;
                    }
                    m_dbg[10]++;
                    float t = (m_shopFar - d) / (0.35f * m_shopFar);
                    float fadeD = t >= 1 ? 1.0f : t * t * (3 - 2 * t);
                    float g = powf(fminf(sh.glass * 1.6f, 1.0f), 0.7f) * fadeD * B.fade * strength * m_shopK;
                    for (int j = 0; j < 3; j++)
                        k.col[j] = sh.colour[j] * g;
                    k.kind = kLine;
                    k.score = g * (sh.colour[0] + sh.colour[1] + sh.colour[2]) * (k.r + hl) / (d + 4.0f);
                    shops[ns++] = k;
                }
            }
            std::sort(shops, shops + ns, [](const Pick& a, const Pick& b) { return a.score > b.score; });
            for (int i = 0; i < ns && i < kMaxShop && n < 2048; i++)
                picks[n++] = shops[i];
        }
        std::sort(picks, picks + n, [](const Pick& a, const Pick& b) { return a.score > b.score; });
        if (n > kMaxLights)
            n = kMaxLights;
        // tiles: at most 32 across and down, and the index within the texture
        const uint32_t tileTexel0 = (uint32_t)kTexelsPerLight * (uint32_t)kMaxLights;   // (the lights' records first)
        const uint32_t texelsPerTile = kPerTile / 4;
        uint32_t tile = 32;
        while ((W + tile - 1) / tile > kMaxTilesX || (H + tile - 1) / tile > kMaxTilesY ||
               tileTexel0 + ((W + tile - 1) / tile) * ((H + tile - 1) / tile) * texelsPerTile > kTex * kTex)
            tile *= 2;
        uint32_t tx = (W + tile - 1) / tile, ty = (H + tile - 1) / tile;
        static float data[kTex * kTex * 4];
        static uint8_t counts[kMaxTilesX * kMaxTilesY];
        memset(counts, 0, sizeof counts);
        for (uint32_t t = 0; t < tx * ty * texelsPerTile; t++)
            for (int k = 0; k < 4; k++)
                data[4 * (tileTexel0 + t) + k] = -1.0f;
        int shopsPlaced = 0;
        for (int i = 0; i < n; i++) {
            const Pick& k = picks[i];
            float* rec = data + 4 * kTexelsPerLight * i;
            memcpy(rec, k.cam, 3 * sizeof(float));
            rec[3] = k.r;
            memcpy(rec + 4, k.col, 3 * sizeof(float));
            rec[7] = (float)k.kind;
            memcpy(rec + 8, k.x, 4 * sizeof(float));
            memcpy(m_sphere + 4 * i, k.bc, 3 * sizeof(float));
            m_sphere[4 * i + 3] = k.br;
            shopsPlaced += k.kind == kLine;
            spots += k.kind == kSpot;
            // its screen rectangle: the corners of the sphere's box, projected (one behind the camera: all of it)
            float x0 = 1e30f, y0 = 1e30f, x1 = -1e30f, y1 = -1e30f;
            bool all = false;
            for (int cnr = 0; cnr < 8 && !all; cnr++) {
                float q[3] = {k.bc[0] + (cnr & 1 ? k.br : -k.br), k.bc[1] + (cnr & 2 ? k.br : -k.br),
                              k.bc[2] + (cnr & 4 ? k.br : -k.br)};
                float wq = P[12] * q[0] + P[13] * q[1] + P[14] * q[2] + P[15];
                if (wq < 0.05f) {
                    all = true;
                    break;
                }
                float xq = (P[0] * q[0] + P[1] * q[1] + P[2] * q[2] + P[3]) / wq;
                float yq = (P[4] * q[0] + P[5] * q[1] + P[6] * q[2] + P[7]) / wq;
                float px = (xq * 0.5f + 0.5f) * W, py = (0.5f - yq * 0.5f) * H;
                x0 = fminf(x0, px), x1 = fmaxf(x1, px), y0 = fminf(y0, py), y1 = fmaxf(y1, py);
            }
            int a0 = 0, a1 = (int)tx - 1, b0 = 0, b1 = (int)ty - 1;
            if (!all) {
                a0 = std::max(0, (int)floorf(x0 / tile)), a1 = std::min((int)tx - 1, (int)floorf(x1 / tile));
                b0 = std::max(0, (int)floorf(y0 / tile)), b1 = std::min((int)ty - 1, (int)floorf(y1 / tile));
            }
            for (int b = b0; b <= b1; b++)
                for (int a = a0; a <= a1; a++) {
                    uint32_t t = (uint32_t)b * tx + (uint32_t)a;
                    if (counts[t] >= kPerTile)
                        continue;
                    data[4 * (tileTexel0 + t * texelsPerTile) + counts[t]] = (float)i;
                    counts[t]++;
                }
        }
        m_count = n;
        m_placedSum += n;
        m_shopPlacedSum += shopsPlaced;
        m_spotSum += spots;
        bgfx::updateTexture2D(bgfx::TextureHandle{m_tex}, 0, 0, 0, 0, kTex, kTex,
                              bgfx::copy(data, sizeof data));
        const bgfx::Caps* caps = bgfx::getCaps();
        m_u[0][0] = (float)n, m_u[0][1] = (float)tile, m_u[0][2] = (float)tx, m_u[0][3] = 1.0f;
        m_u[1][0] = (float)H, m_u[1][1] = caps && caps->originBottomLeft ? 1.0f : 0.0f, m_u[1][2] = (float)kPerTile;
        m_u[1][3] = (float)tileTexel0;
        m_u[2][0] = m_up3[0], m_u[2][1] = m_up3[1], m_u[2][2] = m_up3[2], m_u[2][3] = fmaxf(0.0f, m_night);
    }
    bool up()
    {
        if (m_up)
            return true;
        const bgfx::Caps* caps = bgfx::getCaps();
        bgfx::TextureFormat::Enum fmt = bgfx::TextureFormat::RGBA32F;
        if (caps && !(caps->formats[fmt] & BGFX_CAPS_FORMAT_TEXTURE_2D))
            fmt = bgfx::TextureFormat::RGBA16F;
        if (fmt == bgfx::TextureFormat::RGBA16F)
            return false;                               // (the records need float precision; the pass stays off)
        bgfx::TextureHandle t = bgfx::createTexture2D(kTex, kTex, false, 1, fmt, BGFX_SAMPLER_POINT);
        if (!bgfx::isValid(t))
            return false;
        m_tex = t.idx;
        static float none[kTex * kTex * 4];
        for (float& v : none)
            v = -1.0f;
        bgfx::updateTexture2D(t, 0, 0, 0, 0, kTex, kTex, bgfx::copy(none, sizeof none));
        m_uCity = bgfx::createUniform("u_rmCity", bgfx::UniformType::Vec4, 3);
        m_sCity = bgfx::createUniform("s_rmCity", bgfx::UniformType::Sampler);
        return m_up = true;
    }
    // HULK_NIGHT_DUMP=a:b[:path] (development): the sources of presented frames a..b (the draw's frame numbering)
    bool dumpOn(uint32_t frame)
    {
        static int state = -1;
        static uint32_t a, b;
        if (state < 0) {
            state = 0;
            if (const char* e = getenv("HULK_NIGHT_DUMP")) {
                char path[512] = "night-dump.txt";
                if (sscanf(e, "%u:%u:%511s", &a, &b, path) >= 2 && (m_dump = fopen(path, "w")))
                    state = 1;
            }
        }
        bool on = state > 0 && frame >= a && frame <= b;
        m_dumpThis |= on;
        return on;
    }
    // HULK_NIGHT_AB=N: the pass off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = envInt("HULK_NIGHT_AB");
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
                fprintf(stderr, "hulk-app: night lights cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1], m_abCpu[0] / m_abN[0],
                        m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1], st ? (unsigned)st->width : 0,
                        st ? (unsigned)st->height : 0);
        }
    }

    struct Found {
        float pos[3], size, colour[3];
        uint32_t texture;
        int car = kNoCar;                               // (a car was found: dir is its light's direction)
        int cls = kNoCar;                               // (a white or red glow: a vehicle light if it moves)
        float dir[3] = {0, 0, 0};
        float front[3] = {0, 0, 0};                     // (a tail light on a car: its headlight's place)
    };
    struct Bounds {
        float lo[3], hi[3];
    };
    struct GeoVtx {
        float pos[3], uv[2][2];
    };
    struct Geo {
        std::shared_ptr<std::vector<GeoVtx>> v;
        uint32_t owner = 0, lastFrame = 0, writes = 0;
    };
    struct Car {
        float centre[3], axis[3];                       // world space; axis: the length, horizontal, unit
        float half, halfW, height;
        int la;                                         // (the model axis along its length: axis is its + direction)
    };
    struct Shop {
        float c[3], half[3];                            // world space: the segment's middle (at the light's height), half
        float colour[3];
        float glass, foot;
        int64_t cell;
        bool lit;
    };
    struct Built {
        uint32_t vb = 0, ib = 0, lastDrawn = 0;
        float foot = 1e30f, fade = 0;
        std::vector<Shop> shops;
    };
    std::unordered_map<uint32_t, Bounds> m_bounds;     // sink vertex buffer -> its box (model space)
    std::unordered_map<uint32_t, Geo> m_geo;           // sink vertex buffer -> positions, uv sets 0 and 1
    std::unordered_map<uint32_t, std::shared_ptr<const std::vector<uint16_t>>> m_ib;
    std::unordered_map<uint64_t, Built> m_built;       // (vertex buffer, index buffer, count) -> its shop fronts
    std::unordered_map<uint32_t, int> m_vbUse, m_ibUse;
    std::unordered_set<int64_t> m_shopCells;
    std::unordered_map<int64_t, float> m_footGrid;   // (kept while the location lasts: a few thousand cells)
    std::unordered_set<uint32_t> m_buildingHashes;
    std::vector<Car> m_cars;
    size_t m_shopTotal = 0;
    float m_footMin = 1e30f, m_ground = 1e30f;
    // HULK_NIGHT_CARS=headStrength,headRadius,headCos,headTilt,tailStrength,tailRadius (wlook4)
    float m_headK = 0.6f, m_headR = 22.0f, m_headCos = 0.80f, m_headTilt = 0.10f, m_tailK = 0.6f, m_tailR = 7.0f;
    // HULK_NIGHT_SHOPS=strength,radius,far,lit,height (wlook4)
    float m_shopK = 1.8f, m_shopR = 9.0f, m_shopFar = 80.0f, m_shopLit = 0.72f, m_shopHeight = 1.7f;
    double m_carSum = 0, m_shopPlacedSum = 0, m_spotSum = 0;
    unsigned m_dbg[12] = {};
    struct Small {
        float c[3] = {0, 0, 0}, size = 0, col[3] = {1, 1, 1};
    };
    std::unordered_map<uint32_t, Small> m_small;       // small prim buffers (<= 512 vertices): their bounds and colour
    std::unordered_map<uint32_t, uint32_t> m_ownerOf;
    std::vector<Found> m_found;
    std::vector<Cached> m_cache;
    int m_on = 0;
    bool m_haveView = false, m_viewKnown = false, m_placed = false, m_up = false, m_fogKnown = false;
    uint16_t m_worldPass = 0xffff;
    float m_view[3][4] = {}, m_inv[3][3] = {}, m_proj[16] = {}, m_up3[3] = {0, 1, 0};
    float m_sphere[4 * kMaxLights] = {};
    float m_u[3][4] = {};
    int m_count = 0;
    uint32_t m_present = 0;
    float m_fogSum[3] = {0, 0, 0}, m_fog[3] = {0, 0, 0};
    unsigned m_fogN = 0;
    float m_night = -1.0f;
    float m_strength = 3.0f, m_radiusScale = 8.0f, m_minR = 10.0f, m_maxR = 24.0f, m_dayStrength = 0.0f;
    float m_maxSize = 14.0f, m_warm = 0.7f;
    uint16_t m_tex = kInvalid;
    bgfx::UniformHandle m_uCity = BGFX_INVALID_HANDLE, m_sCity = BGFX_INVALID_HANDLE;
    FILE* m_dump = nullptr;
    bool m_dumpThis = false;
    unsigned m_frames = 0;
    double m_srcSum = 0, m_placedSum = 0;
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};
};

NightLightsPass s_pass;
rm::Registrar s_reg(&s_pass);

} // namespace

bool rm::nightLightsActive() { return s_pass.active(); }
bool rm::nightLightsTouch(const float centre[3], float radius) { return s_pass.touch(centre, radius); }
void rm::nightLightsBind(const DrawPacket& p) { s_pass.bind(s_pass.receives(p), 5); }
bool rm::nightLightsBindPost(uint8_t stage)
{
    if (!s_pass.active())
        return false;
    s_pass.bind(true, stage);
    return true;
}
float rm::nightAmount() { float n = s_pass.night(); return n < 0 ? 0 : n; }
bool rm::nightFogColour(float rgb[3]) { return s_pass.fog(rgb); }
bool rm::frameCamera(float view[3][4], float inv[3][3], float proj[16]) { return s_pass.camera(view, inv, proj); }
