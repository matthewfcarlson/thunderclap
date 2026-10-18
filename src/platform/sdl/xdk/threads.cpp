// Stand-ins for threads / sync / fibers: each counts and logs its calls (xdk_shim.h) and returns 0 (a null handle,
// FALSE, S_OK / ERROR_SUCCESS: out-parameters are left as they are). First written by
// tools/native_shim.py --skeleton; real implementations replace these one by one (docs/native-build.md
// "Platform shim"). Native builds only: tools/native_link.py compiles and links this directory.
#include "imports.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetThreadPriority(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("SetThreadPriority");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ResumeThread(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("ResumeThread");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ExitThread(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("ExitThread");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateThread(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3, hulk_u32 a4, hulk_u32 a5) {
    (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; (void)a5;
    HULK_XDK_TRACE("CreateThread");
    return 0;
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_GetCurrentThreadId(void) {
    HULK_XDK_TRACE("GetCurrentThreadId");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateSemaphoreA(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3;
    HULK_XDK_TRACE("CreateSemaphoreA");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ReleaseSemaphore(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("ReleaseSemaphore");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_WaitForSingleObject(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1;
    HULK_XDK_TRACE("WaitForSingleObject");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Sleep(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("Sleep");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateFiber(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2;
    HULK_XDK_TRACE("CreateFiber");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_DeleteFiber(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("DeleteFiber");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SwitchToFiber(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("SwitchToFiber");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ConvertThreadToFiber(hulk_u32 a0) {
    (void)a0;
    HULK_XDK_TRACE("ConvertThreadToFiber");
    return 0;
}
