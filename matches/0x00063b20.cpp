// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_63b20 {};
class ParamValue_63b20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_63b20 : public ParamValue_63b20 {
  public:
    virtual void f();
};
extern CStageCondition_63b20 zeroCondition;

template <> void* fight::ParamEnumConstList<CSmartPropEventTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_63b20 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
