// The pddi backend's smoke test (host macOS build, outside the game): an SDL3 window, bgfx through bgfxDisplay,
// and per frame the context API as the engine drives it: begin frame (slot 4), the self-test scene
// (selftest_scene.cpp: prim streams, a texture, prim buffers, the skinning extension and the "skin" vertex program,
// z / blend / stencil / cull / fog / colour-mask state through the context's slots), end frame (5), swap (display
// slot 14). Takes a screenshot near the end and checks every probe of the scene.
//
//   build/third_party/out/pddi-host/pddi_smoke [--frames 120] [--capture out.tga] [--drawlog out.pdl]
//                                               [--page N]      (one self-test page; default: every page, a
//                                                                screenshot each: out.tga, out-page1.tga, ...)
//   build/third_party/out/pddi-host/pddi_smoke --combiner-keys out.txt   (no window: every combiner key the shader
//                                                                classes make; tools/native_gfx.py combiners)
//   build/third_party/out/pddi-host/pddi_smoke --fx-params        (no window: the filter program's parameters per
//                                                                colour-pass level and side; tools/xps.py prove)
#include "bgfx_pddi.h"
#include "../../platform_events.h"

#include <SDL3/SDL.h>
#include <bgfx/bgfx.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace hulk::pddi;


static void printLine(const char* line) { fputs(line, stdout); }

static FILE* s_keys;
static void keyLine(const char* key, const char* example)
{
    uint32_t h = 2166136261u;
    for (const unsigned char* p = (const unsigned char*)key; *p; p++)
        h = (h ^ *p) * 16777619u;
    fprintf(s_keys, "%s\t%08x\t%s\n", key, h, example);
}

