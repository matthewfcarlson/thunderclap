#include "gen/global.h"

class Inner2_165f0 {
  public:
    Inner2_165f0* Step2();
    void Step3(int);
};
class Inner1_165f0 {
  public:
    Inner2_165f0* Step1();
};

void CIntangibleAction::vfunc_4() {
    Inner2_165f0* p = (*(Inner1_165f0 * *)&this->f_1c)->Step1()->Step2();
    p->Step3(0);
}
