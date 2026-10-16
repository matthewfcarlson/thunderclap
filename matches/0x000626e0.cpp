// Same code shape as 0x0005dd70 (propagated; names are from that function)
#include "gen/global.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_626e0 {
    int FUN_0001cfd0(CSmartPropSpawnTrack*, int);
};

int CSmartPropSpawnTrack::vfunc_12(int param) {
    Helper_626e0* p = (Helper_626e0*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_0001cfd0(this, param);
    return 0;
}
