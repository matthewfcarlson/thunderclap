// The pddi backend's smoke test (host macOS build, outside the game): an SDL3 window, bgfx through bgfxDisplay,
// and per frame the context API as the engine drives it: begin frame (slot 4), the self-test scene
// (selftest_scene.cpp: prim streams, a texture, prim buffers, the skinning extension and the "skin" vertex program,
// z / blend / stencil / cull / fog / colour-mask state through the context's slots), end frame (5), swap (display
// slot 14). Takes a screenshot near the end and checks every probe of the scene.
//
//   build/third_party/out/pddi-host/pddi_smoke [--frames 120] [--capture out.tga] [--drawlog out.pdl]
#include "bgfx_pddi.h"

#include <SDL3/SDL.h>
#include <bgfx/bgfx.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace hulk::pddi;


static void printLine(const char* line) { fputs(line, stdout); }

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
    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--frames"))
            frames = atoi(argv[i + 1]);
        else if (!strcmp(argv[i], "--capture"))
            capture = argv[i + 1];
        else if (!strcmp(argv[i], "--drawlog"))
            dl = argv[i + 1];
    }
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
        return 2;
    }
    SDL_Window* win = SDL_CreateWindow("pddi smoke (G0)", 640, 480, 0);
    if (!win) {
        fprintf(stderr, "SDL_CreateWindow: %s\n", SDL_GetError());
        return 2;
    }
    void* nwh = SDL_GetPointerProperty(SDL_GetWindowProperties(win), SDL_PROP_WINDOW_COCOA_WINDOW_POINTER, 0);

    // what pure3d::InitPlatform does: the device, a display, the context
    void* dev = 0;
    if (hulk_pddi_create_device(0x12, 0xb, &dev) != 1)
        return 3;
    bgfxDevice* device = (bgfxDevice*)dev;
    bgfxDisplay* display = (bgfxDisplay*)device->vfunc_7(0);
    device->vfunc_5(display);
    Shot shot;
    if (!display->hostInit(nwh, 0, 640, 480, bgfx::RendererType::Count, &shot))
        return 4;
    bgfxContext* ctx = (bgfxContext*)device->vfunc_8(display);
    drawlogEnable(0, 1, 0xffffffffu);

    for (int f = 0; f < frames; f++) {
        SDL_Event e;
        while (SDL_PollEvent(&e))
            if (e.type == SDL_EVENT_QUIT)
                f = frames;
        ctx->vfunc_4();                                   // begin frame
        selfTestScene(ctx);                               // clears, then every cell's draws
        ctx->vfunc_5();                                   // end frame
        if (f == frames - 4)
            bgfx::requestScreenShot(BGFX_INVALID_HANDLE, capture);
        display->vfunc_14();                              // swap
    }
    for (int i = 0; i < 4 && !shot.done; i++)
        display->vfunc_14();
    bool ok = shot.done && shot.probes > 0 && shot.passed == shot.probes;
    printf("smoke: renderer %s, %d frames, %u draws logged, screenshot %s: %d of %d probes -> %s\n",
           bgfx::getRendererName(bgfx::getRendererType()), frames, drawlogCount(), shot.done ? capture : "(none)",
           shot.passed, shot.probes, ok ? "PASS" : "FAIL");
    if (dl)
        drawlogDump(dl);
    stubReport();
    delete ctx;
    display->hostShutdown();
    SDL_DestroyWindow(win);
    SDL_Quit();
    return ok ? 0 : 1;
}
