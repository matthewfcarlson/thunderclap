// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_145150;
class ParamValue_145150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_145150 : public ParamValue_145150 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::motion::MotionBlurTrack>::vfunc_2() {
    return this->f_10 == 0;
}
