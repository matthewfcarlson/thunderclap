#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
class BaseCondition {
  public:
    BaseCondition(int) throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
};
class GrappleOrientationCondition_14be40 : public BaseCondition {
  public:
    GrappleOrientationCondition_14be40() throw() : BaseCondition(0) {
        a = 0;
        b = 0x3fc90fdb;
    }
    virtual void v0();
    int a;
    int b;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleOrientationCondition>::vfunc_5() {
    return (void*)(new GrappleOrientationCondition_14be40);
}
