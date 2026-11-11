// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00146900..0x0014c470 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleThrowAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0014afe0 hulkfight::motion::CivilianAnimationTrack::vfunc_10 (70 B): matches/0x0014afe0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@CivilianAnimationTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_14afe0 {
  public:
    int x;
};
extern Params_14afe0 hulk_at_00494b44;
extern Params_14afe0 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_14afe0*, Params_14afe0*, int);
struct CivilianAnimationAction_nv_14afe0 {
    int Init_001493c0(hulkfight::motion::CivilianAnimationTrack*, hulk_intptr);
};
hulkfight::motion::CivilianAnimationAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::CivilianAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::CivilianAnimationAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((CivilianAnimationAction_nv_14afe0*)(((hulkfight::motion::CivilianAnimationAction*)(p))))->Init_001493c0(this, c);
    }
    return 0;
}

