// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_185500 {};
class ParamValue_185500 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_185500 : public ParamValue_185500 {
  public:
    virtual void f();
};
extern CStageCondition_185500 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_185500 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
