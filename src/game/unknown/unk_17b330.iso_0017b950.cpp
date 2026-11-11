// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017b950 hulkfight::motion::SuckInPropsTrack::vfunc_10 (70 B): matches/0x0017b950.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@SuckInPropsTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b950 {
  public:
    int x;
};
extern Params_17b950 TypeA_17b950;
extern Params_17b950 TypeB_17b950;
int __cdecl Check(void*, int, Params_17b950*, Params_17b950*, int);
struct SuckInPropsAction_nv_17b950 {
    int Init(hulkfight::motion::SuckInPropsTrack*, hulk_intptr);
};
hulkfight::motion::SuckInPropsAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::SuckInPropsTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17b950, &TypeB_17b950, 0);
    if (result) {
        hulkfight::motion::SuckInPropsAction* p = Alloc(0x24);
        if (p)
            return ((SuckInPropsAction_nv_17b950*)(((hulkfight::motion::SuckInPropsAction*)(p))))->Init(this, c);
    }
    return 0;
}

