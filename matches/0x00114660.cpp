#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
    BaseCondition(int) throw();
};
class RandomKeyWordWaitCondition_114660 : public BaseCondition {
  public:
    int a, b;
    RandomKeyWordWaitCondition_114660() throw();
    virtual void v0();
};
RandomKeyWordWaitCondition_114660::RandomKeyWordWaitCondition_114660() throw() : BaseCondition(0), a(0), b(0) {}
} // namespace ai
} // namespace hulkfight
namespace fight {
class ConditionFactory_114660 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::ai::RandomKeyWordWaitCondition_114660* vfunc_5();
};

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_5() {
    return (void*)(new hulkfight::ai::RandomKeyWordWaitCondition_114660);
}
