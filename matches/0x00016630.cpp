// Same code shape as 0x000165f0 (propagated; names are from that function)
#include "gen/global.h"

class Inner2_16630 {
  public:
    Inner2_16630* Step2();
    void Step3(int);
};
class Inner1_16630 {
  public:
    Inner2_16630* Step1();
};

void CIntangibleToActorsAction::vfunc_4() {
    Inner2_16630* p = (*(Inner1_16630 * *)&this->f_1c)->Step1()->Step2();
    p->Step3(0);
}
