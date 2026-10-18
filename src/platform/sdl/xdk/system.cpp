// Stand-ins for process / system settings: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XLaunchNewImageA(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XLaunchNewImageA");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetLaunchInfo(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XGetLaunchInfo");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_XGetLanguage(void) {
    HULK_XDK_TRACE("XGetLanguage");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetLastError(void) {
    HULK_XDK_TRACE("GetLastError");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_XGetAudioFlags(void) {
    HULK_XDK_TRACE("XGetAudioFlags");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_XGetVideoFlags(void) {
    HULK_XDK_TRACE("XGetVideoFlags");
    return 0;
}
