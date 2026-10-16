#include "gen/global.h"

class Child_e4d50 {
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

void FEContainer::vfunc_15() {
    if ((*(Child_e4d50 * *)&this->f_48)) {
        (*(Child_e4d50 * *)&this->f_48)->f10(3);
        (*(Child_e4d50 * *)&this->f_48)->f9(0);
    }
}
