// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_4e210 {};
class ParamValue_4e210 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4e210 : public ParamValue_4e210 {
  public:
    virtual void f();
};
extern CStageCondition_4e210 zeroCondition;

template <> void* fight::ParamEnumConstList<CAxisTimeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4e210 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
