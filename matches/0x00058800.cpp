#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f710c[];
extern "C" void* __cdecl Allocate(unsigned int);
struct Condition_58800 {
    void* vptr;
    unsigned char pad4[8];
    unsigned char enabled;
    unsigned char padD[3];
    int value;
    int last;
    void Initialize(int);
};

template <> void* fight::ConditionFactoryTemplate<CSmartPropAttachedCondition>::vfunc_5() {
    Condition_58800* p = (Condition_58800*)Allocate(0x18);
    if (p) {
        p->Initialize(0);
        p->vptr = (void*)((hulk_intptr)DAT_003f710c);
        p->enabled = 1;
        p->value = 0;
        p->last = -1;
        return (void*)(p);
    }
    return (void*)(0);
}
