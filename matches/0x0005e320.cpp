// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_5e320;
class ParamValue_5e320 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_5e320 : public ParamValue_5e320 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<CCollisionTrack>::vfunc_2() {
    return this->f_10 == 0;
}
