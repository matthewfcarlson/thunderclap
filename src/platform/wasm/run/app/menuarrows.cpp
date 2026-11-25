// The menus' scroll arrows (wmenu2): Video Options and Gameplay Options show nine of their rows at a time
// (fe_options.c, wmenu1 D238); while rows are hidden above the window an up arrow sits above the first place, while rows
// are hidden below a down arrow sits below the last. fe_options.c works out which (and where, in the 640x480 frame) at
// each present and hands the packed word over through gfx_quality's `what` 0x100 (app.cpp); this pass draws the two
// triangles into a small B, G, R, A image (anti-aliased, a dark rim) that the sink blends over the presented frame in its
// third overlay slot (bgfx_sink.cpp hulk_gfx_sink_overlay_slot 2; slot 0 the movie ring / controller banner, 1 the
// performance overlay). The frame's place in the window (rm::currentPresent) maps the frame's pixels, so the arrows
// follow any window size, aspect and render scale. Output only: nothing here reads or writes the module's memory.
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

#include "rm_pass.h"

using namespace hulk::pddi;

extern "C" void hulk_gfx_sink_overlay_slot(unsigned slot, const void* bgra, unsigned w, unsigned h, int x, int y,
                                           unsigned version);

namespace {

uint32_t s_state;           // fe_options.c's word: bit 0 up, 1 down, 2..11 x, 12..20 the up arrow's y, 21..29 the down's

// signed distance (pixels, negative inside) from (px, py) to the triangle a, b, c (counter-clockwise or not)
float triDist(float px, float py, const float* t)
{
    float d = -1e9f;
    float area = (t[2] - t[0]) * (t[5] - t[1]) - (t[3] - t[1]) * (t[4] - t[0]);
    float s = area < 0 ? -1.0f : 1.0f;
    for (int e = 0; e < 3; e++) {
        float ax = t[2 * e], ay = t[2 * e + 1], bx = t[2 * ((e + 1) % 3)], by = t[2 * ((e + 1) % 3) + 1];
        float ex = bx - ax, ey = by - ay, len = sqrtf(ex * ex + ey * ey);
        if (len <= 0)
            continue;
        // outward distance from the edge's line
        d = std::max(d, -s * (ex * (py - ay) - ey * (px - ax)) / len);
    }
    return d;
}

class MenuArrowsPass final : public rm::Pass {
  public:
    const char* name() const override { return "menu arrows"; }
    int order() const override { return 2001; }      // (after the performance overlay's hook; drawn in slot order)
    void postScene(const rm::Scene&, uint16_t&) override
    {
        const SinkPresent* p = rm::currentPresent();
        uint32_t st = s_state;
        if (!p || !(st & 3) || p->w <= 0 || p->h <= 0) {
            if (m_shown)
                hulk_gfx_sink_overlay_slot(2, nullptr, 0, 0, 0, 0, 0);
            m_shown = false;
            return;
        }
        if (m_shown && st == m_st && p->x == m_px && p->y == m_py && p->w == m_pw && p->h == m_ph)
            return;
        m_st = st, m_px = p->x, m_py = p->y, m_pw = p->w, m_ph = p->h;
        float fw = p->frameWidth ? (float)p->frameWidth : 640.0f, fh = p->frameHeight ? (float)p->frameHeight : 480.0f;
        float sx = (float)p->w / fw, sy = (float)p->h / fh;
        float cx = (float)(st >> 2 & 0x3ff) * sx, yu = (float)(st >> 12 & 0x1ff) * sy, yd = (float)(st >> 21 & 0x1ff) * sy;
        // an arrow 18 x 10 frame pixels (its centre at x, y), a rim of 1.5
        float hw = 9.0f * sy, hh = 5.0f * sy, rim = std::max(1.0f, 1.5f * sy);
        int pad = (int)ceilf(rim + 2.0f);
        int x0 = (int)floorf(cx - hw) - pad, y0 = (int)floorf(yu - hh) - pad;
        int w = (int)ceilf(2 * hw) + 2 * pad + 1, h = (int)ceilf(yd - yu + 2 * hh) + 2 * pad + 1;
        if (w <= 0 || h <= 0 || w > 4096 || h > 4096)
            return;
        if (w * h != m_w * m_h) {
            free(m_px_buf);
            m_px_buf = (uint32_t*)malloc((size_t)w * h * 4);
        }
        m_w = w, m_h = h;
        memset(m_px_buf, 0, (size_t)w * h * 4);
        float lx = cx - (float)x0, uy = yu - (float)y0, dy = yd - (float)y0;
        const float up[6] = {lx - hw, uy + hh, lx + hw, uy + hh, lx, uy - hh};
        const float down[6] = {lx - hw, dy - hh, lx + hw, dy - hh, lx, dy + hh};
        for (int j = 0; j < h; j++)
            for (int i = 0; i < w; i++) {
                float px = (float)i + 0.5f, py = (float)j + 0.5f, d = 1e9f;
                if (st & 1)
                    d = std::min(d, triDist(px, py, up));
                if (st & 2)
                    d = std::min(d, triDist(px, py, down));
                if (d > rim + 0.5f)
                    continue;
                // the fill (the menu text's off-white) inside, the dark rim around it, each edge a pixel's ramp
                float fill = std::min(1.0f, std::max(0.0f, 0.5f - d));
                float cover = std::min(1.0f, std::max(0.0f, rim + 0.5f - d));
                float a = cover * 0.9f;
                float r = 0.94f * fill, g = 0.94f * fill, b = 0.86f * fill;      // (over black: straight alpha)
                float al = std::max(a, fill);
                if (al <= 0)
                    continue;
                uint32_t A = (uint32_t)lroundf(al * 255.0f), R = (uint32_t)lroundf(r / al * 255.0f),
                         G = (uint32_t)lroundf(g / al * 255.0f), B = (uint32_t)lroundf(b / al * 255.0f);
                m_px_buf[j * w + i] = A << 24 | std::min(R, 255u) << 16 | std::min(G, 255u) << 8 | std::min(B, 255u);
            }
        hulk_gfx_sink_overlay_slot(2, m_px_buf, (unsigned)w, (unsigned)h, p->x + x0, p->y + y0, ++m_version);
        m_shown = true;
    }

  private:
    uint32_t* m_px_buf = nullptr;
    int m_w = 0, m_h = 0;
    unsigned m_version = 0;
    bool m_shown = false;
    uint32_t m_st = 0;
    int32_t m_px = 0, m_py = 0, m_pw = 0, m_ph = 0;
};
HULK_RM_REGISTER_PASS(MenuArrowsPass);

}  // namespace

extern "C" void hulk_app_menu_arrows(uint32_t state) { s_state = state; }
