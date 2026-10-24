// The Win32 host functions of src/platform/sdl/crt/host_crt.h, implemented on POSIX (macOS, Linux) for the native
// builds (docs/native-mac.md "Host side"): threads, semaphores, events, critical sections, fibers, files, time and
// the last-error code. The XDK shims (src/platform/sdl/xdk/) call these under the same `hulk_host_<name>` names
// they use on Windows / Wine, where the functions come from kernel32 instead.
//
// Compiled for the host (the native builds' host side: plain C++ on the host's own ABI, with system headers); every
// function has C linkage, so the game side (MS C++ ABI, docs/native-mac.md) calls it directly. Not linked into any
// image yet.
//
// Handles are pointers to our own objects (HulkHostObject); INVALID_HANDLE_VALUE is (void*)-1 as on Windows. Waits:
// WaitForSingleObject on a thread (until it exits), a semaphore or an event. Wait results and error codes are the
// Win32 values the shims and the game's callers test.
#ifndef HULK_PLATFORM_SDL_HOST_WIN32_POSIX_H
#define HULK_PLATFORM_SDL_HOST_WIN32_POSIX_H

#include "../crt/host_crt.h"

extern "C" {
// Events (beyond host_crt.h's table: the Xbox kernel's events, for the shims that need them)
void* hulk_host_CreateEventA(void* sa, int manual_reset, int initial, const char* name);
int hulk_host_SetEvent(void* event);
int hulk_host_ResetEvent(void* event);
// Fibers: the data ConvertThreadToFiber / CreateFiber were given, and the running fiber
void* hulk_host_GetFiberData(void);
void* hulk_host_GetCurrentFiber(void);
void HULK_HOST_STDCALL hulk_host_DeleteCriticalSection(void* cs);
// Win32 constants the callers use
enum {
    HULK_WAIT_OBJECT_0 = 0,
    HULK_WAIT_TIMEOUT = 0x102,
    HULK_WAIT_FAILED = 0xffffffffu,
    HULK_INFINITE = 0xffffffffu,
    HULK_CREATE_SUSPENDED = 4,
    HULK_GENERIC_READ = 0x80000000u,
    HULK_GENERIC_WRITE = 0x40000000u,
    HULK_CREATE_NEW = 1,
    HULK_CREATE_ALWAYS = 2,
    HULK_OPEN_EXISTING = 3,
    HULK_OPEN_ALWAYS = 4,
    HULK_TRUNCATE_EXISTING = 5,
    HULK_FILE_BEGIN = 0,
    HULK_FILE_CURRENT = 1,
    HULK_FILE_END = 2,
    HULK_FILE_ATTRIBUTE_DIRECTORY = 0x10,
    HULK_FILE_ATTRIBUTE_NORMAL = 0x80,
    HULK_INVALID_FILE_ATTRIBUTES = 0xffffffffu,
    HULK_INVALID_SET_FILE_POINTER = 0xffffffffu,
    HULK_ERROR_FILE_NOT_FOUND = 2,
    HULK_ERROR_PATH_NOT_FOUND = 3,
    HULK_ERROR_ACCESS_DENIED = 5,
    HULK_ERROR_INVALID_HANDLE = 6,
    HULK_ERROR_NOT_ENOUGH_MEMORY = 8,
    HULK_ERROR_FILE_EXISTS = 80,
    HULK_ERROR_INVALID_PARAMETER = 87,
    HULK_ERROR_DISK_FULL = 112,
    HULK_ERROR_TOO_MANY_POSTS = 298,
    HULK_ERROR_ALREADY_EXISTS = 183,
    HULK_ERROR_NEGATIVE_SEEK = 131,
    HULK_ERROR_NOT_SUPPORTED = 50,
};
}
#define HULK_INVALID_HANDLE_VALUE ((void*)~(__UINTPTR_TYPE__)0)

#endif
