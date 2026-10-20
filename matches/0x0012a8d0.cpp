#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040fe54[];
class TargetVelocityYCondition_12a8d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    TargetVelocityYCondition_12a8d0(int);
    int pad1;
    int pad2;
    int a;
    int b;
};
extern void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityYCondition>::vfunc_5() {
    TargetVelocityYCondition_12a8d0* p = (TargetVelocityYCondition_12a8d0*)FUN_0008d690(0x14);
    if (p) {
        p->TargetVelocityYCondition_12a8d0::TargetVelocityYCondition_12a8d0(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0040fe54);
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
