// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_169330 {};
class ParamValue_169330 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_169330 : public ParamValue_169330 {
  public:
    virtual void f();
};
extern CStageCondition_169330 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::LocomotionMotionStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_169330 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
