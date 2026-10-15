#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[8];
};
class TargetDirectionXZCondition_12ac40 : public BaseCondition {
  public:
    TargetDirectionXZCondition_12ac40() throw() : BaseCondition(0), a(0), b(0) {}
    virtual void f0();
    int a;
    int b;
};
} // namespace ai
} // namespace hulkfight
namespace fight {
class ConditionFactory_12ac40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual hulkfight::ai::TargetDirectionXZCondition_12ac40* vfunc_5();
};

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionXZCondition>::vfunc_5() {
    return (void*)(new hulkfight::ai::TargetDirectionXZCondition_12ac40);
}
