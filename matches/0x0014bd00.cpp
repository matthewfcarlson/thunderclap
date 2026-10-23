#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
namespace fight {
} // namespace fight
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void f();
    char pad[8];
    BaseCondition(int) throw();
};
class CivilianAttachedCondition_14bd00 : public BaseCondition {
  public:
    virtual void f();
    unsigned char flag;
    CivilianAttachedCondition_14bd00(int x) throw() : BaseCondition(x), flag(1) {}
};
} // namespace motion
} // namespace hulkfight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::CivilianAttachedCondition_14bd00(0));
}
