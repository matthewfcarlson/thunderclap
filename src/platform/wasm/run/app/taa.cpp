// Temporal anti-aliasing (wperf1, docs/performance.md; Video Options > Anti-Aliasing: TAA, the msaa row's value 1).
// Each presented frame's scene draws are jittered by a sub-pixel offset (Halton 2,3, 8 phases: the clip-space rows of
// every vertex program's constants, rm::Pass::late, so the passes that redraw the world see the same jitter; from the
// world's first room draw on: the sky before it and frames without a world, the front end, are left alone); at the
// frame's first effect (before the game's colour pass, bloom and HUD, and before HDR's tone map; else at the end of
// the frame) the scene is resolved against its history: reprojected through the scene's depth and the camera's motion
// since the last presented frame (fs_rm_taa.sc: neighbourhood clip against ghosting, Catmull-Rom history, HDR-safe
// weights) and written back sharpened (fs_rm_taasharp.sc). Objects (the characters' skinned meshes, cars, props: every
// opaque buffer draw of the scene that is not a room) are drawn again into a velocity target with both this frame's
// and the matching draw's constants of the last presented frame (vs_rm_vel.sh: per vertex, so limbs move too; matched
// by buffers, count, program and first texture, the nearest in camera space), and their pixels reproject by it. Interpolated 60 / 120 fps frames are presented frames like
// any other: each takes the next jitter phase and reprojects from the frame before it. The scene is single-sampled
// (MSAA off) with TAA. Output only: nothing here reads or writes the module's memory.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);
extern "C" uint32_t hulk_gfx_sink_scene_hdr();

