#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004166d8[];
extern void* __cdecl FUN_0008d690(unsigned int);
class VelocityYCondition_16d5a0 {
  public:
    virtual void dummy();
    int pad1;
    int pad2;
    int b;
    int c;
    VelocityYCondition_16d5a0(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityYCondition>::vfunc_5() {
    VelocityYCondition_16d5a0* p = (VelocityYCondition_16d5a0*)FUN_0008d690(0x14);
    if (p) {
        p->VelocityYCondition_16d5a0::VelocityYCondition_16d5a0(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004166d8);
        p->b = 0;
        p->c = 0;
        return (void*)(p);
    } else {
        return (void*)((VelocityYCondition_16d5a0*)0);
    }
}
