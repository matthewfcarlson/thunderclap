// Stand-ins for graphics: XGraphics: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_uptr HULK_STDCALL hulk_xdk_XGBuffer_GetBufferPointer(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("XGBuffer_GetBufferPointer");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGBuffer_Release(hulk_uptr a0) {
    (void)a0;
    HULK_XDK_TRACE("XGBuffer_Release");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGAssembleShader(hulk_uptr a0, hulk_uptr a1, hulk_u32 a2, hulk_u32 a3, hulk_uptr a4, hulk_uptr a5, hulk_uptr a6, hulk_uptr a7, hulk_uptr a8, hulk_uptr a9, hulk_uptr a10) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7; (void)a8; (void)a9; (void)a10;
    HULK_XDK_TRACE("XGAssembleShader");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGIsSwizzledFormat(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XGIsSwizzledFormat");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGSwizzleRect(hulk_uptr a0, hulk_u32 a1, hulk_uptr a2, hulk_uptr a3, hulk_u32 a4, hulk_u32 a5, hulk_uptr a6, hulk_u32 a7) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7;
    HULK_XDK_TRACE("XGSwizzleRect");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGSwizzleBox(hulk_uptr a0, hulk_u32 a1, hulk_u32 a2, hulk_uptr a3, hulk_uptr a4, hulk_u32 a5, hulk_u32 a6, hulk_u32 a7, hulk_uptr a8, hulk_u32 a9) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6; (void)a7; (void)a8; (void)a9;
    HULK_XDK_TRACE("XGSwizzleBox");
    return 0;
}
