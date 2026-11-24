// HULK_GFX_STATS=N (wprof1): per-frame graphics statistics of the app runner, averaged over N updates and logged.
// Counts what the module asks of the sink (draws, transient vertices, prim buffer and texture uploads, passes), how
// many consecutive draws could merge, the time spent in the sink imports by kind and between updates, and bgfx's own
// stats of the last bgfx frame of each update. Reads only what the runner already has: no game state.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <bgfx/bgfx.h>
#include "gfxstats.h"
#include "perfov.h"
#include "pddi/bgfx_bridge.h"

using namespace hulk::pddi;

int g_gsOn = -1;
static int s_every;

namespace {
struct Acc {
    uint64_t frames, draws, dTransient, dIndexed, dQuery, tVerts, prims;
    uint64_t vb, vbBytes, vbRe, ib, ibBytes, ibRe, texC, texU, texBytes, passes, fx;
    uint64_t sameAll, sameButConst, pipeChg, texChg, stateChg, vbChg, groups, uniBytes;
    uint64_t ns[kGsCats], wallNs;
    double bgCpuMs, bgGpuMs, bgWaitMs;
    uint64_t bgDraws, bgTvb, bgTib, bgDynVb, bgVb;
    uint64_t bgTexMem, bgRtMem;
    uint32_t w, h;
    uint64_t waits, lateNs, lateMax, spinNs, lateHist[256];
    uint64_t xns[kGxCats], bgFrames;
} A;

struct Last {
    bool valid;
    uint16_t pass;
    uint32_t pipeline, vb, ib, transient, nc, prim;
    SinkRenderState st;
    SinkStage stage[4];
    uint64_t constHash, fragHash;
} L;

// (a word-at-a-time FNV-style mix: the constants are 1 KB a draw)
uint64_t fnv(const void* p, size_t n, uint64_t h = 0xcbf29ce484222325ull)
{
    const uint8_t* b = (const uint8_t*)p;
    size_t i = 0;
    for (; i + 8 <= n; i += 8) {
        uint64_t w;
        memcpy(&w, b + i, 8);
        h = (h ^ w) * 0x100000001b3ull;
        h ^= h >> 29;
    }
    for (; i < n; i++)
        h = (h ^ b[i]) * 0x100000001b3ull;
    return h;
}

// instancing groups: distinct (pass, pipeline, state, stages, frag, vb, ib, count) among a frame's buffer draws
const int kSet = 1 << 14;
uint64_t s_set[kSet];
uint32_t s_setGen[kSet], s_gen = 1, s_setUsed;   // (used: at most half full, or no more are counted)
uint16_t s_vbUp[65536], s_ibUp[65536];
uint64_t s_lastWall;
}

#if defined(__APPLE__)
uint64_t gs_now() { return clock_gettime_nsec_np(CLOCK_UPTIME_RAW); }
#else
uint64_t gs_now() { struct timespec t; clock_gettime(CLOCK_MONOTONIC, &t); return (uint64_t)t.tv_sec * 1000000000ull + t.tv_nsec; }
#endif

int gs_init()
{
    const char* e = getenv("HULK_GFX_STATS");
    s_every = e ? atoi(e) : 0;
    g_gsOn = s_every > 0;
    return g_gsOn;
}
static bool on() { return gs_enabled(); }

void gs_time(int cat, uint64_t t0) { A.ns[cat] += gs_now() - t0; }

