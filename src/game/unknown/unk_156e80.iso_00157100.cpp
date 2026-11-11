// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00156e80..0x00157150 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00157100 hulkfight::motion::NoHitPushbackTrack::vfunc_10 (70 B): matches/0x00157100.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@NoHitPushbackTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_157100 {
  public:
    int x;
};
extern Params_157100 TypeA_157100;
extern Params_157100 TypeB_157100;
int __cdecl Check(void*, int, Params_157100*, Params_157100*, int);
struct NoHitPushbackAction_nv_157100 {
    int Init(hulkfight::motion::NoHitPushbackTrack*, hulk_intptr);
};
hulkfight::motion::NoHitPushbackAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::NoHitPushbackTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_157100, &TypeB_157100, 0);
    if (result) {
        hulkfight::motion::NoHitPushbackAction* p = Alloc(0x24);
        if (p)
            return ((NoHitPushbackAction_nv_157100*)(((hulkfight::motion::NoHitPushbackAction*)(p))))->Init(this, c);
    }
    return 0;
}

