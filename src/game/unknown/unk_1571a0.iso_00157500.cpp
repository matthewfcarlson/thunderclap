// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001571a0..0x001575f0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x00157500 hulkfight::motion::HealthTrack::vfunc_10 (70 B): matches/0x00157500.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@HealthTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_157500 {
  public:
    int x;
};
extern Params_157500 hulk_at_00494b44;
extern Params_157500 hulk_at_00494b60;
struct HealthAction_nv_157500 {
    int Init_00152630(hulkfight::motion::HealthTrack*, hulk_intptr);
};
hulkfight::motion::HealthAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::HealthTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::HealthAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((HealthAction_nv_157500*)(((hulkfight::motion::HealthAction*)(p))))->Init_00152630(this, c);
    }
    return 0;
}

