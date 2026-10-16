// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_177e60 {};
class ParamValue_177e60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_177e60 : public ParamValue_177e60 {
  public:
    virtual void f();
};
extern CStageCondition_177e60 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::LocomotionStateTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_177e60 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
