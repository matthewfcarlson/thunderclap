// Contact shadows and bounce light (wshadow1; docs/hdr-shadows.md "Contact shadows and bounce light"; Video
// Options > Contact Shadows and Bounce Light: Off (Original) / On each). Two screen-space terms from the scene's depth
// (sampled: the sink keeps it readable while this is on) and the world pass's projection, in views of the runner's own
// in the world pass once the characters are drawn and before its translucent effects (rm::viewsHere: the first
// translucent or 2D draw after a skinned draw that follows the stencil shadow's quad; a frame without them at its first
// effect, rm::viewsBefore), so smoke, glows and shock waves are not darkened; before TAA's resolve and HDR's tone map:
// - contact shadows: from each pixel a short ray (0.8 units, 12 steps) towards the key light (the sun: the strongest
//   directional light of the frame's lit draws, smoothed in world space as the shadow pass takes it) is marched through
//   the depth; a surface in front of the ray within a thickness darkens the pixel. It finds the small-scale contact the
//   shadow map's texels miss: feet, tyres, debris and props on the street, and works without the Shadows option;
// - bounce light: 8 samples of the scene's colour in a disc of 2.5 units around each pixel, weighted by the receiver's
//   cosine and the distance, tint the pixel (one bounce of the lit surfaces nearby: the sunlit street up onto walls,
//   cars and the Hulk, his green onto the ground beside him).
// Both are computed at half size with a 4x4 Bayer rotation per pixel, blurred 4x4 with depth weights at full size (each
// of the 16 rotations once: the noise cancels without TAA, wlook3) and multiplied into the scene (destination x
// visibility x (1 + bounce)). Fixed per-pixel patterns, no history: a still scene is the same every frame. Sky (far
// depth) and the HUD (drawn after the effects) are untouched. Output only: nothing here reads or writes the module's
// memory.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);

namespace {

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_CONTACT_LOG") && atoi(getenv("HULK_CONTACT_LOG")) > 0;
    return on;
}

class ContactPass final : public rm::Pass {
  public:
    const char* name() const override { return "contact"; }
    // (after lighting, 10, whose samplers it binds again for the draw it runs before; at the first effect after
    // reflections, 7, and before TAA, 20, AO's late run, 25, and HDR, 30: the terms are in the scene's light, then
    // resolved and tone mapped)
    int order() const override { return 15; }
    void settingsChanged(const rm::Settings& s) override
    {
        int contact = s[rm::kContact] != 0, bounce = s[rm::kBounce] != 0;
        if (contact != m_contact || bounce != m_bounceOn)
            fprintf(stderr, "hulk-app: contact shadows %s, bounce light %s\n", contact ? "on" : "off",
                    bounce ? "on" : "off");
        m_contact = contact, m_bounceOn = bounce;
        // (tuning: ray length, thickness, shadow strength, bounce strength, bounce radius, fade start, fade end)
        if (const char* e = getenv("HULK_CONTACT"))
            sscanf(e, "%f,%f,%f,%f,%f,%f,%f", &m_len, &m_thick, &m_strength, &m_bounce, &m_radius, &m_fade0, &m_fade1);
    }
    bool midFrame() const override { return (m_contact || m_bounceOn) && !m_abOff; }
    void draw(const DrawPacket& p) override
    {
        if (!midFrame() || m_done)
            return;
        if (!m_haveProj) {
            // the world's view and projection: a room draw (unlit fixed function, its modelview the view, c4..c7 a
            // perspective: the sky is drawn first, with its own near and far)
            if (p.viewMode == 0 && rm::passIsScene(p.pass) && p.vertexProgram == 0 && p.vertexConstants &&
                p.vertexConstantCount >= 8 && p.transient == kSinkNone && !p.lighting && !p.state.blend &&
                p.state.depthWrite && (p.shaderKind == 1 || p.shaderKind == 2)) {
                const float* c = p.vertexConstants;
                const float* q = c + 16;
                if (fabsf(q[14]) > 0.5f && fabsf(q[15]) < 1e-3f && fabsf(q[12]) < 1e-6f && fabsf(q[13]) < 1e-6f &&
                    takeView(c)) {
                    memcpy(m_proj, q, sizeof m_proj);
                    m_haveProj = true;
                    m_worldPass = rm::currentGamePass();
                }
            }
            return;
        }
        if (rm::currentGamePass() != m_worldPass)
            return;
        if (p.lighting && p.lights && !m_sunFixed)
            sunFrom(p);
        if (p.viewMode == 0 && !p.state.blend && p.state.depthWrite) {
            m_scene = true;
            if (m_quad && (p.vertexProgram == 1 || p.vertexProgram == 2))
                m_skin = true;                          // (the characters: skinned, after the stencil shadow's quad)
            return;
        }
        if (p.state.stencil && (p.viewMode != 0 || p.state.blend))
            m_quad = true;                              // (the stencil shadow's darkening quad: hidden under Shadows)
        // wshadow1: before the world pass's translucent draws (particles, smoke, glows, shock waves: they would take
        // the darkening) and after the characters, whose depth the rays need: the first translucent or 2D draw after a
        // skinned draw that follows the stencil shadow's quad (play3: opaque rooms and objects, some characters, ~80
        // decals, the stencil volumes and their quad, the skinned characters, then props and translucent effects
        // mixed, then the particles); a frame without them takes the terms at its first effect
        if (m_skin && m_scene && !p.state.stencil && (p.viewMode != 0 || (p.state.blend && !p.state.depthWrite))) {
            run(-1);
            rm::lightingRebind(p);                      // (our quads took the samplers the lighting pass bound for it)
        }
    }
    void copy(uint16_t pass, const SinkTarget& dst) override
    {
        if (!active())
            return;
        SinkTarget refr = {kSinkNone, kSinkNone};
        hulk_gfx_sink_frame_copy(&refr);               // (the refraction copy of the frame: mid-scene, not the effects)
        if (dst.texture != refr.texture)
            run((int)pass);
    }
    void fx(const FxPacket& p) override
    {
        if (active())
            run((int)p.pass);
    }
    void frame() override
    {
        abCost();
        if (logOn() && ++m_frames % 300 == 0) {
            fprintf(stderr, "hulk-app: contact: %u of 300 frames (%u at the first effect), sun %.2f %.2f %.2f (%s) key "
                    "%.2f\n", m_runs - m_runs0, m_late,
                    m_sun[0], m_sun[1], m_sun[2], m_sunFixed ? "fixed" : m_sunSeen ? "key light" : "default", m_key);
            m_runs0 = m_runs, m_late = 0;
        }
        m_done = m_haveProj = m_scene = m_skin = m_quad = false;
    }

