#include "gen/fight.h"

extern "C" char DAT_004167f8[];
class ConditionFactory_16da60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
namespace hulkfight {
namespace motion {
class VelocityAnimatedYCondition_16da60 {
  public:
    void Init(int);
    int vptr;
    int m4;
    int m8;
    int mC;
    int m10;
};
} // namespace motion
} // namespace hulkfight
extern void* __cdecl alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::VelocityAnimatedYCondition>::vfunc_5() {
    hulkfight::motion::VelocityAnimatedYCondition_16da60* p =
        (hulkfight::motion::VelocityAnimatedYCondition_16da60*)alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = ((int)DAT_004167f8);
        p->mC = 0;
        p->m10 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
