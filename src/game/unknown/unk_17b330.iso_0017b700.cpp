// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017b700 hulkfight::motion::TeleportTrack::vfunc_10 (70 B): matches/0x0017b700.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@TeleportTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b700 {
  public:
    int x;
};
extern Params_17b700 TypeA_17b700;
extern Params_17b700 TypeB_17b700;
int __cdecl Check(void*, int, Params_17b700*, Params_17b700*, int);
struct TeleportAction_nv_17b700 {
    int Init(hulkfight::motion::TeleportTrack*, hulk_intptr);
};
hulkfight::motion::TeleportAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::TeleportTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17b700, &TypeB_17b700, 0);
    if (result) {
        hulkfight::motion::TeleportAction* p = Alloc(0x24);
        if (p)
            return ((TeleportAction_nv_17b700*)(((hulkfight::motion::TeleportAction*)(p))))->Init(this, c);
    }
    return 0;
}

