#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f6f34[];
void* __cdecl Alloc(hulk_uintptr);
struct CAxisDirectionCondition_56ca0 {
    hulk_intptr vt;
    void Init(int);
    char pad[8];
    int a;
    int b;
    int c;
};

template <> void* fight::ConditionFactoryTemplate<CAxisDirectionCondition>::vfunc_5() {
    CAxisDirectionCondition_56ca0* p = (CAxisDirectionCondition_56ca0*)Alloc(0x18);
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_003f6f34);
        p->a = 0;
        p->b = 0;
        p->c = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)(0);
}