struct Shot : bgfx::CallbackI {
    bool done = false, ok = false;
    int probes = 0, passed = 0;
    void fatal(const char* f, uint16_t l, bgfx::Fatal::Enum c, const char* s) override
    {
        fprintf(stderr, "bgfx fatal %s:%u %d %s\n", f, l, (int)c, s);
        abort();
    }
    void traceVargs(const char*, uint16_t, const char* fmt, va_list ap) override
    {
        char buf[1024];
        vsnprintf(buf, sizeof(buf), fmt, ap);
        if (strstr(buf, "rror") || strstr(buf, "ailed") || getenv("PDDI_SMOKE_TRACE"))   // errors only by default
            fprintf(stderr, "bgfx: %s", buf);
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
    void screenShot(const char* path, uint32_t w, uint32_t h, uint32_t pitch, bgfx::TextureFormat::Enum fmt,
                    const void* data, uint32_t, bool yflip) override
    {
        const unsigned char* px = (const unsigned char*)data;
        bool bgra = fmt != bgfx::TextureFormat::RGBA8;
        const SelfTestProbe* p;
        probes = selfTestProbes(&p);
        passed = selfTestCheck(px, w, h, pitch, bgra, yflip, printLine);
        // TGA, 32-bit BGRA, top-left origin
        FILE* f = fopen(path, "wb");
        if (f) {
            unsigned char hdr[18] = {0, 0, 2};
            hdr[12] = w & 255; hdr[13] = w >> 8; hdr[14] = h & 255; hdr[15] = h >> 8; hdr[16] = 32; hdr[17] = 0x28;
            fwrite(hdr, 18, 1, f);
            for (uint32_t y = 0; y < h; y++) {
                const unsigned char* p = px + (yflip ? h - 1 - y : y) * pitch;
                for (uint32_t x = 0; x < w; x++, p += 4) {
                    unsigned char q[4] = {bgra ? p[0] : p[2], p[1], bgra ? p[2] : p[0], p[3]};
                    fwrite(q, 4, 1, f);
                }
            }
            fclose(f);
        }
        done = true;
    }
};

int main(int argc, char** argv)
{
    int frames = 120;
    const char* capture = "pddi_smoke.tga";
    const char* dl = 0;
    const char* keys = 0;
    int onlyPage = -1;
    if (argc == 2 && !strcmp(argv[1], "--fx-params")) {
        for (int lv = 1; lv <= 64; lv *= 2)
            for (int side = 0; side < 2; side++) {
                float p[8];
                fxProgramParams(lv, side, p);
                printf("%d %d %g %g %g %g %g %g %g %g\n", lv, side, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
            }
        return 0;
    }
    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--frames"))
            frames = atoi(argv[i + 1]);
        else if (!strcmp(argv[i], "--capture"))
            capture = argv[i + 1];
        else if (!strcmp(argv[i], "--drawlog"))
            dl = argv[i + 1];
        else if (!strcmp(argv[i], "--combiner-keys"))
            keys = argv[i + 1];
        else if (!strcmp(argv[i], "--page"))
            onlyPage = atoi(argv[i + 1]);
    }
    if (keys) {
        void* dev = 0;
        if (hulk_pddi_create_device(0x12, 0xb, &dev) != 1)
            return 3;
        bgfxDevice* device = (bgfxDevice*)dev;
        bgfxDisplay* display = (bgfxDisplay*)device->vfunc_7(0);
        device->vfunc_5(display);
        bgfxContext* ctx = (bgfxContext*)device->vfunc_8(display);
        s_keys = fopen(keys, "w");
        if (!s_keys)
            return 2;
        int n = enumerateCombinerKeys(ctx, keyLine);
        fclose(s_keys);
        printf("combiner keys: %d -> %s\n", n, keys);
        return 0;
    }
    // the window and the event pump are platform_events.cpp's, as in the native image
    if (!hulk_platform_video_init()) {
        fprintf(stderr, "SDL video: %s\n", hulk_platform_error());
        return 2;
    }
    void* win = hulk_platform_create_window("pddi smoke", 640, 480, getenv("PDDI_SMOKE_HIDDEN") != 0, 0);
    if (!win) {
        fprintf(stderr, "SDL window: %s\n", hulk_platform_error());
        return 2;
    }
    void *nwh, *ndt;
    int wayland;
    if (!hulk_platform_native_handles(win, &nwh, &ndt, &wayland)) {
        fprintf(stderr, "SDL window: no native handle\n");
        return 2;
    }

    // what pure3d::InitPlatform does: the device, a display, the context
    void* dev = 0;
    if (hulk_pddi_create_device(0x12, 0xb, &dev) != 1)
        return 3;
    bgfxDevice* device = (bgfxDevice*)dev;
    bgfxDisplay* display = (bgfxDisplay*)device->vfunc_7(0);
    device->vfunc_5(display);
    display->m_nativeType = wayland;
    Shot shot;
    if (!display->hostInit(nwh, ndt, 640, 480, bgfx::RendererType::Count, &shot))
        return 4;
    bgfxContext* ctx = (bgfxContext*)device->vfunc_8(display);
    drawlogEnable(0, 1, 0xffffffffu);

    int pages = selfTestPages(), first = onlyPage >= 0 ? onlyPage : 0, last = onlyPage >= 0 ? onlyPage : pages - 1;
    int probes = 0, passed = 0, shots = 0, runs = 0;
    bool quit = false;
    auto runPage = [&](int page, const char* path, const char* label) {
        shot.done = false;
        shot.probes = shot.passed = 0;
        for (int f = 0; f < frames + 8 && !shot.done; f++) {
            hulk_platform_pump();
            quit = hulk_platform_quit_requested() != 0;
            if (quit)
                break;
            ctx->vfunc_4();                               // begin frame
            selfTestScene(ctx, page);                     // clears, then every cell's draws
            ctx->vfunc_5();                               // end frame
            if (f == frames - 4)
                bgfx::requestScreenShot(BGFX_INVALID_HANDLE, path);
            display->vfunc_14();                          // swap
        }
        bool ok = shot.done && shot.probes > 0 && shot.passed == shot.probes;
        printf("smoke: page %d%s: screenshot %s: %d of %d probes -> %s\n", page, label, shot.done ? path : "(none)",
               shot.passed, shot.probes, ok ? "PASS" : "FAIL");
        probes += shot.probes;
        passed += shot.passed;
        shots += shot.done;
        runs++;
    };
    for (int page = first; page <= last && !quit; page++) {
        char path[1024];
        const char* dot = strrchr(capture, '.');
        if (page == 0 || !dot)
            snprintf(path, sizeof(path), "%s", capture);
        else
            snprintf(path, sizeof(path), "%.*s-page%d%s", (int)(dot - capture), capture, page, dot);
        runPage(page, path, "");
    }
    // G5: page 9 again in resized windows: the 640x480 frame scaled into each with its aspect kept
    if (!quit && (onlyPage < 0 || onlyPage == 9)) {
        static const struct { int w, h, mode; const char* name; } kCases[3] = {
            {960, 540, 0, "linear"}, {900, 600, 2, "integer"}, {800, 800, 1, "nearest"}};
        for (int i = 0; i < 3 && !quit; i++) {
            SDL_SetWindowSize((SDL_Window*)win, kCases[i].w, kCases[i].h);
            SDL_SyncWindow((SDL_Window*)win);
            hulk_platform_pump();
            display->m_scaleMode = kCases[i].mode;
            display->hostResize((unsigned)kCases[i].w, (unsigned)kCases[i].h);
            char path[1024], label[64];
            const char* dot = strrchr(capture, '.');
            snprintf(path, sizeof(path), "%.*s-page9-%dx%d%s", dot ? (int)(dot - capture) : (int)strlen(capture),
                     capture, kCases[i].w, kCases[i].h, dot ? dot : ".tga");
            snprintf(label, sizeof(label), " (window %dx%d, %s)", kCases[i].w, kCases[i].h, kCases[i].name);
            runPage(9, path, label);
        }
    }
    bool ok = shots == runs && probes > 0 && passed == probes;
    printf("smoke: renderer %s, %d pages (%d shots), %u draws logged: %d of %d probes -> %s\n",
           bgfx::getRendererName(bgfx::getRendererType()), last - first + 1, runs, drawlogCount(), passed, probes,
           ok ? "PASS" : "FAIL");
    int gen, generic, draws[2];
    ctx->combinerStats(&gen, &generic, draws);
    printf("smoke: combiners: %d keys with a generated program, %d through the generic one; draws %d generated, "
           "%d generic\n", gen, generic, draws[0], draws[1]);
    if (dl)
        drawlogDump(dl);
    stubReport();
    delete ctx;
    display->hostShutdown();
    hulk_platform_video_quit();
    return ok ? 0 : 1;
}
