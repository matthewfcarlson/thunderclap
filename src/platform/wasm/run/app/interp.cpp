// Display rates by interpolation (fps2, D228a; docs/wasm-port.md "Display rates by interpolation").
//
// The simulation always steps at the original's rate; with a display rate above it (60, 120, the display's refresh)
// app.cpp hands each update's drawing here instead of to the sink: the passes, frame copies, draws (the packet with
// copies of its vertex constants and its transient vertices), full-screen passes and the present make one stream,
// which the pacing (`plat_pace`, the module's SwapBuffers) draws m times at alpha = (k+1)/m between the previous
// update's transforms and this one's. Nothing here writes the module's memory: the game state is the same at any
// display rate.
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <SDL3/SDL.h>
#include <bgfx/bgfx.h>

#include <vector>

#include "pddi/bgfx_bridge.h"
#include "interp.h"
#include "rm_pass.h"
#include "gfxstats.h"
#include "perfov.h"

using namespace hulk::pddi;

// wmov1's movie marker and skip ring (run/app/movie.c): while a Bink movie plays, its frames are presented as they
// come (never recorded, interpolated or drawn twice); the ring is drawn once per present, after the stream.
extern "C" int hulk_app_movie_playing(void);
extern "C" void hulk_app_movie_overlay(unsigned ww, unsigned wh);
static bool moviePlaying() { return hulk_app_movie_playing() != 0; }

namespace {

enum OpKind : uint8_t { kOpPass, kOpCopy, kOpDraw, kOpFx, kOpPresent };
struct Op {
    OpKind kind;
    uint32_t index;          // into the stream's table of that kind
};
struct Draw {
    DrawPacket p;            // host ids; pointers cleared (constants: `c`)
    uint32_t c0, nc;         // the vertex constants: consts[c0 .. c0 + 4 nc)
    uint32_t t0, nt;         // transient vertices: verts[t0 .. t0 + nt) (nt 0: a buffer draw)
    uint64_t key;
    int32_t match;           // the previous stream's draw (-1: none)
    int32_t subst;           // an unmatched draw: the matched draw of this stream whose transform it shares (-1)
    uint8_t snap;            // matched but drawn from this frame unchanged (a jump)
};
struct Copy { uint16_t pass; SinkTarget t; };
struct Stream {
    std::vector<Op> ops;
    std::vector<SinkPass> passes;
    std::vector<Copy> copies;
    std::vector<Draw> draws;
    std::vector<FxPacket> fx;
    std::vector<SinkPresent> presents;
    std::vector<float> consts;
    std::vector<SinkVertex> verts;
    double stamp;            // the display clock when the update was recorded (wgrass1: interp_display_time)
    bool valid;
    void clear()
    {
        ops.clear(), passes.clear(), copies.clear(), draws.clear(), fx.clear(), presents.clear(), consts.clear();
        verts.clear();
        valid = false;
    }
};

Stream s_streams[2];
Stream* s_cur = &s_streams[0];     // being recorded / the last closed
Stream* s_prev = &s_streams[1];    // the update before it
bool s_recording;                  // this update's drawing goes to s_cur
bool s_closed;                     // s_cur holds a closed stream not yet drawn
bool s_havePrev;
// the display clock (wgrass1): seconds of the original's fields since the start, at the start of the update being
// drawn (advanced in interp_pace); while a recorded stream is drawn, its time between the previous update's and its own
double s_clock, s_drawTime;
bool s_inStream;
int s_rate = -1;                   // display rate: 30 (no interpolation), 60, 120, 0 (the display's refresh)
int s_override = -2;               // HULK_DISPLAY_FPS (-1: none)
int s_paceMode = -1;               // 0 off, 1 on
int s_log = -1;
void* s_window;

// destroys the module made while a stream could still draw what they name
struct Deferred { uint8_t kind; uint32_t a, b; };
std::vector<Deferred> s_deferred;

// the transient vertices of the next draw (the module writes them after gfx_alloc_transient)
uint32_t s_tCount;
int32_t s_tFirst = -1;

// statistics (HULK_INTERP_LOG)
struct Stats { uint64_t draws, matched, snapped, subst, unmatched, cuts, frames, presents; double recMs, drawMs, gpuMs; uint64_t gpuN; } s_st;
// input latency (HULK_FPS_LOG): from the pad's sample (the frame end after the wait) to the update's first present and
// to its last (the update's own frame, alpha 1)
int64_t s_sampleNs;
struct Lat { double first, last; uint32_t n; } s_lat;

double nowMs()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1e3 + t.tv_nsec / 1e6;
}

