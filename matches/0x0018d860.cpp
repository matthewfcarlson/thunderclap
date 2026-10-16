// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_18d860 {};
class ParamValue_18d860 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_18d860 : public ParamValue_18d860 {
  public:
    virtual void f();
};
extern CStageCondition_18d860 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::GrappleVarCompareCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_18d860 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
