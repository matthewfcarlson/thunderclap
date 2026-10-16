// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_177c90 {};
class ParamValue_177c90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_177c90 : public ParamValue_177c90 {
  public:
    virtual void f();
};
extern CStageCondition_177c90 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::SyncToLocatorTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_177c90 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
