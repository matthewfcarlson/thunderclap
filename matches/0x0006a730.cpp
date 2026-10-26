// Same code shape as 0x0005dd70 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_6a730 {
    int FUN_0001cfd0(COrientTrack*, int);
};

hulk_intptr COrientTrack::vfunc_12(hulk_intptr param) {
    Helper_6a730* p = (Helper_6a730*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001cfd0(this, param);
    return 0;
}
