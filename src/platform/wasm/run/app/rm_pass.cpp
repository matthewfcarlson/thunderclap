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
#include "rm_post.h"
#include "texpack.h"
#include "gfxstats.h"

using namespace hulk::pddi;

// the sink's extras for the app (bgfx_sink.cpp under HULK_SINK_OVERLAY)
extern "C" uint32_t hulk_gfx_sink_quality(uint32_t aniso, uint32_t msaa);
extern "C" uint32_t hulk_gfx_sink_targets(uint32_t hdr, uint32_t depthRead);
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

// wperf1 (HULK_GFX_STATS, docs/performance.md): the time in the passes' hooks (the runner's own encoding), apart from
// the sink's
namespace {
struct HookTimer {
    uint64_t t0;
    HookTimer() : t0(gs_enabled() ? gs_now() : 0) {}
    ~HookTimer() { if (t0) gs_extra(kGxHooks, t0); }
};
} // namespace
#define RM_EACH(call)              \
    do {                           \
        HookTimer ht_;             \
        for (Pass* q_ : ordered()) \
            q_->call;              \
    } while (0)

static uint8_t s_forced[kQualityCount];
static bool s_forcing;
void setQuality(uint32_t what, int32_t value)
{
    if (what == 0 || what >= kQualityCount || s_settings.value[what] == value || (s_forced[what] && !s_forcing))
        return;
    s_settings.value[what] = value;
    RM_EACH(settingsChanged(s_settings));
}

void packet(DrawPacket& p)
{
    RM_EACH(packet(p));
}

// ---- mid-frame views (wr3a): the game's pass ids renumbered in submission order, the runner's views among them
namespace {
bool s_frameOpen;                 // a frame's first sink call was seen (closed by the present)
bool s_remap;                     // this frame renumbers (a pass asked for mid-frame views)
uint16_t s_next;                  // the next free view
uint16_t s_map[256];              // game pass id -> view, valid where s_mapFrame == s_frameNo
uint32_t s_mapFrame[256], s_frameNo = 1;
uint16_t s_curGame = 0xffff;      // the game's current pass and the sink pass it is now
SinkPass s_curSink;
enum : uint16_t { kLastView = 250 };

void beginFrame()
{
    if (s_frameOpen)
        return;
    s_frameOpen = true;
    s_frameNo++;
    s_next = 0;
    s_curGame = 0xffff;
    s_remap = false;
    for (Pass* q : ordered())
        s_remap = s_remap || q->midFrame();
}
uint16_t lookup(uint16_t g)
{
    if (!s_remap)
        return g;
    if (g < 256 && s_mapFrame[g] == s_frameNo)
        return s_map[g];
    uint16_t v = s_next <= kLastView ? s_next++ : kLastView;
    if (g < 256)
        s_map[g] = v, s_mapFrame[g] = s_frameNo;
    return v;
}
void markScene(const SinkPass& pass);
} // namespace

uint16_t newView()
{
    beginFrame();
    if (!s_remap || s_next > kLastView)
        return kNoView;
    return s_next++;
}

uint16_t splitPass()
{
    beginFrame();
    if (!s_remap || s_next > kLastView || s_curGame == 0xffff)
        return kNoView;
    uint16_t old = s_curSink.id;
    SinkPass p = s_curSink;
    p.id = s_next++;
    p.clearFlags = 0;
    s_map[s_curGame] = p.id, s_mapFrame[s_curGame] = s_frameNo;
    s_curSink = p;
    markScene(p);
    hulk_gfx_sink_set_pass(&p);
    return old;
}

uint16_t sinkView(uint16_t gamePass) { return s_remap ? lookup(gamePass) : gamePass; }

uint16_t currentGamePass() { return s_curGame; }

bool viewsHere(int n, uint16_t* out) { return s_curGame != 0xffff && viewsBefore(s_curGame, n, out); }

bool viewsBefore(uint16_t g, int n, uint16_t* out)
{
    beginFrame();
    bool mapped = g < 256 && s_mapFrame[g] == s_frameNo;
    if (!s_remap || n <= 0 || s_next + n + (mapped ? 1 : 0) > kLastView + 1 || (mapped && g != s_curGame))
        return false;
    for (int i = 0; i < n; i++)
        out[i] = s_next++;
    if (mapped)
        splitPass();                    // (the pass's draws so far stay in its old view, the rest after ours)
    return true;
}

static unsigned s_stencilDraws, s_allDraws;      // (HULK_RM_LOG: the game's stencil draws a frame)
// wlook2: the next transient draw's vertices (the sink's copy, written before the draw is handed over)
namespace {
const SinkVertex* s_tVerts;
uint32_t s_tCount;
} // namespace
void setTransient(const SinkVertex* v, uint32_t count)
{
    s_tVerts = v, s_tCount = count;
}
const SinkVertex* transientVertices(const DrawPacket& p, uint32_t* count)
{
    if (p.transient == kSinkNone || !s_tVerts || s_tCount < p.vertexCount) {
        *count = 0;
        return nullptr;
    }
    *count = s_tCount;
    return s_tVerts;
}

