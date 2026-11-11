// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017bc70..0x0017e1a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::SnapToGroundTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0017bdc0 hulkfight::motion::CriticalMassDrainTrack::vfunc_10 (70 B): matches/0x0017bdc0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_10@CriticalMassDrainTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bdc0 {
  public:
    int x;
};
extern Params_17bdc0 hulk_at_00494b44;
extern Params_17bdc0 hulk_at_00494b60;
int __cdecl Check(void*, int, Params_17bdc0*, Params_17bdc0*, int);
struct CriticalMassDrainAction_nv_17bdc0 {
    int Init_00177430(hulkfight::motion::CriticalMassDrainTrack*, hulk_intptr);
};
hulkfight::motion::CriticalMassDrainAction* __cdecl Alloc_0008d690(int);

hulk_intptr hulkfight::motion::CriticalMassDrainTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0);
    if (result) {
        hulkfight::motion::CriticalMassDrainAction* p = Alloc_0008d690(0x24);
        if (p)
            return ((CriticalMassDrainAction_nv_17bdc0*)(((hulkfight::motion::CriticalMassDrainAction*)(p))))->Init_00177430(this, c);
    }
    return 0;
}

