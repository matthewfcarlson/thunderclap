#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7154[];
class CSmartPropWeaponTypeCondition_58b60 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    int x4;
    int x8;
    int value;
    int type;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CSmartPropWeaponTypeCondition>::vfunc_5() {
    CSmartPropWeaponTypeCondition_58b60* p = (CSmartPropWeaponTypeCondition_58b60*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f7154);
        p->value = 0;
        p->type = -1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}
