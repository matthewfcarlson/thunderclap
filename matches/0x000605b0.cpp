// Same code shape as 0x0005dd70 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_605b0 {
    int FUN_0001cfd0(CMotionTrailTrack*, hulk_intptr);
};

hulk_intptr CMotionTrailTrack::vfunc_12(hulk_intptr param) {
    Helper_605b0* p = (Helper_605b0*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001cfd0(this, param);
    return 0;
}
