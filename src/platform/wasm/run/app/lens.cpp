// Lens effects (wlens1, D249; docs/hdr-shadows.md "Lens effects"; Video Options > Cutscene Depth of Field, Lens Flare,
// Vignette, Chromatic Aberration, Film Grain). Drawn over the scene in views of the runner's own before the game's
// first framebuffer effect (its bloom and colour pass), after HDR's tone map and the colour grade at the same point
// (rm::viewsBefore), so the game's bloom, overlay, fader and the HUD (the frame's tail, after its effects) all come
// after them: the HUD, menus and subtitles are never touched. A frame without effects (the front end) gets none.
//
//   Cutscene Depth of Field  only while the game's letterbox is up (an in-engine cutscene: gfx/lens.c reads it, as
//                            wskip1's "in play" test does) and never while a movie plays; it eases in and out over
//                            ~0.4 s of updates. The focus is the main actor when he is in the shot and not hidden
//                            (gfx/lens.c hands his position over), else the nearest subject in the frame's upper middle
//                            (25 depth taps, the nearest cluster), eased in log depth across frames in a 1x1 target.
//                            The blur follows a thin lens (|1/z - 1/f| x an aperture): close-ups blur their
//                            backgrounds, wide and aerial shots stay sharp (no miniature look). The letterbox bars
//                            (black rows) are left alone. A half-size
//                            gather (36 taps on a golden-angle disc, each tap's own circle of confusion deciding
//                            whether it reaches the pixel, brighter taps weighted up: round bokeh), then a full-size
//                            blend by the pixel's own circle (and the foreground's that spills over it).
//   Lens Flare               the sun: where the key light's direction (the strongest directional light of the lit draws,
//                            as the shadows and the atmosphere's sun glow take it) is on screen by day and the sky is
//                            clear there (depth taps at the sky), a soft glow, a faint horizontal streak and a few
//                            tinted ghosts along the line through the centre; strong small lights (a bright-pass that
//                            keeps only spots brighter than their surround: lamps, signs, orbs, flashes, not a bright
//                            sky) give mirrored ghosts and a halo. Quarter size, blurred, added.
//   Vignette                 a soft darkening towards the corners.
//   Chromatic Aberration     red and blue fringes towards the screen's edges, only while the camera shakes hard (big
//                            impacts: gfx/lens.c reads the game camera's shakes).
//   Film Grain               a fine grain weighted to the mid-tones, new each presented frame.
// Vignette and grain alone are one multiply quad; anything else reads a copy of the scene and writes it back once.
// Output only: nothing here reads or writes the module's memory (the module hands the cutscene and shake word over).
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bgfx/bgfx.h>

#include "nightlights.h"
#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"
#include "rm_post.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);
extern "C" uint32_t hulk_gfx_sink_scene_hdr();
extern "C" int hulk_app_movie_playing(void);

namespace {

uint32_t s_state;               // gfx/lens.c's word (bit 0 letterbox, 8..15 / 16..23 the camera's shake)
float s_subject[3];             // gfx/lens.c's main actor's position while the letterbox is up (zeros: none)

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_LENS_LOG") ? atoi(getenv("HULK_LENS_LOG")) : 0;
    return on;
}

