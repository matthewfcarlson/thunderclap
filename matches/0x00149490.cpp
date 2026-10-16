// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_149490 {};
class ParamValue_149490 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_149490 : public ParamValue_149490 {
  public:
    virtual void f();
};
extern CStageCondition_149490 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::GrappleAttachJointCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_149490 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
