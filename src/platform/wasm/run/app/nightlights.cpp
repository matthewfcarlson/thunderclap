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
// Output only: nothing here reads or writes the module's memory; lights are render state rebuilt from the stream.
#include "nightlights.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "texpack.h"

using namespace hulk::pddi;

namespace {

const uint16_t kInvalid = 0xffff;
#if defined(__ANDROID__)
enum { kMaxLights = 64, kPerTile = 8 };     // (handheld budget: fewer lights, 8 a tile)
#else
enum { kMaxLights = 128, kPerTile = 16 };
#endif
enum { kTex = 64, kMaxTilesX = 32, kMaxTilesY = 32 };
enum Kind { kPoint = 0, kLamp = 1 };
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
};

class NightLightsPass final : public rm::Pass {
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
        if (!m_on)
            m_cache.clear(), m_count = 0;
    }
    void late(DrawPacket& p) override
    {
        if (p.viewMode != 0)
            return;                                 // (the camera and fog are tracked with the pass off too: atmosphere.cpp)
        if (!m_haveView && takeView(p)) {
            m_haveView = m_viewKnown = true;
            m_worldPass = rm::currentGamePass();
            place();
        } else if (!m_haveView && !m_placed && m_viewKnown) {
            place();                                // (the draws before the frame's first world draw: the last camera)
        }
        if (!p.state.blend && p.state.depthWrite && p.fog && p.vertexProgram == 0 && !p.lighting &&
            (p.shaderKind == 1 || p.shaderKind == 2) && rm::currentGamePass() == m_worldPass)
            m_fogSum[0] += p.frag[1][0], m_fogSum[1] += p.frag[1][1], m_fogSum[2] += p.frag[1][2], m_fogN++;
        if (m_haveView && m_on && !m_abOff)
            source(p);
    }
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (!d.count || !d.vertices || !d.owner || d.count > 512)
            return;
        float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
        double col[3] = {0, 0, 0};
        for (uint32_t i = 0; i < d.count; i++) {
            for (int k = 0; k < 3; k++)
                lo[k] = fminf(lo[k], d.vertices[i].pos[k]), hi[k] = fmaxf(hi[k], d.vertices[i].pos[k]);
            uint32_t c = d.vertices[i].colour0;           // (D3DCOLOR: b g r a in memory)
            col[0] += (c >> 16 & 255) / 255.0, col[1] += (c >> 8 & 255) / 255.0, col[2] += (c & 255) / 255.0;
        }
        Small s;
        for (int k = 0; k < 3; k++)
            s.c[k] = 0.5f * (lo[k] + hi[k]), s.size = fmaxf(s.size, hi[k] - lo[k]), s.col[k] = (float)(col[k] / d.count);
        m_small[d.owner] = s;
        m_ownerOf[sinkBuffer] = d.owner;
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        auto it = m_ownerOf.find(sinkBuffer);
        if (it != m_ownerOf.end()) {
            m_small.erase(it->second);
            m_ownerOf.erase(it);
        }
    }
    void postScene(const rm::Scene&, uint16_t&) override { endFrame(); }
    void frame() override
    {
        abCost();
        if (envInt("HULK_NIGHT_LOG") > 0 && ++m_frames >= 300) {
            fprintf(stderr, "hulk-app: night lights: %.1f sources, %.1f lights placed a frame, %zu cached, night %.2f "
                    "(fog %.3f %.3f %.3f)\n", m_srcSum / m_frames, m_placedSum / m_frames, m_cache.size(), m_night,
                    m_fog[0], m_fog[1], m_fog[2]);
            m_frames = 0, m_srcSum = m_placedSum = 0;
        }
    }

    // ---- for lighting.cpp and atmosphere.cpp
    bool active() const { return m_on && !m_abOff && m_count > 0; }
    bool touch(const float c[3], float r) const
    {
        if (!active())
            return false;
        for (int i = 0; i < m_count; i++) {
            const float* l = m_data + 8 * i;
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
                    float dx = e.pos[0] - f.pos[0], dy = e.pos[1] - f.pos[1], dz = e.pos[2] - f.pos[2];
                    float d2 = dx * dx + dy * dy + dz * dz, lim = fmaxf(1.0f, 0.6f * fmaxf(e.size, f.size));
                    if (d2 < lim * lim && d2 < bd && e.lastSeen != now)
                        bd = d2, best = &e;
                }
                if (best) {
                    Cached& e = *best;
                    float dx = f.pos[0] - e.origin[0], dy = f.pos[1] - e.origin[1], dz = f.pos[2] - e.origin[2];
                    e.moved = fmaxf(e.moved, sqrtf(dx * dx + dy * dy + dz * dz));
                    bool still = e.moved < kStill;
                    for (int k = 0; k < 3; k++) {
                        e.pos[k] = still ? e.pos[k] + 0.2f * (f.pos[k] - e.pos[k]) : f.pos[k];
                        e.colour[k] += 0.25f * (f.colour[k] - e.colour[k]);
                    }
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
                fprintf(m_dump, "  L %.2f %.2f %.2f size %.2f seen %u unseen %u moved %.2f fade %.2f tex %u%s\n", e.pos[0],
                        e.pos[1], e.pos[2], e.size, e.seen, now - e.lastSeen, e.moved, e.fade, e.texture,
                        e.dying ? " dying" : "");
            fflush(m_dump);
        }
        m_found.clear();
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
        struct Pick { float score; const Cached* e; float cam[3]; float r; };
        static Pick picks[1024];
        int n = 0;
        const float* P = m_proj;
        for (const Cached& e : m_cache) {
            if (e.fade <= 0.0f)
                continue;
            float c[3];
            toCam(e.pos, c);
            float r = fminf(m_maxR, fmaxf(m_minR, m_radiusScale * e.size));
            // the sphere against the frustum's sides (clip space: |x| <= w + r * |row|)
            float wc = P[12] * c[0] + P[13] * c[1] + P[14] * c[2] + P[15];
            float x = P[0] * c[0] + P[1] * c[1] + P[2] * c[2] + P[3];
            float y = P[4] * c[0] + P[5] * c[1] + P[6] * c[2] + P[7];
            float rx = r * sqrtf(P[0] * P[0] + P[1] * P[1] + P[2] * P[2] + P[12] * P[12] + P[13] * P[13] + P[14] * P[14]);
            float ry = r * sqrtf(P[4] * P[4] + P[5] * P[5] + P[6] * P[6] + P[12] * P[12] + P[13] * P[13] + P[14] * P[14]);
            float rw = r * sqrtf(P[12] * P[12] + P[13] * P[13] + P[14] * P[14]);
            if (wc < -rw || x > wc + rx || -x > wc + rx || y > wc + ry || -y > wc + ry)
                continue;
            float d = sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
            picks[n].score = e.fade * (e.colour[0] + e.colour[1] + e.colour[2]) * r / (d + 4.0f);
            picks[n].e = &e;
            memcpy(picks[n].cam, c, sizeof c);
            picks[n].r = r;
            if (++n == 1024)
                break;
        }
        std::sort(picks, picks + n, [](const Pick& a, const Pick& b) { return a.score > b.score; });
        if (n > kMaxLights)
            n = kMaxLights;
        // tiles: at most 32 across and down
        uint32_t tile = 32;
        while ((W + tile - 1) / tile > kMaxTilesX || (H + tile - 1) / tile > kMaxTilesY)
            tile *= 2;
        uint32_t tx = (W + tile - 1) / tile, ty = (H + tile - 1) / tile;
        static float data[kTex * kTex * 4];
        const uint32_t tileTexel0 = 2 * kMaxLights;          // (the lights' records first, 2 texels each)
        const uint32_t texelsPerTile = kPerTile / 4;
        static uint8_t counts[kMaxTilesX * kMaxTilesY];
        memset(counts, 0, sizeof counts);
        for (uint32_t t = 0; t < tx * ty * texelsPerTile; t++)
            for (int k = 0; k < 4; k++)
                data[4 * (tileTexel0 + t) + k] = -1.0f;
        for (int i = 0; i < n; i++) {
            const Pick& k = picks[i];
            float* rec = data + 8 * i;
            memcpy(rec, k.cam, 3 * sizeof(float));
            rec[3] = k.r;
            bool isStatic = k.e->seen >= 4 && k.e->moved < kStill;
            for (int j = 0; j < 3; j++)                 // (moving glows: effects, markers, cars; half as strong)
                rec[4 + j] = k.e->colour[j] * k.e->fade * strength * (isStatic ? 1.0f : 0.5f);
            rec[7] = isStatic ? (float)kLamp : (float)kPoint;
            memcpy(m_data + 8 * i, rec, 8 * sizeof(float));
            // its screen rectangle: the corners of the sphere's box, projected (one behind the camera: all of it)
            float x0 = 1e30f, y0 = 1e30f, x1 = -1e30f, y1 = -1e30f;
            bool all = false;
            for (int cnr = 0; cnr < 8 && !all; cnr++) {
                float q[3] = {k.cam[0] + (cnr & 1 ? k.r : -k.r), k.cam[1] + (cnr & 2 ? k.r : -k.r),
                              k.cam[2] + (cnr & 4 ? k.r : -k.r)};
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
    };
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
    float m_data[8 * kMaxLights] = {};
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
