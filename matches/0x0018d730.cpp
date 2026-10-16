// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_18d730 {};
class ParamValue_18d730 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_18d730 : public ParamValue_18d730 {
  public:
    virtual void f();
};
extern CStageCondition_18d730 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::TimerCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_18d730 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
