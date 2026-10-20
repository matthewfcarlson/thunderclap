#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00413fb0[];
extern "C" void* FUN_0008d690(unsigned int);
class CollisionThrowCondition_1590a0 {
  public:
    hulk_intptr vt;
    int a;
    int b;
    unsigned char flag;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionThrowCondition>::vfunc_5() {
    CollisionThrowCondition_1590a0* p = (CollisionThrowCondition_1590a0*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        p->vt = ((hulk_intptr)DAT_00413fb0);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
