// Same code shape as 0x0004df50 (propagated; names are from that function)
#include "gen/fight.h"
#include "decls/data/game/global.h"
// data: zeroCondition = DAT_003f335c

class CStageCondition_185c00 {};
class ParamValue_185c00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_185c00 : public ParamValue_185c00 {
  public:
    virtual void f();
};

template <> void* fight::ParamEnumConstList<hulkfight::motion::PropAnimationTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_185c00 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_185c00*)&DAT_003f335c));
}
