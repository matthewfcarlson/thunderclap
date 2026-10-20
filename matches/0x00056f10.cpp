#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class BaseCondition {
  public:
    BaseCondition() throw();
    virtual void v0();
    char pad[28];
};
class CAxisPressCondition_56f10 : public BaseCondition {
  public:
    CAxisPressCondition_56f10() throw() : BaseCondition() {}
    virtual void v0();
};

template <> void* fight::ConditionFactoryTemplate<CAxisPressCondition>::vfunc_5() {
    return (void*)(new CAxisPressCondition_56f10);
}
