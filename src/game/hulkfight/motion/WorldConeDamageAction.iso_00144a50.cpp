// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00143100..0x00146900 (kind game, layer game, confidence high), dominant class hulkfight::motion::WorldConeDamageAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00144a50 hulkfight::motion::WorldConeDamageTrack::vfunc_10 (70 B): matches/0x00144a50.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@WorldConeDamageTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_144a50 {
  public:
    int x;
};
extern Params_144a50 TypeA_144a50;
extern Params_144a50 TypeB_144a50;
int __cdecl Check(void*, int, Params_144a50*, Params_144a50*, int);
struct WorldConeDamageAction_nv_144a50 {
    int Init(hulkfight::motion::WorldConeDamageTrack*, hulk_intptr);
};
hulkfight::motion::WorldConeDamageAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::WorldConeDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_144a50, &TypeB_144a50, 0);
    if (result) {
        hulkfight::motion::WorldConeDamageAction* p = Alloc(0x24);
        if (p)
            return ((WorldConeDamageAction_nv_144a50*)(((hulkfight::motion::WorldConeDamageAction*)(p))))->Init(this, c);
    }
    return 0;
}

