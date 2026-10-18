// Stand-ins for memory: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GlobalMemoryStatus(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("GlobalMemoryStatus");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_HeapCreate(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("HeapCreate");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_HeapFree(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("HeapFree");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_HeapSize(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("HeapSize");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_HeapAlloc(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("HeapAlloc");
    return 0;
}
