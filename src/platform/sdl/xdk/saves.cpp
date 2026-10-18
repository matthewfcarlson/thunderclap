// Stand-ins for saves / storage: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_CDECL hulk_xdk_XFormatUtilityDrive(void) {
    HULK_XDK_TRACE("XFormatUtilityDrive");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XMUNameFromDriveLetter(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("XMUNameFromDriveLetter");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureBegin(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XCalculateSignatureBegin");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureUpdate(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("XCalculateSignatureUpdate");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCalculateSignatureEnd(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XCalculateSignatureEnd");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XCreateSaveGame(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("XCreateSaveGame");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XDeleteSaveGame_XFindFirstSaveGame(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XDeleteSaveGame_XFindFirstSaveGame");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindFirstSaveGame(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XFindFirstSaveGame");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindNextSaveGame(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XFindNextSaveGame");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XFindClose(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XFindClose");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XMountMUA(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("XMountMUA");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XUnmountMU(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("XUnmountMU");
    return 0;
}
