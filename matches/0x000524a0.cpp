// Same code shape as 0x000521a0 (propagated; names are from that function)
#include "gen/fight.h"

struct CFightNodeTimeCondition_524a0 {
    virtual ~CFightNodeTimeCondition_524a0();
    char pad[0x10];
    void Initialize();
};
extern void* __cdecl operator_new(unsigned int);
extern void* conditionVtable;

template <> void* fight::ConditionFactoryTemplate<CGrappleFightNodeTimeCondition>::vfunc_5() {
    CFightNodeTimeCondition_524a0* p = (CFightNodeTimeCondition_524a0*)operator_new(0x14);
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
