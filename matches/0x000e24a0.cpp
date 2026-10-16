#include "gen/global.h"

class Child_e24a0 {
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
    virtual void f9();
    virtual void f10();
    virtual bool f11(int, int);
};

bool VScroll::vfunc_6(int a, int b) {
    if ((*(Child_e24a0 * *)&this->f_244) && (*(Child_e24a0 * *)&this->f_244)->f11(a, b))
        return true;
    return false;
}
