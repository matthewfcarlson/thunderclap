// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018ecb0..0x00192030 (kind game, layer game, confidence high), dominant class hulkfight::motion::TankLocomotionAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001917c0 hulkfight::motion::ImpulseVelocityTrack::vfunc_10 (70 B): matches/0x001917c0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@ImpulseVelocityTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1917c0 {
  public:
    int x;
};
extern Params_1917c0 TypeA_1917c0;
extern Params_1917c0 TypeB_1917c0;
int __cdecl Check(void*, int, Params_1917c0*, Params_1917c0*, int);
struct ImpulseVelocityAction_nv_1917c0 {
    int Init(hulkfight::motion::ImpulseVelocityTrack*, hulk_intptr);
};
hulkfight::motion::ImpulseVelocityAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::ImpulseVelocityTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_1917c0, &TypeB_1917c0, 0);
    if (result) {
        hulkfight::motion::ImpulseVelocityAction* p = Alloc(0x24);
        if (p)
            return ((ImpulseVelocityAction_nv_1917c0*)(((hulkfight::motion::ImpulseVelocityAction*)(p))))->Init(this, c);
    }
    return 0;
}

