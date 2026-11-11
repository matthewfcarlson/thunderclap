// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00199630..0x0019c050 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireProjectileAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0019bc00 hulkfight::motion::MissilePunchTrack::vfunc_10 (70 B): matches/0x0019bc00.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@MissilePunchTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19bc00 {
  public:
    int x;
};
extern Params_19bc00 hulk_at_00494b44;
extern Params_19bc00 hulk_at_00494b60;
struct MissilePunchAction_nv_19bc00 {
    int Init_00199630(hulkfight::motion::MissilePunchTrack*, hulk_intptr);
};
hulkfight::motion::MissilePunchAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::MissilePunchTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::MissilePunchAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((MissilePunchAction_nv_19bc00*)(((hulkfight::motion::MissilePunchAction*)(p))))->Init_00199630(this, c);
    }
    return 0;
}

