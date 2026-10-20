#include "compat/ptr.h"
#include "gen/fight.h"

extern void* alloc(hulk_uintptr);
extern int velocity_vftable;
class VelocityCondition_16d650 {
  public:
    hulk_intptr vt;
    char pad[8];
    int a;
    int b;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_5() {
    VelocityCondition_16d650* p = (VelocityCondition_16d650*)alloc(0x14);
    if (p) {
        p->Init(0);
        p->vt = (hulk_intptr)&velocity_vftable;
        p->a = 0;
        p->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