int parseRate(const char* e)
{
    if (!e || !*e)
        return -1;
    if (!strcmp(e, "display"))
        return 0;
    int v = atoi(e);
    return v == 60 || v == 120 ? v : 30;
}

int rate()
{
    if (s_override == -2)
        s_override = parseRate(getenv("HULK_DISPLAY_FPS"));
    if (s_override >= 0)
        return s_override;
    return s_rate < 0 ? 30 : s_rate;
}

bool paceOn()
{
    if (s_paceMode < 0) {
        const char* e = getenv("HULK_FPS_CAP");
        const char* r = getenv("HULK_INPUT_SOURCE");
        const char* g = getenv("HULK_GFX_RENDERER");
        const char* b = getenv("HULK_RECORD_BASE");   // a playthrough session: unpaced until the hand-off
        if (e && *e)
            s_paceMode = atoi(e) != 0;
        else
            s_paceMode = !((r && !strncmp(r, "replay:", 7)) || (g && !strcmp(g, "noop")) || (b && *b));
        s_log = getenv("HULK_INTERP_LOG") ? atoi(getenv("HULK_INTERP_LOG")) : 0;
        fprintf(stderr, "hulk-app: frame pacing %s\n", s_paceMode ? "on (the game's rate)" : "off");
    }
    return s_paceMode != 0;
}

double refreshHz()
{
    static double hz = 0;
    if (hz <= 0) {
        SDL_DisplayID d = s_window ? SDL_GetDisplayForWindow((SDL_Window*)s_window) : SDL_GetPrimaryDisplay();
        const SDL_DisplayMode* m = d ? SDL_GetCurrentDisplayMode(d) : nullptr;
        hz = m && m->refresh_rate > 1 ? m->refresh_rate : 60.0;
        fprintf(stderr, "hulk-app: display refresh %.2f Hz\n", hz);
    }
    return hz;
}

// ---------------------------------------------------------------------------------------- matching and blending
uint64_t fnv(uint64_t h, const void* p, size_t n)
{
    const uint8_t* b = (const uint8_t*)p;
    for (size_t i = 0; i < n; i++)
        h = (h ^ b[i]) * 0x100000001b3ull;
    return h;
}
uint64_t drawKey(const DrawPacket& p)
{
    uint64_t h = 0xcbf29ce484222325ull;
    h = fnv(h, &p.pass, sizeof p.pass);
    h = fnv(h, &p.bufferOwner, 4);
    h = fnv(h, &p.vertexProgram, 4);
    h = fnv(h, &p.shaderKind, 4);          // (not shaderSerial: a change serial, new at every set-up)
    h = fnv(h, &p.combinerHash, 4);
    for (int i = 0; i < 4; i++)
        h = fnv(h, &p.stage[i].ordinal, 4);
    h = fnv(h, &p.state.prim, 1);
    uint8_t t = p.transient != kSinkNone;
    h = fnv(h, &t, 1);
    return h;
}

