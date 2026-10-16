#include "gen/global.h"

class FELayout_e2470 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class Child_e2470 {
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
    virtual bool f10(int, int);
};

bool VScroll::vfunc_5(int a, int b) {
    if ((*(Child_e2470 * *)&this->f_244) && (*(Child_e2470 * *)&this->f_244)->f10(a, b))
        return true;
    return false;
}
