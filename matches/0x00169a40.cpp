// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_169a40;
class ParamValue_169a40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_169a40 : public ParamValue_169a40 {
  public:
    int pad;
};

template <> bool fight::ParamVector<hulkfight::motion::RayCastCondition>::vfunc_2() {
    return this->f_10 == 0;
}