bool isFF(const Draw& d) { return d.nc == 56; }
// the draw's main transform: translation (camera space) and three basis rows; false: none known
bool frameOf(const Stream& s, const Draw& d, float t[3], float b[3][3])
{
    const float* c = &s.consts[d.c0];
    int base;
    if (isFF(d))
        base = 0;                       // c0-c3: the modelview's columns
    else if (d.p.vertexProgram == 1 || d.p.vertexProgram == 2 || d.p.vertexProgram == 4)
        base = 113 - 96;                // bone 0's three rows
    else if (d.p.vertexProgram == 3)
        base = 102 - 96;                // refract's world columns
    else
        return false;
    for (int k = 0; k < 3; k++) {
        t[k] = c[(base + k) * 4 + 3];
        for (int j = 0; j < 3; j++)
            b[k][j] = c[(base + k) * 4 + j];
    }
    return true;
}
float transDelta(const Stream& a, const Draw& da, const Stream& b, const Draw& db)
{
    float ta[3], tb[3], ba[3][3], bb[3][3];
    if (!frameOf(a, da, ta, ba) || !frameOf(b, db, tb, bb))
        return 0.0f;
    float d = 0;
    for (int k = 0; k < 3; k++)
        d += (ta[k] - tb[k]) * (ta[k] - tb[k]);
    return sqrtf(d);
}
// a jump in one update: the translation (camera space) moved more than 40 units plus 0.3 of its distance (a turn of
// the camera moves far things by their distance times the angle: 0.3 is about 17 degrees), an axis turned more than
// 30 degrees, or the scale stepped by half. (play3's world: things 100-3,000 units away move 1-40 units an update.)
bool jumped(const Stream& a, const Draw& da, const Stream& b, const Draw& db)
{
    float ta[3], tb[3], ba[3][3], bb[3][3];
    if (!frameOf(a, da, ta, ba) || !frameOf(b, db, tb, bb))
        return false;
    float d = 0;
    for (int k = 0; k < 3; k++)
        d += (ta[k] - tb[k]) * (ta[k] - tb[k]);
    float r = sqrtf(tb[0] * tb[0] + tb[1] * tb[1] + tb[2] * tb[2]), lim = 40.0f + 0.3f * r;
    if (d > lim * lim)
        return true;
    // the basis columns (rows of the 3x3 as stored: compare each of the three axis vectors)
    for (int j = 0; j < 3; j++) {
        float u[3] = {ba[0][j], ba[1][j], ba[2][j]}, v[3] = {bb[0][j], bb[1][j], bb[2][j]};
        float nu = sqrtf(u[0] * u[0] + u[1] * u[1] + u[2] * u[2]), nv = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        if (nu < 1e-6f || nv < 1e-6f)
            continue;
        float cs = (u[0] * v[0] + u[1] * v[1] + u[2] * v[2]) / (nu * nv);
        if (cs < 0.866f)                // cos 30 degrees
            return true;
        if (nu > nv * 1.5f || nv > nu * 1.5f)
            return true;                // a scale step (pop in / out)
    }
    return false;
}

void matchStreams(Stream& cur, const Stream& prev)
{
    // the previous stream's draws by key, in order
    struct KeyList { uint64_t key; std::vector<int32_t> prev, cur; };
    std::vector<KeyList> lists;
    std::vector<int32_t> slot(1u << 14, -1);       // open addressing: key -> lists index
    auto find = [&](uint64_t key, bool add) -> KeyList* {
        uint32_t m = (uint32_t)slot.size() - 1, i = (uint32_t)(key ^ (key >> 29)) & m;
        for (;; i = (i + 1) & m) {
            if (slot[i] < 0) {
                if (!add)
                    return nullptr;
                if (lists.size() * 2 > slot.size())
                    return nullptr;             // (full: unmatched)
                slot[i] = (int32_t)lists.size();
                lists.push_back(KeyList{key, {}, {}});
                return &lists.back();
            }
            if (lists[slot[i]].key == key)
                return &lists[slot[i]];
        }
    };
    for (size_t i = 0; i < prev.draws.size(); i++)
        if (KeyList* l = find(prev.draws[i].key, true))
            l->prev.push_back((int32_t)i);
    for (size_t i = 0; i < cur.draws.size(); i++) {
        Draw& d = cur.draws[i];
        d.match = d.subst = -1;
        d.snap = 0;
        if (d.nc != 56 && d.nc != 96)
            continue;
        if (KeyList* l = find(d.key, false))
            l->cur.push_back((int32_t)i);
    }
    for (KeyList& l : lists) {
        if (l.cur.empty() || l.prev.empty())
            continue;
        if (l.cur.size() == l.prev.size() || l.cur.size() * l.prev.size() > 4096) {
            size_t n = l.cur.size() < l.prev.size() ? l.cur.size() : l.prev.size();
            for (size_t k = 0; k < n; k++)
                cur.draws[l.cur[k]].match = l.prev[k];
        } else {
            std::vector<uint8_t> used(l.prev.size(), 0);
            for (int32_t ci : l.cur) {
                float best = 1e30f;
                int bk = -1;
                for (size_t k = 0; k < l.prev.size(); k++) {
                    if (used[k])
                        continue;
                    float dd = transDelta(cur, cur.draws[ci], prev, prev.draws[l.prev[k]]);
                    if (dd < best)
                        best = dd, bk = (int)k;
                }
                if (bk >= 0) {
                    used[bk] = 1;
                    cur.draws[ci].match = l.prev[bk];
                }
            }
        }
    }
    // jumps, and a cut when most of the matched draws with a known transform jumped
    uint32_t known = 0, jumps = 0;
    for (Draw& d : cur.draws) {
        if (d.match < 0)
            continue;
        const Draw& p = prev.draws[d.match];
        if (p.nc != d.nc) {
            d.match = -1;
            continue;
        }
        float t[3], b[3][3];
        if (frameOf(cur, d, t, b))
            known++;
        if (jumped(cur, d, prev, p))
            d.snap = 1, jumps++;
    }
    bool cut = known >= 8 && jumps * 2 > known;
    if (cut) {
        s_st.cuts++;
        for (Draw& d : cur.draws)
            d.snap = d.match >= 0 ? 1 : 0;
        if (s_log)
            fprintf(stderr, "hulk-app: interp: a cut (%u of %u draws jumped)\n", jumps, known);
    }
    // unmatched fixed-function draws: the transform of a matched draw with the same modelview and projection
    if (!cut) {
        std::vector<int32_t> tbl(1u << 12, -1);
        uint32_t m = (uint32_t)tbl.size() - 1;
        for (size_t i = 0; i < cur.draws.size(); i++) {
            const Draw& d = cur.draws[i];
            if (!isFF(d) || d.match < 0 || d.snap)
                continue;
            uint64_t h = fnv(0xcbf29ce484222325ull, &cur.consts[d.c0], 8 * 16);
            for (uint32_t k = (uint32_t)h & m, n = 0; n < 64; k = (k + 1) & m, n++)
                if (tbl[k] < 0) {
                    tbl[k] = (int32_t)i;
                    break;
                }
        }
        for (Draw& d : cur.draws) {
            if (!isFF(d) || d.match >= 0)
                continue;
            uint64_t h = fnv(0xcbf29ce484222325ull, &cur.consts[d.c0], 8 * 16);
            for (uint32_t k = (uint32_t)h & m, n = 0; n < 64 && tbl[k] >= 0; k = (k + 1) & m, n++)
                if (!memcmp(&cur.consts[cur.draws[tbl[k]].c0], &cur.consts[d.c0], 8 * 16)) {
                    d.subst = tbl[k];
                    break;
                }
        }
    }
    for (const Draw& d : cur.draws) {
        s_st.draws++;
        if (d.match >= 0 && d.snap)
            s_st.snapped++;
        else if (d.match >= 0)
            s_st.matched++;
        else if (d.subst >= 0)
            s_st.subst++;
        else
            s_st.unmatched++;
    }
}

