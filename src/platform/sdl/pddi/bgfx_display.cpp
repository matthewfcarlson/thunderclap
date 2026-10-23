// bgfxDisplay: the window/back buffer and presentation (stands in for pure3d::d3dDisplay).
#include "bgfx_pddi.h"

#include <bgfx/bgfx.h>
#include <stdlib.h>
#include <string.h>

namespace hulk {
namespace pddi {

enum { kNone = 0xffff };

bgfxDisplay::bgfxDisplay(bgfxDevice* device)
    : m_device(device), m_width(640), m_height(480), m_depth(32), m_initialised(false), m_frame(0), m_nativeType(0),
      m_offscreen(false), m_sceneFb(kNone), m_sceneColour(kNone), m_sceneDepth(kNone), m_copyTex(kNone),
      m_targetWidth(0), m_targetHeight(0), m_presentProgram(kNone), m_uPresentTex(kNone), m_presentTried(false),
      m_wantCopy(1), m_prevFrame(kNone), m_prevAsked(0xfffffff0u), m_windowWidth(640), m_windowHeight(480),
      m_scaleMode(0), m_quadCopy(false), m_copyFb(kNone), m_prevFb(kNone)
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

// Bring bgfx up on a native window (host test builds now; the SDL3 platform layer in the native image, G1).
// renderer: a bgfx::RendererType value (Count = bgfx's default for the platform).
bool bgfxDisplay::hostInit(void* nativeWindow, void* nativeDisplay, unsigned width, unsigned height, int renderer,
                           void* callback)
{
    bgfx::Init init;
    init.callback = (bgfx::CallbackI*)callback;
    init.type = (bgfx::RendererType::Enum)renderer;
    init.platformData.type = m_nativeType ? bgfx::NativeWindowHandleType::Wayland : bgfx::NativeWindowHandleType::Default;
    init.swapChain.nwh = nativeWindow;            // bgfx (2026): the window is the init swap chain's
    init.swapChain.ndt = nativeDisplay;
    init.swapChain.width = width;
    init.swapChain.height = height;
    init.reset = BGFX_RESET_VSYNC;
    if (!bgfx::init(init)) {
        logf("pddi: bgfx::init failed\n");
        return false;
    }
    m_width = m_windowWidth = width;
    m_height = m_windowHeight = height;
    m_initialised = true;
    logf("pddi: bgfx %s, %ux%u\n", bgfx::getRendererName(bgfx::getRendererType()), width, height);
    ensureTargets();
    return true;
}

// ---- the scene target, the copy texture, the present pass (G4; see bgfx_pddi.h)
void bgfxDisplay::destroyTargets()
{
    if (m_sceneFb != kNone)
        bgfx::destroy(bgfx::FrameBufferHandle{(uint16_t)m_sceneFb});     // destroys its textures too
    destroyCopyTarget(&m_copyTex, &m_copyFb);
    destroyCopyTarget(&m_prevFrame, &m_prevFb);
    m_sceneFb = m_sceneColour = m_sceneDepth = kNone;
    m_targetWidth = m_targetHeight = 0;
}

// A texture the scene target is copied into: a blit destination, or (quad copies) a render target with a frame
// buffer of its own
unsigned bgfxDisplay::makeCopyTarget(unsigned w, unsigned h, unsigned* fb)
{
    *fb = kNone;
    const uint64_t clamp = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;
    bgfx::TextureHandle t = bgfx::createTexture2D((uint16_t)w, (uint16_t)h, false, 1, bgfx::TextureFormat::BGRA8,
                                                  (m_quadCopy ? BGFX_TEXTURE_RT : BGFX_TEXTURE_BLIT_DST) | clamp);
    if (!bgfx::isValid(t))
        return kNone;
    if (m_quadCopy) {
        bgfx::FrameBufferHandle f = bgfx::createFrameBuffer(1, &t, true);
        if (!bgfx::isValid(f)) {
            bgfx::destroy(t);
            return kNone;
        }
        *fb = f.idx;
    }
    return t.idx;
}

void bgfxDisplay::destroyCopyTarget(unsigned* tex, unsigned* fb)
{
    if (*fb != kNone)
        bgfx::destroy(bgfx::FrameBufferHandle{(uint16_t)*fb});          // and its texture
    else if (*tex != kNone)
        bgfx::destroy(bgfx::TextureHandle{(uint16_t)*tex});
    *tex = *fb = kNone;
}

bool bgfxDisplay::ensureTargets()
{
    if (!m_initialised)
        return false;
    if (!m_presentTried) {
        m_presentTried = true;
        const char* direct = getenv("HULK_GFX_DIRECT");        // 1: no scene target (the G3 path: no copies)
        if (direct && *direct == '1') {
            logf("pddi: HULK_GFX_DIRECT: drawing to the back buffer (no frame-buffer copies or effects)\n");
            return m_offscreen = false;
        }
        m_presentProgram = loadProgram("vs_pddi_present", "fs_pddi_present");
        if (m_presentProgram != kNone)
            m_uPresentTex = bgfx::createUniform("s_pddiPresent", bgfx::UniformType::Sampler).idx;
        else
            logf("pddi: no present program for this renderer: drawing to the back buffer (no frame-buffer copies)\n");
        const char* qc = getenv("HULK_GFX_QUAD_COPY");
        m_quadCopy = qc && *qc ? *qc == '1' : bgfx::getRendererType() == bgfx::RendererType::OpenGL;
        if (m_quadCopy)
            logf("pddi: render-target copies by quad (no blits)\n");
    }
    if (m_presentProgram == kNone)
        return m_offscreen = false;
    if (m_sceneFb != kNone && m_targetWidth == m_width && m_targetHeight == m_height)
        return m_offscreen = true;
    destroyTargets();
    const uint64_t rt = BGFX_TEXTURE_RT | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP | BGFX_SAMPLER_POINT;
    bgfx::TextureHandle colour = bgfx::createTexture2D((uint16_t)m_width, (uint16_t)m_height, false, 1,
                                                       bgfx::TextureFormat::BGRA8, rt);
    // depth + stencil: D24S8 where the renderer can render to it, else 32-bit float depth + stencil (MoltenVK and
    // Apple GPUs have no D24S8)
    const bgfx::Caps* caps = bgfx::getCaps();
    bgfx::TextureFormat::Enum depthFormat = bgfx::TextureFormat::D24S8;
    if (caps && !(caps->formats[bgfx::TextureFormat::D24S8] & BGFX_CAPS_FORMAT_TEXTURE_FRAMEBUFFER))
        depthFormat = bgfx::TextureFormat::D32FS8;
    bgfx::TextureHandle depth = bgfx::createTexture2D((uint16_t)m_width, (uint16_t)m_height, false, 1, depthFormat,
                                                      BGFX_TEXTURE_RT_WRITE_ONLY);
    bgfx::TextureHandle both[2] = {colour, depth};
    bgfx::FrameBufferHandle fb = bgfx::createFrameBuffer(2, both, true);
    if (!bgfx::isValid(fb)) {
        logf("pddi: scene target %ux%u (depth format %d): bgfx refused it: drawing to the back buffer\n", m_width,
             m_height, (int)depthFormat);
        bgfx::destroy(colour);
        bgfx::destroy(depth);
        return m_offscreen = false;
    }
    m_sceneFb = fb.idx;
    m_sceneColour = colour.idx;
    m_sceneDepth = depth.idx;
    // the copy (the game's display+0x498: the back buffer's size and format); a blit destination, sampled
    // (this bgfx has no blit capability bit: every renderer we build blits; WebGL2, G5, gets a quad copy if not)
    m_copyTex = makeCopyTarget(m_width, m_height, &m_copyFb);
    m_targetWidth = m_width;
    m_targetHeight = m_height;
    logf("pddi: scene target %ux%u (depth format %s)%s\n", m_width, m_height,
         depthFormat == bgfx::TextureFormat::D24S8 ? "D24S8" : "D32FS8", m_copyTex != kNone ? " + frame-buffer copy" : "");
    return m_offscreen = true;
}

// The previous frame for the framebuffer effects' overlay: made on first use (the frame it is first asked for has
// nothing in it yet: black, as a fresh Xbox front buffer would hold whatever was last shown); kept up to date by the
// present while it is asked for
unsigned bgfxDisplay::prevFrame()
{
    if (!m_offscreen || m_sceneFb == kNone)
        return kNone;
    if (m_prevFrame == kNone)
        m_prevFrame = makeCopyTarget(m_targetWidth, m_targetHeight, &m_prevFb);
    m_prevAsked = m_frame;
    return m_prevFrame;
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

void bgfxDisplay::fullQuad(uint16_t view, unsigned srcTex, uint32_t sampler, float x0, float y0, float x1, float y1)
{
    struct V { float x, y, z, u, v; };
    static bgfx::VertexLayout s_layout;
    static bool s_made;
    if (!s_made) {
        s_layout.begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
            .end();
        s_made = true;
    }
    if (bgfx::getAvailTransientVertexBuffer(4, s_layout) < 4)
        return;
    bgfx::TransientVertexBuffer tvb;
    bgfx::allocTransientVertexBuffer(&tvb, 4, s_layout);
    const bgfx::Caps* caps = bgfx::getCaps();
    bool flip = caps && caps->originBottomLeft;
    float vt = flip ? 1.0f : 0.0f, vb = flip ? 0.0f : 1.0f;
    V q[4] = {{x0, y0, 0, 0, vt}, {x1, y0, 0, 1, vt}, {x0, y1, 0, 0, vb}, {x1, y1, 0, 1, vb}};
    memcpy(tvb.data, q, sizeof(q));
    bgfx::setVertexBuffer(0, &tvb);
    bgfx::setTexture(0, bgfx::UniformHandle{(uint16_t)m_uPresentTex}, bgfx::TextureHandle{(uint16_t)srcTex},
                     sampler | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP);
    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_PT_TRISTRIP);
    bgfx::submit(view, bgfx::ProgramHandle{(uint16_t)m_presentProgram});
}

// A quad copy (renderers that can't blit): `srcTex` drawn 1:1 into the frame buffer `dstFb` in `view`
void bgfxDisplay::copyQuad(uint16_t view, unsigned srcTex, unsigned dstFb, unsigned w, unsigned h)
{
    bgfx::setViewFrameBuffer(view, bgfx::FrameBufferHandle{(uint16_t)dstFb});
    bgfx::setViewRect(view, 0, 0, (uint16_t)w, (uint16_t)h);
    bgfx::setViewClear(view, BGFX_CLEAR_NONE);
    bgfx::setViewMode(view, bgfx::ViewMode::Sequential);
    fullQuad(view, srcTex, BGFX_SAMPLER_POINT, -1.0f, 1.0f, 1.0f, -1.0f);
}

// Before bgfx::frame: the scene target onto the back buffer, a quad in the last view: 1:1 (point sampled) when the
// window has the frame's size, else scaled into presentRect with black bars around it (G5).
void bgfxDisplay::present()
{
    if (!m_initialised || !m_offscreen || m_sceneFb == kNone)
        return;
    bgfx::ViewId view = (bgfx::ViewId)kPresentView;
    if (m_prevFrame != kNone && m_frame - m_prevAsked < 2) {     // the front buffer of the next frame (a view's
        if (m_quadCopy) {                                        // blits run before its draws: the frame as drawn)
            copyQuad((uint16_t)(kPresentView - 1), m_sceneColour, m_prevFb, m_targetWidth, m_targetHeight);
        } else {
            bgfx::TextureRegion dst, srcRegion;
            dst.init(bgfx::TextureHandle{(uint16_t)m_prevFrame});
            srcRegion.init(bgfx::TextureHandle{(uint16_t)m_sceneColour});
            bgfx::blit(view, dst, srcRegion);
        }
    }
    int rx, ry, rw, rh;
    presentRect(&rx, &ry, &rw, &rh);
    unsigned ww = m_windowWidth ? m_windowWidth : 1, wh = m_windowHeight ? m_windowHeight : 1;
    bool bars = rx > 0 || ry > 0 || (unsigned)rw < ww || (unsigned)rh < wh;
    bool scaled = (unsigned)rw != m_width || (unsigned)rh != m_height;
    bgfx::setViewFrameBuffer(view, BGFX_INVALID_HANDLE);
    bgfx::setViewRect(view, 0, 0, (uint16_t)ww, (uint16_t)wh);
    bgfx::setViewClear(view, bars ? BGFX_CLEAR_COLOR : BGFX_CLEAR_NONE, 0x000000ff);
    bgfx::setViewMode(view, bgfx::ViewMode::Sequential);
    float x0 = 2.0f * (float)rx / (float)ww - 1.0f, x1 = 2.0f * (float)(rx + rw) / (float)ww - 1.0f;
    float y0 = 1.0f - 2.0f * (float)ry / (float)wh, y1 = 1.0f - 2.0f * (float)(ry + rh) / (float)wh;
    fullQuad(view, m_sceneColour, scaled && m_scaleMode == 0 ? 0 : BGFX_SAMPLER_POINT, x0, y0, x1, y1);
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
    bgfx::SwapChain sc;
    sc.width = width;
    sc.height = height;
    bgfx::reset(BGFX_RESET_VSYNC, &sc);
    if (!m_offscreen) {
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
        destroyTargets();
        if (m_presentProgram != kNone)
            bgfx::destroy(bgfx::ProgramHandle{(uint16_t)m_presentProgram});
        if (m_uPresentTex != kNone)
            bgfx::destroy(bgfx::UniformHandle{(uint16_t)m_uPresentTex});
        m_presentProgram = m_uPresentTex = kNone;
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
        if (!m_offscreen) {                     // the back buffer is the frame
            m_windowWidth = m_width;
            m_windowHeight = m_height;
            bgfx::SwapChain sc;
            sc.width = m_width;
            sc.height = m_height;
            bgfx::reset(BGFX_RESET_VSYNC, &sc);
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
// callback 0x31acc0 counts them) and presents; bgfx::frame presents with vsync.
void bgfxDisplay::vfunc_14()
{
#if HULK_PDDI_GAME && defined(_WIN32)
    platformBeforeFrame(m_frame);
#endif
    if (m_initialised) {
        flushPendingTextures(512);
        present();
        bgfx::frame();
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
