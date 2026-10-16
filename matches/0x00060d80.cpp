// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_60d80 {};
class ParamValue_60d80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_60d80 : public ParamValue_60d80 {
  public:
    virtual void f();
};
extern CStageCondition_60d80 zeroCondition;

template <> void* fight::ParamEnumConstList<CEffectTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_60d80 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
