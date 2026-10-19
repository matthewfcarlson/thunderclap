// The native image's side of the display (HULK_PDDI_GAME on Windows / Wine): the window, bgfx's callback (fatal
// errors, screenshots), the run-time options and the per-frame hooks (screenshots, the draw log dump).
//
// Options (environment, read once when the display is initialised):
//   HULK_GFX_RENDERER   d3d11 (default) | d3d12 | gl | vulkan | noop
//   HULK_GFX_SIZE       WxH of the window and back buffer (default 640x480, the size the hybrid harness captures)
//   HULK_GFX_SHOT       frame numbers to capture (comma-separated); HULK_GFX_SHOT_DIR: where (default .), as
//                       shot-<frame>.tga
//   HULK_GFX_DRAWLOG    first:every:last frames to log (the hybrid build's --drawlog spec); HULK_GFX_DRAWLOG_OUT: the
//                       file (PDL1, tools/drawlog_diff.py), written after the last logged frame and at exit
//   HULK_GFX_FRAMES     exit the process after this many presented frames (test runs)
//   HULK_GFX_HIDDEN     1: don't show the window (it still exists: D3D11 needs one)
//   HULK_GFX_SELFTEST   N: when the context is created, drive N frames through the same slots the engine uses (begin
//                       frame, clear colour + clear, one triangle through the prim stream, end frame, swap), then
//                       go on with the game: the present path and the draw path, independent of how far the game gets
#include "bgfx_pddi.h"

#if HULK_PDDI_GAME && defined(_WIN32)

#include <bgfx/bgfx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

extern "C" void __cdecl hulk_native_log(const char* line);      // src/platform/sdl/xdk/startup.cpp: the trace

