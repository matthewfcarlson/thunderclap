// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017bf00 hulkfight::motion::VisibilityTrack::vfunc_10 (70 B): matches/0x0017bf00.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@VisibilityTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bf00 {
  public:
    int x;
};
extern Params_17bf00 hulk_at_00494b44;
extern Params_17bf00 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_17bf00*, Params_17bf00*, int);
struct VisibilityAction_nv_17bf00 {
    int Init_00177550(hulkfight::motion::VisibilityTrack*, hulk_intptr);
};
hulkfight::motion::VisibilityAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::VisibilityTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::VisibilityAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((VisibilityAction_nv_17bf00*)(((hulkfight::motion::VisibilityAction*)(p))))->Init_00177550(this, c);
    }
    return 0;
}

