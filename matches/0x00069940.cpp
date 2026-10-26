// Same code shape as 0x0005dd70 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_69940 {
    int FUN_0001cfd0(CMoveTrack*, int);
};

hulk_intptr CMoveTrack::vfunc_12(hulk_intptr param) {
    Helper_69940* p = (Helper_69940*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001cfd0(this, param);
    return 0;
}
