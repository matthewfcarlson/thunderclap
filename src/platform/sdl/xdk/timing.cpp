// Stand-ins for timing (xdk_shim.h counts and logs each call). Native builds only.
//
// The game assumes the Xbox's performance-counter frequency, 733,333,333 Hz, in places (docs/platform-boundary.md),
// so the stand-ins keep that frequency and scale the host's counter to it.
#include "imports.h"
#include "../crt/host_crt.h"

static const unsigned long long hulk_xbox_hz = 733333333ull;

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceCounter(hulk_u32 a0) {
    HULK_XDK_TRACE("QueryPerformanceCounter");
    unsigned long long c = 0, f = 1;
    hulk_host_QueryPerformanceCounter(&c);
    hulk_host_QueryPerformanceFrequency(&f);
    if (!f)
        f = 1;
    // c * 733333333 / f without overflowing 64 bits for a long uptime
    unsigned long long whole = c / f, part = c % f;
    unsigned long long v = whole * hulk_xbox_hz + part * hulk_xbox_hz / f;
    if (a0)
        *(unsigned long long*)a0 = v;
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceFrequency(hulk_u32 a0) {
    HULK_XDK_TRACE("QueryPerformanceFrequency");
    if (a0)
        *(unsigned long long*)a0 = hulk_xbox_hz;
    return 1;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetLocalTime(hulk_u32 a0) {
    HULK_XDK_TRACE("GetLocalTime");
    if (a0)
        hulk_host_GetLocalTime((void*)a0);  // SYSTEMTIME: the same public layout on both
    return 0;
}
