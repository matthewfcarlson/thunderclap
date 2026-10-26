// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"
#include "decls/data/game/global.h"
// data: zeroCondition = DAT_003f335c

class CStageCondition_502e0 {};
class ParamValue_502e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_502e0 : public ParamValue_502e0 {
  public:
    virtual void f();
};

template <> void* fight::ParamEnumConstList<CIntentionSpeedCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_502e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_502e0*)&DAT_003f335c));
}
