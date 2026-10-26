// Same code shape as 0x00267230 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

typedef unsigned int u32_2de210;
void __cdecl AllocHelper(u32_2de210, u32_2de210);

void pure3d::DXTNHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { u32_2de210 a = (u32_2de210)__p0; u32_2de210 b = (u32_2de210)__p1;

    AllocHelper(a, b);
}
