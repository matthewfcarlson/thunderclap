// The runner's render passes (rm_pass.h; wr2, D236): the registry, the dispatch around the sink, and the picture
// options that are passes today (fog, texture quality, MSAA).
#include "rm_pass.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#include <algorithm>
#include <vector>

#include <bgfx/bgfx.h>

#include "pddi/bgfx_bridge.h"
#include "texpack.h"

using namespace hulk::pddi;

// the sink's extras for the app (bgfx_sink.cpp under HULK_SINK_OVERLAY)
extern "C" uint32_t hulk_gfx_sink_quality(uint32_t aniso, uint32_t msaa);
extern "C" void hulk_gfx_sink_scene_handles(uint32_t* fb, uint32_t* colour, uint32_t* depth, uint32_t* samples);

namespace rm {

namespace {
std::vector<Pass*>& passes()
{
    static std::vector<Pass*> v;
    return v;
}
bool s_sorted;
Settings s_settings;
bool s_sceneSeen;              // the frame's first scene-target pass was seen

std::vector<Pass*>& ordered()
{
    if (!s_sorted) {
        std::stable_sort(passes().begin(), passes().end(), [](Pass* a, Pass* b) { return a->order() < b->order(); });
        s_sorted = true;
    }
    return passes();
}
} // namespace

Registrar::Registrar(Pass* p)
{
    passes().push_back(p);
    s_sorted = false;
}

const Settings& settings() { return s_settings; }

void setQuality(uint32_t what, int32_t value)
{
    if (what == 0 || what >= kQualityCount || s_settings.value[what] == value)
        return;
    s_settings.value[what] = value;
    for (Pass* p : ordered())
        p->settingsChanged(s_settings);
}

void packet(DrawPacket& p)
{
    for (Pass* q : ordered())
        q->packet(p);
}

static unsigned s_stencilDraws, s_allDraws;      // (HULK_RM_LOG: the game's stencil draws a frame)
void submitDraw(const DrawPacket& p)
{
    s_stencilDraws += p.state.stencil != 0, s_allDraws++;
    for (Pass* q : ordered())
        q->draw(p);
    hulk_gfx_sink_submit_draw(&p);
}

void vertices(uint32_t sinkBuffer, const SinkVertexData& d)
{
    for (Pass* q : ordered())
        q->vertices(sinkBuffer, d);
}

void buffersDropped(uint32_t sinkBuffer)
{
    for (Pass* q : ordered())
        q->buffersDropped(sinkBuffer);
}

void setPass(const SinkPass& pass)
{
    if (pass.target == kSinkTargetScene && !s_sceneSeen) {
        s_sceneSeen = true;
        SinkPass p = pass;
        for (Pass* q : ordered())
            q->sceneBegin(p);
        hulk_gfx_sink_set_pass(&p);
        return;
    }
    hulk_gfx_sink_set_pass(&pass);
}

void present(const SinkPresent& p)
{
    Scene s = {};
    uint32_t samples = 1;
    hulk_gfx_sink_scene_handles(&s.frameBuffer, &s.colour, &s.depth, &samples);
    s.samples = samples;
    s.width = hulk_gfx_sink_target_width();
    s.height = hulk_gfx_sink_target_height();
    uint16_t view = kFirstView;
    if (s.frameBuffer != kSinkNone)
        for (Pass* q : ordered())
            q->postScene(s, view);
    hulk_gfx_sink_present(&p);
    s_sceneSeen = false;
}

// HULK_RM_LOG=1: every 300 presented frames, bgfx's GPU and submit (CPU) times a frame and the draw count
static void costLog()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_RM_LOG") && atoi(getenv("HULK_RM_LOG")) > 0;
    if (!on)
        return;
    static double gpu, cpu, draws, stencil, game;
    static unsigned n, gn;
    const bgfx::Stats* st = bgfx::getStats();
    if (!st)
        return;
    if (st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin)
        gpu += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq, gn++;
    if (st->cpuTimerFreq > 0)
        cpu += 1e3 * (double)(st->cpuTimeEnd - st->cpuTimeBegin) / (double)st->cpuTimerFreq;
    draws += st->numDraw;
    stencil += s_stencilDraws, game += s_allDraws;
    s_stencilDraws = s_allDraws = 0;
    if (++n == 300) {
        fprintf(stderr, "hulk-app: rm: %u frames: GPU %.3f ms, render thread %.3f ms, %.0f draws a frame (%ux%u); "
                "game draws %.0f, stencil %.1f\n", n, gn ? gpu / gn : 0.0, cpu / n, draws / n, (unsigned)st->width,
                (unsigned)st->height, game / n, stencil / n);
        gpu = cpu = draws = stencil = game = 0, n = gn = 0;
    }
}

void frame()
{
    costLog();
    for (Pass* q : ordered())
        q->frame();
}

uint32_t sceneSamples()
{
    uint32_t fb, c, d, n = 1;
    hulk_gfx_sink_scene_handles(&fb, &c, &d, &n);
    return n ? n : 1;
}

// ------------------------------------------------------------------------------------------- the passes of today
namespace {

// Fog (wvid1's override, now a pass): 0 the game's, 1 reduced (the planes x2.5), 2 off. Set by gfx_fog.
int s_fog;
class FogPass final : public Pass {
  public:
    const char* name() const override { return "fog"; }
    void packet(DrawPacket& p) override
    {
        if (s_fog == 2) {
            p.fog = 0;
            p.frag[1][3] = 0.0f;
        } else if (s_fog == 1 && p.fog) {
            p.frag[2][0] *= 2.5f;
            p.frag[2][1] *= 2.5f;
        }
    }
};
HULK_RM_REGISTER_PASS(FogPass);

// Texture quality: generated mip chains (texpack.cpp: textures uploaded from then on) and anisotropic filtering (the
// sink's samplers); MSAA on the scene target (the sink makes it again between frames: app.cpp's render-size path).
class QualityPass final : public Pass {
  public:
    const char* name() const override { return "quality"; }
    void settingsChanged(const Settings& s) override
    {
        texpack_mipmaps(s[kMipmaps]);
        int msaa = s[kMsaa];
        if (hulk_gfx_sink_quality(s[kAniso] ? 1 : 0, (uint32_t)(msaa > 1 ? msaa : 1)))
            appTargetsChanged();
        if (s[kAniso] != m_aniso || msaa != m_msaa)
            fprintf(stderr, "hulk-app: anisotropic filtering %s, MSAA %dx\n", s[kAniso] ? "16x" : "off",
                    msaa > 1 ? msaa : 1);
        m_aniso = s[kAniso], m_msaa = msaa;
    }

  private:
    int m_aniso = -1, m_msaa = -1;
};
HULK_RM_REGISTER_PASS(QualityPass);

} // namespace
} // namespace rm

// app.cpp's gfx_fog import lands here (the fog pass's setting)
extern "C" void rm_set_fog(int value) { rm::s_fog = value; }
