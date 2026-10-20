#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7250[];
class Factory_58950 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};
class Init_58950 {
  public:
    void InitFn(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CSmartPropStateCondition>::vfunc_5() {
    void* p = FUN_0008d690(0x14);
    if (p) {
        ((Init_58950*)p)->InitFn(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_003f7250);
        *(unsigned long*)((char*)p + 0xc) = 2;
        *(unsigned long*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)((void*)0);
}
