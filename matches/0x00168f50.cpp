// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_168f50 {};
class ParamValue_168f50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_168f50 : public ParamValue_168f50 {
  public:
    virtual void f();
};
extern CStageCondition_168f50 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::VelocityYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_168f50 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