void gs_draw(const DrawPacket& p)
{
    if (!on())
        return;
    A.draws++;
    bool tr = p.transient != kSinkNone;
    A.dTransient += tr;
    A.dIndexed += !tr && p.indexBuffer != kSinkNone;
    A.dQuery += p.query != kSinkNone;
    A.uniBytes += (uint64_t)p.vertexConstantCount * 16 + sizeof p.frag;
    uint64_t ch = fnv(p.vertexConstants, (size_t)p.vertexConstantCount * 16);
    uint64_t fh = fnv(p.frag, sizeof p.frag);
    if (L.valid) {
        bool samePipe = L.pipeline == p.pipeline && L.pass == p.pass;
        bool sameTex = !memcmp(L.stage, p.stage, sizeof p.stage);
        bool sameState = !memcmp(&L.st, &p.state, sizeof p.state);
        bool sameSrc = tr ? (L.transient != kSinkNone && p.state.prim == 0 && L.prim == 0)
                          : (L.vb == p.vertexBuffer && L.ib == p.indexBuffer);
        A.pipeChg += !samePipe;
        A.texChg += !sameTex;
        A.stateChg += !sameState;
        A.vbChg += tr ? L.transient == kSinkNone : (L.vb != p.vertexBuffer || L.ib != p.indexBuffer);
        bool base = samePipe && sameTex && sameState && L.fragHash == fh && L.nc == p.vertexConstantCount;
        if (base && sameSrc && L.constHash == ch)
            A.sameAll++;            // mergeable into the previous draw (one transform, one state)
        else if (base && L.constHash != ch)
            A.sameButConst++;       // only the vertex constants differ (instancing / uniform-array batching)
    }
    if (!tr && s_setUsed < kSet / 2) {
        uint64_t k = fnv(p.stage, sizeof p.stage, fnv(&p.state, sizeof p.state, fh ^ (uint64_t)p.pipeline << 32 ^
                         p.pass)) ^ ((uint64_t)p.vertexBuffer << 40 | (uint64_t)p.indexBuffer << 20 | p.count);
        uint32_t i = (uint32_t)(k ^ k >> 29) & (kSet - 1);
        for (;; i = (i + 1) & (kSet - 1)) {
            if (s_setGen[i] != s_gen) {
                s_setGen[i] = s_gen, s_set[i] = k;
                s_setUsed++;
                A.groups++;
                break;
            }
            if (s_set[i] == k)
                break;
        }
    }
    uint32_t n = p.count;
    switch (p.state.prim) {
    case 0: A.prims += n / 3; break;
    case 1: A.prims += n > 2 ? n - 2 : 0; break;
    default: A.prims += n; break;
    }
    L.valid = true;
    L.pass = p.pass, L.pipeline = p.pipeline, L.vb = p.vertexBuffer, L.ib = p.indexBuffer, L.transient = p.transient;
    L.nc = p.vertexConstantCount, L.prim = p.state.prim, L.st = p.state;
    memcpy(L.stage, p.stage, sizeof p.stage);
    L.constHash = ch, L.fragHash = fh;
}
void gs_transient(uint32_t count) { if (on()) A.tVerts += count; }
void gs_vb(uint32_t vid, uint32_t count)
{
    if (!on())
        return;
    A.vb++, A.vbBytes += (uint64_t)count * sizeof(SinkVertex);
    if (s_vbUp[vid & 0xffff]++)
        A.vbRe++;
}
void gs_ib(uint32_t vid, uint32_t count)
{
    if (!on())
        return;
    A.ib++, A.ibBytes += (uint64_t)count * 2;
    if (s_ibUp[vid & 0xffff]++)
        A.ibRe++;
}
void gs_tex(int create, uint32_t bytes)
{
    if (!on())
        return;
    (create ? A.texC : A.texU)++;
    A.texBytes += bytes;
}
void gs_wait(int64_t late, int64_t spin)
{
    A.waits++, A.lateNs += (uint64_t)late, A.spinNs += (uint64_t)spin;
    if ((uint64_t)late > A.lateMax)
        A.lateMax = (uint64_t)late;
    int b = (int)(late / 10000);       // 10 us buckets
    A.lateHist[b < 255 ? b : 255]++;
}
void gs_pass() { if (on()) A.passes++; }
void gs_fx() { if (on()) A.fx++; }
void gs_extra(int cat, uint64_t t0) { A.xns[cat] += gs_now() - t0; }
void gs_sink_frame()
{
    uint64_t t0 = on() || g_perfOv ? gs_now() : 0;
    hulk_gfx_sink_frame();
    if (t0) {
        if (g_perfOv)
            perfov_encode(gs_now() - t0);
        if (on()) {
            gs_extra(kGxBgfxFrame, t0);
            A.bgFrames++;
        }
    }
}

