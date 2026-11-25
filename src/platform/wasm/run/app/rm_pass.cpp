// The runner's render passes (rm_pass.h; wr2, D236): the registry, the dispatch around the sink, and the picture
// options that are passes today (fog, texture quality, MSAA).
#include "rm_pass.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <time.h>

#include <string>

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
Settings s_settings;           // the menu's values
Settings s_effective;          // what the passes see (wperf2: a temporal upscaler implies TAA)
bool s_sceneSeen;              // the frame's first scene-target pass was seen
bool s_holdWant;               // whud1: a pass asked for the frame's tail (Pass::holdTail)
bool s_holding;                // whud1: ops are being kept now

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

const Settings& settings() { return s_effective; }

// wperf2 (upscale.cpp, docs/performance.md 4.2): the temporal upscalers (Temporal 3, MetalFX 4; Auto 1 when the
// Anti-Aliasing row is TAA, except on Android, where FSR 1 is the cheaper pick) do the anti-aliasing too: the scene is
// jittered and single-sampled as with TAA, whatever the Anti-Aliasing row says
bool upscalerTemporal(const Settings& menu)
{
    int u = menu[kUpscaler];
#if defined(__ANDROID__)
    return u == 3 || u == 4;
#else
    return u == 3 || u == 4 || (u == 1 && menu[kMsaa] == 1);
#endif
}

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

// HULK_RM_TRACE=1 (development, whud1): the sink calls of the presented frames around each screenshot request
// (app.cpp rm::traceShot), one line per pass, copy, effect and run of like draws, on stderr
namespace {
int traceOn()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_RM_TRACE") && atoi(getenv("HULK_RM_TRACE")) > 0;
    return on;
}
std::string s_trace[2];           // the last frame's and this frame's
int s_traceDump;                  // frames still to print
char s_traceRun[160];
unsigned s_traceRunN;
void traceFlushRun()
{
    if (s_traceRunN) {
        char b[200];
        snprintf(b, sizeof b, "  D x%u %s\n", s_traceRunN, s_traceRun);
        s_trace[1] += b;
    }
    s_traceRunN = 0;
}
void traceLine(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
void traceLine(const char* fmt, ...)
{
    if (!traceOn())
        return;
    traceFlushRun();
    char b[300];
    va_list a;
    va_start(a, fmt);
    vsnprintf(b, sizeof b, fmt, a);
    va_end(a);
    s_trace[1] += b;
}
void traceDraw(const DrawPacket& p, uint16_t view)
{
    if (!traceOn())
        return;
    char k[160];
    snprintf(k, sizeof k, "v=%u g=%u vm=%u vp=%u kind=%u bl=%u:%u/%u dt=%u:%u dw=%u st=%u tr=%u nc=%u q=%u lit=%u",
             view, p.pass, p.viewMode, p.vertexProgram, p.shaderKind, p.state.blend, p.state.srcBlend,
             p.state.dstBlend, p.state.depthTest, p.state.depthFunc, p.state.depthWrite, p.state.stencil,
             p.transient != kSinkNone, p.vertexConstantCount, p.query != kSinkNone, p.lighting);
    if (s_traceRunN && !strcmp(k, s_traceRun)) {
        s_traceRunN++;
        return;
    }
    traceFlushRun();
    snprintf(s_traceRun, sizeof s_traceRun, "%s", k);
    s_traceRunN = 1;
}
void traceFrameEnd()
{
    if (!traceOn())
        return;
    traceFlushRun();
    if (s_traceDump > 0) {
        fprintf(stderr, "RMTRACE frame begin\n%sRMTRACE frame end\n", s_trace[1].c_str());
        s_traceDump--;
    }
    s_trace[0].swap(s_trace[1]);
    s_trace[1].clear();
}
} // namespace
void traceShot()
{
    if (!traceOn())
        return;
    fprintf(stderr, "RMTRACE shot requested (previous frame follows)\nRMTRACE frame begin\n%sRMTRACE frame end\n",
            s_trace[0].c_str());
    s_traceDump = 2;
}

