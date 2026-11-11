// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00188d80..0x00189050 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00188ec0 hulkfight::motion::PropDestroyTrack::vfunc_10 (70 B): matches/0x00188ec0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@PropDestroyTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188ec0 {
  public:
    int x;
};
extern Params_188ec0 TypeA_188ec0;
extern Params_188ec0 TypeB_188ec0;
int __cdecl Check(void*, int, Params_188ec0*, Params_188ec0*, int);
struct PropDestroyAction_nv_188ec0 {
    int Init(hulkfight::motion::PropDestroyTrack*, hulk_intptr);
};
hulkfight::motion::PropDestroyAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropDestroyTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188ec0, &TypeB_188ec0, 0);
    if (result) {
        hulkfight::motion::PropDestroyAction* p = Alloc(0x24);
        if (p)
            return ((PropDestroyAction_nv_188ec0*)(((hulkfight::motion::PropDestroyAction*)(p))))->Init(this, c);
    }
    return 0;
}

