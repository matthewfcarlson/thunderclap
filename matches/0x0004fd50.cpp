// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_4fd50 {};
class ParamValue_4fd50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4fd50 : public ParamValue_4fd50 {
  public:
    virtual void f();
};
extern CStageCondition_4fd50 zeroCondition;

template <> void* fight::ParamEnumConstList<CAlertStatusCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4fd50 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
