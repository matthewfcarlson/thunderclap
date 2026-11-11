// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00156cf0 hulkfight::motion::InterruptPriorityTrack::vfunc_10 (70 B): matches/0x00156cf0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@InterruptPriorityTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_156cf0 {
  public:
    int x;
};
extern Params_156cf0 TypeA_156cf0;
extern Params_156cf0 TypeB_156cf0;
int __cdecl Check(void*, int, Params_156cf0*, Params_156cf0*, int);
struct InterruptPriorityAction_nv_156cf0 {
    int Init(hulkfight::motion::InterruptPriorityTrack*, hulk_intptr);
};
hulkfight::motion::InterruptPriorityAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::InterruptPriorityTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_156cf0, &TypeB_156cf0, 0);
    if (result) {
        hulkfight::motion::InterruptPriorityAction* p = Alloc(0x24);
        if (p)
            return ((InterruptPriorityAction_nv_156cf0*)(((hulkfight::motion::InterruptPriorityAction*)(p))))->Init(this, c);
    }
    return 0;
}

