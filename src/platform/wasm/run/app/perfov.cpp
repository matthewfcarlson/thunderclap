// The performance overlay (wperf1, docs/performance.md; Video Options > Performance Overlay: Off / FPS / Graph).
// FPS: a corner readout (presented frames a second, frame time, the render size and scale, the upscaler and the
// anti-aliasing). Graph adds the last 240 presented frames' times as bars (green within 8.3 ms, yellow within 16.7, orange
// within 33.3, red beyond; lines at 8.3 and 16.7 ms), the 1% low, and below it the CPU split a frame (the module's
// update with its own draws, interp's replays, bgfx::frame's encoding) stacked, with bgfx's GPU timer as a line.
// The runner draws it: a small B, G, R, A image made here (a 3x5 pixel font, scaled) and drawn by the sink over the
// presented frame in its second overlay slot (bgfx_sink.cpp hulk_gfx_sink_overlay_slot; slot 0 stays the movie ring and
// the controller banner). Output only: nothing here reads or writes the module's memory. Off: one test a hook.
#include "perfov.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

#include <bgfx/bgfx.h>

#include "gfxstats.h"
#include "pddi/bgfx_bridge.h"
#include "rm_pass.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_overlay_slot(unsigned slot, const void* bgra, unsigned w, unsigned h, int x, int y,
                                           unsigned version);

int g_perfOv;

namespace {

// a 3x5 font: five rows of three bits (bit 2 the left column) for the characters the overlay writes
struct Glyph { char c; uint8_t rows[5]; };
const Glyph kFont[] = {
    {'0', {7, 5, 5, 5, 7}}, {'1', {2, 6, 2, 2, 7}}, {'2', {7, 1, 7, 4, 7}}, {'3', {7, 1, 7, 1, 7}},
    {'4', {5, 5, 7, 1, 1}}, {'5', {7, 4, 7, 1, 7}}, {'6', {7, 4, 7, 5, 7}}, {'7', {7, 1, 1, 1, 1}},
    {'8', {7, 5, 7, 5, 7}}, {'9', {7, 5, 7, 1, 7}}, {'.', {0, 0, 0, 0, 2}}, {'%', {5, 1, 2, 4, 5}},
    {':', {0, 2, 0, 2, 0}}, {'/', {1, 1, 2, 4, 4}}, {'-', {0, 0, 7, 0, 0}}, {'|', {2, 2, 2, 2, 2}},
    {'(', {1, 2, 2, 2, 1}}, {')', {4, 2, 2, 2, 4}}, {'A', {2, 5, 7, 5, 5}}, {'B', {6, 5, 6, 5, 6}},
    {'C', {7, 4, 4, 4, 7}}, {'D', {6, 5, 5, 5, 6}}, {'E', {7, 4, 6, 4, 7}}, {'F', {7, 4, 6, 4, 4}},
    {'G', {7, 4, 5, 5, 7}}, {'H', {5, 5, 7, 5, 5}}, {'I', {7, 2, 2, 2, 7}}, {'J', {1, 1, 1, 5, 7}},
    {'K', {5, 5, 6, 5, 5}}, {'L', {4, 4, 4, 4, 7}}, {'M', {5, 7, 7, 5, 5}}, {'N', {6, 5, 5, 5, 5}},
    {'O', {7, 5, 5, 5, 7}}, {'P', {7, 5, 7, 4, 4}}, {'Q', {7, 5, 5, 7, 1}}, {'R', {6, 5, 6, 5, 5}},
    {'S', {7, 4, 7, 1, 7}}, {'T', {7, 2, 2, 2, 2}}, {'U', {5, 5, 5, 5, 7}}, {'V', {5, 5, 5, 5, 2}},
    {'W', {5, 5, 7, 7, 5}}, {'X', {5, 5, 2, 5, 5}}, {'Y', {5, 5, 2, 2, 2}}, {'Z', {7, 1, 2, 4, 7}},
};
const uint8_t* glyph(char c)
{
    if (c >= 'a' && c <= 'z')
        c = (char)(c - 32);
    for (const Glyph& g : kFont)
        if (g.c == c)
            return g.rows;
    return nullptr;
}

const int kN = 240;                         // (presented frames in the graph)

struct Img {
    uint32_t* px = nullptr;
    int w = 0, h = 0;
    void make(int nw, int nh)
    {
        if (nw * nh != w * h) {
            free(px);
            px = (uint32_t*)malloc((size_t)nw * nh * 4);
        }
        w = nw, h = nh;
        memset(px, 0, (size_t)w * h * 4);
    }
    // B, G, R, A in memory: a uint32 0xAARRGGBB on a little-endian host
    void rect(int x, int y, int rw, int rh, uint32_t c)
    {
        for (int j = std::max(0, y); j < std::min(h, y + rh); j++)
            for (int i = std::max(0, x); i < std::min(w, x + rw); i++)
                px[j * w + i] = c;
    }
    int text(int x, int y, int k, const char* s, uint32_t c)
    {
        for (; *s; s++, x += 4 * k) {
            const uint8_t* g = glyph(*s);
            if (!g)
                continue;
            for (int r = 0; r < 5; r++)
                for (int b = 0; b < 3; b++)
                    if (g[r] >> (2 - b) & 1)
                        rect(x + b * k, y + r * k, k, k, c);
        }
        return x;
    }
};

class PerfOverlayPass final : public rm::Pass {
  public:
    const char* name() const override { return "perf overlay"; }
    int order() const override { return 2000; }      // (after every pass, the upscaler included)
    void settingsChanged(const rm::Settings& s) override
    {
        int m = s[rm::kPerfOverlay];
        if (m != g_perfOv) {
            fprintf(stderr, "hulk-app: performance overlay %s\n", m == 0 ? "off" : m == 1 ? "fps" : "graph");
            if (!m)
                hulk_gfx_sink_overlay_slot(1, nullptr, 0, 0, 0, 0, 0);
        }
        g_perfOv = m;
        m_aa = s[rm::kMsaa];
        m_upscaler = s[rm::kUpscaler];
    }
    void postScene(const rm::Scene& s, uint16_t&) override
    {
        if (!g_perfOv)
            return;
        uint64_t now = gs_now();
        const SinkPresent* p = rm::currentPresent();
        Sample& f = m_ring[m_head];
        f.frame = m_last ? (float)((now - m_last) * 1e-6) : 0.0f;
        m_last = now;
        const bgfx::Stats* st = bgfx::getStats();
        f.gpu = st && st->gpuTimerFreq && st->gpuTimeEnd > st->gpuTimeBegin
                    ? (float)(1e3 * (double)(st->gpuTimeEnd - st->gpuTimeBegin) / (double)st->gpuTimerFreq) : 0.0f;
        f.game = m_game, f.interp = m_interp, f.encode = m_encode;
        m_interp = m_encode = 0.0f;
        m_head = (m_head + 1) % kN;
        m_count = std::min(m_count + 1, kN);
        if (!p || (++m_every & 1))                    // (the image is made every second presented frame)
            return;
        render(s, *p);
    }
    // hooks (perfov.h)
    void paceBegin(uint64_t t)
    {
        m_inPace = true;
        if (m_paceEnd)
            m_game = (float)((t - m_paceEnd) * 1e-6) - m_encodeInUpdate;
        m_encodeInUpdate = 0.0f;
    }
    void paceEnd(uint64_t t) { m_paceEnd = t, m_inPace = false; }
    void interp(uint64_t ns) { m_interp += (float)(ns * 1e-6); }
    void encode(uint64_t ns)
    {
        m_encode += (float)(ns * 1e-6);
        if (!m_inPace)
            m_encodeInUpdate += (float)(ns * 1e-6);
    }

