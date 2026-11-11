// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00188a60 hulkfight::motion::PropAddToCollisionTrack::vfunc_10 (70 B): matches/0x00188a60.cpp [isolated: conflict: Alloc; Check; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PropAddToCollisionTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188a60 {
  public:
    int x;
};
extern Params_188a60 hulk_at_00494b44;
extern Params_188a60 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_188a60*, Params_188a60*, int);
struct PropAddToCollisionAction_nv_188a60 {
    int Init_00183c10(hulkfight::motion::PropAddToCollisionTrack*, hulk_intptr);
};
hulkfight::motion::PropAddToCollisionAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::PropAddToCollisionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::PropAddToCollisionAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((PropAddToCollisionAction_nv_188a60*)(((hulkfight::motion::PropAddToCollisionAction*)(p))))->Init_00183c10(this, c);
    }
    return 0;
}

