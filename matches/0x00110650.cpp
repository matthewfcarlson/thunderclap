// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_110650;
class ParamValue_110650 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_110650 : public ParamValue_110650 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<hulkfight::ai::PropsToSuckCondition>::vfunc_2() {
    return this->f_10 == 0;
}
