#include "gen/fight.h"

class CButtonDownCondition_57230 {
  public:
    CButtonDownCondition_57230();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int g_vft_57230;

template <> void* fight::ConditionFactoryTemplate<CButtonDownCondition>::vfunc_5() {
    CButtonDownCondition_57230* p = (CButtonDownCondition_57230*)FUN_0008d690(0x20);
    if (p) {
        p->CButtonDownCondition_57230::CButtonDownCondition_57230();
        *(int*)p = (int)&g_vft_57230;
        return (void*)(p);
    }
    return (void*)(0);
}
