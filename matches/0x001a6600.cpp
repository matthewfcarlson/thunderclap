// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"
#include "decls/data/game/global.h"
// data: zeroCondition = DAT_003f335c

class CStageCondition_1a6600 {};
class ParamValue_1a6600 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1a6600 : public ParamValue_1a6600 {
  public:
    virtual void f();
};

template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1a6600 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1a6600*)&DAT_003f335c));
}
