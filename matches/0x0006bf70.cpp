// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_6bf70;
class ParamValue_6bf70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_6bf70 : public ParamValue_6bf70 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<CJumpTrack>::vfunc_2() {
    return this->f_10 == 0;
}
