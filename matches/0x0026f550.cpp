#include "compat/ptr.h"
#include "gen/core.h"

// CloseHandle (the XDK row 0x0020bbc2); the find handle is pointer-sized on the 64-bit builds
extern "C" int __stdcall FUN_0020bbc2(hulk_uintptr);
int core::XboxDrive::vfunc_20(hulk_intptr __p0) { hulk_uintptr * p = (hulk_uintptr *)__p0;

    FUN_0020bbc2(*p);
    *p = (hulk_uintptr)-1;
    return (int)(1);
}
