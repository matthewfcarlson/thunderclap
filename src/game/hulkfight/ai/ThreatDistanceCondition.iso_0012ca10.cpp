// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0012ca10 hulkfight::ai::ThreatDodgeTrack::vfunc_10 (70 B): matches/0x0012ca10.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@ThreatDodgeTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_12ca10 {
  public:
    int x;
};
extern Params_12ca10 hulk_at_00494b44;
extern Params_12ca10 hulk_at_00494b60;
struct ThreatDodgeAction_nv_12ca10 {
    int Init_0012c080(hulkfight::ai::ThreatDodgeTrack*, hulk_intptr);
};
hulkfight::ai::ThreatDodgeAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::ai::ThreatDodgeTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::ai::ThreatDodgeAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((ThreatDodgeAction_nv_12ca10*)(((hulkfight::ai::ThreatDodgeAction*)(p))))->Init_0012c080(this, c);
    }
    return 0;
}

