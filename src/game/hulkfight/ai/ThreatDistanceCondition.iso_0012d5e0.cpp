// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0012d5e0 fight::ConditionFactoryTemplate<hulkfight::ai::ThreatCondition>::vfunc_5 (56 B): matches/0x0012d5e0.cpp [isolated: conflict: alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VThreatCondition@ai@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"

extern "C" char DAT_00410bd4[];
typedef unsigned int u32_12d5e0;
typedef unsigned char u8;
extern void* __cdecl alloc(hulk_uintptr);
struct Sub_12d5e0 {
    char pad[8];
    void init_0027af00();
};
struct ThreatDistanceCondition_12d5e0 {
    hulk_uintptr vptr;
    char pad4[8];
    u8 flagC;
    char padD[3];
    Sub_12d5e0 sub;
    u8 flag18;
    void init_00234590(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::ThreatCondition>::vfunc_5() {
    ThreatDistanceCondition_12d5e0* p = (ThreatDistanceCondition_12d5e0*)alloc(0x20);
    if (p) {
        p->init_00234590(0);
        p->vptr = ((hulk_intptr)DAT_00410bd4);
        p->flagC = 1;
        p->sub.init_0027af00();
        p->flag18 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

