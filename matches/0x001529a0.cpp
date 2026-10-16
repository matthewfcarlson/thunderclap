// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_1529a0 {};
class ParamValue_1529a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1529a0 : public ParamValue_1529a0 {
  public:
    virtual void f();
};
extern CStageCondition_1529a0 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::CollisionSourceSizeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1529a0 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
