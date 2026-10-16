// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_152a30 {};
class ParamValue_152a30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_152a30 : public ParamValue_152a30 {
  public:
    virtual void f();
};
extern CStageCondition_152a30 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionSourceTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_152a30 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
