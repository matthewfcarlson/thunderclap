#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00416938[];
extern "C" void* __cdecl operator_new(unsigned int);
class Obj {
  public:
    Obj(int);
    hulk_uintptr vf;
    int a;
    int b;
    int c;
    unsigned int d;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_5() {
    Obj* p = (Obj*)operator_new(0x14);
    if (p) {
        p->Obj::Obj(0);
        p->vf = ((hulk_intptr)DAT_00416938);
        p->c = 0;
        p->d = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)(0);
}
