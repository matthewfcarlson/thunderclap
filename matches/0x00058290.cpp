// Same code shape as 0x00057c10 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_58290;
extern "C" void* __cdecl Alloc(unsigned int);
struct CCollisionPushbackYAngleCondition_58290 {
    u32_58290 vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init(int);
};
extern u32_58290 CCollisionPushbackYAngleCondition_vftable_58290;

template <> void* fight::ConditionFactoryTemplate<CIntentionSpeedCondition>::vfunc_5() {
    CCollisionPushbackYAngleCondition_58290* p = (CCollisionPushbackYAngleCondition_58290*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (u32_58290)&CCollisionPushbackYAngleCondition_vftable_58290;
        p->fieldC = 5;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
