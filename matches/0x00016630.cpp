// Same code shape as 0x000165f0 (propagated; names are from that function)
#include "gen/global.h"
#include "gen/owners.h"

class Inner2_16630 {
  public:
    Inner2_16630* Step2();
    void Step3(int);
};
class Inner1_16630 {
  public:
};

void CIntangibleToActorsAction::vfunc_4() {
    Inner2_16630* p = ((Inner2_16630 *)((owners::Object_592a0 *)((*(Inner1_16630 * *)&this->f_1c)))->FUN_000592a0())->Step2();
    p->Step3(0);
}
