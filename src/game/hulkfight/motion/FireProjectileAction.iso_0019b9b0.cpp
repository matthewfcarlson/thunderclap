// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00199630..0x0019c050 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireProjectileAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0019b9b0 hulkfight::motion::FireGroundShockwaveTrack::vfunc_10 (70 B): matches/0x0019b9b0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@FireGroundShockwaveTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19b9b0 {
  public:
    int x;
};
extern Params_19b9b0 TypeA_19b9b0;
extern Params_19b9b0 TypeB_19b9b0;
int __cdecl Check(void*, int, Params_19b9b0*, Params_19b9b0*, int);
struct FireGroundShockwaveAction_nv_19b9b0 {
    int Init(hulkfight::motion::FireGroundShockwaveTrack*, hulk_intptr);
};
hulkfight::motion::FireGroundShockwaveAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::FireGroundShockwaveTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_19b9b0, &TypeB_19b9b0, 0);
    if (result) {
        hulkfight::motion::FireGroundShockwaveAction* p = Alloc(0x24);
        if (p)
            return ((FireGroundShockwaveAction_nv_19b9b0*)(((hulkfight::motion::FireGroundShockwaveAction*)(p))))->Init(this, c);
    }
    return 0;
}

