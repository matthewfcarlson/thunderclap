#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f73bc[];
extern "C" void* __cdecl Allocate(unsigned int);
struct CMotionHitCondition_584a0 {
    unsigned int vtable;
    unsigned int pad1;
    unsigned int pad2;
    unsigned int value;
    unsigned int value2;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<CMotionHitCondition>::vfunc_5() {
    CMotionHitCondition_584a0* p = (CMotionHitCondition_584a0*)Allocate(0x14);
    if (p) {
        p->Init(0);
        p->vtable = ((hulk_intptr)DAT_003f73bc);
        p->value = 0;
        p->value2 = 2;
        return (void*)(p);
    }
    return (void*)(0);
}
