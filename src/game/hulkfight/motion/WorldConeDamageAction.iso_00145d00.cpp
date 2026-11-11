// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00143100..0x00146900 (kind game, layer game, confidence high), dominant class hulkfight::motion::WorldConeDamageAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00145d00 hulkfight::motion::MotionTrailStopTrack::vfunc_10 (70 B): matches/0x00145d00.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@MotionTrailStopTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_145d00 {
  public:
    int x;
};
extern Params_145d00 hulk_at_00494b44;
extern Params_145d00 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_145d00*, Params_145d00*, int);
struct MotionTrailStopAction_nv_145d00 {
    int Init_00144b80(hulkfight::motion::MotionTrailStopTrack*, hulk_intptr);
};
hulkfight::motion::MotionTrailStopAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::MotionTrailStopTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::MotionTrailStopAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((MotionTrailStopAction_nv_145d00*)(((hulkfight::motion::MotionTrailStopAction*)(p))))->Init_00144b80(this, c);
    }
    return 0;
}

