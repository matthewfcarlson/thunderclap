// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_137380;
class ParamValue_137380 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137380 : public ParamValue_137380 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}
