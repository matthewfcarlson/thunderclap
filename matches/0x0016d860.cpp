#include "compat/ptr.h"
#include "gen/fight.h"

class Condition_16d860 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init(int);
};
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern int LocomotionVTable;
struct Locomotion_16d860 {
    int* vptr;
    char pad[8];
    int a;
    int b;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_5() {
    Condition_16d860* p = (Condition_16d860*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        Locomotion_16d860* q = (Locomotion_16d860*)p;
        q->vptr = &LocomotionVTable;
        q->a = 0;
        q->b = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
