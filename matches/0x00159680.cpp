#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
class Base {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    int y;
    Base(int) throw();
};
class HitPushbackVelocityCondition_159680 : public Base {
  public:
    HitPushbackVelocityCondition_159680() throw();
    virtual void a();
    int velocity;
    int timer;
};
HitPushbackVelocityCondition_159680::HitPushbackVelocityCondition_159680() throw() : Base(0) {
    velocity = 0;
    timer = 0;
}

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_5() {
    return (void*)(new HitPushbackVelocityCondition_159680);
}
