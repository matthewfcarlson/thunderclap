/* Tighter Text Spacing (port_settings.c `text_spacing`, wtext2, D250; HULK_WASM_GFX=1 builds only).
 *
 * The shipped fonts (font_futura_lt_med and font_serpentine_lt_med in art.rcf's art\fonts_<lang>.p3d, msgothic's Latin
 * glyphs too) draw each glyph's atlas cell whole and advance by the cell's width, and many cells end in blank columns:
 * body text shows gaps after w, k, x, Y, A ("lik e", "artw ork"; wtext1). The original's loader
 * (TextureFontLoader::vfunc_5 0x00295620) already trims three letters by hand (v by 2, o and r by 1: exactly their
 * blank columns). This setting trims every glyph the same way, measured from the player's own atlas when the font
 * loads: an entry hook on the loader (tools/wasm_port.py GFX_APP_HOOKS) runs it, then reads each glyph's cell in its
 * page's texture (the pddi front end keeps the CPU copy: lock slot 13, unlock slot 14) and counts the trailing columns
 * whose alpha stays below 16 (an invisible fringe; an anti-aliased edge stays). The advance becomes the ink's right
 * edge plus whatever gap the font gave beyond the cell (a tabular digit's), never more than it was:
 *     advance' = min(advance, max(advance, x + width) - blank)
 * Only Latin, Latin-1, the extended Latin blocks and general punctuation / letterlike symbols are trimmed (kana and
 * kanji stay monospaced; the button icons sit outside these blocks).
 *
 * TextureFont (32-bit layout, src/engine/pure3d/TextureFontLoader.cpp): pages +0x2c count / +0x30 array of
 * pure3d::Texture* (+0x10 the pddi texture), glyphs +0x38 count / +0x3c array of 0x28-byte glyphs: +0 x offset, +8
 * width, +0xc advance (float), +0x10 code (u16), +0x14 page, +0x18 u0, +0x1c v0, +0x20 u1, +0x24 v1. The advance is
 * read only by the font itself: TextureFont::vfunc_18 0x00295270 (a line's width: wrapping, centring), vfunc_10 (the
 * widest line) and vfunc_19 0x002952e0 (drawing).
 *
 * It changes game state: the glyph tables are in the game heap, and the game lays text out from the widths. So it is
 * a per-session setting (port_settings.c changes_game): replays and tests pin it off (the faithful value), netplay
 * peers share it. Nothing at all happens with it off: the hook only remembers the loaded fonts. Measuring locks and
 * unlocks the atlas (one more upload of it), so it waits until the setting is on. The record of what was trimmed lives
 * in hulk_game_state, next to the heap it describes (a snapshot restores both). HULK_TEXT_LOG=1 logs the trims. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "port_settings.h"

#define GAME_STATE __attribute__((section("hulk_game_state")))

#define TEXTUREFONT_VFTABLE 0x0042d15cu
#define TF_PAGE_COUNT 0x2c
#define TF_PAGES 0x30
#define TF_GLYPH_COUNT 0x38
#define TF_GLYPHS 0x3c
#define GLYPH_SIZE 0x28
#define BLANK_ALPHA 16          /* a column whose alpha stays below this is blank */
#define MAX_FONTS 8
#define MAX_GLYPHS 1536         /* (msgothic has 1,050) */

typedef struct {
    uint32_t font, glyphs, count;
    int32_t measured;           /* trim[] holds the measurement */
    int32_t applied;            /* the advances are trimmed */
    uint8_t trim[MAX_GLYPHS];   /* whole pixels taken off each glyph's advance */
} font_rec;

GAME_STATE static font_rec g_fonts[MAX_FONTS];
static int g_on;

