#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    int y;
    int z;
    int w;
    BaseCondition(int) throw();
};
class TargetVelocityXZCondition_12ab90 : public BaseCondition {
  public:
    TargetVelocityXZCondition_12ab90() throw();
    virtual void a();
    virtual void b();
    virtual void c();
};
TargetVelocityXZCondition_12ab90::TargetVelocityXZCondition_12ab90() throw() : BaseCondition(0) {
    z = 0;
    w = 0;
}
} // namespace ai
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityXZCondition>::vfunc_5() {
    return (void*)(new hulkfight::ai::TargetVelocityXZCondition_12ab90());
}
