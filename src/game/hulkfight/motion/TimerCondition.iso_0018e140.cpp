// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018cab0..0x0018ecb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TimerCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0018e140 hulkfight::motion::VarAssignTrack::vfunc_10 (70 B): matches/0x0018e140.cpp [isolated: conflict: Check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@VarAssignTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_18e140 {
  public:
    int x;
};
extern Params_18e140 hulk_at_00494b44;
extern Params_18e140 hulk_at_00494b60;
struct VarAssignAction_nv_18e140 {
    int Init_0018d3f0(hulkfight::motion::VarAssignTrack*, hulk_intptr);
};
hulkfight::motion::VarAssignAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::VarAssignTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::VarAssignAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((VarAssignAction_nv_18e140*)(((hulkfight::motion::VarAssignAction*)(p))))->Init_0018d3f0(this, c);
    }
    return 0;
}

