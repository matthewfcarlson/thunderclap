// Water (wwater1, D249/D250, docs/water.md; Video Options > Water: Original / Enhanced).
//
// The game's water is flat: the sea around the city and the dam's lake are one big plane each at y = 0 (the location's
// `waterShape`, a "simple" shader, the dark teal WATER2_TILE / WATER3_TILE alpha-blended at 80-94% with baked vertex
// colours), the outskirts' river is opaque WATEROS / waterOS ground in its rooms (y = -25.2), Banner's cabin has a pond.
// With the row on, this pass gives those draws the runner's program vs_px_ff + fs_px_water (shaders/fs_px_water.sc,
// rm_water.sh): world-space ripples, refraction of what is under the water and a depth-dependent colour (copies of the
// scene's colour and linear depth taken once a frame, in a split view, before the first blended water draw), Schlick's
// Fresnel towards the sky's colour, the sun's glint, and foam and a soft edge at the shore. The reflection pass
// (ssr.cpp) draws the water into its G-buffer with the same rippled normal, so screen-space reflections land on it.
//
// A water draw: the world pass, fixed function, unlit, shader kind 0 (simple), one texture stage, a rigid modelview,
// opaque or src-alpha / inv-src-alpha blended, never additive (waterfalls and spray keep the game's look), depth
// tested, no stencil or occlusion query, its vertices one level sheet at least 8 units across (the sea is streamed each
// frame: transient vertices; the river and the pond are room buffers), and its texture's mean colour (texpack_mean, the
// game's own level 0) blue-green: red well below green and blue, green and blue alike. On disc that colour also takes
// signs, neon, lightmaps and reflection maps; those are other shader kinds, vertical or small. The program itself keeps
// the faithful texture x colour on faces that are not level. The ripples live in the draw's model space (the sea's and
// the rooms' are the world's), so they need no camera; the copies need the world's projection (the sea is sometimes
// drawn before the rooms, among the sky's draws: then it has none, and the reflection pass leaves it out).
// Output only: nothing here reads or writes the module's memory.
#include "water.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unordered_map>
#include <unordered_set>

#include <bgfx/bgfx.h>

#include "interp.h"
#include "nightlights.h"
#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"
#include "shadows.h"
#include "texpack.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);
extern "C" uint32_t hulk_gfx_sink_scene_hdr();

namespace {

int logLevel()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_WATER_LOG") ? atoi(getenv("HULK_WATER_LOG")) : 0;
    return on;
}

// a texture's mean colour (alpha-weighted, 0..1) reads as water: dark teal, sea green, blue-green
bool waterColour(const float m[4])
{
    float s = m[0] + m[1] + m[2];
    if (s < 0.03f || m[3] < 0.9f)
        return false;
    float kr = m[0] / s, kg = m[1] / s, kb = m[2] / s;
    return kg - kr > 0.06f && kb - kr > 0.04f && fabsf(kg - kb) < 0.07f;
}

class WaterPass;
WaterPass* s_pass;

