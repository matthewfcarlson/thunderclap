#include "compat/ptr.h"
// ReleaseSemaphore (the XDK row 0x0020c380) on the semaphore 0x0026d860 created; its result is the caller's (the
// drive thread's queue 0x00272fc0 and the drives' requests return it)
extern "C" int __stdcall FUN_0020c380(hulk_uintptr, int, hulk_uintptr);
extern "C" int __cdecl FUN_0026d8a0(hulk_uintptr* handle) {
    return FUN_0020c380(*handle, 1, 0);
}