namespace {

// the first of the four clip-space rows in each vertex program's constants (bgfx_draw.cpp kPrograms; pddi shaders/vp)
int clipRow(uint32_t vp)
{
    static const int kRow[7] = {4, 2, 2, 2, 2, 14, 4};    // ff, skin, onebone, refract, skin_refract, proximity, ff2s
    return vp < 7 ? kRow[vp] : -1;
}
float halton(uint32_t i, uint32_t b)
{
    float f = 1.0f, r = 0.0f;
    for (; i; i /= b) {
        f /= (float)b;
        r += f * (float)(i % b);
    }
    return r;
}
// 4x4 rows: a = b * c
void mul4(float* a, const float* b, const float* c)
{
    float t[16];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            t[4 * i + j] = b[4 * i] * c[j] + b[4 * i + 1] * c[4 + j] + b[4 * i + 2] * c[8 + j] + b[4 * i + 3] * c[12 + j];
    memcpy(a, t, sizeof t);
}
// the inverse of an affine 4x4 (rows; last row 0 0 0 1)
bool invAffine(float* o, const float* m)
{
    float a = m[0], b = m[1], c = m[2], d = m[4], e = m[5], f = m[6], g = m[8], h = m[9], k = m[10];
    float A = e * k - f * h, B = -(d * k - f * g), C = d * h - e * g;
    float det = a * A + b * B + c * C;
    if (fabsf(det) < 1e-12f)
        return false;
    float id = 1.0f / det;
    float r[9] = {A * id, -(b * k - c * h) * id, (b * f - c * e) * id,
                  B * id, (a * k - c * g) * id, -(a * f - c * d) * id,
                  C * id, -(a * h - b * g) * id, (a * e - b * d) * id};
    for (int i = 0; i < 3; i++) {
        o[4 * i] = r[3 * i], o[4 * i + 1] = r[3 * i + 1], o[4 * i + 2] = r[3 * i + 2];
        o[4 * i + 3] = -(r[3 * i] * m[3] + r[3 * i + 1] * m[7] + r[3 * i + 2] * m[11]);
    }
    o[12] = o[13] = o[14] = 0.0f, o[15] = 1.0f;
    return true;
}

class TaaPass final : public rm::Pass {
  public:
    const char* name() const override { return "taa"; }
    // (after reflections, 7, and lighting, 10: their redraws see the jittered constants; before AO, 25, and HDR, 30:
    // the resolve's views come before HDR's tone map at the same effect)
    int order() const override { return 20; }
    void settingsChanged(const rm::Settings& s) override
    {
        bool on = s[rm::kMsaa] == 1;
        if (on != m_on)
            fprintf(stderr, "hulk-app: TAA %s\n", on ? "on" : "off");
        m_on = on;
        m_valid = false;
        if (const char* e = getenv("HULK_TAA"))          // (tuning: current frame's weight, clip gamma, sharpen)
            sscanf(e, "%f,%f,%f", &m_alpha, &m_gamma, &m_sharp);
    }
    bool midFrame() const override { return m_on && !m_abOff; }
    void sceneBegin(SinkPass&) override
    {
        m_jitter = false;
        m_resolved = false;
        m_haveCam = false;
        m_frameDrawn = 0;
        if (!midFrame())
            return;
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (!w || !h)
            return;
        m_velView = rm::kNoView;
        if (m_motion && ensureVel(w, h) && (m_velView = rm::newView()) != rm::kNoView)
            rm::viewInto(m_velView, m_vfb, w, h, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0, 1.0f);
        m_phase = (m_phase + 1) & 7;
        m_jx = (halton(m_phase + 1, 2) - 0.5f) * 2.0f / (float)w;     // (NDC: two units across the target)
        m_jy = (halton(m_phase + 1, 3) - 0.5f) * 2.0f / (float)h;
        m_jitter = true;
    }
    void late(DrawPacket& p) override
    {
        if (!m_jitter || m_resolved || p.viewMode != 0 || !p.vertexConstants || !rm::passIsScene(p.pass))
            return;
        int r = clipRow(p.vertexProgram);
        if (r < 0 || p.vertexConstantCount < (uint32_t)r + 4 || p.vertexConstantCount > kMaxConst)
            return;
        if (!m_haveCam)
            takeCamera(p);
        if (!m_haveCam)
            return;                                 // (draws before the world's first room draw, the sky, and frames
                                                    // without a world, the front end, are not jittered)
        m_velPrev = -1;
        if (m_velView != rm::kNoView)
            recordObject(p);
        memcpy(m_const, p.vertexConstants, (size_t)p.vertexConstantCount * 16);
        float* x = m_const + 4 * r;
        const float* w = m_const + 4 * (r + 3);
        for (int i = 0; i < 4; i++) {
            x[i] += m_jx * w[i];
            x[4 + i] += m_jy * w[i];
        }
        p.vertexConstants = m_const;            // (valid until the next draw: the sink copies the uniforms)
        m_drawn++, m_frameDrawn++;
        if (m_velPrev >= 0)
            velocityDraw(p);
    }
    // an object whose last frame is known: drawn again into the velocity target, jittered as the scene's draw. (Here,
    // not in a draw hook: the lighting pass's draw hook, 10, sets the draw's own textures and uniforms for the sink's
    // submit, and a draw submitted after it would take them.)
    void velocityDraw(const DrawPacket& q)
    {
        static const char* const kVs[3] = {"vs_rm_vel_ff", "vs_rm_vel_skin", "vs_rm_vel_skin_onebone"};
        uint16_t prog = rm::program(kVs[q.vertexProgram == 6 ? 0 : q.vertexProgram], "fs_rm_vel");
        const Obj& o = m_prevObjs[(size_t)m_velPrev];
        m_velPrev = -1;
        if (prog == rm::kNoHandle)
            return;
        DrawPacket v = q;
        v.pipeline = prog;
        v.pass = m_velView;
        v.query = kSinkNone;
        v.fog = 0;
        v.state.writeMask = 0xf;
        v.state.blend = 0;
        v.state.stencil = 0;
        v.state.depthTest = 1;
        v.state.depthFunc = 3;                              // (lequal)
        v.state.depthWrite = 1;
        float j[4] = {m_jx, m_jy, 0, 0};
        rm::uniform("u_rmPrev", &m_prevConst[o.c0], kVelConst);
        rm::uniform("u_rmVel", j);
        hulk_gfx_sink_submit_draw(&v);
        m_velDraws++;
    }
    void copy(uint16_t pass, const SinkTarget& dst) override
    {
        if (!active())
            return;
        SinkTarget refr = {kSinkNone, kSinkNone};
        hulk_gfx_sink_frame_copy(&refr);               // (the refraction copy of the frame: mid-scene, not the effects)
        if (dst.texture != refr.texture)
            resolve(pass);
    }
    void fx(const FxPacket& p) override
    {
        if (active())
            resolve(p.pass);
    }
    void postScene(const rm::Scene&, uint16_t&) override
    {
        if (active())
            resolve(0xffff);                            // (no effects this frame: the whole frame)
    }
    void frame() override
    {
        abCost();
        if (logOn() && ++m_frames % 300 == 0)
            fprintf(stderr, "hulk-app: taa: %u of 300 frames resolved (%u at the end), %.1f jittered draws a frame, "
                    "%.1f objects with motion, jitter phase %u\n", m_runs, m_late, m_drawn / 300.0, m_velDraws / 300.0,
                    m_phase), m_runs = m_late = 0, m_drawn = m_velDraws = 0;
        if (!m_resolved)
            m_valid = false;                            // (a frame without a resolve breaks the history)
        m_jitter = false;
        m_prevObjs.swap(m_objs);                        // (this frame's objects are the next one's last frame)
        m_prevConst.swap(m_objConst);
        m_objs.clear();
        m_objConst.clear();
    }

