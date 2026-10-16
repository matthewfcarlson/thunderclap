// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_149570;
class ParamValue_149570 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149570 : public ParamValue_149570 {
  public:
    int pad;
};

template <> bool fight::ParamBool<hulkfight::motion::CivilianAttachedCondition>::vfunc_2() {
    return this->f_10 == 0;
}
