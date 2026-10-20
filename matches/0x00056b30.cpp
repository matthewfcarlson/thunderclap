#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7404[];
extern "C" void* __cdecl Alloc(unsigned int);
struct InitObj_56b30 {
    void Init(int);
};
struct CAlertStatusCondition_56b30 {
    int a, b, c, d, e;
};

template <> void* fight::ConditionFactoryTemplate<CAlertStatusCondition>::vfunc_5() {
    CAlertStatusCondition_56b30* p = (CAlertStatusCondition_56b30*)Alloc(0x14);
    if (p != 0) {
        ((InitObj_56b30*)p)->Init(0);
        p->a = ((hulk_intptr)DAT_003f7404);
        p->d = 0;
        p->e = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
