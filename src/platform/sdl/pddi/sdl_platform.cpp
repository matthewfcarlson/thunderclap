// The native image's side of the display (HULK_PDDI_GAME on Windows / Wine): an SDL3 window (platform_events.h owns
// the event pump; the window's native handle goes to bgfx), bgfx's callback (fatal errors, screenshots), the run-time
// options and the per-frame hooks (screenshots, the draw log dump).
//
// Options (environment, read once when the display is initialised):
//   HULK_GFX_RENDERER   d3d11 (default) | d3d12 | gl | vulkan | noop
//   HULK_GFX_SIZE       WxH of the game's frame (the mode it sees; default 640x480, the size the hybrid harness
//                       captures) and of the window unless HULK_GFX_WINDOW says otherwise
//   HULK_GFX_WINDOW     WxH of the window (G5): the frame is presented scaled into it with its aspect kept (bars)
//   HULK_GFX_SCALE      linear (default) | nearest | integer: how the frame is scaled into a window of another size
//   HULK_GFX_QUAD_COPY  1 / 0: render-target copies by full-screen quads instead of blits (default: OpenGL only)
//   HULK_GFX_SHOT       frame numbers to capture (comma-separated); HULK_GFX_SHOT_DIR: where (default .), as
//                       shot-<frame>.tga
//   HULK_GFX_DRAWLOG    first:every:last frames to log (the hybrid build's --drawlog spec); HULK_GFX_DRAWLOG_OUT: the
//                       file (PDL1, tools/drawlog_diff.py), written after the last logged frame and at exit
//   HULK_GFX_FRAMES     exit the process after this many presented frames (test runs)
//   HULK_GFX_HIDDEN     1: don't show the window (it still exists: D3D11 needs one)
//   HULK_GFX_DIRECT     1: no scene target (G4): draw straight to the back buffer, no frame-buffer copies or effects
//   HULK_GFX_FULLSCREEN 1: start in desktop-size fullscreen (F11 / Alt+Enter toggle it; the window is resizable and
//                       the back buffer follows its pixel size)
//   HULK_FPS_CAP       30 (default) | 60 | 0: the frame pacing the original gets from the vblank wait in
//                       d3dDisplay::SwapBuffers (0x31b190: flag 0x5554a0 clear = two vblanks per frame = 30 fps, as in
//                       gameplay; set = one = 60 fps, the front end). 30 = that (the game's flag picks 30 or 60), 60 =
//                       always 60, 0 = no pacing beyond the swap chain's vsync. Unset it is off for replays
//                       (HULK_INPUT_SOURCE) and the noop renderer; set explicitly it applies everywhere.
//   HULK_FPS_LOG        1: log the measured frame time (average, worst, fps) every 120 presents
//   HULK_GFX_SELFTEST   N: when the context is created, drive N frames of the self-test scene (selftest_scene.cpp:
//                       prim streams, a texture, prim buffers, the skinning extension and its vertex program, z /
//                       blend / stencil / cull / fog / colour-mask state, all through the slots the engine uses)
//                       and check the HULK_GFX_SHOT screenshot against the scene's probes ("pddi: self-test probes
//                       N of M"), then go on with the game: independent of how far the game gets
//   HULK_GFX_SELFTEST_PAGE  which page of the scene (default 0: G3's draw path; 1 G2's combiners, 2 the same through
//                       the generic combiner, 3 2D / linear textures / movie tile / state, 4 every combiner key
//                       against a CPU reference; G4: 5 refraction, 6 colour correction + visibility test, 7 bloom,
//                       8 the overlay; G5: 9 window scaling, with HULK_GFX_WINDOW, 10 two-sided lighting); one
//                       screenshot per run
//                       under Wine's winevulkan, so one page per run
#include "bgfx_pddi.h"

#if HULK_PDDI_GAME && defined(_WIN32)

#include <bgfx/bgfx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../platform_events.h"

extern "C" void __cdecl hulk_native_log(const char* line);      // src/platform/sdl/xdk/startup.cpp: the trace