class WaterPass final : public rm::Pass {
  public:
    WaterPass() { s_pass = this; }
    const char* name() const override { return "water"; }
    // (late: after the night lights' pass (6) has the frame's camera; the draw hook binds the program's samplers after
    // every pass that submits from the same draw's hooks: the reflections' G-buffer 7, ambient occlusion 25, the
    // atmosphere 30, soft particles 35)
    int order() const override { return 36; }
    void settingsChanged(const rm::Settings& s) override
    {
        int on = s[rm::kWater] != 0;
        if (on != m_on)
            fprintf(stderr, "hulk-app: water %s\n", on ? "enhanced" : "original");
        m_on = on;
        // HULK_WATER=ripples,refraction,clarity,foam,shore,edge,glint,sky,ssr,shade (development tuning)
        if (const char* e = getenv("HULK_WATER"))
            sscanf(e, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &m_ripple, &m_refr, &m_clarity, &m_foam, &m_shore, &m_edge, &m_glint,
                   &m_sky, &m_ssr, &m_shade);
    }
    bool midFrame() const override { return m_on && !m_abOff; }
    void late(DrawPacket& p) override
    {
        if (!m_on || m_abOff)
            return;
        // the world's pass: the game pass of the frame's first room draw (shader kind 1/2, unlit, opaque); the sea is
        // sometimes drawn before it (with the sky's draws): then the previous frame's world pass, and no copies
        if (!m_worldKnown && p.viewMode == 0 && p.vertexProgram == 0 && !p.state.blend && p.state.depthWrite &&
            !p.lighting && p.transient == kSinkNone && (p.shaderKind == 1 || p.shaderKind == 2)) {
            m_worldPass = rm::currentGamePass();
            m_worldKnown = m_worldEver = true;
            return;
        }
        if (!m_worldEver || !water(p))
            return;
        uint16_t prog = rm::program("vs_px_ff", "fs_px_water");
        if (prog == rm::kNoHandle)
            return;
        // the copies (refraction, depth) only behind a blended surface drawn in the world's light with the world's
        // projection, once the world's opaque draws are in
        bool copies = p.state.blend && m_worldKnown && camera() && sameProjection(p);
        if (copies && !m_copied)
            copyScene();
        m_lateIndex = p.drawIndex, m_lateFrame = p.frame, m_lateCopies = copies && m_copyOk;
        if (logLevel())
            m_cover = fmaxf(m_cover, coverage(p));
        p.pipeline = prog;
        m_prog = prog;
        m_draws++, m_frameDraws++;
        if (p.state.blend)
            m_blended++;
    }
    // a prim buffer written: it is a water candidate when it is one level sheet (every vertex at one height; a room's
    // and the location's vertices are in world space) at least kMinSide units across
    void vertices(uint32_t buf, const SinkVertexData& d) override
    {
        Box b;
        if (flatSheet(d.vertices, d.count, &b))
            m_flat[buf] = b;
        else
            m_flat.erase(buf);
    }
    void buffersDropped(uint32_t buf) override { m_flat.erase(buf); }
    void draw(const DrawPacket& p) override
    {
        if (!m_on || m_abOff || m_prog == rm::kNoHandle || p.pipeline != m_prog)
            return;
        bind(p);
    }
    void frame() override
    {
        abCost();
        if (logLevel() && ++m_frames % 300 == 0) {
            if (m_draws)
                fprintf(stderr, "hulk-app: water: present %u: %.2f water draws a frame (%.2f blended), %u copies\n",
                        m_lastFrame, m_draws / 300.0, m_blended / 300.0, m_copies);
            m_draws = m_blended = 0, m_copies = 0;
        }
        if (logLevel() && m_cover >= 0.05f && m_lastFrame >= m_coverNext) {
            fprintf(stderr, "hulk-app: water: present %u covers %.0f%% of the view\n", m_lastFrame, 100.0f * m_cover);
            m_coverNext = m_lastFrame + 30;
        }
        m_cover = 0;
        m_worldKnown = m_copied = m_copyOk = false;
        m_frameDraws = 0;
        m_frameNo++;
    }

    bool taken(const DrawPacket& p) const { return m_on && !m_abOff && m_prog != rm::kNoHandle && p.pipeline == m_prog; }
    void rippleUniforms(const DrawPacket& p)
    {
        ensureUniforms();
        rippleConstants(p);
        bgfx::setUniform(m_uWater, m_water, 7);
    }
    void rebind(const DrawPacket& q)
    {
        if (taken(q))
            bindTextures();
    }

