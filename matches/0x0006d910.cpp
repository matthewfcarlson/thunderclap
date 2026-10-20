// Same code shape as 0x000508c0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern int __cdecl FUN_00344e74(int, int, int, int, int);
extern int gTypeA_6d910;
extern int gTypeB;

template <> bool fight::TrackFactoryCasterTemplate<CGrappleAutoTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_6d910, (hulk_intptr)&gTypeB, 0) != 0;
}
