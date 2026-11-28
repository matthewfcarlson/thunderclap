// Colour grade (wlook1, docs/look.md "Colour grade"; Video Options > Colour Grade: Original / Natural / Cinematic). A
// parametric grade of the scene before the game's own effects (its colour pass, bloom, fader) and the HUD: contrast,
// saturation with vibrance, split toning (cool shadows, warm highlights, more so at night under the street lights),
// a toe and a soft vignette (Cinematic). The time of day comes from the rooms' fog (as the reflections' night test:
// downtown night ~0.09, the desert ~0.5), so the city at night and the desert by day take their own grade.
//
// Where: inside HDR's tone-map pass (hdr.cpp reads rm::gradeConstants), the one full-screen step the scene already
// takes before the game's effects: the grade adds no pass and no copy (lead, frame budget: 16 ms at 60 fps). With HDR
// off nothing is graded. A frame with no effects (the front end, menus) is not tone mapped, so not graded. Output only:
// nothing here reads or writes the module's memory; Original (the faithful value) draws nothing.
#include "grade.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"

using namespace hulk::pddi;

namespace {

// a preset by day and by night: contrast, saturation, vibrance, pivot; shadows' tint; highlights' tint; vignette,
// exposure, tint strength, split; black lift
struct Look {
    float contrast, saturation, vibrance, pivot;
    float shadow[3], highlight[3];
    float vignette, exposure, tints, split, lift;
};
// Natural: a little more contrast and colour than the original, barely toned
const Look kNaturalDay = {1.06f, 1.05f, 0.10f, 0.45f, {0.98f, 1.00f, 1.03f}, {1.02f, 1.00f, 0.97f},
                          0.00f, 1.00f, 1.0f, 0.40f, 0.00f};
const Look kNaturalNight = {1.08f, 1.06f, 0.12f, 0.40f, {0.96f, 1.00f, 1.06f}, {1.04f, 1.00f, 0.95f},
                            0.00f, 1.03f, 1.0f, 0.40f, 0.00f};
// Cinematic: the grounded modern city: firm contrast with a toe, teal-blue shadows and warm highlights (sodium light
// at night), richer colour where it is weak, a soft vignette
const Look kCinematicDay = {1.18f, 1.07f, 0.30f, 0.45f, {0.92f, 1.00f, 1.10f}, {1.07f, 1.01f, 0.90f},
                            0.16f, 1.02f, 1.0f, 0.42f, -0.012f};
// (wsweep1: vibrance 0.28 -> 0.15 and the highlights' sodium amber 1.09/1.00/0.86 -> 1.03/1.00/0.95: with the night
// lights on the greenish streets the amber and the vibrance made a yellow-green wash, play3 f41000 / f42000)
const Look kCinematicNight = {1.18f, 1.10f, 0.15f, 0.38f, {0.88f, 0.99f, 1.14f}, {1.03f, 1.00f, 0.95f},
                              0.22f, 1.08f, 1.0f, 0.38f, -0.010f};

float lum(const float* c) { return 0.2126f * c[0] + 0.7152f * c[1] + 0.0722f * c[2]; }

int logOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_GRADE_LOG") && atoi(getenv("HULK_GRADE_LOG")) > 0;
    return on;
}

class GradePass;
GradePass* s_grade;

class GradePass final : public rm::Pass {
  public:
    GradePass() { s_grade = this; }
    const char* name() const override { return "grade"; }
    int order() const override { return 31; }
    void settingsChanged(const rm::Settings& s) override
    {
        int level = s[rm::kGrade];
        if (level != m_level)
            fprintf(stderr, "hulk-app: grade %s\n", level == 0 ? "original" : level == 1 ? "natural" : "cinematic");
        m_level = level;
        // HULK_GRADE=contrast,saturation,vibrance,vignette,tints,night (development: scale the preset; night < 0: from fog)
        if (const char* e = getenv("HULK_GRADE"))
            sscanf(e, "%f,%f,%f,%f,%f,%f", &m_tune[0], &m_tune[1], &m_tune[2], &m_tune[3], &m_tune[4], &m_tune[5]);
        // HULK_GRADE_NIGHT=contrast,saturation,vibrance,shadowR,G,B,highlightR,G,B,exposure (development: Cinematic's
        // night look)
        if (const char* e = getenv("HULK_GRADE_NIGHT")) {
            Look& n = m_cinNight;
            sscanf(e, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &n.contrast, &n.saturation, &n.vibrance, &n.shadow[0],
                   &n.shadow[1], &n.shadow[2], &n.highlight[0], &n.highlight[1], &n.highlight[2], &n.exposure);
        }
    }
    void draw(const DrawPacket& p) override
    {
        if (!m_level)
            return;
        // the rooms' fog: unlit world shaders (simple, layered, layeredReflect), opaque, fogged
        if (p.fog && p.viewMode == 0 && !p.lighting && p.vertexProgram == 0 && p.shaderKind <= 2 && !p.state.blend)
            m_fogLum += 0.3f * p.frag[1][0] + 0.59f * p.frag[1][1] + 0.11f * p.frag[1][2], m_fogN++;
    }
    void frame() override
    {
        abCost();
        if (m_fogN) {
            float l = m_fogLum / m_fogN;
            m_night = 1.0f - fminf(fmaxf((l - 0.12f) / (0.35f - 0.12f), 0.0f), 1.0f);
            m_lastFog = l;
        }
        if (logOn() && ++m_frames % 300 == 0)
            fprintf(stderr, "hulk-app: grade: fog %.3f night %.2f, %u of 300 frames graded in the tone map\n",
                    m_lastFog, m_night, m_graded), m_graded = 0;
        m_fogLum = 0, m_fogN = 0;
    }

