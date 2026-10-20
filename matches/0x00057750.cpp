#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f6fc8[];
typedef unsigned int u32_57750;
extern void* __cdecl Alloc(unsigned int);
struct CCollisionDirectionCondition_57750 {
    u32_57750 vptr;
    u32_57750 pad4, pad8, fieldC, field10;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<CCollisionDirectionCondition>::vfunc_5() {
    CCollisionDirectionCondition_57750* p = (CCollisionDirectionCondition_57750*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = ((hulk_intptr)DAT_003f6fc8);
        p->fieldC = 0;
        p->field10 = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)(0);
}
