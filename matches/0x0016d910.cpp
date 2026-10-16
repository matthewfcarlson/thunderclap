#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    BaseCondition(int) throw();
    char pad[8];
};
class GrappleReactionTypeCondition_16d910 : public BaseCondition {
  public:
    GrappleReactionTypeCondition_16d910() throw() : BaseCondition(0), a(0), b(0) {}
    virtual void f5();
    int a, b;
};
} // namespace motion
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleReactionTypeCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::GrappleReactionTypeCondition_16d910);
}
