// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_126a00;
class ParamValue_126a00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126a00 : public ParamValue_126a00 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::vfunc_2() {
    return this->f_10 == 0;
}
