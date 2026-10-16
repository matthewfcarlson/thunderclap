// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_10fce0 {};
class ParamValue_10fce0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_10fce0 : public ParamValue_10fce0 {
  public:
    virtual void f();
};
extern CStageCondition_10fce0 zeroCondition;

template <> void* fight::ParamEnumConstList<hulkfight::ai::AIHistoryNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_10fce0 ** *)&this->f_10)[index]);
    return (void*)(&zeroCondition);
}