inline float lerp(float a, float b, float t) { return a + (b - a) * t; }

// the fixed-function constants of draw d at alpha (out: 56 vec4s)
void blendFF(const float* a, const float* b, float t, float* o)
{
    memcpy(o, b, 56 * 16);
    for (int i = 0; i < 8 * 4; i++)                 // modelview, projection
        o[i] = lerp(a[i], b[i], t);
    bool lightsSame = true;                         // the same lights (types) on
    for (int n = 0; n < 4; n++)
        if (a[(14 + 4 * n) * 4 + 3] != b[(14 + 4 * n) * 4 + 3])
            lightsSame = false;
    if (lightsSame)
        for (int n = 0; n < 4; n++)
            for (int k = 0; k < 8; k++)             // position + type, direction + range
                o[(14 + 4 * n) * 4 + k] = k == 3 ? b[(14 + 4 * n) * 4 + 3] : lerp(a[(14 + 4 * n) * 4 + k], b[(14 + 4 * n) * 4 + k], t);
    for (int s = 0; s < 4; s++) {                   // the stage texture matrices, unless one wrapped
        const float *x = a + (32 + 4 * s) * 4, *y = b + (32 + 4 * s) * 4;
        bool wrap = false;
        for (int k = 0; k < 16; k++)
            wrap |= fabsf(x[k] - y[k]) > 0.5f;
        if (!wrap)
            for (int k = 0; k < 16; k++)
                o[(32 + 4 * s) * 4 + k] = lerp(x[k], y[k], t);
    }
    // the normal matrix from the blended modelview (bgfx_draw.cpp ffConstants: c0-c2 hold its columns)
    float w[3][3];
    for (int r = 0; r < 3; r++)
        for (int k = 0; k < 3; k++)
            w[r][k] = o[k * 4 + r];                 // m[r][k] = column k's r-th
    float a00 = w[0][0], a01 = w[0][1], a02 = w[0][2], a10 = w[1][0], a11 = w[1][1], a12 = w[1][2], a20 = w[2][0],
          a21 = w[2][1], a22 = w[2][2];
    float c00 = a11 * a22 - a12 * a21, c01 = a12 * a20 - a10 * a22, c02 = a10 * a21 - a11 * a20;
    float det = a00 * c00 + a01 * c01 + a02 * c02;
    float k = det != 0.0f ? 1.0f / det : 0.0f;
    float inv[3][3] = {
        {c00 * k, (a02 * a21 - a01 * a22) * k, (a01 * a12 - a02 * a11) * k},
        {c01 * k, (a00 * a22 - a02 * a20) * k, (a02 * a10 - a00 * a12) * k},
        {c02 * k, (a01 * a20 - a00 * a21) * k, (a00 * a11 - a01 * a10) * k},
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            o[(52 + i) * 4 + j] = inv[i][j];
}

void destroyNow(const Deferred& d)
{
    SinkTarget t = {d.a, d.b};
    switch (d.kind) {
    case 1: hulk_gfx_sink_destroy_texture(d.a); break;
    case 2: hulk_gfx_sink_destroy_buffers(d.a, d.b); break;
    case 3: hulk_gfx_sink_destroy_render_target(&t); break;
    case 4: hulk_gfx_sink_destroy_copy_target(&t); break;
    }
}
void runDeferred()
{
    for (const Deferred& d : s_deferred)
        destroyNow(d);
    s_deferred.clear();
}

// draw the closed stream at alpha t; the last present of an update keeps the front buffer
std::vector<float> s_scratch;
void drawStream(const Stream& s, const Stream* prev, float t, bool last)
{
    s_scratch.resize(96 * 4);
    s_drawTime = prev ? prev->stamp + (s.stamp - prev->stamp) * (double)t : s.stamp;
    s_inStream = true;
    struct End { ~End() { s_inStream = false; } } end;
    for (const Op& op : s.ops) {
        switch (op.kind) {
        case kOpPass:
            rm::setPass(s.passes[op.index]);
            break;
        case kOpCopy:
            rm::copyFrame(s.copies[op.index].pass, s.copies[op.index].t);
            break;
        case kOpFx:
            rm::fxDraw(s.fx[op.index]);
            break;
        case kOpPresent: {
            SinkPresent p = s.presents[op.index];
            if (!last)
                p.keepFrontBuffer = 0;
            hulk_app_movie_overlay(p.windowWidth, p.windowHeight);
            rm::present(p);
            break;
        }
        case kOpDraw: {
            const Draw& d = s.draws[op.index];
            DrawPacket p = d.p;
            const float* c = &s.consts[d.c0];
            if (prev && t < 1.0f) {
                const Draw* src = nullptr;
                const Draw* via = &d;
                if (d.match >= 0 && !d.snap)
                    src = &prev->draws[d.match];
                else if (d.subst >= 0)
                    via = &s.draws[d.subst], src = &prev->draws[via->match];
                if (src) {
                    const float* a = &prev->consts[src->c0];
                    const float* b = &s.consts[via->c0];
                    float* o = s_scratch.data();
                    if (isFF(d)) {
                        blendFF(a, b, t, o);
                        if (via != &d) {            // only the shared transform: the rest is the draw's own
                            float own[56 * 4];
                            memcpy(own, c, sizeof own);
                            memcpy(own, o, 8 * 16);
                            memcpy(own + 52 * 4, o + 52 * 4, 3 * 16);
                            memcpy(o, own, sizeof own);
                        }
                    } else {
                        for (uint32_t i = 0; i < d.nc * 4; i++)
                            o[i] = lerp(a[i], b[i], t);
                    }
                    c = o;
                }
            }
            p.vertexConstants = c;
            if (d.nt) {
                uint32_t tok = kSinkNone;
                SinkVertex* v = hulk_gfx_sink_alloc_transient(d.nt, &tok);
                if (!v)
                    break;
                memcpy(v, &s.verts[d.t0], (size_t)d.nt * sizeof(SinkVertex));
                p.transient = tok;
                rm::setTransient(v, d.nt);               // (wlook2: the night lights read glow sprites)
            }
            rm::submitDraw(p);
            break;
        }
        }
    }
}

// HULK_INTERP_DUMP=A:B: the draws of updates A..B (one line each: identity, constants count, translation, match)
void dumpStream(const Stream& s)
{
    static long a = -2, b;
    if (a == -2) {
        const char* e = getenv("HULK_INTERP_DUMP");
        a = -1;
        if (e)
            sscanf(e, "%ld:%ld", &a, &b);
    }
    long f = (long)s_st.frames;
    if (a < 0 || f < a || f > b)
        return;
    for (size_t i = 0; i < s.draws.size(); i++) {
        const Draw& d = s.draws[i];
        float t[3] = {0, 0, 0}, m[3][3];
        frameOf(s, d, t, m);
        fprintf(stderr, "IDUMP %ld %zu pass=%u own=%u vp=%u ser=%u comb=%08x tex=%u,%u prim=%u nt=%u nc=%u cnt=%u "
                "inst=%llx phase=%u t=%.3f,%.3f,%.3f match=%d snap=%u subst=%d\n", f, i, d.p.pass, d.p.bufferOwner,
                d.p.vertexProgram, d.p.shaderSerial, d.p.combinerHash, d.p.stage[0].ordinal, d.p.stage[1].ordinal,
                d.p.state.prim, d.nt, d.nc, d.p.count, (unsigned long long)d.p.instance, d.p.phase, t[0], t[1], t[2],
                d.match, d.snap, d.subst);
    }
}

// HULK_INTERP_SHOT=A:B: a screenshot of every present of updates A..B (interp_UPDATE_K.tga; local only)
void shotMaybe(int k)
{
    static long a = -2, b;
    if (a == -2) {
        const char* e = getenv("HULK_INTERP_SHOT");
        a = -1;
        if (e)
            sscanf(e, "%ld:%ld", &a, &b);
    }
    long f = (long)s_st.frames;
    if (a < 0 || f < a || f > b)
        return;
    char path[64];
    snprintf(path, sizeof path, "interp_%05ld_%d.tga", f, k);
    hulk_gfx_sink_request_screenshot(path);
}

int64_t s_deadlineNs, s_nextPresentNs;
int64_t nsNow()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (int64_t)t.tv_sec * 1000000000 + t.tv_nsec;
}
void waitUntil(int64_t ns)
{
    int64_t spin = 0;
    bool waited = false;
    for (;;) {
        int64_t now = nsNow(), d = ns - now;
        if (d <= 0) {
            if (waited && gs_enabled())
                gs_wait(-d, spin);          // (HULK_GFX_STATS: how late the wait woke, how long it yielded)
            return;
        }
        waited = true;
        if (d > 2000000) {
            usleep((useconds_t)((d - 1000000) / 1000));
        } else {
            sched_yield();
            spin += nsNow() - now;
        }
    }
}

