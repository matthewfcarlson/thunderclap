#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Condition_16e270 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    Condition_16e270(int) throw();
    char pad[8];
};
class HealthPercentCondition_16e270 : public Condition_16e270 {
  public:
    HealthPercentCondition_16e270() throw() : Condition_16e270(0), a(0), b(0) {}
    virtual void f5();
    int a;
    int b;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_5() {
    return (void*)(new HealthPercentCondition_16e270);
}
