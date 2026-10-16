// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_177f90;
class ParamValue_177f90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_177f90 : public ParamValue_177f90 {
  public:
    int pad;
};

template <> bool fight::ParamVector<hulkfight::motion::MoveJointTrack>::vfunc_2() {
    return this->f_10 == 0;
}
