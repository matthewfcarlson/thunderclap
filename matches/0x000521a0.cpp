#include "gen/fight.h"

struct CFightNodeTimeCondition_521a0 {
    virtual ~CFightNodeTimeCondition_521a0();
    char pad[0x10];
    void Initialize();
};
extern void* __cdecl operator_new(unsigned int);
extern void* conditionVtable;

template <> void* fight::ConditionFactoryTemplate<CFightNodeTimeCondition>::vfunc_5() {
    CFightNodeTimeCondition_521a0* p = (CFightNodeTimeCondition_521a0*)operator_new(0x14);
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
