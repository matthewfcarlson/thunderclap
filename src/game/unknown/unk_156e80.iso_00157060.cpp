// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00156e80..0x00157150 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x00157060 hulkfight::motion::HitPushbackAddTrack::vfunc_10 (70 B): matches/0x00157060.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@HitPushbackAddTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_157060 {
  public:
    int x;
};
extern Params_157060 hulk_at_00494b44;
extern Params_157060 hulk_at_00494b60;
struct HitPushbackAddAction_nv_157060 {
    int Init_00151a30(hulkfight::motion::HitPushbackAddTrack*, hulk_intptr);
};
hulkfight::motion::HitPushbackAddAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::HitPushbackAddTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::HitPushbackAddAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((HitPushbackAddAction_nv_157060*)(((hulkfight::motion::HitPushbackAddAction*)(p))))->Init_00151a30(this, c);
    }
    return 0;
}