static uint32_t rd(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
static uint32_t vslot(uint32_t obj, int i) { return rd(rd(obj) + 4u * (uint32_t)i); }
static int log_on(void) {
    static int v = -1;
    if (v < 0) v = getenv("HULK_TEXT_LOG") ? atoi(getenv("HULK_TEXT_LOG")) : 0;
    return v;
}

static int latin(unsigned code) { return code < 0x0250u || (code >= 0x2000u && code < 0x2150u); }

/* the record still describes a live font (a freed one fails: its vftable or tables moved) */
static int live(const font_rec* r) {
    return r->font && rd(r->font) == TEXTUREFONT_VFTABLE && rd(r->font + TF_GLYPHS) == r->glyphs &&
           rd(r->font + TF_GLYPH_COUNT) == r->count;
}

/* pddi texture lock (bgfxTexture::LockInfo, src/platform/sdl/pddi/bgfx_pddi.h): width +0, height +4, type +0x10 (6:
 * A8R8G8B8, B G R A bytes), stride +0x48 (negative: lock row 0 is the last memory row), bits +0x50 */
typedef struct {
    const uint8_t* mem;         /* memory row 0 (v = 0) */
    int w, h, pitch;
} atlas;

static int lock_page(uint32_t font, uint32_t page, atlas* a) {
    uint32_t tex = rd(rd(font + TF_PAGES) + 4u * page);
    uint32_t ptex = tex ? rd(tex + 0x10) : 0;
    if (!ptex) return 0;
    uint32_t li = ff_call_this(vslot(ptex, 13), ptex, 2, 0u, 0u);
    int ok = 0;
    if (li) {
        int w = (int)rd(li), h = (int)rd(li + 4), type = (int)rd(li + 0x10), stride = (int)rd(li + 0x48);
        uint32_t bits = rd(li + 0x50);
        if (type == 6 && bits && w > 0 && h > 0 && stride == -4 * w) {
            a->w = w;
            a->h = h;
            a->pitch = 4 * w;
            a->mem = (const uint8_t*)PTR(bits) + (intptr_t)(h - 1) * stride;
            ok = 1;
        }
    }
    return ok;
}
static void unlock_page(uint32_t font, uint32_t page) {
    uint32_t tex = rd(rd(font + TF_PAGES) + 4u * page);
    uint32_t ptex = tex ? rd(tex + 0x10) : 0;
    if (ptex) ff_call_this(vslot(ptex, 14), ptex, 1, 0u);
}

static int clampi(int v, int lo, int hi) { return v < lo ? lo : v > hi ? hi : v; }

static void measure(font_rec* r) {
    uint32_t pages = rd(r->font + TF_PAGE_COUNT);
    memset(r->trim, 0, sizeof r->trim);
    int trimmed = 0;
    char line[600];
    int ln = 0;
    for (uint32_t pg = 0; pg < pages && pg < 32; pg++) {
        atlas a;
        int used = 0;
        for (uint32_t i = 0; i < r->count && i < MAX_GLYPHS; i++) {
            uint32_t g = r->glyphs + i * GLYPH_SIZE;
            if (rd(g + 0x14) == pg && latin(*(uint16_t*)PTR(g + 0x10))) used = 1;
        }
        if (!used || !lock_page(r->font, pg, &a)) continue;
        for (uint32_t i = 0; i < r->count && i < MAX_GLYPHS; i++) {
            uint32_t g = r->glyphs + i * GLYPH_SIZE;
            unsigned code = *(uint16_t*)PTR(g + 0x10);
            if (rd(g + 0x14) != pg || !latin(code)) continue;
            const float* f = (const float*)PTR(g);
            int x0 = clampi((int)(f[6] * a.w + 0.5f), 0, a.w), x1 = clampi((int)(f[8] * a.w + 0.5f), 0, a.w);
            int y0 = clampi((int)(f[7] * a.h + 0.5f), 0, a.h), y1 = clampi((int)(f[9] * a.h + 0.5f), 0, a.h);
            if (y0 > y1) { int t = y0; y0 = y1; y1 = t; }
            if (x1 <= x0 || y1 <= y0) continue;
            int blank = 0;
            for (int x = x1 - 1; x >= x0; x--) {
                int ink = 0;
                for (int y = y0; y < y1 && !ink; y++) ink = a.mem[(size_t)y * a.pitch + (size_t)x * 4 + 3] >= BLANK_ALPHA;
                if (ink) break;
                blank++;
            }
            if (blank == x1 - x0) continue;             /* (an empty cell: a space) */
            float adv = f[3], right = f[0] + f[2];
            float want = (adv > right ? adv : right) - (float)blank;
            if (want >= adv || want < 0) continue;
            int t = (int)(adv - want + 0.5f);
            if (t <= 0 || t > 255 || (float)t != adv - want) continue;   /* (whole pixels only: exact to undo) */
            r->trim[i] = (uint8_t)t;
            trimmed++;
            if (log_on() && ln < (int)sizeof line - 16)
                ln += snprintf(line + ln, sizeof line - (size_t)ln, code >= 33 && code < 127 ? " %c%d" : " U+%04x:%d",
                               code, t);
        }
        unlock_page(r->font, pg);
    }
    r->measured = 1;
    if (log_on())
        fprintf(stderr, "hulk: text spacing: font %08x (%u glyphs, %u pages): %d trimmed:%s\n", r->font, r->count,
                pages, trimmed, line);
}

static void set_font(font_rec* r, int on) {
    if (!live(r)) {
        memset(r, 0, sizeof *r);
        return;
    }
    if (on && !r->measured) measure(r);
    if (on == r->applied) return;
    for (uint32_t i = 0; i < r->count && i < MAX_GLYPHS; i++) {
        if (!r->trim[i]) continue;
        float* adv = (float*)PTR(r->glyphs + i * GLYPH_SIZE + 0xc);
        *adv += on ? -(float)r->trim[i] : (float)r->trim[i];
    }
    r->applied = on;
}

void hulk_wasm_text_spacing_apply(int value) {
    g_on = value != 0;
    for (int k = 0; k < MAX_FONTS; k++)
        if (g_fonts[k].font) set_font(&g_fonts[k], g_on);
}

void ffgo_00295620(uint32_t, uint32_t, void*, void*);   /* TextureFontLoader::vfunc_5 (the hook's original) */
void ffh_hulk_app_font_load(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_00295620(ecx, edx, st, rb);
    uint32_t font = rd(ARG(0));
    if (!font || rd(font) != TEXTUREFONT_VFTABLE) return;
    font_rec* r = 0;
    for (int k = 0; k < MAX_FONTS && !r; k++)
        if (!g_fonts[k].font || !live(&g_fonts[k]) || g_fonts[k].font == font) r = &g_fonts[k];
    if (!r) return;                                      /* (more than MAX_FONTS fonts alive: the rest stay as shipped) */
    memset(r, 0, sizeof *r);
    r->font = font;
    r->glyphs = rd(font + TF_GLYPHS);
    r->count = rd(font + TF_GLYPH_COUNT);
    if (!r->glyphs || !r->count) {
        r->font = 0;
        return;
    }
    if (hulk_setting("text_spacing")) set_font(r, 1);
}
