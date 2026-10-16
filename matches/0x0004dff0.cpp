#include "gen/fight.h"

class CStageCondition_4dff0;
class ParamValue_4dff0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_4dff0 : public ParamValue_4dff0 {
  public:
    int pad;
};

template <> bool fight::ParamIntConstRange<CStageCondition>::vfunc_2() {
    return this->f_10 == 0;
}
