// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0012d5e0 fight::ConditionFactoryTemplate<hulkfight::ai::ThreatCondition>::vfunc_5 (56 B): matches/0x0012d5e0.cpp [isolated: conflict: alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VThreatCondition@ai@hulkfight@@@fight@@UAEPAXXZ
#include "gen/fight.h"
#include "gen/hulkfight.h"
struct AllocWords_12d5e0 : ::hulkfight::ai::ThreatCondition {   // (sweep-allocsize) gen's words and the allocation's last word (gen's size is its
    int last;                                                  // last field's end, 4 short of the 0x20-byte allocation)
};
typedef char AllocWords_12d5e0_size32[(sizeof(void*) != 4 || sizeof(AllocWords_12d5e0) == 0x20) ? 1 : -1];

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
    void init_00234590(hulk_intptr);   // (decl1) passes as defined
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::ThreatCondition>::vfunc_5() {
    ThreatDistanceCondition_12d5e0* p = (ThreatDistanceCondition_12d5e0*)alloc(sizeof(AllocWords_12d5e0));
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

