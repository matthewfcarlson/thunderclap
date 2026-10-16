// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_160960;
class ParamValue_160960 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160960 : public ParamValue_160960 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<hulkfight::motion::ClimbLocomotion4Track>::vfunc_2() {
    return this->f_10 == 0;
}
