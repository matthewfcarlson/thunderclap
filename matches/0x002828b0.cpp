#include "gen/pure3d.h"

class Ref_2828b0 {
  public:
    virtual void f0();
    virtual void f1();
};

void pure3d::prop::CMotionTrail::vfunc_13() {
    if ((*(Ref_2828b0 * *)&this->f_40)) {
        (*(Ref_2828b0 * *)&this->f_40)->f1();
        (*(Ref_2828b0 * *)&this->f_40) = 0;
    }
    if ((*(Ref_2828b0 * *)&this->f_44)) {
        (*(Ref_2828b0 * *)&this->f_44)->f1();
        (*(Ref_2828b0 * *)&this->f_44) = 0;
    }
}
