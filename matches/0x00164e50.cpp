#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
namespace hulkfight {
namespace motion {
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int a;
    int b;
};
class PhaseCondition_164e50 : public Base {
  public:
    PhaseCondition_164e50() throw() : Base(0), c(0), d(0) {}
    virtual void f0();
    int c;
    int d;
};
} // namespace motion
} // namespace hulkfight
namespace fight {
class ConditionFactory_164e50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PhaseCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::PhaseCondition_164e50);
}
