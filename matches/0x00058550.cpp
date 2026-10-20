#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7394[];
typedef unsigned int u32_58550;
void* __cdecl Allocate(unsigned int);
struct CMotionStateCondition_58550 {
    u32_58550 vtable;
    u32_58550 pad4;
    u32_58550 pad8;
    u32_58550 fieldC;
    u32_58550 field10;
    void Initialize(int);
};

template <> void* fight::ConditionFactoryTemplate<CMotionStateCondition>::vfunc_5() {
    CMotionStateCondition_58550* p = (CMotionStateCondition_58550*)Allocate(0x14);
    if (p) {
        p->Initialize(0);
        p->vtable = ((hulk_intptr)DAT_003f7394);
        p->fieldC = 0;
        p->field10 = 1;
        return (void*)(p);
    } else {
        return (void*)(0);
    }
}
