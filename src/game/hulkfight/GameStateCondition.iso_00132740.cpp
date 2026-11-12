// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
extern "C" char DAT_00411224[];   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)


// 0x00132740 fight::ConditionFactoryTemplate<hulkfight::MissionProgressCondition>::vfunc_5 (61 B): matches/0x00132740.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VMissionProgressCondition@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00113f80 (propagated; names are from that function)
#include "gen/fight.h"
#include "gen/hulkfight.h"

extern void* __cdecl Alloc_0008d690(unsigned int);
struct GameStateCondition_nv_132740 {
    void Init_00234590(int);
};
extern int AIHistoryNameCondition_vftable;

template <> void* fight::ConditionFactoryTemplate<hulkfight::MissionProgressCondition>::vfunc_5() {
    hulkfight::GameStateCondition* p = (hulkfight::GameStateCondition*)Alloc_0008d690(0x18);
    void* result;
    if (p) {
        ((GameStateCondition_nv_132740*)(p))->Init_00234590(0);
        *(int**)p = ((int*)DAT_00411224);
        (*(int *)&p->f_0c) = 0;
        p->compare = 0;
        (*(int *)&p->f_14) = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}

