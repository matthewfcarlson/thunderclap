// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_149a60;
class ParamValue_149a60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_149a60 : public ParamValue_149a60 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_2() {
    return this->f_10 == 0;
}
