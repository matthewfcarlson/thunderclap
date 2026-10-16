// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_160870;
class ParamValue_160870 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_160870 : public ParamValue_160870 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::motion::PhaseCondition>::vfunc_2() {
    return this->f_10 == 0;
}
