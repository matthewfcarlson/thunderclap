// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_137330;
class ParamValue_137330 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137330 : public ParamValue_137330 {
  public:
    int pad;
};

template <> bool fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}
