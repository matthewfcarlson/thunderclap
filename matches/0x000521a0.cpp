#include "gen/fight.h"

struct CFightNodeTimeCondition_521a0 {
    virtual ~CFightNodeTimeCondition_521a0();
    char pad[0x10];
    void Initialize();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void* conditionVtable;

template <> void* fight::ConditionFactoryTemplate<CFightNodeTimeCondition>::vfunc_5() {
    CFightNodeTimeCondition_521a0* p = (CFightNodeTimeCondition_521a0*)FUN_0008d690(0x14);
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
