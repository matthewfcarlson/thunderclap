// bgfxDisplay: the window/back buffer and presentation (stands in for pure3d::d3dDisplay).
#include "bgfx_pddi.h"

#include <bgfx/bgfx.h>

namespace hulk {
namespace pddi {

bgfxDisplay::bgfxDisplay(bgfxDevice* device)
    : m_device(device), m_width(640), m_height(480), m_depth(32), m_initialised(false), m_frame(0)
{
}

bgfxDisplay::~bgfxDisplay()
{
    hostShutdown();
}

// Bring bgfx up on a native window (host test builds now; the SDL3 platform layer in the native image, G1).
// renderer: a bgfx::RendererType value (Count = bgfx's default for the platform).
bool bgfxDisplay::hostInit(void* nativeWindow, void* nativeDisplay, unsigned width, unsigned height, int renderer,
                           void* callback)
{
    bgfx::Init init;
    init.callback = (bgfx::CallbackI*)callback;
    init.type = (bgfx::RendererType::Enum)renderer;
    init.swapChain.nwh = nativeWindow;            // bgfx (2026): the window is the init swap chain's
    init.swapChain.ndt = nativeDisplay;
    init.swapChain.width = width;
    init.swapChain.height = height;
    init.reset = BGFX_RESET_VSYNC;
    if (!bgfx::init(init)) {
        logf("pddi: bgfx::init failed\n");
        return false;
    }
    m_width = width;
    m_height = height;
    m_initialised = true;
    logf("pddi: bgfx %s, %ux%u\n", bgfx::getRendererName(bgfx::getRendererType()), width, height);
    return true;
}

void bgfxDisplay::hostShutdown()
{
    if (m_initialised) {
        bgfx::shutdown();
        m_initialised = false;
    }
}

// ---- slots
// slot 4: init from the engine's display config ({width, height, depth, ...}: 0x31ae70 picks a mode from its table
// and creates the D3D device). Here: the platform's window and bgfx on it, at the platform's size (the window's,
// not the TV mode's; 640x480 by default). The host build's caller brings bgfx up itself (hostInit).
bool bgfxDisplay::vfunc_4(int a0)
{
    if (m_initialised)
        return true;
#if HULK_PDDI_GAME && defined(_WIN32)
    const int* cfg = (const int*)a0;
    logf("pddi: display init: game asks %dx%d depth %d\n", cfg ? cfg[0] : 0, cfg ? cfg[1] : 0, cfg ? cfg[2] : 0);
    if (cfg && cfg[2])
        m_depth = (unsigned)cfg[2];
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
        bgfx::SwapChain sc;
        sc.width = m_width;
        sc.height = m_height;
        bgfx::reset(BGFX_RESET_VSYNC, &sc);     // G1: check how the 2026 API wants the main window resized
    }
    return m_initialised;
}
unsigned int bgfxDisplay::vfunc_6() { return m_width; }
unsigned int bgfxDisplay::vfunc_7() { return m_height; }
int bgfxDisplay::vfunc_8() { return (int)m_depth; }
unsigned int bgfxDisplay::vfunc_9() { return 0; }
unsigned char bgfxDisplay::vfunc_10() { PDDI_STUB(10); return 0; }
unsigned int bgfxDisplay::vfunc_11() { return m_width; }     // back-buffer size: the window's (the game: its mode)
unsigned int bgfxDisplay::vfunc_12() { return m_height; }
unsigned int bgfxDisplay::vfunc_13() { return 0; }
// slot 14: swap. The game kicks the push buffer, waits for the vblanks its frame pacing asks for (the vblank
// callback 0x31acc0 counts them) and presents; bgfx::frame presents with vsync.
void bgfxDisplay::vfunc_14()
{
#if HULK_PDDI_GAME && defined(_WIN32)
    platformBeforeFrame(m_frame);
#endif
    if (m_initialised)
        bgfx::frame();
#if HULK_PDDI_GAME && defined(_WIN32)
    platformAfterFrame(m_frame);
#endif
    m_frame++;
}
void bgfxDisplay::vfunc_15(int a0, int a1) { PDDI_STUB(15); }   // copy the back buffer rect (CopyRects): G4
float bgfxDisplay::vfunc_16() { return m_height ? (float)m_width / (float)m_height : 4.0f / 3.0f; }
unsigned int bgfxDisplay::vfunc_17() { return 0; }

} // namespace pddi
} // namespace hulk
