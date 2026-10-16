// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_160780;
class ParamValue_160780 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160780 : public ParamValue_160780 {
  public:
    int pad;
};

template <> bool fight::ParamBool<hulkfight::motion::LocomotingCondition>::vfunc_2() {
    return this->f_10 == 0;
}
