// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_126d00 {};
class ParamValue_126d00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_126d00 : public ParamValue_126d00 {
  public:
    virtual void f();
};
extern CStageCondition_126d00 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_126d00 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
