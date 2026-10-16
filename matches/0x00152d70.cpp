// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_152d70 {};
class ParamValue_152d70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152d70 : public ParamValue_152d70 {
  public:
    virtual void f();
};
extern CStageCondition_152d70 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::HitPushbackVelocityCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152d70 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
