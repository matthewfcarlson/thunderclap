#include "gen/fight.h"

extern void* __cdecl alloc(unsigned int);
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
    VelocityXZAngleCondition_16de70* p = (VelocityXZAngleCondition_16de70*)alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = (int)&velocityVtable;
        p->z = 0;
        p->angle = 1.57079637f;
        return (void*)(p);
    }
    return (void*)(0);
}
