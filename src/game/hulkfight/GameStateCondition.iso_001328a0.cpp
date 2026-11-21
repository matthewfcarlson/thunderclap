// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
extern "C" char DAT_00411264[];   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)


// 0x001328a0 fight::ConditionFactoryTemplate<hulkfight::GameStateCondition>::vfunc_5 (61 B): matches/0x001328a0.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VGameStateCondition@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00113f80 (propagated; names are from that function)
#include "gen/fight.h"
#include "gen/hulkfight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl2) the allocator as defined (unk_08ceb0.cpp)
struct GameStateCondition_nv_1328a0 {
    void Init_00234590(hulk_intptr);   // (decl1) passes as defined
};
extern int AIHistoryNameCondition_vftable;

template <> void* fight::ConditionFactoryTemplate<hulkfight::GameStateCondition>::vfunc_5() {
    hulkfight::GameStateCondition* p = (hulkfight::GameStateCondition*)FUN_0008d690((unsigned int)sizeof(::hulkfight::GameStateCondition));   // (decl2) gen's record (0x18 on 32-bit)
    void* result;
    if (p) {
        ((GameStateCondition_nv_1328a0*)(p))->Init_00234590(0);
        *(int**)p = ((int*)DAT_00411264);
        p->f_0c = 0;
        p->compare = 0;
        p->f_14 = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}

