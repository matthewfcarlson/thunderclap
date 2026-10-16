// Same code shape as 0x0004dff0 (propagated; names are from that function)
#include "gen/fight.h"

class CStageCondition_152ba0;
class ParamValue_152ba0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_152ba0 : public ParamValue_152ba0 {
  public:
    int pad;
};

template <> bool fight::ParamBool<hulkfight::motion::CollisionDevastatorCondition>::vfunc_2() {
    return this->f_10 == 0;
}