  private:
    struct Sample { float frame, gpu, game, interp, encode; };
    void render(const rm::Scene& s, const SinkPresent& p)
    {
        int k = p.windowHeight >= 900 ? 2 : 1;      // (pixels of a font pixel: Retina-sized windows get 2)
        bool graph = g_perfOv >= 2;
        int pad = 3 * k, line = 7 * k, gw = kN * k, gh = 50 * k, sh = 30 * k;
        int w = graph ? gw + 2 * pad : 92 * 4 * k / 2;
        w = std::max(w, 70 * 4 * k / 2 + 2 * pad);
        int h = graph ? pad + 3 * line + gh + pad + sh + pad : pad + 2 * line;
        m_img.make(w, h);
        m_img.rect(0, 0, w, h, 0xE0101010u);
        // the averages over the last second's frames (or fewer)
        float sum = 0, gpu = 0, game = 0, ip = 0, enc = 0, worst = 0;
        int n = 0;
        float sorted[kN];
        for (int i = 0; i < m_count; i++) {
            const Sample& a = m_ring[(m_head - 1 - i + 2 * kN) % kN];
            if (a.frame <= 0)
                continue;
            sorted[n++] = a.frame;
            if (sum < 1000.0f) {
                sum += a.frame, gpu += a.gpu, game += a.game, ip += a.interp, enc += a.encode;
                worst += 1.0f;
            }
        }
        float ms = worst ? sum / worst : 0, fps = ms > 0 ? 1000.0f / ms : 0;
        std::sort(sorted, sorted + n);
        float low = n ? 1000.0f / sorted[std::min(n - 1, (int)ceilf(n * 0.99f) - 1)] : 0;
        char t[128];
        uint32_t white = 0xFFFFFFFFu, grey = 0xFFB0B0B0u;
        snprintf(t, sizeof t, "%3.0f FPS %5.1f MS", fps, ms);
        int y = pad;
        int x = m_img.text(pad, y, k, t, fps >= 59 ? 0xFF60FF60u : fps >= 29 ? 0xFFFFE040u : 0xFFFF6040u);
        const char* aa = m_aa == 1 ? "TAA" : m_aa >= 2 ? (m_aa == 2 ? "MSAA 2X" : m_aa == 4 ? "MSAA 4X" : "MSAA 8X") : "AA OFF";
        bool up = (uint32_t)p.w > s.width + s.width / 100;
        snprintf(t, sizeof t, "%ux%u %d%% %s %s", s.width, s.height, p.w ? (int)(100.0f * s.width / p.w + 0.5f) : 100,
                 up ? (m_upscaler ? "FSR1" : "BILINEAR") : "NATIVE", aa);
        (void)x;
        m_img.text(pad, y + line, k, t, grey);
        if (graph) {
            // the legend in the graph's colours
            float d = worst ? worst : 1.0f;
            struct { const char* f; float v; uint32_t c; } leg[5] = {
                {"1%% LOW %.0f ", low, white}, {"GPU %.1f ", gpu / d, white}, {"UPD %.1f ", game / d, 0xFF4080FFu},
                {"INT %.1f ", ip / d, 0xFFB060FFu}, {"ENC %.1f", enc / d, 0xFF40E0E0u}};
            int lx = pad;
            for (auto& e : leg) {
                snprintf(t, sizeof t, e.f, e.v);
                lx = m_img.text(lx, y + 2 * line, k, t, e.c);
            }
            int gy = pad + 3 * line, sy = gy + gh + pad;
            m_img.rect(pad, gy, gw, gh, 0xFF202020u);
            m_img.rect(pad, sy, gw, sh, 0xFF202020u);
            const float top = 33.3f;
            for (int i = 0; i < m_count; i++) {
                const Sample& a = m_ring[(m_head - m_count + i + 2 * kN) % kN];
                int cx = pad + (kN - m_count + i) * k;
                float v = std::min(a.frame, top);
                int bh = (int)(v / top * gh);
                uint32_t c = a.frame <= 8.4f ? 0xFF40E040u : a.frame <= 16.8f ? 0xFFE0E040u
                             : a.frame <= 33.4f ? 0xFFFF9020u : 0xFFFF3030u;
                m_img.rect(cx, gy + gh - bh, k, bh, c);
                // the CPU split, stacked (update blue, interp violet, encode cyan), GPU a white dot; 0..33.3 ms
                float parts[3] = {a.game, a.interp, a.encode};
                const uint32_t pc[3] = {0xFF4080FFu, 0xFFB060FFu, 0xFF40E0E0u};
                float acc = 0;
                for (int q = 0; q < 3; q++) {
                    float a0 = std::min(acc, top), a1 = std::min(acc + std::max(parts[q], 0.0f), top);
                    int y0 = sy + sh - (int)(a1 / top * sh), y1 = sy + sh - (int)(a0 / top * sh);
                    m_img.rect(cx, y0, k, y1 - y0, pc[q]);
                    acc += std::max(parts[q], 0.0f);
                }
                if (a.gpu > 0)
                    m_img.rect(cx, sy + sh - (int)(std::min(a.gpu, top) / top * sh) - k / 2, k, k, white);
            }
            for (float l : {8.33f, 16.67f}) {
                int ly = gy + gh - (int)(l / top * gh);
                m_img.rect(pad, ly, gw, std::max(1, k / 2), 0xFFA0A0A0u);
                m_img.text(pad + gw - 16 * k, ly - 6 * k, k, l < 10 ? "8.3" : "16.7", 0xFFA0A0A0u);
                m_img.rect(pad, sy + sh - (int)(l / top * sh), gw, std::max(1, k / 2), 0xFF707070u);
            }
        }
        hulk_gfx_sink_overlay_slot(1, m_img.px, (unsigned)w, (unsigned)h, 8 * k, 8 * k, ++m_version);
    }

    Sample m_ring[kN] = {};
    int m_head = 0, m_count = 0;
    unsigned m_every = 0, m_version = 0;
    uint64_t m_last = 0, m_paceEnd = 0;
    float m_game = 0, m_interp = 0, m_encode = 0, m_encodeInUpdate = 0;
    int m_aa = 0, m_upscaler = 0;
    bool m_inPace = false;
    Img m_img;
};
PerfOverlayPass s_perfPass;
rm::Registrar s_perfReg(&s_perfPass);

} // namespace

void perfov_pace_begin() { s_perfPass.paceBegin(gs_now()); }
void perfov_pace_end() { s_perfPass.paceEnd(gs_now()); }
void perfov_interp(uint64_t ns) { s_perfPass.interp(ns); }
void perfov_encode(uint64_t ns) { s_perfPass.encode(ns); }
