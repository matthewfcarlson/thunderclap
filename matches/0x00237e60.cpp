// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_237e60;
class ParamValue_237e60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_237e60 : public ParamValue_237e60 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<fight::SequenceTrack>::vfunc_2() {
    return this->f_10 == 0;
}
