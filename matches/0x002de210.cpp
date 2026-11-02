// Same code shape as 0x00267230 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

typedef unsigned int u32_2de210;
extern "C" void __cdecl FUN_002de030(void *, void *);

void pure3d::DXTNHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { u32_2de210 a = (u32_2de210)__p0; u32_2de210 b = (u32_2de210)__p1;

    FUN_002de030((void *)(hulk_uintptr)(unsigned int)a, (void *)(hulk_uintptr)(unsigned int)b);
}
