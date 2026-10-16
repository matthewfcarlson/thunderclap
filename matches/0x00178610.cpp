// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_178610 {};
class ParamValue_178610 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_178610 : public ParamValue_178610 {
  public:
    virtual void f();
};
extern CStageCondition_178610 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::JointPivotTrackerTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_178610 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
