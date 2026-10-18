// Stand-ins for file I/O: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetDiskFreeSpaceExA(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("GetDiskFreeSpaceExA");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDiskSectorSizeA(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XGetDiskSectorSizeA");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CloseHandle(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("CloseHandle");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ReadFile(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
    HULK_XDK_TRACE("ReadFile");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_WriteFile(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
    HULK_XDK_TRACE("WriteFile");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetEndOfFile(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("SetEndOfFile");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetFilePointer(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("SetFilePointer");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_GetFileSize(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("GetFileSize");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateFileA(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5, hulk_u32 a6) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5; (void)a6;
    HULK_XDK_TRACE("CreateFileA");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XapiOpenDirectory(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("XapiOpenDirectory");
    return 0;
}
