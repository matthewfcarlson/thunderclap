// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x00156c50 hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_10 (70 B): matches/0x00156c50.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@InterruptAccumulatorSetTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_156c50 {
  public:
    int x;
};
extern Params_156c50 hulk_at_00494b44;
extern Params_156c50 hulk_at_00494b60;
struct InterruptAccumulatorSetAction_nv_156c50 {
    int Init_00150fd0(hulkfight::motion::InterruptAccumulatorSetTrack*, hulk_intptr);
};
hulkfight::motion::InterruptAccumulatorSetAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::InterruptAccumulatorSetAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((InterruptAccumulatorSetAction_nv_156c50*)(((hulkfight::motion::InterruptAccumulatorSetAction*)(p))))->Init_00150fd0(this, c);
    }
    return 0;
}

