// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_177e10;
class ParamValue_177e10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177e10 : public ParamValue_177e10 {
  public:
    int pad;
};

template <> bool fight::ParamFloatConstRange<hulkfight::motion::LocomotionStateTrack>::vfunc_2() {
    return this->f_10 == 0;
}