  private:
    struct Box { float lo[3], hi[3]; };
    static bool flatSheet(const SinkVertex* v, uint32_t n, Box* box = nullptr)
    {
        if (!v || n < 3)
            return false;
        float lo[3] = {v[0].pos[0], v[0].pos[1], v[0].pos[2]}, hi[3] = {lo[0], lo[1], lo[2]};
        for (uint32_t i = 1; i < n; i++)
            for (int k = 0; k < 3; k++)
                lo[k] = fminf(lo[k], v[i].pos[k]), hi[k] = fmaxf(hi[k], v[i].pos[k]);
        if (box)
            memcpy(box->lo, lo, sizeof lo), memcpy(box->hi, hi, sizeof hi);
        return hi[1] - lo[1] < 0.05f && fmaxf(hi[0] - lo[0], hi[2] - lo[2]) >= kMinSide;
    }
    // HULK_WATER_LOG: the share of the screen a water draw covers (its triangles, or a buffer's level box, clipped to
    // the view; occlusion not counted): finds the frames where the water can be seen
    float coverage(const DrawPacket& p)
    {
        const float* c = p.vertexConstants;
        const float* P = c + 16;
        auto clip = [&](const float* m, float out[4]) {
            float v[4] = {c[0] * m[0] + c[1] * m[1] + c[2] * m[2] + c[3], c[4] * m[0] + c[5] * m[1] + c[6] * m[2] + c[7],
                          c[8] * m[0] + c[9] * m[1] + c[10] * m[2] + c[11], 1.0f};
            for (int i = 0; i < 4; i++)
                out[i] = P[4 * i] * v[0] + P[4 * i + 1] * v[1] + P[4 * i + 2] * v[2] + P[4 * i + 3] * v[3];
        };
        auto area = [&](float (*poly)[4], int n) {
            // clip against w > 1e-3 and the four sides (x, y within +-w), then the polygon's area in NDC
            float a[16][4], b[16][4];
            memcpy(a, poly, sizeof(float) * 4 * n);
            for (int pl = 0; pl < 5 && n; pl++) {
                int m = 0;
                for (int i = 0; i < n && m < 15; i++) {
                    const float* p0 = a[i];
                    const float* p1 = a[(i + 1) % n];
                    auto d = [&](const float* q) {
                        return pl == 0 ? q[3] - 1e-3f : pl == 1 ? q[3] - q[0] : pl == 2 ? q[3] + q[0]
                             : pl == 3 ? q[3] - q[1] : q[3] + q[1];
                    };
                    float d0 = d(p0), d1 = d(p1);
                    if (d0 >= 0)
                        memcpy(b[m++], p0, sizeof b[0]);
                    if ((d0 >= 0) != (d1 >= 0) && m < 15) {
                        float t = d0 / (d0 - d1);
                        for (int k = 0; k < 4; k++)
                            b[m][k] = p0[k] + t * (p1[k] - p0[k]);
                        m++;
                    }
                }
                n = m;
                memcpy(a, b, sizeof(float) * 4 * n);
            }
            float s = 0;
            for (int i = 0; i < n; i++) {
                const float* p0 = a[i];
                const float* p1 = a[(i + 1) % n];
                s += p0[0] / p0[3] * (p1[1] / p1[3]) - p1[0] / p1[3] * (p0[1] / p0[3]);
            }
            return fabsf(s) * 0.5f / 4.0f;                   // (NDC is 2 x 2)
        };
        float sum = 0;
        if (p.transient != kSinkNone) {
            uint32_t n = 0;
            const SinkVertex* v = rm::transientVertices(p, &n);
            for (uint32_t i = 0; v && i + 2 < n && i + 2 < p.vertexCount; i += 3) {
                float tri[3][4];
                for (int k = 0; k < 3; k++)
                    clip(v[i + k].pos, tri[k]);
                sum += area(tri, 3);
            }
        } else {
            auto it = m_flat.find(p.vertexBuffer);
            if (it == m_flat.end())
                return 0;
            const Box& b = it->second;
            float q[4][3] = {{b.lo[0], b.lo[1], b.lo[2]}, {b.hi[0], b.lo[1], b.lo[2]}, {b.hi[0], b.lo[1], b.hi[2]},
                             {b.lo[0], b.lo[1], b.hi[2]}};
            float quad[4][4];
            for (int k = 0; k < 4; k++)
                clip(q[k], quad[k]);
            sum = area(quad, 4);
        }
        return fminf(sum, 1.0f);
    }
    static constexpr float kMinSide = 8.0f;
    // HULK_WATER_LOG=4: every draw of a water-coloured texture, once per texture and reason it was not taken
    void why(const DrawPacket& p, const char* reason)
    {
        if (logLevel() < 4 || !p.stage[0].ordinal)
            return;
        float m[4];
        if (!texpack_mean(p.stage[0].ordinal, m) || !waterColour(m))
            return;
        uint64_t key = (uint64_t)p.stage[0].ordinal << 8 ^ (uint64_t)(uintptr_t)reason;
        if (!m_whys.insert(key).second)
            return;
        fprintf(stderr, "hulk-app: water: texture %u (mean %.3f %.3f %.3f) at present %u not taken: %s (kind %u, vp %u, "
                "lit %u, blend %u %u/%u, depth %u/%u, pass %u/%u, %u vertices, transient %d)\n", p.stage[0].ordinal, m[0],
                m[1], m[2], p.frame, reason, p.shaderKind, p.vertexProgram, p.lighting, p.state.blend, p.state.srcBlend,
                p.state.dstBlend, p.state.depthTest, p.state.depthWrite, rm::currentGamePass(), m_worldPass,
                p.vertexCount, p.transient != kSinkNone);
    }
    bool water(const DrawPacket& p)
    {
        bool r = waterTest(p);
        if (!r)
            why(p, m_reason);
        return r;
    }
    bool waterTest(const DrawPacket& p)
    {
        m_reason = "draw";
        if (p.viewMode != 0 || p.vertexProgram != 0 || p.lighting || p.shaderKind != 0 || p.query != kSinkNone ||
            p.state.stencil || !p.state.writeMask || !p.state.depthTest || !p.vertexConstants ||
            p.vertexConstantCount < 8 || p.pipeline == kSinkNone || rm::currentGamePass() != m_worldPass)
            return false;
        m_reason = "blend";
        if (p.state.blend && !(p.state.blendOp == kBlendAdd && p.state.srcBlend == kBlendSrcAlpha &&
                               p.state.dstBlend == kBlendInvSrcAlpha))
            return false;
        m_reason = "stages";
        if (p.frag[8][0] > 1.5f || !p.stage[0].ordinal)           // (one texture stage)
            return false;
        float m[4];
        bool known = texpack_mean(p.stage[0].ordinal, m);
        if (logLevel() >= 3 && (!known || !waterColour(m)) && m_seenOther.insert(p.stage[0].ordinal).second &&
            (p.transient != kSinkNone || m_flat.count(p.vertexBuffer)))
            fprintf(stderr, "hulk-app: water: not water: texture %u (mean %.3f %.3f %.3f) at present %u: level sheet, %s, "
                    "%u vertices\n", p.stage[0].ordinal, known ? m[0] : -1.0f, known ? m[1] : -1.0f, known ? m[2] : -1.0f,
                    p.frame, p.state.blend ? "blended" : "opaque", p.vertexCount);
        if (!known || !waterColour(m))
            return false;
        m_reason = "not a level sheet";
        // one level sheet of water (the sea's plane, a river's or a pond's surface), never a sign or a box's top
        if (p.transient != kSinkNone) {
            uint32_t n = 0;
            const SinkVertex* v = rm::transientVertices(p, &n);
            if (!flatSheet(v, n))
                return false;
        } else if (!m_flat.count(p.vertexBuffer)) {
            return false;
        }
        m_reason = "modelview";
        // a rigid, unscaled modelview (a placed or world-space object: the location's sea, a room's river)
        if (!rigid(p.vertexConstants))
            return false;
        m_lastFrame = p.frame;
        if (logLevel() >= 2 && m_seen.emplace(p.stage[0].ordinal, p.frame).second) {
            bool cam = camera();
            const float* c = p.vertexConstants;
            fprintf(stderr, "hulk-app: water: texture %u (mean %.3f %.3f %.3f) first at present %u: %s, %u vertices%s, "
                    "combiner %s, %s, world projection %s, modelview t (%.2f %.2f %.2f) view t (%.2f %.2f %.2f)\n",
                    p.stage[0].ordinal, m[0], m[1], m[2], p.frame, p.state.blend ? "blended" : "opaque", p.vertexCount,
                    p.transient != kSinkNone ? " (transient)" : "", p.combinerKey ? p.combinerKey : "?",
                    m_worldKnown ? "in the world pass" : "before the rooms", cam && sameProjection(p) ? "yes" : "no",
                    c[3], c[7], c[11], cam ? m_view[0][3] : 0.0f, cam ? m_view[1][3] : 0.0f, cam ? m_view[2][3] : 0.0f);
        }
        return true;
    }
    // the frame's camera (rm::frameCamera) and the ripples' constants from it, once a frame
    bool camera()
    {
        if (m_camFrame == m_frameNo)
            return m_camOk;
        m_camFrame = m_frameNo;
        float inv[3][3];
        m_camOk = rm::frameCamera(m_view, inv, m_proj);
        return m_camOk;
    }
    bool sameProjection(const DrawPacket& p) const
    {
        if (p.vertexConstantCount < 8)
            return false;
        // (the scale and depth terms: TAA jitters the draws' x / y offsets after the camera is taken)
        static const int kTerms[6] = {0, 5, 10, 11, 14, 15};
        const float* pr = p.vertexConstants + 16;
        for (int i : kTerms)
            if (fabsf(pr[i] - m_proj[i]) > 1e-4f * (1.0f + fabsf(m_proj[i])))
                return false;
        return true;
    }
    static bool rigid(const float* c)
    {
        for (int j = 0; j < 3; j++) {
            float l = c[j] * c[j] + c[4 + j] * c[4 + j] + c[8 + j] * c[8 + j];
            if (fabsf(l - 1.0f) > 0.01f)
                return false;
        }
        return true;
    }
    // the ripples' constants for a draw: camera space -> the draw's model space (the sea's and the rooms' model space is
    // the world's, up to a fixed offset, so the waves stay put as the camera moves), its modelview's rows (normals)
    void rippleConstants(const DrawPacket& p)
    {
        const float* c = p.vertexConstants;
        // modelview rows c0..c2 (camera = M x (model, 1)); a rigid M: its inverse is the transpose
        for (int i = 0; i < 3; i++) {
            float w = 0;
            for (int j = 0; j < 3; j++)
                w -= c[4 * j + i] * c[4 * j + 3];
            m_water[i][0] = c[i], m_water[i][1] = c[4 + i], m_water[i][2] = c[8 + i], m_water[i][3] = w;
        }
        for (int i = 0; i < 3; i++)
            m_water[3 + i][0] = c[4 * i], m_water[3 + i][1] = c[4 * i + 1], m_water[3 + i][2] = c[4 * i + 2],
                         m_water[3 + i][3] = 0;
        m_water[6][0] = (float)fmod(interp_display_time(), 3600.0);
        m_water[6][1] = m_ripple;
        m_water[6][2] = 0.95f;                                   // (level: within ~18 degrees)
        m_water[6][3] = m_ssr;
    }
    // the scene so far: its colour (blit) and its depth as linear camera depth, in a view before the rest of the
    // world pass (the water draw goes after it)
    void copyScene()
    {
        m_copied = true;                                // (one try a frame)
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || colour == kSinkNone || depth == kSinkNone || !w || !h)
            return;
        uint16_t prog = rm::program("vs_rm_quad", "fs_rm_softdepth");
        if (prog == rm::kNoHandle)
            return;
        if (!m_depthFormat) {
            const bgfx::Caps* caps = bgfx::getCaps();
            const uint32_t need = BGFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER | BGFX_CAPS_FORMAT_TEXTURE_2D;
            m_depthFormat = caps && (caps->formats[bgfx::TextureFormat::R32F] & need) == need
                                ? bgfx::TextureFormat::R32F : bgfx::TextureFormat::R16F;
        }
        uint32_t sf = hulk_gfx_sink_scene_hdr() ? bgfx::TextureFormat::RGBA16F : bgfx::TextureFormat::BGRA8;
        if (!m_depth.ensure(w, h, m_depthFormat, false, false) || !m_colour.ensure(w, h, sf, true))
            return;
        uint16_t v;
        if (!rm::viewsHere(1, &v))
            return;
        m_w = w, m_h = h;
        bgfx::TextureRegion dst, src;
        dst.init(bgfx::TextureHandle{m_colour.tex});
        src.init(bgfx::TextureHandle{(uint16_t)colour});
        bgfx::blit(v, dst, src);
        float a[4] = {m_proj[10], m_proj[11], m_proj[14], m_proj[15]};   // (c6.z, c6.w, c7.z, c7.w)
        rm::viewInto(v, m_depth.fb, w, h);
        rm::texture(0, (uint16_t)depth, BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT);
        rm::uniform("u_rmSoftCopy", a);
        rm::quad(v, prog, BGFX_STATE_WRITE_R);
        m_copyOk = true;
        m_copies++;
    }

    void ensureUniforms()
    {
        if (m_up)
            return;
        m_uWater = bgfx::createUniform("u_rmWater", bgfx::UniformType::Vec4, 7);
        m_uK = bgfx::createUniform("u_rmWaterK", bgfx::UniformType::Vec4, 5);
        m_sScene = bgfx::createUniform("s_rmWaterScene", bgfx::UniformType::Sampler);
        m_sDepth = bgfx::createUniform("s_rmWaterDepth", bgfx::UniformType::Sampler);
        const uint32_t white = 0xffffffffu;
        m_dummy = bgfx::createTexture2D(1, 1, false, 1, bgfx::TextureFormat::BGRA8,
                                        BGFX_SAMPLER_POINT | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP,
                                        bgfx::copy(&white, 4));
        m_up = true;
    }
    // every sampler the program declares is bound (Vulkan reads an unbound one as garbage)
    void bindTextures()
    {
        ensureUniforms();
        const uint32_t clampLin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        bool ok = m_copyOk && m_colour.tex != rm::kNoHandle && m_depth.tex != rm::kNoHandle;
        rm::bindTexture(4, m_sScene.idx, (ok ? bgfx::TextureHandle{m_colour.tex} : m_dummy).idx, clampLin);
        rm::bindTexture(5, m_sDepth.idx, (ok ? bgfx::TextureHandle{m_depth.tex} : m_dummy).idx,
                         clampLin | BGFX_SAMPLER_POINT);
    }
    void bind(const DrawPacket& p)
    {
        ensureUniforms();
        bool ok = m_lateCopies && m_lateIndex == p.drawIndex && m_lateFrame == p.frame;
        rippleConstants(p);
        float night = rm::nightAmount();
        float sky[3] = {p.frag[1][0], p.frag[1][1], p.frag[1][2]};
        if (!p.fog && !rm::nightFogColour(sky))
            sky[0] = 0.5f, sky[1] = 0.55f, sky[2] = 0.6f;
        static const int show = getenv("HULK_WATER_SHOW") ? atoi(getenv("HULK_WATER_SHOW")) : 0;
        float k[5][4] = {
            {m_w ? 1.0f / m_w : 0.0f, m_h ? 1.0f / m_h : 0.0f, m_refr, ok ? 1.0f : 0.0f},
            {sky[0], sky[1], sky[2], m_sky},
            {0, 0, 0, 0},
            {m_foam, m_shore, m_clarity, m_edge},
            {(float)show, m_shade, 0, 0},
        };
        uint16_t atlas = rm::kNoHandle;
        const float* sc = rm::shadowConstants(false, &atlas);
        if (sc) {
            float l = sqrtf(sc[36] * sc[36] + sc[37] * sc[37] + sc[38] * sc[38]);
            if (l > 1e-6f)          // (the moon's glint at night is softer than the sun's)
                k[2][0] = sc[36] / l, k[2][1] = sc[37] / l, k[2][2] = sc[38] / l,
                k[2][3] = m_glint * (1.0f - 0.6f * night);
        }
        bgfx::setUniform(m_uWater, m_water, 7);
        bgfx::setUniform(m_uK, k, 5);
        bgfx::TextureHandle scene = m_dummy, depth = m_dummy;
        if (ok)
            scene = bgfx::TextureHandle{m_colour.tex}, depth = bgfx::TextureHandle{m_depth.tex};
        const uint32_t clampLin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        rm::bindTexture(4, m_sScene.idx, scene.idx, clampLin);
        rm::bindTexture(5, m_sDepth.idx, depth.idx, clampLin | BGFX_SAMPLER_POINT);
    }

    // HULK_WATER_AB=N: the pass off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_WATER_AB") ? atoi(getenv("HULK_WATER_AB")) : 0;
        if (n <= 0)
            return;
        const bgfx::Stats* st = bgfx::getStats();
        if (st && m_abFrame > 2 && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin) {
            int i = m_abOff ? 0 : 1;
            m_abGpu[i] += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq;
            m_abCpu[i] += 1e3 * (double)(st->cpuTimeEnd - st->cpuTimeBegin) / (double)st->cpuTimerFreq;
            m_abN[i]++;
            m_abWater[i] += m_frameDraws > 0;
        }
        if (++m_abFrame >= (unsigned)n) {
            m_abFrame = 0;
            m_abOff = !m_abOff;
            if (++m_abTurns % 20 == 0 && m_abN[0] && m_abN[1])
                fprintf(stderr, "hulk-app: water cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %u with water on, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1], m_abWater[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0}, m_abWater[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_on = 0;
    bool m_up = false, m_worldKnown = false, m_worldEver = false, m_lateCopies = false, m_copied = false, m_copyOk = false, m_camOk = false;
    uint16_t m_worldPass = 0xffff, m_prog = rm::kNoHandle;
    uint32_t m_lateIndex = 0, m_lateFrame = 0, m_depthFormat = 0, m_w = 0, m_h = 0, m_lastFrame = 0;
    float m_cover = 0;
    uint32_t m_coverNext = 0;
    unsigned m_camFrame = 0, m_frameNo = 1;
    float m_view[3][4] = {}, m_proj[16] = {}, m_water[7][4] = {};
    rm::Target m_depth, m_colour;
    bgfx::UniformHandle m_uWater = BGFX_INVALID_HANDLE, m_uK = BGFX_INVALID_HANDLE;
    bgfx::UniformHandle m_sScene = BGFX_INVALID_HANDLE, m_sDepth = BGFX_INVALID_HANDLE;
    bgfx::TextureHandle m_dummy = BGFX_INVALID_HANDLE;
    // the ripples' slope scale, the refraction (uv per unit of slope), the depth over which the water turns from clear
    // to the game's opacity, the foam's strength, the shore's width and the soft edge's (units), the glint's strength,
    // the sky reflection's strength, the screen-space reflection's strength on water, the waves' shading
    float m_ripple = 1.0f, m_refr = 0.04f, m_clarity = 1.5f, m_foam = 0.8f, m_shore = 0.6f, m_edge = 0.15f,
          m_glint = 3.0f, m_sky = 0.35f, m_ssr = 0.45f, m_shade = 1.5f;
    unsigned m_frames = 0, m_copies = 0, m_frameDraws = 0;
    double m_draws = 0, m_blended = 0;
    std::unordered_map<uint32_t, uint32_t> m_seen;
    std::unordered_set<uint32_t> m_seenOther;
    std::unordered_set<uint64_t> m_whys;
    const char* m_reason = "";
    std::unordered_map<uint32_t, Box> m_flat;      // sink vertex buffers that are one level sheet (their box)
};
HULK_RM_REGISTER_PASS(WaterPass);

} // namespace

bool rm::waterDraw(const DrawPacket& p) { return s_pass && s_pass->taken(p); }
void rm::waterRippleUniforms(const DrawPacket& p)
{
    if (s_pass)
        s_pass->rippleUniforms(p);
}
void rm::waterRebind(const DrawPacket& q)
{
    if (s_pass)
        s_pass->rebind(q);
}
