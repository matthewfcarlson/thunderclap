#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00428a44[];
typedef unsigned int u32_23d180;
extern void* __cdecl FUN_0008d690(unsigned int);
struct Init_23d180 {
    void init(int);
};

template <> void* fight::ConditionFactoryTemplate<fight::OrCondition>::vfunc_5() {
    Init_23d180* p = (Init_23d180*)FUN_0008d690(12);
    if (p) {
        p->init(1);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00428a44);
        return (void*)(p);
    }
    return (void*)(0);
}
