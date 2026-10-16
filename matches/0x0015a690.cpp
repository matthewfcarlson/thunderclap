#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class Sub {
  public:
    Sub() throw();
    char pad[8];
};
class Condition_15a690 : public Base {
  public:
    Condition_15a690() throw() : Base(0), field(0), sub() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int field;
    Sub sub;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceNameCondition>::vfunc_5() {
    return (void*)(new Condition_15a690);
}
