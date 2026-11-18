// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x001571a0..0x001575f0 (kind game, layer game, confidence low); was game/unknown/unk_1571a0.iso_001575a0.cpp until D46
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001575a0 hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_10 (70 B): matches/0x001575a0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@ClearFightParamsHitRecordTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1575a0 {
  public:
    int x;
};
extern Params_1575a0 hulk_at_00494b44;
extern Params_1575a0 hulk_at_00494b60;
struct ClearFightParamsHitRecordAction_nv_1575a0 {
    int Init_001526c0(hulkfight::motion::ClearFightParamsHitRecordTrack*, hulk_intptr);
};
hulkfight::motion::ClearFightParamsHitRecordAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::ClearFightParamsHitRecordAction* p = Alloc_0008d690((int)sizeof(::hulkfight::motion::ClearFightParamsHitRecordAction));   // (allocsize1) the size by gen's record
        if (p)
            return ((ClearFightParamsHitRecordAction_nv_1575a0*)(((hulkfight::motion::ClearFightParamsHitRecordAction*)(p))))->Init_001526c0(this, c);
    }
    return 0;
}

