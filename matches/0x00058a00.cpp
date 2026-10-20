#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7178[];
class CSmartPropTypeCondition_58a00 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    void Init(int);
    char pad[8];
    int a;
    int b;
};
extern "C" CSmartPropTypeCondition_58a00* Alloc(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<CSmartPropTypeCondition>::vfunc_5() {
    CSmartPropTypeCondition_58a00* p = Alloc(0x14);
    if (p) {
        p->Init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_003f7178);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
