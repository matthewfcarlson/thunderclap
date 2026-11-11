// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00143100..0x00146900 (kind game, layer game, confidence high), dominant class hulkfight::motion::WorldConeDamageAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x00144a50 hulkfight::motion::WorldConeDamageTrack::vfunc_10 (70 B): matches/0x00144a50.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@WorldConeDamageTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_144a50 {
  public:
    int x;
};
extern Params_144a50 hulk_at_00494b44;
extern Params_144a50 hulk_at_00494b60;
struct WorldConeDamageAction_nv_144a50 {
    int Init_001449c0(hulkfight::motion::WorldConeDamageTrack*, hulk_intptr);
};
hulkfight::motion::WorldConeDamageAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::WorldConeDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::WorldConeDamageAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((WorldConeDamageAction_nv_144a50*)(((hulkfight::motion::WorldConeDamageAction*)(p))))->Init_001449c0(this, c);
    }
    return 0;
}

