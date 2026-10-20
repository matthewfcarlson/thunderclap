// Same code shape as 0x00057c10 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_57cc0;
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct CCollisionPushbackYAngleCondition_57cc0 {
    hulk_uintptr vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init(int);
};
extern u32_57cc0 CCollisionPushbackYAngleCondition_vftable_57cc0;

template <> void* fight::ConditionFactoryTemplate<CCollisionStunTimeCondition>::vfunc_5() {
    CCollisionPushbackYAngleCondition_57cc0* p = (CCollisionPushbackYAngleCondition_57cc0*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (hulk_uintptr)&CCollisionPushbackYAngleCondition_vftable_57cc0;
        p->fieldC = 5;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
