// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017b7a0 hulkfight::motion::TeleportRelativeTrack::vfunc_10 (70 B): matches/0x0017b7a0.cpp [isolated: compile error C2440: 'initializing' : cannot convert from 'fn_fbea2d00::Result_17b330 *' to 'hulkfight::motion::TeleportRelativeAction *'; on include/gen/ and not mergeable]
// sym: ?vfunc_10@TeleportRelativeTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0011a060 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b7a0;
struct TeleportRelativeAction_nv_17b7a0 {
    u32_17b7a0 init_00175920(hulkfight::motion::TeleportRelativeTrack*, u32_17b7a0);
};
extern int MatchType(u32_17b7a0, int, const void*, const void*, int);
extern hulkfight::motion::TeleportRelativeAction* Alloc_0008d690(unsigned int);
extern const char hulk_at_00494b44[];
extern const char hulk_at_00494b60[];

hulk_intptr hulkfight::motion::TeleportRelativeTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b7a0 a = (u32_17b7a0)__p0; u32_17b7a0 b = (u32_17b7a0)__p1; u32_17b7a0 c = (u32_17b7a0)__p2;

    if (MatchType(c, 0, hulk_at_00494b44, hulk_at_00494b60, 0)) {
        hulkfight::motion::TeleportRelativeAction* p = Alloc_0008d690(0x30);
        if (p)
            return (int)(((TeleportRelativeAction_nv_17b7a0*)(((hulkfight::motion::TeleportRelativeAction*)(p))))->init_00175920(this, c));
    }
    return (int)(0);
}

