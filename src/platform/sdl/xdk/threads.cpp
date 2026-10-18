// Stand-ins for threads / sync / fibers (xdk_shim.h counts and logs each call). XAPI's thread, semaphore, wait and
// fiber functions have the Win32 shapes (public documentation), so on Windows / Wine each forwards to the host's
// kernel32 function of the same name (src/platform/sdl/crt/host_crt.h): handles are host handles, the game's thread
// and fiber routines are called by the host (both `__stdcall` with one pointer argument, as on the Xbox). An SDL3
// backend (SDL_Thread, SDL_Semaphore, a ucontext/asm fiber switch) replaces this file on other hosts. Native builds
// only: tools/native_link.py compiles and links this directory.
#include "imports.h"
#include "../crt/host_crt.h"

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SetThreadPriority(hulk_u32 thread, hulk_u32 priority) {
    HULK_XDK_TRACE("SetThreadPriority");
    // (Xbox priorities are Win32's: -15..15 with THREAD_PRIORITY_TIME_CRITICAL 15; the host accepts the same values)
    return (hulk_u32)hulk_host_SetThreadPriority((void*)thread, (int)priority);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ResumeThread(hulk_u32 thread) {
    HULK_XDK_TRACE("ResumeThread");
    return hulk_host_ResumeThread((void*)thread);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ExitThread(hulk_u32 code) {
    HULK_XDK_TRACE("ExitThread");
    hulk_host_ExitThread(code);
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateThread(hulk_u32 sa, hulk_u32 stack, hulk_u32 start, hulk_u32 param,
                                                      hulk_u32 flags, hulk_u32 tid) {
    HULK_XDK_TRACE("CreateThread");
    (void)sa;
    // (flags: CREATE_SUSPENDED 4 is the one the game uses; the Xbox's own stack sizes are small, the host's default
    // is used when the game asks for less than 64 KB)
    return (hulk_u32)hulk_host_CreateThread(0, stack < 0x10000 ? 0 : stack, (void*)start, (void*)param, flags & 4,
                                            (hulk_u32*)tid);
}

extern "C" hulk_u32 HULK_CDECL hulk_xdk_GetCurrentThreadId(void) {
    HULK_XDK_TRACE("GetCurrentThreadId");
    return hulk_host_GetCurrentThreadId();
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateSemaphoreA(hulk_u32 sa, hulk_u32 initial, hulk_u32 maximum, hulk_u32 name) {
    HULK_XDK_TRACE("CreateSemaphoreA");
    (void)sa;
    (void)name;  // (named semaphores are process-local on the Xbox: unnamed here)
    return (hulk_u32)hulk_host_CreateSemaphoreA(0, (int)initial, (int)maximum, 0);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ReleaseSemaphore(hulk_u32 sem, hulk_u32 count, hulk_u32 previous) {
    HULK_XDK_TRACE("ReleaseSemaphore");
    return (hulk_u32)hulk_host_ReleaseSemaphore((void*)sem, (int)count, (int*)previous);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_WaitForSingleObject(hulk_u32 handle, hulk_u32 ms) {
    HULK_XDK_TRACE("WaitForSingleObject");
    return hulk_host_WaitForSingleObject((void*)handle, ms);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_Sleep(hulk_u32 ms) {
    HULK_XDK_TRACE("Sleep");
    hulk_host_Sleep(ms);
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_CreateFiber(hulk_u32 stack, hulk_u32 start, hulk_u32 param) {
    HULK_XDK_TRACE("CreateFiber");
    // (a clang-compiled fiber needs more stack than the Xbox original's frame sizes: at least 256 KB)
    return (hulk_u32)hulk_host_CreateFiber(stack < 0x40000 ? 0x40000 : stack, (void*)start, (void*)param);
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_DeleteFiber(hulk_u32 fiber) {
    HULK_XDK_TRACE("DeleteFiber");
    hulk_host_DeleteFiber((void*)fiber);
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_SwitchToFiber(hulk_u32 fiber) {
    HULK_XDK_TRACE("SwitchToFiber");
    hulk_host_SwitchToFiber((void*)fiber);
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_ConvertThreadToFiber(hulk_u32 param) {
    HULK_XDK_TRACE("ConvertThreadToFiber");
    return (hulk_u32)hulk_host_ConvertThreadToFiber((void*)param);
}
