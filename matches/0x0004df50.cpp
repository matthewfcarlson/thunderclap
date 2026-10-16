#include "gen/fight.h"

class CStageCondition_4df50 {};
class ParamValue_4df50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4df50 : public ParamValue_4df50 {
  public:
    virtual void f();
};
extern CStageCondition_4df50 zeroCondition;

template <> void* fight::ParamEnumConstList<CStageCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4df50 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
