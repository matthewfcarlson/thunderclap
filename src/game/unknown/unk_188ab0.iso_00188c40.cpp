// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00188ab0..0x00188d30 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00188c40 hulkfight::motion::PropSpawnTrack::vfunc_10 (70 B): matches/0x00188c40.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PropSpawnTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188c40 {
  public:
    int x;
};
extern Params_188c40 hulk_at_00494b44;
extern Params_188c40 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_188c40*, Params_188c40*, int);
struct PropSpawnAction_nv_188c40 {
    int Init_00183e40(hulkfight::motion::PropSpawnTrack*, hulk_intptr);
};
hulkfight::motion::PropSpawnAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::PropSpawnTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::PropSpawnAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((PropSpawnAction_nv_188c40*)(((hulkfight::motion::PropSpawnAction*)(p))))->Init_00183e40(this, c);
    }
    return 0;
}

