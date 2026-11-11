// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00188d80..0x00189050 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00189000 hulkfight::motion::ShieldArcTrack::vfunc_10 (70 B): matches/0x00189000.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@ShieldArcTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_189000 {
  public:
    int x;
};
extern Params_189000 hulk_at_00494b44;
extern Params_189000 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_189000*, Params_189000*, int);
struct ShieldArcAction_nv_189000 {
    int Init_00184750(hulkfight::motion::ShieldArcTrack*, hulk_intptr);
};
hulkfight::motion::ShieldArcAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::ShieldArcTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::ShieldArcAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((ShieldArcAction_nv_189000*)(((hulkfight::motion::ShieldArcAction*)(p))))->Init_00184750(this, c);
    }
    return 0;
}

