// Same code shape as 0x000e4d50 (propagated; names are from that function)
#include "gen/global.h"

class Child_e5600 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int);
    virtual void f10(int);
};

void FEScreenBase::vfunc_15() {
    if ((*(Child_e5600 * *)&this->f_48)) {
        (*(Child_e5600 * *)&this->f_48)->f10(3);
        (*(Child_e5600 * *)&this->f_48)->f9(0);
    }
}
