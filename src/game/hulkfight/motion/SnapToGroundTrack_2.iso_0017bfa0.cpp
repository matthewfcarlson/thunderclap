// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017bfa0 hulkfight::motion::SnapToGroundTrack::vfunc_10 (70 B): matches/0x0017bfa0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@SnapToGroundTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bfa0 {
  public:
    int x;
};
extern Params_17bfa0 TypeA_17bfa0;
extern Params_17bfa0 TypeB_17bfa0;
int __cdecl Check(void*, int, Params_17bfa0*, Params_17bfa0*, int);
struct SnapToGroundAction_nv_17bfa0 {
    int Init(hulkfight::motion::SnapToGroundTrack*, hulk_intptr);
};
hulkfight::motion::SnapToGroundAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::SnapToGroundTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17bfa0, &TypeB_17bfa0, 0);
    if (result) {
        hulkfight::motion::SnapToGroundAction* p = Alloc(0x24);
        if (p)
            return ((SnapToGroundAction_nv_17bfa0*)(((hulkfight::motion::SnapToGroundAction*)(p))))->Init(this, c);
    }
    return 0;
}

