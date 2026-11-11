// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001887d0 hulkfight::motion::PropActorToPropTrack::vfunc_10 (70 B): matches/0x001887d0.cpp [isolated: conflict: Check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PropActorToPropTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1887d0 {
  public:
    int x;
};
extern Params_1887d0 TypeA_1887d0;
extern Params_1887d0 TypeB_1887d0;
int __cdecl Check(void*, int, Params_1887d0*, Params_1887d0*, int);
struct PropActorToPropAction_nv_1887d0 {
    int Init(hulkfight::motion::PropActorToPropTrack*, hulk_intptr);
};
hulkfight::motion::PropActorToPropAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropActorToPropTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_1887d0, &TypeB_1887d0, 0);
    if (result) {
        hulkfight::motion::PropActorToPropAction* p = Alloc(0x24);
        if (p)
            return ((PropActorToPropAction_nv_1887d0*)(((hulkfight::motion::PropActorToPropAction*)(p))))->Init(this, c);
    }
    return 0;
}

