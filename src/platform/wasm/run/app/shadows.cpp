// Sun shadows (wr3a, docs/hdr-shadows.md; Video Options > Shadows: Original / Low / High). A depth atlas the runner
// draws each frame from the sun's direction, before the game's scene (views taken at the frame's first scene pass,
// rm::newView): the world pass's opaque draws are drawn again into it with caster programs (the faithful vertex
// transform, then the sun's view: run/app/shaders/vs_rm_cast_*.sc) as they reach the sink. The atlas has two rows: the
// characters' and objects' depth, and the world's (the rooms: static, unlit, in world space). The lighting pass's
// per-pixel programs sample it (fs_px_stage.sh pxShadow): the baked world takes the characters' and objects' shadows
// (it already holds its own), darkened moderately where it faces the sun; characters and objects take both, on their
// key light. Low: one 1024 cascade to 60 units; High: two 2048 cascades to 30 and 150 units. wperf1: a fixed-function
// caster goes only into the cascades its bounding sphere (its prim buffer's box through its modelview) reaches. The game's own stencil
// shadow (its volumes' darkening quad) is hidden while this is on. Output only: nothing here reads or writes the
// module's memory.
#include "shadows.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unordered_map>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

namespace {

struct V3 { float x, y, z; };
V3 v3(float x, float y, float z) { return V3{x, y, z}; }
float dot(V3 a, V3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
V3 cross(V3 a, V3 b) { return v3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
V3 norm(V3 a)
{
    float l = sqrtf(dot(a, a));
    return l > 0 ? v3(a.x / l, a.y / l, a.z / l) : v3(0, -1, 0);
}

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_SHADOW_LOG") && atoi(getenv("HULK_SHADOW_LOG")) > 0;
    return on;
}

class ShadowPass;
ShadowPass* s_pass;

class ShadowPass final : public rm::Pass {
  public:
    ShadowPass() { s_pass = this; }
    const char* name() const override { return "shadows"; }
    int order() const override { return 5; }        // (before lighting: its casters are submitted before the draw's
                                                     // own uniforms are set)
    void settingsChanged(const rm::Settings& s) override
    {
        int level = s[rm::kShadows];
        if (level != m_level)
            fprintf(stderr, "hulk-app: shadows %s\n", level == 0 ? "original" : level == 1 ? "low" : "high");
        m_level = level;
        m_size = level >= 2 ? 2048 : 1024;
        m_cascades = level >= 2 ? 2 : 1;
        if (const char* e = getenv("HULK_SHADOW"))       // (tuning: baked darkening, key light, cascade 0 far, far)
            sscanf(e, "%f,%f,%f,%f", &m_baked, &m_key, &m_far0, &m_far1);
        if (const char* e = getenv("HULK_SHADOW_BIAS"))  // (tuning, in texels: normal offset, + x sin, depth, + x tan)
            sscanf(e, "%f,%f,%f,%f", &m_bias[0], &m_bias[1], &m_bias[2], &m_bias[3]);
        if (const char* e = getenv("HULK_SUN")) {        // (a fixed sun: its direction of travel, world space)
            float x, y, z;
            if (sscanf(e, "%f,%f,%f", &x, &y, &z) == 3)
                m_sunFixed = true, m_sun = norm(v3(x, y, z));
        }
    }
    bool midFrame() const override { return m_level > 0; }
    void sceneBegin(SinkPass&) override
    {
        m_haveViews = false;
        if (!m_level || m_abOff)
            return;
        int n = 2 * m_cascades;
        for (int i = 0; i < n; i++)
            if ((m_views[i] = rm::newView()) == rm::kNoView)
                return;
        m_haveViews = true;
        m_viewsSet = false;
    }
    // wperf1: each prim buffer's bounding sphere (object space), for culling casters per cascade
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (!d.count || !d.vertices)
            return;
        float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
        for (uint32_t i = 0; i < d.count; i++)
            for (int k = 0; k < 3; k++)
                lo[k] = fminf(lo[k], d.vertices[i].pos[k]), hi[k] = fmaxf(hi[k], d.vertices[i].pos[k]);
        Sphere b;
        float r2 = 0;
        for (int k = 0; k < 3; k++)
            b.c[k] = 0.5f * (lo[k] + hi[k]), r2 += 0.25f * (hi[k] - lo[k]) * (hi[k] - lo[k]);
        b.r = sqrtf(r2);
        m_bounds[sinkBuffer] = b;
    }
    void buffersDropped(uint32_t sinkBuffer) override { m_bounds.erase(sinkBuffer); }
    void packet(DrawPacket& p) override
    {
        // the game's stencil shadow: its darkening quad (a stencil-tested, blended draw) is hidden
        if (m_level && !m_abOff && p.state.stencil && p.state.blend && p.query == kSinkNone)
            p.state.writeMask = 0;
    }
    void draw(const DrawPacket& p) override
    {
        if (!m_level || m_abOff)
            return;
        if (!m_ready) {
            if (takeView(p))
                compute(p);
            return;
        }
        if (rm::currentGamePass() != m_worldPass)      // (the game's pass: views of ours may split it)
            return;
        if (p.lighting && p.lights && !m_sunFixed)
            sunFrom(p);
        if (m_haveViews && p.viewMode == 0 && !p.state.blend && p.state.depthWrite && p.state.writeMask &&
            !p.state.stencil && p.query == kSinkNone && p.transient == kSinkNone && p.vertexConstants &&
            (p.vertexProgram <= 2 || p.vertexProgram == 6))
            cast(p);
    }
    void frame() override
    {
        abCost();
        if (logOn() && ++m_frames % 300 == 0) {
            fprintf(stderr, "hulk-app: shadows: %.1f casters a frame (%.1f world; %.1f cascade draws culled), sun %.2f "
                    "%.2f %.2f (%s)\n", m_casts / 300.0, m_worldCasts / 300.0, m_culled / 300.0, m_sun.x, m_sun.y,
                    m_sun.z, m_sunFixed ? "fixed" : m_sunSeen ? "key light" : "default");
            m_casts = m_worldCasts = m_culled = 0;
        }
        m_ready = false;
    }

    const float* constants(bool takesWorld)
    {
        if (!m_level || m_abOff || !m_ready || !m_haveViews || rm::currentGamePass() != m_worldPass ||
            m_atlas.tex == rm::kNoHandle)
            return nullptr;
        m_consts[10][1] = takesWorld ? 1.0f : 0.0f;
        return &m_consts[0][0];
    }
    uint16_t atlas() const { return m_atlas.tex; }
    uint16_t dummy()
    {
        if (m_dummy == rm::kNoHandle) {
            bgfx::TextureHandle t = bgfx::createTexture2D(1, 1, false, 1, bgfx::TextureFormat::D16, BGFX_TEXTURE_RT);
            m_dummy = bgfx::isValid(t) ? t.idx : rm::kNoHandle;
        }
        return m_dummy;
    }

  private:
    // the frame's view: a static room draw's modelview (rooms are in world space)
    bool takeView(const DrawPacket& p)
    {
        if (p.vertexProgram != 0 || !p.vertexConstants || p.vertexConstantCount < 8 || p.transient != kSinkNone ||
            p.lighting || p.state.blend || !p.state.depthWrite || p.shaderKind < 1 || p.shaderKind > 2 || p.viewMode)
            return false;
        const float* c = p.vertexConstants;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                m_view[i][j] = c[4 * i + j];
        float(*m)[4] = m_view;
        float det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                    m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        if (fabsf(det) < 1e-12f || fabsf(c[16]) < 1e-6f || fabsf(c[21]) < 1e-6f)
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
        m_tanX = 1.0f / fabsf(c[16]);       // (c4.x, c5.y: the projection's scales)
        m_tanY = 1.0f / fabsf(c[21]);
        m_worldPass = rm::currentGamePass();
        return true;
    }
    V3 toWorldDir(const float* d) const
    {
        return v3(m_inv[0][0] * d[0] + m_inv[0][1] * d[1] + m_inv[0][2] * d[2],
                  m_inv[1][0] * d[0] + m_inv[1][1] * d[1] + m_inv[1][2] * d[2],
                  m_inv[2][0] * d[0] + m_inv[2][1] * d[1] + m_inv[2][2] * d[2]);
    }
    // the sun: the key light (the strongest directional light) of the frame's lit draws, in world space, smoothed
    void sunFrom(const DrawPacket& p)
    {
        int best = -1;
        float lum = 0.05f;
        for (int i = 0; i < 8; i++) {
            const SinkLight& l = p.lights[i];
            float y = 0.3f * l.diffuse[0] + 0.6f * l.diffuse[1] + 0.1f * l.diffuse[2];
            if (l.on && l.type == 3 && y > lum)
                lum = y, best = i;
        }
        if (best < 0)
            return;
        V3 w = norm(toWorldDir(p.lights[best].direction));
        if (w.y > -0.2f)                  // (a light from below or the horizon casts no useful shadow: keep the last)
            return;
        if (!m_sunSeen)
            m_sun = w, m_sunSeen = true;
        else
            m_sun = norm(v3(m_sun.x * 0.97f + w.x * 0.03f, m_sun.y * 0.97f + w.y * 0.03f, m_sun.z * 0.97f + w.z * 0.03f));
    }
    // a world row (world point -> value, a.P + o) as a camera-space row
    void camRow(V3 a, float o, float* out) const
    {
        // P_w = inv (P_c - t): a.P_w + o = (a.inv).P_c + o - (a.inv).t
        float r[3];
        for (int j = 0; j < 3; j++)
            r[j] = a.x * m_inv[0][j] + a.y * m_inv[1][j] + a.z * m_inv[2][j];
        out[0] = r[0], out[1] = r[1], out[2] = r[2];
        out[3] = o - (r[0] * m_view[0][3] + r[1] * m_view[1][3] + r[2] * m_view[2][3]);
    }
    void compute(const DrawPacket&)
    {
        m_ready = true;
        if (!m_atlas.ensure((uint32_t)(m_size * m_cascades), (uint32_t)(2 * m_size), bgfx::TextureFormat::D16))
            return;
        const bgfx::Caps* caps = bgfx::getCaps();
        bool homog = caps && caps->homogeneousDepth, bottom = caps && caps->originBottomLeft;
        float t3[3] = {m_view[0][3], m_view[1][3], m_view[2][3]};
        float zero[3] = {0, 0, 1};
        V3 cam = toWorldDir(t3);
        cam = v3(-cam.x, -cam.y, -cam.z);
        V3 fwd = norm(toWorldDir(zero));
        V3 s = m_sun;
        V3 up = fabsf(s.y) > 0.99f ? v3(1, 0, 0) : v3(0, 1, 0);
        V3 right = norm(cross(up, s)), up2 = cross(s, right);
        float splits[3] = {0.0f, m_cascades > 1 ? m_far0 : 60.0f, m_far1};      // (Low: one cascade to 60)
        memset(m_consts, 0, sizeof m_consts);
        for (int c = 0; c < m_cascades; c++) {
            float n = splits[c], f = splits[c + 1], mid = 0.5f * (n + f);
            V3 centre = v3(cam.x + fwd.x * mid, cam.y + fwd.y * mid, cam.z + fwd.z * mid);
            float hx = f * m_tanX, hy = f * m_tanY, R = sqrtf(0.25f * (f - n) * (f - n) + hx * hx + hy * hy);
            R = ceilf(R);                                   // (a radius that changes only with the field of view)
            float texel = 2.0f * R / m_size;
            m_R[c] = R;
            float cx = floorf(dot(centre, right) / texel) * texel, cy = floorf(dot(centre, up2) / texel) * texel;
            float zr = R + 250.0f, cz = dot(centre, s);
            float rx[4], ry[4], rz[4];
            camRow(v3(right.x / R, right.y / R, right.z / R), -cx / R, rx);
            camRow(v3(up2.x / R, up2.y / R, up2.z / R), -cy / R, ry);
            camRow(v3(s.x / (2 * zr), s.y / (2 * zr), s.z / (2 * zr)), (zr - cz) / (2 * zr), rz);
            // the casters: the sun's clip space in this cascade's square of the atlas (the view's rectangle)
            for (int j = 0; j < 4; j++) {
                m_cast[c][0][j] = rx[j];
                m_cast[c][1][j] = ry[j];
                m_cast[c][2][j] = homog ? 2.0f * rz[j] - (j == 3 ? 1.0f : 0.0f) : rz[j];
                m_cast[c][3][j] = j == 3 ? 1.0f : 0.0f;
            }
            // the receivers: the atlas's u, v (first row) and the depth
            float* u = m_consts[4 * c];
            float* v = m_consts[4 * c + 1];
            float* d = m_consts[4 * c + 2];
            float su = 0.5f / m_cascades, ou = (c + 0.5f) / m_cascades;
            float sv = bottom ? 0.25f : -0.25f;
            for (int j = 0; j < 4; j++) {
                u[j] = rx[j] * su + (j == 3 ? ou : 0.0f);
                v[j] = ry[j] * sv + (j == 3 ? (bottom ? 0.75f : 0.25f) : 0.0f);
                d[j] = rz[j];
            }
            // wlook1: the receiver's bias for this cascade, from its own texel (a texel of the far cascade is ~5x
            // the near one's) and the surface's slope to the sun (fs_px_stage.sh pxShadow): the normal offset
            // texel x (n0 + n1 sin), the depth bias texel x (b0 + b1 tan) in the cascade's depth units
            float* b = m_consts[4 * c + 3];
            b[0] = m_bias[0] * texel;
            b[1] = m_bias[1] * texel;
            b[2] = m_bias[2] * texel / (2.0f * zr);
            b[3] = m_bias[3] * texel / (2.0f * zr);
        }
        float sunCam[3];
        for (int i = 0; i < 3; i++)
            sunCam[i] = -(m_view[i][0] * s.x + m_view[i][1] * s.y + m_view[i][2] * s.z);
        float l = sqrtf(sunCam[0] * sunCam[0] + sunCam[1] * sunCam[1] + sunCam[2] * sunCam[2]);
        m_consts[8][0] = (float)m_cascades;
        m_consts[8][1] = splits[1];
        m_consts[8][2] = m_baked;
        m_consts[8][3] = m_key;
        for (int i = 0; i < 3; i++)
            m_consts[9][i] = l > 0 ? sunCam[i] / l : 0.0f;
        m_consts[10][0] = bottom ? -0.5f : 0.5f;                     // (the world's row)
        m_consts[10][3] = 1.0f / (m_size * m_cascades);
        m_consts[11][0] = splits[m_cascades];
    }
    // a caster: the draw again into the atlas (its row by class), once per cascade
    void cast(const DrawPacket& p)
    {
        if (m_atlas.fb == rm::kNoHandle)
            return;
        static const char* const kVs[3] = {"vs_rm_cast_ff", "vs_rm_cast_skin", "vs_rm_cast_skin_onebone"};
        uint16_t prog = rm::program(kVs[p.vertexProgram == 6 ? 0 : p.vertexProgram], "fs_rm_cast");
        if (prog == rm::kNoHandle)
            return;
        if (!m_viewsSet) {
            m_viewsSet = true;
            for (int r = 0; r < 2; r++)
                for (int c = 0; c < m_cascades; c++) {
                    uint16_t v = m_views[r * m_cascades + c];
                    bgfx::setViewFrameBuffer(v, bgfx::FrameBufferHandle{m_atlas.fb});
                    bgfx::setViewMode(v, bgfx::ViewMode::Sequential);
                    bgfx::setViewRect(v, (uint16_t)(c * m_size), (uint16_t)(r * m_size), (uint16_t)m_size,
                                      (uint16_t)m_size);
                    bgfx::setViewClear(v, BGFX_CLEAR_DEPTH, 0, 1.0f, 0);
                    bgfx::setViewTransform(v, nullptr, nullptr);
                    bgfx::touch(v);
                }
        }
        bool world = isWorld(p);
        DrawPacket q = p;
        q.pipeline = prog;
        q.query = kSinkNone;
        q.fog = 0;
        q.state.depthTest = 1;
        q.state.depthFunc = 3;                                       // (lequal)
        q.state.depthWrite = 1;
        q.state.blend = 0;
        q.state.cull = 0;
        q.state.stencil = 0;
        q.state.writeMask = 0;
        // the cascades the draw's bounding sphere reaches (fixed function: the modelview takes object space to the
        // camera's; skinned draws, whose bones place them, go into every cascade)
        bool reach[2] = {true, true};
        if (p.vertexProgram == 0 || p.vertexProgram == 6) {
            auto it = m_bounds.find(p.vertexBuffer);
            if (it != m_bounds.end() && p.vertexConstantCount >= 4) {
                const float* m = p.vertexConstants;
                const Sphere& b = it->second;
                float cc[4] = {0, 0, 0, 1}, sc = 0;
                for (int i = 0; i < 3; i++) {
                    cc[i] = m[4 * i] * b.c[0] + m[4 * i + 1] * b.c[1] + m[4 * i + 2] * b.c[2] + m[4 * i + 3];
                    sc = fmaxf(sc, sqrtf(m[i] * m[i] + m[4 + i] * m[4 + i] + m[8 + i] * m[8 + i]));
                }
                for (int c = 0; c < m_cascades; c++) {
                    const float* rx = m_cast[c][0];
                    const float* ry = m_cast[c][1];
                    float x = rx[0] * cc[0] + rx[1] * cc[1] + rx[2] * cc[2] + rx[3];
                    float y = ry[0] * cc[0] + ry[1] * cc[1] + ry[2] * cc[2] + ry[3];
                    float rr = 1.0f + b.r * sc / m_R[c];
                    reach[c] = fabsf(x) <= rr && fabsf(y) <= rr;
                }
            }
        }
        for (int c = 0; c < m_cascades; c++) {
            if (!reach[c]) {
                m_culled++;
                continue;
            }
            q.pass = m_views[(world ? 1 : 0) * m_cascades + c];
            rm::uniform("u_rmCast", &m_cast[c][0][0], 4);
            hulk_gfx_sink_submit_draw(&q);
        }
        m_casts++;
        m_worldCasts += world;
    }
  public:
    // a room: unlit fixed function, a world shader (simple, layered or layeredReflect: wlook1, the desert's ground and
    // the tutorial's buildings are `simple`), the modelview the view itself
    bool isWorld(const DrawPacket& p) const
    {
        if (!m_ready || p.vertexProgram != 0 || p.lighting || p.shaderKind > 2 || p.vertexConstantCount < 4 ||
            !p.vertexConstants)
            return false;
        const float* c = p.vertexConstants;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                if (fabsf(c[4 * i + j] - m_view[i][j]) > 1e-3f * (1.0f + fabsf(m_view[i][j])))
                    return false;
        return true;
    }

  private:
    // HULK_SHADOW_AB=N: shadows off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_SHADOW_AB") ? atoi(getenv("HULK_SHADOW_AB")) : 0;
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
                fprintf(stderr, "hulk-app: shadows cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_level = 0, m_size = 1024, m_cascades = 1;
    float m_baked = 0.45f, m_key = 0.85f, m_far0 = 30.0f, m_far1 = 150.0f;
    float m_bias[4] = {0.6f, 1.4f, 0.35f, 0.6f};
    bool m_sunFixed = false, m_sunSeen = false;
    V3 m_sun = norm(v3(0.35f, -1.0f, 0.25f));
    bool m_ready = false, m_haveViews = false, m_viewsSet = false;
    uint16_t m_views[4];
    uint16_t m_worldPass = 0;
    float m_view[3][4], m_inv[3][3], m_tanX = 1, m_tanY = 1;
    float m_cast[2][4][4];
    float m_consts[12][4];
    rm::Target m_atlas;
    uint16_t m_dummy = rm::kNoHandle;
    unsigned m_frames = 0;
    double m_casts = 0, m_worldCasts = 0, m_culled = 0;
    struct Sphere { float c[3], r; };
    std::unordered_map<uint32_t, Sphere> m_bounds;
    float m_R[2] = {1, 1};
};
HULK_RM_REGISTER_PASS(ShadowPass);

} // namespace

bool rm::shadowsOn() { return s_pass && s_pass->midFrame(); }
const float* rm::shadowConstants(bool takesWorld, uint16_t* atlas)
{
    const float* c = s_pass ? s_pass->constants(takesWorld) : nullptr;
    *atlas = c ? s_pass->atlas() : rm::kNoHandle;
    return c;
}
bool rm::shadowWorldDraw(const DrawPacket& p) { return s_pass && s_pass->isWorld(p); }
uint16_t rm::shadowDummy() { return s_pass ? s_pass->dummy() : rm::kNoHandle; }
