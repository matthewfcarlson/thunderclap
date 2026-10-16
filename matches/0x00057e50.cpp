// Same code shape as 0x000521a0 (propagated; names are from that function)
#include "gen/fight.h"

struct CFightNodeTimeCondition_57e50 {
    virtual ~CFightNodeTimeCondition_57e50();
    char pad[0x10];
    void Initialize();
};
extern void* __cdecl operator_new(unsigned int);
extern void* conditionVtable;

template <> void* fight::ConditionFactoryTemplate<CGrappleAlertStatusCondition>::vfunc_5() {
    CFightNodeTimeCondition_57e50* p = (CFightNodeTimeCondition_57e50*)operator_new(0x14);
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return (void*)(p);
    }
    return (void*)(0);
}