static uint8_t s_forced[kQualityCount];
static bool s_forcing;
void setQuality(uint32_t what, int32_t value)
{
    if (what == 0 || what >= kQualityCount || s_settings.value[what] == value || (s_forced[what] && !s_forcing))
        return;
    s_settings.value[what] = value;
    s_effective = s_settings;
    if (upscalerTemporal(s_settings))
        s_effective.value[kMsaa] = 1;
    RM_EACH(settingsChanged(s_effective));
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
uint32_t s_workFrame[256];        // whud1: a view had work (a draw, copy or effect) this frame (== s_frameNo)
enum : uint16_t { kLastView = 250 };
void work(uint16_t view)
{
    if (view < 256)
        s_workFrame[view] = s_frameNo;
}
void forgetIdle(uint16_t g)
{
    if (s_remap && g < 256 && s_mapFrame[g] == s_frameNo && g != s_curGame && s_map[g] < 256 &&
        s_workFrame[s_map[g]] != s_frameNo)
        s_mapFrame[g] = 0;
}

void beginFrame()
{
    if (s_frameOpen)
        return;
    s_frameOpen = true;
    s_frameNo++;
    s_next = 0;
    s_curGame = 0xffff;
    s_remap = false;
    s_holdWant = false;
    for (Pass* q : ordered()) {
        s_remap = s_remap || q->midFrame();
        s_holdWant = s_holdWant || q->holdTail();
    }
    s_holdWant = s_holdWant && s_remap;
    s_holding = false;
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
    traceLine("  V new %u\n", s_next);
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
    traceLine("  V before g=%u n=%d first=%u split=%u\n", g, n, out[0], mapped);
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

// ---- whud1: the frame's tail held (rm_pass.h Pass::holdTail; run/app/hud.cpp)
// While a pass asks for it, the game's scene draws after the frame's last effect (its copies and full-screen quads:
// the HUD, the menus, subtitles) are not drawn at once but kept, with the passes they set, until the next effect (then
// drawn in order through the usual path, as if they had just come) or the present (then they are the frame's tail: the
// hud pass draws them into the present-size frame, and they are drawn into the scene target after the passes' post
// views, so the scene ends as the game drew it). Holding stops at a pass into another target and at a draw that is not
// HUD-like (it writes depth under a depth test, uses the stencil or counts pixels): those, and what was kept, go on at
// once; it starts again at the next scene pass or effect.
namespace {
struct HeldDraw {
    DrawPacket p;                 // pointers cleared: the copies below
    uint32_t c0, nc;              // vertex constants (vec4s) in s_hConst
    uint32_t t0, nt;              // transient vertices in s_hVerts (nt 0: a buffer draw)
    uint32_t m[3], l;             // matrices in s_hMats (16 floats; ~0u none), lights in s_hLights (8; ~0u none)
    uint32_t key, prog;           // combiner key / program name in s_hStr (~0u: "")
};
struct HeldOp {
    bool draw;
    bool synthetic;               // the pass that was current when holding began (already set: never set again)
    uint32_t index;               // into s_hPasses / s_hDraws
};
std::vector<HeldOp> s_hOps;
std::vector<SinkPass> s_hPasses;
std::vector<HeldDraw> s_hDraws;
std::vector<float> s_hConst, s_hMats;
std::vector<SinkVertex> s_hVerts;
std::vector<SinkLight> s_hLights;
std::vector<char> s_hStr;
bool s_inFlush;
uint8_t s_holdIds[32];            // the game pass ids the kept ops set (all of the scene's)
const uint32_t kNoCopy = ~0u;
enum { kMaxHeldDraws = 8192 };

uint32_t keepStr(const char* c)
{
    if (!c || !*c)
        return kNoCopy;
    uint32_t at = (uint32_t)s_hStr.size();
    s_hStr.insert(s_hStr.end(), c, c + strlen(c) + 1);
    return at;
}
uint32_t keepFloats(std::vector<float>& v, const float* f, size_t n)
{
    if (!f)
        return kNoCopy;
    uint32_t at = (uint32_t)v.size();
    v.insert(v.end(), f, f + n);
    return at;
}
void holdId(uint16_t g)
{
    if (g < 256)
        s_holdIds[g >> 3] |= (uint8_t)(1 << (g & 7));
}
bool heldId(uint16_t g) { return g < 256 && (s_holdIds[g >> 3] >> (g & 7) & 1); }
void heldClear()
{
    memset(s_holdIds, 0, sizeof s_holdIds);
    s_hOps.clear(), s_hPasses.clear(), s_hDraws.clear(), s_hConst.clear(), s_hMats.clear(), s_hVerts.clear();
    s_hLights.clear(), s_hStr.clear();
}
// a held draw as a packet again (the transient vertices copied into a new allocation of the sink's)
bool heldPacket(const HeldDraw& d, DrawPacket& q)
{
    q = d.p;
    q.vertexConstants = d.nc ? &s_hConst[d.c0] : nullptr;
    const float** mp[3] = {&q.modelview, &q.projection, &q.view};
    for (int i = 0; i < 3; i++)
        *mp[i] = d.m[i] != kNoCopy ? &s_hMats[d.m[i]] : nullptr;
    q.lights = d.l != kNoCopy ? &s_hLights[d.l] : nullptr;
    q.combinerKey = d.key != kNoCopy ? &s_hStr[d.key] : "";
    q.programName = d.prog != kNoCopy ? &s_hStr[d.prog] : "";
    if (d.nt) {
        uint32_t tok = kSinkNone;
        SinkVertex* v = hulk_gfx_sink_alloc_transient(d.nt, &tok);
        if (!v)
            return false;
        memcpy(v, &s_hVerts[d.t0], (size_t)d.nt * sizeof(SinkVertex));
        q.transient = tok;
        setTransient(v, d.nt);
    }
    return true;
}
bool hudLike(const DrawPacket& p)
{
    return !(p.state.depthTest && p.state.depthWrite && p.state.depthFunc != 1) && !p.state.stencil &&
           p.query == kSinkNone && s_hDraws.size() < kMaxHeldDraws;
}
void setPassNow(const SinkPass& pass);
void submitNow(const DrawPacket& p);
// what was kept goes on now, in order, through the usual path (the passes' hooks see it as if it had just come)
void heldFlush()
{
    s_holding = false;
    if (s_hOps.empty())
        return;
    s_inFlush = true;
    for (const HeldOp& o : s_hOps) {
        if (!o.draw) {
            if (!o.synthetic)
                setPassNow(s_hPasses[o.index]);
            continue;
        }
        DrawPacket q;
        if (heldPacket(s_hDraws[o.index], q))
            submitNow(q);
    }
    s_inFlush = false;
    heldClear();
}
// holding starts (after an effect, or at a scene pass): the current pass, when it is the scene's, heads the tail
void holdStart()
{
    if (!s_holdWant || !s_sceneSeen || s_holding || s_inFlush)
        return;
    s_holding = true;
    if (s_curGame != 0xffff && s_curSink.target == kSinkTargetScene) {
        SinkPass g = s_curSink;
        g.id = s_curGame;
        g.clearFlags = 0;
        s_hOps.push_back(HeldOp{false, true, (uint32_t)s_hPasses.size()});
        s_hPasses.push_back(g);
        holdId(g.id);
    }
}
void holdDraw(const DrawPacket& p)
{
    HeldDraw d;
    d.p = p;
    d.p.vertexConstants = nullptr;
    d.p.modelview = d.p.projection = d.p.view = nullptr;
    d.p.lights = nullptr;
    d.p.combinerKey = d.p.programName = "";
    d.nc = p.vertexConstants ? p.vertexConstantCount : 0;
    d.c0 = d.nc ? keepFloats(s_hConst, p.vertexConstants, (size_t)d.nc * 4) : 0;
    const float* mats[3] = {p.modelview, p.projection, p.view};
    for (int i = 0; i < 3; i++)
        d.m[i] = keepFloats(s_hMats, mats[i], 16);
    d.l = kNoCopy;
    if (p.lights) {
        d.l = (uint32_t)s_hLights.size();
        s_hLights.insert(s_hLights.end(), p.lights, p.lights + 8);
    }
    d.key = keepStr(p.combinerKey);
    d.prog = keepStr(p.programName);
    d.t0 = d.nt = 0;
    if (p.transient != kSinkNone) {
        uint32_t n = 0;
        const SinkVertex* v = transientVertices(p, &n);
        if (!v)
            return;                             // (no vertices: dropped, as a failed allocation is)
        d.t0 = (uint32_t)s_hVerts.size();
        d.nt = n;
        s_hVerts.insert(s_hVerts.end(), v, v + n);
    }
    s_hOps.push_back(HeldOp{true, false, (uint32_t)s_hDraws.size()});
    s_hDraws.push_back(d);
}
} // namespace

bool holdingDraws() { return !s_hOps.empty(); }

void drawTail(uint16_t& view, uint16_t fb, uint32_t w, uint32_t h, float sx, float sy)
{
    uint16_t map[256];
    memset(map, 0xff, sizeof map);
    uint16_t cur = kNoView;
    for (const HeldOp& o : s_hOps) {
        if (!o.draw) {
            const SinkPass& g = s_hPasses[o.index];
            uint16_t id = g.id < 256 ? g.id : 255;
            if (map[id] == 0xffff) {
                if (view > kFirstView + kViewCount - 1)
                    return;
                map[id] = view++;
            }
            cur = map[id];
            uint32_t x0 = (uint32_t)(g.x * sx + 0.5f), y0 = (uint32_t)(g.y * sy + 0.5f);
            uint32_t x1 = (uint32_t)((g.x + g.w) * sx + 0.5f), y1 = (uint32_t)((g.y + g.h) * sy + 0.5f);
            x1 = x1 > w ? w : x1, y1 = y1 > h ? h : y1;
            bgfx::setViewFrameBuffer(cur, bgfx::FrameBufferHandle{fb});
            bgfx::setViewMode(cur, bgfx::ViewMode::Sequential);
            bgfx::setViewRect(cur, (uint16_t)x0, (uint16_t)y0, (uint16_t)(x1 > x0 ? x1 - x0 : 0),
                              (uint16_t)(y1 > y0 ? y1 - y0 : 0));
            bgfx::setViewClear(cur, g.clearFlags, g.clearRgba, g.clearDepth, (uint8_t)g.clearStencil);
            bgfx::touch(cur);
            continue;
        }
        if (cur == kNoView)
            continue;
        DrawPacket q;
        if (!heldPacket(s_hDraws[o.index], q))
            continue;
        q.pass = cur;
        hulk_gfx_sink_submit_draw(&q);
    }
}

void submitDraw(const DrawPacket& p)
{
    beginFrame();
    if (s_holding) {
        if (heldId(p.pass) && hudLike(p)) {
            holdDraw(p);
            if (p.transient != kSinkNone)
                s_tVerts = nullptr, s_tCount = 0;
            return;
        }
        heldFlush();
    }
    submitNow(p);
}
namespace {
void submitNow(const DrawPacket& p)
{
    s_stencilDraws += p.state.stencil != 0, s_allDraws++;
    DrawPacket q = p;
    q.pass = sinkView(p.pass);
    RM_EACH(late(q));
    RM_EACH(draw(q));
    q.pass = sinkView(p.pass);          // (a pass may have split the game's pass: rm::viewsHere)
    traceDraw(q, q.pass);
    {
        uint64_t t0 = gs_enabled() ? gs_now() : 0;
        hulk_gfx_sink_submit_draw(&q);
        if (t0)
            gs_extra(kGxSubmit, t0);
    }
    work(q.pass);
    if (p.transient != kSinkNone)
        s_tVerts = nullptr, s_tCount = 0;   // (one draw's)
}
} // namespace

void copyFrame(uint16_t pass, const SinkTarget& dst)
{
    beginFrame();
    heldFlush();
    RM_EACH(copy(pass, dst));
    traceLine("  C g=%u v=%u dst=%u/%u\n", pass, sinkView(pass), dst.texture, dst.frameBuffer);
    SinkTarget t = dst;
    hulk_gfx_sink_copy_frame(sinkView(pass), &t);
    work(sinkView(pass));
    holdStart();
}

void fxDraw(const FxPacket& p)
{
    beginFrame();
    heldFlush();
    RM_EACH(fx(p));
    FxPacket q = p;
    q.pass = sinkView(p.pass);
    traceLine("  F g=%u v=%u prog=%u tex=%u state=%u quad=%.0f,%.0f-%.0f,%.0f t=%ux%u\n", p.pass, q.pass, p.program,
              p.textures, p.state, p.x0, p.y0, p.x1, p.y1, p.targetWidth, p.targetHeight);
    hulk_gfx_sink_fx_draw(&q);
    work(q.pass);
    holdStart();
}

void vertices(uint32_t sinkBuffer, const SinkVertexData& d)
{
    RM_EACH(vertices(sinkBuffer, d));
}

void buffersDropped(uint32_t sinkBuffer)
{
    RM_EACH(buffersDropped(sinkBuffer));
}

void indices(uint32_t sinkIndexBuffer, const uint16_t* idx, uint32_t n)
{
    for (Pass* q : ordered())
        q->indices(sinkIndexBuffer, idx, n);
}

void indicesDropped(uint32_t sinkIndexBuffer)
{
    for (Pass* q : ordered())
        q->indicesDropped(sinkIndexBuffer);
}

void textureCreated(uint32_t vid, const SinkTextureDesc& d)
{
    for (Pass* q : ordered())
        q->textureCreated(vid, d);
}

void textureLevel(uint32_t vid, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t size)
{
    for (Pass* q : ordered())
        q->textureLevel(vid, level, w, h, data, size);
}

void textureDropped(uint32_t vid)
{
    for (Pass* q : ordered())
        q->textureDropped(vid);
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
    if (s_holding && pass.target == kSinkTargetScene) {
        s_hOps.push_back(HeldOp{false, false, (uint32_t)s_hPasses.size()});
        s_hPasses.push_back(pass);
        holdId(pass.id);
        return;
    }
    heldFlush();
    setPassNow(pass);
    if (pass.target == kSinkTargetScene)
        holdStart();
}
namespace {
void setPassNow(const SinkPass& pass)
{
    SinkPass p = pass;
    if (pass.target == kSinkTargetScene && !s_sceneSeen) {
        s_sceneSeen = true;
        RM_EACH(sceneBegin(p));         // (a pass may take views before the scene's: rm::newView)
    }
    // whud1: a game pass set again after others, whose view has had no work this frame, takes a new view in its place
    // in the order (the game's pass ids follow on from the last frame's: the first pass of a frame, set before the
    // world and never drawn into, has the id the frame's HUD pass takes when this frame has one effect pass more;
    // drawn into that first view, the HUD went under the world's clear: f39000, an explosion's extra pass)
    forgetIdle(pass.id);
    s_curGame = pass.id;
    p.id = sinkView(pass.id);
    traceLine("  P g=%u v=%u tgt=%s%u clr=%u rgba=%08x rect=%u,%u %ux%u\n", pass.id, p.id,
              pass.target == kSinkTargetScene ? "scene" : "", pass.target == kSinkTargetScene ? 0 : pass.target,
              pass.clearFlags, pass.clearRgba, pass.x, pass.y, pass.w, pass.h);
    s_curSink = p;
    markScene(p);
    RM_EACH(passSet(pass.id, p));
    hulk_gfx_sink_set_pass(&p);
}
} // namespace

static const SinkPresent* s_present;
const SinkPresent* currentPresent() { return s_present; }

// whud1: the tail into the scene target, after the post views (the upscalers read the scene without it): each pass as
// set (the view its id has, as at once), its draws in a view of its own after the post views (no clear)
static void tailIntoScene()
{
    if (s_hOps.empty())
        return;
    s_inFlush = true;
    uint16_t cont = kNoView;
    const SinkPass* pend = nullptr;
    for (const HeldOp& o : s_hOps) {
        if (!o.draw) {
            const SinkPass& g = s_hPasses[o.index];
            if (!o.synthetic) {
                SinkPass p = g;
                forgetIdle(g.id);
                s_curGame = g.id;
                p.id = sinkView(g.id);
                s_curSink = p;
                markScene(p);
                hulk_gfx_sink_set_pass(&p);
            }
            cont = kNoView;
            pend = &g;
            continue;
        }
        if (cont == kNoView && pend && s_next <= kFirstView + kViewCount - 1) {
            SinkPass c = *pend;
            c.id = s_next++;
            c.clearFlags = 0;
            markScene(c);
            hulk_gfx_sink_set_pass(&c);
            cont = c.id;
        }
        DrawPacket q;
        if (cont == kNoView || !heldPacket(s_hDraws[o.index], q))
            continue;
        q.pass = cont;
        hulk_gfx_sink_submit_draw(&q);
    }
    s_inFlush = false;
    heldClear();
}

void present(const SinkPresent& p)
{
    s_present = &p;
    Scene s = {};
    uint32_t samples = 1;
    hulk_gfx_sink_scene_handles(&s.frameBuffer, &s.colour, &s.depth, &samples);
    s.samples = samples;
    s.width = hulk_gfx_sink_target_width();
    s.height = hulk_gfx_sink_target_height();
    s_holding = false;
    // (with renumbering the post views follow the game's and the passes' own: the tail, after them, fits too)
    uint16_t view = s_remap && s_next < kFirstView ? s_next : kFirstView;
    if (s.frameBuffer != kSinkNone) {
        HookTimer ht;
        for (Pass* q : ordered()) {
            if (s_remap && s_next > view && s_next < kFirstView)
                view = s_next;
            q->postScene(s, view);
            if (s_remap && view > s_next)
                s_next = view;
        }
    }
    tailIntoScene();
    s_present = nullptr;
    traceLine("  PRESENT next=%u remap=%u win=%ux%u rect=%d,%d %dx%d scene=%ux%u\n", s_next, s_remap, p.windowWidth,
              p.windowHeight, p.x, p.y, p.w, p.h, s.width, s.height);
    traceFrameEnd();
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
        // (wlook2: the atmosphere; wperf1: TAA, the msaa row's 1, reprojects through the depth; wfx1: soft particles)
        if (hulk_gfx_sink_targets((uint32_t)hdr, s[kAo] || s[kAtmosphere] || s[kParticles] || msaa == 1 ? 1 : 0))
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
