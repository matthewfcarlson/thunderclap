// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_153000 {};
class ParamValue_153000 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_153000 : public ParamValue_153000 {
  public:
    virtual void f();
};
extern CStageCondition_153000 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionChargeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_153000 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
