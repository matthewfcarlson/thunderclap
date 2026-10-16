// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_168cb0 {};
class ParamValue_168cb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_168cb0 : public ParamValue_168cb0 {
  public:
    virtual void f();
};
extern CStageCondition_168cb0 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::ChargeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_168cb0 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
