// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_1a64e0 {};
class ParamValue_1a64e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1a64e0 : public ParamValue_1a64e0 {
  public:
    virtual void f();
};
extern CStageCondition_1a64e0 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1a64e0 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