// HULK_FPS_LOG: present and update rates
struct PresentLog { int64_t last, worst, sum; uint32_t n, updates; } s_pl;
void logPresent()
{
    static int on = -1;
    if (on < 0)
        on = getenv("HULK_FPS_LOG") && *getenv("HULK_FPS_LOG") == '1';
    if (!on)
        return;
    int64_t now = nsNow();
    if (s_pl.last) {
        int64_t dt = now - s_pl.last;
        s_pl.sum += dt;
        if (dt > s_pl.worst)
            s_pl.worst = dt;
        if (++s_pl.n == 240) {
            fprintf(stderr, "hulk-app: presents %.1f fps (worst %.2f ms), updates %.1f /s over %u presents; input to "
                    "first present %.1f ms, to the update's own frame %.1f ms\n",
                    1e9 * s_pl.n / (double)s_pl.sum, s_pl.worst / 1e6, 1e9 * s_pl.updates / (double)s_pl.sum, s_pl.n,
                    s_lat.n ? s_lat.first / s_lat.n : 0.0, s_lat.n ? s_lat.last / s_lat.n : 0.0);
            s_lat = Lat{};
            s_pl.n = s_pl.updates = 0;
            s_pl.sum = s_pl.worst = 0;
        }
    }
    s_pl.last = now;
}

} // namespace

