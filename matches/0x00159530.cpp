#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f();
    virtual void g();
    virtual void h();
    int a;
    int b;
};
class CollisionTargetSizeCondition_159530 : public Base {
  public:
    CollisionTargetSizeCondition_159530() throw();
    virtual void f();
    int x;
    int y;
};
CollisionTargetSizeCondition_159530::CollisionTargetSizeCondition_159530() throw() : Base(0) {
    x = 0;
    y = 0;
}

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_5() {
    return (void*)(new CollisionTargetSizeCondition_159530);
}