namespace hulk {
namespace pddi {

static void traceSink(const char* line)
{
    hulk_native_log(line);
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
        const SelfTestProbe* probes;
        int n = selfTestProbes(&probes);
        if (n) {
            int ok = selfTestCheck(px, w, h, pitch, bgra, yflip, traceSink);
            logf("pddi: self-test probes %d of %d -> %s\n", ok, n, ok == n ? "PASS" : "FAIL");
        }
    }
};

static Callback s_callback;
static void* s_window;
static bgfxDisplay* s_display;
static unsigned s_shots[16], s_shotCount, s_drawlogLast, s_exitAfter;
// native16: HULK_GFX_SHOT_GAME=<game frame>,...: screenshots by GameClock frame (the replay checkpoints' numbering), at
// the first present after that frame's update, as game-<frame>.tga
static unsigned s_gameShots[64], s_gameShotCount;
extern "C" unsigned int hulk_native_frame_no;   // src/platform/sdl/xdk/startup.cpp (counted by replay_hooks.cpp)
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

static void readSize(const char* name, unsigned* w, unsigned* h)
{
    const char* s = getenv(name);
    unsigned a, b;
    if (s && sscanf(s, "%ux%u", &a, &b) == 2 && a >= 64 && b >= 64 && a <= 8192 && b <= 8192) {
        *w = a;
        *h = b;
    }
}

static void readOptions(unsigned* w, unsigned* h)
{
    readSize("HULK_GFX_SIZE", w, h);
    const char* s;
    s = getenv("HULK_GFX_SHOT");
    while (s && *s && s_shotCount < 16) {
        s_shots[s_shotCount++] = (unsigned)strtoul(s, (char**)&s, 10);
        if (*s != ',')
            break;
        s++;
    }
    s = getenv("HULK_GFX_SHOT_GAME");
    while (s && *s && s_gameShotCount < 64) {
        s_gameShots[s_gameShotCount++] = (unsigned)strtoul(s, (char**)&s, 10);
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

// the window's pixel size changed (resize, fullscreen): the back buffer follows
static void onResize(int w, int h, void*)
{
    if (s_display)
        s_display->hostResize((unsigned)w, (unsigned)h);
}

// display slot 4 on Windows: our SDL3 window, bgfx on it. Returns false if SDL or bgfx can't start.
bool platformDisplayInit(bgfxDisplay* d, unsigned width, unsigned height)
{
    readOptions(&width, &height);
    unsigned winW = width, winH = height;
    readSize("HULK_GFX_WINDOW", &winW, &winH);
    if (!hulk_platform_video_init()) {
        logf("pddi: SDL video init failed: %s\n", hulk_platform_error());
        return false;
    }
    const char* hidden = getenv("HULK_GFX_HIDDEN");
    s_window = hulk_platform_create_window("The Incredible Hulk: Ultimate Destruction (native)", (int)winW, (int)winH,
                                           hidden && *hidden == '1', 1);
    if (!s_window) {
        logf("pddi: SDL window failed: %s\n", hulk_platform_error());
        return false;
    }
    void *nwh, *ndt;
    int wayland;
    if (!hulk_platform_native_handles(s_window, &nwh, &ndt, &wayland)) {
        logf("pddi: the SDL window has no native handle\n");
        return false;
    }
    s_display = d;
    d->m_nativeType = wayland;
    hulk_platform_set_resize_handler(onResize, 0);
    const char* fs = getenv("HULK_GFX_FULLSCREEN");
    if (fs && *fs == '1')
        hulk_platform_toggle_fullscreen();
    platformPump();
    if (!d->hostInit(nwh, ndt, width, height, rendererFromEnv(), &s_callback))
        return false;
    if (winW != width || winH != height)
        d->hostResize(winW, winH);           // the frame keeps the mode's size; the window gets it scaled
    return true;
}

// the one event pump (platform_events.h): window close ends the process as the old window's WM_CLOSE did
void platformPump()
{
    hulk_platform_pump();
    if (hulk_platform_quit_requested()) {
        logf("pddi: window closed\n");
        ExitProcess(0);
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

// game globals the platform layer reads (the linked image binds them)
extern "C" unsigned char DAT_005554a0[4];       // SwapBuffers' vsync flag
extern "C" float DAT_004de600, DAT_004de604;    // the HUD layout frame (width, height)

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
    for (unsigned i = 0; i < s_gameShotCount; i++)
        if (s_gameShots[i] && hulk_native_frame_no >= s_gameShots[i]) {
            char path[300];
            _snprintf(path, sizeof(path) - 1, "%s\\game-%u.tga", s_shotDir, s_gameShots[i]);
            path[sizeof(path) - 1] = 0;
            logf("pddi: game frame %u (present %u): screenshot requested\n", hulk_native_frame_no, frame);
            bgfx::requestScreenShot(BGFX_INVALID_HANDLE, path);
            s_gameShots[i] = 0;
        }
}

// after frame `frame` was presented
void platformAfterFrame(unsigned frame)
{
    platformPump();
    if (frame < 3 || (frame & (frame - 1)) == 0)
        logf("pddi: frame %u presented (%u draws)\n", frame, drawCount());
    if (getenv("HULK_HUD_LOG")) {
        static float lw = -1, lh = -1;
        if (DAT_004de600 != lw || DAT_004de604 != lh) {
            lw = DAT_004de600;
            lh = DAT_004de604;
            logf("pddi: hud layout %f x %f at present %u (game frame %u)\n", (double)lw, (double)lh, frame, hulk_native_frame_no);
        }
    }
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

// HULK_FPS_CAP (see the top): after the present, wait until one frame period has passed since the last deadline
// (sleep most of it, spin the rest). The period follows the game's SwapBuffers flag (0x5554a0) unless forced.
static long long qpcNow()
{
    LARGE_INTEGER c;
    QueryPerformanceCounter(&c);
    return c.QuadPart;
}
void platformFramePace()
{
    static int mode = -1;              // 0 no pacing, 30 the game's flag decides, 60 always one vblank
    static long long freq, deadline, lastNow, worst, sum;
    static unsigned count, logEvery;
    if (mode < 0) {
        LARGE_INTEGER f;
        QueryPerformanceFrequency(&f);
        freq = f.QuadPart ? f.QuadPart : 1;
        const char* e = getenv("HULK_FPS_CAP");
        if (e && *e) {
            mode = atoi(e) == 60 ? 60 : atoi(e) == 30 ? 30 : 0;
        } else {
            const char* r = getenv("HULK_INPUT_SOURCE");
            const char* g = getenv("HULK_GFX_RENDERER");
            mode = (r && !strncmp(r, "replay:", 7)) || (g && !strcmp(g, "noop")) ? 0 : 30;
        }
        const char* l = getenv("HULK_FPS_LOG");
        logEvery = l && *l == '1' ? 120 : 0;
        logf("pddi: frame pacing %s\n", mode == 0 ? "off" : mode == 60 ? "60 fps" : "30 fps in gameplay, 60 in the front end (the game's flag)");
    }
    long long now = qpcNow();
    if (mode) {
        long long period = freq / ((mode == 60 || DAT_005554a0[0]) ? 60 : 30);
        if (!deadline || now > deadline + period * 2)
            deadline = now;                         // first frame, or we fell behind (a load): don't catch up
        deadline += period;
        while ((now = qpcNow()) < deadline) {
            long long ms = (deadline - now) * 1000 / freq;
            if (ms > 2)
                Sleep((DWORD)(ms - 1));
            else
                YieldProcessor();
        }
    }
    if (logEvery) {
        if (lastNow) {
            long long dt = now - lastNow;
            sum += dt;
            if (dt > worst)
                worst = dt;
            if (++count == logEvery) {
                long long avgUs = sum * 1000000 / count / freq, worstUs = worst * 1000000 / freq;
                logf("pddi: frame time avg %d.%02d ms (%d.%d fps), worst %d.%02d ms over %u presents\n",
                     (int)(avgUs / 1000), (int)(avgUs % 1000 / 10), (int)(1000000 / avgUs),
                     (int)(10000000 / avgUs % 10), (int)(worstUs / 1000), (int)(worstUs % 1000 / 10), count);
                count = 0;
                sum = worst = 0;
            }
        }
        lastNow = now;
    }
}

// HULK_GFX_SELFTEST (see the top): the self-test scene, frame after frame, through the context's and display's slots
void platformSelfTest(bgfxContext* ctx, bgfxDisplay* display)
{
    const char* s = getenv("HULK_GFX_SELFTEST");
    int frames = s ? atoi(s) : 0;
    if (frames <= 0)
        return;
    const char* pg = getenv("HULK_GFX_SELFTEST_PAGE");
    int page = pg ? atoi(pg) : 0;
    if (page < 0 || page >= selfTestPages())
        page = 0;
    logf("pddi: self-test: %d frames of page %d\n", frames, page);
    int probes = 0;
    for (int f = 0; f < frames; f++) {
        ctx->vfunc_4();                                         // begin frame
        probes = selfTestScene(ctx, page);                      // clears, then every cell's draws
        ctx->vfunc_5();                                         // end frame
        display->vfunc_14();                                    // swap (screenshots of HULK_GFX_SHOT frames)
    }
    ctx->vfunc_99();                                            // the base's state reset again: the game's defaults
    logf("pddi: self-test done (%u draws, %d probes per frame)\n", drawCount(), probes);
}

} // namespace pddi
} // namespace hulk

#endif
