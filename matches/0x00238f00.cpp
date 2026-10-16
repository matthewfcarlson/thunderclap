// Same code shape as 0x000508c0 (propagated; names are from that function)
#include "gen/fight.h"

extern int __cdecl FUN_00344e74(int, int, int, int, int);
extern int gTypeA_238f00;
extern int gTypeB;

template <> bool fight::TrackFactoryCasterTemplate<fight::PrintTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((int)p, 0, (int)&gTypeA_238f00, (int)&gTypeB, 0) != 0;
}
