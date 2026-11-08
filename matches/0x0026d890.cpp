#include "compat/ptr.h"
// WaitForSingleObject (the XDK row 0x0020c6f7) on the semaphore 0x0026d860 created
extern "C" unsigned int __stdcall FUN_0020c6f7(hulk_uintptr, int);
extern "C" void __cdecl FUN_0026d890(hulk_uintptr* p) {
    FUN_0020c6f7(*p, -1);
}
