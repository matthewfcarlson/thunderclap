// Stub logging, pddiObject's slots, the device entry point and the native draw log.
#include "bgfx_pddi.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#if defined(_WIN32)
#define HULK_VSNPRINTF _vsnprintf
#else
#define HULK_VSNPRINTF vsnprintf
#endif

namespace hulk {
namespace pddi {

static const char* const kClassNames[kClassCount] = {
    "bgfxDevice", "bgfxDisplay", "bgfxContext", "bgfxTexture", "bgfxPrimBuffer", "bgfxPrimBufferStream",
    "bgfxPrimStream", "bgfxShader", "bgfxExtAntialiasControl", "bgfxExtFrameBufferTexture",
    "bgfxExtFramebufferEffects", "bgfxExtGammaControl", "bgfxExtGlobalProjectedTexture", "bgfxExtHardwareSkinning",
    "bgfxExtReadPixels", "bgfxExtVertexProgram", "bgfxExtVisibilityTest",
};

enum { kMaxSlots = 128 };
static unsigned s_calls[kClassCount][kMaxSlots];

static void defaultSink(const char* line)
{
#if HULK_PDDI_HOST
    fputs(line, stderr);
#else
    (void)line;     // the native image sets a sink (the platform's log) with setLogSink
#endif
}

static LogSink s_sink = defaultSink;

void setLogSink(LogSink sink)
{
    s_sink = sink ? sink : defaultSink;
}

void logf(const char* fmt, ...)
{
    char buf[512];
    va_list ap;
    va_start(ap, fmt);
    HULK_VSNPRINTF(buf, sizeof(buf) - 1, fmt, ap);
    va_end(ap);
    buf[sizeof(buf) - 1] = 0;
    s_sink(buf);
}

void stubHit(int cls, int slot, const char* fn)
{
    if (cls < 0 || cls >= kClassCount || slot < 0 || slot >= kMaxSlots)
        return;
    if (s_calls[cls][slot]++ == 0)
        logf("pddi: %s slot %d (%s) is a stub\n", kClassNames[cls], slot, fn);
}

unsigned stubCalls(int cls, int slot)
{
    return (cls >= 0 && cls < kClassCount && slot >= 0 && slot < kMaxSlots) ? s_calls[cls][slot] : 0;
}

void stubReport()
{
    for (int c = 0; c < kClassCount; c++)
        for (int s = 0; s < kMaxSlots; s++)
            if (s_calls[c][s])
                logf("pddi: stub %s slot %d: %u calls\n", kClassNames[c], s, s_calls[c][s]);
}

// ---------------------------------------------------------------------------------------------
// pddiObject
void bgfxObject::vfunc_0()
{
    ++m_refCount;
}

void bgfxObject::vfunc_1()
{
    if (--m_refCount < 1)
        delete this;
}

int bgfxObject::vfunc_2()
{
    return *(int*)((char*)this + 8);
}

bgfxObject::~bgfxObject() {}

// ---------------------------------------------------------------------------------------------
// The native draw log (the same records as the hybrid build's; tools/drawlog_diff.py compares them)
enum { kDrawRing = 8192 };
static DrawRecord s_ring[kDrawRing];
static uint32_t s_count, s_first, s_every, s_last;

void drawlogEnable(uint32_t firstFrame, uint32_t every, uint32_t lastFrame)
{
    s_first = firstFrame;
    s_every = every;
    s_last = lastFrame;
    s_count = 0;
}

bool drawlogWants(uint32_t frame)
{
    return s_every && frame >= s_first && frame <= s_last && (frame - s_first) % s_every == 0;
}

void drawlogAppend(const DrawRecord& r)
{
    s_ring[s_count % kDrawRing] = r;
    s_count++;
}

uint32_t drawlogCount()
{
    return s_count < kDrawRing ? s_count : kDrawRing;
}

const DrawRecord* drawlogAt(uint32_t i)
{
    uint32_t n = drawlogCount();
    if (i >= n)
        return 0;
    return &s_ring[(s_count - n + i) % kDrawRing];
}

// texture -> first-seen ordinal, given out at the first logged draw that uses it (hybrid/hooks.cpp dl_tex)
enum { kTexSlots = 4096 };
static const void* s_texKey[kTexSlots];
static uint32_t s_texVal[kTexSlots], s_texCount;

uint32_t drawlogTexture(const void* t)
{
    if (!t)
        return 0;
    uint32_t h = (uint32_t)(((uintptr_t)t >> 4) % kTexSlots);
    for (uint32_t i = 0; i < kTexSlots; i++, h = (h + 1) % kTexSlots) {
        if (s_texKey[h] == t)
            return s_texVal[h];
        if (!s_texKey[h]) {
            s_texKey[h] = t;
            s_texVal[h] = ++s_texCount;
            return s_texCount;
        }
    }
    return 0xffffffffu;
}

static unsigned s_draws;
unsigned drawCount() { return s_draws; }
void countDraw() { s_draws++; }

bool drawlogDump(const char* path)
{
    FILE* f = fopen(path, "wb");
    if (!f)
        return false;
    uint32_t hdr[2] = {0x314c4450u /* 'PDL1' */, drawlogCount()};
    fwrite(hdr, sizeof(hdr), 1, f);
    for (uint32_t i = 0; i < hdr[1]; i++)
        fwrite(drawlogAt(i), sizeof(DrawRecord), 1, f);
    fclose(f);
    return true;
}

} // namespace pddi
} // namespace hulk

#if HULK_PDDI_GAME && defined(_WIN32)
extern "C" void hulk_pddi_run_initializers(void);     // win32_glue.cpp
#endif

// d3dCreateDevice (0x31ba60): only version 0x12/0xb; one device for the process. Returns 1, or 100 (and null).
extern "C" int hulk_pddi_create_device(int major, int minor, void** out)
{
    static hulk::pddi::bgfxDevice* s_device;
#if HULK_PDDI_GAME && defined(_WIN32)
    hulk_pddi_run_initializers();                       // bx/bgfx's static initializers (once)
    hulk::pddi::platformInit();
    hulk::pddi::logf("pddi: create device %d.%d (bgfx backend)\n", major, minor);
#endif
    if (major == 0x12 && minor == 0xb) {
        if (!s_device)
            s_device = new hulk::pddi::bgfxDevice();
        *out = s_device;
        return 1;
    }
    *out = 0;
    return 100;
}