class LensPass final : public rm::Pass {
  public:
    const char* name() const override { return "lens"; }
    int order() const override { return 32; }            // (after HDR's tone map, 30, and the grade, 31)
    void settingsChanged(const rm::Settings& s) override
    {
        int on[5] = {s[rm::kDof], s[rm::kLensFlare], s[rm::kVignette], s[rm::kAberration], s[rm::kGrain]};
        if (memcmp(on, m_on, sizeof on))
            fprintf(stderr, "hulk-app: lens: depth of field %s, flare %s, vignette %s, aberration %s, grain %s\n",
                    on[0] ? "on" : "off", on[1] ? "on" : "off", on[2] ? "on" : "off", on[3] ? "on" : "off",
                    on[4] ? "on" : "off");
        memcpy(m_on, on, sizeof on);
        // development tuning: HULK_LENS_DOF=band,aperture,max radius (half-size px at 480 lines); HULK_LENS_FLARE=
        // sun,ghosts,halo,threshold; HULK_LENS_FX=vignette,aberration,grain; HULK_LENS_SHAKE=units,degrees (full
        // aberration); HULK_LENS_FORCE=1 the depth of field always (cutscene or not), 2 the aberration at full
        // strength, 3 both
        if (const char* e = getenv("HULK_LENS_DOF"))
            sscanf(e, "%f,%f,%f", &m_band, &m_gain, &m_maxR);
        if (const char* e = getenv("HULK_LENS_FLARE"))
            sscanf(e, "%f,%f,%f,%f", &m_sunGain, &m_ghostGain, &m_haloGain, &m_threshold);
        if (const char* e = getenv("HULK_LENS_FX"))
            sscanf(e, "%f,%f,%f", &m_vigK, &m_caK, &m_grainK);
        if (const char* e = getenv("HULK_LENS_SHAKE"))
            sscanf(e, "%f,%f", &m_shakeUnits, &m_shakeDeg);
        if (const char* e = getenv("HULK_LENS_FORCE"))
            m_force = atoi(e);
    }
    bool any() const { return m_on[0] || m_on[1] || m_on[2] || m_on[3] || m_on[4]; }
    bool midFrame() const override { return any() && !m_abOff; }
    // the cutscene ease and the shake, once an update (the draws of an update come here once at every display rate)
    void packet(DrawPacket& p) override
    {
        if (p.frame == m_lastUpdate)
            return;
        m_lastUpdate = p.frame;
        bool cut = ((s_state & 1) != 0 || (m_force & 1)) && !hulk_app_movie_playing();
        m_ramp = cut ? fminf(m_ramp + 1.0f / 12.0f, 1.0f) : fmaxf(m_ramp - 1.0f / 12.0f, 0.0f);
        float tr = (float)(s_state >> 8 & 255) * 0.02f, rot = (float)(s_state >> 16 & 255) * 0.04f;
        float level = fmaxf(tr / m_shakeUnits, rot / m_shakeDeg);
        // (play3's shakes are 0.1 .. 0.6 units of translation, none of rotation, a quarter second each: the
        // footsteps' and hits' 0.1 .. 0.3 take none, the heavy landings, throws and explosions' 0.4 .. 0.6 the most)
        level = fminf(fmaxf((level - 0.4f) / 0.6f, 0.0f), 1.0f);
        if (m_force & 2)
            level = 1.0f;
        m_impact = fmaxf(level, m_impact * 0.82f);
        if (m_impact < 0.01f)
            m_impact = 0.0f;
        if (logOn() >= 2 && (s_state & 0xffff00))
            fprintf(stderr, "hulk-app: lens: update %u shake %.2f units %.2f deg -> impact %.2f\n", p.frame, tr, rot,
                    m_impact);
    }
    void late(DrawPacket& p) override
    {
        if (m_on[1])
            keyLight(p);
    }
    void draw(const DrawPacket& p) override
    {
        if (p.viewMode == 0 && rm::passIsScene(p.pass) && !p.state.blend && p.state.depthWrite)
            m_scene = true;
    }
    void copy(uint16_t pass, const SinkTarget& dst) override
    {
        if (!active())
            return;
        SinkTarget refr = {kSinkNone, kSinkNone};
        hulk_gfx_sink_frame_copy(&refr);               // (the refraction copy of the frame: mid-scene, not the effects)
        if (dst.texture != refr.texture)
            run(pass);
    }
    void fx(const FxPacket& p) override
    {
        if (active())
            run(p.pass);
    }
    void frame() override
    {
        abCost();
        if (logOn() && ++m_frames % 300 == 0)
            fprintf(stderr, "hulk-app: lens: %u of 300 frames (%u with depth of field, %u flare, %u sun, %u aberration); "
                    "%u on the main actor; cutscene %.2f, impact %.2f\n", m_runs, m_dofRuns, m_flareRuns, m_sunRuns,
                    m_caRuns, m_subjectRuns, m_ramp, m_impact),
                m_runs = m_dofRuns = m_flareRuns = m_sunRuns = m_caRuns = m_subjectRuns = 0;
        m_done = m_scene = false;
        m_seed = (m_seed + 1) % 977;
    }
    void state(uint32_t v)
    {
        if (logOn() && (v & 1) != (s_state & 1))
            fprintf(stderr, "hulk-app: lens: letterbox %s\n", v & 1 ? "up" : "down");
        s_state = v;
    }

