// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00199630..0x0019c050 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireProjectileAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0019b9b0 hulkfight::motion::FireGroundShockwaveTrack::vfunc_10 (70 B): matches/0x0019b9b0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@FireGroundShockwaveTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19b9b0 {
  public:
    int x;
};
extern Params_19b9b0 hulk_at_00494b44;
extern Params_19b9b0 hulk_at_00494b60;
struct FireGroundShockwaveAction_nv_19b9b0 {
    int Init_00198900(hulkfight::motion::FireGroundShockwaveTrack*, hulk_intptr);
};
hulkfight::motion::FireGroundShockwaveAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::FireGroundShockwaveTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::FireGroundShockwaveAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((FireGroundShockwaveAction_nv_19b9b0*)(((hulkfight::motion::FireGroundShockwaveAction*)(p))))->Init_00198900(this, c);
    }
    return 0;
}

