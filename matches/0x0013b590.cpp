// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"
#include "decls/data/game/global.h"
// data: zeroCondition = DAT_003f335c

class CStageCondition_13b590 {};
class ParamValue_13b590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_13b590 : public ParamValue_13b590 {
  public:
    virtual void f();
};

template <> void* fight::ParamEnumConstList<hulkfight::motion::AnimationTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_13b590 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_13b590*)&DAT_003f335c));
}
