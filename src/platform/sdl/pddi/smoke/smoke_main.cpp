// The pddi skeleton's smoke test (host macOS build, outside the game): an SDL3 window, bgfx through bgfxDisplay,
// and per frame the context API as the engine drives it: begin frame (slot 4), clear (12), begin prims (30), three
// vertices written through the prim stream's pointers, end prims (31), end frame (5), swap (display slot 14). Takes a
// screenshot near the end and checks two pixels: the clear colour in a corner, the triangle's colour in the middle.
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

static const unsigned kClear = 0xff203040u;         // D3DCOLOR: dark blue-grey
static const unsigned kTriangle = 0xffff8000u;      // D3DCOLOR: orange

struct Shot : bgfx::CallbackI {
    bool done = false, ok = false;
    unsigned corner[3] = {0, 0, 0}, centre[3] = {0, 0, 0};
    void fatal(const char* f, uint16_t l, bgfx::Fatal::Enum c, const char* s) override
    {
        fprintf(stderr, "bgfx fatal %s:%u %d %s\n", f, l, (int)c, s);
        abort();
    }
    void traceVargs(const char*, uint16_t, const char*, va_list) override {}
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
        auto at = [&](uint32_t x, uint32_t y, unsigned* rgb) {
            uint32_t row = yflip ? h - 1 - y : y;
            const unsigned char* p = px + row * pitch + x * 4;
            rgb[0] = bgra ? p[2] : p[0];
            rgb[1] = p[1];
            rgb[2] = bgra ? p[0] : p[2];
        };
        at(4, 4, corner);
        at(w / 2, h / 2, centre);
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

static bool near(const unsigned* rgb, unsigned d3dcolour)
{
    int want[3] = {(int)(d3dcolour >> 16) & 255, (int)(d3dcolour >> 8) & 255, (int)d3dcolour & 255};
    for (int i = 0; i < 3; i++)
        if (abs((int)rgb[i] - want[i]) > 2)
            return false;
    return true;
}

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
    ctx->hostSetClear(kClear, 1.0f, 0);
    drawlogEnable(0, 1, 0xffffffffu);

    static const float tri[3][3] = {{-0.5f, -0.5f, 0.5f}, {0.5f, -0.5f, 0.5f}, {0.0f, 0.5f, 0.5f}};
    for (int f = 0; f < frames; f++) {
        SDL_Event e;
        while (SDL_PollEvent(&e))
            if (e.type == SDL_EVENT_QUIT)
                f = frames;
        ctx->vfunc_4();                                   // begin frame
        ctx->vfunc_12(1 | 2);                             // clear colour + depth
        bgfxPrimStream* s = (bgfxPrimStream*)ctx->vfunc_30(0, kPrimTriList, kVertexColour, 3, 0);
        for (int v = 0; v < 3; v++) {                     // as the engine's inline prim-stream writes do
            memcpy(s->posPtr, tri[v], 12);
            *(unsigned*)s->colorPtr = kTriangle;
            s->vertex();
        }
        ctx->vfunc_31(s);                                 // end prims: the draw
        ctx->vfunc_5();                                   // end frame
        if (f == frames - 4)
            bgfx::requestScreenShot(BGFX_INVALID_HANDLE, capture);
        display->vfunc_14();                              // swap
    }
    for (int i = 0; i < 4 && !shot.done; i++)
        display->vfunc_14();
    bool ok = shot.done && near(shot.corner, kClear) && near(shot.centre, kTriangle);
    printf("smoke: renderer %s, %d frames, %u draws logged, screenshot %s: corner %u,%u,%u centre %u,%u,%u -> %s\n",
           bgfx::getRendererName(bgfx::getRendererType()), frames, drawlogCount(), shot.done ? capture : "(none)",
           shot.corner[0], shot.corner[1], shot.corner[2], shot.centre[0], shot.centre[1], shot.centre[2],
           ok ? "PASS" : "FAIL");
    if (dl)
        drawlogDump(dl);
    stubReport();
    delete ctx;
    display->hostShutdown();
    SDL_DestroyWindow(win);
    SDL_Quit();
    return ok ? 0 : 1;
}
