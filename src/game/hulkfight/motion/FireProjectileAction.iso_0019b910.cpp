// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00199630..0x0019c050 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireProjectileAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0019b910 hulkfight::motion::MissileThrowTrack::vfunc_10 (70 B): matches/0x0019b910.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@MissileThrowTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19b910 {
  public:
    int x;
};
extern Params_19b910 hulk_at_00494b44;
extern Params_19b910 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_19b910*, Params_19b910*, int);
struct MissileThrowAction_nv_19b910 {
    int Init_00198560(hulkfight::motion::MissileThrowTrack*, hulk_intptr);
};
hulkfight::motion::MissileThrowAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::MissileThrowTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::MissileThrowAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((MissileThrowAction_nv_19b910*)(((hulkfight::motion::MissileThrowAction*)(p))))->Init_00198560(this, c);
    }
    return 0;
}