  private:
    bool active() const { return midFrame() && !m_done && m_scene; }

    // the key light, towards the light in world space (atmosphere.cpp's keyLight: the strongest directional light)
    void keyLight(const DrawPacket& p)
    {
        if (!p.lighting || !p.lights)
            return;
        float view[3][4], inv[3][3], proj[16];
        if (!rm::frameCamera(view, inv, proj))
            return;
        float best = 0;
        const SinkLight* k = nullptr;
        for (int i = 0; i < 8; i++) {
            const SinkLight& l = p.lights[i];
            float s = l.diffuse[0] + l.diffuse[1] + l.diffuse[2];
            if (l.on && l.type == 3 && s > best)
                best = s, k = &l;
        }
        if (!k)
            return;
        float t[3] = {-k->direction[0], -k->direction[1], -k->direction[2]}, w[3];
        for (int i = 0; i < 3; i++)
            w[i] = inv[i][0] * t[0] + inv[i][1] * t[1] + inv[i][2] * t[2];
        float l = sqrtf(w[0] * w[0] + w[1] * w[1] + w[2] * w[2]);
        if (l < 1e-6f)
            return;
        for (int i = 0; i < 3; i++)
            m_key[i] = m_keyKnown ? m_key[i] + 0.05f * (w[i] / l - m_key[i]) : w[i] / l;
        m_keyKnown = true;
    }

    // the sun's place on screen (uv, top-left origin) and its strength before occlusion; false: none this frame
    bool sunOnScreen(const float view[3][4], const float proj[16], float uv[2], float* amount)
    {
        if (!m_keyKnown || m_key[1] < -0.02f)
            return false;
        float night = rm::nightAmount();
        if (night > 0.6f)
            return false;
        float c[3];
        for (int i = 0; i < 3; i++)
            c[i] = view[i][0] * m_key[0] + view[i][1] * m_key[1] + view[i][2] * m_key[2];
        float x = proj[0] * c[0] + proj[1] * c[1] + proj[2] * c[2];
        float y = proj[4] * c[0] + proj[5] * c[1] + proj[6] * c[2];
        float w = proj[12] * c[0] + proj[13] * c[1] + proj[14] * c[2];
        if (w <= 1e-4f)
            return false;
        uv[0] = 0.5f + 0.5f * x / w, uv[1] = 0.5f - 0.5f * y / w;
        // (fades out as it leaves the screen, and out over the dusk)
        float edge = fminf(fminf(uv[0] + 0.15f, 1.15f - uv[0]), fminf(uv[1] + 0.15f, 1.15f - uv[1])) / 0.15f;
        *amount = fminf(fmaxf(edge, 0.0f), 1.0f) * (1.0f - fminf(fmaxf((night - 0.2f) / 0.4f, 0.0f), 1.0f));
        return *amount > 0.01f;
    }

    // the cutscene's subject (the main actor, his chest 1.4 units over his node) on screen: uv, view depth, 1
    void subject(const float view[3][4], const float proj[16], float out[4])
    {
        if (!(s_state & 1) || (s_subject[0] == 0.0f && s_subject[1] == 0.0f && s_subject[2] == 0.0f))
            return;
        float p[3] = {s_subject[0], s_subject[1] + 1.4f, s_subject[2]}, c[3];
        for (int i = 0; i < 3; i++)
            c[i] = view[i][0] * p[0] + view[i][1] * p[1] + view[i][2] * p[2] + view[i][3];
        float x = proj[0] * c[0] + proj[1] * c[1] + proj[2] * c[2] + proj[3];
        float y = proj[4] * c[0] + proj[5] * c[1] + proj[6] * c[2] + proj[7];
        float w = proj[12] * c[0] + proj[13] * c[1] + proj[14] * c[2] + proj[15];
        if (w <= 0.05f)
            return;
        float u = 0.5f + 0.5f * x / w, v = 0.5f - 0.5f * y / w;
        if (u < 0.06f || u > 0.94f || v < 0.1f || v > 0.95f)
            return;
        out[0] = u, out[1] = v, out[2] = fabsf(c[2]), out[3] = 1.0f;
        m_subjectRuns++;
    }

