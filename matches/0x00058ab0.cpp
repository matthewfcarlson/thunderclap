#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7130[];
class Condition_58ab0 {
  public:
    void init(int);
};
class CSmartPropWeaponizableTypeCondition_58ab0 {
  public:
    hulk_uintptr vptr;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};
extern void* __cdecl alloc(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<CSmartPropWeaponizableTypeCondition>::vfunc_5() {
    CSmartPropWeaponizableTypeCondition_58ab0* p = (CSmartPropWeaponizableTypeCondition_58ab0*)alloc(0x14);
    if (p) {
        ((Condition_58ab0*)p)->init(0);
        p->vptr = ((hulk_intptr)DAT_003f7130);
        p->c = 0;
        p->d = 0xffffffff;
        return (void*)(p);
    }
    return (void*)(0);
}