namespace hulk {
namespace pddi {

static void traceSink(const char* line)
{
    hulk_native_log(line);
}

static LRESULT CALLBACK wndproc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    if (m == WM_CLOSE) {
        logf("pddi: window closed\n");
        ExitProcess(0);
    }
    return DefWindowProcA(h, m, w, l);
}

struct Callback : bgfx::CallbackI {
    void fatal(const char* file, uint16_t line, bgfx::Fatal::Enum code, const char* str) override
    {
        logf("pddi: bgfx fatal %s:%u code %d: %s\n", file, line, (int)code, str);
        stubReport();
        ExitProcess(3);
    }
    void traceVargs(const char*, uint16_t, const char* fmt, va_list ap) override
    {
        char buf[512];
        _vsnprintf(buf, sizeof(buf) - 1, fmt, ap);
        buf[sizeof(buf) - 1] = 0;
        if (strstr(buf, "rror") || strstr(buf, "ailed"))   // bgfx's own trace is chatty: errors only
            logf("bgfx: %s", buf);
    }
    void profilerBegin(const char*, uint32_t, const char*, uint16_t) override {}
    void profilerBeginLiteral(const char*, uint32_t, const char*, uint16_t) override {}
    void profilerEnd() override {}
    uint32_t cacheReadSize(uint64_t) override { return 0; }
    bool cacheRead(uint64_t, void*, uint32_t) override { return false; }
    void cacheWrite(uint64_t, const void*, uint32_t) override {}
    void captureBegin(uint32_t, uint32_t, uint32_t, bgfx::TextureFormat::Enum, bool) override {}
    void captureEnd() override {}
    void captureFrame(const void*, uint32_t) override {}
    // TGA, 32-bit BGRA, top-left origin; logs the centre and a corner pixel (the check a test reads back)
    void screenShot(const char* path, uint32_t w, uint32_t h, uint32_t pitch, bgfx::TextureFormat::Enum fmt,
                    const void* data, uint32_t, bool yflip) override
    {
        const unsigned char* px = (const unsigned char*)data;
        bool bgra = fmt != bgfx::TextureFormat::RGBA8;
        FILE* f = fopen(path, "wb");
        if (f) {
            unsigned char hdr[18] = {0, 0, 2};
            hdr[12] = w & 255; hdr[13] = (w >> 8) & 255; hdr[14] = h & 255; hdr[15] = (h >> 8) & 255;
            hdr[16] = 32; hdr[17] = 0x28;
            fwrite(hdr, 18, 1, f);
            unsigned char* row = (unsigned char*)malloc(w * 4);
            for (uint32_t y = 0; y < h; y++) {
                const unsigned char* p = px + (yflip ? h - 1 - y : y) * pitch;
                for (uint32_t x = 0; x < w; x++, p += 4) {
                    row[x * 4 + 0] = bgra ? p[0] : p[2];
                    row[x * 4 + 1] = p[1];
                    row[x * 4 + 2] = bgra ? p[2] : p[0];
                    row[x * 4 + 3] = p[3];
                }
                fwrite(row, w * 4, 1, f);
            }
            free(row);
            fclose(f);
        }
        const unsigned char* c = px + (yflip ? h - 1 - h / 2 : h / 2) * pitch + (w / 2) * 4;
        logf("pddi: screenshot %s %ux%u centre rgb %u,%u,%u\n", path, w, h, bgra ? c[2] : c[0], c[1],
             bgra ? c[0] : c[2]);
    }
};

static Callback s_callback;
static HWND s_hwnd;
static unsigned s_shots[16], s_shotCount, s_drawlogLast, s_exitAfter;
static char s_shotDir[260] = ".";
static char s_drawlogOut[260];
static bool s_drawlogDumped;

static int rendererFromEnv()
{
    const char* r = getenv("HULK_GFX_RENDERER");
    if (!r || !*r || !strcmp(r, "d3d11"))
        return bgfx::RendererType::Direct3D11;
    if (!strcmp(r, "d3d12"))
        return bgfx::RendererType::Direct3D12;
    if (!strcmp(r, "gl"))
        return bgfx::RendererType::OpenGL;
    if (!strcmp(r, "vulkan"))
        return bgfx::RendererType::Vulkan;
    if (!strcmp(r, "noop"))
        return bgfx::RendererType::Noop;
    return bgfx::RendererType::Count;
}

static void readOptions(unsigned* w, unsigned* h)
{
    const char* s = getenv("HULK_GFX_SIZE");
    unsigned a, b;
    if (s && sscanf(s, "%ux%u", &a, &b) == 2 && a >= 64 && b >= 64 && a <= 8192 && b <= 8192) {
        *w = a;
        *h = b;
    }
    s = getenv("HULK_GFX_SHOT");
    while (s && *s && s_shotCount < 16) {
        s_shots[s_shotCount++] = (unsigned)strtoul(s, (char**)&s, 10);
        if (*s != ',')
            break;
        s++;
    }
    s = getenv("HULK_GFX_SHOT_DIR");
    if (s && *s)
        _snprintf(s_shotDir, sizeof(s_shotDir) - 1, "%s", s);
    s = getenv("HULK_GFX_DRAWLOG");
    unsigned first, every, last;
    if (s && sscanf(s, "%u:%u:%u", &first, &every, &last) == 3 && every) {
        drawlogEnable(first, every, last);
        s_drawlogLast = last;
    }
    s = getenv("HULK_GFX_DRAWLOG_OUT");
    if (s && *s)
        _snprintf(s_drawlogOut, sizeof(s_drawlogOut) - 1, "%s", s);
    s = getenv("HULK_GFX_FRAMES");
    if (s && *s)
        s_exitAfter = (unsigned)strtoul(s, 0, 10);
}

void platformInit()
{
    setLogSink(traceSink);
}

// display slot 4 on Windows: our window, bgfx on it. Returns false if bgfx can't start.
bool platformDisplayInit(bgfxDisplay* d, unsigned width, unsigned height)
{
    readOptions(&width, &height);
    WNDCLASSA wc;
    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = wndproc;
    wc.hInstance = GetModuleHandleA(0);
    wc.hCursor = LoadCursorA(0, (LPCSTR)IDC_ARROW);
    wc.lpszClassName = "hulk_pddi";
    RegisterClassA(&wc);
    RECT r = {0, 0, (LONG)width, (LONG)height};
    DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    AdjustWindowRect(&r, style, FALSE);
    const char* hidden = getenv("HULK_GFX_HIDDEN");
    s_hwnd = CreateWindowExA(0, "hulk_pddi", "The Incredible Hulk: Ultimate Destruction (native)",
                             style | (hidden && *hidden == '1' ? 0 : WS_VISIBLE), CW_USEDEFAULT, CW_USEDEFAULT,
                             r.right - r.left, r.bottom - r.top, 0, 0, wc.hInstance, 0);
    if (!s_hwnd) {
        logf("pddi: CreateWindowExA failed (%lu)\n", GetLastError());
        return false;
    }
    platformPump();
    return d->hostInit(s_hwnd, 0, width, height, rendererFromEnv(), &s_callback);
}

void platformPump()
{
    MSG msg;
    while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

static void dumpDrawlog()
{
    if (s_drawlogOut[0] && !s_drawlogDumped) {
        s_drawlogDumped = true;
        bool ok = drawlogDump(s_drawlogOut);
        logf("pddi: drawlog %u records -> %s%s\n", drawlogCount(), s_drawlogOut, ok ? "" : " (failed)");
    }
}

// before bgfx::frame() of frame `frame` (0-based, counting presents): request the screenshots asked for
void platformBeforeFrame(unsigned frame)
{
    for (unsigned i = 0; i < s_shotCount; i++)
        if (s_shots[i] == frame) {
            char path[300];
            _snprintf(path, sizeof(path) - 1, "%s\\shot-%u.tga", s_shotDir, frame);
            path[sizeof(path) - 1] = 0;
            bgfx::requestScreenShot(BGFX_INVALID_HANDLE, path);
        }
}

// after frame `frame` was presented
void platformAfterFrame(unsigned frame)
{
    platformPump();
    if (frame < 3 || (frame & (frame - 1)) == 0)
        logf("pddi: frame %u presented (%u draws)\n", frame, drawCount());
    if (s_drawlogLast && frame == s_drawlogLast + 1)
        dumpDrawlog();
    if (s_exitAfter && frame + 1 >= s_exitAfter) {
        bgfx::frame();          // the screenshot of the last frame is delivered on the next one
        bgfx::frame();
        dumpDrawlog();
        stubReport();
        logf("pddi: HULK_GFX_FRAMES=%u reached: exit\n", s_exitAfter);
        ExitProcess(0);
    }
}

// HULK_GFX_SELFTEST (see the top): what the engine does per frame, through the context's and display's slots
void platformSelfTest(bgfxContext* ctx, bgfxDisplay* display)
{
    const char* s = getenv("HULK_GFX_SELFTEST");
    int frames = s ? atoi(s) : 0;
    if (frames <= 0)
        return;
    logf("pddi: self-test: %d frames\n", frames);
    // a 64x64 checker texture through the device (slot 9), lock (13) and unlock (14), and a "simple" shader (device
    // slot 11) with its TEX parameter set through pddiBaseShader's slot 5 (the tree's code walking our key table)
    bgfxDevice* dev = ctx->m_device;
    int params[9] = {64, 64, 0, 32, 8, 0, 0, 0, 0};
    bgfxTexture* tex = (bgfxTexture*)dev->vfunc_9(params);
    bgfxShader* simple = (bgfxShader*)dev->vfunc_11("simple", 0);
    if (tex) {
        bgfxTexture::LockInfo* li = (bgfxTexture::LockInfo*)tex->vfunc_13(0, 0);
        for (int y = 0; y < li->height; y++) {
            unsigned* row = (unsigned*)((char*)li->bits + y * li->stride);
            for (int x = 0; x < li->width; x++)
                row[x] = ((x >> 3) ^ (y >> 3)) & 1 ? 0xffffffffu : 0xff0040c0u;    // A8R8G8B8
        }
        tex->vfunc_14(0);
    }
    bool set = simple && tex && simple->vfunc_5(0x584554 /* "TEX" */, (int)(intptr_t)tex);
    logf("pddi: self-test: texture %s, simple shader %s, TEX set through the base: %s\n", tex ? "ok" : "FAILED",
         simple ? simple->vfunc_4() : "FAILED", set ? "yes" : "no");
    static const float tri[3][3] = {{-0.9f, -0.5f, 0.5f}, {-0.1f, -0.5f, 0.5f}, {-0.5f, 0.5f, 0.5f}};
    static const float quad[4][5] = {{0.1f, -0.5f, 0.5f, 0, 1}, {0.1f, 0.5f, 0.5f, 0, 0}, {0.9f, -0.5f, 0.5f, 1, 1},
                                     {0.9f, 0.5f, 0.5f, 1, 0}};
    for (int f = 0; f < frames; f++) {
        ctx->vfunc_4();                                         // begin frame
        ctx->vfunc_6(0xff203040u);                              // clear colour (the base's clear block)
        ctx->vfunc_12(1 | 2);                                   // clear colour + depth
        bgfxPrimStream* p = (bgfxPrimStream*)ctx->vfunc_30(0, kPrimTriList, kVertexColour, 3, 0);
        for (int v = 0; v < 3; v++) {                           // as the engine's inline prim-stream writes do
            memcpy(p->posPtr, tri[v], 12);
            *(unsigned*)p->colorPtr = 0xffff8000u;
            p->vertex();
        }
        ctx->vfunc_31(p);                                       // end prims: the draw
        if (simple) {                                           // the textured quad: a strip, colour + one uv set
            p = (bgfxPrimStream*)ctx->vfunc_30(simple, kPrimTriStrip, kVertexColour | 1, 4, 0);
            for (int v = 0; v < 4; v++) {
                memcpy(p->posPtr, quad[v], 12);
                *(unsigned*)p->colorPtr = 0xffffffffu;
                memcpy(p->uvPtr, quad[v] + 3, 8);
                p->vertex();
            }
            ctx->vfunc_31(p);
        }
        ctx->vfunc_5();                                         // end frame
        display->vfunc_14();                                    // swap
    }
    logf("pddi: self-test done (%u draws)\n", drawCount());
}

} // namespace pddi
} // namespace hulk

#endif
