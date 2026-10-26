// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"
#include "decls/data/game/global.h"
// data: zeroCondition = DAT_003f335c

class CStageCondition_4f730 {};
class ParamValue_4f730 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_4f730 : public ParamValue_4f730 {
  public:
    virtual void f();
};

template <> void* fight::ParamEnumConstList<CPropActorStateCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_4f730 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_4f730*)&DAT_003f335c));
}
