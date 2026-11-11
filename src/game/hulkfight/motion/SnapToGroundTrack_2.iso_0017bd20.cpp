// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x0017bd20 hulkfight::motion::SuckTrack::vfunc_10 (70 B): matches/0x0017bd20.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@SuckTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bd20 {
  public:
    int x;
};
extern Params_17bd20 hulk_at_00494b44;
extern Params_17bd20 hulk_at_00494b60;
struct SuckAction_nv_17bd20 {
    int Init_00176ff0(hulkfight::motion::SuckTrack*, hulk_intptr);
};
hulkfight::motion::SuckAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::SuckTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::SuckAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((SuckAction_nv_17bd20*)(((hulkfight::motion::SuckAction*)(p))))->Init_00176ff0(this, c);
    }
    return 0;
}

