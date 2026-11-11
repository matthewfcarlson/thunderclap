// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017bd20 hulkfight::motion::SuckTrack::vfunc_10 (70 B): matches/0x0017bd20.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@SuckTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bd20 {
  public:
    int x;
};
extern Params_17bd20 TypeA_17bd20;
extern Params_17bd20 TypeB_17bd20;
int __cdecl Check(void*, int, Params_17bd20*, Params_17bd20*, int);
struct SuckAction_nv_17bd20 {
    int Init(hulkfight::motion::SuckTrack*, hulk_intptr);
};
hulkfight::motion::SuckAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::SuckTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17bd20, &TypeB_17bd20, 0);
    if (result) {
        hulkfight::motion::SuckAction* p = Alloc(0x24);
        if (p)
            return ((SuckAction_nv_17bd20*)(((hulkfight::motion::SuckAction*)(p))))->Init(this, c);
    }
    return 0;
}