// ------------------------------------------------------------------------------------------- app.cpp's side
void interp_set_window(void* w) { s_window = w; }
void interp_set_rate(int r)
{
    if (r != s_rate)
        fprintf(stderr, "hulk-app: display rate %s\n", r == 0 ? "the display's" : r == 60 ? "60" : r == 120 ? "120" : "30");
    s_rate = r;
}
void interp_discontinuity() { s_havePrev = false; }
// a playthrough session's hand-off (wplay4; the module's plat_record_live): paced from here on, as free play
void interp_record_live()
{
    const char* e = getenv("HULK_FPS_CAP");
    paceOn();
    if (!(e && *e) && !s_paceMode) {
        s_paceMode = 1;
        s_deadlineNs = 0;
        fprintf(stderr, "hulk-app: frame pacing on (the player has the pad)\n");
    }
    s_havePrev = false;
}
bool interp_recording() { return s_recording; }

void interp_pass(const SinkPass& p)
{
    s_cur->ops.push_back(Op{kOpPass, (uint32_t)s_cur->passes.size()});
    s_cur->passes.push_back(p);
}
void interp_copy(uint16_t pass, const SinkTarget& t)
{
    s_cur->ops.push_back(Op{kOpCopy, (uint32_t)s_cur->copies.size()});
    s_cur->copies.push_back(Copy{pass, t});
}
void interp_fx(const FxPacket& p)
{
    s_cur->ops.push_back(Op{kOpFx, (uint32_t)s_cur->fx.size()});
    s_cur->fx.push_back(p);
}
void interp_present(const SinkPresent& p)
{
    s_cur->ops.push_back(Op{kOpPresent, (uint32_t)s_cur->presents.size()});
    s_cur->presents.push_back(p);
}
// the module's transient vertices for the next draw (null: an allocation began, the vertices follow)
void interp_transient(const SinkVertex* v, uint32_t count)
{
    s_tFirst = -1;
    if (!v)
        return;
    s_tFirst = (int32_t)s_cur->verts.size();
    s_tCount = count;
    s_cur->verts.insert(s_cur->verts.end(), v, v + count);
}
void interp_draw(const DrawPacket& p)
{
    Draw d;
    d.p = p;
    d.p.programName = "";
    d.p.combinerKey = "";
    d.p.modelview = d.p.projection = d.p.view = nullptr;
    d.p.lights = nullptr;
    d.p.vertexConstants = nullptr;
    d.c0 = (uint32_t)s_cur->consts.size();
    d.nc = p.vertexConstantCount;
    if (p.vertexConstants && d.nc)
        s_cur->consts.insert(s_cur->consts.end(), p.vertexConstants, p.vertexConstants + 4 * d.nc);
    d.t0 = d.nt = 0;
    if (p.transient != kSinkNone) {
        if (s_tFirst < 0)
            return;                                 // (no vertices: dropped, as a failed allocation is)
        d.t0 = (uint32_t)s_tFirst;
        d.nt = s_tCount;
        s_tFirst = -1;
    }
    d.key = drawKey(p);
    d.match = d.subst = -1;
    d.snap = 0;
    s_cur->ops.push_back(Op{kOpDraw, (uint32_t)s_cur->draws.size()});
    s_cur->draws.push_back(d);
}
// a destroy: now, or once no stream can draw what it names
void interp_destroy(int kind, uint32_t a, uint32_t b)
{
    Deferred d = {(uint8_t)kind, a, b};
    if (s_recording || s_closed)
        s_deferred.push_back(d);
    else
        destroyNow(d);
}
// the update's frame end (gfx_frame): true when the stream was recorded (the present happens in interp_pace)
bool interp_frame()
{
    if (!s_recording) {
        if (s_sampleNs) {
            double l = (nsNow() - s_sampleNs) / 1e6;
            s_lat.first += l, s_lat.last += l, s_lat.n++;
        }
        s_pl.updates++;
        logPresent();
        if (s_log > 0) {                            // (30: the GPU's time a frame, for comparison)
            const bgfx::Stats* st = bgfx::getStats();
            if (st && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin)
                s_st.gpuMs += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq, s_st.gpuN++;
            if (++s_st.presents % 600 == 0)
                fprintf(stderr, "hulk-app: direct: %llu presents (GPU %.3f ms)\n", (unsigned long long)s_st.presents,
                        s_st.gpuN ? s_st.gpuMs / s_st.gpuN : 0.0);
        }
        return false;
    }
    s_recording = false;
    s_closed = true;
    s_cur->valid = true;
    s_cur->stamp = s_clock;
    return true;
}
double interp_display_time() { return s_inStream ? s_drawTime : s_clock; }
void interp_context_destroyed()
{
    s_cur->clear();
    s_prev->clear();
    s_havePrev = false;
    s_closed = false;
}

