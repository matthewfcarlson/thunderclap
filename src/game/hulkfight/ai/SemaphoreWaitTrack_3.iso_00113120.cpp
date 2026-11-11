// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00113120 hulkfight::ai::HulkActionTrack::vfunc_10 (70 B): matches/0x00113120.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@HulkActionTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_113120 {
  public:
    int x;
};
extern Params_113120 hulk_at_00494b44;
extern Params_113120 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_113120*, Params_113120*, int);
struct HulkAction_nv_113120 {
    int Init_0010f310(hulkfight::ai::HulkActionTrack*, hulk_intptr);
};
hulkfight::ai::HulkAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::ai::HulkActionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::ai::HulkAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((HulkAction_nv_113120*)(((hulkfight::ai::HulkAction*)(p))))->Init_0010f310(this, c);
    }
    return 0;
}

