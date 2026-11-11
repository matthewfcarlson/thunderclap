// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017bb40 hulkfight::motion::TargetBreakTrack::vfunc_10 (64 B): matches/0x0017bb40.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_10@TargetBreakTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001617c0 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct TargetBreakAction_nv_17bb40 {
    int Make_001764d0(void*);
};
extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern hulkfight::motion::TargetBreakAction* __cdecl FUN_0008d690(unsigned int);

hulk_intptr hulkfight::motion::TargetBreakTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * c = (void *)__p2;

    if (FUN_00344e74(c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        hulkfight::motion::TargetBreakAction* p = FUN_0008d690((int)sizeof(hulkfight::motion::TargetBreakAction));
        if (p)
            return ((TargetBreakAction_nv_17bb40*)(((hulkfight::motion::TargetBreakAction*)(p))))->Make_001764d0(c);
    }
    return 0;
}

