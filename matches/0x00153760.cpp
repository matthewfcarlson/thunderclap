// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_153760;
class ParamValue_153760 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153760 : public ParamValue_153760 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack>::vfunc_2() {
    return this->f_10 == 0;
}