  private:
    bool active() const { return midFrame() && !m_done && m_haveProj && m_scene; }
    // the frame's view (a room's modelview: rooms are in world space) and its inverse rotation
    bool takeView(const float* c)
    {
        float m[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
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
    // the key light (the strongest directional light of a lit draw, camera space) into world space, smoothed; a light
    // from below or the horizon is ignored (as the shadow pass's sun, shadows.cpp)
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
        const float* d = p.lights[best].direction;
        float w[3];
        for (int i = 0; i < 3; i++)
            w[i] = m_inv[i][0] * d[0] + m_inv[i][1] * d[1] + m_inv[i][2] * d[2];
        float l = sqrtf(w[0] * w[0] + w[1] * w[1] + w[2] * w[2]);
        if (l <= 0 || w[1] / l > -0.2f)
            return;
        float k = m_sunSeen ? 0.03f : 1.0f;
        for (int i = 0; i < 3; i++)
            m_sun[i] = m_sun[i] * (1 - k) + w[i] / l * k;
        m_key = m_key * (1 - k) + fminf(lum, 1.5f) * k;
        float n = sqrtf(m_sun[0] * m_sun[0] + m_sun[1] * m_sun[1] + m_sun[2] * m_sun[2]);
        for (int i = 0; i < 3; i++)
            m_sun[i] /= n > 0 ? n : 1;
        m_sunSeen = true;
    }
    // the terms in views before the rest of the current pass (gamePass < 0) or before the game pass `gamePass` goes on
    // (its first effect)
    void run(int gamePass)
    {
        m_done = true;
        m_late += gamePass >= 0;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || depth == kSinkNone || colour == kSinkNone || !w || !h)
            return;
        uint16_t ct = rm::program("vs_rm_quad", "fs_rm_contact"), apply = rm::program("vs_rm_quad", "fs_rm_contactapply");
        if (ct == rm::kNoHandle || apply == rm::kNoHandle)
            return;
        if (!m_half.ensure((w + 1) / 2, (h + 1) / 2, bgfx::TextureFormat::RGBA16F, false, false))
            return;
        // a frame buffer of the scene's colour alone (the depth is read while the terms are applied)
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
        uint16_t v[2];
        if (!(gamePass < 0 ? rm::viewsHere(2, v) : rm::viewsBefore((uint16_t)gamePass, 2, v)))
            return;
        // the toward-the-sun direction in camera space (the view takes world directions to the camera's)
        float sc[3];
        for (int i = 0; i < 3; i++)
            sc[i] = -(m_view[i][0] * m_sun[0] + m_view[i][1] * m_sun[1] + m_view[i][2] * m_sun[2]);
        float sl = sqrtf(sc[0] * sc[0] + sc[1] * sc[1] + sc[2] * sc[2]);
        for (int i = 0; i < 3; i++)
            sc[i] = sl > 0 ? sc[i] / sl : 0.0f;
        // the shadow's strength follows the key light (weak at night: the moon's or a street rig's)
        float key = fminf(1.0f, fmaxf(0.0f, (m_key - 0.1f) / 0.4f));
        const float* c = m_proj;          // rows c4, c5, c6, c7
        float u0[4] = {c[0], c[5], c[2], c[6]};
        float u1[4] = {c[10], c[11], c[14], c[15]};
        float u2[4] = {c[3], c[7], 1.0f / w, 1.0f / h};
        float u3[4] = {sc[0], sc[1], sc[2], m_contact ? m_strength * key : 0.0f};
        float u4[4] = {m_len, m_thick, m_bounceOn ? m_bounce : 0.0f, m_radius};
        float u5[4] = {m_fade0, m_fade1, 0, 0};
        const uint32_t point = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
        rm::viewInto(v[0], m_half.fb, m_half.w, m_half.h);
        rm::texture(0, (uint16_t)depth, point);
        rm::texture(1, (uint16_t)colour, BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
        rm::uniform("u_rmCt0", u0);
        rm::uniform("u_rmCt1", u1);
        rm::uniform("u_rmCt2", u2);
        rm::uniform("u_rmCt3", u3);
        rm::uniform("u_rmCt4", u4);
        rm::uniform("u_rmCt5", u5);
        rm::quad(v[0], ct, BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A);
        static const int showMode = getenv("HULK_CONTACT_SHOW") ? atoi(getenv("HULK_CONTACT_SHOW")) : 0;
        float t[4] = {1.0f / m_half.w, 1.0f / m_half.h, (float)showMode, 0};
        rm::viewInto(v[1], m_fb, w, h);
        rm::texture(0, (uint16_t)depth, point);
        rm::texture(1, m_half.tex, point);
        rm::uniform("u_rmCt1", u1);
        rm::uniform("u_rmPost0", t);
        // destination x visibility x (1 + bounce): src.rgb = vis x bounce, src.a = vis (development: the terms alone)
        rm::quad(v[1], apply, BGFX_STATE_WRITE_RGB |
                                  (showMode ? 0 : BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_DST_COLOR,
                                                                        BGFX_STATE_BLEND_SRC_ALPHA)));
        m_runs++;
    }
    // HULK_CONTACT_AB=N: the terms off and on in turns of N presented frames (GPU and render thread time a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_CONTACT_AB") ? atoi(getenv("HULK_CONTACT_AB")) : 0;
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
                fprintf(stderr, "hulk-app: contact cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u; applied %u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0, m_runs);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_contact = 0, m_bounceOn = 0;
    bool m_done = false, m_haveProj = false, m_scene = false, m_skin = false, m_quad = false;
    uint16_t m_worldPass = 0;
    float m_proj[16], m_view[3][3], m_inv[3][3];
    bool m_sunFixed = false, m_sunSeen = false;
    float m_sun[3] = {-0.58f, -0.81f, 0.07f}, m_key = 0.6f;
    float m_len = 0.8f, m_thick = 1.0f, m_strength = 0.6f, m_bounce = 1.2f, m_radius = 2.5f, m_fade0 = 60.0f,
          m_fade1 = 100.0f;
    rm::Target m_half;
    uint16_t m_fb = rm::kNoHandle;
    uint32_t m_colourOf = kSinkNone;
    unsigned m_runs = 0, m_runs0 = 0, m_frames = 0, m_late = 0;

  public:
    ContactPass()
    {
        if (const char* e = getenv("HULK_SUN")) {        // (a fixed sun, as the shadow pass's: direction of travel)
            float x, y, z;
            if (sscanf(e, "%f,%f,%f", &x, &y, &z) == 3) {
                float l = sqrtf(x * x + y * y + z * z);
                if (l > 0)
                    m_sun[0] = x / l, m_sun[1] = y / l, m_sun[2] = z / l, m_sunFixed = true;
            }
        }
    }
};
HULK_RM_REGISTER_PASS(ContactPass);

} // namespace
