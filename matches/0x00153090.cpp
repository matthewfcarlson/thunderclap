// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_153090;
class ParamValue_153090 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_153090 : public ParamValue_153090 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::motion::CollisionChargeCondition>::vfunc_2() {
    return this->f_10 == 0;
}
