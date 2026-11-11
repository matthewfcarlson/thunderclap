// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00119db0 hulkfight::ai::MotionFacingTrack::vfunc_10 (70 B): matches/0x00119db0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@MotionFacingTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_119db0 {
  public:
    int x;
};
extern Params_119db0 hulk_at_00494b44;
extern Params_119db0 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_119db0*, Params_119db0*, int);
struct MotionFacingAction_nv_119db0 {
    int Init_001169a0(hulkfight::ai::MotionFacingTrack*, hulk_intptr);
};
hulkfight::ai::MotionFacingAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::ai::MotionFacingTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::ai::MotionFacingAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((MotionFacingAction_nv_119db0*)(((hulkfight::ai::MotionFacingAction*)(p))))->Init_001169a0(this, c);
    }
    return 0;
}

