// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_130620 {};
class ParamValue_130620 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_130620 : public ParamValue_130620 {
  public:
    virtual void f();
};
extern CStageCondition_130620 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::LocationCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_130620 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
