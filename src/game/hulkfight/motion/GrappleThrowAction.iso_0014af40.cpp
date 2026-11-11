// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00146900..0x0014c470 (kind game, layer game, confidence high), dominant class hulkfight::motion::GrappleThrowAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0014af40 hulkfight::motion::CivilianDetachTrack::vfunc_10 (70 B): matches/0x0014af40.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@CivilianDetachTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_14af40 {
  public:
    int x;
};
extern Params_14af40 hulk_at_00494b44;
extern Params_14af40 hulk_at_00494b60;
struct CivilianDetachAction_nv_14af40 {
    int Init_00149330(hulkfight::motion::CivilianDetachTrack*, hulk_intptr);
};
hulkfight::motion::CivilianDetachAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::CivilianDetachTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::CivilianDetachAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((CivilianDetachAction_nv_14af40*)(((hulkfight::motion::CivilianDetachAction*)(p))))->Init_00149330(this, c);
    }
    return 0;
}

