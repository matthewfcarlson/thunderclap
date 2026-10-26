#include "compat/ptr.h"
#include "gen/global.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_5dd70 {
    int FUN_0001cfd0(CHitAnimationTrack*, int);
};

hulk_intptr CHitAnimationTrack::vfunc_12(hulk_intptr param) {
    Helper_5dd70* p = (Helper_5dd70*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001cfd0(this, param);
    return 0;
}
