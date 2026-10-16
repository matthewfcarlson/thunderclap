// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_4eca0 {};
class ParamValue_4eca0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4eca0 : public ParamValue_4eca0 {
  public:
    virtual void f();
};
extern CStageCondition_4eca0 zeroCondition;

template <> void* fight::ParamEnumConstList<CCollisionPushbackYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4eca0 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
