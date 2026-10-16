// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_127800;
class ParamValue_127800 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127800 : public ParamValue_127800 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetClearTrack>::vfunc_2() {
    return this->f_10 == 0;
}
