// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_50120 {};
class ParamValue_50120 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_50120 : public ParamValue_50120 {
  public:
    virtual void f();
};
extern CStageCondition_50120 zeroCondition;

template <> void* fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_50120 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
