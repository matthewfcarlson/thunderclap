// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_12c450;
class ParamValue_12c450 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12c450 : public ParamValue_12c450 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::ai::ThreatBallTrack>::vfunc_2() {
    return this->f_10 == 0;
}
