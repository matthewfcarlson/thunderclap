#include "compat/ptr.h"
// CreateSemaphore (the XDK row 0x0020c2c9): the handle is pointer-sized on the 64-bit builds
extern "C" hulk_uintptr __stdcall FUN_0020c2c9(hulk_uintptr, int, int, hulk_uintptr);
extern "C" void __cdecl FUN_0026d860(hulk_uintptr* out, int value) {
    *out = FUN_0020c2c9(0, value, 32000, 0);
}
