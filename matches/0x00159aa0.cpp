#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[8];
    int value;
};
namespace hulkfight {
namespace motion {
class CollisionInterruptPriorityCondition_159aa0 : public BaseCondition {
  public:
    CollisionInterruptPriorityCondition_159aa0() throw() : BaseCondition(0) { value = 0; }
    virtual void f0();
};
} // namespace motion
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionInterruptPriorityCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::CollisionInterruptPriorityCondition_159aa0());
}
