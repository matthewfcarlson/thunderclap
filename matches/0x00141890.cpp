// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_141890;
class ParamValue_141890 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_141890 : public ParamValue_141890 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<hulkfight::motion::WallExitTrack>::vfunc_2() {
    return this->f_10 == 0;
}