void gs_frame_end()
{
    if (!on())
        return;
    uint64_t now = gs_now();
    if (s_lastWall)
        A.wallNs += now - s_lastWall;
    s_lastWall = now;
    A.frames++;
    L.valid = false;
    s_gen++;
    s_setUsed = 0;
    if (const bgfx::Stats* s = bgfx::getStats()) {
        if (s->cpuTimerFreq)
            A.bgCpuMs += (double)(s->cpuTimeEnd - s->cpuTimeBegin) * 1e3 / (double)s->cpuTimerFreq,
            A.bgWaitMs += (double)(s->waitRender + s->waitSubmit) * 1e3 / (double)s->cpuTimerFreq;
        if (s->gpuTimerFreq && s->gpuTimeEnd > s->gpuTimeBegin)
            A.bgGpuMs += (double)(s->gpuTimeEnd - s->gpuTimeBegin) * 1e3 / (double)s->gpuTimerFreq;
        A.bgDraws += s->numDraw;
        A.bgTvb += (uint64_t)s->transientVbUsed;
        A.bgTib += (uint64_t)s->transientIbUsed;
        A.bgDynVb += s->numDynamicVertexBuffers;
        A.bgVb += s->numVertexBuffers;
        A.bgTexMem = (uint64_t)s->textureMemoryUsed;
        A.bgRtMem = (uint64_t)s->rtMemoryUsed;
        A.w = s->width, A.h = s->height;
    }
    if (A.frames < (uint64_t)s_every)
        return;
    double f = (double)A.frames, ms = 1e-6 / f;
    uint64_t imp = 0;
    for (int i = 0; i < kGsCats; i++)
        imp += A.ns[i];
    fprintf(stderr,
            "gfxstats: %llu upd | wall %.3f ms/upd: imports %.3f (draw %.3f transient %.3f buffers %.3f tex %.3f pass %.3f "
            "frame %.3f present %.3f other %.3f), module+rest %.3f | bgfx cpu %.3f gpu %.3f wait %.3f ms\n",
            (unsigned long long)A.frames, A.wallNs * ms, imp * ms, A.ns[kGsDraw] * ms, A.ns[kGsTransient] * ms,
            A.ns[kGsBuffers] * ms, A.ns[kGsTextures] * ms, A.ns[kGsPass] * ms, A.ns[kGsFrame] * ms,
            A.ns[kGsPresent] * ms, A.ns[kGsOther] * ms, (A.wallNs > imp ? A.wallNs - imp : 0) * ms,
            A.bgCpuMs / f, A.bgGpuMs / f, A.bgWaitMs / f);
    fprintf(stderr,
            "gfxstats:   draws %.1f/upd (transient %.1f, indexed %.1f, query %.1f; bgfx %.1f) prims %.0f | "
            "mergeable %.1f, const-only %.1f, groups %.1f | changes: pipe %.1f tex %.1f state %.1f src %.1f | "
            "passes %.1f fx %.1f | uniforms %.1f KB\n",
            A.draws / f, A.dTransient / f, A.dIndexed / f, A.dQuery / f, A.bgDraws / f, A.prims / f, A.sameAll / f,
            A.sameButConst / f, A.groups / f, A.pipeChg / f, A.texChg / f, A.stateChg / f, A.vbChg / f, A.passes / f,
            A.fx / f, A.uniBytes / f / 1024);
    fprintf(stderr,
            "gfxstats:   transient %.0f verts (%.1f KB; bgfx tvb %.1f KB) | vb uploads %.2f (%.1f KB, again %.2f) "
            "ib %.2f (%.1f KB, again %.2f) | tex create %.2f update %.2f (%.1f KB) | bgfx vb %.0f dynvb %.0f "
            "texmem %.1f MB rt %.1f MB | %ux%u\n",
            A.tVerts / f, A.tVerts * sizeof(SinkVertex) / f / 1024, A.bgTvb / f / 1024, A.vb / f, A.vbBytes / f / 1024,
            A.vbRe / f, A.ib / f, A.ibBytes / f / 1024, A.ibRe / f, A.texC / f, A.texU / f, A.texBytes / f / 1024,
            A.bgVb / f, A.bgDynVb / f, A.bgTexMem / 1048576.0, A.bgRtMem / 1048576.0, A.w, A.h);
    {
        double pf = A.bgFrames ? (double)A.bgFrames : f;
        fprintf(stderr, "gfxstats:   runner cpu ms/upd: hooks %.3f submit %.3f bgfx-frame %.3f interp %.3f | %.2f bgfx "
                "frames/upd (%.3f ms bgfx-frame each)\n", A.xns[kGxHooks] * ms, A.xns[kGxSubmit] * ms,
                A.xns[kGxBgfxFrame] * ms, A.xns[kGxInterp] * ms, pf / f, A.xns[kGxBgfxFrame] * 1e-6 / pf);
    }
    if (A.waits) {
        uint64_t k = 0, p50 = 0, p99 = 0;
        for (int i = 0; i < 256; i++) {
            k += A.lateHist[i];
            if (!p50 && k * 2 >= A.waits)
                p50 = (uint64_t)(i + 1) * 10;
            if (!p99 && k * 100 >= A.waits * 99)
                p99 = (uint64_t)(i + 1) * 10;
        }
        fprintf(stderr, "gfxstats:   pacing waits %llu: late mean %.1f us, p50 <= %llu us, p99 <= %llu us, max %.1f us; "
                "yielding %.3f ms/upd\n", (unsigned long long)A.waits, A.lateNs / 1e3 / A.waits,
                (unsigned long long)p50, (unsigned long long)p99, A.lateMax / 1e3, A.spinNs * ms);
    }
    memset(&A, 0, sizeof A);
    memset(s_vbUp, 0, sizeof s_vbUp);
    memset(s_ibUp, 0, sizeof s_ibUp);
}
