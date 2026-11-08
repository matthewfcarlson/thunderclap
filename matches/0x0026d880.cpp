#include "compat/ptr.h"
// CloseHandle (the XDK row 0x0020bbc2) on the semaphore 0x0026d860 created
extern "C" int __stdcall FUN_0020bbc2(hulk_uintptr);
extern "C" void __cdecl FUN_0026d880(hulk_uintptr* handle) {
    FUN_0020bbc2(*handle);
}
