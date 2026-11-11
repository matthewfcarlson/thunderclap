// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


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
int __cdecl Check(void*, int, Params_1889c0*, Params_1889c0*, int);
struct PropAddToMissileCountAction_nv_1889c0 {
    int Init_00183b80(hulkfight::motion::PropAddToMissileCountTrack*, hulk_intptr);
};
hulkfight::motion::PropAddToMissileCountAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::PropAddToMissileCountTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::PropAddToMissileCountAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((PropAddToMissileCountAction_nv_1889c0*)(((hulkfight::motion::PropAddToMissileCountAction*)(p))))->Init_00183b80(this, c);
    }
    return 0;
}

