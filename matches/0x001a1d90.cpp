#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class LuaCondition_1a1d90 : public Base {
  public:
    LuaCondition_1a1d90() throw() : Base(0) {
        a = 0;
        b = 0;
    }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    int a;
    int b;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::LuaCondition>::vfunc_5() {
    return (void*)(new LuaCondition_1a1d90);
}
