#include "gen/global.h"
#include "gen/owners.h"

class Inner2_165f0 {
  public:
    Inner2_165f0* Step2();
    void Step3(int);
};
class Inner1_165f0 {
  public:
};

void CIntangibleAction::vfunc_4() {
    Inner2_165f0* p = ((Inner2_165f0 *)((owners::Object_592a0 *)((*(Inner1_165f0 * *)&this->f_1c)))->FUN_000592a0())->Step2();
    p->Step3(0);
}
