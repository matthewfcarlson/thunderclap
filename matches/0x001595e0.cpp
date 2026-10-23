#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace hulkfight {
namespace motion {
class BaseCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    BaseCondition(int) throw();
};
class CollisionSourceIsMissileCondition_1595e0 : public BaseCondition {
  public:
    CollisionSourceIsMissileCondition_1595e0() throw() : BaseCondition(0) { flag = 1; }
    virtual void a();
    virtual void b();
    virtual void c();
    char flag;
};
} // namespace motion
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionSourceIsMissileCondition>::vfunc_5() {
    return (void*)(new hulkfight::motion::CollisionSourceIsMissileCondition_1595e0);
}
