// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128240..0x001296f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x00129600 hulkfight::ai::ClearProjectileDistanceTrack::vfunc_10 (70 B): matches/0x00129600.cpp [isolated: conflict: Alloc; Check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@ClearProjectileDistanceTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_129600 {
  public:
    int x;
};
extern Params_129600 hulk_at_00494b44;
extern Params_129600 hulk_at_00494b60;
struct ClearProjectileDistanceAction_nv_129600 {
    int Init_00126810(hulkfight::ai::ClearProjectileDistanceTrack*, hulk_intptr);
};
hulkfight::ai::ClearProjectileDistanceAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::ai::ClearProjectileDistanceTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::ai::ClearProjectileDistanceAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((ClearProjectileDistanceAction_nv_129600*)(((hulkfight::ai::ClearProjectileDistanceAction*)(p))))->Init_00126810(this, c);
    }
    return 0;
}

