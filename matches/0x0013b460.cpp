// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_13b460 {};
class ParamValue_13b460 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_13b460 : public ParamValue_13b460 {
  public:
    virtual void f();
};
extern CStageCondition_13b460 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::FrameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_13b460 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
