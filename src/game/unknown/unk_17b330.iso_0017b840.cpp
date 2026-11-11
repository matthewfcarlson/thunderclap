// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017b840 hulkfight::motion::TeleportToLocatorTrack::vfunc_10 (70 B): matches/0x0017b840.cpp [isolated: compile error C2440: 'initializing' : cannot convert from 'fn_fbea2d00::Result_17b330 *' to 'hulkfight::motion::TeleportToLocatorAction *'; on include/gen/ and not mergeable]
// sym: ?vfunc_10@TeleportToLocatorTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0011a060 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_17b840;
struct TeleportToLocatorAction_nv_17b840 {
    u32_17b840 init(hulkfight::motion::TeleportToLocatorTrack*, u32_17b840);
};
extern int MatchType(u32_17b840, int, const void*, const void*, int);
extern hulkfight::motion::TeleportToLocatorAction* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];

hulk_intptr hulkfight::motion::TeleportToLocatorTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b840 a = (u32_17b840)__p0; u32_17b840 b = (u32_17b840)__p1; u32_17b840 c = (u32_17b840)__p2;

    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        hulkfight::motion::TeleportToLocatorAction* p = Alloc(0x30);
        if (p)
            return (int)(((TeleportToLocatorAction_nv_17b840*)(((hulkfight::motion::TeleportToLocatorAction*)(p))))->init(this, c));
    }
    return (int)(0);
}

