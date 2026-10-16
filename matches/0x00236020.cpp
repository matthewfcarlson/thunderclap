// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_236020 {};
class ParamValue_236020 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_236020 : public ParamValue_236020 {
  public:
    virtual void f();
};
extern CStageCondition_236020 zeroCondition;

template <> void* fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_236020 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
