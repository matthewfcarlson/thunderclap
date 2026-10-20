#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int __cdecl FUN_0005a3f0(int);

void* hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_8(void* __p0, void* __p1) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1;

    return (void*)(FUN_0005a3f0(b));
}