  private:
    enum { kMaxConst = 256 };
    static int logOn()
    {
        static int on = -1;
        if (on < 0)
            on = getenv("HULK_TAA_LOG") && atoi(getenv("HULK_TAA_LOG")) > 0;
        return on;
    }
    bool active() const { return m_jitter && !m_resolved && m_frameDrawn; }
    // the world camera: the frame's first room draw (unlit fixed function, a world shader, opaque, perspective; its
    // modelview is the view itself) before the jitter, as the reflections and shadows take it
    void takeCamera(const DrawPacket& p)
    {
        if (p.vertexProgram != 0 || p.vertexConstantCount < 8 || p.transient != kSinkNone || p.lighting ||
            p.state.blend || !p.state.depthWrite || p.shaderKind < 1 || p.shaderKind > 2)
            return;
        const float* c = p.vertexConstants;
        const float* pr = c + 16;
        if (!(fabsf(pr[14]) > 0.5f && fabsf(pr[15]) < 1e-3f && fabsf(pr[12]) < 1e-6f && fabsf(pr[13]) < 1e-6f))
            return;
        memcpy(m_proj, pr, sizeof m_proj);
        memcpy(m_view, c, 12 * sizeof(float));
        m_view[12] = m_view[13] = m_view[14] = 0.0f, m_view[15] = 1.0f;
        m_haveCam = true;
    }
    bool ensureVel(uint32_t w, uint32_t h)
    {
        if (m_vfb != rm::kNoHandle && m_vw == w && m_vh == h)
            return true;
        if (m_vfb != rm::kNoHandle)
            bgfx::destroy(bgfx::FrameBufferHandle{m_vfb});
        m_vfb = m_vtex = rm::kNoHandle;
        const uint64_t flags = BGFX_TEXTURE_RT | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        bgfx::TextureHandle t[2] = {
            bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, bgfx::TextureFormat::RGBA16F, flags),
            bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, bgfx::TextureFormat::D24S8,
                                  BGFX_TEXTURE_RT_WRITE_ONLY)};
        if (!bgfx::isValid(t[0]) || !bgfx::isValid(t[1])) {
            if (bgfx::isValid(t[0])) bgfx::destroy(t[0]);
            if (bgfx::isValid(t[1])) bgfx::destroy(t[1]);
            return false;
        }
        bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(2, t, true);
        if (!bgfx::isValid(f))
            return false;
        m_vfb = f.idx, m_vtex = t[0].idx, m_vw = w, m_vh = h;
        return true;
    }
    // an object draw (opaque buffer draw, not a room: its modelview is not the view): this frame's unjittered
    // constants kept for the next, and the last frame's match (same buffers, count, program and first texture; the
    // nearest origin in camera space, within 3 units) for the velocity draw
    void recordObject(const DrawPacket& p)
    {
        uint32_t vp = p.vertexProgram;
        if (p.transient != kSinkNone || p.state.blend || !p.state.depthWrite || p.state.stencil ||
            p.query != kSinkNone || !(vp <= 2 || vp == 6) || p.vertexConstantCount > kVelConst)
            return;
        const float* c = p.vertexConstants;
        float t[3];
        if (vp == 0 || vp == 6) {
            bool world = true;
            for (int i = 0; i < 12 && world; i++)
                world = fabsf(c[i] - m_view[i]) <= 1e-3f * (1.0f + fabsf(m_view[i]));
            if (world)
                return;
            t[0] = c[3], t[1] = c[7], t[2] = c[11];
        } else {
            if (p.vertexConstantCount < 20)
                return;
            t[0] = c[17 * 4 + 3], t[1] = c[18 * 4 + 3], t[2] = c[19 * 4 + 3];
        }
        Obj o;
        o.key = (uint64_t)p.vertexBuffer * 0x9e3779b97f4a7c15ull ^ (uint64_t)p.indexBuffer << 32 ^
                (uint64_t)p.count << 8 ^ vp ^ (uint64_t)p.stage[0].ordinal * 0x100000001b3ull;
        memcpy(o.t, t, sizeof t);
        o.c0 = (uint32_t)m_objConst.size();
        o.used = false;
        m_objConst.resize(m_objConst.size() + 4 * kVelConst, 0.0f);
        memcpy(&m_objConst[o.c0], c, (size_t)p.vertexConstantCount * 16);
        m_objs.push_back(o);
        float best = 9.0f;
        for (size_t i = 0; i < m_prevObjs.size(); i++) {
            Obj& q = m_prevObjs[i];
            if (q.key != o.key || q.used)
                continue;
            float d = (q.t[0] - t[0]) * (q.t[0] - t[0]) + (q.t[1] - t[1]) * (q.t[1] - t[1]) +
                      (q.t[2] - t[2]) * (q.t[2] - t[2]);
            if (d < best)
                best = d, m_velPrev = (int)i;
        }
        if (m_velPrev >= 0)
            m_prevObjs[(size_t)m_velPrev].used = true;
    }
    void resolve(uint16_t pass)
    {
        m_resolved = true;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        uint16_t taa = rm::program("vs_rm_quad", "fs_rm_taa"), sharp = rm::program("vs_rm_quad", "fs_rm_taasharp");
        if (fb == kSinkNone || depth == kSinkNone || !w || !h || samples > 1 || !m_haveCam || taa == rm::kNoHandle ||
            sharp == rm::kNoHandle) {
            m_valid = false;
            return;
        }
        bgfx::TextureFormat::Enum sf = hulk_gfx_sink_scene_hdr() ? bgfx::TextureFormat::RGBA16F
                                                                   : bgfx::TextureFormat::BGRA8;
        if (!m_cur.ensure(w, h, sf, true) || !m_hist[0].ensure(w, h, bgfx::TextureFormat::RGBA16F, false) ||
            !m_hist[1].ensure(w, h, bgfx::TextureFormat::RGBA16F, false))
            return;
        uint16_t v[2];
        bool ok = pass == 0xffff ? (v[0] = rm::newView()) != rm::kNoView && (v[1] = rm::newView()) != rm::kNoView
                                 : rm::viewsBefore(pass, 2, v);
        if (!ok) {
            m_valid = false;
            return;
        }
        // current camera space -> the last frame's clip: P' V' V^-1 (the reprojection; identity on a reset)
        float inv[16], m[16];
        bool reset = !m_valid || !invAffine(inv, m_view);
        if (!reset) {
            mul4(m, m_prevView, inv);
            mul4(m, m_prevProj, m);
            // a cut: the camera jumped (more than 4 units or the view turned by more than ~25 degrees)
            float dz = m_view[2] * m_prevView[2] + m_view[6] * m_prevView[6] + m_view[10] * m_prevView[10];
            float nz = sqrtf((m_view[2] * m_view[2] + m_view[6] * m_view[6] + m_view[10] * m_view[10]) *
                             (m_prevView[2] * m_prevView[2] + m_prevView[6] * m_prevView[6] +
                              m_prevView[10] * m_prevView[10]));
            if (nz > 0 && dz / nz < 0.9f)
                reset = true;
        }
        if (reset)
            memcpy(m, m_proj, sizeof m);
        const bgfx::Caps* caps = bgfx::getCaps();
        float flip = caps && caps->originBottomLeft ? 1.0f : 0.0f;
        const float* c = m_proj;
        float u0[4] = {c[0], c[5], c[2], c[6]};
        float u1[4] = {c[10], c[11], c[14], c[15]};
        float u2[4] = {c[3], c[7], m_alpha, reset ? 1.0f : 0.0f};
        float u3[4] = {flip + (m_velView != rm::kNoView ? 2.0f : 0.0f), m_gamma, 1.0f / w, 1.0f / h};
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        const uint32_t lin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        rm::Target& out = m_hist[m_cur01 ^ 1];
        rm::Target& in = m_hist[m_cur01];
        bgfx::TextureRegion dst, src;
        dst.init(bgfx::TextureHandle{m_cur.tex});
        src.init(bgfx::TextureHandle{(uint16_t)colour});
        bgfx::blit(v[0], dst, src);                      // (a view's blits run before its draws)
        rm::viewInto(v[0], out.fb, w, h);
        rm::texture(0, m_cur.tex, point);
        rm::texture(1, (uint16_t)depth, point);
        rm::texture(2, in.tex, lin);
        rm::texture(3, m_velView != rm::kNoView ? m_vtex : m_cur.tex, point);
        rm::uniform("u_rmTaa0", u0);
        rm::uniform("u_rmTaa1", u1);
        rm::uniform("u_rmTaa2", u2);
        rm::uniform("u_rmTaa3", u3);
        rm::uniform("u_rmTaaM", m, 4);
        rm::quad(v[0], taa, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        float s3[4] = {flip, m_sharp, 1.0f / w, 1.0f / h};
        rm::viewInto(v[1], (uint16_t)fb, w, h);
        rm::texture(0, out.tex, point);
        rm::uniform("u_rmTaa3", s3);
        rm::quad(v[1], sharp, BGFX_STATE_WRITE_RGB);
        m_cur01 ^= 1;
        m_valid = true;
        memcpy(m_prevView, m_view, sizeof m_view);
        memcpy(m_prevProj, m_proj, sizeof m_proj);
        m_runs++;
        m_late += pass == 0xffff;
    }
    // HULK_TAA_AB=N: TAA's jitter and resolve off and on in turns of N presented frames (the scene stays single-sampled)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_TAA_AB") ? atoi(getenv("HULK_TAA_AB")) : 0;
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
            m_valid = false;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: taa cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    bool m_on = false, m_jitter = false, m_resolved = false, m_haveCam = false, m_valid = false;
    uint32_t m_phase = 0, m_cur01 = 0, m_drawn = 0, m_frameDrawn = 0, m_frames = 0, m_runs = 0, m_late = 0;
    float m_jx = 0, m_jy = 0, m_alpha = 0.1f, m_gamma = 1.25f, m_sharp = 0.35f;
    float m_const[kMaxConst * 4];
    float m_proj[16], m_view[16], m_prevProj[16], m_prevView[16];
    rm::Target m_cur, m_hist[2];
    // motion vectors (HULK_TAA_MOTION=0: the camera's only)
    enum { kVelConst = 96 };
    struct Obj { uint64_t key; float t[3]; uint32_t c0; bool used; };
    std::vector<Obj> m_objs, m_prevObjs;
    std::vector<float> m_objConst, m_prevConst;
    bool m_motion = !getenv("HULK_TAA_MOTION") || atoi(getenv("HULK_TAA_MOTION")) != 0;
    uint16_t m_velView = rm::kNoView, m_vfb = rm::kNoHandle, m_vtex = rm::kNoHandle;
    uint32_t m_vw = 0, m_vh = 0, m_velDraws = 0;
    int m_velPrev = -1;
};
HULK_RM_REGISTER_PASS(TaaPass);

} // namespace
