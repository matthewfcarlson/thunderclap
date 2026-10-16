// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_199890;
class ParamValue_199890 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199890 : public ParamValue_199890 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_2() {
    return this->f_10 == 0;
}