    void run(uint16_t pass)
    {
        m_done = true;
        uint32_t fb = kSinkNone, colour = kSinkNone, depth = kSinkNone, samples = 1;
        hulk_gfx_sink_scene_handles(&fb, &colour, &depth, &samples);
        uint32_t w = hulk_gfx_sink_target_width(), h = hulk_gfx_sink_target_height();
        if (fb == kSinkNone || !w || !h)
            return;
        float view[3][4], inv[3][3], proj[16];
        bool cam = rm::frameCamera(view, inv, proj) && depth != kSinkNone;
        bool hdrFmt = rm::hdrSupported();
        bool dof = m_on[0] && m_ramp > 0.0f && cam && hdrFmt;
        bool flare = m_on[1] && hdrFmt;
        bool ca = m_on[3] && m_impact > 0.0f;
        float vig = m_on[2] ? m_vigK : 0.0f, grain = m_on[4] ? m_grainK : 0.0f;
        bool copyPath = dof || flare || ca;
        if (!copyPath && vig <= 0.0f && grain <= 0.0f)
            return;
        if (!dof)
            m_focusValid = false;
        const uint64_t write = BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A;
        const uint32_t lin = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
        const uint32_t point = lin | BGFX_SAMPLER_POINT;
        float aspect = (float)w / (float)h;
        // a frame buffer of the scene's colour alone (the depth is sampled while the composite writes)
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
        float lens[4][4] = {{0, 0, vig, grain}, {0, 0, 0, 0}, {0, (float)m_seed, aspect, 0},
                            {m_band, m_gain, (float)w, (float)h}};
        if (cam) {
            lens[1][0] = proj[10], lens[1][1] = proj[11], lens[1][2] = proj[14], lens[1][3] = proj[15];
        }
        if (!copyPath) {
            uint16_t mul = rm::program("vs_rm_quad", "fs_rm_lensmul");
            uint16_t v[1];
            if (mul == rm::kNoHandle || !rm::viewsBefore(pass, 1, v))
                return;
            rm::viewInto(v[0], m_fb, w, h);
            rm::uniform("u_rmLens", &lens[0][0], 4);
            rm::quad(v[0], mul, BGFX_STATE_WRITE_RGB | BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_DST_COLOR,
                                                                               BGFX_STATE_BLEND_SRC_COLOR));
            m_runs++;
            return;
        }
        uint16_t comp = rm::program("vs_rm_quad", "fs_rm_lens");
        uint32_t fmt = hulk_gfx_sink_scene_hdr() ? bgfx::TextureFormat::RGBA16F : bgfx::TextureFormat::BGRA8;
        if (comp == rm::kNoHandle || !m_copy.ensure(w, h, fmt, true))
            return;
        uint16_t focusP = rm::program("vs_rm_quad", "fs_rm_dfocus"), prepP = rm::program("vs_rm_quad", "fs_rm_dprep"),
                 gatherP = rm::program("vs_rm_quad", "fs_rm_dgather");
        uint32_t hw = (w + 1) / 2, hh = (h + 1) / 2;
        if (dof && (focusP == rm::kNoHandle || prepP == rm::kNoHandle || gatherP == rm::kNoHandle ||
                    !m_focus[0].ensure(1, 1, bgfx::TextureFormat::RGBA16F, false, false) ||
                    !m_focus[1].ensure(1, 1, bgfx::TextureFormat::RGBA16F, false, false) ||
                    !m_prep.ensure(hw, hh, bgfx::TextureFormat::RGBA16F) ||
                    !m_blur.ensure(hw, hh, bgfx::TextureFormat::RGBA16F)))
            dof = false;
        uint16_t brightP = rm::program("vs_rm_quad", "fs_rm_fbright"), ghostP = rm::program("vs_rm_quad", "fs_rm_fghost"),
                 blurP = rm::program("vs_rm_quad", "fs_rm_blur");
        uint32_t qw = (w + 3) / 4, qh = (h + 3) / 4;
        if (flare && (brightP == rm::kNoHandle || ghostP == rm::kNoHandle || blurP == rm::kNoHandle ||
                      !m_fa.ensure(qw, qh, bgfx::TextureFormat::RGBA16F) ||
                      !m_fb2.ensure(qw, qh, bgfx::TextureFormat::RGBA16F)))
            flare = false;
        if (!dof && !flare && !ca && vig <= 0.0f && grain <= 0.0f)
            return;
        int n = (dof ? 3 : 0) + (flare ? 4 : 0) + 1;
        uint16_t v[8];
        if (!rm::viewsBefore(pass, n, v))
            return;
        // the scene as it is now, into the copy (a view's blits run before its draws: the first view's)
        bgfx::TextureRegion dst, src;
        dst.init(bgfx::TextureHandle{m_copy.tex});
        src.init(bgfx::TextureHandle{(uint16_t)colour});
        bgfx::blit(v[0], dst, src);
        int k = 0;
        uint16_t focusTex = m_copy.tex;
        if (dof) {
            // the focus: last frame's eased towards this frame's subject (1x1); a new cutscene takes it at once
            int cur = m_fi ^ 1;
            float sub[4] = {0, 0, 0, 0};
            subject(view, proj, sub);
            float dofU[3][4] = {{proj[10], proj[11], proj[14], proj[15]},
                                {m_focusValid ? 0.18f : 1.0f, m_band, m_gain, m_focusValid ? 0.0f : 1.0f},
                                {sub[0], sub[1], sub[2], sub[3]}};
            rm::viewInto(v[k], m_focus[cur].fb, 1, 1);
            rm::texture(0, (uint16_t)depth, point);
            rm::texture(1, m_focus[m_fi].tex, point);
            rm::uniform("u_rmDof", &dofU[0][0], 3);
            rm::quad(v[k++], focusP, write);
            m_fi = cur, m_focusValid = true;
            focusTex = m_focus[cur].tex;
            // half size: colour and the signed circle of confusion (the nearest of the four depths)
            float g[4] = {1.0f / w, 1.0f / h, 0, 0};
            rm::viewInto(v[k], m_prep.fb, hw, hh);
            rm::texture(0, m_copy.tex, lin);
            rm::texture(1, focusTex, point);
            rm::texture(2, (uint16_t)depth, point);
            rm::uniform("u_rmDof", &dofU[0][0], 3);
            rm::uniform("u_rmDofG", g);
            rm::quad(v[k++], prepP, write);
            // the gather
            float r = m_maxR * (float)hh / 240.0f * m_ramp;
            float g2[4] = {1.0f / hw, 1.0f / hh, r, m_ramp};
            rm::viewInto(v[k], m_blur.fb, hw, hh);
            rm::texture(0, m_prep.tex, point);
            rm::uniform("u_rmDofG", g2);
            rm::quad(v[k++], gatherP, write);
            lens[0][0] = m_ramp;
            m_dofRuns++;
        }
        if (flare) {
            float sunUv[2] = {0, 0}, sunAmt = 0;
            bool sun = cam && sunOnScreen(view, proj, sunUv, &sunAmt);
            float fu[4][4] = {{1.0f / w, 1.0f / h, m_threshold, 6.0f / qw},
                              {m_ghostGain, m_haloGain, aspect, sun ? sunAmt * m_sunGain : 0.0f},
                              {sunUv[0], sunUv[1], 0, 0},
                              {proj[10], proj[11], proj[14], proj[15]}};
            rm::viewInto(v[k], m_fa.fb, qw, qh);
            rm::texture(0, m_copy.tex, lin);
            rm::uniform("u_rmFlare", &fu[0][0], 4);
            rm::quad(v[k++], brightP, write);
            rm::viewInto(v[k], m_fb2.fb, qw, qh);
            rm::texture(0, m_fa.tex, lin);
            rm::texture(1, cam ? (uint16_t)depth : m_copy.tex, point);
            rm::texture(2, m_copy.tex, lin);
            rm::uniform("u_rmFlare", &fu[0][0], 4);
            rm::quad(v[k++], ghostP, write);
            float px[4] = {1.0f / qw, 0, 0, 0}, py[4] = {0, 1.0f / qh, 0, 0};
            rm::viewInto(v[k], m_fa.fb, qw, qh);
            rm::texture(0, m_fb2.tex, lin);
            rm::uniform("u_rmPost0", px);
            rm::quad(v[k++], blurP, write);
            rm::viewInto(v[k], m_fb2.fb, qw, qh);
            rm::texture(0, m_fa.tex, lin);
            rm::uniform("u_rmPost0", py);
            rm::quad(v[k++], blurP, write);
            lens[2][0] = 1.0f;
            m_flareRuns++;
            m_sunRuns += sun;
        }
        if (ca) {
            lens[0][1] = m_impact * m_caK;
            m_caRuns++;
        }
        // the composite, into the scene (every sampler bound: the unused ones to the copy, wlinux2)
        rm::viewInto(v[k], m_fb, w, h);
        rm::texture(0, m_copy.tex, lin);
        rm::texture(1, dof ? m_blur.tex : m_copy.tex, lin);
        rm::texture(2, dof ? (uint16_t)depth : m_copy.tex, point);
        rm::texture(3, focusTex, point);
        rm::texture(4, flare ? m_fb2.tex : m_copy.tex, lin);
        rm::uniform("u_rmLens", &lens[0][0], 4);
        rm::quad(v[k], comp, write);
        m_runs++;
    }

    // HULK_LENS_AB=N: the lens views off and on in turns of N presented frames (GPU and render thread a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_LENS_AB") ? atoi(getenv("HULK_LENS_AB")) : 0;
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
                fprintf(stderr, "hulk-app: lens cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames, %ux%u)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1],
                        m_abCpu[0] / m_abN[0], m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1],
                        st ? (unsigned)st->width : 0, st ? (unsigned)st->height : 0);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_on[5] = {0, 0, 0, 0, 0};
    int m_force = 0;
    bool m_done = false, m_scene = false, m_keyKnown = false, m_focusValid = false;
    uint32_t m_lastUpdate = ~0u;
    float m_ramp = 0, m_impact = 0, m_key[3] = {0, 1, 0};
    // tuning: the focus band and the aperture (lensCoc), the largest radius (half-size px at 480 lines)
    float m_band = 0.1f, m_gain = 8.0f, m_maxR = 4.0f;
    float m_sunGain = 1.0f, m_ghostGain = 1.0f, m_haloGain = 1.0f, m_threshold = 0.82f;
    float m_vigK = 1.0f, m_caK = 1.0f, m_grainK = 1.0f;
    float m_shakeUnits = 0.6f, m_shakeDeg = 2.0f;
    rm::Target m_copy, m_focus[2], m_prep, m_blur, m_fa, m_fb2;
    int m_fi = 0;
    uint16_t m_fb = rm::kNoHandle;
    uint32_t m_colourOf = kSinkNone;
    unsigned m_subjectRuns = 0, m_seed = 0, m_frames = 0, m_runs = 0, m_dofRuns = 0, m_flareRuns = 0, m_sunRuns = 0, m_caRuns = 0;
};
HULK_RM_REGISTER_PASS(LensPass);

} // namespace

// gfx/lens.c's word at each module present (app.cpp's gfx_quality what 0x101)
extern "C" void hulk_app_lens_state(uint32_t state) { s_rmPass_LensPass.state(state); }
// gfx/lens.c's subject position (what 0x102 + axis: float bits)
extern "C" void hulk_app_lens_subject(uint32_t axis, uint32_t bits)
{
    if (axis < 3)
        memcpy(&s_subject[axis], &bits, 4);
}