void submitDraw(const DrawPacket& p)
{
    beginFrame();
    s_stencilDraws += p.state.stencil != 0, s_allDraws++;
    DrawPacket q = p;
    q.pass = sinkView(p.pass);
    RM_EACH(late(q));
    RM_EACH(draw(q));
    q.pass = sinkView(p.pass);          // (a pass may have split the game's pass: rm::viewsHere)
    {
        uint64_t t0 = gs_enabled() ? gs_now() : 0;
        hulk_gfx_sink_submit_draw(&q);
        if (t0)
            gs_extra(kGxSubmit, t0);
    }
    if (p.transient != kSinkNone)
        s_tVerts = nullptr, s_tCount = 0;   // (one draw's)
}

void copyFrame(uint16_t pass, const SinkTarget& dst)
{
    beginFrame();
    RM_EACH(copy(pass, dst));
    SinkTarget t = dst;
    hulk_gfx_sink_copy_frame(sinkView(pass), &t);
}

void fxDraw(const FxPacket& p)
{
    beginFrame();
    RM_EACH(fx(p));
    FxPacket q = p;
    q.pass = sinkView(p.pass);
    hulk_gfx_sink_fx_draw(&q);
}

void vertices(uint32_t sinkBuffer, const SinkVertexData& d)
{
    RM_EACH(vertices(sinkBuffer, d));
}

void buffersDropped(uint32_t sinkBuffer)
{
    RM_EACH(buffersDropped(sinkBuffer));
}

static uint8_t s_passScene[65536 / 8];
bool passIsScene(uint16_t pass) { return s_passScene[pass >> 3] >> (pass & 7) & 1; }
namespace {
void markScene(const SinkPass& pass)
{
    if (pass.target == kSinkTargetScene)
        s_passScene[pass.id >> 3] |= (uint8_t)(1 << (pass.id & 7));
    else
        s_passScene[pass.id >> 3] &= (uint8_t)~(1 << (pass.id & 7));
}
} // namespace

void setPass(const SinkPass& pass)
{
    beginFrame();
    SinkPass p = pass;
    if (pass.target == kSinkTargetScene && !s_sceneSeen) {
        s_sceneSeen = true;
        RM_EACH(sceneBegin(p));         // (a pass may take views before the scene's: rm::newView)
    }
    s_curGame = pass.id;
    p.id = sinkView(pass.id);
    s_curSink = p;
    markScene(p);
    RM_EACH(passSet(pass.id, p));
    hulk_gfx_sink_set_pass(&p);
}

static const SinkPresent* s_present;
const SinkPresent* currentPresent() { return s_present; }

void present(const SinkPresent& p)
{
    s_present = &p;
    Scene s = {};
    uint32_t samples = 1;
    hulk_gfx_sink_scene_handles(&s.frameBuffer, &s.colour, &s.depth, &samples);
    s.samples = samples;
    s.width = hulk_gfx_sink_target_width();
    s.height = hulk_gfx_sink_target_height();
    uint16_t view = kFirstView;
    if (s.frameBuffer != kSinkNone) {
        HookTimer ht;
        for (Pass* q : ordered())
            q->postScene(s, view);
    }
    s_present = nullptr;
    hulk_gfx_sink_present(&p);
    s_sceneSeen = false;
    s_frameOpen = false;
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

// HULK_RM_FORCE="what=value,...": pins Quality rows (rm_pass.h numbers) over the menu's (development; wr3a)
static void forceLog()
{
    static bool done;
    if (done)
        return;
    done = true;
    const char* e = getenv("HULK_RM_FORCE");
    while (e && *e) {
        unsigned w = 0;
        int v = 0, n = 0;
        if (sscanf(e, "%u=%d%n", &w, &v, &n) != 2)
            break;
        fprintf(stderr, "hulk-app: rm: quality %u pinned to %d (HULK_RM_FORCE)\n", w, v);
        s_forced[w < kQualityCount ? w : 0] = 1;
        s_settings.value[w < kQualityCount ? w : 0] = v - 1;   // (differs: setQuality applies it)
        s_forcing = true;
        setQuality(w, v);
        s_forcing = false;
        e += n;
        if (*e == ',')
            e++;
    }
}

void frame()
{
    forceLog();
    costLog();
    RM_EACH(frame());
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
        bool remake = hulk_gfx_sink_quality(s[kAniso] ? 1 : 0, (uint32_t)(msaa > 1 ? msaa : 1)) != 0;
        // wr3a: the scene in half floats (HDR), its depth sampled (ambient occlusion, the atmosphere)
        int hdr = s[kHdr] != 0;          // (the sink falls back to 8 bits where half floats can't be drawn)
        if (hulk_gfx_sink_targets((uint32_t)hdr, s[kAo] || s[kAtmosphere] ? 1 : 0))   // (wlook2: the atmosphere)
            remake = true;
        if (remake)
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

// wlook2: the Fog row's value (atmosphere.cpp scales its own fog by it)
int rm::fogSetting() { return rm::s_fog; }

// app.cpp's gfx_fog import lands here (the fog pass's setting)
extern "C" void rm_set_fog(int value) { rm::s_fog = value; }
