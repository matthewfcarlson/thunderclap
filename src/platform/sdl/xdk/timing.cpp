// Stand-ins for timing: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceCounter(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("QueryPerformanceCounter");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_QueryPerformanceFrequency(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("QueryPerformanceFrequency");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetLocalTime(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("GetLocalTime");
    return 0;
}
