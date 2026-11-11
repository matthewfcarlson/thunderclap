// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018ecb0..0x00192030 (kind game, layer game, confidence high), dominant class hulkfight::motion::TankLocomotionAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001917c0 hulkfight::motion::ImpulseVelocityTrack::vfunc_10 (70 B): matches/0x001917c0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@ImpulseVelocityTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1917c0 {
  public:
    int x;
};
extern Params_1917c0 hulk_at_00494b44;
extern Params_1917c0 hulk_at_00494b60;
struct ImpulseVelocityAction_nv_1917c0 {
    int Init_001909b0(hulkfight::motion::ImpulseVelocityTrack*, hulk_intptr);
};
hulkfight::motion::ImpulseVelocityAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::ImpulseVelocityTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::ImpulseVelocityAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((ImpulseVelocityAction_nv_1917c0*)(((hulkfight::motion::ImpulseVelocityAction*)(p))))->Init_001909b0(this, c);
    }
    return 0;
}

