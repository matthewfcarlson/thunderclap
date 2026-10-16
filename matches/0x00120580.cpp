// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_120580;
class ParamValue_120580 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120580 : public ParamValue_120580 {
  public:
    int pad;
};

template <> bool fight::ParamString<hulkfight::ai::PathTrack>::vfunc_2() {
    return this->f_10 == 0;
}
