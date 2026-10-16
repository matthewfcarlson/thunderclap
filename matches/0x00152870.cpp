// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_152870 {};
class ParamValue_152870 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152870 : public ParamValue_152870 {
  public:
    virtual void f();
};
extern CStageCondition_152870 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152870 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
