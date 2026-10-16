// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_127630 {};
class ParamValue_127630 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_127630 : public ParamValue_127630 {
  public:
    virtual void f();
};
extern CStageCondition_127630 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetDirectionXZCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_127630 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
