// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_199960 {};
class ParamValue_199960 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_199960 : public ParamValue_199960 {
  public:
    virtual void f();
};
extern CStageCondition_199960 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_199960 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
