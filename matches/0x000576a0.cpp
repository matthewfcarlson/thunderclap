#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7528[];
typedef unsigned int u32_576a0;
extern "C" void* __cdecl Alloc(unsigned int);
struct CClimbEdgeCondition_576a0 {
    u32_576a0 vptr;
    char pad[8];
    u32_576a0 f0c;
    char f10;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<CClimbEdgeCondition>::vfunc_5() {
    CClimbEdgeCondition_576a0* p = (CClimbEdgeCondition_576a0*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = ((hulk_intptr)DAT_003f7528);
        p->f0c = 0;
        p->f10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
