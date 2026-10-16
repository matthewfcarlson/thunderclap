// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_18da70;
class ParamValue_18da70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_18da70 : public ParamValue_18da70 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<hulkfight::motion::TimerSetTrack>::vfunc_2() {
    return this->f_10 == 0;
}
