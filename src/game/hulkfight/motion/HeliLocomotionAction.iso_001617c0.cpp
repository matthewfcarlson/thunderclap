// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015cd10..0x00161c10 (kind game, layer game, confidence high), dominant class hulkfight::motion::HeliLocomotionAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001617c0 hulkfight::motion::LocomotingTrack::vfunc_10 (64 B): matches/0x001617c0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_10@LocomotingTrack@motion@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct LocomotingAction_nv_1617c0 {
    int Make_001606d0(void*);
};
extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern hulkfight::motion::LocomotingAction* __cdecl FUN_0008d690(unsigned int);

hulk_intptr hulkfight::motion::LocomotingTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    if (FUN_00344e74(c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::motion::LocomotingAction* p = FUN_0008d690((int)sizeof(hulkfight::motion::LocomotingAction));
        if (p)
            return ((LocomotingAction_nv_1617c0*)(((hulkfight::motion::LocomotingAction*)(p))))->Make_001606d0(c);
    }
    return 0;
}

