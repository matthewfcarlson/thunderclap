// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0011a060 hulkfight::ai::MotionLocatorTrack::vfunc_10 (70 B): matches/0x0011a060.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@MotionLocatorTrack@ai@hulkfight@@UAEHHHH@Z
#include "gen/hulkfight.h"

typedef unsigned int u32_11a060;
struct MotionLocatorAction_nv_11a060 {
    u32_11a060 init(hulkfight::ai::MotionLocatorTrack*, u32_11a060);
};
extern int MatchType(u32_11a060, int, const void*, const void*, int);
extern hulkfight::ai::MotionLocatorAction* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];

hulk_intptr hulkfight::ai::MotionLocatorTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_11a060 a = (u32_11a060)__p0; u32_11a060 b = (u32_11a060)__p1; u32_11a060 c = (u32_11a060)__p2;

    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        hulkfight::ai::MotionLocatorAction* p = Alloc(0x30);
        if (p)
            return (int)(((MotionLocatorAction_nv_11a060*)(((hulkfight::ai::MotionLocatorAction*)(p))))->init(this, c));
    }
    return (int)(0);
}

