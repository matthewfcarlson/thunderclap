// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0017b3d0 hulkfight::motion::ChargeClearTrack::vfunc_10 (70 B): matches/0x0017b3d0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@ChargeClearTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b3d0 {
  public:
    int x;
};
extern Params_17b3d0 hulk_at_00494b44;
extern Params_17b3d0 hulk_at_00494b60;
struct ChargeClearAction_nv_17b3d0 {
    int Init_00174820(hulkfight::motion::ChargeClearTrack*, hulk_intptr);
};
hulkfight::motion::ChargeClearAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::ChargeClearTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::ChargeClearAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((ChargeClearAction_nv_17b3d0*)(((hulkfight::motion::ChargeClearAction*)(p))))->Init_00174820(this, c);
    }
    return 0;
}

