#include "gen/fight.h"

typedef unsigned int u32_57c10;
extern "C" void* __cdecl Alloc(unsigned int);
struct CCollisionPushbackYAngleCondition_57c10 {
    u32_57c10 vptr;
    char pad[8];
    int fieldC;
    int field10;
    void Init(int);
};
extern u32_57c10 CCollisionPushbackYAngleCondition_vftable_57c10;

template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackYAngleCondition>::vfunc_5() {
    CCollisionPushbackYAngleCondition_57c10* p = (CCollisionPushbackYAngleCondition_57c10*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (u32_57c10)&CCollisionPushbackYAngleCondition_vftable_57c10;
        p->fieldC = 5;
        p->field10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