    // the u_rmGrade[4] constants (null: no grade); hdr.cpp asks while it tone maps
    const float* constants()
    {
        if (!m_level || m_abOff)
            return nullptr;
        const Look& d = m_level >= 2 ? kCinematicDay : kNaturalDay;
        const Look& n = m_level >= 2 ? m_cinNight : kNaturalNight;
        float t = m_tune[5] >= 0.0f ? m_tune[5] : m_night;
        auto mix = [t](float a, float b) { return a + (b - a) * t; };
        float sh[3], hi[3];
        for (int i = 0; i < 3; i++)
            sh[i] = mix(d.shadow[i], n.shadow[i]), hi[i] = mix(d.highlight[i], n.highlight[i]);
        float ls = lum(sh), lh = lum(hi);                              // (tints of luminance 1)
        m_c[0][0] = 1.0f + (mix(d.contrast, n.contrast) - 1.0f) * m_tune[0];
        m_c[0][1] = 1.0f + (mix(d.saturation, n.saturation) - 1.0f) * m_tune[1];
        m_c[0][2] = mix(d.vibrance, n.vibrance) * m_tune[2];
        m_c[0][3] = 1.0f;
        for (int i = 0; i < 3; i++)
            m_c[1][i] = sh[i] / ls, m_c[2][i] = hi[i] / lh;
        m_c[1][3] = mix(d.pivot, n.pivot);
        m_c[2][3] = mix(d.lift, n.lift);
        m_c[3][0] = mix(d.vignette, n.vignette) * m_tune[3];
        m_c[3][1] = mix(d.exposure, n.exposure);
        m_c[3][2] = mix(d.tints, n.tints) * m_tune[4];
        m_c[3][3] = mix(d.split, n.split);
        return &m_c[0][0];
    }
    void hdrGraded() { m_graded++; }

  private:
    // HULK_GRADE_AB=N: the grade off and on in turns of N presented frames (GPU and render thread a frame)
    void abCost()
    {
        static int n = -1;
        if (n < 0)
            n = getenv("HULK_GRADE_AB") ? atoi(getenv("HULK_GRADE_AB")) : 0;
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
                fprintf(stderr, "hulk-app: grade cost: GPU %.3f ms off, %.3f ms on; render thread %.3f / %.3f ms "
                        "(%u / %u frames)\n", m_abGpu[0] / m_abN[0], m_abGpu[1] / m_abN[1], m_abCpu[0] / m_abN[0],
                        m_abCpu[1] / m_abN[1], m_abN[0], m_abN[1]);
        }
    }
    bool m_abOff = false;
    unsigned m_abFrame = 0, m_abTurns = 0, m_abN[2] = {0, 0};
    double m_abGpu[2] = {0, 0}, m_abCpu[2] = {0, 0};

    int m_level = 0;
    float m_night = 0.0f, m_lastFog = 0.0f, m_fogLum = 0.0f;
    unsigned m_fogN = 0, m_frames = 0, m_graded = 0;
    float m_tune[6] = {1, 1, 1, 1, 1, -1};
    float m_c[4][4];
    Look m_cinNight = kCinematicNight;
};
HULK_RM_REGISTER_PASS(GradePass);

} // namespace

const float* rm::gradeConstants() { return s_grade ? s_grade->constants() : nullptr; }
void rm::gradeDoneInToneMap()
{
    if (s_grade)
        s_grade->hdrGraded();
}
