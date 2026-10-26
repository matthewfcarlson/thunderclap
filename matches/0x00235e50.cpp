// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"
#include "decls/data/game/global.h"
// data: zeroCondition = DAT_003f335c

class CStageCondition_235e50 {};
class ParamValue_235e50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_235e50 : public ParamValue_235e50 {
  public:
    virtual void f();
};

template <> void* fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_235e50 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_235e50*)&DAT_003f335c));
}
