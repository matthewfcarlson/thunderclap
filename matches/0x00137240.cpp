// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_137240;
class ParamValue_137240 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137240 : public ParamValue_137240 {
  public:
    int pad;
};

template <> bool fight::ParamVector<hulkfight::motion::FallTrack>::vfunc_2() {
    return this->f_10 == 0;
}
