#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041928c[];
class SmartPropIsCargoCondition_18bc60 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int a, b, c, d;
    void Init(int);
};
extern void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_5() {
    SmartPropIsCargoCondition_18bc60* p = (SmartPropIsCargoCondition_18bc60*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0041928c);
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
