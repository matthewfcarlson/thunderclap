#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void f();
    char pad[8];
    BaseCondition(int) throw();
};
class ShoreNearCondition_16e1d0 : public BaseCondition {
  public:
    virtual void f();
    bool enabled;
    ShoreNearCondition_16e1d0(int x) throw() : BaseCondition(x), enabled(true) {}
};
} // namespace motion
} // namespace hulkfight
namespace fight {
} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::ShoreNearCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::ShoreNearCondition_16e1d0(0));
}
