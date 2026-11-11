// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128240..0x001296f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);


// 0x001296a0 hulkfight::ai::TargetClearTrack::vfunc_10 (70 B): matches/0x001296a0.cpp [isolated: conflict: Alloc; Check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@TargetClearTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1296a0 {
  public:
    int x;
};
extern Params_1296a0 hulk_at_00494b44;
extern Params_1296a0 hulk_at_00494b60;
struct TargetClearAction_nv_1296a0 {
    int Init_001268a0(hulkfight::ai::TargetClearTrack*, hulk_intptr);
};
hulkfight::ai::TargetClearAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::ai::TargetClearTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        hulkfight::ai::TargetClearAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((TargetClearAction_nv_1296a0*)(((hulkfight::ai::TargetClearAction*)(p))))->Init_001268a0(this, c);
    }
    return 0;
}

