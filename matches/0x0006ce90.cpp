// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_6ce90 {};
class ParamValue_6ce90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_6ce90 : public ParamValue_6ce90 {
  public:
    virtual void f();
};
extern CStageCondition_6ce90 zeroCondition;

template <> void* fight::ParamEnumConstList<CRageModeTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_6ce90 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
