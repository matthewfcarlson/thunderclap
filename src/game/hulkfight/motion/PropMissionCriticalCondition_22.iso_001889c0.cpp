// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00187340..0x00188ab0 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropAddToCollisionTrack); was game/hulkfight/motion/PropAddToCollisionTrack_3.iso_001889c0.cpp until D46
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001889c0 hulkfight::motion::PropAddToMissileCountTrack::vfunc_10 (70 B): matches/0x001889c0.cpp [isolated: conflict: Alloc; Check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PropAddToMissileCountTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1889c0 {
  public:
    int x;
};
extern Params_1889c0 hulk_at_00494b44;
extern Params_1889c0 hulk_at_00494b60;
struct PropAddToMissileCountAction_nv_1889c0 {
    int Init_00183b80(hulkfight::motion::PropAddToMissileCountTrack*, hulk_intptr);
};
hulkfight::motion::PropAddToMissileCountAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::PropAddToMissileCountTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::motion::PropAddToMissileCountAction* p = Alloc_0008d690((int)sizeof(::hulkfight::motion::PropAddToMissileCountAction));   // (allocsize1) the size by gen's record
        if (p)
            return ((PropAddToMissileCountAction_nv_1889c0*)(((hulkfight::motion::PropAddToMissileCountAction*)(p))))->Init_00183b80(this, c);
    }
    return 0;
}

