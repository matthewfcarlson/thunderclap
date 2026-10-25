// bgfxDisplay: the window/back buffer and presentation (stands in for pure3d::d3dDisplay). The front end's half:
// the mode, the window and where the frame lands in it; the targets, the present pass and the swap are the sink's
// (draw_sink.h; bgfx_sink.cpp since the front-end/sink split, docs/graphics-backend.md section 15).
#include "bgfx_pddi.h"

#include <stdlib.h>
#include <string.h>

namespace hulk {
namespace pddi {

enum { kNone = 0xffff };

bgfxDisplay::bgfxDisplay(bgfxDevice* device)
    : m_device(device), m_width(640), m_height(480), m_depth(32), m_initialised(false), m_frame(0), m_nativeType(0),
      m_wantCopy(1), m_prevAsked(0xfffffff0u), m_windowWidth(640), m_windowHeight(480), m_scaleMode(0)
{
    const char* sc = getenv("HULK_GFX_SCALE");
    if (sc && (!strcmp(sc, "nearest") || !strcmp(sc, "point")))
        m_scaleMode = 1;
    else if (sc && !strcmp(sc, "integer"))
        m_scaleMode = 2;
}

bgfxDisplay::~bgfxDisplay()
{
    hostShutdown();
}

// Bring the sink up on a native window (host test builds; the SDL3 platform layer in the native image, G1).
// renderer: the sink's renderer choice (bgfx: a bgfx::RendererType value; Count = bgfx's default for the platform).
bool bgfxDisplay::hostInit(void* nativeWindow, void* nativeDisplay, unsigned width, unsigned height, int renderer,
                           void* callback)
{
    SinkInit init;
    init.nativeWindow = nativeWindow;
    init.nativeDisplay = nativeDisplay;
    init.width = width;
    init.height = height;
    init.renderer = renderer;
    init.nativeType = m_nativeType;
    init.callback = callback;
    if (!drawSink()->init(init))
        return false;
    m_width = m_windowWidth = width;
    m_height = m_windowHeight = height;
    m_initialised = true;
    ensureTargets();
    return true;
}

// ---- the scene target, the copy texture, the present pass (G4; see bgfx_pddi.h): the sink's
bool bgfxDisplay::ensureTargets()
{
    if (!m_initialised)
        return false;
    return drawSink()->frameTargets(m_width, m_height);
}

bool bgfxDisplay::offscreen() const { return drawSink()->offscreen(); }
unsigned bgfxDisplay::targetWidth() const { return drawSink()->targetWidth(); }
unsigned bgfxDisplay::targetHeight() const { return drawSink()->targetHeight(); }

// The previous frame for the framebuffer effects' overlay: made on first use (the frame it is first asked for has
// nothing in it yet: black, as a fresh Xbox front buffer would hold whatever was last shown); kept up to date by the
// present while it is asked for
unsigned bgfxDisplay::prevFrame()
{
    DrawSink* sink = drawSink();
    if (!sink->sceneTarget())
        return kNone;
    unsigned t = sink->frontBuffer();
    m_prevAsked = m_frame;
    return t;
}


// Where the frame lands in the window (G5): the largest rectangle of the frame's aspect that fits, centred; with
// HULK_GFX_SCALE=integer the largest whole multiple of the frame's size that fits (when at least 1x)
void bgfxDisplay::presentRect(int* x, int* y, int* w, int* h) const
{
    unsigned ww = m_windowWidth, wh = m_windowHeight, fw = m_width, fh = m_height;
    unsigned rw = ww, rh = wh;
    if (fw && fh && ww && wh) {
        unsigned k = ww / fw < wh / fh ? ww / fw : wh / fh;
        if (m_scaleMode == 2 && k >= 1) {
            rw = fw * k;
            rh = fh * k;
        } else if ((unsigned long long)ww * fh <= (unsigned long long)wh * fw) {   // the window is narrower
            rw = ww;
            rh = (unsigned)(((unsigned long long)ww * fh + fw / 2) / fw);
        } else {
            rh = wh;
            rw = (unsigned)(((unsigned long long)wh * fw + fh / 2) / fh);
        }
    }
    *x = (int)(ww - rw) / 2;
    *y = (int)(wh - rh) / 2;
    *w = (int)rw;
    *h = (int)rh;
}

// Before the sink's frame: the scene target onto the back buffer, a quad in the last view: 1:1 (point sampled) when
// the window has the frame's size, else scaled into presentRect with black bars around it (G5).
void bgfxDisplay::present()
{
    if (!m_initialised)
        return;
    SinkPresent p;
    memset(&p, 0, sizeof(p));
    presentRect(&p.x, &p.y, &p.w, &p.h);
    unsigned ww = m_windowWidth ? m_windowWidth : 1, wh = m_windowHeight ? m_windowHeight : 1;
    bool bars = p.x > 0 || p.y > 0 || (unsigned)p.w < ww || (unsigned)p.h < wh;
    bool scaled = (unsigned)p.w != m_width || (unsigned)p.h != m_height;
    p.windowWidth = m_windowWidth;
    p.windowHeight = m_windowHeight;
    p.frameWidth = m_width;
    p.frameHeight = m_height;
    p.point = !(scaled && m_scaleMode == 0);
    p.bars = bars;
    p.keepFrontBuffer = m_frame - m_prevAsked < 2;
    drawSink()->present(p);
}

// The window's size in pixels changed (resized, fullscreen): the main swap chain follows it. With a scene target the
// game's frame keeps its size (the mode it asked for) and is scaled into the window at the present; without one the
// back buffer is the frame, and the engine reads the new size through slots 6/7/11/12.
void bgfxDisplay::hostResize(unsigned width, unsigned height)
{
    if (!m_initialised || !width || !height || (width == m_windowWidth && height == m_windowHeight))
        return;
    m_windowWidth = width;
    m_windowHeight = height;
    drawSink()->resizeBackBuffer(width, height);
    if (!offscreen()) {
        m_width = width;
        m_height = height;
    }
    ensureTargets();
    int rx, ry, rw, rh;
    presentRect(&rx, &ry, &rw, &rh);
    logf("pddi: window %ux%u (resized): the %ux%u frame at %d,%d %dx%d\n", width, height, m_width, m_height, rx, ry,
         rw, rh);
}

void bgfxDisplay::hostShutdown()
{
    if (m_initialised) {
        drawSink()->shutdown();
        m_initialised = false;
    }
}

// ---- slots
// slot 4: init from the engine's display config ({width, height, depth, ...}: 0x31ae70 picks a mode from its table
// and creates the D3D device). Here: the platform's window and the sink on it, at the platform's size (the window's,
// not the TV mode's; 640x480 by default). The host build's caller brings the sink up itself (hostInit).
bool bgfxDisplay::vfunc_4(int a0)
{
    if (m_initialised)
        return true;
#if HULK_PDDI_GAME && defined(_WIN32)
    const int* cfg = (const int*)a0;
    logf("pddi: display init: game asks %dx%d depth %d\n", cfg ? cfg[0] : 0, cfg ? cfg[1] : 0, cfg ? cfg[2] : 0);
    if (cfg && cfg[2])
        m_depth = (unsigned)cfg[2];
    if (cfg) {
        // DisplayConfig +0x2e: make the frame-buffer copy texture (0x31ae70). The copy exists either way here (the
        // refraction shader is its only reader and checks for it as the game does); logged for the record.
        m_wantCopy = ((const unsigned char*)cfg)[0x2e];
        logf("pddi: display init: frame-buffer texture %s\n", m_wantCopy ? "asked for" : "not asked for");
    }
    return platformDisplayInit(this, 640, 480);
#else
    PDDI_STUB(4);
    return m_initialised;
#endif
}
// slot 5: set the mode (width, height, depth); unchanged -> true, else re-init through slot 4
bool bgfxDisplay::vfunc_5(int a0, int a1, int a2)
{
    if ((unsigned)a0 == m_width && (unsigned)a1 == m_height && (unsigned)a2 == m_depth)
        return true;
    m_width = a0;
    m_height = a1;
    m_depth = a2;
    if (m_initialised) {
        if (!offscreen()) {                     // the back buffer is the frame
            m_windowWidth = m_width;
            m_windowHeight = m_height;
            drawSink()->resizeBackBuffer(m_width, m_height);
        }
        ensureTargets();                        // the scene target at the mode's size, presented into the window
    }
    return m_initialised;
}
// slots 6/7 (0x31ad30, 0x31ad40): the mode's height (+0x478) and width (+0x47c): 0x31ae70 gives the back buffer
// +0x47c as its width; d3dRefractVertexShader::vfunc_24 divides the back buffer's width by slot 7 (G1 had the two
// swapped; docs/subsystems.md has 7 = width, 6 = height)
unsigned int bgfxDisplay::vfunc_6() { return m_height; }
unsigned int bgfxDisplay::vfunc_7() { return m_width; }
int bgfxDisplay::vfunc_8() { return (int)m_depth; }
unsigned int bgfxDisplay::vfunc_9() { return 0; }
unsigned char bgfxDisplay::vfunc_10() { PDDI_STUB(10); return 0; }
unsigned int bgfxDisplay::vfunc_11() { return m_width; }     // back-buffer size: the window's (the game: its mode)
unsigned int bgfxDisplay::vfunc_12() { return m_height; }
unsigned int bgfxDisplay::vfunc_13() { return 0; }
// slot 14: swap. The game kicks the push buffer, waits for the vblanks its frame pacing asks for (the vblank
// callback 0x31acc0 counts them) and presents; the sink's frame presents with vsync.
void bgfxDisplay::vfunc_14()
{
#if HULK_PDDI_GAME && defined(_WIN32)
    platformBeforeFrame(m_frame);
#endif
    if (m_initialised) {
        flushPendingTextures(512);
        present();
        drawSink()->frame();
    }
#if HULK_PDDI_GAME && defined(_WIN32)
    platformFramePace();
    platformAfterFrame(m_frame);
#endif
    m_frame++;
}
void bgfxDisplay::vfunc_15(int a0, int a1) { PDDI_STUB(15); }   // copy the back buffer rect (CopyRects): G4
float bgfxDisplay::vfunc_16() { return m_height ? (float)m_width / (float)m_height : 4.0f / 3.0f; }
unsigned int bgfxDisplay::vfunc_17() { return 0; }

} // namespace pddi
} // namespace hulk
