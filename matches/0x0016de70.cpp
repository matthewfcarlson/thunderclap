#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
extern int velocityVtable;
class VelocityXZAngleCondition_16de70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    int x;
    int y;
    int z;
    float angle;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityXZAngleCondition>::vfunc_5() {
    VelocityXZAngleCondition_16de70* p = (VelocityXZAngleCondition_16de70*)FUN_0008d690((int)sizeof(VelocityXZAngleCondition_16de70));
    if (p) {
        p->Init(0);
        *(hulk_intptr*)p = (hulk_intptr)&velocityVtable;
        p->z = 0;
        p->angle = 1.57079637f;
        return (void*)(p);
    }
    return (void*)(0);
}
