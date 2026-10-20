#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0048f610[];
extern "C" char DAT_004ce8a4[];
typedef unsigned int u32_2a7e90;
extern void* const EntityRTTI_2a7e90;
extern void* const VisibilityNodeRTTI;
extern u32_2a7e90 __cdecl FindType(hulk_uintptr, int, void*, void*, int);

void pure3d::SceneGraphVisibilityAnimationController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    *(u32_2a7e90*)((char*)this + 0x44) = FindType(arg, 0, (void*)((hulk_intptr)DAT_0048f610), (void*)((hulk_intptr)DAT_004ce8a4), 0);
}
