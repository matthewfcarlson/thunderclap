// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_235f10 {};
class ParamValue_235f10 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_235f10 : public ParamValue_235f10 {
  public:
    virtual void f();
};
extern CStageCondition_235f10 zeroCondition;

template <> void* fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_235f10 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
