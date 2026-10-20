#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004167d8[];
class TargetingCondition_16d9c0 {
  public:
    TargetingCondition_16d9c0(int);
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init(int);
    char pad[12];
    char flag;
};
extern void* operator_new(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetingCondition>::vfunc_5() {
    TargetingCondition_16d9c0* p = (TargetingCondition_16d9c0*)operator_new(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((hulk_intptr)DAT_004167d8);
        *((char*)p + 0xc) = 1;
    } else {
        p = 0;
    }
    return (void*)(p);
}
