// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_178120;
class ParamValue_178120 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_178120 : public ParamValue_178120 {
  public:
    int pad;
};

template <> bool fight::ParamString<hulkfight::motion::DriftToPositionTrack>::vfunc_2() {
    return this->f_10 == 0;
}