// the module's SwapBuffers wait (sdl_platform.cpp platformFramePace -> gfx.c -> plat_pace): fields of 60 Hz this
// update lasts. Draws the closed stream m times, paced; decides whether the next update records.
void interp_pace(uint32_t fields)
{
    if (g_perfOv)
        perfov_pace_begin();
    bool pace = paceOn();
    int64_t period = (int64_t)fields * 1000000000 / 60;
    int64_t now = nsNow();
    int64_t start = now;
    if (pace) {
        if (!s_deadlineNs || now > s_deadlineNs + period * 2)
            s_deadlineNs = now;
        start = s_deadlineNs;
        s_deadlineNs += period;
    }
    if (s_closed) {
        double t0 = nowMs();
        int r = rate();
        double hz = r == 0 ? refreshHz() : r;
        // the presents of this update: paced, at the display's period d from the running present clock, alpha the
        // time from the update's start plus d over its period (the displayed state trails by period - d; at a
        // whole ratio m the presents are at alpha 1/m .. 1); unpaced, m presents back to back
        struct Slot { int64_t t; float a; };
        Slot slots[16];
        int n = 0;
        int64_t d = (int64_t)(1e9 / hz);
        if (moviePlaying()) {
            s_havePrev = false;              // (a movie began during this update: its frame once, as it came)
            slots[n++] = Slot{0, 1.0f};
        } else if (pace) {
            int64_t tp = s_nextPresentNs;
            if (tp < start - d / 4 || tp > start + period || llabs(tp - start) < d / 4)
                tp = start;                  // (behind, or ahead after a load; whole ratios realign every update)
            for (; tp < s_deadlineNs - d / 8 && n < 16; tp += d) {
                double a = (double)(tp - start + d) / (double)period;
                slots[n++] = Slot{tp, a > 0.999 ? 1.0f : (float)a};
            }
            s_nextPresentNs = tp;
        } else {
            int m = (int)floor(hz * fields / 60.0 + 0.5);
            m = m < 1 ? 1 : m > 8 ? 8 : m;
            for (int k = 0; k < m; k++)
                slots[n++] = Slot{0, (float)(k + 1) / m};
        }
        bool prev = s_havePrev && s_prev->valid;
        if (prev)
            matchStreams(*s_cur, *s_prev);
        dumpStream(*s_cur);
        s_st.recMs += nowMs() - t0;
        s_pl.updates++;
        for (int k = 0; k < n; k++) {
            bool last = k == n - 1;
            if (slots[k].t) {
                if (!last && nsNow() > slots[k + 1].t)
                    continue;                       // (behind: on to the next present)
                waitUntil(slots[k].t);
            }
            double a = nowMs();
            uint64_t gsT0 = gs_enabled() || g_perfOv ? gs_now() : 0;
            drawStream(*s_cur, prev ? s_prev : nullptr, slots[k].a, last);
            if (s_sampleNs && (k == 0 || last)) {
                double l = (nsNow() - s_sampleNs) / 1e6;
                if (k == 0)
                    s_lat.first += l, s_lat.n++;
                if (last)
                    s_lat.last += l;
            }
            shotMaybe(k);
            gs_sink_frame();
            rm::frame();
            s_st.drawMs += nowMs() - a;
            if (gsT0 && gs_enabled())
                gs_extra(kGxInterp, gsT0);
            if (gsT0 && g_perfOv)
                perfov_interp(gs_now() - gsT0);
            if (s_log) {                            // (the GPU's time for a frame, as bgfx last measured it)
                const bgfx::Stats* st = bgfx::getStats();
                if (st && st->gpuTimerFreq > 0 && st->gpuTimeEnd > st->gpuTimeBegin)
                    s_st.gpuMs += 1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq, s_st.gpuN++;
            }
            s_st.presents++;
            logPresent();
        }
        s_closed = false;
        runDeferred();
        Stream* t = s_prev;
        s_prev = s_cur;
        s_cur = t;
        s_cur->clear();
        s_havePrev = true;
        s_st.frames++;
        if (s_log && s_st.frames % 300 == 0) {
            fprintf(stderr,
                    "hulk-app: interp: %llu updates, %llu presents; draws %llu: matched %.1f%%, jumped %.1f%%, "
                    "shared %.1f%%, unmatched %.1f%%; cuts %llu; match %.3f ms, draw %.3f ms a present (GPU %.3f ms)\n",
                    (unsigned long long)s_st.frames, (unsigned long long)s_st.presents, (unsigned long long)s_st.draws,
                    100.0 * s_st.matched / (s_st.draws ? s_st.draws : 1), 100.0 * s_st.snapped / (s_st.draws ? s_st.draws : 1),
                    100.0 * s_st.subst / (s_st.draws ? s_st.draws : 1), 100.0 * s_st.unmatched / (s_st.draws ? s_st.draws : 1),
                    (unsigned long long)s_st.cuts, s_st.recMs / s_st.frames, s_st.drawMs / (s_st.presents ? s_st.presents : 1),
                    s_st.gpuN ? s_st.gpuMs / s_st.gpuN : 0.0);
        }
    }
    s_clock += fields / 60.0;
    if (pace)
        waitUntil(s_deadlineNs);
    s_sampleNs = nsNow();
    // the next update records when the display runs faster than the original's 30
    bool rec = rate() != 30 && !moviePlaying();
    if (!rec) {
        runDeferred();
        s_havePrev = false;
    }
    s_recording = rec;
    if (g_perfOv)
        perfov_pace_end();
}
